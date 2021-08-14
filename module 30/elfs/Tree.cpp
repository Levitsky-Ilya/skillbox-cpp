//
// Created by leviz on 09.08.2021.
//

#include "Tree.h"

/// Branch ///

Branch::Branch(int housesCount, Branch* parent = nullptr) :
    m_houses(housesCount),
    m_houseStats({housesCount, 0}),
    m_totalHouseStats({housesCount, 0}),
    m_parentBranch(parent)
{
    for (auto& house : m_houses) {
        // Fill the branch with new empty houses
        house = new House;
    }

    if (parent != nullptr) {
        m_level = parent->m_level + 1;
        m_name = parent->m_name + std::to_string(parent->m_childBranches.size()) + "/";
        parent->addTotalHouseStats({housesCount, 0});
    } else {
        m_level = 0;
        m_name = "";
    }
}

HouseStats Branch::getHousesStats() const {
    ASSERT_THIS_NULLPTR
    return m_houseStats;
}

void Branch::addTotalHouseStats(HouseStats houseStats) {
    ASSERT_THIS_NULLPTR
    m_totalHouseStats.housesCount += houseStats.housesCount;
    m_totalHouseStats.occupiedHousesCount += houseStats.occupiedHousesCount;
    if (m_parentBranch != nullptr) {
        m_parentBranch->addTotalHouseStats(houseStats);
    }
}

HouseStats Branch::getTotalHousesStats() const {
    return m_totalHouseStats;
}

Branch *Branch::growChildBranch(int housesCount) {
    ASSERT_THIS_NULLPTR
    auto* branchPtr = new Branch(housesCount, this);
    m_childBranches.push_back(branchPtr);
    return branchPtr;
}

bool Branch::findOwner(const std::string &ownerName) const {
    for (auto house : m_houses) {
        if (house->getOwnerName() == ownerName) {
            return true;
        }
    }

    for (auto childBranch : m_childBranches) {
        if (childBranch->findOwner(ownerName)) {
            return true;
        }
    }
}

/// Tree ///

Tree::Tree() : Branch(0) {}