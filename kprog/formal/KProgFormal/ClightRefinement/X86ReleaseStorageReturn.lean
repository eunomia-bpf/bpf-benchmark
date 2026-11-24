import KProgFormal.ClightRefinement.X86ReleaseReturn
import KProgFormal.ClightRefinement.X86RegisterWriteRspStorage

namespace KProgFormal.ClightRefinement.X86ReleaseStorageReturn
open X86RegisterView
open X86ReleaseProvider (Available)

/-- Reverse materialization, both actual RSP table stores, either signed-SP
release branch and original handler free/return compose from initial source
observations. Every release read and native post-write view is derived from
those stores. Provider ABI and architectural ownership remain explicit. -/
theorem execute (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (stackLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_stack_mem = some X86RegisterWriteRspReleaseWord.stackRecord)
    (caller memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (binding localBlock baseBlock cells stack input helper : CC.Block)
    (baseOffset cellOffset cacheOffset : CC.Integers.Ptrofs) (places : X86CallFrameComplete.Places)
    (value old : BitVec 64) (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.X86.Origins) (cpu : X86.Cpu) (flags : X86LogicFlagOrder.Locations)
    (declared : (writerAllocation ge.genv_cenv caller).1.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (bindingRead : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint (4#32)))
    (savedOld : le.get X86_program_profile_bpf.___x86_write_old_sp__5 = some (.Vlong old))
    (current : CC.Mem.load CC.Mptr memory localBlock 0 = some (.Vlong value))
    (header : CC.Mem.load CC.Mptr memory binding 112 = some (.Vptr baseBlock baseOffset))
    (native : CC.Mem.load .Mint64 memory baseBlock (CC.Integers.Ptrofs.unsigned baseOffset) = some (.Vlong origins.stack))
    (bindingCells : binding ≠ cells)
    (tag : le.get X86_program_profile_bpf.___x86_wr_cell_tag__2 = some (.Vint (0#32)))
    (represented : RegistersRepresent addresses origins memory cells cellOffset cpu)
    (flagValues : X86LogicFlagMemory.FlagsRepresent memory flags cpu.flags)
    (view : X86ReleaseOuterComplete.View memory binding stack cells cacheOffset cellOffset places old)
    (symbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._native_lab_entry_input = some input)
    (global : CC.Genv.findFunctPtr ge.genv_genv input = some X86RegisterWriteRspReleaseWord.inputFunction)
    (helperSymbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_call_frame_values = some helper)
    (helperGlobal : CC.Genv.findFunctPtr ge.genv_genv helper = some (.Internal X86CallFrameEntry.handler))
    (bindingSeparate : binding ≠ stack) (cellsSeparate : cells ≠ stack)
    (metadataSeparate : X86CallFrameComplete.Separated binding places)
    (available : Available ge binding stack cacheOffset)
    (cellsOutside : X86ReleaseReturn.ObserverOutside stack places cells)
    (flagsOutside : X86ReleaseReturn.FlagsOutside stack places flags)
    (flagsNotCells : flags.cf.1 ≠ cells ∧ flags.zf.1 ≠ cells ∧ flags.sf.1 ≠ cells ∧
      flags.overflow.1 ≠ cells ∧ flags.pf.1 ≠ cells)
    (bindingOld : binding.toNat < caller.nextblock.toNat) (cellsOld : cells.toNat < caller.nextblock.toNat)
    (flagsOld : flags.cf.1.toNat < caller.nextblock.toNat ∧ flags.zf.1.toNat < caller.nextblock.toNat ∧
      flags.sf.1.toNat < caller.nextblock.toNat ∧ flags.overflow.1.toNat < caller.nextblock.toNat ∧
      flags.pf.1.toNat < caller.nextblock.toNat)
    (access : memory.access = (writerAllocation ge.genv_cenv caller).2.access)
    (wordPermission : CC.Mem.validAccess memory CC.Mptr cells
      (CC.Integers.Ptrofs.unsigned (cellOffset + 64)) .Writable = true)
    (tagPermission : CC.Mem.validAccess memory .Mint8unsigned cells
      (CC.Integers.Ptrofs.unsigned ((cellOffset + 64) + 8)) .Writable = true)
    (boundary : CC.isCallCont k = true) :
    ∃ trace final, CC.Star (CC.Step2 ge)
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG .Sskip
        (.Kseq X86ShiftWriteback.storageTail (X86ShiftWriteback.loadCont (X86AluEntry.continuation k)))
        (writerAllocation ge.genv_cenv caller).1 le memory) trace
      (.Returnstate .Vundef k final) ∧
    RegistersRepresent addresses origins final cells cellOffset (cpu.setReg .q (X86.GPR.ofIndex 4) value) ∧
    X86LogicFlagMemory.FlagsRepresent final flags cpu.flags ∧ final.nextblock = memory.nextblock ∧
    (∀ row ∈ CC.blocksOfEnv ge.genv_cenv (writerAllocation ge.genv_cenv caller).1,
      ∀ offset, row.2.1 ≤ offset → offset < row.2.2 →
      ∀ kind permission, CC.Mem.perm final row.1 offset kind permission = false) ∧
    (∀ chunk block offset, block.toNat < caller.nextblock.toNat → block ≠ cells →
      X86ReleaseReturn.ObserverOutside stack places block →
      CC.Mem.load chunk final block offset = CC.Mem.load chunk memory block offset) := by
  have allocation : CC.AllocVariables ge.genv_cenv CC.emptyEnv caller
      X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_vars
      (writerAllocation ge.genv_cenv caller).1 (writerAllocation ge.genv_cenv caller).2 :=
    CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (writerAllocation ge.genv_cenv caller)).symm
  have localStorage := (allocated_local_storage allocation).1 _ _ declared
  have fresh : caller.nextblock.toNat ≤ localBlock.toNat := localStorage.1
  have localOutside (block : CC.Block) (oldBlock : block.toNat < caller.nextblock.toNat) : block ≠ localBlock := by
    intro same
    have encoded := congrArg CC.Positive.toNat same
    omega
  have localPermission : CC.Mem.validAccess memory CC.Mptr localBlock 0 .Writable = true :=
    writer_local_writable ge.genv_cenv layout.gpr caller memory localBlock declared access
  have bindingLocal := localOutside binding bindingOld
  have cellsLocal := localOutside cells cellsOld
  obtain ⟨written, storageRun, registers, readback, storageAccess, storageNext, storageFrame⟩ :=
    X86RegisterWriteRspStorage.execute_readback ge layout valueLayout
      X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG (writerAllocation ge.genv_cenv caller).1 le
      (X86ShiftWriteback.loadCont (X86AluEntry.continuation k)) memory binding localBlock baseBlock cells baseOffset cellOffset value addresses origins cpu
      declared bindingRead destination current header native localPermission ⟨bindingLocal.symm, cellsLocal.symm⟩
      bindingCells view.table tag represented wordPermission tagPermission
  have bindingFrame (chunk : CC.Chunk) (offset : Int) := storageFrame chunk binding offset bindingLocal bindingCells
  have rights (chunk : CC.Chunk) (block : CC.Block) (offset : Int) (permission : CC.Permission) :=
    X86ReleaseProvider.access_rights memory written storageAccess chunk block offset permission
  have releaseView : X86ReleaseOuterComplete.View written binding stack cells cacheOffset cellOffset places (value - origins.stack) := by
    refine ⟨⟨(bindingFrame CC.Mptr 8).trans view.cache.header, ?_, ?_⟩, ?_,
      (bindingFrame CC.Mptr 0).trans view.table, readback⟩
    · intro slot lane
      exact (rights _ _ _ _).trans (view.cache.bytes slot lane)
    · intro slot
      exact (rights _ _ _ _).trans (view.cache.words slot)
    · refine ⟨?_, ?_, ?_, ?_⟩
      · intro slot
        exact (bindingFrame CC.Mptr _).trans (view.metadata.tags slot)
      · intro slot
        exact (bindingFrame CC.Mptr _).trans (view.metadata.pointers slot)
      · intro slot
        exact (rights _ _ _ _).trans (view.metadata.tag_rights slot)
      · intro slot
        exact (rights _ _ _ _).trans (view.metadata.pointer_rights slot)
  have flags : X86LogicFlagMemory.FlagsRepresent written flags (cpu.setReg .q (X86.GPR.ofIndex 4) value).flags :=
    ⟨(storageFrame _ _ _ (localOutside _ flagsOld.1) flagsNotCells.1).trans flagValues.cf,
      (storageFrame _ _ _ (localOutside _ flagsOld.2.1) flagsNotCells.2.1).trans flagValues.zf,
      (storageFrame _ _ _ (localOutside _ flagsOld.2.2.1) flagsNotCells.2.2.1).trans flagValues.sf,
      (storageFrame _ _ _ (localOutside _ flagsOld.2.2.2.1) flagsNotCells.2.2.2.1).trans flagValues.overflow,
      (storageFrame _ _ _ (localOutside _ flagsOld.2.2.2.2) flagsNotCells.2.2.2.2).trans flagValues.pf⟩
  let ready := X86ShiftWriteback.tableTemps (X86RegisterWriteRsp.temps le baseBlock baseOffset value origins.stack)
    (.Vlong (value - origins.stack)) (0#8) 4 cells cellOffset
  have readyBinding : ready.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0) := by
    simp +decide [ready, X86ShiftWriteback.tableTemps, X86ShiftWriteback.tableStoreTemps, X86ShiftWriteback.tableIndexTemps,
      X86ShiftWriteback.tableLoadTemps, X86RegisterWriteRsp.temps, CC.PTree.gso, bindingRead]
  have readyDestination : ready.get X86_program_profile_bpf._dst = some (.Vint (4#32)) := by
    simp +decide [ready, X86ShiftWriteback.tableTemps, X86ShiftWriteback.tableStoreTemps, X86ShiftWriteback.tableIndexTemps,
      X86ShiftWriteback.tableLoadTemps, X86RegisterWriteRsp.temps, CC.PTree.gso, destination]
  have readyOld : ready.get X86_program_profile_bpf.___x86_write_old_sp__5 = some (.Vlong old) := by
    simp +decide [ready, X86ShiftWriteback.tableTemps, X86ShiftWriteback.tableStoreTemps, X86ShiftWriteback.tableIndexTemps,
      X86ShiftWriteback.tableLoadTemps, X86RegisterWriteRsp.temps, CC.PTree.gso, savedOld]
  have notLocal : (writerAllocation ge.genv_cenv caller).1.get X86_program_profile_bpf._native_lab_entry_input = none := by
    simpa only [CC.emptyEnv, CC.PTree.gempty] using CC.allocVariables_env_other allocation
      (show X86_program_profile_bpf._native_lab_entry_input ∉ CC.varNames X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_vars by decide +kernel)
  have helperNotLocal : (writerAllocation ge.genv_cenv caller).1.get X86_program_profile_bpf._x86_sim_inline_call_frame_values = none := by
    simpa only [CC.emptyEnv, CC.PTree.gempty] using CC.allocVariables_env_other allocation
      (show X86_program_profile_bpf._x86_sim_inline_call_frame_values ∉ CC.varNames X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_vars by decide +kernel)
  obtain ⟨trace, final, run, finalRegisters, finalFlags, finalNext, released, frame⟩ :=
    X86ReleaseReturn.from_load ge layout stackLayout valueLayout caller ready k written binding stack cells input helper
      cacheOffset cellOffset places old (value - origins.stack) symbol global notLocal helperSymbol helperGlobal helperNotLocal
      bindingSeparate cellsSeparate metadataSeparate available releaseView readyBinding readyDestination readyOld addresses origins
      (cpu.setReg .q (X86.GPR.ofIndex 4) value) _ registers flags cellsOutside flagsOutside cellsOld flagsOld
      (storageAccess.trans access) boundary
  refine ⟨trace, final, ?_, finalRegisters, finalFlags, finalNext.trans storageNext, released, ?_⟩
  · simpa only [CC.E0, CC.Eapp, List.nil_append] using star_trans storageRun.sound run
  · intro chunk block offset oldBlock notCells outside
    exact (frame chunk block offset oldBlock outside).trans (storageFrame chunk block offset (localOutside block oldBlock) notCells)

end KProgFormal.ClightRefinement.X86ReleaseStorageReturn
