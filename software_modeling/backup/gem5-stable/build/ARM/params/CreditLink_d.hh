#ifndef __PARAMS__CreditLink_d__
#define __PARAMS__CreditLink_d__

class CreditLink_d;


#include "params/NetworkLink_d.hh"

struct CreditLink_dParams
    : public NetworkLink_dParams
{
    CreditLink_d * create();
};

#endif // __PARAMS__CreditLink_d__
