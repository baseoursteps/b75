#pragma once

#include <cstddef>
#include <cstdlib>
#include <deque>
#include <optional>

enum class Type
{
    Max,
    Min,
};

template<typename T, Type K>
class Heap
{
public:
    Heap() = default;

    void
    insert(const T &val)
    {
        m_arr.push_front(val);
        psort(0);
    }

    std::optional<T>
    front()
    {
        if (m_arr.empty())
            return {};
        else
            return m_arr.front();
    }

    std::optional<T>
    pop_front()
    {
        std::optional<T> val;
        if (!m_arr.empty()) {
            val = m_arr.front();
            m_arr.pop_front();
            psort(0);
        }

        return val;
    }

    bool
    empty() const
    {
        return size() == 0;
    }

    size_t
    size() const
    {
        return m_arr.size();
    }

private:
    void
    heapify()
    {
        for (ssize_t i = m_arr.size() / 2; i >= 0; --i)
            psort(i);
    }

    void
    psort(std::size_t parent)
    {
        auto lchild = 2 * parent + 1, rchild = 2 * parent + 2;

        auto cmp = [&](std::size_t a, std::size_t b) {
            if (K == Type::Max)
                return m_arr.at(a) <= m_arr.at(b);
            else
                return m_arr.at(a) >= m_arr.at(b);
        };

        auto max = parent;
        if (lchild < m_arr.size() && cmp(max, lchild))
            max = lchild;

        if (rchild < m_arr.size() && cmp(max, rchild))
            max = rchild;

        if (parent != max) {
            std::swap(m_arr.at(parent), m_arr.at(max));
            psort(max);
        }
    }
    std::deque<T> m_arr;
};
