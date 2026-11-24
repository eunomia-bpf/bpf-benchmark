import KProgFormal.ClightRefinement.X86ProducerAbiAddress

namespace KProgFormal.ClightRefinement.X86ProducerAbiStore
open X86ProducerAbiSource X86ProducerAbiLayout
open X86ProducerHeaderSource (producer)
open X86ProducerHeaderLocals (Local)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)

/-- The real integer-zero or null-pointer expression and destination cast
produce the exact typed zero that the original assignment stores. -/
theorem rhs_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (i : Fin 187) :
    CC.doEvalExpr ge e le memory (rhs i) = some (value i) ∧
    CC.Cop.semCast (value i) (CC.typeof (rhs i)) (CC.typeof (target i)) memory = some (value i) ∧
    CC.Val.loadResult (chunk i) (value i) = value i := by
  by_cases pointer : (group i).val = 3 ∨ (group i).val = 5
  all_goals by_cases word : (group i).val = 1
  all_goals simp +decide [rhs, value, target, field, fieldType, element, chunk, pointer, word,
    CC.doEvalExpr, CC.typeof, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.tptr, CC.tvoid, CC.tint, CC.tuint, CC.tuchar, CC.Val.loadResult,
    CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Mptr]

private theorem target_access : ∀ i : Fin 187,
    CC.accessMode (CC.typeof (target i)) = .By_value (chunk i) := by decide +kernel
private theorem field_bounds : ∀ i : Fin 187,
    0 ≤ offset i ∧ offset i + CC.sizeChunk (chunk i) ≤ 216 ∧
    offset i % CC.alignChunk (chunk i) = 0 ∧
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr (offset i)) = offset i := by decide +kernel
private theorem neighboring : ∀ i j : Fin 187, j ≠ i →
    offset j + CC.sizeChunk (chunk j) ≤ offset i ∨
    offset i + CC.sizeChunk (chunk i) ≤ offset j := by decide +kernel

/-- Every original ABI assignment constructs its successful store from actual
allocation rights, with exact readback and preservation of all other typed rows
and every other block. -/
theorem write (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (rest : CC.Stmt)
    (i : Fin 187) (abi : Local ge.genv_cenv before X86_program_profile_bpf.___x86_sim_abi abiType)
    (access : memory.access = (allocation ge.genv_cenv before).2.access) :
    ∃ after, InternalRun ge 3
      (.State producer (.Ssequence (assignment i) rest) k (allocation ge.genv_cenv before).1 le memory)
      (.State producer rest k (allocation ge.genv_cenv before).1 le after) ∧
    CC.Mem.store (chunk i) memory abi.block (offset i) (value i) = some after ∧
    CC.Mem.load (chunk i) after abi.block (offset i) = some (value i) ∧
    (∀ j : Fin 187, j ≠ i → CC.Mem.load (chunk j) after abi.block (offset j) =
      CC.Mem.load (chunk j) memory abi.block (offset j)) ∧
    (∀ c b ofs, b ≠ abi.block → CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs) ∧
    FrameBelow before.nextblock memory after ∧ after.access = memory.access ∧ after.nextblock = memory.nextblock := by
  have bounds := field_bounds i
  have rangeWritable := CC.Mem.rangePerm_implies abi.range
    (show CC.permOrder .Freeable .Writable = true by decide +kernel)
  have writable : CC.Mem.validAccess memory (chunk i) abi.block (offset i) .Writable = true := by
    simp only [CC.Mem.validAccess, Bool.and_eq_true]
    constructor
    · apply CC.Mem.rangePerm_intro
      intro ofs lower upper
      have permission := CC.Mem.rangePerm_perm (allocation ge.genv_cenv before).2 abi.block 0
        (CC.sizeof ge.genv_cenv abiType) .Cur .Writable rangeWritable ofs (by omega) (by rw [source_layout.2]; omega)
      simpa only [CC.Mem.perm, access] using permission
    · simpa only [beq_iff_eq] using bounds.2.2.1
  have existsStore : ∃ after, CC.Mem.store (chunk i) memory abi.block (offset i) (value i) = some after := by
    simp only [CC.Mem.store, writable, ite_true]
    exact ⟨_, rfl⟩
  obtain ⟨after, stored⟩ := existsStore
  have storev : CC.Mem.storev (chunk i) memory (.Vptr abi.block (CC.Integers.Ptrofs.repr (offset i))) (value i) = some after := by
    simpa only [CC.Mem.storev, bounds.2.2.2] using stored
  have address := X86ProducerAbiAddress.target_address (allocation ge.genv_cenv before).1 le memory abi.block i abi.binding
  have source := rhs_value (allocation ge.genv_cenv before).1 le memory i
  have assigned : CC.doStep ge
      (.State producer (assignment i) (.Kseq rest k) (allocation ge.genv_cenv before).1 le memory) =
      some (CC.E0, .State producer .Sskip (.Kseq rest k) (allocation ge.genv_cenv before).1 le after) := by
    simp only [assignment, CC.doStep, address, source.1, source.2.1, CC.doAssignLoc, target_access]
    change (match CC.Mem.storev (chunk i) memory (.Vptr abi.block (CC.Integers.Ptrofs.repr (offset i))) (value i) with
      | some heap => some (CC.E0, CC.State.State producer .Sskip (.Kseq rest k) (allocation ge.genv_cenv before).1 le heap)
      | none => none) = _
    rw [storev]
  refine ⟨after, ?_, stored, ?_, ?_, ?_, FrameBelow.store abi.fresh stored,
    CC.Mem.store_access stored, CC.Mem.store_nextblock stored⟩
  · exact .step trivial (CC.doStep_sound ge _ _ _ rfl)
      (.step trivial (CC.doStep_sound ge _ _ _ assigned)
        (.step trivial (CC.doStep_sound ge _ _ _ rfl) (.refl _)))
  · simpa only [source.2.2] using CC.Mem.load_store_same stored
  · intro j different
    exact CC.Mem.load_store_other stored (chunk j) abi.block (offset j) (.inr (neighboring i j different))
  · intro c b ofs different
    exact CC.Mem.load_store_other stored c b ofs (.inl different)

end KProgFormal.ClightRefinement.X86ProducerAbiStore
