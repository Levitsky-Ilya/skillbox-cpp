#include <iostream>
#include <fstream>
#include <sstream>
#include "nlohmann/json.hpp"

#define PTR(x) std::shared_ptr<x>

using std::string;

struct DictionaryEntry {
    PTR(string) fullName;
    PTR(string) role;
    PTR(string) film;
};

using Dictionary = std::multimap<string, DictionaryEntry>;

int main() {
    std::ifstream inFile("../scratch.json");
    if (!inFile.is_open()) {
        std::cout << "The file is not found";
        return 0;
    }
    nlohmann::json j;
    Dictionary dict;
    inFile >> j;

    // Parsing JSON into a dictionary
    for (const auto& film : j.items()) {
        PTR(string) filmPtr = std::make_shared<string>(film.key());
        for (const auto& actorRolePair : film.value()["actors"].items()) {
            std::stringstream ss;
            ss << actorRolePair.key();
            PTR(string) fullName = std::make_shared<string>(actorRolePair.key());
            PTR(string) role = std::make_shared<string>(actorRolePair.value());
            while (!ss.eof()) {
                string namePart;
                ss >> namePart;
                dict.emplace(namePart, DictionaryEntry{fullName, role, filmPtr});
            }
        }
    }

    // Finding the fullName, the role, and film by a name or surname
    std::cout << "Welcome to actor search!\n";
    std::cout << "Enter \"exit\" to stop the program.\n";
    string actorName;
    while (actorName != "exit") {
        std::cout << "Enter actor's first or second name: ";
        std::cin >> actorName;

        if (actorName == "exit") {
            std::cout << "Exiting.\n";
            return 0;
        }

        auto range = dict.equal_range(actorName);
        if (range.first != dict.end()) {
            for (auto it = range.first; it != range.second; it++) {
                auto [fullName, role, film] = it->second;
                std::cout << "Actor " << *fullName << " has starred in \"" << *film << "\" as " << *role << ".\n";
            }
        } else {
            std::cout << "Actor with the name " << actorName << " was not found in the database.\n";
        }
    }


    return 0;
}
