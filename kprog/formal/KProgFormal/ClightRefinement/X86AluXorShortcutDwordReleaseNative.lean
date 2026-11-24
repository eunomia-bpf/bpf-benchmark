import KProgFormal.ClightRefinement.X86AluXorShortcutDwordReleaseCall
import KProgFormal.ClightRefinement.X86LogicDwordReference
import KProgFormal.ClightRefinement.X86LogicReferenceView

namespace KProgFormal.ClightRefinement.X86AluXorShortcutDwordReleaseNative
open X86RegisterView X86LogicFlagOrder

/-- The original matched-register XOR zero shortcut and arbitrary-tag dword overwrite/zero-extension compose with both signed-SP release branches and real return, yielding views of the SAME canonical checked ISA output. Initial caller source View/rights, observer ownership and provider ABI remain explicit; actual trace and supplied heaps stay retained. -/
theorem execute (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (caller : CC.Mem) (k : CC.Cont) (op imm : CC.Val)
    (flags width : BitVec 8) (aux : BitVec 32)
    (left : BitVec 64) (widthBlock aluBlock bindingBlock cellsBlock baseBlock : CC.Block)
    (cellsOffset baseOffset : CC.Integers.Ptrofs)
    (oldBinding : bindingBlock.toNat < caller.nextblock.toNat)
    (oldCells : cellsBlock.toNat < caller.nextblock.toNat)
    (oldBase : baseBlock.toNat < caller.nextblock.toNat)
    (operationCode : (aux.setWidth 8).setWidth 32 = (2#32))
    (effective : X86Width.result flags = X86ShiftLeft.argument .d)
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
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * ((4 : Fin 16).val : Int)))) =
        some (.Vlong left))
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
    (state : Reference.X86.State) (nextPc : BitVec 64)
    (represented : RegistersRepresent addresses origins caller cellsBlock cellsOffset (X86LogicReference.input state))
    (nativeBase : CC.Mem.load .Mint64 caller baseBlock (CC.Integers.Ptrofs.unsigned baseOffset) =
      some (.Vlong origins.stack))
    (dstLane : (aux >>> 8).setWidth 8 = BitVec.ofNat 8 ((Reference.X86.RegisterSlice.low 4).shift .w32))
    (srcLane : (aux >>> 16).setWidth 8 = (0#8))
    (running : state.modelError = none)
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
    let native := Reference.X86.step (.logic .w32 .xor (.register (.low 4)) (.register (.low 4)) nextPc) state
    ∃ trace final, CC.Star (CC.Step2 ge)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG)
        [.Vptr bindingBlock 0, op, X86Width.argument (X86RegisterReadValue.registerByte (4 : Fin 16)),
          X86Width.argument (X86RegisterReadValue.registerByte (4 : Fin 16)), X86Width.argument flags,
          .Vint aux, imm, X86Width.argument width] k caller) trace
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
        X86ReleaseReturn.ObserverOutside stack ghostPlaces block →
        CC.Mem.load chunk final block offset = CC.Mem.load chunk caller block offset) := by
  dsimp only
  let cpu := X86LogicReference.input state
  let value := (0#64)
  have zeroDst : (aux >>> 8).setWidth 8 = (0#8) := by
    simpa [Reference.X86.RegisterSlice.shift] using dstLane
  obtain ⟨trace, final, run, registers, flagBytes, next, released, kept⟩ :=
    X86AluXorShortcutDwordReleaseCall.execute ge layout caller k op imm flags width aux left
      widthBlock aluBlock bindingBlock cellsBlock baseBlock cellsOffset baseOffset oldBinding oldCells oldBase operationCode
      zeroDst srcLane effective widthHelper aluHelper
      cells leftRead header valueLayout applyBlock bitsBlock applyBinding bitsBinding
      places headers differentFlags oldFlags separate outside outsideBase bindingSeparate permissions oldCf oldByte
      cellWritable tagWritable addresses origins cpu
      (state.oracle.bits state.oracle.cursor) represented nativeBase stack input frameHelper cacheOffset ghostPlaces stackLayout cacheView ghostView oldStack oldGhost
      inputSymbol inputGlobal frameSymbol frameGlobal bindingCache cellsCache ghostSeparate available cellsGhost flagsGhost boundary
  have nativeSize : X86LogicRegisterReference.size .w32 = .d := rfl
  have canonical := X86LogicRegisterReference.step .w32 state (.low 4) (.low 4)
    .xor value nextPc running (by
      refine .inl ⟨rfl, ?_⟩
      simp [value,
        Reference.X86.RegisterSlice.shift, Reference.X86.RegisterSlice.reg, nativeSize])
  let output := {cpu.setReg .d (X86.GPR.ofIndex (4 : Fin 16)) value with
    flags := X86.Flags.logic .d (X86.Value.trunc .d value)
      (state.oracle.bits state.oracle.cursor) cpu.flags}
  have views := X86LogicReferenceView.represented addresses origins final cellsBlock cellsOffset places
    output (Reference.X86.step (.logic .w32 .xor (.register (.low 4)) (.register (.low 4)) nextPc) state).state
    state.rflags registers flagBytes
    (by
      intro index
      rw [canonical]
      simp [output, cpu, value, Reference.X86.RegisterSlice.shift, Reference.X86.RegisterSlice.reg, X86.Cpu.setReg,
        X86.Value.writeView, X86.Value.trunc_trunc, nativeSize]) (by rw [canonical]; simp only [nativeSize]; rfl)
  refine ⟨trace, final, run, views.1, views.2, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, next, released, kept⟩
  all_goals rw [canonical] <;> rfl

end KProgFormal.ClightRefinement.X86AluXorShortcutDwordReleaseNative
