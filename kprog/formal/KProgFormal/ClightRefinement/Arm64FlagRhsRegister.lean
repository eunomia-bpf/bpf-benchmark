import KProgFormal.ClightRefinement.Arm64ProgramEntryLinked
import KProgFormal.ClightRefinement.InternalExecution

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64FlagRhsRegister
abbrev handler := Arm64Numeric.f_kprog_arm64_flag_rhs
private def body : CC.Stmt := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm (← `(handler.fn_body)) none
    Lean.Elab.Tactic.closeMainGoal `actual_flag_rhs_register_body (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private theorem body_source : handler.fn_body = body := rfl
private theorem return_type : handler.fn_return = CC.tulong := rfl
private theorem empty_elements : (CC.PTree.empty : CC.Env).elements = [] := rfl

def arguments (value : BitVec 64) : List CC.Val := [.Vlong 23,.Vlong 0,.Vlong value]
def temps (value : BitVec 64) : CC.TempEnv :=
  (((CC.createUndefTemps handler.fn_temps).set Arm64Numeric._op (.Vlong 23)).set
    Arm64Numeric._imm (.Vlong 0)).set Arm64Numeric._reg (.Vlong value)

theorem enter (world : CC.CGenv) (value : BitVec 64) (k : CC.Cont) (m : CC.Mem) :
    InternalRun world 1 (.Callstate (.Internal handler) (arguments value) k m)
      (.State handler body k CC.emptyEnv (temps value) m) := by
  have entry : CC.FunctionEntry2 world handler (arguments value) m CC.emptyEnv (temps value) m :=
    .intro (by decide +kernel) (by decide +kernel) (by decide +kernel) (.nil _ _) rfl
  rw [←body_source]
  exact .step trivial (.internal_function _ _ _ _ _ _ _ entry) (.refl _)

set_option hygiene false in
/-- Complete original Numeric op23 takes its actual register-RHS default and
returns the original arbitrary 64-bit operand with the identical whole heap. -/
theorem execute (world : CC.CGenv) (value : BitVec 64) (k : CC.Cont) (m : CC.Mem) :
    ∃ count, InternalRun world count (.Callstate (.Internal handler) (arguments value) k m)
      (.Returnstate (.Vlong value) (CC.callCont k) m) := by
  suffices rest : ∃ count, InternalRun world count (.State handler body k CC.emptyEnv (temps value) m)
      (.Returnstate (.Vlong value) (CC.callCont k) m) by
    obtain ⟨count,run⟩ := rest
    exact ⟨_,(enter world value k m).trans run⟩
  refine ⟨?count,?execution⟩
  case execution => run_tac Lean.Meta.withAssignableSyntheticOpaque do
    let mut finished := false
    for i in [:48] do
      let goal ← Lean.Elab.Tactic.getMainTarget
      let state ← Lean.instantiateMVars goal.getAppArgs[2]!
      if state.isAppOfArity ``CC.State.Returnstate 3 then
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))
        Lean.logInfo m!"actual flag_rhs op23 transitions including entry: {i+1}"
        finished := true
        break
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [body,CC.doStep,CC.doEvalExpr,CC.typeof,
        temps,CC.PTree.gss,CC.PTree.gso,CC.Cop.semSwitchArg,CC.Cop.classifySwitch,
        CC.selectSwitch,CC.seqOfLabeledStatement,CC.Cop.semCast,CC.Cop.classifyCast,
        CC.tulong,CC.Archi.ptr64,CC.blocksOfEnv,CC.emptyEnv,CC.Mem.freeList,empty_elements,return_type,
        ite_true,ite_false,eq_self,CC.E0,CC.Eapp,List.nil_append,List.append_nil] <;> try rfl))
    unless finished do throwError "original flag_rhs op23 has further transitions"
end KProgFormal.ClightRefinement.Arm64FlagRhsRegister
