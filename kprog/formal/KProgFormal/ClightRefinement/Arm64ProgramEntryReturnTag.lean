import KProgFormal.ClightRefinement.Arm64ProgramEntryReturnGuard

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryReturnTag
open Arm64Producer (HeaderLocal)
open Arm64ProgramEntryAllocation (world allocation)

private def cachePart (source : Lean.Syntax) (index : Nat) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
  unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original RET_TO tag source changed"
  Lean.Elab.Tactic.closeMainGoal `actual_return_tag_part actual.getAppArgs[index]!
def readCall : CC.Stmt := by run_tac cachePart (← `(Arm64ProgramEntryReturnGuard.perform)) 0
def choice : CC.Stmt := by run_tac cachePart (← `(Arm64ProgramEntryReturnGuard.perform)) 1
theorem source : Arm64ProgramEntryReturnGuard.perform = .Ssequence readCall choice := rfl

def temps (le : CC.TempEnv) : CC.TempEnv := le.set Arm64ProgramFixture._t'150 (.Vint (9#32))

theorem call_source : readCall = .Scall (some Arm64ProgramFixture._t'150)
    (.Evar Arm64ProgramFixture._kprog_arm64_program_tag
      (.Tfunction [CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr),CC.tulong]
        CC.tuint CC.cc_default))
    [.Eaddrof (.Evar Arm64ProgramFixture.___a64_entry (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr))
       (CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr)),
     .Econst_int (30#32) CC.tuint] := rfl

private theorem unshadowed (initial : CC.Mem) :
    (allocation initial).1.get Arm64ProgramFixture._kprog_arm64_program_tag = none := by
  have outside : Arm64ProgramFixture._kprog_arm64_program_tag ∉
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

theorem call_step {initial : CC.Mem} (entry : HeaderLocal initial) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    CC.Step2 world (.State Arm64ProgramFixture.f_arm64_execute_compile readCall k (allocation initial).1 le m) CC.E0
      (.Callstate (.Internal (Arm64RegisterReads.reader true)) [.Vptr entry.block 0,.Vlong 30]
        (.Kcall (some Arm64ProgramFixture._t'150) Arm64ProgramFixture.f_arm64_execute_compile
          (allocation initial).1 le k) m) := by
  have header : (allocation initial).1.get Arm64ProgramFixture.___a64_entry =
      some (entry.block,.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr) :=
    Arm64ProgramEntryAllocation.local_binding initial _ _ _ entry.binding
  have binding := Arm64ProgramEntryReturnRaw.reader_binding true
  change CC.Genv.findSymbol world.genv_genv Arm64ProgramFixture._kprog_arm64_program_tag = _ ∧ _ at binding
  rw [call_source]
  apply CC.Step.call (tyargs := [CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr),CC.tulong])
    (tyres := CC.tuint) (cconv := CC.cc_default) (vf := .Vptr (Arm64ProgramEntryReturnRaw.readerBlock true) 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr,CC.lvalOfVar,unshadowed initial,binding.1,CC.doDerefLoc,CC.accessMode]
    rfl
  · apply CC.doEvalExprlist_sound
    refine eval_cons (v := .Vptr entry.block 0) ?_ (by rfl) ?_
    · simp only [CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,header]
      rfl
    exact eval_cons (v := .Vint (30#32)) (by rfl) (by rfl) (by rfl)
  · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero] using binding.2
  · rfl

/-- Complete original tag helper and saved caller on the same X30 effect. -/
theorem invoke {initial : CC.Mem} (entry : HeaderLocal initial) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (observed : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 30 = some (.Vlong 64,.Vint (9#32))) :
    InternalRun world 30
      (.State Arm64ProgramFixture.f_arm64_execute_compile readCall k (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 (temps le) m) := by
  let cont := CC.Cont.Kcall (some Arm64ProgramFixture._t'150) Arm64ProgramFixture.f_arm64_execute_compile (allocation initial).1 le k
  have enter : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile readCall k (allocation initial).1 le m)
      (.Callstate (.Internal (Arm64RegisterReads.reader true)) [.Vptr entry.block 0,.Vlong 30] cont m) :=
    .step (by rw [call_source]; trivial) (call_step entry le m k) (.refl _)
  have helper := (Arm64ProgramEntryReturnRaw.readers entry m cont observed).2
  have leave : InternalRun world 1 (.Returnstate (.Vint (9#32)) (CC.callCont cont) m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 (temps le) m) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  exact (enter.trans helper).trans leave

/-- Original sequence/call/resume reaches the real tag comparison, retaining
all actual source temporaries except t150 and the exact same heap. -/
theorem execute {initial : CC.Mem} (entry : HeaderLocal initial) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (observed : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 30 = some (.Vlong 64,.Vint (9#32))) :
    InternalRun world 32
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryReturnGuard.perform k (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile choice k (allocation initial).1 (temps le) m) := by
  have enter : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryReturnGuard.perform k (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile readCall (.Kseq choice k) (allocation initial).1 le m) :=
    .step (by rw [source]; trivial) (CC.doStep_sound _ _ _ _ (by rw [source,CC.doStep])) (.refl _)
  have resume : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip (.Kseq choice k) (allocation initial).1 (temps le) m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile choice k (allocation initial).1 (temps le) m) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  exact (enter.trans (invoke entry le m (.Kseq choice k) observed)).trans resume

end KProgFormal.ClightRefinement.Arm64ProgramEntryReturnTag
