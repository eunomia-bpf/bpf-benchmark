import KProgFormal.ClightRefinement.Arm64CacheLocalFrame
import KProgFormal.ClightRefinement.Arm64ProgramEntryCacheFrame
import KProgFormal.ClightRefinement.Arm64ProgramEntryBodyView

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProducerTailFrame

open Arm64Producer (HeaderLocal TailLocal allocation)
open Arm64RegisterStorageFrontier (local_owned)

/-- Exact raw observations of the actual header and all nine original tail
locals, including the ABI byte, stack data and24 initialized tag bytes. -/
structure Frame (initial : CC.Mem) (entry : HeaderLocal initial) (before after : CC.Mem) : Prop where
  header : ∀ chunk ofs, CC.Mem.load chunk after entry.block ofs = CC.Mem.load chunk before entry.block ofs
  tail : ∀ (i : Fin 9) (cell : TailLocal initial i) chunk ofs,
    CC.Mem.load chunk after cell.block ofs = CC.Mem.load chunk before cell.block ofs

theorem Frame.trans {initial a b c : CC.Mem} {entry : HeaderLocal initial}
    (first : Frame initial entry a b) (second : Frame initial entry b c) : Frame initial entry a c :=
  ⟨fun chunk ofs => (second.header chunk ofs).trans (first.header chunk ofs),
    fun i cell chunk ofs => (second.tail i cell chunk ofs).trans (first.tail i cell chunk ofs)⟩

/-- Actual allocation/free framing at the owned producer frontier protects
these same declared blocks and every imported load result. -/
theorem of_frame {initial before after : CC.Mem} (entry : HeaderLocal initial) (frontier : CC.Block)
    (bound : (allocation initial).2.nextblock.toNat ≤ frontier.toNat)
    (frame : FrameBelow frontier before after) : Frame initial entry before after := by
  refine ⟨?_,?_⟩
  · intro chunk ofs
    exact frame.load chunk entry.block ofs (Nat.lt_of_lt_of_le entry.owned bound)
  · intro i cell chunk ofs
    exact frame.load chunk cell.block ofs
      (Nat.lt_of_lt_of_le (local_owned initial _ _ _ cell.binding) bound)

private theorem header_not_cell : ∀ tags (j : Fin 31),
    Arm64Producer.tableCellName tags j ≠ Arm64Entry._entry := by decide +kernel
private theorem tail_not_cell : ∀ tags (j : Fin 31) (i : Fin 9),
    Arm64Producer.tableCellName tags j ≠ Arm64Producer.tailLocalName i := by decide +kernel

theorem of_kept {initial before after : CC.Mem} (entry : HeaderLocal initial) (j : Fin 31)
    (kept : Arm64CacheLocalFrame.Kept initial before after j) : Frame initial entry before after :=
  ⟨fun chunk ofs => kept _ _ _ entry.binding (header_not_cell false j) (header_not_cell true j) chunk ofs,
    fun i cell chunk ofs => kept _ _ _ cell.binding (tail_not_cell false j i) (tail_not_cell true j i) chunk ofs⟩

private theorem header_not_cache : ∀ returns,
    Arm64Producer.baseName returns ≠ Arm64Entry._entry ∧
    Arm64Producer.validName returns ≠ Arm64Entry._entry := by decide +kernel
private theorem tail_not_cache : ∀ returns (i : Fin 9),
    Arm64Producer.baseName returns ≠ Arm64Producer.tailLocalName i ∧
    Arm64Producer.validName returns ≠ Arm64Producer.tailLocalName i := by decide +kernel

/-- The actual admitted provider/cache frame preserves the header/tail locals
while retaining the real writes to its two cache cells. -/
theorem of_cache {initial before after : CC.Mem} {returns : Bool} (entry : HeaderLocal initial)
    (frame : Arm64ProgramEntryCacheFrame.Frame initial returns before after) : Frame initial entry before after :=
  ⟨fun chunk ofs => frame.local_load _ _ _ entry.binding
      (header_not_cache returns).1 (header_not_cache returns).2 chunk ofs,
    fun i cell chunk ofs => frame.local_load _ _ _ cell.binding
      (tail_not_cache returns i).1 (tail_not_cache returns i).2 chunk ofs⟩

private theorem header_not_setup : Arm64Entry._entry ≠ Arm64Entry.___a64_sp ∧
    ∀ i : Fin 4, Arm64Entry._entry ≠ Arm64ProgramEntryBody.flagName i := by decide +kernel
private theorem tail_not_setup : ∀ j : Fin 9,
    Arm64Producer.tailLocalName j ≠ Arm64Entry.___a64_sp ∧
    ∀ i : Fin 4, Arm64Producer.tailLocalName j ≠ Arm64ProgramEntryBody.flagName i := by decide +kernel

theorem of_setup {initial before after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Arm64ProducerRegisterStorage.Storage initial before entry}
    {le : CC.TempEnv} {k : CC.Cont} {ctxBlock : CC.Block} {ctxOfs : CC.Integers.Ptrofs}
    {values : Fin 3 → BitVec 32}
    (result : Arm64ProgramEntryBodyView.Result storage le k ctxBlock ctxOfs values after) :
    Frame initial entry before after :=
  ⟨fun chunk ofs => result.local_load _ _ _ entry.binding header_not_setup.1 header_not_setup.2 chunk ofs,
    fun i cell chunk ofs => result.local_load _ _ _ cell.binding (tail_not_setup i).1 (tail_not_setup i).2 chunk ofs⟩

/-- Transport the genuine ABI pointer and byte from the same earlier heap. -/
theorem Frame.abi {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (frame : Frame initial entry before after) (kind : TailLocal initial 6)
    (pointer : CC.Mem.load CC.Mptr before entry.block 704 = some (.Vptr kind.block 0))
    (byte : CC.Mem.load .Mint8unsigned before kind.block 0 = some (.Vint 2)) :
    CC.Mem.load CC.Mptr after entry.block 704 = some (.Vptr kind.block 0) ∧
    CC.Mem.load .Mint8unsigned after kind.block 0 = some (.Vint 2) :=
  ⟨(frame.header CC.Mptr 704).trans pointer,(frame.tail 6 kind .Mint8unsigned 0).trans byte⟩

end KProgFormal.ClightRefinement.Arm64ProducerTailFrame
