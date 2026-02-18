#include <iostream>
#include <sys/types.h>

#include "tree.h"

using namespace std;

// A path in a binary tree is a sequence of nodes where each pair of adjacent
// nodes in the sequence has an edge connecting them. A node can only appear in
// the sequence at most once. Note that the path does not need to pass through
// the root. The path sum of a path is the sum of the node's values in the path.
// Given the root of a binary tree, return the maximum path sum of any non-empty
// path.

// Input: root = [-10,9,20,null,null,15,7]
// Output: 42
// Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7
// = 42.

// tricky

// we have a root
// we determine max on the left and right
// we sum left, right, current
// if right > sum return right
// if left > sum return left
// else return sum

template<typename T>
ssize_t
max_sum(typename Tree<T>::Child root)
{
    auto locked = root.lock();
    if (!locked)
        return 0;

    auto left  = max_sum<T>(locked->left);
    auto right = max_sum<T>(locked->right);

    auto sum = left + right + locked->val;

    if (left > sum)
        return left;
    else if (right > sum)
        return right;
    else
        return sum;
}

template<typename T>
ssize_t
print_max(const typename Tree<T>::List &list)
{
    auto [elems, root] = Tree<T>::from_list(list);

    if (!root)
        throw "dude, stop";

    return max_sum<T>(root);
}

int
main()
{
    // 42
    Tree<int>::List t1 { -10, 9, 20, {}, {}, 15, 7 };

    // 6
    Tree<int>::List t2 { 1, 2, 3 };

    cout << print_max<int>(t1) << " " << print_max<int>(t2) << "\n";
}
