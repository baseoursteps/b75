#include "matrix.h"
#include <iostream>

using namespace std;

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and
// '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands
// horizontally or vertically. You may assume all four edges of the grid are all
// surrounded by water.

void
nos(matrix<int> &lands, int i, int j)
{
    if (i < 0 || i >= (int)lands.size() || j < 0 ||
        j >= (int)lands.at(i).size() || !lands.at(i).at(j))
        return;

    lands.at(i).at(j) = 0;
    nos(lands, i + 1, j);
    nos(lands, i - 1, j);
    nos(lands, i, j + 1);
    nos(lands, i, j - 1);
}

int
count_em(matrix<int> &lands)
{
    int counter { 0 };
    for (int i = 0; i < (int)lands.size(); ++i) {
        for (int j = 0; j < (int)lands.at(i).size(); ++j) {
            if (lands.at(i).at(j) == 1) {
                counter++;
                nos(lands, i, j);
            }
        }
    }

    return counter;
}

int
main()
{
    matrix<int> lands { { 1, 1, 0, 0, 0 },
                        { 1, 1, 0, 0, 0 },
                        { 0, 0, 1, 0, 0 },
                        { 0, 0, 0, 1, 1 } };

    matrix<int> lands1 { { 1, 1, 1, 1, 0 },
                         { 1, 1, 0, 1, 0 },
                         { 1, 1, 0, 0, 0 },
                         { 0, 0, 0, 0, 0 } };

    cout << count_em(lands) << " " << count_em(lands1) << "\n";
}
