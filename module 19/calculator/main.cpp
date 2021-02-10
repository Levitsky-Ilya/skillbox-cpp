#include <iostream>
#include <sstream>

int main() {
    std::string input;
    std::stringstream inputStream;
    std::cout << "Input equation: " << std::endl;
    std::cin >> input;

    double leftOperand = 0, rightOperand = 0;
    char operation;
    inputStream << input;
    inputStream >> leftOperand >> operation >> rightOperand;
    double answer;
    if (operation == '+') {
        answer = leftOperand + rightOperand;
    } else if (operation == '-') {
        answer = leftOperand - rightOperand;
    } else if (operation == '*') {
        answer = leftOperand * rightOperand;
    } else if (operation == '/') {
        answer = leftOperand / rightOperand;
    } else {
        std::cout << "Wrong input!\n";
        return 0;
    }
    std::cout << leftOperand << " " <<
                 std::string(1, operation) << " " <<
                 rightOperand << " = " << answer;
}
