import KProgFormal.GeneratedArm64AluResult
import KProgFormal.GeneratedArm64Decode
import KProgFormal.GeneratedArm64Flags
import KProgFormal.GeneratedArm64Width
import KProgFormal.Arm64Flags

namespace KProgFormal

open GeneratedArm64AluDecode (Alu)

/-- Independent AArch64 width mask, restated so the narrowing used by the
generated contracts is not itself the only definition of the mask. -/
def arm64WidthMaskSpec : GeneratedArm64Width.Width -> BitVec 64
  | .w8 => BitVec.ofNat 64 0xff
  | .w16 => BitVec.ofNat 64 0xffff
  | .w32 => BitVec.ofNat 64 0xffffffff
  | .w64 => BitVec.ofNat 64 0xffffffffffffffff

/-- Independent width narrowing: keep the low `width` bits of the operand. -/
def arm64NarrowSpec (value : BitVec 64)
    (width : GeneratedArm64Width.Width) : BitVec 64 :=
  value &&& arm64WidthMaskSpec width

theorem arm64_narrow_refines (value : BitVec 64)
    (width : GeneratedArm64Width.Width) :
    GeneratedArm64Width.narrow value width = arm64NarrowSpec value width := by
  cases width <;> rfl

/-- Independent statement of the six AArch64 ALU result formulas. SUBS/ADDS
form the result from the operands directly; subtraction is stated as
add-of-two's-complement so the statement does not reuse the generated
subtraction form, and BIC is stated with an explicit complement mask. -/
def arm64AluResultSpec (op : Alu) (lhs rhs : BitVec 64) : BitVec 64 :=
  match op with
  | .add => lhs + rhs
  | .sub => lhs + ~~~rhs + 1
  | .and => lhs &&& rhs
  | .bic => lhs &&& (~~~rhs)
  | .eor => lhs ^^^ rhs
  | .orr => lhs ||| rhs

/-- The generated op-step contract agrees with the independent statement for
every one of the six ALU operations. -/
theorem arm64_alu_result_refines (op : Alu) (lhs rhs : BitVec 64) :
    GeneratedArm64AluResult.result op lhs rhs = arm64AluResultSpec op lhs rhs := by
  cases op <;> simp [GeneratedArm64AluResult.result, arm64AluResultSpec] <;> bv_decide

/-- Every supported ALU operation is inside the numeric case-label range
`0U..5U` used by the shared C macro, so the macro's `default` (unsupported)
branch is unreachable for a valid `Alu`. -/
theorem arm64_alu_result_code_in_range (op : Alu) :
    GeneratedArm64AluDecode.code op < 6 := by
  cases op <;> decide

/-- The six generated codes are exactly the macro's case labels. -/
theorem arm64_alu_result_code_dispatch (lhs rhs : BitVec 64) :
    arm64AluResultSpec .add lhs rhs = lhs + rhs ∧
    arm64AluResultSpec .sub lhs rhs = lhs - rhs ∧
    arm64AluResultSpec .and lhs rhs = lhs &&& rhs ∧
    arm64AluResultSpec .bic lhs rhs = lhs &&& ~~~rhs ∧
    arm64AluResultSpec .eor lhs rhs = lhs ^^^ rhs ∧
    arm64AluResultSpec .orr lhs rhs = lhs ||| rhs := by
  refine ⟨?_, ?_, ?_, ?_, ?_, ?_⟩ <;> simp [arm64AluResultSpec] <;> bv_decide

/-- Narrowing the 64-bit op-step result is the same as computing the operation
on width-narrowed operands and narrowing again. This is the property the C
handler relies on when it writes `KPROG_ALU64_RESULT` through
`ARM64_SIM_L_WRITE_REG_WIDTH`. -/
theorem arm64_alu_result_narrow_refines (op : Alu) (lhs rhs : BitVec 64)
    (width : GeneratedArm64Width.Width) :
    GeneratedArm64Width.narrow (GeneratedArm64AluResult.result op lhs rhs) width =
      arm64NarrowSpec (arm64AluResultSpec op
        (arm64NarrowSpec lhs width) (arm64NarrowSpec rhs width)) width := by
  cases op <;> cases width <;>
    simp [GeneratedArm64AluResult.result, arm64AluResultSpec,
      GeneratedArm64Width.narrow, GeneratedArm64Width.mask, arm64NarrowSpec,
      arm64WidthMaskSpec] <;> bv_decide

/-- Result value plus the four NZCV observations of one flag-setting ALU step. -/
structure Arm64AluStep where
  value : BitVec 64
  flags : GeneratedArm64Flags.Flags
  deriving DecidableEq, Repr

def arm64AddStepSpec (lhs rhs : BitVec 64)
    (width : GeneratedArm64Width.Width) : Arm64AluStep :=
  { value := arm64AluResultSpec .add lhs rhs,
    flags := { n := (arm64AddNzc lhs rhs width).n,
               z := (arm64AddNzc lhs rhs width).z,
               c := (arm64AddNzc lhs rhs width).c,
               v := (arm64AddNzc lhs rhs width).v } }

def arm64SubStepSpec (lhs rhs : BitVec 64)
    (width : GeneratedArm64Width.Width) : Arm64AluStep :=
  { value := arm64AluResultSpec .sub lhs rhs,
    flags := { n := (arm64SubNzc lhs rhs width).n,
               z := (arm64SubNzc lhs rhs width).z,
               c := (arm64SubNzc lhs rhs width).c,
               v := (arm64SubNzc lhs rhs width).v } }

def arm64LogicStepSpec (op : Alu) (lhs rhs : BitVec 64)
    (width : GeneratedArm64Width.Width) : Arm64AluStep :=
  { value := arm64AluResultSpec op lhs rhs,
    flags := { n := (arm64LogicNzc (arm64AluResultSpec op lhs rhs) width).n,
               z := (arm64LogicNzc (arm64AluResultSpec op lhs rhs) width).z,
               c := (arm64LogicNzc (arm64AluResultSpec op lhs rhs) width).c,
               v := (arm64LogicNzc (arm64AluResultSpec op lhs rhs) width).v } }
/-- ADDS/CMN: the generated result and the generated ADD flag transition
compose to the independent step statement. -/
theorem arm64_add_step_refines (lhs rhs : BitVec 64)
    (width : GeneratedArm64Width.Width) :
    ({ value := GeneratedArm64AluResult.result .add lhs rhs,
       flags := GeneratedArm64Flags.applyAdd lhs rhs width } : Arm64AluStep) =
      arm64AddStepSpec lhs rhs width := by
  rw [arm64_alu_result_refines, arm64_add_flags_refines]
  rfl

/-- SUBS/CMP: the generated result and the generated SUB flag transition
compose to the independent step statement. -/
theorem arm64_sub_step_refines (lhs rhs : BitVec 64)
    (width : GeneratedArm64Width.Width) :
    ({ value := GeneratedArm64AluResult.result .sub lhs rhs,
       flags := GeneratedArm64Flags.applySub lhs rhs width } : Arm64AluStep) =
      arm64SubStepSpec lhs rhs width := by
  rw [arm64_alu_result_refines, arm64_sub_flags_refines]
  rfl

/-- ANDS/BICS/TST: the generated logic result and the generated logic flag
transition compose to the independent step statement. The flag transition
observes the shared op-step result, so value and flags derive from one
contract. -/
theorem arm64_logic_step_refines (op : Alu) (lhs rhs : BitVec 64)
    (width : GeneratedArm64Width.Width) :
    ({ value := GeneratedArm64AluResult.result op lhs rhs,
       flags := GeneratedArm64Flags.applyLogic
         (GeneratedArm64AluResult.result op lhs rhs) width } : Arm64AluStep) =
      arm64LogicStepSpec op lhs rhs width := by
  rw [arm64_alu_result_refines, arm64_logic_flags_refines]
  rfl

/-- AArch64 canonical example: 64-bit `1 - 2` yields all ones and borrows. -/
theorem arm64_sub_borrow_example :
    (arm64SubStepSpec 1 2 .w64).value = 0xffffffffffffffff ∧
    (arm64SubStepSpec 1 2 .w64).flags.c = false ∧
    (arm64SubStepSpec 1 2 .w64).flags.n = true ∧
    (arm64SubStepSpec 1 2 .w64).flags.v = false := by
  native_decide

/-- AArch64 canonical example: BIC clears exactly the selected bits. -/
theorem arm64_bic_example :
    arm64AluResultSpec .bic 0xff 0x0f = 0xf0 := by
  native_decide

/-- AArch64 canonical example: EOR of an operand with itself is zero, which
also sets Z through the logic flag transition. -/
theorem arm64_eor_self_example :
    (arm64LogicStepSpec .eor 0x123456789abcdef0 0x123456789abcdef0 .w64).value = 0 ∧
    (arm64LogicStepSpec .eor 0x123456789abcdef0 0x123456789abcdef0 .w64).flags.z = true := by
  native_decide

/-- AArch64 canonical example: ORR sets every selected bit and clears C/V. -/
theorem arm64_orr_example :
    (arm64LogicStepSpec .orr 0xf0 0x0f .w64).value = 0xff ∧
    (arm64LogicStepSpec .orr 0xf0 0x0f .w64).flags.c = false ∧
    (arm64LogicStepSpec .orr 0xf0 0x0f .w64).flags.v = false := by
  native_decide

/-- AArch64 canonical example: 64-bit `0xffffffffffffffff + 1` wraps to zero
and carries out. -/
theorem arm64_add_wrap_example :
    (arm64AddStepSpec 0xffffffffffffffff 1 .w64).value = 0 ∧
    (arm64AddStepSpec 0xffffffffffffffff 1 .w64).flags.c = true ∧
    (arm64AddStepSpec 0xffffffffffffffff 1 .w64).flags.z = true := by
  native_decide

end KProgFormal
