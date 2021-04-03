#include <iostream>
#include <string>
#include <vector>
#include <map>

//checkPhone is a simple verification that the number contains only digits and '-'.
bool checkPhone(const std::string& number) {
    for (char ch : number)
        if (!isdigit(ch) && ch != '-') return false;
    return true;
}

int main() {
    std::cout << "Welcome to Phonebook!" << std::endl;
    std::map<std::string, std::string> numberKeysPhonebook;
    std::map<std::string, std::vector<std::string>> nameKeysPhonebook;

    while (true) {
        std::cout << "Enter a new phone-name pair, enter a phone, or a name:" << std::endl;
        std::string input1, input2;
        std::getline(std::cin, input1);
        int spacePos = input1.find(' ');

        if(spacePos != std::string::npos) {
            input2 = input1.substr(spacePos + 1);
            input1 = input1.substr(0, spacePos);
        }
        if (input2.empty()) {
            if (!checkPhone(input1)) { // A name was entered.
                // auto is std::map<std::string, std::vector<std::string>>::iterator
                auto nameEntry = nameKeysPhonebook.find(input1);
                if (nameEntry == nameKeysPhonebook.end())
                    std::cout << "Name " << input1 << " was not found in the phonebook.\n";
                else {
                    std::cout << "Name " << input1 << ":";
                    for (const std::string& phoneNumber : nameEntry->second)
                        std::cout << phoneNumber << " ";
                    std::cout << std::endl;
                }
            } else { // A phone number was entered
                if (numberKeysPhonebook.find(input1) == numberKeysPhonebook.end())
                    std::cout << "Phone " << input1 << " was not found in the phonebook.\n";
                else
                    std::cout << "Phone "  << input1 << " is owned by " << numberKeysPhonebook[input1] << ".\n";
            }
        } else if (!checkPhone(input1)) { // The first argument is expected to be a number
            std::cout << "Wrong input. Exiting.\n";
            break;
        } else {
            // Before writing a new number-name pair, remove the old name form phonebook
            std::string oldName = numberKeysPhonebook[input1]; // find the old name in phonebook
            if (!oldName.empty()) { // if found - remove it
                // find the iterator that points to the number searched
                auto itNumber = nameKeysPhonebook[oldName].begin();
                for (; *itNumber != input1 && itNumber != nameKeysPhonebook[oldName].end(); itNumber++);
                // remove the number
                nameKeysPhonebook[oldName].erase(itNumber);
                if (nameKeysPhonebook[oldName].empty()) // if no numbers left for the name
                    nameKeysPhonebook.erase(oldName); // remove the name from the phonebook
            }

            numberKeysPhonebook[input1] = input2;
            nameKeysPhonebook[input2].push_back(input1);
            std::cout << "Phone book updated: phone "  << input1 << " is owned by " << input2 << ".\n";
        }
    }
    return 0;
}
