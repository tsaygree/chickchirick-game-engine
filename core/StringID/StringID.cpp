/*

    StringID.cpp
    chickchirick-game-engine

    Created by <chickchirik> on 19/09/2019.

*/

#include "StringID.hpp"

/*  global string lookup table  */
HashTable<uint32_t, string> gStringTable;

StringID::StringID(uint32_t sid, const char* str) {
    if (gStringTable.count(sid) == 0) {
        gStringTable[sid] = std::string(str);
    } else {
        /*
            ASSERTION DEBUG ONLY. This case may happen when:
            1. string was added twice or more - valid
            2. hash of new string equals to hash of
               already stored string - not valid
            else-statement should be removed in release version
        */
        assert(gStringTable[sid] == string(str));
    }
    id = sid;
    ptr = gStringTable[sid].c_str();
}

uint32_t    StringID::getID()       {   return id;      }
const char* StringID::getPtr()      {   return ptr;     }

uint32_t hashCrc32(const char* str) {
    return ~crc32(str, std::strlen(str));
}
