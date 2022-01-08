#pragma once

#include <cstdlib>
#include <memory>
#include <ostream>
#include <unordered_map>
#include <utility>
#include <vector>

template<typename T>
class LList
{
public:
    using Next  = std::weak_ptr<LList<T>>;
    using List  = std::vector<T>;
    using Owned = std::shared_ptr<LList<T>>;

    explicit LList(T val) : m_val(val) {}
    LList(T val, Next n) : m_val(val), m_next(n) {}

    static std::pair<std::vector<LList<T>::Owned>, LList<T>::Owned>
    from_list(const LList<T>::List &list)
    {
        if (list.empty())
            return {};

        std::vector<Owned> vals;
        Owned              head;

        for (auto i = list.rbegin(); i != list.rend(); ++i) {
            auto n = std::make_shared<LList<T>>(*i, head);
            vals.push_back(n);
            head = std::move(n);
        }

        return { vals, head };
    }

    T &
    getVal()
    {
        return m_val;
    }

    Next &
    getNext()
    {
        return m_next;
    }

    bool
    operator<(const LList<T> &other) const
    {
        return m_val < other.m_val;
    }

    bool
    operator>(const LList<T> &other) const
    {
        return m_val > other.m_val;
    }

    friend std::ostream &
    operator<<(std::ostream &out, const LList<T>::Owned &head)
    {
        for (auto c = head; c; c = c->m_next.lock())
            out << (c != head ? " -> " : "") << c->m_val;

        return out;
    }

    friend bool
    operator<(const LList<T>::Owned &a, const LList<T>::Owned &b)
    {
        return a->m_val < b->m_val;
    }
    friend bool
    operator>(const LList<T>::Owned &a, const LList<T>::Owned &b)
    {
        return a->m_val > b->m_val;
    }

private:
    T    m_val;
    Next m_next;
};
