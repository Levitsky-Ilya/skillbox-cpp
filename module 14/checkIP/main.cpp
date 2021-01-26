#include <iostream>
#include <string>

// checkIfDigits returns TRUE if str contains only digits
bool checkIfDigits(std::string str) {
    // IDE recommends to replace for with std::all_of()
    for (char c : str) {
        if (c < '0' || c > '9') return false;
    }
    return true;
}

// checkNumber returns TRUE if str is a non-negative number less than 256 without leading zeros
bool checkNumber(std::string str) {
    if (str.length() == 0 || !checkIfDigits(str)) return false;

    int number = std::stoi(str);
    if (number == 0) {
        return str.length() == 1;
    } else {
        return (str[0] != '0' && number < 256);
    }
}

// checkIP returns TRUE if "address" is a valid IP address
bool checkIP(std::string address) {
    for (int i = 0; i < 3; i++) {
        int dotPos = address.find('.');
        if (dotPos == -1 ||
            !checkNumber(address.substr(0, dotPos)))
            return false;
        address = address.substr(dotPos + 1, address.length() - dotPos - 1);
    }
    return checkNumber(address);
}

int main() {
    std::string ipAddress;
    std::cout << "Enter IP address:" << std::endl;
    std::cin >> ipAddress;

    std::cout << "Checking IP address...\n" << std::endl;
    std::cout << (checkIP(ipAddress) ? "Yes\n" : "No\n");
    return 0;
}
