#include <iostream>
#include <string>

// checkRow returns TRUE only if row has length 3 and
//  contains only symbols 'X', 'O', '.'
bool checkRow(std::string row) {
    if (row.length() != 3)
        return false;
    // for (char c : row) <- suggestion given by IDE
    // IDE recommends to replace for with std:::all_of
    for (char c : row)
        if (c != 'X' && c != 'O' && c != '.')
            return false;
    return true;
}

// countSymbols counts number of times "c" is found in str
int countSymbols(std::string str, char symbol) {
    int count = 0;
    // (char i : str) <- suggestion given by IDE
    for (char c : str)
        count += (c == symbol);
    return count;
}

// checkTable returns
//  0 if Xs == Os
//  1 if Xs == Os + 1
//  -1 otherwise (incorrect number of Xs and Os)
int checkTable(std::string table) {

    int numX = countSymbols(table, 'X');
    int numO = countSymbols(table, 'O');
    return numX == numO ? 0 : numX == (numO + 1) ? 1 : -1;
}

// checkIfWon returns TRUE if nots-and-crosses table
//  has a winner, indicated by the symbol
bool checkIfWon(std::string table, char symbol) {
    return
            (table[0] == symbol && table[1] == symbol && table[2] == symbol) ||
            (table[3] == symbol && table[4] == symbol && table[5] == symbol) ||
            (table[6] == symbol && table[7] == symbol && table[8] == symbol) ||
            (table[0] == symbol && table[3] == symbol && table[6] == symbol) ||
            (table[1] == symbol && table[4] == symbol && table[7] == symbol) ||
            (table[2] == symbol && table[5] == symbol && table[8] == symbol) ||
            (table[0] == symbol && table[4] == symbol && table[8] == symbol) ||
            (table[2] == symbol && table[4] == symbol && table[6] == symbol);
}

int main() {
    std::cout << "Nots and Crosses\n\n";

    std::string row1, row2, row3, table;
    std::cout << "Input table state:\n";
    std::getline(std::cin, row1);
    std::getline(std::cin, row2);
    std::getline(std::cin, row3);

    table = row1 + row2 + row3;
    int checkTableResult = checkTable(table);
    if (!checkRow(row1) ||
        !checkRow(row2) ||
        !checkRow(row3) ||
        checkTableResult == -1) {

        std::cout << "Incorrect\n";
        return 0;
    }

    bool PetyaWins = checkIfWon(table, 'X');
    bool VanyaWins = checkIfWon(table, 'O');
    if ((PetyaWins && VanyaWins) ||
        (PetyaWins && checkTableResult != 1) ||
        (VanyaWins && checkTableResult != 0)) {

        std::cout << "Incorrect\n";
        return 0;
    }

    std::cout <<
        (PetyaWins ? "Petya won\n" : VanyaWins ? "Vanya won\n" : "Nobody won\n");

}