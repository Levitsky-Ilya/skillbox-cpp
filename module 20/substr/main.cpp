#include <iostream>

bool substr(char* a, char* b) {
    int len_a = strlen(a), len_b = strlen(b);
    for (int i = 0; i <= len_a - len_b; i++)
        if(strncmp(a + i, b, len_b) == 0) return true;
    return false;
}

int main() {
    const char* a = "Hello world";
    const char* b = "wor";
    const char* c = "banana";
    std::cout << substr((char*) a, (char*)b) << " " << substr((char*) a,(char*) c);
}
