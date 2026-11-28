import KProgFormal.ClightRefinement.Arm64CiliumCallerSPAlignment

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerSPPreindex
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerEntryScalars (Locals chunk value)

private structure Parts where
  setup : CC.Stmt
  branch : CC.Stmt
  condition : CC.Expr
  otherWidth : CC.Stmt
  call : CC.Stmt

private noncomputable def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless node.isAppOfArity ctor arity do throwError "actual SP preindex prefix changed"
      pure node.getAppArgs
    let original ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerSPAlignment.tail)) none
    let loop ← peel original ``CC.Stmt.Sloop 2
    let body ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let setup ← peel body[0]! ``CC.Stmt.Ssequence 2
    let choose ← peel setup[0]! ``CC.Stmt.Sifthenelse 3
    let nonzero ← peel body[1]! ``CC.Stmt.Sifthenelse 3
    let width ← peel nonzero[1]! ``CC.Stmt.Sifthenelse 3
    let write ← peel width[1]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_sp_preindex
      (← Lean.Meta.mkAppM ``Parts.mk #[body[0]!,body[1]!,choose[0]!,width[2]!,write[1]!])

noncomputable def setup : CC.Stmt := parts.setup
noncomputable def branch : CC.Stmt := parts.branch
noncomputable def condition : CC.Expr := parts.condition
noncomputable def otherWidth : CC.Stmt := parts.otherWidth
noncomputable def call : CC.Stmt := parts.call
noncomputable def body : CC.Stmt := .Ssequence setup branch
def delta : BitVec 64 := CC.Integers.Int64.repr (-32)

theorem source : Arm64CiliumCallerSPAlignment.tail = .Sloop body .Sbreak := rfl
theorem setup_source : setup = .Ssequence
    (.Sifthenelse condition
      (.Sset _t'137 (.Ecast (.Econst_long delta CC.tulong) CC.tulong))
      (.Sset _t'137 (.Ecast (.Econst_int (0#32) CC.tint) CC.tulong)))
    (.Sset ___a64_l_pp (.Ecast (.Etempvar _t'137 CC.tulong) CC.tlong)) := rfl
theorem branch_source : branch = .Sifthenelse
    (.Ebinop .One (.Etempvar ___a64_l_pp CC.tlong) (.Econst_int (0#32) CC.tint) CC.tint)
    (.Sifthenelse
      (.Ebinop .Oeq (.Econst_int (32#32) CC.tuint) (.Econst_int (32#32) CC.tuint) CC.tint)
      (.Ssequence (.Sset _t'13900 (.Evar ___a64_sp CC.tlong)) call)
      otherWidth)
    .Sskip := rfl

theorem condition_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr ge e le memory condition = some (.Vint (1#32)) := rfl
private theorem condition_type : CC.typeof condition = CC.tuint := rfl
private theorem delta_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr ge e le memory (.Ecast (.Econst_long delta CC.tulong) CC.tulong) =
      some (.Vlong delta) := rfl
private theorem pp_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get _t'137 = some (.Vlong delta)) :
    CC.doEvalExpr ge e le memory (.Ecast (.Etempvar _t'137 CC.tulong) CC.tlong) =
      some (.Vlong delta) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem nonzero_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get ___a64_l_pp = some (.Vlong delta)) :
    CC.doEvalExpr ge e le memory
      (.Ebinop .One (.Etempvar ___a64_l_pp CC.tlong) (.Econst_int (0#32) CC.tint) CC.tint) =
      some (.Vint (1#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem compare_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr ge e le memory
      (.Ebinop .Oeq (.Econst_int (32#32) CC.tuint) (.Econst_int (32#32) CC.tuint) CC.tint) =
      some (.Vint (1#32)) := rfl
private theorem branch_type :
    CC.typeof (.Ebinop .One (.Etempvar ___a64_l_pp CC.tlong) (.Econst_int (0#32) CC.tint) CC.tint) =
      CC.tint := rfl
private theorem compare_type :
    CC.typeof (.Ebinop .Oeq (.Econst_int (32#32) CC.tuint) (.Econst_int (32#32) CC.tuint) CC.tint) =
      CC.tint := rfl
private theorem bool_one (memory : CC.Mem) :
    CC.Cop.boolVal (.Vint (1#32)) CC.tint memory = some true ∧
    CC.Cop.boolVal (.Vint (1#32)) CC.tuint memory = some true := ⟨rfl,rfl⟩

noncomputable def resultEnv (le : CC.TempEnv) : CC.TempEnv :=
  ((le.set _t'137 (.Vlong delta)).set ___a64_l_pp (.Vlong delta)).set _t'13900 (.Vlong (0#64))

/-- Reach the original pointer writer call with its actual preindex and SP temporaries. -/
theorem execute {m memory : CC.Mem} (scalars : Locals m)
    (reads : ∀ i : Fin 2,CC.Mem.load (chunk i) memory (scalars.block i) 0 = some (value i))
    (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 13 (.State procedure Arm64CiliumCallerSPAlignment.tail k (allocation m).1 le memory)
      (.State procedure call (.Kloop1 body .Sbreak k) (allocation m).1 (resultEnv le) memory) := by
  have currentSP (temps : CC.TempEnv) := Arm64CiliumCallerSPAlignment.sp_value scalars reads temps
  apply internalRun_of_steps
  all_goals
    simp only [source,body,setup_source,branch_source,steps,InternalPath,InternalState,CC.doStep,
      condition_value,condition_type,delta_value,pp_value,nonzero_value,compare_value,
      branch_type,compare_type,(bool_one memory).1,(bool_one memory).2,currentSP,
      CC.PTree.gss,resultEnv,ite_true,ite_false,Bool.false_eq_true,true_and,and_true,
      CC.E0,CC.Eapp,List.nil_append]

end KProgFormal.ClightRefinement.Arm64CiliumCallerSPPreindex
