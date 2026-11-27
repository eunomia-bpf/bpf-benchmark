import KProgFormal.ClightRefinement.Arm64KernelMemcpyRetainedView
import KProgFormal.ClightRefinement.Arm64MemcpyClobberRelease

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyRetainedRelease
open Arm64Producer
open Arm64ProgramEntryAllocation (world)
open Arm64KernelMemcpyProviders (Gprs Flags Vectors)
open Arm64KernelMemcpyRetainedRegisters (Kept)

/-- The actual original release entry, all byte and tag scans, targeted
providers, stores, helper return and eight frees form one execution.
The complete final register relation follows from the binding before release. -/
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
    (byteInputs : Arm64ClobberReleaseComplete.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe)
    (registerInputs : Arm64KernelMemcpyProviderRegisters.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe (Arm64KernelMemcpyReturn.Return stores.final))
    (flagInputs : Arm64KernelMemcpyProviderFlags.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe (Gprs (Arm64KernelMemcpyReturn.Return stores.final)) (Arm64KernelMemcpyReturn.Return stores.final))
    (vectorInputs : Arm64KernelMemcpyProviderVectors.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe
      (Gprs (Arm64KernelMemcpyReturn.Return stores.final)) (Flags (Arm64KernelMemcpyReturn.Return stores.final)) (Arm64KernelMemcpyReturn.Return stores.final))
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (prior : Arm64Registers.Represents addresses origins (fun r => r.val) m.nextblock m (.Vptr entry.block 0) native)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ calleeBefore.nextblock.toNat)
    (k : CC.Cont) (hk : CC.isCallCont k = true) :
    ∃ after written trace,
    ∃ packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16 (Gprs (Arm64KernelMemcpyReturn.Return stores.final)) (Flags (Arm64KernelMemcpyReturn.Return stores.final)) (Vectors (Arm64KernelMemcpyReturn.Return stores.final)) cell flagValue after,
      CC.Star (CC.Step2 world)
        (.State Arm64MemcpySource.handler Arm64MemcpyTransferSource.clobbers (Arm64MemcpySource.continuation k)
          (Arm64MemcpySource.allocation calleeBefore).1 outerLe m) trace (.Returnstate .Vundef k after) ∧
      Arm64MemcpyReturn.FreeResult calleeBefore written after ∧ FrameBelow initial.nextblock m after ∧
      after.nextblock = m.nextblock ∧ Kept entry.block m after ∧ Arm64KernelMemcpyTargetView.View after entry.block (Arm64KernelMemcpyReturn.Return stores.final) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) after.nextblock after (.Vptr entry.block 0)
        (Arm64KernelMemcpyReturn.Return stores.final) := by
  obtain ⟨released,releasedLe,releaseTrace,releaseCurrent,releaseRun,releaseFrame,_releaseAccess,releaseNext,releaseGprs⟩ :=
    Arm64MemcpyClobberRelease.execute_framed current flag byteInputs (Arm64MemcpySource.continuation k)
  obtain ⟨after,written,trace,packet,run,freed,frame,next,kept,view⟩ :=
    Arm64KernelMemcpyRetainedClobber.complete (Arm64KernelMemcpyReturn.Return stores.final) releaseCurrent
      registerInputs flagInputs vectorInputs bound k hk
  have releaseKept : Kept entry.block m released := fun j _ => releaseGprs j
  have completeKept := releaseKept.trans kept
  have represented := Arm64KernelMemcpyRetainedView.observe native first profile origin leading arrived loads stores
    (Arm64ClobberMemoryState.of_memcpy current flag).memory packet completeKept addresses origins prior
  exact ⟨after,written,CC.Eapp releaseTrace trace,packet,star_trans releaseRun run,freed,
    releaseFrame.trans frame,next.trans releaseNext,completeKept,view,represented⟩

end KProgFormal.ClightRefinement.Arm64KernelMemcpyRetainedRelease
