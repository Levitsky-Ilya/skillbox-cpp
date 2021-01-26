#include <iostream>

// Обязательны ли буквы в какой-либо части? Например, {}3!#@- является корректным адресом

// checkIfFromAlphabet returns TRUE if str contains only
// symbols from the alphabet
bool checkIfFromAlphabet(std::string str, std::string alphabet) {
    for (char c : str) {
        if (alphabet.find(c) == -1)
            return false;
    }
    return true;
}

// checkDots returns true if str does not have dots at the start,
// end, or two consecutive dots.
bool checkDots(std::string str) {
    bool prevIsDot = true;
    for (char c : str) {
        if (c == '.') {
            if (prevIsDot) return false;
            prevIsDot = true;
        } else
            prevIsDot = false;
    }
    return !prevIsDot;
}

//
bool checkAddress(std::string address) {
    int addressLength = address.length();
    if (!addressLength)
        return false;

    int dividerPos = address.find("@");
    if (dividerPos < 1 || dividerPos > 64)
        return false;

    std::string firstPart = address.substr(0,dividerPos);
    std::string secondPart = address.substr(dividerPos + 1, addressLength - dividerPos - 1);
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz0123456789-.";
    std::string specialSymbols = "!#$%&'*+-/=?^_`{|}~";

    return (checkIfFromAlphabet(firstPart, alphabet+specialSymbols) &&
            checkDots(firstPart) &&
            (secondPart.length() > 0 && secondPart.length() < 64) &&
            checkIfFromAlphabet(secondPart, alphabet) &&
            checkDots(secondPart));
}

int main() {

    std::string address;
    std::cout << "Input e-mail address:\n" << std::endl;
    std::cin >> address;

    std::cout << (checkAddress(address) ? "Yes\n" : "No\n");
}
