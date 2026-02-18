#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <string>
#include <string_view>
#include <utility>

using namespace std;

struct byteorder
{
    static constexpr const union
    {
        uint8_t  byte[2];
        uint16_t bytes;
    } __a { .bytes = 0xAABB };

    static uint64_t
    flip(uint64_t val)
    {
        return val << 56 | (val & 0xFF00) << 40 | (val & 0xFF0000) << 32 |
               (val & 0xFF000000) << 24 | (val >> 56) |
               (val & 0xFF000000000000) >> 40 | (val & 0xFF0000000000) >> 32 |
               (val & 0xFF00000000) >> 24;
    }

    static uint64_t
    to_network(uint64_t val)
    {
        if (__a.byte[0] == 0xAA)
            return val;
        else
            return flip(val);
    }

    static uint64_t
    to_host(uint64_t val)
    {
        if (__a.byte[0] == 0xAA)
            return val;
        else
            return flip(val);
    }
};

class Encoder final
{
    bool owned { false };

    struct _repr
    {
        uint64_t sz;
        uint8_t  buff[0];
    } * repr { nullptr };

public:
    Encoder(const string &s)
    {
        owned    = true;
        repr     = (_repr *)malloc(s.size() + 8);
        repr->sz = byteorder::to_network(s.size());
        copy(s.c_str(), s.c_str() + s.size(), repr->buff);
    };

    Encoder(uint8_t *bytes)
    {
        repr = reinterpret_cast<_repr *>(bytes);
    };

    string_view
    decode() const
    {
        return { (char *)repr->buff, size() - 8 };
    }

    size_t
    size() const
    {
        return byteorder::to_host(repr->sz) + 8;
    }

    void
    copy_to(uint8_t *out)
    {
        copy((uint8_t *)repr, ((uint8_t *)repr) + size(), out);
    }

    ~Encoder()
    {
        if (owned)
            free(repr);
    }

    using chunk = pair<uint8_t *, size_t>;

    static chunk
    encode(const list<string> &vals)
    {
        uint8_t *bytes { nullptr };
        size_t   whence { 0 };

        for (auto &&v : vals) {
            Encoder e(v);
            auto    sz = e.size();
            bytes      = (uint8_t *)realloc(bytes, whence + sz);
            e.copy_to(bytes + whence);
            whence += sz;
        }

        return { bytes, whence };
    }

    static list<string_view>
    decode(const chunk buff)
    {
        auto &&[bytes, sz] = buff;

        if (!bytes)
            return {};

        list<string_view> vals;

        for (size_t whence = 0; whence < sz;) {
            Encoder e(bytes + whence);
            vals.push_back(e.decode());
            whence += e.size();
        }

        return vals;
    }
};

int
main()
{
    auto tuple = Encoder::encode({ "master", "gave", "Doby", "clothes", "!" });
    auto vals  = Encoder::decode(tuple);

    for (auto &&v : vals)
        cout << "'" << v << "' ";

    cout << "\n";

    free(tuple.first);
}
