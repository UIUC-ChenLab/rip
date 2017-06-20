#ifndef __ENUM__Enums__PageManage__
#define __ENUM__Enums__PageManage__

namespace Enums {
    enum PageManage {
        open = 0,
        open_adaptive = 1,
        close = 2,
        close_adaptive = 3,
        Num_PageManage = 4
    };
extern const char *PageManageStrings[Num_PageManage];
}

#endif // __ENUM__Enums__PageManage__
