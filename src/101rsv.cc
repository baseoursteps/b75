#include <iostream>
#include <queue>
#include <vector>

#include "tree.h"

using namespace std;

// Given the root of a binary tree, imagine yourself standing on the right side
// of it, return the values of the nodes you can see ordered from top to bottom.

// Input: root = [1,2,3,null,5,null,4]
// Output: [1,3,4]

// The trick seems to be that on each level i have to print the rightmost
// node...in other words.

vector<int>
rightSideView(TreeNode *root)
{
    queue<TreeNode *> q;
    vector<int>       sol;

    if (!root) {
        return sol;
    }

    q.push(root);

    while (q.size()) {
        auto pq = std::move(q);

        while (pq.size()) {
            auto el = pq.front();
            pq.pop();

            if (pq.empty()) {
                sol.push_back(el->val);
            }

            if (el->left) {
                q.push(el->left);
            }

            if (el->right) {
                q.push(el->right);
            }
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
