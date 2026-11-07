import KProgFormal.Arm64Extrev
import KProgFormal.Refinement.Arm64Mul

namespace KProgFormal.Refinement.Arm64Extrev

open Reference
open Reference.AArch64 (Width ExtendBits ExtrevInstruction)
open Arm64Register (handlerWidth readReg writeReg)

def extendOpcode : ExtendBits → GeneratedArm64Extrev.Extrev
  | .byte => .sxtb | .half => .sxth | .word => .sxtw

theorem extract_value_refines (width : Width) (lhs rhs shift : Reference.Word) :
    Reference.AArch64.narrow (GeneratedArm64Extrev.value .extr
      (GeneratedArm64Width.narrow lhs (handlerWidth width))
      (GeneratedArm64Width.narrow rhs (handlerWidth width)) shift (handlerWidth width)) width =
      Reference.AArch64.extractValue width.bits lhs rhs shift := by
  cases width <;>
    simp only [GeneratedArm64Extrev.value, GeneratedArm64Width.narrow,
      GeneratedArm64Width.bits, GeneratedArm64Width.mask, handlerWidth,
      Reference.AArch64.narrow, Reference.AArch64.Width.bits,
      Reference.AArch64.extractValue, Reference.AArch64.extractRawWindow, Reference.Word] <;> bv_decide

theorem reverse_value_refines (width : Width) (halfwords : Bool) (src : Reference.Word) :
    Reference.AArch64.narrow (GeneratedArm64Extrev.value
      (if halfwords then .rev16 else .rev) src 0 0 (handlerWidth width)) width =
      (if halfwords then Reference.AArch64.reverseHalfwordBytes src width.bytes
        else Reference.AArch64.reverseBytes src width.bytes) := by
  cases width <;> cases halfwords
  · change Reference.AArch64.narrow (GeneratedArm64Extrev.rev src .w32) .w32 =
      arm64ExtrevRev32Spec src
    rw [← arm64_extrev_rev_w32_refines]
    simp only [Reference.AArch64.narrow, Reference.AArch64.Width.bits,
      GeneratedArm64Extrev.rev, ↓reduceIte, Reference.Word] <;> bv_decide
  · change Reference.AArch64.narrow (GeneratedArm64Extrev.rev16 src .w32) .w32 =
      arm64ExtrevRev16W32Spec src
    rw [← arm64_extrev_rev16_w32_refines]
    simp only [Reference.AArch64.narrow, Reference.AArch64.Width.bits,
      GeneratedArm64Extrev.rev16, ↓reduceIte, Reference.Word] <;> bv_decide
  · exact arm64_extrev_rev_w64_refines src
  · exact arm64_extrev_rev16_w64_refines src

theorem extend_value_refines (width : Width) (source : ExtendBits) (src : Reference.Word) :
    Reference.AArch64.narrow (GeneratedArm64Extrev.value (extendOpcode source)
      src 0 0 (handlerWidth width)) width =
      Reference.AArch64.narrow (Reference.AArch64.signExtendValue src source.bits) width := by
  cases source <;>
    simp only [extendOpcode, GeneratedArm64Extrev.value, Reference.AArch64.ExtendBits.bits,
      arm64_extrev_sxtb_refines, arm64_extrev_sxth_refines, arm64_extrev_sxtw_refines,
      arm64ExtrevSignExtSpec]

/-- Actual EXTR pre-reads are narrowed before the generated shift pair; the
other five handler bodies read a full source before their generated operation.
Every destination uses the shared generated GPR/width selector. -/
def handlerState (i : ExtrevInstruction) (s : Reference.AArch64.State) : Reference.AArch64.State :=
  match i with
  | .extract width amount dst lhs rhs =>
      let lhs := GeneratedArm64Width.narrow (readReg s lhs) (handlerWidth width)
      let rhs := GeneratedArm64Width.narrow (readReg s rhs) (handlerWidth width)
      let value := GeneratedArm64Extrev.value .extr lhs rhs (BitVec.ofNat 64 amount.val) (handlerWidth width)
      writeReg s dst value width
  | .reverse width halfwords dst src =>
      let value := GeneratedArm64Extrev.value (if halfwords then .rev16 else .rev)
        (readReg s src) 0 0 (handlerWidth width)
      writeReg s dst value width
  | .extend width source dst src =>
      let value := GeneratedArm64Extrev.value (extendOpcode source) (readReg s src) 0 0 (handlerWidth width)
      writeReg s dst value width

def handlerStep (i : ExtrevInstruction) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  ⟨{ handlerState i s with pc := s.pc + 4 }, [], none⟩

theorem step_refines (i : ExtrevInstruction) (s : Reference.AArch64.State) :
    handlerStep i s = Reference.AArch64.step (.extrev i) s := by
  cases i <;>
    simp only [handlerStep, handlerState, Reference.AArch64.step, Reference.AArch64.extrevStep,
      Reference.AArch64.extrevResult, Arm64Register.read_refines, Arm64Register.write_refines,
      extract_value_refines, reverse_value_refines, extend_value_refines]

theorem handler_refines (i : ExtrevInstruction) (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.extrev i) s (handlerStep i s) := (step_refines i s).symm


/-- Numeric case labels of the production extract/reverse/extend family. -/
def decodeOpcode (opcode : Nat) : Option GeneratedArm64Extrev.Extrev :=
  if opcode = GeneratedArm64Extrev.code .extr then some .extr
  else if opcode = GeneratedArm64Extrev.code .rev then some .rev
  else if opcode = GeneratedArm64Extrev.code .rev16 then some .rev16
  else if opcode = GeneratedArm64Extrev.code .sxth then some .sxth
  else if opcode = GeneratedArm64Extrev.code .sxtw then some .sxtw
  else if opcode = GeneratedArm64Extrev.code .sxtb then some .sxtb else none

theorem decode_code (op : GeneratedArm64Extrev.Extrev) :
    decodeOpcode (GeneratedArm64Extrev.code op) = some op := by cases op <;> rfl

/-- The actual numeric EXTR selector narrows both sources before the shift
pair. All other rows read full sources; their value primitive ignores the
second source and immediate. All reads precede the destination width write. -/
def rawStep (op : GeneratedArm64Extrev.Extrev) (width : Width)
    (dst src src2 : Reference.AArch64.Register) (immediate : Word) (s : Reference.AArch64.State) :
    Transition Reference.AArch64.State :=
  let inputWidth := if GeneratedArm64Extrev.code op = GeneratedArm64Extrev.code .extr
    then handlerWidth width else .w64
  let lhs := GeneratedArm64Width.narrow (readReg s src) inputWidth
  let rhs := GeneratedArm64Width.narrow (readReg s src2) inputWidth
  let value := GeneratedArm64Extrev.value op lhs rhs immediate (handlerWidth width)
  ⟨{ writeReg s dst value width with pc := s.pc + 4 }, [], none⟩

theorem raw_extract_refines (width : Width) (amount : Fin width.bits)
    (dst lhs rhs : Reference.AArch64.Register) (s : Reference.AArch64.State) :
    rawStep .extr width dst lhs rhs (BitVec.ofNat 64 amount.val) s =
      Reference.AArch64.step (.extrev (.extract width amount dst lhs rhs)) s := by
  simp only [rawStep, GeneratedArm64Extrev.code, ↓reduceIte]
  change handlerStep (.extract width amount dst lhs rhs) s = _
  rw [step_refines]

theorem raw_reverse_refines (width : Width) (halfwords : Bool)
    (dst src src2 : Reference.AArch64.Register) (immediate : Word) (s : Reference.AArch64.State) :
    rawStep (if halfwords then .rev16 else .rev) width dst src src2 immediate s =
      Reference.AArch64.step (.extrev (.reverse width halfwords dst src)) s := by
  rw [← step_refines]
  cases halfwords <;>
    simp only [rawStep, GeneratedArm64Extrev.code, Nat.reduceEqDiff, ↓reduceIte,
      Arm64Mul.input_full, handlerStep, handlerState, Bool.false_eq_true, GeneratedArm64Extrev.value]

theorem raw_extend_refines (width : Width) (source : ExtendBits)
    (dst src src2 : Reference.AArch64.Register) (immediate : Word) (s : Reference.AArch64.State) :
    rawStep (extendOpcode source) width dst src src2 immediate s =
      Reference.AArch64.step (.extrev (.extend width source dst src)) s := by
  rw [← step_refines]
  cases source <;>
    simp only [rawStep, extendOpcode, GeneratedArm64Extrev.code, Nat.reduceEqDiff, ↓reduceIte,
      Arm64Mul.input_full, handlerStep, handlerState, GeneratedArm64Extrev.value]

def dispatch (opcode : Nat) (width : Width) (dst src src2 : Reference.AArch64.Register)
    (immediate : Word) (s : Reference.AArch64.State) : Option (Transition Reference.AArch64.State) :=
  (decodeOpcode opcode).map (fun op => rawStep op width dst src src2 immediate s)

theorem dispatch_extract_refines (width : Width) (amount : Fin width.bits)
    (dst lhs rhs : Reference.AArch64.Register) (s : Reference.AArch64.State) :
    dispatch (GeneratedArm64Extrev.code .extr) width dst lhs rhs (BitVec.ofNat 64 amount.val) s =
      some (Reference.AArch64.step (.extrev (.extract width amount dst lhs rhs)) s) := by
  simp only [dispatch, decode_code]
  change some (rawStep .extr width dst lhs rhs (BitVec.ofNat 64 amount.val) s) = _
  rw [raw_extract_refines]

theorem dispatch_reverse_refines (width : Width) (halfwords : Bool)
    (dst src src2 : Reference.AArch64.Register) (immediate : Word) (s : Reference.AArch64.State) :
    dispatch (GeneratedArm64Extrev.code (if halfwords then .rev16 else .rev))
      width dst src src2 immediate s =
      some (Reference.AArch64.step (.extrev (.reverse width halfwords dst src)) s) := by
  simp only [dispatch, decode_code]
  change some (rawStep (if halfwords then .rev16 else .rev) width dst src src2 immediate s) = _
  rw [raw_reverse_refines]

theorem dispatch_extend_refines (width : Width) (source : ExtendBits)
    (dst src src2 : Reference.AArch64.Register) (immediate : Word) (s : Reference.AArch64.State) :
    dispatch (GeneratedArm64Extrev.code (extendOpcode source)) width dst src src2 immediate s =
      some (Reference.AArch64.step (.extrev (.extend width source dst src)) s) := by
  simp only [dispatch, decode_code]
  change some (rawStep (extendOpcode source) width dst src src2 immediate s) = _
  rw [raw_extend_refines]

theorem dispatch_other (opcode : Nat) (width : Width) (dst src src2 : Reference.AArch64.Register)
    (immediate : Word) (s : Reference.AArch64.State) (other : ∀ op, opcode ≠ GeneratedArm64Extrev.code op) :
    dispatch opcode width dst src src2 immediate s = none := by simp [dispatch, decodeOpcode, other]

end KProgFormal.Refinement.Arm64Extrev
