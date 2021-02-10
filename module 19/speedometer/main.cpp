#include <iostream>
#include <string>

int main() {
    float speed = 0.0;
    std::cout << "Hello, I am SmartCar. My speed is 0.0\n";

    float delta;
    char speedString[20];
    do {
        std::cout << "Input delta speed: ";
        std::cin >> delta;
        if (delta > 150)
            delta = 150;
        speed += delta;
        if (speed > 150)
            speed = 150;
        std::sprintf(speedString, "%.1f", speed);
        if (speed >= 0.01)
            std::cout << "SmartCar's speed is " << speedString << std::endl;
    } while (speed >= 0.01);

    std::cout << "SmartCar stopped.\n";
}
