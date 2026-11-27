import KProgFormal.ClightRefinement.Arm64KernelMemcpyProviders
import KProgFormal.ClightRefinement.Arm64MemcpyCompleteProgram

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyTargetContinuation
open Arm64Producer (HeaderLocal TailLocal)
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetPhysicalByte (address)

/-- Continue the SAME source afterCopy packet through all real tag-transfer
steps, clobber/provider trace, eight local frees and saved caller return.
The same native returned state supplies exact targeted GPR/flag/vector words, genuine RET and final bytes. -/
theorem execute {initial seed before middle : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (copyLe callerLe : CC.TempEnv) (k : CC.Cont) (addresses : Arm64Registers.PointerOrigins)
    (copy : Arm64MemcpyLoopState.Invariant base abi byte (Arm64MemcpyLengthState.words gprs) flags values before 16 middle copyLe)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ middle.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation before).2.nextblock.toNat ≤ middle.nextblock.toNat)
    (cell : TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue middle)
    (byteInputs : ∀ outerLe, Arm64ClobberReleaseComplete.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe)
    (physicalOrigin codeOrigin : BitVec 64) (profile : MemoryProfile) (native : Reference.AArch64.State)
    (stores : Arm64KernelMemcpyTwoStores.Result native profile codeOrigin)
    (registerInputs : ∀ outerLe, Arm64KernelMemcpyProviderRegisters.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe
      (Arm64KernelMemcpyReturn.Return stores.final))
    (flagInputs : ∀ outerLe, Arm64KernelMemcpyProviderFlags.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe
      (Arm64KernelMemcpyProviders.Gprs (Arm64KernelMemcpyReturn.Return stores.final)) (Arm64KernelMemcpyReturn.Return stores.final))
    (vectorInputs : ∀ outerLe, Arm64KernelMemcpyProviderVectors.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe
      (Arm64KernelMemcpyProviders.Gprs (Arm64KernelMemcpyReturn.Return stores.final))
      (Arm64KernelMemcpyProviders.Flags (Arm64KernelMemcpyReturn.Return stores.final)) (Arm64KernelMemcpyReturn.Return stores.final))
    (observed : ∀ j : Fin 16, CC.Mem.load .Mint8unsigned middle base.stack.block (80+(j.val : Int)) =
      some (.Vint ((read_mem (address physicalOrigin (Arm64MemcpyStorePhysical.index j)) stores.final.machine).setWidth 32))) :
    ∃ after written trace,
    ∃ packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16
      (Arm64KernelMemcpyProviders.Gprs (Arm64KernelMemcpyReturn.Return stores.final))
      (Arm64KernelMemcpyProviders.Flags (Arm64KernelMemcpyReturn.Return stores.final))
      (Arm64KernelMemcpyProviders.Vectors (Arm64KernelMemcpyReturn.Return stores.final)) cell flagValue after,
      CC.Star (CC.Step2 world)
        (.State Arm64MemcpySource.handler Arm64MemcpyCopyEntry.afterCopy
          (Arm64MemcpySource.continuation (Arm64MemcpyProgramEntry.callCont initial callerLe k))
          (Arm64MemcpySource.allocation before).1 copyLe middle) trace
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64MemcpyProgramEntry.next k
          (Arm64ProgramEntryAllocation.allocation initial).1 callerLe after) ∧
      Arm64MemcpyReturn.FreeResult before written after ∧
      FrameBelow initial.nextblock middle after ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (∀ j : Fin 16, CC.Mem.load .Mint8unsigned after base.stack.block (80+(j.val : Int)) =
        some (.Vint ((read_mem (address physicalOrigin (Arm64MemcpyStorePhysical.index j))
          (Arm64KernelMemcpyReturn.Return stores.final).machine).setWidth 32))) ∧
      Reference.AArch64.step stores.final = ⟨Arm64KernelMemcpyReturn.Return stores.final,[],none⟩ ∧
      read_pc (Arm64KernelMemcpyReturn.Return stores.final).machine = Reference.AArch64.gpr native 30 ∧
      read_memory_profile (Arm64KernelMemcpyReturn.Return stores.final).machine =
        some (Arm64KernelMemcpyWriteMemory.updated profile 16 (Reference.AArch64.gpr native 0)) := by
  let cont := Arm64MemcpySource.continuation (Arm64MemcpyProgramEntry.callCont initial callerLe k)
  obtain ⟨transferred,transferLe,transferCurrent,transferRun,_,transferFrame,transferFlag,frontier⟩ :=
    Arm64MemcpyTransferSequential.execute copyLe cont addresses copy producerBound callerBound cell flagValue flag
  obtain ⟨after,written,trace,packet,procedure,freed,frame,next,_registers,_flags,_vectors⟩ :=
    Arm64KernelMemcpyProviders.complete (Arm64KernelMemcpyReturn.Return stores.final)
      transferCurrent transferFlag (byteInputs transferLe) (registerInputs transferLe)
      (flagInputs transferLe) (vectorInputs transferLe) bound (Arm64MemcpyProgramEntry.callCont initial callerLe k) rfl
  have initialBound : initial.nextblock.toNat ≤ middle.nextblock.toNat := by
    have allocated := (FrameBelow.allocVariables (CC.doAllocVariables_sound _ _ _ _ _ _
      (Prod.eta (Arm64Producer.allocation initial)).symm) initial.nextblock (Nat.le_refl _)).1
    exact Nat.le_trans allocated producerBound
  have older : FrameBelow initial.nextblock middle transferred :=
    fun block below => transferFrame block (Nat.lt_of_lt_of_le below initialBound)
  have returned := Arm64KernelMemcpyReturn.execute native profile codeOrigin stores
  have nativeMemory := (Arm64ProgramEntryReturnNative.resources stores.final).1
  refine ⟨after,written,trace,packet,?_,freed,older.trans frame,?_,?_,
    returned.1,returned.2.1,Arm64KernelMemcpyReturn.profile native profile codeOrigin stores⟩
  · simpa only [CC.E0,CC.Eapp,List.nil_append,List.append_nil] using
      star_trans (star_trans transferRun procedure) (Arm64MemcpyCompleteProgram.returned initial callerLe after k).sound
  · rw [next,frontier]
    exact producerBound
  · intro j
    have word : byte.setWidth 32 = (read_mem (address physicalOrigin (Arm64MemcpyStorePhysical.index j)) stores.final.machine).setWidth 32 := by
      exact CC.Val.Vint.inj (Option.some.inj ((copy.copied j j.isLt).symm.trans (observed j)))
    have sameByte : read_mem (address physicalOrigin (Arm64MemcpyStorePhysical.index j))
        (Arm64KernelMemcpyReturn.Return stores.final).machine =
        read_mem (address physicalOrigin (Arm64MemcpyStorePhysical.index j)) stores.final.machine :=
      congrArg (fun mem : Memory => mem (address physicalOrigin (Arm64MemcpyStorePhysical.index j))) nativeMemory
    exact (packet.memory.copied j j.isLt).trans (congrArg (fun value : BitVec 32 => some (CC.Val.Vint value))
      (word.trans (congrArg (fun value : BitVec 8 => value.setWidth 32) sameByte.symm)))

end KProgFormal.ClightRefinement.Arm64KernelMemcpyTargetContinuation
