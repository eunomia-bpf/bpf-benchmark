import KProgFormal.ClightRefinement.Arm64CiliumCallerR30Word

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerR30Tag
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure allocation)
open Arm64CiliumCallerLinkedProgram (ge)
open Arm64CiliumCallerHeaderSource (Header Sources)
open Arm64CiliumCallerEntryScalars (Locals)
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
      unless node.isAppOfArity ctor arity do throwError "actual R30 tag reader changed"
      pure node.getAppArgs
    let original ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerR30Word.afterWord)) none
    let outer ← peel original ``CC.Stmt.Ssequence 2
    let loop ← peel outer[0]! ``CC.Stmt.Sloop 2
    let body ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let tail ← peel body[1]! ``CC.Stmt.Ssequence 2
    let choose ← peel tail[0]! ``CC.Stmt.Sifthenelse 3
    let lt ← peel choose[2]! ``CC.Stmt.Sifthenelse 3
    Lean.Elab.Tactic.closeMainGoal `actual_r30_tag
      (← Lean.Meta.mkAppM ``Parts.mk #[outer[1]!,loop[0]!,choose[1]!,lt[2]!])

noncomputable def stage : CC.Stmt := Arm64CiliumCallerR30Word.afterWord
noncomputable def after : CC.Stmt := parts.after
noncomputable def body : CC.Stmt := parts.tagBody
noncomputable def reader : CC.Stmt := .Sloop body .Sbreak
private noncomputable def ptrTy : CC.Ty := CC.tptr CC.tuchar
private noncomputable def tableTy : CC.Ty := CC.tarray ptrTy 31
private noncomputable def reg : CC.Expr := .Etempvar ___a64_l_reg__5 CC.tulong
private noncomputable def address : CC.Expr := .Ebinop .Oadd (.Evar ___a64_tag_cells tableTy)
  (.Ecast reg CC.tuchar) (CC.tptr ptrTy)
noncomputable def pointerExpr : CC.Expr := .Ederef address ptrTy
noncomputable def tagExpr : CC.Expr := .Ederef (.Etempvar _t'13883 ptrTy) CC.tuchar
private noncomputable def selected : CC.Stmt := .Ssequence
  (.Ssequence (.Sset _t'13883 pointerExpr)
    (.Ssequence (.Sset _t'13884 tagExpr)
      (.Sset _t'155 (.Ecast (.Etempvar _t'13884 CC.tuchar) CC.tuint))))
  (.Sset _t'155 (.Ecast (.Etempvar _t'155 CC.tuint) CC.tuint))

theorem source : stage = .Ssequence reader after := rfl
theorem reader_source : body = .Ssequence
    (.Sset ___a64_l_reg__5 (.Ecast (.Econst_int (CC.Integers.Int.repr 30) CC.tuint) CC.tulong))
    (.Ssequence
      (.Sifthenelse (.Ebinop .Oeq reg (.Econst_int (CC.Integers.Int.repr 32) CC.tuint) CC.tint)
        parts.spBranch
        (.Sifthenelse (.Ebinop .Olt reg (.Econst_int (CC.Integers.Int.repr 31) CC.tuint) CC.tint)
          selected parts.otherBranch))
      (.Sset ___a64_read_tag__1 (.Ecast (.Etempvar _t'155 CC.tuint) CC.tuchar))) := rfl

private theorem address_value {m memory : CC.Mem} (tags : Table true m)
    (le : CC.TempEnv) (read : le.get ___a64_l_reg__5 = some (.Vlong (30#64))) :
    CC.doEvalExpr ge (allocation m).1 le memory address =
      some (.Vptr tags.block (CC.Integers.Ptrofs.repr 240)) := by
  have binding : (allocation m).1.get ___a64_tag_cells = some (tags.block,tableTy) := tags.binding
  simp only [address,reg,CC.doEvalExpr,CC.lvalOfVar,binding,ite_true,read]
  rfl

/-- The original tag table expression loads the actual slot30 pointer. -/
theorem pointer_value {m memory : CC.Mem} (tags : Table true m) (tagCells : Cells true m)
    (slot : CC.Mem.load .Mint64 memory tags.block 240 = some (.Vptr (tagCells.block ⟨30,by decide⟩) 0))
    (le : CC.TempEnv) (read : le.get ___a64_l_reg__5 = some (.Vlong (30#64))) :
    CC.doEvalExpr ge (allocation m).1 le memory pointerExpr =
      some (.Vptr (tagCells.block ⟨30,by decide⟩) 0) := by
  unfold pointerExpr
  rw [CC.doEvalExpr,address_value tags le read]
  change CC.Mem.load .Mint64 memory tags.block 240 = _
  exact slot

/-- The original byte dereference reads RETURN tag10 from the same actual cell. -/
theorem tag_value {m memory : CC.Mem} (tagCells : Cells true m)
    (stored : CC.Mem.load .Mint8unsigned memory (tagCells.block ⟨30,by decide⟩) 0 = some (.Vint (10#32)))
    (le : CC.TempEnv) (read : le.get _t'13883 = some (.Vptr (tagCells.block ⟨30,by decide⟩) 0)) :
    CC.doEvalExpr ge (allocation m).1 le memory tagExpr = some (.Vint (10#32)) := by
  simp only [tagExpr,CC.doEvalExpr,read]
  change CC.Mem.load .Mint8unsigned memory (tagCells.block ⟨30,by decide⟩) 0 = _
  exact stored

private theorem reg_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr ge e le memory
      (.Ecast (.Econst_int (CC.Integers.Int.repr 30) CC.tuint) CC.tulong) = some (.Vlong (30#64)) := rfl
private theorem eq_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get ___a64_l_reg__5 = some (.Vlong (30#64))) :
    CC.doEvalExpr ge e le memory
      (.Ebinop .Oeq reg (.Econst_int (CC.Integers.Int.repr 32) CC.tuint) CC.tint) = some (.Vint (0#32)) := by
  simp only [reg,CC.doEvalExpr,read]
  rfl
private theorem lt_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get ___a64_l_reg__5 = some (.Vlong (30#64))) :
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
  CC.PTree.set ___a64_read_tag__1 (CC.Val.Vint (10#32))
    (CC.PTree.set _t'155 (CC.Val.Vint (10#32))
      (CC.PTree.set _t'155 (CC.Val.Vint (10#32))
        (CC.PTree.set _t'13884 (CC.Val.Vint (10#32))
          (CC.PTree.set _t'13883 (CC.Val.Vptr (tagCells.block ⟨30,by decide⟩) 0)
            (CC.PTree.set ___a64_l_reg__5 (CC.Val.Vlong (30#64)) le)))))

/-- Original tag loop consumes actual pointer and byte loads after the SAME SP store. -/
theorem execute {m before : CC.Mem} {header : Header m} {sources : Sources m} {scalars : Locals m}
    (result : Arm64CiliumCallerSPWriteMemory.Store (before := before) header sources scalars)
    (tags : Table true m) (wordCells : Cells false m) (tagCells : Cells true m)
    (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs) (inputs : Fin 30 → BitVec 64)
    (slots : ∀ i : Fin 31,CC.Mem.load .Mint64 before tags.block (8*(i.val : Int)) =
      some (.Vptr (tagCells.block i) 0))
    (current : Arm64CiliumCallerContextEntry.CurrentGPR m before ctx ctxOfs inputs)
    (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 21 (.State procedure reader k (allocation m).1 le result.after)
      (.State procedure .Sskip k (allocation m).1 (resultEnv tagCells le) result.after) := by
  have afterSlots := Arm64CiliumCallerSPGPRFrame.table_slots result true tags tagCells slots
  have afterCurrent := Arm64CiliumCallerSPGPRFrame.current_gpr result ctx ctxOfs inputs current
  have tagReads := (Arm64CiliumCallerGPRView.cell_readbacks wordCells tagCells ctx ctxOfs inputs afterCurrent).2
  have slot : CC.Mem.load .Mint64 result.after tags.block 240 =
      some (.Vptr (tagCells.block ⟨30,by decide⟩) 0) := afterSlots ⟨30,by decide⟩
  have stored : CC.Mem.load .Mint8unsigned result.after (tagCells.block ⟨30,by decide⟩) 0 =
      some (.Vint (10#32)) := tagReads ⟨30,by decide⟩
  apply internalRun_of_steps
  all_goals
    simp only [reader,reader_source,selected,steps,InternalPath,InternalState,CC.doStep,
      reg_value,eq_value,lt_value,pointer_value tags tagCells slot,tag_value tagCells stored,
      cast_byte,cast_uint,cast_tag,temp_value,binop_type,(bools result.after).1,(bools result.after).2,
      CC.PTree.gss,resultEnv,ite_true,ite_false,Bool.false_eq_true,true_and,and_true,
      CC.E0,CC.Eapp,List.nil_append] <;> trivial

/-- Exactly five actual temporary names change; the original _t155 is assigned twice. -/
theorem temp_frame {m : CC.Mem} (tagCells : Cells true m) (le : CC.TempEnv) (id : CC.Ident)
    (h0 : id ≠ ___a64_l_reg__5) (h1 : id ≠ _t'13883) (h2 : id ≠ _t'13884)
    (h3 : id ≠ _t'155) (h4 : id ≠ ___a64_read_tag__1) :
    (resultEnv tagCells le).get id = le.get id := by
  unfold resultEnv
  rw [CC.PTree.gso ___a64_read_tag__1 id _ _ (Ne.symm h4),
    CC.PTree.gso _t'155 id _ _ (Ne.symm h3),CC.PTree.gso _t'155 id _ _ (Ne.symm h3),
    CC.PTree.gso _t'13884 id _ _ (Ne.symm h2),CC.PTree.gso _t'13883 id _ _ (Ne.symm h1),
    CC.PTree.gso ___a64_l_reg__5 id _ _ (Ne.symm h0)]

/-- The original word result survives, and the new tag result is RETURN10. -/
theorem values {m : CC.Mem} (wordCells : Cells false m) (tagCells : Cells true m) (le : CC.TempEnv) :
    (resultEnv tagCells (Arm64CiliumCallerR30Word.resultEnv wordCells le)).get ___a64_read_value__1 =
      some (.Vlong (0#64)) ∧
    (resultEnv tagCells (Arm64CiliumCallerR30Word.resultEnv wordCells le)).get ___a64_read_tag__1 =
      some (.Vint (10#32)) := by
  constructor
  · rw [temp_frame tagCells _ ___a64_read_value__1 (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel) (by decide +kernel)]
    unfold Arm64CiliumCallerR30Word.resultEnv
    exact CC.PTree.gss _ _ _
  · unfold resultEnv
    exact CC.PTree.gss _ _ _

/-- The SAME complete word/SP prefix feeds the original tag loop and materialization continuation. -/
theorem advance {m before : CC.Mem} (header : Header m) (sources : Sources m) (scalars : Locals m)
    (words : Table false m) (tags : Table true m) (wordCells : Cells false m) (tagCells : Cells true m)
    (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs) (inputs : Fin 30 → BitVec 64)
    (slots : ∀ i : Fin 31,CC.Mem.load .Mint64 before words.block (8*(i.val : Int)) =
      some (.Vptr (wordCells.block i) 0))
    (tagSlots : ∀ i : Fin 31,CC.Mem.load .Mint64 before tags.block (8*(i.val : Int)) =
      some (.Vptr (tagCells.block i) 0))
    (current : Arm64CiliumCallerContextEntry.CurrentGPR m before ctx ctxOfs inputs)
    (access : before.access = (allocation m).2.access)
    (pointers : Arm64CiliumCallerHeaderSequence.Initialized header sources before 12)
    (reads : ∀ i : Fin 2,CC.Mem.load (Arm64CiliumCallerEntryScalars.chunk i)
      before (scalars.block i) 0 = some (Arm64CiliumCallerEntryScalars.value i))
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ result : Arm64CiliumCallerSPWriteMemory.Store (before := before) header sources scalars,
      InternalRun ge 182
        (.State procedure Arm64CiliumCallerSPAlignment.tail
          (.Kloop1 Arm64CiliumCallerSPAlignment.body .Sbreak (.Kseq Arm64CiliumCallerMemOffsetPrefix.stage k))
          (allocation m).1 le before)
        (.State procedure after (.Kloop1 (.Ssequence Arm64CiliumCallerR30Word.reader Arm64CiliumCallerR30Word.afterWord) .Sbreak (.Kseq Arm64CiliumCallerR30Word.rest k))
          (allocation m).1
          (resultEnv tagCells (Arm64CiliumCallerR30Word.resultEnv wordCells (Arm64CiliumCallerMemOffset.resultEnv (Arm64CiliumCallerSPPreindex.resultEnv le)))) result.after) ∧
      Arm64EntryMemory.borrowed result.after.nextblock .Mint64 result.after (.Vptr header.block 0)
        Arm64Program._sp = some (.Vlong Arm64CiliumCallerSPPreindex.delta) := by
  obtain ⟨result,run,read⟩ := Arm64CiliumCallerR30Word.advance header sources scalars words wordCells tagCells
    ctx ctxOfs inputs slots current access pointers reads le k
  let temps := Arm64CiliumCallerR30Word.resultEnv wordCells
    (Arm64CiliumCallerMemOffset.resultEnv (Arm64CiliumCallerSPPreindex.resultEnv le))
  let groupCont := CC.Cont.Kloop1
    (.Ssequence Arm64CiliumCallerR30Word.reader Arm64CiliumCallerR30Word.afterWord) .Sbreak
    (.Kseq Arm64CiliumCallerR30Word.rest k)
  have enter : InternalRun ge 1 (.State procedure stage groupCont (allocation m).1 temps result.after)
      (.State procedure reader (.Kseq after groupCont) (allocation m).1 temps result.after) := by
    apply internalRun_of_steps
    all_goals
      simp only [source,steps,InternalPath,InternalState,CC.doStep,CC.E0,CC.Eapp,List.nil_append] <;> trivial
  have tagRun := execute result tags wordCells tagCells ctx ctxOfs inputs tagSlots current temps (.Kseq after groupCont)
  have leave : InternalRun ge 1
      (.State procedure .Sskip (.Kseq after groupCont) (allocation m).1 (resultEnv tagCells temps) result.after)
      (.State procedure after groupCont (allocation m).1 (resultEnv tagCells temps) result.after) := by
    apply internalRun_of_steps
    all_goals
      simp only [steps,InternalPath,InternalState,CC.doStep,CC.E0,CC.Eapp,List.nil_append] <;> trivial
  exact ⟨result,run.trans (enter.trans (tagRun.trans leave)),read⟩

end KProgFormal.ClightRefinement.Arm64CiliumCallerR30Tag
