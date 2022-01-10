#include <iostream>

#include "list.hpp"

using namespace std;

int
main()
{
    auto [vals, head] = LList<int>::from_list({ 1, 2, 3, 4, 5, 6 });

    LList<int>::reverse(head);

    cout << head << "\n";
}
