//
// Created by leviz on 24.09.2021.
//

#ifndef SHARED_PTR_TOY_H
#define SHARED_PTR_TOY_H

#include <iostream>
#include "Toy.h"

class shared_ptr_toy {
public:
    // *** Constructor *** //
    shared_ptr_toy() {
        m_toy = new Toy;
        m_nRefs = new int(1);
    }

    // *** Copy constructor *** //
    shared_ptr_toy(const shared_ptr_toy &oth) {
        m_toy = oth.m_toy;
        m_nRefs = oth.m_nRefs;
        (*m_nRefs)++;
    }

    void reset() {
        (*m_nRefs)--;
        if (*m_nRefs == 0) {
            std::cout << "Resetting " << m_toy->getName() << std::endl;
            delete m_toy;
            delete m_nRefs;
        }
        m_toy = nullptr;
        m_nRefs = nullptr;
    }

    // *** Assignment operator *** //
    shared_ptr_toy& operator=(const shared_ptr_toy &oth) {
        if (this == &oth) {
            return *this;
        }

        if (m_toy != nullptr) {
            reset();
        }
        m_toy = oth.m_toy;
        m_nRefs = oth.m_nRefs;
        (*m_nRefs)++;
        return *this;
    }

    // *** Destructor *** //
    ~shared_ptr_toy() {
        reset();
    }

    shared_ptr_toy make_shared_toy(std::string name, int age) {
        reset();
        m_toy = new Toy(name, age);
        m_nRefs = new int(1);
        return *this;
    }

    shared_ptr_toy make_shared_toy(std::string name) {
        return make_shared_toy(name, 0);
    }

    shared_ptr_toy make_shared_toy(int age) {
        return make_shared_toy("unknown", age);
    }

    shared_ptr_toy make_shared_toy(const Toy& toy) {
        reset();
        m_toy = new Toy(toy);
        m_nRefs = new int(1);
        return *this;
    }

private:

    int* m_nRefs = nullptr;
    Toy* m_toy = nullptr;
};


#endif //SHARED_PTR_TOY_H
