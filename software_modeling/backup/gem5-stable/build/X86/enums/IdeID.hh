#ifndef __ENUM__Enums__IdeID__
#define __ENUM__Enums__IdeID__

namespace Enums {
    enum IdeID {
        master = 0,
        slave = 1,
        Num_IdeID = 2
    };
extern const char *IdeIDStrings[Num_IdeID];
}

#endif // __ENUM__Enums__IdeID__
