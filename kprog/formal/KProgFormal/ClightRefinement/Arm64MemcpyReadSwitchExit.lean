import KProgFormal.ClightRefinement.Arm64MemcpyReadSpCheck

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyReadSwitchExit

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpyReadCall (reader)

private structure Parts where
  remaining : CC.Stmt
  valueCopy : CC.Stmt
  body : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original reader switch continuation changed"
      pure actual.getAppArgs
    let first ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyReadDispatch.continuation CC.Cont.Kstop)) none) ``CC.Cont.Kseq 2
    let second ← peel first[1]! ``CC.Cont.Kseq 2
    let switch ← peel second[1]! ``CC.Cont.Kswitch 1
    let value ← peel switch[0]! ``CC.Cont.Kseq 2
    let loop ← peel value[1]! ``CC.Cont.Kloop1 3
    Lean.Elab.Tactic.closeMainGoal `actual_reader_switch_exit
      (← Lean.Meta.mkAppM ``Parts.mk #[second[0]!,value[0]!,loop[0]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_reader_switch_exit_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def remaining : CC.Stmt := by run_tac cachePart (← `(parts.remaining))
private def valueCopy : CC.Stmt := by run_tac cachePart (← `(parts.valueCopy))
private def body : CC.Stmt := by run_tac cachePart (← `(parts.body))

def continuation (k : CC.Cont) : CC.Cont :=
  .Kseq remaining (.Kswitch (.Kseq valueCopy (.Kloop1 body .Sbreak k)))

theorem source : Arm64MemcpyReadDispatch.continuation k = .Kseq Arm64MemcpyReadDispatch.read (continuation k) := rfl
private theorem value_source : valueCopy =
    .Sset Arm64Program.___a64_memory_value (.Etempvar Arm64Program.___a64_mrd_value CC.tulong) := rfl

def temps (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv :=
  le.set Arm64Program.___a64_memory_value (.Vlong value)

/-- The genuine completed base statement enters the original source37 case
with its remaining labels and Kswitch intact. -/
theorem enter_read (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 1 (.State reader .Sskip (Arm64MemcpyReadDispatch.continuation k) e le m)
      (.State reader Arm64MemcpyReadDispatch.read (continuation k) e le m) := by
  rw [source]
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

/-- The original post-read case exits its own outer loop before executing
its actual final break statement under the saved switch continuation. -/
theorem outer_exit (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 3 (.State reader .Sskip (Arm64MemcpyReadObserve.continuation k) e le m)
      (.State reader .Sbreak k e le m) := by
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

/-- Follow the real case-break propagation through the original remaining
labels and Kswitch, copy the actual mrd_value, then leave its original loop. -/
theorem switch_exit (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (value : BitVec 64)
    (read : le.get Arm64Program.___a64_mrd_value = some (.Vlong value)) :
    InternalRun world 6 (.State reader .Sbreak (continuation k) e le m)
      (.State reader .Sskip k e (temps le value) m) := by
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [value_source]
  refine .step (mid := .State reader .Sskip (.Kloop1 body .Sbreak k) e (temps le value) m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [CC.doStep,CC.doEvalExpr,read,temps]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

/-- Both original loop and switch exits operate on the same current result. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (value : BitVec 64)
    (read : le.get Arm64Program.___a64_mrd_value = some (.Vlong value)) :
    InternalRun world 9
      (.State reader .Sskip (Arm64MemcpyReadObserve.continuation (continuation k)) e le m)
      (.State reader .Sskip k e (temps le value) m) :=
  (outer_exit e le m (continuation k)).trans (switch_exit e le m k value read)

theorem kept (le : CC.TempEnv) (value : BitVec 64) (key : CC.Ident)
    (other : Arm64Program.___a64_memory_value ≠ key) : (temps le value).get key = le.get key :=
  CC.PTree.gso _ _ _ _ other

end KProgFormal.ClightRefinement.Arm64MemcpyReadSwitchExit
