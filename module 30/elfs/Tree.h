//
// Created by leviz on 09.08.2021.
//

#ifndef ELFS_TREE_H
#define ELFS_TREE_H

#include <iostream>
#include <vector>

#include "House.h"

struct HouseStats {
    int housesCount;
    int occupiedHousesCount;
};

class Branch {
public:

    // Branch constructor creates branch with housesCount empty houses,
    // updates its statistic of the parent branch.
    explicit Branch(int housesCount, Branch* parent);

    // getHousesStats returns number of houses on this branch.
    [[nodiscard]] HouseStats getHousesStats() const;

    // addTotalHouseStats adds a total number of houses to this branch and a parent branch.
    void addTotalHouseStats(HouseStats houseStats);

    // getTotalHousesStats returns total number of houses on this branch and all children branches.
    [[nodiscard]] HouseStats getTotalHousesStats() const;

    // growChildBranch adds a new Branch pointer to m_childBranches vector.
    // The new branch has housesCount new empty houses.
    Branch* growChildBranch(int housesCount);

    // findOwner searches recursively through the branch for house owner with name ownerName.
    [[nodiscard]] bool findOwner(const std::string& ownerName) const;

    int m_level;
    std::string m_name;
    std::vector<House*> m_houses;
    HouseStats m_houseStats;
    HouseStats m_totalHouseStats;
    std::vector<Branch*> m_childBranches;
    Branch *m_parentBranch;
};

class Tree : public Branch {
public:

    // Tree constructor creates tree with no branches.
    Tree();
};


#endif //ELFS_TREE_H
