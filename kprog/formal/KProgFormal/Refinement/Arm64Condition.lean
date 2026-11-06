import KProgFormal.Reference.AArch64
import KProgFormal.Arm64Cond

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

end KProgFormal.Refinement.Arm64Condition
