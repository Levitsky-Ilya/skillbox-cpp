//
// Created by leviz on 13.08.2021.
//

#ifndef ELFS_TREEHELPER_H
#define ELFS_TREEHELPER_H

#include <cstdlib>
#include "Tree.h"

const int maxLevel = 2;
const int minChildrenPerLevel[] = {3, 2};
const int maxChildrenPerLevel[] = {5, 3};

// populateBranch initiates process of populating each house on branch.
// User inputs owner name of each house.
void populateBranch(Branch* branch);

// growBranchesHelper grows a random number of children branches (in a range that depends on level),
// populates each children branch. Each children updates statistics on their parent branches.
void growBranchesHelper(Branch* branch);

// findOwnersNeighborsCount searches through the tree for elf with name ownerName.
// The result of search is printed in console. If found, a number of his neighbours
// on the same branch of level 1 is printed.
void findOwnersNeighborsCount(const Tree& tree, const std::string& ownerName);

#endif //ELFS_TREEHELPER_H
