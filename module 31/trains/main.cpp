#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <queue>

std::mutex trainStationAccess;

std::queue<int> trainStationQueue;

void trainGo(int index, int travelTime) {
    std::this_thread::sleep_for(std::chrono::seconds(travelTime));
    trainStationAccess.lock();
    trainStationQueue.push(index);
    trainStationAccess.unlock();
}

int main() {

    std::cout << "Welcome to Train Station Simulator!" << std::endl;

    int trainsCount = 3;
    std::vector<std::thread*> trainThreads(trainsCount);
    for (int i = 0; i < trainsCount; i++) {
        std::cout << "Enter the travel time for train #" << i << ":\n";
        int travelTime;
        std::cin >> travelTime;
        trainThreads[i] = new std::thread(trainGo, i, travelTime);
        std::cout << "Train #" << i << " has started.\n";
    }
    std::cout << "All trains are on the way...\n";

    int trainsArrived = 0, trainIndex;
    bool trainArrived = false;
    while (trainsArrived < trainsCount) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        trainStationAccess.lock();
        if (!trainStationQueue.empty()) {
            trainIndex = trainStationQueue.front();
            trainArrived = true;
            trainsArrived++;
            trainStationQueue.pop();
        }
        trainStationAccess.unlock();

        if (trainArrived) {
            std::string command;
            while (command != "depart") {
                std::cout << "Train " << trainIndex << " arrived at the station. \n"
                             "Enter \"depart\" to allow its departure.\n";
                std::cin >> command;
            }
            trainThreads[trainIndex]->join();
            std::cout << "Train " << trainIndex << " departed from the station.\n";
            trainArrived = false;
        }
    }
    return 0;
}
