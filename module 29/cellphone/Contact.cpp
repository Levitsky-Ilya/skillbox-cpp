//
// Created by leviz on 06.07.2021.
//

#include "Contact.h"

bool Contact::isNumberValid(const std::string &number) {
    return (number.size() == 12 &&
        number.substr(0,2) == "+7" &&
        number.substr(2, 10).find_first_not_of("0123456789") == std::string::npos);
}

void Contact::setName(const std::string &name) {
    Contact::name = name;
}

void Contact::setNumber(const std::string &number) {
    Contact::number = number;
}

const std::string &Contact::getName() const {
    return name;
}

const std::string &Contact::getNumber() const {
    return number;
}

// create() initializes Contact class members. Returns the bool success status.
bool Contact::create(const std::string &name, const std::string &number) {
    if (!isNumberValid(number)) {
        std::cout << "Number is invalid.\n";
        return false;
    }
    setName(name);
setNumber(number);
    std::cout << "New contact is created.\n";
    return true;
}
