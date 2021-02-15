#include <iostream>

int findRoutesForStairs(int steps, int jumpMax = 3) {
    if (steps < 0) return 0;
    if (steps <= 1) return 1;

    int result = 0;
    int stepsLeft = steps - 1;
    for (int jump = 1; jump <= jumpMax && stepsLeft >= 0; jump++) {
        result += findRoutesForStairs(stepsLeft--, jumpMax);
    }
    return result;
}

int main() {
    int steps;
    std::cout << "Enter the length of stairs: ";
    std::cin >> steps;

    int jumpMax;
    std::cout << "Enter the maximum jump length: ";
    std::cin >> jumpMax;
    if (jumpMax < 1) {
        std::cout << "Error! Maximum jump length must be greater than 0.\n";
    }

    int routes = findRoutesForStairs(steps, jumpMax);
    std::cout << "There are " << routes << " ways to reach the #" << steps << " step.\n" << std::endl;
    return 0;
}
