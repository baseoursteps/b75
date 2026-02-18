#include <cstdlib>
#include <iostream>

#include "heap.hpp"

using namespace std;
int
main()
{
    Heap<int, Type::Max> h { 1, 3, 1, 3, 9, 7, 5 };

    srand(time(nullptr));

    for (int i = 0; i < 10; i++)
        h.insert(rand() % 1024);

    while (!h.empty())
        cout << h.pop_front().value() << "\n";
}
