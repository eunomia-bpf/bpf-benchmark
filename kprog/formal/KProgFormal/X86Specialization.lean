import KProgFormal.GeneratedX86Specialization

namespace KProgFormal

open GeneratedX86Specialization

/-- The `X86_OP_*` spelling of a generated token. -/
def x86SpecToken : GeneratedX86Specialization.Op -> String :=
  GeneratedX86Specialization.tokenName

/-- Drop a trailing `_AUX` or `_STEP` spelling suffix. -/
def stripSuffix (s : String) : String :=
  if s.endsWith "_AUX" then s.dropRight 4
  else if s.endsWith "_STEP" then s.dropRight 5
  else s

/-- Every token the chain and the encoder both serve selects the same
specialized body: the chain handler, the encoder's aux-0 macro and its aux-gated
override agree once the `_AUX`/`_STEP` spelling suffixes are dropped. This is
the no-insertion property O2 requires of the specialized dispatch. -/
def noInsertion : List (String × Dispatch × String × String × String) -> Bool
  | [] => true
  | row :: rest =>
      let chain := stripSuffix row.2.2.1
      let direct := stripSuffix row.2.2.2.1
      let aux := stripSuffix row.2.2.2.2
      (chain = "" || direct = "" || chain = direct) ∧
      (aux = "" || chain = "" || aux = chain || aux = direct) ∧
      noInsertion rest

/-- Independent enumeration of the x86-64 specialization dispatch, written as
explicit token/class/macro tuples so it does not reuse the generated table. The
tuples are in the order `kprog/x86/x86_sim.h` defines the tokens.

Each tuple is `(token, encoder dispatch class, the `X86_SIM_L_EXEC` handler the
token's chain arm calls, the specialized macro the encoder emits at aux 0, the
aux-gated override for nonzero aux)`; `""` marks an absent handler or macro. -/
def x86SpecSpec : List (String × Dispatch × String × String × String) := [
  ("X86_OP_NOP", .genericRunOp, "", "", ""),
  ("X86_OP_MOV_IMM", .directMacro, "", "X86_SIM_L_EXEC_MOV_IMM", "X86_SIM_L_EXEC_MOV_IMM_AUX"),
  ("X86_OP_MOV_REG", .directMacro, "", "X86_SIM_L_EXEC_MOV_REG", "X86_SIM_L_EXEC_MOV_REG_AUX"),
  ("X86_OP_ADD_IMM", .directMacro, "X86_SIM_L_EXEC_ALU_IMM", "X86_SIM_L_EXEC_ALU_IMM", ""),
  ("X86_OP_ADD_REG", .directMacro, "X86_SIM_L_EXEC_ALU_REG", "X86_SIM_L_EXEC_ALU_REG", ""),
  ("X86_OP_XOR_REG", .directMacro, "X86_SIM_L_EXEC_ALU_REG", "X86_SIM_L_EXEC_ALU_REG", ""),
  ("X86_OP_MOV_LOAD", .directMacro, "X86_SIM_L_EXEC_MOV_LOAD", "X86_SIM_L_EXEC_MOV_LOAD", ""),
  ("X86_OP_MOV_STORE_IMM", .directMacro, "X86_SIM_L_EXEC_STORE", "X86_SIM_L_EXEC_STORE", ""),
  ("X86_OP_MOV_STORE_REG", .directMacro, "X86_SIM_L_EXEC_STORE", "X86_SIM_L_EXEC_STORE", ""),
  ("X86_OP_LEA", .directMacro, "X86_SIM_L_EXEC_LEA", "X86_SIM_L_EXEC_LEA", ""),
  ("X86_OP_ALU_IMM", .directMacro, "X86_SIM_L_EXEC_ALU_IMM", "X86_SIM_L_EXEC_ALU_IMM", ""),
  ("X86_OP_ALU_REG", .directMacro, "X86_SIM_L_EXEC_ALU_REG", "X86_SIM_L_EXEC_ALU_REG", ""),
  ("X86_OP_CMP_IMM", .directMacro, "X86_SIM_L_EXEC_CMP_IMM_OP_AUX", "X86_SIM_L_EXEC_CMP_IMM_OP", "X86_SIM_L_EXEC_CMP_IMM_OP_AUX"),
  ("X86_OP_CMP_REG", .directMacro, "X86_SIM_L_EXEC_CMP_REG_OP_AUX", "X86_SIM_L_EXEC_CMP_REG_OP", "X86_SIM_L_EXEC_CMP_REG_OP_AUX"),
  ("X86_OP_TEST_IMM", .directMacro, "X86_SIM_L_EXEC_CMP_IMM_OP_AUX", "X86_SIM_L_EXEC_CMP_IMM_OP", "X86_SIM_L_EXEC_CMP_IMM_OP_AUX"),
  ("X86_OP_TEST_REG", .directMacro, "X86_SIM_L_EXEC_CMP_REG_OP_AUX", "X86_SIM_L_EXEC_CMP_REG_OP", "X86_SIM_L_EXEC_CMP_REG_OP_AUX"),
  ("X86_OP_JCC", .branchHandler, "", "", ""),
  ("X86_OP_JMP", .branchHandler, "", "", ""),
  ("X86_OP_PUSH", .directMacro, "X86_SIM_L_EXEC_PUSH", "X86_SIM_L_EXEC_PUSH", ""),
  ("X86_OP_POP", .directMacro, "X86_SIM_L_EXEC_POP", "X86_SIM_L_EXEC_POP", ""),
  ("X86_OP_CALL", .branchHandler, "", "", ""),
  ("X86_OP_CMOV", .directMacro, "X86_SIM_L_EXEC_CMOV", "X86_SIM_L_EXEC_CMOV", ""),
  ("X86_OP_SETCC", .directMacro, "X86_SIM_L_EXEC_SETCC_STEP", "X86_SIM_L_EXEC_SETCC", ""),
  ("X86_OP_BSWAP", .genericRunOp, "", "", ""),
  ("X86_OP_POPCNT", .genericRunOp, "", "", ""),
  ("X86_OP_XCHG", .genericRunOp, "", "", ""),
  ("X86_OP_DIV", .genericRunOp, "", "", ""),
  ("X86_OP_SHLD_IMM", .genericRunOp, "", "", ""),
  ("X86_OP_SHRD_IMM", .genericRunOp, "", "", ""),
  ("X86_OP_CMP_MEM_IMM", .directMacro, "X86_SIM_L_EXEC_CMP_MEM", "X86_SIM_L_EXEC_CMP_MEM", ""),
  ("X86_OP_TEST_MEM_IMM", .directMacro, "X86_SIM_L_EXEC_CMP_MEM", "X86_SIM_L_EXEC_CMP_MEM", ""),
  ("X86_OP_CMP_MEM_REG", .directMacro, "X86_SIM_L_EXEC_CMP_MEM", "X86_SIM_L_EXEC_CMP_MEM", ""),
  ("X86_OP_MOVZX_REG", .directMacro, "", "X86_SIM_L_EXEC_MOVX_REG", ""),
  ("X86_OP_MOVSX_REG", .directMacro, "", "X86_SIM_L_EXEC_MOVX_REG", ""),
  ("X86_OP_MOVSX_LOAD", .directMacro, "X86_SIM_L_EXEC_MOV_LOAD", "X86_SIM_L_EXEC_MOV_LOAD", ""),
  ("X86_OP_ALU_MEM", .directMacro, "X86_SIM_L_EXEC_ALU_MEM", "X86_SIM_L_EXEC_ALU_MEM", ""),
  ("X86_OP_CMP_REG_MEM", .directMacro, "X86_SIM_L_EXEC_CMP_REG_MEM", "X86_SIM_L_EXEC_CMP_REG_MEM", ""),
  ("X86_OP_MOV_LOAD_SCALAR", .directMacro, "X86_SIM_L_EXEC_MOV_LOAD", "X86_SIM_L_EXEC_MOV_LOAD", ""),
  ("X86_OP_SHIFTX", .genericRunOp, "", "", ""),
  ("X86_OP_RORX", .genericRunOp, "", "", ""),
  ("X86_OP_MOVBE_LOAD", .genericRunOp, "X86_SIM_L_EXEC_MOVBE_LOAD", "", ""),
  ("X86_OP_MOVBE_STORE", .genericRunOp, "X86_SIM_L_EXEC_MOVBE_STORE", "", ""),
  ("X86_OP_SHIFTX_MEM", .genericRunOp, "", "", ""),
  ("X86_OP_RORX_MEM", .genericRunOp, "", "", ""),
  ("X86_OP_MOV_LOAD_MAP_PTR", .genericRunOp, "", "", ""),
  ("X86_OP_MOV_LOAD_HELPER_ID", .genericRunOp, "", "", ""),
  ("X86_OP_CALL_HELPER", .directMacro, "", "X86_SIM_BPF_CALL_ID", ""),
  ("X86_OP_CALL_REG", .directMacro, "X86_SIM_BPF_CALL_REG", "X86_SIM_BPF_CALL_REG", ""),
  ("X86_OP_LOAD_XMM0", .genericRunOp, "X86_SIM_L_EXEC_LOAD_XMM0", "", ""),
  ("X86_OP_STORE_XMM0", .genericRunOp, "X86_SIM_L_EXEC_STORE_XMM0", "", ""),
  ("X86_OP_ALU_MEM_UNARY", .directMacro, "X86_SIM_L_EXEC_ALU_MEM_UNARY", "X86_SIM_L_EXEC_ALU_MEM_UNARY", ""),
  ("X86_OP_ALU_MEM_IMM", .directMacro, "X86_SIM_L_EXEC_ALU_MEM_IMM", "X86_SIM_L_EXEC_ALU_MEM_IMM", ""),
  ("X86_OP_BZHI", .genericRunOp, "X86_SIM_L_EXEC_BZHI", "", ""),
  ("X86_OP_BZHI_MEM", .genericRunOp, "X86_SIM_L_EXEC_BZHI_MEM", "", ""),
  ("X86_OP_ALU_MEM_REG", .directMacro, "X86_SIM_L_EXEC_ALU_MEM_REG", "X86_SIM_L_EXEC_ALU_MEM_REG", ""),
  ("X86_OP_BT", .directMacro, "X86_SIM_L_EXEC_BT", "X86_SIM_L_EXEC_BT", ""),
  ("X86_OP_IMUL_IMM", .directMacro, "X86_SIM_L_EXEC_IMUL_IMM", "X86_SIM_L_EXEC_IMUL_IMM", ""),
  ("X86_OP_MULX", .directMacro, "X86_SIM_L_EXEC_MULX", "X86_SIM_L_EXEC_MULX", ""),
  ("X86_OP_REP_MOVS", .directMacro, "X86_SIM_L_EXEC_REP_MOVS", "X86_SIM_L_EXEC_REP_MOVS", ""),
  ("X86_OP_TEST_MEM_REG", .directMacro, "X86_SIM_L_EXEC_CMP_MEM", "X86_SIM_L_EXEC_CMP_MEM", ""),
  ("X86_OP_CALL_MEMSET", .directMacro, "X86_SIM_L_EXEC_CALL_MEMSET", "X86_SIM_L_EXEC_CALL_MEMSET", ""),
  ("X86_OP_ANDN", .directMacro, "X86_SIM_L_EXEC_ANDN", "X86_SIM_L_EXEC_ANDN", ""),
  ("X86_OP_SETCC_MEM", .directMacro, "X86_SIM_L_EXEC_SETCC_MEM", "X86_SIM_L_EXEC_SETCC_MEM", ""),
  ("X86_OP_CALL_MEMCPY", .directMacro, "X86_SIM_L_EXEC_CALL_MEMCPY", "X86_SIM_L_EXEC_CALL_MEMCPY", ""),
  ("X86_OP_CMOV_MEM", .directMacro, "X86_SIM_L_EXEC_CMOV_MEM", "X86_SIM_L_EXEC_CMOV_MEM", ""),
  ("X86_OP_IMUL_MEM_IMM", .directMacro, "X86_SIM_L_EXEC_IMUL_MEM_IMM", "X86_SIM_L_EXEC_IMUL_MEM_IMM", ""),
  ("X86_OP_BT_IMM", .directMacro, "X86_SIM_L_EXEC_BT_IMM", "X86_SIM_L_EXEC_BT_IMM", ""),
  ("X86_OP_BT_MEM_IMM", .directMacro, "X86_SIM_L_EXEC_BT_MEM_IMM", "X86_SIM_L_EXEC_BT_MEM_IMM", ""),
  ("X86_OP_ANDN_MEM", .directMacro, "X86_SIM_L_EXEC_ANDN_MEM", "X86_SIM_L_EXEC_ANDN_MEM", ""),
  ("X86_OP_CALL_MEMSET_REG", .directMacro, "X86_SIM_L_EXEC_CALL_MEMSET_REG", "X86_SIM_L_EXEC_CALL_MEMSET_REG", ""),
  ("X86_OP_CALL_MEMCPY_REG", .directMacro, "X86_SIM_L_EXEC_CALL_MEMCPY_REG", "X86_SIM_L_EXEC_CALL_MEMCPY_REG", ""),
  ("X86_OP_RET", .branchHandler, "", "", ""),
]

/-- Constructor enumeration for the generated table, in specification order. -/
def allSpecOps : List GeneratedX86Specialization.Op := [
  .nop,
  .movImm,
  .movReg,
  .addImm,
  .addReg,
  .xorReg,
  .movLoad,
  .movStoreImm,
  .movStoreReg,
  .lea,
  .aluImm,
  .aluReg,
  .cmpImm,
  .cmpReg,
  .testImm,
  .testReg,
  .jcc,
  .jmp,
  .push,
  .pop,
  .call,
  .cmov,
  .setcc,
  .bswap,
  .popcnt,
  .xchg,
  .div,
  .shldImm,
  .shrdImm,
  .cmpMemImm,
  .testMemImm,
  .cmpMemReg,
  .movzxReg,
  .movsxReg,
  .movsxLoad,
  .aluMem,
  .cmpRegMem,
  .movLoadScalar,
  .shiftx,
  .rorx,
  .movbeLoad,
  .movbeStore,
  .shiftxMem,
  .rorxMem,
  .movLoadMapPtr,
  .movLoadHelperId,
  .callHelper,
  .callReg,
  .loadXmm0,
  .storeXmm0,
  .aluMemUnary,
  .aluMemImm,
  .bzhi,
  .bzhiMem,
  .aluMemReg,
  .bt,
  .imulImm,
  .mulx,
  .repMovs,
  .testMemReg,
  .callMemset,
  .andn,
  .setccMem,
  .callMemcpy,
  .cmovMem,
  .imulMemImm,
  .btImm,
  .btMemImm,
  .andnMem,
  .callMemsetReg,
  .callMemcpyReg,
  .ret,
]

/-- The generated table, projected to the same tuple shape (with the token's
`X86_OP_*` spelling read back through `tokenName`), equals the independent
specification list. A change to a generated class, handler or macro, or to the
independent list, breaks this equality. -/
theorem x86_specialization_refines :
    x86SpecSpec =
      allSpecOps.map (fun op =>
        (x86SpecToken op, GeneratedX86Specialization.dispatch op,
         GeneratedX86Specialization.chainMacro op,
         GeneratedX86Specialization.directMacro op,
         GeneratedX86Specialization.auxMacro op)) := by
  native_decide

/-- The table covers every token exactly once, so a dispatch on the listed
tokens selects one row. -/
theorem x86_specialization_total :
    allSpecOps.length = 72 ∧
    x86SpecSpec.length = 72 ∧
    (allSpecOps.eraseDups).length = 72 ∧
    (x86SpecSpec.map (fun row => row.1)).eraseDups.length = 72 := by
  native_decide

/-- The no-insertion property holds for the independent table, and the generated
macros reproduce the handlers the independent table records. -/
theorem x86_specialization_no_insertion :
    noInsertion x86SpecSpec = true ∧
    x86SpecSpec =
      allSpecOps.map (fun op =>
        (x86SpecToken op, GeneratedX86Specialization.dispatch op,
         GeneratedX86Specialization.chainMacro op,
         GeneratedX86Specialization.directMacro op,
         GeneratedX86Specialization.auxMacro op)) := by
  native_decide

end KProgFormal
