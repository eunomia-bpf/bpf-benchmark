import KProgFormal.ClightRefinement.Arm64MemsetClobberVectorsComplete

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MemsetClobberReturn

open Arm64Producer
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetClobberEntry (helper)

private def body : CC.Stmt := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm (← `(helper.fn_body)) none
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
    unless actual.isAppOfArity ``CC.Stmt.Sloop 2 do throwError "original helper loop changed"
    Lean.Elab.Tactic.closeMainGoal `actual_helper_return_body actual.getAppArgs[0]!

theorem continuation_source (k : CC.Cont) : Arm64MemsetReleaseTagLoop.restCont k = .Kloop1 body .Sbreak k := rfl
theorem empty_locals : helper.fn_vars = [] := rfl

/-- The genuine helper wrapper exits through its original break, performs
its actual empty-environment freeList and returns on the same reached heap. -/
theorem exit (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (hk : CC.isCallCont k = true) :
    InternalRun world 3 (.State helper .Sskip (Arm64MemsetReleaseTagLoop.restCont k) CC.emptyEnv le m)
      (.Returnstate .Vundef k m) := by
  rw [continuation_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  exact .step trivial (.skip_call _ _ _ _ _ _ hk rfl) (.refl _)

/-- The real Kcall none restores the saved memset function, eight-local
environment and caller temps, retaining the same actual vector-store heap. -/
theorem restore (before m : CC.Mem) (outerLe helperLe : CC.TempEnv) (k : CC.Cont) :
    InternalRun world 4
      (.State helper .Sskip
        (Arm64MemsetReleaseTagLoop.restCont (Arm64MemsetClobberEntry.callCont before outerLe k)) CC.emptyEnv helperLe m)
      (.State Arm64MemsetSource.handler .Sskip k (Arm64MemsetSource.allocation before).1 outerLe m) := by
  have leave := exit helperLe m (Arm64MemsetClobberEntry.callCont before outerLe k) rfl
  have returned : InternalRun world 1 (.Returnstate .Vundef (Arm64MemsetClobberEntry.callCont before outerLe k) m)
      (.State Arm64MemsetSource.handler .Sskip k (Arm64MemsetSource.allocation before).1 outerLe m) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  exact leave.trans returned

/-- The original clobbers Scall executes all150 genuine kind6 visits and176
stores, actual helper exit/free/return and the caller's real restoration. -/
theorem original {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe : CC.TempEnv} (current : Arm64MemsetTagTransferComplete.Invariant base abi byte 16 m outerLe)
    (byteInputs : Arm64MemsetReleaseComplete.Inputs base abi byte outerLe)
    (registerInputs : Arm64MemsetClobberRegisterComplete.Inputs base abi byte outerLe)
    (flagInputs : ∀ gprs, Arm64MemsetClobberFlagsComplete.Inputs base abi byte outerLe gprs)
    (vectorInputs : ∀ gprs flags, Arm64MemsetClobberVectorsComplete.Inputs base abi byte outerLe gprs flags)
    (before : CC.Mem) (k : CC.Cont) :
    ∃ after helperLe gprs flags values trace,
      ∃ _current : Arm64MemsetClobberVectorsComplete.Invariant base abi byte outerLe gprs flags 64 values after helperLe,
      CC.Star (CC.Step2 world) (.State Arm64MemsetSource.handler Arm64MemsetTagTransfer.clobbers k
        (Arm64MemsetSource.allocation before).1 outerLe m) trace
        (.State Arm64MemsetSource.handler .Sskip k (Arm64MemsetSource.allocation before).1 outerLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := by
  obtain ⟨after,helperLe,gprs,flags,values,trace,packet,run,frame,access,next⟩ :=
    Arm64MemsetClobberVectorsComplete.original current byteInputs registerInputs flagInputs vectorInputs before k
  have returned := restore before after outerLe helperLe k
  refine ⟨after,helperLe,gprs,flags,values,trace,packet,?_,frame,access,next⟩
  simpa only [CC.E0,CC.Eapp,List.append_nil] using star_trans run returned.sound

end KProgFormal.ClightRefinement.Arm64MemsetClobberReturn
