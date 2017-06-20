#ifndef __PARAMS__Process__
#define __PARAMS__Process__

class Process;

#include <cstddef>
#include <string>
#include <cstddef>
#include <string>
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>
#include <cstddef>
#include "params/System.hh"
#include <cstddef>

#include "params/SimObject.hh"

struct ProcessParams
    : public SimObjectParams
{
    std::string errout;
    std::string input;
    bool kvmInSE;
    uint64_t max_stack_size;
    std::string output;
    System * system;
    bool useArchPT;
};

#endif // __PARAMS__Process__
