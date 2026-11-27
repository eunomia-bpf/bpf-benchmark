import KProgFormal.ClightRefinement.Arm64KernelMemcpyOutput
import KProgFormal.ClightRefinement.Arm64MemcpyCopyProgram
import KProgFormal.ClightRefinement.Arm64MemcpyPhysicalByteRead
import KProgFormal.ClightRefinement.Arm64MemcpyStorePhysical

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpySource
open Arm64MemsetPhysicalByte (Represents address)
open Arm64ProgramEntryAllocation (world)

theorem source_address (origin : BitVec 64) (j : Fin 16) :
    address origin (Arm64MemsetStoreExecution.index j) = origin+(-32#64)+BitVec.ofNat 64 j.val := by
  simp only [address,Arm64MemsetStoreExecution.index,BitVec.ofNat_add]
  bv_omega

theorem destination_address (origin : BitVec 64) (j : Fin 16) :
    address origin (Arm64MemcpyStorePhysical.index j) = origin+(-16#64)+BitVec.ofNat 64 j.val := by
  rw [Arm64MemcpyStorePhysical.physical_address]
  bv_omega

/-- One original C memcpy execution and the SAME actual native load/store
witness copy the same16 bytes. Source resources derive physical write rights;
real source loads supply initialized bytes, retaining actual caller frames. -/
theorem execute_framed {initial seed before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (prior : Arm64MemsetPointerState.Packet base abi byte (Arm64MemcpyLengthState.words gprs) flags values before)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (le : CC.TempEnv) (k : CC.Cont) (cell : Arm64Producer.TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before)
    (physicalOrigin codeOrigin : BitVec 64) (input : MemoryProfile) (native current : Reference.AArch64.State)
    (represented : Represents before base.stack.block physicalOrigin input native.machine)
    (source : Reference.AArch64.gpr native 1 = physicalOrigin+(-32#64))
    (destination : Reference.AArch64.gpr native 0 = physicalOrigin+(-16#64))
    (loads : Arm64KernelMemcpyTwoLoads.Result native input codeOrigin) (reached : current = loads.final)
    (destinationEnd : Reference.AArch64.gpr native 5 = Reference.AArch64.gpr native 0+16#64) :
    ∃ after copyLe, ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte
      (Arm64MemcpyLengthState.words gprs) flags values before 16 after copyLe,
    ∃ stores : Arm64KernelMemcpyTwoStores.Result current input codeOrigin,
      CC.Star (CC.Step2 world)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterThird k
          (Arm64ProgramEntryAllocation.allocation initial).1 le before) CC.E0
        (.State Arm64MemcpySource.handler Arm64MemcpyCopyEntry.afterCopy
          (Arm64MemcpySource.continuation (Arm64MemcpyProgramEntry.callCont initial le k))
          (Arm64MemcpySource.allocation before).1 copyLe after) ∧
      (∀ j : Fin 16, CC.Mem.load .Mint8unsigned after base.stack.block (80+(j.val : Int)) =
        some (.Vint ((read_mem (address physicalOrigin (Arm64MemcpyStorePhysical.index j)) stores.final.machine).setWidth 32))) ∧
      read_memory_profile stores.final.machine = some
        (Arm64KernelMemcpyWriteMemory.updated input 16 (Reference.AArch64.gpr current 0)) ∧
      (∀ other : BitVec 64, 16 ≤ (other-Reference.AArch64.gpr current 0).toNat →
        read_mem other stores.final.machine = read_mem other current.machine) ∧
      Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧
      FrameBelow initial.nextblock before after ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (Arm64MemcpySource.allocation before).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (∀ q : Fin 31, Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) q.val =
        Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) q.val) := by
  have range := (Arm64MemsetStoreExecution.ranges prior.view prior.resources).2
  rw [prior.stackSame] at range
  have writable : MemoryMode.permitted input.writable (Reference.AArch64.gpr native 0) 16 = true := by
    simp only [MemoryMode.permitted,List.all_eq_true]
    intro j member
    let index : Fin 16 := ⟨j,List.mem_range.mp member⟩
    have actual := CC.Mem.rangePerm_perm before base.stack.block 0 160 .Cur .Writable range
      ((Arm64MemcpyStorePhysical.index index).val : Int) (by simp only [Arm64MemcpyStorePhysical.index]; omega)
      (by simp only [Arm64MemcpyStorePhysical.index]; have := index.isLt; omega)
    have mapped := (represented.writable (Arm64MemcpyStorePhysical.index index)).trans actual
    have sameAddress : address physicalOrigin (Arm64MemcpyStorePhysical.index index) =
        Reference.AArch64.gpr native 0+BitVec.ofNat 64 j := by
      simpa only [destination] using destination_address physicalOrigin index
    exact (congrArg input.writable sameAddress).symm.trans mapped
  have sourceByte (j : Fin 16) : read_mem (Reference.AArch64.gpr native 1+BitVec.ofNat 64 j.val) native.machine = byte := by
    have actual := (Arm64MemcpyPhysicalByteRead.observed represented (Arm64MemsetStoreExecution.index j) byte (prior.written j)).2.2
    have sameAddress : address physicalOrigin (Arm64MemsetStoreExecution.index j) =
        Reference.AArch64.gpr native 1+BitVec.ofNat 64 j.val := by
      simpa only [source] using source_address physicalOrigin j
    exact (congrArg (fun a => read_mem a native.machine) sameAddress).symm.trans actual
  obtain ⟨stores,_,nativeBytes,otherBytes,profileAfter⟩ :=
    Arm64KernelMemcpyOutput.complete_from_loads native current codeOrigin input loads reached destinationEnd represented.profileRead writable
  have currentDestination : Reference.AArch64.gpr current 0 = Reference.AArch64.gpr native 0 :=
    (congrArg (fun state => Reference.AArch64.gpr state 0) reached).trans
      (loads.fields (.GPR (0#5)) (by decide) (by decide) (by decide) (by decide) (by decide))
  have finalByte (j : Fin 16) : read_mem (address physicalOrigin (Arm64MemcpyStorePhysical.index j)) stores.final.machine = byte := by
    have sameAddress : address physicalOrigin (Arm64MemcpyStorePhysical.index j) =
        Reference.AArch64.gpr current 0+BitVec.ofNat 64 j.val := by
      simpa only [currentDestination,destination] using destination_address physicalOrigin j
    exact (congrArg (fun a => read_mem a stores.final.machine) sameAddress).trans
      ((nativeBytes j).trans (sourceByte j))
  obtain ⟨after,copyLe,next,sourceRun,copied,flagAfter,frame,producerBound,calleeBound,gprsKept⟩ :=
    Arm64MemcpyCopyProgram.execute_framed prior bound le k cell flagValue flag
  refine ⟨after,copyLe,next,stores,sourceRun,?_,profileAfter,otherBytes,flagAfter,frame,producerBound,calleeBound,gprsKept⟩
  intro j
  simpa only [finalByte j] using copied j
/-- The complete original interface consumes the same actual native and source execution. -/
theorem execute {initial seed before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (prior : Arm64MemsetPointerState.Packet base abi byte (Arm64MemcpyLengthState.words gprs) flags values before)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (le : CC.TempEnv) (k : CC.Cont) (cell : Arm64Producer.TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before)
    (physicalOrigin codeOrigin : BitVec 64) (input : MemoryProfile) (native current : Reference.AArch64.State)
    (represented : Represents before base.stack.block physicalOrigin input native.machine)
    (source : Reference.AArch64.gpr native 1 = physicalOrigin+(-32#64))
    (destination : Reference.AArch64.gpr native 0 = physicalOrigin+(-16#64))
    (loads : Arm64KernelMemcpyTwoLoads.Result native input codeOrigin) (reached : current = loads.final)
    (destinationEnd : Reference.AArch64.gpr native 5 = Reference.AArch64.gpr native 0+16#64) :
    ∃ after copyLe, ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte
      (Arm64MemcpyLengthState.words gprs) flags values before 16 after copyLe,
    ∃ stores : Arm64KernelMemcpyTwoStores.Result current input codeOrigin,
      CC.Star (CC.Step2 world)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterThird k
          (Arm64ProgramEntryAllocation.allocation initial).1 le before) CC.E0
        (.State Arm64MemcpySource.handler Arm64MemcpyCopyEntry.afterCopy
          (Arm64MemcpySource.continuation (Arm64MemcpyProgramEntry.callCont initial le k))
          (Arm64MemcpySource.allocation before).1 copyLe after) ∧
      (∀ j : Fin 16, CC.Mem.load .Mint8unsigned after base.stack.block (80+(j.val : Int)) =
        some (.Vint ((read_mem (address physicalOrigin (Arm64MemcpyStorePhysical.index j)) stores.final.machine).setWidth 32))) ∧
      read_memory_profile stores.final.machine = some
        (Arm64KernelMemcpyWriteMemory.updated input 16 (Reference.AArch64.gpr current 0)) ∧
      (∀ other : BitVec 64, 16 ≤ (other-Reference.AArch64.gpr current 0).toNat →
        read_mem other stores.final.machine = read_mem other current.machine) ∧
      Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧
      FrameBelow initial.nextblock before after ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (Arm64MemcpySource.allocation before).2.nextblock.toNat ≤ after.nextblock.toNat := by
  obtain ⟨after,copyLe,next,stores,run,observed,profileAfter,outside,flagAfter,frame,pbound,cbound,_kept⟩ := execute_framed prior bound le k cell flagValue flag physicalOrigin codeOrigin input native current represented source destination loads reached destinationEnd
  exact ⟨after,copyLe,next,stores,run,observed,profileAfter,outside,flagAfter,frame,pbound,cbound⟩

end KProgFormal.ClightRefinement.Arm64KernelMemcpySource
