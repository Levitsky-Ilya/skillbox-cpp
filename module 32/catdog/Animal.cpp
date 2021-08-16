//
// Created by leviz on 16.08.2021.
//

#include "Animal.h"

void Cat::meetWith(Animal &other) {
    // dynamic_cast to a pointer type returns NULL if the cast fails
    // (dynamic_cast to a reference type would throw an exception on failure)
    if (Cat* cat = dynamic_cast<Cat*>(&other)) {
        std::cout << "Purr";
    } else if (Dog* dog = dynamic_cast<Dog*>(&other)) {
        std::cout << "Meow";
    } else {
        return;
    }
}

void Dog::meetWith(Animal &other) {
    if (Cat* cat = dynamic_cast<Cat*>(&other)) {
        std::cout << "Bark";
    } else if (Dog* dog = dynamic_cast<Dog*>(&other)) {
        std::cout << "Woof";
    } else {
        return;
    }
}
