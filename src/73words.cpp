#include "matrix.h"

#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

using namespace std;

// Given an m x n board of characters and a list of strings words, return all
// words on the board.

// Each word must be constructed from letters of sequentially adjacent cells,
// where adjacent cells are horizontally or vertically neighboring. The same
// letter cell may not be used more than once in a word.

// brute force -- will never pass larger input
bool
contains(matrix<char> &board,
         const string &word,
         size_t        idx,
         ssize_t       i,
         ssize_t       j)
{
    if (idx >= word.size())
        return true;

    if (i < 0 || (size_t)i >= board.size())
        return false;

    if (j < 0 || (size_t)j >= board.begin()->size())
        return false;

    if (word.at(idx) != board.at(i).at(j))
        return false;

    char temp = '\0';
    swap(board.at(i).at(j), temp);

    bool ret { true };

    do {
        if (contains(board, word, idx + 1, i + 1, j))
            break;
        if (contains(board, word, idx + 1, i - 1, j))
            break;
        if (contains(board, word, idx + 1, i, j + 1))
            break;
        if (contains(board, word, idx + 1, i, j - 1))
            break;

        ret = false;
    } while (0);

    swap(board.at(i).at(j), temp);

    return ret;
}

void
firstSol(const vector<string> &words, const matrix<char> &_board)
{
    auto board = _board;
    for (auto &s : words) {
        bool done { false };
        for (size_t i = 0; i < board.size() && !done; ++i)
            for (size_t j = 0; j < board.at(i).size() && !done; ++j) {
                if (contains(board, s, 0, i, j)) {
                    done = true;
                    cout << "board contains:" << s << "\n";
                }
            }
    }
}

// we could use a trie for the given words in order to skip searching partially
// matched words
class Trie
{
public:
    Trie() = default;
    Trie(char current) : m_current(current) {}

    void
    addWord(const string &word)
    {
        if (word.empty())
            return;

        auto c = word.at(0);

        if (!m_next.count(c))
            m_next.insert({ c, make_shared<Trie>(c) });

        m_next.at(c)->_addWord(word, 1);
    }

    shared_ptr<Trie>
    getNext(char c) const
    {
        auto next = m_next.find(c);
        if (next == m_next.end())
            return {};
        else
            return next->second;
    }

    bool
    search(const string &word)
    {
        if (word.empty())
            return true;

        auto c = word.at(0);

        // check all next
        if (m_next.count(c))
            return m_next.at(c)->_search(word, 1);

        return false;
    }

    char
    getCurrent() const
    {
        return m_current;
    }

    bool
    isBoundary() const
    {
        return m_boundary;
    }

private:
    // whenever we encounter a dot we must split and check all possible next...
    bool
    _search(const string &word, size_t idx)
    {
        if (idx == word.size()) {
            if (m_boundary && word.at(idx - 1) == m_current)
                return true;
            else
                return false;
        }

        auto c = word.at(idx);
        if (m_next.count(c))
            return m_next.at(c)->_search(word, idx + 1);

        return false;
    }

    void
    _addWord(const string &str, size_t idx)
    {
        if (idx == str.size()) {
            m_boundary = true;
            return;
        }

        auto c = str.at(idx);

        if (!m_next.count(c))
            m_next.insert({ c, make_shared<Trie>(c) });

        m_next.at(c)->_addWord(str, idx + 1);
    }

    unordered_map<char, shared_ptr<Trie>> m_next;
    char                                  m_current { 127 };
    bool                                  m_boundary { false };
};

void
dfs(matrix<char>     &board,
    shared_ptr<Trie> &t,
    ssize_t           i,
    ssize_t           j,
    vector<char>     &sol)
{
    if (i < 0 || (size_t)i >= board.size())
        return;

    if (j < 0 || (size_t)j >= board.at(i).size())
        return;

    if (board.at(i).at(j) == '\0')
        return;

    auto currentT = t->getNext(board.at(i).at(j));

    if (!currentT)
        return;

    char temp = '\0';
    swap(board.at(i).at(j), temp);
    sol.push_back(temp);

    dfs(board, currentT, i + 1, j, sol);
    dfs(board, currentT, i - 1, j, sol);
    dfs(board, currentT, i, j + 1, sol);
    dfs(board, currentT, i, j - 1, sol);

    if (currentT->isBoundary())
        cout << "found a solution:'" << string { sol.begin(), sol.end() }
             << "'\n";

    sol.pop_back();
    swap(board.at(i).at(j), temp);
}

// so using a trie we can skip iterations whenever we are already on a
// substring splitting into multiple solutions. although i think that actually
// removing from the trie whenever we encounter a solution would also improve
// the performance
void
secondSol(const vector<string> &words, const matrix<char> &_board)
{
    auto         board = _board;
    auto         t     = make_shared<Trie>();
    vector<char> sol;

    for (auto &w : words)
        t->addWord(w);

    for (size_t i = 0; i < board.size(); ++i) {
        for (size_t j = 0; j < board.at(i).size(); ++j) {
            dfs(board, t, i, j, sol);
        }
    }
}

int
main()
{
    matrix<char> board { { 'o', 'a', 'a', 'n' },
                         { 'e', 't', 'a', 'e' },
                         { 'i', 'h', 'k', 'r' },
                         { 'i', 'f', 'l', 'v' } };

    const vector<string> words { "oath", "pea", "eat", "rain" };

    // firstSol(words, board);
    secondSol(words, board);
}
