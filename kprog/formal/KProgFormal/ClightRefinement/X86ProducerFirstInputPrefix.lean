import KProgFormal.ClightRefinement.X86ProducerFirstInput

namespace KProgFormal.ClightRefinement.X86ProducerFirstInputPrefix
open X86ProducerGhostSource X86ProducerGhostStore
open X86ProducerInitialPrefix (contextValues)
open X86ProducerHeaderSource (producer)
open X86ProducerHeaderLocals (Local)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)

/-- The SAME original entry/ABI/ghost/context execution reaches the first real
kind-6 external Callstate in618 transitions, preserving all constructed
readbacks/current typed inputs/rights and the genuine caller continuation.
The provider's actual output trace/word/supplied memory is still an independent obligation. -/
theorem from_call (before : CC.Mem) (ctx : CC.Val) (k : CC.Cont) :
    ∃ abi : Local ge.genv_cenv before X86_program_profile_bpf.___x86_sim_abi X86ProducerAbiSource.abiType,
    ∃ locals : Locals before, ∃ after,
    InternalRun ge 618 (.Callstate (.Internal producer) [ctx] k before)
      (.Callstate X86RegisterWriteRspReleaseWord.inputFunction [.Vint (6#32)]
        (X86ProducerFirstInput.continuation (allocation ge.genv_cenv before).1
          (finalTemps (contextTemps (X86ProducerEntry.initialTemps ctx))) k) after) ∧
    (∀ i, CC.Mem.load (X86ProducerAbiSource.chunk i) after abi.block (X86ProducerAbiSource.offset i) = some (X86ProducerAbiSource.value i)) ∧
    (∀ i, CC.Mem.load (chunk i) after (locals i).block 0 = some (value i)) ∧
    X86ProducerContextSource.Typed contextValues ∧
    (∀ i, (finalTemps (contextTemps (X86ProducerEntry.initialTemps ctx))).get
      (X86ProducerContextSource.tempName i) = some (contextValues i)) ∧
    FrameBelow before.nextblock before after ∧
    after.access = (allocation ge.genv_cenv before).2.access ∧ after.nextblock = (allocation ge.genv_cenv before).2.nextblock := by
  obtain ⟨abi, locals, after, run, abiReads, ghostReads, typed, inputs, frame, access, frontier⟩ :=
    X86ProducerInitialPrefix.from_call before ctx k
  exact ⟨abi, locals, after,
    run.trans (X86ProducerFirstInput.enter before after
      (finalTemps (contextTemps (X86ProducerEntry.initialTemps ctx))) k),
    abiReads, ghostReads, typed, inputs, frame, access, frontier⟩

end KProgFormal.ClightRefinement.X86ProducerFirstInputPrefix
