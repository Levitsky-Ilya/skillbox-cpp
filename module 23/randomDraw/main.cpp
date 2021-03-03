#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>


int main() {
    std::string filename;
    std::cout << "Enter full path to the statements file:\n";
    std::getline(std::cin, filename);

    std::ofstream outStream;
    outStream.open(filename, std::ios::app); // Open file in appending mode
    if (outStream.fail()) {
        std::cout << "Error! File cannot be opened!\n";
        return 0;
    }

    int height, width;
    std::cout << "Enter height and width fot the picture :\n";
    std::cin >> height >> width;
    if (height < 1 || width < 1) {
        std::cout << "Incorrect height or width. Exiting.\n";
        return 0;
    }

    // Initialize random number generator.

    // Clang-Tidy: Random number generator seeded with a disallowed source of seed value
    //  will generate a predictable sequence of values
    std::srand(std::time(nullptr));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Clang-Tidy: Rand() has limited randomness; use C++11 random library instead
            outStream << rand() % 2;
        }
        outStream << "\n";
    }

    std::cout << "Drawing finished!" << std::endl;

    outStream.close();
}
