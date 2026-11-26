import KProgFormal.ClightRefinement.Arm64MemcpyCompleteProgram

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ClobberCoreComplete

open Arm64Producer (HeaderLocal TailLocal)
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetClobberEntry (helper)

/-- Real FunctionEntry2 and the original twenty-step SP/release selector use
only the shared current memory. The saved caller's actual temps stay its own. -/
theorem entered {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {env : CC.Env} {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {copiedN : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (current : Arm64ClobberCoreState.Saved env base abi byte rawR0 copiedN cell flagValue m) (k : CC.Cont) :
    InternalRun world 21 (.Callstate (.Internal helper) [.Vptr entry.block 0] k m)
      (.State helper Arm64MemsetClobberEntry.loop (Arm64MemsetClobberEntry.continuation k) CC.emptyEnv
        (Arm64MemsetClobberEntry.temps entry.block current.memory.storage.sp.block) m) := by
  have opened : InternalRun world 1 (.Callstate (.Internal helper) [.Vptr entry.block 0] k m)
      (.State helper helper.fn_body k CC.emptyEnv (Arm64MemsetClobberEntry.initialTemps entry.block) m) :=
    .step trivial (.internal_function _ _ _ _ _ _ _ (Arm64MemsetClobberEntry.entry_valid m entry.block)) (.refl _)
  have bodyRun := Arm64MemsetClobberEntry.enter CC.emptyEnv (Arm64MemsetClobberEntry.initialTemps entry.block) m k
    entry.block current.memory.storage.sp.block
    (by simp only [Arm64MemsetClobberEntry.initialTemps,CC.PTree.gss]) current.memory.view.bias
    current.memory.storage.spPointer (by simpa only [current.memory.spAtBase] using current.memory.storage.spRead)
  exact opened.trans bodyRun

/-- One real helper execution consumes the actual provider/cache outcomes
once, retains each selected value and returns with the original saved-env
rights and initialized flag. Both actual caller allocation environments fit
through their source-equal fn_vars while their functions and temps remain distinct. -/
theorem execute {initial seed calleeBefore before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {copiedN : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8} {outerLe : CC.TempEnv}
    (current : Arm64ClobberCoreState.Saved (Arm64MemcpySource.allocation calleeBefore).1
      base abi byte rawR0 copiedN cell flagValue before)
    (byteInputs : Arm64ClobberReleaseComplete.Inputs base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe)
    (registerInputs : Arm64ClobberRegisterComplete.Inputs base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe)
    (flagInputs : ∀ gprs, Arm64ClobberFlagsComplete.Inputs base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs)
    (vectorInputs : ∀ gprs flags, Arm64ClobberVectorsComplete.Inputs base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs flags)
    (k : CC.Cont) (hk : CC.isCallCont k = true) :
    ∃ after helperLe gprs flags values trace,
      ∃ _current : Arm64ClobberVectorsComplete.Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe
        gprs flags 64 values after helperLe,
      CC.Star (CC.Step2 world) (.Callstate (.Internal helper) [.Vptr entry.block 0] k before) trace
        (.Returnstate .Vundef k after) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock := by
  have enter := entered current k
  obtain ⟨released,releaseLe,releaseTrace,releasePacket,releaseRun,releaseFrame,releaseAccess,releaseNext⟩ :=
    Arm64ClobberReleaseTagComplete.original current byteInputs k
  let cont := Arm64MemsetReleaseTagLoop.restCont k
  obtain ⟨registerAfter,registerLe,gprs,registerTrace,registerPacket,registerRun,registerFrame,registerAccess,registerNext⟩ :=
    Arm64ClobberRegisterComplete.execute releasePacket registerInputs cont
  obtain ⟨flagAfter,flagLe,flags,flagTrace,flagPacket,flagRun,flagFrame,flagAccess,flagNext⟩ :=
    Arm64ClobberFlagsComplete.execute registerPacket (flagInputs gprs) cont
  obtain ⟨after,helperLe,values,vectorTrace,packet,vectorRun,vectorFrame,vectorAccess,vectorNext⟩ :=
    Arm64ClobberVectorsComplete.execute flagPacket (vectorInputs gprs flags) cont
  have leave := Arm64MemsetClobberReturn.exit helperLe after k hk
  refine ⟨after,helperLe,gprs,flags,values,
    CC.Eapp (CC.Eapp (CC.Eapp (CC.Eapp (CC.Eapp CC.E0 releaseTrace) registerTrace) flagTrace) vectorTrace) CC.E0,packet,?_,
    ((releaseFrame.trans registerFrame).trans flagFrame).trans vectorFrame,
    vectorAccess.trans (flagAccess.trans (registerAccess.trans releaseAccess)),
    vectorNext.trans (flagNext.trans (registerNext.trans releaseNext))⟩
  exact star_trans (star_trans (star_trans (star_trans (star_trans enter.sound releaseRun) registerRun) flagRun) vectorRun) leave.sound

end KProgFormal.ClightRefinement.Arm64ClobberCoreComplete
