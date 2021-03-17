#include <iostream>
#include <string>

struct Vector {
    double x = 0;
    double y = 0;
};

Vector add(Vector a, Vector b) {
    return {a.x+b.x, a.y+b.y};
}

Vector subtract(Vector a, Vector b) {
    return {a.x-b.x, a.y-b.y};
}

Vector scale(Vector a, double s) {
    return {a.x*s, a.y*s};
}

double length(Vector a) {
    return std::sqrt(a.x*a.x + a.y*a.y);
}

Vector normalize(Vector a) {
    return scale(a, 1/length(a));
}

double inputScalar() {
    std::cout << "Enter a scalar:\n";
    double s;
    std::cin >> s;
    return s;
}

Vector inputVector() {
    std::cout << "Enter two vector coordinates, separated by space (x y):\n";
    Vector a;
    std::cin >> a.x >> a.y;
    return a;
}

std::string printVector(Vector a) {
    return "(" + std::to_string(a.x) + ";" + std::to_string(a.y) + ")";
}

int main() {
    std::cout << "Enter operation (add/subtract/scale/length/normalize):\n" << std::endl;
    std::string operation;
    std::cin >> operation;
    if (operation == "add") {
        Vector a = inputVector(), b = inputVector();
        std::cout << printVector(add(a,b)) << std::endl;
    } else if (operation == "subtract") {
        Vector a = inputVector(), b = inputVector();
        std::cout << printVector(subtract(a,b)) << std::endl;
    } else if (operation == "scale") {
        Vector a = inputVector();
        double s = inputScalar();
        std::cout << printVector(scale(a, s)) << std::endl;
    } else if (operation == "length") {
        Vector a = inputVector();
        std::cout << length(a) << std::endl;
    } else if (operation == "normalize") {
        Vector a = inputVector();
        std::cout << printVector(normalize(a)) << std::endl;
    } else {
        std::cout << "Undefined operation!\n";
    }
    return 0;
}
