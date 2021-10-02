#include <iostream>
#include "shared_ptr_toy.h"

int main() {
    shared_ptr_toy a;
    a.make_shared_toy("Ball", 5);

    shared_ptr_toy b = a;

    shared_ptr_toy c;
    c.make_shared_toy("Doll");
    a = c;

    Toy toy("Coal", 20);

    shared_ptr_toy d;
    d.make_shared_toy(toy);

    a = d;
    b = d;

    shared_ptr_toy e;
    e.make_shared_toy(15);

    e = a;


    return 0;
}
