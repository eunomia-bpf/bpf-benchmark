import KProgFormal.GeneratedX86CmpOp
import KProgFormal.X86Immediate
import KProgFormal.X86MemAccess
import KProgFormal.X86AluWriteback

namespace KProgFormal

open GeneratedX86CmpOp (RhsSource FlagKind LhsSource DispKind rhsSource
  flagKind lhsSource dispKind)

/-- The compare/test operations whose memory-source handler `X86_SIM_L_EXEC_CMP_MEM`
covers. The memory operand is the left-hand side in every case; `cmpReg`/`testReg`
read the right-hand side from a register and `cmpImm`/`testImm` from the decoded
immediate. These four are exactly the four memory opcodes of the shared
`X86CmpOp` contract: `CMP_MEM_IMM` (`0x1d`), `TEST_MEM_IMM` (`0x1e`),
`CMP_MEM_REG` (`0x1f`), `TEST_MEM_REG` (`0x3b`). -/
inductive X86MemCompareOp
  | cmpImm
  | testImm
  | cmpReg
  | testReg
  deriving DecidableEq, Repr

/-- Bridge to the shared `CMP`/`TEST` opcode table: each memory compare/test
operation is the memory form the shared contract names. -/
def x86MemCompareOpToCmpOp : X86MemCompareOp -> GeneratedX86CmpOp.Op
  | .cmpImm => .cmpMemImm
  | .testImm => .testMemImm
  | .cmpReg => .cmpMemReg
  | .testReg => .testMemReg

/-- Independent statement of where each memory form reads its right-hand side:
the decoded immediate for the `_IMM` forms, the register for the `_REG` forms. -/
def x86MemCompareRhsSourceSpec : X86MemCompareOp -> RhsSource
  | .cmpImm => .immediate
  | .testImm => .immediate
  | .cmpReg => .register
  | .testReg => .register

/-- Independent statement of which flag production each memory form uses. -/
def x86MemCompareFlagKindSpec : X86MemCompareOp -> FlagKind
  | .cmpImm => .sub
  | .testImm => .logic
  | .cmpReg => .sub
  | .testReg => .logic

/-- Independent statement of where each memory form reads its left-hand side:
from memory in every case. -/
def x86MemCompareLhsSourceSpec : X86MemCompareOp -> LhsSource :=
  fun _ => .memory

/-- The shared contract's right-hand-side-source table agrees with the
independent statement for the four memory forms. -/
theorem x86_mem_compare_rhs_source_refines (op : X86MemCompareOp) :
    rhsSource (x86MemCompareOpToCmpOp op) = x86MemCompareRhsSourceSpec op := by
  cases op <;> rfl

/-- The shared contract's flag-kind table agrees with the independent statement
for the four memory forms. -/
theorem x86_mem_compare_flag_kind_refines (op : X86MemCompareOp) :
    flagKind (x86MemCompareOpToCmpOp op) = x86MemCompareFlagKindSpec op := by
  cases op <;> rfl

/-- The shared contract's left-hand-side-source table agrees with the
independent statement for the four memory forms: every memory form reads the
left-hand side from memory. -/
theorem x86_mem_compare_lhs_source_refines (op : X86MemCompareOp) :
    lhsSource (x86MemCompareOpToCmpOp op) = x86MemCompareLhsSourceSpec op := by
  cases op <;> rfl

/-- The displacement kind is carried by the shared table and is *not* a function
of the right-hand-side source: `testMemReg` reads a register right-hand side yet
takes the store displacement while `cmpMemReg` takes the signed one, so the
memory body's `STORE_DISP` argument is a per-opcode fact rather than derivable
from the immediate/register split. -/
theorem x86_mem_compare_disp_kind :
    dispKind (x86MemCompareOpToCmpOp .cmpReg) = .simm ∧
      dispKind (x86MemCompareOpToCmpOp .testReg) = .store ∧
      dispKind (x86MemCompareOpToCmpOp .cmpImm) = .store ∧
      dispKind (x86MemCompareOpToCmpOp .testImm) = .store ∧
      x86MemCompareRhsSourceSpec .cmpReg =
        x86MemCompareRhsSourceSpec .testReg := by
  refine ⟨rfl, rfl, rfl, rfl, rfl⟩

/-- `CMP/TEST [mem], rhs` after valid-address and width selection. The shared
contract selects the left-hand-side source (memory), the right-hand-side source,
the flag kind, and the displacement kind; the memory operand is loaded as the
left-hand side, the right-hand side is the decoded immediate or the register,
and the flags are the zero-borrow subtraction flags or the logical flags of the
width-narrowed conjunction. No register is written, so the destination register
value and tag pass through unchanged. -/
def generatedX86MemCompareStep (op : X86MemCompareOp) (state : X86RegAluState)
    (byte : Nat -> X86MemByte) (srcBits rawImm : BitVec 64)
    (width : X86Width) : X86RegAluState :=
  let lhs := GeneratedX86MemAccess.load byte width
  let rhs := match rhsSource (x86MemCompareOpToCmpOp op) with
    | .immediate => GeneratedX86Immediate.value rawImm width
    | .register => srcBits
  match flagKind (x86MemCompareOpToCmpOp op) with
  | .sub =>
      { dst := state.dst
        flags := generatedX86SubFlags (GeneratedX86Width.narrow lhs width)
          (GeneratedX86Width.narrow rhs width)
          (GeneratedX86Width.narrow
            (GeneratedX86SbbResult.result lhs rhs false) width)
          (GeneratedX86Width.signMask width) }
  | .logic =>
      { dst := state.dst
        flags := generatedX86LogicFlags
          (GeneratedX86Width.zero (BitVec.and lhs rhs) width)
          (GeneratedX86Width.sign (BitVec.and lhs rhs) width) }

/-- Independent statement of the same bounded handler: load the memory operand
through the byte-sum specification, take the right-hand side from the
independent source statement, then state the compare or test flags from the
independently defined subtraction/logical flag specification and preserve the
destination register. -/
def x86MemCompareStepSpec (op : X86MemCompareOp) (state : X86RegAluState)
    (byte : Nat -> X86MemByte) (srcBits rawImm : BitVec 64)
    (width : X86Width) : X86RegAluState :=
  let lhs := x86MemLoadSpec byte width
  let rhs := match x86MemCompareRhsSourceSpec op with
    | .immediate => x86ImmediateValueSpec rawImm width
    | .register => srcBits
  match x86MemCompareFlagKindSpec op with
  | .sub =>
      { dst := state.dst
        flags := x86SubFlagsSpec (x86NarrowSpec lhs width)
          (x86NarrowSpec rhs width)
          (x86NarrowSpec (x86SubResultSpec lhs rhs) width)
          (x86WidthSignMaskSpec width) }
  | .logic =>
      { dst := state.dst
        flags := x86LogicFlagsSpec (x86ZeroSpec (BitVec.and lhs rhs) width)
          (x86SignSpec (BitVec.and lhs rhs) width) }

/-- The memory-source compare/test handler composition refines the independent
load/source/flags statement for arbitrary memory bytes, register state, source
register bits, raw immediate, operation, and legal operand width. -/
theorem x86_mem_compare_step_refines (op : X86MemCompareOp)
    (state : X86RegAluState) (byte : Nat -> X86MemByte)
    (srcBits rawImm : BitVec 64) (width : X86Width) :
    generatedX86MemCompareStep op state byte srcBits rawImm width =
      x86MemCompareStepSpec op state byte srcBits rawImm width := by
  cases op <;>
    simp only [generatedX86MemCompareStep, x86MemCompareStepSpec, rhsSource,
      flagKind, x86MemCompareOpToCmpOp, x86MemCompareRhsSourceSpec,
      x86MemCompareFlagKindSpec, x86_immediate_value_refines,
      x86_mem_load_refines] <;>
    first
      | rw [x86_sub_step_refines]
      | rw [x86_zero_refines, x86_sign_refines, x86_logic_flags_refine]

/-- Neither compare nor test writes a register: the destination register value
and its provenance tag are preserved exactly. -/
theorem x86_mem_compare_preserves_dst (op : X86MemCompareOp)
    (state : X86RegAluState) (byte : Nat -> X86MemByte)
    (srcBits rawImm : BitVec 64) (width : X86Width) :
    (generatedX86MemCompareStep op state byte srcBits rawImm width).dst =
      state.dst := by
  cases op <;> rfl

/-- Both compare operations produce the zero-borrow subtraction flags of the
width-narrowed memory operand and their respective right-hand side — the decoded
immediate for `cmpImm`, the register bits for `cmpReg` — so the flag *kind* is
shared while the right-hand-side source remains a per-opcode fact. -/
theorem x86_mem_compare_cmp_flags (state : X86RegAluState)
    (byte : Nat -> X86MemByte) (srcBits rawImm : BitVec 64)
    (width : X86Width) :
    x86MemCompareFlagKindSpec .cmpImm = .sub ∧
      x86MemCompareFlagKindSpec .cmpReg = .sub ∧
      (generatedX86MemCompareStep .cmpImm state byte srcBits rawImm
        width).flags =
        x86SubFlagsSpec
          (x86NarrowSpec (x86MemLoadSpec byte width) width)
          (x86NarrowSpec (x86ImmediateValueSpec rawImm width) width)
          (x86NarrowSpec
            (x86SubResultSpec (x86MemLoadSpec byte width)
              (x86ImmediateValueSpec rawImm width)) width)
          (x86WidthSignMaskSpec width) ∧
      (generatedX86MemCompareStep .cmpReg state byte srcBits rawImm
        width).flags =
        x86SubFlagsSpec (x86NarrowSpec (x86MemLoadSpec byte width) width)
          (x86NarrowSpec srcBits width)
          (x86NarrowSpec
            (x86SubResultSpec (x86MemLoadSpec byte width) srcBits) width)
          (x86WidthSignMaskSpec width) := by
  refine ⟨rfl, rfl, ?_, ?_⟩ <;>
    simp only [generatedX86MemCompareStep, x86MemCompareOpToCmpOp, rhsSource,
      flagKind, x86MemCompareRhsSourceSpec, x86MemCompareFlagKindSpec,
      x86_immediate_value_refines, x86_mem_load_refines] <;>
    rw [x86_sub_step_refines]

/-- Both test operations produce the logical flags of the width-narrowed
conjunction: carry and overflow are cleared and zero/sign come from the
conjunction, with the right-hand side taken from the immediate for `testImm` and
the register for `testReg`. -/
theorem x86_mem_compare_test_flags (state : X86RegAluState)
    (byte : Nat -> X86MemByte) (srcBits rawImm : BitVec 64)
    (width : X86Width) :
    x86MemCompareFlagKindSpec .testImm = .logic ∧
      x86MemCompareFlagKindSpec .testReg = .logic ∧
      (generatedX86MemCompareStep .testImm state byte srcBits rawImm
        width).flags =
        x86LogicFlagsSpec
          (x86ZeroSpec
            (BitVec.and (x86MemLoadSpec byte width)
              (x86ImmediateValueSpec rawImm width)) width)
          (x86SignSpec
            (BitVec.and (x86MemLoadSpec byte width)
              (x86ImmediateValueSpec rawImm width)) width) ∧
      (generatedX86MemCompareStep .testReg state byte srcBits rawImm
        width).flags =
        x86LogicFlagsSpec
          (x86ZeroSpec (BitVec.and (x86MemLoadSpec byte width) srcBits) width)
          (x86SignSpec (BitVec.and (x86MemLoadSpec byte width) srcBits)
            width) := by
  refine ⟨rfl, rfl, ?_, ?_⟩ <;>
    simp only [generatedX86MemCompareStep, x86MemCompareOpToCmpOp, rhsSource,
      flagKind, x86MemCompareRhsSourceSpec, x86MemCompareFlagKindSpec,
      x86_immediate_value_refines, x86_mem_load_refines] <;>
    rw [x86_zero_refines, x86_sign_refines, x86_logic_flags_refine]

/-- The memory compare/test handler consumes the shared `CMP`/`TEST` contract's
per-opcode tables: the left-hand side is always memory, the right-hand-side
source and the flag kind are the shared table's entries, and the composed step
refines the independent statement while preserving the destination register. -/
theorem x86_mem_compare_contract_refines (op : X86MemCompareOp)
    (state : X86RegAluState) (byte : Nat -> X86MemByte)
    (srcBits rawImm : BitVec 64) (width : X86Width) :
    lhsSource (x86MemCompareOpToCmpOp op) = .memory ∧
      rhsSource (x86MemCompareOpToCmpOp op) = x86MemCompareRhsSourceSpec op ∧
      flagKind (x86MemCompareOpToCmpOp op) = x86MemCompareFlagKindSpec op ∧
      generatedX86MemCompareStep op state byte srcBits rawImm width =
        x86MemCompareStepSpec op state byte srcBits rawImm width := by
  refine ⟨x86_mem_compare_lhs_source_refines op, ?_, ?_, ?_⟩
  · exact x86_mem_compare_rhs_source_refines op
  · exact x86_mem_compare_flag_kind_refines op
  · exact x86_mem_compare_step_refines op state byte srcBits rawImm width

/-- `CMP reg, [mem]` after address-space selection has supplied the memory
bytes. The register is the left-hand side and the memory operand the right-hand
side; both are narrowed by the operand width, the zero-borrow subtraction flags
replace the flags, and no register is written. -/
def generatedX86CmpRegMemStep (state : X86RegAluState)
    (byte : Nat -> X86MemByte) (width : X86Width) : X86RegAluState :=
  let lhs := state.dst.bits
  let rhs := GeneratedX86MemAccess.load byte width
  { dst := state.dst
    flags := generatedX86SubFlags (GeneratedX86Width.narrow lhs width)
      (GeneratedX86Width.narrow rhs width)
      (GeneratedX86Width.narrow
        (GeneratedX86SbbResult.result lhs rhs false) width)
      (GeneratedX86Width.signMask width) }

/-- Independent statement of the register/memory compare. -/
def x86CmpRegMemStepSpec (state : X86RegAluState)
    (byte : Nat -> X86MemByte) (width : X86Width) : X86RegAluState :=
  let lhs := state.dst.bits
  let rhs := x86MemLoadSpec byte width
  { dst := state.dst
    flags := x86SubFlagsSpec (x86NarrowSpec lhs width)
      (x86NarrowSpec rhs width)
      (x86NarrowSpec (x86SubResultSpec lhs rhs) width)
      (x86WidthSignMaskSpec width) }

theorem x86_cmp_reg_mem_step_refines (state : X86RegAluState)
    (byte : Nat -> X86MemByte) (width : X86Width) :
    generatedX86CmpRegMemStep state byte width =
      x86CmpRegMemStepSpec state byte width := by
  simp only [generatedX86CmpRegMemStep, x86CmpRegMemStepSpec]
  rw [x86_mem_load_refines, x86_sub_step_refines]

theorem x86_cmp_reg_mem_preserves_dst (state : X86RegAluState)
    (byte : Nat -> X86MemByte) (width : X86Width) :
    (generatedX86CmpRegMemStep state byte width).dst = state.dst := by
  rfl

/-- The complete memory-source compare handler surface: every compare/test
operation consumes the shared contract's tables and preserves the destination
register, and the register/memory compare likewise refines its independent
statement while preserving the register. -/
theorem x86_mem_compare_handler_refines (op : X86MemCompareOp)
    (state : X86RegAluState) (byte : Nat -> X86MemByte)
    (srcBits rawImm : BitVec 64) (width : X86Width) :
    (generatedX86MemCompareStep op state byte srcBits rawImm width).dst =
        state.dst ∧
      generatedX86CmpRegMemStep state byte width =
        x86CmpRegMemStepSpec state byte width := by
  constructor
  · exact x86_mem_compare_preserves_dst op state byte srcBits rawImm width
  · exact x86_cmp_reg_mem_step_refines state byte width

/-- A 32-bit compare of equal operands sets zero, clears carry, sign, and
overflow, and leaves the packet-tagged destination untouched. -/
theorem x86_mem_compare_equal_w32 :
    let old : Nat -> X86MemByte := fun i =>
      match i with
      | 0 => 0x78 | 1 => 0x56 | 2 => 0x34 | 3 => 0x12 | _ => 0
    generatedX86MemCompareStep .cmpImm
      { dst := { bits := 0xdeadbeefcafef00d, tag := .packet },
        flags := { cf := true, zf := false, sf := true, of := true } }
      old 0 0x12345678 .w32 =
      { dst := { bits := 0xdeadbeefcafef00d, tag := .packet },
        flags := { cf := false, zf := true, sf := false, of := false } } := by
  decide

/-- An 8-bit compare of one against two borrows: carry and sign are set, zero
and overflow are clear. -/
theorem x86_mem_compare_borrow_w8 :
    let old : Nat -> X86MemByte := fun i => if i = 0 then 0x01 else 0
    (generatedX86MemCompareStep .cmpReg
      { dst := { bits := 0xffffffffffffffff, tag := .scalar },
        flags := { cf := false, zf := true, sf := false, of := false } }
      old 0x02 0 .w8).flags =
      { cf := true, zf := false, sf := true, of := false } := by
  decide

/-- A 16-bit test whose width-local conjunction is zero sets zero and clears
carry, sign, and overflow. -/
theorem x86_mem_compare_test_zero_w16 :
    let old : Nat -> X86MemByte := fun i => if i = 0 then 0x00 else 0xff
    (generatedX86MemCompareStep .testImm
      { dst := { bits := 0xffffffffffffffff, tag := .mapValue },
        flags := { cf := true, zf := false, sf := true, of := true } }
      old 0 0x00ff .w16).flags =
      { cf := false, zf := true, sf := false, of := false } := by
  decide

/-- The register/memory compare takes the register as its left-hand side: three
compared against a loaded five borrows and leaves the destination intact. -/
theorem x86_cmp_reg_mem_borrow_w64 :
    let old : Nat -> X86MemByte := fun i => if i = 0 then 0x05 else 0
    generatedX86CmpRegMemStep
      { dst := { bits := 0x0000000000000003, tag := .abi },
        flags := { cf := false, zf := true, sf := false, of := false } }
      old .w64 =
      { dst := { bits := 0x0000000000000003, tag := .abi },
        flags := { cf := true, zf := false, sf := true, of := false } } := by
  decide

end KProgFormal
