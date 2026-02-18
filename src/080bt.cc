#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

// Given a binary tree, determine if it is height-balanced.
//
// For this problem, a height-balanced binary tree is defined as:
//
// a binary tree in which the left and right subtrees of every node differ in
// height by no more than 1.

struct TreeNode
{
    int       val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) :
        val(x),
        left(left),
        right(right)
    {
    }
};

int
level(TreeNode *root)
{
    if (!root) {
        return 0;
    } else {
        return std::max(level(root->left), level(root->right)) + 1;
    }
}

bool
isBalanced(TreeNode *root)
{
    bool ok { true };
    if (!root) {
        return ok;
    }

    auto l = level(root->left);
    auto r = level(root->right);

    ok &= (abs(l - r) <= 1);

    if (ok)
        ok &= isBalanced(root->left);

    if (ok)
        ok &= isBalanced(root->right);

    return ok;
}

int
main()
{
    vector<TreeNode> vals { { 0 }, { 1 }, { 2 }, { 3 }, { 4 }, { 5 }, { 6 } };

    //          0
    //       1        2
    //    3    4
    // 5     6
    vals.at(0).right = &vals.at(2);
    vals.at(0).left  = &vals.at(1);

    vals.at(1).left  = &vals.at(3);
    vals.at(1).right = &vals.at(4);

    vals.at(3).left  = &vals.at(5);
    vals.at(3).right = &vals.at(6);

    cout << isBalanced(&vals.at(0)) << "\n";
}
