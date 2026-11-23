import KProgFormal.ClightRefinement.X86LogicFlagStage

namespace KProgFormal.ClightRefinement.X86LogicByteWriteback
open X86ShiftWriteback X86RegisterView X86LogicFlagOrder X86LogicFlagStores

private theorem load_frame (before after : CC.Mem) (chunk : CC.Chunk) (block : CC.Block)
    (offset : Int)
    (contents : CC.PMap.get block after.contents = CC.PMap.get block before.contents)
    (access : CC.PMap.get block after.access = CC.PMap.get block before.access) :
    CC.Mem.load chunk after block offset = CC.Mem.load chunk before block offset := by
  unfold CC.Mem.load
  rw [CC.Mem.validAccess_congr (m1 := after) (m2 := before) (fun _ => by simp only [CC.Mem.perm, access]), contents]

/-- The original complete byte writer changes the represented native register,
retains the logical flag bytes and preserves all other caller-owned blocks.
Writable inputs derive the actual stores through the original local allocation. -/
theorem from_writer (ge : CC.CGenv) {code : BitVec 32}
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (gprLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr =
      some X86RegisterLayout.gprRecord)
    (cellLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr_cell =
      some X86RegisterLayout.cellRecord)
    (caller m : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (bindingBlock cellsBlock : CC.Block) (cellsOffset : CC.Integers.Ptrofs) (value : CC.Val)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (cells : CC.Mem.load CC.Mptr m bindingBlock 0 = some (.Vptr cellsBlock cellsOffset))
    (rsp : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + 64)) = some value)
    (word : CC.Cop.semCast value (CC.tptr CC.tvoid) CC.tlong m = some value)
    (index : Fin 16)
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint ((BitVec.ofNat 8 index.val).setWidth 32)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument .b))
    (alu : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint code))
    (widthBlock : CC.Block)
    (widthBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some widthBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv widthBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (shift : BitVec 8) (next : BitVec 64)
    (observedShift : le.get X86_program_profile_bpf.___x86_l_dst_shift = some (.Vint (shift.setWidth 32)))
    (observedValue : le.get X86_program_profile_bpf.___x86_l_result = some (.Vlong next))
    (old : BitVec 64)
    (cellCurrent : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) =
        some (.Vlong old))
    (currentTag : CC.Mem.load .Mint8unsigned m cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset +
        CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) =
          some (.Vint (0#32)))
    (ordinary : (BitVec.ofNat 8 index.val).setWidth 32 ≠ (4#32))
    (bindingSeparate : bindingBlock ≠ cellsBlock)
    (cellWritable : CC.Mem.validAccess caller CC.Mptr cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset +
        CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) .Writable = true)
    (tagWritable : CC.Mem.validAccess caller .Mint8unsigned cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset +
        CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) .Writable = true)
    (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.X86.Origins) (cpu : X86.Cpu)
    (represented : RegistersRepresent addresses origins m cellsBlock cellsOffset cpu)
    (bindingOld : bindingBlock.toNat < caller.nextblock.toNat)
    (cellsOld : cellsBlock.toNat < caller.nextblock.toNat)
    (access : m.access = (writerAllocation ge.genv_cenv caller).2.access)
    (places : X86LogicFlagOrder.Locations) (resultFlags : X86.Flags)
    (flags : X86LogicFlagMemory.FlagsRepresent m places resultFlags)
    (oldFlags : places.cf.1.toNat < caller.nextblock.toNat ∧
      places.zf.1.toNat < caller.nextblock.toNat ∧ places.sf.1.toNat < caller.nextblock.toNat ∧
      places.overflow.1.toNat < caller.nextblock.toNat ∧ places.pf.1.toNat < caller.nextblock.toNat)
    (outside : places.cf.1 ≠ cellsBlock ∧ places.zf.1 ≠ cellsBlock ∧ places.sf.1 ≠ cellsBlock ∧
      places.overflow.1 ≠ cellsBlock ∧ places.pf.1 ≠ cellsBlock)
    (scalarCode : code ≠ (0#32) ∧ code ≠ (1#32) := by first | assumption | decide +kernel) :
    ∃ final finalTemps, InternalRun ge 169
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG writer k
        (writerAllocation ge.genv_cenv caller).1 le m)
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG .Sskip k
        (writerAllocation ge.genv_cenv caller).1 finalTemps final) ∧
      RegistersRepresent addresses origins final cellsBlock cellsOffset
        ({cpu.setReg .b (X86.GPR.ofIndex index) next (decide (shift.setWidth 32 = (8#32))) with flags := resultFlags}) ∧
      final.access = m.access ∧ final.nextblock = m.nextblock ∧
      (∀ block, block.toNat < caller.nextblock.toNat → block ≠ cellsBlock →
        CC.PMap.get block final.contents = CC.PMap.get block m.contents ∧
        CC.PMap.get block final.access = CC.PMap.get block m.access) ∧
      X86LogicFlagMemory.FlagsRepresent final places resultFlags := by
  obtain ⟨final, finalTemps, run, registers, finalAccess, finalNext, otherContents⟩ :=
    byte_writer_allocated ge bindingsLayout gprLayout cellLayout caller m le k
      bindingBlock cellsBlock cellsOffset value binding cells rsp word index destination width alu
      widthBlock widthBinding shift next observedShift observedValue old cellCurrent currentTag
      ordinary bindingSeparate cellWritable tagWritable addresses origins cpu represented
      bindingOld cellsOld access scalarCode
  refine ⟨final, finalTemps, run, registers, finalAccess, finalNext, otherContents, ?_⟩
  have preserve (block : CC.Block) (offset : Int)
      (oldBlock : block.toNat < caller.nextblock.toNat) (notCells : block ≠ cellsBlock) :
      CC.Mem.load .Mint8unsigned final block offset = CC.Mem.load .Mint8unsigned m block offset :=
    load_frame m final .Mint8unsigned block offset
      (otherContents block oldBlock notCells).1 (otherContents block oldBlock notCells).2
  exact ⟨(preserve _ _ oldFlags.1 outside.1).trans flags.cf,
    (preserve _ _ oldFlags.2.1 outside.2.1).trans flags.zf,
    (preserve _ _ oldFlags.2.2.1 outside.2.2.1).trans flags.sf,
    (preserve _ _ oldFlags.2.2.2.1 outside.2.2.2.1).trans flags.overflow,
    (preserve _ _ oldFlags.2.2.2.2 outside.2.2.2.2).trans flags.pf⟩

/-- The actual logical flags stage and complete byte writer compose, deriving
all six writer inputs and its heap observations from the preceding execution. -/
theorem from_flags (ge : CC.CGenv)
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
    (m cfHeap zfHeap sfHeap ofHeap after : CC.Mem) (bindingBlock cellsBlock : CC.Block) (places : Locations)
    (value : BitVec 64) (af : Bool) (cpu : X86.Cpu) (old code : BitVec 8)
    (supported : code = (2#8) ∨ code = (3#8) ∨ code = (4#8))
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (code.setWidth 32)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument .b))
    (oldByte : CC.Mem.load .Mint8unsigned m places.cf.1 (CC.Integers.Ptrofs.unsigned places.cf.2) =
      some (.Vint (old.setWidth 32)))
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (word : le.get X86_program_profile_bpf.___x86_l_result = some (.Vlong value))
    (headers : HeaderLoads m bindingBlock places)
    (different : X86LogicFlagMemory.Distinct places)
    (separate : places.cf.1 ≠ bindingBlock ∧ places.zf.1 ≠ bindingBlock ∧
      places.sf.1 ≠ bindingBlock ∧ places.overflow.1 ≠ bindingBlock ∧ places.pf.1 ≠ bindingBlock)
    (cfStored : CC.Mem.store .Mint8unsigned m places.cf.1 (CC.Integers.Ptrofs.unsigned places.cf.2)
      (.Vint (0#32)) = some cfHeap)
    (zfStored : CC.Mem.store .Mint8unsigned cfHeap places.zf.1 (CC.Integers.Ptrofs.unsigned places.zf.2)
      (X86ShiftFlagZF.bit (X86.Value.trunc .b value)) = some zfHeap)
    (sfStored : CC.Mem.store .Mint8unsigned zfHeap places.sf.1 (CC.Integers.Ptrofs.unsigned places.sf.2)
      (signByte (X86.Value.trunc .b value) .b) = some sfHeap)
    (ofStored : CC.Mem.store .Mint8unsigned sfHeap places.overflow.1
      (CC.Integers.Ptrofs.unsigned places.overflow.2) (.Vint (0#32)) = some ofHeap)
    (pfStored : CC.Mem.store .Mint8unsigned ofHeap places.pf.1 (CC.Integers.Ptrofs.unsigned places.pf.2)
      (X86ShiftFlagPF.bit (X86.Value.trunc .b value)) = some after)
    (cellsOffset : CC.Integers.Ptrofs) (rspValue : CC.Val)
    (cells : CC.Mem.load CC.Mptr m bindingBlock 0 = some (.Vptr cellsBlock cellsOffset))
    (rsp : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + 64)) = some rspValue)
    (rspCast : CC.Cop.semCast rspValue (CC.tptr CC.tvoid) CC.tlong m = some rspValue)
    (index : Fin 16)
    (destination : le.get X86_program_profile_bpf._dst =
      some (.Vint ((BitVec.ofNat 8 index.val).setWidth 32)))
    (shift : BitVec 8)
    (observedShift : le.get X86_program_profile_bpf.___x86_l_dst_shift = some (.Vint (shift.setWidth 32)))
    (previous : BitVec 64)
    (cellCurrent : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) =
      some (.Vlong previous))
    (currentTag : CC.Mem.load .Mint8unsigned m cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) =
      some (.Vint (0#32)))
    (ordinary : (BitVec.ofNat 8 index.val).setWidth 32 ≠ (4#32))
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
      places.overflow.1 ≠ cellsBlock ∧ places.pf.1 ≠ cellsBlock) :
    ∃ final finalTemps, InternalRun ge (X86LogicFlagStage.length .b + 169)
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG X86ShiftLeftRoute.flags k
        (writerAllocation ge.genv_cenv caller).1 le m)
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG .Sskip k
        (writerAllocation ge.genv_cenv caller).1 finalTemps final) ∧
      RegistersRepresent addresses origins final cellsBlock cellsOffset
        ({cpu.setReg .b (X86.GPR.ofIndex index) value (decide (shift.setWidth 32 = (8#32))) with
          flags := X86.Flags.logic .b (X86.Value.trunc .b value) af cpu.flags}) ∧
      X86LogicFlagMemory.FlagsRepresent final places
        (X86.Flags.logic .b (X86.Value.trunc .b value) af cpu.flags) ∧
      final.access = m.access ∧ final.nextblock = m.nextblock ∧
      (∀ (chunk : CC.Chunk) (block : CC.Block) (offset : Int),
        block.toNat < caller.nextblock.toNat → block ≠ cellsBlock →
        block ≠ places.cf.1 ∧ block ≠ places.zf.1 ∧ block ≠ places.sf.1 ∧
          block ≠ places.overflow.1 ∧ block ≠ places.pf.1 →
        CC.Mem.load chunk final block offset = CC.Mem.load chunk m block offset) := by
  have flagsRun := X86LogicFlagStage.to_writer ge bindingsLayout valueLayout
    effectiveBlock applyBlock bitsBlock effectiveBinding applyBinding bitsBinding
    X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG (writerAllocation ge.genv_cenv caller).1
    le k unshadowed m cfHeap zfHeap sfHeap ofHeap after bindingBlock places
    value .b af cpu.flags old code supported operation width oldByte binding word headers
    different separate cfStored zfStored sfStored ofStored pfStored
  have inputs := X86LogicFlagStage.writer_observations le places old value .b
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
  have registers := X86LogicFlagMemory.registers m cfHeap zfHeap sfHeap ofHeap after places
    _ _ _ _ _ cfStored zfStored sfStored ofStored pfStored addresses origins cellsBlock cellsOffset
    cpu represented outsideCells
  have flagsAccess : after.access = m.access := by
    rw [CC.Mem.store_access pfStored, CC.Mem.store_access ofStored,
      CC.Mem.store_access sfStored, CC.Mem.store_access zfStored, CC.Mem.store_access cfStored]
  have flagsNext : after.nextblock = m.nextblock := by
    rw [CC.Mem.store_nextblock pfStored, CC.Mem.store_nextblock ofStored,
      CC.Mem.store_nextblock sfStored, CC.Mem.store_nextblock zfStored, CC.Mem.store_nextblock cfStored]
  have cast : CC.Cop.semCast rspValue (CC.tptr CC.tvoid) CC.tlong after = some rspValue := by
    have stable : CC.Cop.semCast rspValue (CC.tptr CC.tvoid) CC.tlong after =
        CC.Cop.semCast rspValue (CC.tptr CC.tvoid) CC.tlong m := by cases rspValue <;> rfl
    exact stable.trans rspCast
  have scalarCode : code.setWidth 32 ≠ (0#32) ∧ code.setWidth 32 ≠ (1#32) := by
    rcases supported with rfl | rfl | rfl <;> decide +kernel
  obtain ⟨final, finalTemps, writerRun, finalRegisters, finalAccess, finalNext, other, finalFlags⟩ :=
    from_writer ge bindingsLayout gprLayout cellLayout caller after
      (X86LogicFlagStage.temps le places old value .b) k
      bindingBlock cellsBlock cellsOffset rspValue (inputs.1.trans binding)
      ((frame CC.Mptr bindingBlock 0 outsideHeader).trans cells)
      ((frame CC.Mptr cellsBlock _ outsideCells).trans rsp) cast index
      (inputs.2.1.trans destination) (inputs.2.2.2.1.trans width)
      (inputs.2.2.1.trans operation) effectiveBlock effectiveBinding shift value
      (inputs.2.2.2.2.2.trans observedShift) (inputs.2.2.2.2.1.trans word) previous
      ((frame CC.Mptr cellsBlock _ outsideCells).trans cellCurrent)
      ((frame .Mint8unsigned cellsBlock _ outsideCells).trans currentTag)
      ordinary bindingSeparate cellWritable tagWritable addresses origins cpu registers
      bindingOld cellsOld (flagsAccess.trans access) places _ flagsRun.2.2 oldFlags outside scalarCode
  refine ⟨final, finalTemps, flagsRun.1.trans writerRun, finalRegisters, finalFlags,
    finalAccess.trans flagsAccess, finalNext.trans flagsNext, ?_⟩
  intro chunk block offset oldBlock notCells outsideFlags
  exact (load_frame after final chunk block offset
    (other block oldBlock notCells).1 (other block oldBlock notCells).2).trans
      (frame chunk block offset outsideFlags)

end KProgFormal.ClightRefinement.X86LogicByteWriteback
