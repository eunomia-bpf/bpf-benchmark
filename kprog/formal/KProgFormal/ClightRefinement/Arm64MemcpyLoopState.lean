import KProgFormal.ClightRefinement.Arm64MemcpyCopyEntry

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyLoopState

open Arm64Producer Arm64ProducerRegisterStorage
open Arm64ProgramEntryAllocation (world)

private theorem frame_sp {initial current finalMem : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial current entry) (frontier : CC.Block)
    (bound : (allocation initial).2.nextblock.toNat ≤ frontier.toNat) (frame : FrameBelow frontier current finalMem) :
    (Arm64MemsetFreeState.storage frontier bound frame storage).spValue = storage.spValue := by
  unfold Arm64MemsetFreeState.storage Arm64RegisterStorageFrontier.storage_frame
  rfl

/-- Any actual old-block allocation/free frame transports the existing raw
word packet and current producer rights at its genuine memory frontier. -/
def packet_frame {initial seed before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (frontier : CC.Block) (bound : (allocation initial).2.nextblock.toNat ≤ frontier.toNat)
    (frame : FrameBelow frontier before after)
    (prior : Arm64MemsetPointerState.Packet base abi byte gprs flags values before) :
    Arm64MemsetPointerState.Packet base abi byte gprs flags values after := by
  refine {
    view := Arm64MemsetFreeState.view frontier bound frame prior.view
    stackSame := prior.stackSame
    tagsSame := prior.tagsSame
    resources := Arm64MemsetFreeState.resources frontier bound frame prior.resources
    storage := Arm64MemsetFreeState.storage frontier bound frame prior.storage
    spAtBase := (frame_sp prior.storage frontier bound frame).trans prior.spAtBase
    r0 := (Arm64MemsetFreeState.gpr frontier bound frame prior.storage 0).trans prior.r0
    r1 := (Arm64MemsetFreeState.gpr frontier bound frame prior.storage 1).trans prior.r1
    abiHeader := (Arm64MemsetFreeState.header frontier bound frame CC.Mptr 704).trans prior.abiHeader
    abiKind := (Arm64MemsetFreeState.tail frontier bound frame 6 abi .Mint8unsigned 0).trans prior.abiKind
    tagBytes := ?_
    written := ?_
    registers := fun j positive => (Arm64MemsetFreeState.gpr frontier bound frame prior.storage
      (Arm64MemsetClobberRegisters.declaration j).reg).trans (prior.registers j positive)
    flags := fun j => (Arm64MemsetFreeState.flag frontier bound frame prior.storage j).trans (prior.flags j)
    vectors := ?_ }
  · intro j
    have kept := Arm64MemsetFreeState.tail frontier bound frame 2 ⟨prior.view.tags.block,prior.view.tags.binding⟩ .Mint8unsigned (j.val : Int)
    change CC.Mem.load .Mint8unsigned after prior.view.tags.block (j.val : Int) =
      CC.Mem.load .Mint8unsigned before prior.view.tags.block (j.val : Int) at kept
    rw [prior.tagsSame] at kept
    exact kept.trans (prior.tagBytes j)
  · intro j
    have kept := Arm64MemsetFreeState.tail frontier bound frame 0 prior.view.stack .Mint8unsigned
      ((Arm64MemsetStoreExecution.index j).val : Int)
    rw [prior.stackSame] at kept
    exact kept.trans (prior.written j)
  · intro j
    change CC.Mem.load .Mint64 after prior.storage.vectors.block (Arm64MemsetClobberVectors.offset j) = _
    exact (Arm64MemsetFreeState.local_load frontier bound frame _ _ _ prior.storage.vectors.binding
      .Mint64 (Arm64MemsetClobberVectors.offset j)).trans (prior.vectors j)

/-- Original memcpy loop observations, source data, current resources and
actual copied destination bytes on the same reached heap. -/
structure Invariant {initial seed : CC.Mem} {entry : HeaderLocal initial}
    (base : Arm64MemsetHeaderView.View initial seed entry) (abi : TailLocal initial 6) (byte : BitVec 8)
    (gprs : Fin 18 → BitVec 64) (flags : Fin 4 → BitVec 64) (values : Fin 64 → BitVec 64)
    (calleeBefore : CC.Mem) (n : Nat) (m : CC.Mem) (le : CC.TempEnv) where
  packet : Arm64MemsetPointerState.Packet base abi byte gprs flags values m
  callee : ∀ id value, (Arm64MemcpySource.allocation calleeBefore).1.get id = some value →
    CC.Mem.rangePerm m value.1 0 (CC.sizeof world.genv_cenv value.2) .Cur .Freeable = true
  entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0)
  length : le.get Arm64Program.___a64_lib_len = some (.Vlong (16#64))
  counter : le.get Arm64Program.___a64_lib_i = some (.Vlong (BitVec.ofNat 64 n))
  sourceTag : le.get Arm64Program.___a64_lib_src_tag = some (.Vint ((4#8).setWidth 32))
  copied : ∀ j : Fin 16, j.val < n → CC.Mem.load .Mint8unsigned m base.stack.block
    (80 + (j.val : Int)) = some (.Vint (byte.setWidth 32))

/-- The preceding same actual packet supplies length16 and source R1/tag4.
Real memcpy entry, reads, guards and initializer reach iteration0 in119 steps. -/
theorem original {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (prior : Arm64MemsetPointerState.Packet base abi byte (Arm64MemcpyLengthState.words gprs) flags values before)
    (bound : (allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat) (k : CC.Cont) :
    ∃ le, ∃ _current : Invariant base abi byte (Arm64MemcpyLengthState.words gprs) flags values before 0
        (Arm64MemcpySource.allocation before).2 le,
      InternalRun world 119 (.Callstate (.Internal Arm64MemcpySource.handler) [.Vptr entry.block 0] k before)
        (.State Arm64MemcpySource.handler Arm64MemcpyCopyEntry.loop
          (Arm64MemcpyCopyEntry.continuation (Arm64MemcpySource.continuation k))
          (Arm64MemcpySource.allocation before).1 le (Arm64MemcpySource.allocation before).2) := by
  let current := packet_frame before.nextblock bound (Arm64MemcpySource.entry_frame before) prior
  let le := Arm64MemcpySource.lengthTemps entry.block (16#64)
  let tagLe := Arm64MemcpySourceTag.finalTemps le (current.storage.tables true).tableBlock
    ((current.storage.tables true).cellBlock 1) (4#8)
  let finalLe := Arm64MemcpyCopyEntry.temps tagLe
  have entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0) := by
    simp +decide only [le,Arm64MemcpySource.lengthTemps,Arm64MemcpySource.initialTemps,CC.PTree.gso,CC.PTree.gss]
  have length : le.get Arm64Program.___a64_lib_len = some (.Vlong (16#64)) := by
    simp only [le,Arm64MemcpySource.lengthTemps,CC.PTree.gss]
  have entryRun := Arm64MemcpySource.current_length prior k
  have sourceRun := Arm64MemcpyCopyEntry.ready current.storage (Arm64MemcpySource.allocation before).1 le
    (Arm64MemcpySource.continuation k) entryRead length current.r1
  have tagReads := Arm64MemcpySourceTag.observations le (current.storage.tables true).tableBlock
    ((current.storage.tables true).cellBlock 1) (4#8)
  have finalReads := Arm64MemcpyCopyEntry.observations tagLe
  refine ⟨finalLe,?_,entryRun.trans sourceRun⟩
  refine {
    packet := current
    callee := ?_
    entryRead := finalReads.1.trans (tagReads.1.trans entryRead)
    length := finalReads.2.1.trans (tagReads.2.1.trans length)
    counter := finalReads.2.2.2
    sourceTag := finalReads.2.2.1.trans tagReads.2.2
    copied := ?_ }
  · intro id value binding
    exact ((allocated_local_storage (Arm64MemcpySource.allocated before)).1 id value binding).2.2
  · intro j impossible
    omega

end KProgFormal.ClightRefinement.Arm64MemcpyLoopState
