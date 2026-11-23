import KProgFormal.ClightRefinement.Arm64ProgramEntryLinked
import KProgFormal.ClightRefinement.InternalExecution

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Fmov.Destination

abbrev handler := Arm64Numeric.f_kprog_arm64_fmov_dest

def arguments (mode : Fin 4) : List CC.Val := [.Vlong (BitVec.ofNat 64 mode.val)]
def result (mode : Fin 4) : CC.Val := .Vlong (if mode.val = 0 ∨ mode.val = 2 then 1 else 0)

private theorem mode_cases : ∀ mode : Fin 4, mode = 0 ∨ mode = 1 ∨ mode = 2 ∨ mode = 3 := by decide +kernel

private def choose : CC.Stmt := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "actual FMOV destination sequence changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(handler.fn_body)) none) ``CC.Stmt.Ssequence 2
    let loop ← peel root[0]! ``CC.Stmt.Sloop 2
    let first ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let second ← peel first[1]! ``CC.Stmt.Ssequence 2
    let third ← peel second[1]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_fmov_dest_switch third[0]!

private def labels : CC.LStmts := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(choose)) none))
    unless actual.isAppOfArity ``CC.Stmt.Sswitch 2 do throwError "actual FMOV destination switch changed"
    Lean.Elab.Tactic.closeMainGoal `actual_fmov_dest_labels actual.getAppArgs[1]!

private theorem choose_source : choose = .Sswitch
    (.Etempvar Arm64Numeric.___kprog_a64_fmd_dir CC.tulong) labels := rfl

private theorem choose_step (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (bits : BitVec 64)
    (observed : le.get Arm64Numeric.___kprog_a64_fmd_dir = some (.Vlong bits)) :
    CC.Step2 world (.State handler choose k e le m) CC.E0
      (.State handler (CC.seqOfLabeledStatement (CC.selectSwitch (CC.Integers.Int64.unsigned bits) labels))
        (.Kswitch k) e le m) := by
  apply CC.doStep_sound
  simp only [choose_source,CC.doStep,CC.doEvalExpr,observed,CC.Cop.semSwitchArg,
    CC.Cop.classifySwitch,CC.tulong,CC.typeof]

set_option hygiene false in
/-- Every actual legal direction executes the exported destination helper,
with its original call continuation and unchanged entire heap. -/
theorem execute (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont) (mode : Fin 4) :
    ∃ count, InternalRun world count (.Callstate (.Internal handler) (arguments mode) k m)
      (.Returnstate (result mode) (CC.callCont k) m) := by
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  rcases mode_cases mode with rfl|rfl|rfl|rfl
  all_goals
    refine ⟨?_,?_⟩
    rotate_left
    run_tac Lean.Meta.withAssignableSyntheticOpaque do
      let mut finished := false
      for i in [:100] do
        let goal ← Lean.Elab.Tactic.getMainTarget
        let state ← Lean.instantiateMVars goal.getAppArgs[2]!
        if state.isAppOfArity ``CC.State.Returnstate 3 then
          Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))
          Lean.logInfo m!"actual FMOV destination helper transitions: {i}"
          finished := true
          break
        if state.isAppOfArity ``CC.State.State 6 then
          let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf state.getAppArgs[1]!)
          if stmt.isAppOfArity ``CC.Stmt.Sswitch 2 then
            Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
            Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
            Lean.Elab.Tactic.evalTactic (← `(tactic| apply choose_step))
            Lean.Elab.Tactic.evalTactic (← `(tactic| rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]; exact CC.PTree.gss _ _ _))
            continue
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [
          Fin.val_ofNat,CC.doStep,CC.doFunctionEntry2,handler,Arm64Numeric.f_kprog_arm64_fmov_dest,arguments,result,
          CC.listNorepet,CC.varNames,CC.listDisjoint,CC.doAllocVariables,CC.bindParameterTemps,
          CC.createUndefTemps,CC.PTree.gss,CC.PTree.gso,CC.doEvalExpr,CC.typeof,
          CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.castIntLong,
          CC.Cop.semSwitchArg,CC.Cop.classifySwitch,CC.typeconv,CC.removeAttributes,
          CC.tattr,CC.tuint,CC.tint,CC.tulong,CC.Integers.Int.repr,CC.Integers.MI.repr,
          CC.Integers.Int64.unsigned,CC.Integers.MI.unsigned,CC.Integers.Int64.repr,
          CC.blocksOfEnv,CC.emptyEnv,empty,CC.Mem.freeList,
          CC.E0,CC.Eapp,List.nil_append,List.append_nil,ite_true,ite_false] <;> try rfl))
      unless finished do throwError "FMOV destination helper continues before its original return"

/-- The original D_FROM_X direction selects the vector destination. -/
theorem d_from_x (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont) :
    ∃ count, InternalRun world count (.Callstate (.Internal handler) [.Vlong 0] k m)
      (.Returnstate (.Vlong 1) (CC.callCont k) m) := by
  exact execute world m k 0

end KProgFormal.ClightRefinement.Arm64Fmov.Destination
