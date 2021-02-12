#include <iostream>

bool substr(char* a, char* b) {
    int len_a = strlen(a), len_b = strlen(b);
    for (int i = 0; i <= len_a - len_b; i++)
        if(strncmp(a + i, b, len_b) == 0) return true;
    return false;
}

int main() {
    //ISO C++11 does nor allow conversion from string literal to char *
    char* a = "Hello world";
    char* b = "wor";
    char* c = "banana";
    std::cout << substr(a,b) << " " << substr(a,c);
}
