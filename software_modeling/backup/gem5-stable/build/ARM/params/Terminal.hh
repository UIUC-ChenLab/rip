#ifndef __PARAMS__Terminal__
#define __PARAMS__Terminal__

class Terminal;

#include <cstddef>
#include "params/IntrControl.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"

#include "params/SimObject.hh"

struct TerminalParams
    : public SimObjectParams
{
    Terminal * create();
    IntrControl * intr_control;
    int number;
    bool output;
    uint16_t port;
};

#endif // __PARAMS__Terminal__
