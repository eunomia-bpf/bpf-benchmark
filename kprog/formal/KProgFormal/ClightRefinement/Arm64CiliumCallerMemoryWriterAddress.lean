import KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterSP

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterAddress
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure allocation)
open Arm64CiliumCallerLinkedProgram (ge)
open Arm64CiliumCallerDefaults (Locals)
open Arm64CiliumCallerTables (Table)
open Arm64CiliumCallerInitializers (Cells)
open Arm64CiliumCallerHeaderTailValues (Storage)

private structure Parts where
  innerBody : CC.Stmt
  rest : CC.Stmt
  after : CC.Stmt
private noncomputable def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless node.isAppOfArity ctor arity do throwError "actual original stack store address changed"
      pure node.getAppArgs
    let original ← Lean.Elab.Term.elabTerm (← `(s_trusted_arm64_arm64_sim_xdp_141)) none
    let offset ← peel original ``CC.Stmt.Ssequence 2
    let width ← peel offset[1]! ``CC.Stmt.Ssequence 2
    let value ← peel width[1]! ``CC.Stmt.Ssequence 2
    let outer ← peel value[1]! ``CC.Stmt.Ssequence 2
    let loop ← peel outer[0]! ``CC.Stmt.Sloop 2
    let index ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let storeWidth ← peel index[1]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_stack_store_address
      (← Lean.Meta.mkAppM ``Parts.mk #[loop[0]!,outer[1]!,storeWidth[1]!])

noncomputable def stage : CC.Stmt := Arm64CiliumCallerMemoryWriterSP.after
noncomputable def body : CC.Stmt := s_trusted_arm64_arm64_sim_xdp_141
noncomputable def innerBody : CC.Stmt := parts.innerBody
noncomputable def rest : CC.Stmt := parts.rest
noncomputable def after : CC.Stmt := parts.after
noncomputable def continuation (k : CC.Cont) : CC.Cont :=
  .Kloop1 innerBody .Sbreak (.Kseq rest (.Kloop1 body s_trusted_arm64_arm64_sim_xdp_142 k))

theorem source : stage = .Sloop body s_trusted_arm64_arm64_sim_xdp_142 := rfl
theorem body_source : body = .Ssequence
    (.Sset ___a64_loss_off (.Ebinop .Oadd (.Etempvar ___a64_mwr_base CC.tlong)
      (.Etempvar ___a64_mwr_off CC.tlong) CC.tlong))
    (.Ssequence (.Sset ___a64_loss_width (.Ecast (.Etempvar ___a64_l_width CC.tuchar) CC.tuchar))
      (.Ssequence (.Sset ___a64_loss_value (.Etempvar ___a64_store_value CC.tulong))
        (.Ssequence (.Sloop innerBody .Sbreak) rest))) := rfl
theorem inner_source : innerBody = .Ssequence
    (.Sset ___a64_stw_index (.Ebinop .Oadd
      (.Ecast (.Econst_long (CC.Integers.Int64.repr 32) CC.tlong) CC.tulong)
      (.Ecast (.Etempvar ___a64_loss_off CC.tlong) CC.tulong) CC.tulong))
    (.Ssequence (.Sset ___a64_stw_width (.Ecast (.Etempvar ___a64_loss_width CC.tuchar) CC.tuchar))
      after) := rfl

private theorem offset_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (sp : BitVec 64)
    (base : le.get ___a64_mwr_base = some (.Vlong sp))
    (offset : le.get ___a64_mwr_off = some (.Vlong (0#64))) :
    CC.doEvalExpr ge e le memory (.Ebinop .Oadd (.Etempvar ___a64_mwr_base CC.tlong)
      (.Etempvar ___a64_mwr_off CC.tlong) CC.tlong) = some (.Vlong sp) := by
  simp only [CC.doEvalExpr,base,offset]
  change some (CC.Val.Vlong (sp + (0#64))) = some (.Vlong sp)
  rw [BitVec.add_zero]
private theorem width_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (id : CC.Ident)
    (read : le.get id = some (.Vint (8#32))) :
    CC.doEvalExpr ge e le memory (.Ecast (.Etempvar id CC.tuchar) CC.tuchar) = some (.Vint (8#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem index_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (sp : BitVec 64)
    (read : le.get ___a64_loss_off = some (.Vlong sp)) :
    CC.doEvalExpr ge e le memory (.Ebinop .Oadd
      (.Ecast (.Econst_long (CC.Integers.Int64.repr 32) CC.tlong) CC.tulong)
      (.Ecast (.Etempvar ___a64_loss_off CC.tlong) CC.tulong) CC.tulong) =
      some (.Vlong ((32#64) + sp)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem temp_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (id : CC.Ident) (ty : CC.Ty) :
    CC.doEvalExpr ge e le memory (.Etempvar id ty) = le.get id := rfl

noncomputable def resultEnv (le : CC.TempEnv) (sp value : BitVec 64) : CC.TempEnv :=
  CC.PTree.set ___a64_stw_width (CC.Val.Vint (8#32))
    (CC.PTree.set ___a64_stw_index (CC.Val.Vlong ((32#64) + sp))
      (CC.PTree.set ___a64_loss_value (CC.Val.Vlong value)
        (CC.PTree.set ___a64_loss_width (CC.Val.Vint (8#32))
          (CC.PTree.set ___a64_loss_off (CC.Val.Vlong sp) le))))

/-- Eighteen original steps derive the signed offset, width and numeric value,
then the stack index and width. No data store or alternative body is replaced. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (sp value : BitVec 64)
    (base : le.get ___a64_mwr_base = some (.Vlong sp))
    (offset : le.get ___a64_mwr_off = some (.Vlong (0#64)))
    (width : le.get ___a64_l_width = some (.Vint (8#32)))
    (stored : le.get ___a64_store_value = some (.Vlong value)) (k : CC.Cont) :
    InternalRun ge 18 (.State procedure stage k e le memory)
      (.State procedure after (continuation k) e (resultEnv le sp value) memory) := by
  have offsetEval := offset_value e le memory sp base offset
  have indexEval (temps : CC.TempEnv) (read : temps.get ___a64_loss_off = some (.Vlong sp)) :
      CC.doEvalExpr ge e temps memory (.Ebinop .Oadd
        (.Ecast (.Econst_long (CC.Integers.Int64.repr 32) CC.tlong) CC.tulong)
        (.Ecast (.Etempvar ___a64_loss_off CC.tlong) CC.tulong) CC.tulong) =
        some (.Vlong ((32#64) + sp)) :=
    index_value e temps memory sp read
  have widthFrame : ∀ v, (CC.PTree.set ___a64_loss_off v le).get ___a64_l_width = le.get ___a64_l_width :=
    fun v => CC.PTree.gso _ _ _ _ (by decide +kernel)
  have valueFrame : ∀ a b, (CC.PTree.set ___a64_loss_width b
      (CC.PTree.set ___a64_loss_off a le)).get ___a64_store_value = le.get ___a64_store_value := by
    intro a b
    rw [CC.PTree.gso ___a64_loss_width ___a64_store_value _ _ (by decide +kernel),
      CC.PTree.gso ___a64_loss_off ___a64_store_value _ _ (by decide +kernel)]
  have offsetFrame : ∀ a b c, (CC.PTree.set ___a64_loss_value c (CC.PTree.set ___a64_loss_width b
      (CC.PTree.set ___a64_loss_off a le))).get ___a64_loss_off = some a := by
    intro a b c
    rw [CC.PTree.gso ___a64_loss_value ___a64_loss_off _ _ (by decide +kernel),
      CC.PTree.gso ___a64_loss_width ___a64_loss_off _ _ (by decide +kernel),CC.PTree.gss]
  have lossWidthFrame : ∀ a b c d, (CC.PTree.set ___a64_stw_index d
      (CC.PTree.set ___a64_loss_value c (CC.PTree.set ___a64_loss_width b
        (CC.PTree.set ___a64_loss_off a le)))).get ___a64_loss_width = some b := by
    intro a b c d
    rw [CC.PTree.gso ___a64_stw_index ___a64_loss_width _ _ (by decide +kernel),
      CC.PTree.gso ___a64_loss_value ___a64_loss_width _ _ (by decide +kernel),CC.PTree.gss]
  apply internalRun_of_steps
  all_goals
    simp only [source,body_source,inner_source,steps,InternalPath,InternalState,CC.doStep,
      offsetEval,width_value,indexEval,temp_value,widthFrame,valueFrame,offsetFrame,lossWidthFrame,
      base,offset,width,stored,CC.PTree.gss,resultEnv,continuation,
      eq_self,true_and,and_true,CC.E0,CC.Eapp,List.nil_append] <;> trivial

theorem temp_frame (le : CC.TempEnv) (sp value : BitVec 64) (id : CC.Ident)
    (h0 : id ≠ ___a64_loss_off) (h1 : id ≠ ___a64_loss_width) (h2 : id ≠ ___a64_loss_value)
    (h3 : id ≠ ___a64_stw_index) (h4 : id ≠ ___a64_stw_width) :
    (resultEnv le sp value).get id = le.get id := by
  unfold resultEnv
  rw [CC.PTree.gso ___a64_stw_width id _ _ (Ne.symm h4),
    CC.PTree.gso ___a64_stw_index id _ _ (Ne.symm h3),
    CC.PTree.gso ___a64_loss_value id _ _ (Ne.symm h2),
    CC.PTree.gso ___a64_loss_width id _ _ (Ne.symm h1),CC.PTree.gso ___a64_loss_off id _ _ (Ne.symm h0)]

theorem values (le : CC.TempEnv) (sp value : BitVec 64) :
    (resultEnv le sp value).get ___a64_loss_off = some (.Vlong sp) ∧
    (resultEnv le sp value).get ___a64_stw_index = some (.Vlong ((32#64) + sp)) ∧
    (resultEnv le sp value).get ___a64_stw_width = some (.Vint (8#32)) ∧
    (resultEnv le sp value).get ___a64_loss_value = some (.Vlong value) := by
  refine ⟨?_,?_,?_,?_⟩
  · unfold resultEnv
    rw [CC.PTree.gso ___a64_stw_width ___a64_loss_off _ _ (by decide +kernel),
      CC.PTree.gso ___a64_stw_index ___a64_loss_off _ _ (by decide +kernel),
      CC.PTree.gso ___a64_loss_value ___a64_loss_off _ _ (by decide +kernel),
      CC.PTree.gso ___a64_loss_width ___a64_loss_off _ _ (by decide +kernel)]
    exact CC.PTree.gss _ _ _
  · unfold resultEnv
    rw [CC.PTree.gso ___a64_stw_width ___a64_stw_index _ _ (by decide +kernel)]
    exact CC.PTree.gss _ _ _
  · unfold resultEnv
    exact CC.PTree.gss _ _ _
  · unfold resultEnv
    rw [CC.PTree.gso ___a64_stw_width ___a64_loss_value _ _ (by decide +kernel),
      CC.PTree.gso ___a64_stw_index ___a64_loss_value _ _ (by decide +kernel)]
    exact CC.PTree.gss _ _ _

theorem index_zero (le : CC.TempEnv) (value : BitVec 64) :
    (resultEnv le Arm64CiliumCallerSPPreindex.delta value).get ___a64_stw_index = some (.Vlong (0#64)) := by
  rw [(values le Arm64CiliumCallerSPPreindex.delta value).2.1]
  rfl

noncomputable def incomingEnv {m : CC.Mem} (wordCells : Cells false m) (tagCells : Cells true m)
    (le : CC.TempEnv) (base sp : BitVec 64) : CC.TempEnv :=
  Arm64CiliumCallerMemoryWriterSP.resultEnv
    (Arm64CiliumCallerMemoryWriterSP.incomingEnv wordCells tagCells le base) sp

theorem literal_width (le : CC.TempEnv) :
    (Arm64CiliumCallerWidthPrefix.resultEnv le).get ___a64_l_width = some (.Vint (8#32)) := by
  unfold Arm64CiliumCallerWidthPrefix.resultEnv
  exact CC.PTree.gss _ _ _

private theorem returned_width (le : CC.TempEnv) (base : BitVec 64) :
    (Arm64CiliumCallerReturnMemory.resultEnv le base).get ___a64_l_width = le.get ___a64_l_width := by
  unfold Arm64CiliumCallerReturnMemory.resultEnv
  exact CC.PTree.gso _t'157 ___a64_l_width _ _ (by decide +kernel)
private theorem preindex_width (le : CC.TempEnv) :
    (Arm64CiliumCallerSPPreindex.resultEnv le).get ___a64_l_width = le.get ___a64_l_width := by
  unfold Arm64CiliumCallerSPPreindex.resultEnv
  rw [CC.PTree.gso _t'13900 ___a64_l_width _ _ (by decide +kernel),
    CC.PTree.gso ___a64_l_pp ___a64_l_width _ _ (by decide +kernel),
    CC.PTree.gso _t'137 ___a64_l_width _ _ (by decide +kernel)]

theorem stored_value {m : CC.Mem} (wordCells : Cells false m) (tagCells : Cells true m)
    (le : CC.TempEnv) (base sp : BitVec 64) :
    (incomingEnv wordCells tagCells le base sp).get ___a64_store_value = some (.Vlong base) := by
  unfold incomingEnv Arm64CiliumCallerMemoryWriterSP.incomingEnv Arm64CiliumCallerMemoryWriterPrefix.incomingEnv
  rw [Arm64CiliumCallerMemoryWriterSP.temp_frame _ sp ___a64_store_value
      (by decide +kernel) (by decide +kernel) (by decide +kernel),
    Arm64CiliumCallerMemoryWriterGuard.temp_frame _ ___a64_store_value
      (by decide +kernel) (by decide +kernel),
    Arm64CiliumCallerMemoryWriterPrefix.temp_frame _ ___a64_store_value
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel),
    Arm64CiliumCallerStoreTag.temp_frame tagCells _ ___a64_store_value
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)]
  exact (Arm64CiliumCallerReturnOutcomes.values _ base).1

/-- The real width temporary is framed through every actual offset/reader/
return/cache/writer update. Its incoming8 premise is supplied by literal_width. -/
theorem width_preserved {m : CC.Mem} (wordCells : Cells false m) (tagCells : Cells true m)
    (le : CC.TempEnv) (base sp : BitVec 64) :
    (incomingEnv wordCells tagCells le base sp).get ___a64_l_width = le.get ___a64_l_width := by
  unfold incomingEnv Arm64CiliumCallerMemoryWriterSP.incomingEnv Arm64CiliumCallerMemoryWriterPrefix.incomingEnv
    Arm64CiliumCallerReturnOutcomes.resultEnv Arm64CiliumCallerReturnOutcomes.reachedEnv
  rw [Arm64CiliumCallerMemoryWriterSP.temp_frame _ sp ___a64_l_width
      (by decide +kernel) (by decide +kernel) (by decide +kernel),
    Arm64CiliumCallerMemoryWriterGuard.temp_frame _ ___a64_l_width
      (by decide +kernel) (by decide +kernel),
    Arm64CiliumCallerMemoryWriterPrefix.temp_frame _ ___a64_l_width
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel),
    Arm64CiliumCallerStoreTag.temp_frame tagCells _ ___a64_l_width
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel),
    Arm64CiliumCallerReturnMaterialize.temp_frame _ base ___a64_l_width
      (by decide +kernel) (by decide +kernel) (by decide +kernel),
    returned_width,
    Arm64CiliumCallerReturnProvider.temp_frame _ ___a64_l_width
      (by decide +kernel) (by decide +kernel) (by decide +kernel),
    Arm64CiliumCallerR30Tag.temp_frame tagCells _ ___a64_l_width
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel),
    Arm64CiliumCallerR30Word.temp_frame wordCells _ ___a64_l_width
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel),
    Arm64CiliumCallerMemOffset.temp_frame _ ___a64_l_width
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel),
    Arm64CiliumCallerMemOffsetPrefix.temp_frame _ ___a64_l_width
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel),
    preindex_width]


/-- The actual77-step reader/writer prefix composes with18 address-setup
steps, on the same heap and explicit provider resources. Width8 is an
incoming temporary invariant, not a read/store-success or native-state oracle. -/
theorem advance {m supplied : CC.Mem} {locals : Locals m} {base : BitVec 64}
    (result : Arm64CiliumCallerReturnMemory.Store (supplied := supplied) locals base)
    (header : Storage m) (scalars : Arm64CiliumCallerEntryScalars.Locals m)
    (tags : Table true m) (wordCells : Cells false m) (tagCells : Cells true m) (sp : BitVec 64)
    (spRead : CC.Mem.load .Mint64 supplied (scalars.block 0) 0 = some (.Vlong sp))
    (abi : CC.Mem.load .Mint8unsigned supplied (header.block 6) 0 = some (.Vint (1#32)))
    (slot : CC.Mem.load .Mint64 supplied tags.block 240 = some (.Vptr (tagCells.block ⟨30,by decide⟩) 0))
    (tag : CC.Mem.load .Mint8unsigned supplied (tagCells.block ⟨30,by decide⟩) 0 = some (.Vint (10#32)))
    (le : CC.TempEnv) (width : le.get ___a64_l_width = some (.Vint (8#32))) (k : CC.Cont) :
    InternalRun ge 95
      (.State procedure .Sskip (Arm64CiliumCallerReturnOutcomes.groupCont k) (allocation m).1
        (Arm64CiliumCallerReturnOutcomes.resultEnv
          (Arm64CiliumCallerReturnOutcomes.reachedEnv wordCells tagCells le) base) result.after)
      (.State procedure after (continuation (Arm64CiliumCallerMemoryWriterPrefix.continuation k)) (allocation m).1
        (resultEnv (incomingEnv wordCells tagCells le base sp) sp base) result.after) := by
  have spRun := Arm64CiliumCallerMemoryWriterSP.advance result header scalars tags wordCells tagCells sp spRead abi slot tag le k
  have reached := Arm64CiliumCallerMemoryWriterSP.values
    (Arm64CiliumCallerMemoryWriterSP.incomingEnv wordCells tagCells le base) sp
  have addressRun := execute (allocation m).1 (incomingEnv wordCells tagCells le base sp)
    result.after sp base reached.2.2
    (Arm64CiliumCallerMemoryWriterSP.offset_zero wordCells tagCells le base sp)
    ((width_preserved wordCells tagCells le base sp).trans width)
    (stored_value wordCells tagCells le base sp)
    (Arm64CiliumCallerMemoryWriterPrefix.continuation k)
  exact spRun.trans addressRun

end KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterAddress
