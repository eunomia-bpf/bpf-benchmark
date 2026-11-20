import KProgFormal.ClightRefinement.Arm64ProducerStack
import KProgFormal.ClightRefinement.Arm64Registers

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Producer

/-- The five actual context/ABI/register-tag stores before header construction. -/
def contextName (i : Fin 5) : CC.Ident :=
  [Arm64Entry.___a64_sim_helper_ctx, Arm64Entry.___a64_sim_helper_abi_base,
   Arm64Entry.___a64_x0, Arm64Entry.___a64_x30_tag, Arm64Entry.___a64_x0_tag][i]

def contextLocalType (i : Fin 5) : CC.Ty :=
  if i.val < 2 then CC.tptr CC.tvoid else
  if i.val = 2 then .Tunion Arm64Entry._arm64_sim_gpr CC.noattr else CC.tuchar

def contextTarget (i : Fin 5) : CC.Expr :=
  if i.val = 2 then .Efield (.Evar (contextName i) (contextLocalType i)) Arm64Entry._ptr (CC.tptr CC.tvoid)
  else .Evar (contextName i) (contextLocalType i)

def contextRhs (i : Fin 5) : CC.Expr :=
  if i.val < 3 then .Ecast (.Etempvar Arm64Entry._ctx (CC.tptr CC.tvoid)) (CC.tptr CC.tvoid)
  else .Econst_int (if i.val = 3 then 10 else 1) CC.tuint

/-- Parameter type and temporary of the real caller, retaining the void* cast. -/
def contextRhsFor (temporary : CC.Ident) (pointee : CC.Ty) (i : Fin 5) : CC.Expr :=
  if i.val < 3 then .Ecast (.Etempvar temporary (CC.tptr pointee)) (CC.tptr CC.tvoid)
  else .Econst_int (if i.val = 3 then 10 else 1) CC.tuint

def contextValue (ctx : CC.Val) (i : Fin 5) : CC.Val :=
  if i.val < 3 then ctx else .Vint (if i.val = 3 then 10 else 1)

def contextChunk (i : Fin 5) : CC.Chunk :=
  if i.val < 3 then CC.Mptr else .Mint8unsigned

def contextAssignment (i : Fin 5) : CC.Stmt := .Sassign (contextTarget i) (contextRhs i)

def contextAssignmentFor (temporary : CC.Ident) (pointee : CC.Ty) (i : Fin 5) : CC.Stmt :=
  .Sassign (contextTarget i) (contextRhsFor temporary pointee i)

private theorem five_cases : ∀ i : Fin 5, i = 0 ∨ i = 1 ∨ i = 2 ∨ i = 3 ∨ i = 4 := by
  decide +kernel

private def contextParts : List CC.Stmt × CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(afterSpZero)) none
    let mut rows : Array Lean.Expr := #[]
    for _ in [:5] do
      body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "producer context/tag initializer sequence changed"
      rows := rows.push body.getAppArgs[0]!
      body := body.getAppArgs[1]!
    let front ← Lean.Meta.mkListLit (Lean.mkConst ``CC.Stmt) rows.toList
    Lean.Elab.Tactic.closeMainGoal `actual_context_stores (← Lean.Meta.mkAppM ``Prod.mk #[front, body])

def afterContext : CC.Stmt := contextParts.2

theorem context_source : afterSpZero =
    (List.ofFn contextAssignment).foldr CC.Stmt.Ssequence afterContext := by
  have rows : contextParts.1 = List.ofFn contextAssignment := rfl
  have source : afterSpZero = contextParts.1.foldr CC.Stmt.Ssequence afterContext := rfl
  rw [rows] at source
  exact source

theorem context_names_distinct : Function.Injective contextName := by
  have distinct : ∀ i j : Fin 5, contextName i = contextName j → i = j := by decide +kernel
  exact distinct

theorem context_pointer_layout :
    ge.genv_cenv.get Arm64Entry._arm64_sim_gpr = some gprComposite ∧
    CC.unionFieldOffset ge.genv_cenv Arm64Entry._ptr gprComposite.co_members = .OK (0, .Full) := by
  decide +kernel

/-- Only the named union and its pointer-member offset are needed. -/
def ContextLayout (world : CC.CGenv) : Prop :=
  world.genv_cenv.get Arm64Entry._arm64_sim_gpr = some gprComposite ∧
  CC.unionFieldOffset world.genv_cenv Arm64Entry._ptr gprComposite.co_members = .OK (0, .Full)

/-- Reuse the defined architectural-value representation: undef and 32-bit
integer contexts cannot silently become a 64-bit ABI pointer. -/
theorem context_cast_body (pointee : CC.Ty) {addresses : Arm64Registers.PointerOrigins} {ctx : CC.Val} {word : BitVec 64}
    (represented : Arm64Registers.ValueRep addresses ctx word) (memory : CC.Mem) :
    CC.Cop.semCast ctx (CC.tptr pointee) (CC.tptr CC.tvoid) memory = some ctx ∧
      CC.Val.loadResult CC.Mptr ctx = ctx := by
  cases ctx <;> try contradiction
  all_goals simp [CC.Cop.semCast, CC.Cop.classifyCast, CC.Archi.ptr64,
    CC.tptr, CC.Val.loadResult, CC.Mptr]

theorem context_cast {addresses : Arm64Registers.PointerOrigins} {ctx : CC.Val} {word : BitVec 64}
    (represented : Arm64Registers.ValueRep addresses ctx word) (memory : CC.Mem) :
    CC.Cop.semCast ctx (CC.tptr CC.tvoid) (CC.tptr CC.tvoid) memory = some ctx ∧
      CC.Val.loadResult CC.Mptr ctx = ctx :=
  context_cast_body CC.tvoid represented memory

structure ContextLocal (m : CC.Mem) (i : Fin 5) where
  block : CC.Block
  binding : (allocation m).1.get (contextName i) = some (block, contextLocalType i)
  fresh : m.nextblock.toNat ≤ block.toNat
  writable : CC.Mem.validAccess (allocation m).2 (contextChunk i) block 0 .Writable = true

theorem context_local (m : CC.Mem) (i : Fin 5) : Nonempty (ContextLocal m i) := by
  have present : (contextName i, contextLocalType i) ∈ producer.fn_vars := by
    rcases five_cases i with rfl | rfl | rfl | rfl | rfl <;> decide +kernel
  have size : CC.sizeof ge.genv_cenv (contextLocalType i) = CC.sizeChunk (contextChunk i) := by
    rcases five_cases i with rfl | rfl | rfl | rfl | rfl <;> decide +kernel
  have align : (0 : Int) % CC.alignChunk (contextChunk i) = 0 := by
    rcases five_cases i with rfl | rfl | rfl | rfl | rfl <;> decide +kernel
  obtain ⟨block, binding, fresh, writable⟩ :=
    scalar_local m (contextName i) (contextLocalType i) (contextChunk i) present size align
  exact ⟨⟨block, binding, fresh, writable⟩⟩

theorem context_lvalue_body (world : CC.CGenv) (e : CC.Env)
    (layout : ContextLayout world) (m before : CC.Mem) (le : CC.TempEnv) (i : Fin 5)
    (cell : ContextLocal m i)
    (actualBinding : e.get (contextName i) = some (cell.block, contextLocalType i)) :
    CC.doEvalLvalue world e le before (contextTarget i) = some (cell.block, 0, .Full) := by
  rcases five_cases i with rfl | rfl | rfl | rfl | rfl
  all_goals simp +decide [contextTarget, contextLocalType, CC.doEvalLvalue, CC.lvalOfVar,
    CC.doEvalExpr, CC.doDerefLoc, CC.accessMode, CC.lvalOfField, CC.typeof,
    actualBinding, layout.1, layout.2,
    CC.Integers.Ptrofs.add, CC.Integers.Ptrofs.repr, CC.Integers.MI.add,
    CC.Integers.MI.repr, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero]

theorem context_rhs_body (world : CC.CGenv) (e : CC.Env) (temporary : CC.Ident) (pointee : CC.Ty) {addresses : Arm64Registers.PointerOrigins} {ctx : CC.Val} {word : BitVec 64}
    (represented : Arm64Registers.ValueRep addresses ctx word) (before : CC.Mem)
    (le : CC.TempEnv) (input : le.get temporary = some ctx) (i : Fin 5) :
    CC.doEvalExpr world e le before (contextRhsFor temporary pointee i) = some (contextValue ctx i) ∧
    CC.Cop.semCast (contextValue ctx i) (CC.typeof (contextRhsFor temporary pointee i))
      (CC.typeof (contextTarget i)) before = some (contextValue ctx i) ∧
    CC.Val.loadResult (contextChunk i) (contextValue ctx i) = contextValue ctx i := by
  have cast := context_cast_body pointee represented before
  have selfCast := context_cast represented before
  rcases five_cases i with rfl | rfl | rfl | rfl | rfl
  all_goals simp +decide [contextRhsFor, contextValue, contextTarget, contextLocalType, contextChunk,
    CC.doEvalExpr, input, CC.typeof, cast.1, selfCast.1, cast.2]
  all_goals simp [CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.tuint, CC.tuchar, CC.Val.loadResult, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext]

private theorem context_write (world : CC.CGenv) (f : CC.Function) (e : CC.Env) (temporary : CC.Ident) (pointee : CC.Ty)
    (layout : ContextLayout world) {addresses : Arm64Registers.PointerOrigins} {ctx : CC.Val} {word : BitVec 64}
    (represented : Arm64Registers.ValueRep addresses ctx word) (m before : CC.Mem)
    (le : CC.TempEnv) (input : le.get temporary = some ctx) (k : CC.Cont)
    (i : Fin 5) (cell : ContextLocal m i) (rest : CC.Stmt)
    (actualBinding : e.get (contextName i) = some (cell.block, contextLocalType i))
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world 3
        (.State f (.Ssequence (contextAssignmentFor temporary pointee i) rest) k e le before)
        (.State f rest k e le after) ∧
      CC.Mem.load (contextChunk i) after cell.block 0 = some (contextValue ctx i) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ contextName i →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨after, stored, afterAccess⟩ :=
    create_store m before (contextChunk i) cell.block (contextValue ctx i) access cell.writable
  have target := context_lvalue_body world e layout m before le i cell actualBinding
  have rhs := context_rhs_body world e temporary pointee represented before le input i
  have mode : CC.accessMode (CC.typeof (contextTarget i)) = .By_value (contextChunk i) := by
    rcases five_cases i with rfl | rfl | rfl | rfl | rfl <;> rfl
  have assigned : CC.doStep world
      (.State f (contextAssignmentFor temporary pointee i) (.Kseq rest k) e le before) =
      some (CC.E0, .State f .Sskip (.Kseq rest k) e le after) := by
    simp only [contextAssignmentFor, CC.doStep, target, rhs.1, rhs.2.1, CC.doAssignLoc, mode]
    change (match CC.Mem.store (contextChunk i) before cell.block 0 (contextValue ctx i) with
      | some memory => some (CC.E0, CC.State.State f .Sskip (.Kseq rest k) e le memory)
      | none => none) = _
    rw [stored]
  have run : InternalRun world 3
      (.State f (.Ssequence (contextAssignmentFor temporary pointee i) rest) k e le before)
      (.State f rest k e le after) :=
    .step trivial (CC.doStep_sound world _ _ _ rfl)
      (.step trivial (CC.doStep_sound world _ _ _ assigned)
        (.step trivial (CC.doStep_sound world _ _ _ rfl) (.refl _)))
  refine ⟨after, run, ?_, ?_, FrameBelow.store cell.fresh stored,
    afterAccess.trans access.symm, CC.Mem.store_nextblock stored⟩
  · simpa only [rhs.2.2] using CC.Mem.load_store_same stored
  · intro id ty block bound different chunk ofs
    have distinct := (allocated_local_storage
      (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm)).2
    exact CC.Mem.load_store_other stored chunk block ofs
      (.inl (distinct _ _ _ _ bound cell.binding different))

private theorem run_context (world : CC.CGenv) (f : CC.Function) (e : CC.Env) (temporary : CC.Ident) (pointee : CC.Ty)
    (layout : ContextLayout world) {addresses : Arm64Registers.PointerOrigins} {ctx : CC.Val} {word : BitVec 64}
    (represented : Arm64Registers.ValueRep addresses ctx word) (m : CC.Mem)
    (cells : (i : Fin 5) → ContextLocal m i)
    (actualBindings : ∀ i, e.get (contextName i) = some ((cells i).block, contextLocalType i))
    (rows : List (Fin 5)) (rest : CC.Stmt)
    (le : CC.TempEnv) (input : le.get temporary = some ctx) (k : CC.Cont) (before : CC.Mem)
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world (3 * rows.length)
        (.State f (rows.foldr (fun i next => .Ssequence (contextAssignmentFor temporary pointee i) next) rest)
          k e le before)
        (.State f rest k e le after) ∧
      (∀ i ∈ rows, CC.Mem.load (contextChunk i) after (cells i).block 0 = some (contextValue ctx i)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) →
        (∀ i ∈ rows, id ≠ contextName i) →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  induction rows generalizing before with
  | nil =>
    refine ⟨before, .refl _, ?_, ?_, FrameBelow.refl _ _, rfl, rfl⟩
    · intro i member; cases member
    · intro id ty block bound different chunk ofs; rfl
  | cons head tail ih =>
    obtain ⟨middle, headRun, headRead, headOther, headFrame, headAccess, headNext⟩ :=
      context_write world f e temporary pointee layout represented m before le input k head (cells head)
        (tail.foldr (fun i next => .Ssequence (contextAssignmentFor temporary pointee i) next) rest) (actualBindings head) access
    obtain ⟨after, tailRun, tailRead, tailOther, tailFrame, tailAccess, tailNext⟩ :=
      ih middle (headAccess.trans access)
    refine ⟨after, ?_, ?_, ?_, headFrame.trans tailFrame,
      tailAccess.trans headAccess, tailNext.trans headNext⟩
    · simpa only [List.foldr_cons, List.length_cons, Nat.mul_add, Nat.mul_one,
        Nat.add_comm] using headRun.trans tailRun
    · intro i member
      by_cases later : i ∈ tail
      · exact tailRead i later
      · have same : i = head := (List.mem_cons.mp member).resolve_right later
        subst i
        have separate : ∀ i ∈ tail, contextName head ≠ contextName i := by
          intro i member equal
          exact later ((context_names_distinct equal) ▸ member)
        exact (tailOther _ _ _ (cells head).binding separate (contextChunk head) 0).trans headRead
    · intro id ty block bound different chunk ofs
      exact (tailOther id ty block bound
        (fun i member => different i (List.mem_cons_of_mem _ member)) chunk ofs).trans
        (headOther id ty block bound (different head (List.mem_cons_self)) chunk ofs)

/-- The actual five stores take fifteen internal transitions. All three context
cells retain the represented input, LR has RETURN tag 10, and x0 has ABI tag 1. -/
theorem context_initialized_body (world : CC.CGenv) (f : CC.Function) (e : CC.Env) (temporary : CC.Ident) (pointee : CC.Ty)
    (layout : ContextLayout world) {addresses : Arm64Registers.PointerOrigins} {ctx : CC.Val} {word : BitVec 64}
    (represented : Arm64Registers.ValueRep addresses ctx word) (m before : CC.Mem)
    (le : CC.TempEnv) (input : le.get temporary = some ctx) (k : CC.Cont)
    (rest : CC.Stmt)
    (actualBindings : ∀ i block, (allocation m).1.get (contextName i) = some (block, contextLocalType i) →
      e.get (contextName i) = some (block, contextLocalType i))
    (access : before.access = (allocation m).2.access) :
    ∃ cells : (i : Fin 5) → ContextLocal m i, ∃ after,
      InternalRun world 15 (.State f ((List.ofFn (contextAssignmentFor temporary pointee)).foldr CC.Stmt.Ssequence rest) k e le before)
        (.State f rest k e le after) ∧
      (∀ i, CC.Mem.load (contextChunk i) after (cells i).block 0 = some (contextValue ctx i)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) →
        (∀ i, id ≠ contextName i) →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  classical
  let cells : (i : Fin 5) → ContextLocal m i := fun i => Classical.choice (context_local m i)
  obtain ⟨after, run, read, other, frame, finalAccess, next⟩ :=
    run_context world f e temporary pointee layout represented m cells
      (fun i => actualBindings i _ (cells i).binding) (List.finRange 5) rest le input k before access
  refine ⟨cells, after, ?_, (fun i => read i (List.mem_finRange i)), ?_, frame, finalAccess, next⟩
  · have mapped : List.ofFn (contextAssignmentFor temporary pointee) = (List.finRange 5).map (contextAssignmentFor temporary pointee) := by
      simp only [List.finRange, List.map_ofFn, Function.comp_def]
    simpa only [List.length_finRange, mapped, List.foldr_map] using run
  · intro id ty block bound different chunk ofs
    exact other id ty block bound (fun i _ => different i) chunk ofs

theorem context_initialized_bound (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) {addresses : Arm64Registers.PointerOrigins} {ctx : CC.Val} {word : BitVec 64}
    (represented : Arm64Registers.ValueRep addresses ctx word) (m before : CC.Mem)
    (le : CC.TempEnv) (input : le.get Arm64Entry._ctx = some ctx) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ cells : (i : Fin 5) → ContextLocal m i, ∃ after,
      InternalRun world 15 (.State producer afterSpZero k (allocation m).1 le before)
        (.State producer afterContext k (allocation m).1 le after) ∧
      (∀ i, CC.Mem.load (contextChunk i) after (cells i).block 0 = some (contextValue ctx i)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) →
        (∀ i, id ≠ contextName i) →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  have actualLayout : ContextLayout world := by rw [ContextLayout, layout]; exact context_pointer_layout
  have run := context_initialized_body world producer (allocation m).1 Arm64Entry._ctx CC.tvoid
    actualLayout represented m before le input k afterContext (fun _ _ bound => bound) access
  rw [context_source]
  exact run

/-- Source-composed stack-tag/SP/context setup. Previously initialized stack
metadata survives the context writes, with no external boundary in this segment. -/
theorem stack_sp_and_context_bound (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) {addresses : Arm64Registers.PointerOrigins} {ctx : CC.Val} {word : BitVec 64}
    (represented : Arm64Registers.ValueRep addresses ctx word) (m before : CC.Mem)
    (le : CC.TempEnv) (input : le.get Arm64Entry._ctx = some ctx) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ tags : StackTagLocal m, ∃ spBlock, ∃ cells : (i : Fin 5) → ContextLocal m i, ∃ after,
      (allocation m).1.get Arm64Entry.___a64_sp = some (spBlock, CC.tlong) ∧
      InternalRun world 90 (.State producer afterVectorInputs k (allocation m).1 le before)
        (.State producer afterContext k (allocation m).1 le after) ∧
      (∀ i : Fin 24, CC.Mem.load .Mint8unsigned after tags.block (i.val : Int) = some (.Vint 0)) ∧
      CC.Mem.loadv .Mint64 after (.Vptr spBlock 0) = some (.Vlong 0) ∧
      (∀ i, CC.Mem.load (contextChunk i) after (cells i).block 0 = some (contextValue ctx i)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) →
        id ≠ Arm64Entry.___a64_stack_tag → id ≠ Arm64Entry.___a64_sp →
        (∀ i, id ≠ contextName i) →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨tags, spBlock, middle, spBinding, setupRun, tagReads, spRead,
      setupOther, setupFrame, setupAccess, setupNext⟩ := stack_tags_and_sp_bound world m before le k access
  obtain ⟨cells, after, contextRun, contextReads, contextOther, contextFrame, contextAccess, contextNext⟩ :=
    context_initialized_bound world layout represented m middle le input k (setupAccess.trans access)
  have notTags : ∀ i, Arm64Entry.___a64_stack_tag ≠ contextName i := by decide +kernel
  have notSp : ∀ i, Arm64Entry.___a64_sp ≠ contextName i := by decide +kernel
  refine ⟨tags, spBlock, cells, after, spBinding, setupRun.trans contextRun, ?_, ?_, contextReads,
    ?_, setupFrame.trans contextFrame, contextAccess.trans setupAccess, contextNext.trans setupNext⟩
  · intro i
    exact (contextOther _ _ _ tags.binding notTags .Mint8unsigned (i.val : Int)).trans (tagReads i)
  · change CC.Mem.load .Mint64 after spBlock 0 = some (.Vlong 0)
    exact (contextOther _ _ _ spBinding notSp .Mint64 0).trans spRead
  · intro id ty block bound notTags notSp notContext chunk ofs
    exact (contextOther id ty block bound notContext chunk ofs).trans
      (setupOther id ty block bound notTags notSp chunk ofs)

theorem context_initialized {addresses : Arm64Registers.PointerOrigins} {ctx : CC.Val} {word : BitVec 64}
    (represented : Arm64Registers.ValueRep addresses ctx word) (m before : CC.Mem)
    (le : CC.TempEnv) (input : le.get Arm64Entry._ctx = some ctx) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ cells : (i : Fin 5) → ContextLocal m i, ∃ after,
      InternalRun ge 15 (.State producer afterSpZero k (allocation m).1 le before)
        (.State producer afterContext k (allocation m).1 le after) ∧
      (∀ i, CC.Mem.load (contextChunk i) after (cells i).block 0 = some (contextValue ctx i)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) →
        (∀ i, id ≠ contextName i) →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock :=
  context_initialized_bound ge rfl represented m before le input k access

theorem stack_sp_and_context {addresses : Arm64Registers.PointerOrigins} {ctx : CC.Val} {word : BitVec 64}
    (represented : Arm64Registers.ValueRep addresses ctx word) (m before : CC.Mem)
    (le : CC.TempEnv) (input : le.get Arm64Entry._ctx = some ctx) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ tags : StackTagLocal m, ∃ spBlock, ∃ cells : (i : Fin 5) → ContextLocal m i, ∃ after,
      (allocation m).1.get Arm64Entry.___a64_sp = some (spBlock, CC.tlong) ∧
      InternalRun ge 90 (.State producer afterVectorInputs k (allocation m).1 le before)
        (.State producer afterContext k (allocation m).1 le after) ∧
      (∀ i : Fin 24, CC.Mem.load .Mint8unsigned after tags.block (i.val : Int) = some (.Vint 0)) ∧
      CC.Mem.loadv .Mint64 after (.Vptr spBlock 0) = some (.Vlong 0) ∧
      (∀ i, CC.Mem.load (contextChunk i) after (cells i).block 0 = some (contextValue ctx i)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) →
        id ≠ Arm64Entry.___a64_stack_tag → id ≠ Arm64Entry.___a64_sp →
        (∀ i, id ≠ contextName i) →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock :=
  stack_sp_and_context_bound ge rfl represented m before le input k access

end KProgFormal.ClightRefinement.Arm64Producer
