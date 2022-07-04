#include <iostream>
#include <vector>

using namespace std;

// Given the root of a binary tree, return the length of the diameter of the
// tree.
//
// The diameter of a binary tree is the length of the longest path between any
// two nodes in a tree. This path may or may not pass through the root.
//
// The length of a path between two nodes is represented by the number of edges
// between them.

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

// max length from it, max length through it or its children
pair<int, int>
diam(TreeNode *t)
{
    if (!t)
        return { 0, 0 };

    auto &&[lf, lt] = diam(t->left);
    auto &&[rf, rt] = diam(t->right);

    pair<int, int> md;
    md.first  = 1 + std::max(lf, rf);
    md.second = std::max(lf + rf, std::max(lt, rt));

    return md;
}

int
diameterOfBinaryTree(TreeNode *root)
{
    auto sol = diam(root);
    return sol.second;
}

int
main()
{
    vector<TreeNode> vals { { 0 }, { 1 }, { 2 }, { 3 }, { 4 }, { 5 } };

    //            0
    //    2              1
    // 3    4
    vals.at(0).right = &vals.at(1);
    vals.at(0).left  = &vals.at(2);

    vals.at(2).left  = &vals.at(3);
    vals.at(2).right = &vals.at(4);

    cout << diameterOfBinaryTree(&vals.at(0)) << "\n";
}
