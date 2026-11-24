import KProgFormal.ClightRefinement.X86PartialRspWriteback

namespace KProgFormal.ClightRefinement.X86PartialRspAllocated
open X86RegisterView

/-- At the genuine allocated handler environment, caller table rights and
entry access supply the fresh local, its separation and all writer permissions.
No local store, read result or helper-scope assumption is added. -/
theorem execute (isWord : Bool) (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (caller memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (bindingBlock cellsBlock baseBlock : CC.Block) (base baseOffset : CC.Integers.Ptrofs)
    (value old : BitVec 64) (shift : BitVec 8)
    (destination : le.get X86_program_profile_bpf._dst =
      some (.Vint ((X86RegisterReadValue.registerByte 4).setWidth 32)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument (if isWord then .w else .b)))
    (code : BitVec 32)
    (alu : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint code))
    (scalarCode : code ≠ (0#32) ∧ code ≠ (1#32))
    (observedShift : le.get X86_program_profile_bpf.___x86_l_dst_shift = some (.Vint (shift.setWidth 32)))
    (low : isWord = false → shift = 0)
    (observedValue : le.get X86_program_profile_bpf.___x86_l_result = some (.Vlong value))
    (widthBlock : CC.Block)
    (widthBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some widthBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv widthBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (cells : CC.Mem.load CC.Mptr memory bindingBlock 0 = some (.Vptr cellsBlock base))
    (bindingSeparate : bindingBlock ≠ cellsBlock)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (cpu : X86.Cpu) (represented : RegistersRepresent addresses origins memory cellsBlock base cpu)
    (rspRead : CC.Mem.load CC.Mptr memory cellsBlock
      (CC.Integers.Ptrofs.unsigned (base + 64)) = some (.Vlong old))
    (scalar : CC.Mem.load .Mint8unsigned memory cellsBlock
      (CC.Integers.Ptrofs.unsigned ((base + 64) + 8)) = some (.Vint (0#32)))
    (header : CC.Mem.load CC.Mptr memory bindingBlock 112 = some (.Vptr baseBlock baseOffset))
    (nativeBase : CC.Mem.load .Mint64 memory baseBlock (CC.Integers.Ptrofs.unsigned baseOffset) =
      some (.Vlong origins.stack))
    (nonIncreasing : CC.Integers.Int64.cmp .Cgt
      (X86.Value.writeView (if isWord then .w else .b) (old + origins.stack) value - origins.stack) old = false)
    (baseOld : baseBlock.toNat < caller.nextblock.toNat)
    (bindingOld : bindingBlock.toNat < caller.nextblock.toNat)
    (cellsOld : cellsBlock.toNat < caller.nextblock.toNat)
    (access : memory.access = (writerAllocation ge.genv_cenv caller).2.access)
    (wordPermission : CC.Mem.validAccess caller CC.Mptr cellsBlock
      (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * ((4 : Fin 16).val : Int)))) .Writable = true)
    (tagPermission : CC.Mem.validAccess caller .Mint8unsigned cellsBlock
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * ((4 : Fin 16).val : Int))) + 8))
      .Writable = true) :
    ∃ final finalTemps, InternalRun ge (if isWord then 216 else 204)
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG X86ShiftWriteback.writer k
        (writerAllocation ge.genv_cenv caller).1 le memory)
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG .Sskip k
        (writerAllocation ge.genv_cenv caller).1 finalTemps final) ∧
      RegistersRepresent addresses origins final cellsBlock base
        (cpu.setReg (if isWord then .w else .b) (X86.GPR.ofIndex 4) value) ∧
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
  have baseSeparate : baseBlock ≠ localBlock := by
    have fresh := ((allocated_local_storage allocation).1 _ _ declared).1
    dsimp only at fresh
    intro same
    have encoded := congrArg CC.Positive.toNat same
    omega
  obtain ⟨final, finalTemps, run, native, finalAccess, finalNext, kept⟩ :=
    X86PartialRspWriteback.execute isWord ge layout valueLayout X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG
      (writerAllocation ge.genv_cenv caller).1 le k memory localBlock bindingBlock cellsBlock baseBlock base baseOffset
      value old shift declared destination width code alu scalarCode observedShift low observedValue
      widthBlock widthBinding unshadowed binding cells bindingSeparate ⟨separate.1, separate.2, baseSeparate⟩ addresses origins
      cpu represented rspRead scalar header nativeBase nonIncreasing localRight wordRight tagRight
  refine ⟨final, finalTemps, run, native, finalAccess, finalNext, ?_⟩
  intro chunk block offset old notCells
  have fresh := ((allocated_local_storage allocation).1 _ _ declared).1
  dsimp only at fresh
  have different : block ≠ localBlock := by
    intro same
    have encoded := congrArg CC.Positive.toNat same
    omega
  exact kept chunk block offset different notCells

end KProgFormal.ClightRefinement.X86PartialRspAllocated
