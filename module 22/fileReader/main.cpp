#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename;
    std::cout << "Enter enter full path to the statements file:\n";
    std::getline(std::cin, filename);

    std::ifstream textStream;
    // It works fine even without binary mode.
    textStream.open(filename);
    if (textStream.fail()) {
        std::cout << "Error! File cannot be opened!\n";
        return 0;
    }

    char buffer [101];
    while(!textStream.eof()) {
        std::string word;
        textStream.read(buffer, sizeof(buffer) - 1);
        int symbolsRead = textStream.gcount();
        buffer[symbolsRead] = '\0';
        std::cout << buffer;
    }

    textStream.close();
}
