import KProgFormal.ClightRefinement.X86AluNativeXorResultEntry
import KProgFormal.ClightRefinement.X86AluXorInputs

namespace KProgFormal.ClightRefinement.X86AluNativeXorInputs

def temps (binding op imm : CC.Val) (dst src : Fin 16) (flags width : BitVec 8)
    (aux : BitVec 32) (size : X86.Size) (cpu : X86.Cpu) (highDst highSrc : Bool) : CC.TempEnv :=
  let initial := X86RegisterView.writerInitialTemps binding op
    (X86Width.argument (X86RegisterReadValue.registerByte dst))
    (X86Width.argument (X86RegisterReadValue.registerByte src)) (X86Width.argument flags)
    (.Vint aux) imm (X86Width.argument width)
  let ready := X86AluDecode.temps (X86AluEntry.widthTemps
    (initial.set X86_program_profile_bpf.___x86_l_width (X86Width.argument width)) flags) aux
  let lhs := cpu.getReg size (X86.GPR.ofIndex dst) highDst
  let rhs := cpu.getReg size (X86.GPR.ofIndex src) highSrc
  X86ShiftLeftSite.afterTemps (X86AluReadNativeXorOperands.temps ready lhs rhs) (.Vlong (lhs ^^^ rhs))

/-- Every tail observation is derived from the exact reached temporary map,
including the distinct-register and same-register/different-lane routes. -/
theorem observations (binding op imm : CC.Val) (dst src : Fin 16) (flags width : BitVec 8)
    (aux : BitVec 32) (size : X86.Size) (cpu : X86.Cpu) (highDst highSrc : Bool)
    (operationCode : (aux.setWidth 8).setWidth 32 = (2#32))
    (effective : X86Width.result flags = X86ShiftLeft.argument size) :
    X86AluXorInputs.Observed (temps binding op imm dst src flags width aux size cpu highDst highSrc) binding dst size
      ((aux >>> 8).setWidth 8)
      ((fun a b => a ^^^ b)
        (cpu.getReg size (X86.GPR.ofIndex dst) highDst)
        (cpu.getReg size (X86.GPR.ofIndex src) highSrc)) := by
  refine ⟨?_, ?_, ?_, ?_, ?_, ?_⟩
  all_goals
    simp +decide [temps, X86ShiftLeftSite.afterTemps, X86AluReadNativeXorOperands.temps,
      X86AluReadSite.selectedTemps, X86AluReadNativeTail.temps, X86AluReadRhs.temps,
      X86AluReadSite.lhsTemps, X86AluDecode.temps, X86AluEntry.widthTemps,
      X86RegisterView.writerInitialTemps, X86Width.argument, CC.PTree.gss, CC.PTree.gso,
      X86AluDecode.field_byte, BitVec.ushiftRight_zero, operationCode, effective]

/-- The real decode and source execution retain the original source-lane
field needed by qword pointer selection; no intermediate observation is assumed. -/
theorem source_shift (binding op imm : CC.Val) (dst src : Fin 16) (flags width : BitVec 8)
    (aux : BitVec 32) (size : X86.Size) (cpu : X86.Cpu) (highDst highSrc : Bool) :
    (temps binding op imm dst src flags width aux size cpu highDst highSrc).get
      X86_program_profile_bpf.___x86_l_src_shift =
      some (.Vint (((aux >>> 16).setWidth 8).setWidth 32)) := by
  all_goals
    simp +decide [temps, X86ShiftLeftSite.afterTemps, X86AluReadNativeXorOperands.temps,
      X86AluReadSite.selectedTemps, X86AluReadNativeTail.temps, X86AluReadRhs.temps,
      X86AluReadSite.lhsTemps, X86AluDecode.temps, X86AluEntry.widthTemps,
      X86RegisterView.writerInitialTemps, X86Width.argument, CC.PTree.gss, CC.PTree.gso,
      X86AluDecode.field_byte]

/-- Genuine handler entry derives the numerical source execution and all
six tail observations for ordinary and RSP readers, using the same initial CPU. -/
theorem entry (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (cpu : X86.Cpu)
    (caller : CC.Mem) (k : CC.Cont) (op imm : CC.Val) (dst src : Fin 16)
    (flags width : BitVec 8) (aux : BitVec 32) (size : X86.Size) (highDst highSrc : Bool)
    (left right : BitVec 64) (widthBlock readerBlock aluBlock bindingBlock cellsBlock baseBlock : CC.Block)
    (cellsOffset baseOffset : CC.Integers.Ptrofs)
    (oldBinding : bindingBlock.toNat < caller.nextblock.toNat)
    (oldCells : cellsBlock.toNat < caller.nextblock.toNat)
    (oldBase : baseBlock.toNat < caller.nextblock.toNat)
    (different : dst ≠ src)
    (operationCode : (aux.setWidth 8).setWidth 32 = (2#32))
    (represented : X86RegisterView.RegistersRepresent addresses origins caller cellsBlock cellsOffset cpu)
    (legalDst : highDst = true → size = .b ∧ dst.val < 4)
    (legalSrc : highSrc = true → size = .b ∧ src.val < 4)
    (dstLane : (aux >>> 8).setWidth 8 = (if highDst then 8 else 0))
    (srcLane : (aux >>> 16).setWidth 8 = (if highSrc then 8 else 0))
    (effective : X86Width.result flags = X86ShiftLeft.argument size)
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
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (dst.val : Int)))) =
        some (.Vlong left))
    (rightRead : CC.Mem.load CC.Mptr caller cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (src.val : Int)))) =
        some (.Vlong right))
    (leftTag : dst ≠ 4 → CC.Mem.load .Mint8unsigned caller cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * (dst.val : Int))) + 8)) =
        some (.Vint (0#32)))
    (rightTag : src ≠ 4 → CC.Mem.load .Mint8unsigned caller cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * (src.val : Int))) + 8)) =
        some (.Vint (0#32)))
    (header : CC.Mem.load CC.Mptr caller bindingBlock 112 = some (.Vptr baseBlock baseOffset))
    (native : CC.Mem.load .Mint64 caller baseBlock (CC.Integers.Ptrofs.unsigned baseOffset) =
      some (.Vlong origins.stack)) :
    let value := (fun a b => a ^^^ b)
      (cpu.getReg size (X86.GPR.ofIndex dst) highDst)
      (cpu.getReg size (X86.GPR.ofIndex src) highSrc)
    let reached := temps (.Vptr bindingBlock 0) op imm dst src flags width aux size cpu highDst highSrc
    InternalRun ge (37 + X86AluReadNativeXorOperands.length dst src size + 29)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG)
        [.Vptr bindingBlock 0, op, X86Width.argument (X86RegisterReadValue.registerByte dst),
          X86Width.argument (X86RegisterReadValue.registerByte src), X86Width.argument flags,
          .Vint aux, imm, X86Width.argument width] k caller)
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG X86ShiftLeftRoute.flags
        (X86AluEntry.continuation k) (X86RegisterView.writerAllocation ge.genv_cenv caller).1
        reached (X86RegisterView.writerAllocation ge.genv_cenv caller).2) ∧
    X86AluXorInputs.Observed reached (.Vptr bindingBlock 0) dst size ((aux >>> 8).setWidth 8) value := by
  dsimp only
  refine ⟨?_, observations _ _ _ dst src flags width aux size cpu highDst highSrc operationCode effective⟩
  exact X86AluNativeXorResultEntry.from_call ge layout valueLayout addresses origins cpu caller k op imm dst src
    flags width aux size highDst highSrc left right widthBlock readerBlock aluBlock bindingBlock cellsBlock
    baseBlock cellsOffset baseOffset oldBinding oldCells oldBase different operationCode represented legalDst legalSrc
    dstLane srcLane effective widthHelper readerHelper aluHelper cells leftRead rightRead leftTag rightTag
    header native

end KProgFormal.ClightRefinement.X86AluNativeXorInputs
