//
// Created by leviz on 09.08.2021.
//

#ifndef ELFS_HOUSE_H
#define ELFS_HOUSE_H

#define ASSERT_THIS_NULLPTR assert(this != nullptr);

#include <cassert>
#include <string>

class House {
public:

    House();

    explicit House(const std::string& ownerName);

    static bool isOwnerNameNone(const std::string& ownerName);

    std::string getOwnerName();

    void setNewOwner(const std::string& newOwnerName);

    void removeOwner();

    bool isOccupied();

private:

    std::string m_ownerName;
    bool m_occupied;
};


#endif //ELFS_HOUSE_H
