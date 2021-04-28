#include <iostream>

#define WINTER

int main() {
#ifdef SPRING
    std::cout << "SPRING" << std::endl;
#endif
#ifdef SUMMER
    std::cout << "SUMMER" << std::endl;
#endif
#ifdef AUTUMN
    std::cout << "AUTUMN" << std::endl;
#endif
#ifdef WINTER
    std::cout << "WINTER" << std::endl;
#endif
}

/* Second program realization

 #define WINTER 1

int main() {
#if SPRING
    std::cout << "SPRING" << std::endl;
#endif
#if SUMMER
    std::cout << "SUMMER" << std::endl;
#endif
#if AUTUMN
    std::cout << "AUTUMN" << std::endl;
#endif
#if WINTER
    std::cout << "WINTER" << std::endl;
#endif
}
 */
