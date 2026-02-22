#include <optional>
#include "tree.h"

using namespace std;

// Given the root of a binary search tree, and an integer k, return the kth
// smallest value (1-indexed) of all the values of the nodes in the tree.

// Input: root = [3,1,4,null,2], k = 1
// Output: 1

// Input: root = [5,3,6,2,4,null,null,1], k = 3
// Output: 3

// post-order traversal i guess

void
iot(TreeNode *root, int k, int &where, optional<int> &sol)
{
    if (!root || where > k) {
        return;
    }

    iot(root->left, k, where, sol);
    if (++where == k) {
        sol = root->val;
        return;
    }
    iot(root->right, k, where, sol);
}

int
kthSmallest(TreeNode *root, int k)
{
    int           where {};
    optional<int> sol {};
    iot(root, k, where, sol);
    return sol.value();
}

int
main()
{
}
