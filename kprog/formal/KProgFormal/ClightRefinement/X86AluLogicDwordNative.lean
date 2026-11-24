import KProgFormal.ClightRefinement.X86AluLogicDwordCall
import KProgFormal.ClightRefinement.X86LogicDwordReference
import KProgFormal.ClightRefinement.X86LogicReferenceView

namespace KProgFormal.ClightRefinement.X86AluLogicDwordNative
open X86RegisterView X86LogicFlagOrder

/-- Genuine scalar/tag0 dword OR/AND call, from initial caller heap and permissions
through real readers, numerical helper, five flag stores, dword writeback,
local release and void return, refines the SAME canonical ISA step. Legal
slices determine the shifts; the final GPR and flag views use that step's
actual output state. The caller frame and released locals remain explicit. -/
theorem execute (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (caller : CC.Mem) (k : CC.Cont) (op imm : CC.Val) (dst src : Reference.X86.RegisterSlice)
    (flags width : BitVec 8) (aux : BitVec 32) (isAnd : Bool)
    (left right : BitVec 64) (widthBlock readerBlock aluBlock bindingBlock cellsBlock : CC.Block)
    (cellsOffset : CC.Integers.Ptrofs)
    (oldBinding : bindingBlock.toNat < caller.nextblock.toNat)
    (oldCells : cellsBlock.toNat < caller.nextblock.toNat)
    (operationCode : (aux.setWidth 8).setWidth 32 = (X86AluLogicResultEntry.code isAnd).setWidth 32)
    (ordinaryDst : dst.reg ≠ 4) (ordinarySrc : src.reg ≠ 4)
    (effective : X86Width.result flags = X86ShiftLeft.argument .d)
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
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (dst.reg.val : Int)))) =
        some (.Vlong left))
    (rightRead : CC.Mem.load CC.Mptr caller cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (src.reg.val : Int)))) =
        some (.Vlong right))
    (leftTag : CC.Mem.load .Mint8unsigned caller cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * (dst.reg.val : Int))) + 8)) =
        some (X86Width.argument (0#8)))
    (rightTag : CC.Mem.load .Mint8unsigned caller cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * (src.reg.val : Int))) + 8)) =
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
    (cellWritable : CC.Mem.validAccess caller CC.Mptr cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (dst.reg.val : Int)))) .Writable = true)
    (tagWritable : CC.Mem.validAccess caller .Mint8unsigned cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * (dst.reg.val : Int))) + 8))
      .Writable = true)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (state : Reference.X86.State) (nextPc : BitVec 64)
    (represented : RegistersRepresent addresses origins caller cellsBlock cellsOffset (X86LogicReference.input state))
    (dstLane : (aux >>> 8).setWidth 8 = BitVec.ofNat 8 (dst.shift .w32))
    (srcLane : (aux >>> 16).setWidth 8 = BitVec.ofNat 8 (src.shift .w32))
    (running : state.modelError = none)
    (boundary : CC.isCallCont k = true) :
    let native := Reference.X86.step (.logic .w32 (X86LogicDwordReference.kind isAnd) (.register dst) (.register src) nextPc) state
    ∃ final, InternalRun ge ((37 + X86AluReadOperands.length .d + 29) +
      (X86LogicFlagStage.length .d + 197 + 5))
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG)
        [.Vptr bindingBlock 0, op, X86Width.argument (X86RegisterReadValue.registerByte dst.reg),
          X86Width.argument (X86RegisterReadValue.registerByte src.reg), X86Width.argument flags,
          .Vint aux, imm, X86Width.argument width] k caller)
      (.Returnstate .Vundef k final) ∧
      RegistersRepresent addresses origins final cellsBlock cellsOffset (X86LogicReference.input native.state) ∧
      X86LogicFlagMemory.FlagsRepresent final places (X86LogicReference.input native.state).flags ∧
      native.events = [] ∧ native.fault = none ∧ native.state.pc = nextPc ∧
      native.state.oracle = {state.oracle with cursor := state.oracle.cursor + 1} ∧
      native.state.memory = state.memory ∧ native.state.xmm0 = state.xmm0 ∧
      native.state.fsBase = state.fsBase ∧ native.state.gsBase = state.gsBase ∧
      native.state.addressWidth = state.addressWidth ∧ native.state.modelError = none ∧
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
  let cpu := X86LogicReference.input state
  let value := X86AluLogicResultEntry.result isAnd
      (X86RegisterReadLanes.result left .d ((aux >>> 8).setWidth 8))
      (X86RegisterReadLanes.result right .d ((aux >>> 16).setWidth 8))
  have boundDst : ((aux >>> 8).setWidth 8).toNat < 64 := by
    rw [dstLane]
    cases dst <;> simp [Reference.X86.RegisterSlice.shift]
  have boundSrc : ((aux >>> 16).setWidth 8).toNat < 64 := by
    rw [srcLane]
    cases src <;> simp [Reference.X86.RegisterSlice.shift]
  obtain ⟨final, run, registers, flagBytes, next, released, kept⟩ :=
    X86AluLogicDwordCall.execute ge layout caller k op imm dst.reg src.reg flags width aux isAnd left right
      widthBlock readerBlock aluBlock bindingBlock cellsBlock cellsOffset oldBinding oldCells operationCode
      ordinaryDst ordinarySrc boundDst boundSrc effective widthHelper readerHelper aluHelper
      cells leftRead rightRead leftTag rightTag valueLayout applyBlock bitsBlock applyBinding bitsBinding
      places headers differentFlags oldFlags separate outside bindingSeparate permissions oldCf oldByte
      cellWritable tagWritable addresses origins cpu
      (state.oracle.bits state.oracle.cursor) represented boundary
  have canonical := X86LogicDwordReference.step addresses origins caller cellsBlock cellsOffset state
    represented dst src left right nextPc aux isAnd ordinaryDst ordinarySrc dstLane srcLane
    leftRead rightRead leftTag rightTag running
  let output := {cpu.setReg .d (X86.GPR.ofIndex dst.reg) value with
    flags := X86.Flags.logic .d (X86.Value.trunc .d value)
      (state.oracle.bits state.oracle.cursor) cpu.flags}
  have views := X86LogicReferenceView.represented addresses origins final cellsBlock cellsOffset places
    output (Reference.X86.step (.logic .w32 (X86LogicDwordReference.kind isAnd) (.register dst) (.register src) nextPc) state).state
    state.rflags registers flagBytes
    (by
      intro index
      rw [canonical]
      cases dst <;> simp [output, cpu, value, Reference.X86.RegisterSlice.shift, X86.Cpu.setReg,
        X86.Value.writeView, X86.Value.trunc_trunc]) (by rw [canonical])
  refine ⟨final, run, views.1, views.2, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, next, released, kept⟩
  all_goals rw [canonical] <;> rfl

end KProgFormal.ClightRefinement.X86AluLogicDwordNative
