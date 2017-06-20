#ifndef __PARAMS__System__
#define __PARAMS__System__

class System;

#include <cstddef>
#include <string>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "enums/MemoryMode.hh"
#include <vector>
#include "base/types.hh"
#include "base/addr_range.hh"
#include <vector>
#include "params/AbstractMemory.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>
#include <cstddef>
#include <string>
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

#include "params/MemObject.hh"

#include "enums/MemoryMode.hh"

struct SystemParams
    : public MemObjectParams
{
    System * create();
    std::string boot_osflags;
    unsigned cache_line_size;
    uint64_t init_param;
    std::string kernel;
    bool kernel_addr_check;
    uint64_t load_addr_mask;
    uint64_t load_offset;
    Enums::MemoryMode mem_mode;
    std::vector< AddrRange > mem_ranges;
    std::vector< AbstractMemory * > memories;
    bool mmap_using_noreserve;
    int num_work_ids;
    std::string readfile;
    std::string symbolfile;
    Counter work_begin_ckpt_count;
    int work_begin_cpu_id_exit;
    Counter work_begin_exit_count;
    Counter work_cpus_ckpt_count;
    Counter work_end_ckpt_count;
    Counter work_end_exit_count;
    int work_item_id;
    unsigned int port_system_port_connection_count;
};

#endif // __PARAMS__System__
