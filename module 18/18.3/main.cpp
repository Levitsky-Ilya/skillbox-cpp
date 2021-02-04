#include <iostream>
#include <vector>

int main() {
    int input;
    std::cout << "Input array of numbers:\n" << std::endl;
    std::cin >> input;

    while (input == -1) {
        std::cout << "Not enough elements!\n";
        std::cin >> input;
    }

    // The vector never has to store more than 5 elements.
    std::vector<int> array(5, input);
    int arraySizeVirtual = 0;
    while (input != -2) {

        // Output 5th lowest number
        if (input == -1) {
            if (arraySizeVirtual < 5) {
                std::cout << "Not enough elements!\n";
            } else {
                std::cout << "5th smallest number is " << array[4] << "\n";
            }
        } else {
            // Insert number
            for (int i = 0; i < arraySizeVirtual; i++) {
                if (input < array[i]) {
                    int tmp = array[i];
                    array[i] = input;
                    input = tmp;
                }
            }
        }
        std::cin >> input;
        if (arraySizeVirtual < 5)
            arraySizeVirtual++;
    }
}
