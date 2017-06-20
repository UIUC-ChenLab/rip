#ifndef __PARAMS__LinuxX86System__
#define __PARAMS__LinuxX86System__

class LinuxX86System;

#include <cstddef>
#include "params/X86E820Table.hh"

#include "params/X86System.hh"

struct LinuxX86SystemParams
    : public X86SystemParams
{
    LinuxX86System * create();
    X86ISA::E820Table * e820_table;
};

#endif // __PARAMS__LinuxX86System__
