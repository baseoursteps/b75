#include <deque>
#include <iostream>
#include <vector>

using namespace std;

// Given the root of a binary tree, imagine yourself standing on the right side
// of it, return the values of the nodes you can see ordered from top to bottom.

// Input: root = [1,2,3,null,5,null,4]
// Output: [1,3,4]

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

// The trick seems to be that on each level i have to print the rightmost
// node...in other words.
vector<int>
rightSideView(TreeNode *root)
{
    if (!root)
        return {};

    deque<TreeNode *> nodes;

    nodes.push_back(root);

    vector<int> sol;

    while (!nodes.empty()) {
        auto level = move(nodes);
        sol.push_back(level.back()->val);

        while (!level.empty()) {
            auto node = level.front();
            level.pop_front();

            if (node->left)
                nodes.push_back(node->left);

            if (node->right)
                nodes.push_back(node->right);
        }
    }

    return sol;
}

int
main()
{
    /*
                   0
            1            2
               3      4     5
                   6

      would be 0 2 5 6
     */
    vector<TreeNode> nodes { 0, 1, 2, 3, 4, 5, 6 };

    nodes.at(0).left  = &nodes.at(1);
    nodes.at(0).right = &nodes.at(2);

    nodes.at(1).right = &nodes.at(3);

    nodes.at(2).left  = &nodes.at(4);
    nodes.at(2).right = &nodes.at(5);

    nodes.at(4).left = &nodes.at(6);

    for (auto &&v : rightSideView(&nodes.at(0)))
        cout << v << " ";

    cout << "\n";
}
