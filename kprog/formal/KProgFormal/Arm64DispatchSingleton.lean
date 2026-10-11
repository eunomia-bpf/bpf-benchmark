import KProgFormal.GeneratedArm64DispatchSingleton
import KProgFormal.Arm64DispatchFamily
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64DispatchSingleton (SingletonOp code nopHandled movkHandled
  bitfieldHandled cmnImmHandled cmnRegHandled tstBicRegHandled bicsRegHandled
  loadHandled storeHandled ldpHandled stpHandled loadD0Handled storeD0Handled
  loadQ0Handled storeQ0Handled fmovHandled)

/-- The NOP singleton, named independently of the generated `nopHandled`
match. -/
def arm64DispNopOps : List SingletonOp := [.nop]

/-- The MOVK singleton. -/
def arm64DispMovkOps : List SingletonOp := [.movk]

/-- The BITFIELD singleton. -/
def arm64DispBitfieldOps : List SingletonOp := [.bitfield]

/-- The CMN-immediate singleton. -/
def arm64DispCmnImmOps : List SingletonOp := [.cmnImm]

/-- The CMN-register singleton. -/
def arm64DispCmnRegOps : List SingletonOp := [.cmnReg]

/-- The TST_BIC-register singleton. -/
def arm64DispTstBicRegOps : List SingletonOp := [.tstBicReg]

/-- The BICS-register singleton. -/
def arm64DispBicsRegOps : List SingletonOp := [.bicsReg]

/-- The LOAD singleton. -/
def arm64DispLoadOps : List SingletonOp := [.load]

/-- The STORE singleton. -/
def arm64DispStoreOps : List SingletonOp := [.store]

/-- The LDP singleton. -/
def arm64DispLdpOps : List SingletonOp := [.ldp]

/-- The STP singleton. -/
def arm64DispStpOps : List SingletonOp := [.stp]

/-- The LOAD_D0 singleton. -/
def arm64DispLoadD0Ops : List SingletonOp := [.loadD0]

/-- The STORE_D0 singleton. -/
def arm64DispStoreD0Ops : List SingletonOp := [.storeD0]

/-- The LOAD_Q0 singleton. -/
def arm64DispLoadQ0Ops : List SingletonOp := [.loadQ0]

/-- The STORE_Q0 singleton. -/
def arm64DispStoreQ0Ops : List SingletonOp := [.storeQ0]

/-- The FMOV singleton. -/
def arm64DispFmovOps : List SingletonOp := [.fmov]

/-- Every singleton opcode, in dispatcher order. -/
def arm64SingletonOps : List SingletonOp :=
  arm64DispNopOps ++ arm64DispMovkOps ++ arm64DispBitfieldOps ++
  arm64DispCmnImmOps ++ arm64DispCmnRegOps ++ arm64DispTstBicRegOps ++
  arm64DispBicsRegOps ++ arm64DispLoadOps ++ arm64DispStoreOps ++
  arm64DispLdpOps ++ arm64DispStpOps ++ arm64DispLoadD0Ops ++
  arm64DispStoreD0Ops ++ arm64DispLoadQ0Ops ++ arm64DispStoreQ0Ops ++
  arm64DispFmovOps

/-- Independent NOP membership: the opcode is the one named NOP member.
Structurally separate from the generated `op == .nop` test. -/
def arm64DispNopSpec (op : SingletonOp) : Bool := op ∈ arm64DispNopOps

/-- Independent MOVK membership. -/
def arm64DispMovkSpec (op : SingletonOp) : Bool := op ∈ arm64DispMovkOps

/-- Independent BITFIELD membership. -/
def arm64DispBitfieldSpec (op : SingletonOp) : Bool := op ∈ arm64DispBitfieldOps

/-- Independent CMN-immediate membership. -/
def arm64DispCmnImmSpec (op : SingletonOp) : Bool := op ∈ arm64DispCmnImmOps

/-- Independent CMN-register membership. -/
def arm64DispCmnRegSpec (op : SingletonOp) : Bool := op ∈ arm64DispCmnRegOps

/-- Independent TST_BIC-register membership. -/
def arm64DispTstBicRegSpec (op : SingletonOp) : Bool := op ∈ arm64DispTstBicRegOps

/-- Independent BICS-register membership. -/
def arm64DispBicsRegSpec (op : SingletonOp) : Bool := op ∈ arm64DispBicsRegOps

/-- Independent LOAD membership. -/
def arm64DispLoadSpec (op : SingletonOp) : Bool := op ∈ arm64DispLoadOps

/-- Independent STORE membership. -/
def arm64DispStoreSpec (op : SingletonOp) : Bool := op ∈ arm64DispStoreOps

/-- Independent LDP membership. -/
def arm64DispLdpSpec (op : SingletonOp) : Bool := op ∈ arm64DispLdpOps

/-- Independent STP membership. -/
def arm64DispStpSpec (op : SingletonOp) : Bool := op ∈ arm64DispStpOps

/-- Independent LOAD_D0 membership. -/
def arm64DispLoadD0Spec (op : SingletonOp) : Bool := op ∈ arm64DispLoadD0Ops

/-- Independent STORE_D0 membership. -/
def arm64DispStoreD0Spec (op : SingletonOp) : Bool := op ∈ arm64DispStoreD0Ops

/-- Independent LOAD_Q0 membership. -/
def arm64DispLoadQ0Spec (op : SingletonOp) : Bool := op ∈ arm64DispLoadQ0Ops

/-- Independent STORE_Q0 membership. -/
def arm64DispStoreQ0Spec (op : SingletonOp) : Bool := op ∈ arm64DispStoreQ0Ops

/-- Independent FMOV membership. -/
def arm64DispFmovSpec (op : SingletonOp) : Bool := op ∈ arm64DispFmovOps

/-- The generated NOP membership table agrees with the independent statement. -/
theorem arm64_disp_singleton_nop_refines (op : SingletonOp) :
    nopHandled op = arm64DispNopSpec op := by
  cases op <;> decide

/-- The generated MOVK membership table agrees with the independent statement. -/
theorem arm64_disp_singleton_movk_refines (op : SingletonOp) :
    movkHandled op = arm64DispMovkSpec op := by
  cases op <;> decide

/-- The generated BITFIELD membership table agrees with the independent
statement. -/
theorem arm64_disp_singleton_bitfield_refines (op : SingletonOp) :
    bitfieldHandled op = arm64DispBitfieldSpec op := by
  cases op <;> decide

/-- The generated CMN-immediate membership table agrees with the independent
statement. -/
theorem arm64_disp_singleton_cmn_imm_refines (op : SingletonOp) :
    cmnImmHandled op = arm64DispCmnImmSpec op := by
  cases op <;> decide

/-- The generated CMN-register membership table agrees with the independent
statement. -/
theorem arm64_disp_singleton_cmn_reg_refines (op : SingletonOp) :
    cmnRegHandled op = arm64DispCmnRegSpec op := by
  cases op <;> decide

/-- The generated TST_BIC-register membership table agrees with the independent
statement. -/
theorem arm64_disp_singleton_tst_bic_reg_refines (op : SingletonOp) :
    tstBicRegHandled op = arm64DispTstBicRegSpec op := by
  cases op <;> decide

/-- The generated BICS-register membership table agrees with the independent
statement. -/
theorem arm64_disp_singleton_bics_reg_refines (op : SingletonOp) :
    bicsRegHandled op = arm64DispBicsRegSpec op := by
  cases op <;> decide

/-- The generated LOAD membership table agrees with the independent statement. -/
theorem arm64_disp_singleton_load_refines (op : SingletonOp) :
    loadHandled op = arm64DispLoadSpec op := by
  cases op <;> decide

/-- The generated STORE membership table agrees with the independent statement. -/
theorem arm64_disp_singleton_store_refines (op : SingletonOp) :
    storeHandled op = arm64DispStoreSpec op := by
  cases op <;> decide

/-- The generated LDP membership table agrees with the independent statement. -/
theorem arm64_disp_singleton_ldp_refines (op : SingletonOp) :
    ldpHandled op = arm64DispLdpSpec op := by
  cases op <;> decide

/-- The generated STP membership table agrees with the independent statement. -/
theorem arm64_disp_singleton_stp_refines (op : SingletonOp) :
    stpHandled op = arm64DispStpSpec op := by
  cases op <;> decide

/-- The generated LOAD_D0 membership table agrees with the independent
statement. -/
theorem arm64_disp_singleton_load_d0_refines (op : SingletonOp) :
    loadD0Handled op = arm64DispLoadD0Spec op := by
  cases op <;> decide

/-- The generated STORE_D0 membership table agrees with the independent
statement. -/
theorem arm64_disp_singleton_store_d0_refines (op : SingletonOp) :
    storeD0Handled op = arm64DispStoreD0Spec op := by
  cases op <;> decide

/-- The generated LOAD_Q0 membership table agrees with the independent
statement. -/
theorem arm64_disp_singleton_load_q0_refines (op : SingletonOp) :
    loadQ0Handled op = arm64DispLoadQ0Spec op := by
  cases op <;> decide

/-- The generated STORE_Q0 membership table agrees with the independent
statement. -/
theorem arm64_disp_singleton_store_q0_refines (op : SingletonOp) :
    storeQ0Handled op = arm64DispStoreQ0Spec op := by
  cases op <;> decide

/-- The generated FMOV membership table agrees with the independent statement. -/
theorem arm64_disp_singleton_fmov_refines (op : SingletonOp) :
    fmovHandled op = arm64DispFmovSpec op := by
  cases op <;> decide

/-- A generated singleton membership test holds exactly when the opcode is a
member of the singleton's named list. -/
theorem arm64_singleton_handled_iff_mem (op : SingletonOp) :
    (nopHandled op = true ↔ op ∈ arm64DispNopOps) ∧
    (movkHandled op = true ↔ op ∈ arm64DispMovkOps) ∧
    (bitfieldHandled op = true ↔ op ∈ arm64DispBitfieldOps) ∧
    (cmnImmHandled op = true ↔ op ∈ arm64DispCmnImmOps) ∧
    (cmnRegHandled op = true ↔ op ∈ arm64DispCmnRegOps) ∧
    (tstBicRegHandled op = true ↔ op ∈ arm64DispTstBicRegOps) ∧
    (bicsRegHandled op = true ↔ op ∈ arm64DispBicsRegOps) ∧
    (loadHandled op = true ↔ op ∈ arm64DispLoadOps) ∧
    (storeHandled op = true ↔ op ∈ arm64DispStoreOps) ∧
    (ldpHandled op = true ↔ op ∈ arm64DispLdpOps) ∧
    (stpHandled op = true ↔ op ∈ arm64DispStpOps) ∧
    (loadD0Handled op = true ↔ op ∈ arm64DispLoadD0Ops) ∧
    (storeD0Handled op = true ↔ op ∈ arm64DispStoreD0Ops) ∧
    (loadQ0Handled op = true ↔ op ∈ arm64DispLoadQ0Ops) ∧
    (storeQ0Handled op = true ↔ op ∈ arm64DispStoreQ0Ops) ∧
    (fmovHandled op = true ↔ op ∈ arm64DispFmovOps) := by
  cases op <;> decide

/-- A singleton member is dispatched exactly when the generated table names it:
the hypothesis-taking form the C gate's truth is decided by. -/
theorem arm64_singleton_member_handled (op : SingletonOp)
    (h : op ∈ arm64SingletonOps) :
    nopHandled op || movkHandled op || bitfieldHandled op || cmnImmHandled op ||
    cmnRegHandled op || tstBicRegHandled op || bicsRegHandled op ||
    loadHandled op || storeHandled op || ldpHandled op || stpHandled op ||
    loadD0Handled op || storeD0Handled op || loadQ0Handled op ||
    storeQ0Handled op || fmovHandled op = true := by
  cases op <;>
    simp_all [arm64SingletonOps, arm64DispNopOps, arm64DispMovkOps,
              arm64DispBitfieldOps, arm64DispCmnImmOps, arm64DispCmnRegOps,
              arm64DispTstBicRegOps, arm64DispBicsRegOps, arm64DispLoadOps,
              arm64DispStoreOps, arm64DispLdpOps, arm64DispStpOps,
              arm64DispLoadD0Ops, arm64DispStoreD0Ops, arm64DispLoadQ0Ops,
              arm64DispStoreQ0Ops, arm64DispFmovOps, nopHandled, movkHandled,
              bitfieldHandled, cmnImmHandled, cmnRegHandled, tstBicRegHandled,
              bicsRegHandled, loadHandled, storeHandled, ldpHandled, stpHandled,
              loadD0Handled, storeD0Handled, loadQ0Handled, storeQ0Handled,
              fmovHandled]

/-- An opcode outside every singleton is handled by no generated singleton
test, so the dispatcher reaches its unsupported arm. -/
theorem arm64_singleton_nonmember_unhandled (op : SingletonOp)
    (h : op ∉ arm64SingletonOps) :
    nopHandled op = false ∧ movkHandled op = false ∧
    bitfieldHandled op = false ∧ cmnImmHandled op = false ∧
    cmnRegHandled op = false ∧ tstBicRegHandled op = false ∧
    bicsRegHandled op = false ∧ loadHandled op = false ∧
    storeHandled op = false ∧ ldpHandled op = false ∧
    stpHandled op = false ∧ loadD0Handled op = false ∧
    storeD0Handled op = false ∧ loadQ0Handled op = false ∧
    storeQ0Handled op = false ∧ fmovHandled op = false := by
  cases op <;>
    simp_all [arm64SingletonOps, arm64DispNopOps, arm64DispMovkOps,
              arm64DispBitfieldOps, arm64DispCmnImmOps, arm64DispCmnRegOps,
              arm64DispTstBicRegOps, arm64DispBicsRegOps, arm64DispLoadOps,
              arm64DispStoreOps, arm64DispLdpOps, arm64DispStpOps,
              arm64DispLoadD0Ops, arm64DispStoreD0Ops, arm64DispLoadQ0Ops,
              arm64DispStoreQ0Ops, arm64DispFmovOps, nopHandled, movkHandled,
              bitfieldHandled, cmnImmHandled, cmnRegHandled, tstBicRegHandled,
              bicsRegHandled, loadHandled, storeHandled, ldpHandled, stpHandled,
              loadD0Handled, storeD0Handled, loadQ0Handled, storeQ0Handled,
              fmovHandled]

/-- The generated code dispatch: the sixteen singleton mnemonics map onto the
sixteen ARM64_OP_* opcode numbers the C gates compare against. -/
theorem arm64_singleton_code_dispatch :
    code .nop = 0 ∧ code .movk = 5 ∧ code .bitfield = 18 ∧
    code .cmnImm = 51 ∧ code .cmnReg = 58 ∧ code .tstBicReg = 44 ∧
    code .bicsReg = 67 ∧ code .load = 31 ∧ code .store = 32 ∧
    code .ldp = 33 ∧ code .stp = 34 ∧ code .loadD0 = 40 ∧
    code .storeD0 = 41 ∧ code .loadQ0 = 42 ∧ code .storeQ0 = 43 ∧
    code .fmov = 35 := by
  decide

/-- Every singleton opcode lies inside the numeric range the C opcode byte can
address. -/
theorem arm64_singleton_code_in_range (op : SingletonOp) :
    code op ≤ 67 := by
  cases op <;> decide

/-- The sixteen singleton opcodes are pairwise distinct, so no opcode is gated
by two singleton arms. -/
theorem arm64_singleton_codes_nodup :
    (arm64SingletonOps.map code).Nodup := by
  decide

/-- Cross-contract: no opcode is gated by both a singleton arm and an
immediate/register dispatch family, so the full `ARM64_SIM_L_EXEC` chain selects
exactly one arm per opcode. Stated as non-duplication of the combined generated
opcode-number list. -/
theorem arm64_dispatch_chain_codes_nodup :
    (arm64SingletonOps.map code ++
     arm64DispatchOps.map GeneratedArm64DispatchFamily.code).Nodup := by
  decide

/-- Canonical example: the NOP singleton is a singleton member. -/
theorem arm64_disp_singleton_nop_example :
    arm64DispNopSpec .nop = true := by
  decide

/-- Canonical example: the LOAD singleton is not the STORE singleton. -/
theorem arm64_disp_singleton_load_store_example :
    arm64DispLoadSpec .store = false := by
  decide

/-- Canonical example: the FMOV singleton is a singleton member. -/
theorem arm64_disp_singleton_fmov_example :
    arm64DispFmovSpec .fmov = true := by
  decide

end KProgFormal
