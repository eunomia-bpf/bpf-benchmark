import KProgFormal.ClightRefinement.Arm64KernelMemcpyTargetEntry

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyTargetView
open Arm64Producer

/-- Actual post-free entry reads, through the exported layout and retained
producer pointer tables. Only the real selected GPR range is named here. -/
structure View (m : CC.Mem) (entry : CC.Block) (returned : Reference.AArch64.State) : Prop where
  r0 : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry 0) 0 = some (.Vlong (-16#64),.Vint (4#32))
  gprs : ∀ j : Fin 18, Arm64EntryMemory.gpr m.nextblock m (.Vptr entry 0) (j.val+1) =
    some (.Vlong (Reference.AArch64.gpr returned ⟨j.val+1,by omega⟩),.Vint 0)
  sp : Arm64EntryMemory.borrowed m.nextblock .Mint64 m (.Vptr entry 0) Arm64Program._sp = some (.Vlong (-32#64))
  flags : Arm64Nop.FlagsRepresent m.nextblock m (.Vptr entry 0) returned
  vectors : ∀ j : Fin 32, Arm64EntryMemory.vector m.nextblock m (.Vptr entry 0) j =
    some (.Vlong ((Reference.AArch64.readVector returned j).setWidth 64),
      .Vlong (((Reference.AArch64.readVector returned j) >>> 64).setWidth 64))

section Packet
variable {initial seed after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {cell : TailLocal initial 5} {flagValue : BitVec 8} {returned : Reference.AArch64.State}
    (packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16
      (Arm64KernelMemcpyProviders.Gprs returned) (Arm64KernelMemcpyProviders.Flags returned)
      (Arm64KernelMemcpyProviders.Vectors returned) cell flagValue after)
include packet

theorem registers (j : Fin 18) : Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) (j.val+1) =
    some (.Vlong (Reference.AArch64.gpr returned ⟨j.val+1,by omega⟩),.Vint 0) := by
  have declarations : ∀ j : Fin 18, (Arm64MemsetClobberRegisters.declaration j).reg.val = j.val+1 := by decide +kernel
  have same : (Arm64MemsetClobberRegisters.declaration j).reg = ⟨j.val+1,by omega⟩ := Fin.ext (declarations j)
  simpa only [Arm64KernelMemcpyProviders.Gprs,Arm64KernelMemcpyProviderRegisters.target,same] using packet.registers j

theorem sp : Arm64EntryMemory.borrowed after.nextblock .Mint64 after (.Vptr entry.block 0)
    Arm64Program._sp = some (.Vlong (-32#64)) := by
  have observed := Arm64ProducerEntryView.header_borrowed_readback after entry.block 5 .Mint64
    packet.memory.storage.sp.block 0 _ packet.memory.storage.spPointer packet.memory.storage.spRead
  change Arm64EntryMemory.borrowed after.nextblock .Mint64 after (.Vptr entry.block 0)
    Arm64Program._sp = some (.Vlong packet.memory.storage.spValue) at observed
  simpa only [packet.memory.spAtBase] using observed

theorem flags : Arm64Nop.FlagsRepresent after.nextblock after (.Vptr entry.block 0) returned := by
  have bit (j : Fin 4) : Arm64EntryMemory.borrowed after.nextblock .Mint8unsigned after (.Vptr entry.block 0)
      (Arm64MemsetClobberFlags.field j) = some (Arm64ProducerEntryView.flagValues returned j) := by
    simpa only [Arm64KernelMemcpyProviders.Flags,Arm64KernelMemcpyProviderFlags.observed] using packet.flagWords j
  have n := bit 0
  have z := bit 1
  have c := bit 2
  have v := bit 3
  change Arm64EntryMemory.borrowed after.nextblock .Mint8unsigned after (.Vptr entry.block 0)
    Arm64Program._n = some (Arm64ProducerEntryView.flagValues returned 0) at n
  change Arm64EntryMemory.borrowed after.nextblock .Mint8unsigned after (.Vptr entry.block 0)
    Arm64Program._z = some (Arm64ProducerEntryView.flagValues returned 1) at z
  change Arm64EntryMemory.borrowed after.nextblock .Mint8unsigned after (.Vptr entry.block 0)
    Arm64Program._c = some (Arm64ProducerEntryView.flagValues returned 2) at c
  change Arm64EntryMemory.borrowed after.nextblock .Mint8unsigned after (.Vptr entry.block 0)
    Arm64Program._v = some (Arm64ProducerEntryView.flagValues returned 3) at v
  change Arm64EntryMemory.flags after.nextblock after (.Vptr entry.block 0) = _
  unfold Arm64EntryMemory.flags
  rw [n,z,c,v]
  rfl

/-- Both genuine post-free pointer-table walks reach the actual low/high
Mint64 words, whose offsets follow the imported producer allocation. -/
theorem vectors (j : Fin 32) : Arm64EntryMemory.vector after.nextblock after (.Vptr entry.block 0) j =
    some (.Vlong ((Reference.AArch64.readVector returned j).setWidth 64),
      .Vlong (((Reference.AArch64.readVector returned j) >>> 64).setWidth 64)) := by
  let low : Fin 64 := ⟨2*j.val,by omega⟩
  let high : Fin 64 := ⟨2*j.val+1,by omega⟩
  have lowOffset : Arm64MemsetClobberVectors.offset low =
      CC.Integers.Ptrofs.unsigned (vectorLoopSourceOffset false j) := by
    rw [Arm64MemsetClobberVectors.source_offsets,(vector_loop_offsets false j).2]
    simp only [low,Bool.false_eq_true,ite_false]
    omega
  have highOffset : Arm64MemsetClobberVectors.offset high =
      CC.Integers.Ptrofs.unsigned (vectorLoopSourceOffset true j) := by
    rw [Arm64MemsetClobberVectors.source_offsets,(vector_loop_offsets true j).2]
    simp only [high,ite_true]
    omega
  have lo := packet.vectors low
  have hi := packet.vectors high
  simp only [Arm64KernelMemcpyProviders.Vectors,lowOffset,highOffset] at lo hi
  rw [Arm64RegisterWrite.storage_vector packet.memory.storage j,lo,hi]
  have halves := Arm64KernelMemcpyProviderVectors.halves returned j
  rw [halves.1,halves.2]
  rw [BitVec.setWidth_ushiftRight_eq_extractLsb,BitVec.setWidth_eq_extractLsb' (by decide)]
  rfl

theorem observe : View after entry.block returned :=
  ⟨packet.memory.r0,registers packet,sp packet,flags packet,vectors packet⟩

end Packet
end KProgFormal.ClightRefinement.Arm64KernelMemcpyTargetView
