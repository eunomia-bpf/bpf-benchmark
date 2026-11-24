import KProgFormal.ClightRefinement.Arm64MemsetSource
import KProgFormal.ClightRefinement.Arm64MovImmediateOrdinaryFrame

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MemsetInputs

open Arm64ProgramEntryAllocation (world)
open Arm64MovImmediate

/-- The actual word/tag stores and real free give a scalar observation at
the reached heap frontier; this is readback from the same C effect. -/
theorem selected {initial before written after : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {storage : Arm64ProducerRegisterStorage.Storage initial before entry}
    {i : Fin 31} {value : BitVec 64} {addresses : Arm64Registers.PointerOrigins}
    {origins : Reference.Provenance.AArch64.Origins} {s : Reference.AArch64.State} {k : CC.Cont}
    (result : OrdinaryCall.Result storage i value addresses origins s k written after)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat) :
    Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) i.val = some (.Vlong value,.Vint 0) := by
  have actual := result.effect.gpr i
  simp only [eq_self,ite_true,Arm64RegisterWrite.written,Bool.false_eq_true,ite_false] at actual
  have atWritten : Arm64EntryMemory.gpr written.nextblock written (.Vptr entry.block 0) i.val =
      some (.Vlong value,.Vint 0) := by
    simpa only [result.effect.nextblock] using actual
  have framed := (Arm64EntryMemory.gpr_frame result.frame (.Vptr entry.block 0) i.val).trans
    ((Arm64RegisterStorageFrontier.gpr_eq result.effect.storage before.nextblock bound i).trans atWritten)
  exact (Arm64RegisterStorageFrontier.gpr_eq (result.storage bound) before.nextblock bound i).symm.trans framed

/-- Every other register's actual word and tag survive the complete ordinary
call, including its local allocation and release. -/
theorem other {initial before written after : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {storage : Arm64ProducerRegisterStorage.Storage initial before entry}
    {i : Fin 31} {value : BitVec 64} {addresses : Arm64Registers.PointerOrigins}
    {origins : Reference.Provenance.AArch64.Origins} {s : Reference.AArch64.State} {k : CC.Cont}
    (result : OrdinaryCall.Result storage i value addresses origins s k written after)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (j : Fin 31) (different : i ≠ j) :
    Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) j.val =
      Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) j.val := by
  rw [Arm64RegisterWrite.storage_gpr (result.storage bound) j,
    result.kept.cell_load storage (result.storage bound) false j different .Mint64 0,
    result.kept.cell_load storage (result.storage bound) true j different .Mint8unsigned 0,
    ← Arm64RegisterWrite.storage_gpr storage j]

theorem bound_after {initial before written after : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {storage : Arm64ProducerRegisterStorage.Storage initial before entry}
    {i : Fin 31} {value : BitVec 64} {addresses : Arm64Registers.PointerOrigins}
    {origins : Reference.Provenance.AArch64.Origins} {s : Reference.AArch64.State} {k : CC.Cont}
    (result : OrdinaryCall.Result storage i value addresses origins s k written after)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat) :
    (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat := by
  rw [result.nextblock,result.effect.nextblock]
  exact Nat.le_trans bound (FrameBelow.allocVariables (Arm64MovImmediate.allocated_bound world before)
    before.nextblock (Nat.le_refl _)).1

/-- The two preceding genuine MOV calls supply the actual memset inputs.
R1 is the original zero-extended mark and R2 is16; both tag bytes are0.
Every source-read equation follows the actual stores, surviving cells and
frees, rather than an additional successful-read premise. -/
theorem original_reads {initial before markWritten markAfter constantWritten constantAfter : CC.Mem}
    {entry : Arm64Producer.HeaderLocal initial}
    {storage : Arm64ProducerRegisterStorage.Storage initial before entry}
    {addresses : Arm64Registers.PointerOrigins} {origins : Reference.Provenance.AArch64.Origins}
    {prior next : Reference.AArch64.State} {priorK nextK : CC.Cont} (mark : BitVec 32)
    (first : OrdinaryCall.Result storage 1 (mark.setWidth 64) addresses origins prior priorK markWritten markAfter)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (second : OrdinaryCall.Result (first.storage bound) 2 (16#64) addresses origins next nextK
      constantWritten constantAfter) (k : CC.Cont) :
    InternalRun world 162
      (.Callstate (.Internal Arm64MemsetSource.handler) [.Vptr entry.block 0] k constantAfter)
      (.State Arm64MemsetSource.handler Arm64MemsetSource.afterReads (Arm64MemsetSource.continuation k)
        (Arm64MemsetSource.allocation constantAfter).1
        (Arm64MemsetSource.readTemps entry.block (mark.setWidth 64) (16#64))
        (Arm64MemsetSource.allocation constantAfter).2) := by
  have nextBound := bound_after first bound
  have byte := (other second nextBound 1 (by decide)).trans (selected first bound)
  have length := selected second nextBound
  exact Arm64MemsetSource.enter_reads constantAfter entry.block (mark.setWidth 64) (16#64) k byte length

end KProgFormal.ClightRefinement.Arm64MemsetInputs
