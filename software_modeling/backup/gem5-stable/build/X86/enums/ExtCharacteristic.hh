#ifndef __ENUM__Enums__ExtCharacteristic__
#define __ENUM__Enums__ExtCharacteristic__

namespace Enums {
    enum ExtCharacteristic {
        ACPI = 0,
        AGP = 2,
        BootSpec = 8,
        FirewireBoot = 6,
        I20Boot = 3,
        LS_120Boot = 4,
        NetServiceBoot = 9,
        SmartBattery = 7,
        TargetContent = 10,
        USBLegacy = 1,
        ZIPBoot = 5,
        Num_ExtCharacteristic = 11
    };
extern const char *ExtCharacteristicStrings[Num_ExtCharacteristic];
}

#endif // __ENUM__Enums__ExtCharacteristic__
