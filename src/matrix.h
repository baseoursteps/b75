#include <vector>
#include <iostream>

#pragma once

template<typename T>
using matrix = std::vector<std::vector<T>>;

template<typename T>
void
print_matrix(const matrix<T> &m)
{
    for (auto &&l : m) {
        for (auto &&c : l)
            std::cout << c << " ";

        std::cout << "\n";
    }
    std::cout << "\n";
}
