import KProgFormal.ClightRefinement.X86AluXorOperandsEntry
import KProgFormal.ClightRefinement.X86LogicSite

namespace KProgFormal.ClightRefinement.X86AluXorResultEntry

/-- Genuine XOR handler entry, both original scalar reader calls, numerical
helper and caller resume reach the original flags stage with the exact XOR
word. All intermediate observations are derived from the actual executions. -/
theorem from_call (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (caller : CC.Mem) (k : CC.Cont) (op imm : CC.Val) (dst src : Fin 16)
    (flags width tagDst tagSrc : BitVec 8) (aux : BitVec 32) (size : X86.Size)
    (left right : BitVec 64) (widthBlock readerBlock aluBlock bindingBlock cellsBlock : CC.Block)
    (bindingOffset cellsOffset : CC.Integers.Ptrofs)
    (oldBinding : bindingBlock.toNat < caller.nextblock.toNat)
    (oldCells : cellsBlock.toNat < caller.nextblock.toNat)
    (xorCode : (aux.setWidth 8).setWidth 32 = (2#32))
    (different : dst ≠ src ∨ (aux >>> 8).setWidth 8 ≠ (aux >>> 16).setWidth 8)
    (ordinaryDst : dst ≠ 4) (ordinarySrc : src ≠ 4)
    (notStackDst : tagDst ≠ (4#8)) (notStackSrc : tagSrc ≠ (4#8))
    (boundDst : ((aux >>> 8).setWidth 8).toNat < 64)
    (boundSrc : ((aux >>> 16).setWidth 8).toNat < 64)
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
    (cells : CC.Mem.load CC.Mptr caller bindingBlock (CC.Integers.Ptrofs.unsigned bindingOffset) =
      some (.Vptr cellsBlock cellsOffset))
    (leftRead : CC.Mem.load CC.Mptr caller cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (dst.val : Int)))) =
        some (.Vlong left))
    (rightRead : CC.Mem.load CC.Mptr caller cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (src.val : Int)))) =
        some (.Vlong right))
    (leftTag : CC.Mem.load .Mint8unsigned caller cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * (dst.val : Int))) + 8)) =
        some (X86Width.argument tagDst))
    (rightTag : CC.Mem.load .Mint8unsigned caller cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * (src.val : Int))) + 8)) =
        some (X86Width.argument tagSrc)) :
    let initial := X86RegisterView.writerInitialTemps (.Vptr bindingBlock bindingOffset) op
      (X86Width.argument (X86RegisterReadValue.registerByte dst))
      (X86Width.argument (X86RegisterReadValue.registerByte src)) (X86Width.argument flags)
      (.Vint aux) imm (X86Width.argument width)
    let ready := X86AluDecode.temps (X86AluEntry.widthTemps
      (initial.set X86_program_profile_bpf.___x86_l_width (X86Width.argument width)) flags) aux
    let leftValue := X86RegisterReadLanes.result left size ((aux >>> 8).setWidth 8)
    let rightValue := X86RegisterReadLanes.result right size ((aux >>> 16).setWidth 8)
    InternalRun ge (37 + X86AluReadOperands.length size + 29)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG)
        [.Vptr bindingBlock bindingOffset, op,
          X86Width.argument (X86RegisterReadValue.registerByte dst),
          X86Width.argument (X86RegisterReadValue.registerByte src), X86Width.argument flags,
          .Vint aux, imm, X86Width.argument width] k caller)
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG X86ShiftLeftRoute.flags
        (X86AluEntry.continuation k) (X86RegisterView.writerAllocation ge.genv_cenv caller).1
        (X86ShiftLeftSite.afterTemps (X86AluReadXorOperands.temps ready dst src leftValue rightValue)
          (.Vlong (leftValue ^^^ rightValue)))
        (X86RegisterView.writerAllocation ge.genv_cenv caller).2) := by
  dsimp only
  let initial := X86RegisterView.writerInitialTemps (.Vptr bindingBlock bindingOffset) op
    (X86Width.argument (X86RegisterReadValue.registerByte dst))
    (X86Width.argument (X86RegisterReadValue.registerByte src)) (X86Width.argument flags)
    (.Vint aux) imm (X86Width.argument width)
  let afterWidth := X86AluEntry.widthTemps
    (initial.set X86_program_profile_bpf.___x86_l_width (X86Width.argument width)) flags
  let ready := X86AluDecode.temps afterWidth aux
  let leftValue := X86RegisterReadLanes.result left size ((aux >>> 8).setWidth 8)
  let rightValue := X86RegisterReadLanes.result right size ((aux >>> 16).setWidth 8)
  let operands := X86AluReadXorOperands.temps ready dst src leftValue rightValue
  have lhs : operands.get X86_program_profile_bpf.___x86_l_lhs = some (.Vlong leftValue) := by
    simp +decide [operands, X86AluReadXorOperands.temps, X86AluReadTail.temps,
      X86AluReadRhs.temps, X86AluReadSite.lhsTemps, CC.PTree.gss, CC.PTree.gso]
  have rhs : operands.get X86_program_profile_bpf.___x86_l_rhs = some (.Vlong rightValue) := by
    simp +decide [operands, X86AluReadXorOperands.temps, X86AluReadTail.temps,
      X86AluReadRhs.temps, X86AluReadSite.lhsTemps, CC.PTree.gss, CC.PTree.gso]
  have readyOperation : ready.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (2#32)) := by
    simpa only [ready, X86AluDecode.field_byte, BitVec.ushiftRight_zero, xorCode] using
      (X86AluDecode.observations afterWidth aux).1
  have readyWidth : ready.get X86_program_profile_bpf.___x86_l_width__1 =
      some (X86ShiftLeft.argument size) := by
    simpa +decide [ready, afterWidth, X86AluDecode.temps, X86AluEntry.widthTemps,
      CC.PTree.gss, CC.PTree.gso] using congrArg some effective
  have operation : operands.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (2#32)) := by
    by_cases same : dst = src <;>
      simp +decide [operands, X86AluReadXorOperands.temps, X86AluReadTail.temps,
        X86AluReadRhs.temps, X86AluReadSite.lhsTemps, X86AluReadXorOperands.selectedTemps,
        same, X86AluReadXorSelect.differentLaneTemps, X86AluReadSite.selectedTemps,
        CC.PTree.gss, CC.PTree.gso, readyOperation]
  have resolvedWidth : operands.get X86_program_profile_bpf.___x86_l_width__1 =
      some (X86ShiftLeft.argument size) := by
    by_cases same : dst = src <;>
      simp +decide [operands, X86AluReadXorOperands.temps, X86AluReadTail.temps,
        X86AluReadRhs.temps, X86AluReadSite.lhsTemps, X86AluReadXorOperands.selectedTemps,
        same, X86AluReadXorSelect.differentLaneTemps, X86AluReadSite.selectedTemps,
        CC.PTree.gss, CC.PTree.gso, readyWidth]
  have notLocal : X86_program_profile_bpf._x86_alu_result ∉
      CC.varNames X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_vars := by
    decide +kernel
  have unshadowed : (X86RegisterView.writerAllocation ge.genv_cenv caller).1.get
      X86_program_profile_bpf._x86_alu_result = none := by
    simpa only [CC.emptyEnv, CC.PTree.gempty] using CC.allocVariables_env_other
      (CC.doAllocVariables_sound _ _ _ _ _ _
        (Prod.eta (X86RegisterView.writerAllocation ge.genv_cenv caller)).symm) notLocal
  have reads := X86AluXorOperandsEntry.from_call ge layout caller k op imm dst src
    flags width tagDst tagSrc aux size left right widthBlock readerBlock bindingBlock cellsBlock
    bindingOffset cellsOffset oldBinding oldCells xorCode different ordinaryDst ordinarySrc
    notStackDst notStackSrc boundDst boundSrc effective widthHelper readerHelper
    cells leftRead rightRead leftTag rightTag
  have numerical := X86LogicSite.xor_to_flags ge aluBlock aluHelper
    X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG
    (X86RegisterView.writerAllocation ge.genv_cenv caller).1 operands unshadowed
    leftValue rightValue size lhs rhs resolvedWidth (X86AluEntry.continuation k)
    (X86RegisterView.writerAllocation ge.genv_cenv caller).2 operation
  exact reads.trans numerical

/-- The genuine matched-register/lane XOR shortcut reaches the real flags
stage in77 steps, with exact numerical result zero for every binding value. -/
theorem shortcut_from_call (ge : CC.CGenv) (caller : CC.Mem) (k : CC.Cont)
    (binding op imm : CC.Val) (reg flags width : BitVec 8) (aux : BitVec 32)
    (size : X86.Size) (widthBlock aluBlock : CC.Block)
    (xorCode : (aux.setWidth 8).setWidth 32 = (2#32))
    (sameLane : (aux >>> 16).setWidth 8 = (aux >>> 8).setWidth 8)
    (effective : X86Width.result flags = X86ShiftLeft.argument size)
    (widthHelper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective =
        some widthBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv widthBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (aluHelper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_alu_result =
        some aluBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv aluBlock =
        some (.Internal X86_program_profile_bpf.f_x86_alu_result)) :
    let initial := X86RegisterView.writerInitialTemps binding op
      (X86Width.argument reg) (X86Width.argument reg) (X86Width.argument flags)
      (.Vint aux) imm (X86Width.argument width)
    let ready := X86AluDecode.temps (X86AluEntry.widthTemps
      (initial.set X86_program_profile_bpf.___x86_l_width (X86Width.argument width)) flags) aux
    InternalRun ge 77
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG)
        [binding, op, X86Width.argument reg, X86Width.argument reg, X86Width.argument flags,
          .Vint aux, imm, X86Width.argument width] k caller)
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG X86ShiftLeftRoute.flags
        (X86AluEntry.continuation k) (X86RegisterView.writerAllocation ge.genv_cenv caller).1
        (X86ShiftLeftSite.afterTemps (X86AluReadSelfXor.temps ready) (.Vlong (0#64)))
        (X86RegisterView.writerAllocation ge.genv_cenv caller).2) := by
  dsimp only
  let initial := X86RegisterView.writerInitialTemps binding op
    (X86Width.argument reg) (X86Width.argument reg) (X86Width.argument flags)
    (.Vint aux) imm (X86Width.argument width)
  let afterWidth := X86AluEntry.widthTemps
    (initial.set X86_program_profile_bpf.___x86_l_width (X86Width.argument width)) flags
  let ready := X86AluDecode.temps afterWidth aux
  let selected := X86AluReadSelfXor.temps ready
  have zeroes := X86AluReadSelfXor.zeroes afterWidth aux
  have readyOperation : ready.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (2#32)) := by
    simpa only [ready, X86AluDecode.field_byte, BitVec.ushiftRight_zero, xorCode] using
      (X86AluDecode.observations afterWidth aux).1
  have operation : selected.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (2#32)) := by
    simp +decide [selected, X86AluReadSelfXor.temps, CC.PTree.gso, readyOperation]
  have resolvedWidth : selected.get X86_program_profile_bpf.___x86_l_width__1 =
      some (X86ShiftLeft.argument size) := by
    simpa +decide [selected, ready, afterWidth, X86AluReadSelfXor.temps, X86AluDecode.temps,
      X86AluEntry.widthTemps, CC.PTree.gss, CC.PTree.gso] using congrArg some effective
  have notLocal : X86_program_profile_bpf._x86_alu_result ∉
      CC.varNames X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_vars := by
    decide +kernel
  have unshadowed : (X86RegisterView.writerAllocation ge.genv_cenv caller).1.get
      X86_program_profile_bpf._x86_alu_result = none := by
    simpa only [CC.emptyEnv, CC.PTree.gempty] using CC.allocVariables_env_other
      (CC.doAllocVariables_sound _ _ _ _ _ _
        (Prod.eta (X86RegisterView.writerAllocation ge.genv_cenv caller)).symm) notLocal
  have shortcut := X86AluReadSelfXor.from_call ge caller k binding op imm reg flags width aux
    widthBlock xorCode sameLane widthHelper
  have numerical := X86LogicSite.xor_to_flags ge aluBlock aluHelper
    X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG
    (X86RegisterView.writerAllocation ge.genv_cenv caller).1 selected unshadowed
    (0#64) (0#64) size zeroes.1 zeroes.2 resolvedWidth (X86AluEntry.continuation k)
    (X86RegisterView.writerAllocation ge.genv_cenv caller).2 operation
  simpa only [BitVec.xor_self] using shortcut.trans numerical

end KProgFormal.ClightRefinement.X86AluXorResultEntry
