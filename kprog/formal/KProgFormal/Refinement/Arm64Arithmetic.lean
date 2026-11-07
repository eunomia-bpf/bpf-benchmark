import KProgFormal.Refinement.Arm64Logic
import KProgFormal.Refinement.Arm64Condition
import KProgFormal.Refinement.Arm64Move
import KProgFormal.Generated.GeneratedArm64AluHandler
import KProgFormal.Generated.GeneratedArm64AluOperandSelect
import KProgFormal.Generated.GeneratedArm64FlagHandler
import KProgFormal.Generated.GeneratedPtrAdd
import KProgFormal.Generated.GeneratedArm64CcmpHandler
import KProgFormal.Generated.GeneratedArm64FlagOperand
import KProgFormal.Arm64Aux
import KProgFormal.Arm64CcmpDecode
import KProgFormal.Generated.GeneratedArm64DispatchFamily
import KProgFormal.Generated.GeneratedArm64DispatchSingleton

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

theorem normalized_compare_refines (width : Width) (subtract : Bool)
    (src : Reference.AArch64.RegisterRef) (rhs : Reference.Word) (s : Reference.AArch64.State) :
    Reference.AArch64.arithmeticImmediateStep width subtract true .zero src
      (Reference.AArch64.narrow rhs width) s = compareArithmeticHandlerStep width subtract false src 0 rhs s :=
  (step_rhs_normalization width subtract true .zero src rhs s).symm.trans
    (compare_arithmetic_refines width subtract false src 0 rhs s)

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
  unfold Reference.AArch64.Step compareRegisterHandlerStep
  rw [← normalized_compare_refines]
  rw [Arm64Register.read_refines, register_modifier_refines]
  rfl

def extensionModifier : Reference.AArch64.RegisterExtend → GeneratedArm64ModDecode.Mod
  | .uxtb => .uxtb | .uxth => .uxth | .uxtw => .uxtw | .uxtx => .lsl
  | .sxtb => .sxtb | .sxth => .sxth | .sxtw => .sxtw | .sxtx => .lsl

set_option maxHeartbeats 4000000 in
theorem extension_value_refines (width : Width) (kind : Reference.AArch64.RegisterExtend) (value amount : Reference.Word)
    (bounded : amount < 5) :
    Reference.AArch64.narrow
      (GeneratedArm64Mod.value (extensionModifier kind) value amount (Arm64Register.handlerWidth width)) width =
      Reference.AArch64.extendValue width kind value amount := by
  cases width <;> cases kind <;>
    simp only [GeneratedArm64Mod.value, extensionModifier, Arm64Register.handlerWidth,
      GeneratedArm64Width.mask, Reference.AArch64.narrow, Reference.AArch64.Width.bits,
      Reference.AArch64.extendValue, Reference.AArch64.RegisterExtend.bits, Reference.AArch64.RegisterExtend.signed, Reference.Word, Bool.false_eq_true, if_true, if_false] <;>
    (simp only [Nat.min_def, Nat.reduceLeDiff, if_true, if_false]; bv_decide (config := { timeout := 60 }))

theorem amount_bound (amount : Fin 5) : (BitVec.ofNat 64 amount.val : Reference.Word) < 5 := by
  change amount.val % 2^64 < 5
  omega

/-- A full-operand-size extension can print as LSL or a bare register.
Explicit extensions and both shift aliases use their actual generated selectors. -/
def extendedModifier (width : Width) (kind : Reference.AArch64.RegisterExtend) (amount : Reference.Word) (plainSource : Bool) :
    GeneratedArm64ModDecode.Mod :=
  if plainSource ∧ width.bits ≤ kind.bits then
    if amount = 0 then .none else .lsl
  else extensionModifier kind

theorem extended_modifier_refines (width : Width) (kind : Reference.AArch64.RegisterExtend)
    (value amount : Reference.Word) (plainSource : Bool) (bounded : amount < 5) :
    Reference.AArch64.narrow
      (GeneratedArm64Mod.value (extendedModifier width kind amount plainSource) value amount
        (Arm64Register.handlerWidth width)) width = Reference.AArch64.extendValue width kind value amount := by
  cases plainSource with
  | false =>
    simpa only [extendedModifier, Bool.false_eq_true, false_and, ↓reduceIte] using
      extension_value_refines width kind value amount bounded
  | true =>
    by_cases zero : amount = 0
    · subst amount
      cases width <;> cases kind <;>
        simp only [extendedModifier, extensionModifier, GeneratedArm64Mod.value, Arm64Register.handlerWidth,
          GeneratedArm64Width.mask, Reference.AArch64.narrow, Reference.AArch64.Width.bits,
          Reference.AArch64.extendValue, Reference.AArch64.RegisterExtend.bits, Reference.AArch64.RegisterExtend.signed,
          Reference.Word, Bool.false_eq_true, reduceCtorEq, false_and, true_and, and_false, and_true,
          false_or, true_or, or_false, or_true, ↓reduceIte, Nat.min_def, Nat.reduceLeDiff] <;>
        bv_decide
    · cases width <;> cases kind <;>
        simp only [extendedModifier, extensionModifier, zero, GeneratedArm64Mod.value, Arm64Register.handlerWidth,
          GeneratedArm64Width.mask, Reference.AArch64.narrow, Reference.AArch64.Width.bits,
          Reference.AArch64.extendValue, Reference.AArch64.RegisterExtend.bits, Reference.AArch64.RegisterExtend.signed,
          Reference.Word, Bool.false_eq_true, reduceCtorEq, false_and, true_and, and_false, and_true,
          false_or, true_or, or_false, or_true, ↓reduceIte, Nat.min_def, Nat.reduceLeDiff] <;>
        bv_decide (config := { timeout := 60 })

def extendedHandlerStep (width : Width) (subtract setFlags sourceIsScalar plainSource : Bool)
    (dst src : Reference.AArch64.RegisterRef) (rhs : Register) (kind : Reference.AArch64.RegisterExtend)
    (amount : Fin 5) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let value := GeneratedArm64Mod.value (extendedModifier width kind (BitVec.ofNat 64 amount.val) plainSource)
    (Arm64Register.readReg s rhs) (BitVec.ofNat 64 amount.val) (Arm64Register.handlerWidth width)
  arithmeticHandlerStep width subtract setFlags sourceIsScalar false dst src 0 value s

theorem extended_step_refines (width : Width) (subtract setFlags sourceIsScalar plainSource : Bool)
    (dst src : Reference.AArch64.RegisterRef) (rhs : Register) (kind : Reference.AArch64.RegisterExtend)
    (amount : Fin 5) (s : Reference.AArch64.State) :
    extendedHandlerStep width subtract setFlags sourceIsScalar plainSource dst src rhs kind amount s =
      Reference.AArch64.step (.arithmeticExtended width subtract setFlags dst src rhs kind amount) s := by
  unfold extendedHandlerStep
  rw [arithmetic_step_refines]
  simp only [Bool.false_eq_true, ↓reduceIte]
  conv =>
    lhs
    rw [step_rhs_normalization]
  simp only [Arm64Register.read_refines, extended_modifier_refines _ _ _ _ _ (amount_bound amount)]
  rfl

theorem extended_handler_refines (width : Width) (subtract setFlags sourceIsScalar plainSource : Bool)
    (dst src : Reference.AArch64.RegisterRef) (rhs : Register) (kind : Reference.AArch64.RegisterExtend)
    (amount : Fin 5) (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.arithmeticExtended width subtract setFlags dst src rhs kind amount) s
      (extendedHandlerStep width subtract setFlags sourceIsScalar plainSource dst src rhs kind amount s) :=
  (extended_step_refines width subtract setFlags sourceIsScalar plainSource dst src rhs kind amount s).symm

def compareExtendedHandlerStep (width : Width) (subtract plainSource : Bool)
    (src : Reference.AArch64.RegisterRef) (rhs : Register) (kind : Reference.AArch64.RegisterExtend)
    (amount : Fin 5) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let value := GeneratedArm64Mod.value (extendedModifier width kind (BitVec.ofNat 64 amount.val) plainSource)
    (Arm64Register.readReg s rhs) (BitVec.ofNat 64 amount.val) (Arm64Register.handlerWidth width)
  compareArithmeticHandlerStep width subtract false src 0 value s

theorem extended_compare_alias_refines (width : Width) (subtract plainSource : Bool)
    (src : Reference.AArch64.RegisterRef) (rhs : Register) (kind : Reference.AArch64.RegisterExtend)
    (amount : Fin 5) (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.arithmeticExtended width subtract true .zero src rhs kind amount) s
      (compareExtendedHandlerStep width subtract plainSource src rhs kind amount s) := by
  unfold Reference.AArch64.Step compareExtendedHandlerStep
  rw [← normalized_compare_refines]
  simp only [Arm64Register.read_refines, extended_modifier_refines _ _ _ _ _ (amount_bound amount)]
  rfl


namespace ConditionalCompare

/-- The two numeric family labels select their actual operand-table rows. -/
def decodeOpcode (code : Nat) : Option GeneratedArm64FlagOperand.FlagOp :=
  if code = GeneratedArm64DispatchFamily.code .ccmpImm then some .ccmpImm
  else if code = GeneratedArm64DispatchFamily.code .ccmpReg then some .ccmpReg else none

theorem decode_family (op : GeneratedArm64DispatchFamily.DispatchOp) :
    (decodeOpcode (GeneratedArm64DispatchFamily.code op)).isSome =
      GeneratedArm64DispatchFamily.ccmpHandled op := by cases op <;> rfl

theorem decoded_operand (code : Nat) (op : GeneratedArm64FlagOperand.FlagOp)
    (valid : decodeOpcode code = some op) :
    GeneratedArm64FlagOperand.code op = code ∧
      GeneratedArm64FlagOperand.immediate op = (code == GeneratedArm64DispatchFamily.code .ccmpImm) := by
  unfold decodeOpcode at valid
  split at valid
  · have equal := Option.some.inj valid
    subst op
    subst code
    exact ⟨rfl, rfl⟩
  · split at valid
    · have equal := Option.some.inj valid
      subst op
      subst code
      exact ⟨rfl, rfl⟩
    · simp at valid

def packedAux (predicate : Arm64Cond) (fallback lane2 lane3 : Byte) : BitVec 32 :=
  GeneratedArm64Aux.pack (BitVec.ofNat 32 (GeneratedArm64Cond.code predicate))
    (fallback.setWidth 32) (lane2.setWidth 32) (lane3.setWidth 32)

theorem packed_condition (predicate : Arm64Cond) (fallback lane2 lane3 : Byte) :
    Arm64Condition.decode (GeneratedArm64CcmpDecode.ccmpCond (packedAux predicate fallback lane2 lane3)).toNat =
      some predicate := by
  rw [(arm64_ccmp_decode_lanes _).1]
  simp only [packedAux, arm64_aux_b0_roundtrip]
  cases predicate <;> rfl

theorem packed_fallback (predicate : Arm64Cond) (fallback lane2 lane3 : Byte) :
    (GeneratedArm64CcmpDecode.ccmpNzcv (packedAux predicate fallback lane2 lane3)).setWidth 8 = fallback := by
  rw [(arm64_ccmp_decode_lanes _).2]
  simp only [packedAux, arm64_aux_b1_roundtrip]
  bv_decide

/-- Only the fallback byte discards high bits; the condition decoder above
compares all eight extracted condition bits. -/
theorem fallback_low_bits (fallback : Byte) :
    GeneratedArm64CcmpHandler.fallbackFlags fallback =
      GeneratedArm64CcmpHandler.fallbackFlags ((fallback.setWidth 4).setWidth 8) := by
  simp only [GeneratedArm64CcmpHandler.fallbackFlags]
  congr 1 <;> bv_decide

theorem apply_fallback_low_bits (incoming : GeneratedArm64Flags.Flags) (predicate : Arm64Cond)
    (lhs rhs : Word) (width : GeneratedArm64Width.Width) (fallback : Byte) :
    GeneratedArm64CcmpHandler.apply incoming predicate lhs rhs width fallback =
      GeneratedArm64CcmpHandler.apply incoming predicate lhs rhs width ((fallback.setWidth 4).setWidth 8) := by
  unfold GeneratedArm64CcmpHandler.apply
  split
  · rfl
  · rw [fallback_low_bits]

/-- Production CCMP uses the instruction's DST field as its left source,
reads SRC only for the register operand and replaces NZCV without a GPR write. -/
def rawStep (op : GeneratedArm64FlagOperand.FlagOp) (width : Width) (lhs src : Register)
    (immediate : Word) (predicate : Arm64Cond) (fallback : Byte) (s : Reference.AArch64.State) :
    Transition Reference.AArch64.State :=
  let rhs := if GeneratedArm64FlagOperand.immediate op then immediate else Arm64Register.readReg s src
  let result := GeneratedArm64CcmpHandler.apply (incomingFlags s.flags) predicate
    (Arm64Register.readReg s lhs) rhs (Arm64Register.handlerWidth width) fallback
  ⟨{ s with flags := Arm64Logic.flagsWord s.flags result.flags, pc := s.pc + 4 }, [], none⟩

theorem raw_immediate_refines (width : Width) (lhs src : Register) (immediate : BitVec 5)
    (predicate : Arm64Cond) (fallback : Byte) (s : Reference.AArch64.State) :
    rawStep .ccmpImm width lhs src (immediate.setWidth 64) predicate fallback s =
      Reference.AArch64.step (.compare width lhs (.immediate immediate)
        (Arm64Condition.nativeCode predicate) (fallback.setWidth 4)) s := by
  simp only [rawStep, GeneratedArm64FlagOperand.immediate, ↓reduceIte]
  rw [apply_fallback_low_bits]
  change handlerStep width lhs (.immediate immediate) predicate (fallback.setWidth 4) s = _
  rw [step_refines]

theorem raw_register_refines (width : Width) (lhs src : Register) (immediate : Word)
    (predicate : Arm64Cond) (fallback : Byte) (s : Reference.AArch64.State) :
    rawStep .ccmpReg width lhs src immediate predicate fallback s =
      Reference.AArch64.step (.compare width lhs (.register src)
        (Arm64Condition.nativeCode predicate) (fallback.setWidth 4)) s := by
  simp only [rawStep, GeneratedArm64FlagOperand.immediate, Bool.false_eq_true, ↓reduceIte]
  rw [apply_fallback_low_bits]
  change handlerStep width lhs (.register src) predicate (fallback.setWidth 4) s = _
  rw [step_refines]

def dispatch (code : Nat) (aux : BitVec 32) (width : Width) (lhs src : Register)
    (immediate : Word) (s : Reference.AArch64.State) : Option (Transition Reference.AArch64.State) :=
  (decodeOpcode code).bind (fun op =>
    (Arm64Condition.decode (GeneratedArm64CcmpDecode.ccmpCond aux).toNat).map
      (fun predicate => rawStep op width lhs src immediate predicate
        ((GeneratedArm64CcmpDecode.ccmpNzcv aux).setWidth 8) s))

theorem dispatch_immediate_refines (width : Width) (lhs src : Register) (immediate : BitVec 5)
    (predicate : Arm64Cond) (fallback lane2 lane3 : Byte) (s : Reference.AArch64.State) :
    dispatch (GeneratedArm64DispatchFamily.code .ccmpImm) (packedAux predicate fallback lane2 lane3)
      width lhs src (immediate.setWidth 64) s =
      some (Reference.AArch64.step (.compare width lhs (.immediate immediate)
        (Arm64Condition.nativeCode predicate) (fallback.setWidth 4)) s) := by
  have decoded : decodeOpcode (GeneratedArm64DispatchFamily.code .ccmpImm) = some .ccmpImm := rfl
  simp only [dispatch, decoded, packed_condition, packed_fallback]
  change some (rawStep .ccmpImm width lhs src (immediate.setWidth 64) predicate fallback s) = _
  rw [raw_immediate_refines]

theorem dispatch_register_refines (width : Width) (lhs src : Register) (immediate : Word)
    (predicate : Arm64Cond) (fallback lane2 lane3 : Byte) (s : Reference.AArch64.State) :
    dispatch (GeneratedArm64DispatchFamily.code .ccmpReg) (packedAux predicate fallback lane2 lane3)
      width lhs src immediate s =
      some (Reference.AArch64.step (.compare width lhs (.register src)
        (Arm64Condition.nativeCode predicate) (fallback.setWidth 4)) s) := by
  have decoded : decodeOpcode (GeneratedArm64DispatchFamily.code .ccmpReg) = some .ccmpReg := rfl
  simp only [dispatch, decoded, packed_condition, packed_fallback]
  change some (rawStep .ccmpReg width lhs src immediate predicate fallback s) = _
  rw [raw_register_refines]

theorem dispatch_bad_condition (code : Nat) (aux : BitVec 32) (width : Width) (lhs src : Register)
    (immediate : Word) (s : Reference.AArch64.State)
    (bad : 15 ≤ (GeneratedArm64CcmpDecode.ccmpCond aux).toNat) :
    dispatch code aux width lhs src immediate s = none := by
  simp [dispatch, Arm64Condition.decode_bad _ bad]

theorem dispatch_other (code : Nat) (aux : BitVec 32) (width : Width) (lhs src : Register)
    (immediate : Word) (s : Reference.AArch64.State)
    (notImm : code ≠ GeneratedArm64DispatchFamily.code .ccmpImm)
    (notReg : code ≠ GeneratedArm64DispatchFamily.code .ccmpReg) :
    dispatch code aux width lhs src immediate s = none := by simp [dispatch, decodeOpcode, notImm, notReg]

end ConditionalCompare


namespace FlagArithmetic

/-- The generated four writeback, two CMP and two CMN numeric labels. -/
def operationCode (subtract writeback immediate : Bool) : Nat :=
  if writeback then
    if subtract then GeneratedArm64FlagOperand.code (if immediate then .subsImm else .subsReg)
    else GeneratedArm64FlagOperand.code (if immediate then .addsImm else .addsReg)
  else if subtract then GeneratedArm64FlagOperand.code (if immediate then .cmpImm else .cmpReg)
  else GeneratedArm64DispatchSingleton.code (if immediate then .cmnImm else .cmnReg)

def decodeOpcode (code : Nat) : Option (Bool × Bool × Bool) :=
  if code = operationCode true true true then some (true, true, true)
  else if code = operationCode true true false then some (true, true, false)
  else if code = operationCode false true true then some (false, true, true)
  else if code = operationCode false true false then some (false, true, false)
  else if code = operationCode true false true then some (true, false, true)
  else if code = operationCode true false false then some (true, false, false)
  else if code = operationCode false false true then some (false, false, true)
  else if code = operationCode false false false then some (false, false, false) else none

theorem decode_code (subtract writeback immediate : Bool) :
    decodeOpcode (operationCode subtract writeback immediate) = some (subtract, writeback, immediate) := by
  cases subtract <;> cases writeback <;> cases immediate <;> rfl

theorem writeback_codes (subtract immediate : Bool) :
    operationCode subtract true immediate = GeneratedArm64DispatchFamily.code
      (if subtract then if immediate then .subsImm else .subsReg
        else if immediate then .addsImm else .addsReg) := by cases subtract <;> cases immediate <;> rfl

theorem compare_codes (immediate : Bool) :
    operationCode true false immediate = GeneratedArm64DispatchFamily.code
      (if immediate then .cmpImm else .cmpReg) := by cases immediate <;> rfl

/-- The C modifier switch has no default assignment: unknown byte codes leave
its incoming value unchanged, just like NONE. No rejection rule is invented. -/
def modifierOf (code : Nat) : GeneratedArm64ModDecode.Mod :=
  match code with
  | 1 => .lsl | 2 => .lsr | 3 => .asr | 4 => .ror
  | 5 => .uxtw | 6 => .sxtw | 7 => .uxth | 8 => .sxth
  | 9 => .uxtb | 10 => .sxtb | _ => .none

theorem modifier_code (mod : GeneratedArm64ModDecode.Mod) :
    modifierOf (GeneratedArm64ModDecode.code mod) = mod := by cases mod <;> rfl

def packedAux (mod : GeneratedArm64ModDecode.Mod) (amount lane0 lane3 : Byte) : BitVec 32 :=
  GeneratedArm64Aux.pack (lane0.setWidth 32) (BitVec.ofNat 32 (GeneratedArm64ModDecode.code mod))
    (amount.setWidth 32) (lane3.setWidth 32)

theorem packed_modifier (mod : GeneratedArm64ModDecode.Mod) (amount lane0 lane3 : Byte) :
    modifierOf (GeneratedArm64Aux.b1 (packedAux mod amount lane0 lane3)).toNat = mod := by
  simp only [packedAux, arm64_aux_b1_roundtrip]
  cases mod <;> rfl

theorem packed_amount (mod : GeneratedArm64ModDecode.Mod) (amount lane0 lane3 : Byte) :
    (GeneratedArm64Aux.b2 (packedAux mod amount lane0 lane3)).setWidth 64 = amount.setWidth 64 := by
  simp only [packedAux, arm64_aux_b2_roundtrip]
  bv_decide

def registerValue (aux : BitVec 32) (width : Width) (rhs : Register) (s : Reference.AArch64.State) : Word :=
  GeneratedArm64Mod.value (modifierOf (GeneratedArm64Aux.b1 aux).toNat) (Arm64Register.readReg s rhs)
    ((GeneratedArm64Aux.b2 aux).setWidth 64) (Arm64Register.handlerWidth width)

/-- Actual flag-setting writeback or compare-only body, with its generated
immediate/register selector and packed source modifier. Compare rows ignore DST;
flag-setting writeback never takes the non-flag pointer-ADD branch. -/
def rawStep (subtract writeback immediate sourceIsScalar : Bool) (aux : BitVec 32) (width : Width)
    (dst src : Reference.AArch64.RegisterRef) (rhs : Register) (value : Word) (s : Reference.AArch64.State) :
    Transition Reference.AArch64.State :=
  if writeback then arithmeticHandlerStep width subtract true sourceIsScalar immediate dst src value
      (registerValue aux width rhs s) s
  else compareArithmeticHandlerStep width subtract immediate src value (registerValue aux width rhs s) s

theorem raw_step_refines (subtract writeback immediate sourceIsScalar : Bool) (aux : BitVec 32) (width : Width)
    (dst src : Reference.AArch64.RegisterRef) (rhs : Register) (value : Word) (s : Reference.AArch64.State) :
    rawStep subtract writeback immediate sourceIsScalar aux width dst src rhs value s =
      Reference.AArch64.arithmeticImmediateStep width subtract true (if writeback then dst else .zero) src
        (if immediate then value else registerValue aux width rhs s) s := by
  cases writeback
  · exact (compare_arithmetic_refines width subtract immediate src value (registerValue aux width rhs s) s).symm
  · exact arithmetic_step_refines width subtract true sourceIsScalar immediate dst src value
      (registerValue aux width rhs s) s

def dispatch (code : Nat) (aux : BitVec 32) (width : Width) (sourceIsScalar : Bool)
    (dst src : Reference.AArch64.RegisterRef) (rhs : Register) (value : Word) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  (decodeOpcode code).map (fun choice => rawStep choice.1 choice.2.1 choice.2.2 sourceIsScalar
    aux width dst src rhs value s)

theorem dispatch_immediate_refines (subtract writeback sourceIsScalar : Bool) (aux : BitVec 32) (width : Width)
    (dst src : Reference.AArch64.RegisterRef) (rhs : Register) (value : Word) (s : Reference.AArch64.State) :
    dispatch (operationCode subtract writeback true) aux width sourceIsScalar dst src rhs value s =
      some (Reference.AArch64.step
        (.arithmeticImmediate width subtract true (if writeback then dst else .zero) src value) s) := by
  simp only [dispatch, decode_code]
  change some (rawStep subtract writeback true sourceIsScalar aux width dst src rhs value s) = _
  rw [raw_step_refines]
  rfl

theorem dispatch_register_refines (subtract writeback sourceIsScalar : Bool) (width : Width)
    (dst src : Reference.AArch64.RegisterRef) (rhs : Register) (kind : Fin 3) (amount : Fin width.bits)
    (value : Word) (lane0 lane3 : Byte) (s : Reference.AArch64.State) :
    dispatch (operationCode subtract writeback false)
      (packedAux (registerModifier width kind amount) (BitVec.ofNat 8 amount.val) lane0 lane3)
      width sourceIsScalar dst src rhs value s =
      some (Reference.AArch64.step (.arithmeticRegister width subtract true
        (if writeback then dst else .zero) src rhs kind amount) s) := by
  simp only [dispatch, decode_code]
  change some (rawStep subtract writeback false sourceIsScalar _ width dst src rhs value s) = _
  rw [raw_step_refines]
  simp only [Bool.false_eq_true, ↓reduceIte, registerValue, packed_modifier, packed_amount,
    Arm64Shift.Unary.native_amount]
  conv => lhs; rw [step_rhs_normalization]
  simp only [Arm64Register.read_refines, register_modifier_refines]
  rfl

theorem extended_amount (amount : Fin 5) :
    (BitVec.ofNat 8 amount.val).setWidth 64 = BitVec.ofNat 64 amount.val := by
  apply BitVec.eq_of_toNat_eq
  have bound : amount.val < 256 := by have := amount.isLt; omega
  simp only [BitVec.toNat_setWidth, BitVec.toNat_ofNat, Nat.mod_eq_of_lt bound]

theorem dispatch_extended_refines (subtract writeback sourceIsScalar plainSource : Bool) (width : Width)
    (dst src : Reference.AArch64.RegisterRef) (rhs : Register) (kind : Reference.AArch64.RegisterExtend)
    (amount : Fin 5) (value : Word) (lane0 lane3 : Byte) (s : Reference.AArch64.State) :
    dispatch (operationCode subtract writeback false)
      (packedAux (extendedModifier width kind (BitVec.ofNat 64 amount.val) plainSource)
        (BitVec.ofNat 8 amount.val) lane0 lane3) width sourceIsScalar dst src rhs value s =
      some (Reference.AArch64.step (.arithmeticExtended width subtract true
        (if writeback then dst else .zero) src rhs kind amount) s) := by
  simp only [dispatch, decode_code]
  change some (rawStep subtract writeback false sourceIsScalar _ width dst src rhs value s) = _
  rw [raw_step_refines]
  simp only [Bool.false_eq_true, ↓reduceIte, registerValue, packed_modifier, packed_amount, extended_amount]
  conv => lhs; rw [step_rhs_normalization]
  simp only [Arm64Register.read_refines, extended_modifier_refines _ _ _ _ _ (amount_bound amount)]
  rfl

theorem dispatch_other (code : Nat) (aux : BitVec 32) (width : Width) (sourceIsScalar : Bool)
    (dst src : Reference.AArch64.RegisterRef) (rhs : Register) (value : Word) (s : Reference.AArch64.State)
    (other : ∀ subtract writeback immediate, code ≠ operationCode subtract writeback immediate) :
    dispatch code aux width sourceIsScalar dst src rhs value s = none := by simp [dispatch, decodeOpcode, other]

end FlagArithmetic

end KProgFormal.Refinement.Arm64Arithmetic
