#include <iostream>

int main() {
    float M[4][4];

    std::cout << "Input matrix M:\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin >> M[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            M[i][j] = M[j][i] = 0;
        }
    }

    std::cout << "Matrix M with elements nulled except the diagonal:\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << M[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
