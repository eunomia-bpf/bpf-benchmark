import KProgFormal.ClightRefinement.X86ProducerStackBaseSource

namespace KProgFormal.ClightRefinement.X86ProducerStackBaseReturn
open X86ProducerStackBaseSource
open X86ProducerHeaderSource (producer)
open X86ProducerHeaderLocals (SourceLocal)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)
open X86RegisterWriteRspReleaseWord (inputFunction inputEF)

def temps (le : CC.TempEnv) (word : BitVec 64) : CC.TempEnv := le.set resultName (.Vlong word)

/-- The genuine kind1 return reaches its original native-base assignment,
keeping the complete supplied heap and original continuation. -/
theorem returned (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (k : CC.Cont) (word : BitVec 64) :
    InternalRun ge 2 (.Returnstate (.Vlong word) (continuation e le k) memory)
      (.State producer assignment (.Kseq finalSetup k) e (temps le word) memory) := by
  exact .step trivial (CC.doStep_sound ge _ _ _ rfl)
    (.step trivial (CC.doStep_sound ge _ _ _ rfl) (.refl _))

/-- Actual original native-base local rights construct the full-word store,
readback and post-provider frame, not a successful-store premise. -/
theorem stored (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (word : BitVec 64)
    (base : SourceLocal ge.genv_cenv before 14) (read : le.get resultName = some (.Vlong word))
    (access : memory.access = (allocation ge.genv_cenv before).2.access) :
    ∃ after, InternalRun ge 2
      (.State producer assignment (.Kseq finalSetup k) (allocation ge.genv_cenv before).1 le memory)
      (.State producer finalSetup k (allocation ge.genv_cenv before).1 le after) ∧
    CC.Mem.store .Mint64 memory base.block 0 (.Vlong word) = some after ∧
    CC.Mem.load .Mint64 after base.block 0 = some (.Vlong word) ∧
    (∀ c b ofs, b ≠ base.block → CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs) ∧
    FrameBelow before.nextblock memory after ∧ after.access = memory.access ∧ after.nextblock = memory.nextblock := by
  have evaluated : CC.doEvalExpr ge (allocation ge.genv_cenv before).1 le memory (.Etempvar resultName CC.tulong) = some (.Vlong word) := by
    simp only [CC.doEvalExpr, read]
  rw [source_assignment]
  exact X86ProducerScalarStore.write before memory le k finalSetup 0 base (.Etempvar resultName CC.tulong)
      (.Vlong word) (.Vlong word) evaluated rfl rfl access

/-- The actual kind1 external outcome/trace/full supplied heap and real return
and store reach the original final-context setup. Permission preservation of
the supplied heap remains explicit; no kind6 ABI or outcome is substituted. -/
theorem execute (before memory supplied : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (word : BitVec 64) (trace : CC.Trace) (base : SourceLocal ge.genv_cenv before 14)
    (provider : CC.externalCall inputEF (CC.Genv.toSenv ge.genv_genv) [.Vint (1#32)] memory trace (.Vlong word) supplied)
    (access : supplied.access = (allocation ge.genv_cenv before).2.access) :
    ∃ after, CC.Star (CC.Step2 ge)
      (.Callstate inputFunction [.Vint (1#32)] (continuation (allocation ge.genv_cenv before).1 le k) memory) trace
      (.State producer finalSetup k (allocation ge.genv_cenv before).1 (temps le word) after) ∧
    CC.Mem.store .Mint64 supplied base.block 0 (.Vlong word) = some after ∧
    CC.Mem.load .Mint64 after base.block 0 = some (.Vlong word) ∧
    (∀ c b ofs, b ≠ base.block → CC.Mem.load c after b ofs = CC.Mem.load c supplied b ofs) ∧
    FrameBelow before.nextblock supplied after ∧ after.access = supplied.access ∧ after.nextblock = supplied.nextblock := by
  have returnRun := returned (allocation ge.genv_cenv before).1 le supplied k word
  obtain ⟨after, storeRun, equation, read, outside, frame, rights, next⟩ :=
    stored before supplied (temps le word) k word base (CC.PTree.gss _ _ _) access
  have call : CC.Star (CC.Step2 ge)
      (.Callstate inputFunction [.Vint (1#32)] (continuation (allocation ge.genv_cenv before).1 le k) memory) trace
      (.Returnstate (.Vlong word) (continuation (allocation ge.genv_cenv before).1 le k) supplied) :=
    .step _ _ _ _ _ _ (.external_function _ _ _ _ _ _ _ _ _ _ provider) (.refl _) (by simp [CC.E0, CC.Eapp])
  refine ⟨after, ?_, equation, read, outside, frame, rights, next⟩
  simpa only [CC.E0, CC.Eapp, List.append_nil] using star_trans call (returnRun.trans storeRun).sound

end KProgFormal.ClightRefinement.X86ProducerStackBaseReturn
