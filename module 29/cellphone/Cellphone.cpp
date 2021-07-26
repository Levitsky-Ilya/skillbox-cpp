//
// Created by leviz on 06.07.2021.
//

#include "Cellphone.h"

void Cellphone::action(Action action, const std::string& callee, const std::string& msg) {

    if (callee.substr(0,2) == "+7") {
        if (Contact::isNumberValid(callee)) {
            if (action == CALL) {
                std::cout << "Calling " << callee << "... Done!\n";
            } else if (action == SMS) {
                std::cout << "Sending SMS \"" << msg << "\" to " << callee << "... Done!\n";
            } else {
                std::cout << "Error! Unknown action.\n";
            }
        } else {
            std::cout << "Number is invalid.\n";
        }
    } else {
        bool contactFound = false;
        for (const auto &contact : contacts) {
            if (contact.getName() == callee) {
                contactFound = true;
                if (action == CALL) {
                    std::cout << "Calling " << callee << " (" << contact.getNumber() << ")... Done!\n";
                } else if (action == SMS) {
                    std::cout << "Sending SMS \"" << msg << "\" to "
                              << callee << " (" << contact.getNumber() << ")... Done!\n";
                } else {
                    std::cout << "Error! Unknown action.\n";
                }
                break;
            }
        }
        if (!contactFound) {
            std::cout << "Contact name \"" << callee << "\" not found.\n";
        }
    }
}

void Cellphone::addContact(const std::string& name, const std::string& number) {
    Contact contact;
    contact.create(name, number);
    contacts.push_back(contact);
}

void Cellphone::call(const std::string& callee) {
    action(CALL, callee, "");
}

void Cellphone::sms(const std::string& callee, const std::string& msg) {
    action(SMS, callee, msg);
}
