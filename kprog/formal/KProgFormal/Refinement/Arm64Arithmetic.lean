import KProgFormal.Refinement.Arm64Logic
import KProgFormal.Refinement.Arm64Condition
import KProgFormal.Refinement.Arm64Move
import KProgFormal.Generated.GeneratedArm64AluHandler
import KProgFormal.Generated.GeneratedArm64AluOperandSelect
import KProgFormal.Generated.GeneratedArm64FlagHandler
import KProgFormal.Generated.GeneratedPtrAdd
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

/-- Both immediate routing tables select the decoded immediate. The pointer
ADD branch is included for either input tag classification; its architectural
bits use the same source-value lift as the scalar branch. -/
def immediateHandlerStep (width : Width) (subtract setFlags sourceIsScalar : Bool)
    (dst src : Reference.AArch64.RegisterRef) (rhs : Reference.Word) (s : Reference.AArch64.State) :
    Transition Reference.AArch64.State :=
  let lhs := Arm64Move.readData s src
  let rhs := if setFlags then
      if GeneratedArm64FlagOperand.immediate (if subtract then .subsImm else .addsImm) then rhs else 0
    else if GeneratedArm64AluOperandSelect.immediate .aluImm then rhs else 0
  let op := if subtract then GeneratedArm64AluDecode.Alu.sub else .add
  let value := GeneratedArm64AluResult.result op lhs rhs
  let write := if !setFlags && GeneratedArm64AluHandler.usePointer (Arm64Register.handlerWidth width)
      op (decide (dst = .stack)) sourceIsScalar then
      Arm64Move.widthWrite s dst (GeneratedPtrAdd.bits lhs rhs) .w64
    else Arm64Move.widthWrite s dst value width
  let flags := if setFlags then Arm64Logic.flagsWord s.flags
      (GeneratedArm64FlagHandler.flags (if subtract then .sub else .add) lhs rhs
        (Arm64Register.handlerWidth width)) else s.flags
  ⟨{ write with flags := flags, pc := s.pc + 4 }, [], none⟩

theorem family_flags_refines (width : Width) (subtract : Bool) (lhs rhs old : Reference.Word) :
    Arm64Logic.flagsWord old
      (GeneratedArm64FlagHandler.flags (if subtract then .sub else .add) lhs rhs
        (Arm64Register.handlerWidth width)) = Reference.AArch64.arithmeticFlags width subtract lhs rhs old := by
  cases subtract
  · exact flags_refines width false lhs rhs old
  · exact flags_refines width true lhs rhs old

theorem immediate_step_refines (width : Width) (subtract setFlags sourceIsScalar : Bool)
    (dst src : Reference.AArch64.RegisterRef) (rhs : Reference.Word) (s : Reference.AArch64.State) :
    immediateHandlerStep width subtract setFlags sourceIsScalar dst src rhs s =
      Reference.AArch64.step (.arithmeticImmediate width subtract setFlags dst src rhs) s := by
  simp only [immediateHandlerStep, family_flags_refines]
  cases width <;> cases subtract <;> cases setFlags <;> cases sourceIsScalar <;>
    simp [immediateHandlerStep, Reference.AArch64.step, Reference.AArch64.arithmeticImmediateStep,
      Arm64Move.read_data_refines, Arm64Move.width_write_refines, Arm64Register.handlerWidth,
      GeneratedArm64FlagOperand.immediate, GeneratedArm64AluOperandSelect.immediate,
      GeneratedArm64AluHandler.usePointer, GeneratedArm64AluResult.result, GeneratedPtrAdd.bits,
      family_flags_refines]

theorem immediate_handler_refines (width : Width) (subtract setFlags sourceIsScalar : Bool)
    (dst src : Reference.AArch64.RegisterRef) (rhs : Reference.Word) (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.arithmeticImmediate width subtract setFlags dst src rhs) s
      (immediateHandlerStep width subtract setFlags sourceIsScalar dst src rhs s) :=
  (immediate_step_refines width subtract setFlags sourceIsScalar dst src rhs s).symm

/-- CMP and CMN use the compare body, which updates flags without a
writeback. CMP selects its immediate through the generated flag table. -/
def compareImmediateHandlerStep (width : Width) (subtract : Bool)
    (src : Reference.AArch64.RegisterRef) (rhs : Reference.Word) (s : Reference.AArch64.State) :
    Transition Reference.AArch64.State :=
  let rhs := if subtract then
      if GeneratedArm64FlagOperand.immediate .cmpImm then rhs else 0 else rhs
  let flags := GeneratedArm64FlagHandler.flags (if subtract then .sub else .add)
    (Arm64Move.readData s src) rhs (Arm64Register.handlerWidth width)
  ⟨{ s with flags := Arm64Logic.flagsWord s.flags flags, pc := s.pc + 4 }, [], none⟩

theorem immediate_compare_alias_refines (width : Width) (subtract : Bool)
    (src : Reference.AArch64.RegisterRef) (rhs : Reference.Word) (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.arithmeticImmediate width subtract true .zero src rhs) s
      (compareImmediateHandlerStep width subtract src rhs s) := by
  unfold Reference.AArch64.Step
  simp only [compareImmediateHandlerStep, Reference.AArch64.step, Reference.AArch64.arithmeticImmediateStep,
    Reference.AArch64.writeData, GeneratedArm64FlagOperand.immediate, ↓reduceIte,
    family_flags_refines, Arm64Move.read_data_refines]
  cases subtract <;> rfl

end KProgFormal.Refinement.Arm64Arithmetic
