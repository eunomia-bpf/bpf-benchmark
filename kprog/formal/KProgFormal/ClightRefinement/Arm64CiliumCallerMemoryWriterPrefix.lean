import KProgFormal.ClightRefinement.Arm64CiliumCallerStoreTag

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterPrefix
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure allocation)
open Arm64CiliumCallerLinkedProgram (ge)
open Arm64CiliumCallerDefaults (Locals)
open Arm64CiliumCallerTables (Table)
open Arm64CiliumCallerInitializers (Cells)

private structure Parts where
  rest : CC.Stmt
  body : CC.Stmt
  tagBody : CC.Stmt
  otherTag : CC.Stmt
  armBody : CC.Stmt
  otherArm : CC.Stmt
  after : CC.Stmt

private noncomputable def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless node.isAppOfArity ctor arity do throwError "actual original memory writer prefix changed"
      pure node.getAppArgs
    let original ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerStoreTag.after)) none
    let outer ← peel original ``CC.Stmt.Ssequence 2
    let loop ← peel outer[0]! ``CC.Stmt.Sloop 2
    let offset ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let tags ← peel offset[1]! ``CC.Stmt.Ssequence 2
    let tagLoop ← peel tags[0]! ``CC.Stmt.Sloop 2
    let reg ← peel tagLoop[0]! ``CC.Stmt.Ssequence 2
    let tagTail ← peel reg[1]! ``CC.Stmt.Ssequence 2
    let tagChoice ← peel tagTail[0]! ``CC.Stmt.Sifthenelse 3
    let afterTag ← peel tags[1]! ``CC.Stmt.Ssequence 2
    let arm ← peel afterTag[0]! ``CC.Stmt.Ssequence 2
    let choices ← peel arm[0]! ``CC.Stmt.Ssequence 2
    let armChoice ← peel choices[0]! ``CC.Stmt.Sifthenelse 3
    Lean.Elab.Tactic.closeMainGoal `actual_memory_writer_prefix
      (← Lean.Meta.mkAppM ``Parts.mk
        #[outer[1]!,loop[0]!,tagLoop[0]!,tagChoice[2]!,afterTag[0]!,armChoice[2]!,afterTag[1]!])

noncomputable def stage : CC.Stmt := Arm64CiliumCallerStoreTag.after
noncomputable def rest : CC.Stmt := parts.rest
noncomputable def body : CC.Stmt := parts.body
noncomputable def writer : CC.Stmt := .Sloop body .Sbreak
noncomputable def tagBody : CC.Stmt := parts.tagBody
noncomputable def tagReader : CC.Stmt := .Sloop tagBody .Sbreak
noncomputable def armBody : CC.Stmt := parts.armBody
noncomputable def after : CC.Stmt := parts.after
noncomputable def continuation (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak (.Kseq rest k)

theorem source : stage = .Ssequence writer rest := rfl
theorem body_source : body = .Ssequence
    (.Sset ___a64_mwr_off (.Etempvar ___a64_store_off CC.tlong))
    (.Ssequence tagReader (.Ssequence armBody after)) := rfl
theorem tag_source : tagBody = .Ssequence
    (.Sset ___a64_l_reg__7 (.Ecast (.Econst_int (CC.Integers.Int.repr 32) CC.tuint) CC.tulong))
    (.Ssequence
      (.Sifthenelse (.Ebinop .Oeq (.Etempvar ___a64_l_reg__7 CC.tulong)
          (.Econst_int (CC.Integers.Int.repr 32) CC.tuint) CC.tint)
        (.Sset _t'159 (.Ecast (.Econst_int (CC.Integers.Int.repr 4) CC.tuint) CC.tuint)) parts.otherTag)
      (.Sset ___a64_mwr_tag (.Ecast (.Etempvar _t'159 CC.tuint) CC.tuchar))) := rfl
theorem arm_source : armBody = .Ssequence
    (.Ssequence
      (.Sifthenelse (.Ebinop .Oeq (.Econst_int (CC.Integers.Int.repr 32) CC.tuint)
          (.Econst_int (CC.Integers.Int.repr 32) CC.tuint) CC.tint)
        (.Sset _t'160 (.Econst_int (CC.Integers.Int.repr 1) CC.tint)) parts.otherArm)
      (.Sifthenelse (.Etempvar _t'160 CC.tint)
        (.Sset _t'161 (.Ecast (.Econst_int (CC.Integers.Int.repr 0) CC.tuint) CC.tuint))
        (.Sset _t'161 (.Ecast (.Econst_int (CC.Integers.Int.repr 1) CC.tuint) CC.tuint))))
    (.Sset ___a64_mwr_arm (.Ecast (.Ecast (.Etempvar _t'161 CC.tuint) CC.tuchar) CC.tuchar)) := rfl


private theorem reg_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr ge e le memory
      (.Ecast (.Econst_int (CC.Integers.Int.repr 32) CC.tuint) CC.tulong) = some (.Vlong (32#64)) := rfl
private theorem reg_eq (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get ___a64_l_reg__7 = some (.Vlong (32#64))) :
    CC.doEvalExpr ge e le memory
      (.Ebinop .Oeq (.Etempvar ___a64_l_reg__7 CC.tulong)
        (.Econst_int (CC.Integers.Int.repr 32) CC.tuint) CC.tint) = some (.Vint (1#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem constant_eq (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr ge e le memory
      (.Ebinop .Oeq (.Econst_int (CC.Integers.Int.repr 32) CC.tuint)
        (.Econst_int (CC.Integers.Int.repr 32) CC.tuint) CC.tint) = some (.Vint (1#32)) := rfl
private theorem four_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr ge e le memory
      (.Ecast (.Econst_int (CC.Integers.Int.repr 4) CC.tuint) CC.tuint) = some (.Vint (4#32)) := rfl
private theorem zero_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr ge e le memory
      (.Ecast (.Econst_int (CC.Integers.Int.repr 0) CC.tuint) CC.tuint) = some (.Vint (0#32)) := rfl
private theorem one_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr ge e le memory (.Econst_int (CC.Integers.Int.repr 1) CC.tint) = some (.Vint (1#32)) := rfl
private theorem tag_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get _t'159 = some (.Vint (4#32))) :
    CC.doEvalExpr ge e le memory (.Ecast (.Etempvar _t'159 CC.tuint) CC.tuchar) = some (.Vint (4#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem arm_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get _t'161 = some (.Vint (0#32))) :
    CC.doEvalExpr ge e le memory
      (.Ecast (.Ecast (.Etempvar _t'161 CC.tuint) CC.tuchar) CC.tuchar) = some (.Vint (0#32)) := by
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

noncomputable def resultEnv (le : CC.TempEnv) : CC.TempEnv :=
  CC.PTree.set ___a64_mwr_arm (CC.Val.Vint (0#32))
    (CC.PTree.set _t'161 (CC.Val.Vint (0#32))
      (CC.PTree.set _t'160 (CC.Val.Vint (1#32))
        (CC.PTree.set ___a64_mwr_tag (CC.Val.Vint (4#32))
          (CC.PTree.set _t'159 (CC.Val.Vint (4#32))
            (CC.PTree.set ___a64_l_reg__7 (CC.Val.Vlong (32#64))
              (CC.PTree.set ___a64_mwr_off (CC.Val.Vlong (0#64)) le))))))

/-- Original writer entry, offset copy, STACK-tag reader and arm selection.
All29 transitions retain the whole heap and stop at the original ABI guard. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (zero : le.get ___a64_store_off = some (.Vlong (0#64))) (k : CC.Cont) :
    InternalRun ge 29 (.State procedure stage k e le memory)
      (.State procedure after (continuation k) e (resultEnv le) memory) := by
  apply internalRun_of_steps
  all_goals
    simp only [source,writer,body_source,tagReader,tag_source,arm_source,
      steps,InternalPath,InternalState,CC.doStep,reg_value,reg_eq,constant_eq,four_value,zero_value,one_value,
      tag_value,arm_value,temp_value,zero,binop_type,temp_type,bool_true,
      CC.PTree.gss,resultEnv,continuation,ite_true,eq_self,true_and,and_true,
      CC.E0,CC.Eapp,List.nil_append] <;> trivial

theorem temp_frame (le : CC.TempEnv) (id : CC.Ident)
    (h0 : id ≠ ___a64_mwr_off)
    (h1 : id ≠ ___a64_l_reg__7)
    (h2 : id ≠ _t'159)
    (h3 : id ≠ ___a64_mwr_tag)
    (h4 : id ≠ _t'160)
    (h5 : id ≠ _t'161)
    (h6 : id ≠ ___a64_mwr_arm) :
    (resultEnv le).get id = le.get id := by
  unfold resultEnv
  rw [CC.PTree.gso ___a64_mwr_arm id _ _ (Ne.symm h6),
    CC.PTree.gso _t'161 id _ _ (Ne.symm h5),
    CC.PTree.gso _t'160 id _ _ (Ne.symm h4),
    CC.PTree.gso ___a64_mwr_tag id _ _ (Ne.symm h3),
    CC.PTree.gso _t'159 id _ _ (Ne.symm h2),
    CC.PTree.gso ___a64_l_reg__7 id _ _ (Ne.symm h1),
    CC.PTree.gso ___a64_mwr_off id _ _ (Ne.symm h0)]

theorem values (le : CC.TempEnv) :
    (resultEnv le).get ___a64_mwr_off = some (.Vlong (0#64)) ∧
    (resultEnv le).get ___a64_mwr_tag = some (.Vint (4#32)) ∧
    (resultEnv le).get ___a64_mwr_arm = some (.Vint (0#32)) := by
  refine ⟨?_,?_,?_⟩
  · unfold resultEnv
    rw [CC.PTree.gso ___a64_mwr_arm ___a64_mwr_off _ _ (by decide +kernel),
      CC.PTree.gso _t'161 ___a64_mwr_off _ _ (by decide +kernel),
      CC.PTree.gso _t'160 ___a64_mwr_off _ _ (by decide +kernel),
      CC.PTree.gso ___a64_mwr_tag ___a64_mwr_off _ _ (by decide +kernel),
      CC.PTree.gso _t'159 ___a64_mwr_off _ _ (by decide +kernel),
      CC.PTree.gso ___a64_l_reg__7 ___a64_mwr_off _ _ (by decide +kernel)]
    exact CC.PTree.gss _ _ _
  · unfold resultEnv
    rw [CC.PTree.gso ___a64_mwr_arm ___a64_mwr_tag _ _ (by decide +kernel),
      CC.PTree.gso _t'161 ___a64_mwr_tag _ _ (by decide +kernel),
      CC.PTree.gso _t'160 ___a64_mwr_tag _ _ (by decide +kernel)]
    exact CC.PTree.gss _ _ _
  · unfold resultEnv
    exact CC.PTree.gss _ _ _


noncomputable def incomingEnv {m : CC.Mem} (wordCells : Cells false m) (tagCells : Cells true m)
    (le : CC.TempEnv) (base : BitVec 64) : CC.TempEnv :=
  Arm64CiliumCallerStoreTag.resultEnv tagCells
    (Arm64CiliumCallerReturnOutcomes.resultEnv
      (Arm64CiliumCallerReturnOutcomes.reachedEnv wordCells tagCells le) base)

private theorem returned_offset (le : CC.TempEnv) (base : BitVec 64) :
    (Arm64CiliumCallerReturnMemory.resultEnv le base).get ___a64_store_off = le.get ___a64_store_off := by
  unfold Arm64CiliumCallerReturnMemory.resultEnv
  exact CC.PTree.gso _t'157 ___a64_store_off _ _ (by decide +kernel)

/-- The actual earlier effective0 survives all original reader, call-return,
materialization and store-tag temporaries; no successful offset oracle is added. -/
theorem offset_zero {m : CC.Mem} (wordCells : Cells false m) (tagCells : Cells true m)
    (le : CC.TempEnv) (base : BitVec 64) :
    (incomingEnv wordCells tagCells le base).get ___a64_store_off = some (.Vlong (0#64)) := by
  unfold incomingEnv Arm64CiliumCallerReturnOutcomes.resultEnv Arm64CiliumCallerReturnOutcomes.reachedEnv
  rw [Arm64CiliumCallerStoreTag.temp_frame tagCells _ ___a64_store_off
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel),
    Arm64CiliumCallerReturnMaterialize.temp_frame _ base ___a64_store_off
      (by decide +kernel) (by decide +kernel) (by decide +kernel),
    returned_offset,
    Arm64CiliumCallerReturnProvider.temp_frame _ ___a64_store_off
      (by decide +kernel) (by decide +kernel) (by decide +kernel),
    Arm64CiliumCallerR30Tag.temp_frame tagCells _ ___a64_store_off
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel),
    Arm64CiliumCallerR30Word.temp_frame wordCells _ ___a64_store_off
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)]
  exact (Arm64CiliumCallerMemOffset.values (Arm64CiliumCallerSPPreindex.resultEnv le)).2.2.2.2

/-- The SAME cache memory and explicit supplied tag resources feed both original
store-tag26 and memory-writer29; the actual reached temps derive effective offset0. -/
theorem advance {m supplied : CC.Mem} {locals : Locals m} {base : BitVec 64}
    (result : Arm64CiliumCallerReturnMemory.Store (supplied := supplied) locals base)
    (tags : Table true m) (wordCells : Cells false m) (tagCells : Cells true m)
    (slot : CC.Mem.load .Mint64 supplied tags.block 240 = some (.Vptr (tagCells.block ⟨30,by decide⟩) 0))
    (tag : CC.Mem.load .Mint8unsigned supplied (tagCells.block ⟨30,by decide⟩) 0 = some (.Vint (10#32)))
    (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 55
      (.State procedure .Sskip (Arm64CiliumCallerReturnOutcomes.groupCont k) (allocation m).1
        (Arm64CiliumCallerReturnOutcomes.resultEnv
          (Arm64CiliumCallerReturnOutcomes.reachedEnv wordCells tagCells le) base) result.after)
      (.State procedure after (continuation k) (allocation m).1
        (resultEnv (incomingEnv wordCells tagCells le base)) result.after) := by
  have tagRun := Arm64CiliumCallerStoreTag.advance result tags tagCells slot tag
    (Arm64CiliumCallerReturnOutcomes.resultEnv
      (Arm64CiliumCallerReturnOutcomes.reachedEnv wordCells tagCells le) base) k
  have writerRun := execute (allocation m).1 (incomingEnv wordCells tagCells le base) result.after
    (offset_zero wordCells tagCells le base) k
  exact tagRun.trans writerRun

end KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterPrefix
