import KProgFormal.ClightRefinement.X86ProducerContextAddress

namespace KProgFormal.ClightRefinement.X86ProducerContextStore
open X86ProducerContextSource
open X86ProducerHeaderSource (producer headerType)
open X86ProducerHeaderLocals
open X86ProducerCacheAllocation (allocation)

private theorem byte_normalized : ∀ byte : BitVec 8,
    CC.Integers.Int.zero_ext 8 (byte.setWidth 32) = byte.setWidth 32 := by decide +kernel

/-- The actual temporary lookup, source cast and typed readback preserve precisely
those values admitted by the original pointer/unsigned-byte fields. -/
theorem rhs_value (ge : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (values : Fin 5 → CC.Val) (typed : Typed values) (i : Fin 5)
    (bound : le.get (tempName i) = some (values i)) :
    CC.doEvalExpr ge e le memory (rhs i) = some (values i) ∧
    CC.Cop.semCast (values i) (CC.typeof (rhs i)) (CC.typeof (target i)) memory = some (values i) ∧
    CC.Val.loadResult (chunk i) (values i) = values i := by
  refine ⟨?_, ?_⟩
  · simpa only [rhs, CC.doEvalExpr] using bound
  · have value := typed i
    by_cases pointer : i.val < 3
    · simp only [pointer, ite_true] at value
      rcases value with ⟨b, ofs, value⟩ | ⟨word, value⟩
      all_goals rw [value]
      all_goals
        have options : i.val < 2 ∨ i.val = 2 := by omega
        rcases options with small | last
      all_goals simp_all [rhs, target, CC.typeof, fieldType, chunk,
        CC.Cop.semCast, CC.Cop.classifyCast, CC.tptr, CC.Val.loadResult, CC.Mptr, CC.Archi.ptr64]
    · have notFirst : ¬ i.val < 2 := by omega
      have notSecond : ¬ i.val = 2 := by omega
      simp only [pointer, ite_false] at value
      obtain ⟨byte, value⟩ := value
      rw [value]
      simp [rhs, target, CC.typeof, fieldType, notFirst, notSecond, chunk, pointer,
        CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
        CC.tuchar, CC.Val.loadResult, byte_normalized]

private theorem target_access : ∀ i : Fin 5,
    CC.accessMode (CC.typeof (target i)) = .By_value (chunk i) := by decide +kernel
private theorem field_bounds : ∀ i : Fin 5,
    0 ≤ offset i ∧ offset i + CC.sizeChunk (chunk i) ≤ 224 ∧
    offset i % CC.alignChunk (chunk i) = 0 ∧
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr (offset i)) = offset i := by decide +kernel
private theorem neighboring : ∀ i j : Fin 5, j ≠ i →
    offset j + CC.sizeChunk (chunk j) ≤ offset i ∨
    offset i + CC.sizeChunk (chunk i) ≤ offset j := by decide +kernel
private theorem context_start : ∀ i : Fin 5, 192 ≤ offset i := by decide +kernel

/-- Construct each of the five actual stores from the allocated header rights,
execute its three genuine transitions, and retain both old pointer-header reads
and every neighboring context field. -/
theorem write (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings = some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (rest : CC.Stmt)
    (values : Fin 5 → CC.Val) (typed : Typed values) (i : Fin 5)
    (inputs : ∀ i, le.get (tempName i) = some (values i))
    (entry : HeaderLocal ge.genv_cenv before)
    (access : memory.access = (allocation ge.genv_cenv before).2.access) :
    ∃ after, InternalRun ge 3
      (.State producer (.Ssequence (assignment i) rest) k (allocation ge.genv_cenv before).1 le memory)
      (.State producer rest k (allocation ge.genv_cenv before).1 le after) ∧
    CC.Mem.store (chunk i) memory entry.block (offset i) (values i) = some after ∧
    CC.Mem.load (chunk i) after entry.block (offset i) = some (values i) ∧
    (∀ j : Fin 5, j ≠ i → CC.Mem.load (chunk j) after entry.block (offset j) =
      CC.Mem.load (chunk j) memory entry.block (offset j)) ∧
    (∀ c ofs, ofs + CC.sizeChunk c ≤ 192 → CC.Mem.load c after entry.block ofs =
      CC.Mem.load c memory entry.block ofs) ∧
    (∀ c b ofs, b ≠ entry.block → CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs) ∧
    FrameBelow before.nextblock memory after ∧ after.access = memory.access ∧ after.nextblock = memory.nextblock := by
  have bounds := field_bounds i
  have headerSize : CC.sizeof ge.genv_cenv headerType = 224 := by
    simp only [headerType, CC.sizeof, bindingsLayout]
    rfl
  have rangeWritable := CC.Mem.rangePerm_implies entry.range
    (show CC.permOrder .Freeable .Writable = true by decide +kernel)
  have writable : CC.Mem.validAccess memory (chunk i) entry.block (offset i) .Writable = true := by
    simp only [CC.Mem.validAccess, Bool.and_eq_true]
    constructor
    · apply CC.Mem.rangePerm_intro
      intro ofs lower upper
      have permission := CC.Mem.rangePerm_perm (allocation ge.genv_cenv before).2 entry.block 0
        (CC.sizeof ge.genv_cenv headerType) .Cur .Writable rangeWritable ofs (by omega) (by rw [headerSize]; omega)
      simpa only [CC.Mem.perm, access] using permission
    · simpa only [beq_iff_eq] using bounds.2.2.1
  have existsStore : ∃ after, CC.Mem.store (chunk i) memory entry.block (offset i) (values i) = some after := by
    simp only [CC.Mem.store, writable, ite_true]
    exact ⟨_, rfl⟩
  obtain ⟨after, stored⟩ := existsStore
  have storev : CC.Mem.storev (chunk i) memory (.Vptr entry.block (CC.Integers.Ptrofs.repr (offset i))) (values i) = some after := by
    simpa only [CC.Mem.storev, bounds.2.2.2] using stored
  have address := X86ProducerContextAddress.target_address ge (allocation ge.genv_cenv before).1 le memory
    entry.block i bindingsLayout valueLayout entry.binding
  have source := rhs_value ge (allocation ge.genv_cenv before).1 le memory values typed i (inputs i)
  have assigned : CC.doStep ge
      (.State producer (assignment i) (.Kseq rest k) (allocation ge.genv_cenv before).1 le memory) =
      some (CC.E0, .State producer .Sskip (.Kseq rest k) (allocation ge.genv_cenv before).1 le after) := by
    simp only [assignment, CC.doStep, address, source.1, source.2.1, CC.doAssignLoc, target_access]
    change (match CC.Mem.storev (chunk i) memory (.Vptr entry.block (CC.Integers.Ptrofs.repr (offset i))) (values i) with
      | some heap => some (CC.E0, CC.State.State producer .Sskip (.Kseq rest k) (allocation ge.genv_cenv before).1 le heap)
      | none => none) = _
    rw [storev]
  refine ⟨after, ?_, stored, ?_, ?_, ?_, ?_, FrameBelow.store entry.fresh stored,
    CC.Mem.store_access stored, CC.Mem.store_nextblock stored⟩
  · exact .step trivial (CC.doStep_sound ge _ _ _ rfl)
      (.step trivial (CC.doStep_sound ge _ _ _ assigned)
        (.step trivial (CC.doStep_sound ge _ _ _ rfl) (.refl _)))
  · simpa only [source.2.2] using CC.Mem.load_store_same stored
  · intro j different
    exact CC.Mem.load_store_other stored (chunk j) entry.block (offset j) (.inr (neighboring i j different))
  · intro c ofs beforeContext
    have start := context_start i
    exact CC.Mem.load_store_other stored c entry.block ofs (.inr (.inl (Int.le_trans beforeContext start)))
  · intro c b ofs different
    exact CC.Mem.load_store_other stored c b ofs (.inl different)

end KProgFormal.ClightRefinement.X86ProducerContextStore
