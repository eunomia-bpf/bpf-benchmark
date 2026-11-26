import KProgFormal.ClightRefinement.Arm64ProgramEntryTerminalStores

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryTerminalFrame
open Arm64Producer
open Arm64ProducerRegisterStorage (Storage)
open Arm64ProgramEntryTerminalStores (Effect SpEffect)

private theorem header_other : Arm64Entry._entry ≠ Arm64Entry.___a64_sp := by decide +kernel
private theorem table_other : ∀ tags, tableName tags ≠ Arm64Entry.___a64_sp := by decide +kernel
private theorem cell_other : ∀ tags (r : Fin 31), tableCellName tags r ≠ Arm64Entry.___a64_sp := by decide +kernel
private theorem tail_other : ∀ i : Fin 9, tailLocalName i ≠ Arm64Entry.___a64_sp := by decide +kernel
private theorem word_vector : tableCellName false (0 : Fin 31) ≠ Arm64Entry.___a64_vectors := by decide +kernel
private theorem tag_vector : tableCellName true (0 : Fin 31) ≠ Arm64Entry.___a64_vectors := by decide +kernel
private theorem vector_other : Arm64Entry.___a64_vectors ≠ Arm64Entry.___a64_sp := by decide +kernel
private theorem flags_other : ∀ i : Fin 4, headerSourceName (Arm64ProducerEntryView.flagIndex i) ≠ Arm64Entry.___a64_sp := by decide +kernel
private theorem word_flag : ∀ i : Fin 4, tableCellName false (0 : Fin 31) ≠ headerSourceName (Arm64ProducerEntryView.flagIndex i) := by decide +kernel
private theorem tag_flag : ∀ i : Fin 4, tableCellName true (0 : Fin 31) ≠ headerSourceName (Arm64ProducerEntryView.flagIndex i) := by decide +kernel

/-- The real SP store updates the actual storage SP value to zero, preserving
all allocated tables, pointers, flags, vectors and their current rights. -/
def sp_storage {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (prior : Storage initial before entry) (effect : SpEffect prior.sp before after) : Storage initial after entry := by
  have keepHeader := effect.local_load _ _ _ entry.binding header_other
  refine {prior with
    roots := fun tags => (keepHeader CC.Mptr _).trans (prior.roots tags)
    slots := fun tags i => (effect.local_load _ _ _ (prior.tables tags).binding (table_other tags) CC.Mptr _).trans (prior.slots tags i)
    writable := ?_
    spPointer := (keepHeader CC.Mptr _).trans prior.spPointer
    spValue := 0
    spRead := CC.Mem.load_store_same effect.stored
    flagPointers := fun i => (keepHeader CC.Mptr _).trans (prior.flagPointers i)
    flagWritable := fun i => (CC.Mem.validAccess_congr (m1 := after) (m2 := before)
      (fun ofs => by simp only [CC.Mem.perm,effect.access])).trans (prior.flagWritable i)
    vectorWritable := (CC.Mem.rangePerm_congr (m1 := after) (m2 := before)
      (fun ofs => by simp only [CC.Mem.perm,effect.access])).trans prior.vectorWritable
    vectorPointers := fun high i => (keepHeader CC.Mptr _).trans (prior.vectorPointers high i)}
  intro tags i
  exact (CC.Mem.validAccess_congr (m1 := after) (m2 := before)
    (fun ofs => by simp only [CC.Mem.perm,effect.access])).trans (prior.writable tags i)

theorem sp_gpr {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (prior : Storage initial before entry) (effect : SpEffect prior.sp before after) (r : Fin 31) :
    Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) r.val =
      Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) r.val := by
  rw [Arm64RegisterWrite.storage_gpr (sp_storage prior effect) r,Arm64RegisterWrite.storage_gpr prior r]
  change (do
    let word ← CC.Mem.load .Mint64 after ((prior.tables false).cellBlock r) 0
    let tag ← CC.Mem.load .Mint8unsigned after ((prior.tables true).cellBlock r) 0
    pure (word,tag)) = _
  rw [effect.local_load _ _ _ ((prior.tables false).cellBinding r) (cell_other false r) .Mint64 0,
    effect.local_load _ _ _ ((prior.tables true).cellBinding r) (cell_other true r) .Mint8unsigned 0]

theorem sp_tailFrame {initial before after : CC.Mem} {sp : HeaderSourceLocal initial 5}
    (effect : SpEffect sp before after) (entry : HeaderLocal initial) :
    Arm64ProducerTailFrame.Frame initial entry before after :=
  ⟨fun chunk ofs => effect.local_load _ _ _ entry.binding header_other chunk ofs,
   fun i cell chunk ofs => effect.local_load _ _ _ cell.binding (tail_other i) chunk ofs⟩

section Effect
variable {initial before after : CC.Mem} {entry : HeaderLocal initial} {prior : Storage initial before entry}
    {value : BitVec 64} (effect : Effect prior value after)
include effect

theorem caller : FrameBelow initial.nextblock before after := effect.registers.caller.trans effect.sp.caller

theorem access : after.access = before.access := effect.sp.access.trans effect.registers.access

theorem nextblock : after.nextblock = before.nextblock := effect.sp.nextblock.trans effect.registers.nextblock

theorem local_load (id : CC.Ident) (ty : CC.Ty) (block : CC.Block)
    (binding : (Arm64Producer.allocation initial).1.get id = some (block,ty))
    (wordOther : tableCellName false (0 : Fin 31) ≠ id) (tagOther : tableCellName true (0 : Fin 31) ≠ id)
    (spOther : id ≠ Arm64Entry.___a64_sp) (chunk : CC.Chunk) (ofs : Int) :
    CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs :=
  (effect.sp.local_load _ _ _ binding spOther chunk ofs).trans (effect.registers.local_load _ _ _ binding wordOther tagOther chunk ofs)

/-- Actual final storage, with scalar X0/tag0 and SP value zero. -/
def storage : Storage initial after entry := sp_storage effect.registers.storage effect.sp

theorem sp_zero : (storage effect).spValue = 0 := rfl

theorem sp_readback : CC.Mem.load .Mint64 after prior.sp.block 0 = some (.Vlong 0) := CC.Mem.load_store_same effect.sp.stored

theorem gpr (r : Fin 31) : Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) r.val =
    if r = 0 then some (.Vlong value,.Vint (0#32))
    else Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) r.val := by
  rw [sp_gpr effect.registers.storage effect.sp r,effect.registers.nextblock]
  simpa only [show (0#8).setWidth 32 = (0#32) by decide +kernel] using effect.registers.gpr r

theorem r0 : Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) 0 = some (.Vlong value,.Vint (0#32)) := by
  simpa only [show (0 : Fin 31).val = 0 by decide +kernel,ite_true] using gpr effect (0 : Fin 31)

theorem tailFrame : Arm64ProducerTailFrame.Frame initial entry before after :=
  (Arm64ProducerTailFrame.of_kept entry (0 : Fin 31) effect.registers.kept).trans (sp_tailFrame effect.sp entry)

theorem flag (i : Fin 4) : Arm64EntryMemory.borrowed after.nextblock .Mint8unsigned after (.Vptr entry.block 0)
      (Arm64MemsetClobberFlags.field i) =
    Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before (.Vptr entry.block 0) (Arm64MemsetClobberFlags.field i) := by
  unfold Arm64MemsetClobberFlags.field
  rw [Arm64RegisterWrite.storage_flag (storage effect) i,Arm64RegisterWrite.storage_flag prior i]
  exact local_load effect _ _ _ (prior.flags i).binding (word_flag i) (tag_flag i) (flags_other i) .Mint8unsigned 0

theorem vector (i : Fin 64) : CC.Mem.load .Mint64 after prior.vectors.block (Arm64MemsetClobberVectors.offset i) =
    CC.Mem.load .Mint64 before prior.vectors.block (Arm64MemsetClobberVectors.offset i) :=
  local_load effect _ _ _ prior.vectors.binding word_vector tag_vector vector_other .Mint64 _

end Effect
end KProgFormal.ClightRefinement.Arm64ProgramEntryTerminalFrame
