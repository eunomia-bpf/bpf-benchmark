import KProgFormal.ClightRefinement.InternalExecution
import KProgFormal.Clight.X86ProgramProfile
import X86.Flags

namespace KProgFormal.ClightRefinement.X86WidthShape

def argument (code : BitVec 8) : CC.Val := .Vint (code.setWidth 32)

def length (code : BitVec 8) : Nat :=
  if code = 1 then 6 else if code = 2 then 10 else 14

namespace Bits

def result (code : BitVec 8) : CC.Val :=
  .Vint (if code = 1 then 8 else if code = 2 then 16 else if code = 4 then 32 else 64)

/-- All byte inputs follow the actual nested comparisons and source casts. -/
private theorem execution (ge : CC.CGenv) (code : BitVec 8) (k : CC.Cont) (m : CC.Mem) :
    steps ge (length code) (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_bits)
      [argument code] k m) = some (CC.E0, .Returnstate (result code) (CC.callCont k) m) ∧
    InternalPath ge (length code) (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_bits)
      [argument code] k m) := by
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  have ids : X86_program_profile_bpf._width ≠ X86_program_profile_bpf._t'1 := by decide
  have cast_eq (n : BitVec 8) : code.setWidth 32 = n.setWidth 32 ↔ code = n := by
    constructor
    · intro equal
      have low := congrArg (fun v : BitVec 32 => v.setWidth 8) equal
      simpa using low
    · intro equal
      subst code
      rfl
  by_cases one : code = 1
  all_goals by_cases two : code = 2
  all_goals by_cases four : code = 4
  all_goals
    try have one32 : code.setWidth 32 ≠ (1#32) := fun eq => one ((cast_eq 1).mp eq)
    try have two32 : code.setWidth 32 ≠ (2#32) := fun eq => two ((cast_eq 2).mp eq)
    try have four32 : code.setWidth 32 ≠ (4#32) := fun eq => four ((cast_eq 4).mp eq)
  all_goals
    simp_all [ CC.typeof, CC.typeconv, CC.removeAttributes,
    CC.tattr, CC.tuchar, CC.tuint, CC.tint, steps, InternalPath, InternalState, argument, result, length,
    CC.doStep, CC.doFunctionEntry2,
    X86_program_profile_bpf.f_x86_width_bits, CC.listNorepet, CC.varNames,
    CC.listDisjoint, CC.doAllocVariables, CC.bindParameterTemps, CC.createUndefTemps,
    CC.doEvalExpr, CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
    CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.Cop.boolVal, CC.Cop.classifyBool, CC.Val.ofBool,
    CC.Integers.Int.cmpu, CC.Integers.MI.cmpu,
    CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.zero,
    CC.Integers.Int.one, CC.Integers.MI.zero, CC.Integers.MI.one,
    CC.Integers.Int.repr, CC.Integers.MI.repr,
    CC.Eapp, CC.E0, CC.Val.Vtrue, CC.Val.Vfalse, CC.blocksOfEnv, CC.emptyEnv, CC.Mem.freeList]


/-- The complete actual call is internal and preserves the entire memory. -/
theorem internal (ge : CC.CGenv) (code : BitVec 8) (k : CC.Cont) (m : CC.Mem) :
    InternalRun ge (length code)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_bits) [argument code] k m)
      (.Returnstate (result code) (CC.callCont k) m) :=
  internalRun_of_steps (execution ge code k m).2 (execution ge code k m).1

/-- The Clight relational execution returns with the original memory. -/
theorem returns (ge : CC.CGenv) (code : BitVec 8) (k : CC.Cont) (m : CC.Mem) :
    CC.Star (CC.Step2 ge)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_bits) [argument code] k m)
      CC.E0 (.Returnstate (result code) (CC.callCont k) m) :=
  (internal ge code k m).sound

/-- Every finite execution is a silent prefix of the unique terminal return,
and an infinite execution from the same input is impossible. -/
theorem all_behaviors (ge : CC.CGenv) (code : BitVec 8) (m : CC.Mem) :
    (∀ t other, CC.Star (CC.Step2 ge)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_bits)
        [argument code] .Kstop m) t other →
      t = CC.E0 ∧ ∃ remaining, InternalRun ge remaining other
        (.Returnstate (result code) .Kstop m)) ∧
    (∀ t other, CC.Star (CC.Step2 ge)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_bits)
        [argument code] .Kstop m) t other →
      (∀ u next, ¬ CC.Step2 ge other u next) →
      t = CC.E0 ∧ other = .Returnstate (result code) .Kstop m) ∧
    ¬ (∃ states : Nat → CC.State,
      states 0 = .Callstate (.Internal X86_program_profile_bpf.f_x86_width_bits)
        [argument code] .Kstop m ∧
      ∀ i, ∃ t, CC.Step2 ge (states i) t (states (i + 1))) := by
  have run := internal ge code .Kstop m
  have stuck : ∀ t next, ¬ CC.Step2 ge (.Returnstate (result code) .Kstop m) t next := by
    intro t next step
    cases step
  exact ⟨fun _ _ observed => run.finish_prefix stuck observed,
    fun _ _ observed endpoint => run.endpoint_unique stuck observed endpoint,
    run.no_infinite stuck⟩

/-- The actual helper value agrees with the existing mature x86 width definition. -/
theorem native_result (size : X86.Size) :
    result (BitVec.ofNat 8 size.bytes) = .Vint (BitVec.ofNat 32 size.bits) := by
  cases size <;> rfl

/-- Actual source execution returns the width value used by the mature ISA. -/
theorem native_returns (ge : CC.CGenv) (size : X86.Size) (k : CC.Cont) (m : CC.Mem) :
    CC.Star (CC.Step2 ge)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_bits)
        [argument (BitVec.ofNat 8 size.bytes)] k m)
      CC.E0 (.Returnstate (.Vint (BitVec.ofNat 32 size.bits)) (CC.callCont k) m) := by
  simpa only [native_result] using returns ge (BitVec.ofNat 8 size.bytes) k m

end Bits

namespace Mask

def result (code : BitVec 8) : CC.Val :=
  .Vlong (if code = 1 then 255 else if code = 2 then 65535 else if code = 4 then 4294967295 else -1)

/-- All byte inputs follow the actual nested comparisons and source casts. -/
private theorem execution (ge : CC.CGenv) (code : BitVec 8) (k : CC.Cont) (m : CC.Mem) :
    steps ge (length code) (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_mask)
      [argument code] k m) = some (CC.E0, .Returnstate (result code) (CC.callCont k) m) ∧
    InternalPath ge (length code) (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_mask)
      [argument code] k m) := by
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  have ids : X86_program_profile_bpf._width ≠ X86_program_profile_bpf._t'1 := by decide
  have cast_eq (n : BitVec 8) : code.setWidth 32 = n.setWidth 32 ↔ code = n := by
    constructor
    · intro equal
      have low := congrArg (fun v : BitVec 32 => v.setWidth 8) equal
      simpa using low
    · intro equal
      subst code
      rfl
  by_cases one : code = 1
  all_goals by_cases two : code = 2
  all_goals by_cases four : code = 4
  all_goals
    try have one32 : code.setWidth 32 ≠ (1#32) := fun eq => one ((cast_eq 1).mp eq)
    try have two32 : code.setWidth 32 ≠ (2#32) := fun eq => two ((cast_eq 2).mp eq)
    try have four32 : code.setWidth 32 ≠ (4#32) := fun eq => four ((cast_eq 4).mp eq)
  all_goals
    simp_all [ CC.typeof, CC.typeconv, CC.removeAttributes,
    CC.tattr, CC.tuchar, CC.tuint, CC.tint, CC.tulong, steps, InternalPath, InternalState, argument, result, length,
    CC.doStep, CC.doFunctionEntry2,
    X86_program_profile_bpf.f_x86_width_mask, CC.listNorepet, CC.varNames,
    CC.listDisjoint, CC.doAllocVariables, CC.bindParameterTemps, CC.createUndefTemps,
    CC.doEvalExpr, CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
    CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.Cop.boolVal, CC.Cop.classifyBool, CC.Val.ofBool,
    CC.Integers.Int.cmpu, CC.Integers.MI.cmpu,
    CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.zero,
    CC.Integers.Int.one, CC.Integers.MI.zero, CC.Integers.MI.one,
    CC.Integers.Int.repr, CC.Integers.MI.repr,
    CC.Integers.Int64.repr,
    CC.Eapp, CC.E0, CC.Val.Vtrue, CC.Val.Vfalse, CC.blocksOfEnv, CC.emptyEnv, CC.Mem.freeList]



/-- The complete actual call is internal and preserves the entire memory. -/
theorem internal (ge : CC.CGenv) (code : BitVec 8) (k : CC.Cont) (m : CC.Mem) :
    InternalRun ge (length code)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_mask) [argument code] k m)
      (.Returnstate (result code) (CC.callCont k) m) :=
  internalRun_of_steps (execution ge code k m).2 (execution ge code k m).1

/-- The Clight relational execution returns with the original memory. -/
theorem returns (ge : CC.CGenv) (code : BitVec 8) (k : CC.Cont) (m : CC.Mem) :
    CC.Star (CC.Step2 ge)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_mask) [argument code] k m)
      CC.E0 (.Returnstate (result code) (CC.callCont k) m) :=
  (internal ge code k m).sound

/-- Every finite execution is a silent prefix of the unique terminal return,
and an infinite execution from the same input is impossible. -/
theorem all_behaviors (ge : CC.CGenv) (code : BitVec 8) (m : CC.Mem) :
    (∀ t other, CC.Star (CC.Step2 ge)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_mask)
        [argument code] .Kstop m) t other →
      t = CC.E0 ∧ ∃ remaining, InternalRun ge remaining other
        (.Returnstate (result code) .Kstop m)) ∧
    (∀ t other, CC.Star (CC.Step2 ge)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_mask)
        [argument code] .Kstop m) t other →
      (∀ u next, ¬ CC.Step2 ge other u next) →
      t = CC.E0 ∧ other = .Returnstate (result code) .Kstop m) ∧
    ¬ (∃ states : Nat → CC.State,
      states 0 = .Callstate (.Internal X86_program_profile_bpf.f_x86_width_mask)
        [argument code] .Kstop m ∧
      ∀ i, ∃ t, CC.Step2 ge (states i) t (states (i + 1))) := by
  have run := internal ge code .Kstop m
  have stuck : ∀ t next, ¬ CC.Step2 ge (.Returnstate (result code) .Kstop m) t next := by
    intro t next step
    cases step
  exact ⟨fun _ _ observed => run.finish_prefix stuck observed,
    fun _ _ observed endpoint => run.endpoint_unique stuck observed endpoint,
    run.no_infinite stuck⟩

/-- The actual helper value agrees with the existing mature x86 width definition. -/
theorem native_result (size : X86.Size) :
    result (BitVec.ofNat 8 size.bytes) = .Vlong size.mask := by
  cases size <;> rfl

/-- Actual source execution returns the width value used by the mature ISA. -/
theorem native_returns (ge : CC.CGenv) (size : X86.Size) (k : CC.Cont) (m : CC.Mem) :
    CC.Star (CC.Step2 ge)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_mask)
        [argument (BitVec.ofNat 8 size.bytes)] k m)
      CC.E0 (.Returnstate (.Vlong size.mask) (CC.callCont k) m) := by
  simpa only [native_result] using returns ge (BitVec.ofNat 8 size.bytes) k m

end Mask

end KProgFormal.ClightRefinement.X86WidthShape
