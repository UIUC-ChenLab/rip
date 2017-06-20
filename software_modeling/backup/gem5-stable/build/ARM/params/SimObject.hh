#ifndef __PARAMS__SimObject__
#define __PARAMS__SimObject__

class SimObject;

#ifndef PY_VERSION
struct PyObject;
#endif

#include <string>
#include <cstddef>
#include "base/types.hh"

struct SimObjectParams
{
        SimObjectParams() {}
        virtual ~SimObjectParams() {}

        std::string name;
        PyObject *pyobj;
                
    uint32_t eventq_index;
};

#endif // __PARAMS__SimObject__
