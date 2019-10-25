/*

    StringID.cpp
    chickchirick-game-engine

    Created by <chickchirik> on 19/09/2019.

*/

#include "StringID.hpp"

/*  static string lookup table  */
static HashTable<uint32_t, string> gStringTable;

void StringID::registerStr(uint32_t sid, const string& str) {
    if (gStringTable.count(sid) == 0) {                 /*  StringID checks whether global string       */
        gStringTable[sid] = str;                        /*  table contains the entry and adds if not    */
    }
    id = sid;
    ptr = gStringTable[sid].c_str();
}

StringID::StringID(uint32_t sid, const char* str) {
    registerStr(sid, string(str));
}

StringID::StringID(const string& str) {
    registerStr(crc32(str.c_str(), str.length()), str);
}

uint32_t        StringID::getID()   const   {   return id;                  }
const char*     StringID::getPtr()  const   {   return ptr;                 }
const string&   StringID::getStr()  const   {   return gStringTable[id];    }

StringID operator+(const StringID& lhs, const StringID& rhs) {
    string concat = lhs.getStr() + rhs.getStr();
    return StringID(concat);
}
