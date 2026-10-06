import KProgFormal.GeneratedArm64Flags
import KProgFormal.GeneratedArm64Width

namespace KProgFormal

/-- Independent AArch64 NZCV statement for the three generated families. It is
written as a record of four `Bool` observations over already width-narrowed
operands so it does not reuse the generated `apply*` definitions. -/
structure Arm64NzcSpec where
  n : Bool
  z : Bool
  c : Bool
  v : Bool
  deriving DecidableEq, Repr

/-- ADD carry-out: true exactly when the unsigned width-sized sum overflows. -/
def arm64AddCarrySpec (lhs rhs : BitVec 64) (width : GeneratedArm64Width.Width) : Bool :=
  let mask := GeneratedArm64Width.mask width
  GeneratedArm64Width.narrow lhs width > mask - GeneratedArm64Width.narrow rhs width

/-- SUB carry (NOT borrow): true exactly when `lhs >= rhs` at the operand width. -/
def arm64SubCarrySpec (lhs rhs : BitVec 64) (width : GeneratedArm64Width.Width) : Bool :=
  GeneratedArm64Width.narrow lhs width >= GeneratedArm64Width.narrow rhs width

/-- Signed-overflow observation shared by ADD and SUB: the operands share the
sign bit and the width-narrowed result has the opposite sign bit. -/
def arm64AddOverflowSpec (lhs rhs : BitVec 64) (width : GeneratedArm64Width.Width) : Bool :=
  let mask := GeneratedArm64Width.signMask width
  let l := GeneratedArm64Width.narrow lhs width
  let r := GeneratedArm64Width.narrow rhs width
  let res := GeneratedArm64Width.narrow (l + r) width
  ((l ^^^ r) &&& mask) == 0 && (((l ^^^ res) &&& mask) != 0)

def arm64SubOverflowSpec (lhs rhs : BitVec 64) (width : GeneratedArm64Width.Width) : Bool :=
  let mask := GeneratedArm64Width.signMask width
  let l := GeneratedArm64Width.narrow lhs width
  let r := GeneratedArm64Width.narrow rhs width
  let res := GeneratedArm64Width.narrow (l - r) width
  (((l ^^^ r) &&& mask) != 0) && (((l ^^^ res) &&& mask) != 0)

def arm64AddNzc (lhs rhs : BitVec 64) (width : GeneratedArm64Width.Width) :
    Arm64NzcSpec :=
  let res := GeneratedArm64Width.narrow (GeneratedArm64Width.narrow lhs width
           + GeneratedArm64Width.narrow rhs width) width
  { n := GeneratedArm64Width.sign res width,
    z := res == 0,
    c := arm64AddCarrySpec lhs rhs width,
    v := arm64AddOverflowSpec lhs rhs width }

def arm64SubNzc (lhs rhs : BitVec 64) (width : GeneratedArm64Width.Width) :
    Arm64NzcSpec :=
  let res := GeneratedArm64Width.narrow (GeneratedArm64Width.narrow lhs width
           - GeneratedArm64Width.narrow rhs width) width
  { n := GeneratedArm64Width.sign res width,
    z := res == 0,
    c := arm64SubCarrySpec lhs rhs width,
    v := arm64SubOverflowSpec lhs rhs width }

def arm64LogicNzc (value : BitVec 64) (width : GeneratedArm64Width.Width) :
    Arm64NzcSpec :=
  let res := GeneratedArm64Width.narrow value width
  { n := GeneratedArm64Width.sign res width, z := res == 0, c := false, v := false }

/-- The generated ADD flag transition equals the independent NZCV statement. -/
theorem arm64_add_flags_refines (lhs rhs : BitVec 64)
    (width : GeneratedArm64Width.Width) :
    GeneratedArm64Flags.applyAdd lhs rhs width =
      { n := (arm64AddNzc lhs rhs width).n,
        z := (arm64AddNzc lhs rhs width).z,
        c := (arm64AddNzc lhs rhs width).c,
        v := (arm64AddNzc lhs rhs width).v } := by
  cases width <;> rfl

/-- The generated SUB flag transition equals the independent NZCV statement. -/
theorem arm64_sub_flags_refines (lhs rhs : BitVec 64)
    (width : GeneratedArm64Width.Width) :
    GeneratedArm64Flags.applySub lhs rhs width =
      { n := (arm64SubNzc lhs rhs width).n,
        z := (arm64SubNzc lhs rhs width).z,
        c := (arm64SubNzc lhs rhs width).c,
        v := (arm64SubNzc lhs rhs width).v } := by
  cases width <;> rfl

/-- The generated logical flag transition equals the independent NZCV statement,
which clears carry and overflow. -/
theorem arm64_logic_flags_refines (value : BitVec 64)
    (width : GeneratedArm64Width.Width) :
    GeneratedArm64Flags.applyLogic value width =
      { n := (arm64LogicNzc value width).n,
        z := (arm64LogicNzc value width).z,
        c := (arm64LogicNzc value width).c,
        v := (arm64LogicNzc value width).v } := by
  cases width <;> rfl

/-- AArch64 canonical example: 64-bit `0xffffffffffffffff + 1` sets C and Z,
clears N and V. -/
theorem arm64_add_carry_w64_example :
    let f := GeneratedArm64Flags.applyAdd 0xffffffffffffffff 1 .w64
    f.c = true ∧ f.z = true ∧ f.n = false ∧ f.v = false := by
  native_decide

/-- AArch64 canonical example: 64-bit `0 + 0` subtract sets C (no borrow), Z,
and clears N and V. -/
theorem arm64_sub_zero_w64_example :
    let f := GeneratedArm64Flags.applySub 0 0 .w64
    f.c = true ∧ f.z = true ∧ f.n = false ∧ f.v = false := by
  native_decide

/-- AArch64 canonical example: 32-bit `0x7fffffff + 1` sets V and N (result
sign flips), clears Z, and does not carry out. -/
theorem arm64_add_overflow_w32_example :
    let f := GeneratedArm64Flags.applyAdd 0x7fffffff 1 .w32
    f.v = true ∧ f.n = true ∧ f.z = false ∧ f.c = false := by
  native_decide

/-- AArch64 canonical example: 64-bit `1 - 2` borrows, so C is clear. -/
theorem arm64_sub_borrow_w64_example :
    let f := GeneratedArm64Flags.applySub 1 2 .w64
    f.c = false ∧ f.n = true ∧ f.z = false ∧ f.v = false := by
  native_decide

/-- Logical flags clear C and V and observe the width-narrowed value. -/
theorem arm64_logic_clears_carry_overflow :
    let f := GeneratedArm64Flags.applyLogic 0x80000000 .w32
    f.c = false ∧ f.v = false ∧ f.n = true ∧ f.z = false := by
  native_decide

end KProgFormal
