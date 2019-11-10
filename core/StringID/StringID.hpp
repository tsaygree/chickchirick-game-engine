/*

    StringID.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 17/09/2019.

    DESCRIPTION:
    StringID module interns character literals to
    it's hash value by running a crc32B hash function
    on it. All happens at compile time, therefore no
    overhead at runtime.
    This way StringID allows to abstract form using
    strings gaining perfomance boost.
    StringID also registers every string to special
    lookup table, so it is possible to retrieve a
    string later.
    NOTE: This class is not thread safe.

*/

#pragma once
#include <string>
#include <cstring>
#include "HashTable.hpp"
#include "Initializers.hpp"

using std::string;

class StringID {
private:
    uint32_t        id;                         /*  crc32b string id                                */
    const char*     ptr;                        /*  ptr to actual string instance in gStringTable   */
    void registerStr(uint32_t sid, const string& str);
public:
    StringID() = default;
    StringID(uint32_t sid, const char* str);
    StringID(const string& str);
    inline bool operator==(const StringID& other) const { return id == other.getID(); }
    inline bool operator!=(const StringID& other) const { return id != other.getID(); }
    uint32_t      getID()  const;
    const char*   getPtr() const;
    const string& getStr() const;
};

StringID operator+(const StringID& lhs, const StringID& rhs);

/*  user defined StringID hash function for HashTable   */
class SIDHashFunc {
public:
    /*  just return string id because it is a hash of string    */
    size_t operator()(const StringID& sid) const { return sid.getID();  }
};

/*  SIDTable is a hash table where StringID is a key and    */
/*  template type is a value                                */
template <typename V>
using SIDTable = std::unordered_map<StringID, V, SIDHashFunc>;

/*  cimpile time function that calculates crc32b                            */
constexpr uint32_t crc32(const char* data, size_t length);
/*  user string literal to calculate hash on a string at compile time       */
constexpr uint32_t operator"" _sid(const char* str, size_t length);
/*  macro to create StringID instance from a simple string literal          */
    /*  compile time    */
#define SID(str) StringID(str##_sid, str)
    /*  runtime         */
#define SHID(sptr) StringID(crc32(sptr, std::strlen(sptr)), sptr)

/*  lookup table for crc32b hash calculation                                */
const constexpr uint32_t crc32Table[256] = CRC32LOOKUPVALUES;

/*  cimpile time function that calculates crc32b                            */
constexpr uint32_t crc32(const char* data, size_t length) {
    uint32_t remainder = 0xFFFFFFFFU;
    while (length) {
        remainder = crc32Table[(remainder & 0xFF) ^ *data++] ^ (remainder >> 8);
        length--;
    }
    return ~remainder;
}

/*  user string literal to calculate hash on a string at compile time       */
constexpr uint32_t operator"" _sid(const char* str, size_t length) {
    return crc32(str, length);
}
