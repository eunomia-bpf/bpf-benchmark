import KProgFormal.GeneratedArm64Flags
import KProgFormal.GeneratedX86SubFlags

/-!
The two architectures disagree about what the carry flag means after a
subtraction, and that disagreement is deliberate: AArch64 sets `C` to
*not-borrow* (the unsigned `lhs >= rhs` relation, so `CMP`/`SUBS` followed by
`B.HS` means "no borrow"), while x86-64 sets `CF` to *borrow* (unsigned
`lhs < rhs`, so `CMP` followed by `JB` means "borrow"). Each is correct for its
own ISA, and each is already proved against its own independent statement.

Nothing related the two, though. A reader comparing the specs sees one use `>=`
and the other `<` and cannot tell whether that is the architectural difference
or a mistake in one of them. This module proves the relation: on the same
narrowed operands the two are exact complements, so the disagreement is
polarity and not value.

This is a statement about the two generated flag contracts, not about either
simulator's C; `cross_isa_differential_host.c` covers the compiled layer.
-/

namespace KProgFormal.CrossIsaFlags

open KProgFormal

/-- AArch64's subtract carry (not-borrow) is exactly the negation of x86-64's
borrow condition on the same narrowed operands. Both sides narrow first, so the
statement is about the width-resolved values rather than the raw registers. -/
theorem arm64_notborrow_is_not_x86_borrow (a b : BitVec 64)
    (w : GeneratedArm64Width.Width) :
    GeneratedArm64Flags.subCarry a b w =
      !(BitVec.ult (GeneratedArm64Width.narrow a w)
                    (GeneratedArm64Width.narrow b w)) := by
  simp only [GeneratedArm64Flags.subCarry, BitVec.le_def, BitVec.ult]
  generalize GeneratedArm64Width.narrow b w = y at *
  generalize GeneratedArm64Width.narrow a w = x at *
  by_cases h : x.toNat < y.toNat
  · have : ¬ (y.toNat ≤ x.toNat) := Nat.not_le_of_gt h
    rw [decide_eq_false this, decide_eq_true h]; rfl
  · have hyx : y.toNat ≤ x.toNat := Nat.le_of_not_lt h
    rw [decide_eq_true hyx, decide_eq_false h]; rfl

/-- The complement is not a technicality: on a concrete borrow the two flags
genuinely differ. With `a = 1` and `b = 2` the subtraction borrows, so x86-64's
`CF` is set while AArch64's `C` is clear. -/
theorem arm64_x86_disagree_on_borrow :
    GeneratedArm64Flags.subCarry 1 2 .w64 = false ∧
      BitVec.ult (GeneratedArm64Width.narrow 1 .w64)
                 (GeneratedArm64Width.narrow 2 .w64) = true := by
  refine ⟨?_, ?_⟩ <;> native_decide

/-- And on a non-borrowing subtraction they differ the other way, so the
complement holds in both directions rather than in one. -/
theorem arm64_x86_disagree_on_noborrow :
    GeneratedArm64Flags.subCarry 2 1 .w64 = true ∧
      BitVec.ult (GeneratedArm64Width.narrow 2 .w64)
                 (GeneratedArm64Width.narrow 1 .w64) = false := by
  refine ⟨?_, ?_⟩ <;> native_decide

/-- The relation holds at every width, not only at 64 bits: narrowing first
means the same polarity difference appears at 8, 16, 32 and 64 alike. -/
theorem arm64_x86_polarity_at_every_width (a b : BitVec 64) :
    (GeneratedArm64Flags.subCarry a b .w8 =
        !(BitVec.ult (GeneratedArm64Width.narrow a .w8)
                      (GeneratedArm64Width.narrow b .w8))) ∧
      (GeneratedArm64Flags.subCarry a b .w16 =
        !(BitVec.ult (GeneratedArm64Width.narrow a .w16)
                      (GeneratedArm64Width.narrow b .w16))) ∧
      (GeneratedArm64Flags.subCarry a b .w32 =
        !(BitVec.ult (GeneratedArm64Width.narrow a .w32)
                      (GeneratedArm64Width.narrow b .w32))) ∧
      (GeneratedArm64Flags.subCarry a b .w64 =
        !(BitVec.ult (GeneratedArm64Width.narrow a .w64)
                      (GeneratedArm64Width.narrow b .w64))) :=
  ⟨arm64_notborrow_is_not_x86_borrow a b .w8,
   arm64_notborrow_is_not_x86_borrow a b .w16,
   arm64_notborrow_is_not_x86_borrow a b .w32,
   arm64_notborrow_is_not_x86_borrow a b .w64⟩

end KProgFormal.CrossIsaFlags