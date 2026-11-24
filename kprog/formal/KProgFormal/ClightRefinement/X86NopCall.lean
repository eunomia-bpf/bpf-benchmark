import KProgFormal.ClightRefinement.X86RegisterView

namespace KProgFormal.ClightRefinement.X86NopCall

def handler : CC.Function := X86_program_profile_bpf.f_x86_sim_inline_arm_DISP_NOP

def initialTemps (binding op dst src flags aux imm width : CC.Val) : CC.TempEnv :=
  ((((((((CC.createUndefTemps handler.fn_temps).set
    X86_program_profile_bpf.___x86_bind binding).set X86_program_profile_bpf._op op).set
    X86_program_profile_bpf._dst dst).set X86_program_profile_bpf._src src).set
    X86_program_profile_bpf._flags flags).set X86_program_profile_bpf._aux aux).set
    X86_program_profile_bpf._imm imm).set X86_program_profile_bpf._width width

private theorem declarations : CC.listNorepet (CC.varNames handler.fn_vars) ∧
    CC.listNorepet (CC.varNames handler.fn_params) ∧
    CC.listDisjoint (CC.varNames handler.fn_params) (CC.varNames handler.fn_temps) := by decide +kernel

private theorem byte_cast (value : BitVec 8) :
    value.setWidth 32 &&& (255#32) = value.setWidth 32 := by
  change value.setWidth 32 &&& (BitVec.allOnes 8).setWidth 32 = value.setWidth 32
  rw [← BitVec.setWidth_and, BitVec.and_allOnes]

/-- Actual function entry binds every original argument and allocates no local
memory. Unused operands may include arbitrary pointers or undefined values. -/
theorem entry (ge : CC.CGenv) (memory : CC.Mem)
    (binding op dst src flags aux imm width : CC.Val) :
    CC.FunctionEntry2 ge handler [binding, op, dst, src, flags, aux, imm, width] memory CC.emptyEnv
      (initialTemps binding op dst src flags aux imm width) memory :=
  .intro declarations.1 declarations.2.1 declarations.2.2 (.nil _ _) rfl

/-- The complete genuine NOP call enters the original exported handler,
executes its width assignment and loop, then returns with the identical heap.
No register, flag, provenance, memory or unused-operand domain is excluded. -/
theorem execute (ge : CC.CGenv) (memory : CC.Mem) (k : CC.Cont)
    (binding op dst src flags aux imm : CC.Val) (width : BitVec 8)
    (boundary : CC.isCallCont k = true) :
    InternalRun ge 6
      (.Callstate (.Internal handler) [binding, op, dst, src, flags, aux, imm, .Vint (width.setWidth 32)] k memory)
      (.Returnstate .Vundef k memory) := by
  let initial := initialTemps binding op dst src flags aux imm (.Vint (width.setWidth 32))
  have entered : InternalRun ge 1
      (.Callstate (.Internal handler) [binding, op, dst, src, flags, aux, imm, .Vint (width.setWidth 32)] k memory)
      (.State handler handler.fn_body k CC.emptyEnv initial memory) :=
    .step trivial (.internal_function _ _ _ _ _ _ _
      (entry ge memory binding op dst src flags aux imm (.Vint (width.setWidth 32)))) (.refl _)
  have freed : CC.Mem.freeList memory (CC.blocksOfEnv ge.genv_cenv CC.emptyEnv) = some memory := rfl
  have body : InternalRun ge 5 (.State handler handler.fn_body k CC.emptyEnv initial memory)
      (.Returnstate .Vundef k memory) := by
    cases k <;> simp only [CC.isCallCont, Bool.false_eq_true] at boundary
    all_goals apply internalRun_of_steps
    all_goals simp +decide [steps, InternalPath, InternalState, handler,
      X86_program_profile_bpf.f_x86_sim_inline_arm_DISP_NOP, initial, initialTemps,
      CC.doStep, CC.doEvalExpr, CC.typeof, CC.PTree.gss, CC.PTree.gso,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
      CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.tuchar, byte_cast,
      freed,
      CC.callCont, CC.Eapp, CC.E0]
  exact entered.trans body

end KProgFormal.ClightRefinement.X86NopCall
