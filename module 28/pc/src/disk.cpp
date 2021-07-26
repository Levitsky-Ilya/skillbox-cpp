//
// Created by leviz on 30.06.2021.
//

#include "disk.h"

std::string filename = "../data.txt";

void save() {
    std::ofstream saveFile;
    saveFile.open(filename, std::ios::binary);
    if (saveFile.fail()) {
        display("Disk error! Cannot save RAM!\n");
        return;
    }
    // save() read directly from RAM
    for (int num : ram) {
        saveFile.write((char*) &num, sizeof(num));
    }
    display("RAM saved to disk.\n");
    saveFile.close();
}

void load() {
    std::ifstream loadFile;
    loadFile.open(filename, std::ios::binary);
    if (loadFile.fail()) {
        display("Disk error! Cannot load RAM!\n");
        return;
    }
    // load() writes directly to RAM
    for (int &num : ram) {
        loadFile.read((char*) &num, sizeof(num));
    }
    display("RAM loaded to disk.\n");
    loadFile.close();
}