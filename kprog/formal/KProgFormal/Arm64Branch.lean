import KProgFormal.GeneratedArm64Branch
import KProgFormal.GeneratedArm64Cond

namespace KProgFormal

open KProgFormal.GeneratedArm64Branch (Branch value)

/-- Independent statement of the AArch64 compare-and-branch predicates. The
whole-value arms compare the register against zero; the bit arms test the single
bit at the masked index against zero or one, stated through `Nat` division and
remainder rather than the generated shift-and-mask pair. -/
def arm64BranchTakenSpec (kind : Branch) (reg bit : BitVec 64) : Bool :=
  match kind with
  | .cbz => decide (reg = 0)
  | .cbnz => decide (reg ≠ 0)
  | .tbz => decide ((reg.toNat >>> (bit.toNat % 64)) % 2 = 0)
  | .tbnz => decide ((reg.toNat >>> (bit.toNat % 64)) % 2 = 1)

/-- C masks the tested bit index with `& 63`; its magnitude is that index modulo
the 64-bit register domain. -/
theorem arm64BranchBitMask (bit : BitVec 64) :
    (bit &&& 63).toNat = bit.toNat % 64 := by
  have h63 : BitVec.toNat (63 : BitVec 64) = 63 := by decide
  have hpow : (63 : Nat) = 2^6 - 1 := by decide
  rw [BitVec.toNat_and, h63, hpow, Nat.and_two_pow_sub_one_eq_mod]

/-- The generated bit-extract reduces to the architectural bit's magnitude. -/
theorem arm64BranchBitOf (value bit : BitVec 64) :
    ((value >>> (bit &&& 63).toNat) &&& 1 : BitVec 64).toNat =
      (value.toNat >>> (bit.toNat % 64)) % 2 := by
  rw [BitVec.toNat_and, BitVec.toNat_ushiftRight,
    show BitVec.toNat (1 : BitVec 64) = 1 from rfl, arm64BranchBitMask,
    Nat.and_one_is_mod, Nat.shiftRight_eq_div_pow]

/-- The generated branch predicate agrees with the independent statement for all
four kinds and all register and bit values. -/
theorem arm64_branch_refines (kind : Branch) (reg bit : BitVec 64) :
    value kind reg bit = arm64BranchTakenSpec kind reg bit := by
  cases kind
  · rw [show value .cbz reg bit = decide (reg = 0) from rfl,
        show arm64BranchTakenSpec .cbz reg bit = decide (reg = 0) from rfl]
  · rw [show value .cbnz reg bit = decide (reg ≠ 0) from rfl,
        show arm64BranchTakenSpec .cbnz reg bit = decide (reg ≠ 0) from rfl]
  · rw [show value .tbz reg bit = decide (((reg >>> (bit &&& 63).toNat) &&& 1 : BitVec 64) = 0)
          from rfl,
        show arm64BranchTakenSpec .tbz reg bit =
          decide ((reg.toNat >>> (bit.toNat % 64)) % 2 = 0) from rfl,
        decide_eq_decide]
    rw [show (((reg >>> (bit &&& 63).toNat) &&& 1 : BitVec 64) = 0) ↔
          (((reg >>> (bit &&& 63).toNat) &&& 1 : BitVec 64).toNat = 0) from
          (BitVec.toNat_eq.trans
            (by simp [show BitVec.toNat (0 : BitVec 64) = 0 from rfl])),
        arm64BranchBitOf]
  · rw [show value .tbnz reg bit = decide (((reg >>> (bit &&& 63).toNat) &&& 1 : BitVec 64) = 1)
          from rfl,
        show arm64BranchTakenSpec .tbnz reg bit =
          decide ((reg.toNat >>> (bit.toNat % 64)) % 2 = 1) from rfl,
        decide_eq_decide]
    rw [show (((reg >>> (bit &&& 63).toNat) &&& 1 : BitVec 64) = 1) ↔
          (((reg >>> (bit &&& 63).toNat) &&& 1 : BitVec 64).toNat = 1) from
          (BitVec.toNat_eq.trans
            (by simp [show BitVec.toNat (1 : BitVec 64) = 1 from rfl])),
        arm64BranchBitOf]

/-- The branch predicate selects the same next program counter as the independent
statement: taking the predicate steps to the branch target, otherwise the
fall-through address is next. This is the predicate half of the
condition-to-next-PC relation; the flag-based half is
`arm64_conditional_branch_refines`. -/
theorem arm64_branch_next_pc_refines (kind : Branch) (reg bit : BitVec 64)
    (fallthrough target : Nat) :
    (if value kind reg bit then target else fallthrough) =
      (if arm64BranchTakenSpec kind reg bit then target else fallthrough) := by
  rw [arm64_branch_refines]

/-- Every branch predicate kind of the generated enum is inside the contiguous
case-label range `0U..3U` the shared C macro switches on, so the macro is total
and no unsupported arm is needed. -/
theorem arm64_branch_code_in_range (kind : Branch) :
    GeneratedArm64Branch.code kind < 4 := by
  cases kind <;> decide

/-- The generated kind dispatch: the four mnemonics map onto the four numeric
case labels in table order. -/
theorem arm64_branch_code_dispatch :
    GeneratedArm64Branch.code .cbz = 0 ∧
    GeneratedArm64Branch.code .cbnz = 1 ∧
    GeneratedArm64Branch.code .tbz = 2 ∧
    GeneratedArm64Branch.code .tbnz = 3 := by
  decide

/-- Canonical example: CBZ is taken for a zero register. -/
theorem arm64_branch_cbz_example :
    arm64BranchTakenSpec .cbz 0 0 = true := by
  native_decide

/-- Canonical example: CBZ is not taken for a nonzero register. -/
theorem arm64_branch_cbz_untaken_example :
    arm64BranchTakenSpec .cbz 1 0 = false := by
  native_decide

/-- Canonical example: TBNZ is taken when the tested bit is set. -/
theorem arm64_branch_tbnz_example :
    arm64BranchTakenSpec .tbnz 0x4 2 = true := by
  native_decide

/-- Canonical example: TBZ is taken when the tested bit is clear. -/
theorem arm64_branch_tbz_example :
    arm64BranchTakenSpec .tbz 0x4 1 = true := by
  native_decide

end KProgFormal
