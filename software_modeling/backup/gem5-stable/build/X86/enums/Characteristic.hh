#ifndef __ENUM__Enums__Characteristic__
#define __ENUM__Enums__Characteristic__

namespace Enums {
    enum Characteristic {
        APM = 10,
        CDBoot = 15,
        CGA_Mono = 30,
        EDD = 19,
        EISA = 6,
        ESCD = 14,
        Flash = 11,
        Floppy_3_5_2_88MB = 25,
        Floppy_3_5_720KB = 24,
        Floppy_5_25_1_2MB = 23,
        Floppy_5_25_360KB = 22,
        ISA = 4,
        Keyboard8024 = 27,
        MCA = 5,
        NEC9800 = 20,
        NEC_PC_98 = 31,
        PCI = 7,
        PCMCIA = 8,
        PCMCIABoot = 18,
        PnP = 9,
        PrintScreen = 26,
        Printer = 29,
        SelectBoot = 16,
        Serial = 28,
        Shadow = 12,
        Socketed = 17,
        Toshiba = 21,
        Unknown = 2,
        Unsupported = 3,
        VL_Vesa = 13,
        Num_Characteristic = 30
    };
extern const char *CharacteristicStrings[Num_Characteristic];
}

#endif // __ENUM__Enums__Characteristic__
