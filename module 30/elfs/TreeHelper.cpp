//
// Created by leviz on 13.08.2021.
//

#include "TreeHelper.h"

void populateBranch(Branch* branch) {
    assert(branch != nullptr);

    auto [housesCount, oldOccupiedHousesCount] = branch->m_houseStats;
    int newOccupiedHousesCount = 0;

    for (int index = 0; index < housesCount; index++) {
        std::string ownerName;
        std::cout << "Who lives in house #" << index << "?\n";
        std::cin >> ownerName;

        House* house = branch->m_houses[index];
        bool houseOccupied = house->isOccupied();

        if (!House::isOwnerNameNone(ownerName)) {
            // set new owner
            house->setNewOwner(ownerName);

            // update occupiedHousesCount if house was not occupied
            branch->m_houseStats.occupiedHousesCount += !houseOccupied;
            branch->m_totalHouseStats.occupiedHousesCount += !houseOccupied;

            newOccupiedHousesCount++;
            std::cout << "Elf " << ownerName << " now occupies house #" << index << ".\n";
        } else {
            // remove old owner
            house->removeOwner();

            // update occupiedHousesCount if house was occupied
            branch->m_houseStats.occupiedHousesCount -= houseOccupied;
            branch->m_totalHouseStats.occupiedHousesCount -= houseOccupied;

            std::cout << "House #" << index << " is empty.\n";
        }
    }

    branch->m_parentBranch->addTotalHouseStats({0, newOccupiedHousesCount - oldOccupiedHousesCount});
}

void growBranchesHelper(Branch* branch) {
    int level = branch->m_level;
    if (level >= maxLevel) {
        return;
    }

    int minChildren = minChildrenPerLevel[level];
    int childrenRange = maxChildrenPerLevel[level] - minChildren + 1;
    int childrenCount = minChildren + (rand() % childrenRange);
    for (int i = 0; i < childrenCount; i++) {
        std::cout << "How many houses are on branch " << branch->m_name << i << "/ ?\n";
        int housesCount;
        std::cin >> housesCount;
        auto* childBranch = branch->growChildBranch(housesCount);
        populateBranch(childBranch);
        growBranchesHelper(childBranch);
    }
}

void findOwnersNeighborsCount(const Tree& tree, const std::string& ownerName) {
    for (const auto& branch : tree.m_childBranches) {
        if (branch->findOwner(ownerName)) {
            std::cout << "Elf " << ownerName << " is found somewhere on branch " << branch->m_name
                      << " and has " << branch->getTotalHousesStats().occupiedHousesCount - 1 << " neighbors on this branch.\n";
            return;
        }
    }
    std::cout << "Elf " << ownerName << " was not found.\n";
}