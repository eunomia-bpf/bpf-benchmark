import KProgFormal.ClightRefinement.Arm64ProgramEntryOrdinaryRights
import KProgFormal.ClightRefinement.Arm64ProgramEntryMemsetAllocation

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryMemoryPacket
open Arm64Producer (HeaderLocal TailLocal)
open Arm64ProducerRegisterStorage (Storage)

private theorem ordinary_sp {initial before written after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial before entry} {i : Fin 31} {value : BitVec 64}
    {addresses : Arm64Registers.PointerOrigins} {origins : Reference.Provenance.AArch64.Origins}
    {s : Reference.AArch64.State} {k : CC.Cont}
    (result : Arm64MovImmediate.OrdinaryCall.Result storage i value addresses origins s k written after)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat) :
    (result.storage bound).spValue = storage.spValue := by
  simp only [Arm64MovImmediate.OrdinaryCall.Result.storage,Arm64RegisterStorageFrontier.storage_frame,
    Arm64RegisterWrite.Result.storage,Arm64MovImmediate.OrdinaryCall.allocatedStorage,
    Arm64ProducerRegisterStorage.Storage.frame]

/-- The SAME actual pointer write, repeated MOV and constant MOV derive all
memset-entry observations and permissions from the preceding reached heap.
Both ordinary calls retain their real allocations, two stores and frees. -/
def prepare {initial before pointerWritten markWritten markAfter constantWritten constantAfter : CC.Mem}
    {entry : HeaderLocal initial} {storage : Storage initial before entry}
    {addresses : Arm64Registers.PointerOrigins} {origins : Reference.Provenance.AArch64.Origins}
    {prior next : Reference.AArch64.State} {priorK nextK : CC.Cont} {mark : BitVec 32}
    (pointer : Arm64PointerWrite.Result storage 0 (-32#64) (4#8) pointerWritten)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ pointerWritten.nextblock.toNat)
    (first : Arm64MovImmediate.OrdinaryCall.Result pointer.storage 1 (mark.setWidth 64)
      addresses origins prior priorK markWritten markAfter)
    (second : Arm64MovImmediate.OrdinaryCall.Result (first.storage bound) 2 (16#64)
      addresses origins next nextK constantWritten constantAfter)
    (view : Arm64MemsetHeaderView.View initial before entry)
    (resources : Arm64ProgramEntryResources.Resources initial before entry)
    (spAtBase : storage.spValue = (-32#64)) (abi : TailLocal initial 6)
    (abiHeader : CC.Mem.load CC.Mptr before entry.block 704 = some (.Vptr abi.block 0))
    (abiKind : CC.Mem.load .Mint8unsigned before abi.block 0 = some (.Vint 2))
    (tagBytes : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned before view.tags.block (j.val : Int) = some (.Vint 0)) :
    Arm64ProgramEntryMemsetAllocation.Prepared initial constantAfter entry abi := by
  have pointerTail := Arm64ProducerTailFrame.of_kept entry 0 pointer.local_load
  have pointerResources := Arm64ProgramEntryResourceTransport.resources resources pointerTail
    (fun block _ => congrArg (CC.PMap.get block) pointer.access)
  have firstBound := Arm64MemsetInputs.bound_after first bound
  have finalBound := Arm64MemsetInputs.bound_after second firstBound
  have currentResources := Arm64ProgramEntryOrdinaryRights.resources second firstBound
    (Arm64ProgramEntryOrdinaryRights.resources first bound pointerResources)
  have fullTail := (pointerTail.trans (Arm64ProducerTailFrame.of_kept entry 1 first.kept)).trans
    (Arm64ProducerTailFrame.of_kept entry 2 second.kept)
  let currentView := Arm64MemsetHeaderView.of_frame view fullTail
  have actualR0 : Arm64EntryMemory.gpr pointerWritten.nextblock pointerWritten (.Vptr entry.block 0) 0 =
      some (.Vlong (-32#64),.Vint ((4#8).setWidth 32)) := by
    simpa only [pointer.nextblock,eq_self,ite_true,Fin.val_zero] using pointer.gpr 0
  have currentR0 := (Arm64MemsetInputs.other second firstBound 0 (by decide)).trans
    ((Arm64MemsetInputs.other first bound 0 (by decide)).trans actualR0)
  have currentTags (j : Fin 24) : CC.Mem.load .Mint8unsigned constantAfter currentView.tags.block (j.val : Int) = some (.Vint 0) :=
    (fullTail.tail 2 ⟨view.tags.block,view.tags.binding⟩ .Mint8unsigned (j.val : Int)).trans (tagBytes j)
  have spFirst : (first.storage bound).spValue = pointer.storage.spValue := ordinary_sp first bound
  have spSecond : (second.storage firstBound).spValue = (first.storage bound).spValue := ordinary_sp second firstBound
  have spPointer : pointer.storage.spValue = storage.spValue := by simp only [Arm64PointerWrite.Result.storage]
  have currentSp := spSecond.trans (spFirst.trans (spPointer.trans spAtBase))
  exact Arm64ProgramEntryMemsetAllocation.prepare currentView currentResources (second.storage firstBound) finalBound
    currentSp currentR0 abi ((fullTail.header CC.Mptr 704).trans abiHeader)
    ((fullTail.tail 6 abi .Mint8unsigned 0).trans abiKind) currentTags

/-- The two original memory helpers' provider families, indexed by the
SAME prepared view and actual call input heap. -/
structure Providers {initial seed : CC.Mem} {entry : HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial seed entry) (abi : TailLocal initial 6)
    (mark : BitVec 32) (before : CC.Mem) (cell : TailLocal initial 5) where
  bytes : ∀ le, Arm64ClobberReleaseComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) before (-32#64) 0 cell (0#8) le
  registers : ∀ le, Arm64ClobberRegisterComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) before (-32#64) 0 cell (0#8) le
  flags : ∀ le gprs, Arm64ClobberFlagsComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) before (-32#64) 0 cell (0#8) le gprs
  vectors : ∀ le gprs flags, Arm64ClobberVectorsComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) before (-32#64) 0 cell (0#8) le gprs flags
  copyBytes : ∀ copyBefore le, Arm64ClobberReleaseComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) copyBefore (-16#64) 16 cell (0#8) le
  copyRegisters : ∀ copyBefore le, Arm64ClobberRegisterComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) copyBefore (-16#64) 16 cell (0#8) le
  copyFlags : ∀ copyBefore le gprs, Arm64ClobberFlagsComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) copyBefore (-16#64) 16 cell (0#8) le gprs
  copyVectors : ∀ copyBefore le gprs flags, Arm64ClobberVectorsComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) copyBefore (-16#64) 16 cell (0#8) le gprs flags

end KProgFormal.ClightRefinement.Arm64ProgramEntryMemoryPacket
