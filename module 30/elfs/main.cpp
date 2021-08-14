#include <iostream>
#include "Tree.h"
#include "TreeHelper.h"

int main() {
    srand(time(nullptr));
    Tree tree;

    std::cout << "Tree is created!\n";

    growBranchesHelper(&tree);

    while (true) {

        std::cout << "Type name of the elf:\n";
        std::string ownerName;
        std::cin >> ownerName;

        findOwnersNeighborsCount(tree, ownerName);
    }

    return 0;
}
