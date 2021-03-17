#include <iostream>
#include <fstream>
#include <string>

struct Payment {
    std::string name = "Name";
    std::string surname = "Surname";
    std::string date = "01.01.1970";
    int amount = 0;
};

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

// checkPayment checks that the payment follows the format "Name Surname DD.MM.YYYY Amount".
// The function returns true if format is correct, false otherwise.
bool checkPayment(const Payment& payment) {
    return (checkDate(payment.date) && payment.amount > 0);
}

void read(const std::string& filename) {
    std::ifstream textStream;
    textStream.open(filename);
    if (textStream.fail()) {
        std::cout << "Error! File cannot be opened!\n";
        return;
    }

    while (!textStream.eof()) {
        Payment payment;
        textStream >> payment.name >>
                      payment.surname >>
                      payment.date >>
                      payment.amount;
        if (!checkPayment(payment))
            if (textStream.eof())
                std::cout << " ==== (End of statement) ==== \n";
            else
                std::cout << " ==== (Invalid entry) ==== \n";
        else
            std::cout << payment.name << " " <<
                         payment.surname << " " <<
                         payment.date << " " <<
                         payment.amount << std::endl;
    }

    textStream.close();
}

void add(const std::string& filename, const Payment payment) {
    std::ofstream textStream;
    textStream.open(filename, std::ios::app);
    if (textStream.fail()) {
        std::cout << "Error! File cannot be opened!\n";
        return;
    }

    //payment is assumed to be checked
    textStream << payment.name << " " <<
               payment.surname << " " <<
               payment.date << " " <<
               payment.amount << std::endl;

    textStream.close();
}

int main() {
    std::cout << "Welcome to Statements Controller.\n";

    std::string filename;
    std::cout << "Enter full path to the statements file:\n";
    std::getline(std::cin, filename);

    while (true) {
        std::string command;
        std::cout << "\n"
                     "To read and display the statements list, enter \"r\".\n"
                     "To add a payment to the statement, enter \"a\".\n"
                     "Enter any other key to exit.\n";
        std::getline(std::cin, command);

        if (command == "r") {
            read(filename);
        } else if (command == "a") {
            Payment payment;
            std::string amountString;
            std::cout << "Enter name:\n";
            std::getline(std::cin, payment.name);
            std::cout << "Enter surname:\n";
            std::getline(std::cin, payment.surname);
            std::cout << "Enter date:\n";
            std::getline(std::cin, payment.date);
            while (!checkDate(payment.date)) {
                std::cout << "Enter a valid date in format \"DD.MM.YYYY\":\n";
                std::getline(std::cin, payment.date);
            }
            std::cout << "Enter payment amount: ";
            std::getline(std::cin, amountString);
            payment.amount = atoi(amountString.c_str());
            while (payment.amount <= 0) {
                std::cout << "Enter a valid positive amount: ";
                std::getline(std::cin, amountString);
                payment.amount = atoi(amountString.c_str());
            }

            add(filename, payment);
        } else {
            std::cout << "Exiting.\n";
            break;
        }
    }

    return 0;
}
