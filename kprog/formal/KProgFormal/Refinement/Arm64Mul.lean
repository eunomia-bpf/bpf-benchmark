import KProgFormal.Arm64Mul
import KProgFormal.Refinement.Arm64Register
import KProgFormal.Refinement.Arm64Shift

namespace KProgFormal.Refinement.Arm64Mul

open Reference
open Reference.AArch64 (Width MulInstruction)
open Arm64Register (handlerWidth readReg writeReg)

theorem input_width_refines (value : Reference.Word) (width : Width) :
    GeneratedArm64Width.narrow value (handlerWidth width) =
      Reference.AArch64.narrow value width := by
  cases width <;>
    simp only [handlerWidth, GeneratedArm64Width.narrow, GeneratedArm64Width.mask,
      Reference.AArch64.narrow, Reference.AArch64.Width.bits, Reference.Word] <;> bv_decide

theorem narrow_full (value : Reference.Word) :
    Reference.AArch64.narrow value .w64 = value := by rfl

/-- Arm X[n,datasize] narrows all three MADD/MSUB inputs. The generated
handler may defer that narrowing to its write without changing the result. -/
theorem multiply_width_refines (width : Width) (subtract : Bool)
    (lhs rhs addend : Reference.Word) :
    let op := if subtract then Reference.AArch64.MulOp.msub else .madd
    Reference.AArch64.narrow (Reference.AArch64.mulValue op lhs rhs addend) width =
      Reference.AArch64.narrow (Reference.AArch64.mulValue op
        (Reference.AArch64.narrow lhs width) (Reference.AArch64.narrow rhs width)
        (Reference.AArch64.narrow addend width)) width := by
  cases width <;> cases subtract <;>
    simp only [Reference.AArch64.narrow, Reference.AArch64.Width.bits,
      Reference.AArch64.mulValue, Bool.false_eq_true, ↓reduceIte, Reference.Word] <;> bv_decide

/-- The generated multiply-family expressions feed the real generated width
and GPR write selectors. UDIV narrows both inputs before division, unlike the
multiply arms whose final narrowing suffices. NZCV/vector/SP/memory are retained. -/
def handlerState (i : MulInstruction) (s : Reference.AArch64.State) : Reference.AArch64.State :=
  match i with
  | .multiply width subtract dst lhs rhs addend =>
      let op := if subtract then GeneratedArm64Mul.Mul.msub else .madd
      let value := GeneratedArm64Mul.value op (readReg s lhs) (readReg s rhs) (readReg s addend)
      writeReg s dst value width
  | .longMultiply signed dst lhs rhs addend =>
      let op := if signed then GeneratedArm64Mul.Mul.smaddl else .umaddl
      let value := GeneratedArm64Mul.value op (readReg s lhs) (readReg s rhs) (readReg s addend)
      writeReg s dst value .w64
  | .unsignedHigh dst lhs rhs =>
      writeReg s dst (GeneratedArm64Mul.value .umulh (readReg s lhs) (readReg s rhs) 0) .w64
  | .unsignedDivide width dst lhs rhs =>
      let lhs := GeneratedArm64Width.narrow (readReg s lhs) (handlerWidth width)
      let rhs := GeneratedArm64Width.narrow (readReg s rhs) (handlerWidth width)
      writeReg s dst (GeneratedArm64Mul.value .udiv lhs rhs 0) width

def handlerStep (i : MulInstruction) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  ⟨{ handlerState i s with pc := s.pc + 4 }, [], none⟩

/-- Exact full-state equality for all multiply/divide register encodings,
including aliased operands, ZR sources/discarded destinations and 32-bit writes. -/
theorem step_refines (i : MulInstruction) (s : Reference.AArch64.State) :
    handlerStep i s = Reference.AArch64.step (.mul i) s := by
  cases i with
  | multiply width subtract dst lhs rhs addend =>
      have h := multiply_width_refines width subtract
        (Reference.AArch64.readReg s lhs) (Reference.AArch64.readReg s rhs)
        (Reference.AArch64.readReg s addend)
      cases subtract <;>
        simp only [handlerStep, handlerState, Reference.AArch64.step, Reference.AArch64.mulStep, Reference.AArch64.mulResult,
          Arm64Register.read_refines, Arm64Register.write_refines, arm64_mul_refines,
          arm64MulValueSpec, arm64MulToReference, Bool.false_eq_true, ↓reduceIte] at h ⊢
      all_goals rw [h]
  | longMultiply signed dst lhs rhs addend =>
      cases signed <;>
        simp only [handlerStep, handlerState, Reference.AArch64.step, Reference.AArch64.mulStep, Reference.AArch64.mulResult,
          Arm64Register.read_refines, Arm64Register.write_refines, arm64_mul_refines,
          arm64MulValueSpec, arm64MulToReference, Bool.false_eq_true, ↓reduceIte, narrow_full]
  | unsignedHigh dst lhs rhs =>
      simp only [handlerStep, handlerState, Reference.AArch64.step, Reference.AArch64.mulStep, Reference.AArch64.mulResult,
        Arm64Register.read_refines, Arm64Register.write_refines, arm64_mul_refines,
        arm64MulValueSpec, arm64MulToReference, narrow_full]
  | unsignedDivide width dst lhs rhs =>
      simp only [handlerStep, handlerState, Reference.AArch64.step, Reference.AArch64.mulStep, Reference.AArch64.mulResult,
        Arm64Register.read_refines, Arm64Register.write_refines, input_width_refines,
        arm64_mul_refines, arm64MulValueSpec, arm64MulToReference]

theorem handler_refines (i : MulInstruction) (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.mul i) s (handlerStep i s) := (step_refines i s).symm

/-- MUL/UMULL select their own production opcode, while their native encodings
are MADD/UMADDL with Ra=ZR. The extra argument read by the C macro is unused. -/
def aliasStep (op : GeneratedArm64Mul.Mul) (width : Width)
    (dst lhs rhs : Reference.AArch64.Register) (s : Reference.AArch64.State) :
    Transition Reference.AArch64.State :=
  let value := GeneratedArm64Mul.value op (readReg s lhs) (readReg s rhs) 0
  ⟨{ writeReg s dst value width with pc := s.pc + 4 }, [], none⟩

theorem mul_refines (width : Width) (dst lhs rhs : Reference.AArch64.Register)
    (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.mul (.multiply width false dst lhs rhs 31)) s
      (aliasStep .mul width dst lhs rhs s) := by
  unfold Reference.AArch64.Step
  rw [← step_refines]
  simp only [handlerStep, handlerState, aliasStep, Bool.false_eq_true, ↓reduceIte,
    GeneratedArm64Mul.value]
  have hz : readReg s 31 = 0 := by rw [Arm64Register.read_refines]; rfl
  have hadd (v : Reference.Word) : v + 0 = v := by
    simp only [Reference.Word]; bv_decide
  simp only [hz, hadd]

theorem umull_refines (dst lhs rhs : Reference.AArch64.Register)
    (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.mul (.longMultiply false dst lhs rhs 31)) s
      (aliasStep .umull .w64 dst lhs rhs s) := by
  unfold Reference.AArch64.Step
  rw [← step_refines]
  simp only [handlerStep, handlerState, aliasStep, Bool.false_eq_true, ↓reduceIte,
    GeneratedArm64Mul.value]
  have hz : readReg s 31 = 0 := by rw [Arm64Register.read_refines]; rfl
  have hadd (v : Reference.Word) : v + 0 = v := by
    simp only [Reference.Word]; bv_decide
  simp only [hz, hadd]


/-- The actual multiply-family gate, with no alias to a neighbouring opcode. -/
def decodeOpcode (opcode : Nat) : Option GeneratedArm64Mul.Mul :=
  if opcode = GeneratedArm64Mul.code .madd then some .madd
  else if opcode = GeneratedArm64Mul.code .msub then some .msub
  else if opcode = GeneratedArm64Mul.code .mul then some .mul
  else if opcode = GeneratedArm64Mul.code .umull then some .umull
  else if opcode = GeneratedArm64Mul.code .udiv then some .udiv
  else if opcode = GeneratedArm64Mul.code .umulh then some .umulh
  else if opcode = GeneratedArm64Mul.code .umaddl then some .umaddl
  else if opcode = GeneratedArm64Mul.code .smaddl then some .smaddl else none

theorem decode_code (op : GeneratedArm64Mul.Mul) :
    decodeOpcode (GeneratedArm64Mul.code op) = some op := by cases op <;> rfl

/-- Native long/high multiplies have X destinations. This is a decoded-source
condition, not a new width guard in the C handler. -/
def nativeWidth (op : GeneratedArm64Mul.Mul) (width : Width) : Prop :=
  match op with
  | .umull | .umulh | .umaddl | .smaddl => width = .w64
  | _ => True

def instruction (op : GeneratedArm64Mul.Mul) (width : Width)
    (dst lhs rhs addend : Reference.AArch64.Register) : MulInstruction :=
  match op with
  | .madd => .multiply width false dst lhs rhs addend
  | .msub => .multiply width true dst lhs rhs addend
  | .mul => .multiply width false dst lhs rhs 31
  | .umull => .longMultiply false dst lhs rhs 31
  | .udiv => .unsignedDivide width dst lhs rhs
  | .umulh => .unsignedHigh dst lhs rhs
  | .umaddl => .longMultiply false dst lhs rhs addend
  | .smaddl => .longMultiply true dst lhs rhs addend

/-- C applies WIDTH to both inputs only for numeric UDIV, and applies full
width otherwise. The accumulator is read from the incoming state even when
its value is unused by MUL/UMULL/UDIV/UMULH. -/
def rawStep (op : GeneratedArm64Mul.Mul) (width : Width)
    (dst lhs rhs addend : Reference.AArch64.Register) (s : Reference.AArch64.State) :
    Transition Reference.AArch64.State :=
  let inputWidth := if GeneratedArm64Mul.code op = GeneratedArm64Mul.code .udiv
    then handlerWidth width else .w64
  let lhsValue := GeneratedArm64Width.narrow (readReg s lhs) inputWidth
  let rhsValue := GeneratedArm64Width.narrow (readReg s rhs) inputWidth
  let value := GeneratedArm64Mul.value op lhsValue rhsValue (readReg s addend)
  ⟨{ writeReg s dst value width with pc := s.pc + 4 }, [], none⟩

theorem input_full (value : Word) : GeneratedArm64Width.narrow value .w64 = value := by
  exact (input_width_refines value .w64).trans (narrow_full value)

theorem raw_step_refines (op : GeneratedArm64Mul.Mul) (width : Width)
    (dst lhs rhs addend : Reference.AArch64.Register) (s : Reference.AArch64.State)
    (valid : nativeWidth op width) :
    rawStep op width dst lhs rhs addend s =
      Reference.AArch64.step (.mul (instruction op width dst lhs rhs addend)) s := by
  cases op with
  | madd =>
      simpa only [rawStep, GeneratedArm64Mul.code, Nat.reduceEqDiff, ↓reduceIte, input_full,
        instruction, handlerStep, handlerState, Bool.false_eq_true]
        using step_refines (.multiply width false dst lhs rhs addend) s
  | msub =>
      simpa only [rawStep, GeneratedArm64Mul.code, Nat.reduceEqDiff, ↓reduceIte, input_full,
        instruction, handlerStep, handlerState, Bool.true_eq]
        using step_refines (.multiply width true dst lhs rhs addend) s
  | mul =>
      simpa only [rawStep, GeneratedArm64Mul.code, Nat.reduceEqDiff, ↓reduceIte, input_full,
        instruction, aliasStep, GeneratedArm64Mul.value]
        using (mul_refines width dst lhs rhs s).symm
  | umull =>
      have width64 := valid
      change width = .w64 at width64
      subst width
      simpa only [rawStep, GeneratedArm64Mul.code, Nat.reduceEqDiff, ↓reduceIte, input_full,
        instruction, aliasStep, GeneratedArm64Mul.value]
        using (umull_refines dst lhs rhs s).symm
  | udiv =>
      simpa only [rawStep, GeneratedArm64Mul.code, ↓reduceIte, instruction, handlerStep,
        handlerState, GeneratedArm64Mul.value]
        using step_refines (.unsignedDivide width dst lhs rhs) s
  | umulh =>
      have width64 := valid
      change width = .w64 at width64
      subst width
      simpa only [rawStep, GeneratedArm64Mul.code, Nat.reduceEqDiff, ↓reduceIte, input_full,
        instruction, handlerStep, handlerState, GeneratedArm64Mul.value]
        using step_refines (.unsignedHigh dst lhs rhs) s
  | umaddl =>
      have width64 := valid
      change width = .w64 at width64
      subst width
      simpa only [rawStep, GeneratedArm64Mul.code, Nat.reduceEqDiff, ↓reduceIte, input_full,
        instruction, handlerStep, handlerState, Bool.false_eq_true]
        using step_refines (.longMultiply false dst lhs rhs addend) s
  | smaddl =>
      have width64 := valid
      change width = .w64 at width64
      subst width
      simpa only [rawStep, GeneratedArm64Mul.code, Nat.reduceEqDiff, ↓reduceIte, input_full,
        instruction, handlerStep, handlerState, Bool.true_eq]
        using step_refines (.longMultiply true dst lhs rhs addend) s

def dispatch (opcode : Nat) (width : Width) (dst lhs rhs addend : Reference.AArch64.Register)
    (s : Reference.AArch64.State) : Option (Transition Reference.AArch64.State) :=
  (decodeOpcode opcode).map (fun op => rawStep op width dst lhs rhs addend s)

theorem dispatch_refines (op : GeneratedArm64Mul.Mul) (width : Width)
    (dst lhs rhs addend : Reference.AArch64.Register) (s : Reference.AArch64.State)
    (valid : nativeWidth op width) :
    dispatch (GeneratedArm64Mul.code op) width dst lhs rhs addend s =
      some (Reference.AArch64.step (.mul (instruction op width dst lhs rhs addend)) s) := by
  simp only [dispatch, decode_code]
  change some (rawStep op width dst lhs rhs addend s) = _
  rw [raw_step_refines op width dst lhs rhs addend s valid]

theorem dispatch_other (opcode : Nat) (width : Width) (dst lhs rhs addend : Reference.AArch64.Register)
    (s : Reference.AArch64.State) (other : ∀ op, opcode ≠ GeneratedArm64Mul.code op) :
    dispatch opcode width dst lhs rhs addend s = none := by
  simp [dispatch, decodeOpcode, other]


namespace DispatchChain

/-- The consecutive SHIFT, multiply and unary branches in ARM64_SIM_L_EXEC,
in their actual order. None hands the opcode to the surrounding dispatcher;
this is a concrete fragment, not a hypothesis that every handler refines. -/
def dispatch (opcode : Nat) (aux : BitVec 32) (width : Width)
    (dst src src2 src3 : Reference.AArch64.Register) (immediate : Word) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  match Arm64Shift.dispatch opcode aux width dst src src2 immediate s with
  | some result => some result
  | none => match Arm64Mul.dispatch opcode width dst src src2 src3 s with
    | some result => some result
    | none => Arm64Shift.Unary.dispatch opcode aux width dst src s

theorem shift_immediate_refines (width : Width) (kind : Reference.AArch64.ShiftKind)
    (amount : Fin width.bits) (dst src src2 src3 : Reference.AArch64.Register)
    (s : Reference.AArch64.State) :
    dispatch (GeneratedArm64DispatchFamily.code .shiftImm)
      (Arm64Shift.nativeAux kind) width dst src src2 src3 (BitVec.ofNat 64 amount.val) s =
      some (Reference.AArch64.step (.shift (.immediate width kind amount dst src)) s) := by
  unfold dispatch
  rw [Arm64Shift.dispatch_immediate_refines]

theorem shift_register_refines (width : Width) (kind : Reference.AArch64.ShiftKind)
    (dst src src2 src3 : Reference.AArch64.Register) (immediate : Word)
    (s : Reference.AArch64.State) :
    dispatch (GeneratedArm64DispatchFamily.code .shiftReg)
      (Arm64Shift.nativeAux kind) width dst src src2 src3 immediate s =
      some (Reference.AArch64.step (.shift (.register width kind dst src src2)) s) := by
  unfold dispatch
  rw [Arm64Shift.dispatch_register_refines]

theorem multiply_refines (op : GeneratedArm64Mul.Mul) (width : Width) (aux : BitVec 32)
    (dst src src2 src3 : Reference.AArch64.Register) (immediate : Word) (s : Reference.AArch64.State)
    (valid : nativeWidth op width) :
    dispatch (GeneratedArm64Mul.code op) aux width dst src src2 src3 immediate s =
      some (Reference.AArch64.step (.mul (instruction op width dst src src2 src3)) s) := by
  have before : Arm64Shift.dispatch (GeneratedArm64Mul.code op) aux width dst src src2 immediate s = none :=
    Arm64Shift.dispatch_other _ _ _ _ _ _ _ _
      (by cases op <;> decide) (by cases op <;> decide)
  unfold dispatch
  rw [before]
  rw [Arm64Mul.dispatch_refines op width dst src src2 src3 s valid]

/-- Numeric disjointness is proved against both preceding families, so unary
reaches its own body independently of AUX, unused operands and immediate. -/
theorem unary_reached (op : GeneratedArm64Unary.Unary) (aux : BitVec 32) (width : Width)
    (dst src src2 src3 : Reference.AArch64.Register) (immediate : Word) (s : Reference.AArch64.State) :
    dispatch (GeneratedArm64Unary.code op) aux width dst src src2 src3 immediate s =
      Arm64Shift.Unary.dispatch (GeneratedArm64Unary.code op) aux width dst src s := by
  have before : Arm64Shift.dispatch (GeneratedArm64Unary.code op) aux width dst src src2 immediate s = none :=
    Arm64Shift.dispatch_other _ _ _ _ _ _ _ _
      (by cases op <;> decide) (by cases op <;> decide)
  have middle : Arm64Mul.dispatch (GeneratedArm64Unary.code op) width dst src src2 src3 s = none :=
    Arm64Mul.dispatch_other _ _ _ _ _ _ _ (by intro member; cases op <;> cases member <;> decide)
  simp only [dispatch, before, middle]

theorem invert_refines (width : Width) (kind : Reference.AArch64.ShiftKind) (amount : Fin width.bits)
    (dst src src2 src3 : Reference.AArch64.Register) (immediate : Word) (lane0 lane3 : Byte)
    (s : Reference.AArch64.State) :
    dispatch (GeneratedArm64Unary.code .mvn)
      (Arm64Shift.Unary.packedAux (Arm64Shift.modifier kind) (BitVec.ofNat 8 amount.val) lane0 lane3)
      width dst src src2 src3 immediate s =
      some (Reference.AArch64.step (.shift (.invert width kind amount dst src)) s) := by
  rw [unary_reached]
  exact Arm64Shift.Unary.dispatch_invert_refines width kind amount dst src lane0 lane3 s

theorem negate_refines (width : Width) (kind : Fin 3) (amount : Fin width.bits)
    (dst src src2 src3 : Reference.AArch64.Register) (immediate : Word) (lane0 lane3 : Byte)
    (s : Reference.AArch64.State) :
    dispatch (GeneratedArm64Unary.code .neg)
      (Arm64Shift.Unary.packedAux (Arm64Shift.modifier (Reference.AArch64.arithmeticShift kind))
        (BitVec.ofNat 8 amount.val) lane0 lane3) width dst src src2 src3 immediate s =
      some (Reference.AArch64.step (.shift (.negate width kind amount dst src)) s) := by
  rw [unary_reached]
  exact Arm64Shift.Unary.dispatch_negate_refines width kind amount dst src lane0 lane3 s

theorem unmodified_invert_refines (width : Width) (dst src src2 src3 : Reference.AArch64.Register)
    (immediate : Word) (amount lane0 lane3 : Byte) (s : Reference.AArch64.State) :
    dispatch (GeneratedArm64Unary.code .mvn) (Arm64Shift.Unary.packedAux .none amount lane0 lane3)
      width dst src src2 src3 immediate s =
      some (Reference.AArch64.step
        (.shift (.invert width .lsl ⟨0, by cases width <;> decide⟩ dst src)) s) := by
  rw [unary_reached]
  exact Arm64Shift.Unary.dispatch_unmodified_invert_refines width dst src amount lane0 lane3 s

theorem unmodified_negate_refines (width : Width) (dst src src2 src3 : Reference.AArch64.Register)
    (immediate : Word) (amount lane0 lane3 : Byte) (s : Reference.AArch64.State) :
    dispatch (GeneratedArm64Unary.code .neg) (Arm64Shift.Unary.packedAux .none amount lane0 lane3)
      width dst src src2 src3 immediate s =
      some (Reference.AArch64.step
        (.shift (.negate width 0 ⟨0, by cases width <;> decide⟩ dst src)) s) := by
  rw [unary_reached]
  exact Arm64Shift.Unary.dispatch_unmodified_negate_refines width dst src amount lane0 lane3 s

theorem other (opcode : Nat) (aux : BitVec 32) (width : Width)
    (dst src src2 src3 : Reference.AArch64.Register) (immediate : Word) (s : Reference.AArch64.State)
    (notShiftImm : opcode ≠ GeneratedArm64DispatchFamily.code .shiftImm)
    (notShiftReg : opcode ≠ GeneratedArm64DispatchFamily.code .shiftReg)
    (notMul : ∀ op, opcode ≠ GeneratedArm64Mul.code op)
    (notUnary : ∀ op, opcode ≠ GeneratedArm64Unary.code op) :
    dispatch opcode aux width dst src src2 src3 immediate s = none := by
  have first := Arm64Shift.dispatch_other opcode aux width dst src src2 immediate s notShiftImm notShiftReg
  have second := Arm64Mul.dispatch_other opcode width dst src src2 src3 s notMul
  have third := Arm64Shift.Unary.dispatch_other opcode aux width dst src s (notUnary .mvn) (notUnary .neg)
  simp only [dispatch, first, second, third]

end DispatchChain

end KProgFormal.Refinement.Arm64Mul
