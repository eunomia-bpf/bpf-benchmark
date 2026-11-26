import KProgFormal.ClightRefinement.Arm64ProgramEntryCbzPrefix
import KProgFormal.ClightRefinement.Arm64BranchZero

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryCbzCall

open Arm64ProgramEntryAllocation (world allocation)
open Arm64ProgramEntryCbz

/-- Bind the same selected helper word through the imported register writer.
This is an input observation, with no native instruction executed here. -/
def native (s : Reference.AArch64.State) (raw : BitVec 64) : Reference.AArch64.State :=
  { s with machine := w (.GPR (3#5)) raw s.machine }
theorem native_word (s : Reference.AArch64.State) (raw : BitVec 64) :
    Reference.AArch64.gpr (native s raw) 3 = raw := by
  change r (.GPR (3#5)) (w (.GPR (3#5)) raw s.machine) = raw
  rw [r_of_w_same]
theorem native_other (s : Reference.AArch64.State) (raw : BitVec 64) (field : StateField)
    (other : field ≠ .GPR (3#5)) : r field (native s raw).machine = r field s.machine :=
  r_of_w_different other

private def symbol : CC.Block :=
  (CC.Genv.findSymbol world.genv_genv Arm64ProgramFixture._kprog_arm64_branch_test).get (by decide +kernel)
private theorem binding :
    CC.Genv.findSymbol world.genv_genv Arm64ProgramFixture._kprog_arm64_branch_test = some symbol ∧
    CC.Genv.findFunctPtr world.genv_genv symbol = some (.Internal Arm64BranchZero.handler) := by
  constructor <;> run_tac Arm64ProgramEntryLinked.sourceEquality
private theorem unshadowed (initial : CC.Mem) :
    (allocation initial).1.get Arm64ProgramFixture._kprog_arm64_branch_test = none := by
  have outside : Arm64ProgramFixture._kprog_arm64_branch_test ∉
      CC.varNames Arm64ProgramFixture.f_arm64_execute_compile.fn_vars := by decide +kernel
  simpa only [CC.emptyEnv,CC.PTree.gempty] using CC.allocVariables_env_other
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation initial)).symm) outside

theorem call_source : branchCall = .Scall (some Arm64ProgramFixture._t'138)
    (.Evar Arm64ProgramFixture._kprog_arm64_branch_test (.Tfunction [CC.tulong,CC.tulong,CC.tulong] CC.tint CC.cc_default))
    [.Econst_int (0#32) CC.tuint,.Etempvar Arm64ProgramFixture.___a64_l_value CC.tulong,
      .Econst_long (0#64) CC.tulong] := rfl

private theorem eval_cons {e : CC.Env} {le : CC.TempEnv} {m : CC.Mem}
    {a : CC.Expr} {xs : List CC.Expr} {ty : CC.Ty} {tys : List CC.Ty}
    {v converted : CC.Val} {values : List CC.Val}
    (head : CC.doEvalExpr world e le m a = some v)
    (cast : CC.Cop.semCast v (CC.typeof a) ty m = some converted)
    (rest : CC.doEvalExprlist world e le m xs tys = some values) :
    CC.doEvalExprlist world e le m (a :: xs) (ty :: tys) = some (converted :: values) := by
  simp only [CC.doEvalExprlist,head,cast,rest]

theorem call_step {initial : CC.Mem} (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (value : BitVec 32)
    (read : le.get Arm64ProgramFixture.___a64_l_value = some (.Vlong (value.setWidth 64))) :
    CC.Step2 world
      (.State Arm64ProgramFixture.f_arm64_execute_compile branchCall k (allocation initial).1 le m) CC.E0
      (.Callstate (.Internal Arm64BranchZero.handler) (Arm64BranchZero.arguments value)
        (.Kcall (some Arm64ProgramFixture._t'138) Arm64ProgramFixture.f_arm64_execute_compile (allocation initial).1 le k) m) := by
  rw [call_source]
  apply CC.Step.call (tyargs := [CC.tulong,CC.tulong,CC.tulong]) (tyres := CC.tint)
    (cconv := CC.cc_default) (vf := .Vptr symbol 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr,CC.lvalOfVar,unshadowed initial,binding.1,CC.doDerefLoc,CC.accessMode]
    rfl
  · apply CC.doEvalExprlist_sound
    refine eval_cons (v := .Vint (0#32)) (by rfl) (by rfl) ?_
    refine eval_cons (v := .Vlong (value.setWidth 64)) ?_ (by rfl) ?_
    · simp only [CC.doEvalExpr,read]
    exact eval_cons (v := .Vlong (0#64)) (by rfl) (by rfl) (by rfl)
  · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero] using binding.2
  · rfl

def temps (le : CC.TempEnv) (s : Reference.AArch64.State) : CC.TempEnv :=
  le.set Arm64ProgramFixture._t'138 (.Vint (if Arm64BranchZero.taken s then 1#32 else 0#32))

/-- Complete this actual Numeric call, real op0 function, return and saved
program caller using the imported compare-branch condition. -/
theorem invoke {initial : CC.Mem} (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (value : BitVec 32)
    (read : le.get Arm64ProgramFixture.___a64_l_value = some (.Vlong (value.setWidth 64)))
    (s : Reference.AArch64.State) (word : (Reference.AArch64.gpr s 3).setWidth 32 = value) :
    ∃ count, InternalRun world count
      (.State Arm64ProgramFixture.f_arm64_execute_compile branchCall k (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 (temps le s) m) := by
  let cont := CC.Cont.Kcall (some Arm64ProgramFixture._t'138) Arm64ProgramFixture.f_arm64_execute_compile
    (allocation initial).1 le k
  have enter : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile branchCall k (allocation initial).1 le m)
      (.Callstate (.Internal Arm64BranchZero.handler) (Arm64BranchZero.arguments value) cont m) :=
    .step (by rw [call_source]; trivial) (call_step le m k value read) (.refl _)
  obtain ⟨count,run⟩ := Arm64BranchZero.execute world value cont m s word
  have leave : InternalRun world 1
      (.Returnstate (.Vint (if Arm64BranchZero.taken s then 1#32 else 0#32)) (CC.callCont cont) m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 (temps le s) m) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  exact ⟨_,(enter.trans run).trans leave⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryCbzCall
