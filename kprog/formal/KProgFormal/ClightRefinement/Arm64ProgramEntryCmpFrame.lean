import KProgFormal.ClightRefinement.Arm64ProgramEntryCmpStores

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryCmpFrame
open Arm64Producer
open Arm64ProducerRegisterStorage
open Arm64Compare.Stores (Effect flagIndex)

private theorem header_other : ∀ i : Fin 4,
    headerSourceName (Arm64ProducerEntryView.flagIndex (flagIndex i)) ≠ Arm64Entry._entry := by decide +kernel
private theorem tail_other : ∀ (j : Fin 9) (i : Fin 4),
    headerSourceName (Arm64ProducerEntryView.flagIndex (flagIndex i)) ≠ tailLocalName j := by decide +kernel
private theorem cell_other : ∀ (tags : Bool) (r : Fin 31) (i : Fin 4),
    headerSourceName (Arm64ProducerEntryView.flagIndex (flagIndex i)) ≠ tableCellName tags r := by decide +kernel
private theorem vectors_other : ∀ i : Fin 4,
    headerSourceName (Arm64ProducerEntryView.flagIndex (flagIndex i)) ≠ Arm64Entry.___a64_vectors := by decide +kernel

section Effect
variable {initial before after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial before entry} {lhs rhs result sign : BitVec 64}
    (effect : Effect storage lhs rhs result sign after)
include effect

/-- All real header and tail locals, including copied bytes and initialized
ABI/is_xdp cells, survive these four different allocated flag-cell stores. -/
theorem tailFrame : Arm64ProducerTailFrame.Frame initial entry before after :=
  ⟨fun chunk ofs => effect.local_load _ _ _ entry.binding header_other chunk ofs,
   fun j cell chunk ofs => effect.local_load _ _ _ cell.binding (tail_other j) chunk ofs⟩

/-- Exact original raw GPR/tag pointer walks at the actual current frontier. -/
theorem gpr (r : Fin 31) :
    Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) r.val =
      Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) r.val := by
  rw [Arm64RegisterWrite.storage_gpr effect.storage r,Arm64RegisterWrite.storage_gpr storage r]
  change (do
    let word ← CC.Mem.load .Mint64 after ((storage.tables false).cellBlock r) 0
    let tag ← CC.Mem.load .Mint8unsigned after ((storage.tables true).cellBlock r) 0
    pure (word,tag)) = _
  rw [effect.local_load _ _ _ ((storage.tables false).cellBinding r) (cell_other false r) .Mint64 0,
      effect.local_load _ _ _ ((storage.tables true).cellBinding r) (cell_other true r) .Mint8unsigned 0]

/-- The SAME complete current memory packet is transported through the actual
four stores; its original ABI, tags, SP, R0 and all copied/source bytes remain. -/
def memory {seed : CC.Mem} {base : Arm64MemsetHeaderView.View initial seed entry}
    {abi : TailLocal initial 6} {byte : BitVec 8} {rawR0 : BitVec 64} {n : Nat}
    (prior : Arm64ClobberMemoryState.Packet base abi byte rawR0 n before) (matching : prior.storage = storage) :
    Arm64ClobberMemoryState.Packet base abi byte rawR0 n after := by
  subst storage
  let tail := tailFrame effect
  let view := Arm64MemsetHeaderView.of_frame prior.view tail
  refine {
    view := view
    stackSame := prior.stackSame
    tagsSame := prior.tagsSame
    resources := Arm64MemsetIterationResources.resources prior.resources tail.header
      (fun block _ => congrArg (CC.PMap.get block) effect.access)
    storage := effect.storage
    spAtBase := prior.spAtBase
    r0 := (gpr effect (0 : Fin 31)).trans prior.r0
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

/-- Every actual vector-half observation survives the same real stores. -/
theorem vector (chunk : CC.Chunk) (ofs : CC.Z) :
    CC.Mem.load chunk after effect.storage.vectors.block ofs =
      CC.Mem.load chunk before storage.vectors.block ofs :=
  effect.local_load _ _ _ storage.vectors.binding vectors_other chunk ofs

end Effect
end KProgFormal.ClightRefinement.Arm64ProgramEntryCmpFrame
