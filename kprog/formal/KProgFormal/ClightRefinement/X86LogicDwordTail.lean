import KProgFormal.ClightRefinement.X86AluReturn
import KProgFormal.ClightRefinement.X86DwordWriteback
import KProgFormal.ClightRefinement.X86LogicFlagWritable

namespace KProgFormal.ClightRefinement.X86LogicDwordTail
open X86ShiftWriteback X86RegisterView X86LogicFlagOrder X86LogicFlagStores

/-- Initial permissions derive every real flag store; actual flag computation,
dword writeback, loop exits and local release reach the real void return.
The final native GPR/flag views, caller loads and revoked local ranges are explicit. -/
theorem execute (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (gprLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr =
      some X86RegisterLayout.gprRecord)
    (cellLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr_cell =
      some X86RegisterLayout.cellRecord)
    (effectiveBlock applyBlock bitsBlock : CC.Block)
    (effectiveBinding :
      CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some effectiveBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv effectiveBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (applyBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_apply_width = some applyBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv applyBlock =
        some (.Internal X86_program_profile_bpf.f_x86_apply_width))
    (bitsBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_bits = some bitsBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv bitsBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_bits))
    (caller : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (unshadowed : (writerAllocation ge.genv_cenv caller).1.get X86_program_profile_bpf._x86_width_effective = none ∧
      (writerAllocation ge.genv_cenv caller).1.get X86_program_profile_bpf._x86_apply_width = none ∧
      (writerAllocation ge.genv_cenv caller).1.get X86_program_profile_bpf._x86_width_bits = none)
    (m : CC.Mem) (bindingBlock cellsBlock : CC.Block) (places : Locations)
    (value : BitVec 64) (af : Bool) (cpu : X86.Cpu) (old code : BitVec 8)
    (supported : code = (2#8) ∨ code = (3#8) ∨ code = (4#8))
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (code.setWidth 32)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument .d))
    (oldByte : CC.Mem.load .Mint8unsigned m places.cf.1 (CC.Integers.Ptrofs.unsigned places.cf.2) =
      some (.Vint (old.setWidth 32)))
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (word : le.get X86_program_profile_bpf.___x86_l_result = some (.Vlong value))
    (headers : HeaderLoads m bindingBlock places)
    (different : X86LogicFlagMemory.Distinct places)
    (separate : places.cf.1 ≠ bindingBlock ∧ places.zf.1 ≠ bindingBlock ∧
      places.sf.1 ≠ bindingBlock ∧ places.overflow.1 ≠ bindingBlock ∧ places.pf.1 ≠ bindingBlock)
    (cellsOffset : CC.Integers.Ptrofs)
    (cells : CC.Mem.load CC.Mptr m bindingBlock 0 = some (.Vptr cellsBlock cellsOffset))
    (index : Fin 16)
    (destination : le.get X86_program_profile_bpf._dst =
      some (.Vint ((BitVec.ofNat 8 index.val).setWidth 32)))
    (shift : BitVec 8)
    (observedShift : le.get X86_program_profile_bpf.___x86_l_dst_shift = some (.Vint (shift.setWidth 32)))
    (ordinary : index ≠ 4)
    (bindingSeparate : bindingBlock ≠ cellsBlock)
    (cellWritable : CC.Mem.validAccess caller CC.Mptr cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int))))
      .Writable = true)
    (tagWritable : CC.Mem.validAccess caller .Mint8unsigned cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8))
      .Writable = true)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (represented : RegistersRepresent addresses origins m cellsBlock cellsOffset cpu)
    (bindingOld : bindingBlock.toNat < caller.nextblock.toNat)
    (cellsOld : cellsBlock.toNat < caller.nextblock.toNat)
    (access : m.access = (writerAllocation ge.genv_cenv caller).2.access)
    (oldFlags : places.cf.1.toNat < caller.nextblock.toNat ∧
      places.zf.1.toNat < caller.nextblock.toNat ∧ places.sf.1.toNat < caller.nextblock.toNat ∧
      places.overflow.1.toNat < caller.nextblock.toNat ∧ places.pf.1.toNat < caller.nextblock.toNat)
    (outside : places.cf.1 ≠ cellsBlock ∧ places.zf.1 ≠ cellsBlock ∧ places.sf.1 ≠ cellsBlock ∧
      places.overflow.1 ≠ cellsBlock ∧ places.pf.1 ≠ cellsBlock)
    (permissions : X86LogicFlagWritable.Writable m places)
    (boundary : CC.isCallCont k = true) :
    ∃ final, InternalRun ge (X86LogicFlagStage.length .d + 197 + 5)
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG X86ShiftLeftRoute.flags
        (X86AluEntry.continuation k) (writerAllocation ge.genv_cenv caller).1 le m)
      (.Returnstate .Vundef k final) ∧
      RegistersRepresent addresses origins final cellsBlock cellsOffset
        ({cpu.setReg .d (X86.GPR.ofIndex index) value with
          flags := X86.Flags.logic .d (X86.Value.trunc .d value) af cpu.flags}) ∧
      X86LogicFlagMemory.FlagsRepresent final places
        (X86.Flags.logic .d (X86.Value.trunc .d value) af cpu.flags) ∧
      final.nextblock = m.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv ge.genv_cenv (writerAllocation ge.genv_cenv caller).1,
        ∀ offset, row.2.1 ≤ offset → offset < row.2.2 →
        ∀ kind permission, CC.Mem.perm final row.1 offset kind permission = false) ∧
      (∀ (chunk : CC.Chunk) (block : CC.Block) (offset : Int),
        block.toNat < caller.nextblock.toNat → block ≠ cellsBlock →
        block ≠ places.cf.1 ∧ block ≠ places.zf.1 ∧ block ≠ places.sf.1 ∧
          block ≠ places.overflow.1 ∧ block ≠ places.pf.1 →
        CC.Mem.load chunk final block offset = CC.Mem.load chunk m block offset) := by
  obtain ⟨cfHeap, zfHeap, sfHeap, ofHeap, after, cfStored, zfStored, sfStored, ofStored, pfStored⟩ :=
    X86LogicFlagWritable.stores m places permissions (.Vint (0#32))
      (X86ShiftFlagZF.bit (X86.Value.trunc .d value))
      (signByte (X86.Value.trunc .d value) .d) (.Vint (0#32))
      (X86ShiftFlagPF.bit (X86.Value.trunc .d value))
  have flagsRun := X86LogicFlagStage.to_writer ge bindingsLayout valueLayout
    effectiveBlock applyBlock bitsBlock effectiveBinding applyBinding bitsBinding
    X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG (writerAllocation ge.genv_cenv caller).1
    le (X86AluEntry.continuation k) unshadowed m cfHeap zfHeap sfHeap ofHeap after bindingBlock places
    value .d af cpu.flags old code supported operation width oldByte binding word headers
    different separate cfStored zfStored sfStored ofStored pfStored
  have inputs := X86LogicFlagStage.writer_observations le places old value .d
  have frame := X86LogicFlagMemory.frame m cfHeap zfHeap sfHeap ofHeap after places
    _ _ _ _ _ cfStored zfStored sfStored ofStored pfStored
  have outsideCells : cellsBlock ≠ places.cf.1 ∧ cellsBlock ≠ places.zf.1 ∧
      cellsBlock ≠ places.sf.1 ∧ cellsBlock ≠ places.overflow.1 ∧ cellsBlock ≠ places.pf.1 :=
    ⟨outside.1.symm, outside.2.1.symm, outside.2.2.1.symm,
      outside.2.2.2.1.symm, outside.2.2.2.2.symm⟩
  have outsideHeader : bindingBlock ≠ places.cf.1 ∧ bindingBlock ≠ places.zf.1 ∧
      bindingBlock ≠ places.sf.1 ∧ bindingBlock ≠ places.overflow.1 ∧ bindingBlock ≠ places.pf.1 :=
    ⟨separate.1.symm, separate.2.1.symm, separate.2.2.1.symm,
      separate.2.2.2.1.symm, separate.2.2.2.2.symm⟩
  have afterRegisters := X86LogicFlagMemory.registers m cfHeap zfHeap sfHeap ofHeap after places
    _ _ _ _ _ cfStored zfStored sfStored ofStored pfStored addresses origins cellsBlock cellsOffset
    cpu represented outsideCells
  have flagsAccess : after.access = m.access := by
    rw [CC.Mem.store_access pfStored, CC.Mem.store_access ofStored,
      CC.Mem.store_access sfStored, CC.Mem.store_access zfStored, CC.Mem.store_access cfStored]
  have flagsNext : after.nextblock = m.nextblock := by
    rw [CC.Mem.store_nextblock pfStored, CC.Mem.store_nextblock ofStored,
      CC.Mem.store_nextblock sfStored, CC.Mem.store_nextblock zfStored, CC.Mem.store_nextblock cfStored]
  have scalarCode : code.setWidth 32 ≠ (0#32) ∧ code.setWidth 32 ≠ (1#32) := by
    rcases supported with rfl | rfl | rfl <;> decide +kernel
  let layout : X86RegisterReadValue.Layout ge := ⟨bindingsLayout, gprLayout, cellLayout⟩
  obtain ⟨written, finalTemps, writerRun, registers, writerAccess, writerNext, writerFrame⟩ :=
    X86DwordWriteback.allocated ge layout caller after (X86LogicFlagStage.temps le places old value .d)
      (X86AluEntry.continuation k) bindingBlock cellsBlock cellsOffset index value shift
      (inputs.2.1.trans destination) (inputs.2.2.2.1.trans width) (code.setWidth 32)
      (inputs.2.2.1.trans operation) scalarCode (inputs.2.2.2.2.2.trans observedShift)
      (inputs.2.2.2.2.1.trans word) effectiveBlock effectiveBinding ordinary (inputs.1.trans binding)
      ((frame CC.Mptr bindingBlock 0 outsideHeader).trans cells) bindingSeparate addresses origins cpu
      afterRegisters bindingOld cellsOld (flagsAccess.trans access) cellWritable tagWritable
  have flags : X86LogicFlagMemory.FlagsRepresent written places
      (X86.Flags.logic .d (X86.Value.trunc .d value) af cpu.flags) :=
    ⟨(writerFrame _ _ _ oldFlags.1 outside.1).trans flagsRun.2.2.cf,
      (writerFrame _ _ _ oldFlags.2.1 outside.2.1).trans flagsRun.2.2.zf,
      (writerFrame _ _ _ oldFlags.2.2.1 outside.2.2.1).trans flagsRun.2.2.sf,
      (writerFrame _ _ _ oldFlags.2.2.2.1 outside.2.2.2.1).trans flagsRun.2.2.overflow,
      (writerFrame _ _ _ oldFlags.2.2.2.2 outside.2.2.2.2).trans flagsRun.2.2.pf⟩
  have body := flagsRun.1.trans writerRun
  have bodyAccess := writerAccess.trans flagsAccess
  have bodyNext := writerNext.trans flagsNext
  have kept (chunk : CC.Chunk) (block : CC.Block) (offset : Int)
      (oldBlock : block.toNat < caller.nextblock.toNat) (notCells : block ≠ cellsBlock)
      (outsideFlags : block ≠ places.cf.1 ∧ block ≠ places.zf.1 ∧ block ≠ places.sf.1 ∧
        block ≠ places.overflow.1 ∧ block ≠ places.pf.1) :
      CC.Mem.load chunk written block offset = CC.Mem.load chunk m block offset :=
    (writerFrame chunk block offset oldBlock notCells).trans (frame chunk block offset outsideFlags)
  obtain ⟨final, returned, callerFrame, contents, next, released⟩ :=
    X86AluReturn.finish ge caller written finalTemps k boundary (bodyAccess.trans access)
  have finalRegisters := X86AluReturn.registers callerFrame addresses origins cellsBlock cellsOffset
    _ cellsOld registers
  have finalFlags := X86AluReturn.flags callerFrame places _ oldFlags flags
  refine ⟨final, body.trans returned, finalRegisters, finalFlags,
    next.trans bodyNext, released, ?_⟩
  intro chunk block offset oldBlock notCells outsideFlags
  exact (callerFrame.load chunk block offset oldBlock).trans
    (kept chunk block offset oldBlock notCells outsideFlags)

end KProgFormal.ClightRefinement.X86LogicDwordTail
