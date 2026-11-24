import KProgFormal.ClightRefinement.X86ProducerScalarSource

namespace KProgFormal.ClightRefinement.X86ProducerScalarValue
open X86ProducerScalarSource

def input (i : Fin 8) (word : BitVec 64) : CC.Val :=
  .Vlong (if i.val < 6 then word &&& 1 else word)
def value (i : Fin 8) (word : BitVec 64) : CC.Val := if i.val < 6 then
  .Vint (CC.Cop.castIntInt .I8 .Unsigned (CC.Integers.Int.repr (CC.Integers.Int64.unsigned (word &&& 1))))
  else .Vlong word

private theorem target_type : ∀ i : Fin 8, X86ProducerHeaderSource.localType (row i) =
    if i.val < 6 then CC.tuchar else CC.tulong := by decide +kernel

/-- Evaluate the actual input&1/full-word source expression on an arbitrary
provider word and complete supplied memory. -/
theorem evaluated (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (i : Fin 8) (word : BitVec 64)
    (read : le.get (site i).resultName = some (.Vlong word)) :
    CC.doEvalExpr X86ProducerLayout.ge e le memory (rhs i) = some (input i word) := by
  by_cases flag : i.val < 6
  all_goals simp only [rhs, input, flag, ite_true, ite_false, CC.doEvalExpr, CC.typeof, read]
  all_goals rfl

/-- The actual target-type cast and typed-load normalization; no narrowed
value or successful store is supplied by a caller. -/
theorem cast (memory : CC.Mem) (i : Fin 8) (word : BitVec 64) :
    CC.Cop.semCast (input i word) (CC.typeof (rhs i)) (X86ProducerHeaderSource.localType (row i)) memory = some (value i word) ∧
    CC.Val.loadResult (chunk i) (value i word) = value i word := by
  rw [target_type]
  by_cases flag : i.val < 6
  all_goals simp only [rhs, input, value, chunk, flag, ite_true, ite_false, CC.typeof]
  · constructor
    · rfl
    · simp [CC.Val.loadResult, CC.Cop.castIntInt, CC.Integers.Int.zero_ext,
        CC.Integers.MI.zero_ext, BitVec.and_assoc]
  · constructor <;> rfl

end KProgFormal.ClightRefinement.X86ProducerScalarValue
