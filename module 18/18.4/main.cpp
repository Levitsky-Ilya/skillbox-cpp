#include <iostream>
#include <vector>

int main() {
    int N;
    std::cout << "Input array size: " << std::endl;
    std::cin >> N;

    std::vector<int> arrayInput(N), arrayOutput(N);
    std::cout << "Input sorted array of numbers:\n" << std::endl;
    for (int i = 0; i < N; i++)
        std::cin >> arrayInput[i];

    int first = 0, last = N - 1;
    for(int i = 0; i < N; i++) {
        if (-arrayInput[first] > arrayInput[last]) {
            arrayOutput[i] = arrayInput[first];
            first++;
        } else {
            arrayOutput[i] = arrayInput[last];
            last--;
        }
    }

    for(int i = N - 1; i >= 0; i--)
        std::cout << arrayOutput[i] << " ";
}
