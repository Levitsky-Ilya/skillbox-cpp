#include <iostream>

// printTable prints 3x3 square with the characters from table
void printTable(char table[][3]) {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++)
            std::cout << table[r][c];
        std::cout << std::endl;
    }
}

// returns true if row and col are in range and they do not point to an
// already occupied space.
bool checkInput(char table[][3], int row, int col) {
    return row >= 0 && row <= 3 &&
           col >= 0 && col <= 3 &&
           table[row - 1][col - 1] == '_';
}

// updateGameState changes table by changing the character to ch on the
// given row and col position. Returns 1 if player 1 won, -1 if player 2
// won, 0 if neither.
int updateGameState(char table[][3], int row, int col, char ch) {
    table[row-1][col-1] = ch;

    // these variables store sum of + Xs - Os
    int sumRowSymbols;
    int sumColSymbols;

    for (int r = 0; r < 3; r++) {
        sumRowSymbols = 0;
        sumColSymbols = 0;
        for (int c = 0; c < 3; c++) {
            sumRowSymbols += (table[r][c] == 'X' ? 1 : table[r][c] == 'O' ? -1 : 0);
            sumColSymbols += (table[c][r] == 'X' ? 1 : table[c][r] == 'O' ? -1 : 0);
        }
        if (sumRowSymbols == 3 || sumColSymbols == 3) return 1;
        if (sumRowSymbols == -3 || sumColSymbols == -3) return -1;
    }
    return 0;
}

int main() {
    std::cout << "Let us start the Nots & Crosses Game!\n\n";

    bool playerOneTurn = false;
    int gameState = 0;
    // Space symbol in the task are replaced with underscores for better visibility
    char table[3][3] = {{'_', '_', '_',},
                        {'_', '_', '_',},
                        {'_', '_', '_',}};
    int row_input, col_input;
    while (gameState == 0) {
        playerOneTurn = !playerOneTurn;
        printTable(table);

        std::cout << "Player " << (playerOneTurn ? "1" : "2") << ", your turn!\n" <<
        "Type two numbers between 1 and 3, indicating row and column:\n";

        std::cin >> row_input >> col_input;

        while (!checkInput(table, row_input, col_input)) {
            std::cout << "Incorrect input or occupied place! Enter two different numbers:\n";
            std::cin >> row_input >> col_input;
        }

        gameState = updateGameState(table, row_input, col_input, (playerOneTurn ? 'X' : 'O'));
    }

    printTable(table);
    std::cout << "Player " << (playerOneTurn ? "1" : "2") << " WON!\n";
}
