import KProgFormal.ClightRefinement.Arm64MemcpyReadByteSetup
import KProgFormal.ClightRefinement.Arm64MemcpyReadWidthGuards

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyReadObserve

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpyReadCall (reader)

private structure Parts where
  outerBody : CC.Stmt
  caseBreak : CC.Stmt

private def parts : Parts := by
  run_tac do
    let root ← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyReadDispatch.read)) none
    let root ← Lean.Meta.withTransparency .all (Lean.Meta.whnf root)
    unless root.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original read case changed"
    let outer ← Lean.Meta.withTransparency .all (Lean.Meta.whnf root.getAppArgs[0]!)
    unless outer.isAppOfArity ``CC.Stmt.Sloop 2 do throwError "original outer reader loop changed"
    Lean.Elab.Tactic.closeMainGoal `actual_reader_observed_loop
      (← Lean.Meta.mkAppM ``Parts.mk #[outer.getAppArgs[0]!,root.getAppArgs[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_reader_observed_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def outerBody : CC.Stmt := by run_tac cachePart (← `(parts.outerBody))
private def caseBreak : CC.Stmt := by run_tac cachePart (← `(parts.caseBreak))

def continuation (k : CC.Cont) : CC.Cont := .Kloop1 outerBody .Sbreak (.Kseq caseBreak k)

theorem source : Arm64MemcpyReadByteSetup.observed =
    .Sset Arm64Program.___a64_observed (.Etempvar Arm64Program.___a64_str_value CC.tulong) := rfl

def temps (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv :=
  le.set Arm64Program.___a64_observed (.Vlong value)

/-- The real observed-value copy exits the actual inner loop through its
original break and reaches the genuine post-read SP sequence. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (value : BitVec 64)
    (read : le.get Arm64Program.___a64_str_value = some (.Vlong value)) :
    InternalRun world 5
      (.State reader .Sskip (.Kseq Arm64MemcpyReadByteSetup.observed (Arm64MemcpyReadIndex.continuation k)) e le m)
      (.State reader Arm64MemcpyReadIndex.postRead (continuation k) e (temps le value) m) := by
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [source]
  refine .step (mid := .State reader .Sskip (Arm64MemcpyReadIndex.continuation k) e (temps le value) m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [CC.doStep,CC.doEvalExpr,read,temps]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

/-- The seven real width gates and observed/loop suffix compose without
changing the loaded word or the current heap. -/
theorem after_width (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (value : BitVec 64)
    (width : le.get Arm64Program.___a64_str_width = some (.Vint 1))
    (read : le.get Arm64Program.___a64_str_value = some (.Vlong value)) :
    InternalRun world 24
      (.State reader Arm64MemcpyReadByte.remaining
        (.Kseq Arm64MemcpyReadByteSetup.observed (Arm64MemcpyReadIndex.continuation k)) e le m)
      (.State reader Arm64MemcpyReadIndex.postRead (continuation k) e (temps le value) m) :=
  (Arm64MemcpyReadWidthGuards.execute e le m _ width).trans (execute e le m k value read)

theorem kept (le : CC.TempEnv) (value : BitVec 64) (key : CC.Ident)
    (other : Arm64Program.___a64_observed ≠ key) : (temps le value).get key = le.get key :=
  CC.PTree.gso _ _ _ _ other

end KProgFormal.ClightRefinement.Arm64MemcpyReadObserve
