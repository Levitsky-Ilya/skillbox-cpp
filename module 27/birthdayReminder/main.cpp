#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>

struct Friend {
    std::string name;
    std::tm birthday;
};

void printSoonestBirthday(const std::vector<Friend> &friends) {
    std::time_t t = std::time(nullptr);
    std::tm localTime = *std::localtime(&t);
    double diffTimeMin = std::numeric_limits<double>::max();
    std::tm soonestBirthday;
    bool isBirthdayToday = false;
    std::vector<std::string> friendNames;

    for (auto friend_1 : friends) {
        // Set the soonest birthday fro the friend.
        // Depends on whether a birthday was this year.
        if (friend_1.birthday.tm_mon < localTime.tm_mon ||
            (friend_1.birthday.tm_mon == localTime.tm_mon &&
                    friend_1.birthday.tm_mday < localTime.tm_mday)) {
            friend_1.birthday.tm_year = localTime.tm_year + 1;
        } else {
            friend_1.birthday.tm_year = localTime.tm_year;
        }

        // Find the soonest birthday. If multiple soonest birthdays, track all of them.
        double diffTime = std::difftime(mktime(&friend_1.birthday), mktime(&localTime));
        if (diffTime == diffTimeMin) {
            friendNames.push_back(friend_1.name);
        }
        if (diffTime < diffTimeMin) {
            isBirthdayToday = (friend_1.birthday.tm_mon == localTime.tm_mon &&
                               friend_1.birthday.tm_mday == localTime.tm_mday);
            friendNames.clear();
            friendNames.push_back(friend_1.name);
            diffTimeMin = diffTime;
            soonestBirthday = friend_1.birthday;
        }
    }

    for (const auto& friendName : friendNames) {
        if (isBirthdayToday) {
            std::cout << friendName << " has birthday today! Don't forget!\n";
        } else {
            std::cout << friendName << " has soonest birthday " <<
                std::put_time(&soonestBirthday, "%m/%d") << "\n";
        }
    }
}

int main() {
    std::vector<Friend> friends;
    std::time_t t = std::time(nullptr);
    std::tm tmpTime = *std::localtime(&t);
    std::string command, tmpName;

    std::cout << "** Welcome to Birthday Tracker **\n";
    while (command != "end") {
        std::cout << "Enter name and of your friend.\n"
                     "Enter \"end\" to finish the list.\n";
        std::cin >> command;

        if (command != "end") {
            tmpName = command;
            std::cout << "Enter birthday of your friend in format: \"friend_name YY/MM/DD\".\n";
            // No input check here! Input is assumed to be correct!
            std::cin >> std::get_time(&tmpTime, "%y/%m/%d");
            friends.push_back({tmpName, tmpTime});
        }
    }

    printSoonestBirthday(friends);

    return 0;
}