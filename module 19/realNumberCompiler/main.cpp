#include <iostream>
#include <string>
#include <climits>

bool checkIfDigits(std::string str) {
    for (char ch : str)
        if (ch < '0' || ch > '9')
            return false;
    return true;
}

int main() {
    std::string wholePartString, fractionalPartString;
    bool negative;

    std::cout << "Input whole part of the real number: " << std::endl;
    std::cin >> wholePartString;
    if (wholePartString[0] == '-') {
        wholePartString = wholePartString.substr(1,wholePartString.size() - 1);
        negative = true;
    }
    if (!checkIfDigits(wholePartString)) {
        std::cout << "Error! Incorrect number." << std::endl;
        return 0;
    }

    std::cout << "Input fractional part of the real number: " << std::endl;
    std::cin >> fractionalPartString;
    if (!checkIfDigits(fractionalPartString)) {
        std::cout << "Error! Incorrect number." << std::endl;
        return 0;
    }

    double number = std::stod(wholePartString + "." + fractionalPartString);
    if (negative) number = -number;

    std::cout << "Your real number: " << std::to_string(number) << std::endl;
    return 0;
}
