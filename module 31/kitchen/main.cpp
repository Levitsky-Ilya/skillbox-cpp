#include <cassert>
#include <cstdlib>
#include <iostream>
#include <mutex>
#include <thread>
#include <queue>

#define SLEEP_FOR(x) { std::this_thread::sleep_for(std::chrono::seconds(x)); }

bool kitchenBusy = false;
bool newOrderArrived = false;
bool mealFinished = false;
bool deliveryReady = false;

enum Meal {
    PIZZA,
    SOUP,
    STEAK,
    SALAD,
    SUSHI
};

std::queue<Meal> mealsToCook, mealsReady;
std::mutex mealsToCookAccess, mealsReadyAccess;

std::string mealToString(Meal meal) {
    return (meal == PIZZA) ? "Pizza" :
           (meal == SOUP) ? "Soup" :
           (meal == STEAK) ? "Steak" :
           (meal == SALAD) ? "Salad" : "Sushi";
}

int randInInterval(int min, int max) {
    assert(min <= max);
    int random = rand();
    int ret = min + random % (max - min + 1);
    return ret;
}


void orderGenerate() {
    srand(time(nullptr));
    int minTime = 5, maxTime = 10;

    SLEEP_FOR(randInInterval(minTime, maxTime))

    mealsToCookAccess.lock();
    mealsToCook.push(static_cast<Meal>(randInInterval(0, 4)));
    newOrderArrived = true;
    mealsToCookAccess.unlock();
}

void kitchenCook(Meal meal) {
    srand(time(nullptr));
    int minTime = 5, maxTime = 15;

    SLEEP_FOR(randInInterval(minTime, maxTime))

    mealsReadyAccess.lock();
    mealsReady.push(meal);
    kitchenBusy = false;
    mealFinished = true;
    mealsReadyAccess.unlock();
}

void doDeliver() {
    int tim = 30;

    SLEEP_FOR(tim)

    deliveryReady = true;
}

int main() {
    std::cout << "Welcome to Kitchen Simulator!\n\n";

    std::thread orderThread(orderGenerate);
    orderThread.detach();

    std::thread kitchenThread;

    std::thread deliveryThread(doDeliver);
    deliveryThread.detach();

    int mealsDelivered = 0;
    while (mealsDelivered < 10) {
        if (newOrderArrived) {
            std::cout << "A new order for " << mealToString(mealsToCook.back()) << " arrived.\n";
            newOrderArrived = false;
            orderThread = std::thread(orderGenerate);
            orderThread.detach();
        }

        if (mealFinished) {

            mealsReadyAccess.lock();
            mealFinished = false;
            Meal meal = mealsReady.back();
            mealsReadyAccess.unlock();

            std::cout << "Kitchen finished to cook " << mealToString(meal) << ".\n";
        }

        if (!kitchenBusy && mealsToCookAccess.try_lock()) {
            if (!mealFinished && !newOrderArrived && !mealsToCook.empty()) {
                Meal meal = mealsToCook.front();
                mealsToCook.pop();
                kitchenBusy = true;
                mealsToCookAccess.unlock();

                kitchenThread = std::thread(kitchenCook, meal);
                kitchenThread.detach();
                std::cout << "Kitchen started to cook " << mealToString(meal) << "." << std::endl;
            } else {
                mealsToCookAccess.unlock();
            }
        }

        if (deliveryReady && mealsReadyAccess.try_lock()) {
            if (!mealFinished && !mealsReady.empty()) {
                std::cout << "Delivery arrived and took: ";

                while (!mealsReady.empty()) {
                    Meal meal = mealsReady.front();
                    mealsReady.pop();
                    std::cout << mealToString(meal) + " ";
                    mealsDelivered++;
                }
                deliveryReady = false;
                std::cout << "\n";
                mealsReadyAccess.unlock();

                deliveryThread = std::thread(doDeliver);
                deliveryThread.detach();
            } else {
                mealsReadyAccess.unlock();
            }
        }
    }

    return 0;
}
