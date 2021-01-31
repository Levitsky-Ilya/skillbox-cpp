#include <iostream>

// clearField sets all boolean matrix elements to false.
void clearField(bool field[][10][10]) {
    for (int player = 0; player < 2; player++)
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                field[player][i][j] = false;
}

// checkShipPlacing returns true if x and y are correct, false otherwise.
// Prints an error message in case of incorrect coords.
bool checkShipPlacing(bool field[][10], int x1, int y1, int x2, int y2, int shipLength) {

    // Check if coordinates are in range
    if (x1 < 0 || x1 > 9 ||
        y1 < 0 || y1 > 9 ||
        x2 < 0 || x2 > 9 ||
        y2 < 0 || y2 > 9) {
        std::cout << "Coordinates are out of range. Enter numbers in range 0 - 9: ";
        return false;
    }

    // If coordinates correspond to ship length
    if (!((x1 == x2 && std::abs(y1 - y2) == shipLength - 1) ||
          (y1 == y2 && std::abs(x1 - x2) == shipLength - 1))) {
        std::cout << "Coordinates do no match the length of the ship (" << shipLength << "):";
        return false;
    }

    // Check if new ship overlaps with previous ones
    int x = std::min(x1, x2);
    int y = std::min(y1, y2);
    bool shipHorizontal = (y1 == y2);
    for (int i = 0; i < shipLength; i++) {
        if (field[x][y]) {
            std::cout << "New ship overlaps with a previous one. Enter another coordinates: ";
            return false;
        }
        x += shipHorizontal;
        y += !shipHorizontal;
    }
    return true;
}

// placeShip returns same as checkShipPlacing function. If returns true, the ship
// is placed successfully.
bool placeShip(bool field[][10], int x1, int y1, int x2, int y2, int shipLength) {
    if (!checkShipPlacing(field, x1, y1, x2, y2, shipLength)) return false;

    // Place ship
    int x = std::min(x1, x2);
    int y = std::min(y1, y2);
    bool shipHorizontal = (y1 == y2);
    for (int i = 0; i < shipLength; i++) {
        field[x][y] = true;
        x += shipHorizontal;
        y += !shipHorizontal;
    }
    return true;
}

// checkAttackCoords returns true if x and y are i range, false otherwise.
// Prints an error message in case of incorrect coords.
bool checkAttackCoords(int x, int y) {
    if (x < 0 || x > 9 ||
        y < 0 || y > 9) {
        std::cout << "Coordinates are out of range. Enter two numbers in range 0 - 9:";
        return false;
    }
    return true;
}

// displayField prints field.
void displayField(bool field[][10]){
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            std::cout << (field[i][j] ? "X " : "~ ");
        std::cout << std::endl;
    }
}

int main() {
    // Matrix fields contains two player fields;
    bool playerFields[2][10][10];
    bool attackFields[2][10][10];
    clearField(playerFields);
    clearField(attackFields);

    // 4 boats, 3 small and 2 medium ships, 1 big ship
    int shipsNumber[] = {4, 3, 2, 1};
    int shipLength[] = {1, 2, 3, 4};
    int shipPointsLeft[2] = {20, 20};

    std::cout << "Welcome to Battleship 3.0!\n\n";

    // Placing ships
    for (int playerIndex = 0; playerIndex < 2; playerIndex++) {
        int playerDisplayIndex = playerIndex + 1;
        std::cout << "PLAYER " << playerIndex + 1 << "!!!\n";

        for (int shipType = 0; shipType < 4; shipType++) {
            bool IsLengthOne = (shipLength[shipType] == 1);
            std::cout << "Place your ships of size " << shipLength[shipType] <<
            ". Enter coordinates " << (IsLengthOne ? "x y" : "x1 y1 x2 y2") << " .\n";
            for (int shipNumber = 0; shipNumber < shipsNumber[shipType]; shipNumber++) {
                displayField(playerFields[playerIndex]);
                std::cout << "Ship # " << shipNumber + 1 << ":";
                if (IsLengthOne) {
                    int x, y;
                    std::cin >> x >> y;
                    while (!placeShip(playerFields[playerIndex], x, y, x, y, 1))
                        std::cin >> x >> y;
                } else {
                    int x1, y1, x2, y2;
                    std::cin >> x1 >> y1 >> x2 >> y2;
                    while (!placeShip(playerFields[playerIndex], x1, y1, x2, y2, shipLength[shipType]))
                        std::cin >> x1 >> y1 >> x2 >> y2;
                }
            }
        }
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    }

    bool victory = false;
    while (true) {
        for (int playerIndex = 0; playerIndex < 2; playerIndex++) {
            int playerDisplayIndex = playerIndex + 1;
            int opponentIndex = 1 - playerIndex;
            std::cout << "PLAYER " << playerDisplayIndex << "!!! Your turn! Attack!\n";

            // Added ability to shoot multiple times if shot is successful.
            bool missed = false;
            while (!missed) {
                displayField(attackFields[playerIndex]);

                int x, y;
                std::cin >> x >> y;
                while(!checkAttackCoords(x, y))
                    std::cin >> x >> y;

                attackFields[playerIndex][x][y] = true;

                if (playerFields[opponentIndex][x][y]) {
                    std::cout << "HIT!! Nice shot! ";
                    playerFields[opponentIndex][x][y] = false;
                    shipPointsLeft[opponentIndex]--;
                    victory = (shipPointsLeft[opponentIndex] == 0);
                } else {
                    std::cout << "Miss.";
                    missed = true;
                }
                if (!missed) {
                    if (victory) {
                        std::cout << "\n\n PLAYER " << playerDisplayIndex << " WON!!! Congratulations!";
                        break;
                    } else
                        std::cout << "Shoot again!\n";
                } else
                    std::cout << std::endl;
            }
        }
        if (victory)
            break;
    }

}
