import KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterPrefix

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterGuard
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure allocation)
open Arm64CiliumCallerLinkedProgram (ge)
open Arm64CiliumCallerDefaults (Locals)
open Arm64CiliumCallerTables (Table)
open Arm64CiliumCallerInitializers (Cells)
open Arm64CiliumCallerHeaderTailValues (Storage)

private structure Parts where
  guard : CC.Stmt
  branch : CC.Stmt
  xdp : CC.Stmt
  sp : CC.Stmt
  pointer : CC.Stmt

private noncomputable def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless node.isAppOfArity ctor arity do throwError "actual original memory writer guard changed"
      pure node.getAppArgs
    let original ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerMemoryWriterPrefix.after)) none
    let outer ← peel original ``CC.Stmt.Ssequence 2
    let choose ← peel outer[1]! ``CC.Stmt.Sifthenelse 3
    let arm ← peel choose[2]! ``CC.Stmt.Sifthenelse 3
    Lean.Elab.Tactic.closeMainGoal `actual_memory_writer_guard
      (← Lean.Meta.mkAppM ``Parts.mk #[outer[0]!,outer[1]!,choose[1]!,arm[1]!,arm[2]!])

noncomputable def stage : CC.Stmt := Arm64CiliumCallerMemoryWriterPrefix.after
noncomputable def guard : CC.Stmt := parts.guard
noncomputable def branch : CC.Stmt := parts.branch
noncomputable def after : CC.Stmt := parts.sp

theorem source : stage = .Ssequence guard branch := rfl
theorem guard_source : guard = .Ssequence
    (.Sset _t'13876 (.Evar ___a64_sim_abi_kind CC.tuchar))
    (.Sifthenelse (.Ebinop .Oeq (.Etempvar _t'13876 CC.tuchar)
        (.Econst_int (CC.Integers.Int.repr 1) CC.tuint) CC.tint)
      (.Sset _t'209 (.Ecast (.Ebinop .Oeq (.Etempvar ___a64_mwr_tag CC.tuchar)
        (.Econst_int (CC.Integers.Int.repr 1) CC.tuint) CC.tint) CC.tbool))
      (.Sset _t'209 (.Econst_int (CC.Integers.Int.repr 0) CC.tint))) := rfl
theorem branch_source : branch = .Sifthenelse (.Etempvar _t'209 CC.tint) parts.xdp
    (.Sifthenelse (.Ebinop .Oeq (.Etempvar ___a64_mwr_arm CC.tuchar)
      (.Econst_int (CC.Integers.Int.repr 0) CC.tuint) CC.tint) after parts.pointer) := rfl

theorem sp_source : after = .Ssequence
    (.Ssequence
      (.Sifthenelse (.Ebinop .Oeq (.Econst_int (CC.Integers.Int.repr 32) CC.tuint)
        (.Econst_int (CC.Integers.Int.repr 32) CC.tuint) CC.tint)
        s_trusted_arm64_arm64_sim_xdp_67 s_trusted_arm64_arm64_sim_xdp_68)
      (.Sset ___a64_mwr_bsrc (.Ecast (.Ecast (.Etempvar _t'167 CC.tuint) CC.tuchar) CC.tuchar)))
    (.Ssequence (.Sset ___a64_mwr_base (.Evar ___a64_sp CC.tlong))
      (.Ssequence s_trusted_arm64_arm64_sim_xdp_69
        (.Sloop s_trusted_arm64_arm64_sim_xdp_141 s_trusted_arm64_arm64_sim_xdp_142))) := rfl

/-- The real ABI byte is an explicit post-provider resource. The actual cache
assignments preserve its allocated block; external-call purity is not assumed. -/
theorem resources {m supplied : CC.Mem} {locals : Locals m} {base : BitVec 64}
    (result : Arm64CiliumCallerReturnMemory.Store (supplied := supplied) locals base)
    (header : Storage m) :
    CC.Mem.load .Mint8unsigned result.after (header.block 6) 0 =
      CC.Mem.load .Mint8unsigned supplied (header.block 6) 0 :=
  Arm64CiliumCallerReturnMemory.bound_frame result (header.binding 6)
    (by decide +kernel) (by decide +kernel) .Mint8unsigned 0

theorem abi_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (block : CC.Block)
    (binding : e.get ___a64_sim_abi_kind = some (block,CC.tuchar))
    (read : CC.Mem.load .Mint8unsigned memory block 0 = some (.Vint (1#32))) :
    CC.doEvalExpr ge e le memory (.Evar ___a64_sim_abi_kind CC.tuchar) = some (.Vint (1#32)) := by
  simp only [CC.doEvalExpr,CC.lvalOfVar,binding,ite_true]
  change CC.Mem.load .Mint8unsigned memory block 0 = _
  exact read

private theorem abi_eq (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get _t'13876 = some (.Vint (1#32))) :
    CC.doEvalExpr ge e le memory (.Ebinop .Oeq (.Etempvar _t'13876 CC.tuchar)
      (.Econst_int (CC.Integers.Int.repr 1) CC.tuint) CC.tint) = some (.Vint (1#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem tag_false (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get ___a64_mwr_tag = some (.Vint (4#32))) :
    CC.doEvalExpr ge e le memory (.Ecast (.Ebinop .Oeq (.Etempvar ___a64_mwr_tag CC.tuchar)
      (.Econst_int (CC.Integers.Int.repr 1) CC.tuint) CC.tint) CC.tbool) = some (.Vint (0#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem arm_true (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get ___a64_mwr_arm = some (.Vint (0#32))) :
    CC.doEvalExpr ge e le memory (.Ebinop .Oeq (.Etempvar ___a64_mwr_arm CC.tuchar)
      (.Econst_int (CC.Integers.Int.repr 0) CC.tuint) CC.tint) = some (.Vint (1#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem temp_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (id : CC.Ident) (ty : CC.Ty) :
    CC.doEvalExpr ge e le memory (.Etempvar id ty) = le.get id := rfl
private theorem binop_type (op : CC.Binop) (a b : CC.Expr) (ty : CC.Ty) :
    CC.typeof (.Ebinop op a b ty) = ty := rfl
private theorem temp_type (id : CC.Ident) (ty : CC.Ty) :
    CC.typeof (.Etempvar id ty) = ty := rfl
private theorem bool_true (memory : CC.Mem) :
    CC.Cop.boolVal (.Vint (1#32)) CC.tint memory = some true := rfl
private theorem bool_false (memory : CC.Mem) :
    CC.Cop.boolVal (.Vint (0#32)) CC.tint memory = some false := rfl

noncomputable def resultEnv (le : CC.TempEnv) : CC.TempEnv :=
  CC.PTree.set _t'209 (CC.Val.Vint (0#32)) (CC.PTree.set _t'13876 (CC.Val.Vint (1#32)) le)

/-- Nine original steps read ABI1, reject tag4 as XDP tag1, and select arm0's
original SP-based branch. The complete heap and both unselected branches remain. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (block : CC.Block)
    (binding : e.get ___a64_sim_abi_kind = some (block,CC.tuchar))
    (read : CC.Mem.load .Mint8unsigned memory block 0 = some (.Vint (1#32)))
    (tag : le.get ___a64_mwr_tag = some (.Vint (4#32)))
    (arm : le.get ___a64_mwr_arm = some (.Vint (0#32))) (k : CC.Cont) :
    InternalRun ge 9 (.State procedure stage k e le memory)
      (.State procedure after k e (resultEnv le) memory) := by
  have evalABI (temps : CC.TempEnv) :
      CC.doEvalExpr ge e temps memory (.Evar ___a64_sim_abi_kind CC.tuchar) = some (.Vint (1#32)) :=
    abi_value e temps memory block binding read
  have tagFrame : ∀ v, (CC.PTree.set _t'13876 v le).get ___a64_mwr_tag = le.get ___a64_mwr_tag :=
    fun v => CC.PTree.gso _ _ _ _ (by decide +kernel)
  have armFrame : ∀ v w, (CC.PTree.set _t'209 w (CC.PTree.set _t'13876 v le)).get ___a64_mwr_arm =
      le.get ___a64_mwr_arm := by
    intro v w
    rw [CC.PTree.gso _t'209 ___a64_mwr_arm _ _ (by decide +kernel),
      CC.PTree.gso _t'13876 ___a64_mwr_arm _ _ (by decide +kernel)]
  apply internalRun_of_steps
  all_goals
    simp only [source,guard_source,branch_source,steps,InternalPath,InternalState,CC.doStep,
      evalABI,abi_eq,tag_false,arm_true,temp_value,
      tagFrame,armFrame,tag,arm,CC.PTree.gss,binop_type,temp_type,bool_true,bool_false,
      resultEnv,ite_true,ite_false,Bool.false_eq_true,eq_self,true_and,and_true,CC.E0,CC.Eapp,List.nil_append] <;> trivial

theorem temp_frame (le : CC.TempEnv) (id : CC.Ident) (h0 : id ≠ _t'13876) (h1 : id ≠ _t'209) :
    (resultEnv le).get id = le.get id := by
  unfold resultEnv
  rw [CC.PTree.gso _t'209 id _ _ (Ne.symm h1),CC.PTree.gso _t'13876 id _ _ (Ne.symm h0)]

theorem values (le : CC.TempEnv) :
    (resultEnv le).get _t'13876 = some (.Vint (1#32)) ∧
    (resultEnv le).get _t'209 = some (.Vint (0#32)) := by
  constructor
  · unfold resultEnv
    rw [CC.PTree.gso _t'209 _t'13876 _ _ (by decide +kernel)]
    exact CC.PTree.gss _ _ _
  · unfold resultEnv
    exact CC.PTree.gss _ _ _

/-- The actual store-tag26, writer-prefix29 and guard9 compose on the SAME
cache heap. The ABI1 read, like slot30/tag30, remains an explicit supplied resource. -/
theorem advance {m supplied : CC.Mem} {locals : Locals m} {base : BitVec 64}
    (result : Arm64CiliumCallerReturnMemory.Store (supplied := supplied) locals base)
    (header : Storage m) (tags : Table true m) (wordCells : Cells false m) (tagCells : Cells true m)
    (abi : CC.Mem.load .Mint8unsigned supplied (header.block 6) 0 = some (.Vint (1#32)))
    (slot : CC.Mem.load .Mint64 supplied tags.block 240 = some (.Vptr (tagCells.block ⟨30,by decide⟩) 0))
    (tag : CC.Mem.load .Mint8unsigned supplied (tagCells.block ⟨30,by decide⟩) 0 = some (.Vint (10#32)))
    (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 64
      (.State procedure .Sskip (Arm64CiliumCallerReturnOutcomes.groupCont k) (allocation m).1
        (Arm64CiliumCallerReturnOutcomes.resultEnv
          (Arm64CiliumCallerReturnOutcomes.reachedEnv wordCells tagCells le) base) result.after)
      (.State procedure after (Arm64CiliumCallerMemoryWriterPrefix.continuation k) (allocation m).1
        (resultEnv (Arm64CiliumCallerMemoryWriterPrefix.resultEnv
          (Arm64CiliumCallerMemoryWriterPrefix.incomingEnv wordCells tagCells le base))) result.after) := by
  have prefixRun := Arm64CiliumCallerMemoryWriterPrefix.advance result tags wordCells tagCells slot tag le k
  have reached := Arm64CiliumCallerMemoryWriterPrefix.values
    (Arm64CiliumCallerMemoryWriterPrefix.incomingEnv wordCells tagCells le base)
  have guardRun := execute (allocation m).1
    (Arm64CiliumCallerMemoryWriterPrefix.resultEnv
      (Arm64CiliumCallerMemoryWriterPrefix.incomingEnv wordCells tagCells le base))
    result.after (header.block 6) (header.binding 6)
    ((resources result header).trans abi) reached.2.1 reached.2.2
    (Arm64CiliumCallerMemoryWriterPrefix.continuation k)
  exact prefixRun.trans guardRun

end KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterGuard
