import KProgFormal.ClightRefinement.X86ProducerGprPair

namespace KProgFormal.ClightRefinement.X86ProducerGprExecute
open X86ProducerGprSites
open X86ProducerHeaderSource (producer)
open X86ProducerHeaderLocals (SourceLocal)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)

/-- Each ordinary original GPR site executes its genuine condition, call,
external outcome, both pointer casts and both stores to the real successor.
The actual provider trace/word/complete supplied heap are preserved; current
supplied access is an explicit ABI condition. -/
theorem ordinary (before memory supplied : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (i : Fin 16) (notRsp : i ≠ 4) (word : BitVec 64) (trace : CC.Trace)
    (gprs : SourceLocal ge.genv_cenv before 0)
    (provider : CC.externalCall X86RegisterWriteRspReleaseWord.inputEF (CC.Genv.toSenv ge.genv_genv)
      [.Vint (6#32)] memory trace (.Vlong word) supplied)
    (access : supplied.access = (allocation ge.genv_cenv before).2.access) :
    ∃ after, CC.Star (CC.Step2 ge)
      (.State producer (site i).whole k (allocation ge.genv_cenv before).1 le memory) trace
      (.State producer (site i).following k (allocation ge.genv_cenv before).1 (X86ProducerGprEnter.temps i le word) after) ∧
    CC.Mem.load CC.Mptr after gprs.block (16 * (i.val : Int)) = some (.Vlong word) ∧
    CC.Mem.load .Mint8unsigned after gprs.block (16 * (i.val : Int) + 8) = some (.Vint 0) ∧
    (∀ row : Fin 32, row ≠ valueRow i → row ≠ tagRow i →
      CC.Mem.load (X86ProducerGprStore.chunk row) after gprs.block (X86ProducerGprStore.offset row) =
      CC.Mem.load (X86ProducerGprStore.chunk row) supplied gprs.block (X86ProducerGprStore.offset row)) ∧
    (∀ c b ofs, b ≠ gprs.block → CC.Mem.load c after b ofs = CC.Mem.load c supplied b ofs) ∧
    FrameBelow before.nextblock supplied after ∧ after.access = supplied.access ∧ after.nextblock = supplied.nextblock := by
  have entered := X86ProducerGprEnter.enter before memory le k i notRsp
  have returned := X86ProducerGprEnter.returned (allocation ge.genv_cenv before).1 le supplied k i word
  have read : (X86ProducerGprEnter.temps i le word).get (site i).savedName = some (.Vlong word) := CC.PTree.gss _ _ _
  obtain ⟨middle, after, written, storedValue, storedTag, readValue, readTag, other, outside, frame, finalAccess, frontier⟩ :=
    X86ProducerGprPair.written before supplied (X86ProducerGprEnter.temps i le word) k i word gprs read access
  have call : CC.Star (CC.Step2 ge)
      (.Callstate X86RegisterWriteRspReleaseWord.inputFunction [.Vint (6#32)]
        (X86ProducerGprEnter.continuation i (allocation ge.genv_cenv before).1 le k) memory)
      trace (.Returnstate (.Vlong word)
        (X86ProducerGprEnter.continuation i (allocation ge.genv_cenv before).1 le k) supplied) :=
    .step _ _ _ _ _ _ (.external_function _ _ _ _ _ _ _ _ _ _ provider) (.refl _) (by simp [CC.E0, CC.Eapp])
  refine ⟨after, ?_, readValue, readTag, other, outside, frame, finalAccess, frontier⟩
  simpa only [CC.E0, CC.Eapp, List.nil_append, List.append_nil] using
    star_trans (star_trans entered.sound call) (returned.trans written).sound

/-- The genuine RSP branch stores its raw zero pointer and tag0 in10 internal
transitions, with no external outcome or invented provider call. -/
theorem rsp (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (gprs : SourceLocal ge.genv_cenv before 0)
    (access : memory.access = (allocation ge.genv_cenv before).2.access) :
    ∃ after, InternalRun ge 10
      (.State producer (site 4).whole k (allocation ge.genv_cenv before).1 le memory)
      (.State producer (site 4).following k (allocation ge.genv_cenv before).1
        (le.set (site 4).savedName (.Vlong 0)) after) ∧
    CC.Mem.load CC.Mptr after gprs.block 64 = some (.Vlong 0) ∧
    CC.Mem.load .Mint8unsigned after gprs.block 72 = some (.Vint 0) ∧
    (∀ row : Fin 32, row ≠ valueRow 4 → row ≠ tagRow 4 →
      CC.Mem.load (X86ProducerGprStore.chunk row) after gprs.block (X86ProducerGprStore.offset row) =
      CC.Mem.load (X86ProducerGprStore.chunk row) memory gprs.block (X86ProducerGprStore.offset row)) ∧
    (∀ c b ofs, b ≠ gprs.block → CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs) ∧
    FrameBelow before.nextblock memory after ∧ after.access = memory.access ∧ after.nextblock = memory.nextblock := by
  have entered := X86ProducerGprEnter.rsp (allocation ge.genv_cenv before).1 le memory k
  have read : (le.set (site 4).savedName (.Vlong 0)).get (site 4).savedName = some (.Vlong 0) := CC.PTree.gss _ _ _
  obtain ⟨middle, after, written, storedValue, storedTag, readValue, readTag, other, outside, frame, finalAccess, frontier⟩ :=
    X86ProducerGprPair.written before memory (le.set (site 4).savedName (.Vlong 0)) k 4 0 gprs read access
  exact ⟨after, entered.trans written, readValue, readTag, other, outside, frame, finalAccess, frontier⟩

end KProgFormal.ClightRefinement.X86ProducerGprExecute
