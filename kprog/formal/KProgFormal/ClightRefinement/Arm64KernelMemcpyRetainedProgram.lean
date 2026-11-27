import KProgFormal.ClightRefinement.Arm64KernelMemcpyRetainedTransfer
import KProgFormal.ClightRefinement.Arm64MemcpyCompleteProgram

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyRetainedProgram
open Arm64Producer
open Arm64ProgramEntryAllocation (world)
open Arm64KernelMemcpyProviders (Gprs Flags Vectors)
open Arm64KernelMemcpyRetainedRegisters (Kept)

/-- One actual original caller-to-caller memcpy runs every copy, tag transfer,
release, targeted provider, real store, eight-local free and saved return.
Its complete final relation follows from the original caller's input binding. -/
theorem finish_copied {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {cell : TailLocal initial 5} {flagValue : BitVec 8} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (native first : Reference.AArch64.State) (profile : MemoryProfile) (origin : BitVec 64)
    (leading : Arm64KernelMemcpySmallPrefix.Result native origin)
    (arrived : first = Arm64KernelMemcpySmallPrefix.after native)
    (loads : Arm64KernelMemcpyTwoLoads.Result first profile origin)
    (stores : Arm64KernelMemcpyTwoStores.Result loads.final profile origin)
    (packetBefore : Arm64MemsetPointerState.Packet base abi byte (Arm64MemcpyLengthState.words gprs) flags values before)
    (le : CC.TempEnv) (k : CC.Cont)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before)
    (byteInputs : ∀ outerLe, Arm64ClobberReleaseComplete.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe)
    (registerInputs : ∀ outerLe, Arm64KernelMemcpyProviderRegisters.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe (Arm64KernelMemcpyReturn.Return stores.final))
    (flagInputs : ∀ outerLe, Arm64KernelMemcpyProviderFlags.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe (Gprs (Arm64KernelMemcpyReturn.Return stores.final)) (Arm64KernelMemcpyReturn.Return stores.final))
    (vectorInputs : ∀ outerLe, Arm64KernelMemcpyProviderVectors.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe
      (Gprs (Arm64KernelMemcpyReturn.Return stores.final)) (Flags (Arm64KernelMemcpyReturn.Return stores.final)) (Arm64KernelMemcpyReturn.Return stores.final))
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (prior : Arm64Registers.Represents addresses origins (fun r => r.val) before.nextblock before (.Vptr entry.block 0) native)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (copied : CC.Mem) (copyLe : CC.TempEnv)
    (copyCurrent : Arm64MemcpyLoopState.Invariant base abi byte (Arm64MemcpyLengthState.words gprs) flags values before 16 copied copyLe)
    (copyRun : CC.Star (CC.Step2 world)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterThird k
        (Arm64ProgramEntryAllocation.allocation initial).1 le before) CC.E0
      (.State Arm64MemcpySource.handler Arm64MemcpyCopyEntry.afterCopy
        (Arm64MemcpySource.continuation (Arm64MemcpyProgramEntry.callCont initial le k))
        (Arm64MemcpySource.allocation before).1 copyLe copied))
    (copyFlag : Arm64MemcpyReadCurrent.Flag entry cell flagValue copied)
    (copyFrame : FrameBelow initial.nextblock before copied)
    (pbound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ copied.nextblock.toNat)
    (cbound : (Arm64MemcpySource.allocation before).2.nextblock.toNat ≤ copied.nextblock.toNat)
    (copyGprs : ∀ q : Fin 31, Arm64EntryMemory.gpr copied.nextblock copied (.Vptr entry.block 0) q.val =
      Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) q.val)
    :
    ∃ after written trace,
    ∃ packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16 (Gprs (Arm64KernelMemcpyReturn.Return stores.final)) (Flags (Arm64KernelMemcpyReturn.Return stores.final)) (Vectors (Arm64KernelMemcpyReturn.Return stores.final)) cell flagValue after,
      CC.Star (CC.Step2 world)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterThird k
          (Arm64ProgramEntryAllocation.allocation initial).1 le before) trace
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64MemcpyProgramEntry.next k
          (Arm64ProgramEntryAllocation.allocation initial).1 le after) ∧
      Arm64MemcpyReturn.FreeResult before written after ∧ FrameBelow initial.nextblock before after ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧ Kept entry.block before after ∧ Arm64KernelMemcpyTargetView.View after entry.block (Arm64KernelMemcpyReturn.Return stores.final) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) after.nextblock after (.Vptr entry.block 0)
        (Arm64KernelMemcpyReturn.Return stores.final) := by
  let cont := Arm64MemcpySource.continuation (Arm64MemcpyProgramEntry.callCont initial le k)
  obtain ⟨transferred,transferLe,transferCurrent,transferRun,_copies,transferFrame,transferFlag,transferNext⟩ :=
    Arm64MemcpyTransferSequential.execute copyLe cont addresses copyCurrent pbound cbound cell flagValue copyFlag
  have transferGprs (j : Fin 31) :=
    Arm64MemsetFreeState.gpr copied.nextblock pbound transferFrame copyCurrent.packet.storage j
  obtain ⟨released,releasedLe,releaseTrace,releaseCurrent,releaseRun,releaseFrame,_releaseAccess,releaseNext,releaseGprs⟩ :=
    Arm64MemcpyClobberRelease.execute_framed transferCurrent transferFlag (byteInputs transferLe) cont
  obtain ⟨after,written,trace,packet,run,freed,frame,next,kept,view⟩ :=
    Arm64KernelMemcpyRetainedClobber.complete (Arm64KernelMemcpyReturn.Return stores.final) releaseCurrent
      (registerInputs transferLe) (flagInputs transferLe) (vectorInputs transferLe) bound
      (Arm64MemcpyProgramEntry.callCont initial le k) rfl
  have copyKept : Kept entry.block before copied := fun j _ => copyGprs j
  have transferKept : Kept entry.block copied transferred := fun j _ => transferGprs j
  have releaseKept : Kept entry.block transferred released := fun j _ => releaseGprs j
  have completeKept := ((copyKept.trans transferKept).trans releaseKept).trans kept
  let inputMemory : Arm64ClobberMemoryState.Packet base abi byte (-16#64) 0 before := {
    view := packetBefore.view
    stackSame := packetBefore.stackSame
    tagsSame := packetBefore.tagsSame
    resources := packetBefore.resources
    storage := packetBefore.storage
    spAtBase := packetBefore.spAtBase
    r0 := packetBefore.r0
    abiHeader := packetBefore.abiHeader
    abiKind := packetBefore.abiKind
    tagBytes := packetBefore.tagBytes
    source := fun j => by
      have index : ((Arm64MemsetStoreExecution.index j).val : Int) = 64+(j.val : Int) := by
        change ((64+j.val : Nat) : Int) = _
        omega
      simpa only [index] using packetBefore.written j
    copied := by intro j impossible; omega }
  have represented := Arm64KernelMemcpyRetainedView.observe native first profile origin leading arrived loads stores
    inputMemory packet completeKept addresses origins prior
  have allocated := (FrameBelow.allocVariables (CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (Arm64Producer.allocation initial)).symm) initial.nextblock (Nat.le_refl _)).1
  have older : FrameBelow initial.nextblock copied transferred := fun block below =>
    transferFrame block (Nat.lt_of_lt_of_le below (Nat.le_trans allocated pbound))
  have finalBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat := by
    rw [next,releaseNext,transferNext]
    exact pbound
  refine ⟨after,written,CC.Eapp releaseTrace trace,packet,?_,freed,
    ((copyFrame.trans older).trans releaseFrame).trans frame,finalBound,completeKept,view,represented⟩
  have returned := Arm64MemcpyCompleteProgram.returned initial le after k
  simpa only [CC.E0,CC.Eapp,List.nil_append,List.append_nil,cont] using
    star_trans copyRun (star_trans transferRun (star_trans releaseRun (star_trans run returned.sound)))
/-- Execute the original copy once and feed its SAME reached witnesses to the full continuation. -/
theorem complete {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {cell : TailLocal initial 5} {flagValue : BitVec 8} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (native first : Reference.AArch64.State) (profile : MemoryProfile) (origin : BitVec 64)
    (leading : Arm64KernelMemcpySmallPrefix.Result native origin)
    (arrived : first = Arm64KernelMemcpySmallPrefix.after native)
    (loads : Arm64KernelMemcpyTwoLoads.Result first profile origin)
    (stores : Arm64KernelMemcpyTwoStores.Result loads.final profile origin)
    (packetBefore : Arm64MemsetPointerState.Packet base abi byte (Arm64MemcpyLengthState.words gprs) flags values before)
    (le : CC.TempEnv) (k : CC.Cont)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before)
    (byteInputs : ∀ outerLe, Arm64ClobberReleaseComplete.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe)
    (registerInputs : ∀ outerLe, Arm64KernelMemcpyProviderRegisters.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe (Arm64KernelMemcpyReturn.Return stores.final))
    (flagInputs : ∀ outerLe, Arm64KernelMemcpyProviderFlags.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe (Gprs (Arm64KernelMemcpyReturn.Return stores.final)) (Arm64KernelMemcpyReturn.Return stores.final))
    (vectorInputs : ∀ outerLe, Arm64KernelMemcpyProviderVectors.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe
      (Gprs (Arm64KernelMemcpyReturn.Return stores.final)) (Flags (Arm64KernelMemcpyReturn.Return stores.final)) (Arm64KernelMemcpyReturn.Return stores.final))
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (prior : Arm64Registers.Represents addresses origins (fun r => r.val) before.nextblock before (.Vptr entry.block 0) native)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    :
    ∃ after written trace,
    ∃ packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16 (Gprs (Arm64KernelMemcpyReturn.Return stores.final)) (Flags (Arm64KernelMemcpyReturn.Return stores.final)) (Vectors (Arm64KernelMemcpyReturn.Return stores.final)) cell flagValue after,
      CC.Star (CC.Step2 world)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterThird k
          (Arm64ProgramEntryAllocation.allocation initial).1 le before) trace
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64MemcpyProgramEntry.next k
          (Arm64ProgramEntryAllocation.allocation initial).1 le after) ∧
      Arm64MemcpyReturn.FreeResult before written after ∧ FrameBelow initial.nextblock before after ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧ Kept entry.block before after ∧ Arm64KernelMemcpyTargetView.View after entry.block (Arm64KernelMemcpyReturn.Return stores.final) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) after.nextblock after (.Vptr entry.block 0)
        (Arm64KernelMemcpyReturn.Return stores.final) := by
  obtain ⟨copied,copyLe,copyCurrent,copyRun,_written,copyFlag,copyFrame,pbound,cbound,copyGprs⟩ :=
    Arm64MemcpyCopyProgram.execute_framed packetBefore bound le k cell flagValue flag
  exact finish_copied native first profile origin leading arrived loads stores packetBefore le k flag byteInputs registerInputs flagInputs vectorInputs addresses origins prior bound copied copyLe copyCurrent copyRun copyFlag copyFrame pbound cbound copyGprs

end KProgFormal.ClightRefinement.Arm64KernelMemcpyRetainedProgram
