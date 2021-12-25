#include "matrix.h"

using namespace std;

// given an n * n matrix, turn it clockwise
template<typename P>
void
do_it(matrix<P> &m)
{
    if (m.size() < 2 || m.size() != m.at(0).size())
        return;

    for (size_t i = 0; i < m.size() / 2; ++i) {
        for (size_t j = i; j < m.size() - i - 1; ++j) {
            auto temp = m.at(i).at(j);

            m.at(i).at(j) = m.at(m.size() - j - 1).at(i);

            m.at(m.size() - j - 1).at(i) =
                m.at(m.size() - i - 1).at(m.size() - j - 1);

            m.at(m.size() - i - 1).at(m.size() - j - 1) =
                m.at(j).at(m.size() - i - 1);

            m.at(j).at(m.size() - i - 1) = temp;
        }
    }
}

int
main()
{
    // 1 2 3
    // 4 5 6
    // 7 8 9

    // 7 4 1
    // 8 5 2
    // 9 6 3
    matrix<int> m { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };

    matrix<int> p { { 1, 2, 3, 4, 5 },
                    { 6, 7, 8, 9, 10 },
                    { 11, 12, 13, 14, 15 },
                    { 16, 17, 18, 19, 20 },
                    { 21, 22, 23, 24, 25 } };

    matrix<int> q { { 1, 2, 3, 4 },
                    { 5, 6, 7, 8 },
                    { 9, 10, 11, 12 },
                    { 13, 14, 15, 16 } };

    do_it(p);
    print_matrix(p);

    do_it(m);
    print_matrix(m);

    do_it(q);
    print_matrix(q);
}
