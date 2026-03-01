#include "tree.h"
#include <deque>

using namespace std;

bool
findNode(TreeNode *root, const TreeNode *f, deque<TreeNode *> &path)
{
    if (!root) {
        return false;
    }

    path.push_back(root);
    if (root->val == f->val) {
        return true;
    }

    auto l = findNode(root->left, f, path);
    auto r = findNode(root->right, f, path);

    if (l || r) {
        return true;
    } else {
        path.pop_back();
        return false;
    }
}

TreeNode *
lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!(root && p && q)) {
        return {};
    }

    deque<TreeNode *> dp, dq;
    findNode(root, p, dp);
    findNode(root, q, dq);

    TreeNode *last {};

    while (dp.size() && dq.size()) {
        auto pf = dp.front();
        dp.pop_front();
        auto qf = dq.front();
        dq.pop_front();

        if (pf->val == qf->val) {
            last = pf;
        } else {
            return last;
        }
    }

    return last;
}

int
main()
{
}
