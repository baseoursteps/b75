#include <iostream>
#include <vector>

#include "tree.h"

using namespace std;

// Given the root of a binary tree, return the length of the diameter of the
// tree.
//
// The diameter of a binary tree is the length of the longest path between any
// two nodes in a tree. This path may or may not pass through the root.
//
// The length of a path between two nodes is represented by the number of edges
// between them.


    int diameter{};

    int level(TreeNode* n) {
        if (!n) {
            return 0;
        }

        auto l = level(n->left);
        auto r = level(n->right);
        diameter = std::max(diameter, l + r);

        return std::max(l, r) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        level(root);
        return diameter;
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
