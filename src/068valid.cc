#include "tree.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

void
inorder(TreeNode *root, vector<int> &vals)
{
    if (!root)
        return;

    inorder(root->left, vals);
    vals.push_back(root->val);
    inorder(root->right, vals);
}

bool
isValidBST(TreeNode *root)
{
    vector<int> vals;
    inorder(root, vals);
    if (is_sorted(vals.begin(), vals.end())) {
        for (size_t i = 1; i < vals.size(); ++i) {
            if (vals[i] == vals[i - 1]) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

int
main()
{
}
