import KProgFormal.ClightRefinement.Arm64CiliumCallerWidthEntry

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerOperandGuard
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge)

private structure Parts where
  guard : CC.Stmt
  after : CC.Stmt
  condition : CC.Expr

private noncomputable def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless node.isAppOfArity ctor arity do throwError "actual initial operand guard changed"
      pure node.getAppArgs
    let original ← Lean.Elab.Term.elabTerm (← `(s_trusted_arm64_arm64_sim_xdp_150)) none
    let outer ← peel original ``CC.Stmt.Ssequence 2
    let loop ← peel outer[0]! ``CC.Stmt.Sloop 2
    let sequence ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let inner ← peel sequence[0]! ``CC.Stmt.Ssequence 2
    let first ← peel inner[0]! ``CC.Stmt.Sifthenelse 3
    Lean.Elab.Tactic.closeMainGoal `actual_operand_guard
      (← Lean.Meta.mkAppM ``Parts.mk #[outer[0]!,outer[1]!,first[0]!])

noncomputable def guard : CC.Stmt := parts.guard
noncomputable def after : CC.Stmt := parts.after
noncomputable def condition : CC.Expr := parts.condition
noncomputable def unsupported : CC.Stmt := .Sloop
  (.Scall none (.Evar _arm64_sim_unsupported_opcode
    (.Tfunction [] CC.tvoid CC.cc_default)) []) .Sbreak

theorem source : s_trusted_arm64_arm64_sim_xdp_150 = .Ssequence guard after := rfl
theorem guard_source : guard = .Sloop
    (.Ssequence
      (.Ssequence
        (.Sifthenelse condition
          (.Sset _t'134 (.Ecast
            (.Ebinop .One (.Econst_int (32#32) CC.tuint) (.Econst_int (32#32) CC.tuint) CC.tint) CC.tbool))
          (.Sset _t'134 (.Econst_int (0#32) CC.tint)))
        (.Sifthenelse (.Etempvar _t'134 CC.tint)
          (.Sset _t'135 (.Ecast
            (.Ebinop .Oeq (.Econst_int (32#32) CC.tuint) (.Econst_int (30#32) CC.tuint) CC.tint) CC.tbool))
          (.Sset _t'135 (.Econst_int (0#32) CC.tint))))
      (.Sifthenelse (.Etempvar _t'135 CC.tint) unsupported .Sskip)) .Sbreak := rfl

private theorem condition_type : CC.typeof condition = CC.tuint := rfl
private theorem temp_type (id : CC.Ident) (ty : CC.Ty) :
    CC.typeof (.Etempvar id ty) = ty := rfl

theorem condition_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr ge e le memory condition = some (.Vint (1#32)) := by rfl

private theorem zero_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr ge e le memory
      (.Ecast (.Ebinop .One (.Econst_int (32#32) CC.tuint)
        (.Econst_int (32#32) CC.tuint) CC.tint) CC.tbool) = some (.Vint (0#32)) := by rfl

private theorem temp_eval (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (id : CC.Ident) (ty : CC.Ty) :
    CC.doEvalExpr ge e le memory (.Etempvar id ty) = le.get id := rfl
private theorem literal_zero (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr ge e le memory (.Econst_int (0#32) CC.tint) = some (.Vint (0#32)) := rfl
private theorem bool_one (memory : CC.Mem) :
    CC.Cop.boolVal (.Vint (1#32)) CC.tuint memory = some true := rfl
private theorem bool_zero (memory : CC.Mem) :
    CC.Cop.boolVal (.Vint (0#32)) CC.tint memory = some false := rfl

noncomputable def resultEnv (le : CC.TempEnv) : CC.TempEnv :=
  (le.set _t'134 (.Vint (0#32))).set _t'135 (.Vint (0#32))

/-- Actual constant operand checks bypass the unsupported call, preserving the entire heap. -/
theorem guard_execute (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (k : CC.Cont) :
    InternalRun ge 12 (.State procedure guard k e le memory)
      (.State procedure .Sskip k e (resultEnv le) memory) := by
  apply internalRun_of_steps
  all_goals
    simp only [guard_source,steps,InternalPath,InternalState,CC.doStep,
      condition_value,zero_value,temp_eval,literal_zero,
      condition_type,temp_type,bool_one,bool_zero,CC.PTree.gss,resultEnv,
      ite_true,ite_false,Bool.false_eq_true,true_and,and_true,CC.E0,CC.Eapp,List.nil_append]

/-- Enter the real inner loop, execute its first guard, and reach the original SP check. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (k : CC.Cont) :
    InternalRun ge 15 (.State procedure Arm64CiliumCallerWidthPrefix.next k e le memory)
      (.State procedure after
        (.Kloop1 s_trusted_arm64_arm64_sim_xdp_150 s_trusted_arm64_arm64_sim_xdp_151 k)
        e (resultEnv le) memory) := by
  let rest := CC.Cont.Kloop1 s_trusted_arm64_arm64_sim_xdp_150 s_trusted_arm64_arm64_sim_xdp_151 k
  have leave : InternalRun ge 1
      (.State procedure .Sskip (.Kseq after rest) e (resultEnv le) memory)
      (.State procedure after rest e (resultEnv le) memory) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  have run := (guard_execute e le memory (.Kseq after rest)).trans leave
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
    (.step trivial (CC.doStep_sound _ _ _ _ rfl) run)

end KProgFormal.ClightRefinement.Arm64CiliumCallerOperandGuard
