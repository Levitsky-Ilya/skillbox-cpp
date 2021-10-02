//
// Created by leviz on 24.09.2021.
//

#ifndef TOY_H
#define TOY_H

#include <string>

class Toy {
public:

    Toy(std::string name, int age) : m_name(name) {
        m_age = (age >= 0 && age <= 30) ? age : 0;
    }

    Toy(std::string name) : Toy(name, 0) {}
    Toy(int age) : Toy("unknown", age) {}
    Toy() : Toy("unknown", 0) {}

    Toy(Toy const &toy): m_name(toy.m_name), m_age(toy.m_age) {}


    void setName(std::string name);
    void setAge(int age);
    std::string getName();
    int getAge();

private:
    std::string m_name;
    int m_age;
};


#endif //TOY_H
