#include <iostream>

int main() {
    bool terrain[5][5][10];
    std::cout << "Welcome to Minecraft 2.0!\n\n";
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            int height;
            std::cout << "Input height for column x = " << i << ", z = " << j << ": ";
            std::cin >> height;
            while (height < 0 || height > 10) {
                std::cout << "Height should be between 0 and 10: ";
                std::cin >> height;
            }
            int k = 0;
            for (; k < height; k++)
                terrain[i][j][k] = true;
            for(; k < 10; k++)
                terrain[i][j][k] = false;
        }

    int sliceLevel;
    std::cout << "Input the level of horizontal slice: ";
    std::cin >> sliceLevel;
    while (sliceLevel < 0 || sliceLevel > 10) {
        std::cout << "Slice level should be between 0 and 10: ";
        std::cin >> sliceLevel;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << (terrain[i][j][sliceLevel] ? "1" : "0");
        }
        std::cout << std::endl;
    }
}
