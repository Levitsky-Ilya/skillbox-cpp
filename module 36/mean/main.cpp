#include <iostream>
#include <vector>

template <typename T>
T mean(std::vector<T> numbers) {
    T sum = 0;
    for (auto number : numbers) {
        sum += number;
    }

    return sum / numbers.size();
}

int main() {
    std::cout << "*** Automatic test of function  mean  ***\n" << std::endl;

    std::cout << "mean(3,8,1,-6,95) = "
              << mean(std::vector<int> {3,8,1,-6,95}) << std::endl;
    std::cout << "Comment: mean of integers is also rounded to an integer." << std::endl;

    std::cout << "mean(3.0f,8.0f,1.0f,-6.0f,95.0f) = "
              << mean(std::vector<float> {3.0f,8.0f,1.0f,-6.0f,95.0f}) << std::endl;

    std::cout << "mean(3.0,8.0,1.0,-6.0,95.0) = "
              << mean(std::vector<double> {3.0,8.0,1.0,-6.0,95.0}) << std::endl;

    return 0;
}
