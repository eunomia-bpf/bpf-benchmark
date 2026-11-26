import KProgFormal.ClightRefinement.Arm64ProgramEntryLinkWriter

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryLinkWritten
open Arm64Producer
open Arm64ProducerRegisterStorage

private theorem not_link (i : Fin 18) : (Arm64MemsetClobberRegisters.declaration i).reg ≠ (30 : Fin 31) := by
  have all : ∀ i : Fin 18, (Arm64MemsetClobberRegisters.declaration i).reg ≠ (30 : Fin 31) := by decide +kernel
  exact all i
private theorem vector_other : ∀ tags,
    tableCellName tags (30 : Fin 31) ≠ Arm64Entry.___a64_vectors := by decide +kernel
private theorem lr_other : ∀ tags,
    tableCellName tags (30 : Fin 31) ≠ headerSourceName 4 := by decide +kernel

section Effect
variable {initial before after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial before entry}
    (effect : Arm64PointerWrite.Result storage 30 64 (9#8) after)
include effect

/-- Actual current X30 raw word and tag are read from the SAME two stores. -/
theorem link : Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) 30 =
    some (.Vlong 64,.Vint (9#32)) := by
  have read := effect.gpr (30 : Fin 31)
  rw [effect.nextblock]
  have index : (30 : Fin 31).val = 30 := by decide +kernel
  have tag : (9#8).setWidth 32 = (9#32) := by decide +kernel
  simpa only [eq_self,ite_true,index,tag] using read

/-- The original LR local remains64 across the writer's actual X30 stores. -/
theorem lr (cell : HeaderSourceLocal initial 4) :
    CC.Mem.load .Mint64 after cell.block 0 = CC.Mem.load .Mint64 before cell.block 0 :=
  effect.local_load _ _ _ cell.binding (lr_other false) (lr_other true) .Mint64 0

theorem gpr_other (r : Fin 31) (different : r ≠ 30) :
    Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) r.val =
      Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) r.val := by
  rw [effect.nextblock]
  simpa only [ite_eq_right different] using effect.gpr r

/-- Original source/copied bytes, R0/SP/ABI, actual pointers and resource ranges
remain on the SAME incoming packet after its genuine writer effect. -/
def memory {seed : CC.Mem} {base : Arm64MemsetHeaderView.View initial seed entry}
    {abi : TailLocal initial 6} {byte : BitVec 8} {rawR0 : BitVec 64} {n : Nat}
    (prior : Arm64ClobberMemoryState.Packet base abi byte rawR0 n before) (matching : prior.storage = storage) :
    Arm64ClobberMemoryState.Packet base abi byte rawR0 n after := by
  subst storage
  let tail := Arm64ProducerTailFrame.of_kept entry (30 : Fin 31) effect.kept
  refine {
    view := Arm64MemsetHeaderView.of_frame prior.view tail
    stackSame := prior.stackSame
    tagsSame := prior.tagsSame
    resources := Arm64MemsetIterationResources.resources prior.resources tail.header
      (fun block _ => congrArg (CC.PMap.get block) effect.access)
    storage := effect.storage
    spAtBase := prior.spAtBase
    r0 := (gpr_other effect (0 : Fin 31) (by decide)).trans prior.r0
    abiHeader := (tail.header CC.Mptr 704).trans prior.abiHeader
    abiKind := (tail.tail 6 abi .Mint8unsigned 0).trans prior.abiKind
    tagBytes := ?_
    source := ?_
    copied := ?_ }
  · intro j
    have kept := tail.tail 2 ⟨prior.view.tags.block,prior.view.tags.binding⟩ .Mint8unsigned (j.val : Int)
    change CC.Mem.load .Mint8unsigned after prior.view.tags.block (j.val : Int) =
      CC.Mem.load .Mint8unsigned before prior.view.tags.block (j.val : Int) at kept
    rw [prior.tagsSame] at kept
    exact kept.trans (prior.tagBytes j)
  · intro j
    have kept := tail.tail 0 prior.view.stack .Mint8unsigned (64+(j.val : Int))
    rw [prior.stackSame] at kept
    exact kept.trans (prior.source j)
  · intro j limit
    have kept := tail.tail 0 prior.view.stack .Mint8unsigned (80+(j.val : Int))
    rw [prior.stackSame] at kept
    exact kept.trans (prior.copied j limit)

end Effect

/-- Updated CMP flags and all eighteen current provider GPR/tag pairs remain;
X30's NEW raw64/tag9 observation is supplied separately by the real effect. -/
def packet {initial seed before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64}
    {vectors : Fin 64 → BitVec 64} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (prior : Arm64ClobberResult.Packet base abi byte rawR0 n gprs flags vectors cell flagValue before)
    (effect : Arm64PointerWrite.Result prior.memory.storage 30 64 (9#8) after) :
    Arm64ClobberResult.Packet base abi byte rawR0 n gprs flags vectors cell flagValue after where
  memory := memory effect prior.memory rfl
  registers := fun i => (gpr_other effect (Arm64MemsetClobberRegisters.declaration i).reg (not_link i)).trans (prior.registers i)
  flagWords := fun i => by
    have preserved := effect.flag i
    rw [effect.nextblock]
    exact preserved.trans (prior.flagWords i)
  vectors := fun i => (effect.local_load _ _ _ prior.memory.storage.vectors.binding
    (vector_other false) (vector_other true) .Mint64 (Arm64MemsetClobberVectors.offset i)).trans (prior.vectors i)
  flag := prior.flag.tail_frame (Arm64ProducerTailFrame.of_kept entry (30 : Fin 31) effect.kept)

end KProgFormal.ClightRefinement.Arm64ProgramEntryLinkWritten
