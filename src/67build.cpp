#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <memory>
#include <unordered_map>
#include <utility>
#include <vector>

#include "tree.h"

using namespace std;

// Given two integer arrays preorder and inorder where preorder is the preorder
// traversal of a binary tree and inorder is the inorder traversal of the same
// tree, construct and return the binary tree.
// disgusting

// preorder
// visit left right

// inorder
// left visit right

// i swear to god. after 4 hours it just clicked. i have no idea why this is
// correct, but it works

template<typename T>
typename Tree<T>::OwnedTree
cvt(vector<T>                                     &preorder,
    vector<T>                                     &inorder,
    unordered_map<T, typename Tree<T>::OwnedTree> &vals)

{
    if (preorder.empty())
        return {};

    auto root = make_shared<Tree<T>>(*preorder.begin());
    vals.insert({ root->val, root });

    if (*preorder.begin() == *inorder.begin()) {
        preorder.erase(preorder.begin());
        inorder.erase(inorder.begin());
    } else {
        preorder.erase(find(preorder.begin(), preorder.end(), root->val));
        inorder.erase(find(inorder.begin(), inorder.end(), root->val));

        root->left  = cvt<T>(preorder, inorder, vals);
        root->right = cvt<T>(preorder, inorder, vals);
    }

    return root;
}

template<typename T>
pair<unordered_map<T, typename Tree<T>::OwnedTree>, typename Tree<T>::OwnedTree>
convert(vector<T> &preorder, vector<T> &inorder)
{
    if (preorder.empty())
        return {};

    unordered_map<T, typename Tree<T>::OwnedTree> vals;
    auto root = cvt<T>(preorder, inorder, vals);

    return { vals, root };
}

int
main()
{
    vector<int> pre { 3, 9, 20, 15, 7 }, in { 9, 3, 15, 20, 7 };
    auto [elems, root] = convert<int>(pre, in);

    cout << root << "\n";
}
