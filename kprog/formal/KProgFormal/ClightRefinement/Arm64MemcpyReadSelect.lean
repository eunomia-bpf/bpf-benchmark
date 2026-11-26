import KProgFormal.ClightRefinement.Arm64MemcpyReadTag

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyReadSelect

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpyReadCall (reader)

private structure Parts where
  loop : CC.Stmt
  body : CC.Stmt
  choose : CC.Stmt
  first : CC.Stmt
  second : CC.Stmt
  copy : CC.Stmt
  afterSelect : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor 2 do throwError "original memory-reader source selection changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyReadTag.afterTag)) none) ``CC.Stmt.Ssequence
    let loop ← peel root[0]! ``CC.Stmt.Sloop
    let body ← peel loop[0]! ``CC.Stmt.Ssequence
    let choose ← peel body[0]! ``CC.Stmt.Ssequence
    Lean.Elab.Tactic.closeMainGoal `actual_memory_reader_source_choice
      (← Lean.Meta.mkAppM ``Parts.mk #[root[0]!,loop[0]!,body[0]!,choose[0]!,choose[1]!,body[1]!,root[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memory_reader_choice_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def loop : CC.Stmt := by run_tac cachePart (← `(parts.loop))
private def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
private def choose : CC.Stmt := by run_tac cachePart (← `(parts.choose))
private def first : CC.Stmt := by run_tac cachePart (← `(parts.first))
private def second : CC.Stmt := by run_tac cachePart (← `(parts.second))
private def copy : CC.Stmt := by run_tac cachePart (← `(parts.copy))
def afterSelect : CC.Stmt := by run_tac cachePart (← `(parts.afterSelect))

theorem source : Arm64MemcpyReadTag.afterTag = .Ssequence loop afterSelect := rfl
private theorem loop_source : loop = .Sloop body .Sbreak := rfl
private theorem body_source : body = .Ssequence choose copy := rfl
private theorem choose_source : choose = .Ssequence first second := rfl

def temps (le : CC.TempEnv) : CC.TempEnv :=
  ((le.set Arm64Program._t'18 (.Vint 1)).set Arm64Program.___kprog_a64_md_src (.Vint 0)).set
    Arm64Program.___a64_memory_source (.Vint 0)

private def firstNo : CC.Stmt := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(first)) none))
    unless actual.isAppOfArity ``CC.Stmt.Sifthenelse 3 do throwError "original first selection changed"
    Lean.Elab.Tactic.closeMainGoal `actual_reader_first_no actual.getAppArgs[2]!
private def secondYes : CC.Stmt := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(second)) none))
    unless actual.isAppOfArity ``CC.Stmt.Sifthenelse 3 do throwError "original second selection changed"
    Lean.Elab.Tactic.closeMainGoal `actual_reader_second_yes actual.getAppArgs[1]!

private theorem first_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (hbase : le.get Arm64Program._base = some (.Vlong 1)) :
    CC.doStep world (.State reader first k e le m) = some (CC.E0,.State reader firstNo k e le m) := by
  simp only [first,CC.doStep,CC.doEvalExpr,hbase]
  rfl

private theorem first_assign (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (htag : le.get Arm64Program.___a64_memory_tag = some (.Vint ((4#8).setWidth 32))) :
    CC.doStep world (.State reader firstNo k e le m) =
      some (CC.E0,.State reader .Sskip k e (le.set Arm64Program._t'18 (.Vint 1)) m) := by
  simp only [firstNo,CC.doStep,CC.doEvalExpr,htag]
  rfl

private theorem second_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    CC.doStep world (.State reader second k e (le.set Arm64Program._t'18 (.Vint 1)) m) =
      some (CC.E0,.State reader secondYes k e (le.set Arm64Program._t'18 (.Vint 1)) m) := by
  simp only [second,CC.doStep,CC.doEvalExpr,CC.PTree.gss]
  rfl

private theorem second_assign (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    CC.doStep world (.State reader secondYes k e le m) =
      some (CC.E0,.State reader .Sskip k e (le.set Arm64Program.___kprog_a64_md_src (.Vint 0)) m) := by
  simp only [secondYes,CC.doStep,CC.doEvalExpr]
  rfl

private theorem copy_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    CC.doStep world (.State reader copy k e
      ((le.set Arm64Program._t'18 (.Vint 1)).set Arm64Program.___kprog_a64_md_src (.Vint 0)) m) =
      some (CC.E0,.State reader .Sskip k e (temps le) m) := by
  simp only [copy,CC.doStep,CC.doEvalExpr,CC.PTree.gss]
  rfl

/-- The original base32 test and tag4 test choose the actual stack source,
then execute the original assignment and both loop exits on the same heap. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (hbase : le.get Arm64Program._base = some (.Vlong 1))
    (htag : le.get Arm64Program.___a64_memory_tag = some (.Vint ((4#8).setWidth 32))) :
    InternalRun world 14 (.State reader Arm64MemcpyReadTag.afterTag k e le m)
      (.State reader afterSelect k e (temps le) m) := by
  rw [source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [loop_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [body_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [choose_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (first_step e le m _ hbase)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (first_assign e le m _ htag)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (second_step e le m _)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (second_assign e _ m _)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (copy_step e le m _)) ?_
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
    (.step trivial (CC.doStep_sound _ _ _ _ rfl)
      (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)))

/-- Every other original input follows the three actual source setters. -/
theorem kept (le : CC.TempEnv) (key : CC.Ident)
    (sourceOther : Arm64Program.___a64_memory_source ≠ key)
    (selectorOther : Arm64Program.___kprog_a64_md_src ≠ key)
    (conditionOther : Arm64Program._t'18 ≠ key) :
    (temps le).get key = le.get key := by
  simp only [temps,CC.PTree.gso _ _ _ _ sourceOther,CC.PTree.gso _ _ _ _ selectorOther,
    CC.PTree.gso _ _ _ _ conditionOther]

theorem output (le : CC.TempEnv) :
    (temps le).get Arm64Program.___a64_memory_source = some (.Vint 0) := CC.PTree.gss _ _ _

end KProgFormal.ClightRefinement.Arm64MemcpyReadSelect
