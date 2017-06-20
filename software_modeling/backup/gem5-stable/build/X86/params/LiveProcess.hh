#ifndef __PARAMS__LiveProcess__
#define __PARAMS__LiveProcess__

class LiveProcess;

#include <vector>
#include <string>
#include <cstddef>
#include <string>
#include <vector>
#include "params/EmulatedDriver.hh"
#include <cstddef>
#include "base/types.hh"
#include <vector>
#include <string>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/Process.hh"

struct LiveProcessParams
    : public ProcessParams
{
    LiveProcess * create();
    std::vector< std::string > cmd;
    std::string cwd;
    std::vector< EmulatedDriver * > drivers;
    int egid;
    std::vector< std::string > env;
    int euid;
    std::string executable;
    int gid;
    int pid;
    int ppid;
    uint64_t simpoint;
    int uid;
};

#endif // __PARAMS__LiveProcess__
