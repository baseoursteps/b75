#include <queue>
#include <vector>

#include "tree.h"

using namespace std;

vector<vector<int>>
levelOrder(TreeNode *root)
{
    vector<vector<int>> sol;

    queue<TreeNode *> q;

    q.push(root);
    while (q.size()) {
        auto p = std::move(q);

        vector<int> level;
        while (p.size()) {
            auto el = p.front();
            p.pop();

            if (el) {
                level.push_back(el->val);

                q.push(el->left);
                q.push(el->right);
            }
        }

        if (level.size())
            sol.push_back(std::move(level));
    }

    return sol;
}

int
main()
{
 }
