import KProgFormal.ClightRefinement.Arm64CiliumCallerReturnOutcomes

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerStoreTag
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure allocation)
open Arm64CiliumCallerLinkedProgram (ge)
open Arm64CiliumCallerHeaderSource (Header Sources)
open Arm64CiliumCallerDefaults (Locals)
open Arm64CiliumCallerTables (Table)
open Arm64CiliumCallerInitializers (Cells)

private structure Parts where
  after : CC.Stmt
  tagBody : CC.Stmt
  spBranch : CC.Stmt
  otherBranch : CC.Stmt

private noncomputable def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless node.isAppOfArity ctor arity do throwError "actual original store-tag reader changed"
      pure node.getAppArgs
    let original ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerR30Word.rest)) none
    let outer ← peel original ``CC.Stmt.Ssequence 2
    let loop ← peel outer[0]! ``CC.Stmt.Sloop 2
    let body ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let tail ← peel body[1]! ``CC.Stmt.Ssequence 2
    let choose ← peel tail[0]! ``CC.Stmt.Sifthenelse 3
    let lt ← peel choose[2]! ``CC.Stmt.Sifthenelse 3
    Lean.Elab.Tactic.closeMainGoal `actual_r30_tag
      (← Lean.Meta.mkAppM ``Parts.mk #[outer[1]!,loop[0]!,choose[1]!,lt[2]!])

noncomputable def stage : CC.Stmt := Arm64CiliumCallerR30Word.rest
noncomputable def after : CC.Stmt := parts.after
noncomputable def body : CC.Stmt := parts.tagBody
noncomputable def reader : CC.Stmt := .Sloop body .Sbreak
private noncomputable def ptrTy : CC.Ty := CC.tptr CC.tuchar
private noncomputable def tableTy : CC.Ty := CC.tarray ptrTy 31
private noncomputable def reg : CC.Expr := .Etempvar ___a64_l_reg__6 CC.tulong
private noncomputable def address : CC.Expr := .Ebinop .Oadd (.Evar ___a64_tag_cells tableTy)
  (.Ecast reg CC.tuchar) (CC.tptr ptrTy)
noncomputable def pointerExpr : CC.Expr := .Ederef address ptrTy
noncomputable def tagExpr : CC.Expr := .Ederef (.Etempvar _t'13879 ptrTy) CC.tuchar
private noncomputable def selected : CC.Stmt := .Ssequence
  (.Ssequence (.Sset _t'13879 pointerExpr)
    (.Ssequence (.Sset _t'13880 tagExpr)
      (.Sset _t'158 (.Ecast (.Etempvar _t'13880 CC.tuchar) CC.tuint))))
  (.Sset _t'158 (.Ecast (.Etempvar _t'158 CC.tuint) CC.tuint))

theorem source : stage = .Ssequence reader after := rfl
theorem reader_source : body = .Ssequence
    (.Sset ___a64_l_reg__6 (.Ecast (.Econst_int (CC.Integers.Int.repr 30) CC.tuint) CC.tulong))
    (.Ssequence
      (.Sifthenelse (.Ebinop .Oeq reg (.Econst_int (CC.Integers.Int.repr 32) CC.tuint) CC.tint)
        parts.spBranch
        (.Sifthenelse (.Ebinop .Olt reg (.Econst_int (CC.Integers.Int.repr 31) CC.tuint) CC.tint)
          selected parts.otherBranch))
      (.Sset ___a64_store_tag (.Ecast (.Etempvar _t'158 CC.tuint) CC.tuchar))) := rfl

private theorem address_value {m memory : CC.Mem} (tags : Table true m)
    (le : CC.TempEnv) (read : le.get ___a64_l_reg__6 = some (.Vlong (30#64))) :
    CC.doEvalExpr ge (allocation m).1 le memory address =
      some (.Vptr tags.block (CC.Integers.Ptrofs.repr 240)) := by
  have binding : (allocation m).1.get ___a64_tag_cells = some (tags.block,tableTy) := tags.binding
  simp only [address,reg,CC.doEvalExpr,CC.lvalOfVar,binding,ite_true,read]
  rfl

/-- The original tag table expression loads the actual slot30 pointer. -/
theorem pointer_value {m memory : CC.Mem} (tags : Table true m) (tagCells : Cells true m)
    (slot : CC.Mem.load .Mint64 memory tags.block 240 = some (.Vptr (tagCells.block ⟨30,by decide⟩) 0))
    (le : CC.TempEnv) (read : le.get ___a64_l_reg__6 = some (.Vlong (30#64))) :
    CC.doEvalExpr ge (allocation m).1 le memory pointerExpr =
      some (.Vptr (tagCells.block ⟨30,by decide⟩) 0) := by
  unfold pointerExpr
  rw [CC.doEvalExpr,address_value tags le read]
  change CC.Mem.load .Mint64 memory tags.block 240 = _
  exact slot

/-- The original byte dereference reads RETURN tag10 from the same actual cell. -/
theorem tag_value {m memory : CC.Mem} (tagCells : Cells true m)
    (stored : CC.Mem.load .Mint8unsigned memory (tagCells.block ⟨30,by decide⟩) 0 = some (.Vint (10#32)))
    (le : CC.TempEnv) (read : le.get _t'13879 = some (.Vptr (tagCells.block ⟨30,by decide⟩) 0)) :
    CC.doEvalExpr ge (allocation m).1 le memory tagExpr = some (.Vint (10#32)) := by
  simp only [tagExpr,CC.doEvalExpr,read]
  change CC.Mem.load .Mint8unsigned memory (tagCells.block ⟨30,by decide⟩) 0 = _
  exact stored

private theorem reg_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr ge e le memory
      (.Ecast (.Econst_int (CC.Integers.Int.repr 30) CC.tuint) CC.tulong) = some (.Vlong (30#64)) := rfl
private theorem eq_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get ___a64_l_reg__6 = some (.Vlong (30#64))) :
    CC.doEvalExpr ge e le memory
      (.Ebinop .Oeq reg (.Econst_int (CC.Integers.Int.repr 32) CC.tuint) CC.tint) = some (.Vint (0#32)) := by
  simp only [reg,CC.doEvalExpr,read]
  rfl
private theorem lt_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get ___a64_l_reg__6 = some (.Vlong (30#64))) :
    CC.doEvalExpr ge e le memory
      (.Ebinop .Olt reg (.Econst_int (CC.Integers.Int.repr 31) CC.tuint) CC.tint) = some (.Vint (1#32)) := by
  simp only [reg,CC.doEvalExpr,read]
  rfl
private theorem cast_byte (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (id : CC.Ident)
    (read : le.get id = some (.Vint (10#32))) :
    CC.doEvalExpr ge e le memory (.Ecast (.Etempvar id CC.tuchar) CC.tuint) = some (.Vint (10#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem cast_uint (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (id : CC.Ident)
    (read : le.get id = some (.Vint (10#32))) :
    CC.doEvalExpr ge e le memory (.Ecast (.Etempvar id CC.tuint) CC.tuint) = some (.Vint (10#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem cast_tag (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (id : CC.Ident)
    (read : le.get id = some (.Vint (10#32))) :
    CC.doEvalExpr ge e le memory (.Ecast (.Etempvar id CC.tuint) CC.tuchar) = some (.Vint (10#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem temp_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (id : CC.Ident) (ty : CC.Ty) :
    CC.doEvalExpr ge e le memory (.Etempvar id ty) = le.get id := rfl
private theorem binop_type (op : CC.Binop) (left right : CC.Expr) (ty : CC.Ty) :
    CC.typeof (.Ebinop op left right ty) = ty := rfl
private theorem bools (memory : CC.Mem) :
    CC.Cop.boolVal (.Vint (0#32)) CC.tint memory = some false ∧
    CC.Cop.boolVal (.Vint (1#32)) CC.tint memory = some true := ⟨rfl,rfl⟩

noncomputable def resultEnv {m : CC.Mem} (tagCells : Cells true m) (le : CC.TempEnv) : CC.TempEnv :=
  CC.PTree.set ___a64_store_tag (CC.Val.Vint (10#32))
    (CC.PTree.set _t'158 (CC.Val.Vint (10#32))
      (CC.PTree.set _t'158 (CC.Val.Vint (10#32))
        (CC.PTree.set _t'13880 (CC.Val.Vint (10#32))
          (CC.PTree.set _t'13879 (CC.Val.Vptr (tagCells.block ⟨30,by decide⟩) 0)
            (CC.PTree.set ___a64_l_reg__6 (CC.Val.Vlong (30#64)) le)))))

/-- Actual provider-supplied slot/tag reads survive the two derived cache stores.
These are explicit supplied-memory resources, not an assumption that the provider is pure. -/
theorem resources {m supplied : CC.Mem} {locals : Locals m} {base : BitVec 64}
    (result : Arm64CiliumCallerReturnMemory.Store (supplied := supplied) locals base)
    (tags : Table true m) (tagCells : Cells true m)
    (slot : CC.Mem.load .Mint64 supplied tags.block 240 = some (.Vptr (tagCells.block ⟨30,by decide⟩) 0))
    (tag : CC.Mem.load .Mint8unsigned supplied (tagCells.block ⟨30,by decide⟩) 0 = some (.Vint (10#32))) :
    CC.Mem.load .Mint64 result.after tags.block 240 = some (.Vptr (tagCells.block ⟨30,by decide⟩) 0) ∧
    CC.Mem.load .Mint8unsigned result.after (tagCells.block ⟨30,by decide⟩) 0 = some (.Vint (10#32)) := by
  constructor
  · exact (Arm64CiliumCallerReturnMemory.bound_frame result tags.binding
      (by decide +kernel) (by decide +kernel) .Mint64 240).trans slot
  · exact (Arm64CiliumCallerReturnMemory.bound_frame result (tagCells.binding ⟨30,by decide⟩)
      (by decide +kernel) (by decide +kernel) .Mint8unsigned 0).trans tag

/-- The original store-tag loop reads the actual pointer and RETURN byte after those SAME stores. -/
theorem execute {m supplied : CC.Mem} {locals : Locals m} {base : BitVec 64}
    (result : Arm64CiliumCallerReturnMemory.Store (supplied := supplied) locals base)
    (tags : Table true m) (tagCells : Cells true m)
    (slot : CC.Mem.load .Mint64 supplied tags.block 240 = some (.Vptr (tagCells.block ⟨30,by decide⟩) 0))
    (tag : CC.Mem.load .Mint8unsigned supplied (tagCells.block ⟨30,by decide⟩) 0 = some (.Vint (10#32)))
    (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 21 (.State procedure reader k (allocation m).1 le result.after)
      (.State procedure .Sskip k (allocation m).1 (resultEnv tagCells le) result.after) := by
  have reads := resources result tags tagCells slot tag
  apply internalRun_of_steps
  all_goals
    simp only [reader,reader_source,selected,steps,InternalPath,InternalState,CC.doStep,
      reg_value,eq_value,lt_value,pointer_value tags tagCells reads.1,tag_value tagCells reads.2,
      cast_byte,cast_uint,cast_tag,temp_value,binop_type,(bools result.after).1,(bools result.after).2,
      CC.PTree.gss,resultEnv,ite_true,ite_false,Bool.false_eq_true,true_and,and_true,
      CC.E0,CC.Eapp,List.nil_append] <;> trivial

/-- Six assignments affect exactly the five original store-tag reader temporary names. -/
theorem temp_frame {m : CC.Mem} (tagCells : Cells true m) (le : CC.TempEnv) (id : CC.Ident)
    (h0 : id ≠ ___a64_l_reg__6) (h1 : id ≠ _t'13879) (h2 : id ≠ _t'13880)
    (h3 : id ≠ _t'158) (h4 : id ≠ ___a64_store_tag) :
    (resultEnv tagCells le).get id = le.get id := by
  unfold resultEnv
  rw [CC.PTree.gso ___a64_store_tag id _ _ (Ne.symm h4),
    CC.PTree.gso _t'158 id _ _ (Ne.symm h3),CC.PTree.gso _t'158 id _ _ (Ne.symm h3),
    CC.PTree.gso _t'13880 id _ _ (Ne.symm h2),CC.PTree.gso _t'13879 id _ _ (Ne.symm h1),
    CC.PTree.gso ___a64_l_reg__6 id _ _ (Ne.symm h0)]

theorem values {m : CC.Mem} (tagCells : Cells true m) (le : CC.TempEnv) :
    (resultEnv tagCells le).get ___a64_store_tag = some (.Vint (10#32)) ∧
    (resultEnv tagCells le).get ___a64_store_value = le.get ___a64_store_value := by
  constructor
  · unfold resultEnv
    exact CC.PTree.gss _ _ _
  · exact temp_frame tagCells le ___a64_store_value (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel) (by decide +kernel)

/-- Original R30-group exit3 + sequence entry1 + actual tag reader21 + continuation1 reaches the writer source. -/
theorem advance {m supplied : CC.Mem} {locals : Locals m} {base : BitVec 64}
    (result : Arm64CiliumCallerReturnMemory.Store (supplied := supplied) locals base)
    (tags : Table true m) (tagCells : Cells true m)
    (slot : CC.Mem.load .Mint64 supplied tags.block 240 = some (.Vptr (tagCells.block ⟨30,by decide⟩) 0))
    (tag : CC.Mem.load .Mint8unsigned supplied (tagCells.block ⟨30,by decide⟩) 0 = some (.Vint (10#32)))
    (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 26
      (.State procedure .Sskip (Arm64CiliumCallerReturnOutcomes.groupCont k)
        (allocation m).1 le result.after)
      (.State procedure after k (allocation m).1 (resultEnv tagCells le) result.after) := by
  have leaveGroup : InternalRun ge 3
      (.State procedure .Sskip (Arm64CiliumCallerReturnOutcomes.groupCont k)
        (allocation m).1 le result.after)
      (.State procedure stage k (allocation m).1 le result.after) := by
    refine .step trivial (CC.Step.skip_or_continue_loop1 _ _ _ _ _ _ _ _ (Or.inl rfl)) ?_
    refine .step trivial (CC.Step.break_loop2 _ _ _ _ _ _ _) ?_
    exact .step trivial (CC.Step.skip_seq _ _ _ _ _ _) (.refl _)
  have enter : InternalRun ge 1 (.State procedure stage k (allocation m).1 le result.after)
      (.State procedure reader (.Kseq after k) (allocation m).1 le result.after) := by
    rw [source]
    exact .step trivial (CC.Step.seq _ _ _ _ _ _ _) (.refl _)
  have readTag := execute result tags tagCells slot tag le (.Kseq after k)
  have leave : InternalRun ge 1
      (.State procedure .Sskip (.Kseq after k) (allocation m).1 (resultEnv tagCells le) result.after)
      (.State procedure after k (allocation m).1 (resultEnv tagCells le) result.after) :=
    .step trivial (CC.Step.skip_seq _ _ _ _ _ _) (.refl _)
  exact leaveGroup.trans (enter.trans (readTag.trans leave))

end KProgFormal.ClightRefinement.Arm64CiliumCallerStoreTag
