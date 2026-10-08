import KProgFormal.GeneratedX86Opcode

namespace KProgFormal

/-- Independent enumeration of the x86-64 `X86_OP_*` tokens and their numeric
codes, written as explicit token/code pairs so it does not reuse the generated
tables. The pairs are in the order `kprog/x86/x86_sim.h` defines them. -/
def x86OpcodeSpec : List (String × Nat) := [
  ("X86_OP_NOP", 0), ("X86_OP_MOV_IMM", 1), ("X86_OP_MOV_REG", 2),
  ("X86_OP_ADD_IMM", 3), ("X86_OP_ADD_REG", 4), ("X86_OP_XOR_REG", 5),
  ("X86_OP_MOV_LOAD", 6), ("X86_OP_MOV_STORE_IMM", 7), ("X86_OP_MOV_STORE_REG", 8),
  ("X86_OP_LEA", 9), ("X86_OP_ALU_IMM", 10), ("X86_OP_ALU_REG", 11),
  ("X86_OP_CMP_IMM", 12), ("X86_OP_CMP_REG", 13), ("X86_OP_TEST_IMM", 14),
  ("X86_OP_TEST_REG", 15), ("X86_OP_JCC", 16), ("X86_OP_JMP", 17),
  ("X86_OP_PUSH", 18), ("X86_OP_POP", 19), ("X86_OP_CALL", 20),
  ("X86_OP_CMOV", 21), ("X86_OP_SETCC", 22), ("X86_OP_BSWAP", 23),
  ("X86_OP_POPCNT", 24), ("X86_OP_XCHG", 25), ("X86_OP_DIV", 26),
  ("X86_OP_SHLD_IMM", 27), ("X86_OP_SHRD_IMM", 28), ("X86_OP_CMP_MEM_IMM", 29),
  ("X86_OP_TEST_MEM_IMM", 30), ("X86_OP_CMP_MEM_REG", 31), ("X86_OP_MOVZX_REG", 32),
  ("X86_OP_MOVSX_REG", 33), ("X86_OP_MOVSX_LOAD", 34), ("X86_OP_ALU_MEM", 35),
  ("X86_OP_CMP_REG_MEM", 36), ("X86_OP_MOV_LOAD_SCALAR", 37), ("X86_OP_SHIFTX", 38),
  ("X86_OP_RORX", 39), ("X86_OP_MOVBE_LOAD", 40), ("X86_OP_MOVBE_STORE", 41),
  ("X86_OP_SHIFTX_MEM", 42), ("X86_OP_RORX_MEM", 43), ("X86_OP_MOV_LOAD_MAP_PTR", 44),
  ("X86_OP_MOV_LOAD_HELPER_ID", 45), ("X86_OP_CALL_HELPER", 46), ("X86_OP_CALL_REG", 47),
  ("X86_OP_LOAD_XMM0", 48), ("X86_OP_STORE_XMM0", 49), ("X86_OP_ALU_MEM_UNARY", 50),
  ("X86_OP_ALU_MEM_IMM", 51), ("X86_OP_BZHI", 52), ("X86_OP_BZHI_MEM", 53),
  ("X86_OP_ALU_MEM_REG", 54), ("X86_OP_BT", 55), ("X86_OP_IMUL_IMM", 56),
  ("X86_OP_MULX", 57), ("X86_OP_REP_MOVS", 58), ("X86_OP_TEST_MEM_REG", 59),
  ("X86_OP_CALL_MEMSET", 60), ("X86_OP_ANDN", 61), ("X86_OP_SETCC_MEM", 62),
  ("X86_OP_CALL_MEMCPY", 63), ("X86_OP_CMOV_MEM", 64), ("X86_OP_IMUL_MEM_IMM", 65),
  ("X86_OP_BT_IMM", 66), ("X86_OP_BT_MEM_IMM", 67), ("X86_OP_ANDN_MEM", 68),
  ("X86_OP_CALL_MEMSET_REG", 69), ("X86_OP_CALL_MEMCPY_REG", 70), ("X86_OP_RET", 255),
]

/-- Constructor enumeration for the generated table, in specification order;
the values themselves still come from the generated `define`/`code`
definitions. -/
def allOpcodes : List GeneratedX86Opcode.Op := [
  .nop, .movImm, .movReg, .addImm, .addReg, .xorReg,
  .movLoad, .movStoreImm, .movStoreReg, .lea, .aluImm, .aluReg,
  .cmpImm, .cmpReg, .testImm, .testReg, .jcc, .jmp,
  .push, .pop, .call, .cmov, .setcc, .bswap,
  .popcnt, .xchg, .div, .shldImm, .shrdImm, .cmpMemImm,
  .testMemImm, .cmpMemReg, .movzxReg, .movsxReg, .movsxLoad, .aluMem,
  .cmpRegMem, .movLoadScalar, .shiftx, .rorx, .movbeLoad, .movbeStore,
  .shiftxMem, .rorxMem, .movLoadMapPtr, .movLoadHelperId, .callHelper, .callReg,
  .loadXmm0, .storeXmm0, .aluMemUnary, .aluMemImm, .bzhi, .bzhiMem,
  .aluMemReg, .bt, .imulImm, .mulx, .repMovs, .testMemReg,
  .callMemset, .andn, .setccMem, .callMemcpy, .cmovMem, .imulMemImm,
  .btImm, .btMemImm, .andnMem, .callMemsetReg, .callMemcpyReg, .ret,
]

/-- The generated table, projected to token/code pairs, equals the independent
specification list. A change to either a generated code or a generated token
spelling, or to the independent list, breaks this equality. -/
theorem x86_opcode_refines :
    x86OpcodeSpec =
      allOpcodes.map (fun op => (GeneratedX86Opcode.define op,
                                 GeneratedX86Opcode.code op)) := by
  native_decide

/-- Selected generated codes are distinct, so dispatch on the numeric code
selects exactly one operation. The check is a representative sample of the
2556 pairs, not the full pairwise enumeration. -/
theorem x86_opcode_codes_distinct :
    GeneratedX86Opcode.code .nop ≠ GeneratedX86Opcode.code .ret ∧
    GeneratedX86Opcode.code .movImm ≠ GeneratedX86Opcode.code .movReg ∧
    GeneratedX86Opcode.code .cmpImm ≠ GeneratedX86Opcode.code .testImm ∧
    GeneratedX86Opcode.code .bswap ≠ GeneratedX86Opcode.code .popcnt ∧
    GeneratedX86Opcode.code .callMemsetReg ≠
      GeneratedX86Opcode.code .callMemcpyReg := by
  native_decide

end KProgFormal
