import KProgFormal.ClightRefinement.Arm64ProgramEntryPointerWrites
import KProgFormal.ClightRefinement.Arm64MovImmediateOrdinaryFrame

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryOrdinaryMoves

open Arm64ProgramEntryAllocation (world allocation)
open Arm64MovImmediate

private structure Parts where
  mark : CC.Stmt
  first : CC.Stmt
  afterFirst : CC.Stmt
  second : CC.Stmt
  afterSecond : CC.Stmt
  third : CC.Stmt
  afterThird : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "original ordinary MOV sequence changed"
      pure actual.getAppArgs
    let outer ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryPointerWrites.afterFirst)) none)
    let first ← peel outer[0]!
    let second ← peel outer[1]!
    let third ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryPointerWrites.afterThird)) none)
    Lean.Elab.Tactic.closeMainGoal `actual_ordinary_mov_sites
      (← Lean.Meta.mkAppM ``Parts.mk #[first[0]!,first[1]!,outer[1]!,second[0]!,second[1]!,third[0]!,third[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_ordinary_mov_site
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def markSet : CC.Stmt := by run_tac cachePart (← `(parts.mark))
private def first : CC.Stmt := by run_tac cachePart (← `(parts.first))
def afterFirst : CC.Stmt := by run_tac cachePart (← `(parts.afterFirst))
private def second : CC.Stmt := by run_tac cachePart (← `(parts.second))
def afterSecond : CC.Stmt := by run_tac cachePart (← `(parts.afterSecond))
private def third : CC.Stmt := by run_tac cachePart (← `(parts.third))
def afterThird : CC.Stmt := by run_tac cachePart (← `(parts.afterThird))

def call (site : Fin 3) : CC.Stmt :=
  if site.val = 0 then first else if site.val = 1 then second else third
def destination (site : Fin 3) : Fin 31 := if site.val = 0 then 1 else 2
def value (site : Fin 3) (mark : BitVec 32) : BitVec 64 := if site.val = 0 then mark.setWidth 64 else 16#64
def after (site : Fin 3) : CC.Stmt :=
  if site.val = 0 then afterFirst else if site.val = 1 then afterSecond else afterThird
def markTemps (le : CC.TempEnv) (mark : BitVec 32) : CC.TempEnv :=
  le.set Arm64ProgramFixture._t'163 (.Vint mark)

private theorem site_cases (site : Fin 3) : site = 0 ∨ site = 1 ∨ site = 2 := by
  obtain ⟨i,bound⟩ := site
  have cases : i = 0 ∨ i = 1 ∨ i = 2 := by omega
  rcases cases with zero|one|two
  · exact .inl (Fin.ext zero)
  · exact .inr (.inl (Fin.ext one))
  · exact .inr (.inr (Fin.ext two))

theorem first_source : Arm64ProgramEntryPointerWrites.afterFirst =
    .Ssequence (.Ssequence markSet (call 0)) afterFirst := rfl
theorem second_source : afterFirst = .Ssequence (call 1) afterSecond := rfl
theorem third_source : Arm64ProgramEntryPointerWrites.afterThird = .Ssequence (call 2) afterThird := rfl

private def parameterTypes : List CC.Ty :=
  [CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr),CC.tuint,CC.tulong,
    CC.tulong,CC.tulong,CC.tulong,CC.tuchar,CC.tuint,CC.tulong]
private def target : CC.Expr := .Evar Arm64ProgramFixture._kprog_arm64_program_execute
  (.Tfunction parameterTypes CC.tvoid CC.cc_default)
private def actualArgs (site : Fin 3) : List CC.Expr :=
  [.Eaddrof (.Evar Arm64ProgramFixture.___a64_entry
     (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr))
     (CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr)),
   .Econst_int (CC.Integers.Int.repr 1) CC.tuint,
   .Econst_int (CC.Integers.Int.repr (destination site).val) CC.tint,
   .Econst_int (CC.Integers.Int.repr 255) CC.tint,
   .Econst_int (CC.Integers.Int.repr 255) CC.tuint,
   .Econst_int (CC.Integers.Int.repr 255) CC.tuint,
   .Econst_int (CC.Integers.Int.repr 8) CC.tint,
   .Econst_int (CC.Integers.Int.repr 0) CC.tint,
   if site.val = 0 then .Etempvar Arm64ProgramFixture._t'163 CC.tuint
   else .Econst_int (CC.Integers.Int.repr 16) CC.tint]

theorem call_source (site : Fin 3) : call site = .Scall none target (actualArgs site) := by
  rcases site_cases site with rfl|rfl|rfl <;> rfl

private theorem unshadowed (initial : CC.Mem) :
    (allocation initial).1.get Arm64ProgramFixture._kprog_arm64_program_execute = none := by
  have outside : Arm64ProgramFixture._kprog_arm64_program_execute ∉
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

private theorem args_eval {initial : CC.Mem} (entry : Arm64Producer.HeaderLocal initial)
    (site : Fin 3) (le : CC.TempEnv) (m : CC.Mem) (mark : BitVec 32)
    (read : site = 0 → le.get Arm64ProgramFixture._t'163 = some (.Vint mark)) :
    CC.doEvalExprlist world (allocation initial).1 le m (actualArgs site) parameterTypes =
      some (Arm64MovImmediate.Dispatch.arguments (OrdinaryCall.operands entry.block (destination site) (value site mark)) false) := by
  have header : (allocation initial).1.get Arm64ProgramFixture.___a64_entry =
      some (entry.block,.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr) :=
    Arm64ProgramEntryAllocation.local_binding initial _ _ _ entry.binding
  unfold actualArgs parameterTypes
  rcases site_cases site with rfl|rfl|rfl
  all_goals
    refine eval_cons (v := .Vptr entry.block 0) ?_ (by rfl) ?_
    · simp only [CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,header]
      rfl
    refine eval_cons (by rfl) (by rfl) ?_
    refine eval_cons (by rfl) (by rfl) ?_
    refine eval_cons (by rfl) (by rfl) ?_
    refine eval_cons (by rfl) (by rfl) ?_
    refine eval_cons (by rfl) (by rfl) ?_
    refine eval_cons (by rfl) (by rfl) ?_
    refine eval_cons (by rfl) (by rfl) ?_
  · refine eval_cons (v := .Vint mark) ?_ ?_ (by rfl)
    · exact read rfl
    · simp only [value,CC.typeof,CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntLong,
        CC.Integers.Int64.repr,CC.Integers.MI.repr,CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,
        BitVec.ofInt_natCast,BitVec.ofNat_toNat]
      rfl
  · exact eval_cons (by rfl) (by rfl) (by rfl)
  · exact eval_cons (by rfl) (by rfl) (by rfl)

theorem call_step {initial : CC.Mem} (entry : Arm64Producer.HeaderLocal initial)
    (site : Fin 3) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (mark : BitVec 32)
    (read : site = 0 → le.get Arm64ProgramFixture._t'163 = some (.Vint mark)) :
    CC.Step2 world
      (.State Arm64ProgramFixture.f_arm64_execute_compile (call site) k (allocation initial).1 le m) CC.E0
      (.Callstate (.Internal Arm64Nop.handler)
        (Arm64MovImmediate.Dispatch.arguments (OrdinaryCall.operands entry.block (destination site) (value site mark)) false)
        (.Kcall none Arm64ProgramFixture.f_arm64_execute_compile (allocation initial).1 le k) m) := by
  have symbol : CC.Genv.findSymbol world.genv_genv Arm64ProgramFixture._kprog_arm64_program_execute =
      some Arm64ProgramEntryLinked.executeBlock := Arm64ProgramEntryLinked.execute_binding.1
  have function : CC.Genv.findFunctPtr world.genv_genv Arm64ProgramEntryLinked.executeBlock =
      some (.Internal Arm64Nop.handler) := Arm64ProgramEntryLinked.execute_binding.2
  rw [call_source]
  apply CC.Step.call (tyargs := parameterTypes) (tyres := CC.tvoid) (cconv := CC.cc_default)
    (vf := .Vptr Arm64ProgramEntryLinked.executeBlock 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [target,CC.doEvalExpr,CC.lvalOfVar,unshadowed initial,symbol,CC.doDerefLoc,CC.accessMode]
    rfl
  · apply CC.doEvalExprlist_sound
    exact args_eval entry site le m mark read
  · have zero : CC.Integers.Ptrofs.eq (0 : CC.Integers.Ptrofs) CC.Integers.Ptrofs.zero = true := rfl
    simp only [CC.Genv.findFunct,zero,ite_true,function]
  · rfl

/-- Complete genuine call-site entry, generic C execution and original return.
The same Result retains both writes, all registers, caches and final frame free. -/
theorem invoke {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ m.nextblock.toNat)
    (site : Fin 3) (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val) m.nextblock m (.Vptr entry.block 0) s)
    (le : CC.TempEnv) (k : CC.Cont) (mark : BitVec 32)
    (read : site = 0 → le.get Arm64ProgramFixture._t'163 = some (.Vint mark)) :
    ∃ written after, OrdinaryCall.Result storage (destination site) (value site mark) addresses origins s
        (.Kcall none Arm64ProgramFixture.f_arm64_execute_compile (allocation initial).1 le k) written after ∧
      InternalRun world 205
        (.State Arm64ProgramFixture.f_arm64_execute_compile (call site) k (allocation initial).1 le m)
        (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 le after) := by
  let cont := CC.Cont.Kcall none Arm64ProgramFixture.f_arm64_execute_compile (allocation initial).1 le k
  have enter : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile (call site) k (allocation initial).1 le m)
      (.Callstate (.Internal Arm64Nop.handler)
        (Arm64MovImmediate.Dispatch.arguments (OrdinaryCall.operands entry.block (destination site) (value site mark)) false) cont m) :=
    .step (by rw [call_source]; trivial) (call_step entry site le m k mark read) (.refl _)
  obtain ⟨written,after,result⟩ := OrdinaryCall.corresponds storage bound (destination site) (value site mark)
    addresses origins s represented cont rfl
  have leave : InternalRun world 1 (.Returnstate .Vundef cont after)
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 le after) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  exact ⟨written,after,result,(enter.trans result.run).trans leave⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryOrdinaryMoves
