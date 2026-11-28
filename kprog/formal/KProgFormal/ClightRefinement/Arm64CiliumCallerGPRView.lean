import KProgFormal.ClightRefinement.Arm64CiliumCallerVectorView

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerGPRView
open Arm64CiliumCallerLink (allocation)
open Arm64CiliumCallerHeaderSource (Header Sources)
open Arm64CiliumCallerTables (Table tableName tableType)
open Arm64CiliumCallerInitializers (Cells)
open Arm64CiliumCallerGPRSource (declaration)
open Arm64CiliumCallerGPRFrames (localRead)
open Arm64CiliumCallerContextEntry (CurrentGPR wordValue tagValue)

private def tableIndex (tags : Bool) : Fin 12 := if tags then 1 else 0

/-- Independently chosen actual source/table witnesses agree through SAME allocation lookup. -/
theorem table_blocks {m : CC.Mem} (sources : Sources m) (tags : Bool) (table : Table tags m) :
    sources.block (tableIndex tags) = table.block := by
  have bound : (allocation m).1.get (tableName tags) =
      some (sources.block (tableIndex tags),tableType tags) := by
    cases tags
    · exact sources.binding 0
    · exact sources.binding 1
  exact congrArg Prod.fst (Option.some.inj (bound.symm.trans table.binding))

private theorem cell_names : ∀ i : Fin 31,
    Arm64CiliumCallerInitializers.name false i = (declaration i).word ∧
    Arm64CiliumCallerInitializers.name true i = (declaration i).tag := by decide +kernel

/-- Current word/tag observations refer to those same actual table-cell objects. -/
theorem cell_readbacks {m memory : CC.Mem} (words : Cells false m) (tags : Cells true m)
    (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs) (inputs : Fin 30 → BitVec 64)
    (current : CurrentGPR m memory ctx ctxOfs inputs) :
    (∀ i : Fin 31,CC.Mem.load .Mint64 memory (words.block i) 0 =
      some (wordValue ctx ctxOfs inputs i)) ∧
    (∀ i : Fin 31,CC.Mem.load .Mint8unsigned memory (tags.block i) 0 =
      some (tagValue i)) := by
  constructor
  · intro i
    have read := current.word i
    rw [← (cell_names i).1] at read
    simpa only [localRead,words.binding i,Option.bind_some] using read
  · intro i
    have read := current.tag i
    rw [← (cell_names i).2] at read
    simpa only [localRead,tags.binding i,Option.bind_some] using read

/-- Existing consumer GPR reader follows the real header/table/cell pointer chain.
Pointer-valued R0 and the current R0/R30 tags are retained by wordValue/tagValue. -/
theorem gpr_readbacks {m memory : CC.Mem} (header : Header m) (sources : Sources m)
    (words : Table false m) (tags : Table true m)
    (wordCells : Cells false m) (tagCells : Cells true m)
    (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs) (inputs : Fin 30 → BitVec 64)
    (headerReads : Arm64CiliumCallerHeaderSequence.Initialized header sources memory 12)
    (wordSlots : ∀ i : Fin 31,CC.Mem.load .Mint64 memory words.block (8*(i.val : Int)) =
      some (.Vptr (wordCells.block i) 0))
    (tagSlots : ∀ i : Fin 31,CC.Mem.load .Mint64 memory tags.block (8*(i.val : Int)) =
      some (.Vptr (tagCells.block i) 0))
    (current : CurrentGPR m memory ctx ctxOfs inputs) :
    ∀ i : Fin 31,Arm64EntryMemory.gpr memory.nextblock memory (.Vptr header.block 0) i.val =
      some (wordValue ctx ctxOfs inputs i,tagValue i) := by
  have wordHeader := headerReads 0 (by decide)
  have tagHeader := headerReads 1 (by decide)
  have wordBlock : sources.block 0 = words.block := table_blocks sources false words
  have tagBlock : sources.block 1 = tags.block := table_blocks sources true tags
  rw [wordBlock] at wordHeader
  rw [tagBlock] at tagHeader
  obtain ⟨wordReads,tagReads⟩ := cell_readbacks wordCells tagCells ctx ctxOfs inputs current
  intro i
  apply Arm64ProducerGprView.gpr_readback memory header.block words.block tags.block
    (wordCells.block i) (tagCells.block i) i (wordValue ctx ctxOfs inputs i) (tagValue i)
  · simpa [CC.Mptr,CC.Archi.ptr64] using wordHeader
  · simpa [CC.Mptr,CC.Archi.ptr64] using tagHeader
  · simpa [CC.Mptr,CC.Archi.ptr64] using wordSlots i
  · simpa [CC.Mptr,CC.Archi.ptr64] using tagSlots i
  · exact wordReads i
  · exact tagReads i

end KProgFormal.ClightRefinement.Arm64CiliumCallerGPRView
