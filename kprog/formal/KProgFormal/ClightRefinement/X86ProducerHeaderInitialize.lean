import KProgFormal.ClightRefinement.X86ProducerHeaderStore

namespace KProgFormal.ClightRefinement.X86ProducerHeaderInitialize
open X86ProducerHeaderSource X86ProducerHeaderLocals
open X86ProducerCacheAllocation (allocation)

private theorem run_rows (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings = some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (registers : CC.Composite)
    (registersLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_register_cells = some registers)
    (cellsOffset : CC.unionFieldOffset ge.genv_cenv X86_program_profile_bpf._gpr_cells registers.co_members = .OK (0, .Full))
    (before : CC.Mem) (entry : HeaderLocal ge.genv_cenv before)
    (sources : (i : Fin 24) → SourceLocal ge.genv_cenv before i) (rows : List (Fin 24))
    (rest : CC.Stmt) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (access : memory.access = (allocation ge.genv_cenv before).2.access) :
    ∃ after, InternalRun ge (3 * rows.length)
      (.State producer (rows.foldr (fun i next => .Ssequence (assignment i) next) rest)
        k (allocation ge.genv_cenv before).1 le memory)
      (.State producer rest k (allocation ge.genv_cenv before).1 le after) ∧
    (∀ i ∈ rows, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) = some (.Vptr (sources i).block 0)) ∧
    (∀ i ∉ rows, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) =
      CC.Mem.load CC.Mptr memory entry.block (8 * (i.val : Int))) ∧
    (∀ chunk block offset, block ≠ entry.block → CC.Mem.load chunk after block offset = CC.Mem.load chunk memory block offset) ∧
    FrameBelow before.nextblock memory after ∧ after.access = memory.access ∧ after.nextblock = memory.nextblock := by
  induction rows generalizing memory with
  | nil =>
    refine ⟨memory, .refl _, ?_, ?_, ?_, FrameBelow.refl _ _, rfl, rfl⟩
    · intro i member
      cases member
    · intro i absent
      rfl
    · intro chunk block offset different
      rfl
  | cons head tail ih =>
    obtain ⟨middle, firstRun, stored, firstRead, firstOther, firstOutside, firstFrame, firstAccess, firstNext⟩ :=
      X86ProducerHeaderStore.write ge bindingsLayout valueLayout registers registersLayout cellsOffset before memory le k
        (tail.foldr (fun i next => .Ssequence (assignment i) next) rest) head entry (sources head) access
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
    · intro chunk block offset different
      exact (lastOutside chunk block offset different).trans (firstOutside chunk block offset different)

/-- All24 original pointer assignments execute in72 internal transitions.
The same actual allocation constructs every source/header local and rights;
only current access equality is required at this genuine source cut. The
preceding provider/input/flag setup is not asserted to have run by this theorem. -/
theorem header_initialized (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings = some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (registers : CC.Composite)
    (registersLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_register_cells = some registers)
    (cellsOffset : CC.unionFieldOffset ge.genv_cenv X86_program_profile_bpf._gpr_cells registers.co_members = .OK (0, .Full))
    (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : memory.access = (allocation ge.genv_cenv before).2.access) :
    ∃ entry : HeaderLocal ge.genv_cenv before,
    ∃ sources : (i : Fin 24) → SourceLocal ge.genv_cenv before i, ∃ after,
    InternalRun ge 72 (.State producer headerStart k (allocation ge.genv_cenv before).1 le memory)
      (.State producer afterHeader k (allocation ge.genv_cenv before).1 le after) ∧
    (∀ i, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) = some (.Vptr (sources i).block 0)) ∧
    (∀ chunk block offset, block ≠ entry.block → CC.Mem.load chunk after block offset = CC.Mem.load chunk memory block offset) ∧
    FrameBelow before.nextblock memory after ∧ after.access = memory.access ∧ after.nextblock = memory.nextblock := by
  obtain ⟨entry⟩ := header_local ge.genv_cenv before
  let sources : (i : Fin 24) → SourceLocal ge.genv_cenv before i := fun i => Classical.choice (source_local ge.genv_cenv before i)
  obtain ⟨after, run, read, other, outside, frame, finalAccess, frontier⟩ :=
    run_rows ge bindingsLayout valueLayout registers registersLayout cellsOffset before entry sources
      (List.finRange 24) afterHeader le k memory access
  refine ⟨entry, sources, after, ?_, fun i => read i (List.mem_finRange i), outside, frame, finalAccess, frontier⟩
  have mapped : List.ofFn assignment = (List.finRange 24).map assignment := by
    simp only [List.finRange, List.map_ofFn, Function.comp_def]
  rw [source_header]
  simpa only [List.length_finRange, mapped, List.foldr_map] using run

end KProgFormal.ClightRefinement.X86ProducerHeaderInitialize
