import KProgFormal.ClightRefinement.X86RegisterWriteRsp

namespace KProgFormal.ClightRefinement.X86RegisterWriteRspWritable

/-- Initial local write access derives the real reverse-materialization store,
its exact source run, readback, allocation frontier and frame. -/
theorem execute (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (memory : CC.Mem) (bindingBlock localBlock baseBlock : CC.Block)
    (baseOffset : CC.Integers.Ptrofs) (value nativeBase : BitVec 64)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint (4#32)))
    (current : CC.Mem.load CC.Mptr memory localBlock 0 = some (.Vlong value))
    (header : CC.Mem.load CC.Mptr memory bindingBlock 112 = some (.Vptr baseBlock baseOffset))
    (native : CC.Mem.load .Mint64 memory baseBlock (CC.Integers.Ptrofs.unsigned baseOffset) =
      some (.Vlong nativeBase))
    (permission : CC.Mem.validAccess memory CC.Mptr localBlock 0 .Writable = true) :
    ∃ after, CC.Mem.store CC.Mptr memory localBlock 0 (.Vlong (value - nativeBase)) = some after ∧
    InternalRun ge 14
      (.State function .Sskip (.Kseq X86ShiftWriteback.storageTail k) e le memory)
      (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_112 k e
        (X86RegisterWriteRsp.temps le baseBlock baseOffset value nativeBase) after) ∧
      CC.Mem.load CC.Mptr after localBlock 0 = some (.Vlong (value - nativeBase)) ∧
      after.access = memory.access ∧ after.nextblock = memory.nextblock ∧
      (∀ chunk other offset, other ≠ localBlock →
        CC.Mem.load chunk after other offset = CC.Mem.load chunk memory other offset) := by
  have existsStore : ∃ after, CC.Mem.store CC.Mptr memory localBlock 0
      (.Vlong (value - nativeBase)) = some after := by
    simp only [CC.Mem.store, permission, ite_true]
    exact ⟨_, rfl⟩
  obtain ⟨after, stored⟩ := existsStore
  have normalized : CC.Val.loadResult CC.Mptr (.Vlong (value - nativeBase)) =
      .Vlong (value - nativeBase) := rfl
  refine ⟨after, stored,
    X86RegisterWriteRsp.run ge layout valueLayout function e le k memory after
      bindingBlock localBlock baseBlock baseOffset value nativeBase
      declared binding destination current header native stored,
    (CC.Mem.load_store_same stored).trans (congrArg some normalized),
    CC.Mem.store_access stored, CC.Mem.store_nextblock stored, ?_⟩
  intro chunk other offset different
  exact CC.Mem.load_store_other stored chunk other offset (.inl different)

end KProgFormal.ClightRefinement.X86RegisterWriteRspWritable
