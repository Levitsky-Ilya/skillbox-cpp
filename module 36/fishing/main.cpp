#include <iostream>
#include "fishing.h"

int main() {
    std::cout << "\n*** Welcome to Fisherman Simulator! ***\n\n" << std::endl;
    Pound pound;

    while (true) {
        int sectorIndex;
        std::cout << "Enter a pound sector index from 0 to 8:\n";
        std::cin >> sectorIndex;
        try {
            pound.chooseSector(sectorIndex);
            std::cout << "Nothing is caught. Try again!\n";
        } catch (const std::out_of_range &e) {
            std::cerr << "Argument sectorIndex is out of bounds.\n";
        } catch (const std::exception &e) {
            std::cout << "Caught something: " << e.what() << "\n";
            break;
        } catch (...) {
            std::cout << "Unknown exception caught!\n";
            return -1;
        }
    }

    return 0;
}
