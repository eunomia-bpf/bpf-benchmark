import KProgFormal.ClightRefinement.X86ProducerGprEnter

namespace KProgFormal.ClightRefinement.X86ProducerGprPair
open X86ProducerGprSites
open X86ProducerHeaderSource (producer)
open X86ProducerHeaderLocals (SourceLocal)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)

private theorem rows : ∀ i : Fin 16,
    X86ProducerGprStore.register (valueRow i) = i ∧ (valueRow i).val % 2 ≠ 1 ∧
    X86ProducerGprStore.register (tagRow i) = i ∧ (tagRow i).val % 2 = 1 := by decide +kernel

/-- Both genuine value/tag stores execute for every original GPR site in5
transitions, including the sequence before the tag. Rights and successful
stores derive the SAME allocated object; all other typed rows/blocks and
post-provider raw caller frame follow the actual stores. -/
theorem written (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16)
    (word : BitVec 64) (gprs : SourceLocal ge.genv_cenv before 0)
    (read : le.get (site i).savedName = some (.Vlong word))
    (access : memory.access = (allocation ge.genv_cenv before).2.access) :
    ∃ middle after, InternalRun ge 5
      (.State producer (site i).destination (.Kseq (X86ProducerGprEnter.tail i) k) (allocation ge.genv_cenv before).1 le memory)
      (.State producer (site i).following k (allocation ge.genv_cenv before).1 le after) ∧
    CC.Mem.store CC.Mptr memory gprs.block (16 * (i.val : Int)) (.Vlong word) = some middle ∧
    CC.Mem.store .Mint8unsigned middle gprs.block (16 * (i.val : Int) + 8) (.Vint 0) = some after ∧
    CC.Mem.load CC.Mptr after gprs.block (16 * (i.val : Int)) = some (.Vlong word) ∧
    CC.Mem.load .Mint8unsigned after gprs.block (16 * (i.val : Int) + 8) = some (.Vint 0) ∧
    (∀ row : Fin 32, row ≠ valueRow i → row ≠ tagRow i →
      CC.Mem.load (X86ProducerGprStore.chunk row) after gprs.block (X86ProducerGprStore.offset row) =
      CC.Mem.load (X86ProducerGprStore.chunk row) memory gprs.block (X86ProducerGprStore.offset row)) ∧
    (∀ c b ofs, b ≠ gprs.block → CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs) ∧
    FrameBelow before.nextblock memory after ∧ after.access = memory.access ∧ after.nextblock = memory.nextblock := by
  obtain ⟨middle, valueRun, valueStored, valueRead, valueOther, valueOutside, valueFrame, valueAccess, valueNext⟩ :=
    X86ProducerGprStore.write before memory le k (X86ProducerGprEnter.tail i) gprs (valueRow i) (site i).savedName word read access
  obtain ⟨after, tagRun, tagStored, tagRead, tagOther, tagOutside, tagFrame, tagAccess, tagNext⟩ :=
    X86ProducerGprStore.write before middle le k (site i).following gprs (tagRow i) (site i).savedName word read (valueAccess.trans access)
  have originalValue : InternalRun ge 2
      (.State producer (site i).destination (.Kseq (X86ProducerGprEnter.tail i) k) (allocation ge.genv_cenv before).1 le memory)
      (.State producer (X86ProducerGprEnter.tail i) k (allocation ge.genv_cenv before).1 le middle) := by
    rw [(source_stores i).1]
    exact valueRun
  have originalTag : InternalRun ge 3
      (.State producer (X86ProducerGprEnter.tail i) k (allocation ge.genv_cenv before).1 le middle)
      (.State producer (site i).following k (allocation ge.genv_cenv before).1 le after) := by
    unfold X86ProducerGprEnter.tail
    rw [(source_stores i).2]
    exact .step trivial (CC.doStep_sound ge _ _ _ rfl) tagRun
  have different : valueRow i ≠ tagRow i := by
    intro equal
    have same := congrArg Fin.val equal
    simp only [valueRow, tagRow] at same
    omega
  have finalValue := (tagOther (valueRow i) different).trans valueRead
  refine ⟨middle, after, originalValue.trans originalTag, ?_, ?_, ?_, ?_, ?_, ?_,
    valueFrame.trans tagFrame, tagAccess.trans valueAccess, tagNext.trans valueNext⟩
  · simpa only [X86ProducerGprStore.chunk, X86ProducerGprStore.offset, X86ProducerGprStore.value,
      (rows i).1, (rows i).2.1, ite_false, Int.add_zero] using valueStored
  · simpa only [X86ProducerGprStore.chunk, X86ProducerGprStore.offset, X86ProducerGprStore.value,
      (rows i).2.2.1, (rows i).2.2.2, ite_true] using tagStored
  · simpa only [X86ProducerGprStore.chunk, X86ProducerGprStore.offset, X86ProducerGprStore.value,
      (rows i).1, (rows i).2.1, ite_false, Int.add_zero] using finalValue
  · simpa only [X86ProducerGprStore.chunk, X86ProducerGprStore.offset, X86ProducerGprStore.value,
      (rows i).2.2.1, (rows i).2.2.2, ite_true] using tagRead
  · intro row notValue notTag
    exact (tagOther row notTag).trans (valueOther row notValue)
  · intro c b ofs differentBlock
    exact (tagOutside c b ofs differentBlock).trans (valueOutside c b ofs differentBlock)

end KProgFormal.ClightRefinement.X86ProducerGprPair
