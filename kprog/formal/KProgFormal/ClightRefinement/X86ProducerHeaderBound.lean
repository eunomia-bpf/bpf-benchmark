import KProgFormal.ClightRefinement.X86ProducerLayout

namespace KProgFormal.ClightRefinement.X86ProducerHeaderBound
open X86ProducerContextSource (Typed tempName followingCalls)
open X86ProducerBindLoop (firstCall)
open X86ProducerHeaderSource (producer headerStart)
open X86ProducerHeaderLocals
open X86ProducerHeaderViews (ghosts)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)

/-- This version binds every header/register/cache layout and the GPR-array
address to the complete original exported world. Only actual current typed
inputs/access at the source cut remain; it does not assert prefix/provider execution. -/
theorem to_first_call
    (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (values : Fin 5 → CC.Val) (typed : Typed values)
    (inputs : ∀ i, le.get (tempName i) = some (values i))
    (access : memory.access = (allocation ge.genv_cenv before).2.access) :
    ∃ entry : HeaderLocal ge.genv_cenv before,
    ∃ sources : (i : Fin 24) → SourceLocal ge.genv_cenv before i, ∃ after,
    InternalRun ge 94 (.State producer headerStart k (allocation ge.genv_cenv before).1 le memory)
      (.State producer firstCall (.Kseq followingCalls k) (allocation ge.genv_cenv before).1 le after) ∧
    X86ReleaseProvider.View after entry.block (sources 1).block 0 ∧
    X86CallFrameComplete.View after entry.block (ghosts sources) ∧
    CC.Mem.load CC.Mptr after entry.block 0 = some (.Vptr (sources 0).block 0) ∧
    (∀ i, CC.Mem.load (X86ProducerContextSource.chunk i) after entry.block (X86ProducerContextSource.offset i) = some (values i)) ∧
    entry.block ≠ (sources 1).block ∧ X86CallFrameComplete.Outside (ghosts sources) (sources 1).block ∧
    X86CallFrameComplete.Separated entry.block (ghosts sources) ∧
    (sources 1).block.toNat < after.nextblock.toNat ∧
    (∀ slot, ((ghosts sources).tag slot).1.toNat < after.nextblock.toNat ∧
      ((ghosts sources).pointer slot).1.toNat < after.nextblock.toNat) ∧
    (∀ c b ofs, b ≠ entry.block → CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs) ∧
    FrameBelow before.nextblock memory after ∧ after.access = memory.access ∧ after.nextblock = memory.nextblock := by
  exact X86ProducerHeaderComplete.to_first_call ge
    X86ProducerLayout.layouts.1 X86ProducerLayout.layouts.2.1 X86ProducerLayout.layouts.2.2.1
    X86ProducerLayout.registersRecord X86ProducerLayout.layouts.2.2.2 X86ProducerLayout.cells_offset
    before memory le k values typed inputs access

end KProgFormal.ClightRefinement.X86ProducerHeaderBound
