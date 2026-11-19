import KProgFormal.ClightRefinement.Arm64ProducerTableSource

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Producer

/-- Real allocated table and target-local bindings; no contents are assumed. -/
structure TableLocals (tags : Bool) (m : CC.Mem) where
  tableBlock : CC.Block
  binding : (allocation m).1.get (tableName tags) = some (tableBlock, tableType tags)
  fresh : m.nextblock.toNat ≤ tableBlock.toNat
  range : CC.Mem.rangePerm (allocation m).2 tableBlock 0 248 .Cur .Writable = true
  cellBlock : Fin 31 → CC.Block
  cellBinding : ∀ i, (allocation m).1.get (tableCellName tags i) =
    some (cellBlock i, tableCellType tags)

theorem table_locals (tags : Bool) (m : CC.Mem) : Nonempty (TableLocals tags m) := by
  obtain ⟨b, binding, fresh, _, range⟩ := local_storage m (tableName tags) (tableType tags)
    (table_declarations tags).1
  rw [(table_declarations tags).2] at range
  have cells : ∀ i : Fin 31, ∃ b, (allocation m).1.get (tableCellName tags i) =
      some (b, tableCellType tags) := by
    intro i
    obtain ⟨b, binding, _⟩ := local_storage m (tableCellName tags i) (tableCellType tags)
      (table_cell_declaration tags i)
    exact ⟨b, binding⟩
  exact ⟨⟨b, binding, fresh,
    CC.Mem.rangePerm_implies range (by decide : CC.permOrder .Freeable .Writable = true),
    fun i => Classical.choose (cells i), fun i => Classical.choose_spec (cells i)⟩⟩

private theorem table_assignment_exec (world : CC.CGenv) (f : CC.Function) (e : CC.Env) (tags : Bool) (m before after : CC.Mem)
    (locals : TableLocals tags m) (i : Fin 31) (le : CC.TempEnv) (k : CC.Cont) (rest : CC.Stmt)
    (tableBinding : e.get (tableName tags) = some (locals.tableBlock, tableType tags))
    (cellBinding : ∀ j, e.get (tableCellName tags j) = some (locals.cellBlock j, tableCellType tags))
    (stored : CC.Mem.storev CC.Mptr before (.Vptr locals.tableBlock (tableOffset i))
      (.Vptr (locals.cellBlock i) 0) = some after) :
    steps world 3 (.State f (.Ssequence (tableAssignment tags i) rest) k e le before) =
      some (CC.E0, .State f rest k e le after) ∧
    InternalPath world 3 (.State f (.Ssequence (tableAssignment tags i) rest) k e le before) := by
  simp [steps, InternalPath, InternalState, tableAssignment, tableType,
    CC.doStep, CC.doEvalLvalue, CC.doEvalExpr, CC.lvalOfVar, CC.doDerefLoc,
    CC.doAssignLoc, CC.accessMode, CC.typeof, CC.Cop.semBinaryOperation,
    CC.Cop.semAdd, CC.Cop.classifyAdd, CC.Cop.semAddPtrInt, CC.Cop.ptrofsOfInt,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.typeconv, CC.removeAttributes, CC.tattr,
    CC.sizeof, CC.tarray, CC.tptr, CC.tint, CC.Archi.ptr64, tableOffset,
    CC.Integers.Ptrofs.zero, CC.Integers.MI.zero,
    tableBinding, cellBinding, CC.E0, CC.Eapp] at stored ⊢
  simp [stored, CC.doStep, CC.E0, CC.Eapp, InternalState, InternalPath, steps]

private theorem table_write (world : CC.CGenv) (f : CC.Function) (e : CC.Env) (tags : Bool) (m before : CC.Mem) (locals : TableLocals tags m)
    (i : Fin 31) (le : CC.TempEnv) (k : CC.Cont) (rest : CC.Stmt)
    (tableBinding : e.get (tableName tags) = some (locals.tableBlock, tableType tags))
    (cellBinding : ∀ j, e.get (tableCellName tags j) = some (locals.cellBlock j, tableCellType tags))
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world 3
        (.State f (.Ssequence (tableAssignment tags i) rest) k e le before)
        (.State f rest k e le after) ∧
      CC.Mem.load CC.Mptr after locals.tableBlock (8 * (i.val : Int)) =
        some (.Vptr (locals.cellBlock i) 0) ∧
      (∀ j : Fin 31, j ≠ i → CC.Mem.load CC.Mptr after locals.tableBlock (8 * (j.val : Int)) =
        CC.Mem.load CC.Mptr before locals.tableBlock (8 * (j.val : Int))) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ tableName tags →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  have writable : CC.Mem.validAccess before CC.Mptr locals.tableBlock (8 * (i.val : Int)) .Writable = true := by
    simp only [CC.Mem.validAccess, Bool.and_eq_true]
    refine ⟨?_, ?_⟩
    · apply CC.Mem.rangePerm_intro
      intro ofs lower upper
      have bound := i.isLt
      have lo : (0 : Int) ≤ ofs := by omega
      have hi : ofs < (248 : Int) := by change ofs < 8 * (i.val : Int) + 8 at upper; omega
      have perm := CC.Mem.rangePerm_perm (allocation m).2 locals.tableBlock 0 248 .Cur .Writable
        locals.range ofs lo hi
      simpa only [CC.Mem.perm, access] using perm
    · change ((8 * (i.val : Int)) % 8 == 0) = true
      have aligned : (8 * (i.val : Int)) % 8 = 0 := by omega
      simp only [aligned, beq_self_eq_true]
  have storeExists : ∃ after, CC.Mem.store CC.Mptr before locals.tableBlock (8 * (i.val : Int))
      (.Vptr (locals.cellBlock i) 0) = some after := by
    unfold CC.Mem.store
    rw [writable]
    exact ⟨_, rfl⟩
  obtain ⟨after, stored⟩ := storeExists
  have storev : CC.Mem.storev CC.Mptr before (.Vptr locals.tableBlock (tableOffset i))
      (.Vptr (locals.cellBlock i) 0) = some after := by
    simpa only [CC.Mem.storev, table_offsets] using stored
  have exec := table_assignment_exec world f e tags m before after locals i le k rest tableBinding cellBinding storev
  refine ⟨after, internalRun_of_steps exec.2 exec.1, ?_, ?_, ?_,
    FrameBelow.store locals.fresh stored, CC.Mem.store_access stored, CC.Mem.store_nextblock stored⟩
  · simpa [CC.Mptr, CC.Archi.ptr64, CC.Val.loadResult] using CC.Mem.load_store_same stored
  · intro j different
    have ne : j.val ≠ i.val := fun h => different (Fin.ext h)
    have separate : 8 * (j.val : Int) + 8 ≤ 8 * (i.val : Int) ∨
        8 * (i.val : Int) + 8 ≤ 8 * (j.val : Int) := by omega
    apply CC.Mem.load_store_other stored
    exact Or.inr separate
  · intro id ty block bound different chunk ofs
    have distinct := (allocated_local_storage
      (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm)).2
    exact CC.Mem.load_store_other stored chunk block ofs
      (.inl (distinct _ _ _ _ bound locals.binding different))

private theorem run_table_list (world : CC.CGenv) (f : CC.Function) (e : CC.Env) (tags : Bool) (m : CC.Mem) (locals : TableLocals tags m)
    (rows : List (Fin 31)) (rest : CC.Stmt) (le : CC.TempEnv) (k : CC.Cont)
    (before : CC.Mem)
    (tableBinding : e.get (tableName tags) = some (locals.tableBlock, tableType tags))
    (cellBinding : ∀ j, e.get (tableCellName tags j) = some (locals.cellBlock j, tableCellType tags))
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world (3 * rows.length)
        (.State f (rows.foldr (fun i next => .Ssequence (tableAssignment tags i) next) rest)
          k e le before)
        (.State f rest k e le after) ∧
      (∀ i ∈ rows, CC.Mem.load CC.Mptr after locals.tableBlock (8 * (i.val : Int)) =
        some (.Vptr (locals.cellBlock i) 0)) ∧
      (∀ i ∉ rows, CC.Mem.load CC.Mptr after locals.tableBlock (8 * (i.val : Int)) =
        CC.Mem.load CC.Mptr before locals.tableBlock (8 * (i.val : Int))) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ tableName tags →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  induction rows generalizing before with
  | nil =>
    refine ⟨before, .refl _, ?_, ?_, ?_, FrameBelow.refl _ _, rfl, rfl⟩
    · intro i member; cases member
    · intro i _; rfl
    · intro id ty block bound different chunk ofs; rfl
  | cons head tail ih =>
    obtain ⟨middle, headRun, headRead, headOther, headLocals, headFrame, headAccess, headNext⟩ :=
      table_write world f e tags m before locals head le k
        (tail.foldr (fun i next => .Ssequence (tableAssignment tags i) next) rest) tableBinding cellBinding access
    obtain ⟨after, tailRun, tailRead, tailOther, tailLocals, tailFrame, tailAccess, tailNext⟩ :=
      ih middle (headAccess.trans access)
    refine ⟨after, ?_, ?_, ?_, ?_, headFrame.trans tailFrame,
      tailAccess.trans headAccess, tailNext.trans headNext⟩
    · simpa only [List.foldr_cons, List.length_cons, Nat.mul_add, Nat.mul_one,
        Nat.add_comm] using headRun.trans tailRun
    · intro i member
      by_cases later : i ∈ tail
      · exact tailRead i later
      · have same : i = head := (List.mem_cons.mp member).resolve_right later
        subst i
        exact (tailOther head later).trans headRead
    · intro i absent
      have notHead : i ≠ head := by intro same; apply absent; simp [same]
      have notTail : i ∉ tail := fun member => absent (List.mem_cons_of_mem _ member)
      exact (tailOther i notTail).trans (headOther i notHead)
    · intro id ty block bound different chunk ofs
      exact (tailLocals id ty block bound different chunk ofs).trans
        (headLocals id ty block bound different chunk ofs)

/-- All 31 actual slots of either selected table are initialized from the
real local addresses, preserving every other declared local load. -/
theorem initialize_pointer_table_body (world : CC.CGenv) (f : CC.Function) (e : CC.Env) (tags : Bool) (m before : CC.Mem) (le : CC.TempEnv)
    (k : CC.Cont) (rest : CC.Stmt) (locals : TableLocals tags m)
    (tableBinding : e.get (tableName tags) = some (locals.tableBlock, tableType tags))
    (cellBinding : ∀ j, e.get (tableCellName tags j) = some (locals.cellBlock j, tableCellType tags))
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world 93
        (.State f ((tableAssignments tags).foldr CC.Stmt.Ssequence rest)
          k e le before)
        (.State f rest k e le after) ∧
      (∀ i, CC.Mem.load CC.Mptr after locals.tableBlock (8 * (i.val : Int)) =
        some (.Vptr (locals.cellBlock i) 0)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ tableName tags →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨after, run, read, _, other, frame, finalAccess, next⟩ :=
    run_table_list world f e tags m locals (List.finRange 31) rest le k before tableBinding cellBinding access
  refine ⟨after, ?_, (fun i => read i (List.mem_finRange i)), other, frame, finalAccess, next⟩
  have mapped : tableAssignments tags = (List.finRange 31).map (tableAssignment tags) := by
    simp only [tableAssignments, List.finRange, List.map_ofFn, Function.comp_def]
  simpa only [List.length_finRange, mapped, List.foldr_map] using run

theorem initialize_pointer_table_bound (world : CC.CGenv) (tags : Bool) (m before : CC.Mem) (le : CC.TempEnv)
    (k : CC.Cont) (rest : CC.Stmt) (access : before.access = (allocation m).2.access) :
    ∃ locals : TableLocals tags m, ∃ after, InternalRun world 93
        (.State producer ((tableAssignments tags).foldr CC.Stmt.Ssequence rest)
          k (allocation m).1 le before)
        (.State producer rest k (allocation m).1 le after) ∧
      (∀ i, CC.Mem.load CC.Mptr after locals.tableBlock (8 * (i.val : Int)) =
        some (.Vptr (locals.cellBlock i) 0)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ tableName tags →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨locals⟩ := table_locals tags m
  obtain ⟨after, run, reads, other, frame, finalAccess, next⟩ :=
    initialize_pointer_table_body world producer (allocation m).1 tags m before le k rest
      locals locals.binding locals.cellBinding access
  exact ⟨locals, after, run, reads, other, frame, finalAccess, next⟩

/-- The actual 62-table-store producer segment completes with both complete
typed pointer tables and exact framing of other local loads and caller blocks. -/
theorem pointer_tables_initialized_bound (world : CC.CGenv) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world 186
        (.State producer (registerDeclaration 30).rest k (allocation m).1 le before)
        (.State producer afterPointerTables k (allocation m).1 le after) ∧
      (∀ tags, ∃ locals : TableLocals tags m, ∀ i,
        CC.Mem.load CC.Mptr after locals.tableBlock (8 * (i.val : Int)) =
          some (.Vptr (locals.cellBlock i) 0)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) →
        id ≠ tableName false → id ≠ tableName true →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨words, middle, wordRun, wordRead, wordOther, wordFrame, wordAccess, wordNext⟩ :=
    initialize_pointer_table_bound world false m before le k
      ((tableAssignments true).foldr CC.Stmt.Ssequence afterPointerTables) access
  obtain ⟨tags, after, tagRun, tagRead, tagOther, tagFrame, tagAccess, tagNext⟩ :=
    initialize_pointer_table_bound world true m middle le k afterPointerTables (wordAccess.trans access)
  refine ⟨after, ?_, ?_, ?_, wordFrame.trans tagFrame,
    tagAccess.trans wordAccess, tagNext.trans wordNext⟩
  · rw [pointer_tables_source]
    exact wordRun.trans tagRun
  · intro selected
    cases selected
    · refine ⟨words, ?_⟩
      intro i
      exact (tagOther _ _ _ words.binding (by decide +kernel) CC.Mptr (8 * (i.val : Int))).trans
        (wordRead i)
    · exact ⟨tags, tagRead⟩
  · intro id ty block bound notWord notTag chunk ofs
    exact (tagOther id ty block bound notTag chunk ofs).trans
      (wordOther id ty block bound notWord chunk ofs)

/-- The real x30 zero branch followed immediately by both pointer tables.
The zero register/tag observations survive the table writes. -/
theorem register30_and_pointer_tables_bound (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    let d := registerDeclaration 30
    ∃ xb tb after,
      (allocation m).1.get d.word = some (xb, .Tunion Arm64Entry._arm64_sim_gpr CC.noattr) ∧
      (allocation m).1.get d.tag = some (tb, CC.tuchar) ∧
      InternalRun world 196 (.State producer (registerDeclarationStage 30) k (allocation m).1 le before)
        (.State producer afterPointerTables k (allocation m).1
          (le.set d.resultTemp (.Vlong (0#64))) after) ∧
      CC.Mem.loadv .Mint64 after (.Vptr xb 0) = some (.Vlong 0) ∧
      CC.Mem.loadv .Mint8unsigned after (.Vptr tb 0) = some (.Vint 0) ∧
      (∀ tags, ∃ locals : TableLocals tags m, ∀ i,
        CC.Mem.load CC.Mptr after locals.tableBlock (8 * (i.val : Int)) =
          some (.Vptr (locals.cellBlock i) 0)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) →
        id ≠ (registerDeclaration 30).word → id ≠ (registerDeclaration 30).tag →
        id ≠ tableName false → id ≠ tableName true →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  dsimp only
  obtain ⟨xb, tb, middle, wordBinding, tagBinding, zeroRun, zeroWord, zeroTag, zeroOther, zeroFrame, zeroAccess, zeroNext⟩ :=
    register30_initialized_bound world layout m before le k access
  obtain ⟨after, tableRun, tables, other, tableFrame, tableAccess, tableNext⟩ :=
    pointer_tables_initialized_bound world m middle
      (le.set (registerDeclaration 30).resultTemp (.Vlong (0#64))) k (zeroAccess.trans access)
  refine ⟨xb, tb, after, wordBinding, tagBinding, zeroRun.trans tableRun, ?_, ?_, tables, ?_,
    zeroFrame.trans tableFrame, tableAccess.trans zeroAccess, tableNext.trans zeroNext⟩
  · exact (other _ _ _ wordBinding (by decide +kernel) (by decide +kernel) .Mint64 0).trans zeroWord
  · exact (other _ _ _ tagBinding (by decide +kernel) (by decide +kernel) .Mint8unsigned 0).trans zeroTag

  · intro id ty block bound notWord notTag notWords notTags chunk ofs
    exact (other id ty block bound notWords notTags chunk ofs).trans
      (zeroOther id ty block bound notWord notTag chunk ofs)

theorem initialize_pointer_table (tags : Bool) (m before : CC.Mem) (le : CC.TempEnv)
    (k : CC.Cont) (rest : CC.Stmt) (access : before.access = (allocation m).2.access) :
    ∃ locals : TableLocals tags m, ∃ after, InternalRun ge 93
        (.State producer ((tableAssignments tags).foldr CC.Stmt.Ssequence rest)
          k (allocation m).1 le before)
        (.State producer rest k (allocation m).1 le after) ∧
      (∀ i, CC.Mem.load CC.Mptr after locals.tableBlock (8 * (i.val : Int)) =
        some (.Vptr (locals.cellBlock i) 0)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ tableName tags →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock :=
  initialize_pointer_table_bound ge tags m before le k rest access

theorem pointer_tables_initialized (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun ge 186
        (.State producer (registerDeclaration 30).rest k (allocation m).1 le before)
        (.State producer afterPointerTables k (allocation m).1 le after) ∧
      (∀ tags, ∃ locals : TableLocals tags m, ∀ i,
        CC.Mem.load CC.Mptr after locals.tableBlock (8 * (i.val : Int)) =
          some (.Vptr (locals.cellBlock i) 0)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) →
        id ≠ tableName false → id ≠ tableName true →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock :=
  pointer_tables_initialized_bound ge m before le k access

theorem register30_and_pointer_tables (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    let d := registerDeclaration 30
    ∃ xb tb after,
      (allocation m).1.get d.word = some (xb, .Tunion Arm64Entry._arm64_sim_gpr CC.noattr) ∧
      (allocation m).1.get d.tag = some (tb, CC.tuchar) ∧
      InternalRun ge 196 (.State producer (registerDeclarationStage 30) k (allocation m).1 le before)
        (.State producer afterPointerTables k (allocation m).1
          (le.set d.resultTemp (.Vlong (0#64))) after) ∧
      CC.Mem.loadv .Mint64 after (.Vptr xb 0) = some (.Vlong 0) ∧
      CC.Mem.loadv .Mint8unsigned after (.Vptr tb 0) = some (.Vint 0) ∧
      (∀ tags, ∃ locals : TableLocals tags m, ∀ i,
        CC.Mem.load CC.Mptr after locals.tableBlock (8 * (i.val : Int)) =
          some (.Vptr (locals.cellBlock i) 0)) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨xb, tb, after, wordBinding, tagBinding, run, word, tag, tables, _, frame, finalAccess, next⟩ :=
    register30_and_pointer_tables_bound ge rfl m before le k access
  exact ⟨xb, tb, after, wordBinding, tagBinding, run, word, tag, tables, frame, finalAccess, next⟩

end KProgFormal.ClightRefinement.Arm64Producer
