#include <algorithm>
#include <cstddef>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

using namespace std;

// Design a data structure that supports adding new words and finding if a
// string matches any previously added string.

// Implement the WordDictionary class:

// WordDictionary() Initializes the object.

// void addWord(word) Adds word to the data structure, it can be matched
// later.

//  bool search(word) Returns true if there is any string in the data
//  structure that matches word or false otherwise. word may contain dots
//  '.' where dots can be matched with any letter.

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

    bool
    search(const string &word)
    {
        if (word.empty())
            return true;

        auto c = word.at(0);

        // check all next
        if (_is_special(c)) {
            if (word.size() == 1) {
                return any_of(m_next.begin(), m_next.end(), [](auto val) {
                    return val.second->m_boundary;
                });
            }

            return any_of(m_next.begin(), m_next.end(), [&word](auto val) {
                return val.second->_search(word, 1);
            });

        } else if (m_next.count(c))
            return m_next.at(c)->_search(word, 1);

        return false;
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

        if (_is_special(c)) {
            if (word.size() == idx + 1) {
                return any_of(m_next.begin(), m_next.end(), [](auto val) {
                    return val.second->m_boundary;
                });
            }

            return any_of(m_next.begin(), m_next.end(), [&](auto val) {
                return val.second->_search(word, idx + 1);
            });

        } else if (m_next.count(c))
            return m_next.at(c)->_search(word, idx + 1);

        return false;
    }

    bool
    _is_special(char c)
    {
        return c == '.';
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

int
main()
{
    Trie t;
    t.addWord("salut");
    t.addWord("sare");
    t.addWord("salt");
    t.addWord("spock");
    t.addWord("cal");

    // 1111110
    cout << t.search(".al") << t.search("cal") << t.search("c.l")
         << t.search(".al") << t.search(".are") << t.search("..re")
         << t.search(".bre");

    cout << "\n";
}
