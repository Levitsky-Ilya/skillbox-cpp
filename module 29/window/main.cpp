#include <iostream>
#include <sstream>
#include "Window.h"

int main() {
    Window window;

    std::cout << "Window is created\n"
                 "Commands:\n"
                 " move <coord_x> <coord_y>\n"
                 " resize <width> <height>\n"
                 " display\n"
                 " close\n";

    std::string command, argument1, argument2;
    std::stringstream commandStream;
    while (command != "close") {
        argument1 = argument2 = "";
        std::getline(std::cin, command);
        commandStream << command;
        commandStream >> command >> argument1 >> argument2;
        commandStream.clear();
        if (command == "move") {
            PixelCoords pixelCoords;
            pixelCoords.setPixelCoords({std::stoi(argument1), std::stoi(argument2)});
            window.move(pixelCoords);
        } else if (command == "resize") {
            window.resize(std::stoi(argument1), std::stoi(argument2));
        } else if (command == "display") {
            window.display();
        } else if (command != "exit") {
            std::cout << "Unknown command\n";
        }
    }
    std::cout << "Window is closed\n";
    return 0;
}
