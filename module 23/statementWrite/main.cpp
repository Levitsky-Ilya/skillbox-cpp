#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// checkDate returns true if date has correct format "DD.MM.YYYY", returns false otherwise.
// checkDate DOES NOT check the correct number of days in month (e.g. 31.02.1999 would be valid).
bool checkDate(const std::string& date) {
    if (date.size() != 10)
        return false;
    if (date[2] != '.' || date[5] != '.')
        return false;
    int day = std::stoi(date.substr(0,2));
    int month = std::stoi(date.substr(3,2));
    int year = std::stoi(date.substr(6,4));
    return (day > 0 && day <= 31 &&
        month > 0 && month <= 12 &&
        year > 0 && year < 2300);
}

// checkStatement checks that statements follows the format "Name Surname DD.MM.YYYY Payment".
// The function returns true if format is correct, false otherwise.
bool checkStatement(const std::string& statement) {
    std::stringstream streamStatement(statement);
    std::string name, surname, date, dummy;
    int payment;
    streamStatement >> name >> surname >> date >> payment >> dummy;
    return (checkDate(date) && payment >= 0 && dummy.empty());
}

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

    std::cout << "Enter correct statements in format \"Name Surname DD.MM.YYYY Payment\"\n"
                 "The incorrect entry will finish the program." << std::endl;

    while (true) {
        std::string inputStatement;
        std::getline(std::cin, inputStatement);
        if (!checkStatement(inputStatement))
            break;
        outStream << inputStatement << std::endl;
    }

    std::cout << "The program finished." << std::endl;

    outStream.close();
}
