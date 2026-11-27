import KProgFormal.ClightRefinement.Arm64KernelMemcpyEntryControl
import KProgFormal.ClightRefinement.Arm64KernelMemcpyRetainedEntry

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyAliasEntry
open Arm64Producer (HeaderLocal TailLocal)
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetPhysicalByte (Represents address)

/-- The actual exported memcpy alias starts the same native/source witness.
Alias BTI, B, generic BTI and the thirteen actual helper steps execute on the
same Code, memory and profile. One original C caller-to-caller copy yields
both sixteen-byte and complete register observations. The Code's generic
branch and mature plain feature projection are explicit. -/
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
    (code : Arm64KernelMemcpyEntryCode.Code codeOrigin native.machine)
    (pc : read_pc native.machine = codeOrigin+0x230#64)
    (count : Reference.AArch64.gpr native 2 = 16#64) (noError : read_err native.machine = .None)
    (registerInputs : ∀ (first : Reference.AArch64.State), first = Arm64KernelMemcpySmallPrefix.after (Arm64KernelMemcpyEntryControl.after native) →
      ∀ (loads : Arm64KernelMemcpyTwoLoads.Result first input codeOrigin)
        (stores : Arm64KernelMemcpyTwoStores.Result loads.final input codeOrigin) outerLe,
      Arm64KernelMemcpyProviderRegisters.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe
        (Arm64KernelMemcpyReturn.Return stores.final))
    (flagInputs : ∀ (first : Reference.AArch64.State), first = Arm64KernelMemcpySmallPrefix.after (Arm64KernelMemcpyEntryControl.after native) →
      ∀ (loads : Arm64KernelMemcpyTwoLoads.Result first input codeOrigin)
        (stores : Arm64KernelMemcpyTwoStores.Result loads.final input codeOrigin) outerLe,
      Arm64KernelMemcpyProviderFlags.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe
        (Arm64KernelMemcpyProviders.Gprs (Arm64KernelMemcpyReturn.Return stores.final)) (Arm64KernelMemcpyReturn.Return stores.final))
    (vectorInputs : ∀ (first : Reference.AArch64.State), first = Arm64KernelMemcpySmallPrefix.after (Arm64KernelMemcpyEntryControl.after native) →
      ∀ (loads : Arm64KernelMemcpyTwoLoads.Result first input codeOrigin)
        (stores : Arm64KernelMemcpyTwoStores.Result loads.final input codeOrigin) outerLe,
      Arm64KernelMemcpyProviderVectors.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe
        (Arm64KernelMemcpyProviders.Gprs (Arm64KernelMemcpyReturn.Return stores.final))
        (Arm64KernelMemcpyProviders.Flags (Arm64KernelMemcpyReturn.Return stores.final)) (Arm64KernelMemcpyReturn.Return stores.final))
    (origins : Reference.Provenance.AArch64.Origins)
    (registerBinding : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) native) :
    ∃ control : Arm64KernelMemcpyEntryControl.Result native codeOrigin,
    ∃ first : Reference.AArch64.State, ∃ leading : Arm64KernelMemcpySmallPrefix.Result (Arm64KernelMemcpyEntryControl.after native) codeOrigin,
      first = Arm64KernelMemcpySmallPrefix.after (Arm64KernelMemcpyEntryControl.after native) ∧
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
      Arm64KernelMemcpyRetainedRegisters.Kept entry.block before after ∧
      Arm64KernelMemcpyTargetView.View after entry.block (Arm64KernelMemcpyReturn.Return stores.final) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) after.nextblock after (.Vptr entry.block 0)
        (Arm64KernelMemcpyReturn.Return stores.final) := by
  have control := Arm64KernelMemcpyEntryControl.execute native codeOrigin code pc noError
  have frame := Arm64KernelMemcpyEntryControl.resources native
  have representedAfter : Represents before base.stack.block physicalOrigin input
      (Arm64KernelMemcpyEntryControl.after native).machine := by
    refine ⟨frame.2.2.1.trans represented.profileRead,represented.readable,represented.writable,?_⟩
    intro i readable
    simpa only [read_mem,frame.1] using represented.bytes i readable
  have sourceAfter : Reference.AArch64.gpr (Arm64KernelMemcpyEntryControl.after native) 1 = physicalOrigin+(-32#64) :=
    (Arm64KernelMemcpyEntryControl.field native (.GPR (1#5)) (by decide)).trans source
  have destinationAfter : Reference.AArch64.gpr (Arm64KernelMemcpyEntryControl.after native) 0 = physicalOrigin+(-16#64) :=
    (Arm64KernelMemcpyEntryControl.field native (.GPR (0#5)) (by decide)).trans destination
  have countAfter : Reference.AArch64.gpr (Arm64KernelMemcpyEntryControl.after native) 2 = 16#64 :=
    (Arm64KernelMemcpyEntryControl.field native (.GPR (2#5)) (by decide)).trans count
  have registerAfter := (Arm64KernelMemcpyEntryControl.registers before (.Vptr entry.block 0) native).mpr registerBinding
  obtain ⟨first,leading,arrived,loads,stores,after,written,trace,packet,run,freed,caller,boundAfter,
      observed,returned,nativePC,profile,kept,view,relation⟩ :=
    Arm64KernelMemcpyRetainedEntry.execute prior bound le k addresses cell flagValue flag byteInputs
      physicalOrigin codeOrigin input (Arm64KernelMemcpyEntryControl.after native) representedAfter sourceAfter destinationAfter
      control.code control.pc countAfter control.noError registerInputs flagInputs vectorInputs origins registerAfter
  have link : Reference.AArch64.gpr (Arm64KernelMemcpyEntryControl.after native) 30 = Reference.AArch64.gpr native 30 :=
    Arm64KernelMemcpyEntryControl.field native (.GPR (30#5)) (by decide)
  exact ⟨control,first,leading,arrived,loads,stores,after,written,trace,packet,run,freed,caller,boundAfter,
    observed,returned,nativePC.trans link,profile,kept,view,relation⟩

end KProgFormal.ClightRefinement.Arm64KernelMemcpyAliasEntry
