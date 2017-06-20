#ifndef __PARAMS__VoltageDomain__
#define __PARAMS__VoltageDomain__

class VoltageDomain;

#include <vector>

#include "params/SimObject.hh"

struct VoltageDomainParams
    : public SimObjectParams
{
    VoltageDomain * create();
    std::vector< double > voltage;
};

#endif // __PARAMS__VoltageDomain__
