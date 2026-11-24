import KProgFormal.ClightRefinement.X86AluXorInputs

namespace KProgFormal.ClightRefinement.X86AluXorShortcutInputs

def temps (binding op imm : CC.Val) (reg : Fin 16) (flags width : BitVec 8)
    (aux : BitVec 32) : CC.TempEnv :=
  let initial := X86RegisterView.writerInitialTemps binding op
    (X86Width.argument (X86RegisterReadValue.registerByte reg))
    (X86Width.argument (X86RegisterReadValue.registerByte reg)) (X86Width.argument flags)
    (.Vint aux) imm (X86Width.argument width)
  let ready := X86AluDecode.temps (X86AluEntry.widthTemps
    (initial.set X86_program_profile_bpf.___x86_l_width (X86Width.argument width)) flags) aux
  X86ShiftLeftSite.afterTemps (X86AluReadSelfXor.temps ready) (.Vlong (0#64))

/-- All six real byte-tail inputs survive the matched-register/lane shortcut;
its result is the original zero initialization followed by the actual ALU call. -/
theorem observations (binding op imm : CC.Val) (reg : Fin 16) (flags width : BitVec 8)
    (aux : BitVec 32) (size : X86.Size)
    (xorCode : (aux.setWidth 8).setWidth 32 = (2#32))
    (effective : X86Width.result flags = X86ShiftLeft.argument size) :
    X86AluXorInputs.Observed (temps binding op imm reg flags width aux) binding reg size
      ((aux >>> 8).setWidth 8) (0#64) := by
  refine ⟨?_, ?_, ?_, ?_, ?_, ?_⟩
  all_goals simp +decide [temps, X86ShiftLeftSite.afterTemps, X86AluReadSelfXor.temps,
    X86AluDecode.temps, X86AluEntry.widthTemps, X86RegisterView.writerInitialTemps,
    X86Width.argument, CC.PTree.gss, CC.PTree.gso, X86AluDecode.field_byte,
    BitVec.ushiftRight_zero, xorCode, effective]

/-- Genuine eight-argument matched XOR call reaches the flags stage in77
actual transitions and derives every tail observation, without a register
reader call or an assumed shortcut result. -/
theorem entry (ge : CC.CGenv) (caller : CC.Mem) (k : CC.Cont)
    (binding op imm : CC.Val) (reg : Fin 16) (flags width : BitVec 8) (aux : BitVec 32)
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
    InternalRun ge 77
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG)
        [binding, op, X86Width.argument (X86RegisterReadValue.registerByte reg),
          X86Width.argument (X86RegisterReadValue.registerByte reg), X86Width.argument flags,
          .Vint aux, imm, X86Width.argument width] k caller)
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG X86ShiftLeftRoute.flags
        (X86AluEntry.continuation k) (X86RegisterView.writerAllocation ge.genv_cenv caller).1
        (temps binding op imm reg flags width aux)
        (X86RegisterView.writerAllocation ge.genv_cenv caller).2) ∧
    X86AluXorInputs.Observed (temps binding op imm reg flags width aux) binding reg size
      ((aux >>> 8).setWidth 8) (0#64) := by
  exact ⟨X86AluXorResultEntry.shortcut_from_call ge caller k binding op imm
      (X86RegisterReadValue.registerByte reg) flags width aux size widthBlock aluBlock
      xorCode sameLane effective widthHelper aluHelper,
    observations binding op imm reg flags width aux size xorCode effective⟩

end KProgFormal.ClightRefinement.X86AluXorShortcutInputs
