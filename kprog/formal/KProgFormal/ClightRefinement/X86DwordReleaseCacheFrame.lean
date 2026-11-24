import KProgFormal.ClightRefinement.X86FullWidthReleaseCacheFrame
import KProgFormal.ClightRefinement.X86DwordRspSetup

namespace KProgFormal.ClightRefinement.X86DwordReleaseCacheFrame
open X86RegisterView
open X86ReleaseByteCacheFrame (AboveFrame)
open X86ReleaseByteCompleteFrame (PreservingInputs)

/-- The whole original dword RSP writer, with arbitrary initial tag,
executes actual selectors, copy/zero-extending overwrite and both signed-SP
release paths through real free/return. Allocation derives local rights and
scope; initial View/cache lifetime/cache-ghost ownership/stronger provider ABI remain explicit. Actual cache-byte reads at or above new raw SP survive from whole writer entry through return. -/
theorem execute (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (stackLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_stack_mem = some X86RegisterWriteRspReleaseWord.stackRecord)
    (caller memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (binding baseBlock cells stack input helper widthBlock : CC.Block)
    (baseOffset cellOffset cacheOffset : CC.Integers.Ptrofs) (places : X86CallFrameComplete.Places)
    (value old : BitVec 64) (shift : BitVec 8) (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.X86.Origins) (cpu : X86.Cpu) (flags : X86LogicFlagOrder.Locations)
    (bindingRead : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint (4#32)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument .d))
    (code : BitVec 32) (alu : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint code))
    (scalarCode : code ≠ (0#32) ∧ code ≠ (1#32))
    (observedShift : le.get X86_program_profile_bpf.___x86_l_dst_shift = some (.Vint (shift.setWidth 32)))
    (observedValue : le.get X86_program_profile_bpf.___x86_l_result = some (.Vlong value))
    (widthBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some widthBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv widthBlock = some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (header : CC.Mem.load CC.Mptr memory binding 112 = some (.Vptr baseBlock baseOffset))
    (native : CC.Mem.load .Mint64 memory baseBlock (CC.Integers.Ptrofs.unsigned baseOffset) = some (.Vlong origins.stack))
    (bindingCells : binding ≠ cells)
    (represented : RegistersRepresent addresses origins memory cells cellOffset cpu)
    (flagValues : X86LogicFlagMemory.FlagsRepresent memory flags cpu.flags)
    (view : X86ReleaseOuterComplete.View memory binding stack cells cacheOffset cellOffset places old)
    (symbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._native_lab_entry_input = some input)
    (global : CC.Genv.findFunctPtr ge.genv_genv input = some X86RegisterWriteRspReleaseWord.inputFunction)
    (helperSymbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_call_frame_values = some helper)
    (helperGlobal : CC.Genv.findFunctPtr ge.genv_genv helper = some (.Internal X86CallFrameEntry.handler))
    (bindingSeparate : binding ≠ stack) (cellsSeparate : cells ≠ stack)
    (cacheOutside : X86CallFrameComplete.Outside places stack)
    (metadataSeparate : X86CallFrameComplete.Separated binding places)
    (available : PreservingInputs ge binding stack cacheOffset (X86.Value.trunc .d value - origins.stack))
    (cellsOutside : X86ReleaseReturn.ObserverOutside stack places cells)
    (flagsOutside : X86ReleaseReturn.FlagsOutside stack places flags)
    (flagsNotCells : flags.cf.1 ≠ cells ∧ flags.zf.1 ≠ cells ∧ flags.sf.1 ≠ cells ∧
      flags.overflow.1 ≠ cells ∧ flags.pf.1 ≠ cells)
    (baseOld : baseBlock.toNat < caller.nextblock.toNat)
    (cacheOld : stack.toNat < caller.nextblock.toNat)
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
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG X86ShiftWriteback.writer (X86AluEntry.continuation k)
        (writerAllocation ge.genv_cenv caller).1 le memory) trace
      (.Returnstate .Vundef k final) ∧
    RegistersRepresent addresses origins final cells cellOffset (cpu.setReg .d (X86.GPR.ofIndex 4) value) ∧
    X86LogicFlagMemory.FlagsRepresent final flags cpu.flags ∧ final.nextblock = memory.nextblock ∧
    (∀ row ∈ CC.blocksOfEnv ge.genv_cenv (writerAllocation ge.genv_cenv caller).1,
      ∀ offset, row.2.1 ≤ offset → offset < row.2.2 →
      ∀ kind permission, CC.Mem.perm final row.1 offset kind permission = false) ∧
    (∀ chunk block offset, block.toNat < caller.nextblock.toNat → block ≠ cells →
      X86ReleaseReturn.ObserverOutside stack places block →
      CC.Mem.load chunk final block offset = CC.Mem.load chunk memory block offset) ∧
    AboveFrame stack cacheOffset (X86.Value.trunc .d value - origins.stack) memory final := by
  have allocation : CC.AllocVariables ge.genv_cenv CC.emptyEnv caller
      X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_vars
      (writerAllocation ge.genv_cenv caller).1 (writerAllocation ge.genv_cenv caller).2 :=
    CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (writerAllocation ge.genv_cenv caller)).symm
  obtain ⟨localBlock, declared, fresh, owned, right⟩ := writer_local_storage ge.genv_cenv layout.gpr caller
  have localOutside (block : CC.Block) (oldBlock : block.toNat < caller.nextblock.toNat) : block ≠ localBlock := by
    intro same
    have encoded := congrArg CC.Positive.toNat same
    omega
  have localPermission := writer_local_writable ge.genv_cenv layout.gpr caller memory localBlock declared access
  have bindingLocal := localOutside binding bindingOld
  have cellsLocal := localOutside cells cellsOld
  have widthNotLocal : (writerAllocation ge.genv_cenv caller).1.get X86_program_profile_bpf._x86_width_effective = none := by
    simpa only [CC.emptyEnv, CC.PTree.gempty] using CC.allocVariables_env_other allocation
      (show X86_program_profile_bpf._x86_width_effective ∉ CC.varNames X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_vars by decide +kernel)
  obtain ⟨middle, ready, firstRun, copied, readyRegisters, observations⟩ :=
    X86DwordRspSetup.to_storage ge layout X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG
      (writerAllocation ge.genv_cenv caller).1 le (X86AluEntry.continuation k) memory localBlock binding cells cellOffset value old shift
      declared destination width code alu scalarCode observedShift observedValue widthBlock widthBinding widthNotLocal bindingRead
      view.table ⟨bindingLocal, cellsLocal⟩ addresses origins cpu represented view.rawSp localPermission
  have sameAccess := CC.Mem.store_access copied
  have sameNext := CC.Mem.store_nextblock copied
  have frame (chunk : CC.Chunk) (block : CC.Block) (offset : Int) (different : block ≠ localBlock) :=
    CC.Mem.load_store_other copied chunk block offset (.inl different)
  have rights (chunk : CC.Chunk) (block : CC.Block) (offset : Int) (permission : CC.Permission) :=
    X86ReleaseProvider.access_rights memory middle sameAccess chunk block offset permission
  have middleView : X86ReleaseOuterComplete.View middle binding stack cells cacheOffset cellOffset places old := by
    refine ⟨⟨(frame CC.Mptr binding 8 bindingLocal).trans view.cache.header, ?_, ?_⟩,
      ⟨?_, ?_, ?_, ?_⟩, (frame CC.Mptr binding 0 bindingLocal).trans view.table,
      (frame CC.Mptr cells _ cellsLocal).trans view.rawSp⟩
    · intro slot lane
      exact (rights _ _ _ _).trans (view.cache.bytes slot lane)
    · intro slot
      exact (rights _ _ _ _).trans (view.cache.words slot)
    · intro slot
      exact (frame CC.Mptr binding _ bindingLocal).trans (view.metadata.tags slot)
    · intro slot
      exact (frame CC.Mptr binding _ bindingLocal).trans (view.metadata.pointers slot)
    · intro slot
      exact (rights _ _ _ _).trans (view.metadata.tag_rights slot)
    · intro slot
      exact (rights _ _ _ _).trans (view.metadata.pointer_rights slot)
  have middleFlags : X86LogicFlagMemory.FlagsRepresent middle flags cpu.flags :=
    ⟨(frame _ _ _ (localOutside _ flagsOld.1)).trans flagValues.cf,
      (frame _ _ _ (localOutside _ flagsOld.2.1)).trans flagValues.zf,
      (frame _ _ _ (localOutside _ flagsOld.2.2.1)).trans flagValues.sf,
      (frame _ _ _ (localOutside _ flagsOld.2.2.2.1)).trans flagValues.overflow,
      (frame _ _ _ (localOutside _ flagsOld.2.2.2.2)).trans flagValues.pf⟩
  obtain ⟨trace, final, run, finalRegisters, finalFlags, finalNext, released, finalFrame, aboveFrame⟩ :=
    X86FullWidthReleaseCacheFrame.execute ge layout valueLayout stackLayout caller middle ready k binding localBlock baseBlock cells stack input helper
      baseOffset cellOffset cacheOffset places value old true addresses origins cpu flags declared observations.binding observations.destination
      observations.old observations.width observations.value ((frame CC.Mptr binding 112 bindingLocal).trans header)
      ((frame .Mint64 baseBlock _ (localOutside _ baseOld)).trans native) bindingCells readyRegisters middleFlags middleView
      symbol global helperSymbol helperGlobal bindingSeparate cellsSeparate cacheOutside metadataSeparate available cellsOutside flagsOutside flagsNotCells
      baseOld cacheOld bindingOld cellsOld flagsOld (sameAccess.trans access) ((rights _ _ _ _).trans wordPermission)
      ((rights _ _ _ _).trans tagPermission) boundary
  refine ⟨trace, final, ?_, finalRegisters, finalFlags, finalNext.trans sameNext, released, ?_, ?_⟩
  · simpa only [CC.E0, CC.Eapp, List.nil_append] using star_trans firstRun.sound run
  · intro chunk block offset oldBlock notCells outside
    exact (finalFrame chunk block offset oldBlock notCells outside).trans (frame chunk block offset (localOutside block oldBlock))
  · intro readSlot readLane above
    exact (aboveFrame readSlot readLane above).trans (frame .Mint8unsigned stack _ (localOutside stack cacheOld))

end KProgFormal.ClightRefinement.X86DwordReleaseCacheFrame
