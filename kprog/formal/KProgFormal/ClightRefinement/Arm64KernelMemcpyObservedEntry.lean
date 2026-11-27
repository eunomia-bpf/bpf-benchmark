import KProgFormal.ClightRefinement.Arm64KernelMemcpyCoordinates

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyObservedEntry
open Arm64Producer (HeaderLocal TailLocal)
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetPhysicalByte (Represents address)

/-- The same original C call and all13 actual native steps supply the genuine
post-free reader results and invocation-bound R0/SP coordinates once. -/
theorem execute {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (prior : Arm64MemsetPointerState.Packet base abi byte (Arm64MemcpyLengthState.words gprs) flags values before)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (le : CC.TempEnv) (k : CC.Cont) (addresses : Arm64Registers.PointerOrigins)
    (cell : TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before)
    (byteInputs : ∀ outerLe, Arm64ClobberReleaseComplete.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe)
    (physicalOrigin codeOrigin : BitVec 64) (input : MemoryProfile) (native : Reference.AArch64.State)
    (represented : Represents before base.stack.block physicalOrigin input native.machine)
    (source : Reference.AArch64.gpr native 1 = physicalOrigin+(-32#64))
    (destination : Reference.AArch64.gpr native 0 = physicalOrigin+(-16#64))
    (code : Arm64KernelMemcpyCode.Code codeOrigin native.machine)
    (pc : read_pc native.machine = codeOrigin+4#64)
    (count : Reference.AArch64.gpr native 2 = 16#64) (noError : read_err native.machine = .None)
    (registerInputs : ∀ (first : Reference.AArch64.State), first = Arm64KernelMemcpySmallPrefix.after native →
      ∀ (loads : Arm64KernelMemcpyTwoLoads.Result first input codeOrigin)
        (stores : Arm64KernelMemcpyTwoStores.Result loads.final input codeOrigin) outerLe,
      Arm64KernelMemcpyProviderRegisters.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe
        (Arm64KernelMemcpyReturn.Return stores.final))
    (flagInputs : ∀ (first : Reference.AArch64.State), first = Arm64KernelMemcpySmallPrefix.after native →
      ∀ (loads : Arm64KernelMemcpyTwoLoads.Result first input codeOrigin)
        (stores : Arm64KernelMemcpyTwoStores.Result loads.final input codeOrigin) outerLe,
      Arm64KernelMemcpyProviderFlags.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe
        (Arm64KernelMemcpyProviders.Gprs (Arm64KernelMemcpyReturn.Return stores.final)) (Arm64KernelMemcpyReturn.Return stores.final))
    (vectorInputs : ∀ (first : Reference.AArch64.State), first = Arm64KernelMemcpySmallPrefix.after native →
      ∀ (loads : Arm64KernelMemcpyTwoLoads.Result first input codeOrigin)
        (stores : Arm64KernelMemcpyTwoStores.Result loads.final input codeOrigin) outerLe,
      Arm64KernelMemcpyProviderVectors.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe
        (Arm64KernelMemcpyProviders.Gprs (Arm64KernelMemcpyReturn.Return stores.final))
        (Arm64KernelMemcpyProviders.Flags (Arm64KernelMemcpyReturn.Return stores.final)) (Arm64KernelMemcpyReturn.Return stores.final))
    (origins : Reference.Provenance.AArch64.Origins) (sameOrigin : physicalOrigin = origins.stack)
    (initialSP : Reference.AArch64.sp native = (-32#64)+origins.stack) :
    ∃ first : Reference.AArch64.State, ∃ leading : Arm64KernelMemcpySmallPrefix.Result native codeOrigin,
      first = Arm64KernelMemcpySmallPrefix.after native ∧
    ∃ loads : Arm64KernelMemcpyTwoLoads.Result first input codeOrigin,
    ∃ stores : Arm64KernelMemcpyTwoStores.Result loads.final input codeOrigin,
    ∃ after written trace,
    ∃ packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16
      (Arm64KernelMemcpyProviders.Gprs (Arm64KernelMemcpyReturn.Return stores.final))
      (Arm64KernelMemcpyProviders.Flags (Arm64KernelMemcpyReturn.Return stores.final))
      (Arm64KernelMemcpyProviders.Vectors (Arm64KernelMemcpyReturn.Return stores.final)) cell flagValue after,
      CC.Star (CC.Step2 world)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterThird k
          (Arm64ProgramEntryAllocation.allocation initial).1 le before) trace
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64MemcpyProgramEntry.next k
          (Arm64ProgramEntryAllocation.allocation initial).1 le after) ∧
      Arm64MemcpyReturn.FreeResult before written after ∧
      FrameBelow initial.nextblock before after ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (∀ j : Fin 16, CC.Mem.load .Mint8unsigned after base.stack.block (80+(j.val : Int)) =
        some (.Vint ((read_mem (address physicalOrigin (Arm64MemcpyStorePhysical.index j))
          (Arm64KernelMemcpyReturn.Return stores.final).machine).setWidth 32))) ∧
      Reference.AArch64.step stores.final = ⟨Arm64KernelMemcpyReturn.Return stores.final,[],none⟩ ∧
      read_pc (Arm64KernelMemcpyReturn.Return stores.final).machine = Reference.AArch64.gpr native 30 ∧
      read_memory_profile (Arm64KernelMemcpyReturn.Return stores.final).machine =
        some (Arm64KernelMemcpyWriteMemory.updated input 16 (Reference.AArch64.gpr loads.final 0)) ∧
      Arm64KernelMemcpyTargetView.View after entry.block (Arm64KernelMemcpyReturn.Return stores.final) ∧
      Reference.AArch64.gpr (Arm64KernelMemcpyReturn.Return stores.final) 0 =
        Reference.Provenance.AArch64.materialize origins (-16#64) (4#8) ∧
      Reference.AArch64.sp (Arm64KernelMemcpyReturn.Return stores.final) =
        Reference.Provenance.AArch64.materialize origins (-32#64) (4#8) := by
  obtain ⟨first,leading,arrived,loads,stores,after,written,trace,packet,sourceRun,freed,frame,next,
      observed,nativeStep,nativePC,nativeProfile⟩ :=
    Arm64KernelMemcpyTargetEntry.execute prior bound le k addresses cell flagValue flag byteInputs
      physicalOrigin codeOrigin input native represented source destination code pc count noError
      registerInputs flagInputs vectorInputs
  have actualDestination : Reference.AArch64.gpr native 0 = origins.stack+(-16#64) :=
    destination.trans (congrArg (fun word => word+(-16#64)) sameOrigin)
  obtain ⟨view,r0,sp⟩ := Arm64KernelMemcpyCoordinates.observe native first input codeOrigin leading arrived loads stores
    packet origins actualDestination initialSP
  exact ⟨first,leading,arrived,loads,stores,after,written,trace,packet,sourceRun,freed,frame,next,observed,
    nativeStep,nativePC,nativeProfile,view,r0,sp⟩

end KProgFormal.ClightRefinement.Arm64KernelMemcpyObservedEntry
