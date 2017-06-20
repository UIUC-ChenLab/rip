#include "enums/TimingExprOp.hh"
namespace Enums {
     const char *TimingExprOpStrings[Num_TimingExprOp] =
    {
        "timingExprAdd",
        "timingExprSub",
        "timingExprUMul",
        "timingExprUDiv",
        "timingExprSMul",
        "timingExprSDiv",
        "timingExprUCeilDiv",
        "timingExprEqual",
        "timingExprNotEqual",
        "timingExprULessThan",
        "timingExprUGreaterThan",
        "timingExprSLessThan",
        "timingExprSGreaterThan",
        "timingExprInvert",
        "timingExprNot",
        "timingExprAnd",
        "timingExprOr",
        "timingExprSizeInBits",
        "timingExprSignExtend32To64",
        "timingExprAbs",
    };
    } // namespace Enums
