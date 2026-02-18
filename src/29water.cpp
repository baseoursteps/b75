#include "graph.h"
#include "matrix.h"
#include <array>
#include <cstddef>
#include <iostream>
#include <sys/types.h>
#include <vector>

using namespace std;

// There is an m x n rectangular island that borders both the Pacific Ocean and
// Atlantic Ocean. The Pacific Ocean touches the island's left and top edges,
// and the Atlantic Ocean touches the island's right and bottom edges.

// The island is partitioned into a grid of square cells. You are given an m x n
// integer matrix heights where heights[r][c] represents the height above sea
// level of the cell at coordinate (r, c).

// The island receives a lot of rain, and the rain water can flow to neighboring
// cells directly north, south, east, and west if the neighboring cell's height
// is less than or equal to the current cell's height. Water can flow from any
// cell adjacent to an ocean into the ocean.

// Return a 2D list of grid coordinates result where result[i] = [ri, ci]
// denotes that rain water can flow from cell (ri, ci) to both the Pacific and
// Atlantic oceans. Input: heights =
// [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]] Output:
// [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]

// this is my lame solution, but it can supposedly be done using graphs...how?
void
do_it(matrix<int> &flows,
      ssize_t      i,
      ssize_t      j,
      int          current,
      bool        &atlantic,
      bool        &pacific)
{
    bool set { false };
    if (i < 0 || j < 0) {
        set = atlantic = true;
    }
    if (i >= (ssize_t)flows.size() || j >= (ssize_t)flows.at(0).size()) {
        set = pacific = true;
    }

    if (set)
        return;

    if (atlantic && pacific)
        return;

    auto newc = flows.at(i).at(j);
    if (newc == -1 || current < newc)
        return;

    flows.at(i).at(j) = -1;

    do_it(flows, i + 1, j, newc, atlantic, pacific);
    do_it(flows, i - 1, j, newc, atlantic, pacific);
    do_it(flows, i, j + 1, newc, atlantic, pacific);
    do_it(flows, i, j - 1, newc, atlantic, pacific);

    flows.at(i).at(j) = newc;
}

void
print_sols(matrix<int> &flows)
{
    for (ssize_t i = 0; i < (ssize_t)flows.size(); ++i) {
        for (ssize_t j = 0; j < (ssize_t)flows.at(i).size(); ++j) {
            bool atlantic { false }, pacific { false };

            do_it(flows, i, j, flows.at(i).at(j), atlantic, pacific);

            if (atlantic && pacific)
                cout << "solution: " << i << " " << j << "\n";
        }
    }
    cout << "--\n";
}

int
main()
{
    matrix<int> flows { { 1, 2, 2, 3, 5 },
                        { 3, 2, 3, 4, 4 },
                        { 2, 4, 5, 3, 1 },
                        { 6, 7, 1, 4, 5 },
                        { 5, 1, 1, 2, 4 } };

    matrix<int> flows1 { { 2, 1 }, { 1, 2 } };

    print_sols(flows);
    print_sols(flows1);
}
