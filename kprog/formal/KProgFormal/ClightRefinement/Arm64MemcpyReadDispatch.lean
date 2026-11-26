import KProgFormal.ClightRefinement.Arm64MemcpyReadAbiContext

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyReadDispatch

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpyReadCall (reader)

private structure Parts where
  loop : CC.Stmt
  body : CC.Stmt
  switch : CC.Stmt
  valueCopy : CC.Stmt
  labels : CC.LStmts
  selected : CC.Stmt
  pair : CC.Stmt
  remaining : CC.Stmt
  base : CC.Stmt
  read : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original memory-reader stack switch changed: expected {ctor}, got {actual.getAppFn}"
      pure actual.getAppArgs
    let route ← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyReadAbiContext.stack)) none
    let loop ← peel route ``CC.Stmt.Sloop 2
    let body ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let switch ← peel body[0]! ``CC.Stmt.Sswitch 2
    let zero ← Lean.Elab.Term.elabTerm (← `((0 : Int))) none
    let labels ← Lean.Meta.mkAppM ``CC.selectSwitch #[zero,switch[1]!]
    let selected ← Lean.Meta.mkAppM ``CC.seqOfLabeledStatement #[labels]
    let first ← peel selected ``CC.Stmt.Ssequence 2
    let pair ← peel first[0]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_memory_reader_stack_dispatch
      (← Lean.Meta.mkAppM ``Parts.mk #[route,loop[0]!,body[0]!,body[1]!,
        switch[1]!,selected,first[0]!,first[1]!,pair[0]!,pair[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memory_reader_dispatch_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def loop : CC.Stmt := by run_tac cachePart (← `(parts.loop))
private def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
private def switch : CC.Stmt := by run_tac cachePart (← `(parts.switch))
private def valueCopy : CC.Stmt := by run_tac cachePart (← `(parts.valueCopy))
private def labels : CC.LStmts := by run_tac cachePart (← `(parts.labels))
private def selected : CC.Stmt := by run_tac cachePart (← `(parts.selected))
private def pair : CC.Stmt := by run_tac cachePart (← `(parts.pair))
private def remaining : CC.Stmt := by run_tac cachePart (← `(parts.remaining))
def base : CC.Stmt := by run_tac cachePart (← `(parts.base))
def read : CC.Stmt := by run_tac cachePart (← `(parts.read))

theorem source : Arm64MemcpyReadAbiContext.stack = loop := rfl
private theorem loop_source : loop = .Sloop body .Sbreak := rfl
private theorem body_source : body = .Ssequence switch valueCopy := rfl
private theorem switch_source : switch = .Sswitch
    (.Etempvar Arm64Program.___a64_memory_source CC.tuchar) labels := rfl
private theorem selected_source : selected = CC.seqOfLabeledStatement (CC.selectSwitch 0 labels) := rfl
private theorem selected_first : selected = .Ssequence pair remaining := rfl
private theorem pair_source : pair = .Ssequence base read := rfl

/-- The actual imported switch semantics select exactly the original two
case0 source statements, retaining all original labels and break context. -/
theorem case_source : base = Arm64Program.s_kprog_arm64_program_memory_read_28 ∧
    read = Arm64Program.s_kprog_arm64_program_memory_read_37 := ⟨rfl,rfl⟩

def continuation (k : CC.Cont) : CC.Cont :=
  .Kseq read (.Kseq remaining (.Kswitch (.Kseq valueCopy (.Kloop1 body .Sbreak k))))

/-- Follow the actual loop and switch into the original R1
pointer statement. The caller, original case suffix and heap stay intact. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (source0 : le.get Arm64Program.___a64_memory_source = some (.Vint 0)) :
    InternalRun world 5 (.State reader Arm64MemcpyReadAbiContext.stack k e le m)
      (.State reader base (continuation k) e le m) := by
  rw [source]
  rw [loop_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [body_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State reader selected (.Kswitch (.Kseq valueCopy (.Kloop1 body .Sbreak k))) e le m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [switch_source,CC.doStep,CC.doEvalExpr,source0,selected_source]
    rfl
  rw [selected_first]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [pair_source]
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

end KProgFormal.ClightRefinement.Arm64MemcpyReadDispatch
