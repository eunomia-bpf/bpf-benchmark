import KProgFormal.Refinement.Arm64Logic
import KProgFormal.Refinement.Arm64Condition
import KProgFormal.Generated.GeneratedArm64CcmpHandler
import KProgFormal.Generated.GeneratedArm64FlagOperand

namespace KProgFormal.Refinement.Arm64Arithmetic

open Reference
open Reference.AArch64 (Width Register CompareOperand)

set_option maxRecDepth 4096 in
set_option maxHeartbeats 4000000 in
theorem flags_refines (width : Width) (subtract : Bool) (lhs rhs old : Reference.Word) :
    Arm64Logic.flagsWord old
      (if subtract then GeneratedArm64Flags.applySub lhs rhs (Arm64Register.handlerWidth width)
        else GeneratedArm64Flags.applyAdd lhs rhs (Arm64Register.handlerWidth width)) =
      Reference.AArch64.arithmeticFlags width subtract lhs rhs old := by
  cases width <;> cases subtract <;>
    simp only [Arm64Logic.flagsWord, Reference.AArch64.arithmeticFlags, Reference.AArch64.Width.bits,
      Arm64Register.handlerWidth, GeneratedArm64Flags.applySub,
      GeneratedArm64Flags.applyAdd, GeneratedArm64Flags.subCarry, GeneratedArm64Flags.subOverflow,
      GeneratedArm64Flags.addCarry, GeneratedArm64Flags.addOverflow,
      GeneratedArm64Width.narrow, GeneratedArm64Width.mask, GeneratedArm64Width.sign,
      GeneratedArm64Width.signMask, GeneratedArm64Width.bits, Reference.Word,
      Bool.false_eq_true, if_true, if_false] <;>
    bv_decide (config := { timeout := 60 })

def incomingFlags (old : Reference.Word) : GeneratedArm64Flags.Flags :=
  ⟨old.getLsbD 31, old.getLsbD 30, old.getLsbD 29, old.getLsbD 28⟩

def operand (s : Reference.AArch64.State) : CompareOperand → Reference.Word
  | .register src => if GeneratedArm64FlagOperand.immediate .ccmpReg then 0 else Arm64Register.readReg s src
  | .immediate value => if GeneratedArm64FlagOperand.immediate .ccmpImm then value.setWidth 64 else 0

theorem operand_refines (s : Reference.AArch64.State) (rhs : CompareOperand) :
    operand s rhs = Reference.AArch64.compareOperand s rhs := by
  cases rhs <;> simp only [operand, GeneratedArm64FlagOperand.immediate, Bool.false_eq_true,
    ↓reduceIte, Arm64Register.read_refines, Reference.AArch64.compareOperand]

theorem fallback_refines (old : Reference.Word) (fallback : BitVec 4) :
    Arm64Logic.flagsWord old (GeneratedArm64CcmpHandler.fallbackFlags (fallback.setWidth 8)) =
      Reference.AArch64.compareFallback old fallback := by
  simp only [Arm64Logic.flagsWord, GeneratedArm64CcmpHandler.fallbackFlags,
    Reference.AArch64.compareFallback, Reference.Word]
  bv_decide

theorem conditional_flags_refines (width : Width) (predicate : Arm64Cond)
    (lhs rhs old : Reference.Word) (fallback : BitVec 4) :
    Arm64Logic.flagsWord old
      (GeneratedArm64CcmpHandler.apply (incomingFlags old) predicate lhs rhs
        (Arm64Register.handlerWidth width) (fallback.setWidth 8)).flags =
      if Reference.AArch64.condition old (Arm64Condition.nativeCode predicate) then
        Reference.AArch64.arithmeticFlags width true lhs rhs old
      else Reference.AArch64.compareFallback old fallback := by
  have bridge := Arm64Condition.condition_refines old predicate
  change GeneratedArm64Cond.eval (old.getLsbD 31) (old.getLsbD 30)
    (old.getLsbD 29) (old.getLsbD 28) predicate = _ at bridge
  simp only [GeneratedArm64CcmpHandler.apply, incomingFlags]
  simp only [bridge]
  split
  · exact flags_refines width true lhs rhs old
  · exact fallback_refines old fallback

def handlerStep (width : Width) (lhs : Register) (rhs : CompareOperand)
    (predicate : Arm64Cond) (fallback : BitVec 4) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let flags := (GeneratedArm64CcmpHandler.apply (incomingFlags s.flags) predicate
    (Arm64Register.readReg s lhs) (operand s rhs) (Arm64Register.handlerWidth width) (fallback.setWidth 8)).flags
  ⟨{ s with flags := Arm64Logic.flagsWord s.flags flags, pc := s.pc + 4 }, [], none⟩

theorem step_refines (width : Width) (lhs : Register) (rhs : CompareOperand)
    (predicate : Arm64Cond) (fallback : BitVec 4) (s : Reference.AArch64.State) :
    handlerStep width lhs rhs predicate fallback s =
      Reference.AArch64.step (.compare width lhs rhs (Arm64Condition.nativeCode predicate) fallback) s := by
  simp only [handlerStep, Reference.AArch64.step, Reference.AArch64.compareStep,
    conditional_flags_refines, Arm64Register.read_refines, operand_refines]

theorem handler_refines (width : Width) (lhs : Register) (rhs : CompareOperand)
    (predicate : Arm64Cond) (fallback : BitVec 4) (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.compare width lhs rhs (Arm64Condition.nativeCode predicate) fallback) s
      (handlerStep width lhs rhs predicate fallback s) :=
  (step_refines width lhs rhs predicate fallback s).symm

theorem nv_handler_refines (width : Width) (lhs : Register) (rhs : CompareOperand)
    (fallback : BitVec 4) (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.compare width lhs rhs 15 fallback) s
      (handlerStep width lhs rhs .al fallback s) := handler_refines width lhs rhs .al fallback s

end KProgFormal.Refinement.Arm64Arithmetic
