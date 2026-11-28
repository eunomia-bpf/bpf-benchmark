import KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterMask

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterUnmaterialize
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure allocation)
open Arm64CiliumCallerLinkedProgram (ge)
open Arm64CiliumCallerDefaults (Locals)
open Arm64CiliumCallerTables (Table)
open Arm64CiliumCallerInitializers (Cells)
open Arm64CiliumCallerHeaderTailValues (Storage)

private structure Parts where
  tags : CC.Stmt
  stack : CC.Stmt
  cold : CC.Stmt
private noncomputable def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless node.isAppOfArity ctor arity do throwError "actual original word unmaterialization changed"
      pure node.getAppArgs
    let original ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerMemoryWriterWord.after)) none
    let outer ← peel original ``CC.Stmt.Ssequence 2
    let body ← Lean.Elab.Term.elabTerm (← `(s_trusted_arm64_arm64_sim_xdp_75)) none
    let initial ← peel body ``CC.Stmt.Ssequence 2
    let tagged ← peel initial[1]! ``CC.Stmt.Ssequence 2
    let rest ← peel tagged[1]! ``CC.Stmt.Ssequence 2
    let stack ← peel rest[0]! ``CC.Stmt.Sifthenelse 3
    let returned ← peel stack[2]! ``CC.Stmt.Sifthenelse 3
    let returnedSequence ← peel returned[1]! ``CC.Stmt.Ssequence 2
    let loop ← peel returnedSequence[0]! ``CC.Stmt.Sloop 2
    let loopBody ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let guard ← peel loopBody[0]! ``CC.Stmt.Ssequence 2
    let choose ← peel guard[1]! ``CC.Stmt.Sifthenelse 3
    Lean.Elab.Tactic.closeMainGoal `actual_word_unmaterialization
      (← Lean.Meta.mkAppM ``Parts.mk #[outer[1]!,stack[1]!,choose[1]!])

noncomputable def stage : CC.Stmt := Arm64CiliumCallerMemoryWriterWord.after
noncomputable def tags : CC.Stmt := parts.tags
noncomputable def after : CC.Stmt :=
  .Sloop s_trusted_arm64_arm64_sim_xdp_77 s_trusted_arm64_arm64_sim_xdp_78
noncomputable def continuation (k : CC.Cont) : CC.Cont := .Kseq tags k
noncomputable def returnBody : CC.Stmt := .Ssequence
  (.Ssequence (.Sset _t'13863 (.Evar ___a64_numeric_return_valid CC.tuchar))
    (.Sifthenelse (.Eunop .Onotbool (.Etempvar _t'13863 CC.tuchar) CC.tint) parts.cold .Sskip))
  (.Sset ___a64_unmat_base__1 (.Evar ___a64_numeric_return CC.tulong))

theorem source : stage = .Ssequence
    (.Ssequence
      (.Sifthenelse (.Ebinop .Oeq (.Etempvar ___a64_store_tag CC.tuchar)
        (.Econst_int (CC.Integers.Int.repr 4) CC.tuint) CC.tint)
        (.Sset _t'175 (.Econst_int (CC.Integers.Int.repr 1) CC.tint))
        s_trusted_arm64_arm64_sim_xdp_74)
      (.Sifthenelse (.Etempvar _t'175 CC.tint)
        (.Ssequence (.Sloop s_trusted_arm64_arm64_sim_xdp_75 s_trusted_arm64_arm64_sim_xdp_76) after) .Sskip))
    tags := rfl
theorem guard_source : s_trusted_arm64_arm64_sim_xdp_74 = .Sset _t'175
    (.Ecast (.Ebinop .Oeq (.Etempvar ___a64_store_tag CC.tuchar)
      (.Econst_int (CC.Integers.Int.repr 10) CC.tuint) CC.tint) CC.tbool) := rfl
theorem body_source : s_trusted_arm64_arm64_sim_xdp_75 = .Ssequence
    (.Sset ___a64_unmat_value (.Etempvar ___a64_stw_value CC.tulong))
    (.Ssequence (.Sset ___a64_unmat_tag (.Ecast (.Etempvar ___a64_store_tag CC.tuchar) CC.tuchar))
      (.Ssequence
        (.Sifthenelse (.Ebinop .Oeq (.Etempvar ___a64_unmat_tag CC.tuchar)
          (.Econst_int (CC.Integers.Int.repr 4) CC.tuint) CC.tint) parts.stack
          (.Sifthenelse (.Ebinop .Oeq (.Etempvar ___a64_unmat_tag CC.tuchar)
            (.Econst_int (CC.Integers.Int.repr 10) CC.tuint) CC.tint)
            (.Ssequence (.Sloop returnBody .Sbreak)
              (.Sset ___a64_unmat_value (.Ebinop .Osub (.Etempvar ___a64_unmat_value CC.tulong)
                (.Etempvar ___a64_unmat_base__1 CC.tulong) CC.tulong))) .Sskip))
        (.Sset ___a64_stw_payload (.Etempvar ___a64_unmat_value CC.tulong)))) := rfl
theorem break_source : s_trusted_arm64_arm64_sim_xdp_76 = .Sbreak := rfl

theorem cache_values {m supplied : CC.Mem} {locals : Locals m} {base : BitVec 64}
    (cache : Arm64CiliumCallerReturnMemory.Store (supplied := supplied) locals base)
    (header : Storage m)
    (word : Arm64CiliumCallerMemoryWriterWord.Store (before := cache.after) header base)
    (le : CC.TempEnv) :
    CC.doEvalExpr ge (allocation m).1 le word.after (.Evar ___a64_numeric_return CC.tulong) = some (.Vlong base) ∧
    CC.doEvalExpr ge (allocation m).1 le word.after (.Evar ___a64_numeric_return_valid CC.tuchar) = some (.Vint (1#32)) := by
  have reads := Arm64CiliumCallerMemoryWriterWord.cache_values cache header word
  constructor
  · have binding : (allocation m).1.get ___a64_numeric_return = some (locals.block 3,CC.tulong) := locals.binding 3
    simp only [CC.doEvalExpr,CC.lvalOfVar,binding,ite_true]
    change CC.Mem.load .Mint64 word.after (locals.block 3) 0 = _
    exact reads.1
  · have binding : (allocation m).1.get ___a64_numeric_return_valid = some (locals.block 5,CC.tuchar) := locals.binding 5
    simp only [CC.doEvalExpr,CC.lvalOfVar,binding,ite_true]
    change CC.Mem.load .Mint8unsigned word.after (locals.block 5) 0 = _
    exact reads.2

private theorem tag4 (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (id : CC.Ident)
    (read : le.get id = some (.Vint (10#32))) :
    CC.doEvalExpr ge e le memory (.Ebinop .Oeq (.Etempvar id CC.tuchar)
      (.Econst_int (CC.Integers.Int.repr 4) CC.tuint) CC.tint) = some (.Vint (0#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem tag10 (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (id : CC.Ident)
    (read : le.get id = some (.Vint (10#32))) :
    CC.doEvalExpr ge e le memory (.Ebinop .Oeq (.Etempvar id CC.tuchar)
      (.Econst_int (CC.Integers.Int.repr 10) CC.tuint) CC.tint) = some (.Vint (1#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem guard_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get ___a64_store_tag = some (.Vint (10#32))) :
    CC.doEvalExpr ge e le memory (.Ecast (.Ebinop .Oeq (.Etempvar ___a64_store_tag CC.tuchar)
      (.Econst_int (CC.Integers.Int.repr 10) CC.tuint) CC.tint) CC.tbool) = some (.Vint (1#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem tag_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get ___a64_store_tag = some (.Vint (10#32))) :
    CC.doEvalExpr ge e le memory (.Ecast (.Etempvar ___a64_store_tag CC.tuchar) CC.tuchar) = some (.Vint (10#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem not_valid (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get _t'13863 = some (.Vint (1#32))) :
    CC.doEvalExpr ge e le memory (.Eunop .Onotbool (.Etempvar _t'13863 CC.tuchar) CC.tint) =
      some (.Vint (0#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem subtract (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (base : BitVec 64)
    (left : le.get ___a64_unmat_value = some (.Vlong base))
    (right : le.get ___a64_unmat_base__1 = some (.Vlong base)) :
    CC.doEvalExpr ge e le memory (.Ebinop .Osub (.Etempvar ___a64_unmat_value CC.tulong)
      (.Etempvar ___a64_unmat_base__1 CC.tulong) CC.tulong) = some (.Vlong (0#64)) := by
  simp only [CC.doEvalExpr,left,right]
  change some (CC.Val.Vlong (base-base)) = some (.Vlong (0#64))
  rw [BitVec.sub_self]
private theorem temp_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (id : CC.Ident) (ty : CC.Ty) :
    CC.doEvalExpr ge e le memory (.Etempvar id ty) = le.get id := rfl
private theorem binop_type (op : CC.Binop) (a b : CC.Expr) (ty : CC.Ty) :
    CC.typeof (.Ebinop op a b ty) = ty := rfl
private theorem temp_type (id : CC.Ident) (ty : CC.Ty) :
    CC.typeof (.Etempvar id ty) = ty := rfl
private theorem unop_type (op : CC.Unop) (a : CC.Expr) (ty : CC.Ty) :
    CC.typeof (.Eunop op a ty) = ty := rfl
private theorem true_value (memory : CC.Mem) : CC.Cop.boolVal (.Vint (1#32)) CC.tint memory = some true := rfl
private theorem false_value (memory : CC.Mem) : CC.Cop.boolVal (.Vint (0#32)) CC.tint memory = some false := rfl
private theorem stw175 (le : CC.TempEnv) (value : CC.Val) :
    (CC.PTree.set _t'175 value le).get ___a64_stw_value = le.get ___a64_stw_value :=
  CC.PTree.gso _ _ _ _ (by decide +kernel)
private theorem tag175 (le : CC.TempEnv) (value : CC.Val) :
    (CC.PTree.set _t'175 value le).get ___a64_store_tag = le.get ___a64_store_tag :=
  CC.PTree.gso _ _ _ _ (by decide +kernel)
private theorem tagcopy (le : CC.TempEnv) (value : CC.Val) :
    (CC.PTree.set ___a64_unmat_value value le).get ___a64_store_tag = le.get ___a64_store_tag :=
  CC.PTree.gso _ _ _ _ (by decide +kernel)
private theorem valueTag (le : CC.TempEnv) (value : CC.Val) :
    (CC.PTree.set ___a64_unmat_tag value le).get ___a64_unmat_value = le.get ___a64_unmat_value :=
  CC.PTree.gso _ _ _ _ (by decide +kernel)
private theorem valueValid (le : CC.TempEnv) (value : CC.Val) :
    (CC.PTree.set _t'13863 value le).get ___a64_unmat_value = le.get ___a64_unmat_value :=
  CC.PTree.gso _ _ _ _ (by decide +kernel)
private theorem valueBase (le : CC.TempEnv) (value : CC.Val) :
    (CC.PTree.set ___a64_unmat_base__1 value le).get ___a64_unmat_value = le.get ___a64_unmat_value :=
  CC.PTree.gso _ _ _ _ (by decide +kernel)

noncomputable def resultEnv (le : CC.TempEnv) (base : BitVec 64) : CC.TempEnv :=
  CC.PTree.set ___a64_stw_payload (CC.Val.Vlong (0#64))
    (CC.PTree.set ___a64_unmat_value (CC.Val.Vlong (0#64))
      (CC.PTree.set ___a64_unmat_base__1 (CC.Val.Vlong base)
        (CC.PTree.set _t'13863 (CC.Val.Vint (1#32))
          (CC.PTree.set ___a64_unmat_tag (CC.Val.Vint (10#32))
            (CC.PTree.set ___a64_unmat_value (CC.Val.Vlong base)
              (CC.PTree.set _t'175 (CC.Val.Vint (1#32)) le))))))

/-- Actual word-store cache frames supply valid1 and the same scalar base,
so the original RETURN10 path does not call the provider again. It computes
payload=base-base=0 and stops before the original volatile payload-store loop. -/
theorem execute {m supplied : CC.Mem} {locals : Locals m} {base : BitVec 64}
    (cache : Arm64CiliumCallerReturnMemory.Store (supplied := supplied) locals base)
    (header : Storage m)
    (word : Arm64CiliumCallerMemoryWriterWord.Store (before := cache.after) header base)
    (le : CC.TempEnv) (tag : le.get ___a64_store_tag = some (.Vint (10#32)))
    (stored : le.get ___a64_stw_value = some (.Vlong base)) (k : CC.Cont) :
    InternalRun ge 35 (.State procedure stage k (allocation m).1 le word.after)
      (.State procedure after (continuation k) (allocation m).1 (resultEnv le base) word.after) := by
  have returned (temps : CC.TempEnv) := (cache_values cache header word temps).1
  have valid (temps : CC.TempEnv) := (cache_values cache header word temps).2
  have sub (temps : CC.TempEnv)
      (left : temps.get ___a64_unmat_value = some (.Vlong base))
      (right : temps.get ___a64_unmat_base__1 = some (.Vlong base)) :=
    subtract (allocation m).1 temps word.after base left right
  apply internalRun_of_steps
  all_goals
    simp only [source,guard_source,body_source,break_source,returnBody,
      steps,InternalPath,InternalState,CC.doStep,tag4,tag10,guard_value,tag_value,not_valid,
      returned,valid,sub,temp_value,stw175,tag175,tagcopy,valueTag,valueValid,valueBase,tag,stored,
      CC.PTree.gss,binop_type,temp_type,unop_type,true_value,false_value,resultEnv,continuation,
      ite_true,ite_false,Bool.false_eq_true,eq_self,true_and,and_true,CC.E0,CC.Eapp,List.nil_append] <;> trivial


theorem temp_frame (le : CC.TempEnv) (base : BitVec 64) (id : CC.Ident)
    (h0 : id ≠ _t'175) (h1 : id ≠ ___a64_unmat_value) (h2 : id ≠ ___a64_unmat_tag)
    (h3 : id ≠ _t'13863) (h4 : id ≠ ___a64_unmat_base__1) (h5 : id ≠ ___a64_stw_payload) :
    (resultEnv le base).get id = le.get id := by
  unfold resultEnv
  rw [CC.PTree.gso ___a64_stw_payload id _ _ (Ne.symm h5),
    CC.PTree.gso ___a64_unmat_value id _ _ (Ne.symm h1),
    CC.PTree.gso ___a64_unmat_base__1 id _ _ (Ne.symm h4),
    CC.PTree.gso _t'13863 id _ _ (Ne.symm h3),
    CC.PTree.gso ___a64_unmat_tag id _ _ (Ne.symm h2),
    CC.PTree.gso ___a64_unmat_value id _ _ (Ne.symm h1),CC.PTree.gso _t'175 id _ _ (Ne.symm h0)]

theorem values (le : CC.TempEnv) (base : BitVec 64) :
    (resultEnv le base).get ___a64_stw_payload = some (.Vlong (0#64)) ∧
    (resultEnv le base).get ___a64_unmat_value = some (.Vlong (0#64)) ∧
    (resultEnv le base).get ___a64_unmat_base__1 = some (.Vlong base) := by
  refine ⟨?_,?_,?_⟩
  · unfold resultEnv
    exact CC.PTree.gss _ _ _
  · unfold resultEnv
    rw [CC.PTree.gso ___a64_stw_payload ___a64_unmat_value _ _ (by decide +kernel)]
    exact CC.PTree.gss _ _ _
  · unfold resultEnv
    rw [CC.PTree.gso ___a64_stw_payload ___a64_unmat_base__1 _ _ (by decide +kernel),
      CC.PTree.gso ___a64_unmat_value ___a64_unmat_base__1 _ _ (by decide +kernel)]
    exact CC.PTree.gss _ _ _

noncomputable def incomingEnv {m : CC.Mem} (wordCells : Cells false m) (tagCells : Cells true m)
    (le : CC.TempEnv) (base : BitVec 64) : CC.TempEnv :=
  Arm64CiliumCallerMemoryWriterMask.resultEnv
    (Arm64CiliumCallerMemoryWriterAddress.resultEnv
      (Arm64CiliumCallerMemoryWriterAddress.incomingEnv wordCells tagCells le base
        Arm64CiliumCallerSPPreindex.delta) Arm64CiliumCallerSPPreindex.delta base) base

theorem incoming_value {m : CC.Mem} (wordCells : Cells false m) (tagCells : Cells true m)
    (le : CC.TempEnv) (base : BitVec 64) :
    (incomingEnv wordCells tagCells le base).get ___a64_stw_value = some (.Vlong base) :=
  (Arm64CiliumCallerMemoryWriterMask.values _ base).1

theorem incoming_tag {m : CC.Mem} (wordCells : Cells false m) (tagCells : Cells true m)
    (le : CC.TempEnv) (base : BitVec 64) :
    (incomingEnv wordCells tagCells le base).get ___a64_store_tag = some (.Vint (10#32)) := by
  unfold incomingEnv Arm64CiliumCallerMemoryWriterAddress.incomingEnv
    Arm64CiliumCallerMemoryWriterSP.incomingEnv Arm64CiliumCallerMemoryWriterPrefix.incomingEnv
  rw [
Arm64CiliumCallerMemoryWriterMask.temp_frame _ base ___a64_store_tag
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel),
    Arm64CiliumCallerMemoryWriterAddress.temp_frame _ Arm64CiliumCallerSPPreindex.delta base ___a64_store_tag
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel),
    Arm64CiliumCallerMemoryWriterSP.temp_frame _ Arm64CiliumCallerSPPreindex.delta ___a64_store_tag
      (by decide +kernel) (by decide +kernel) (by decide +kernel),
    Arm64CiliumCallerMemoryWriterGuard.temp_frame _ ___a64_store_tag
      (by decide +kernel) (by decide +kernel),
    Arm64CiliumCallerMemoryWriterPrefix.temp_frame _ ___a64_store_tag
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)]
  exact (Arm64CiliumCallerStoreTag.values tagCells _).1

/-- The actual129-step word-store route and the original35-step RETURN
unmaterialization share the SAME real word heap and cache reads. The original
volatile payload/tag stores are the next boundary, not executed here. -/
theorem advance {m supplied : CC.Mem} {locals : Locals m} {base : BitVec 64}
    (cache : Arm64CiliumCallerReturnMemory.Store (supplied := supplied) locals base)
    (header : Storage m) (scalars : Arm64CiliumCallerEntryScalars.Locals m)
    (tags : Table true m) (wordCells : Cells false m) (tagCells : Cells true m)
    (access : supplied.access = (allocation m).2.access)
    (spRead : CC.Mem.load .Mint64 supplied (scalars.block 0) 0 =
      some (.Vlong Arm64CiliumCallerSPPreindex.delta))
    (abi : CC.Mem.load .Mint8unsigned supplied (header.block 6) 0 = some (.Vint (1#32)))
    (slot : CC.Mem.load .Mint64 supplied tags.block 240 = some (.Vptr (tagCells.block ⟨30,by decide⟩) 0))
    (tag : CC.Mem.load .Mint8unsigned supplied (tagCells.block ⟨30,by decide⟩) 0 = some (.Vint (10#32)))
    (le : CC.TempEnv) (width : le.get ___a64_l_width = some (.Vint (8#32))) (k : CC.Cont) :
    ∃ word : Arm64CiliumCallerMemoryWriterWord.Store (before := cache.after) header base,
      InternalRun ge 164
        (.State procedure .Sskip (Arm64CiliumCallerReturnOutcomes.groupCont k) (allocation m).1
          (Arm64CiliumCallerReturnOutcomes.resultEnv
            (Arm64CiliumCallerReturnOutcomes.reachedEnv wordCells tagCells le) base) cache.after)
        (.State procedure after
          (continuation (Arm64CiliumCallerMemoryWriterAddress.continuation
            (Arm64CiliumCallerMemoryWriterPrefix.continuation k))) (allocation m).1
          (resultEnv (incomingEnv wordCells tagCells le base) base) word.after) := by
  obtain ⟨word,written⟩ := Arm64CiliumCallerMemoryWriterMask.advance cache header scalars tags wordCells tagCells
    access spRead abi slot tag le width k
  have unmat := execute cache header word (incomingEnv wordCells tagCells le base)
    (incoming_tag wordCells tagCells le base) (incoming_value wordCells tagCells le base)
    (Arm64CiliumCallerMemoryWriterAddress.continuation (Arm64CiliumCallerMemoryWriterPrefix.continuation k))
  exact ⟨word,written.trans unmat⟩

end KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterUnmaterialize
