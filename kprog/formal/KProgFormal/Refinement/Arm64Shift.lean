import KProgFormal.Refinement.Arm64Register
import KProgFormal.Arm64Mod
import KProgFormal.Arm64Unary
import KProgFormal.Arm64Shift
import KProgFormal.Arm64Aux
import KProgFormal.Generated.GeneratedArm64ImmOperand
import KProgFormal.Generated.GeneratedArm64DispatchFamily

namespace KProgFormal.Refinement.Arm64Shift

open Reference
open Reference.AArch64 (Width ShiftKind ShiftInstruction)
open Arm64Register (handlerWidth readReg writeReg)

def shiftCode : ShiftKind → GeneratedArm64ShiftDecode.Shift
  | .lsl => .lsl | .lsr => .lsr | .asr => .asr | .ror => .ror

def modifier : ShiftKind → GeneratedArm64ModDecode.Mod
  | .lsl => .lsl | .lsr => .lsr | .asr => .asr | .ror => .ror

theorem shift_value_refines (width : Width) (kind : ShiftKind) (value amount : Reference.Word) :
    Reference.AArch64.narrow
      (GeneratedArm64Shift.value (shiftCode kind) value amount (handlerWidth width)) width =
      Reference.AArch64.shiftValue width kind value amount := by
  cases width <;> cases kind <;>
    simp only [GeneratedArm64Shift.value, shiftCode, handlerWidth,
      GeneratedArm64Width.narrow, GeneratedArm64Width.mask,
      Reference.AArch64.narrow, Reference.AArch64.Width.bits,
      Reference.AArch64.shiftValue, Reference.AArch64.extractValue,
      Reference.AArch64.extractRawWindow, Reference.Word] <;> bv_decide

/-- Generated MVN/NEG consume the modifier before the unary operation. ASR may
sign-extend in the temporary, but only architectural low bits reach writeback. -/
theorem unary_value_refines (width : Width) (kind : ShiftKind) (value amount : Reference.Word) :
    GeneratedArm64Unary.value .mvn
        (GeneratedArm64Mod.value (modifier kind) value amount (handlerWidth width)) (handlerWidth width) =
      Reference.AArch64.narrow (~~~(Reference.AArch64.shiftValue width kind value amount)) width ∧
    GeneratedArm64Unary.value .neg
        (GeneratedArm64Mod.value (modifier kind) value amount (handlerWidth width)) (handlerWidth width) =
      Reference.AArch64.narrow (-(Reference.AArch64.shiftValue width kind value amount)) width := by
  cases width <;> cases kind <;>
    simp only [GeneratedArm64Mod.value, GeneratedArm64Unary.value, modifier, handlerWidth,
      GeneratedArm64Width.narrow, GeneratedArm64Width.mask,
      Reference.AArch64.narrow, Reference.AArch64.Width.bits,
      Reference.AArch64.shiftValue, Reference.AArch64.extractValue,
      Reference.AArch64.extractRawWindow, Reference.Word] <;>
    constructor <;> bv_decide

theorem narrow_idempotent (width : Width) (value : Reference.Word) :
    Reference.AArch64.narrow (Reference.AArch64.narrow value width) width =
      Reference.AArch64.narrow value width := by
  cases width <;>
    simp only [Reference.AArch64.narrow, Reference.AArch64.Width.bits, Reference.Word] <;> bv_decide

def handlerState (i : ShiftInstruction) (s : Reference.AArch64.State) : Reference.AArch64.State :=
  match i with
  | .register width kind dst src count =>
      writeReg s dst (GeneratedArm64Shift.value (shiftCode kind)
        (readReg s src) (readReg s count) (handlerWidth width)) width
  | .immediate width kind amount dst src =>
      writeReg s dst (GeneratedArm64Shift.value (shiftCode kind)
        (readReg s src) (BitVec.ofNat 64 amount.val) (handlerWidth width)) width
  | .invert width kind amount dst src =>
      let source := GeneratedArm64Mod.value (modifier kind) (readReg s src)
        (BitVec.ofNat 64 amount.val) (handlerWidth width)
      writeReg s dst (GeneratedArm64Unary.value .mvn source (handlerWidth width)) width
  | .negate width kind amount dst src =>
      let source := GeneratedArm64Mod.value (modifier (Reference.AArch64.arithmeticShift kind))
        (readReg s src) (BitVec.ofNat 64 amount.val) (handlerWidth width)
      writeReg s dst (GeneratedArm64Unary.value .neg source (handlerWidth width)) width

def handlerStep (i : ShiftInstruction) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  ⟨{ handlerState i s with pc := s.pc + 4 }, [], none⟩

theorem step_refines (i : ShiftInstruction) (s : Reference.AArch64.State) :
    handlerStep i s = Reference.AArch64.step (.shift i) s := by
  cases i <;>
    simp only [handlerStep, handlerState, Reference.AArch64.step, Reference.AArch64.shiftStep,
      Reference.AArch64.shiftResult, Arm64Register.read_refines, Arm64Register.write_refines,
      shift_value_refines, (unary_value_refines _ _ _ _).1, (unary_value_refines _ _ _ _).2,
      narrow_idempotent]

theorem handler_refines (i : ShiftInstruction) (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.shift i) s (handlerStep i s) := (step_refines i s).symm

/-- Actual shift-family case labels bind the shared operand-source table.
Other opcodes stay outside this handler, even when they select an immediate in
another family such as MOV_IMM. -/
def decodeOpcode (opcode : Nat) : Option GeneratedArm64ImmOperand.ImmOp :=
  if opcode = GeneratedArm64DispatchFamily.code .shiftImm then some .shiftImm
  else if opcode = GeneratedArm64DispatchFamily.code .shiftReg then some .shiftReg
  else none

theorem decode_immediate : decodeOpcode (GeneratedArm64DispatchFamily.code .shiftImm) = some .shiftImm := rfl
theorem decode_register : decodeOpcode (GeneratedArm64DispatchFamily.code .shiftReg) = some .shiftReg := rfl

theorem decode_family (op : GeneratedArm64DispatchFamily.DispatchOp) :
    (decodeOpcode (GeneratedArm64DispatchFamily.code op)).isSome =
      GeneratedArm64DispatchFamily.shiftOpHandled op := by
  cases op <;> rfl

/-- The selected operand-table row carries the very same numeric opcode and
immediate/register decision as the family gate; the two generated tables
cannot silently disagree. -/
theorem decoded_operand (opcode : Nat) (op : GeneratedArm64ImmOperand.ImmOp)
    (valid : decodeOpcode opcode = some op) :
    GeneratedArm64ImmOperand.code op = opcode ∧
      GeneratedArm64ImmOperand.immediate op = (opcode == GeneratedArm64DispatchFamily.code .shiftImm) := by
  unfold decodeOpcode at valid
  split at valid
  · have equal := Option.some.inj valid
    subst op
    subst opcode
    exact ⟨rfl, rfl⟩
  · split at valid
    · have equal := Option.some.inj valid
      subst op
      subst opcode
      exact ⟨rfl, rfl⟩
    · simp at valid

def decodeKind (code : Nat) : Option ShiftKind :=
  if code = GeneratedArm64ShiftDecode.code .lsl then some .lsl
  else if code = GeneratedArm64ShiftDecode.code .lsr then some .lsr
  else if code = GeneratedArm64ShiftDecode.code .asr then some .asr
  else if code = GeneratedArm64ShiftDecode.code .ror then some .ror
  else none

def packedAux (kind : ShiftKind) (lane1 lane2 lane3 : Byte) : BitVec 32 :=
  GeneratedArm64Aux.pack (BitVec.ofNat 32 (GeneratedArm64ShiftDecode.code (shiftCode kind)))
    (lane1.setWidth 32) (lane2.setWidth 32) (lane3.setWidth 32)

theorem packed_kind (kind : ShiftKind) (lane1 lane2 lane3 : Byte) :
    decodeKind (GeneratedArm64Aux.b0 (packedAux kind lane1 lane2 lane3)).toNat = some kind := by
  simp only [packedAux, arm64_aux_b0_roundtrip]
  cases kind <;> rfl

/-- The C shift switch receives the complete AUX word; native SHIFT encodings
place the kind in byte0 and fill the remaining bytes with0. -/
def nativeAux (kind : ShiftKind) : BitVec 32 := packedAux kind 0 0 0

theorem native_kind (kind : ShiftKind) :
    decodeKind (nativeAux kind).toNat = some kind := by cases kind <;> rfl

/-- Actual body order: the generated immediate/register selector chooses the
count, the generated kind primitive consumes the complete AUX word, then a
width write commits the result. All sources are read from the incoming state. -/
def rawStep (op : GeneratedArm64ImmOperand.ImmOp) (kind : ShiftKind) (width : Width)
    (dst src count : Reference.AArch64.Register) (immediate : Word) (s : Reference.AArch64.State) :
    Transition Reference.AArch64.State :=
  let amount := if GeneratedArm64ImmOperand.immediate op then immediate else readReg s count
  let value := GeneratedArm64Shift.value (shiftCode kind) (readReg s src) amount (handlerWidth width)
  ⟨{ writeReg s dst value width with pc := s.pc + 4 }, [], none⟩

def dispatch (opcode : Nat) (aux : BitVec 32) (width : Width)
    (dst src count : Reference.AArch64.Register) (immediate : Word) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  (decodeOpcode opcode).bind (fun op =>
    (decodeKind aux.toNat).map (fun kind => rawStep op kind width dst src count immediate s))

theorem dispatch_immediate_refines (width : Width) (kind : ShiftKind) (amount : Fin width.bits)
    (dst src count : Reference.AArch64.Register) (s : Reference.AArch64.State) :
    dispatch (GeneratedArm64DispatchFamily.code .shiftImm) (nativeAux kind)
      width dst src count (BitVec.ofNat 64 amount.val) s =
      some (Reference.AArch64.step (.shift (.immediate width kind amount dst src)) s) := by
  simp only [dispatch, decode_immediate, native_kind]
  change some (handlerStep (.immediate width kind amount dst src) s) = _
  rw [step_refines]

theorem dispatch_register_refines (width : Width) (kind : ShiftKind)
    (dst src count : Reference.AArch64.Register) (immediate : Word)
    (s : Reference.AArch64.State) :
    dispatch (GeneratedArm64DispatchFamily.code .shiftReg) (nativeAux kind)
      width dst src count immediate s =
      some (Reference.AArch64.step (.shift (.register width kind dst src count)) s) := by
  simp only [dispatch, decode_register, native_kind]
  change some (handlerStep (.register width kind dst src count) s) = _
  rw [step_refines]

theorem dispatch_bad_kind (opcode : Nat) (aux : BitVec 32) (width : Width)
    (dst src count : Reference.AArch64.Register) (immediate : Word) (s : Reference.AArch64.State)
    (outside : 3 < aux.toNat) :
    dispatch opcode aux width dst src count immediate s = none := by
  have invalid : decodeKind aux.toNat = none := by
    simp [decodeKind, GeneratedArm64ShiftDecode.code, show aux.toNat ≠ 0 by omega,
      show aux.toNat ≠ 1 by omega,
      show aux.toNat ≠ 2 by omega,
      show aux.toNat ≠ 3 by omega]
  simp only [dispatch, invalid]
  cases decodeOpcode opcode <;> rfl

theorem dispatch_other (opcode : Nat) (aux : BitVec 32) (width : Width)
    (dst src count : Reference.AArch64.Register) (immediate : Word) (s : Reference.AArch64.State)
    (notImmediate : opcode ≠ GeneratedArm64DispatchFamily.code .shiftImm)
    (notRegister : opcode ≠ GeneratedArm64DispatchFamily.code .shiftReg) :
    dispatch opcode aux width dst src count immediate s = none := by
  simp [dispatch, decodeOpcode, notImmediate, notRegister]


namespace Unary

/-- Numeric labels of the actual two-member unary family. -/
def decodeOpcode (opcode : Nat) : Option GeneratedArm64Unary.Unary :=
  if opcode = GeneratedArm64Unary.code .mvn then some .mvn
  else if opcode = GeneratedArm64Unary.code .neg then some .neg else none

/-- Certified native MVN/NEG operands use identity or a shift modifier.
The generated primitive also implements extensions for other families; None
here means outside this native-form lift, not a new C rejection rule. -/
def decodeModifier (code : Nat) : Option GeneratedArm64ModDecode.Mod :=
  if code = GeneratedArm64ModDecode.code .none then some .none
  else if code = GeneratedArm64ModDecode.code .lsl then some .lsl
  else if code = GeneratedArm64ModDecode.code .lsr then some .lsr
  else if code = GeneratedArm64ModDecode.code .asr then some .asr
  else if code = GeneratedArm64ModDecode.code .ror then some .ror else none

def packedAux (mod : GeneratedArm64ModDecode.Mod) (amount lane0 lane3 : Byte) : BitVec 32 :=
  GeneratedArm64Aux.pack (lane0.setWidth 32)
    (BitVec.ofNat 32 (GeneratedArm64ModDecode.code mod))
    (amount.setWidth 32) (lane3.setWidth 32)

theorem packed_shift (kind : ShiftKind) (amount lane0 lane3 : Byte) :
    decodeModifier (GeneratedArm64Aux.b1 (packedAux (modifier kind) amount lane0 lane3)).toNat =
      some (modifier kind) := by
  simp only [packedAux, arm64_aux_b1_roundtrip]
  cases kind <;> rfl

theorem packed_none (amount lane0 lane3 : Byte) :
    decodeModifier (GeneratedArm64Aux.b1 (packedAux .none amount lane0 lane3)).toNat = some .none := by
  simp only [packedAux, arm64_aux_b1_roundtrip]
  rfl

theorem packed_amount (mod : GeneratedArm64ModDecode.Mod) (amount lane0 lane3 : Byte) :
    (GeneratedArm64Aux.b2 (packedAux mod amount lane0 lane3)).setWidth 64 = amount.setWidth 64 := by
  simp only [packedAux, arm64_aux_b2_roundtrip]
  bv_decide

theorem native_amount (width : Width) (amount : Fin width.bits) :
    (BitVec.ofNat 8 amount.val).setWidth 64 = BitVec.ofNat 64 amount.val := by
  have bound : amount.val < 256 := by
    have := amount.isLt
    cases width <;> simp only [Reference.AArch64.Width.bits] at * <;> omega
  apply BitVec.eq_of_toNat_eq
  simp only [BitVec.toNat_setWidth, BitVec.toNat_ofNat, Nat.mod_eq_of_lt bound]

/-- C body order: incoming source, AUX byte1 modifier, AUX byte2 amount,
then generated unary operation and width write. No flag or memory update. -/
def rawStep (op : GeneratedArm64Unary.Unary) (mod : GeneratedArm64ModDecode.Mod)
    (amount : Word) (width : Width) (dst src : Reference.AArch64.Register)
    (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let value := GeneratedArm64Mod.value mod (readReg s src) amount (handlerWidth width)
  let result := GeneratedArm64Unary.value op value (handlerWidth width)
  ⟨{ writeReg s dst result width with pc := s.pc + 4 }, [], none⟩

def dispatch (opcode : Nat) (aux : BitVec 32) (width : Width)
    (dst src : Reference.AArch64.Register) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  (decodeOpcode opcode).bind (fun op =>
    (decodeModifier (GeneratedArm64Aux.b1 aux).toNat).map (fun mod =>
      rawStep op mod ((GeneratedArm64Aux.b2 aux).setWidth 64) width dst src s))

theorem dispatch_invert_refines (width : Width) (kind : ShiftKind) (amount : Fin width.bits)
    (dst src : Reference.AArch64.Register) (lane0 lane3 : Byte) (s : Reference.AArch64.State) :
    dispatch (GeneratedArm64Unary.code .mvn)
      (packedAux (modifier kind) (BitVec.ofNat 8 amount.val) lane0 lane3) width dst src s =
      some (Reference.AArch64.step (.shift (.invert width kind amount dst src)) s) := by
  simp only [dispatch, decodeOpcode, ↓reduceIte, Option.bind_some, packed_shift, Option.map_some,
    packed_amount, native_amount]
  change some (handlerStep (.invert width kind amount dst src) s) = _
  rw [step_refines]

/-- NEG admits only the architectural LSL/LSR/ASR selectors; the typed
reference does not invent a NEG-with-ROR native instruction. -/
theorem dispatch_negate_refines (width : Width) (kind : Fin 3) (amount : Fin width.bits)
    (dst src : Reference.AArch64.Register) (lane0 lane3 : Byte) (s : Reference.AArch64.State) :
    dispatch (GeneratedArm64Unary.code .neg)
      (packedAux (modifier (Reference.AArch64.arithmeticShift kind))
        (BitVec.ofNat 8 amount.val) lane0 lane3) width dst src s =
      some (Reference.AArch64.step (.shift (.negate width kind amount dst src)) s) := by
  simp only [dispatch, decodeOpcode, GeneratedArm64Unary.code, Nat.reduceEqDiff, ↓reduceIte,
    Option.bind_some, packed_shift, Option.map_some, packed_amount, native_amount]
  change some (handlerStep (.negate width kind amount dst src) s) = _
  rw [step_refines]

theorem identity_value (op : GeneratedArm64Unary.Unary) (width : Width) (value amount : Word) :
    GeneratedArm64Unary.value op (GeneratedArm64Mod.value .none value amount (handlerWidth width))
      (handlerWidth width) =
    GeneratedArm64Unary.value op (GeneratedArm64Mod.value .lsl value 0 (handlerWidth width))
      (handlerWidth width) := by
  cases op <;> cases width <;>
    simp only [GeneratedArm64Unary.value, GeneratedArm64Mod.value, handlerWidth,
      GeneratedArm64Width.narrow, GeneratedArm64Width.mask] <;> bv_decide

/-- Omitted modifiers ignore byte2, including arbitrary unused shift bits. -/
theorem dispatch_unmodified (op : GeneratedArm64Unary.Unary) (width : Width)
    (dst src : Reference.AArch64.Register) (amount lane0 lane3 : Byte) (s : Reference.AArch64.State) :
    dispatch (GeneratedArm64Unary.code op) (packedAux .none amount lane0 lane3) width dst src s =
      dispatch (GeneratedArm64Unary.code op) (packedAux .lsl 0 lane0 lane3) width dst src s := by
  have zero : decodeModifier (GeneratedArm64Aux.b1 (packedAux .lsl 0 lane0 lane3)).toNat = some .lsl :=
    packed_shift .lsl 0 lane0 lane3
  cases op <;>
    simp only [dispatch, decodeOpcode, GeneratedArm64Unary.code, Nat.reduceEqDiff, ↓reduceIte,
      packed_none, zero, packed_amount]
  all_goals
    change some (rawStep _ .none (amount.setWidth 64) width dst src s) =
      some (rawStep _ .lsl 0 width dst src s)
    simp only [rawStep, identity_value]

theorem dispatch_unmodified_invert_refines (width : Width) (dst src : Reference.AArch64.Register)
    (amount lane0 lane3 : Byte) (s : Reference.AArch64.State) :
    dispatch (GeneratedArm64Unary.code .mvn) (packedAux .none amount lane0 lane3) width dst src s =
      some (Reference.AArch64.step
        (.shift (.invert width .lsl ⟨0, by cases width <;> decide⟩ dst src)) s) := by
  rw [dispatch_unmodified]
  exact dispatch_invert_refines width .lsl ⟨0, by cases width <;> decide⟩ dst src lane0 lane3 s

theorem dispatch_unmodified_negate_refines (width : Width) (dst src : Reference.AArch64.Register)
    (amount lane0 lane3 : Byte) (s : Reference.AArch64.State) :
    dispatch (GeneratedArm64Unary.code .neg) (packedAux .none amount lane0 lane3) width dst src s =
      some (Reference.AArch64.step
        (.shift (.negate width 0 ⟨0, by cases width <;> decide⟩ dst src)) s) := by
  rw [dispatch_unmodified]
  exact dispatch_negate_refines width 0 ⟨0, by cases width <;> decide⟩ dst src lane0 lane3 s

theorem dispatch_other (opcode : Nat) (aux : BitVec 32) (width : Width)
    (dst src : Reference.AArch64.Register) (s : Reference.AArch64.State)
    (notMvn : opcode ≠ GeneratedArm64Unary.code .mvn) (notNeg : opcode ≠ GeneratedArm64Unary.code .neg) :
    dispatch opcode aux width dst src s = none := by simp [dispatch, decodeOpcode, notMvn, notNeg]

end Unary

end KProgFormal.Refinement.Arm64Shift
