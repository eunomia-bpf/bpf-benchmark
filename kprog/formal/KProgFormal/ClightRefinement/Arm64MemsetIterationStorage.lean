import KProgFormal.ClightRefinement.Arm64MemsetIterationResources

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetIterationStorage

open Arm64Producer Arm64ProducerRegisterStorage

section Stores
variable {initial before tagged after : CC.Mem} {entry : HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial before entry)
    (i : Fin 16) (byte : BitVec 8)
    (tagStore : CC.Mem.store .Mint64 before view.tags.block 8 (.Vlong 0) = some tagged)
    (byteStore : CC.Mem.store .Mint8unsigned tagged view.stack.block
      ((Arm64MemsetStoreExecution.index i).val : Int) (.Vint (byte.setWidth 32)) = some after)

include view i byte tagStore byteStore

private theorem other (id : CC.Ident) (ty : CC.Ty) (block : CC.Block)
    (binding : (allocation initial).1.get id = some (block,ty))
    (notTag : id ≠ tailLocalName 2) (notStack : id ≠ tailLocalName 0)
    (chunk : CC.Chunk) (offset : Int) :
    CC.Mem.load chunk after block offset = CC.Mem.load chunk before block offset := by
  have separate := (allocated_local_storage (CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (allocation initial)).symm)).2
  have tagOther := separate _ _ _ _ binding view.tags.binding notTag
  have stackOther := separate _ _ _ _ binding view.stack.binding notStack
  exact (CC.Mem.load_store_other byteStore chunk block offset (.inl stackOther)).trans
    (CC.Mem.load_store_other tagStore chunk block offset (.inl tagOther))

omit view i byte tagStore byteStore

private theorem tables_other : ∀ tags, tableName tags ≠ tailLocalName 2 ∧ tableName tags ≠ tailLocalName 0 := by decide +kernel
private theorem sp_other : headerSourceName 5 ≠ tailLocalName 2 ∧ headerSourceName 5 ≠ tailLocalName 0 := by decide +kernel

/-- The real stack/tag writes retain all current architectural storage:
actual tables, SP raw bits/read, flags, vector roots and every permission.
No unchanged-stack premise is needed because these are different real locals. -/
def storage (old : Storage initial before entry) : Storage initial after entry where
  tables := old.tables
  roots := fun tags => (other view i byte tagStore byteStore _ _ _ entry.binding (by decide +kernel) (by decide +kernel)
    CC.Mptr _).trans (old.roots tags)
  slots := fun tags j => (other view i byte tagStore byteStore _ _ _ (old.tables tags).binding
    (tables_other tags).1 (tables_other tags).2 CC.Mptr _).trans (old.slots tags j)
  writable := fun tags j => (CC.Mem.validAccess_congr (m1 := after) (m2 := before)
    (fun offset => by simp only [CC.Mem.perm,CC.Mem.store_access byteStore,CC.Mem.store_access tagStore])).trans (old.writable tags j)
  sp := old.sp
  spPointer := (other view i byte tagStore byteStore _ _ _ entry.binding (by decide +kernel) (by decide +kernel)
    CC.Mptr 40).trans old.spPointer
  spValue := old.spValue
  spRead := (other view i byte tagStore byteStore _ _ _ old.sp.binding sp_other.1 sp_other.2 .Mint64 0).trans old.spRead
  flags := old.flags
  flagPointers := fun flag => (other view i byte tagStore byteStore _ _ _ entry.binding (by decide +kernel) (by decide +kernel)
    CC.Mptr _).trans (old.flagPointers flag)
  flagWritable := fun flag => (CC.Mem.validAccess_congr (m1 := after) (m2 := before)
    (fun offset => by simp only [CC.Mem.perm,CC.Mem.store_access byteStore,CC.Mem.store_access tagStore])).trans (old.flagWritable flag)
  vectors := old.vectors
  vectorPointers := fun high j => (other view i byte tagStore byteStore _ _ _ entry.binding (by decide +kernel) (by decide +kernel)
    CC.Mptr _).trans (old.vectorPointers high j)
  vectorWritable := (CC.Mem.rangePerm_congr (m1 := after) (m2 := before)
    (fun offset => by simp only [CC.Mem.perm,CC.Mem.store_access byteStore,CC.Mem.store_access tagStore])).trans old.vectorWritable

include view i byte tagStore byteStore

/-- The next iteration observes the SAME original source SP bits. -/
theorem sp_value (old : Storage initial before entry) :
    (storage view i byte tagStore byteStore old).spValue = old.spValue := rfl

end Stores
end KProgFormal.ClightRefinement.Arm64MemsetIterationStorage
