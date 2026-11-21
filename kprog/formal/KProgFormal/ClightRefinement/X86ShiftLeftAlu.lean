import KProgFormal.ClightRefinement.X86ShiftLeft

namespace KProgFormal.ClightRefinement.X86ShiftLeftAlu
open X86ShiftLeft (argument result)

def arguments (lhs rhs : BitVec 64) (size : X86.Size) : List CC.Val :=
  [.Vlong lhs, .Vlong rhs, .Vint (5#32), argument size]

def length (size : X86.Size) : Nat := 12 + X86ShiftLeft.length size + 12

private theorem signature : CC.typeOfFundef
    (.Internal X86_program_profile_bpf.f_kprog_x86_shl_result) =
    .Tfunction [CC.tulong, CC.tulong, CC.tuchar] CC.tulong CC.cc_default := rfl

/-- The actual ALU switch selects its SHL call and resumes through the original
assignment, switch break, loop break and return for every result word. -/
private theorem plumbing (ge : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._kprog_x86_shl_result = some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block =
        some (.Internal X86_program_profile_bpf.f_kprog_x86_shl_result))
    (lhs rhs : BitVec 64) (size : X86.Size) (k : CC.Cont) (m : CC.Mem) :
    ∃ callK,
      InternalRun ge 12
        (.Callstate (.Internal X86_program_profile_bpf.f_x86_alu_result) (arguments lhs rhs size) k m)
        (.Callstate (.Internal X86_program_profile_bpf.f_kprog_x86_shl_result)
          [.Vlong lhs, .Vlong rhs, argument size] callK m) ∧
      ∀ value : BitVec 64, InternalRun ge 12
        (.Returnstate (.Vlong value) (CC.callCont callK) m)
        (.Returnstate (.Vlong value) (CC.callCont k) m) := by
  obtain ⟨symbol, callee⟩ := binding
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  have width_arg : (BitVec.ofNat 32 size.bytes &&& (255#32)) = BitVec.ofNat 32 size.bytes := by
    cases size <;> decide
  refine ⟨?callK, ?beforeCall, ?afterCall⟩
  case beforeCall =>
    apply internalRun_of_steps
    · simp +decide [InternalPath, InternalState, width_arg, CC.PTree.gso, CC.typeof, CC.tuchar, CC.tuint, CC.tint,
      CC.tulong, CC.cc_default, arguments, CC.doStep, CC.doFunctionEntry2,
      X86_program_profile_bpf.f_x86_alu_result, CC.doAllocVariables, CC.bindParameterTemps,
      CC.createUndefTemps, CC.doEvalExpr, CC.doEvalExprlist, CC.Cop.semSwitchArg,
      CC.Cop.classifySwitch, CC.Cop.classifyFun, CC.selectSwitch, CC.selectSwitchCase,
      CC.seqOfLabeledStatement, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
      CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Integers.Int.unsigned, CC.Integers.MI.unsigned,
      CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.lvalOfVar, CC.doDerefLoc, CC.accessMode,
      CC.Genv.findFunct, symbol, callee, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero, CC.E0,
      CC.emptyEnv, X86ShiftLeft.argument]
    · simp +decide [steps, width_arg, CC.PTree.gso, CC.typeof, CC.tuchar, CC.tuint, CC.tint, CC.tulong,
      CC.cc_default, arguments, CC.doStep, CC.doFunctionEntry2,
      X86_program_profile_bpf.f_x86_alu_result, CC.doAllocVariables, CC.bindParameterTemps,
      CC.createUndefTemps, CC.doEvalExpr, CC.doEvalExprlist, CC.Cop.semSwitchArg,
      CC.Cop.classifySwitch, CC.Cop.classifyFun, CC.selectSwitch, CC.selectSwitchCase,
      CC.seqOfLabeledStatement, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
      CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Integers.Int.unsigned, CC.Integers.MI.unsigned,
      CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.lvalOfVar, CC.doDerefLoc, CC.accessMode,
      CC.Genv.findFunct, symbol, callee, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero, CC.Eapp, CC.E0,
      CC.emptyEnv, X86ShiftLeft.argument]
      rfl
  case afterCall =>
    intro value
    apply internalRun_of_steps
    · simp +decide [InternalPath, InternalState, empty, CC.typeof, CC.doStep, CC.doEvalExpr, CC.Cop.semCast,
      CC.Cop.classifyCast, CC.E0, CC.callCont, CC.blocksOfEnv, CC.Mem.freeList, CC.setOpttemp]
    · simp +decide [steps, empty, CC.typeof, CC.doStep, CC.doEvalExpr, CC.Cop.semCast, CC.Cop.classifyCast, CC.Eapp,
      CC.E0, CC.callCont, CC.blocksOfEnv, CC.Mem.freeList, CC.setOpttemp]

/-- The real ALU call composes the selected helper with genuine source control. -/
theorem internal (ge : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._kprog_x86_shl_result = some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block =
        some (.Internal X86_program_profile_bpf.f_kprog_x86_shl_result))
    (lhs rhs : BitVec 64) (size : X86.Size) (k : CC.Cont) (m : CC.Mem) :
    InternalRun ge (length size)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_alu_result) (arguments lhs rhs size) k m)
      (.Returnstate (result lhs rhs size) (CC.callCont k) m) := by
  obtain ⟨callK, beforeCall, afterCall⟩ := plumbing ge block binding lhs rhs size k m
  have helper := X86ShiftLeft.internal ge lhs rhs size callK m
  simpa only [length, X86ShiftLeft.result] using
    (beforeCall.trans helper).trans (afterCall
      (X86.Value.trunc size ((X86.Value.trunc size lhs) <<<
        X86.Flags.shiftCount size (rhs.setWidth 8))))

/-- Relational source execution returns the mature ISA arithmetic result and original memory. -/
theorem returns (ge : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._kprog_x86_shl_result = some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block =
        some (.Internal X86_program_profile_bpf.f_kprog_x86_shl_result))
    (lhs rhs : BitVec 64) (size : X86.Size) (k : CC.Cont) (m : CC.Mem) :
    CC.Star (CC.Step2 ge)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_alu_result) (arguments lhs rhs size) k m)
      CC.E0 (.Returnstate (result lhs rhs size) (CC.callCont k) m) :=
  (internal ge block binding lhs rhs size k m).sound

/-- Every finite execution is a silent prefix of the same return; the complete
relational execution terminates with that unique terminal state. -/
theorem all_behaviors (ge : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._kprog_x86_shl_result = some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block =
        some (.Internal X86_program_profile_bpf.f_kprog_x86_shl_result))
    (lhs rhs : BitVec 64) (size : X86.Size) (m : CC.Mem) :
    (∀ t other, CC.Star (CC.Step2 ge)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_alu_result)
        (arguments lhs rhs size) .Kstop m) t other →
      t = CC.E0 ∧ ∃ remaining, InternalRun ge remaining other
        (.Returnstate (result lhs rhs size) .Kstop m)) ∧
    (∀ t other, CC.Star (CC.Step2 ge)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_alu_result)
        (arguments lhs rhs size) .Kstop m) t other →
      (∀ u next, ¬ CC.Step2 ge other u next) →
      t = CC.E0 ∧ other = .Returnstate (result lhs rhs size) .Kstop m) ∧
    ¬ (∃ states : Nat → CC.State,
      states 0 = .Callstate (.Internal X86_program_profile_bpf.f_x86_alu_result)
        (arguments lhs rhs size) .Kstop m ∧
      ∀ i, ∃ t, CC.Step2 ge (states i) t (states (i + 1))) := by
  have run := internal ge block binding lhs rhs size .Kstop m
  have stuck : ∀ t next, ¬ CC.Step2 ge (.Returnstate (result lhs rhs size) .Kstop m) t next := by
    intro t next step
    cases step
  exact ⟨fun _ _ observed => run.finish_prefix stuck observed,
    fun _ _ observed endpoint => run.endpoint_unique stuck observed endpoint,
    run.no_infinite stuck⟩



end KProgFormal.ClightRefinement.X86ShiftLeftAlu
