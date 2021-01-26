#include <iostream>

int main() {
    int totalRegistered;
    std::cout << "How many people are registered in the house?" << std::endl;
    std::cin >> totalRegistered;
    int houseHeight = 5;
    int peopleOnStage[5];

    for (int i = 0; i < houseHeight; i++) {
        std::cout << "How many people are currently on stage " << i + 1 << "?" << std::endl;
        std::cin >> peopleOnStage[i];
    }

    int totalInHouse = 0;
    for(int people : peopleOnStage)
        totalInHouse += people;

    float selfIsolationLevel = (float) totalInHouse * 100 / totalRegistered;
    std::cout << "The self-isolation level is " << selfIsolationLevel << "%\n";
    if (selfIsolationLevel > 100.f)
        std::cout << "Hmm, the level above 100% is a bit unexpected...\n";

    return 0;
}
