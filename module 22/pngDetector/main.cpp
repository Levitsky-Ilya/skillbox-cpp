#include <iostream>
#include <fstream>
#include <string>

bool checkHeader(const char* header) {
    return (header[0] == -119 &&
            header[1] == 'P' &&
            header[2] == 'N' &&
            header[3] == 'G');
}

int main() {
    std::string filename;
    std::cout << "Enter enter full path to the statements file:\n";
    std::getline(std::cin, filename);

    if (filename.substr(filename.size() - 4) != ".png") {
        std::cout << "The file does not have a .png extension.\n";
        return 0;
    }

    std::ifstream fileStream;
    fileStream.open(filename, std::ios::binary);
    if (fileStream.fail()) {
        std::cout << "Error! File cannot be opened!\n";
        return 0;
    }

    char header[4];
    fileStream.read(header, sizeof(header));
    fileStream.close();

    if (checkHeader(header)) {
        std::cout << "This is a PNG file.\n";
    } else {
        std::cout << "This is NOT a PNG file.\n";
    }

    return 0;
}
