#ifndef __PARAMS__EtherDevBase__
#define __PARAMS__EtherDevBase__

class EtherDevBase;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/inet.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>

#include "params/EtherDevice.hh"

struct EtherDevBaseParams
    : public EtherDeviceParams
{
    Tick dma_read_delay;
    Tick dma_read_factor;
    Tick dma_write_delay;
    Tick dma_write_factor;
    Net::EthAddr hardware_address;
    Tick intr_delay;
    bool rss;
    Tick rx_delay;
    uint64_t rx_fifo_size;
    bool rx_filter;
    bool rx_thread;
    Tick tx_delay;
    uint64_t tx_fifo_size;
    bool tx_thread;
};

#endif // __PARAMS__EtherDevBase__
