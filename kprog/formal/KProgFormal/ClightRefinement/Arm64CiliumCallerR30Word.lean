import KProgFormal.ClightRefinement.Arm64CiliumCallerSPGPRFrame

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerR30Word
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure allocation)
open Arm64CiliumCallerLinkedProgram (ge)
open Arm64CiliumCallerHeaderSource (Header Sources)
open Arm64CiliumCallerEntryScalars (Locals)
open Arm64CiliumCallerTables (Table)
open Arm64CiliumCallerInitializers (Cells)

private structure Parts where
  rest : CC.Stmt
  afterWord : CC.Stmt
  wordBody : CC.Stmt
  spBranch : CC.Stmt
  otherBranch : CC.Stmt

private noncomputable def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless node.isAppOfArity ctor arity do throwError "actual R30 word reader changed"
      pure node.getAppArgs
    let original ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerMemOffsetPrefix.rest)) none
    let outer ← peel original ``CC.Stmt.Ssequence 2
    let group ← peel outer[0]! ``CC.Stmt.Sloop 2
    let pair ← peel group[0]! ``CC.Stmt.Ssequence 2
    let word ← peel pair[0]! ``CC.Stmt.Sloop 2
    let body ← peel word[0]! ``CC.Stmt.Ssequence 2
    let tail ← peel body[1]! ``CC.Stmt.Ssequence 2
    let choose ← peel tail[0]! ``CC.Stmt.Sifthenelse 3
    let lt ← peel choose[2]! ``CC.Stmt.Sifthenelse 3
    Lean.Elab.Tactic.closeMainGoal `actual_r30_word
      (← Lean.Meta.mkAppM ``Parts.mk #[outer[1]!,pair[1]!,word[0]!,choose[1]!,lt[2]!])

noncomputable def stage : CC.Stmt := Arm64CiliumCallerMemOffsetPrefix.rest
noncomputable def rest : CC.Stmt := parts.rest
noncomputable def afterWord : CC.Stmt := parts.afterWord
noncomputable def body : CC.Stmt := parts.wordBody
noncomputable def reader : CC.Stmt := .Sloop body .Sbreak
private noncomputable def unionTy : CC.Ty := .Tunion _arm64_sim_gpr CC.noattr
private noncomputable def ptrTy : CC.Ty := CC.tptr unionTy
private noncomputable def tableTy : CC.Ty := CC.tarray ptrTy 31
private noncomputable def reg : CC.Expr := .Etempvar ___a64_l_reg__4 CC.tulong
private noncomputable def address : CC.Expr := .Ebinop .Oadd (.Evar ___a64_cells tableTy)
  (.Ecast reg CC.tuchar) (CC.tptr ptrTy)
noncomputable def pointerExpr : CC.Expr := .Ederef address ptrTy
noncomputable def wordExpr : CC.Expr :=
  .Efield (.Ederef (.Etempvar _t'13885 ptrTy) unionTy) _x CC.tulong
private noncomputable def selected : CC.Stmt := .Ssequence
  (.Ssequence (.Sset _t'13885 pointerExpr)
    (.Ssequence (.Sset _t'13886 wordExpr)
      (.Sset _t'154 (.Ecast (.Etempvar _t'13886 CC.tulong) CC.tulong))))
  (.Sset _t'154 (.Ecast (.Etempvar _t'154 CC.tulong) CC.tulong))

theorem source : stage = .Ssequence (.Sloop (.Ssequence reader afterWord) .Sbreak) rest := rfl
theorem reader_source : body = .Ssequence
    (.Sset ___a64_l_reg__4 (.Ecast (.Econst_int (CC.Integers.Int.repr 30) CC.tuint) CC.tulong))
    (.Ssequence
      (.Sifthenelse (.Ebinop .Oeq reg (.Econst_int (CC.Integers.Int.repr 32) CC.tuint) CC.tint)
        parts.spBranch
        (.Sifthenelse (.Ebinop .Olt reg (.Econst_int (CC.Integers.Int.repr 31) CC.tuint) CC.tint)
          selected parts.otherBranch))
      (.Sset ___a64_read_value__1 (.Etempvar _t'154 CC.tulong))) := rfl

private theorem address_value {m memory : CC.Mem} (words : Table false m)
    (le : CC.TempEnv) (read : le.get ___a64_l_reg__4 = some (.Vlong (30#64))) :
    CC.doEvalExpr ge (allocation m).1 le memory address = some (.Vptr words.block (CC.Integers.Ptrofs.repr 240)) := by
  have binding : (allocation m).1.get ___a64_cells = some (words.block,tableTy) := words.binding
  simp only [address,reg,CC.doEvalExpr,CC.lvalOfVar,binding,ite_true,read]
  rfl

/-- The original table expression loads the actual slot30 pointer. -/
theorem pointer_value {m memory : CC.Mem} (words : Table false m) (wordCells : Cells false m)
    (slot : CC.Mem.load .Mint64 memory words.block 240 = some (.Vptr (wordCells.block ⟨30,by decide⟩) 0))
    (le : CC.TempEnv) (read : le.get ___a64_l_reg__4 = some (.Vlong (30#64))) :
    CC.doEvalExpr ge (allocation m).1 le memory pointerExpr =
      some (.Vptr (wordCells.block ⟨30,by decide⟩) 0) := by
  unfold pointerExpr
  rw [CC.doEvalExpr,address_value words le read]
  change CC.Mem.load .Mint64 memory words.block 240 = _
  exact slot

private theorem gpr_layout : Arm64Producer.GprLayout ge := by
  unfold Arm64Producer.GprLayout
  decide +kernel

private theorem field_value (block : CC.Block) :
    CC.lvalOfField ge unionTy _x (.Vptr block 0) = some (block,0,.Full) := by
  have names : _arm64_sim_gpr = Arm64Entry._arm64_sim_gpr ∧ _x = Arm64Entry._x := by decide +kernel
  simp only [CC.lvalOfField,unionTy,names.1,names.2,gpr_layout.1,gpr_layout.2]
  rfl

/-- The actual exported union field reads the same loaded R30 cell. -/
theorem word_value {m memory : CC.Mem} (wordCells : Cells false m)
    (stored : CC.Mem.load .Mint64 memory (wordCells.block ⟨30,by decide⟩) 0 = some (.Vlong (0#64)))
    (le : CC.TempEnv) (read : le.get _t'13885 = some (.Vptr (wordCells.block ⟨30,by decide⟩) 0)) :
    CC.doEvalExpr ge (allocation m).1 le memory wordExpr = some (.Vlong (0#64)) := by
  have cell : CC.doEvalExpr ge (allocation m).1 le memory
      (.Ederef (.Etempvar _t'13885 ptrTy) unionTy) = some (.Vptr (wordCells.block ⟨30,by decide⟩) 0) := by
    simp only [CC.doEvalExpr,read]
    rfl
  have cell_type : CC.typeof (.Ederef (.Etempvar _t'13885 ptrTy) unionTy) = unionTy := rfl
  unfold wordExpr
  rw [CC.doEvalExpr,cell,cell_type]
  simp only [field_value]
  change CC.Mem.load .Mint64 memory (wordCells.block ⟨30,by decide⟩) 0 = _
  exact stored

private theorem reg_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr ge e le memory
      (.Ecast (.Econst_int (CC.Integers.Int.repr 30) CC.tuint) CC.tulong) = some (.Vlong (30#64)) := rfl
private theorem eq_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get ___a64_l_reg__4 = some (.Vlong (30#64))) :
    CC.doEvalExpr ge e le memory
      (.Ebinop .Oeq reg (.Econst_int (CC.Integers.Int.repr 32) CC.tuint) CC.tint) = some (.Vint (0#32)) := by
  simp only [reg,CC.doEvalExpr,read]
  rfl
private theorem lt_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get ___a64_l_reg__4 = some (.Vlong (30#64))) :
    CC.doEvalExpr ge e le memory
      (.Ebinop .Olt reg (.Econst_int (CC.Integers.Int.repr 31) CC.tuint) CC.tint) = some (.Vint (1#32)) := by
  simp only [reg,CC.doEvalExpr,read]
  rfl
private theorem cast_zero (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (id : CC.Ident)
    (read : le.get id = some (.Vlong (0#64))) :
    CC.doEvalExpr ge e le memory (.Ecast (.Etempvar id CC.tulong) CC.tulong) = some (.Vlong (0#64)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem temp_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (id : CC.Ident) (ty : CC.Ty) :
    CC.doEvalExpr ge e le memory (.Etempvar id ty) = le.get id := rfl
private theorem binop_type (op : CC.Binop) (left right : CC.Expr) (ty : CC.Ty) :
    CC.typeof (.Ebinop op left right ty) = ty := rfl
private theorem bools (memory : CC.Mem) :
    CC.Cop.boolVal (.Vint (0#32)) CC.tint memory = some false ∧
    CC.Cop.boolVal (.Vint (1#32)) CC.tint memory = some true := ⟨rfl,rfl⟩

noncomputable def resultEnv {m : CC.Mem} (wordCells : Cells false m) (le : CC.TempEnv) : CC.TempEnv :=
  CC.PTree.set ___a64_read_value__1 (CC.Val.Vlong (0#64))
    (CC.PTree.set _t'154 (CC.Val.Vlong (0#64))
      (CC.PTree.set _t'154 (CC.Val.Vlong (0#64))
        (CC.PTree.set _t'13886 (CC.Val.Vlong (0#64))
          (CC.PTree.set _t'13885 (CC.Val.Vptr (wordCells.block ⟨30,by decide⟩) 0)
            (CC.PTree.set ___a64_l_reg__4 (CC.Val.Vlong (30#64)) le)))))

/-- The original loop executes real pointer-table and union-cell loads on the same SP-updated heap. -/
theorem execute {m before : CC.Mem} {header : Header m} {sources : Sources m} {scalars : Locals m}
    (result : Arm64CiliumCallerSPWriteMemory.Store (before := before) header sources scalars)
    (words : Table false m) (wordCells : Cells false m) (tagCells : Cells true m)
    (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs) (inputs : Fin 30 → BitVec 64)
    (slots : ∀ i : Fin 31,CC.Mem.load .Mint64 before words.block (8*(i.val : Int)) =
      some (.Vptr (wordCells.block i) 0))
    (current : Arm64CiliumCallerContextEntry.CurrentGPR m before ctx ctxOfs inputs)
    (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 21 (.State procedure reader k (allocation m).1 le result.after)
      (.State procedure .Sskip k (allocation m).1 (resultEnv wordCells le) result.after) := by
  have afterSlots := Arm64CiliumCallerSPGPRFrame.table_slots result false words wordCells slots
  have afterCurrent := Arm64CiliumCallerSPGPRFrame.current_gpr result ctx ctxOfs inputs current
  have wordReads := (Arm64CiliumCallerGPRView.cell_readbacks wordCells tagCells ctx ctxOfs inputs afterCurrent).1
  have slot : CC.Mem.load .Mint64 result.after words.block 240 =
      some (.Vptr (wordCells.block ⟨30,by decide⟩) 0) := afterSlots ⟨30,by decide⟩
  have stored : CC.Mem.load .Mint64 result.after (wordCells.block ⟨30,by decide⟩) 0 =
      some (.Vlong (0#64)) := wordReads ⟨30,by decide⟩
  apply internalRun_of_steps
  all_goals
    simp only [reader,reader_source,selected,steps,InternalPath,InternalState,CC.doStep,
      reg_value,eq_value,lt_value,pointer_value words wordCells slot,word_value wordCells stored,
      cast_zero,temp_value,binop_type,(bools result.after).1,(bools result.after).2,
      CC.PTree.gss,resultEnv,ite_true,ite_false,Bool.false_eq_true,true_and,and_true,
      CC.E0,CC.Eapp,List.nil_append] <;> trivial

/-- Exactly five original temporary names change (the original _t154 is assigned twice). -/
theorem temp_frame {m : CC.Mem} (wordCells : Cells false m) (le : CC.TempEnv) (id : CC.Ident)
    (h0 : id ≠ ___a64_l_reg__4) (h1 : id ≠ _t'13885) (h2 : id ≠ _t'13886)
    (h3 : id ≠ _t'154) (h4 : id ≠ ___a64_read_value__1) :
    (resultEnv wordCells le).get id = le.get id := by
  unfold resultEnv
  rw [CC.PTree.gso ___a64_read_value__1 id _ _ (Ne.symm h4),
    CC.PTree.gso _t'154 id _ _ (Ne.symm h3),CC.PTree.gso _t'154 id _ _ (Ne.symm h3),
    CC.PTree.gso _t'13886 id _ _ (Ne.symm h2),CC.PTree.gso _t'13885 id _ _ (Ne.symm h1),
    CC.PTree.gso ___a64_l_reg__4 id _ _ (Ne.symm h0)]

/-- The original numeric/SP prefix reaches the real R30 word loop and its actual next continuation. -/
theorem advance {m before : CC.Mem} (header : Header m) (sources : Sources m) (scalars : Locals m)
    (words : Table false m) (wordCells : Cells false m) (tagCells : Cells true m)
    (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs) (inputs : Fin 30 → BitVec 64)
    (slots : ∀ i : Fin 31,CC.Mem.load .Mint64 before words.block (8*(i.val : Int)) =
      some (.Vptr (wordCells.block i) 0))
    (current : Arm64CiliumCallerContextEntry.CurrentGPR m before ctx ctxOfs inputs)
    (access : before.access = (allocation m).2.access)
    (pointers : Arm64CiliumCallerHeaderSequence.Initialized header sources before 12)
    (reads : ∀ i : Fin 2,CC.Mem.load (Arm64CiliumCallerEntryScalars.chunk i)
      before (scalars.block i) 0 = some (Arm64CiliumCallerEntryScalars.value i))
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ result : Arm64CiliumCallerSPWriteMemory.Store (before := before) header sources scalars,
      InternalRun ge 159
        (.State procedure Arm64CiliumCallerSPAlignment.tail
          (.Kloop1 Arm64CiliumCallerSPAlignment.body .Sbreak (.Kseq Arm64CiliumCallerMemOffsetPrefix.stage k))
          (allocation m).1 le before)
        (.State procedure afterWord (.Kloop1 (.Ssequence reader afterWord) .Sbreak (.Kseq rest k))
          (allocation m).1
          (resultEnv wordCells (Arm64CiliumCallerMemOffset.resultEnv (Arm64CiliumCallerSPPreindex.resultEnv le))) result.after) ∧
      Arm64EntryMemory.borrowed result.after.nextblock .Mint64 result.after (.Vptr header.block 0)
        Arm64Program._sp = some (.Vlong Arm64CiliumCallerSPPreindex.delta) := by
  obtain ⟨result,run,read⟩ := Arm64CiliumCallerMemOffset.advance header sources scalars access pointers reads le k
  let temps := Arm64CiliumCallerMemOffset.resultEnv (Arm64CiliumCallerSPPreindex.resultEnv le)
  let groupCont := CC.Cont.Kloop1 (.Ssequence reader afterWord) .Sbreak (.Kseq rest k)
  have bridge : InternalRun ge 3
      (.State procedure .Sskip (.Kloop1 Arm64CiliumCallerMemOffsetPrefix.body .Sbreak
        (.Kseq Arm64CiliumCallerMemOffsetPrefix.rest k)) (allocation m).1 temps result.after)
      (.State procedure stage k (allocation m).1 temps result.after) := by
    apply internalRun_of_steps
    all_goals
      simp only [stage,steps,InternalPath,InternalState,CC.doStep,CC.E0,CC.Eapp,List.nil_append] <;> trivial
  have enter : InternalRun ge 3 (.State procedure stage k (allocation m).1 temps result.after)
      (.State procedure reader (.Kseq afterWord groupCont) (allocation m).1 temps result.after) := by
    apply internalRun_of_steps
    all_goals
      simp only [source,groupCont,steps,InternalPath,InternalState,CC.doStep,CC.E0,CC.Eapp,List.nil_append] <;> trivial
  have wordRun := execute result words wordCells tagCells ctx ctxOfs inputs slots current temps (.Kseq afterWord groupCont)
  have leave : InternalRun ge 1
      (.State procedure .Sskip (.Kseq afterWord groupCont) (allocation m).1 (resultEnv wordCells temps) result.after)
      (.State procedure afterWord groupCont (allocation m).1 (resultEnv wordCells temps) result.after) := by
    apply internalRun_of_steps
    all_goals
      simp only [steps,InternalPath,InternalState,CC.doStep,CC.E0,CC.Eapp,List.nil_append] <;> trivial
  exact ⟨result,run.trans (bridge.trans (enter.trans (wordRun.trans leave))),read⟩

end KProgFormal.ClightRefinement.Arm64CiliumCallerR30Word
