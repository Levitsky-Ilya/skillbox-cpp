#include <iostream>

int main() {
    float M[4][4];
    float V[4];
    float R[4] = {0, 0, 0, 0};

    std::cout << "Input matrix M 4x4:\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin >> M[i][j];
        }
    }

    std::cout << "Input vector V:\n";
    for (int i = 0; i < 4; i++) {
        std::cin >> V[i];
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            R[i] += M[i][j] * V[j];
        }
    }

    std::cout << "Vector R = M * V:\n";
    for (int i = 0; i < 4; i++) {
        std::cout << R[i] << std::endl;
    }
}
