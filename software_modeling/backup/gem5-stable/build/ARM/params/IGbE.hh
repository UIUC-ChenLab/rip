#ifndef __PARAMS__IGbE__
#define __PARAMS__IGbE__

class IGbE;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/inet.hh"
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
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/EtherDevice.hh"

struct IGbEParams
    : public EtherDeviceParams
{
    IGbE * create();
    Tick fetch_comp_delay;
    Tick fetch_delay;
    Net::EthAddr hardware_address;
    uint16_t phy_epid;
    uint16_t phy_pid;
    int rx_desc_cache_size;
    uint64_t rx_fifo_size;
    Tick rx_write_delay;
    int tx_desc_cache_size;
    uint64_t tx_fifo_size;
    Tick tx_read_delay;
    Tick wb_comp_delay;
    Tick wb_delay;
};

#endif // __PARAMS__IGbE__
