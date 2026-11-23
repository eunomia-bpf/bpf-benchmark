import KProgFormal.ClightRefinement.X86LogicFlagStage

namespace KProgFormal.ClightRefinement.X86LogicByteWriteback
open X86ShiftWriteback X86RegisterView

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

end KProgFormal.ClightRefinement.X86LogicByteWriteback
