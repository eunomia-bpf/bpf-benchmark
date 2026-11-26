import KProgFormal.ClightRefinement.Arm64MemcpyLengthCall

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyLengthState

open Arm64Producer Arm64ProducerRegisterStorage
open Arm64ProgramEntryAllocation (world)
open Arm64MemcpyLengthCall (Result)

/-- The existing raw-word packet records the actual MOV value at R2; every
other clobber word retains its original provider value. -/
def words (previous : Fin 18 → BitVec 64) (j : Fin 18) : BitVec 64 := if j = 1 then 16#64 else previous j

private theorem tail_name : ∀ tags (j : Fin 9), tableCellName tags (2 : Fin 31) ≠ tailLocalName j := by decide +kernel
private theorem flag_name : ∀ tags (j : Fin 4), tableCellName tags (2 : Fin 31) ≠
    headerSourceName (Arm64ProducerEntryView.flagIndex j) := by decide +kernel
private theorem register_other : ∀ j : Fin 18, j ≠ 1 → (2 : Fin 31) ≠ (Arm64MemsetClobberRegisters.declaration j).reg := by decide +kernel
private theorem register_selected : (Arm64MemsetClobberRegisters.declaration 1).reg = (2 : Fin 31) := rfl

private theorem retained_sp {initial current finalMem : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial current entry) (frontier : CC.Block)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ frontier.toNat)
    (frame : FrameBelow frontier current finalMem) :
    (Arm64RegisterStorageFrontier.storage_frame storage frontier bound frame).spValue = storage.spValue := by
  unfold Arm64RegisterStorageFrontier.storage_frame
  rfl
private theorem stored_sp {initial current written : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial current entry} {i : Fin 31} {value : BitVec 64} {narrow : Bool}
    (effect : Arm64RegisterWrite.Result storage i value narrow written) : effect.storage.spValue = storage.spValue := rfl
private theorem allocated_sp {initial current allocated : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial current entry) (frame : FrameBelow current.nextblock current allocated) :
    (storage.frame frame).spValue = storage.spValue := by
  unfold Storage.frame
  rfl

section Effect
variable {initial beforeMem written finalMem : CC.Mem} {entry : HeaderLocal initial}
    {old : Storage initial beforeMem entry} (result : Result old written finalMem)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ beforeMem.nextblock.toNat)
include result

theorem header (chunk : CC.Chunk) (ofs : Int) :
    CC.Mem.load chunk finalMem entry.block ofs = CC.Mem.load chunk beforeMem entry.block ofs :=
  result.kept _ _ _ entry.binding (by decide +kernel) (by decide +kernel) chunk ofs

theorem tail (j : Fin 9) (cell : TailLocal initial j) (chunk : CC.Chunk) (ofs : Int) :
    CC.Mem.load chunk finalMem cell.block ofs = CC.Mem.load chunk beforeMem cell.block ofs :=
  result.kept _ _ _ cell.binding (tail_name false j) (tail_name true j) chunk ofs

theorem vector_load (chunk : CC.Chunk) (ofs : Int) :
    CC.Mem.load chunk finalMem old.vectors.block ofs = CC.Mem.load chunk beforeMem old.vectors.block ofs :=
  result.kept _ _ _ old.vectors.binding (by decide +kernel) (by decide +kernel) chunk ofs

include bound

theorem flag (j : Fin 4) :
    Arm64EntryMemory.borrowed finalMem.nextblock .Mint8unsigned finalMem (.Vptr entry.block 0)
      (Arm64MemsetClobberFlags.field j) =
    Arm64EntryMemory.borrowed beforeMem.nextblock .Mint8unsigned beforeMem (.Vptr entry.block 0)
      (Arm64MemsetClobberFlags.field j) := by
  unfold Arm64MemsetClobberFlags.field
  rw [Arm64RegisterWrite.storage_flag (result.storage bound) j,Arm64RegisterWrite.storage_flag old j]
  exact result.kept _ _ _ (old.flags j).binding (flag_name false j) (flag_name true j) .Mint8unsigned 0

/-- Real allocation/store/free changes permissions on the callee blocks.
All original producer rights retain their actual permission-map observations. -/
theorem access (block : CC.Block) (owned : block.toNat < (Arm64Producer.allocation initial).2.nextblock.toNat) :
    CC.PMap.get block finalMem.access = CC.PMap.get block beforeMem.access := by
  have earlier := Nat.lt_of_lt_of_le owned bound
  exact ((result.frame block earlier).2.trans (congrArg (CC.PMap.get block) result.effect.access)).trans
    ((Arm64Nop.entry_frame world beforeMem block earlier).2)

theorem bound_after : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ finalMem.nextblock.toNat := by
  rw [result.nextblock,result.effect.nextblock]
  exact Nat.le_trans bound (FrameBelow.allocVariables (Arm64MovImmediate.allocated_bound world beforeMem)
    beforeMem.nextblock (Nat.le_refl _)).1

/-- Normalize each real storage transport before projecting the saved SP. -/
theorem storage_sp : (result.storage bound).spValue = old.spValue := by
  unfold Arm64MemcpyLengthCall.Result.storage
  rw [retained_sp,stored_sp,Arm64MovImmediate.OrdinaryCall.allocatedStorage,allocated_sp]

/-- Reuse the complete same packet, updating only R2's raw-word observation
from the actual source store. Data, tags, other words and rights survive free. -/
def transport {seed : CC.Mem} {base : Arm64MemsetHeaderView.View initial seed entry}
    {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (prior : Arm64MemsetPointerState.Packet base abi byte gprs flags values beforeMem)
    (actual : old = prior.storage) :
    Arm64MemsetPointerState.Packet base abi byte (words gprs) flags values finalMem := by
  subst old
  let currentView : Arm64MemsetHeaderView.View initial finalMem entry := {
    prior.view with
      stackPointer := (header result CC.Mptr 608).trans prior.view.stackPointer
      tagPointer := (header result CC.Mptr 648).trans prior.view.tagPointer
      capacity := (header result .Mint32 656).trans prior.view.capacity
      bias := (header result .Mint64 672).trans prior.view.bias }
  refine {
    view := currentView
    stackSame := prior.stackSame
    tagsSame := prior.tagsSame
    resources := Arm64MemsetIterationResources.resources prior.resources (header result) (access result bound)
    storage := result.storage bound
    spAtBase := (storage_sp result bound).trans prior.spAtBase
    r0 := (result.other bound 0 (by decide)).trans prior.r0
    r1 := (result.other bound 1 (by decide)).trans prior.r1
    abiHeader := (header result CC.Mptr 704).trans prior.abiHeader
    abiKind := (tail result 6 abi .Mint8unsigned 0).trans prior.abiKind
    tagBytes := ?_
    written := ?_
    registers := ?_
    flags := fun j => (flag result bound j).trans (prior.flags j)
    vectors := ?_ }
  · intro j
    have kept := tail result 2 ⟨prior.view.tags.block,prior.view.tags.binding⟩ .Mint8unsigned (j.val : Int)
    change CC.Mem.load .Mint8unsigned finalMem prior.view.tags.block (j.val : Int) =
      CC.Mem.load .Mint8unsigned beforeMem prior.view.tags.block (j.val : Int) at kept
    rw [prior.tagsSame] at kept
    exact kept.trans (prior.tagBytes j)
  · intro j
    have kept := tail result 0 prior.view.stack .Mint8unsigned ((Arm64MemsetStoreExecution.index j).val : Int)
    rw [prior.stackSame] at kept
    exact kept.trans (prior.written j)
  · intro j positive
    by_cases selected : j = 1
    · subst j
      simpa +decide [words,register_selected] using result.selected bound
    · simpa only [words,selected,ite_false] using
        (result.other bound (Arm64MemsetClobberRegisters.declaration j).reg (register_other j selected)).trans
          (prior.registers j positive)
  · intro j
    change CC.Mem.load .Mint64 finalMem prior.storage.vectors.block (Arm64MemsetClobberVectors.offset j) = _
    exact (vector_load result .Mint64 (Arm64MemsetClobberVectors.offset j)).trans (prior.vectors j)

end Effect

/-- The current complete post-memset/pointer packet executes the original
fifteenth MOV and reaches memcpy with its newly stored length and all rights. -/
theorem execute {initial seed beforeMem : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (prior : Arm64MemsetPointerState.Packet base abi byte gprs flags values beforeMem)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ beforeMem.nextblock.toNat)
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ written finalMem, ∃ result : Result prior.storage written finalMem,
      ∃ _current : Arm64MemsetPointerState.Packet base abi byte (words gprs) flags values finalMem,
        InternalRun world 207
          (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryPointerWrites.afterThird k
            (Arm64ProgramEntryAllocation.allocation initial).1 le beforeMem)
          (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterThird k
            (Arm64ProgramEntryAllocation.allocation initial).1 le finalMem) := by
  obtain ⟨written,finalMem,result,run⟩ := Arm64MemcpyLengthCall.execute prior.storage bound le k
  exact ⟨written,finalMem,result,transport result bound prior rfl,run⟩

end KProgFormal.ClightRefinement.Arm64MemcpyLengthState
