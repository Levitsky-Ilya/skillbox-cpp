#include <iostream>
#include <vector>

void printVector(std::vector<float> vec) {
    for (float element : vec)
        std::cout << element << " ";
}

int main() {
    int databaseSize = 20;
    std::vector<float> database(databaseSize);
    int oldestEntry = 0;

    std::cout << "\nEnter float database elements, except -1. Enter -1 to finish. \n";
    float entry;
    std::cin >> entry;

    while (entry != -1.f) {
        database[oldestEntry] = entry;
        oldestEntry = (oldestEntry + 1) % databaseSize;
        std::cin >> entry;
    };

    std::cout << "\n Database is: ";
    for (int i = 0; i < databaseSize; i++) {
        std::cout << database[oldestEntry] << " ";
        oldestEntry = (oldestEntry + 1) % databaseSize;
    }

}
