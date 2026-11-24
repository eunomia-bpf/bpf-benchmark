import KProgFormal.ClightRefinement.X86AluNativeLogicByteCall
import KProgFormal.ClightRefinement.X86LogicByteReference
import KProgFormal.ClightRefinement.X86LogicReferenceView

namespace KProgFormal.ClightRefinement.X86AluNativeLogicByteNative
open X86RegisterView X86LogicFlagOrder

/-- Genuine RSP-source byte OR/AND call, from initial caller heap and permissions
through real readers, numerical helper, five flag stores, byte writeback,
local release and void return, refines the SAME canonical ISA step. Legal
slices determine the shifts; the final GPR and flag views use that step's
actual output state. The caller frame and released locals remain explicit. -/
theorem execute (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (caller : CC.Mem) (k : CC.Cont) (op imm : CC.Val) (dst src : Reference.X86.RegisterSlice)
    (flags width : BitVec 8) (aux : BitVec 32) (isAnd : Bool)
    (left right : BitVec 64) (widthBlock readerBlock aluBlock bindingBlock cellsBlock baseBlock : CC.Block)
    (cellsOffset baseOffset : CC.Integers.Ptrofs)
    (oldBinding : bindingBlock.toNat < caller.nextblock.toNat)
    (oldCells : cellsBlock.toNat < caller.nextblock.toNat)
    (oldBase : baseBlock.toNat < caller.nextblock.toNat)
    (operationCode : (aux.setWidth 8).setWidth 32 = (X86AluLogicResultEntry.code isAnd).setWidth 32)
    (ordinaryDst : dst.reg ≠ 4)
    (effective : X86Width.result flags = X86ShiftLeft.argument .b)
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
    (rightTag : src.reg ≠ 4 → CC.Mem.load .Mint8unsigned caller cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * (src.reg.val : Int))) + 8)) =
        some (X86Width.argument (0#8)))
    (header : CC.Mem.load CC.Mptr caller bindingBlock 112 = some (.Vptr baseBlock baseOffset))
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
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (dst.reg.val : Int)))) .Writable = true)
    (tagWritable : CC.Mem.validAccess caller .Mint8unsigned cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * (dst.reg.val : Int))) + 8))
      .Writable = true)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (state : Reference.X86.State) (nextPc : BitVec 64)
    (represented : RegistersRepresent addresses origins caller cellsBlock cellsOffset (X86LogicReference.input state))
    (nativeBase : CC.Mem.load .Mint64 caller baseBlock (CC.Integers.Ptrofs.unsigned baseOffset) =
      some (.Vlong origins.stack))
    (dstLane : (aux >>> 8).setWidth 8 = BitVec.ofNat 8 (dst.shift .w8))
    (srcLane : (aux >>> 16).setWidth 8 = BitVec.ofNat 8 (src.shift .w8))
    (running : state.modelError = none)
    (boundary : CC.isCallCont k = true) :
    let native := Reference.X86.step (.logic .w8 (X86LogicByteReference.kind isAnd) (.register dst) (.register src) nextPc) state
    ∃ final, InternalRun ge ((37 + X86AluReadNativeOperands.length dst.reg src.reg .b + 29) +
      (X86LogicFlagStage.length .b + 169 + 5))
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
    (cpu.getReg .b (X86.GPR.ofIndex dst.reg) (dst.shift .w8 == 8))
    (cpu.getReg .b (X86.GPR.ofIndex src.reg) (src.shift .w8 == 8))
  have legalDst : (dst.shift .w8 == 8) = true → .b = X86.Size.b ∧ dst.reg.val < 4 := by
    cases dst <;> simp [Reference.X86.RegisterSlice.shift, Reference.X86.RegisterSlice.reg]
  have legalSrc : (src.shift .w8 == 8) = true → .b = X86.Size.b ∧ src.reg.val < 4 := by
    cases src <;> simp [Reference.X86.RegisterSlice.shift, Reference.X86.RegisterSlice.reg]
  have laneDst : (aux >>> 8).setWidth 8 = (if dst.shift .w8 == 8 then 8 else 0) := by
    rw [dstLane]
    cases dst <;> rfl
  have laneSrc : (aux >>> 16).setWidth 8 = (if src.shift .w8 == 8 then 8 else 0) := by
    rw [srcLane]
    cases src <;> rfl
  have highDst : decide (((aux >>> 8).setWidth 8).setWidth 32 = (8#32)) =
      (dst.shift .w8 == 8) := by
    rw [dstLane]
    cases dst <;> rfl
  obtain ⟨final, run, registers, flagBytes, next, released, kept⟩ :=
    X86AluNativeLogicByteCall.execute ge layout caller k op imm dst.reg src.reg flags width aux isAnd (dst.shift .w8 == 8) (src.shift .w8 == 8) left right
      widthBlock readerBlock aluBlock bindingBlock cellsBlock baseBlock cellsOffset baseOffset oldBinding oldCells oldBase operationCode
      ordinaryDst legalDst legalSrc laneDst laneSrc effective widthHelper readerHelper aluHelper
      cells leftRead rightRead leftTag rightTag header valueLayout applyBlock bitsBlock applyBinding bitsBinding
      places headers differentFlags oldFlags separate outside bindingSeparate permissions oldCf oldByte
      rspValue rsp rspCast cellWritable tagWritable addresses origins cpu
      (state.oracle.bits state.oracle.cursor) represented nativeBase boundary
  have nativeSize : X86LogicRegisterReference.size .w8 = .b := rfl
  have canonical := X86LogicRegisterReference.step .w8 state dst src
    (X86LogicByteReference.kind isAnd) value nextPc running (by
      cases isAnd
      · refine .inr (.inl ⟨rfl, ?_⟩)
        cases dst <;> cases src <;> simp [value, cpu, X86AluLogicResultEntry.result,
          Reference.X86.RegisterSlice.shift, nativeSize]
      · refine .inr (.inr ⟨rfl, ?_⟩)
        cases dst <;> cases src <;> simp [value, cpu, X86AluLogicResultEntry.result,
          Reference.X86.RegisterSlice.shift, nativeSize])
  let output := {cpu.setReg .b (X86.GPR.ofIndex dst.reg) value (dst.shift .w8 == 8) with
    flags := X86.Flags.logic .b (X86.Value.trunc .b value)
      (state.oracle.bits state.oracle.cursor) cpu.flags}
  have views := X86LogicReferenceView.represented addresses origins final cellsBlock cellsOffset places
    output (Reference.X86.step (.logic .w8 (X86LogicByteReference.kind isAnd) (.register dst) (.register src) nextPc) state).state
    state.rflags (by simpa only [highDst] using registers) flagBytes
    (by
      intro index
      rw [canonical]
      cases dst <;> simp [output, cpu, value, Reference.X86.RegisterSlice.shift, X86.Cpu.setReg,
        X86.Value.writeView, X86.Value.writeHigh8, X86.Value.trunc_trunc, nativeSize]) (by rw [canonical]; simp only [nativeSize]; rfl)
  refine ⟨final, run, views.1, views.2, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, next, released, kept⟩
  all_goals rw [canonical] <;> rfl

end KProgFormal.ClightRefinement.X86AluNativeLogicByteNative
