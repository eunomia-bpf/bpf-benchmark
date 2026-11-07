import KProgFormal.Reference.AArch64
import KProgFormal.Arm64Cond
import KProgFormal.Generated.GeneratedArm64CcDecode

namespace KProgFormal.Refinement.Arm64Condition

/-- The production NZCV bits, projected from the architectural status word. -/
def flags (word : Reference.Word) : Arm64Flags :=
  ⟨word.getLsbD 31, word.getLsbD 30, word.getLsbD 29, word.getLsbD 28⟩

def nativeCode (predicate : Arm64Cond) : Fin 16 :=
  ⟨GeneratedArm64Cond.code predicate, by cases predicate <;> decide⟩

theorem condition_refines (word : Reference.Word) (predicate : Arm64Cond) :
    generatedArm64Cond (flags word) predicate =
      Reference.AArch64.condition word (nativeCode predicate) := by
  cases predicate <;> rfl

/-- NV has architectural encoding15, but uses the same predicate as AL14.
This is semantic normalization, not interpreting NV as the complement of AL. -/
theorem nv_normalizes_to_al (word : Reference.Word) :
    Reference.AArch64.condition word 15 = generatedArm64Cond (flags word) .al := by rfl


/-- ARM64_SIM_L_EVAL_COND compares the whole AUX value, not its low byte.
Only codes0..14 enter the generated predicate. Native NV is normalized by
GeneratedArm64CcDecode before this boundary; raw15 is not a C condition arm. -/
def decode (code : Nat) : Option Arm64Cond :=
  if code < 15 then some (match code with
    | 0 => .eq | 1 => .ne | 2 => .cs | 3 => .cc
    | 4 => .mi | 5 => .pl | 6 => .vs | 7 => .vc
    | 8 => .hi | 9 => .ls | 10 => .ge | 11 => .lt
    | 12 => .gt | 13 => .le | _ => .al)
  else none

theorem decode_code (predicate : Arm64Cond) :
    decode (GeneratedArm64Cond.code predicate) = some predicate := by cases predicate <;> rfl

theorem decode_bad (code : Nat) (bad : 15 ≤ code) : decode code = none := by
  simp only [decode, if_neg (Nat.not_lt.mpr bad)]

theorem decode_normalized_nv : decode (GeneratedArm64CcDecode.code .nv) = some .al := rfl

end KProgFormal.Refinement.Arm64Condition
