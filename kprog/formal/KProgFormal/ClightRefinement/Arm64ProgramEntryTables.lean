import KProgFormal.ClightRefinement.Arm64ProgramEntryGprInputs
import KProgFormal.ClightRefinement.Arm64ProducerTables

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryTables

open Arm64ProgramEntryAllocation (world allocation)
open Arm64Producer (TableLocals tableName tableType tableCellName tableCellType tableAssignment tableAssignments)

/-- The actual 62 assignment heads and their real production successor. -/
private def parts : List CC.Stmt × CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryRegisterSource.afterRegisters)) none
    let mut front : Array Lean.Expr := #[]
    for _ in [:62] do
      body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "actual production pointer-table spine ended early"
      let stmt := body.getAppArgs[0]!
      let head ← Lean.Meta.withTransparency .all (Lean.Meta.whnf stmt)
      unless head.isAppOfArity ``CC.Stmt.Sassign 2 do
        throwError "actual production pointer table contains a non-assignment"
      front := front.push stmt
      body := body.getAppArgs[1]!
    let rows ← Lean.Meta.mkListLit (Lean.mkConst ``CC.Stmt) front.toList
    Lean.Elab.Tactic.closeMainGoal `actual_pointer_tables
      (← Lean.Meta.mkAppM ``Prod.mk #[rows, body])

def afterPointerTables : CC.Stmt := parts.2

private theorem words_source : parts.1.take 31 = tableAssignments false := by rfl
private theorem tags_source : parts.1.drop 31 = tableAssignments true := by rfl

/-- Both complete assignment families are checked against the actual AST. -/
theorem source : Arm64ProgramEntryRegisterSource.afterRegisters =
    (tableAssignments false).foldr CC.Stmt.Ssequence
      ((tableAssignments true).foldr CC.Stmt.Ssequence afterPointerTables) := by
  have spine : Arm64ProgramEntryRegisterSource.afterRegisters =
      parts.1.foldr CC.Stmt.Ssequence afterPointerTables := by
    run_tac do
      let rhs ← Lean.Elab.Term.elabTerm (← `(parts.1.foldr CC.Stmt.Ssequence afterPointerTables)) none
      Lean.Elab.Tactic.closeMainGoal `actual_pointer_spine (← Lean.Meta.mkEqRefl rhs)
  rw [← words_source, ← tags_source, ← List.foldr_append, List.take_append_drop]
  exact spine

theorem table_binding (initial : CC.Mem) (tags : Bool) (locals : TableLocals tags initial) :
    (allocation initial).1.get (tableName tags) = some (locals.tableBlock, tableType tags) := by
  have bound := Arm64ProgramEntryAllocation.local_binding initial _ _ _ locals.binding
  have fixed : Arm64ProgramEntryAllocation.localName (tableName tags) = tableName tags := by
    cases tags <;> decide +kernel
  rw [fixed] at bound
  cases tags <;> exact bound

theorem cell_binding (initial : CC.Mem) (tags : Bool) (locals : TableLocals tags initial) (i : Fin 31) :
    (allocation initial).1.get (tableCellName tags i) = some (locals.cellBlock i, tableCellType tags) :=
  Arm64ProgramEntryGprInputs.actual_cell_binding initial tags i _ (locals.cellBinding i)

/-- One complete table reuses the shared store construction and list induction. -/
theorem table_initialized (initial before : CC.Mem) (tags : Bool) (locals : TableLocals tags initial)
    (le : CC.TempEnv) (k : CC.Cont) (rest : CC.Stmt)
    (access : before.access = (allocation initial).2.access) :
    ∃ after, InternalRun world 93
      (.State Arm64ProgramFixture.f_arm64_execute_compile
        ((tableAssignments tags).foldr CC.Stmt.Ssequence rest) k (allocation initial).1 le before)
      (.State Arm64ProgramFixture.f_arm64_execute_compile rest k (allocation initial).1 le after) ∧
      (∀ i, CC.Mem.load CC.Mptr after locals.tableBlock (8 * (i.val : Int)) =
        some (.Vptr (locals.cellBlock i) 0)) ∧
      (∀ id ty block, (Arm64Producer.allocation initial).1.get id = some (block, ty) →
        id ≠ tableName tags → ∀ chunk ofs,
        CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  apply Arm64Producer.initialize_pointer_table_body world Arm64ProgramFixture.f_arm64_execute_compile
    (allocation initial).1 tags initial before le k rest locals
    (table_binding initial tags locals) (cell_binding initial tags locals)
  exact access.trans (congrArg CC.Mem.access
    (Arm64ProgramEntryAllocation.allocation_corresponds initial).1.symm)

/-- Actual table bindings, actual cell bindings and every typed table slot. -/
def Readbacks (initial after : CC.Mem) : Prop :=
  ∀ tags, ∃ locals : TableLocals tags initial,
    (allocation initial).1.get (tableName tags) = some (locals.tableBlock, tableType tags) ∧
    (∀ i, (allocation initial).1.get (tableCellName tags i) =
      some (locals.cellBlock i, tableCellType tags)) ∧
    ∀ i, CC.Mem.load CC.Mptr after locals.tableBlock (8 * (i.val : Int)) =
      some (.Vptr (locals.cellBlock i) 0)

/-- The actual 62 stores execute 186 internal steps to their actual successor. -/
theorem initialized (initial before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation initial).2.access) :
    ∃ after, InternalRun world 186
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryRegisterSource.afterRegisters
        k (allocation initial).1 le before)
      (.State Arm64ProgramFixture.f_arm64_execute_compile afterPointerTables
        k (allocation initial).1 le after) ∧
      Readbacks initial after ∧
      (∀ id ty block, (Arm64Producer.allocation initial).1.get id = some (block, ty) →
        id ≠ tableName false → id ≠ tableName true → ∀ chunk ofs,
        CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨words⟩ := Arm64Producer.table_locals false initial
  obtain ⟨tags⟩ := Arm64Producer.table_locals true initial
  obtain ⟨middle, wordRun, wordRead, wordOther, wordFrame, wordAccess, wordNext⟩ :=
    table_initialized initial before false words le k
      ((tableAssignments true).foldr CC.Stmt.Ssequence afterPointerTables) access
  obtain ⟨after, tagRun, tagRead, tagOther, tagFrame, tagAccess, tagNext⟩ :=
    table_initialized initial middle true tags le k afterPointerTables (wordAccess.trans access)
  refine ⟨after, ?_, ?_, ?_, wordFrame.trans tagFrame,
    tagAccess.trans wordAccess, tagNext.trans wordNext⟩
  · rw [source]
    exact wordRun.trans tagRun
  · intro selected
    cases selected
    · refine ⟨words, table_binding initial false words, cell_binding initial false words, ?_⟩
      intro i
      exact (tagOther _ _ _ words.binding (by decide +kernel) CC.Mptr (8 * (i.val : Int))).trans
        (wordRead i)
    · exact ⟨tags, table_binding initial true tags, cell_binding initial true tags, tagRead⟩
  · intro id ty block bound notWords notTags chunk ofs
    exact (tagOther id ty block bound notTags chunk ofs).trans
      (wordOther id ty block bound notWords chunk ofs)

private theorem cells_separate : ∀ tags (i : Fin 31),
    tableCellName tags i ≠ tableName false ∧ tableCellName tags i ≠ tableName true := by
  decide +kernel

private theorem caches_separate : ∀ returns,
    Arm64Producer.baseName returns ≠ tableName false ∧ Arm64Producer.baseName returns ≠ tableName true ∧
    Arm64Producer.validName returns ≠ tableName false ∧ Arm64Producer.validName returns ≠ tableName true := by
  decide +kernel

/-- Real call entry through registers and both tables. Table pointers identify
exactly the cells with the retained register readbacks, not unrelated witnesses. -/
theorem entry_initialized (initial : CC.Mem) (ctx : CC.Val) (k : CC.Cont)
    (values : Fin 31 → BitVec 64) (provider : Arm64ProducerGprInputs.ProviderAt world initial values) :
    ∃ blocks : Bool → Fin 31 → CC.Block, ∃ after le, ∃ traces : List CC.Trace,
      traces.length = 30 ∧
      (∀ selected i, (Arm64Producer.allocation initial).1.get (tableCellName selected i) =
        some (blocks selected i, tableCellType selected)) ∧
      (∀ selected i, (allocation initial).1.get (tableCellName selected i) =
        some (blocks selected i, tableCellType selected)) ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [ctx] k initial)
        traces.flatten (.State Arm64ProgramFixture.f_arm64_execute_compile afterPointerTables
          k (allocation initial).1 le after) ∧
      (∀ i, CC.Mem.load .Mint64 after (blocks false i) 0 =
          some (.Vlong (Arm64ProgramEntryGprInputs.wordValue values i)) ∧
        CC.Mem.load .Mint8unsigned after (blocks true i) 0 = some (.Vint 0)) ∧
      (∀ selected, ∃ locals : TableLocals selected initial,
        (allocation initial).1.get (tableName selected) = some (locals.tableBlock, tableType selected) ∧
        (∀ i, (allocation initial).1.get (tableCellName selected i) =
          some (locals.cellBlock i, tableCellType selected)) ∧
        ∀ i, CC.Mem.load CC.Mptr after locals.tableBlock (8 * (i.val : Int)) =
          some (.Vptr (blocks selected i) 0)) ∧
      Arm64ProgramEntryInputs.CacheReadbacks initial after ∧ le.get Arm64ProgramFixture._ctx = some ctx ∧
      FrameBelow initial.nextblock initial after ∧ after.access = (allocation initial).2.access ∧
      after.nextblock = (allocation initial).2.nextblock := by
  obtain ⟨blocks, middle, le, traces, length, bindings, actualBindings, registerRun,
      registers, caches, context, frame, access, next⟩ :=
    Arm64ProgramEntryGprInputs.entry_initialized initial ctx k values provider
  obtain ⟨after, tableRun, tables, other, tableFrame, tableAccess, tableNext⟩ :=
    initialized initial middle le k access
  refine ⟨blocks, after, le, traces, length, bindings, actualBindings, ?_, ?_, ?_, ?_, context,
    frame.trans tableFrame, tableAccess.trans access, tableNext.trans next⟩
  · simpa only [CC.E0, CC.Eapp, List.append_nil] using star_trans registerRun tableRun.sound
  · intro i
    exact ⟨(other _ _ _ (bindings false i) (cells_separate false i).1 (cells_separate false i).2 .Mint64 0).trans
        (registers i).1,
      (other _ _ _ (bindings true i) (cells_separate true i).1 (cells_separate true i).2 .Mint8unsigned 0).trans
        (registers i).2⟩
  · intro selected
    obtain ⟨locals, bound, cells, reads⟩ := tables selected
    refine ⟨locals, bound, cells, ?_⟩
    intro i
    have same : locals.cellBlock i = blocks selected i :=
      congrArg Prod.fst (Option.some.inj ((locals.cellBinding i).symm.trans (bindings selected i)))
    simpa only [same] using reads i
  · intro returns
    obtain ⟨locals, baseBound, validBound, base, valid⟩ := caches returns
    refine ⟨locals, baseBound, validBound, ?_, ?_⟩
    · exact (other _ _ _ locals.baseBinding (caches_separate returns).1
        (caches_separate returns).2.1 .Mint64 0).trans base
    · exact (other _ _ _ locals.validBinding (caches_separate returns).2.2.1
        (caches_separate returns).2.2.2 .Mint8unsigned 0).trans valid

end KProgFormal.ClightRefinement.Arm64ProgramEntryTables
