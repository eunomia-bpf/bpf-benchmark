import KProgFormal.ClightRefinement.Arm64CntVectorMemory
import KProgFormal.ClightRefinement.Arm64FmovVectorStorage

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Cnt.VectorStorage

open Arm64Producer Arm64ProducerRegisterStorage

private theorem local_load {initial before after : CC.Mem} (vectors : VectorLocal initial)
    (low high : BitVec 64) (effect : VectorMemory.Effect before after vectors.block low high)
    (id : CC.Ident) (ty : CC.Ty) (block : CC.Block)
    (binding : (allocation initial).1.get id = some (block,ty))
    (different : id ≠ Arm64Entry.___a64_vectors) (chunk : CC.Chunk) (offset : Int) :
    CC.Mem.load chunk after block offset = CC.Mem.load chunk before block offset :=
  effect.other chunk block offset (Arm64Fmov.VectorStorage.separate vectors id ty block binding different)

private theorem access {before after : CC.Mem} {block : CC.Block} {low high : BitVec 64}
    (effect : VectorMemory.Effect before after block low high) (chunk : CC.Chunk) (b : CC.Block) (offset : Int) :
    CC.Mem.validAccess after chunk b offset .Writable = CC.Mem.validAccess before chunk b offset .Writable := by
  obtain ⟨middle,lowStore,highStore⟩ := effect
  exact (CC.Mem.validAccess_store_eq highStore chunk b offset .Writable).trans
    (CC.Mem.validAccess_store_eq lowStore chunk b offset .Writable)

private theorem table_different : ∀ tags, tableName tags ≠ Arm64Entry.___a64_vectors := by decide +kernel
private theorem cell_different : ∀ tags (i : Fin 31), tableCellName tags i ≠ Arm64Entry.___a64_vectors := by decide +kernel
private theorem flag_different : ∀ i : Fin 4,
    headerSourceName (Arm64ProducerEntryView.flagIndex i) ≠ Arm64Entry.___a64_vectors := by decide +kernel

/-- Both original CNT writes retain all producer bindings, permissions,
scalar cells, SP, flags and vector pointer slots. -/
def storage {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) (low high : BitVec 64)
    (effect : VectorMemory.Effect before after old.vectors.block low high) : Storage initial after entry where
  tables := old.tables
  roots := fun tags => (local_load old.vectors low high effect _ _ _ entry.binding
    (by decide +kernel) _ _).trans (old.roots tags)
  slots := fun tags i => (local_load old.vectors low high effect _ _ _ (old.tables tags).binding
    (table_different tags) _ _).trans (old.slots tags i)
  writable := fun tags i => (access effect _ _ _).trans (old.writable tags i)
  sp := old.sp
  spPointer := (local_load old.vectors low high effect _ _ _ entry.binding (by decide +kernel) _ _).trans old.spPointer
  spValue := old.spValue
  spRead := (local_load old.vectors low high effect _ _ _ old.sp.binding (by decide +kernel) _ _).trans old.spRead
  flags := old.flags
  flagPointers := fun i => (local_load old.vectors low high effect _ _ _ entry.binding
    (by decide +kernel) _ _).trans (old.flagPointers i)
  flagWritable := fun i => (access effect _ _ _).trans (old.flagWritable i)
  vectors := old.vectors
  vectorWritable := (CC.Mem.rangePerm_congr (m1 := after) (m2 := before)
    (fun offset => by simp only [CC.Mem.perm,effect.access])).trans old.vectorWritable
  vectorPointers := fun highHalf i => (local_load old.vectors low high effect _ _ _ entry.binding
    (by decide +kernel) _ _).trans (old.vectorPointers highHalf i)

theorem cell {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) (low high : BitVec 64)
    (effect : VectorMemory.Effect before after old.vectors.block low high)
    (tags : Bool) (i : Fin 31) (chunk : CC.Chunk) (offset : Int) :
    CC.Mem.load chunk after ((old.tables tags).cellBlock i) offset =
      CC.Mem.load chunk before ((old.tables tags).cellBlock i) offset :=
  effect.other chunk _ offset (old.separate_local tags i _ _ _ old.vectors.binding
    (cell_different tags i))

theorem flag {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) (low high : BitVec 64)
    (effect : VectorMemory.Effect before after old.vectors.block low high)
    (i : Fin 4) (chunk : CC.Chunk) (offset : Int) :
    CC.Mem.load chunk after (old.flags i).block offset = CC.Mem.load chunk before (old.flags i).block offset :=
  local_load old.vectors low high effect _ _ _ (old.flags i).binding (flag_different i) chunk offset

end KProgFormal.ClightRefinement.Arm64Cnt.VectorStorage
