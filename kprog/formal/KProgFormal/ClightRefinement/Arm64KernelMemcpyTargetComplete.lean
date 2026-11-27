import KProgFormal.ClightRefinement.Arm64KernelMemcpyTargetContinuation

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyTargetComplete
open Arm64Producer (HeaderLocal TailLocal)
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetPhysicalByte (Represents address)

/-- One original C memcpy call, from its real caller statement through all
copies/tags/clobbers/frees to the same caller, corresponds to the SAME actual
native load/store/RET witness's copied bytes, exact targeted provider maps and control/resource outputs. -/
theorem execute {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (prior : Arm64MemsetPointerState.Packet base abi byte (Arm64MemcpyLengthState.words gprs) flags values before)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (le : CC.TempEnv) (k : CC.Cont) (addresses : Arm64Registers.PointerOrigins)
    (cell : TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before)
    (byteInputs : ∀ outerLe, Arm64ClobberReleaseComplete.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe)
    (physicalOrigin codeOrigin : BitVec 64) (input : MemoryProfile) (native current : Reference.AArch64.State)
    (represented : Represents before base.stack.block physicalOrigin input native.machine)
    (source : Reference.AArch64.gpr native 1 = physicalOrigin+(-32#64))
    (destination : Reference.AArch64.gpr native 0 = physicalOrigin+(-16#64))
    (loads : Arm64KernelMemcpyTwoLoads.Result native input codeOrigin) (reached : current = loads.final)
    (destinationEnd : Reference.AArch64.gpr native 5 = Reference.AArch64.gpr native 0+16#64)
    (registerInputs : ∀ (stores : Arm64KernelMemcpyTwoStores.Result current input codeOrigin) outerLe,
      Arm64KernelMemcpyProviderRegisters.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe
        (Arm64KernelMemcpyReturn.Return stores.final))
    (flagInputs : ∀ (stores : Arm64KernelMemcpyTwoStores.Result current input codeOrigin) outerLe,
      Arm64KernelMemcpyProviderFlags.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe
        (Arm64KernelMemcpyProviders.Gprs (Arm64KernelMemcpyReturn.Return stores.final)) (Arm64KernelMemcpyReturn.Return stores.final))
    (vectorInputs : ∀ (stores : Arm64KernelMemcpyTwoStores.Result current input codeOrigin) outerLe,
      Arm64KernelMemcpyProviderVectors.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe
        (Arm64KernelMemcpyProviders.Gprs (Arm64KernelMemcpyReturn.Return stores.final))
        (Arm64KernelMemcpyProviders.Flags (Arm64KernelMemcpyReturn.Return stores.final)) (Arm64KernelMemcpyReturn.Return stores.final)) :
    ∃ stores : Arm64KernelMemcpyTwoStores.Result current input codeOrigin,
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
      read_pc (Arm64KernelMemcpyReturn.Return stores.final).machine = Reference.AArch64.gpr current 30 ∧
      read_memory_profile (Arm64KernelMemcpyReturn.Return stores.final).machine =
        some (Arm64KernelMemcpyWriteMemory.updated input 16 (Reference.AArch64.gpr current 0)) := by
  obtain ⟨middle,copyLe,copy,stores,copyRun,observed,_,_,copyFlag,copyFrame,producerBound,callerBound⟩ :=
    Arm64KernelMemcpySource.execute prior bound le k cell flagValue flag physicalOrigin codeOrigin input native current
      represented source destination loads reached destinationEnd
  obtain ⟨after,written,trace,packet,tailRun,freed,frame,next,
      observedAfter,nativeStep,nativePC,nativeProfile⟩ :=
    Arm64KernelMemcpyTargetContinuation.execute copyLe le k addresses copy bound producerBound callerBound cell flagValue copyFlag
      byteInputs physicalOrigin codeOrigin input current stores (registerInputs stores) (flagInputs stores) (vectorInputs stores) observed
  refine ⟨stores,after,written,trace,packet,?_,freed,
    copyFrame.trans frame,next,observedAfter,nativeStep,nativePC,nativeProfile⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans copyRun tailRun

end KProgFormal.ClightRefinement.Arm64KernelMemcpyTargetComplete
