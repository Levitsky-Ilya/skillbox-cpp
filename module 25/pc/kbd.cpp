//
// Created by leviz on 30.06.2021.
//

#include "kbd.h"

std::string inputCommand() {
    display(">");
    std::string command;
    std::cin >> command;
    return command;
}

void inputNumbers() {
    display("Enter 8 numbers:");
    Ram in;
    for (int &num : in) {
        std::cin >> num;
    }
    read(in);
}