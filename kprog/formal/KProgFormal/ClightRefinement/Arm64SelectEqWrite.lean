import KProgFormal.ClightRefinement.Arm64SelectWrite

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Select

/-- The actual condition and path-result temporaries before CSEL writeback. -/
def eqTemps {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (le : CC.TempEnv) (native : Reference.AArch64.State) : CC.TempEnv :=
  PathCall.temps (Condition.temps le (fun i => (storage.flags i).block)
    (read_flag .Z native.machine)) (28#32) (8#8)

private theorem eq_truth (native : Reference.AArch64.State) :
    (read_flag .Z native.machine).setWidth 32 =
      (if ConditionHolds (0#4) native.machine then 1 else 0) := by
  have bits : ∀ z : BitVec 1, z=0#1 ∨ z=1#1 := by decide +kernel
  rcases bits (read_flag .Z native.machine) with zero|one
  · simp +decide [ConditionHolds,BitVec.lsb,zero]
  · simp +decide [ConditionHolds,BitVec.lsb,one]

private theorem eqTemps_original {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (le : CC.TempEnv) (native : Reference.AArch64.State) (id : CC.Ident)
    (original : id ∈ [Arm64Program._entry,Arm64Program._dst,Arm64Program._src,Arm64Program._src2]) :
    (eqTemps storage le native).get id = le.get id := by
  simp at original
  rcases original with rfl|rfl|rfl|rfl
  all_goals
    rw [eqTemps,PathCall.temps_other _ _ _ _ (by decide +kernel),
      Condition.temps_other _ _ _ _ (by decide +kernel)]

/-- The actual EQ flag loads, condition call, normalization and path helper
compose with selected read/writeback and the fetched native CSEL64. The choice
is derived from the pre-state flags, rather than supplied as a taken premise. -/
theorem eq_write_matches {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (native : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (dst lhs rhs : Fin 31)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      m.nextblock m (.Vptr entry.block 0) native)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (conditionNameFree : e.get Arm64Program._kprog_arm64_program_condition = none)
    (pathNameFree : e.get Arm64Program._kprog_arm64_csel_path = none)
    (pointerNameFree : e.get Arm64Program._kprog_arm64_program_pointer = none)
    (tagNameFree : e.get Arm64Program._kprog_arm64_program_tag = none)
    (writerNameFree : e.get Arm64Program._kprog_arm64_program_write_pointer = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (left : le.get Arm64Program._src = some (.Vlong (BitVec.ofNat 64 lhs.val)))
    (right : le.get Arm64Program._src2 = some (.Vlong (BitVec.ofNat 64 rhs.val)))
    (destination : le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 dst.val)))
    (aux : le.get Arm64Program._aux = some (.Vint 0))
    (op : le.get Arm64Program._op = some (.Vint (28#32)))
    (width : le.get Arm64Program.___a64_l_width = some (.Vint (8#32)))
    (decoded : instruction.decoded = .DPR (.Conditional_select (Native.fields dst lhs rhs (0#4))))
    (noError : read_err native.machine = .None)
    (fetched : fetch_inst (read_pc native.machine) native.machine = some instruction.encoding) :
    ∃ value raw tag after,
      Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0)
        (if ConditionHolds (0#4) native.machine then lhs else rhs).val =
          some (value,.Vint (tag.setWidth 32)) ∧
      Arm64Registers.ValueRep addresses value raw ∧
      Arm64PointerWrite.ValueResult storage dst value tag after ∧
      InternalRun Arm64ProgramEntryLinked.ge 186
        (.State Arm64Nop.handler Condition.branch k e le m)
        (.State Arm64Nop.handler .Sskip k e
          (Branch.temps (ConditionHolds (0#4) native.machine) (eqTemps storage le native) value tag) after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) m.nextblock after (.Vptr entry.block 0)
        (Arm64PointerWrite.nativeUpdate origins native dst raw tag) ∧
      Arm64CacheLocalFrame.Kept initial m after dst ∧
      Reference.AArch64.step native =
        ⟨Arm64Nop.atCursor (read_pc native.machine + 4#64)
          (Arm64PointerWrite.nativeUpdate origins native dst raw tag), [], none⟩ := by
  have conditionRun : InternalRun Arm64ProgramEntryLinked.ge 66
      (.State Arm64Nop.handler Condition.branch k e le m)
      (.State Arm64Nop.handler Branch.source k e (eqTemps storage le native) m) := by
    simpa only [PathCall.csel64_source,Branch.source,eqTemps] using
      PathCall.execute_condition storage native represented.flags e le k (28#32) (8#8)
        (.inl rfl) conditionNameFree pathNameFree entryRead aux op width
  have decision : (eqTemps storage le native).get Arm64Program.___a64_l_taken =
      some (.Vint (if ConditionHolds (0#4) native.machine then 1 else 0)) := by
    rw [eqTemps,PathCall.temps_other _ _ _ _ (by decide +kernel),Condition.taken_value,eq_truth]
  have index : (eqTemps storage le native).get (Branch.sourceName (ConditionHolds (0#4) native.machine)) =
      some (.Vlong (BitVec.ofNat 64 (if ConditionHolds (0#4) native.machine then lhs else rhs).val)) := by
    cases taken : ConditionHolds (0#4) native.machine
    all_goals
      simp only [Branch.sourceName,taken,Bool.false_eq_true,ite_false,ite_true]
      rw [eqTemps_original storage le native _ (by simp)]
      assumption
  obtain ⟨value,raw,tag,after,read,bits,result,run,registers,kept,step⟩ := write_matches storage
    addresses origins native instruction dst lhs rhs (0#4) represented e (eqTemps storage le native) k
    pointerNameFree tagNameFree writerNameFree decision
    ((eqTemps_original storage le native _ (by simp)).trans entryRead) index
    ((eqTemps_original storage le native _ (by simp)).trans destination) decoded noError fetched
  exact ⟨value,raw,tag,after,read,bits,result,conditionRun.trans run,registers,kept,step⟩

end KProgFormal.ClightRefinement.Arm64Select
