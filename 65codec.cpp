#include <deque>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

#include "tree.h"

using namespace std;

template<typename T>
unordered_map<T, typename Tree<T>::OwnedTree>
from_str(string in, typename Tree<T>::OwnedTree &root)
{
    if (in.empty())
        return {};

    decltype(in.size()) pos = 0;

    if (in.at(in.size() - 1) != '#')
        in.push_back('#');

    typename Tree<T>::List listy;

    while ((pos = in.find('#')) != in.npos) {
        stringstream ss { in.substr(0, pos) };
        T            rez;
        if (ss >> rez)
            listy.push_back(rez);
        else
            listy.push_back({});

        in.erase(0, pos + 1);
    }

    return Tree<T>::from_list(listy, root);
}

template<typename T>
string
to_str(typename Tree<T>::Child const &root)
{
    if (!root.lock())
        return {};

    deque<typename Tree<T>::Child> vals;
    vals.push_back(root);

    stringstream conv;
    for (size_t count = 1; count;) {
        auto val = vals.front().lock();
        vals.pop_front();

        if (!val) {
            conv << "x";
            vals.push_back({});
            vals.push_back({});
            --count;
        } else {
            conv << val->val;
            vals.push_back(val->left);
            vals.push_back(val->right);
            ++count;
        }

        conv << "#";
    }

    return conv.str();
}

int
main()
{
    string list { "1#2#3#x#x#4#5" };
    // string list { "1" };

    Tree<int>::OwnedTree root;

    auto elems = from_str<int>(list, root);

    auto as_str = to_str<int>(root);

    cout << root << "\n" << as_str << "\n";
}
