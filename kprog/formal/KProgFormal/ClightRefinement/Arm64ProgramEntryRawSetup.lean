import KProgFormal.ClightRefinement.Arm64ProgramEntryVectorInputs

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryRawSetup

open Arm64ProgramEntryAllocation (world allocation)
open Arm64Producer (StackTagLocal ContextLocal tableCellName tableCellType tableName tableType TableLocals
  contextName contextLocalType contextChunk contextValue)

def pointee : CC.Ty := .Tstruct Arm64ProgramFixture.___sk_buff CC.noattr

def assignments : List CC.Stmt := List.ofFn (Arm64Producer.contextAssignmentFor Arm64ProgramFixture._ctx pointee)

/-- Actual successors after the 24 tag stores, SP zero, and five context stores. -/
private def parts : CC.Stmt × CC.Stmt × CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryVectorInputs.afterVectorInputs)) none
    let mut afterTags := body
    let mut afterSP := body
    for i in [:30] do
      if i == 24 then afterTags := body
      if i == 25 then afterSP := body
      let outer ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless outer.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "actual RAW setup no longer has all 30 assignment heads"
      body := outer.getAppArgs[1]!
    Lean.Elab.Tactic.closeMainGoal `actual_raw_successors
      (← Lean.Meta.mkAppM ``Prod.mk #[afterTags, (← Lean.Meta.mkAppM ``Prod.mk #[afterSP, body])])

def afterStackTags : CC.Stmt := parts.1
def afterSpZero : CC.Stmt := parts.2.1
def beforeHeader : CC.Stmt := parts.2.2

theorem stack_source : Arm64ProgramEntryVectorInputs.afterVectorInputs =
    (List.ofFn Arm64Producer.stackTagAssignment).foldr CC.Stmt.Ssequence afterStackTags := by
  run_tac do
    let rhs ← Lean.Elab.Term.elabTerm
      (← `((List.ofFn Arm64Producer.stackTagAssignment).foldr CC.Stmt.Ssequence afterStackTags)) none
    Lean.Elab.Tactic.closeMainGoal `actual_stack_tags (← Lean.Meta.mkEqRefl rhs)

theorem sp_source : afterStackTags =
    .Ssequence (.Sassign (.Evar Arm64Entry.___a64_sp CC.tlong) (.Econst_int (0#32) CC.tint)) afterSpZero := by
  run_tac do
    let rhs ← Lean.Elab.Term.elabTerm
      (← `((CC.Stmt.Ssequence (.Sassign (.Evar Arm64Entry.___a64_sp CC.tlong)
        (.Econst_int (0#32) CC.tint)) afterSpZero))) none
    Lean.Elab.Tactic.closeMainGoal `actual_sp_zero (← Lean.Meta.mkEqRefl rhs)

theorem context_source : afterSpZero = assignments.foldr CC.Stmt.Ssequence beforeHeader := by
  run_tac do
    let rhs ← Lean.Elab.Term.elabTerm (← `(assignments.foldr CC.Stmt.Ssequence beforeHeader)) none
    Lean.Elab.Tactic.closeMainGoal `actual_context_stores (← Lean.Meta.mkEqRefl rhs)

theorem boundary : beforeHeader = Arm64ProgramEntryAssignments.beforeHeader := by
  run_tac do
    let rhs ← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryAssignments.beforeHeader)) none
    Lean.Elab.Tactic.closeMainGoal `actual_raw_header_boundary (← Lean.Meta.mkEqRefl rhs)

theorem tag_binding (initial : CC.Mem) (tags : StackTagLocal initial) :
    (allocation initial).1.get Arm64Entry.___a64_stack_tag = some (tags.block, Arm64Producer.stackTagType) := by
  have bound := Arm64ProgramEntryAllocation.local_binding initial _ _ _ tags.binding
  have fixed : Arm64ProgramEntryAllocation.localName Arm64Entry.___a64_stack_tag = Arm64Entry.___a64_stack_tag := by
    decide +kernel
  rw [fixed] at bound
  exact bound

theorem sp_binding (initial : CC.Mem) (block : CC.Block)
    (bound : (Arm64Producer.allocation initial).1.get Arm64Entry.___a64_sp = some (block, CC.tlong)) :
    (allocation initial).1.get Arm64Entry.___a64_sp = some (block, CC.tlong) := by
  have actual := Arm64ProgramEntryAllocation.local_binding initial _ _ _ bound
  have fixed : Arm64ProgramEntryAllocation.localName Arm64Entry.___a64_sp = Arm64Entry.___a64_sp := by
    decide +kernel
  rw [fixed] at actual
  exact actual

theorem context_binding (initial : CC.Mem) (i : Fin 5) (block : CC.Block)
    (bound : (Arm64Producer.allocation initial).1.get (contextName i) = some (block, contextLocalType i)) :
    (allocation initial).1.get (contextName i) = some (block, contextLocalType i) := by
  have actual := Arm64ProgramEntryAllocation.local_binding initial _ _ _ bound
  have fixed : ∀ i : Fin 5,
      Arm64ProgramEntryAllocation.localName (contextName i) = contextName i ∧
      Arm64ProgramEntryAllocation.localType (contextLocalType i) = contextLocalType i := by decide +kernel
  rw [(fixed i).1, (fixed i).2] at actual
  exact actual

theorem context_layout : Arm64Producer.ContextLayout world := by
  unfold Arm64Producer.ContextLayout
  decide +kernel

/-- Stack-tag, signed-SP and context observations at the actual header boundary. -/
def Readbacks (initial memory : CC.Mem) (ctx : CC.Val) : Prop :=
  ∃ tags : StackTagLocal initial, ∃ spBlock, ∃ cells : (i : Fin 5) → ContextLocal initial i,
    (allocation initial).1.get Arm64Entry.___a64_stack_tag = some (tags.block, Arm64Producer.stackTagType) ∧
    (Arm64Producer.allocation initial).1.get Arm64Entry.___a64_sp = some (spBlock, CC.tlong) ∧
    (allocation initial).1.get Arm64Entry.___a64_sp = some (spBlock, CC.tlong) ∧
    (∀ i, (allocation initial).1.get (contextName i) = some ((cells i).block, contextLocalType i)) ∧
    (∀ i : Fin 24, CC.Mem.load .Mint8unsigned memory tags.block (i.val : Int) = some (.Vint 0)) ∧
    CC.Mem.loadv .Mint64 memory (.Vptr spBlock 0) = some (.Vlong 0) ∧
    ∀ i, CC.Mem.load (contextChunk i) memory (cells i).block 0 = some (contextValue ctx i)

/-- The actual 30 stores execute silently in 90 transitions with unchanged temps. -/
theorem initialized {addresses : Arm64Registers.PointerOrigins} {ctx : CC.Val} {word : BitVec 64}
    (represented : Arm64Registers.ValueRep addresses ctx word) (initial before : CC.Mem)
    (le : CC.TempEnv) (input : le.get Arm64ProgramFixture._ctx = some ctx) (k : CC.Cont)
    (access : before.access = (allocation initial).2.access) :
    ∃ after, InternalRun world 90
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryVectorInputs.afterVectorInputs
        k (allocation initial).1 le before)
      (.State Arm64ProgramFixture.f_arm64_execute_compile beforeHeader k (allocation initial).1 le after) ∧
      Readbacks initial after ctx ∧
      (∀ id ty block, (Arm64Producer.allocation initial).1.get id = some (block, ty) →
        id ≠ Arm64Entry.___a64_stack_tag → id ≠ Arm64Entry.___a64_sp →
        (∀ i, id ≠ contextName i) → ∀ chunk ofs,
        CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  have canonical : before.access = (Arm64Producer.allocation initial).2.access :=
    access.trans (congrArg CC.Mem.access (Arm64ProgramEntryAllocation.allocation_corresponds initial).1.symm)
  obtain ⟨tags⟩ := Arm64Producer.stack_tag_local initial
  obtain ⟨m1, tagRun, tagReads, tagOther, tagFrame, tagAccess, tagNext⟩ :=
    Arm64Producer.stack_tags_initialized_body world Arm64ProgramFixture.f_arm64_execute_compile
      (allocation initial).1 initial before le k afterStackTags tags (tag_binding initial tags) canonical
  obtain ⟨spBlock, m2, spBinding, spRun, spRead, spOther, spFrame, spAccess, spNext⟩ :=
    Arm64Producer.sp_initialized_body world Arm64ProgramFixture.f_arm64_execute_compile
      (allocation initial).1 afterSpZero initial m1 le k (sp_binding initial) (tagAccess.trans canonical)
  obtain ⟨cells, after, contextRun, contextReads, contextOther, contextFrame, contextAccess, contextNext⟩ :=
    Arm64Producer.context_initialized_body world Arm64ProgramFixture.f_arm64_execute_compile
      (allocation initial).1 Arm64ProgramFixture._ctx pointee context_layout represented initial m2 le input k
      beforeHeader (context_binding initial) (spAccess.trans (tagAccess.trans canonical))
  rw [← stack_source] at tagRun
  rw [← sp_source] at spRun
  change InternalRun world 15 (.State Arm64ProgramFixture.f_arm64_execute_compile
    (assignments.foldr CC.Stmt.Ssequence beforeHeader) k (allocation initial).1 le m2)
    (.State Arm64ProgramFixture.f_arm64_execute_compile beforeHeader k (allocation initial).1 le after) at contextRun
  rw [← context_source] at contextRun
  refine ⟨after, tagRun.trans (spRun.trans contextRun), ?_, ?_,
    tagFrame.trans (spFrame.trans contextFrame), contextAccess.trans (spAccess.trans tagAccess),
    contextNext.trans (spNext.trans tagNext)⟩
  · refine ⟨tags, spBlock, cells, tag_binding initial tags, spBinding, sp_binding initial _ spBinding,
      (fun i => context_binding initial i _ (cells i).binding), ?_, ?_, contextReads⟩
    · intro i
      exact (contextOther _ _ _ tags.binding (by decide +kernel) .Mint8unsigned (i.val : Int)).trans
        ((spOther _ _ _ tags.binding (by decide +kernel) .Mint8unsigned (i.val : Int)).trans (tagReads i))
    · exact (contextOther _ _ _ spBinding (by decide +kernel) .Mint64 0).trans spRead
  · intro id ty block bound notTags notSP notContext chunk ofs
    exact (contextOther id ty block bound notContext chunk ofs).trans
      ((spOther id ty block bound notSP chunk ofs).trans (tagOther id ty block bound notTags chunk ofs))

/-- Actual byte readback values of the RAW context and return tags. -/
def tagWord (i : Fin 31) : CC.Integers.Int := if i = 0 then 1 else if i = 30 then 10 else 0

private abbrev Protected (id : CC.Ident) : Prop :=
  id ≠ Arm64Entry.___a64_stack_tag ∧ id ≠ Arm64Entry.___a64_sp ∧ ∀ i : Fin 5, id ≠ contextName i

private theorem words_protected : ∀ i : Fin 31, i ≠ 0 → Protected (tableCellName false i) := by decide +kernel
private theorem tags_protected : ∀ i : Fin 31, i ≠ 0 → i ≠ 30 → Protected (tableCellName true i) := by decide +kernel
private theorem tables_protected : ∀ selected, Protected (tableName selected) := by decide +kernel
private theorem flags_protected : ∀ i : Fin 4, Protected (Arm64ProgramEntryFlags.declaration i).name := by
  have different : ∀ i : Fin 4, Protected (Arm64Producer.flagDeclaration i).name := by decide +kernel
  intro i
  rw [(Arm64ProgramEntryFlags.metadata i).1]
  exact different i
private theorem lr_protected : Protected Arm64Entry.___a64_lr := by decide +kernel
private theorem vectors_protected : Protected Arm64Entry.___a64_vectors := by decide +kernel
private theorem caches_protected : ∀ returns,
    Protected (Arm64Producer.baseName returns) ∧ Protected (Arm64Producer.validName returns) := by decide +kernel

private theorem word_expected (values : Fin 31 → BitVec 64) (ctx : CC.Val) (i : Fin 31) (nonzero : i ≠ 0) :
    .Vlong (Arm64ProgramEntryGprInputs.wordValue values i) = Arm64EntryAdmissibility.rawValue ctx values i := by
  simp only [Arm64EntryAdmissibility.rawValue, ite_eq_right nonzero]
  by_cases last : i = 30
  · subst i; rfl
  · have notLast : i.val ≠ 30 := fun same => last (Fin.ext same)
    simp only [Arm64ProgramEntryGprInputs.wordValue, ite_eq_right notLast, ite_eq_right last]

/-- Actual entry through the silent RAW setup. x0 is replaced by context,
x0/x30 tags change to1/10, and all other previously derived observations survive. -/
theorem entry_initialized (initial : CC.Mem) (ctx : CC.Val) (k : CC.Cont)
    (addresses : Arm64Registers.PointerOrigins) (ctxWord : BitVec 64)
    (represented : Arm64Registers.ValueRep addresses ctx ctxWord)
    (values : Fin 31 → BitVec 64) (provider : Arm64ProducerGprInputs.ProviderAt world initial values)
    (flags : Fin 4 → BitVec 64) (flagProvider : Arm64ProducerFlagInputs.ProviderAt world initial flags)
    (vectors : Fin 64 → BitVec 64) (vectorProvider : Arm64ProducerVectorInputs.ProviderAt world initial vectors) :
    ∃ blocks : Bool → Fin 31 → CC.Block, ∃ after le, ∃ traces : List CC.Trace,
      traces.length = 98 ∧
      (∀ selected i, (Arm64Producer.allocation initial).1.get (tableCellName selected i) =
        some (blocks selected i, tableCellType selected)) ∧
      (∀ selected i, (allocation initial).1.get (tableCellName selected i) =
        some (blocks selected i, tableCellType selected)) ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [ctx] k initial)
        traces.flatten (.State Arm64ProgramFixture.f_arm64_execute_compile beforeHeader
          k (allocation initial).1 le after) ∧
      (∀ i, CC.Mem.load .Mint64 after (blocks false i) 0 =
          some (Arm64EntryAdmissibility.rawValue ctx values i) ∧
        CC.Mem.load .Mint8unsigned after (blocks true i) 0 = some (.Vint (tagWord i))) ∧
      (∀ selected, ∃ locals : TableLocals selected initial,
        (allocation initial).1.get (tableName selected) = some (locals.tableBlock, tableType selected) ∧
        (∀ i, (allocation initial).1.get (tableCellName selected i) =
          some (locals.cellBlock i, tableCellType selected)) ∧
        ∀ i, CC.Mem.load CC.Mptr after locals.tableBlock (8 * (i.val : Int)) =
          some (.Vptr (blocks selected i) 0)) ∧
      Arm64ProgramEntryFlags.Readbacks initial after flags ∧
      Arm64ProgramEntryVectorInputs.Readbacks initial after vectors ∧
      Readbacks initial after ctx ∧
      Arm64ProgramEntryInputs.CacheReadbacks initial after ∧ le.get Arm64ProgramFixture._ctx = some ctx ∧
      FrameBelow initial.nextblock initial after ∧ after.access = (allocation initial).2.access ∧
      after.nextblock = (allocation initial).2.nextblock := by
  obtain ⟨blocks, before, le, traces, length, bindings, actualBindings, priorRun,
      registers, tables, flagReads, vectorReads, caches, context, frame, access, next⟩ :=
    Arm64ProgramEntryVectorInputs.entry_initialized initial ctx k values provider flags flagProvider vectors vectorProvider
  obtain ⟨after, rawRun, rawReads, other, rawFrame, rawAccess, rawNext⟩ :=
    initialized represented initial before le context k access
  obtain ⟨stackTags, spBlock, cells, tagsBinding, spBinding, actualSpBinding, cellBindings,
      stackReads, spRead, contextReads⟩ := rawReads
  refine ⟨blocks, after, le, traces, length, bindings, actualBindings, ?_, ?_, ?_, ?_, ?_,
    ⟨stackTags, spBlock, cells, tagsBinding, spBinding, actualSpBinding, cellBindings, stackReads, spRead, contextReads⟩,
    ?_, context, frame.trans rawFrame, rawAccess.trans access, rawNext.trans next⟩
  · simpa only [CC.E0, CC.Eapp, List.append_nil] using star_trans priorRun rawRun.sound
  · intro i
    constructor
    · by_cases zero : i = 0
      · subst i
        have cellBound := (cells 2).binding
        change (Arm64Producer.allocation initial).1.get (tableCellName false 0) =
          some ((cells 2).block, tableCellType false) at cellBound
        have same : (cells 2).block = blocks false 0 :=
          congrArg Prod.fst (Option.some.inj (cellBound.symm.trans (bindings false 0)))
        have read := contextReads 2
        change CC.Mem.load .Mint64 after (cells 2).block 0 = some ctx at read
        simpa only [Arm64EntryAdmissibility.rawValue, ite_eq_left rfl, ite_true, same] using read
      · have keep := other _ _ _ (bindings false i) (words_protected i zero).1
          (words_protected i zero).2.1 (words_protected i zero).2.2 .Mint64 0
        rw [← word_expected values ctx i zero]
        exact keep.trans (registers i).1
    · by_cases zero : i = 0
      · subst i
        have cellBound := (cells 4).binding
        change (Arm64Producer.allocation initial).1.get (tableCellName true 0) =
          some ((cells 4).block, tableCellType true) at cellBound
        have same : (cells 4).block = blocks true 0 :=
          congrArg Prod.fst (Option.some.inj (cellBound.symm.trans (bindings true 0)))
        have read := contextReads 4
        change CC.Mem.load .Mint8unsigned after (cells 4).block 0 = some (.Vint 1) at read
        simpa only [tagWord, ite_eq_left rfl, ite_true, same] using read
      · by_cases last : i = 30
        · subst i
          have cellBound := (cells 3).binding
          change (Arm64Producer.allocation initial).1.get (tableCellName true 30) =
            some ((cells 3).block, tableCellType true) at cellBound
          have same : (cells 3).block = blocks true 30 :=
            congrArg Prod.fst (Option.some.inj (cellBound.symm.trans (bindings true 30)))
          have read := contextReads 3
          change CC.Mem.load .Mint8unsigned after (cells 3).block 0 = some (.Vint 10) at read
          simpa only [tagWord, ite_eq_right zero, ite_eq_left rfl, ite_true, same] using read
        · have keep := other _ _ _ (bindings true i) (tags_protected i zero last).1
            (tags_protected i zero last).2.1 (tags_protected i zero last).2.2 .Mint8unsigned 0
          simpa only [tagWord, ite_eq_right zero, ite_eq_right last] using keep.trans (registers i).2
  · intro selected
    obtain ⟨locals, bound, cellBounds, reads⟩ := tables selected
    refine ⟨locals, bound, cellBounds, ?_⟩
    intro i
    exact (other _ _ _ locals.binding (tables_protected selected).1 (tables_protected selected).2.1
      (tables_protected selected).2.2 CC.Mptr (8 * (i.val : Int))).trans (reads i)
  · obtain ⟨flagBlocks, lrBlock, flagBindings, actualFlagBindings, lrBinding, actualLrBinding,
        reads, lrRead⟩ := flagReads
    refine ⟨flagBlocks, lrBlock, flagBindings, actualFlagBindings, lrBinding, actualLrBinding, ?_, ?_⟩
    · intro i
      exact (other _ _ _ (flagBindings i) (flags_protected i).1 (flags_protected i).2.1
        (flags_protected i).2.2 .Mint8unsigned 0).trans (reads i)
    · exact (other _ _ _ lrBinding lr_protected.1 lr_protected.2.1 lr_protected.2.2 .Mint64 0).trans lrRead
  · obtain ⟨localVector, bound, reads⟩ := vectorReads
    refine ⟨localVector, bound, ?_⟩
    intro i
    exact (other _ _ _ localVector.binding vectors_protected.1 vectors_protected.2.1
      vectors_protected.2.2 .Mint64 (8 * (i.val : Int))).trans (reads i)
  · intro returns
    obtain ⟨locals, baseBound, validBound, base, valid⟩ := caches returns
    refine ⟨locals, baseBound, validBound, ?_, ?_⟩
    · exact (other _ _ _ locals.baseBinding (caches_protected returns).1.1
        (caches_protected returns).1.2.1 (caches_protected returns).1.2.2 .Mint64 0).trans base
    · exact (other _ _ _ locals.validBinding (caches_protected returns).2.1
        (caches_protected returns).2.2.1 (caches_protected returns).2.2.2 .Mint8unsigned 0).trans valid

end KProgFormal.ClightRefinement.Arm64ProgramEntryRawSetup
