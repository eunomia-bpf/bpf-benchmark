import KProgFormal.ClightRefinement.Arm64ProgramEntryCmpBranch
import KProgFormal.ClightRefinement.Arm64FlagRhsRegister

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryCmpRhsCall

open Arm64ProgramEntryAllocation (world allocation)
open Arm64ProgramEntryCmpBranch

private def symbol : CC.Block :=
  (CC.Genv.findSymbol world.genv_genv Arm64ProgramFixture._kprog_arm64_flag_rhs).get (by decide +kernel)
private theorem binding :
    CC.Genv.findSymbol world.genv_genv Arm64ProgramFixture._kprog_arm64_flag_rhs = some symbol ∧
    CC.Genv.findFunctPtr world.genv_genv symbol = some (.Internal Arm64FlagRhsRegister.handler) := by
  constructor <;> run_tac Arm64ProgramEntryLinked.sourceEquality
private theorem unshadowed (initial : CC.Mem) :
    (allocation initial).1.get Arm64ProgramFixture._kprog_arm64_flag_rhs = none := by
  have outside : Arm64ProgramFixture._kprog_arm64_flag_rhs ∉
      CC.varNames Arm64ProgramFixture.f_arm64_execute_compile.fn_vars := by decide +kernel
  simpa only [CC.emptyEnv,CC.PTree.gempty] using CC.allocVariables_env_other
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation initial)).symm) outside

theorem call_source : flagRhsCall = .Scall (some Arm64ProgramFixture._t'145)
    (.Evar Arm64ProgramFixture._kprog_arm64_flag_rhs (.Tfunction [CC.tulong,CC.tulong,CC.tulong] CC.tulong CC.cc_default))
    [.Econst_int (23#32) CC.tuint,.Econst_int (0#32) CC.tint,
      .Etempvar Arm64ProgramFixture._t'144 CC.tulong] := rfl

private theorem eval_cons {e : CC.Env} {le : CC.TempEnv} {m : CC.Mem}
    {a : CC.Expr} {xs : List CC.Expr} {ty : CC.Ty} {tys : List CC.Ty}
    {v converted : CC.Val} {values : List CC.Val}
    (head : CC.doEvalExpr world e le m a = some v)
    (cast : CC.Cop.semCast v (CC.typeof a) ty m = some converted)
    (rest : CC.doEvalExprlist world e le m xs tys = some values) :
    CC.doEvalExprlist world e le m (a :: xs) (ty :: tys) = some (converted :: values) := by
  simp only [CC.doEvalExprlist,head,cast,rest]

theorem call_step {initial : CC.Mem} (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (value : BitVec 64)
    (read : le.get Arm64ProgramFixture._t'144 = some (.Vlong value)) :
    CC.Step2 world
      (.State Arm64ProgramFixture.f_arm64_execute_compile flagRhsCall k (allocation initial).1 le m) CC.E0
      (.Callstate (.Internal Arm64FlagRhsRegister.handler) (Arm64FlagRhsRegister.arguments value)
        (.Kcall (some Arm64ProgramFixture._t'145) Arm64ProgramFixture.f_arm64_execute_compile (allocation initial).1 le k) m) := by
  rw [call_source]
  apply CC.Step.call (tyargs := [CC.tulong,CC.tulong,CC.tulong]) (tyres := CC.tulong)
    (cconv := CC.cc_default) (vf := .Vptr symbol 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr,CC.lvalOfVar,unshadowed initial,binding.1,CC.doDerefLoc,CC.accessMode]
    rfl
  · apply CC.doEvalExprlist_sound
    refine eval_cons (v := .Vint (23#32)) (by rfl) (by rfl) ?_
    refine eval_cons (v := .Vint (0#32)) (by rfl) (by rfl) ?_
    exact eval_cons (v := .Vlong value) (by simpa only [CC.doEvalExpr] using read) (by rfl) (by rfl)
  · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero] using binding.2
  · rfl

def temps (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv :=
  le.set Arm64ProgramFixture._t'145 (.Vlong value)

/-- Complete this actual Numeric call, real op23 function, return and saved
program caller with the original same-width operand. -/
theorem invoke {initial : CC.Mem} (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (value : BitVec 64)
    (read : le.get Arm64ProgramFixture._t'144 = some (.Vlong value))
    :
    ∃ count, InternalRun world count
      (.State Arm64ProgramFixture.f_arm64_execute_compile flagRhsCall k (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 (temps le value) m) := by
  let cont := CC.Cont.Kcall (some Arm64ProgramFixture._t'145) Arm64ProgramFixture.f_arm64_execute_compile
    (allocation initial).1 le k
  have enter : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile flagRhsCall k (allocation initial).1 le m)
      (.Callstate (.Internal Arm64FlagRhsRegister.handler) (Arm64FlagRhsRegister.arguments value) cont m) :=
    .step (by rw [call_source]; trivial) (call_step le m k value read) (.refl _)
  obtain ⟨count,run⟩ := Arm64FlagRhsRegister.execute world value cont m
  have leave : InternalRun world 1
      (.Returnstate (.Vlong value) (CC.callCont cont) m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 (temps le value) m) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  exact ⟨_,(enter.trans run).trans leave⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryCmpRhsCall
