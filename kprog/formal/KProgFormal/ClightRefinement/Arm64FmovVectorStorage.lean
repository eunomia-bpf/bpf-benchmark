import KProgFormal.ClightRefinement.Arm64FmovVectorMemory

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Fmov.VectorStorage

open Arm64Producer Arm64ProducerRegisterStorage

/-- Original typed allocation separates every differently named producer
local from the real vector array, without physical-address assumptions. -/
theorem separate {initial : CC.Mem} (vectors : VectorLocal initial)
    (id : CC.Ident) (ty : CC.Ty) (block : CC.Block)
    (binding : (allocation initial).1.get id = some (block,ty))
    (different : id ≠ Arm64Entry.___a64_vectors) : block ≠ vectors.block :=
  (allocated_local_storage (CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (allocation initial)).symm)).2 _ _ _ _ binding vectors.binding different

/-- Both real vector stores preserve every chunk of every other typed local. -/
theorem local_load {initial before after : CC.Mem} (vectors : VectorLocal initial) (value : BitVec 64)
    (effect : VectorMemory.Effect before after vectors.block value)
    (id : CC.Ident) (ty : CC.Ty) (block : CC.Block)
    (binding : (allocation initial).1.get id = some (block,ty))
    (different : id ≠ Arm64Entry.___a64_vectors) (chunk : CC.Chunk) (offset : Int) :
    CC.Mem.load chunk after block offset = CC.Mem.load chunk before block offset :=
  effect.other chunk block offset (separate vectors id ty block binding different)

private theorem access {before after : CC.Mem} {block : CC.Block} {value : BitVec 64}
    (effect : VectorMemory.Effect before after block value) (chunk : CC.Chunk) (b : CC.Block) (offset : Int) :
    CC.Mem.validAccess after chunk b offset .Writable = CC.Mem.validAccess before chunk b offset .Writable := by
  obtain ⟨middle,low,high⟩ := effect
  exact (CC.Mem.validAccess_store_eq high chunk b offset .Writable).trans
    (CC.Mem.validAccess_store_eq low chunk b offset .Writable)

private theorem table_different : ∀ tags, tableName tags ≠ Arm64Entry.___a64_vectors := by decide +kernel
private theorem cell_different : ∀ tags (i : Fin 31), tableCellName tags i ≠ Arm64Entry.___a64_vectors := by decide +kernel
private theorem flag_different : ∀ i : Fin 4,
    headerSourceName (Arm64ProducerEntryView.flagIndex i) ≠ Arm64Entry.___a64_vectors := by decide +kernel

/-- Retain the actual header, tables, permissions, SP, flag and vector-pointer
bindings after the two actual writes. Only vector3's data changes. -/
def storage {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) (value : BitVec 64)
    (effect : VectorMemory.Effect before after old.vectors.block value) : Storage initial after entry where
  tables := old.tables
  roots := fun tags => (local_load old.vectors value effect _ _ _ entry.binding
    (by decide +kernel) _ _).trans (old.roots tags)
  slots := fun tags i => (local_load old.vectors value effect _ _ _ (old.tables tags).binding
    (table_different tags) _ _).trans (old.slots tags i)
  writable := fun tags i => (access effect _ _ _).trans (old.writable tags i)
  sp := old.sp
  spPointer := (local_load old.vectors value effect _ _ _ entry.binding (by decide +kernel) _ _).trans old.spPointer
  spValue := old.spValue
  spRead := (local_load old.vectors value effect _ _ _ old.sp.binding (by decide +kernel) _ _).trans old.spRead
  flags := old.flags
  flagPointers := fun i => (local_load old.vectors value effect _ _ _ entry.binding
    (by decide +kernel) _ _).trans (old.flagPointers i)
  flagWritable := fun i => (access effect _ _ _).trans (old.flagWritable i)
  vectors := old.vectors
  vectorPointers := fun high i => (local_load old.vectors value effect _ _ _ entry.binding
    (by decide +kernel) _ _).trans (old.vectorPointers high i)

/-- Every GPR data/tag cell retains its complete raw load through FMOV. -/
theorem cell {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) (value : BitVec 64)
    (effect : VectorMemory.Effect before after old.vectors.block value)
    (tags : Bool) (i : Fin 31) (chunk : CC.Chunk) (offset : Int) :
    CC.Mem.load chunk after ((old.tables tags).cellBlock i) offset =
      CC.Mem.load chunk before ((old.tables tags).cellBlock i) offset :=
  effect.other chunk _ offset (old.separate_local tags i _ _ _ old.vectors.binding
    (cell_different tags i))

/-- Every flag-byte local retains all successful and refused raw loads. -/
theorem flag {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) (value : BitVec 64)
    (effect : VectorMemory.Effect before after old.vectors.block value)
    (i : Fin 4) (chunk : CC.Chunk) (offset : Int) :
    CC.Mem.load chunk after (old.flags i).block offset = CC.Mem.load chunk before (old.flags i).block offset :=
  local_load old.vectors value effect _ _ _ (old.flags i).binding (flag_different i) chunk offset

end KProgFormal.ClightRefinement.Arm64Fmov.VectorStorage
