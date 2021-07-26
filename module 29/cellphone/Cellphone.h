//
// Created by leviz on 06.07.2021.
//

#pragma once

#include <iostream>
#include <vector>
#include "Contact.h"

class Cellphone {
    enum Action {
        NO_ACTION,
        CALL,
        SMS
    };

    std::vector<Contact> contacts;

    void action(Action action, const std::string& callee, const std::string& msg);

public:

    void addContact(const std::string& name, const std::string& number);

    void call(const std::string& callee);

    void sms(const std::string& callee, const std::string& msg);
};
