import KProgFormal.ClightRefinement.Arm64KernelMemcpyRetainedProgram
import KProgFormal.ClightRefinement.Arm64MemcpyCompleteProgram

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyRetainedProgram
open Arm64Producer
open Arm64ProgramEntryAllocation (world)
open Arm64KernelMemcpyProviders (Gprs Flags Vectors)
open Arm64KernelMemcpyRetainedRegisters (Kept)

example {initial seed before : CC.Mem} {entry : HeaderLocal initial}
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
        (Arm64KernelMemcpyReturn.Return stores.final) :=
  Arm64KernelMemcpyRetainedProgram.finish_copied native first profile origin leading arrived loads stores packetBefore le k flag byteInputs registerInputs flagInputs vectorInputs addresses origins prior bound copied copyLe copyCurrent copyRun copyFlag copyFrame pbound cbound copyGprs

example {initial seed before : CC.Mem} {entry : HeaderLocal initial}
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
        (Arm64KernelMemcpyReturn.Return stores.final) :=
  Arm64KernelMemcpyRetainedProgram.complete native first profile origin leading arrived loads stores packetBefore le k flag byteInputs registerInputs flagInputs vectorInputs addresses origins prior bound

#check Arm64KernelMemcpyRetainedProgram.finish_copied_factual
#print axioms Arm64KernelMemcpyRetainedProgram.finish_copied_factual
#check Arm64KernelMemcpyRetainedProgram.complete_factual
#print axioms Arm64KernelMemcpyRetainedProgram.complete_factual
#check Arm64KernelMemcpyRetainedProgram.finish_copied
#print axioms Arm64KernelMemcpyRetainedProgram.finish_copied
#check Arm64KernelMemcpyRetainedProgram.complete
#print axioms Arm64KernelMemcpyRetainedProgram.complete
end KProgFormal.ClightRefinement.Arm64KernelMemcpyRetainedProgram
