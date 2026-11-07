import KProgFormal.Arm64Csel
import KProgFormal.Arm64Cneg
import KProgFormal.Arm64CselPtr
import KProgFormal.Refinement.Arm64Condition
import KProgFormal.Refinement.Arm64Register

namespace KProgFormal.Refinement.Arm64Select

open Reference
open Reference.AArch64 (Width SelectElse Register)
open Arm64Register (readReg writeReg)
open Arm64Condition (flags nativeCode)

def opcode : SelectElse → GeneratedArm64Csel.Csel
  | .keep => .csel | .increment => .csinc | .invert => .csinv | .negate => .csneg

theorem value_refines (width : Width) (alternative : SelectElse)
    (taken : Bool) (lhs rhs : Reference.Word) :
    Reference.AArch64.narrow (GeneratedArm64Csel.value (opcode alternative) taken lhs rhs) width =
      Reference.AArch64.selectValue width alternative taken lhs rhs := by
  cases width <;> cases alternative <;> cases taken <;>
    simp only [opcode, GeneratedArm64Csel.value, Reference.AArch64.selectValue,
      Reference.AArch64.narrow, Reference.AArch64.Width.bits, Reference.Word,
      Bool.false_eq_true, ↓reduceIte] <;> bv_decide

/-- Four native conditional-select bodies use the generated condition, value,
register-cell selector and zero-extending write arm. All sources precede write. -/
def handlerStep (width : Width) (alternative : SelectElse) (dst lhs rhs : Register)
    (predicate : Arm64Cond) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let taken := generatedArm64Cond (flags s.flags) predicate
  let value := GeneratedArm64Csel.value (opcode alternative) taken (readReg s lhs) (readReg s rhs)
  ⟨{ writeReg s dst value width with pc := s.pc + 4 }, [], none⟩

theorem step_refines (width : Width) (alternative : SelectElse) (dst lhs rhs : Register)
    (predicate : Arm64Cond) (s : Reference.AArch64.State) :
    handlerStep width alternative dst lhs rhs predicate s =
      Reference.AArch64.step (.select width alternative dst lhs rhs (nativeCode predicate)) s := by
  simp only [handlerStep, Reference.AArch64.step, Arm64Register.read_refines,
    Arm64Register.write_refines, Arm64Condition.condition_refines, value_refines]

theorem handler_refines (width : Width) (alternative : SelectElse) (dst lhs rhs : Register)
    (predicate : Arm64Cond) (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.select width alternative dst lhs rhs (nativeCode predicate)) s
      (handlerStep width alternative dst lhs rhs predicate s) :=
  (step_refines width alternative dst lhs rhs predicate s).symm

/-- A decoded NV instruction uses the proved AL handler without reading NZCV;
all register/vector/memory/PC/effect components satisfy the same step theorem. -/
theorem nv_handler_refines (width : Width) (alternative : SelectElse) (dst lhs rhs : Register)
    (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.select width alternative dst lhs rhs 15) s
      (handlerStep width alternative dst lhs rhs .al s) := by
  have h := handler_refines width alternative dst lhs rhs .al s
  exact h

/-- Alias conditions invert adjacent raw code pairs; AL/NV are not valid
condition operands for CINC/CINV/CSET/CSETM aliases in the A64 encoding. -/
def inverse : Arm64Cond → Arm64Cond
  | .eq => .ne | .ne => .eq | .cs => .cc | .cc => .cs
  | .mi => .pl | .pl => .mi | .vs => .vc | .vc => .vs
  | .hi => .ls | .ls => .hi | .ge => .lt | .lt => .ge
  | .gt => .le | .le => .gt | .al => .al

theorem inverse_refines (word : Reference.Word) (predicate : Arm64Cond)
    (h : predicate ≠ .al) :
    Reference.AArch64.condition word (nativeCode (inverse predicate)) =
      !Reference.AArch64.condition word (nativeCode predicate) := by
  cases predicate <;> try (exact (h rfl).elim)
  all_goals
    simp only [inverse, nativeCode, GeneratedArm64Cond.code,
      Reference.AArch64.condition, Reference.Word] <;> bv_decide

inductive Alias | increment | invert | set | mask
  deriving DecidableEq, Repr

def aliasOpcode : Alias → GeneratedArm64Csel.Csel
  | .increment => .cinc | .invert => .cinv | .set => .cset | .mask => .csetm

def aliasAlternative : Alias → SelectElse
  | .increment | .set => .increment
  | .invert | .mask => .invert

def aliasSource : Alias → Register → Register
  | .increment, src | .invert, src => src
  | .set, _ | .mask, _ => 31

def aliasSourceValue : Alias → Reference.Word → Reference.Word
  | .increment, value | .invert, value => value
  | .set, _ | .mask, _ => 0

theorem alias_read_refines (alias : Alias) (s : Reference.AArch64.State) (src : Register) :
    Reference.AArch64.readReg s (aliasSource alias src) =
      aliasSourceValue alias (Reference.AArch64.readReg s src) := by
  cases alias <;> rfl

theorem alias_value_refines (width : Width) (alias : Alias) (taken : Bool)
    (src : Reference.Word) :
    Reference.AArch64.narrow (GeneratedArm64Csel.value (aliasOpcode alias) taken src 0) width =
      Reference.AArch64.selectValue width (aliasAlternative alias) (!taken)
        (aliasSourceValue alias src) (aliasSourceValue alias src) := by
  cases width <;> cases alias <;> cases taken <;>
    simp only [aliasOpcode, aliasAlternative, aliasSourceValue, GeneratedArm64Csel.value,
      Reference.AArch64.selectValue, Reference.AArch64.narrow, Reference.AArch64.Width.bits,
      Reference.Word, Bool.not_false, Bool.not_true, Bool.false_eq_true, ↓reduceIte] <;> bv_decide

def aliasStep (width : Width) (alias : Alias) (dst src : Register)
    (predicate : Arm64Cond) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let value := GeneratedArm64Csel.value (aliasOpcode alias)
    (generatedArm64Cond (flags s.flags) predicate) (readReg s src) 0
  ⟨{ writeReg s dst value width with pc := s.pc + 4 }, [], none⟩

/-- These four distinct production opcodes refine their actual native aliases,
including condition inversion and ZR operands for CSET/CSETM. -/
theorem alias_step_refines (width : Width) (alias : Alias) (dst src : Register)
    (predicate : Arm64Cond) (s : Reference.AArch64.State) (h : predicate ≠ .al) :
    aliasStep width alias dst src predicate s =
      Reference.AArch64.step (.select width (aliasAlternative alias) dst
        (aliasSource alias src) (aliasSource alias src) (nativeCode (inverse predicate))) s := by
  simp only [aliasStep, Reference.AArch64.step, Arm64Register.read_refines,
    Arm64Register.write_refines, inverse_refines s.flags predicate h,
    Arm64Condition.condition_refines, alias_read_refines, alias_value_refines]

theorem alias_handler_refines (width : Width) (alias : Alias) (dst src : Register)
    (predicate : Arm64Cond) (s : Reference.AArch64.State) (h : predicate ≠ .al) :
    Reference.AArch64.Step (.select width (aliasAlternative alias) dst
      (aliasSource alias src) (aliasSource alias src) (nativeCode (inverse predicate))) s
      (aliasStep width alias dst src predicate s) :=
  (alias_step_refines width alias dst src predicate s h).symm

/-- CNEG is the remaining conditional alias, implemented by its own generated
width-narrowing macro and encoded as CSNEG with equal source registers. -/
theorem negate_value_refines (width : Width) (taken : Bool) (src : Reference.Word) :
    Reference.AArch64.narrow
      (GeneratedArm64Cneg.value .cneg taken src (Arm64Register.handlerWidth width)) width =
      Reference.AArch64.selectValue width .negate (!taken) src src := by
  cases width <;> cases taken <;>
    simp only [GeneratedArm64Cneg.value, Arm64Register.handlerWidth,
      GeneratedArm64Width.narrow, GeneratedArm64Width.mask,
      Reference.AArch64.selectValue, Reference.AArch64.narrow, Reference.AArch64.Width.bits,
      Reference.Word, Bool.not_false, Bool.not_true, Bool.false_eq_true, ↓reduceIte] <;> bv_decide

def negateStep (width : Width) (dst src : Register) (predicate : Arm64Cond)
    (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let value := GeneratedArm64Cneg.value .cneg (generatedArm64Cond (flags s.flags) predicate)
    (readReg s src) (Arm64Register.handlerWidth width)
  ⟨{ writeReg s dst value width with pc := s.pc + 4 }, [], none⟩

theorem negate_step_refines (width : Width) (dst src : Register) (predicate : Arm64Cond)
    (s : Reference.AArch64.State) (h : predicate ≠ .al) :
    negateStep width dst src predicate s =
      Reference.AArch64.step (.select width .negate dst src src (nativeCode (inverse predicate))) s := by
  simp only [negateStep, Reference.AArch64.step, Arm64Register.read_refines,
    Arm64Register.write_refines, inverse_refines s.flags predicate h,
    Arm64Condition.condition_refines, negate_value_refines]

theorem negate_handler_refines (width : Width) (dst src : Register) (predicate : Arm64Cond)
    (s : Reference.AArch64.State) (h : predicate ≠ .al) :
    Reference.AArch64.Step (.select width .negate dst src src (nativeCode (inverse predicate))) s
      (negateStep width dst src predicate s) := (negate_step_refines width dst src predicate s h).symm


/-- Actual eight-member conditional-select family gate. -/
def decodeOpcode (code : Nat) : Option GeneratedArm64Csel.Csel :=
  if code = GeneratedArm64Csel.code .csel then some .csel
  else if code = GeneratedArm64Csel.code .cinc then some .cinc
  else if code = GeneratedArm64Csel.code .cset then some .cset
  else if code = GeneratedArm64Csel.code .cinv then some .cinv
  else if code = GeneratedArm64Csel.code .csinv then some .csinv
  else if code = GeneratedArm64Csel.code .csinc then some .csinc
  else if code = GeneratedArm64Csel.code .csetm then some .csetm
  else if code = GeneratedArm64Csel.code .csneg then some .csneg else none

theorem decode_code (op : GeneratedArm64Csel.Csel) :
    decodeOpcode (GeneratedArm64Csel.code op) = some op := by cases op <;> rfl

/-- The generated pointer-preserving gate precedes the scalar computation.
Only CSEL/X copies the selected incoming source at full width; every other
row computes its generated scalar value and performs the width write. This
numeric projection leaves native pointer/provenance transport to Entry/O4. -/
def rawStep (op : GeneratedArm64Csel.Csel) (width : Width) (dst lhs rhs : Register)
    (predicate : Arm64Cond) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let taken := generatedArm64Cond (flags s.flags) predicate
  let state := if GeneratedArm64CselPtr.ptrTagPath op (Arm64Register.handlerWidth width) then
      writeReg s dst (if taken then readReg s lhs else readReg s rhs) .w64
    else writeReg s dst (GeneratedArm64Csel.value op taken (readReg s lhs) (readReg s rhs)) width
  ⟨{ state with pc := s.pc + 4 }, [], none⟩

theorem raw_step_refines (width : Width) (alternative : SelectElse) (dst lhs rhs : Register)
    (predicate : Arm64Cond) (s : Reference.AArch64.State) :
    rawStep (opcode alternative) width dst lhs rhs predicate s =
      Reference.AArch64.step (.select width alternative dst lhs rhs (nativeCode predicate)) s := by
  rw [← step_refines]
  cases alternative <;> cases width <;>
    simp only [rawStep, handlerStep, opcode, GeneratedArm64CselPtr.ptrTagPath,
      Arm64Register.handlerWidth, GeneratedArm64Csel.value, Bool.false_eq_true, ↓reduceIte]

theorem raw_alias_refines (width : Width) (alias : Alias) (dst src src2 : Register)
    (predicate : Arm64Cond) (s : Reference.AArch64.State) (valid : predicate ≠ .al) :
    rawStep (aliasOpcode alias) width dst src src2 predicate s =
      Reference.AArch64.step (.select width (aliasAlternative alias) dst
        (aliasSource alias src) (aliasSource alias src) (nativeCode (inverse predicate))) s := by
  rw [← alias_step_refines width alias dst src predicate s valid]
  cases alias <;> cases width <;>
    simp only [rawStep, aliasStep, aliasOpcode, GeneratedArm64CselPtr.ptrTagPath,
      Arm64Register.handlerWidth, GeneratedArm64Csel.value, Bool.false_eq_true, ↓reduceIte]

def dispatch (code condition : Nat) (width : Width) (dst lhs rhs : Register)
    (s : Reference.AArch64.State) : Option (Transition Reference.AArch64.State) :=
  (decodeOpcode code).bind (fun op => (Arm64Condition.decode condition).map
    (fun predicate => rawStep op width dst lhs rhs predicate s))

theorem dispatch_refines (width : Width) (alternative : SelectElse) (dst lhs rhs : Register)
    (predicate : Arm64Cond) (s : Reference.AArch64.State) :
    dispatch (GeneratedArm64Csel.code (opcode alternative)) (GeneratedArm64Cond.code predicate)
      width dst lhs rhs s =
      some (Reference.AArch64.step (.select width alternative dst lhs rhs (nativeCode predicate)) s) := by
  simp only [dispatch, decode_code, Arm64Condition.decode_code]
  change some (rawStep (opcode alternative) width dst lhs rhs predicate s) = _
  rw [raw_step_refines]

theorem dispatch_alias_refines (width : Width) (alias : Alias) (dst src src2 : Register)
    (predicate : Arm64Cond) (s : Reference.AArch64.State) (valid : predicate ≠ .al) :
    dispatch (GeneratedArm64Csel.code (aliasOpcode alias)) (GeneratedArm64Cond.code predicate)
      width dst src src2 s =
      some (Reference.AArch64.step (.select width (aliasAlternative alias) dst
        (aliasSource alias src) (aliasSource alias src) (nativeCode (inverse predicate))) s) := by
  simp only [dispatch, decode_code, Arm64Condition.decode_code]
  change some (rawStep (aliasOpcode alias) width dst src src2 predicate s) = _
  rw [raw_alias_refines width alias dst src src2 predicate s valid]

/-- NV's native encoding15 consumes the existing producer-normalized AL14,
while the canonical ISA retains native condition15. No raw15 C arm is added. -/
theorem dispatch_normalized_nv (width : Width) (alternative : SelectElse) (dst lhs rhs : Register)
    (s : Reference.AArch64.State) :
    dispatch (GeneratedArm64Csel.code (opcode alternative)) (GeneratedArm64CcDecode.code .nv)
      width dst lhs rhs s =
      some (Reference.AArch64.step (.select width alternative dst lhs rhs 15) s) := by
  simp only [dispatch, decode_code, Arm64Condition.decode_normalized_nv]
  change some (rawStep (opcode alternative) width dst lhs rhs .al s) = _
  rw [raw_step_refines]
  rfl

def dispatchNegate (code condition : Nat) (width : Width) (dst src : Register)
    (s : Reference.AArch64.State) : Option (Transition Reference.AArch64.State) :=
  if code = GeneratedArm64Cneg.code .cneg then
    (Arm64Condition.decode condition).map (fun predicate => negateStep width dst src predicate s)
  else none

theorem dispatch_negate_refines (width : Width) (dst src : Register) (predicate : Arm64Cond)
    (s : Reference.AArch64.State) (valid : predicate ≠ .al) :
    dispatchNegate (GeneratedArm64Cneg.code .cneg) (GeneratedArm64Cond.code predicate) width dst src s =
      some (Reference.AArch64.step (.select width .negate dst src src (nativeCode (inverse predicate))) s) := by
  simp only [dispatchNegate, ↓reduceIte, Arm64Condition.decode_code]
  change some (negateStep width dst src predicate s) = _
  rw [negate_step_refines width dst src predicate s valid]

theorem dispatch_bad_condition (code condition : Nat) (width : Width) (dst lhs rhs : Register)
    (s : Reference.AArch64.State) (bad : 15 ≤ condition) :
    dispatch code condition width dst lhs rhs s = none := by
  simp [dispatch, Arm64Condition.decode_bad condition bad]

theorem dispatch_negate_bad_condition (code condition : Nat) (width : Width) (dst src : Register)
    (s : Reference.AArch64.State) (bad : 15 ≤ condition) :
    dispatchNegate code condition width dst src s = none := by
  simp [dispatchNegate, Arm64Condition.decode_bad condition bad]

theorem dispatch_other (code condition : Nat) (width : Width) (dst lhs rhs : Register)
    (s : Reference.AArch64.State) (other : ∀ op, code ≠ GeneratedArm64Csel.code op) :
    dispatch code condition width dst lhs rhs s = none := by simp [dispatch, decodeOpcode, other]

theorem dispatch_negate_other (code condition : Nat) (width : Width) (dst src : Register)
    (s : Reference.AArch64.State) (other : code ≠ GeneratedArm64Cneg.code .cneg) :
    dispatchNegate code condition width dst src s = none := by simp [dispatchNegate, other]

end KProgFormal.Refinement.Arm64Select
