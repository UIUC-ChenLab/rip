#ifndef __CONFIG_THE_ISA_HH__
#define __CONFIG_THE_ISA_HH__

#define ALPHA_ISA 1
#define ARM_ISA 2
#define MIPS_ISA 3
#define NULL_ISA 4
#define POWER_ISA 5
#define SPARC_ISA 6
#define X86_ISA 7

enum class Arch {
  AlphaISA = ALPHA_ISA,
  ArmISA = ARM_ISA,
  MipsISA = MIPS_ISA,
  NullISA = NULL_ISA,
  PowerISA = POWER_ISA,
  SparcISA = SPARC_ISA,
  X86ISA = X86_ISA
};

#define THE_ISA X86_ISA
#define TheISA X86ISA
#define THE_ISA_STR "x86"

#endif // __CONFIG_THE_ISA_HH__
