import KProgFormal.ClightRefinement.X86ProducerGprStore

namespace KProgFormal.ClightRefinement.X86ProducerRaxReturn
open X86ProducerHeaderSource (producer)
open X86ProducerHeaderLocals (SourceLocal)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)
open X86ProducerGprAddress (afterRax)
open X86ProducerInputReturn (temps)

/-- The actual first input return/double casts/RAX value store/tag0 store reach
the original RCX route in9 internal transitions. Both stores are constructed
from the same allocated GPR rights, with no successful store/output view/frame
premise. Every other GPR/tag row and all other blocks retain their supplied
heap observations; the provider's supplied heap remains explicit. -/
theorem returned (before supplied : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (word : BitVec 64)
    (gprs : SourceLocal ge.genv_cenv before 0)
    (access : supplied.access = (allocation ge.genv_cenv before).2.access) :
    ∃ middle after, InternalRun ge 9
      (.Returnstate (.Vlong word) (X86ProducerFirstInput.continuation (allocation ge.genv_cenv before).1 le k) supplied)
      (.State producer afterRax k (allocation ge.genv_cenv before).1 (temps le word) after) ∧
    CC.Mem.store CC.Mptr supplied gprs.block 0 (.Vlong word) = some middle ∧
    CC.Mem.store .Mint8unsigned middle gprs.block 8 (.Vint 0) = some after ∧
    CC.Mem.load CC.Mptr after gprs.block 0 = some (.Vlong word) ∧
    CC.Mem.load .Mint8unsigned after gprs.block 8 = some (.Vint 0) ∧
    (∀ row : Fin 32, row ≠ 0 → row ≠ 1 →
      CC.Mem.load (X86ProducerGprStore.chunk row) after gprs.block (X86ProducerGprStore.offset row) =
      CC.Mem.load (X86ProducerGprStore.chunk row) supplied gprs.block (X86ProducerGprStore.offset row)) ∧
    (∀ c b ofs, b ≠ gprs.block → CC.Mem.load c after b ofs = CC.Mem.load c supplied b ofs) ∧
    FrameBelow before.nextblock supplied after ∧ after.access = supplied.access ∧ after.nextblock = supplied.nextblock := by
  have read : (temps le word).get X86_program_profile_bpf._t'1 = some (.Vlong word) := CC.PTree.gss _ _ _
  obtain ⟨middle, valueRun, valueStored, valueRead, valueOther, valueOutside, valueFrame, valueAccess, valueNext⟩ :=
    X86ProducerGprStore.write before supplied (temps le word) k X86ProducerInputReturn.following gprs 0
      X86_program_profile_bpf._t'1 word read access
  obtain ⟨after, tagRun, tagStored, tagRead, tagOther, tagOutside, tagFrame, tagAccess, tagNext⟩ :=
    X86ProducerGprStore.write before middle (temps le word) k afterRax gprs 1
      X86_program_profile_bpf._t'1 word read (valueAccess.trans access)
  have originalValue : InternalRun ge 2
      (.State producer X86ProducerInputReturn.destination (.Kseq X86ProducerInputReturn.following k)
        (allocation ge.genv_cenv before).1 (temps le word) supplied)
      (.State producer X86ProducerInputReturn.following k (allocation ge.genv_cenv before).1 (temps le word) middle) := by
    rw [X86ProducerGprAddress.source_destination]
    exact valueRun
  have originalTag : InternalRun ge 3
      (.State producer X86ProducerInputReturn.following k (allocation ge.genv_cenv before).1 (temps le word) middle)
      (.State producer afterRax k (allocation ge.genv_cenv before).1 (temps le word) after) := by
    rw [X86ProducerGprAddress.source_tag]
    exact .step trivial (CC.doStep_sound ge _ _ _ rfl) tagRun
  refine ⟨middle, after,
    ((X86ProducerInputReturn.to_destination ge (allocation ge.genv_cenv before).1 le supplied k word).trans originalValue).trans originalTag,
    valueStored, tagStored, ?_, tagRead, ?_, ?_, valueFrame.trans tagFrame, tagAccess.trans valueAccess, tagNext.trans valueNext⟩
  · exact (tagOther 0 (by decide +kernel)).trans valueRead
  · intro row notValue notTag
    exact (tagOther row notTag).trans (valueOther row notValue)
  · intro c b ofs different
    exact (tagOutside c b ofs different).trans (valueOutside c b ofs different)

/-- The original external step keeps its actual trace, word and complete
supplied memory, then the SAME constructed return/stores execute. The memory
ABI is supplied explicitly as current access equality, not inferred from the
imported external-call determinacy/trace-length laws. -/
theorem execute (before memory supplied : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (word : BitVec 64) (trace : CC.Trace) (gprs : SourceLocal ge.genv_cenv before 0)
    (provider : CC.externalCall X86RegisterWriteRspReleaseWord.inputEF (CC.Genv.toSenv ge.genv_genv)
      [.Vint (6#32)] memory trace (.Vlong word) supplied)
    (access : supplied.access = (allocation ge.genv_cenv before).2.access) :
    ∃ middle after, CC.Star (CC.Step2 ge)
      (.Callstate X86RegisterWriteRspReleaseWord.inputFunction [.Vint (6#32)]
        (X86ProducerFirstInput.continuation (allocation ge.genv_cenv before).1 le k) memory)
      trace (.State producer afterRax k (allocation ge.genv_cenv before).1 (temps le word) after) ∧
    CC.Mem.store CC.Mptr supplied gprs.block 0 (.Vlong word) = some middle ∧
    CC.Mem.store .Mint8unsigned middle gprs.block 8 (.Vint 0) = some after ∧
    CC.Mem.load CC.Mptr after gprs.block 0 = some (.Vlong word) ∧
    CC.Mem.load .Mint8unsigned after gprs.block 8 = some (.Vint 0) ∧
    (∀ row : Fin 32, row ≠ 0 → row ≠ 1 →
      CC.Mem.load (X86ProducerGprStore.chunk row) after gprs.block (X86ProducerGprStore.offset row) =
      CC.Mem.load (X86ProducerGprStore.chunk row) supplied gprs.block (X86ProducerGprStore.offset row)) ∧
    (∀ c b ofs, b ≠ gprs.block → CC.Mem.load c after b ofs = CC.Mem.load c supplied b ofs) ∧
    FrameBelow before.nextblock supplied after ∧ after.access = supplied.access ∧ after.nextblock = supplied.nextblock := by
  obtain ⟨middle, after, run, storedValue, storedTag, readValue, readTag, other, outside, frame, finalAccess, frontier⟩ :=
    returned before supplied le k word gprs access
  have call : CC.Star (CC.Step2 ge)
      (.Callstate X86RegisterWriteRspReleaseWord.inputFunction [.Vint (6#32)]
        (X86ProducerFirstInput.continuation (allocation ge.genv_cenv before).1 le k) memory)
      trace (.Returnstate (.Vlong word) (X86ProducerFirstInput.continuation (allocation ge.genv_cenv before).1 le k) supplied) :=
    .step _ _ _ _ _ _ (.external_function _ _ _ _ _ _ _ _ _ _ provider) (.refl _) (by simp [CC.E0, CC.Eapp])
  refine ⟨middle, after, ?_, storedValue, storedTag, readValue, readTag, other, outside, frame, finalAccess, frontier⟩
  simpa only [CC.E0, CC.Eapp, List.append_nil] using star_trans call run.sound

end KProgFormal.ClightRefinement.X86ProducerRaxReturn
