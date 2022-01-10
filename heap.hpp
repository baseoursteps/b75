#pragma once

#include <cstddef>
#include <cstdlib>
#include <optional>
#include <ostream>
#include <type_traits>
#include <vector>

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
        m_arr.push_back(val);
        bubble_up(m_arr.size() - 1);
    }

    std::optional<T>
    front() const
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
            // !! careful -- you bubble down after placing the last element at
            // the top for some reason
            std::swap(m_arr.front(), m_arr.back());
            m_arr.pop_back();
            bubble_down(0);
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

    friend std::ostream &
    operator<<(std::ostream &out, const Heap<T, K> &other)
    {
        for (auto &v : other.m_arr)
            out << v << " ";

        return out;
    }

private:
    void
    bubble_up(std::size_t current)
    {
        const auto parent = current / 2;
        const auto cmp    = [&](std::size_t a, std::size_t b) {
            if (K == Type::Max)
                return m_arr.at(a) < m_arr.at(b);
            else
                return m_arr.at(b) < m_arr.at(a);
        };

        auto max = current;
        if (cmp(parent, max))
            max = parent;

        if (max != current) {
            std::swap(m_arr.at(current), m_arr.at(max));
            bubble_up(max);
        }
    }

    void
    bubble_down(std::size_t root)
    {
        const auto lchild = 2 * root + 1, rchild = 2 * root + 2;

        const auto cmp = [&](std::size_t a, std::size_t b) {
            if (K == Type::Max)
                return m_arr.at(a) < m_arr.at(b);
            else
                return m_arr.at(b) < m_arr.at(a);
        };

        auto max = root;
        if (lchild < m_arr.size() && cmp(max, lchild))
            max = lchild;

        if (rchild < m_arr.size() && cmp(max, rchild))
            max = rchild;

        if (root != max) {
            std::swap(m_arr.at(root), m_arr.at(max));
            bubble_down(max);
        }
    }
    std::vector<T> m_arr;
};
