//
// Created by leviz on 11.10.2021.
//

#include "productContainer.h"

void ProductContainer::addToContainer(const std::string& productName, int productCount) {
    if (productCount <= 0) {
        throw std::invalid_argument("productCount");
    }

    m_container[productName] += productCount;
}

void ProductContainer::removeFromContainer(const std::string& productName, int productCount) {
    if (productCount <= 0) {
        throw std::invalid_argument("productCount must be positive");
    }

    if (m_container.find(productName) == m_container.end()) {
        throw std::invalid_argument("no " + productName + " found");
    }

    int& productCountNow = m_container[productName];

    if (productCountNow < productCount) {
        throw std::invalid_argument("productCount is too big");
    }

    productCountNow -= productCount;

    if (productCountNow == 0) {
        m_container.erase(productName);
    }
}
