#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename;
    std::cout << "Enter full path to the statements file:\n";
    std::getline(std::cin, filename);

    std::ifstream textStream;
    textStream.open(filename);
    if (textStream.fail()) {
        std::cout << "Error! File cannot be opened!\n";
        return 0;
    }

    int paymentMax = -1, totalPayments = 0;
    std::string paymentMaxOwnerName, paymentMaxOwnerSurname;
    while(!textStream.eof()) {
        std::string name, surname, date;
        int payment;
        textStream >> name >> surname >> payment >> date;
        totalPayments += payment;
        if (payment > paymentMax) {
            paymentMax = payment;
            paymentMaxOwnerName = name;
            paymentMaxOwnerSurname = surname;
        }
    }

    textStream.close();

    std::cout << "Total payments: " << totalPayments << std::endl;
    std::cout << "Largest payment owner: " << paymentMaxOwnerName << " " << paymentMaxOwnerSurname << std::endl;
}
