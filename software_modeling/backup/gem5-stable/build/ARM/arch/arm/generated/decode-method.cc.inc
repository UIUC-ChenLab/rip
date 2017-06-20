// DO NOT EDIT
// This file was automatically generated from an ISA description:
//   arm/isa/main.isa


StaticInstPtr
ArmISA::Decoder::decodeInst(ArmISA::ExtMachInst machInst)
{
    using namespace ArmISAInst;
  switch (DECODERFAULT) {
    
    case 0x0: 
      switch (THUMB) {
        
        case 0x0: 
          switch (AARCH64) {
            
            case 0x0: 
              switch (COND_CODE) {
                
                case 0xf:   
                  // ArmUnconditional::armUnconditional(([], {}))
                  
                      {
                          const IntRegIndex rn = (IntRegIndex)(uint32_t)bits(machInst, 19, 16);
                          const uint32_t op1 = bits(machInst, 27, 20);
                          if (bits(op1, 7) == 0) {
                              const uint32_t op2 = bits(machInst, 7, 4);
                              if (op1 == 0x10) {
                                  if (bits((uint32_t)rn, 0) == 1 && op2 == 0) {
                                      return new Setend(machInst, bits(machInst, 9));
                                  } else if (bits((uint32_t)rn, 0) == 0 && bits(op2, 1) == 0) {
                                      const bool enable = bits(machInst, 19, 18) == 0x2;
                                      const uint32_t mods = bits(machInst, 4, 0) |
                                                            (bits(machInst, 8, 6) << 5) |
                                                            (bits(machInst, 17) << 8) |
                                                            ((enable ? 1 : 0) << 9);
                                      return new Cps(machInst, mods);
                                  }
                              } else if (bits(op1, 6, 5) == 0x1) {
                                  return decodeNeonData(machInst);
                              } else if (bits(op1, 6, 4) == 0x4) {
                                  if (bits(op1, 0) == 0) {
                                      return decodeNeonMem(machInst);
                                  } else if (bits(op1, 2, 0) == 1) {
                                      // Unallocated memory hint
                                      return new NopInst(machInst);
                                  } else if (bits(op1, 2, 0) == 5) {
                                      const bool add = bits(machInst, 23);
                                      const uint32_t imm12 = bits(machInst, 11, 0);
                                      if (add) {
                                          return new PLI_LOAD_IMM_AY_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO,
                                                                  rn, add, imm12);
                                      } else {
                                          return new PLI_LOAD_IMM_AN_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO,
                                                                  rn, add, imm12);
                                      }
                                  }
                              } else if (bits(op1, 6, 4) == 0x5) {
                                  if (bits(op1, 1, 0) == 0x1) {
                                      const bool add = bits(machInst, 23);
                                      const bool pldw = bits(machInst, 22);
                                      const uint32_t imm12 = bits(machInst, 11, 0);
                                      if (pldw) {
                                          if (add) {
                                              return new PLDW_LOAD_IMM_AY_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO,
                                                                       rn, add, imm12);
                                          } else {
                                              return new PLDW_LOAD_IMM_AN_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO,
                                                                       rn, add, imm12);
                                          }
                                      } else {
                                          if (add) {
                                              return new PLD_LOAD_IMM_AY_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO,
                                                                      rn, add, imm12);
                                          } else {
                                              return new PLD_LOAD_IMM_AN_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO,
                                                                      rn, add, imm12);
                                          }
                                      }
                                  } else if (op1 == 0x57) {
                                      switch (op2) {
                                        case 0x1:
                                          return new Clrex(machInst);
                                        case 0x4:
                                          return new Dsb(machInst, 0);
                                        case 0x5:
                                          return new Dmb(machInst, 0);
                                        case 0x6:
                                          return new Isb(machInst, 0);
                                      }
                                  }
                              } else if (bits(op2, 0) == 0) {
                                  switch (op1 & 0xf7) {
                                    case 0x61:
                                      // Unallocated memory hint
                                      return new NopInst(machInst);
                                    case 0x65:
                                      {
                                          const uint32_t imm5 = bits(machInst, 11, 7);
                                          const uint32_t type = bits(machInst, 6, 5);
                                          const bool add = bits(machInst, 23);
                                          const IntRegIndex rm =
                                              (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                          if (add) {
                                              return new PLI_LOAD_REG_AY_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO, rn,
                                                                      add, imm5, type, rm);
                                          } else {
                                              return new PLI_LOAD_REG_AN_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO, rn,
                                                                      add, imm5, type, rm);
                                          }
                                      }
                                    case 0x71:
                                    case 0x75:
                                      {
                                          const uint32_t imm5 = bits(machInst, 11, 7);
                                          const uint32_t type = bits(machInst, 6, 5);
                                          const bool add = bits(machInst, 23);
                                          const bool pldw = bits(machInst, 22);
                                          const IntRegIndex rm =
                                              (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                          if (pldw) {
                                              if (add) {
                                                  return new PLDW_LOAD_REG_AY_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO,
                                                                           rn, add, imm5,
                                                                           type, rm);
                                              } else {
                                                  return new PLDW_LOAD_REG_AN_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO,
                                                                           rn, add, imm5,
                                                                           type, rm);
                                              }
                                          } else {
                                              if (add) {
                                                  return new PLD_LOAD_REG_AY_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO,
                                                                          rn, add, imm5,
                                                                          type, rm);
                                              } else {
                                                  return new PLD_LOAD_REG_AN_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO,
                                                                          rn, add, imm5,
                                                                          type, rm);
                                              }
                                          }
                                      }
                                  }
                              }
                          } else {
                              switch (bits(machInst, 26, 25)) {
                                case 0x0:
                                  {
                                      const uint32_t val = ((machInst >> 20) & 0x5);
                                      if (val == 0x4) {
                                          const uint32_t mode = bits(machInst, 4, 0);
                                          if (badMode32((OperatingMode)mode))
                                              return new Unknown(machInst);
                                          switch (bits(machInst, 24, 21)) {
                                            case 0x2:
                                              return new SRS_STORE_IMM_AN_PY_SN_UN_WN_SZ8(machInst, mode,
                                                      SrsOp::DecrementAfter, false);
                                            case 0x3:
                                              return new SRS_STORE_IMM_AN_PY_SN_UN_WY_SZ8(machInst, mode,
                                                      SrsOp::DecrementAfter, true);
                                            case 0x6:
                                              return new SRS_STORE_IMM_AY_PY_SN_UN_WN_SZ8(machInst, mode,
                                                      SrsOp::IncrementAfter, false);
                                            case 0x7:
                                              return new SRS_STORE_IMM_AY_PY_SN_UN_WY_SZ8(machInst, mode,
                                                      SrsOp::IncrementAfter, true);
                                            case 0xa:
                                              return new SRS_STORE_IMM_AN_PN_SN_UN_WN_SZ8(machInst, mode,
                                                      SrsOp::DecrementBefore, false);
                                            case 0xb:
                                              return new SRS_STORE_IMM_AN_PN_SN_UN_WY_SZ8(machInst, mode,
                                                      SrsOp::DecrementBefore, true);
                                            case 0xe:
                                              return new SRS_STORE_IMM_AY_PN_SN_UN_WN_SZ8(machInst, mode,
                                                      SrsOp::IncrementBefore, false);
                                            case 0xf:
                                              return new SRS_STORE_IMM_AY_PN_SN_UN_WY_SZ8(machInst, mode,
                                                      SrsOp::IncrementBefore, true);
                                          }
                                          return new Unknown(machInst);
                                      } else if (val == 0x1) {
                                          switch (bits(machInst, 24, 21)) {
                                            case 0x0:
                                              return new RFE_LOAD_IMM_AN_PY_SN_UN_WN_SZ8(machInst, rn,
                                                      RfeOp::DecrementAfter, false);
                                            case 0x1:
                                              return new RFE_LOAD_IMM_AN_PY_SN_UN_WY_SZ8(machInst, rn,
                                                      RfeOp::DecrementAfter, true);
                                            case 0x4:
                                              return new RFE_LOAD_IMM_AY_PY_SN_UN_WN_SZ8(machInst, rn,
                                                      RfeOp::IncrementAfter, false);
                                            case 0x5:
                                              return new RFE_LOAD_IMM_AY_PY_SN_UN_WY_SZ8(machInst, rn,
                                                      RfeOp::IncrementAfter, true);
                                            case 0x8:
                                              return new RFE_LOAD_IMM_AN_PN_SN_UN_WN_SZ8(machInst, rn,
                                                      RfeOp::DecrementBefore, false);
                                            case 0x9:
                                              return new RFE_LOAD_IMM_AN_PN_SN_UN_WY_SZ8(machInst, rn,
                                                      RfeOp::DecrementBefore, true);
                                            case 0xc:
                                              return new RFE_LOAD_IMM_AY_PN_SN_UN_WN_SZ8(machInst, rn,
                                                      RfeOp::IncrementBefore, false);
                                            case 0xd:
                                              return new RFE_LOAD_IMM_AY_PN_SN_UN_WY_SZ8(machInst, rn,
                                                      RfeOp::IncrementBefore, true);
                                          }
                                          return new Unknown(machInst);
                                      }
                                  }
                                  break;
                                case 0x1:
                                  {
                                      const uint32_t imm =
                                          (sext<26>(bits(machInst, 23, 0) << 2)) |
                                          (bits(machInst, 24) << 1);
                                      return new BlxImm(machInst, imm, COND_UC);
                                  }
                                case 0x2:
                                  if (bits(op1, 4, 0) != 0) {
                                      if (CPNUM == 0xa || CPNUM == 0xb) {
                                          return decodeExtensionRegLoadStore(machInst);
                                      }
                                      if (bits(op1, 0) == 1) {
                                          if (rn == INTREG_PC) {
                                              if (bits(op1, 4, 3) != 0x0) {
                                                  return new WarnUnimplemented(
                                                          "ldc, ldc2 (literal)", machInst);
                                              }
                                          } else {
                                              if (op1 == 0xC3 || op1 == 0xC7) {
                                                  return new WarnUnimplemented(
                                                          "ldc, ldc2 (immediate)", machInst);
                                              }
                                          }
                                      } else {
                                          if (bits(op1, 4, 3) != 0 || bits(op1, 1) == 1) {
                                              return new WarnUnimplemented(
                                                      "stc, stc2", machInst);
                                          }
                                      }
                                  }
                                  break;
                                case 0x3:
                                  if (bits(op1, 4) == 0) {
                                      if (CPNUM == 0xa || CPNUM == 0xb) {
                                          return decodeShortFpTransfer(machInst);
                                      } else if (CPNUM == 0xe) {
                                          return decodeMcrMrc14(machInst);
                                      } else if (CPNUM == 0xf) {
                                          return decodeMcrMrc15(machInst);
                                      }
                                      const bool op = bits(machInst, 4);
                                      if (op) {
                                          if (bits(op1, 0)) {
                                              return new WarnUnimplemented(
                                                      "mrc, mrc2", machInst);
                                          } else {
                                              return new WarnUnimplemented(
                                                      "mcr, mcr2", machInst);
                                          }
                                      } else {
                                          return new WarnUnimplemented("cdp, cdp2", machInst);
                                      }
                                  }
                                  break;
                              }
                          }
                          return new Unknown(machInst);
                      }
                      break;
                
                default:
                  switch (ENCODING) {
                    
                    case 0x0: 
                      switch (SEVEN_AND_FOUR) {
                        
                        case 0x1: 
                          switch (MISC_OPCODE) {
                            
                            case 0x9: 
                              switch (PREPOST) {
                                
                                case 0x0:   
                                  // ArmMultAndMultAcc::armMultAndMultAcc(([], {}))
                                  
                                      {
                                          // The manual defines this field as 23-20, but bit 20 is usually
                                          // ignored.
                                          const uint32_t op = bits(machInst, 23, 21);
                                          const bool s = bits(machInst, 20);
                                          const IntRegIndex rd = (IntRegIndex)(uint32_t)bits(machInst, 19, 16);
                                          const IntRegIndex ra = (IntRegIndex)(uint32_t)bits(machInst, 15, 12);
                                          const IntRegIndex rm = (IntRegIndex)(uint32_t)bits(machInst, 11, 8);
                                          const IntRegIndex rn = (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                          switch (op) {
                                              case 0x0:
                                                if (s) {
                                                    return new MulCc(machInst, rd, rm, rn);
                                                } else {
                                                    return new Mul(machInst, rd, rm, rn);
                                                }
                                              case 0x1:
                                                if (s) {
                                                    return new MlaCc(machInst, rd, rn, rm, ra);
                                                } else {
                                                    return new Mla(machInst, rd, rn, rm, ra);
                                                }
                                              case 0x2:
                                                return new Umaal(machInst, ra, rd, rn, rm);
                                              case 0x3:
                                                return new Mls(machInst, rd, rn, rm, ra);
                                              case 0x4:
                                                if (s) {
                                                    return new UmullCc(machInst, ra, rd, rn, rm);
                                                } else {
                                                    return new Umull(machInst, ra, rd, rn, rm);
                                                }
                                              case 0x5:
                                                if (s) {
                                                    return new UmlalCc(machInst, ra, rd, rn, rm);
                                                } else {
                                                    return new Umlal(machInst, ra, rd, rn, rm);
                                                }
                                              case 0x6:
                                                if (s) {
                                                    return new SmullCc(machInst, ra, rd, rn, rm);
                                                } else {
                                                    return new Smull(machInst, ra, rd, rn, rm);
                                                }
                                              case 0x7:
                                                if (s) {
                                                    return new SmlalCc(machInst, ra, rd, rn, rm);
                                                } else {
                                                    return new Smlal(machInst, ra, rd, rn, rm);
                                                }
                                          }
                                      }
                                      break;
                                
                                case 0x1:   
                                  // ArmSyncMem::armSyncMem(([], {}))
                                  
                                      {
                                          const IntRegIndex rn = (IntRegIndex)(uint32_t)bits(machInst, 19, 16);
                                          const IntRegIndex rt = (IntRegIndex)(uint32_t)bits(machInst, 15, 12);
                                          const IntRegIndex rt2 = (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                          switch (PUBWL) {
                                            case 0x10:
                                              return new Swp(machInst, rt, rt2, rn);
                                            case 0x14:
                                              return new Swpb(machInst, rt, rt2, rn);
                                            case 0x18:
                                              return new STREX_STORE_IMM_AY_PN_SN_UN_WN_SZ4(machInst, rt, rt2, rn, true, 0);
                                            case 0x19:
                                              return new LDREX_LOAD_IMM_AY_PN_SN_UN_WN_SZ4(machInst, rt, rn, true, 0);
                                            case 0x1a:
                                              return new STREXD_STORE_IMMD_AY_PN_SN_UN_WN_SZ4(machInst, rt, rt2, rt2 + 1, rn, true, 0);
                                            case 0x1b:
                                              return new LDREXD_LOAD_IMMD_AY_PN_SN_UN_WN_SZ4(machInst, rt, rt + 1, rn, true, 0);
                                            case 0x1c:
                                              return new STREXB_STORE_IMM_AY_PN_SN_UN_WN_SZ1(machInst, rt, rt2, rn, true, 0);
                                            case 0x1d:
                                              return new LDREXB_LOAD_IMM_AY_PN_SN_UN_WN_SZ1(machInst, rt, rn, true, 0);
                                            case 0x1e:
                                              return new STREXH_STORE_IMM_AY_PN_SN_UN_WN_SZ2(machInst, rt, rt2, rn, true, 0);
                                            case 0x1f:
                                              return new LDREXH_LOAD_IMM_AY_PN_SN_UN_WN_SZ2(machInst, rt, rn, true, 0);
                                            default:
                                              return new Unknown(machInst);
                                          }
                                      }
                                      break;
                                
                                default:
                                  
                                  // Unknown::unknown(([], {}))
                                  return new Unknown(machInst);
                                  break;
                                }
                              
                            case 0xb: case 0xd: case 0xf:   
                              // AddrMode3::addrMode3(([], {}))
                              
                                  {
                                      const uint32_t op1 = bits(machInst, 24, 20);
                                      const uint32_t op2 = bits(machInst, 6, 5);
                                      const uint32_t puiw = bits(machInst, 24, 21);
                                      const uint32_t imm = IMMED_HI_11_8 << 4 | IMMED_LO_3_0;
                                      switch (op2) {
                                        case 0x1:
                                          if (op1 & 0x1) {
                                              switch (puiw) {
                              
                                        case 0x0:
                                          return new LOAD_REG_AN_PY_SN_UN_WY_SZ2(machInst, RT, RN, false, 0, LSL, RM);
                              
                                        case 0x1:
                                          return new LOAD_REG_AN_PY_SN_UY_WY_SZ2(machInst, RT, RN, false, 0, LSL, RM);
                              
                                        case 0x2:
                                          return new LOAD_IMM_AN_PY_SN_UN_WY_SZ2(machInst, RT, RN, false, imm);
                              
                                        case 0x3:
                                          return new LOAD_IMM_AN_PY_SN_UY_WY_SZ2(machInst, RT, RN, false, imm);
                              
                                        case 0x4:
                                          return new LOAD_REG_AY_PY_SN_UN_WY_SZ2(machInst, RT, RN, true, 0, LSL, RM);
                              
                                        case 0x5:
                                          return new LOAD_REG_AY_PY_SN_UY_WY_SZ2(machInst, RT, RN, true, 0, LSL, RM);
                              
                                        case 0x6:
                                          return new LOAD_IMM_AY_PY_SN_UN_WY_SZ2(machInst, RT, RN, true, imm);
                              
                                        case 0x7:
                                          return new LOAD_IMM_AY_PY_SN_UY_WY_SZ2(machInst, RT, RN, true, imm);
                              
                                        case 0x8:
                                          return new LOAD_REG_AN_PN_SN_UN_WN_SZ2(machInst, RT, RN, false, 0, LSL, RM);
                              
                                        case 0x9:
                                          return new LOAD_REG_AN_PN_SN_UN_WY_SZ2(machInst, RT, RN, false, 0, LSL, RM);
                              
                                        case 0xa:
                                          return new LOAD_IMM_AN_PN_SN_UN_WN_SZ2(machInst, RT, RN, false, imm);
                              
                                        case 0xb:
                                          return new LOAD_IMM_AN_PN_SN_UN_WY_SZ2(machInst, RT, RN, false, imm);
                              
                                        case 0xc:
                                          return new LOAD_REG_AY_PN_SN_UN_WN_SZ2(machInst, RT, RN, true, 0, LSL, RM);
                              
                                        case 0xd:
                                          return new LOAD_REG_AY_PN_SN_UN_WY_SZ2(machInst, RT, RN, true, 0, LSL, RM);
                              
                                        case 0xe:
                                          return new LOAD_IMM_AY_PN_SN_UN_WN_SZ2(machInst, RT, RN, true, imm);
                              
                                        case 0xf:
                                          return new LOAD_IMM_AY_PN_SN_UN_WY_SZ2(machInst, RT, RN, true, imm);
                              
                                        default:
                                          return new Unknown(machInst);
                                      }
                                      
                                          } else {
                                              switch (puiw) {
                              
                                        case 0x0:
                                          return new STORE_REG_AN_PY_SN_UN_WY_SZ2(machInst, RT, RN, false, 0, LSL, RM);
                              
                                        case 0x1:
                                          return new STORE_REG_AN_PY_SN_UY_WY_SZ2(machInst, RT, RN, false, 0, LSL, RM);
                              
                                        case 0x2:
                                          return new STORE_IMM_AN_PY_SN_UN_WY_SZ2(machInst, RT, RN, false, imm);
                              
                                        case 0x3:
                                          return new STORE_IMM_AN_PY_SN_UY_WY_SZ2(machInst, RT, RN, false, imm);
                              
                                        case 0x4:
                                          return new STORE_REG_AY_PY_SN_UN_WY_SZ2(machInst, RT, RN, true, 0, LSL, RM);
                              
                                        case 0x5:
                                          return new STORE_REG_AY_PY_SN_UY_WY_SZ2(machInst, RT, RN, true, 0, LSL, RM);
                              
                                        case 0x6:
                                          return new STORE_IMM_AY_PY_SN_UN_WY_SZ2(machInst, RT, RN, true, imm);
                              
                                        case 0x7:
                                          return new STORE_IMM_AY_PY_SN_UY_WY_SZ2(machInst, RT, RN, true, imm);
                              
                                        case 0x8:
                                          return new STORE_REG_AN_PN_SN_UN_WN_SZ2(machInst, RT, RN, false, 0, LSL, RM);
                              
                                        case 0x9:
                                          return new STORE_REG_AN_PN_SN_UN_WY_SZ2(machInst, RT, RN, false, 0, LSL, RM);
                              
                                        case 0xa:
                                          return new STORE_IMM_AN_PN_SN_UN_WN_SZ2(machInst, RT, RN, false, imm);
                              
                                        case 0xb:
                                          return new STORE_IMM_AN_PN_SN_UN_WY_SZ2(machInst, RT, RN, false, imm);
                              
                                        case 0xc:
                                          return new STORE_REG_AY_PN_SN_UN_WN_SZ2(machInst, RT, RN, true, 0, LSL, RM);
                              
                                        case 0xd:
                                          return new STORE_REG_AY_PN_SN_UN_WY_SZ2(machInst, RT, RN, true, 0, LSL, RM);
                              
                                        case 0xe:
                                          return new STORE_IMM_AY_PN_SN_UN_WN_SZ2(machInst, RT, RN, true, imm);
                              
                                        case 0xf:
                                          return new STORE_IMM_AY_PN_SN_UN_WY_SZ2(machInst, RT, RN, true, imm);
                              
                                        default:
                                          return new Unknown(machInst);
                                      }
                                      
                                          }
                                        case 0x2:
                                          if (op1 & 0x1) {
                                              switch (puiw) {
                              
                                        case 0x0:
                                          return new LOAD_REG_AN_PY_SY_UN_WY_SZ1(machInst, RT, RN, false, 0, LSL, RM);
                              
                                        case 0x1:
                                          return new LOAD_REG_AN_PY_SY_UY_WY_SZ1(machInst, RT, RN, false, 0, LSL, RM);
                              
                                        case 0x2:
                                          return new LOAD_IMM_AN_PY_SY_UN_WY_SZ1(machInst, RT, RN, false, imm);
                              
                                        case 0x3:
                                          return new LOAD_IMM_AN_PY_SY_UY_WY_SZ1(machInst, RT, RN, false, imm);
                              
                                        case 0x4:
                                          return new LOAD_REG_AY_PY_SY_UN_WY_SZ1(machInst, RT, RN, true, 0, LSL, RM);
                              
                                        case 0x5:
                                          return new LOAD_REG_AY_PY_SY_UY_WY_SZ1(machInst, RT, RN, true, 0, LSL, RM);
                              
                                        case 0x6:
                                          return new LOAD_IMM_AY_PY_SY_UN_WY_SZ1(machInst, RT, RN, true, imm);
                              
                                        case 0x7:
                                          return new LOAD_IMM_AY_PY_SY_UY_WY_SZ1(machInst, RT, RN, true, imm);
                              
                                        case 0x8:
                                          return new LOAD_REG_AN_PN_SY_UN_WN_SZ1(machInst, RT, RN, false, 0, LSL, RM);
                              
                                        case 0x9:
                                          return new LOAD_REG_AN_PN_SY_UN_WY_SZ1(machInst, RT, RN, false, 0, LSL, RM);
                              
                                        case 0xa:
                                          return new LOAD_IMM_AN_PN_SY_UN_WN_SZ1(machInst, RT, RN, false, imm);
                              
                                        case 0xb:
                                          return new LOAD_IMM_AN_PN_SY_UN_WY_SZ1(machInst, RT, RN, false, imm);
                              
                                        case 0xc:
                                          return new LOAD_REG_AY_PN_SY_UN_WN_SZ1(machInst, RT, RN, true, 0, LSL, RM);
                              
                                        case 0xd:
                                          return new LOAD_REG_AY_PN_SY_UN_WY_SZ1(machInst, RT, RN, true, 0, LSL, RM);
                              
                                        case 0xe:
                                          return new LOAD_IMM_AY_PN_SY_UN_WN_SZ1(machInst, RT, RN, true, imm);
                              
                                        case 0xf:
                                          return new LOAD_IMM_AY_PN_SY_UN_WY_SZ1(machInst, RT, RN, true, imm);
                              
                                        default:
                                          return new Unknown(machInst);
                                      }
                                      
                                          } else if ((RT % 2) == 0) {
                                              switch (puiw) {
                              
                                        case 0x0:
                                          return new LOAD_REGD_AN_PY_SN_UN_WY_SZ4(machInst, RT & ~1, RT | 1, RN, false, 0, LSL, RM);
                              
                                        case 0x1:
                                          return new LOAD_REGD_AN_PY_SN_UN_WY_SZ4(machInst, RT & ~1, RT | 1, RN, false, 0, LSL, RM);
                              
                                        case 0x2:
                                          return new LOAD_IMMD_AN_PY_SN_UN_WY_SZ4(machInst, RT & ~1, RT | 1, RN, false, imm);
                              
                                        case 0x3:
                                          return new LOAD_IMMD_AN_PY_SN_UN_WY_SZ4(machInst, RT & ~1, RT | 1, RN, false, imm);
                              
                                        case 0x4:
                                          return new LOAD_REGD_AY_PY_SN_UN_WY_SZ4(machInst, RT & ~1, RT | 1, RN, true, 0, LSL, RM);
                              
                                        case 0x5:
                                          return new LOAD_REGD_AY_PY_SN_UN_WY_SZ4(machInst, RT & ~1, RT | 1, RN, true, 0, LSL, RM);
                              
                                        case 0x6:
                                          return new LOAD_IMMD_AY_PY_SN_UN_WY_SZ4(machInst, RT & ~1, RT | 1, RN, true, imm);
                              
                                        case 0x7:
                                          return new LOAD_IMMD_AY_PY_SN_UN_WY_SZ4(machInst, RT & ~1, RT | 1, RN, true, imm);
                              
                                        case 0x8:
                                          return new LOAD_REGD_AN_PN_SN_UN_WN_SZ4(machInst, RT & ~1, RT | 1, RN, false, 0, LSL, RM);
                              
                                        case 0x9:
                                          return new LOAD_REGD_AN_PN_SN_UN_WY_SZ4(machInst, RT & ~1, RT | 1, RN, false, 0, LSL, RM);
                              
                                        case 0xa:
                                          return new LOAD_IMMD_AN_PN_SN_UN_WN_SZ4(machInst, RT & ~1, RT | 1, RN, false, imm);
                              
                                        case 0xb:
                                          return new LOAD_IMMD_AN_PN_SN_UN_WY_SZ4(machInst, RT & ~1, RT | 1, RN, false, imm);
                              
                                        case 0xc:
                                          return new LOAD_REGD_AY_PN_SN_UN_WN_SZ4(machInst, RT & ~1, RT | 1, RN, true, 0, LSL, RM);
                              
                                        case 0xd:
                                          return new LOAD_REGD_AY_PN_SN_UN_WY_SZ4(machInst, RT & ~1, RT | 1, RN, true, 0, LSL, RM);
                              
                                        case 0xe:
                                          return new LOAD_IMMD_AY_PN_SN_UN_WN_SZ4(machInst, RT & ~1, RT | 1, RN, true, imm);
                              
                                        case 0xf:
                                          return new LOAD_IMMD_AY_PN_SN_UN_WY_SZ4(machInst, RT & ~1, RT | 1, RN, true, imm);
                              
                                        default:
                                          return new Unknown(machInst);
                                      }
                                      
                                          } else {
                                              return new Unknown(machInst);
                                          }
                                        case 0x3:
                                          if (op1 & 0x1) {
                                              switch (puiw) {
                              
                                        case 0x0:
                                          return new LOAD_REG_AN_PY_SY_UN_WY_SZ2(machInst, RT, RN, false, 0, LSL, RM);
                              
                                        case 0x1:
                                          return new LOAD_REG_AN_PY_SY_UY_WY_SZ2(machInst, RT, RN, false, 0, LSL, RM);
                              
                                        case 0x2:
                                          return new LOAD_IMM_AN_PY_SY_UN_WY_SZ2(machInst, RT, RN, false, imm);
                              
                                        case 0x3:
                                          return new LOAD_IMM_AN_PY_SY_UY_WY_SZ2(machInst, RT, RN, false, imm);
                              
                                        case 0x4:
                                          return new LOAD_REG_AY_PY_SY_UN_WY_SZ2(machInst, RT, RN, true, 0, LSL, RM);
                              
                                        case 0x5:
                                          return new LOAD_REG_AY_PY_SY_UY_WY_SZ2(machInst, RT, RN, true, 0, LSL, RM);
                              
                                        case 0x6:
                                          return new LOAD_IMM_AY_PY_SY_UN_WY_SZ2(machInst, RT, RN, true, imm);
                              
                                        case 0x7:
                                          return new LOAD_IMM_AY_PY_SY_UY_WY_SZ2(machInst, RT, RN, true, imm);
                              
                                        case 0x8:
                                          return new LOAD_REG_AN_PN_SY_UN_WN_SZ2(machInst, RT, RN, false, 0, LSL, RM);
                              
                                        case 0x9:
                                          return new LOAD_REG_AN_PN_SY_UN_WY_SZ2(machInst, RT, RN, false, 0, LSL, RM);
                              
                                        case 0xa:
                                          return new LOAD_IMM_AN_PN_SY_UN_WN_SZ2(machInst, RT, RN, false, imm);
                              
                                        case 0xb:
                                          return new LOAD_IMM_AN_PN_SY_UN_WY_SZ2(machInst, RT, RN, false, imm);
                              
                                        case 0xc:
                                          return new LOAD_REG_AY_PN_SY_UN_WN_SZ2(machInst, RT, RN, true, 0, LSL, RM);
                              
                                        case 0xd:
                                          return new LOAD_REG_AY_PN_SY_UN_WY_SZ2(machInst, RT, RN, true, 0, LSL, RM);
                              
                                        case 0xe:
                                          return new LOAD_IMM_AY_PN_SY_UN_WN_SZ2(machInst, RT, RN, true, imm);
                              
                                        case 0xf:
                                          return new LOAD_IMM_AY_PN_SY_UN_WY_SZ2(machInst, RT, RN, true, imm);
                              
                                        default:
                                          return new Unknown(machInst);
                                      }
                                      
                                          } else {
                                              switch (puiw) {
                              
                                        case 0x0:
                                          return new STORE_REGD_AN_PY_SN_UN_WY_SZ4(machInst, RT & ~1, RT | 1, RN, false, 0, LSL, RM);
                              
                                        case 0x1:
                                          return new STORE_REGD_AN_PY_SN_UN_WY_SZ4(machInst, RT & ~1, RT | 1, RN, false, 0, LSL, RM);
                              
                                        case 0x2:
                                          return new STORE_IMMD_AN_PY_SN_UN_WY_SZ4(machInst, RT & ~1, RT | 1, RN, false, imm);
                              
                                        case 0x3:
                                          return new STORE_IMMD_AN_PY_SN_UN_WY_SZ4(machInst, RT & ~1, RT | 1, RN, false, imm);
                              
                                        case 0x4:
                                          return new STORE_REGD_AY_PY_SN_UN_WY_SZ4(machInst, RT & ~1, RT | 1, RN, true, 0, LSL, RM);
                              
                                        case 0x5:
                                          return new STORE_REGD_AY_PY_SN_UN_WY_SZ4(machInst, RT & ~1, RT | 1, RN, true, 0, LSL, RM);
                              
                                        case 0x6:
                                          return new STORE_IMMD_AY_PY_SN_UN_WY_SZ4(machInst, RT & ~1, RT | 1, RN, true, imm);
                              
                                        case 0x7:
                                          return new STORE_IMMD_AY_PY_SN_UN_WY_SZ4(machInst, RT & ~1, RT | 1, RN, true, imm);
                              
                                        case 0x8:
                                          return new STORE_REGD_AN_PN_SN_UN_WN_SZ4(machInst, RT & ~1, RT | 1, RN, false, 0, LSL, RM);
                              
                                        case 0x9:
                                          return new STORE_REGD_AN_PN_SN_UN_WY_SZ4(machInst, RT & ~1, RT | 1, RN, false, 0, LSL, RM);
                              
                                        case 0xa:
                                          return new STORE_IMMD_AN_PN_SN_UN_WN_SZ4(machInst, RT & ~1, RT | 1, RN, false, imm);
                              
                                        case 0xb:
                                          return new STORE_IMMD_AN_PN_SN_UN_WY_SZ4(machInst, RT & ~1, RT | 1, RN, false, imm);
                              
                                        case 0xc:
                                          return new STORE_REGD_AY_PN_SN_UN_WN_SZ4(machInst, RT & ~1, RT | 1, RN, true, 0, LSL, RM);
                              
                                        case 0xd:
                                          return new STORE_REGD_AY_PN_SN_UN_WY_SZ4(machInst, RT & ~1, RT | 1, RN, true, 0, LSL, RM);
                              
                                        case 0xe:
                                          return new STORE_IMMD_AY_PN_SN_UN_WN_SZ4(machInst, RT & ~1, RT | 1, RN, true, imm);
                              
                                        case 0xf:
                                          return new STORE_IMMD_AY_PN_SN_UN_WY_SZ4(machInst, RT & ~1, RT | 1, RN, true, imm);
                              
                                        default:
                                          return new Unknown(machInst);
                                      }
                                      
                                          }
                                        default:
                                          return new Unknown(machInst);
                                      }
                                  }
                                  break;
                            
                            default:
                              
                              // Unknown::unknown(([], {}))
                              return new Unknown(machInst);
                              break;
                            }
                          
                        case 0x0: 
                          switch (IS_MISC) {
                            
                            case 0x0:   
                              // ArmDataProcReg::armDataProcReg(([], {}))
                              
                                  {
                                      const bool immShift = (bits(machInst, 4) == 0);
                                      const bool setCc = (bits(machInst, 20) == 1);
                                      const uint32_t imm5 = bits(machInst, 11, 7);
                                      const ArmShiftType type = (ArmShiftType)(uint32_t)bits(machInst, 6, 5);
                                      const IntRegIndex rd = (IntRegIndex)(uint32_t)RD;
                                      const IntRegIndex rn = (IntRegIndex)(uint32_t)RN;
                                      const IntRegIndex rm = (IntRegIndex)(uint32_t)RM;
                                      const IntRegIndex rs = (IntRegIndex)(uint32_t)RS;
                                      switch (OPCODE) {
                                  
                                        case 0x0:
                                          if (immShift) {
                                              if (setCc) {
                                                  if (rd == INTREG_PC) {
                                                      
                                      return new AndsRegPclr(machInst, rd,
                                                                      rn, rm, imm5,
                                                                      type);
                                  
                                                  } else {
                                                      return new AndRegCc(machInst, rd,
                                                                                    rn, rm, imm5, type);
                                                  }
                                              } else {
                                                  return new AndReg(machInst, rd, rn,
                                                                               rm, imm5, type);
                                              }
                                          } else {
                                              if (setCc) {
                                                  return new AndRegRegCc(machInst, rd,
                                                                                    rn, rm, rs, type);
                                              } else {
                                                  return new AndRegReg(machInst, rd,
                                                                                  rn, rm, rs, type);
                                              }
                                          }
                                          break;
                                  
                                        case 0x1:
                                          if (immShift) {
                                              if (setCc) {
                                                  if (rd == INTREG_PC) {
                                                      
                                      return new EorsRegPclr(machInst, rd,
                                                                      rn, rm, imm5,
                                                                      type);
                                  
                                                  } else {
                                                      return new EorRegCc(machInst, rd,
                                                                                    rn, rm, imm5, type);
                                                  }
                                              } else {
                                                  return new EorReg(machInst, rd, rn,
                                                                               rm, imm5, type);
                                              }
                                          } else {
                                              if (setCc) {
                                                  return new EorRegRegCc(machInst, rd,
                                                                                    rn, rm, rs, type);
                                              } else {
                                                  return new EorRegReg(machInst, rd,
                                                                                  rn, rm, rs, type);
                                              }
                                          }
                                          break;
                                  
                                        case 0x2:
                                          if (immShift) {
                                              if (setCc) {
                                                  if (rd == INTREG_PC) {
                                                      
                                      return new SubsRegPclr(machInst, rd,
                                                                      rn, rm, imm5,
                                                                      type);
                                  
                                                  } else {
                                                      return new SubRegCc(machInst, rd,
                                                                                    rn, rm, imm5, type);
                                                  }
                                              } else {
                                                  return new SubReg(machInst, rd, rn,
                                                                               rm, imm5, type);
                                              }
                                          } else {
                                              if (setCc) {
                                                  return new SubRegRegCc(machInst, rd,
                                                                                    rn, rm, rs, type);
                                              } else {
                                                  return new SubRegReg(machInst, rd,
                                                                                  rn, rm, rs, type);
                                              }
                                          }
                                          break;
                                  
                                        case 0x3:
                                          if (immShift) {
                                              if (setCc) {
                                                  if (rd == INTREG_PC) {
                                                      
                                      return new RsbsRegPclr(machInst, rd,
                                                                      rn, rm, imm5,
                                                                      type);
                                  
                                                  } else {
                                                      return new RsbRegCc(machInst, rd,
                                                                                    rn, rm, imm5, type);
                                                  }
                                              } else {
                                                  return new RsbReg(machInst, rd, rn,
                                                                               rm, imm5, type);
                                              }
                                          } else {
                                              if (setCc) {
                                                  return new RsbRegRegCc(machInst, rd,
                                                                                    rn, rm, rs, type);
                                              } else {
                                                  return new RsbRegReg(machInst, rd,
                                                                                  rn, rm, rs, type);
                                              }
                                          }
                                          break;
                                  
                                        case 0x4:
                                          if (immShift) {
                                              if (setCc) {
                                                  if (rd == INTREG_PC) {
                                                      
                                      return new AddsRegPclr(machInst, rd,
                                                                      rn, rm, imm5,
                                                                      type);
                                  
                                                  } else {
                                                      return new AddRegCc(machInst, rd,
                                                                                    rn, rm, imm5, type);
                                                  }
                                              } else {
                                                  return new AddReg(machInst, rd, rn,
                                                                               rm, imm5, type);
                                              }
                                          } else {
                                              if (setCc) {
                                                  return new AddRegRegCc(machInst, rd,
                                                                                    rn, rm, rs, type);
                                              } else {
                                                  return new AddRegReg(machInst, rd,
                                                                                  rn, rm, rs, type);
                                              }
                                          }
                                          break;
                                  
                                        case 0x5:
                                          if (immShift) {
                                              if (setCc) {
                                                  if (rd == INTREG_PC) {
                                                      
                                      return new AdcsRegPclr(machInst, rd,
                                                                      rn, rm, imm5,
                                                                      type);
                                  
                                                  } else {
                                                      return new AdcRegCc(machInst, rd,
                                                                                    rn, rm, imm5, type);
                                                  }
                                              } else {
                                                  return new AdcReg(machInst, rd, rn,
                                                                               rm, imm5, type);
                                              }
                                          } else {
                                              if (setCc) {
                                                  return new AdcRegRegCc(machInst, rd,
                                                                                    rn, rm, rs, type);
                                              } else {
                                                  return new AdcRegReg(machInst, rd,
                                                                                  rn, rm, rs, type);
                                              }
                                          }
                                          break;
                                  
                                        case 0x6:
                                          if (immShift) {
                                              if (setCc) {
                                                  if (rd == INTREG_PC) {
                                                      
                                      return new SbcsRegPclr(machInst, rd,
                                                                      rn, rm, imm5,
                                                                      type);
                                  
                                                  } else {
                                                      return new SbcRegCc(machInst, rd,
                                                                                    rn, rm, imm5, type);
                                                  }
                                              } else {
                                                  return new SbcReg(machInst, rd, rn,
                                                                               rm, imm5, type);
                                              }
                                          } else {
                                              if (setCc) {
                                                  return new SbcRegRegCc(machInst, rd,
                                                                                    rn, rm, rs, type);
                                              } else {
                                                  return new SbcRegReg(machInst, rd,
                                                                                  rn, rm, rs, type);
                                              }
                                          }
                                          break;
                                  
                                        case 0x7:
                                          if (immShift) {
                                              if (setCc) {
                                                  if (rd == INTREG_PC) {
                                                      
                                      return new RscsRegPclr(machInst, rd,
                                                                      rn, rm, imm5,
                                                                      type);
                                  
                                                  } else {
                                                      return new RscRegCc(machInst, rd,
                                                                                    rn, rm, imm5, type);
                                                  }
                                              } else {
                                                  return new RscReg(machInst, rd, rn,
                                                                               rm, imm5, type);
                                              }
                                          } else {
                                              if (setCc) {
                                                  return new RscRegRegCc(machInst, rd,
                                                                                    rn, rm, rs, type);
                                              } else {
                                                  return new RscRegReg(machInst, rd,
                                                                                  rn, rm, rs, type);
                                              }
                                          }
                                          break;
                                  
                                        case 0x8:
                                          if (immShift) {
                                              if (setCc) {
                                                  if (INTREG_ZERO == INTREG_PC) {
                                                      
                                                  } else {
                                                      return new TstRegCc(machInst, INTREG_ZERO,
                                                                                    rn, rm, imm5, type);
                                                  }
                                              } else {
                                                  return new TstReg(machInst, INTREG_ZERO, rn,
                                                                               rm, imm5, type);
                                              }
                                          } else {
                                              if (setCc) {
                                                  return new TstRegRegCc(machInst, INTREG_ZERO,
                                                                                    rn, rm, rs, type);
                                              } else {
                                                  return new TstRegReg(machInst, INTREG_ZERO,
                                                                                  rn, rm, rs, type);
                                              }
                                          }
                                          break;
                                  
                                        case 0x9:
                                          if (immShift) {
                                              if (setCc) {
                                                  if (INTREG_ZERO == INTREG_PC) {
                                                      
                                                  } else {
                                                      return new TeqRegCc(machInst, INTREG_ZERO,
                                                                                    rn, rm, imm5, type);
                                                  }
                                              } else {
                                                  return new TeqReg(machInst, INTREG_ZERO, rn,
                                                                               rm, imm5, type);
                                              }
                                          } else {
                                              if (setCc) {
                                                  return new TeqRegRegCc(machInst, INTREG_ZERO,
                                                                                    rn, rm, rs, type);
                                              } else {
                                                  return new TeqRegReg(machInst, INTREG_ZERO,
                                                                                  rn, rm, rs, type);
                                              }
                                          }
                                          break;
                                  
                                        case 0xa:
                                          if (immShift) {
                                              if (setCc) {
                                                  if (INTREG_ZERO == INTREG_PC) {
                                                      
                                                  } else {
                                                      return new CmpRegCc(machInst, INTREG_ZERO,
                                                                                    rn, rm, imm5, type);
                                                  }
                                              } else {
                                                  return new CmpReg(machInst, INTREG_ZERO, rn,
                                                                               rm, imm5, type);
                                              }
                                          } else {
                                              if (setCc) {
                                                  return new CmpRegRegCc(machInst, INTREG_ZERO,
                                                                                    rn, rm, rs, type);
                                              } else {
                                                  return new CmpRegReg(machInst, INTREG_ZERO,
                                                                                  rn, rm, rs, type);
                                              }
                                          }
                                          break;
                                  
                                        case 0xb:
                                          if (immShift) {
                                              if (setCc) {
                                                  if (INTREG_ZERO == INTREG_PC) {
                                                      
                                                  } else {
                                                      return new CmnRegCc(machInst, INTREG_ZERO,
                                                                                    rn, rm, imm5, type);
                                                  }
                                              } else {
                                                  return new CmnReg(machInst, INTREG_ZERO, rn,
                                                                               rm, imm5, type);
                                              }
                                          } else {
                                              if (setCc) {
                                                  return new CmnRegRegCc(machInst, INTREG_ZERO,
                                                                                    rn, rm, rs, type);
                                              } else {
                                                  return new CmnRegReg(machInst, INTREG_ZERO,
                                                                                  rn, rm, rs, type);
                                              }
                                          }
                                          break;
                                  
                                        case 0xc:
                                          if (immShift) {
                                              if (setCc) {
                                                  if (rd == INTREG_PC) {
                                                      
                                      return new OrrsRegPclr(machInst, rd,
                                                                      rn, rm, imm5,
                                                                      type);
                                  
                                                  } else {
                                                      return new OrrRegCc(machInst, rd,
                                                                                    rn, rm, imm5, type);
                                                  }
                                              } else {
                                                  return new OrrReg(machInst, rd, rn,
                                                                               rm, imm5, type);
                                              }
                                          } else {
                                              if (setCc) {
                                                  return new OrrRegRegCc(machInst, rd,
                                                                                    rn, rm, rs, type);
                                              } else {
                                                  return new OrrRegReg(machInst, rd,
                                                                                  rn, rm, rs, type);
                                              }
                                          }
                                          break;
                                  
                                        case 0xd:
                                          if (immShift) {
                                              if (setCc) {
                                                  if (rd == INTREG_PC) {
                                                      
                                      return new MovsRegPclr(machInst, rd,
                                                                      INTREG_ZERO, rm, imm5,
                                                                      type);
                                  
                                                  } else {
                                                      return new MovRegCc(machInst, rd,
                                                                                    INTREG_ZERO, rm, imm5, type);
                                                  }
                                              } else {
                                                  return new MovReg(machInst, rd, INTREG_ZERO,
                                                                               rm, imm5, type);
                                              }
                                          } else {
                                              if (setCc) {
                                                  return new MovRegRegCc(machInst, rd,
                                                                                    INTREG_ZERO, rm, rs, type);
                                              } else {
                                                  return new MovRegReg(machInst, rd,
                                                                                  INTREG_ZERO, rm, rs, type);
                                              }
                                          }
                                          break;
                                  
                                        case 0xe:
                                          if (immShift) {
                                              if (setCc) {
                                                  if (rd == INTREG_PC) {
                                                      
                                      return new BicsRegPclr(machInst, rd,
                                                                      rn, rm, imm5,
                                                                      type);
                                  
                                                  } else {
                                                      return new BicRegCc(machInst, rd,
                                                                                    rn, rm, imm5, type);
                                                  }
                                              } else {
                                                  return new BicReg(machInst, rd, rn,
                                                                               rm, imm5, type);
                                              }
                                          } else {
                                              if (setCc) {
                                                  return new BicRegRegCc(machInst, rd,
                                                                                    rn, rm, rs, type);
                                              } else {
                                                  return new BicRegReg(machInst, rd,
                                                                                  rn, rm, rs, type);
                                              }
                                          }
                                          break;
                                  
                                        case 0xf:
                                          if (immShift) {
                                              if (setCc) {
                                                  if (rd == INTREG_PC) {
                                                      
                                      return new MvnsRegPclr(machInst, rd,
                                                                      INTREG_ZERO, rm, imm5,
                                                                      type);
                                  
                                                  } else {
                                                      return new MvnRegCc(machInst, rd,
                                                                                    INTREG_ZERO, rm, imm5, type);
                                                  }
                                              } else {
                                                  return new MvnReg(machInst, rd, INTREG_ZERO,
                                                                               rm, imm5, type);
                                              }
                                          } else {
                                              if (setCc) {
                                                  return new MvnRegRegCc(machInst, rd,
                                                                                    INTREG_ZERO, rm, rs, type);
                                              } else {
                                                  return new MvnRegReg(machInst, rd,
                                                                                  INTREG_ZERO, rm, rs, type);
                                              }
                                          }
                                          break;
                                  
                                        default:
                                          return new Unknown(machInst);
                                      }
                                  }
                                  break;
                            
                            case 0x1: 
                              switch (OPCODE_7) {
                                
                                case 0x0: 
                                  switch (MISC_OPCODE) {
                                    
                                    case 0x0:   
                                      // ArmMsrMrs::armMsrMrs(([], {}))
                                      
                                          {
                                              const uint8_t byteMask = bits(machInst, 19, 16);
                                              const uint8_t sysM     = byteMask | (bits(machInst, 8) << 4);
                                              const IntRegIndex rn = (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                              const IntRegIndex rd = (IntRegIndex)(uint32_t)bits(machInst, 15, 12);
                                              const uint32_t opcode = bits(machInst, 24, 21);
                                              const bool useImm = bits(machInst, 25);
                                              const bool r      = bits(machInst, 22);
                                              const bool isBanked = bits(machInst, 9);
                                              const uint32_t unrotated = bits(machInst, 7, 0);
                                              const uint32_t rotation = (bits(machInst, 11, 8) << 1);
                                              const uint32_t imm = rotate_imm(unrotated, rotation);
                                              switch (opcode) {
                                                case 0x8:
                                                  if (isBanked) {
                                                      return new MrsBankedReg(machInst, rd, sysM, r!=0);
                                                  } else {
                                                      return new MrsCpsr(machInst, rd);
                                                  }
                                                case 0x9:
                                                  if (useImm) {
                                                      return new MsrCpsrImm(machInst, imm, byteMask);
                                                  } else {
                                                      if (isBanked) {
                                                          return new MsrBankedReg(machInst, rn, sysM, r!=0);
                                                      } else {
                                                          return new MsrCpsrReg(machInst, rn, byteMask);
                                                      }
                                                  }
                                                case 0xa:
                                                  if (isBanked) {
                                                      return new MrsBankedReg(machInst, rd, sysM, r!=0);
                                                  } else {
                                                      return new MrsSpsr(machInst, rd);
                                                  }
                                                case 0xb:
                                                  if (useImm) {
                                                      return new MsrSpsrImm(machInst, imm, byteMask);
                                                  } else {
                                                      if (isBanked) {
                                                          return new MsrBankedReg(machInst, rn, sysM, r!=0);
                                                      } else {
                                                          return new MsrSpsrReg(machInst, rn, byteMask);
                                                      }
                                                  }
                                                default:
                                                  return new Unknown(machInst);
                                              }
                                          }
                                          break;
                                    
                                    case 0x1: case 0x2:   
                                      // ArmBxClz::armBxClz(([], {}))
                                      
                                          {
                                              const IntRegIndex rm = (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                              const IntRegIndex rd = (IntRegIndex)(uint32_t)bits(machInst, 15, 12);
                                              if (OPCODE == 0x9) {
                                                  return new BxReg(machInst, rm,
                                                          (ConditionCode)(uint32_t)machInst.condCode);
                                              } else if (OPCODE == 0xb) {
                                                  return new Clz(machInst, rd, rm);
                                              } else {
                                                  return new Unknown(machInst);
                                              }
                                          }
                                          break;
                                    
                                    case 0x3: 
                                      switch (OPCODE) {
                                        
                                        case 0x9:   
                                          // ArmBlxReg::armBlxReg(([], {}))
                                          
                                                  return new BlxReg(machInst, (IntRegIndex)(uint32_t)bits(machInst, 3, 0),
                                                                    (ConditionCode)(uint32_t)machInst.condCode);
                                              break;
                                        
                                        default:
                                          
                                          // Unknown::unknown(([], {}))
                                          return new Unknown(machInst);
                                          break;
                                        }
                                      
                                    case 0x5:   
                                      // ArmSatAddSub::armSatAddSub(([], {}))
                                      
                                          {
                                              IntRegIndex rn = (IntRegIndex)(uint32_t)bits(machInst, 19, 16);
                                              IntRegIndex rd = (IntRegIndex)(uint32_t)bits(machInst, 15, 12);
                                              IntRegIndex rm = (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                              switch (OPCODE) {
                                                case 0x8:
                                                  return new QaddRegCc(machInst, rd, rm, rn, 0, LSL);
                                                case 0x9:
                                                  return new QsubRegCc(machInst, rd, rm, rn, 0, LSL);
                                                case 0xa:
                                                  return new QdaddRegCc(machInst, rd, rm, rn, 0, LSL);
                                                case 0xb:
                                                  return new QdsubRegCc(machInst, rd, rm, rn, 0, LSL);
                                                default:
                                                  return new Unknown(machInst);
                                              }
                                          }
                                          break;
                                    
                                    case 0x6:   
                                      // ArmERet::armERet(([], {}))
                                      return new Eret(machInst);break;
                                    
                                    case 0x7: 
                                      switch (OPCODE_22) {
                                        
                                        case 0x0:   
                                          // Breakpoint::bkpt(([], {}))
                                          return new Breakpoint(machInst);
                                          break;
                                        
                                        case 0x1:   
                                          // ArmSmcHyp::armSmcHyp(([], {}))
                                          
                                              {
                                                  if (bits(machInst, 21))
                                                  {
                                                      return new Smc(machInst);
                                                  } else {
                                                      uint32_t imm16 = (bits(machInst, 19, 8) << 4) |
                                                                       (bits(machInst,  3, 0) << 0);
                                                      return new Hvc(machInst, imm16);
                                                  }
                                              }
                                              break;
                                        
                                        default:
                                          
                                          // Unknown::unknown(([], {}))
                                          return new Unknown(machInst);
                                          break;
                                        }
                                      
                                    default:
                                      
                                      // Unknown::unknown(([], {}))
                                      return new Unknown(machInst);
                                      break;
                                    }
                                  
                                case 0x1:   
                                  // ArmHalfWordMultAndMultAcc::armHalfWordMultAndMultAcc(([], {}))
                                  
                                      {
                                          const uint32_t op1 = bits(machInst, 22, 21);
                                          const bool op = bits(machInst, 5);
                                          const IntRegIndex rd = (IntRegIndex)(uint32_t)bits(machInst, 19, 16);
                                          const IntRegIndex ra = (IntRegIndex)(uint32_t)bits(machInst, 15, 12);
                                          const IntRegIndex rm = (IntRegIndex)(uint32_t)bits(machInst, 11, 8);
                                          const IntRegIndex rn = (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                          switch (op1) {
                                            case 0x0:
                                              switch (bits(machInst, 6, 5)) {
                                                case 0x0:
                                                  return new SmlabbCc(machInst, rd, rn, rm, ra);
                                                case 0x1:
                                                  return new SmlatbCc(machInst, rd, rn, rm, ra);
                                                case 0x2:
                                                  return new SmlabtCc(machInst, rd, rn, rm, ra);
                                                case 0x3:
                                                  return new SmlattCc(machInst, rd, rn, rm, ra);
                                              }
                                            case 0x1:
                                              if (op) {
                                                  if (bits(machInst, 6)) {
                                                      return new Smulwt(machInst, rd, rn, rm);
                                                  } else {
                                                      return new Smulwb(machInst, rd, rn, rm);
                                                  }
                                              } else {
                                                  if (bits(machInst, 6)) {
                                                      return new SmlawtCc(machInst, rd, rn, rm, ra);
                                                  } else {
                                                      return new SmlawbCc(machInst, rd, rn, rm, ra);
                                                  }
                                              }
                                            case 0x2:
                                              switch (bits(machInst, 6, 5)) {
                                                case 0x0:
                                                  return new Smlalbb(machInst, ra, rd, rn, rm);
                                                case 0x1:
                                                  return new Smlaltb(machInst, ra, rd, rn, rm);
                                                case 0x2:
                                                  return new Smlalbt(machInst, ra, rd, rn, rm);
                                                case 0x3:
                                                  return new Smlaltt(machInst, ra, rd, rn, rm);
                                              }
                                            case 0x3:
                                              switch (bits(machInst, 6, 5)) {
                                                case 0x0:
                                                  return new Smulbb(machInst, rd, rn, rm);
                                                case 0x1:
                                                  return new Smultb(machInst, rd, rn, rm);
                                                case 0x2:
                                                  return new Smulbt(machInst, rd, rn, rm);
                                                case 0x3:
                                                  return new Smultt(machInst, rd, rn, rm);
                                              }
                                          }
                                      }
                                      break;
                                
                                default:
                                  
                                  // Unknown::unknown(([], {}))
                                  return new Unknown(machInst);
                                  break;
                                }
                              
                            default:
                              
                              // Unknown::unknown(([], {}))
                              return new Unknown(machInst);
                              break;
                            }
                          
                        default:
                          
                          // Unknown::unknown(([], {}))
                          return new Unknown(machInst);
                          break;
                        }
                      
                    case 0x1: 
                      switch (IS_MISC) {
                        
                        case 0x0:   
                          // ArmDataProcImm::armDataProcImm(([], {}))
                          
                              {
                                  const bool setCc = (bits(machInst, 20) == 1);
                                  const uint32_t unrotated = bits(machInst, 7, 0);
                                  const uint32_t rotation = (bits(machInst, 11, 8) << 1);
                                  const bool rotC = (rotation != 0);
                                  const uint32_t imm = rotate_imm(unrotated, rotation);
                                  const IntRegIndex rd = (IntRegIndex)(uint32_t)RD;
                                  const IntRegIndex rn = (IntRegIndex)(uint32_t)RN;
                                  switch (OPCODE) {
                              
                                    case 0x0:
                                      if (setCc) {
                                          if (true && rd == INTREG_PC) {
                                              
                                  return new AndsImmPclr(machInst, rd,
                                                                  rn, imm, false);
                              
                                          } else {
                                              return new AndImmCc(machInst, rd, rn,
                                                                             imm, rotC);
                                          }
                                      } else {
                                          if (false && rn == INTREG_PC) {
                                              
                                          } else {
                                              return new AndImm(machInst, rd, rn,
                                                                           imm, rotC);
                                          }
                                      }
                                      break;
                              
                                    case 0x1:
                                      if (setCc) {
                                          if (true && rd == INTREG_PC) {
                                              
                                  return new EorsImmPclr(machInst, rd,
                                                                  rn, imm, false);
                              
                                          } else {
                                              return new EorImmCc(machInst, rd, rn,
                                                                             imm, rotC);
                                          }
                                      } else {
                                          if (false && rn == INTREG_PC) {
                                              
                                          } else {
                                              return new EorImm(machInst, rd, rn,
                                                                           imm, rotC);
                                          }
                                      }
                                      break;
                              
                                    case 0x2:
                                      if (setCc) {
                                          if (true && rd == INTREG_PC) {
                                              
                                  return new SubsImmPclr(machInst, rd,
                                                                  rn, imm, false);
                              
                                          } else {
                                              return new SubImmCc(machInst, rd, rn,
                                                                             imm, rotC);
                                          }
                                      } else {
                                          if (true && rn == INTREG_PC) {
                                              
                                  return new AdrImm(machInst, rd, (IntRegIndex)0,
                                                               imm, false);
                              
                                          } else {
                                              return new SubImm(machInst, rd, rn,
                                                                           imm, rotC);
                                          }
                                      }
                                      break;
                              
                                    case 0x3:
                                      if (setCc) {
                                          if (true && rd == INTREG_PC) {
                                              
                                  return new RsbsImmPclr(machInst, rd,
                                                                  rn, imm, false);
                              
                                          } else {
                                              return new RsbImmCc(machInst, rd, rn,
                                                                             imm, rotC);
                                          }
                                      } else {
                                          if (false && rn == INTREG_PC) {
                                              
                                          } else {
                                              return new RsbImm(machInst, rd, rn,
                                                                           imm, rotC);
                                          }
                                      }
                                      break;
                              
                                    case 0x4:
                                      if (setCc) {
                                          if (true && rd == INTREG_PC) {
                                              
                                  return new AddsImmPclr(machInst, rd,
                                                                  rn, imm, false);
                              
                                          } else {
                                              return new AddImmCc(machInst, rd, rn,
                                                                             imm, rotC);
                                          }
                                      } else {
                                          if (true && rn == INTREG_PC) {
                                              
                                  return new AdrImm(machInst, rd, (IntRegIndex)1,
                                                               imm, false);
                              
                                          } else {
                                              return new AddImm(machInst, rd, rn,
                                                                           imm, rotC);
                                          }
                                      }
                                      break;
                              
                                    case 0x5:
                                      if (setCc) {
                                          if (true && rd == INTREG_PC) {
                                              
                                  return new AdcsImmPclr(machInst, rd,
                                                                  rn, imm, false);
                              
                                          } else {
                                              return new AdcImmCc(machInst, rd, rn,
                                                                             imm, rotC);
                                          }
                                      } else {
                                          if (false && rn == INTREG_PC) {
                                              
                                          } else {
                                              return new AdcImm(machInst, rd, rn,
                                                                           imm, rotC);
                                          }
                                      }
                                      break;
                              
                                    case 0x6:
                                      if (setCc) {
                                          if (true && rd == INTREG_PC) {
                                              
                                  return new SbcsImmPclr(machInst, rd,
                                                                  rn, imm, false);
                              
                                          } else {
                                              return new SbcImmCc(machInst, rd, rn,
                                                                             imm, rotC);
                                          }
                                      } else {
                                          if (false && rn == INTREG_PC) {
                                              
                                          } else {
                                              return new SbcImm(machInst, rd, rn,
                                                                           imm, rotC);
                                          }
                                      }
                                      break;
                              
                                    case 0x7:
                                      if (setCc) {
                                          if (true && rd == INTREG_PC) {
                                              
                                  return new RscsImmPclr(machInst, rd,
                                                                  rn, imm, false);
                              
                                          } else {
                                              return new RscImmCc(machInst, rd, rn,
                                                                             imm, rotC);
                                          }
                                      } else {
                                          if (false && rn == INTREG_PC) {
                                              
                                          } else {
                                              return new RscImm(machInst, rd, rn,
                                                                           imm, rotC);
                                          }
                                      }
                                      break;
                              
                                    case 0x8:
                                      if (setCc) {
                                          if (false && INTREG_ZERO == INTREG_PC) {
                                              
                                          } else {
                                              return new TstImmCc(machInst, INTREG_ZERO, rn,
                                                                             imm, rotC);
                                          }
                                      } else {
                                          if (false && rn == INTREG_PC) {
                                              
                                          } else {
                                              return new TstImm(machInst, INTREG_ZERO, rn,
                                                                           imm, rotC);
                                          }
                                      }
                                      break;
                              
                                    case 0x9:
                                      if (setCc) {
                                          if (false && INTREG_ZERO == INTREG_PC) {
                                              
                                          } else {
                                              return new TeqImmCc(machInst, INTREG_ZERO, rn,
                                                                             imm, rotC);
                                          }
                                      } else {
                                          if (false && rn == INTREG_PC) {
                                              
                                          } else {
                                              return new TeqImm(machInst, INTREG_ZERO, rn,
                                                                           imm, rotC);
                                          }
                                      }
                                      break;
                              
                                    case 0xa:
                                      if (setCc) {
                                          if (false && INTREG_ZERO == INTREG_PC) {
                                              
                                          } else {
                                              return new CmpImmCc(machInst, INTREG_ZERO, rn,
                                                                             imm, rotC);
                                          }
                                      } else {
                                          if (false && rn == INTREG_PC) {
                                              
                                          } else {
                                              return new CmpImm(machInst, INTREG_ZERO, rn,
                                                                           imm, rotC);
                                          }
                                      }
                                      break;
                              
                                    case 0xb:
                                      if (setCc) {
                                          if (false && INTREG_ZERO == INTREG_PC) {
                                              
                                          } else {
                                              return new CmnImmCc(machInst, INTREG_ZERO, rn,
                                                                             imm, rotC);
                                          }
                                      } else {
                                          if (false && rn == INTREG_PC) {
                                              
                                          } else {
                                              return new CmnImm(machInst, INTREG_ZERO, rn,
                                                                           imm, rotC);
                                          }
                                      }
                                      break;
                              
                                    case 0xc:
                                      if (setCc) {
                                          if (true && rd == INTREG_PC) {
                                              
                                  return new OrrsImmPclr(machInst, rd,
                                                                  rn, imm, false);
                              
                                          } else {
                                              return new OrrImmCc(machInst, rd, rn,
                                                                             imm, rotC);
                                          }
                                      } else {
                                          if (false && rn == INTREG_PC) {
                                              
                                          } else {
                                              return new OrrImm(machInst, rd, rn,
                                                                           imm, rotC);
                                          }
                                      }
                                      break;
                              
                                    case 0xd:
                                      if (setCc) {
                                          if (true && rd == INTREG_PC) {
                                              
                                  return new MovsImmPclr(machInst, rd,
                                                                  INTREG_ZERO, imm, false);
                              
                                          } else {
                                              return new MovImmCc(machInst, rd, INTREG_ZERO,
                                                                             imm, rotC);
                                          }
                                      } else {
                                          if (false && INTREG_ZERO == INTREG_PC) {
                                              
                                          } else {
                                              return new MovImm(machInst, rd, INTREG_ZERO,
                                                                           imm, rotC);
                                          }
                                      }
                                      break;
                              
                                    case 0xe:
                                      if (setCc) {
                                          if (true && rd == INTREG_PC) {
                                              
                                  return new BicsImmPclr(machInst, rd,
                                                                  rn, imm, false);
                              
                                          } else {
                                              return new BicImmCc(machInst, rd, rn,
                                                                             imm, rotC);
                                          }
                                      } else {
                                          if (false && rn == INTREG_PC) {
                                              
                                          } else {
                                              return new BicImm(machInst, rd, rn,
                                                                           imm, rotC);
                                          }
                                      }
                                      break;
                              
                                    case 0xf:
                                      if (setCc) {
                                          if (true && rd == INTREG_PC) {
                                              
                                  return new MvnsImmPclr(machInst, rd,
                                                                  INTREG_ZERO, imm, false);
                              
                                          } else {
                                              return new MvnImmCc(machInst, rd, INTREG_ZERO,
                                                                             imm, rotC);
                                          }
                                      } else {
                                          if (false && INTREG_ZERO == INTREG_PC) {
                                              
                                          } else {
                                              return new MvnImm(machInst, rd, INTREG_ZERO,
                                                                           imm, rotC);
                                          }
                                      }
                                      break;
                              
                                    default:
                                      return new Unknown(machInst);
                                  }
                              }
                              break;
                        
                        case 0x1:   
                          // ArmMisc::armMisc(([], {}))
                          
                              {
                                  const uint32_t unrotated = bits(machInst, 7, 0);
                                  const uint32_t rotation = (bits(machInst, 11, 8) << 1);
                                  const uint32_t imm = rotate_imm(unrotated, rotation);
                                  const uint8_t byteMask = bits(machInst, 19, 16);
                                  switch (OPCODE) {
                                    case 0x8:
                                      return new MovImm(machInst, (IntRegIndex)(uint32_t)RD,
                                              (IntRegIndex)INTREG_ZERO,
                                              bits(machInst, 11, 0) | (bits(machInst, 19, 16) << 12),
                                              false);
                                    case 0x9:
                                      if (RN == 0) {
                                          switch (IMM) {
                                            case 0x0:
                                              return new NopInst(machInst);
                                            case 0x1:
                                              return new YieldInst(machInst);
                                            case 0x2:
                                              return new WfeInst(machInst);
                                            case 0x3:
                                              return new WfiInst(machInst);
                                            case 0x4:
                                              return new SevInst(machInst);
                                            default:
                                              return new Unknown(machInst);
                                          }
                                      } else {
                                          return new MsrCpsrImm(machInst, imm, byteMask);
                                      }
                                    case 0xa:
                                      {
                                          const uint32_t timm = (bits(machInst, 19, 16) << 12) |
                                                                 bits(machInst, 11, 0);
                                          return new MovtImm(machInst, (IntRegIndex)(uint32_t)RD,
                                                             (IntRegIndex)(uint32_t)RD, timm, true);
                                      }
                                    case 0xb:
                                      return new MsrSpsrImm(machInst, imm, byteMask);
                                    default:
                                      return new Unknown(machInst);
                                  }
                              }
                              break;
                        
                        default:
                          
                          // Unknown::unknown(([], {}))
                          return new Unknown(machInst);
                          break;
                        }
                      
                    case 0x2:   
                      // AddrMode2::addrMode2((['True'], {}))
                      switch(PUBWL) {
                      
                                              case 0x1:
                                                {return new LOAD_IMM_AN_PY_SN_UN_WY_SZ4(machInst, RD, RN,false, machInst.immed11_0);}
                                                break;
                                          
                                              case 0x0:
                                                {return new STORE_IMM_AN_PY_SN_UN_WY_SZ4(machInst, RD, RN,false, machInst.immed11_0);}
                                                break;
                                          
                                              case 0x3:
                                                {return new LOAD_IMM_AN_PY_SN_UY_WY_SZ4(machInst, RD, RN,false, machInst.immed11_0);}
                                                break;
                                          
                                              case 0x2:
                                                {return new STORE_IMM_AN_PY_SN_UY_WY_SZ4(machInst, RD, RN,false, machInst.immed11_0);}
                                                break;
                                          
                                              case 0x5:
                                                {return new LOAD_IMM_AN_PY_SN_UN_WY_SZ1(machInst, RD, RN,false, machInst.immed11_0);}
                                                break;
                                          
                                              case 0x4:
                                                {return new STORE_IMM_AN_PY_SN_UN_WY_SZ1(machInst, RD, RN,false, machInst.immed11_0);}
                                                break;
                                          
                                              case 0x7:
                                                {return new LOAD_IMM_AN_PY_SN_UY_WY_SZ1(machInst, RD, RN,false, machInst.immed11_0);}
                                                break;
                                          
                                              case 0x6:
                                                {return new STORE_IMM_AN_PY_SN_UY_WY_SZ1(machInst, RD, RN,false, machInst.immed11_0);}
                                                break;
                                          
                                              case 0x9:
                                                {return new LOAD_IMM_AY_PY_SN_UN_WY_SZ4(machInst, RD, RN,true, machInst.immed11_0);}
                                                break;
                                          
                                              case 0x8:
                                                {return new STORE_IMM_AY_PY_SN_UN_WY_SZ4(machInst, RD, RN,true, machInst.immed11_0);}
                                                break;
                                          
                                              case 0xb:
                                                {return new LOAD_IMM_AY_PY_SN_UY_WY_SZ4(machInst, RD, RN,true, machInst.immed11_0);}
                                                break;
                                          
                                              case 0xa:
                                                {return new STORE_IMM_AY_PY_SN_UY_WY_SZ4(machInst, RD, RN,true, machInst.immed11_0);}
                                                break;
                                          
                                              case 0xd:
                                                {return new LOAD_IMM_AY_PY_SN_UN_WY_SZ1(machInst, RD, RN,true, machInst.immed11_0);}
                                                break;
                                          
                                              case 0xc:
                                                {return new STORE_IMM_AY_PY_SN_UN_WY_SZ1(machInst, RD, RN,true, machInst.immed11_0);}
                                                break;
                                          
                                              case 0xf:
                                                {return new LOAD_IMM_AY_PY_SN_UY_WY_SZ1(machInst, RD, RN,true, machInst.immed11_0);}
                                                break;
                                          
                                              case 0xe:
                                                {return new STORE_IMM_AY_PY_SN_UY_WY_SZ1(machInst, RD, RN,true, machInst.immed11_0);}
                                                break;
                                          
                                              case 0x11:
                                                {return new LOAD_IMM_AN_PN_SN_UN_WN_SZ4(machInst, RD, RN,false, machInst.immed11_0);}
                                                break;
                                          
                                              case 0x10:
                                                {return new STORE_IMM_AN_PN_SN_UN_WN_SZ4(machInst, RD, RN,false, machInst.immed11_0);}
                                                break;
                                          
                                              case 0x13:
                                                {return new LOAD_IMM_AN_PN_SN_UN_WY_SZ4(machInst, RD, RN,false, machInst.immed11_0);}
                                                break;
                                          
                                              case 0x12:
                                                {return new STORE_IMM_AN_PN_SN_UN_WY_SZ4(machInst, RD, RN,false, machInst.immed11_0);}
                                                break;
                                          
                                              case 0x15:
                                                {return new LOAD_IMM_AN_PN_SN_UN_WN_SZ1(machInst, RD, RN,false, machInst.immed11_0);}
                                                break;
                                          
                                              case 0x14:
                                                {return new STORE_IMM_AN_PN_SN_UN_WN_SZ1(machInst, RD, RN,false, machInst.immed11_0);}
                                                break;
                                          
                                              case 0x17:
                                                {return new LOAD_IMM_AN_PN_SN_UN_WY_SZ1(machInst, RD, RN,false, machInst.immed11_0);}
                                                break;
                                          
                                              case 0x16:
                                                {return new STORE_IMM_AN_PN_SN_UN_WY_SZ1(machInst, RD, RN,false, machInst.immed11_0);}
                                                break;
                                          
                                              case 0x19:
                                                {return new LOAD_IMM_AY_PN_SN_UN_WN_SZ4(machInst, RD, RN,true, machInst.immed11_0);}
                                                break;
                                          
                                              case 0x18:
                                                {return new STORE_IMM_AY_PN_SN_UN_WN_SZ4(machInst, RD, RN,true, machInst.immed11_0);}
                                                break;
                                          
                                              case 0x1b:
                                                {return new LOAD_IMM_AY_PN_SN_UN_WY_SZ4(machInst, RD, RN,true, machInst.immed11_0);}
                                                break;
                                          
                                              case 0x1a:
                                                {return new STORE_IMM_AY_PN_SN_UN_WY_SZ4(machInst, RD, RN,true, machInst.immed11_0);}
                                                break;
                                          
                                              case 0x1d:
                                                {return new LOAD_IMM_AY_PN_SN_UN_WN_SZ1(machInst, RD, RN,true, machInst.immed11_0);}
                                                break;
                                          
                                              case 0x1c:
                                                {return new STORE_IMM_AY_PN_SN_UN_WN_SZ1(machInst, RD, RN,true, machInst.immed11_0);}
                                                break;
                                          
                                              case 0x1f:
                                                {return new LOAD_IMM_AY_PN_SN_UN_WY_SZ1(machInst, RD, RN,true, machInst.immed11_0);}
                                                break;
                                          
                                              case 0x1e:
                                                {return new STORE_IMM_AY_PN_SN_UN_WY_SZ1(machInst, RD, RN,true, machInst.immed11_0);}
                                                break;
                                          
                              default:
                                return new Unknown(machInst);
                              break;
                          }break;
                    
                    case 0x3: 
                      switch (OPCODE_4) {
                        
                        case 0x0:   
                          // AddrMode2::addrMode2((['False'], {}))
                          switch(PUBWL) {
                          
                                                  case 0x1:
                                                    {return new LOAD_REG_AN_PY_SN_UN_WY_SZ4(machInst, RD, RN, false,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0x0:
                                                    {return new STORE_REG_AN_PY_SN_UN_WY_SZ4(machInst, RD, RN, false,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0x3:
                                                    {return new LOAD_REG_AN_PY_SN_UY_WY_SZ4(machInst, RD, RN, false,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0x2:
                                                    {return new STORE_REG_AN_PY_SN_UY_WY_SZ4(machInst, RD, RN, false,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0x5:
                                                    {return new LOAD_REG_AN_PY_SN_UN_WY_SZ1(machInst, RD, RN, false,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0x4:
                                                    {return new STORE_REG_AN_PY_SN_UN_WY_SZ1(machInst, RD, RN, false,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0x7:
                                                    {return new LOAD_REG_AN_PY_SN_UY_WY_SZ1(machInst, RD, RN, false,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0x6:
                                                    {return new STORE_REG_AN_PY_SN_UY_WY_SZ1(machInst, RD, RN, false,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0x9:
                                                    {return new LOAD_REG_AY_PY_SN_UN_WY_SZ4(machInst, RD, RN, true,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0x8:
                                                    {return new STORE_REG_AY_PY_SN_UN_WY_SZ4(machInst, RD, RN, true,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0xb:
                                                    {return new LOAD_REG_AY_PY_SN_UY_WY_SZ4(machInst, RD, RN, true,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0xa:
                                                    {return new STORE_REG_AY_PY_SN_UY_WY_SZ4(machInst, RD, RN, true,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0xd:
                                                    {return new LOAD_REG_AY_PY_SN_UN_WY_SZ1(machInst, RD, RN, true,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0xc:
                                                    {return new STORE_REG_AY_PY_SN_UN_WY_SZ1(machInst, RD, RN, true,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0xf:
                                                    {return new LOAD_REG_AY_PY_SN_UY_WY_SZ1(machInst, RD, RN, true,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0xe:
                                                    {return new STORE_REG_AY_PY_SN_UY_WY_SZ1(machInst, RD, RN, true,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0x11:
                                                    {return new LOAD_REG_AN_PN_SN_UN_WN_SZ4(machInst, RD, RN, false,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0x10:
                                                    {return new STORE_REG_AN_PN_SN_UN_WN_SZ4(machInst, RD, RN, false,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0x13:
                                                    {return new LOAD_REG_AN_PN_SN_UN_WY_SZ4(machInst, RD, RN, false,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0x12:
                                                    {return new STORE_REG_AN_PN_SN_UN_WY_SZ4(machInst, RD, RN, false,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0x15:
                                                    {return new LOAD_REG_AN_PN_SN_UN_WN_SZ1(machInst, RD, RN, false,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0x14:
                                                    {return new STORE_REG_AN_PN_SN_UN_WN_SZ1(machInst, RD, RN, false,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0x17:
                                                    {return new LOAD_REG_AN_PN_SN_UN_WY_SZ1(machInst, RD, RN, false,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0x16:
                                                    {return new STORE_REG_AN_PN_SN_UN_WY_SZ1(machInst, RD, RN, false,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0x19:
                                                    {return new LOAD_REG_AY_PN_SN_UN_WN_SZ4(machInst, RD, RN, true,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0x18:
                                                    {return new STORE_REG_AY_PN_SN_UN_WN_SZ4(machInst, RD, RN, true,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0x1b:
                                                    {return new LOAD_REG_AY_PN_SN_UN_WY_SZ4(machInst, RD, RN, true,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0x1a:
                                                    {return new STORE_REG_AY_PN_SN_UN_WY_SZ4(machInst, RD, RN, true,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0x1d:
                                                    {return new LOAD_REG_AY_PN_SN_UN_WN_SZ1(machInst, RD, RN, true,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0x1c:
                                                    {return new STORE_REG_AY_PN_SN_UN_WN_SZ1(machInst, RD, RN, true,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0x1f:
                                                    {return new LOAD_REG_AY_PN_SN_UN_WY_SZ1(machInst, RD, RN, true,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                                  case 0x1e:
                                                    {return new STORE_REG_AY_PN_SN_UN_WY_SZ1(machInst, RD, RN, true,machInst.shiftSize,machInst.shift, RM);}
                                                    break;
                                              
                                  default:
                                    return new Unknown(machInst);
                                  break;
                              }break;
                        
                        case 0x1: 
                          switch (OPCODE_24_23) {
                            
                            case 0x0:   
                              // ArmParallelAddSubtract::armParallelAddSubtract(([], {}))
                              
                                  {
                                      const uint32_t op1 = bits(machInst, 21, 20);
                                      const uint32_t op2 = bits(machInst, 7, 5);
                                      const IntRegIndex rn = (IntRegIndex)(uint32_t)bits(machInst, 19, 16);
                                      const IntRegIndex rd = (IntRegIndex)(uint32_t)bits(machInst, 15, 12);
                                      const IntRegIndex rm = (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                      if (bits(machInst, 22) == 0) {
                                          switch (op1) {
                                            case 0x1:
                                              switch (op2) {
                                                case 0x0:
                                                  return new Sadd16RegCc(machInst, rd, rn, rm, 0, LSL);
                                                case 0x1:
                                                  return new SasxRegCc(machInst, rd, rn, rm, 0, LSL);
                                                case 0x2:
                                                  return new SsaxRegCc(machInst, rd, rn, rm, 0, LSL);
                                                case 0x3:
                                                  return new Ssub16RegCc(machInst, rd, rn, rm, 0, LSL);
                                                case 0x4:
                                                  return new Sadd8RegCc(machInst, rd, rn, rm, 0, LSL);
                                                case 0x7:
                                                  return new Ssub8RegCc(machInst, rd, rn, rm, 0, LSL);
                                              }
                                              break;
                                            case 0x2:
                                              switch (op2) {
                                                case 0x0:
                                                  return new Qadd16Reg(machInst, rd, rn, rm, 0, LSL);
                                                case 0x1:
                                                  return new QasxReg(machInst, rd, rn, rm, 0, LSL);
                                                case 0x2:
                                                  return new QsaxReg(machInst, rd, rn, rm, 0, LSL);
                                                case 0x3:
                                                  return new Qsub16Reg(machInst, rd, rn, rm, 0, LSL);
                                                case 0x4:
                                                  return new Qadd8Reg(machInst, rd, rn, rm, 0, LSL);
                                                case 0x7:
                                                  return new Qsub8Reg(machInst, rd, rn, rm, 0, LSL);
                                              }
                                              break;
                                            case 0x3:
                                              switch (op2) {
                                                case 0x0:
                                                  return new Shadd16Reg(machInst, rd, rn, rm, 0, LSL);
                                                case 0x1:
                                                  return new ShasxReg(machInst, rd, rn, rm, 0, LSL);
                                                case 0x2:
                                                  return new ShsaxReg(machInst, rd, rn, rm, 0, LSL);
                                                case 0x3:
                                                  return new Shsub16Reg(machInst, rd, rn, rm, 0, LSL);
                                                case 0x4:
                                                  return new Shadd8Reg(machInst, rd, rn, rm, 0, LSL);
                                                case 0x7:
                                                  return new Shsub8Reg(machInst, rd, rn, rm, 0, LSL);
                                              }
                                              break;
                                          }
                                      } else {
                                          switch (op1) {
                                            case 0x1:
                                              switch (op2) {
                                                case 0x0:
                                                  return new Uadd16RegCc(machInst, rd, rn, rm, 0, LSL);
                                                case 0x1:
                                                  return new UasxRegCc(machInst, rd, rn, rm, 0, LSL);
                                                case 0x2:
                                                  return new UsaxRegCc(machInst, rd, rn, rm, 0, LSL);
                                                case 0x3:
                                                  return new Usub16RegCc(machInst, rd, rn, rm, 0, LSL);
                                                case 0x4:
                                                  return new Uadd8RegCc(machInst, rd, rn, rm, 0, LSL);
                                                case 0x7:
                                                  return new Usub8RegCc(machInst, rd, rn, rm, 0, LSL);
                                              }
                                              break;
                                            case 0x2:
                                              switch (op2) {
                                                case 0x0:
                                                  return new Uqadd16Reg(machInst, rd, rn, rm, 0, LSL);
                                                case 0x1:
                                                  return new UqasxReg(machInst, rd, rn, rm, 0, LSL);
                                                case 0x2:
                                                  return new UqsaxReg(machInst, rd, rn, rm, 0, LSL);
                                                case 0x3:
                                                  return new Uqsub16Reg(machInst, rd, rn, rm, 0, LSL);
                                                case 0x4:
                                                  return new Uqadd8Reg(machInst, rd, rn, rm, 0, LSL);
                                                case 0x7:
                                                  return new Uqsub8Reg(machInst, rd, rn, rm, 0, LSL);
                                              }
                                              break;
                                            case 0x3:
                                              switch (op2) {
                                                case 0x0:
                                                  return new Uhadd16Reg(machInst, rd, rn, rm, 0, LSL);
                                                case 0x1:
                                                  return new UhasxReg(machInst, rd, rn, rm, 0, LSL);
                                                case 0x2:
                                                  return new UhsaxReg(machInst, rd, rn, rm, 0, LSL);
                                                case 0x3:
                                                  return new Uhsub16Reg(machInst, rd, rn, rm, 0, LSL);
                                                case 0x4:
                                                  return new Uhadd8Reg(machInst, rd, rn, rm, 0, LSL);
                                                case 0x7:
                                                  return new Uhsub8Reg(machInst, rd, rn, rm, 0, LSL);
                                              }
                                              break;
                                          }
                                      }
                                      return new Unknown(machInst);
                                  }
                                  break;
                            
                            case 0x1:   
                              // ArmPackUnpackSatReverse::armPackUnpackSatReverse(([], {}))
                              
                                  {
                                      const uint32_t op1 = bits(machInst, 22, 20);
                                      const uint32_t a = bits(machInst, 19, 16);
                                      const uint32_t op2 = bits(machInst, 7, 5);
                                      if (bits(op2, 0) == 0) {
                                          const IntRegIndex rn =
                                              (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                          const IntRegIndex rd =
                                              (IntRegIndex)(uint32_t)bits(machInst, 15, 12);
                                          const uint32_t satImm = bits(machInst, 20, 16);
                                          const uint32_t imm = bits(machInst, 11, 7);
                                          const ArmShiftType type =
                                              (ArmShiftType)(uint32_t)bits(machInst, 6, 5);
                                          if (op1 == 0) {
                                              if (type) {
                                                  return new PkhtbReg(machInst, rd, (IntRegIndex)a,
                                                                      rn, imm, type);
                                              } else {
                                                  return new PkhbtReg(machInst, rd, (IntRegIndex)a,
                                                                      rn, imm, type);
                                              }
                                          } else if (bits(op1, 2, 1) == 1) {
                                              return new Ssat(machInst, rd, satImm + 1, rn, imm, type);
                                          } else if (bits(op1, 2, 1) == 3) {
                                              return new Usat(machInst, rd, satImm, rn, imm, type);
                                          }
                                          return new Unknown(machInst);
                                      }
                                      switch (op1) {
                                        case 0x0:
                                          {
                                              const IntRegIndex rn =
                                                  (IntRegIndex)(uint32_t)bits(machInst, 19, 16);
                                              const IntRegIndex rd =
                                                  (IntRegIndex)(uint32_t)bits(machInst, 15, 12);
                                              const IntRegIndex rm =
                                                  (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                              if (op2 == 0x3) {
                                                  const uint32_t rotation =
                                                      (uint32_t)bits(machInst, 11, 10) << 3;
                                                  if (a == 0xf) {
                                                      return new Sxtb16(machInst, rd, rotation, rm);
                                                  } else {
                                                      return new Sxtab16(machInst, rd, rn, rm, rotation);
                                                  }
                                              } else if (op2 == 0x5) {
                                                  return new Sel(machInst, rd, rn, rm);
                                              }
                                          }
                                          break;
                                        case 0x2:
                                          if (op2 == 0x1) {
                                              const IntRegIndex rn =
                                                  (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                              const IntRegIndex rd =
                                                  (IntRegIndex)(uint32_t)bits(machInst, 15, 12);
                                              const uint32_t satImm = bits(machInst, 20, 16);
                                              return new Ssat16(machInst, rd, satImm + 1, rn);
                                          } else if (op2 == 0x3) {
                                              const IntRegIndex rn =
                                                  (IntRegIndex)(uint32_t)bits(machInst, 19, 16);
                                              const IntRegIndex rd =
                                                  (IntRegIndex)(uint32_t)bits(machInst, 15, 12);
                                              const IntRegIndex rm =
                                                  (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                              const uint32_t rotation =
                                                  (uint32_t)bits(machInst, 11, 10) << 3;
                                              if (a == 0xf) {
                                                  return new Sxtb(machInst, rd, rotation, rm);
                                              } else {
                                                  return new Sxtab(machInst, rd, rn, rm, rotation);
                                              }
                                          }
                                          break;
                                        case 0x3:
                                          if (op2 == 0x1) {
                                              IntRegIndex rd = (IntRegIndex)(uint32_t)bits(machInst, 15, 12);
                                              IntRegIndex rm = (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                              return new Rev(machInst, rd, rm);
                                          } else if (op2 == 0x3) {
                                              const IntRegIndex rn =
                                                  (IntRegIndex)(uint32_t)bits(machInst, 19, 16);
                                              const IntRegIndex rd =
                                                  (IntRegIndex)(uint32_t)bits(machInst, 15, 12);
                                              const IntRegIndex rm =
                                                  (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                              const uint32_t rotation =
                                                  (uint32_t)bits(machInst, 11, 10) << 3;
                                              if (a == 0xf) {
                                                  return new Sxth(machInst, rd, rotation, rm);
                                              } else {
                                                  return new Sxtah(machInst, rd, rn, rm, rotation);
                                              }
                                          } else if (op2 == 0x5) {
                                              IntRegIndex rd = (IntRegIndex)(uint32_t)bits(machInst, 15, 12);
                                              IntRegIndex rm = (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                              return new Rev16(machInst, rd, rm);
                                          }
                                          break;
                                        case 0x4:
                                          if (op2 == 0x3) {
                                              const IntRegIndex rn =
                                                  (IntRegIndex)(uint32_t)bits(machInst, 19, 16);
                                              const IntRegIndex rd =
                                                  (IntRegIndex)(uint32_t)bits(machInst, 15, 12);
                                              const IntRegIndex rm =
                                                  (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                              const uint32_t rotation =
                                                  (uint32_t)bits(machInst, 11, 10) << 3;
                                              if (a == 0xf) {
                                                  return new Uxtb16(machInst, rd, rotation, rm);
                                              } else {
                                                  return new Uxtab16(machInst, rd, rn, rm, rotation);
                                              }
                                          }
                                          break;
                                        case 0x6:
                                          if (op2 == 0x1) {
                                              const IntRegIndex rn =
                                                  (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                              const IntRegIndex rd =
                                                  (IntRegIndex)(uint32_t)bits(machInst, 15, 12);
                                              const uint32_t satImm = bits(machInst, 20, 16);
                                              return new Usat16(machInst, rd, satImm, rn);
                                          } else if (op2 == 0x3) {
                                              const IntRegIndex rn =
                                                  (IntRegIndex)(uint32_t)bits(machInst, 19, 16);
                                              const IntRegIndex rd =
                                                  (IntRegIndex)(uint32_t)bits(machInst, 15, 12);
                                              const IntRegIndex rm =
                                                  (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                              const uint32_t rotation =
                                                  (uint32_t)bits(machInst, 11, 10) << 3;
                                              if (a == 0xf) {
                                                  return new Uxtb(machInst, rd, rotation, rm);
                                              } else {
                                                  return new Uxtab(machInst, rd, rn, rm, rotation);
                                              }
                                          }
                                          break;
                                        case 0x7:
                                          {
                                              const IntRegIndex rn =
                                                  (IntRegIndex)(uint32_t)bits(machInst, 19, 16);
                                              const IntRegIndex rd =
                                                  (IntRegIndex)(uint32_t)bits(machInst, 15, 12);
                                              const IntRegIndex rm =
                                                  (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                              if (op2 == 0x1) {
                                                  return new Rbit(machInst, rd, rm);
                                              } else if (op2 == 0x3) {
                                                  const uint32_t rotation =
                                                      (uint32_t)bits(machInst, 11, 10) << 3;
                                                  if (a == 0xf) {
                                                      return new Uxth(machInst, rd, rotation, rm);
                                                  } else {
                                                      return new Uxtah(machInst, rd, rn, rm, rotation);
                                                  }
                                              } else if (op2 == 0x5) {
                                                  return new Revsh(machInst, rd, rm);
                                              }
                                          }
                                          break;
                                      }
                                      return new Unknown(machInst);
                                  }
                                  break;
                            
                            case 0x2:   
                              // ArmSignedMultiplies::armSignedMultiplies(([], {}))
                              
                                  {
                                      const uint32_t op1 = bits(machInst, 22, 20);
                                      // This is 7-5 in the manual, but bit 5 is always ignored.
                                      const uint32_t op2 = bits(machInst, 7, 6);
                                      const bool aIsF = (bits(machInst, 15, 12) == 0xf);
                                      const IntRegIndex rd = (IntRegIndex)(uint32_t)bits(machInst, 19, 16);
                                      const IntRegIndex rn = (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                      const IntRegIndex rm = (IntRegIndex)(uint32_t)bits(machInst, 11, 8);
                                      const IntRegIndex ra = (IntRegIndex)(uint32_t)bits(machInst, 15, 12);
                                      const bool m = bits(machInst, 5);
                                      switch (op1) {
                                        case 0x0:
                                          if (op2 == 0) {
                                              if (aIsF) {
                                                  if (m) {
                                                      return new SmuadxCc(machInst, rd, rn, rm);
                                                  } else {
                                                      return new SmuadCc(machInst, rd, rn, rm);
                                                  }
                                              } else {
                                                  if (m) {
                                                      return new SmladxCc(machInst, rd, rn, rm, ra);
                                                  } else {
                                                      return new SmladCc(machInst, rd, rn, rm, ra);
                                                  }
                                              }
                                          } else if (op2 == 1) {
                                              if (aIsF) {
                                                  if (m) {
                                                      return new Smusdx(machInst, rd, rn, rm);
                                                  } else {
                                                      return new Smusd(machInst, rd, rn, rm);
                                                  }
                                              } else {
                                                  if (m) {
                                                      return new SmlsdxCc(machInst, rd, rn, rm, ra);
                                                  } else {
                                                      return new SmlsdCc(machInst, rd, rn, rm, ra);
                                                  }
                                              }
                                          }
                                          break;
                                        case 0x1:
                                          if (op2 == 0 && m == 0 && ra == 0xf) {
                                              return new Sdiv(machInst, rd, rn, rm);
                                          }
                                          break;
                                        case 0x3:
                                          if (op2 == 0 && m == 0 && ra == 0xf) {
                                              return new Udiv(machInst, rd, rn, rm);
                                          }
                                          break;
                                        case 0x4:
                                          if (op2 == 0) {
                                              if (m) {
                                                  return new Smlaldx(machInst, ra, rd, rn, rm);
                                              } else {
                                                  return new Smlald(machInst, ra, rd, rn, rm);
                                              }
                                          } else if (op2 == 1) {
                                              if (m) {
                                                  return new Smlsldx(machInst, ra, rd, rn, rm);
                                              } else {
                                                  return new Smlsld(machInst, ra, rd, rn, rm);
                                              }
                                          }
                                          break;
                                        case 0x5:
                                          if (op2 == 0) {
                                              if (aIsF) {
                                                  if (m) {
                                                      return new Smmulr(machInst, rd, rn, rm);
                                                  } else {
                                                      return new Smmul(machInst, rd, rn, rm);
                                                  }
                                              } else {
                                                  if (m) {
                                                      return new Smmlar(machInst, rd, rn, rm, ra);
                                                  } else {
                                                      return new Smmla(machInst, rd, rn, rm, ra);
                                                  }
                                              }
                                          } else if (op2 == 0x3) {
                                              if (m) {
                                                  return new Smmlsr(machInst, rd, rn, rm, ra);
                                              } else {
                                                  return new Smmls(machInst, rd, rn, rm, ra);
                                              }
                                          }
                                          break;
                                        default:
                                          break;
                                      }
                                      return new Unknown(machInst);
                                  }
                                  break;
                            
                            case 0x3: 
                              switch (MEDIA_OPCODE) {
                                
                                case 0x1f: 
                                  switch (OPC2) {
                                    
                                    default:  
                                      // ArmMiscMedia::armMiscMedia(([], {}))
                                      
                                          {
                                              const uint32_t op1 = bits(machInst, 22, 20);
                                              const uint32_t op2 = bits(machInst, 7, 5);
                                              const IntRegIndex rn = (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                              const IntRegIndex ra = (IntRegIndex)(uint32_t)bits(machInst, 15, 12);
                                              if (op1 == 0 && op2 == 0) {
                                                  const IntRegIndex rd =
                                                      (IntRegIndex)(uint32_t)bits(machInst, 19, 16);
                                                  const IntRegIndex rm =
                                                      (IntRegIndex)(uint32_t)bits(machInst, 11, 8);
                                                  if (ra == 0xf) {
                                                      return new Usad8(machInst, rd, rn, rm);
                                                  } else {
                                                      return new Usada8(machInst, rd, rn, rm, ra);
                                                  }
                                              } else if (bits(op2, 1, 0) == 0x2) {
                                                  const uint32_t lsb = bits(machInst, 11, 7);
                                                  const uint32_t msb = lsb + bits(machInst, 20, 16);
                                                  if (bits(op1, 2, 1) == 0x3) {
                                                      return new Ubfx(machInst, ra, rn, lsb, msb);
                                                  } else if (bits(op1, 2, 1) == 0x1) {
                                                      return new Sbfx(machInst, ra, rn, lsb, msb);
                                                  }
                                              } else if (bits(op2, 1, 0) == 0x0 && bits(op1, 2, 1) == 0x2) {
                                                  const uint32_t lsb = bits(machInst, 11, 7);
                                                  const uint32_t msb = bits(machInst, 20, 16);
                                                  if (rn == 0xf) {
                                                      return new Bfc(machInst, ra, ra, lsb, msb);
                                                  } else {
                                                      return new Bfi(machInst, ra, rn, lsb, msb);
                                                  }
                                              }
                                              return new Unknown(machInst);
                                          }
                                          break;
                                    }
                                  
                                default:  
                                  // ArmMiscMedia::armMiscMedia(([], {}))
                                  
                                      {
                                          const uint32_t op1 = bits(machInst, 22, 20);
                                          const uint32_t op2 = bits(machInst, 7, 5);
                                          const IntRegIndex rn = (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                          const IntRegIndex ra = (IntRegIndex)(uint32_t)bits(machInst, 15, 12);
                                          if (op1 == 0 && op2 == 0) {
                                              const IntRegIndex rd =
                                                  (IntRegIndex)(uint32_t)bits(machInst, 19, 16);
                                              const IntRegIndex rm =
                                                  (IntRegIndex)(uint32_t)bits(machInst, 11, 8);
                                              if (ra == 0xf) {
                                                  return new Usad8(machInst, rd, rn, rm);
                                              } else {
                                                  return new Usada8(machInst, rd, rn, rm, ra);
                                              }
                                          } else if (bits(op2, 1, 0) == 0x2) {
                                              const uint32_t lsb = bits(machInst, 11, 7);
                                              const uint32_t msb = lsb + bits(machInst, 20, 16);
                                              if (bits(op1, 2, 1) == 0x3) {
                                                  return new Ubfx(machInst, ra, rn, lsb, msb);
                                              } else if (bits(op1, 2, 1) == 0x1) {
                                                  return new Sbfx(machInst, ra, rn, lsb, msb);
                                              }
                                          } else if (bits(op2, 1, 0) == 0x0 && bits(op1, 2, 1) == 0x2) {
                                              const uint32_t lsb = bits(machInst, 11, 7);
                                              const uint32_t msb = bits(machInst, 20, 16);
                                              if (rn == 0xf) {
                                                  return new Bfc(machInst, ra, ra, lsb, msb);
                                              } else {
                                                  return new Bfi(machInst, ra, rn, lsb, msb);
                                              }
                                          }
                                          return new Unknown(machInst);
                                      }
                                      break;
                                }
                              
                            default:
                              
                              // Unknown::unknown(([], {}))
                              return new Unknown(machInst);
                              break;
                            }
                          
                        default:
                          
                          // Unknown::unknown(([], {}))
                          return new Unknown(machInst);
                          break;
                        }
                      
                    case 0x4:   
                      // ArmMacroMem::armMacroMem(([], {}))
                      
                          return new LdmStm(machInst, (IntRegIndex)(uint32_t)RN, !PREPOST, UP,
                                            PSRUSER, WRITEBACK, LOADOP, machInst.regList);
                          break;
                    
                    case 0x5: 
                      switch (OPCODE_24) {
                        
                        case 0x0:   
                          // ArmBBlxImm::armBBlxImm(([], {}))
                          
                                  if (machInst.condCode == 0xF) {
                                      int32_t imm = (sext<26>(bits(machInst, 23, 0) << 2)) |
                                                    (bits(machInst, 24) << 1);
                                      return new BlxImm(machInst, imm, COND_UC);
                                  } else {
                                      return new B(machInst, sext<26>(bits(machInst, 23, 0) << 2),
                                                   (ConditionCode)(uint32_t)machInst.condCode);
                                  }
                              break;
                        
                        case 0x1:   
                          // ArmBlBlxImm::armBlBlxImm(([], {}))
                          
                                  if (machInst.condCode == 0xF) {
                                      int32_t imm = (sext<26>(bits(machInst, 23, 0) << 2)) |
                                                    (bits(machInst, 24) << 1);
                                      return new BlxImm(machInst, imm, COND_UC);
                                  } else {
                                      return new Bl(machInst, sext<26>(bits(machInst, 23, 0) << 2),
                                                    (ConditionCode)(uint32_t)machInst.condCode);
                                  }
                              break;
                        
                        default:
                          
                          // Unknown::unknown(([], {}))
                          return new Unknown(machInst);
                          break;
                        }
                      
                    case 0x6: 
                      switch (CPNUM) {
                        
                        case 0xa: case 0xb:   
                          // ExtensionRegLoadStore::extensionRegLoadStore(([], {}))
                          
                              return decodeExtensionRegLoadStore(machInst);
                              break;
                        
                        case 0xf: 
                          switch (OPCODE_20) {
                            
                            case 0x0:   
                              // Mcrr15::Mcrr15(([], {}))
                              
                                  return decodeMcrrMrrc15(machInst);
                                  break;
                            
                            case 0x1:   
                              // Mrrc15::Mrrc15(([], {}))
                              
                                  return decodeMcrrMrrc15(machInst);
                                  break;
                            
                            default:
                              
                              // Unknown::unknown(([], {}))
                              return new Unknown(machInst);
                              break;
                            }
                          
                        default:
                          
                          // Unknown::unknown(([], {}))
                          return new Unknown(machInst);
                          break;
                        }
                      
                    case 0x7: 
                      switch (OPCODE_24) {
                        
                        case 0x0: 
                          switch (OPCODE_4) {
                            
                            case 0x0: 
                              switch (CPNUM) {
                                
                                case 0xa: case 0xb:   
                                  // VfpData::vfpData(([], {}))
                                  
                                      return decodeVfpData(machInst);
                                      break;
                                
                                default:
                                  
                                  // Unknown::unknown(([], {}))
                                  return new Unknown(machInst);
                                  break;
                                }
                              
                            case 0x1: 
                              switch (CPNUM) {
                                
                                case 0x1:   
                                  // M5ops::m5ops(([], {}))
                                  
                                      {
                                          const uint32_t m5func = bits(machInst, 23, 16);
                                          switch(m5func) {
                                              case 0x00: return new Arm(machInst);
                                              case 0x01: return new Quiesce(machInst);
                                              case 0x02: return new QuiesceNs(machInst);
                                              case 0x03: return new QuiesceCycles(machInst);
                                              case 0x04: return new QuiesceTime(machInst);
                                              case 0x07: return new Rpns(machInst);
                                              case 0x09: return new WakeCPU(machInst);
                                              case 0x10: return new Deprecated_ivlb(machInst);
                                              case 0x11: return new Deprecated_ivle(machInst);
                                              case 0x20: return new Deprecated_exit (machInst);
                                              case 0x21: return new M5exit(machInst);
                                              case 0x22: return new M5fail(machInst);
                                              case 0x31: return new Loadsymbol(machInst);
                                              case 0x30: return new Initparam(machInst);
                                              case 0x40: return new Resetstats(machInst);
                                              case 0x41: return new Dumpstats(machInst);
                                              case 0x42: return new Dumpresetstats(machInst);
                                              case 0x43: return new M5checkpoint(machInst);
                                              case 0x4F: return new M5writefile(machInst);
                                              case 0x50: return new M5readfile(machInst);
                                              case 0x51: return new M5break(machInst);
                                              case 0x52: return new M5switchcpu(machInst);
                                              case 0x53: return new M5addsymbol(machInst);
                                              case 0x54: return new M5panic(machInst);
                                              case 0x5a: return new M5workbegin(machInst);
                                              case 0x5b: return new M5workend(machInst);
                                          }
                                     }
                                     break;
                                
                                case 0xa: case 0xb:   
                                  // ShortFpTransfer::shortFpTransfer(([], {}))
                                  
                                      return decodeShortFpTransfer(machInst);
                                      break;
                                
                                case 0xe:   
                                  // McrMrc14::mcrMrc14(([], {}))
                                  
                                      return decodeMcrMrc14(machInst);
                                      break;
                                
                                case 0xf:   
                                  // McrMrc15::mcrMrc15(([], {}))
                                  
                                      return decodeMcrMrc15(machInst);
                                      break;
                                
                                default:
                                  
                                  // Unknown::unknown(([], {}))
                                  return new Unknown(machInst);
                                  break;
                                }
                              
                            default:
                              
                              // Unknown::unknown(([], {}))
                              return new Unknown(machInst);
                              break;
                            }
                          
                        case 0x1:   
                          // Svc::svc(([], {}))
                          return new Svc(machInst, bits(machInst, 23, 0));break;
                        
                        default:
                          
                          // Unknown::unknown(([], {}))
                          return new Unknown(machInst);
                          break;
                        }
                      
                    default:
                      
                      // Unknown::unknown(([], {}))
                      return new Unknown(machInst);
                      break;
                    }
                  }
              
            case 0x1:   
              // Aarch64::aarch64(([], {}))
              
                  {
                      using namespace Aarch64;
                      if (bits(machInst, 27) == 0x0) {
                          if (bits(machInst, 28) == 0x0)
                              return new Unknown64(machInst);
                          else if (bits(machInst, 26) == 0)
                              // bit 28:26=100
                              return decodeDataProcImm(machInst);
                          else
                              // bit 28:26=101
                              return decodeBranchExcSys(machInst);
                      } else if (bits(machInst, 25) == 0) {
                          // bit 27=1, 25=0
                          return decodeLoadsStores(machInst);
                      } else if (bits(machInst, 26) == 0) {
                          // bit 27:25=101
                          return decodeDataProcReg(machInst);
                      } else if (bits(machInst, 24) == 1 &&
                                 bits(machInst, 31, 28) == 0xF) {
                          return decodeGem5Ops(machInst);
                      } else {
                          // bit 27:25=111
                          return decodeFpAdvSIMD(machInst);
                      }
                  }
                  break;
            
            default:
              
              // Unknown::unknown(([], {}))
              return new Unknown(machInst);
              break;
            }
          
        case 0x1: 
          switch (BIGTHUMB) {
            
            case 0x0: 
              switch (TOPCODE_15_13) {
                
                case 0x0: case 0x1:   
                  // Thumb16ShiftAddSubMoveCmp::thumb16ShiftAddMoveCmp(([], {}))
                  
                      {
                          const uint32_t imm5 = bits(machInst, 10, 6);
                          const uint32_t imm3 = bits(machInst, 8, 6);
                          const uint32_t imm8 = bits(machInst, 7, 0);
                          const IntRegIndex rd = (IntRegIndex)(uint32_t)bits(machInst, 2, 0);
                          const IntRegIndex rd8 = (IntRegIndex)(uint32_t)bits(machInst, 10, 8);
                          const IntRegIndex rn = (IntRegIndex)(uint32_t)bits(machInst, 5, 3);
                          const IntRegIndex rm = (IntRegIndex)(uint32_t)bits(machInst, 8, 6);
                          switch (bits(machInst, 13, 11)) {
                            case 0x0: // lsl
                              if (machInst.itstateMask) {
                                  return new MovReg(machInst, rd, INTREG_ZERO, rn, imm5, LSL);
                              } else {
                                  return new MovRegCc(machInst, rd, INTREG_ZERO, rn, imm5, LSL);
                              }
                            case 0x1: // lsr
                              if (machInst.itstateMask) {
                                  return new MovReg(machInst, rd, INTREG_ZERO, rn, imm5, LSR);
                              } else {
                                  return new MovRegCc(machInst, rd, INTREG_ZERO, rn, imm5, LSR);
                              }
                            case 0x2: // asr
                              if (machInst.itstateMask) {
                                  return new MovReg(machInst, rd, INTREG_ZERO, rn, imm5, ASR);
                              } else {
                                  return new MovRegCc(machInst, rd, INTREG_ZERO, rn, imm5, ASR);
                              }
                            case 0x3:
                              switch (bits(machInst, 10, 9)) {
                                case 0x0:
                                  if (machInst.itstateMask) {
                                      return new AddReg(machInst, rd, rn, rm, 0, LSL);
                                  } else {
                                      return new AddRegCc(machInst, rd, rn, rm, 0, LSL);
                                  }
                                case 0x1:
                                  if (machInst.itstateMask) {
                                      return new SubReg(machInst, rd, rn, rm, 0, LSL);
                                  } else {
                                      return new SubRegCc(machInst, rd, rn, rm, 0, LSL);
                                  }
                                case 0x2:
                                  if (machInst.itstateMask) {
                                      return new AddImm(machInst, rd, rn, imm3, true);
                                  } else {
                                      return new AddImmCc(machInst, rd, rn, imm3, true);
                                  }
                                case 0x3:
                                  if (machInst.itstateMask) {
                                      return new SubImm(machInst, rd, rn, imm3, true);
                                  } else {
                                      return new SubImmCc(machInst, rd, rn, imm3, true);
                                  }
                              }
                            case 0x4:
                              if (machInst.itstateMask) {
                                  return new MovImm(machInst, rd8, INTREG_ZERO, imm8, false);
                              } else {
                                  return new MovImmCc(machInst, rd8, INTREG_ZERO, imm8, false);
                              }
                            case 0x5:
                              return new CmpImmCc(machInst, INTREG_ZERO, rd8, imm8, true);
                            case 0x6:
                              if (machInst.itstateMask) {
                                  return new AddImm(machInst, rd8, rd8, imm8, true);
                              } else {
                                  return new AddImmCc(machInst, rd8, rd8, imm8, true);
                              }
                            case 0x7:
                              if (machInst.itstateMask) {
                                  return new SubImm(machInst, rd8, rd8, imm8, true);
                              } else {
                                  return new SubImmCc(machInst, rd8, rd8, imm8, true);
                              }
                          }
                      }
                      break;
                
                case 0x2: 
                  switch (TOPCODE_12_10) {
                    
                    case 0x0:   
                      // Thumb16DataProcessing::thumb16DataProcessing(([], {}))
                      
                          {
                              const IntRegIndex rdn = (IntRegIndex)(uint32_t)bits(machInst, 2, 0);
                              const IntRegIndex rm = (IntRegIndex)(uint32_t)bits(machInst, 5, 3);
                              switch (bits(machInst, 9, 6)) {
                                case 0x0:
                                  if (machInst.itstateMask) {
                                      return new AndReg(machInst, rdn, rdn, rm, 0, LSL);
                                  } else {
                                      return new AndRegCc(machInst, rdn, rdn, rm, 0, LSL);
                                  }
                                case 0x1:
                                  if (machInst.itstateMask) {
                                      return new EorReg(machInst, rdn, rdn, rm, 0, LSL);
                                  } else {
                                      return new EorRegCc(machInst, rdn, rdn, rm, 0, LSL);
                                  }
                                case 0x2: //lsl
                                  if (machInst.itstateMask) {
                                      return new MovRegReg(machInst, rdn,
                                              INTREG_ZERO, rdn, rm, LSL);
                                  } else {
                                      return new MovRegRegCc(machInst, rdn,
                                              INTREG_ZERO, rdn, rm, LSL);
                                  }
                                case 0x3: //lsr
                                  if (machInst.itstateMask) {
                                      return new MovRegReg(machInst, rdn,
                                              INTREG_ZERO, rdn, rm, LSR);
                                  } else {
                                      return new MovRegRegCc(machInst, rdn,
                                              INTREG_ZERO, rdn, rm, LSR);
                                  }
                                case 0x4: //asr
                                  if (machInst.itstateMask) {
                                      return new MovRegReg(machInst, rdn,
                                              INTREG_ZERO, rdn, rm, ASR);
                                  } else {
                                      return new MovRegRegCc(machInst, rdn,
                                              INTREG_ZERO, rdn, rm, ASR);
                                  }
                                case 0x5:
                                  if (machInst.itstateMask) {
                                      return new AdcReg(machInst, rdn, rdn, rm, 0, LSL);
                                  } else {
                                      return new AdcRegCc(machInst, rdn, rdn, rm, 0, LSL);
                                  }
                                case 0x6:
                                  if (machInst.itstateMask) {
                                      return new SbcReg(machInst, rdn, rdn, rm, 0, LSL);
                                  } else {
                                      return new SbcRegCc(machInst, rdn, rdn, rm, 0, LSL);
                                  }
                                case 0x7: // ror
                                  if (machInst.itstateMask) {
                                      return new MovRegReg(machInst, rdn,
                                              INTREG_ZERO, rdn, rm, ROR);
                                  } else {
                                      return new MovRegRegCc(machInst, rdn,
                                              INTREG_ZERO, rdn, rm, ROR);
                                  }
                                case 0x8:
                                  return new TstRegCc(machInst, INTREG_ZERO, rdn, rm, 0, LSL);
                                case 0x9:
                                  if (machInst.itstateMask) {
                                      return new RsbImm(machInst, rdn, rm, 0, true);
                                  } else {
                                      return new RsbImmCc(machInst, rdn, rm, 0, true);
                                  }
                                case 0xa:
                                  return new CmpRegCc(machInst, INTREG_ZERO, rdn, rm, 0, LSL);
                                case 0xb:
                                  return new CmnRegCc(machInst, INTREG_ZERO, rdn, rm, 0, LSL);
                                case 0xc:
                                  if (machInst.itstateMask) {
                                      return new OrrReg(machInst, rdn, rdn, rm, 0, LSL);
                                  } else {
                                      return new OrrRegCc(machInst, rdn, rdn, rm, 0, LSL);
                                  }
                                case 0xd:
                                  if (machInst.itstateMask) {
                                      return new Mul(machInst, rdn, rm, rdn);
                                  } else {
                                      return new MulCc(machInst, rdn, rm, rdn);
                                  }
                                case 0xe:
                                  if (machInst.itstateMask) {
                                      return new BicReg(machInst, rdn, rdn, rm, 0, LSL);
                                  } else {
                                      return new BicRegCc(machInst, rdn, rdn, rm, 0, LSL);
                                  }
                                case 0xf:
                                  if (machInst.itstateMask) {
                                      return new MvnReg(machInst, rdn, INTREG_ZERO, rm, 0, LSL);
                                  } else {
                                      return new MvnRegCc(machInst, rdn, INTREG_ZERO, rm, 0, LSL);
                                  }
                              }
                          }
                          break;
                    
                    case 0x1:   
                      // Thumb16SpecDataAndBx::thumb16SpecDataAndBx(([], {}))
                      
                          {
                              const IntRegIndex rdn =
                                  (IntRegIndex)(uint32_t)(bits(machInst, 2, 0) |
                                                          (bits(machInst, 7) << 3));
                              const IntRegIndex rm = (IntRegIndex)(uint32_t)bits(machInst, 6, 3);
                              switch (bits(machInst, 9, 8)) {
                                case 0x0:
                                  return new AddReg(machInst, rdn, rdn, rm, 0, LSL);
                                case 0x1:
                                  return new CmpRegCc(machInst, INTREG_ZERO, rdn, rm, 0, LSL);
                                case 0x2:
                                  return new MovReg(machInst, rdn, INTREG_ZERO, rm, 0, LSL);
                                case 0x3:
                                  if (bits(machInst, 7) == 0) {
                                      return new BxReg(machInst,
                                                       (IntRegIndex)(uint32_t)bits(machInst, 6, 3),
                                                       COND_UC);
                                  } else {
                                      return new BlxReg(machInst,
                                                        (IntRegIndex)(uint32_t)bits(machInst, 6, 3),
                                                        COND_UC);
                                  }
                              }
                          }
                          break;
                    
                    case 0x2: case 0x3:   
                      // Thumb16MemLit::thumb16MemLit(([], {}))
                      
                          {
                              const uint32_t rt = bits(machInst, 10, 8);
                              const uint32_t imm8 = bits(machInst, 7, 0);
                              return new LOAD_IMM_AY_PN_SN_UN_WN_SZ4(machInst, rt, INTREG_PC, true, imm8 << 2);
                          }
                          break;
                    
                    default:  
                      // Thumb16MemReg::thumb16MemReg(([], {}))
                      
                          {
                              const uint32_t opb = bits(machInst, 11, 9);
                              const uint32_t rt = bits(machInst, 2, 0);
                              const uint32_t rn = bits(machInst, 5, 3);
                              const uint32_t rm = bits(machInst, 8, 6);
                              switch (opb) {
                                case 0x0:
                                  return new STORE_REG_AY_PN_SN_UN_WN_SZ4(machInst, rt, rn, true, 0, LSL, rm);
                                case 0x1:
                                  return new STORE_REG_AY_PN_SN_UN_WN_SZ2(machInst, rt, rn, true, 0, LSL, rm);
                                case 0x2:
                                  return new STORE_REG_AY_PN_SN_UN_WN_SZ1(machInst, rt, rn, true, 0, LSL, rm);
                                case 0x3:
                                  return new LOAD_REG_AY_PN_SY_UN_WN_SZ1(machInst, rt, rn, true, 0, LSL, rm);
                                case 0x4:
                                  return new LOAD_REG_AY_PN_SN_UN_WN_SZ4(machInst, rt, rn, true, 0, LSL, rm);
                                case 0x5:
                                  return new LOAD_REG_AY_PN_SN_UN_WN_SZ2(machInst, rt, rn, true, 0, LSL, rm);
                                case 0x6:
                                  return new LOAD_REG_AY_PN_SN_UN_WN_SZ1(machInst, rt, rn, true, 0, LSL, rm);
                                case 0x7:
                                  return new LOAD_REG_AY_PN_SY_UN_WN_SZ2(machInst, rt, rn, true, 0, LSL, rm);
                              }
                          }
                          break;
                    }
                  
                case 0x3: case 0x4:   
                  // Thumb16MemImm::thumb16MemImm(([], {}))
                  
                      {
                          const uint32_t opa = bits(machInst, 15, 12);
                          const uint32_t opb = bits(machInst, 11, 9);
                          const uint32_t lrt = bits(machInst, 2, 0);
                          const uint32_t lrn = bits(machInst, 5, 3);
                          const uint32_t hrt = bits(machInst, 10, 8);
                          const uint32_t imm5 = bits(machInst, 10, 6);
                          const uint32_t imm8 = bits(machInst, 7, 0);
                          const bool load = bits(opb, 2);
                          switch (opa) {
                            case 0x6:
                              if (load) {
                                  return new LOAD_IMM_AY_PN_SN_UN_WN_SZ4(machInst, lrt, lrn, true, imm5 << 2);
                              } else {
                                  return new STORE_IMM_AY_PN_SN_UN_WN_SZ4(machInst, lrt, lrn, true, imm5 << 2);
                              }
                            case 0x7:
                              if (load) {
                                  return new LOAD_IMM_AY_PN_SN_UN_WN_SZ1(machInst, lrt, lrn, true, imm5);
                              } else {
                                  return new STORE_IMM_AY_PN_SN_UN_WN_SZ1(machInst, lrt, lrn, true, imm5);
                              }
                            case 0x8:
                              if (load) {
                                  return new LOAD_IMM_AY_PN_SN_UN_WN_SZ2(machInst, lrt, lrn, true, imm5 << 1);
                              } else {
                                  return new STORE_IMM_AY_PN_SN_UN_WN_SZ2(machInst, lrt, lrn, true, imm5 << 1);
                              }
                            case 0x9:
                              if (load) {
                                  return new LOAD_IMM_AY_PN_SN_UN_WN_SZ4(machInst, hrt, INTREG_SP, true, imm8 << 2);
                              } else {
                                  return new STORE_IMM_AY_PN_SN_UN_WN_SZ4(machInst, hrt, INTREG_SP, true, imm8 << 2);
                              }
                            default:
                              return new Unknown(machInst);
                          }
                      }
                      break;
                
                case 0x5: 
                  switch (TOPCODE_12_11) {
                    
                    case 0x0:   
                      // Thumb16Adr::thumb16Adr(([], {}))
                      
                          {
                              const IntRegIndex rd = (IntRegIndex)(uint32_t)bits(machInst, 10, 8);
                              const uint32_t imm8 = bits(machInst, 7, 0) << 2;
                              return new AdrImm(machInst, rd, (IntRegIndex)1, imm8, false);
                          }
                          break;
                    
                    case 0x1:   
                      // Thumb16AddSp::thumb16AddSp(([], {}))
                      
                          {
                              const IntRegIndex rd = (IntRegIndex)(uint32_t)bits(machInst, 10, 8);
                              const uint32_t imm8 = bits(machInst, 7, 0) << 2;
                              return new AddImm(machInst, rd, INTREG_SP, imm8, true);
                          }
                          break;
                    
                    case 0x2: case 0x3:   
                      // Thumb16Misc::thumb16Misc(([], {}))
                      
                          {
                              switch (bits(machInst, 11, 8)) {
                                case 0x0:
                                  if (bits(machInst, 7)) {
                                      return new SubImm(machInst, INTREG_SP, INTREG_SP,
                                                         bits(machInst, 6, 0) << 2, true);
                                  } else {
                                      return new AddImm(machInst, INTREG_SP, INTREG_SP,
                                                         bits(machInst, 6, 0) << 2, true);
                                  }
                                case 0x2:
                                  {
                                      const IntRegIndex rd =
                                          (IntRegIndex)(uint32_t)bits(machInst, 2, 0);
                                      const IntRegIndex rm =
                                          (IntRegIndex)(uint32_t)bits(machInst, 5, 3);
                                      switch (bits(machInst, 7, 6)) {
                                        case 0x0:
                                          return new Sxth(machInst, rd, 0, rm);
                                        case 0x1:
                                          return new Sxtb(machInst, rd, 0, rm);
                                        case 0x2:
                                          return new Uxth(machInst, rd, 0, rm);
                                        case 0x3:
                                          return new Uxtb(machInst, rd, 0, rm);
                                      }
                                  }
                                case 0x1:
                                case 0x3:
                                  return new Cbz(machInst,
                                                 (bits(machInst, 9) << 6) |
                                                 (bits(machInst, 7, 3) << 1),
                                                 (IntRegIndex)(uint32_t)bits(machInst, 2, 0));
                                case 0x4:
                                case 0x5:
                                  {
                                      const uint32_t m = bits(machInst, 8);
                                      const uint32_t regList = bits(machInst, 7, 0) | (m << 14);
                                      return new LdmStm(machInst, INTREG_SP, false, false, false,
                                                        true, false, regList);
                                  }
                                case 0x6:
                                  {
                                      const uint32_t opBits = bits(machInst, 7, 5);
                                      if (opBits == 2) {
                                          return new Setend(machInst, bits(machInst, 3));
                                      } else if (opBits == 3) {
                                          const bool enable = (bits(machInst, 4) == 0);
                                          const uint32_t mods = (bits(machInst, 2, 0) << 5) |
                                                                ((enable ? 1 : 0) << 9);
                                          return new Cps(machInst, mods);
                                      }
                                  }
                                case 0xa:
                                  {
                                      IntRegIndex rd = (IntRegIndex)(uint32_t)bits(machInst, 2, 0);
                                      IntRegIndex rm = (IntRegIndex)(uint32_t)bits(machInst, 5, 3);
                                      switch (bits(machInst, 7, 6)) {
                                        case 0x0:
                                          return new Rev(machInst, rd, rm);
                                        case 0x1:
                                          return new Rev16(machInst, rd, rm);
                                        case 0x3:
                                          return new Revsh(machInst, rd, rm);
                                        default:
                                          break;
                                      }
                                  }
                                  break;
                                case 0x9:
                                case 0xb:
                                  return new Cbnz(machInst,
                                                  (bits(machInst, 9) << 6) |
                                                  (bits(machInst, 7, 3) << 1),
                                                  (IntRegIndex)(uint32_t)bits(machInst, 2, 0));
                                case 0xc:
                                case 0xd:
                                  {
                                      const uint32_t p = bits(machInst, 8);
                                      const uint32_t regList = bits(machInst, 7, 0) | (p << 15);
                                      return new LdmStm(machInst, INTREG_SP, true, true, false,
                                                        true, true, regList);
                                  }
                                case 0xe:
                                  return new BkptInst(machInst);
                                case 0xf:
                                  if (bits(machInst, 3, 0) != 0)
                                      return new ItInst(machInst);
                                  switch (bits(machInst, 7, 4)) {
                                    case 0x0:
                                      return new NopInst(machInst);
                                    case 0x1:
                                      return new YieldInst(machInst);
                                    case 0x2:
                                      return new WfeInst(machInst);
                                    case 0x3:
                                      return new WfiInst(machInst);
                                    case 0x4:
                                      return new SevInst(machInst);
                                    default:
                                      return new WarnUnimplemented("unallocated_hint", machInst);
                                  }
                                default:
                                  break;
                              }
                              return new Unknown(machInst);
                          }
                          break;
                    
                    default:
                      
                      // Unknown::unknown(([], {}))
                      return new Unknown(machInst);
                      break;
                    }
                  
                case 0x6: 
                  switch (TOPCODE_12_11) {
                    
                    case 0x0: case 0x1:   
                      // Thumb16MacroMem::thumb16MacroMem(([], {}))
                      
                          {
                              const IntRegIndex rn = (IntRegIndex)(uint32_t)bits(machInst, 10, 8);
                              const bool load = (bits(machInst, 11) == 1);
                              const uint32_t regList = bits(machInst, 7, 0);
                              const bool writeback = (!load || bits(regList, rn) == 0);
                              return new LdmStm(machInst, rn, true, true, false,
                                                writeback, load, regList);
                          }
                          break;
                    
                    case 0x2: case 0x3:   
                      // Thumb16CondBranchAndSvc::thumb16CondBranchAndSvc(([], {}))
                      
                              if (bits(machInst, 11, 9) != 0x7) {
                                  return new B(machInst, sext<9>(bits(machInst, 7, 0) << 1),
                                               (ConditionCode)(uint32_t)bits(machInst, 11, 8));
                              } else if (bits(machInst, 8)) {
                                  return new Svc(machInst, bits(machInst, 7, 0));
                              } else {
                                  // This space will not be allocated in the future.
                                  return new Unknown(machInst);
                              }
                          break;
                    
                    default:
                      
                      // Unknown::unknown(([], {}))
                      return new Unknown(machInst);
                      break;
                    }
                  
                case 0x7: 
                  switch (TOPCODE_12_11) {
                    
                    case 0x0:   
                      // Thumb16UncondBranch::thumb16UncondBranch(([], {}))
                      
                              return new B(machInst, sext<12>(bits(machInst, 10, 0) << 1), COND_UC);
                          break;
                    
                    default:
                      
                      // Unknown::unknown(([], {}))
                      return new Unknown(machInst);
                      break;
                    }
                  
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              
            case 0x1: 
              switch (HTOPCODE_12_11) {
                
                case 0x1: 
                  switch (HTOPCODE_10_9) {
                    
                    case 0x0: 
                      switch (HTOPCODE_6) {
                        
                        case 0x0: 
                          switch (HTOPCODE_8_7) {
                            
                            case 0x0: case 0x3:   
                              // Thumb32SrsRfe::thumb32SrsRfe(([], {}))
                              
                                  {
                                      const bool wb = (bits(machInst, 21) == 1);
                                      const bool add = (bits(machInst, 24, 23) == 0x3);
                                      if (bits(machInst, 20) == 1) {
                                          // post == add
                                          const IntRegIndex rn =
                                              (IntRegIndex)(uint32_t)bits(machInst, 19, 16);
                                          if (!add && !wb) {
                                              return new RFE_LOAD_IMM_AN_PN_SN_UN_WN_SZ8(machInst, rn, RfeOp::DecrementBefore, wb);
                                          } else if (add && !wb) {
                                              return new RFE_LOAD_IMM_AY_PY_SN_UN_WN_SZ8(machInst, rn, RfeOp::IncrementAfter, wb);
                                          } else if (!add && wb) {
                                              return new RFE_LOAD_IMM_AN_PN_SN_UN_WY_SZ8(machInst, rn, RfeOp::DecrementBefore, wb);
                                          } else {
                                              return new RFE_LOAD_IMM_AY_PY_SN_UN_WY_SZ8(machInst, rn, RfeOp::IncrementAfter, wb);
                                          }
                                      } else {
                                          const uint32_t mode = bits(machInst, 4, 0);
                                          if (badMode32((OperatingMode)mode))
                                              return new Unknown(machInst);
                                          if (!add && !wb) {
                                              return new SRS_STORE_IMM_AN_PN_SN_UN_WN_SZ8(machInst, mode,
                                                      SrsOp::DecrementBefore, wb);
                                          } else if (add && !wb) {
                                              return new SRS_STORE_IMM_AY_PY_SN_UN_WN_SZ8(machInst, mode,
                                                      SrsOp::IncrementAfter, wb);
                                          } else if (!add && wb) {
                                              return new SRS_STORE_IMM_AN_PN_SN_UN_WY_SZ8(machInst, mode,
                                                      SrsOp::DecrementBefore, wb);
                                          } else {
                                              return new SRS_STORE_IMM_AY_PY_SN_UN_WY_SZ8(machInst, mode,
                                                      SrsOp::IncrementAfter, wb);
                                          }
                                      }
                                  }
                                  break;
                            
                            default:  
                              // ArmMacroMem::armMacroMem(([], {}))
                              
                                  return new LdmStm(machInst, (IntRegIndex)(uint32_t)RN, !PREPOST, UP,
                                                    PSRUSER, WRITEBACK, LOADOP, machInst.regList);
                                  break;
                            }
                          
                        case 0x1:   
                          // Thumb32LdrStrDExTbh::thumb32LdrStrDExTbh(([], {}))
                          
                              {
                                  const uint32_t op1 = bits(machInst, 24, 23);
                                  const uint32_t op2 = bits(machInst, 21, 20);
                                  const uint32_t op3 = bits(machInst, 7, 4);
                                  const IntRegIndex rn = (IntRegIndex)(uint32_t)bits(machInst, 19, 16);
                                  const IntRegIndex rt = (IntRegIndex)(uint32_t)bits(machInst, 15, 12);
                                  const IntRegIndex rt2 = (IntRegIndex)(uint32_t)bits(machInst, 11, 8);
                                  const IntRegIndex rd = (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                  const uint32_t imm8 = bits(machInst, 7, 0);
                                  if (bits(op1, 1) == 0 && bits(op2, 1) == 0) {
                                      if (op1 == 0) {
                                          const uint32_t imm = bits(machInst, 7, 0) << 2;
                                          if (op2 == 0) {
                                              return new STREX_STORE_IMM_AY_PN_SN_UN_WN_SZ4(machInst, rt2, rt, rn, true, imm);
                                          } else {
                                              return new LDREX_LOAD_IMM_AY_PN_SN_UN_WN_SZ4(machInst, rt, rn, true, imm);
                                          }
                                      } else {
                                          if (op2 == 0) {
                                              switch (op3) {
                                                case 0x4:
                                                  return new STREXB_STORE_IMM_AY_PN_SN_UN_WN_SZ1(machInst, rd, rt, rn, true, 0);
                                                case 0x5:
                                                  return new STREXH_STORE_IMM_AY_PN_SN_UN_WN_SZ2(machInst, rd, rt, rn, true, 0);
                                                case 0x7:
                                                  return new STREXD_STORE_IMMD_AY_PN_SN_UN_WN_SZ4(machInst, rd, rt,
                                                                        rt2, rn, true, 0);
                                                default:
                                                  return new Unknown(machInst);
                                              }
                                          } else {
                                              switch (op3) {
                                                case 0x0:
                                                  return new Tbb(machInst, rn, rd);
                                                case 0x1:
                                                  return new Tbh(machInst, rn, rd);
                                                case 0x4:
                                                  return new LDREXB_LOAD_IMM_AY_PN_SN_UN_WN_SZ1(machInst, rt, rn, true, 0);
                                                case 0x5:
                                                  return new LDREXH_LOAD_IMM_AY_PN_SN_UN_WN_SZ2(machInst, rt, rn, true, 0);
                                                case 0x7:
                                                  return new LDREXD_LOAD_IMMD_AY_PN_SN_UN_WN_SZ4(machInst, rt, rt2, rn, true, 0);
                                                default:
                                                  return new Unknown(machInst);
                                              }
                                          }
                                      }
                                  } else {
                                      const uint32_t puw = (bits(machInst, 24, 23) << 1) |
                                                            bits(machInst, 21);
                                      const uint32_t dimm = imm8 << 2;
                                      if (bits(op2, 0) == 0) {
                                          switch (puw) {
                                            case 0x1:
                                              return new STORE_IMMD_AN_PY_SN_UN_WY_SZ4(machInst, rt, rt2, rn, false, dimm);
                                            case 0x3:
                                              return new STORE_IMMD_AY_PY_SN_UN_WY_SZ4(machInst, rt, rt2, rn, true, dimm);
                                            case 0x4:
                                              return new STORE_IMMD_AN_PN_SN_UN_WN_SZ4(machInst, rt, rt2, rn, false, dimm);
                                            case 0x5:
                                              return new STORE_IMMD_AN_PN_SN_UN_WY_SZ4(machInst, rt, rt2, rn, false, dimm);
                                            case 0x6:
                                              return new STORE_IMMD_AY_PN_SN_UN_WN_SZ4(machInst, rt, rt2, rn, true, dimm);
                                            case 0x7:
                                              return new STORE_IMMD_AY_PN_SN_UN_WY_SZ4(machInst, rt, rt2, rn, true, dimm);
                                            default:
                                              return new Unknown(machInst);
                                          }
                                      } else {
                                          switch (puw) {
                                            case 0x1:
                                              return new LOAD_IMMD_AN_PY_SN_UN_WY_SZ4(machInst, rt, rt2, rn, false, dimm);
                                            case 0x3:
                                              return new LOAD_IMMD_AY_PY_SN_UN_WY_SZ4(machInst, rt, rt2, rn, true, dimm);
                                            case 0x4:
                                              return new LOAD_IMMD_AN_PN_SN_UN_WN_SZ4(machInst, rt, rt2, rn, false, dimm);
                                            case 0x5:
                                              return new LOAD_IMMD_AN_PN_SN_UN_WY_SZ4(machInst, rt, rt2, rn, false, dimm);
                                            case 0x6:
                                              return new LOAD_IMMD_AY_PN_SN_UN_WN_SZ4(machInst, rt, rt2, rn, true, dimm);
                                            case 0x7:
                                              return new LOAD_IMMD_AY_PN_SN_UN_WY_SZ4(machInst, rt, rt2, rn, true, dimm);
                                            default:
                                              return new Unknown(machInst);
                                          }
                                      }
                                  }
                              }
                              break;
                        
                        default:
                          
                          // Unknown::unknown(([], {}))
                          return new Unknown(machInst);
                          break;
                        }
                      
                    case 0x1:   
                      // Thumb32DataProcShiftReg::thumb32DataProcShiftReg(([], {}))
                      
                          {
                              const uint32_t op = bits(machInst, 24, 21);
                              const bool s = (bits(machInst, 20) == 1);
                              const IntRegIndex rn = (IntRegIndex)(uint32_t)bits(machInst, 19, 16);
                              const IntRegIndex rd = (IntRegIndex)(uint32_t)bits(machInst, 11, 8);
                              const IntRegIndex rm = (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                              const uint32_t amt = (bits(machInst, 14, 12) << 2) |
                                                    bits(machInst, 7, 6);
                              const ArmShiftType type = (ArmShiftType)(uint32_t)bits(machInst, 5, 4);
                              switch (op) {
                                case 0x0:
                                  if (rd == INTREG_PC) {
                                      
                                  if (s) {
                                      return new TstRegCc(machInst, INTREG_ZERO,
                                                                rn, rm, amt, type);
                                  } else {
                                      return new TstReg(machInst, INTREG_ZERO,
                                                              rn, rm, amt, type);
                                  }
                              
                                  } else {
                                      
                                  if (s) {
                                      return new AndRegCc(machInst, rd,
                                                                rn, rm, amt, type);
                                  } else {
                                      return new AndReg(machInst, rd,
                                                              rn, rm, amt, type);
                                  }
                              
                                  }
                                case 0x1:
                                  
                                  if (s) {
                                      return new BicRegCc(machInst, rd,
                                                                rn, rm, amt, type);
                                  } else {
                                      return new BicReg(machInst, rd,
                                                              rn, rm, amt, type);
                                  }
                              
                                case 0x2:
                                  if (rn == INTREG_PC) {
                                      
                                  if (s) {
                                      return new MovRegCc(machInst, rd,
                                                                INTREG_ZERO, rm, amt, type);
                                  } else {
                                      return new MovReg(machInst, rd,
                                                              INTREG_ZERO, rm, amt, type);
                                  }
                              
                                  } else {
                                      
                                  if (s) {
                                      return new OrrRegCc(machInst, rd,
                                                                rn, rm, amt, type);
                                  } else {
                                      return new OrrReg(machInst, rd,
                                                              rn, rm, amt, type);
                                  }
                              
                                  }
                                case 0x3:
                                  if (rn == INTREG_PC) {
                                      
                                  if (s) {
                                      return new MvnRegCc(machInst, rd,
                                                                INTREG_ZERO, rm, amt, type);
                                  } else {
                                      return new MvnReg(machInst, rd,
                                                              INTREG_ZERO, rm, amt, type);
                                  }
                              
                                  } else {
                                      
                                  if (s) {
                                      return new OrnRegCc(machInst, rd,
                                                                rn, rm, amt, type);
                                  } else {
                                      return new OrnReg(machInst, rd,
                                                              rn, rm, amt, type);
                                  }
                              
                                  }
                                case 0x4:
                                  if (rd == INTREG_PC) {
                                      
                                  if (s) {
                                      return new TeqRegCc(machInst, INTREG_ZERO,
                                                                rn, rm, amt, type);
                                  } else {
                                      return new TeqReg(machInst, INTREG_ZERO,
                                                              rn, rm, amt, type);
                                  }
                              
                                  } else {
                                      
                                  if (s) {
                                      return new EorRegCc(machInst, rd,
                                                                rn, rm, amt, type);
                                  } else {
                                      return new EorReg(machInst, rd,
                                                              rn, rm, amt, type);
                                  }
                              
                                  }
                                case 0x6:
                                  if (type) {
                                      return new PkhtbReg(machInst, rd, rn, rm, amt, type);
                                  } else {
                                      return new PkhbtReg(machInst, rd, rn, rm, amt, type);
                                  }
                                case 0x8:
                                  if (rd == INTREG_PC) {
                                      
                                  if (s) {
                                      return new CmnRegCc(machInst, INTREG_ZERO,
                                                                rn, rm, amt, type);
                                  } else {
                                      return new CmnReg(machInst, INTREG_ZERO,
                                                              rn, rm, amt, type);
                                  }
                              
                                  } else {
                                      
                                  if (s) {
                                      return new AddRegCc(machInst, rd,
                                                                rn, rm, amt, type);
                                  } else {
                                      return new AddReg(machInst, rd,
                                                              rn, rm, amt, type);
                                  }
                              
                                  }
                                case 0xa:
                                  
                                  if (s) {
                                      return new AdcRegCc(machInst, rd,
                                                                rn, rm, amt, type);
                                  } else {
                                      return new AdcReg(machInst, rd,
                                                              rn, rm, amt, type);
                                  }
                              
                                case 0xb:
                                  
                                  if (s) {
                                      return new SbcRegCc(machInst, rd,
                                                                rn, rm, amt, type);
                                  } else {
                                      return new SbcReg(machInst, rd,
                                                              rn, rm, amt, type);
                                  }
                              
                                case 0xd:
                                  if (rd == INTREG_PC) {
                                      
                                  if (s) {
                                      return new CmpRegCc(machInst, INTREG_ZERO,
                                                                rn, rm, amt, type);
                                  } else {
                                      return new CmpReg(machInst, INTREG_ZERO,
                                                              rn, rm, amt, type);
                                  }
                              
                                  } else {
                                      
                                  if (s) {
                                      return new SubRegCc(machInst, rd,
                                                                rn, rm, amt, type);
                                  } else {
                                      return new SubReg(machInst, rd,
                                                              rn, rm, amt, type);
                                  }
                              
                                  }
                                case 0xe:
                                  
                                  if (s) {
                                      return new RsbRegCc(machInst, rd,
                                                                rn, rm, amt, type);
                                  } else {
                                      return new RsbReg(machInst, rd,
                                                              rn, rm, amt, type);
                                  }
                              
                                default:
                                  return new Unknown(machInst);
                              }
                          }
                          break;
                    
                    default:
                      switch (HTOPCODE_9_8) {
                        
                        case 0x2: 
                          switch (LTOPCODE_4) {
                            
                            case 0x0: 
                              switch (LTCOPROC) {
                                
                                case 0xa: case 0xb:   
                                  // VfpData::vfpData(([], {}))
                                  
                                      return decodeVfpData(machInst);
                                      break;
                                
                                default:  
                                  // WarnUnimpl::cdp(([], {}))
                                  
                                          return new WarnUnimplemented("cdp", machInst);
                                  break;
                                }
                              
                            case 0x1: 
                              switch (LTCOPROC) {
                                
                                case 0x1:   
                                  // M5ops::m5ops(([], {}))
                                  
                                      {
                                          const uint32_t m5func = bits(machInst, 23, 16);
                                          switch(m5func) {
                                              case 0x00: return new Arm(machInst);
                                              case 0x01: return new Quiesce(machInst);
                                              case 0x02: return new QuiesceNs(machInst);
                                              case 0x03: return new QuiesceCycles(machInst);
                                              case 0x04: return new QuiesceTime(machInst);
                                              case 0x07: return new Rpns(machInst);
                                              case 0x09: return new WakeCPU(machInst);
                                              case 0x10: return new Deprecated_ivlb(machInst);
                                              case 0x11: return new Deprecated_ivle(machInst);
                                              case 0x20: return new Deprecated_exit (machInst);
                                              case 0x21: return new M5exit(machInst);
                                              case 0x22: return new M5fail(machInst);
                                              case 0x31: return new Loadsymbol(machInst);
                                              case 0x30: return new Initparam(machInst);
                                              case 0x40: return new Resetstats(machInst);
                                              case 0x41: return new Dumpstats(machInst);
                                              case 0x42: return new Dumpresetstats(machInst);
                                              case 0x43: return new M5checkpoint(machInst);
                                              case 0x4F: return new M5writefile(machInst);
                                              case 0x50: return new M5readfile(machInst);
                                              case 0x51: return new M5break(machInst);
                                              case 0x52: return new M5switchcpu(machInst);
                                              case 0x53: return new M5addsymbol(machInst);
                                              case 0x54: return new M5panic(machInst);
                                              case 0x5a: return new M5workbegin(machInst);
                                              case 0x5b: return new M5workend(machInst);
                                          }
                                     }
                                     break;
                                
                                case 0xa: case 0xb:   
                                  // ShortFpTransfer::shortFpTransfer(([], {}))
                                  
                                      return decodeShortFpTransfer(machInst);
                                      break;
                                
                                case 0xe:   
                                  // McrMrc14::mcrMrc14(([], {}))
                                  
                                      return decodeMcrMrc14(machInst);
                                      break;
                                
                                case 0xf:   
                                  // McrMrc15::mcrMrc15(([], {}))
                                  
                                      return decodeMcrMrc15(machInst);
                                      break;
                                
                                default:
                                  
                                  // Unknown::unknown(([], {}))
                                  return new Unknown(machInst);
                                  break;
                                }
                              
                            default:
                              
                              // Unknown::unknown(([], {}))
                              return new Unknown(machInst);
                              break;
                            }
                          
                        case 0x3:   
                          // ThumbNeonData::ThumbNeonData(([], {}))
                          
                              return decodeNeonData(machInst);
                              break;
                        
                        default:
                          switch (LTCOPROC) {
                            
                            case 0xa: case 0xb:   
                              // ExtensionRegLoadStore::extensionRegLoadStre(([], {}))
                              
                                  return decodeExtensionRegLoadStore(machInst);
                                  break;
                            
                            case 0xf: 
                              switch (HTOPCODE_9_4) {
                                
                                case 0x0:   
                                  // Unknown::undefined(([], {}))
                                  return new Unknown(machInst);
                                  break;
                                
                                case 0x4: 
                                  switch (LTCOPROC) {
                                    
                                    case 0xf:   
                                      // Mcrr15::Mcrr15(([], {}))
                                      
                                          return decodeMcrrMrrc15(machInst);
                                          break;
                                    
                                    default:  
                                      // WarnUnimpl::mcrr(([], {}))
                                      
                                              return new WarnUnimplemented("mcrr", machInst);
                                      break;
                                    }
                                  
                                case 0x5: 
                                  switch (LTCOPROC) {
                                    
                                    case 0xf:   
                                      // Mrrc15::Mrrc15(([], {}))
                                      
                                          return decodeMcrrMrrc15(machInst);
                                          break;
                                    
                                    default:  
                                      // WarnUnimpl::mrrc(([], {}))
                                      
                                              return new WarnUnimplemented("mrrc", machInst);
                                      break;
                                    }
                                  
                                case 0x2: case 0x6: case 0x8: case 0xa: case 0xc: case 0xe: case 0x10: case 0x12: case 0x14: case 0x16: case 0x18: case 0x1a: case 0x1c: case 0x1e:   
                                  // WarnUnimpl::stc(([], {}))
                                  
                                          return new WarnUnimplemented("stc", machInst);
                                  break;
                                
                                case 0x3: case 0x7: case 0x9: case 0xb: case 0xd: case 0xf: case 0x11: case 0x13: case 0x15: case 0x17: case 0x19: case 0x1b: case 0x1d: case 0x1f: 
                                  switch (HTRN) {
                                    
                                    case 0xf:   
                                      // WarnUnimpl::ldc(([], {}))
                                      
                                              return new WarnUnimplemented("ldc", machInst);
                                      break;
                                    
                                    default:  
                                      // WarnUnimpl::ldc(([], {}))
                                      
                                              return new WarnUnimplemented("ldc", machInst);
                                      break;
                                    }
                                  
                                default:
                                  
                                  // Unknown::unknown(([], {}))
                                  return new Unknown(machInst);
                                  break;
                                }
                              
                            default:
                              
                              // Unknown::unknown(([], {}))
                              return new Unknown(machInst);
                              break;
                            }
                          }
                      }
                  
                case 0x2: 
                  switch (LTOPCODE_15) {
                    
                    case 0x0: 
                      switch (HTOPCODE_9) {
                        
                        case 0x0:   
                          // Thumb32DataProcModImm::thumb32DataProcModImm(([], {}))
                          
                              {
                                  const uint32_t op = bits(machInst, 24, 21);
                                  const bool s = (bits(machInst, 20) == 1);
                                  const IntRegIndex rn = (IntRegIndex)(uint32_t)bits(machInst, 19, 16);
                                  const IntRegIndex rd = (IntRegIndex)(uint32_t)bits(machInst, 11, 8);
                                  const uint32_t ctrlImm = bits(machInst.instBits, 26) << 3 |
                                                           bits(machInst, 14, 12);
                                  const bool rotC = ctrlImm > 3;
                                  const uint32_t dataImm = bits(machInst, 7, 0);
                                  const uint32_t imm = modified_imm(ctrlImm, dataImm);
                                  switch (op) {
                                    case 0x0:
                                      if (rd == INTREG_PC) {
                                          
                                      if (s) {
                                          return new TstImmCc(machInst, INTREG_ZERO,
                                                                    rn, imm, rotC);
                                      } else {
                                          return new TstImm(machInst, INTREG_ZERO,
                                                                  rn, imm, rotC);
                                      }
                                  
                                      } else {
                                          
                                      if (s) {
                                          return new AndImmCc(machInst, rd,
                                                                    rn, imm, rotC);
                                      } else {
                                          return new AndImm(machInst, rd,
                                                                  rn, imm, rotC);
                                      }
                                  
                                      }
                                    case 0x1:
                                      
                                      if (s) {
                                          return new BicImmCc(machInst, rd,
                                                                    rn, imm, rotC);
                                      } else {
                                          return new BicImm(machInst, rd,
                                                                  rn, imm, rotC);
                                      }
                                  
                                    case 0x2:
                                      if (rn == INTREG_PC) {
                                          
                                      if (s) {
                                          return new MovImmCc(machInst, rd,
                                                                    INTREG_ZERO, imm, rotC);
                                      } else {
                                          return new MovImm(machInst, rd,
                                                                  INTREG_ZERO, imm, rotC);
                                      }
                                  
                                      } else {
                                          
                                      if (s) {
                                          return new OrrImmCc(machInst, rd,
                                                                    rn, imm, rotC);
                                      } else {
                                          return new OrrImm(machInst, rd,
                                                                  rn, imm, rotC);
                                      }
                                  
                                      }
                                    case 0x3:
                                      if (rn == INTREG_PC) {
                                          
                                      if (s) {
                                          return new MvnImmCc(machInst, rd,
                                                                    INTREG_ZERO, imm, rotC);
                                      } else {
                                          return new MvnImm(machInst, rd,
                                                                  INTREG_ZERO, imm, rotC);
                                      }
                                  
                                      } else {
                                          
                                      if (s) {
                                          return new OrnImmCc(machInst, rd,
                                                                    rn, imm, rotC);
                                      } else {
                                          return new OrnImm(machInst, rd,
                                                                  rn, imm, rotC);
                                      }
                                  
                                      }
                                    case 0x4:
                                      if (rd == INTREG_PC) {
                                          
                                      if (s) {
                                          return new TeqImmCc(machInst, INTREG_ZERO,
                                                                    rn, imm, rotC);
                                      } else {
                                          return new TeqImm(machInst, INTREG_ZERO,
                                                                  rn, imm, rotC);
                                      }
                                  
                                      } else {
                                          
                                      if (s) {
                                          return new EorImmCc(machInst, rd,
                                                                    rn, imm, rotC);
                                      } else {
                                          return new EorImm(machInst, rd,
                                                                  rn, imm, rotC);
                                      }
                                  
                                      }
                                    case 0x8:
                                      if (rd == INTREG_PC) {
                                          
                                      if (s) {
                                          return new CmnImmCc(machInst, INTREG_ZERO,
                                                                    rn, imm, rotC);
                                      } else {
                                          return new CmnImm(machInst, INTREG_ZERO,
                                                                  rn, imm, rotC);
                                      }
                                  
                                      } else {
                                          
                                      if (s) {
                                          return new AddImmCc(machInst, rd,
                                                                    rn, imm, rotC);
                                      } else {
                                          return new AddImm(machInst, rd,
                                                                  rn, imm, rotC);
                                      }
                                  
                                      }
                                    case 0xa:
                                      
                                      if (s) {
                                          return new AdcImmCc(machInst, rd,
                                                                    rn, imm, rotC);
                                      } else {
                                          return new AdcImm(machInst, rd,
                                                                  rn, imm, rotC);
                                      }
                                  
                                    case 0xb:
                                      
                                      if (s) {
                                          return new SbcImmCc(machInst, rd,
                                                                    rn, imm, rotC);
                                      } else {
                                          return new SbcImm(machInst, rd,
                                                                  rn, imm, rotC);
                                      }
                                  
                                    case 0xd:
                                      if (rd == INTREG_PC) {
                                          
                                      if (s) {
                                          return new CmpImmCc(machInst, INTREG_ZERO,
                                                                    rn, imm, rotC);
                                      } else {
                                          return new CmpImm(machInst, INTREG_ZERO,
                                                                  rn, imm, rotC);
                                      }
                                  
                                      } else {
                                          
                                      if (s) {
                                          return new SubImmCc(machInst, rd,
                                                                    rn, imm, rotC);
                                      } else {
                                          return new SubImm(machInst, rd,
                                                                  rn, imm, rotC);
                                      }
                                  
                                      }
                                    case 0xe:
                                      
                                      if (s) {
                                          return new RsbImmCc(machInst, rd,
                                                                    rn, imm, rotC);
                                      } else {
                                          return new RsbImm(machInst, rd,
                                                                  rn, imm, rotC);
                                      }
                                  
                                    default:
                                      return new Unknown(machInst);
                                  }
                              }
                              break;
                        
                        case 0x1:   
                          // Thumb32DataProcPlainBin::thumb32DataProcPlainBin(([], {}))
                          
                              {
                                  const uint32_t op = bits(machInst, 24, 20);
                                  const IntRegIndex rn = (IntRegIndex)(uint32_t)bits(machInst, 19, 16);
                                  const IntRegIndex rd = (IntRegIndex)(uint32_t)bits(machInst, 11, 8);
                                  switch (op) {
                                    case 0x0:
                                      {
                                          const uint32_t imm = bits(machInst, 7, 0) |
                                                               (bits(machInst, 14, 12) << 8) |
                                                               (bits(machInst, 26) << 11);
                                          if (rn == 0xf) {
                                              return new AdrImm(machInst, rd, (IntRegIndex)1,
                                                                imm, false);
                                          } else {
                                              return new AddImm(machInst, rd, rn, imm, true);
                                          }
                                      }
                                    case 0x4:
                                      {
                                          const uint32_t imm = bits(machInst, 7, 0) |
                                                               (bits(machInst, 14, 12) << 8) |
                                                               (bits(machInst, 26) << 11) |
                                                               (bits(machInst, 19, 16) << 12);
                                          return new MovImm(machInst, rd, INTREG_ZERO, imm, true);
                                      }
                                    case 0xa:
                                      {
                                          const uint32_t imm = bits(machInst, 7, 0) |
                                                               (bits(machInst, 14, 12) << 8) |
                                                               (bits(machInst, 26) << 11);
                                          if (rn == 0xf) {
                                              return new AdrImm(machInst, rd, (IntRegIndex)0,
                                                                imm, false);
                                          } else {
                                              return new SubImm(machInst, rd, rn, imm, true);
                                          }
                                      }
                                    case 0xc:
                                      {
                                          const uint32_t imm = bits(machInst, 7, 0) |
                                                               (bits(machInst, 14, 12) << 8) |
                                                               (bits(machInst, 26) << 11) |
                                                               (bits(machInst, 19, 16) << 12);
                                          return new MovtImm(machInst, rd, rd, imm, true);
                                      }
                                    case 0x12:
                                      if (!(bits(machInst, 14, 12) || bits(machInst, 7, 6))) {
                                          const uint32_t satImm = bits(machInst, 4, 0);
                                          return new Ssat16(machInst, rd, satImm + 1, rn);
                                      }
                                      // Fall through on purpose...
                                    case 0x10:
                                      {
                                          const uint32_t satImm = bits(machInst, 4, 0);
                                          const uint32_t imm = bits(machInst, 7, 6) |
                                                               (bits(machInst, 14, 12) << 2);
                                          const ArmShiftType type =
                                              (ArmShiftType)(uint32_t)bits(machInst, 21, 20);
                                          return new Ssat(machInst, rd, satImm + 1, rn, imm, type);
                                      }
                                    case 0x14:
                                      {
                                          const uint32_t lsb = bits(machInst, 7, 6) |
                                                               (bits(machInst, 14, 12) << 2);
                                          const uint32_t msb = lsb + bits(machInst, 4, 0);
                                          return new Sbfx(machInst, rd, rn, lsb, msb);
                                      }
                                    case 0x16:
                                      {
                                          const uint32_t lsb = bits(machInst, 7, 6) |
                                                               (bits(machInst, 14, 12) << 2);
                                          const uint32_t msb = bits(machInst, 4, 0);
                                          if (rn == 0xf) {
                                              return new Bfc(machInst, rd, rd, lsb, msb);
                                          } else {
                                              return new Bfi(machInst, rd, rn, lsb, msb);
                                          }
                                      }
                                    case 0x1a:
                                      if (!(bits(machInst, 14, 12) || bits(machInst, 7, 6))) {
                                          const uint32_t satImm = bits(machInst, 4, 0);
                                          return new Usat16(machInst, rd, satImm, rn);
                                      }
                                      // Fall through on purpose...
                                    case 0x18:
                                      {
                                          const uint32_t satImm = bits(machInst, 4, 0);
                                          const uint32_t imm = bits(machInst, 7, 6) |
                                                               (bits(machInst, 14, 12) << 2);
                                          const ArmShiftType type =
                                              (ArmShiftType)(uint32_t)bits(machInst, 21, 20);
                                          return new Usat(machInst, rd, satImm, rn, imm, type);
                                      }
                                    case 0x1c:
                                      {
                                          const uint32_t lsb = bits(machInst, 7, 6) |
                                                               (bits(machInst, 14, 12) << 2);
                                          const uint32_t msb = lsb + bits(machInst, 4, 0);
                                          return new Ubfx(machInst, rd, rn, lsb, msb);
                                      }
                                    default:
                                      return new Unknown(machInst);
                                  }
                              }
                              break;
                        
                        default:
                          
                          // Unknown::unknown(([], {}))
                          return new Unknown(machInst);
                          break;
                        }
                      
                    case 0x1:   
                      // Thumb32BranchesAndMiscCtrl::thumb32BranchesAndMiscCtrl(([], {}))
                      
                          {
                              const uint32_t op = bits(machInst, 26, 20);
                              const uint32_t op1 = bits(machInst, 14, 12);
                              switch (op1 & 0x5) {
                                case 0x0:
                                  if (op == 127) {
                                      if (op1 & 0x2) {
                                          // Permanently undefined.
                                          return new Unknown(machInst);
                                      } else {
                                          return new Smc(machInst);
                                      }
                                  } else if ((op & 0x38) != 0x38) {
                                      const uint32_t s = bits(machInst, 26);
                                      const uint32_t j1 = bits(machInst, 13);
                                      const uint32_t j2 = bits(machInst, 11);
                                      const uint32_t imm6 = bits(machInst, 21, 16);
                                      const uint32_t imm11 = bits(machInst, 10, 0);
                                      const int32_t imm = sext<21>((s << 20) |
                                                                   (j2 << 19) | (j1 << 18) |
                                                                   (imm6 << 12) | (imm11 << 1));
                                      return new B(machInst, imm,
                                                   (ConditionCode)(uint32_t)bits(machInst, 25, 22));
                                  } else {
                                      // HIGH: 12-11=10, LOW: 15-14=00, 12=0
                                      switch (op) {
                                        case 0x38:
                                        case 0x39:
                                          {
                                              const IntRegIndex rn =
                                                  (IntRegIndex)(uint32_t)bits(machInst, 19, 16);
                                              const uint8_t byteMask = bits(machInst, 11, 8);
                                              const bool    r        = bits(machInst, 20);
                                              if (bits(machInst, 5)) {
                                                  const uint8_t sysM = (bits(machInst, 4) << 4) |
                                                                        byteMask;
                                                  return new MsrBankedReg(machInst, rn, sysM, r);
                                              } else {
                                                  if (r) {
                                                      return new MsrSpsrReg(machInst, rn, byteMask);
                                                  } else {
                                                      return new MsrCpsrReg(machInst, rn, byteMask);
                                                  }
                                              }
                                          }
                                        case 0x3a:
                                          {
                                              const uint32_t op1 = bits(machInst, 10, 8);
                                              const uint32_t op2 = bits(machInst, 7, 0);
                                              if (op1 != 0) {
                                                  const bool enable = bits(machInst, 10, 9) == 0x2;
                                                  const uint32_t mods = bits(machInst, 8, 0) |
                                                                        ((enable ? 1 : 0) << 9);
                                                  return new Cps(machInst, mods);
                                              } else if ((op2 & 0xf0) == 0xf0) {
                                                  return new Dbg(machInst);
                                              } else {
                                                  switch (op2) {
                                                    case 0x0:
                                                      return new NopInst(machInst);
                                                    case 0x1:
                                                      return new YieldInst(machInst);
                                                    case 0x2:
                                                      return new WfeInst(machInst);
                                                    case 0x3:
                                                      return new WfiInst(machInst);
                                                    case 0x4:
                                                      return new SevInst(machInst);
                                                    default:
                                                      break;
                                                  }
                                              }
                                              break;
                                          }
                                        case 0x3b:
                                          {
                                              const uint32_t op = bits(machInst, 7, 4);
                                              switch (op) {
                                                case 0x0:
                                                  return new Leavex(machInst);
                                                case 0x1:
                                                  return new Enterx(machInst);
                                                case 0x2:
                                                  return new Clrex(machInst);
                                                case 0x4:
                                                  return new Dsb(machInst, 0);
                                                case 0x5:
                                                  return new Dmb(machInst, 0);
                                                case 0x6:
                                                  return new Isb(machInst, 0);
                                                default:
                                                  break;
                                              }
                                              break;
                                          }
                                        case 0x3c:
                                          {
                                              return new BxjReg(machInst,
                                                       (IntRegIndex)(uint32_t)bits(machInst, 19, 16),
                                                       COND_UC);
                                          }
                                        case 0x3d:
                                          {
                                              const uint32_t imm32 = bits(machInst, 7, 0);
                                              if (imm32 == 0) {
                                                  return new Eret(machInst);
                                              } else {
                                                  return new SubsImmPclr(machInst, INTREG_PC,
                                                                         INTREG_LR, imm32, false);
                                              }
                                          }
                                        case 0x3e:
                                        case 0x3f:
                                          {
                                              const IntRegIndex rd =
                                                  (IntRegIndex)(uint32_t)bits(machInst, 11, 8);
                                              const bool    r        = bits(machInst, 20);
                                              if (bits(machInst, 5)) {
                                                  const uint8_t sysM = (bits(machInst, 4) << 4) |
                                                                        bits(machInst, 11, 8);
                                                  return new MrsBankedReg(machInst, rd, sysM, r);
                                              } else {
                                                  if (r) {
                                                      return new MrsSpsr(machInst, rd);
                                                  } else {
                                                      return new MrsCpsr(machInst, rd);
                                                  }
                                              }
                                          }
                                        case 0xfe:
                                          {
                                              uint32_t imm16 = (bits(machInst, 19, 16) << 12) |
                                                               (bits(machInst, 11,  0) <<  0);
                                              return new Hvc(machInst, imm16);
                                          }
                                      }
                                      break;
                                  }
                                case 0x1:
                                  {
                                      const uint32_t s = bits(machInst, 26);
                                      const uint32_t i1 = !(bits(machInst, 13) ^ s);
                                      const uint32_t i2 = !(bits(machInst, 11) ^ s);
                                      const uint32_t imm10 = bits(machInst, 25, 16);
                                      const uint32_t imm11 = bits(machInst, 10, 0);
                                      const int32_t imm = sext<25>((s << 24) |
                                                                   (i1 << 23) | (i2 << 22) |
                                                                   (imm10 << 12) | (imm11 << 1));
                                      return new B(machInst, imm, COND_UC);
                                  }
                                case 0x4:
                                  {
                                      if (bits(machInst, 0) == 1) {
                                          return new Unknown(machInst);
                                      }
                                      const uint32_t s = bits(machInst, 26);
                                      const uint32_t i1 = !(bits(machInst, 13) ^ s);
                                      const uint32_t i2 = !(bits(machInst, 11) ^ s);
                                      const uint32_t imm10h = bits(machInst, 25, 16);
                                      const uint32_t imm10l = bits(machInst, 10, 1);
                                      const int32_t imm = sext<25>((s << 24) |
                                                                   (i1 << 23) | (i2 << 22) |
                                                                   (imm10h << 12) | (imm10l << 2));
                                      return new BlxImm(machInst, imm, COND_UC);
                                  }
                                case 0x5:
                                  {
                                      const uint32_t s = bits(machInst, 26);
                                      const uint32_t i1 = !(bits(machInst, 13) ^ s);
                                      const uint32_t i2 = !(bits(machInst, 11) ^ s);
                                      const uint32_t imm10 = bits(machInst, 25, 16);
                                      const uint32_t imm11 = bits(machInst, 10, 0);
                                      const int32_t imm = sext<25>((s << 24) |
                                                                   (i1 << 23) | (i2 << 22) |
                                                                   (imm10 << 12) | (imm11 << 1));
                                      return new Bl(machInst, imm, COND_UC);
                                  }
                                default:
                                  break;
                              }
                              return new Unknown(machInst);
                          }
                          break;
                    
                    default:
                      
                      // Unknown::unknown(([], {}))
                      return new Unknown(machInst);
                      break;
                    }
                  
                case 0x3: 
                  switch (HTOPCODE_10_9) {
                    
                    case 0x0: 
                      switch (HTOPCODE_4) {
                        
                        case 0x0: 
                          switch (HTOPCODE_8) {
                            
                            case 0x0:   
                              // Thumb32StoreSingle::thumb32StoreSingle(([], {}))
                              
                                  {
                                      uint32_t op1 = bits(machInst, 23, 21);
                                      uint32_t op2 = bits(machInst, 11, 6);
                                      bool op2Puw = ((op2 & 0x24) == 0x24 ||
                                                     (op2 & 0x3c) == 0x30);
                                      if (RN == 0xf) {
                                          return new Unknown(machInst);
                                      }
                                      if (op1 == 4) {
                                          return new STORE_IMM_AY_PN_SN_UN_WN_SZ1(machInst, RT, RN, true, IMMED_11_0);
                                      } else if (op1 == 0 && op2Puw) {
                                          
                                              {
                                                  uint32_t puw = bits(machInst, 10, 8);
                                                  uint32_t imm = IMMED_7_0;
                                                  switch (puw) {
                                                    case 0:
                                                    case 2:
                                                      // If we're here, either P or W must have been set.
                                                      panic("Neither P or W set, but that "
                                                              "shouldn't be possible.\n");
                                                    case 1:
                                                      return new STORE_IMM_AN_PY_SN_UN_WY_SZ1(machInst, RT, RN, false, imm);
                                                    case 3:
                                                      return new STORE_IMM_AY_PY_SN_UN_WY_SZ1(machInst, RT, RN, true, imm);
                                                    case 4:
                                                      return new STORE_IMM_AN_PN_SN_UN_WN_SZ1(machInst, RT, RN, false, imm);
                                                    case 5:
                                                      return new STORE_IMM_AN_PN_SN_UN_WY_SZ1(machInst, RT, RN, false, imm);
                                                    case 6:
                                                      return new STORE_IMM_AY_PN_SN_UN_WN_SZ1(machInst, RT, RN, true, imm);
                                                    case 7:
                                                      return new STORE_IMM_AY_PN_SN_UN_WY_SZ1(machInst, RT, RN, true, imm);
                                                  }
                                              }
                                      ;
                                      } else if (op1 == 0 && ((op2 & 0x3c) == 0x38)) {
                                          return new STORE_IMM_AY_PN_SN_UY_WN_SZ1(machInst, RT, RN, true, IMMED_7_0);
                                      } else if (op1 == 0 && op2 == 0) {
                                          return new STORE_REG_AY_PN_SN_UN_WN_SZ1(machInst, RT, RN, true,
                                                                  bits(machInst, 5, 4), LSL, RM);
                                      } else if (op1 == 5) {
                                          return new STORE_IMM_AY_PN_SN_UN_WN_SZ2(machInst, RT, RN, true, IMMED_11_0);
                                      } else if (op1 == 1 && op2Puw) {
                                          
                                              {
                                                  uint32_t puw = bits(machInst, 10, 8);
                                                  uint32_t imm = IMMED_7_0;
                                                  switch (puw) {
                                                    case 0:
                                                    case 2:
                                                      // If we're here, either P or W must have been set.
                                                      panic("Neither P or W set, but that "
                                                              "shouldn't be possible.\n");
                                                    case 1:
                                                      return new STORE_IMM_AN_PY_SN_UN_WY_SZ2(machInst, RT, RN, false, imm);
                                                    case 3:
                                                      return new STORE_IMM_AY_PY_SN_UN_WY_SZ2(machInst, RT, RN, true, imm);
                                                    case 4:
                                                      return new STORE_IMM_AN_PN_SN_UN_WN_SZ2(machInst, RT, RN, false, imm);
                                                    case 5:
                                                      return new STORE_IMM_AN_PN_SN_UN_WY_SZ2(machInst, RT, RN, false, imm);
                                                    case 6:
                                                      return new STORE_IMM_AY_PN_SN_UN_WN_SZ2(machInst, RT, RN, true, imm);
                                                    case 7:
                                                      return new STORE_IMM_AY_PN_SN_UN_WY_SZ2(machInst, RT, RN, true, imm);
                                                  }
                                              }
                                      ;
                                      } else if (op1 == 1 && ((op2 & 0x3c) == 0x38)) {
                                          return new STORE_IMM_AY_PN_SN_UY_WN_SZ2(machInst, RT, RN, true, IMMED_7_0);
                                      } else if (op1 == 1 && op2 == 0) {
                                          return new STORE_REG_AY_PN_SN_UN_WN_SZ2(machInst, RT, RN, true,
                                                                  bits(machInst, 5, 4), LSL, RM);
                                      } else if (op1 == 6) {
                                          return new STORE_IMM_AY_PN_SN_UN_WN_SZ4(machInst, RT, RN, true, IMMED_11_0);
                                      } else if (op1 == 2 && op2Puw) {
                                          
                                              {
                                                  uint32_t puw = bits(machInst, 10, 8);
                                                  uint32_t imm = IMMED_7_0;
                                                  switch (puw) {
                                                    case 0:
                                                    case 2:
                                                      // If we're here, either P or W must have been set.
                                                      panic("Neither P or W set, but that "
                                                              "shouldn't be possible.\n");
                                                    case 1:
                                                      return new STORE_IMM_AN_PY_SN_UN_WY_SZ4(machInst, RT, RN, false, imm);
                                                    case 3:
                                                      return new STORE_IMM_AY_PY_SN_UN_WY_SZ4(machInst, RT, RN, true, imm);
                                                    case 4:
                                                      return new STORE_IMM_AN_PN_SN_UN_WN_SZ4(machInst, RT, RN, false, imm);
                                                    case 5:
                                                      return new STORE_IMM_AN_PN_SN_UN_WY_SZ4(machInst, RT, RN, false, imm);
                                                    case 6:
                                                      return new STORE_IMM_AY_PN_SN_UN_WN_SZ4(machInst, RT, RN, true, imm);
                                                    case 7:
                                                      return new STORE_IMM_AY_PN_SN_UN_WY_SZ4(machInst, RT, RN, true, imm);
                                                  }
                                              }
                                      ;
                                      } else if (op1 == 2 && ((op2 & 0x3c) == 0x38)) {
                                          return new STORE_IMM_AY_PN_SN_UY_WN_SZ4(machInst, RT, RN, true, IMMED_7_0);
                                      } else if (op1 == 2 && op2 == 0) {
                                          return new STORE_REG_AY_PN_SN_UN_WN_SZ4(machInst, RT, RN, true,
                                                                 bits(machInst, 5, 4), LSL, RM);
                                      } else {
                                          return new Unknown(machInst);
                                      }
                                  }
                                  break;
                            
                            case 0x1:   
                              // ThumbNeonMem::thumbNeonMem(([], {}))
                              
                                  return decodeNeonMem(machInst);
                                  break;
                            
                            default:
                              
                              // Unknown::unknown(([], {}))
                              return new Unknown(machInst);
                              break;
                            }
                          
                        case 0x1: 
                          switch (HTOPCODE_6_5) {
                            
                            case 0x0:   
                              // LoadByteMemoryHints::loadByteMemoryHints(([], {}))
                              
                                  {
                                      const uint32_t op1 = bits(machInst, 24, 23);
                                      const uint32_t op2 = bits(machInst, 11, 6);
                                      const IntRegIndex rn = (IntRegIndex)(uint32_t)bits(machInst, 19, 16);
                                      const IntRegIndex rt = (IntRegIndex)(uint32_t)bits(machInst, 15, 12);
                                      const IntRegIndex rm = (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                      const uint32_t imm12 = bits(machInst, 11, 0);
                                      const uint32_t imm8 = bits(machInst, 7, 0);
                                      bool pldw = bits(machInst, 21);
                                      const uint32_t imm2 = bits(machInst, 5, 4);
                                      if (rn == 0xf) {
                                          if (rt == 0xf) {
                                              const bool add = bits(machInst, 23);
                                              if (bits(op1, 1) == 1) {
                                                  if (add) {
                                                      return new PLI_LOAD_IMM_AY_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO,
                                                                               INTREG_PC, true, imm12);
                                                  } else {
                                                      return new PLI_LOAD_IMM_AN_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO,
                                                                              INTREG_PC, false, imm12);
                                                  }
                                              } else {
                                                  if (add) {
                                                      return new PLD_LOAD_IMM_AY_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO,
                                                                               INTREG_PC, true, imm12);
                                                  } else {
                                                      return new PLD_LOAD_IMM_AN_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO,
                                                                              INTREG_PC, false, imm12);
                                                  }
                                              }
                                          } else {
                                              if (bits(op1, 1) == 1) {
                                                  if (bits(machInst, 23)) {
                                                      return new LOAD_IMM_AY_PN_SY_UN_WN_SZ1(machInst, rt, INTREG_PC,
                                                                                 true, imm12);
                                                  } else {
                                                      return new LOAD_IMM_AN_PN_SY_UN_WN_SZ1(machInst, rt, INTREG_PC,
                                                                               false, imm12);
                                                  }
                                              } else {
                                                  if (bits(machInst, 23)) {
                                                      return new LOAD_IMM_AY_PN_SN_UN_WN_SZ1(machInst, rt, INTREG_PC,
                                                                                true, imm12);
                                                  } else {
                                                      return new LOAD_IMM_AN_PN_SN_UN_WN_SZ1(machInst, rt, INTREG_PC,
                                                                              false, imm12);
                                                  }
                                              }
                                          }
                                      } else if (rt == 0xf) {
                                          switch (op1) {
                                            case 0x0:
                                              if (op2 == 0x0) {
                                                  if (pldw) {
                                                      return new PLDW_LOAD_REG_AY_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO,
                                                                               rn, true, imm2, LSL, rm);
                                                  } else {
                                                      return new PLD_LOAD_REG_AY_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO,
                                                                              rn, true, imm2, LSL, rm);
                                                  }
                                              } else if (bits(op2, 5, 2) == 0xc) {
                                                  if (pldw) {
                                                      return new PLDW_LOAD_IMM_AN_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO,
                                                                               rn, false, imm8);
                                                  } else {
                                                      return new PLD_LOAD_IMM_AN_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO,
                                                                              rn, false, imm8);
                                                  }
                                              }
                                              break;
                                            case 0x1:
                                              if (pldw) {
                                                  return new PLDW_LOAD_IMM_AY_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO,
                                                                           rn, true, imm12);
                                              } else {
                                                  return new PLD_LOAD_IMM_AY_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO,
                                                                          rn, true, imm12);
                                              }
                                            case 0x2:
                                              if (op2 == 0x0) {
                                                  return new PLI_LOAD_REG_AY_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO, rn,
                                                                          true, imm2, LSL, rm);
                                              } else if (bits(op2, 5, 2) == 0xc) {
                                                  return new PLI_LOAD_IMM_AN_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO,
                                                                          INTREG_PC, false, imm8);
                                              }
                                              break;
                                            case 0x3:
                                              return new PLI_LOAD_IMM_AY_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO,
                                                                      INTREG_PC, true, imm12);
                                          }
                                          return new Unknown(machInst);
                                      } else {
                                          switch (op1) {
                                            case 0x0:
                                              if (op2 == 0) {
                                                  return new LOAD_REG_AY_PN_SN_UN_WN_SZ1(machInst, rt, rn, true,
                                                                           imm2, LSL, rm);
                                              } else if (bits(op2, 5, 2) == 0xe) {
                                                  return new LOAD_IMM_AY_PN_SN_UY_WN_SZ1(machInst, rt, rn, true, imm8);
                                              } else if ((op2 & 0x24) == 0x24 || bits(op2, 5, 2) == 0xc) {
                                                  const uint32_t puw = bits(machInst, 10, 8);
                                                  switch (puw) {
                                                    case 0x1:
                                                      return new LOAD_IMM_AN_PY_SN_UN_WY_SZ1(machInst, rt,
                                                                             rn, false, imm8);
                                                    case 0x3:
                                                      return new LOAD_IMM_AY_PY_SN_UN_WY_SZ1(machInst, rt,
                                                                              rn, true, imm8);
                                                    case 0x4:
                                                      return new LOAD_IMM_AN_PN_SN_UN_WN_SZ1(machInst, rt,
                                                                             rn, false, imm8);
                                                    case 0x5:
                                                      return new LOAD_IMM_AN_PN_SN_UN_WY_SZ1(machInst, rt,
                                                                              rn, false, imm8);
                                                    case 0x7:
                                                      return new LOAD_IMM_AY_PN_SN_UN_WY_SZ1(machInst, rt,
                                                                               rn, true, imm8);
                                                  }
                                              }
                                              break;
                                            case 0x1:
                                              return new LOAD_IMM_AY_PN_SN_UN_WN_SZ1(machInst, rt, rn, true, imm12);
                                            case 0x2:
                                              if (op2 == 0) {
                                                  return new LOAD_REG_AY_PN_SY_UN_WN_SZ1(machInst, rt, rn, true,
                                                                            imm2, LSL, rm);
                                              } else if (bits(op2, 5, 2) == 0xe) {
                                                  return new LOAD_IMM_AY_PN_SY_UY_WN_SZ1(machInst, rt, rn, true, imm8);
                                              } else if ((op2 & 0x24) == 0x24 || bits(op2, 5, 2) == 0xc) {
                                                  const uint32_t puw = bits(machInst, 10, 8);
                                                  switch (puw) {
                                                    case 0x1:
                                                      return new LOAD_IMM_AN_PY_SY_UN_WY_SZ1(machInst, rt,
                                                                              rn, false, imm8);
                                                    case 0x3:
                                                      return new LOAD_IMM_AY_PY_SY_UN_WY_SZ1(machInst, rt,
                                                                               rn, true, imm8);
                                                    case 0x4:
                                                      return new LOAD_IMM_AN_PN_SY_UN_WN_SZ1(machInst, rt,
                                                                              rn, false, imm8);
                                                    case 0x5:
                                                      return new LOAD_IMM_AN_PN_SY_UN_WY_SZ1(machInst, rt,
                                                                               rn, false, imm8);
                                                    case 0x7:
                                                      return new LOAD_IMM_AY_PN_SY_UN_WY_SZ1(machInst, rt,
                                                                                rn, true, imm8);
                                                  }
                                              }
                                              break;
                                            case 0x3:
                                              return new LOAD_IMM_AY_PN_SY_UN_WN_SZ1(machInst, rt, rn, true, imm12);
                                          }
                                          return new Unknown(machInst);
                                      }
                                  }
                                  break;
                            
                            case 0x1:   
                              // LoadHalfwordMemoryHints::loadHalfwordMemoryHints(([], {}))
                              
                                  {
                                      const uint32_t op1 = bits(machInst, 24, 23);
                                      const uint32_t op2 = bits(machInst, 11, 6);
                                      const IntRegIndex rn = (IntRegIndex)(uint32_t)bits(machInst, 19, 16);
                                      const IntRegIndex rt = (IntRegIndex)(uint32_t)bits(machInst, 15, 12);
                                      const IntRegIndex rm = (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                      const uint32_t imm12 = bits(machInst, 11, 0);
                                      const uint32_t imm8 = bits(machInst, 7, 0);
                                      bool pldw = bits(machInst, 21);
                                      const uint32_t imm2 = bits(machInst, 5, 4);
                                      if (rn == 0xf) {
                                          if (rt == 0xf) {
                                              if (bits(op1, 1) == 1) {
                                                  // Unallocated memory hint
                                                  return new NopInst(machInst);
                                              } else {
                                                  return new Unknown(machInst);
                                              }
                                          } else {
                                              if (bits(op1, 1) == 1) {
                                                  if (bits(machInst, 23)) {
                                                      return new LOAD_IMM_AY_PN_SY_UN_WN_SZ2(machInst, rt, INTREG_PC,
                                                                                 true, imm12);
                                                  } else {
                                                      return new LOAD_IMM_AN_PN_SY_UN_WN_SZ2(machInst, rt, INTREG_PC,
                                                                               false, imm12);
                                                  }
                                              } else {
                                                  if (bits(machInst, 23)) {
                                                      return new LOAD_IMM_AY_PN_SN_UN_WN_SZ2(machInst, rt, INTREG_PC,
                                                                                true, imm12);
                                                  } else {
                                                      return new LOAD_IMM_AN_PN_SN_UN_WN_SZ2(machInst, rt, INTREG_PC,
                                                                              false, imm12);
                                                  }
                                              }
                                          }
                                      } else if (rt == 0xf) {
                                          switch (op1) {
                                            case 0x0:
                                              if (op2 == 0x0) {
                                                  if (pldw) {
                                                      return new PLDW_LOAD_REG_AY_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO,
                                                                               rn, true, imm2, LSL, rm);
                                                  } else {
                                                      return new PLD_LOAD_REG_AY_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO,
                                                                              rn, true, imm2, LSL, rm);
                                                  }
                                              } else if (bits(op2, 5, 2) == 0xc) {
                                                  if (pldw) {
                                                      return new PLDW_LOAD_IMM_AN_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO,
                                                                               rn, false, imm8);
                                                  } else {
                                                      return new PLD_LOAD_IMM_AN_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO,
                                                                              rn, false, imm8);
                                                  }
                                              }
                                              break;
                                            case 0x1:
                                              if (pldw) {
                                                  return new PLDW_LOAD_IMM_AY_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO,
                                                                           rn, true, imm12);
                                              } else {
                                                  return new PLD_LOAD_IMM_AY_PN_SN_UN_WN_SZ1(machInst, INTREG_ZERO,
                                                                          rn, true, imm12);
                                              }
                                            case 0x2:
                                              if (op2 == 0x0 || bits(op2, 5, 2) == 0xc) {
                                                  // Unallocated memory hint
                                                  return new NopInst(machInst);
                                              }
                                              break;
                                            case 0x3:
                                              return new NopInst(machInst);
                                          }
                                          return new Unknown(machInst);
                                      } else {
                                          switch (op1) {
                                            case 0x0:
                                              if (op2 == 0) {
                                                  return new LOAD_REG_AY_PN_SN_UN_WN_SZ2(machInst, rt, rn, true,
                                                                           imm2, LSL, rm);
                                              } else if (bits(op2, 5, 2) == 0xe) {
                                                  return new LOAD_IMM_AY_PN_SN_UY_WN_SZ2(machInst, rt, rn, true, imm8);
                                              } else if ((op2 & 0x24) == 0x24 || bits(op2, 5, 2) == 0xc) {
                                                  const uint32_t puw = bits(machInst, 10, 8);
                                                  switch (puw) {
                                                    case 0x1:
                                                      return new LOAD_IMM_AN_PY_SN_UN_WY_SZ2(machInst, rt,
                                                                             rn, false, imm8);
                                                    case 0x3:
                                                      return new LOAD_IMM_AY_PY_SN_UN_WY_SZ2(machInst, rt,
                                                                              rn, true, imm8);
                                                    case 0x4:
                                                      return new LOAD_IMM_AN_PN_SN_UN_WN_SZ2(machInst, rt,
                                                                             rn, false, imm8);
                                                    case 0x5:
                                                      return new LOAD_IMM_AN_PN_SN_UN_WY_SZ2(machInst, rt,
                                                                              rn, false, imm8);
                                                    case 0x7:
                                                      return new LOAD_IMM_AY_PN_SN_UN_WY_SZ2(machInst, rt,
                                                                               rn, true, imm8);
                                                  }
                                              }
                                              break;
                                            case 0x1:
                                              return new LOAD_IMM_AY_PN_SN_UN_WN_SZ2(machInst, rt, rn, true, imm12);
                                            case 0x2:
                                              if (op2 == 0) {
                                                  return new LOAD_REG_AY_PN_SY_UN_WN_SZ2(machInst, rt, rn, true,
                                                                            imm2, LSL, rm);
                                              } else if (bits(op2, 5, 2) == 0xe) {
                                                  return new LOAD_IMM_AY_PN_SY_UY_WN_SZ2(machInst, rt, rn, true, imm8);
                                              } else if ((op2 & 0x24) == 0x24 || bits(op2, 5, 2) == 0xc) {
                                                  const uint32_t puw = bits(machInst, 10, 8);
                                                  switch (puw) {
                                                    case 0x1:
                                                      return new LOAD_IMM_AN_PY_SY_UN_WY_SZ2(machInst, rt,
                                                                              rn, false, imm8);
                                                    case 0x3:
                                                      return new LOAD_IMM_AY_PY_SY_UN_WY_SZ2(machInst, rt,
                                                                               rn, true, imm8);
                                                    case 0x4:
                                                      return new LOAD_IMM_AN_PN_SY_UN_WN_SZ2(machInst, rt,
                                                                              rn, false, imm8);
                                                    case 0x5:
                                                      return new LOAD_IMM_AN_PN_SY_UN_WY_SZ2(machInst, rt,
                                                                               rn, false, imm8);
                                                    case 0x7:
                                                      return new LOAD_IMM_AY_PN_SY_UN_WY_SZ2(machInst, rt,
                                                                                rn, true, imm8);
                                                  }
                                              }
                                              break;
                                            case 0x3:
                                              return new LOAD_IMM_AY_PN_SY_UN_WN_SZ2(machInst, rt, rn, true, imm12);
                                          }
                                          return new Unknown(machInst);
                                      }
                                  }
                                  break;
                            
                            case 0x2:   
                              // Thumb32LoadWord::thumb32LoadWord(([], {}))
                              
                                  {
                                      uint32_t op1 = bits(machInst, 24, 23);
                                      if (bits(op1, 1) == 0) {
                                          uint32_t op2 = bits(machInst, 11, 6);
                                          if (HTRN == 0xF) {
                                              if (UP) {
                                                  return new LOAD_IMM_AY_PN_SN_UN_WN_SZ4(machInst, RT, INTREG_PC,
                                                                           true, IMMED_11_0);
                                              } else {
                                                  return new LOAD_IMM_AN_PN_SN_UN_WN_SZ4(machInst, RT, INTREG_PC,
                                                                         false, IMMED_11_0);
                                              }
                                          } else if (op1 == 0x1) {
                                              return new LOAD_IMM_AY_PN_SN_UN_WN_SZ4(machInst, RT, RN, true, IMMED_11_0);
                                          } else if (op2 == 0) {
                                              return new LOAD_REG_AY_PN_SN_UN_WN_SZ4(machInst, RT, RN, UP,
                                                                      bits(machInst, 5, 4), LSL, RM);
                                          } else if ((op2 & 0x3c) == 0x38) {
                                              return new LOAD_IMM_AY_PN_SN_UY_WN_SZ4(machInst, RT, RN, true, IMMED_7_0);
                                          } else if ((op2 & 0x3c) == 0x30 || //P
                                                     (op2 & 0x24) == 0x24) { //W
                                              uint32_t puw = bits(machInst, 10, 8);
                                              uint32_t imm = IMMED_7_0;
                                              switch (puw) {
                                                case 0:
                                                case 2:
                                                  // If we're here, either P or W must have been set.
                                                  panic("Neither P or W set, but that "
                                                          "shouldn't be possible.\n");
                                                case 1:
                                                  return new LOAD_IMM_AN_PY_SN_UN_WY_SZ4(machInst, RT, RN, false, imm);
                                                case 3:
                                                  return new LOAD_IMM_AY_PY_SN_UN_WY_SZ4(machInst, RT, RN, true, imm);
                                                case 4:
                                                  return new LOAD_IMM_AN_PN_SN_UN_WN_SZ4(machInst, RT, RN, false, imm);
                                                case 5:
                                                  return new LOAD_IMM_AN_PN_SN_UN_WY_SZ4(machInst, RT, RN, false, imm);
                                                case 6:
                                                  return new LOAD_IMM_AY_PN_SN_UN_WN_SZ4(machInst, RT, RN, true, imm);
                                                case 7:
                                                  return new LOAD_IMM_AY_PN_SN_UN_WY_SZ4(machInst, RT, RN, true, imm);
                                              }
                                          }
                                      } else {
                                          return new Unknown(machInst);
                                      }
                                  }
                                  break;
                            
                            default:
                              
                              // Unknown::unknown(([], {}))
                              return new Unknown(machInst);
                              break;
                            }
                          
                        default:
                          
                          // Unknown::unknown(([], {}))
                          return new Unknown(machInst);
                          break;
                        }
                      
                    case 0x1: 
                      switch (HTOPCODE_8_7) {
                        
                        case 0x2:   
                          // Thumb32MulMulAccAndAbsDiff::thumb32MulMulAccAndAbsDiff(([], {}))
                          
                              {
                                  const uint32_t op1 = bits(machInst, 22, 20);
                                  const uint32_t op2 = bits(machInst, 5, 4);
                                  const IntRegIndex ra = (IntRegIndex)(uint32_t)bits(machInst, 15, 12);
                                  const IntRegIndex rn = (IntRegIndex)(uint32_t)bits(machInst, 19, 16);
                                  const IntRegIndex rd = (IntRegIndex)(uint32_t)bits(machInst, 11, 8);
                                  const IntRegIndex rm = (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                  if (op1 != 0x1 && bits(op2, 1) != 0) {
                                      return new Unknown(machInst);
                                  }
                                  switch (op1) {
                                    case 0x0:
                                      if (op2 == 0) {
                                          if (ra == 0xf) {
                                              return new Mul(machInst, rd, rn, rm);
                                          } else {
                                              return new Mla(machInst, rd, rn, rm, ra);
                                          }
                                      } else {
                                          return new Mls(machInst, rd, rn, rm, ra);
                                      }
                                    case 0x1:
                                      if (ra == 0xf) {
                                          switch (bits(machInst, 5, 4)) {
                                            case 0x0:
                                              return new Smulbb(machInst, rd, rn, rm);
                                            case 0x1:
                                              return new Smulbt(machInst, rd, rn, rm);
                                            case 0x2:
                                              return new Smultb(machInst, rd, rn, rm);
                                            case 0x3:
                                              return new Smultt(machInst, rd, rn, rm);
                                          }
                                      } else {
                                          switch (bits(machInst, 5, 4)) {
                                            case 0x0:
                                              return new SmlabbCc(machInst, rd, rn, rm, ra);
                                            case 0x1:
                                              return new SmlabtCc(machInst, rd, rn, rm, ra);
                                            case 0x2:
                                              return new SmlatbCc(machInst, rd, rn, rm, ra);
                                            case 0x3:
                                              return new SmlattCc(machInst, rd, rn, rm, ra);
                                          }
                                      }
                                    case 0x2:
                                      if (ra == 0xf) {
                                          if (bits(machInst, 4)) {
                                              return new SmuadxCc(machInst, rd, rn, rm);
                                          } else {
                                              return new SmuadCc(machInst, rd, rn, rm);
                                          }
                                      } else {
                                          if (bits(machInst, 4)) {
                                              return new SmladxCc(machInst, rd, rn, rm, ra);
                                          } else {
                                              return new SmladCc(machInst, rd, rn, rm, ra);
                                          }
                                      }
                                    case 0x3:
                                      if (ra == 0xf) {
                                          if (bits(machInst, 4)) {
                                              return new Smulwt(machInst, rd, rn, rm);
                                          } else {
                                              return new Smulwb(machInst, rd, rn, rm);
                                          }
                                      } else {
                                          if (bits(machInst, 4)) {
                                              return new SmlawtCc(machInst, rd, rn, rm, ra);
                                          } else {
                                              return new SmlawbCc(machInst, rd, rn, rm, ra);
                                          }
                                      }
                                    case 0x4:
                                      if (ra == 0xf) {
                                          if (bits(machInst, 4)) {
                                              return new Smusdx(machInst, rd, rn, rm);
                                          } else {
                                              return new Smusd(machInst, rd, rn, rm);
                                          }
                                      } else {
                                          if (bits(machInst, 4)) {
                                              return new SmlsdxCc(machInst, rd, rn, rm, ra);
                                          } else {
                                              return new SmlsdCc(machInst, rd, rn, rm, ra);
                                          }
                                      }
                                    case 0x5:
                                      if (ra == 0xf) {
                                          if (bits(machInst, 4)) {
                                              return new Smmulr(machInst, rd, rn, rm);
                                          } else {
                                              return new Smmul(machInst, rd, rn, rm);
                                          }
                                      } else {
                                          if (bits(machInst, 4)) {
                                              return new Smmlar(machInst, rd, rn, rm, ra);
                                          } else {
                                              return new Smmla(machInst, rd, rn, rm, ra);
                                          }
                                      }
                                    case 0x6:
                                      if (bits(machInst, 4)) {
                                          return new Smmlsr(machInst, rd, rn, rm, ra);
                                      } else {
                                          return new Smmls(machInst, rd, rn, rm, ra);
                                      }
                                    case 0x7:
                                      if (op2 != 0x0) {
                                          return new Unknown(machInst);
                                      } else if (ra == 0xf) {
                                          return new Usad8(machInst, rd, rn, rm);
                                      } else {
                                          return new Usada8(machInst, rd, rn, rm, ra);
                                      }
                                  }
                              }
                              break;
                        
                        case 0x3:   
                          // Thumb32LongMulMulAccAndDiv::thumb32LongMulMulAccAndDiv(([], {}))
                          
                              {
                                  const uint32_t op1 = bits(machInst, 22, 20);
                                  const uint32_t op2 = bits(machInst, 7, 4);
                                  const IntRegIndex rn = (IntRegIndex)(uint32_t)bits(machInst, 19, 16);
                                  const IntRegIndex rdlo = (IntRegIndex)(uint32_t)bits(machInst, 15, 12);
                                  const IntRegIndex rdhi = (IntRegIndex)(uint32_t)bits(machInst, 11, 8);
                                  const IntRegIndex rm = (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                  switch (op1) {
                                    case 0x0:
                                      if (op2 == 0x0) {
                                          return new Smull(machInst, rdlo, rdhi, rn, rm);
                                      }
                                      break;
                                    case 0x1:
                                      if (op2 == 0xf) {
                                          return new Sdiv(machInst, rdhi, rn, rm);
                                      }
                                      break;
                                    case 0x2:
                                      if (op2 == 0x0) {
                                          return new Umull(machInst, rdlo, rdhi, rn, rm);
                                      }
                                      break;
                                    case 0x3:
                                      if (op2 == 0xf) {
                                          return new Udiv(machInst, rdhi, rn, rm);
                                      }
                                      break;
                                    case 0x4:
                                      if (op2 == 0) {
                                          return new Smlal(machInst, rdlo, rdhi, rn, rm);
                                      } else if (bits(op2, 3, 2) == 0x2) {
                                          switch (bits(machInst, 5, 4)) {
                                            case 0x0:
                                              return new Smlalbb(machInst, rdlo, rdhi, rn, rm);
                                            case 0x1:
                                              return new Smlalbt(machInst, rdlo, rdhi, rn, rm);
                                            case 0x2:
                                              return new Smlaltb(machInst, rdlo, rdhi, rn, rm);
                                            case 0x3:
                                              return new Smlaltt(machInst, rdlo, rdhi, rn, rm);
                                          }
                                      } else if (bits(op2, 3, 1) == 0x6) {
                                          if (bits(machInst, 4)) {
                                              return new Smlaldx(machInst, rdlo, rdhi, rn, rm);
                                          } else {
                                              return new Smlald(machInst, rdlo, rdhi, rn, rm);
                                          }
                                      }
                                      break;
                                    case 0x5:
                                      if (bits(op2, 3, 1) == 0x6) {
                                          if (bits(machInst, 4)) {
                                              return new Smlsldx(machInst, rdlo, rdhi, rn, rm);
                                          } else {
                                              return new Smlsld(machInst, rdlo, rdhi, rn, rm);
                                          }
                                      }
                                      break;
                                    case 0x6:
                                      if (op2 == 0) {
                                          return new Umlal(machInst, rdlo, rdhi, rn, rm);
                                      } else if (op2 == 0x6) {
                                          return new Umaal(machInst, rdlo, rdhi, rn, rm);
                                      }
                                      break;
                                  }
                                  return new Unknown(machInst);
                              }
                              break;
                        
                        default:  
                          // Thumb32DataProcReg::thumb32DataProcReg(([], {}))
                          
                              {
                                  const uint32_t op1 = bits(machInst, 23, 20);
                                  const IntRegIndex rn = (IntRegIndex)(uint32_t)bits(machInst, 19, 16);
                                  const uint32_t op2 = bits(machInst, 7, 4);
                                  if (bits(machInst, 15, 12) != 0xf) {
                                      return new Unknown(machInst);
                                  }
                                  if (bits(op1, 3) != 1) {
                                      if (op2 == 0) {
                                          IntRegIndex rd = (IntRegIndex)(uint32_t)bits(machInst, 11, 8);
                                          IntRegIndex rm = (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                          switch (bits(op1, 2, 0)) {
                                            case 0x0:
                                              return new MovRegReg(machInst, rd,
                                                      INTREG_ZERO, rn, rm, LSL);
                                            case 0x1:
                                              return new MovRegRegCc(machInst, rd,
                                                      INTREG_ZERO, rn, rm, LSL);
                                            case 0x2:
                                              return new MovRegReg(machInst, rd,
                                                      INTREG_ZERO, rn, rm, LSR);
                                            case 0x3:
                                              return new MovRegRegCc(machInst, rd,
                                                      INTREG_ZERO, rn, rm, LSR);
                                            case 0x4:
                                              return new MovRegReg(machInst, rd,
                                                      INTREG_ZERO, rn, rm, ASR);
                                            case 0x5:
                                              return new MovRegRegCc(machInst, rd,
                                                      INTREG_ZERO, rn, rm, ASR);
                                            case 0x6:
                                              return new MovRegReg(machInst, rd,
                                                      INTREG_ZERO, rn, rm, ROR);
                                            case 0x7:
                                              return new MovRegRegCc(machInst, rd,
                                                      INTREG_ZERO, rn, rm, ROR);
                                          }
                                      } else if (bits(op2, 3) == 0) {
                                          return new Unknown(machInst);
                                      } else {
                                          const IntRegIndex rd =
                                              (IntRegIndex)(uint32_t)bits(machInst, 11, 8);
                                          const IntRegIndex rm =
                                              (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                          const uint32_t rotation =
                                              (uint32_t)bits(machInst, 5, 4) << 3;
                                          switch (bits(op1, 2, 0)) {
                                            case 0x0:
                                              if (rn == 0xf) {
                                                  return new Sxth(machInst, rd, rotation, rm);
                                              } else {
                                                  return new Sxtah(machInst, rd, rn, rm, rotation);
                                              }
                                            case 0x1:
                                              if (rn == 0xf) {
                                                  return new Uxth(machInst, rd, rotation, rm);
                                              } else {
                                                  return new Uxtah(machInst, rd, rn, rm, rotation);
                                              }
                                            case 0x2:
                                              if (rn == 0xf) {
                                                  return new Sxtb16(machInst, rd, rotation, rm);
                                              } else {
                                                  return new Sxtab16(machInst, rd, rn, rm, rotation);
                                              }
                                            case 0x3:
                                              if (rn == 0xf) {
                                                  return new Uxtb16(machInst, rd, rotation, rm);
                                              } else {
                                                  return new Uxtab16(machInst, rd, rn, rm, rotation);
                                              }
                                            case 0x4:
                                              if (rn == 0xf) {
                                                  return new Sxtb(machInst, rd, rotation, rm);
                                              } else {
                                                  return new Sxtab(machInst, rd, rn, rm, rotation);
                                              }
                                            case 0x5:
                                              if (rn == 0xf) {
                                                  return new Uxtb(machInst, rd, rotation, rm);
                                              } else {
                                                  return new Uxtab(machInst, rd, rn, rm, rotation);
                                              }
                                            default:
                                              return new Unknown(machInst);
                                          }
                                      }
                                  } else {
                                      if (bits(op2, 3) == 0) {
                                          const IntRegIndex rd =
                                              (IntRegIndex)(uint32_t)bits(machInst, 11, 8);
                                          const IntRegIndex rm =
                                              (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                          if (bits(op2, 2) == 0x0) {
                                              const uint32_t op1 = bits(machInst, 22, 20);
                                              const uint32_t op2 = bits(machInst, 5, 4);
                                              switch (op2) {
                                                case 0x0:
                                                  switch (op1) {
                                                    case 0x1:
                                                      return new Sadd16RegCc(machInst, rd,
                                                                             rn, rm, 0, LSL);
                                                    case 0x2:
                                                      return new SasxRegCc(machInst, rd,
                                                                           rn, rm, 0, LSL);
                                                    case 0x6:
                                                      return new SsaxRegCc(machInst, rd,
                                                                           rn, rm, 0, LSL);
                                                    case 0x5:
                                                      return new Ssub16RegCc(machInst, rd,
                                                                             rn, rm, 0, LSL);
                                                    case 0x0:
                                                      return new Sadd8RegCc(machInst, rd,
                                                                            rn, rm, 0, LSL);
                                                    case 0x4:
                                                      return new Ssub8RegCc(machInst, rd,
                                                                            rn, rm, 0, LSL);
                                                  }
                                                  break;
                                                case 0x1:
                                                  switch (op1) {
                                                    case 0x1:
                                                      return new Qadd16Reg(machInst, rd, rn, rm, 0, LSL);
                                                    case 0x2:
                                                      return new QasxReg(machInst, rd, rn, rm, 0, LSL);
                                                    case 0x6:
                                                      return new QsaxReg(machInst, rd, rn, rm, 0, LSL);
                                                    case 0x5:
                                                      return new Qsub16Reg(machInst, rd, rn, rm, 0, LSL);
                                                    case 0x0:
                                                      return new Qadd8Reg(machInst, rd, rn, rm, 0, LSL);
                                                    case 0x4:
                                                      return new Qsub8Reg(machInst, rd, rn, rm, 0, LSL);
                                                  }
                                                  break;
                                                case 0x2:
                                                  switch (op1) {
                                                    case 0x1:
                                                      return new Shadd16Reg(machInst, rd, rn, rm, 0, LSL);
                                                    case 0x2:
                                                      return new ShasxReg(machInst, rd, rn, rm, 0, LSL);
                                                    case 0x6:
                                                      return new ShsaxReg(machInst, rd, rn, rm, 0, LSL);
                                                    case 0x5:
                                                      return new Shsub16Reg(machInst, rd, rn, rm, 0, LSL);
                                                    case 0x0:
                                                      return new Shadd8Reg(machInst, rd, rn, rm, 0, LSL);
                                                    case 0x4:
                                                      return new Shsub8Reg(machInst, rd, rn, rm, 0, LSL);
                                                  }
                                                  break;
                                              }
                                          } else {
                                              const uint32_t op1 = bits(machInst, 22, 20);
                                              const uint32_t op2 = bits(machInst, 5, 4);
                                              switch (op2) {
                                                case 0x0:
                                                  switch (op1) {
                                                    case 0x1:
                                                      return new Uadd16RegCc(machInst, rd,
                                                                             rn, rm, 0, LSL);
                                                    case 0x2:
                                                      return new UasxRegCc(machInst, rd,
                                                                           rn, rm, 0, LSL);
                                                    case 0x6:
                                                      return new UsaxRegCc(machInst, rd,
                                                                           rn, rm, 0, LSL);
                                                    case 0x5:
                                                      return new Usub16RegCc(machInst, rd,
                                                                             rn, rm, 0, LSL);
                                                    case 0x0:
                                                      return new Uadd8RegCc(machInst, rd,
                                                                            rn, rm, 0, LSL);
                                                    case 0x4:
                                                      return new Usub8RegCc(machInst, rd,
                                                                            rn, rm, 0, LSL);
                                                  }
                                                  break;
                                                case 0x1:
                                                  switch (op1) {
                                                    case 0x1:
                                                      return new Uqadd16Reg(machInst, rd, rn, rm, 0, LSL);
                                                    case 0x2:
                                                      return new UqasxReg(machInst, rd, rn, rm, 0, LSL);
                                                    case 0x6:
                                                      return new UqsaxReg(machInst, rd, rn, rm, 0, LSL);
                                                    case 0x5:
                                                      return new Uqsub16Reg(machInst, rd, rn, rm, 0, LSL);
                                                    case 0x0:
                                                      return new Uqadd8Reg(machInst, rd, rn, rm, 0, LSL);
                                                    case 0x4:
                                                      return new Uqsub8Reg(machInst, rd, rn, rm, 0, LSL);
                                                  }
                                                  break;
                                                case 0x2:
                                                  switch (op1) {
                                                    case 0x1:
                                                      return new Uhadd16Reg(machInst, rd, rn, rm, 0, LSL);
                                                    case 0x2:
                                                      return new UhasxReg(machInst, rd, rn, rm, 0, LSL);
                                                    case 0x6:
                                                      return new UhsaxReg(machInst, rd, rn, rm, 0, LSL);
                                                    case 0x5:
                                                      return new Uhsub16Reg(machInst, rd, rn, rm, 0, LSL);
                                                    case 0x0:
                                                      return new Uhadd8Reg(machInst, rd, rn, rm, 0, LSL);
                                                    case 0x4:
                                                      return new Uhsub8Reg(machInst, rd, rn, rm, 0, LSL);
                                                  }
                                                  break;
                                              }
                                          }
                                      } else if (bits(op1, 3, 2) == 0x2 && bits(op2, 3, 2) == 0x2) {
                                          const uint32_t op1 = bits(machInst, 21, 20);
                                          const uint32_t op2 = bits(machInst, 5, 4);
                                          const IntRegIndex rd =
                                              (IntRegIndex)(uint32_t)bits(machInst, 11, 8);
                                          const IntRegIndex rm =
                                              (IntRegIndex)(uint32_t)bits(machInst, 3, 0);
                                          switch (op1) {
                                            case 0x0:
                                              switch (op2) {
                                                case 0x0:
                                                  return new QaddRegCc(machInst, rd,
                                                                       rm, rn, 0, LSL);
                                                case 0x1:
                                                  return new QdaddRegCc(machInst, rd,
                                                                        rm, rn, 0, LSL);
                                                case 0x2:
                                                  return new QsubRegCc(machInst, rd,
                                                                       rm, rn, 0, LSL);
                                                case 0x3:
                                                  return new QdsubRegCc(machInst, rd,
                                                                        rm, rn, 0, LSL);
                                              }
                                              break;
                                            case 0x1:
                                              switch (op2) {
                                                case 0x0:
                                                  return new Rev(machInst, rd, rn);
                                                case 0x1:
                                                  return new Rev16(machInst, rd, rn);
                                                case 0x2:
                                                  return new Rbit(machInst, rd, rm);
                                                case 0x3:
                                                  return new Revsh(machInst, rd, rn);
                                              }
                                              break;
                                            case 0x2:
                                              if (op2 == 0) {
                                                  return new Sel(machInst, rd, rn, rm);
                                              }
                                              break;
                                            case 0x3:
                                              if (op2 == 0) {
                                                  return new Clz(machInst, rd, rm);
                                              }
                                          }
                                      }
                                      return new Unknown(machInst);
                                  }
                              }
                              break;
                        }
                      
                    default:
                      switch (HTOPCODE_9_8) {
                        
                        case 0x2: 
                          switch (LTOPCODE_4) {
                            
                            case 0x0: 
                              switch (LTCOPROC) {
                                
                                case 0xa: case 0xb:   
                                  // VfpData::vfpData(([], {}))
                                  
                                      return decodeVfpData(machInst);
                                      break;
                                
                                default:  
                                  // WarnUnimpl::cdp(([], {}))
                                  
                                          return new WarnUnimplemented("cdp", machInst);
                                  break;
                                }
                              
                            case 0x1: 
                              switch (LTCOPROC) {
                                
                                case 0x1:   
                                  // M5ops::m5ops(([], {}))
                                  
                                      {
                                          const uint32_t m5func = bits(machInst, 23, 16);
                                          switch(m5func) {
                                              case 0x00: return new Arm(machInst);
                                              case 0x01: return new Quiesce(machInst);
                                              case 0x02: return new QuiesceNs(machInst);
                                              case 0x03: return new QuiesceCycles(machInst);
                                              case 0x04: return new QuiesceTime(machInst);
                                              case 0x07: return new Rpns(machInst);
                                              case 0x09: return new WakeCPU(machInst);
                                              case 0x10: return new Deprecated_ivlb(machInst);
                                              case 0x11: return new Deprecated_ivle(machInst);
                                              case 0x20: return new Deprecated_exit (machInst);
                                              case 0x21: return new M5exit(machInst);
                                              case 0x22: return new M5fail(machInst);
                                              case 0x31: return new Loadsymbol(machInst);
                                              case 0x30: return new Initparam(machInst);
                                              case 0x40: return new Resetstats(machInst);
                                              case 0x41: return new Dumpstats(machInst);
                                              case 0x42: return new Dumpresetstats(machInst);
                                              case 0x43: return new M5checkpoint(machInst);
                                              case 0x4F: return new M5writefile(machInst);
                                              case 0x50: return new M5readfile(machInst);
                                              case 0x51: return new M5break(machInst);
                                              case 0x52: return new M5switchcpu(machInst);
                                              case 0x53: return new M5addsymbol(machInst);
                                              case 0x54: return new M5panic(machInst);
                                              case 0x5a: return new M5workbegin(machInst);
                                              case 0x5b: return new M5workend(machInst);
                                          }
                                     }
                                     break;
                                
                                case 0xa: case 0xb:   
                                  // ShortFpTransfer::shortFpTransfer(([], {}))
                                  
                                      return decodeShortFpTransfer(machInst);
                                      break;
                                
                                case 0xe:   
                                  // McrMrc14::mcrMrc14(([], {}))
                                  
                                      return decodeMcrMrc14(machInst);
                                      break;
                                
                                case 0xf:   
                                  // McrMrc15::mcrMrc15(([], {}))
                                  
                                      return decodeMcrMrc15(machInst);
                                      break;
                                
                                default:
                                  
                                  // Unknown::unknown(([], {}))
                                  return new Unknown(machInst);
                                  break;
                                }
                              
                            default:
                              
                              // Unknown::unknown(([], {}))
                              return new Unknown(machInst);
                              break;
                            }
                          
                        case 0x3:   
                          // ThumbNeonData::thumbNeonData(([], {}))
                          
                              return decodeNeonData(machInst);
                              break;
                        
                        default:
                          switch (LTCOPROC) {
                            
                            case 0xa: case 0xb:   
                              // ExtensionRegLoadStore::extensionRegLoadStre(([], {}))
                              
                                  return decodeExtensionRegLoadStore(machInst);
                                  break;
                            
                            case 0xf: 
                              switch (HTOPCODE_9_4) {
                                
                                case 0x0:   
                                  // Unknown::undefined(([], {}))
                                  return new Unknown(machInst);
                                  break;
                                
                                case 0x4:   
                                  // WarnUnimpl::mcrr(([], {}))
                                  
                                          return new WarnUnimplemented("mcrr", machInst);
                                  break;
                                
                                case 0x5:   
                                  // WarnUnimpl::mrrc(([], {}))
                                  
                                          return new WarnUnimplemented("mrrc", machInst);
                                  break;
                                
                                case 0x2: case 0x6: case 0x8: case 0xa: case 0xc: case 0xe: case 0x10: case 0x12: case 0x14: case 0x16: case 0x18: case 0x1a: case 0x1c: case 0x1e:   
                                  // WarnUnimpl::stc(([], {}))
                                  
                                          return new WarnUnimplemented("stc", machInst);
                                  break;
                                
                                case 0x3: case 0x7: case 0x9: case 0xb: case 0xd: case 0xf: case 0x11: case 0x13: case 0x15: case 0x17: case 0x19: case 0x1b: case 0x1d: case 0x1f: 
                                  switch (HTRN) {
                                    
                                    case 0xf:   
                                      // WarnUnimpl::ldc(([], {}))
                                      
                                              return new WarnUnimplemented("ldc", machInst);
                                      break;
                                    
                                    default:  
                                      // WarnUnimpl::ldc(([], {}))
                                      
                                              return new WarnUnimplemented("ldc", machInst);
                                      break;
                                    }
                                  
                                default:
                                  
                                  // Unknown::unknown(([], {}))
                                  return new Unknown(machInst);
                                  break;
                                }
                              
                            default:
                              
                              // Unknown::unknown(([], {}))
                              return new Unknown(machInst);
                              break;
                            }
                          }
                      }
                  
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              
            default:
              
              // Unknown::unknown(([], {}))
              return new Unknown(machInst);
              break;
            }
          
        default:
          
          // Unknown::unknown(([], {}))
          return new Unknown(machInst);
          break;
        }
      
    default:
      
      // DecoderFault::decoderFault(([], {}))
      
              return new DecoderFaultInst(machInst);
          break;
    }
  }