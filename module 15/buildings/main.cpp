#include <iostream>

int main() {
    int buildingsHeight[] = {2, 1, 4, 6, 9};
    int totalStages = 0;
    for (int stages : buildingsHeight)
        totalStages += stages;
    std::cout << "Approximate average height in the city is " <<
        (float) totalStages / (sizeof(buildingsHeight) / sizeof(buildingsHeight[0])) << std::endl;
    return 0;
}
