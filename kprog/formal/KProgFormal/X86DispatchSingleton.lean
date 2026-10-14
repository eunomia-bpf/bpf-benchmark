import KProgFormal.GeneratedX86DispatchSingleton
import KProgFormal.X86DispatchFamily
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedX86DispatchSingleton (SingletonOp code nopHandled
  callMemcpyHandled callMemsetHandled callMemcpyRegHandled
  callMemsetRegHandled callRegHandled movImmHandled movRegHandled
  movbeLoadHandled movbeStoreHandled loadXmm0Handled storeXmm0Handled
  leaHandled aluMemHandled aluMemUnaryHandled aluMemImmHandled
  aluMemRegHandled cmpRegMemHandled cmovHandled cmovMemHandled setccHandled
  setccMemHandled bswapHandled popcntHandled shiftxHandled shiftxMemHandled
  rorxHandled rorxMemHandled bzhiHandled bzhiMemHandled btHandled btImmHandled
  btMemImmHandled imulImmHandled imulMemImmHandled mulxHandled repMovsHandled
  andnHandled andnMemHandled xchgHandled divHandled pushHandled popHandled)

/-- The NOP singleton, named independently of the generated
`nopHandled` match. -/
def x86DispNopOps : List SingletonOp := [.nop]

/-- The CALLMEMCPY singleton, named independently of the generated
`callMemcpyHandled` match. -/
def x86DispCallMemcpyOps : List SingletonOp := [.callMemcpy]

/-- The CALLMEMSET singleton, named independently of the generated
`callMemsetHandled` match. -/
def x86DispCallMemsetOps : List SingletonOp := [.callMemset]

/-- The CALLMEMCPYREG singleton, named independently of the generated
`callMemcpyRegHandled` match. -/
def x86DispCallMemcpyRegOps : List SingletonOp := [.callMemcpyReg]

/-- The CALLMEMSETREG singleton, named independently of the generated
`callMemsetRegHandled` match. -/
def x86DispCallMemsetRegOps : List SingletonOp := [.callMemsetReg]

/-- The CALLREG singleton, named independently of the generated
`callRegHandled` match. -/
def x86DispCallRegOps : List SingletonOp := [.callReg]

/-- The MOVIMM singleton, named independently of the generated
`movImmHandled` match. -/
def x86DispMovImmOps : List SingletonOp := [.movImm]

/-- The MOVREG singleton, named independently of the generated
`movRegHandled` match. -/
def x86DispMovRegOps : List SingletonOp := [.movReg]

/-- The MOVBELOAD singleton, named independently of the generated
`movbeLoadHandled` match. -/
def x86DispMovbeLoadOps : List SingletonOp := [.movbeLoad]

/-- The MOVBESTORE singleton, named independently of the generated
`movbeStoreHandled` match. -/
def x86DispMovbeStoreOps : List SingletonOp := [.movbeStore]

/-- The LOADXMM0 singleton, named independently of the generated
`loadXmm0Handled` match. -/
def x86DispLoadXmm0Ops : List SingletonOp := [.loadXmm0]

/-- The STOREXMM0 singleton, named independently of the generated
`storeXmm0Handled` match. -/
def x86DispStoreXmm0Ops : List SingletonOp := [.storeXmm0]

/-- The LEA singleton, named independently of the generated
`leaHandled` match. -/
def x86DispLeaOps : List SingletonOp := [.lea]

/-- The ALUMEM singleton, named independently of the generated
`aluMemHandled` match. -/
def x86DispAluMemOps : List SingletonOp := [.aluMem]

/-- The ALUMEMUNARY singleton, named independently of the generated
`aluMemUnaryHandled` match. -/
def x86DispAluMemUnaryOps : List SingletonOp := [.aluMemUnary]

/-- The ALUMEMIMM singleton, named independently of the generated
`aluMemImmHandled` match. -/
def x86DispAluMemImmOps : List SingletonOp := [.aluMemImm]

/-- The ALUMEMREG singleton, named independently of the generated
`aluMemRegHandled` match. -/
def x86DispAluMemRegOps : List SingletonOp := [.aluMemReg]

/-- The CMPREGMEM singleton, named independently of the generated
`cmpRegMemHandled` match. -/
def x86DispCmpRegMemOps : List SingletonOp := [.cmpRegMem]

/-- The CMOV singleton, named independently of the generated
`cmovHandled` match. -/
def x86DispCmovOps : List SingletonOp := [.cmov]

/-- The CMOVMEM singleton, named independently of the generated
`cmovMemHandled` match. -/
def x86DispCmovMemOps : List SingletonOp := [.cmovMem]

/-- The SETCC singleton, named independently of the generated
`setccHandled` match. -/
def x86DispSetccOps : List SingletonOp := [.setcc]

/-- The SETCCMEM singleton, named independently of the generated
`setccMemHandled` match. -/
def x86DispSetccMemOps : List SingletonOp := [.setccMem]

/-- The BSWAP singleton, named independently of the generated
`bswapHandled` match. -/
def x86DispBswapOps : List SingletonOp := [.bswap]

/-- The POPCNT singleton, named independently of the generated
`popcntHandled` match. -/
def x86DispPopcntOps : List SingletonOp := [.popcnt]

/-- The SHIFTX singleton, named independently of the generated
`shiftxHandled` match. -/
def x86DispShiftxOps : List SingletonOp := [.shiftx]

/-- The SHIFTXMEM singleton, named independently of the generated
`shiftxMemHandled` match. -/
def x86DispShiftxMemOps : List SingletonOp := [.shiftxMem]

/-- The RORX singleton, named independently of the generated
`rorxHandled` match. -/
def x86DispRorxOps : List SingletonOp := [.rorx]

/-- The RORXMEM singleton, named independently of the generated
`rorxMemHandled` match. -/
def x86DispRorxMemOps : List SingletonOp := [.rorxMem]

/-- The BZHI singleton, named independently of the generated
`bzhiHandled` match. -/
def x86DispBzhiOps : List SingletonOp := [.bzhi]

/-- The BZHIMEM singleton, named independently of the generated
`bzhiMemHandled` match. -/
def x86DispBzhiMemOps : List SingletonOp := [.bzhiMem]

/-- The BT singleton, named independently of the generated
`btHandled` match. -/
def x86DispBtOps : List SingletonOp := [.bt]

/-- The BTIMM singleton, named independently of the generated
`btImmHandled` match. -/
def x86DispBtImmOps : List SingletonOp := [.btImm]

/-- The BTMEMIMM singleton, named independently of the generated
`btMemImmHandled` match. -/
def x86DispBtMemImmOps : List SingletonOp := [.btMemImm]

/-- The IMULIMM singleton, named independently of the generated
`imulImmHandled` match. -/
def x86DispImulImmOps : List SingletonOp := [.imulImm]

/-- The IMULMEMIMM singleton, named independently of the generated
`imulMemImmHandled` match. -/
def x86DispImulMemImmOps : List SingletonOp := [.imulMemImm]

/-- The MULX singleton, named independently of the generated
`mulxHandled` match. -/
def x86DispMulxOps : List SingletonOp := [.mulx]

/-- The REPMOVS singleton, named independently of the generated
`repMovsHandled` match. -/
def x86DispRepMovsOps : List SingletonOp := [.repMovs]

/-- The ANDN singleton, named independently of the generated
`andnHandled` match. -/
def x86DispAndnOps : List SingletonOp := [.andn]

/-- The ANDNMEM singleton, named independently of the generated
`andnMemHandled` match. -/
def x86DispAndnMemOps : List SingletonOp := [.andnMem]

/-- The XCHG singleton, named independently of the generated
`xchgHandled` match. -/
def x86DispXchgOps : List SingletonOp := [.xchg]

/-- The DIV singleton, named independently of the generated
`divHandled` match. -/
def x86DispDivOps : List SingletonOp := [.div]

/-- The PUSH singleton, named independently of the generated
`pushHandled` match. -/
def x86DispPushOps : List SingletonOp := [.push]

/-- The POP singleton, named independently of the generated
`popHandled` match. -/
def x86DispPopOps : List SingletonOp := [.pop]

def x86SingletonOps : List SingletonOp :=
  x86DispNopOps ++
  x86DispCallMemcpyOps ++
  x86DispCallMemsetOps ++
  x86DispCallMemcpyRegOps ++
  x86DispCallMemsetRegOps ++
  x86DispCallRegOps ++
  x86DispMovImmOps ++
  x86DispMovRegOps ++
  x86DispMovbeLoadOps ++
  x86DispMovbeStoreOps ++
  x86DispLoadXmm0Ops ++
  x86DispStoreXmm0Ops ++
  x86DispLeaOps ++
  x86DispAluMemOps ++
  x86DispAluMemUnaryOps ++
  x86DispAluMemImmOps ++
  x86DispAluMemRegOps ++
  x86DispCmpRegMemOps ++
  x86DispCmovOps ++
  x86DispCmovMemOps ++
  x86DispSetccOps ++
  x86DispSetccMemOps ++
  x86DispBswapOps ++
  x86DispPopcntOps ++
  x86DispShiftxOps ++
  x86DispShiftxMemOps ++
  x86DispRorxOps ++
  x86DispRorxMemOps ++
  x86DispBzhiOps ++
  x86DispBzhiMemOps ++
  x86DispBtOps ++
  x86DispBtImmOps ++
  x86DispBtMemImmOps ++
  x86DispImulImmOps ++
  x86DispImulMemImmOps ++
  x86DispMulxOps ++
  x86DispRepMovsOps ++
  x86DispAndnOps ++
  x86DispAndnMemOps ++
  x86DispXchgOps ++
  x86DispDivOps ++
  x86DispPushOps ++
  x86DispPopOps

/-- Independent NOP membership: the opcode is the one named NOP member.
Structurally separate from the generated `op == .nop` test. -/
def x86DispNopSpec (op : SingletonOp) : Bool := op ∈ x86DispNopOps

/-- Independent CALLMEMCPY membership. -/
def x86DispCallMemcpySpec (op : SingletonOp) : Bool := op ∈ x86DispCallMemcpyOps

/-- Independent CALLMEMSET membership. -/
def x86DispCallMemsetSpec (op : SingletonOp) : Bool := op ∈ x86DispCallMemsetOps

/-- Independent CALLMEMCPYREG membership. -/
def x86DispCallMemcpyRegSpec (op : SingletonOp) : Bool := op ∈ x86DispCallMemcpyRegOps

/-- Independent CALLMEMSETREG membership. -/
def x86DispCallMemsetRegSpec (op : SingletonOp) : Bool := op ∈ x86DispCallMemsetRegOps

/-- Independent CALLREG membership. -/
def x86DispCallRegSpec (op : SingletonOp) : Bool := op ∈ x86DispCallRegOps

/-- Independent MOVIMM membership. -/
def x86DispMovImmSpec (op : SingletonOp) : Bool := op ∈ x86DispMovImmOps

/-- Independent MOVREG membership. -/
def x86DispMovRegSpec (op : SingletonOp) : Bool := op ∈ x86DispMovRegOps

/-- Independent MOVBELOAD membership. -/
def x86DispMovbeLoadSpec (op : SingletonOp) : Bool := op ∈ x86DispMovbeLoadOps

/-- Independent MOVBESTORE membership. -/
def x86DispMovbeStoreSpec (op : SingletonOp) : Bool := op ∈ x86DispMovbeStoreOps

/-- Independent LOADXMM0 membership. -/
def x86DispLoadXmm0Spec (op : SingletonOp) : Bool := op ∈ x86DispLoadXmm0Ops

/-- Independent STOREXMM0 membership. -/
def x86DispStoreXmm0Spec (op : SingletonOp) : Bool := op ∈ x86DispStoreXmm0Ops

/-- Independent LEA membership. -/
def x86DispLeaSpec (op : SingletonOp) : Bool := op ∈ x86DispLeaOps

/-- Independent ALUMEM membership. -/
def x86DispAluMemSpec (op : SingletonOp) : Bool := op ∈ x86DispAluMemOps

/-- Independent ALUMEMUNARY membership. -/
def x86DispAluMemUnarySpec (op : SingletonOp) : Bool := op ∈ x86DispAluMemUnaryOps

/-- Independent ALUMEMIMM membership. -/
def x86DispAluMemImmSpec (op : SingletonOp) : Bool := op ∈ x86DispAluMemImmOps

/-- Independent ALUMEMREG membership. -/
def x86DispAluMemRegSpec (op : SingletonOp) : Bool := op ∈ x86DispAluMemRegOps

/-- Independent CMPREGMEM membership. -/
def x86DispCmpRegMemSpec (op : SingletonOp) : Bool := op ∈ x86DispCmpRegMemOps

/-- Independent CMOV membership. -/
def x86DispCmovSpec (op : SingletonOp) : Bool := op ∈ x86DispCmovOps

/-- Independent CMOVMEM membership. -/
def x86DispCmovMemSpec (op : SingletonOp) : Bool := op ∈ x86DispCmovMemOps

/-- Independent SETCC membership. -/
def x86DispSetccSpec (op : SingletonOp) : Bool := op ∈ x86DispSetccOps

/-- Independent SETCCMEM membership. -/
def x86DispSetccMemSpec (op : SingletonOp) : Bool := op ∈ x86DispSetccMemOps

/-- Independent BSWAP membership. -/
def x86DispBswapSpec (op : SingletonOp) : Bool := op ∈ x86DispBswapOps

/-- Independent POPCNT membership. -/
def x86DispPopcntSpec (op : SingletonOp) : Bool := op ∈ x86DispPopcntOps

/-- Independent SHIFTX membership. -/
def x86DispShiftxSpec (op : SingletonOp) : Bool := op ∈ x86DispShiftxOps

/-- Independent SHIFTXMEM membership. -/
def x86DispShiftxMemSpec (op : SingletonOp) : Bool := op ∈ x86DispShiftxMemOps

/-- Independent RORX membership. -/
def x86DispRorxSpec (op : SingletonOp) : Bool := op ∈ x86DispRorxOps

/-- Independent RORXMEM membership. -/
def x86DispRorxMemSpec (op : SingletonOp) : Bool := op ∈ x86DispRorxMemOps

/-- Independent BZHI membership. -/
def x86DispBzhiSpec (op : SingletonOp) : Bool := op ∈ x86DispBzhiOps

/-- Independent BZHIMEM membership. -/
def x86DispBzhiMemSpec (op : SingletonOp) : Bool := op ∈ x86DispBzhiMemOps

/-- Independent BT membership. -/
def x86DispBtSpec (op : SingletonOp) : Bool := op ∈ x86DispBtOps

/-- Independent BTIMM membership. -/
def x86DispBtImmSpec (op : SingletonOp) : Bool := op ∈ x86DispBtImmOps

/-- Independent BTMEMIMM membership. -/
def x86DispBtMemImmSpec (op : SingletonOp) : Bool := op ∈ x86DispBtMemImmOps

/-- Independent IMULIMM membership. -/
def x86DispImulImmSpec (op : SingletonOp) : Bool := op ∈ x86DispImulImmOps

/-- Independent IMULMEMIMM membership. -/
def x86DispImulMemImmSpec (op : SingletonOp) : Bool := op ∈ x86DispImulMemImmOps

/-- Independent MULX membership. -/
def x86DispMulxSpec (op : SingletonOp) : Bool := op ∈ x86DispMulxOps

/-- Independent REPMOVS membership. -/
def x86DispRepMovsSpec (op : SingletonOp) : Bool := op ∈ x86DispRepMovsOps

/-- Independent ANDN membership. -/
def x86DispAndnSpec (op : SingletonOp) : Bool := op ∈ x86DispAndnOps

/-- Independent ANDNMEM membership. -/
def x86DispAndnMemSpec (op : SingletonOp) : Bool := op ∈ x86DispAndnMemOps

/-- Independent XCHG membership. -/
def x86DispXchgSpec (op : SingletonOp) : Bool := op ∈ x86DispXchgOps

/-- Independent DIV membership. -/
def x86DispDivSpec (op : SingletonOp) : Bool := op ∈ x86DispDivOps

/-- Independent PUSH membership. -/
def x86DispPushSpec (op : SingletonOp) : Bool := op ∈ x86DispPushOps

/-- Independent POP membership. -/
def x86DispPopSpec (op : SingletonOp) : Bool := op ∈ x86DispPopOps

/-- The generated NOP membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_nop_refines (op : SingletonOp) :
    nopHandled op = x86DispNopSpec op := by
  cases op <;> decide

/-- The generated CALLMEMCPY membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_call_memcpy_refines (op : SingletonOp) :
    callMemcpyHandled op = x86DispCallMemcpySpec op := by
  cases op <;> decide

/-- The generated CALLMEMSET membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_call_memset_refines (op : SingletonOp) :
    callMemsetHandled op = x86DispCallMemsetSpec op := by
  cases op <;> decide

/-- The generated CALLMEMCPYREG membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_call_memcpy_reg_refines (op : SingletonOp) :
    callMemcpyRegHandled op = x86DispCallMemcpyRegSpec op := by
  cases op <;> decide

/-- The generated CALLMEMSETREG membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_call_memset_reg_refines (op : SingletonOp) :
    callMemsetRegHandled op = x86DispCallMemsetRegSpec op := by
  cases op <;> decide

/-- The generated CALLREG membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_call_reg_refines (op : SingletonOp) :
    callRegHandled op = x86DispCallRegSpec op := by
  cases op <;> decide

/-- The generated MOVIMM membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_mov_imm_refines (op : SingletonOp) :
    movImmHandled op = x86DispMovImmSpec op := by
  cases op <;> decide

/-- The generated MOVREG membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_mov_reg_refines (op : SingletonOp) :
    movRegHandled op = x86DispMovRegSpec op := by
  cases op <;> decide

/-- The generated MOVBELOAD membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_movbe_load_refines (op : SingletonOp) :
    movbeLoadHandled op = x86DispMovbeLoadSpec op := by
  cases op <;> decide

/-- The generated MOVBESTORE membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_movbe_store_refines (op : SingletonOp) :
    movbeStoreHandled op = x86DispMovbeStoreSpec op := by
  cases op <;> decide

/-- The generated LOADXMM0 membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_load_xmm0_refines (op : SingletonOp) :
    loadXmm0Handled op = x86DispLoadXmm0Spec op := by
  cases op <;> decide

/-- The generated STOREXMM0 membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_store_xmm0_refines (op : SingletonOp) :
    storeXmm0Handled op = x86DispStoreXmm0Spec op := by
  cases op <;> decide

/-- The generated LEA membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_lea_refines (op : SingletonOp) :
    leaHandled op = x86DispLeaSpec op := by
  cases op <;> decide

/-- The generated ALUMEM membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_alu_mem_refines (op : SingletonOp) :
    aluMemHandled op = x86DispAluMemSpec op := by
  cases op <;> decide

/-- The generated ALUMEMUNARY membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_alu_mem_unary_refines (op : SingletonOp) :
    aluMemUnaryHandled op = x86DispAluMemUnarySpec op := by
  cases op <;> decide

/-- The generated ALUMEMIMM membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_alu_mem_imm_refines (op : SingletonOp) :
    aluMemImmHandled op = x86DispAluMemImmSpec op := by
  cases op <;> decide

/-- The generated ALUMEMREG membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_alu_mem_reg_refines (op : SingletonOp) :
    aluMemRegHandled op = x86DispAluMemRegSpec op := by
  cases op <;> decide

/-- The generated CMPREGMEM membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_cmp_reg_mem_refines (op : SingletonOp) :
    cmpRegMemHandled op = x86DispCmpRegMemSpec op := by
  cases op <;> decide

/-- The generated CMOV membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_cmov_refines (op : SingletonOp) :
    cmovHandled op = x86DispCmovSpec op := by
  cases op <;> decide

/-- The generated CMOVMEM membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_cmov_mem_refines (op : SingletonOp) :
    cmovMemHandled op = x86DispCmovMemSpec op := by
  cases op <;> decide

/-- The generated SETCC membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_setcc_refines (op : SingletonOp) :
    setccHandled op = x86DispSetccSpec op := by
  cases op <;> decide

/-- The generated SETCCMEM membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_setcc_mem_refines (op : SingletonOp) :
    setccMemHandled op = x86DispSetccMemSpec op := by
  cases op <;> decide

/-- The generated BSWAP membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_bswap_refines (op : SingletonOp) :
    bswapHandled op = x86DispBswapSpec op := by
  cases op <;> decide

/-- The generated POPCNT membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_popcnt_refines (op : SingletonOp) :
    popcntHandled op = x86DispPopcntSpec op := by
  cases op <;> decide

/-- The generated SHIFTX membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_shiftx_refines (op : SingletonOp) :
    shiftxHandled op = x86DispShiftxSpec op := by
  cases op <;> decide

/-- The generated SHIFTXMEM membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_shiftx_mem_refines (op : SingletonOp) :
    shiftxMemHandled op = x86DispShiftxMemSpec op := by
  cases op <;> decide

/-- The generated RORX membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_rorx_refines (op : SingletonOp) :
    rorxHandled op = x86DispRorxSpec op := by
  cases op <;> decide

/-- The generated RORXMEM membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_rorx_mem_refines (op : SingletonOp) :
    rorxMemHandled op = x86DispRorxMemSpec op := by
  cases op <;> decide

/-- The generated BZHI membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_bzhi_refines (op : SingletonOp) :
    bzhiHandled op = x86DispBzhiSpec op := by
  cases op <;> decide

/-- The generated BZHIMEM membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_bzhi_mem_refines (op : SingletonOp) :
    bzhiMemHandled op = x86DispBzhiMemSpec op := by
  cases op <;> decide

/-- The generated BT membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_bt_refines (op : SingletonOp) :
    btHandled op = x86DispBtSpec op := by
  cases op <;> decide

/-- The generated BTIMM membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_bt_imm_refines (op : SingletonOp) :
    btImmHandled op = x86DispBtImmSpec op := by
  cases op <;> decide

/-- The generated BTMEMIMM membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_bt_mem_imm_refines (op : SingletonOp) :
    btMemImmHandled op = x86DispBtMemImmSpec op := by
  cases op <;> decide

/-- The generated IMULIMM membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_imul_imm_refines (op : SingletonOp) :
    imulImmHandled op = x86DispImulImmSpec op := by
  cases op <;> decide

/-- The generated IMULMEMIMM membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_imul_mem_imm_refines (op : SingletonOp) :
    imulMemImmHandled op = x86DispImulMemImmSpec op := by
  cases op <;> decide

/-- The generated MULX membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_mulx_refines (op : SingletonOp) :
    mulxHandled op = x86DispMulxSpec op := by
  cases op <;> decide

/-- The generated REPMOVS membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_rep_movs_refines (op : SingletonOp) :
    repMovsHandled op = x86DispRepMovsSpec op := by
  cases op <;> decide

/-- The generated ANDN membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_andn_refines (op : SingletonOp) :
    andnHandled op = x86DispAndnSpec op := by
  cases op <;> decide

/-- The generated ANDNMEM membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_andn_mem_refines (op : SingletonOp) :
    andnMemHandled op = x86DispAndnMemSpec op := by
  cases op <;> decide

/-- The generated XCHG membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_xchg_refines (op : SingletonOp) :
    xchgHandled op = x86DispXchgSpec op := by
  cases op <;> decide

/-- The generated DIV membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_div_refines (op : SingletonOp) :
    divHandled op = x86DispDivSpec op := by
  cases op <;> decide

/-- The generated PUSH membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_push_refines (op : SingletonOp) :
    pushHandled op = x86DispPushSpec op := by
  cases op <;> decide

/-- The generated POP membership table agrees with the independent
statement. -/
theorem x86_disp_singleton_pop_refines (op : SingletonOp) :
    popHandled op = x86DispPopSpec op := by
  cases op <;> decide

/-- A generated singleton membership test holds exactly when the opcode is a
member of the singleton's named list. -/
theorem x86_singleton_handled_iff_mem (op : SingletonOp) :
    (nopHandled op = true ↔ op ∈ x86DispNopOps) ∧
    (callMemcpyHandled op = true ↔ op ∈ x86DispCallMemcpyOps) ∧
    (callMemsetHandled op = true ↔ op ∈ x86DispCallMemsetOps) ∧
    (callMemcpyRegHandled op = true ↔ op ∈ x86DispCallMemcpyRegOps) ∧
    (callMemsetRegHandled op = true ↔ op ∈ x86DispCallMemsetRegOps) ∧
    (callRegHandled op = true ↔ op ∈ x86DispCallRegOps) ∧
    (movImmHandled op = true ↔ op ∈ x86DispMovImmOps) ∧
    (movRegHandled op = true ↔ op ∈ x86DispMovRegOps) ∧
    (movbeLoadHandled op = true ↔ op ∈ x86DispMovbeLoadOps) ∧
    (movbeStoreHandled op = true ↔ op ∈ x86DispMovbeStoreOps) ∧
    (loadXmm0Handled op = true ↔ op ∈ x86DispLoadXmm0Ops) ∧
    (storeXmm0Handled op = true ↔ op ∈ x86DispStoreXmm0Ops) ∧
    (leaHandled op = true ↔ op ∈ x86DispLeaOps) ∧
    (aluMemHandled op = true ↔ op ∈ x86DispAluMemOps) ∧
    (aluMemUnaryHandled op = true ↔ op ∈ x86DispAluMemUnaryOps) ∧
    (aluMemImmHandled op = true ↔ op ∈ x86DispAluMemImmOps) ∧
    (aluMemRegHandled op = true ↔ op ∈ x86DispAluMemRegOps) ∧
    (cmpRegMemHandled op = true ↔ op ∈ x86DispCmpRegMemOps) ∧
    (cmovHandled op = true ↔ op ∈ x86DispCmovOps) ∧
    (cmovMemHandled op = true ↔ op ∈ x86DispCmovMemOps) ∧
    (setccHandled op = true ↔ op ∈ x86DispSetccOps) ∧
    (setccMemHandled op = true ↔ op ∈ x86DispSetccMemOps) ∧
    (bswapHandled op = true ↔ op ∈ x86DispBswapOps) ∧
    (popcntHandled op = true ↔ op ∈ x86DispPopcntOps) ∧
    (shiftxHandled op = true ↔ op ∈ x86DispShiftxOps) ∧
    (shiftxMemHandled op = true ↔ op ∈ x86DispShiftxMemOps) ∧
    (rorxHandled op = true ↔ op ∈ x86DispRorxOps) ∧
    (rorxMemHandled op = true ↔ op ∈ x86DispRorxMemOps) ∧
    (bzhiHandled op = true ↔ op ∈ x86DispBzhiOps) ∧
    (bzhiMemHandled op = true ↔ op ∈ x86DispBzhiMemOps) ∧
    (btHandled op = true ↔ op ∈ x86DispBtOps) ∧
    (btImmHandled op = true ↔ op ∈ x86DispBtImmOps) ∧
    (btMemImmHandled op = true ↔ op ∈ x86DispBtMemImmOps) ∧
    (imulImmHandled op = true ↔ op ∈ x86DispImulImmOps) ∧
    (imulMemImmHandled op = true ↔ op ∈ x86DispImulMemImmOps) ∧
    (mulxHandled op = true ↔ op ∈ x86DispMulxOps) ∧
    (repMovsHandled op = true ↔ op ∈ x86DispRepMovsOps) ∧
    (andnHandled op = true ↔ op ∈ x86DispAndnOps) ∧
    (andnMemHandled op = true ↔ op ∈ x86DispAndnMemOps) ∧
    (xchgHandled op = true ↔ op ∈ x86DispXchgOps) ∧
    (divHandled op = true ↔ op ∈ x86DispDivOps) ∧
    (pushHandled op = true ↔ op ∈ x86DispPushOps) ∧
    (popHandled op = true ↔ op ∈ x86DispPopOps) := by
  cases op <;> simp_all [x86DispNopOps, x86DispCallMemcpyOps, x86DispCallMemsetOps, x86DispCallMemcpyRegOps, x86DispCallMemsetRegOps, x86DispCallRegOps, x86DispMovImmOps, x86DispMovRegOps, x86DispMovbeLoadOps, x86DispMovbeStoreOps, x86DispLoadXmm0Ops, x86DispStoreXmm0Ops, x86DispLeaOps, x86DispAluMemOps, x86DispAluMemUnaryOps, x86DispAluMemImmOps, x86DispAluMemRegOps, x86DispCmpRegMemOps, x86DispCmovOps, x86DispCmovMemOps, x86DispSetccOps, x86DispSetccMemOps, x86DispBswapOps, x86DispPopcntOps, x86DispShiftxOps, x86DispShiftxMemOps, x86DispRorxOps, x86DispRorxMemOps, x86DispBzhiOps, x86DispBzhiMemOps, x86DispBtOps, x86DispBtImmOps, x86DispBtMemImmOps, x86DispImulImmOps, x86DispImulMemImmOps, x86DispMulxOps, x86DispRepMovsOps, x86DispAndnOps, x86DispAndnMemOps, x86DispXchgOps, x86DispDivOps, x86DispPushOps, x86DispPopOps, nopHandled, callMemcpyHandled, callMemsetHandled, callMemcpyRegHandled, callMemsetRegHandled, callRegHandled, movImmHandled, movRegHandled, movbeLoadHandled, movbeStoreHandled, loadXmm0Handled, storeXmm0Handled, leaHandled, aluMemHandled, aluMemUnaryHandled, aluMemImmHandled, aluMemRegHandled, cmpRegMemHandled, cmovHandled, cmovMemHandled, setccHandled, setccMemHandled, bswapHandled, popcntHandled, shiftxHandled, shiftxMemHandled, rorxHandled, rorxMemHandled, bzhiHandled, bzhiMemHandled, btHandled, btImmHandled, btMemImmHandled, imulImmHandled, imulMemImmHandled, mulxHandled, repMovsHandled, andnHandled, andnMemHandled, xchgHandled, divHandled, pushHandled, popHandled]
/-- The operator-side statement of the same contract: for a member opcode every generated singleton test returns true. -/
theorem x86_singleton_member_handled (op : SingletonOp)
    (h : op ∈ x86SingletonOps) :
    nopHandled op ||
    callMemcpyHandled op ||
    callMemsetHandled op ||
    callMemcpyRegHandled op ||
    callMemsetRegHandled op ||
    callRegHandled op ||
    movImmHandled op ||
    movRegHandled op ||
    movbeLoadHandled op ||
    movbeStoreHandled op ||
    loadXmm0Handled op ||
    storeXmm0Handled op ||
    leaHandled op ||
    aluMemHandled op ||
    aluMemUnaryHandled op ||
    aluMemImmHandled op ||
    aluMemRegHandled op ||
    cmpRegMemHandled op ||
    cmovHandled op ||
    cmovMemHandled op ||
    setccHandled op ||
    setccMemHandled op ||
    bswapHandled op ||
    popcntHandled op ||
    shiftxHandled op ||
    shiftxMemHandled op ||
    rorxHandled op ||
    rorxMemHandled op ||
    bzhiHandled op ||
    bzhiMemHandled op ||
    btHandled op ||
    btImmHandled op ||
    btMemImmHandled op ||
    imulImmHandled op ||
    imulMemImmHandled op ||
    mulxHandled op ||
    repMovsHandled op ||
    andnHandled op ||
    andnMemHandled op ||
    xchgHandled op ||
    divHandled op ||
    pushHandled op ||
    popHandled op = true := by
  cases op <;>
    simp_all [ x86DispNopOps, x86DispCallMemcpyOps, x86DispCallMemsetOps,
              x86DispCallMemcpyRegOps, x86DispCallMemsetRegOps, x86DispCallRegOps,
              x86DispMovImmOps, x86DispMovRegOps, x86DispMovbeLoadOps, x86DispMovbeStoreOps,
              x86DispLoadXmm0Ops, x86DispStoreXmm0Ops, x86DispLeaOps, x86DispAluMemOps,
              x86DispAluMemUnaryOps, x86DispAluMemImmOps, x86DispAluMemRegOps,
              x86DispCmpRegMemOps, x86DispCmovOps, x86DispCmovMemOps, x86DispSetccOps,
              x86DispSetccMemOps, x86DispBswapOps, x86DispPopcntOps, x86DispShiftxOps,
              x86DispShiftxMemOps, x86DispRorxOps, x86DispRorxMemOps, x86DispBzhiOps,
              x86DispBzhiMemOps, x86DispBtOps, x86DispBtImmOps, x86DispBtMemImmOps,
              x86DispImulImmOps, x86DispImulMemImmOps, x86DispMulxOps, x86DispRepMovsOps,
              x86DispAndnOps, x86DispAndnMemOps, x86DispXchgOps, x86DispDivOps, x86DispPushOps,
              x86DispPopOps, nopHandled, callMemcpyHandled, callMemsetHandled,
              callMemcpyRegHandled, callMemsetRegHandled, callRegHandled, movImmHandled,
              movRegHandled, movbeLoadHandled, movbeStoreHandled, loadXmm0Handled,
              storeXmm0Handled, leaHandled, aluMemHandled, aluMemUnaryHandled, aluMemImmHandled,
              aluMemRegHandled, cmpRegMemHandled, cmovHandled, cmovMemHandled, setccHandled,
              setccMemHandled, bswapHandled, popcntHandled, shiftxHandled, shiftxMemHandled,
              rorxHandled, rorxMemHandled, bzhiHandled, bzhiMemHandled, btHandled, btImmHandled,
              btMemImmHandled, imulImmHandled, imulMemImmHandled, mulxHandled, repMovsHandled,
              andnHandled, andnMemHandled, xchgHandled, divHandled, pushHandled, popHandled]

/-- Nonmember arm, part a: conjuncts 1–15 stay unhandled (combined 43-way membership form in `x86_singleton_handled_iff_mem`). -/
theorem x86_singleton_nonmember_unhandled_a (op : SingletonOp)
    (h : op ∉ x86SingletonOps) :
    nopHandled op = false ∧
    callMemcpyHandled op = false ∧
    callMemsetHandled op = false ∧
    callMemcpyRegHandled op = false ∧
    callMemsetRegHandled op = false ∧
    callRegHandled op = false ∧
    movImmHandled op = false ∧
    movRegHandled op = false ∧
    movbeLoadHandled op = false ∧
    movbeStoreHandled op = false ∧
    loadXmm0Handled op = false ∧
    storeXmm0Handled op = false ∧
    leaHandled op = false ∧
    aluMemHandled op = false ∧
    aluMemUnaryHandled op = false := by
  cases op <;> simp_all [x86DispNopOps, x86DispCallMemcpyOps, x86DispCallMemsetOps, x86DispCallMemcpyRegOps, x86DispCallMemsetRegOps, x86DispCallRegOps, x86DispMovImmOps, x86DispMovRegOps, x86DispMovbeLoadOps, x86DispMovbeStoreOps, x86DispLoadXmm0Ops, x86DispStoreXmm0Ops, x86DispLeaOps, x86DispAluMemOps, x86DispAluMemUnaryOps, nopHandled, callMemcpyHandled, callMemsetHandled, callMemcpyRegHandled, callMemsetRegHandled, callRegHandled, movImmHandled, movRegHandled, movbeLoadHandled, movbeStoreHandled, loadXmm0Handled, storeXmm0Handled, leaHandled, aluMemHandled, aluMemUnaryHandled, aluMemImmHandled, aluMemRegHandled, cmpRegMemHandled, cmovHandled, cmovMemHandled, setccHandled, setccMemHandled, bswapHandled, popcntHandled, shiftxHandled, shiftxMemHandled, rorxHandled, rorxMemHandled, bzhiHandled, bzhiMemHandled, btHandled, btImmHandled, btMemImmHandled, imulImmHandled, imulMemImmHandled, mulxHandled, repMovsHandled, andnHandled, andnMemHandled, xchgHandled, divHandled, pushHandled, popHandled] <;> exfalso <;> exact h (by decide)
/-- Nonmember arm, part b: conjuncts 16–30 stay unhandled.
(See `x86_singleton_handled_iff_mem` for the combined 43-way membership form.) -/
theorem x86_singleton_nonmember_unhandled_b (op : SingletonOp)
    (h : op ∉ x86SingletonOps) :
    aluMemImmHandled op = false ∧
    aluMemRegHandled op = false ∧
    cmpRegMemHandled op = false ∧
    cmovHandled op = false ∧
    cmovMemHandled op = false ∧
    setccHandled op = false ∧
    setccMemHandled op = false ∧
    bswapHandled op = false ∧
    popcntHandled op = false ∧
    shiftxHandled op = false ∧
    shiftxMemHandled op = false ∧
    rorxHandled op = false ∧
    rorxMemHandled op = false ∧
    bzhiHandled op = false ∧
    bzhiMemHandled op = false := by
  cases op <;> simp_all [x86DispNopOps, x86DispCallMemcpyOps, x86DispCallMemsetOps, x86DispCallMemcpyRegOps, x86DispCallMemsetRegOps, x86DispCallRegOps, x86DispMovImmOps, x86DispMovRegOps, x86DispMovbeLoadOps, x86DispMovbeStoreOps, x86DispLoadXmm0Ops, x86DispStoreXmm0Ops, x86DispLeaOps, x86DispAluMemOps, x86DispAluMemUnaryOps, x86DispAluMemImmOps, x86DispAluMemRegOps, x86DispCmpRegMemOps, x86DispCmovOps, x86DispCmovMemOps, x86DispSetccOps, x86DispSetccMemOps, x86DispBswapOps, x86DispPopcntOps, x86DispShiftxOps, x86DispShiftxMemOps, x86DispRorxOps, x86DispRorxMemOps, x86DispBzhiOps, x86DispBzhiMemOps, x86DispBtOps, x86DispBtImmOps, x86DispBtMemImmOps, x86DispImulImmOps, x86DispImulMemImmOps, x86DispMulxOps, x86DispRepMovsOps, x86DispAndnOps, x86DispAndnMemOps, x86DispXchgOps, x86DispDivOps, x86DispPushOps, x86DispPopOps, nopHandled, callMemcpyHandled, callMemsetHandled, callMemcpyRegHandled, callMemsetRegHandled, callRegHandled, movImmHandled, movRegHandled, movbeLoadHandled, movbeStoreHandled, loadXmm0Handled, storeXmm0Handled, leaHandled, aluMemHandled, aluMemUnaryHandled, aluMemImmHandled, aluMemRegHandled, cmpRegMemHandled, cmovHandled, cmovMemHandled, setccHandled, setccMemHandled, bswapHandled, popcntHandled, shiftxHandled, shiftxMemHandled, rorxHandled, rorxMemHandled, bzhiHandled, bzhiMemHandled, btHandled, btImmHandled, btMemImmHandled, imulImmHandled, imulMemImmHandled, mulxHandled, repMovsHandled, andnHandled, andnMemHandled, xchgHandled, divHandled, pushHandled, popHandled] <;> exfalso <;> exact h (by decide)
/-- Nonmember arm, part c: conjuncts 31–43 stay unhandled.
(See `x86_singleton_handled_iff_mem` for the combined 43-way membership form.) -/
theorem x86_singleton_nonmember_unhandled_c (op : SingletonOp)
    (h : op ∉ x86SingletonOps) :
    btHandled op = false ∧
    btImmHandled op = false ∧
    btMemImmHandled op = false ∧
    imulImmHandled op = false ∧
    imulMemImmHandled op = false ∧
    mulxHandled op = false ∧
    repMovsHandled op = false ∧
    andnHandled op = false ∧
    andnMemHandled op = false ∧
    xchgHandled op = false ∧
    divHandled op = false ∧
    pushHandled op = false ∧
    popHandled op = false := by
  cases op <;> simp_all [x86DispNopOps, x86DispCallMemcpyOps, x86DispCallMemsetOps, x86DispCallMemcpyRegOps, x86DispCallMemsetRegOps, x86DispCallRegOps, x86DispMovImmOps, x86DispMovRegOps, x86DispMovbeLoadOps, x86DispMovbeStoreOps, x86DispLoadXmm0Ops, x86DispStoreXmm0Ops, x86DispLeaOps, x86DispAluMemOps, x86DispAluMemUnaryOps, x86DispAluMemImmOps, x86DispAluMemRegOps, x86DispCmpRegMemOps, x86DispCmovOps, x86DispCmovMemOps, x86DispSetccOps, x86DispSetccMemOps, x86DispBswapOps, x86DispPopcntOps, x86DispShiftxOps, x86DispShiftxMemOps, x86DispRorxOps, x86DispRorxMemOps, x86DispBzhiOps, x86DispBzhiMemOps, x86DispBtOps, x86DispBtImmOps, x86DispBtMemImmOps, x86DispImulImmOps, x86DispImulMemImmOps, x86DispMulxOps, x86DispRepMovsOps, x86DispAndnOps, x86DispAndnMemOps, x86DispXchgOps, x86DispDivOps, x86DispPushOps, x86DispPopOps, nopHandled, callMemcpyHandled, callMemsetHandled, callMemcpyRegHandled, callMemsetRegHandled, callRegHandled, movImmHandled, movRegHandled, movbeLoadHandled, movbeStoreHandled, loadXmm0Handled, storeXmm0Handled, leaHandled, aluMemHandled, aluMemUnaryHandled, aluMemImmHandled, aluMemRegHandled, cmpRegMemHandled, cmovHandled, cmovMemHandled, setccHandled, setccMemHandled, bswapHandled, popcntHandled, shiftxHandled, shiftxMemHandled, rorxHandled, rorxMemHandled, bzhiHandled, bzhiMemHandled, btHandled, btImmHandled, btMemImmHandled, imulImmHandled, imulMemImmHandled, mulxHandled, repMovsHandled, andnHandled, andnMemHandled, xchgHandled, divHandled, pushHandled, popHandled] <;> exfalso <;> exact h (by decide)
/-- The generated code dispatch: the forty-three singleton mnemonics map onto
the X86_OP_* opcode numbers the C gates compare against. -/
theorem x86_singleton_code_dispatch :
    code .nop = 0 ∧
    code .callMemcpy = 63 ∧
    code .callMemset = 60 ∧
    code .callMemcpyReg = 70 ∧
    code .callMemsetReg = 69 ∧
    code .callReg = 47 ∧
    code .movImm = 1 ∧
    code .movReg = 2 ∧
    code .movbeLoad = 40 ∧
    code .movbeStore = 41 ∧
    code .loadXmm0 = 48 ∧
    code .storeXmm0 = 49 ∧
    code .lea = 9 ∧
    code .aluMem = 35 ∧
    code .aluMemUnary = 50 ∧
    code .aluMemImm = 51 ∧
    code .aluMemReg = 54 ∧
    code .cmpRegMem = 36 ∧
    code .cmov = 21 ∧
    code .cmovMem = 64 ∧
    code .setcc = 22 ∧
    code .setccMem = 62 ∧
    code .bswap = 23 ∧
    code .popcnt = 24 ∧
    code .shiftx = 38 ∧
    code .shiftxMem = 42 ∧
    code .rorx = 39 ∧
    code .rorxMem = 43 ∧
    code .bzhi = 52 ∧
    code .bzhiMem = 53 ∧
    code .bt = 55 ∧
    code .btImm = 66 ∧
    code .btMemImm = 67 ∧
    code .imulImm = 56 ∧
    code .imulMemImm = 65 ∧
    code .mulx = 57 ∧
    code .repMovs = 58 ∧
    code .andn = 61 ∧
    code .andnMem = 68 ∧
    code .xchg = 25 ∧
    code .div = 26 ∧
    code .push = 18 ∧
    code .pop = 19 := by
  decide

/-- Every singleton opcode lies inside the numeric range the C opcode byte can
address. -/
theorem x86_singleton_code_in_range (op : SingletonOp) :
    code op ≤ 70 := by
  cases op <;> decide

/-- The forty-three singleton opcodes are pairwise distinct, so no opcode is
gated by two singleton arms. -/
theorem x86_singleton_codes_nodup :
    (x86SingletonOps.map code).Nodup := by
  decide

/-- Cross-contract: no opcode is gated by both a singleton arm and one of the
ten dispatch families, so the full `X86_SIM_L_EXEC` chain selects exactly one
arm per opcode. Stated as non-duplication of the combined generated
opcode-number list. -/
theorem x86_dispatch_chain_codes_nodup :
    (x86SingletonOps.map code ++
     x86DispatchOps.map GeneratedX86DispatchFamily.code).Nodup := by
  decide

/-- Canonical example: the NOP singleton is a singleton member. -/
theorem x86_disp_singleton_nop_example :
    x86DispNopSpec .nop = true := by
  decide

/-- Canonical example: the SETCC opcode is not the DIV singleton. -/
theorem x86_disp_singleton_div_setcc_example :
    x86DispDivSpec .setcc = false := by
  decide

/-- Canonical example: the POP singleton is a singleton member. -/
theorem x86_disp_singleton_pop_example :
    x86DispPopSpec .pop = true := by
  decide

end KProgFormal
