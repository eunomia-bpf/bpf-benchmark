import KProgFormal.ClightRefinement.Arm64ProgramEntryCall
import KProgFormal.ClightRefinement.Arm64ProducerPrefix

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryPrefix

open Arm64ProgramEntryAllocation (world allocation)
open Arm64ProgramEntryCall (initialTemps)

/-- The actual successor after the first 189 production assignments. -/
def cacheStage : CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm
      (← `(Arm64ProgramFixture.f_arm64_execute_compile.fn_body)) none
    for _ in [:189] do
      body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "production ABI prefix ended early"
      body := body.getAppArgs[1]!
    body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
    Lean.Elab.Tactic.closeMainGoal `actual_cache_stage body

/-- The statements are compared with the emitted production body, not a
mapped source tail. The successor is extracted from that same actual body. -/
theorem prefix_source : Arm64ProgramFixture.f_arm64_execute_compile.fn_body =
    Arm64Producer.cachePrefix.foldr CC.Stmt.Ssequence cacheStage := by rfl

theorem abi_layout : Arm64Producer.AbiLayout world := by
  unfold Arm64Producer.AbiLayout
  decide +kernel

private theorem prefix_local (initial : CC.Mem) (id : CC.Ident) (ty : CC.Ty)
    (present : (id, ty) ∈ Arm64Producer.producer.fn_vars)
    (name : Arm64ProgramEntryAllocation.localName id = id)
    (type : Arm64ProgramEntryAllocation.localType ty = ty) :
    Nonempty (Arm64Producer.PrefixLocal (fun m => (allocation m).1) initial id ty) := by
  obtain ⟨block, bound, fresh, _, range⟩ := Arm64Producer.local_storage initial id ty present
  have actual := Arm64ProgramEntryAllocation.local_binding initial id block ty bound
  rw [name, type] at actual
  exact ⟨⟨block, actual, fresh, range⟩⟩

/-- Execute all initial production assignments with the real allocation and
unchanged production temporaries. Caller framing follows actual call entry. -/
theorem prefix_internal (initial : CC.Mem) (ctx : CC.Val) (k : CC.Cont) :
    ∃ before, InternalRun world 568
      (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [ctx] k initial)
      (.State Arm64ProgramFixture.f_arm64_execute_compile cacheStage k
        (allocation initial).1 (initialTemps ctx) before) ∧
      before.access = (allocation initial).2.access ∧
      before.nextblock = (allocation initial).2.nextblock ∧
      FrameBelow initial.nextblock initial before := by
  obtain ⟨abi⟩ := prefix_local initial Arm64Entry.___a64_sim_abi
    (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr)
    (by decide +kernel) (by decide +kernel) (by rfl)
  obtain ⟨ctxLocal⟩ := prefix_local initial Arm64Entry.___a64_sim_skb_ctx
    (CC.tptr (.Tstruct Arm64Entry.___sk_buff CC.noattr))
    (by decide +kernel) (by decide +kernel) (by rfl)
  obtain ⟨kind⟩ := prefix_local initial Arm64Entry.___a64_sim_abi_kind CC.tuchar
    (by decide +kernel) (by decide +kernel) (by rfl)
  obtain ⟨before, run, access, next, frame⟩ := Arm64Producer.prefix_body_bound
    world Arm64ProgramFixture.f_arm64_execute_compile (fun m => (allocation m).1)
    abi_layout initial abi ctxLocal kind cacheStage (initialTemps ctx) k
  have allocated := (Arm64ProgramEntryAllocation.allocation_corresponds initial).1
  have prefixRun : InternalRun world 567
      (.State Arm64ProgramFixture.f_arm64_execute_compile
        Arm64ProgramFixture.f_arm64_execute_compile.fn_body k (allocation initial).1
        (initialTemps ctx) (allocation initial).2)
      (.State Arm64ProgramFixture.f_arm64_execute_compile cacheStage k
        (allocation initial).1 (initialTemps ctx) before) := by
    rw [prefix_source]
    simpa only [allocated] using run
  refine ⟨before, (Arm64ProgramEntryCall.entry_internal initial ctx k).trans prefixRun,
    access.trans (congrArg CC.Mem.access allocated), next.trans (congrArg CC.Mem.nextblock allocated), ?_⟩
  have actualFrame : FrameBelow initial.nextblock (allocation initial).2 before := by
    simpa only [allocated] using frame
  exact (Arm64ProgramEntryCall.entry_frame initial).trans actualFrame

/-- The real production successor of the four cache assignments. -/
def afterCacheStage : CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(cacheStage)) none
    for _ in [:4] do
      body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "production cache prefix ended early"
      body := body.getAppArgs[1]!
    body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
    Lean.Elab.Tactic.closeMainGoal `actual_after_cache_stage body

theorem cache_source : cacheStage =
    Arm64Producer.cacheAssignments.foldr CC.Stmt.Ssequence afterCacheStage := by rfl

private theorem cache_bindings (initial : CC.Mem) (returns : Bool) :
    (allocation initial).1.get (Arm64Producer.baseName returns) =
      (Arm64Producer.allocation initial).1.get (Arm64Producer.baseName returns) ∧
    (allocation initial).1.get (Arm64Producer.validName returns) =
      (Arm64Producer.allocation initial).1.get (Arm64Producer.validName returns) := by
  obtain ⟨locals⟩ := Arm64Producer.cache_locals returns initial
  have base := Arm64ProgramEntryAllocation.local_binding initial _ _ _ locals.baseBinding
  have valid := Arm64ProgramEntryAllocation.local_binding initial _ _ _ locals.validBinding
  have baseName : Arm64ProgramEntryAllocation.localName (Arm64Producer.baseName returns) =
      Arm64Producer.baseName returns := by cases returns <;> decide +kernel
  have validName : Arm64ProgramEntryAllocation.localName (Arm64Producer.validName returns) =
      Arm64Producer.validName returns := by cases returns <;> decide +kernel
  rw [baseName] at base
  rw [validName] at valid
  exact ⟨base.trans locals.baseBinding.symm, valid.trans locals.validBinding.symm⟩

/-- Actual call entry through all 193 assignments. Both cache words and
validity bytes are cold in the actual allocation environment, with its exact
frontier. Store construction and framing are shared with the source proof. -/
theorem entry_caches_initialized (initial : CC.Mem) (ctx : CC.Val) (k : CC.Cont) :
    ∃ after, InternalRun world 580
      (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [ctx] k initial)
      (.State Arm64ProgramFixture.f_arm64_execute_compile afterCacheStage k
        (allocation initial).1 (initialTemps ctx) after) ∧
      (∀ returns, ∃ locals : Arm64Producer.CacheLocals returns initial,
        (allocation initial).1.get (Arm64Producer.baseName returns) = some (locals.baseBlock, CC.tulong) ∧
        (allocation initial).1.get (Arm64Producer.validName returns) = some (locals.validBlock, CC.tuchar) ∧
        CC.Mem.loadv .Mint64 after (.Vptr locals.baseBlock 0) = some (.Vlong 0) ∧
        CC.Mem.loadv .Mint8unsigned after (.Vptr locals.validBlock 0) = some (.Vint 0)) ∧
      FrameBelow initial.nextblock initial after ∧
      after.access = (allocation initial).2.access ∧
      after.nextblock = (allocation initial).2.nextblock := by
  obtain ⟨before, prefixRun, access, next, frame⟩ := prefix_internal initial ctx k
  have allocated := (Arm64ProgramEntryAllocation.allocation_corresponds initial).1
  have sourceAccess : before.access = (Arm64Producer.allocation initial).2.access :=
    access.trans (congrArg CC.Mem.access allocated.symm)
  obtain ⟨after, run, initialized, storedFrame, storedAccess, storedNext⟩ :=
    Arm64Producer.initialize_caches_body world Arm64ProgramFixture.f_arm64_execute_compile
      afterCacheStage initial before (allocation initial).1 k (initialTemps ctx)
      (fun returns => (cache_bindings initial returns).1)
      (fun returns => (cache_bindings initial returns).2) sourceAccess
  have cacheRun : InternalRun world 12
      (.State Arm64ProgramFixture.f_arm64_execute_compile cacheStage k
        (allocation initial).1 (initialTemps ctx) before)
      (.State Arm64ProgramFixture.f_arm64_execute_compile afterCacheStage k
        (allocation initial).1 (initialTemps ctx) after) := by
    rw [cache_source]
    exact run
  refine ⟨after, prefixRun.trans cacheRun, ?_, frame.trans storedFrame,
    storedAccess.trans access, storedNext.trans next⟩
  intro returns
  obtain ⟨locals, base, valid⟩ := initialized returns
  exact ⟨locals, (cache_bindings initial returns).1.trans locals.baseBinding,
    (cache_bindings initial returns).2.trans locals.validBinding, base, valid⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryPrefix
