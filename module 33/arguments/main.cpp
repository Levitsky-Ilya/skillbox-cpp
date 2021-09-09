#include <iostream>
#include <cpr/cpr.h>

int main() {

    std::cout << "Enter pairs of <argument> <value>\n"
                 "To send the request, enter \"post\" or \"get\"\n";


    std::string argument, value;
    std::stringstream commandStream;

    std::vector<cpr::Pair> argumentList;
    cpr::Response r;

    while (argument != "post" && argument != "get") {

        argument = value = "";
        std::getline(std::cin, argument);
        commandStream << argument;
        commandStream >> argument;

        if (argument == "post") {

            //********** POST request **********//
            r = cpr::Post(cpr::Url("http://httpbin.org/post"),
                          cpr::Payload(argumentList.begin(), argumentList.end()));

        } else if (argument == "get") {

            //********** GET request **********//
            std::string argumentTail;
            if (!argumentList.empty()) {
                argumentTail = "?";
                for (const auto& pair : argumentList) {
                    argumentTail += pair.key + "=" + pair.value + "&";
                }
                argumentTail = argumentTail.substr(0,argumentTail.size() - 1);
                std::cout << "http://httpbin.org/get" + argumentTail << "\n";
            }

            r = cpr::Get(cpr::Url("http://httpbin.org/get" + argumentTail));

        } else if (!argument.empty()) {
            commandStream >> value;
            argumentList.emplace_back(argument, value);

        }

        commandStream.clear();
    }

    std::cout << r.text << std::endl;
    return 0;
}
