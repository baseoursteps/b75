#include <cstddef>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

// A trie (pronounced as "try") or prefix tree is a tree data structure used to
// efficiently store and retrieve keys in a dataset of strings. There are
// various applications of this data structure, such as autocomplete and
// spellchecker.

// Implement the Trie class:

// - Trie() Initializes the trie object.

// - void insert(String word) Inserts the string word into the trie.

// - boolean search(String word) Returns true if the string word is in the
//  trie (i.e., was inserted before), and false otherwise. boolean

// - startsWith(String prefix) Returns true if there is a previously inserted
//  string word that has the prefix prefix, and false otherwise.

using namespace std;

struct Trie
{
    vector<shared_ptr<Trie>> m_next;
    char                     m_current { 127 };
    bool                     boundary { false };

    Trie()
    {
        m_next.resize(26);
    }
    explicit Trie(char c) : m_current(c)
    {
        m_next.resize(26);
    }

    void
    insert(const string &word)
    {
        if (word.empty())
            return;

        auto first = word.at(0);

        auto &next = m_next.at(first - 'a');

        if (!next)
            next = make_shared<Trie>(first);

        next->_insert(word, 1);
    }

    bool
    search(const string &other) const
    {
        if (other.empty())
            return true;

        auto next = m_next.at(other.at(0) - 'a');
        if (next)
            return next->_search(other, 1, true);
        else
            return false;
    }

    bool
    startsWith(const string &prefix) const
    {
        if (prefix.empty())
            return true;

        auto next = m_next.at(prefix.at(0) - 'a');
        if (next)
            return next->_search(prefix, 1, false);
        else
            return false;
    }

private:
    bool
    _search(const string &part, size_t idx, bool full)
    {
        if (idx == part.size()) {
            if (part.at(idx - 1) == m_current) {
                if ((full && boundary) || !full)
                    return true;
                else
                    return false;
            } else
                return false;
        } else {
            auto next = m_next.at(part.at(idx) - 'a');
            if (next)
                return next->_search(part, idx + 1, full);
            else
                return false;
        }
    }

    void
    _insert(const string &part, size_t idx)
    {
        auto c = part.at(idx);

        auto &next = m_next.at(c - 'a');
        if (!next)
            next = make_shared<Trie>(c);

        if (idx + 1 == part.size()) {
            next->boundary = true;
            return;
        } else {
            next->_insert(part, idx + 1);
        }
    }
};

int
main()
{
    Trie t;
    t.insert("apple");
    cout << t.search("apple");   // true
    cout << t.search("app");     // false
    cout << t.startsWith("app"); // true
    t.insert("app");
    cout << t.search("apple"); // true
    cout << "\n";
    // 1011
}
