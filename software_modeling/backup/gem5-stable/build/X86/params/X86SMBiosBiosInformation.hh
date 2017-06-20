#ifndef __PARAMS__X86SMBiosBiosInformation__
#define __PARAMS__X86SMBiosBiosInformation__

namespace X86ISA {
namespace SMBios {
class BiosInformation;
} // namespace SMBios
} // namespace X86ISA

#include <vector>
#include "enums/ExtCharacteristic.hh"
#include <vector>
#include "enums/Characteristic.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>
#include <cstddef>
#include <string>

#include "params/X86SMBiosSMBiosStructure.hh"

#include "enums/ExtCharacteristic.hh"

#include "enums/Characteristic.hh"

struct X86SMBiosBiosInformationParams
    : public X86SMBiosSMBiosStructureParams
{
    X86ISA::SMBios::BiosInformation * create();
    std::vector< Enums::ExtCharacteristic > characteristic_ext_bytes;
    std::vector< Enums::Characteristic > characteristics;
    uint8_t emb_cont_firmware_major;
    uint8_t emb_cont_firmware_minor;
    uint8_t major;
    uint8_t minor;
    std::string release_date;
    uint8_t rom_size;
    uint16_t starting_addr_segment;
    std::string vendor;
    std::string version;
};

#endif // __PARAMS__X86SMBiosBiosInformation__
