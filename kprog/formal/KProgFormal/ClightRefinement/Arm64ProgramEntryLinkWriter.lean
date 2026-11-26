import KProgFormal.ClightRefinement.Arm64ProgramEntryLinkFrame

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryLinkWriter
open Arm64Producer (HeaderLocal)
open Arm64ProducerRegisterStorage (Storage)
open Arm64ProgramEntryAllocation (world allocation)
open Arm64ProgramEntryLinkCall (writeCall)

theorem call_source : writeCall = .Scall none
    (.Evar Arm64ProgramFixture._kprog_arm64_program_write_pointer
      (.Tfunction [CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr),CC.tulong,
        CC.tptr CC.tvoid,CC.tuchar] CC.tvoid CC.cc_default))
    [.Eaddrof (.Evar Arm64ProgramFixture.___a64_entry (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr))
       (CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr)),
     .Econst_int (30#32) CC.tuint,
     .Ecast (.Ecast (.Etempvar Arm64ProgramFixture._t'159 CC.tulong) CC.tlong) (CC.tptr CC.tvoid),
     .Econst_int (9#32) CC.tuint] := rfl

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

/-- True linked CALL-site evaluation retains t159's original signed-long then
void-pointer casts, destination X30 and actual code tag9. -/
theorem call_step {initial : CC.Mem} (entry : HeaderLocal initial) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (read : le.get Arm64ProgramFixture._t'159 = some (.Vlong 64)) :
    CC.Step2 world (.State Arm64ProgramFixture.f_arm64_execute_compile writeCall k (allocation initial).1 le m) CC.E0
      (.Callstate (.Internal Arm64PointerWrite.procedure) (Arm64PointerWrite.arguments entry.block 30 64 (9#8))
        (.Kcall none Arm64ProgramFixture.f_arm64_execute_compile (allocation initial).1 le k) m) := by
  have header : (allocation initial).1.get Arm64ProgramFixture.___a64_entry =
      some (entry.block,.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr) :=
    Arm64ProgramEntryAllocation.local_binding initial _ _ _ entry.binding
  have binding : CC.Genv.findSymbol world.genv_genv Arm64ProgramFixture._kprog_arm64_program_write_pointer =
      some (CC.Positive.ofNat 67) ∧ CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 67) =
      some (.Internal Arm64PointerWrite.procedure) := by
    have name : Arm64ProgramFixture._kprog_arm64_program_write_pointer =
        Arm64Program._kprog_arm64_program_write_pointer := rfl
    simpa only [Arm64ProgramEntryAllocation.world,name] using Arm64PointerWrite.Linked.binding
  rw [call_source]
  apply CC.Step.call (tyargs := [CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr),CC.tulong,
    CC.tptr CC.tvoid,CC.tuchar]) (tyres := CC.tvoid) (cconv := CC.cc_default) (vf := .Vptr (CC.Positive.ofNat 67) 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr,CC.lvalOfVar,unshadowed initial,binding.1,CC.doDerefLoc,CC.accessMode]
    rfl
  · apply CC.doEvalExprlist_sound
    refine eval_cons (v := .Vptr entry.block 0) ?_ (by rfl) ?_
    · simp only [CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,header]
      rfl
    refine eval_cons (v := .Vint (30#32)) (by rfl) (by rfl) ?_
    refine eval_cons (v := .Vlong 64) ?_ (by rfl) ?_
    · simp only [CC.doEvalExpr,read]
      rfl
    exact eval_cons (v := .Vint (9#32)) (by rfl) (by rfl) (by rfl)
  · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero] using binding.2
  · rfl

/-- The SAME actual word/tag stores supply the full original writer execution,
true return and saved program caller; no native state is invented as an input. -/
theorem invoke {initial m : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial m entry) (le : CC.TempEnv) (k : CC.Cont)
    (read : le.get Arm64ProgramFixture._t'159 = some (.Vlong 64)) :
    ∃ written, Arm64PointerWrite.Result storage 30 64 (9#8) written ∧ InternalRun world 55
      (.State Arm64ProgramFixture.f_arm64_execute_compile writeCall k (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 le written) := by
  let cont := CC.Cont.Kcall none Arm64ProgramFixture.f_arm64_execute_compile (allocation initial).1 le k
  obtain ⟨written,effect⟩ := Arm64PointerWrite.write storage 30 64 (9#8)
  obtain ⟨middle,word,tag⟩ := effect.stores
  have enter : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile writeCall k (allocation initial).1 le m)
      (.Callstate (.Internal Arm64PointerWrite.procedure) (Arm64PointerWrite.arguments entry.block 30 64 (9#8)) cont m) :=
    .step (by rw [call_source]; trivial) (call_step entry le m k read) (.refl _)
  have procedure := Arm64PointerWrite.execute_stores_layout world Arm64PointerWrite.Linked.layout cont rfl
    initial m middle written entry storage 30 64 (9#8) word tag
  have leave : InternalRun world 1 (.Returnstate .Vundef cont written)
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 le written) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  exact ⟨written,effect,(enter.trans procedure).trans leave⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryLinkWriter
