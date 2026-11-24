import KProgFormal.ClightRefinement.X86ProducerAbiStore

namespace KProgFormal.ClightRefinement.X86ProducerAbiInitialize
open X86ProducerAbiSource X86ProducerAbiLayout
open X86ProducerHeaderSource (producer)
open X86ProducerHeaderLocals (Local)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)

private theorem run_rows (before : CC.Mem)
    (abi : Local ge.genv_cenv before X86_program_profile_bpf.___x86_sim_abi abiType)
    (rows : List (Fin 187)) (rest : CC.Stmt) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (access : memory.access = (allocation ge.genv_cenv before).2.access) :
    ∃ after, InternalRun ge (3 * rows.length)
      (.State producer (rows.foldr (fun i next => .Ssequence (assignment i) next) rest)
        k (allocation ge.genv_cenv before).1 le memory)
      (.State producer rest k (allocation ge.genv_cenv before).1 le after) ∧
    (∀ i ∈ rows, CC.Mem.load (chunk i) after abi.block (offset i) = some (value i)) ∧
    (∀ i ∉ rows, CC.Mem.load (chunk i) after abi.block (offset i) = CC.Mem.load (chunk i) memory abi.block (offset i)) ∧
    (∀ c b ofs, b ≠ abi.block → CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs) ∧
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
      X86ProducerAbiStore.write before memory le k (tail.foldr (fun i next => .Ssequence (assignment i) next) rest) head abi access
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
      exact (lastOutside c b ofs different).trans (firstOutside c b ofs different)

/-- All187 original ABI assignments really execute from the actual allocation
in561 transitions, with every typed zero readback and actual caller frame.
There are no supplied store, initialized-view, provider or permission premises. -/
theorem abi_initialized (before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ abi : Local ge.genv_cenv before X86_program_profile_bpf.___x86_sim_abi abiType, ∃ after,
    InternalRun ge 561 (.State producer producer.fn_body k (allocation ge.genv_cenv before).1 le (allocation ge.genv_cenv before).2)
      (.State producer afterAbi k (allocation ge.genv_cenv before).1 le after) ∧
    (∀ i, CC.Mem.load (chunk i) after abi.block (offset i) = some (value i)) ∧
    (∀ c b ofs, b ≠ abi.block → CC.Mem.load c after b ofs = CC.Mem.load c (allocation ge.genv_cenv before).2 b ofs) ∧
    FrameBelow before.nextblock before after ∧
    after.access = (allocation ge.genv_cenv before).2.access ∧ after.nextblock = (allocation ge.genv_cenv before).2.nextblock := by
  obtain ⟨abi⟩ := abi_local before
  obtain ⟨after, run, read, other, outside, frame, finalAccess, frontier⟩ :=
    run_rows before abi (List.finRange 187) afterAbi le k (allocation ge.genv_cenv before).2 rfl
  refine ⟨abi, after, ?_, fun i => read i (List.mem_finRange i), outside,
    (X86ProducerEntry.entry_frame ge before).trans frame, finalAccess, frontier⟩
  have mapped : List.ofFn assignment = (List.finRange 187).map assignment := by
    simp only [List.finRange, List.map_ofFn, Function.comp_def]
  rw [source_abi]
  simpa only [List.length_finRange, mapped, List.foldr_map] using run

/-- The same full original call enters and initializes its ABI object in562
real transitions, retaining the original continuation, context temporary and
entire remaining provider/setup suffix. -/
theorem from_call (before : CC.Mem) (ctx : CC.Val) (k : CC.Cont) :
    ∃ abi : Local ge.genv_cenv before X86_program_profile_bpf.___x86_sim_abi abiType, ∃ after,
    InternalRun ge 562 (.Callstate (.Internal producer) [ctx] k before)
      (.State producer afterAbi k (allocation ge.genv_cenv before).1 (X86ProducerEntry.initialTemps ctx) after) ∧
    (∀ i, CC.Mem.load (chunk i) after abi.block (offset i) = some (value i)) ∧
    (∀ c b ofs, b ≠ abi.block → CC.Mem.load c after b ofs = CC.Mem.load c (allocation ge.genv_cenv before).2 b ofs) ∧
    FrameBelow before.nextblock before after ∧
    after.access = (allocation ge.genv_cenv before).2.access ∧ after.nextblock = (allocation ge.genv_cenv before).2.nextblock := by
  obtain ⟨abi, after, run, reads, outside, frame, access, frontier⟩ :=
    abi_initialized before (X86ProducerEntry.initialTemps ctx) k
  exact ⟨abi, after, (X86ProducerEntry.entry_internal ge before ctx k).trans run,
    reads, outside, frame, access, frontier⟩

end KProgFormal.ClightRefinement.X86ProducerAbiInitialize
