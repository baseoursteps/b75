#include <utility>

struct TreeNode
{
    int       val;
    TreeNode *left {};
    TreeNode *right {};
    TreeNode(int x) : val(x) {}
};

// Given a binary search tree (BST), find the lowest common ancestor (LCA) of
// two given nodes in the BST.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor
// is defined between two nodes p and q as the lowest node in T that has both p
// and q as descendants (where we allow a node to be a descendant of itself).”

// Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
// Output: 6

TreeNode *
lca(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root->val == p->val || root->val == q->val) {
        return root;
    } else if (root->val > p->val && root->val < q->val) {
        return root;
    } else if (root->val < p->val && root->val < q->val) {
        return lca(root->right, p, q);
    } else if (root->val > p->val && root->val > q->val) {
        return lca(root->left, p, q);
    }

    return nullptr;
}

TreeNode *
lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!(root && p && q)) {
        return nullptr;
    }

    if (p->val > q->val) {
        std::swap(p, q);
    }

    return lca(root, p, q);
}

int
main()
{
}
