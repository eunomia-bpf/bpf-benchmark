import KProgFormal.ClightRefinement.Arm64ClobberCoreComplete

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MemsetFlagClobber

open Arm64Producer (HeaderLocal TailLocal)
open Arm64ProgramEntryAllocation (world)

/-- The original memset Scall opens the same helper and consumes the real
provider outcomes once. Its own saved handler, allocation env and temp map
are restored on the reached heap, with the same initialized flag. -/
theorem execute {initial seed calleeBefore before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {cell : TailLocal initial 5} {flagValue : BitVec 8} {outerLe : CC.TempEnv}
    (current : Arm64MemsetTagTransferComplete.Invariant base abi byte 16 before outerLe)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before)
    (access : before.access = (Arm64MemsetSource.allocation calleeBefore).2.access)
    (byteInputs : Arm64ClobberReleaseComplete.Inputs base abi byte calleeBefore (-32#64) 0 cell flagValue outerLe)
    (registerInputs : Arm64ClobberRegisterComplete.Inputs base abi byte calleeBefore (-32#64) 0 cell flagValue outerLe)
    (flagInputs : ∀ gprs, Arm64ClobberFlagsComplete.Inputs base abi byte calleeBefore (-32#64) 0 cell flagValue outerLe gprs)
    (vectorInputs : ∀ gprs flags, Arm64ClobberVectorsComplete.Inputs base abi byte calleeBefore (-32#64) 0 cell flagValue outerLe gprs flags)
    (k : CC.Cont) :
    ∃ after helperLe gprs flags values trace,
      ∃ _current : Arm64ClobberVectorsComplete.Invariant base abi byte calleeBefore (-32#64) 0 cell flagValue outerLe
        gprs flags 64 values after helperLe,
      CC.Star (CC.Step2 world)
        (.State Arm64MemsetSource.handler Arm64MemsetTagTransfer.clobbers k
          (Arm64MemsetSource.allocation calleeBefore).1 outerLe before) trace
        (.State Arm64MemsetSource.handler .Sskip k (Arm64MemsetSource.allocation calleeBefore).1 outerLe after) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock := by
  let saved := Arm64ClobberCoreState.of_memset current.ready flag access
  have first : InternalRun world 1
      (.State Arm64MemsetSource.handler Arm64MemsetTagTransfer.clobbers k
        (Arm64MemsetSource.allocation calleeBefore).1 outerLe before)
      (.Callstate (.Internal Arm64MemsetClobberEntry.helper) [.Vptr entry.block 0]
        (Arm64MemsetClobberEntry.callCont calleeBefore outerLe k) before) :=
    .step trivial (Arm64MemsetClobberEntry.call_step calleeBefore before entry.block outerLe k current.ready.entryRead) (.refl _)
  obtain ⟨after,helperLe,gprs,flags,values,trace,packet,helperRun,frame,helperAccess,next⟩ :=
    Arm64ClobberCoreComplete.execute saved byteInputs registerInputs flagInputs vectorInputs
      (Arm64MemsetClobberEntry.callCont calleeBefore outerLe k) rfl
  have restored : InternalRun world 1
      (.Returnstate .Vundef (Arm64MemsetClobberEntry.callCont calleeBefore outerLe k) after)
      (.State Arm64MemsetSource.handler .Sskip k (Arm64MemsetSource.allocation calleeBefore).1 outerLe after) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  refine ⟨after,helperLe,gprs,flags,values,trace,packet,?_,frame,helperAccess,next⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append,List.append_nil] using star_trans (star_trans first.sound helperRun) restored.sound

end KProgFormal.ClightRefinement.Arm64MemsetFlagClobber
