#include <iostream>
#include <vector>

// removeElement returns a vec but without elements equal to "element"
std::vector<int> removeElement(std::vector<int> vec, int element) {
    // This option was inspired by online recommendations;
    //vec.erase(std::remove(vec.begin(), vec.end(), element), vec.end());

    // This option is based on Skillbox courses, part 16
    int elementsRemoved = 0;

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == element)
            elementsRemoved++;
        else
            vec[i-elementsRemoved] = vec[i];
    }
    vec.resize(vec.size()-elementsRemoved);
    return vec;
}

int main() {
    int N;
    std::cout << "Enter the number of elements to be added: " << std::endl;
    std::cin >> N;
    while (N <= 0) {
        std::cout << "The number of elements must be non-negative: " << std::endl;
        std::cin >> N;
    }

    std::vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        std::cout << ">";
        std::cin >> vec[i];
    }

    int elementToRemove;
    std::cout << "Enter a number to be deleted: ";
    std::cin >> elementToRemove;

    vec = removeElement(vec, elementToRemove);

    std::cout << "Your vector is\n";
    for (int i : vec)
        std::cout << i << " ";

}
