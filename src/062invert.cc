#include <utility>

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

void
reverse(TreeNode *root)
{
    if (!root) {
        return;
    }
    std::swap(root->left, root->right);

    reverse(root->left);
    reverse(root->right);
}

TreeNode *
invertTree(TreeNode *root)
{
    reverse(root);
    return root;
}

int
main()
{
}
