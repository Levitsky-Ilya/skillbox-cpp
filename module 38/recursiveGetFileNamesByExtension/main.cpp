#include <iostream>
#include <vector>
#include <memory>
#include <filesystem>

// TODO Dear Skillbox! Please state explicitly that
//  C++17 version is needed for filesystem library to operate correctly!

// TODO Dear Skillbox! I had troubles with a bug of filesystem as reported here:
//  https://sourceforge.net/p/mingw-w64/bugs/737/
//  It is a good idea to give a recommendation for students on how to resolve it. (I used Visual Studio)

auto recursiveGetFileNamesByExtension =
       [](std::filesystem::path path,
          const std::string extension) {

    namespace fs = std::filesystem;
    std::vector<std::string> filenames;

    for (auto& p: fs::recursive_directory_iterator(path)) {

        if (p.is_regular_file() && (p.path().extension().compare(extension) == 0)) {
            filenames.push_back(p.path().string());
        }
    }
    return std::make_unique<std::vector<std::string>>(filenames);
};

int main() {
    namespace fs = std::filesystem;

    std::cout << "Type the path to file:\n> ";
    std::string input;
    std::cin >> input;
    fs::path path(input);

    std::cout << "Type the extenstion to be searched, e.g.: .txt:\n> ";
    std::cin >> input;

    auto filenames = recursiveGetFileNamesByExtension(path, input);
    for (auto& filename : *filenames) {
        std::cout << filename << "\n";
    }
    return 0;
}
