#ifndef __PARAMS__Sinic__
#define __PARAMS__Sinic__

namespace Sinic {
class Device;
} // namespace Sinic

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
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/EtherDevBase.hh"

struct SinicParams
    : public EtherDevBaseParams
{
    Sinic::Device * create();
    bool delay_copy;
    uint64_t rx_fifo_low_mark;
    uint64_t rx_fifo_threshold;
    uint64_t rx_max_copy;
    uint32_t rx_max_intr;
    uint64_t tx_fifo_high_mark;
    uint64_t tx_fifo_threshold;
    uint64_t tx_max_copy;
    bool virtual_addr;
    uint32_t virtual_count;
    bool zero_copy;
    uint32_t zero_copy_size;
    uint32_t zero_copy_threshold;
};

#endif // __PARAMS__Sinic__
