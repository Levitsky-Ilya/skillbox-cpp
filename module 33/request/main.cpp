#include <iostream>
#include <cpr/cpr.h>

int main() {

    std::cout << "Commands: get, post, put, delete, patch, exit\n\n>";

    std::string command;

    while (command != "exit") {
        std::cin >> command;

        bool isCommandValid = true;
        cpr::Response r;

        if (command == "get") {
            r = cpr::Get(cpr::Url("http://httpbin.org/get"));
        } else if (command == "post") {
            r = cpr::Post(cpr::Url("http://httpbin.org/post"));
        } else if (command == "put") {
            r = cpr::Put(cpr::Url("http://httpbin.org/put"));
        } else if (command == "delete") {
            r = cpr::Delete(cpr::Url("http://httpbin.org/delete"));
        } else if (command == "patch") {
            r = cpr::Patch(cpr::Url("http://httpbin.org/patch"));
        } else {
            isCommandValid = false;
            if (command != "exit")  {
                std::cout << "Unknown command!\n";
            }
        }

        if (isCommandValid) {
            std::cout << r.text << "\n>";
        }
    }

}
