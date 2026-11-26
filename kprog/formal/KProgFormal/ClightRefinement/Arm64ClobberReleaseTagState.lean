import KProgFormal.ClightRefinement.Arm64ClobberReleaseComplete

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ClobberReleaseTagState

open Arm64Producer Arm64ProducerRegisterStorage
open Arm64ProgramEntryAllocation (world)
open Arm64ClobberMemoryState (Packet)
open Arm64ClobberCoreState (Saved)

private theorem local_load {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial before entry)
    (stored : CC.Mem.store .Mint64 before view.tags.block 0 (.Vlong 0) = some after)
    (id : CC.Ident) (ty : CC.Ty) (block : CC.Block)
    (binding : (allocation initial).1.get id = some (block,ty))
    (notTags : id ≠ tailLocalName 2) (chunk : CC.Chunk) (offset : Int) :
    CC.Mem.load chunk after block offset = CC.Mem.load chunk before block offset := by
  have separate := (allocated_local_storage (CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (allocation initial)).symm)).2
  exact CC.Mem.load_store_other stored chunk block offset (.inl
    (separate _ _ _ _ binding view.tags.binding notTags))

/-- The real offset0 release-tag store retains the generic actual R0,
current architecture storage and source/copied bytes. Its actual zero-byte
effect preserves all24 tag observations through the existing store law. -/
def released {initial seed before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat} (prior : Packet base abi byte rawR0 n before)
    (stored : CC.Mem.store .Mint64 before prior.view.tags.block 0 (.Vlong 0) = some after) :
    Packet base abi byte rawR0 n after := by
  refine {
    view := Arm64MemsetReleaseTagStore.view_after prior.view stored
    stackSame := prior.stackSame
    tagsSame := prior.tagsSame
    resources := Arm64MemsetReleaseTagStore.resources_after prior.view stored prior.resources
    storage := Arm64MemsetReleaseTagStore.storage_after prior.view stored prior.storage
    spAtBase := prior.spAtBase
    r0 := (Arm64MemsetReleaseTagStore.gpr_after prior.view stored prior.storage (0 : Fin 31)).trans prior.r0
    abiHeader := (local_load prior.view stored _ _ _ entry.binding (by decide +kernel) CC.Mptr 704).trans prior.abiHeader
    abiKind := (local_load prior.view stored _ _ _ abi.binding (by decide +kernel) .Mint8unsigned 0).trans prior.abiKind
    tagBytes := ?_
    source := ?_
    copied := ?_ }
  · have zero : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned before prior.view.tags.block (j.val : Int) = some (.Vint 0) := by
      simpa only [prior.tagsSame] using prior.tagBytes
    simpa only [prior.tagsSame] using Arm64MemsetReleaseTagStore.tag_bytes stored zero
  · intro j
    have kept := local_load prior.view stored _ _ _ prior.view.stack.binding (by decide +kernel)
      .Mint8unsigned (64+(j.val : Int))
    rw [prior.stackSame] at kept
    exact kept.trans (prior.source j)
  · intro j limit
    have kept := local_load prior.view stored _ _ _ prior.view.stack.binding (by decide +kernel)
      .Mint8unsigned (80+(j.val : Int))
    rw [prior.stackSame] at kept
    exact kept.trans (prior.copied j limit)

/-- Actual tag-store access and allocation separation preserve the same
eight memcpy locals and the initialized flag in the saved caller packet. -/
def caller_released {initial seed before after : CC.Mem} {entry : HeaderLocal initial} {env : CC.Env}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (prior : Saved env base abi byte rawR0 n cell flagValue before)
    (stored : CC.Mem.store .Mint64 before prior.memory.view.tags.block 0 (.Vlong 0) = some after) :
    Saved env base abi byte rawR0 n cell flagValue after where
  memory := released prior.memory stored
  callee := fun id result binding => (CC.Mem.rangePerm_congr (m1 := after) (m2 := before)
    (fun offset => by simp only [CC.Mem.perm,CC.Mem.store_access stored])).trans (prior.callee id result binding)
  flag := ⟨(local_load prior.memory.view stored _ _ _ entry.binding (by decide +kernel) CC.Mptr 696).trans prior.flag.header,
    (local_load prior.memory.view stored _ _ _ cell.binding (by decide +kernel) .Mint8unsigned 0).trans prior.flag.byte⟩

end KProgFormal.ClightRefinement.Arm64ClobberReleaseTagState
