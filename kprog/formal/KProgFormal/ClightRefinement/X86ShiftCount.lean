import KProgFormal.ClightRefinement.InternalExecution
import KProgFormal.Clight.X86ProgramProfile
import X86.Flags

namespace KProgFormal.ClightRefinement.X86ShiftCount

private theorem mask31 (value : Nat) : value &&& 31 = value % 32 :=
  Nat.and_two_pow_sub_one_eq_mod value 5

private theorem mask63 (value : Nat) : value &&& 63 = value % 64 :=
  Nat.and_two_pow_sub_one_eq_mod value 6

private theorem mask255 (value : Nat) : value &&& 255 = value % 256 :=
  Nat.and_two_pow_sub_one_eq_mod value 8

def argument (width : BitVec 8) : CC.Val := .Vint (width.setWidth 32)

def count (rhs : BitVec 64) (width : BitVec 8) : BitVec 8 :=
  rhs.setWidth 8 &&& (if width == 8 then 63 else 31)

def result (rhs : BitVec 64) (width : BitVec 8) : CC.Val :=
  .Vint ((count rhs width).setWidth 32)

/-- The actual exported helper masks every input and preserves complete memory. -/
private theorem execution (ge : CC.CGenv) (rhs : BitVec 64) (code : BitVec 8)
    (k : CC.Cont) (m : CC.Mem) :
    steps ge 6 (.Callstate (.Internal X86_program_profile_bpf.f_x86_shift_count)
      [.Vlong rhs, argument code] k m) =
        some (CC.E0, .Returnstate (result rhs code) (CC.callCont k) m) ∧
    InternalPath ge 6 (.Callstate (.Internal X86_program_profile_bpf.f_x86_shift_count)
      [.Vlong rhs, argument code] k m) := by
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  have ids : X86_program_profile_bpf._width ≠ X86_program_profile_bpf._t'1 := by decide
  have ids2 : X86_program_profile_bpf._rhs ≠ X86_program_profile_bpf._t'1 := by decide
  have ids3 : X86_program_profile_bpf._rhs ≠ X86_program_profile_bpf._width := by decide
  have codeeq : code.setWidth 32 = (8#32) ↔ code = 8 := by
    constructor
    · intro equal
      have low := congrArg (fun v : BitVec 32 => v.setWidth 8) equal
      simpa using low
    · intro equal
      subst code
      rfl
  by_cases hz : code = 8
  all_goals
    try have nonEight : code.setWidth 32 ≠ (8#32) := fun equal => hz (codeeq.mp equal)
  all_goals
    simp_all [CC.PTree.gso, Ne.symm ids2, Ne.symm ids3, CC.tulong,
    CC.typeof, CC.typeconv, CC.removeAttributes,
    CC.tattr, CC.tuchar, CC.tuint, CC.tint, steps, InternalPath, InternalState, argument, result, count,
    CC.doStep, CC.doFunctionEntry2,
    X86_program_profile_bpf.f_x86_shift_count, CC.listNorepet, CC.varNames,
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
    CC.Eapp, CC.E0, CC.Val.Vtrue, CC.Val.Vfalse, CC.blocksOfEnv, CC.emptyEnv, CC.Mem.freeList, CC.Cop.semAnd, CC.Cop.castIntLong,
    CC.Cop.castIntInt, CC.Integers.Int64.and, CC.Integers.MI.and,
    CC.Integers.Int64.repr, CC.Integers.Int64.unsigned, CC.Integers.Int.unsigned, CC.Integers.MI.unsigned]

  all_goals
    apply BitVec.eq_of_toNat_eq
    simp [BitVec.toNat_and, BitVec.toNat_setWidth, BitVec.toNat_ofNat,
      mask31, mask63, mask255]
    omega

/-- Six internal transitions execute the actual helper for arbitrary continuations. -/
theorem internal (ge : CC.CGenv) (rhs : BitVec 64) (code : BitVec 8)
    (k : CC.Cont) (m : CC.Mem) :
    InternalRun ge 6 (.Callstate (.Internal X86_program_profile_bpf.f_x86_shift_count)
      [.Vlong rhs, argument code] k m)
      (.Returnstate (result rhs code) (CC.callCont k) m) :=
  internalRun_of_steps (execution ge rhs code k m).2 (execution ge rhs code k m).1

/-- The relational execution returns the masked count and the original memory. -/
theorem returns (ge : CC.CGenv) (rhs : BitVec 64) (code : BitVec 8)
    (k : CC.Cont) (m : CC.Mem) :
    CC.Star (CC.Step2 ge)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_shift_count)
        [.Vlong rhs, argument code] k m)
      CC.E0 (.Returnstate (result rhs code) (CC.callCont k) m) :=
  steps_sound ge 6 _ _ _ (execution ge rhs code k m).1

/-- Every finite execution is a silent prefix of the same return; the complete
relational execution terminates with that unique terminal state. -/
theorem all_behaviors (ge : CC.CGenv) (rhs : BitVec 64) (code : BitVec 8) (m : CC.Mem) :
    (∀ t other, CC.Star (CC.Step2 ge)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_shift_count)
        [.Vlong rhs, argument code] .Kstop m) t other →
      t = CC.E0 ∧ ∃ remaining, InternalRun ge remaining other
        (.Returnstate (result rhs code) .Kstop m)) ∧
    (∀ t other, CC.Star (CC.Step2 ge)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_shift_count)
        [.Vlong rhs, argument code] .Kstop m) t other →
      (∀ u next, ¬ CC.Step2 ge other u next) →
      t = CC.E0 ∧ other = .Returnstate (result rhs code) .Kstop m) ∧
    ¬ (∃ states : Nat → CC.State,
      states 0 = .Callstate (.Internal X86_program_profile_bpf.f_x86_shift_count)
        [.Vlong rhs, argument code] .Kstop m ∧
      ∀ i, ∃ t, CC.Step2 ge (states i) t (states (i + 1))) := by
  have run := internal ge rhs code .Kstop m
  have stuck : ∀ t next, ¬ CC.Step2 ge (.Returnstate (result rhs code) .Kstop m) t next := by
    intro t next step
    cases step
  exact ⟨fun _ _ observed => run.finish_prefix stuck observed,
    fun _ _ observed endpoint => run.endpoint_unique stuck observed endpoint,
    run.no_infinite stuck⟩


/-- Byte widths agree with the count used by mature x86 shift handlers. -/
theorem native_count (rhs : BitVec 64) (size : X86.Size) :
    (count rhs (BitVec.ofNat 8 size.bytes)).toNat =
      X86.Flags.shiftCount size (rhs.setWidth 8) := by
  cases size <;> simp [count, X86.Size.bytes, X86.Flags.shiftCount, mask31, mask63] <;> omega


/-- The actual C call returns the count consumed by the mature ISA handler. -/
theorem native_returns (ge : CC.CGenv) (rhs : BitVec 64) (size : X86.Size)
    (k : CC.Cont) (m : CC.Mem) :
    CC.Star (CC.Step2 ge)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_shift_count)
        [.Vlong rhs, argument (BitVec.ofNat 8 size.bytes)] k m)
      CC.E0 (.Returnstate
        (.Vint (BitVec.ofNat 32 (X86.Flags.shiftCount size (rhs.setWidth 8))))
        (CC.callCont k) m) := by
  have value : (count rhs (BitVec.ofNat 8 size.bytes)).setWidth 32 =
      BitVec.ofNat 32 (X86.Flags.shiftCount size (rhs.setWidth 8)) := by
    apply BitVec.eq_of_toNat_eq
    simp only [BitVec.toNat_setWidth, BitVec.toNat_ofNat]
    rw [native_count]
  simpa only [result, value] using returns ge rhs (BitVec.ofNat 8 size.bytes) k m

end KProgFormal.ClightRefinement.X86ShiftCount
