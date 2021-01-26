#include <iostream>

// checkRealNumber returns true if str is a valid real number
bool checkRealNumber(std::string str) {
    bool firstChar = true, pointMet = false, metDigit = false;
    for (char c : str) {
        // If not number
        if (c < '0' || c > '9') {
            // then isn't it "-" not in the first place?
            if (c == '-' && firstChar) {
                firstChar = false;
                continue;
            }
            // then is it "." that we not met before?
            if (c == '.' && !pointMet) {
                pointMet = true;
                continue;
            }
            // It is neither a number, nor one of the expected symbols.
            return false;
        } else {
            // We met a number, so it is potentially correct.
            metDigit = true;
        }
        firstChar = false;
    }
    return metDigit;
}

// isNegative returns true if str has a negative real number
bool isNegative(std::string str) {
    return str[0] == '-';
}

// removeZeros returns string with leading and trailing zeros removed from str
std::string removeZeros(std::string str) {
    // check if 0
    if (str.find_first_not_of('0') == -1) return "0";

    // removing leading zeros
    str = str.substr(str.find_first_not_of('0'));

    // removing trailing zeros
    str = str.substr(0,str.find_last_not_of('0') + 1);

    // removing decimal point if in the end
    str = str.substr(0, str.find_last_not_of('.') + 1);
    return (str == "" ? "0" : str);
}

// comparePosReal returns "Less", "More", or "Equal" depending on comparison
//  of first and second string that contain non-negative real numbers.
//  The result is inverted if negate is true.
std::string comparePosReal(std::string first, std::string second, bool negate) {

    // cycle will end if one of the strings has dor earlier or if
    //  '\0' is encountered.
    for (int i = 0;; i++) {
        if (first[i] < second[i]) return (negate ? "More" : "Less");
        if (first[i] > second[i]) return (negate ? "Less" : "More");
        if (first[i] == '\0' && second[i] == '\0') return "Equal";
    }
}

// compareReal returns "Less", "More", or "Equal" depending on comparison
// of first and second string that contain non-negative real numbers.
// Returns error if input is incorrect.
std::string compareReal(std::string first, std::string second) {
    if (!checkRealNumber(first) || !checkRealNumber(second))
        return "Incorrect input!\n";

    bool firstNegative = isNegative(first);
    bool secondNegative = isNegative(second);
    if (firstNegative && !secondNegative) return "Less";
    if (!firstNegative && secondNegative) return "More";
    if (firstNegative) { // if both are negative
        // make them positive
        first = first.substr(1, first.length() - 1);
        second = second.substr(1, second.length() - 1);
    }

    first = removeZeros(first);
    second = removeZeros(second);

    return comparePosReal(first, second, firstNegative);
}

int main() {
    std::string first, second;
    std::cout << "Enter two real numbers to compare:" << std::endl;
    std::cin >> first >> second;

    std::cout << compareReal(first, second);
}

