#pragma once

#include <cstddef>
#include <deque>
#include <memory>
#include <optional>
#include <unordered_map>
#include <unordered_set>
#include <vector>

template<typename T>
struct Tree
{
    using OwnedTree = std::shared_ptr<Tree<T>>;
    using Child     = std::weak_ptr<Tree<T>>;
    using List      = std::vector<std::optional<T>>;

    T     val;
    Child left, right;

    Tree<T>() : val { {} } {}
    Tree<T>(const T &val) : val { val } {}

    Tree<T>(const T &val, const Child &l, const Child &r) :
        val { val },
        left { l },
        right { r }
    {
    }

    static std::unordered_map<T, typename Tree<T>::OwnedTree>
    from_list(typename Tree<T>::List vals, typename Tree<T>::OwnedTree &root)

    {
        if (vals.empty())
            return {};

        std::unordered_map<T, typename Tree<T>::OwnedTree> tree;

        bool rset { false };

        for (auto &&el : vals)
            if (el) {
                auto elem = std::make_shared<Tree<T>>(el.value());
                tree.insert({ el.value(), elem });
                if (!rset) {
                    root = elem;
                    rset = true;
                }
            }

        // must always put both left and right child -- must be uneven
        if (vals.size() % 2 == 0)
            vals.push_back({});

        for (size_t i = 0; i < vals.size() / 2; ++i) {
            auto parent = vals.at(i);

            if (!parent)
                continue;

            auto lchild = vals.at(2 * i + 1);
            if (lchild)
                tree.at(parent.value())->left = tree.at(lchild.value());

            auto rchild = vals.at(2 * i + 2);
            if (rchild)
                tree.at(parent.value())->right = tree.at(rchild.value());
        }

        return tree;
    }

    friend std::ostream &
    operator<<(std::ostream &out, typename Tree<T>::OwnedTree tree)
    {
        if (!tree)
            return out;

        // bfs
        std::deque<typename Tree<T>::OwnedTree> vals;
        vals.push_back(tree);

        while (!vals.empty()) {
            auto curr = vals.front();
            vals.pop_front();
            out << "current: " << curr->val << ", left: ";

            if (auto left = curr->left.lock()) {
                vals.push_back(left);
                out << left->val;
            } else
                out << "x";

            out << ", right: ";

            if (auto right = curr->right.lock()) {
                vals.push_back(right);
                out << right->val;
            } else
                out << "x";

            out << "\n";
        }

        return out;
    }
};
