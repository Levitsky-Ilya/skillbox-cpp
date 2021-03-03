#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

enum {
    SUCCESS = 0,
    FILE_OPEN_FAILURE = 1,
    FILE_WRONG_FORMAT = 2,
    NOT_ENOUGH_CASH = 3,
};

const int bankNotesMaxCount = 1000;
const int banknoteTypes[] = {5000, 2000, 1000, 500, 200, 100};
const int banknoteTypesCount = 6;

// refillCashMachine restocks the cash machine (cashFile) with new banknotes.
// New banknotes are sorted in descending order.
// Return true if success, false otherwise.
int refillCashMachine(std::string cashMachFilename) {
    std::fstream cashFile(cashMachFilename, std::ios::out);
    if (cashFile.fail())
        return FILE_OPEN_FAILURE;
    int banknotes[6] = {0, 0, 0, 0, 0, 0};

    std::srand(time(nullptr));

    // The banknote generation procedure bellow is equivalent to generating random banknotes and sorting them.
    for (int i = 0; i < bankNotesMaxCount; i++)
        banknotes[rand() % banknoteTypesCount]++;

    for (int i = 0; i < banknoteTypesCount; i++) {
        for (int j = 0; j < banknotes[i]; j++) {
            cashFile << std::endl << banknoteTypes[i];
        }
    }

    cashFile.close();
    return SUCCESS;
}

int banknote2Index(int banknote) {
    return banknote == 5000 ? 0 :
           banknote == 2000 ? 1 :
           banknote == 1000 ? 2 :
           banknote == 500 ? 3 :
           banknote == 200 ? 4 :
           banknote == 100 ? 5 : -1;
}

//
int withdrawCashMachine(std::string cashMachFilename, int value) {

    std::fstream cashFile(cashMachFilename, std::ios::in);
    if (cashFile.fail())
        return FILE_OPEN_FAILURE;

    // banknotesToKeep will store the total number of banknotes of each type
    // excluding the ones withdrawn.
    int banknotesToKeep[6] = {0, 0, 0, 0, 0, 0};

    while (!cashFile.eof()) {
        int banknote = 0;
        cashFile >> banknote;
        int index = banknote2Index(banknote);

        if (index == -1)
            return FILE_WRONG_FORMAT;

        std::cout << "value = "<< value << ", banknote = " << banknote << std::endl;
        if (value >= banknote)
            value -= banknote;
        else
            banknotesToKeep[index]++;
    }

    if (value != 0)
        return NOT_ENOUGH_CASH;

    cashFile.close();
    cashFile.open(cashMachFilename, std::fstream::out | std::fstream::trunc);
    if (cashFile.fail())
        return FILE_OPEN_FAILURE;

    for (int i = 0; i < banknoteTypesCount; i++) {
        for (int j = 0; j < banknotesToKeep[i]; j++) {
            cashFile << std::endl << banknoteTypes[i];
        }
    }
    return SUCCESS;
}

int main() {
    std::string input;
    std::cout << "Enter \"+\" to refill the cash machine.\n"
                 "Enter \"-\" to withdraw from the cash machine.\n" << std::endl;
    std::getline(std::cin, input);

    if (input != "+" && input != "-") {
        std::cout << "Error! Incorrect command! Exiting.\n";
        return 0;
    }

    std::string cashMachFilename;
    std::cout << "Enter full path to the cash_machine.txt file:\n";
    std::getline(std::cin, cashMachFilename);

    if (input == "+") {
        // Note: refilling does not keep previously stored banknotes.
        // The storage is fully renewed.

        // Why redoing the function definition to accept 'std::fstream' rather then '&std::fstream' gives the following:
        // Call to deleted constructor of 'std::fstream' (aka 'basic_fstream<char, char_traits<char>>')
        if (refillCashMachine(cashMachFilename) == FILE_OPEN_FAILURE) {
            std::cout << "Error! File cannot be opened! Exiting.\n";
            return 0;
        }
        std::cout << "Cash machine refilled successfully!";

    } else {

        std::string stringValue;
        std::cout << "Enter the sum to withdraw: ";
        std::cin >> stringValue;
        int value;
        if ((value = std::stoi(stringValue)) <= 0 ||
             value % 100 != 0) {
            std::cout << "Error! Incorrect value entered! Exiting.\n";
            return 0;            
        }

        int err;
        if ((err = withdrawCashMachine(cashMachFilename, value)) != SUCCESS) {
            if (err == FILE_OPEN_FAILURE)
                std::cout << "Error! File cannot be opened!\n";
            if (err == FILE_WRONG_FORMAT)
                std::cout << "Error! File has incorrect format!\n";
            if (err == NOT_ENOUGH_CASH)
                std::cout << "Error! Not enough cash.\n";
            return 0;
        }
        std::cout << "Withdrawn " << value << " successfully!";
    }

    return 0;
}
