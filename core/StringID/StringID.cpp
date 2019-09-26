/*

    StringID.cpp
    chickchirick-game-engine

    Created by <chickchirik> on 19/09/2019.

*/

#include "StringID.hpp"

/*  static string lookup table  */
static HashTable<uint32_t, string> gStringTable;

StringID::StringID(uint32_t sid, const char* str) {
    if (gStringTable.count(sid) == 0) {                 /*  StringID checks whether global string       */
        gStringTable[sid] = std::string(str);           /*  table contains the entry and adds if not    */
    }
    id = sid;
    ptr = gStringTable[sid].c_str();
}

uint32_t        StringID::getID()   const   {   return id;                  }
const char*     StringID::getPtr()  const   {   return ptr;                 }
const string&   StringID::getStr()  const   {   return gStringTable[id];    }
