#include <iostream>
#include <string>
#include <map>

int main() {
    std::map<std::string, int> registrationQueue;
    while (true) {
        std::cout << "Enter name or \"Next\":" << std::endl;
        std::string input;
        std::cin >> input;
        if (input == "Next") {
            auto queueHead = registrationQueue.begin();
            if (queueHead != registrationQueue.end()) {
                std::cout << queueHead->first << "\n";
                if (--(queueHead->second) == 0) {
                    registrationQueue.erase(queueHead);
                }
            }
        } else {
            registrationQueue[input]++;
        }
    }
}
