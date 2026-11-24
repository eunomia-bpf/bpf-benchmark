import KProgFormal.ClightRefinement.Arm64ProgramEntryResultCondition
import KProgFormal.ClightRefinement.Arm64PointerWriteLinked

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryPointerWrites

open Arm64ProgramEntryAllocation (world allocation)

private structure Parts where
  first : CC.Stmt
  afterFirst : CC.Stmt
  beforeSecond : CC.Stmt
  second : CC.Stmt
  afterSecond : CC.Stmt
  third : CC.Stmt
  afterThird : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "original pointer-write sequence changed"
      pure actual.getAppArgs
    let first ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryResultCondition.afterCondition)) none)
    let firstMov ← peel first[1]!
    let secondMov ← peel firstMov[1]!
    let memset ← peel secondMov[1]!
    let second ← peel memset[1]!
    let third ← peel second[1]!
    Lean.Elab.Tactic.closeMainGoal `actual_pointer_write_sites
      (← Lean.Meta.mkAppM ``Parts.mk #[first[0]!,first[1]!,memset[1]!,second[0]!,second[1]!,third[0]!,third[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_pointer_write_site
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def first : CC.Stmt := by run_tac cachePart (← `(parts.first))
def afterFirst : CC.Stmt := by run_tac cachePart (← `(parts.afterFirst))
def beforeSecond : CC.Stmt := by run_tac cachePart (← `(parts.beforeSecond))
private def second : CC.Stmt := by run_tac cachePart (← `(parts.second))
def afterSecond : CC.Stmt := by run_tac cachePart (← `(parts.afterSecond))
private def third : CC.Stmt := by run_tac cachePart (← `(parts.third))
def afterThird : CC.Stmt := by run_tac cachePart (← `(parts.afterThird))

def before (site : Fin 3) : CC.Stmt :=
  if site.val = 0 then Arm64ProgramEntryResultCondition.afterCondition
  else if site.val = 1 then beforeSecond else afterSecond
def call (site : Fin 3) : CC.Stmt :=
  if site.val = 0 then first else if site.val = 1 then second else third
def after (site : Fin 3) : CC.Stmt :=
  if site.val = 0 then afterFirst else if site.val = 1 then afterSecond else afterThird
def destination (site : Fin 3) : Fin 31 := if site.val = 2 then 1 else 0
def distance (site : Fin 3) : Int := if site.val = 1 then 16 else 32
def raw (site : Fin 3) : BitVec 64 := CC.Integers.Int64.repr (-distance site)

private theorem site_cases (site : Fin 3) : site = 0 ∨ site = 1 ∨ site = 2 := by
  obtain ⟨i,bound⟩ := site
  have cases : i = 0 ∨ i = 1 ∨ i = 2 := by omega
  rcases cases with zero|one|two
  · exact .inl (Fin.ext zero)
  · exact .inr (.inl (Fin.ext one))
  · exact .inr (.inr (Fin.ext two))

theorem source (site : Fin 3) : before site = .Ssequence (call site) (after site) := by
  rcases site_cases site with rfl|rfl|rfl <;> rfl

theorem call_source (site : Fin 3) : call site = .Scall none
    (.Evar Arm64ProgramFixture._kprog_arm64_program_write_pointer
      (.Tfunction [CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr),CC.tulong,
        CC.tptr CC.tvoid,CC.tuchar] CC.tvoid CC.cc_default))
    [.Eaddrof (.Evar Arm64ProgramFixture.___a64_entry
       (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr))
       (CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr)),
     .Econst_int (CC.Integers.Int.repr (destination site).val) CC.tuint,
     .Ecast (.Ecast (.Eunop .Oneg (.Econst_int (CC.Integers.Int.repr (distance site)) CC.tint)
       CC.tint) CC.tlong) (CC.tptr CC.tvoid),
     .Econst_int (CC.Integers.Int.repr 4) CC.tuint] := by
  rcases site_cases site with rfl|rfl|rfl <;> rfl

private theorem unshadowed (initial : CC.Mem) :
    (allocation initial).1.get Arm64ProgramFixture._kprog_arm64_program_write_pointer = none := by
  have outside : Arm64ProgramFixture._kprog_arm64_program_write_pointer ∉
      CC.varNames Arm64ProgramFixture.f_arm64_execute_compile.fn_vars := by decide +kernel
  simpa only [CC.emptyEnv,CC.PTree.gempty] using CC.allocVariables_env_other
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation initial)).symm) outside

private theorem eval_cons {e : CC.Env} {le : CC.TempEnv} {m : CC.Mem}
    {a : CC.Expr} {xs : List CC.Expr} {ty : CC.Ty} {tys : List CC.Ty}
    {v converted : CC.Val} {values : List CC.Val}
    (head : CC.doEvalExpr world e le m a = some v)
    (cast : CC.Cop.semCast v (CC.typeof a) ty m = some converted)
    (rest : CC.doEvalExprlist world e le m xs tys = some values) :
    CC.doEvalExprlist world e le m (a :: xs) (ty :: tys) = some (converted :: values) := by
  simp only [CC.doEvalExprlist,head,cast,rest]

/-- Every actual pointer call passes its original negative offset and stack
tag through the genuine C casts, using the original allocated header. -/
theorem call_step {initial : CC.Mem} (entry : Arm64Producer.HeaderLocal initial)
    (site : Fin 3) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    CC.Step2 world
      (.State Arm64ProgramFixture.f_arm64_execute_compile (call site) k (allocation initial).1 le m) CC.E0
      (.Callstate (.Internal Arm64PointerWrite.procedure)
        (Arm64PointerWrite.arguments entry.block (destination site) (raw site) (4#8))
        (.Kcall none Arm64ProgramFixture.f_arm64_execute_compile (allocation initial).1 le k) m) := by
  have header : (allocation initial).1.get Arm64ProgramFixture.___a64_entry =
      some (entry.block,.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr) :=
    Arm64ProgramEntryAllocation.local_binding initial _ _ _ entry.binding
  have binding : CC.Genv.findSymbol world.genv_genv Arm64ProgramFixture._kprog_arm64_program_write_pointer =
      some (CC.Positive.ofNat 67) ∧ CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 67) =
        some (.Internal Arm64PointerWrite.procedure) := by
    constructor <;> run_tac Arm64ProgramEntryLinked.sourceEquality
  rw [call_source]
  apply CC.Step.call
    (tyargs := [CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr),CC.tulong,
      CC.tptr CC.tvoid,CC.tuchar]) (tyres := CC.tvoid) (cconv := CC.cc_default)
    (vf := .Vptr (CC.Positive.ofNat 67) 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr,CC.lvalOfVar,unshadowed initial,binding.1,CC.doDerefLoc,CC.accessMode]
    rfl
  · apply CC.doEvalExprlist_sound
    refine eval_cons (v := .Vptr entry.block 0) ?_ (by rfl) ?_
    · simp only [CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,header]
      rfl
    rcases site_cases site with rfl|rfl|rfl <;> rfl
  · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero] using binding.2
  · rfl

/-- The complete source helper retains both actual payload/tag stores and
returns to the true original caller. Storage supplies its write rights. -/
theorem invoke {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry) (site : Fin 3)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      m.nextblock m (.Vptr entry.block 0) s) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ written, Arm64PointerWrite.Result storage (destination site) (raw site) (4#8) written ∧
      InternalRun world 55
        (.State Arm64ProgramFixture.f_arm64_execute_compile (call site) k (allocation initial).1 le m)
        (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 le written) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) m.nextblock written (.Vptr entry.block 0)
        (Arm64PointerWrite.nativeUpdate origins s (destination site) (raw site) (4#8)) ∧
      Arm64CacheLocalFrame.Kept initial m written (destination site) := by
  let cont := CC.Cont.Kcall none Arm64ProgramFixture.f_arm64_execute_compile (allocation initial).1 le k
  have enter : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile (call site) k (allocation initial).1 le m)
      (.Callstate (.Internal Arm64PointerWrite.procedure)
        (Arm64PointerWrite.arguments entry.block (destination site) (raw site) (4#8)) cont m) :=
    .step (by rw [call_source]; trivial) (call_step entry site le m k) (.refl _)
  obtain ⟨written,effect,write,registers,kept⟩ := Arm64PointerWrite.Linked.write storage (destination site)
    (raw site) (4#8) addresses origins s represented cont rfl
  have leave : InternalRun world 1 (.Returnstate .Vundef cont written)
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 le written) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  exact ⟨written,effect,(enter.trans write).trans leave,registers,kept⟩

/-- A site reaches its actual next source statement, including both sequence
transitions. The intervening MOV/memory calls remain in those continuations. -/
theorem execute {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry) (site : Fin 3)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      m.nextblock m (.Vptr entry.block 0) s) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ written, Arm64PointerWrite.Result storage (destination site) (raw site) (4#8) written ∧
      InternalRun world 57
        (.State Arm64ProgramFixture.f_arm64_execute_compile (before site) k (allocation initial).1 le m)
        (.State Arm64ProgramFixture.f_arm64_execute_compile (after site) k (allocation initial).1 le written) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) m.nextblock written (.Vptr entry.block 0)
        (Arm64PointerWrite.nativeUpdate origins s (destination site) (raw site) (4#8)) ∧
      Arm64CacheLocalFrame.Kept initial m written (destination site) := by
  obtain ⟨written,effect,run,registers,kept⟩ := invoke storage site addresses origins s represented le (.Kseq (after site) k)
  have enter : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile (before site) k (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile (call site) (.Kseq (after site) k)
        (allocation initial).1 le m) := by
    rw [source]
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  have leave : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip (.Kseq (after site) k) (allocation initial).1 le written)
      (.State Arm64ProgramFixture.f_arm64_execute_compile (after site) k (allocation initial).1 le written) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  exact ⟨written,effect,(enter.trans run).trans leave,registers,kept⟩

/-- Stack-tagged raw offsets materialize through the existing provenance
binding; the original helper introduces no extra architectural step. -/
theorem native_gpr (site : Fin 3) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State) (j : Fin 31) :
    Reference.AArch64.gpr (Arm64PointerWrite.nativeUpdate origins s (destination site) (raw site) (4#8)) j =
      if j = destination site then raw site + origins.stack else Reference.AArch64.gpr s j := by
  simpa +decide only [Reference.Provenance.AArch64.materialize,ite_true] using
    Arm64PointerWrite.native_gpr origins s (destination site) (raw site) (4#8) j

end KProgFormal.ClightRefinement.Arm64ProgramEntryPointerWrites
