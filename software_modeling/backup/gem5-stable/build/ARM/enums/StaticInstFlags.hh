#ifndef __ENUM__StaticInstFlags__Flags__
#define __ENUM__StaticInstFlags__Flags__

struct StaticInstFlags {
    enum Flags {
        IsNop = 0,
        IsInteger = 1,
        IsFloating = 2,
        IsCC = 3,
        IsMemRef = 4,
        IsLoad = 5,
        IsStore = 6,
        IsStoreConditional = 7,
        IsIndexed = 8,
        IsInstPrefetch = 9,
        IsDataPrefetch = 10,
        IsControl = 11,
        IsDirectControl = 12,
        IsIndirectControl = 13,
        IsCondControl = 14,
        IsUncondControl = 15,
        IsCall = 16,
        IsReturn = 17,
        IsCondDelaySlot = 18,
        IsThreadSync = 19,
        IsSerializing = 20,
        IsSerializeBefore = 21,
        IsSerializeAfter = 22,
        IsMemBarrier = 23,
        IsWriteBarrier = 24,
        IsReadBarrier = 25,
        IsERET = 26,
        IsNonSpeculative = 27,
        IsQuiesce = 28,
        IsIprAccess = 29,
        IsUnverifiable = 30,
        IsSyscall = 31,
        IsMacroop = 32,
        IsMicroop = 33,
        IsDelayedCommit = 34,
        IsLastMicroop = 35,
        IsFirstMicroop = 36,
        IsMicroBranch = 37,
        IsDspOp = 38,
        IsSquashAfter = 39,
        Num_Flags = 40
    };
    static const char *FlagsStrings[Num_Flags];
};

#endif // __ENUM__StaticInstFlags__Flags__
