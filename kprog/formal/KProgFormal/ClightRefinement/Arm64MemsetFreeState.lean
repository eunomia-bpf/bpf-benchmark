import KProgFormal.ClightRefinement.Arm64MemsetReturn

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetFreeState

open Arm64Producer Arm64ProducerRegisterStorage

section Retained
variable {initial current after : CC.Mem} {entry : HeaderLocal initial}
    (frontier : CC.Block) (bound : (allocation initial).2.nextblock.toNat ≤ frontier.toNat)
    (frame : FrameBelow frontier current after)
include bound frame

/-- The actual old-block frame transports loads and current rights only on
retained producer locals, while the freed callee permissions may change. -/
theorem local_load (id : CC.Ident) (ty : CC.Ty) (block : CC.Block)
    (binding : (allocation initial).1.get id = some (block,ty)) (chunk : CC.Chunk) (ofs : Int) :
    CC.Mem.load chunk after block ofs = CC.Mem.load chunk current block ofs :=
  frame.load chunk block ofs (Nat.lt_of_lt_of_le
    (Arm64RegisterStorageFrontier.local_owned initial _ _ _ binding) bound)

def storage (old : Storage initial current entry) : Storage initial after entry :=
  Arm64RegisterStorageFrontier.storage_frame old frontier bound frame

theorem header (chunk : CC.Chunk) (ofs : Int) :
    CC.Mem.load chunk after entry.block ofs = CC.Mem.load chunk current entry.block ofs :=
  local_load frontier bound frame _ _ _ entry.binding chunk ofs

theorem tail (j : Fin 9) (cell : TailLocal initial j) (chunk : CC.Chunk) (ofs : Int) :
    CC.Mem.load chunk after cell.block ofs = CC.Mem.load chunk current cell.block ofs :=
  local_load frontier bound frame _ _ _ cell.binding chunk ofs

theorem gpr (old : Storage initial current entry) (j : Fin 31) :
    Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) j.val =
      Arm64EntryMemory.gpr current.nextblock current (.Vptr entry.block 0) j.val := by
  rw [Arm64RegisterWrite.storage_gpr (storage frontier bound frame old) j,Arm64RegisterWrite.storage_gpr old j]
  change (do
    let word ← CC.Mem.load .Mint64 after ((old.tables false).cellBlock j) 0
    let tag ← CC.Mem.load .Mint8unsigned after ((old.tables true).cellBlock j) 0
    pure (word,tag)) = _
  rw [local_load frontier bound frame _ _ _ ((old.tables false).cellBinding j) .Mint64 0,
    local_load frontier bound frame _ _ _ ((old.tables true).cellBinding j) .Mint8unsigned 0]

theorem flag (old : Storage initial current entry) (j : Fin 4) :
    Arm64EntryMemory.borrowed after.nextblock .Mint8unsigned after (.Vptr entry.block 0) (Arm64MemsetClobberFlags.field j) =
      Arm64EntryMemory.borrowed current.nextblock .Mint8unsigned current (.Vptr entry.block 0) (Arm64MemsetClobberFlags.field j) := by
  unfold Arm64MemsetClobberFlags.field
  rw [Arm64RegisterWrite.storage_flag (storage frontier bound frame old) j,Arm64RegisterWrite.storage_flag old j]
  exact local_load frontier bound frame _ _ _ (old.flags j).binding .Mint8unsigned 0

theorem resources (prior : Arm64ProgramEntryResources.Resources initial current entry) :
    Arm64ProgramEntryResources.Resources initial after entry :=
  Arm64MemsetIterationResources.resources prior (header frontier bound frame)
    (fun block owned => (frame block (Nat.lt_of_lt_of_le owned bound)).2)

def view (prior : Arm64MemsetHeaderView.View initial current entry) : Arm64MemsetHeaderView.View initial after entry :=
  Arm64MemsetHeaderView.of_frame prior (Arm64ProducerTailFrame.of_frame entry frontier bound frame)

def ready {seed : CC.Mem} {base : Arm64MemsetHeaderView.View initial seed entry}
    {abi : TailLocal initial 6} {byte : BitVec 8} {outerLe : CC.TempEnv}
    (prior : Arm64MemsetWriteLoop.Invariant base abi byte 16 current outerLe) :
    Arm64MemsetWriteLoop.Invariant base abi byte 16 after outerLe := by
  refine {prior with
    view := view frontier bound frame prior.view
    resources := resources frontier bound frame prior.resources
    storage := storage frontier bound frame prior.storage
    gpr := (gpr frontier bound frame prior.storage 0).trans prior.gpr
    abiHeader := (header frontier bound frame CC.Mptr 704).trans prior.abiHeader
    abiKind := (tail frontier bound frame 6 abi .Mint8unsigned 0).trans prior.abiKind
    tagBytes := ?_
    written := ?_ }
  · intro j
    have kept := tail frontier bound frame 2 ⟨prior.view.tags.block,prior.view.tags.binding⟩ .Mint8unsigned (j.val : Int)
    change CC.Mem.load .Mint8unsigned after prior.view.tags.block (j.val : Int) =
      CC.Mem.load .Mint8unsigned current prior.view.tags.block (j.val : Int) at kept
    rw [prior.tagsSame] at kept
    exact kept.trans (prior.tagBytes j)
  · intro j limit
    have kept := tail frontier bound frame 0 prior.view.stack .Mint8unsigned ((Arm64MemsetStoreExecution.index j).val : Int)
    rw [prior.stackSame] at kept
    exact kept.trans (prior.written j limit)

/-- All actual provider word observations survive the real local free on
their retained producer blocks at the genuine caller frontier. -/
def complete {seed : CC.Mem} {base : Arm64MemsetHeaderView.View initial seed entry}
    {abi : TailLocal initial 6} {byte : BitVec 8} {outerLe helperLe : CC.TempEnv}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (prior : Arm64MemsetClobberVectorsComplete.Invariant base abi byte outerLe gprs flags 64 values current helperLe) :
    Arm64MemsetClobberVectorsComplete.Invariant base abi byte outerLe gprs flags 64 values after helperLe where
  flagsPacket := {
    registers := {
      ready := ready frontier bound frame prior.flagsPacket.registers.ready
      parameter := prior.flagsPacket.registers.parameter
      written := fun j limit => (gpr frontier bound frame prior.flagsPacket.registers.ready.storage
        (Arm64MemsetClobberRegisters.declaration j).reg).trans (prior.flagsPacket.registers.written j limit) }
    written := fun j limit => (flag frontier bound frame prior.flagsPacket.registers.ready.storage j).trans
      (prior.flagsPacket.written j limit) }
  written := by
    intro j limit
    have block : (ready frontier bound frame prior.flagsPacket.registers.ready).storage.vectors.block =
        prior.flagsPacket.registers.ready.storage.vectors.block := by
      unfold ready storage Arm64RegisterStorageFrontier.storage_frame
      rfl
    change CC.Mem.load .Mint64 after (ready frontier bound frame prior.flagsPacket.registers.ready).storage.vectors.block
      (Arm64MemsetClobberVectors.offset j) = _
    rw [block]
    exact (local_load frontier bound frame _ _ _ prior.flagsPacket.registers.ready.storage.vectors.binding
      .Mint64 (Arm64MemsetClobberVectors.offset j)).trans (prior.written j limit)

end Retained

end KProgFormal.ClightRefinement.Arm64MemsetFreeState
