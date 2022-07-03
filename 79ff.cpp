#include "matrix.h"
#include <iostream>
#include <sys/types.h>
#include <vector>

using namespace std;

// An image is represented by an m x n integer grid image where image[i][j]
// represents the pixel value of the image.
//
// You are also given three integers sr, sc, and color. You should perform a
// flood fill on the image starting from the pixel image[sr][sc].
//
// To perform a flood fill, consider the starting pixel, plus any pixels
// connected 4-directionally to the starting pixel of the same color as the
// starting pixel, plus any pixels connected 4-directionally to those pixels
// (also with the same color), and so on. Replace the color of all of the
// aforementioned pixels with color.
//
// Return the modified image after performing the flood fill.
//
//
//
// Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
// Output: [[2,2,2],[2,2,0],[2,0,1]]
// Explanation: From the center of the image with position (sr, sc) = (1, 1)
// (i.e., the red pixel), all pixels connected by a path of the same color as
// the starting pixel (i.e., the blue pixels) are colored with the new color.
// Note the bottom corner is not colored 2, because it is not 4-directionally
// connected to the starting pixel.

void
ff(matrix<int> &image, int sr, int sc, int o_color)
{
    if (sr < 0 || sc < 0 || sr >= ssize_t(image.size()) ||
        sc >= ssize_t(image.front().size()))
        return;

    if (image.at(sr).at(sc) == o_color) {
        image.at(sr).at(sc) = -1;
        ff(image, sr + 1, sc, o_color);
        ff(image, sr - 1, sc, o_color);
        ff(image, sr, sc + 1, o_color);
        ff(image, sr, sc - 1, o_color);
    }
}

vector<vector<int>>
floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    if (image.empty() || image.front().empty())
        return image;

    ff(image, sr, sc, image.at(sr).at(sc));

    for (auto &l : image)
        for (auto &c : l)
            if (c == -1)
                c = color;

    return image;
}

int
main()
{
    matrix<int> val { { 1, 1, 1 }, { 1, 1, 0 }, { 1, 0, 1 } },
        val2 { { 0, 0, 0 }, { 0, 0, 0 } };

    floodFill(val, 1, 1, 2);
    floodFill(val2, 0, 0, 0);

    print_matrix(val);
    print_matrix(val2);
}
