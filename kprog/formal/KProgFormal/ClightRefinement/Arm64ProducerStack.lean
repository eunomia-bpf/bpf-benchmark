import KProgFormal.ClightRefinement.Arm64ProducerVectors

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Producer

def stackTagType : CC.Ty := CC.tarray CC.tuchar 24

def stackTagAssignment (i : Fin 24) : CC.Stmt :=
  .Sassign (.Ederef (.Ebinop .Oadd (.Evar Arm64Entry.___a64_stack_tag stackTagType)
    (.Econst_int (CC.Integers.Int.repr i.val) CC.tint) (CC.tptr CC.tuchar)) CC.tuchar)
    (.Econst_int (0#32) CC.tint)

private def stackTagParts : List CC.Stmt × CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(afterVectorInputs)) none
    let mut rows : Array Lean.Expr := #[]
    for _ in [:24] do
      body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "producer stack-tag initializer sequence changed"
      rows := rows.push body.getAppArgs[0]!
      body := body.getAppArgs[1]!
    let front ← Lean.Meta.mkListLit (Lean.mkConst ``CC.Stmt) rows.toList
    Lean.Elab.Tactic.closeMainGoal `actual_stack_tags (← Lean.Meta.mkAppM ``Prod.mk #[front, body])

def afterStackTags : CC.Stmt := stackTagParts.2

theorem stack_tags_source : afterVectorInputs =
    (List.ofFn stackTagAssignment).foldr CC.Stmt.Ssequence afterStackTags := by
  have rows : stackTagParts.1 = List.ofFn stackTagAssignment := rfl
  have source : afterVectorInputs = stackTagParts.1.foldr CC.Stmt.Ssequence afterStackTags := rfl
  rw [rows] at source
  exact source

def stackTagOffset (i : Fin 24) : CC.Integers.Ptrofs :=
  CC.Integers.Ptrofs.add CC.Integers.Ptrofs.zero
    (CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr 1)
      (CC.Integers.Ptrofs.of_ints (CC.Integers.Int.repr i.val)))

theorem stack_tag_offsets : ∀ i : Fin 24,
    CC.Integers.Ptrofs.unsigned (stackTagOffset i) = (i.val : Int) := by decide +kernel

structure StackTagLocal (m : CC.Mem) where
  block : CC.Block
  binding : (allocation m).1.get Arm64Entry.___a64_stack_tag = some (block, stackTagType)
  fresh : m.nextblock.toNat ≤ block.toNat
  range : CC.Mem.rangePerm (allocation m).2 block 0 24 .Cur .Writable = true

theorem stack_tag_local (m : CC.Mem) : Nonempty (StackTagLocal m) := by
  obtain ⟨block, binding, fresh, _, range⟩ :=
    local_storage m Arm64Entry.___a64_stack_tag stackTagType (by decide +kernel)
  change CC.Mem.rangePerm (allocation m).2 block 0 24 .Cur .Freeable = true at range
  exact ⟨⟨block, binding, fresh, CC.Mem.rangePerm_implies range
    (by decide : CC.permOrder .Freeable .Writable = true)⟩⟩

private theorem stack_tag_write (world : CC.CGenv) (f : CC.Function) (e : CC.Env) (m before : CC.Mem) (tags : StackTagLocal m)
    (i : Fin 24) (le : CC.TempEnv) (k : CC.Cont) (rest : CC.Stmt)
    (actualBinding : e.get Arm64Entry.___a64_stack_tag = some (tags.block, stackTagType))
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world 3
        (.State f (.Ssequence (stackTagAssignment i) rest) k e le before)
        (.State f rest k e le after) ∧
      CC.Mem.load .Mint8unsigned after tags.block (i.val : Int) = some (.Vint 0) ∧
      (∀ j : Fin 24, j ≠ i → CC.Mem.load .Mint8unsigned after tags.block (j.val : Int) =
        CC.Mem.load .Mint8unsigned before tags.block (j.val : Int)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry.___a64_stack_tag →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  have writable : CC.Mem.validAccess before .Mint8unsigned tags.block (i.val : Int) .Writable = true := by
    simp only [CC.Mem.validAccess, Bool.and_eq_true]
    refine ⟨?_, ?_⟩
    · apply CC.Mem.rangePerm_intro
      intro ofs lower upper
      have bound := i.isLt
      have lo : (0 : Int) ≤ ofs := by omega
      have hi : ofs < (24 : Int) := by change ofs < (i.val : Int) + 1 at upper; omega
      have perm := CC.Mem.rangePerm_perm (allocation m).2 tags.block 0 24 .Cur .Writable tags.range ofs lo hi
      simpa only [CC.Mem.perm, access] using perm
    · change ((i.val : Int) % 1 == 0) = true
      simp only [Int.emod_one, beq_self_eq_true]
  have existsStore : ∃ after, CC.Mem.store .Mint8unsigned before tags.block (i.val : Int)
      (.Vint (0#32)) = some after := by
    unfold CC.Mem.store
    rw [writable]
    exact ⟨_, rfl⟩
  obtain ⟨after, stored⟩ := existsStore
  have storev : CC.Mem.storev .Mint8unsigned before (.Vptr tags.block (stackTagOffset i))
      (.Vint (0#32)) = some after := by
    simpa only [CC.Mem.storev, stack_tag_offsets] using stored
  have exec : steps world 3
      (.State f (.Ssequence (stackTagAssignment i) rest) k e le before) =
      some (CC.E0, .State f rest k e le after) ∧
      InternalPath world 3
        (.State f (.Ssequence (stackTagAssignment i) rest) k e le before) := by
    simp +decide [steps, InternalPath, InternalState, stackTagAssignment, stackTagType,
      CC.doStep, CC.doEvalLvalue, CC.doEvalExpr, CC.lvalOfVar, CC.doDerefLoc,
      CC.doAssignLoc, CC.accessMode, CC.typeof, CC.Cop.semBinaryOperation,
      CC.Cop.semAdd, CC.Cop.classifyAdd, CC.Cop.semAddPtrInt, CC.Cop.ptrofsOfInt,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.typeconv,
      CC.removeAttributes, CC.tattr, CC.sizeof, CC.tarray, CC.tptr, CC.tint, CC.tuchar,
      CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Integers.Int.zero_ext,
      CC.Integers.MI.zero_ext, stackTagOffset, actualBinding, CC.E0, CC.Eapp] at storev ⊢
    simp [storev, CC.doStep, CC.E0, CC.Eapp, InternalState, InternalPath, steps]
  refine ⟨after, internalRun_of_steps exec.2 exec.1, ?_, ?_, ?_,
    FrameBelow.store tags.fresh stored, CC.Mem.store_access stored, CC.Mem.store_nextblock stored⟩
  · simpa [CC.Val.loadResult, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext] using
      CC.Mem.load_store_same stored
  · intro j different
    have ne : j.val ≠ i.val := fun h => different (Fin.ext h)
    have separate : (j.val : Int) + 1 ≤ (i.val : Int) ∨ (i.val : Int) + 1 ≤ (j.val : Int) := by omega
    apply CC.Mem.load_store_other stored
    exact Or.inr separate
  · intro id ty block bound different chunk ofs
    have distinct := (allocated_local_storage
      (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm)).2
    exact CC.Mem.load_store_other stored chunk block ofs
      (.inl (distinct _ _ _ _ bound tags.binding different))

private theorem run_stack_tags (world : CC.CGenv) (f : CC.Function) (e : CC.Env) (m : CC.Mem) (tags : StackTagLocal m) (rows : List (Fin 24))
    (rest : CC.Stmt) (le : CC.TempEnv) (k : CC.Cont) (before : CC.Mem)
    (actualBinding : e.get Arm64Entry.___a64_stack_tag = some (tags.block, stackTagType))
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world (3 * rows.length)
        (.State f (rows.foldr (fun i next => .Ssequence (stackTagAssignment i) next) rest)
          k e le before)
        (.State f rest k e le after) ∧
      (∀ i ∈ rows, CC.Mem.load .Mint8unsigned after tags.block (i.val : Int) = some (.Vint 0)) ∧
      (∀ i ∉ rows, CC.Mem.load .Mint8unsigned after tags.block (i.val : Int) =
        CC.Mem.load .Mint8unsigned before tags.block (i.val : Int)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry.___a64_stack_tag →
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
      stack_tag_write world f e m before tags head le k
        (tail.foldr (fun i next => .Ssequence (stackTagAssignment i) next) rest) actualBinding access
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

/-- All actual stack-tag byte initializers execute and read back zero. -/
theorem stack_tags_initialized_body (world : CC.CGenv) (f : CC.Function) (e : CC.Env) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (rest : CC.Stmt) (tags : StackTagLocal m)
    (actualBinding : e.get Arm64Entry.___a64_stack_tag = some (tags.block, stackTagType))
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world 72
        (.State f ((List.ofFn stackTagAssignment).foldr CC.Stmt.Ssequence rest) k e le before)
        (.State f rest k e le after) ∧
      (∀ i : Fin 24, CC.Mem.load .Mint8unsigned after tags.block (i.val : Int) = some (.Vint 0)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry.___a64_stack_tag →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨after, run, read, _, other, frame, finalAccess, next⟩ :=
    run_stack_tags world f e m tags (List.finRange 24) rest le k before actualBinding access
  refine ⟨after, ?_, (fun i => read i (List.mem_finRange i)), other, frame, finalAccess, next⟩
  have mapped : List.ofFn stackTagAssignment = (List.finRange 24).map stackTagAssignment := by
    simp only [List.finRange, List.map_ofFn, Function.comp_def]
  simpa only [List.length_finRange, mapped, List.foldr_map] using run

theorem stack_tags_initialized_bound (world : CC.CGenv) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ tags : StackTagLocal m, ∃ after, InternalRun world 72
        (.State producer afterVectorInputs k (allocation m).1 le before)
        (.State producer afterStackTags k (allocation m).1 le after) ∧
      (∀ i : Fin 24, CC.Mem.load .Mint8unsigned after tags.block (i.val : Int) = some (.Vint 0)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry.___a64_stack_tag →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨tags⟩ := stack_tag_local m
  obtain ⟨after, run, reads, other, frame, finalAccess, next⟩ :=
    stack_tags_initialized_body world producer (allocation m).1 m before le k afterStackTags tags tags.binding access
  rw [stack_tags_source]
  exact ⟨tags, after, run, reads, other, frame, finalAccess, next⟩

def afterSpZero : CC.Stmt := by
  run_tac do
    let body ← Lean.Elab.Term.elabTerm (← `(afterStackTags)) none
    let exposed ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
    unless exposed.isAppOfArity ``CC.Stmt.Ssequence 2 do
      throwError "producer SP declaration no longer follows stack tags"
    Lean.Elab.Tactic.closeMainGoal `actual_after_sp exposed.getAppArgs[1]!

theorem sp_zero_source : afterStackTags =
    .Ssequence (.Sassign (.Evar Arm64Entry.___a64_sp CC.tlong)
      (.Econst_int (0#32) CC.tint)) afterSpZero := by rfl

theorem sp_initialized_body (world : CC.CGenv) (f : CC.Function) (e : CC.Env) (rest : CC.Stmt) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (actualBinding : ∀ block, (allocation m).1.get Arm64Entry.___a64_sp = some (block, CC.tlong) →
      e.get Arm64Entry.___a64_sp = some (block, CC.tlong))
    (access : before.access = (allocation m).2.access) :
    ∃ block after, (allocation m).1.get Arm64Entry.___a64_sp = some (block, CC.tlong) ∧
      InternalRun world 3 (.State f (.Ssequence (.Sassign (.Evar Arm64Entry.___a64_sp CC.tlong) (.Econst_int (0#32) CC.tint)) rest) k e le before)
        (.State f rest k e le after) ∧
      CC.Mem.loadv .Mint64 after (.Vptr block 0) = some (.Vlong 0) ∧
      (∀ id ty other, (allocation m).1.get id = some (other, ty) → id ≠ Arm64Entry.___a64_sp →
        ∀ chunk ofs, CC.Mem.load chunk after other ofs = CC.Mem.load chunk before other ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨block, binding, fresh, writable⟩ := scalar_local m Arm64Entry.___a64_sp CC.tlong .Mint64
    (by decide +kernel) rfl (by decide)
  obtain ⟨after, stored, afterAccess⟩ := create_store m before .Mint64 block (.Vlong (0#64)) access writable
  have exec : steps world 3 (.State f (.Ssequence (.Sassign (.Evar Arm64Entry.___a64_sp CC.tlong) (.Econst_int (0#32) CC.tint)) rest) k e le before) =
      some (CC.E0, .State f rest k e le after) ∧
      InternalPath world 3 (.State f (.Ssequence (.Sassign (.Evar Arm64Entry.___a64_sp CC.tlong) (.Econst_int (0#32) CC.tint)) rest) k e le before) := by
    change CC.Mem.storev .Mint64 before (.Vptr block (0#64)) (.Vlong (0#64)) = some after at stored
    simp +decide [steps, InternalPath, InternalState, CC.doStep, CC.doEvalLvalue, CC.doEvalExpr,
      CC.lvalOfVar, CC.doAssignLoc, CC.accessMode, CC.typeof, CC.Cop.semCast, CC.Cop.classifyCast,
      CC.Cop.castIntLong, CC.Integers.Int.signed, CC.Integers.MI.signed,
      CC.Integers.Int64.repr, CC.Integers.Int.repr, CC.Integers.MI.repr,
      CC.Integers.Ptrofs.zero, CC.Integers.MI.zero, CC.tlong, CC.tint,
      CC.Archi.ptr64, CC.E0, CC.Eapp, actualBinding block binding, stored]
  refine ⟨block, after, binding, internalRun_of_steps exec.2 exec.1,
    CC.Mem.load_store_same stored, ?_, FrameBelow.store fresh stored,
    afterAccess.trans access.symm, CC.Mem.store_nextblock stored⟩
  intro id ty other bound different chunk ofs
  have distinct := (allocated_local_storage
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm)).2
  exact CC.Mem.load_store_other stored chunk other ofs
    (.inl (distinct _ _ _ _ bound binding different))

theorem sp_initialized_bound (world : CC.CGenv) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ block after, (allocation m).1.get Arm64Entry.___a64_sp = some (block, CC.tlong) ∧
      InternalRun world 3 (.State producer afterStackTags k (allocation m).1 le before)
        (.State producer afterSpZero k (allocation m).1 le after) ∧
      CC.Mem.loadv .Mint64 after (.Vptr block 0) = some (.Vlong 0) ∧
      (∀ id ty other, (allocation m).1.get id = some (other, ty) → id ≠ Arm64Entry.___a64_sp →
        ∀ chunk ofs, CC.Mem.load chunk after other ofs = CC.Mem.load chunk before other ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  rw [sp_zero_source]
  exact sp_initialized_body world producer (allocation m).1 afterSpZero m before le k
    (fun _ bound => bound) access

/-- The actual 24 tag clears and SP zero assignment complete without a
provider call, with exact byte/SP readback and other-local framing. -/
theorem stack_tags_and_sp_bound (world : CC.CGenv) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ tags : StackTagLocal m, ∃ spBlock after,
      (allocation m).1.get Arm64Entry.___a64_sp = some (spBlock, CC.tlong) ∧
      InternalRun world 75 (.State producer afterVectorInputs k (allocation m).1 le before)
        (.State producer afterSpZero k (allocation m).1 le after) ∧
      (∀ i : Fin 24, CC.Mem.load .Mint8unsigned after tags.block (i.val : Int) = some (.Vint 0)) ∧
      CC.Mem.loadv .Mint64 after (.Vptr spBlock 0) = some (.Vlong 0) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) →
        id ≠ Arm64Entry.___a64_stack_tag → id ≠ Arm64Entry.___a64_sp →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨tags, middle, tagRun, tagReads, tagOther, tagFrame, tagAccess, tagNext⟩ :=
    stack_tags_initialized_bound world m before le k access
  obtain ⟨spBlock, after, spBinding, spRun, spRead, spOther, spFrame, spAccess, spNext⟩ :=
    sp_initialized_bound world m middle le k (tagAccess.trans access)
  refine ⟨tags, spBlock, after, spBinding, tagRun.trans spRun, ?_, spRead, ?_,
    tagFrame.trans spFrame, spAccess.trans tagAccess, spNext.trans tagNext⟩
  · intro i
    exact (spOther _ _ _ tags.binding (by decide +kernel) .Mint8unsigned (i.val : Int)).trans (tagReads i)
  · intro id ty block bound notTags notSp chunk ofs
    exact (spOther id ty block bound notSp chunk ofs).trans (tagOther id ty block bound notTags chunk ofs)

theorem stack_tags_initialized (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ tags : StackTagLocal m, ∃ after, InternalRun ge 72
        (.State producer afterVectorInputs k (allocation m).1 le before)
        (.State producer afterStackTags k (allocation m).1 le after) ∧
      (∀ i : Fin 24, CC.Mem.load .Mint8unsigned after tags.block (i.val : Int) = some (.Vint 0)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry.___a64_stack_tag →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock :=
  stack_tags_initialized_bound ge m before le k access

theorem sp_initialized (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ block after, (allocation m).1.get Arm64Entry.___a64_sp = some (block, CC.tlong) ∧
      InternalRun ge 3 (.State producer afterStackTags k (allocation m).1 le before)
        (.State producer afterSpZero k (allocation m).1 le after) ∧
      CC.Mem.loadv .Mint64 after (.Vptr block 0) = some (.Vlong 0) ∧
      (∀ id ty other, (allocation m).1.get id = some (other, ty) → id ≠ Arm64Entry.___a64_sp →
        ∀ chunk ofs, CC.Mem.load chunk after other ofs = CC.Mem.load chunk before other ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock :=
  sp_initialized_bound ge m before le k access

theorem stack_tags_and_sp (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ tags : StackTagLocal m, ∃ spBlock after,
      (allocation m).1.get Arm64Entry.___a64_sp = some (spBlock, CC.tlong) ∧
      InternalRun ge 75 (.State producer afterVectorInputs k (allocation m).1 le before)
        (.State producer afterSpZero k (allocation m).1 le after) ∧
      (∀ i : Fin 24, CC.Mem.load .Mint8unsigned after tags.block (i.val : Int) = some (.Vint 0)) ∧
      CC.Mem.loadv .Mint64 after (.Vptr spBlock 0) = some (.Vlong 0) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) →
        id ≠ Arm64Entry.___a64_stack_tag → id ≠ Arm64Entry.___a64_sp →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock :=
  stack_tags_and_sp_bound ge m before le k access

end KProgFormal.ClightRefinement.Arm64Producer
