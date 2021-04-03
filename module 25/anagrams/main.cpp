#include <iostream>
#include <string>
#include <map>

bool isAnagram(std::string a, std::string b) {
    std::map<char,int> charsCnt;
    for (char ch : a)
        charsCnt[ch]++;
    for (char ch : b) {
        int & chCnt = --charsCnt[ch];
        if (chCnt == 0)
            charsCnt.erase(ch);
        else if (chCnt < 0)
            return false;
    }
    return (charsCnt.empty());
}

int main() {
    std::string a, b;
    std::cout << "Input first word: \n";
    std::cin >> a;
    std::cout << "Input second word: \n";
    std::cin >> b;
    std::cout << (isAnagram(a, b) ? "true\n" : "false\n");
    return 0;
}
