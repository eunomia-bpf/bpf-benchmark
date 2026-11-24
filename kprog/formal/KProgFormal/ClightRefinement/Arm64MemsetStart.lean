import KProgFormal.ClightRefinement.Arm64MemsetInputs
import KProgFormal.ClightRefinement.Arm64MemsetLoop

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MemsetStart

open Arm64ProgramEntryAllocation (world)
open Arm64MovImmediate

/-- From the two original MOV effects, enter the genuine memset call and
reach its first real byte-write body. The input values, zero scalar tags,
unsigned length16 and actual first loop guard all follow from that execution.
The allocated memory and all remaining original source effects are retained. -/
theorem original {initial before markWritten markAfter constantWritten constantAfter : CC.Mem}
    {entry : Arm64Producer.HeaderLocal initial}
    {storage : Arm64ProducerRegisterStorage.Storage initial before entry}
    {addresses : Arm64Registers.PointerOrigins} {origins : Reference.Provenance.AArch64.Origins}
    {prior next : Reference.AArch64.State} {priorK nextK : CC.Cont} (mark : BitVec 32)
    (first : OrdinaryCall.Result storage 1 (mark.setWidth 64) addresses origins prior priorK markWritten markAfter)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (second : OrdinaryCall.Result (first.storage bound) 2 (16#64) addresses origins next nextK
      constantWritten constantAfter) (k : CC.Cont) :
    InternalRun world 170
      (.Callstate (.Internal Arm64MemsetSource.handler) [.Vptr entry.block 0] k constantAfter)
      (.State Arm64MemsetSource.handler Arm64MemsetLoop.write
        (Arm64MemsetLoop.writeCont (.Kseq Arm64MemsetLoop.effects (Arm64MemsetSource.continuation k)))
        (Arm64MemsetSource.allocation constantAfter).1
        (Arm64MemsetLoop.initializedTemps entry.block (mark.setWidth 64) (16#64))
        (Arm64MemsetSource.allocation constantAfter).2) := by
  have reads := Arm64MemsetInputs.original_reads mark first bound second k
  have initializeLoop := Arm64MemsetLoop.start (Arm64MemsetSource.allocation constantAfter).1
    (Arm64MemsetSource.allocation constantAfter).2 entry.block (mark.setWidth 64) (16#64)
    (Arm64MemsetSource.continuation k)
  have guard := Arm64MemsetLoop.guard_true (Arm64MemsetSource.allocation constantAfter).1
    (Arm64MemsetLoop.initializedTemps entry.block (mark.setWidth 64) (16#64))
    (Arm64MemsetSource.allocation constantAfter).2
    (.Kseq Arm64MemsetLoop.effects (Arm64MemsetSource.continuation k)) 0 (16#64)
    (by simp only [Arm64MemsetLoop.initializedTemps,CC.PTree.gss])
    (by simp +decide only [Arm64MemsetLoop.initializedTemps,Arm64MemsetSource.readTemps,
      CC.PTree.gss,CC.PTree.gso]) (by decide)
  exact (reads.trans initializeLoop).trans guard

end KProgFormal.ClightRefinement.Arm64MemsetStart
