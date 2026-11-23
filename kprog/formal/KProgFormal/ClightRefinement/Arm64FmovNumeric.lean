import KProgFormal.ClightRefinement.Arm64FmovReadOperands

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Fmov.Numeric

private structure Pieces where
  init : CC.Stmt
  choose : CC.Stmt
  copy : CC.Stmt

private def pieces : Pieces := by
  run_tac do
    let peel (term : Lean.Expr) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "actual FMOV numeric sequence changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(ReadEntry.tail)) none)
    let rest ← peel root[1]!
    Lean.Elab.Tactic.closeMainGoal `actual_fmov_numeric (← Lean.Meta.mkAppM ``Pieces.mk #[root[0]!,rest[0]!,rest[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_fmov_numeric_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def init : CC.Stmt := by run_tac cachePart (← `(pieces.init))
private def choose : CC.Stmt := by run_tac cachePart (← `(pieces.choose))
private def copy : CC.Stmt := by run_tac cachePart (← `(pieces.copy))

theorem source : ReadEntry.tail = .Ssequence init (.Ssequence choose copy) := rfl

private def labels : CC.LStmts := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(choose)) none))
    unless actual.isAppOfArity ``CC.Stmt.Sswitch 2 do throwError "actual FMOV numeric switch changed"
    Lean.Elab.Tactic.closeMainGoal `actual_fmov_numeric_labels actual.getAppArgs[1]!
private def selected : CC.Stmt := by
  run_tac do
    let term ← Lean.Meta.mkAppM ``CC.selectSwitch #[(← Lean.Elab.Term.elabTerm (← `((0 : Int))) none),
      (← Lean.Elab.Term.elabTerm (← `(labels)) none)]
    let term ← Lean.Meta.mkAppM ``CC.seqOfLabeledStatement #[term]
    Lean.Elab.Tactic.closeMainGoal `actual_fmov_selected (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private theorem choose_source : choose = .Sswitch (.Etempvar Arm64Program.___kprog_a64_fmov_dir CC.tulong) labels := rfl
private theorem chosen_source : CC.seqOfLabeledStatement (CC.selectSwitch 0 labels) = selected := rfl
private def srcSet : CC.Stmt := .Sset Arm64Program.___kprog_a64_fmov_result
  (.Etempvar Arm64Program.___kprog_a64_fmov_src CC.tulong)
private theorem case_source : Arm64Program.s_kprog_arm64_program_execute_3545 = .Ssequence srcSet .Sbreak := rfl

private theorem choose_step (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (dir : le.get Arm64Program.___kprog_a64_fmov_dir = some (.Vlong 0)) :
    CC.Step2 world (.State Arm64Nop.handler choose k e le m) CC.E0
      (.State Arm64Nop.handler selected (.Kswitch k) e le m) := by
  apply CC.doStep_sound
  simp only [choose_source,CC.doStep,CC.doEvalExpr,dir,CC.Cop.semSwitchArg,
    CC.Cop.classifySwitch,CC.typeof,CC.tulong,CC.Integers.Int64.unsigned,CC.Integers.MI.unsigned,chosen_source]
  rfl

private theorem src_step (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (value : BitVec 64)
    (src : le.get Arm64Program.___kprog_a64_fmov_src = some (.Vlong value)) :
    CC.Step2 world (.State Arm64Nop.handler srcSet k e le m) CC.E0
      (.State Arm64Nop.handler .Sskip k e (le.set Arm64Program.___kprog_a64_fmov_result (.Vlong value)) m) := by
  apply CC.doStep_sound
  simp only [srcSet,CC.doStep,CC.doEvalExpr,src,CC.typeof,CC.Cop.semCast,
    CC.Cop.classifyCast,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong]

def retained : List CC.Ident :=
  [Arm64Program._entry,Arm64Program._dst,Arm64Program._src,Arm64Program._src2,
   Arm64Program._src3,Arm64Program._flags,Arm64Program._aux,Arm64Program._op,
   Arm64Program._imm,Arm64Program.___a64_l_width,Arm64Program.___a64_fmov_index,
   Arm64Program.___kprog_a64_fmov_dir,Arm64Program.___kprog_a64_fmov_src,Arm64Program.___kprog_a64_fmov_v0]
private theorem outside0 : Arm64Program.___kprog_a64_fmov_result ∉ retained := by decide +kernel
private theorem outside1 : Arm64Program.___a64_fmov_result ∉ retained := by decide +kernel
private theorem get_kept (key id : CC.Ident) (value : CC.Val) (le : CC.TempEnv)
    (outside : key ∉ retained) (inside : id ∈ retained) : (le.set key value).get id = le.get id := by
  apply CC.PTree.gso
  intro same
  exact outside (same.symm ▸ inside)
private def finalTemps (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv :=
  ((le.set Arm64Program.___kprog_a64_fmov_result (.Vlong 0)).set
    Arm64Program.___kprog_a64_fmov_result (.Vlong value)).set Arm64Program.___a64_fmov_result (.Vlong value)

set_option hygiene false in
/-- Original D_FROM_X init, switch case0, result copy and inner-loop exit
reach the real destination-call site with all ABI/index/direction inputs kept. -/
theorem execute (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (value : BitVec 64)
    (dir : le.get Arm64Program.___kprog_a64_fmov_dir = some (.Vlong 0))
    (src : le.get Arm64Program.___kprog_a64_fmov_src = some (.Vlong value)) :
    ∃ count le', InternalRun world count
      (.State Arm64Nop.handler ReadEntry.tail (ReadEntry.innerCont k) e le m)
      (.State Arm64Nop.handler DestinationSite.site k e le' m) ∧
      le'.get Arm64Program.___a64_fmov_result = some (.Vlong value) ∧
      ∀ id ∈ retained, le'.get id = le.get id := by
  rw [source]
  refine ⟨?count,?temps,?execution,?result,?kept⟩
  case execution => run_tac Lean.Meta.withAssignableSyntheticOpaque do
    let mut finished := false
    for i in [:80] do
      let goal ← Lean.Elab.Tactic.getMainTarget
      let state ← Lean.instantiateMVars goal.getAppArgs[2]!
      if state.isAppOfArity ``CC.State.State 6 && state.getAppArgs[1]!.isConstOf ``DestinationSite.site then
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))
        Lean.logInfo m!"actual FMOV numeric transitions: {i}"
        finished := true
        break
      if state.isAppOfArity ``CC.State.State 6 && state.getAppArgs[1]!.isConstOf ``choose then
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply choose_step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]; exact dir))
        continue
      if state.isAppOfArity ``CC.State.State 6 && state.getAppArgs[1]!.isConstOf ``srcSet then
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply src_step (value := value)))
        Lean.Elab.Tactic.evalTactic (← `(tactic| rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]; exact src))
        continue
      if state.isAppOfArity ``CC.State.State 6 then
        if state.getAppArgs[1]!.isConstOf ``Arm64Program.s_kprog_arm64_program_execute_3545 then
          Lean.Elab.Tactic.evalTactic (← `(tactic| rw [case_source]))
        else if let .const name _ := state.getAppArgs[1]! then
          if let .defnInfo _ ← Lean.getConstInfo name then
            let alias := Lean.mkIdent name
            Lean.Elab.Tactic.evalTactic (← `(tactic| unfold $alias:ident))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep,source,init,copy,ReadEntry.innerCont,
        CC.PTree.gss,CC.doEvalExpr,CC.typeof,CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntLong,
        CC.typeconv,CC.removeAttributes,CC.tattr,CC.tint,CC.tulong,CC.Integers.Int64.repr,
        CC.Integers.Int.signed,CC.Integers.MI.signed,CC.Integers.MI.repr,
        CC.E0,CC.Eapp,List.nil_append,List.append_nil] <;> try rfl))
    unless finished do throwError "FMOV numeric path continues before destination site"
  case result => exact CC.PTree.gss _ _ _
  case kept =>
    intro id inside
    change (finalTemps le value).get id = le.get id
    unfold finalTemps
    rw [get_kept _ id _ _ outside1 inside,get_kept _ id _ _ outside0 inside,get_kept _ id _ _ outside0 inside]

end KProgFormal.ClightRefinement.Arm64Fmov.Numeric
