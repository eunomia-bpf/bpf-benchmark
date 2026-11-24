import KProgFormal.ClightRefinement.X86AluReadNativeXorOperands

namespace KProgFormal.ClightRefinement.X86AluNativeXorOperandsEntry

private theorem resolved_width (flags : BitVec 8) :
    X86Width.result (if flags == 0 then 8 else flags) = X86Width.result flags := by
  by_cases zero : flags = (0#8) <;> simp [X86Width.result, zero]

/-- From the original eight handler arguments, real entry/allocation, width
resolution, aux decoding and both complete ordinary/RSP distinct-XOR reads reach the original
arithmetic dispatcher. All required post-entry heap reads are derived from
the caller's representation and real memory by the allocation frame theorem. -/
theorem from_call (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (cpu : X86.Cpu)
    (caller : CC.Mem) (k : CC.Cont) (op imm : CC.Val) (dst src : Fin 16)
    (flags width : BitVec 8) (aux : BitVec 32) (size : X86.Size) (highDst highSrc : Bool)
    (left right : BitVec 64) (widthBlock readerBlock bindingBlock cellsBlock baseBlock : CC.Block)
    (cellsOffset baseOffset : CC.Integers.Ptrofs)
    (oldBinding : bindingBlock.toNat < caller.nextblock.toNat)
    (oldCells : cellsBlock.toNat < caller.nextblock.toNat)
    (oldBase : baseBlock.toNat < caller.nextblock.toNat)
    (different : dst ≠ src)
    (xorCode : (aux.setWidth 8).setWidth 32 = (2#32))
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
    InternalRun ge (37 + X86AluReadNativeXorOperands.length dst src size)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG)
        [.Vptr bindingBlock (0 : CC.Integers.Ptrofs), op,
          X86Width.argument (X86RegisterReadValue.registerByte dst),
          X86Width.argument (X86RegisterReadValue.registerByte src), X86Width.argument flags,
          .Vint aux, imm, X86Width.argument width] k caller)
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG X86ShiftLeftRoute.dispatch
        (X86AluEntry.continuation k) (X86RegisterView.writerAllocation ge.genv_cenv caller).1
        (X86AluReadNativeXorOperands.temps ready
          (cpu.getReg size (X86.GPR.ofIndex dst) highDst)
          (cpu.getReg size (X86.GPR.ofIndex src) highSrc))
        (X86RegisterView.writerAllocation ge.genv_cenv caller).2) := by
  dsimp only
  let initial := X86RegisterView.writerInitialTemps (.Vptr bindingBlock (0 : CC.Integers.Ptrofs)) op
    (X86Width.argument (X86RegisterReadValue.registerByte dst))
    (X86Width.argument (X86RegisterReadValue.registerByte src)) (X86Width.argument flags)
    (.Vint aux) imm (X86Width.argument width)
  let afterWidth := X86AluEntry.widthTemps
    (initial.set X86_program_profile_bpf.___x86_l_width (X86Width.argument width)) flags
  let ready := X86AluDecode.temps afterWidth aux
  have opRead : ready.get X86_program_profile_bpf.___x86_l_alu =
      some (.Vint ((aux.setWidth 8).setWidth 32)) := by
    simpa only [ready, X86AluDecode.field_byte, BitVec.ushiftRight_zero] using
      (X86AluDecode.observations afterWidth aux).1
  have dstShift : ready.get X86_program_profile_bpf.___x86_l_dst_shift =
      some (X86Width.argument (if highDst then 8 else 0)) := by
    simpa only [ready, X86Width.argument, X86AluDecode.field_byte, dstLane] using
      (X86AluDecode.observations afterWidth aux).2.1
  have srcShift : ready.get X86_program_profile_bpf.___x86_l_src_shift =
      some (X86Width.argument (if highSrc then 8 else 0)) := by
    simpa only [ready, X86Width.argument, X86AluDecode.field_byte, srcLane] using
      (X86AluDecode.observations afterWidth aux).2.2.1
  have binding : ready.get X86_program_profile_bpf.___x86_bind =
      some (.Vptr bindingBlock (0 : CC.Integers.Ptrofs)) := by
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
  have entry := X86AluDecode.from_call ge caller k (.Vptr bindingBlock (0 : CC.Integers.Ptrofs)) op
    (X86Width.argument (X86RegisterReadValue.registerByte dst))
    (X86Width.argument (X86RegisterReadValue.registerByte src)) imm aux flags width widthBlock widthHelper
  have allocatedRegisters : X86RegisterView.RegistersRepresent addresses origins
      (X86RegisterView.writerAllocation ge.genv_cenv caller).2 cellsBlock cellsOffset cpu := by
    intro index
    obtain ⟨word, raw, tag, wordRead, tagRead, rep, view⟩ := represented index
    exact ⟨word, raw, tag, (frame.load _ _ _ oldCells).trans wordRead,
      (frame.load _ _ _ oldCells).trans tagRead, rep, view⟩
  exact entry.trans (X86AluReadNativeXorOperands.read ge layout valueLayout addresses origins cpu
    X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG
      (X86RegisterView.writerAllocation ge.genv_cenv caller).1 ready (X86AluEntry.continuation k)
      (X86RegisterView.writerAllocation ge.genv_cenv caller).2
      (if flags == 0 then 8 else flags) highDst highSrc size dst src left right
      widthBlock readerBlock bindingBlock cellsBlock baseBlock cellsOffset baseOffset different
      allocatedRegisters legalDst legalSrc ((resolved_width flags).trans effective)
      widthHelper readerHelper unshadowed (by simpa only [xorCode] using opRead) binding destination sourceReg widthRead dstShift srcShift
      ((frame.load _ _ _ oldBinding).trans cells)
      ((frame.load _ _ _ oldCells).trans leftRead) ((frame.load _ _ _ oldCells).trans rightRead)
      (fun notSp => (frame.load _ _ _ oldCells).trans (leftTag notSp))
      (fun notSp => (frame.load _ _ _ oldCells).trans (rightTag notSp))
      ((frame.load _ _ _ oldBinding).trans header) ((frame.load _ _ _ oldBase).trans native))

end KProgFormal.ClightRefinement.X86AluNativeXorOperandsEntry
