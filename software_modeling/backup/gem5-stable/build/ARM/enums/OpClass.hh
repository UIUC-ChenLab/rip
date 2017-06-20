#ifndef __ENUM__Enums__OpClass__
#define __ENUM__Enums__OpClass__

namespace Enums {
    enum OpClass {
        No_OpClass = 0,
        IntAlu = 1,
        IntMult = 2,
        IntDiv = 3,
        FloatAdd = 4,
        FloatCmp = 5,
        FloatCvt = 6,
        FloatMult = 7,
        FloatDiv = 8,
        FloatSqrt = 9,
        SimdAdd = 10,
        SimdAddAcc = 11,
        SimdAlu = 12,
        SimdCmp = 13,
        SimdCvt = 14,
        SimdMisc = 15,
        SimdMult = 16,
        SimdMultAcc = 17,
        SimdShift = 18,
        SimdShiftAcc = 19,
        SimdSqrt = 20,
        SimdFloatAdd = 21,
        SimdFloatAlu = 22,
        SimdFloatCmp = 23,
        SimdFloatCvt = 24,
        SimdFloatDiv = 25,
        SimdFloatMisc = 26,
        SimdFloatMult = 27,
        SimdFloatMultAcc = 28,
        SimdFloatSqrt = 29,
        MemRead = 30,
        MemWrite = 31,
        IprAccess = 32,
        InstPrefetch = 33,
        Num_OpClass = 34
    };
extern const char *OpClassStrings[Num_OpClass];
}

#endif // __ENUM__Enums__OpClass__
