import KProgFormal.ClightRefinement.Arm64KernelMemcpyRetainedRelease
import KProgFormal.ClightRefinement.Arm64MemcpyTransferSequential

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyRetainedTransfer
open Arm64Producer
open Arm64ProgramEntryAllocation (world)
open Arm64KernelMemcpyProviders (Gprs Flags Vectors)
open Arm64KernelMemcpyRetainedRegisters (Kept)

/-- The original afterCopy statement runs both active and all fourteen inactive
transfer iterations before the same release, targeted providers and real return.
The initial source/native binding is taken before those actual tag effects. -/
theorem complete {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {cell : TailLocal initial 5} {flagValue : BitVec 8} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64} {outerLe : CC.TempEnv}
    (native first : Reference.AArch64.State) (profile : MemoryProfile) (origin : BitVec 64)
    (leading : Arm64KernelMemcpySmallPrefix.Result native origin)
    (arrived : first = Arm64KernelMemcpySmallPrefix.after native)
    (loads : Arm64KernelMemcpyTwoLoads.Result first profile origin)
    (stores : Arm64KernelMemcpyTwoStores.Result loads.final profile origin)
    (current : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 m outerLe)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue m)
    (byteInputs : ∀ outerLe, Arm64ClobberReleaseComplete.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe)
    (registerInputs : ∀ outerLe, Arm64KernelMemcpyProviderRegisters.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe (Arm64KernelMemcpyReturn.Return stores.final))
    (flagInputs : ∀ outerLe, Arm64KernelMemcpyProviderFlags.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe (Gprs (Arm64KernelMemcpyReturn.Return stores.final)) (Arm64KernelMemcpyReturn.Return stores.final))
    (vectorInputs : ∀ outerLe, Arm64KernelMemcpyProviderVectors.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe
      (Gprs (Arm64KernelMemcpyReturn.Return stores.final)) (Flags (Arm64KernelMemcpyReturn.Return stores.final)) (Arm64KernelMemcpyReturn.Return stores.final))
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ m.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ m.nextblock.toNat)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (prior : Arm64Registers.Represents addresses origins (fun r => r.val) m.nextblock m (.Vptr entry.block 0) native)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ calleeBefore.nextblock.toNat)
    (k : CC.Cont) (hk : CC.isCallCont k = true) :
    ∃ after written trace,
    ∃ packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16 (Gprs (Arm64KernelMemcpyReturn.Return stores.final)) (Flags (Arm64KernelMemcpyReturn.Return stores.final)) (Vectors (Arm64KernelMemcpyReturn.Return stores.final)) cell flagValue after,
      CC.Star (CC.Step2 world)
        (.State Arm64MemcpySource.handler Arm64MemcpyCopyEntry.afterCopy (Arm64MemcpySource.continuation k)
          (Arm64MemcpySource.allocation calleeBefore).1 outerLe m) trace (.Returnstate .Vundef k after) ∧
      Arm64MemcpyReturn.FreeResult calleeBefore written after ∧ FrameBelow initial.nextblock m after ∧
      after.nextblock = m.nextblock ∧ Kept entry.block m after ∧ Arm64KernelMemcpyTargetView.View after entry.block (Arm64KernelMemcpyReturn.Return stores.final) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) after.nextblock after (.Vptr entry.block 0)
        (Arm64KernelMemcpyReturn.Return stores.final) := by
  obtain ⟨transferred,transferLe,transferCurrent,transferRun,_copies,transferFrame,transferFlag,transferNext⟩ :=
    Arm64MemcpyTransferSequential.execute outerLe (Arm64MemcpySource.continuation k) addresses current
      producerBound callerBound cell flagValue flag
  have transferGprs (j : Fin 31) :=
    Arm64MemsetFreeState.gpr m.nextblock producerBound transferFrame current.packet.storage j
  have transferKept : Kept entry.block m transferred := fun j _ => transferGprs j
  have transferredPrior : Arm64Registers.Represents addresses origins (fun r => r.val)
      transferred.nextblock transferred (.Vptr entry.block 0) native := by
    rw [transferNext]
    exact (Arm64Registers.frame transferFrame (.Vptr entry.block 0) native).mpr prior
  obtain ⟨after,written,trace,packet,run,freed,frame,next,kept,view,represented⟩ :=
    Arm64KernelMemcpyRetainedRelease.complete native first profile origin leading arrived loads stores
      transferCurrent transferFlag (byteInputs transferLe) (registerInputs transferLe) (flagInputs transferLe) (vectorInputs transferLe) addresses origins transferredPrior bound k hk
  have completeKept := transferKept.trans kept
  have older : FrameBelow initial.nextblock m transferred := fun block below =>
    transferFrame block (Nat.lt_of_lt_of_le below (by
      have allocated := (FrameBelow.allocVariables (CC.doAllocVariables_sound _ _ _ _ _ _
        (Prod.eta (Arm64Producer.allocation initial)).symm) initial.nextblock (Nat.le_refl _)).1
      exact Nat.le_trans allocated producerBound))
  refine ⟨after,written,CC.Eapp CC.E0 trace,packet,?_,freed,
    older.trans frame,next.trans transferNext,completeKept,view,represented⟩
  exact star_trans transferRun run

end KProgFormal.ClightRefinement.Arm64KernelMemcpyRetainedTransfer
