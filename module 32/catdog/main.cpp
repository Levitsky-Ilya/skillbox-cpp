#include "Animal.h"

void meeting(Animal* a, Animal* b) {
    a->meetWith(*b);
    std::cout << " ";
    b->meetWith(*a);
    std::cout << "\n";
}

int main() {
    Cat dog;
    Cat cat;
    meeting(&dog, &cat);
    return 0;
}
