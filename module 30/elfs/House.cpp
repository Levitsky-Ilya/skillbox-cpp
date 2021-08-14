//
// Created by leviz on 09.08.2021.
//

#include "House.h"

House::House()
{
    m_ownerName = "none";
    m_occupied = false;
}

bool House::isOwnerNameNone(const std::string &ownerName) {
    return (ownerName.empty() ||
            ownerName == "none" ||
            ownerName == "None");
}

House::House(const std::string& ownerName) : m_ownerName(ownerName)
{
    ASSERT_THIS_NULLPTR
    m_occupied = !isOwnerNameNone(ownerName);
    if (!m_occupied) {
        m_ownerName = "none";
    }
}

std::string House::getOwnerName() {
    ASSERT_THIS_NULLPTR
    return m_ownerName;
}

void House::setNewOwner(const std::string& newOwnerName) {
    ASSERT_THIS_NULLPTR
    assert(!isOwnerNameNone(newOwnerName));
    m_ownerName = newOwnerName;
    m_occupied = true;
}

void House::removeOwner() {
    ASSERT_THIS_NULLPTR
    m_ownerName = "none";
    m_occupied = false;
}

bool House::isOccupied() {
    ASSERT_THIS_NULLPTR
    return m_occupied;
}

