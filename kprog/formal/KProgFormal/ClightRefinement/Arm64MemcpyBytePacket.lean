import KProgFormal.ClightRefinement.Arm64MemcpyByteStorage

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyBytePacket

open Arm64Producer Arm64ProducerRegisterStorage
open Arm64ProgramEntryAllocation (world)

private theorem source_before_destination : ∀ i j : Fin 16,
    (Arm64MemsetStoreExecution.index j).val < 80+i.val := by decide +kernel

/-- The actual destination byte is disjoint from all sixteen earlier
source bytes and from each original register, flag, vector and tag local. -/
def packet {initial seed before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (prior : Arm64MemsetPointerState.Packet base abi byte gprs flags values before) (i : Fin 16)
    (stored : CC.Mem.store .Mint8unsigned before base.stack.block (80+(i.val : Int)) (.Vint (byte.setWidth 32)) = some after) :
    Arm64MemsetPointerState.Packet base abi byte gprs flags values after := by
  have header (chunk : CC.Chunk) (ofs : Int) := Arm64MemcpyByteStorage.local_load base.stack
    (80+(i.val : Int)) byte stored _ _ _ entry.binding (by decide +kernel) chunk ofs
  let view : Arm64MemsetHeaderView.View initial after entry :=
    ⟨prior.view.stack,prior.view.tags,(header CC.Mptr 608).trans prior.view.stackPointer,
      (header CC.Mptr 648).trans prior.view.tagPointer,(header .Mint32 656).trans prior.view.capacity,
      (header .Mint64 672).trans prior.view.bias⟩
  let storage := Arm64MemcpyByteStorage.storage base.stack (80+(i.val : Int)) byte stored prior.storage
  refine {
    view := view
    stackSame := prior.stackSame
    tagsSame := prior.tagsSame
    resources := Arm64MemsetIterationResources.resources prior.resources header
      (fun block _ => congrArg (CC.PMap.get block) (CC.Mem.store_access stored))
    storage := storage
    spAtBase := prior.spAtBase
    r0 := (Arm64MemcpyByteStorage.gpr base.stack (80+(i.val : Int)) byte stored prior.storage 0).trans prior.r0
    r1 := (Arm64MemcpyByteStorage.gpr base.stack (80+(i.val : Int)) byte stored prior.storage 1).trans prior.r1
    abiHeader := (header CC.Mptr 704).trans prior.abiHeader
    abiKind := (Arm64MemcpyByteStorage.local_load base.stack (80+(i.val : Int)) byte stored _ _ _
      abi.binding (by decide +kernel) .Mint8unsigned 0).trans prior.abiKind
    tagBytes := ?_
    written := ?_
    registers := fun j positive => (Arm64MemcpyByteStorage.gpr base.stack (80+(i.val : Int)) byte stored
      prior.storage (Arm64MemsetClobberRegisters.declaration j).reg).trans (prior.registers j positive)
    flags := ?_
    vectors := ?_ }
  · intro j
    exact (Arm64MemcpyByteStorage.local_load base.stack (80+(i.val : Int)) byte stored _ _ _
      base.tags.binding (by decide +kernel) .Mint8unsigned (j.val : Int)).trans (prior.tagBytes j)
  · intro j
    have order := source_before_destination i j
    exact (CC.Mem.load_store_other stored .Mint8unsigned base.stack.block
      ((Arm64MemsetStoreExecution.index j).val : Int)
      (.inr (.inl (by change ((Arm64MemsetStoreExecution.index j).val : Int)+1 ≤ 80+(i.val : Int); omega)))).trans
      (prior.written j)
  · intro j
    have kept : Arm64EntryMemory.borrowed after.nextblock .Mint8unsigned after (.Vptr entry.block 0)
        (Arm64MemsetClobberFlags.field j) =
        Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before (.Vptr entry.block 0)
          (Arm64MemsetClobberFlags.field j) := by
      unfold Arm64MemsetClobberFlags.field
      rw [Arm64RegisterWrite.storage_flag storage j,Arm64RegisterWrite.storage_flag prior.storage j]
      have different : ∀ j : Fin 4, headerSourceName (Arm64ProducerEntryView.flagIndex j) ≠ tailLocalName 0 := by decide +kernel
      exact Arm64MemcpyByteStorage.local_load base.stack (80+(i.val : Int)) byte stored _ _ _
        (prior.storage.flags j).binding (different j) .Mint8unsigned 0
    exact kept.trans (prior.flags j)
  · intro j
    change CC.Mem.load .Mint64 after prior.storage.vectors.block (Arm64MemsetClobberVectors.offset j) = _
    exact (Arm64MemcpyByteStorage.local_load base.stack (80+(i.val : Int)) byte stored _ _ _
      prior.storage.vectors.binding (by decide +kernel) .Mint64 (Arm64MemsetClobberVectors.offset j)).trans (prior.vectors j)

/-- Before the real counter increment, the actual byte store retains the
same current iteration and every already copied earlier destination byte. -/
def current {initial seed calleeBefore before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64} {le : CC.TempEnv}
    (i : Fin 16)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val before le)
    (stored : CC.Mem.store .Mint8unsigned before base.stack.block (80+(i.val : Int)) (.Vint (byte.setWidth 32)) = some after) :
    Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val after le := by
  refine {
    packet := packet prior.packet i stored
    callee := ?_
    entryRead := prior.entryRead
    length := prior.length
    counter := prior.counter
    sourceTag := prior.sourceTag
    copied := ?_ }
  · intro id value binding
    exact (CC.Mem.rangePerm_congr (m1:=after) (m2:=before)
      (fun ofs => by simp only [CC.Mem.perm,CC.Mem.store_access stored])).trans (prior.callee id value binding)
  · intro j limit
    exact (CC.Mem.load_store_other stored .Mint8unsigned base.stack.block (80+(j.val : Int))
      (.inr (.inl (by change 80+(j.val : Int)+1 ≤ 80+(i.val : Int); omega)))).trans (prior.copied j limit)

end KProgFormal.ClightRefinement.Arm64MemcpyBytePacket
