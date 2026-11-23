import KProgFormal.ClightRefinement.X86AluReadXorOperands

namespace KProgFormal.ClightRefinement.X86AluXorOperandsEntry

private theorem resolved_width (flags : BitVec 8) :
    X86Width.result (if flags == 0 then 8 else flags) = X86Width.result flags := by
  by_cases zero : flags = (0#8) <;> simp [X86Width.result, zero]

/-- From the original eight handler arguments, real entry/allocation, width
resolution, aux decoding and both complete scalar XOR reads reach the original
arithmetic dispatcher. All required post-entry heap reads are derived from
the caller's word/tag observations by the actual allocation frame theorem. -/
theorem from_call (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (caller : CC.Mem) (k : CC.Cont) (op imm : CC.Val) (dst src : Fin 16)
    (flags width tagDst tagSrc : BitVec 8) (aux : BitVec 32) (size : X86.Size)
    (left right : BitVec 64) (widthBlock readerBlock bindingBlock cellsBlock : CC.Block)
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
    InternalRun ge (37 + X86AluReadOperands.length size)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG)
        [.Vptr bindingBlock bindingOffset, op,
          X86Width.argument (X86RegisterReadValue.registerByte dst),
          X86Width.argument (X86RegisterReadValue.registerByte src), X86Width.argument flags,
          .Vint aux, imm, X86Width.argument width] k caller)
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG X86ShiftLeftRoute.dispatch
        (X86AluEntry.continuation k) (X86RegisterView.writerAllocation ge.genv_cenv caller).1
        (X86AluReadXorOperands.temps ready dst src
          (X86RegisterReadLanes.result left size ((aux >>> 8).setWidth 8))
          (X86RegisterReadLanes.result right size ((aux >>> 16).setWidth 8)))
        (X86RegisterView.writerAllocation ge.genv_cenv caller).2) := by
  dsimp only
  let initial := X86RegisterView.writerInitialTemps (.Vptr bindingBlock bindingOffset) op
    (X86Width.argument (X86RegisterReadValue.registerByte dst))
    (X86Width.argument (X86RegisterReadValue.registerByte src)) (X86Width.argument flags)
    (.Vint aux) imm (X86Width.argument width)
  let afterWidth := X86AluEntry.widthTemps
    (initial.set X86_program_profile_bpf.___x86_l_width (X86Width.argument width)) flags
  let ready := X86AluDecode.temps afterWidth aux
  have opRead : ready.get X86_program_profile_bpf.___x86_l_alu =
      some (.Vint (2#32)) := by
    simpa only [ready, X86AluDecode.field_byte, BitVec.ushiftRight_zero, xorCode] using
      (X86AluDecode.observations afterWidth aux).1
  have dstShift : ready.get X86_program_profile_bpf.___x86_l_dst_shift =
      some (X86Width.argument ((aux >>> 8).setWidth 8)) := by
    simpa only [ready, X86Width.argument, X86AluDecode.field_byte] using
      (X86AluDecode.observations afterWidth aux).2.1
  have srcShift : ready.get X86_program_profile_bpf.___x86_l_src_shift =
      some (X86Width.argument ((aux >>> 16).setWidth 8)) := by
    simpa only [ready, X86Width.argument, X86AluDecode.field_byte] using
      (X86AluDecode.observations afterWidth aux).2.2.1
  have binding : ready.get X86_program_profile_bpf.___x86_bind =
      some (.Vptr bindingBlock bindingOffset) := by
    simp +decide [ready, afterWidth, initial, X86AluDecode.temps, X86AluEntry.widthTemps,
      X86RegisterView.writerInitialTemps, CC.PTree.gss, CC.PTree.gso]
  have destination : ready.get X86_program_profile_bpf._dst =
      some (X86Width.argument (X86RegisterReadValue.registerByte dst)) := by
    simp +decide [ready, afterWidth, initial, X86AluDecode.temps, X86AluEntry.widthTemps,
      X86RegisterView.writerInitialTemps, CC.PTree.gss, CC.PTree.gso]
  have sourceReg : ready.get X86_program_profile_bpf._src =
      some (X86Width.argument (X86RegisterReadValue.registerByte src)) := by
    simp +decide [ready, afterWidth, initial, X86AluDecode.temps, X86AluEntry.widthTemps,
      X86RegisterView.writerInitialTemps, CC.PTree.gss, CC.PTree.gso]
  have widthRead : ready.get X86_program_profile_bpf.___x86_l_width__1 =
      some (X86Width.argument (if flags == 0 then 8 else flags)) := by
    simp +decide [ready, afterWidth, X86AluDecode.temps, X86AluEntry.widthTemps,
      X86Width.result, CC.PTree.gss, CC.PTree.gso]
  have notLocal : X86_program_profile_bpf._x86_sim_inline_read_reg ∉
      CC.varNames X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_vars := by
    decide +kernel
  have unshadowed : (X86RegisterView.writerAllocation ge.genv_cenv caller).1.get
      X86_program_profile_bpf._x86_sim_inline_read_reg = none := by
    simpa only [CC.emptyEnv, CC.PTree.gempty] using CC.allocVariables_env_other
      (CC.doAllocVariables_sound _ _ _ _ _ _
        (Prod.eta (X86RegisterView.writerAllocation ge.genv_cenv caller)).symm) notLocal
  have frame := X86RegisterView.writer_caller_frame ge.genv_cenv caller
  have entry := X86AluDecode.from_call ge caller k (.Vptr bindingBlock bindingOffset) op
    (X86Width.argument (X86RegisterReadValue.registerByte dst))
    (X86Width.argument (X86RegisterReadValue.registerByte src)) imm aux flags width widthBlock widthHelper
  exact entry.trans (X86AluReadXorOperands.read ge layout
    X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG
      (X86RegisterView.writerAllocation ge.genv_cenv caller).1 ready (X86AluEntry.continuation k)
      (X86RegisterView.writerAllocation ge.genv_cenv caller).2
      (if flags == 0 then 8 else flags)
      ((aux >>> 8).setWidth 8) ((aux >>> 16).setWidth 8) tagDst tagSrc size dst src left right
      widthBlock readerBlock bindingBlock cellsBlock bindingOffset cellsOffset different
      ordinaryDst ordinarySrc notStackDst notStackSrc boundDst boundSrc
      ((resolved_width flags).trans effective) widthHelper readerHelper unshadowed opRead binding
      destination sourceReg widthRead dstShift srcShift
      ((frame.load _ _ _ oldBinding).trans cells)
      ((frame.load _ _ _ oldCells).trans leftRead) ((frame.load _ _ _ oldCells).trans rightRead)
      ((frame.load _ _ _ oldCells).trans leftTag) ((frame.load _ _ _ oldCells).trans rightTag))

end KProgFormal.ClightRefinement.X86AluXorOperandsEntry
