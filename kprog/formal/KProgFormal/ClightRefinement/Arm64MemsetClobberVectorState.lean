import KProgFormal.ClightRefinement.Arm64MemsetClobberVectors

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetClobberVectorState

open Arm64Producer Arm64ProducerRegisterStorage
open Arm64MemsetClobberVectors (Effect declaration offset)

private theorem table_name : ∀ tags, tableName tags ≠ Arm64Entry.___a64_vectors := by decide +kernel
private theorem cell_name : ∀ tags (j : Fin 31), tableCellName tags j ≠ Arm64Entry.___a64_vectors := by decide +kernel
private theorem flag_name : ∀ j : Fin 4,
    headerSourceName (Arm64ProducerEntryView.flagIndex j) ≠ Arm64Entry.___a64_vectors := by decide +kernel
private theorem tail_name : ∀ j : Fin 9, tailLocalName j ≠ Arm64Entry.___a64_vectors := by decide +kernel

section Effect
variable {initial before after : CC.Mem} {entry : HeaderLocal initial}
    {old : Storage initial before entry} {i : Fin 64} {value : BitVec 64}
    (effect : Effect old i value after)
include effect

theorem local_load (id : CC.Ident) (ty : CC.Ty) (block : CC.Block)
    (binding : (allocation initial).1.get id = some (block,ty)) (different : id ≠ Arm64Entry.___a64_vectors)
    (chunk : CC.Chunk) (ofs : Int) : CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs := by
  have separated := (allocated_local_storage (CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (allocation initial)).symm)).2
  exact CC.Mem.load_store_other effect.stored chunk block ofs
    (.inl (separated _ _ _ _ binding old.vectors.binding different))

def storage : Storage initial after entry where
  tables := old.tables
  roots := fun tags => (local_load effect _ _ _ entry.binding (by decide +kernel) CC.Mptr _).trans (old.roots tags)
  slots := fun tags j => (local_load effect _ _ _ (old.tables tags).binding (table_name tags) CC.Mptr _).trans (old.slots tags j)
  writable := fun tags j => (CC.Mem.validAccess_store_eq effect.stored _ _ _ _).trans (old.writable tags j)
  sp := old.sp
  spPointer := (local_load effect _ _ _ entry.binding (by decide +kernel) CC.Mptr 40).trans old.spPointer
  spValue := old.spValue
  spRead := (local_load effect _ _ _ old.sp.binding (by decide +kernel) .Mint64 0).trans old.spRead
  flags := old.flags
  flagPointers := fun flag => (local_load effect _ _ _ entry.binding (by decide +kernel) CC.Mptr _).trans (old.flagPointers flag)
  flagWritable := fun flag => (CC.Mem.validAccess_store_eq effect.stored _ _ _ _).trans (old.flagWritable flag)
  vectors := old.vectors
  vectorPointers := fun high j => (local_load effect _ _ _ entry.binding (by decide +kernel) CC.Mptr _).trans (old.vectorPointers high j)
  vectorWritable := CC.Mem.rangePerm_store effect.stored old.vectors.block 0 512 .Cur .Writable old.vectorWritable

theorem header (chunk : CC.Chunk) (ofs : Int) :
    CC.Mem.load chunk after entry.block ofs = CC.Mem.load chunk before entry.block ofs :=
  local_load effect _ _ _ entry.binding (by decide +kernel) chunk ofs

theorem tail (j : Fin 9) (cell : TailLocal initial j) (chunk : CC.Chunk) (ofs : Int) :
    CC.Mem.load chunk after cell.block ofs = CC.Mem.load chunk before cell.block ofs :=
  local_load effect _ _ _ cell.binding (tail_name j) chunk ofs

theorem gpr (j : Fin 31) : Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) j.val =
    Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) j.val := by
  rw [Arm64RegisterWrite.storage_gpr (storage effect) j,Arm64RegisterWrite.storage_gpr old j]
  change (do
    let word ← CC.Mem.load .Mint64 after ((old.tables false).cellBlock j) 0
    let tag ← CC.Mem.load .Mint8unsigned after ((old.tables true).cellBlock j) 0
    pure (word,tag)) = _
  rw [local_load effect _ _ _ ((old.tables false).cellBinding j) (cell_name false j) .Mint64 0,
    local_load effect _ _ _ ((old.tables true).cellBinding j) (cell_name true j) .Mint8unsigned 0]

theorem flag (j : Fin 4) : Arm64EntryMemory.borrowed after.nextblock .Mint8unsigned after (.Vptr entry.block 0)
    (Arm64MemsetClobberFlags.field j) =
    Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before (.Vptr entry.block 0) (Arm64MemsetClobberFlags.field j) := by
  unfold Arm64MemsetClobberFlags.field
  rw [Arm64RegisterWrite.storage_flag (storage effect) j,Arm64RegisterWrite.storage_flag old j]
  exact local_load effect _ _ _ (old.flags j).binding (flag_name j) .Mint8unsigned 0

/-- Different halves share the SAME block and retain their values by the
actual disjoint eight-byte offsets, including the other half of one vector. -/
theorem other_half (j : Fin 64) (different : j ≠ i) :
    CC.Mem.load .Mint64 after old.vectors.block (offset j) = CC.Mem.load .Mint64 before old.vectors.block (offset j) := by
  have unequal : j.val ≠ i.val := by intro equal; exact different (Fin.ext equal)
  have separate : offset j + 8 ≤ offset i ∨ offset i + 8 ≤ offset j := by
    rw [Arm64MemsetClobberVectors.source_offsets j,Arm64MemsetClobberVectors.source_offsets i]
    omega
  exact CC.Mem.load_store_other effect.stored .Mint64 old.vectors.block (offset j) (.inr separate)

def view (prior : Arm64MemsetHeaderView.View initial before entry) : Arm64MemsetHeaderView.View initial after entry where
  stack := prior.stack
  tags := prior.tags
  stackPointer := (header effect CC.Mptr 608).trans prior.stackPointer
  tagPointer := (header effect CC.Mptr 648).trans prior.tagPointer
  capacity := (header effect .Mint32 656).trans prior.capacity
  bias := (header effect .Mint64 672).trans prior.bias

theorem resources (prior : Arm64ProgramEntryResources.Resources initial before entry) :
    Arm64ProgramEntryResources.Resources initial after entry :=
  Arm64MemsetIterationResources.resources prior (header effect)
    (fun block _ => congrArg (CC.PMap.get block) effect.access)

def ready {seed : CC.Mem} {base : Arm64MemsetHeaderView.View initial seed entry}
    {abi : TailLocal initial 6} {byte : BitVec 8} {outerLe : CC.TempEnv}
    (prior : Arm64MemsetWriteLoop.Invariant base abi byte 16 before outerLe)
    (same : prior.storage = old) : Arm64MemsetWriteLoop.Invariant base abi byte 16 after outerLe := by
  subst old
  refine {prior with
    view := view effect prior.view
    resources := resources effect prior.resources
    storage := storage effect
    gpr := (gpr effect 0).trans prior.gpr
    abiHeader := (header effect CC.Mptr 704).trans prior.abiHeader
    abiKind := (tail effect 6 abi .Mint8unsigned 0).trans prior.abiKind
    tagBytes := ?_
    written := ?_ }
  · intro j
    have kept := tail effect 2 ⟨prior.view.tags.block,prior.view.tags.binding⟩ .Mint8unsigned (j.val : Int)
    change CC.Mem.load .Mint8unsigned after prior.view.tags.block (j.val : Int) =
      CC.Mem.load .Mint8unsigned before prior.view.tags.block (j.val : Int) at kept
    rw [prior.tagsSame] at kept
    exact kept.trans (prior.tagBytes j)
  · intro j bound
    have kept := tail effect 0 prior.view.stack .Mint8unsigned ((Arm64MemsetStoreExecution.index j).val : Int)
    rw [prior.stackSame] at kept
    exact kept.trans (prior.written j bound)

end Effect

end KProgFormal.ClightRefinement.Arm64MemsetClobberVectorState
