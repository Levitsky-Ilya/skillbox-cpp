#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <memory>

auto remove_copies = [](std::vector<int> v)
{
    std::unordered_set<int> s(v.begin(), v.end());
    std::vector<int> result;
    std::for_each(s.begin(), s.end(), [&result](auto it){ result.push_back(it); });
    return std::make_unique<std::vector<int>> (result);
};

int main() {
    auto unique_values = remove_copies({1, 2, 2, 3, 3, 2, 1, 1, 2, 67, 76, 67});
    for (auto &i : *unique_values) {
        std::cout << i << " ";
    }
    return 0;
}
