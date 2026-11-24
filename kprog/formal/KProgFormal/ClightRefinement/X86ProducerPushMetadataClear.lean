import KProgFormal.ClightRefinement.X86ProducerPushMetadataClearAddress

namespace KProgFormal.ClightRefinement.X86ProducerPushMetadataClear
open X86ProducerLayout (ge)
open X86ProducerPushBody (handler)
open X86ProducerPushMetadataClearSource

def tagTemps (le : CC.TempEnv) (tagBlock : CC.Block) (tagOffset : CC.Integers.Ptrofs) : CC.TempEnv :=
  le.set X86_program_profile_bpf._t'215 (.Vptr tagBlock tagOffset)
def temps (le : CC.TempEnv) (tagBlock pointerBlock : CC.Block) (tagOffset pointerOffset : CC.Integers.Ptrofs) : CC.TempEnv :=
  (tagTemps le tagBlock tagOffset).set X86_program_profile_bpf._t'214 (.Vptr pointerBlock pointerOffset)

/-- Both real slot5 stores follow initial current rights. Actual pointer loads,
all13 original loop/sequence/store transitions, readbacks and frames remain
part of one source execution; no successful-store premise is supplied. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (binding tagBlock pointerBlock : CC.Block) (tagOffset pointerOffset : CC.Integers.Ptrofs)
    (bound : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (tagReadValue : CC.Mem.load CC.Mptr memory binding 96 = some (.Vptr tagBlock tagOffset))
    (pointerReadValue : CC.Mem.load CC.Mptr memory binding 104 = some (.Vptr pointerBlock pointerOffset))
    (notHeader : tagBlock ≠ binding) (different : tagBlock ≠ pointerBlock)
    (tagWritable : CC.Mem.validAccess memory .Mint8unsigned tagBlock (CC.Integers.Ptrofs.unsigned tagOffset) .Writable = true)
    (pointerWritable : CC.Mem.validAccess memory CC.Mptr pointerBlock (CC.Integers.Ptrofs.unsigned pointerOffset) .Writable = true) :
    ∃ middle after,
    CC.Mem.store .Mint8unsigned memory tagBlock (CC.Integers.Ptrofs.unsigned tagOffset) (.Vint 0) = some middle ∧
    CC.Mem.store CC.Mptr middle pointerBlock (CC.Integers.Ptrofs.unsigned pointerOffset) (.Vlong 0) = some after ∧
    InternalRun ge 13 (.State handler (X86ProducerPushMetadataSource.clear 5) k e le memory)
      (.State handler .Sskip k e (temps le tagBlock pointerBlock tagOffset pointerOffset) after) ∧
    CC.Mem.load .Mint8unsigned after tagBlock (CC.Integers.Ptrofs.unsigned tagOffset) = some (.Vint 0) ∧
    CC.Mem.load CC.Mptr after pointerBlock (CC.Integers.Ptrofs.unsigned pointerOffset) = some (.Vlong 0) ∧
    after.access = memory.access ∧ after.nextblock = memory.nextblock ∧
    (∀ c b ofs, b ≠ tagBlock → b ≠ pointerBlock → CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs) := by
  obtain ⟨middle, tagStored⟩ : ∃ middle, CC.Mem.store .Mint8unsigned memory tagBlock
      (CC.Integers.Ptrofs.unsigned tagOffset) (.Vint 0) = some middle := by
    simp only [CC.Mem.store, tagWritable, ite_true]
    exact ⟨_,rfl⟩
  have nextPermission := (CC.Mem.validAccess_store_eq tagStored CC.Mptr pointerBlock
    (CC.Integers.Ptrofs.unsigned pointerOffset) .Writable).trans pointerWritable
  obtain ⟨after, pointerStored⟩ : ∃ after, CC.Mem.store CC.Mptr middle pointerBlock
      (CC.Integers.Ptrofs.unsigned pointerOffset) (.Vlong 0) = some after := by
    simp only [CC.Mem.store, nextPermission, ite_true]
    exact ⟨_,rfl⟩
  have keptPointer := (CC.Mem.load_store_other tagStored CC.Mptr binding 104 (.inl (Ne.symm notHeader))).trans pointerReadValue
  have keptBinding : (tagTemps le tagBlock tagOffset).get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0) := by
    simpa +decide [tagTemps, CC.PTree.gso] using bound
  have h1 := X86ProducerPushMetadataClearAddress.tag_value e le memory binding tagBlock tagOffset bound tagReadValue
  have h2 := X86ProducerPushMetadataClearAddress.pointer_value e (tagTemps le tagBlock tagOffset) middle binding pointerBlock pointerOffset keptBinding keptPointer
  dsimp only [tagTemps] at h2
  have castTag : CC.Cop.semCast (.Vint (CC.Integers.Int.repr 0)) CC.tuint CC.tuchar memory = some (.Vint 0) := rfl
  have castPointer : CC.Cop.semCast (.Vint (CC.Integers.Int.repr 0)) CC.tint (CC.tptr CC.tvoid) middle = some (.Vlong 0) := rfl
  have modeTag : CC.accessMode CC.tuchar = .By_value .Mint8unsigned := rfl
  have modePointer : CC.accessMode (CC.tptr CC.tvoid) = .By_value CC.Mptr := rfl
  refine ⟨middle,after,tagStored,pointerStored,?_,?_,CC.Mem.load_store_same pointerStored,
    (CC.Mem.store_access pointerStored).trans (CC.Mem.store_access tagStored),
    (CC.Mem.store_nextblock pointerStored).trans (CC.Mem.store_nextblock tagStored),?_⟩
  · rw [source.1,source.2]
    apply internalRun_of_steps
    all_goals simp only [steps, InternalPath, InternalState, CC.doStep, reads.1, reads.2.1, stores.1, stores.2,
      CC.doEvalExpr, CC.doEvalLvalue, h1, h2, CC.PTree.gss, CC.doAssignLoc, CC.typeof, modeTag, modePointer,
      castTag, castPointer, CC.Mem.storev, tagStored, pointerStored, tagTemps, temps,
      CC.E0, CC.Eapp, List.nil_append, true_and]
  · exact (CC.Mem.load_store_other pointerStored .Mint8unsigned tagBlock _ (.inl different)).trans (CC.Mem.load_store_same tagStored)
  · intro c b ofs notTag notPointer
    exact (CC.Mem.load_store_other pointerStored c b ofs (.inl notPointer)).trans
      (CC.Mem.load_store_other tagStored c b ofs (.inl notTag))

theorem stable (le : CC.TempEnv) (tagBlock pointerBlock : CC.Block) (tagOffset pointerOffset : CC.Integers.Ptrofs) :
    (temps le tagBlock pointerBlock tagOffset pointerOffset).get X86_program_profile_bpf.___x86_bind = le.get X86_program_profile_bpf.___x86_bind ∧
    (temps le tagBlock pointerBlock tagOffset pointerOffset).get X86_program_profile_bpf.___x86_sv_index = le.get X86_program_profile_bpf.___x86_sv_index ∧
    (temps le tagBlock pointerBlock tagOffset pointerOffset).get X86_program_profile_bpf.___x86_sv_width = le.get X86_program_profile_bpf.___x86_sv_width ∧
    (temps le tagBlock pointerBlock tagOffset pointerOffset).get X86_program_profile_bpf.___x86_l_pp_value = le.get X86_program_profile_bpf.___x86_l_pp_value := by
  simp +decide [temps, tagTemps, CC.PTree.gso]

end KProgFormal.ClightRefinement.X86ProducerPushMetadataClear
