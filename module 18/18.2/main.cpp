#include <iostream>
#include <vector>

int main() {
    int N;
    std::cout << "Enter the number of elements in the array: " << std::endl;
    std::cin >> N;
    if (N <= 0) {
        std::cout << "Error! Entered a non-positive number!\n";
        return 0;
    }

    std::vector<int> array(N);
    std::cout << "Input array of numbers:\n" << std::endl;
    for (int i = 0; i < N; i++)
        std::cin >> array[i];

    int sum;
    std::cout << "Enter the sum of the two elements: " << std::endl;
    std::cin >> sum;

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (array[i] + array[j] == sum) {
                std::cout << "The sum is produced by " << array[i] << " and " << array[j] << "\n" << std::endl;
                return 0;
            }
        }
    }
}
