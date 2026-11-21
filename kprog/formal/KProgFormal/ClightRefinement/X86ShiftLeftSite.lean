import KProgFormal.ClightRefinement.X86ShiftLeftAlu

namespace KProgFormal.ClightRefinement.X86ShiftLeftSite

def statement : CC.Stmt := X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_59

def afterTemps (le : CC.TempEnv) (value : CC.Val) : CC.TempEnv :=
  (le.set X86_program_profile_bpf._t'42 value).set X86_program_profile_bpf.___x86_l_result value

def length (size : X86.Size) : Nat := 2 + X86ShiftLeftAlu.length size + 3

private theorem signature : CC.typeOfFundef (.Internal X86_program_profile_bpf.f_x86_alu_result) =
    .Tfunction [CC.tulong, CC.tulong, CC.tuint, CC.tuchar] CC.tulong CC.cc_default := rfl

/-- The real ALU_REG arithmetic site enters its genuine ALU callee and resumes
to the same caller, locals and continuation with the exact two temporary writes. -/
private theorem plumbing (ge : CC.CGenv) (aluBlock : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_alu_result = some aluBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv aluBlock =
        some (.Internal X86_program_profile_bpf.f_x86_alu_result))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_alu_result = none)
    (lhs rhs : BitVec 64) (size : X86.Size)
    (left : le.get X86_program_profile_bpf.___x86_l_lhs = some (.Vlong lhs))
    (right : le.get X86_program_profile_bpf.___x86_l_rhs = some (.Vlong rhs))
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (5#32)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument size))
    (k : CC.Cont) (m : CC.Mem) :
    ∃ callK,
      InternalRun ge 2 (.State function statement k e le m)
        (.Callstate (.Internal X86_program_profile_bpf.f_x86_alu_result)
          (X86ShiftLeftAlu.arguments lhs rhs size) callK m) ∧
      ∀ value : CC.Val, InternalRun ge 3
        (.Returnstate value (CC.callCont callK) m)
        (.State function .Sskip k e (afterTemps le value) m) := by
  obtain ⟨symbol, callee⟩ := binding
  have width_arg : (BitVec.ofNat 32 size.bytes &&& (255#32)) = BitVec.ofNat 32 size.bytes := by
    cases size <;> decide
  refine ⟨?callK, ?beforeCall, ?afterCall⟩
  case beforeCall =>
    apply internalRun_of_steps
    · simp +decide [InternalPath, InternalState, statement, X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_59,
      CC.typeof, CC.tulong, CC.tuint, CC.tuchar, CC.cc_default, CC.doStep, CC.doEvalExpr,
      CC.doEvalExprlist, CC.lvalOfVar, CC.doDerefLoc, CC.accessMode, CC.Cop.classifyFun,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Genv.findFunct,
      CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero,
      unshadowed, left, right, operation, width, width_arg, symbol, callee, X86ShiftLeft.argument,
      CC.E0]
    · simp +decide [steps, statement, X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_59, CC.typeof, CC.tulong,
      CC.tuint, CC.tuchar, CC.cc_default, CC.doStep, CC.doEvalExpr, CC.doEvalExprlist, CC.lvalOfVar,
      CC.doDerefLoc, CC.accessMode, CC.Cop.classifyFun, CC.Cop.semCast, CC.Cop.classifyCast,
      CC.Cop.castIntInt, CC.Genv.findFunct, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
      CC.Integers.Ptrofs.zero, CC.Integers.MI.zero, unshadowed, left, right, operation, width,
      width_arg, symbol, callee, X86ShiftLeftAlu.arguments, X86ShiftLeft.argument, CC.Eapp, CC.E0]
      rfl
  case afterCall =>
    intro value
    apply internalRun_of_steps
    · simp +decide [InternalPath, InternalState, CC.doStep, CC.doEvalExpr, CC.callCont, CC.setOpttemp, CC.E0]
    · simp +decide [steps, afterTemps, CC.doStep, CC.doEvalExpr, CC.callCont, CC.setOpttemp, CC.Eapp, CC.E0]

/-- The actual source site returns the mature SHL result into its original caller. -/
theorem internal (ge : CC.CGenv) (aluBlock shiftBlock : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_alu_result = some aluBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv aluBlock =
        some (.Internal X86_program_profile_bpf.f_x86_alu_result))
    (shiftBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._kprog_x86_shl_result = some shiftBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv shiftBlock =
        some (.Internal X86_program_profile_bpf.f_kprog_x86_shl_result))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_alu_result = none)
    (lhs rhs : BitVec 64) (size : X86.Size)
    (left : le.get X86_program_profile_bpf.___x86_l_lhs = some (.Vlong lhs))
    (right : le.get X86_program_profile_bpf.___x86_l_rhs = some (.Vlong rhs))
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (5#32)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument size))
    (k : CC.Cont) (m : CC.Mem) :
    InternalRun ge (length size) (.State function statement k e le m)
      (.State function .Sskip k e (afterTemps le (X86ShiftLeft.result lhs rhs size)) m) := by
  obtain ⟨callK, beforeCall, afterCall⟩ :=
    plumbing ge aluBlock binding function e le unshadowed lhs rhs size left right operation width k m
  have arithmetic := X86ShiftLeftAlu.internal ge shiftBlock shiftBinding lhs rhs size callK m
  exact (beforeCall.trans arithmetic).trans (afterCall (X86ShiftLeft.result lhs rhs size))

/-- Complete relational source execution preserves caller locals and all memory. -/
theorem returns (ge : CC.CGenv) (aluBlock shiftBlock : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_alu_result = some aluBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv aluBlock =
        some (.Internal X86_program_profile_bpf.f_x86_alu_result))
    (shiftBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._kprog_x86_shl_result = some shiftBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv shiftBlock =
        some (.Internal X86_program_profile_bpf.f_kprog_x86_shl_result))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_alu_result = none)
    (lhs rhs : BitVec 64) (size : X86.Size)
    (left : le.get X86_program_profile_bpf.___x86_l_lhs = some (.Vlong lhs))
    (right : le.get X86_program_profile_bpf.___x86_l_rhs = some (.Vlong rhs))
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (5#32)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument size))
    (k : CC.Cont) (m : CC.Mem) :
    CC.Star (CC.Step2 ge) (.State function statement k e le m) CC.E0
      (.State function .Sskip k e (afterTemps le (X86ShiftLeft.result lhs rhs size)) m) :=
  (internal ge aluBlock shiftBlock binding shiftBinding function e le unshadowed
    lhs rhs size left right operation width k m).sound

/-- The result and call temporary read back exactly, while every other temporary retains its value. -/
theorem temps (le : CC.TempEnv) (value : CC.Val) :
    (afterTemps le value).get X86_program_profile_bpf.___x86_l_result = some value ∧
    (afterTemps le value).get X86_program_profile_bpf._t'42 = some value ∧
    ∀ id, id ≠ X86_program_profile_bpf.___x86_l_result →
      id ≠ X86_program_profile_bpf._t'42 → (afterTemps le value).get id = le.get id := by
  have distinct : X86_program_profile_bpf.___x86_l_result ≠ X86_program_profile_bpf._t'42 := by decide
  refine ⟨by simp [afterTemps], by simp [afterTemps, CC.PTree.gso, distinct], ?_⟩
  intro id result_ne call_ne
  simp [afterTemps, CC.PTree.gso, Ne.symm result_ne, Ne.symm call_ne]

end KProgFormal.ClightRefinement.X86ShiftLeftSite
