import KProgFormal.ClightRefinement.X86ProducerGhostStore

namespace KProgFormal.ClightRefinement.X86ProducerGhostInitialize
open X86ProducerGhostSource X86ProducerGhostStore
open X86ProducerHeaderSource (producer)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)

private theorem run_rows (before : CC.Mem) (locals : Locals before)
    (rows : List (Fin 12)) (rest : CC.Stmt) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (access : memory.access = (allocation ge.genv_cenv before).2.access) :
    ∃ after, InternalRun ge (3 * rows.length)
      (.State producer (rows.foldr (fun i next => .Ssequence (assignment i) next) rest)
        k (allocation ge.genv_cenv before).1 le memory)
      (.State producer rest k (allocation ge.genv_cenv before).1 le after) ∧
    (∀ i ∈ rows, CC.Mem.load (chunk i) after (locals i).block 0 = some (value i)) ∧
    (∀ i ∉ rows, CC.Mem.load (chunk i) after (locals i).block 0 = CC.Mem.load (chunk i) memory (locals i).block 0) ∧
    (∀ c b ofs, Outside locals b → CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs) ∧
    FrameBelow before.nextblock memory after ∧ after.access = memory.access ∧ after.nextblock = memory.nextblock := by
  induction rows generalizing memory with
  | nil =>
    refine ⟨memory, .refl _, ?_, ?_, ?_, FrameBelow.refl _ _, rfl, rfl⟩
    · intro i member
      cases member
    · intro i absent
      rfl
    · intro c b ofs different
      rfl
  | cons head tail ih =>
    obtain ⟨middle, firstRun, stored, firstRead, firstOther, firstOutside, firstFrame, firstAccess, firstNext⟩ :=
      X86ProducerGhostStore.write before memory le k (tail.foldr (fun i next => .Ssequence (assignment i) next) rest) locals head access
    obtain ⟨after, lastRun, lastRead, lastOther, lastOutside, lastFrame, lastAccess, lastNext⟩ :=
      ih middle (firstAccess.trans access)
    refine ⟨after, ?_, ?_, ?_, ?_, firstFrame.trans lastFrame, lastAccess.trans firstAccess, lastNext.trans firstNext⟩
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
    · intro c b ofs different
      exact (lastOutside c b ofs different).trans (firstOutside c b ofs (different head))

/-- All twelve original tag/null-pointer assignments execute from actual
allocated locals with exact readbacks and derived frames; current access is
explicit when this cut is used independently of the earlier ABI prefix. -/
theorem ghosts_initialized (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : memory.access = (allocation ge.genv_cenv before).2.access) :
    ∃ locals : Locals before, ∃ after,
    InternalRun ge 36 (.State producer ghostStart k (allocation ge.genv_cenv before).1 le memory)
      (.State producer afterGhosts k (allocation ge.genv_cenv before).1 le after) ∧
    (∀ i, CC.Mem.load (chunk i) after (locals i).block 0 = some (value i)) ∧
    (∀ c b ofs, Outside locals b → CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs) ∧
    FrameBelow before.nextblock memory after ∧ after.access = memory.access ∧ after.nextblock = memory.nextblock := by
  obtain ⟨locals⟩ := local_bindings before
  obtain ⟨after, run, read, other, outside, frame, finalAccess, frontier⟩ :=
    run_rows before locals (List.finRange 12) afterGhosts le k memory access
  refine ⟨locals, after, ?_, fun i => read i (List.mem_finRange i), outside, frame, finalAccess, frontier⟩
  have mapped : List.ofFn assignment = (List.finRange 12).map assignment := by
    simp only [List.finRange, List.map_ofFn, Function.comp_def]
  rw [source_ghosts]
  simpa only [List.length_finRange, mapped, List.foldr_map] using run

/-- The genuine surrounding context assignments and twelve stores compose51
actual transitions to the untouched provider suffix, with exact final temporaries. -/
theorem setup_initialized (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : memory.access = (allocation ge.genv_cenv before).2.access) :
    ∃ locals : Locals before, ∃ after,
    InternalRun ge 51 (.State producer X86ProducerAbiSource.afterAbi k (allocation ge.genv_cenv before).1 le memory)
      (.State producer beforeProvider k (allocation ge.genv_cenv before).1 (finalTemps (contextTemps le)) after) ∧
    (∀ i, CC.Mem.load (chunk i) after (locals i).block 0 = some (value i)) ∧
    (∀ c b ofs, Outside locals b → CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs) ∧
    FrameBelow before.nextblock memory after ∧ after.access = memory.access ∧ after.nextblock = memory.nextblock := by
  obtain ⟨locals, after, run, reads, outside, frame, finalAccess, frontier⟩ :=
    ghosts_initialized before memory (contextTemps le) k access
  exact ⟨locals, after,
    ((to_ghosts ge (allocation ge.genv_cenv before).1 le memory k).trans run).trans
      (after_ghosts ge (allocation ge.genv_cenv before).1 (contextTemps le) after k),
    reads, outside, frame, finalAccess, frontier⟩

end KProgFormal.ClightRefinement.X86ProducerGhostInitialize
