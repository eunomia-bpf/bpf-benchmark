import KProgFormal.GeneratedX86AluResult
import KProgFormal.X86AluDecode
import KProgFormal.X86AddResult
import KProgFormal.X86SubResult
import KProgFormal.X86ShiftResult

namespace KProgFormal

/-- Independent statement of the x86 ALU op-step result over the ALU contract's
own token literals: the sum at ADD and ADC, the difference at SUB, the borrow
difference at SBB, the bitwise operations at XOR/OR/AND, the width-local shift
at the four shift tokens (through the shared shift-result contracts), the
64-bit wrap-around product at IMUL, the increment at INC, the decrement at
DEC, the complement at NOT, and the negation at NEG (the left operand there is
the subtrahend, as in the simulator's `SBB(0, lhs)` negation). -/
def x86AluResultSpec (alu : X86Alu) (lhs rhs : BitVec 64) (width : X86Width) :
    BitVec 64 :=
  match alu with
  | .add => x86AddResultSpec lhs rhs
  | .sub => x86SubResultSpec lhs rhs
  | .xor => lhs ^^^ rhs
  | .or => lhs ||| rhs
  | .and => lhs &&& rhs
  | .shl => x86ShlResultSpec lhs rhs width
  | .shr => x86ShrResultSpec lhs rhs width
  | .sar => x86SarResultSpec lhs rhs width
  | .rol => x86RolResultSpec lhs rhs width
  | .imul => lhs * rhs
  | .inc => x86AddResultSpec lhs 1
  | .not => BitVec.not lhs
  | .sbb => x86SubResultSpec lhs rhs
  | .dec => x86SubResultSpec lhs 1
  | .neg => x86SubResultSpec 0 lhs
  | .adc => x86AddResultSpec lhs rhs

/-- The generated op-step result equals the independent per-op statement for
every token: each arm reuses the token's own single-step refinement (the add
and subtract step contracts for the carry/borrow arms, the shared shift-result
refinements for the four shifts) rather than restating the arm formulas, so
an arm swapped, dropped, or re-keyed in either the generated header or this
statement is caught. -/
theorem x86_alu_result_refines (alu : X86Alu) (lhs rhs : BitVec 64)
    (width : X86Width) :
    GeneratedX86AluResult.result alu lhs rhs width =
      x86AluResultSpec alu lhs rhs width := by
  cases alu <;>
    simp only [GeneratedX86AluResult.result, x86AluResultSpec] <;>
    first
      | exact x86_add_result_refines _ _
      | exact x86_sub_result_refines _ _
      | exact x86_shl_result_refines _ _ _
      | exact x86_shr_result_refines _ _ _
      | exact x86_sar_result_refines _ _ _
      | exact x86_rol_result_refines _ _ _
      | rfl

/-- The generated numeric code of each token equals the independent
`x86AluCodeSpec` literal, so the C switch's `case 0U..15U` labels track the
hand dispatcher's `X86_ALU_*` comparisons part-for-part. -/
theorem x86_alu_result_code_dispatch (alu : X86Alu) :
    GeneratedX86AluDecode.code alu = x86AluCodeSpec alu :=
  x86_alu_code_refines alu

/-- The generated result is defined for every token the ALU-decode table
names: the numeric code of each token is below sixteen, so a re-labelled case
in the C switch is out of range. -/
theorem x86_alu_result_code_in_range (alu : X86Alu) :
    GeneratedX86AluDecode.code alu < 16 := by
  cases alu <;> native_decide

end KProgFormal
