import KProgFormal.ClightRefinement.X86ProducerContextStore

namespace KProgFormal.ClightRefinement.X86ProducerContextInitialize
open X86ProducerContextSource
open X86ProducerHeaderSource (producer afterHeader)
open X86ProducerHeaderLocals
open X86ProducerCacheAllocation (allocation)

private theorem run_rows (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings = some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (before : CC.Mem) (entry : HeaderLocal ge.genv_cenv before)
    (values : Fin 5 → CC.Val) (typed : Typed values) (rows : List (Fin 5))
    (rest : CC.Stmt) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (inputs : ∀ i, le.get (tempName i) = some (values i))
    (access : memory.access = (allocation ge.genv_cenv before).2.access) :
    ∃ after, InternalRun ge (3 * rows.length)
      (.State producer (rows.foldr (fun i next => .Ssequence (assignment i) next) rest)
        k (allocation ge.genv_cenv before).1 le memory)
      (.State producer rest k (allocation ge.genv_cenv before).1 le after) ∧
    (∀ i ∈ rows, CC.Mem.load (chunk i) after entry.block (offset i) = some (values i)) ∧
    (∀ i ∉ rows, CC.Mem.load (chunk i) after entry.block (offset i) =
      CC.Mem.load (chunk i) memory entry.block (offset i)) ∧
    (∀ c ofs, ofs + CC.sizeChunk c ≤ 192 → CC.Mem.load c after entry.block ofs = CC.Mem.load c memory entry.block ofs) ∧
    (∀ c b ofs, b ≠ entry.block → CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs) ∧
    FrameBelow before.nextblock memory after ∧ after.access = memory.access ∧ after.nextblock = memory.nextblock := by
  induction rows generalizing memory with
  | nil =>
    refine ⟨memory, .refl _, ?_, ?_, ?_, ?_, FrameBelow.refl _ _, rfl, rfl⟩
    · intro i member
      cases member
    · intro i absent
      rfl
    · intro c ofs bound
      rfl
    · intro c b ofs different
      rfl
  | cons head tail ih =>
    obtain ⟨middle, firstRun, stored, firstRead, firstOther, firstHeader, firstOutside, firstFrame, firstAccess, firstNext⟩ :=
      X86ProducerContextStore.write ge bindingsLayout valueLayout before memory le k
        (tail.foldr (fun i next => .Ssequence (assignment i) next) rest) values typed head inputs entry access
    obtain ⟨after, lastRun, lastRead, lastOther, lastHeader, lastOutside, lastFrame, lastAccess, lastNext⟩ :=
      ih middle (firstAccess.trans access)
    refine ⟨after, ?_, ?_, ?_, ?_, ?_, firstFrame.trans lastFrame, lastAccess.trans firstAccess, lastNext.trans firstNext⟩
    · simpa only [List.foldr_cons, List.length_cons, Nat.mul_add, Nat.mul_one, Nat.add_comm] using firstRun.trans lastRun
    · intro i member
      by_cases later : i ∈ tail
      · exact lastRead i later
      · have same : i = head := (List.mem_cons.mp member).resolve_right later
        subst i
        exact (lastOther head later).trans firstRead
    · intro i absent
      have notHead : i ≠ head := by
        intro same
        apply absent
        simp [same]
      have notTail : i ∉ tail := fun member => absent (List.mem_cons_of_mem _ member)
      exact (lastOther i notTail).trans (firstOther i notHead)
    · intro c ofs bound
      exact (lastHeader c ofs bound).trans (firstHeader c ofs bound)
    · intro c b ofs different
      exact (lastOutside c b ofs different).trans (firstOutside c b ofs different)

/-- The same allocated header receives all five original context stores in15
transitions. All earlier header bytes and every other block are framed by the
actual stores; current source temporaries and access at this cut remain explicit. -/
theorem context_initialized (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings = some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (values : Fin 5 → CC.Val) (typed : Typed values)
    (inputs : ∀ i, le.get (tempName i) = some (values i))
    (entry : HeaderLocal ge.genv_cenv before)
    (access : memory.access = (allocation ge.genv_cenv before).2.access) :
    ∃ after, InternalRun ge 15
      (.State producer afterHeader k (allocation ge.genv_cenv before).1 le memory)
      (.State producer afterContext k (allocation ge.genv_cenv before).1 le after) ∧
    (∀ i, CC.Mem.load (chunk i) after entry.block (offset i) = some (values i)) ∧
    (∀ c ofs, ofs + CC.sizeChunk c ≤ 192 → CC.Mem.load c after entry.block ofs = CC.Mem.load c memory entry.block ofs) ∧
    (∀ c b ofs, b ≠ entry.block → CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs) ∧
    FrameBelow before.nextblock memory after ∧ after.access = memory.access ∧ after.nextblock = memory.nextblock := by
  obtain ⟨after, run, read, other, header, outside, frame, finalAccess, frontier⟩ :=
    run_rows ge bindingsLayout valueLayout before entry values typed (List.finRange 5) afterContext le k memory inputs access
  refine ⟨after, ?_, fun i => read i (List.mem_finRange i), header, outside, frame, finalAccess, frontier⟩
  have mapped : List.ofFn assignment = (List.finRange 5).map assignment := by
    simp only [List.finRange, List.map_ofFn, Function.comp_def]
  rw [source_context]
  simpa only [List.length_finRange, mapped, List.foldr_map] using run

end KProgFormal.ClightRefinement.X86ProducerContextInitialize
