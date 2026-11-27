import KProgFormal.ClightRefinement.Arm64KernelMemcpyRetainedProgram

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyRetainedEntry
open Arm64Producer (HeaderLocal TailLocal)
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetPhysicalByte (Represents address)

private theorem represented_at {m : CC.Mem} {stack : CC.Block} {origin : BitVec 64} {profile : MemoryProfile}
    {before after : ArmState} (prior : Represents m stack origin profile before)
    (memory : after.mem = before.mem) (sameProfile : after.memoryProfile = before.memoryProfile) :
    Represents m stack origin profile after := by
  refine ⟨sameProfile.trans prior.profileRead,prior.readable,prior.writable,?_⟩
  intro i readable
  simpa only [read_mem,memory] using prior.bytes i readable

/-- One original native prefix/load/store/RET and source caller-to-caller
execution,with actual byte/profile/trace/free/Kept witnesses. The final
register interpretation is deferred to a reader of this SAME result. -/
theorem execute_factual {initial seed before : CC.Mem} {entry : HeaderLocal initial}
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
 :
    ∃ inputMemory : Arm64ClobberMemoryState.Packet base abi byte (-16#64) 0 before,
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
      Arm64KernelMemcpyRetainedRegisters.Kept entry.block before after ∧
      Arm64KernelMemcpyTargetView.View after entry.block (Arm64KernelMemcpyReturn.Return stores.final) := by
  have leading := Arm64KernelMemcpySmallPrefix.execute native codeOrigin code pc count noError
  obtain ⟨first,arrived⟩ : ∃ first : Reference.AArch64.State, first = Arm64KernelMemcpySmallPrefix.after native := ⟨_,rfl⟩
  have memory : first.machine.mem = native.machine.mem :=
    (congrArg (fun state : Reference.AArch64.State => state.machine.mem) arrived).trans leading.memory
  have sameProfile : first.machine.memoryProfile = native.machine.memoryProfile :=
    (congrArg (fun state : Reference.AArch64.State => state.machine.memoryProfile) arrived).trans leading.profile
  have firstRepresented := represented_at represented memory sameProfile
  have first0 : Reference.AArch64.gpr first 0 = Reference.AArch64.gpr native 0 :=
    (congrArg (fun state => Reference.AArch64.gpr state 0) arrived).trans
      (leading.fields (.GPR (0#5)) (by decide) (by decide) (by decide) (by intro f; cases f <;> decide))
  have first1 : Reference.AArch64.gpr first 1 = Reference.AArch64.gpr native 1 :=
    (congrArg (fun state => Reference.AArch64.gpr state 1) arrived).trans
      (leading.fields (.GPR (1#5)) (by decide) (by decide) (by decide) (by intro f; cases f <;> decide))
  have first30 : Reference.AArch64.gpr first 30 = Reference.AArch64.gpr native 30 :=
    (congrArg (fun state => Reference.AArch64.gpr state 30) arrived).trans
      (leading.fields (.GPR (30#5)) (by decide) (by decide) (by decide) (by intro f; cases f <;> decide))
  have readable : MemoryMode.permitted input.readable (Reference.AArch64.gpr native 1) 16 = true := by
    simp only [MemoryMode.permitted,List.all_eq_true]
    intro j member
    let index : Fin 16 := ⟨j,List.mem_range.mp member⟩
    have actual := (Arm64MemcpyPhysicalByteRead.observed represented (Arm64MemsetStoreExecution.index index) byte (prior.written index)).1
    have sameAddress : address physicalOrigin (Arm64MemsetStoreExecution.index index) =
        Reference.AArch64.gpr native 1+BitVec.ofNat 64 j := by
      simpa only [source] using Arm64KernelMemcpySource.source_address physicalOrigin index
    exact (congrArg input.readable sameAddress).symm.trans actual
  obtain ⟨loads⟩ := Arm64KernelMemcpyTwoLoads.continue_from_prefix native first codeOrigin input leading arrived represented.profileRead readable
  have endDestination : Reference.AArch64.gpr first 5 = Reference.AArch64.gpr first 0+16#64 :=
    ((congrArg (fun state => Reference.AArch64.gpr state 5) arrived).trans leading.destinationEnd).trans
      (congrArg (fun a => a+16#64) first0.symm)
  obtain ⟨copied,copyLe,copyCurrent,stores,copyRun,copyObserved,_profile,_outside,copyFlag,copyFrame,pbound,cbound,copyGprs⟩ :=
    Arm64KernelMemcpySource.execute_framed prior bound le k cell flagValue flag
      physicalOrigin codeOrigin input first loads.final firstRepresented (first1.trans source) (first0.trans destination)
      loads rfl endDestination
  obtain ⟨inputMemory,after,written,trace,packet,run,freed,frame,next,kept,view⟩ :=
    Arm64KernelMemcpyRetainedProgram.finish_copied_factual (Arm64KernelMemcpyReturn.Return stores.final)
      prior le k flag byteInputs (registerInputs first arrived loads stores)
      (flagInputs first arrived loads stores) (vectorInputs first arrived loads stores)
      addresses bound copied copyLe copyCurrent copyRun copyFlag copyFrame pbound cbound copyGprs
  have returned := Arm64KernelMemcpyReturn.execute loads.final input codeOrigin stores
  have link : Reference.AArch64.gpr loads.final 30 = Reference.AArch64.gpr native 30 :=
    (loads.fields (.GPR (30#5)) (by decide) (by decide) (by decide) (by decide) (by decide)).trans first30
  have observed : ∀ j : Fin 16, CC.Mem.load .Mint8unsigned after base.stack.block (80+(j.val : Int)) =
      some (.Vint ((read_mem (address physicalOrigin (Arm64MemcpyStorePhysical.index j))
        (Arm64KernelMemcpyReturn.Return stores.final).machine).setWidth 32)) := by
    have nativeMemory := (Arm64ProgramEntryReturnNative.resources stores.final).1
    intro j
    have word : byte.setWidth 32 = (read_mem (address physicalOrigin (Arm64MemcpyStorePhysical.index j)) stores.final.machine).setWidth 32 :=
      CC.Val.Vint.inj (Option.some.inj ((copyCurrent.copied j j.isLt).symm.trans (copyObserved j)))
    have sameByte : read_mem (address physicalOrigin (Arm64MemcpyStorePhysical.index j))
        (Arm64KernelMemcpyReturn.Return stores.final).machine =
        read_mem (address physicalOrigin (Arm64MemcpyStorePhysical.index j)) stores.final.machine :=
      congrArg (fun mem : Memory => mem (address physicalOrigin (Arm64MemcpyStorePhysical.index j))) nativeMemory
    exact (packet.memory.copied j j.isLt).trans (congrArg (fun value : BitVec 32 => some (CC.Val.Vint value))
      (word.trans (congrArg (fun value : BitVec 8 => value.setWidth 32) sameByte.symm)))
  exact ⟨inputMemory,first,leading,arrived,loads,stores,after,written,trace,packet,run,freed,frame,next,observed,
    returned.1,returned.2.1.trans link,Arm64KernelMemcpyReturn.profile loads.final input codeOrigin stores,
    kept,view⟩

/-- Preserve the exact original numeric API through one factual execution. -/
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
    (origins : Reference.Provenance.AArch64.Origins)
    (registerBinding : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) native) :
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
      Arm64KernelMemcpyRetainedRegisters.Kept entry.block before after ∧
      Arm64KernelMemcpyTargetView.View after entry.block (Arm64KernelMemcpyReturn.Return stores.final) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) after.nextblock after (.Vptr entry.block 0)
        (Arm64KernelMemcpyReturn.Return stores.final) := by

  obtain ⟨inputMemory,first,leading,arrived,loads,stores,after,written,trace,packet,
    run,freed,frame,next,observed,returned,nativePC,profile,kept,view⟩ :=
    execute_factual prior bound le k addresses cell flagValue flag byteInputs physicalOrigin codeOrigin input native
      represented source destination code pc count noError registerInputs flagInputs vectorInputs
  have relation := Arm64KernelMemcpyRetainedView.observe native first input codeOrigin leading arrived loads stores
    inputMemory packet kept addresses origins registerBinding
  exact ⟨first,leading,arrived,loads,stores,after,written,trace,packet,run,freed,frame,next,
    observed,returned,nativePC,profile,kept,view,relation⟩

end KProgFormal.ClightRefinement.Arm64KernelMemcpyRetainedEntry
