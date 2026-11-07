import KProgFormal.Refinement.Arm64Shift
import KProgFormal.Refinement.Arm64Move
import KProgFormal.Generated.GeneratedArm64LogicFlagHandler
import KProgFormal.Generated.GeneratedArm64Orn

import KProgFormal.Generated.GeneratedArm64AluOperandSelect
import KProgFormal.Generated.GeneratedArm64AluOperand
import KProgFormal.Generated.GeneratedArm64AluHandler
import KProgFormal.Generated.GeneratedArm64FlagOperand
import KProgFormal.Generated.GeneratedArm64DispatchFamily
import KProgFormal.Generated.GeneratedArm64DispatchSingleton
import KProgFormal.Generated.GeneratedPtrAdd

namespace KProgFormal.Refinement.Arm64Logic

open Reference
open Reference.AArch64 (Width ShiftKind LogicOp LogicInstruction)
open Arm64Register (handlerWidth readReg writeReg)

def value (width : Width) (op : LogicOp) (lhs rhs : Reference.Word) : Reference.Word :=
  match op with
  | .conjunction invert _ => GeneratedArm64AluResult.result (if invert then .bic else .and) lhs rhs
  | .disjunction false => GeneratedArm64AluResult.result .orr lhs rhs
  | .disjunction true => GeneratedArm64Orn.value .orn_reg lhs rhs (handlerWidth width)
  | .exclusive => GeneratedArm64AluResult.result .eor lhs rhs

def flagsWord (old : Reference.Word) (flags : GeneratedArm64Flags.Flags) : Reference.Word :=
  (old &&& 0xffffffff0fffffff) |||
    (if flags.n then 0x80000000 else 0) ||| (if flags.z then 0x40000000 else 0) |||
    (if flags.c then 0x20000000 else 0) ||| (if flags.v then 0x10000000 else 0)

theorem value_refines (width : Width) (op : LogicOp) (kind : ShiftKind)
    (lhs rhs amount : Reference.Word) :
    Reference.AArch64.narrow (value width op lhs
      (GeneratedArm64Mod.value (Arm64Shift.modifier kind) rhs amount (handlerWidth width))) width =
      Reference.AArch64.logicValue width op lhs (Reference.AArch64.shiftValue width kind rhs amount) := by
  cases op <;> (first
    | (rename_i invert flags; cases invert)
    | (rename_i invert; cases invert)
    | skip)
  all_goals
    cases width <;> cases kind <;>
      simp only [value, Reference.AArch64.logicValue, GeneratedArm64AluResult.result,
        GeneratedArm64Orn.value, GeneratedArm64Mod.value, Arm64Shift.modifier, handlerWidth,
        GeneratedArm64Width.narrow, GeneratedArm64Width.mask,
        Reference.AArch64.narrow, Reference.AArch64.Width.bits, Reference.AArch64.shiftValue,
        Reference.AArch64.extractValue, Reference.AArch64.extractRawWindow, Reference.Word] <;> bv_decide

theorem flags_refines (width : Width) (result old : Reference.Word) :
    flagsWord old (GeneratedArm64Flags.applyLogic result (handlerWidth width)) =
      Reference.AArch64.logicFlags width (Reference.AArch64.narrow result width) old := by
  cases width <;>
    simp only [flagsWord, GeneratedArm64Flags.applyLogic, GeneratedArm64Width.narrow,
      GeneratedArm64Width.sign, GeneratedArm64Width.signMask, GeneratedArm64Width.mask,
      GeneratedArm64Width.bits,
      handlerWidth, Reference.AArch64.logicFlags, Reference.AArch64.narrow,
      Reference.AArch64.Width.bits, Reference.Word] <;> bv_decide

def handlerStep (i : LogicInstruction) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let rhs := GeneratedArm64Mod.value (Arm64Shift.modifier i.kind) (readReg s i.rhs)
    (BitVec.ofNat 64 i.amount.val) (handlerWidth i.width)
  let result := value i.width i.op (readReg s i.lhs) rhs
  let flags := if i.op.setFlags then flagsWord s.flags (GeneratedArm64Flags.applyLogic result (handlerWidth i.width))
    else s.flags
  ⟨{ writeReg s i.dst result i.width with flags := flags, pc := s.pc + 4 }, [], none⟩

theorem step_refines (i : LogicInstruction) (s : Reference.AArch64.State) :
    handlerStep i s = Reference.AArch64.step (.logic i) s := by
  simp only [handlerStep, Reference.AArch64.step, Reference.AArch64.logicStep, Arm64Register.read_refines,
    Arm64Register.write_refines, flags_refines, value_refines]

theorem handler_refines (i : LogicInstruction) (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.logic i) s (handlerStep i s) := (step_refines i s).symm


/-- An immediate is consumed directly, without manufacturing a register
operand or applying a source modifier. The same generated logical primitives
agree with the canonical architectural-width operation. -/
theorem immediate_value_refines (width : Width) (op : LogicOp) (lhs rhs : Word) :
    Reference.AArch64.narrow (value width op lhs rhs) width =
      Reference.AArch64.logicValue width op lhs rhs := by
  cases op <;> (first
    | (rename_i invert flags; cases invert)
    | (rename_i invert; cases invert)
    | skip)
  all_goals
    cases width <;>
      simp only [value, Reference.AArch64.logicValue, GeneratedArm64AluResult.result,
        GeneratedArm64Orn.value, handlerWidth, GeneratedArm64Width.narrow, GeneratedArm64Width.mask,
        Reference.AArch64.narrow, Reference.AArch64.Width.bits, Reference.Word,
        Bool.false_eq_true, ↓reduceIte] <;> bv_decide

theorem logic_value_narrow (width : Width) (op : LogicOp) (lhs rhs : Word) :
    Reference.AArch64.narrow (Reference.AArch64.logicValue width op lhs rhs) width =
      Reference.AArch64.logicValue width op lhs rhs := by
  have equal := Arm64Shift.narrow_idempotent width (value width op lhs rhs)
  simpa only [immediate_value_refines] using equal

/-- The generated immediate value and optional logical flags feed the actual
width write, including the separate SP destination. Native decoded AND/ORR/EOR
use SP for field31; ANDS/TST use the discarded ZR destination instead. -/
def immediateHandlerStep (width : Width) (op : LogicOp) (dst : Reference.AArch64.RegisterRef)
    (src : Reference.AArch64.Register) (immediate : Word) (s : Reference.AArch64.State) :
    Transition Reference.AArch64.State :=
  let result := value width op (readReg s src) immediate
  let flags := if op.setFlags then flagsWord s.flags (GeneratedArm64Flags.applyLogic result (handlerWidth width))
    else s.flags
  ⟨{ Arm64Move.widthWrite s dst result width with flags := flags, pc := s.pc + 4 }, [], none⟩

theorem immediate_step_refines (width : Width) (op : LogicOp) (dst : Reference.AArch64.RegisterRef)
    (src : Reference.AArch64.Register) (immediate : Word) (s : Reference.AArch64.State) :
    immediateHandlerStep width op dst src immediate s =
      Reference.AArch64.step (.logicImmediate width op dst src immediate) s := by
  cases dst <;>
    simp only [immediateHandlerStep, Reference.AArch64.step, Reference.AArch64.logicImmediateStep,
      Arm64Move.width_write_refines, Arm64Register.read_refines, Reference.AArch64.writeData,
      flags_refines, immediate_value_refines, logic_value_narrow]

theorem immediate_handler_refines (width : Width) (op : LogicOp) (dst : Reference.AArch64.RegisterRef)
    (src : Reference.AArch64.Register) (immediate : Word) (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.logicImmediate width op dst src immediate) s
      (immediateHandlerStep width op dst src immediate s) :=
  (immediate_step_refines width op dst src immediate s).symm

namespace ImmediateDispatch

/-- The logical AUX-byte choices of the generic ALU family. Arithmetic
members remain with their own handler. BIC is a normalized complement
operand, not an invented native BIC-immediate instruction. -/
inductive Logical
  | conjunction | bitClear | exclusive | disjunction
  deriving DecidableEq

def alu : Logical → GeneratedArm64AluDecode.Alu
  | .conjunction => .and | .bitClear => .bic | .exclusive => .eor | .disjunction => .orr

def operation : Logical → LogicOp
  | .conjunction => .conjunction false false | .bitClear => .conjunction true false
  | .exclusive => .exclusive | .disjunction => .disjunction false

def decodeAlu (code : Nat) : Option Logical :=
  if code = GeneratedArm64AluDecode.code .and then some .conjunction
  else if code = GeneratedArm64AluDecode.code .bic then some .bitClear
  else if code = GeneratedArm64AluDecode.code .eor then some .exclusive
  else if code = GeneratedArm64AluDecode.code .orr then some .disjunction else none

theorem decode_code (op : Logical) : decodeAlu (GeneratedArm64AluDecode.code (alu op)) = some op := by
  cases op <;> rfl

/-- Numeric projection of the actual ORR stack-pointer branch. The pointer
read must materialize the same native word as the ordinary read (Entry/O4).
Disjoint added bits cannot carry: no alignment or small-offset hypothesis
is needed for this numeric identity. -/
theorem pointer_orr (lhs rhs : Word) :
    GeneratedPtrAdd.bits lhs (rhs &&& ~~~lhs) = lhs ||| rhs := by
  simp only [GeneratedPtrAdd.bits, Reference.Word]
  bv_decide

theorem no_arithmetic_pointer_branch (op : Logical) (width : Width) (dstIsSp sourceScalar sourceStack : Bool) :
    GeneratedArm64AluHandler.usePointer (handlerWidth width) (alu op) dstIsSp sourceScalar = false ∧
    GeneratedArm64AluHandler.useStackSub (handlerWidth width) (alu op) dstIsSp sourceStack = false := by
  cases op <;> cases width <;> exact ⟨rfl, rfl⟩

theorem operand_code : GeneratedArm64AluOperandSelect.code .aluImm =
    GeneratedArm64DispatchFamily.code .aluImm := rfl

/-- The body keeps the production stack-ORR branch, generated RHS selector,
ALU result and width/SP write. The ADD/SUB pointer branches are false for
these logical members; sourceStack is not replaced with a scalar premise. -/
def rawStep (op : Logical) (width : Width) (sourceStack : Bool)
    (dst : Reference.AArch64.RegisterRef) (src : Reference.AArch64.Register)
    (immediate : Word) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let lhs := readReg s src
  let rhs := GeneratedArm64AluOperand.rhs
    (if GeneratedArm64AluOperandSelect.immediate .aluImm then .immediate else .register)
    immediate .none 0 0 (handlerWidth width)
  let result := GeneratedArm64AluResult.result (alu op) lhs rhs
  let state := if width = .w64 ∧ alu op = .orr ∧ sourceStack ∧ rhs < 16 then
      Arm64Move.widthWrite s dst (GeneratedPtrAdd.bits lhs (rhs &&& ~~~lhs)) .w64
    else Arm64Move.widthWrite s dst result width
  ⟨{ state with pc := s.pc + 4 }, [], none⟩

theorem raw_step_refines (op : Logical) (width : Width) (sourceStack : Bool)
    (dst : Reference.AArch64.RegisterRef) (src : Reference.AArch64.Register)
    (immediate : Word) (s : Reference.AArch64.State) :
    rawStep op width sourceStack dst src immediate s =
      Reference.AArch64.step (.logicImmediate width (operation op) dst src immediate) s := by
  have body : rawStep op width sourceStack dst src immediate s =
      immediateHandlerStep width (operation op) dst src immediate s := by
    cases op <;> cases width <;> cases dst <;>
        simp only [rawStep, immediateHandlerStep, operation, value,
          GeneratedArm64AluOperandSelect.immediate, GeneratedArm64AluOperand.rhs,
          GeneratedArm64AluResult.result, LogicOp.setFlags, alu, Arm64Move.widthWrite,
          Arm64Register.writeReg, pointer_orr,
          Bool.false_eq_true, reduceCtorEq, ↓reduceIte,
          and_true, and_false, false_and, true_and]
    all_goals first | rfl | (split <;> rfl)
  rw [body, immediate_step_refines]

def packedAux (op : Logical) (lane1 lane2 lane3 : Byte) : BitVec 32 :=
  GeneratedArm64Aux.pack (BitVec.ofNat 32 (GeneratedArm64AluDecode.code (alu op)))
    (lane1.setWidth 32) (lane2.setWidth 32) (lane3.setWidth 32)

theorem packed_operation (op : Logical) (lane1 lane2 lane3 : Byte) :
    (GeneratedArm64Aux.b0 (packedAux op lane1 lane2 lane3)).toNat = GeneratedArm64AluDecode.code (alu op) := by
  simp only [packedAux, arm64_aux_b0_roundtrip]
  cases op <;> rfl

def dispatch (code : Nat) (aux : BitVec 32) (width : Width) (sourceStack : Bool)
    (dst : Reference.AArch64.RegisterRef) (src : Reference.AArch64.Register)
    (immediate : Word) (s : Reference.AArch64.State) : Option (Transition Reference.AArch64.State) :=
  if code = GeneratedArm64DispatchFamily.code .aluImm then
    (decodeAlu (GeneratedArm64Aux.b0 aux).toNat).map
      (fun op => rawStep op width sourceStack dst src immediate s)
  else none

theorem dispatch_refines (op : Logical) (width : Width) (sourceStack : Bool)
    (dst : Reference.AArch64.RegisterRef) (src : Reference.AArch64.Register)
    (immediate : Word) (lane1 lane2 lane3 : Byte) (s : Reference.AArch64.State) :
    dispatch (GeneratedArm64DispatchFamily.code .aluImm) (packedAux op lane1 lane2 lane3)
      width sourceStack dst src immediate s =
      some (Reference.AArch64.step (.logicImmediate width (operation op) dst src immediate) s) := by
  simp only [dispatch, ↓reduceIte, packed_operation, decode_code]
  change some (rawStep op width sourceStack dst src immediate s) = _
  rw [raw_step_refines]

/-- The ALU_REG row selects its register through the independent operand
contract before entering the same logical value/write body. rawStep's
immediate selector is the identity on that already-selected word; it neither
manufactures a guest register nor adds a second instruction transition. -/
def registerRawStep (op : Logical) (mod : GeneratedArm64ModDecode.Mod) (amount : Word)
    (width : Width) (sourceStack : Bool) (dst src rhs : Reference.AArch64.Register)
    (immediate : Word) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let selected := GeneratedArm64AluOperand.rhs
    (if GeneratedArm64AluOperandSelect.immediate .aluReg then .immediate else .register)
    immediate mod (readReg s rhs) amount (handlerWidth width)
  rawStep op width sourceStack (Arm64Move.scalarDestination dst) src selected s

theorem register_operand_code : GeneratedArm64AluOperandSelect.code .aluReg =
    GeneratedArm64DispatchFamily.code .aluReg := rfl

theorem register_raw_refines (op : Logical) (width : Width) (sourceStack : Bool)
    (kind : ShiftKind) (amount : Fin width.bits) (dst src rhs : Reference.AArch64.Register)
    (immediate : Word) (s : Reference.AArch64.State) :
    registerRawStep op (Arm64Shift.modifier kind) (BitVec.ofNat 64 amount.val)
      width sourceStack dst src rhs immediate s =
      Reference.AArch64.step (.logic ⟨width, operation op, kind, amount, dst, src, rhs⟩) s := by
  unfold registerRawStep
  have body (right : Word) : rawStep op width sourceStack (Arm64Move.scalarDestination dst) src right s =
      immediateHandlerStep width (operation op) (Arm64Move.scalarDestination dst) src right s := by
    rw [raw_step_refines, immediate_step_refines]
  rw [body]
  have same : immediateHandlerStep width (operation op) (Arm64Move.scalarDestination dst) src
      (GeneratedArm64AluOperand.rhs
        (if GeneratedArm64AluOperandSelect.immediate .aluReg then .immediate else .register)
        immediate (Arm64Shift.modifier kind) (readReg s rhs) (BitVec.ofNat 64 amount.val) (handlerWidth width)) s =
      handlerStep ⟨width, operation op, kind, amount, dst, src, rhs⟩ s := by
    cases op <;>
      simp only [immediateHandlerStep, handlerStep, operation, LogicOp.setFlags,
        GeneratedArm64AluOperandSelect.immediate, GeneratedArm64AluOperand.rhs,
        Arm64Move.scalar_destination_write, Bool.false_eq_true, ↓reduceIte]
  rw [same, step_refines]

def registerAux (op : Logical) (mod : GeneratedArm64ModDecode.Mod) (amount lane3 : Byte) : BitVec 32 :=
  Arm64Shift.Unary.packedAux mod amount (BitVec.ofNat 8 (GeneratedArm64AluDecode.code (alu op))) lane3

theorem register_aux_operation (op : Logical) (mod : GeneratedArm64ModDecode.Mod) (amount lane3 : Byte) :
    (GeneratedArm64Aux.b0 (registerAux op mod amount lane3)).toNat = GeneratedArm64AluDecode.code (alu op) := by
  simp only [registerAux, Arm64Shift.Unary.packedAux, arm64_aux_b0_roundtrip]
  cases op <;> rfl

/-- Unknown or extended modifier codes are outside this native logical-shift
certificate, not newly rejected by the production C modifier switch. -/
def dispatchRegister (code : Nat) (aux : BitVec 32) (width : Width) (sourceStack : Bool)
    (dst src rhs : Reference.AArch64.Register) (immediate : Word) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  if code = GeneratedArm64DispatchFamily.code .aluReg then
    (decodeAlu (GeneratedArm64Aux.b0 aux).toNat).bind (fun op =>
      (Arm64Shift.Unary.decodeModifier (GeneratedArm64Aux.b1 aux).toNat).map
        (fun mod => registerRawStep op mod ((GeneratedArm64Aux.b2 aux).setWidth 64)
          width sourceStack dst src rhs immediate s))
  else none

theorem dispatch_register_refines (op : Logical) (width : Width) (sourceStack : Bool)
    (kind : ShiftKind) (amount : Fin width.bits) (dst src rhs : Reference.AArch64.Register)
    (immediate : Word) (lane3 : Byte) (s : Reference.AArch64.State) :
    dispatchRegister (GeneratedArm64DispatchFamily.code .aluReg)
      (registerAux op (Arm64Shift.modifier kind) (BitVec.ofNat 8 amount.val) lane3)
      width sourceStack dst src rhs immediate s =
      some (Reference.AArch64.step (.logic ⟨width, operation op, kind, amount, dst, src, rhs⟩) s) := by
  simp only [dispatchRegister, ↓reduceIte, register_aux_operation, decode_code]
  change (Arm64Shift.Unary.decodeModifier
    (GeneratedArm64Aux.b1 (registerAux op (Arm64Shift.modifier kind) (BitVec.ofNat 8 amount.val) lane3)).toNat).map _ = _
  simp only [registerAux]
  rw [Arm64Shift.Unary.packed_shift]
  change some (registerRawStep op (Arm64Shift.modifier kind)
    ((GeneratedArm64Aux.b2 (registerAux op (Arm64Shift.modifier kind) (BitVec.ofNat 8 amount.val) lane3)).setWidth 64)
    width sourceStack dst src rhs immediate s) = _
  simp only [registerAux]
  rw [Arm64Shift.Unary.packed_amount, Arm64Shift.Unary.native_amount, register_raw_refines]

/-- NONE's temporary may retain high bits. Width result and flags use only
architectural low bits, and only the64bit ORR branch can preserve pointers. -/
theorem register_identity (op : Logical) (width : Width) (sourceStack : Bool)
    (dst src rhs : Reference.AArch64.Register) (immediate amount : Word) (s : Reference.AArch64.State) :
    registerRawStep op .none amount width sourceStack dst src rhs immediate s =
      registerRawStep op .lsl 0 width sourceStack dst src rhs immediate s := by
  unfold registerRawStep
  simp only [GeneratedArm64AluOperandSelect.immediate, GeneratedArm64AluOperand.rhs,
    Bool.false_eq_true, ↓reduceIte, raw_step_refines, Reference.AArch64.step,
    Reference.AArch64.logicImmediateStep, Arm64Move.scalarDestination]
  have equal : Reference.AArch64.logicValue width (operation op) (Reference.AArch64.readReg s src)
      (GeneratedArm64Mod.value .none (readReg s rhs) amount (handlerWidth width)) =
    Reference.AArch64.logicValue width (operation op) (Reference.AArch64.readReg s src)
      (GeneratedArm64Mod.value .lsl (readReg s rhs) 0 (handlerWidth width)) := by
    cases width <;> cases op <;>
      simp only [GeneratedArm64Mod.value, operation, handlerWidth, GeneratedArm64Width.mask,
        Reference.AArch64.logicValue, Reference.AArch64.narrow, Reference.AArch64.Width.bits,
        Reference.Word, Bool.false_eq_true, ↓reduceIte] <;> bv_decide
  rw [equal]

theorem dispatch_register_unmodified_refines (op : Logical) (width : Width) (sourceStack : Bool)
    (dst src rhs : Reference.AArch64.Register) (immediate : Word) (amount lane3 : Byte)
    (s : Reference.AArch64.State) :
    dispatchRegister (GeneratedArm64DispatchFamily.code .aluReg) (registerAux op .none amount lane3)
      width sourceStack dst src rhs immediate s =
      some (Reference.AArch64.step (.logic
        ⟨width, operation op, .lsl, ⟨0, by cases width <;> decide⟩, dst, src, rhs⟩) s) := by
  simp only [dispatchRegister, ↓reduceIte, register_aux_operation, decode_code]
  change (Arm64Shift.Unary.decodeModifier (GeneratedArm64Aux.b1 (registerAux op .none amount lane3)).toNat).map _ = _
  simp only [registerAux]
  rw [Arm64Shift.Unary.packed_none]
  change some (registerRawStep op .none ((GeneratedArm64Aux.b2 (registerAux op .none amount lane3)).setWidth 64)
    width sourceStack dst src rhs immediate s) = _
  rw [register_identity]
  exact congrArg some (register_raw_refines op width sourceStack .lsl
    ⟨0, by cases width <;> decide⟩ dst src rhs immediate s)

end ImmediateDispatch

namespace FlagDispatch

/-- Exact TST/ANDS immediate/register rows plus the two BIC register
singletons, including the independent generated flag-operand selection. -/
def operationCode (invert writeback immediate : Bool) : Nat :=
  if invert then GeneratedArm64DispatchSingleton.code (if writeback then .bicsReg else .tstBicReg)
  else GeneratedArm64FlagOperand.code
    (if writeback then if immediate then .andsImm else .andsReg else if immediate then .tstImm else .tstReg)

def decodeOpcode (code : Nat) : Option (Bool × Bool × Bool) :=
  if code = operationCode false true true then some (false, true, true)
  else if code = operationCode false true false then some (false, true, false)
  else if code = operationCode false false true then some (false, false, true)
  else if code = operationCode false false false then some (false, false, false)
  else if code = operationCode true true false then some (true, true, false)
  else if code = operationCode true false false then some (true, false, false) else none

theorem decode_family (op : GeneratedArm64DispatchFamily.DispatchOp) :
    (decodeOpcode (GeneratedArm64DispatchFamily.code op)).isSome =
      (GeneratedArm64DispatchFamily.tstHandled op || GeneratedArm64DispatchFamily.andsHandled op) := by
  cases op <;> rfl

theorem decode_singleton (op : GeneratedArm64DispatchSingleton.SingletonOp) :
    (decodeOpcode (GeneratedArm64DispatchSingleton.code op)).isSome =
      (op == .tstBicReg || op == .bicsReg) := by cases op <;> rfl


theorem decode_code (invert writeback immediate : Bool) (native : invert = true → immediate = false) :
    decodeOpcode (operationCode invert writeback immediate) = some (invert, writeback, immediate) := by
  cases invert <;> cases writeback <;> cases immediate <;> simp_all [decodeOpcode, operationCode,
    GeneratedArm64DispatchSingleton.code, GeneratedArm64FlagOperand.code]

def operandOp (writeback immediate : Bool) : GeneratedArm64FlagOperand.FlagOp :=
  if writeback then if immediate then .andsImm else .andsReg else if immediate then .tstImm else .tstReg

theorem operand_immediate (writeback immediate : Bool) :
    GeneratedArm64FlagOperand.immediate (operandOp writeback immediate) = immediate := by
  cases writeback <;> cases immediate <;> rfl

/-- Test aliases read their left operand from DST and their right register
from SRC; writeback rows read SRC/SRC2. All reads precede writes, including
aliased registers. The immediate branch ignores every AUX byte. -/
def rawStep (invert writeback immediate : Bool) (width : Width)
    (dst src rhs : Reference.AArch64.Register) (value : Word)
    (mod : GeneratedArm64ModDecode.Mod) (amount : Word) (s : Reference.AArch64.State) :
    Transition Reference.AArch64.State :=
  let lhs := readReg s (if writeback then src else dst)
  let register := GeneratedArm64Mod.value mod (readReg s (if writeback then rhs else src)) amount (handlerWidth width)
  let rhs := if GeneratedArm64FlagOperand.immediate (operandOp writeback immediate) then value else register
  let step := GeneratedArm64LogicFlagHandler.apply (if invert then .bic else .and) lhs rhs (handlerWidth width)
  let state := if writeback then writeReg s dst step.value width else s
  ⟨{ state with flags := flagsWord s.flags step.flags, pc := s.pc + 4 }, [], none⟩

def dispatch (code : Nat) (aux : BitVec 32) (width : Width)
    (dst src rhs : Reference.AArch64.Register) (value : Word) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  (decodeOpcode code).bind (fun choice =>
    if choice.2.2 then some (rawStep choice.1 choice.2.1 true width dst src rhs value .none 0 s)
    else (Arm64Shift.Unary.decodeModifier (GeneratedArm64Aux.b1 aux).toNat).map
      (fun mod => rawStep choice.1 choice.2.1 false width dst src rhs value mod
        ((GeneratedArm64Aux.b2 aux).setWidth 64) s))

/-- None from the modifier decoder describes the certified native-form
boundary only: extensions/unknown bytes are not new production C rejects. -/
theorem dispatch_immediate_refines (writeback : Bool) (aux : BitVec 32) (width : Width)
    (dst src rhs : Reference.AArch64.Register) (immediate : Word) (s : Reference.AArch64.State) :
    dispatch (operationCode false writeback true) aux width dst src rhs immediate s =
      some (Reference.AArch64.step (.logicImmediate width (.conjunction false true)
        (Arm64Move.scalarDestination (if writeback then dst else 31))
        (if writeback then src else dst) immediate) s) := by
  simp only [dispatch, decode_code false writeback true (by simp)]
  change some (rawStep false writeback true width dst src rhs immediate .none 0 s) = _
  have body : rawStep false writeback true width dst src rhs immediate .none 0 s =
      immediateHandlerStep width (.conjunction false true)
        (Arm64Move.scalarDestination (if writeback then dst else 31))
        (if writeback then src else dst) immediate s := by
    cases writeback <;>
      simp only [rawStep, immediateHandlerStep, operand_immediate, GeneratedArm64LogicFlagHandler.apply,
        GeneratedArm64LogicFlagHandler.alu, Arm64Logic.value, LogicOp.setFlags, Bool.false_eq_true, ↓reduceIte,
        Arm64Move.scalar_destination_write]
    all_goals rfl
  rw [body, immediate_step_refines]

/-- The generated register destination selector discards field31 in test
aliases. This states equality of the entire state, not only its GPR image. -/
theorem write_zero (s : Reference.AArch64.State) (value : Word) (width : Width) :
    writeReg s 31 value width = s := by
  rw [Arm64Register.write_refines]
  have equal : (fun i : Reference.AArch64.Gpr =>
      if i.val = 31 then Reference.AArch64.narrow value width else s.gpr i) = s.gpr := by
    funext i
    rw [if_neg (show i.val ≠ 31 by omega)]
  change { s with gpr := fun i : Reference.AArch64.Gpr =>
    if i.val = 31 then Reference.AArch64.narrow value width else s.gpr i } = s
  rw [equal]

/-- The canonical instruction uses ZR for the discarded destination, while
its operands retain the actual test/writeback field routing. -/
def instruction (invert writeback : Bool) (width : Width) (kind : ShiftKind)
    (amount : Fin width.bits) (dst src rhs : Reference.AArch64.Register) : LogicInstruction :=
  ⟨width, .conjunction invert true, kind, amount, (if writeback then dst else 31),
    (if writeback then src else dst), (if writeback then rhs else src)⟩

theorem raw_register_refines (invert writeback : Bool) (width : Width) (kind : ShiftKind)
    (amount : Fin width.bits) (dst src rhs : Reference.AArch64.Register) (value : Word)
    (s : Reference.AArch64.State) :
    rawStep invert writeback false width dst src rhs value (Arm64Shift.modifier kind)
      (BitVec.ofNat 64 amount.val) s =
      Reference.AArch64.step (.logic (instruction invert writeback width kind amount dst src rhs)) s := by
  have body : rawStep invert writeback false width dst src rhs value (Arm64Shift.modifier kind)
      (BitVec.ofNat 64 amount.val) s =
      handlerStep (instruction invert writeback width kind amount dst src rhs) s := by
    cases invert <;> cases writeback <;>
      simp only [rawStep, handlerStep, instruction, operand_immediate, GeneratedArm64LogicFlagHandler.apply,
        GeneratedArm64LogicFlagHandler.alu, Arm64Logic.value, LogicOp.setFlags, Bool.false_eq_true,
        ↓reduceIte, write_zero]
    all_goals rfl
  rw [body, step_refines]

theorem dispatch_register_refines (invert writeback : Bool) (width : Width) (kind : ShiftKind)
    (amount : Fin width.bits) (dst src rhs : Reference.AArch64.Register) (value : Word)
    (lane0 lane3 : Byte) (s : Reference.AArch64.State) :
    dispatch (operationCode invert writeback false)
      (Arm64Shift.Unary.packedAux (Arm64Shift.modifier kind) (BitVec.ofNat 8 amount.val) lane0 lane3)
      width dst src rhs value s =
      some (Reference.AArch64.step (.logic (instruction invert writeback width kind amount dst src rhs)) s) := by
  simp only [dispatch, decode_code invert writeback false (by simp)]
  change (Arm64Shift.Unary.decodeModifier
    (GeneratedArm64Aux.b1 (Arm64Shift.Unary.packedAux (Arm64Shift.modifier kind)
      (BitVec.ofNat 8 amount.val) lane0 lane3)).toNat).map _ = _
  rw [Arm64Shift.Unary.packed_shift]
  change some (rawStep invert writeback false width dst src rhs value (Arm64Shift.modifier kind)
    ((GeneratedArm64Aux.b2 (Arm64Shift.Unary.packedAux (Arm64Shift.modifier kind)
      (BitVec.ofNat 8 amount.val) lane0 lane3)).setWidth 64) s) = _
  rw [Arm64Shift.Unary.packed_amount, Arm64Shift.Unary.native_amount, raw_register_refines]

/-- NONE leaves its temporary untrimmed, while LSL0 narrows it. Logical
results, width writeback and NZCV depend on the same selected low bits. -/
theorem raw_identity_refines (invert writeback : Bool) (width : Width)
    (dst src rhs : Reference.AArch64.Register) (immediate amount : Word) (s : Reference.AArch64.State) :
    rawStep invert writeback false width dst src rhs immediate .none amount s =
      rawStep invert writeback false width dst src rhs immediate .lsl 0 s := by
  have result (lhs rhs : Word) :
      Reference.AArch64.narrow
        (GeneratedArm64AluResult.result (if invert then .bic else .and) lhs
          (GeneratedArm64Mod.value .none rhs amount (handlerWidth width))) width =
      Reference.AArch64.narrow
        (GeneratedArm64AluResult.result (if invert then .bic else .and) lhs
          (GeneratedArm64Mod.value .lsl rhs 0 (handlerWidth width))) width := by
    cases invert <;> cases width <;>
      simp only [GeneratedArm64AluResult.result, GeneratedArm64Mod.value, handlerWidth,
        GeneratedArm64Width.mask, Reference.AArch64.narrow, Reference.AArch64.Width.bits,
        Reference.Word, Bool.false_eq_true, ↓reduceIte] <;> bv_decide
  cases writeback <;> cases invert <;>
    simp only [rawStep, operand_immediate, Bool.false_eq_true, ↓reduceIte,
      GeneratedArm64LogicFlagHandler.apply, GeneratedArm64LogicFlagHandler.alu,
      Arm64Register.write_refines, flags_refines]
  all_goals
    first
    | (rw [result]; done)
    | (have equal := result (readReg s src) (readReg s rhs); simp only [Bool.false_eq_true, ↓reduceIte] at equal; rw [equal])
    | (have equal := result (readReg s dst) (readReg s src); simp only [Bool.false_eq_true, ↓reduceIte] at equal; rw [equal])

theorem dispatch_unmodified_refines (invert writeback : Bool) (width : Width)
    (dst src rhs : Reference.AArch64.Register) (value : Word) (amount lane0 lane3 : Byte)
    (s : Reference.AArch64.State) :
    dispatch (operationCode invert writeback false)
      (Arm64Shift.Unary.packedAux .none amount lane0 lane3) width dst src rhs value s =
      some (Reference.AArch64.step (.logic (instruction invert writeback width .lsl ⟨0, by cases width <;> decide⟩
        dst src rhs)) s) := by
  simp only [dispatch, decode_code invert writeback false (by simp)]
  change (Arm64Shift.Unary.decodeModifier
    (GeneratedArm64Aux.b1 (Arm64Shift.Unary.packedAux .none amount lane0 lane3)).toNat).map _ = _
  rw [Arm64Shift.Unary.packed_none]
  change some (rawStep invert writeback false width dst src rhs value .none
    ((GeneratedArm64Aux.b2 (Arm64Shift.Unary.packedAux .none amount lane0 lane3)).setWidth 64) s) = _
  rw [raw_identity_refines]
  exact congrArg some (raw_register_refines invert writeback width .lsl ⟨0, by cases width <;> decide⟩ dst src rhs value s)


end FlagDispatch

end KProgFormal.Refinement.Arm64Logic
