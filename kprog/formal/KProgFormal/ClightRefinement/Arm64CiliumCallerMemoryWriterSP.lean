import KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterGuard

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterSP
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure allocation)
open Arm64CiliumCallerLinkedProgram (ge)
open Arm64CiliumCallerDefaults (Locals)
open Arm64CiliumCallerTables (Table)
open Arm64CiliumCallerInitializers (Cells)
open Arm64CiliumCallerHeaderTailValues (Storage)

noncomputable def stage : CC.Stmt := Arm64CiliumCallerMemoryWriterGuard.after
noncomputable def after : CC.Stmt :=
  .Sloop s_trusted_arm64_arm64_sim_xdp_141 s_trusted_arm64_arm64_sim_xdp_142

private noncomputable def pointerBranch : CC.Stmt := by
  run_tac do
    let original ← Lean.Elab.Term.elabTerm (← `(s_trusted_arm64_arm64_sim_xdp_69)) none
    let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf original)
    unless node.isAppOfArity ``CC.Stmt.Sifthenelse 3 do throwError "actual original memory writer source choice changed"
    Lean.Elab.Tactic.closeMainGoal `actual_memory_writer_source_choice node.getAppArgs[1]!

theorem source : stage = .Ssequence
    (.Ssequence
      (.Sifthenelse (.Ebinop .Oeq (.Econst_int (CC.Integers.Int.repr 32) CC.tuint)
        (.Econst_int (CC.Integers.Int.repr 32) CC.tuint) CC.tint)
        s_trusted_arm64_arm64_sim_xdp_67 s_trusted_arm64_arm64_sim_xdp_68)
      (.Sset ___a64_mwr_bsrc (.Ecast (.Ecast (.Etempvar _t'167 CC.tuint) CC.tuchar) CC.tuchar)))
    (.Ssequence (.Sset ___a64_mwr_base (.Evar ___a64_sp CC.tlong))
      (.Ssequence s_trusted_arm64_arm64_sim_xdp_69 after)) := rfl
theorem stack_source : s_trusted_arm64_arm64_sim_xdp_67 =
    .Sset _t'167 (.Ecast (.Econst_int (CC.Integers.Int.repr 0) CC.tuint) CC.tuint) := rfl
theorem pointer_source : s_trusted_arm64_arm64_sim_xdp_69 =
    .Sifthenelse (.Ebinop .One (.Etempvar ___a64_mwr_bsrc CC.tuchar)
      (.Econst_int (CC.Integers.Int.repr 0) CC.tuint) CC.tint) pointerBranch .Sskip := rfl

/-- Only the two actual cache blocks were written. The current supplied SP
contents remain explicit and are not inferred from pre-provider SP or rights. -/
theorem resources {m supplied : CC.Mem} {locals : Locals m} {base : BitVec 64}
    (result : Arm64CiliumCallerReturnMemory.Store (supplied := supplied) locals base)
    (scalars : Arm64CiliumCallerEntryScalars.Locals m) :
    CC.Mem.load .Mint64 result.after (scalars.block 0) 0 =
      CC.Mem.load .Mint64 supplied (scalars.block 0) 0 :=
  Arm64CiliumCallerReturnMemory.bound_frame result (scalars.binding 0)
    (by decide +kernel) (by decide +kernel) .Mint64 0

theorem sp_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (block : CC.Block) (sp : BitVec 64)
    (binding : e.get ___a64_sp = some (block,CC.tlong))
    (read : CC.Mem.load .Mint64 memory block 0 = some (.Vlong sp)) :
    CC.doEvalExpr ge e le memory (.Evar ___a64_sp CC.tlong) = some (.Vlong sp) := by
  simp only [CC.doEvalExpr,CC.lvalOfVar,binding,ite_true]
  change CC.Mem.load .Mint64 memory block 0 = _
  exact read

private theorem constant_eq (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr ge e le memory (.Ebinop .Oeq (.Econst_int (CC.Integers.Int.repr 32) CC.tuint)
      (.Econst_int (CC.Integers.Int.repr 32) CC.tuint) CC.tint) = some (.Vint (1#32)) := rfl
private theorem zero_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr ge e le memory
      (.Ecast (.Econst_int (CC.Integers.Int.repr 0) CC.tuint) CC.tuint) = some (.Vint (0#32)) := rfl
private theorem source_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get _t'167 = some (.Vint (0#32))) :
    CC.doEvalExpr ge e le memory
      (.Ecast (.Ecast (.Etempvar _t'167 CC.tuint) CC.tuchar) CC.tuchar) = some (.Vint (0#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem pointer_false (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get ___a64_mwr_bsrc = some (.Vint (0#32))) :
    CC.doEvalExpr ge e le memory (.Ebinop .One (.Etempvar ___a64_mwr_bsrc CC.tuchar)
      (.Econst_int (CC.Integers.Int.repr 0) CC.tuint) CC.tint) = some (.Vint (0#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem binop_type (op : CC.Binop) (a b : CC.Expr) (ty : CC.Ty) :
    CC.typeof (.Ebinop op a b ty) = ty := rfl
private theorem bool_true (memory : CC.Mem) :
    CC.Cop.boolVal (.Vint (1#32)) CC.tint memory = some true := rfl
private theorem bool_false (memory : CC.Mem) :
    CC.Cop.boolVal (.Vint (0#32)) CC.tint memory = some false := rfl

noncomputable def resultEnv (le : CC.TempEnv) (sp : BitVec 64) : CC.TempEnv :=
  CC.PTree.set ___a64_mwr_base (CC.Val.Vlong sp)
    (CC.PTree.set ___a64_mwr_bsrc (CC.Val.Vint (0#32)) (CC.PTree.set _t'167 (CC.Val.Vint (0#32)) le))

/-- Thirteen actual steps select the original register32 source, read the real
post-provider SP, and skip the pointer alternative to the original address loop. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (block : CC.Block) (sp : BitVec 64)
    (binding : e.get ___a64_sp = some (block,CC.tlong))
    (read : CC.Mem.load .Mint64 memory block 0 = some (.Vlong sp)) (k : CC.Cont) :
    InternalRun ge 13 (.State procedure stage k e le memory)
      (.State procedure after k e (resultEnv le sp) memory) := by
  have evalSP (temps : CC.TempEnv) :
      CC.doEvalExpr ge e temps memory (.Evar ___a64_sp CC.tlong) = some (.Vlong sp) :=
    sp_value e temps memory block sp binding read
  have sourceFrame : ∀ v w, (CC.PTree.set ___a64_mwr_base v (CC.PTree.set ___a64_mwr_bsrc w
      (CC.PTree.set _t'167 (.Vint (0#32)) le))).get ___a64_mwr_bsrc = some w := by
    intro v w
    rw [CC.PTree.gso ___a64_mwr_base ___a64_mwr_bsrc _ _ (by decide +kernel),CC.PTree.gss]
  apply internalRun_of_steps
  all_goals
    simp only [source,stack_source,pointer_source,steps,InternalPath,InternalState,CC.doStep,
      constant_eq,zero_value,source_value,evalSP,pointer_false,sourceFrame,
      CC.PTree.gss,binop_type,bool_true,bool_false,resultEnv,ite_true,ite_false,Bool.false_eq_true,
      eq_self,true_and,and_true,CC.E0,CC.Eapp,List.nil_append] <;> trivial

theorem temp_frame (le : CC.TempEnv) (sp : BitVec 64) (id : CC.Ident)
    (h0 : id ≠ _t'167) (h1 : id ≠ ___a64_mwr_bsrc) (h2 : id ≠ ___a64_mwr_base) :
    (resultEnv le sp).get id = le.get id := by
  unfold resultEnv
  rw [CC.PTree.gso ___a64_mwr_base id _ _ (Ne.symm h2),
    CC.PTree.gso ___a64_mwr_bsrc id _ _ (Ne.symm h1),CC.PTree.gso _t'167 id _ _ (Ne.symm h0)]

theorem values (le : CC.TempEnv) (sp : BitVec 64) :
    (resultEnv le sp).get _t'167 = some (.Vint (0#32)) ∧
    (resultEnv le sp).get ___a64_mwr_bsrc = some (.Vint (0#32)) ∧
    (resultEnv le sp).get ___a64_mwr_base = some (.Vlong sp) := by
  refine ⟨?_,?_,?_⟩
  · unfold resultEnv
    rw [CC.PTree.gso ___a64_mwr_base _t'167 _ _ (by decide +kernel),
      CC.PTree.gso ___a64_mwr_bsrc _t'167 _ _ (by decide +kernel)]
    exact CC.PTree.gss _ _ _
  · unfold resultEnv
    rw [CC.PTree.gso ___a64_mwr_base ___a64_mwr_bsrc _ _ (by decide +kernel)]
    exact CC.PTree.gss _ _ _
  · unfold resultEnv
    exact CC.PTree.gss _ _ _

noncomputable def incomingEnv {m : CC.Mem} (wordCells : Cells false m) (tagCells : Cells true m)
    (le : CC.TempEnv) (base : BitVec 64) : CC.TempEnv :=
  Arm64CiliumCallerMemoryWriterGuard.resultEnv (Arm64CiliumCallerMemoryWriterPrefix.resultEnv
    (Arm64CiliumCallerMemoryWriterPrefix.incomingEnv wordCells tagCells le base))

/-- The effective offset0 follows from the actual earlier prefix through both
subsequent temporary frames; SP is not preindexed a second time. -/
theorem offset_zero {m : CC.Mem} (wordCells : Cells false m) (tagCells : Cells true m)
    (le : CC.TempEnv) (base sp : BitVec 64) :
    (resultEnv (incomingEnv wordCells tagCells le base) sp).get ___a64_mwr_off = some (.Vlong (0#64)) := by
  rw [temp_frame _ sp ___a64_mwr_off (by decide +kernel) (by decide +kernel) (by decide +kernel)]
  unfold incomingEnv
  rw [Arm64CiliumCallerMemoryWriterGuard.temp_frame _ ___a64_mwr_off
    (by decide +kernel) (by decide +kernel)]
  exact (Arm64CiliumCallerMemoryWriterPrefix.values
    (Arm64CiliumCallerMemoryWriterPrefix.incomingEnv wordCells tagCells le base)).1

/-- Actual store-tag26 + writer29 + guard9 + SP preparation13 =77. The
post-provider SP and ABI contents are explicit resources on the same supplied heap. -/
theorem advance {m supplied : CC.Mem} {locals : Locals m} {base : BitVec 64}
    (result : Arm64CiliumCallerReturnMemory.Store (supplied := supplied) locals base)
    (header : Storage m) (scalars : Arm64CiliumCallerEntryScalars.Locals m)
    (tags : Table true m) (wordCells : Cells false m) (tagCells : Cells true m) (sp : BitVec 64)
    (spRead : CC.Mem.load .Mint64 supplied (scalars.block 0) 0 = some (.Vlong sp))
    (abi : CC.Mem.load .Mint8unsigned supplied (header.block 6) 0 = some (.Vint (1#32)))
    (slot : CC.Mem.load .Mint64 supplied tags.block 240 = some (.Vptr (tagCells.block ⟨30,by decide⟩) 0))
    (tag : CC.Mem.load .Mint8unsigned supplied (tagCells.block ⟨30,by decide⟩) 0 = some (.Vint (10#32)))
    (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 77
      (.State procedure .Sskip (Arm64CiliumCallerReturnOutcomes.groupCont k) (allocation m).1
        (Arm64CiliumCallerReturnOutcomes.resultEnv
          (Arm64CiliumCallerReturnOutcomes.reachedEnv wordCells tagCells le) base) result.after)
      (.State procedure after (Arm64CiliumCallerMemoryWriterPrefix.continuation k) (allocation m).1
        (resultEnv (incomingEnv wordCells tagCells le base) sp) result.after) := by
  have guardRun := Arm64CiliumCallerMemoryWriterGuard.advance result header tags wordCells tagCells abi slot tag le k
  have spRun := execute (allocation m).1 (incomingEnv wordCells tagCells le base)
    result.after (scalars.block 0) sp (scalars.binding 0) ((resources result scalars).trans spRead)
    (Arm64CiliumCallerMemoryWriterPrefix.continuation k)
  exact guardRun.trans spRun

end KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterSP
