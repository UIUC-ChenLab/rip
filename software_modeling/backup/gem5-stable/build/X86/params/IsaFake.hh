#ifndef __PARAMS__IsaFake__
#define __PARAMS__IsaFake__

class IsaFake;

#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include <string>

#include "params/BasicPioDevice.hh"

struct IsaFakeParams
    : public BasicPioDeviceParams
{
    IsaFake * create();
    bool fake_mem;
    Addr pio_size;
    bool ret_bad_addr;
    uint16_t ret_data16;
    uint32_t ret_data32;
    uint64_t ret_data64;
    uint8_t ret_data8;
    bool update_data;
    std::string warn_access;
};

#endif // __PARAMS__IsaFake__
