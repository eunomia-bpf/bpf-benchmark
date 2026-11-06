import KProgFormal.Refinement.X86Cmov
import KProgFormal.Refinement.X86Scalar
import KProgFormal.Generated.GeneratedX86FullCondition

namespace KProgFormal.Refinement.X86Condition
open Reference

def evaluate (code : Fin 16) (flags : Reference.Word) : Option Bool :=
  GeneratedX86FullCondition.eval (BitVec.ofNat 32 code.val)
    (flags.getLsbD 0) (flags.getLsbD 6) (flags.getLsbD 7) (flags.getLsbD 11) (flags.getLsbD 2)

theorem matched_code (code : Fin 16) :
    GeneratedX86FullCondition.matched (BitVec.ofNat 8 code.val) = BitVec.ofNat 16 code.val := by
  have all : ∀ c : Fin 16,
      GeneratedX86FullCondition.matched (BitVec.ofNat 8 c.val) = BitVec.ofNat 16 c.val := by decide
  exact all code

theorem condition_refines (code : Fin 16) (flags : Reference.Word) :
    evaluate code flags = some (Reference.X86.condition flags code) := by
  obtain ⟨n, bound⟩ := code
  have choices : n = 0 ∨ n = 1 ∨ n = 2 ∨ n = 3 ∨ n = 4 ∨ n = 5 ∨ n = 6 ∨ n = 7 ∨
      n = 8 ∨ n = 9 ∨ n = 10 ∨ n = 11 ∨ n = 12 ∨ n = 13 ∨ n = 14 ∨ n = 15 := by omega
  rcases choices with h | h | h | h | h | h | h | h | h | h | h | h | h | h | h | h <;>
    subst n <;> simp [evaluate, GeneratedX86FullCondition.eval, GeneratedX86Cond.eval, Reference.X86.condition]

/-- This extends the retained fourteen-condition CMOV proof to every native
condition, reusing its generated value/writeback contract and eager reads. -/
def cmovStep (width : Reference.X86.CmovWidth) (code : Fin 16) (dst : Reference.X86.Register)
    (source : Reference.X86.Source) (nextPc : Reference.Word) (s : Reference.X86.State)
    (dstTag sourceTag : Tag) : Option (Transition Reference.X86.State) :=
  match Reference.X86.readSource s source width.bytes with
  | .error fault => some ⟨s, [.fault fault], some fault⟩
  | .ok (value, events) => do
      let taken ← evaluate code s.rflags
      let result := X86Cmov.handlerValue width taken ⟨s.gpr dst, dstTag⟩ ⟨value, sourceTag⟩
      return ⟨{ s with gpr := fun r => if r = dst then result.bits else s.gpr r, pc := nextPc }, events, none⟩

theorem cmov_refines (width : Reference.X86.CmovWidth) (code : Fin 16) (dst : Reference.X86.Register)
    (source : Reference.X86.Source) (nextPc : Reference.Word) (s : Reference.X86.State)
    (dstTag sourceTag : Tag) :
    cmovStep width code dst source nextPc s dstTag sourceTag =
      some (Reference.X86.step (.cmov width code dst source nextPc) s) := by
  cases h : Reference.X86.readSource s source width.bytes with
  | error fault => simp [cmovStep, Reference.X86.step, h]
  | ok pair =>
      rcases pair with ⟨value, events⟩
      simp [cmovStep, Reference.X86.step, h, condition_refines, X86Cmov.value_refines]

def setccStep (code : Fin 16) (dst : Reference.X86.ScalarDestination) (nextPc : Reference.Word)
    (s : Reference.X86.State) : Option (Transition Reference.X86.State) := do
  let matched := GeneratedX86FullCondition.matched (BitVec.ofNat 8 code.val)
  let taken ← GeneratedX86FullCondition.eval (matched.setWidth 32)
    (s.rflags.getLsbD 0) (s.rflags.getLsbD 6) (s.rflags.getLsbD 7)
    (s.rflags.getLsbD 11) (s.rflags.getLsbD 2)
  return match X86Scalar.write s .w8 dst (if taken then 1 else 0) with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (result, events) => ⟨{ result with pc := nextPc }, events, none⟩

theorem setcc_refines (code : Fin 16) (dst : Reference.X86.ScalarDestination) (nextPc : Reference.Word)
    (s : Reference.X86.State) :
    setccStep code dst nextPc s = some (Reference.X86.step (.setcc code dst nextPc) s) := by
  have fits : (BitVec.ofNat 16 code.val).setWidth 32 = BitVec.ofNat 32 code.val := by
    apply BitVec.eq_of_toNat_eq
    simp [BitVec.toNat_setWidth, Nat.mod_eq_of_lt (show code.val < 65536 by omega),
      Nat.mod_eq_of_lt (show code.val < 4294967296 by omega)]
  have evaluated := condition_refines code s.rflags
  unfold evaluate at evaluated
  simp only [setccStep, matched_code, fits, evaluated, Option.bind_some,
    X86Scalar.write_refines, Reference.X86.step]
  rfl

/-- The forward and backward generated goto shapes select this same PC;
neither shape decrements fuel or changes architectural state. -/
def branchStep (code : Option (Fin 16)) (target nextPc : Reference.Word) (s : Reference.X86.State) :
    Option (Transition Reference.X86.State) := do
  let taken ← match code with | none => some true | some cc => evaluate cc s.rflags
  return ⟨{ s with pc := if taken then target else nextPc }, [], none⟩

theorem branch_refines (code : Option (Fin 16)) (target nextPc : Reference.Word) (s : Reference.X86.State) :
    branchStep code target nextPc s = some (Reference.X86.step (.branch code target nextPc) s) := by
  cases code <;> simp [branchStep, condition_refines, Reference.X86.step]

theorem nop_refines (nextPc : Reference.Word) (s : Reference.X86.State) :
    (⟨{ s with pc := nextPc }, [], none⟩ : Transition Reference.X86.State) =
      Reference.X86.step (.nop nextPc) s := rfl

end KProgFormal.Refinement.X86Condition
