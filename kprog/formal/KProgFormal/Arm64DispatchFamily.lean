import KProgFormal.GeneratedArm64DispatchFamily
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64DispatchFamily (DispatchOp code aluHandled shiftOpHandled
  subsHandled addsHandled cmpHandled tstHandled andsHandled ccmpHandled)

/-- The ALU pair members, named independently of the generated `aluHandled`
match. -/
def arm64DispAluOps : List DispatchOp := [.aluImm, .aluReg]

/-- The SHIFT pair members. -/
def arm64DispShiftOps : List DispatchOp := [.shiftImm, .shiftReg]

/-- The SUBS pair members. -/
def arm64DispSubsOps : List DispatchOp := [.subsImm, .subsReg]

/-- The ADDS pair members. -/
def arm64DispAddsOps : List DispatchOp := [.addsImm, .addsReg]

/-- The CMP pair members. -/
def arm64DispCmpOps : List DispatchOp := [.cmpImm, .cmpReg]

/-- The TST pair members. -/
def arm64DispTstOps : List DispatchOp := [.tstImm, .tstReg]

/-- The ANDS pair members. -/
def arm64DispAndsOps : List DispatchOp := [.andsReg, .andsImm]

/-- The CCMP pair members. -/
def arm64DispCcmpOps : List DispatchOp := [.ccmpImm, .ccmpReg]

/-- Every opcode of the eight dispatch families. -/
def arm64DispatchOps : List DispatchOp :=
  arm64DispAluOps ++ arm64DispShiftOps ++ arm64DispSubsOps ++ arm64DispAddsOps ++
  arm64DispCmpOps ++ arm64DispTstOps ++ arm64DispAndsOps ++ arm64DispCcmpOps

/-- Independent statement of the ALU family membership: the opcode is one of the
two named ALU members. Structurally separate from the generated disjunction: a
membership test over a named list rather than a chain of constructor
comparisons. -/
def arm64DispAluSpec (op : DispatchOp) : Bool := op ∈ arm64DispAluOps

/-- Independent SHIFT family membership. -/
def arm64DispShiftSpec (op : DispatchOp) : Bool := op ∈ arm64DispShiftOps

/-- Independent SUBS family membership. -/
def arm64DispSubsSpec (op : DispatchOp) : Bool := op ∈ arm64DispSubsOps

/-- Independent ADDS family membership. -/
def arm64DispAddsSpec (op : DispatchOp) : Bool := op ∈ arm64DispAddsOps

/-- Independent CMP family membership. -/
def arm64DispCmpSpec (op : DispatchOp) : Bool := op ∈ arm64DispCmpOps

/-- Independent TST family membership. -/
def arm64DispTstSpec (op : DispatchOp) : Bool := op ∈ arm64DispTstOps

/-- Independent ANDS family membership. -/
def arm64DispAndsSpec (op : DispatchOp) : Bool := op ∈ arm64DispAndsOps

/-- Independent CCMP family membership. -/
def arm64DispCcmpSpec (op : DispatchOp) : Bool := op ∈ arm64DispCcmpOps

/-- The generated ALU membership table agrees with the independent list
membership statement on all sixteen opcodes. -/
theorem arm64_dispatch_alu_refines (op : DispatchOp) :
    aluHandled op = arm64DispAluSpec op := by
  cases op <;> decide

/-- The generated SHIFT membership table agrees with the independent statement. -/
theorem arm64_dispatch_shift_refines (op : DispatchOp) :
    shiftOpHandled op = arm64DispShiftSpec op := by
  cases op <;> decide

/-- The generated SUBS membership table agrees with the independent statement. -/
theorem arm64_dispatch_subs_refines (op : DispatchOp) :
    subsHandled op = arm64DispSubsSpec op := by
  cases op <;> decide

/-- The generated ADDS membership table agrees with the independent statement. -/
theorem arm64_dispatch_adds_refines (op : DispatchOp) :
    addsHandled op = arm64DispAddsSpec op := by
  cases op <;> decide

/-- The generated CMP membership table agrees with the independent statement. -/
theorem arm64_dispatch_cmp_refines (op : DispatchOp) :
    cmpHandled op = arm64DispCmpSpec op := by
  cases op <;> decide

/-- The generated TST membership table agrees with the independent statement. -/
theorem arm64_dispatch_tst_refines (op : DispatchOp) :
    tstHandled op = arm64DispTstSpec op := by
  cases op <;> decide

/-- The generated ANDS membership table agrees with the independent statement. -/
theorem arm64_dispatch_ands_refines (op : DispatchOp) :
    andsHandled op = arm64DispAndsSpec op := by
  cases op <;> decide

/-- The generated CCMP membership table agrees with the independent statement. -/
theorem arm64_dispatch_ccmp_refines (op : DispatchOp) :
    ccmpHandled op = arm64DispCcmpSpec op := by
  cases op <;> decide

/-- A generated membership test holds exactly when the opcode is a member of the
family's named list. -/
theorem arm64_dispatch_handled_iff_mem (op : DispatchOp) :
    (aluHandled op = true ↔ op ∈ arm64DispAluOps) ∧
    (shiftOpHandled op = true ↔ op ∈ arm64DispShiftOps) ∧
    (subsHandled op = true ↔ op ∈ arm64DispSubsOps) ∧
    (addsHandled op = true ↔ op ∈ arm64DispAddsOps) ∧
    (cmpHandled op = true ↔ op ∈ arm64DispCmpOps) ∧
    (tstHandled op = true ↔ op ∈ arm64DispTstOps) ∧
    (andsHandled op = true ↔ op ∈ arm64DispAndsOps) ∧
    (ccmpHandled op = true ↔ op ∈ arm64DispCcmpOps) := by
  cases op <;> decide

/-- No two of the eight dispatch families overlap: the dispatcher's ordered
membership chain has at most one taken gate per opcode. -/
theorem arm64_dispatch_families_disjoint (op : DispatchOp) :
    ¬ ((op ∈ arm64DispAluOps ∧ op ∈ arm64DispShiftOps) ∨
       (op ∈ arm64DispAluOps ∧ op ∈ arm64DispSubsOps) ∨
       (op ∈ arm64DispAluOps ∧ op ∈ arm64DispAddsOps) ∨
       (op ∈ arm64DispAluOps ∧ op ∈ arm64DispCmpOps) ∨
       (op ∈ arm64DispAluOps ∧ op ∈ arm64DispTstOps) ∨
       (op ∈ arm64DispAluOps ∧ op ∈ arm64DispAndsOps) ∨
       (op ∈ arm64DispAluOps ∧ op ∈ arm64DispCcmpOps) ∨
       (op ∈ arm64DispShiftOps ∧ op ∈ arm64DispSubsOps) ∨
       (op ∈ arm64DispShiftOps ∧ op ∈ arm64DispAddsOps) ∨
       (op ∈ arm64DispShiftOps ∧ op ∈ arm64DispCmpOps) ∨
       (op ∈ arm64DispShiftOps ∧ op ∈ arm64DispTstOps) ∨
       (op ∈ arm64DispShiftOps ∧ op ∈ arm64DispAndsOps) ∨
       (op ∈ arm64DispShiftOps ∧ op ∈ arm64DispCcmpOps) ∨
       (op ∈ arm64DispSubsOps ∧ op ∈ arm64DispAddsOps) ∨
       (op ∈ arm64DispSubsOps ∧ op ∈ arm64DispCmpOps) ∨
       (op ∈ arm64DispSubsOps ∧ op ∈ arm64DispTstOps) ∨
       (op ∈ arm64DispSubsOps ∧ op ∈ arm64DispAndsOps) ∨
       (op ∈ arm64DispSubsOps ∧ op ∈ arm64DispCcmpOps) ∨
       (op ∈ arm64DispAddsOps ∧ op ∈ arm64DispCmpOps) ∨
       (op ∈ arm64DispAddsOps ∧ op ∈ arm64DispTstOps) ∨
       (op ∈ arm64DispAddsOps ∧ op ∈ arm64DispAndsOps) ∨
       (op ∈ arm64DispAddsOps ∧ op ∈ arm64DispCcmpOps) ∨
       (op ∈ arm64DispCmpOps ∧ op ∈ arm64DispTstOps) ∨
       (op ∈ arm64DispCmpOps ∧ op ∈ arm64DispAndsOps) ∨
       (op ∈ arm64DispCmpOps ∧ op ∈ arm64DispCcmpOps) ∨
       (op ∈ arm64DispTstOps ∧ op ∈ arm64DispAndsOps) ∨
       (op ∈ arm64DispTstOps ∧ op ∈ arm64DispCcmpOps) ∨
       (op ∈ arm64DispAndsOps ∧ op ∈ arm64DispCcmpOps)) := by
  cases op <;>
    simp [arm64DispAluOps, arm64DispShiftOps, arm64DispSubsOps, arm64DispAddsOps,
          arm64DispCmpOps, arm64DispTstOps, arm64DispAndsOps, arm64DispCcmpOps]

/-- A family member is dispatched exactly when the generated table names it: the
hypothesis-taking form the C `_HANDLED` macro's truth is decided by. -/
theorem arm64_dispatch_member_handled (op : DispatchOp)
    (h : op ∈ arm64DispatchOps) :
    aluHandled op || shiftOpHandled op || subsHandled op || addsHandled op ||
    cmpHandled op || tstHandled op || andsHandled op || ccmpHandled op =
    true := by
  cases op <;>
    simp_all [arm64DispatchOps, arm64DispAluOps, arm64DispShiftOps, arm64DispSubsOps,
              arm64DispAddsOps, arm64DispCmpOps, arm64DispTstOps, arm64DispAndsOps,
              arm64DispCcmpOps, aluHandled, shiftOpHandled, subsHandled,
              addsHandled, cmpHandled, tstHandled, andsHandled, ccmpHandled]

/-- An opcode outside every dispatch family is handled by no generated membership
test, so the dispatcher reaches its unsupported arm. -/
theorem arm64_dispatch_nonmember_unhandled (op : DispatchOp)
    (h : op ∉ arm64DispatchOps) :
    aluHandled op = false ∧ shiftOpHandled op = false ∧
    subsHandled op = false ∧ addsHandled op = false ∧
    cmpHandled op = false ∧ tstHandled op = false ∧
    andsHandled op = false ∧ ccmpHandled op = false := by
  cases op <;>
    simp_all [arm64DispatchOps, arm64DispAluOps, arm64DispShiftOps, arm64DispSubsOps,
              arm64DispAddsOps, arm64DispCmpOps, arm64DispTstOps, arm64DispAndsOps,
              arm64DispCcmpOps, aluHandled, shiftOpHandled, subsHandled,
              addsHandled, cmpHandled, tstHandled, andsHandled, ccmpHandled]

/-- The generated code dispatch: the sixteen mnemonics map onto the sixteen
ARM64_OP_* opcode numbers the C macros compare against. -/
theorem arm64_dispatch_code_dispatch :
    code .aluImm = 6 ∧ code .aluReg = 7 ∧
    code .shiftImm = 8 ∧ code .shiftReg = 9 ∧
    code .subsImm = 48 ∧ code .subsReg = 50 ∧
    code .addsImm = 49 ∧ code .addsReg = 66 ∧
    code .cmpImm = 22 ∧ code .cmpReg = 23 ∧
    code .tstImm = 24 ∧ code .tstReg = 25 ∧
    code .andsReg = 45 ∧ code .andsImm = 55 ∧
    code .ccmpImm = 26 ∧ code .ccmpReg = 27 := by
  decide

/-- Every dispatch opcode lies inside the numeric range the C opcode byte can
address. -/
theorem arm64_dispatch_code_in_range (op : DispatchOp) :
    code op ≤ 66 := by
  cases op <;> decide

/-- Canonical example: the ALU immediate member is an ALU-family member. -/
theorem arm64_dispatch_alu_imm_example :
    arm64DispAluSpec .aluImm = true := by
  decide

/-- Canonical example: the ADDS register member is not an ALU-family member. -/
theorem arm64_dispatch_alu_adds_example :
    arm64DispAluSpec .addsReg = false := by
  decide

/-- Canonical example: the CCMP register member is a CCMP-family member. -/
theorem arm64_dispatch_ccmp_reg_example :
    arm64DispCcmpSpec .ccmpReg = true := by
  decide

end KProgFormal
