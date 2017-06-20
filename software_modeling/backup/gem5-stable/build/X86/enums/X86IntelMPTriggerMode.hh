#ifndef __ENUM__Enums__X86IntelMPTriggerMode__
#define __ENUM__Enums__X86IntelMPTriggerMode__

namespace Enums {
    enum X86IntelMPTriggerMode {
        ConformTrigger = 0,
        EdgeTrigger = 1,
        LevelTrigger = 3,
        Num_X86IntelMPTriggerMode = 3
    };
extern const char *X86IntelMPTriggerModeStrings[Num_X86IntelMPTriggerMode];
}

#endif // __ENUM__Enums__X86IntelMPTriggerMode__
