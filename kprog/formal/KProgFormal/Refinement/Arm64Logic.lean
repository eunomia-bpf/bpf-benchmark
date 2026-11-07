import KProgFormal.Refinement.Arm64Shift
import KProgFormal.Refinement.Arm64Move
import KProgFormal.Generated.GeneratedArm64LogicFlagHandler
import KProgFormal.Generated.GeneratedArm64Orn

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

end KProgFormal.Refinement.Arm64Logic
