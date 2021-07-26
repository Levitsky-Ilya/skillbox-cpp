//
// Created by leviz on 06.07.2021.
//

#pragma once

#include <iostream>

class Contact {
    std::string name;
    std::string number;

    void setName(const std::string &name);

    void setNumber(const std::string &number);

public:

    static bool isNumberValid(const std::string& number);

    const std::string &getName() const;

    const std::string &getNumber() const;

    bool create(const std::string &name, const std::string &number);
};
