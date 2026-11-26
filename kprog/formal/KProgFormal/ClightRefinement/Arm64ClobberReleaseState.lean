import KProgFormal.ClightRefinement.Arm64ClobberCoreState

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ClobberReleaseState

open Arm64Producer Arm64ProducerRegisterStorage
open Arm64ProgramEntryAllocation (world)
open Arm64ClobberMemoryState (Packet)
open Arm64ClobberCoreState (Saved)

private theorem local_load {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial before entry) (i : Fin 64) (value : BitVec 64)
    (stored : CC.Mem.store .Mint8unsigned before view.stack.block (i.val : Int)
      (.Vint ((value.setWidth 8).setWidth 32)) = some after)
    (id : CC.Ident) (ty : CC.Ty) (block : CC.Block)
    (binding : (allocation initial).1.get id = some (block,ty))
    (notStack : id ≠ tailLocalName 0) (chunk : CC.Chunk) (offset : Int) :
    CC.Mem.load chunk after block offset = CC.Mem.load chunk before block offset := by
  have separate := (allocated_local_storage (CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (allocation initial)).symm)).2
  exact CC.Mem.load_store_other stored chunk block offset (.inl
    (separate _ _ _ _ binding view.stack.binding notStack))

/-- One real release-byte store preserves the generic R0 and all current
memory resources. Actual disjoint offsets protect source64..79 and every
copied destination80..95, while original allocation separation protects tags. -/
def released {initial seed before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat} (prior : Packet base abi byte rawR0 n before)
    (i : Fin 64) (value : BitVec 64)
    (stored : CC.Mem.store .Mint8unsigned before prior.view.stack.block (i.val : Int)
      (.Vint ((value.setWidth 8).setWidth 32)) = some after) : Packet base abi byte rawR0 n after := by
  refine {
    view := Arm64MemsetReleaseStore.view_after prior.view i value stored
    stackSame := prior.stackSame
    tagsSame := prior.tagsSame
    resources := Arm64MemsetReleaseStore.resources_after prior.view i value stored prior.resources
    storage := Arm64MemsetReleaseStore.storage_after prior.view i value stored prior.storage
    spAtBase := prior.spAtBase
    r0 := (Arm64MemsetReleaseStore.gpr_after prior.view i value stored prior.storage (0 : Fin 31)).trans prior.r0
    abiHeader := (local_load prior.view i value stored _ _ _ entry.binding (by decide +kernel) CC.Mptr 704).trans prior.abiHeader
    abiKind := (local_load prior.view i value stored _ _ _ abi.binding (by decide +kernel) .Mint8unsigned 0).trans prior.abiKind
    tagBytes := ?_
    source := ?_
    copied := ?_ }
  · intro j
    have kept := (Arm64MemsetReleaseStore.data_tags prior.view i value stored).2 j
    rw [prior.tagsSame] at kept
    exact kept.trans (prior.tagBytes j)
  · intro j
    have kept : CC.Mem.load .Mint8unsigned after base.stack.block (64+(j.val : Int)) =
        CC.Mem.load .Mint8unsigned before base.stack.block (64+(j.val : Int)) := by
      rw [←prior.stackSame]
      apply CC.Mem.load_store_other stored
      right
      right
      have bound := i.isLt
      change (i.val : Int)+1 ≤ 64+(j.val : Int)
      omega
    exact kept.trans (prior.source j)
  · intro j limit
    have kept : CC.Mem.load .Mint8unsigned after base.stack.block (80+(j.val : Int)) =
        CC.Mem.load .Mint8unsigned before base.stack.block (80+(j.val : Int)) := by
      rw [←prior.stackSame]
      apply CC.Mem.load_store_other stored
      right
      right
      have bound := i.isLt
      change (i.val : Int)+1 ≤ 80+(j.val : Int)
      omega
    exact kept.trans (prior.copied j limit)

/-- The actual store also retains memcpy's saved caller, all eight local
Freeable ranges and the same initialized flag through genuine separation. -/
def caller_released {initial seed before after : CC.Mem} {entry : HeaderLocal initial} {env : CC.Env}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (prior : Saved env base abi byte rawR0 n cell flagValue before)
    (i : Fin 64) (value : BitVec 64)
    (stored : CC.Mem.store .Mint8unsigned before prior.memory.view.stack.block (i.val : Int)
      (.Vint ((value.setWidth 8).setWidth 32)) = some after) :
    Saved env base abi byte rawR0 n cell flagValue after where
  memory := released prior.memory i value stored
  callee := fun id result binding => (CC.Mem.rangePerm_congr (m1 := after) (m2 := before)
    (fun offset => by simp only [CC.Mem.perm,CC.Mem.store_access stored])).trans (prior.callee id result binding)
  flag := ⟨(local_load prior.memory.view i value stored _ _ _ entry.binding (by decide +kernel) CC.Mptr 696).trans prior.flag.header,
    (local_load prior.memory.view i value stored _ _ _ cell.binding (by decide +kernel) .Mint8unsigned 0).trans prior.flag.byte⟩

end KProgFormal.ClightRefinement.Arm64ClobberReleaseState
