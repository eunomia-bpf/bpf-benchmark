import KProgFormal.ClightRefinement.Arm64ProgramEntryMemoryReturn
import KProgFormal.ClightRefinement.Arm64ProgramEntryResourceTransport

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryOrdinaryRights
open Arm64Producer (HeaderLocal)
open Arm64ProducerRegisterStorage (Storage)
open Arm64ProgramEntryAllocation (world)

section Result
variable {initial before written after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial before entry} {i : Fin 31} {value : BitVec 64}
    {addresses : Arm64Registers.PointerOrigins} {origins : Reference.Provenance.AArch64.Origins}
    {native : Reference.AArch64.State} {k : CC.Cont}
    (result : Arm64MovImmediate.OrdinaryCall.Result storage i value addresses origins native k written after)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
include result bound

/-- Actual allocation, both real register stores and the original free frame
retain every producer-block Cur/Max permission in the SAME completed call. -/
theorem permissions : ∀ block, block.toNat < (Arm64Producer.allocation initial).2.nextblock.toNat →
    CC.PMap.get block after.access = CC.PMap.get block before.access := by
  intro block owned
  have old := Nat.lt_of_lt_of_le owned bound
  have allocated := (Arm64Nop.entry_frame world before block old).2
  exact ((result.frame block old).2.trans (congrArg (CC.PMap.get block) result.effect.access)).trans allocated

theorem resources (prior : Arm64ProgramEntryResources.Resources initial before entry) :
    Arm64ProgramEntryResources.Resources initial after entry :=
  Arm64ProgramEntryResourceTransport.resources prior (Arm64ProducerTailFrame.of_kept entry i result.kept) (permissions result bound)

theorem gpr_other (r : Fin 31) (different : r ≠ i) :
    Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) r.val =
      Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) r.val := by
  rw [Arm64RegisterWrite.storage_gpr (result.storage bound) r,Arm64RegisterWrite.storage_gpr storage r]
  rw [result.kept.cell_load storage (result.storage bound) false r (Ne.symm different) .Mint64 0,
    result.kept.cell_load storage (result.storage bound) true r (Ne.symm different) .Mint8unsigned 0]

theorem next_bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat := by
  rw [result.nextblock,result.effect.nextblock]
  exact Nat.le_trans bound (FrameBelow.allocVariables (Arm64MovImmediate.allocated_bound world before)
    before.nextblock (Nat.le_refl _)).1

end Result
end KProgFormal.ClightRefinement.Arm64ProgramEntryOrdinaryRights
