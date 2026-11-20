import KProgFormal.ClightRefinement.Arm64ProgramEntryFlags

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryVectorInputs

open Arm64ProgramEntryAllocation (world allocation)
open Arm64Producer (VectorLocal VectorLayout TableLocals tableCellName tableCellType tableName tableType)

def tag : CC.Ident := Arm64ProgramFixture.__5183
def arrayType : CC.Ty := Arm64Producer.vectorArrayTypeFor tag

structure Declaration where
  index : Fin 64
  temporary : CC.Ident
  rest : CC.Stmt

def Declaration.body (d : Declaration) : CC.Stmt :=
  .Ssequence (Arm64Producer.vectorInitializerFor tag d.temporary d.index) d.rest

/-- Each actual initializer has a checked complete body and real successor. -/
private def parts : List { row : CC.Stmt × Declaration // row.1 = row.2.body } × CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryFlags.vectorStart)) none
    let rowTy ← Lean.Elab.Term.elabTerm (← `(CC.Stmt × Declaration)) none
    let predicate ← Lean.Elab.Term.elabTerm (← `(fun row : CC.Stmt × Declaration => row.1 = row.2.body)) none
    let certificateTy ← Lean.Meta.mkAppM ``Subtype #[predicate]
    let mut rows : Array Lean.Expr := #[]
    for i in [:64] do
      let original := body
      let outer ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless outer.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "actual vector initializer spine ended early"
      let next := outer.getAppArgs[1]!
      let number := Lean.Syntax.mkNumLit (toString i)
      let index ← Lean.Elab.Term.elabTerm (← `(($number : Fin 64))) none
      let source ← Lean.Meta.mkAppM ``Arm64Producer.vectorInputTemp #[index]
      let temporary ← Lean.Meta.mkAppM ``Arm64ProgramEntrySource.temporaryName #[source]
      let declaration ← Lean.Meta.mkAppM ``Declaration.mk #[index, temporary, next]
      let row ← Lean.Meta.mkAppM ``Prod.mk #[original, declaration]
      let rhs ← Lean.Meta.mkAppM ``Declaration.body #[declaration]
      rows := rows.push (Lean.mkAppN (Lean.mkConst ``Subtype.mk [.succ .zero])
        #[rowTy, predicate, row, (← Lean.Meta.mkEqRefl rhs)])
      body := next
    Lean.Elab.Tactic.closeMainGoal `actual_vector_inputs
      (← Lean.Meta.mkAppM ``Prod.mk #[(← Lean.Meta.mkListLit certificateTy rows.toList), body])

private theorem count : parts.1.length = 64 := by rfl

def declaration (i : Fin 64) : Declaration :=
  (parts.1[i.val]'(by rw [count]; exact i.isLt)).val.2

def inputTemp (i : Fin 64) : CC.Ident := (declaration i).temporary

def inputStage (i : Fin 64) : CC.Stmt :=
  (parts.1[i.val]'(by rw [count]; exact i.isLt)).val.1

def afterVectorInputs : CC.Stmt := parts.2

def stage (n : Nat) : CC.Stmt :=
  if h : n < 64 then inputStage ⟨n, h⟩ else afterVectorInputs

theorem metadata : ∀ i : Fin 64,
    (declaration i).index = i ∧
    inputTemp i = Arm64ProgramEntrySource.temporaryName (Arm64Producer.vectorInputTemp i) ∧
    inputTemp i ≠ Arm64ProgramFixture._ctx := by decide +kernel

theorem source (i : Fin 64) : inputStage i =
    .Ssequence (Arm64Producer.vectorInitializerFor tag (inputTemp i) i) (declaration i).rest := by
  have checked := (parts.1[i.val]'(by rw [count]; exact i.isLt)).property
  change inputStage i = .Ssequence
    (Arm64Producer.vectorInitializerFor tag (inputTemp i) (declaration i).index) (declaration i).rest at checked
  rw [(metadata i).1] at checked
  exact checked

theorem first_stage : stage 0 = Arm64ProgramEntryFlags.vectorStart := by rfl

theorem chain : ∀ i : Fin 64, (declaration i).rest = stage (i.val + 1) := by
  simp only [Fin.forall_fin_succ, Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | trivial

theorem last_stage : stage 64 = afterVectorInputs := by rfl

/-- The actual anonymous record, its 16-byte stride and both member offsets. -/
def layout : VectorLayout world tag :=
  { composite := (world.genv_cenv.get tag).get (by decide +kernel)
    binding := by decide +kernel
    size := by decide +kernel
    offsets := by decide +kernel }

theorem binding (initial : CC.Mem) (localVector : VectorLocal initial) :
    (allocation initial).1.get Arm64Entry.___a64_vectors = some (localVector.block, arrayType) := by
  have actual := Arm64ProgramEntryAllocation.local_binding initial _ _ _ localVector.binding
  have fixed : Arm64ProgramEntryAllocation.localName Arm64Entry.___a64_vectors = Arm64Entry.___a64_vectors := by
    decide +kernel
  rw [fixed] at actual
  exact actual

/-- One actual vector input, with the shared layout-relative execution and store. -/
theorem input_returns (i : Fin 64) (initial before supplied : CC.Mem) (localVector : VectorLocal initial)
    (le : CC.TempEnv) (k : CC.Cont) (value : BitVec 64) (trace : CC.Trace)
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
      [.Vint (6#32)] before trace (.Vlong value) supplied)
    (access : supplied.access = (Arm64Producer.allocation initial).2.access) :
    ∃ after, CC.Star (CC.Step2 world)
      (.State Arm64ProgramFixture.f_arm64_execute_compile (inputStage i) k (allocation initial).1 le before)
      trace (.State Arm64ProgramFixture.f_arm64_execute_compile (declaration i).rest k (allocation initial).1
        (le.set (inputTemp i) (.Vlong value)) after) ∧
      CC.Mem.load .Mint64 after localVector.block (8 * (i.val : Int)) = some (.Vlong value) ∧
      (∀ j : Fin 64, j ≠ i → CC.Mem.load .Mint64 after localVector.block (8 * (j.val : Int)) =
        CC.Mem.load .Mint64 supplied localVector.block (8 * (j.val : Int))) ∧
      (∀ id ty block, (Arm64Producer.allocation initial).1.get id = some (block, ty) →
        id ≠ Arm64Entry.___a64_vectors → ∀ chunk ofs,
        CC.Mem.load chunk after block ofs = CC.Mem.load chunk supplied block ofs) ∧
      FrameBelow initial.nextblock supplied after ∧ after.access = supplied.access ∧
      after.nextblock = supplied.nextblock := by
  rw [source]
  exact Arm64Producer.vector_input_returns_body world Arm64ProgramFixture.f_arm64_execute_compile
    (allocation initial).1 Arm64ProgramEntryCall.inputBlock Arm64ProgramEntryCall.input_binding
    (Arm64ProgramEntryCall.input_unshadowed initial) tag (inputTemp i) i (declaration i).rest
    initial before supplied localVector layout (binding initial localVector) le k value trace provider access

/-- All 64 actual visits retain ordered traces, earlier lanes and caller resources. -/
theorem initialized (initial before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (values : Fin 64 → BitVec 64) (provider : Arm64ProducerVectorInputs.ProviderAt world initial values)
    (access : before.access = (allocation initial).2.access) :
    ∃ localVector : VectorLocal initial, ∃ after finalLe, ∃ traces : List CC.Trace,
      traces.length = 64 ∧
      (allocation initial).1.get Arm64Entry.___a64_vectors = some (localVector.block, arrayType) ∧
      CC.Star (CC.Step2 world)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryFlags.vectorStart
          k (allocation initial).1 le before)
        traces.flatten (.State Arm64ProgramFixture.f_arm64_execute_compile afterVectorInputs
          k (allocation initial).1 finalLe after) ∧
      (∀ i, CC.Mem.load .Mint64 after localVector.block (8 * (i.val : Int)) = some (.Vlong (values i))) ∧
      (∀ id ty block, (Arm64Producer.allocation initial).1.get id = some (block, ty) →
        id ≠ Arm64Entry.___a64_vectors → ∀ chunk ofs,
        CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      (∀ id, (∀ i, id ≠ inputTemp i) → finalLe.get id = le.get id) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨localVector⟩ := Arm64Producer.vector_local initial
  have canonical : before.access = (Arm64Producer.allocation initial).2.access :=
    access.trans (congrArg CC.Mem.access (Arm64ProgramEntryAllocation.allocation_corresponds initial).1.symm)
  obtain ⟨after, finalLe, traces, length, run, reads, _, locals, temps, frame, finalAccess, next⟩ :=
    Arm64ProducerVectorInputs.run_suffix_body world Arm64ProgramFixture.f_arm64_execute_compile
      (allocation initial).1 stage inputTemp initial localVector values provider
      (fun i before supplied le k trace call access => by
        obtain ⟨after, run, reads, lanes, locals, frame, finalAccess, next⟩ :=
          input_returns i initial before supplied localVector le k (values i) trace call access
        rw [chain i] at run
        refine ⟨localVector, after, ?_, reads, lanes, locals, frame, finalAccess, next⟩
        simpa only [stage, dite_eq_left i.isLt] using run)
      64 0 rfl before le k canonical
  rw [first_stage, last_stage] at run
  exact ⟨localVector, after, finalLe, traces, length, binding initial localVector, run,
    (fun i => reads i (Nat.zero_le _)), locals, temps, frame, finalAccess, next⟩

/-- The actual anonymous array binding and every derived vector word. -/
def Readbacks (initial memory : CC.Mem) (values : Fin 64 → BitVec 64) : Prop :=
  ∃ localVector : VectorLocal initial,
    (allocation initial).1.get Arm64Entry.___a64_vectors = some (localVector.block, arrayType) ∧
    ∀ i, CC.Mem.load .Mint64 memory localVector.block (8 * (i.val : Int)) = some (.Vlong (values i))

private theorem cells_separate : ∀ selected (i : Fin 31),
    tableCellName selected i ≠ Arm64Entry.___a64_vectors := by decide +kernel

private theorem tables_separate : ∀ selected,
    tableName selected ≠ Arm64Entry.___a64_vectors := by decide +kernel

private theorem flags_separate : ∀ i : Fin 4,
    (Arm64ProgramEntryFlags.declaration i).name ≠ Arm64Entry.___a64_vectors := by
  have different : ∀ i : Fin 4, (Arm64Producer.flagDeclaration i).name ≠ Arm64Entry.___a64_vectors := by
    decide +kernel
  intro i
  rw [(Arm64ProgramEntryFlags.metadata i).1]
  exact different i

private theorem caches_separate : ∀ returns,
    Arm64Producer.baseName returns ≠ Arm64Entry.___a64_vectors ∧
    Arm64Producer.validName returns ≠ Arm64Entry.___a64_vectors := by decide +kernel

/-- Actual entry through all98 provider visits, with every prior observation
framed by the same reached memory and actual production environment. -/
theorem entry_initialized (initial : CC.Mem) (ctx : CC.Val) (k : CC.Cont)
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
        traces.flatten (.State Arm64ProgramFixture.f_arm64_execute_compile afterVectorInputs
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
      Arm64ProgramEntryFlags.Readbacks initial after flags ∧
      Readbacks initial after vectors ∧
      Arm64ProgramEntryInputs.CacheReadbacks initial after ∧ le.get Arm64ProgramFixture._ctx = some ctx ∧
      FrameBelow initial.nextblock initial after ∧ after.access = (allocation initial).2.access ∧
      after.nextblock = (allocation initial).2.nextblock := by
  obtain ⟨blocks, before, le, priorTraces, priorLength, bindings, actualBindings,
      priorRun, registers, tables, flagReadbacks, caches, context, frame, access, next⟩ :=
    Arm64ProgramEntryFlags.entry_initialized initial ctx k values provider flags flagProvider
  obtain ⟨localVector, after, finalLe, vectorTraces, vectorLength, vectorBinding,
      vectorRun, vectorReads, other, temps, vectorFrame, vectorAccess, vectorNext⟩ :=
    initialized initial before le k vectors vectorProvider access
  refine ⟨blocks, after, finalLe, priorTraces ++ vectorTraces, ?_, bindings, actualBindings,
    ?_, ?_, ?_, ?_, ⟨localVector, vectorBinding, vectorReads⟩, ?_, ?_,
    frame.trans vectorFrame, vectorAccess.trans access, vectorNext.trans next⟩
  · simp only [List.length_append, priorLength, vectorLength]
  · simpa only [List.flatten_append, CC.Eapp] using star_trans priorRun vectorRun
  · intro i
    exact ⟨(other _ _ _ (bindings false i) (cells_separate false i) .Mint64 0).trans (registers i).1,
      (other _ _ _ (bindings true i) (cells_separate true i) .Mint8unsigned 0).trans (registers i).2⟩
  · intro selected
    obtain ⟨locals, bound, cells, reads⟩ := tables selected
    refine ⟨locals, bound, cells, ?_⟩
    intro i
    exact (other _ _ _ locals.binding (tables_separate selected) CC.Mptr (8 * (i.val : Int))).trans (reads i)
  · obtain ⟨flagBlocks, lrBlock, flagBindings, actualFlagBindings, lrBinding, actualLrBinding,
        flagsRead, lrRead⟩ := flagReadbacks
    refine ⟨flagBlocks, lrBlock, flagBindings, actualFlagBindings, lrBinding, actualLrBinding, ?_, ?_⟩
    · intro i
      exact (other _ _ _ (flagBindings i) (flags_separate i) .Mint8unsigned 0).trans (flagsRead i)
    · exact (other _ _ _ lrBinding (by decide +kernel) .Mint64 0).trans lrRead
  · intro returns
    obtain ⟨locals, baseBound, validBound, base, valid⟩ := caches returns
    refine ⟨locals, baseBound, validBound, ?_, ?_⟩
    · exact (other _ _ _ locals.baseBinding (caches_separate returns).1 .Mint64 0).trans base
    · exact (other _ _ _ locals.validBinding (caches_separate returns).2 .Mint8unsigned 0).trans valid
  · exact (temps _ (fun i => Ne.symm (metadata i).2.2)).trans context

end KProgFormal.ClightRefinement.Arm64ProgramEntryVectorInputs
