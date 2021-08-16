#include <cassert>
#include "Swimmer.h"

int main() {
    std::cout << "***** Welcome to Olympiad in Tokyo 2020! *****\n\n";

    int swimmersCount = 6;
    std::vector<Swimmer*> swimmers;

    for (int i = 1; i <= swimmersCount; i++) {
        std::cout << "Enter name of swimmer #" << i << ": \n";
        std::string swimmerName;
        std::cin >> swimmerName;

        std::cout << "Enter his speed:" << "\n";
        double swimmerSpeed;
        std::cin >> swimmerSpeed;
        assert(swimmerSpeed >= 1.0);

        swimmers.push_back(new Swimmer(swimmerName, swimmerSpeed));
    }
    std::cout << "3, 2, 1, GO!\n\n";
    for (int i = 0; i < swimmersCount; i++) {
        swimmers[i]->start();
    }

    for (int i = 0; i < swimmersCount; i++) {
        swimmers[i]->finish();
    }

    std::cout << "Race is finished!\n";
    int i = 0;
    for (const auto& finishRecord : g_finishRecords) {
        i++;
        std::cout << "No" << i << " is " << finishRecord.second << "! Time is " << finishRecord.first << "s.\n";
    }


}
