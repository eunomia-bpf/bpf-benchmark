import KProgFormal.ClightRefinement.Arm64ProducerHeader

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Producer

private def nullVectorParts : List CC.Stmt × CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(afterHeaderPointers)) none
    let mut rows : Array Lean.Expr := #[]
    for _ in [:64] do
      body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "header vector-pointer initializer sequence changed"
      let head ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body.getAppArgs[0]!)
      rows := rows.push head
      body := body.getAppArgs[1]!
    let front ← Lean.Meta.mkListLit (Lean.mkConst ``CC.Stmt) rows.toList
    Lean.Elab.Tactic.closeMainGoal `actual_vector_pointer_zeroes (← Lean.Meta.mkAppM ``Prod.mk #[front, body])

def nullVectorTarget (i : Fin 64) : CC.Expr :=
  .Ederef (.Ebinop .Oadd
    (.Efield (.Evar Arm64Entry._entry headerType)
      (if i.val < 32 then Arm64Entry._vector_lo else Arm64Entry._vector_hi)
      (CC.tarray (CC.tptr CC.tulong) 32))
    (.Econst_int (CC.Integers.Int.repr (i.val % 32)) CC.tint)
    (CC.tptr (CC.tptr CC.tulong))) (CC.tptr CC.tulong)

def nullVectorStore (i : Fin 64) : CC.Stmt :=
  .Sassign (nullVectorTarget i) (.Ecast (.Econst_int 0 CC.tint) (CC.tptr CC.tvoid))

def afterNullVectorPointers : CC.Stmt := nullVectorParts.2

theorem null_vector_source : afterHeaderPointers =
    (List.ofFn nullVectorStore).foldr CC.Stmt.Ssequence afterNullVectorPointers := by
  have rows : nullVectorParts.1 = List.ofFn nullVectorStore := rfl
  have source : afterHeaderPointers = nullVectorParts.1.foldr CC.Stmt.Ssequence afterNullVectorPointers := rfl
  rw [rows] at source
  exact source

private def nullVectorComposite : CC.Composite :=
  (ge.genv_cenv.get Arm64Entry._kprog_arm64_entry).get (by decide +kernel)

theorem null_vector_layout :
    ge.genv_cenv.get Arm64Entry._kprog_arm64_entry = some nullVectorComposite ∧
    CC.fieldOffset ge.genv_cenv Arm64Entry._vector_lo nullVectorComposite.co_members = .OK (96, .Full) ∧
    CC.fieldOffset ge.genv_cenv Arm64Entry._vector_hi nullVectorComposite.co_members = .OK (352, .Full) ∧
    CC.sizeof ge.genv_cenv headerType = 728 := by decide +kernel

def nullVectorOffset (i : Fin 64) : CC.Integers.Ptrofs :=
  CC.Integers.Ptrofs.add
    (CC.Integers.Ptrofs.add 0 (CC.Integers.Ptrofs.repr (if i.val < 32 then 96 else 352)))
    (CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr 8)
      (CC.Integers.Ptrofs.of_ints (CC.Integers.Int.repr (i.val % 32))))

theorem null_vector_offsets : ∀ i : Fin 64,
    CC.Integers.Ptrofs.unsigned (nullVectorOffset i) = 96 + 8 * (i.val : Int) := by decide +kernel

private theorem null_vector_lvalue (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (m before : CC.Mem) (le : CC.TempEnv)
    (entry : HeaderLocal m) (i : Fin 64) :
    CC.doEvalLvalue world (allocation m).1 le before (nullVectorTarget i) =
      some (entry.block, nullVectorOffset i, .Full) := by
  by_cases low : i.val < 32
  all_goals simp [nullVectorTarget, low, headerType, CC.doEvalLvalue, CC.doEvalExpr,
    CC.lvalOfVar, CC.doDerefLoc, CC.lvalOfField, CC.typeof, CC.accessMode, entry.binding, layout,
    null_vector_layout.1, null_vector_layout.2.1, null_vector_layout.2.2.1,
    CC.Cop.semBinaryOperation, CC.Cop.semAdd, CC.Cop.classifyAdd, CC.Cop.semAddPtrInt,
    CC.Cop.ptrofsOfInt, CC.typeconv, CC.removeAttributes, CC.tattr, CC.sizeof,
    CC.tptr, CC.tarray, CC.tint, nullVectorOffset]
  all_goals rfl

private theorem null_vector_write (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (entry : HeaderLocal m) (i : Fin 64) (rest : CC.Stmt)
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world 3
        (.State producer (.Ssequence (nullVectorStore i) rest) k (allocation m).1 le before)
        (.State producer rest k (allocation m).1 le after) ∧
      CC.Mem.load CC.Mptr after entry.block (96 + 8 * (i.val : Int)) = some (.Vlong 0) ∧
      (∀ j : Fin 64, j ≠ i → CC.Mem.load CC.Mptr after entry.block (96 + 8 * (j.val : Int)) =
        CC.Mem.load CC.Mptr before entry.block (96 + 8 * (j.val : Int))) ∧
      (∀ j : Fin 12, CC.Mem.load CC.Mptr after entry.block (8 * (j.val : Int)) =
        CC.Mem.load CC.Mptr before entry.block (8 * (j.val : Int))) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry._entry →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  have writable : CC.Mem.validAccess before CC.Mptr entry.block (96 + 8 * (i.val : Int)) .Writable = true := by
    simp only [CC.Mem.validAccess, Bool.and_eq_true]
    refine ⟨?_, ?_⟩
    · apply CC.Mem.rangePerm_intro
      intro ofs lower upper
      have bound := i.isLt
      have lo : (0 : Int) ≤ ofs := by omega
      have hi : ofs < CC.sizeof ge.genv_cenv headerType := by
        change ofs < 96 + 8 * (i.val : Int) + 8 at upper
        rw [null_vector_layout.2.2.2]
        omega
      have perm := CC.Mem.rangePerm_perm (allocation m).2 entry.block 0
        (CC.sizeof ge.genv_cenv headerType) .Cur .Writable entry.range ofs lo hi
      simpa only [CC.Mem.perm, access] using perm
    · change ((96 + 8 * (i.val : Int)) % 8 == 0) = true
      have aligned : (96 + 8 * (i.val : Int)) % 8 = 0 := by omega
      simp only [aligned, beq_self_eq_true]
  have existsStore : ∃ after, CC.Mem.store CC.Mptr before entry.block (96 + 8 * (i.val : Int))
      (.Vlong 0) = some after := by
    unfold CC.Mem.store
    rw [writable]
    exact ⟨_, rfl⟩
  obtain ⟨after, stored⟩ := existsStore
  have storev : CC.Mem.storev CC.Mptr before (.Vptr entry.block (nullVectorOffset i)) (.Vlong 0) = some after := by
    simpa only [CC.Mem.storev, null_vector_offsets] using stored
  have target := null_vector_lvalue world layout m before le entry i
  have assigned : CC.doStep world
      (.State producer (nullVectorStore i) (.Kseq rest k) (allocation m).1 le before) =
      some (CC.E0, .State producer .Sskip (.Kseq rest k) (allocation m).1 le after) := by
    simp only [nullVectorStore, CC.doStep, target]
    rw [show CC.typeof (nullVectorTarget i) = CC.tptr CC.tulong from rfl]
    change (match CC.Mem.storev CC.Mptr before (.Vptr entry.block (nullVectorOffset i)) (.Vlong 0) with
      | some memory => some (CC.E0, CC.State.State producer .Sskip (.Kseq rest k) (allocation m).1 le memory)
      | none => none) = _
    rw [storev]
  have run : InternalRun world 3
      (.State producer (.Ssequence (nullVectorStore i) rest) k (allocation m).1 le before)
      (.State producer rest k (allocation m).1 le after) :=
    .step trivial (CC.doStep_sound world _ _ _ rfl)
      (.step trivial (CC.doStep_sound world _ _ _ assigned)
        (.step trivial (CC.doStep_sound world _ _ _ rfl) (.refl _)))
  refine ⟨after, run, CC.Mem.load_store_same stored, ?_, ?_, ?_,
    FrameBelow.store entry.fresh stored, CC.Mem.store_access stored, CC.Mem.store_nextblock stored⟩
  · intro j different
    have ne : j.val ≠ i.val := fun h => different (Fin.ext h)
    have separate : 96 + 8 * (j.val : Int) + 8 ≤ 96 + 8 * (i.val : Int) ∨
        96 + 8 * (i.val : Int) + 8 ≤ 96 + 8 * (j.val : Int) := by omega
    exact CC.Mem.load_store_other stored CC.Mptr entry.block _ (.inr separate)
  · intro j
    apply CC.Mem.load_store_other stored
    right; left
    have bound := j.isLt
    change 8 * (j.val : Int) + 8 ≤ 96 + 8 * (i.val : Int)
    omega
  · intro id ty block bound different chunk ofs
    have distinct := (allocated_local_storage
      (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm)).2
    exact CC.Mem.load_store_other stored chunk block ofs
      (.inl (distinct _ _ _ _ bound entry.binding different))

private theorem run_null_vectors (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (m : CC.Mem) (entry : HeaderLocal m) (rows : List (Fin 64))
    (rest : CC.Stmt) (le : CC.TempEnv) (k : CC.Cont) (before : CC.Mem)
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world (3 * rows.length)
        (.State producer (rows.foldr (fun i next => .Ssequence (nullVectorStore i) next) rest)
          k (allocation m).1 le before)
        (.State producer rest k (allocation m).1 le after) ∧
      (∀ i ∈ rows, CC.Mem.load CC.Mptr after entry.block (96 + 8 * (i.val : Int)) = some (.Vlong 0)) ∧
      (∀ i ∉ rows, CC.Mem.load CC.Mptr after entry.block (96 + 8 * (i.val : Int)) =
        CC.Mem.load CC.Mptr before entry.block (96 + 8 * (i.val : Int))) ∧
      (∀ j : Fin 12, CC.Mem.load CC.Mptr after entry.block (8 * (j.val : Int)) =
        CC.Mem.load CC.Mptr before entry.block (8 * (j.val : Int))) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry._entry →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  induction rows generalizing before with
  | nil =>
    refine ⟨before, .refl _, ?_, ?_, ?_, ?_, FrameBelow.refl _ _, rfl, rfl⟩
    · intro i member; cases member
    · intro i absent; rfl
    · intro j; rfl
    · intro id ty block bound different chunk ofs; rfl
  | cons head tail ih =>
    obtain ⟨middle, headRun, headRead, headOther, headScalars, headLocals, headFrame, headAccess, headNext⟩ :=
      null_vector_write world layout m before le k entry head
        (tail.foldr (fun i next => .Ssequence (nullVectorStore i) next) rest) access
    obtain ⟨after, tailRun, tailRead, tailOther, tailScalars, tailLocals, tailFrame, tailAccess, tailNext⟩ :=
      ih middle (headAccess.trans access)
    refine ⟨after, ?_, ?_, ?_, ?_, ?_, headFrame.trans tailFrame,
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
    · intro j
      exact (tailScalars j).trans (headScalars j)
    · intro id ty block bound different chunk ofs
      exact (tailLocals id ty block bound different chunk ofs).trans
        (headLocals id ty block bound different chunk ofs)

/-- All 64 actual null pointer initializers execute, retaining the twelve scalar
header pointers and every other declared local. -/
theorem null_vector_pointers_initialized_bound (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (m before : CC.Mem) (entry : HeaderLocal m)
    (le : CC.TempEnv) (k : CC.Cont) (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world 192
        (.State producer afterHeaderPointers k (allocation m).1 le before)
        (.State producer afterNullVectorPointers k (allocation m).1 le after) ∧
      (∀ i : Fin 64, CC.Mem.load CC.Mptr after entry.block (96 + 8 * (i.val : Int)) = some (.Vlong 0)) ∧
      (∀ j : Fin 12, CC.Mem.load CC.Mptr after entry.block (8 * (j.val : Int)) =
        CC.Mem.load CC.Mptr before entry.block (8 * (j.val : Int))) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry._entry →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨after, run, read, _, scalars, other, frame, finalAccess, next⟩ :=
    run_null_vectors world layout m entry (List.finRange 64) afterNullVectorPointers le k before access
  refine ⟨after, ?_, (fun i => read i (List.mem_finRange i)), scalars, other, frame, finalAccess, next⟩
  have mapped : List.ofFn nullVectorStore = (List.finRange 64).map nullVectorStore := by
    simp only [List.finRange, List.map_ofFn, Function.comp_def]
  rw [null_vector_source]
  simpa only [List.length_finRange, mapped, List.foldr_map] using run

theorem null_vector_pointers_initialized (m before : CC.Mem) (entry : HeaderLocal m)
    (le : CC.TempEnv) (k : CC.Cont) (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun ge 192
        (.State producer afterHeaderPointers k (allocation m).1 le before)
        (.State producer afterNullVectorPointers k (allocation m).1 le after) ∧
      (∀ i : Fin 64, CC.Mem.load CC.Mptr after entry.block (96 + 8 * (i.val : Int)) = some (.Vlong 0)) ∧
      (∀ j : Fin 12, CC.Mem.load CC.Mptr after entry.block (8 * (j.val : Int)) =
        CC.Mem.load CC.Mptr before entry.block (8 * (j.val : Int))) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry._entry →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock :=
  null_vector_pointers_initialized_bound ge rfl m before entry le k access

/-- The twelve scalar pointers and 64 null vector pointers execute in their
actual source order, retaining all observations at the same allocated entry. -/
theorem header_and_null_vector_pointers_bound (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ entry : HeaderLocal m, ∃ cells : (i : Fin 12) → HeaderSourceLocal m i, ∃ after,
      InternalRun world 228 (.State producer afterContext k (allocation m).1 le before)
        (.State producer afterNullVectorPointers k (allocation m).1 le after) ∧
      (∀ i, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) = some (.Vptr (cells i).block 0)) ∧
      (∀ i : Fin 64, CC.Mem.load CC.Mptr after entry.block (96 + 8 * (i.val : Int)) = some (.Vlong 0)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry._entry →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨entry, cells, middle, headRun, headReads, headLocals, headFrame, headAccess, headNext⟩ :=
    header_initialized_bound world layout m before le k access
  obtain ⟨after, tailRun, nullReads, scalars, tailLocals, tailFrame, tailAccess, tailNext⟩ :=
    null_vector_pointers_initialized_bound world layout m middle entry le k (headAccess.trans access)
  refine ⟨entry, cells, after, headRun.trans tailRun, ?_, nullReads, ?_, headFrame.trans tailFrame,
    tailAccess.trans headAccess, tailNext.trans headNext⟩
  · intro i
    exact (scalars i).trans (headReads i)
  · intro id ty block bound different chunk ofs
    exact (tailLocals id ty block bound different chunk ofs).trans
      (headLocals id ty block bound different chunk ofs)

theorem header_and_null_vector_pointers (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ entry : HeaderLocal m, ∃ cells : (i : Fin 12) → HeaderSourceLocal m i, ∃ after,
      InternalRun ge 228 (.State producer afterContext k (allocation m).1 le before)
        (.State producer afterNullVectorPointers k (allocation m).1 le after) ∧
      (∀ i, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) = some (.Vptr (cells i).block 0)) ∧
      (∀ i : Fin 64, CC.Mem.load CC.Mptr after entry.block (96 + 8 * (i.val : Int)) = some (.Vlong 0)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry._entry →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock :=
  header_and_null_vector_pointers_bound ge rfl m before le k access

/-- The reached post-null-initialization memory satisfies both existing cache
contracts, constructed from the preserved actual scalar header pointers. -/
theorem header_and_null_vector_caches_bound (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ stack : CacheLocals false m, ∃ returns : CacheLocals true m, ∃ after,
      InternalRun world 228 (.State producer afterContext k (allocation m).1 le before)
        (.State producer afterNullVectorPointers k (allocation m).1 le after) ∧
      Nonempty (Arm64RegisterReads.BorrowedCacheStorage false (allocation m).2.nextblock stack.entryBlock 0 after) ∧
      Nonempty (Arm64RegisterReads.BorrowedCacheStorage true (allocation m).2.nextblock returns.entryBlock 0 after) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨entry, cells, after, run, reads, _, _, frame, afterAccess, next⟩ :=
    header_and_null_vector_pointers_bound world layout m before le k access
  obtain ⟨stack, stackStorage⟩ := header_cache_storage false m after entry cells (afterAccess.trans access) reads
  obtain ⟨returns, returnStorage⟩ := header_cache_storage true m after entry cells (afterAccess.trans access) reads
  exact ⟨stack, returns, after, run, stackStorage, returnStorage, frame, afterAccess, next⟩

theorem header_and_null_vector_caches (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ stack : CacheLocals false m, ∃ returns : CacheLocals true m, ∃ after,
      InternalRun ge 228 (.State producer afterContext k (allocation m).1 le before)
        (.State producer afterNullVectorPointers k (allocation m).1 le after) ∧
      Nonempty (Arm64RegisterReads.BorrowedCacheStorage false (allocation m).2.nextblock stack.entryBlock 0 after) ∧
      Nonempty (Arm64RegisterReads.BorrowedCacheStorage true (allocation m).2.nextblock returns.entryBlock 0 after) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock :=
  header_and_null_vector_caches_bound ge rfl m before le k access

end KProgFormal.ClightRefinement.Arm64Producer
