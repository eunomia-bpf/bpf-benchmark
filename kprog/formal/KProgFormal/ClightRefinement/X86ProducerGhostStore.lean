import KProgFormal.ClightRefinement.X86ProducerGhostSource

namespace KProgFormal.ClightRefinement.X86ProducerGhostStore
open X86ProducerGhostSource
open X86ProducerHeaderSource (producer localName localType)
open X86ProducerHeaderLocals (SourceLocal)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)

abbrev Locals (before : CC.Mem) := (i : Fin 12) → SourceLocal ge.genv_cenv before (row i)
def Outside {before : CC.Mem} (locals : Locals before) (block : CC.Block) : Prop :=
  ∀ i, block ≠ (locals i).block

private theorem type_row : ∀ i : Fin 12, localType (row i) =
    if i.val % 2 = 0 then CC.tuchar else CC.tptr CC.tvoid := by decide +kernel
private theorem type_size : ∀ i : Fin 12, CC.sizeof ge.genv_cenv (localType (row i)) = CC.sizeChunk (chunk i) := by decide +kernel
private theorem target_access : ∀ i : Fin 12, CC.accessMode (localType (row i)) = .By_value (chunk i) := by decide +kernel
private theorem distinct_names : ∀ i j : Fin 12, j ≠ i → localName (row j) ≠ localName (row i) := by decide +kernel

private theorem cast_value (memory : CC.Mem) (i : Fin 12) :
    CC.Cop.semCast (.Vint (CC.Integers.Int.repr 0)) CC.tint (localType (row i)) memory = some (value i) ∧
    CC.Val.loadResult (chunk i) (value i) = value i := by
  rw [type_row]
  by_cases parity : i.val % 2 = 0
  all_goals simp only [parity, ite_true, ite_false, value, chunk]
  all_goals constructor <;> rfl

/-- The actual allocation constructs every ghost local; no initialized contents
or independent block-disjointness premise is supplied. -/
theorem local_bindings (before : CC.Mem) : Nonempty (Locals before) :=
  ⟨fun i => Classical.choice (X86ProducerHeaderLocals.source_local ge.genv_cenv before (row i))⟩

/-- Each genuine tag/null-pointer assignment is constructed from the same
allocated local rights, with exact readback, name-derived other-ghost frame,
all other blocks, caller frame, permissions and frontier. -/
theorem write (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (rest : CC.Stmt)
    (locals : Locals before) (i : Fin 12)
    (access : memory.access = (allocation ge.genv_cenv before).2.access) :
    ∃ after, InternalRun ge 3
      (.State producer (.Ssequence (assignment i) rest) k (allocation ge.genv_cenv before).1 le memory)
      (.State producer rest k (allocation ge.genv_cenv before).1 le after) ∧
    CC.Mem.store (chunk i) memory (locals i).block 0 (value i) = some after ∧
    CC.Mem.load (chunk i) after (locals i).block 0 = some (value i) ∧
    (∀ j : Fin 12, j ≠ i → CC.Mem.load (chunk j) after (locals j).block 0 = CC.Mem.load (chunk j) memory (locals j).block 0) ∧
    (∀ c b ofs, b ≠ (locals i).block → CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs) ∧
    FrameBelow before.nextblock memory after ∧ after.access = memory.access ∧ after.nextblock = memory.nextblock := by
  have rangeWritable := CC.Mem.rangePerm_implies (locals i).range
    (show CC.permOrder .Freeable .Writable = true by decide +kernel)
  have writable : CC.Mem.validAccess memory (chunk i) (locals i).block 0 .Writable = true := by
    simp only [CC.Mem.validAccess, Bool.and_eq_true]
    constructor
    · apply CC.Mem.rangePerm_intro
      intro ofs lower upper
      have bound : ofs < CC.sizeof ge.genv_cenv (localType (row i)) := by
        rw [type_size]
        simpa only [Int.zero_add] using upper
      have permission := CC.Mem.rangePerm_perm (allocation ge.genv_cenv before).2 (locals i).block 0
        (CC.sizeof ge.genv_cenv (localType (row i))) .Cur .Writable rangeWritable ofs lower bound
      simpa only [CC.Mem.perm, access] using permission
    · simp
  have existsStore : ∃ after, CC.Mem.store (chunk i) memory (locals i).block 0 (value i) = some after := by
    simp only [CC.Mem.store, writable, ite_true]
    exact ⟨_, rfl⟩
  obtain ⟨after, stored⟩ := existsStore
  have cast := cast_value memory i
  have assigned : CC.doStep ge
      (.State producer (assignment i) (.Kseq rest k) (allocation ge.genv_cenv before).1 le memory) =
      some (CC.E0, .State producer .Sskip (.Kseq rest k) (allocation ge.genv_cenv before).1 le after) := by
    simp only [assignment, CC.doStep, CC.doEvalLvalue, CC.lvalOfVar, (locals i).binding,
      CC.doEvalExpr, CC.typeof, ite_true, cast.1, CC.doAssignLoc, target_access, CC.Mem.storev]
    change (match CC.Mem.store (chunk i) memory (locals i).block 0 (value i) with
      | some heap => some (CC.E0, CC.State.State producer .Sskip (.Kseq rest k) (allocation ge.genv_cenv before).1 le heap)
      | none => none) = _
    rw [stored]
  refine ⟨after, ?_, stored, ?_, ?_, ?_, FrameBelow.store (locals i).fresh stored,
    CC.Mem.store_access stored, CC.Mem.store_nextblock stored⟩
  · exact .step trivial (CC.doStep_sound ge _ _ _ rfl)
      (.step trivial (CC.doStep_sound ge _ _ _ assigned)
        (.step trivial (CC.doStep_sound ge _ _ _ rfl) (.refl _)))
  · simpa only [cast.2] using CC.Mem.load_store_same stored
  · intro j different
    have allocated : CC.AllocVariables ge.genv_cenv CC.emptyEnv before producer.fn_vars
        (allocation ge.genv_cenv before).1 (allocation ge.genv_cenv before).2 :=
      CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation ge.genv_cenv before)).symm
    have separate := (allocated_local_storage allocated).2 _ _ _ _ (locals j).binding (locals i).binding (distinct_names i j different)
    exact CC.Mem.load_store_other stored (chunk j) (locals j).block 0 (.inl separate)
  · intro c b ofs different
    exact CC.Mem.load_store_other stored c b ofs (.inl different)

end KProgFormal.ClightRefinement.X86ProducerGhostStore
