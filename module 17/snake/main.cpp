#include <iostream>

int main() {
    int table[5][5];
    for (int i = 0; i < 25; i++) {
        table[i / 5][(9 - std::abs((2 * i) % 20 - 9)) / 2 ] = i;
    }

    for (auto & i : table) {
        for (int j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}
