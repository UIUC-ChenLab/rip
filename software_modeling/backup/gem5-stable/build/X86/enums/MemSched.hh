#ifndef __ENUM__Enums__MemSched__
#define __ENUM__Enums__MemSched__

namespace Enums {
    enum MemSched {
        fcfs = 0,
        frfcfs = 1,
        Num_MemSched = 2
    };
extern const char *MemSchedStrings[Num_MemSched];
}

#endif // __ENUM__Enums__MemSched__
