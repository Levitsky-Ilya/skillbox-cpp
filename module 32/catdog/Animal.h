//
// Created by leviz on 16.08.2021.
//

#ifndef CATDOG_ANIMAL_H
#define CATDOG_ANIMAL_H

#include <iostream>

// Using run time type comparison via dynamic_cast

class Animal {
public:
    virtual void meetWith(Animal& other) = 0;
};

class Cat : public Animal {
public:
    void meetWith(Animal& other) override;
};

class Dog : public Animal {
public:
    void meetWith(Animal& other) override;
};

#endif //CATDOG_ANIMAL_H
