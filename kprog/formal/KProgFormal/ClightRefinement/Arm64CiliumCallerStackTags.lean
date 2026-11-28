import KProgFormal.ClightRefinement.Arm64CiliumCallerVectorEntry

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerStackTags
open Arm64CiliumCallerLink (procedure ge allocation)

def stackTagType : CC.Ty := CC.tarray CC.tuchar 8

noncomputable def stackTagAssignment (i : Fin 8) : CC.Stmt :=
  .Sassign (.Ederef (.Ebinop .Oadd (.Evar Arm64CiliumCallerUnit.___a64_stack_tag stackTagType)
    (.Econst_int (CC.Integers.Int.repr i.val) CC.tint) (CC.tptr CC.tuchar)) CC.tuchar)
    (.Econst_int (0#32) CC.tint)

private noncomputable def stackTagParts : List CC.Stmt × CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerVectorSource.after)) none
    let mut rows : Array Lean.Expr := #[]
    for _ in [:8] do
      body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "actual caller stack-tag initializer sequence changed"
      rows := rows.push body.getAppArgs[0]!
      body := body.getAppArgs[1]!
    let front ← Lean.Meta.mkListLit (Lean.mkConst ``CC.Stmt) rows.toList
    Lean.Elab.Tactic.closeMainGoal `actual_stack_tags (← Lean.Meta.mkAppM ``Prod.mk #[front, body])

noncomputable def afterStackTags : CC.Stmt := stackTagParts.2

theorem stack_tags_source : Arm64CiliumCallerVectorSource.after =
    (List.ofFn stackTagAssignment).foldr CC.Stmt.Ssequence afterStackTags := by
  have rows : stackTagParts.1 = List.ofFn stackTagAssignment := rfl
  have source : Arm64CiliumCallerVectorSource.after = stackTagParts.1.foldr CC.Stmt.Ssequence afterStackTags := rfl
  rw [rows] at source
  exact source

def stackTagOffset (i : Fin 8) : CC.Integers.Ptrofs :=
  CC.Integers.Ptrofs.add CC.Integers.Ptrofs.zero
    (CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr 1)
      (CC.Integers.Ptrofs.of_ints (CC.Integers.Int.repr i.val)))

theorem stack_tag_offsets : ∀ i : Fin 8,
    CC.Integers.Ptrofs.unsigned (stackTagOffset i) = (i.val : Int) := by decide +kernel

structure StackTagLocal (m : CC.Mem) where
  block : CC.Block
  binding : (allocation m).1.get Arm64CiliumCallerUnit.___a64_stack_tag = some (block, stackTagType)
  fresh : m.nextblock.toNat ≤ block.toNat
  range : CC.Mem.rangePerm (allocation m).2 block 0 8 .Cur .Writable = true

theorem stack_tag_local (m : CC.Mem) : Nonempty (StackTagLocal m) := by
  have noDuplicates : CC.listNorepet (CC.varNames procedure.fn_vars) := by
    cases Arm64CiliumCallerLink.entry_valid m .Vundef with
    | intro hn _ _ _ _ => exact hn
  have declared : (Arm64CiliumCallerUnit.___a64_stack_tag,stackTagType) ∈ procedure.fn_vars := by decide +kernel
  obtain ⟨block,binding⟩ := allocated_local_binding (Arm64CiliumCallerLink.allocated m) noDuplicates declared
  have owned := (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).1 _ _ binding
  have range : CC.Mem.rangePerm (allocation m).2 block 0 8 .Cur .Freeable = true := by
    exact owned.2.2
  exact ⟨⟨block,binding,owned.1,CC.Mem.rangePerm_implies range
    (by decide : CC.permOrder .Freeable .Writable = true)⟩⟩

private theorem stack_tag_write (world : CC.CGenv) (f : CC.Function) (e : CC.Env) (m before : CC.Mem) (tags : StackTagLocal m)
    (i : Fin 8) (le : CC.TempEnv) (k : CC.Cont) (rest : CC.Stmt)
    (actualBinding : e.get Arm64CiliumCallerUnit.___a64_stack_tag = some (tags.block, stackTagType))
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world 3
        (.State f (.Ssequence (stackTagAssignment i) rest) k e le before)
        (.State f rest k e le after) ∧
      CC.Mem.load .Mint8unsigned after tags.block (i.val : Int) = some (.Vint 0) ∧
      (∀ j : Fin 8, j ≠ i → CC.Mem.load .Mint8unsigned after tags.block (j.val : Int) =
        CC.Mem.load .Mint8unsigned before tags.block (j.val : Int)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64CiliumCallerUnit.___a64_stack_tag →
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
      have hi : ofs < (8 : Int) := by change ofs < (i.val : Int) + 1 at upper; omega
      have perm := CC.Mem.rangePerm_perm (allocation m).2 tags.block 0 8 .Cur .Writable tags.range ofs lo hi
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

private theorem run_stack_tags (world : CC.CGenv) (f : CC.Function) (e : CC.Env) (m : CC.Mem) (tags : StackTagLocal m) (rows : List (Fin 8))
    (rest : CC.Stmt) (le : CC.TempEnv) (k : CC.Cont) (before : CC.Mem)
    (actualBinding : e.get Arm64CiliumCallerUnit.___a64_stack_tag = some (tags.block, stackTagType))
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world (3 * rows.length)
        (.State f (rows.foldr (fun i next => .Ssequence (stackTagAssignment i) next) rest)
          k e le before)
        (.State f rest k e le after) ∧
      (∀ i ∈ rows, CC.Mem.load .Mint8unsigned after tags.block (i.val : Int) = some (.Vint 0)) ∧
      (∀ i ∉ rows, CC.Mem.load .Mint8unsigned after tags.block (i.val : Int) =
        CC.Mem.load .Mint8unsigned before tags.block (i.val : Int)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64CiliumCallerUnit.___a64_stack_tag →
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
    (actualBinding : e.get Arm64CiliumCallerUnit.___a64_stack_tag = some (tags.block, stackTagType))
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world 24
        (.State f ((List.ofFn stackTagAssignment).foldr CC.Stmt.Ssequence rest) k e le before)
        (.State f rest k e le after) ∧
      (∀ i : Fin 8, CC.Mem.load .Mint8unsigned after tags.block (i.val : Int) = some (.Vint 0)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64CiliumCallerUnit.___a64_stack_tag →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨after, run, read, _, other, frame, finalAccess, next⟩ :=
    run_stack_tags world f e m tags (List.finRange 8) rest le k before actualBinding access
  refine ⟨after, ?_, (fun i => read i (List.mem_finRange i)), other, frame, finalAccess, next⟩
  have mapped : List.ofFn stackTagAssignment = (List.finRange 8).map stackTagAssignment := by
    simp only [List.finRange, List.map_ofFn, Function.comp_def]
  simpa only [List.length_finRange, mapped, List.foldr_map] using run

theorem stack_tags_initialized_bound (world : CC.CGenv) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ tags : StackTagLocal m, ∃ after, InternalRun world 24
        (.State procedure Arm64CiliumCallerVectorSource.after k (allocation m).1 le before)
        (.State procedure afterStackTags k (allocation m).1 le after) ∧
      (∀ i : Fin 8, CC.Mem.load .Mint8unsigned after tags.block (i.val : Int) = some (.Vint 0)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64CiliumCallerUnit.___a64_stack_tag →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨tags⟩ := stack_tag_local m
  obtain ⟨after, run, reads, other, frame, finalAccess, next⟩ :=
    stack_tags_initialized_body world procedure (allocation m).1 m before le k afterStackTags tags tags.binding access
  rw [stack_tags_source]
  exact ⟨tags, after, run, reads, other, frame, finalAccess, next⟩

noncomputable def afterSpZero : CC.Stmt := by
  run_tac do
    let body ← Lean.Elab.Term.elabTerm (← `(afterStackTags)) none
    let exposed ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
    unless exposed.isAppOfArity ``CC.Stmt.Ssequence 2 do
      throwError "actual caller SP declaration no longer follows stack tags"
    Lean.Elab.Tactic.closeMainGoal `actual_after_sp exposed.getAppArgs[1]!

theorem sp_zero_source : afterStackTags =
    .Ssequence (.Sassign (.Evar Arm64CiliumCallerUnit.___a64_sp CC.tlong)
      (.Econst_int (0#32) CC.tint)) afterSpZero := rfl

end KProgFormal.ClightRefinement.Arm64CiliumCallerStackTags
