#include <sstream>
#include "registry.h"

int main() {

    Registry<int, int> registry;

    std::string command;
    std::stringstream commandStream;
    int key; // int was used for this test
    int value; // int was used for this test

    std::cout << "\nWelcome to The Registry!\n\n"
                 "Type  add <key> <value>  to add the value with the key to the registry.\n"
                 "Type  remove <key>  to remove all values the the key from the registry.\n"
                 "Type  print <key>  to print to console all values the the key from the registry.\n"
                 "Type  find <key>  to exit the program.\n"
                 "Type  stop  to exit the program.\n";

    while (command != "stop") {
        std::getline(std::cin, command);
        commandStream << command;
        commandStream >> command;

        if (command.empty() || command == "stop") {
            continue;
        }

        commandStream >> key;

        if (command == "add") {
            commandStream >> value;
            registry.add(key, value);
            std::cout << "The value " << value << " with key " << key << " is added to the registry.\n";
        } else if (command == "remove") {
            registry.remove(key);
            std::cout << "All values with key " << key << " are removed from the registry.\n";
        } else if (command == "print") {
            registry.print(key);
        } else if (command == "find") {
            auto vec = registry.find(key);
            std::cout << "There are " << vec.size() << " matching values found in the registry.\n";
        } else {
            std::cout << "Unknown command. Try again.\n";
        }

        commandStream.clear();
    }

    std::cout << "Exiting\n";

    return 0;
}
