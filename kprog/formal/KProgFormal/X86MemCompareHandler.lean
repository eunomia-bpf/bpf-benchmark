import KProgFormal.X86MemAccess
import KProgFormal.X86AluWriteback

namespace KProgFormal

/-- The compare/test operations whose memory-source handler `X86_SIM_L_EXEC_CMP_MEM`
covers. The memory operand is the left-hand side in every case; `cmpReg`/`testReg`
read the right-hand side from a register and `cmpImm`/`testImm` from the decoded
immediate, both already supplied here as a 64-bit value. -/
inductive X86MemCompareOp
  | cmpImm
  | testImm
  | cmpReg
  | testReg
  deriving DecidableEq, Repr

/-- `CMP/TEST [mem], rhs` after valid-address, right-hand-side, operation, and
width selection. The memory operand is loaded as the left-hand side; a compare
takes the zero-borrow subtraction flags and a test takes the logical flags from
the width-narrowed conjunction. No register is written, so the destination
register value and tag pass through unchanged. -/
def generatedX86MemCompareStep (op : X86MemCompareOp) (state : X86RegAluState)
    (byte : Nat -> X86MemByte) (rhs : BitVec 64)
    (width : X86Width) : X86RegAluState :=
  let lhs := GeneratedX86MemAccess.load byte width
  match op with
  | .cmpImm | .cmpReg =>
      { dst := state.dst
        flags := generatedX86SubFlags (GeneratedX86Width.narrow lhs width)
          (GeneratedX86Width.narrow rhs width)
          (GeneratedX86Width.narrow
            (GeneratedX86SbbResult.result lhs rhs false) width)
          (GeneratedX86Width.signMask width) }
  | .testImm | .testReg =>
      { dst := state.dst
        flags := generatedX86LogicFlags
          (GeneratedX86Width.zero (BitVec.and lhs rhs) width)
          (GeneratedX86Width.sign (BitVec.and lhs rhs) width) }

/-- Independent statement of the same bounded handler: load the memory operand
through the byte-sum specification, then state the compare or test flags from the
independently defined subtraction/logical flag specification and preserve the
destination register. -/
def x86MemCompareStepSpec (op : X86MemCompareOp) (state : X86RegAluState)
    (byte : Nat -> X86MemByte) (rhs : BitVec 64)
    (width : X86Width) : X86RegAluState :=
  let lhs := x86MemLoadSpec byte width
  match op with
  | .cmpImm | .cmpReg =>
      { dst := state.dst
        flags := x86SubFlagsSpec (x86NarrowSpec lhs width)
          (x86NarrowSpec rhs width)
          (x86NarrowSpec (x86SubResultSpec lhs rhs) width)
          (x86WidthSignMaskSpec width) }
  | .testImm | .testReg =>
      { dst := state.dst
        flags := x86LogicFlagsSpec (x86ZeroSpec (BitVec.and lhs rhs) width)
          (x86SignSpec (BitVec.and lhs rhs) width) }

/-- The memory-source compare/test handler composition refines the independent
load/flags statement for arbitrary memory bytes, register state, right-hand-side
value, operation, and legal operand width. -/
theorem x86_mem_compare_step_refines (op : X86MemCompareOp)
    (state : X86RegAluState) (byte : Nat -> X86MemByte) (rhs : BitVec 64)
    (width : X86Width) :
    generatedX86MemCompareStep op state byte rhs width =
      x86MemCompareStepSpec op state byte rhs width := by
  cases op <;>
    simp only [generatedX86MemCompareStep, x86MemCompareStepSpec] <;>
    rw [x86_mem_load_refines]
  · rw [x86_sub_step_refines]
  · rw [x86_zero_refines, x86_sign_refines, x86_logic_flags_refine]
  · rw [x86_sub_step_refines]
  · rw [x86_zero_refines, x86_sign_refines, x86_logic_flags_refine]

/-- Neither compare nor test writes a register: the destination register value
and its provenance tag are preserved exactly. -/
theorem x86_mem_compare_preserves_dst (op : X86MemCompareOp)
    (state : X86RegAluState) (byte : Nat -> X86MemByte) (rhs : BitVec 64)
    (width : X86Width) :
    (generatedX86MemCompareStep op state byte rhs width).dst = state.dst := by
  cases op <;> rfl

/-- The two compare operations replace the flags with the zero-borrow
subtraction flags of the width-narrowed memory operand and right-hand side. -/
theorem x86_mem_compare_cmp_flags (state : X86RegAluState)
    (byte : Nat -> X86MemByte) (rhs : BitVec 64) (width : X86Width) :
    (generatedX86MemCompareStep .cmpImm state byte rhs width).flags =
      (generatedX86MemCompareStep .cmpReg state byte rhs width).flags ∧
    (generatedX86MemCompareStep .cmpReg state byte rhs width).flags =
      x86SubFlagsSpec (x86NarrowSpec (x86MemLoadSpec byte width) width)
        (x86NarrowSpec rhs width)
        (x86NarrowSpec (x86SubResultSpec (x86MemLoadSpec byte width) rhs) width)
        (x86WidthSignMaskSpec width) := by
  constructor
  · rfl
  · rw [x86_mem_compare_step_refines, x86MemCompareStepSpec]

/-- The two test operations replace the flags with the logical flags: carry and
overflow are cleared and zero/sign come from the width-narrowed conjunction. -/
theorem x86_mem_compare_test_flags (state : X86RegAluState)
    (byte : Nat -> X86MemByte) (rhs : BitVec 64) (width : X86Width) :
    (generatedX86MemCompareStep .testImm state byte rhs width).flags =
      (generatedX86MemCompareStep .testReg state byte rhs width).flags ∧
    (generatedX86MemCompareStep .testReg state byte rhs width).flags =
      x86LogicFlagsSpec
        (x86ZeroSpec (BitVec.and (x86MemLoadSpec byte width) rhs) width)
        (x86SignSpec (BitVec.and (x86MemLoadSpec byte width) rhs) width) := by
  constructor
  · rfl
  · rw [x86_mem_compare_step_refines, x86MemCompareStepSpec]

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
operation preserves the destination register, and the register/memory compare
likewise refines its independent statement while preserving the register. -/
theorem x86_mem_compare_handler_refines (op : X86MemCompareOp)
    (state : X86RegAluState) (byte : Nat -> X86MemByte) (rhs : BitVec 64)
    (width : X86Width) :
    (generatedX86MemCompareStep op state byte rhs width).dst = state.dst ∧
      generatedX86CmpRegMemStep state byte width =
        x86CmpRegMemStepSpec state byte width := by
  constructor
  · exact x86_mem_compare_preserves_dst op state byte rhs width
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
      old 0x12345678 .w32 =
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
      old 0x02 .w8).flags =
      { cf := true, zf := false, sf := true, of := false } := by
  decide

/-- A 16-bit test whose width-local conjunction is zero sets zero and clears
carry, sign, and overflow. -/
theorem x86_mem_compare_test_zero_w16 :
    let old : Nat -> X86MemByte := fun i => if i = 0 then 0x00 else 0xff
    (generatedX86MemCompareStep .testImm
      { dst := { bits := 0xffffffffffffffff, tag := .mapValue },
        flags := { cf := true, zf := false, sf := true, of := true } }
      old 0x00ff .w16).flags =
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
