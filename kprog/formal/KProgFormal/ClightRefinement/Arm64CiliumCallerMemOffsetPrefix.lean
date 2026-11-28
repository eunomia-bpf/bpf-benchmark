import KProgFormal.ClightRefinement.Arm64CiliumCallerLinkedSPPreindex

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerMemOffsetPrefix
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure allocation)
open Arm64CiliumCallerLinkedProgram (ge)
open Arm64CiliumCallerHeaderSource (Header Sources)
open Arm64CiliumCallerEntryScalars (Locals)

private structure Parts where
  rest : CC.Stmt
  hasSetup : CC.Stmt
  sourceSetup : CC.Stmt
  immSet : CC.Stmt
  indexSet : CC.Stmt
  selectIndex : CC.Stmt
  indexed : CC.Stmt
  afterIndex : CC.Stmt

private noncomputable def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless node.isAppOfArity ctor arity do throwError "actual caller memory-offset prefix changed"
      pure node.getAppArgs
    let original ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerSPAlignment.afterGroup)) none
    let outer ← peel original ``CC.Stmt.Ssequence 2
    let loop ← peel outer[0]! ``CC.Stmt.Sloop 2
    let b0 ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let b1 ← peel b0[1]! ``CC.Stmt.Ssequence 2
    let b2 ← peel b1[1]! ``CC.Stmt.Ssequence 2
    let b3 ← peel b2[1]! ``CC.Stmt.Ssequence 2
    let b4 ← peel b3[1]! ``CC.Stmt.Ssequence 2
    let choose ← peel b4[0]! ``CC.Stmt.Sifthenelse 3
    Lean.Elab.Tactic.closeMainGoal `actual_mem_offset_prefix
      (← Lean.Meta.mkAppM ``Parts.mk #[outer[1]!,b0[0]!,b1[0]!,b2[0]!,b3[0]!,b4[0]!,choose[1]!,b4[1]!])

noncomputable def stage : CC.Stmt := Arm64CiliumCallerSPAlignment.afterGroup
noncomputable def rest : CC.Stmt := parts.rest
private noncomputable def hasSetup : CC.Stmt := parts.hasSetup
private noncomputable def sourceSetup : CC.Stmt := parts.sourceSetup
private noncomputable def immSet : CC.Stmt := parts.immSet
private noncomputable def indexSet : CC.Stmt := parts.indexSet
private noncomputable def selectIndex : CC.Stmt := parts.selectIndex
noncomputable def afterIndex : CC.Stmt := parts.afterIndex
noncomputable def body : CC.Stmt := .Ssequence hasSetup (.Ssequence sourceSetup
  (.Ssequence immSet (.Ssequence indexSet (.Ssequence selectIndex afterIndex))))

theorem source : stage = .Ssequence (.Sloop body .Sbreak) rest := rfl
private theorem has_source : hasSetup = .Ssequence
    (.Sifthenelse (.Ebinop .One (.Econst_int (255#32) CC.tuint) (.Econst_int (255#32) CC.tuint) CC.tint)
      (.Sset _t'140 (.Ecast (.Econst_int (1#32) CC.tint) CC.tint))
      (.Sset _t'140 (.Ecast (.Econst_int (0#32) CC.tint) CC.tint)))
    (.Sset ___a64_mbo_has_index (.Ecast (.Ecast (.Etempvar _t'140 CC.tint) CC.tuchar) CC.tuchar)) := rfl
private theorem source_source : sourceSetup = .Ssequence
    (.Sifthenelse (.Etempvar ___a64_mbo_has_index CC.tuchar)
      (.Sset _t'141 (.Ecast (.Econst_int (0#32) CC.tuint) CC.tuint))
      (.Sset _t'141 (.Ecast (.Econst_int (1#32) CC.tuint) CC.tuint)))
    (.Sset ___a64_mbo_isrc (.Ecast (.Ecast (.Etempvar _t'141 CC.tuint) CC.tuchar) CC.tuchar)) := rfl
private theorem imm_source : immSet =
    .Sset ___a64_mbo_imm (.Econst_long Arm64CiliumCallerSPPreindex.delta CC.tulong) := rfl
private theorem index_source : indexSet =
    .Sset ___a64_mbo_index (.Ecast (.Econst_int (0#32) CC.tint) CC.tulong) := rfl
private theorem select_source : selectIndex = .Sifthenelse
    (.Ebinop .Oeq (.Etempvar ___a64_mbo_isrc CC.tuchar) (.Econst_int (0#32) CC.tuint) CC.tint)
    parts.indexed .Sskip := rfl

noncomputable def resultEnv (le : CC.TempEnv) : CC.TempEnv :=
  CC.PTree.set ___a64_mbo_index (CC.Val.Vlong (0#64))
    (CC.PTree.set ___a64_mbo_imm (CC.Val.Vlong Arm64CiliumCallerSPPreindex.delta)
      (CC.PTree.set ___a64_mbo_isrc (CC.Val.Vint (1#32))
        (CC.PTree.set _t'141 (CC.Val.Vint (1#32))
          (CC.PTree.set ___a64_mbo_has_index (CC.Val.Vint (0#32))
            (CC.PTree.set _t'140 (CC.Val.Vint (0#32)) le)))))

private theorem temp_value (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (id : CC.Ident) (ty : CC.Ty) :
    CC.doEvalExpr world e le memory (.Etempvar id ty) = le.get id := rfl

private theorem has_condition (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e le memory
      (.Ebinop .One (.Econst_int (255#32) CC.tuint) (.Econst_int (255#32) CC.tuint) CC.tint) =
      some (.Vint (0#32)) := rfl
private theorem zero_value (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e le memory (.Ecast (.Econst_int (0#32) CC.tint) CC.tint) =
      some (.Vint (0#32)) := rfl
private theorem one_value (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e le memory (.Ecast (.Econst_int (1#32) CC.tuint) CC.tuint) =
      some (.Vint (1#32)) := rfl
private theorem has_value (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get _t'140 = some (.Vint (0#32))) :
    CC.doEvalExpr world e le memory (.Ecast (.Ecast (.Etempvar _t'140 CC.tint) CC.tuchar) CC.tuchar) =
      some (.Vint (0#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem isrc_value (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get _t'141 = some (.Vint (1#32))) :
    CC.doEvalExpr world e le memory (.Ecast (.Ecast (.Etempvar _t'141 CC.tuint) CC.tuchar) CC.tuchar) =
      some (.Vint (1#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem select_value (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get ___a64_mbo_isrc = some (.Vint (1#32))) :
    CC.doEvalExpr world e le memory
      (.Ebinop .Oeq (.Etempvar ___a64_mbo_isrc CC.tuchar) (.Econst_int (0#32) CC.tuint) CC.tint) =
      some (.Vint (0#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem immediate_value (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e le memory (.Econst_long Arm64CiliumCallerSPPreindex.delta CC.tulong) =
      some (.Vlong Arm64CiliumCallerSPPreindex.delta) := rfl
private theorem index_value (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e le memory (.Ecast (.Econst_int (0#32) CC.tint) CC.tulong) =
      some (.Vlong (0#64)) := rfl
private theorem bool_zero (memory : CC.Mem) :
    CC.Cop.boolVal (.Vint (0#32)) CC.tint memory = some false ∧
    CC.Cop.boolVal (.Vint (0#32)) CC.tuchar memory = some false := ⟨rfl,rfl⟩

/-- The six actual assignments retain every other temporary lookup. -/
theorem temp_frame (le : CC.TempEnv) (id : CC.Ident)
    (h0 : id ≠ _t'140) (h1 : id ≠ ___a64_mbo_has_index) (h2 : id ≠ _t'141)
    (h3 : id ≠ ___a64_mbo_isrc) (h4 : id ≠ ___a64_mbo_imm) (h5 : id ≠ ___a64_mbo_index) :
    (resultEnv le).get id = le.get id := by
  unfold resultEnv
  rw [CC.PTree.gso ___a64_mbo_index id _ _ (Ne.symm h5),
    CC.PTree.gso ___a64_mbo_imm id _ _ (Ne.symm h4),
    CC.PTree.gso ___a64_mbo_isrc id _ _ (Ne.symm h3),
    CC.PTree.gso _t'141 id _ _ (Ne.symm h2),
    CC.PTree.gso ___a64_mbo_has_index id _ _ (Ne.symm h1),
    CC.PTree.gso _t'140 id _ _ (Ne.symm h0)]

/-- Actual flags/immediate/index values, before the original numeric offset computation. -/
theorem values (le : CC.TempEnv) :
    (resultEnv le).get ___a64_mbo_has_index = some (.Vint (0#32)) ∧
    (resultEnv le).get ___a64_mbo_isrc = some (.Vint (1#32)) ∧
    (resultEnv le).get ___a64_mbo_imm = some (.Vlong Arm64CiliumCallerSPPreindex.delta) ∧
    (resultEnv le).get ___a64_mbo_index = some (.Vlong (0#64)) := by
  have keys : ___a64_mbo_index ≠ ___a64_mbo_has_index ∧
      ___a64_mbo_imm ≠ ___a64_mbo_has_index ∧ ___a64_mbo_isrc ≠ ___a64_mbo_has_index ∧
      _t'141 ≠ ___a64_mbo_has_index ∧ ___a64_mbo_index ≠ ___a64_mbo_isrc ∧
      ___a64_mbo_imm ≠ ___a64_mbo_isrc ∧ ___a64_mbo_index ≠ ___a64_mbo_imm := by decide +kernel
  rcases keys with ⟨a,b,c,d,e,f,g⟩
  unfold resultEnv
  refine ⟨?_,?_,?_,?_⟩
  · rw [CC.PTree.gso ___a64_mbo_index ___a64_mbo_has_index _ _ a,
      CC.PTree.gso ___a64_mbo_imm ___a64_mbo_has_index _ _ b,
      CC.PTree.gso ___a64_mbo_isrc ___a64_mbo_has_index _ _ c,
      CC.PTree.gso _t'141 ___a64_mbo_has_index _ _ d,CC.PTree.gss]
  · rw [CC.PTree.gso ___a64_mbo_index ___a64_mbo_isrc _ _ e,
      CC.PTree.gso ___a64_mbo_imm ___a64_mbo_isrc _ _ f,CC.PTree.gss]
  · rw [CC.PTree.gso ___a64_mbo_index ___a64_mbo_imm _ _ g,CC.PTree.gss]
  · exact CC.PTree.gss _ _ _

private theorem selected_after (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e
      (CC.PTree.set ___a64_mbo_index (CC.Val.Vlong (0#64))
        (CC.PTree.set ___a64_mbo_imm (CC.Val.Vlong Arm64CiliumCallerSPPreindex.delta)
          (CC.PTree.set ___a64_mbo_isrc (CC.Val.Vint (1#32))
            (CC.PTree.set _t'141 (CC.Val.Vint (1#32))
              (CC.PTree.set ___a64_mbo_has_index (CC.Val.Vint (0#32))
                (CC.PTree.set _t'140 (CC.Val.Vint (0#32)) le))))))
      memory
      (.Ebinop .Oeq (.Etempvar ___a64_mbo_isrc CC.tuchar) (.Econst_int (0#32) CC.tuint) CC.tint) =
      some (.Vint (0#32)) :=
  select_value world e (resultEnv le) memory (values le).2.1

/-- The original flag/immediate/index prefix, retaining its unselected index branch. -/
theorem execute (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (k : CC.Cont) :
    InternalRun world 25 (.State procedure stage k e le memory)
      (.State procedure afterIndex (.Kloop1 body .Sbreak (.Kseq rest k)) e (resultEnv le) memory) := by
  apply internalRun_of_steps
  all_goals
    simp only [source,body,has_source,source_source,imm_source,index_source,select_source,
      steps,InternalPath,InternalState,CC.doStep,CC.typeof,temp_value,
      has_condition,zero_value,one_value,has_value,isrc_value,selected_after,immediate_value,index_value,
      (bool_zero memory).1,(bool_zero memory).2,CC.PTree.gss,
      resultEnv,ite_true,ite_false,Bool.false_eq_true,true_and,and_true,CC.E0,CC.Eapp,List.nil_append] <;> trivial

/-- The real preindex write and SP-group exit feed the actual next memory-offset prefix. -/
theorem advance {m before : CC.Mem} (header : Header m) (sources : Sources m) (scalars : Locals m)
    (access : before.access = (allocation m).2.access)
    (pointers : Arm64CiliumCallerHeaderSequence.Initialized header sources before 12)
    (reads : ∀ i : Fin 2,CC.Mem.load (Arm64CiliumCallerEntryScalars.chunk i)
      before (scalars.block i) 0 = some (Arm64CiliumCallerEntryScalars.value i))
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ result : Arm64CiliumCallerSPWriteMemory.Store (before := before) header sources scalars,
      InternalRun ge 87
        (.State procedure Arm64CiliumCallerSPAlignment.tail
          (.Kloop1 Arm64CiliumCallerSPAlignment.body .Sbreak (.Kseq stage k))
          (allocation m).1 le before)
        (.State procedure afterIndex (.Kloop1 body .Sbreak (.Kseq rest k)) (allocation m).1
          (resultEnv (Arm64CiliumCallerSPPreindex.resultEnv le)) result.after) ∧
      Arm64EntryMemory.borrowed result.after.nextblock .Mint64 result.after (.Vptr header.block 0)
        Arm64Program._sp = some (.Vlong Arm64CiliumCallerSPPreindex.delta) := by
  let groupCont := CC.Cont.Kloop1 Arm64CiliumCallerSPAlignment.body .Sbreak (.Kseq stage k)
  obtain ⟨result,run,read⟩ :=
    Arm64CiliumCallerLinkedSPPreindex.execute header sources scalars access pointers reads le groupCont
  have bridgeRun : InternalRun ge 3
      (.State procedure .Sskip groupCont (allocation m).1
        (Arm64CiliumCallerSPPreindex.resultEnv le) result.after)
      (.State procedure stage k (allocation m).1
        (Arm64CiliumCallerSPPreindex.resultEnv le) result.after) := by
    apply internalRun_of_steps
    all_goals
      simp only [steps,InternalPath,InternalState,CC.doStep,groupCont,CC.E0,CC.Eapp,List.nil_append] <;> trivial
  have offsetRun := execute ge (allocation m).1 (Arm64CiliumCallerSPPreindex.resultEnv le) result.after k
  exact ⟨result,run.trans (bridgeRun.trans offsetRun),read⟩

end KProgFormal.ClightRefinement.Arm64CiliumCallerMemOffsetPrefix
