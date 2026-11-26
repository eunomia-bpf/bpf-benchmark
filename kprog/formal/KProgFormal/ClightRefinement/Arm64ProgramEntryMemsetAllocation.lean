import KProgFormal.ClightRefinement.Arm64ProgramEntryMemoryReturn

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryMemsetAllocation
open Arm64Producer (HeaderLocal TailLocal)
open Arm64ProducerRegisterStorage (Storage)
open Arm64ProgramEntryAllocation (world)

/-- Exact current source observations used by the real memset entry, after
its actual eight-local allocation. -/
structure Prepared (initial before : CC.Mem) (entry : HeaderLocal initial) (abi : TailLocal initial 6) where
  view : Arm64MemsetHeaderView.View initial (Arm64MemsetSource.allocation before).2 entry
  resources : Arm64ProgramEntryResources.Resources initial (Arm64MemsetSource.allocation before).2 entry
  storage : Storage initial (Arm64MemsetSource.allocation before).2 entry
  spAtBase : storage.spValue = (-32#64)
  r0 : Arm64EntryMemory.gpr (Arm64MemsetSource.allocation before).2.nextblock
    (Arm64MemsetSource.allocation before).2 (.Vptr entry.block 0) 0 = some (.Vlong (-32#64),.Vint ((4#8).setWidth 32))
  abiHeader : CC.Mem.load CC.Mptr (Arm64MemsetSource.allocation before).2 entry.block 704 = some (.Vptr abi.block 0)
  abiKind : CC.Mem.load .Mint8unsigned (Arm64MemsetSource.allocation before).2 abi.block 0 = some (.Vint 2)
  tagBytes : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned (Arm64MemsetSource.allocation before).2
    view.tags.block (j.val : Int) = some (.Vint 0)

/-- Derive every true helper-entry observation from the SAME before-call
heap and imported allocation frame; no after-allocation readback is a premise. -/
def prepare {initial before : CC.Mem} {entry : HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial before entry)
    (resources : Arm64ProgramEntryResources.Resources initial before entry) (storage : Storage initial before entry)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (spAtBase : storage.spValue = (-32#64))
    (r0 : Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) 0 = some (.Vlong (-32#64),.Vint ((4#8).setWidth 32)))
    (abi : TailLocal initial 6)
    (abiHeader : CC.Mem.load CC.Mptr before entry.block 704 = some (.Vptr abi.block 0))
    (abiKind : CC.Mem.load .Mint8unsigned before abi.block 0 = some (.Vint 2))
    (tagBytes : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned before view.tags.block (j.val : Int) = some (.Vint 0)) :
    Prepared initial before entry abi := by
  let frame := Arm64MemsetSource.entry_frame before
  refine {
    view := Arm64MemsetFreeState.view before.nextblock bound frame view
    resources := Arm64MemsetFreeState.resources before.nextblock bound frame resources
    storage := Arm64MemsetFreeState.storage before.nextblock bound frame storage
    spAtBase := spAtBase
    r0 := (Arm64MemsetFreeState.gpr before.nextblock bound frame storage 0).trans r0
    abiHeader := (Arm64MemsetFreeState.header before.nextblock bound frame CC.Mptr 704).trans abiHeader
    abiKind := (Arm64MemsetFreeState.tail before.nextblock bound frame 6 abi .Mint8unsigned 0).trans abiKind
    tagBytes := ?_ }
  intro j
  have kept := Arm64MemsetFreeState.tail before.nextblock bound frame 2
    ⟨view.tags.block,view.tags.binding⟩ .Mint8unsigned (j.val : Int)
  exact kept.trans (tagBytes j)

end KProgFormal.ClightRefinement.Arm64ProgramEntryMemsetAllocation
