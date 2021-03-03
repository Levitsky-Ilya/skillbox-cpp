#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string inFilename, outFilename;

    std::cout << "Enter full path to the river.txt file:\n";
    std::getline(std::cin, inFilename);
    std::ifstream inFileStream(inFilename);
    if (inFileStream.fail()) {
        std::cout << "Error! File cannot be opened!\n";
        return 0;
    }

    std::cout << "Enter full path to the basket.txt file:\n";
    std::getline(std::cin, outFilename);
    std::ofstream outFileStream(outFilename);
    if (outFileStream.fail()) {
        std::cout << "Error! File cannot be opened!\n";
        return 0;
    }

    std::string inputFish, caughtFish;
    std::cout << "Let's start fishing! What kind of fish are we catching today?\n";
    std::cin >> inputFish;

    while(!inFileStream.eof()) {
        inFileStream >> caughtFish;
        if (inputFish == caughtFish)
            outFileStream << caughtFish << std::endl;
    }

    std::cout << "Fishing finished! See basket.txt.\n";

    inFileStream.close();
    outFileStream.close();
}
