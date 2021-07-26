#include <iostream>
#include <sstream>

#include "Player.h"

int main() {
    Player player;
    player.downloadTracks();

    std::cout << "Player turned on\n\n" << std::endl;

    std::string command, argument;
    std::stringstream commandStream;
    while (command != "exit") {
        std::cout << "Enter command: play <track name>/pause/next/stop/exit\n";
        std::getline(std::cin, command);
        commandStream << command;
        commandStream >> command >> argument;
        commandStream.clear();
        if (command == "play") {
            player.play(argument);
        } else if (command == "pause") {
            player.pause();
        } else if (command == "next") {
            player.next();
        } else if (command == "stop") {
            player.stop();
        } else if (command != "exit") {
            std::cout << "Unknown command\n";
        }
    }
    std::cout << "Player turned off\n";
    return 0;
}
