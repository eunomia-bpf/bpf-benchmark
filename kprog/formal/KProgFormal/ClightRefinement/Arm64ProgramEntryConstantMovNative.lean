import KProgFormal.ClightRefinement.Arm64ProgramEntryOrdinaryMoveNative

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryConstantMovNative

open Arm64ProgramEntryAllocation (world allocation)
open Arm64MovImmediate

/-- Reuse the same producer storage after the repeated MOV's actual free.
The established register relation is transported to the real memory frontier
before executing the original constant16 call and same fetched LNSym step. -/
theorem execute {initial before written after : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {storage : Arm64ProducerRegisterStorage.Storage initial before entry}
    {prior : Reference.AArch64.State} {priorK : CC.Cont} {mark : BitVec 32}
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (result : OrdinaryCall.Result storage 1 (mark.setWidth 64) addresses origins prior priorK written after)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock after (.Vptr entry.block 0) s)
    (le : CC.TempEnv) (k : CC.Cont) (instruction : Reference.AArch64.Instruction)
    (decoded : instruction.decoded = .DPI (.Move_wide_imm (Wide.fields 2 (16#16) 0 false false)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    ∃ constantWritten constantAfter, OrdinaryCall.Result (result.storage bound) 2 (16#64) addresses origins s
        (.Kcall none Arm64ProgramFixture.f_arm64_execute_compile (allocation initial).1 le
          (.Kseq Arm64ProgramEntryOrdinaryMoves.afterSecond k)) constantWritten constantAfter ∧
      InternalRun world 207
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterFirst k
          (allocation initial).1 le after)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterSecond k
          (allocation initial).1 le constantAfter) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) after.nextblock constantAfter (.Vptr entry.block 0)
        (Reference.AArch64.step s).state ∧
      (Reference.AArch64.step s).events = [] ∧ (Reference.AArch64.step s).fault = none := by
  have actualBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat := by
    rw [result.nextblock,result.effect.nextblock]
    exact Nat.le_trans bound (FrameBelow.allocVariables
      (Arm64MovImmediate.allocated_bound world before) before.nextblock (Nat.le_refl _)).1
  have actualRegisters := (Arm64RegisterStorageFrontier.represents_iff (result.storage bound)
    before.nextblock bound addresses origins s).mp represented
  exact Arm64ProgramEntryOrdinaryMoveNative.constant (result.storage bound) actualBound false addresses origins
    s actualRegisters le k instruction decoded noError fetched

end KProgFormal.ClightRefinement.Arm64ProgramEntryConstantMovNative
