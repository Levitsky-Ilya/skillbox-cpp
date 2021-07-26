#include <iostream>
#include <sstream>
#include "Cellphone.h"

int main() {
    Cellphone cellphone;

    std::cout << "Cellphone turned on\n"
                 "Commands:\n"
                 " add <name> <number>\n"
                 " call <name/number>\n"
                 " sms <name/number> <message_no_spaces>\n"
                 " exit\n";

    std::string command, argument1, argument2;
    std::stringstream commandStream;
    while (command != "exit") {
        argument1 = argument2 = "";
        std::getline(std::cin, command);
        commandStream << command;
        commandStream >> command >> argument1 >> argument2;
        commandStream.clear();
        if (command == "add") {
            cellphone.addContact(argument1, argument2);
        } else if (command == "call") {
            cellphone.call(argument1);
        } else if (command == "sms") {
            cellphone.sms(argument1, argument2);
        } else if (command != "exit") {
            std::cout << "Unknown command\n";
        }
    }
    std::cout << "Cellphone turned off\n";
    return 0;
}
