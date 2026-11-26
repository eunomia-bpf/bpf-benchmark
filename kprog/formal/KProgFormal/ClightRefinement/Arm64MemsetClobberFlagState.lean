import KProgFormal.ClightRefinement.Arm64MemsetClobberFlags

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetClobberFlagState

open Arm64Producer Arm64ProducerRegisterStorage
open Arm64ProducerEntryView (flagIndex)
open Arm64MemsetClobberFlags (Effect)

def name (i : Fin 4) : CC.Ident := headerSourceName (flagIndex i)
private theorem header_name : ∀ i : Fin 4, Arm64Entry._entry ≠ name i := by decide +kernel
private theorem table_name : ∀ (tags : Bool) (i : Fin 4), tableName tags ≠ name i := by decide +kernel
private theorem sp_name : ∀ i : Fin 4, headerSourceName 5 ≠ name i := by decide +kernel
private theorem cell_name : ∀ (tags : Bool) (j : Fin 31) (i : Fin 4), tableCellName tags j ≠ name i := by decide +kernel
private theorem tail_name : ∀ (j : Fin 9) (i : Fin 4), tailLocalName j ≠ name i := by decide +kernel
private theorem flag_name : ∀ i j : Fin 4, j ≠ i → name j ≠ name i := by decide +kernel

section Effect
variable {initial before after : CC.Mem} {entry : HeaderLocal initial}
    {old : Storage initial before entry} {i : Fin 4} {value : BitVec 64}
    (effect : Effect old i value after)
include effect

/-- The actual flag byte store preserves every load from a differently named
producer local, using the original allocation bindings to separate blocks. -/
theorem local_load (id : CC.Ident) (ty : CC.Ty) (block : CC.Block)
    (binding : (allocation initial).1.get id = some (block,ty)) (different : id ≠ name i)
    (chunk : CC.Chunk) (offset : Int) :
    CC.Mem.load chunk after block offset = CC.Mem.load chunk before block offset := by
  have separated := (allocated_local_storage (CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (allocation initial)).symm)).2
  exact CC.Mem.load_store_other effect.stored chunk block offset
    (.inl (separated _ _ _ _ binding (old.flags i).binding different))

def storage : Storage initial after entry where
  tables := old.tables
  roots := fun tags => (local_load effect _ _ _ entry.binding (header_name i) CC.Mptr _).trans (old.roots tags)
  slots := fun tags j => (local_load effect _ _ _ (old.tables tags).binding (table_name tags i) CC.Mptr _).trans (old.slots tags j)
  writable := fun tags j => (CC.Mem.validAccess_store_eq effect.stored _ _ _ _).trans (old.writable tags j)
  sp := old.sp
  spPointer := (local_load effect _ _ _ entry.binding (header_name i) CC.Mptr 40).trans old.spPointer
  spValue := old.spValue
  spRead := (local_load effect _ _ _ old.sp.binding (sp_name i) .Mint64 0).trans old.spRead
  flags := old.flags
  flagPointers := fun flag => (local_load effect _ _ _ entry.binding (header_name i) CC.Mptr _).trans (old.flagPointers flag)
  flagWritable := fun flag => (CC.Mem.validAccess_store_eq effect.stored _ _ _ _).trans (old.flagWritable flag)
  vectors := old.vectors
  vectorPointers := fun high j => (local_load effect _ _ _ entry.binding (header_name i) CC.Mptr _).trans (old.vectorPointers high j)
  vectorWritable := (CC.Mem.rangePerm_congr (m1 := after) (m2 := before)
    (fun offset => by simp only [CC.Mem.perm,effect.access])).trans old.vectorWritable

theorem header (chunk : CC.Chunk) (offset : Int) :
    CC.Mem.load chunk after entry.block offset = CC.Mem.load chunk before entry.block offset :=
  local_load effect _ _ _ entry.binding (header_name i) chunk offset

theorem tail (j : Fin 9) (cell : TailLocal initial j) (chunk : CC.Chunk) (offset : Int) :
    CC.Mem.load chunk after cell.block offset = CC.Mem.load chunk before cell.block offset :=
  local_load effect _ _ _ cell.binding (tail_name j i) chunk offset

theorem gpr (j : Fin 31) : Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) j.val =
    Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) j.val := by
  rw [Arm64RegisterWrite.storage_gpr (storage effect) j,Arm64RegisterWrite.storage_gpr old j]
  change (do
    let word ← CC.Mem.load .Mint64 after ((old.tables false).cellBlock j) 0
    let tag ← CC.Mem.load .Mint8unsigned after ((old.tables true).cellBlock j) 0
    pure (word,tag)) = _
  rw [local_load effect _ _ _ ((old.tables false).cellBinding j) (cell_name false j i) .Mint64 0,
    local_load effect _ _ _ ((old.tables true).cellBinding j) (cell_name true j i) .Mint8unsigned 0]

theorem selected : Arm64EntryMemory.borrowed after.nextblock .Mint8unsigned after (.Vptr entry.block 0)
    (Arm64MemsetClobberFlags.field i) = some (.Vint (flagWord value)) :=
  (Arm64RegisterWrite.storage_flag (storage effect) i).trans effect.read

theorem other_flag (j : Fin 4) (different : j ≠ i) :
    Arm64EntryMemory.borrowed after.nextblock .Mint8unsigned after (.Vptr entry.block 0)
      (Arm64MemsetClobberFlags.field j) =
    Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before (.Vptr entry.block 0)
      (Arm64MemsetClobberFlags.field j) := by
  unfold Arm64MemsetClobberFlags.field
  rw [Arm64RegisterWrite.storage_flag (storage effect) j,Arm64RegisterWrite.storage_flag old j]
  exact local_load effect _ _ _ (old.flags j).binding (flag_name i j different) .Mint8unsigned 0

theorem vector (chunk : CC.Chunk) (offset : Int) :
    CC.Mem.load chunk after old.vectors.block offset = CC.Mem.load chunk before old.vectors.block offset := by
  have other : ∀ i : Fin 4, Arm64Entry.___a64_vectors ≠ name i := by decide +kernel
  exact local_load effect _ _ _ old.vectors.binding (other i) chunk offset

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

end KProgFormal.ClightRefinement.Arm64MemsetClobberFlagState
