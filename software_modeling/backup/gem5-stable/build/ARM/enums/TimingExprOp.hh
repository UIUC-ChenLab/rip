#ifndef __ENUM__Enums__TimingExprOp__
#define __ENUM__Enums__TimingExprOp__

namespace Enums {
    enum TimingExprOp {
        timingExprAdd = 0,
        timingExprSub = 1,
        timingExprUMul = 2,
        timingExprUDiv = 3,
        timingExprSMul = 4,
        timingExprSDiv = 5,
        timingExprUCeilDiv = 6,
        timingExprEqual = 7,
        timingExprNotEqual = 8,
        timingExprULessThan = 9,
        timingExprUGreaterThan = 10,
        timingExprSLessThan = 11,
        timingExprSGreaterThan = 12,
        timingExprInvert = 13,
        timingExprNot = 14,
        timingExprAnd = 15,
        timingExprOr = 16,
        timingExprSizeInBits = 17,
        timingExprSignExtend32To64 = 18,
        timingExprAbs = 19,
        Num_TimingExprOp = 20
    };
extern const char *TimingExprOpStrings[Num_TimingExprOp];
}

#endif // __ENUM__Enums__TimingExprOp__
