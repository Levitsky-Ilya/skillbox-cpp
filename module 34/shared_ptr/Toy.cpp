//
// Created by leviz on 24.09.2021.
//

#include "Toy.h"

void Toy::setName(std::string name) {
    m_name = name;
}

void Toy::setAge(int age) {
    if (age >= 0 && age <= 30) {
        m_age = age;
    }
}

std::string Toy::getName() {
    return m_name;
}

int Toy::getAge() {
    return m_age;
}
