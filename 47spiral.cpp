#include <iostream>
#include <sys/types.h>
#include <vector>
using namespace std;

template<typename T>
using matrix = vector<vector<T>>;

// Given an m * n matrix return its elements in spiral order
template<typename P>
vector<P>
do_it(const matrix<P> &m)
{
    if (m.size() == 0)
        return {};

    ssize_t   L /*eft*/   = 0;
    ssize_t   R /*ight*/  = m.at(0).size() - 1;
    ssize_t   T /*op*/    = 0;
    ssize_t   B /*ottom*/ = m.size() - 1;
    vector<P> vals;

    while (vals.size() < m.size() * m.at(0).size()) {
        // left to right
        for (ssize_t i = L; i <= R; ++i) {
            vals.push_back(m.at(T).at(i));
        }
        ++T;

        // top to bottom
        for (ssize_t i = T; i <= B; ++i) {
            vals.push_back(m.at(i).at(R));
        }
        --R;

        // right to left
        for (ssize_t i = R; i >= L; --i) {
            vals.push_back(m.at(B).at(i));
        }
        --B;

        // bottom to top
        for (ssize_t i = B; i >= T; --i) {
            vals.push_back(m.at(i).at(L));
        }
        L++;
    }

    // we end up with extra elements when n != m
    vals.resize(m.size() * m.at(0).size());
    return vals;
}

template<typename T>
void
print(const matrix<T> &m)
{
    for (auto &&l : m) {
        for (auto &&c : l)
            std::cout << c << " ";

        cout << "\n";
    }

    auto rez = do_it(m);

    for (auto &&e : rez)
        cout << e << " ";

    cout << "\n\n";
}

int
main()
{
    matrix<int>       m { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    const vector<int> m_rez { 1, 2, 3, 6, 9, 8, 7, 4, 5 };

    matrix<int>       p { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
    const vector<int> p_rez { 1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7 };

    matrix<int>       q { { 1 }, { 2 }, { 3 } };
    const vector<int> q_rez { 1, 2, 3 };

    print(m);
    print(p);
    print(q);
}
