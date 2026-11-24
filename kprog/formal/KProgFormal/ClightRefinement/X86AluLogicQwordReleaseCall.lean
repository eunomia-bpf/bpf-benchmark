import KProgFormal.ClightRefinement.X86AluLogicRspQwordCall
import KProgFormal.ClightRefinement.X86LogicQwordReleaseTail

namespace KProgFormal.ClightRefinement.X86AluLogicQwordReleaseCall
open X86RegisterView X86LogicFlagOrder

private theorem unshadowed (ge : CC.CGenv) (caller : CC.Mem) (id : CC.Ident)
    (other : id ∉ CC.varNames X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_vars) :
    (writerAllocation ge.genv_cenv caller).1.get id = none := by
  have allocated := CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (writerAllocation ge.genv_cenv caller)).symm
  simpa only [CC.emptyEnv, CC.PTree.gempty] using CC.allocVariables_env_other allocated other

/-- The genuine OR/AND RSP qword handler call now completes both signed-SP
release branches. Initial caller View/rights derive their actual allocation
and post-flag observations before every source store and free/return.
Provider ABI and architectural cache/ghost ownership remain explicit. -/
theorem execute (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (caller : CC.Mem) (k : CC.Cont) (op imm : CC.Val) (src : Fin 16)
    (flags width : BitVec 8) (aux : BitVec 32) (isAnd : Bool)
    (left right : BitVec 64) (widthBlock readerBlock aluBlock bindingBlock cellsBlock baseBlock : CC.Block)
    (cellsOffset baseOffset : CC.Integers.Ptrofs)
    (oldBinding : bindingBlock.toNat < caller.nextblock.toNat)
    (oldCells : cellsBlock.toNat < caller.nextblock.toNat)
    (oldBase : baseBlock.toNat < caller.nextblock.toNat)
    (operationCode : (aux.setWidth 8).setWidth 32 = (X86AluLogicResultEntry.code isAnd).setWidth 32)
    (dstLane : (aux >>> 8).setWidth 8 = (0#8))
    (srcLane : (aux >>> 16).setWidth 8 = (0#8))
    (effective : X86Width.result flags = X86ShiftLeft.argument .q)
    (widthHelper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective =
        some widthBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv widthBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (readerHelper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_read_reg =
        some readerBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv readerBlock =
        some (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg))
    (aluHelper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_alu_result =
        some aluBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv aluBlock =
        some (.Internal X86_program_profile_bpf.f_x86_alu_result))
    (cells : CC.Mem.load CC.Mptr caller bindingBlock (CC.Integers.Ptrofs.unsigned (0 : CC.Integers.Ptrofs)) =
      some (.Vptr cellsBlock cellsOffset))
    (leftRead : CC.Mem.load CC.Mptr caller cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * ((4 : Fin 16).val : Int)))) =
        some (.Vlong left))
    (rightRead : CC.Mem.load CC.Mptr caller cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (src.val : Int)))) =
        some (.Vlong right))
    (leftTag : CC.Mem.load .Mint8unsigned caller cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * ((4 : Fin 16).val : Int))) + 8)) =
        some (X86Width.argument (0#8)))
    (rightTag : src ≠ 4 → CC.Mem.load .Mint8unsigned caller cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * (src.val : Int))) + 8)) =
        some (X86Width.argument (0#8)))
    (header : CC.Mem.load CC.Mptr caller bindingBlock 112 = some (.Vptr baseBlock baseOffset))
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (applyBlock bitsBlock : CC.Block)
    (applyBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_apply_width = some applyBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv applyBlock = some (.Internal X86_program_profile_bpf.f_x86_apply_width))
    (bitsBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_bits = some bitsBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv bitsBlock = some (.Internal X86_program_profile_bpf.f_x86_width_bits))
    (tagHelper : CC.Block)
    (tagBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_reg_tag = some tagHelper ∧
      CC.Genv.findFunctPtr ge.genv_genv tagHelper =
        some (.Internal X86_program_profile_bpf.f_x86_sim_inline_reg_tag))
    (places : Locations) (headers : HeaderLoads caller bindingBlock places)
    (differentFlags : X86LogicFlagMemory.Distinct places)
    (oldFlags : places.cf.1.toNat < caller.nextblock.toNat ∧ places.zf.1.toNat < caller.nextblock.toNat ∧
      places.sf.1.toNat < caller.nextblock.toNat ∧ places.overflow.1.toNat < caller.nextblock.toNat ∧
      places.pf.1.toNat < caller.nextblock.toNat)
    (separate : places.cf.1 ≠ bindingBlock ∧ places.zf.1 ≠ bindingBlock ∧ places.sf.1 ≠ bindingBlock ∧
      places.overflow.1 ≠ bindingBlock ∧ places.pf.1 ≠ bindingBlock)
    (outside : places.cf.1 ≠ cellsBlock ∧ places.zf.1 ≠ cellsBlock ∧ places.sf.1 ≠ cellsBlock ∧
      places.overflow.1 ≠ cellsBlock ∧ places.pf.1 ≠ cellsBlock)
    (outsideBase : places.cf.1 ≠ baseBlock ∧ places.zf.1 ≠ baseBlock ∧ places.sf.1 ≠ baseBlock ∧
      places.overflow.1 ≠ baseBlock ∧ places.pf.1 ≠ baseBlock)
    (bindingSeparate : bindingBlock ≠ cellsBlock)
    (permissions : X86LogicFlagWritable.Writable caller places)
    (oldCf : BitVec 8)
    (oldByte : CC.Mem.load .Mint8unsigned caller places.cf.1 (CC.Integers.Ptrofs.unsigned places.cf.2) =
      some (.Vint (oldCf.setWidth 32)))
    (cellWritable : CC.Mem.validAccess caller CC.Mptr cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * ((4 : Fin 16).val : Int)))) .Writable = true)
    (tagWritable : CC.Mem.validAccess caller .Mint8unsigned cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * ((4 : Fin 16).val : Int))) + 8))
      .Writable = true)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (cpu : X86.Cpu) (af : Bool)
    (represented : RegistersRepresent addresses origins caller cellsBlock cellsOffset cpu)
    (nativeBase : CC.Mem.load .Mint64 caller baseBlock (CC.Integers.Ptrofs.unsigned baseOffset) =
      some (.Vlong origins.stack))
    (stack input frameHelper : CC.Block) (cacheOffset : CC.Integers.Ptrofs)
    (ghostPlaces : X86CallFrameComplete.Places)
    (stackLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_stack_mem = some X86RegisterWriteRspReleaseWord.stackRecord)
    (cacheView : X86ReleaseProvider.View caller bindingBlock stack cacheOffset)
    (ghostView : X86CallFrameComplete.View caller bindingBlock ghostPlaces)
    (oldStack : stack.toNat < caller.nextblock.toNat)
    (oldGhost : ∀ slot, (ghostPlaces.tag slot).1.toNat < caller.nextblock.toNat ∧
      (ghostPlaces.pointer slot).1.toNat < caller.nextblock.toNat)
    (inputSymbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._native_lab_entry_input = some input)
    (inputGlobal : CC.Genv.findFunctPtr ge.genv_genv input = some X86RegisterWriteRspReleaseWord.inputFunction)
    (frameSymbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_call_frame_values = some frameHelper)
    (frameGlobal : CC.Genv.findFunctPtr ge.genv_genv frameHelper = some (.Internal X86CallFrameEntry.handler))
    (bindingCache : bindingBlock ≠ stack) (cellsCache : cellsBlock ≠ stack)
    (ghostSeparate : X86CallFrameComplete.Separated bindingBlock ghostPlaces)
    (available : X86ReleaseProvider.Available ge bindingBlock stack cacheOffset)
    (cellsGhost : X86ReleaseReturn.ObserverOutside stack ghostPlaces cellsBlock)
    (flagsGhost : X86ReleaseReturn.FlagsOutside stack ghostPlaces places)
    (boundary : CC.isCallCont k = true) :
    let value := X86AluLogicResultEntry.result isAnd
      (cpu.getReg .q (X86.GPR.ofIndex (4 : Fin 16)) false)
      (cpu.getReg .q (X86.GPR.ofIndex src) false)
    ∃ trace final, CC.Star (CC.Step2 ge)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG)
        [.Vptr bindingBlock 0, op, X86Width.argument (X86RegisterReadValue.registerByte (4 : Fin 16)),
          X86Width.argument (X86RegisterReadValue.registerByte src), X86Width.argument flags,
          .Vint aux, imm, X86Width.argument width] k caller) trace
      (.Returnstate .Vundef k final) ∧
      RegistersRepresent addresses origins final cellsBlock cellsOffset
        ({cpu.setReg .q (X86.GPR.ofIndex (4 : Fin 16)) value with
            flags := X86.Flags.logic .q (X86.Value.trunc .q value) af cpu.flags}) ∧
      X86LogicFlagMemory.FlagsRepresent final places (X86.Flags.logic .q (X86.Value.trunc .q value) af cpu.flags) ∧
      final.nextblock = (writerAllocation ge.genv_cenv caller).2.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv ge.genv_cenv (writerAllocation ge.genv_cenv caller).1,
        ∀ offset, row.2.1 ≤ offset → offset < row.2.2 →
        ∀ kind permission, CC.Mem.perm final row.1 offset kind permission = false) ∧
      (∀ (chunk : CC.Chunk) (block : CC.Block) (offset : Int),
        block.toNat < caller.nextblock.toNat → block ≠ cellsBlock →
        block ≠ places.cf.1 ∧ block ≠ places.zf.1 ∧ block ≠ places.sf.1 ∧
          block ≠ places.overflow.1 ∧ block ≠ places.pf.1 →
        X86ReleaseReturn.ObserverOutside stack ghostPlaces block →
        CC.Mem.load chunk final block offset = CC.Mem.load chunk caller block offset) := by
  dsimp only
  let allocated := (writerAllocation ge.genv_cenv caller).2
  let reached := X86AluNativeLogicInputs.temps (.Vptr bindingBlock 0) op imm (4 : Fin 16) src flags width aux .q isAnd cpu false false
  let value := X86AluLogicResultEntry.result isAnd
    (cpu.getReg .q (X86.GPR.ofIndex (4 : Fin 16)) false)
    (cpu.getReg .q (X86.GPR.ofIndex src) false)
  have allocation := writer_caller_frame ge.genv_cenv caller
  have entryRun := X86AluNativeLogicInputs.entry ge layout valueLayout addresses origins cpu
    caller k op imm (4 : Fin 16) src flags width aux .q false false left right
    widthBlock readerBlock aluBlock bindingBlock cellsBlock baseBlock cellsOffset baseOffset
    oldBinding oldCells oldBase isAnd operationCode represented (by simp) (by simp)
    (by simpa using dstLane) (by simpa using srcLane) effective widthHelper readerHelper aluHelper
    cells leftRead rightRead (fun _ => leftTag) rightTag header nativeBase
  have allocatedHeaders : HeaderLoads allocated bindingBlock places :=
    ⟨(allocation.load CC.Mptr _ _ oldBinding).trans headers.cf,
      (allocation.load CC.Mptr _ _ oldBinding).trans headers.zf,
      (allocation.load CC.Mptr _ _ oldBinding).trans headers.sf,
      (allocation.load CC.Mptr _ _ oldBinding).trans headers.overflow,
      (allocation.load CC.Mptr _ _ oldBinding).trans headers.pf⟩
  have allocatedPermissions := X86LogicFlagWritable.frame allocation places oldFlags permissions
  have allocatedRegisters := X86AluReturn.registers allocation addresses origins cellsBlock cellsOffset
    cpu oldCells represented
  have unshadowedHelpers :
      (writerAllocation ge.genv_cenv caller).1.get X86_program_profile_bpf._x86_width_effective = none ∧
      (writerAllocation ge.genv_cenv caller).1.get X86_program_profile_bpf._x86_apply_width = none ∧
      (writerAllocation ge.genv_cenv caller).1.get X86_program_profile_bpf._x86_width_bits = none :=
    ⟨unshadowed ge caller _ (by decide +kernel), unshadowed ge caller _ (by decide +kernel),
      unshadowed ge caller _ (by decide +kernel)⟩
  have allocatedView : X86ReleaseOuterComplete.View allocated bindingBlock stack cellsBlock cacheOffset cellsOffset ghostPlaces left := by
    refine ⟨⟨(allocation.load CC.Mptr bindingBlock 8 oldBinding).trans cacheView.header, ?_, ?_⟩,
      ⟨?_, ?_, ?_, ?_⟩, (allocation.load CC.Mptr bindingBlock 0 oldBinding).trans cells,
      (allocation.load CC.Mptr cellsBlock _ oldCells).trans leftRead⟩
    · intro slot lane
      exact (writer_caller_access ge.genv_cenv caller allocated stack oldStack rfl _ _ _).trans (cacheView.bytes slot lane)
    · intro slot
      exact (writer_caller_access ge.genv_cenv caller allocated stack oldStack rfl _ _ _).trans (cacheView.words slot)
    · intro slot
      exact (allocation.load CC.Mptr bindingBlock _ oldBinding).trans (ghostView.tags slot)
    · intro slot
      exact (allocation.load CC.Mptr bindingBlock _ oldBinding).trans (ghostView.pointers slot)
    · intro slot
      exact (writer_caller_access ge.genv_cenv caller allocated (ghostPlaces.tag slot).1 (oldGhost slot).1 rfl _ _ _).trans (ghostView.tag_rights slot)
    · intro slot
      exact (writer_caller_access ge.genv_cenv caller allocated (ghostPlaces.pointer slot).1 (oldGhost slot).2 rfl _ _ _).trans (ghostView.pointer_rights slot)
  obtain ⟨trace, final, tailRun, registers, finalFlags, next, released, kept⟩ :=
    X86LogicQwordReleaseTail.execute ge layout.bindings valueLayout layout.gpr layout.cell
      widthBlock applyBlock bitsBlock widthHelper applyBinding bitsBinding tagHelper tagBinding caller reached k unshadowedHelpers
      allocated bindingBlock cellsBlock baseBlock places value left af cpu oldCf (X86AluLogicResultEntry.code isAnd)
      (by cases isAnd <;> simp [X86AluLogicResultEntry.code])
      entryRun.2.operation entryRun.2.width ((allocation.load .Mint8unsigned _ _ oldFlags.1).trans oldByte)
      entryRun.2.binding entryRun.2.result allocatedHeaders differentFlags separate
      cellsOffset baseOffset ((allocation.load CC.Mptr _ _ oldBinding).trans cells)
      entryRun.2.destination
      (by simpa [dstLane, reached] using entryRun.2.shift)
      (by simpa [srcLane, reached] using
        (X86AluNativeLogicInputs.source_shift
          (.Vptr bindingBlock 0) op imm (4 : Fin 16) src flags width aux .q isAnd cpu false false))
      ((allocation.load .Mint8unsigned _ _ oldCells).trans leftTag)
      bindingSeparate cellWritable tagWritable addresses origins allocatedRegisters
      ((allocation.load CC.Mptr _ _ oldCells).trans leftRead)
      ((allocation.load CC.Mptr _ _ oldBinding).trans header)
      ((allocation.load .Mint64 _ _ oldBase).trans nativeBase)
      oldBase oldBinding oldCells rfl oldFlags outside outsideBase allocatedPermissions
      stack input frameHelper cacheOffset ghostPlaces stackLayout allocatedView inputSymbol inputGlobal frameSymbol frameGlobal
      bindingCache cellsCache ghostSeparate available cellsGhost flagsGhost boundary
  refine ⟨trace, final, ?_, registers, finalFlags, next, released, ?_⟩
  · simpa only [CC.E0, CC.Eapp, List.nil_append] using star_trans entryRun.1.sound tailRun
  · intro chunk block offset oldBlock notCells outsideFlags outsideRelease
    exact (kept chunk block offset oldBlock notCells outsideFlags outsideRelease).trans
      (allocation.load chunk block offset oldBlock)


end KProgFormal.ClightRefinement.X86AluLogicQwordReleaseCall
