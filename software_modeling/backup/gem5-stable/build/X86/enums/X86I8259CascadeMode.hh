#ifndef __ENUM__Enums__X86I8259CascadeMode__
#define __ENUM__Enums__X86I8259CascadeMode__

namespace Enums {
    enum X86I8259CascadeMode {
        I8259Master = 0,
        I8259Single = 2,
        I8259Slave = 1,
        Num_X86I8259CascadeMode = 3
    };
extern const char *X86I8259CascadeModeStrings[Num_X86I8259CascadeMode];
}

#endif // __ENUM__Enums__X86I8259CascadeMode__
