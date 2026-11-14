# Native simulator verification

## External-base migration (M1 complete)

The operator's replacement plan is in [todo section 4](../docs/todo.md).
The external bases are forks, pinned as Git submodules; changes needed by
kprog belong in those forks. No replacement ISA semantics is defined locally.

| Base | Fork / submodule | Pinned source | Upstream toolchain |
|---|---|---|---|
| AArch64 | [eunomia-bpf/LNSym](https://github.com/eunomia-bpf/LNSym), `external/LNSym` | `4a9bc9df5a6e` | Lean 4.35.0 |
| x86-64 | [eunomia-bpf/x86lean](https://github.com/eunomia-bpf/x86lean), `external/x86lean` | `74a2e2849cde` | Lean 4.32.0-rc1 |
| Clight | [eunomia-bpf/clean](https://github.com/eunomia-bpf/clean), `external/clean/export` | `123f7f7767e2` | Lean 4.32.1 |

`make -C kprog/formal mature` builds the migration Lake package on Lean 4.35.0,
importing the external `Arm`, `X86`, `CCLib` and `Clightdefs` libraries directly.
The combined build passed on 2026-11-14 (121 Lake jobs), importing all four
libraries on the common toolchain. The x86lean fork patch `74a2e2849cde`
uses an explicit Boolean-decision bridge for the existing masked-count
hypothesis; its theorem statement and instruction semantics are unchanged.
Build output and the earlier failed attempts are retained in
`/workspaces/kprog-raw/formal/m1-compat-2` and `m1-compat-1`.
The legacy package remains on Lean 4.19.0 while M3-M5 migrate its references
and theorems. M2 coverage is pending; the legacy counts below describe the old
foundation, not proofs against these external bases. Retirement occurs at M6.

LNSym and x86lean retain their Apache-2.0 licenses. Clean retains its own
[LICENSE](external/clean/LICENSE): its tree is under INRIA non-commercial
terms, with the listed components, including `export/`, also offered under
LGPL-2.1-or-later. Keep those license terms separate. Clean explicitly labels
its C-to-Lean exporter/semantics experimental in its upstream README; the
CompCert front end and the Lean export/semantics have separate trust claims.

## Operation coverage (M2 in progress)

LNSym `4a9bc9df5a6e66ba048c07c27da2f642093d9b95`, x86lean `74a2e2849cde10fce9035c6abb7fdd49968b2915`.

Source inspection, not refinement proofs or conformance results. `present` means an execution path exists; `partial`/`missing` remain M2 work; `layer` identifies linking/ABI transport above an existing ISA form. Memory permissions, initialization, fault prefixes, exclusive ordering and ABI require explicit relations.

LNSym `4a9bc9df5a6e` adds the conditional increment/invert/negate forms through
its existing execution function and expands its random conformance generator.
The combined build and 24 encoded regression vectors passed on 2026-11-14
(`m2-select-3`, 122 Lake jobs). These use upstream-style `native_decide` finite
checks; they are not hardware differential results or migrated refinement counts.

### AArch64: 74 simulator operations

| Code | Operation | Source status | LNSym source (Arm/Insts unless Arm/) | Constraint / work |
|---|---|---|---|---|
| 0x00 | `NOP` | present | [BR/Hints.lean](external/LNSym/Arm/Insts/BR/Hints.lean) | NOP encoding |
| 0x01 | `MOV_IMM` | present | [DPI/Move_wide_imm.lean](external/LNSym/Arm/Insts/DPI/Move_wide_imm.lean) | MOVZ/MOVN/MOVK, retain width and encoding |
| 0x02 | `MOV_REG` | present | [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean); [DPI/Add_sub_imm.lean](external/LNSym/Arm/Insts/DPI/Add_sub_imm.lean) | ORR alias for GPR/ZR; ADD immediate0 alias for SP, keep register identities |
| 0x03 | `ADD_IMM` | present | [DPI/Add_sub_imm.lean](external/LNSym/Arm/Insts/DPI/Add_sub_imm.lean) | S/op/Rd encode CMP/CMN |
| 0x04 | `SUB_IMM` | present | [DPI/Add_sub_imm.lean](external/LNSym/Arm/Insts/DPI/Add_sub_imm.lean) | S/op/Rd encode CMP/CMN |
| 0x05 | `MOVK` | present | [DPI/Move_wide_imm.lean](external/LNSym/Arm/Insts/DPI/Move_wide_imm.lean) | MOVZ/MOVN/MOVK, retain width and encoding |
| 0x06 | `ALU_IMM` | present | [DPI/Logical_imm.lean](external/LNSym/Arm/Insts/DPI/Logical_imm.lean) | Requires architectural bitmask encoding |
| 0x07 | `ALU_REG` | partial | [DPR/Add_sub_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_shifted_reg.lean); [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean) | Shifted forms exist; add/sub extended-register class absent |
| 0x08 | `SHIFT_IMM` | partial | [DPI/Bitfield.lean](external/LNSym/Arm/Insts/DPI/Bitfield.lean) | LSL/LSR/ASR aliases exist; ROR requires scalar EXTR, absent |
| 0x09 | `SHIFT_REG` | present | [DPR/Data_processing_two_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_two_source.lean) | LSLV/LSRV/ASRV/RORV |
| 0x0a | `MADD` | present | [DPR/Data_processing_three_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_three_source.lean) | MUL aliases MADD with Ra=XZR |
| 0x0b | `MSUB` | missing | [DPR/Data_processing_three_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_three_source.lean) | Only MADD executes; other valid forms explicitly Unimplemented |
| 0x0c | `MUL` | present | [DPR/Data_processing_three_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_three_source.lean) | MUL aliases MADD with Ra=XZR |
| 0x0d | `UMULL` | missing | [DPR/Data_processing_three_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_three_source.lean) | Only MADD executes; other valid forms explicitly Unimplemented |
| 0x0e | `UDIV` | missing | [DPR/Data_processing_two_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_two_source.lean) | Only variable shifts execute |
| 0x0f | `MVN` | present | [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean); [DPI/Logical_imm.lean](external/LNSym/Arm/Insts/DPI/Logical_imm.lean) | Alias encodings |
| 0x10 | `NEG` | partial | [DPR/Add_sub_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_shifted_reg.lean); [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean) | Shifted forms exist; add/sub extended-register class absent |
| 0x11 | `EXTR` | missing | [Arm/Decode/DPR.lean](external/LNSym/Arm/Decode/DPR.lean); [Arm/Exec.lean](external/LNSym/Arm/Exec.lean) | Scalar EXTR absent; SIMD extract is different |
| 0x12 | `BITFIELD` | present | [DPI/Bitfield.lean](external/LNSym/Arm/Insts/DPI/Bitfield.lean) | BFM/SBFM/UBFM and extension aliases |
| 0x13 | `REV` | present | [DPR/Data_processing_one_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_one_source.lean) | REV widths per legal opcode |
| 0x14 | `REV16` | present | [DPR/Data_processing_one_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_one_source.lean) | REV widths per legal opcode |
| 0x15 | `SXTH` | present | [DPI/Bitfield.lean](external/LNSym/Arm/Insts/DPI/Bitfield.lean) | BFM/SBFM/UBFM and extension aliases |
| 0x16 | `CMP_IMM` | present | [DPI/Add_sub_imm.lean](external/LNSym/Arm/Insts/DPI/Add_sub_imm.lean) | S/op/Rd encode CMP/CMN |
| 0x17 | `CMP_REG` | partial | [DPR/Add_sub_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_shifted_reg.lean); [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean) | Shifted forms exist; add/sub extended-register class absent |
| 0x18 | `TST_IMM` | present | [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean); [DPI/Logical_imm.lean](external/LNSym/Arm/Insts/DPI/Logical_imm.lean) | Alias encodings |
| 0x19 | `TST_REG` | present | [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean); [DPI/Logical_imm.lean](external/LNSym/Arm/Insts/DPI/Logical_imm.lean) | Alias encodings |
| 0x1a | `CCMP_IMM` | missing | [Arm/Decode/DPR.lean](external/LNSym/Arm/Decode/DPR.lean); [Arm/Exec.lean](external/LNSym/Arm/Exec.lean) | Conditional compare absent |
| 0x1b | `CCMP_REG` | missing | [Arm/Decode/DPR.lean](external/LNSym/Arm/Decode/DPR.lean); [Arm/Exec.lean](external/LNSym/Arm/Exec.lean) | Conditional compare absent |
| 0x1c | `CSEL` | present | [DPR/Conditional_select.lean](external/LNSym/Arm/Insts/DPR/Conditional_select.lean) | CSEL plus CSINC/CSINV/CSNEG, legal S=0/op2[1]=0 |
| 0x1d | `CINC` | present | [DPR/Conditional_select.lean](external/LNSym/Arm/Insts/DPR/Conditional_select.lean) | CSINC/CSINV/CSNEG and aliases; 24 encoded W/X branch/ZR/wrap/frame checks pass |
| 0x1e | `CSET` | present | [DPR/Conditional_select.lean](external/LNSym/Arm/Insts/DPR/Conditional_select.lean) | CSINC/CSINV/CSNEG and aliases; 24 encoded W/X branch/ZR/wrap/frame checks pass |
| 0x1f | `LOAD` | partial | [LDST/Reg_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_imm.lean); [LDST/Reg_unscaled_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_unscaled_imm.lean) | Byte/word/double immediate exists; halfword GPR, GPR unscaled, pre-index and register-offset absent |
| 0x20 | `STORE` | partial | [LDST/Reg_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_imm.lean); [LDST/Reg_unscaled_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_unscaled_imm.lean) | Byte/word/double immediate exists; halfword GPR, GPR unscaled, pre-index and register-offset absent |
| 0x21 | `LDP` | partial | [LDST/Reg_pair.lean](external/LNSym/Arm/Insts/LDST/Reg_pair.lean) | Pre/post/offset exists; pair width, overlap, LSE2/fault profiles need audit |
| 0x22 | `STP` | partial | [LDST/Reg_pair.lean](external/LNSym/Arm/Insts/LDST/Reg_pair.lean) | Pre/post/offset exists; pair width, overlap, LSE2/fault profiles need audit |
| 0x23 | `FMOV` | partial | [DPSFP/Conversion_between_FP_and_Int.lean](external/LNSym/Arm/Insts/DPSFP/Conversion_between_FP_and_Int.lean) | FMOV GPR31 reads/writes SP via read_gpr/write_gpr; old reference uses XZR/WZR. Fix both directions, preserve SP |
| 0x24 | `CNT` | missing | [DPSFP/Advanced_simd_two_reg_misc.lean](external/LNSym/Arm/Insts/DPSFP/Advanced_simd_two_reg_misc.lean); [Arm/Exec.lean](external/LNSym/Arm/Exec.lean) | Only reversals in two-reg-misc; across-lanes class absent |
| 0x25 | `UADDLV` | missing | [DPSFP/Advanced_simd_two_reg_misc.lean](external/LNSym/Arm/Insts/DPSFP/Advanced_simd_two_reg_misc.lean); [Arm/Exec.lean](external/LNSym/Arm/Exec.lean) | Only reversals in two-reg-misc; across-lanes class absent |
| 0x26 | `ADRP_GOT` | layer | [DPI/PC_rel_addressing.lean](external/LNSym/Arm/Insts/DPI/PC_rel_addressing.lean) | ADRP exists; relocation/GOT/readonly resolution is linking premise |
| 0x27 | `ADRP_RODATA` | layer | [DPI/PC_rel_addressing.lean](external/LNSym/Arm/Insts/DPI/PC_rel_addressing.lean) | ADRP exists; relocation/GOT/readonly resolution is linking premise |
| 0x28 | `LOAD_D0` | partial | [LDST/Reg_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_imm.lean); [LDST/Reg_unscaled_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_unscaled_imm.lean) | SIMD immediate/unscaled exists; pre-index/register-offset absent |
| 0x29 | `STORE_D0` | partial | [LDST/Reg_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_imm.lean); [LDST/Reg_unscaled_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_unscaled_imm.lean) | SIMD immediate/unscaled exists; pre-index/register-offset absent |
| 0x2a | `LOAD_Q0` | partial | [LDST/Reg_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_imm.lean); [LDST/Reg_unscaled_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_unscaled_imm.lean) | SIMD immediate/unscaled exists; pre-index/register-offset absent |
| 0x2b | `STORE_Q0` | partial | [LDST/Reg_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_imm.lean); [LDST/Reg_unscaled_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_unscaled_imm.lean) | SIMD immediate/unscaled exists; pre-index/register-offset absent |
| 0x2c | `TST_BIC_REG` | present | [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean); [DPI/Logical_imm.lean](external/LNSym/Arm/Insts/DPI/Logical_imm.lean) | Alias encodings |
| 0x2d | `ANDS_REG` | present | [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean); [DPI/Logical_imm.lean](external/LNSym/Arm/Insts/DPI/Logical_imm.lean) | Alias encodings |
| 0x2e | `UMULH` | missing | [DPR/Data_processing_three_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_three_source.lean) | Only MADD executes; other valid forms explicitly Unimplemented |
| 0x2f | `SXTW` | present | [DPI/Bitfield.lean](external/LNSym/Arm/Insts/DPI/Bitfield.lean) | BFM/SBFM/UBFM and extension aliases |
| 0x30 | `SUBS_IMM` | present | [DPI/Add_sub_imm.lean](external/LNSym/Arm/Insts/DPI/Add_sub_imm.lean) | S/op/Rd encode CMP/CMN |
| 0x31 | `ADDS_IMM` | present | [DPI/Add_sub_imm.lean](external/LNSym/Arm/Insts/DPI/Add_sub_imm.lean) | S/op/Rd encode CMP/CMN |
| 0x32 | `SUBS_REG` | partial | [DPR/Add_sub_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_shifted_reg.lean); [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean) | Shifted forms exist; add/sub extended-register class absent |
| 0x33 | `CMN_IMM` | present | [DPI/Add_sub_imm.lean](external/LNSym/Arm/Insts/DPI/Add_sub_imm.lean) | S/op/Rd encode CMP/CMN |
| 0x34 | `CINV` | present | [DPR/Conditional_select.lean](external/LNSym/Arm/Insts/DPR/Conditional_select.lean) | CSINC/CSINV/CSNEG and aliases; 24 encoded W/X branch/ZR/wrap/frame checks pass |
| 0x35 | `ORN_REG` | present | [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean); [DPI/Logical_imm.lean](external/LNSym/Arm/Insts/DPI/Logical_imm.lean) | Alias encodings |
| 0x36 | `LDRSB` | missing | [LDST/Reg_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_imm.lean); [LDST/Reg_unscaled_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_unscaled_imm.lean) | Signed GPR loads absent |
| 0x37 | `ANDS_IMM` | present | [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean); [DPI/Logical_imm.lean](external/LNSym/Arm/Insts/DPI/Logical_imm.lean) | Alias encodings |
| 0x38 | `STLXR` | missing | [Arm/Decode/LDST.lean](external/LNSym/Arm/Decode/LDST.lean); [Arm/Exec.lean](external/LNSym/Arm/Exec.lean) | Exclusive class, monitor/outcome state absent; LDXR also needed |
| 0x39 | `LDRSW` | missing | [LDST/Reg_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_imm.lean); [LDST/Reg_unscaled_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_unscaled_imm.lean) | Signed GPR loads absent |
| 0x3a | `CMN_REG` | partial | [DPR/Add_sub_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_shifted_reg.lean); [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean) | Shifted forms exist; add/sub extended-register class absent |
| 0x3b | `UMADDL` | missing | [DPR/Data_processing_three_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_three_source.lean) | Only MADD executes; other valid forms explicitly Unimplemented |
| 0x3c | `SXTB` | present | [DPI/Bitfield.lean](external/LNSym/Arm/Insts/DPI/Bitfield.lean) | BFM/SBFM/UBFM and extension aliases |
| 0x3d | `CSINV` | present | [DPR/Conditional_select.lean](external/LNSym/Arm/Insts/DPR/Conditional_select.lean) | CSINC/CSINV/CSNEG and aliases; 24 encoded W/X branch/ZR/wrap/frame checks pass |
| 0x3e | `CSINC` | present | [DPR/Conditional_select.lean](external/LNSym/Arm/Insts/DPR/Conditional_select.lean) | CSINC/CSINV/CSNEG and aliases; 24 encoded W/X branch/ZR/wrap/frame checks pass |
| 0x3f | `LDRSH` | missing | [LDST/Reg_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_imm.lean); [LDST/Reg_unscaled_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_unscaled_imm.lean) | Signed GPR loads absent |
| 0x40 | `SMADDL` | missing | [DPR/Data_processing_three_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_three_source.lean) | Only MADD executes; other valid forms explicitly Unimplemented |
| 0x41 | `CNEG` | present | [DPR/Conditional_select.lean](external/LNSym/Arm/Insts/DPR/Conditional_select.lean) | CSINC/CSINV/CSNEG and aliases; 24 encoded W/X branch/ZR/wrap/frame checks pass |
| 0x42 | `ADDS_REG` | partial | [DPR/Add_sub_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_shifted_reg.lean); [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean) | Shifted forms exist; add/sub extended-register class absent |
| 0x43 | `BICS_REG` | present | [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean); [DPI/Logical_imm.lean](external/LNSym/Arm/Insts/DPI/Logical_imm.lean) | Alias encodings |
| 0x44 | `CSETM` | present | [DPR/Conditional_select.lean](external/LNSym/Arm/Insts/DPR/Conditional_select.lean) | CSINC/CSINV/CSNEG and aliases; 24 encoded W/X branch/ZR/wrap/frame checks pass |
| 0x45 | `CSNEG` | present | [DPR/Conditional_select.lean](external/LNSym/Arm/Insts/DPR/Conditional_select.lean) | CSINC/CSINV/CSNEG and aliases; 24 encoded W/X branch/ZR/wrap/frame checks pass |
| 0x46 | `LDADD` | missing | [Arm/Decode/LDST.lean](external/LNSym/Arm/Decode/LDST.lean); [Arm/Exec.lean](external/LNSym/Arm/Exec.lean) | LSE atomic RMW absent; include STADD/STSET/STCLR aliases |
| 0x47 | `LDSET` | missing | [Arm/Decode/LDST.lean](external/LNSym/Arm/Decode/LDST.lean); [Arm/Exec.lean](external/LNSym/Arm/Exec.lean) | LSE atomic RMW absent; include STADD/STSET/STCLR aliases |
| 0x48 | `LDCLR` | missing | [Arm/Decode/LDST.lean](external/LNSym/Arm/Decode/LDST.lean); [Arm/Exec.lean](external/LNSym/Arm/Exec.lean) | LSE atomic RMW absent; include STADD/STSET/STCLR aliases |
| 0xff | `RET` | present | [BR/Uncond_branch_reg.lean](external/LNSym/Arm/Insts/BR/Uncond_branch_reg.lean) | Only RET encoding accepted; BR/BLR absent |

Outside the 74-operation roster: LDXR; B/B.cond/CBZ/CBNZ/TBZ/TBNZ; MRS TPIDR_EL1/EL2; BR/BLR helper calls. Required by retained reference environment, not extra completed tokens.

### x86-64: 75 simulator operations

| Code | Operation | Source status | x86lean constructor | Constraint / work |
|---|---|---|---|---|
| 0x00 | `nop` | present | [nop](external/x86lean/X86/Syntax.lean) |  |
| 0x01 | `movImm` | present | [mov](external/x86lean/X86/Syntax.lean) |  |
| 0x02 | `movReg` | present | [mov](external/x86lean/X86/Syntax.lean) |  |
| 0x03 | `addImm` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x04 | `addReg` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x05 | `xorReg` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x06 | `movLoad` | present | [mov](external/x86lean/X86/Syntax.lean) |  |
| 0x07 | `movStoreImm` | present | [mov](external/x86lean/X86/Syntax.lean) |  |
| 0x08 | `movStoreReg` | present | [mov](external/x86lean/X86/Syntax.lean) |  |
| 0x09 | `lea` | present | [lea](external/x86lean/X86/Syntax.lean) |  |
| 0x0a | `aluImm` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x0b | `aluReg` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x0c | `cmpImm` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x0d | `cmpReg` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x0e | `testImm` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x0f | `testReg` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x10 | `jcc` | present | [jcc](external/x86lean/X86/Syntax.lean) |  |
| 0x11 | `jmp` | present | [jmp](external/x86lean/X86/Syntax.lean) |  |
| 0x12 | `push` | present | [push](external/x86lean/X86/Syntax.lean) |  |
| 0x13 | `pop` | present | [pop](external/x86lean/X86/Syntax.lean) |  |
| 0x14 | `call` | present | [call](external/x86lean/X86/Syntax.lean) | Native CALL; external ABI/effects separate |
| 0x15 | `cmov` | present | [cmov](external/x86lean/X86/Syntax.lean) | Read memory before condition test |
| 0x16 | `setcc` | present | [setcc](external/x86lean/X86/Syntax.lean) |  |
| 0x17 | `bswap` | present | [bswap](external/x86lean/X86/Syntax.lean) |  |
| 0x18 | `popcnt` | present | [bitcnt .popcnt](external/x86lean/X86/Syntax.lean) |  |
| 0x19 | `xchg` | present | [xchg](external/x86lean/X86/Syntax.lean) |  |
| 0x1a | `div` | present | [muldiv .div / .idiv](external/x86lean/X86/Syntax.lean) | Signed/unsigned subopcodes, all sizes |
| 0x1b | `shldImm` | present | [dshift](external/x86lean/X86/Syntax.lean) | 16-bit memory destination with masked count>16 explicitly stops as unimplemented; preserve actual register/memory domain |
| 0x1c | `shrdImm` | present | [dshift](external/x86lean/X86/Syntax.lean) | 16-bit memory destination with masked count>16 explicitly stops as unimplemented; preserve actual register/memory domain |
| 0x1d | `cmpMemImm` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x1e | `testMemImm` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x1f | `cmpMemReg` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x20 | `movzxReg` | present | [movx](external/x86lean/X86/Syntax.lean) |  |
| 0x21 | `movsxReg` | present | [movx](external/x86lean/X86/Syntax.lean) |  |
| 0x22 | `movsxLoad` | present | [movx](external/x86lean/X86/Syntax.lean) |  |
| 0x23 | `aluMem` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x24 | `cmpRegMem` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x25 | `movLoadScalar` | present | [mov](external/x86lean/X86/Syntax.lean) |  |
| 0x26 | `shiftx` | present | [shiftx](external/x86lean/X86/Syntax.lean) |  |
| 0x27 | `rorx` | present | [rorx](external/x86lean/X86/Syntax.lean) |  |
| 0x28 | `movbeLoad` | present | [movbe](external/x86lean/X86/Syntax.lean) |  |
| 0x29 | `movbeStore` | present | [movbe](external/x86lean/X86/Syntax.lean) |  |
| 0x2a | `shiftxMem` | present | [shiftx](external/x86lean/X86/Syntax.lean) |  |
| 0x2b | `rorxMem` | present | [rorx](external/x86lean/X86/Syntax.lean) |  |
| 0x2c | `movLoadMapPtr` | layer | [mov / call](external/x86lean/X86/Syntax.lean) | Symbol/helper resolution or library effects belong to decoded-sequence/ABI relation |
| 0x2d | `movLoadHelperId` | layer | [mov / call](external/x86lean/X86/Syntax.lean) | Symbol/helper resolution or library effects belong to decoded-sequence/ABI relation |
| 0x2e | `callHelper` | layer | [mov / call](external/x86lean/X86/Syntax.lean) | Symbol/helper resolution or library effects belong to decoded-sequence/ABI relation |
| 0x2f | `callReg` | present | [call](external/x86lean/X86/Syntax.lean) | Native CALL; external ABI/effects separate |
| 0x30 | `loadXmm0` | present | [vload/vstore; vloadq/vstoreq](external/x86lean/X86/Syntax.lean) | Retain actual D/Q width, alignment, scalar upper bits |
| 0x31 | `storeXmm0` | present | [vload/vstore; vloadq/vstoreq](external/x86lean/X86/Syntax.lean) | Retain actual D/Q width, alignment, scalar upper bits |
| 0x32 | `aluMemUnary` | present | [un / shift](external/x86lean/X86/Syntax.lean) |  |
| 0x33 | `aluMemImm` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x34 | `bzhi` | present | [bzhi](external/x86lean/X86/Syntax.lean) | Already implemented30c9b2e: Value.bzhi, Flags.bzhi, step_bzhi_cf and bzhi_index_past; coverage T-frame, x86isa refuses |
| 0x35 | `bzhiMem` | present | [bzhi](external/x86lean/X86/Syntax.lean) | Already implemented30c9b2e: Value.bzhi, Flags.bzhi, step_bzhi_cf and bzhi_index_past; coverage T-frame, x86isa refuses |
| 0x36 | `aluMemReg` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x37 | `bt` | present | [bit .bt](external/x86lean/X86/Syntax.lean) |  |
| 0x38 | `imulImm` | present | [imulr](external/x86lean/X86/Syntax.lean) |  |
| 0x39 | `mulx` | present | [mulx](external/x86lean/X86/Syntax.lean) |  |
| 0x3a | `repMovs` | present | [repstrop .rep .movs](external/x86lean/X86/Syntax.lean) | Rep semantics and fault-prefix transport remain explicit |
| 0x3b | `testMemReg` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x3c | `callMemset` | layer | [mov / call](external/x86lean/X86/Syntax.lean) | Symbol/helper resolution or library effects belong to decoded-sequence/ABI relation |
| 0x3d | `andn` | present | [andn](external/x86lean/X86/Syntax.lean) |  |
| 0x3e | `setccMem` | present | [setcc](external/x86lean/X86/Syntax.lean) |  |
| 0x3f | `callMemcpy` | layer | [mov / call](external/x86lean/X86/Syntax.lean) | Symbol/helper resolution or library effects belong to decoded-sequence/ABI relation |
| 0x40 | `cmovMem` | present | [cmov](external/x86lean/X86/Syntax.lean) | Read memory before condition test |
| 0x41 | `imulMemImm` | present | [imulr](external/x86lean/X86/Syntax.lean) |  |
| 0x42 | `btImm` | present | [bit .bt](external/x86lean/X86/Syntax.lean) |  |
| 0x43 | `btMemImm` | present | [bit .bt](external/x86lean/X86/Syntax.lean) |  |
| 0x44 | `andnMem` | present | [andn](external/x86lean/X86/Syntax.lean) |  |
| 0x45 | `callMemsetReg` | layer | [mov / call](external/x86lean/X86/Syntax.lean) | Symbol/helper resolution or library effects belong to decoded-sequence/ABI relation |
| 0x46 | `callMemcpyReg` | layer | [mov / call](external/x86lean/X86/Syntax.lean) | Symbol/helper resolution or library effects belong to decoded-sequence/ABI relation |
| 0x47 | `popcntMem` | present | [bitcnt .popcnt](external/x86lean/X86/Syntax.lean) |  |
| 0x48 | `ror` | present | [rot .ror](external/x86lean/X86/Syntax.lean) |  |
| 0x49 | `rorMem` | present | [rot .ror](external/x86lean/X86/Syntax.lean) |  |
| 0xff | `ret` | present | [ret](external/x86lean/X86/Syntax.lean) | Native stack pop; simulator return modes need relation |

Cross-cutting gaps: X86.Mem is a finite byte association list with implicit zero background, total reads/writes, no access-permission faults. Cpu has no 48/57-bit canonical-address profile. LNSym also uses total byte memory, without the retained permission/initialized/event/fault-prefix contract, exclusive monitor or thread-pointer inputs. These are not closed by listing instruction constructors; M2/M3 must preserve the existing theorem domains through external-model extensions and explicit relations. x86lean takes post-decode Instr.op/len. BZHI is absent from the differential roster, not absent from step: do not duplicate its semantics.

## Legacy foundation (migration pending)

Safety uses two facts: the stock verifier accepts B, and B faithfully simulates
P. This directory proves generic simulator and token laws; native-link
preservation lives in [tv/](../tv/). The current
[coverage ledger](../results/kprog_verification_20261107/README.md) records every
operation/token, its exact theorem domain, replay source epoch and remaining
implementation interface. It currently records71 x86-64 complete current C-model token-body equalities and73 of74
AArch64 operation bodies, plus an explicit current RET exit-contract interface
and two returning-helper interface equalities. LDADD/STADD0x46, LDSET/STSET0x47 and LDCLR/STCLR0x48 share canonical atomic access, typed success laws and unified token bindings. Additional helper macro-routing and two-mode RET control laws retain their
parametric/source bindings and do not increase the71 complete current x86 bodies.
Full ISA and compiled-simulator closure remain active work. The production DIV signed AUX1 branch has its canonical signed reference and554 semantic scenes. Signed/unsigned AUXbit0 dispatch and arbitrary fresh flags compose through the generic step/token laws. The current signed DIV raw/tag body directly executes all four widths of word arithmetic, the complete restoring loop/zero-high fast path, word-limit comparison and unsigned sign restoration, composing captured operands and whole state/fresh flags through current dispatcher/O2 laws. Both unsigned and signed domains now meet the concrete C-model token category used by the other complete rows. C-source extraction, compiled-B and physical/ABI transport remain explicit interfaces.

`X86RemainingTokenO2.StackRelease` adds seventeen universal component laws for
internal RET lifetime: ordered fresh-byte writes over the released signed
interval, clearing every declared below-SP word tag/valid field, preserving
pointer/scalar payloads and live cells, pre-release saved-word capture and
selected/default token transport. Sparse declared-word lists and arbitrary fresh
bytes are quantified. Source owned-read/forwarding, signed-coordinate validity,
live-stack/native-memory representation and compiler/physical transport remain
explicit interfaces; RET retains its partial category.

Nine additional owned-read laws cover full64 scalar forwarding, unaligned byte
assembly, saved-word projection, live-read preservation and byte reads after
reallocation. Source byte/scalar coherence supplies the saved-read premise;
computed index, union memory and physical/compiler transport retain their
explicit source profile.

Twelve source-coordinate/coherence laws connect the actual wrapping generated
stack index, signed raw-SP coordinate and native byte addresses. An allocated
eight-byte return interval derives exact signed RSP advance and supplies the
source read projection. The live byte/scalar relation survives release and
composes current source RET with the reference step and selected/default token.
C/compiler establishment of that relation, producer mode and physical control
transport remain explicit interfaces.

`ControlABI.ArmReturn` adds twelve current ARM RET component laws: raw target
decides RETURN-tag invocation or CODE-tag finite continuation/default, with
complete scratch capture and tag-aware X0 numeric materialization. Internal
branches refine the reference branch step in the stated numeric image, and
outer source callee/SP guards derive the native ABI contract. Actual producer
operand/table extraction and physical LR/code-PC/compiler transport remain
explicit; ARM RET retains its partial category.

Actual compiled scalar coverage is16 of75 x86 operations across158 combined
units, including two partial returning-helper units. Classic ROR adds five
width/lane units with arbitrary values, counts and fresh inputs; actual BPF
execution preserves memory/exclusive state and consumes the23 captured input
positions. Whole flags/tag/frame and physical/compiler embedding retain their
explicit simulator interfaces.

ADD_IMM contributes five actual scalar units for8-bit low/high lanes and16/32/64-bit
writeback, with the encoded imm32 sign extension at64-bit width. Seven execution
laws quantify every operand, immediate, fresh stream and initial visit, preserving
memory/exclusive state, consuming23 inputs and reaching the stated result.
The complete flags/tag/register frame and physical/compiler embedding remain
explicit interfaces.

ADD_REG adds seven actual scalar units: all four low/high byte-lane pairs and
16/32/64-bit writeback. Nine execution laws quantify every operand and fresh
stream and preserve memory/exclusive state with23 consumed inputs. Complete
flags/tag/GPR-frame, operand mapping and physical/compiler transport remain
explicit interfaces.

x86 raw handler/dispatcher refinement covers34/75 operations. JCC/JMP now
retain the full raw GPR/tag/flags/memory frame and select PC through generated
source shapes and a native label map. Source ordering and native address
ordering can differ. Ten control laws compile with module/root0 and sorryAx0;
the existing entry image and native/source/physical/compiler interfaces retain
their domains.

ARM raw handler/dispatcher refinement covers58/74 operations: immediate moves,
multiply/divide, shift/unary, ORN, extract/reverse/extension, conditional select,
bitfields, conditional compare, logical flags, arithmetic flags, MOV_REG, resolved GOT/RODATA addresses, CNT/UADDLV vector reductions, ADD/SUB immediate aliases, shared ALU tokens and FMOV.
One hundred and ninety-four laws audit and compile with module/root0 and sorryAx0. All raw64-bit
words, byte tags, STACK4/RETURN10 materialization, register aliases/XZR and the
complete architectural image compose through one58-operation emission step theorem.
CSEL/X retains its selected raw word/tag; scalar results use width/scalar-tag
writes. CNT/UADDLV capture both input halves and retain the complete raw GPR/tag,
SP, flags, memory, exclusive and other vector-bank frame. FMOV covers all32 vector banks and four directions, full raw/tag materialization,
vector high-half clearing and scalar-tag GPR width writes. Their token laws cover
all ignored fields; the current scalar producer policy retains its own domain. The six ALU selectors cover the arithmetic and logical domains of ALU_IMM/REG:
source provenance derives from captured tags, pointer increments commute with
materialization, and SP32/STACK writes retain their relative coordinates.
Native shifts/extensions and immediate aliases share the production dispatcher. STACK ORR transports its low-bit update through an explicitly aligned entry
stack origin; preceding emission bindings retain their origin domains. CCMP updates NZCV and preserves its complete raw GPR/tag frame. ANDS/BICS scalarize their destination; TST preserves the full raw tag map. ADDS/SUBS/CMP/CMN retain SP32-source materialization, shifted/extended operands and the full compare-only frame. MOV retains full raw/tag copies and SP coordinate writes; address writes retain generated GOT7/RODATA8 tags and resolved-IMM identities. SHIFT and conditions consume the actual whole AUX, while unary uses
AUX byte1/byte2. Native widths, amount/alias domains and NV normalization stay
explicit. The ledger retains production dispatcher equalities and arbitrary
unused-field domains. Entry origin identity, C extraction/union and physical/
compiler transport remain interfaces independent of B forwarding storage. Six
additional source-emitted branch families (B/B.cond/CBZ/CBNZ/TBZ/TBNZ) compose
with these58 numeric operations through one source-emission step theorem.
Source/current/next/target label-to-native-address identities stay explicit;
NZCV/value/bit tests derive the outcome and preserve the entire data/tag frame.
Their source-operation/token rows retain a separate6/6 raw count.


## Specification and proof scope

The reference ISA is defined once in
[Reference/X86.lean](KProgFormal/Reference/X86.lean) and
[Reference/AArch64.lean](KProgFormal/Reference/AArch64.lean), with shared
[memory, permissions, initialization and ordered effects/faults](KProgFormal/Reference/Memory.lean).
These definitions cite Intel/Arm sources and are independent of generated
implementation contracts. [ReferenceMain.lean](ReferenceMain.lean) executes
these same definitions through JSON for hardware and artifact comparisons.
The [Arm ASL state comparison](../results/kprog_verification_20261107/reference-arm-asl.md)
records5016 agreeing observations across74 operation labels and explicit STLXR
monitor profiles. LDADD adds1344 agreeing cases and stated atomic/compiler premises. It retains its source/binary
identities and platform premises alongside the [x86 Sail comparison](../results/kprog_verification_20261107/reference-x86-sail.md),
which, together with the [direct ACL2 comparison](../results/kprog_verification_20261107/reference-x86-acl2.md),
records63 agreeing operation labels and four ANDN/BZHI model-stopped labels
in the current selected comparison. Historical source epochs retain their observations. ACL28.7 retains72 memory-SHIFTX PC-1 observations
with matching GPR/flags/XMM/memory, plus48 REP element/whole-step differences.
Original source/certificate diagnostics and separate CPU evidence remain recorded.

Handler/dispatcher and specialized-token laws compose modeled registers,
PC, ordered memory effects, faults and defined architectural outputs under
their stated operand, address, access and platform premises. Undefined outputs
use the reference step's observation mask; uninitialized memory has arbitrary
values. The theorem statements and coverage rows give each operation's domain.
FreshAux composes the production ANDN/BZHI independent PF/AF choices, proves
complete local output realization and transports a two-position fresh stream.
Global incoming-state/other undefined-output and compiler/ABI transport remain
explicit interfaces.
The x86 pointer bodies share the extended dispatcher and refine resolved moves
for all sixteen registers, including the RSP coordinate. Native symbol/helper
address transport remains an explicit interface. Four memory-call token bodies
include sequential byte effects and the fresh caller-clobber frame; their
native call/ABI and physical memory relations remain explicit. Two helper token
wrappers prove full64-bit sparse ID routing, pre-call capture, result/memory/events
and fresh caller/callee-frame laws over a returning helper-effect interface;
typed arguments, native ABI and successful tail transfer remain explicit. Internal RET includes a total label/unresolved continuation result, with
complete captured read/SP advance in both alternatives. O2 covers its default;
O4 carries CALL -1 decode/error semantics and derives case membership for
accepted entered states under explicit compiled-edge/stock rejection premises.
The shared architectural-fault prefix also has actual byte decode/execution
and a complete scratch/memory/ghost frame at every linked instruction offset,
under literal-copy, entry/reachability, NULL-unmapped and verifier premises.
Actual returning BPF CALL laws also retain the pre-call argument snapshot,
full-width resolved identity, result/memory/effects and caller/callee/ghost frame
through identity-preserving resolution; physical/native ABI and C/compiler
correspondence remain explicit.
The existing x86/ARM callee-tag/value/SP exit predicates now derive the
quantified ABI contract and exact normal-return value/frame. The x86 RET-token
guard and native-return/JIT-result laws compose this contract under explicit
snapshot, stack-origin and tag-projection inputs. Internal return stack erasure,
ARM return-mode/LR binding, native-to-B entry and C/compiler/physical transport
remain explicit.

Architectural profiles are stated in the reference and theorem premises:
x86 near control uses 48/57-bit canonical addresses with CET disabled, and
LEAVE uses the LASS-disabled frame profile. ARM uses the Cortex-A72 base
profile with explicit SP alignment, pair-access granularity and exclusive
monitor/order inputs. Each dynamic exclusive attempt receives its own
possible failure outcome. Concurrent memory behavior retains its physical
profile obligations. The safety argument uses generic simulator, token and
link-transformation theorems; historical per-program artifacts stay frozen.

The typed byte atomic kfunc C model now composes ADD/SET/CLR operand truncation,
old-value return and one-byte state commit through the unified dispatcher.
Primitive ordering, kfunc identity/call ABI and compiler transport remain explicit.

The read-only helper return also composes its valid-cell stack-tag map with the
full return observation. Its index origin and signed below-SP policy are proved;
physical frame ownership, helper effects/provenance and ABI remain explicit.

## Trusted boundary

The boundary includes Lean's kernel/toolchain and executable reduction bridge
(`Lean.ofReduceBool`), contract generation and C/Lean correspondence, native
decoding/encoding, and the C/BPF compilation path. Entry ABI, physical
memory/provenance, exclusive monitor/order/site identity and native address
transport are caller/platform interfaces. The ledger distinguishes proved
model laws, finite oracle/hardware evidence and complete-check outcomes.
The generic readonly finite-case law also composes object identity and shifted
aliases with canonical memory reads; final byte transfer transports its frozen
image premise. Every permitted canonical guest write preserves the frozen
image and its write permissions. Physical symbol/map lifetime, helper/platform
state effects and C/compiler transport stay explicit.
The private-spill projection also proves actual decoded STXDW/LDXDW pair execution,
whole BPF register/input-frame and public-memory preservation, and exact owned
event erasure for every signed16-bit offset. Finite disjoint-write histories
preserve the saved read; actual decoded spill/arbitrary finite body/reload
composition restores the captured word and preserves the other body state
and ordered projected trace. Actual compiler ownership/layout, body control
and slot/frame liveness plus physical frame/ABI correspondence remain explicit.
[Composition](../tv/Composition.lean) and the
[artifact work](../tv/README.md) track the generic link/compiler obligations.

The existing X86StackIndex module also proves inactive stack-ghost payload
initialization/replacement is erased through finite save/invalidate/frame/clear
histories and complete lookup traversals, retaining active STACK pointers.
This metadata C-model law leaves C definedness and compiler/physical ABI explicit.

Arm64NumericAddress also proves sparse tag-table store/clear/copy preservation
under explicit initial-support and producer-domain coverage premises, plus
packed-word whole-byte-table store refinement. Actual CFG producer soundness
and C/clang storage correspondence remain explicit interfaces.

## Run

```sh
make -C kprog/formal check
```

Use an x86-64 Linux host with BMI1/BMI2 and POPCNT, Lean/Elan, Python3,
Rust/Cargo, a C compiler with UBSan, clang 18/LLVM 18, GNU objdump,
AArch64 cross-GCC, QEMU user emulation, and the vendor/libbpf and
vendor/linux-framework submodules. This entry point builds all Lean modules,
checks generated contracts and proof hygiene, and runs retained semantic C
oracles and executable-reference comparisons. The existing compiled CMOV unit covers all16 conditions and16/32/64 widths
through decoded clang bytes, arbitrary fresh inputs and whole-memory preservation;
The same fixture proves all32 SETCC condition/low-high-byte units and their actual
decoded executions, with arbitrary old value/flags/fresh inputs and whole-memory preservation;
BSWAP adds both32/64-bit widths with complete arbitrary BPF register/memory/ghost-frame
preservation and actual decoded executions. Their scalar-register mapping,
initial scratch state and invocation interface remain explicit. MOV_REG adds7 scalar byte-lane/width units with arbitrary whole memory and both
ghost indices; pointer/RSP frame and physical ABI embedding remain explicit.
MOVZX/MOVSX add15 scalar source-lane/width units with canonical extension,
whole memory and both ghost indices; register/tag frame and ABI embedding
remain explicit.
SHIFTX adds6 scalar width/count units with arbitrary counts and both SARX
control paths; complete register/flag/tag frame and ABI embedding remain
explicit.
UD2 adds exact0f0b decode and an unchanged-state #UD terminal, plus the
actual shared architectural-fault byte prefix and generic O2/O4 transport.
Its12 ACL2 observations retain the explicit model RIP+2 profile difference.
Compiler/link/entered-state and stock-soundness premises remain explicit.
ANDN adds2 scalar width/writeback units with width32 zero extension;
flags/native-frame/physical ABI embedding remain explicit.
Two returning helper scalar units (lookup1/ktime5) retain argument/result,
complete helper memory/effects and independent clobbers under a matched platform
contract; full helper registry/tag/frame/native ABI/compiler transport remains
explicit. These are partial helper-body units, not a completed token family.
RORX adds2 scalar width/writeback units with width32 zero extension;
flags/native-frame/physical ABI embedding remain explicit.
MOV_IMM adds5 scalar width/writeback units with width32 zero extension;
flags/native-frame/physical ABI embedding remain explicit.
BZHI adds2 scalar width/writeback units with width32 zero extension;
flags/native-frame/physical ABI embedding remain explicit.
POPCNT adds3 scalar width/writeback units, with high48 preservation at16
bits and zero extension at32 bits; full flags/register/tag frame and ABI
embedding remain explicit.
Existing build caches are reused. Generator checks compare locked numeric contracts
and generated artifacts; compiled oracles exercise the current production bodies.
The dated ledger retains exact source hashes, commands and original outcomes.

Caller-owned helper frames preserve exact saved reads through disjoint memory
effects; actual returning BPF CALL/LDXDW Execution retains the full helper/read
trace. Selected helper footprint, pointer lifetime and native ABI stay explicit.

Native x86 CALL/RET laws account for the actual RSP-8 return-slot write,
separate caller and return-slot footprints, saved PC and unsigned SP release.
Selected native helper stack restoration and physical native-to-B ABI remain explicit.

Conditional scalar read-recovery laws above the raw ISA account for stock-frame
x86/ARM zero-and-resume, including nativeX5/XZR and the raw fault prefix.
Actual site/table/exception-class/B-observation and O3 correspondence stay open.

x86 exception-table encoding also composes saved-GPR offsets, fixup fields and
relative final-PC entries with whole-register/PC recovery. Actual frame/site/table
lifetime and B/physical fault correspondence remain explicit.

ARM native-marker and paired-register fields likewise compose with whole-X/PC4
recovery, X5/XZR semantics and the actual raw fault state. Production site/frame
and B ordered-prefix correspondence remain explicit.

BPFPlatform also models seven kernel-internal nonarena PROBE_MEM/SX load
codes with full success/fault/frame and decoded-step laws. Actual conversion,
physical guard and O3/native fault-prefix correspondence remain explicit.

## Layout

- [Reference/](KProgFormal/Reference/): canonical ISA and memory specifications.
- [contracts/](contracts/), [generated/](generated/) and
  [Generated/](KProgFormal/Generated/): JSON inputs and generated C/Lean contracts.
- [KProgFormal/](KProgFormal/) and [Refinement/](KProgFormal/Refinement/):
  primitives, full-state refinements, dispatcher/token and environment laws.
- [oracles/](oracles/): retained semantic C oracles.
- [tools/](tools/): generators and semantic tooling.
  build/ and .lake/ hold incremental outputs.

Canonical ARM LDP recovery also proves first-element, second-element and
FEAT_LSE2 double-width fault paths, retaining ordered read events and clearing
both whole X destinations from the input frame before PC4 continuation.
Physical site/frame, pre/post writeback and compiled-B/O3 bindings remain explicit.

Kind4 per-CPU final-byte laws compose the selected entered thread-pointer
profile with canonical X10 materialization, preserving the full state and
empty trace through the final copied word. Physical CPU/profile and C/compiler
entry/copy/lifetime bindings remain explicit.

LEA adds12 scalar width/scale units with canonical writeValue, complete memory
and exclusive-index preservation and actual decoded execution. Field/address
mapping, pointer/RSP and physical native frame/compiler embedding remain explicit.
The current lookup1/ktime5 units include their decoded private byte store at
R10-8: the full execution has exact scratch memory and ordered store event,
under explicit successful-store/slot ownership premises. Prefix and suffix
composition retains the complete helper result and effects.
