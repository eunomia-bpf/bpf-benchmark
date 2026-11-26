import KProgFormal.ClightRefinement.X86SubImmediateReference
import KProgFormal.ClightRefinement.X86ShiftFlagPF

namespace KProgFormal.ClightRefinement.X86SubFlagValues

/-- Actual source CF comparison equals the SAME external qword SUB borrow. -/
theorem cf (lhs rhs : BitVec 64) (flags : X86.Flags) :
    (X86.Flags.sub .q lhs rhs flags).cf = decide (lhs.toNat < rhs.toNat) := by
  simp only [X86.Flags.sub,X86.Flags.subCF,X86.Value.uval,X86.Value.trunc_q]

/-- Original source ZF compares the operands; qword subtraction is zero
exactly on equality, including wraparound. -/
theorem zf (lhs rhs : BitVec 64) (flags : X86.Flags) :
    (X86.Flags.sub .q lhs rhs flags).zf = (lhs == rhs) := by
  simp only [X86.Flags.sub,X86.Flags.fromResult,X86.Flags.subResult,X86.Value.isZero,X86.Value.trunc_q]
  apply Bool.eq_iff_iff.mpr
  simp only [beq_iff_eq,BitVec.sub_eq_iff_eq_add]
  change lhs = (0#64)+rhs ↔ lhs = rhs
  rw [BitVec.zero_add]

/-- Original source AF bit transport agrees with external subtraction. -/
theorem af (lhs rhs : BitVec 64) (flags : X86.Flags) :
    (X86.Flags.sub .q lhs rhs flags).af = (lhs ^^^ rhs ^^^ (lhs-rhs)).getLsbD 4 := by
  simp only [X86.Flags.sub,X86.Flags.subResult,X86.Flags.auxCarry,X86.Value.trunc_q]

/-- Qword parity and sign are projections of the original external result. -/
theorem pf_sf (lhs rhs : BitVec 64) (flags : X86.Flags) :
    (X86.Flags.sub .q lhs rhs flags).pf = X86.Value.parity8 (lhs-rhs) ∧
    (X86.Flags.sub .q lhs rhs flags).sf = (lhs-rhs).getLsbD 63 := by
  constructor <;> simp only [X86.Flags.sub,X86.Flags.fromResult,X86.Flags.subResult,
    X86.Value.trunc_q,X86.Value.msb,X86.Size.signBit]


/-- Reuse the original sign-mask proof for the exact SUB result rather than
introducing an independent flag specification. -/
theorem sf_source (lhs rhs : BitVec 64) (flags : X86.Flags) :
    X86ShiftFlagSF.bit (lhs-rhs) (0x8000000000000000#64) =
      .Vint (if (X86.Flags.sub .q lhs rhs flags).sf then 1 else 0) := by
  have actual := X86ShiftFlagSF.native_value .q lhs (lhs-rhs) 0 false false false flags
  change X86ShiftFlagSF.bit (lhs-rhs) (0x8000000000000000#64) =
    .Vint (if X86.Value.msb .q (lhs-rhs) then 1 else 0) at actual
  simpa only [X86.Flags.sub,X86.Flags.fromResult,X86.Flags.subResult,X86.Value.trunc_q] using actual

/-- The original shared nibble-fold parity table also supplies SUB PF. -/
theorem pf_source (lhs rhs : BitVec 64) (flags : X86.Flags) :
    X86ShiftFlagPF.bit (lhs-rhs) =
      .Vint (if (X86.Flags.sub .q lhs rhs flags).pf then 1 else 0) := by
  simpa only [X86.Flags.sub,X86.Flags.fromResult,X86.Flags.subResult,X86.Value.trunc_q] using
    X86ShiftFlagPF.parity (lhs-rhs)

/-- The source SUB overflow mask equals the exact external signed-overflow
predicate for every qword operand pair, including wraparound. -/
theorem of_source (lhs rhs : BitVec 64) (flags : X86.Flags) :
    X86ShiftFlagSF.bit ((lhs ^^^ rhs) &&& (lhs ^^^ (lhs-rhs))) (0x8000000000000000#64) =
      .Vint (if (X86.Flags.sub .q lhs rhs flags).of then 1 else 0) := by
  have observed := X86ShiftFlagSF.native_value .q lhs ((lhs ^^^ rhs) &&& (lhs ^^^ (lhs-rhs))) 0 false false false flags
  change X86ShiftFlagSF.bit ((lhs ^^^ rhs) &&& (lhs ^^^ (lhs-rhs))) (0x8000000000000000#64) =
    .Vint (if ((lhs ^^^ rhs) &&& (lhs ^^^ (lhs-rhs))).getLsbD 63 then 1 else 0) at observed
  rw [observed]
  simp only [X86.Flags.sub,X86.Flags.subOF,X86.Flags.subResult,X86.Value.trunc_q,
    X86.Value.msb,X86.Size.signBit,BitVec.getLsbD_and,BitVec.getLsbD_xor]
  cases a : lhs.getLsbD 63 <;> cases b : rhs.getLsbD 63 <;> cases r : (lhs-rhs).getLsbD 63 <;> rfl

end KProgFormal.ClightRefinement.X86SubFlagValues
