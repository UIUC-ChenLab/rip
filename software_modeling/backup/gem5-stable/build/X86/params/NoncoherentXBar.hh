#ifndef __PARAMS__NoncoherentXBar__
#define __PARAMS__NoncoherentXBar__

class NoncoherentXBar;


#include "params/BaseXBar.hh"

struct NoncoherentXBarParams
    : public BaseXBarParams
{
    NoncoherentXBar * create();
};

#endif // __PARAMS__NoncoherentXBar__
