import KProgFormal.ClightRefinement.Arm64MemcpyReturn
import KProgFormal.ClightRefinement.Arm64MemsetFreeState

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ClobberResult

open Arm64Producer Arm64ProducerRegisterStorage

/-- Current semantic observations remain after the callee locals are freed.
The actual provider maps stay explicit while the callee's rights are released. -/
structure Packet {initial seed : CC.Mem} {entry : HeaderLocal initial}
    (base : Arm64MemsetHeaderView.View initial seed entry) (abi : TailLocal initial 6) (byte : BitVec 8)
    (rawR0 : BitVec 64) (copiedN : Nat) (gprs : Fin 18 → BitVec 64)
    (flags : Fin 4 → BitVec 64) (values : Fin 64 → BitVec 64)
    (cell : TailLocal initial 5) (flagValue : BitVec 8) (m : CC.Mem) where
  memory : Arm64ClobberMemoryState.Packet base abi byte rawR0 copiedN m
  registers : ∀ j : Fin 18, Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0)
    (Arm64MemsetClobberRegisters.declaration j).reg.val = some (.Vlong (gprs j),.Vint 0)
  flagWords : ∀ j : Fin 4, Arm64EntryMemory.borrowed m.nextblock .Mint8unsigned m (.Vptr entry.block 0)
    (Arm64MemsetClobberFlags.field j) = some (.Vint (flagWord (flags j)))
  vectors : ∀ j : Fin 64, CC.Mem.load .Mint64 m memory.storage.vectors.block
    (Arm64MemsetClobberVectors.offset j) = some (.Vlong (values j))
  flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue m

def of_complete {initial seed calleeBefore m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {copiedN : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe helperLe : CC.TempEnv} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (prior : Arm64ClobberVectorsComplete.Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe
      gprs flags 64 values m helperLe) : Packet base abi byte rawR0 copiedN gprs flags values cell flagValue m where
  memory := prior.flagsPacket.registers.ready.memory
  registers := fun j => prior.flagsPacket.registers.written j j.isLt
  flagWords := fun j => prior.flagsPacket.written j j.isLt
  vectors := fun j => prior.written j j.isLt
  flag := prior.flagsPacket.registers.ready.flag

section Frame
variable {initial seed before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {copiedN : Nat}
    (frontier : CC.Block) (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ frontier.toNat)
    (frame : FrameBelow frontier before after)
include bound frame

/-- The original retained-local frame preserves the same source/copied bytes,
ABI, tags, SP and actual R0 across a real later-callee free. -/
def memory_retained (prior : Arm64ClobberMemoryState.Packet base abi byte rawR0 copiedN before) :
    Arm64ClobberMemoryState.Packet base abi byte rawR0 copiedN after := by
  refine {
    view := Arm64MemsetFreeState.view frontier bound frame prior.view
    stackSame := prior.stackSame
    tagsSame := prior.tagsSame
    resources := Arm64MemsetFreeState.resources frontier bound frame prior.resources
    storage := Arm64MemsetFreeState.storage frontier bound frame prior.storage
    spAtBase := prior.spAtBase
    r0 := (Arm64MemsetFreeState.gpr frontier bound frame prior.storage 0).trans prior.r0
    abiHeader := (Arm64MemsetFreeState.header frontier bound frame CC.Mptr 704).trans prior.abiHeader
    abiKind := (Arm64MemsetFreeState.tail frontier bound frame 6 abi .Mint8unsigned 0).trans prior.abiKind
    tagBytes := ?_
    source := ?_
    copied := ?_ }
  · intro j
    have kept := Arm64MemsetFreeState.tail frontier bound frame 2 ⟨prior.view.tags.block,prior.view.tags.binding⟩
      .Mint8unsigned (j.val : Int)
    change CC.Mem.load .Mint8unsigned after prior.view.tags.block (j.val : Int) =
      CC.Mem.load .Mint8unsigned before prior.view.tags.block (j.val : Int) at kept
    rw [prior.tagsSame] at kept
    exact kept.trans (prior.tagBytes j)
  · intro j
    have kept := Arm64MemsetFreeState.tail frontier bound frame 0 prior.view.stack .Mint8unsigned (64+(j.val : Int))
    rw [prior.stackSame] at kept
    exact kept.trans (prior.source j)
  · intro j limit
    have kept := Arm64MemsetFreeState.tail frontier bound frame 0 prior.view.stack .Mint8unsigned (80+(j.val : Int))
    rw [prior.stackSame] at kept
    exact kept.trans (prior.copied j limit)

/-- All actual provider maps and the same initialized flag survive on the
retained producer blocks through the actual local-free frame. -/
def retained {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (prior : Packet base abi byte rawR0 copiedN gprs flags values cell flagValue before) :
    Packet base abi byte rawR0 copiedN gprs flags values cell flagValue after where
  memory := memory_retained frontier bound frame prior.memory
  registers := fun j => (Arm64MemsetFreeState.gpr frontier bound frame prior.memory.storage
    (Arm64MemsetClobberRegisters.declaration j).reg).trans (prior.registers j)
  flagWords := fun j => (Arm64MemsetFreeState.flag frontier bound frame prior.memory.storage j).trans (prior.flagWords j)
  vectors := fun j => (Arm64MemsetFreeState.local_load frontier bound frame _ _ _ prior.memory.storage.vectors.binding
    .Mint64 (Arm64MemsetClobberVectors.offset j)).trans (prior.vectors j)
  flag := prior.flag.tail_frame (Arm64ProducerTailFrame.of_frame entry frontier bound frame)

end Frame

end KProgFormal.ClightRefinement.Arm64ClobberResult
