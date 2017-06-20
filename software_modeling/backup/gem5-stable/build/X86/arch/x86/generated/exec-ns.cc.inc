// DO NOT EDIT
// This file was automatically generated from an ISA description:
//   x86/isa/main.isa

#if !defined(__SPLIT) || (__SPLIT == 1)

        Fault Unknown::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            return std::make_shared<InvalidOpcode>();
        }

    Fault
    FailUnimplemented::execute(CPU_EXEC_CONTEXT *xc,
                               Trace::InstRecord *traceData) const
    {
        panic("attempt to execute unimplemented instruction '%s' %s",
                mnemonic, machInst);
        return NoFault;
    }

    Fault
    WarnUnimplemented::execute(CPU_EXEC_CONTEXT *xc,
                               Trace::InstRecord *traceData) const
    {
        if (!warned) {
            warn("instruction '%s' unimplemented\n", mnemonic);
            warned = true;
        }

        return NoFault;
    }

        Fault MovfpTopTag::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t FpSrcReg1 = 0;
uint64_t FpDestReg = 0;
uint8_t TOP = 0;
uint16_t FTW = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpDestReg = xc->readFloatRegOperandBits(this, 1);
TOP = xc->readMiscRegOperand(this, 2);
FTW = xc->readMiscRegOperand(this, 3);
;

            if(true)
            {
                FpDestReg = FpSrcReg1;;
                ;
                FTW = genX87Tags(FTW, TOP, spm);;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                FpDestReg = FpDestReg;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); }xc->setMiscRegOperand(this, 2, FTW);
if (traceData) { traceData->setData(FTW); };
            }
            return fault;
        }

        Fault MovfpTop::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t FpSrcReg1 = 0;
uint64_t FpDestReg = 0;
uint8_t TOP = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpDestReg = xc->readFloatRegOperandBits(this, 1);
TOP = xc->readMiscRegOperand(this, 2);
;

            if(true)
            {
                FpDestReg = FpSrcReg1;;
                ;
                ;;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                FpDestReg = FpDestReg;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); };
            }
            return fault;
        }

        Fault Movfp::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t FpSrcReg1 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpDestReg = xc->readFloatRegOperandBits(this, 1);
;

            if(true)
            {
                FpDestReg = FpSrcReg1;;
                ;
                ;;
                ;;
            }
            else
            {
                FpDestReg = FpDestReg;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault MovfpFlagsTopTag::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t FpSrcReg1 = 0;
uint64_t FpDestReg = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
uint8_t TOP = 0;
uint16_t FTW = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpDestReg = xc->readFloatRegOperandBits(this, 1);
ccFlagBits = xc->readCCRegOperand(this, 2);
cfofBits = xc->readCCRegOperand(this, 3);
dfBit = xc->readCCRegOperand(this, 4);
ecfBit = xc->readCCRegOperand(this, 5);
ezfBit = xc->readCCRegOperand(this, 6);
TOP = xc->readMiscRegOperand(this, 7);
FTW = xc->readMiscRegOperand(this, 8);
;

            if(checkCondition(ccFlagBits | cfofBits | dfBit |                                      ecfBit | ezfBit, src2))
            {
                FpDestReg = FpSrcReg1;;
                ;
                FTW = genX87Tags(FTW, TOP, spm);;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                FpDestReg = FpDestReg;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); }xc->setMiscRegOperand(this, 2, FTW);
if (traceData) { traceData->setData(FTW); };
            }
            return fault;
        }

        Fault MovfpFlagsTop::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t FpSrcReg1 = 0;
uint64_t FpDestReg = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
uint8_t TOP = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpDestReg = xc->readFloatRegOperandBits(this, 1);
ccFlagBits = xc->readCCRegOperand(this, 2);
cfofBits = xc->readCCRegOperand(this, 3);
dfBit = xc->readCCRegOperand(this, 4);
ecfBit = xc->readCCRegOperand(this, 5);
ezfBit = xc->readCCRegOperand(this, 6);
TOP = xc->readMiscRegOperand(this, 7);
;

            if(checkCondition(ccFlagBits | cfofBits | dfBit |                                      ecfBit | ezfBit, src2))
            {
                FpDestReg = FpSrcReg1;;
                ;
                ;;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                FpDestReg = FpDestReg;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); };
            }
            return fault;
        }

        Fault MovfpFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t FpSrcReg1 = 0;
uint64_t FpDestReg = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpDestReg = xc->readFloatRegOperandBits(this, 1);
ccFlagBits = xc->readCCRegOperand(this, 2);
cfofBits = xc->readCCRegOperand(this, 3);
dfBit = xc->readCCRegOperand(this, 4);
ecfBit = xc->readCCRegOperand(this, 5);
ezfBit = xc->readCCRegOperand(this, 6);
;

            if(checkCondition(ccFlagBits | cfofBits | dfBit |                                      ecfBit | ezfBit, src2))
            {
                FpDestReg = FpSrcReg1;;
                ;
                ;;
                ;;
            }
            else
            {
                FpDestReg = FpDestReg;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault XorfpTopTag::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t FpDestReg = 0;
uint8_t TOP = 0;
uint16_t FTW = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
TOP = xc->readMiscRegOperand(this, 2);
FTW = xc->readMiscRegOperand(this, 3);
;

            if(true)
            {
                FpDestReg = FpSrcReg1 ^ FpSrcReg2;;
                ;
                FTW = genX87Tags(FTW, TOP, spm);;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); }xc->setMiscRegOperand(this, 2, FTW);
if (traceData) { traceData->setData(FTW); };
            }
            return fault;
        }

        Fault XorfpTop::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t FpDestReg = 0;
uint8_t TOP = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
TOP = xc->readMiscRegOperand(this, 2);
;

            if(true)
            {
                FpDestReg = FpSrcReg1 ^ FpSrcReg2;;
                ;
                ;;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); };
            }
            return fault;
        }

        Fault Xorfp::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
;

            if(true)
            {
                FpDestReg = FpSrcReg1 ^ FpSrcReg2;;
                ;
                ;;
                ;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SqrtfpTopTag::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg2 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
uint16_t FTW = 0;
;
            FpSrcReg2 = xc->readFloatRegOperand(this, 0);
TOP = xc->readMiscRegOperand(this, 1);
FTW = xc->readMiscRegOperand(this, 2);
;

            if(true)
            {
                FpDestReg = sqrt(FpSrcReg2);;
                ;
                FTW = genX87Tags(FTW, TOP, spm);;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); }xc->setMiscRegOperand(this, 2, FTW);
if (traceData) { traceData->setData(FTW); };
            }
            return fault;
        }

        Fault SqrtfpTop::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg2 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
;
            FpSrcReg2 = xc->readFloatRegOperand(this, 0);
TOP = xc->readMiscRegOperand(this, 1);
;

            if(true)
            {
                FpDestReg = sqrt(FpSrcReg2);;
                ;
                ;;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); };
            }
            return fault;
        }

        Fault Sqrtfp::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg2 = 0;
double FpDestReg = 0;
;
            FpSrcReg2 = xc->readFloatRegOperand(this, 0);
;

            if(true)
            {
                FpDestReg = sqrt(FpSrcReg2);;
                ;
                ;;
                ;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault CosfpTopTag::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
uint16_t FTW = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
TOP = xc->readMiscRegOperand(this, 1);
FTW = xc->readMiscRegOperand(this, 2);
;

            if(true)
            {
                FpDestReg = cos(FpSrcReg1);;
                ;
                FTW = genX87Tags(FTW, TOP, spm);;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); }xc->setMiscRegOperand(this, 2, FTW);
if (traceData) { traceData->setData(FTW); };
            }
            return fault;
        }

        Fault CosfpTop::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
TOP = xc->readMiscRegOperand(this, 1);
;

            if(true)
            {
                FpDestReg = cos(FpSrcReg1);;
                ;
                ;;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); };
            }
            return fault;
        }

        Fault Cosfp::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
;

            if(true)
            {
                FpDestReg = cos(FpSrcReg1);;
                ;
                ;;
                ;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SinfpTopTag::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
uint16_t FTW = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
TOP = xc->readMiscRegOperand(this, 1);
FTW = xc->readMiscRegOperand(this, 2);
;

            if(true)
            {
                FpDestReg = sin(FpSrcReg1);;
                ;
                FTW = genX87Tags(FTW, TOP, spm);;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); }xc->setMiscRegOperand(this, 2, FTW);
if (traceData) { traceData->setData(FTW); };
            }
            return fault;
        }

        Fault SinfpTop::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
TOP = xc->readMiscRegOperand(this, 1);
;

            if(true)
            {
                FpDestReg = sin(FpSrcReg1);;
                ;
                ;;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); };
            }
            return fault;
        }

        Fault Sinfp::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
;

            if(true)
            {
                FpDestReg = sin(FpSrcReg1);;
                ;
                ;;
                ;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault TanfpTopTag::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
uint16_t FTW = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
TOP = xc->readMiscRegOperand(this, 1);
FTW = xc->readMiscRegOperand(this, 2);
;

            if(true)
            {
                FpDestReg = tan(FpSrcReg1);;
                ;
                FTW = genX87Tags(FTW, TOP, spm);;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); }xc->setMiscRegOperand(this, 2, FTW);
if (traceData) { traceData->setData(FTW); };
            }
            return fault;
        }

        Fault TanfpTop::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
TOP = xc->readMiscRegOperand(this, 1);
;

            if(true)
            {
                FpDestReg = tan(FpSrcReg1);;
                ;
                ;;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); };
            }
            return fault;
        }

        Fault Tanfp::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
;

            if(true)
            {
                FpDestReg = tan(FpSrcReg1);;
                ;
                ;;
                ;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault cvtf_i2dTopTag::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SSrcReg1 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
uint16_t FTW = 0;
;
            SSrcReg1 = xc->readIntRegOperand(this, 0);
TOP = xc->readMiscRegOperand(this, 1);
FTW = xc->readMiscRegOperand(this, 2);
;

            if(true)
            {
                
            X86IntReg intReg = SSrcReg1;
            if (REX_W)
                FpDestReg = intReg.SR;
            else
                FpDestReg = intReg.SE;
            ;
                ;
                FTW = genX87Tags(FTW, TOP, spm);;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); }xc->setMiscRegOperand(this, 2, FTW);
if (traceData) { traceData->setData(FTW); };
            }
            return fault;
        }

        Fault cvtf_i2dTop::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SSrcReg1 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
;
            SSrcReg1 = xc->readIntRegOperand(this, 0);
TOP = xc->readMiscRegOperand(this, 1);
;

            if(true)
            {
                
            X86IntReg intReg = SSrcReg1;
            if (REX_W)
                FpDestReg = intReg.SR;
            else
                FpDestReg = intReg.SE;
            ;
                ;
                ;;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); };
            }
            return fault;
        }

        Fault cvtf_i2d::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SSrcReg1 = 0;
double FpDestReg = 0;
;
            SSrcReg1 = xc->readIntRegOperand(this, 0);
;

            if(true)
            {
                
            X86IntReg intReg = SSrcReg1;
            if (REX_W)
                FpDestReg = intReg.SR;
            else
                FpDestReg = intReg.SE;
            ;
                ;
                ;;
                ;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault cvtf_i2d_hiTopTag::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SSrcReg1 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
uint16_t FTW = 0;
;
            SSrcReg1 = xc->readIntRegOperand(this, 0);
TOP = xc->readMiscRegOperand(this, 1);
FTW = xc->readMiscRegOperand(this, 2);
;

            if(true)
            {
                FpDestReg = bits(SSrcReg1, 63, 32);;
                ;
                FTW = genX87Tags(FTW, TOP, spm);;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); }xc->setMiscRegOperand(this, 2, FTW);
if (traceData) { traceData->setData(FTW); };
            }
            return fault;
        }

        Fault cvtf_i2d_hiTop::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SSrcReg1 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
;
            SSrcReg1 = xc->readIntRegOperand(this, 0);
TOP = xc->readMiscRegOperand(this, 1);
;

            if(true)
            {
                FpDestReg = bits(SSrcReg1, 63, 32);;
                ;
                ;;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); };
            }
            return fault;
        }

        Fault cvtf_i2d_hi::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SSrcReg1 = 0;
double FpDestReg = 0;
;
            SSrcReg1 = xc->readIntRegOperand(this, 0);
;

            if(true)
            {
                FpDestReg = bits(SSrcReg1, 63, 32);;
                ;
                ;;
                ;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault cvtf_d2iTopTag::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SDestReg = 0;
double FpSrcReg1 = 0;
uint8_t TOP = 0;
uint16_t FTW = 0;
;
            SDestReg = xc->readIntRegOperand(this, 0);
FpSrcReg1 = xc->readFloatRegOperand(this, 1);
TOP = xc->readMiscRegOperand(this, 2);
FTW = xc->readMiscRegOperand(this, 3);
;

            if(true)
            {
                
            int64_t intSrcReg1 = static_cast<int64_t>(FpSrcReg1);
            if (REX_W)
                SDestReg = intSrcReg1;
            else
                SDestReg = merge(SDestReg, intSrcReg1, 4);
            ;
                ;
                FTW = genX87Tags(FTW, TOP, spm);;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = SDestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); }xc->setMiscRegOperand(this, 2, FTW);
if (traceData) { traceData->setData(FTW); };
            }
            return fault;
        }

        Fault cvtf_d2iTop::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SDestReg = 0;
double FpSrcReg1 = 0;
uint8_t TOP = 0;
;
            SDestReg = xc->readIntRegOperand(this, 0);
FpSrcReg1 = xc->readFloatRegOperand(this, 1);
TOP = xc->readMiscRegOperand(this, 2);
;

            if(true)
            {
                
            int64_t intSrcReg1 = static_cast<int64_t>(FpSrcReg1);
            if (REX_W)
                SDestReg = intSrcReg1;
            else
                SDestReg = merge(SDestReg, intSrcReg1, 4);
            ;
                ;
                ;;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = SDestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); };
            }
            return fault;
        }

        Fault cvtf_d2i::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SDestReg = 0;
double FpSrcReg1 = 0;
;
            SDestReg = xc->readIntRegOperand(this, 0);
FpSrcReg1 = xc->readFloatRegOperand(this, 1);
;

            if(true)
            {
                
            int64_t intSrcReg1 = static_cast<int64_t>(FpSrcReg1);
            if (REX_W)
                SDestReg = intSrcReg1;
            else
                SDestReg = merge(SDestReg, intSrcReg1, 4);
            ;
                ;
                ;;
                ;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = SDestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault cvtint_fp80TopTag::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SSrcReg1 = 0;
uint64_t SSrcReg2 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
uint16_t FTW = 0;
;
            SSrcReg1 = xc->readIntRegOperand(this, 0);
SSrcReg2 = xc->readIntRegOperand(this, 1);
TOP = xc->readMiscRegOperand(this, 2);
FTW = xc->readMiscRegOperand(this, 3);
;

            if(true)
            {
                
            uint8_t bits[10];
            *(uint64_t *)(bits + 0) = SSrcReg1;
            *(uint16_t *)(bits + 8) = (uint16_t)SSrcReg2;
            FpDestReg = loadFloat80(bits);
            ;
                ;
                FTW = genX87Tags(FTW, TOP, spm);;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); }xc->setMiscRegOperand(this, 2, FTW);
if (traceData) { traceData->setData(FTW); };
            }
            return fault;
        }

        Fault cvtint_fp80Top::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SSrcReg1 = 0;
uint64_t SSrcReg2 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
;
            SSrcReg1 = xc->readIntRegOperand(this, 0);
SSrcReg2 = xc->readIntRegOperand(this, 1);
TOP = xc->readMiscRegOperand(this, 2);
;

            if(true)
            {
                
            uint8_t bits[10];
            *(uint64_t *)(bits + 0) = SSrcReg1;
            *(uint16_t *)(bits + 8) = (uint16_t)SSrcReg2;
            FpDestReg = loadFloat80(bits);
            ;
                ;
                ;;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); };
            }
            return fault;
        }

        Fault cvtint_fp80::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SSrcReg1 = 0;
uint64_t SSrcReg2 = 0;
double FpDestReg = 0;
;
            SSrcReg1 = xc->readIntRegOperand(this, 0);
SSrcReg2 = xc->readIntRegOperand(this, 1);
;

            if(true)
            {
                
            uint8_t bits[10];
            *(uint64_t *)(bits + 0) = SSrcReg1;
            *(uint16_t *)(bits + 8) = (uint16_t)SSrcReg2;
            FpDestReg = loadFloat80(bits);
            ;
                ;
                ;;
                ;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault cvtfp80h_intTopTag::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SDestReg = 0;
double FpSrcReg1 = 0;
uint8_t TOP = 0;
uint16_t FTW = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
TOP = xc->readMiscRegOperand(this, 1);
FTW = xc->readMiscRegOperand(this, 2);
;

            if(true)
            {
                
            char bits[10];
            storeFloat80(bits, FpSrcReg1);
            SDestReg = *(uint64_t *)(bits + 0);
            ;
                ;
                FTW = genX87Tags(FTW, TOP, spm);;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = SDestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); }xc->setMiscRegOperand(this, 2, FTW);
if (traceData) { traceData->setData(FTW); };
            }
            return fault;
        }

        Fault cvtfp80h_intTop::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SDestReg = 0;
double FpSrcReg1 = 0;
uint8_t TOP = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
TOP = xc->readMiscRegOperand(this, 1);
;

            if(true)
            {
                
            char bits[10];
            storeFloat80(bits, FpSrcReg1);
            SDestReg = *(uint64_t *)(bits + 0);
            ;
                ;
                ;;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = SDestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); };
            }
            return fault;
        }

        Fault cvtfp80h_int::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SDestReg = 0;
double FpSrcReg1 = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
;

            if(true)
            {
                
            char bits[10];
            storeFloat80(bits, FpSrcReg1);
            SDestReg = *(uint64_t *)(bits + 0);
            ;
                ;
                ;;
                ;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = SDestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault cvtfp80l_intTopTag::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SDestReg = 0;
double FpSrcReg1 = 0;
uint8_t TOP = 0;
uint16_t FTW = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
TOP = xc->readMiscRegOperand(this, 1);
FTW = xc->readMiscRegOperand(this, 2);
;

            if(true)
            {
                
            char bits[10];
            storeFloat80(bits, FpSrcReg1);
            SDestReg = *(uint16_t *)(bits + 8);
            ;
                ;
                FTW = genX87Tags(FTW, TOP, spm);;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = SDestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); }xc->setMiscRegOperand(this, 2, FTW);
if (traceData) { traceData->setData(FTW); };
            }
            return fault;
        }

        Fault cvtfp80l_intTop::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SDestReg = 0;
double FpSrcReg1 = 0;
uint8_t TOP = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
TOP = xc->readMiscRegOperand(this, 1);
;

            if(true)
            {
                
            char bits[10];
            storeFloat80(bits, FpSrcReg1);
            SDestReg = *(uint16_t *)(bits + 8);
            ;
                ;
                ;;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = SDestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); };
            }
            return fault;
        }

        Fault cvtfp80l_int::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SDestReg = 0;
double FpSrcReg1 = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
;

            if(true)
            {
                
            char bits[10];
            storeFloat80(bits, FpSrcReg1);
            SDestReg = *(uint16_t *)(bits + 8);
            ;
                ;
                ;;
                ;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = SDestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault addfpTopTag::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpSrcReg2 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
uint16_t FTW = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
FpSrcReg2 = xc->readFloatRegOperand(this, 1);
TOP = xc->readMiscRegOperand(this, 2);
FTW = xc->readMiscRegOperand(this, 3);
;

            if(true)
            {
                FpDestReg = FpSrcReg1 + FpSrcReg2;;
                ;
                FTW = genX87Tags(FTW, TOP, spm);;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); }xc->setMiscRegOperand(this, 2, FTW);
if (traceData) { traceData->setData(FTW); };
            }
            return fault;
        }

        Fault addfpTop::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpSrcReg2 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
FpSrcReg2 = xc->readFloatRegOperand(this, 1);
TOP = xc->readMiscRegOperand(this, 2);
;

            if(true)
            {
                FpDestReg = FpSrcReg1 + FpSrcReg2;;
                ;
                ;;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); };
            }
            return fault;
        }

        Fault addfp::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpSrcReg2 = 0;
double FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
FpSrcReg2 = xc->readFloatRegOperand(this, 1);
;

            if(true)
            {
                FpDestReg = FpSrcReg1 + FpSrcReg2;;
                ;
                ;;
                ;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault mulfpTopTag::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpSrcReg2 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
uint16_t FTW = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
FpSrcReg2 = xc->readFloatRegOperand(this, 1);
TOP = xc->readMiscRegOperand(this, 2);
FTW = xc->readMiscRegOperand(this, 3);
;

            if(true)
            {
                FpDestReg = FpSrcReg1 * FpSrcReg2;;
                ;
                FTW = genX87Tags(FTW, TOP, spm);;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); }xc->setMiscRegOperand(this, 2, FTW);
if (traceData) { traceData->setData(FTW); };
            }
            return fault;
        }

        Fault mulfpTop::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpSrcReg2 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
FpSrcReg2 = xc->readFloatRegOperand(this, 1);
TOP = xc->readMiscRegOperand(this, 2);
;

            if(true)
            {
                FpDestReg = FpSrcReg1 * FpSrcReg2;;
                ;
                ;;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); };
            }
            return fault;
        }

        Fault mulfp::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpSrcReg2 = 0;
double FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
FpSrcReg2 = xc->readFloatRegOperand(this, 1);
;

            if(true)
            {
                FpDestReg = FpSrcReg1 * FpSrcReg2;;
                ;
                ;;
                ;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault divfpTopTag::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpSrcReg2 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
uint16_t FTW = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
FpSrcReg2 = xc->readFloatRegOperand(this, 1);
TOP = xc->readMiscRegOperand(this, 2);
FTW = xc->readMiscRegOperand(this, 3);
;

            if(true)
            {
                FpDestReg = FpSrcReg1 / FpSrcReg2;;
                ;
                FTW = genX87Tags(FTW, TOP, spm);;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); }xc->setMiscRegOperand(this, 2, FTW);
if (traceData) { traceData->setData(FTW); };
            }
            return fault;
        }

        Fault divfpTop::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpSrcReg2 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
FpSrcReg2 = xc->readFloatRegOperand(this, 1);
TOP = xc->readMiscRegOperand(this, 2);
;

            if(true)
            {
                FpDestReg = FpSrcReg1 / FpSrcReg2;;
                ;
                ;;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); };
            }
            return fault;
        }

        Fault divfp::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpSrcReg2 = 0;
double FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
FpSrcReg2 = xc->readFloatRegOperand(this, 1);
;

            if(true)
            {
                FpDestReg = FpSrcReg1 / FpSrcReg2;;
                ;
                ;;
                ;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault subfpTopTag::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpSrcReg2 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
uint16_t FTW = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
FpSrcReg2 = xc->readFloatRegOperand(this, 1);
TOP = xc->readMiscRegOperand(this, 2);
FTW = xc->readMiscRegOperand(this, 3);
;

            if(true)
            {
                FpDestReg = FpSrcReg1 - FpSrcReg2;;
                ;
                FTW = genX87Tags(FTW, TOP, spm);;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); }xc->setMiscRegOperand(this, 2, FTW);
if (traceData) { traceData->setData(FTW); };
            }
            return fault;
        }

        Fault subfpTop::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpSrcReg2 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
FpSrcReg2 = xc->readFloatRegOperand(this, 1);
TOP = xc->readMiscRegOperand(this, 2);
;

            if(true)
            {
                FpDestReg = FpSrcReg1 - FpSrcReg2;;
                ;
                ;;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); };
            }
            return fault;
        }

        Fault subfp::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpSrcReg2 = 0;
double FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
FpSrcReg2 = xc->readFloatRegOperand(this, 1);
;

            if(true)
            {
                FpDestReg = FpSrcReg1 - FpSrcReg2;;
                ;
                ;;
                ;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Yl2xFpTopTag::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpSrcReg2 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
uint16_t FTW = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
FpSrcReg2 = xc->readFloatRegOperand(this, 1);
TOP = xc->readMiscRegOperand(this, 2);
FTW = xc->readMiscRegOperand(this, 3);
;

            if(true)
            {
                
            FpDestReg = FpSrcReg2 * (log(FpSrcReg1) / log(2));
        ;
                ;
                FTW = genX87Tags(FTW, TOP, spm);;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); }xc->setMiscRegOperand(this, 2, FTW);
if (traceData) { traceData->setData(FTW); };
            }
            return fault;
        }

        Fault Yl2xFpTop::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpSrcReg2 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
FpSrcReg2 = xc->readFloatRegOperand(this, 1);
TOP = xc->readMiscRegOperand(this, 2);
;

            if(true)
            {
                
            FpDestReg = FpSrcReg2 * (log(FpSrcReg1) / log(2));
        ;
                ;
                ;;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); };
            }
            return fault;
        }

        Fault Yl2xFp::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpSrcReg2 = 0;
double FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
FpSrcReg2 = xc->readFloatRegOperand(this, 1);
;

            if(true)
            {
                
            FpDestReg = FpSrcReg2 * (log(FpSrcReg1) / log(2));
        ;
                ;
                ;;
                ;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault PremFpTopTag::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpSrcReg2 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
uint16_t FSW = 0;
uint16_t FTW = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
FpSrcReg2 = xc->readFloatRegOperand(this, 1);
FpDestReg = xc->readFloatRegOperand(this, 2);
TOP = xc->readMiscRegOperand(this, 3);
FSW = xc->readMiscRegOperand(this, 4);
FTW = xc->readMiscRegOperand(this, 5);
;

            if(true)
            {
                
            MiscReg new_fsw(FSW);
            int src1_exp;
            int src2_exp;
            std::frexp(FpSrcReg1, &src1_exp);
            std::frexp(FpSrcReg2, &src2_exp);
            const int d(src2_exp - src1_exp);
            if (d < 64) {
                const int64_t q(std::trunc(FpSrcReg2 / FpSrcReg1));
                FpDestReg = FpSrcReg2 - FpSrcReg1 * q;
                new_fsw &= ~(CC0Bit | CC1Bit | CC2Bit | CC2Bit);
                new_fsw |= (q & 0x1) ? CC1Bit : 0;
                new_fsw |= (q & 0x2) ? CC3Bit : 0;
                new_fsw |= (q & 0x4) ? CC0Bit : 0;
            } else {
                const int n(42);
                const int64_t qq(std::trunc(
                    FpSrcReg2 / std::ldexp(FpSrcReg1, d - n)));
                FpDestReg = FpSrcReg2 - std::ldexp(FpSrcReg1 * qq, d - n);
                new_fsw |= CC2Bit;
            }
            DPRINTF(X86, "src1: %lf, src2: %lf, dest: %lf, FSW: 0x%x\n",
                    FpSrcReg1, FpSrcReg2, FpDestReg, new_fsw);
        ;
                ;
                FTW = genX87Tags(FTW, TOP, spm);;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); }xc->setMiscRegOperand(this, 2, FTW);
if (traceData) { traceData->setData(FTW); };
            }
            return fault;
        }

        Fault PremFpTop::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpSrcReg2 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
uint16_t FSW = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
FpSrcReg2 = xc->readFloatRegOperand(this, 1);
FpDestReg = xc->readFloatRegOperand(this, 2);
TOP = xc->readMiscRegOperand(this, 3);
FSW = xc->readMiscRegOperand(this, 4);
;

            if(true)
            {
                
            MiscReg new_fsw(FSW);
            int src1_exp;
            int src2_exp;
            std::frexp(FpSrcReg1, &src1_exp);
            std::frexp(FpSrcReg2, &src2_exp);
            const int d(src2_exp - src1_exp);
            if (d < 64) {
                const int64_t q(std::trunc(FpSrcReg2 / FpSrcReg1));
                FpDestReg = FpSrcReg2 - FpSrcReg1 * q;
                new_fsw &= ~(CC0Bit | CC1Bit | CC2Bit | CC2Bit);
                new_fsw |= (q & 0x1) ? CC1Bit : 0;
                new_fsw |= (q & 0x2) ? CC3Bit : 0;
                new_fsw |= (q & 0x4) ? CC0Bit : 0;
            } else {
                const int n(42);
                const int64_t qq(std::trunc(
                    FpSrcReg2 / std::ldexp(FpSrcReg1, d - n)));
                FpDestReg = FpSrcReg2 - std::ldexp(FpSrcReg1 * qq, d - n);
                new_fsw |= CC2Bit;
            }
            DPRINTF(X86, "src1: %lf, src2: %lf, dest: %lf, FSW: 0x%x\n",
                    FpSrcReg1, FpSrcReg2, FpDestReg, new_fsw);
        ;
                ;
                ;;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); };
            }
            return fault;
        }

        Fault PremFp::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpSrcReg2 = 0;
double FpDestReg = 0;
uint16_t FSW = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
FpSrcReg2 = xc->readFloatRegOperand(this, 1);
FpDestReg = xc->readFloatRegOperand(this, 2);
FSW = xc->readMiscRegOperand(this, 3);
;

            if(true)
            {
                
            MiscReg new_fsw(FSW);
            int src1_exp;
            int src2_exp;
            std::frexp(FpSrcReg1, &src1_exp);
            std::frexp(FpSrcReg2, &src2_exp);
            const int d(src2_exp - src1_exp);
            if (d < 64) {
                const int64_t q(std::trunc(FpSrcReg2 / FpSrcReg1));
                FpDestReg = FpSrcReg2 - FpSrcReg1 * q;
                new_fsw &= ~(CC0Bit | CC1Bit | CC2Bit | CC2Bit);
                new_fsw |= (q & 0x1) ? CC1Bit : 0;
                new_fsw |= (q & 0x2) ? CC3Bit : 0;
                new_fsw |= (q & 0x4) ? CC0Bit : 0;
            } else {
                const int n(42);
                const int64_t qq(std::trunc(
                    FpSrcReg2 / std::ldexp(FpSrcReg1, d - n)));
                FpDestReg = FpSrcReg2 - std::ldexp(FpSrcReg1 * qq, d - n);
                new_fsw |= CC2Bit;
            }
            DPRINTF(X86, "src1: %lf, src2: %lf, dest: %lf, FSW: 0x%x\n",
                    FpSrcReg1, FpSrcReg2, FpDestReg, new_fsw);
        ;
                ;
                ;;
                ;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault PremFpFlagsTopTag::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpSrcReg2 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
uint16_t FSW = 0;
uint16_t FTW = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
FpSrcReg2 = xc->readFloatRegOperand(this, 1);
FpDestReg = xc->readFloatRegOperand(this, 2);
TOP = xc->readMiscRegOperand(this, 3);
FSW = xc->readMiscRegOperand(this, 4);
FTW = xc->readMiscRegOperand(this, 5);
;

            if(true)
            {
                
            MiscReg new_fsw(FSW);
            int src1_exp;
            int src2_exp;
            std::frexp(FpSrcReg1, &src1_exp);
            std::frexp(FpSrcReg2, &src2_exp);
            const int d(src2_exp - src1_exp);
            if (d < 64) {
                const int64_t q(std::trunc(FpSrcReg2 / FpSrcReg1));
                FpDestReg = FpSrcReg2 - FpSrcReg1 * q;
                new_fsw &= ~(CC0Bit | CC1Bit | CC2Bit | CC2Bit);
                new_fsw |= (q & 0x1) ? CC1Bit : 0;
                new_fsw |= (q & 0x2) ? CC3Bit : 0;
                new_fsw |= (q & 0x4) ? CC0Bit : 0;
            } else {
                const int n(42);
                const int64_t qq(std::trunc(
                    FpSrcReg2 / std::ldexp(FpSrcReg1, d - n)));
                FpDestReg = FpSrcReg2 - std::ldexp(FpSrcReg1 * qq, d - n);
                new_fsw |= CC2Bit;
            }
            DPRINTF(X86, "src1: %lf, src2: %lf, dest: %lf, FSW: 0x%x\n",
                    FpSrcReg1, FpSrcReg2, FpDestReg, new_fsw);
        ;
                FSW = new_fsw;;
                FTW = genX87Tags(FTW, TOP, spm);;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); }xc->setMiscRegOperand(this, 2, FSW);
if (traceData) { traceData->setData(FSW); }xc->setMiscRegOperand(this, 3, FTW);
if (traceData) { traceData->setData(FTW); };
            }
            return fault;
        }

        Fault PremFpFlagsTop::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpSrcReg2 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
uint16_t FSW = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
FpSrcReg2 = xc->readFloatRegOperand(this, 1);
FpDestReg = xc->readFloatRegOperand(this, 2);
TOP = xc->readMiscRegOperand(this, 3);
FSW = xc->readMiscRegOperand(this, 4);
;

            if(true)
            {
                
            MiscReg new_fsw(FSW);
            int src1_exp;
            int src2_exp;
            std::frexp(FpSrcReg1, &src1_exp);
            std::frexp(FpSrcReg2, &src2_exp);
            const int d(src2_exp - src1_exp);
            if (d < 64) {
                const int64_t q(std::trunc(FpSrcReg2 / FpSrcReg1));
                FpDestReg = FpSrcReg2 - FpSrcReg1 * q;
                new_fsw &= ~(CC0Bit | CC1Bit | CC2Bit | CC2Bit);
                new_fsw |= (q & 0x1) ? CC1Bit : 0;
                new_fsw |= (q & 0x2) ? CC3Bit : 0;
                new_fsw |= (q & 0x4) ? CC0Bit : 0;
            } else {
                const int n(42);
                const int64_t qq(std::trunc(
                    FpSrcReg2 / std::ldexp(FpSrcReg1, d - n)));
                FpDestReg = FpSrcReg2 - std::ldexp(FpSrcReg1 * qq, d - n);
                new_fsw |= CC2Bit;
            }
            DPRINTF(X86, "src1: %lf, src2: %lf, dest: %lf, FSW: 0x%x\n",
                    FpSrcReg1, FpSrcReg2, FpDestReg, new_fsw);
        ;
                FSW = new_fsw;;
                ;;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); }xc->setMiscRegOperand(this, 2, FSW);
if (traceData) { traceData->setData(FSW); };
            }
            return fault;
        }

        Fault PremFpFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpSrcReg2 = 0;
double FpDestReg = 0;
uint16_t FSW = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
FpSrcReg2 = xc->readFloatRegOperand(this, 1);
FpDestReg = xc->readFloatRegOperand(this, 2);
FSW = xc->readMiscRegOperand(this, 3);
;

            if(true)
            {
                
            MiscReg new_fsw(FSW);
            int src1_exp;
            int src2_exp;
            std::frexp(FpSrcReg1, &src1_exp);
            std::frexp(FpSrcReg2, &src2_exp);
            const int d(src2_exp - src1_exp);
            if (d < 64) {
                const int64_t q(std::trunc(FpSrcReg2 / FpSrcReg1));
                FpDestReg = FpSrcReg2 - FpSrcReg1 * q;
                new_fsw &= ~(CC0Bit | CC1Bit | CC2Bit | CC2Bit);
                new_fsw |= (q & 0x1) ? CC1Bit : 0;
                new_fsw |= (q & 0x2) ? CC3Bit : 0;
                new_fsw |= (q & 0x4) ? CC0Bit : 0;
            } else {
                const int n(42);
                const int64_t qq(std::trunc(
                    FpSrcReg2 / std::ldexp(FpSrcReg1, d - n)));
                FpDestReg = FpSrcReg2 - std::ldexp(FpSrcReg1 * qq, d - n);
                new_fsw |= CC2Bit;
            }
            DPRINTF(X86, "src1: %lf, src2: %lf, dest: %lf, FSW: 0x%x\n",
                    FpSrcReg1, FpSrcReg2, FpDestReg, new_fsw);
        ;
                FSW = new_fsw;;
                ;;
                ;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, FSW);
if (traceData) { traceData->setData(FSW); };
            }
            return fault;
        }

        Fault CompfpTopTag::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpSrcReg2 = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint8_t TOP = 0;
uint16_t FTW = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
FpSrcReg2 = xc->readFloatRegOperand(this, 1);
ccFlagBits = xc->readCCRegOperand(this, 2);
cfofBits = xc->readCCRegOperand(this, 3);
TOP = xc->readMiscRegOperand(this, 4);
FTW = xc->readMiscRegOperand(this, 5);
;

            if(true)
            {
                
            //               ZF PF CF
            // Unordered      1  1  1
            // Greater than   0  0  0
            // Less than      0  0  1
            // Equal          1  0  0
            //           OF = SF = AF = 0
            ccFlagBits = ccFlagBits & ~(SFBit | AFBit | ZFBit | PFBit);
            cfofBits = cfofBits & ~(OFBit | CFBit);
            if (std::isnan(FpSrcReg1) || std::isnan(FpSrcReg2)) {
                ccFlagBits = ccFlagBits | (ZFBit | PFBit);
                cfofBits = cfofBits | CFBit;
            }
            else if(FpSrcReg1 < FpSrcReg2)
                cfofBits = cfofBits | CFBit;
            else if(FpSrcReg1 == FpSrcReg2)
                ccFlagBits = ccFlagBits | ZFBit;
        ;
                ;
                FTW = genX87Tags(FTW, TOP, spm);;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = ccFlagBits;
            xc->setCCRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = cfofBits;
            xc->setCCRegOperand(this, 1, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 2, TOP);
if (traceData) { traceData->setData(TOP); }xc->setMiscRegOperand(this, 3, FTW);
if (traceData) { traceData->setData(FTW); };
            }
            return fault;
        }

        Fault CompfpTop::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpSrcReg2 = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint8_t TOP = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
FpSrcReg2 = xc->readFloatRegOperand(this, 1);
ccFlagBits = xc->readCCRegOperand(this, 2);
cfofBits = xc->readCCRegOperand(this, 3);
TOP = xc->readMiscRegOperand(this, 4);
;

            if(true)
            {
                
            //               ZF PF CF
            // Unordered      1  1  1
            // Greater than   0  0  0
            // Less than      0  0  1
            // Equal          1  0  0
            //           OF = SF = AF = 0
            ccFlagBits = ccFlagBits & ~(SFBit | AFBit | ZFBit | PFBit);
            cfofBits = cfofBits & ~(OFBit | CFBit);
            if (std::isnan(FpSrcReg1) || std::isnan(FpSrcReg2)) {
                ccFlagBits = ccFlagBits | (ZFBit | PFBit);
                cfofBits = cfofBits | CFBit;
            }
            else if(FpSrcReg1 < FpSrcReg2)
                cfofBits = cfofBits | CFBit;
            else if(FpSrcReg1 == FpSrcReg2)
                ccFlagBits = ccFlagBits | ZFBit;
        ;
                ;
                ;;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = ccFlagBits;
            xc->setCCRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = cfofBits;
            xc->setCCRegOperand(this, 1, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 2, TOP);
if (traceData) { traceData->setData(TOP); };
            }
            return fault;
        }

        Fault Compfp::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpSrcReg2 = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
FpSrcReg2 = xc->readFloatRegOperand(this, 1);
ccFlagBits = xc->readCCRegOperand(this, 2);
cfofBits = xc->readCCRegOperand(this, 3);
;

            if(true)
            {
                
            //               ZF PF CF
            // Unordered      1  1  1
            // Greater than   0  0  0
            // Less than      0  0  1
            // Equal          1  0  0
            //           OF = SF = AF = 0
            ccFlagBits = ccFlagBits & ~(SFBit | AFBit | ZFBit | PFBit);
            cfofBits = cfofBits & ~(OFBit | CFBit);
            if (std::isnan(FpSrcReg1) || std::isnan(FpSrcReg2)) {
                ccFlagBits = ccFlagBits | (ZFBit | PFBit);
                cfofBits = cfofBits | CFBit;
            }
            else if(FpSrcReg1 < FpSrcReg2)
                cfofBits = cfofBits | CFBit;
            else if(FpSrcReg1 == FpSrcReg2)
                ccFlagBits = ccFlagBits | ZFBit;
        ;
                ;
                ;;
                ;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = ccFlagBits;
            xc->setCCRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = cfofBits;
            xc->setCCRegOperand(this, 1, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault absfpTopTag::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
uint16_t FTW = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
TOP = xc->readMiscRegOperand(this, 1);
FTW = xc->readMiscRegOperand(this, 2);
;

            if(true)
            {
                FpDestReg = fabs(FpSrcReg1);;
                ;
                FTW = genX87Tags(FTW, TOP, spm);;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); }xc->setMiscRegOperand(this, 2, FTW);
if (traceData) { traceData->setData(FTW); };
            }
            return fault;
        }

        Fault absfpTop::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
TOP = xc->readMiscRegOperand(this, 1);
;

            if(true)
            {
                FpDestReg = fabs(FpSrcReg1);;
                ;
                ;;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); };
            }
            return fault;
        }

        Fault absfp::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
;

            if(true)
            {
                FpDestReg = fabs(FpSrcReg1);;
                ;
                ;;
                ;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault absfpFlagsTopTag::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
uint16_t FSW = 0;
uint16_t FTW = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
TOP = xc->readMiscRegOperand(this, 1);
FSW = xc->readMiscRegOperand(this, 2);
FTW = xc->readMiscRegOperand(this, 3);
;

            if(true)
            {
                FpDestReg = fabs(FpSrcReg1);;
                FSW = FSW & (~CC1Bit);;
                FTW = genX87Tags(FTW, TOP, spm);;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); }xc->setMiscRegOperand(this, 2, FSW);
if (traceData) { traceData->setData(FSW); }xc->setMiscRegOperand(this, 3, FTW);
if (traceData) { traceData->setData(FTW); };
            }
            return fault;
        }

        Fault absfpFlagsTop::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
uint16_t FSW = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
TOP = xc->readMiscRegOperand(this, 1);
FSW = xc->readMiscRegOperand(this, 2);
;

            if(true)
            {
                FpDestReg = fabs(FpSrcReg1);;
                FSW = FSW & (~CC1Bit);;
                ;;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); }xc->setMiscRegOperand(this, 2, FSW);
if (traceData) { traceData->setData(FSW); };
            }
            return fault;
        }

        Fault absfpFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpDestReg = 0;
uint16_t FSW = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
FSW = xc->readMiscRegOperand(this, 1);
;

            if(true)
            {
                FpDestReg = fabs(FpSrcReg1);;
                FSW = FSW & (~CC1Bit);;
                ;;
                ;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, FSW);
if (traceData) { traceData->setData(FSW); };
            }
            return fault;
        }

        Fault chsfpTopTag::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
uint16_t FTW = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
TOP = xc->readMiscRegOperand(this, 1);
FTW = xc->readMiscRegOperand(this, 2);
;

            if(true)
            {
                FpDestReg = (-1) * (FpSrcReg1);;
                ;
                FTW = genX87Tags(FTW, TOP, spm);;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); }xc->setMiscRegOperand(this, 2, FTW);
if (traceData) { traceData->setData(FTW); };
            }
            return fault;
        }

        Fault chsfpTop::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
TOP = xc->readMiscRegOperand(this, 1);
;

            if(true)
            {
                FpDestReg = (-1) * (FpSrcReg1);;
                ;
                ;;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); };
            }
            return fault;
        }

        Fault chsfp::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
;

            if(true)
            {
                FpDestReg = (-1) * (FpSrcReg1);;
                ;
                ;;
                ;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault chsfpFlagsTopTag::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
uint16_t FSW = 0;
uint16_t FTW = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
TOP = xc->readMiscRegOperand(this, 1);
FSW = xc->readMiscRegOperand(this, 2);
FTW = xc->readMiscRegOperand(this, 3);
;

            if(true)
            {
                FpDestReg = (-1) * (FpSrcReg1);;
                FSW = FSW & (~CC1Bit);;
                FTW = genX87Tags(FTW, TOP, spm);;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); }xc->setMiscRegOperand(this, 2, FSW);
if (traceData) { traceData->setData(FSW); }xc->setMiscRegOperand(this, 3, FTW);
if (traceData) { traceData->setData(FTW); };
            }
            return fault;
        }

        Fault chsfpFlagsTop::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpDestReg = 0;
uint8_t TOP = 0;
uint16_t FSW = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
TOP = xc->readMiscRegOperand(this, 1);
FSW = xc->readMiscRegOperand(this, 2);
;

            if(true)
            {
                FpDestReg = (-1) * (FpSrcReg1);;
                FSW = FSW & (~CC1Bit);;
                ;;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, TOP);
if (traceData) { traceData->setData(TOP); }xc->setMiscRegOperand(this, 2, FSW);
if (traceData) { traceData->setData(FSW); };
            }
            return fault;
        }

        Fault chsfpFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            double FpSrcReg1 = 0;
double FpDestReg = 0;
uint16_t FSW = 0;
;
            FpSrcReg1 = xc->readFloatRegOperand(this, 0);
FSW = xc->readMiscRegOperand(this, 1);
;

            if(true)
            {
                FpDestReg = (-1) * (FpSrcReg1);;
                FSW = FSW & (~CC1Bit);;
                ;;
                ;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            double final_val = FpDestReg;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 1, FSW);
if (traceData) { traceData->setData(FSW); };
            }
            return fault;
        }

        Fault Pop87TopTag::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint8_t TOP = 0;
uint16_t FTW = 0;
;
            TOP = xc->readMiscRegOperand(this, 0);
FTW = xc->readMiscRegOperand(this, 1);
;

            if(true)
            {
                ;
                ;
                FTW = genX87Tags(FTW, TOP, spm);;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                xc->setMiscRegOperand(this, 0, TOP);
if (traceData) { traceData->setData(TOP); }xc->setMiscRegOperand(this, 1, FTW);
if (traceData) { traceData->setData(FTW); };
            }
            return fault;
        }

        Fault Pop87Top::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint8_t TOP = 0;
;
            TOP = xc->readMiscRegOperand(this, 0);
;

            if(true)
            {
                ;
                ;
                ;;
                TOP = (TOP + spm + 8) % 8;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                xc->setMiscRegOperand(this, 0, TOP);
if (traceData) { traceData->setData(TOP); };
            }
            return fault;
        }

        Fault Pop87::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            ;
            ;

            if(true)
            {
                ;
                ;
                ;;
                ;;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

        Fault Add::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
DestReg = xc->readIntRegOperand(this, 2);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);
DestReg = merge(DestReg, result = (psrc1 + psrc2), dataSize);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault AddBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);
DestReg = result = (psrc1 + psrc2) & mask(dataSize * 8);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault AddFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);
DestReg = merge(DestReg, result = (psrc1 + psrc2), dataSize);;
                
            uint64_t newFlags = genFlags(PredccFlagBits | PredcfofBits |
                                    PreddfBit | PredecfBit | PredezfBit,
                                    ext, result, psrc1, psrc2);
            PredcfofBits = newFlags & cfofMask;
            PredecfBit = newFlags & ECFBit;
            PredezfBit = newFlags & EZFBit;
            PreddfBit = newFlags & DFBit;
            PredccFlagBits = newFlags & ccFlagMask;
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault AddFlagsBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);
DestReg = result = (psrc1 + psrc2) & mask(dataSize * 8);;
                
            uint64_t newFlags = genFlags(PredccFlagBits | PredcfofBits |
                                    PreddfBit | PredecfBit | PredezfBit,
                                    ext, result, psrc1, psrc2);
            PredcfofBits = newFlags & cfofMask;
            PredecfBit = newFlags & ECFBit;
            PredezfBit = newFlags & EZFBit;
            PreddfBit = newFlags & DFBit;
            PredccFlagBits = newFlags & ccFlagMask;
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault AddImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
DestReg = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
DestReg = merge(DestReg, result = (psrc1 + imm8), dataSize);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault AddImmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
DestReg = result = (psrc1 + imm8) & mask(dataSize * 8);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault AddFlagsImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
DestReg = merge(DestReg, result = (psrc1 + imm8), dataSize);;
                
            uint64_t newFlags = genFlags(PredccFlagBits | PredcfofBits |
                                    PreddfBit | PredecfBit | PredezfBit,
                                    ext, result, psrc1, imm8);
            PredcfofBits = newFlags & cfofMask;
            PredecfBit = newFlags & ECFBit;
            PredezfBit = newFlags & EZFBit;
            PreddfBit = newFlags & DFBit;
            PredccFlagBits = newFlags & ccFlagMask;
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault AddFlagsImmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
DestReg = result = (psrc1 + imm8) & mask(dataSize * 8);;
                
            uint64_t newFlags = genFlags(PredccFlagBits | PredcfofBits |
                                    PreddfBit | PredecfBit | PredezfBit,
                                    ext, result, psrc1, imm8);
            PredcfofBits = newFlags & cfofMask;
            PredecfBit = newFlags & ECFBit;
            PredezfBit = newFlags & EZFBit;
            PreddfBit = newFlags & DFBit;
            PredccFlagBits = newFlags & ccFlagMask;
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Or::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
DestReg = xc->readIntRegOperand(this, 2);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);
DestReg = merge(DestReg, result = (psrc1 | psrc2), dataSize);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault OrBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);
DestReg = result = (psrc1 | psrc2) & mask(dataSize * 8);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault OrFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);
DestReg = merge(DestReg, result = (psrc1 | psrc2), dataSize);;
                
            //Don't have genFlags handle the OF or CF bits
            uint64_t mask = CFBit | ECFBit | OFBit;
            uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                 PredezfBit, ext & ~mask, result, psrc1, psrc2);
            PredezfBit = newFlags & EZFBit;
            PreddfBit = newFlags & DFBit;
            PredccFlagBits = newFlags & ccFlagMask;
            //If a logic microop wants to set these, it wants to set them to 0.
            PredcfofBits = PredcfofBits & ~((CFBit | OFBit) & ext);
            PredecfBit = PredecfBit & ~(ECFBit & ext);
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault OrFlagsBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);
DestReg = result = (psrc1 | psrc2) & mask(dataSize * 8);;
                
            //Don't have genFlags handle the OF or CF bits
            uint64_t mask = CFBit | ECFBit | OFBit;
            uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                 PredezfBit, ext & ~mask, result, psrc1, psrc2);
            PredezfBit = newFlags & EZFBit;
            PreddfBit = newFlags & DFBit;
            PredccFlagBits = newFlags & ccFlagMask;
            //If a logic microop wants to set these, it wants to set them to 0.
            PredcfofBits = PredcfofBits & ~((CFBit | OFBit) & ext);
            PredecfBit = PredecfBit & ~(ECFBit & ext);
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault OrImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
DestReg = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
DestReg = merge(DestReg, result = (psrc1 | imm8), dataSize);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault OrImmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
DestReg = result = (psrc1 | imm8) & mask(dataSize * 8);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault OrFlagsImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
DestReg = merge(DestReg, result = (psrc1 | imm8), dataSize);;
                
            //Don't have genFlags handle the OF or CF bits
            uint64_t mask = CFBit | ECFBit | OFBit;
            uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                 PredezfBit, ext & ~mask, result, psrc1, imm8);
            PredezfBit = newFlags & EZFBit;
            PreddfBit = newFlags & DFBit;
            PredccFlagBits = newFlags & ccFlagMask;
            //If a logic microop wants to set these, it wants to set them to 0.
            PredcfofBits = PredcfofBits & ~((CFBit | OFBit) & ext);
            PredecfBit = PredecfBit & ~(ECFBit & ext);
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault OrFlagsImmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
DestReg = result = (psrc1 | imm8) & mask(dataSize * 8);;
                
            //Don't have genFlags handle the OF or CF bits
            uint64_t mask = CFBit | ECFBit | OFBit;
            uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                 PredezfBit, ext & ~mask, result, psrc1, imm8);
            PredezfBit = newFlags & EZFBit;
            PreddfBit = newFlags & DFBit;
            PredccFlagBits = newFlags & ccFlagMask;
            //If a logic microop wants to set these, it wants to set them to 0.
            PredcfofBits = PredcfofBits & ~((CFBit | OFBit) & ext);
            PredecfBit = PredecfBit & ~(ECFBit & ext);
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Adc::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t cfofBits = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
DestReg = xc->readIntRegOperand(this, 2);
cfofBits = xc->readCCRegOperand(this, 3);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            CCFlagBits flags = cfofBits;
            DestReg = merge(DestReg, result = (psrc1 + psrc2 + flags.cf), dataSize);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault AdcBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t cfofBits = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
cfofBits = xc->readCCRegOperand(this, 2);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            CCFlagBits flags = cfofBits;
            DestReg = result = (psrc1 + psrc2 + flags.cf) & mask(dataSize * 8);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault AdcFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
cfofBits = xc->readCCRegOperand(this, _sourceIndex++);
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            CCFlagBits flags = cfofBits;
            DestReg = merge(DestReg, result = (psrc1 + psrc2 + flags.cf), dataSize);
            ;
                
            uint64_t newFlags = genFlags(PredccFlagBits | PredcfofBits |
                                    PreddfBit | PredecfBit | PredezfBit,
                                    ext, result, psrc1, psrc2);
            PredcfofBits = newFlags & cfofMask;
            PredecfBit = newFlags & ECFBit;
            PredezfBit = newFlags & EZFBit;
            PreddfBit = newFlags & DFBit;
            PredccFlagBits = newFlags & ccFlagMask;
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault AdcFlagsBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
cfofBits = xc->readCCRegOperand(this, _sourceIndex++);
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            CCFlagBits flags = cfofBits;
            DestReg = result = (psrc1 + psrc2 + flags.cf) & mask(dataSize * 8);
            ;
                
            uint64_t newFlags = genFlags(PredccFlagBits | PredcfofBits |
                                    PreddfBit | PredecfBit | PredezfBit,
                                    ext, result, psrc1, psrc2);
            PredcfofBits = newFlags & cfofMask;
            PredecfBit = newFlags & ECFBit;
            PredezfBit = newFlags & EZFBit;
            PreddfBit = newFlags & DFBit;
            PredccFlagBits = newFlags & ccFlagMask;
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault AdcImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t cfofBits = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
DestReg = xc->readIntRegOperand(this, 1);
cfofBits = xc->readCCRegOperand(this, 2);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            CCFlagBits flags = cfofBits;
            DestReg = merge(DestReg, result = (psrc1 + imm8 + flags.cf), dataSize);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault AdcImmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t cfofBits = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
cfofBits = xc->readCCRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            CCFlagBits flags = cfofBits;
            DestReg = result = (psrc1 + imm8 + flags.cf) & mask(dataSize * 8);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault AdcFlagsImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
cfofBits = xc->readCCRegOperand(this, _sourceIndex++);
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            CCFlagBits flags = cfofBits;
            DestReg = merge(DestReg, result = (psrc1 + imm8 + flags.cf), dataSize);
            ;
                
            uint64_t newFlags = genFlags(PredccFlagBits | PredcfofBits |
                                    PreddfBit | PredecfBit | PredezfBit,
                                    ext, result, psrc1, imm8);
            PredcfofBits = newFlags & cfofMask;
            PredecfBit = newFlags & ECFBit;
            PredezfBit = newFlags & EZFBit;
            PreddfBit = newFlags & DFBit;
            PredccFlagBits = newFlags & ccFlagMask;
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault AdcFlagsImmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
cfofBits = xc->readCCRegOperand(this, _sourceIndex++);
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            CCFlagBits flags = cfofBits;
            DestReg = result = (psrc1 + imm8 + flags.cf) & mask(dataSize * 8);
            ;
                
            uint64_t newFlags = genFlags(PredccFlagBits | PredcfofBits |
                                    PreddfBit | PredecfBit | PredezfBit,
                                    ext, result, psrc1, imm8);
            PredcfofBits = newFlags & cfofMask;
            PredecfBit = newFlags & ECFBit;
            PredezfBit = newFlags & EZFBit;
            PreddfBit = newFlags & DFBit;
            PredccFlagBits = newFlags & ccFlagMask;
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Sbb::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t cfofBits = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
DestReg = xc->readIntRegOperand(this, 2);
cfofBits = xc->readCCRegOperand(this, 3);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            CCFlagBits flags = cfofBits;
            DestReg = merge(DestReg, result = (psrc1 - psrc2 - flags.cf), dataSize);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SbbBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t cfofBits = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
cfofBits = xc->readCCRegOperand(this, 2);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            CCFlagBits flags = cfofBits;
            DestReg = result = (psrc1 - psrc2 - flags.cf) & mask(dataSize * 8);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SbbFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
cfofBits = xc->readCCRegOperand(this, _sourceIndex++);
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            CCFlagBits flags = cfofBits;
            DestReg = merge(DestReg, result = (psrc1 - psrc2 - flags.cf), dataSize);
            ;
                
            uint64_t newFlags = genFlags(PredccFlagBits | PredcfofBits |
                                         PreddfBit | PredecfBit | PredezfBit,
                                         ext, result, psrc1, ~psrc2, true);
            PredcfofBits = newFlags & cfofMask;
            PredecfBit = newFlags & ECFBit;
            PredezfBit = newFlags & EZFBit;
            PreddfBit = newFlags & DFBit;
            PredccFlagBits = newFlags & ccFlagMask;
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SbbFlagsBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
cfofBits = xc->readCCRegOperand(this, _sourceIndex++);
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            CCFlagBits flags = cfofBits;
            DestReg = result = (psrc1 - psrc2 - flags.cf) & mask(dataSize * 8);
            ;
                
            uint64_t newFlags = genFlags(PredccFlagBits | PredcfofBits |
                                         PreddfBit | PredecfBit | PredezfBit,
                                         ext, result, psrc1, ~psrc2, true);
            PredcfofBits = newFlags & cfofMask;
            PredecfBit = newFlags & ECFBit;
            PredezfBit = newFlags & EZFBit;
            PreddfBit = newFlags & DFBit;
            PredccFlagBits = newFlags & ccFlagMask;
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SbbImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t cfofBits = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
DestReg = xc->readIntRegOperand(this, 1);
cfofBits = xc->readCCRegOperand(this, 2);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            CCFlagBits flags = cfofBits;
            DestReg = merge(DestReg, result = (psrc1 - imm8 - flags.cf), dataSize);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SbbImmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t cfofBits = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
cfofBits = xc->readCCRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            CCFlagBits flags = cfofBits;
            DestReg = result = (psrc1 - imm8 - flags.cf) & mask(dataSize * 8);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SbbFlagsImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
cfofBits = xc->readCCRegOperand(this, _sourceIndex++);
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            CCFlagBits flags = cfofBits;
            DestReg = merge(DestReg, result = (psrc1 - imm8 - flags.cf), dataSize);
            ;
                
            uint64_t newFlags = genFlags(PredccFlagBits | PredcfofBits |
                                         PreddfBit | PredecfBit | PredezfBit,
                                         ext, result, psrc1, ~imm8, true);
            PredcfofBits = newFlags & cfofMask;
            PredecfBit = newFlags & ECFBit;
            PredezfBit = newFlags & EZFBit;
            PreddfBit = newFlags & DFBit;
            PredccFlagBits = newFlags & ccFlagMask;
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SbbFlagsImmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
cfofBits = xc->readCCRegOperand(this, _sourceIndex++);
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            CCFlagBits flags = cfofBits;
            DestReg = result = (psrc1 - imm8 - flags.cf) & mask(dataSize * 8);
            ;
                
            uint64_t newFlags = genFlags(PredccFlagBits | PredcfofBits |
                                         PreddfBit | PredecfBit | PredezfBit,
                                         ext, result, psrc1, ~imm8, true);
            PredcfofBits = newFlags & cfofMask;
            PredecfBit = newFlags & ECFBit;
            PredezfBit = newFlags & EZFBit;
            PreddfBit = newFlags & DFBit;
            PredccFlagBits = newFlags & ccFlagMask;
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault And::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
DestReg = xc->readIntRegOperand(this, 2);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);
DestReg = merge(DestReg, result = (psrc1 & psrc2), dataSize);
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault AndBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);
DestReg = result = (psrc1 & psrc2) & mask(dataSize * 8);
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault AndFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);
DestReg = merge(DestReg, result = (psrc1 & psrc2), dataSize);
                
            //Don't have genFlags handle the OF or CF bits
            uint64_t mask = CFBit | ECFBit | OFBit;
            uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                 PredezfBit, ext & ~mask, result, psrc1, psrc2);
            PredezfBit = newFlags & EZFBit;
            PreddfBit = newFlags & DFBit;
            PredccFlagBits = newFlags & ccFlagMask;
            //If a logic microop wants to set these, it wants to set them to 0.
            PredcfofBits = PredcfofBits & ~((CFBit | OFBit) & ext);
            PredecfBit = PredecfBit & ~(ECFBit & ext);
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault AndFlagsBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);
DestReg = result = (psrc1 & psrc2) & mask(dataSize * 8);
                
            //Don't have genFlags handle the OF or CF bits
            uint64_t mask = CFBit | ECFBit | OFBit;
            uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                 PredezfBit, ext & ~mask, result, psrc1, psrc2);
            PredezfBit = newFlags & EZFBit;
            PreddfBit = newFlags & DFBit;
            PredccFlagBits = newFlags & ccFlagMask;
            //If a logic microop wants to set these, it wants to set them to 0.
            PredcfofBits = PredcfofBits & ~((CFBit | OFBit) & ext);
            PredecfBit = PredecfBit & ~(ECFBit & ext);
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault AndImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
DestReg = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
DestReg = merge(DestReg, result = (psrc1 & imm8), dataSize);
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault AndImmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
DestReg = result = (psrc1 & imm8) & mask(dataSize * 8);
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault AndFlagsImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
DestReg = merge(DestReg, result = (psrc1 & imm8), dataSize);
                
            //Don't have genFlags handle the OF or CF bits
            uint64_t mask = CFBit | ECFBit | OFBit;
            uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                 PredezfBit, ext & ~mask, result, psrc1, imm8);
            PredezfBit = newFlags & EZFBit;
            PreddfBit = newFlags & DFBit;
            PredccFlagBits = newFlags & ccFlagMask;
            //If a logic microop wants to set these, it wants to set them to 0.
            PredcfofBits = PredcfofBits & ~((CFBit | OFBit) & ext);
            PredecfBit = PredecfBit & ~(ECFBit & ext);
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault AndFlagsImmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
DestReg = result = (psrc1 & imm8) & mask(dataSize * 8);
                
            //Don't have genFlags handle the OF or CF bits
            uint64_t mask = CFBit | ECFBit | OFBit;
            uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                 PredezfBit, ext & ~mask, result, psrc1, imm8);
            PredezfBit = newFlags & EZFBit;
            PreddfBit = newFlags & DFBit;
            PredccFlagBits = newFlags & ccFlagMask;
            //If a logic microop wants to set these, it wants to set them to 0.
            PredcfofBits = PredcfofBits & ~((CFBit | OFBit) & ext);
            PredecfBit = PredecfBit & ~(ECFBit & ext);
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Sub::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
DestReg = xc->readIntRegOperand(this, 2);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);
DestReg = merge(DestReg, result = (psrc1 - psrc2), dataSize);
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SubBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);
DestReg = result = (psrc1 - psrc2) & mask(dataSize * 8);
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SubFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);
DestReg = merge(DestReg, result = (psrc1 - psrc2), dataSize);
                
            uint64_t newFlags = genFlags(PredccFlagBits | PredcfofBits |
                                         PreddfBit | PredecfBit | PredezfBit,
                                         ext, result, psrc1, ~psrc2, true);
            PredcfofBits = newFlags & cfofMask;
            PredecfBit = newFlags & ECFBit;
            PredezfBit = newFlags & EZFBit;
            PreddfBit = newFlags & DFBit;
            PredccFlagBits = newFlags & ccFlagMask;
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SubFlagsBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);
DestReg = result = (psrc1 - psrc2) & mask(dataSize * 8);
                
            uint64_t newFlags = genFlags(PredccFlagBits | PredcfofBits |
                                         PreddfBit | PredecfBit | PredezfBit,
                                         ext, result, psrc1, ~psrc2, true);
            PredcfofBits = newFlags & cfofMask;
            PredecfBit = newFlags & ECFBit;
            PredezfBit = newFlags & EZFBit;
            PreddfBit = newFlags & DFBit;
            PredccFlagBits = newFlags & ccFlagMask;
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SubImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
DestReg = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
DestReg = merge(DestReg, result = (psrc1 - imm8), dataSize);
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SubImmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
DestReg = result = (psrc1 - imm8) & mask(dataSize * 8);
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SubFlagsImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
DestReg = merge(DestReg, result = (psrc1 - imm8), dataSize);
                
            uint64_t newFlags = genFlags(PredccFlagBits | PredcfofBits |
                                         PreddfBit | PredecfBit | PredezfBit,
                                         ext, result, psrc1, ~imm8, true);
            PredcfofBits = newFlags & cfofMask;
            PredecfBit = newFlags & ECFBit;
            PredezfBit = newFlags & EZFBit;
            PreddfBit = newFlags & DFBit;
            PredccFlagBits = newFlags & ccFlagMask;
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SubFlagsImmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
DestReg = result = (psrc1 - imm8) & mask(dataSize * 8);
                
            uint64_t newFlags = genFlags(PredccFlagBits | PredcfofBits |
                                         PreddfBit | PredecfBit | PredezfBit,
                                         ext, result, psrc1, ~imm8, true);
            PredcfofBits = newFlags & cfofMask;
            PredecfBit = newFlags & ECFBit;
            PredezfBit = newFlags & EZFBit;
            PreddfBit = newFlags & DFBit;
            PredccFlagBits = newFlags & ccFlagMask;
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Xor::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
DestReg = xc->readIntRegOperand(this, 2);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);
DestReg = merge(DestReg, result = (psrc1 ^ psrc2), dataSize);
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault XorBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);
DestReg = result = (psrc1 ^ psrc2) & mask(dataSize * 8);
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault XorFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);
DestReg = merge(DestReg, result = (psrc1 ^ psrc2), dataSize);
                
            //Don't have genFlags handle the OF or CF bits
            uint64_t mask = CFBit | ECFBit | OFBit;
            uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                 PredezfBit, ext & ~mask, result, psrc1, psrc2);
            PredezfBit = newFlags & EZFBit;
            PreddfBit = newFlags & DFBit;
            PredccFlagBits = newFlags & ccFlagMask;
            //If a logic microop wants to set these, it wants to set them to 0.
            PredcfofBits = PredcfofBits & ~((CFBit | OFBit) & ext);
            PredecfBit = PredecfBit & ~(ECFBit & ext);
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault XorFlagsBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);
DestReg = result = (psrc1 ^ psrc2) & mask(dataSize * 8);
                
            //Don't have genFlags handle the OF or CF bits
            uint64_t mask = CFBit | ECFBit | OFBit;
            uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                 PredezfBit, ext & ~mask, result, psrc1, psrc2);
            PredezfBit = newFlags & EZFBit;
            PreddfBit = newFlags & DFBit;
            PredccFlagBits = newFlags & ccFlagMask;
            //If a logic microop wants to set these, it wants to set them to 0.
            PredcfofBits = PredcfofBits & ~((CFBit | OFBit) & ext);
            PredecfBit = PredecfBit & ~(ECFBit & ext);
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault XorImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
DestReg = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
DestReg = merge(DestReg, result = (psrc1 ^ imm8), dataSize);
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault XorImmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
DestReg = result = (psrc1 ^ imm8) & mask(dataSize * 8);
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault XorFlagsImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
DestReg = merge(DestReg, result = (psrc1 ^ imm8), dataSize);
                
            //Don't have genFlags handle the OF or CF bits
            uint64_t mask = CFBit | ECFBit | OFBit;
            uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                 PredezfBit, ext & ~mask, result, psrc1, imm8);
            PredezfBit = newFlags & EZFBit;
            PreddfBit = newFlags & DFBit;
            PredccFlagBits = newFlags & ccFlagMask;
            //If a logic microop wants to set these, it wants to set them to 0.
            PredcfofBits = PredcfofBits & ~((CFBit | OFBit) & ext);
            PredecfBit = PredecfBit & ~(ECFBit & ext);
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault XorFlagsImmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
DestReg = result = (psrc1 ^ imm8) & mask(dataSize * 8);
                
            //Don't have genFlags handle the OF or CF bits
            uint64_t mask = CFBit | ECFBit | OFBit;
            uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                 PredezfBit, ext & ~mask, result, psrc1, imm8);
            PredezfBit = newFlags & EZFBit;
            PreddfBit = newFlags & DFBit;
            PredccFlagBits = newFlags & ccFlagMask;
            //If a logic microop wants to set these, it wants to set them to 0.
            PredcfofBits = PredcfofBits & ~((CFBit | OFBit) & ext);
            PredecfBit = PredecfBit & ~(ECFBit & ext);
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Mul1s::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t ProdLow = 0;
uint64_t ProdHi = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            ProdLow = psrc1 * psrc2;
            int halfSize = (dataSize * 8) / 2;
            uint64_t shifter = (ULL(1) << halfSize);
            uint64_t hiResult;
            uint64_t psrc1_h = psrc1 / shifter;
            uint64_t psrc1_l = psrc1 & mask(halfSize);
            uint64_t psrc2_h = (psrc2 / shifter) & mask(halfSize);
            uint64_t psrc2_l = psrc2 & mask(halfSize);
            hiResult = ((psrc1_l * psrc2_h + psrc1_h * psrc2_l +
                        ((psrc1_l * psrc2_l) / shifter)) /shifter) +
                       psrc1_h * psrc2_h;
            if (bits(psrc1, dataSize * 8 - 1))
                hiResult -= psrc2;
            if (bits(psrc2, dataSize * 8 - 1))
                hiResult -= psrc1;
            ProdHi = hiResult;
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = ProdLow;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = ProdHi;
            xc->setIntRegOperand(this, 1, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Mul1sFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t ProdLow = 0;
uint64_t ProdHi = 0;
uint64_t PredcfofBits = 0;
uint64_t PredecfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
ProdLow = xc->readIntRegOperand(this, _sourceIndex++);
ProdHi = xc->readIntRegOperand(this, _sourceIndex++);
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            ProdLow = psrc1 * psrc2;
            int halfSize = (dataSize * 8) / 2;
            uint64_t shifter = (ULL(1) << halfSize);
            uint64_t hiResult;
            uint64_t psrc1_h = psrc1 / shifter;
            uint64_t psrc1_l = psrc1 & mask(halfSize);
            uint64_t psrc2_h = (psrc2 / shifter) & mask(halfSize);
            uint64_t psrc2_l = psrc2 & mask(halfSize);
            hiResult = ((psrc1_l * psrc2_h + psrc1_h * psrc2_l +
                        ((psrc1_l * psrc2_l) / shifter)) /shifter) +
                       psrc1_h * psrc2_h;
            if (bits(psrc1, dataSize * 8 - 1))
                hiResult -= psrc2;
            if (bits(psrc2, dataSize * 8 - 1))
                hiResult -= psrc1;
            ProdHi = hiResult;
            ;
                
            if ((-ProdHi & mask(dataSize * 8)) !=
                    bits(ProdLow, dataSize * 8 - 1)) {
                PredcfofBits = PredcfofBits | (ext & (CFBit | OFBit));
                PredecfBit = PredecfBit | (ext & ECFBit);
            } else {
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = ProdLow;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (true)
        {
            uint64_t final_val = ProdHi;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Mul1sImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t ProdLow = 0;
uint64_t ProdHi = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            ProdLow = psrc1 * imm8;
            int halfSize = (dataSize * 8) / 2;
            uint64_t shifter = (ULL(1) << halfSize);
            uint64_t hiResult;
            uint64_t psrc1_h = psrc1 / shifter;
            uint64_t psrc1_l = psrc1 & mask(halfSize);
            uint64_t psrc2_h = (imm8 / shifter) & mask(halfSize);
            uint64_t psrc2_l = imm8 & mask(halfSize);
            hiResult = ((psrc1_l * psrc2_h + psrc1_h * psrc2_l +
                        ((psrc1_l * psrc2_l) / shifter)) /shifter) +
                       psrc1_h * psrc2_h;
            if (bits(psrc1, dataSize * 8 - 1))
                hiResult -= imm8;
            if (bits(imm8, dataSize * 8 - 1))
                hiResult -= psrc1;
            ProdHi = hiResult;
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = ProdLow;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = ProdHi;
            xc->setIntRegOperand(this, 1, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Mul1sFlagsImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t ProdLow = 0;
uint64_t ProdHi = 0;
uint64_t PredcfofBits = 0;
uint64_t PredecfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
ProdLow = xc->readIntRegOperand(this, _sourceIndex++);
ProdHi = xc->readIntRegOperand(this, _sourceIndex++);
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            ProdLow = psrc1 * imm8;
            int halfSize = (dataSize * 8) / 2;
            uint64_t shifter = (ULL(1) << halfSize);
            uint64_t hiResult;
            uint64_t psrc1_h = psrc1 / shifter;
            uint64_t psrc1_l = psrc1 & mask(halfSize);
            uint64_t psrc2_h = (imm8 / shifter) & mask(halfSize);
            uint64_t psrc2_l = imm8 & mask(halfSize);
            hiResult = ((psrc1_l * psrc2_h + psrc1_h * psrc2_l +
                        ((psrc1_l * psrc2_l) / shifter)) /shifter) +
                       psrc1_h * psrc2_h;
            if (bits(psrc1, dataSize * 8 - 1))
                hiResult -= imm8;
            if (bits(imm8, dataSize * 8 - 1))
                hiResult -= psrc1;
            ProdHi = hiResult;
            ;
                
            if ((-ProdHi & mask(dataSize * 8)) !=
                    bits(ProdLow, dataSize * 8 - 1)) {
                PredcfofBits = PredcfofBits | (ext & (CFBit | OFBit));
                PredecfBit = PredecfBit | (ext & ECFBit);
            } else {
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = ProdLow;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (true)
        {
            uint64_t final_val = ProdHi;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Mul1u::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t ProdLow = 0;
uint64_t ProdHi = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            ProdLow = psrc1 * psrc2;
            int halfSize = (dataSize * 8) / 2;
            uint64_t shifter = (ULL(1) << halfSize);
            uint64_t psrc1_h = psrc1 / shifter;
            uint64_t psrc1_l = psrc1 & mask(halfSize);
            uint64_t psrc2_h = (psrc2 / shifter) & mask(halfSize);
            uint64_t psrc2_l = psrc2 & mask(halfSize);
            ProdHi = ((psrc1_l * psrc2_h + psrc1_h * psrc2_l +
                      ((psrc1_l * psrc2_l) / shifter)) / shifter) +
                     psrc1_h * psrc2_h;
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = ProdLow;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = ProdHi;
            xc->setIntRegOperand(this, 1, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Mul1uFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t ProdLow = 0;
uint64_t ProdHi = 0;
uint64_t PredcfofBits = 0;
uint64_t PredecfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
ProdHi = xc->readIntRegOperand(this, _sourceIndex++);
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            ProdLow = psrc1 * psrc2;
            int halfSize = (dataSize * 8) / 2;
            uint64_t shifter = (ULL(1) << halfSize);
            uint64_t psrc1_h = psrc1 / shifter;
            uint64_t psrc1_l = psrc1 & mask(halfSize);
            uint64_t psrc2_h = (psrc2 / shifter) & mask(halfSize);
            uint64_t psrc2_l = psrc2 & mask(halfSize);
            ProdHi = ((psrc1_l * psrc2_h + psrc1_h * psrc2_l +
                      ((psrc1_l * psrc2_l) / shifter)) / shifter) +
                     psrc1_h * psrc2_h;
            ;
                
            if (ProdHi) {
                PredcfofBits = PredcfofBits | (ext & (CFBit | OFBit));
                PredecfBit = PredecfBit | (ext & ECFBit);
            } else {
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = ProdLow;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (true)
        {
            uint64_t final_val = ProdHi;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Mul1uImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t ProdLow = 0;
uint64_t ProdHi = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            ProdLow = psrc1 * imm8;
            int halfSize = (dataSize * 8) / 2;
            uint64_t shifter = (ULL(1) << halfSize);
            uint64_t psrc1_h = psrc1 / shifter;
            uint64_t psrc1_l = psrc1 & mask(halfSize);
            uint64_t psrc2_h = (imm8 / shifter) & mask(halfSize);
            uint64_t psrc2_l = imm8 & mask(halfSize);
            ProdHi = ((psrc1_l * psrc2_h + psrc1_h * psrc2_l +
                      ((psrc1_l * psrc2_l) / shifter)) / shifter) +
                     psrc1_h * psrc2_h;
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = ProdLow;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = ProdHi;
            xc->setIntRegOperand(this, 1, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Mul1uFlagsImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t ProdLow = 0;
uint64_t ProdHi = 0;
uint64_t PredcfofBits = 0;
uint64_t PredecfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
ProdHi = xc->readIntRegOperand(this, _sourceIndex++);
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            ProdLow = psrc1 * imm8;
            int halfSize = (dataSize * 8) / 2;
            uint64_t shifter = (ULL(1) << halfSize);
            uint64_t psrc1_h = psrc1 / shifter;
            uint64_t psrc1_l = psrc1 & mask(halfSize);
            uint64_t psrc2_h = (imm8 / shifter) & mask(halfSize);
            uint64_t psrc2_l = imm8 & mask(halfSize);
            ProdHi = ((psrc1_l * psrc2_h + psrc1_h * psrc2_l +
                      ((psrc1_l * psrc2_l) / shifter)) / shifter) +
                     psrc1_h * psrc2_h;
            ;
                
            if (ProdHi) {
                PredcfofBits = PredcfofBits | (ext & (CFBit | OFBit));
                PredecfBit = PredecfBit | (ext & ECFBit);
            } else {
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = ProdLow;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (true)
        {
            uint64_t final_val = ProdHi;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Mulel::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t ProdLow = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
ProdLow = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                DestReg = merge(SrcReg1, ProdLow, dataSize);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault MulelBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t ProdLow = 0;
;
            ProdLow = xc->readIntRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                DestReg = ProdLow & mask(dataSize * 8);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Muleh::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t ProdHi = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
ProdHi = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                DestReg = merge(SrcReg1, ProdHi, dataSize);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault MulehBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t ProdHi = 0;
;
            ProdHi = xc->readIntRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                DestReg = ProdHi & mask(dataSize * 8);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Div1::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t Quotient = 0;
uint64_t Remainder = 0;
uint64_t Divisor = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            //These are temporaries so that modifying them later won't make
            //the ISA parser think they're also sources.
            uint64_t quotient = 0;
            uint64_t remainder = psrc1;
            //Similarly, this is a temporary so changing it doesn't make it
            //a source.
            uint64_t divisor = psrc2;
            //This is a temporary just for consistency and clarity.
            uint64_t dividend = remainder;
            //Do the division.
            if (divisor == 0) {
                fault = std::make_shared<DivideError>();
            } else {
                divide(dividend, divisor, quotient, remainder);
                //Record the final results.
                Remainder = remainder;
                Quotient = quotient;
                Divisor = divisor;
            }
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = Quotient;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = Remainder;
            xc->setIntRegOperand(this, 1, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = Divisor;
            xc->setIntRegOperand(this, 2, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Div1Imm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t Quotient = 0;
uint64_t Remainder = 0;
uint64_t Divisor = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            //These are temporaries so that modifying them later won't make
            //the ISA parser think they're also sources.
            uint64_t quotient = 0;
            uint64_t remainder = psrc1;
            //Similarly, this is a temporary so changing it doesn't make it
            //a source.
            uint64_t divisor = imm8;
            //This is a temporary just for consistency and clarity.
            uint64_t dividend = remainder;
            //Do the division.
            if (divisor == 0) {
                fault = std::make_shared<DivideError>();
            } else {
                divide(dividend, divisor, quotient, remainder);
                //Record the final results.
                Remainder = remainder;
                Quotient = quotient;
                Divisor = divisor;
            }
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = Quotient;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = Remainder;
            xc->setIntRegOperand(this, 1, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = Divisor;
            xc->setIntRegOperand(this, 2, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Div2::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t Quotient = 0;
uint64_t Remainder = 0;
uint64_t Divisor = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
DestReg = xc->readIntRegOperand(this, 2);
Quotient = xc->readIntRegOperand(this, 3);
Remainder = xc->readIntRegOperand(this, 4);
Divisor = xc->readIntRegOperand(this, 5);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint64_t dividend = Remainder;
            uint64_t divisor = Divisor;
            uint64_t quotient = Quotient;
            uint64_t remainder = dividend;
            int remaining = psrc2;
            //If we overshot, do nothing. This lets us unrool division loops a
            //little.
            if (divisor == 0) {
                fault = std::make_shared<DivideError>();
            } else if (remaining) {
                if (divisor & (ULL(1) << 63)) {
                    while (remaining && !(dividend & (ULL(1) << 63))) {
                        dividend = (dividend << 1) |
                            bits(SrcReg1, remaining - 1);
                        quotient <<= 1;
                        remaining--;
                    }
                    if (dividend & (ULL(1) << 63)) {
                        bool highBit = false;
                        if (dividend < divisor && remaining) {
                            highBit = true;
                            dividend = (dividend << 1) |
                                bits(SrcReg1, remaining - 1);
                            quotient <<= 1;
                            remaining--;
                        }
                        if (highBit || divisor <= dividend) {
                            quotient++;
                            dividend -= divisor;
                        }
                    }
                    remainder = dividend;
                } else {
                    //Shift in bits from the low order portion of the dividend
                    while (dividend < divisor && remaining) {
                        dividend = (dividend << 1) |
                            bits(SrcReg1, remaining - 1);
                        quotient <<= 1;
                        remaining--;
                    }
                    remainder = dividend;
                    //Do the division.
                    divide(dividend, divisor, quotient, remainder);
                }
            }
            //Keep track of how many bits there are still to pull in.
            DestReg = merge(DestReg, remaining, dataSize);
            //Record the final results
            Remainder = remainder;
            Quotient = quotient;
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = Quotient;
            xc->setIntRegOperand(this, 1, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = Remainder;
            xc->setIntRegOperand(this, 2, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Div2Big::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t Quotient = 0;
uint64_t Remainder = 0;
uint64_t Divisor = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
Quotient = xc->readIntRegOperand(this, 2);
Remainder = xc->readIntRegOperand(this, 3);
Divisor = xc->readIntRegOperand(this, 4);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint64_t dividend = Remainder;
            uint64_t divisor = Divisor;
            uint64_t quotient = Quotient;
            uint64_t remainder = dividend;
            int remaining = psrc2;
            //If we overshot, do nothing. This lets us unrool division loops a
            //little.
            if (divisor == 0) {
                fault = std::make_shared<DivideError>();
            } else if (remaining) {
                if (divisor & (ULL(1) << 63)) {
                    while (remaining && !(dividend & (ULL(1) << 63))) {
                        dividend = (dividend << 1) |
                            bits(SrcReg1, remaining - 1);
                        quotient <<= 1;
                        remaining--;
                    }
                    if (dividend & (ULL(1) << 63)) {
                        bool highBit = false;
                        if (dividend < divisor && remaining) {
                            highBit = true;
                            dividend = (dividend << 1) |
                                bits(SrcReg1, remaining - 1);
                            quotient <<= 1;
                            remaining--;
                        }
                        if (highBit || divisor <= dividend) {
                            quotient++;
                            dividend -= divisor;
                        }
                    }
                    remainder = dividend;
                } else {
                    //Shift in bits from the low order portion of the dividend
                    while (dividend < divisor && remaining) {
                        dividend = (dividend << 1) |
                            bits(SrcReg1, remaining - 1);
                        quotient <<= 1;
                        remaining--;
                    }
                    remainder = dividend;
                    //Do the division.
                    divide(dividend, divisor, quotient, remainder);
                }
            }
            //Keep track of how many bits there are still to pull in.
            DestReg = remaining & mask(dataSize * 8);
            //Record the final results
            Remainder = remainder;
            Quotient = quotient;
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = Quotient;
            xc->setIntRegOperand(this, 1, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = Remainder;
            xc->setIntRegOperand(this, 2, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Div2Flags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t Quotient = 0;
uint64_t Remainder = 0;
uint64_t Divisor = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
Quotient = xc->readIntRegOperand(this, _sourceIndex++);
Remainder = xc->readIntRegOperand(this, _sourceIndex++);
Divisor = xc->readIntRegOperand(this, _sourceIndex++);
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint64_t dividend = Remainder;
            uint64_t divisor = Divisor;
            uint64_t quotient = Quotient;
            uint64_t remainder = dividend;
            int remaining = psrc2;
            //If we overshot, do nothing. This lets us unrool division loops a
            //little.
            if (divisor == 0) {
                fault = std::make_shared<DivideError>();
            } else if (remaining) {
                if (divisor & (ULL(1) << 63)) {
                    while (remaining && !(dividend & (ULL(1) << 63))) {
                        dividend = (dividend << 1) |
                            bits(SrcReg1, remaining - 1);
                        quotient <<= 1;
                        remaining--;
                    }
                    if (dividend & (ULL(1) << 63)) {
                        bool highBit = false;
                        if (dividend < divisor && remaining) {
                            highBit = true;
                            dividend = (dividend << 1) |
                                bits(SrcReg1, remaining - 1);
                            quotient <<= 1;
                            remaining--;
                        }
                        if (highBit || divisor <= dividend) {
                            quotient++;
                            dividend -= divisor;
                        }
                    }
                    remainder = dividend;
                } else {
                    //Shift in bits from the low order portion of the dividend
                    while (dividend < divisor && remaining) {
                        dividend = (dividend << 1) |
                            bits(SrcReg1, remaining - 1);
                        quotient <<= 1;
                        remaining--;
                    }
                    remainder = dividend;
                    //Do the division.
                    divide(dividend, divisor, quotient, remainder);
                }
            }
            //Keep track of how many bits there are still to pull in.
            DestReg = merge(DestReg, remaining, dataSize);
            //Record the final results
            Remainder = remainder;
            Quotient = quotient;
        ;
                
            if (remaining == 0)
                PredezfBit = PredezfBit | (ext & EZFBit);
            else
                PredezfBit = PredezfBit & ~(ext & EZFBit);
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (true)
        {
            uint64_t final_val = Quotient;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (true)
        {
            uint64_t final_val = Remainder;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Div2FlagsBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t Quotient = 0;
uint64_t Remainder = 0;
uint64_t Divisor = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
Quotient = xc->readIntRegOperand(this, _sourceIndex++);
Remainder = xc->readIntRegOperand(this, _sourceIndex++);
Divisor = xc->readIntRegOperand(this, _sourceIndex++);
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint64_t dividend = Remainder;
            uint64_t divisor = Divisor;
            uint64_t quotient = Quotient;
            uint64_t remainder = dividend;
            int remaining = psrc2;
            //If we overshot, do nothing. This lets us unrool division loops a
            //little.
            if (divisor == 0) {
                fault = std::make_shared<DivideError>();
            } else if (remaining) {
                if (divisor & (ULL(1) << 63)) {
                    while (remaining && !(dividend & (ULL(1) << 63))) {
                        dividend = (dividend << 1) |
                            bits(SrcReg1, remaining - 1);
                        quotient <<= 1;
                        remaining--;
                    }
                    if (dividend & (ULL(1) << 63)) {
                        bool highBit = false;
                        if (dividend < divisor && remaining) {
                            highBit = true;
                            dividend = (dividend << 1) |
                                bits(SrcReg1, remaining - 1);
                            quotient <<= 1;
                            remaining--;
                        }
                        if (highBit || divisor <= dividend) {
                            quotient++;
                            dividend -= divisor;
                        }
                    }
                    remainder = dividend;
                } else {
                    //Shift in bits from the low order portion of the dividend
                    while (dividend < divisor && remaining) {
                        dividend = (dividend << 1) |
                            bits(SrcReg1, remaining - 1);
                        quotient <<= 1;
                        remaining--;
                    }
                    remainder = dividend;
                    //Do the division.
                    divide(dividend, divisor, quotient, remainder);
                }
            }
            //Keep track of how many bits there are still to pull in.
            DestReg = remaining & mask(dataSize * 8);
            //Record the final results
            Remainder = remainder;
            Quotient = quotient;
        ;
                
            if (remaining == 0)
                PredezfBit = PredezfBit | (ext & EZFBit);
            else
                PredezfBit = PredezfBit & ~(ext & EZFBit);
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (true)
        {
            uint64_t final_val = Quotient;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (true)
        {
            uint64_t final_val = Remainder;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Div2Imm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t Quotient = 0;
uint64_t Remainder = 0;
uint64_t Divisor = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
DestReg = xc->readIntRegOperand(this, 1);
Quotient = xc->readIntRegOperand(this, 2);
Remainder = xc->readIntRegOperand(this, 3);
Divisor = xc->readIntRegOperand(this, 4);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                
            uint64_t dividend = Remainder;
            uint64_t divisor = Divisor;
            uint64_t quotient = Quotient;
            uint64_t remainder = dividend;
            int remaining = imm8;
            //If we overshot, do nothing. This lets us unrool division loops a
            //little.
            if (divisor == 0) {
                fault = std::make_shared<DivideError>();
            } else if (remaining) {
                if (divisor & (ULL(1) << 63)) {
                    while (remaining && !(dividend & (ULL(1) << 63))) {
                        dividend = (dividend << 1) |
                            bits(SrcReg1, remaining - 1);
                        quotient <<= 1;
                        remaining--;
                    }
                    if (dividend & (ULL(1) << 63)) {
                        bool highBit = false;
                        if (dividend < divisor && remaining) {
                            highBit = true;
                            dividend = (dividend << 1) |
                                bits(SrcReg1, remaining - 1);
                            quotient <<= 1;
                            remaining--;
                        }
                        if (highBit || divisor <= dividend) {
                            quotient++;
                            dividend -= divisor;
                        }
                    }
                    remainder = dividend;
                } else {
                    //Shift in bits from the low order portion of the dividend
                    while (dividend < divisor && remaining) {
                        dividend = (dividend << 1) |
                            bits(SrcReg1, remaining - 1);
                        quotient <<= 1;
                        remaining--;
                    }
                    remainder = dividend;
                    //Do the division.
                    divide(dividend, divisor, quotient, remainder);
                }
            }
            //Keep track of how many bits there are still to pull in.
            DestReg = merge(DestReg, remaining, dataSize);
            //Record the final results
            Remainder = remainder;
            Quotient = quotient;
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = Quotient;
            xc->setIntRegOperand(this, 1, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = Remainder;
            xc->setIntRegOperand(this, 2, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Div2ImmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t Quotient = 0;
uint64_t Remainder = 0;
uint64_t Divisor = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
Quotient = xc->readIntRegOperand(this, 1);
Remainder = xc->readIntRegOperand(this, 2);
Divisor = xc->readIntRegOperand(this, 3);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                
            uint64_t dividend = Remainder;
            uint64_t divisor = Divisor;
            uint64_t quotient = Quotient;
            uint64_t remainder = dividend;
            int remaining = imm8;
            //If we overshot, do nothing. This lets us unrool division loops a
            //little.
            if (divisor == 0) {
                fault = std::make_shared<DivideError>();
            } else if (remaining) {
                if (divisor & (ULL(1) << 63)) {
                    while (remaining && !(dividend & (ULL(1) << 63))) {
                        dividend = (dividend << 1) |
                            bits(SrcReg1, remaining - 1);
                        quotient <<= 1;
                        remaining--;
                    }
                    if (dividend & (ULL(1) << 63)) {
                        bool highBit = false;
                        if (dividend < divisor && remaining) {
                            highBit = true;
                            dividend = (dividend << 1) |
                                bits(SrcReg1, remaining - 1);
                            quotient <<= 1;
                            remaining--;
                        }
                        if (highBit || divisor <= dividend) {
                            quotient++;
                            dividend -= divisor;
                        }
                    }
                    remainder = dividend;
                } else {
                    //Shift in bits from the low order portion of the dividend
                    while (dividend < divisor && remaining) {
                        dividend = (dividend << 1) |
                            bits(SrcReg1, remaining - 1);
                        quotient <<= 1;
                        remaining--;
                    }
                    remainder = dividend;
                    //Do the division.
                    divide(dividend, divisor, quotient, remainder);
                }
            }
            //Keep track of how many bits there are still to pull in.
            DestReg = remaining & mask(dataSize * 8);
            //Record the final results
            Remainder = remainder;
            Quotient = quotient;
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = Quotient;
            xc->setIntRegOperand(this, 1, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = Remainder;
            xc->setIntRegOperand(this, 2, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Div2FlagsImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t Quotient = 0;
uint64_t Remainder = 0;
uint64_t Divisor = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
Quotient = xc->readIntRegOperand(this, _sourceIndex++);
Remainder = xc->readIntRegOperand(this, _sourceIndex++);
Divisor = xc->readIntRegOperand(this, _sourceIndex++);
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                
            uint64_t dividend = Remainder;
            uint64_t divisor = Divisor;
            uint64_t quotient = Quotient;
            uint64_t remainder = dividend;
            int remaining = imm8;
            //If we overshot, do nothing. This lets us unrool division loops a
            //little.
            if (divisor == 0) {
                fault = std::make_shared<DivideError>();
            } else if (remaining) {
                if (divisor & (ULL(1) << 63)) {
                    while (remaining && !(dividend & (ULL(1) << 63))) {
                        dividend = (dividend << 1) |
                            bits(SrcReg1, remaining - 1);
                        quotient <<= 1;
                        remaining--;
                    }
                    if (dividend & (ULL(1) << 63)) {
                        bool highBit = false;
                        if (dividend < divisor && remaining) {
                            highBit = true;
                            dividend = (dividend << 1) |
                                bits(SrcReg1, remaining - 1);
                            quotient <<= 1;
                            remaining--;
                        }
                        if (highBit || divisor <= dividend) {
                            quotient++;
                            dividend -= divisor;
                        }
                    }
                    remainder = dividend;
                } else {
                    //Shift in bits from the low order portion of the dividend
                    while (dividend < divisor && remaining) {
                        dividend = (dividend << 1) |
                            bits(SrcReg1, remaining - 1);
                        quotient <<= 1;
                        remaining--;
                    }
                    remainder = dividend;
                    //Do the division.
                    divide(dividend, divisor, quotient, remainder);
                }
            }
            //Keep track of how many bits there are still to pull in.
            DestReg = merge(DestReg, remaining, dataSize);
            //Record the final results
            Remainder = remainder;
            Quotient = quotient;
        ;
                
            if (remaining == 0)
                PredezfBit = PredezfBit | (ext & EZFBit);
            else
                PredezfBit = PredezfBit & ~(ext & EZFBit);
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (true)
        {
            uint64_t final_val = Quotient;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (true)
        {
            uint64_t final_val = Remainder;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Div2FlagsImmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t Quotient = 0;
uint64_t Remainder = 0;
uint64_t Divisor = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
Quotient = xc->readIntRegOperand(this, _sourceIndex++);
Remainder = xc->readIntRegOperand(this, _sourceIndex++);
Divisor = xc->readIntRegOperand(this, _sourceIndex++);
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                
            uint64_t dividend = Remainder;
            uint64_t divisor = Divisor;
            uint64_t quotient = Quotient;
            uint64_t remainder = dividend;
            int remaining = imm8;
            //If we overshot, do nothing. This lets us unrool division loops a
            //little.
            if (divisor == 0) {
                fault = std::make_shared<DivideError>();
            } else if (remaining) {
                if (divisor & (ULL(1) << 63)) {
                    while (remaining && !(dividend & (ULL(1) << 63))) {
                        dividend = (dividend << 1) |
                            bits(SrcReg1, remaining - 1);
                        quotient <<= 1;
                        remaining--;
                    }
                    if (dividend & (ULL(1) << 63)) {
                        bool highBit = false;
                        if (dividend < divisor && remaining) {
                            highBit = true;
                            dividend = (dividend << 1) |
                                bits(SrcReg1, remaining - 1);
                            quotient <<= 1;
                            remaining--;
                        }
                        if (highBit || divisor <= dividend) {
                            quotient++;
                            dividend -= divisor;
                        }
                    }
                    remainder = dividend;
                } else {
                    //Shift in bits from the low order portion of the dividend
                    while (dividend < divisor && remaining) {
                        dividend = (dividend << 1) |
                            bits(SrcReg1, remaining - 1);
                        quotient <<= 1;
                        remaining--;
                    }
                    remainder = dividend;
                    //Do the division.
                    divide(dividend, divisor, quotient, remainder);
                }
            }
            //Keep track of how many bits there are still to pull in.
            DestReg = remaining & mask(dataSize * 8);
            //Record the final results
            Remainder = remainder;
            Quotient = quotient;
        ;
                
            if (remaining == 0)
                PredezfBit = PredezfBit | (ext & EZFBit);
            else
                PredezfBit = PredezfBit & ~(ext & EZFBit);
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (true)
        {
            uint64_t final_val = Quotient;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (true)
        {
            uint64_t final_val = Remainder;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Divq::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t Quotient = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
Quotient = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                DestReg = merge(SrcReg1, Quotient, dataSize);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault DivqBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t Quotient = 0;
;
            Quotient = xc->readIntRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                DestReg = Quotient & mask(dataSize * 8);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Divr::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t Remainder = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
Remainder = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                DestReg = merge(SrcReg1, Remainder, dataSize);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault DivrBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t Remainder = 0;
;
            Remainder = xc->readIntRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                DestReg = Remainder & mask(dataSize * 8);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Mov::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
DestReg = xc->readIntRegOperand(this, 2);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc2 = pick(SrcReg2, 1, dataSize);
DestReg = merge(SrcReg1, psrc2, dataSize);
                ;
            }
            else
            {
                DestReg = DestReg;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault MovFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
DestReg = xc->readIntRegOperand(this, 2);
ccFlagBits = xc->readCCRegOperand(this, 3);
cfofBits = xc->readCCRegOperand(this, 4);
dfBit = xc->readCCRegOperand(this, 5);
ecfBit = xc->readCCRegOperand(this, 6);
ezfBit = xc->readCCRegOperand(this, 7);
;

            IntReg result M5_VAR_USED;

            if(checkCondition(ccFlagBits | cfofBits | dfBit | ecfBit |                                      ezfBit, ext))
            {
                uint64_t psrc2 = pick(SrcReg2, 1, dataSize);
DestReg = merge(SrcReg1, psrc2, dataSize);
                ;
            }
            else
            {
                DestReg = DestReg;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault MovImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
DestReg = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                DestReg = merge(SrcReg1, imm8, dataSize);
                ;
            }
            else
            {
                DestReg = DestReg;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault MovFlagsImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
DestReg = xc->readIntRegOperand(this, 1);
ccFlagBits = xc->readCCRegOperand(this, 2);
cfofBits = xc->readCCRegOperand(this, 3);
dfBit = xc->readCCRegOperand(this, 4);
ecfBit = xc->readCCRegOperand(this, 5);
ezfBit = xc->readCCRegOperand(this, 6);
;

            IntReg result M5_VAR_USED;

            if(checkCondition(ccFlagBits | cfofBits | dfBit | ecfBit |                                      ezfBit, ext))
            {
                DestReg = merge(SrcReg1, imm8, dataSize);
                ;
            }
            else
            {
                DestReg = DestReg;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Sll::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
DestReg = xc->readIntRegOperand(this, 2);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint8_t shiftAmt = (psrc2 & ((dataSize == 8) ? mask(6) : mask(5)));
            DestReg = merge(DestReg, psrc1 << shiftAmt, dataSize);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SllBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint8_t shiftAmt = (psrc2 & ((dataSize == 8) ? mask(6) : mask(5)));
            DestReg = (psrc1 << shiftAmt) & mask(dataSize * 8);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SllFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint8_t shiftAmt = (psrc2 & ((dataSize == 8) ? mask(6) : mask(5)));
            DestReg = merge(DestReg, psrc1 << shiftAmt, dataSize);
            ;
                
            // If the shift amount is zero, no flags should be modified.
            if (shiftAmt) {
                //Zero out any flags we might modify. This way we only have to
                //worry about setting them.
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                int CFBits = 0;
                //Figure out if we -would- set the CF bits if requested.
                if (shiftAmt <= dataSize * 8 &&
                        bits(SrcReg1, dataSize * 8 - shiftAmt)) {
                    CFBits = 1;
                }
                //If some combination of the CF bits need to be set, set them.
                if ((ext & (CFBit | ECFBit)) && CFBits) {
                    PredcfofBits = PredcfofBits | (ext & CFBit);
                    PredecfBit = PredecfBit | (ext & ECFBit);
                }
                //Figure out what the OF bit should be.
                if ((ext & OFBit) && (CFBits ^ bits(DestReg, dataSize * 8 - 1)))
                    PredcfofBits = PredcfofBits | OFBit;
                //Use the regular mechanisms to calculate the other flags.
                uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                PredezfBit, ext & ~(CFBit | ECFBit | OFBit),
                                DestReg, psrc1, psrc2);
                PredezfBit = newFlags & EZFBit;
                PreddfBit = newFlags & DFBit;
                PredccFlagBits = newFlags & ccFlagMask;
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SllFlagsBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint8_t shiftAmt = (psrc2 & ((dataSize == 8) ? mask(6) : mask(5)));
            DestReg = (psrc1 << shiftAmt) & mask(dataSize * 8);
            ;
                
            // If the shift amount is zero, no flags should be modified.
            if (shiftAmt) {
                //Zero out any flags we might modify. This way we only have to
                //worry about setting them.
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                int CFBits = 0;
                //Figure out if we -would- set the CF bits if requested.
                if (shiftAmt <= dataSize * 8 &&
                        bits(SrcReg1, dataSize * 8 - shiftAmt)) {
                    CFBits = 1;
                }
                //If some combination of the CF bits need to be set, set them.
                if ((ext & (CFBit | ECFBit)) && CFBits) {
                    PredcfofBits = PredcfofBits | (ext & CFBit);
                    PredecfBit = PredecfBit | (ext & ECFBit);
                }
                //Figure out what the OF bit should be.
                if ((ext & OFBit) && (CFBits ^ bits(DestReg, dataSize * 8 - 1)))
                    PredcfofBits = PredcfofBits | OFBit;
                //Use the regular mechanisms to calculate the other flags.
                uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                PredezfBit, ext & ~(CFBit | ECFBit | OFBit),
                                DestReg, psrc1, psrc2);
                PredezfBit = newFlags & EZFBit;
                PreddfBit = newFlags & DFBit;
                PredccFlagBits = newFlags & ccFlagMask;
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SllImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
DestReg = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            uint8_t shiftAmt = (imm8 & ((dataSize == 8) ? mask(6) : mask(5)));
            DestReg = merge(DestReg, psrc1 << shiftAmt, dataSize);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SllImmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            uint8_t shiftAmt = (imm8 & ((dataSize == 8) ? mask(6) : mask(5)));
            DestReg = (psrc1 << shiftAmt) & mask(dataSize * 8);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SllFlagsImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            uint8_t shiftAmt = (imm8 & ((dataSize == 8) ? mask(6) : mask(5)));
            DestReg = merge(DestReg, psrc1 << shiftAmt, dataSize);
            ;
                
            // If the shift amount is zero, no flags should be modified.
            if (shiftAmt) {
                //Zero out any flags we might modify. This way we only have to
                //worry about setting them.
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                int CFBits = 0;
                //Figure out if we -would- set the CF bits if requested.
                if (shiftAmt <= dataSize * 8 &&
                        bits(SrcReg1, dataSize * 8 - shiftAmt)) {
                    CFBits = 1;
                }
                //If some combination of the CF bits need to be set, set them.
                if ((ext & (CFBit | ECFBit)) && CFBits) {
                    PredcfofBits = PredcfofBits | (ext & CFBit);
                    PredecfBit = PredecfBit | (ext & ECFBit);
                }
                //Figure out what the OF bit should be.
                if ((ext & OFBit) && (CFBits ^ bits(DestReg, dataSize * 8 - 1)))
                    PredcfofBits = PredcfofBits | OFBit;
                //Use the regular mechanisms to calculate the other flags.
                uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                PredezfBit, ext & ~(CFBit | ECFBit | OFBit),
                                DestReg, psrc1, imm8);
                PredezfBit = newFlags & EZFBit;
                PreddfBit = newFlags & DFBit;
                PredccFlagBits = newFlags & ccFlagMask;
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SllFlagsImmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            uint8_t shiftAmt = (imm8 & ((dataSize == 8) ? mask(6) : mask(5)));
            DestReg = (psrc1 << shiftAmt) & mask(dataSize * 8);
            ;
                
            // If the shift amount is zero, no flags should be modified.
            if (shiftAmt) {
                //Zero out any flags we might modify. This way we only have to
                //worry about setting them.
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                int CFBits = 0;
                //Figure out if we -would- set the CF bits if requested.
                if (shiftAmt <= dataSize * 8 &&
                        bits(SrcReg1, dataSize * 8 - shiftAmt)) {
                    CFBits = 1;
                }
                //If some combination of the CF bits need to be set, set them.
                if ((ext & (CFBit | ECFBit)) && CFBits) {
                    PredcfofBits = PredcfofBits | (ext & CFBit);
                    PredecfBit = PredecfBit | (ext & ECFBit);
                }
                //Figure out what the OF bit should be.
                if ((ext & OFBit) && (CFBits ^ bits(DestReg, dataSize * 8 - 1)))
                    PredcfofBits = PredcfofBits | OFBit;
                //Use the regular mechanisms to calculate the other flags.
                uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                PredezfBit, ext & ~(CFBit | ECFBit | OFBit),
                                DestReg, psrc1, imm8);
                PredezfBit = newFlags & EZFBit;
                PreddfBit = newFlags & DFBit;
                PredccFlagBits = newFlags & ccFlagMask;
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Srl::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
DestReg = xc->readIntRegOperand(this, 2);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint8_t shiftAmt = (psrc2 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint64_t logicalMask = mask(dataSize * 8 - shiftAmt);
            DestReg = merge(DestReg, (psrc1 >> shiftAmt) & logicalMask, dataSize);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SrlBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint8_t shiftAmt = (psrc2 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint64_t logicalMask = mask(dataSize * 8 - shiftAmt);
            DestReg = (psrc1 >> shiftAmt) & logicalMask;
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SrlFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint8_t shiftAmt = (psrc2 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint64_t logicalMask = mask(dataSize * 8 - shiftAmt);
            DestReg = merge(DestReg, (psrc1 >> shiftAmt) & logicalMask, dataSize);
            ;
                
            // If the shift amount is zero, no flags should be modified.
            if (shiftAmt) {
                //Zero out any flags we might modify. This way we only have to
                //worry about setting them.
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                //If some combination of the CF bits need to be set, set them.
                if ((ext & (CFBit | ECFBit)) && 
                        shiftAmt <= dataSize * 8 &&
                        bits(SrcReg1, shiftAmt - 1)) {
                    PredcfofBits = PredcfofBits | (ext & CFBit);
                    PredecfBit = PredecfBit | (ext & ECFBit);
                }
                //Figure out what the OF bit should be.
                if ((ext & OFBit) && bits(SrcReg1, dataSize * 8 - 1))
                    PredcfofBits = PredcfofBits | OFBit;
                //Use the regular mechanisms to calculate the other flags.
                uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                PredezfBit, ext & ~(CFBit | ECFBit | OFBit),
                                DestReg, psrc1, psrc2);
                PredezfBit = newFlags & EZFBit;
                PreddfBit = newFlags & DFBit;
                PredccFlagBits = newFlags & ccFlagMask;
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SrlFlagsBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint8_t shiftAmt = (psrc2 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint64_t logicalMask = mask(dataSize * 8 - shiftAmt);
            DestReg = (psrc1 >> shiftAmt) & logicalMask;
            ;
                
            // If the shift amount is zero, no flags should be modified.
            if (shiftAmt) {
                //Zero out any flags we might modify. This way we only have to
                //worry about setting them.
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                //If some combination of the CF bits need to be set, set them.
                if ((ext & (CFBit | ECFBit)) && 
                        shiftAmt <= dataSize * 8 &&
                        bits(SrcReg1, shiftAmt - 1)) {
                    PredcfofBits = PredcfofBits | (ext & CFBit);
                    PredecfBit = PredecfBit | (ext & ECFBit);
                }
                //Figure out what the OF bit should be.
                if ((ext & OFBit) && bits(SrcReg1, dataSize * 8 - 1))
                    PredcfofBits = PredcfofBits | OFBit;
                //Use the regular mechanisms to calculate the other flags.
                uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                PredezfBit, ext & ~(CFBit | ECFBit | OFBit),
                                DestReg, psrc1, psrc2);
                PredezfBit = newFlags & EZFBit;
                PreddfBit = newFlags & DFBit;
                PredccFlagBits = newFlags & ccFlagMask;
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SrlImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
DestReg = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            uint8_t shiftAmt = (imm8 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint64_t logicalMask = mask(dataSize * 8 - shiftAmt);
            DestReg = merge(DestReg, (psrc1 >> shiftAmt) & logicalMask, dataSize);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SrlImmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            uint8_t shiftAmt = (imm8 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint64_t logicalMask = mask(dataSize * 8 - shiftAmt);
            DestReg = (psrc1 >> shiftAmt) & logicalMask;
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SrlFlagsImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            uint8_t shiftAmt = (imm8 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint64_t logicalMask = mask(dataSize * 8 - shiftAmt);
            DestReg = merge(DestReg, (psrc1 >> shiftAmt) & logicalMask, dataSize);
            ;
                
            // If the shift amount is zero, no flags should be modified.
            if (shiftAmt) {
                //Zero out any flags we might modify. This way we only have to
                //worry about setting them.
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                //If some combination of the CF bits need to be set, set them.
                if ((ext & (CFBit | ECFBit)) && 
                        shiftAmt <= dataSize * 8 &&
                        bits(SrcReg1, shiftAmt - 1)) {
                    PredcfofBits = PredcfofBits | (ext & CFBit);
                    PredecfBit = PredecfBit | (ext & ECFBit);
                }
                //Figure out what the OF bit should be.
                if ((ext & OFBit) && bits(SrcReg1, dataSize * 8 - 1))
                    PredcfofBits = PredcfofBits | OFBit;
                //Use the regular mechanisms to calculate the other flags.
                uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                PredezfBit, ext & ~(CFBit | ECFBit | OFBit),
                                DestReg, psrc1, imm8);
                PredezfBit = newFlags & EZFBit;
                PreddfBit = newFlags & DFBit;
                PredccFlagBits = newFlags & ccFlagMask;
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SrlFlagsImmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            uint8_t shiftAmt = (imm8 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint64_t logicalMask = mask(dataSize * 8 - shiftAmt);
            DestReg = (psrc1 >> shiftAmt) & logicalMask;
            ;
                
            // If the shift amount is zero, no flags should be modified.
            if (shiftAmt) {
                //Zero out any flags we might modify. This way we only have to
                //worry about setting them.
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                //If some combination of the CF bits need to be set, set them.
                if ((ext & (CFBit | ECFBit)) && 
                        shiftAmt <= dataSize * 8 &&
                        bits(SrcReg1, shiftAmt - 1)) {
                    PredcfofBits = PredcfofBits | (ext & CFBit);
                    PredecfBit = PredecfBit | (ext & ECFBit);
                }
                //Figure out what the OF bit should be.
                if ((ext & OFBit) && bits(SrcReg1, dataSize * 8 - 1))
                    PredcfofBits = PredcfofBits | OFBit;
                //Use the regular mechanisms to calculate the other flags.
                uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                PredezfBit, ext & ~(CFBit | ECFBit | OFBit),
                                DestReg, psrc1, imm8);
                PredezfBit = newFlags & EZFBit;
                PreddfBit = newFlags & DFBit;
                PredccFlagBits = newFlags & ccFlagMask;
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Sra::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
DestReg = xc->readIntRegOperand(this, 2);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint8_t shiftAmt = (psrc2 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint64_t arithMask = (shiftAmt == 0) ? 0 :
                -bits(psrc1, dataSize * 8 - 1) << (dataSize * 8 - shiftAmt);
            DestReg = merge(DestReg, (psrc1 >> shiftAmt) | arithMask, dataSize);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SraBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint8_t shiftAmt = (psrc2 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint64_t arithMask = (shiftAmt == 0) ? 0 :
                -bits(psrc1, dataSize * 8 - 1) << (dataSize * 8 - shiftAmt);
            DestReg = ((psrc1 >> shiftAmt) | arithMask) & mask(dataSize * 8);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SraFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint8_t shiftAmt = (psrc2 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint64_t arithMask = (shiftAmt == 0) ? 0 :
                -bits(psrc1, dataSize * 8 - 1) << (dataSize * 8 - shiftAmt);
            DestReg = merge(DestReg, (psrc1 >> shiftAmt) | arithMask, dataSize);
            ;
                
            // If the shift amount is zero, no flags should be modified.
            if (shiftAmt) {
                //Zero out any flags we might modify. This way we only have to
                //worry about setting them.
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                //If some combination of the CF bits need to be set, set them.
                uint8_t effectiveShift =
                    (shiftAmt <= dataSize * 8) ? shiftAmt : (dataSize * 8);
                if ((ext & (CFBit | ECFBit)) &&
                        bits(SrcReg1, effectiveShift - 1)) {
                    PredcfofBits = PredcfofBits | (ext & CFBit);
                    PredecfBit = PredecfBit | (ext & ECFBit);
                }
                //Use the regular mechanisms to calculate the other flags.
                uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                PredezfBit, ext & ~(CFBit | ECFBit | OFBit),
                                DestReg, psrc1, psrc2);
                PredezfBit = newFlags & EZFBit;
                PreddfBit = newFlags & DFBit;
                PredccFlagBits = newFlags & ccFlagMask;
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SraFlagsBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint8_t shiftAmt = (psrc2 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint64_t arithMask = (shiftAmt == 0) ? 0 :
                -bits(psrc1, dataSize * 8 - 1) << (dataSize * 8 - shiftAmt);
            DestReg = ((psrc1 >> shiftAmt) | arithMask) & mask(dataSize * 8);
            ;
                
            // If the shift amount is zero, no flags should be modified.
            if (shiftAmt) {
                //Zero out any flags we might modify. This way we only have to
                //worry about setting them.
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                //If some combination of the CF bits need to be set, set them.
                uint8_t effectiveShift =
                    (shiftAmt <= dataSize * 8) ? shiftAmt : (dataSize * 8);
                if ((ext & (CFBit | ECFBit)) &&
                        bits(SrcReg1, effectiveShift - 1)) {
                    PredcfofBits = PredcfofBits | (ext & CFBit);
                    PredecfBit = PredecfBit | (ext & ECFBit);
                }
                //Use the regular mechanisms to calculate the other flags.
                uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                PredezfBit, ext & ~(CFBit | ECFBit | OFBit),
                                DestReg, psrc1, psrc2);
                PredezfBit = newFlags & EZFBit;
                PreddfBit = newFlags & DFBit;
                PredccFlagBits = newFlags & ccFlagMask;
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SraImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
DestReg = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            uint8_t shiftAmt = (imm8 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint64_t arithMask = (shiftAmt == 0) ? 0 :
                -bits(psrc1, dataSize * 8 - 1) << (dataSize * 8 - shiftAmt);
            DestReg = merge(DestReg, (psrc1 >> shiftAmt) | arithMask, dataSize);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SraImmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            uint8_t shiftAmt = (imm8 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint64_t arithMask = (shiftAmt == 0) ? 0 :
                -bits(psrc1, dataSize * 8 - 1) << (dataSize * 8 - shiftAmt);
            DestReg = ((psrc1 >> shiftAmt) | arithMask) & mask(dataSize * 8);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SraFlagsImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            uint8_t shiftAmt = (imm8 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint64_t arithMask = (shiftAmt == 0) ? 0 :
                -bits(psrc1, dataSize * 8 - 1) << (dataSize * 8 - shiftAmt);
            DestReg = merge(DestReg, (psrc1 >> shiftAmt) | arithMask, dataSize);
            ;
                
            // If the shift amount is zero, no flags should be modified.
            if (shiftAmt) {
                //Zero out any flags we might modify. This way we only have to
                //worry about setting them.
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                //If some combination of the CF bits need to be set, set them.
                uint8_t effectiveShift =
                    (shiftAmt <= dataSize * 8) ? shiftAmt : (dataSize * 8);
                if ((ext & (CFBit | ECFBit)) &&
                        bits(SrcReg1, effectiveShift - 1)) {
                    PredcfofBits = PredcfofBits | (ext & CFBit);
                    PredecfBit = PredecfBit | (ext & ECFBit);
                }
                //Use the regular mechanisms to calculate the other flags.
                uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                PredezfBit, ext & ~(CFBit | ECFBit | OFBit),
                                DestReg, psrc1, imm8);
                PredezfBit = newFlags & EZFBit;
                PreddfBit = newFlags & DFBit;
                PredccFlagBits = newFlags & ccFlagMask;
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SraFlagsImmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            uint8_t shiftAmt = (imm8 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint64_t arithMask = (shiftAmt == 0) ? 0 :
                -bits(psrc1, dataSize * 8 - 1) << (dataSize * 8 - shiftAmt);
            DestReg = ((psrc1 >> shiftAmt) | arithMask) & mask(dataSize * 8);
            ;
                
            // If the shift amount is zero, no flags should be modified.
            if (shiftAmt) {
                //Zero out any flags we might modify. This way we only have to
                //worry about setting them.
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                //If some combination of the CF bits need to be set, set them.
                uint8_t effectiveShift =
                    (shiftAmt <= dataSize * 8) ? shiftAmt : (dataSize * 8);
                if ((ext & (CFBit | ECFBit)) &&
                        bits(SrcReg1, effectiveShift - 1)) {
                    PredcfofBits = PredcfofBits | (ext & CFBit);
                    PredecfBit = PredecfBit | (ext & ECFBit);
                }
                //Use the regular mechanisms to calculate the other flags.
                uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                PredezfBit, ext & ~(CFBit | ECFBit | OFBit),
                                DestReg, psrc1, imm8);
                PredezfBit = newFlags & EZFBit;
                PreddfBit = newFlags & DFBit;
                PredccFlagBits = newFlags & ccFlagMask;
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Ror::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
DestReg = xc->readIntRegOperand(this, 2);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint8_t shiftAmt =
                (psrc2 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t realShiftAmt = shiftAmt % (dataSize * 8);
            if (realShiftAmt) {
                uint64_t top = psrc1 << (dataSize * 8 - realShiftAmt);
                uint64_t bottom = bits(psrc1, dataSize * 8, realShiftAmt);
                DestReg = merge(DestReg, top | bottom, dataSize);
            } else
                DestReg = merge(DestReg, DestReg, dataSize);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault RorFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint8_t shiftAmt =
                (psrc2 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t realShiftAmt = shiftAmt % (dataSize * 8);
            if (realShiftAmt) {
                uint64_t top = psrc1 << (dataSize * 8 - realShiftAmt);
                uint64_t bottom = bits(psrc1, dataSize * 8, realShiftAmt);
                DestReg = merge(DestReg, top | bottom, dataSize);
            } else
                DestReg = merge(DestReg, DestReg, dataSize);
            ;
                
            // If the shift amount is zero, no flags should be modified.
            if (shiftAmt) {
                //Zero out any flags we might modify. This way we only have to
                //worry about setting them.
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                //Find the most and second most significant bits of the result.
                int msb = bits(DestReg, dataSize * 8 - 1);
                int smsb = bits(DestReg, dataSize * 8 - 2);
                //If some combination of the CF bits need to be set, set them.
                if ((ext & (CFBit | ECFBit)) && msb) {
                    PredcfofBits = PredcfofBits | (ext & CFBit);
                    PredecfBit = PredecfBit | (ext & ECFBit);
                }
                //Figure out what the OF bit should be.
                if ((ext & OFBit) && (msb ^ smsb))
                    PredcfofBits = PredcfofBits | OFBit;
                //Use the regular mechanisms to calculate the other flags.
                uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                PredezfBit, ext & ~(CFBit | ECFBit | OFBit),
                                DestReg, psrc1, psrc2);
                PredezfBit = newFlags & EZFBit;
                PreddfBit = newFlags & DFBit;
                PredccFlagBits = newFlags & ccFlagMask;
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault RorImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
DestReg = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            uint8_t shiftAmt =
                (imm8 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t realShiftAmt = shiftAmt % (dataSize * 8);
            if (realShiftAmt) {
                uint64_t top = psrc1 << (dataSize * 8 - realShiftAmt);
                uint64_t bottom = bits(psrc1, dataSize * 8, realShiftAmt);
                DestReg = merge(DestReg, top | bottom, dataSize);
            } else
                DestReg = merge(DestReg, DestReg, dataSize);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault RorFlagsImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            uint8_t shiftAmt =
                (imm8 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t realShiftAmt = shiftAmt % (dataSize * 8);
            if (realShiftAmt) {
                uint64_t top = psrc1 << (dataSize * 8 - realShiftAmt);
                uint64_t bottom = bits(psrc1, dataSize * 8, realShiftAmt);
                DestReg = merge(DestReg, top | bottom, dataSize);
            } else
                DestReg = merge(DestReg, DestReg, dataSize);
            ;
                
            // If the shift amount is zero, no flags should be modified.
            if (shiftAmt) {
                //Zero out any flags we might modify. This way we only have to
                //worry about setting them.
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                //Find the most and second most significant bits of the result.
                int msb = bits(DestReg, dataSize * 8 - 1);
                int smsb = bits(DestReg, dataSize * 8 - 2);
                //If some combination of the CF bits need to be set, set them.
                if ((ext & (CFBit | ECFBit)) && msb) {
                    PredcfofBits = PredcfofBits | (ext & CFBit);
                    PredecfBit = PredecfBit | (ext & ECFBit);
                }
                //Figure out what the OF bit should be.
                if ((ext & OFBit) && (msb ^ smsb))
                    PredcfofBits = PredcfofBits | OFBit;
                //Use the regular mechanisms to calculate the other flags.
                uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                PredezfBit, ext & ~(CFBit | ECFBit | OFBit),
                                DestReg, psrc1, imm8);
                PredezfBit = newFlags & EZFBit;
                PreddfBit = newFlags & DFBit;
                PredccFlagBits = newFlags & ccFlagMask;
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Rcr::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t cfofBits = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
DestReg = xc->readIntRegOperand(this, 2);
cfofBits = xc->readCCRegOperand(this, 3);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint8_t shiftAmt =
                (psrc2 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t realShiftAmt = shiftAmt % (dataSize * 8 + 1);
            if (realShiftAmt) {
                CCFlagBits flags = cfofBits;
                uint64_t top = flags.cf << (dataSize * 8 - realShiftAmt);
                if (realShiftAmt > 1)
                    top |= psrc1 << (dataSize * 8 - realShiftAmt + 1);
                uint64_t bottom = bits(psrc1, dataSize * 8 - 1, realShiftAmt);
                DestReg = merge(DestReg, top | bottom, dataSize);
            } else
                DestReg = merge(DestReg, DestReg, dataSize);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault RcrFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
cfofBits = xc->readCCRegOperand(this, _sourceIndex++);
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint8_t shiftAmt =
                (psrc2 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t realShiftAmt = shiftAmt % (dataSize * 8 + 1);
            if (realShiftAmt) {
                CCFlagBits flags = cfofBits;
                uint64_t top = flags.cf << (dataSize * 8 - realShiftAmt);
                if (realShiftAmt > 1)
                    top |= psrc1 << (dataSize * 8 - realShiftAmt + 1);
                uint64_t bottom = bits(psrc1, dataSize * 8 - 1, realShiftAmt);
                DestReg = merge(DestReg, top | bottom, dataSize);
            } else
                DestReg = merge(DestReg, DestReg, dataSize);
            ;
                
            // If the shift amount is zero, no flags should be modified.
            if (shiftAmt) {
                int origCFBit = (cfofBits & CFBit) ? 1 : 0;
                //Zero out any flags we might modify. This way we only have to
                //worry about setting them.
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                //Figure out what the OF bit should be.
                if ((ext & OFBit) && (origCFBit ^
                                      bits(SrcReg1, dataSize * 8 - 1))) {
                    PredcfofBits = PredcfofBits | OFBit;
                }
                //If some combination of the CF bits need to be set, set them.
                if ((ext & (CFBit | ECFBit)) &&
                        (realShiftAmt == 0) ? origCFBit :
                        bits(SrcReg1, realShiftAmt - 1)) {
                    PredcfofBits = PredcfofBits | (ext & CFBit);
                    PredecfBit = PredecfBit | (ext & ECFBit);
                }
                //Use the regular mechanisms to calculate the other flags.
                uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                PredezfBit, ext & ~(CFBit | ECFBit | OFBit),
                                DestReg, psrc1, psrc2);
                PredezfBit = newFlags & EZFBit;
                PreddfBit = newFlags & DFBit;
                PredccFlagBits = newFlags & ccFlagMask;
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault RcrImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t cfofBits = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
DestReg = xc->readIntRegOperand(this, 1);
cfofBits = xc->readCCRegOperand(this, 2);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            uint8_t shiftAmt =
                (imm8 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t realShiftAmt = shiftAmt % (dataSize * 8 + 1);
            if (realShiftAmt) {
                CCFlagBits flags = cfofBits;
                uint64_t top = flags.cf << (dataSize * 8 - realShiftAmt);
                if (realShiftAmt > 1)
                    top |= psrc1 << (dataSize * 8 - realShiftAmt + 1);
                uint64_t bottom = bits(psrc1, dataSize * 8 - 1, realShiftAmt);
                DestReg = merge(DestReg, top | bottom, dataSize);
            } else
                DestReg = merge(DestReg, DestReg, dataSize);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault RcrFlagsImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
cfofBits = xc->readCCRegOperand(this, _sourceIndex++);
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            uint8_t shiftAmt =
                (imm8 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t realShiftAmt = shiftAmt % (dataSize * 8 + 1);
            if (realShiftAmt) {
                CCFlagBits flags = cfofBits;
                uint64_t top = flags.cf << (dataSize * 8 - realShiftAmt);
                if (realShiftAmt > 1)
                    top |= psrc1 << (dataSize * 8 - realShiftAmt + 1);
                uint64_t bottom = bits(psrc1, dataSize * 8 - 1, realShiftAmt);
                DestReg = merge(DestReg, top | bottom, dataSize);
            } else
                DestReg = merge(DestReg, DestReg, dataSize);
            ;
                
            // If the shift amount is zero, no flags should be modified.
            if (shiftAmt) {
                int origCFBit = (cfofBits & CFBit) ? 1 : 0;
                //Zero out any flags we might modify. This way we only have to
                //worry about setting them.
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                //Figure out what the OF bit should be.
                if ((ext & OFBit) && (origCFBit ^
                                      bits(SrcReg1, dataSize * 8 - 1))) {
                    PredcfofBits = PredcfofBits | OFBit;
                }
                //If some combination of the CF bits need to be set, set them.
                if ((ext & (CFBit | ECFBit)) &&
                        (realShiftAmt == 0) ? origCFBit :
                        bits(SrcReg1, realShiftAmt - 1)) {
                    PredcfofBits = PredcfofBits | (ext & CFBit);
                    PredecfBit = PredecfBit | (ext & ECFBit);
                }
                //Use the regular mechanisms to calculate the other flags.
                uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                PredezfBit, ext & ~(CFBit | ECFBit | OFBit),
                                DestReg, psrc1, imm8);
                PredezfBit = newFlags & EZFBit;
                PreddfBit = newFlags & DFBit;
                PredccFlagBits = newFlags & ccFlagMask;
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Rol::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
DestReg = xc->readIntRegOperand(this, 2);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint8_t shiftAmt =
                (psrc2 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t realShiftAmt = shiftAmt % (dataSize * 8);
            if (realShiftAmt) {
                uint64_t top = psrc1 << realShiftAmt;
                uint64_t bottom =
                    bits(psrc1, dataSize * 8 - 1, dataSize * 8 - realShiftAmt);
                DestReg = merge(DestReg, top | bottom, dataSize);
            } else
                DestReg = merge(DestReg, DestReg, dataSize);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault RolFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint8_t shiftAmt =
                (psrc2 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t realShiftAmt = shiftAmt % (dataSize * 8);
            if (realShiftAmt) {
                uint64_t top = psrc1 << realShiftAmt;
                uint64_t bottom =
                    bits(psrc1, dataSize * 8 - 1, dataSize * 8 - realShiftAmt);
                DestReg = merge(DestReg, top | bottom, dataSize);
            } else
                DestReg = merge(DestReg, DestReg, dataSize);
            ;
                
            // If the shift amount is zero, no flags should be modified.
            if (shiftAmt) {
                //Zero out any flags we might modify. This way we only have to
                //worry about setting them.
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                //The CF bits, if set, would be set to the lsb of the result.
                int lsb = DestReg & 0x1;
                int msb = bits(DestReg, dataSize * 8 - 1);
                //If some combination of the CF bits need to be set, set them.
                if ((ext & (CFBit | ECFBit)) && lsb) {
                    PredcfofBits = PredcfofBits | (ext & CFBit);
                    PredecfBit = PredecfBit | (ext & ECFBit);
                }
                //Figure out what the OF bit should be.
                if ((ext & OFBit) && (msb ^ lsb))
                    PredcfofBits = PredcfofBits | OFBit;
                //Use the regular mechanisms to calculate the other flags.
                uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                PredezfBit, ext & ~(CFBit | ECFBit | OFBit),
                                DestReg, psrc1, psrc2);
                PredezfBit = newFlags & EZFBit;
                PreddfBit = newFlags & DFBit;
                PredccFlagBits = newFlags & ccFlagMask;
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault RolImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
DestReg = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            uint8_t shiftAmt =
                (imm8 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t realShiftAmt = shiftAmt % (dataSize * 8);
            if (realShiftAmt) {
                uint64_t top = psrc1 << realShiftAmt;
                uint64_t bottom =
                    bits(psrc1, dataSize * 8 - 1, dataSize * 8 - realShiftAmt);
                DestReg = merge(DestReg, top | bottom, dataSize);
            } else
                DestReg = merge(DestReg, DestReg, dataSize);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault RolFlagsImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            uint8_t shiftAmt =
                (imm8 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t realShiftAmt = shiftAmt % (dataSize * 8);
            if (realShiftAmt) {
                uint64_t top = psrc1 << realShiftAmt;
                uint64_t bottom =
                    bits(psrc1, dataSize * 8 - 1, dataSize * 8 - realShiftAmt);
                DestReg = merge(DestReg, top | bottom, dataSize);
            } else
                DestReg = merge(DestReg, DestReg, dataSize);
            ;
                
            // If the shift amount is zero, no flags should be modified.
            if (shiftAmt) {
                //Zero out any flags we might modify. This way we only have to
                //worry about setting them.
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                //The CF bits, if set, would be set to the lsb of the result.
                int lsb = DestReg & 0x1;
                int msb = bits(DestReg, dataSize * 8 - 1);
                //If some combination of the CF bits need to be set, set them.
                if ((ext & (CFBit | ECFBit)) && lsb) {
                    PredcfofBits = PredcfofBits | (ext & CFBit);
                    PredecfBit = PredecfBit | (ext & ECFBit);
                }
                //Figure out what the OF bit should be.
                if ((ext & OFBit) && (msb ^ lsb))
                    PredcfofBits = PredcfofBits | OFBit;
                //Use the regular mechanisms to calculate the other flags.
                uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                PredezfBit, ext & ~(CFBit | ECFBit | OFBit),
                                DestReg, psrc1, imm8);
                PredezfBit = newFlags & EZFBit;
                PreddfBit = newFlags & DFBit;
                PredccFlagBits = newFlags & ccFlagMask;
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Rcl::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t cfofBits = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
DestReg = xc->readIntRegOperand(this, 2);
cfofBits = xc->readCCRegOperand(this, 3);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint8_t shiftAmt =
                (psrc2 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t realShiftAmt = shiftAmt % (dataSize * 8 + 1);
            if (realShiftAmt) {
                CCFlagBits flags = cfofBits;
                uint64_t top = psrc1 << realShiftAmt;
                uint64_t bottom = flags.cf << (realShiftAmt - 1);
                if(shiftAmt > 1)
                    bottom |=
                        bits(psrc1, dataSize * 8 - 1,
                                   dataSize * 8 - realShiftAmt + 1);
                DestReg = merge(DestReg, top | bottom, dataSize);
            } else
                DestReg = merge(DestReg, DestReg, dataSize);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault RclFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
cfofBits = xc->readCCRegOperand(this, _sourceIndex++);
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint8_t shiftAmt =
                (psrc2 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t realShiftAmt = shiftAmt % (dataSize * 8 + 1);
            if (realShiftAmt) {
                CCFlagBits flags = cfofBits;
                uint64_t top = psrc1 << realShiftAmt;
                uint64_t bottom = flags.cf << (realShiftAmt - 1);
                if(shiftAmt > 1)
                    bottom |=
                        bits(psrc1, dataSize * 8 - 1,
                                   dataSize * 8 - realShiftAmt + 1);
                DestReg = merge(DestReg, top | bottom, dataSize);
            } else
                DestReg = merge(DestReg, DestReg, dataSize);
            ;
                
            // If the shift amount is zero, no flags should be modified.
            if (shiftAmt) {
                int origCFBit = (cfofBits & CFBit) ? 1 : 0;
                //Zero out any flags we might modify. This way we only have to
                //worry about setting them.
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                int msb = bits(DestReg, dataSize * 8 - 1);
                int CFBits = bits(SrcReg1, dataSize * 8 - realShiftAmt);
                //If some combination of the CF bits need to be set, set them.
                if ((ext & (CFBit | ECFBit)) && 
                        (realShiftAmt == 0) ? origCFBit : CFBits) {
                    PredcfofBits = PredcfofBits | (ext & CFBit);
                    PredecfBit = PredecfBit | (ext & ECFBit);
                }
                //Figure out what the OF bit should be.
                if ((ext & OFBit) && (msb ^ CFBits))
                    PredcfofBits = PredcfofBits | OFBit;
                //Use the regular mechanisms to calculate the other flags.
                uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                PredezfBit, ext & ~(CFBit | ECFBit | OFBit),
                                DestReg, psrc1, psrc2);
                PredezfBit = newFlags & EZFBit;
                PreddfBit = newFlags & DFBit;
                PredccFlagBits = newFlags & ccFlagMask;
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault RclImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t cfofBits = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
DestReg = xc->readIntRegOperand(this, 1);
cfofBits = xc->readCCRegOperand(this, 2);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            uint8_t shiftAmt =
                (imm8 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t realShiftAmt = shiftAmt % (dataSize * 8 + 1);
            if (realShiftAmt) {
                CCFlagBits flags = cfofBits;
                uint64_t top = psrc1 << realShiftAmt;
                uint64_t bottom = flags.cf << (realShiftAmt - 1);
                if(shiftAmt > 1)
                    bottom |=
                        bits(psrc1, dataSize * 8 - 1,
                                   dataSize * 8 - realShiftAmt + 1);
                DestReg = merge(DestReg, top | bottom, dataSize);
            } else
                DestReg = merge(DestReg, DestReg, dataSize);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault RclFlagsImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
cfofBits = xc->readCCRegOperand(this, _sourceIndex++);
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            uint8_t shiftAmt =
                (imm8 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t realShiftAmt = shiftAmt % (dataSize * 8 + 1);
            if (realShiftAmt) {
                CCFlagBits flags = cfofBits;
                uint64_t top = psrc1 << realShiftAmt;
                uint64_t bottom = flags.cf << (realShiftAmt - 1);
                if(shiftAmt > 1)
                    bottom |=
                        bits(psrc1, dataSize * 8 - 1,
                                   dataSize * 8 - realShiftAmt + 1);
                DestReg = merge(DestReg, top | bottom, dataSize);
            } else
                DestReg = merge(DestReg, DestReg, dataSize);
            ;
                
            // If the shift amount is zero, no flags should be modified.
            if (shiftAmt) {
                int origCFBit = (cfofBits & CFBit) ? 1 : 0;
                //Zero out any flags we might modify. This way we only have to
                //worry about setting them.
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                int msb = bits(DestReg, dataSize * 8 - 1);
                int CFBits = bits(SrcReg1, dataSize * 8 - realShiftAmt);
                //If some combination of the CF bits need to be set, set them.
                if ((ext & (CFBit | ECFBit)) && 
                        (realShiftAmt == 0) ? origCFBit : CFBits) {
                    PredcfofBits = PredcfofBits | (ext & CFBit);
                    PredecfBit = PredecfBit | (ext & ECFBit);
                }
                //Figure out what the OF bit should be.
                if ((ext & OFBit) && (msb ^ CFBits))
                    PredcfofBits = PredcfofBits | OFBit;
                //Use the regular mechanisms to calculate the other flags.
                uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                PredezfBit, ext & ~(CFBit | ECFBit | OFBit),
                                DestReg, psrc1, imm8);
                PredezfBit = newFlags & EZFBit;
                PreddfBit = newFlags & DFBit;
                PredccFlagBits = newFlags & ccFlagMask;
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Sld::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t DoubleBits = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
DestReg = xc->readIntRegOperand(this, 2);
DoubleBits = xc->readIntRegOperand(this, 3);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint8_t shiftAmt = (psrc2 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t dataBits = dataSize * 8;
            uint8_t realShiftAmt = shiftAmt % (2 * dataBits);
            uint64_t result;
            if (realShiftAmt == 0) {
                result = psrc1;
            } else if (realShiftAmt < dataBits) {
                result = (psrc1 << realShiftAmt) |
                         (DoubleBits >> (dataBits - realShiftAmt));
            } else {
                result = (DoubleBits << (realShiftAmt - dataBits)) |
                         (psrc1 >> (2 * dataBits - realShiftAmt));
            }
            DestReg = merge(DestReg, result, dataSize);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SldBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t DoubleBits = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
DoubleBits = xc->readIntRegOperand(this, 2);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint8_t shiftAmt = (psrc2 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t dataBits = dataSize * 8;
            uint8_t realShiftAmt = shiftAmt % (2 * dataBits);
            uint64_t result;
            if (realShiftAmt == 0) {
                result = psrc1;
            } else if (realShiftAmt < dataBits) {
                result = (psrc1 << realShiftAmt) |
                         (DoubleBits >> (dataBits - realShiftAmt));
            } else {
                result = (DoubleBits << (realShiftAmt - dataBits)) |
                         (psrc1 >> (2 * dataBits - realShiftAmt));
            }
            DestReg = result & mask(dataSize * 8);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SldFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t DoubleBits = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
DoubleBits = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint8_t shiftAmt = (psrc2 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t dataBits = dataSize * 8;
            uint8_t realShiftAmt = shiftAmt % (2 * dataBits);
            uint64_t result;
            if (realShiftAmt == 0) {
                result = psrc1;
            } else if (realShiftAmt < dataBits) {
                result = (psrc1 << realShiftAmt) |
                         (DoubleBits >> (dataBits - realShiftAmt));
            } else {
                result = (DoubleBits << (realShiftAmt - dataBits)) |
                         (psrc1 >> (2 * dataBits - realShiftAmt));
            }
            DestReg = merge(DestReg, result, dataSize);
            ;
                
            // If the shift amount is zero, no flags should be modified.
            if (shiftAmt) {
                //Zero out any flags we might modify. This way we only have to
                //worry about setting them.
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                int CFBits = 0;
                //Figure out if we -would- set the CF bits if requested.
                if ((realShiftAmt == 0 &&
                        bits(DoubleBits, 0)) ||
                    (realShiftAmt <= dataBits &&
                     bits(SrcReg1, dataBits - realShiftAmt)) ||
                    (realShiftAmt > dataBits &&
                     bits(DoubleBits, 2 * dataBits - realShiftAmt))) {
                    CFBits = 1;
                }
                //If some combination of the CF bits need to be set, set them.
                if ((ext & (CFBit | ECFBit)) && CFBits) {
                    PredcfofBits = PredcfofBits | (ext & CFBit);
                    PredecfBit = PredecfBit | (ext & ECFBit);
                }
                //Figure out what the OF bit should be.
                if ((ext & OFBit) && (bits(SrcReg1, dataBits - 1) ^
                                      bits(result, dataBits - 1)))
                    PredcfofBits = PredcfofBits | OFBit;
                //Use the regular mechanisms to calculate the other flags.
                uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                PredezfBit, ext & ~(CFBit | ECFBit | OFBit),
                                DestReg, psrc1, psrc2);
                PredezfBit = newFlags & EZFBit;
                PreddfBit = newFlags & DFBit;
                PredccFlagBits = newFlags & ccFlagMask;
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SldFlagsBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t DoubleBits = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
DoubleBits = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint8_t shiftAmt = (psrc2 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t dataBits = dataSize * 8;
            uint8_t realShiftAmt = shiftAmt % (2 * dataBits);
            uint64_t result;
            if (realShiftAmt == 0) {
                result = psrc1;
            } else if (realShiftAmt < dataBits) {
                result = (psrc1 << realShiftAmt) |
                         (DoubleBits >> (dataBits - realShiftAmt));
            } else {
                result = (DoubleBits << (realShiftAmt - dataBits)) |
                         (psrc1 >> (2 * dataBits - realShiftAmt));
            }
            DestReg = result & mask(dataSize * 8);
            ;
                
            // If the shift amount is zero, no flags should be modified.
            if (shiftAmt) {
                //Zero out any flags we might modify. This way we only have to
                //worry about setting them.
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                int CFBits = 0;
                //Figure out if we -would- set the CF bits if requested.
                if ((realShiftAmt == 0 &&
                        bits(DoubleBits, 0)) ||
                    (realShiftAmt <= dataBits &&
                     bits(SrcReg1, dataBits - realShiftAmt)) ||
                    (realShiftAmt > dataBits &&
                     bits(DoubleBits, 2 * dataBits - realShiftAmt))) {
                    CFBits = 1;
                }
                //If some combination of the CF bits need to be set, set them.
                if ((ext & (CFBit | ECFBit)) && CFBits) {
                    PredcfofBits = PredcfofBits | (ext & CFBit);
                    PredecfBit = PredecfBit | (ext & ECFBit);
                }
                //Figure out what the OF bit should be.
                if ((ext & OFBit) && (bits(SrcReg1, dataBits - 1) ^
                                      bits(result, dataBits - 1)))
                    PredcfofBits = PredcfofBits | OFBit;
                //Use the regular mechanisms to calculate the other flags.
                uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                PredezfBit, ext & ~(CFBit | ECFBit | OFBit),
                                DestReg, psrc1, psrc2);
                PredezfBit = newFlags & EZFBit;
                PreddfBit = newFlags & DFBit;
                PredccFlagBits = newFlags & ccFlagMask;
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SldImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t DoubleBits = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
DestReg = xc->readIntRegOperand(this, 1);
DoubleBits = xc->readIntRegOperand(this, 2);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            uint8_t shiftAmt = (imm8 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t dataBits = dataSize * 8;
            uint8_t realShiftAmt = shiftAmt % (2 * dataBits);
            uint64_t result;
            if (realShiftAmt == 0) {
                result = psrc1;
            } else if (realShiftAmt < dataBits) {
                result = (psrc1 << realShiftAmt) |
                         (DoubleBits >> (dataBits - realShiftAmt));
            } else {
                result = (DoubleBits << (realShiftAmt - dataBits)) |
                         (psrc1 >> (2 * dataBits - realShiftAmt));
            }
            DestReg = merge(DestReg, result, dataSize);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SldImmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t DoubleBits = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
DoubleBits = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            uint8_t shiftAmt = (imm8 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t dataBits = dataSize * 8;
            uint8_t realShiftAmt = shiftAmt % (2 * dataBits);
            uint64_t result;
            if (realShiftAmt == 0) {
                result = psrc1;
            } else if (realShiftAmt < dataBits) {
                result = (psrc1 << realShiftAmt) |
                         (DoubleBits >> (dataBits - realShiftAmt));
            } else {
                result = (DoubleBits << (realShiftAmt - dataBits)) |
                         (psrc1 >> (2 * dataBits - realShiftAmt));
            }
            DestReg = result & mask(dataSize * 8);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SldFlagsImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t DoubleBits = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
DoubleBits = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            uint8_t shiftAmt = (imm8 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t dataBits = dataSize * 8;
            uint8_t realShiftAmt = shiftAmt % (2 * dataBits);
            uint64_t result;
            if (realShiftAmt == 0) {
                result = psrc1;
            } else if (realShiftAmt < dataBits) {
                result = (psrc1 << realShiftAmt) |
                         (DoubleBits >> (dataBits - realShiftAmt));
            } else {
                result = (DoubleBits << (realShiftAmt - dataBits)) |
                         (psrc1 >> (2 * dataBits - realShiftAmt));
            }
            DestReg = merge(DestReg, result, dataSize);
            ;
                
            // If the shift amount is zero, no flags should be modified.
            if (shiftAmt) {
                //Zero out any flags we might modify. This way we only have to
                //worry about setting them.
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                int CFBits = 0;
                //Figure out if we -would- set the CF bits if requested.
                if ((realShiftAmt == 0 &&
                        bits(DoubleBits, 0)) ||
                    (realShiftAmt <= dataBits &&
                     bits(SrcReg1, dataBits - realShiftAmt)) ||
                    (realShiftAmt > dataBits &&
                     bits(DoubleBits, 2 * dataBits - realShiftAmt))) {
                    CFBits = 1;
                }
                //If some combination of the CF bits need to be set, set them.
                if ((ext & (CFBit | ECFBit)) && CFBits) {
                    PredcfofBits = PredcfofBits | (ext & CFBit);
                    PredecfBit = PredecfBit | (ext & ECFBit);
                }
                //Figure out what the OF bit should be.
                if ((ext & OFBit) && (bits(SrcReg1, dataBits - 1) ^
                                      bits(result, dataBits - 1)))
                    PredcfofBits = PredcfofBits | OFBit;
                //Use the regular mechanisms to calculate the other flags.
                uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                PredezfBit, ext & ~(CFBit | ECFBit | OFBit),
                                DestReg, psrc1, imm8);
                PredezfBit = newFlags & EZFBit;
                PreddfBit = newFlags & DFBit;
                PredccFlagBits = newFlags & ccFlagMask;
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SldFlagsImmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t DoubleBits = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
DoubleBits = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            uint8_t shiftAmt = (imm8 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t dataBits = dataSize * 8;
            uint8_t realShiftAmt = shiftAmt % (2 * dataBits);
            uint64_t result;
            if (realShiftAmt == 0) {
                result = psrc1;
            } else if (realShiftAmt < dataBits) {
                result = (psrc1 << realShiftAmt) |
                         (DoubleBits >> (dataBits - realShiftAmt));
            } else {
                result = (DoubleBits << (realShiftAmt - dataBits)) |
                         (psrc1 >> (2 * dataBits - realShiftAmt));
            }
            DestReg = result & mask(dataSize * 8);
            ;
                
            // If the shift amount is zero, no flags should be modified.
            if (shiftAmt) {
                //Zero out any flags we might modify. This way we only have to
                //worry about setting them.
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                int CFBits = 0;
                //Figure out if we -would- set the CF bits if requested.
                if ((realShiftAmt == 0 &&
                        bits(DoubleBits, 0)) ||
                    (realShiftAmt <= dataBits &&
                     bits(SrcReg1, dataBits - realShiftAmt)) ||
                    (realShiftAmt > dataBits &&
                     bits(DoubleBits, 2 * dataBits - realShiftAmt))) {
                    CFBits = 1;
                }
                //If some combination of the CF bits need to be set, set them.
                if ((ext & (CFBit | ECFBit)) && CFBits) {
                    PredcfofBits = PredcfofBits | (ext & CFBit);
                    PredecfBit = PredecfBit | (ext & ECFBit);
                }
                //Figure out what the OF bit should be.
                if ((ext & OFBit) && (bits(SrcReg1, dataBits - 1) ^
                                      bits(result, dataBits - 1)))
                    PredcfofBits = PredcfofBits | OFBit;
                //Use the regular mechanisms to calculate the other flags.
                uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                PredezfBit, ext & ~(CFBit | ECFBit | OFBit),
                                DestReg, psrc1, imm8);
                PredezfBit = newFlags & EZFBit;
                PreddfBit = newFlags & DFBit;
                PredccFlagBits = newFlags & ccFlagMask;
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Srd::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t DoubleBits = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
DestReg = xc->readIntRegOperand(this, 2);
DoubleBits = xc->readIntRegOperand(this, 3);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint8_t shiftAmt = (psrc2 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t dataBits = dataSize * 8;
            uint8_t realShiftAmt = shiftAmt % (2 * dataBits);
            uint64_t result;
            if (realShiftAmt == 0) {
                result = psrc1;
            } else if (realShiftAmt < dataBits) {
                // Because what happens to the bits shift -in- on a right
                // shift is not defined in the C/C++ standard, we have to
                // mask them out to be sure they're zero.
                uint64_t logicalMask = mask(dataBits - realShiftAmt);
                result = ((psrc1 >> realShiftAmt) & logicalMask) |
                         (DoubleBits << (dataBits - realShiftAmt));
            } else {
                uint64_t logicalMask = mask(2 * dataBits - realShiftAmt);
                result = ((DoubleBits >> (realShiftAmt - dataBits)) &
                          logicalMask) |
                         (psrc1 << (2 * dataBits - realShiftAmt));
            }
            DestReg = merge(DestReg, result, dataSize);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SrdBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t DoubleBits = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
DoubleBits = xc->readIntRegOperand(this, 2);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint8_t shiftAmt = (psrc2 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t dataBits = dataSize * 8;
            uint8_t realShiftAmt = shiftAmt % (2 * dataBits);
            uint64_t result;
            if (realShiftAmt == 0) {
                result = psrc1;
            } else if (realShiftAmt < dataBits) {
                // Because what happens to the bits shift -in- on a right
                // shift is not defined in the C/C++ standard, we have to
                // mask them out to be sure they're zero.
                uint64_t logicalMask = mask(dataBits - realShiftAmt);
                result = ((psrc1 >> realShiftAmt) & logicalMask) |
                         (DoubleBits << (dataBits - realShiftAmt));
            } else {
                uint64_t logicalMask = mask(2 * dataBits - realShiftAmt);
                result = ((DoubleBits >> (realShiftAmt - dataBits)) &
                          logicalMask) |
                         (psrc1 << (2 * dataBits - realShiftAmt));
            }
            DestReg = result & mask(dataSize * 8);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SrdFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t DoubleBits = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
DoubleBits = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint8_t shiftAmt = (psrc2 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t dataBits = dataSize * 8;
            uint8_t realShiftAmt = shiftAmt % (2 * dataBits);
            uint64_t result;
            if (realShiftAmt == 0) {
                result = psrc1;
            } else if (realShiftAmt < dataBits) {
                // Because what happens to the bits shift -in- on a right
                // shift is not defined in the C/C++ standard, we have to
                // mask them out to be sure they're zero.
                uint64_t logicalMask = mask(dataBits - realShiftAmt);
                result = ((psrc1 >> realShiftAmt) & logicalMask) |
                         (DoubleBits << (dataBits - realShiftAmt));
            } else {
                uint64_t logicalMask = mask(2 * dataBits - realShiftAmt);
                result = ((DoubleBits >> (realShiftAmt - dataBits)) &
                          logicalMask) |
                         (psrc1 << (2 * dataBits - realShiftAmt));
            }
            DestReg = merge(DestReg, result, dataSize);
            ;
                
            // If the shift amount is zero, no flags should be modified.
            if (shiftAmt) {
                //Zero out any flags we might modify. This way we only have to
                //worry about setting them.
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                int CFBits = 0;
                //If some combination of the CF bits need to be set, set them.
                if ((realShiftAmt == 0 &&
                            bits(DoubleBits, dataBits - 1)) ||
                        (realShiftAmt <= dataBits &&
                         bits(SrcReg1, realShiftAmt - 1)) ||
                        (realShiftAmt > dataBits &&
                         bits(DoubleBits, realShiftAmt - dataBits - 1))) {
                    CFBits = 1;
                }
                //If some combination of the CF bits need to be set, set them.
                if ((ext & (CFBit | ECFBit)) && CFBits) {
                    PredcfofBits = PredcfofBits | (ext & CFBit);
                    PredecfBit = PredecfBit | (ext & ECFBit);
                }
                //Figure out what the OF bit should be.
                if ((ext & OFBit) && (bits(SrcReg1, dataBits - 1) ^
                                      bits(result, dataBits - 1)))
                    PredcfofBits = PredcfofBits | OFBit;
                //Use the regular mechanisms to calculate the other flags.
                uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                PredezfBit, ext & ~(CFBit | ECFBit | OFBit),
                                DestReg, psrc1, psrc2);
                PredezfBit = newFlags & EZFBit;
                PreddfBit = newFlags & DFBit;
                PredccFlagBits = newFlags & ccFlagMask;
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SrdFlagsBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t DoubleBits = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
DoubleBits = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint8_t shiftAmt = (psrc2 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t dataBits = dataSize * 8;
            uint8_t realShiftAmt = shiftAmt % (2 * dataBits);
            uint64_t result;
            if (realShiftAmt == 0) {
                result = psrc1;
            } else if (realShiftAmt < dataBits) {
                // Because what happens to the bits shift -in- on a right
                // shift is not defined in the C/C++ standard, we have to
                // mask them out to be sure they're zero.
                uint64_t logicalMask = mask(dataBits - realShiftAmt);
                result = ((psrc1 >> realShiftAmt) & logicalMask) |
                         (DoubleBits << (dataBits - realShiftAmt));
            } else {
                uint64_t logicalMask = mask(2 * dataBits - realShiftAmt);
                result = ((DoubleBits >> (realShiftAmt - dataBits)) &
                          logicalMask) |
                         (psrc1 << (2 * dataBits - realShiftAmt));
            }
            DestReg = result & mask(dataSize * 8);
            ;
                
            // If the shift amount is zero, no flags should be modified.
            if (shiftAmt) {
                //Zero out any flags we might modify. This way we only have to
                //worry about setting them.
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                int CFBits = 0;
                //If some combination of the CF bits need to be set, set them.
                if ((realShiftAmt == 0 &&
                            bits(DoubleBits, dataBits - 1)) ||
                        (realShiftAmt <= dataBits &&
                         bits(SrcReg1, realShiftAmt - 1)) ||
                        (realShiftAmt > dataBits &&
                         bits(DoubleBits, realShiftAmt - dataBits - 1))) {
                    CFBits = 1;
                }
                //If some combination of the CF bits need to be set, set them.
                if ((ext & (CFBit | ECFBit)) && CFBits) {
                    PredcfofBits = PredcfofBits | (ext & CFBit);
                    PredecfBit = PredecfBit | (ext & ECFBit);
                }
                //Figure out what the OF bit should be.
                if ((ext & OFBit) && (bits(SrcReg1, dataBits - 1) ^
                                      bits(result, dataBits - 1)))
                    PredcfofBits = PredcfofBits | OFBit;
                //Use the regular mechanisms to calculate the other flags.
                uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                PredezfBit, ext & ~(CFBit | ECFBit | OFBit),
                                DestReg, psrc1, psrc2);
                PredezfBit = newFlags & EZFBit;
                PreddfBit = newFlags & DFBit;
                PredccFlagBits = newFlags & ccFlagMask;
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SrdImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t DoubleBits = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
DestReg = xc->readIntRegOperand(this, 1);
DoubleBits = xc->readIntRegOperand(this, 2);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            uint8_t shiftAmt = (imm8 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t dataBits = dataSize * 8;
            uint8_t realShiftAmt = shiftAmt % (2 * dataBits);
            uint64_t result;
            if (realShiftAmt == 0) {
                result = psrc1;
            } else if (realShiftAmt < dataBits) {
                // Because what happens to the bits shift -in- on a right
                // shift is not defined in the C/C++ standard, we have to
                // mask them out to be sure they're zero.
                uint64_t logicalMask = mask(dataBits - realShiftAmt);
                result = ((psrc1 >> realShiftAmt) & logicalMask) |
                         (DoubleBits << (dataBits - realShiftAmt));
            } else {
                uint64_t logicalMask = mask(2 * dataBits - realShiftAmt);
                result = ((DoubleBits >> (realShiftAmt - dataBits)) &
                          logicalMask) |
                         (psrc1 << (2 * dataBits - realShiftAmt));
            }
            DestReg = merge(DestReg, result, dataSize);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SrdImmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t DoubleBits = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
DoubleBits = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            uint8_t shiftAmt = (imm8 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t dataBits = dataSize * 8;
            uint8_t realShiftAmt = shiftAmt % (2 * dataBits);
            uint64_t result;
            if (realShiftAmt == 0) {
                result = psrc1;
            } else if (realShiftAmt < dataBits) {
                // Because what happens to the bits shift -in- on a right
                // shift is not defined in the C/C++ standard, we have to
                // mask them out to be sure they're zero.
                uint64_t logicalMask = mask(dataBits - realShiftAmt);
                result = ((psrc1 >> realShiftAmt) & logicalMask) |
                         (DoubleBits << (dataBits - realShiftAmt));
            } else {
                uint64_t logicalMask = mask(2 * dataBits - realShiftAmt);
                result = ((DoubleBits >> (realShiftAmt - dataBits)) &
                          logicalMask) |
                         (psrc1 << (2 * dataBits - realShiftAmt));
            }
            DestReg = result & mask(dataSize * 8);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SrdFlagsImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t DoubleBits = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
DoubleBits = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            uint8_t shiftAmt = (imm8 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t dataBits = dataSize * 8;
            uint8_t realShiftAmt = shiftAmt % (2 * dataBits);
            uint64_t result;
            if (realShiftAmt == 0) {
                result = psrc1;
            } else if (realShiftAmt < dataBits) {
                // Because what happens to the bits shift -in- on a right
                // shift is not defined in the C/C++ standard, we have to
                // mask them out to be sure they're zero.
                uint64_t logicalMask = mask(dataBits - realShiftAmt);
                result = ((psrc1 >> realShiftAmt) & logicalMask) |
                         (DoubleBits << (dataBits - realShiftAmt));
            } else {
                uint64_t logicalMask = mask(2 * dataBits - realShiftAmt);
                result = ((DoubleBits >> (realShiftAmt - dataBits)) &
                          logicalMask) |
                         (psrc1 << (2 * dataBits - realShiftAmt));
            }
            DestReg = merge(DestReg, result, dataSize);
            ;
                
            // If the shift amount is zero, no flags should be modified.
            if (shiftAmt) {
                //Zero out any flags we might modify. This way we only have to
                //worry about setting them.
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                int CFBits = 0;
                //If some combination of the CF bits need to be set, set them.
                if ((realShiftAmt == 0 &&
                            bits(DoubleBits, dataBits - 1)) ||
                        (realShiftAmt <= dataBits &&
                         bits(SrcReg1, realShiftAmt - 1)) ||
                        (realShiftAmt > dataBits &&
                         bits(DoubleBits, realShiftAmt - dataBits - 1))) {
                    CFBits = 1;
                }
                //If some combination of the CF bits need to be set, set them.
                if ((ext & (CFBit | ECFBit)) && CFBits) {
                    PredcfofBits = PredcfofBits | (ext & CFBit);
                    PredecfBit = PredecfBit | (ext & ECFBit);
                }
                //Figure out what the OF bit should be.
                if ((ext & OFBit) && (bits(SrcReg1, dataBits - 1) ^
                                      bits(result, dataBits - 1)))
                    PredcfofBits = PredcfofBits | OFBit;
                //Use the regular mechanisms to calculate the other flags.
                uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                PredezfBit, ext & ~(CFBit | ECFBit | OFBit),
                                DestReg, psrc1, imm8);
                PredezfBit = newFlags & EZFBit;
                PreddfBit = newFlags & DFBit;
                PredccFlagBits = newFlags & ccFlagMask;
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SrdFlagsImmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t DoubleBits = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PreddfBit = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
DoubleBits = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PreddfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            uint8_t shiftAmt = (imm8 & ((dataSize == 8) ? mask(6) : mask(5)));
            uint8_t dataBits = dataSize * 8;
            uint8_t realShiftAmt = shiftAmt % (2 * dataBits);
            uint64_t result;
            if (realShiftAmt == 0) {
                result = psrc1;
            } else if (realShiftAmt < dataBits) {
                // Because what happens to the bits shift -in- on a right
                // shift is not defined in the C/C++ standard, we have to
                // mask them out to be sure they're zero.
                uint64_t logicalMask = mask(dataBits - realShiftAmt);
                result = ((psrc1 >> realShiftAmt) & logicalMask) |
                         (DoubleBits << (dataBits - realShiftAmt));
            } else {
                uint64_t logicalMask = mask(2 * dataBits - realShiftAmt);
                result = ((DoubleBits >> (realShiftAmt - dataBits)) &
                          logicalMask) |
                         (psrc1 << (2 * dataBits - realShiftAmt));
            }
            DestReg = result & mask(dataSize * 8);
            ;
                
            // If the shift amount is zero, no flags should be modified.
            if (shiftAmt) {
                //Zero out any flags we might modify. This way we only have to
                //worry about setting them.
                PredcfofBits = PredcfofBits & ~(ext & (CFBit | OFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                int CFBits = 0;
                //If some combination of the CF bits need to be set, set them.
                if ((realShiftAmt == 0 &&
                            bits(DoubleBits, dataBits - 1)) ||
                        (realShiftAmt <= dataBits &&
                         bits(SrcReg1, realShiftAmt - 1)) ||
                        (realShiftAmt > dataBits &&
                         bits(DoubleBits, realShiftAmt - dataBits - 1))) {
                    CFBits = 1;
                }
                //If some combination of the CF bits need to be set, set them.
                if ((ext & (CFBit | ECFBit)) && CFBits) {
                    PredcfofBits = PredcfofBits | (ext & CFBit);
                    PredecfBit = PredecfBit | (ext & ECFBit);
                }
                //Figure out what the OF bit should be.
                if ((ext & OFBit) && (bits(SrcReg1, dataBits - 1) ^
                                      bits(result, dataBits - 1)))
                    PredcfofBits = PredcfofBits | OFBit;
                //Use the regular mechanisms to calculate the other flags.
                uint64_t newFlags = genFlags(PredccFlagBits | PreddfBit |
                                PredezfBit, ext & ~(CFBit | ECFBit | OFBit),
                                DestReg, psrc1, imm8);
                PredezfBit = newFlags & EZFBit;
                PreddfBit = newFlags & DFBit;
                PredccFlagBits = newFlags & ccFlagMask;
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & DFBit) != 0))
        {
            uint64_t final_val = PreddfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Mdb::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DoubleBits = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);
DoubleBits = psrc1 ^ psrc2;;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DoubleBits;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault MdbImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DoubleBits = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
DoubleBits = psrc1 ^ imm8;;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DoubleBits;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Wrip::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t NRIP = 0;
uint64_t CSBase = 0;
TheISA::PCState __parserAutoPCState;
;
            __parserAutoPCState = xc->pcState();
SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
NRIP = __parserAutoPCState.npc();
CSBase = xc->readMiscRegOperand(this, 2);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
int64_t spsrc2 = signedPick(SrcReg2, 1, dataSize);
NRIP = psrc1 + spsrc2 + CSBase;;
                ;
            }
            else
            {
                NRIP = NRIP;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                __parserAutoPCState.npc(NRIP);
xc->pcState(__parserAutoPCState);
;
            }
            return fault;
        }

        Fault WripFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t NRIP = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
uint64_t CSBase = 0;
TheISA::PCState __parserAutoPCState;
;
            __parserAutoPCState = xc->pcState();
SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
NRIP = __parserAutoPCState.npc();
ccFlagBits = xc->readCCRegOperand(this, 2);
cfofBits = xc->readCCRegOperand(this, 3);
dfBit = xc->readCCRegOperand(this, 4);
ecfBit = xc->readCCRegOperand(this, 5);
ezfBit = xc->readCCRegOperand(this, 6);
CSBase = xc->readMiscRegOperand(this, 7);
;

            IntReg result M5_VAR_USED;

            if(checkCondition(ccFlagBits | cfofBits | dfBit | ecfBit |                                      ezfBit, ext))
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
int64_t spsrc2 = signedPick(SrcReg2, 1, dataSize);
NRIP = psrc1 + spsrc2 + CSBase;;
                ;
            }
            else
            {
                NRIP = NRIP;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                __parserAutoPCState.npc(NRIP);
xc->pcState(__parserAutoPCState);
;
            }
            return fault;
        }

        Fault WripImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t NRIP = 0;
uint64_t CSBase = 0;
TheISA::PCState __parserAutoPCState;
;
            __parserAutoPCState = xc->pcState();
SrcReg1 = xc->readIntRegOperand(this, 0);
NRIP = __parserAutoPCState.npc();
CSBase = xc->readMiscRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
int8_t simm8 = imm8;
NRIP = psrc1 + simm8 + CSBase;;
                ;
            }
            else
            {
                NRIP = NRIP;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                __parserAutoPCState.npc(NRIP);
xc->pcState(__parserAutoPCState);
;
            }
            return fault;
        }

        Fault WripFlagsImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t NRIP = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
uint64_t CSBase = 0;
TheISA::PCState __parserAutoPCState;
;
            __parserAutoPCState = xc->pcState();
SrcReg1 = xc->readIntRegOperand(this, 0);
NRIP = __parserAutoPCState.npc();
ccFlagBits = xc->readCCRegOperand(this, 1);
cfofBits = xc->readCCRegOperand(this, 2);
dfBit = xc->readCCRegOperand(this, 3);
ecfBit = xc->readCCRegOperand(this, 4);
ezfBit = xc->readCCRegOperand(this, 5);
CSBase = xc->readMiscRegOperand(this, 6);
;

            IntReg result M5_VAR_USED;

            if(checkCondition(ccFlagBits | cfofBits | dfBit | ecfBit |                                      ezfBit, ext))
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
int8_t simm8 = imm8;
NRIP = psrc1 + simm8 + CSBase;;
                ;
            }
            else
            {
                NRIP = NRIP;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                __parserAutoPCState.npc(NRIP);
xc->pcState(__parserAutoPCState);
;
            }
            return fault;
        }

        Fault Wruflags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            uint64_t newFlags = psrc1 ^ psrc2;
            cfofBits = newFlags & cfofMask;
            ecfBit = newFlags & ECFBit;
            ezfBit = newFlags & EZFBit;
            dfBit = newFlags & DFBit;
            ccFlagBits = newFlags & ccFlagMask;
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = ccFlagBits;
            xc->setCCRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = cfofBits;
            xc->setCCRegOperand(this, 1, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = dfBit;
            xc->setCCRegOperand(this, 2, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = ecfBit;
            xc->setCCRegOperand(this, 3, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = ezfBit;
            xc->setCCRegOperand(this, 4, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault WruflagsImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            uint64_t newFlags = psrc1 ^ imm8;
            cfofBits = newFlags & cfofMask;
            ecfBit = newFlags & ECFBit;
            ezfBit = newFlags & EZFBit;
            dfBit = newFlags & DFBit;
            ccFlagBits = newFlags & ccFlagMask;
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = ccFlagBits;
            xc->setCCRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = cfofBits;
            xc->setCCRegOperand(this, 1, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = dfBit;
            xc->setCCRegOperand(this, 2, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = ecfBit;
            xc->setCCRegOperand(this, 3, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = ezfBit;
            xc->setCCRegOperand(this, 4, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Wrflags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
uint64_t nccFlagBits = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            MiscReg newFlags = psrc1 ^ psrc2;
            MiscReg userFlagMask = 0xDD5;
            // Get only the user flags
            ccFlagBits = newFlags & ccFlagMask;
            dfBit = newFlags & DFBit;
            cfofBits = newFlags & cfofMask;
            ecfBit = 0;
            ezfBit = 0;
            // Get everything else
            nccFlagBits = newFlags & ~userFlagMask;
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = ccFlagBits;
            xc->setCCRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = cfofBits;
            xc->setCCRegOperand(this, 1, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = dfBit;
            xc->setCCRegOperand(this, 2, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = ecfBit;
            xc->setCCRegOperand(this, 3, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = ezfBit;
            xc->setCCRegOperand(this, 4, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 5, nccFlagBits);
if (traceData) { traceData->setData(nccFlagBits); };
            }
            return fault;
        }

        Fault WrflagsImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
uint64_t nccFlagBits = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            MiscReg newFlags = psrc1 ^ imm8;
            MiscReg userFlagMask = 0xDD5;
            // Get only the user flags
            ccFlagBits = newFlags & ccFlagMask;
            dfBit = newFlags & DFBit;
            cfofBits = newFlags & cfofMask;
            ecfBit = 0;
            ezfBit = 0;
            // Get everything else
            nccFlagBits = newFlags & ~userFlagMask;
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = ccFlagBits;
            xc->setCCRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = cfofBits;
            xc->setCCRegOperand(this, 1, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = dfBit;
            xc->setCCRegOperand(this, 2, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = ecfBit;
            xc->setCCRegOperand(this, 3, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = ezfBit;
            xc->setCCRegOperand(this, 4, final_val);

            if (traceData) { traceData->setData(final_val); }
        }xc->setMiscRegOperand(this, 5, nccFlagBits);
if (traceData) { traceData->setData(nccFlagBits); };
            }
            return fault;
        }

        Fault Rdip::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t NRIP = 0;
uint64_t CSBase = 0;
TheISA::PCState __parserAutoPCState;
;
            __parserAutoPCState = xc->pcState();
NRIP = __parserAutoPCState.npc();
CSBase = xc->readMiscRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                DestReg = NRIP - CSBase;;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Ruflags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
;
            ccFlagBits = xc->readCCRegOperand(this, 0);
cfofBits = xc->readCCRegOperand(this, 1);
dfBit = xc->readCCRegOperand(this, 2);
ecfBit = xc->readCCRegOperand(this, 3);
ezfBit = xc->readCCRegOperand(this, 4);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                DestReg = ccFlagBits | cfofBits | dfBit | ecfBit | ezfBit;;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Rflags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
uint64_t nccFlagBits = 0;
;
            ccFlagBits = xc->readCCRegOperand(this, 0);
cfofBits = xc->readCCRegOperand(this, 1);
dfBit = xc->readCCRegOperand(this, 2);
ecfBit = xc->readCCRegOperand(this, 3);
ezfBit = xc->readCCRegOperand(this, 4);
nccFlagBits = xc->readMiscRegOperand(this, 5);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                
            DestReg = ccFlagBits | cfofBits | dfBit |
                      ecfBit | ezfBit | nccFlagBits;
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Ruflag::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t DestReg = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
;
            DestReg = xc->readIntRegOperand(this, 0);
ccFlagBits = xc->readCCRegOperand(this, 1);
cfofBits = xc->readCCRegOperand(this, 2);
dfBit = xc->readCCRegOperand(this, 3);
ecfBit = xc->readCCRegOperand(this, 4);
ezfBit = xc->readCCRegOperand(this, 5);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                
            int flag = bits(ccFlagBits | cfofBits | dfBit |
                            ecfBit | ezfBit, imm8);
            DestReg = merge(DestReg, flag, dataSize);
            ezfBit = (flag == 0) ? EZFBit : 0;
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = ezfBit;
            xc->setCCRegOperand(this, 1, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault RuflagBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t DestReg = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
;
            ccFlagBits = xc->readCCRegOperand(this, 0);
cfofBits = xc->readCCRegOperand(this, 1);
dfBit = xc->readCCRegOperand(this, 2);
ecfBit = xc->readCCRegOperand(this, 3);
ezfBit = xc->readCCRegOperand(this, 4);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                
            int flag = bits(ccFlagBits | cfofBits | dfBit |
                            ecfBit | ezfBit, imm8);
            DestReg = flag & mask(dataSize * 8);
            ezfBit = (flag == 0) ? EZFBit : 0;
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = ezfBit;
            xc->setCCRegOperand(this, 1, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Rflag::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t DestReg = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
uint64_t nccFlagBits = 0;
;
            DestReg = xc->readIntRegOperand(this, 0);
ccFlagBits = xc->readCCRegOperand(this, 1);
cfofBits = xc->readCCRegOperand(this, 2);
dfBit = xc->readCCRegOperand(this, 3);
ecfBit = xc->readCCRegOperand(this, 4);
ezfBit = xc->readCCRegOperand(this, 5);
nccFlagBits = xc->readMiscRegOperand(this, 6);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                
            MiscReg flagMask = 0x3F7FDD5;
            MiscReg flags = (nccFlagBits | ccFlagBits | cfofBits | dfBit |
                             ecfBit | ezfBit) & flagMask;
            int flag = bits(flags, imm8);
            DestReg = merge(DestReg, flag, dataSize);
            ezfBit = (flag == 0) ? EZFBit : 0;
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = ezfBit;
            xc->setCCRegOperand(this, 1, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault RflagBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t DestReg = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
uint64_t nccFlagBits = 0;
;
            ccFlagBits = xc->readCCRegOperand(this, 0);
cfofBits = xc->readCCRegOperand(this, 1);
dfBit = xc->readCCRegOperand(this, 2);
ecfBit = xc->readCCRegOperand(this, 3);
ezfBit = xc->readCCRegOperand(this, 4);
nccFlagBits = xc->readMiscRegOperand(this, 5);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                
            MiscReg flagMask = 0x3F7FDD5;
            MiscReg flags = (nccFlagBits | ccFlagBits | cfofBits | dfBit |
                             ecfBit | ezfBit) & flagMask;
            int flag = bits(flags, imm8);
            DestReg = flag & mask(dataSize * 8);
            ezfBit = (flag == 0) ? EZFBit : 0;
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = ezfBit;
            xc->setCCRegOperand(this, 1, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Sext::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
DestReg = xc->readIntRegOperand(this, 2);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            IntReg val = psrc1;
            // Mask the bit position so that it wraps.
            int bitPos = psrc2 & (dataSize * 8 - 1);
            int sign_bit = bits(val, bitPos, bitPos);
            uint64_t maskVal = mask(bitPos+1);
            val = sign_bit ? (val | ~maskVal) : (val & maskVal);
            DestReg = merge(DestReg, val, dataSize);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SextBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            IntReg val = psrc1;
            // Mask the bit position so that it wraps.
            int bitPos = psrc2 & (dataSize * 8 - 1);
            int sign_bit = bits(val, bitPos, bitPos);
            uint64_t maskVal = mask(bitPos+1);
            val = sign_bit ? (val | ~maskVal) : (val & maskVal);
            DestReg = val & mask(dataSize * 8);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SextFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            IntReg val = psrc1;
            // Mask the bit position so that it wraps.
            int bitPos = psrc2 & (dataSize * 8 - 1);
            int sign_bit = bits(val, bitPos, bitPos);
            uint64_t maskVal = mask(bitPos+1);
            val = sign_bit ? (val | ~maskVal) : (val & maskVal);
            DestReg = merge(DestReg, val, dataSize);
            ;
                
            if (!sign_bit) {
                PredccFlagBits = PredccFlagBits & ~(ext & (ZFBit));
                PredcfofBits = PredcfofBits & ~(ext & (CFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                PredezfBit = PredezfBit & ~(ext & EZFBit);
            } else {
                PredccFlagBits = PredccFlagBits | (ext & (ZFBit));
                PredcfofBits = PredcfofBits | (ext & (CFBit));
                PredecfBit = PredecfBit | (ext & ECFBit);
                PredezfBit = PredezfBit | (ext & EZFBit);
            }
            ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SextFlagsBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
SrcReg2 = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);

            IntReg val = psrc1;
            // Mask the bit position so that it wraps.
            int bitPos = psrc2 & (dataSize * 8 - 1);
            int sign_bit = bits(val, bitPos, bitPos);
            uint64_t maskVal = mask(bitPos+1);
            val = sign_bit ? (val | ~maskVal) : (val & maskVal);
            DestReg = val & mask(dataSize * 8);
            ;
                
            if (!sign_bit) {
                PredccFlagBits = PredccFlagBits & ~(ext & (ZFBit));
                PredcfofBits = PredcfofBits & ~(ext & (CFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                PredezfBit = PredezfBit & ~(ext & EZFBit);
            } else {
                PredccFlagBits = PredccFlagBits | (ext & (ZFBit));
                PredcfofBits = PredcfofBits | (ext & (CFBit));
                PredecfBit = PredecfBit | (ext & ECFBit);
                PredezfBit = PredezfBit | (ext & EZFBit);
            }
            ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SextImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
DestReg = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            IntReg val = psrc1;
            // Mask the bit position so that it wraps.
            int bitPos = imm8 & (dataSize * 8 - 1);
            int sign_bit = bits(val, bitPos, bitPos);
            uint64_t maskVal = mask(bitPos+1);
            val = sign_bit ? (val | ~maskVal) : (val & maskVal);
            DestReg = merge(DestReg, val, dataSize);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SextImmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            IntReg val = psrc1;
            // Mask the bit position so that it wraps.
            int bitPos = imm8 & (dataSize * 8 - 1);
            int sign_bit = bits(val, bitPos, bitPos);
            uint64_t maskVal = mask(bitPos+1);
            val = sign_bit ? (val | ~maskVal) : (val & maskVal);
            DestReg = val & mask(dataSize * 8);
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SextFlagsImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            IntReg val = psrc1;
            // Mask the bit position so that it wraps.
            int bitPos = imm8 & (dataSize * 8 - 1);
            int sign_bit = bits(val, bitPos, bitPos);
            uint64_t maskVal = mask(bitPos+1);
            val = sign_bit ? (val | ~maskVal) : (val & maskVal);
            DestReg = merge(DestReg, val, dataSize);
            ;
                
            if (!sign_bit) {
                PredccFlagBits = PredccFlagBits & ~(ext & (ZFBit));
                PredcfofBits = PredcfofBits & ~(ext & (CFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                PredezfBit = PredezfBit & ~(ext & EZFBit);
            } else {
                PredccFlagBits = PredccFlagBits | (ext & (ZFBit));
                PredcfofBits = PredcfofBits | (ext & (CFBit));
                PredecfBit = PredecfBit | (ext & ECFBit);
                PredezfBit = PredezfBit | (ext & EZFBit);
            }
            ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault SextFlagsImmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredcfofBits = 0;
uint64_t PredecfBit = 0;
uint64_t PredezfBit = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredcfofBits = ((((ext & CFBit) == 0 ||
                (ext & OFBit) == 0) && ((ext & (CFBit | OFBit)) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredecfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            IntReg val = psrc1;
            // Mask the bit position so that it wraps.
            int bitPos = imm8 & (dataSize * 8 - 1);
            int sign_bit = bits(val, bitPos, bitPos);
            uint64_t maskVal = mask(bitPos+1);
            val = sign_bit ? (val | ~maskVal) : (val & maskVal);
            DestReg = val & mask(dataSize * 8);
            ;
                
            if (!sign_bit) {
                PredccFlagBits = PredccFlagBits & ~(ext & (ZFBit));
                PredcfofBits = PredcfofBits & ~(ext & (CFBit));
                PredecfBit = PredecfBit & ~(ext & ECFBit);
                PredezfBit = PredezfBit & ~(ext & EZFBit);
            } else {
                PredccFlagBits = PredccFlagBits | (ext & (ZFBit));
                PredcfofBits = PredcfofBits | (ext & (CFBit));
                PredecfBit = PredecfBit | (ext & ECFBit);
                PredezfBit = PredezfBit | (ext & EZFBit);
            }
            ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (true)
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & (CFBit | OFBit)) != 0))
        {
            uint64_t final_val = PredcfofBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & ECFBit) != 0))
        {
            uint64_t final_val = PredecfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Zext::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
DestReg = xc->readIntRegOperand(this, 2);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);
DestReg = merge(DestReg, bits(psrc1, psrc2, 0), dataSize);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault ZextBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
uint64_t psrc2 = pick(SrcReg2, 1, dataSize);
DestReg = bits(psrc1, psrc2, 0) & mask(dataSize * 8);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault ZextImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
DestReg = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
DestReg = merge(DestReg, bits(psrc1, imm8, 0), dataSize);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault ZextImmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);
DestReg = bits(psrc1, imm8, 0) & mask(dataSize * 8);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Rddr::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t DebugSrc1 = 0;
uint64_t CR4Op = 0;
uint64_t DR7Op = 0;
;
            DestReg = xc->readIntRegOperand(this, 0);
DebugSrc1 = xc->readMiscRegOperand(this, 1);
CR4Op = xc->readMiscRegOperand(this, 2);
DR7Op = xc->readMiscRegOperand(this, 3);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                
            CR4 cr4 = CR4Op;
            DR7 dr7 = DR7Op;
            if ((cr4.de == 1 && (src1 == 4 || src1 == 5)) || src1 >= 8) {
                fault = std::make_shared<InvalidOpcode>();
            } else if (dr7.gd) {
                fault = std::make_shared<DebugException>();
            } else {
                DestReg = merge(DestReg, DebugSrc1, dataSize);
            }
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault RddrBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t DebugSrc1 = 0;
uint64_t CR4Op = 0;
uint64_t DR7Op = 0;
;
            DebugSrc1 = xc->readMiscRegOperand(this, 0);
CR4Op = xc->readMiscRegOperand(this, 1);
DR7Op = xc->readMiscRegOperand(this, 2);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                
            CR4 cr4 = CR4Op;
            DR7 dr7 = DR7Op;
            if ((cr4.de == 1 && (src1 == 4 || src1 == 5)) || src1 >= 8) {
                fault = std::make_shared<InvalidOpcode>();
            } else if (dr7.gd) {
                fault = std::make_shared<DebugException>();
            } else {
                DestReg = DebugSrc1 & mask(dataSize * 8);
            }
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Wrdr::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t DebugDest = 0;
uint64_t CR4Op = 0;
uint64_t DR7Op = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
CR4Op = xc->readMiscRegOperand(this, 1);
DR7Op = xc->readMiscRegOperand(this, 2);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            CR4 cr4 = CR4Op;
            DR7 dr7 = DR7Op;
            if ((cr4.de == 1 && (dest == 4 || dest == 5)) || dest >= 8) {
                fault = std::make_shared<InvalidOpcode>();
            } else if ((dest == 6 || dest == 7) && bits(psrc1, 63, 32) &&
                    machInst.mode.mode == LongMode) {
                fault = std::make_shared<GeneralProtection>(0);
            } else if (dr7.gd) {
                fault = std::make_shared<DebugException>();
            } else {
                DebugDest = psrc1;
            }
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                xc->setMiscRegOperand(this, 0, DebugDest);
if (traceData) { traceData->setData(DebugDest); };
            }
            return fault;
        }

        Fault Rdcr::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t ControlSrc1 = 0;
;
            DestReg = xc->readIntRegOperand(this, 0);
ControlSrc1 = xc->readMiscRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                
            if (src1 == 1 || (src1 > 4 && src1 < 8) || (src1 > 8)) {
                fault = std::make_shared<InvalidOpcode>();
            } else {
                DestReg = merge(DestReg, ControlSrc1, dataSize);
            }
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault RdcrBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t ControlSrc1 = 0;
;
            ControlSrc1 = xc->readMiscRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                
            if (src1 == 1 || (src1 > 4 && src1 < 8) || (src1 > 8)) {
                fault = std::make_shared<InvalidOpcode>();
            } else {
                DestReg = ControlSrc1 & mask(dataSize * 8);
            }
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Wrcr::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t ControlDest = 0;
uint64_t EferOp = 0;
uint64_t CR4Op = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
EferOp = xc->readMiscRegOperand(this, 1);
CR4Op = xc->readMiscRegOperand(this, 2);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            if (dest == 1 || (dest > 4 && dest < 8) || (dest > 8)) {
                fault = std::make_shared<InvalidOpcode>();
            } else {
                // There are *s in the line below so it doesn't confuse the
                // parser. They may be unnecessary.
                //Mis*cReg old*Val = pick(Cont*rolDest, 0, dat*aSize);
                MiscReg newVal = psrc1;
                // Check for any modifications that would cause a fault.
                switch(dest) {
                  case 0:
                    {
                        Efer efer = EferOp;
                        CR0 cr0 = newVal;
                        CR4 oldCr4 = CR4Op;
                        if (bits(newVal, 63, 32) ||
                                (!cr0.pe && cr0.pg) ||
                                (!cr0.cd && cr0.nw) ||
                                (cr0.pg && efer.lme && !oldCr4.pae))
                            fault = std::make_shared<GeneralProtection>(0);
                    }
                    break;
                  case 2:
                    break;
                  case 3:
                    break;
                  case 4:
                    {
                        CR4 cr4 = newVal;
                        // PAE can't be disabled in long mode.
                        if (bits(newVal, 63, 11) ||
                                (machInst.mode.mode == LongMode && !cr4.pae))
                            fault = std::make_shared<GeneralProtection>(0);
                    }
                    break;
                  case 8:
                    {
                        if (bits(newVal, 63, 4))
                            fault = std::make_shared<GeneralProtection>(0);
                    }
                  default:
                    fault = std::make_shared<GenericISA::M5PanicFault>(
                            "Unrecognized control register %d.\n", dest);
                }
                ControlDest = newVal;
            }
            ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                xc->setMiscRegOperand(this, 0, ControlDest);
if (traceData) { traceData->setData(ControlDest); };
            }
            return fault;
        }

        Fault Wrbase::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SegBaseDest = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            SegBaseDest = psrc1;
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                xc->setMiscRegOperand(this, 0, SegBaseDest);
if (traceData) { traceData->setData(SegBaseDest); };
            }
            return fault;
        }

        Fault WrbaseFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
uint64_t SegBaseDest = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
ccFlagBits = xc->readCCRegOperand(this, 1);
cfofBits = xc->readCCRegOperand(this, 2);
dfBit = xc->readCCRegOperand(this, 3);
ecfBit = xc->readCCRegOperand(this, 4);
ezfBit = xc->readCCRegOperand(this, 5);
;

            IntReg result M5_VAR_USED;

            if(checkCondition(ccFlagBits | cfofBits | dfBit | ecfBit |                                      ezfBit, ext))
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            SegBaseDest = psrc1;
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                xc->setMiscRegOperand(this, 0, SegBaseDest);
if (traceData) { traceData->setData(SegBaseDest); };
            }
            return fault;
        }

        Fault Wrlimit::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SegLimitDest = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            SegLimitDest = psrc1;
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                xc->setMiscRegOperand(this, 0, SegLimitDest);
if (traceData) { traceData->setData(SegLimitDest); };
            }
            return fault;
        }

        Fault WrlimitFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
uint64_t SegLimitDest = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
ccFlagBits = xc->readCCRegOperand(this, 1);
cfofBits = xc->readCCRegOperand(this, 2);
dfBit = xc->readCCRegOperand(this, 3);
ecfBit = xc->readCCRegOperand(this, 4);
ezfBit = xc->readCCRegOperand(this, 5);
;

            IntReg result M5_VAR_USED;

            if(checkCondition(ccFlagBits | cfofBits | dfBit | ecfBit |                                      ezfBit, ext))
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            SegLimitDest = psrc1;
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                xc->setMiscRegOperand(this, 0, SegLimitDest);
if (traceData) { traceData->setData(SegLimitDest); };
            }
            return fault;
        }

        Fault Wrsel::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SegSelDest = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            SegSelDest = psrc1;
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                xc->setMiscRegOperand(this, 0, SegSelDest);
if (traceData) { traceData->setData(SegSelDest); };
            }
            return fault;
        }

        Fault WrselFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
uint64_t SegSelDest = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
ccFlagBits = xc->readCCRegOperand(this, 1);
cfofBits = xc->readCCRegOperand(this, 2);
dfBit = xc->readCCRegOperand(this, 3);
ecfBit = xc->readCCRegOperand(this, 4);
ezfBit = xc->readCCRegOperand(this, 5);
;

            IntReg result M5_VAR_USED;

            if(checkCondition(ccFlagBits | cfofBits | dfBit | ecfBit |                                      ezfBit, ext))
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            SegSelDest = psrc1;
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                xc->setMiscRegOperand(this, 0, SegSelDest);
if (traceData) { traceData->setData(SegSelDest); };
            }
            return fault;
        }

        Fault WrAttr::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SegAttrDest = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            SegAttrDest = psrc1;
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                xc->setMiscRegOperand(this, 0, SegAttrDest);
if (traceData) { traceData->setData(SegAttrDest); };
            }
            return fault;
        }

        Fault WrAttrFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
uint64_t SegAttrDest = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
ccFlagBits = xc->readCCRegOperand(this, 1);
cfofBits = xc->readCCRegOperand(this, 2);
dfBit = xc->readCCRegOperand(this, 3);
ecfBit = xc->readCCRegOperand(this, 4);
ezfBit = xc->readCCRegOperand(this, 5);
;

            IntReg result M5_VAR_USED;

            if(checkCondition(ccFlagBits | cfofBits | dfBit | ecfBit |                                      ezfBit, ext))
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            SegAttrDest = psrc1;
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                xc->setMiscRegOperand(this, 0, SegAttrDest);
if (traceData) { traceData->setData(SegAttrDest); };
            }
            return fault;
        }

        Fault Rdbase::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t SegBaseSrc1 = 0;
;
            DestReg = xc->readIntRegOperand(this, 0);
SegBaseSrc1 = xc->readMiscRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                DestReg = merge(DestReg, SegBaseSrc1, dataSize);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault RdbaseBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t SegBaseSrc1 = 0;
;
            SegBaseSrc1 = xc->readMiscRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                DestReg = SegBaseSrc1 & mask(dataSize * 8);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault RdbaseFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
uint64_t SegBaseSrc1 = 0;
;
            DestReg = xc->readIntRegOperand(this, 0);
ccFlagBits = xc->readCCRegOperand(this, 1);
cfofBits = xc->readCCRegOperand(this, 2);
dfBit = xc->readCCRegOperand(this, 3);
ecfBit = xc->readCCRegOperand(this, 4);
ezfBit = xc->readCCRegOperand(this, 5);
SegBaseSrc1 = xc->readMiscRegOperand(this, 6);
;

            IntReg result M5_VAR_USED;

            if(checkCondition(ccFlagBits | cfofBits | dfBit | ecfBit |                                      ezfBit, ext))
            {
                DestReg = merge(DestReg, SegBaseSrc1, dataSize);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault RdbaseFlagsBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
uint64_t SegBaseSrc1 = 0;
;
            ccFlagBits = xc->readCCRegOperand(this, 0);
cfofBits = xc->readCCRegOperand(this, 1);
dfBit = xc->readCCRegOperand(this, 2);
ecfBit = xc->readCCRegOperand(this, 3);
ezfBit = xc->readCCRegOperand(this, 4);
SegBaseSrc1 = xc->readMiscRegOperand(this, 5);
;

            IntReg result M5_VAR_USED;

            if(checkCondition(ccFlagBits | cfofBits | dfBit | ecfBit |                                      ezfBit, ext))
            {
                DestReg = SegBaseSrc1 & mask(dataSize * 8);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Rdlimit::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t SegLimitSrc1 = 0;
;
            DestReg = xc->readIntRegOperand(this, 0);
SegLimitSrc1 = xc->readMiscRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                DestReg = merge(DestReg, SegLimitSrc1, dataSize);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault RdlimitBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t SegLimitSrc1 = 0;
;
            SegLimitSrc1 = xc->readMiscRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                DestReg = SegLimitSrc1 & mask(dataSize * 8);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault RdlimitFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
uint64_t SegLimitSrc1 = 0;
;
            DestReg = xc->readIntRegOperand(this, 0);
ccFlagBits = xc->readCCRegOperand(this, 1);
cfofBits = xc->readCCRegOperand(this, 2);
dfBit = xc->readCCRegOperand(this, 3);
ecfBit = xc->readCCRegOperand(this, 4);
ezfBit = xc->readCCRegOperand(this, 5);
SegLimitSrc1 = xc->readMiscRegOperand(this, 6);
;

            IntReg result M5_VAR_USED;

            if(checkCondition(ccFlagBits | cfofBits | dfBit | ecfBit |                                      ezfBit, ext))
            {
                DestReg = merge(DestReg, SegLimitSrc1, dataSize);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault RdlimitFlagsBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
uint64_t SegLimitSrc1 = 0;
;
            ccFlagBits = xc->readCCRegOperand(this, 0);
cfofBits = xc->readCCRegOperand(this, 1);
dfBit = xc->readCCRegOperand(this, 2);
ecfBit = xc->readCCRegOperand(this, 3);
ezfBit = xc->readCCRegOperand(this, 4);
SegLimitSrc1 = xc->readMiscRegOperand(this, 5);
;

            IntReg result M5_VAR_USED;

            if(checkCondition(ccFlagBits | cfofBits | dfBit | ecfBit |                                      ezfBit, ext))
            {
                DestReg = SegLimitSrc1 & mask(dataSize * 8);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault RdAttr::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t SegAttrSrc1 = 0;
;
            DestReg = xc->readIntRegOperand(this, 0);
SegAttrSrc1 = xc->readMiscRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                DestReg = merge(DestReg, SegAttrSrc1, dataSize);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault RdAttrBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t SegAttrSrc1 = 0;
;
            SegAttrSrc1 = xc->readMiscRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                DestReg = SegAttrSrc1 & mask(dataSize * 8);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault RdAttrFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
uint64_t SegAttrSrc1 = 0;
;
            DestReg = xc->readIntRegOperand(this, 0);
ccFlagBits = xc->readCCRegOperand(this, 1);
cfofBits = xc->readCCRegOperand(this, 2);
dfBit = xc->readCCRegOperand(this, 3);
ecfBit = xc->readCCRegOperand(this, 4);
ezfBit = xc->readCCRegOperand(this, 5);
SegAttrSrc1 = xc->readMiscRegOperand(this, 6);
;

            IntReg result M5_VAR_USED;

            if(checkCondition(ccFlagBits | cfofBits | dfBit | ecfBit |                                      ezfBit, ext))
            {
                DestReg = merge(DestReg, SegAttrSrc1, dataSize);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault RdAttrFlagsBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
uint64_t SegAttrSrc1 = 0;
;
            ccFlagBits = xc->readCCRegOperand(this, 0);
cfofBits = xc->readCCRegOperand(this, 1);
dfBit = xc->readCCRegOperand(this, 2);
ecfBit = xc->readCCRegOperand(this, 3);
ezfBit = xc->readCCRegOperand(this, 4);
SegAttrSrc1 = xc->readMiscRegOperand(this, 5);
;

            IntReg result M5_VAR_USED;

            if(checkCondition(ccFlagBits | cfofBits | dfBit | ecfBit |                                      ezfBit, ext))
            {
                DestReg = SegAttrSrc1 & mask(dataSize * 8);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Rdsel::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t SegSelSrc1 = 0;
;
            DestReg = xc->readIntRegOperand(this, 0);
SegSelSrc1 = xc->readMiscRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                DestReg = merge(DestReg, SegSelSrc1, dataSize);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault RdselBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t SegSelSrc1 = 0;
;
            SegSelSrc1 = xc->readMiscRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                DestReg = SegSelSrc1 & mask(dataSize * 8);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault RdselFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
uint64_t SegSelSrc1 = 0;
;
            DestReg = xc->readIntRegOperand(this, 0);
ccFlagBits = xc->readCCRegOperand(this, 1);
cfofBits = xc->readCCRegOperand(this, 2);
dfBit = xc->readCCRegOperand(this, 3);
ecfBit = xc->readCCRegOperand(this, 4);
ezfBit = xc->readCCRegOperand(this, 5);
SegSelSrc1 = xc->readMiscRegOperand(this, 6);
;

            IntReg result M5_VAR_USED;

            if(checkCondition(ccFlagBits | cfofBits | dfBit | ecfBit |                                      ezfBit, ext))
            {
                DestReg = merge(DestReg, SegSelSrc1, dataSize);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault RdselFlagsBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
uint64_t SegSelSrc1 = 0;
;
            ccFlagBits = xc->readCCRegOperand(this, 0);
cfofBits = xc->readCCRegOperand(this, 1);
dfBit = xc->readCCRegOperand(this, 2);
ecfBit = xc->readCCRegOperand(this, 3);
ezfBit = xc->readCCRegOperand(this, 4);
SegSelSrc1 = xc->readMiscRegOperand(this, 5);
;

            IntReg result M5_VAR_USED;

            if(checkCondition(ccFlagBits | cfofBits | dfBit | ecfBit |                                      ezfBit, ext))
            {
                DestReg = SegSelSrc1 & mask(dataSize * 8);;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Rdval::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t MiscRegSrc1 = 0;
;
            MiscRegSrc1 = xc->readMiscRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                
            DestReg = MiscRegSrc1;
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Wrval::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t MiscRegDest = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                
            MiscRegDest = SrcReg1;
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                xc->setMiscRegOperand(this, 0, MiscRegDest);
if (traceData) { traceData->setData(MiscRegDest); };
            }
            return fault;
        }

        Fault Chks::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t M5Reg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
DestReg = xc->readIntRegOperand(this, 1);
M5Reg = xc->readMiscRegOperand(this, 2);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                
            // The selector is in source 1 and can be at most 16 bits.
            SegSelector selector = DestReg;
            SegDescriptor desc = SrcReg1;
            HandyM5Reg m5reg = M5Reg;
            switch (imm8)
            {
              case SegNoCheck:
                break;
              case SegCSCheck:
                // Make sure it's the right type
                if (desc.s == 0 || desc.type.codeOrData != 1) {
                    fault = std::make_shared<GeneralProtection>(0);
                } else if (m5reg.cpl != desc.dpl) {
                    fault = std::make_shared<GeneralProtection>(0);
                }
                break;
              case SegCallGateCheck:
                fault = std::make_shared<GenericISA::M5PanicFault>(
                        "CS checks for far "
                        "calls/jumps through call gates not implemented.\n");
                break;
              case SegSoftIntGateCheck:
                // Check permissions.
                if (desc.dpl < m5reg.cpl) {
                    fault = std::make_shared<GeneralProtection>(selector);
                    break;
                }
                // Fall through on purpose
              case SegIntGateCheck:
                // Make sure the gate's the right type.
                if ((m5reg.mode == LongMode && (desc.type & 0xe) != 0xe) ||
                        ((desc.type & 0x6) != 0x6)) {
                    fault = std::make_shared<GeneralProtection>(0);
                }
                break;
              case SegSSCheck:
                if (selector.si || selector.ti) {
                    if (!desc.p) {
                        fault = std::make_shared<StackFault>(selector);
                    } else if (!(desc.s == 1 && desc.type.codeOrData == 0 &&
                                desc.type.w) ||
                            (desc.dpl != m5reg.cpl) ||
                            (selector.rpl != m5reg.cpl)) {
                        fault = std::make_shared<GeneralProtection>(selector);
                    }
                } else if (m5reg.submode != SixtyFourBitMode ||
                        m5reg.cpl == 3) {
                    fault = std::make_shared<GeneralProtection>(selector);
                }
                break;
              case SegIretCheck:
                {
                    if ((!selector.si && !selector.ti) ||
                            (selector.rpl < m5reg.cpl) ||
                            !(desc.s == 1 && desc.type.codeOrData == 1) ||
                            (!desc.type.c && desc.dpl != selector.rpl) ||
                            (desc.type.c && desc.dpl > selector.rpl)) {
                        fault = std::make_shared<GeneralProtection>(selector);
                    } else if (!desc.p) {
                        fault = std::make_shared<SegmentNotPresent>(selector);
                    }
                    break;
                }
              case SegIntCSCheck:
                if (m5reg.mode == LongMode) {
                    if (desc.l != 1 || desc.d != 0) {
                        fault = std::make_shared<GeneralProtection>(selector);
                    }
                } else {
                    fault = std::make_shared<GenericISA::M5PanicFault>(
                            "Interrupt CS "
                            "checks not implemented in legacy mode.\n");
                }
                break;
              case SegTRCheck:
                if (!selector.si || selector.ti) {
                    fault = std::make_shared<GeneralProtection>(selector);
                }
                break;
              case SegTSSCheck:
                if (!desc.p) {
                    fault = std::make_shared<SegmentNotPresent>(selector);
                } else if (!(desc.type == 0x9 ||
                        (desc.type == 1 &&
                         m5reg.mode != LongMode))) {
                    fault = std::make_shared<GeneralProtection>(selector);
                }
                break;
              case SegInGDTCheck:
                if (selector.ti) {
                    fault = std::make_shared<GeneralProtection>(selector);
                }
                break;
              case SegLDTCheck:
                if (!desc.p) {
                    fault = std::make_shared<SegmentNotPresent>(selector);
                } else if (desc.type != 0x2) {
                    fault = std::make_shared<GeneralProtection>(selector);
                }
                break;
              default:
                fault = std::make_shared<GenericISA::M5PanicFault>(
                        "Undefined segment check type.\n");
            }
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

        Fault ChksFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t DestReg = 0;
uint64_t PredccFlagBits = 0;
uint64_t PredezfBit = 0;
uint64_t M5Reg = 0;
uint8_t _sourceIndex = 0;
uint8_t M5_VAR_USED _destIndex = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, _sourceIndex++);
DestReg = xc->readIntRegOperand(this, _sourceIndex++);
PredccFlagBits = ((((ext & (PFBit | AFBit | ZFBit | SFBit
                )) != (PFBit | AFBit | ZFBit | SFBit )) &&
                ((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
PredezfBit = ((false)) ? xc->readCCRegOperand(this, _sourceIndex++) : 0;
M5Reg = xc->readMiscRegOperand(this, _sourceIndex++);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                
            // The selector is in source 1 and can be at most 16 bits.
            SegSelector selector = DestReg;
            SegDescriptor desc = SrcReg1;
            HandyM5Reg m5reg = M5Reg;
            switch (imm8)
            {
              case SegNoCheck:
                break;
              case SegCSCheck:
                // Make sure it's the right type
                if (desc.s == 0 || desc.type.codeOrData != 1) {
                    fault = std::make_shared<GeneralProtection>(0);
                } else if (m5reg.cpl != desc.dpl) {
                    fault = std::make_shared<GeneralProtection>(0);
                }
                break;
              case SegCallGateCheck:
                fault = std::make_shared<GenericISA::M5PanicFault>(
                        "CS checks for far "
                        "calls/jumps through call gates not implemented.\n");
                break;
              case SegSoftIntGateCheck:
                // Check permissions.
                if (desc.dpl < m5reg.cpl) {
                    fault = std::make_shared<GeneralProtection>(selector);
                    break;
                }
                // Fall through on purpose
              case SegIntGateCheck:
                // Make sure the gate's the right type.
                if ((m5reg.mode == LongMode && (desc.type & 0xe) != 0xe) ||
                        ((desc.type & 0x6) != 0x6)) {
                    fault = std::make_shared<GeneralProtection>(0);
                }
                break;
              case SegSSCheck:
                if (selector.si || selector.ti) {
                    if (!desc.p) {
                        fault = std::make_shared<StackFault>(selector);
                    } else if (!(desc.s == 1 && desc.type.codeOrData == 0 &&
                                desc.type.w) ||
                            (desc.dpl != m5reg.cpl) ||
                            (selector.rpl != m5reg.cpl)) {
                        fault = std::make_shared<GeneralProtection>(selector);
                    }
                } else if (m5reg.submode != SixtyFourBitMode ||
                        m5reg.cpl == 3) {
                    fault = std::make_shared<GeneralProtection>(selector);
                }
                break;
              case SegIretCheck:
                {
                    if ((!selector.si && !selector.ti) ||
                            (selector.rpl < m5reg.cpl) ||
                            !(desc.s == 1 && desc.type.codeOrData == 1) ||
                            (!desc.type.c && desc.dpl != selector.rpl) ||
                            (desc.type.c && desc.dpl > selector.rpl)) {
                        fault = std::make_shared<GeneralProtection>(selector);
                    } else if (!desc.p) {
                        fault = std::make_shared<SegmentNotPresent>(selector);
                    }
                    break;
                }
              case SegIntCSCheck:
                if (m5reg.mode == LongMode) {
                    if (desc.l != 1 || desc.d != 0) {
                        fault = std::make_shared<GeneralProtection>(selector);
                    }
                } else {
                    fault = std::make_shared<GenericISA::M5PanicFault>(
                            "Interrupt CS "
                            "checks not implemented in legacy mode.\n");
                }
                break;
              case SegTRCheck:
                if (!selector.si || selector.ti) {
                    fault = std::make_shared<GeneralProtection>(selector);
                }
                break;
              case SegTSSCheck:
                if (!desc.p) {
                    fault = std::make_shared<SegmentNotPresent>(selector);
                } else if (!(desc.type == 0x9 ||
                        (desc.type == 1 &&
                         m5reg.mode != LongMode))) {
                    fault = std::make_shared<GeneralProtection>(selector);
                }
                break;
              case SegInGDTCheck:
                if (selector.ti) {
                    fault = std::make_shared<GeneralProtection>(selector);
                }
                break;
              case SegLDTCheck:
                if (!desc.p) {
                    fault = std::make_shared<SegmentNotPresent>(selector);
                } else if (desc.type != 0x2) {
                    fault = std::make_shared<GeneralProtection>(selector);
                }
                break;
              default:
                fault = std::make_shared<GenericISA::M5PanicFault>(
                        "Undefined segment check type.\n");
            }
        ;
                
            // Check for a NULL selector and set ZF,EZF appropriately.
            PredccFlagBits = PredccFlagBits & ~(ext & ZFBit);
            PredezfBit = PredezfBit & ~(ext & EZFBit);
            if (!selector.si && !selector.ti) {
                PredccFlagBits = PredccFlagBits | (ext & ZFBit);
                PredezfBit = PredezfBit | (ext & EZFBit);
            }
        ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        if (((ext & (PFBit | AFBit | ZFBit | SFBit )) != 0))
        {
            uint64_t final_val = PredccFlagBits;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        if (((ext & EZFBit) != 0))
        {
            uint64_t final_val = PredezfBit;
            xc->setCCRegOperand(this, _destIndex++, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Wrdh::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t DestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                
            SegDescriptor desc = SrcReg1;
            uint64_t target = bits(SrcReg2, 31, 0) << 32;
            switch(desc.type) {
              case LDT64:
              case AvailableTSS64:
              case BusyTSS64:
                replaceBits(target, 23, 0, desc.baseLow);
                replaceBits(target, 31, 24, desc.baseHigh);
                break;
              case CallGate64:
              case IntGate64:
              case TrapGate64:
                replaceBits(target, 15, 0, bits(desc, 15, 0));
                replaceBits(target, 31, 16, bits(desc, 63, 48));
                break;
              default:
                fault = std::make_shared<GenericISA::M5PanicFault>(
                        "Wrdh used with wrong descriptor type!\n");
            }
            DestReg = target;
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Wrtsc::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t TscOp = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                uint64_t psrc1 = pick(SrcReg1, 0, dataSize);

            TscOp = psrc1;
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                xc->setMiscRegOperand(this, 0, TscOp);
if (traceData) { traceData->setData(TscOp); };
            }
            return fault;
        }

        Fault Rdtsc::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t TscOp = 0;
;
            TscOp = xc->readMiscRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                
            DestReg = TscOp;
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Rdm5reg::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint64_t M5Reg = 0;
;
            M5Reg = xc->readMiscRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                
            DestReg = M5Reg;
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Wrdl::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint64_t SrcReg2 = 0;
uint64_t SegBaseDest = 0;
uint64_t SegLimitDest = 0;
uint64_t SegAttrDest = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
SrcReg2 = xc->readIntRegOperand(this, 1);
SegBaseDest = xc->readMiscRegOperand(this, 2);
SegLimitDest = xc->readMiscRegOperand(this, 3);
SegAttrDest = xc->readMiscRegOperand(this, 4);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                
            SegDescriptor desc = SrcReg1;
            SegSelector selector = SrcReg2;
            // This while loop is so we can use break statements in the code
            // below to skip the rest of this section without a bunch of
            // nesting.
            while (true) {
                if (selector.si || selector.ti) {
                    if (!desc.p) {
                        fault = std::make_shared<GenericISA::M5PanicFault>(
                                "Segment not present.\n");
                        break;
                    }
                    SegAttr attr = 0;
                    attr.dpl = desc.dpl;
                    attr.unusable = 0;
                    attr.defaultSize = desc.d;
                    attr.longMode = desc.l;
                    attr.avl = desc.avl;
                    attr.granularity = desc.g;
                    attr.present = desc.p;
                    attr.system = desc.s;
                    attr.type = desc.type;
                    if (!desc.s) {
                        // The expand down bit happens to be set for gates.
                        if (desc.type.e) {
                            fault = std::make_shared<GenericISA::M5PanicFault>(
                                    "Gate descriptor encountered.\n");
                            break;
                        }
                        attr.readable = 1;
                        attr.writable = 1;
                        attr.expandDown = 0;
                    } else {
                        if (desc.type.codeOrData) {
                            attr.expandDown = 0;
                            attr.readable = desc.type.r;
                            attr.writable = 0;
                        } else {
                            attr.expandDown = desc.type.e;
                            attr.readable = 1;
                            attr.writable = desc.type.w;
                        }
                    }
                    Addr base = desc.baseLow | (desc.baseHigh << 24);
                    Addr limit = desc.limitLow | (desc.limitHigh << 16);
                    if (desc.g)
                        limit = (limit << 12) | mask(12);
                    SegBaseDest = base;
                    SegLimitDest = limit;
                    SegAttrDest = attr;
                } else {
                    SegBaseDest = SegBaseDest;
                    SegLimitDest = SegLimitDest;
                    SegAttrDest = SegAttrDest;
                }
                break;
            }
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                xc->setMiscRegOperand(this, 0, SegBaseDest);
if (traceData) { traceData->setData(SegBaseDest); }xc->setMiscRegOperand(this, 1, SegLimitDest);
if (traceData) { traceData->setData(SegLimitDest); }xc->setMiscRegOperand(this, 2, SegAttrDest);
if (traceData) { traceData->setData(SegAttrDest); };
            }
            return fault;
        }

        Fault Wrxftw::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t SrcReg1 = 0;
uint16_t FTW = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                
            FTW = X86ISA::convX87XTagsToTags(SrcReg1);
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                xc->setMiscRegOperand(this, 0, FTW);
if (traceData) { traceData->setData(FTW); };
            }
            return fault;
        }

        Fault Rdxftw::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            DPRINTF(X86, "The data size is %d\n", dataSize);
            uint64_t DestReg = 0;
uint16_t FTW = 0;
;
            FTW = xc->readMiscRegOperand(this, 0);
;

            IntReg result M5_VAR_USED;

            if(true)
            {
                
            DestReg = X86ISA::convX87TagsToXTags(FTW);
        ;
                ;
            }
            else
            {
                ;;
            }

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Limm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            uint64_t DestReg = 0;
;
            DestReg = xc->readIntRegOperand(this, 0);
;
            DestReg = merge(DestReg, imm, dataSize);;
            
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            return NoFault;
        }

        Fault LimmBig::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            uint64_t DestReg = 0;
;
            ;
            DestReg = imm & mask(dataSize * 8);;
            
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            return NoFault;
        }

        Fault Lfpimm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            uint64_t FpDestReg = 0;
;
            ;
            FpDestReg = imm;
            
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            return NoFault;
        }

    Fault Ld::execute(CPU_EXEC_CONTEXT *xc,
          Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;
        Addr EA;

        uint64_t Index = 0;
uint64_t Base = 0;
uint64_t Data = 0;
uint64_t SegBase = 0;
uint64_t Mem = 0;
;
        Index = xc->readIntRegOperand(this, 0);
Base = xc->readIntRegOperand(this, 1);
Data = xc->readIntRegOperand(this, 2);
SegBase = xc->readMiscRegOperand(this, 3);
;
        
    EA = SegBase + bits(scale * Index + Base + disp, addressSize * 8 - 1, 0);
    ;
        DPRINTF(X86, "%s : %s: The address is %#x\n", instMnem, mnemonic, EA);

        fault = readMemAtomic(xc, traceData, EA, Mem, dataSize, memFlags);

        if (fault == NoFault) {
            Data = merge(Data, Mem, dataSize);;
        } else if (memFlags & Request::PREFETCH) {
            // For prefetches, ignore any faults/exceptions.
            return NoFault;
        }
        if(fault == NoFault)
        {
            
        
        {
            uint64_t final_val = Data;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Ld::initiateAcc(CPU_EXEC_CONTEXT * xc,
            Trace::InstRecord * traceData) const
    {
        Fault fault = NoFault;
        Addr EA;

        uint64_t Index = 0;
uint64_t Base = 0;
uint64_t SegBase = 0;
uint64_t Mem = 0;
;
        Index = xc->readIntRegOperand(this, 0);
Base = xc->readIntRegOperand(this, 1);
SegBase = xc->readMiscRegOperand(this, 3);
;
        
    EA = SegBase + bits(scale * Index + Base + disp, addressSize * 8 - 1, 0);
    ;
        DPRINTF(X86, "%s : %s: The address is %#x\n", instMnem, mnemonic, EA);

        fault = readMemTiming(xc, traceData, EA, Mem, dataSize, memFlags);

        return fault;
    }

    Fault Ld::completeAcc(PacketPtr pkt,
            CPU_EXEC_CONTEXT * xc,
            Trace::InstRecord * traceData) const
    {
        Fault fault = NoFault;

        uint64_t Data = 0;
uint64_t Mem = 0;
;
        Data = xc->readIntRegOperand(this, 2);
;

        Mem = getMem(pkt, dataSize, traceData);

        Data = merge(Data, Mem, dataSize);;

        if(fault == NoFault)
        {
            
        
        {
            uint64_t final_val = Data;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault LdBig::execute(CPU_EXEC_CONTEXT *xc,
          Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;
        Addr EA;

        uint64_t Index = 0;
uint64_t Base = 0;
uint64_t Data = 0;
uint64_t SegBase = 0;
uint64_t Mem = 0;
;
        Index = xc->readIntRegOperand(this, 0);
Base = xc->readIntRegOperand(this, 1);
SegBase = xc->readMiscRegOperand(this, 2);
;
        
    EA = SegBase + bits(scale * Index + Base + disp, addressSize * 8 - 1, 0);
    ;
        DPRINTF(X86, "%s : %s: The address is %#x\n", instMnem, mnemonic, EA);

        fault = readMemAtomic(xc, traceData, EA, Mem, dataSize, memFlags);

        if (fault == NoFault) {
            Data = Mem & mask(dataSize * 8);;
        } else if (memFlags & Request::PREFETCH) {
            // For prefetches, ignore any faults/exceptions.
            return NoFault;
        }
        if(fault == NoFault)
        {
            
        
        {
            uint64_t final_val = Data;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault LdBig::initiateAcc(CPU_EXEC_CONTEXT * xc,
            Trace::InstRecord * traceData) const
    {
        Fault fault = NoFault;
        Addr EA;

        uint64_t Index = 0;
uint64_t Base = 0;
uint64_t SegBase = 0;
uint64_t Mem = 0;
;
        Index = xc->readIntRegOperand(this, 0);
Base = xc->readIntRegOperand(this, 1);
SegBase = xc->readMiscRegOperand(this, 2);
;
        
    EA = SegBase + bits(scale * Index + Base + disp, addressSize * 8 - 1, 0);
    ;
        DPRINTF(X86, "%s : %s: The address is %#x\n", instMnem, mnemonic, EA);

        fault = readMemTiming(xc, traceData, EA, Mem, dataSize, memFlags);

        return fault;
    }

    Fault LdBig::completeAcc(PacketPtr pkt,
            CPU_EXEC_CONTEXT * xc,
            Trace::InstRecord * traceData) const
    {
        Fault fault = NoFault;

        uint64_t Data = 0;
uint64_t Mem = 0;
;
        ;

        Mem = getMem(pkt, dataSize, traceData);

        Data = Mem & mask(dataSize * 8);;

        if(fault == NoFault)
        {
            
        
        {
            uint64_t final_val = Data;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Ldst::execute(CPU_EXEC_CONTEXT *xc,
          Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;
        Addr EA;

        uint64_t Index = 0;
uint64_t Base = 0;
uint64_t Data = 0;
uint64_t SegBase = 0;
uint64_t Mem = 0;
;
        Index = xc->readIntRegOperand(this, 0);
Base = xc->readIntRegOperand(this, 1);
Data = xc->readIntRegOperand(this, 2);
SegBase = xc->readMiscRegOperand(this, 3);
;
        
    EA = SegBase + bits(scale * Index + Base + disp, addressSize * 8 - 1, 0);
    ;
        DPRINTF(X86, "%s : %s: The address is %#x\n", instMnem, mnemonic, EA);

        fault = readMemAtomic(xc, traceData, EA, Mem, dataSize, memFlags);

        if (fault == NoFault) {
            Data = merge(Data, Mem, dataSize);;
        } else if (memFlags & Request::PREFETCH) {
            // For prefetches, ignore any faults/exceptions.
            return NoFault;
        }
        if(fault == NoFault)
        {
            
        
        {
            uint64_t final_val = Data;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Ldst::initiateAcc(CPU_EXEC_CONTEXT * xc,
            Trace::InstRecord * traceData) const
    {
        Fault fault = NoFault;
        Addr EA;

        uint64_t Index = 0;
uint64_t Base = 0;
uint64_t SegBase = 0;
uint64_t Mem = 0;
;
        Index = xc->readIntRegOperand(this, 0);
Base = xc->readIntRegOperand(this, 1);
SegBase = xc->readMiscRegOperand(this, 3);
;
        
    EA = SegBase + bits(scale * Index + Base + disp, addressSize * 8 - 1, 0);
    ;
        DPRINTF(X86, "%s : %s: The address is %#x\n", instMnem, mnemonic, EA);

        fault = readMemTiming(xc, traceData, EA, Mem, dataSize, memFlags);

        return fault;
    }

    Fault Ldst::completeAcc(PacketPtr pkt,
            CPU_EXEC_CONTEXT * xc,
            Trace::InstRecord * traceData) const
    {
        Fault fault = NoFault;

        uint64_t Data = 0;
uint64_t Mem = 0;
;
        Data = xc->readIntRegOperand(this, 2);
;

        Mem = getMem(pkt, dataSize, traceData);

        Data = merge(Data, Mem, dataSize);;

        if(fault == NoFault)
        {
            
        
        {
            uint64_t final_val = Data;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault LdstBig::execute(CPU_EXEC_CONTEXT *xc,
          Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;
        Addr EA;

        uint64_t Index = 0;
uint64_t Base = 0;
uint64_t Data = 0;
uint64_t SegBase = 0;
uint64_t Mem = 0;
;
        Index = xc->readIntRegOperand(this, 0);
Base = xc->readIntRegOperand(this, 1);
SegBase = xc->readMiscRegOperand(this, 2);
;
        
    EA = SegBase + bits(scale * Index + Base + disp, addressSize * 8 - 1, 0);
    ;
        DPRINTF(X86, "%s : %s: The address is %#x\n", instMnem, mnemonic, EA);

        fault = readMemAtomic(xc, traceData, EA, Mem, dataSize, memFlags);

        if (fault == NoFault) {
            Data = Mem & mask(dataSize * 8);;
        } else if (memFlags & Request::PREFETCH) {
            // For prefetches, ignore any faults/exceptions.
            return NoFault;
        }
        if(fault == NoFault)
        {
            
        
        {
            uint64_t final_val = Data;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault LdstBig::initiateAcc(CPU_EXEC_CONTEXT * xc,
            Trace::InstRecord * traceData) const
    {
        Fault fault = NoFault;
        Addr EA;

        uint64_t Index = 0;
uint64_t Base = 0;
uint64_t SegBase = 0;
uint64_t Mem = 0;
;
        Index = xc->readIntRegOperand(this, 0);
Base = xc->readIntRegOperand(this, 1);
SegBase = xc->readMiscRegOperand(this, 2);
;
        
    EA = SegBase + bits(scale * Index + Base + disp, addressSize * 8 - 1, 0);
    ;
        DPRINTF(X86, "%s : %s: The address is %#x\n", instMnem, mnemonic, EA);

        fault = readMemTiming(xc, traceData, EA, Mem, dataSize, memFlags);

        return fault;
    }

    Fault LdstBig::completeAcc(PacketPtr pkt,
            CPU_EXEC_CONTEXT * xc,
            Trace::InstRecord * traceData) const
    {
        Fault fault = NoFault;

        uint64_t Data = 0;
uint64_t Mem = 0;
;
        ;

        Mem = getMem(pkt, dataSize, traceData);

        Data = Mem & mask(dataSize * 8);;

        if(fault == NoFault)
        {
            
        
        {
            uint64_t final_val = Data;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Ldstl::execute(CPU_EXEC_CONTEXT *xc,
          Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;
        Addr EA;

        uint64_t Index = 0;
uint64_t Base = 0;
uint64_t Data = 0;
uint64_t SegBase = 0;
uint64_t Mem = 0;
;
        Index = xc->readIntRegOperand(this, 0);
Base = xc->readIntRegOperand(this, 1);
Data = xc->readIntRegOperand(this, 2);
SegBase = xc->readMiscRegOperand(this, 3);
;
        
    EA = SegBase + bits(scale * Index + Base + disp, addressSize * 8 - 1, 0);
    ;
        DPRINTF(X86, "%s : %s: The address is %#x\n", instMnem, mnemonic, EA);

        fault = readMemAtomic(xc, traceData, EA, Mem, dataSize, memFlags);

        if (fault == NoFault) {
            Data = merge(Data, Mem, dataSize);;
        } else if (memFlags & Request::PREFETCH) {
            // For prefetches, ignore any faults/exceptions.
            return NoFault;
        }
        if(fault == NoFault)
        {
            
        
        {
            uint64_t final_val = Data;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Ldstl::initiateAcc(CPU_EXEC_CONTEXT * xc,
            Trace::InstRecord * traceData) const
    {
        Fault fault = NoFault;
        Addr EA;

        uint64_t Index = 0;
uint64_t Base = 0;
uint64_t SegBase = 0;
uint64_t Mem = 0;
;
        Index = xc->readIntRegOperand(this, 0);
Base = xc->readIntRegOperand(this, 1);
SegBase = xc->readMiscRegOperand(this, 3);
;
        
    EA = SegBase + bits(scale * Index + Base + disp, addressSize * 8 - 1, 0);
    ;
        DPRINTF(X86, "%s : %s: The address is %#x\n", instMnem, mnemonic, EA);

        fault = readMemTiming(xc, traceData, EA, Mem, dataSize, memFlags);

        return fault;
    }

    Fault Ldstl::completeAcc(PacketPtr pkt,
            CPU_EXEC_CONTEXT * xc,
            Trace::InstRecord * traceData) const
    {
        Fault fault = NoFault;

        uint64_t Data = 0;
uint64_t Mem = 0;
;
        Data = xc->readIntRegOperand(this, 2);
;

        Mem = getMem(pkt, dataSize, traceData);

        Data = merge(Data, Mem, dataSize);;

        if(fault == NoFault)
        {
            
        
        {
            uint64_t final_val = Data;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault LdstlBig::execute(CPU_EXEC_CONTEXT *xc,
          Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;
        Addr EA;

        uint64_t Index = 0;
uint64_t Base = 0;
uint64_t Data = 0;
uint64_t SegBase = 0;
uint64_t Mem = 0;
;
        Index = xc->readIntRegOperand(this, 0);
Base = xc->readIntRegOperand(this, 1);
SegBase = xc->readMiscRegOperand(this, 2);
;
        
    EA = SegBase + bits(scale * Index + Base + disp, addressSize * 8 - 1, 0);
    ;
        DPRINTF(X86, "%s : %s: The address is %#x\n", instMnem, mnemonic, EA);

        fault = readMemAtomic(xc, traceData, EA, Mem, dataSize, memFlags);

        if (fault == NoFault) {
            Data = Mem & mask(dataSize * 8);;
        } else if (memFlags & Request::PREFETCH) {
            // For prefetches, ignore any faults/exceptions.
            return NoFault;
        }
        if(fault == NoFault)
        {
            
        
        {
            uint64_t final_val = Data;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault LdstlBig::initiateAcc(CPU_EXEC_CONTEXT * xc,
            Trace::InstRecord * traceData) const
    {
        Fault fault = NoFault;
        Addr EA;

        uint64_t Index = 0;
uint64_t Base = 0;
uint64_t SegBase = 0;
uint64_t Mem = 0;
;
        Index = xc->readIntRegOperand(this, 0);
Base = xc->readIntRegOperand(this, 1);
SegBase = xc->readMiscRegOperand(this, 2);
;
        
    EA = SegBase + bits(scale * Index + Base + disp, addressSize * 8 - 1, 0);
    ;
        DPRINTF(X86, "%s : %s: The address is %#x\n", instMnem, mnemonic, EA);

        fault = readMemTiming(xc, traceData, EA, Mem, dataSize, memFlags);

        return fault;
    }

    Fault LdstlBig::completeAcc(PacketPtr pkt,
            CPU_EXEC_CONTEXT * xc,
            Trace::InstRecord * traceData) const
    {
        Fault fault = NoFault;

        uint64_t Data = 0;
uint64_t Mem = 0;
;
        ;

        Mem = getMem(pkt, dataSize, traceData);

        Data = Mem & mask(dataSize * 8);;

        if(fault == NoFault)
        {
            
        
        {
            uint64_t final_val = Data;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Ldfp::execute(CPU_EXEC_CONTEXT *xc,
          Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;
        Addr EA;

        uint64_t Index = 0;
uint64_t Base = 0;
uint64_t FpData = 0;
uint64_t SegBase = 0;
uint64_t Mem = 0;
;
        Index = xc->readIntRegOperand(this, 0);
Base = xc->readIntRegOperand(this, 1);
SegBase = xc->readMiscRegOperand(this, 2);
;
        
    EA = SegBase + bits(scale * Index + Base + disp, addressSize * 8 - 1, 0);
    ;
        DPRINTF(X86, "%s : %s: The address is %#x\n", instMnem, mnemonic, EA);

        fault = readMemAtomic(xc, traceData, EA, Mem, dataSize, memFlags);

        if (fault == NoFault) {
            FpData = Mem;
        } else if (memFlags & Request::PREFETCH) {
            // For prefetches, ignore any faults/exceptions.
            return NoFault;
        }
        if(fault == NoFault)
        {
            
        {
            uint64_t final_val = FpData;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Ldfp::initiateAcc(CPU_EXEC_CONTEXT * xc,
            Trace::InstRecord * traceData) const
    {
        Fault fault = NoFault;
        Addr EA;

        uint64_t Index = 0;
uint64_t Base = 0;
uint64_t SegBase = 0;
uint64_t Mem = 0;
;
        Index = xc->readIntRegOperand(this, 0);
Base = xc->readIntRegOperand(this, 1);
SegBase = xc->readMiscRegOperand(this, 2);
;
        
    EA = SegBase + bits(scale * Index + Base + disp, addressSize * 8 - 1, 0);
    ;
        DPRINTF(X86, "%s : %s: The address is %#x\n", instMnem, mnemonic, EA);

        fault = readMemTiming(xc, traceData, EA, Mem, dataSize, memFlags);

        return fault;
    }

    Fault Ldfp::completeAcc(PacketPtr pkt,
            CPU_EXEC_CONTEXT * xc,
            Trace::InstRecord * traceData) const
    {
        Fault fault = NoFault;

        uint64_t FpData = 0;
uint64_t Mem = 0;
;
        ;

        Mem = getMem(pkt, dataSize, traceData);

        FpData = Mem;

        if(fault == NoFault)
        {
            
        {
            uint64_t final_val = FpData;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Ldfp87::execute(CPU_EXEC_CONTEXT *xc,
          Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;
        Addr EA;

        uint64_t Index = 0;
uint64_t Base = 0;
double FpData = 0;
uint64_t SegBase = 0;
uint64_t Mem = 0;
;
        Index = xc->readIntRegOperand(this, 0);
Base = xc->readIntRegOperand(this, 1);
SegBase = xc->readMiscRegOperand(this, 2);
;
        
    EA = SegBase + bits(scale * Index + Base + disp, addressSize * 8 - 1, 0);
    ;
        DPRINTF(X86, "%s : %s: The address is %#x\n", instMnem, mnemonic, EA);

        fault = readMemAtomic(xc, traceData, EA, Mem, dataSize, memFlags);

        if (fault == NoFault) {
            
        switch (dataSize)
        {
          case 4:
            FpData = *(float *)&Mem;
            break;
          case 8:
            FpData = *(double *)&Mem;
            break;
          default:
            panic("Unhandled data size in LdFp87.\n");
        }
    ;
        } else if (memFlags & Request::PREFETCH) {
            // For prefetches, ignore any faults/exceptions.
            return NoFault;
        }
        if(fault == NoFault)
        {
            
        {
            double final_val = FpData;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Ldfp87::initiateAcc(CPU_EXEC_CONTEXT * xc,
            Trace::InstRecord * traceData) const
    {
        Fault fault = NoFault;
        Addr EA;

        uint64_t Index = 0;
uint64_t Base = 0;
uint64_t SegBase = 0;
uint64_t Mem = 0;
;
        Index = xc->readIntRegOperand(this, 0);
Base = xc->readIntRegOperand(this, 1);
SegBase = xc->readMiscRegOperand(this, 2);
;
        
    EA = SegBase + bits(scale * Index + Base + disp, addressSize * 8 - 1, 0);
    ;
        DPRINTF(X86, "%s : %s: The address is %#x\n", instMnem, mnemonic, EA);

        fault = readMemTiming(xc, traceData, EA, Mem, dataSize, memFlags);

        return fault;
    }

    Fault Ldfp87::completeAcc(PacketPtr pkt,
            CPU_EXEC_CONTEXT * xc,
            Trace::InstRecord * traceData) const
    {
        Fault fault = NoFault;

        double FpData = 0;
uint64_t Mem = 0;
;
        ;

        Mem = getMem(pkt, dataSize, traceData);

        
        switch (dataSize)
        {
          case 4:
            FpData = *(float *)&Mem;
            break;
          case 8:
            FpData = *(double *)&Mem;
            break;
          default:
            panic("Unhandled data size in LdFp87.\n");
        }
    ;

        if(fault == NoFault)
        {
            
        {
            double final_val = FpData;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault St::execute(CPU_EXEC_CONTEXT * xc,
            Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        Addr EA;
        uint64_t Index = 0;
uint64_t Base = 0;
uint64_t Data = 0;
uint64_t SegBase = 0;
uint64_t Mem = 0;
;
        Index = xc->readIntRegOperand(this, 0);
Base = xc->readIntRegOperand(this, 1);
Data = xc->readIntRegOperand(this, 2);
SegBase = xc->readMiscRegOperand(this, 3);
;
        
    EA = SegBase + bits(scale * Index + Base + disp, addressSize * 8 - 1, 0);
    ;
        DPRINTF(X86, "%s : %s: The address is %#x\n", instMnem, mnemonic, EA);

        Mem = pick(Data, 2, dataSize);;

        if(fault == NoFault)
        {
            fault = writeMemAtomic(xc, traceData, Mem, dataSize, EA,
                    memFlags, NULL);
            if(fault == NoFault)
            {
                ;
            }
        }

        return fault;
    }

    Fault St::initiateAcc(CPU_EXEC_CONTEXT * xc,
            Trace::InstRecord * traceData) const
    {
        Fault fault = NoFault;

        Addr EA;
        uint64_t Index = 0;
uint64_t Base = 0;
uint64_t Data = 0;
uint64_t SegBase = 0;
uint64_t Mem = 0;
;
        Index = xc->readIntRegOperand(this, 0);
Base = xc->readIntRegOperand(this, 1);
Data = xc->readIntRegOperand(this, 2);
SegBase = xc->readMiscRegOperand(this, 3);
;
        
    EA = SegBase + bits(scale * Index + Base + disp, addressSize * 8 - 1, 0);
    ;
        DPRINTF(X86, "%s : %s: The address is %#x\n", instMnem, mnemonic, EA);

        Mem = pick(Data, 2, dataSize);;

        if(fault == NoFault)
        {
            fault = writeMemTiming(xc, traceData, Mem, dataSize, EA,
                    memFlags, NULL);
        }
        return fault;
    }

    Fault St::completeAcc(PacketPtr pkt,
            CPU_EXEC_CONTEXT * xc, Trace::InstRecord * traceData) const
    {
        ;
        ;
        ;
        ;
        return NoFault;
    }

    Fault Stul::execute(CPU_EXEC_CONTEXT * xc,
            Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        Addr EA;
        uint64_t Index = 0;
uint64_t Base = 0;
uint64_t Data = 0;
uint64_t SegBase = 0;
uint64_t Mem = 0;
;
        Index = xc->readIntRegOperand(this, 0);
Base = xc->readIntRegOperand(this, 1);
Data = xc->readIntRegOperand(this, 2);
SegBase = xc->readMiscRegOperand(this, 3);
;
        
    EA = SegBase + bits(scale * Index + Base + disp, addressSize * 8 - 1, 0);
    ;
        DPRINTF(X86, "%s : %s: The address is %#x\n", instMnem, mnemonic, EA);

        Mem = pick(Data, 2, dataSize);;

        if(fault == NoFault)
        {
            fault = writeMemAtomic(xc, traceData, Mem, dataSize, EA,
                    memFlags, NULL);
            if(fault == NoFault)
            {
                ;
            }
        }

        return fault;
    }

    Fault Stul::initiateAcc(CPU_EXEC_CONTEXT * xc,
            Trace::InstRecord * traceData) const
    {
        Fault fault = NoFault;

        Addr EA;
        uint64_t Index = 0;
uint64_t Base = 0;
uint64_t Data = 0;
uint64_t SegBase = 0;
uint64_t Mem = 0;
;
        Index = xc->readIntRegOperand(this, 0);
Base = xc->readIntRegOperand(this, 1);
Data = xc->readIntRegOperand(this, 2);
SegBase = xc->readMiscRegOperand(this, 3);
;
        
    EA = SegBase + bits(scale * Index + Base + disp, addressSize * 8 - 1, 0);
    ;
        DPRINTF(X86, "%s : %s: The address is %#x\n", instMnem, mnemonic, EA);

        Mem = pick(Data, 2, dataSize);;

        if(fault == NoFault)
        {
            fault = writeMemTiming(xc, traceData, Mem, dataSize, EA,
                    memFlags, NULL);
        }
        return fault;
    }

    Fault Stul::completeAcc(PacketPtr pkt,
            CPU_EXEC_CONTEXT * xc, Trace::InstRecord * traceData) const
    {
        ;
        ;
        ;
        ;
        return NoFault;
    }

    Fault Stfp::execute(CPU_EXEC_CONTEXT * xc,
            Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        Addr EA;
        uint64_t Index = 0;
uint64_t Base = 0;
uint64_t FpData = 0;
uint64_t SegBase = 0;
uint64_t Mem = 0;
;
        Index = xc->readIntRegOperand(this, 0);
Base = xc->readIntRegOperand(this, 1);
FpData = xc->readFloatRegOperandBits(this, 2);
SegBase = xc->readMiscRegOperand(this, 3);
;
        
    EA = SegBase + bits(scale * Index + Base + disp, addressSize * 8 - 1, 0);
    ;
        DPRINTF(X86, "%s : %s: The address is %#x\n", instMnem, mnemonic, EA);

        Mem = FpData;;

        if(fault == NoFault)
        {
            fault = writeMemAtomic(xc, traceData, Mem, dataSize, EA,
                    memFlags, NULL);
            if(fault == NoFault)
            {
                ;
            }
        }

        return fault;
    }

    Fault Stfp::initiateAcc(CPU_EXEC_CONTEXT * xc,
            Trace::InstRecord * traceData) const
    {
        Fault fault = NoFault;

        Addr EA;
        uint64_t Index = 0;
uint64_t Base = 0;
uint64_t FpData = 0;
uint64_t SegBase = 0;
uint64_t Mem = 0;
;
        Index = xc->readIntRegOperand(this, 0);
Base = xc->readIntRegOperand(this, 1);
FpData = xc->readFloatRegOperandBits(this, 2);
SegBase = xc->readMiscRegOperand(this, 3);
;
        
    EA = SegBase + bits(scale * Index + Base + disp, addressSize * 8 - 1, 0);
    ;
        DPRINTF(X86, "%s : %s: The address is %#x\n", instMnem, mnemonic, EA);

        Mem = FpData;;

        if(fault == NoFault)
        {
            fault = writeMemTiming(xc, traceData, Mem, dataSize, EA,
                    memFlags, NULL);
        }
        return fault;
    }

    Fault Stfp::completeAcc(PacketPtr pkt,
            CPU_EXEC_CONTEXT * xc, Trace::InstRecord * traceData) const
    {
        ;
        ;
        ;
        ;
        return NoFault;
    }

    Fault Stfp87::execute(CPU_EXEC_CONTEXT * xc,
            Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        Addr EA;
        uint64_t Index = 0;
uint64_t Base = 0;
double FpData = 0;
uint64_t SegBase = 0;
uint64_t Mem = 0;
;
        Index = xc->readIntRegOperand(this, 0);
Base = xc->readIntRegOperand(this, 1);
FpData = xc->readFloatRegOperand(this, 2);
SegBase = xc->readMiscRegOperand(this, 3);
;
        
    EA = SegBase + bits(scale * Index + Base + disp, addressSize * 8 - 1, 0);
    ;
        DPRINTF(X86, "%s : %s: The address is %#x\n", instMnem, mnemonic, EA);

        
        switch (dataSize)
        {
          case 4: {
            float single(FpData);
            Mem = *(uint32_t *)&single;
          } break;
          case 8:
            Mem = *(uint64_t *)&FpData;
            break;
          default:
            panic("Unhandled data size in StFp87.\n");
        }
    ;

        if(fault == NoFault)
        {
            fault = writeMemAtomic(xc, traceData, Mem, dataSize, EA,
                    memFlags, NULL);
            if(fault == NoFault)
            {
                ;
            }
        }

        return fault;
    }

    Fault Stfp87::initiateAcc(CPU_EXEC_CONTEXT * xc,
            Trace::InstRecord * traceData) const
    {
        Fault fault = NoFault;

        Addr EA;
        uint64_t Index = 0;
uint64_t Base = 0;
double FpData = 0;
uint64_t SegBase = 0;
uint64_t Mem = 0;
;
        Index = xc->readIntRegOperand(this, 0);
Base = xc->readIntRegOperand(this, 1);
FpData = xc->readFloatRegOperand(this, 2);
SegBase = xc->readMiscRegOperand(this, 3);
;
        
    EA = SegBase + bits(scale * Index + Base + disp, addressSize * 8 - 1, 0);
    ;
        DPRINTF(X86, "%s : %s: The address is %#x\n", instMnem, mnemonic, EA);

        
        switch (dataSize)
        {
          case 4: {
            float single(FpData);
            Mem = *(uint32_t *)&single;
          } break;
          case 8:
            Mem = *(uint64_t *)&FpData;
            break;
          default:
            panic("Unhandled data size in StFp87.\n");
        }
    ;

        if(fault == NoFault)
        {
            fault = writeMemTiming(xc, traceData, Mem, dataSize, EA,
                    memFlags, NULL);
        }
        return fault;
    }

    Fault Stfp87::completeAcc(PacketPtr pkt,
            CPU_EXEC_CONTEXT * xc, Trace::InstRecord * traceData) const
    {
        ;
        ;
        ;
        ;
        return NoFault;
    }

    Fault Cda::execute(CPU_EXEC_CONTEXT * xc,
            Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        Addr EA;
        uint64_t Index = 0;
uint64_t Base = 0;
uint64_t SegBase = 0;
uint64_t Mem = 0;
;
        Index = xc->readIntRegOperand(this, 0);
Base = xc->readIntRegOperand(this, 1);
SegBase = xc->readMiscRegOperand(this, 2);
;
        
    EA = SegBase + bits(scale * Index + Base + disp, addressSize * 8 - 1, 0);
    ;
        DPRINTF(X86, "%s : %s: The address is %#x\n", instMnem, mnemonic, EA);

        Mem = 0;;

        if(fault == NoFault)
        {
            fault = writeMemAtomic(xc, traceData, Mem, dataSize, EA,
                    memFlags, NULL);
            if(fault == NoFault)
            {
                ;
            }
        }

        return fault;
    }

    Fault Cda::initiateAcc(CPU_EXEC_CONTEXT * xc,
            Trace::InstRecord * traceData) const
    {
        Fault fault = NoFault;

        Addr EA;
        uint64_t Index = 0;
uint64_t Base = 0;
uint64_t SegBase = 0;
uint64_t Mem = 0;
;
        Index = xc->readIntRegOperand(this, 0);
Base = xc->readIntRegOperand(this, 1);
SegBase = xc->readMiscRegOperand(this, 2);
;
        
    EA = SegBase + bits(scale * Index + Base + disp, addressSize * 8 - 1, 0);
    ;
        DPRINTF(X86, "%s : %s: The address is %#x\n", instMnem, mnemonic, EA);

        Mem = 0;;

        if(fault == NoFault)
        {
            fault = writeMemTiming(xc, traceData, Mem, dataSize, EA,
                    memFlags, NULL);
        }
        return fault;
    }

    Fault Cda::completeAcc(PacketPtr pkt,
            CPU_EXEC_CONTEXT * xc, Trace::InstRecord * traceData) const
    {
        ;
        ;
        ;
        ;
        return NoFault;
    }

    Fault Lea::execute(CPU_EXEC_CONTEXT *xc,
          Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;
        Addr EA;

        uint64_t Index = 0;
uint64_t Base = 0;
uint64_t Data = 0;
;
        Index = xc->readIntRegOperand(this, 0);
Base = xc->readIntRegOperand(this, 1);
Data = xc->readIntRegOperand(this, 2);
;
        
             EA = bits(scale * Index + Base + disp, addressSize * 8 - 1, 0);
             ;
        DPRINTF(X86, "%s : %s: The address is %#x\n", instMnem, mnemonic, EA);

        Data = merge(Data, EA, dataSize);;
        if(fault == NoFault)
        {
            
        
        {
            uint64_t final_val = Data;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Tia::execute(CPU_EXEC_CONTEXT *xc,
          Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;
        Addr EA;

        uint64_t Index = 0;
uint64_t Base = 0;
uint64_t SegBase = 0;
;
        Index = xc->readIntRegOperand(this, 0);
Base = xc->readIntRegOperand(this, 1);
SegBase = xc->readMiscRegOperand(this, 2);
;
        
    EA = SegBase + bits(scale * Index + Base + disp, addressSize * 8 - 1, 0);
    ;
        DPRINTF(X86, "%s : %s: The address is %#x\n", instMnem, mnemonic, EA);

        xc->demapPage(EA, 0);;
        if(fault == NoFault)
        {
            ;
        }

        return fault;
    }

        Fault Mov2int::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t DestReg = 0;
uint64_t FpSrcReg1 = 0;
;
            DestReg = xc->readIntRegOperand(this, 0);
FpSrcReg1 = xc->readFloatRegOperandBits(this, 1);
;

            
            int items = sizeof(FloatRegBits) / srcSize;
            int offset = imm8;
            if (bits(src1, 0) && (ext & 0x1))
                offset -= items;
            if (offset >= 0 && offset < items) {
                uint64_t fpSrcReg1 =
                    bits(FpSrcReg1,
                            (offset + 1) * srcSize * 8 - 1,
                            (offset + 0) * srcSize * 8);
                DestReg = merge(0, fpSrcReg1, destSize);
            } else {
                DestReg = DestReg;
            }
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Mov2fp::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t SrcReg1 = 0;
uint64_t FpDestReg = 0;
;
            SrcReg1 = xc->readIntRegOperand(this, 0);
FpDestReg = xc->readFloatRegOperandBits(this, 1);
;

            
            int items = sizeof(FloatRegBits) / destSize;
            int offset = imm8;
            if (bits(dest, 0) && (ext & 0x1))
                offset -= items;
            if (offset >= 0 && offset < items) {
                uint64_t srcReg1 = pick(SrcReg1, 0, srcSize);
                FpDestReg =
                    insertBits(FpDestReg,
                            (offset + 1) * destSize * 8 - 1,
                            (offset + 0) * destSize * 8, srcReg1);
            } else {
                FpDestReg = FpDestReg;
            }
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Movsign::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t DestReg = 0;
uint64_t FpSrcReg1 = 0;
;
            DestReg = xc->readIntRegOperand(this, 0);
FpSrcReg1 = xc->readFloatRegOperandBits(this, 1);
;

            
            int items = sizeof(FloatRegBits) / srcSize;
            uint64_t result = 0;
            int offset = (ext & 0x1) ? items : 0;
            for (int i = 0; i < items; i++) {
                uint64_t picked =
                    bits(FpSrcReg1, (i + 1) * 8 * srcSize - 1);
                result = insertBits(result, i + offset, i + offset, picked);
            }
            DestReg = DestReg | result;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = DestReg;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Maskmov::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
FpDestReg = xc->readFloatRegOperandBits(this, 2);
;

            
            assert(srcSize == destSize);
            int size = srcSize;
            int sizeBits = size * 8;
            int items = numItems(size);
            uint64_t result = FpDestReg;
            for (int i = 0; i < items; i++) {
                int hiIndex = (i + 1) * sizeBits - 1;
                int loIndex = (i + 0) * sizeBits;
                uint64_t arg1Bits = bits(FpSrcReg1, hiIndex, loIndex);
                if (bits(FpSrcReg2, hiIndex))
                    result = insertBits(result, hiIndex, loIndex, arg1Bits);
            }
            FpDestReg = result;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault shuffle::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
;

            
            assert(srcSize == destSize);
            int size = srcSize;
            int sizeBits = size * 8;
            int items = sizeof(FloatRegBits) / size;
            int options;
            int optionBits;
            if (size == 8) {
                options = 2;
                optionBits = 1;
            } else {
                options = 4;
                optionBits = 2;
            }
            uint64_t result = 0;
            uint8_t sel = ext;
            for (int i = 0; i < items; i++) {
                uint64_t resBits;
                uint8_t lsel = sel & mask(optionBits);
                if (lsel * size >= sizeof(FloatRegBits)) {
                    lsel -= options / 2;
                    resBits = bits(FpSrcReg2,
                            (lsel + 1) * sizeBits - 1,
                            (lsel + 0) * sizeBits);
                }  else {
                    resBits = bits(FpSrcReg1,
                            (lsel + 1) * sizeBits - 1,
                            (lsel + 0) * sizeBits);
                }
                sel >>= optionBits;
                int hiIndex = (i + 1) * sizeBits - 1;
                int loIndex = (i + 0) * sizeBits;
                result = insertBits(result, hiIndex, loIndex, resBits);
            }
            FpDestReg = result;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Unpack::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
;

            
            assert(srcSize == destSize);
            int size = destSize;
            int items = (sizeof(FloatRegBits) / size) / 2;
            int offset = ext ? items : 0;
            uint64_t result = 0;
            for (int i = 0; i < items; i++) {
                uint64_t pickedLow =
                    bits(FpSrcReg1, (i + offset + 1) * 8 * size - 1,
                                        (i + offset) * 8 * size);
                result = insertBits(result,
                                    (2 * i + 1) * 8 * size - 1,
                                    (2 * i + 0) * 8 * size,
                                    pickedLow);
                uint64_t pickedHigh =
                    bits(FpSrcReg2, (i + offset + 1) * 8 * size - 1,
                                        (i + offset) * 8 * size);
                result = insertBits(result,
                                    (2 * i + 2) * 8 * size - 1,
                                    (2 * i + 1) * 8 * size,
                                    pickedHigh);
            }
            FpDestReg = result;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Pack::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
;

            
            assert(srcSize == destSize * 2);
            int items = (sizeof(FloatRegBits) / destSize);
            int destBits = destSize * 8;
            int srcBits = srcSize * 8;
            uint64_t result = 0;
            int i;
            for (i = 0; i < items / 2; i++) {
                uint64_t picked =
                    bits(FpSrcReg1, (i + 1) * srcBits - 1,
                                        (i + 0) * srcBits);
                unsigned signBit = bits(picked, srcBits - 1);
                uint64_t overflow = bits(picked, srcBits - 1, destBits - 1);
                // Handle saturation.
                if (signBit) {
                    if (overflow != mask(destBits - srcBits + 1)) {
                        if (signedOp())
                            picked = (ULL(1) << (destBits - 1));
                        else
                            picked = 0;
                    }
                } else {
                    if (overflow != 0) {
                        if (signedOp())
                            picked = mask(destBits - 1);
                        else
                            picked = mask(destBits);
                    }
                }
                result = insertBits(result,
                                    (i + 1) * destBits - 1,
                                    (i + 0) * destBits,
                                    picked);
            }
            for (;i < items; i++) {
                uint64_t picked =
                    bits(FpSrcReg2, (i - items + 1) * srcBits - 1,
                                        (i - items + 0) * srcBits);
                unsigned signBit = bits(picked, srcBits - 1);
                uint64_t overflow = bits(picked, srcBits - 1, destBits - 1);
                // Handle saturation.
                if (signBit) {
                    if (overflow != mask(destBits - srcBits + 1)) {
                        if (signedOp())
                            picked = (ULL(1) << (destBits - 1));
                        else
                            picked = 0;
                    }
                } else {
                    if (overflow != 0) {
                        if (signedOp())
                            picked = mask(destBits - 1);
                        else
                            picked = mask(destBits);
                    }
                }
                result = insertBits(result,
                                    (i + 1) * destBits - 1,
                                    (i + 0) * destBits,
                                    picked);
            }
            FpDestReg = result;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Mxor::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
;

            
            FpDestReg = FpSrcReg1 ^ FpSrcReg2;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Mor::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
;

            
            FpDestReg = FpSrcReg1 | FpSrcReg2;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Mand::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
;

            
            FpDestReg = FpSrcReg1 & FpSrcReg2;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Mandn::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
;

            
            FpDestReg = ~FpSrcReg1 & FpSrcReg2;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Mminf::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
FpDestReg = xc->readFloatRegOperandBits(this, 2);
;

            
            union floatInt
            {
                float f;
                uint32_t i;
            };
            union doubleInt
            {
                double d;
                uint64_t i;
            };
            assert(srcSize == destSize);
            int size = srcSize;
            int sizeBits = size * 8;
            assert(srcSize == 4 || srcSize == 8);
            int items = numItems(size);
            uint64_t result = FpDestReg;
            for (int i = 0; i < items; i++) {
                double arg1, arg2;
                int hiIndex = (i + 1) * sizeBits - 1;
                int loIndex = (i + 0) * sizeBits;
                uint64_t arg1Bits = bits(FpSrcReg1, hiIndex, loIndex);
                uint64_t arg2Bits = bits(FpSrcReg2, hiIndex, loIndex);
                if (size == 4) {
                    floatInt fi;
                    fi.i = arg1Bits;
                    arg1 = fi.f;
                    fi.i = arg2Bits;
                    arg2 = fi.f;
                } else {
                    doubleInt di;
                    di.i = arg1Bits;
                    arg1 = di.d;
                    di.i = arg2Bits;
                    arg2 = di.d;
                }
                if (arg1 < arg2) {
                    result = insertBits(result, hiIndex, loIndex, arg1Bits);
                } else {
                    result = insertBits(result, hiIndex, loIndex, arg2Bits);
                }
            }
            FpDestReg = result;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Mmaxf::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
FpDestReg = xc->readFloatRegOperandBits(this, 2);
;

            
            union floatInt
            {
                float f;
                uint32_t i;
            };
            union doubleInt
            {
                double d;
                uint64_t i;
            };
            assert(srcSize == destSize);
            int size = srcSize;
            int sizeBits = size * 8;
            assert(srcSize == 4 || srcSize == 8);
            int items = numItems(size);
            uint64_t result = FpDestReg;
            for (int i = 0; i < items; i++) {
                double arg1, arg2;
                int hiIndex = (i + 1) * sizeBits - 1;
                int loIndex = (i + 0) * sizeBits;
                uint64_t arg1Bits = bits(FpSrcReg1, hiIndex, loIndex);
                uint64_t arg2Bits = bits(FpSrcReg2, hiIndex, loIndex);
                if (size == 4) {
                    floatInt fi;
                    fi.i = arg1Bits;
                    arg1 = fi.f;
                    fi.i = arg2Bits;
                    arg2 = fi.f;
                } else {
                    doubleInt di;
                    di.i = arg1Bits;
                    arg1 = di.d;
                    di.i = arg2Bits;
                    arg2 = di.d;
                }
                if (arg1 > arg2) {
                    result = insertBits(result, hiIndex, loIndex, arg1Bits);
                } else {
                    result = insertBits(result, hiIndex, loIndex, arg2Bits);
                }
            }
            FpDestReg = result;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Mmini::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
FpDestReg = xc->readFloatRegOperandBits(this, 2);
;

            
            assert(srcSize == destSize);
            int size = srcSize;
            int sizeBits = size * 8;
            int items = numItems(size);
            uint64_t result = FpDestReg;
            for (int i = 0; i < items; i++) {
                int hiIndex = (i + 1) * sizeBits - 1;
                int loIndex = (i + 0) * sizeBits;
                uint64_t arg1Bits = bits(FpSrcReg1, hiIndex, loIndex);
                int64_t arg1 = arg1Bits |
                    (0 - (arg1Bits & (ULL(1) << (sizeBits - 1))));
                uint64_t arg2Bits = bits(FpSrcReg2, hiIndex, loIndex);
                int64_t arg2 = arg2Bits |
                    (0 - (arg2Bits & (ULL(1) << (sizeBits - 1))));
                uint64_t resBits;
                if (signedOp()) {
                    if (arg1 < arg2) {
                        resBits = arg1Bits;
                    } else {
                        resBits = arg2Bits;
                    }
                } else {
                    if (arg1Bits < arg2Bits) {
                        resBits = arg1Bits;
                    } else {
                        resBits = arg2Bits;
                    }
                }
                result = insertBits(result, hiIndex, loIndex, resBits);
            }
            FpDestReg = result;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Mmaxi::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
FpDestReg = xc->readFloatRegOperandBits(this, 2);
;

            
            assert(srcSize == destSize);
            int size = srcSize;
            int sizeBits = size * 8;
            int items = numItems(size);
            uint64_t result = FpDestReg;
            for (int i = 0; i < items; i++) {
                int hiIndex = (i + 1) * sizeBits - 1;
                int loIndex = (i + 0) * sizeBits;
                uint64_t arg1Bits = bits(FpSrcReg1, hiIndex, loIndex);
                int64_t arg1 = arg1Bits |
                    (0 - (arg1Bits & (ULL(1) << (sizeBits - 1))));
                uint64_t arg2Bits = bits(FpSrcReg2, hiIndex, loIndex);
                int64_t arg2 = arg2Bits |
                    (0 - (arg2Bits & (ULL(1) << (sizeBits - 1))));
                uint64_t resBits;
                if (signedOp()) {
                    if (arg1 > arg2) {
                        resBits = arg1Bits;
                    } else {
                        resBits = arg2Bits;
                    }
                } else {
                    if (arg1Bits > arg2Bits) {
                        resBits = arg1Bits;
                    } else {
                        resBits = arg2Bits;
                    }
                }
                result = insertBits(result, hiIndex, loIndex, resBits);
            }
            FpDestReg = result;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Msqrt::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpDestReg = xc->readFloatRegOperandBits(this, 1);
;

            
            union floatInt
            {
                float f;
                uint32_t i;
            };
            union doubleInt
            {
                double d;
                uint64_t i;
            };
            assert(srcSize == destSize);
            int size = srcSize;
            int sizeBits = size * 8;
            assert(srcSize == 4 || srcSize == 8);
            int items = numItems(size);
            uint64_t result = FpDestReg;
            for (int i = 0; i < items; i++) {
                int hiIndex = (i + 1) * sizeBits - 1;
                int loIndex = (i + 0) * sizeBits;
                uint64_t argBits = bits(FpSrcReg1, hiIndex, loIndex);
                if (size == 4) {
                    floatInt fi;
                    fi.i = argBits;
                    fi.f = sqrt(fi.f);
                    argBits = fi.i;
                } else {
                    doubleInt di;
                    di.i = argBits;
                    di.d = sqrt(di.d);
                    argBits = di.i;
                }
                result = insertBits(result, hiIndex, loIndex, argBits);
            }
            FpDestReg = result;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Maddf::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
FpDestReg = xc->readFloatRegOperandBits(this, 2);
;

            
            union floatInt
            {
                float f;
                uint32_t i;
            };
            union doubleInt
            {
                double d;
                uint64_t i;
            };
            assert(srcSize == destSize);
            int size = srcSize;
            int sizeBits = size * 8;
            assert(srcSize == 4 || srcSize == 8);
            int items = numItems(size);
            uint64_t result = FpDestReg;
            for (int i = 0; i < items; i++) {
                int hiIndex = (i + 1) * sizeBits - 1;
                int loIndex = (i + 0) * sizeBits;
                uint64_t arg1Bits = bits(FpSrcReg1, hiIndex, loIndex);
                uint64_t arg2Bits = bits(FpSrcReg2, hiIndex, loIndex);
                uint64_t resBits;
                if (size == 4) {
                    floatInt arg1, arg2, res;
                    arg1.i = arg1Bits;
                    arg2.i = arg2Bits;
                    res.f = arg1.f + arg2.f;
                    resBits = res.i;
                } else {
                    doubleInt arg1, arg2, res;
                    arg1.i = arg1Bits;
                    arg2.i = arg2Bits;
                    res.d = arg1.d + arg2.d;
                    resBits = res.i;
                }
                result = insertBits(result, hiIndex, loIndex, resBits);
            }
            FpDestReg = result;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Msubf::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
FpDestReg = xc->readFloatRegOperandBits(this, 2);
;

            
            union floatInt
            {
                float f;
                uint32_t i;
            };
            union doubleInt
            {
                double d;
                uint64_t i;
            };
            assert(srcSize == destSize);
            int size = srcSize;
            int sizeBits = size * 8;
            assert(srcSize == 4 || srcSize == 8);
            int items = numItems(size);
            uint64_t result = FpDestReg;
            for (int i = 0; i < items; i++) {
                int hiIndex = (i + 1) * sizeBits - 1;
                int loIndex = (i + 0) * sizeBits;
                uint64_t arg1Bits = bits(FpSrcReg1, hiIndex, loIndex);
                uint64_t arg2Bits = bits(FpSrcReg2, hiIndex, loIndex);
                uint64_t resBits;
                if (size == 4) {
                    floatInt arg1, arg2, res;
                    arg1.i = arg1Bits;
                    arg2.i = arg2Bits;
                    res.f = arg1.f - arg2.f;
                    resBits = res.i;
                } else {
                    doubleInt arg1, arg2, res;
                    arg1.i = arg1Bits;
                    arg2.i = arg2Bits;
                    res.d = arg1.d - arg2.d;
                    resBits = res.i;
                }
                result = insertBits(result, hiIndex, loIndex, resBits);
            }
            FpDestReg = result;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Mmulf::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
FpDestReg = xc->readFloatRegOperandBits(this, 2);
;

            
            union floatInt
            {
                float f;
                uint32_t i;
            };
            union doubleInt
            {
                double d;
                uint64_t i;
            };
            assert(srcSize == destSize);
            int size = srcSize;
            int sizeBits = size * 8;
            assert(srcSize == 4 || srcSize == 8);
            int items = numItems(size);
            uint64_t result = FpDestReg;
            for (int i = 0; i < items; i++) {
                int hiIndex = (i + 1) * sizeBits - 1;
                int loIndex = (i + 0) * sizeBits;
                uint64_t arg1Bits = bits(FpSrcReg1, hiIndex, loIndex);
                uint64_t arg2Bits = bits(FpSrcReg2, hiIndex, loIndex);
                uint64_t resBits;
                if (size == 4) {
                    floatInt arg1, arg2, res;
                    arg1.i = arg1Bits;
                    arg2.i = arg2Bits;
                    res.f = arg1.f * arg2.f;
                    resBits = res.i;
                } else {
                    doubleInt arg1, arg2, res;
                    arg1.i = arg1Bits;
                    arg2.i = arg2Bits;
                    res.d = arg1.d * arg2.d;
                    resBits = res.i;
                }
                result = insertBits(result, hiIndex, loIndex, resBits);
            }
            FpDestReg = result;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Mdivf::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
FpDestReg = xc->readFloatRegOperandBits(this, 2);
;

            
            union floatInt
            {
                float f;
                uint32_t i;
            };
            union doubleInt
            {
                double d;
                uint64_t i;
            };
            assert(srcSize == destSize);
            int size = srcSize;
            int sizeBits = size * 8;
            assert(srcSize == 4 || srcSize == 8);
            int items = numItems(size);
            uint64_t result = FpDestReg;
            for (int i = 0; i < items; i++) {
                int hiIndex = (i + 1) * sizeBits - 1;
                int loIndex = (i + 0) * sizeBits;
                uint64_t arg1Bits = bits(FpSrcReg1, hiIndex, loIndex);
                uint64_t arg2Bits = bits(FpSrcReg2, hiIndex, loIndex);
                uint64_t resBits;
                if (size == 4) {
                    floatInt arg1, arg2, res;
                    arg1.i = arg1Bits;
                    arg2.i = arg2Bits;
                    res.f = arg1.f / arg2.f;
                    resBits = res.i;
                } else {
                    doubleInt arg1, arg2, res;
                    arg1.i = arg1Bits;
                    arg2.i = arg2Bits;
                    res.d = arg1.d / arg2.d;
                    resBits = res.i;
                }
                result = insertBits(result, hiIndex, loIndex, resBits);
            }
            FpDestReg = result;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Maddi::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
FpDestReg = xc->readFloatRegOperandBits(this, 2);
;

            
            assert(srcSize == destSize);
            int size = srcSize;
            int sizeBits = size * 8;
            int items = numItems(size);
            uint64_t result = FpDestReg;
            for (int i = 0; i < items; i++) {
                int hiIndex = (i + 1) * sizeBits - 1;
                int loIndex = (i + 0) * sizeBits;
                uint64_t arg1Bits = bits(FpSrcReg1, hiIndex, loIndex);
                uint64_t arg2Bits = bits(FpSrcReg2, hiIndex, loIndex);
                uint64_t resBits = arg1Bits + arg2Bits;
                if (ext & 0x2) {
                    if (signedOp()) {
                        int arg1Sign = bits(arg1Bits, sizeBits - 1);
                        int arg2Sign = bits(arg2Bits, sizeBits - 1);
                        int resSign = bits(resBits, sizeBits - 1);
                        if ((arg1Sign == arg2Sign) && (arg1Sign != resSign)) {
                            if (resSign == 0)
                                resBits = (ULL(1) << (sizeBits - 1));
                            else
                                resBits = mask(sizeBits - 1);
                        }
                    } else {
                        if (findCarry(sizeBits, resBits, arg1Bits, arg2Bits))
                            resBits = mask(sizeBits);
                    }
                }
                result = insertBits(result, hiIndex, loIndex, resBits);
            }
            FpDestReg = result;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Msubi::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
FpDestReg = xc->readFloatRegOperandBits(this, 2);
;

            
            assert(srcSize == destSize);
            int size = srcSize;
            int sizeBits = size * 8;
            int items = numItems(size);
            uint64_t result = FpDestReg;
            for (int i = 0; i < items; i++) {
                int hiIndex = (i + 1) * sizeBits - 1;
                int loIndex = (i + 0) * sizeBits;
                uint64_t arg1Bits = bits(FpSrcReg1, hiIndex, loIndex);
                uint64_t arg2Bits = bits(FpSrcReg2, hiIndex, loIndex);
                uint64_t resBits = arg1Bits - arg2Bits;
                if (ext & 0x2) {
                    if (signedOp()) {
                        int arg1Sign = bits(arg1Bits, sizeBits - 1);
                        int arg2Sign = !bits(arg2Bits, sizeBits - 1);
                        int resSign = bits(resBits, sizeBits - 1);
                        if ((arg1Sign == arg2Sign) && (arg1Sign != resSign)) {
                            if (resSign == 0)
                                resBits = (ULL(1) << (sizeBits - 1));
                            else
                                resBits = mask(sizeBits - 1);
                        }
                    } else {
                        if (arg2Bits > arg1Bits) {
                            resBits = 0;
                        } else if (!findCarry(sizeBits, resBits,
                                             arg1Bits, ~arg2Bits)) {
                            resBits = mask(sizeBits);
                        }
                    }
                }
                result = insertBits(result, hiIndex, loIndex, resBits);
            }
            FpDestReg = result;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Mmuli::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
FpDestReg = xc->readFloatRegOperandBits(this, 2);
;

            
            int srcBits = srcSize * 8;
            int destBits = destSize * 8;
            assert(destBits <= 64);
            assert(destSize >= srcSize);
            int items = numItems(destSize);
            uint64_t result = FpDestReg;
            for (int i = 0; i < items; i++) {
                int offset = 0;
                if (ext & 16) {
                    if (ext & 32)
                        offset = i * (destBits - srcBits);
                    else
                        offset = i * (destBits - srcBits) + srcBits;
                }
                int srcHiIndex = (i + 1) * srcBits - 1 + offset;
                int srcLoIndex = (i + 0) * srcBits + offset;
                uint64_t arg1Bits = bits(FpSrcReg1, srcHiIndex, srcLoIndex);
                uint64_t arg2Bits = bits(FpSrcReg2, srcHiIndex, srcLoIndex);
                uint64_t resBits;
                if (signedOp()) {
                    int64_t arg1 = arg1Bits |
                        (0 - (arg1Bits & (ULL(1) << (srcBits - 1))));
                    int64_t arg2 = arg2Bits |
                        (0 - (arg2Bits & (ULL(1) << (srcBits - 1))));
                    resBits = (uint64_t)(arg1 * arg2);
                } else {
                    resBits = arg1Bits * arg2Bits;
                }
                if (ext & 0x4)
                    resBits += (ULL(1) << (destBits - 1));
                if (multHi())
                    resBits >>= destBits;
                int destHiIndex = (i + 1) * destBits - 1;
                int destLoIndex = (i + 0) * destBits;
                result = insertBits(result, destHiIndex, destLoIndex, resBits);
            }
            FpDestReg = result;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Mavg::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
FpDestReg = xc->readFloatRegOperandBits(this, 2);
;

            
            assert(srcSize == destSize);
            int size = srcSize;
            int sizeBits = size * 8;
            int items = numItems(size);
            uint64_t result = FpDestReg;
            for (int i = 0; i < items; i++) {
                int hiIndex = (i + 1) * sizeBits - 1;
                int loIndex = (i + 0) * sizeBits;
                uint64_t arg1Bits = bits(FpSrcReg1, hiIndex, loIndex);
                uint64_t arg2Bits = bits(FpSrcReg2, hiIndex, loIndex);
                uint64_t resBits = (arg1Bits + arg2Bits + 1) / 2;
                result = insertBits(result, hiIndex, loIndex, resBits);
            }
            FpDestReg = result;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Msad::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
;

            
            int srcBits = srcSize * 8;
            int items = sizeof(FloatRegBits) / srcSize;
            uint64_t sum = 0;
            for (int i = 0; i < items; i++) {
                int hiIndex = (i + 1) * srcBits - 1;
                int loIndex = (i + 0) * srcBits;
                uint64_t arg1Bits = bits(FpSrcReg1, hiIndex, loIndex);
                uint64_t arg2Bits = bits(FpSrcReg2, hiIndex, loIndex);
                int64_t resBits = arg1Bits - arg2Bits;
                if (resBits < 0)
                    resBits = -resBits;
                sum += resBits;
            }
            FpDestReg = sum & mask(destSize * 8);
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Msrl::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
FpDestReg = xc->readFloatRegOperandBits(this, 2);
;

            
            assert(srcSize == destSize);
            int size = srcSize;
            int sizeBits = size * 8;
            int items = numItems(size);
            uint64_t shiftAmt = FpSrcReg2;
            uint64_t result = FpDestReg;
            for (int i = 0; i < items; i++) {
                int hiIndex = (i + 1) * sizeBits - 1;
                int loIndex = (i + 0) * sizeBits;
                uint64_t arg1Bits = bits(FpSrcReg1, hiIndex, loIndex);
                uint64_t resBits;
                if (shiftAmt >= sizeBits) {
                    resBits = 0;
                } else {
                    resBits = (arg1Bits >> shiftAmt) &
                        mask(sizeBits - shiftAmt);
                }
                result = insertBits(result, hiIndex, loIndex, resBits);
            }
            FpDestReg = result;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault MsrlImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpDestReg = xc->readFloatRegOperandBits(this, 1);
;

            
            assert(srcSize == destSize);
            int size = srcSize;
            int sizeBits = size * 8;
            int items = numItems(size);
            uint64_t shiftAmt = imm8;
            uint64_t result = FpDestReg;
            for (int i = 0; i < items; i++) {
                int hiIndex = (i + 1) * sizeBits - 1;
                int loIndex = (i + 0) * sizeBits;
                uint64_t arg1Bits = bits(FpSrcReg1, hiIndex, loIndex);
                uint64_t resBits;
                if (shiftAmt >= sizeBits) {
                    resBits = 0;
                } else {
                    resBits = (arg1Bits >> shiftAmt) &
                        mask(sizeBits - shiftAmt);
                }
                result = insertBits(result, hiIndex, loIndex, resBits);
            }
            FpDestReg = result;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Msra::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
FpDestReg = xc->readFloatRegOperandBits(this, 2);
;

            
            assert(srcSize == destSize);
            int size = srcSize;
            int sizeBits = size * 8;
            int items = numItems(size);
            uint64_t shiftAmt = FpSrcReg2;
            uint64_t result = FpDestReg;
            for (int i = 0; i < items; i++) {
                int hiIndex = (i + 1) * sizeBits - 1;
                int loIndex = (i + 0) * sizeBits;
                uint64_t arg1Bits = bits(FpSrcReg1, hiIndex, loIndex);
                uint64_t resBits;
                if (shiftAmt >= sizeBits) {
                    if (bits(arg1Bits, sizeBits - 1))
                        resBits = mask(sizeBits);
                    else
                        resBits = 0;
                } else {
                    resBits = (arg1Bits >> shiftAmt);
                    resBits = resBits |
                        (0 - (resBits & (ULL(1) << (sizeBits - 1 - shiftAmt))));
                }
                result = insertBits(result, hiIndex, loIndex, resBits);
            }
            FpDestReg = result;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault MsraImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpDestReg = xc->readFloatRegOperandBits(this, 1);
;

            
            assert(srcSize == destSize);
            int size = srcSize;
            int sizeBits = size * 8;
            int items = numItems(size);
            uint64_t shiftAmt = imm8;
            uint64_t result = FpDestReg;
            for (int i = 0; i < items; i++) {
                int hiIndex = (i + 1) * sizeBits - 1;
                int loIndex = (i + 0) * sizeBits;
                uint64_t arg1Bits = bits(FpSrcReg1, hiIndex, loIndex);
                uint64_t resBits;
                if (shiftAmt >= sizeBits) {
                    if (bits(arg1Bits, sizeBits - 1))
                        resBits = mask(sizeBits);
                    else
                        resBits = 0;
                } else {
                    resBits = (arg1Bits >> shiftAmt);
                    resBits = resBits |
                        (0 - (resBits & (ULL(1) << (sizeBits - 1 - shiftAmt))));
                }
                result = insertBits(result, hiIndex, loIndex, resBits);
            }
            FpDestReg = result;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Msll::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
FpDestReg = xc->readFloatRegOperandBits(this, 2);
;

            
            assert(srcSize == destSize);
            int size = srcSize;
            int sizeBits = size * 8;
            int items = numItems(size);
            uint64_t shiftAmt = FpSrcReg2;
            uint64_t result = FpDestReg;
            for (int i = 0; i < items; i++) {
                int hiIndex = (i + 1) * sizeBits - 1;
                int loIndex = (i + 0) * sizeBits;
                uint64_t arg1Bits = bits(FpSrcReg1, hiIndex, loIndex);
                uint64_t resBits;
                if (shiftAmt >= sizeBits) {
                    resBits = 0;
                } else {
                    resBits = (arg1Bits << shiftAmt);
                }
                result = insertBits(result, hiIndex, loIndex, resBits);
            }
            FpDestReg = result;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault MsllImm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpDestReg = xc->readFloatRegOperandBits(this, 1);
;

            
            assert(srcSize == destSize);
            int size = srcSize;
            int sizeBits = size * 8;
            int items = numItems(size);
            uint64_t shiftAmt = imm8;
            uint64_t result = FpDestReg;
            for (int i = 0; i < items; i++) {
                int hiIndex = (i + 1) * sizeBits - 1;
                int loIndex = (i + 0) * sizeBits;
                uint64_t arg1Bits = bits(FpSrcReg1, hiIndex, loIndex);
                uint64_t resBits;
                if (shiftAmt >= sizeBits) {
                    resBits = 0;
                } else {
                    resBits = (arg1Bits << shiftAmt);
                }
                result = insertBits(result, hiIndex, loIndex, resBits);
            }
            FpDestReg = result;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Cvtf2i::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpDestReg = xc->readFloatRegOperandBits(this, 1);
;

            
            union floatInt
            {
                float f;
                uint32_t i;
            };
            union doubleInt
            {
                double d;
                uint64_t i;
            };
            assert(destSize == 4 || destSize == 8);
            assert(srcSize == 4 || srcSize == 8);
            int srcSizeBits = srcSize * 8;
            int destSizeBits = destSize * 8;
            int items;
            int srcStart = 0;
            int destStart = 0;
            if (srcSize == 2 * destSize) {
                items = numItems(srcSize);
                if (ext & 0x2)
                    destStart = destSizeBits * items;
            } else if (destSize == 2 * srcSize) {
                items = numItems(destSize);
                if (ext & 0x2)
                    srcStart = srcSizeBits * items;
            } else {
                items = numItems(destSize);
            }
            uint64_t result = FpDestReg;
            for (int i = 0; i < items; i++) {
                int srcHiIndex = srcStart + (i + 1) * srcSizeBits - 1;
                int srcLoIndex = srcStart + (i + 0) * srcSizeBits;
                uint64_t argBits = bits(FpSrcReg1, srcHiIndex, srcLoIndex);
                double arg;
                if (srcSize == 4) {
                    floatInt fi;
                    fi.i = argBits;
                    arg = fi.f;
                } else {
                    doubleInt di;
                    di.i = argBits;
                    arg = di.d;
                }
                if (ext & 0x4) {
                    if (arg >= 0)
                        arg += 0.5;
                    else
                        arg -= 0.5;
                }
                if (destSize == 4) {
                    argBits = (uint32_t)arg;
                } else {
                    argBits = (uint64_t)arg;
                }
                int destHiIndex = destStart + (i + 1) * destSizeBits - 1;
                int destLoIndex = destStart + (i + 0) * destSizeBits;
                result = insertBits(result, destHiIndex, destLoIndex, argBits);
            }
            FpDestReg = result;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Cvti2f::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpDestReg = xc->readFloatRegOperandBits(this, 1);
;

            
            union floatInt
            {
                float f;
                uint32_t i;
            };
            union doubleInt
            {
                double d;
                uint64_t i;
            };
            assert(destSize == 4 || destSize == 8);
            assert(srcSize == 4 || srcSize == 8);
            int srcSizeBits = srcSize * 8;
            int destSizeBits = destSize * 8;
            int items;
            int srcStart = 0;
            int destStart = 0;
            if (srcSize == 2 * destSize) {
                items = numItems(srcSize);
                if (ext & 0x2)
                    destStart = destSizeBits * items;
            } else if (destSize == 2 * srcSize) {
                items = numItems(destSize);
                if (ext & 0x2)
                    srcStart = srcSizeBits * items;
            } else {
                items = numItems(destSize);
            }
            uint64_t result = FpDestReg;
            for (int i = 0; i < items; i++) {
                int srcHiIndex = srcStart + (i + 1) * srcSizeBits - 1;
                int srcLoIndex = srcStart + (i + 0) * srcSizeBits;
                uint64_t argBits = bits(FpSrcReg1, srcHiIndex, srcLoIndex);
                int64_t sArg = argBits |
                    (0 - (argBits & (ULL(1) << (srcSizeBits - 1))));
                double arg = sArg;
                if (destSize == 4) {
                    floatInt fi;
                    fi.f = arg;
                    argBits = fi.i;
                } else {
                    doubleInt di;
                    di.d = arg;
                    argBits = di.i;
                }
                int destHiIndex = destStart + (i + 1) * destSizeBits - 1;
                int destLoIndex = destStart + (i + 0) * destSizeBits;
                result = insertBits(result, destHiIndex, destLoIndex, argBits);
            }
            FpDestReg = result;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Cvtf2f::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpDestReg = xc->readFloatRegOperandBits(this, 1);
;

            
            union floatInt
            {
                float f;
                uint32_t i;
            };
            union doubleInt
            {
                double d;
                uint64_t i;
            };
            assert(destSize == 4 || destSize == 8);
            assert(srcSize == 4 || srcSize == 8);
            int srcSizeBits = srcSize * 8;
            int destSizeBits = destSize * 8;
            int items;
            int srcStart = 0;
            int destStart = 0;
            if (srcSize == 2 * destSize) {
                items = numItems(srcSize);
                if (ext & 0x2)
                    destStart = destSizeBits * items;
            } else if (destSize == 2 * srcSize) {
                items = numItems(destSize);
                if (ext & 0x2)
                    srcStart = srcSizeBits * items;
            } else {
                items = numItems(destSize);
            }
            uint64_t result = FpDestReg;
            for (int i = 0; i < items; i++) {
                int srcHiIndex = srcStart + (i + 1) * srcSizeBits - 1;
                int srcLoIndex = srcStart + (i + 0) * srcSizeBits;
                uint64_t argBits = bits(FpSrcReg1, srcHiIndex, srcLoIndex);
                double arg;
                if (srcSize == 4) {
                    floatInt fi;
                    fi.i = argBits;
                    arg = fi.f;
                } else {
                    doubleInt di;
                    di.i = argBits;
                    arg = di.d;
                }
                if (destSize == 4) {
                    floatInt fi;
                    fi.f = arg;
                    argBits = fi.i;
                } else {
                    doubleInt di;
                    di.d = arg;
                    argBits = di.i;
                }
                int destHiIndex = destStart + (i + 1) * destSizeBits - 1;
                int destLoIndex = destStart + (i + 0) * destSizeBits;
                result = insertBits(result, destHiIndex, destLoIndex, argBits);
            }
            FpDestReg = result;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Mcmpi2r::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
FpDestReg = xc->readFloatRegOperandBits(this, 2);
;

            
            union floatInt
            {
                float f;
                uint32_t i;
            };
            union doubleInt
            {
                double d;
                uint64_t i;
            };
            assert(srcSize == destSize);
            int size = srcSize;
            int sizeBits = size * 8;
            int items = numItems(size);
            uint64_t result = FpDestReg;
            for (int i = 0; i < items; i++) {
                int hiIndex = (i + 1) * sizeBits - 1;
                int loIndex = (i + 0) * sizeBits;
                uint64_t arg1Bits = bits(FpSrcReg1, hiIndex, loIndex);
                int64_t arg1 = arg1Bits |
                    (0 - (arg1Bits & (ULL(1) << (sizeBits - 1))));
                uint64_t arg2Bits = bits(FpSrcReg2, hiIndex, loIndex);
                int64_t arg2 = arg2Bits |
                    (0 - (arg2Bits & (ULL(1) << (sizeBits - 1))));
                uint64_t resBits = 0;
                if (((ext & 0x2) == 0 && arg1 == arg2) ||
                    ((ext & 0x2) == 0x2 && arg1 > arg2))
                    resBits = mask(sizeBits);
                result = insertBits(result, hiIndex, loIndex, resBits);
            }
            FpDestReg = result;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Mcmpf2r::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t FpDestReg = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
FpDestReg = xc->readFloatRegOperandBits(this, 2);
;

            
            union floatInt
            {
                float f;
                uint32_t i;
            };
            union doubleInt
            {
                double d;
                uint64_t i;
            };
            assert(srcSize == destSize);
            int size = srcSize;
            int sizeBits = size * 8;
            int items = numItems(size);
            uint64_t result = FpDestReg;
            for (int i = 0; i < items; i++) {
                int hiIndex = (i + 1) * sizeBits - 1;
                int loIndex = (i + 0) * sizeBits;
                uint64_t arg1Bits = bits(FpSrcReg1, hiIndex, loIndex);
                uint64_t arg2Bits = bits(FpSrcReg2, hiIndex, loIndex);
                double arg1, arg2;
                if (size == 4) {
                    floatInt fi;
                    fi.i = arg1Bits;
                    arg1 = fi.f;
                    fi.i = arg2Bits;
                    arg2 = fi.f;
                } else {
                    doubleInt di;
                    di.i = arg1Bits;
                    arg1 = di.d;
                    di.i = arg2Bits;
                    arg2 = di.d;
                }
                uint64_t resBits = 0;
                bool nanop = std::isnan(arg1) || std::isnan(arg2);
                switch (ext & mask(3)) {
                  case 0:
                    if (arg1 == arg2 && !nanop)
                        resBits = mask(sizeBits);
                    break;
                  case 1:
                    if (arg1 < arg2 && !nanop)
                        resBits = mask(sizeBits);
                    break;
                  case 2:
                    if (arg1 <= arg2 && !nanop)
                        resBits = mask(sizeBits);
                    break;
                  case 3:
                    if (nanop)
                        resBits = mask(sizeBits);
                    break;
                  case 4:
                    if (arg1 != arg2 || nanop)
                        resBits = mask(sizeBits);
                    break;
                  case 5:
                    if (!(arg1 < arg2) || nanop)
                        resBits = mask(sizeBits);
                    break;
                  case 6:
                    if (!(arg1 <= arg2) || nanop)
                        resBits = mask(sizeBits);
                    break;
                  case 7:
                    if (!nanop)
                        resBits = mask(sizeBits);
                    break;
                };
                result = insertBits(result, hiIndex, loIndex, resBits);
            }
            FpDestReg = result;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        {
            uint64_t final_val = FpDestReg;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Mcmpf2rf::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint64_t FpSrcReg1 = 0;
uint64_t FpSrcReg2 = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
;
            FpSrcReg1 = xc->readFloatRegOperandBits(this, 0);
FpSrcReg2 = xc->readFloatRegOperandBits(this, 1);
ccFlagBits = xc->readCCRegOperand(this, 2);
cfofBits = xc->readCCRegOperand(this, 3);
;

            
            union floatInt
            {
                float f;
                uint32_t i;
            };
            union doubleInt
            {
                double d;
                uint64_t i;
            };
            assert(srcSize == destSize);
            assert(srcSize == 4 || srcSize == 8);
            int size = srcSize;
            int sizeBits = size * 8;
            double arg1, arg2;
            uint64_t arg1Bits = bits(FpSrcReg1, sizeBits - 1, 0);
            uint64_t arg2Bits = bits(FpSrcReg2, sizeBits - 1, 0);
            if (size == 4) {
                floatInt fi;
                fi.i = arg1Bits;
                arg1 = fi.f;
                fi.i = arg2Bits;
                arg2 = fi.f;
            } else {
                doubleInt di;
                di.i = arg1Bits;
                arg1 = di.d;
                di.i = arg2Bits;
                arg2 = di.d;
            }
            //               ZF PF CF
            // Unordered      1  1  1
            // Greater than   0  0  0
            // Less than      0  0  1
            // Equal          1  0  0
            //           OF = SF = AF = 0
            ccFlagBits = ccFlagBits & ~(SFBit | AFBit | ZFBit | PFBit);
            cfofBits   = cfofBits   & ~(OFBit | CFBit);
            if (std::isnan(arg1) || std::isnan(arg2)) {
                ccFlagBits = ccFlagBits | (ZFBit | PFBit);
                cfofBits = cfofBits | CFBit;
            }
            else if(arg1 < arg2)
                cfofBits = cfofBits | CFBit;
            else if(arg1 == arg2)
                ccFlagBits = ccFlagBits | ZFBit;
        ;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = ccFlagBits;
            xc->setCCRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = cfofBits;
            xc->setCCRegOperand(this, 1, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

        Fault Emms::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            uint16_t FTW = 0;
;
            ;

            FTW = 0xFFFF;;

            //Write the resulting state to the execution context
            if(fault == NoFault)
            {
                xc->setMiscRegOperand(this, 0, FTW);
if (traceData) { traceData->setData(FTW); };
            }
            return fault;
        }

        Fault MicroBranchFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            uint64_t nuIP = 0;
uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
TheISA::PCState __parserAutoPCState;
;
            __parserAutoPCState = xc->pcState();
nuIP = __parserAutoPCState.nupc();
ccFlagBits = xc->readCCRegOperand(this, 0);
cfofBits = xc->readCCRegOperand(this, 1);
dfBit = xc->readCCRegOperand(this, 2);
ecfBit = xc->readCCRegOperand(this, 3);
ezfBit = xc->readCCRegOperand(this, 4);
;
            if (checkCondition(ccFlagBits | cfofBits | dfBit |                                           ecfBit | ezfBit, cc)) {
                nuIP = target;;
            } else {
                nuIP = nuIP;;
            }
            __parserAutoPCState.nupc(nuIP);
xc->pcState(__parserAutoPCState);
;
            return NoFault;
        }

        Fault MicroBranch::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            uint64_t nuIP = 0;
TheISA::PCState __parserAutoPCState;
;
            __parserAutoPCState = xc->pcState();
nuIP = __parserAutoPCState.nupc();
;
            if (true) {
                nuIP = target;;
            } else {
                nuIP = nuIP;;
            }
            __parserAutoPCState.nupc(nuIP);
xc->pcState(__parserAutoPCState);
;
            return NoFault;
        }

        Fault EretFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
;
            ccFlagBits = xc->readCCRegOperand(this, 0);
cfofBits = xc->readCCRegOperand(this, 1);
dfBit = xc->readCCRegOperand(this, 2);
ecfBit = xc->readCCRegOperand(this, 3);
ezfBit = xc->readCCRegOperand(this, 4);
;
            if (checkCondition(ccFlagBits | cfofBits | dfBit |                                           ecfBit | ezfBit, cc)) {
                ;
            } else {
                ;
            }
            ;
            return NoFault;
        }

        Fault Eret::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            ;
            ;
            if (true) {
                ;
            } else {
                ;
            }
            ;
            return NoFault;
        }

    Fault
    MicroHalt::execute(CPU_EXEC_CONTEXT *xc,
            Trace::InstRecord * traceData) const
    {
        xc->tcBase()->suspend();
        return NoFault;
    }

        Fault MicroFaultFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;
;
            ccFlagBits = xc->readCCRegOperand(this, 0);
cfofBits = xc->readCCRegOperand(this, 1);
dfBit = xc->readCCRegOperand(this, 2);
ecfBit = xc->readCCRegOperand(this, 3);
ezfBit = xc->readCCRegOperand(this, 4);
;
            if (checkCondition(ccFlagBits | cfofBits | dfBit |                                           ecfBit | ezfBit, cc)) {
                //Return the fault we were constructed with
                return fault;
            } else {
                return NoFault;
            }
        }

        Fault MicroFault::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            ;
            ;
            if (true) {
                //Return the fault we were constructed with
                return fault;
            } else {
                return NoFault;
            }
        }

        Fault Mfence::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            ;
            ;
            ;

            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

        Fault
        MicroPanicFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;

            ccFlagBits = xc->readCCRegOperand(this, 0);
cfofBits = xc->readCCRegOperand(this, 1);
dfBit = xc->readCCRegOperand(this, 2);
ecfBit = xc->readCCRegOperand(this, 3);
ezfBit = xc->readCCRegOperand(this, 4);

            if (checkCondition(ccFlagBits | cfofBits |                                               dfBit | ecfBit | ezfBit, cc)) {
                return std::make_shared<GenericISA::M5DebugFault>(func,
                                                                  message);
            } else {
                return NoFault;
            }
        }

        Fault
        MicroPanic::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            
            
            if (true) {
                return std::make_shared<GenericISA::M5DebugFault>(func,
                                                                  message);
            } else {
                return NoFault;
            }
        }

        Fault
        MicroFatalFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;

            ccFlagBits = xc->readCCRegOperand(this, 0);
cfofBits = xc->readCCRegOperand(this, 1);
dfBit = xc->readCCRegOperand(this, 2);
ecfBit = xc->readCCRegOperand(this, 3);
ezfBit = xc->readCCRegOperand(this, 4);

            if (checkCondition(ccFlagBits | cfofBits |                                               dfBit | ecfBit | ezfBit, cc)) {
                return std::make_shared<GenericISA::M5DebugFault>(func,
                                                                  message);
            } else {
                return NoFault;
            }
        }

        Fault
        MicroFatal::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            
            
            if (true) {
                return std::make_shared<GenericISA::M5DebugFault>(func,
                                                                  message);
            } else {
                return NoFault;
            }
        }

        Fault
        MicroWarnFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;

            ccFlagBits = xc->readCCRegOperand(this, 0);
cfofBits = xc->readCCRegOperand(this, 1);
dfBit = xc->readCCRegOperand(this, 2);
ecfBit = xc->readCCRegOperand(this, 3);
ezfBit = xc->readCCRegOperand(this, 4);

            if (checkCondition(ccFlagBits | cfofBits |                                               dfBit | ecfBit | ezfBit, cc)) {
                return std::make_shared<GenericISA::M5DebugFault>(func,
                                                                  message);
            } else {
                return NoFault;
            }
        }

        Fault
        MicroWarn::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            
            
            if (true) {
                return std::make_shared<GenericISA::M5DebugFault>(func,
                                                                  message);
            } else {
                return NoFault;
            }
        }

        Fault
        MicroWarn_onceFlags::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            uint64_t ccFlagBits = 0;
uint64_t cfofBits = 0;
uint64_t dfBit = 0;
uint64_t ecfBit = 0;
uint64_t ezfBit = 0;

            ccFlagBits = xc->readCCRegOperand(this, 0);
cfofBits = xc->readCCRegOperand(this, 1);
dfBit = xc->readCCRegOperand(this, 2);
ecfBit = xc->readCCRegOperand(this, 3);
ezfBit = xc->readCCRegOperand(this, 4);

            if (checkCondition(ccFlagBits | cfofBits |                                               dfBit | ecfBit | ezfBit, cc)) {
                return std::make_shared<GenericISA::M5DebugFault>(func,
                                                                  message);
            } else {
                return NoFault;
            }
        }

        Fault
        MicroWarn_once::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            
            
            if (true) {
                return std::make_shared<GenericISA::M5DebugFault>(func,
                                                                  message);
            } else {
                return NoFault;
            }
        }

// Inst::UD2([],{})

// WarnUnimpl::push_ES(([], {}))

// Inst::UD2([],{})

// WarnUnimpl::pop_ES(([], {}))

// MultiInst::ADD((['OPCODE_OP_BOTTOM3', ['Gb'], ['Gv'], [], [], [], []], {}))

// Inst::UD2([],{})

// WarnUnimpl::push_CS(([], {}))

// M5InternalError::error((['"Saw a one byte opcode whose value was 0x0F!"'], {}))

// MultiInst::OR((['OPCODE_OP_BOTTOM3', ['Gb'], ['Gv'], [], [], [], []], {}))

// Inst::UD2([],{})

// WarnUnimpl::push_SS(([], {}))

// Inst::UD2([],{})

// WarnUnimpl::pop_SS(([], {}))

// MultiInst::ADC((['OPCODE_OP_BOTTOM3', ['Gb'], ['Gv'], [], [], [], []], {}))

// Inst::UD2([],{})

// WarnUnimpl::push_DS(([], {}))

// Inst::UD2([],{})

// WarnUnimpl::pop_DS(([], {}))

// MultiInst::SBB((['OPCODE_OP_BOTTOM3', ['Gb'], ['Gv'], [], [], [], []], {}))

// M5InternalError::error((['"Tried to execute the ES segment override prefix!"'], {}))

// Inst::UD2([],{})

// WarnUnimpl::daa(([], {}))

// MultiInst::AND((['OPCODE_OP_BOTTOM3', ['Gb'], ['Gv'], [], [], [], []], {}))

// M5InternalError::error((['"Tried to execute the CS segment override prefix!"'], {}))

// Inst::UD2([],{})

// WarnUnimpl::das(([], {}))

// MultiInst::SUB((['OPCODE_OP_BOTTOM3', ['Gb'], ['Gv'], [], [], [], []], {}))

// M5InternalError::error((['"Tried to execute the SS segment override prefix!"'], {}))

// Inst::UD2([],{})

// WarnUnimpl::aaa(([], {}))

// MultiInst::XOR((['OPCODE_OP_BOTTOM3', ['Gb'], ['Gv'], [], [], [], []], {}))

// M5InternalError::error((['"Tried to execute the DS segment override prefix!"'], {}))

// Inst::UD2([],{})

// WarnUnimpl::aas(([], {}))

// MultiInst::CMP((['OPCODE_OP_BOTTOM3', ['Gb'], ['Gv'], [], [], [], []], {}))

// M5InternalError::error((['"Tried to execute an REX prefix!"'], {}))

// Inst::INC(['Bv'],{})

// M5InternalError::error((['"Tried to execute an REX prefix!"'], {}))

// Inst::DEC(['Bv'],{})

// Inst::PUSH(['Bv'],{})

// Inst::POP(['Bv'],{})

// Inst::UD2([],{})

// Inst::PUSHA([],{})

// Inst::UD2([],{})

// Inst::POPA([],{})

// Inst::UD2([],{})

// Inst::BOUND(['Gv', 'Mv'],{})

// Inst::MOVSXD(['Gv', 'Ev'],{})

// WarnUnimpl::arpl_Ew_Gw(([], {}))

// M5InternalError::error((['"Tried to execute the FS segment override prefix!"'], {}))

// M5InternalError::error((['"Tried to execute the GS segment override prefix!"'], {}))

// M5InternalError::error((['"Tried to execute the operand size override prefix!"'], {}))

// M5InternalError::error((['"Tried to execute the DS address size override prefix!"'], {}))

// Unknown::unknown(([], {}))

// Inst::PUSH(['Iz'],{})

// Inst::IMUL(['Gv', 'Ev', 'Iz'],{})

// Inst::PUSH(['Ib'],{})

// Inst::IMUL(['Gv', 'Ev', 'Ib'],{})

// StringInst::INS((['Yb', 'rD'], {}))

// StringInst::INS((['Yz', 'rD'], {}))

// StringInst::OUTS((['rD', 'Xb'], {}))

// StringInst::OUTS((['rD', 'Xz'], {}))

// Unknown::unknown(([], {}))

// Inst::JO(['Jb'],{})

// Inst::JNO(['Jb'],{})

// Inst::JB(['Jb'],{})

// Inst::JNB(['Jb'],{})

// Inst::JZ(['Jb'],{})

// Inst::JNZ(['Jb'],{})

// Inst::JBE(['Jb'],{})

// Inst::JNBE(['Jb'],{})

// Unknown::unknown(([], {}))

// Inst::JS(['Jb'],{})

// Inst::JNS(['Jb'],{})

// Inst::JP(['Jb'],{})

// Inst::JNP(['Jb'],{})

// Inst::JL(['Jb'],{})

// Inst::JNL(['Jb'],{})

// Inst::JLE(['Jb'],{})

// Inst::JNLE(['Jb'],{})

// Unknown::unknown(([], {}))

// Inst::ADD(['Eb', 'Ib'],{})

// Inst::OR(['Eb', 'Ib'],{})

// Inst::ADC(['Eb', 'Ib'],{})

// Inst::SBB(['Eb', 'Ib'],{})

// Inst::AND(['Eb', 'Ib'],{})

// Inst::SUB(['Eb', 'Ib'],{})

// Inst::XOR(['Eb', 'Ib'],{})

// Inst::CMP(['Eb', 'Ib'],{})

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

// Inst::TEST(['Ev', 'Gv'],{})

// Inst::XCHG(['Eb', 'Gb'],{})

// Inst::XCHG(['Ev', 'Gv'],{})

// Unknown::unknown(([], {}))

// Inst::MOV(['Eb', 'Gb'],{})

// Inst::MOV(['Ev', 'Gv'],{})

// Inst::MOV(['Gb', 'Eb'],{})

// Inst::MOV(['Gv', 'Ev'],{})

// Inst::MOV(['Ev', 'Sv'],{})

// Unknown::unknown(([], {}))

// Inst::LEA(['Gv', 'M'],{})

// Inst::MOV_REAL(['Sv', 'Ev'],{})

// Inst::UD2([],{})

// Inst::MOVSS(['Sv', 'Ev'],{})

// Inst::MOV(['Sv', 'Ev'],{})

// Inst::UD2([],{})

// Inst::POP(['Ev'],{})

// Inst::UD2([],{})

// Unknown::unknown(([], {}))

// NopInst::NOP(([], {}))

    Fault NOP::execute(CPU_EXEC_CONTEXT *xc,
            Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// Inst::XCHG(['Bv', 'rAv'],{})

// Inst::CDQE(['rAv'],{})

// Inst::CQO(['rAv', 'rDv'],{})

// Inst::UD2([],{})

// WarnUnimpl::call_far_Ap(([], {}))

// WarnUnimpl::fwait(([], {}))

// Inst::PUSHF([],{})

// Inst::POPF([],{})

// Inst::SAHF([],{})

// Inst::LAHF([],{})

// Unknown::unknown(([], {}))

// Inst::MOV(['rAb', 'Ob'],{})

// Inst::MOV(['rAv', 'Ov'],{})

// Inst::MOV(['Ob', 'rAb'],{})

// Inst::MOV(['Ov', 'rAv'],{})

// StringInst::MOVS((['Yb', 'Xb'], {}))

// StringInst::MOVS((['Yv', 'Xv'], {}))

// StringTestInst::CMPS((['Yb', 'Xb'], {}))

// StringTestInst::CMPS((['Yv', 'Xv'], {}))

// Unknown::unknown(([], {}))

// Inst::TEST(['rAb', 'Ib'],{})

// Inst::TEST(['rAv', 'Iz'],{})

// StringInst::STOS((['Yb'], {}))

// StringInst::STOS((['Yv'], {}))

// StringInst::LODS((['Xb'], {}))

// StringInst::LODS((['Xv'], {}))

// StringTestInst::SCAS((['Yb'], {}))

// StringTestInst::SCAS((['Yv'], {}))

// Unknown::unknown(([], {}))

// Inst::MOV(['Bb', 'Ib'],{})

// Inst::MOV(['Bv', 'Iv'],{})

// Inst::ROL(['Eb', 'Ib'],{})

// Inst::ROR(['Eb', 'Ib'],{})

// Inst::RCL(['Eb', 'Ib'],{})

// Inst::RCR(['Eb', 'Ib'],{})

// Inst::SAL(['Eb', 'Ib'],{})

// Inst::SHR(['Eb', 'Ib'],{})

// Inst::SAL(['Eb', 'Ib'],{})

// Inst::SAR(['Eb', 'Ib'],{})

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

// Inst::RET_NEAR([],{})

// Inst::UD2([],{})

// WarnUnimpl::les_Gz_Mp(([], {}))

// Inst::UD2([],{})

// WarnUnimpl::lds_Gz_Mp(([], {}))

// Inst::MOV(['Eb', 'Ib'],{})

// Inst::UD2([],{})

// Inst::MOV(['Ev', 'Iz'],{})

// Inst::UD2([],{})

// Unknown::unknown(([], {}))

// Inst::ENTER((['Iw', 'Iw'], {}))

// Inst::LEAVE(([], {}))

// WarnUnimpl::ret_far_Iw([],{})

// WarnUnimpl::ret_far_real([],{})

// Inst::RET_FAR(([], {}))

// Inst::INT3(([], {}))

// SyscallInst::int80((['xc->syscall(Rax)', 'IsSyscall', 'IsNonSpeculative', 'IsSerializeAfter'], {}))

    Fault Int80::execute(CPU_EXEC_CONTEXT *xc,
            Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;
        uint64_t Rax = 0;
;
        Rax = xc->readIntRegOperand(this, 0);
;
        xc->syscall(Rax);
        return fault;
    }

// WarnUnimpl::inst_ib([],{})

// Inst::INT((['Ib'], {}))

// Inst::UD2(([], {}))

// WarnUnimpl::into([],{})

// Inst::IRET_REAL(([], {}))

// Inst::IRET_VIRT(([], {}))

// Inst::IRET_PROT(([], {}))

// Unknown::unknown(([], {}))

// Inst::ROL_1(['Eb'],{})

// Inst::ROR_1(['Eb'],{})

// Inst::RCL_1(['Eb'],{})

// Inst::RCR_1(['Eb'],{})

// Inst::SAL_1(['Eb'],{})

// Inst::SHR_1(['Eb'],{})

// Inst::SAL_1(['Eb'],{})

// Inst::SAR_1(['Eb'],{})

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

// Inst::ROR(['Eb', 'rCb'],{})

// Inst::RCL(['Eb', 'rCb'],{})

// Inst::RCR(['Eb', 'rCb'],{})

// Inst::SAL(['Eb', 'rCb'],{})

// Inst::SHR(['Eb', 'rCb'],{})

// Inst::SAL(['Eb', 'rCb'],{})

// Inst::SAR(['Eb', 'rCb'],{})

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

// Inst::XLAT([],{})

// Unknown::unknown(([], {}))

// Inst::FADD1((['Eq'], {}))

// Inst::FADD1((['Md'], {}))

// Inst::FMUL1((['Eq'], {}))

// Inst::FMUL1((['Md'], {}))

// WarnUnimpl::fcom([],{})

// WarnUnimpl::fcomp([],{})

// Inst::FSUB1((['Eq'], {}))

// Inst::FSUB1((['Md'], {}))

// WarnUnimpl::fsubr([],{})

// Inst::FDIV1((['Eq'], {}))

// Inst::FDIV1((['Md'], {}))

// WarnUnimpl::fdivr([],{})

// Unknown::unknown(([], {}))

// Inst::FLD((['Eq'], {}))

// Inst::FLD((['Md'], {}))

// Inst::FXCH((['Eq'], {}))

// Inst::UD2(([], {}))

// WarnUnimpl::fnop([],{})

// Inst::UD2(([], {}))

// Inst::FST((['Ed'], {}))

// Inst::UD2(([], {}))

// Inst::FSTP((['Ed'], {}))

// Inst::FCHS(([], {}))

// Inst::FABS(([], {}))

// WarnUnimpl::ftst([],{})

// WarnUnimpl::fxam([],{})

// Inst::UD2(([], {}))

// Inst::FLDENV((['M'], {}))

// Inst::FLD1(([], {}))

// Inst::FLDL2T(([], {}))

// Inst::FLDL2E(([], {}))

// Inst::FLDPI(([], {}))

// Inst::FLDLG2(([], {}))

// Inst::FLDLN2(([], {}))

// Inst::FLDZ(([], {}))

// Unknown::unknown(([], {}))

// Inst::FLDCW((['Mw'], {}))

// WarnUnimpl::f2xm1([],{})

// Inst::FYL2X(([], {}))

// Inst::FPTAN(([], {}))

// WarnUnimpl::fpatan([],{})

// WarnUnimpl::fxtract([],{})

// Inst::FPREM1(([], {}))

// WarnUnimpl::fdecstp([],{})

// WarnUnimpl::fincstp([],{})

// Unknown::unknown(([], {}))

// Inst::FNSTENV((['M'], {}))

// Inst::FPREM(([], {}))

// WarnUnimpl::fyl2xp1([],{})

// WarnUnimpl::fsqrt([],{})

// Inst::FSINCOS(([], {}))

// WarnUnimpl::frndint([],{})

// WarnUnimpl::fscale([],{})

// Inst::FSIN(([], {}))

// Inst::FCOS(([], {}))

// Unknown::unknown(([], {}))

// Inst::FNSTCW((['Mw'], {}))

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

// WarnUnimpl::fcomi([],{})

// Inst::UD2(([], {}))

// Inst::UD2(([], {}))

// Inst::FST80P((['M'], {}))

// Unknown::unknown(([], {}))

// Inst::FADD2((['Eq'], {}))

// Inst::FADD2((['Mq'], {}))

// Inst::FMUL2((['Eq'], {}))

// Inst::FMUL2((['Mq'], {}))

// Inst::UD2(([], {}))

// WarnUnimpl::fcom([],{})

// Inst::UD2(([], {}))

// WarnUnimpl::fcomp([],{})

// WarnUnimpl::fsubr([],{})

// Inst::FSUB2((['Mq'], {}))

// Inst::FSUB2((['Eq'], {}))

// WarnUnimpl::fsubr([],{})

// WarnUnimpl::fdivr([],{})

// Inst::FDIV2((['Mq'], {}))

// Inst::FDIV2((['Eq'], {}))

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

// Unknown::unknown(([], {}))

// Inst::FADDP(([], {}))

// Inst::FADDP((['Eq'], {}))

// WarnUnimpl::fiadd([],{})

// Inst::FMULP((['Eq'], {}))

// WarnUnimpl::fimul([],{})

// Inst::UD2(([], {}))

// WarnUnimpl::ficom([],{})

// WarnUnimpl::fcompp([],{})

// Inst::UD2(([], {}))

// WarnUnimpl::ficomp([],{})

// WarnUnimpl::fsubrp([],{})

// WarnUnimpl::fisub([],{})

// Inst::FSUBP(([], {}))

// Inst::FSUBP((['Eq'], {}))

// WarnUnimpl::fisubr([],{})

// WarnUnimpl::fdivrp([],{})

// WarnUnimpl::fidiv([],{})

// Inst::FDIVP((['Eq'], {}))

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

// Inst::LOOPE(['Jb'],{})

// Inst::LOOP(['Jb'],{})

// Inst::JRCX(['Jb'],{})

// Inst::IN(['rAb', 'Ib'],{})

// Inst::IN(['rAv', 'Iv'],{})

// Inst::OUT(['Ib', 'rAb'],{})

// Inst::OUT(['Iv', 'rAv'],{})

// Unknown::unknown(([], {}))

// Inst::CALL_NEAR(['Jz'],{})

// Inst::JMP(['Jz'],{})

// Inst::UD2([],{})

// Inst::JMP_FAR(['Iz'],{})

// Inst::JMP_FAR(['Iz'],{})

// Inst::JMP_FAR_REAL(['Iz'],{})

// Inst::JMP_FAR_REAL(['Iz'],{})

// Unknown::unknown(([], {}))

// Inst::JMP(['Jb'],{})

// Inst::IN(['rAb', 'rD'],{})

// Inst::IN(['rAv', 'rD'],{})

// Inst::OUT(['rD', 'rAb'],{})

// Inst::OUT(['rD', 'rAv'],{})

// Unknown::unknown(([], {}))

// M5InternalError::error((['"Tried to execute the lock prefix!"'], {}))

// WarnUnimpl::int1(([], {}))

// M5InternalError::error((['"Tried to execute the repne prefix!"'], {}))

// M5InternalError::error((['"Tried to execute the rep/repe prefix!"'], {}))

// Inst::HLT([],{})

// Inst::CMC([],{})

// Inst::TEST(['Eb', 'Iz'],{})

// Inst::TEST(['Eb', 'Iz'],{})

// Inst::NOT(['Eb'],{})

// Inst::NEG(['Eb'],{})

// Inst::MUL_B(['Eb'],{})

// Inst::IMUL_B(['Eb'],{})

// Inst::DIV_B(['Ew'],{})

// Inst::IDIV_B(['Eb'],{})

// Unknown::unknown(([], {}))

// Inst::TEST(['Ev', 'Iz'],{})

// Inst::TEST(['Ev', 'Iz'],{})

// Inst::NOT(['Ev'],{})

// Inst::NEG(['Ev'],{})

// Inst::MUL(['Ev'],{})

// Inst::IMUL(['Ev'],{})

// Inst::DIV(['Ev'],{})

// Inst::IDIV(['Ev'],{})

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Inst::CLC([],{})

// Inst::STC([],{})

// Inst::CLI([],{})

// Inst::STI([],{})

// Inst::CLD([],{})

// Inst::STD([],{})

// Inst::INC(['Eb'],{})

// Inst::DEC(['Eb'],{})

// Inst::UD2([],{})

// Inst::INC(['Ev'],{})

// Inst::DEC(['Ev'],{})

// Inst::CALL_NEAR(['Ev'],{})

// WarnUnimpl::call_far_Mp(([], {}))

// Inst::JMP(['Ev'],{})

// Inst::JMP_FAR(['Mz'],{})

// Inst::JMP_FAR(['Mz'],{})

// Inst::JMP_FAR(['Mz'],{})

// Inst::JMP_FAR_REAL(['Mz'],{})

// Inst::JMP_FAR_REAL(['Mz'],{})

// Unknown::unknown(([], {}))

// Inst::PUSH(['Ev'],{})

// Inst::UD2([],{})

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// FailUnimpl::oneByteOps(([], {}))

// WarnUnimpl::sldt_Mw_or_Rv([],{})

// WarnUnimpl::str_Mw_or_Rv([],{})

// Inst::LLDT((['Ew'], {}))

// Inst::LTR((['Ew'], {}))

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

        Fault Monitor::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            uint64_t Rax = 0;
;
            Rax = xc->readIntRegOperand(this, 0);
;
            
                           xc->armMonitor(Rax);
                        ;

            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

// MwaitInst::mwait((['\n                           uint64_t m = 0;          //mem\n                           unsigned s = 0x8;        //size\n                           unsigned f = 0;          //flags\n                           readMemAtomic(xc, traceData,\n                                         xc->getAddrMonitor()->vAddr,\n                                         m, s, f);\n                           xc->mwaitAtomic(xc->tcBase());\n                           MicroHalt hltObj(machInst, mnemonic, 0x0);\n                           hltObj.execute(xc, traceData);\n                        '], {}))

        Fault Mwait::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            ;
            ;
            
                           uint64_t m = 0;          //mem
                           unsigned s = 0x8;        //size
                           unsigned f = 0;          //flags
                           readMemAtomic(xc, traceData,
                                         xc->getAddrMonitor()->vAddr,
                                         m, s, f);
                           xc->mwaitAtomic(xc->tcBase());
                           MicroHalt hltObj(machInst, mnemonic, 0x0);
                           hltObj.execute(xc, traceData);
                        ;

            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

    Fault Mwait::initiateAcc(CPU_EXEC_CONTEXT * xc,
            Trace::InstRecord * traceData) const
    {
        uint64_t m = 0;          //mem
        unsigned s = 0x8;        //size
        unsigned f = 0;          //flags
        readMemTiming(xc, traceData, xc->getAddrMonitor()->vAddr, m, s, f);
        return NoFault;
    }

    Fault Mwait::completeAcc(PacketPtr pkt, CPU_EXEC_CONTEXT *xc,
            Trace::InstRecord *traceData) const
    {
        MicroHalt hltObj(machInst, mnemonic, 0x0);
        if(xc->mwait(pkt)) {
            hltObj.execute(xc, traceData);
        }
        return NoFault;
    }

// Inst::UD2(([], {}))

// WarnUnimpl::sidt_Ms([],{})

// WarnUnimpl::xgetbv([],{})

// WarnUnimpl::xsetbv([],{})

// Unknown::unknown(([], {}))

// Inst::LGDT((['M'], {}))

// Inst::LGDT_16((['M'], {}))

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

// Inst::LIDT_16((['M'], {}))

// Inst::LIDT((['M'], {}))

// Inst::SMSW((['Rv'], {}))

// Inst::SMSW((['Mw'], {}))

// Inst::LMSW((['Ew'], {}))

// Inst::SWAPGS(([], {}))

// WarnUnimpl::rdtscp([],{})

// Inst::UD2(([], {}))

// Inst::INVLPG((['M'], {}))

// Unknown::unknown(([], {}))

// WarnUnimpl::lar_Gv_Ew([],{})

// WarnUnimpl::lsl_Gv_Ew([],{})

// BasicOperate::m5arm(['\n                        PseudoInst::arm(xc->tcBase());\n                    ', 'IsNonSpeculative'],{})

        Fault M5arm::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            ;
            ;
            
                        PseudoInst::arm(xc->tcBase());
                    ;

            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

// BasicOperate::m5quiesce(['\n                        PseudoInst::quiesce(xc->tcBase());\n                    ', 'IsNonSpeculative', 'IsQuiesce'],{})

        Fault M5quiesce::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            ;
            ;
            
                        PseudoInst::quiesce(xc->tcBase());
                    ;

            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

// BasicOperate::m5quiesceNs(['\n                        PseudoInst::quiesceNs(xc->tcBase(), Rdi);\n                    ', 'IsNonSpeculative', 'IsQuiesce'],{})

        Fault M5quiesceNs::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            uint64_t Rdi = 0;
;
            Rdi = xc->readIntRegOperand(this, 0);
;
            
                        PseudoInst::quiesceNs(xc->tcBase(), Rdi);
                    ;

            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

// BasicOperate::m5quiesceCycle(['\n                        PseudoInst::quiesceCycles(xc->tcBase(), Rdi);\n                    ', 'IsNonSpeculative', 'IsQuiesce'],{})

        Fault M5quiesceCycle::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            uint64_t Rdi = 0;
;
            Rdi = xc->readIntRegOperand(this, 0);
;
            
                        PseudoInst::quiesceCycles(xc->tcBase(), Rdi);
                    ;

            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

// BasicOperate::m5quiesceTime(['\n                        Rax = PseudoInst::quiesceTime(xc->tcBase());\n                    ', 'IsNonSpeculative'],{})

        Fault M5quiesceTime::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            uint64_t Rax = 0;
;
            ;
            
                        Rax = PseudoInst::quiesceTime(xc->tcBase());
                    ;

            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = Rax;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

// BasicOperate::m5rpns(['\n                        Rax = PseudoInst::rpns(xc->tcBase());\n                    ', 'IsNonSpeculative'],{})

        Fault M5rpns::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            uint64_t Rax = 0;
;
            ;
            
                        Rax = PseudoInst::rpns(xc->tcBase());
                    ;

            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = Rax;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

// BasicOperate::m5exit(['\n                        PseudoInst::m5exit(xc->tcBase(), Rdi);\n                    ', 'IsNonSpeculative'],{})

        Fault M5exit::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            uint64_t Rdi = 0;
;
            Rdi = xc->readIntRegOperand(this, 0);
;
            
                        PseudoInst::m5exit(xc->tcBase(), Rdi);
                    ;

            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

// BasicOperate::m5fail(['\n                        PseudoInst::m5fail(xc->tcBase(), Rdi, Rsi);\n                    ', 'IsNonSpeculative'],{})

        Fault M5fail::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            uint64_t Rsi = 0;
uint64_t Rdi = 0;
;
            Rsi = xc->readIntRegOperand(this, 0);
Rdi = xc->readIntRegOperand(this, 1);
;
            
                        PseudoInst::m5fail(xc->tcBase(), Rdi, Rsi);
                    ;

            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

// BasicOperate::m5initparam(['\n                        Rax = PseudoInst::initParam(xc->tcBase());\n                    ', 'IsNonSpeculative'],{})

        Fault M5initparam::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            uint64_t Rax = 0;
;
            ;
            
                        Rax = PseudoInst::initParam(xc->tcBase());
                    ;

            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = Rax;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

// BasicOperate::m5loadsymbol(['\n                        PseudoInst::loadsymbol(xc->tcBase());\n                    ', 'IsNonSpeculative'],{})

        Fault M5loadsymbol::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            ;
            ;
            
                        PseudoInst::loadsymbol(xc->tcBase());
                    ;

            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

// BasicOperate::m5resetstats(['\n                        PseudoInst::resetstats(xc->tcBase(), Rdi, Rsi);\n                    ', 'IsNonSpeculative'],{})

        Fault M5resetstats::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            uint64_t Rsi = 0;
uint64_t Rdi = 0;
;
            Rsi = xc->readIntRegOperand(this, 0);
Rdi = xc->readIntRegOperand(this, 1);
;
            
                        PseudoInst::resetstats(xc->tcBase(), Rdi, Rsi);
                    ;

            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

// BasicOperate::m5dumpstats(['\n                        PseudoInst::dumpstats(xc->tcBase(), Rdi, Rsi);\n                    ', 'IsNonSpeculative'],{})

        Fault M5dumpstats::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            uint64_t Rsi = 0;
uint64_t Rdi = 0;
;
            Rsi = xc->readIntRegOperand(this, 0);
Rdi = xc->readIntRegOperand(this, 1);
;
            
                        PseudoInst::dumpstats(xc->tcBase(), Rdi, Rsi);
                    ;

            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

// BasicOperate::m5dumpresetstats(['\n                        PseudoInst::dumpresetstats(xc->tcBase(), Rdi, Rsi);\n                    ', 'IsNonSpeculative'],{})

        Fault M5dumpresetstats::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            uint64_t Rsi = 0;
uint64_t Rdi = 0;
;
            Rsi = xc->readIntRegOperand(this, 0);
Rdi = xc->readIntRegOperand(this, 1);
;
            
                        PseudoInst::dumpresetstats(xc->tcBase(), Rdi, Rsi);
                    ;

            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

// BasicOperate::m5checkpoint(['\n                        PseudoInst::m5checkpoint(xc->tcBase(), Rdi, Rsi);\n                    ', 'IsNonSpeculative'],{})

        Fault M5checkpoint::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            uint64_t Rsi = 0;
uint64_t Rdi = 0;
;
            Rsi = xc->readIntRegOperand(this, 0);
Rdi = xc->readIntRegOperand(this, 1);
;
            
                        PseudoInst::m5checkpoint(xc->tcBase(), Rdi, Rsi);
                    ;

            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

// BasicOperate::m5readfile(['\n                        Rax = PseudoInst::readfile(\n                            xc->tcBase(), Rdi, Rsi, Rdx);\n                    ', 'IsNonSpeculative'],{})

        Fault M5readfile::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            uint64_t Rax = 0;
uint64_t Rdx = 0;
uint64_t Rsi = 0;
uint64_t Rdi = 0;
;
            Rdx = xc->readIntRegOperand(this, 0);
Rsi = xc->readIntRegOperand(this, 1);
Rdi = xc->readIntRegOperand(this, 2);
;
            
                        Rax = PseudoInst::readfile(
                            xc->tcBase(), Rdi, Rsi, Rdx);
                    ;

            if(fault == NoFault)
            {
                
        
        {
            uint64_t final_val = Rax;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
            return fault;
        }

// BasicOperate::m5debugbreak(['\n                        PseudoInst::debugbreak(xc->tcBase());\n                    ', 'IsNonSpeculative'],{})

        Fault M5debugbreak::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            ;
            ;
            
                        PseudoInst::debugbreak(xc->tcBase());
                    ;

            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

// BasicOperate::m5switchcpu(['\n                        PseudoInst::switchcpu(xc->tcBase());\n                    ', 'IsNonSpeculative'],{})

        Fault M5switchcpu::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            ;
            ;
            
                        PseudoInst::switchcpu(xc->tcBase());
                    ;

            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

// BasicOperate::m5addsymbol(['\n                        PseudoInst::addsymbol(xc->tcBase(), Rdi, Rsi);\n                    ', 'IsNonSpeculative'],{})

        Fault M5addsymbol::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            uint64_t Rsi = 0;
uint64_t Rdi = 0;
;
            Rsi = xc->readIntRegOperand(this, 0);
Rdi = xc->readIntRegOperand(this, 1);
;
            
                        PseudoInst::addsymbol(xc->tcBase(), Rdi, Rsi);
                    ;

            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

// BasicOperate::m5panic(['\n                        panic("M5 panic instruction called at pc = %#x.\\n",\n                              RIP);\n                    ', 'IsNonSpeculative'],{})

        Fault M5panic::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            uint64_t RIP = 0;
TheISA::PCState __parserAutoPCState;
;
            __parserAutoPCState = xc->pcState();
RIP = __parserAutoPCState.pc();
;
            
                        panic("M5 panic instruction called at pc = %#x.\n",
                              RIP);
                    ;

            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

// BasicOperate::m5reserved1(['\n                        warn("M5 reserved opcode 1 ignored.\\n");\n                    ', 'IsNonSpeculative'],{})

        Fault M5reserved1::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            ;
            ;
            
                        warn("M5 reserved opcode 1 ignored.\n");
                    ;

            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

// BasicOperate::m5reserved2(['\n                        warn("M5 reserved opcode 2 ignored.\\n");\n                    ', 'IsNonSpeculative'],{})

        Fault M5reserved2::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            ;
            ;
            
                        warn("M5 reserved opcode 2 ignored.\n");
                    ;

            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

// BasicOperate::m5reserved3(['\n                        warn("M5 reserved opcode 3 ignored.\\n");\n                    ', 'IsNonSpeculative'],{})

        Fault M5reserved3::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            ;
            ;
            
                        warn("M5 reserved opcode 3 ignored.\n");
                    ;

            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

// BasicOperate::m5reserved4(['\n                        warn("M5 reserved opcode 4 ignored.\\n");\n                    ', 'IsNonSpeculative'],{})

        Fault M5reserved4::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            ;
            ;
            
                        warn("M5 reserved opcode 4 ignored.\n");
                    ;

            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

// BasicOperate::m5reserved5(['\n                        warn("M5 reserved opcode 5 ignored.\\n");\n                    ', 'IsNonSpeculative'],{})

        Fault M5reserved5::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            ;
            ;
            
                        warn("M5 reserved opcode 5 ignored.\n");
                    ;

            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

// BasicOperate::m5_work_begin(['\n                        PseudoInst::workbegin(xc->tcBase(), Rdi, Rsi);\n                    ', 'IsNonSpeculative'],{})

        Fault M5_work_begin::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            uint64_t Rsi = 0;
uint64_t Rdi = 0;
;
            Rsi = xc->readIntRegOperand(this, 0);
Rdi = xc->readIntRegOperand(this, 1);
;
            
                        PseudoInst::workbegin(xc->tcBase(), Rdi, Rsi);
                    ;

            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

// BasicOperate::m5_work_end(['\n                        PseudoInst::workend(xc->tcBase(), Rdi, Rsi);\n                    ', 'IsNonSpeculative'],{})

        Fault M5_work_end::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            uint64_t Rsi = 0;
uint64_t Rdi = 0;
;
            Rsi = xc->readIntRegOperand(this, 0);
Rdi = xc->readIntRegOperand(this, 1);
;
            
                        PseudoInst::workend(xc->tcBase(), Rdi, Rsi);
                    ;

            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

// Inst::UD2(([], {}))

// SyscallInst::syscall((['xc->syscall(Rax)', 'IsSyscall', 'IsNonSpeculative', 'IsSerializeAfter'], {}))

    Fault Syscall::execute(CPU_EXEC_CONTEXT *xc,
            Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;
        uint64_t Rax = 0;
;
        Rax = xc->readIntRegOperand(this, 0);
;
        xc->syscall(Rax);
        return fault;
    }

// Inst::SYSCALL_64(([], {}))

// Inst::SYSCALL_COMPAT(([], {}))

// Unknown::unknown(([], {}))

// Inst::SYSCALL_LEGACY(([], {}))

// Unknown::unknown(([], {}))

// Inst::CLTS(([], {}))

// Inst::SYSRET_TO_64(([], {}))

// Inst::SYSRET_TO_COMPAT(([], {}))

// Inst::SYSRET_NON_64(([], {}))

// Unknown::unknown(([], {}))

// WarnUnimpl::invd([],{})

// WarnUnimpl::wbinvd([],{})

// Inst::UD2(([], {}))

// Inst::UD2(([], {}))

// Inst::UD2(([], {}))

// Inst::PREFETCH((['Mb'], {}))

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

// WarnUnimpl::pfadd_Pq_Qq([],{})

// WarnUnimpl::pfcmpgt_Pq_Qq([],{})

// WarnUnimpl::pfmax_Pq_Qq([],{})

// WarnUnimpl::pfrcpit1_Pq_Qq([],{})

// WarnUnimpl::pfrsqit1_Pq_Qq([],{})

// Inst::PFSUBR((['Pq', 'Qq'], {}))

// WarnUnimpl::pfacc_Pq_Qq([],{})

// WarnUnimpl::pfcmpeq_Pq_Qq([],{})

// Inst::PFMUL((['Pq', 'Qq'], {}))

// WarnUnimpl::pfrcpit2_Pq_Qq([],{})

// Inst::PMULHRW((['Pq', 'Qq'], {}))

// WarnUnimpl::pswapd_Pq_Qq([],{})

// WarnUnimpl::pavgusb_Pq_Qq([],{})

// Inst::UD2(([], {}))

// Unknown::unknown(([], {}))

// Inst::MOVUPS(['Vo', 'Wo'],{})

// Inst::MOVUPS(['Wo', 'Vo'],{})

// Inst::MOVHLPS(['Vps', 'VRq'],{})

// Inst::MOVLPS(['Vps', 'Mq'],{})

// Inst::MOVLPS(['Mq', 'Vps'],{})

// Inst::UNPCKLPS(['Vps', 'Wq'],{})

// Inst::UNPCKHPS(['Vps', 'Wq'],{})

// Inst::MOVLHPS(['Vps', 'VRq'],{})

// Inst::MOVHPS(['Vps', 'Mq'],{})

// Inst::MOVHPS(['Mq', 'Vq'],{})

// Unknown::unknown(([], {}))

// Inst::MOVSS(['Vd', 'Wd'],{})

// Inst::MOVSS(['Wd', 'Vd'],{})

// WarnUnimpl::movsldup_Vo_Wo(([], {}))

// WarnUnimpl::movshdup_Vo_Wo(([], {}))

// Inst::UD2([],{})

// Inst::MOVUPD(['Vo', 'Wo'],{})

// Inst::MOVUPD(['Wo', 'Vo'],{})

// Inst::MOVLPD(['Vq', 'Mq'],{})

// Inst::MOVLPD(['Mq', 'Vq'],{})

// Inst::UNPCKLPD(['Vo', 'Wq'],{})

// Inst::UNPCKHPD(['Vo', 'Wo'],{})

// Inst::MOVHPD(['Vq', 'Mq'],{})

// Inst::MOVHPD(['Mq', 'Vq'],{})

// Unknown::unknown(([], {}))

// Inst::MOVSD(['Vq', 'Wq'],{})

// Inst::MOVSD(['Wq', 'Vq'],{})

// Inst::MOVDDUP(['Vo', 'Wq'],{})

// Inst::UD2([],{})

// Inst::UD2([],{})

// WarnUnimpl::prefetch_nta(([], {}))

// Inst::PREFETCH_T0(['Mb'],{})

// WarnUnimpl::prefetch_t1(([], {}))

// WarnUnimpl::prefetch_t2(([], {}))

// Inst::HINT_NOP([],{})

// Inst::HINT_NOP([],{})

// Inst::HINT_NOP([],{})

// Inst::HINT_NOP([],{})

// Inst::HINT_NOP([],{})

// Inst::HINT_NOP([],{})

// Inst::HINT_NOP([],{})

// Inst::HINT_NOP([],{})

// Unknown::unknown(([], {}))

// Inst::MOV(['Rd', 'Cd'],{})

// Inst::MOV(['Rd', 'Dd'],{})

// Inst::MOV(['Cd', 'Rd'],{})

// Inst::MOV(['Dd', 'Rd'],{})

// Inst::UD2([],{})

// Inst::UD2([],{})

// Inst::MOVAPS(['Vq', 'Wq'],{})

// Inst::MOVAPS(['Wq', 'Vq'],{})

// Inst::CVTPI2PS(['Vq', 'Qq'],{})

// WarnUnimpl::movntps_Mo_Vo(([], {}))

// Inst::CVTTPS2PI(['Pq', 'Wq'],{})

// Inst::CVTPS2PI(['Pq', 'Wq'],{})

// Inst::UCOMISS(['Vd', 'Wd'],{})

// Inst::COMISS(['Vd', 'Wd'],{})

// Unknown::unknown(([], {}))

// Inst::CVTSI2SS(['Vd', 'Ed'],{})

// Inst::CVTTSS2SI(['Gd', 'Wd'],{})

// Inst::CVTSS2SI(['Gd', 'Wd'],{})

// Inst::UD2([],{})

// Inst::MOVAPD(['Vo', 'Wo'],{})

// Inst::MOVAPD(['Wo', 'Vo'],{})

// Inst::CVTPI2PD(['Vo', 'Qq'],{})

// WarnUnimpl::movntpd_Mo_Vo(([], {}))

// Inst::CVTTPD2PI(['Pq', 'Wo'],{})

// Inst::CVTPD2PI(['Pq', 'Wo'],{})

// Inst::UCOMISD(['Vq', 'Wq'],{})

// Inst::COMISD(['Vq', 'Wq'],{})

// Unknown::unknown(([], {}))

// Inst::CVTSI2SD(['Vdp', 'Edp'],{})

// Inst::CVTTSD2SI(['Gdp', 'Wdp'],{})

// Inst::CVTSD2SI(['Gd', 'Wq'],{})

// Inst::UD2([],{})

// Inst::UD2([],{})

// Inst::WRMSR(([], {}))

// Inst::RDTSC(([], {}))

// Inst::RDMSR(([], {}))

// WarnUnimpl::rdpmc([],{})

// SyscallInst::sysenter((['xc->syscall(Rax)', 'IsSyscall', 'IsNonSpeculative', 'IsSerializeAfter'], {}))

    Fault Sysenter::execute(CPU_EXEC_CONTEXT *xc,
            Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;
        uint64_t Rax = 0;
;
        Rax = xc->readIntRegOperand(this, 0);
;
        xc->syscall(Rax);
        return fault;
    }

// WarnUnimpl::sysenter([],{})

// WarnUnimpl::sysexit([],{})

// Inst::UD2(([], {}))

// WarnUnimpl::getsec([],{})

// Unknown::unknown(([], {}))

// M5InternalError::error((['"Three byte opcode shouldn\'t be handled by "\n                  "two_byte_opcodes.isa!"'], {}))

// M5InternalError::error((['"Three byte opcode shouldn\'t be handled by "\n                  "two_byte_opcodes.isa!"'], {}))

// WarnUnimpl::UD2([],{})

// Inst::CMOVO(['Gv', 'Ev'],{})

// Inst::CMOVNO(['Gv', 'Ev'],{})

// Inst::CMOVB(['Gv', 'Ev'],{})

// Inst::CMOVNB(['Gv', 'Ev'],{})

// Inst::CMOVZ(['Gv', 'Ev'],{})

// Inst::CMOVNZ(['Gv', 'Ev'],{})

// Inst::CMOVBE(['Gv', 'Ev'],{})

// Inst::CMOVNBE(['Gv', 'Ev'],{})

// Unknown::unknown(([], {}))

// Inst::CMOVS(['Gv', 'Ev'],{})

// Inst::CMOVNS(['Gv', 'Ev'],{})

// Inst::CMOVP(['Gv', 'Ev'],{})

// Inst::CMOVNP(['Gv', 'Ev'],{})

// Inst::CMOVL(['Gv', 'Ev'],{})

// Inst::CMOVNL(['Gv', 'Ev'],{})

// Inst::CMOVLE(['Gv', 'Ev'],{})

// Inst::CMOVNLE(['Gv', 'Ev'],{})

// Unknown::unknown(([], {}))

// Inst::MOVMSKPS(['Gd', 'VRo'],{})

// Inst::SQRTPS(['Vo', 'Wo'],{})

// WarnUnimpl::rqsrtps_Vo_Wo(([], {}))

// WarnUnimpl::rcpps_Vo_Wo(([], {}))

// Inst::ANDPS(['Vo', 'Wo'],{})

// Inst::ANDNPS(['Vo', 'Wo'],{})

// Inst::ORPS(['Vo', 'Wo'],{})

// Inst::XORPS(['Vo', 'Wo'],{})

// Unknown::unknown(([], {}))

// Inst::SQRTSS(['Vd', 'Wd'],{})

// WarnUnimpl::rsqrtss_Vd_Wd(([], {}))

// WarnUnimpl::rcpss_Vd_Wd(([], {}))

// Inst::UD2([],{})

// Inst::MOVMSKPD(['Gd', 'VRo'],{})

// Inst::SQRTPD(['Vo', 'Wo'],{})

// Inst::ANDPD(['Vo', 'Wo'],{})

// Inst::ANDNPD(['Vo', 'Wo'],{})

// Inst::ORPD(['Vo', 'Wo'],{})

// Inst::XORPD(['Vo', 'Wo'],{})

// Inst::UD2([],{})

// Inst::SQRTSD(['Vq', 'Wq'],{})

// Inst::UD2([],{})

// Inst::UD2([],{})

// Inst::ADDPS(['Vo', 'Wo'],{})

// Inst::MULPS(['Vo', 'Wo'],{})

// Inst::CVTPS2PD(['Vo', 'Wq'],{})

// Inst::CVTDQ2PS(['Vo', 'Wo'],{})

// Inst::SUBPS(['Vo', 'Wo'],{})

// Inst::MINPS(['Vo', 'Wo'],{})

// Inst::DIVPS(['Vo', 'Wo'],{})

// Inst::MAXPS(['Vo', 'Wo'],{})

// Unknown::unknown(([], {}))

// Inst::ADDSS(['Vd', 'Wd'],{})

// Inst::MULSS(['Vd', 'Wd'],{})

// Inst::CVTSS2SD(['Vq', 'Wd'],{})

// Inst::CVTTPS2DQ(['Vo', 'Wo'],{})

// Inst::SUBSS(['Vd', 'Wd'],{})

// Inst::MINSS(['Vd', 'Wd'],{})

// Inst::DIVSS(['Vd', 'Wd'],{})

// Inst::MAXSS(['Vd', 'Wd'],{})

// Unknown::unknown(([], {}))

// Inst::ADDPD(['Vo', 'Wo'],{})

// Inst::MULPD(['Vo', 'Wo'],{})

// Inst::CVTPD2PS(['Vo', 'Wo'],{})

// Inst::CVTPS2DQ(['Vo', 'Wo'],{})

// Inst::SUBPD(['Vo', 'Wo'],{})

// Inst::MINPD(['Vo', 'Wo'],{})

// Inst::DIVPD(['Vo', 'Wo'],{})

// Inst::MAXPD(['Vo', 'Wo'],{})

// Unknown::unknown(([], {}))

// Inst::ADDSD(['Vq', 'Wq'],{})

// Inst::MULSD(['Vq', 'Wq'],{})

// Inst::CVTSD2SS(['Vd', 'Wq'],{})

// Inst::SUBSD(['Vq', 'Wq'],{})

// Inst::MINSD(['Vq', 'Wq'],{})

// Inst::DIVSD(['Vq', 'Wq'],{})

// Inst::MAXSD(['Vq', 'Wq'],{})

// Inst::UD2([],{})

// Inst::UD2([],{})

// Inst::PUNPCKLBW(['Pq', 'Qd'],{})

// Inst::PUNPCKLWD(['Pq', 'Qd'],{})

// Inst::PUNPCKLDQ(['Pq', 'Qd'],{})

// Inst::PACKSSWB(['Pq', 'Qq'],{})

// Inst::PCMPGTB(['Pq', 'Qq'],{})

// Inst::PCMPGTW(['Pq', 'Qq'],{})

// Inst::PCMPGTD(['Pq', 'Qq'],{})

// Inst::PACKUSWB(['Pq', 'Qq'],{})

// Unknown::unknown(([], {}))

// Inst::PUNPCKLBW(['Vo', 'Wq'],{})

// Inst::PUNPCKLWD(['Vo', 'Wq'],{})

// Inst::PUNPCKLDQ(['Vo', 'Wq'],{})

// Inst::PACKSSWB(['Vo', 'Wo'],{})

// Inst::PCMPGTB(['Vo', 'Wo'],{})

// Inst::PCMPGTW(['Vo', 'Wo'],{})

// Inst::PCMPGTD(['Vo', 'Wo'],{})

// Inst::PACKUSWB(['Vo', 'Wo'],{})

// Unknown::unknown(([], {}))

// Inst::UD2([],{})

// Inst::PUNPCKHBW(['Pq', 'Qq'],{})

// Inst::PUNPCKHWD(['Pq', 'Qq'],{})

// Inst::PUNPCKHDQ(['Pq', 'Qq'],{})

// Inst::PACKSSDW(['Pq', 'Qq'],{})

// Inst::MOVD(['Pq', 'Edp'],{})

// Inst::MOVQ(['Pq', 'Qq'],{})

// Inst::UD2([],{})

// Inst::MOVDQU(['Vo', 'Wo'],{})

// Inst::UD2([],{})

// Inst::PUNPCKHBW(['Vo', 'Wo'],{})

// Inst::PUNPCKHWD(['Vo', 'Wo'],{})

// Inst::PUNPCKHDQ(['Vo', 'Wo'],{})

// Inst::PACKSSDW(['Vo', 'Wo'],{})

// Inst::PUNPCKLQDQ(['Vo', 'Wq'],{})

// Inst::PUNPCKHQDQ(['Vo', 'Wq'],{})

// Inst::MOVD(['Vo', 'Edp'],{})

// Inst::MOVDQA(['Vo', 'Wo'],{})

// Unknown::unknown(([], {}))

// Inst::UD2([],{})

// Inst::PSHUFW(['Pq', 'Qq', 'Ib'],{})

// Inst::PSRLW(['PRq', 'Ib'],{})

// Inst::PSRAW(['PRq', 'Ib'],{})

// Inst::PSLLW(['PRq', 'Ib'],{})

// Inst::UD2([],{})

// Inst::PSRLD(['PRq', 'Ib'],{})

// Inst::PSRAD(['PRq', 'Ib'],{})

// Inst::PSLLD(['PRq', 'Ib'],{})

// Inst::UD2([],{})

// Inst::PSRLQ(['PRq', 'Ib'],{})

// Inst::PSLLQ(['PRq', 'Ib'],{})

// Inst::UD2(([], {}))

// Inst::PCMPEQB((['Pq', 'Qq'], {}))

// Inst::PCMPEQW((['Pq', 'Qq'], {}))

// Inst::PCMPEQD((['Pq', 'Qq'], {}))

// Inst::EMMS(([], {}))

// Unknown::unknown(([], {}))

// Inst::PSHUFHW(['Vo', 'Wo', 'Ib'],{})

// Inst::UD2([],{})

// Inst::PSHUFD(['Vo', 'Wo', 'Ib'],{})

// Inst::PSRLW(['VRo', 'Ib'],{})

// Inst::PSRAW(['VRo', 'Ib'],{})

// Inst::PSLLW(['VRo', 'Ib'],{})

// Unknown::unknown(([], {}))

// Inst::PSRLD(['VRo', 'Ib'],{})

// Inst::PSRAD(['VRo', 'Ib'],{})

// Inst::PSLLD(['VRo', 'Ib'],{})

// Inst::UD2([],{})

// Inst::PSRLQ(['VRo', 'Ib'],{})

// Inst::PSRLDQ(['VRo', 'Ib'],{})

// Inst::PSLLQ(['VRo', 'Ib'],{})

// Inst::PSLLDQ(['VRo', 'Ib'],{})

// Inst::UD2([],{})

// Inst::PCMPEQB(['Vo', 'Wo'],{})

// Inst::PCMPEQW(['Vo', 'Wo'],{})

// Inst::PCMPEQD(['Vo', 'Wo'],{})

// Inst::UD2([],{})

// Inst::PSHUFLW(['Vo', 'Wo', 'Ib'],{})

// Inst::UD2([],{})

// Inst::UD2([],{})

// WarnUnimpl::vmread_Edp_Gdp(([], {}))

// WarnUnimpl::vmwrite_Gdp_Edp(([], {}))

// Inst::MOVD(['Edp', 'Pdp'],{})

// Inst::MOVQ(['Qq', 'Pq'],{})

// Inst::UD2([],{})

// Inst::MOVQ(['Vq', 'Wq'],{})

// Inst::MOVDQU(['Wo', 'Vo'],{})

// Inst::UD2([],{})

// Inst::HADDPD(['Vo', 'Wo'],{})

// WarnUnimpl::hsubpd_Vo_Wo(([], {}))

// Inst::MOVD(['Edp', 'Vd'],{})

// Inst::MOVDQA(['Wo', 'Vo'],{})

// Inst::UD2([],{})

// Inst::HADDPS(['Vo', 'Wo'],{})

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

// Inst::SETNO(['Eb'],{})

// Inst::SETB(['Eb'],{})

// Inst::SETNB(['Eb'],{})

// Inst::SETZ(['Eb'],{})

// Inst::SETNZ(['Eb'],{})

// Inst::SETBE(['Eb'],{})

// Inst::SETNBE(['Eb'],{})

// Unknown::unknown(([], {}))

// Inst::SETS(['Eb'],{})

// Inst::SETNS(['Eb'],{})

// Inst::SETP(['Eb'],{})

// Inst::SETNP(['Eb'],{})

// Inst::SETL(['Eb'],{})

// Inst::SETNL(['Eb'],{})

// Inst::SETLE(['Eb'],{})

// Inst::SETNLE(['Eb'],{})

// Unknown::unknown(([], {}))

// WarnUnimpl::push_fs([],{})

// WarnUnimpl::pop_fs([],{})

// CPUIDInst::CPUID((['\n                CpuidResult result;\n                bool success = doCpuid(xc->tcBase(), bits(Rax, 31, 0),\n                    bits(Rcx, 31, 0), result);\n                if (success) {\n                    Rax = result.rax;\n                    Rbx = result.rbx;\n                    Rcx = result.rcx;\n                    Rdx = result.rdx;\n                } else {\n                    Rax = Rax;\n                    Rbx = Rbx;\n                    Rcx = Rcx;\n                    Rdx = Rdx;\n                }\n                '], {}))

    Fault CPUID::execute(CPU_EXEC_CONTEXT *xc,
            Trace::InstRecord *traceData) const
    {
        // If the CPUID instruction used a valid function number, this will
        // be set to true. Otherwise, the instruction does nothing.
        uint64_t Rax = 0;
uint64_t Rbx = 0;
uint64_t Rcx = 0;
uint64_t Rdx = 0;
;
        Rax = xc->readIntRegOperand(this, 0);
Rbx = xc->readIntRegOperand(this, 1);
Rcx = xc->readIntRegOperand(this, 2);
Rdx = xc->readIntRegOperand(this, 3);
;
        
                CpuidResult result;
                bool success = doCpuid(xc->tcBase(), bits(Rax, 31, 0),
                    bits(Rcx, 31, 0), result);
                if (success) {
                    Rax = result.rax;
                    Rbx = result.rbx;
                    Rcx = result.rcx;
                    Rdx = result.rdx;
                } else {
                    Rax = Rax;
                    Rbx = Rbx;
                    Rcx = Rcx;
                    Rdx = Rdx;
                }
                ;
        
        
        {
            uint64_t final_val = Rax;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = Rbx;
            xc->setIntRegOperand(this, 1, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = Rcx;
            xc->setIntRegOperand(this, 2, final_val);

            if (traceData) { traceData->setData(final_val); }
        }
        
        {
            uint64_t final_val = Rdx;
            xc->setIntRegOperand(this, 3, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// Inst::BT((['Ev', 'Gv'], {}))

// Inst::SHLD((['Ev', 'Gv', 'Ib'], {}))

// Inst::SHLD((['Ev', 'Gv'], {}))

// Inst::UD2(([], {}))

// WarnUnimpl::push_gs([],{})

// WarnUnimpl::pop_gs([],{})

// WarnUnimpl::rsm_smm([],{})

// Inst::BTS((['Ev', 'Gv'], {}))

// Inst::SHRD((['Ev', 'Gv', 'Ib'], {}))

// Inst::SHRD((['Ev', 'Gv'], {}))

// BasicOperate::LFENCE((['/*Nothing*/', 'IsReadBarrier'], {}))

        Fault LFENCE::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            ;
            ;
            /*Nothing*/;

            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

// BasicOperate::MFENCE((['/*Nothing*/', 'IsMemBarrier'], {}))

        Fault MFENCE::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            ;
            ;
            /*Nothing*/;

            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

// BasicOperate::SFENCE((['/*Nothing*/', 'IsWriteBarrier'], {}))

        Fault SFENCE::execute(CPU_EXEC_CONTEXT *xc,
                Trace::InstRecord *traceData) const
        {
            Fault fault = NoFault;

            ;
            ;
            ;
            /*Nothing*/;

            if(fault == NoFault)
            {
                ;
            }
            return fault;
        }

// Inst::UD2(([], {}))

// Inst::FXSAVE((['M'], {}))

// Inst::FXSAVE64((['M'], {}))

// WarnUnimpl::fxsave([],{})

// Inst::FXRSTOR((['M'], {}))

// Inst::FXRSTOR64((['M'], {}))

// WarnUnimpl::fxrstor([],{})

// Inst::LDMXCSR((['Md'], {}))

// Inst::STMXCSR((['Md'], {}))

// WarnUnimpl::xsave([],{})

// WarnUnimpl::xrstor([],{})

// Inst::UD2(([], {}))

// WarnUnimpl::clflush([],{})

// Unknown::unknown(([], {}))

// Inst::IMUL((['Gv', 'Ev'], {}))

// Unknown::unknown(([], {}))

// Inst::CMPXCHG(['Eb', 'Gb'],{})

// Inst::CMPXCHG(['Ev', 'Gv'],{})

// WarnUnimpl::lss_Gz_Mp(([], {}))

// Inst::BTR(['Ev', 'Gv'],{})

// WarnUnimpl::lfs_Gz_Mp(([], {}))

// WarnUnimpl::lgs_Gz_Mp(([], {}))

// Inst::MOVZX_B(['Gv', 'Ev'],{})

// Inst::MOVZX_W(['Gv', 'Ev'],{})

// Unknown::unknown(([], {}))

// WarnUnimpl::jmpe_Jz(([], {}))

// WarnUnimpl::popcnt_Gv_Ev(([], {}))

// Unknown::unknown(([], {}))

// Inst::UD2([],{})

// Inst::BT(['Ev', 'Ib'],{})

// Inst::BTS(['Ev', 'Ib'],{})

// Inst::BTR(['Ev', 'Ib'],{})

// Inst::BTC(['Ev', 'Ib'],{})

// Inst::UD2([],{})

// Inst::BTC(['Ev', 'Gv'],{})

// Inst::BSF(['Gv', 'Ev'],{})

// Inst::BSR(['Gv', 'Ev'],{})

// Inst::MOVSX_B(['Gv', 'Ev'],{})

// Inst::MOVSX_W(['Gv', 'Ev'],{})

// Unknown::unknown(([], {}))

// Inst::XADD(['Eb', 'Gb'],{})

// Inst::XADD(['Ev', 'Gv'],{})

// Inst::CMPXCHG8B(['Mdp'],{})

// WarnUnimpl::vmclear_Mq(([], {}))

// WarnUnimpl::vmxon_Mq(([], {}))

// WarnUnimpl::vmptrld_Mq(([], {}))

// Unknown::unknown(([], {}))

// WarnUnimpl::vmptrst_Mq(([], {}))

// Inst::UD2([],{})

// Inst::CMPPS(['Vo', 'Wo', 'Ib'],{})

// Inst::MOVNTI(['Mdp', 'Gdp'],{})

// Inst::PINSRW(['Pq', 'Ew', 'Ib'],{})

// Inst::PEXTRW(['Gd', 'PRq', 'Ib'],{})

// Inst::SHUFPS(['Vps', 'Wps', 'Ib'],{})

// Unknown::unknown(([], {}))

// Inst::CMPSS(['Vd', 'Wd', 'Ib'],{})

// Inst::UD2([],{})

// Inst::CMPPD(['Vo', 'Wo', 'Ib'],{})

// Inst::PINSRW(['Vdw', 'Ew', 'Ib'],{})

// Inst::PEXTRW(['Gd', 'VRdq', 'Ib'],{})

// Inst::SHUFPD(['Vpd', 'Wpd', 'Ib'],{})

// Inst::UD2([],{})

// Inst::CMPSD(['Vq', 'Wq', 'Ib'],{})

// Inst::UD2([],{})

// Inst::UD2([],{})

// Inst::BSWAP_D(['Bd'],{})

// Inst::BSWAP_Q(['Bq'],{})

// Inst::UD2([],{})

// Inst::PSRLW(['Pq', 'Qq'],{})

// Inst::PSRLD(['Pq', 'Qq'],{})

// Inst::PSRLQ(['Pq', 'Qq'],{})

// Inst::PADDQ(['Pq', 'Qq'],{})

// Inst::PMULLW(['Pq', 'Qq'],{})

// Inst::PMOVMSKB(['Gd', 'PRq'],{})

// Inst::UD2([],{})

// Inst::MOVQ2DQ(['Vo', 'PRq'],{})

// Inst::UD2([],{})

// Inst::ADDSUBPD(['Vo', 'Wo'],{})

// Inst::PSRLW(['Vo', 'Wo'],{})

// Inst::PSRLD(['Vo', 'Wo'],{})

// Inst::PSRLQ(['Vo', 'Wo'],{})

// Inst::PADDQ(['Vo', 'Wo'],{})

// Inst::PMULLW(['Vo', 'Wo'],{})

// Inst::MOVQ(['Wq', 'Vq'],{})

// Inst::PMOVMSKB(['Gd', 'VRo'],{})

// Unknown::unknown(([], {}))

// WarnUnimpl::addsubps_Vo_Wo(([], {}))

// Inst::MOVDQ2Q(['Pq', 'VRq'],{})

// Inst::UD2([],{})

// Inst::UD2([],{})

// Inst::PSUBUSB(['Pq', 'Qq'],{})

// Inst::PSUBUSW(['Pq', 'Qq'],{})

// Inst::PMINUB(['Pq', 'Qq'],{})

// Inst::PAND(['Pq', 'Qq'],{})

// Inst::PADDUSB(['Pq', 'Qq'],{})

// Inst::PADDUSW(['Pq', 'Qq'],{})

// Inst::PMAXUB(['Pq', 'Qq'],{})

// Inst::PANDN(['Pq', 'Qq'],{})

// Unknown::unknown(([], {}))

// Inst::PSUBUSB(['Vo', 'Wo'],{})

// Inst::PSUBUSW(['Vo', 'Wo'],{})

// Inst::PMINUB(['Vo', 'Wo'],{})

// Inst::PAND(['Vo', 'Wo'],{})

// Inst::PADDUSB(['Vo', 'Wo'],{})

// Inst::PADDUSW(['Vo', 'Wo'],{})

// Inst::PMAXUB(['Vo', 'Wo'],{})

// Inst::PANDN(['Vo', 'Wo'],{})

// Unknown::unknown(([], {}))

// Inst::UD2([],{})

// Inst::PAVGB(['Pq', 'Qq'],{})

// Inst::PSRAW(['Pq', 'Qq'],{})

// Inst::PSRAD(['Pq', 'Qq'],{})

// Inst::PAVGW(['Pq', 'Qq'],{})

// Inst::PMULHUW(['Pq', 'Qq'],{})

// Inst::PMULHW(['Pq', 'Qq'],{})

// WarnUnimpl::movntq_Mq_Pq(([], {}))

// Inst::UD2([],{})

// Inst::CVTDQ2PD(['Vo', 'Wq'],{})

// Inst::UD2([],{})

// Inst::PAVGB(['Vo', 'Wo'],{})

// Inst::PSRAW(['Vo', 'Wo'],{})

// Inst::PSRAD(['Vo', 'Wo'],{})

// Inst::PAVGW(['Vo', 'Wo'],{})

// Inst::PMULHUW(['Vo', 'Wo'],{})

// Inst::PMULHW(['Vo', 'Wo'],{})

// Inst::CVTTPD2DQ(['Vo', 'Wo'],{})

// WarnUnimpl::movntdq_Mo_Vo(([], {}))

// Unknown::unknown(([], {}))

// Inst::CVTPD2DQ(['Vo', 'Wo'],{})

// Inst::UD2([],{})

// Inst::UD2([],{})

// Inst::PSUBSB(['Pq', 'Qq'],{})

// Inst::PSUBSW(['Pq', 'Qq'],{})

// Inst::PMINSW(['Pq', 'Qq'],{})

// Inst::POR(['Pq', 'Qq'],{})

// Inst::PADDSB(['Pq', 'Qq'],{})

// Inst::PADDSW(['Pq', 'Qq'],{})

// Inst::PMAXSW(['Pq', 'Qq'],{})

// Inst::PXOR(['Pq', 'Qq'],{})

// Unknown::unknown(([], {}))

// Inst::PSUBSB(['Vo', 'Wo'],{})

// Inst::PSUBSW(['Vo', 'Wo'],{})

// Inst::PMINSW(['Vo', 'Wo'],{})

// Inst::POR(['Vo', 'Wo'],{})

// Inst::PADDSB(['Vo', 'Wo'],{})

// Inst::PADDSW(['Vo', 'Wo'],{})

// Inst::PMAXSW(['Vo', 'Wo'],{})

// Inst::PXOR(['Vo', 'Wo'],{})

// Unknown::unknown(([], {}))

// Inst::UD2([],{})

// Inst::PSLLW(['Pq', 'Qq'],{})

// Inst::PSLLD(['Pq', 'Qq'],{})

// Inst::PSLLQ(['Pq', 'Qq'],{})

// Inst::PMULUDQ(['Pq', 'Qq'],{})

// Inst::PMADDWD(['Pq', 'Qq'],{})

// Inst::PSADBW(['Pq', 'Qq'],{})

// Inst::MASKMOVQ(['Pq', 'PRq'],{})

// Inst::UD2([],{})

// Inst::PSLLW(['Vo', 'Wo'],{})

// Inst::PSLLD(['Vo', 'Wo'],{})

// Inst::PSLLQ(['Vo', 'Wo'],{})

// Inst::PMULUDQ(['Vo', 'Wo'],{})

// Inst::PMADDWD(['Vo', 'Wo'],{})

// Inst::PSADBW(['Vo', 'Wo'],{})

// Inst::MASKMOVDQU(['Vo', 'VRo'],{})

// Inst::UD2([],{})

// WarnUnimpl::lddqu_Vo_Mo(([], {}))

// Inst::UD2([],{})

// Inst::UD2([],{})

// Inst::PSUBB(['Pq', 'Qq'],{})

// Inst::PSUBW(['Pq', 'Qq'],{})

// Inst::PSUBD(['Pq', 'Qq'],{})

// Inst::PSUBQ(['Pq', 'Qq'],{})

// Inst::PADDB(['Pq', 'Qq'],{})

// Inst::PADDW(['Pq', 'Qq'],{})

// Inst::PADDD(['Pq', 'Qq'],{})

// Inst::UD2([],{})

// Unknown::unknown(([], {}))

// Inst::PSUBB(['Vo', 'Wo'],{})

// Inst::PSUBW(['Vo', 'Wo'],{})

// Inst::PSUBD(['Vo', 'Wo'],{})

// Inst::PSUBQ(['Vo', 'Wo'],{})

// Inst::PADDB(['Vo', 'Wo'],{})

// Inst::PADDW(['Vo', 'Wo'],{})

// Inst::PADDD(['Vo', 'Wo'],{})

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

// MultiInst::OR_LOCKED((['OPCODE_OP_BOTTOM3', ['Gb'], ['Gv']], {}))

// MultiInst::ADC_LOCKED((['OPCODE_OP_BOTTOM3', ['Gb'], ['Gv']], {}))

// MultiInst::SBB_LOCKED((['OPCODE_OP_BOTTOM3', ['Gb'], ['Gv']], {}))

// MultiInst::AND_LOCKED((['OPCODE_OP_BOTTOM3', ['Gb'], ['Gv']], {}))

// MultiInst::SUB_LOCKED((['OPCODE_OP_BOTTOM3', ['Gb'], ['Gv']], {}))

// MultiInst::XOR_LOCKED((['OPCODE_OP_BOTTOM3', ['Gb'], ['Gv']], {}))

// Inst::ADD_LOCKED(['Mb', 'Ib'],{})

// Inst::OR_LOCKED(['Mb', 'Ib'],{})

// Inst::ADC_LOCKED(['Mb', 'Ib'],{})

// Inst::SBB_LOCKED(['Mb', 'Ib'],{})

// Inst::AND_LOCKED(['Mb', 'Ib'],{})

// Inst::SUB_LOCKED(['Mb', 'Ib'],{})

// Inst::XOR_LOCKED(['Mb', 'Ib'],{})

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

// Inst::XCHG_LOCKED(['Mv', 'Gv'],{})

// Unknown::unknown(([], {}))

// Inst::NOT_LOCKED(['Mb'],{})

// Inst::NEG_LOCKED(['Mb'],{})

// Unknown::unknown(([], {}))

// Inst::NOT_LOCKED(['Mv'],{})

// Inst::NEG_LOCKED(['Mv'],{})

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Inst::INC_LOCKED(['Mb'],{})

// Inst::DEC_LOCKED(['Mb'],{})

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

// Unknown::unknown(([], {}))

// Inst::CMPXCHG_LOCKED(['Mb', 'Gb'],{})

// Inst::CMPXCHG_LOCKED(['Mv', 'Gv'],{})

// Inst::BTR_LOCKED(['Mv', 'Gv'],{})

// Unknown::unknown(([], {}))

// Inst::BTS_LOCKED(['Mv', 'Ib'],{})

// Inst::BTR_LOCKED(['Mv', 'Ib'],{})

// Inst::BTC_LOCKED(['Mv', 'Ib'],{})

// Unknown::unknown(([], {}))

// Inst::BTC_LOCKED(['Mv', 'Gv'],{})

// Unknown::unknown(([], {}))

// Inst::XADD_LOCKED(['Mb', 'Gb'],{})

// Inst::XADD_LOCKED(['Mv', 'Gv'],{})

// Inst::CMPXCHG8B_LOCKED(['Mdp'],{})

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

#endif
