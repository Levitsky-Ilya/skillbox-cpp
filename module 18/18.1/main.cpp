#include <iostream>
#include <vector>

int main() {
    int N;
    std::cout << "How many numbers will be in the array?\n" << std::endl;
    std::cin >> N;
    if (N <= 0) {
        std::cout << "Error! Entered a non-positive number!\n";
        return 0;
    }

    std::vector<int> array(N);
    std::cout << "Input array of numbers:\n" << std::endl;
    for (int i = 0; i < N; i++)
        std::cin >> array[i];

    // Variables for 2)
    int firstIndexTmp = 0, firstIndex = 0, secondIndex = 0, sumCurrent = 0;
    int maxSum = array[0];

    for (int i = 0; i < N; i++) {

        if (sumCurrent == 0)
            firstIndexTmp = i;

        sumCurrent += array[i];

        if (maxSum <= sumCurrent) {
            maxSum = sumCurrent;
            secondIndex = i;
            firstIndex = firstIndexTmp;
        }

        sumCurrent = std::max(sumCurrent, 0);
    }

    std::cout << "Summing the elements between " << firstIndex << " and " << secondIndex << " will produce the greatest sum.\n" << std::endl;
}
