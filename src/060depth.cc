#include "tree.h"
#include <algorithm>

using namespace std;

// Given the root of a binary tree, return its maximum depth.

// A binary tree's maximum depth is the number of nodes along the longest path
// from the root node down to the farthest leaf node.

int
maxDepth(TreeNode *root)
{
    if (!root) {
        return 0;
    } else {
        auto l = maxDepth(root->left);
        auto r = maxDepth(root->right);

        return std::max(l, r) + 1;
    }
}

int
main()
{
}
