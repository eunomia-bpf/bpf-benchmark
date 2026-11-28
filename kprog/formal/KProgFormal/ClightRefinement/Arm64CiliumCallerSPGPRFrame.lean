import KProgFormal.ClightRefinement.Arm64CiliumCallerMemOffset

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerSPGPRFrame
open Arm64CiliumCallerLink (allocation)
open Arm64CiliumCallerHeaderSource (Header Sources)
open Arm64CiliumCallerEntryScalars (Locals)
open Arm64CiliumCallerTables (Table tableName)
open Arm64CiliumCallerInitializers (Cells)
open Arm64CiliumCallerGPRSource (declaration)
open Arm64CiliumCallerGPRFrames (localRead)
open Arm64CiliumCallerContextEntry (CurrentGPR wordValue tagValue)

variable {m before : CC.Mem} {header : Header m} {sources : Sources m} {scalars : Locals m}

/-- Actual allocation separates every differently named local from the SP cell. -/
theorem bound_frame (result : Arm64CiliumCallerSPWriteMemory.Store (before := before) header sources scalars)
    {id : CC.Ident} {ty : CC.Ty} {block : CC.Block}
    (binding : (allocation m).1.get id = some (block,ty))
    (different : id ≠ Arm64CiliumCallerEntryScalars.name 0) :
    ∀ chunk offset,CC.Mem.load chunk result.after block offset = CC.Mem.load chunk before block offset :=
  result.otherBlocks block ((allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
    _ _ _ _ binding (scalars.binding 0) different)

private theorem local_frame
    (result : Arm64CiliumCallerSPWriteMemory.Store (before := before) header sources scalars)
    (id : CC.Ident) (different : id ≠ Arm64CiliumCallerEntryScalars.name 0)
    (chunk : CC.Chunk) (offset : Int) :
    localRead m result.after id chunk offset = localRead m before id chunk offset := by
  cases binding : (allocation m).1.get id with
  | none => simp only [localRead,binding,Option.bind_none]
  | some cell =>
    simpa only [localRead,binding,Option.bind_some] using
      bound_frame result binding different chunk offset

private theorem gpr_names : ∀ i : Fin 31,
    (declaration i).word ≠ Arm64CiliumCallerEntryScalars.name 0 ∧
    (declaration i).tag ≠ Arm64CiliumCallerEntryScalars.name 0 := by decide +kernel
private theorem table_names : ∀ tags : Bool,
    tableName tags ≠ Arm64CiliumCallerEntryScalars.name 0 := by decide +kernel

/-- All actual GPR observations survive the real SP write, including pointer R0 and tag10 R30. -/
theorem current_gpr
    (result : Arm64CiliumCallerSPWriteMemory.Store (before := before) header sources scalars)
    (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs) (inputs : Fin 30 → BitVec 64)
    (current : CurrentGPR m before ctx ctxOfs inputs) :
    CurrentGPR m result.after ctx ctxOfs inputs := by
  constructor
  · intro i
    exact (local_frame result (declaration i).word (gpr_names i).1 .Mint64 0).trans (current.word i)
  · intro i
    exact (local_frame result (declaration i).tag (gpr_names i).2 .Mint8unsigned 0).trans (current.tag i)

/-- The same actual two-level table slots are retained; no array/table identification is assumed. -/
theorem table_slots
    (result : Arm64CiliumCallerSPWriteMemory.Store (before := before) header sources scalars)
    (tags : Bool) (table : Table tags m) (cells : Cells tags m)
    (slots : ∀ i : Fin 31,CC.Mem.load .Mint64 before table.block (8*(i.val : Int)) =
      some (.Vptr (cells.block i) 0)) :
    ∀ i : Fin 31,CC.Mem.load .Mint64 result.after table.block (8*(i.val : Int)) =
      some (.Vptr (cells.block i) 0) := by
  intro i
  exact (bound_frame result table.binding (table_names tags) .Mint64 _).trans (slots i)

/-- Header, table and cell reads all refer to the same SP-updated memory and real allocation. -/
theorem gpr_readbacks
    (result : Arm64CiliumCallerSPWriteMemory.Store (before := before) header sources scalars)
    (words : Table false m) (tags : Table true m)
    (wordCells : Cells false m) (tagCells : Cells true m)
    (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs) (inputs : Fin 30 → BitVec 64)
    (wordSlots : ∀ i : Fin 31,CC.Mem.load .Mint64 before words.block (8*(i.val : Int)) =
      some (.Vptr (wordCells.block i) 0))
    (tagSlots : ∀ i : Fin 31,CC.Mem.load .Mint64 before tags.block (8*(i.val : Int)) =
      some (.Vptr (tagCells.block i) 0))
    (current : CurrentGPR m before ctx ctxOfs inputs) :
    ∀ i : Fin 31,Arm64EntryMemory.gpr result.after.nextblock result.after (.Vptr header.block 0) i.val =
      some (wordValue ctx ctxOfs inputs i,tagValue i) :=
  Arm64CiliumCallerGPRView.gpr_readbacks header sources words tags wordCells tagCells ctx ctxOfs inputs
    result.pointers (table_slots result false words wordCells wordSlots)
    (table_slots result true tags tagCells tagSlots) (current_gpr result ctx ctxOfs inputs current)

/-- The next original store-source reader sees word R30 zero and its actual RETURN tag10. -/
theorem r30_readback
    (result : Arm64CiliumCallerSPWriteMemory.Store (before := before) header sources scalars)
    (words : Table false m) (tags : Table true m)
    (wordCells : Cells false m) (tagCells : Cells true m)
    (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs) (inputs : Fin 30 → BitVec 64)
    (wordSlots : ∀ i : Fin 31,CC.Mem.load .Mint64 before words.block (8*(i.val : Int)) =
      some (.Vptr (wordCells.block i) 0))
    (tagSlots : ∀ i : Fin 31,CC.Mem.load .Mint64 before tags.block (8*(i.val : Int)) =
      some (.Vptr (tagCells.block i) 0))
    (current : CurrentGPR m before ctx ctxOfs inputs) :
    Arm64EntryMemory.gpr result.after.nextblock result.after (.Vptr header.block 0) 30 =
      some (.Vlong (0#64),.Vint (10#32)) := by
  have read := gpr_readbacks result words tags wordCells tagCells ctx ctxOfs inputs wordSlots tagSlots current ⟨30,by decide⟩
  change Arm64EntryMemory.gpr result.after.nextblock result.after (.Vptr header.block 0) 30 =
    some (.Vlong (0#64),.Vint (10#32)) at read
  exact read

end KProgFormal.ClightRefinement.Arm64CiliumCallerSPGPRFrame
