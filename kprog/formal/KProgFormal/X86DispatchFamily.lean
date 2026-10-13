import KProgFormal.GeneratedX86DispatchFamily
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedX86DispatchFamily (DispatchOp code
  movLoadPtrHandled movxRegHandled movLoadHandled movStoreHandled aluImmHandled aluRegHandled cmpImmHandled cmpRegHandled cmpMemHandled doubleShiftHandled)

/-- The movLoadPtr family members, named independently of the generated
`movLoadPtrHandled` match. -/
def x86DispMovLoadPtrOps : List DispatchOp := [.movLoadMapPtr, .movLoadHelperId]

/-- The movxReg family members, named independently of the generated
`movxRegHandled` match. -/
def x86DispMovxRegOps : List DispatchOp := [.movzxReg, .movsxReg]

/-- The movLoad family members, named independently of the generated
`movLoadHandled` match. -/
def x86DispMovLoadOps : List DispatchOp := [.movLoad, .movLoadScalar, .movsxLoad]

/-- The movStore family members, named independently of the generated
`movStoreHandled` match. -/
def x86DispMovStoreOps : List DispatchOp := [.movStoreImm, .movStoreReg]

/-- The aluImm family members, named independently of the generated
`aluImmHandled` match. -/
def x86DispAluImmOps : List DispatchOp := [.aluImm, .addImm]

/-- The aluReg family members, named independently of the generated
`aluRegHandled` match. -/
def x86DispAluRegOps : List DispatchOp := [.aluReg, .addReg, .xorReg]

/-- The cmpImm family members, named independently of the generated
`cmpImmHandled` match. -/
def x86DispCmpImmOps : List DispatchOp := [.cmpImm, .testImm]

/-- The cmpReg family members, named independently of the generated
`cmpRegHandled` match. -/
def x86DispCmpRegOps : List DispatchOp := [.cmpReg, .testReg]

/-- The cmpMem family members, named independently of the generated
`cmpMemHandled` match. -/
def x86DispCmpMemOps : List DispatchOp := [.cmpMemImm, .testMemImm, .cmpMemReg, .testMemReg]

/-- The doubleShift family members, named independently of the generated
`doubleShiftHandled` match. -/
def x86DispDoubleShiftOps : List DispatchOp := [.shldImm, .shrdImm]

/-- Every opcode of the ten dispatch families. -/
def x86DispatchOps : List DispatchOp :=
  x86DispMovLoadPtrOps ++
  x86DispMovxRegOps ++
  x86DispMovLoadOps ++
  x86DispMovStoreOps ++
  x86DispAluImmOps ++
  x86DispAluRegOps ++
  x86DispCmpImmOps ++
  x86DispCmpRegOps ++
  x86DispCmpMemOps ++
  x86DispDoubleShiftOps

/-- Independent statement of the movLoadPtr family membership: the opcode is one of
the named movLoadPtr members. Structurally separate from the generated disjunction: a
membership test over a named list rather than a chain of constructor
comparisons. -/
def x86DispMovLoadPtrSpec (op : DispatchOp) : Bool := op ∈ x86DispMovLoadPtrOps

/-- Independent statement of the movxReg family membership: the opcode is one of
the named movxReg members. Structurally separate from the generated disjunction: a
membership test over a named list rather than a chain of constructor
comparisons. -/
def x86DispMovxRegSpec (op : DispatchOp) : Bool := op ∈ x86DispMovxRegOps

/-- Independent statement of the movLoad family membership: the opcode is one of
the named movLoad members. Structurally separate from the generated disjunction: a
membership test over a named list rather than a chain of constructor
comparisons. -/
def x86DispMovLoadSpec (op : DispatchOp) : Bool := op ∈ x86DispMovLoadOps

/-- Independent statement of the movStore family membership: the opcode is one of
the named movStore members. Structurally separate from the generated disjunction: a
membership test over a named list rather than a chain of constructor
comparisons. -/
def x86DispMovStoreSpec (op : DispatchOp) : Bool := op ∈ x86DispMovStoreOps

/-- Independent statement of the aluImm family membership: the opcode is one of
the named aluImm members. Structurally separate from the generated disjunction: a
membership test over a named list rather than a chain of constructor
comparisons. -/
def x86DispAluImmSpec (op : DispatchOp) : Bool := op ∈ x86DispAluImmOps

/-- Independent statement of the aluReg family membership: the opcode is one of
the named aluReg members. Structurally separate from the generated disjunction: a
membership test over a named list rather than a chain of constructor
comparisons. -/
def x86DispAluRegSpec (op : DispatchOp) : Bool := op ∈ x86DispAluRegOps

/-- Independent statement of the cmpImm family membership: the opcode is one of
the named cmpImm members. Structurally separate from the generated disjunction: a
membership test over a named list rather than a chain of constructor
comparisons. -/
def x86DispCmpImmSpec (op : DispatchOp) : Bool := op ∈ x86DispCmpImmOps

/-- Independent statement of the cmpReg family membership: the opcode is one of
the named cmpReg members. Structurally separate from the generated disjunction: a
membership test over a named list rather than a chain of constructor
comparisons. -/
def x86DispCmpRegSpec (op : DispatchOp) : Bool := op ∈ x86DispCmpRegOps

/-- Independent statement of the cmpMem family membership: the opcode is one of
the named cmpMem members. Structurally separate from the generated disjunction: a
membership test over a named list rather than a chain of constructor
comparisons. -/
def x86DispCmpMemSpec (op : DispatchOp) : Bool := op ∈ x86DispCmpMemOps

/-- Independent statement of the doubleShift family membership: the opcode is one of
the named doubleShift members. Structurally separate from the generated disjunction: a
membership test over a named list rather than a chain of constructor
comparisons. -/
def x86DispDoubleShiftSpec (op : DispatchOp) : Bool := op ∈ x86DispDoubleShiftOps

/-- The generated movLoadPtr membership table agrees with the independent list
membership statement on all twenty-four opcodes. -/
theorem x86_dispatch_movLoadPtr_refines (op : DispatchOp) :
    movLoadPtrHandled op = x86DispMovLoadPtrSpec op := by
  cases op <;> decide

/-- The generated movxReg membership table agrees with the independent list
membership statement on all twenty-four opcodes. -/
theorem x86_dispatch_movxReg_refines (op : DispatchOp) :
    movxRegHandled op = x86DispMovxRegSpec op := by
  cases op <;> decide

/-- The generated movLoad membership table agrees with the independent list
membership statement on all twenty-four opcodes. -/
theorem x86_dispatch_movLoad_refines (op : DispatchOp) :
    movLoadHandled op = x86DispMovLoadSpec op := by
  cases op <;> decide

/-- The generated movStore membership table agrees with the independent list
membership statement on all twenty-four opcodes. -/
theorem x86_dispatch_movStore_refines (op : DispatchOp) :
    movStoreHandled op = x86DispMovStoreSpec op := by
  cases op <;> decide

/-- The generated aluImm membership table agrees with the independent list
membership statement on all twenty-four opcodes. -/
theorem x86_dispatch_aluImm_refines (op : DispatchOp) :
    aluImmHandled op = x86DispAluImmSpec op := by
  cases op <;> decide

/-- The generated aluReg membership table agrees with the independent list
membership statement on all twenty-four opcodes. -/
theorem x86_dispatch_aluReg_refines (op : DispatchOp) :
    aluRegHandled op = x86DispAluRegSpec op := by
  cases op <;> decide

/-- The generated cmpImm membership table agrees with the independent list
membership statement on all twenty-four opcodes. -/
theorem x86_dispatch_cmpImm_refines (op : DispatchOp) :
    cmpImmHandled op = x86DispCmpImmSpec op := by
  cases op <;> decide

/-- The generated cmpReg membership table agrees with the independent list
membership statement on all twenty-four opcodes. -/
theorem x86_dispatch_cmpReg_refines (op : DispatchOp) :
    cmpRegHandled op = x86DispCmpRegSpec op := by
  cases op <;> decide

/-- The generated cmpMem membership table agrees with the independent list
membership statement on all twenty-four opcodes. -/
theorem x86_dispatch_cmpMem_refines (op : DispatchOp) :
    cmpMemHandled op = x86DispCmpMemSpec op := by
  cases op <;> decide

/-- The generated doubleShift membership table agrees with the independent list
membership statement on all twenty-four opcodes. -/
theorem x86_dispatch_doubleShift_refines (op : DispatchOp) :
    doubleShiftHandled op = x86DispDoubleShiftSpec op := by
  cases op <;> decide

/-- A generated membership test holds exactly when the opcode is a member of the
family's named list. -/
theorem x86_dispatch_handled_iff_mem (op : DispatchOp) :
    (movLoadPtrHandled op = true ↔ op ∈ x86DispMovLoadPtrOps) ∧
    (movxRegHandled op = true ↔ op ∈ x86DispMovxRegOps) ∧
    (movLoadHandled op = true ↔ op ∈ x86DispMovLoadOps) ∧
    (movStoreHandled op = true ↔ op ∈ x86DispMovStoreOps) ∧
    (aluImmHandled op = true ↔ op ∈ x86DispAluImmOps) ∧
    (aluRegHandled op = true ↔ op ∈ x86DispAluRegOps) ∧
    (cmpImmHandled op = true ↔ op ∈ x86DispCmpImmOps) ∧
    (cmpRegHandled op = true ↔ op ∈ x86DispCmpRegOps) ∧
    (cmpMemHandled op = true ↔ op ∈ x86DispCmpMemOps) ∧
    (doubleShiftHandled op = true ↔ op ∈ x86DispDoubleShiftOps) := by
  cases op <;> decide
/-- No two of the ten dispatch families overlap: the dispatcher's ordered
membership chain has at most one taken gate per opcode. -/
theorem x86_dispatch_families_disjoint (op : DispatchOp) :
    ¬ ((op ∈ x86DispMovLoadPtrOps ∧ op ∈ x86DispMovxRegOps) ∨
       (op ∈ x86DispMovLoadPtrOps ∧ op ∈ x86DispMovLoadOps) ∨
       (op ∈ x86DispMovLoadPtrOps ∧ op ∈ x86DispMovStoreOps) ∨
       (op ∈ x86DispMovLoadPtrOps ∧ op ∈ x86DispAluImmOps) ∨
       (op ∈ x86DispMovLoadPtrOps ∧ op ∈ x86DispAluRegOps) ∨
       (op ∈ x86DispMovLoadPtrOps ∧ op ∈ x86DispCmpImmOps) ∨
       (op ∈ x86DispMovLoadPtrOps ∧ op ∈ x86DispCmpRegOps) ∨
       (op ∈ x86DispMovLoadPtrOps ∧ op ∈ x86DispCmpMemOps) ∨
       (op ∈ x86DispMovLoadPtrOps ∧ op ∈ x86DispDoubleShiftOps) ∨
       (op ∈ x86DispMovxRegOps ∧ op ∈ x86DispMovLoadOps) ∨
       (op ∈ x86DispMovxRegOps ∧ op ∈ x86DispMovStoreOps) ∨
       (op ∈ x86DispMovxRegOps ∧ op ∈ x86DispAluImmOps) ∨
       (op ∈ x86DispMovxRegOps ∧ op ∈ x86DispAluRegOps) ∨
       (op ∈ x86DispMovxRegOps ∧ op ∈ x86DispCmpImmOps) ∨
       (op ∈ x86DispMovxRegOps ∧ op ∈ x86DispCmpRegOps) ∨
       (op ∈ x86DispMovxRegOps ∧ op ∈ x86DispCmpMemOps) ∨
       (op ∈ x86DispMovxRegOps ∧ op ∈ x86DispDoubleShiftOps) ∨
       (op ∈ x86DispMovLoadOps ∧ op ∈ x86DispMovStoreOps) ∨
       (op ∈ x86DispMovLoadOps ∧ op ∈ x86DispAluImmOps) ∨
       (op ∈ x86DispMovLoadOps ∧ op ∈ x86DispAluRegOps) ∨
       (op ∈ x86DispMovLoadOps ∧ op ∈ x86DispCmpImmOps) ∨
       (op ∈ x86DispMovLoadOps ∧ op ∈ x86DispCmpRegOps) ∨
       (op ∈ x86DispMovLoadOps ∧ op ∈ x86DispCmpMemOps) ∨
       (op ∈ x86DispMovLoadOps ∧ op ∈ x86DispDoubleShiftOps) ∨
       (op ∈ x86DispMovStoreOps ∧ op ∈ x86DispAluImmOps) ∨
       (op ∈ x86DispMovStoreOps ∧ op ∈ x86DispAluRegOps) ∨
       (op ∈ x86DispMovStoreOps ∧ op ∈ x86DispCmpImmOps) ∨
       (op ∈ x86DispMovStoreOps ∧ op ∈ x86DispCmpRegOps) ∨
       (op ∈ x86DispMovStoreOps ∧ op ∈ x86DispCmpMemOps) ∨
       (op ∈ x86DispMovStoreOps ∧ op ∈ x86DispDoubleShiftOps) ∨
       (op ∈ x86DispAluImmOps ∧ op ∈ x86DispAluRegOps) ∨
       (op ∈ x86DispAluImmOps ∧ op ∈ x86DispCmpImmOps) ∨
       (op ∈ x86DispAluImmOps ∧ op ∈ x86DispCmpRegOps) ∨
       (op ∈ x86DispAluImmOps ∧ op ∈ x86DispCmpMemOps) ∨
       (op ∈ x86DispAluImmOps ∧ op ∈ x86DispDoubleShiftOps) ∨
       (op ∈ x86DispAluRegOps ∧ op ∈ x86DispCmpImmOps) ∨
       (op ∈ x86DispAluRegOps ∧ op ∈ x86DispCmpRegOps) ∨
       (op ∈ x86DispAluRegOps ∧ op ∈ x86DispCmpMemOps) ∨
       (op ∈ x86DispAluRegOps ∧ op ∈ x86DispDoubleShiftOps) ∨
       (op ∈ x86DispCmpImmOps ∧ op ∈ x86DispCmpRegOps) ∨
       (op ∈ x86DispCmpImmOps ∧ op ∈ x86DispCmpMemOps) ∨
       (op ∈ x86DispCmpImmOps ∧ op ∈ x86DispDoubleShiftOps) ∨
       (op ∈ x86DispCmpRegOps ∧ op ∈ x86DispCmpMemOps) ∨
       (op ∈ x86DispCmpRegOps ∧ op ∈ x86DispDoubleShiftOps) ∨
       (op ∈ x86DispCmpMemOps ∧ op ∈ x86DispDoubleShiftOps)) := by
  cases op <;>
    simp [x86DispMovLoadPtrOps,
        x86DispMovxRegOps,
        x86DispMovLoadOps,
        x86DispMovStoreOps,
        x86DispAluImmOps,
        x86DispAluRegOps,
        x86DispCmpImmOps,
        x86DispCmpRegOps,
        x86DispCmpMemOps,
        x86DispDoubleShiftOps]

/-- A family member is dispatched exactly when the generated table names it: the
hypothesis-taking form the C `_HANDLED` macro's truth is decided by. -/
theorem x86_dispatch_member_handled (op : DispatchOp)
    (h : op ∈ x86DispatchOps) :
    movLoadPtrHandled op ||
    movxRegHandled op ||
    movLoadHandled op ||
    movStoreHandled op ||
    aluImmHandled op ||
    aluRegHandled op ||
    cmpImmHandled op ||
    cmpRegHandled op ||
    cmpMemHandled op ||
    doubleShiftHandled op =
    true := by
  cases op <;>
    simp_all [x86DispatchOps, x86DispMovLoadPtrOps,
              x86DispMovxRegOps,
              x86DispMovLoadOps,
              x86DispMovStoreOps,
              x86DispAluImmOps,
              x86DispAluRegOps,
              x86DispCmpImmOps,
              x86DispCmpRegOps,
              x86DispCmpMemOps,
              x86DispDoubleShiftOps,
              movLoadPtrHandled,
              movxRegHandled,
              movLoadHandled,
              movStoreHandled,
              aluImmHandled,
              aluRegHandled,
              cmpImmHandled,
              cmpRegHandled,
              cmpMemHandled,
              doubleShiftHandled]

/-- An opcode outside every dispatch family is handled by no generated membership
test, so the dispatcher reaches its unsupported arm. -/
theorem x86_dispatch_nonmember_unhandled (op : DispatchOp)
    (h : op ∉ x86DispatchOps) :
    movLoadPtrHandled op = false ∧
    movxRegHandled op = false ∧
    movLoadHandled op = false ∧
    movStoreHandled op = false ∧
    aluImmHandled op = false ∧
    aluRegHandled op = false ∧
    cmpImmHandled op = false ∧
    cmpRegHandled op = false ∧
    cmpMemHandled op = false ∧
    doubleShiftHandled op = false := by
  cases op <;>
    simp_all [x86DispatchOps, x86DispMovLoadPtrOps,
              x86DispMovxRegOps,
              x86DispMovLoadOps,
              x86DispMovStoreOps,
              x86DispAluImmOps,
              x86DispAluRegOps,
              x86DispCmpImmOps,
              x86DispCmpRegOps,
              x86DispCmpMemOps,
              x86DispDoubleShiftOps,
              movLoadPtrHandled,
              movxRegHandled,
              movLoadHandled,
              movStoreHandled,
              aluImmHandled,
              aluRegHandled,
              cmpImmHandled,
              cmpRegHandled,
              cmpMemHandled,
              doubleShiftHandled]

/-- The generated code dispatch: the twenty-four mnemonics map onto the
X86_OP_* opcode numbers the C macros compare against. -/
theorem x86_dispatch_code_dispatch :
    code .movLoadMapPtr = 44 ∧
    code .movLoadHelperId = 45 ∧
    code .movzxReg = 32 ∧
    code .movsxReg = 33 ∧
    code .movLoad = 6 ∧
    code .movLoadScalar = 37 ∧
    code .movsxLoad = 34 ∧
    code .movStoreImm = 7 ∧
    code .movStoreReg = 8 ∧
    code .aluImm = 10 ∧
    code .addImm = 3 ∧
    code .aluReg = 11 ∧
    code .addReg = 4 ∧
    code .xorReg = 5 ∧
    code .cmpImm = 12 ∧
    code .testImm = 14 ∧
    code .cmpReg = 13 ∧
    code .testReg = 15 ∧
    code .cmpMemImm = 29 ∧
    code .testMemImm = 30 ∧
    code .cmpMemReg = 31 ∧
    code .testMemReg = 59 ∧
    code .shldImm = 27 ∧
    code .shrdImm = 28 := by
  decide

/-- Every dispatch opcode lies inside the numeric range the C opcode byte can
address. -/
theorem x86_dispatch_code_in_range (op : DispatchOp) :
    code op ≤ 59 := by
  cases op <;> decide

/-- Canonical example: the MOV_LOAD_MAP_PTR member is a movLoadPtr-family member. -/
theorem x86_dispatch_mov_load_map_ptr_example :
    x86DispMovLoadPtrSpec .movLoadMapPtr = true := by
  decide

/-- Canonical example: the MOVSX_LOAD member is not a movxReg-family member. -/
theorem x86_dispatch_movx_load_example :
    x86DispMovxRegSpec .movsxLoad = false := by
  decide

/-- Canonical example: the TEST_MEM_REG member is a cmpMem-family member. -/
theorem x86_dispatch_test_mem_reg_example :
    x86DispCmpMemSpec .testMemReg = true := by
  decide

end KProgFormal
