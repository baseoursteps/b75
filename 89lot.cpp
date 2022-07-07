#include <cstddef>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// Given the root of a binary tree, return the level order traversal of its
// nodes' values. (i.e., from left to right, level by level).

// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]

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

vector<vector<int>>
levelOrder(TreeNode *root)
{
    unordered_map<TreeNode *, size_t> levels;
    queue<TreeNode *>                 q;

    q.push(root);
    levels.insert({ root, 0 });
    vector<vector<int>> sol;

    while (q.size()) {
        auto v = q.front();
        q.pop();

        if (v) {
            if (sol.size() == levels.at(v))
                sol.push_back({});

            sol.at(levels.at(v)).push_back(v->val);

            if (auto l = v->left; l) {
                q.push(l);
                levels.insert({ l, levels.at(v) + 1 });
            }

            if (auto r = v->right; r) {
                q.push(r);
                levels.insert({ r, levels.at(v) + 1 });
            }
        }
    }

    return sol;
}

int
main()
{
    vector<TreeNode> t { { 3 }, { 9 }, { 20 }, { 15 }, { 7 } };

    //       3
    // 9          20
    //         15      7
    t.at(0).left  = &t.at(1);
    t.at(0).right = &t.at(2);

    t.at(2).left  = &t.at(3);
    t.at(2).right = &t.at(4);

    for (auto &&level : levelOrder(&t.front())) {
        for (auto &&v : level)
            cout << v << " ";

        cout << "\n";
    }
}
