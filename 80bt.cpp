#include <algorithm>
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
getLevel(TreeNode *node)
{
    if (!node)
        return 0;

    auto l = getLevel(node->left), r = getLevel(node->right);

    if (l == -1 || r == -1 || abs(l - r) > 1)
        return -1;
    else
        return 1 + std::max(l, r);
}

bool
isBalanced(TreeNode *root)
{
    if (!root)
        return true;

    auto l = getLevel(root->left), r = getLevel(root->right);

    if (l == -1 || r == -1 || abs(l - r) > 1)
        return false;

    return true;
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
