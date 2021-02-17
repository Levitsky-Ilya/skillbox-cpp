#include <iostream>

void evenDigits(long long num, int &ans) {
    if (num < 10) {
        ans = !(num % 2);
    } else {
        evenDigits(num / 10, ans);
        ans += !((num % 10) % 2);
    }
}

int main() {
    int ans;
    long long input;
    std::cout << "Enter number: ";
    std::cin >> input;
    evenDigits(input, ans);
    std::cout << ans << std::endl;
}
