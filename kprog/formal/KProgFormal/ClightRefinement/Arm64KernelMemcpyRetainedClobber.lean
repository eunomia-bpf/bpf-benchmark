import KProgFormal.ClightRefinement.Arm64KernelMemcpyRetainedVectors
import KProgFormal.ClightRefinement.Arm64KernelMemcpyTargetView

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyRetainedClobber
open Arm64Producer
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetClobberEntry (helper)
open Arm64KernelMemcpyProviders (Gprs Flags Vectors)
open Arm64KernelMemcpyRetainedRegisters (Kept)

/-- From the actual completed release packet, all86 original provider visits
retain the same R19–R30 reads alongside every exact native-selected map. -/
theorem execute {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {cell : TailLocal initial 5} {flagValue : BitVec 8} {outerLe le : CC.TempEnv}
    (returned : Reference.AArch64.State)
    (current : Arm64ClobberReleaseTagComplete.Invariant base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe 20 m le)
    (registerInputs : Arm64KernelMemcpyProviderRegisters.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe returned)
    (flagInputs : Arm64KernelMemcpyProviderFlags.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe (Gprs returned) returned)
    (vectorInputs : Arm64KernelMemcpyProviderVectors.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe
      (Gprs returned) (Flags returned) returned) (k : CC.Cont) :
    ∃ after nextLe trace,
    ∃ final : Arm64ClobberVectorsComplete.Invariant base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe
      (Gprs returned) (Flags returned) 64 (Vectors returned) after nextLe,
      CC.Star (CC.Step2 world) (.State helper Arm64MemsetClobberEntry.rest k CC.emptyEnv le m) trace
        (.State helper .Sskip k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock ∧
      Kept entry.block m after := by
  let regStart : Arm64ClobberRegisterComplete.Invariant base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe
      0 (Gprs returned) m le := ⟨current.released.ready,current.released.parameter,by intros j impossible; omega⟩
  obtain ⟨regAfter,regLe,regTrace,regCurrent,regRun,regFrame,regAccess,regNext,regKept⟩ :=
    Arm64KernelMemcpyRetainedRegisters.iterations returned registerInputs k regStart 18 (by decide)
  let flagStart : Arm64ClobberFlagsComplete.Invariant base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe
      (Gprs returned) 0 (Flags returned) regAfter regLe := ⟨regCurrent,by intros j impossible; omega⟩
  obtain ⟨flagAfter,flagLe,flagTrace,flagCurrent,flagRun,flagFrame,flagAccess,flagNext,flagKept⟩ :=
    Arm64KernelMemcpyRetainedFlags.iterations returned flagInputs k flagStart 4 (by decide)
  let vectorStart : Arm64ClobberVectorsComplete.Invariant base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe
      (Gprs returned) (Flags returned) 0 (Vectors returned) flagAfter flagLe := ⟨flagCurrent,by intros j impossible; omega⟩
  obtain ⟨after,nextLe,vectorTrace,final,vectorRun,vectorFrame,vectorAccess,vectorNext,vectorKept⟩ :=
    Arm64KernelMemcpyRetainedVectors.iterations returned vectorInputs k vectorStart 64 (by decide)
  refine ⟨after,nextLe,CC.Eapp (CC.Eapp regTrace flagTrace) vectorTrace,final,?_,
    (regFrame.trans flagFrame).trans vectorFrame,vectorAccess.trans (flagAccess.trans regAccess),
    vectorNext.trans (flagNext.trans regNext),(regKept.trans flagKept).trans vectorKept⟩
  exact star_trans (star_trans regRun flagRun) vectorRun

/-- The same stage run follows the actual helper return and eight-local
free, retaining all twelve original reads and the real post-free View. -/
theorem complete {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {cell : TailLocal initial 5} {flagValue : BitVec 8} {outerLe le : CC.TempEnv}
    (returned : Reference.AArch64.State)
    (current : Arm64ClobberReleaseTagComplete.Invariant base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe 20 m le)
    (registerInputs : Arm64KernelMemcpyProviderRegisters.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe returned)
    (flagInputs : Arm64KernelMemcpyProviderFlags.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe (Gprs returned) returned)
    (vectorInputs : Arm64KernelMemcpyProviderVectors.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe
      (Gprs returned) (Flags returned) returned)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ calleeBefore.nextblock.toNat)
    (k : CC.Cont) (hk : CC.isCallCont k = true) :
    ∃ after written trace,
    ∃ packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16 (Gprs returned) (Flags returned) (Vectors returned) cell flagValue after,
      CC.Star (CC.Step2 world)
        (.State helper Arm64MemsetClobberEntry.rest
          (Arm64MemsetReleaseTagLoop.restCont (Arm64MemcpyClobberEntry.callCont calleeBefore outerLe (Arm64MemcpySource.continuation k)))
          CC.emptyEnv le m) trace (.Returnstate .Vundef k after) ∧
      Arm64MemcpyReturn.FreeResult calleeBefore written after ∧ FrameBelow initial.nextblock m after ∧
      after.nextblock = m.nextblock ∧ Kept entry.block m after ∧ Arm64KernelMemcpyTargetView.View after entry.block returned := by
  let helperK := Arm64MemsetReleaseTagLoop.restCont
    (Arm64MemcpyClobberEntry.callCont calleeBefore outerLe (Arm64MemcpySource.continuation k))
  obtain ⟨written,helperLe,trace,final,run,frame,_access,next,kept⟩ :=
    execute returned current registerInputs flagInputs vectorInputs helperK
  have restore := Arm64MemcpyClobberReturn.restore calleeBefore written outerLe helperLe (Arm64MemcpySource.continuation k)
  obtain ⟨after,freed,leave⟩ := Arm64MemcpyReturn.exit final.flagsPacket.registers.ready outerLe k hk
  let packet := Arm64ClobberResult.retained calleeBefore.nextblock bound freed.caller (Arm64ClobberResult.of_complete final)
  have allocated := (FrameBelow.allocVariables (CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (Arm64Producer.allocation initial)).symm) initial.nextblock (Nat.le_refl _)).1
  have initialBound : initial.nextblock.toNat ≤ calleeBefore.nextblock.toNat := Nat.le_trans allocated bound
  have older : FrameBelow initial.nextblock written after :=
    fun block below => freed.caller block (Nat.lt_of_lt_of_le below initialBound)
  have retained : Kept entry.block written after := fun j _ =>
    Arm64MemsetFreeState.gpr calleeBefore.nextblock bound freed.caller final.flagsPacket.registers.ready.memory.storage j
  refine ⟨after,written,trace,packet,?_,freed,frame.trans older,freed.nextblock.trans next,
    kept.trans retained,Arm64KernelMemcpyTargetView.observe packet⟩
  simpa only [CC.E0,CC.Eapp,List.append_nil] using star_trans (star_trans run restore.sound) leave.sound

end KProgFormal.ClightRefinement.Arm64KernelMemcpyRetainedClobber
