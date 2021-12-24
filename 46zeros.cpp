#include <iostream>
#include <vector>
using namespace std;

// Given an m x n integer matrix matrix, if an element is 0, set its entire row
// and column to 0's, and return the matrix.
template<typename T>
using matrix = vector<vector<T>>;

// Keep the first line and column as flags if the corresponding column or line
// is to be set to zero. Also keep two flags if the first line or column itself
// has to be set. Start setting from the second line/column and at the end check
// the flags and set the first line or column if needed.
template<typename T>
void
do_it(matrix<T> &m)
{
    bool firstColumn { false }, firstLine { false };

    for (ssize_t i = 0; i < m.size(); ++i) {
        for (ssize_t j = 0; j < m.at(i).size(); j++) {
            if (m.at(i).at(j) == 0) {
                if (!i)
                    firstLine = true;

                if (!j)
                    firstColumn = true;

                m.at(i).at(0) = 0;
                m.at(0).at(j) = 0;
            }
        }
    }

    // set lines starting from second
    for (size_t i = 1; i < m.size(); ++i) {
        if (!m.at(i).at(0)) {
            m.at(i) = vector<T>(m.at(i).size(), {});
        }
    }

    // set columns starting from second
    for (size_t j = 1; j < m.at(0).size(); ++j) {
        if (!m.at(0).at(j))
            for (size_t i = 0; i < m.size(); ++i)
                m.at(i).at(j) = 0;
    }

    if (firstLine)
        m.at(0) = vector<T>(m.at(0).size(), {});

    if (firstColumn)
        for (ssize_t i = 0; i < m.size(); ++i)
            m.at(i).at(0) = {};
}

template<typename T>
void
print_matrix(const matrix<T> &m)
{
    for (auto &&l : m) {
        for (auto &&c : l)
            std::cout << c << " ";

        cout << "\n";
    }
    cout << "\n";
}

int
main()
{
    matrix<int>       a { { 1, 1, 1 }, { 1, 0, 1 }, { 1, 1, 1 } };
    const matrix<int> a_rez { { 1, 0, 1 }, { 0, 0, 0 }, { 1, 0, 1 } };

    matrix<int>       b { { 0, 1, 2, 0 }, { 3, 4, 5, 2 }, { 1, 3, 1, 5 } };
    const matrix<int> b_rez { { 0, 0, 0, 0 }, { 0, 4, 5, 0 }, { 0, 3, 1, 0 } };

    do_it(a);
    print_matrix(a);

    do_it(b);
    print_matrix(b);
}
