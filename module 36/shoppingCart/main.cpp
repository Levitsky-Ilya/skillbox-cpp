#include <iostream>
#include <sstream>
#include "productContainer.h"

int main() {
    ProductContainer shop, cart;

    std::string command, productName;
    std::stringstream commandStream;
    int productCount;

    /*
     * Filling the stock in the online shop.
     */

    std::cout << "Enter the stock data for the shop.\n"
                 "Type <name> <count> to add \"count\" pieces of \"name\" stock.\n"
                 "Type  stop  to finish.\n";

    while (command != "stop") {
        std::getline(std::cin, command);
        commandStream << command;
        commandStream >> command;

        if (command.empty() || command == "stop") {
            commandStream.clear();
            continue;
        }

        productName = command;
        commandStream >> productCount;
        commandStream.clear();

        try {
            shop.addToContainer(productName, productCount);
        } catch (std::exception &e){
            std::cerr << "Exception: " << e.what() << "\n";
        }
    }

    /*
     * Shop is ready. Start buying.
     */

    std::cout << "\n *** Welcome to the online shop! *** \n\n"
                 "Type  add <name> <count>  to add \"count\" pieces of \"name\" to the cart.\n"
                 "Type  remove <name> <count>  to remove \"count\" pieces of \"name\" from the cart.\n"
                 "Type \"buy\" to make a purchase.\n";

    while (command != "buy") {
        std::getline(std::cin, command);
        commandStream << command;
        commandStream >> command;

        if (command.empty() || command == "buy") {
            continue;
        }

        productName.clear();
        productCount = 0;
        commandStream >> productName >> productCount;
        commandStream.clear();

        if (command == "add") {
            try {
                shop.removeFromContainer(productName, productCount);
                cart.addToContainer(productName, productCount);
                std::cout << "Added " << productCount << " of " << productName << ".\n";
            } catch (std::exception &e){
                std::cout << "Error: " << e.what() << ". Try again.\n";
            }
        } else if (command == "remove") {
            try {
                cart.removeFromContainer(productName, productCount);
                shop.addToContainer(productName, productCount);
                std::cout << "Removed " << productCount << " of " << productName << ".\n";
            } catch (std::exception &e){
                std::cout << "Error: " << e.what() << ". Try again.\n";
            }
        } else {
            std::cout << "Unknown command. Try again.\n";
        }
    }

    std::cout << "Thank you for your purchase!\n";

    return 0;
}
