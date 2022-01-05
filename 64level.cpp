#include <iostream>
#include <unordered_map>

#include "tree.h"

using namespace std;

// level order traversal -- queue
template<typename T>
void
dfs(typename Tree<T>::Child           root,
    size_t                            level,
    unordered_map<size_t, vector<T>> &ordering)
{
    auto locked = root.lock();

    if (!locked)
        return;

    if (!ordering.count(level))
        ordering.insert({ level, {} });

    ordering.at(level).push_back(locked->val);

    dfs<T>(locked->left, level + 1, ordering);
    dfs<T>(locked->right, level + 1, ordering);
}

template<typename T>
void
print_em(const typename Tree<T>::List &list)
{
    if (list.empty())
        return;

    auto [elems, root] = Tree<T>::from_list(list);

    unordered_map<size_t, vector<T>> ordering;
    dfs<T>(root, 1, ordering);

    for (size_t i = 1; i <= ordering.size(); ++i) {
        for (auto &e : ordering.at(i))
            cout << e << " ";

        cout << "\n";
    }
    cout << "\n";
}

int
main()
{
    Tree<int>::List l1 { 4, 2, 7, 1, 3, 6, 9 }, l2 { 3, 9, 20, {}, {}, 15, 7 };
    print_em<int>(l1);
    print_em<int>(l2);
}
