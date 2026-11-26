import KProgFormal.ClightRefinement.Arm64MemcpyByteWrite
import KProgFormal.ClightRefinement.Arm64MemcpyReadCurrent

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyByteStorage

open Arm64Producer Arm64ProducerRegisterStorage

section Effect
variable {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (stack : TailLocal initial 0) (offset : Int) (value : BitVec 8)
    (stored : CC.Mem.store .Mint8unsigned before stack.block offset (.Vint (value.setWidth 32)) = some after)
include stored

/-- Actual declared-local separation preserves every load outside the
stack block changed by the genuine destination byte store. -/
theorem local_load (id : CC.Ident) (ty : CC.Ty) (block : CC.Block)
    (binding : (allocation initial).1.get id = some (block,ty))
    (different : id ≠ tailLocalName 0) (chunk : CC.Chunk) (ofs : Int) :
    CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs := by
  have separate := (allocated_local_storage
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation initial)).symm)).2
  exact CC.Mem.load_store_other stored chunk block ofs (.inl (separate _ _ _ _ binding stack.binding different))

omit stored in
private theorem tables_other : ∀ tags, tableName tags ≠ tailLocalName 0 := by decide +kernel
omit stored in
private theorem sp_other : headerSourceName 5 ≠ tailLocalName 0 := by decide +kernel

/-- The real byte store preserves the complete current architectural
storage on its distinct original allocations and current permissions. -/
def storage (old : Storage initial before entry) : Storage initial after entry where
  tables := old.tables
  roots := fun tags => (local_load stack offset value stored _ _ _ entry.binding (by decide +kernel) CC.Mptr _).trans (old.roots tags)
  slots := fun tags j => (local_load stack offset value stored _ _ _ (old.tables tags).binding
    (tables_other tags) CC.Mptr _).trans (old.slots tags j)
  writable := fun tags j => (CC.Mem.validAccess_congr (m1:=after) (m2:=before)
    (fun ofs => by simp only [CC.Mem.perm,CC.Mem.store_access stored])).trans (old.writable tags j)
  sp := old.sp
  spPointer := (local_load stack offset value stored _ _ _ entry.binding (by decide +kernel) CC.Mptr 40).trans old.spPointer
  spValue := old.spValue
  spRead := (local_load stack offset value stored _ _ _ old.sp.binding sp_other .Mint64 0).trans old.spRead
  flags := old.flags
  flagPointers := fun flag => (local_load stack offset value stored _ _ _ entry.binding (by decide +kernel)
    CC.Mptr _).trans (old.flagPointers flag)
  flagWritable := fun flag => (CC.Mem.validAccess_congr (m1:=after) (m2:=before)
    (fun ofs => by simp only [CC.Mem.perm,CC.Mem.store_access stored])).trans (old.flagWritable flag)
  vectors := old.vectors
  vectorPointers := fun high j => (local_load stack offset value stored _ _ _ entry.binding (by decide +kernel)
    CC.Mptr _).trans (old.vectorPointers high j)
  vectorWritable := (CC.Mem.rangePerm_congr (m1:=after) (m2:=before)
    (fun ofs => by simp only [CC.Mem.perm,CC.Mem.store_access stored])).trans old.vectorWritable

omit stored in
private theorem cell_other : ∀ tags (j : Fin 31), tableCellName tags j ≠ tailLocalName 0 := by decide +kernel

/-- The imported register walker observes the same current raw word and
tag after the real byte store, at its actual reached allocation frontier. -/
theorem gpr (old : Storage initial before entry) (j : Fin 31) :
    Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) j.val =
      Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) j.val := by
  rw [Arm64RegisterWrite.storage_gpr (storage stack offset value stored old) j,
    Arm64RegisterWrite.storage_gpr old j]
  change (do
    let word ← CC.Mem.load .Mint64 after ((old.tables false).cellBlock j) 0
    let tag ← CC.Mem.load .Mint8unsigned after ((old.tables true).cellBlock j) 0
    pure (word,tag)) = _
  rw [local_load stack offset value stored _ _ _ ((old.tables false).cellBinding j) (cell_other false j) .Mint64 0,
    local_load stack offset value stored _ _ _ ((old.tables true).cellBinding j) (cell_other true j) .Mint8unsigned 0]

/-- Header696 and its actual TailLocal5 byte survive this distinct
stack-only effect with the original typed read values. -/
theorem flag {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (prior : Arm64MemcpyReadCurrent.Flag entry cell flagValue before) :
    Arm64MemcpyReadCurrent.Flag entry cell flagValue after :=
  ⟨(local_load stack offset value stored _ _ _ entry.binding (by decide +kernel) CC.Mptr 696).trans prior.header,
   (local_load stack offset value stored _ _ _ cell.binding (by decide +kernel) .Mint8unsigned 0).trans prior.byte⟩

end Effect
end KProgFormal.ClightRefinement.Arm64MemcpyByteStorage
