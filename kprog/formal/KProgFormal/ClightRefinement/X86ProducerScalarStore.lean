import KProgFormal.ClightRefinement.X86ProducerScalarSource

namespace KProgFormal.ClightRefinement.X86ProducerScalarStore
open X86ProducerHeaderSource (producer localName localType)
open X86ProducerHeaderLocals (SourceLocal)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)

def row (i : Fin 10) : Fin 24 := ⟨14 + i.val, by omega⟩
def chunk (i : Fin 10) : CC.Chunk := if 1 ≤ i.val ∧ i.val ≤ 6 then .Mint8unsigned else .Mint64

private theorem type_size : ∀ i : Fin 10, CC.sizeof ge.genv_cenv (localType (row i)) = CC.sizeChunk (chunk i) := by decide +kernel
private theorem target_access : ∀ i : Fin 10, CC.accessMode (localType (row i)) = .By_value (chunk i) := by decide +kernel

/-- Actual producer scalar-object ownership constructs the source store and
readback for native base, flags, XMM and return-address locals. Expression
and cast observations remain inputs to this generic lemma and are derived
at each real source call site; no successful store/output heap is assumed. -/
theorem write (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (rest : CC.Stmt)
    (i : Fin 10) (object : SourceLocal ge.genv_cenv before (row i))
    (rhs : CC.Expr) (input value : CC.Val)
    (evaluated : CC.doEvalExpr ge (allocation ge.genv_cenv before).1 le memory rhs = some input)
    (cast : CC.Cop.semCast input (CC.typeof rhs) (localType (row i)) memory = some value)
    (canonical : CC.Val.loadResult (chunk i) value = value)
    (access : memory.access = (allocation ge.genv_cenv before).2.access) :
    ∃ after, InternalRun ge 2
      (.State producer (.Sassign (.Evar (localName (row i)) (localType (row i))) rhs)
        (.Kseq rest k) (allocation ge.genv_cenv before).1 le memory)
      (.State producer rest k (allocation ge.genv_cenv before).1 le after) ∧
    CC.Mem.store (chunk i) memory object.block 0 value = some after ∧
    CC.Mem.load (chunk i) after object.block 0 = some value ∧
    (∀ c b ofs, b ≠ object.block → CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs) ∧
    FrameBelow before.nextblock memory after ∧ after.access = memory.access ∧ after.nextblock = memory.nextblock := by
  have rangeWritable := CC.Mem.rangePerm_implies object.range
    (show CC.permOrder .Freeable .Writable = true by decide +kernel)
  have writable : CC.Mem.validAccess memory (chunk i) object.block 0 .Writable = true := by
    simp only [CC.Mem.validAccess, Bool.and_eq_true]
    constructor
    · apply CC.Mem.rangePerm_intro
      intro ofs lower upper
      have bound : ofs < CC.sizeof ge.genv_cenv (localType (row i)) := by
        rw [type_size]
        simpa only [Int.zero_add] using upper
      have permission := CC.Mem.rangePerm_perm (allocation ge.genv_cenv before).2 object.block 0
        (CC.sizeof ge.genv_cenv (localType (row i))) .Cur .Writable rangeWritable ofs lower bound
      simpa only [CC.Mem.perm, access] using permission
    · simp
  obtain ⟨after, stored⟩ : ∃ after, CC.Mem.store (chunk i) memory object.block 0 value = some after := by
    simp only [CC.Mem.store, writable, ite_true]
    exact ⟨_, rfl⟩
  have assigned : CC.doStep ge
      (.State producer (.Sassign (.Evar (localName (row i)) (localType (row i))) rhs)
        (.Kseq rest k) (allocation ge.genv_cenv before).1 le memory) =
      some (CC.E0, .State producer .Sskip (.Kseq rest k) (allocation ge.genv_cenv before).1 le after) := by
    simp only [CC.doStep, CC.doEvalLvalue, CC.lvalOfVar, object.binding,
      evaluated, ite_true]
    have targetType : CC.typeof (.Evar (localName (row i)) (localType (row i))) = localType (row i) := rfl
    rw [targetType, cast]
    simp only [CC.doAssignLoc, target_access, CC.Mem.storev]
    change (match CC.Mem.store (chunk i) memory object.block 0 value with
      | some heap => some (CC.E0, CC.State.State producer .Sskip (.Kseq rest k) (allocation ge.genv_cenv before).1 le heap)
      | none => none) = _
    rw [stored]
  refine ⟨after, ?_, stored, ?_, ?_, FrameBelow.store object.fresh stored,
    CC.Mem.store_access stored, CC.Mem.store_nextblock stored⟩
  · exact .step trivial (CC.doStep_sound ge _ _ _ assigned)
      (.step trivial (CC.doStep_sound ge _ _ _ rfl) (.refl _))
  · simpa only [canonical] using CC.Mem.load_store_same stored
  · intro c b ofs different
    exact CC.Mem.load_store_other stored c b ofs (.inl different)

end KProgFormal.ClightRefinement.X86ProducerScalarStore
