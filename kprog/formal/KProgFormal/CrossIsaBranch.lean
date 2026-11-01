import KProgFormal.GeneratedArm64BranchEmit
import KProgFormal.GeneratedX86BranchEmit
import KProgFormal.GeneratedArm64Cond
import KProgFormal.GeneratedX86Cond
import KProgFormal.Arm64ControlFlow
import KProgFormal.X86ControlFlow
import KProgFormal.CrossIsaCond

/-!
Every cross-ISA module so far compared one contract at a time: a mask, a flag,
an operand shape. The control-flow path is different in kind, because the
interesting property is not that two contracts match but that two *chains*
compose to the same place.

Each ISA already proves its own chain in isolation. A condition evaluation
refines to the architectural predicate; the emitted shape selects the
architectural next program counter; and each of those refinements is proved
against its own generated contract. So on either ISA, flags in means the
architecturally correct next PC out.

Nothing showed the two chains agree with each other, and the risk is specific:
the chains are *not* the same shape internally. AArch64 evaluates four flags
`(N Z C V)` and x86-64 four flags `(CF ZF SF OF)` where C is the complement of
CF -- so an intermediate step differs even though the endpoints should not.
A chain that composed differently on one side would produce a divergent next PC
while every per-ISA theorem continued to hold, which is exactly the failure the
per-ISA work cannot see.

This module closes the chain end to end: from the same four *architectural*
flag facts, through each ISA's own condition evaluation and shape selection, to
one next program counter. The flag correspondence is the one Step 0490 proved
and Step 0493 carried through the conditions; what is new is that it now
composes through emission rather than stopping at the predicate.
-/

namespace KProgFormal.CrossIsaBranch

open KProgFormal

/-- AArch64's emitted next-PC selection is the architectural one, whatever
shape was chosen. Stated directly so the shape-independence is a fact rather
than something to rediscover. -/
theorem arm64_nextPc_is_architectural (current target : Nat) (taken : Bool)
    (fallthrough : Nat) :
    GeneratedArm64BranchEmit.nextPc
        (GeneratedArm64BranchEmit.shape current target) taken fallthrough target
      = branchPc taken fallthrough target := by
  unfold GeneratedArm64BranchEmit.nextPc branchPc
  split <;> rfl

/-- And x86-64's. The two are separate inductives with separate `nextPc`
definitions, so this is a statement about the second contract, not a restatement
of the first. -/
theorem x86_nextPc_is_architectural (current target : Nat) (taken : Bool)
    (fallthrough : Nat) :
    GeneratedX86BranchEmit.nextPc
        (GeneratedX86BranchEmit.shape current target) taken fallthrough target
      = branchPc taken fallthrough target := by
  unfold GeneratedX86BranchEmit.nextPc branchPc
  split <;> rfl

/-- **The composition.** From the same four architectural flag facts, the two
chains select the same next program counter.

The hypotheses are the flag values as an architecture-independent reader sees
them: a sign, a zero, a carry-set and an overflow. AArch64 consumes them
directly; x86-64 consumes the carry inverted, which is the polarity Step 0490
proved. Because that inversion is confined to the *intermediate* flag, the
endpoints agree -- and this theorem is what shows the inversion does not leak
through emission. -/
theorem chains_compose (sign zero carry overflow : Bool)
    (cond : GeneratedArm64Cond.Cond) (hcond : cond ≠ .al)
    (taken_ft target : Nat) :
    let a64flags : Arm64Flags :=
      { n := sign, z := zero, c := carry, v := overflow }
    let x86flags : X86Flags :=
      { cf := !carry, zf := zero, sf := sign, of := overflow }
    GeneratedArm64BranchEmit.nextPc
        (GeneratedArm64BranchEmit.shape taken_ft target)
        (generatedArm64Cond a64flags cond) taken_ft target
      = GeneratedX86BranchEmit.nextPc
          (GeneratedX86BranchEmit.shape taken_ft target)
          (generatedX86Cond x86flags (CrossIsaCond.toX86 cond))
          taken_ft target := by
  intro a64flags x86flags
  rw [arm64_nextPc_is_architectural, x86_nextPc_is_architectural]
  congr 1
  have h := CrossIsaCond.agrees (!carry) zero sign overflow cond hcond
  simpa only [generatedArm64Cond, generatedX86Cond, a64flags, x86flags,
              Bool.not_not] using h

/-- The shape the two pick is the same decision, even though they are distinct
types: a target at or below the current address is a backward edge on both.
Stated through `backward`, which is the only observable the shapes share. -/
theorem shape_agrees (current target : Nat) :
    GeneratedArm64BranchEmit.backward
        (GeneratedArm64BranchEmit.shape current target)
      = GeneratedX86BranchEmit.backward
          (GeneratedX86BranchEmit.shape current target) := by
  unfold GeneratedArm64BranchEmit.backward GeneratedX86BranchEmit.backward
  by_cases h : target ≤ current <;>
    simp [GeneratedArm64BranchEmit.shape, GeneratedX86BranchEmit.shape, h]

/-- A concrete instance of the composition, so the theorem is seen to decide
rather than merely to typecheck. A backward edge (`target ≤ current`) with a
zero result: both architectures branch on an equality test, and both land on
the target. -/
theorem chains_compose_concretely :
    let a64flags : Arm64Flags := { n := false, z := true, c := true, v := false }
    let x86flags : X86Flags := { cf := false, zf := true, sf := false, of := false }
    GeneratedArm64BranchEmit.nextPc
        (GeneratedArm64BranchEmit.shape 100 50)
        (generatedArm64Cond a64flags .eq) 100 50 = 50 ∧
      GeneratedX86BranchEmit.nextPc
          (GeneratedX86BranchEmit.shape 100 50)
          (generatedX86Cond x86flags .e) 100 50 = 50 := by
  decide

/-- And the negative case at the same site: with the zero flag clear, both fall
through. Together with the previous theorem this pins both directions of the
composition, so a chain that always branched would not pass. -/
theorem chains_compose_fallthrough :
    let a64flags : Arm64Flags := { n := false, z := false, c := true, v := false }
    let x86flags : X86Flags := { cf := false, zf := false, sf := false, of := false }
    GeneratedArm64BranchEmit.nextPc
        (GeneratedArm64BranchEmit.shape 100 50)
        (generatedArm64Cond a64flags .eq) 100 50 = 100 ∧
      GeneratedX86BranchEmit.nextPc
          (GeneratedX86BranchEmit.shape 100 50)
          (generatedX86Cond x86flags .e) 100 50 = 100 := by
  decide

end KProgFormal.CrossIsaBranch