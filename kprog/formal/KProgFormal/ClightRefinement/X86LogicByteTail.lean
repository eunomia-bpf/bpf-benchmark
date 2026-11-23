import KProgFormal.ClightRefinement.X86AluReturn
import KProgFormal.ClightRefinement.X86LogicFlagWritable

namespace KProgFormal.ClightRefinement.X86LogicByteTail
open X86ShiftWriteback X86RegisterView X86LogicFlagOrder X86LogicFlagStores

/-- Initial permissions derive every real flag store; actual flag computation,
byte writeback, loop exits and local release reach the real void return.
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
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument .b))
    (oldByte : CC.Mem.load .Mint8unsigned m places.cf.1 (CC.Integers.Ptrofs.unsigned places.cf.2) =
      some (.Vint (old.setWidth 32)))
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (word : le.get X86_program_profile_bpf.___x86_l_result = some (.Vlong value))
    (headers : HeaderLoads m bindingBlock places)
    (different : X86LogicFlagMemory.Distinct places)
    (separate : places.cf.1 ≠ bindingBlock ∧ places.zf.1 ≠ bindingBlock ∧
      places.sf.1 ≠ bindingBlock ∧ places.overflow.1 ≠ bindingBlock ∧ places.pf.1 ≠ bindingBlock)
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
      places.overflow.1 ≠ cellsBlock ∧ places.pf.1 ≠ cellsBlock)
    (permissions : X86LogicFlagWritable.Writable m places)
    (boundary : CC.isCallCont k = true) :
    ∃ final, InternalRun ge (X86LogicFlagStage.length .b + 169 + 5)
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG X86ShiftLeftRoute.flags
        (X86AluEntry.continuation k) (writerAllocation ge.genv_cenv caller).1 le m)
      (.Returnstate .Vundef k final) ∧
      RegistersRepresent addresses origins final cellsBlock cellsOffset
        ({cpu.setReg .b (X86.GPR.ofIndex index) value (decide (shift.setWidth 32 = (8#32))) with
          flags := X86.Flags.logic .b (X86.Value.trunc .b value) af cpu.flags}) ∧
      X86LogicFlagMemory.FlagsRepresent final places
        (X86.Flags.logic .b (X86.Value.trunc .b value) af cpu.flags) ∧
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
      (X86ShiftFlagZF.bit (X86.Value.trunc .b value))
      (signByte (X86.Value.trunc .b value) .b) (.Vint (0#32))
      (X86ShiftFlagPF.bit (X86.Value.trunc .b value))
  obtain ⟨written, finalTemps, body, registers, flags, bodyAccess, bodyNext, kept⟩ :=
    X86LogicByteWriteback.from_flags ge bindingsLayout valueLayout gprLayout cellLayout
      effectiveBlock applyBlock bitsBlock effectiveBinding applyBinding bitsBinding
      caller le (X86AluEntry.continuation k) unshadowed m cfHeap zfHeap sfHeap ofHeap after
      bindingBlock cellsBlock places value af cpu old code supported operation width oldByte
      binding word headers different separate cfStored zfStored sfStored ofStored pfStored
      cellsOffset rspValue cells rsp rspCast index destination shift observedShift previous
      cellCurrent currentTag ordinary bindingSeparate cellWritable tagWritable addresses origins
      represented bindingOld cellsOld access oldFlags outside
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

end KProgFormal.ClightRefinement.X86LogicByteTail
