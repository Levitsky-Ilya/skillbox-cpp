//
// Created by leviz on 11.10.2021.
//

#ifndef SHOPPINGCART_PRODUCTCONTAINER_H
#define SHOPPINGCART_PRODUCTCONTAINER_H

#include <stdexcept>
#include <map>
#include <string>

//TODO add displayContainer

class ProductContainer {
public:

    void addToContainer(const std::string& productName, int productCount);

    void removeFromContainer(const std::string& productName, int productCount);

private:
    std::map<std::string, int> m_container;
};


#endif //SHOPPINGCART_PRODUCTCONTAINER_H
