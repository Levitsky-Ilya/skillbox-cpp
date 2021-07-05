//
// Created by leviz on 30.06.2021.
//

#include "ram.h"

Ram ram;

void read(Ram in) {
    ram = in;
}

Ram write() {
    return ram;
}