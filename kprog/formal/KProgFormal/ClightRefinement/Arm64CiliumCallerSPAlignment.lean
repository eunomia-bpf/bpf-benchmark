import KProgFormal.ClightRefinement.Arm64CiliumCallerOperandGuard

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerSPAlignment
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerEntryScalars (Locals chunk value)

private structure Parts where
  alignment : CC.Stmt
  tail : CC.Stmt
  afterGroup : CC.Stmt

private noncomputable def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless node.isAppOfArity ctor arity do throwError "actual SP alignment prefix changed"
      pure node.getAppArgs
    let original ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerOperandGuard.after)) none
    let sequence ← peel original ``CC.Stmt.Ssequence 2
    let loop ← peel sequence[0]! ``CC.Stmt.Sloop 2
    let body ← peel loop[0]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_sp_alignment
      (← Lean.Meta.mkAppM ``Parts.mk #[body[0]!,body[1]!,sequence[1]!])

noncomputable def alignment : CC.Stmt := parts.alignment
noncomputable def tail : CC.Stmt := parts.tail
noncomputable def afterGroup : CC.Stmt := parts.afterGroup
noncomputable def body : CC.Stmt := .Ssequence alignment tail
noncomputable def group : CC.Stmt := .Sloop body .Sbreak
noncomputable def mask : CC.Expr := .Ecast
  (.Ebinop .Oand (.Ecast (.Etempvar _t'13901 CC.tlong) CC.tulong)
    (.Econst_int (15#32) CC.tuint) CC.tulong) CC.tbool

theorem source : Arm64CiliumCallerOperandGuard.after = .Ssequence group afterGroup := rfl
theorem alignment_source : alignment = .Sloop
    (.Ssequence
      (.Sifthenelse
        (.Ebinop .Oeq (.Econst_int (32#32) CC.tuint) (.Econst_int (32#32) CC.tuint) CC.tint)
        (.Ssequence (.Sset _t'13901 (.Evar ___a64_sp CC.tlong)) (.Sset _t'136 mask))
        (.Sset _t'136 (.Econst_int (0#32) CC.tint)))
      (.Sifthenelse (.Etempvar _t'136 CC.tint) Arm64CiliumCallerOperandGuard.unsupported .Sskip))
    .Sbreak := rfl

/-- The retained actual SP local binding and readback supply the original source read. -/
theorem sp_value {m memory : CC.Mem} (scalars : Locals m)
    (reads : ∀ i : Fin 2,CC.Mem.load (chunk i) memory (scalars.block i) 0 = some (value i))
    (le : CC.TempEnv) :
    CC.doEvalExpr ge (allocation m).1 le memory (.Evar ___a64_sp CC.tlong) = some (.Vlong (0#64)) := by
  have bound : (allocation m).1.get ___a64_sp = some (scalars.block 0,CC.tlong) := scalars.binding 0
  have read : CC.Mem.load .Mint64 memory (scalars.block 0) 0 = some (.Vlong (0#64)) := reads 0
  simp only [CC.doEvalExpr,CC.lvalOfVar,bound,ite_true]
  change CC.Mem.load .Mint64 memory (scalars.block 0) 0 = some (.Vlong (0#64))
  exact read

noncomputable def resultEnv (le : CC.TempEnv) : CC.TempEnv :=
  (le.set _t'13901 (.Vlong (0#64))).set _t'136 (.Vint (0#32))

private theorem compare_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr ge e le memory
      (.Ebinop .Oeq (.Econst_int (32#32) CC.tuint)
        (.Econst_int (32#32) CC.tuint) CC.tint) = some (.Vint (1#32)) := rfl
private theorem compare_type :
    CC.typeof (.Ebinop .Oeq (.Econst_int (32#32) CC.tuint)
      (.Econst_int (32#32) CC.tuint) CC.tint) = CC.tint := rfl
private theorem temp_type (id : CC.Ident) (ty : CC.Ty) :
    CC.typeof (.Etempvar id ty) = ty := rfl
private theorem temp_eval (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (id : CC.Ident) (ty : CC.Ty) :
    CC.doEvalExpr ge e le memory (.Etempvar id ty) = le.get id := rfl
private theorem bool_one (memory : CC.Mem) :
    CC.Cop.boolVal (.Vint (1#32)) CC.tint memory = some true := rfl
private theorem bool_zero (memory : CC.Mem) :
    CC.Cop.boolVal (.Vint (0#32)) CC.tint memory = some false := rfl
private theorem mask_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get _t'13901 = some (.Vlong (0#64))) :
    CC.doEvalExpr ge e le memory mask = some (.Vint (0#32)) := by
  simp only [mask,CC.doEvalExpr,read,Option.bind_some]
  rfl

/-- Actual zero-SP load and mask bypass the preserved unsupported branch. -/
theorem alignment_execute {m memory : CC.Mem} (scalars : Locals m)
    (reads : ∀ i : Fin 2,CC.Mem.load (chunk i) memory (scalars.block i) 0 = some (value i))
    (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 11 (.State procedure alignment k (allocation m).1 le memory)
      (.State procedure .Sskip k (allocation m).1 (resultEnv le) memory) := by
  have currentSP := sp_value scalars reads le
  apply internalRun_of_steps
  all_goals
    simp only [alignment_source,steps,InternalPath,InternalState,CC.doStep,
      currentSP,compare_value,compare_type,temp_eval,temp_type,mask_value,
      bool_one,bool_zero,CC.PTree.gss,resultEnv,
      ite_true,ite_false,Bool.false_eq_true,true_and,and_true,CC.E0,CC.Eapp,List.nil_append]

/-- Enter the original SP group, execute its alignment guard, and reach its real tail. -/
theorem execute {m memory : CC.Mem} (scalars : Locals m)
    (reads : ∀ i : Fin 2,CC.Mem.load (chunk i) memory (scalars.block i) 0 = some (value i))
    (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 15
      (.State procedure Arm64CiliumCallerOperandGuard.after k (allocation m).1 le memory)
      (.State procedure tail (.Kloop1 body .Sbreak (.Kseq afterGroup k))
        (allocation m).1 (resultEnv le) memory) := by
  let rest := CC.Cont.Kloop1 body .Sbreak (.Kseq afterGroup k)
  have leave : InternalRun ge 1
      (.State procedure .Sskip (.Kseq tail rest) (allocation m).1 (resultEnv le) memory)
      (.State procedure tail rest (allocation m).1 (resultEnv le) memory) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  have run := (alignment_execute scalars reads le (.Kseq tail rest)).trans leave
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
    (.step trivial (CC.doStep_sound _ _ _ _ rfl)
      (.step trivial (CC.doStep_sound _ _ _ _ rfl) run))

end KProgFormal.ClightRefinement.Arm64CiliumCallerSPAlignment
