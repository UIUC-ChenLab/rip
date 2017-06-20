# Copyright (c) 2009-2015 ARM Limited
# All rights reserved.
#
# The license below extends only to copyright in the software and shall
# not be construed as granting a license to any other intellectual
# property including but not limited to intellectual property relating
# to a hardware implementation of the functionality of the software
# licensed hereunder.  You may use the software subject to the license
# terms below provided that you ensure that this notice is replicated
# unmodified and in its entirety in all distributions of the software,
# modified or unmodified, in source code or in binary form.
#
# Copyright (c) 2006-2007 The Regents of The University of Michigan
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met: redistributions of source code must retain the above copyright
# notice, this list of conditions and the following disclaimer;
# redistributions in binary form must reproduce the above copyright
# notice, this list of conditions and the following disclaimer in the
# documentation and/or other materials provided with the distribution;
# neither the name of the copyright holders nor the names of its
# contributors may be used to endorse or promote products derived from
# this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# Authors: Ali Saidi
#          Gabe Black
#          William Wang

from m5.params import *
from m5.proxy import *
from Device import BasicPioDevice, PioDevice, IsaFake, BadAddr, DmaDevice
from Pci import PciConfigAll
from Ethernet import NSGigE, IGbE_igb, IGbE_e1000
from Ide import *
from Platform import Platform
from Terminal import Terminal
from Uart import Uart
from SimpleMemory import SimpleMemory
from Gic import *
from EnergyCtrl import EnergyCtrl

class AmbaPioDevice(BasicPioDevice):
    type = 'AmbaPioDevice'
    abstract = True
    cxx_header = "dev/arm/amba_device.hh"
    amba_id = Param.UInt32("ID of AMBA device for kernel detection")

class AmbaIntDevice(AmbaPioDevice):
    type = 'AmbaIntDevice'
    abstract = True
    cxx_header = "dev/arm/amba_device.hh"
    gic = Param.BaseGic(Parent.any, "Gic to use for interrupting")
    int_num = Param.UInt32("Interrupt number that connects to GIC")
    int_delay = Param.Latency("100ns",
            "Time between action and interrupt generation by device")

class AmbaDmaDevice(DmaDevice):
    type = 'AmbaDmaDevice'
    abstract = True
    cxx_header = "dev/arm/amba_device.hh"
    pio_addr = Param.Addr("Address for AMBA slave interface")
    pio_latency = Param.Latency("10ns", "Time between action and write/read result by AMBA DMA Device")
    gic = Param.BaseGic(Parent.any, "Gic to use for interrupting")
    int_num = Param.UInt32("Interrupt number that connects to GIC")
    amba_id = Param.UInt32("ID of AMBA device for kernel detection")

class A9SCU(BasicPioDevice):
    type = 'A9SCU'
    cxx_header = "dev/arm/a9scu.hh"

class RealViewCtrl(BasicPioDevice):
    type = 'RealViewCtrl'
    cxx_header = "dev/arm/rv_ctrl.hh"
    proc_id0 = Param.UInt32(0x0C000000, "Processor ID, SYS_PROCID")
    proc_id1 = Param.UInt32(0x0C000222, "Processor ID, SYS_PROCID1")
    idreg = Param.UInt32(0x00000000, "ID Register, SYS_ID")

class VGic(PioDevice):
    type = 'VGic'
    cxx_header = "dev/arm/vgic.hh"
    gic = Param.BaseGic(Parent.any, "Gic to use for interrupting")
    platform = Param.Platform(Parent.any, "Platform this device is part of.")
    vcpu_addr = Param.Addr(0, "Address for vcpu interfaces")
    hv_addr = Param.Addr(0, "Address for hv control")
    pio_delay = Param.Latency('10ns', "Delay for PIO r/w")
   # The number of list registers is not currently configurable at runtime.
    ppint = Param.UInt32("HV maintenance interrupt number")

class AmbaFake(AmbaPioDevice):
    type = 'AmbaFake'
    cxx_header = "dev/arm/amba_fake.hh"
    ignore_access = Param.Bool(False, "Ignore reads/writes to this device, (e.g. IsaFake + AMBA)")
    amba_id = 0;

class Pl011(Uart):
    type = 'Pl011'
    cxx_header = "dev/arm/pl011.hh"
    gic = Param.BaseGic(Parent.any, "Gic to use for interrupting")
    int_num = Param.UInt32("Interrupt number that connects to GIC")
    end_on_eot = Param.Bool(False, "End the simulation when a EOT is received on the UART")
    int_delay = Param.Latency("100ns", "Time between action and interrupt generation by UART")

class Sp804(AmbaPioDevice):
    type = 'Sp804'
    cxx_header = "dev/arm/timer_sp804.hh"
    gic = Param.BaseGic(Parent.any, "Gic to use for interrupting")
    int_num0 = Param.UInt32("Interrupt number that connects to GIC")
    clock0 = Param.Clock('1MHz', "Clock speed of the input")
    int_num1 = Param.UInt32("Interrupt number that connects to GIC")
    clock1 = Param.Clock('1MHz', "Clock speed of the input")
    amba_id = 0x00141804

class CpuLocalTimer(BasicPioDevice):
    type = 'CpuLocalTimer'
    cxx_header = "dev/arm/timer_cpulocal.hh"
    gic = Param.BaseGic(Parent.any, "Gic to use for interrupting")
    int_num_timer = Param.UInt32("Interrrupt number used per-cpu to GIC")
    int_num_watchdog = Param.UInt32("Interrupt number for per-cpu watchdog to GIC")

class GenericTimer(SimObject):
    type = 'GenericTimer'
    cxx_header = "dev/arm/generic_timer.hh"
    system = Param.System(Parent.any, "system")
    gic = Param.BaseGic(Parent.any, "GIC to use for interrupting")
    # @todo: for now only two timers per CPU is supported, which is the
    # normal behaviour when security extensions are disabled.
    int_phys = Param.UInt32("Physical timer interrupt number")
    int_virt = Param.UInt32("Virtual timer interrupt number")

class GenericTimerMem(PioDevice):
    type = 'GenericTimerMem'
    cxx_header = "dev/arm/generic_timer.hh"
    gic = Param.BaseGic(Parent.any, "GIC to use for interrupting")

    base = Param.Addr(0, "Base address")

    int_phys = Param.UInt32("Interrupt number")
    int_virt = Param.UInt32("Interrupt number")

class PL031(AmbaIntDevice):
    type = 'PL031'
    cxx_header = "dev/arm/rtc_pl031.hh"
    time = Param.Time('01/01/2009', "System time to use ('Now' for actual time)")
    amba_id = 0x00341031

class Pl050(AmbaIntDevice):
    type = 'Pl050'
    cxx_header = "dev/arm/kmi.hh"
    vnc = Param.VncInput(Parent.any, "Vnc server for remote frame buffer display")
    is_mouse = Param.Bool(False, "Is this interface a mouse, if not a keyboard")
    int_delay = '1us'
    amba_id = 0x00141050

class Pl111(AmbaDmaDevice):
    type = 'Pl111'
    cxx_header = "dev/arm/pl111.hh"
    pixel_clock = Param.Clock('24MHz', "Pixel clock")
    vnc   = Param.VncInput(Parent.any, "Vnc server for remote frame buffer display")
    amba_id = 0x00141111
    enable_capture = Param.Bool(True, "capture frame to system.framebuffer.bmp")


class HDLcd(AmbaDmaDevice):
    type = 'HDLcd'
    cxx_header = "dev/arm/hdlcd.hh"
    # For reference, 1024x768MR-16@60  ~= 56 MHz
    #                1920x1080MR-16@60 ~= 137 MHz
    #                3840x2160MR-16@60 ~= 533 MHz
    # Match against the resolution selected in the Linux DTS/DTB file.
    pixel_clock = Param.Clock('137MHz', "Clock frequency of the pixel clock "
                                        "(i.e. PXLREFCLK / OSCCLK 5")
    vnc = Param.VncInput(Parent.any, "Vnc server for remote frame buffer "
                                     "display")
    amba_id = 0x00141000
    workaround_swap_rb = Param.Bool(True, "Workaround incorrect color "
                                    "selector order in some kernels")
    enable_capture = Param.Bool(True, "capture frame to system.framebuffer.bmp")

class RealView(Platform):
    type = 'RealView'
    cxx_header = "dev/arm/realview.hh"
    system = Param.System(Parent.any, "system")
    pci_io_base = Param.Addr(0, "Base address of PCI IO Space")
    pci_cfg_base = Param.Addr(0, "Base address of PCI Configuraiton Space")
    pci_cfg_gen_offsets = Param.Bool(False, "Should the offsets used for PCI cfg access"
            " be compatible with the pci-generic-host or the legacy host bridge?")
    _mem_regions = [(Addr(0), Addr('256MB'))]

    def attachPciDevices(self):
        pass

    def enableMSIX(self):
        pass

    def onChipIOClkDomain(self, clkdomain):
        pass

    def offChipIOClkDomain(self, clkdomain):
        pass

    def setupBootLoader(self, mem_bus, cur_sys, loc):
        self.nvmem = SimpleMemory(range = AddrRange('2GB', size = '64MB'),
                                  conf_table_reported = False)
        self.nvmem.port = mem_bus.master
        cur_sys.boot_loader = loc('boot.arm')
        cur_sys.atags_addr = 0x100
        cur_sys.load_addr_mask = 0xfffffff
        cur_sys.load_offset = 0


# Reference for memory map and interrupt number
# RealView Platform Baseboard Explore for Cortex-A9 User Guide(ARM DUI 0440A)
# Chapter 4: Programmer's Reference
class RealViewPBX(RealView):
    uart = Pl011(pio_addr=0x10009000, int_num=44)
    realview_io = RealViewCtrl(pio_addr=0x10000000)
    gic = Pl390()
    timer0 = Sp804(int_num0=36, int_num1=36, pio_addr=0x10011000)
    timer1 = Sp804(int_num0=37, int_num1=37, pio_addr=0x10012000)
    local_cpu_timer = CpuLocalTimer(int_num_timer=29, int_num_watchdog=30, pio_addr=0x1f000600)
    clcd = Pl111(pio_addr=0x10020000, int_num=55)
    kmi0   = Pl050(pio_addr=0x10006000, int_num=52)
    kmi1   = Pl050(pio_addr=0x10007000, int_num=53, is_mouse=True)
    a9scu  = A9SCU(pio_addr=0x1f000000)
    cf_ctrl = IdeController(disks=[], pci_func=0, pci_dev=7, pci_bus=2,
                            io_shift = 1, ctrl_offset = 2, Command = 0x1,
                            BAR0 = 0x18000000, BAR0Size = '16B',
                            BAR1 = 0x18000100, BAR1Size = '1B',
                            BAR0LegacyIO = True, BAR1LegacyIO = True)


    l2x0_fake     = IsaFake(pio_addr=0x1f002000, pio_size=0xfff)
    flash_fake    = IsaFake(pio_addr=0x40000000, pio_size=0x20000000,
                            fake_mem=True)
    dmac_fake     = AmbaFake(pio_addr=0x10030000)
    uart1_fake    = AmbaFake(pio_addr=0x1000a000)
    uart2_fake    = AmbaFake(pio_addr=0x1000b000)
    uart3_fake    = AmbaFake(pio_addr=0x1000c000)
    smc_fake      = AmbaFake(pio_addr=0x100e1000)
    sp810_fake    = AmbaFake(pio_addr=0x10001000, ignore_access=True)
    watchdog_fake = AmbaFake(pio_addr=0x10010000)
    gpio0_fake    = AmbaFake(pio_addr=0x10013000)
    gpio1_fake    = AmbaFake(pio_addr=0x10014000)
    gpio2_fake    = AmbaFake(pio_addr=0x10015000)
    ssp_fake      = AmbaFake(pio_addr=0x1000d000)
    sci_fake      = AmbaFake(pio_addr=0x1000e000)
    aaci_fake     = AmbaFake(pio_addr=0x10004000)
    mmc_fake      = AmbaFake(pio_addr=0x10005000)
    rtc           = PL031(pio_addr=0x10017000, int_num=42)
    energy_ctrl   = EnergyCtrl(pio_addr=0x1000f000)


    # Attach I/O devices that are on chip and also set the appropriate
    # ranges for the bridge
    def attachOnChipIO(self, bus, bridge):
       self.gic.pio = bus.master
       self.l2x0_fake.pio = bus.master
       self.a9scu.pio = bus.master
       self.local_cpu_timer.pio = bus.master
       # Bridge ranges based on excluding what is part of on-chip I/O
       # (gic, l2x0, a9scu, local_cpu_timer)
       bridge.ranges = [AddrRange(self.realview_io.pio_addr,
                                  self.a9scu.pio_addr - 1),
                        AddrRange(self.flash_fake.pio_addr,
                                  self.flash_fake.pio_addr + \
                                  self.flash_fake.pio_size - 1)]

    # Set the clock domain for IO objects that are considered
    # to be "close" to the cores.
    def onChipIOClkDomain(self, clkdomain):
        self.gic.clk_domain             = clkdomain
        self.l2x0_fake.clk_domain       = clkdomain
        self.a9scu.clkdomain            = clkdomain
        self.local_cpu_timer.clk_domain = clkdomain

    # Attach I/O devices to specified bus object.  Can't do this
    # earlier, since the bus object itself is typically defined at the
    # System level.
    def attachIO(self, bus):
       self.uart.pio          = bus.master
       self.realview_io.pio   = bus.master
       self.timer0.pio        = bus.master
       self.timer1.pio        = bus.master
       self.clcd.pio          = bus.master
       self.clcd.dma          = bus.slave
       self.kmi0.pio          = bus.master
       self.kmi1.pio          = bus.master
       self.cf_ctrl.pio       = bus.master
       self.cf_ctrl.config    = bus.master
       self.cf_ctrl.dma       = bus.slave
       self.dmac_fake.pio     = bus.master
       self.uart1_fake.pio    = bus.master
       self.uart2_fake.pio    = bus.master
       self.uart3_fake.pio    = bus.master
       self.smc_fake.pio      = bus.master
       self.sp810_fake.pio    = bus.master
       self.watchdog_fake.pio = bus.master
       self.gpio0_fake.pio    = bus.master
       self.gpio1_fake.pio    = bus.master
       self.gpio2_fake.pio    = bus.master
       self.ssp_fake.pio      = bus.master
       self.sci_fake.pio      = bus.master
       self.aaci_fake.pio     = bus.master
       self.mmc_fake.pio      = bus.master
       self.rtc.pio           = bus.master
       self.flash_fake.pio    = bus.master
       self.energy_ctrl.pio   = bus.master

    # Set the clock domain for IO objects that are considered
    # to be "far" away from the cores.
    def offChipIOClkDomain(self, clkdomain):
        self.uart.clk_domain          = clkdomain
        self.realview_io.clk_domain   = clkdomain
        self.timer0.clk_domain        = clkdomain
        self.timer1.clk_domain        = clkdomain
        self.clcd.clk_domain          = clkdomain
        self.kmi0.clk_domain          = clkdomain
        self.kmi1.clk_domain          = clkdomain
        self.cf_ctrl.clk_domain       = clkdomain
        self.dmac_fake.clk_domain     = clkdomain
        self.uart1_fake.clk_domain    = clkdomain
        self.uart2_fake.clk_domain    = clkdomain
        self.uart3_fake.clk_domain    = clkdomain
        self.smc_fake.clk_domain      = clkdomain
        self.sp810_fake.clk_domain    = clkdomain
        self.watchdog_fake.clk_domain = clkdomain
        self.gpio0_fake.clk_domain    = clkdomain
        self.gpio1_fake.clk_domain    = clkdomain
        self.gpio2_fake.clk_domain    = clkdomain
        self.ssp_fake.clk_domain      = clkdomain
        self.sci_fake.clk_domain      = clkdomain
        self.aaci_fake.clk_domain     = clkdomain
        self.mmc_fake.clk_domain      = clkdomain
        self.rtc.clk_domain           = clkdomain
        self.flash_fake.clk_domain    = clkdomain
        self.energy_ctrl.clk_domain   = clkdomain

# Reference for memory map and interrupt number
# RealView Emulation Baseboard User Guide (ARM DUI 0143B)
# Chapter 4: Programmer's Reference
class RealViewEB(RealView):
    uart = Pl011(pio_addr=0x10009000, int_num=44)
    realview_io = RealViewCtrl(pio_addr=0x10000000, idreg=0x01400500)
    gic = Pl390(dist_addr=0x10041000, cpu_addr=0x10040000)
    timer0 = Sp804(int_num0=36, int_num1=36, pio_addr=0x10011000)
    timer1 = Sp804(int_num0=37, int_num1=37, pio_addr=0x10012000)
    clcd   = Pl111(pio_addr=0x10020000, int_num=23)
    kmi0   = Pl050(pio_addr=0x10006000, int_num=20)
    kmi1   = Pl050(pio_addr=0x10007000, int_num=21, is_mouse=True)

    l2x0_fake     = IsaFake(pio_addr=0x1f002000, pio_size=0xfff, warn_access="1")
    flash_fake    = IsaFake(pio_addr=0x40000000, pio_size=0x20000000-1,
                            fake_mem=True)
    dmac_fake     = AmbaFake(pio_addr=0x10030000)
    uart1_fake    = AmbaFake(pio_addr=0x1000a000)
    uart2_fake    = AmbaFake(pio_addr=0x1000b000)
    uart3_fake    = AmbaFake(pio_addr=0x1000c000)
    smcreg_fake   = IsaFake(pio_addr=0x10080000, pio_size=0x10000-1)
    smc_fake      = AmbaFake(pio_addr=0x100e1000)
    sp810_fake    = AmbaFake(pio_addr=0x10001000, ignore_access=True)
    watchdog_fake = AmbaFake(pio_addr=0x10010000)
    gpio0_fake    = AmbaFake(pio_addr=0x10013000)
    gpio1_fake    = AmbaFake(pio_addr=0x10014000)
    gpio2_fake    = AmbaFake(pio_addr=0x10015000)
    ssp_fake      = AmbaFake(pio_addr=0x1000d000)
    sci_fake      = AmbaFake(pio_addr=0x1000e000)
    aaci_fake     = AmbaFake(pio_addr=0x10004000)
    mmc_fake      = AmbaFake(pio_addr=0x10005000)
    rtc_fake      = AmbaFake(pio_addr=0x10017000, amba_id=0x41031)
    energy_ctrl   = EnergyCtrl(pio_addr=0x1000f000)

    # Attach I/O devices that are on chip and also set the appropriate
    # ranges for the bridge
    def attachOnChipIO(self, bus, bridge):
       self.gic.pio = bus.master
       self.l2x0_fake.pio = bus.master
       # Bridge ranges based on excluding what is part of on-chip I/O
       # (gic, l2x0)
       bridge.ranges = [AddrRange(self.realview_io.pio_addr,
                                  self.gic.cpu_addr - 1),
                        AddrRange(self.flash_fake.pio_addr, Addr.max)]

    # Set the clock domain for IO objects that are considered
    # to be "close" to the cores.
    def onChipIOClkDomain(self, clkdomain):
        self.gic.clk_domain             = clkdomain
        self.l2x0_fake.clk_domain       = clkdomain

    # Attach I/O devices to specified bus object.  Can't do this
    # earlier, since the bus object itself is typically defined at the
    # System level.
    def attachIO(self, bus):
       self.uart.pio          = bus.master
       self.realview_io.pio   = bus.master
       self.timer0.pio        = bus.master
       self.timer1.pio        = bus.master
       self.clcd.pio          = bus.master
       self.clcd.dma          = bus.slave
       self.kmi0.pio          = bus.master
       self.kmi1.pio          = bus.master
       self.dmac_fake.pio     = bus.master
       self.uart1_fake.pio    = bus.master
       self.uart2_fake.pio    = bus.master
       self.uart3_fake.pio    = bus.master
       self.smc_fake.pio      = bus.master
       self.sp810_fake.pio    = bus.master
       self.watchdog_fake.pio = bus.master
       self.gpio0_fake.pio    = bus.master
       self.gpio1_fake.pio    = bus.master
       self.gpio2_fake.pio    = bus.master
       self.ssp_fake.pio      = bus.master
       self.sci_fake.pio      = bus.master
       self.aaci_fake.pio     = bus.master
       self.mmc_fake.pio      = bus.master
       self.rtc_fake.pio      = bus.master
       self.flash_fake.pio    = bus.master
       self.smcreg_fake.pio   = bus.master
       self.energy_ctrl.pio   = bus.master

    # Set the clock domain for IO objects that are considered
    # to be "far" away from the cores.
    def offChipIOClkDomain(self, clkdomain):
        self.uart.clk_domain          = clkdomain
        self.realview_io.clk_domain   = clkdomain
        self.timer0.clk_domain        = clkdomain
        self.timer1.clk_domain        = clkdomain
        self.clcd.clk_domain          = clkdomain
        self.kmi0.clk_domain          = clkdomain
        self.kmi1.clk_domain          = clkdomain
        self.dmac_fake.clk_domain     = clkdomain
        self.uart1_fake.clk_domain    = clkdomain
        self.uart2_fake.clk_domain    = clkdomain
        self.uart3_fake.clk_domain    = clkdomain
        self.smc_fake.clk_domain      = clkdomain
        self.sp810_fake.clk_domain    = clkdomain
        self.watchdog_fake.clk_domain = clkdomain
        self.gpio0_fake.clk_domain    = clkdomain
        self.gpio1_fake.clk_domain    = clkdomain
        self.gpio2_fake.clk_domain    = clkdomain
        self.ssp_fake.clk_domain      = clkdomain
        self.sci_fake.clk_domain      = clkdomain
        self.aaci_fake.clk_domain     = clkdomain
        self.mmc_fake.clk_domain      = clkdomain
        self.rtc.clk_domain           = clkdomain
        self.flash_fake.clk_domain    = clkdomain
        self.smcreg_fake.clk_domain   = clkdomain
        self.energy_ctrl.clk_domain   = clkdomain

class VExpress_EMM(RealView):
    _mem_regions = [(Addr('2GB'), Addr('2GB'))]
    pci_cfg_base = 0x30000000
    uart = Pl011(pio_addr=0x1c090000, int_num=37)
    realview_io = RealViewCtrl(proc_id0=0x14000000, proc_id1=0x14000000, \
                               idreg=0x02250000, pio_addr=0x1C010000)
    gic = Pl390(dist_addr=0x2C001000, cpu_addr=0x2C002000)
    local_cpu_timer = CpuLocalTimer(int_num_timer=29, int_num_watchdog=30, pio_addr=0x2C080000)
    generic_timer = GenericTimer(int_phys=29, int_virt=27)
    timer0 = Sp804(int_num0=34, int_num1=34, pio_addr=0x1C110000, clock0='1MHz', clock1='1MHz')
    timer1 = Sp804(int_num0=35, int_num1=35, pio_addr=0x1C120000, clock0='1MHz', clock1='1MHz')
    clcd   = Pl111(pio_addr=0x1c1f0000, int_num=46)
    hdlcd  = HDLcd(pio_addr=0x2b000000, int_num=117)
    kmi0   = Pl050(pio_addr=0x1c060000, int_num=44)
    kmi1   = Pl050(pio_addr=0x1c070000, int_num=45, is_mouse=True)
    vgic   = VGic(vcpu_addr=0x2c006000, hv_addr=0x2c004000, ppint=25)
    cf_ctrl = IdeController(disks=[], pci_func=0, pci_dev=0, pci_bus=2,
                            io_shift = 2, ctrl_offset = 2, Command = 0x1,
                            BAR0 = 0x1C1A0000, BAR0Size = '256B',
                            BAR1 = 0x1C1A0100, BAR1Size = '4096B',
                            BAR0LegacyIO = True, BAR1LegacyIO = True)

    pciconfig = PciConfigAll(size='256MB')
    vram           = SimpleMemory(range = AddrRange(0x18000000, size='32MB'),
                                  conf_table_reported = False)
    rtc            = PL031(pio_addr=0x1C170000, int_num=36)

    l2x0_fake      = IsaFake(pio_addr=0x2C100000, pio_size=0xfff)
    uart1_fake     = AmbaFake(pio_addr=0x1C0A0000)
    uart2_fake     = AmbaFake(pio_addr=0x1C0B0000)
    uart3_fake     = AmbaFake(pio_addr=0x1C0C0000)
    sp810_fake     = AmbaFake(pio_addr=0x1C020000, ignore_access=True)
    watchdog_fake  = AmbaFake(pio_addr=0x1C0F0000)
    aaci_fake      = AmbaFake(pio_addr=0x1C040000)
    lan_fake       = IsaFake(pio_addr=0x1A000000, pio_size=0xffff)
    usb_fake       = IsaFake(pio_addr=0x1B000000, pio_size=0x1ffff)
    mmc_fake       = AmbaFake(pio_addr=0x1c050000)
    energy_ctrl    = EnergyCtrl(pio_addr=0x1c080000)

    # Attach any PCI devices that are supported
    def attachPciDevices(self):
        self.ethernet = IGbE_e1000(pci_bus=0, pci_dev=0, pci_func=0,
                                   InterruptLine=1, InterruptPin=1)
        self.ide = IdeController(disks = [], pci_bus=0, pci_dev=1, pci_func=0,
                                 InterruptLine=2, InterruptPin=2)

    def enableMSIX(self):
        self.gic = Pl390(dist_addr=0x2C001000, cpu_addr=0x2C002000, it_lines=512)
        self.gicv2m = Gicv2m()
        self.gicv2m.frames = [Gicv2mFrame(spi_base=256, spi_len=64, addr=0x2C1C0000)]

    def setupBootLoader(self, mem_bus, cur_sys, loc):
        self.nvmem = SimpleMemory(range = AddrRange('64MB'),
                                  conf_table_reported = False)
        self.nvmem.port = mem_bus.master
        cur_sys.boot_loader = loc('boot_emm.arm')
        cur_sys.atags_addr = 0x8000000
        cur_sys.load_addr_mask = 0xfffffff
        cur_sys.load_offset = 0x80000000

    # Attach I/O devices that are on chip and also set the appropriate
    # ranges for the bridge
    def attachOnChipIO(self, bus, bridge=None):
        self.gic.pio             = bus.master
        self.vgic.pio            = bus.master
        self.local_cpu_timer.pio = bus.master
        if hasattr(self, "gicv2m"):
            self.gicv2m.pio      = bus.master
        self.hdlcd.dma           = bus.slave
        if bridge:
            # Bridge ranges based on excluding what is part of on-chip I/O
            # (gic, a9scu)
            bridge.ranges = [AddrRange(0x2F000000, size='16MB'),
                             AddrRange(0x2B000000, size='4MB'),
                             AddrRange(0x30000000, size='256MB'),
                             AddrRange(0x40000000, size='512MB'),
                             AddrRange(0x18000000, size='64MB'),
                             AddrRange(0x1C000000, size='64MB')]


    # Set the clock domain for IO objects that are considered
    # to be "close" to the cores.
    def onChipIOClkDomain(self, clkdomain):
        self.gic.clk_domain             = clkdomain
        if hasattr(self, "gicv2m"):
            self.gicv2m.clk_domain      = clkdomain
        self.hdlcd.clk_domain           = clkdomain
        self.vgic.clk_domain            = clkdomain

    # Attach I/O devices to specified bus object.  Done here
    # as the specified bus to connect to may not always be fixed.
    def attachIO(self, bus):
       self.uart.pio            = bus.master
       self.realview_io.pio     = bus.master
       self.timer0.pio          = bus.master
       self.timer1.pio          = bus.master
       self.clcd.pio            = bus.master
       self.clcd.dma            = bus.slave
       self.hdlcd.pio           = bus.master
       self.kmi0.pio            = bus.master
       self.kmi1.pio            = bus.master
       self.cf_ctrl.pio         = bus.master
       self.cf_ctrl.dma         = bus.slave
       self.cf_ctrl.config      = bus.master
       self.rtc.pio             = bus.master
       bus.use_default_range    = True
       self.vram.port           = bus.master
       self.pciconfig.pio       = bus.default

       self.l2x0_fake.pio       = bus.master
       self.uart1_fake.pio      = bus.master
       self.uart2_fake.pio      = bus.master
       self.uart3_fake.pio      = bus.master
       self.sp810_fake.pio      = bus.master
       self.watchdog_fake.pio   = bus.master
       self.aaci_fake.pio       = bus.master
       self.lan_fake.pio        = bus.master
       self.usb_fake.pio        = bus.master
       self.mmc_fake.pio        = bus.master
       self.energy_ctrl.pio     = bus.master

       # Try to attach the I/O if it exists
       try:
           self.ide.pio         = bus.master
           self.ide.config      = bus.master
           self.ide.dma         = bus.slave
           self.ethernet.pio    = bus.master
           self.ethernet.config = bus.master
           self.ethernet.dma    = bus.slave
       except:
           pass

    # Set the clock domain for IO objects that are considered
    # to be "far" away from the cores.
    def offChipIOClkDomain(self, clkdomain):
        self.uart.clk_domain          = clkdomain
        self.realview_io.clk_domain   = clkdomain
        self.timer0.clk_domain        = clkdomain
        self.timer1.clk_domain        = clkdomain
        self.clcd.clk_domain          = clkdomain
        self.kmi0.clk_domain          = clkdomain
        self.kmi1.clk_domain          = clkdomain
        self.cf_ctrl.clk_domain       = clkdomain
        self.rtc.clk_domain           = clkdomain
        self.vram.clk_domain          = clkdomain
        self.pciconfig.clk_domain     = clkdomain

        self.l2x0_fake.clk_domain     = clkdomain
        self.uart1_fake.clk_domain    = clkdomain
        self.uart2_fake.clk_domain    = clkdomain
        self.uart3_fake.clk_domain    = clkdomain
        self.sp810_fake.clk_domain    = clkdomain
        self.watchdog_fake.clk_domain = clkdomain
        self.aaci_fake.clk_domain     = clkdomain
        self.lan_fake.clk_domain      = clkdomain
        self.usb_fake.clk_domain      = clkdomain
        self.mmc_fake.clk_domain      = clkdomain
        self.energy_ctrl.clk_domain   = clkdomain

class VExpress_EMM64(VExpress_EMM):
    pci_io_base = 0x2f000000
    pci_cfg_gen_offsets = True
    # Three memory regions are specified totalling 512GB
    _mem_regions = [(Addr('2GB'), Addr('2GB')), (Addr('34GB'), Addr('30GB')),
                    (Addr('512GB'), Addr('480GB'))]
    def setupBootLoader(self, mem_bus, cur_sys, loc):
        self.nvmem = SimpleMemory(range = AddrRange(0, size = '64MB'))
        self.nvmem.port = mem_bus.master
        cur_sys.boot_loader = loc('boot_emm.arm64')
        cur_sys.atags_addr = 0x8000000
        cur_sys.load_addr_mask = 0xfffffff
        cur_sys.load_offset = 0x80000000


