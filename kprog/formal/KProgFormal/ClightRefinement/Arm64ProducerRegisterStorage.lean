import KProgFormal.ClightRefinement.Arm64ProducerVectorView

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProducerRegisterStorage

open Arm64Producer

def cellChunk (tags : Bool) : CC.Chunk := if tags then .Mint8unsigned else .Mint64

/-- Actual allocation-bound roots, cells and current write permissions, plus
SP's real borrowed read and allocated flag/vector pointer bindings.
This is C storage evidence, not a second ISA model. -/
structure Storage (m memory : CC.Mem) (entry : HeaderLocal m) where
  tables : (tags : Bool) → TableLocals tags m
  roots : ∀ tags, CC.Mem.load CC.Mptr memory entry.block (if tags then 8 else 0) =
    some (.Vptr (tables tags).tableBlock 0)
  slots : ∀ tags (i : Fin 31), CC.Mem.load CC.Mptr memory (tables tags).tableBlock (8 * (i.val : Int)) =
    some (.Vptr ((tables tags).cellBlock i) 0)
  writable : ∀ tags (i : Fin 31), CC.Mem.validAccess memory (cellChunk tags)
    ((tables tags).cellBlock i) 0 .Writable = true
  sp : HeaderSourceLocal m 5
  spPointer : CC.Mem.load CC.Mptr memory entry.block 40 = some (.Vptr sp.block 0)
  spValue : BitVec 64
  spRead : CC.Mem.load .Mint64 memory sp.block 0 = some (.Vlong spValue)
  flags : (i : Fin 4) → HeaderSourceLocal m (Arm64ProducerEntryView.flagIndex i)
  flagPointers : ∀ i, CC.Mem.load CC.Mptr memory entry.block
    (8 * ((Arm64ProducerEntryView.flagIndex i).val : Int)) = some (.Vptr (flags i).block 0)
  flagWritable : ∀ i, CC.Mem.validAccess memory .Mint8unsigned (flags i).block 0 .Writable = true
  vectors : VectorLocal m
  vectorPointers : ∀ high (i : Fin 32), CC.Mem.load CC.Mptr memory entry.block
    ((if high then 352 else 96) + 8 * (i.val : Int)) =
      some (.Vptr vectors.block (vectorLoopSourceOffset high i))

private theorem local_writable (m memory : CC.Mem) (tags : Bool) (i : Fin 31)
    (table : TableLocals tags m) (access : memory.access = (allocation m).2.access) :
    CC.Mem.validAccess memory (cellChunk tags) (table.cellBlock i) 0 .Writable = true := by
  have size : CC.sizeof ge.genv_cenv (tableCellType tags) = CC.sizeChunk (cellChunk tags) := by
    cases tags <;> decide +kernel
  have align : (0 : Int) % CC.alignChunk (cellChunk tags) = 0 := by cases tags <;> decide
  obtain ⟨block, binding, _, writable⟩ := scalar_local m (tableCellName tags i) (tableCellType tags)
    (cellChunk tags) (table_cell_declaration tags i) size align
  have same : block = table.cellBlock i := congrArg Prod.fst (Option.some.inj (binding.symm.trans (table.cellBinding i)))
  subst block
  exact (CC.Mem.validAccess_congr (m1 := memory) (m2 := (allocation m).2)
    (chunk := cellChunk tags) (b := table.cellBlock i) (ofs := 0) (p := .Writable)
    (fun o => by simp only [CC.Mem.perm, access])).trans writable

/-- The four real flag locals have writable bytes from the same producer
allocation; no successful flag read or native value supplies permission. -/
private theorem flag_local_writable (m memory : CC.Mem) (i : Fin 4)
    (cell : HeaderSourceLocal m (Arm64ProducerEntryView.flagIndex i))
    (access : memory.access = (allocation m).2.access) :
    CC.Mem.validAccess memory .Mint8unsigned cell.block 0 .Writable = true := by
  have present : ∀ i : Fin 4,
      (headerSourceName (Arm64ProducerEntryView.flagIndex i),headerSourceType (Arm64ProducerEntryView.flagIndex i)) ∈ producer.fn_vars := by decide +kernel
  have size : ∀ i : Fin 4, CC.sizeof ge.genv_cenv (headerSourceType (Arm64ProducerEntryView.flagIndex i)) =
      CC.sizeChunk .Mint8unsigned := by decide +kernel
  obtain ⟨block,binding,_,writable⟩ := scalar_local m _ _ .Mint8unsigned (present i) (size i) (by decide)
  have same : block = cell.block := congrArg Prod.fst (Option.some.inj (binding.symm.trans cell.binding))
  subst block
  exact (CC.Mem.validAccess_congr (m1 := memory) (m2 := (allocation m).2)
    (chunk := .Mint8unsigned) (b := cell.block) (ofs := 0) (p := .Writable)
    (fun o => by simp only [CC.Mem.perm,access])).trans writable

/-- Build storage from the SAME actual header/loop result. Every block identity
comes from its typed allocation lookup, every permission from imported local
allocation and the reached access map. -/
def of_header (m memory : CC.Mem) (entry : HeaderLocal m)
    (header : (i : Fin 12) → HeaderSourceLocal m i) (tables : (tags : Bool) → TableLocals tags m)
    (vectors : VectorLocal m)
    (vectorPointers : ∀ high (i : Fin 32), CC.Mem.load CC.Mptr memory entry.block
      ((if high then 352 else 96) + 8 * (i.val : Int)) =
        some (.Vptr vectors.block (vectorLoopSourceOffset high i)))
    (access : memory.access = (allocation m).2.access)
    (pointers : ∀ i, CC.Mem.load CC.Mptr memory entry.block (8 * (i.val : Int)) =
      some (.Vptr (header i).block 0))
    (slots : ∀ tags (i : Fin 31), CC.Mem.load CC.Mptr memory (tables tags).tableBlock (8 * (i.val : Int)) =
      some (.Vptr ((tables tags).cellBlock i) 0))
    (spValue : BitVec 64) (spRead : CC.Mem.load .Mint64 memory (header 5).block 0 = some (.Vlong spValue)) :
    Storage m memory entry := {
  tables := tables
  roots := by
    intro tags
    cases tags
    · have same : (header 0).block = (tables false).tableBlock :=
        congrArg Prod.fst (Option.some.inj ((header 0).binding.symm.trans (tables false).binding))
      have read := pointers 0
      rw [same] at read
      exact read
    · have same : (header 1).block = (tables true).tableBlock :=
        congrArg Prod.fst (Option.some.inj ((header 1).binding.symm.trans (tables true).binding))
      have read := pointers 1
      rw [same] at read
      exact read
  slots := slots
  writable := fun tags i => local_writable m memory tags i (tables tags) access
  sp := header 5
  spPointer := pointers 5
  spValue := spValue
  spRead := spRead
  flags := fun i => header (Arm64ProducerEntryView.flagIndex i)
  flagPointers := fun i => pointers (Arm64ProducerEntryView.flagIndex i)
  flagWritable := fun i => flag_local_writable m memory i (header _) access
  vectors := vectors
  vectorPointers := vectorPointers }

/-- Any cell is separate from every differently named actual producer local,
including header/tables/SP/flags/vectors; no numeric-address guess is used. -/
theorem Storage.separate_local {m memory : CC.Mem} {entry : HeaderLocal m}
    (storage : Storage m memory entry) (tags : Bool) (i : Fin 31)
    (id : CC.Ident) (ty : CC.Ty) (block : CC.Block)
    (binding : (allocation m).1.get id = some (block, ty)) (different : tableCellName tags i ≠ id) :
    (storage.tables tags).cellBlock i ≠ block := by
  exact (allocated_local_storage
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm)).2
    _ _ _ _ ((storage.tables tags).cellBinding i) binding different

private theorem names_distinct : ∀ left right (i j : Fin 31), left ≠ right ∨ i ≠ j →
    tableCellName left i ≠ tableCellName right j := by decide +kernel

/-- All62 word/tag cells are pairwise distinct, as required to preserve other
register observations when one real data or tag cell is stored. -/
theorem Storage.cells_distinct {m memory : CC.Mem} {entry : HeaderLocal m}
    (storage : Storage m memory entry) (left right : Bool) (i j : Fin 31)
    (different : left ≠ right ∨ i ≠ j) :
    (storage.tables left).cellBlock i ≠ (storage.tables right).cellBlock j :=
  storage.separate_local left i _ _ _ ((storage.tables right).cellBinding j)
    (names_distinct left right i j different)

/-- Scalar/tag stores into these actual local blocks preserve every caller
block below the original producer allocation frontier. -/
theorem Storage.cell_fresh {m memory : CC.Mem} {entry : HeaderLocal m}
    (storage : Storage m memory entry) (tags : Bool) (i : Fin 31) :
    m.nextblock.toNat ≤ ((storage.tables tags).cellBlock i).toNat := by
  obtain ⟨block, binding, fresh, _⟩ := local_storage m (tableCellName tags i) (tableCellType tags)
    (table_cell_declaration tags i)
  have same : block = (storage.tables tags).cellBlock i :=
    congrArg Prod.fst (Option.some.inj (binding.symm.trans ((storage.tables tags).cellBinding i)))
  simpa only [same] using fresh

end KProgFormal.ClightRefinement.Arm64ProducerRegisterStorage
