#ifndef __PARAMS__EtherDump__
#define __PARAMS__EtherDump__

class EtherDump;

#include <cstddef>
#include <string>
#include <cstddef>
#include "base/types.hh"

#include "params/SimObject.hh"

struct EtherDumpParams
    : public SimObjectParams
{
    EtherDump * create();
    std::string file;
    int maxlen;
};

#endif // __PARAMS__EtherDump__
