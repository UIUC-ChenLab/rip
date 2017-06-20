// DO NOT EDIT
// This file was automatically generated from an ISA description:
//   x86/isa/main.isa

#undef REX
#define REX	machInst.rex
#undef REX_PRESENT
#define REX_PRESENT	machInst.rex.present
#undef REX_W
#define REX_W	machInst.rex.w
#undef REX_R
#define REX_R	machInst.rex.r
#undef REX_X
#define REX_X	machInst.rex.x
#undef REX_B
#define REX_B	machInst.rex.b
#undef LEGACY
#define LEGACY	machInst.legacy
#undef LEGACY_DECODEVAL
#define LEGACY_DECODEVAL	machInst.legacy.decodeVal
#undef LEGACY_REPNE
#define LEGACY_REPNE	machInst.legacy.repne
#undef LEGACY_REP
#define LEGACY_REP	machInst.legacy.rep
#undef LEGACY_LOCK
#define LEGACY_LOCK	machInst.legacy.lock
#undef LEGACY_OP
#define LEGACY_OP	machInst.legacy.op
#undef LEGACY_ADDR
#define LEGACY_ADDR	machInst.legacy.addr
#undef LEGACY_SEG
#define LEGACY_SEG	machInst.legacy.seg
#undef OPCODE_TYPE
#define OPCODE_TYPE	machInst.opcode.type
#undef OPCODE_OP
#define OPCODE_OP	machInst.opcode.op
#undef OPCODE_OP_TOP5
#define OPCODE_OP_TOP5	machInst.opcode.op.top5
#undef OPCODE_OP_BOTTOM3
#define OPCODE_OP_BOTTOM3	machInst.opcode.op.bottom3
#undef IMMEDIATE
#define IMMEDIATE	machInst.immediate
#undef DISPLACEMENT
#define DISPLACEMENT	machInst.displacement
#undef MODRM
#define MODRM	machInst.modRM
#undef MODRM_MOD
#define MODRM_MOD	machInst.modRM.mod
#undef MODRM_REG
#define MODRM_REG	machInst.modRM.reg
#undef MODRM_RM
#define MODRM_RM	machInst.modRM.rm
#undef SIB
#define SIB	machInst.sib
#undef SIB_SCALE
#define SIB_SCALE	machInst.sib.scale
#undef SIB_INDEX
#define SIB_INDEX	machInst.sib.index
#undef SIB_BASE
#define SIB_BASE	machInst.sib.base
#undef OPSIZE
#define OPSIZE	machInst.opSize
#undef ADDRSIZE
#define ADDRSIZE	machInst.addrSize
#undef STACKSIZE
#define STACKSIZE	machInst.stackSize
#undef MODE
#define MODE	machInst.mode
#undef MODE_MODE
#define MODE_MODE	machInst.mode.mode
#undef MODE_SUBMODE
#define MODE_SUBMODE	machInst.mode.submode

    class CPUIDInst : public X86ISA::X86StaticInst
    {
      public:
        static const RegIndex foldOBit = 0;
        /// Constructor
        CPUIDInst(const char *_mnemonic, ExtMachInst _machInst,
                OpClass __opClass) :
            X86ISA::X86StaticInst(_mnemonic, _machInst, __opClass)
        {
            flags[IsSerializing] = 1;
            flags[IsSerializeAfter] = 1;
        }

        std::string generateDisassembly(Addr pc,
                const SymbolTable *symtab) const;
    };

    class MonitorInst : public X86ISA::X86StaticInst
    {
      public:
        static const RegIndex foldOBit = 0;
        /// Constructor
        MonitorInst(const char *_mnemonic, ExtMachInst _machInst,
                OpClass __opClass) :
            X86ISA::X86StaticInst(_mnemonic, _machInst, __opClass)
        { }

        std::string generateDisassembly(Addr pc,
                const SymbolTable *symtab) const;
    };

    class MwaitInst : public X86ISA::X86StaticInst
    {
      public:
        static const RegIndex foldOBit = 0;
        /// Constructor
        MwaitInst(const char *_mnemonic, ExtMachInst _machInst,
                OpClass __opClass) :
            X86ISA::X86StaticInst(_mnemonic, _machInst, __opClass)
        {
            flags[IsMemRef] = 1;
            flags[IsLoad] = 1;
        }

        std::string generateDisassembly(Addr pc,
                const SymbolTable *symtab) const;
    };

        /**
         * Class for Unknown/Illegal instructions
         */
        class Unknown : public X86ISA::X86StaticInst
        {
          public:

            // Constructor
            Unknown(ExtMachInst _machInst) :
                    X86ISA::X86StaticInst("unknown", _machInst, No_OpClass)
            {
            }

            
        Fault execute(ExecContext *, Trace::InstRecord *) const;


            std::string generateDisassembly(Addr pc,
                    const SymbolTable *symtab) const;

        };

    /**
     * Static instruction class for unimplemented instructions that
     * cause simulator termination.  Note that these are recognized
     * (legal) instructions that the simulator does not support; the
     * 'Unknown' class is used for unrecognized/illegal instructions.
     * This is a leaf class.
     */
    class FailUnimplemented : public X86ISA::X86StaticInst
    {
      public:
        /// Constructor
        FailUnimplemented(const char *_mnemonic, ExtMachInst _machInst)
            : X86ISA::X86StaticInst(_mnemonic, _machInst, No_OpClass)
        {
            // don't call execute() (which panics) if we're on a
            // speculative path
            flags[IsNonSpeculative] = true;
        }

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;


        std::string
        generateDisassembly(Addr pc, const SymbolTable *symtab) const;
    };

    /**
     * Base class for unimplemented instructions that cause a warning
     * to be printed (but do not terminate simulation).  This
     * implementation is a little screwy in that it will print a
     * warning for each instance of a particular unimplemented machine
     * instruction, not just for each unimplemented opcode.  Should
     * probably make the 'warned' flag a static member of the derived
     * class.
     */
    class WarnUnimplemented : public X86ISA::X86StaticInst
    {
      private:
        /// Have we warned on this instruction yet?
        mutable bool warned;

      public:
        /// Constructor
        WarnUnimplemented(const char *_mnemonic, ExtMachInst _machInst)
            : X86ISA::X86StaticInst(_mnemonic, _machInst, No_OpClass), warned(false)
        {
            // don't call execute() (which panics) if we're on a
            // speculative path
            flags[IsNonSpeculative] = true;
        }

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;


        std::string
        generateDisassembly(Addr pc, const SymbolTable *symtab) const;
    };

    class NopInst : public X86ISA::X86StaticInst
    {
      public:
        static const RegIndex foldOBit = 0;
        /// Constructor
        NopInst(const char *_mnemonic, ExtMachInst _machInst,
                OpClass __opClass) :
            X86ISA::X86StaticInst(_mnemonic, _machInst, __opClass)
        {
        }

        std::string generateDisassembly(Addr pc,
                const SymbolTable *symtab) const;
    };

    class SyscallInst : public X86ISA::X86StaticInst
    {
      public:
        static const RegIndex foldOBit = 0;
        /// Constructor
        SyscallInst(const char *_mnemonic, ExtMachInst _machInst,
                OpClass __opClass) :
            X86ISA::X86StaticInst(_mnemonic, _machInst, __opClass)
        {
        }

        std::string generateDisassembly(Addr pc,
                const SymbolTable *symtab) const;
    };

    class MovfpTopTag : public X86ISA::FpOp
    {
      public:
        MovfpTopTag(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class MovfpTop : public X86ISA::FpOp
    {
      public:
        MovfpTop(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Movfp : public X86ISA::FpOp
    {
      public:
        Movfp(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class MovfpFlagsTopTag : public X86ISA::FpOp
    {
      public:
        MovfpFlagsTopTag(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class MovfpFlagsTop : public X86ISA::FpOp
    {
      public:
        MovfpFlagsTop(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class MovfpFlags : public X86ISA::FpOp
    {
      public:
        MovfpFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class XorfpTopTag : public X86ISA::FpOp
    {
      public:
        XorfpTopTag(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class XorfpTop : public X86ISA::FpOp
    {
      public:
        XorfpTop(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Xorfp : public X86ISA::FpOp
    {
      public:
        Xorfp(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class SqrtfpTopTag : public X86ISA::FpOp
    {
      public:
        SqrtfpTopTag(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class SqrtfpTop : public X86ISA::FpOp
    {
      public:
        SqrtfpTop(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Sqrtfp : public X86ISA::FpOp
    {
      public:
        Sqrtfp(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class CosfpTopTag : public X86ISA::FpOp
    {
      public:
        CosfpTopTag(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class CosfpTop : public X86ISA::FpOp
    {
      public:
        CosfpTop(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Cosfp : public X86ISA::FpOp
    {
      public:
        Cosfp(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class SinfpTopTag : public X86ISA::FpOp
    {
      public:
        SinfpTopTag(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class SinfpTop : public X86ISA::FpOp
    {
      public:
        SinfpTop(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Sinfp : public X86ISA::FpOp
    {
      public:
        Sinfp(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class TanfpTopTag : public X86ISA::FpOp
    {
      public:
        TanfpTopTag(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class TanfpTop : public X86ISA::FpOp
    {
      public:
        TanfpTop(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Tanfp : public X86ISA::FpOp
    {
      public:
        Tanfp(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class cvtf_i2dTopTag : public X86ISA::FpOp
    {
      public:
        cvtf_i2dTopTag(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class cvtf_i2dTop : public X86ISA::FpOp
    {
      public:
        cvtf_i2dTop(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class cvtf_i2d : public X86ISA::FpOp
    {
      public:
        cvtf_i2d(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class cvtf_i2d_hiTopTag : public X86ISA::FpOp
    {
      public:
        cvtf_i2d_hiTopTag(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class cvtf_i2d_hiTop : public X86ISA::FpOp
    {
      public:
        cvtf_i2d_hiTop(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class cvtf_i2d_hi : public X86ISA::FpOp
    {
      public:
        cvtf_i2d_hi(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class cvtf_d2iTopTag : public X86ISA::FpOp
    {
      public:
        cvtf_d2iTopTag(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class cvtf_d2iTop : public X86ISA::FpOp
    {
      public:
        cvtf_d2iTop(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class cvtf_d2i : public X86ISA::FpOp
    {
      public:
        cvtf_d2i(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class cvtint_fp80TopTag : public X86ISA::FpOp
    {
      public:
        cvtint_fp80TopTag(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class cvtint_fp80Top : public X86ISA::FpOp
    {
      public:
        cvtint_fp80Top(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class cvtint_fp80 : public X86ISA::FpOp
    {
      public:
        cvtint_fp80(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class cvtfp80h_intTopTag : public X86ISA::FpOp
    {
      public:
        cvtfp80h_intTopTag(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class cvtfp80h_intTop : public X86ISA::FpOp
    {
      public:
        cvtfp80h_intTop(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class cvtfp80h_int : public X86ISA::FpOp
    {
      public:
        cvtfp80h_int(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class cvtfp80l_intTopTag : public X86ISA::FpOp
    {
      public:
        cvtfp80l_intTopTag(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class cvtfp80l_intTop : public X86ISA::FpOp
    {
      public:
        cvtfp80l_intTop(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class cvtfp80l_int : public X86ISA::FpOp
    {
      public:
        cvtfp80l_int(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class addfpTopTag : public X86ISA::FpOp
    {
      public:
        addfpTopTag(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class addfpTop : public X86ISA::FpOp
    {
      public:
        addfpTop(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class addfp : public X86ISA::FpOp
    {
      public:
        addfp(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class mulfpTopTag : public X86ISA::FpOp
    {
      public:
        mulfpTopTag(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class mulfpTop : public X86ISA::FpOp
    {
      public:
        mulfpTop(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class mulfp : public X86ISA::FpOp
    {
      public:
        mulfp(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class divfpTopTag : public X86ISA::FpOp
    {
      public:
        divfpTopTag(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class divfpTop : public X86ISA::FpOp
    {
      public:
        divfpTop(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class divfp : public X86ISA::FpOp
    {
      public:
        divfp(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class subfpTopTag : public X86ISA::FpOp
    {
      public:
        subfpTopTag(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class subfpTop : public X86ISA::FpOp
    {
      public:
        subfpTop(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class subfp : public X86ISA::FpOp
    {
      public:
        subfp(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Yl2xFpTopTag : public X86ISA::FpOp
    {
      public:
        Yl2xFpTopTag(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Yl2xFpTop : public X86ISA::FpOp
    {
      public:
        Yl2xFpTop(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Yl2xFp : public X86ISA::FpOp
    {
      public:
        Yl2xFp(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class PremFpTopTag : public X86ISA::FpOp
    {
      public:
        PremFpTopTag(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class PremFpTop : public X86ISA::FpOp
    {
      public:
        PremFpTop(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class PremFp : public X86ISA::FpOp
    {
      public:
        PremFp(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class PremFpFlagsTopTag : public X86ISA::FpOp
    {
      public:
        PremFpFlagsTopTag(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class PremFpFlagsTop : public X86ISA::FpOp
    {
      public:
        PremFpFlagsTop(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class PremFpFlags : public X86ISA::FpOp
    {
      public:
        PremFpFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class CompfpTopTag : public X86ISA::FpOp
    {
      public:
        CompfpTopTag(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class CompfpTop : public X86ISA::FpOp
    {
      public:
        CompfpTop(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Compfp : public X86ISA::FpOp
    {
      public:
        Compfp(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class absfpTopTag : public X86ISA::FpOp
    {
      public:
        absfpTopTag(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class absfpTop : public X86ISA::FpOp
    {
      public:
        absfpTop(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class absfp : public X86ISA::FpOp
    {
      public:
        absfp(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class absfpFlagsTopTag : public X86ISA::FpOp
    {
      public:
        absfpFlagsTopTag(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class absfpFlagsTop : public X86ISA::FpOp
    {
      public:
        absfpFlagsTop(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class absfpFlags : public X86ISA::FpOp
    {
      public:
        absfpFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class chsfpTopTag : public X86ISA::FpOp
    {
      public:
        chsfpTopTag(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class chsfpTop : public X86ISA::FpOp
    {
      public:
        chsfpTop(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class chsfp : public X86ISA::FpOp
    {
      public:
        chsfp(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class chsfpFlagsTopTag : public X86ISA::FpOp
    {
      public:
        chsfpFlagsTopTag(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class chsfpFlagsTop : public X86ISA::FpOp
    {
      public:
        chsfpFlagsTop(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class chsfpFlags : public X86ISA::FpOp
    {
      public:
        chsfpFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Pop87TopTag : public X86ISA::FpOp
    {
      public:
        Pop87TopTag(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Pop87Top : public X86ISA::FpOp
    {
      public:
        Pop87Top(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Pop87 : public X86ISA::FpOp
    {
      public:
        Pop87(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, int8_t _spm);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    void
    divide(uint64_t dividend, uint64_t divisor,
            uint64_t &quotient, uint64_t &remainder);

    enum SegmentSelectorCheck {
      SegNoCheck, SegCSCheck, SegCallGateCheck, SegIntGateCheck,
      SegSoftIntGateCheck, SegSSCheck, SegIretCheck, SegIntCSCheck,
      SegTRCheck, SegTSSCheck, SegInGDTCheck, SegLDTCheck
    };

    enum LongModeDescriptorType {
        LDT64 = 2,
        AvailableTSS64 = 9,
        BusyTSS64 = 0xb,
        CallGate64 = 0xc,
        IntGate64 = 0xe,
        TrapGate64 = 0xf
    };

    class Add : public X86ISA::RegOp
    {
      public:
        Add(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class AddBig : public X86ISA::RegOp
    {
      public:
        AddBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class AddFlags : public X86ISA::RegOp
    {
      public:
        AddFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class AddFlagsBig : public X86ISA::RegOp
    {
      public:
        AddFlagsBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class AddImm : public X86ISA::RegOpImm
    {
      public:
        AddImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class AddImmBig : public X86ISA::RegOpImm
    {
      public:
        AddImmBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class AddFlagsImm : public X86ISA::RegOpImm
    {
      public:
        AddFlagsImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class AddFlagsImmBig : public X86ISA::RegOpImm
    {
      public:
        AddFlagsImmBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Or : public X86ISA::RegOp
    {
      public:
        Or(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class OrBig : public X86ISA::RegOp
    {
      public:
        OrBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class OrFlags : public X86ISA::RegOp
    {
      public:
        OrFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class OrFlagsBig : public X86ISA::RegOp
    {
      public:
        OrFlagsBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class OrImm : public X86ISA::RegOpImm
    {
      public:
        OrImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class OrImmBig : public X86ISA::RegOpImm
    {
      public:
        OrImmBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class OrFlagsImm : public X86ISA::RegOpImm
    {
      public:
        OrFlagsImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class OrFlagsImmBig : public X86ISA::RegOpImm
    {
      public:
        OrFlagsImmBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Adc : public X86ISA::RegOp
    {
      public:
        Adc(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class AdcBig : public X86ISA::RegOp
    {
      public:
        AdcBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class AdcFlags : public X86ISA::RegOp
    {
      public:
        AdcFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class AdcFlagsBig : public X86ISA::RegOp
    {
      public:
        AdcFlagsBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class AdcImm : public X86ISA::RegOpImm
    {
      public:
        AdcImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class AdcImmBig : public X86ISA::RegOpImm
    {
      public:
        AdcImmBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class AdcFlagsImm : public X86ISA::RegOpImm
    {
      public:
        AdcFlagsImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class AdcFlagsImmBig : public X86ISA::RegOpImm
    {
      public:
        AdcFlagsImmBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Sbb : public X86ISA::RegOp
    {
      public:
        Sbb(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class SbbBig : public X86ISA::RegOp
    {
      public:
        SbbBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class SbbFlags : public X86ISA::RegOp
    {
      public:
        SbbFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class SbbFlagsBig : public X86ISA::RegOp
    {
      public:
        SbbFlagsBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SbbImm : public X86ISA::RegOpImm
    {
      public:
        SbbImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SbbImmBig : public X86ISA::RegOpImm
    {
      public:
        SbbImmBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SbbFlagsImm : public X86ISA::RegOpImm
    {
      public:
        SbbFlagsImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SbbFlagsImmBig : public X86ISA::RegOpImm
    {
      public:
        SbbFlagsImmBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class And : public X86ISA::RegOp
    {
      public:
        And(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class AndBig : public X86ISA::RegOp
    {
      public:
        AndBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class AndFlags : public X86ISA::RegOp
    {
      public:
        AndFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class AndFlagsBig : public X86ISA::RegOp
    {
      public:
        AndFlagsBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class AndImm : public X86ISA::RegOpImm
    {
      public:
        AndImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class AndImmBig : public X86ISA::RegOpImm
    {
      public:
        AndImmBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class AndFlagsImm : public X86ISA::RegOpImm
    {
      public:
        AndFlagsImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class AndFlagsImmBig : public X86ISA::RegOpImm
    {
      public:
        AndFlagsImmBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Sub : public X86ISA::RegOp
    {
      public:
        Sub(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class SubBig : public X86ISA::RegOp
    {
      public:
        SubBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class SubFlags : public X86ISA::RegOp
    {
      public:
        SubFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class SubFlagsBig : public X86ISA::RegOp
    {
      public:
        SubFlagsBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SubImm : public X86ISA::RegOpImm
    {
      public:
        SubImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SubImmBig : public X86ISA::RegOpImm
    {
      public:
        SubImmBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SubFlagsImm : public X86ISA::RegOpImm
    {
      public:
        SubFlagsImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SubFlagsImmBig : public X86ISA::RegOpImm
    {
      public:
        SubFlagsImmBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Xor : public X86ISA::RegOp
    {
      public:
        Xor(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class XorBig : public X86ISA::RegOp
    {
      public:
        XorBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class XorFlags : public X86ISA::RegOp
    {
      public:
        XorFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class XorFlagsBig : public X86ISA::RegOp
    {
      public:
        XorFlagsBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class XorImm : public X86ISA::RegOpImm
    {
      public:
        XorImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class XorImmBig : public X86ISA::RegOpImm
    {
      public:
        XorImmBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class XorFlagsImm : public X86ISA::RegOpImm
    {
      public:
        XorFlagsImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class XorFlagsImmBig : public X86ISA::RegOpImm
    {
      public:
        XorFlagsImmBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Mul1s : public X86ISA::RegOp
    {
      public:
        Mul1s(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Mul1sFlags : public X86ISA::RegOp
    {
      public:
        Mul1sFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class Mul1sImm : public X86ISA::RegOpImm
    {
      public:
        Mul1sImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class Mul1sFlagsImm : public X86ISA::RegOpImm
    {
      public:
        Mul1sFlagsImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Mul1u : public X86ISA::RegOp
    {
      public:
        Mul1u(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Mul1uFlags : public X86ISA::RegOp
    {
      public:
        Mul1uFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class Mul1uImm : public X86ISA::RegOpImm
    {
      public:
        Mul1uImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class Mul1uFlagsImm : public X86ISA::RegOpImm
    {
      public:
        Mul1uFlagsImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Mulel : public X86ISA::RegOp
    {
      public:
        Mulel(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class MulelBig : public X86ISA::RegOp
    {
      public:
        MulelBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Muleh : public X86ISA::RegOp
    {
      public:
        Muleh(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class MulehBig : public X86ISA::RegOp
    {
      public:
        MulehBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Div1 : public X86ISA::RegOp
    {
      public:
        Div1(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class Div1Imm : public X86ISA::RegOpImm
    {
      public:
        Div1Imm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Div2 : public X86ISA::RegOp
    {
      public:
        Div2(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Div2Big : public X86ISA::RegOp
    {
      public:
        Div2Big(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Div2Flags : public X86ISA::RegOp
    {
      public:
        Div2Flags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Div2FlagsBig : public X86ISA::RegOp
    {
      public:
        Div2FlagsBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class Div2Imm : public X86ISA::RegOpImm
    {
      public:
        Div2Imm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class Div2ImmBig : public X86ISA::RegOpImm
    {
      public:
        Div2ImmBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class Div2FlagsImm : public X86ISA::RegOpImm
    {
      public:
        Div2FlagsImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class Div2FlagsImmBig : public X86ISA::RegOpImm
    {
      public:
        Div2FlagsImmBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Divq : public X86ISA::RegOp
    {
      public:
        Divq(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class DivqBig : public X86ISA::RegOp
    {
      public:
        DivqBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Divr : public X86ISA::RegOp
    {
      public:
        Divr(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class DivrBig : public X86ISA::RegOp
    {
      public:
        DivrBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Mov : public X86ISA::RegOp
    {
      public:
        Mov(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class MovFlags : public X86ISA::RegOp
    {
      public:
        MovFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class MovImm : public X86ISA::RegOpImm
    {
      public:
        MovImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class MovFlagsImm : public X86ISA::RegOpImm
    {
      public:
        MovFlagsImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Sll : public X86ISA::RegOp
    {
      public:
        Sll(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class SllBig : public X86ISA::RegOp
    {
      public:
        SllBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class SllFlags : public X86ISA::RegOp
    {
      public:
        SllFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class SllFlagsBig : public X86ISA::RegOp
    {
      public:
        SllFlagsBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SllImm : public X86ISA::RegOpImm
    {
      public:
        SllImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SllImmBig : public X86ISA::RegOpImm
    {
      public:
        SllImmBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SllFlagsImm : public X86ISA::RegOpImm
    {
      public:
        SllFlagsImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SllFlagsImmBig : public X86ISA::RegOpImm
    {
      public:
        SllFlagsImmBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Srl : public X86ISA::RegOp
    {
      public:
        Srl(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class SrlBig : public X86ISA::RegOp
    {
      public:
        SrlBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class SrlFlags : public X86ISA::RegOp
    {
      public:
        SrlFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class SrlFlagsBig : public X86ISA::RegOp
    {
      public:
        SrlFlagsBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SrlImm : public X86ISA::RegOpImm
    {
      public:
        SrlImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SrlImmBig : public X86ISA::RegOpImm
    {
      public:
        SrlImmBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SrlFlagsImm : public X86ISA::RegOpImm
    {
      public:
        SrlFlagsImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SrlFlagsImmBig : public X86ISA::RegOpImm
    {
      public:
        SrlFlagsImmBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Sra : public X86ISA::RegOp
    {
      public:
        Sra(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class SraBig : public X86ISA::RegOp
    {
      public:
        SraBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class SraFlags : public X86ISA::RegOp
    {
      public:
        SraFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class SraFlagsBig : public X86ISA::RegOp
    {
      public:
        SraFlagsBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SraImm : public X86ISA::RegOpImm
    {
      public:
        SraImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SraImmBig : public X86ISA::RegOpImm
    {
      public:
        SraImmBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SraFlagsImm : public X86ISA::RegOpImm
    {
      public:
        SraFlagsImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SraFlagsImmBig : public X86ISA::RegOpImm
    {
      public:
        SraFlagsImmBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Ror : public X86ISA::RegOp
    {
      public:
        Ror(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class RorFlags : public X86ISA::RegOp
    {
      public:
        RorFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class RorImm : public X86ISA::RegOpImm
    {
      public:
        RorImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class RorFlagsImm : public X86ISA::RegOpImm
    {
      public:
        RorFlagsImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Rcr : public X86ISA::RegOp
    {
      public:
        Rcr(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class RcrFlags : public X86ISA::RegOp
    {
      public:
        RcrFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class RcrImm : public X86ISA::RegOpImm
    {
      public:
        RcrImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class RcrFlagsImm : public X86ISA::RegOpImm
    {
      public:
        RcrFlagsImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Rol : public X86ISA::RegOp
    {
      public:
        Rol(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class RolFlags : public X86ISA::RegOp
    {
      public:
        RolFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class RolImm : public X86ISA::RegOpImm
    {
      public:
        RolImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class RolFlagsImm : public X86ISA::RegOpImm
    {
      public:
        RolFlagsImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Rcl : public X86ISA::RegOp
    {
      public:
        Rcl(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class RclFlags : public X86ISA::RegOp
    {
      public:
        RclFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class RclImm : public X86ISA::RegOpImm
    {
      public:
        RclImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class RclFlagsImm : public X86ISA::RegOpImm
    {
      public:
        RclFlagsImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Sld : public X86ISA::RegOp
    {
      public:
        Sld(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class SldBig : public X86ISA::RegOp
    {
      public:
        SldBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class SldFlags : public X86ISA::RegOp
    {
      public:
        SldFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class SldFlagsBig : public X86ISA::RegOp
    {
      public:
        SldFlagsBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SldImm : public X86ISA::RegOpImm
    {
      public:
        SldImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SldImmBig : public X86ISA::RegOpImm
    {
      public:
        SldImmBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SldFlagsImm : public X86ISA::RegOpImm
    {
      public:
        SldFlagsImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SldFlagsImmBig : public X86ISA::RegOpImm
    {
      public:
        SldFlagsImmBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Srd : public X86ISA::RegOp
    {
      public:
        Srd(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class SrdBig : public X86ISA::RegOp
    {
      public:
        SrdBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class SrdFlags : public X86ISA::RegOp
    {
      public:
        SrdFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class SrdFlagsBig : public X86ISA::RegOp
    {
      public:
        SrdFlagsBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SrdImm : public X86ISA::RegOpImm
    {
      public:
        SrdImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SrdImmBig : public X86ISA::RegOpImm
    {
      public:
        SrdImmBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SrdFlagsImm : public X86ISA::RegOpImm
    {
      public:
        SrdFlagsImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SrdFlagsImmBig : public X86ISA::RegOpImm
    {
      public:
        SrdFlagsImmBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Mdb : public X86ISA::RegOp
    {
      public:
        Mdb(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class MdbImm : public X86ISA::RegOpImm
    {
      public:
        MdbImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Wrip : public X86ISA::RegOp
    {
      public:
        Wrip(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class WripFlags : public X86ISA::RegOp
    {
      public:
        WripFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class WripImm : public X86ISA::RegOpImm
    {
      public:
        WripImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class WripFlagsImm : public X86ISA::RegOpImm
    {
      public:
        WripFlagsImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Wruflags : public X86ISA::RegOp
    {
      public:
        Wruflags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class WruflagsImm : public X86ISA::RegOpImm
    {
      public:
        WruflagsImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Wrflags : public X86ISA::RegOp
    {
      public:
        Wrflags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class WrflagsImm : public X86ISA::RegOpImm
    {
      public:
        WrflagsImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Rdip : public X86ISA::RegOp
    {
      public:
        Rdip(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Ruflags : public X86ISA::RegOp
    {
      public:
        Ruflags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Rflags : public X86ISA::RegOp
    {
      public:
        Rflags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class Ruflag : public X86ISA::RegOpImm
    {
      public:
        Ruflag(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class RuflagBig : public X86ISA::RegOpImm
    {
      public:
        RuflagBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class Rflag : public X86ISA::RegOpImm
    {
      public:
        Rflag(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class RflagBig : public X86ISA::RegOpImm
    {
      public:
        RflagBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Sext : public X86ISA::RegOp
    {
      public:
        Sext(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class SextBig : public X86ISA::RegOp
    {
      public:
        SextBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class SextFlags : public X86ISA::RegOp
    {
      public:
        SextFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class SextFlagsBig : public X86ISA::RegOp
    {
      public:
        SextFlagsBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SextImm : public X86ISA::RegOpImm
    {
      public:
        SextImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SextImmBig : public X86ISA::RegOpImm
    {
      public:
        SextImmBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SextFlagsImm : public X86ISA::RegOpImm
    {
      public:
        SextFlagsImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class SextFlagsImmBig : public X86ISA::RegOpImm
    {
      public:
        SextFlagsImmBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Zext : public X86ISA::RegOp
    {
      public:
        Zext(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class ZextBig : public X86ISA::RegOp
    {
      public:
        ZextBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class ZextImm : public X86ISA::RegOpImm
    {
      public:
        ZextImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class ZextImmBig : public X86ISA::RegOpImm
    {
      public:
        ZextImmBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Rddr : public X86ISA::RegOp
    {
      public:
        Rddr(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class RddrBig : public X86ISA::RegOp
    {
      public:
        RddrBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Wrdr : public X86ISA::RegOp
    {
      public:
        Wrdr(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Rdcr : public X86ISA::RegOp
    {
      public:
        Rdcr(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class RdcrBig : public X86ISA::RegOp
    {
      public:
        RdcrBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Wrcr : public X86ISA::RegOp
    {
      public:
        Wrcr(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Wrbase : public X86ISA::RegOp
    {
      public:
        Wrbase(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class WrbaseFlags : public X86ISA::RegOp
    {
      public:
        WrbaseFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Wrlimit : public X86ISA::RegOp
    {
      public:
        Wrlimit(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class WrlimitFlags : public X86ISA::RegOp
    {
      public:
        WrlimitFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Wrsel : public X86ISA::RegOp
    {
      public:
        Wrsel(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class WrselFlags : public X86ISA::RegOp
    {
      public:
        WrselFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class WrAttr : public X86ISA::RegOp
    {
      public:
        WrAttr(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class WrAttrFlags : public X86ISA::RegOp
    {
      public:
        WrAttrFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Rdbase : public X86ISA::RegOp
    {
      public:
        Rdbase(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class RdbaseBig : public X86ISA::RegOp
    {
      public:
        RdbaseBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class RdbaseFlags : public X86ISA::RegOp
    {
      public:
        RdbaseFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class RdbaseFlagsBig : public X86ISA::RegOp
    {
      public:
        RdbaseFlagsBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Rdlimit : public X86ISA::RegOp
    {
      public:
        Rdlimit(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class RdlimitBig : public X86ISA::RegOp
    {
      public:
        RdlimitBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class RdlimitFlags : public X86ISA::RegOp
    {
      public:
        RdlimitFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class RdlimitFlagsBig : public X86ISA::RegOp
    {
      public:
        RdlimitFlagsBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class RdAttr : public X86ISA::RegOp
    {
      public:
        RdAttr(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class RdAttrBig : public X86ISA::RegOp
    {
      public:
        RdAttrBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class RdAttrFlags : public X86ISA::RegOp
    {
      public:
        RdAttrFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class RdAttrFlagsBig : public X86ISA::RegOp
    {
      public:
        RdAttrFlagsBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Rdsel : public X86ISA::RegOp
    {
      public:
        Rdsel(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class RdselBig : public X86ISA::RegOp
    {
      public:
        RdselBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class RdselFlags : public X86ISA::RegOp
    {
      public:
        RdselFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class RdselFlagsBig : public X86ISA::RegOp
    {
      public:
        RdselFlagsBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Rdval : public X86ISA::RegOp
    {
      public:
        Rdval(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Wrval : public X86ISA::RegOp
    {
      public:
        Wrval(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class Chks : public X86ISA::RegOpImm
    {
      public:
        Chks(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class ChksFlags : public X86ISA::RegOpImm
    {
      public:
        ChksFlags(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint8_t _imm8, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Wrdh : public X86ISA::RegOp
    {
      public:
        Wrdh(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Wrtsc : public X86ISA::RegOp
    {
      public:
        Wrtsc(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Rdtsc : public X86ISA::RegOp
    {
      public:
        Rdtsc(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Rdm5reg : public X86ISA::RegOp
    {
      public:
        Rdm5reg(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Wrdl : public X86ISA::RegOp
    {
      public:
        Wrdl(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Wrxftw : public X86ISA::RegOp
    {
      public:
        Wrxftw(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Rdxftw : public X86ISA::RegOp
    {
      public:
        Rdxftw(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _dataSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Limm : public X86ISA::X86MicroopBase
    {
      protected:
        const RegIndex dest;
        const uint64_t imm;
        const uint8_t dataSize;
        RegIndex foldOBit;

        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const;

      public:
        Limm(ExtMachInst _machInst,
                const char * instMnem,
                uint64_t setFlags, InstRegIndex _dest,
                uint64_t _imm, uint8_t _dataSize);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class LimmBig : public X86ISA::X86MicroopBase
    {
      protected:
        const RegIndex dest;
        const uint64_t imm;
        const uint8_t dataSize;
        RegIndex foldOBit;

        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const;

      public:
        LimmBig(ExtMachInst _machInst,
                const char * instMnem,
                uint64_t setFlags, InstRegIndex _dest,
                uint64_t _imm, uint8_t _dataSize);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Lfpimm : public X86ISA::X86MicroopBase
    {
      protected:
        const RegIndex dest;
        const uint64_t imm;
        const uint8_t dataSize;
        RegIndex foldOBit;

        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const;

      public:
        Lfpimm(ExtMachInst _machInst,
                const char * instMnem,
                uint64_t setFlags, InstRegIndex _dest,
                uint64_t _imm, uint8_t _dataSize);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Ld : public X86ISA::LdStOp
    {
      public:
        Ld(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                uint8_t _scale, InstRegIndex _index, InstRegIndex _base,
                uint64_t _disp, InstRegIndex _segment,
                InstRegIndex _data,
                uint8_t _dataSize, uint8_t _addressSize,
                Request::FlagsType _memFlags);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;


        
    Fault initiateAcc(ExecContext *, Trace::InstRecord *) const;


        
    Fault completeAcc(PacketPtr, ExecContext *, Trace::InstRecord *) const;

    };

    class LdBig : public X86ISA::LdStOp
    {
      public:
        LdBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                uint8_t _scale, InstRegIndex _index, InstRegIndex _base,
                uint64_t _disp, InstRegIndex _segment,
                InstRegIndex _data,
                uint8_t _dataSize, uint8_t _addressSize,
                Request::FlagsType _memFlags);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;


        
    Fault initiateAcc(ExecContext *, Trace::InstRecord *) const;


        
    Fault completeAcc(PacketPtr, ExecContext *, Trace::InstRecord *) const;

    };

    class Ldst : public X86ISA::LdStOp
    {
      public:
        Ldst(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                uint8_t _scale, InstRegIndex _index, InstRegIndex _base,
                uint64_t _disp, InstRegIndex _segment,
                InstRegIndex _data,
                uint8_t _dataSize, uint8_t _addressSize,
                Request::FlagsType _memFlags);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;


        
    Fault initiateAcc(ExecContext *, Trace::InstRecord *) const;


        
    Fault completeAcc(PacketPtr, ExecContext *, Trace::InstRecord *) const;

    };

    class LdstBig : public X86ISA::LdStOp
    {
      public:
        LdstBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                uint8_t _scale, InstRegIndex _index, InstRegIndex _base,
                uint64_t _disp, InstRegIndex _segment,
                InstRegIndex _data,
                uint8_t _dataSize, uint8_t _addressSize,
                Request::FlagsType _memFlags);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;


        
    Fault initiateAcc(ExecContext *, Trace::InstRecord *) const;


        
    Fault completeAcc(PacketPtr, ExecContext *, Trace::InstRecord *) const;

    };

    class Ldstl : public X86ISA::LdStOp
    {
      public:
        Ldstl(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                uint8_t _scale, InstRegIndex _index, InstRegIndex _base,
                uint64_t _disp, InstRegIndex _segment,
                InstRegIndex _data,
                uint8_t _dataSize, uint8_t _addressSize,
                Request::FlagsType _memFlags);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;


        
    Fault initiateAcc(ExecContext *, Trace::InstRecord *) const;


        
    Fault completeAcc(PacketPtr, ExecContext *, Trace::InstRecord *) const;

    };

    class LdstlBig : public X86ISA::LdStOp
    {
      public:
        LdstlBig(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                uint8_t _scale, InstRegIndex _index, InstRegIndex _base,
                uint64_t _disp, InstRegIndex _segment,
                InstRegIndex _data,
                uint8_t _dataSize, uint8_t _addressSize,
                Request::FlagsType _memFlags);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;


        
    Fault initiateAcc(ExecContext *, Trace::InstRecord *) const;


        
    Fault completeAcc(PacketPtr, ExecContext *, Trace::InstRecord *) const;

    };

    class Ldfp : public X86ISA::LdStOp
    {
      public:
        Ldfp(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                uint8_t _scale, InstRegIndex _index, InstRegIndex _base,
                uint64_t _disp, InstRegIndex _segment,
                InstRegIndex _data,
                uint8_t _dataSize, uint8_t _addressSize,
                Request::FlagsType _memFlags);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;


        
    Fault initiateAcc(ExecContext *, Trace::InstRecord *) const;


        
    Fault completeAcc(PacketPtr, ExecContext *, Trace::InstRecord *) const;

    };

    class Ldfp87 : public X86ISA::LdStOp
    {
      public:
        Ldfp87(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                uint8_t _scale, InstRegIndex _index, InstRegIndex _base,
                uint64_t _disp, InstRegIndex _segment,
                InstRegIndex _data,
                uint8_t _dataSize, uint8_t _addressSize,
                Request::FlagsType _memFlags);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;


        
    Fault initiateAcc(ExecContext *, Trace::InstRecord *) const;


        
    Fault completeAcc(PacketPtr, ExecContext *, Trace::InstRecord *) const;

    };

    class St : public X86ISA::LdStOp
    {
      public:
        St(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                uint8_t _scale, InstRegIndex _index, InstRegIndex _base,
                uint64_t _disp, InstRegIndex _segment,
                InstRegIndex _data,
                uint8_t _dataSize, uint8_t _addressSize,
                Request::FlagsType _memFlags);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;


        
    Fault initiateAcc(ExecContext *, Trace::InstRecord *) const;


        
    Fault completeAcc(PacketPtr, ExecContext *, Trace::InstRecord *) const;

    };

    class Stul : public X86ISA::LdStOp
    {
      public:
        Stul(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                uint8_t _scale, InstRegIndex _index, InstRegIndex _base,
                uint64_t _disp, InstRegIndex _segment,
                InstRegIndex _data,
                uint8_t _dataSize, uint8_t _addressSize,
                Request::FlagsType _memFlags);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;


        
    Fault initiateAcc(ExecContext *, Trace::InstRecord *) const;


        
    Fault completeAcc(PacketPtr, ExecContext *, Trace::InstRecord *) const;

    };

    class Stfp : public X86ISA::LdStOp
    {
      public:
        Stfp(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                uint8_t _scale, InstRegIndex _index, InstRegIndex _base,
                uint64_t _disp, InstRegIndex _segment,
                InstRegIndex _data,
                uint8_t _dataSize, uint8_t _addressSize,
                Request::FlagsType _memFlags);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;


        
    Fault initiateAcc(ExecContext *, Trace::InstRecord *) const;


        
    Fault completeAcc(PacketPtr, ExecContext *, Trace::InstRecord *) const;

    };

    class Stfp87 : public X86ISA::LdStOp
    {
      public:
        Stfp87(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                uint8_t _scale, InstRegIndex _index, InstRegIndex _base,
                uint64_t _disp, InstRegIndex _segment,
                InstRegIndex _data,
                uint8_t _dataSize, uint8_t _addressSize,
                Request::FlagsType _memFlags);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;


        
    Fault initiateAcc(ExecContext *, Trace::InstRecord *) const;


        
    Fault completeAcc(PacketPtr, ExecContext *, Trace::InstRecord *) const;

    };

    class Cda : public X86ISA::LdStOp
    {
      public:
        Cda(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                uint8_t _scale, InstRegIndex _index, InstRegIndex _base,
                uint64_t _disp, InstRegIndex _segment,
                InstRegIndex _data,
                uint8_t _dataSize, uint8_t _addressSize,
                Request::FlagsType _memFlags);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;


        
    Fault initiateAcc(ExecContext *, Trace::InstRecord *) const;


        
    Fault completeAcc(PacketPtr, ExecContext *, Trace::InstRecord *) const;

    };

    class Lea : public X86ISA::LdStOp
    {
      public:
        Lea(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                uint8_t _scale, InstRegIndex _index, InstRegIndex _base,
                uint64_t _disp, InstRegIndex _segment,
                InstRegIndex _data,
                uint8_t _dataSize, uint8_t _addressSize,
                Request::FlagsType _memFlags);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Tia : public X86ISA::LdStOp
    {
      public:
        Tia(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                uint8_t _scale, InstRegIndex _index, InstRegIndex _base,
                uint64_t _disp, InstRegIndex _segment,
                InstRegIndex _data,
                uint8_t _dataSize, uint8_t _addressSize,
                Request::FlagsType _memFlags);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class Mov2int : public X86ISA::MediaOpImm
    {
      public:
        Mov2int(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint16_t _imm8, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class Mov2fp : public X86ISA::MediaOpImm
    {
      public:
        Mov2fp(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint16_t _imm8, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Movsign : public X86ISA::MediaOpReg
    {
      public:
        Movsign(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Maskmov : public X86ISA::MediaOpReg
    {
      public:
        Maskmov(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class shuffle : public X86ISA::MediaOpReg
    {
      public:
        shuffle(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Unpack : public X86ISA::MediaOpReg
    {
      public:
        Unpack(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Pack : public X86ISA::MediaOpReg
    {
      public:
        Pack(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Mxor : public X86ISA::MediaOpReg
    {
      public:
        Mxor(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Mor : public X86ISA::MediaOpReg
    {
      public:
        Mor(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Mand : public X86ISA::MediaOpReg
    {
      public:
        Mand(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Mandn : public X86ISA::MediaOpReg
    {
      public:
        Mandn(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Mminf : public X86ISA::MediaOpReg
    {
      public:
        Mminf(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Mmaxf : public X86ISA::MediaOpReg
    {
      public:
        Mmaxf(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Mmini : public X86ISA::MediaOpReg
    {
      public:
        Mmini(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Mmaxi : public X86ISA::MediaOpReg
    {
      public:
        Mmaxi(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Msqrt : public X86ISA::MediaOpReg
    {
      public:
        Msqrt(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Maddf : public X86ISA::MediaOpReg
    {
      public:
        Maddf(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Msubf : public X86ISA::MediaOpReg
    {
      public:
        Msubf(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Mmulf : public X86ISA::MediaOpReg
    {
      public:
        Mmulf(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Mdivf : public X86ISA::MediaOpReg
    {
      public:
        Mdivf(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Maddi : public X86ISA::MediaOpReg
    {
      public:
        Maddi(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Msubi : public X86ISA::MediaOpReg
    {
      public:
        Msubi(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Mmuli : public X86ISA::MediaOpReg
    {
      public:
        Mmuli(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Mavg : public X86ISA::MediaOpReg
    {
      public:
        Mavg(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Msad : public X86ISA::MediaOpReg
    {
      public:
        Msad(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Msrl : public X86ISA::MediaOpReg
    {
      public:
        Msrl(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class MsrlImm : public X86ISA::MediaOpImm
    {
      public:
        MsrlImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint16_t _imm8, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Msra : public X86ISA::MediaOpReg
    {
      public:
        Msra(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class MsraImm : public X86ISA::MediaOpImm
    {
      public:
        MsraImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint16_t _imm8, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Msll : public X86ISA::MediaOpReg
    {
      public:
        Msll(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


    class MsllImm : public X86ISA::MediaOpImm
    {
      public:
        MsllImm(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, uint16_t _imm8, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Cvtf2i : public X86ISA::MediaOpReg
    {
      public:
        Cvtf2i(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Cvti2f : public X86ISA::MediaOpReg
    {
      public:
        Cvti2f(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Cvtf2f : public X86ISA::MediaOpReg
    {
      public:
        Cvtf2f(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Mcmpi2r : public X86ISA::MediaOpReg
    {
      public:
        Mcmpi2r(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Mcmpf2r : public X86ISA::MediaOpReg
    {
      public:
        Mcmpf2r(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Mcmpf2rf : public X86ISA::MediaOpReg
    {
      public:
        Mcmpf2rf(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Emms : public X86ISA::MediaOpReg
    {
      public:
        Emms(ExtMachInst _machInst,
                const char * instMnem, uint64_t setFlags,
                InstRegIndex _src1, InstRegIndex _src2, InstRegIndex _dest,
                uint8_t _srcSize, uint8_t _destSize, uint16_t _ext);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class SeqOpBase : public X86ISA::X86MicroopBase
    {
      protected:
        uint16_t target;
        uint8_t cc;

      public:
        SeqOpBase(ExtMachInst _machInst, const char * instMnem,
                const char * mnemonic, uint64_t setFlags,
                uint16_t _target, uint8_t _cc);

        SeqOpBase(ExtMachInst _machInst, const char * instMnem,
                const char * mnemonic,
                uint16_t _target, uint8_t _cc);

        std::string generateDisassembly(Addr pc,
                const SymbolTable *symtab) const;
    };

    class MicroBranchFlags : public SeqOpBase
    {
      public:
        MicroBranchFlags(ExtMachInst _machInst, const char * instMnem,
                uint64_t setFlags, uint16_t _target, uint8_t _cc);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class MicroBranch : public SeqOpBase
    {
      public:
        MicroBranch(ExtMachInst _machInst, const char * instMnem,
                uint64_t setFlags, uint16_t _target, uint8_t _cc);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class EretFlags : public SeqOpBase
    {
      public:
        EretFlags(ExtMachInst _machInst, const char * instMnem,
                uint64_t setFlags, uint16_t _target, uint8_t _cc);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Eret : public SeqOpBase
    {
      public:
        Eret(ExtMachInst _machInst, const char * instMnem,
                uint64_t setFlags, uint16_t _target, uint8_t _cc);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class MicroFaultBase : public X86ISA::X86MicroopBase
    {
      protected:
        Fault fault;
        uint8_t cc;

      public:
        MicroFaultBase(ExtMachInst _machInst, const char * instMnem,
                uint64_t setFlags, Fault _fault, uint8_t _cc);

        std::string generateDisassembly(Addr pc,
                const SymbolTable *symtab) const;
    };

    class MicroHalt : public X86ISA::X86MicroopBase
    {
      public:
        MicroHalt(ExtMachInst _machInst, const char * instMnem,
                uint64_t setFlags) :
            X86MicroopBase(_machInst, "halt", instMnem,
                           setFlags | (ULL(1) << StaticInst::IsNonSpeculative) |
                           (ULL(1) << StaticInst::IsQuiesce),
                           No_OpClass)
        {
        }

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;


        std::string generateDisassembly(Addr pc,
                const SymbolTable *symtab) const;
    };

    class MicroFaultFlags : public MicroFaultBase
    {
      public:
        MicroFaultFlags(ExtMachInst _machInst, const char * instMnem,
                uint64_t setFlags, Fault _fault, uint8_t _cc);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class MicroFault : public MicroFaultBase
    {
      public:
        MicroFault(ExtMachInst _machInst, const char * instMnem,
                uint64_t setFlags, Fault _fault, uint8_t _cc);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class Mfence : public X86ISA::X86MicroopBase
    {
      public:
        Mfence(ExtMachInst _machInst,
                const char * instMnem,
                uint64_t setFlags);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class MicroDebugBase : public X86ISA::X86MicroopBase
    {
      protected:
        typedef GenericISA::M5DebugFault::DebugFunc DebugFunc;
        DebugFunc func;
        std::string message;
        uint8_t cc;

      public:
        MicroDebugBase(ExtMachInst machInst, const char * mnem,
                const char * instMnem, uint64_t setFlags,
                DebugFunc _func, std::string _message, uint8_t _cc) :
            X86MicroopBase(machInst, mnem, instMnem, setFlags, No_OpClass),
                    func(_func), message(_message), cc(_cc)
        {}

        std::string
        generateDisassembly(Addr pc, const SymbolTable *symtab) const
        {
            std::stringstream response;

            printMnemonic(response, instMnem, mnemonic);
            response << "\"" << message << "\"";

            return response.str();
        }
    };

    class MicroPanicFlags : public MicroDebugBase
    {
      public:
        MicroPanicFlags(ExtMachInst _machInst, const char * instMnem,
                uint64_t setFlags, std::string _message, uint8_t _cc);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class MicroPanic : public MicroDebugBase
    {
      public:
        MicroPanic(ExtMachInst _machInst, const char * instMnem,
                uint64_t setFlags, std::string _message, uint8_t _cc);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class MicroFatalFlags : public MicroDebugBase
    {
      public:
        MicroFatalFlags(ExtMachInst _machInst, const char * instMnem,
                uint64_t setFlags, std::string _message, uint8_t _cc);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class MicroFatal : public MicroDebugBase
    {
      public:
        MicroFatal(ExtMachInst _machInst, const char * instMnem,
                uint64_t setFlags, std::string _message, uint8_t _cc);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class MicroWarnFlags : public MicroDebugBase
    {
      public:
        MicroWarnFlags(ExtMachInst _machInst, const char * instMnem,
                uint64_t setFlags, std::string _message, uint8_t _cc);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class MicroWarn : public MicroDebugBase
    {
      public:
        MicroWarn(ExtMachInst _machInst, const char * instMnem,
                uint64_t setFlags, std::string _message, uint8_t _cc);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class MicroWarn_onceFlags : public MicroDebugBase
    {
      public:
        MicroWarn_onceFlags(ExtMachInst _machInst, const char * instMnem,
                uint64_t setFlags, std::string _message, uint8_t _cc);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };

    class MicroWarn_once : public MicroDebugBase
    {
      public:
        MicroWarn_once(ExtMachInst _machInst, const char * instMnem,
                uint64_t setFlags, std::string _message, uint8_t _cc);

        
        Fault execute(ExecContext *, Trace::InstRecord *) const;

    };


        // Base class for combinationally generated macroops
        class Macroop : public X86ISA::MacroopBase
        {
          public:
            Macroop(const char *mnem, ExtMachInst _machInst,
                    uint32_t _numMicroops, X86ISA::EmulEnv _env)
                        : MacroopBase(mnem, _machInst, _numMicroops, _env)
            {}
            
        Fault execute(ExecContext *, Trace::InstRecord *) const
        {
            panic("Tried to execute macroop directly!");
            return NoFault;
        }

        };
namespace RomLabels {
const static uint64_t label_longModeSoftInterrupt_stackSwitched = 92;
const static uint64_t label_longModeInterrupt_processDescriptor = 11;
const static uint64_t label_longModeInterruptWithError_cplStackSwitch = 152;
const static uint64_t label_longModeInterrupt_istStackSwitch = 28;
const static uint64_t label_jmpFarWork = 192;
const static uint64_t label_farJmpSystemDescriptor = 207;
const static uint64_t label_longModeSoftInterrupt_globalDescriptor = 71;
const static uint64_t label_farJmpGlobalDescriptor = 199;
const static uint64_t label_initIntHalt = 186;
const static uint64_t label_longModeInterruptWithError_istStackSwitch = 150;
const static uint64_t label_legacyModeInterrupt = 184;
const static uint64_t label_longModeInterruptWithError_globalDescriptor = 132;
const static uint64_t label_longModeSoftInterrupt_processDescriptor = 72;
const static uint64_t label_longModeInterruptWithError = 122;
const static uint64_t label_farJmpProcessDescriptor = 200;
const static uint64_t label_longModeSoftInterrupt = 61;
const static uint64_t label_longModeSoftInterrupt_istStackSwitch = 89;
const static uint64_t label_longModeInterrupt_globalDescriptor = 10;
const static uint64_t label_longModeInterrupt_cplStackSwitch = 30;
const static uint64_t label_longModeInterrupt = 0;
const static uint64_t label_longModeInterruptWithError_processDescriptor = 133;
const static uint64_t label_longModeInterruptWithError_stackSwitched = 153;
const static uint64_t label_longModeInterrupt_stackSwitched = 31;
const static uint64_t label_longModeSoftInterrupt_cplStackSwitch = 91;
const static MicroPC extern_label_initIntHalt = 186;
const static MicroPC extern_label_longModeInterruptWithError = 122;
const static MicroPC extern_label_longModeInterrupt = 0;
const static MicroPC extern_label_longModeSoftInterrupt = 61;
const static MicroPC extern_label_legacyModeInterrupt = 184;
const static MicroPC extern_label_jmpFarWork = 192;
}

// Inst::UD2([],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "ud2".
             */
            class UD2 : public Macroop
            {
              private:
                
              public:
                // Constructor.
                UD2(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::push_ES(([], {}))

// Inst::UD2([],{})

// WarnUnimpl::pop_ES(([], {}))

// MultiInst::ADD((['OPCODE_OP_BOTTOM3', ['Gb'], ['Gv'], [], [], [], []], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "add".
             */
            class ADD_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADD_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "add".
             */
            class ADD_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADD_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "add".
             */
            class ADD_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADD_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "add".
             */
            class ADD_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADD_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "add".
             */
            class ADD_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADD_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "add".
             */
            class ADD_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADD_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// WarnUnimpl::push_CS(([], {}))

// M5InternalError::error((['"Saw a one byte opcode whose value was 0x0F!"'], {}))

// MultiInst::OR((['OPCODE_OP_BOTTOM3', ['Gb'], ['Gv'], [], [], [], []], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "or".
             */
            class OR_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                OR_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "or".
             */
            class OR_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                OR_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "or".
             */
            class OR_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                OR_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "or".
             */
            class OR_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                OR_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "or".
             */
            class OR_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                OR_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "or".
             */
            class OR_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                OR_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// WarnUnimpl::push_SS(([], {}))

// Inst::UD2([],{})

// WarnUnimpl::pop_SS(([], {}))

// MultiInst::ADC((['OPCODE_OP_BOTTOM3', ['Gb'], ['Gv'], [], [], [], []], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "adc".
             */
            class ADC_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADC_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "adc".
             */
            class ADC_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADC_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "adc".
             */
            class ADC_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADC_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "adc".
             */
            class ADC_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADC_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "adc".
             */
            class ADC_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADC_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "adc".
             */
            class ADC_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADC_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// WarnUnimpl::push_DS(([], {}))

// Inst::UD2([],{})

// WarnUnimpl::pop_DS(([], {}))

// MultiInst::SBB((['OPCODE_OP_BOTTOM3', ['Gb'], ['Gv'], [], [], [], []], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sbb".
             */
            class SBB_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SBB_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sbb".
             */
            class SBB_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SBB_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sbb".
             */
            class SBB_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SBB_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sbb".
             */
            class SBB_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SBB_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sbb".
             */
            class SBB_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SBB_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sbb".
             */
            class SBB_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SBB_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// M5InternalError::error((['"Tried to execute the ES segment override prefix!"'], {}))

// Inst::UD2([],{})

// WarnUnimpl::daa(([], {}))

// MultiInst::AND((['OPCODE_OP_BOTTOM3', ['Gb'], ['Gv'], [], [], [], []], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "and".
             */
            class AND_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                AND_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "and".
             */
            class AND_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                AND_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "and".
             */
            class AND_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                AND_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "and".
             */
            class AND_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                AND_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "and".
             */
            class AND_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                AND_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "and".
             */
            class AND_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                AND_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// M5InternalError::error((['"Tried to execute the CS segment override prefix!"'], {}))

// Inst::UD2([],{})

// WarnUnimpl::das(([], {}))

// MultiInst::SUB((['OPCODE_OP_BOTTOM3', ['Gb'], ['Gv'], [], [], [], []], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sub".
             */
            class SUB_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SUB_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sub".
             */
            class SUB_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SUB_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sub".
             */
            class SUB_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SUB_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sub".
             */
            class SUB_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SUB_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sub".
             */
            class SUB_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SUB_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sub".
             */
            class SUB_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SUB_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// M5InternalError::error((['"Tried to execute the SS segment override prefix!"'], {}))

// Inst::UD2([],{})

// WarnUnimpl::aaa(([], {}))

// MultiInst::XOR((['OPCODE_OP_BOTTOM3', ['Gb'], ['Gv'], [], [], [], []], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "xor".
             */
            class XOR_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                XOR_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "xor".
             */
            class XOR_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                XOR_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "xor".
             */
            class XOR_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                XOR_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "xor".
             */
            class XOR_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                XOR_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "xor".
             */
            class XOR_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                XOR_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "xor".
             */
            class XOR_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                XOR_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// M5InternalError::error((['"Tried to execute the DS segment override prefix!"'], {}))

// Inst::UD2([],{})

// WarnUnimpl::aas(([], {}))

// MultiInst::CMP((['OPCODE_OP_BOTTOM3', ['Gb'], ['Gv'], [], [], [], []], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmp".
             */
            class CMP_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMP_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmp".
             */
            class CMP_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMP_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmp".
             */
            class CMP_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMP_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmp".
             */
            class CMP_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMP_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmp".
             */
            class CMP_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMP_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmp".
             */
            class CMP_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMP_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// M5InternalError::error((['"Tried to execute an REX prefix!"'], {}))

// Inst::INC(['Bv'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "inc".
             */
            class INC_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                INC_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// M5InternalError::error((['"Tried to execute an REX prefix!"'], {}))

// Inst::DEC(['Bv'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "dec".
             */
            class DEC_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                DEC_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PUSH(['Bv'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "push".
             */
            class PUSH_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUSH_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::POP(['Bv'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pop".
             */
            class POP_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                POP_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::PUSHA([],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pusha".
             */
            class PUSHA : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUSHA(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::POPA([],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "popa".
             */
            class POPA : public Macroop
            {
              private:
                
              public:
                // Constructor.
                POPA(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::BOUND(['Gv', 'Mv'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "bound".
             */
            class BOUND_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BOUND_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "bound".
             */
            class BOUND_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BOUND_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVSXD(['Gv', 'Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movsxd".
             */
            class MOVSXD_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVSXD_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movsxd".
             */
            class MOVSXD_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVSXD_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movsxd".
             */
            class MOVSXD_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVSXD_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::arpl_Ew_Gw(([], {}))

// M5InternalError::error((['"Tried to execute the FS segment override prefix!"'], {}))

// M5InternalError::error((['"Tried to execute the GS segment override prefix!"'], {}))

// M5InternalError::error((['"Tried to execute the operand size override prefix!"'], {}))

// M5InternalError::error((['"Tried to execute the DS address size override prefix!"'], {}))

// Unknown::unknown(([], {}))

// Inst::PUSH(['Iz'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "push".
             */
            class PUSH_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUSH_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::IMUL(['Gv', 'Ev', 'Iz'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "imul".
             */
            class IMUL_R_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                IMUL_R_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "imul".
             */
            class IMUL_R_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                IMUL_R_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "imul".
             */
            class IMUL_R_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                IMUL_R_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PUSH(['Ib'],{})

// Inst::IMUL(['Gv', 'Ev', 'Ib'],{})

// StringInst::INS((['Yb', 'rD'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "ins".
             */
            class INS_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                INS_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "ins".
             */
            class INS_E_M_R : public Macroop
            {
              private:
                const static uint64_t label_end = 13;
const static uint64_t label_topOfLoop = 8;

              public:
                // Constructor.
                INS_E_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// StringInst::INS((['Yz', 'rD'], {}))

// StringInst::OUTS((['rD', 'Xb'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "outs".
             */
            class OUTS_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                OUTS_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "outs".
             */
            class OUTS_E_R_M : public Macroop
            {
              private:
                const static uint64_t label_end = 13;
const static uint64_t label_topOfLoop = 8;

              public:
                // Constructor.
                OUTS_E_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// StringInst::OUTS((['rD', 'Xz'], {}))

// Unknown::unknown(([], {}))

// Inst::JO(['Jb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "jo".
             */
            class JO_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                JO_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::JNO(['Jb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "jno".
             */
            class JNO_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                JNO_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::JB(['Jb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "jb".
             */
            class JB_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                JB_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::JNB(['Jb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "jnb".
             */
            class JNB_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                JNB_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::JZ(['Jb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "jz".
             */
            class JZ_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                JZ_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::JNZ(['Jb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "jnz".
             */
            class JNZ_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                JNZ_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::JBE(['Jb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "jbe".
             */
            class JBE_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                JBE_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::JNBE(['Jb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "jnbe".
             */
            class JNBE_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                JNBE_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::JS(['Jb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "js".
             */
            class JS_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                JS_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::JNS(['Jb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "jns".
             */
            class JNS_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                JNS_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::JP(['Jb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "jp".
             */
            class JP_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                JP_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::JNP(['Jb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "jnp".
             */
            class JNP_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                JNP_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::JL(['Jb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "jl".
             */
            class JL_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                JL_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::JNL(['Jb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "jnl".
             */
            class JNL_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                JNL_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::JLE(['Jb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "jle".
             */
            class JLE_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                JLE_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::JNLE(['Jb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "jnle".
             */
            class JNLE_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                JNLE_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::ADD(['Eb', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "add".
             */
            class ADD_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADD_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "add".
             */
            class ADD_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADD_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::OR(['Eb', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "or".
             */
            class OR_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                OR_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "or".
             */
            class OR_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                OR_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::ADC(['Eb', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "adc".
             */
            class ADC_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADC_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "adc".
             */
            class ADC_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADC_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SBB(['Eb', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sbb".
             */
            class SBB_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SBB_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sbb".
             */
            class SBB_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SBB_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::AND(['Eb', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "and".
             */
            class AND_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                AND_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "and".
             */
            class AND_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                AND_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SUB(['Eb', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sub".
             */
            class SUB_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SUB_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sub".
             */
            class SUB_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SUB_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::XOR(['Eb', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "xor".
             */
            class XOR_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                XOR_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "xor".
             */
            class XOR_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                XOR_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CMP(['Eb', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmp".
             */
            class CMP_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMP_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmp".
             */
            class CMP_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMP_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::ADD(['Ev', 'Iz'],{})

// Inst::OR(['Ev', 'Iz'],{})

// Inst::ADC(['Ev', 'Iz'],{})

// Inst::SBB(['Ev', 'Iz'],{})

// Inst::AND(['Ev', 'Iz'],{})

// Inst::SUB(['Ev', 'Iz'],{})

// Inst::XOR(['Ev', 'Iz'],{})

// Inst::CMP(['Ev', 'Iz'],{})

// Unknown::unknown(([], {}))

// Inst::UD2([],{})

// Inst::ADD(['Eb', 'Ib'],{})

// Inst::OR(['Eb', 'Ib'],{})

// Inst::ADC(['Eb', 'Ib'],{})

// Inst::SBB(['Eb', 'Ib'],{})

// Inst::AND(['Eb', 'Ib'],{})

// Inst::SUB(['Eb', 'Ib'],{})

// Inst::XOR(['Eb', 'Ib'],{})

// Inst::CMP(['Eb', 'Ib'],{})

// Unknown::unknown(([], {}))

// Inst::ADD(['Ev', 'Ib'],{})

// Inst::OR(['Ev', 'Ib'],{})

// Inst::ADC(['Ev', 'Ib'],{})

// Inst::SBB(['Ev', 'Ib'],{})

// Inst::AND(['Ev', 'Ib'],{})

// Inst::SUB(['Ev', 'Ib'],{})

// Inst::XOR(['Ev', 'Ib'],{})

// Inst::CMP(['Ev', 'Ib'],{})

// Unknown::unknown(([], {}))

// Inst::TEST(['Eb', 'Gb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "test".
             */
            class TEST_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                TEST_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "test".
             */
            class TEST_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                TEST_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "test".
             */
            class TEST_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                TEST_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::TEST(['Ev', 'Gv'],{})

// Inst::XCHG(['Eb', 'Gb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "xchg".
             */
            class XCHG_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                XCHG_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "xchg".
             */
            class XCHG_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                XCHG_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "xchg".
             */
            class XCHG_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                XCHG_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::XCHG(['Ev', 'Gv'],{})

// Unknown::unknown(([], {}))

// Inst::MOV(['Eb', 'Gb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mov".
             */
            class MOV_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOV_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mov".
             */
            class MOV_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOV_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mov".
             */
            class MOV_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOV_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOV(['Ev', 'Gv'],{})

// Inst::MOV(['Gb', 'Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mov".
             */
            class MOV_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOV_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mov".
             */
            class MOV_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOV_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOV(['Gv', 'Ev'],{})

// Inst::MOV(['Ev', 'Sv'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mov".
             */
            class MOV_R_S : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOV_R_S(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mov".
             */
            class MOV_M_S : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOV_M_S(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mov".
             */
            class MOV_P_S : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOV_P_S(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::LEA(['Gv', 'M'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "lea".
             */
            class LEA_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                LEA_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "lea".
             */
            class LEA_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                LEA_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOV_REAL(['Sv', 'Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mov".
             */
            class MOV_REAL_S_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOV_REAL_S_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mov".
             */
            class MOV_REAL_S_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOV_REAL_S_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mov".
             */
            class MOV_REAL_S_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOV_REAL_S_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::MOVSS(['Sv', 'Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movss".
             */
            class MOVSS_S_R : public Macroop
            {
              private:
                const static uint64_t label_processDescriptor = 8;
const static uint64_t label_globalDescriptor = 7;

              public:
                // Constructor.
                MOVSS_S_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movss".
             */
            class MOVSS_S_M : public Macroop
            {
              private:
                const static uint64_t label_processDescriptor = 9;
const static uint64_t label_globalDescriptor = 8;

              public:
                // Constructor.
                MOVSS_S_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movss".
             */
            class MOVSS_S_P : public Macroop
            {
              private:
                const static uint64_t label_processDescriptor = 10;
const static uint64_t label_globalDescriptor = 9;

              public:
                // Constructor.
                MOVSS_S_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOV(['Sv', 'Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mov".
             */
            class MOV_S_R : public Macroop
            {
              private:
                const static uint64_t label_processDescriptor = 8;
const static uint64_t label_globalDescriptor = 7;

              public:
                // Constructor.
                MOV_S_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mov".
             */
            class MOV_S_M : public Macroop
            {
              private:
                const static uint64_t label_processDescriptor = 9;
const static uint64_t label_globalDescriptor = 8;

              public:
                // Constructor.
                MOV_S_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mov".
             */
            class MOV_S_P : public Macroop
            {
              private:
                const static uint64_t label_processDescriptor = 10;
const static uint64_t label_globalDescriptor = 9;

              public:
                // Constructor.
                MOV_S_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::POP(['Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pop".
             */
            class POP_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                POP_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pop".
             */
            class POP_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                POP_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Unknown::unknown(([], {}))

// NopInst::NOP(([], {}))

        /**
         * Static instruction class for "NOP".
         */
        class NOP : public NopInst
        {
          public:
            // Constructor.
            NOP(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// Inst::XCHG(['Bv', 'rAv'],{})

// Inst::CDQE(['rAv'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cdqe".
             */
            class CDQE_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CDQE_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CQO(['rAv', 'rDv'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cqo".
             */
            class CQO_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CQO_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// WarnUnimpl::call_far_Ap(([], {}))

// WarnUnimpl::fwait(([], {}))

// Inst::PUSHF([],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pushf".
             */
            class PUSHF : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUSHF(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::POPF([],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "popf".
             */
            class POPF : public Macroop
            {
              private:
                
              public:
                // Constructor.
                POPF(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SAHF([],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sahf".
             */
            class SAHF : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SAHF(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::LAHF([],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "lahf".
             */
            class LAHF : public Macroop
            {
              private:
                
              public:
                // Constructor.
                LAHF(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::MOV(['rAb', 'Ob'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mov".
             */
            class MOV_R_MI : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOV_R_MI(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOV(['rAv', 'Ov'],{})

// Inst::MOV(['Ob', 'rAb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mov".
             */
            class MOV_MI_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOV_MI_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOV(['Ov', 'rAv'],{})

// StringInst::MOVS((['Yb', 'Xb'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movs".
             */
            class MOVS_M_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVS_M_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movs".
             */
            class MOVS_E_M_M : public Macroop
            {
              private:
                const static uint64_t label_end = 12;
const static uint64_t label_topOfLoop = 6;

              public:
                // Constructor.
                MOVS_E_M_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// StringInst::MOVS((['Yv', 'Xv'], {}))

// StringTestInst::CMPS((['Yb', 'Xb'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmps".
             */
            class CMPS_M_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMPS_M_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmps".
             */
            class CMPS_E_M_M : public Macroop
            {
              private:
                const static uint64_t label_end = 13;
const static uint64_t label_topOfLoop = 6;

              public:
                // Constructor.
                CMPS_E_M_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmps".
             */
            class CMPS_N_M_M : public Macroop
            {
              private:
                const static uint64_t label_end = 13;
const static uint64_t label_topOfLoop = 6;

              public:
                // Constructor.
                CMPS_N_M_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// StringTestInst::CMPS((['Yv', 'Xv'], {}))

// Unknown::unknown(([], {}))

// Inst::TEST(['rAb', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "test".
             */
            class TEST_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                TEST_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::TEST(['rAv', 'Iz'],{})

// StringInst::STOS((['Yb'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "stos".
             */
            class STOS_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                STOS_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "stos".
             */
            class STOS_E_M : public Macroop
            {
              private:
                const static uint64_t label_end = 10;
const static uint64_t label_topOfLoop = 6;

              public:
                // Constructor.
                STOS_E_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// StringInst::STOS((['Yv'], {}))

// StringInst::LODS((['Xb'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "lods".
             */
            class LODS_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                LODS_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "lods".
             */
            class LODS_E_M : public Macroop
            {
              private:
                const static uint64_t label_end = 10;
const static uint64_t label_topOfLoop = 6;

              public:
                // Constructor.
                LODS_E_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// StringInst::LODS((['Xv'], {}))

// StringTestInst::SCAS((['Yb'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "scas".
             */
            class SCAS_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SCAS_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "scas".
             */
            class SCAS_E_M : public Macroop
            {
              private:
                const static uint64_t label_end = 11;
const static uint64_t label_topOfLoop = 6;

              public:
                // Constructor.
                SCAS_E_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "scas".
             */
            class SCAS_N_M : public Macroop
            {
              private:
                const static uint64_t label_end = 11;
const static uint64_t label_topOfLoop = 6;

              public:
                // Constructor.
                SCAS_N_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// StringTestInst::SCAS((['Yv'], {}))

// Unknown::unknown(([], {}))

// Inst::MOV(['Bb', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mov".
             */
            class MOV_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOV_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOV(['Bv', 'Iv'],{})

// Inst::ROL(['Eb', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "rol".
             */
            class ROL_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ROL_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "rol".
             */
            class ROL_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ROL_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "rol".
             */
            class ROL_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ROL_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::ROR(['Eb', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "ror".
             */
            class ROR_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ROR_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "ror".
             */
            class ROR_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ROR_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "ror".
             */
            class ROR_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ROR_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::RCL(['Eb', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "rcl".
             */
            class RCL_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                RCL_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "rcl".
             */
            class RCL_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                RCL_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "rcl".
             */
            class RCL_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                RCL_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::RCR(['Eb', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "rcr".
             */
            class RCR_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                RCR_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "rcr".
             */
            class RCR_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                RCR_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "rcr".
             */
            class RCR_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                RCR_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SAL(['Eb', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sal".
             */
            class SAL_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SAL_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sal".
             */
            class SAL_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SAL_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sal".
             */
            class SAL_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SAL_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SHR(['Eb', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "shr".
             */
            class SHR_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SHR_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "shr".
             */
            class SHR_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SHR_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "shr".
             */
            class SHR_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SHR_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SAL(['Eb', 'Ib'],{})

// Inst::SAR(['Eb', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sar".
             */
            class SAR_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SAR_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sar".
             */
            class SAR_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SAR_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sar".
             */
            class SAR_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SAR_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::ROL(['Ev', 'Ib'],{})

// Inst::ROR(['Ev', 'Ib'],{})

// Inst::RCL(['Ev', 'Ib'],{})

// Inst::RCR(['Ev', 'Ib'],{})

// Inst::SAL(['Ev', 'Ib'],{})

// Inst::SHR(['Ev', 'Ib'],{})

// Inst::SAL(['Ev', 'Ib'],{})

// Inst::SAR(['Ev', 'Ib'],{})

// Unknown::unknown(([], {}))

// Inst::RET_NEAR(['Iw'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "ret".
             */
            class RET_NEAR_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                RET_NEAR_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::RET_NEAR([],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "ret".
             */
            class RET_NEAR : public Macroop
            {
              private:
                
              public:
                // Constructor.
                RET_NEAR(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// WarnUnimpl::les_Gz_Mp(([], {}))

// Inst::UD2([],{})

// WarnUnimpl::lds_Gz_Mp(([], {}))

// Inst::MOV(['Eb', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mov".
             */
            class MOV_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOV_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mov".
             */
            class MOV_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOV_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::MOV(['Ev', 'Iz'],{})

// Inst::UD2([],{})

// Unknown::unknown(([], {}))

// Inst::ENTER((['Iw', 'Iw'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "enter".
             */
            class ENTER_I_I : public Macroop
            {
              private:
                const static uint64_t label_bottomOfLoop = 18;
const static uint64_t label_topOfLoop = 12;
const static uint64_t label_skipLoop = 20;

              public:
                // Constructor.
                ENTER_I_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::LEAVE(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "leave".
             */
            class LEAVE : public Macroop
            {
              private:
                
              public:
                // Constructor.
                LEAVE(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::ret_far_Iw([],{})

// WarnUnimpl::ret_far_real([],{})

// Inst::RET_FAR(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "ret".
             */
            class RET_FAR : public Macroop
            {
              private:
                const static uint64_t label_processDescriptor = 13;
const static uint64_t label_globalDescriptor = 12;

              public:
                // Constructor.
                RET_FAR(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::INT3(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "int3".
             */
            class INT3 : public Macroop
            {
              private:
                
              public:
                // Constructor.
                INT3(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// SyscallInst::int80((['xc->syscall(Rax)', 'IsSyscall', 'IsNonSpeculative', 'IsSerializeAfter'], {}))

        /**
         * Static instruction class for "int80".
         */
        class Int80 : public SyscallInst
        {
          public:
            // Constructor.
            Int80(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// WarnUnimpl::inst_ib([],{})

// Inst::INT((['Ib'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "int".
             */
            class INT_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                INT_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2(([], {}))

// WarnUnimpl::into([],{})

// Inst::IRET_REAL(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "iret".
             */
            class IRET_REAL : public Macroop
            {
              private:
                
              public:
                // Constructor.
                IRET_REAL(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::IRET_VIRT(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "iret".
             */
            class IRET_VIRT : public Macroop
            {
              private:
                
              public:
                // Constructor.
                IRET_VIRT(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::IRET_PROT(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "iret".
             */
            class IRET_PROT : public Macroop
            {
              private:
                const static uint64_t label_fallThroughPopStackStuff = 52;
const static uint64_t label_globalCSDescriptor = 21;
const static uint64_t label_processCSDescriptor = 22;
const static uint64_t label_doPopStackStuff = 38;
const static uint64_t label_processSSDescriptor = 48;
const static uint64_t label_protToVirtFallThrough = 13;
const static uint64_t label_skipSegmentSquashing = 58;
const static uint64_t label_globalSSDescriptor = 47;
const static uint64_t label_doPopStackStuffAndCheckRIP = 34;

              public:
                // Constructor.
                IRET_PROT(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::ROL_1(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "rol".
             */
            class ROL_1_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ROL_1_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "rol".
             */
            class ROL_1_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ROL_1_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "rol".
             */
            class ROL_1_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ROL_1_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::ROR_1(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "ror".
             */
            class ROR_1_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ROR_1_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "ror".
             */
            class ROR_1_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ROR_1_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "ror".
             */
            class ROR_1_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ROR_1_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::RCL_1(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "rcl".
             */
            class RCL_1_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                RCL_1_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "rcl".
             */
            class RCL_1_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                RCL_1_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "rcl".
             */
            class RCL_1_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                RCL_1_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::RCR_1(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "rcr".
             */
            class RCR_1_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                RCR_1_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "rcr".
             */
            class RCR_1_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                RCR_1_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "rcr".
             */
            class RCR_1_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                RCR_1_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SAL_1(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sal".
             */
            class SAL_1_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SAL_1_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sal".
             */
            class SAL_1_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SAL_1_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sal".
             */
            class SAL_1_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SAL_1_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SHR_1(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "shr".
             */
            class SHR_1_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SHR_1_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "shr".
             */
            class SHR_1_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SHR_1_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "shr".
             */
            class SHR_1_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SHR_1_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SAL_1(['Eb'],{})

// Inst::SAR_1(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sar".
             */
            class SAR_1_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SAR_1_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sar".
             */
            class SAR_1_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SAR_1_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sar".
             */
            class SAR_1_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SAR_1_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::ROL_1(['Ev'],{})

// Inst::ROR_1(['Ev'],{})

// Inst::RCL_1(['Ev'],{})

// Inst::RCR_1(['Ev'],{})

// Inst::SAL_1(['Ev'],{})

// Inst::SHR_1(['Ev'],{})

// Inst::SAL_1(['Ev'],{})

// Inst::SAR_1(['Ev'],{})

// Unknown::unknown(([], {}))

// Inst::ROL(['Eb', 'rCb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "rol".
             */
            class ROL_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ROL_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "rol".
             */
            class ROL_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ROL_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "rol".
             */
            class ROL_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ROL_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::ROR(['Eb', 'rCb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "ror".
             */
            class ROR_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ROR_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "ror".
             */
            class ROR_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ROR_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "ror".
             */
            class ROR_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ROR_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::RCL(['Eb', 'rCb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "rcl".
             */
            class RCL_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                RCL_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "rcl".
             */
            class RCL_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                RCL_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "rcl".
             */
            class RCL_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                RCL_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::RCR(['Eb', 'rCb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "rcr".
             */
            class RCR_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                RCR_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "rcr".
             */
            class RCR_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                RCR_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "rcr".
             */
            class RCR_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                RCR_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SAL(['Eb', 'rCb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sal".
             */
            class SAL_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SAL_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sal".
             */
            class SAL_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SAL_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sal".
             */
            class SAL_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SAL_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SHR(['Eb', 'rCb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "shr".
             */
            class SHR_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SHR_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "shr".
             */
            class SHR_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SHR_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "shr".
             */
            class SHR_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SHR_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SAL(['Eb', 'rCb'],{})

// Inst::SAR(['Eb', 'rCb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sar".
             */
            class SAR_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SAR_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sar".
             */
            class SAR_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SAR_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sar".
             */
            class SAR_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SAR_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::ROL(['Ev', 'rCv'],{})

// Inst::ROR(['Ev', 'rCv'],{})

// Inst::RCL(['Ev', 'rCv'],{})

// Inst::RCR(['Ev', 'rCv'],{})

// Inst::SAL(['Ev', 'rCv'],{})

// Inst::SHR(['Ev', 'rCv'],{})

// Inst::SAL(['Ev', 'rCv'],{})

// Inst::SAR(['Ev', 'rCv'],{})

// Unknown::unknown(([], {}))

// Inst::UD2([],{})

// WarnUnimpl::aam_Ib(([], {}))

// Inst::UD2([],{})

// WarnUnimpl::aad_Ib(([], {}))

// Inst::UD2([],{})

// Inst::SALC(['rAb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "salc".
             */
            class SALC_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SALC_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::XLAT([],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "xlat".
             */
            class XLAT : public Macroop
            {
              private:
                
              public:
                // Constructor.
                XLAT(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::FADD1((['Eq'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fadd1".
             */
            class FADD1_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FADD1_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fadd1".
             */
            class FADD1_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FADD1_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fadd1".
             */
            class FADD1_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FADD1_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::FADD1((['Md'], {}))

// Inst::FMUL1((['Eq'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fmul1".
             */
            class FMUL1_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FMUL1_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fmul1".
             */
            class FMUL1_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FMUL1_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fmul1".
             */
            class FMUL1_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FMUL1_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::FMUL1((['Md'], {}))

// WarnUnimpl::fcom([],{})

// WarnUnimpl::fcomp([],{})

// Inst::FSUB1((['Eq'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fsub1".
             */
            class FSUB1_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FSUB1_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fsub1".
             */
            class FSUB1_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FSUB1_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fsub1".
             */
            class FSUB1_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FSUB1_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::FSUB1((['Md'], {}))

// WarnUnimpl::fsubr([],{})

// Inst::FDIV1((['Eq'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fdiv1".
             */
            class FDIV1_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FDIV1_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fdiv1".
             */
            class FDIV1_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FDIV1_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fdiv1".
             */
            class FDIV1_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FDIV1_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::FDIV1((['Md'], {}))

// WarnUnimpl::fdivr([],{})

// Unknown::unknown(([], {}))

// Inst::FLD((['Eq'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fld".
             */
            class FLD_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FLD_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fld".
             */
            class FLD_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FLD_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fld".
             */
            class FLD_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FLD_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::FLD((['Md'], {}))

// Inst::FXCH((['Eq'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fxch".
             */
            class FXCH_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FXCH_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fxch".
             */
            class FXCH_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FXCH_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fxch".
             */
            class FXCH_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FXCH_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2(([], {}))

// WarnUnimpl::fnop([],{})

// Inst::UD2(([], {}))

// Inst::FST((['Ed'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fst".
             */
            class FST_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FST_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fst".
             */
            class FST_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FST_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fst".
             */
            class FST_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FST_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2(([], {}))

// Inst::FSTP((['Ed'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fstp".
             */
            class FSTP_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FSTP_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fstp".
             */
            class FSTP_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FSTP_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fstp".
             */
            class FSTP_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FSTP_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::FCHS(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fchs".
             */
            class FCHS : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FCHS(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::FABS(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fabs".
             */
            class FABS : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FABS(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::ftst([],{})

// WarnUnimpl::fxam([],{})

// Inst::UD2(([], {}))

// Inst::FLDENV((['M'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fldenv".
             */
            class FLDENV_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FLDENV_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fldenv".
             */
            class FLDENV_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FLDENV_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::FLD1(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fld1".
             */
            class FLD1 : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FLD1(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::FLDL2T(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fldl2t".
             */
            class FLDL2T : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FLDL2T(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::FLDL2E(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fldl2e".
             */
            class FLDL2E : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FLDL2E(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::FLDPI(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fldpi".
             */
            class FLDPI : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FLDPI(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::FLDLG2(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fldlg2".
             */
            class FLDLG2 : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FLDLG2(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::FLDLN2(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fldln2".
             */
            class FLDLN2 : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FLDLN2(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::FLDZ(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fldz".
             */
            class FLDZ : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FLDZ(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::FLDCW((['Mw'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fldcw".
             */
            class FLDCW_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FLDCW_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fldcw".
             */
            class FLDCW_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FLDCW_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::f2xm1([],{})

// Inst::FYL2X(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fyl2x".
             */
            class FYL2X : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FYL2X(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::FPTAN(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fptan".
             */
            class FPTAN : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FPTAN(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::fpatan([],{})

// WarnUnimpl::fxtract([],{})

// Inst::FPREM1(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fprem1".
             */
            class FPREM1 : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FPREM1(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::fdecstp([],{})

// WarnUnimpl::fincstp([],{})

// Unknown::unknown(([], {}))

// Inst::FNSTENV((['M'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fnstenv".
             */
            class FNSTENV_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FNSTENV_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fnstenv".
             */
            class FNSTENV_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FNSTENV_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::FPREM(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fprem".
             */
            class FPREM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FPREM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::fyl2xp1([],{})

// WarnUnimpl::fsqrt([],{})

// Inst::FSINCOS(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fsincos".
             */
            class FSINCOS : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FSINCOS(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::frndint([],{})

// WarnUnimpl::fscale([],{})

// Inst::FSIN(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fsin".
             */
            class FSIN : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FSIN(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::FCOS(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fcos".
             */
            class FCOS : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FCOS(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::FNSTCW((['Mw'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fnstcw".
             */
            class FNSTCW_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FNSTCW_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fnstcw".
             */
            class FNSTCW_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FNSTCW_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// WarnUnimpl::fcmovb([],{})

// WarnUnimpl::fiadd([],{})

// WarnUnimpl::fcmove([],{})

// WarnUnimpl::fimul([],{})

// WarnUnimpl::fcmovbe([],{})

// WarnUnimpl::ficom([],{})

// WarnUnimpl::fcmovu([],{})

// WarnUnimpl::ficomp([],{})

// Inst::UD2(([], {}))

// WarnUnimpl::fisub([],{})

// WarnUnimpl::fucompp([],{})

// Inst::UD2(([], {}))

// WarnUnimpl::fisubr([],{})

// Inst::UD2(([], {}))

// WarnUnimpl::fidiv([],{})

// Inst::UD2(([], {}))

// WarnUnimpl::fidivr([],{})

// Unknown::unknown(([], {}))

// WarnUnimpl::fcmovnb([],{})

// WarnUnimpl::fild([],{})

// WarnUnimpl::fcmovne([],{})

// WarnUnimpl::fisttp([],{})

// WarnUnimpl::fcmovnbe([],{})

// WarnUnimpl::fist([],{})

// WarnUnimpl::fcmovnu([],{})

// WarnUnimpl::fistp([],{})

// WarnUnimpl::fnclex([],{})

// WarnUnimpl::fninit([],{})

// Inst::UD2(([], {}))

// Inst::UD2(([], {}))

// WarnUnimpl::fucomi([],{})

// Inst::FLD80((['M'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fld80".
             */
            class FLD80_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FLD80_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fld80".
             */
            class FLD80_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FLD80_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::fcomi([],{})

// Inst::UD2(([], {}))

// Inst::UD2(([], {}))

// Inst::FST80P((['M'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fst80p".
             */
            class FST80P_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FST80P_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fst80p".
             */
            class FST80P_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FST80P_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::FADD2((['Eq'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fadd2".
             */
            class FADD2_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FADD2_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fadd2".
             */
            class FADD2_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FADD2_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fadd2".
             */
            class FADD2_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FADD2_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::FADD2((['Mq'], {}))

// Inst::FMUL2((['Eq'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fmul2".
             */
            class FMUL2_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FMUL2_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fmul2".
             */
            class FMUL2_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FMUL2_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fmul2".
             */
            class FMUL2_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FMUL2_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::FMUL2((['Mq'], {}))

// Inst::UD2(([], {}))

// WarnUnimpl::fcom([],{})

// Inst::UD2(([], {}))

// WarnUnimpl::fcomp([],{})

// WarnUnimpl::fsubr([],{})

// Inst::FSUB2((['Mq'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fsub2".
             */
            class FSUB2_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FSUB2_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fsub2".
             */
            class FSUB2_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FSUB2_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::FSUB2((['Eq'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fsub2".
             */
            class FSUB2_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FSUB2_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::fsubr([],{})

// WarnUnimpl::fdivr([],{})

// Inst::FDIV2((['Mq'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fdiv2".
             */
            class FDIV2_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FDIV2_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fdiv2".
             */
            class FDIV2_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FDIV2_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::FDIV2((['Eq'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fdiv2".
             */
            class FDIV2_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FDIV2_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::fdivr([],{})

// Unknown::unknown(([], {}))

// WarnUnimpl::ffree([],{})

// Inst::FLD((['Mq'], {}))

// Inst::UD2(([], {}))

// WarnUnimpl::fisttp([],{})

// Inst::FST((['Eq'], {}))

// Inst::FST((['Mq'], {}))

// Inst::FSTP((['Eq'], {}))

// Inst::FSTP((['Mq'], {}))

// WarnUnimpl::fucom([],{})

// WarnUnimpl::frstor([],{})

// WarnUnimpl::fucomp([],{})

// Inst::UD2(([], {}))

// Inst::UD2(([], {}))

// WarnUnimpl::fnsave([],{})

// Inst::UD2(([], {}))

// Inst::FNSTSW((['Mw'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fnstsw".
             */
            class FNSTSW_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FNSTSW_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fnstsw".
             */
            class FNSTSW_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FNSTSW_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::FADDP(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "faddp".
             */
            class FADDP : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FADDP(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::FADDP((['Eq'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "faddp".
             */
            class FADDP_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FADDP_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "faddp".
             */
            class FADDP_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FADDP_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "faddp".
             */
            class FADDP_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FADDP_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::fiadd([],{})

// Inst::FMULP((['Eq'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fmulp".
             */
            class FMULP_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FMULP_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fmulp".
             */
            class FMULP_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FMULP_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fmulp".
             */
            class FMULP_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FMULP_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::fimul([],{})

// Inst::UD2(([], {}))

// WarnUnimpl::ficom([],{})

// WarnUnimpl::fcompp([],{})

// Inst::UD2(([], {}))

// WarnUnimpl::ficomp([],{})

// WarnUnimpl::fsubrp([],{})

// WarnUnimpl::fisub([],{})

// Inst::FSUBP(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fsubp".
             */
            class FSUBP : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FSUBP(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::FSUBP((['Eq'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fsubp".
             */
            class FSUBP_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FSUBP_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fsubp".
             */
            class FSUBP_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FSUBP_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fsubp".
             */
            class FSUBP_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FSUBP_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::fisubr([],{})

// WarnUnimpl::fdivrp([],{})

// WarnUnimpl::fidiv([],{})

// Inst::FDIVP((['Eq'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fdivp".
             */
            class FDIVP_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FDIVP_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fdivp".
             */
            class FDIVP_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FDIVP_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fdivp".
             */
            class FDIVP_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FDIVP_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::fidivr([],{})

// Unknown::unknown(([], {}))

// WarnUnimpl::ffreep([],{})

// WarnUnimpl::fild([],{})

// Inst::UD2(([], {}))

// WarnUnimpl::fisttp([],{})

// Inst::UD2(([], {}))

// WarnUnimpl::fist([],{})

// Inst::UD2(([], {}))

// WarnUnimpl::fistp([],{})

// Inst::FNSTSW((['rAw'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fnstsw".
             */
            class FNSTSW_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FNSTSW_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2(([], {}))

// WarnUnimpl::fbld([],{})

// WarnUnimpl::fucomip([],{})

// WarnUnimpl::fild([],{})

// WarnUnimpl::fcomip([],{})

// WarnUnimpl::fbstp([],{})

// Inst::UD2(([], {}))

// WarnUnimpl::fistp([],{})

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Inst::LOOPNE(['Jb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "loopne".
             */
            class LOOPNE_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                LOOPNE_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::LOOPE(['Jb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "loope".
             */
            class LOOPE_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                LOOPE_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::LOOP(['Jb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "loop".
             */
            class LOOP_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                LOOP_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::JRCX(['Jb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "jrcx".
             */
            class JRCX_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                JRCX_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::IN(['rAb', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "in".
             */
            class IN_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                IN_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::IN(['rAv', 'Iv'],{})

// Inst::OUT(['Ib', 'rAb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "out".
             */
            class OUT_I_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                OUT_I_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::OUT(['Iv', 'rAv'],{})

// Unknown::unknown(([], {}))

// Inst::CALL_NEAR(['Jz'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "call".
             */
            class CALL_NEAR_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CALL_NEAR_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::JMP(['Jz'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "jmp".
             */
            class JMP_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                JMP_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::JMP_FAR(['Iz'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "jmp".
             */
            class JMP_FAR_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                JMP_FAR_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::JMP_FAR(['Iz'],{})

// Inst::JMP_FAR_REAL(['Iz'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "jmp".
             */
            class JMP_FAR_REAL_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                JMP_FAR_REAL_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::JMP_FAR_REAL(['Iz'],{})

// Unknown::unknown(([], {}))

// Inst::JMP(['Jb'],{})

// Inst::IN(['rAb', 'rD'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "in".
             */
            class IN_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                IN_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::IN(['rAv', 'rD'],{})

// Inst::OUT(['rD', 'rAb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "out".
             */
            class OUT_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                OUT_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::OUT(['rD', 'rAv'],{})

// Unknown::unknown(([], {}))

// M5InternalError::error((['"Tried to execute the lock prefix!"'], {}))

// WarnUnimpl::int1(([], {}))

// M5InternalError::error((['"Tried to execute the repne prefix!"'], {}))

// M5InternalError::error((['"Tried to execute the rep/repe prefix!"'], {}))

// Inst::HLT([],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "hlt".
             */
            class HLT : public Macroop
            {
              private:
                
              public:
                // Constructor.
                HLT(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CMC([],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmc".
             */
            class CMC : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMC(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::TEST(['Eb', 'Iz'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "test".
             */
            class TEST_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                TEST_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "test".
             */
            class TEST_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                TEST_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::TEST(['Eb', 'Iz'],{})

// Inst::NOT(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "not".
             */
            class NOT_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                NOT_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "not".
             */
            class NOT_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                NOT_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "not".
             */
            class NOT_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                NOT_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::NEG(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "neg".
             */
            class NEG_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                NEG_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "neg".
             */
            class NEG_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                NEG_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "neg".
             */
            class NEG_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                NEG_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MUL_B(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mul".
             */
            class MUL_B_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MUL_B_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mul".
             */
            class MUL_B_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MUL_B_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mul".
             */
            class MUL_B_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MUL_B_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::IMUL_B(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "imul".
             */
            class IMUL_B_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                IMUL_B_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "imul".
             */
            class IMUL_B_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                IMUL_B_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "imul".
             */
            class IMUL_B_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                IMUL_B_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::DIV_B(['Ew'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "div".
             */
            class DIV_B_R : public Macroop
            {
              private:
                const static uint64_t label_divLoopTop = 3;

              public:
                // Constructor.
                DIV_B_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "div".
             */
            class DIV_B_M : public Macroop
            {
              private:
                const static uint64_t label_divLoopTop = 4;

              public:
                // Constructor.
                DIV_B_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "div".
             */
            class DIV_B_P : public Macroop
            {
              private:
                const static uint64_t label_divLoopTop = 5;

              public:
                // Constructor.
                DIV_B_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::IDIV_B(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "idiv".
             */
            class IDIV_B_R : public Macroop
            {
              private:
                const static uint64_t label_divLoopTop = 13;

              public:
                // Constructor.
                IDIV_B_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "idiv".
             */
            class IDIV_B_M : public Macroop
            {
              private:
                const static uint64_t label_divLoopTop = 14;

              public:
                // Constructor.
                IDIV_B_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "idiv".
             */
            class IDIV_B_P : public Macroop
            {
              private:
                const static uint64_t label_divLoopTop = 15;

              public:
                // Constructor.
                IDIV_B_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::TEST(['Ev', 'Iz'],{})

// Inst::TEST(['Ev', 'Iz'],{})

// Inst::NOT(['Ev'],{})

// Inst::NEG(['Ev'],{})

// Inst::MUL(['Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mul".
             */
            class MUL_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MUL_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mul".
             */
            class MUL_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MUL_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mul".
             */
            class MUL_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MUL_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::IMUL(['Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "imul".
             */
            class IMUL_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                IMUL_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "imul".
             */
            class IMUL_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                IMUL_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "imul".
             */
            class IMUL_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                IMUL_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::DIV(['Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "div".
             */
            class DIV_R : public Macroop
            {
              private:
                const static uint64_t label_divLoopTop = 3;

              public:
                // Constructor.
                DIV_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "div".
             */
            class DIV_M : public Macroop
            {
              private:
                const static uint64_t label_divLoopTop = 4;

              public:
                // Constructor.
                DIV_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "div".
             */
            class DIV_P : public Macroop
            {
              private:
                const static uint64_t label_divLoopTop = 5;

              public:
                // Constructor.
                DIV_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::IDIV(['Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "idiv".
             */
            class IDIV_R : public Macroop
            {
              private:
                const static uint64_t label_divLoopTop = 13;

              public:
                // Constructor.
                IDIV_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "idiv".
             */
            class IDIV_M : public Macroop
            {
              private:
                const static uint64_t label_divLoopTop = 14;

              public:
                // Constructor.
                IDIV_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "idiv".
             */
            class IDIV_P : public Macroop
            {
              private:
                const static uint64_t label_divLoopTop = 15;

              public:
                // Constructor.
                IDIV_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Inst::CLC([],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "clc".
             */
            class CLC : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CLC(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::STC([],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "stc".
             */
            class STC : public Macroop
            {
              private:
                
              public:
                // Constructor.
                STC(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CLI([],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cli".
             */
            class CLI : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CLI(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::STI([],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sti".
             */
            class STI : public Macroop
            {
              private:
                
              public:
                // Constructor.
                STI(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CLD([],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cld".
             */
            class CLD : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CLD(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::STD([],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "std".
             */
            class STD : public Macroop
            {
              private:
                
              public:
                // Constructor.
                STD(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::INC(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "inc".
             */
            class INC_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                INC_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "inc".
             */
            class INC_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                INC_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::DEC(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "dec".
             */
            class DEC_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                DEC_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "dec".
             */
            class DEC_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                DEC_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::INC(['Ev'],{})

// Inst::DEC(['Ev'],{})

// Inst::CALL_NEAR(['Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "call".
             */
            class CALL_NEAR_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CALL_NEAR_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "call".
             */
            class CALL_NEAR_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CALL_NEAR_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "call".
             */
            class CALL_NEAR_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CALL_NEAR_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::call_far_Mp(([], {}))

// Inst::JMP(['Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "jmp".
             */
            class JMP_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                JMP_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "jmp".
             */
            class JMP_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                JMP_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "jmp".
             */
            class JMP_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                JMP_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::JMP_FAR(['Mz'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "jmp".
             */
            class JMP_FAR_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                JMP_FAR_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "jmp".
             */
            class JMP_FAR_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                JMP_FAR_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::JMP_FAR(['Mz'],{})

// Inst::JMP_FAR(['Mz'],{})

// Inst::JMP_FAR_REAL(['Mz'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "jmp".
             */
            class JMP_FAR_REAL_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                JMP_FAR_REAL_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "jmp".
             */
            class JMP_FAR_REAL_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                JMP_FAR_REAL_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::JMP_FAR_REAL(['Mz'],{})

// Unknown::unknown(([], {}))

// Inst::PUSH(['Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "push".
             */
            class PUSH_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUSH_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "push".
             */
            class PUSH_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUSH_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// FailUnimpl::oneByteOps(([], {}))

// WarnUnimpl::sldt_Mw_or_Rv([],{})

// WarnUnimpl::str_Mw_or_Rv([],{})

// Inst::LLDT((['Ew'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "lldt".
             */
            class LLDT_R : public Macroop
            {
              private:
                const static uint64_t label_end = 10;

              public:
                // Constructor.
                LLDT_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "lldt".
             */
            class LLDT_M : public Macroop
            {
              private:
                const static uint64_t label_end = 11;

              public:
                // Constructor.
                LLDT_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "lldt".
             */
            class LLDT_P : public Macroop
            {
              private:
                const static uint64_t label_end = 12;

              public:
                // Constructor.
                LLDT_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::LTR((['Ew'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "ltr".
             */
            class LTR_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                LTR_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "ltr".
             */
            class LTR_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                LTR_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "ltr".
             */
            class LTR_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                LTR_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::verr_Mw_or_Rv([],{})

// WarnUnimpl::verw_Mw_or_Rv([],{})

// Inst::UD2(([], {}))

// WarnUnimpl::vmcall([],{})

// WarnUnimpl::vmlaunch([],{})

// WarnUnimpl::vmresume([],{})

// WarnUnimpl::vmxoff([],{})

// Inst::UD2(([], {}))

// WarnUnimpl::sgdt_Ms([],{})

// MonitorInst::monitor((['\n                           xc->armMonitor(Rax);\n                        '], {}))

        /**
         * Static instruction class for "monitor".
         */
        class Monitor : public MonitorInst
        {
          public:
            // Constructor.
            Monitor(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// MwaitInst::mwait((['\n                           uint64_t m = 0;          //mem\n                           unsigned s = 0x8;        //size\n                           unsigned f = 0;          //flags\n                           readMemAtomic(xc, traceData,\n                                         xc->getAddrMonitor()->vAddr,\n                                         m, s, f);\n                           xc->mwaitAtomic(xc->tcBase());\n                           MicroHalt hltObj(machInst, mnemonic, 0x0);\n                           hltObj.execute(xc, traceData);\n                        '], {}))

    class Mwait : public MwaitInst
    {
        public:
        // Constructor.
        Mwait(ExtMachInst machInst);
        
    Fault execute(ExecContext *, Trace::InstRecord *) const;
    Fault initiateAcc(ExecContext *, Trace::InstRecord *) const;
    Fault completeAcc(PacketPtr, ExecContext *,
                      Trace::InstRecord *) const;

    };

// Inst::UD2(([], {}))

// WarnUnimpl::sidt_Ms([],{})

// WarnUnimpl::xgetbv([],{})

// WarnUnimpl::xsetbv([],{})

// Unknown::unknown(([], {}))

// Inst::LGDT((['M'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "lgdt".
             */
            class LGDT_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                LGDT_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "lgdt".
             */
            class LGDT_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                LGDT_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::LGDT_16((['M'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "lgdt".
             */
            class LGDT_16_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                LGDT_16_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "lgdt".
             */
            class LGDT_16_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                LGDT_16_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::LGDT((['M'], {}))

// WarnUnimpl::vmrun([],{})

// WarnUnimpl::vmmcall([],{})

// WarnUnimpl::vmload([],{})

// WarnUnimpl::vmsave([],{})

// WarnUnimpl::stgi([],{})

// WarnUnimpl::clgi([],{})

// WarnUnimpl::skinit([],{})

// WarnUnimpl::invlpga([],{})

// Unknown::unknown(([], {}))

// Inst::LIDT((['M'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "lidt".
             */
            class LIDT_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                LIDT_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "lidt".
             */
            class LIDT_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                LIDT_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::LIDT_16((['M'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "lidt".
             */
            class LIDT_16_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                LIDT_16_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "lidt".
             */
            class LIDT_16_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                LIDT_16_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::LIDT((['M'], {}))

// Inst::SMSW((['Rv'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "smsw".
             */
            class SMSW_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SMSW_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SMSW((['Mw'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "smsw".
             */
            class SMSW_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SMSW_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "smsw".
             */
            class SMSW_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SMSW_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::LMSW((['Ew'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "lmsw".
             */
            class LMSW_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                LMSW_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "lmsw".
             */
            class LMSW_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                LMSW_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "lmsw".
             */
            class LMSW_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                LMSW_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SWAPGS(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "swapgs".
             */
            class SWAPGS : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SWAPGS(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::rdtscp([],{})

// Inst::UD2(([], {}))

// Inst::INVLPG((['M'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "invlpg".
             */
            class INVLPG_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                INVLPG_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "invlpg".
             */
            class INVLPG_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                INVLPG_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// WarnUnimpl::lar_Gv_Ew([],{})

// WarnUnimpl::lsl_Gv_Ew([],{})

// BasicOperate::m5arm(['\n                        PseudoInst::arm(xc->tcBase());\n                    ', 'IsNonSpeculative'],{})

        /**
         * Static instruction class for "m5arm".
         */
        class M5arm : public X86ISA::X86StaticInst
        {
          public:
            // Constructor.
            M5arm(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// BasicOperate::m5quiesce(['\n                        PseudoInst::quiesce(xc->tcBase());\n                    ', 'IsNonSpeculative', 'IsQuiesce'],{})

        /**
         * Static instruction class for "m5quiesce".
         */
        class M5quiesce : public X86ISA::X86StaticInst
        {
          public:
            // Constructor.
            M5quiesce(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// BasicOperate::m5quiesceNs(['\n                        PseudoInst::quiesceNs(xc->tcBase(), Rdi);\n                    ', 'IsNonSpeculative', 'IsQuiesce'],{})

        /**
         * Static instruction class for "m5quiesceNs".
         */
        class M5quiesceNs : public X86ISA::X86StaticInst
        {
          public:
            // Constructor.
            M5quiesceNs(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// BasicOperate::m5quiesceCycle(['\n                        PseudoInst::quiesceCycles(xc->tcBase(), Rdi);\n                    ', 'IsNonSpeculative', 'IsQuiesce'],{})

        /**
         * Static instruction class for "m5quiesceCycle".
         */
        class M5quiesceCycle : public X86ISA::X86StaticInst
        {
          public:
            // Constructor.
            M5quiesceCycle(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// BasicOperate::m5quiesceTime(['\n                        Rax = PseudoInst::quiesceTime(xc->tcBase());\n                    ', 'IsNonSpeculative'],{})

        /**
         * Static instruction class for "m5quiesceTime".
         */
        class M5quiesceTime : public X86ISA::X86StaticInst
        {
          public:
            // Constructor.
            M5quiesceTime(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// BasicOperate::m5rpns(['\n                        Rax = PseudoInst::rpns(xc->tcBase());\n                    ', 'IsNonSpeculative'],{})

        /**
         * Static instruction class for "m5rpns".
         */
        class M5rpns : public X86ISA::X86StaticInst
        {
          public:
            // Constructor.
            M5rpns(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// BasicOperate::m5exit(['\n                        PseudoInst::m5exit(xc->tcBase(), Rdi);\n                    ', 'IsNonSpeculative'],{})

        /**
         * Static instruction class for "m5exit".
         */
        class M5exit : public X86ISA::X86StaticInst
        {
          public:
            // Constructor.
            M5exit(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// BasicOperate::m5fail(['\n                        PseudoInst::m5fail(xc->tcBase(), Rdi, Rsi);\n                    ', 'IsNonSpeculative'],{})

        /**
         * Static instruction class for "m5fail".
         */
        class M5fail : public X86ISA::X86StaticInst
        {
          public:
            // Constructor.
            M5fail(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// BasicOperate::m5initparam(['\n                        Rax = PseudoInst::initParam(xc->tcBase());\n                    ', 'IsNonSpeculative'],{})

        /**
         * Static instruction class for "m5initparam".
         */
        class M5initparam : public X86ISA::X86StaticInst
        {
          public:
            // Constructor.
            M5initparam(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// BasicOperate::m5loadsymbol(['\n                        PseudoInst::loadsymbol(xc->tcBase());\n                    ', 'IsNonSpeculative'],{})

        /**
         * Static instruction class for "m5loadsymbol".
         */
        class M5loadsymbol : public X86ISA::X86StaticInst
        {
          public:
            // Constructor.
            M5loadsymbol(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// BasicOperate::m5resetstats(['\n                        PseudoInst::resetstats(xc->tcBase(), Rdi, Rsi);\n                    ', 'IsNonSpeculative'],{})

        /**
         * Static instruction class for "m5resetstats".
         */
        class M5resetstats : public X86ISA::X86StaticInst
        {
          public:
            // Constructor.
            M5resetstats(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// BasicOperate::m5dumpstats(['\n                        PseudoInst::dumpstats(xc->tcBase(), Rdi, Rsi);\n                    ', 'IsNonSpeculative'],{})

        /**
         * Static instruction class for "m5dumpstats".
         */
        class M5dumpstats : public X86ISA::X86StaticInst
        {
          public:
            // Constructor.
            M5dumpstats(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// BasicOperate::m5dumpresetstats(['\n                        PseudoInst::dumpresetstats(xc->tcBase(), Rdi, Rsi);\n                    ', 'IsNonSpeculative'],{})

        /**
         * Static instruction class for "m5dumpresetstats".
         */
        class M5dumpresetstats : public X86ISA::X86StaticInst
        {
          public:
            // Constructor.
            M5dumpresetstats(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// BasicOperate::m5checkpoint(['\n                        PseudoInst::m5checkpoint(xc->tcBase(), Rdi, Rsi);\n                    ', 'IsNonSpeculative'],{})

        /**
         * Static instruction class for "m5checkpoint".
         */
        class M5checkpoint : public X86ISA::X86StaticInst
        {
          public:
            // Constructor.
            M5checkpoint(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// BasicOperate::m5readfile(['\n                        Rax = PseudoInst::readfile(\n                            xc->tcBase(), Rdi, Rsi, Rdx);\n                    ', 'IsNonSpeculative'],{})

        /**
         * Static instruction class for "m5readfile".
         */
        class M5readfile : public X86ISA::X86StaticInst
        {
          public:
            // Constructor.
            M5readfile(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// BasicOperate::m5debugbreak(['\n                        PseudoInst::debugbreak(xc->tcBase());\n                    ', 'IsNonSpeculative'],{})

        /**
         * Static instruction class for "m5debugbreak".
         */
        class M5debugbreak : public X86ISA::X86StaticInst
        {
          public:
            // Constructor.
            M5debugbreak(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// BasicOperate::m5switchcpu(['\n                        PseudoInst::switchcpu(xc->tcBase());\n                    ', 'IsNonSpeculative'],{})

        /**
         * Static instruction class for "m5switchcpu".
         */
        class M5switchcpu : public X86ISA::X86StaticInst
        {
          public:
            // Constructor.
            M5switchcpu(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// BasicOperate::m5addsymbol(['\n                        PseudoInst::addsymbol(xc->tcBase(), Rdi, Rsi);\n                    ', 'IsNonSpeculative'],{})

        /**
         * Static instruction class for "m5addsymbol".
         */
        class M5addsymbol : public X86ISA::X86StaticInst
        {
          public:
            // Constructor.
            M5addsymbol(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// BasicOperate::m5panic(['\n                        panic("M5 panic instruction called at pc = %#x.\\n",\n                              RIP);\n                    ', 'IsNonSpeculative'],{})

        /**
         * Static instruction class for "m5panic".
         */
        class M5panic : public X86ISA::X86StaticInst
        {
          public:
            // Constructor.
            M5panic(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// BasicOperate::m5reserved1(['\n                        warn("M5 reserved opcode 1 ignored.\\n");\n                    ', 'IsNonSpeculative'],{})

        /**
         * Static instruction class for "m5reserved1".
         */
        class M5reserved1 : public X86ISA::X86StaticInst
        {
          public:
            // Constructor.
            M5reserved1(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// BasicOperate::m5reserved2(['\n                        warn("M5 reserved opcode 2 ignored.\\n");\n                    ', 'IsNonSpeculative'],{})

        /**
         * Static instruction class for "m5reserved2".
         */
        class M5reserved2 : public X86ISA::X86StaticInst
        {
          public:
            // Constructor.
            M5reserved2(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// BasicOperate::m5reserved3(['\n                        warn("M5 reserved opcode 3 ignored.\\n");\n                    ', 'IsNonSpeculative'],{})

        /**
         * Static instruction class for "m5reserved3".
         */
        class M5reserved3 : public X86ISA::X86StaticInst
        {
          public:
            // Constructor.
            M5reserved3(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// BasicOperate::m5reserved4(['\n                        warn("M5 reserved opcode 4 ignored.\\n");\n                    ', 'IsNonSpeculative'],{})

        /**
         * Static instruction class for "m5reserved4".
         */
        class M5reserved4 : public X86ISA::X86StaticInst
        {
          public:
            // Constructor.
            M5reserved4(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// BasicOperate::m5reserved5(['\n                        warn("M5 reserved opcode 5 ignored.\\n");\n                    ', 'IsNonSpeculative'],{})

        /**
         * Static instruction class for "m5reserved5".
         */
        class M5reserved5 : public X86ISA::X86StaticInst
        {
          public:
            // Constructor.
            M5reserved5(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// BasicOperate::m5_work_begin(['\n                        PseudoInst::workbegin(xc->tcBase(), Rdi, Rsi);\n                    ', 'IsNonSpeculative'],{})

        /**
         * Static instruction class for "m5_work_begin".
         */
        class M5_work_begin : public X86ISA::X86StaticInst
        {
          public:
            // Constructor.
            M5_work_begin(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// BasicOperate::m5_work_end(['\n                        PseudoInst::workend(xc->tcBase(), Rdi, Rsi);\n                    ', 'IsNonSpeculative'],{})

        /**
         * Static instruction class for "m5_work_end".
         */
        class M5_work_end : public X86ISA::X86StaticInst
        {
          public:
            // Constructor.
            M5_work_end(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// Inst::UD2(([], {}))

// SyscallInst::syscall((['xc->syscall(Rax)', 'IsSyscall', 'IsNonSpeculative', 'IsSerializeAfter'], {}))

        /**
         * Static instruction class for "syscall".
         */
        class Syscall : public SyscallInst
        {
          public:
            // Constructor.
            Syscall(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// Inst::SYSCALL_64(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "syscall".
             */
            class SYSCALL_64 : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SYSCALL_64(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SYSCALL_COMPAT(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "syscall".
             */
            class SYSCALL_COMPAT : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SYSCALL_COMPAT(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::SYSCALL_LEGACY(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "syscall".
             */
            class SYSCALL_LEGACY : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SYSCALL_LEGACY(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::CLTS(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "clts".
             */
            class CLTS : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CLTS(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SYSRET_TO_64(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sysret".
             */
            class SYSRET_TO_64 : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SYSRET_TO_64(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SYSRET_TO_COMPAT(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sysret".
             */
            class SYSRET_TO_COMPAT : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SYSRET_TO_COMPAT(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SYSRET_NON_64(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sysret".
             */
            class SYSRET_NON_64 : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SYSRET_NON_64(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// WarnUnimpl::invd([],{})

// WarnUnimpl::wbinvd([],{})

// Inst::UD2(([], {}))

// Inst::UD2(([], {}))

// Inst::UD2(([], {}))

// Inst::PREFETCH((['Mb'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "prefetch".
             */
            class PREFETCH_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PREFETCH_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "prefetch".
             */
            class PREFETCH_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PREFETCH_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// FailUnimpl::femms(([], {}))

// WarnUnimpl::pi2fw_Pq_Qq([],{})

// WarnUnimpl::pi2fd_Pq_Qq([],{})

// WarnUnimpl::pf2iw_Pq_Qq([],{})

// WarnUnimpl::pf2id_Pq_Qq([],{})

// WarnUnimpl::pfnacc_Pq_Qq([],{})

// WarnUnimpl::pfpnacc_Pq_Qq([],{})

// WarnUnimpl::pfcmpge_Pq_Qq([],{})

// WarnUnimpl::pfmin_Pq_Qq([],{})

// WarnUnimpl::pfrcp_Pq_Qq([],{})

// WarnUnimpl::pfrsqrt_Pq_Qq([],{})

// Inst::PFSUB((['Pq', 'Qq'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pfsub".
             */
            class PFSUB_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PFSUB_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pfsub".
             */
            class PFSUB_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PFSUB_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pfsub".
             */
            class PFSUB_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PFSUB_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::pfadd_Pq_Qq([],{})

// WarnUnimpl::pfcmpgt_Pq_Qq([],{})

// WarnUnimpl::pfmax_Pq_Qq([],{})

// WarnUnimpl::pfrcpit1_Pq_Qq([],{})

// WarnUnimpl::pfrsqit1_Pq_Qq([],{})

// Inst::PFSUBR((['Pq', 'Qq'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pfsubr".
             */
            class PFSUBR_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PFSUBR_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pfsubr".
             */
            class PFSUBR_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PFSUBR_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pfsubr".
             */
            class PFSUBR_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PFSUBR_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::pfacc_Pq_Qq([],{})

// WarnUnimpl::pfcmpeq_Pq_Qq([],{})

// Inst::PFMUL((['Pq', 'Qq'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pfmul".
             */
            class PFMUL_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PFMUL_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pfmul".
             */
            class PFMUL_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PFMUL_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pfmul".
             */
            class PFMUL_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PFMUL_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::pfrcpit2_Pq_Qq([],{})

// Inst::PMULHRW((['Pq', 'Qq'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmulhrw".
             */
            class PMULHRW_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMULHRW_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmulhrw".
             */
            class PMULHRW_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMULHRW_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmulhrw".
             */
            class PMULHRW_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMULHRW_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::pswapd_Pq_Qq([],{})

// WarnUnimpl::pavgusb_Pq_Qq([],{})

// Inst::UD2(([], {}))

// Unknown::unknown(([], {}))

// Inst::MOVUPS(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movups".
             */
            class MOVUPS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVUPS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movups".
             */
            class MOVUPS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVUPS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movups".
             */
            class MOVUPS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVUPS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVUPS(['Wo', 'Vo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movups".
             */
            class MOVUPS_M_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVUPS_M_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movups".
             */
            class MOVUPS_P_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVUPS_P_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVHLPS(['Vps', 'VRq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movhlps".
             */
            class MOVHLPS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVHLPS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVLPS(['Vps', 'Mq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movlps".
             */
            class MOVLPS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVLPS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movlps".
             */
            class MOVLPS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVLPS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVLPS(['Mq', 'Vps'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movlps".
             */
            class MOVLPS_M_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVLPS_M_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movlps".
             */
            class MOVLPS_P_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVLPS_P_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UNPCKLPS(['Vps', 'Wq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "unpcklps".
             */
            class UNPCKLPS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                UNPCKLPS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "unpcklps".
             */
            class UNPCKLPS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                UNPCKLPS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "unpcklps".
             */
            class UNPCKLPS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                UNPCKLPS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UNPCKHPS(['Vps', 'Wq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "unpckhps".
             */
            class UNPCKHPS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                UNPCKHPS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "unpckhps".
             */
            class UNPCKHPS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                UNPCKHPS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "unpckhps".
             */
            class UNPCKHPS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                UNPCKHPS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVLHPS(['Vps', 'VRq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movlhps".
             */
            class MOVLHPS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVLHPS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVHPS(['Vps', 'Mq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movhps".
             */
            class MOVHPS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVHPS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movhps".
             */
            class MOVHPS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVHPS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVHPS(['Mq', 'Vq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movhps".
             */
            class MOVHPS_M_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVHPS_M_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movhps".
             */
            class MOVHPS_P_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVHPS_P_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::MOVSS(['Vd', 'Wd'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movss".
             */
            class MOVSS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVSS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movss".
             */
            class MOVSS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVSS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movss".
             */
            class MOVSS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVSS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVSS(['Wd', 'Vd'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movss".
             */
            class MOVSS_M_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVSS_M_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movss".
             */
            class MOVSS_P_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVSS_P_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::movsldup_Vo_Wo(([], {}))

// WarnUnimpl::movshdup_Vo_Wo(([], {}))

// Inst::UD2([],{})

// Inst::MOVUPD(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movupd".
             */
            class MOVUPD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVUPD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movupd".
             */
            class MOVUPD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVUPD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movupd".
             */
            class MOVUPD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVUPD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVUPD(['Wo', 'Vo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movupd".
             */
            class MOVUPD_M_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVUPD_M_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movupd".
             */
            class MOVUPD_P_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVUPD_P_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVLPD(['Vq', 'Mq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movlpd".
             */
            class MOVLPD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVLPD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movlpd".
             */
            class MOVLPD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVLPD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVLPD(['Mq', 'Vq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movlpd".
             */
            class MOVLPD_M_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVLPD_M_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movlpd".
             */
            class MOVLPD_P_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVLPD_P_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UNPCKLPD(['Vo', 'Wq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "unpcklpd".
             */
            class UNPCKLPD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                UNPCKLPD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "unpcklpd".
             */
            class UNPCKLPD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                UNPCKLPD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "unpcklpd".
             */
            class UNPCKLPD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                UNPCKLPD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UNPCKHPD(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "unpckhpd".
             */
            class UNPCKHPD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                UNPCKHPD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "unpckhpd".
             */
            class UNPCKHPD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                UNPCKHPD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "unpckhpd".
             */
            class UNPCKHPD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                UNPCKHPD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVHPD(['Vq', 'Mq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movhpd".
             */
            class MOVHPD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVHPD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movhpd".
             */
            class MOVHPD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVHPD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVHPD(['Mq', 'Vq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movhpd".
             */
            class MOVHPD_M_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVHPD_M_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movhpd".
             */
            class MOVHPD_P_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVHPD_P_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::MOVSD(['Vq', 'Wq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movsd".
             */
            class MOVSD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVSD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movsd".
             */
            class MOVSD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVSD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movsd".
             */
            class MOVSD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVSD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVSD(['Wq', 'Vq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movsd".
             */
            class MOVSD_M_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVSD_M_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movsd".
             */
            class MOVSD_P_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVSD_P_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVDDUP(['Vo', 'Wq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movddup".
             */
            class MOVDDUP_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVDDUP_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movddup".
             */
            class MOVDDUP_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVDDUP_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movddup".
             */
            class MOVDDUP_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVDDUP_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::UD2([],{})

// WarnUnimpl::prefetch_nta(([], {}))

// Inst::PREFETCH_T0(['Mb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "prefetch".
             */
            class PREFETCH_T0_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PREFETCH_T0_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "prefetch".
             */
            class PREFETCH_T0_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PREFETCH_T0_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::prefetch_t1(([], {}))

// WarnUnimpl::prefetch_t2(([], {}))

// Inst::HINT_NOP([],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "hint".
             */
            class HINT_NOP : public Macroop
            {
              private:
                
              public:
                // Constructor.
                HINT_NOP(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::HINT_NOP([],{})

// Inst::HINT_NOP([],{})

// Inst::HINT_NOP([],{})

// Inst::HINT_NOP([],{})

// Inst::HINT_NOP([],{})

// Inst::HINT_NOP([],{})

// Inst::HINT_NOP([],{})

// Unknown::unknown(([], {}))

// Inst::MOV(['Rd', 'Cd'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mov".
             */
            class MOV_R_C : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOV_R_C(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOV(['Rd', 'Dd'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mov".
             */
            class MOV_R_D : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOV_R_D(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOV(['Cd', 'Rd'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mov".
             */
            class MOV_C_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOV_C_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOV(['Dd', 'Rd'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mov".
             */
            class MOV_D_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOV_D_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::UD2([],{})

// Inst::MOVAPS(['Vq', 'Wq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movaps".
             */
            class MOVAPS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVAPS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movaps".
             */
            class MOVAPS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVAPS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movaps".
             */
            class MOVAPS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVAPS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVAPS(['Wq', 'Vq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movaps".
             */
            class MOVAPS_M_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVAPS_M_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movaps".
             */
            class MOVAPS_P_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVAPS_P_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CVTPI2PS(['Vq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtpi2ps".
             */
            class CVTPI2PS_XMM_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTPI2PS_XMM_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtpi2ps".
             */
            class CVTPI2PS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTPI2PS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtpi2ps".
             */
            class CVTPI2PS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTPI2PS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::movntps_Mo_Vo(([], {}))

// Inst::CVTTPS2PI(['Pq', 'Wq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvttps2pi".
             */
            class CVTTPS2PI_MMX_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTTPS2PI_MMX_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvttps2pi".
             */
            class CVTTPS2PI_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTTPS2PI_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvttps2pi".
             */
            class CVTTPS2PI_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTTPS2PI_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CVTPS2PI(['Pq', 'Wq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtps2pi".
             */
            class CVTPS2PI_MMX_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTPS2PI_MMX_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtps2pi".
             */
            class CVTPS2PI_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTPS2PI_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtps2pi".
             */
            class CVTPS2PI_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTPS2PI_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UCOMISS(['Vd', 'Wd'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "ucomiss".
             */
            class UCOMISS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                UCOMISS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "ucomiss".
             */
            class UCOMISS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                UCOMISS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "ucomiss".
             */
            class UCOMISS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                UCOMISS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::COMISS(['Vd', 'Wd'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "comiss".
             */
            class COMISS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                COMISS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "comiss".
             */
            class COMISS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                COMISS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "comiss".
             */
            class COMISS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                COMISS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::CVTSI2SS(['Vd', 'Ed'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtsi2ss".
             */
            class CVTSI2SS_XMM_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTSI2SS_XMM_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtsi2ss".
             */
            class CVTSI2SS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTSI2SS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtsi2ss".
             */
            class CVTSI2SS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTSI2SS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CVTTSS2SI(['Gd', 'Wd'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvttss2si".
             */
            class CVTTSS2SI_R_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTTSS2SI_R_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvttss2si".
             */
            class CVTTSS2SI_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTTSS2SI_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvttss2si".
             */
            class CVTTSS2SI_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTTSS2SI_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CVTSS2SI(['Gd', 'Wd'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtss2si".
             */
            class CVTSS2SI_R_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTSS2SI_R_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtss2si".
             */
            class CVTSS2SI_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTSS2SI_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtss2si".
             */
            class CVTSS2SI_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTSS2SI_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::MOVAPD(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movapd".
             */
            class MOVAPD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVAPD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movapd".
             */
            class MOVAPD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVAPD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movapd".
             */
            class MOVAPD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVAPD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVAPD(['Wo', 'Vo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movapd".
             */
            class MOVAPD_M_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVAPD_M_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movapd".
             */
            class MOVAPD_P_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVAPD_P_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CVTPI2PD(['Vo', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtpi2pd".
             */
            class CVTPI2PD_XMM_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTPI2PD_XMM_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtpi2pd".
             */
            class CVTPI2PD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTPI2PD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtpi2pd".
             */
            class CVTPI2PD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTPI2PD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::movntpd_Mo_Vo(([], {}))

// Inst::CVTTPD2PI(['Pq', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvttpd2pi".
             */
            class CVTTPD2PI_MMX_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTTPD2PI_MMX_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvttpd2pi".
             */
            class CVTTPD2PI_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTTPD2PI_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvttpd2pi".
             */
            class CVTTPD2PI_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTTPD2PI_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CVTPD2PI(['Pq', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtpd2pi".
             */
            class CVTPD2PI_MMX_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTPD2PI_MMX_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtpd2pi".
             */
            class CVTPD2PI_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTPD2PI_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtpd2pi".
             */
            class CVTPD2PI_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTPD2PI_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UCOMISD(['Vq', 'Wq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "ucomisd".
             */
            class UCOMISD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                UCOMISD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "ucomisd".
             */
            class UCOMISD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                UCOMISD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "ucomisd".
             */
            class UCOMISD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                UCOMISD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::COMISD(['Vq', 'Wq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "comisd".
             */
            class COMISD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                COMISD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "comisd".
             */
            class COMISD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                COMISD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "comisd".
             */
            class COMISD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                COMISD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::CVTSI2SD(['Vdp', 'Edp'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtsi2sd".
             */
            class CVTSI2SD_XMM_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTSI2SD_XMM_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtsi2sd".
             */
            class CVTSI2SD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTSI2SD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtsi2sd".
             */
            class CVTSI2SD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTSI2SD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CVTTSD2SI(['Gdp', 'Wdp'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvttsd2si".
             */
            class CVTTSD2SI_R_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTTSD2SI_R_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvttsd2si".
             */
            class CVTTSD2SI_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTTSD2SI_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvttsd2si".
             */
            class CVTTSD2SI_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTTSD2SI_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CVTSD2SI(['Gd', 'Wq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtsd2si".
             */
            class CVTSD2SI_R_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTSD2SI_R_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtsd2si".
             */
            class CVTSD2SI_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTSD2SI_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtsd2si".
             */
            class CVTSD2SI_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTSD2SI_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::UD2([],{})

// Inst::WRMSR(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "wrmsr".
             */
            class WRMSR : public Macroop
            {
              private:
                
              public:
                // Constructor.
                WRMSR(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::RDTSC(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "rdtsc".
             */
            class RDTSC : public Macroop
            {
              private:
                
              public:
                // Constructor.
                RDTSC(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::RDMSR(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "rdmsr".
             */
            class RDMSR : public Macroop
            {
              private:
                
              public:
                // Constructor.
                RDMSR(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::rdpmc([],{})

// SyscallInst::sysenter((['xc->syscall(Rax)', 'IsSyscall', 'IsNonSpeculative', 'IsSerializeAfter'], {}))

        /**
         * Static instruction class for "sysenter".
         */
        class Sysenter : public SyscallInst
        {
          public:
            // Constructor.
            Sysenter(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// WarnUnimpl::sysenter([],{})

// WarnUnimpl::sysexit([],{})

// Inst::UD2(([], {}))

// WarnUnimpl::getsec([],{})

// Unknown::unknown(([], {}))

// M5InternalError::error((['"Three byte opcode shouldn\'t be handled by "\n                  "two_byte_opcodes.isa!"'], {}))

// M5InternalError::error((['"Three byte opcode shouldn\'t be handled by "\n                  "two_byte_opcodes.isa!"'], {}))

// WarnUnimpl::UD2([],{})

// Inst::CMOVO(['Gv', 'Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovo".
             */
            class CMOVO_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVO_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovo".
             */
            class CMOVO_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVO_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovo".
             */
            class CMOVO_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVO_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CMOVNO(['Gv', 'Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovno".
             */
            class CMOVNO_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVNO_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovno".
             */
            class CMOVNO_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVNO_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovno".
             */
            class CMOVNO_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVNO_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CMOVB(['Gv', 'Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovb".
             */
            class CMOVB_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVB_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovb".
             */
            class CMOVB_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVB_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovb".
             */
            class CMOVB_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVB_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CMOVNB(['Gv', 'Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovnb".
             */
            class CMOVNB_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVNB_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovnb".
             */
            class CMOVNB_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVNB_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovnb".
             */
            class CMOVNB_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVNB_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CMOVZ(['Gv', 'Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovz".
             */
            class CMOVZ_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVZ_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovz".
             */
            class CMOVZ_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVZ_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovz".
             */
            class CMOVZ_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVZ_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CMOVNZ(['Gv', 'Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovnz".
             */
            class CMOVNZ_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVNZ_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovnz".
             */
            class CMOVNZ_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVNZ_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovnz".
             */
            class CMOVNZ_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVNZ_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CMOVBE(['Gv', 'Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovbe".
             */
            class CMOVBE_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVBE_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovbe".
             */
            class CMOVBE_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVBE_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovbe".
             */
            class CMOVBE_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVBE_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CMOVNBE(['Gv', 'Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovnbe".
             */
            class CMOVNBE_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVNBE_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovnbe".
             */
            class CMOVNBE_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVNBE_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovnbe".
             */
            class CMOVNBE_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVNBE_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::CMOVS(['Gv', 'Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovs".
             */
            class CMOVS_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVS_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovs".
             */
            class CMOVS_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVS_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovs".
             */
            class CMOVS_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVS_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CMOVNS(['Gv', 'Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovns".
             */
            class CMOVNS_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVNS_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovns".
             */
            class CMOVNS_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVNS_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovns".
             */
            class CMOVNS_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVNS_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CMOVP(['Gv', 'Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovp".
             */
            class CMOVP_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVP_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovp".
             */
            class CMOVP_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVP_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovp".
             */
            class CMOVP_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVP_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CMOVNP(['Gv', 'Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovnp".
             */
            class CMOVNP_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVNP_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovnp".
             */
            class CMOVNP_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVNP_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovnp".
             */
            class CMOVNP_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVNP_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CMOVL(['Gv', 'Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovl".
             */
            class CMOVL_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVL_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovl".
             */
            class CMOVL_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVL_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovl".
             */
            class CMOVL_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVL_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CMOVNL(['Gv', 'Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovnl".
             */
            class CMOVNL_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVNL_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovnl".
             */
            class CMOVNL_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVNL_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovnl".
             */
            class CMOVNL_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVNL_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CMOVLE(['Gv', 'Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovle".
             */
            class CMOVLE_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVLE_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovle".
             */
            class CMOVLE_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVLE_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovle".
             */
            class CMOVLE_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVLE_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CMOVNLE(['Gv', 'Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovnle".
             */
            class CMOVNLE_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVNLE_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovnle".
             */
            class CMOVNLE_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVNLE_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmovnle".
             */
            class CMOVNLE_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMOVNLE_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::MOVMSKPS(['Gd', 'VRo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movmskps".
             */
            class MOVMSKPS_R_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVMSKPS_R_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SQRTPS(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sqrtps".
             */
            class SQRTPS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SQRTPS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sqrtps".
             */
            class SQRTPS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SQRTPS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sqrtps".
             */
            class SQRTPS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SQRTPS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::rqsrtps_Vo_Wo(([], {}))

// WarnUnimpl::rcpps_Vo_Wo(([], {}))

// Inst::ANDPS(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "andps".
             */
            class ANDPS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ANDPS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "andps".
             */
            class ANDPS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ANDPS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "andps".
             */
            class ANDPS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ANDPS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::ANDNPS(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "andnps".
             */
            class ANDNPS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ANDNPS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "andnps".
             */
            class ANDNPS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ANDNPS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "andnps".
             */
            class ANDNPS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ANDNPS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::ORPS(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "orps".
             */
            class ORPS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ORPS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "orps".
             */
            class ORPS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ORPS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "orps".
             */
            class ORPS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ORPS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::XORPS(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "xorps".
             */
            class XORPS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                XORPS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "xorps".
             */
            class XORPS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                XORPS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "xorps".
             */
            class XORPS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                XORPS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::SQRTSS(['Vd', 'Wd'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sqrtss".
             */
            class SQRTSS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SQRTSS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sqrtss".
             */
            class SQRTSS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SQRTSS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sqrtss".
             */
            class SQRTSS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SQRTSS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::rsqrtss_Vd_Wd(([], {}))

// WarnUnimpl::rcpss_Vd_Wd(([], {}))

// Inst::UD2([],{})

// Inst::MOVMSKPD(['Gd', 'VRo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movmskpd".
             */
            class MOVMSKPD_R_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVMSKPD_R_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SQRTPD(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sqrtpd".
             */
            class SQRTPD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SQRTPD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sqrtpd".
             */
            class SQRTPD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SQRTPD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sqrtpd".
             */
            class SQRTPD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SQRTPD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::ANDPD(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "andpd".
             */
            class ANDPD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ANDPD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "andpd".
             */
            class ANDPD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ANDPD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "andpd".
             */
            class ANDPD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ANDPD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::ANDNPD(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "andnpd".
             */
            class ANDNPD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ANDNPD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "andnpd".
             */
            class ANDNPD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ANDNPD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "andnpd".
             */
            class ANDNPD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ANDNPD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::ORPD(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "orpd".
             */
            class ORPD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ORPD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "orpd".
             */
            class ORPD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ORPD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "orpd".
             */
            class ORPD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ORPD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::XORPD(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "xorpd".
             */
            class XORPD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                XORPD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "xorpd".
             */
            class XORPD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                XORPD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "xorpd".
             */
            class XORPD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                XORPD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::SQRTSD(['Vq', 'Wq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sqrtsd".
             */
            class SQRTSD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SQRTSD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sqrtsd".
             */
            class SQRTSD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SQRTSD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sqrtsd".
             */
            class SQRTSD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SQRTSD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::UD2([],{})

// Inst::ADDPS(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "addps".
             */
            class ADDPS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADDPS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "addps".
             */
            class ADDPS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADDPS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "addps".
             */
            class ADDPS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADDPS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MULPS(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mulps".
             */
            class MULPS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MULPS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mulps".
             */
            class MULPS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MULPS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mulps".
             */
            class MULPS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MULPS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CVTPS2PD(['Vo', 'Wq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtps2pd".
             */
            class CVTPS2PD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTPS2PD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtps2pd".
             */
            class CVTPS2PD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTPS2PD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtps2pd".
             */
            class CVTPS2PD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTPS2PD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CVTDQ2PS(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtdq2ps".
             */
            class CVTDQ2PS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTDQ2PS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtdq2ps".
             */
            class CVTDQ2PS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTDQ2PS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtdq2ps".
             */
            class CVTDQ2PS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTDQ2PS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SUBPS(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "subps".
             */
            class SUBPS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SUBPS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "subps".
             */
            class SUBPS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SUBPS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "subps".
             */
            class SUBPS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SUBPS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MINPS(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "minps".
             */
            class MINPS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MINPS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "minps".
             */
            class MINPS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MINPS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "minps".
             */
            class MINPS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MINPS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::DIVPS(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "divps".
             */
            class DIVPS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                DIVPS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "divps".
             */
            class DIVPS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                DIVPS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "divps".
             */
            class DIVPS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                DIVPS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MAXPS(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "maxps".
             */
            class MAXPS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MAXPS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "maxps".
             */
            class MAXPS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MAXPS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "maxps".
             */
            class MAXPS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MAXPS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::ADDSS(['Vd', 'Wd'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "addss".
             */
            class ADDSS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADDSS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "addss".
             */
            class ADDSS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADDSS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "addss".
             */
            class ADDSS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADDSS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MULSS(['Vd', 'Wd'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mulss".
             */
            class MULSS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MULSS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mulss".
             */
            class MULSS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MULSS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mulss".
             */
            class MULSS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MULSS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CVTSS2SD(['Vq', 'Wd'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtss2sd".
             */
            class CVTSS2SD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTSS2SD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtss2sd".
             */
            class CVTSS2SD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTSS2SD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtss2sd".
             */
            class CVTSS2SD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTSS2SD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CVTTPS2DQ(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvttps2dq".
             */
            class CVTTPS2DQ_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTTPS2DQ_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvttps2dq".
             */
            class CVTTPS2DQ_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTTPS2DQ_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvttps2dq".
             */
            class CVTTPS2DQ_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTTPS2DQ_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SUBSS(['Vd', 'Wd'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "subss".
             */
            class SUBSS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SUBSS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "subss".
             */
            class SUBSS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SUBSS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "subss".
             */
            class SUBSS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SUBSS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MINSS(['Vd', 'Wd'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "minss".
             */
            class MINSS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MINSS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "minss".
             */
            class MINSS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MINSS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "minss".
             */
            class MINSS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MINSS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::DIVSS(['Vd', 'Wd'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "divss".
             */
            class DIVSS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                DIVSS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "divss".
             */
            class DIVSS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                DIVSS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "divss".
             */
            class DIVSS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                DIVSS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MAXSS(['Vd', 'Wd'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "maxss".
             */
            class MAXSS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MAXSS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "maxss".
             */
            class MAXSS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MAXSS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "maxss".
             */
            class MAXSS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MAXSS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::ADDPD(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "addpd".
             */
            class ADDPD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADDPD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "addpd".
             */
            class ADDPD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADDPD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "addpd".
             */
            class ADDPD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADDPD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MULPD(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mulpd".
             */
            class MULPD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MULPD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mulpd".
             */
            class MULPD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MULPD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mulpd".
             */
            class MULPD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MULPD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CVTPD2PS(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtpd2ps".
             */
            class CVTPD2PS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTPD2PS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtpd2ps".
             */
            class CVTPD2PS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTPD2PS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtpd2ps".
             */
            class CVTPD2PS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTPD2PS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CVTPS2DQ(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtps2dq".
             */
            class CVTPS2DQ_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTPS2DQ_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtps2dq".
             */
            class CVTPS2DQ_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTPS2DQ_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtps2dq".
             */
            class CVTPS2DQ_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTPS2DQ_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SUBPD(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "subpd".
             */
            class SUBPD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SUBPD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "subpd".
             */
            class SUBPD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SUBPD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "subpd".
             */
            class SUBPD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SUBPD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MINPD(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "minpd".
             */
            class MINPD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MINPD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "minpd".
             */
            class MINPD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MINPD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "minpd".
             */
            class MINPD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MINPD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::DIVPD(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "divpd".
             */
            class DIVPD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                DIVPD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "divpd".
             */
            class DIVPD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                DIVPD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "divpd".
             */
            class DIVPD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                DIVPD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MAXPD(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "maxpd".
             */
            class MAXPD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MAXPD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "maxpd".
             */
            class MAXPD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MAXPD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "maxpd".
             */
            class MAXPD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MAXPD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::ADDSD(['Vq', 'Wq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "addsd".
             */
            class ADDSD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADDSD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "addsd".
             */
            class ADDSD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADDSD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "addsd".
             */
            class ADDSD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADDSD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MULSD(['Vq', 'Wq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mulsd".
             */
            class MULSD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MULSD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mulsd".
             */
            class MULSD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MULSD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "mulsd".
             */
            class MULSD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MULSD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CVTSD2SS(['Vd', 'Wq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtsd2ss".
             */
            class CVTSD2SS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTSD2SS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtsd2ss".
             */
            class CVTSD2SS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTSD2SS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtsd2ss".
             */
            class CVTSD2SS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTSD2SS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SUBSD(['Vq', 'Wq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "subsd".
             */
            class SUBSD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SUBSD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "subsd".
             */
            class SUBSD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SUBSD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "subsd".
             */
            class SUBSD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SUBSD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MINSD(['Vq', 'Wq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "minsd".
             */
            class MINSD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MINSD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "minsd".
             */
            class MINSD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MINSD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "minsd".
             */
            class MINSD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MINSD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::DIVSD(['Vq', 'Wq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "divsd".
             */
            class DIVSD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                DIVSD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "divsd".
             */
            class DIVSD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                DIVSD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "divsd".
             */
            class DIVSD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                DIVSD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MAXSD(['Vq', 'Wq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "maxsd".
             */
            class MAXSD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MAXSD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "maxsd".
             */
            class MAXSD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MAXSD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "maxsd".
             */
            class MAXSD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MAXSD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::UD2([],{})

// Inst::PUNPCKLBW(['Pq', 'Qd'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpcklbw".
             */
            class PUNPCKLBW_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKLBW_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpcklbw".
             */
            class PUNPCKLBW_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKLBW_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpcklbw".
             */
            class PUNPCKLBW_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKLBW_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PUNPCKLWD(['Pq', 'Qd'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpcklwd".
             */
            class PUNPCKLWD_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKLWD_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpcklwd".
             */
            class PUNPCKLWD_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKLWD_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpcklwd".
             */
            class PUNPCKLWD_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKLWD_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PUNPCKLDQ(['Pq', 'Qd'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpckldq".
             */
            class PUNPCKLDQ_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKLDQ_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpckldq".
             */
            class PUNPCKLDQ_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKLDQ_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpckldq".
             */
            class PUNPCKLDQ_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKLDQ_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PACKSSWB(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "packsswb".
             */
            class PACKSSWB_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PACKSSWB_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "packsswb".
             */
            class PACKSSWB_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PACKSSWB_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "packsswb".
             */
            class PACKSSWB_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PACKSSWB_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PCMPGTB(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpgtb".
             */
            class PCMPGTB_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPGTB_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpgtb".
             */
            class PCMPGTB_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPGTB_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpgtb".
             */
            class PCMPGTB_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPGTB_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PCMPGTW(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpgtw".
             */
            class PCMPGTW_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPGTW_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpgtw".
             */
            class PCMPGTW_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPGTW_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpgtw".
             */
            class PCMPGTW_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPGTW_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PCMPGTD(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpgtd".
             */
            class PCMPGTD_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPGTD_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpgtd".
             */
            class PCMPGTD_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPGTD_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpgtd".
             */
            class PCMPGTD_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPGTD_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PACKUSWB(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "packuswb".
             */
            class PACKUSWB_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PACKUSWB_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "packuswb".
             */
            class PACKUSWB_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PACKUSWB_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "packuswb".
             */
            class PACKUSWB_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PACKUSWB_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::PUNPCKLBW(['Vo', 'Wq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpcklbw".
             */
            class PUNPCKLBW_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKLBW_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpcklbw".
             */
            class PUNPCKLBW_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKLBW_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpcklbw".
             */
            class PUNPCKLBW_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKLBW_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PUNPCKLWD(['Vo', 'Wq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpcklwd".
             */
            class PUNPCKLWD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKLWD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpcklwd".
             */
            class PUNPCKLWD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKLWD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpcklwd".
             */
            class PUNPCKLWD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKLWD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PUNPCKLDQ(['Vo', 'Wq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpckldq".
             */
            class PUNPCKLDQ_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKLDQ_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpckldq".
             */
            class PUNPCKLDQ_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKLDQ_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpckldq".
             */
            class PUNPCKLDQ_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKLDQ_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PACKSSWB(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "packsswb".
             */
            class PACKSSWB_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PACKSSWB_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "packsswb".
             */
            class PACKSSWB_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PACKSSWB_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "packsswb".
             */
            class PACKSSWB_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PACKSSWB_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PCMPGTB(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpgtb".
             */
            class PCMPGTB_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPGTB_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpgtb".
             */
            class PCMPGTB_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPGTB_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpgtb".
             */
            class PCMPGTB_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPGTB_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PCMPGTW(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpgtw".
             */
            class PCMPGTW_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPGTW_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpgtw".
             */
            class PCMPGTW_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPGTW_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpgtw".
             */
            class PCMPGTW_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPGTW_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PCMPGTD(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpgtd".
             */
            class PCMPGTD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPGTD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpgtd".
             */
            class PCMPGTD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPGTD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpgtd".
             */
            class PCMPGTD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPGTD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PACKUSWB(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "packuswb".
             */
            class PACKUSWB_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PACKUSWB_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "packuswb".
             */
            class PACKUSWB_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PACKUSWB_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "packuswb".
             */
            class PACKUSWB_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PACKUSWB_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::UD2([],{})

// Inst::PUNPCKHBW(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpckhbw".
             */
            class PUNPCKHBW_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKHBW_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpckhbw".
             */
            class PUNPCKHBW_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKHBW_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpckhbw".
             */
            class PUNPCKHBW_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKHBW_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PUNPCKHWD(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpckhwd".
             */
            class PUNPCKHWD_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKHWD_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpckhwd".
             */
            class PUNPCKHWD_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKHWD_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpckhwd".
             */
            class PUNPCKHWD_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKHWD_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PUNPCKHDQ(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpckhdq".
             */
            class PUNPCKHDQ_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKHDQ_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpckhdq".
             */
            class PUNPCKHDQ_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKHDQ_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpckhdq".
             */
            class PUNPCKHDQ_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKHDQ_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PACKSSDW(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "packssdw".
             */
            class PACKSSDW_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PACKSSDW_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "packssdw".
             */
            class PACKSSDW_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PACKSSDW_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "packssdw".
             */
            class PACKSSDW_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PACKSSDW_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVD(['Pq', 'Edp'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movd".
             */
            class MOVD_MMX_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVD_MMX_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movd".
             */
            class MOVD_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVD_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movd".
             */
            class MOVD_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVD_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVQ(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movq".
             */
            class MOVQ_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVQ_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movq".
             */
            class MOVQ_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVQ_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movq".
             */
            class MOVQ_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVQ_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::MOVDQU(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movdqu".
             */
            class MOVDQU_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVDQU_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movdqu".
             */
            class MOVDQU_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVDQU_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movdqu".
             */
            class MOVDQU_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVDQU_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::PUNPCKHBW(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpckhbw".
             */
            class PUNPCKHBW_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKHBW_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpckhbw".
             */
            class PUNPCKHBW_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKHBW_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpckhbw".
             */
            class PUNPCKHBW_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKHBW_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PUNPCKHWD(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpckhwd".
             */
            class PUNPCKHWD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKHWD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpckhwd".
             */
            class PUNPCKHWD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKHWD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpckhwd".
             */
            class PUNPCKHWD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKHWD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PUNPCKHDQ(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpckhdq".
             */
            class PUNPCKHDQ_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKHDQ_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpckhdq".
             */
            class PUNPCKHDQ_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKHDQ_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpckhdq".
             */
            class PUNPCKHDQ_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKHDQ_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PACKSSDW(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "packssdw".
             */
            class PACKSSDW_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PACKSSDW_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "packssdw".
             */
            class PACKSSDW_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PACKSSDW_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "packssdw".
             */
            class PACKSSDW_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PACKSSDW_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PUNPCKLQDQ(['Vo', 'Wq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpcklqdq".
             */
            class PUNPCKLQDQ_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKLQDQ_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpcklqdq".
             */
            class PUNPCKLQDQ_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKLQDQ_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpcklqdq".
             */
            class PUNPCKLQDQ_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKLQDQ_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PUNPCKHQDQ(['Vo', 'Wq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpckhqdq".
             */
            class PUNPCKHQDQ_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKHQDQ_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpckhqdq".
             */
            class PUNPCKHQDQ_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKHQDQ_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "punpckhqdq".
             */
            class PUNPCKHQDQ_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PUNPCKHQDQ_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVD(['Vo', 'Edp'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movd".
             */
            class MOVD_XMM_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVD_XMM_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movd".
             */
            class MOVD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movd".
             */
            class MOVD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVDQA(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movdqa".
             */
            class MOVDQA_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVDQA_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movdqa".
             */
            class MOVDQA_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVDQA_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movdqa".
             */
            class MOVDQA_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVDQA_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::UD2([],{})

// Inst::PSHUFW(['Pq', 'Qq', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pshufw".
             */
            class PSHUFW_MMX_MMX_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSHUFW_MMX_MMX_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pshufw".
             */
            class PSHUFW_MMX_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSHUFW_MMX_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pshufw".
             */
            class PSHUFW_MMX_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSHUFW_MMX_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSRLW(['PRq', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrlw".
             */
            class PSRLW_MMX_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRLW_MMX_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSRAW(['PRq', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psraw".
             */
            class PSRAW_MMX_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRAW_MMX_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSLLW(['PRq', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psllw".
             */
            class PSLLW_MMX_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSLLW_MMX_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::PSRLD(['PRq', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrld".
             */
            class PSRLD_MMX_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRLD_MMX_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSRAD(['PRq', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrad".
             */
            class PSRAD_MMX_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRAD_MMX_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSLLD(['PRq', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pslld".
             */
            class PSLLD_MMX_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSLLD_MMX_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::PSRLQ(['PRq', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrlq".
             */
            class PSRLQ_MMX_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRLQ_MMX_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSLLQ(['PRq', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psllq".
             */
            class PSLLQ_MMX_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSLLQ_MMX_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2(([], {}))

// Inst::PCMPEQB((['Pq', 'Qq'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpeqb".
             */
            class PCMPEQB_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPEQB_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpeqb".
             */
            class PCMPEQB_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPEQB_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpeqb".
             */
            class PCMPEQB_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPEQB_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PCMPEQW((['Pq', 'Qq'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpeqw".
             */
            class PCMPEQW_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPEQW_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpeqw".
             */
            class PCMPEQW_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPEQW_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpeqw".
             */
            class PCMPEQW_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPEQW_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PCMPEQD((['Pq', 'Qq'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpeqd".
             */
            class PCMPEQD_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPEQD_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpeqd".
             */
            class PCMPEQD_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPEQD_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpeqd".
             */
            class PCMPEQD_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPEQD_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::EMMS(([], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "emms".
             */
            class EMMS : public Macroop
            {
              private:
                
              public:
                // Constructor.
                EMMS(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::PSHUFHW(['Vo', 'Wo', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pshufhw".
             */
            class PSHUFHW_XMM_XMM_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSHUFHW_XMM_XMM_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pshufhw".
             */
            class PSHUFHW_XMM_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSHUFHW_XMM_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pshufhw".
             */
            class PSHUFHW_XMM_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSHUFHW_XMM_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::PSHUFD(['Vo', 'Wo', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pshufd".
             */
            class PSHUFD_XMM_XMM_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSHUFD_XMM_XMM_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pshufd".
             */
            class PSHUFD_XMM_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSHUFD_XMM_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pshufd".
             */
            class PSHUFD_XMM_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSHUFD_XMM_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSRLW(['VRo', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrlw".
             */
            class PSRLW_XMM_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRLW_XMM_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSRAW(['VRo', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psraw".
             */
            class PSRAW_XMM_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRAW_XMM_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSLLW(['VRo', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psllw".
             */
            class PSLLW_XMM_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSLLW_XMM_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::PSRLD(['VRo', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrld".
             */
            class PSRLD_XMM_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRLD_XMM_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSRAD(['VRo', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrad".
             */
            class PSRAD_XMM_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRAD_XMM_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSLLD(['VRo', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pslld".
             */
            class PSLLD_XMM_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSLLD_XMM_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::PSRLQ(['VRo', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrlq".
             */
            class PSRLQ_XMM_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRLQ_XMM_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSRLDQ(['VRo', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrldq".
             */
            class PSRLDQ_XMM_I : public Macroop
            {
              private:
                const static uint64_t label_psrldq_less_8 = 12;
const static uint64_t label_psrldq_end = 16;
const static uint64_t label_psrldq_less_16 = 9;

              public:
                // Constructor.
                PSRLDQ_XMM_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSLLQ(['VRo', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psllq".
             */
            class PSLLQ_XMM_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSLLQ_XMM_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSLLDQ(['VRo', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pslldq".
             */
            class PSLLDQ_XMM_I : public Macroop
            {
              private:
                const static uint64_t label_pslldq_less_16 = 9;
const static uint64_t label_pslldq_less_8 = 12;
const static uint64_t label_pslldq_end = 16;

              public:
                // Constructor.
                PSLLDQ_XMM_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::PCMPEQB(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpeqb".
             */
            class PCMPEQB_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPEQB_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpeqb".
             */
            class PCMPEQB_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPEQB_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpeqb".
             */
            class PCMPEQB_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPEQB_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PCMPEQW(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpeqw".
             */
            class PCMPEQW_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPEQW_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpeqw".
             */
            class PCMPEQW_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPEQW_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpeqw".
             */
            class PCMPEQW_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPEQW_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PCMPEQD(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpeqd".
             */
            class PCMPEQD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPEQD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpeqd".
             */
            class PCMPEQD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPEQD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pcmpeqd".
             */
            class PCMPEQD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PCMPEQD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::PSHUFLW(['Vo', 'Wo', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pshuflw".
             */
            class PSHUFLW_XMM_XMM_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSHUFLW_XMM_XMM_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pshuflw".
             */
            class PSHUFLW_XMM_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSHUFLW_XMM_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pshuflw".
             */
            class PSHUFLW_XMM_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSHUFLW_XMM_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::UD2([],{})

// WarnUnimpl::vmread_Edp_Gdp(([], {}))

// WarnUnimpl::vmwrite_Gdp_Edp(([], {}))

// Inst::MOVD(['Edp', 'Pdp'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movd".
             */
            class MOVD_R_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVD_R_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movd".
             */
            class MOVD_M_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVD_M_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movd".
             */
            class MOVD_P_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVD_P_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVQ(['Qq', 'Pq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movq".
             */
            class MOVQ_M_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVQ_M_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movq".
             */
            class MOVQ_P_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVQ_P_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::MOVQ(['Vq', 'Wq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movq".
             */
            class MOVQ_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVQ_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movq".
             */
            class MOVQ_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVQ_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movq".
             */
            class MOVQ_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVQ_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVDQU(['Wo', 'Vo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movdqu".
             */
            class MOVDQU_M_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVDQU_M_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movdqu".
             */
            class MOVDQU_P_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVDQU_P_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::HADDPD(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "haddpd".
             */
            class HADDPD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                HADDPD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "haddpd".
             */
            class HADDPD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                HADDPD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "haddpd".
             */
            class HADDPD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                HADDPD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::hsubpd_Vo_Wo(([], {}))

// Inst::MOVD(['Edp', 'Vd'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movd".
             */
            class MOVD_R_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVD_R_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movd".
             */
            class MOVD_M_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVD_M_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movd".
             */
            class MOVD_P_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVD_P_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVDQA(['Wo', 'Vo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movdqa".
             */
            class MOVDQA_M_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVDQA_M_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movdqa".
             */
            class MOVDQA_P_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVDQA_P_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::HADDPS(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "haddps".
             */
            class HADDPS_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                HADDPS_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "haddps".
             */
            class HADDPS_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                HADDPS_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "haddps".
             */
            class HADDPS_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                HADDPS_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::hsubps_Vo_Wo(([], {}))

// Inst::UD2([],{})

// Inst::UD2([],{})

// Inst::JO(['Jz'],{})

// Inst::JNO(['Jz'],{})

// Inst::JB(['Jz'],{})

// Inst::JNB(['Jz'],{})

// Inst::JZ(['Jz'],{})

// Inst::JNZ(['Jz'],{})

// Inst::JBE(['Jz'],{})

// Inst::JNBE(['Jz'],{})

// Unknown::unknown(([], {}))

// Inst::JS(['Jz'],{})

// Inst::JNS(['Jz'],{})

// Inst::JP(['Jz'],{})

// Inst::JNP(['Jz'],{})

// Inst::JL(['Jz'],{})

// Inst::JNL(['Jz'],{})

// Inst::JLE(['Jz'],{})

// Inst::JNLE(['Jz'],{})

// Unknown::unknown(([], {}))

// Inst::SETO(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "seto".
             */
            class SETO_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETO_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "seto".
             */
            class SETO_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETO_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "seto".
             */
            class SETO_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETO_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SETNO(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setno".
             */
            class SETNO_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETNO_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setno".
             */
            class SETNO_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETNO_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setno".
             */
            class SETNO_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETNO_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SETB(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setb".
             */
            class SETB_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETB_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setb".
             */
            class SETB_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETB_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setb".
             */
            class SETB_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETB_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SETNB(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setnb".
             */
            class SETNB_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETNB_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setnb".
             */
            class SETNB_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETNB_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setnb".
             */
            class SETNB_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETNB_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SETZ(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setz".
             */
            class SETZ_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETZ_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setz".
             */
            class SETZ_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETZ_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setz".
             */
            class SETZ_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETZ_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SETNZ(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setnz".
             */
            class SETNZ_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETNZ_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setnz".
             */
            class SETNZ_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETNZ_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setnz".
             */
            class SETNZ_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETNZ_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SETBE(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setbe".
             */
            class SETBE_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETBE_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setbe".
             */
            class SETBE_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETBE_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setbe".
             */
            class SETBE_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETBE_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SETNBE(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setnbe".
             */
            class SETNBE_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETNBE_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setnbe".
             */
            class SETNBE_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETNBE_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setnbe".
             */
            class SETNBE_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETNBE_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::SETS(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sets".
             */
            class SETS_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETS_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sets".
             */
            class SETS_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETS_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sets".
             */
            class SETS_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETS_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SETNS(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setns".
             */
            class SETNS_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETNS_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setns".
             */
            class SETNS_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETNS_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setns".
             */
            class SETNS_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETNS_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SETP(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setp".
             */
            class SETP_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETP_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setp".
             */
            class SETP_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETP_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setp".
             */
            class SETP_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETP_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SETNP(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setnp".
             */
            class SETNP_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETNP_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setnp".
             */
            class SETNP_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETNP_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setnp".
             */
            class SETNP_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETNP_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SETL(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setl".
             */
            class SETL_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETL_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setl".
             */
            class SETL_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETL_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setl".
             */
            class SETL_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETL_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SETNL(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setnl".
             */
            class SETNL_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETNL_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setnl".
             */
            class SETNL_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETNL_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setnl".
             */
            class SETNL_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETNL_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SETLE(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setle".
             */
            class SETLE_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETLE_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setle".
             */
            class SETLE_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETLE_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setle".
             */
            class SETLE_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETLE_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SETNLE(['Eb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setnle".
             */
            class SETNLE_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETNLE_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setnle".
             */
            class SETNLE_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETNLE_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "setnle".
             */
            class SETNLE_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SETNLE_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// WarnUnimpl::push_fs([],{})

// WarnUnimpl::pop_fs([],{})

// CPUIDInst::CPUID((['\n                CpuidResult result;\n                bool success = doCpuid(xc->tcBase(), bits(Rax, 31, 0),\n                    bits(Rcx, 31, 0), result);\n                if (success) {\n                    Rax = result.rax;\n                    Rbx = result.rbx;\n                    Rcx = result.rcx;\n                    Rdx = result.rdx;\n                } else {\n                    Rax = Rax;\n                    Rbx = Rbx;\n                    Rcx = Rcx;\n                    Rdx = Rdx;\n                }\n                '], {}))

        /**
         * Static instruction class for "CPUID".
         */
        class CPUID : public CPUIDInst
        {
          public:
            // Constructor.
            CPUID(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// Inst::BT((['Ev', 'Gv'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "bt".
             */
            class BT_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BT_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "bt".
             */
            class BT_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BT_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "bt".
             */
            class BT_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BT_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SHLD((['Ev', 'Gv', 'Ib'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "shld".
             */
            class SHLD_R_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SHLD_R_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "shld".
             */
            class SHLD_M_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SHLD_M_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "shld".
             */
            class SHLD_P_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SHLD_P_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SHLD((['Ev', 'Gv'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "shld".
             */
            class SHLD_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SHLD_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "shld".
             */
            class SHLD_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SHLD_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "shld".
             */
            class SHLD_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SHLD_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2(([], {}))

// WarnUnimpl::push_gs([],{})

// WarnUnimpl::pop_gs([],{})

// WarnUnimpl::rsm_smm([],{})

// Inst::BTS((['Ev', 'Gv'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "bts".
             */
            class BTS_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTS_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "bts".
             */
            class BTS_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTS_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "bts".
             */
            class BTS_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTS_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SHRD((['Ev', 'Gv', 'Ib'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "shrd".
             */
            class SHRD_R_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SHRD_R_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "shrd".
             */
            class SHRD_M_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SHRD_M_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "shrd".
             */
            class SHRD_P_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SHRD_P_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SHRD((['Ev', 'Gv'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "shrd".
             */
            class SHRD_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SHRD_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "shrd".
             */
            class SHRD_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SHRD_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "shrd".
             */
            class SHRD_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SHRD_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// BasicOperate::LFENCE((['/*Nothing*/', 'IsReadBarrier'], {}))

        /**
         * Static instruction class for "LFENCE".
         */
        class LFENCE : public X86ISA::X86StaticInst
        {
          public:
            // Constructor.
            LFENCE(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// BasicOperate::MFENCE((['/*Nothing*/', 'IsMemBarrier'], {}))

        /**
         * Static instruction class for "MFENCE".
         */
        class MFENCE : public X86ISA::X86StaticInst
        {
          public:
            // Constructor.
            MFENCE(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// BasicOperate::SFENCE((['/*Nothing*/', 'IsWriteBarrier'], {}))

        /**
         * Static instruction class for "SFENCE".
         */
        class SFENCE : public X86ISA::X86StaticInst
        {
          public:
            // Constructor.
            SFENCE(ExtMachInst machInst);
            
        Fault execute(ExecContext *, Trace::InstRecord *) const;

        };

// Inst::UD2(([], {}))

// Inst::FXSAVE((['M'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fxsave".
             */
            class FXSAVE_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FXSAVE_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fxsave".
             */
            class FXSAVE_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FXSAVE_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::FXSAVE64((['M'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fxsave64".
             */
            class FXSAVE64_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FXSAVE64_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fxsave64".
             */
            class FXSAVE64_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FXSAVE64_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::fxsave([],{})

// Inst::FXRSTOR((['M'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fxrstor".
             */
            class FXRSTOR_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FXRSTOR_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fxrstor".
             */
            class FXRSTOR_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FXRSTOR_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::FXRSTOR64((['M'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fxrstor64".
             */
            class FXRSTOR64_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FXRSTOR64_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "fxrstor64".
             */
            class FXRSTOR64_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                FXRSTOR64_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::fxrstor([],{})

// Inst::LDMXCSR((['Md'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "ldmxcsr".
             */
            class LDMXCSR_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                LDMXCSR_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "ldmxcsr".
             */
            class LDMXCSR_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                LDMXCSR_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::STMXCSR((['Md'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "stmxcsr".
             */
            class STMXCSR_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                STMXCSR_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "stmxcsr".
             */
            class STMXCSR_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                STMXCSR_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::xsave([],{})

// WarnUnimpl::xrstor([],{})

// Inst::UD2(([], {}))

// WarnUnimpl::clflush([],{})

// Unknown::unknown(([], {}))

// Inst::IMUL((['Gv', 'Ev'], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "imul".
             */
            class IMUL_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                IMUL_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "imul".
             */
            class IMUL_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                IMUL_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "imul".
             */
            class IMUL_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                IMUL_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::CMPXCHG(['Eb', 'Gb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmpxchg".
             */
            class CMPXCHG_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMPXCHG_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmpxchg".
             */
            class CMPXCHG_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMPXCHG_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmpxchg".
             */
            class CMPXCHG_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMPXCHG_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CMPXCHG(['Ev', 'Gv'],{})

// WarnUnimpl::lss_Gz_Mp(([], {}))

// Inst::BTR(['Ev', 'Gv'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "btr".
             */
            class BTR_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTR_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "btr".
             */
            class BTR_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTR_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "btr".
             */
            class BTR_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTR_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::lfs_Gz_Mp(([], {}))

// WarnUnimpl::lgs_Gz_Mp(([], {}))

// Inst::MOVZX_B(['Gv', 'Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movzx".
             */
            class MOVZX_B_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVZX_B_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movzx".
             */
            class MOVZX_B_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVZX_B_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movzx".
             */
            class MOVZX_B_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVZX_B_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVZX_W(['Gv', 'Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movzx".
             */
            class MOVZX_W_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVZX_W_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movzx".
             */
            class MOVZX_W_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVZX_W_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movzx".
             */
            class MOVZX_W_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVZX_W_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// WarnUnimpl::jmpe_Jz(([], {}))

// WarnUnimpl::popcnt_Gv_Ev(([], {}))

// Unknown::unknown(([], {}))

// Inst::UD2([],{})

// Inst::BT(['Ev', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "bt".
             */
            class BT_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BT_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "bt".
             */
            class BT_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BT_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "bt".
             */
            class BT_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BT_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::BTS(['Ev', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "bts".
             */
            class BTS_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTS_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "bts".
             */
            class BTS_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTS_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "bts".
             */
            class BTS_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTS_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::BTR(['Ev', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "btr".
             */
            class BTR_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTR_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "btr".
             */
            class BTR_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTR_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "btr".
             */
            class BTR_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTR_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::BTC(['Ev', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "btc".
             */
            class BTC_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTC_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "btc".
             */
            class BTC_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTC_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "btc".
             */
            class BTC_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTC_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::BTC(['Ev', 'Gv'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "btc".
             */
            class BTC_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTC_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "btc".
             */
            class BTC_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTC_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "btc".
             */
            class BTC_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTC_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::BSF(['Gv', 'Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "bsf".
             */
            class BSF_R_R : public Macroop
            {
              private:
                const static uint64_t label_end = 29;

              public:
                // Constructor.
                BSF_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "bsf".
             */
            class BSF_R_M : public Macroop
            {
              private:
                const static uint64_t label_end = 31;

              public:
                // Constructor.
                BSF_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "bsf".
             */
            class BSF_R_P : public Macroop
            {
              private:
                const static uint64_t label_end = 32;

              public:
                // Constructor.
                BSF_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::BSR(['Gv', 'Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "bsr".
             */
            class BSR_R_R : public Macroop
            {
              private:
                const static uint64_t label_end = 27;

              public:
                // Constructor.
                BSR_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "bsr".
             */
            class BSR_R_M : public Macroop
            {
              private:
                const static uint64_t label_end = 28;

              public:
                // Constructor.
                BSR_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "bsr".
             */
            class BSR_R_P : public Macroop
            {
              private:
                const static uint64_t label_end = 29;

              public:
                // Constructor.
                BSR_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVSX_B(['Gv', 'Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movsx".
             */
            class MOVSX_B_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVSX_B_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movsx".
             */
            class MOVSX_B_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVSX_B_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movsx".
             */
            class MOVSX_B_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVSX_B_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVSX_W(['Gv', 'Ev'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movsx".
             */
            class MOVSX_W_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVSX_W_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movsx".
             */
            class MOVSX_W_R_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVSX_W_R_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movsx".
             */
            class MOVSX_W_R_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVSX_W_R_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::XADD(['Eb', 'Gb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "xadd".
             */
            class XADD_R_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                XADD_R_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "xadd".
             */
            class XADD_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                XADD_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "xadd".
             */
            class XADD_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                XADD_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::XADD(['Ev', 'Gv'],{})

// Inst::CMPXCHG8B(['Mdp'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmpxchg8b".
             */
            class CMPXCHG8B_M : public Macroop
            {
              private:
                const static uint64_t label_doneComparing = 6;

              public:
                // Constructor.
                CMPXCHG8B_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmpxchg8b".
             */
            class CMPXCHG8B_P : public Macroop
            {
              private:
                const static uint64_t label_doneComparing = 7;

              public:
                // Constructor.
                CMPXCHG8B_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::vmclear_Mq(([], {}))

// WarnUnimpl::vmxon_Mq(([], {}))

// WarnUnimpl::vmptrld_Mq(([], {}))

// Unknown::unknown(([], {}))

// WarnUnimpl::vmptrst_Mq(([], {}))

// Inst::UD2([],{})

// Inst::CMPPS(['Vo', 'Wo', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmpps".
             */
            class CMPPS_XMM_XMM_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMPPS_XMM_XMM_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmpps".
             */
            class CMPPS_XMM_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMPPS_XMM_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmpps".
             */
            class CMPPS_XMM_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMPPS_XMM_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVNTI(['Mdp', 'Gdp'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movnti".
             */
            class MOVNTI_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVNTI_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movnti".
             */
            class MOVNTI_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVNTI_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PINSRW(['Pq', 'Ew', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pinsrw".
             */
            class PINSRW_MMX_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PINSRW_MMX_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pinsrw".
             */
            class PINSRW_MMX_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PINSRW_MMX_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pinsrw".
             */
            class PINSRW_MMX_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PINSRW_MMX_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PEXTRW(['Gd', 'PRq', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pextrw".
             */
            class PEXTRW_R_MMX_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PEXTRW_R_MMX_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SHUFPS(['Vps', 'Wps', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "shufps".
             */
            class SHUFPS_XMM_XMM_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SHUFPS_XMM_XMM_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "shufps".
             */
            class SHUFPS_XMM_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SHUFPS_XMM_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "shufps".
             */
            class SHUFPS_XMM_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SHUFPS_XMM_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::CMPSS(['Vd', 'Wd', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmpss".
             */
            class CMPSS_XMM_XMM_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMPSS_XMM_XMM_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmpss".
             */
            class CMPSS_XMM_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMPSS_XMM_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmpss".
             */
            class CMPSS_XMM_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMPSS_XMM_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::CMPPD(['Vo', 'Wo', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmppd".
             */
            class CMPPD_XMM_XMM_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMPPD_XMM_XMM_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmppd".
             */
            class CMPPD_XMM_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMPPD_XMM_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmppd".
             */
            class CMPPD_XMM_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMPPD_XMM_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PINSRW(['Vdw', 'Ew', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pinsrw".
             */
            class PINSRW_XMM_R_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PINSRW_XMM_R_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pinsrw".
             */
            class PINSRW_XMM_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PINSRW_XMM_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pinsrw".
             */
            class PINSRW_XMM_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PINSRW_XMM_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PEXTRW(['Gd', 'VRdq', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pextrw".
             */
            class PEXTRW_R_XMM_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PEXTRW_R_XMM_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SHUFPD(['Vpd', 'Wpd', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "shufpd".
             */
            class SHUFPD_XMM_XMM_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SHUFPD_XMM_XMM_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "shufpd".
             */
            class SHUFPD_XMM_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SHUFPD_XMM_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "shufpd".
             */
            class SHUFPD_XMM_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SHUFPD_XMM_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::CMPSD(['Vq', 'Wq', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmpsd".
             */
            class CMPSD_XMM_XMM_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMPSD_XMM_XMM_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmpsd".
             */
            class CMPSD_XMM_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMPSD_XMM_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmpsd".
             */
            class CMPSD_XMM_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMPSD_XMM_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::UD2([],{})

// Inst::BSWAP_D(['Bd'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "bswap".
             */
            class BSWAP_D_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BSWAP_D_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::BSWAP_Q(['Bq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "bswap".
             */
            class BSWAP_Q_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BSWAP_Q_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::PSRLW(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrlw".
             */
            class PSRLW_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRLW_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrlw".
             */
            class PSRLW_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRLW_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrlw".
             */
            class PSRLW_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRLW_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSRLD(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrld".
             */
            class PSRLD_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRLD_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrld".
             */
            class PSRLD_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRLD_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrld".
             */
            class PSRLD_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRLD_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSRLQ(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrlq".
             */
            class PSRLQ_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRLQ_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrlq".
             */
            class PSRLQ_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRLQ_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrlq".
             */
            class PSRLQ_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRLQ_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PADDQ(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddq".
             */
            class PADDQ_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDQ_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddq".
             */
            class PADDQ_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDQ_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddq".
             */
            class PADDQ_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDQ_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PMULLW(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmullw".
             */
            class PMULLW_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMULLW_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmullw".
             */
            class PMULLW_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMULLW_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmullw".
             */
            class PMULLW_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMULLW_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PMOVMSKB(['Gd', 'PRq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmovmskb".
             */
            class PMOVMSKB_R_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMOVMSKB_R_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::MOVQ2DQ(['Vo', 'PRq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movq2dq".
             */
            class MOVQ2DQ_XMM_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVQ2DQ_XMM_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::ADDSUBPD(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "addsubpd".
             */
            class ADDSUBPD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADDSUBPD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "addsubpd".
             */
            class ADDSUBPD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADDSUBPD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "addsubpd".
             */
            class ADDSUBPD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADDSUBPD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSRLW(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrlw".
             */
            class PSRLW_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRLW_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrlw".
             */
            class PSRLW_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRLW_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrlw".
             */
            class PSRLW_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRLW_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSRLD(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrld".
             */
            class PSRLD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRLD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrld".
             */
            class PSRLD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRLD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrld".
             */
            class PSRLD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRLD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSRLQ(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrlq".
             */
            class PSRLQ_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRLQ_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrlq".
             */
            class PSRLQ_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRLQ_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrlq".
             */
            class PSRLQ_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRLQ_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PADDQ(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddq".
             */
            class PADDQ_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDQ_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddq".
             */
            class PADDQ_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDQ_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddq".
             */
            class PADDQ_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDQ_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PMULLW(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmullw".
             */
            class PMULLW_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMULLW_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmullw".
             */
            class PMULLW_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMULLW_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmullw".
             */
            class PMULLW_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMULLW_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MOVQ(['Wq', 'Vq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movq".
             */
            class MOVQ_M_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVQ_M_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movq".
             */
            class MOVQ_P_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVQ_P_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PMOVMSKB(['Gd', 'VRo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmovmskb".
             */
            class PMOVMSKB_R_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMOVMSKB_R_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// WarnUnimpl::addsubps_Vo_Wo(([], {}))

// Inst::MOVDQ2Q(['Pq', 'VRq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "movdq2q".
             */
            class MOVDQ2Q_MMX_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MOVDQ2Q_MMX_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::UD2([],{})

// Inst::PSUBUSB(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubusb".
             */
            class PSUBUSB_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBUSB_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubusb".
             */
            class PSUBUSB_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBUSB_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubusb".
             */
            class PSUBUSB_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBUSB_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSUBUSW(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubusw".
             */
            class PSUBUSW_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBUSW_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubusw".
             */
            class PSUBUSW_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBUSW_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubusw".
             */
            class PSUBUSW_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBUSW_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PMINUB(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pminub".
             */
            class PMINUB_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMINUB_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pminub".
             */
            class PMINUB_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMINUB_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pminub".
             */
            class PMINUB_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMINUB_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PAND(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pand".
             */
            class PAND_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PAND_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pand".
             */
            class PAND_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PAND_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pand".
             */
            class PAND_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PAND_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PADDUSB(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddusb".
             */
            class PADDUSB_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDUSB_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddusb".
             */
            class PADDUSB_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDUSB_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddusb".
             */
            class PADDUSB_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDUSB_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PADDUSW(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddusw".
             */
            class PADDUSW_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDUSW_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddusw".
             */
            class PADDUSW_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDUSW_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddusw".
             */
            class PADDUSW_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDUSW_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PMAXUB(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmaxub".
             */
            class PMAXUB_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMAXUB_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmaxub".
             */
            class PMAXUB_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMAXUB_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmaxub".
             */
            class PMAXUB_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMAXUB_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PANDN(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pandn".
             */
            class PANDN_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PANDN_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pandn".
             */
            class PANDN_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PANDN_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pandn".
             */
            class PANDN_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PANDN_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::PSUBUSB(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubusb".
             */
            class PSUBUSB_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBUSB_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubusb".
             */
            class PSUBUSB_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBUSB_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubusb".
             */
            class PSUBUSB_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBUSB_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSUBUSW(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubusw".
             */
            class PSUBUSW_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBUSW_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubusw".
             */
            class PSUBUSW_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBUSW_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubusw".
             */
            class PSUBUSW_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBUSW_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PMINUB(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pminub".
             */
            class PMINUB_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMINUB_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pminub".
             */
            class PMINUB_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMINUB_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pminub".
             */
            class PMINUB_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMINUB_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PAND(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pand".
             */
            class PAND_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PAND_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pand".
             */
            class PAND_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PAND_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pand".
             */
            class PAND_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PAND_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PADDUSB(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddusb".
             */
            class PADDUSB_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDUSB_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddusb".
             */
            class PADDUSB_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDUSB_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddusb".
             */
            class PADDUSB_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDUSB_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PADDUSW(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddusw".
             */
            class PADDUSW_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDUSW_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddusw".
             */
            class PADDUSW_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDUSW_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddusw".
             */
            class PADDUSW_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDUSW_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PMAXUB(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmaxub".
             */
            class PMAXUB_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMAXUB_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmaxub".
             */
            class PMAXUB_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMAXUB_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmaxub".
             */
            class PMAXUB_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMAXUB_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PANDN(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pandn".
             */
            class PANDN_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PANDN_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pandn".
             */
            class PANDN_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PANDN_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pandn".
             */
            class PANDN_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PANDN_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::UD2([],{})

// Inst::PAVGB(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pavgb".
             */
            class PAVGB_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PAVGB_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pavgb".
             */
            class PAVGB_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PAVGB_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pavgb".
             */
            class PAVGB_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PAVGB_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSRAW(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psraw".
             */
            class PSRAW_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRAW_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psraw".
             */
            class PSRAW_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRAW_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psraw".
             */
            class PSRAW_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRAW_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSRAD(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrad".
             */
            class PSRAD_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRAD_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrad".
             */
            class PSRAD_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRAD_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrad".
             */
            class PSRAD_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRAD_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PAVGW(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pavgw".
             */
            class PAVGW_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PAVGW_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pavgw".
             */
            class PAVGW_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PAVGW_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pavgw".
             */
            class PAVGW_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PAVGW_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PMULHUW(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmulhuw".
             */
            class PMULHUW_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMULHUW_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmulhuw".
             */
            class PMULHUW_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMULHUW_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmulhuw".
             */
            class PMULHUW_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMULHUW_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PMULHW(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmulhw".
             */
            class PMULHW_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMULHW_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmulhw".
             */
            class PMULHW_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMULHW_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmulhw".
             */
            class PMULHW_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMULHW_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::movntq_Mq_Pq(([], {}))

// Inst::UD2([],{})

// Inst::CVTDQ2PD(['Vo', 'Wq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtdq2pd".
             */
            class CVTDQ2PD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTDQ2PD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtdq2pd".
             */
            class CVTDQ2PD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTDQ2PD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtdq2pd".
             */
            class CVTDQ2PD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTDQ2PD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::PAVGB(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pavgb".
             */
            class PAVGB_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PAVGB_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pavgb".
             */
            class PAVGB_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PAVGB_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pavgb".
             */
            class PAVGB_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PAVGB_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSRAW(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psraw".
             */
            class PSRAW_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRAW_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psraw".
             */
            class PSRAW_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRAW_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psraw".
             */
            class PSRAW_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRAW_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSRAD(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrad".
             */
            class PSRAD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRAD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrad".
             */
            class PSRAD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRAD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psrad".
             */
            class PSRAD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSRAD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PAVGW(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pavgw".
             */
            class PAVGW_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PAVGW_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pavgw".
             */
            class PAVGW_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PAVGW_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pavgw".
             */
            class PAVGW_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PAVGW_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PMULHUW(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmulhuw".
             */
            class PMULHUW_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMULHUW_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmulhuw".
             */
            class PMULHUW_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMULHUW_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmulhuw".
             */
            class PMULHUW_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMULHUW_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PMULHW(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmulhw".
             */
            class PMULHW_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMULHW_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmulhw".
             */
            class PMULHW_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMULHW_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmulhw".
             */
            class PMULHW_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMULHW_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CVTTPD2DQ(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvttpd2dq".
             */
            class CVTTPD2DQ_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTTPD2DQ_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvttpd2dq".
             */
            class CVTTPD2DQ_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTTPD2DQ_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvttpd2dq".
             */
            class CVTTPD2DQ_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTTPD2DQ_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// WarnUnimpl::movntdq_Mo_Vo(([], {}))

// Unknown::unknown(([], {}))

// Inst::CVTPD2DQ(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtpd2dq".
             */
            class CVTPD2DQ_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTPD2DQ_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtpd2dq".
             */
            class CVTPD2DQ_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTPD2DQ_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cvtpd2dq".
             */
            class CVTPD2DQ_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CVTPD2DQ_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::UD2([],{})

// Inst::PSUBSB(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubsb".
             */
            class PSUBSB_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBSB_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubsb".
             */
            class PSUBSB_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBSB_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubsb".
             */
            class PSUBSB_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBSB_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSUBSW(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubsw".
             */
            class PSUBSW_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBSW_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubsw".
             */
            class PSUBSW_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBSW_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubsw".
             */
            class PSUBSW_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBSW_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PMINSW(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pminsw".
             */
            class PMINSW_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMINSW_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pminsw".
             */
            class PMINSW_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMINSW_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pminsw".
             */
            class PMINSW_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMINSW_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::POR(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "por".
             */
            class POR_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                POR_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "por".
             */
            class POR_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                POR_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "por".
             */
            class POR_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                POR_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PADDSB(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddsb".
             */
            class PADDSB_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDSB_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddsb".
             */
            class PADDSB_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDSB_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddsb".
             */
            class PADDSB_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDSB_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PADDSW(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddsw".
             */
            class PADDSW_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDSW_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddsw".
             */
            class PADDSW_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDSW_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddsw".
             */
            class PADDSW_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDSW_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PMAXSW(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmaxsw".
             */
            class PMAXSW_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMAXSW_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmaxsw".
             */
            class PMAXSW_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMAXSW_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmaxsw".
             */
            class PMAXSW_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMAXSW_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PXOR(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pxor".
             */
            class PXOR_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PXOR_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pxor".
             */
            class PXOR_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PXOR_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pxor".
             */
            class PXOR_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PXOR_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::PSUBSB(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubsb".
             */
            class PSUBSB_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBSB_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubsb".
             */
            class PSUBSB_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBSB_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubsb".
             */
            class PSUBSB_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBSB_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSUBSW(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubsw".
             */
            class PSUBSW_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBSW_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubsw".
             */
            class PSUBSW_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBSW_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubsw".
             */
            class PSUBSW_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBSW_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PMINSW(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pminsw".
             */
            class PMINSW_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMINSW_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pminsw".
             */
            class PMINSW_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMINSW_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pminsw".
             */
            class PMINSW_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMINSW_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::POR(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "por".
             */
            class POR_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                POR_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "por".
             */
            class POR_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                POR_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "por".
             */
            class POR_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                POR_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PADDSB(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddsb".
             */
            class PADDSB_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDSB_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddsb".
             */
            class PADDSB_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDSB_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddsb".
             */
            class PADDSB_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDSB_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PADDSW(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddsw".
             */
            class PADDSW_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDSW_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddsw".
             */
            class PADDSW_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDSW_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddsw".
             */
            class PADDSW_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDSW_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PMAXSW(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmaxsw".
             */
            class PMAXSW_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMAXSW_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmaxsw".
             */
            class PMAXSW_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMAXSW_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmaxsw".
             */
            class PMAXSW_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMAXSW_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PXOR(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pxor".
             */
            class PXOR_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PXOR_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pxor".
             */
            class PXOR_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PXOR_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pxor".
             */
            class PXOR_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PXOR_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::UD2([],{})

// Inst::PSLLW(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psllw".
             */
            class PSLLW_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSLLW_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psllw".
             */
            class PSLLW_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSLLW_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psllw".
             */
            class PSLLW_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSLLW_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSLLD(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pslld".
             */
            class PSLLD_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSLLD_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pslld".
             */
            class PSLLD_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSLLD_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pslld".
             */
            class PSLLD_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSLLD_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSLLQ(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psllq".
             */
            class PSLLQ_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSLLQ_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psllq".
             */
            class PSLLQ_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSLLQ_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psllq".
             */
            class PSLLQ_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSLLQ_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PMULUDQ(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmuludq".
             */
            class PMULUDQ_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMULUDQ_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmuludq".
             */
            class PMULUDQ_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMULUDQ_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmuludq".
             */
            class PMULUDQ_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMULUDQ_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PMADDWD(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmaddwd".
             */
            class PMADDWD_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMADDWD_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmaddwd".
             */
            class PMADDWD_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMADDWD_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmaddwd".
             */
            class PMADDWD_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMADDWD_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSADBW(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psadbw".
             */
            class PSADBW_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSADBW_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psadbw".
             */
            class PSADBW_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSADBW_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psadbw".
             */
            class PSADBW_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSADBW_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MASKMOVQ(['Pq', 'PRq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "maskmovq".
             */
            class MASKMOVQ_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MASKMOVQ_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::PSLLW(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psllw".
             */
            class PSLLW_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSLLW_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psllw".
             */
            class PSLLW_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSLLW_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psllw".
             */
            class PSLLW_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSLLW_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSLLD(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pslld".
             */
            class PSLLD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSLLD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pslld".
             */
            class PSLLD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSLLD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pslld".
             */
            class PSLLD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSLLD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSLLQ(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psllq".
             */
            class PSLLQ_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSLLQ_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psllq".
             */
            class PSLLQ_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSLLQ_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psllq".
             */
            class PSLLQ_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSLLQ_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PMULUDQ(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmuludq".
             */
            class PMULUDQ_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMULUDQ_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmuludq".
             */
            class PMULUDQ_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMULUDQ_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmuludq".
             */
            class PMULUDQ_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMULUDQ_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PMADDWD(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmaddwd".
             */
            class PMADDWD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMADDWD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmaddwd".
             */
            class PMADDWD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMADDWD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "pmaddwd".
             */
            class PMADDWD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PMADDWD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSADBW(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psadbw".
             */
            class PSADBW_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSADBW_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psadbw".
             */
            class PSADBW_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSADBW_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psadbw".
             */
            class PSADBW_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSADBW_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::MASKMOVDQU(['Vo', 'VRo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "maskmovdqu".
             */
            class MASKMOVDQU_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                MASKMOVDQU_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// WarnUnimpl::lddqu_Vo_Mo(([], {}))

// Inst::UD2([],{})

// Inst::UD2([],{})

// Inst::PSUBB(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubb".
             */
            class PSUBB_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBB_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubb".
             */
            class PSUBB_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBB_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubb".
             */
            class PSUBB_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBB_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSUBW(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubw".
             */
            class PSUBW_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBW_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubw".
             */
            class PSUBW_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBW_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubw".
             */
            class PSUBW_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBW_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSUBD(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubd".
             */
            class PSUBD_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBD_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubd".
             */
            class PSUBD_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBD_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubd".
             */
            class PSUBD_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBD_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSUBQ(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubq".
             */
            class PSUBQ_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBQ_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubq".
             */
            class PSUBQ_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBQ_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubq".
             */
            class PSUBQ_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBQ_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PADDB(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddb".
             */
            class PADDB_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDB_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddb".
             */
            class PADDB_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDB_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddb".
             */
            class PADDB_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDB_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PADDW(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddw".
             */
            class PADDW_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDW_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddw".
             */
            class PADDW_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDW_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddw".
             */
            class PADDW_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDW_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PADDD(['Pq', 'Qq'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddd".
             */
            class PADDD_MMX_MMX : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDD_MMX_MMX(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddd".
             */
            class PADDD_MMX_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDD_MMX_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddd".
             */
            class PADDD_MMX_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDD_MMX_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Unknown::unknown(([], {}))

// Inst::PSUBB(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubb".
             */
            class PSUBB_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBB_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubb".
             */
            class PSUBB_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBB_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubb".
             */
            class PSUBB_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBB_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSUBW(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubw".
             */
            class PSUBW_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBW_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubw".
             */
            class PSUBW_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBW_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubw".
             */
            class PSUBW_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBW_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSUBD(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubd".
             */
            class PSUBD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubd".
             */
            class PSUBD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubd".
             */
            class PSUBD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PSUBQ(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubq".
             */
            class PSUBQ_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBQ_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubq".
             */
            class PSUBQ_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBQ_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "psubq".
             */
            class PSUBQ_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PSUBQ_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PADDB(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddb".
             */
            class PADDB_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDB_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddb".
             */
            class PADDB_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDB_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddb".
             */
            class PADDB_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDB_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PADDW(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddw".
             */
            class PADDW_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDW_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddw".
             */
            class PADDW_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDW_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddw".
             */
            class PADDW_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDW_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::PADDD(['Vo', 'Wo'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddd".
             */
            class PADDD_XMM_XMM : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDD_XMM_XMM(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddd".
             */
            class PADDD_XMM_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDD_XMM_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "paddd".
             */
            class PADDD_XMM_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                PADDD_XMM_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Unknown::unknown(([], {}))

// Inst::UD2([],{})

// FailUnimpl::twoByteOps(([], {}))

// WarnUnimpl::pshufb_Vdq_Wdq([],{})

// WarnUnimpl::phaddw_Vdq_Wdq([],{})

// WarnUnimpl::phaddd_Vdq_Wdq([],{})

// WarnUnimpl::phaddsw_Vdq_Wdq([],{})

// WarnUnimpl::pmaddubsw_Vdq_Wdq([],{})

// WarnUnimpl::phsubw_Vdq_Wdq([],{})

// WarnUnimpl::phsubd_Vdq_Wdq([],{})

// WarnUnimpl::phsubsw_Vdq_Wdq([],{})

// WarnUnimpl::psignb_Vdq_Wdq([],{})

// WarnUnimpl::psignw_Vdq_Wdq([],{})

// WarnUnimpl::psignd_Vdq_Wdq([],{})

// WarnUnimpl::pmulhrsw_Vdq_Wdq([],{})

// WarnUnimpl::pblendvb_Vdq_Wdq([],{})

// WarnUnimpl::blendvps_Vdq_Wdq([],{})

// WarnUnimpl::blendvpd_Vdq_Wdq([],{})

// WarnUnimpl::ptest_Vdq_Wdq([],{})

// WarnUnimpl::pabsb_Vdq_Wdq([],{})

// WarnUnimpl::pabsw_Vdq_Wdq([],{})

// WarnUnimpl::pabsd_Vdq_Wdq([],{})

// WarnUnimpl::pmovsxbw_Vdq_Udq_or_Mq([],{})

// WarnUnimpl::pmovsxbd_Vdq_Udq_or_Md([],{})

// WarnUnimpl::pmovsxbq_Vdq_Udq_or_Mw([],{})

// WarnUnimpl::pmovsxwd_Vdq_Udq_or_Mq([],{})

// WarnUnimpl::pmovsxwq_Vdq_Udq_or_Md([],{})

// WarnUnimpl::pmovsxdq_Vdq_Udq_or_Mq([],{})

// WarnUnimpl::pmuldq_Vdq_Wdq([],{})

// WarnUnimpl::pcmpeqq_Vdq_Wdq([],{})

// WarnUnimpl::movntdqa_Vdq_Mdq([],{})

// WarnUnimpl::packusdw_Vdq_Wdq([],{})

// WarnUnimpl::pmovzxbw_Vdq_Udq_or_Mq([],{})

// WarnUnimpl::pmovzxbd_Vdq_Udq_or_Md([],{})

// WarnUnimpl::pmovzxbq_Vdq_Udq_or_Mw([],{})

// WarnUnimpl::pmovzxwd_Vdq_Udq_or_Mq([],{})

// WarnUnimpl::pmovzxwq_Vdq_Udq_or_Md([],{})

// WarnUnimpl::pmovzxdq_Vdq_Udq_or_Mq([],{})

// WarnUnimpl::pcmpgtq_Vdq_Wdq([],{})

// WarnUnimpl::pminsb_Vdq_Wdq([],{})

// WarnUnimpl::pminsd_Vdq_Wdq([],{})

// WarnUnimpl::pminuw_Vdq_Wdq([],{})

// WarnUnimpl::pminud_Vdq_Wdq([],{})

// WarnUnimpl::pmaxsb_Vdq_Wdq([],{})

// WarnUnimpl::pmaxsd_Vdq_Wdq([],{})

// WarnUnimpl::pmaxuw_Vdq_Wdq([],{})

// WarnUnimpl::pmaxud_Vdq_Wdq([],{})

// WarnUnimpl::pmulld_Vdq_Wdq([],{})

// WarnUnimpl::phminposuw_Vdq_Wdq([],{})

// Inst::UD2(([], {}))

// WarnUnimpl::crc32_Gd_Eb([],{})

// WarnUnimpl::crc32_Gd_Ev([],{})

// Inst::UD2(([], {}))

// WarnUnimpl::pshufb_Pq_Qq([],{})

// WarnUnimpl::phaddw_Pq_Qq([],{})

// WarnUnimpl::phaddd_Pq_Qq([],{})

// WarnUnimpl::phaddsw_Pq_Qq([],{})

// WarnUnimpl::pmaddubsw_Pq_Qq([],{})

// WarnUnimpl::phsubw_Pq_Qq([],{})

// WarnUnimpl::phsubd_Pq_Qq([],{})

// WarnUnimpl::phsubsw_Pq_Qq([],{})

// WarnUnimpl::psignb_Pq_Qq([],{})

// WarnUnimpl::psignw_Pq_Qq([],{})

// WarnUnimpl::psignd_Pq_Qq([],{})

// WarnUnimpl::pmulhrsw_Pq_Qq([],{})

// WarnUnimpl::pabsb_Pq_Qq([],{})

// WarnUnimpl::pabsw_Pq_Qq([],{})

// WarnUnimpl::pabsd_Pq_Qq([],{})

// Inst::UD2(([], {}))

// WarnUnimpl::roundps_Vdq_Wdq_Ib([],{})

// WarnUnimpl::roundpd_Vdq_Wdq_Ib([],{})

// WarnUnimpl::roundss_Vss_Wss_Ib([],{})

// WarnUnimpl::roundsd_Vsd_Wsd_Ib([],{})

// WarnUnimpl::blendps_Vdq_Wdq_Ib([],{})

// WarnUnimpl::blendpd_Vdq_Wdq_Ib([],{})

// WarnUnimpl::pblendw_Vdq_Wdq_Ib([],{})

// WarnUnimpl::palignr_Vdq_Wdq_Ib([],{})

// WarnUnimpl::pextrb_Rd_or_Mb_Vdq_Ib([],{})

// Inst::PEXTRW((['Rd', 'Vdq', 'Ib'], {}))

// WarnUnimpl::pextrw_Mw_Vdq_Ib([],{})

// WarnUnimpl::pextrd_pextrq_Ed_or_Eq_Vdq_Ib([],{})

// WarnUnimpl::extractps_Ed_Vdq_Ib([],{})

// WarnUnimpl::pinsrb_Vdq_Rd_or_Rq_or_Mb_Ib([],{})

// WarnUnimpl::insertps_Vdq_Udq_or_Md_Ib([],{})

// WarnUnimpl::pinsrd_pinsrq_Vdq_Ed_or_Eq_Ib([],{})

// WarnUnimpl::dpps_Vdq_Wdq_Ib([],{})

// WarnUnimpl::dppd_Vdq_Wdq_Ib([],{})

// WarnUnimpl::pcmpistrm_Vdq_Wdq_Ib([],{})

// WarnUnimpl::pcmpistri_Vdq_Wdq_Ib([],{})

// Inst::UD2(([], {}))

// WarnUnimpl::palignr_Pq_Qq_Ib([],{})

// Inst::UD2(([], {}))

// Unknown::unknown(([], {}))

// Inst::UD2([],{})

// MultiInst::ADD_LOCKED((['OPCODE_OP_BOTTOM3', ['Gb'], ['Gv']], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "add".
             */
            class ADD_LOCKED_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADD_LOCKED_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "add".
             */
            class ADD_LOCKED_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADD_LOCKED_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// MultiInst::OR_LOCKED((['OPCODE_OP_BOTTOM3', ['Gb'], ['Gv']], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "or".
             */
            class OR_LOCKED_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                OR_LOCKED_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "or".
             */
            class OR_LOCKED_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                OR_LOCKED_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// MultiInst::ADC_LOCKED((['OPCODE_OP_BOTTOM3', ['Gb'], ['Gv']], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "adc".
             */
            class ADC_LOCKED_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADC_LOCKED_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "adc".
             */
            class ADC_LOCKED_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADC_LOCKED_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// MultiInst::SBB_LOCKED((['OPCODE_OP_BOTTOM3', ['Gb'], ['Gv']], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sbb".
             */
            class SBB_LOCKED_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SBB_LOCKED_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sbb".
             */
            class SBB_LOCKED_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SBB_LOCKED_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// MultiInst::AND_LOCKED((['OPCODE_OP_BOTTOM3', ['Gb'], ['Gv']], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "and".
             */
            class AND_LOCKED_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                AND_LOCKED_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "and".
             */
            class AND_LOCKED_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                AND_LOCKED_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// MultiInst::SUB_LOCKED((['OPCODE_OP_BOTTOM3', ['Gb'], ['Gv']], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sub".
             */
            class SUB_LOCKED_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SUB_LOCKED_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sub".
             */
            class SUB_LOCKED_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SUB_LOCKED_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// MultiInst::XOR_LOCKED((['OPCODE_OP_BOTTOM3', ['Gb'], ['Gv']], {}))

        namespace X86Macroop
        {
            /**
             * Static instruction class for "xor".
             */
            class XOR_LOCKED_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                XOR_LOCKED_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "xor".
             */
            class XOR_LOCKED_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                XOR_LOCKED_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::ADD_LOCKED(['Mb', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "add".
             */
            class ADD_LOCKED_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADD_LOCKED_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "add".
             */
            class ADD_LOCKED_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADD_LOCKED_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::OR_LOCKED(['Mb', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "or".
             */
            class OR_LOCKED_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                OR_LOCKED_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "or".
             */
            class OR_LOCKED_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                OR_LOCKED_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::ADC_LOCKED(['Mb', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "adc".
             */
            class ADC_LOCKED_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADC_LOCKED_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "adc".
             */
            class ADC_LOCKED_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                ADC_LOCKED_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SBB_LOCKED(['Mb', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sbb".
             */
            class SBB_LOCKED_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SBB_LOCKED_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sbb".
             */
            class SBB_LOCKED_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SBB_LOCKED_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::AND_LOCKED(['Mb', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "and".
             */
            class AND_LOCKED_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                AND_LOCKED_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "and".
             */
            class AND_LOCKED_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                AND_LOCKED_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::SUB_LOCKED(['Mb', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sub".
             */
            class SUB_LOCKED_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SUB_LOCKED_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "sub".
             */
            class SUB_LOCKED_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                SUB_LOCKED_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::XOR_LOCKED(['Mb', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "xor".
             */
            class XOR_LOCKED_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                XOR_LOCKED_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "xor".
             */
            class XOR_LOCKED_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                XOR_LOCKED_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::ADD_LOCKED(['Mv', 'Iz'],{})

// Inst::OR_LOCKED(['Mv', 'Iz'],{})

// Inst::ADC_LOCKED(['Mv', 'Iz'],{})

// Inst::SBB_LOCKED(['Mv', 'Iz'],{})

// Inst::AND_LOCKED(['Mv', 'Iz'],{})

// Inst::SUB_LOCKED(['Mv', 'Iz'],{})

// Inst::XOR_LOCKED(['Mv', 'Iz'],{})

// Unknown::unknown(([], {}))

// Inst::UD2([],{})

// Inst::ADD_LOCKED(['Mb', 'Ib'],{})

// Inst::OR_LOCKED(['Mb', 'Ib'],{})

// Inst::ADC_LOCKED(['Mb', 'Ib'],{})

// Inst::SBB_LOCKED(['Mb', 'Ib'],{})

// Inst::AND_LOCKED(['Mb', 'Ib'],{})

// Inst::SUB_LOCKED(['Mb', 'Ib'],{})

// Inst::XOR_LOCKED(['Mb', 'Ib'],{})

// Unknown::unknown(([], {}))

// Inst::ADD_LOCKED(['Mv', 'Ib'],{})

// Inst::OR_LOCKED(['Mv', 'Ib'],{})

// Inst::ADC_LOCKED(['Mv', 'Ib'],{})

// Inst::SBB_LOCKED(['Mv', 'Ib'],{})

// Inst::AND_LOCKED(['Mv', 'Ib'],{})

// Inst::SUB_LOCKED(['Mv', 'Ib'],{})

// Inst::XOR_LOCKED(['Mv', 'Ib'],{})

// Unknown::unknown(([], {}))

// Inst::XCHG_LOCKED(['Mb', 'Gb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "xchg".
             */
            class XCHG_LOCKED_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                XCHG_LOCKED_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "xchg".
             */
            class XCHG_LOCKED_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                XCHG_LOCKED_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::XCHG_LOCKED(['Mv', 'Gv'],{})

// Unknown::unknown(([], {}))

// Inst::NOT_LOCKED(['Mb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "not".
             */
            class NOT_LOCKED_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                NOT_LOCKED_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "not".
             */
            class NOT_LOCKED_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                NOT_LOCKED_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::NEG_LOCKED(['Mb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "neg".
             */
            class NEG_LOCKED_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                NEG_LOCKED_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "neg".
             */
            class NEG_LOCKED_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                NEG_LOCKED_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::NOT_LOCKED(['Mv'],{})

// Inst::NEG_LOCKED(['Mv'],{})

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Inst::INC_LOCKED(['Mb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "inc".
             */
            class INC_LOCKED_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                INC_LOCKED_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "inc".
             */
            class INC_LOCKED_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                INC_LOCKED_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::DEC_LOCKED(['Mb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "dec".
             */
            class DEC_LOCKED_M : public Macroop
            {
              private:
                
              public:
                // Constructor.
                DEC_LOCKED_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "dec".
             */
            class DEC_LOCKED_P : public Macroop
            {
              private:
                
              public:
                // Constructor.
                DEC_LOCKED_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::UD2([],{})

// Inst::INC_LOCKED(['Mv'],{})

// Inst::DEC_LOCKED(['Mv'],{})

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// WarnUnimpl::mov_Rd_CR8D(([], {}))

// WarnUnimpl::mov_CR8D_Rd(([], {}))

// Unknown::unknown(([], {}))

// Inst::BTS_LOCKED(['Mv', 'Gv'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "bts".
             */
            class BTS_LOCKED_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTS_LOCKED_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "bts".
             */
            class BTS_LOCKED_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTS_LOCKED_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::CMPXCHG_LOCKED(['Mb', 'Gb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmpxchg".
             */
            class CMPXCHG_LOCKED_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMPXCHG_LOCKED_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmpxchg".
             */
            class CMPXCHG_LOCKED_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                CMPXCHG_LOCKED_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::CMPXCHG_LOCKED(['Mv', 'Gv'],{})

// Inst::BTR_LOCKED(['Mv', 'Gv'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "btr".
             */
            class BTR_LOCKED_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTR_LOCKED_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "btr".
             */
            class BTR_LOCKED_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTR_LOCKED_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::BTS_LOCKED(['Mv', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "bts".
             */
            class BTS_LOCKED_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTS_LOCKED_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "bts".
             */
            class BTS_LOCKED_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTS_LOCKED_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::BTR_LOCKED(['Mv', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "btr".
             */
            class BTR_LOCKED_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTR_LOCKED_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "btr".
             */
            class BTR_LOCKED_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTR_LOCKED_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::BTC_LOCKED(['Mv', 'Ib'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "btc".
             */
            class BTC_LOCKED_M_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTC_LOCKED_M_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "btc".
             */
            class BTC_LOCKED_P_I : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTC_LOCKED_P_I(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::BTC_LOCKED(['Mv', 'Gv'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "btc".
             */
            class BTC_LOCKED_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTC_LOCKED_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "btc".
             */
            class BTC_LOCKED_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                BTC_LOCKED_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Inst::XADD_LOCKED(['Mb', 'Gb'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "xadd".
             */
            class XADD_LOCKED_M_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                XADD_LOCKED_M_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "xadd".
             */
            class XADD_LOCKED_P_R : public Macroop
            {
              private:
                
              public:
                // Constructor.
                XADD_LOCKED_P_R(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Inst::XADD_LOCKED(['Mv', 'Gv'],{})

// Inst::CMPXCHG8B_LOCKED(['Mdp'],{})

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmpxchg8b".
             */
            class CMPXCHG8B_LOCKED_M : public Macroop
            {
              private:
                const static uint64_t label_doneComparing = 6;

              public:
                // Constructor.
                CMPXCHG8B_LOCKED_M(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

        namespace X86Macroop
        {
            /**
             * Static instruction class for "cmpxchg8b".
             */
            class CMPXCHG8B_LOCKED_P : public Macroop
            {
              private:
                const static uint64_t label_doneComparing = 7;

              public:
                // Constructor.
                CMPXCHG8B_LOCKED_P(ExtMachInst machInst, X86ISA::EmulEnv _env);

                std::string
                generateDisassembly(Addr pc, const SymbolTable *symtab) const;
            };
        }

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))
