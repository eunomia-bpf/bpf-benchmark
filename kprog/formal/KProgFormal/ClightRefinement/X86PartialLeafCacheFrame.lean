import KProgFormal.ClightRefinement.X86ReleaseStorageCacheFrame
import KProgFormal.ClightRefinement.X86RegisterWriteRspPartialStore
import KProgFormal.ClightRefinement.X86RegisterReadRspNative

namespace KProgFormal.ClightRefinement.X86PartialLeafCacheFrame
open X86RegisterView
open X86ReleaseByteCacheFrame (AboveFrame)
open X86ReleaseByteCompleteFrame (PreservingInputs)

/-- Actual add-base materialization and byte/word scalar partial stores
compose with real reverse/table writes, both signed-SP release paths and
original free/return. The same original RSP read derives preserved upper bits;
Cache-byte reads at/above the computed new raw SP survive from this genuine leaf through return; initial View/cache lifetime/cache-ghost ownership and stronger provider ABI remain explicit. -/
theorem execute (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (stackLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_stack_mem = some X86RegisterWriteRspReleaseWord.stackRecord)
    (caller memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (binding localBlock baseBlock cells stack input helper : CC.Block)
    (baseOffset cellOffset cacheOffset : CC.Integers.Ptrofs) (places : X86CallFrameComplete.Places)
    (value old : BitVec 64) (isWord : Bool) (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.X86.Origins) (cpu : X86.Cpu) (flags : X86LogicFlagOrder.Locations)
    (declared : (writerAllocation ge.genv_cenv caller).1.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (bindingRead : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint (4#32)))
    (savedOld : le.get X86_program_profile_bpf.___x86_write_old_sp__5 = some (.Vlong old))
    (current : CC.Mem.load CC.Mptr memory localBlock 0 = some (.Vlong old))
    (scalarTag : le.get X86_program_profile_bpf.___x86_wr_cell_tag__2 = some (.Vint (0#32)))
    (low : isWord = false → le.get X86_program_profile_bpf.___x86_wr_shift__2 = some (.Vint (0#32)))
    (observed : le.get X86_program_profile_bpf.___x86_wr_next__2 = some (.Vlong value))
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
    (available : PreservingInputs ge binding stack cacheOffset
      (X86.Value.writeView (if isWord then .w else .b) (old + origins.stack) value - origins.stack))
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
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG (X86RegisterWriteRspPartial.leaf isWord)
        (.Kseq X86ShiftWriteback.storageTail (X86ShiftWriteback.loadCont (X86AluEntry.continuation k)))
        (writerAllocation ge.genv_cenv caller).1 le memory) trace
      (.Returnstate .Vundef k final) ∧
    RegistersRepresent addresses origins final cells cellOffset (cpu.setReg (if isWord then .w else .b) (X86.GPR.ofIndex 4) value) ∧
    X86LogicFlagMemory.FlagsRepresent final flags cpu.flags ∧ final.nextblock = memory.nextblock ∧
    (∀ row ∈ CC.blocksOfEnv ge.genv_cenv (writerAllocation ge.genv_cenv caller).1,
      ∀ offset, row.2.1 ≤ offset → offset < row.2.2 →
      ∀ kind permission, CC.Mem.perm final row.1 offset kind permission = false) ∧
    (∀ chunk block offset, block.toNat < caller.nextblock.toNat → block ≠ cells →
      X86ReleaseReturn.ObserverOutside stack places block →
      CC.Mem.load chunk final block offset = CC.Mem.load chunk memory block offset) ∧
    AboveFrame stack cacheOffset (X86.Value.writeView (if isWord then .w else .b) (old + origins.stack) value - origins.stack) memory final := by
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
  let result := X86.Value.writeView (if isWord then .w else .b) (old + origins.stack) value
  obtain ⟨middle, firstRun, currentWord, sameAccess, sameNext, frame⟩ :=
    X86RegisterWriteRspPartialStore.execute isWord ge layout valueLayout
      X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG (writerAllocation ge.genv_cenv caller).1 le
      (.Kseq X86ShiftWriteback.storageTail (X86ShiftWriteback.loadCont (X86AluEntry.continuation k)))
      memory binding localBlock baseBlock baseOffset old origins.stack value declared bindingRead destination current header native
      localPermission scalarTag observed low
  let materialized := X86RegisterWriteRspPartial.temps isWord le baseBlock baseOffset old origins.stack
  let ready := X86RegisterWriteRspScalarSuffix.temps isWord materialized value
  have readyBinding : ready.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0) := by
    cases isWord <;> simp +decide [ready, materialized, X86RegisterWriteRspScalarSuffix.temps,
      X86WordStorage.temps, X86WordStorage.laneTemps, X86ShiftWriteback.byteTemps, X86ShiftWriteback.byteLaneTemps,
      X86RegisterWriteRspPartial.temps, X86RegisterWriteRspWord.temps, X86RegisterWriteRspByte.temps, CC.PTree.gso, bindingRead]
  have readyDestination : ready.get X86_program_profile_bpf._dst = some (.Vint (4#32)) := by
    cases isWord <;> simp +decide [ready, materialized, X86RegisterWriteRspScalarSuffix.temps,
      X86WordStorage.temps, X86WordStorage.laneTemps, X86ShiftWriteback.byteTemps, X86ShiftWriteback.byteLaneTemps,
      X86RegisterWriteRspPartial.temps, X86RegisterWriteRspWord.temps, X86RegisterWriteRspByte.temps, CC.PTree.gso, destination]
  have readyOld : ready.get X86_program_profile_bpf.___x86_write_old_sp__5 = some (.Vlong old) := by
    cases isWord <;> simp +decide [ready, materialized, X86RegisterWriteRspScalarSuffix.temps,
      X86WordStorage.temps, X86WordStorage.laneTemps, X86ShiftWriteback.byteTemps, X86ShiftWriteback.byteLaneTemps,
      X86RegisterWriteRspPartial.temps, X86RegisterWriteRspWord.temps, X86RegisterWriteRspByte.temps, CC.PTree.gso, savedOld]
  have readyTag : ready.get X86_program_profile_bpf.___x86_wr_cell_tag__2 = some (.Vint (0#32)) := by
    cases isWord <;> simp only [ready, X86RegisterWriteRspScalarSuffix.temps,
      X86WordStorage.temps, X86ShiftWriteback.byteTemps, CC.PTree.gss, Bool.false_eq_true, ite_true, ite_false]
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
  have middleRegisters : RegistersRepresent addresses origins middle cells cellOffset cpu := by
    intro index
    obtain ⟨v, raw, tag, wordRead, tagRead, valueRep, native⟩ := represented index
    exact ⟨v, raw, tag, (frame CC.Mptr cells _ cellsLocal).trans wordRead,
      (frame .Mint8unsigned cells _ cellsLocal).trans tagRead, valueRep, native⟩
  have middleFlags : X86LogicFlagMemory.FlagsRepresent middle flags cpu.flags :=
    ⟨(frame _ _ _ (localOutside _ flagsOld.1)).trans flagValues.cf,
      (frame _ _ _ (localOutside _ flagsOld.2.1)).trans flagValues.zf,
      (frame _ _ _ (localOutside _ flagsOld.2.2.1)).trans flagValues.sf,
      (frame _ _ _ (localOutside _ flagsOld.2.2.2.1)).trans flagValues.overflow,
      (frame _ _ _ (localOutside _ flagsOld.2.2.2.2)).trans flagValues.pf⟩
  obtain ⟨trace, final, run, finalRegisters, finalFlags, finalNext, released, finalFrame, aboveFrame⟩ :=
    X86ReleaseStorageCacheFrame.execute ge layout valueLayout stackLayout caller middle ready k binding localBlock baseBlock cells stack input helper
      baseOffset cellOffset cacheOffset places result old addresses origins cpu flags
      declared readyBinding readyDestination readyOld currentWord ((frame CC.Mptr binding 112 bindingLocal).trans header)
      ((frame .Mint64 baseBlock _ (localOutside _ baseOld)).trans native) bindingCells readyTag middleRegisters middleFlags middleView
      symbol global helperSymbol helperGlobal bindingSeparate cellsSeparate cacheOutside metadataSeparate available cellsOutside flagsOutside flagsNotCells
      cacheOld bindingOld cellsOld flagsOld (sameAccess.trans access) ((rights _ _ _ _).trans wordPermission)
      ((rights _ _ _ _).trans tagPermission) boundary
  have nativeOld := X86RegisterReadRspNative.native_word addresses origins memory cells cellOffset cpu old represented view.rawSp
  have writes : cpu.setReg .q (X86.GPR.ofIndex 4) result =
      cpu.setReg (if isWord then .w else .b) (X86.GPR.ofIndex 4) value := by
    cases isWord <;> simp [result, X86.Cpu.setReg, X86.Value.writeView, nativeOld]
  refine ⟨trace, final, ?_, ?_, finalFlags, finalNext.trans sameNext, released, ?_, ?_⟩
  · simpa only [CC.E0, CC.Eapp, List.nil_append] using star_trans firstRun.sound run
  · simpa only [writes] using finalRegisters
  · intro chunk block offset oldBlock notCells outside
    exact (finalFrame chunk block offset oldBlock notCells outside).trans (frame chunk block offset (localOutside block oldBlock))
  · intro readSlot readLane above
    exact (aboveFrame readSlot readLane above).trans (frame .Mint8unsigned stack _ (localOutside stack cacheOld))

end KProgFormal.ClightRefinement.X86PartialLeafCacheFrame
