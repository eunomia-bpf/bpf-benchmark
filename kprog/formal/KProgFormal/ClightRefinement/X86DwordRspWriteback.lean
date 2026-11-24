import KProgFormal.ClightRefinement.X86FullWidthRspWriteback
import KProgFormal.ClightRefinement.X86RegisterWriterInputs

namespace KProgFormal.ClightRefinement.X86DwordRspWriteback
open X86RegisterView

/-- The actual RSP dword writer, including old-SP and old-cell reads,
width helper, local union copy, zero-extending overwrite and both table
stores. Initial representation and permissions construct every read/cast/store. -/
theorem execute (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (memory : CC.Mem) (localBlock bindingBlock cellsBlock baseBlock : CC.Block)
    (base baseOffset : CC.Integers.Ptrofs) (value old : BitVec 64) (shift : BitVec 8)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (destination : le.get X86_program_profile_bpf._dst =
      some (.Vint ((X86RegisterReadValue.registerByte 4).setWidth 32)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument .d))
    (code : BitVec 32)
    (alu : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint code))
    (scalarCode : code ≠ (0#32) ∧ code ≠ (1#32))
    (observedShift : le.get X86_program_profile_bpf.___x86_l_dst_shift = some (.Vint (shift.setWidth 32)))
    (observedValue : le.get X86_program_profile_bpf.___x86_l_result = some (.Vlong value))
    (widthBlock : CC.Block)
    (widthBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some widthBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv widthBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (unshadowed : e.get X86_program_profile_bpf._x86_width_effective = none)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (cells : CC.Mem.load CC.Mptr memory bindingBlock 0 = some (.Vptr cellsBlock base))
    (bindingSeparate : bindingBlock ≠ cellsBlock)
    (localSeparate : bindingBlock ≠ localBlock ∧ cellsBlock ≠ localBlock ∧ baseBlock ≠ localBlock)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (cpu : X86.Cpu) (represented : RegistersRepresent addresses origins memory cellsBlock base cpu)
    (rspRead : CC.Mem.load CC.Mptr memory cellsBlock
      (CC.Integers.Ptrofs.unsigned (base + 64)) = some (.Vlong old))
    (header : CC.Mem.load CC.Mptr memory bindingBlock 112 = some (.Vptr baseBlock baseOffset))
    (nativeBase : CC.Mem.load .Mint64 memory baseBlock (CC.Integers.Ptrofs.unsigned baseOffset) =
      some (.Vlong origins.stack))
    (nonIncreasing : CC.Integers.Int64.cmp .Cgt
      (X86FullWidthStorage.result true value - origins.stack) old = false)
    (localPermission : CC.Mem.validAccess memory CC.Mptr localBlock 0 .Writable = true)
    (wordPermission : CC.Mem.validAccess memory CC.Mptr cellsBlock
      (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * ((4 : Fin 16).val : Int)))) .Writable = true)
    (tagPermission : CC.Mem.validAccess memory .Mint8unsigned cellsBlock
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * ((4 : Fin 16).val : Int))) + 8))
      .Writable = true) :
    ∃ final finalTemps, InternalRun ge 223
      (.State function X86ShiftWriteback.writer k e le memory)
      (.State function .Sskip k e finalTemps final) ∧
      RegistersRepresent addresses origins final cellsBlock base
        (cpu.setReg .d (X86.GPR.ofIndex 4) value) ∧
      final.access = memory.access ∧ final.nextblock = memory.nextblock ∧
      (∀ chunk other offset, other ≠ localBlock → other ≠ cellsBlock →
        CC.Mem.load chunk final other offset = CC.Mem.load chunk memory other offset) := by
  obtain ⟨rawValue, tag, oldRead, tagRead, copyCast⟩ :=
    X86RegisterWriterInputs.cell addresses origins memory cellsBlock base cpu represented 4
  have rawEqual : rawValue = .Vlong old := Option.some.inj (oldRead.symm.trans rspRead)
  subst rawValue
  have copyExists : ∃ copied, CC.Mem.store CC.Mptr memory localBlock 0 (.Vlong old) = some copied := by
    simp only [CC.Mem.store, localPermission, ite_true]
    exact ⟨_, rfl⟩
  obtain ⟨copied, copiedStore⟩ := copyExists
  have entryRun := X86ShiftWriteback.narrow_storage ge layout.bindings layout.gpr layout.cell
    function e le k memory bindingBlock cellsBlock base (.Vlong old) binding cells rspRead (by rfl)
    (4 : Fin 16) .d (by decide) destination width alu widthBlock widthBinding unshadowed shift value
    observedShift observedValue (.Vlong old) oldRead copyCast localBlock copied declared copiedStore tag tagRead
    ⟨localSeparate.1, localSeparate.2.1⟩ scalarCode
  let reached := X86ShiftWriteback.classTemps
    (X86ShiftWriteback.tagTemps
      (X86ShiftWriteback.cellReadTemps
        (X86ShiftWriteback.writerWidthTemps
          (X86ShiftWriteback.loadTemps
            (X86ShiftWriteback.narrowSrcTemps (X86ShiftWriteback.narrowDstTemps
              (X86ShiftWriteback.selectTemps le (X86RegisterReadValue.registerByte 4) .d)))
            cellsBlock base (.Vlong old)) .d shift value) cellsBlock base (.Vlong old))
      (4 : Fin 16) cellsBlock base tag) .d
  have reachedWidth : reached.get X86_program_profile_bpf.___x86_wr_width__2 =
      some (X86ShiftLeft.argument .d) := by
    simp +decide [reached, X86ShiftWriteback.classTemps, X86ShiftWriteback.tagTemps,
      X86ShiftWriteback.tagReadTemps, X86ShiftWriteback.tagRegTemps,
      X86ShiftWriteback.cellReadTemps, X86ShiftWriteback.writerWidthTemps,
      X86ShiftWriteback.writerEffectiveTemps, CC.PTree.gso]
  have reachedValue : reached.get X86_program_profile_bpf.___x86_wr_next__2 = some (.Vlong value) := by
    simp +decide [reached, X86ShiftWriteback.classTemps, X86ShiftWriteback.tagTemps,
      X86ShiftWriteback.tagReadTemps, X86ShiftWriteback.tagRegTemps,
      X86ShiftWriteback.cellReadTemps, X86ShiftWriteback.writerWidthTemps, CC.PTree.gso]
  have reachedDestination : reached.get X86_program_profile_bpf._dst =
      some (.Vint ((X86RegisterReadValue.registerByte 4).setWidth 32)) := by
    simp +decide [reached, X86ShiftWriteback.classTemps, X86ShiftWriteback.tagTemps,
      X86ShiftWriteback.tagReadTemps, X86ShiftWriteback.tagRegTemps,
      X86ShiftWriteback.cellReadTemps, X86ShiftWriteback.writerWidthTemps,
      X86ShiftWriteback.writerEffectiveTemps, X86ShiftWriteback.writerRawTemps,
      X86ShiftWriteback.loadTemps, X86ShiftWriteback.narrowSrcTemps,
      X86ShiftWriteback.narrowDstTemps, X86ShiftWriteback.selectTemps, CC.PTree.gso, destination]
  have reachedBinding : reached.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0) := by
    simp +decide [reached, X86ShiftWriteback.classTemps, X86ShiftWriteback.tagTemps,
      X86ShiftWriteback.tagReadTemps, X86ShiftWriteback.tagRegTemps,
      X86ShiftWriteback.cellReadTemps, X86ShiftWriteback.writerWidthTemps,
      X86ShiftWriteback.writerEffectiveTemps, X86ShiftWriteback.writerRawTemps,
      X86ShiftWriteback.loadTemps, X86ShiftWriteback.narrowSrcTemps,
      X86ShiftWriteback.narrowDstTemps, X86ShiftWriteback.selectTemps, CC.PTree.gso, binding]
  have copiedFrame : ∀ chunk other offset, other ≠ localBlock →
      CC.Mem.load chunk copied other offset = CC.Mem.load chunk memory other offset := by
    intro chunk other offset different
    exact CC.Mem.load_store_other copiedStore chunk other offset (.inl different)
  have copiedRegisters : RegistersRepresent addresses origins copied cellsBlock base cpu := by
    intro row
    obtain ⟨v, raw, t, vr, tr, rep, native⟩ := represented row
    exact ⟨v, raw, t, (copiedFrame _ cellsBlock _ localSeparate.2.1).trans vr,
      (copiedFrame _ cellsBlock _ localSeparate.2.1).trans tr, rep, native⟩
  have reachedOld : reached.get X86_program_profile_bpf.___x86_write_old_sp__5 = some (.Vlong old) := by
    simp +decide [reached, X86ShiftWriteback.classTemps, X86ShiftWriteback.tagTemps,
      X86ShiftWriteback.tagReadTemps, X86ShiftWriteback.tagRegTemps,
      X86ShiftWriteback.cellReadTemps, X86ShiftWriteback.writerWidthTemps,
      X86ShiftWriteback.writerEffectiveTemps, X86ShiftWriteback.writerRawTemps,
      X86ShiftWriteback.loadTemps, CC.PTree.gss, CC.PTree.gso]
  have destinationCode : (X86RegisterReadValue.registerByte 4).setWidth 32 = (4#32) := rfl
  obtain ⟨final, finalTemps, tailRun, native, access, next, kept⟩ :=
    X86FullWidthRspWriteback.from_storage ge layout valueLayout function e reached k copied localBlock bindingBlock
      cellsBlock baseBlock base baseOffset value old true declared reachedWidth reachedValue
      (by simpa only [destinationCode] using reachedDestination)
      reachedBinding reachedOld ((copiedFrame _ bindingBlock _ localSeparate.1).trans cells)
      ((copiedFrame _ bindingBlock _ localSeparate.1).trans header) bindingSeparate localSeparate addresses origins
      ((copiedFrame _ baseBlock _ localSeparate.2.2).trans nativeBase) cpu copiedRegisters nonIncreasing
      ((CC.Mem.validAccess_store_eq copiedStore _ _ _ .Writable).trans localPermission)
      ((CC.Mem.validAccess_store_eq copiedStore _ _ _ .Writable).trans wordPermission)
      ((CC.Mem.validAccess_store_eq copiedStore _ _ _ .Writable).trans tagPermission)
  refine ⟨final, _, entryRun.trans tailRun, native,
    access.trans (CC.Mem.store_access copiedStore),
    next.trans (CC.Mem.store_nextblock copiedStore), ?_⟩
  intro chunk other offset notLocal notCells
  exact (kept chunk other offset notLocal notCells).trans (copiedFrame chunk other offset notLocal)

/-- At the genuine allocated handler environment, caller table rights and
entry access supply the fresh local, its separation and all writer permissions.
No local store, read result or helper-scope assumption is added. -/
theorem allocated (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (caller memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (bindingBlock cellsBlock baseBlock : CC.Block) (base baseOffset : CC.Integers.Ptrofs)
    (value old : BitVec 64) (shift : BitVec 8)
    (destination : le.get X86_program_profile_bpf._dst =
      some (.Vint ((X86RegisterReadValue.registerByte 4).setWidth 32)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument .d))
    (code : BitVec 32)
    (alu : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint code))
    (scalarCode : code ≠ (0#32) ∧ code ≠ (1#32))
    (observedShift : le.get X86_program_profile_bpf.___x86_l_dst_shift = some (.Vint (shift.setWidth 32)))
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
    (header : CC.Mem.load CC.Mptr memory bindingBlock 112 = some (.Vptr baseBlock baseOffset))
    (nativeBase : CC.Mem.load .Mint64 memory baseBlock (CC.Integers.Ptrofs.unsigned baseOffset) =
      some (.Vlong origins.stack))
    (nonIncreasing : CC.Integers.Int64.cmp .Cgt
      (X86FullWidthStorage.result true value - origins.stack) old = false)
    (baseOld : baseBlock.toNat < caller.nextblock.toNat)
    (bindingOld : bindingBlock.toNat < caller.nextblock.toNat)
    (cellsOld : cellsBlock.toNat < caller.nextblock.toNat)
    (access : memory.access = (writerAllocation ge.genv_cenv caller).2.access)
    (wordPermission : CC.Mem.validAccess caller CC.Mptr cellsBlock
      (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * ((4 : Fin 16).val : Int)))) .Writable = true)
    (tagPermission : CC.Mem.validAccess caller .Mint8unsigned cellsBlock
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * ((4 : Fin 16).val : Int))) + 8))
      .Writable = true) :
    ∃ final finalTemps, InternalRun ge 223
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG X86ShiftWriteback.writer k
        (writerAllocation ge.genv_cenv caller).1 le memory)
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG .Sskip k
        (writerAllocation ge.genv_cenv caller).1 finalTemps final) ∧
      RegistersRepresent addresses origins final cellsBlock base
        (cpu.setReg .d (X86.GPR.ofIndex 4) value) ∧
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
    execute ge layout valueLayout X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG
      (writerAllocation ge.genv_cenv caller).1 le k memory localBlock bindingBlock cellsBlock baseBlock base baseOffset
      value old shift declared destination width code alu scalarCode observedShift observedValue
      widthBlock widthBinding unshadowed binding cells bindingSeparate ⟨separate.1, separate.2, baseSeparate⟩ addresses origins
      cpu represented rspRead header nativeBase nonIncreasing localRight wordRight tagRight
  refine ⟨final, finalTemps, run, native, finalAccess, finalNext, ?_⟩
  intro chunk block offset old notCells
  have fresh := ((allocated_local_storage allocation).1 _ _ declared).1
  dsimp only at fresh
  have different : block ≠ localBlock := by
    intro same
    have encoded := congrArg CC.Positive.toNat same
    omega
  exact kept chunk block offset different notCells

end KProgFormal.ClightRefinement.X86DwordRspWriteback
