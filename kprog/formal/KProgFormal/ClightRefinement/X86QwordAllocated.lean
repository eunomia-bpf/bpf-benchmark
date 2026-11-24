import KProgFormal.ClightRefinement.X86QwordWriteback

namespace KProgFormal.ClightRefinement.X86QwordAllocated
open X86RegisterView

/-- Genuine handler allocation supplies the local binding, separation,
all writer permissions and both helper scopes for the complete252-step writer.
No local store success or old-SP/old-cell read premise is added. -/
theorem execute (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (caller memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (bindingBlock cellsBlock : CC.Block) (base : CC.Integers.Ptrofs)
    (index : Fin 16) (value : BitVec 64)
    (destination : le.get X86_program_profile_bpf._dst =
      some (.Vint ((X86RegisterReadValue.registerByte index).setWidth 32)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument .q))
    (code : BitVec 32)
    (alu : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint code))
    (scalarCode : code ≠ (0#32) ∧ code ≠ (1#32))
    (observedShift : le.get X86_program_profile_bpf.___x86_l_dst_shift = some (.Vint (0#32)))
    (sourceShift : le.get X86_program_profile_bpf.___x86_l_src_shift = some (.Vint (0#32)))
    (observedValue : le.get X86_program_profile_bpf.___x86_l_result = some (.Vlong value))
    (widthBlock : CC.Block)
    (widthBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some widthBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv widthBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (tagHelper : CC.Block)
    (tagBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_reg_tag = some tagHelper ∧
      CC.Genv.findFunctPtr ge.genv_genv tagHelper =
        some (.Internal X86_program_profile_bpf.f_x86_sim_inline_reg_tag))
    (ordinary : index ≠ 4)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (cells : CC.Mem.load CC.Mptr memory bindingBlock 0 = some (.Vptr cellsBlock base))
    (scalarTag : CC.Mem.load .Mint8unsigned memory cellsBlock
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) =
        some (X86Width.argument (0#8)))
    (bindingSeparate : bindingBlock ≠ cellsBlock)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (cpu : X86.Cpu) (represented : RegistersRepresent addresses origins memory cellsBlock base cpu)
    (bindingOld : bindingBlock.toNat < caller.nextblock.toNat)
    (cellsOld : cellsBlock.toNat < caller.nextblock.toNat)
    (access : memory.access = (writerAllocation ge.genv_cenv caller).2.access)
    (wordPermission : CC.Mem.validAccess caller CC.Mptr cellsBlock
      (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) .Writable = true)
    (tagPermission : CC.Mem.validAccess caller .Mint8unsigned cellsBlock
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8))
      .Writable = true) :
    ∃ final finalTemps, InternalRun ge 252
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG X86ShiftWriteback.writer k
        (writerAllocation ge.genv_cenv caller).1 le memory)
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG .Sskip k
        (writerAllocation ge.genv_cenv caller).1 finalTemps final) ∧
      RegistersRepresent addresses origins final cellsBlock base
        (cpu.setReg .q (X86.GPR.ofIndex index) value) ∧
      final.access = memory.access ∧ final.nextblock = memory.nextblock ∧
      (∀ chunk block offset, block.toNat < caller.nextblock.toNat → block ≠ cellsBlock →
        CC.Mem.load chunk final block offset = CC.Mem.load chunk memory block offset) := by
  have allocation : CC.AllocVariables ge.genv_cenv CC.emptyEnv caller
      X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_vars
      (writerAllocation ge.genv_cenv caller).1 (writerAllocation ge.genv_cenv caller).2 :=
    CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (writerAllocation ge.genv_cenv caller)).symm
  obtain ⟨localBlock, declared, separate, localRight, wordRight, tagRight⟩ :=
    writer_entry_storage ge.genv_cenv layout.gpr caller memory bindingBlock cellsBlock
      bindingOld cellsOld access _ _ wordPermission tagPermission
  have notLocal : X86_program_profile_bpf._x86_width_effective ∉
      CC.varNames X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_vars := by decide +kernel
  have unshadowed : (writerAllocation ge.genv_cenv caller).1.get
      X86_program_profile_bpf._x86_width_effective = none := by
    simpa only [CC.emptyEnv, CC.PTree.gempty] using
      CC.allocVariables_env_other allocation notLocal
  have tagNotLocal : X86_program_profile_bpf._x86_sim_inline_reg_tag ∉
      CC.varNames X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_vars := by decide +kernel
  have tagUnshadowed : (writerAllocation ge.genv_cenv caller).1.get
      X86_program_profile_bpf._x86_sim_inline_reg_tag = none := by
    simpa only [CC.emptyEnv, CC.PTree.gempty] using CC.allocVariables_env_other allocation tagNotLocal
  obtain ⟨final, finalTemps, run, native, finalAccess, finalNext, kept⟩ :=
    X86QwordWriteback.execute ge layout X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG
      (writerAllocation ge.genv_cenv caller).1 le k memory localBlock bindingBlock cellsBlock base
      index value declared destination width code alu scalarCode observedShift sourceShift observedValue
      widthBlock widthBinding unshadowed tagHelper tagBinding tagUnshadowed ordinary binding cells scalarTag
      bindingSeparate separate addresses origins
      cpu represented localRight wordRight tagRight
  refine ⟨final, finalTemps, run, native, finalAccess, finalNext, ?_⟩
  intro chunk block offset old notCells
  have fresh := ((allocated_local_storage allocation).1 _ _ declared).1
  dsimp only at fresh
  have different : block ≠ localBlock := by
    intro same
    have encoded := congrArg CC.Positive.toNat same
    omega
  exact kept chunk block offset different notCells

end KProgFormal.ClightRefinement.X86QwordAllocated
