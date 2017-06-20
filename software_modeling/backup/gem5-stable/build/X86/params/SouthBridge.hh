#ifndef __PARAMS__SouthBridge__
#define __PARAMS__SouthBridge__

class SouthBridge;

#include <cstddef>
#include "params/Cmos.hh"
#include <cstddef>
#include "params/I8237.hh"
#include <cstddef>
#include "params/I82094AA.hh"
#include <cstddef>
#include "params/I8042.hh"
#include <cstddef>
#include "params/I8259.hh"
#include <cstddef>
#include "params/I8259.hh"
#include <cstddef>
#include "params/I8254.hh"
#include <cstddef>
#include "params/Platform.hh"
#include <cstddef>
#include "params/PcSpeaker.hh"

#include "params/SimObject.hh"

struct SouthBridgeParams
    : public SimObjectParams
{
    SouthBridge * create();
    X86ISA::Cmos * cmos;
    X86ISA::I8237 * dma1;
    X86ISA::I82094AA * io_apic;
    X86ISA::I8042 * keyboard;
    X86ISA::I8259 * pic1;
    X86ISA::I8259 * pic2;
    X86ISA::I8254 * pit;
    Platform * platform;
    X86ISA::Speaker * speaker;
};

#endif // __PARAMS__SouthBridge__
