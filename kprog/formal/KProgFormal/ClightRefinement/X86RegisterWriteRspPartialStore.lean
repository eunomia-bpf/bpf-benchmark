import KProgFormal.ClightRefinement.X86RegisterWriteRspScalarSuffix

namespace KProgFormal.ClightRefinement.X86RegisterWriteRspPartialStore

private theorem partial_right (isWord : Bool) (memory : CC.Mem) (block : CC.Block)
    (full : CC.Mem.validAccess memory CC.Mptr block 0 .Writable = true) :
    CC.Mem.validAccess memory (X86RegisterWriteRspScalarSuffix.chunk isWord) block 0 .Writable = true := by
  have parts := full
  simp only [CC.Mem.validAccess, Bool.and_eq_true] at parts
  have range : CC.Mem.rangePerm memory block 0 8 .Cur .Writable = true := parts.1
  cases isWord with
  | false =>
    change CC.Mem.rangePerm memory block 0 1 .Cur .Writable && (0 % 1 == 0) = true
    rw [Bool.and_eq_true]
    refine ⟨CC.Mem.rangePerm_intro memory block 0 1 .Cur .Writable
      (fun point lo hi => CC.Mem.rangePerm_perm memory block 0 8 .Cur .Writable range point lo (by omega)), by decide⟩
  | true =>
    change CC.Mem.rangePerm memory block 0 2 .Cur .Writable && (0 % 2 == 0) = true
    rw [Bool.and_eq_true]
    refine ⟨CC.Mem.rangePerm_intro memory block 0 2 .Cur .Writable
      (fun point lo hi => CC.Mem.rangePerm_perm memory block 0 8 .Cur .Writable range point lo (by omega)), by decide⟩

/-- The real RSP byte/word prelude and scalar partial store compose from
initial local permission, original native-base reads and original temporaries.
The native old word is formed by the true add-base store before partial
modification; exact readback preserves its other56/48 bits. -/
theorem execute (isWord : Bool) (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (memory : CC.Mem) (bindingBlock localBlock baseBlock : CC.Block)
    (baseOffset : CC.Integers.Ptrofs) (old nativeBase next : BitVec 64)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint (4#32)))
    (current : CC.Mem.load CC.Mptr memory localBlock 0 = some (.Vlong old))
    (header : CC.Mem.load CC.Mptr memory bindingBlock 112 = some (.Vptr baseBlock baseOffset))
    (native : CC.Mem.load .Mint64 memory baseBlock (CC.Integers.Ptrofs.unsigned baseOffset) =
      some (.Vlong nativeBase))
    (permission : CC.Mem.validAccess memory CC.Mptr localBlock 0 .Writable = true)
    (scalarTag : le.get X86_program_profile_bpf.___x86_wr_cell_tag__2 = some (.Vint (0#32)))
    (observed : le.get X86_program_profile_bpf.___x86_wr_next__2 = some (.Vlong next))
    (low : isWord = false → le.get X86_program_profile_bpf.___x86_wr_shift__2 = some (.Vint (0#32))) :
    ∃ after, InternalRun ge (13 + (if isWord then 11 else 12))
      (.State function (X86RegisterWriteRspPartial.leaf isWord) k e le memory)
      (.State function .Sskip k e
        (X86RegisterWriteRspScalarSuffix.temps isWord
          (X86RegisterWriteRspPartial.temps isWord le baseBlock baseOffset old nativeBase) next) after) ∧
      CC.Mem.load CC.Mptr after localBlock 0 =
        some (.Vlong (X86.Value.writeView (if isWord then .w else .b) (old + nativeBase) next)) ∧
      after.access = memory.access ∧ after.nextblock = memory.nextblock ∧
      (∀ chunk other offset, other ≠ localBlock →
        CC.Mem.load chunk after other offset = CC.Mem.load chunk memory other offset) := by
  obtain ⟨middle, initialized, entered, _, access, nextBlock, frame⟩ :=
    X86RegisterWriteRspPartial.execute isWord ge layout valueLayout function e le k memory
      bindingBlock localBlock baseBlock baseOffset old nativeBase
      declared binding destination current header native permission
  let reached := X86RegisterWriteRspPartial.temps isWord le baseBlock baseOffset old nativeBase
  have keptTag : reached.get X86_program_profile_bpf.___x86_wr_cell_tag__2 = some (.Vint (0#32)) := by
    cases isWord <;> simp +decide [reached, X86RegisterWriteRspPartial.temps,
      X86RegisterWriteRspWord.temps, X86RegisterWriteRspByte.temps, CC.PTree.gso, scalarTag]
  have keptValue : reached.get X86_program_profile_bpf.___x86_wr_next__2 = some (.Vlong next) := by
    cases isWord <;> simp +decide [reached, X86RegisterWriteRspPartial.temps,
      X86RegisterWriteRspWord.temps, X86RegisterWriteRspByte.temps, CC.PTree.gso, observed]
  have keptLow : isWord = false → reached.get X86_program_profile_bpf.___x86_wr_shift__2 = some (.Vint (0#32)) := by
    intro byte
    subst isWord
    simp +decide [reached, X86RegisterWriteRspPartial.temps,
      X86RegisterWriteRspByte.temps, CC.PTree.gso, low rfl]
  have full := (CC.Mem.validAccess_store_eq initialized CC.Mptr localBlock 0 .Writable).trans permission
  have narrow := partial_right isWord middle localBlock full
  have existsStore : ∃ after, CC.Mem.store (X86RegisterWriteRspScalarSuffix.chunk isWord) middle localBlock 0
      (.Vint (X86RegisterWriteRspScalarSuffix.value isWord next)) = some after := by
    simp only [CC.Mem.store, narrow, ite_true]
    exact ⟨_, rfl⟩
  obtain ⟨after, stored⟩ := existsStore
  have written := X86RegisterWriteRspScalarSuffix.run isWord ge layout.gpr function e reached k middle after
    localBlock next declared keptTag keptValue keptLow stored
  have readback : CC.Mem.load CC.Mptr after localBlock 0 =
      some (.Vlong (X86.Value.writeView (if isWord then .w else .b) (old + nativeBase) next)) := by
    cases isWord with
    | false =>
      have read := X86ShiftWriteback.byte_memory memory middle after localBlock (old + nativeBase) next (0#8)
        initialized stored
      simpa only [X86ShiftWriteback.byte_memory_native_low (old + nativeBase) next (0#8) (by decide),
        Bool.false_eq_true, ite_false] using read.1
    | true =>
      have read := X86WordMemory.load memory middle after localBlock (old + nativeBase) next initialized stored
      simpa only [X86WordMemory.native, ite_true] using read.1
  refine ⟨after, entered.trans written, readback, (CC.Mem.store_access stored).trans access,
    (CC.Mem.store_nextblock stored).trans nextBlock, ?_⟩
  intro chunk other offset different
  exact (CC.Mem.load_store_other stored chunk other offset (.inl different)).trans
    (frame chunk other offset different)

end KProgFormal.ClightRefinement.X86RegisterWriteRspPartialStore
