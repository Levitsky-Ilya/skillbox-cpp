//
// Created by leviz on 30.06.2021.
//

#include "gpu.h"

void display(std::string out) {
    std::cout << out;
}

void displayNumbers() {
    Ram mem = write();
    std::string outStr;
    for (int num : mem) {
        outStr += std::to_string(num) + " ";
    }
    display(outStr + "\n");
}
