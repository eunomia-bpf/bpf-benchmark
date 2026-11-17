import KProgFormal.ClightRefinement.Arm64ProducerEntryView

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProducerGprView

open Arm64Producer
open Arm64ProducerEntryView

private theorem slot_unsigned : ∀ i : Fin 31,
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr (8 * (i.val : Int))) =
      8 * (i.val : Int) := by decide +kernel

private theorem slot_readback (memory : CC.Mem) (block : CC.Block) (i : Fin 31) (value : CC.Val)
    (read : CC.Mem.load CC.Mptr memory block (8 * (i.val : Int)) = some value) :
    Arm64EntryMemory.load memory.nextblock CC.Mptr memory
      (CC.Val.offsetPtr (.Vptr block 0) (CC.Integers.Ptrofs.repr
        (CC.sizeof Arm64EntryMemory.composites (CC.tptr CC.tvoid) * i.val))) = some value := by
  have offset : CC.Val.offsetPtr (.Vptr block 0) (CC.Integers.Ptrofs.repr
      (CC.sizeof Arm64EntryMemory.composites (CC.tptr CC.tvoid) * i.val)) =
      .Vptr block (CC.Integers.Ptrofs.repr (8 * (i.val : Int))) := by
    change CC.Val.Vptr block (CC.Integers.Ptrofs.add 0 (CC.Integers.Ptrofs.repr (8 * (i.val : Int)))) = _
    apply congrArg (CC.Val.Vptr block)
    exact BitVec.zero_add _
  rw [offset]
  apply checked_load
  simpa only [slot_unsigned i] using read

/-- Real header, table-slot and cell loads establish the existing GPR reader.
Values and tags are retained, including pointer-valued union cells. Every
reader bound follows from successful imported loads in the same memory. -/
theorem gpr_readback (memory : CC.Mem) (entry words tags wordCell tagCell : CC.Block)
    (i : Fin 31) (value kind : CC.Val)
    (wordHeader : CC.Mem.load CC.Mptr memory entry 0 = some (.Vptr words 0))
    (tagHeader : CC.Mem.load CC.Mptr memory entry 8 = some (.Vptr tags 0))
    (wordSlot : CC.Mem.load CC.Mptr memory words (8 * (i.val : Int)) = some (.Vptr wordCell 0))
    (tagSlot : CC.Mem.load CC.Mptr memory tags (8 * (i.val : Int)) = some (.Vptr tagCell 0))
    (wordRead : CC.Mem.load .Mint64 memory wordCell 0 = some value)
    (tagRead : CC.Mem.load .Mint8unsigned memory tagCell 0 = some kind) :
    Arm64EntryMemory.gpr memory.nextblock memory (.Vptr entry 0) i.val = some (value, kind) := by
  have wordField : Arm64EntryMemory.field memory.nextblock CC.Mptr memory (.Vptr entry 0)
      Arm64Program._cells = some (.Vptr words 0) := header_field_readback memory entry 0 _ wordHeader
  have tagField : Arm64EntryMemory.field memory.nextblock CC.Mptr memory (.Vptr entry 0)
      Arm64Program._tag_cells = some (.Vptr tags 0) := header_field_readback memory entry 1 _ tagHeader
  simp only [Arm64EntryMemory.gpr, bind, pure, Option.bind_eq_some_iff]
  refine ⟨.Vptr words 0, wordField, .Vptr wordCell 0, ?_, .Vptr tags 0, tagField,
    .Vptr tagCell 0, ?_, value, checked_load .Mint64 memory wordCell 0 value wordRead,
    kind, checked_load .Mint8unsigned memory tagCell 0 kind tagRead, rfl⟩
  · exact slot_readback memory words i _ wordSlot
  · exact slot_readback memory tags i _ tagSlot

private def tableIndex (tags : Bool) : Fin 12 := if tags then 1 else 0

/-- Independently chosen source records identify the same actual local block
through allocation lookup uniqueness, rather than an assumed block equality. -/
private theorem header_table_block (tags : Bool) (m : CC.Mem)
    (header : (i : Fin 12) → HeaderSourceLocal m i) (table : TableLocals tags m) :
    (header (tableIndex tags)).block = table.tableBlock := by
  have bound : (allocation m).1.get (tableName tags) =
      some ((header (tableIndex tags)).block, tableType tags) := by
    cases tags
    · exact (header 0).binding
    · exact (header 1).binding
  exact congrArg Prod.fst (Option.some.inj (bound.symm.trans table.binding))

/-- Actual producer HeaderSourceLocal and TableLocals records supply the two
real table roots and every one of the 31 value/tag cell pairs. -/
theorem table_gpr_readbacks (m memory : CC.Mem) (entry : HeaderLocal m)
    (header : (i : Fin 12) → HeaderSourceLocal m i)
    (words : TableLocals false m) (tags : TableLocals true m)
    (values : Fin 31 → CC.Val) (kinds : Fin 31 → BitVec 8)
    (pointers : ∀ i, CC.Mem.load CC.Mptr memory entry.block (8 * (i.val : Int)) =
      some (.Vptr (header i).block 0))
    (wordSlots : ∀ i, CC.Mem.load CC.Mptr memory words.tableBlock (8 * (i.val : Int)) =
      some (.Vptr (words.cellBlock i) 0))
    (tagSlots : ∀ i, CC.Mem.load CC.Mptr memory tags.tableBlock (8 * (i.val : Int)) =
      some (.Vptr (tags.cellBlock i) 0))
    (wordReads : ∀ i, CC.Mem.load .Mint64 memory (words.cellBlock i) 0 = some (values i))
    (tagReads : ∀ i, CC.Mem.load .Mint8unsigned memory (tags.cellBlock i) 0 =
      some (.Vint ((kinds i).setWidth 32))) :
    ∀ i, Arm64EntryMemory.gpr memory.nextblock memory (.Vptr entry.block 0) i.val =
      some (values i, .Vint ((kinds i).setWidth 32)) := by
  have wordHeader : CC.Mem.load CC.Mptr memory entry.block 0 = some (.Vptr words.tableBlock 0) := by
    have read := pointers 0
    have same : (header 0).block = words.tableBlock := header_table_block false m header words
    rw [same] at read
    exact read
  have tagHeader : CC.Mem.load CC.Mptr memory entry.block 8 = some (.Vptr tags.tableBlock 0) := by
    have read := pointers 1
    have same : (header 1).block = tags.tableBlock := header_table_block true m header tags
    rw [same] at read
    exact read
  intro i
  exact gpr_readback memory entry.block words.tableBlock tags.tableBlock
    (words.cellBlock i) (tags.cellBlock i) i (values i) (.Vint ((kinds i).setWidth 32))
    wordHeader tagHeader (wordSlots i) (tagSlots i) (wordReads i) (tagReads i)

/-- The real 638-transition header/loop execution exposes all actual GPR
value/tag readbacks through the consumer reader. Pre-header table and cell
contents remain precise source obligations, not an architectural cell map. -/
theorem producer_gprs_initialized (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (values : Fin 31 → CC.Val) (kinds : Fin 31 → BitVec 8)
    (access : before.access = (allocation m).2.access)
    (tablesBefore : ∀ tags, ∃ table : TableLocals tags m, ∀ i,
      CC.Mem.load CC.Mptr before table.tableBlock (8 * (i.val : Int)) = some (.Vptr (table.cellBlock i) 0))
    (wordsBefore : ∀ (i : Fin 31) (block : CC.Block),
      (allocation m).1.get (tableCellName false i) = some (block, tableCellType false) →
      CC.Mem.load .Mint64 before block 0 = some (values i))
    (tagsBefore : ∀ (i : Fin 31) (block : CC.Block),
      (allocation m).1.get (tableCellName true i) = some (block, tableCellType true) →
      CC.Mem.load .Mint8unsigned before block 0 = some (.Vint ((kinds i).setWidth 32))) :
    ∃ entry : HeaderLocal m, ∃ after finalLe,
      InternalRun ge 638 (.State producer afterContext k (allocation m).1 le before)
        (.State producer afterVectorLoop k (allocation m).1 finalLe after) ∧
      (∀ i : Fin 31, Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) i.val =
        some (values i, .Vint ((kinds i).setWidth 32))) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨entry, header, _, _, after, finalLe, run, _, _, pointers, _, _, locals, frame, accessAfter, next⟩ :=
    header_initialized_before_consumer m before le k access
  obtain ⟨words, wordSlots⟩ := tablesBefore false
  obtain ⟨tags, tagSlots⟩ := tablesBefore true
  have tableOther : ∀ tags, tableName tags ≠ Arm64Entry._entry := by decide +kernel
  have cellOther : ∀ tags (i : Fin 31), tableCellName tags i ≠ Arm64Entry._entry := by decide +kernel
  refine ⟨entry, after, finalLe, run, ?_, frame, accessAfter, next⟩
  apply table_gpr_readbacks m after entry header words tags values kinds pointers
  · intro i
    rw [locals _ _ _ words.binding (tableOther false) CC.Mptr (8 * (i.val : Int))]
    exact wordSlots i
  · intro i
    rw [locals _ _ _ tags.binding (tableOther true) CC.Mptr (8 * (i.val : Int))]
    exact tagSlots i
  · intro i
    rw [locals _ _ _ (words.cellBinding i) (cellOther false i) .Mint64 0]
    exact wordsBefore i _ (words.cellBinding i)
  · intro i
    rw [locals _ _ _ (tags.cellBinding i) (cellOther true i) .Mint8unsigned 0]
    exact tagsBefore i _ (tags.cellBinding i)

end KProgFormal.ClightRefinement.Arm64ProducerGprView
