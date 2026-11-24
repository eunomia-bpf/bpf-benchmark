import KProgFormal.ClightRefinement.X86AluLogicInputs
import KProgFormal.ClightRefinement.X86AluNativeOperandsEntry
import KProgFormal.ClightRefinement.X86LogicSite

namespace KProgFormal.ClightRefinement.X86AluNativeLogicEntry

/-- Genuine OR/AND handler entry, both original ordinary/RSP reader calls, numerical
helper and caller resume reach the original flags stage with the exact selected logical
word. All intermediate observations are derived from the actual executions. -/
theorem from_call (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
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
    (isAnd : Bool)
    (operationCode : (aux.setWidth 8).setWidth 32 = (X86AluLogicResultEntry.code isAnd).setWidth 32)
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
    let initial := X86RegisterView.writerInitialTemps (.Vptr bindingBlock (0 : CC.Integers.Ptrofs)) op
      (X86Width.argument (X86RegisterReadValue.registerByte dst))
      (X86Width.argument (X86RegisterReadValue.registerByte src)) (X86Width.argument flags)
      (.Vint aux) imm (X86Width.argument width)
    let ready := X86AluDecode.temps (X86AluEntry.widthTemps
      (initial.set X86_program_profile_bpf.___x86_l_width (X86Width.argument width)) flags) aux
    let leftValue := cpu.getReg size (X86.GPR.ofIndex dst) highDst
    let rightValue := cpu.getReg size (X86.GPR.ofIndex src) highSrc
    InternalRun ge (37 + X86AluReadNativeOperands.length dst src size + 29)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG)
        [.Vptr bindingBlock (0 : CC.Integers.Ptrofs), op,
          X86Width.argument (X86RegisterReadValue.registerByte dst),
          X86Width.argument (X86RegisterReadValue.registerByte src), X86Width.argument flags,
          .Vint aux, imm, X86Width.argument width] k caller)
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG X86ShiftLeftRoute.flags
        (X86AluEntry.continuation k) (X86RegisterView.writerAllocation ge.genv_cenv caller).1
        (X86ShiftLeftSite.afterTemps (X86AluReadNativeOperands.temps ready leftValue rightValue)
          (.Vlong (X86AluLogicResultEntry.result isAnd leftValue rightValue)))
        (X86RegisterView.writerAllocation ge.genv_cenv caller).2) := by
  dsimp only
  let initial := X86RegisterView.writerInitialTemps (.Vptr bindingBlock (0 : CC.Integers.Ptrofs)) op
    (X86Width.argument (X86RegisterReadValue.registerByte dst))
    (X86Width.argument (X86RegisterReadValue.registerByte src)) (X86Width.argument flags)
    (.Vint aux) imm (X86Width.argument width)
  let afterWidth := X86AluEntry.widthTemps
    (initial.set X86_program_profile_bpf.___x86_l_width (X86Width.argument width)) flags
  let ready := X86AluDecode.temps afterWidth aux
  let leftValue := cpu.getReg size (X86.GPR.ofIndex dst) highDst
  let rightValue := cpu.getReg size (X86.GPR.ofIndex src) highSrc
  let operands := X86AluReadNativeOperands.temps ready leftValue rightValue
  have lhs : operands.get X86_program_profile_bpf.___x86_l_lhs = some (.Vlong leftValue) :=
    (X86AluReadNativeOperands.observations ready leftValue rightValue).1
  have rhs : operands.get X86_program_profile_bpf.___x86_l_rhs = some (.Vlong rightValue) :=
    (X86AluReadNativeOperands.observations ready leftValue rightValue).2.1
  have readyOperation : ready.get X86_program_profile_bpf.___x86_l_alu = some (.Vint ((X86AluLogicResultEntry.code isAnd).setWidth 32)) := by
    simpa only [ready, X86AluDecode.field_byte, BitVec.ushiftRight_zero, operationCode] using
      (X86AluDecode.observations afterWidth aux).1
  have readyWidth : ready.get X86_program_profile_bpf.___x86_l_width__1 =
      some (X86ShiftLeft.argument size) := by
    simpa +decide [ready, afterWidth, X86AluDecode.temps, X86AluEntry.widthTemps,
      CC.PTree.gss, CC.PTree.gso] using congrArg some effective
  have operation : operands.get X86_program_profile_bpf.___x86_l_alu =
      some (.Vint ((X86AluLogicResultEntry.code isAnd).setWidth 32)) := by
    exact (X86AluReadNativeOperands.observations ready leftValue rightValue).2.2.1.trans readyOperation
  have resolvedWidth : operands.get X86_program_profile_bpf.___x86_l_width__1 =
      some (X86ShiftLeft.argument size) := by
    exact (X86AluReadNativeOperands.observations ready leftValue rightValue).2.2.2.trans readyWidth
  have different : (aux.setWidth 8).setWidth 32 ≠ (2#32) := by
    rw [operationCode]
    cases isAnd <;> decide
  have notLocal : X86_program_profile_bpf._x86_alu_result ∉
      CC.varNames X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_vars := by
    decide +kernel
  have unshadowed : (X86RegisterView.writerAllocation ge.genv_cenv caller).1.get
      X86_program_profile_bpf._x86_alu_result = none := by
    simpa only [CC.emptyEnv, CC.PTree.gempty] using CC.allocVariables_env_other
      (CC.doAllocVariables_sound _ _ _ _ _ _
        (Prod.eta (X86RegisterView.writerAllocation ge.genv_cenv caller)).symm) notLocal
  have reads := X86AluNativeOperandsEntry.from_call ge layout valueLayout addresses origins cpu
    caller k op imm dst src flags width aux size highDst highSrc left right
    widthBlock readerBlock bindingBlock cellsBlock baseBlock cellsOffset baseOffset
    oldBinding oldCells oldBase different represented legalDst legalSrc dstLane srcLane
    effective widthHelper readerHelper cells leftRead rightRead leftTag rightTag header native
  have numerical := X86LogicSite.to_flags ge aluBlock aluHelper
    X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG
    (X86RegisterView.writerAllocation ge.genv_cenv caller).1 operands unshadowed
    leftValue rightValue size lhs rhs resolvedWidth (X86AluEntry.continuation k)
    (X86RegisterView.writerAllocation ge.genv_cenv caller).2
    (X86AluLogicResultEntry.code isAnd) (X86AluLogicResultEntry.result isAnd leftValue rightValue) operation (by
      cases isAnd
      · exact .inr (.inl ⟨rfl, rfl⟩)
      · exact .inr (.inr ⟨rfl, rfl⟩))
  exact reads.trans numerical

end KProgFormal.ClightRefinement.X86AluNativeLogicEntry
