import KProgFormal.ClightRefinement.Arm64CiliumCallerExit

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerInitializers
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerTables

noncomputable def statement (tags : Bool) (i : Fin 31) (name : CC.Ident) : CC.Stmt :=
  .Sassign (.Ederef (.Ebinop .Oadd (.Evar (tableName tags) (tableType tags))
    (.Econst_int (CC.Integers.Int.repr i.val) CC.tint)
    (CC.tptr (CC.tptr (cellType tags)))) (CC.tptr (cellType tags)))
    (.Eaddrof (.Evar name (cellType tags)) (CC.tptr (cellType tags)))

structure Declaration where
  tags : Bool
  index : Fin 31
  name : CC.Ident
  stage : CC.Stmt
  assign : CC.Stmt
  next : CC.Stmt
  stage_source : stage = .Ssequence assign next
  assign_source : assign = statement tags index name

private noncomputable def declarations : Array Declaration := by
  run_tac do
    let source ← Lean.getConstInfo ``Arm64CiliumCallerUnit.s_trusted_arm64_arm64_sim_xdp_9296
    let mut pending := #[source.value!]
    let mut start : Option Lean.Expr := none
    while !pending.isEmpty do
      let node := pending.back!
      pending := pending.pop
      if node.isAppOfArity ``CC.Stmt.Ssequence 2 then
        let head := node.getAppArgs[0]!
        if head.isAppOfArity ``CC.Stmt.Sassign 2 then
          let rhs := head.getAppArgs[1]!
          if rhs.isAppOfArity ``CC.Expr.Eaddrof 2 then
            let target := rhs.getAppArgs[0]!
            if target.isAppOfArity ``CC.Expr.Evar 2 &&
                target.getAppArgs[0]!.isConstOf ``Arm64CiliumCallerUnit.___a64_x0 then
              if start.isSome then throwError "duplicate original first table row"
              start := some node
      pending := pending ++ node.getAppArgs
    let some first := start | throwError "original first table row absent"
    let mut current := first
    let mut rows : Array Lean.Expr := #[]
    for n in [:62] do
      let stage ← Lean.Meta.withTransparency .all (Lean.Meta.whnf current)
      unless stage.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original table sequence changed"
      let assign ← Lean.Meta.withTransparency .all (Lean.Meta.whnf stage.getAppArgs[0]!)
      unless assign.isAppOfArity ``CC.Stmt.Sassign 2 do throwError "original table assignment absent"
      let rhs := assign.getAppArgs[1]!
      unless rhs.isAppOfArity ``CC.Expr.Eaddrof 2 do throwError "original row is not address initialization"
      let target := rhs.getAppArgs[0]!
      unless target.isAppOfArity ``CC.Expr.Evar 2 do throwError "original initializer cell is not a local"
      let small ← Lean.Meta.mkAppM ``LT.lt #[Lean.mkNatLit (n%31),Lean.mkNatLit 31]
      let index ← Lean.Meta.mkAppM ``Fin.mk #[Lean.mkNatLit (n%31),← Lean.Meta.mkDecideProof small]
      let row ← Lean.Meta.mkAppM ``Declaration.mk #[Lean.toExpr (n/31==1),index,
        target.getAppArgs[0]!,current,stage.getAppArgs[0]!,stage.getAppArgs[1]!,
        ← Lean.Meta.mkEqRefl current,← Lean.Meta.mkEqRefl stage.getAppArgs[0]!]
      rows := rows.push row
      current := stage.getAppArgs[1]!
    Lean.Elab.Tactic.closeMainGoal `original_62_initializers
      (← Lean.Meta.mkArrayLit (Lean.mkConst ``Declaration) rows.toList)

noncomputable def declaration (tags : Bool) (i : Fin 31) : Declaration :=
  declarations[(if tags then 31 else 0) + i.val]'(by
    have bound := i.isLt
    cases tags
    · change 0+i.val < 62;omega
    · change 31+i.val < 62;omega)
noncomputable def row (tags : Bool) (i : Fin 31) : CC.Stmt := (declaration tags i).assign
noncomputable def name (tags : Bool) (i : Fin 31) : CC.Ident := (declaration tags i).name
noncomputable def start : CC.Stmt := (declaration false 0).stage
noncomputable def tagStart : CC.Stmt := (declaration true 0).stage
noncomputable def afterTables : CC.Stmt := (declaration true 30).next

theorem positions : ∀ tags (i : Fin 31),
    (declaration tags i).tags = tags ∧ (declaration tags i).index = i := by decide +kernel

theorem row_source (tags : Bool) (i : Fin 31) : row tags i = statement tags i (name tags i) := by
  have h := (declaration tags i).assign_source
  rw [(positions tags i).1,(positions tags i).2] at h
  exact h

theorem tables_source :
    start = ((List.finRange 31).map (row false)).foldr CC.Stmt.Ssequence tagStart ∧
    tagStart = ((List.finRange 31).map (row true)).foldr CC.Stmt.Ssequence afterTables := by
  exact ⟨rfl,rfl⟩

theorem last_source (tags : Bool) : row tags 30 = initializer tags := by cases tags <;> rfl

theorem declared : ∀ tags (i : Fin 31), (name tags i,cellType tags) ∈ procedure.fn_vars := by
  decide +kernel

structure Cells (tags : Bool) (m : CC.Mem) where
  block : Fin 31 → CC.Block
  binding : ∀ i, (allocation m).1.get (name tags i) = some (block i,cellType tags)

theorem cells_storage (tags : Bool) (m : CC.Mem) : Nonempty (Cells tags m) := by
  have names : CC.listNorepet (CC.varNames procedure.fn_vars) := by
    cases Arm64CiliumCallerLink.entry_valid m .Vundef with
    | intro hn _ _ _ _ => exact hn
  have witness : ∀ i, ∃ block,
      (allocation m).1.get (name tags i) = some (block,cellType tags) :=
    fun i => allocated_local_binding (Arm64CiliumCallerLink.allocated m) names (declared tags i)
  exact ⟨⟨fun i => Classical.choose (witness i),fun i => Classical.choose_spec (witness i)⟩⟩

noncomputable def lastCell {m : CC.Mem} (tags : Bool) (cells : Cells tags m) : Cell tags m where
  block := cells.block 30
  binding := by
    have h := cells.binding 30
    have lastName : name tags 30 = cellName tags := by cases tags <;> rfl
    simpa only [lastName] using h

private theorem indices : ∀ i : Fin 31,
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr (8 * (i.val : Int))) = 8 * (i.val : Int) ∧
    CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr 8)
      (CC.Cop.ptrofsOfInt .Signed (CC.Integers.Int.repr i.val)) =
      CC.Integers.Ptrofs.repr (8 * (i.val : Int)) := by decide +kernel

/-- Every original row derives its pointer store from real table permissions
and its exact local-cell binding,with no successful-operation premise. -/
theorem store_row {m before : CC.Mem} (tags : Bool) (i : Fin 31)
    (table : Table tags m) (cells : Cells tags m)
    (access : before.access = (allocation m).2.access) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ after,
      InternalRun ge 1
        (.State procedure (row tags i) k (allocation m).1 le before)
        (.State procedure .Sskip k (allocation m).1 le after) ∧
      CC.Mem.store .Mint64 before table.block (8*(i.val : Int))
        (.Vptr (cells.block i) 0) = some after ∧
      CC.Mem.load .Mint64 after table.block (8*(i.val : Int)) =
        some (.Vptr (cells.block i) 0) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  have valid : CC.Mem.validAccess before .Mint64 table.block (8*(i.val : Int)) .Writable = true := by
    simp only [CC.Mem.validAccess,Bool.and_eq_true]
    refine ⟨?_,?_⟩
    · apply CC.Mem.rangePerm_intro
      intro o lower upper
      have bound := i.isLt
      have permission := CC.Mem.perm_implies
        (CC.Mem.rangePerm_perm _ _ _ _ _ _ table.owned o (by omega)
          (by change o < 8*(i.val : Int)+8 at upper;omega))
        (by decide : CC.permOrder .Freeable .Writable = true)
      simpa only [CC.Mem.perm,access] using permission
    · change ((8*(i.val : Int)) % 8 == 0) = true
      have align : (8*(i.val : Int)) % 8 = 0 := by omega
      simp only [align,beq_self_eq_true]
  obtain ⟨after,stored⟩ : ∃ after,CC.Mem.store .Mint64 before table.block
      (8*(i.val : Int)) (.Vptr (cells.block i) 0) = some after := by
    simp only [CC.Mem.store,valid,ite_true]
    exact ⟨_,rfl⟩
  let ofs := CC.Integers.Ptrofs.repr (8*(i.val : Int))
  have array : CC.doEvalExpr ge (allocation m).1 le before
      (.Evar (tableName tags) (tableType tags)) = some (.Vptr table.block 0) := by
    simp only [CC.doEvalExpr,CC.lvalOfVar,table.binding]
    cases tags <;> rfl
  have add : CC.Cop.semBinaryOperation ge.genv_cenv .Oadd (.Vptr table.block 0)
      (tableType tags) (.Vint (CC.Integers.Int.repr i.val)) CC.tint before =
      some (.Vptr table.block ofs) := by
    change some (CC.Val.Vptr table.block (CC.Integers.Ptrofs.add 0
      (CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr 8)
        (CC.Cop.ptrofsOfInt .Signed (CC.Integers.Int.repr i.val))))) = _
    have zero (o : CC.Integers.Ptrofs) : CC.Integers.Ptrofs.add 0 o = o := BitVec.zero_add o
    rw [(indices i).2,zero]
  have address : CC.EvalExpr ge (allocation m).1 le before
      (.Ebinop .Oadd (.Evar (tableName tags) (tableType tags))
        (.Econst_int (CC.Integers.Int.repr i.val) CC.tint)
        (CC.tptr (CC.tptr (cellType tags)))) (.Vptr table.block ofs) :=
    .Ebinop .Oadd _ _ _ _ _ _ (CC.doEvalExpr_sound _ _ _ _ _ _ array) (.Econst_int _ _) add
  have value : CC.doEvalExpr ge (allocation m).1 le before
      (.Eaddrof (.Evar (name tags i) (cellType tags)) (CC.tptr (cellType tags))) =
      some (.Vptr (cells.block i) 0) := by
    simp only [CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,cells.binding]
    rfl
  have cast : CC.Cop.semCast (.Vptr (cells.block i) 0) (CC.tptr (cellType tags))
      (CC.tptr (cellType tags)) before = some (.Vptr (cells.block i) 0) := by cases tags <;> rfl
  have assign : CC.doAssignLoc ge.genv_cenv (CC.tptr (cellType tags)) before table.block ofs .Full
      (.Vptr (cells.block i) 0) = some after := by
    change CC.Mem.store .Mint64 before table.block (CC.Integers.Ptrofs.unsigned ofs)
      (.Vptr (cells.block i) 0) = some after
    rw [(indices i).1]
    exact stored
  have step : CC.Step2 ge
      (.State procedure (row tags i) k (allocation m).1 le before) CC.E0
      (.State procedure .Sskip k (allocation m).1 le after) := by
    rw [row_source]
    apply CC.Step.assign
    · exact .Ederef _ _ _ _ address
    · exact CC.doEvalExpr_sound _ _ _ _ _ _ value
    · exact cast
    · exact CC.doAssignLoc_sound _ _ _ _ _ _ _ _ assign
  have internal : InternalState (.State procedure (row tags i) k (allocation m).1 le before) := by
    rw [row_source];trivial
  exact ⟨after,.step internal step (.refl _),stored,CC.Mem.load_store_same stored,
    FrameBelow.store table.fresh stored,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩


/-- The original rows execute once,in order,while retaining every slot and
all non-table blocks through those same concrete stores. -/
theorem run_rows {m before : CC.Mem} (tags : Bool) (rows : List (Fin 31))
    (table : Table tags m) (cells : Cells tags m)
    (access : before.access = (allocation m).2.access)
    (le : CC.TempEnv) (k : CC.Cont) (rest : CC.Stmt) :
    ∃ after,
      InternalRun ge (3*rows.length)
        (.State procedure (rows.foldr (fun i next => .Ssequence (row tags i) next) rest)
          k (allocation m).1 le before)
        (.State procedure rest k (allocation m).1 le after) ∧
      (∀ i ∈ rows,CC.Mem.load .Mint64 after table.block (8*(i.val : Int)) =
        some (.Vptr (cells.block i) 0)) ∧
      (∀ i ∉ rows,CC.Mem.load .Mint64 after table.block (8*(i.val : Int)) =
        CC.Mem.load .Mint64 before table.block (8*(i.val : Int))) ∧
      (∀ b,b ≠ table.block → ∀ c o,CC.Mem.load c after b o = CC.Mem.load c before b o) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  induction rows generalizing before with
  | nil =>
    refine ⟨before,.refl _,?_,?_,?_,FrameBelow.refl _ _,rfl,rfl⟩
    · intro i member;cases member
    · intro i absent;rfl
    · intro b different c o;rfl
  | cons head tail ih =>
    let next := tail.foldr (fun i next => .Ssequence (row tags i) next) rest
    obtain ⟨middle,headRun,stored,headRead,headFrame,headAccess,headNext⟩ :=
      store_row tags head table cells access le (.Kseq next k)
    have first : InternalRun ge 3
        (.State procedure (.Ssequence (row tags head) next) k (allocation m).1 le before)
        (.State procedure next k (allocation m).1 le middle) :=
      .step trivial (CC.doStep_sound _ _ _ _ rfl)
        (headRun.trans (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)))
    obtain ⟨after,tailRun,tailRead,tailOther,tailBlocks,tailFrame,tailAccess,tailNext⟩ :=
      ih (headAccess.trans access)
    have headOther (i : Fin 31) (different : i ≠ head) :
        CC.Mem.load .Mint64 middle table.block (8*(i.val : Int)) =
          CC.Mem.load .Mint64 before table.block (8*(i.val : Int)) := by
      have ne : i.val ≠ head.val := fun same => different (Fin.ext same)
      have separate : 8*(i.val : Int)+8 ≤ 8*(head.val : Int) ∨
          8*(head.val : Int)+8 ≤ 8*(i.val : Int) := by omega
      exact CC.Mem.load_store_other stored _ _ _ (.inr separate)
    refine ⟨after,?_,?_,?_,?_,headFrame.trans tailFrame,
      tailAccess.trans headAccess,tailNext.trans headNext⟩
    · simpa only [List.foldr_cons,List.length_cons,Nat.mul_add,Nat.mul_one,Nat.add_comm,next]
        using first.trans tailRun
    · intro i member
      by_cases later : i ∈ tail
      · exact tailRead i later
      · have same : i = head := (List.mem_cons.mp member).resolve_right later
        subst i
        exact (tailOther head later).trans headRead
    · intro i absent
      have ne : i ≠ head := by intro same;apply absent;simp only [same,List.mem_cons_self]
      have notTail : i ∉ tail := fun member => absent (List.mem_cons_of_mem _ member)
      exact (tailOther i notTail).trans (headOther i ne)
    · intro b different c o
      exact (tailBlocks b different c o).trans (CC.Mem.load_store_other stored c b o (.inl different))

def firstThirty : List (Fin 31) :=
  (List.finRange 30).map (fun i => ⟨i.val,by have := i.isLt;omega⟩)
private theorem first_thirty : ∀ i : Fin 31,i ∈ firstThirty ↔ i.val < 30 := by decide +kernel
private theorem first_length : firstThirty.length = 30 := by decide +kernel
private theorem complete_rows : List.finRange 31 = firstThirty ++ [30] := by decide +kernel

/-- Keep the final row's genuine1step initializer trace;its whole table-block
frame will survive the subsequent OTHER table's initialization. -/
theorem initialize_group {m before : CC.Mem} (tags : Bool)
    (table : Table tags m) (cells : Cells tags m)
    (access : before.access = (allocation m).2.access)
    (le : CC.TempEnv) (k : CC.Cont) (rest : CC.Stmt) :
    ∃ after,
      InternalRun ge 93
        (.State procedure ((List.finRange 31).foldr
          (fun i next => .Ssequence (row tags i) next) rest) k (allocation m).1 le before)
        (.State procedure rest k (allocation m).1 le after) ∧
      (∀ i,CC.Mem.load .Mint64 after table.block (8*(i.val : Int)) =
        some (.Vptr (cells.block i) 0)) ∧
      Nonempty (Arm64CiliumCallerTableWrites.Initialized tags m after table (lastCell tags cells)) ∧
      (∀ b,b ≠ table.block → ∀ c o,CC.Mem.load c after b o = CC.Mem.load c before b o) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  let finalRow : CC.Stmt := .Ssequence (row tags 30) rest
  obtain ⟨middle,prefixRun,reads,_,blocks,frame,midAccess,midNext⟩ :=
    run_rows tags firstThirty table cells access le k finalRow
  obtain ⟨after,one,stored,read,other,lastFrame,lastAccess,lastNext⟩ :=
    initializer_store tags table (lastCell tags cells) (midAccess.trans access) le (.Kseq rest k)
  have last : InternalRun ge 3
      (.State procedure finalRow k (allocation m).1 le middle)
      (.State procedure rest k (allocation m).1 le after) := by
    dsimp only [finalRow]
    rw [last_source]
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
      (one.trans (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)))
  have run : InternalRun ge 93
      (.State procedure ((List.finRange 31).foldr
        (fun i next => .Ssequence (row tags i) next) rest) k (allocation m).1 le before)
      (.State procedure rest k (allocation m).1 le after) := by
    simpa only [complete_rows,List.foldr_append,List.foldr_cons,List.foldr_nil,
      first_length,finalRow] using prefixRun.trans last
  refine ⟨after,run,?_,⟨⟨middle,after,le,.Kseq rest k,one,stored,fun _ _ => rfl⟩⟩,
    ?_,frame.trans lastFrame,lastAccess.trans midAccess,lastNext.trans midNext⟩
  · intro i
    by_cases earlier : i.val < 30
    · have previous := reads i ((first_thirty i).mpr earlier)
      have apart : 8*(i.val : Int)+8 ≤ 240 := by omega
      have kept : CC.Mem.load .Mint64 after table.block (8*(i.val : Int)) =
          CC.Mem.load .Mint64 middle table.block (8*(i.val : Int)) :=
        CC.Mem.load_store_other stored .Mint64 table.block (8*(i.val : Int)) (.inr (.inl apart))
      exact kept.trans previous
    · have same : i = 30 := by apply Fin.ext;have := i.isLt;omega
      subst i
      exact read
  · intro b different c o
    exact (other b different c o).trans (blocks b different c o)

/-- All62 ORIGINAL assignments in their real word0..30/tag0..30 order.
The actual following vector/provider source is retained as afterTables. -/
theorem execute {m before : CC.Mem} (words : Table false m) (tags : Table true m)
    (wordCells : Cells false m) (tagCells : Cells true m)
    (access : before.access = (allocation m).2.access) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ after,
      InternalRun ge 186
        (.State procedure start k (allocation m).1 le before)
        (.State procedure afterTables k (allocation m).1 le after) ∧
      (∀ i,CC.Mem.load .Mint64 after words.block (8*(i.val : Int)) =
        some (.Vptr (wordCells.block i) 0)) ∧
      (∀ i,CC.Mem.load .Mint64 after tags.block (8*(i.val : Int)) =
        some (.Vptr (tagCells.block i) 0)) ∧
      Nonempty (Arm64CiliumCallerTableWrites.Initialized false m after words (lastCell false wordCells)) ∧
      Nonempty (Arm64CiliumCallerTableWrites.Initialized true m after tags (lastCell true tagCells)) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨middle,wordRun,wordReads,⟨wordEntry⟩,_,wordFrame,wordAccess,wordNext⟩ :=
    initialize_group false words wordCells access le k tagStart
  obtain ⟨after,tagRun,tagReads,tagEntry,tagOther,tagFrame,tagAccess,tagNext⟩ :=
    initialize_group true tags tagCells (wordAccess.trans access) le k afterTables
  have different := tables_separate m words tags
  have wordEntry' : Arm64CiliumCallerTableWrites.Initialized false m after words (lastCell false wordCells) :=
    {wordEntry with frame := fun c o =>
      (tagOther words.block different c o).trans (wordEntry.frame c o)}
  have run : InternalRun ge 186
      (.State procedure start k (allocation m).1 le before)
      (.State procedure afterTables k (allocation m).1 le after) := by
    rw [← List.foldr_map] at wordRun tagRun
    rw [← tables_source.1] at wordRun
    rw [← tables_source.2] at tagRun
    exact wordRun.trans tagRun
  exact ⟨after,run,
    (fun i => (tagOther words.block different .Mint64 (8*(i.val : Int))).trans (wordReads i)),
    tagReads,⟨wordEntry'⟩,tagEntry,wordFrame.trans tagFrame,
    tagAccess.trans wordAccess,tagNext.trans wordNext⟩

end KProgFormal.ClightRefinement.Arm64CiliumCallerInitializers
