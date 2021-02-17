#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename;
    std::cout << "Enter enter full path to the file:\n";
    std:getline(std::cin, filename);

    std::ifstream wordsStream;
    wordsStream.open(filename);
    if (wordsStream.fail()) {
        std::cout << "Error! File cannot be opened!\n";
        return 0;
    }

    std::string wordToSearch;
    std::cout << "Enter a word to search: ";
    std::cin >> wordToSearch;

    int count = 0;
    while(!wordsStream.eof()) {
        std::string word;
        wordsStream >> word;
        count += (word == wordToSearch);
    }
    wordsStream.close();

    std::cout << "The word \"" << wordToSearch << "\" occurs in file " << count << " times.\n";
}
