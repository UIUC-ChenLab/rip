#ifndef __ENUM__Enums__DataDistribution__
#define __ENUM__Enums__DataDistribution__

namespace Enums {
    enum DataDistribution {
        sequential = 0,
        stripe = 1,
        Num_DataDistribution = 2
    };
extern const char *DataDistributionStrings[Num_DataDistribution];
}

#endif // __ENUM__Enums__DataDistribution__
