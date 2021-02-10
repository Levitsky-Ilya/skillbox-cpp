#include <iostream>
#include <string>
#include <climits>


int main() {
    int wholePartInt, fractionalPartInt;
    std::cout << "Input whole part of the real number: " << std::endl;
    std::cin >> wholePartInt;
    if (wholePartInt < 0 || wholePartInt == INT_MAX) {
        std::cout << "Error! Too big or too small number." << std::endl;
        return 0;
    }
    std::cout << "Input fractional part of the real number: " << std::endl;
    std::cin >> fractionalPartInt;
    if (fractionalPartInt < 0 || fractionalPartInt == INT_MAX) {
        std::cout << "Error! Too big or too small number." << std::endl;
        return 0;
    }

    double fraction = (double) fractionalPartInt;
    while (fraction >= 1) {
        fraction /= 10;
    }
    double number = (double) wholePartInt + fraction;

    std::cout << "Your real number: " << std::to_string(number) << std::endl;
    return 0;
}
