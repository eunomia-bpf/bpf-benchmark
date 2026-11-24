import KProgFormal.ClightRefinement.X86ProducerHeaderTarget
import KProgFormal.ClightRefinement.X86ProducerHeaderRhs

namespace KProgFormal.ClightRefinement.X86ProducerHeaderStore
open X86ProducerHeaderSource X86ProducerHeaderLocals
open X86ProducerCacheAllocation (allocation)

private theorem target_access (i : Fin 24) : CC.accessMode (CC.typeof (target i)) = .By_value CC.Mptr := by
  unfold target
  split <;> simp only [CC.typeof] <;> unfold pointerType <;> split <;> rfl

private theorem header_offset : ∀ i : Fin 24,
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr (8 * (i.val : Int))) = 8 * (i.val : Int) := by decide +kernel

/-- One original typed pointer assignment constructs its store from actual
allocated permissions, executes three source transitions and retains exact
readback, neighboring slots and all other blocks. -/
theorem write (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (registers : CC.Composite)
    (registersLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_register_cells = some registers)
    (cellsOffset : CC.unionFieldOffset ge.genv_cenv X86_program_profile_bpf._gpr_cells registers.co_members = .OK (0, .Full))
    (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (rest : CC.Stmt)
    (i : Fin 24) (entry : HeaderLocal ge.genv_cenv before) (source : SourceLocal ge.genv_cenv before i)
    (access : memory.access = (allocation ge.genv_cenv before).2.access) :
    ∃ after, InternalRun ge 3
      (.State producer (.Ssequence (assignment i) rest) k (allocation ge.genv_cenv before).1 le memory)
      (.State producer rest k (allocation ge.genv_cenv before).1 le after) ∧
    CC.Mem.store CC.Mptr memory entry.block (8 * (i.val : Int)) (.Vptr source.block 0) = some after ∧
    CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) = some (.Vptr source.block 0) ∧
    (∀ j : Fin 24, j ≠ i → CC.Mem.load CC.Mptr after entry.block (8 * (j.val : Int)) =
      CC.Mem.load CC.Mptr memory entry.block (8 * (j.val : Int))) ∧
    (∀ chunk block offset, block ≠ entry.block → CC.Mem.load chunk after block offset = CC.Mem.load chunk memory block offset) ∧
    FrameBelow before.nextblock memory after ∧ after.access = memory.access ∧ after.nextblock = memory.nextblock := by
  have headerSize : CC.sizeof ge.genv_cenv headerType = 224 := by
    simp only [headerType, CC.sizeof, bindingsLayout]
    rfl
  have rangeWritable := CC.Mem.rangePerm_implies entry.range
    (show CC.permOrder .Freeable .Writable = true by decide +kernel)
  have writable : CC.Mem.validAccess memory CC.Mptr entry.block (8 * (i.val : Int)) .Writable = true := by
    simp only [CC.Mem.validAccess, Bool.and_eq_true]
    constructor
    · apply CC.Mem.rangePerm_intro
      intro offset lower upper
      have bound := i.isLt
      have low : (0 : Int) ≤ offset := by omega
      have high : offset < CC.sizeof ge.genv_cenv headerType := by
        change offset < 8 * (i.val : Int) + 8 at upper
        rw [headerSize]
        omega
      have permission := CC.Mem.rangePerm_perm (allocation ge.genv_cenv before).2 entry.block 0
        (CC.sizeof ge.genv_cenv headerType) .Cur .Writable rangeWritable offset low high
      simpa only [CC.Mem.perm, access] using permission
    · change ((8 * (i.val : Int)) % 8 == 0) = true
      simp
  have existsStore : ∃ after, CC.Mem.store CC.Mptr memory entry.block
      (8 * (i.val : Int)) (.Vptr source.block 0) = some after := by
    simp only [CC.Mem.store, writable, ite_true]
    exact ⟨_, rfl⟩
  obtain ⟨after, stored⟩ := existsStore
  have storev : CC.Mem.storev CC.Mptr memory
      (.Vptr entry.block (CC.Integers.Ptrofs.repr (8 * (i.val : Int)))) (.Vptr source.block 0) = some after := by
    simpa only [CC.Mem.storev, header_offset] using stored
  have targetAddress := X86ProducerHeaderTarget.target_address ge (allocation ge.genv_cenv before).1 le memory
    entry.block i bindingsLayout valueLayout entry.binding
  have sourceValue := X86ProducerHeaderRhs.rhs_pointer ge before memory le i source registers registersLayout cellsOffset
  have sourceCast := X86ProducerHeaderRhs.cast_pointer memory i source.block
  have assigned : CC.doStep ge
      (.State producer (assignment i) (.Kseq rest k) (allocation ge.genv_cenv before).1 le memory) =
      some (CC.E0, .State producer .Sskip (.Kseq rest k) (allocation ge.genv_cenv before).1 le after) := by
    simp only [assignment, CC.doStep, targetAddress, sourceValue, sourceCast, CC.doAssignLoc, target_access]
    change (match CC.Mem.storev CC.Mptr memory
      (.Vptr entry.block (CC.Integers.Ptrofs.repr (8 * (i.val : Int)))) (.Vptr source.block 0) with
      | some heap => some (CC.E0, CC.State.State producer .Sskip (.Kseq rest k) (allocation ge.genv_cenv before).1 le heap)
      | none => none) = _
    rw [storev]
  refine ⟨after, ?_, stored, ?_, ?_, ?_, FrameBelow.store entry.fresh stored,
    CC.Mem.store_access stored, CC.Mem.store_nextblock stored⟩
  · exact .step trivial (CC.doStep_sound ge _ _ _ rfl)
      (.step trivial (CC.doStep_sound ge _ _ _ assigned)
        (.step trivial (CC.doStep_sound ge _ _ _ rfl) (.refl _)))
  · simpa [CC.Val.loadResult, CC.Mptr, CC.Archi.ptr64] using CC.Mem.load_store_same stored
  · intro j different
    have ne : j.val ≠ i.val := fun equal => different (Fin.ext equal)
    have disjoint : (8 * (j.val : Int)) + 8 ≤ 8 * (i.val : Int) ∨
        (8 * (i.val : Int)) + 8 ≤ 8 * (j.val : Int) := by omega
    exact CC.Mem.load_store_other stored CC.Mptr entry.block (8 * (j.val : Int)) (.inr disjoint)
  · intro chunk block offset different
    exact CC.Mem.load_store_other stored chunk block offset (.inl different)

end KProgFormal.ClightRefinement.X86ProducerHeaderStore
