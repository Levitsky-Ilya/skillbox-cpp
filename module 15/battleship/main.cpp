#include <iostream>

int main() {
    bool tiny_field [3*3];
    bool small_field [7*7];
    bool medium_field [10*10];
    bool large_field [20*20];
    std::cout << sizeof(tiny_field) << " " <<
        sizeof(small_field) << " " <<
        sizeof(medium_field) << " " <<
        sizeof(large_field) << std::endl;
}
