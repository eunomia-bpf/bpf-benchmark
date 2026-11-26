import KProgFormal.ClightRefinement.Arm64MemsetClobberRegisterStores

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetClobberRegisterState

open Arm64Producer Arm64ProducerRegisterStorage
open Arm64MemsetClobberRegisters (declaration)
open Arm64MemsetClobberRegisterStores (Effect)

private theorem cell_header : ∀ tags (i : Fin 31),
    tableCellName tags i ≠ Arm64Entry._entry := by decide +kernel
private theorem cell_table : ∀ tags selected (i : Fin 31),
    tableCellName tags i ≠ tableName selected := by decide +kernel
private theorem cell_sp : ∀ tags (i : Fin 31),
    tableCellName tags i ≠ headerSourceName 5 := by decide +kernel
private theorem cell_tail : ∀ tags (i : Fin 31) (j : Fin 9),
    tableCellName tags i ≠ tailLocalName j := by decide +kernel

section Effect
variable {initial before after : CC.Mem} {entry : HeaderLocal initial}
    {old : Storage initial before entry} {i : Fin 18} {value : BitVec 64}
    (effect : Effect old i value after)
include effect

/-- Retain the same real tables, cells, SP, flags, vectors and write rights
after the two original inline stores, while selected register data changes. -/
def storage : Storage initial after entry where
  tables := old.tables
  roots := fun tags => (effect.local_load _ _ _ entry.binding
    (cell_header false _) (cell_header true _) CC.Mptr _).trans (old.roots tags)
  slots := fun tags j => (effect.local_load _ _ _ (old.tables tags).binding
    (cell_table false tags _) (cell_table true tags _) CC.Mptr _).trans (old.slots tags j)
  writable := fun tags j => (CC.Mem.validAccess_congr (m1 := after) (m2 := before)
    (fun offset => by simp only [CC.Mem.perm,effect.access])).trans (old.writable tags j)
  sp := old.sp
  spPointer := (effect.local_load _ _ _ entry.binding (cell_header false _) (cell_header true _) CC.Mptr 40).trans old.spPointer
  spValue := old.spValue
  spRead := (effect.local_load _ _ _ old.sp.binding (cell_sp false _) (cell_sp true _) .Mint64 0).trans old.spRead
  flags := old.flags
  flagPointers := fun flag => (effect.local_load _ _ _ entry.binding
    (cell_header false _) (cell_header true _) CC.Mptr _).trans (old.flagPointers flag)
  flagWritable := fun flag => (CC.Mem.validAccess_congr (m1 := after) (m2 := before)
    (fun offset => by simp only [CC.Mem.perm,effect.access])).trans (old.flagWritable flag)
  vectors := old.vectors
  vectorPointers := fun high j => (effect.local_load _ _ _ entry.binding
    (cell_header false _) (cell_header true _) CC.Mptr _).trans (old.vectorPointers high j)
  vectorWritable := (CC.Mem.rangePerm_congr (m1 := after) (m2 := before)
    (fun offset => by simp only [CC.Mem.perm,effect.access])).trans old.vectorWritable

theorem header (chunk : CC.Chunk) (offset : Int) :
    CC.Mem.load chunk after entry.block offset = CC.Mem.load chunk before entry.block offset :=
  effect.local_load _ _ _ entry.binding (cell_header false _) (cell_header true _) chunk offset

theorem tail (j : Fin 9) (cell : TailLocal initial j) (chunk : CC.Chunk) (offset : Int) :
    CC.Mem.load chunk after cell.block offset = CC.Mem.load chunk before cell.block offset :=
  effect.local_load _ _ _ cell.binding (cell_tail false _ j) (cell_tail true _ j) chunk offset

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

theorem selected : Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) (declaration i).reg.val =
    some (.Vlong value,.Vint 0) := by
  rw [Arm64RegisterWrite.storage_gpr (storage effect) (declaration i).reg]
  change (do
    let word ← CC.Mem.load .Mint64 after ((old.tables false).cellBlock (declaration i).reg) 0
    let tag ← CC.Mem.load .Mint8unsigned after ((old.tables true).cellBlock (declaration i).reg) 0
    pure (word,tag)) = _
  rw [effect.word,effect.tag]
  rfl

theorem other (j : Fin 31) (different : j ≠ (declaration i).reg) :
    Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) j.val =
      Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) j.val := by
  rw [Arm64RegisterWrite.storage_gpr (storage effect) j,Arm64RegisterWrite.storage_gpr old j]
  change (do
    let word ← CC.Mem.load .Mint64 after ((old.tables false).cellBlock j) 0
    let tag ← CC.Mem.load .Mint8unsigned after ((old.tables true).cellBlock j) 0
    pure (word,tag)) = _
  rw [effect.other_cell false j different .Mint64 0,effect.other_cell true j different .Mint8unsigned 0]

/-- Both original stores preserve the complete finished-memset packet on the
same current heap, including all16 written bytes and24 zero tag observations. -/
def ready {seed : CC.Mem} {base : Arm64MemsetHeaderView.View initial seed entry}
    {abi : TailLocal initial 6} {byte : BitVec 8} {outerLe : CC.TempEnv}
    (prior : Arm64MemsetWriteLoop.Invariant base abi byte 16 before outerLe)
    (same : prior.storage = old) : Arm64MemsetWriteLoop.Invariant base abi byte 16 after outerLe := by
  subst old
  have nonzero : (0 : Fin 31) ≠ (declaration i).reg := by
    intro equal
    have bad := congrArg Fin.val equal
    have nonzero := Arm64MemsetClobberRegisters.register_nonzero i
    simp only [Fin.val_zero] at bad
    exact nonzero bad.symm
  refine {prior with
    view := view effect prior.view
    resources := resources effect prior.resources
    storage := storage effect
    gpr := (other effect 0 nonzero).trans prior.gpr
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

/-- The existing explicit provider/cache ABI transports the same packet.
Its cache writes are allowed; only its stated local and permission frame is used. -/
def supplied {initial seed before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe : CC.TempEnv} (prior : Arm64MemsetWriteLoop.Invariant base abi byte 16 before outerLe)
    (frame : Arm64ProgramEntryCacheFrame.Frame initial false before after) :
    Arm64MemsetWriteLoop.Invariant base abi byte 16 after outerLe := by
  have kept := Arm64ProducerTailFrame.of_cache entry frame
  let view : Arm64MemsetHeaderView.View initial after entry := {
    stack := prior.view.stack
    tags := prior.view.tags
    stackPointer := (kept.header CC.Mptr 608).trans prior.view.stackPointer
    tagPointer := (kept.header CC.Mptr 648).trans prior.view.tagPointer
    capacity := (kept.header .Mint32 656).trans prior.view.capacity
    bias := (kept.header .Mint64 672).trans prior.view.bias }
  refine {prior with
    view := view
    resources := Arm64MemsetIterationResources.resources prior.resources kept.header
      (fun block _ => congrArg (CC.PMap.get block) frame.access)
    storage := frame.storage prior.storage
    gpr := ?_
    abiHeader := (kept.header CC.Mptr 704).trans prior.abiHeader
    abiKind := (kept.tail 6 abi .Mint8unsigned 0).trans prior.abiKind
    tagBytes := ?_
    written := ?_ }
  · rw [frame.nextblock]
    exact (frame.gpr prior.storage (0 : Fin 31)).trans prior.gpr
  · intro j
    have tag := kept.tail 2 ⟨prior.view.tags.block,prior.view.tags.binding⟩ .Mint8unsigned (j.val : Int)
    change CC.Mem.load .Mint8unsigned after prior.view.tags.block (j.val : Int) =
      CC.Mem.load .Mint8unsigned before prior.view.tags.block (j.val : Int) at tag
    rw [prior.tagsSame] at tag
    exact tag.trans (prior.tagBytes j)
  · intro j bound
    have data := kept.tail 0 prior.view.stack .Mint8unsigned ((Arm64MemsetStoreExecution.index j).val : Int)
    rw [prior.stackSame] at data
    exact data.trans (prior.written j bound)

end KProgFormal.ClightRefinement.Arm64MemsetClobberRegisterState
