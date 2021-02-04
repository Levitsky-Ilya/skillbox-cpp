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

    // The algorithm is split in two cases: 1) only negative numbers; 2) not only negative numbers
    // 1) Choose a single maximal element as a range that produces maximal sum
    // 2) Find the lowest cumulative sum.
    // The maximal sum is the difference between the maximal and minimal cumulative sum and
    // The maximal cumulative sum follows (has no smaller index than) the minimal one.

    // Variables for 2)
    int firstIndexTmp = 0, firstIndex = 0, secondIndex = 0, sumCumul = 0;
    int maxSum = array[0], minSumCumul = 0;

    // Variables for 1)
    bool onlyNegative = true;
    int maxElement = array[0], maxElementIndex = 0;

    for (int i = 0; i < N; i++) {
        // Algorithm 1)
        onlyNegative &= (array[i] < 0);
        if (onlyNegative && maxElement < array[i]) {
            maxElement = array[i];
            maxElementIndex = i;
        }

        // Algorithm 2)
        sumCumul += array[i];

        if (sumCumul <= minSumCumul) {
            minSumCumul = sumCumul;
            firstIndexTmp = i + 1;
        }

        if (maxSum < sumCumul - minSumCumul) {
            maxSum = sumCumul - minSumCumul;
            secondIndex = i;
            firstIndex = firstIndexTmp;
        }
    }

    if (onlyNegative)
        firstIndex = secondIndex = maxElementIndex;

    std::cout << "Summing the elements between " << firstIndex << " and " << secondIndex << " will produce the greatest sum.\n" << std::endl;
}
