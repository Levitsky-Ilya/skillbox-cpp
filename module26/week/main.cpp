#include <iostream>

#define PRINT(x) std::cout << (x) << std::endl
#define WELCOME "Input a number of a day in a week: "
#define FAIL "No such day found."

#define MONDAY_NAME "monday"
#define TUESDAY_NAME "tuesday"
#define WEDNESDAY_NAME "wednesday"
#define THURSDAY_NAME "thursday"
#define FRIDAY_NAME "friday"
#define SATURDAY_NAME "saturday"
#define SUNDAY_NAME "sunday"

#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6
#define SUNDAY 7

#define NAME(x) x ## _ ## NAME
int main() {
    PRINT(WELCOME);
    int input;
    std::cin >> input;
    if (input == MONDAY) {
        PRINT(NAME(MONDAY));
    } else if (input == TUESDAY) {
        PRINT(NAME(TUESDAY));
    } else if (input == WEDNESDAY) {
        PRINT(NAME(WEDNESDAY));
    } else if (input == THURSDAY) {
        PRINT(NAME(THURSDAY));
    } else if(input == FRIDAY) {
        PRINT(NAME(FRIDAY));
    } else if(input == SATURDAY) {
        PRINT(NAME(SATURDAY));
    } else if(input == SUNDAY) {
        PRINT(NAME(SUNDAY));
    } else {
        PRINT(FAIL);
    }
}
