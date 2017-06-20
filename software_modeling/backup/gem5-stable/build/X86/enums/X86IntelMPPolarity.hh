#ifndef __ENUM__Enums__X86IntelMPPolarity__
#define __ENUM__Enums__X86IntelMPPolarity__

namespace Enums {
    enum X86IntelMPPolarity {
        ActiveHigh = 1,
        ActiveLow = 3,
        ConformPolarity = 0,
        Num_X86IntelMPPolarity = 3
    };
extern const char *X86IntelMPPolarityStrings[Num_X86IntelMPPolarity];
}

#endif // __ENUM__Enums__X86IntelMPPolarity__
