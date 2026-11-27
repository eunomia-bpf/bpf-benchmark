import KProgFormal.ClightRefinement.Arm64CiliumCallerWriterGuard

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerTables
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation)

noncomputable def cellType (tags : Bool) : CC.Ty :=
  if tags then CC.tuchar else .Tunion _arm64_sim_gpr CC.noattr
noncomputable def tableType (tags : Bool) : CC.Ty := CC.tarray (CC.tptr (cellType tags)) 31
noncomputable def tableName (tags : Bool) : CC.Ident :=
  if tags then ___a64_tag_cells else ___a64_cells
noncomputable def cellName (tags : Bool) : CC.Ident :=
  if tags then ___a64_x30_tag else ___a64_x30

/-- Exact actual slot30 initializer subexpressions in their original exported
source parts;no statement is replaced by a hand-written source fixture. -/
private def selectInitializer (sourceName cell : Lean.Name) : Lean.Elab.Tactic.TacticM Unit := do
  let source ← Lean.getConstInfo sourceName
  let mut pending := #[source.value!]
  let mut found : Option Lean.Expr := none
  while !pending.isEmpty do
    let node := pending.back!
    pending := pending.pop
    if node.isAppOfArity ``CC.Stmt.Sassign 2 then
      let rhs := node.getAppArgs[1]!
      if rhs.isAppOfArity ``CC.Expr.Eaddrof 2 then
        let target := rhs.getAppArgs[0]!
        if target.isAppOfArity ``CC.Expr.Evar 2 && target.getAppArgs[0]!.isConstOf cell then
          if found.isSome then throwError "duplicate original cell-address initializer"
          found := some node
    pending := pending ++ node.getAppArgs
  let some statement := found | throwError "original cell-address initializer absent"
  Lean.Elab.Tactic.closeMainGoal `original_slot30 statement

noncomputable def initializer (tags : Bool) : CC.Stmt := by
  cases tags with
  | false =>
    run_tac do
      selectInitializer ``Arm64CiliumCallerUnit.s_trusted_arm64_arm64_sim_xdp_9294
        ``Arm64CiliumCallerUnit.___a64_x30
  | true =>
    run_tac do
      selectInitializer ``Arm64CiliumCallerUnit.s_trusted_arm64_arm64_sim_xdp_9292
        ``Arm64CiliumCallerUnit.___a64_x30_tag

theorem initializer_source (tags : Bool) :
    initializer tags =
      .Sassign
        (.Ederef
          (.Ebinop .Oadd (.Evar (tableName tags) (tableType tags))
            (.Econst_int (CC.Integers.Int.repr 30) CC.tint) (CC.tptr (CC.tptr (cellType tags))))
          (CC.tptr (cellType tags)))
        (.Eaddrof (.Evar (cellName tags) (cellType tags)) (CC.tptr (cellType tags))) := by
  cases tags <;> rfl

private theorem names (m : CC.Mem) : CC.listNorepet (CC.varNames procedure.fn_vars) := by
  cases Arm64CiliumCallerLink.entry_valid m .Vundef with
  | intro hn hp hd ha hb => exact hn

structure Table (tags : Bool) (m : CC.Mem) where
  block : CC.Block
  binding : (allocation m).1.get (tableName tags) = some (block,tableType tags)
  fresh : m.nextblock.toNat ≤ block.toNat
  owned : CC.Mem.rangePerm (allocation m).2 block 0 248 .Cur .Freeable = true

structure Cell (tags : Bool) (m : CC.Mem) where
  block : CC.Block
  binding : (allocation m).1.get (cellName tags) = some (block,cellType tags)

theorem table_storage (tags : Bool) (m : CC.Mem) : Nonempty (Table tags m) := by
  have member : (tableName tags,tableType tags) ∈ procedure.fn_vars := by cases tags <;> decide +kernel
  obtain ⟨block,binding⟩ := allocated_local_binding (Arm64CiliumCallerLink.allocated m) (names m) member
  have live := (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).1 _ _ binding
  have size : CC.sizeof ge.genv_cenv (tableType tags) = 248 := by cases tags <;> rfl
  exact ⟨⟨block,binding,live.1,by simpa only [size] using live.2.2⟩⟩

theorem cell_storage (tags : Bool) (m : CC.Mem) : Nonempty (Cell tags m) := by
  have member : (cellName tags,cellType tags) ∈ procedure.fn_vars := by cases tags <;> decide +kernel
  obtain ⟨block,binding⟩ := allocated_local_binding (Arm64CiliumCallerLink.allocated m) (names m) member
  exact ⟨⟨block,binding⟩⟩

theorem tables_separate (m : CC.Mem) (words : Table false m) (tags : Table true m) :
    words.block ≠ tags.block :=
  (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
    _ _ _ _ words.binding tags.binding (by decide +kernel)

theorem table_cell_separate (m : CC.Mem) (left right : Bool)
    (table : Table left m) (cell : Cell right m) : table.block ≠ cell.block := by
  apply (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
    _ _ _ _ table.binding cell.binding
  cases left <;> cases right <;> decide +kernel

/-- Current slot permission follows from the same real allocated array and
the preserved access map,not a successful-memory-operation hypothesis. -/
theorem slot_writable {m before : CC.Mem} (tags : Bool) (table : Table tags m)
    (access : before.access = (allocation m).2.access) :
    CC.Mem.validAccess before .Mint64 table.block 240 .Writable = true := by
  simp only [CC.Mem.validAccess,Bool.and_eq_true]
  refine ⟨?_,by decide⟩
  apply CC.Mem.rangePerm_intro
  intro offset lower upper
  have permission := CC.Mem.perm_implies
    (CC.Mem.rangePerm_perm _ _ _ _ _ _ table.owned offset (by omega)
      (by change offset < 240 + 8 at upper;omega))
    (by decide : CC.permOrder .Freeable .Writable = true)
  simpa only [CC.Mem.perm,access] using permission

/-- Execute one ORIGINAL slot30 initializer with its original continuation.
The real allocator derives the successful pointer store and readback;all
non-table blocks and caller memory follow from this same store. -/
theorem initializer_store {m before : CC.Mem} (tags : Bool) (table : Table tags m)
    (cell : Cell tags m) (access : before.access = (allocation m).2.access)
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ after,
      InternalRun ge 1
        (.State procedure (initializer tags) k (allocation m).1 le before)
        (.State procedure .Sskip k (allocation m).1 le after) ∧
      CC.Mem.store .Mint64 before table.block 240 (.Vptr cell.block 0) = some after ∧
      CC.Mem.load .Mint64 after table.block 240 = some (.Vptr cell.block 0) ∧
      (∀ block,block ≠ table.block → ∀ chunk offset,
        CC.Mem.load chunk after block offset = CC.Mem.load chunk before block offset) ∧
      FrameBelow m.nextblock before after ∧
      after.access = before.access ∧ after.nextblock = before.nextblock := by
  have writable := slot_writable tags table access
  obtain ⟨after,stored⟩ : ∃ after,
      CC.Mem.store .Mint64 before table.block 240 (.Vptr cell.block 0) = some after := by
    simp only [CC.Mem.store,writable,ite_true]
    exact ⟨_,rfl⟩
  have arrayValue : CC.doEvalExpr ge (allocation m).1 le before
      (.Evar (tableName tags) (tableType tags)) = some (.Vptr table.block 0) := by
    simp only [CC.doEvalExpr,CC.lvalOfVar,table.binding]
    cases tags <;> rfl
  have add : CC.Cop.semBinaryOperation ge.genv_cenv .Oadd (.Vptr table.block 0)
      (tableType tags) (.Vint (CC.Integers.Int.repr 30)) CC.tint before =
      some (.Vptr table.block (240#64)) := by
    cases tags <;> rfl
  have address : CC.EvalExpr ge (allocation m).1 le before
      (.Ebinop .Oadd (.Evar (tableName tags) (tableType tags))
        (.Econst_int (CC.Integers.Int.repr 30) CC.tint) (CC.tptr (CC.tptr (cellType tags))))
      (.Vptr table.block (240#64)) := by
    exact .Ebinop .Oadd _ _ _ _ _ _
      (CC.doEvalExpr_sound _ _ _ _ _ _ arrayValue) (.Econst_int _ _) add
  have target : CC.EvalLvalue ge (allocation m).1 le before
      (.Ederef
        (.Ebinop .Oadd (.Evar (tableName tags) (tableType tags))
          (.Econst_int (CC.Integers.Int.repr 30) CC.tint) (CC.tptr (CC.tptr (cellType tags))))
        (CC.tptr (cellType tags))) table.block (240#64) .Full :=
    .Ederef _ _ _ _ address
  have value : CC.doEvalExpr ge (allocation m).1 le before
      (.Eaddrof (.Evar (cellName tags) (cellType tags)) (CC.tptr (cellType tags))) =
      some (.Vptr cell.block 0) := by
    simp only [CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,cell.binding]
    rfl
  have cast : CC.Cop.semCast (.Vptr cell.block 0) (CC.tptr (cellType tags))
      (CC.tptr (cellType tags)) before = some (.Vptr cell.block 0) := by
    cases tags <;> rfl
  have assign : CC.doAssignLoc ge.genv_cenv (CC.tptr (cellType tags)) before
      table.block (240#64) .Full (.Vptr cell.block 0) = some after := by
    cases tags <;> exact stored
  have step : CC.Step2 ge
      (.State procedure (initializer tags) k (allocation m).1 le before) CC.E0
      (.State procedure .Sskip k (allocation m).1 le after) := by
    rw [initializer_source]
    apply CC.Step.assign
    · exact target
    · exact CC.doEvalExpr_sound _ _ _ _ _ _ value
    · exact cast
    · exact CC.doAssignLoc_sound _ _ _ _ _ _ _ _ assign
  have internal : InternalState
      (.State procedure (initializer tags) k (allocation m).1 le before) := by
    rw [initializer_source]
    trivial
  exact ⟨after,.step internal step (.refl _),stored,CC.Mem.load_store_same stored,
    (fun block different chunk offset => CC.Mem.load_store_other stored chunk block offset (.inl different)),
    FrameBelow.store table.fresh stored,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩

end KProgFormal.ClightRefinement.Arm64CiliumCallerTables
