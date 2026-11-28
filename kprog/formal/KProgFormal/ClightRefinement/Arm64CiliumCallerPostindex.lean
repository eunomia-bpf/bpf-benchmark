import KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterOutcomes

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerPostindex
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure)
open Arm64CiliumCallerLinkedProgram (ge)

private structure Parts where
  condition : CC.Expr
  update : CC.Stmt

private noncomputable def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless node.isAppOfArity ctor arity do throwError "actual caller postindex changed"
      pure node.getAppArgs
    let original ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerMemoryWriterPrefix.rest)) none
    let loop ← peel original ``CC.Stmt.Sloop 2
    let body ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let setup ← peel body[0]! ``CC.Stmt.Ssequence 2
    let choice ← peel setup[0]! ``CC.Stmt.Sifthenelse 3
    let guard ← peel body[1]! ``CC.Stmt.Sifthenelse 3
    Lean.Elab.Tactic.closeMainGoal `actual_postindex
      (← Lean.Meta.mkAppM ``Parts.mk #[choice[0]!,guard[1]!])

noncomputable def condition : CC.Expr := parts.condition
noncomputable def body : CC.Stmt := .Ssequence
  (.Ssequence
    (.Sifthenelse condition
      (.Sset _t'210 (.Ecast (.Econst_long (CC.Integers.Int64.repr (-32)) CC.tulong) CC.tulong))
      (.Sset _t'210 (.Ecast (.Econst_int (0#32) CC.tint) CC.tulong)))
    (.Sset ___a64_l_pp__1 (.Ecast (.Etempvar _t'210 CC.tulong) CC.tlong)))
  (.Sifthenelse (.Ebinop .One (.Etempvar ___a64_l_pp__1 CC.tlong)
      (.Econst_int (0#32) CC.tint) CC.tint) parts.update .Sskip)

theorem source : Arm64CiliumCallerMemoryWriterPrefix.rest = .Sloop body .Sbreak := rfl

theorem condition_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr ge e le memory condition = some (.Vint (0#32)) := rfl

private theorem condition_type : CC.typeof condition = CC.tuint := rfl
private theorem zero_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr ge e le memory (.Ecast (.Econst_int (0#32) CC.tint) CC.tulong) =
      some (.Vlong (0#64)) := rfl
private theorem pp_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get _t'210 = some (.Vlong (0#64))) :
    CC.doEvalExpr ge e le memory (.Ecast (.Etempvar _t'210 CC.tulong) CC.tlong) =
      some (.Vlong (0#64)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem nonzero_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get ___a64_l_pp__1 = some (.Vlong (0#64))) :
    CC.doEvalExpr ge e le memory
      (.Ebinop .One (.Etempvar ___a64_l_pp__1 CC.tlong) (.Econst_int (0#32) CC.tint) CC.tint) =
      some (.Vint (0#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem nonzero_type : CC.typeof
    (.Ebinop .One (.Etempvar ___a64_l_pp__1 CC.tlong) (.Econst_int (0#32) CC.tint) CC.tint) = CC.tint := rfl
private theorem bool_zero (ty : CC.Ty) (memory : CC.Mem)
    (kind : ty = CC.tint ∨ ty = CC.tuint) :
    CC.Cop.boolVal (.Vint (0#32)) ty memory = some false := by
  rcases kind with rfl | rfl <;> rfl

noncomputable def resultEnv (le : CC.TempEnv) : CC.TempEnv :=
  (le.set _t'210 (.Vlong (0#64))).set ___a64_l_pp__1 (.Vlong (0#64))

/-- The actual encoded addressing flags select preindex, so the original
postindex computes zero and skips both preserved writer-call branches. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (k : CC.Cont) :
    InternalRun ge 11 (.State procedure Arm64CiliumCallerMemoryWriterPrefix.rest k e le memory)
      (.State procedure .Sskip k e (resultEnv le) memory) := by
  apply internalRun_of_steps
  all_goals
    simp only [source,body,steps,InternalPath,InternalState,CC.doStep,
      condition_value,condition_type,zero_value,pp_value,nonzero_value,nonzero_type,
      bool_zero CC.tuint memory (Or.inr rfl),bool_zero CC.tint memory (Or.inl rfl),
      resultEnv,CC.PTree.gss,ite_false,Bool.false_eq_true,eq_self,and_true,
      CC.E0,CC.Eapp,List.nil_append] <;> trivial

theorem temp_frame (le : CC.TempEnv) (id : CC.Ident)
    (first : id ≠ _t'210) (second : id ≠ ___a64_l_pp__1) :
    (resultEnv le).get id = le.get id := by
  unfold resultEnv
  rw [CC.PTree.gso ___a64_l_pp__1 id _ _ (Ne.symm second),CC.PTree.gso _t'210 id _ _ (Ne.symm first)]

end KProgFormal.ClightRefinement.Arm64CiliumCallerPostindex
