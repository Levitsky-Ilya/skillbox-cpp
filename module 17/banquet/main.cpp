#include <iostream>

int main() {
    int chairs[2][6] = {{1, 1, 1, 1, 1, 1},
                         {1, 1, 1, 1, 1, 1}};
    int cultery[2][6] = {{4, 3, 3, 3, 3, 3},
                         {4, 3, 3, 3, 3, 3}};
    int dishes[2][6] = {{3, 2, 2, 2, 2, 2},
                        {3, 2, 2, 2, 2, 2}};

    // Additional chair for a baby
    chairs[0][4]++;

    // A spoon is stolen
    cultery[1][2]--;

    // A spoon was returned...
    cultery[1][2]++;
    // by a VIP person.
    cultery[1][0]--;
    // So, the waiter removed one dish from them.
    dishes[1][0]--;

}
