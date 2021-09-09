#include <iostream>
#include <cpr/cpr.h>

int main() {
    //cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"),
    //                           cpr::Header({{"accept", "text/html"}}));
    cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"));
    std::string text = r.text;
    int beginPos = text.find("<h1>") + 4;
    int endPos = text.find("</h1>", beginPos);
    std::cout << text.substr(beginPos, endPos - beginPos);
}
