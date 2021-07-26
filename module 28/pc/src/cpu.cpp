//
// Created by leviz on 30.06.2021.
//

#include "cpu.h"

void compute() {
    Ram regs = write();
    int regSum = 0;
    for (int reg : regs) {
        regSum += reg;
    }
    display(std::to_string(regSum) + "\n");
}
