import KProgFormal.ClightRefinement.X86AluXorShortcutInputs
import KProgFormal.ClightRefinement.X86LogicByteTail

namespace KProgFormal.ClightRefinement.X86AluXorShortcutByteCall
open X86RegisterView X86LogicFlagOrder

private theorem ordinary_register : ∀ index : Fin 16, index ≠ 4 →
    (BitVec.ofNat 8 index.val).setWidth 32 ≠ (4#32) := by decide +kernel

private theorem unshadowed (ge : CC.CGenv) (caller : CC.Mem) (id : CC.Ident)
    (other : id ∉ CC.varNames X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_vars) :
    (writerAllocation ge.genv_cenv caller).1.get id = none := by
  have allocated := CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (writerAllocation ge.genv_cenv caller)).symm
  simpa only [CC.emptyEnv, CC.PTree.gempty] using CC.allocVariables_env_other allocated other

/-- Genuine matched scalar XOR byte-call entry, zero shortcut, numerical helper,
flags, register writeback and local release compose through the actual void
return. All intermediate source observations and store/free successes are derived. -/
theorem execute (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (caller : CC.Mem) (k : CC.Cont) (op imm : CC.Val) (reg : Fin 16)
    (flags width : BitVec 8) (aux : BitVec 32)
    (previous : BitVec 64) (widthBlock aluBlock bindingBlock cellsBlock : CC.Block)
    (cellsOffset : CC.Integers.Ptrofs)
    (oldBinding : bindingBlock.toNat < caller.nextblock.toNat)
    (oldCells : cellsBlock.toNat < caller.nextblock.toNat)
    (xorCode : (aux.setWidth 8).setWidth 32 = (2#32))
    (sameLane : (aux >>> 16).setWidth 8 = (aux >>> 8).setWidth 8)
    (ordinaryDst : reg ≠ 4)
    (effective : X86Width.result flags = X86ShiftLeft.argument .b)
    (widthHelper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective =
        some widthBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv widthBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (aluHelper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_alu_result =
        some aluBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv aluBlock =
        some (.Internal X86_program_profile_bpf.f_x86_alu_result))
    (cells : CC.Mem.load CC.Mptr caller bindingBlock (CC.Integers.Ptrofs.unsigned (0 : CC.Integers.Ptrofs)) =
      some (.Vptr cellsBlock cellsOffset))
    (leftRead : CC.Mem.load CC.Mptr caller cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (reg.val : Int)))) =
        some (.Vlong previous))
    (leftTag : CC.Mem.load .Mint8unsigned caller cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * (reg.val : Int))) + 8)) =
        some (X86Width.argument (0#8)))
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (applyBlock bitsBlock : CC.Block)
    (applyBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_apply_width = some applyBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv applyBlock = some (.Internal X86_program_profile_bpf.f_x86_apply_width))
    (bitsBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_bits = some bitsBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv bitsBlock = some (.Internal X86_program_profile_bpf.f_x86_width_bits))
    (places : Locations) (headers : HeaderLoads caller bindingBlock places)
    (differentFlags : X86LogicFlagMemory.Distinct places)
    (oldFlags : places.cf.1.toNat < caller.nextblock.toNat ∧ places.zf.1.toNat < caller.nextblock.toNat ∧
      places.sf.1.toNat < caller.nextblock.toNat ∧ places.overflow.1.toNat < caller.nextblock.toNat ∧
      places.pf.1.toNat < caller.nextblock.toNat)
    (separate : places.cf.1 ≠ bindingBlock ∧ places.zf.1 ≠ bindingBlock ∧ places.sf.1 ≠ bindingBlock ∧
      places.overflow.1 ≠ bindingBlock ∧ places.pf.1 ≠ bindingBlock)
    (outside : places.cf.1 ≠ cellsBlock ∧ places.zf.1 ≠ cellsBlock ∧ places.sf.1 ≠ cellsBlock ∧
      places.overflow.1 ≠ cellsBlock ∧ places.pf.1 ≠ cellsBlock)
    (bindingSeparate : bindingBlock ≠ cellsBlock)
    (permissions : X86LogicFlagWritable.Writable caller places)
    (oldCf : BitVec 8)
    (oldByte : CC.Mem.load .Mint8unsigned caller places.cf.1 (CC.Integers.Ptrofs.unsigned places.cf.2) =
      some (.Vint (oldCf.setWidth 32)))
    (rspValue : CC.Val)
    (rsp : CC.Mem.load CC.Mptr caller cellsBlock (CC.Integers.Ptrofs.unsigned (cellsOffset + 64)) = some rspValue)
    (rspCast : CC.Cop.semCast rspValue (CC.tptr CC.tvoid) CC.tlong caller = some rspValue)
    (cellWritable : CC.Mem.validAccess caller CC.Mptr cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (reg.val : Int)))) .Writable = true)
    (tagWritable : CC.Mem.validAccess caller .Mint8unsigned cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * (reg.val : Int))) + 8))
      .Writable = true)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (cpu : X86.Cpu) (af : Bool)
    (represented : RegistersRepresent addresses origins caller cellsBlock cellsOffset cpu)
    (boundary : CC.isCallCont k = true) :
    let value := (0#64)
    ∃ final, InternalRun ge (77 +
      (X86LogicFlagStage.length .b + 169 + 5))
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG)
        [.Vptr bindingBlock 0, op, X86Width.argument (X86RegisterReadValue.registerByte reg),
          X86Width.argument (X86RegisterReadValue.registerByte reg), X86Width.argument flags,
          .Vint aux, imm, X86Width.argument width] k caller)
      (.Returnstate .Vundef k final) ∧
      RegistersRepresent addresses origins final cellsBlock cellsOffset
        ({cpu.setReg .b (X86.GPR.ofIndex reg) value
          (decide (((aux >>> 8).setWidth 8).setWidth 32 = (8#32))) with
            flags := X86.Flags.logic .b (X86.Value.trunc .b value) af cpu.flags}) ∧
      X86LogicFlagMemory.FlagsRepresent final places (X86.Flags.logic .b (X86.Value.trunc .b value) af cpu.flags) ∧
      final.nextblock = (writerAllocation ge.genv_cenv caller).2.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv ge.genv_cenv (writerAllocation ge.genv_cenv caller).1,
        ∀ offset, row.2.1 ≤ offset → offset < row.2.2 →
        ∀ kind permission, CC.Mem.perm final row.1 offset kind permission = false) ∧
      (∀ (chunk : CC.Chunk) (block : CC.Block) (offset : Int),
        block.toNat < caller.nextblock.toNat → block ≠ cellsBlock →
        block ≠ places.cf.1 ∧ block ≠ places.zf.1 ∧ block ≠ places.sf.1 ∧
          block ≠ places.overflow.1 ∧ block ≠ places.pf.1 →
        CC.Mem.load chunk final block offset = CC.Mem.load chunk caller block offset) := by
  dsimp only
  let allocated := (writerAllocation ge.genv_cenv caller).2
  let reached := X86AluXorShortcutInputs.temps (.Vptr bindingBlock 0) op imm reg flags width aux
  let value := (0#64)
  have allocation := writer_caller_frame ge.genv_cenv caller
  have entryRun := X86AluXorShortcutInputs.entry ge caller k (.Vptr bindingBlock 0) op imm
    reg flags width aux .b widthBlock aluBlock xorCode sameLane effective widthHelper aluHelper
  have allocatedHeaders : HeaderLoads allocated bindingBlock places :=
    ⟨(allocation.load CC.Mptr _ _ oldBinding).trans headers.cf,
      (allocation.load CC.Mptr _ _ oldBinding).trans headers.zf,
      (allocation.load CC.Mptr _ _ oldBinding).trans headers.sf,
      (allocation.load CC.Mptr _ _ oldBinding).trans headers.overflow,
      (allocation.load CC.Mptr _ _ oldBinding).trans headers.pf⟩
  have allocatedPermissions := X86LogicFlagWritable.frame allocation places oldFlags permissions
  have allocatedRegisters := X86AluReturn.registers allocation addresses origins cellsBlock cellsOffset
    cpu oldCells represented
  have allocatedCast : CC.Cop.semCast rspValue (CC.tptr CC.tvoid) CC.tlong allocated = some rspValue := by
    have unchanged : CC.Cop.semCast rspValue (CC.tptr CC.tvoid) CC.tlong allocated =
        CC.Cop.semCast rspValue (CC.tptr CC.tvoid) CC.tlong caller := by cases rspValue <;> rfl
    exact unchanged.trans rspCast
  have ordinaryCode : (BitVec.ofNat 8 reg.val).setWidth 32 ≠ (4#32) := ordinary_register reg ordinaryDst
  have unshadowedHelpers :
      (writerAllocation ge.genv_cenv caller).1.get X86_program_profile_bpf._x86_width_effective = none ∧
      (writerAllocation ge.genv_cenv caller).1.get X86_program_profile_bpf._x86_apply_width = none ∧
      (writerAllocation ge.genv_cenv caller).1.get X86_program_profile_bpf._x86_width_bits = none :=
    ⟨unshadowed ge caller _ (by decide +kernel), unshadowed ge caller _ (by decide +kernel),
      unshadowed ge caller _ (by decide +kernel)⟩
  obtain ⟨final, tailRun, registers, finalFlags, next, released, kept⟩ :=
    X86LogicByteTail.execute ge layout.bindings valueLayout layout.gpr layout.cell
      widthBlock applyBlock bitsBlock widthHelper applyBinding bitsBinding caller reached k unshadowedHelpers
      allocated bindingBlock cellsBlock places value af cpu oldCf (2#8) (.inl rfl)
      entryRun.2.operation entryRun.2.width ((allocation.load .Mint8unsigned _ _ oldFlags.1).trans oldByte)
      entryRun.2.binding entryRun.2.result allocatedHeaders differentFlags separate
      cellsOffset rspValue ((allocation.load CC.Mptr _ _ oldBinding).trans cells)
      ((allocation.load CC.Mptr _ _ oldCells).trans rsp) allocatedCast reg entryRun.2.destination
      ((aux >>> 8).setWidth 8) entryRun.2.shift previous
      ((allocation.load CC.Mptr _ _ oldCells).trans leftRead)
      ((allocation.load .Mint8unsigned _ _ oldCells).trans leftTag)
      ordinaryCode bindingSeparate cellWritable tagWritable addresses origins allocatedRegisters
      oldBinding oldCells rfl oldFlags outside allocatedPermissions boundary
  refine ⟨final, entryRun.1.trans tailRun, registers, finalFlags, next, released, ?_⟩
  intro chunk block offset oldBlock notCells outsideFlags
  exact (kept chunk block offset oldBlock notCells outsideFlags).trans
    (allocation.load chunk block offset oldBlock)

end KProgFormal.ClightRefinement.X86AluXorShortcutByteCall
