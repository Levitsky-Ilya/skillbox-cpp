#include <iostream>
#include <vector>

#define CYCLE_10(func) for (int i = 0; i < 10; i++) { func(i); }

std::vector<int> passengersInWagon (10);
int totalPassengers = 0;

// A simple function to fill one element in passengersInWagon
// Has no input verifications
void fillWagon(int wagonId) {
    std::cout << "Enter number of passengers in wagon " << wagonId << ": ";
    std::cin >> passengersInWagon[wagonId];
}

void checkIfWagonOverfilled(int wagonId) {
    if (passengersInWagon[wagonId] > 20)
        std::cout << "Wagon " << wagonId << " is overfilled!\n";
}

void checkIfWagonHasFreeSeats(int wagonId) {
    if (passengersInWagon[wagonId] < 20)
        std::cout << "Wagon " << wagonId << " has free seats.\n";
}

void addPassengersInWagon(int wagonId) {
    totalPassengers += passengersInWagon[wagonId];
}

int main() {
    CYCLE_10(fillWagon)
    CYCLE_10(checkIfWagonOverfilled)
    CYCLE_10(checkIfWagonHasFreeSeats)
    CYCLE_10(addPassengersInWagon)
    std::cout << "There are " << totalPassengers << " passengers in the train.\n";
}
