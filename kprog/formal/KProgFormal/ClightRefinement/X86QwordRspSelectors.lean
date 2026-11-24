import KProgFormal.ClightRefinement.X86QwordWriterSelectors

namespace KProgFormal.ClightRefinement.X86QwordRspSelectors

/-- The real RSP qword selector takes its13-step stack probe, then the same
two destination-tag calls and non-ADD source selector. Stored tag0 and the
actual source fields derive the complete113-step path to the default writer. -/
theorem execute (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (code : BitVec 32)
    (bindingBlock cellsBlock helperBlock : CC.Block) (base : CC.Integers.Ptrofs)
    (destination : le.get X86_program_profile_bpf._dst =
      some (X86Width.argument (X86RegisterReadValue.registerByte 4)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument .q))
    (dstShift : le.get X86_program_profile_bpf.___x86_l_dst_shift = some (.Vint (0#32)))
    (srcShift : le.get X86_program_profile_bpf.___x86_l_src_shift = some (.Vint (0#32)))
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint code))
    (scalarCode : code ≠ (0#32) ∧ code ≠ (1#32))
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (helper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_reg_tag = some helperBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv helperBlock =
        some (.Internal X86_program_profile_bpf.f_x86_sim_inline_reg_tag))
    (unshadowed : e.get X86_program_profile_bpf._x86_sim_inline_reg_tag = none)
    (cells : CC.Mem.load CC.Mptr memory bindingBlock 0 = some (.Vptr cellsBlock base))
    (current : CC.Mem.load .Mint8unsigned memory cellsBlock
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * ((4 : Fin 16).val : Int))) + 8)) =
        some (X86Width.argument (0#8))) :
    InternalRun ge 113 (.State function X86ShiftWriteback.writer k e le memory)
      (.State function X86ShiftWriteback.defaultWriter k e (X86QwordWriterSelectors.temps le 4) memory) := by
  have selected := X86ShiftWriteback.select_scalar ge function e le k memory
    (X86RegisterReadValue.registerByte 4) .q destination width operation scalarCode
  have length : X86ShiftWriteback.selectLength (X86RegisterReadValue.registerByte 4) .q = 13 := rfl
  rw [length] at selected
  let ready := X86ShiftWriteback.selectTemps le (X86RegisterReadValue.registerByte 4) .q
  have destinationRun := X86QwordDestinationScalar.execute ge layout function e ready k memory (4 : Fin 16)
    bindingBlock cellsBlock helperBlock 0 base
    (by simp +decide [ready, X86ShiftWriteback.selectTemps, CC.PTree.gso, width])
    (by simp +decide [ready, X86ShiftWriteback.selectTemps, CC.PTree.gso, dstShift])
    (by simp +decide [ready, X86ShiftWriteback.selectTemps, CC.PTree.gso, srcShift])
    (by simp +decide [ready, X86ShiftWriteback.selectTemps, CC.PTree.gso, destination])
    (by simp +decide [ready, X86ShiftWriteback.selectTemps, CC.PTree.gso, binding])
    helper unshadowed cells current
  have sourceRun := X86QwordSource.execute ge function e (X86QwordWriterSelectors.destinationTemps le 4) k memory code
    ((X86QwordWriterSelectors.destination_get le 4 _ (by decide +kernel)).trans width)
    ((X86QwordWriterSelectors.destination_get le 4 _ (by decide +kernel)).trans dstShift)
    ((X86QwordWriterSelectors.destination_get le 4 _ (by decide +kernel)).trans srcShift)
    ((X86QwordWriterSelectors.destination_get le 4 _ (by decide +kernel)).trans operation) scalarCode.1
  exact (selected.trans destinationRun).trans sourceRun

end KProgFormal.ClightRefinement.X86QwordRspSelectors
