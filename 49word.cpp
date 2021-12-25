#include <iostream>
#include <string>

#include "matrix.h"

using namespace std;

// Given a matrix with characters and a string. check if any combination of
// adjacent cells form the string. the same cell cannot be used twice
template<typename P>
bool
do_it(matrix<P> &m, string word)
{
    if (word.empty())
        return true;

    for (size_t i = 0; i < m.size(); ++i) {
        for (size_t j = 0; j < m.at(i).size(); ++j) {
            if (m.at(i).at(j) == ' ')
                continue;

            if (m.at(i).at(j) == word.at(0)) {
                m.at(i).at(j) = ' ';
                word.erase(0, 1);
                return do_it(m, word);
            }
        }
    }

    return false;
}

int
main()
{
    // true
    matrix<char> board { { 'A', 'B', 'C', 'E' },
                         { 'S', 'F', 'C', 'S' },
                         { 'A', 'D', 'E', 'E' } };

    string word { "ABCCED" };

    // true
    matrix<char> board2 { { 'A', 'B', 'C', 'E' },
                          { 'S', 'F', 'C', 'S' },
                          { 'A', 'D', 'E', 'E' } };
    string       word2 = "SEE";

    // false
    matrix<char> board3 = { { 'A', 'B', 'C', 'E' },
                            { 'S', 'F', 'C', 'S' },
                            { 'A', 'D', 'E', 'E' } };
    string       word3  = "ABCB";

    cout << do_it(board, word) << "\n";
    cout << do_it(board2, word2) << "\n";
    cout << do_it(board3, word3) << "\n";
}
