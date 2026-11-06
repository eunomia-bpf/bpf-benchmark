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

/-- The generated immediate/register selectors feed one shared arithmetic
body, including both scalar and pointer ADD write arms. -/
def arithmeticHandlerStep (width : Width) (subtract setFlags sourceIsScalar sourceIsImmediate : Bool)
    (dst src : Reference.AArch64.RegisterRef) (immediate register : Reference.Word) (s : Reference.AArch64.State) :
    Transition Reference.AArch64.State :=
  let lhs := Arm64Move.readData s src
  let flagOp := if subtract then
      if sourceIsImmediate then GeneratedArm64FlagOperand.FlagOp.subsImm else .subsReg
    else if sourceIsImmediate then .addsImm else .addsReg
  let rhs := if setFlags then
      if GeneratedArm64FlagOperand.immediate flagOp then immediate else register
    else if GeneratedArm64AluOperandSelect.immediate (if sourceIsImmediate then .aluImm else .aluReg)
      then immediate else register
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

def immediateHandlerStep (width : Width) (subtract setFlags sourceIsScalar : Bool)
    (dst src : Reference.AArch64.RegisterRef) (rhs : Reference.Word) (s : Reference.AArch64.State) :
    Transition Reference.AArch64.State :=
  arithmeticHandlerStep width subtract setFlags sourceIsScalar true dst src rhs 0 s

theorem family_flags_refines (width : Width) (subtract : Bool) (lhs rhs old : Reference.Word) :
    Arm64Logic.flagsWord old
      (GeneratedArm64FlagHandler.flags (if subtract then .sub else .add) lhs rhs
        (Arm64Register.handlerWidth width)) = Reference.AArch64.arithmeticFlags width subtract lhs rhs old := by
  cases subtract
  · exact flags_refines width false lhs rhs old
  · exact flags_refines width true lhs rhs old

theorem arithmetic_step_refines (width : Width) (subtract setFlags sourceIsScalar sourceIsImmediate : Bool)
    (dst src : Reference.AArch64.RegisterRef) (immediate register : Reference.Word) (s : Reference.AArch64.State) :
    arithmeticHandlerStep width subtract setFlags sourceIsScalar sourceIsImmediate dst src immediate register s =
      Reference.AArch64.arithmeticImmediateStep width subtract setFlags dst src
        (if sourceIsImmediate then immediate else register) s := by
  simp only [arithmeticHandlerStep, family_flags_refines]
  cases width <;> cases subtract <;> cases setFlags <;> cases sourceIsScalar <;> cases sourceIsImmediate <;>
    simp [Reference.AArch64.arithmeticImmediateStep,
      Arm64Move.read_data_refines, Arm64Move.width_write_refines, Arm64Register.handlerWidth,
      GeneratedArm64FlagOperand.immediate, GeneratedArm64AluOperandSelect.immediate,
      GeneratedArm64AluHandler.usePointer, GeneratedArm64AluResult.result, GeneratedPtrAdd.bits]

theorem immediate_step_refines (width : Width) (subtract setFlags sourceIsScalar : Bool)
    (dst src : Reference.AArch64.RegisterRef) (rhs : Reference.Word) (s : Reference.AArch64.State) :
    immediateHandlerStep width subtract setFlags sourceIsScalar dst src rhs s =
      Reference.AArch64.step (.arithmeticImmediate width subtract setFlags dst src rhs) s :=
  arithmetic_step_refines width subtract setFlags sourceIsScalar true dst src rhs 0 s

theorem immediate_handler_refines (width : Width) (subtract setFlags sourceIsScalar : Bool)
    (dst src : Reference.AArch64.RegisterRef) (rhs : Reference.Word) (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.arithmeticImmediate width subtract setFlags dst src rhs) s
      (immediateHandlerStep width subtract setFlags sourceIsScalar dst src rhs s) :=
  (immediate_step_refines width subtract setFlags sourceIsScalar dst src rhs s).symm

/-- Compare-only arithmetic shares the generated flag family while using
its own immediate/register operand selector and omitting register writeback. -/
def compareArithmeticHandlerStep (width : Width) (subtract sourceIsImmediate : Bool)
    (src : Reference.AArch64.RegisterRef) (immediate register : Reference.Word) (s : Reference.AArch64.State) :
    Transition Reference.AArch64.State :=
  let flagOp := if sourceIsImmediate then GeneratedArm64FlagOperand.FlagOp.cmpImm else .cmpReg
  let rhs := if subtract then
      if GeneratedArm64FlagOperand.immediate flagOp then immediate else register
    else if sourceIsImmediate then immediate else register
  let flags := GeneratedArm64FlagHandler.flags (if subtract then .sub else .add)
    (Arm64Move.readData s src) rhs (Arm64Register.handlerWidth width)
  ⟨{ s with flags := Arm64Logic.flagsWord s.flags flags, pc := s.pc + 4 }, [], none⟩

def compareImmediateHandlerStep (width : Width) (subtract : Bool)
    (src : Reference.AArch64.RegisterRef) (rhs : Reference.Word) (s : Reference.AArch64.State) :
    Transition Reference.AArch64.State :=
  compareArithmeticHandlerStep width subtract true src rhs 0 s

theorem compare_arithmetic_refines (width : Width) (subtract sourceIsImmediate : Bool)
    (src : Reference.AArch64.RegisterRef) (immediate register : Reference.Word) (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.arithmeticImmediate width subtract true .zero src
      (if sourceIsImmediate then immediate else register)) s
      (compareArithmeticHandlerStep width subtract sourceIsImmediate src immediate register s) := by
  unfold Reference.AArch64.Step
  simp only [compareArithmeticHandlerStep, Reference.AArch64.step, Reference.AArch64.arithmeticImmediateStep,
    Reference.AArch64.writeData, ↓reduceIte, family_flags_refines, Arm64Move.read_data_refines]
  cases subtract <;> cases sourceIsImmediate <;> rfl

theorem immediate_compare_alias_refines (width : Width) (subtract : Bool)
    (src : Reference.AArch64.RegisterRef) (rhs : Reference.Word) (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.arithmeticImmediate width subtract true .zero src rhs) s
      (compareImmediateHandlerStep width subtract src rhs s) :=
  compare_arithmetic_refines width subtract true src rhs 0 s

set_option maxHeartbeats 4000000 in
theorem rhs_normalization (width : Width) (subtract : Bool) (lhs rhs old : Reference.Word) :
    (Reference.AArch64.narrow (if subtract then lhs - rhs else lhs + rhs) width,
      Reference.AArch64.arithmeticFlags width subtract lhs rhs old) =
    (Reference.AArch64.narrow (if subtract then lhs - Reference.AArch64.narrow rhs width
      else lhs + Reference.AArch64.narrow rhs width) width,
      Reference.AArch64.arithmeticFlags width subtract lhs (Reference.AArch64.narrow rhs width) old) := by
  cases width <;> cases subtract <;>
    simp only [Reference.AArch64.narrow, Reference.AArch64.Width.bits,
      Reference.AArch64.arithmeticFlags, Reference.Word, Bool.false_eq_true, if_true, if_false] <;>
    apply Prod.ext <;> first | rfl | bv_decide (config := { timeout := 60 })

theorem step_rhs_normalization (width : Width) (subtract setFlags : Bool)
    (dst src : Reference.AArch64.RegisterRef) (rhs : Reference.Word) (s : Reference.AArch64.State) :
    Reference.AArch64.arithmeticImmediateStep width subtract setFlags dst src rhs s =
      Reference.AArch64.arithmeticImmediateStep width subtract setFlags dst src (Reference.AArch64.narrow rhs width) s := by
  have both := rhs_normalization width subtract (Reference.AArch64.readData s src) rhs s.flags
  have values := congrArg Prod.fst both
  have flags := congrArg Prod.snd both
  dsimp only at values flags
  cases dst <;>
    simp only [Reference.AArch64.arithmeticImmediateStep, Reference.AArch64.writeData, values, flags]

theorem shift_modifier_refines (width : Width) (kind : Reference.AArch64.ShiftKind)
    (value amount : Reference.Word) :
    Reference.AArch64.narrow
      (GeneratedArm64Mod.value (Arm64Shift.modifier kind) value amount (Arm64Register.handlerWidth width)) width =
      Reference.AArch64.shiftValue width kind value amount := by
  cases width <;> cases kind <;>
    simp only [GeneratedArm64Mod.value, Arm64Shift.modifier, Arm64Register.handlerWidth,
      GeneratedArm64Width.mask, Reference.AArch64.narrow, Reference.AArch64.Width.bits,
      Reference.AArch64.shiftValue, Reference.AArch64.extractValue,
      Reference.AArch64.extractRawWindow, Reference.Word] <;> bv_decide

/-- Objdump omits an LSL-by-zero suffix; that form uses the actual NONE
modifier, whose untrimmed temporary is handled by width normalization. -/
def registerModifier (width : Width) (kind : Fin 3) (amount : Fin width.bits) : GeneratedArm64ModDecode.Mod :=
  if kind.val = 0 ∧ amount.val = 0 then .none
  else Arm64Shift.modifier (Reference.AArch64.arithmeticShift kind)

theorem register_modifier_refines (width : Width) (kind : Fin 3) (amount : Fin width.bits)
    (value : Reference.Word) :
    Reference.AArch64.narrow
      (GeneratedArm64Mod.value (registerModifier width kind amount) value (BitVec.ofNat 64 amount.val)
        (Arm64Register.handlerWidth width)) width =
      Reference.AArch64.shiftValue width (Reference.AArch64.arithmeticShift kind) value (BitVec.ofNat 64 amount.val) := by
  by_cases h : kind.val = 0 ∧ amount.val = 0
  · simp only [registerModifier, if_pos h, h.1, h.2, GeneratedArm64Mod.value,
      Reference.AArch64.arithmeticShift, Reference.AArch64.shiftValue]
    cases width <;>
      simp only [Reference.AArch64.narrow, Reference.AArch64.Width.bits, Reference.Word] <;> bv_decide
  · simp only [registerModifier, if_neg h]
    exact shift_modifier_refines width (Reference.AArch64.arithmeticShift kind) value (BitVec.ofNat 64 amount.val)

def registerHandlerStep (width : Width) (subtract setFlags sourceIsScalar : Bool)
    (dst src : Reference.AArch64.RegisterRef) (rhs : Register) (kind : Fin 3) (amount : Fin width.bits)
    (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let value := GeneratedArm64Mod.value (registerModifier width kind amount)
    (Arm64Register.readReg s rhs) (BitVec.ofNat 64 amount.val) (Arm64Register.handlerWidth width)
  arithmeticHandlerStep width subtract setFlags sourceIsScalar false dst src 0 value s

theorem register_step_refines (width : Width) (subtract setFlags sourceIsScalar : Bool)
    (dst src : Reference.AArch64.RegisterRef) (rhs : Register) (kind : Fin 3) (amount : Fin width.bits)
    (s : Reference.AArch64.State) :
    registerHandlerStep width subtract setFlags sourceIsScalar dst src rhs kind amount s =
      Reference.AArch64.step (.arithmeticRegister width subtract setFlags dst src rhs kind amount) s := by
  unfold registerHandlerStep
  rw [arithmetic_step_refines]
  simp only [Bool.false_eq_true, ↓reduceIte]
  conv =>
    lhs
    rw [step_rhs_normalization]
  simp only [Arm64Register.read_refines, register_modifier_refines]
  rfl

theorem register_handler_refines (width : Width) (subtract setFlags sourceIsScalar : Bool)
    (dst src : Reference.AArch64.RegisterRef) (rhs : Register) (kind : Fin 3) (amount : Fin width.bits)
    (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.arithmeticRegister width subtract setFlags dst src rhs kind amount) s
      (registerHandlerStep width subtract setFlags sourceIsScalar dst src rhs kind amount s) :=
  (register_step_refines width subtract setFlags sourceIsScalar dst src rhs kind amount s).symm

def compareRegisterHandlerStep (width : Width) (subtract : Bool)
    (src : Reference.AArch64.RegisterRef) (rhs : Register) (kind : Fin 3) (amount : Fin width.bits)
    (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let value := GeneratedArm64Mod.value (registerModifier width kind amount)
    (Arm64Register.readReg s rhs) (BitVec.ofNat 64 amount.val) (Arm64Register.handlerWidth width)
  compareArithmeticHandlerStep width subtract false src 0 value s

theorem register_compare_alias_refines (width : Width) (subtract : Bool)
    (src : Reference.AArch64.RegisterRef) (rhs : Register) (kind : Fin 3) (amount : Fin width.bits)
    (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.arithmeticRegister width subtract true .zero src rhs kind amount) s
      (compareRegisterHandlerStep width subtract src rhs kind amount s) := by
  have h := compare_arithmetic_refines width subtract false src 0
    (GeneratedArm64Mod.value (registerModifier width kind amount)
      (Arm64Register.readReg s rhs) (BitVec.ofNat 64 amount.val) (Arm64Register.handlerWidth width)) s
  simp only [Bool.false_eq_true, ↓reduceIte] at h
  unfold Reference.AArch64.Step at *
  unfold compareRegisterHandlerStep
  rw [← h]
  simp only [Reference.AArch64.step, Reference.AArch64.arithmeticRegisterStep]
  symm
  calc
    _ = _ := step_rhs_normalization width subtract true .zero src _ s
    _ = _ := by rw [Arm64Register.read_refines, register_modifier_refines]

end KProgFormal.Refinement.Arm64Arithmetic
