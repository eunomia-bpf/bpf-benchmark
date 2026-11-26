import KProgFormal.ClightRefinement.Arm64ProgramEntryResourceTransport

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryCallPermissions
open Arm64ProgramEntryAllocation (world)

/-- Actual allocation, a proved body-store access equality and the real
free frame retain every original producer-block Cur/Max permission. The
caller supplies these laws from its SAME completed source Result. -/
theorem of_call {initial before written after : CC.Mem}
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (access : written.access = (Arm64Nop.allocation world before).2.access)
    (freed : FrameBelow before.nextblock written after) :
    ∀ block, block.toNat < (Arm64Producer.allocation initial).2.nextblock.toNat →
      CC.PMap.get block after.access = CC.PMap.get block before.access := by
  intro block owned
  have old := Nat.lt_of_lt_of_le owned bound
  exact (freed block old).2.trans
    ((congrArg (CC.PMap.get block) access).trans (Arm64Nop.entry_frame world before block old).2)

end KProgFormal.ClightRefinement.Arm64ProgramEntryCallPermissions
