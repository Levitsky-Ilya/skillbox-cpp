#include <iostream>

int main() {
    int A[4][4], B[4][4];
    std::cout << "Input matrix A 4x4: " << std::endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin >> A[i][j];
        }
    }
    std::cout << "Input matrix B 4x4: " << std::endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin >> B[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (A[i][j] != B[i][j]) {
                std::cout << "Not equal!\n";
                return 0;
            }
        }
    }

    std::cout << "Equal!\n";
}
