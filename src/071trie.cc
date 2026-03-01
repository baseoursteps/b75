#include <array>
#include <iostream>
#include <string>
#include <string_view>

using namespace std;

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

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

struct Node
{
    array<Node *, 26> next {};
    bool              word {};

    ~Node()
    {
        for (auto n : next) {
            delete n;
        }
    }

    void
    insert(string_view sv)
    {
        auto  current = sv.front();
        auto  rest    = sv.substr(1);
        auto  idx     = current - 'a';
        auto &trie    = next[idx];
        if (!trie) {
            trie = new Node;
        }

        if (rest.empty()) {
            trie->word = true;
        } else {
            trie->insert(rest);
        }
    }

    bool
    search(string_view sv, bool full)
    {
        if (sv.empty()) {
            return true;
        }

        auto current = sv.front();
        auto rest    = sv.substr(1);

        auto  idx  = current - 'a';
        auto &trie = next[idx];
        if (!trie) {
            return false;
        } else {
            if (rest.empty() && full) {
                return trie->word;
            }
            return trie->search(rest, full);
        }
    }
};

class Trie
{
private:
    Node *n {};

public:
    Trie() {}
    ~Trie()
    {
        delete n;
    }

    void
    insert(string word)
    {
        if (!n) {
            n = new Node;
        }
        n->insert(word);
    }

    bool
    search(string word, bool full = true)
    {
        if (!n) {
            return false;
        } else {
            return n->search(word, full);
        }
    }

    bool
    startsWith(string prefix)
    {
        return search(prefix, false);
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
