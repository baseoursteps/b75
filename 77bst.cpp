#include <iostream>
#include <vector>

using namespace std;

// convert binary search tree to doubly-linked list in place

struct List
{
    int          val { -1 };
    struct List *l {}, *r {};

    List(int val) : val(val) {}

    static void
    in_order(List *elem, List *&back, List *&nh, List *&biggest)
    {
        if (!elem)
            return;

        in_order(elem->l, back, nh, biggest);
        elem->l = back;
        back    = elem;

        if (!nh)
            nh = elem;

        if (biggest->val < elem->val)
            biggest = elem;

        in_order(elem->r, back, nh, biggest);
    }
};

int
main()
{
    vector<List> nodes { { 8 },  { 3 }, { 10 }, { 1 }, { 6 },
                         { 14 }, { 4 }, { 7 },  { 13 } };

    List *back {}, *nh {}, *biggest { &nodes.at(0) };

    // should yield 1 3 4 6 7 8 10 13 14

    // 8 -> 3 10
    nodes.at(0).l = &nodes.at(1);
    nodes.at(0).r = &nodes.at(2);

    // 3 -> 1 6
    nodes.at(1).l = &nodes.at(3);
    nodes.at(1).r = &nodes.at(4);

    // 6 -> 4 7
    nodes.at(4).l = &nodes.at(6);
    nodes.at(4).r = &nodes.at(7);

    // 10 -> {} , 14
    nodes.at(2).r = &nodes.at(5);

    // 14-> 13, {}
    nodes.at(5).l = &nodes.at(8);

    List::in_order(&nodes.at(0), back, nh, biggest);

    for (auto prev = biggest, current = biggest->l; current != nullptr;
         prev = current, current = current->l) {
        current->r = prev;
    }

    for (auto &&v = nh; v != nullptr; v = v->r)
        cout << v->val << " ";

    cout << "\n";
}
