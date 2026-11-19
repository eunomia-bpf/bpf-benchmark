import KProgFormal.ClightRefinement.Arm64ProgramEntryPrefix
import KProgFormal.ClightRefinement.Arm64ProducerRegisters

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryInputs

open Arm64ProgramEntryAllocation (world allocation)
open Arm64ProgramEntryCall (initialTemps)

private def stages : CC.Stmt × CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryPrefix.afterCacheStage)) none
    for _ in [:3] do
      body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "production setup ended early"
      body := body.getAppArgs[1]!
    let stage := body
    let outer ← Lean.Meta.withTransparency .all (Lean.Meta.whnf stage)
    unless outer.isAppOfArity ``CC.Stmt.Ssequence 2 do
      throwError "production first register declaration changed"
    let tag ← Lean.Meta.withTransparency .all (Lean.Meta.whnf outer.getAppArgs[1]!)
    unless tag.isAppOfArity ``CC.Stmt.Ssequence 2 do
      throwError "production first register tag changed"
    Lean.Elab.Tactic.closeMainGoal `production_input_stages
      (← Lean.Meta.mkAppM ``Prod.mk #[stage, tag.getAppArgs[1]!])

def registerStage : CC.Stmt := stages.1
def nextRegisterStage : CC.Stmt := stages.2

/-- Compare the three assignments and their successor with the actual body. -/
theorem setup_source : Arm64ProgramEntryPrefix.afterCacheStage =
    Arm64Producer.setupAssignments.foldr CC.Stmt.Ssequence registerStage := by rfl

private theorem unchanged_binding (initial : CC.Mem) (id : CC.Ident) (ty : CC.Ty)
    (present : (id, ty) ∈ Arm64Producer.producer.fn_vars)
    (name : Arm64ProgramEntryAllocation.localName id = id)
    (type : Arm64ProgramEntryAllocation.localType ty = ty) :
    (allocation initial).1.get id = (Arm64Producer.allocation initial).1.get id := by
  obtain ⟨block, bound, _, _, _⟩ := Arm64Producer.local_storage initial id ty present
  have actual := Arm64ProgramEntryAllocation.local_binding initial id block ty bound
  rw [name, type] at actual
  exact actual.trans bound.symm

private theorem setup_bindings (initial : CC.Mem) : ∀ id ∈ Arm64Producer.setupNames,
    (allocation initial).1.get id = (Arm64Producer.allocation initial).1.get id := by
  intro id member
  simp only [Arm64Producer.setupNames, List.mem_cons, List.not_mem_nil, or_false] at member
  rcases member with rfl | rfl | rfl
  · exact unchanged_binding initial _ CC.tuchar (by decide +kernel) (by decide +kernel) rfl
  · exact unchanged_binding initial _ (CC.tptr CC.tvoid) (by decide +kernel) (by decide +kernel) rfl
  · exact unchanged_binding initial _ (CC.tptr CC.tvoid) (by decide +kernel) (by decide +kernel) rfl

/-- Reuse the source three-store memory witness with actual local bindings.
Every other source-corresponding local retains all its loads. -/
theorem setup_internal (initial before : CC.Mem) (temps : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation initial).2.access) :
    ∃ after, InternalRun world 9
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryPrefix.afterCacheStage
        k (allocation initial).1 temps before)
      (.State Arm64ProgramFixture.f_arm64_execute_compile registerStage k
        (allocation initial).1 temps after) ∧
      (∀ id ty block, (Arm64Producer.allocation initial).1.get id = some (block, ty) →
        id ∉ Arm64Producer.setupNames → ∀ chunk ofs,
        CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  rw [setup_source]
  apply Arm64Producer.setup_register_input_body world Arm64ProgramFixture.f_arm64_execute_compile
    (allocation initial).1 registerStage initial before temps k (setup_bindings initial)
  exact access.trans (congrArg CC.Mem.access
    (Arm64ProgramEntryAllocation.allocation_corresponds initial).1.symm)

/-- Both real local bindings and their initialized cache contents. -/
def CacheReadbacks (initial memory : CC.Mem) : Prop :=
  ∀ returns, ∃ locals : Arm64Producer.CacheLocals returns initial,
    (allocation initial).1.get (Arm64Producer.baseName returns) = some (locals.baseBlock, CC.tulong) ∧
    (allocation initial).1.get (Arm64Producer.validName returns) = some (locals.validBlock, CC.tuchar) ∧
    CC.Mem.loadv .Mint64 memory (.Vptr locals.baseBlock 0) = some (.Vlong 0) ∧
    CC.Mem.loadv .Mint8unsigned memory (.Vptr locals.validBlock 0) = some (.Vint 0)

/-- Actual call through setup, with caches preserved across its three stores. -/
theorem entry_setup (initial : CC.Mem) (ctx : CC.Val) (k : CC.Cont) :
    ∃ after, InternalRun world 589
      (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [ctx] k initial)
      (.State Arm64ProgramFixture.f_arm64_execute_compile registerStage k
        (allocation initial).1 (initialTemps ctx) after) ∧
      CacheReadbacks initial after ∧ FrameBelow initial.nextblock initial after ∧
      after.access = (allocation initial).2.access ∧
      after.nextblock = (allocation initial).2.nextblock := by
  obtain ⟨before, prefixRun, caches, frame, access, next⟩ :=
    Arm64ProgramEntryPrefix.entry_caches_initialized initial ctx k
  obtain ⟨after, setupRun, other, setupFrame, setupAccess, setupNext⟩ :=
    setup_internal initial before (initialTemps ctx) k access
  refine ⟨after, prefixRun.trans setupRun, ?_, frame.trans setupFrame,
    setupAccess.trans access, setupNext.trans next⟩
  intro returns
  obtain ⟨locals, baseBound, validBound, base, valid⟩ := caches returns
  refine ⟨locals, baseBound, validBound, ?_, ?_⟩
  · have preserved := other _ _ _ locals.baseBinding
      (by cases returns <;> decide +kernel) .Mint64 0
    exact preserved.trans base
  · have preserved := other _ _ _ locals.validBinding
      (by cases returns <;> decide +kernel) .Mint8unsigned 0
    exact preserved.trans valid

/-- The first production declaration uses its mapped temporaries and actual
successor. Its complete statement equality is checked below. -/
def firstDeclaration : Arm64Producer.RegisterDeclaration :=
  let source := Arm64Producer.registerDeclaration 0
  { source with
    inputTemp := Arm64ProgramEntrySource.temporaryName source.inputTemp
    resultTemp := Arm64ProgramEntrySource.temporaryName source.resultTemp
    rest := nextRegisterStage }

theorem first_declaration_source : registerStage = firstDeclaration.body := by
  run_tac do
    let rhs ← Lean.Elab.Term.elabTerm (← `(firstDeclaration.body)) none
    Lean.Elab.Tactic.closeMainGoal `production_first_declaration (← Lean.Meta.mkEqRefl rhs)

def inputContinuation (initial : CC.Mem) (temps : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some firstDeclaration.inputTemp) Arm64ProgramFixture.f_arm64_execute_compile
    (allocation initial).1 temps (.Kseq firstDeclaration.setValue
      (.Kseq firstDeclaration.storeValue
        (.Kseq (.Ssequence firstDeclaration.storeTag firstDeclaration.rest) k)))

/-- The real callee is block59, resolved through the actual global table.
No external transition or returned input word is assumed. -/
theorem first_call_ready (initial memory : CC.Mem) (temps : CC.TempEnv) (k : CC.Cont) :
    InternalRun world 5
      (.State Arm64ProgramFixture.f_arm64_execute_compile registerStage k
        (allocation initial).1 temps memory)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)]
        (inputContinuation initial temps k) memory) := by
  rw [first_declaration_source]
  have run := Arm64Producer.declaration_call_body world Arm64ProgramFixture.f_arm64_execute_compile
    (allocation initial).1 Arm64ProgramEntryCall.inputBlock Arm64ProgramEntryCall.input_binding
    firstDeclaration memory temps k (Arm64ProgramEntryCall.input_unshadowed initial)
    (by decide +kernel)
  exact internalRun_of_steps run.2 run.1

/-- Actual entry reaches its first kind-6 provider boundary in594 internal
transitions, retaining the context environment, cache contents and caller frame. -/
theorem first_input_ready (initial : CC.Mem) (ctx : CC.Val) (k : CC.Cont) :
    ∃ before, InternalRun world 594
      (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [ctx] k initial)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)]
        (inputContinuation initial (initialTemps ctx) k) before) ∧
      CacheReadbacks initial before ∧ FrameBelow initial.nextblock initial before ∧
      before.access = (allocation initial).2.access ∧
      before.nextblock = (allocation initial).2.nextblock := by
  obtain ⟨before, run, caches, frame, access, next⟩ := entry_setup initial ctx k
  exact ⟨before, run.trans (first_call_ready initial before (initialTemps ctx) k),
    caches, frame, access, next⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryInputs
