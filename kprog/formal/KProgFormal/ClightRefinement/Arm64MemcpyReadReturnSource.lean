import KProgFormal.ClightRefinement.Arm64MemcpyReadSwitchExit

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyReadReturnSource

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpyReadCall (reader)

theorem source : Arm64MemcpyReadContext.result =
    .Sset Arm64Program._result (.Etempvar Arm64Program.___a64_memory_value CC.tulong) ∧
    Arm64MemcpyReadSource.result = .Sreturn (some (.Etempvar Arm64Program._result CC.tulong)) := ⟨rfl,rfl⟩

def temps (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv := le.set Arm64Program._result (.Vlong value)

/-- The real result assignment and original outer reader loop exit reach
its true Sreturn statement. The allocated reader environment stays intact
for the subsequent actual thirteen-local free and return transition. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (value : BitVec 64)
    (read : le.get Arm64Program.___a64_memory_value = some (.Vlong value)) :
    InternalRun world 5
      (.State reader .Sskip (.Kseq Arm64MemcpyReadContext.result (Arm64MemcpyReadSource.outerCont k)) e le m)
      (.State reader Arm64MemcpyReadSource.result k e (temps le value) m) := by
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [source.1]
  refine .step (mid := .State reader .Sskip (Arm64MemcpyReadSource.outerCont k) e (temps le value) m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [CC.doStep,CC.doEvalExpr,read,temps]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

theorem kept (le : CC.TempEnv) (value : BitVec 64) (key : CC.Ident)
    (other : Arm64Program._result ≠ key) : (temps le value).get key = le.get key := CC.PTree.gso _ _ _ _ other

theorem result_read (le : CC.TempEnv) (value : BitVec 64) :
    (temps le value).get Arm64Program._result = some (.Vlong value) := CC.PTree.gss _ _ _

end KProgFormal.ClightRefinement.Arm64MemcpyReadReturnSource
