import KProgFormal.ClightRefinement.InternalExecution
import KProgFormal.Clight.X86ProgramProfile

namespace KProgFormal.ClightRefinement.X86Width

/-- The byte ABI uses a zero-extended 32-bit Clight integer. -/
def argument (code : BitVec 8) : CC.Val := .Vint (code.setWidth 32)

def result (code : BitVec 8) : CC.Val :=
  argument (if code == 0 then 8 else code)

/-- Complete call of the actual x86 export for every byte code, memory and continuation. -/
private theorem execution (ge : CC.CGenv) (code : BitVec 8) (k : CC.Cont) (m : CC.Mem) :
    steps ge 6 (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective)
      [argument code] k m) = some (CC.E0, .Returnstate (result code) (CC.callCont k) m) ∧
    InternalPath ge 6 (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective)
      [argument code] k m) := by
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  have ids : X86_program_profile_bpf._code ≠ X86_program_profile_bpf._t'1 := by decide
  by_cases hz : code = 0
  all_goals
    simp [empty, hz, ids, CC.typeof, CC.typeconv, CC.removeAttributes,
    CC.tattr, CC.tuchar, CC.tuint, CC.tint, steps, InternalPath, InternalState, argument, result,
    CC.doStep, CC.doFunctionEntry2,
    X86_program_profile_bpf.f_x86_width_effective, CC.listNorepet, CC.varNames,
    CC.listDisjoint, CC.doAllocVariables, CC.bindParameterTemps, CC.createUndefTemps,
    CC.doEvalExpr, CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
    CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.Cop.boolVal, CC.Cop.classifyBool, CC.Val.ofBool,
    CC.Integers.Int.cmpu, CC.Integers.MI.cmpu,
    CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.zero,
    CC.Integers.Int.one, CC.Integers.MI.zero, CC.Integers.MI.one,
    CC.Integers.Int.repr, CC.Integers.MI.repr,
    CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
    CC.Eapp, CC.E0, CC.Val.Vtrue, CC.Val.Vfalse, CC.blocksOfEnv, CC.emptyEnv, CC.Mem.freeList]

  all_goals
    have nonzero : code.setWidth 32 ≠ (0#32) := by
      intro heq
      apply hz
      have low := congrArg (fun v : BitVec 32 => v.setWidth 8) heq
      simpa using low
    simp_all [CC.doEvalExpr, CC.Cop.semCast, CC.Cop.classifyCast,
      CC.Cop.castIntInt, CC.typeof, CC.Mem.freeList]

  all_goals
    change code.setWidth 32 &&& (BitVec.allOnes 8).setWidth 32 = code.setWidth 32
    rw [← BitVec.setWidth_and, BitVec.and_allOnes]

/-- The executable call returns the effective width and original memory. -/
theorem executes (ge : CC.CGenv) (code : BitVec 8) (k : CC.Cont) (m : CC.Mem) :
    steps ge 6 (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective)
      [argument code] k m) = some (CC.E0, .Returnstate (result code) (CC.callCont k) m) :=
  (execution ge code k m).1

/-- The six visited states form an internal Clight run in every global environment. -/
theorem internal (ge : CC.CGenv) (code : BitVec 8) (k : CC.Cont) (m : CC.Mem) :
    InternalRun ge 6 (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective)
      [argument code] k m) (.Returnstate (result code) (CC.callCont k) m) :=
  internalRun_of_steps (execution ge code k m).2 (execution ge code k m).1

/-- The complete call is a silent Clight relational execution preserving the entire memory. -/
theorem returns (ge : CC.CGenv) (code : BitVec 8) (k : CC.Cont) (m : CC.Mem) :
    CC.Star (CC.Step2 ge)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective) [argument code] k m)
      CC.E0 (.Returnstate (result code) (CC.callCont k) m) :=
  steps_sound ge 6 _ _ _ (executes ge code k m)


/-- Every finite execution is a silent prefix of the same return; the complete
relational execution terminates with that unique terminal state. -/
theorem all_behaviors (ge : CC.CGenv) (code : BitVec 8) (m : CC.Mem) :
    (∀ t other, CC.Star (CC.Step2 ge)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective)
        [argument code] .Kstop m) t other →
      t = CC.E0 ∧ ∃ remaining, InternalRun ge remaining other
        (.Returnstate (result code) .Kstop m)) ∧
    (∀ t other, CC.Star (CC.Step2 ge)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective)
        [argument code] .Kstop m) t other →
      (∀ u next, ¬ CC.Step2 ge other u next) →
      t = CC.E0 ∧ other = .Returnstate (result code) .Kstop m) ∧
    ¬ (∃ states : Nat → CC.State,
      states 0 = .Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective)
        [argument code] .Kstop m ∧
      ∀ i, ∃ t, CC.Step2 ge (states i) t (states (i + 1))) := by
  have run := internal ge code .Kstop m
  have stuck : ∀ t next, ¬ CC.Step2 ge (.Returnstate (result code) .Kstop m) t next := by
    intro t next step
    cases step
  exact ⟨fun _ _ observed => run.finish_prefix stuck observed,
    fun _ _ observed endpoint => run.endpoint_unique stuck observed endpoint,
    run.no_infinite stuck⟩

end KProgFormal.ClightRefinement.X86Width
