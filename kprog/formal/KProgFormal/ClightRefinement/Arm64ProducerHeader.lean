import KProgFormal.ClightRefinement.Arm64ProducerContext
import KProgFormal.ClightRefinement.Arm64RegisterReads

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Producer

def headerType : CC.Ty := .Tstruct Arm64Entry._kprog_arm64_entry CC.noattr

def headerField (i : Fin 12) : CC.Ident :=
  [Arm64Entry._cells, Arm64Entry._tag_cells, Arm64Entry._sp_base, Arm64Entry._return_base,
   Arm64Entry._lr, Arm64Entry._sp, Arm64Entry._sp_valid, Arm64Entry._return_valid,
   Arm64Entry._n, Arm64Entry._z, Arm64Entry._c, Arm64Entry._v][i]

def headerSourceName (i : Fin 12) : CC.Ident :=
  [Arm64Entry.___a64_cells, Arm64Entry.___a64_tag_cells,
   Arm64Entry.___a64_numeric_sp, Arm64Entry.___a64_numeric_return,
   Arm64Entry.___a64_lr, Arm64Entry.___a64_sp,
   Arm64Entry.___a64_numeric_sp_valid, Arm64Entry.___a64_numeric_return_valid,
   Arm64Entry.___a64_n, Arm64Entry.___a64_z, Arm64Entry.___a64_c, Arm64Entry.___a64_v][i]

def headerSourceType (i : Fin 12) : CC.Ty :=
  [CC.tarray (CC.tptr (.Tunion Arm64Entry._arm64_sim_gpr CC.noattr)) 31,
   CC.tarray (CC.tptr CC.tuchar) 31, CC.tulong, CC.tulong, CC.tulong, CC.tlong,
   CC.tuchar, CC.tuchar, CC.tuchar, CC.tuchar, CC.tuchar, CC.tuchar][i]

def headerPointerType (i : Fin 12) : CC.Ty :=
  [CC.tptr (CC.tptr (.Tunion Arm64Entry._arm64_sim_gpr CC.noattr)),
   CC.tptr (CC.tptr CC.tuchar), CC.tptr CC.tulong, CC.tptr CC.tulong,
   CC.tptr CC.tulong, CC.tptr CC.tlong, CC.tptr CC.tuchar, CC.tptr CC.tuchar,
   CC.tptr CC.tuchar, CC.tptr CC.tuchar, CC.tptr CC.tuchar, CC.tptr CC.tuchar][i]

def headerTarget (i : Fin 12) : CC.Expr :=
  .Efield (.Evar Arm64Entry._entry headerType) (headerField i) (headerPointerType i)

def headerRhs (i : Fin 12) : CC.Expr :=
  if i.val < 2 then .Evar (headerSourceName i) (headerSourceType i)
  else .Eaddrof (.Evar (headerSourceName i) (headerSourceType i)) (headerPointerType i)

def headerAssignment (i : Fin 12) : CC.Stmt := .Sassign (headerTarget i) (headerRhs i)

private def headerParts : List CC.Stmt × CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(afterContext)) none
    let mut rows : Array Lean.Expr := #[]
    for _ in [:12] do
      body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "producer header initializer sequence changed"
      let head ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body.getAppArgs[0]!)
      rows := rows.push head
      body := body.getAppArgs[1]!
    let front ← Lean.Meta.mkListLit (Lean.mkConst ``CC.Stmt) rows.toList
    Lean.Elab.Tactic.closeMainGoal `actual_header_stores (← Lean.Meta.mkAppM ``Prod.mk #[front, body])

def afterHeaderPointers : CC.Stmt := headerParts.2

theorem header_source : afterContext =
    (List.ofFn headerAssignment).foldr CC.Stmt.Ssequence afterHeaderPointers := by
  have rows : headerParts.1 = List.ofFn headerAssignment := rfl
  have source : afterContext = headerParts.1.foldr CC.Stmt.Ssequence afterHeaderPointers := rfl
  rw [rows] at source
  exact source

private def headerComposite : CC.Composite :=
  (ge.genv_cenv.get Arm64Entry._kprog_arm64_entry).get (by decide +kernel)

private theorem twelve_cases : ∀ i : Fin 12, i = 0 ∨ i = 1 ∨ i = 2 ∨ i = 3 ∨ i = 4 ∨ i = 5 ∨ i = 6 ∨ i = 7 ∨ i = 8 ∨ i = 9 ∨ i = 10 ∨ i = 11 := by decide +kernel

theorem header_layout :
    ge.genv_cenv.get Arm64Entry._kprog_arm64_entry = some headerComposite ∧
    (∀ i, CC.fieldOffset ge.genv_cenv (headerField i) headerComposite.co_members =
      .OK (8 * (i.val : Int), .Full)) ∧
    (∀ i, CC.Cop.classifyCast (CC.typeof (headerRhs i)) (CC.typeof (headerTarget i)) = .pointer) ∧
    (∀ i, CC.accessMode (CC.typeof (headerTarget i)) = .By_value CC.Mptr) ∧
    (96 : Int) ≤ CC.sizeof ge.genv_cenv headerType := by
  refine ⟨by decide +kernel, by decide +kernel, ?_, ?_, by decide +kernel⟩
  · intro i
    rcases twelve_cases i with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl <;> rfl
  · intro i
    rcases twelve_cases i with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl <;> rfl

theorem header_offsets : ∀ i : Fin 12,
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr (8 * (i.val : Int))) = (8 * (i.val : Int)) := by
  decide +kernel

structure HeaderLocal (m : CC.Mem) where
  block : CC.Block
  binding : (allocation m).1.get Arm64Entry._entry = some (block, headerType)
  fresh : m.nextblock.toNat ≤ block.toNat
  owned : block.toNat < (allocation m).2.nextblock.toNat
  range : CC.Mem.rangePerm (allocation m).2 block 0
    (CC.sizeof ge.genv_cenv headerType) .Cur .Writable = true

structure HeaderSourceLocal (m : CC.Mem) (i : Fin 12) where
  block : CC.Block
  binding : (allocation m).1.get (headerSourceName i) = some (block, headerSourceType i)
  owned : block.toNat < (allocation m).2.nextblock.toNat

theorem header_local (m : CC.Mem) : Nonempty (HeaderLocal m) := by
  obtain ⟨block, binding, fresh, owned, range⟩ :=
    local_storage m Arm64Entry._entry headerType (by decide +kernel)
  exact ⟨⟨block, binding, fresh, owned, CC.Mem.rangePerm_implies range
    (by decide : CC.permOrder .Freeable .Writable = true)⟩⟩

theorem header_source_local (m : CC.Mem) (i : Fin 12) : Nonempty (HeaderSourceLocal m i) := by
  have present : ∀ i, (headerSourceName i, headerSourceType i) ∈ producer.fn_vars := by decide +kernel
  obtain ⟨block, binding, _, owned, _⟩ :=
    local_storage m (headerSourceName i) (headerSourceType i) (present i)
  exact ⟨⟨block, binding, owned⟩⟩

private theorem header_lvalue (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (m before : CC.Mem) (le : CC.TempEnv) (i : Fin 12)
    (entry : HeaderLocal m) :
    CC.doEvalLvalue world (allocation m).1 le before (headerTarget i) =
      some (entry.block, CC.Integers.Ptrofs.repr (8 * (i.val : Int)), .Full) := by
  simp [headerTarget, headerType, CC.doEvalLvalue, CC.lvalOfVar, CC.doEvalExpr,
    CC.doDerefLoc, CC.accessMode, CC.lvalOfField, CC.typeof, entry.binding,
    layout, header_layout.1, header_layout.2.1, CC.Integers.Ptrofs.add,
    CC.Integers.Ptrofs.zero, CC.Integers.MI.zero, CC.Integers.MI.add]
  all_goals
    apply congrArg (fun ofs => (ofs, CC.Bitfield.Full))
    exact BitVec.zero_add _

private theorem header_rhs (world : CC.CGenv) (m before : CC.Mem) (le : CC.TempEnv) (i : Fin 12)
    (cell : HeaderSourceLocal m i) :
    CC.doEvalExpr world (allocation m).1 le before (headerRhs i) = some (.Vptr cell.block 0) ∧
    CC.Cop.semCast (.Vptr cell.block 0) (CC.typeof (headerRhs i))
      (CC.typeof (headerTarget i)) before = some (.Vptr cell.block 0) := by
  constructor
  · by_cases first : i.val < 2
    · have cases2 : i = 0 ∨ i = 1 := by
        have values : i.val = 0 ∨ i.val = 1 := by omega
        rcases values with zero | one
        · exact .inl (Fin.ext zero)
        · exact .inr (Fin.ext one)
      rcases cases2 with rfl | rfl
      all_goals simp [headerRhs, headerSourceType, CC.tarray, CC.doEvalExpr, CC.lvalOfVar,
        CC.doDerefLoc, CC.accessMode, cell.binding, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero]
    · simp [headerRhs, first, CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar,
        cell.binding, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero]
  · simp [CC.Cop.semCast, header_layout.2.2.1]

private theorem header_write (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (i : Fin 12) (entry : HeaderLocal m) (cell : HeaderSourceLocal m i) (rest : CC.Stmt)
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world 3
        (.State producer (.Ssequence (headerAssignment i) rest) k (allocation m).1 le before)
        (.State producer rest k (allocation m).1 le after) ∧
      CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) = some (.Vptr cell.block 0) ∧
      (∀ j : Fin 12, j ≠ i → CC.Mem.load CC.Mptr after entry.block (8 * (j.val : Int)) =
        CC.Mem.load CC.Mptr before entry.block (8 * (j.val : Int))) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry._entry →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  have writable : CC.Mem.validAccess before CC.Mptr entry.block (8 * (i.val : Int)) .Writable = true := by
    simp only [CC.Mem.validAccess, Bool.and_eq_true]
    refine ⟨?_, ?_⟩
    · apply CC.Mem.rangePerm_intro
      intro ofs lower upper
      have bound := i.isLt
      have size := header_layout.2.2.2.2
      have lo : (0 : Int) ≤ ofs := by omega
      have hi : ofs < CC.sizeof ge.genv_cenv headerType := by
        change ofs < (8 * (i.val : Int)) + 8 at upper
        omega
      have perm := CC.Mem.rangePerm_perm (allocation m).2 entry.block 0
        (CC.sizeof ge.genv_cenv headerType) .Cur .Writable entry.range ofs lo hi
      simpa only [CC.Mem.perm, access] using perm
    · change ((8 * (i.val : Int)) % 8 == 0) = true
      simp
  have existsStore : ∃ after, CC.Mem.store CC.Mptr before entry.block (8 * (i.val : Int))
      (.Vptr cell.block 0) = some after := by
    unfold CC.Mem.store
    rw [writable]
    exact ⟨_, rfl⟩
  obtain ⟨after, stored⟩ := existsStore
  have storev : CC.Mem.storev CC.Mptr before
      (.Vptr entry.block (CC.Integers.Ptrofs.repr (8 * (i.val : Int)))) (.Vptr cell.block 0) = some after := by
    simpa only [CC.Mem.storev, header_offsets] using stored
  have target := header_lvalue world layout m before le i entry
  have rhs := header_rhs world m before le i cell
  have assigned : CC.doStep world
      (.State producer (headerAssignment i) (.Kseq rest k) (allocation m).1 le before) =
      some (CC.E0, .State producer .Sskip (.Kseq rest k) (allocation m).1 le after) := by
    simp only [headerAssignment, CC.doStep, target, rhs.1, rhs.2, CC.doAssignLoc, header_layout.2.2.2.1]
    change (match CC.Mem.storev CC.Mptr before
      (.Vptr entry.block (CC.Integers.Ptrofs.repr (8 * (i.val : Int)))) (.Vptr cell.block 0) with
      | some memory => some (CC.E0, CC.State.State producer .Sskip (.Kseq rest k) (allocation m).1 le memory)
      | none => none) = _
    rw [storev]
  have run : InternalRun world 3
      (.State producer (.Ssequence (headerAssignment i) rest) k (allocation m).1 le before)
      (.State producer rest k (allocation m).1 le after) :=
    .step trivial (CC.doStep_sound world _ _ _ rfl)
      (.step trivial (CC.doStep_sound world _ _ _ assigned)
        (.step trivial (CC.doStep_sound world _ _ _ rfl) (.refl _)))
  refine ⟨after, run, ?_, ?_, ?_, FrameBelow.store entry.fresh stored,
    CC.Mem.store_access stored, CC.Mem.store_nextblock stored⟩
  · simpa [CC.Val.loadResult, CC.Mptr, CC.Archi.ptr64] using CC.Mem.load_store_same stored
  · intro j different
    have ne : j.val ≠ i.val := fun h => different (Fin.ext h)
    have separate : (8 * j.val : Int) + 8 ≤ (8 * i.val : Int) ∨
        (8 * i.val : Int) + 8 ≤ (8 * j.val : Int) := by omega
    exact CC.Mem.load_store_other stored CC.Mptr entry.block (8 * (j.val : Int)) (.inr separate)
  · intro id ty block bound different chunk ofs
    have distinct := (allocated_local_storage
      (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm)).2
    exact CC.Mem.load_store_other stored chunk block ofs
      (.inl (distinct _ _ _ _ bound entry.binding different))

private theorem run_header (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (m : CC.Mem) (entry : HeaderLocal m)
    (cells : (i : Fin 12) → HeaderSourceLocal m i) (rows : List (Fin 12)) (rest : CC.Stmt)
    (le : CC.TempEnv) (k : CC.Cont) (before : CC.Mem)
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world (3 * rows.length)
        (.State producer (rows.foldr (fun i next => .Ssequence (headerAssignment i) next) rest)
          k (allocation m).1 le before)
        (.State producer rest k (allocation m).1 le after) ∧
      (∀ i ∈ rows, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) = some (.Vptr (cells i).block 0)) ∧
      (∀ i ∉ rows, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) =
        CC.Mem.load CC.Mptr before entry.block (8 * (i.val : Int))) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry._entry →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  induction rows generalizing before with
  | nil =>
    refine ⟨before, .refl _, ?_, ?_, ?_, FrameBelow.refl _ _, rfl, rfl⟩
    · intro i member; cases member
    · intro i absent; rfl
    · intro id ty block bound different chunk ofs; rfl
  | cons head tail ih =>
    obtain ⟨middle, headRun, headRead, headOther, headLocals, headFrame, headAccess, headNext⟩ :=
      header_write world layout m before le k head entry (cells head)
        (tail.foldr (fun i next => .Ssequence (headerAssignment i) next) rest) access
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

/-- All twelve actual scalar header pointers are constructed from the real
allocated locals in thirty-six internal transitions. The vector-pointer arrays
and final borrowed continuation remain in the actual successor stage. -/
theorem header_initialized_bound (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ entry : HeaderLocal m, ∃ cells : (i : Fin 12) → HeaderSourceLocal m i, ∃ after,
      InternalRun world 36 (.State producer afterContext k (allocation m).1 le before)
        (.State producer afterHeaderPointers k (allocation m).1 le after) ∧
      (∀ i, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) = some (.Vptr (cells i).block 0)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry._entry →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  classical
  obtain ⟨entry⟩ := header_local m
  let cells : (i : Fin 12) → HeaderSourceLocal m i := fun i => Classical.choice (header_source_local m i)
  obtain ⟨after, run, read, _, other, frame, finalAccess, next⟩ :=
    run_header world layout m entry cells (List.finRange 12) afterHeaderPointers le k before access
  refine ⟨entry, cells, after, ?_, (fun i => read i (List.mem_finRange i)), other, frame, finalAccess, next⟩
  have mapped : List.ofFn headerAssignment = (List.finRange 12).map headerAssignment := by
    simp only [List.finRange, List.map_ofFn, Function.comp_def]
  rw [header_source]
  simpa only [List.length_finRange, mapped, List.foldr_map] using run

theorem header_initialized (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ entry : HeaderLocal m, ∃ cells : (i : Fin 12) → HeaderSourceLocal m i, ∃ after,
      InternalRun ge 36 (.State producer afterContext k (allocation m).1 le before)
        (.State producer afterHeaderPointers k (allocation m).1 le after) ∧
      (∀ i, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) = some (.Vptr (cells i).block 0)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry._entry →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock :=
  header_initialized_bound ge rfl m before le k access

private def borrowedHeader : CC.Composite :=
  (Arm64EntryMemory.composites.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)

private theorem borrowed_cache_layout :
    Arm64EntryMemory.composites.get Arm64Program._kprog_arm64_entry = some borrowedHeader ∧
    (∀ returns : Bool,
      CC.fieldOffset Arm64EntryMemory.composites
        (if returns then Arm64Program._return_valid else Arm64Program._sp_valid)
        borrowedHeader.co_members = .OK ((if returns then 56 else 48), .Full) ∧
      CC.fieldOffset Arm64EntryMemory.composites
        (if returns then Arm64Program._return_base else Arm64Program._sp_base)
        borrowedHeader.co_members = .OK ((if returns then 24 else 16), .Full)) := by
  decide +kernel

private theorem borrowed_header_read (frontier block : CC.Block) (after : CC.Mem)
    (name : CC.Ident) (delta : Int) (value : CC.Val)
    (layout : CC.fieldOffset Arm64EntryMemory.composites name borrowedHeader.co_members = .OK (delta, .Full))
    (norm : CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr delta) = delta)
    (owned : block.toNat < frontier.toNat)
    (read : CC.Mem.load CC.Mptr after block delta = some value) :
    Arm64EntryMemory.field frontier CC.Mptr after (.Vptr block 0) name = some value := by
  simp only [Arm64EntryMemory.field, Arm64EntryMemory.fieldAddress, borrowed_cache_layout.1]
  change ((match CC.fieldOffset Arm64EntryMemory.composites name borrowedHeader.co_members with
    | .OK (offset, .Full) => some (CC.Val.offsetPtr (.Vptr block 0) (CC.Integers.Ptrofs.repr offset))
    | _ => none).bind (fun address => Arm64EntryMemory.load frontier CC.Mptr after address)) = some value
  rw [layout]
  change Arm64EntryMemory.load frontier CC.Mptr after
    (.Vptr block (CC.Integers.Ptrofs.add 0 (CC.Integers.Ptrofs.repr delta))) = some value
  have shifted : CC.Integers.Ptrofs.add 0 (CC.Integers.Ptrofs.repr delta) = CC.Integers.Ptrofs.repr delta := by
    exact BitVec.zero_add _
  simp only [Arm64EntryMemory.load, if_pos owned, shifted, norm]
  exact read

/-- Construct the existing borrowed-cache contract from the actual header
readbacks and allocated cache locals, without postulating header pointers. -/
theorem header_cache_storage (returns : Bool) (m after : CC.Mem) (entry : HeaderLocal m)
    (cells : (i : Fin 12) → HeaderSourceLocal m i)
    (access : after.access = (allocation m).2.access)
    (reads : ∀ i, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) = some (.Vptr (cells i).block 0)) :
    ∃ cache : CacheLocals returns m,
      Nonempty (Arm64RegisterReads.BorrowedCacheStorage returns (allocation m).2.nextblock cache.entryBlock 0 after) := by
  obtain ⟨cache⟩ := cache_locals returns m
  let bi : Fin 12 := if returns then 3 else 2
  let vi : Fin 12 := if returns then 7 else 6
  have entryEq : entry.block = cache.entryBlock := by
    exact congrArg Prod.fst (Option.some.inj (entry.binding.symm.trans cache.entryBinding))
  have baseBind : (allocation m).1.get (headerSourceName bi) =
      some (cache.baseBlock, headerSourceType bi) := by
    cases returns <;> exact cache.baseBinding
  have validBind : (allocation m).1.get (headerSourceName vi) =
      some (cache.validBlock, headerSourceType vi) := by
    cases returns <;> exact cache.validBinding
  have baseEq : (cells bi).block = cache.baseBlock :=
    congrArg Prod.fst (Option.some.inj ((cells bi).binding.symm.trans baseBind))
  have validEq : (cells vi).block = cache.validBlock :=
    congrArg Prod.fst (Option.some.inj ((cells vi).binding.symm.trans validBind))
  have entryOwned : cache.entryBlock.toNat < (allocation m).2.nextblock.toNat := entryEq ▸ entry.owned
  have baseOwned : cache.baseBlock.toNat < (allocation m).2.nextblock.toNat := baseEq ▸ (cells bi).owned
  have validOwned : cache.validBlock.toNat < (allocation m).2.nextblock.toNat := validEq ▸ (cells vi).owned
  have baseRead := reads bi
  have validRead := reads vi
  rw [entryEq, baseEq] at baseRead
  rw [entryEq, validEq] at validRead
  have baseCell : CC.Mem.load CC.Mptr after cache.entryBlock (if returns then 24 else 16) =
      some (.Vptr cache.baseBlock 0) := by cases returns <;> exact baseRead
  have validCell : CC.Mem.load CC.Mptr after cache.entryBlock (if returns then 56 else 48) =
      some (.Vptr cache.validBlock 0) := by cases returns <;> exact validRead
  have baseNorm : CC.Integers.Ptrofs.unsigned
      (CC.Integers.Ptrofs.repr (if returns then 24 else 16)) = (if returns then 24 else 16) := by
    cases returns <;> decide +kernel
  have validNorm : CC.Integers.Ptrofs.unsigned
      (CC.Integers.Ptrofs.repr (if returns then 56 else 48)) = (if returns then 56 else 48) := by
    cases returns <;> decide +kernel
  have baseHeader := borrowed_header_read (allocation m).2.nextblock cache.entryBlock after _ _ _
    (borrowed_cache_layout.2 returns).2 baseNorm entryOwned baseCell
  have validHeader := borrowed_header_read (allocation m).2.nextblock cache.entryBlock after _ _ _
    (borrowed_cache_layout.2 returns).1 validNorm entryOwned validCell
  have perm : ∀ chunk block, CC.Mem.validAccess after chunk block 0 .Writable =
      CC.Mem.validAccess (allocation m).2 chunk block 0 .Writable := by
    intro chunk block
    exact CC.Mem.validAccess_congr (fun ofs => by simp only [CC.Mem.perm, access])
  exact ⟨cache, ⟨⟨cache.validBlock, cache.baseBlock, 0, 0, validHeader, baseHeader,
    validOwned, baseOwned, cache.entryValid, cache.entryBase, .inl cache.separate,
    (perm .Mint64 cache.baseBlock).trans cache.baseWritable,
    (perm .Mint8unsigned cache.validBlock).trans cache.validWritable⟩⟩⟩

/-- Both actual producer caches satisfy the existing consumer storage contract
at this reached stage. The later vector setup and consumer call still follow. -/
theorem header_initializes_caches_bound (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ stack : CacheLocals false m, ∃ returns : CacheLocals true m, ∃ after,
      InternalRun world 36 (.State producer afterContext k (allocation m).1 le before)
        (.State producer afterHeaderPointers k (allocation m).1 le after) ∧
      Nonempty (Arm64RegisterReads.BorrowedCacheStorage false (allocation m).2.nextblock stack.entryBlock 0 after) ∧
      Nonempty (Arm64RegisterReads.BorrowedCacheStorage true (allocation m).2.nextblock returns.entryBlock 0 after) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨entry, cells, after, run, reads, _, frame, afterAccess, next⟩ :=
    header_initialized_bound world layout m before le k access
  obtain ⟨stack, stackStorage⟩ := header_cache_storage false m after entry cells (afterAccess.trans access) reads
  obtain ⟨returns, returnStorage⟩ := header_cache_storage true m after entry cells (afterAccess.trans access) reads
  exact ⟨stack, returns, after, run, stackStorage, returnStorage, frame, afterAccess, next⟩

theorem header_initializes_caches (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ stack : CacheLocals false m, ∃ returns : CacheLocals true m, ∃ after,
      InternalRun ge 36 (.State producer afterContext k (allocation m).1 le before)
        (.State producer afterHeaderPointers k (allocation m).1 le after) ∧
      Nonempty (Arm64RegisterReads.BorrowedCacheStorage false (allocation m).2.nextblock stack.entryBlock 0 after) ∧
      Nonempty (Arm64RegisterReads.BorrowedCacheStorage true (allocation m).2.nextblock returns.entryBlock 0 after) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock :=
  header_initializes_caches_bound ge rfl m before le k access

end KProgFormal.ClightRefinement.Arm64Producer
