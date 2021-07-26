#include "ram.h"
#include "cpu.h"
#include "disk.h"
#include "gpu.h"
#include "kbd.h"

int main() {
    display("PC booted.\n");
    std::string command;
    do {
        display("Enter command <sum/save/load/input/display/exit>\n");
        command = inputCommand();
        if (command == "sum") {
            compute();
        } else if (command == "save") {
            save();
        } else if (command == "load") {
            load();
        } else if (command == "input") {
            inputNumbers();
        } else if (command == "display") {
            displayNumbers();
        } else if (command != "exit") {
            display("Unknown command\n");
        }
    } while (command != "exit");
    display("PC shut down.\n");
}
