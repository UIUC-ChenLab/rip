#ifndef __ENUM__Enums__MemoryMode__
#define __ENUM__Enums__MemoryMode__

namespace Enums {
    enum MemoryMode {
        invalid = 0,
        atomic = 1,
        timing = 2,
        atomic_noncaching = 3,
        Num_MemoryMode = 4
    };
extern const char *MemoryModeStrings[Num_MemoryMode];
}

#endif // __ENUM__Enums__MemoryMode__
