#include <iostream>

// Comment: keys A - G are never used in code.
enum keys {
    A = 1,
    B = 2,
    C = 4,
    D = 8,
    E = 16,
    F = 32,
    G = 64,
    INVALID = 128
};

// parseCombination converts a combNumbers string into a bitmask of keys.
// If conversion is unsuccessful - returns INVALID and prints error message in cout.
int parseCombination(std::string combNumbers) {
    if (combNumbers.length() > 7) {
        std::cout << "To long combination! Try again.\n";
        return INVALID;
    }
    int result = 0;
    for (char key : combNumbers) {
        if (key < '1' || key > '7') {
            std::cout << "Invalid keys. Try again.\n";
            return INVALID;
        }
        // Make use of left shift to get the key bit mask
        int keyCode = 1 << (key - '1');
        if (result & keyCode) {
            std::cout << "Repeating keys. Try again.\n";
            return INVALID;
        } else {
            result |= keyCode;
        }

    }
    return result;
}

// keysBitmaskToString converts bitmask into a string of space-separated keys "A - G".
// Input is assumed to be correct.
std::string keysBitmaskToString(int keysBitmask) {
    char keyLetters[] = "ABCDEFG";
    std::string result;
    for (int i = 0; i < 7; i++) {
        if (keysBitmask & 1 << i)
            result += (std::string(1, keyLetters[i]) + " ");
    }
    return result;
}

int main() {
    std::string notesStream;

    for (int i = 0; i < 12; i++) {
        // combNumbers shall store a number XXXXXXX with unique digits,
        // which is at most 7 digits long, each X is a number from 1 to 7.
        std::string combNumbers;
        std::cout << "Play combination #" << i+1 << ":" << std::endl;

        int keysBitmask;
        do {
            std::cin >> combNumbers;
            keysBitmask = parseCombination(combNumbers);
        } while (keysBitmask == INVALID);

        notesStream += keysBitmaskToString(keysBitmask) + "\n";
    }

    std::cout << notesStream;
}
