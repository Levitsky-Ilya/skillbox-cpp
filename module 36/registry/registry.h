//
// Created by leviz on 15.01.2022.
//

#ifndef REGISTRY_REGISTRY_H
#define REGISTRY_REGISTRY_H

#include <iostream>
#include <vector>

template<typename T1, typename T2>
class Registry {
public:
    void add(T1 key, T2 elem) {
        m_reg.push_back({key, elem});
    }

    void remove(T1 key) {
        for (auto it = m_reg.begin(); it != m_reg.end(); ) {
            if (it->first == key) {
                it = m_reg.erase(it);
            } else {
                it++;
            }
        }
    }

    void print(T1 key) {
        std::vector<T2> result = find(key);
        if (result.empty()) {
            std::cout << "(No values found)\n";
        }
        for (auto& e : result) {
            std::cout << e << "\n";
        }
    }

    std::vector<T2> find(T1 key) {
        std::vector<T2> result;
        for (auto& e : m_reg) {
            if (e.first == key) {
                result.push_back(e.second);
            }
        }
        return result;
    }

private:
    std::vector<std::pair<T1, T2>> m_reg;
};

// Questions:
// 1) Is there a way to move the function definitions to registry.cpp?
//  When I tried, I got "undefined reference to [template function]"
// 2) Is defining template functions in a header file a good practice?

#endif //REGISTRY_REGISTRY_H
