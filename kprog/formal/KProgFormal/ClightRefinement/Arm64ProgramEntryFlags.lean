import KProgFormal.ClightRefinement.Arm64ProgramEntryTables

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryFlags

open Arm64ProgramEntryAllocation (world allocation)
open Arm64Producer (TableLocals FlagDeclaration flagWord tableCellName tableCellType tableName tableType)

/-- Actual flag bodies carry checked source schemas and real successors. -/
private def parts : List { row : CC.Stmt × FlagDeclaration // row.1 = row.2.body } × CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryTables.afterPointerTables)) none
    let rowTy ← Lean.Elab.Term.elabTerm (← `(CC.Stmt × FlagDeclaration)) none
    let predicate ← Lean.Elab.Term.elabTerm
      (← `(fun row : CC.Stmt × FlagDeclaration => row.1 = row.2.body)) none
    let certificateTy ← Lean.Meta.mkAppM ``Subtype #[predicate]
    let mut rows : Array Lean.Expr := #[]
    for i in [:4] do
      let original := body
      let outer ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless outer.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "actual flag declaration spine ended early"
      let next := outer.getAppArgs[1]!
      let number := Lean.Syntax.mkNumLit (toString i)
      let source ← Lean.Elab.Term.elabTerm (← `(Arm64Producer.flagDeclaration $number)) none
      let name ← Lean.Meta.mkAppM ``FlagDeclaration.name #[source]
      let temporary ← Lean.Meta.mkAppM ``FlagDeclaration.inputTemp #[source]
      let mapped ← Lean.Meta.mkAppM ``Arm64ProgramEntrySource.temporaryName #[temporary]
      let decl ← Lean.Meta.mkAppM ``FlagDeclaration.mk #[name, mapped, next]
      let row ← Lean.Meta.mkAppM ``Prod.mk #[original, decl]
      let rhs ← Lean.Meta.mkAppM ``FlagDeclaration.body #[decl]
      rows := rows.push (Lean.mkAppN (Lean.mkConst ``Subtype.mk [.succ .zero])
        #[rowTy, predicate, row, (← Lean.Meta.mkEqRefl rhs)])
      body := next
    Lean.Elab.Tactic.closeMainGoal `actual_flags
      (← Lean.Meta.mkAppM ``Prod.mk #[(← Lean.Meta.mkListLit certificateTy rows.toList), body])

private theorem count : parts.1.length = 4 := by rfl

def declaration (i : Fin 4) : FlagDeclaration :=
  (parts.1[i.val]'(by rw [count]; exact i.isLt)).val.2

def flagStage (i : Fin 4) : CC.Stmt :=
  (parts.1[i.val]'(by rw [count]; exact i.isLt)).val.1

def afterFlags : CC.Stmt := parts.2

def stage (n : Nat) : CC.Stmt :=
  if h : n < 4 then flagStage ⟨n, h⟩ else afterFlags

theorem source (i : Fin 4) : flagStage i = (declaration i).body :=
  (parts.1[i.val]'(by rw [count]; exact i.isLt)).property

theorem first_stage : stage 0 = Arm64ProgramEntryTables.afterPointerTables := by rfl

theorem chain : ∀ i : Fin 4, (declaration i).rest = stage (i.val + 1) := by
  simp only [Fin.forall_fin_succ, Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | trivial

theorem metadata : ∀ i : Fin 4,
    (declaration i).name = (Arm64Producer.flagDeclaration i).name ∧
    (declaration i).inputTemp = Arm64ProgramEntrySource.temporaryName (Arm64Producer.flagDeclaration i).inputTemp ∧
    ((declaration i).name, CC.tuchar) ∈ Arm64Producer.producer.fn_vars ∧
    Arm64ProgramEntryAllocation.localName (declaration i).name = (declaration i).name ∧
    (declaration i).inputTemp ≠ Arm64ProgramFixture._ctx := by decide +kernel

def vectorStart : CC.Stmt := by
  run_tac do
    let body ← Lean.Elab.Term.elabTerm (← `(afterFlags)) none
    let outer ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
    unless outer.isAppOfArity ``CC.Stmt.Ssequence 2 do
      throwError "actual LR-zero successor changed"
    Lean.Elab.Tactic.closeMainGoal `actual_vector_start outer.getAppArgs[1]!

theorem lr_source : afterFlags =
    .Ssequence (.Sassign (.Evar Arm64Entry.___a64_lr CC.tulong) (.Econst_int (0#32) CC.tint)) vectorStart := by
  run_tac do
    let rhs ← Lean.Elab.Term.elabTerm
      (← `((CC.Stmt.Ssequence (.Sassign (.Evar Arm64Entry.___a64_lr CC.tulong)
        (.Econst_int (0#32) CC.tint)) vectorStart))) none
    Lean.Elab.Tactic.closeMainGoal `actual_lr_zero (← Lean.Meta.mkEqRefl rhs)

theorem binding (initial : CC.Mem) (i : Fin 4) (block : CC.Block)
    (bound : (Arm64Producer.allocation initial).1.get (declaration i).name = some (block, CC.tuchar)) :
    (allocation initial).1.get (declaration i).name = some (block, CC.tuchar) := by
  have actual := Arm64ProgramEntryAllocation.local_binding initial _ _ _ bound
  rw [(metadata i).2.2.2.1] at actual
  exact actual

theorem lr_binding (initial : CC.Mem) (block : CC.Block)
    (bound : (Arm64Producer.allocation initial).1.get Arm64Entry.___a64_lr = some (block, CC.tulong)) :
    (allocation initial).1.get Arm64Entry.___a64_lr = some (block, CC.tulong) := by
  have actual := Arm64ProgramEntryAllocation.local_binding initial _ _ _ bound
  have fixed : Arm64ProgramEntryAllocation.localName Arm64Entry.___a64_lr = Arm64Entry.___a64_lr := by
    decide +kernel
  rw [fixed] at actual
  exact actual

/-- The actual flag visit reuses the single shared scalar store construction. -/
theorem input_returns (i : Fin 4) (initial before supplied : CC.Mem)
    (le : CC.TempEnv) (k : CC.Cont) (value : BitVec 64) (trace : CC.Trace)
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
      [.Vint (6#32)] before trace (.Vlong value) supplied)
    (access : supplied.access = (Arm64Producer.allocation initial).2.access) :
    ∃ block after, (Arm64Producer.allocation initial).1.get (declaration i).name = some (block, CC.tuchar) ∧
      CC.Star (CC.Step2 world)
        (.State Arm64ProgramFixture.f_arm64_execute_compile (flagStage i) k (allocation initial).1 le before)
        trace (.State Arm64ProgramFixture.f_arm64_execute_compile (declaration i).rest k
          (allocation initial).1 (le.set (declaration i).inputTemp (.Vlong value)) after) ∧
      CC.Mem.loadv .Mint8unsigned after (.Vptr block 0) = some (.Vint (flagWord value)) ∧
      (flagWord value = (0#32) ∨ flagWord value = (1#32)) ∧
      (∀ id ty other, (Arm64Producer.allocation initial).1.get id = some (other, ty) →
        id ≠ (declaration i).name → ∀ chunk ofs,
        CC.Mem.load chunk after other ofs = CC.Mem.load chunk supplied other ofs) ∧
      FrameBelow initial.nextblock supplied after ∧ after.access = supplied.access ∧
      after.nextblock = supplied.nextblock := by
  rw [source]
  exact Arm64Producer.flag_input_returns_body world Arm64ProgramFixture.f_arm64_execute_compile
    (allocation initial).1 Arm64ProgramEntryCall.inputBlock Arm64ProgramEntryCall.input_binding
    (Arm64ProgramEntryCall.input_unshadowed initial) (declaration i) (metadata i).2.2.1
    initial before supplied (binding initial i) le k value trace provider access

private theorem flag_not_lr : ∀ i : Fin 4, (declaration i).name ≠ Arm64Entry.___a64_lr := by
  decide +kernel

/-- Four actual provider visits followed by the real LR-zero assignment. -/
theorem initialized (initial before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (values : Fin 4 → BitVec 64) (provider : Arm64ProducerFlagInputs.ProviderAt world initial values)
    (access : before.access = (allocation initial).2.access) :
    ∃ blocks : Fin 4 → CC.Block, ∃ lrBlock after finalLe, ∃ traces : List CC.Trace,
      traces.length = 4 ∧
      (∀ i, (Arm64Producer.allocation initial).1.get (declaration i).name = some (blocks i, CC.tuchar)) ∧
      (∀ i, (allocation initial).1.get (declaration i).name = some (blocks i, CC.tuchar)) ∧
      (Arm64Producer.allocation initial).1.get Arm64Entry.___a64_lr = some (lrBlock, CC.tulong) ∧
      (allocation initial).1.get Arm64Entry.___a64_lr = some (lrBlock, CC.tulong) ∧
      CC.Star (CC.Step2 world)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryTables.afterPointerTables
          k (allocation initial).1 le before)
        traces.flatten (.State Arm64ProgramFixture.f_arm64_execute_compile vectorStart
          k (allocation initial).1 finalLe after) ∧
      (∀ i, CC.Mem.load .Mint8unsigned after (blocks i) 0 = some (.Vint (flagWord (values i)))) ∧
      CC.Mem.loadv .Mint64 after (.Vptr lrBlock 0) = some (.Vlong 0) ∧
      (∀ id ty block, (Arm64Producer.allocation initial).1.get id = some (block, ty) →
        (∀ i, id ≠ (declaration i).name) → id ≠ Arm64Entry.___a64_lr → ∀ chunk ofs,
        CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      (∀ id, (∀ i, id ≠ (declaration i).inputTemp) → finalLe.get id = le.get id) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  have storage : ∀ i : Fin 4, ∃ block,
      (Arm64Producer.allocation initial).1.get (declaration i).name = some (block, CC.tuchar) := by
    intro i
    obtain ⟨block, bound, _⟩ := Arm64Producer.scalar_local initial (declaration i).name CC.tuchar .Mint8unsigned
      (metadata i).2.2.1 rfl (by decide)
    exact ⟨block, bound⟩
  let blocks : Fin 4 → CC.Block := fun i => Classical.choose (storage i)
  have bindings : ∀ i, (Arm64Producer.allocation initial).1.get (declaration i).name = some (blocks i, CC.tuchar) :=
    fun i => Classical.choose_spec (storage i)
  have canonical : before.access = (Arm64Producer.allocation initial).2.access :=
    access.trans (congrArg CC.Mem.access (Arm64ProgramEntryAllocation.allocation_corresponds initial).1.symm)
  obtain ⟨middle, finalLe, traces, length, run, reads, _, locals, temps, frame, finalAccess, next⟩ :=
    Arm64ProducerFlagInputs.run_suffix_body world Arm64ProgramFixture.f_arm64_execute_compile
      (allocation initial).1 declaration stage (fun i => (metadata i).1) chain initial blocks bindings values provider
      (fun i before supplied le k trace call access => by
        simpa only [stage, dite_eq_left i.isLt] using input_returns i initial before supplied le k (values i) trace call access)
      4 0 rfl before le k canonical
  obtain ⟨lrBlock, after, lrBinding, lrRun, lrRead, lrLocals, lrFrame, lrAccess, lrNext⟩ :=
    Arm64Producer.lr_initialized_body world Arm64ProgramFixture.f_arm64_execute_compile
      (allocation initial).1 vectorStart initial middle finalLe k (lr_binding initial) (finalAccess.trans canonical)
  have finish : stage 4 = afterFlags := rfl
  rw [first_stage, finish, lr_source] at run
  refine ⟨blocks, lrBlock, after, finalLe, traces, length, bindings, (fun i => binding initial i _ (bindings i)),
    lrBinding, lr_binding initial _ lrBinding, ?_, ?_, lrRead, ?_, temps,
    frame.trans lrFrame, lrAccess.trans finalAccess, lrNext.trans next⟩
  · simpa only [CC.E0, CC.Eapp, List.append_nil] using star_trans run lrRun.sound
  · intro i
    exact (lrLocals _ _ _ (bindings i) (flag_not_lr i) .Mint8unsigned 0).trans (reads i (Nat.zero_le _))
  · intro id ty block bound notFlags notLr chunk ofs
    exact (lrLocals id ty block bound notLr chunk ofs).trans (locals id ty block bound notFlags chunk ofs)

/-- Actual bindings and final observations for all flags and LR. -/
def Readbacks (initial memory : CC.Mem) (values : Fin 4 → BitVec 64) : Prop :=
  ∃ blocks : Fin 4 → CC.Block, ∃ lrBlock,
    (∀ i, (Arm64Producer.allocation initial).1.get (declaration i).name = some (blocks i, CC.tuchar)) ∧
    (∀ i, (allocation initial).1.get (declaration i).name = some (blocks i, CC.tuchar)) ∧
    (Arm64Producer.allocation initial).1.get Arm64Entry.___a64_lr = some (lrBlock, CC.tulong) ∧
    (allocation initial).1.get Arm64Entry.___a64_lr = some (lrBlock, CC.tulong) ∧
    (∀ i, CC.Mem.load .Mint8unsigned memory (blocks i) 0 = some (.Vint (flagWord (values i)))) ∧
    CC.Mem.loadv .Mint64 memory (.Vptr lrBlock 0) = some (.Vlong 0)

private def Protected (id : CC.Ident) : Prop :=
  (∀ i : Fin 4, id ≠ (declaration i).name) ∧ id ≠ Arm64Entry.___a64_lr

private theorem protection (id : CC.Ident)
    (flags : ∀ i : Fin 4, id ≠ (Arm64Producer.flagDeclaration i).name)
    (lr : id ≠ Arm64Entry.___a64_lr) : Protected id := by
  refine ⟨?_, lr⟩
  intro i
  rw [(metadata i).1]
  exact flags i

private theorem cells_protected : ∀ selected (i : Fin 31), Protected (tableCellName selected i) := by
  have different : ∀ selected (i : Fin 31),
      (∀ j : Fin 4, tableCellName selected i ≠ (Arm64Producer.flagDeclaration j).name) ∧
      tableCellName selected i ≠ Arm64Entry.___a64_lr := by decide +kernel
  exact fun selected i => protection _ (different selected i).1 (different selected i).2

private theorem tables_protected : ∀ selected, Protected (tableName selected) := by
  have different : ∀ selected,
      (∀ j : Fin 4, tableName selected ≠ (Arm64Producer.flagDeclaration j).name) ∧
      tableName selected ≠ Arm64Entry.___a64_lr := by decide +kernel
  exact fun selected => protection _ (different selected).1 (different selected).2

private theorem caches_protected : ∀ returns,
    Protected (Arm64Producer.baseName returns) ∧ Protected (Arm64Producer.validName returns) := by
  have different : ∀ returns,
      ((∀ j : Fin 4, Arm64Producer.baseName returns ≠ (Arm64Producer.flagDeclaration j).name) ∧
        Arm64Producer.baseName returns ≠ Arm64Entry.___a64_lr) ∧
      ((∀ j : Fin 4, Arm64Producer.validName returns ≠ (Arm64Producer.flagDeclaration j).name) ∧
        Arm64Producer.validName returns ≠ Arm64Entry.___a64_lr) := by decide +kernel
  exact fun returns => ⟨protection _ (different returns).1.1 (different returns).1.2,
    protection _ (different returns).2.1 (different returns).2.2⟩

/-- Actual entry through the four flag visits and LR zero. The 30 GPR
traces precede the four flag traces; all earlier storage observations survive. -/
theorem entry_initialized (initial : CC.Mem) (ctx : CC.Val) (k : CC.Cont)
    (values : Fin 31 → BitVec 64) (provider : Arm64ProducerGprInputs.ProviderAt world initial values)
    (flags : Fin 4 → BitVec 64) (flagProvider : Arm64ProducerFlagInputs.ProviderAt world initial flags) :
    ∃ blocks : Bool → Fin 31 → CC.Block, ∃ after le, ∃ traces : List CC.Trace,
      traces.length = 34 ∧
      (∀ selected i, (Arm64Producer.allocation initial).1.get (tableCellName selected i) =
        some (blocks selected i, tableCellType selected)) ∧
      (∀ selected i, (allocation initial).1.get (tableCellName selected i) =
        some (blocks selected i, tableCellType selected)) ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [ctx] k initial)
        traces.flatten (.State Arm64ProgramFixture.f_arm64_execute_compile vectorStart
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
      Readbacks initial after flags ∧
      Arm64ProgramEntryInputs.CacheReadbacks initial after ∧ le.get Arm64ProgramFixture._ctx = some ctx ∧
      FrameBelow initial.nextblock initial after ∧ after.access = (allocation initial).2.access ∧
      after.nextblock = (allocation initial).2.nextblock := by
  obtain ⟨blocks, before, le, registerTraces, registerLength, bindings, actualBindings,
      registerRun, registers, tables, caches, context, frame, access, next⟩ :=
    Arm64ProgramEntryTables.entry_initialized initial ctx k values provider
  obtain ⟨flagBlocks, lrBlock, after, finalLe, flagTraces, flagLength, flagBindings,
      actualFlagBindings, lrBinding, actualLrBinding, flagRun, flagReads, lrRead,
      other, temps, flagFrame, flagAccess, flagNext⟩ :=
    initialized initial before le k flags flagProvider access
  refine ⟨blocks, after, finalLe, registerTraces ++ flagTraces, ?_, bindings, actualBindings,
    ?_, ?_, ?_, ⟨flagBlocks, lrBlock, flagBindings, actualFlagBindings, lrBinding, actualLrBinding, flagReads, lrRead⟩,
    ?_, ?_, frame.trans flagFrame, flagAccess.trans access, flagNext.trans next⟩
  · simp only [List.length_append, registerLength, flagLength]
  · simpa only [List.flatten_append, CC.Eapp] using star_trans registerRun flagRun
  · intro i
    exact ⟨(other _ _ _ (bindings false i) (cells_protected false i).1 (cells_protected false i).2 .Mint64 0).trans
        (registers i).1,
      (other _ _ _ (bindings true i) (cells_protected true i).1 (cells_protected true i).2 .Mint8unsigned 0).trans
        (registers i).2⟩
  · intro selected
    obtain ⟨locals, bound, cells, reads⟩ := tables selected
    refine ⟨locals, bound, cells, ?_⟩
    intro i
    exact (other _ _ _ locals.binding (tables_protected selected).1 (tables_protected selected).2
      CC.Mptr (8 * (i.val : Int))).trans (reads i)
  · intro returns
    obtain ⟨locals, baseBound, validBound, base, valid⟩ := caches returns
    refine ⟨locals, baseBound, validBound, ?_, ?_⟩
    · exact (other _ _ _ locals.baseBinding (caches_protected returns).1.1
        (caches_protected returns).1.2 .Mint64 0).trans base
    · exact (other _ _ _ locals.validBinding (caches_protected returns).2.1
        (caches_protected returns).2.2 .Mint8unsigned 0).trans valid
  · exact (temps _ (fun i => Ne.symm (metadata i).2.2.2.2)).trans context

end KProgFormal.ClightRefinement.Arm64ProgramEntryFlags
