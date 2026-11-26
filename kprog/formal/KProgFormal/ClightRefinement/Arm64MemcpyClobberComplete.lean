import KProgFormal.ClightRefinement.Arm64ClobberResult

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MemcpyClobberComplete

open Arm64Producer
open Arm64ProgramEntryAllocation (world)

/-- The same memcpy clobber executes its complete real helper, restores the
callee, frees all eight original local ranges and returns the retained
current output with the same provider trace and initialized flag. -/
theorem original {initial seed calleeBefore m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {vectors : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8} {outerLe : CC.TempEnv}
    (current : Arm64MemcpyLoopState.Invariant base abi byte gprs flags vectors calleeBefore 16 m outerLe)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue m)
    (byteInputs : Arm64ClobberReleaseComplete.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe)
    (registerInputs : Arm64ClobberRegisterComplete.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe)
    (flagInputs : ∀ selectedGprs, Arm64ClobberFlagsComplete.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe selectedGprs)
    (vectorInputs : ∀ selectedGprs selectedFlags, Arm64ClobberVectorsComplete.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe selectedGprs selectedFlags)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ calleeBefore.nextblock.toNat)
    (k : CC.Cont) (hk : CC.isCallCont k = true) :
    ∃ after written selectedGprs selectedFlags values trace,
      ∃ _current : Arm64ClobberResult.Packet base abi byte (-16#64) 16 selectedGprs selectedFlags values cell flagValue after,
      CC.Star (CC.Step2 world)
        (.State Arm64MemcpySource.handler Arm64MemcpyTransferSource.clobbers (Arm64MemcpySource.continuation k)
          (Arm64MemcpySource.allocation calleeBefore).1 outerLe m) trace
        (.Returnstate .Vundef k after) ∧
      Arm64MemcpyReturn.FreeResult calleeBefore written after ∧
      FrameBelow initial.nextblock m after ∧ after.nextblock = m.nextblock := by
  obtain ⟨written,helperLe,selectedGprs,selectedFlags,values,trace,packet,run,frame,_access,next⟩ :=
    Arm64MemcpyClobberReturn.original current flag byteInputs registerInputs flagInputs vectorInputs
      (Arm64MemcpySource.continuation k)
  obtain ⟨after,freed,leave⟩ := Arm64MemcpyReturn.exit packet.flagsPacket.registers.ready outerLe k hk
  let retained := Arm64ClobberResult.retained calleeBefore.nextblock bound freed.caller
    (Arm64ClobberResult.of_complete packet)
  have allocated := (FrameBelow.allocVariables (CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (Arm64Producer.allocation initial)).symm) initial.nextblock (Nat.le_refl _)).1
  have initialBound : initial.nextblock.toNat ≤ calleeBefore.nextblock.toNat := Nat.le_trans allocated bound
  have older : FrameBelow initial.nextblock written after :=
    fun block below => freed.caller block (Nat.lt_of_lt_of_le below initialBound)
  refine ⟨after,written,selectedGprs,selectedFlags,values,trace,retained,?_,freed,frame.trans older,freed.nextblock.trans next⟩
  simpa only [CC.E0,CC.Eapp,List.append_nil] using star_trans run leave.sound

end KProgFormal.ClightRefinement.Arm64MemcpyClobberComplete
