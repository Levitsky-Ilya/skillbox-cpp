#include <iostream>

void initializeMatrix(bool matrix[][12]) {
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            matrix[i][j] = true;
}

// displayMatrix returns false if neither of the matrix elements is true;
bool displayMatrix(bool matrix[][12]){
    bool result = false;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            std::cout << (matrix[i][j] ? "o" : "x");
            result |= matrix[i][j];
        }
        std::cout << std::endl;
    }
    return result;
}

bool checkInput(int x, int y){
    return (x >= 0 && x <= 11 &&
            y >= 0 && y <= 11);
}

void doPopping(bool matrix[][12]){
    int x1, x2, y1, y2;

    std::cout << "Input first coordinates of rectangle (two whole numbers): ";
    std::cin >> x1 >> y1;
    while (!checkInput(x1, y1)) {
        std::cout << "Coordinates must be between 0 and 11: ";
        std::cin >> x1 >> y1;
    }
    std::cout << "Input second coordinates of rectangle (two whole numbers): ";
    std::cin >> x2 >> y2;
    while (!checkInput(x2, y2)) {
        std::cout << "Coordinates must be between 0 and 11: ";
        std::cin >> x2 >> y2;
    }

    for(int x = x1; x <= x2; x++)
        for(int y = y1; y <= y2; y++)
            if (matrix[x][y]) {
                matrix[x][y] = false;
                std::cout << "Pop! ";
            }
    std::cout << std::endl;
}

int main() {
    bool bubbleWrap[12][12];
    initializeMatrix(bubbleWrap);

    while(displayMatrix(bubbleWrap)) {
        doPopping(bubbleWrap);
    }
}
