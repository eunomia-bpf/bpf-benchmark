import KProgFormal.ClightRefinement.InternalExecution
import KProgFormal.Clight.X86ProgramProfile
import X86.Flags

namespace KProgFormal.ClightRefinement.X86ShiftLeft

def argument (size : X86.Size) : CC.Val := .Vint (BitVec.ofNat 32 size.bytes)

def length : X86.Size → Nat
  | .b => 19
  | .w => 23
  | .d | .q => 27

def result (lhs rhs : BitVec 64) (size : X86.Size) : CC.Val :=
  .Vlong (X86.Value.trunc size ((X86.Value.trunc size lhs) <<<
    X86.Flags.shiftCount size (rhs.setWidth 8)))

private theorem mask31 (value : Nat) : value &&& 31 = value % 32 :=
  Nat.and_two_pow_sub_one_eq_mod value 5

private theorem mask63 (value : Nat) : value &&& 63 = value % 64 :=
  Nat.and_two_pow_sub_one_eq_mod value 6

private theorem mask255 (value : Nat) : value &&& 255 = value % 256 :=
  Nat.and_two_pow_sub_one_eq_mod value 8

private theorem count_bounds (rhs : BitVec 64) :
    ((rhs.setWidth 32 &&& (31#32) &&& (255#32)).ult (64#32) = true) ∧
    ((rhs.setWidth 32 &&& (63#32) &&& (255#32)).ult (64#32) = true) := by
  constructor <;> simp [BitVec.ult, BitVec.toNat_and, mask31, mask63, mask255] <;> omega

private theorem count_values (rhs : BitVec 64) :
    (rhs.toNat % 4294967296 % 18446744073709551616 &&& 31 &&& 255) =
      (rhs.setWidth 8).toNat % 32 ∧
    (rhs.toNat % 4294967296 % 18446744073709551616 &&& 63 &&& 255) =
      (rhs.setWidth 8).toNat % 64 := by
  constructor <;> simp [mask31, mask63, mask255] <;> omega

/-- Actual C left-shift result for every operand pair and mature operand size. -/
private theorem execution (ge : CC.CGenv) (lhs rhs : BitVec 64) (size : X86.Size)
    (k : CC.Cont) (m : CC.Mem) :
    steps ge (length size) (.Callstate (.Internal X86_program_profile_bpf.f_kprog_x86_shl_result)
      [.Vlong lhs, .Vlong rhs, argument size] k m) =
        some (CC.E0, .Returnstate (result lhs rhs size) (CC.callCont k) m) ∧
    InternalPath ge (length size) (.Callstate (.Internal X86_program_profile_bpf.f_kprog_x86_shl_result)
      [.Vlong lhs, .Vlong rhs, argument size] k m) := by
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  have h0 : X86_program_profile_bpf._value ≠ X86_program_profile_bpf._rhs := by decide
  have h1 : X86_program_profile_bpf._value ≠ X86_program_profile_bpf._width := by decide
  have h2 : X86_program_profile_bpf._value ≠ X86_program_profile_bpf._count := by decide
  have h3 : X86_program_profile_bpf._value ≠ X86_program_profile_bpf._mask := by decide
  have h4 : X86_program_profile_bpf._value ≠ X86_program_profile_bpf._narrowed := by decide
  have h5 : X86_program_profile_bpf._value ≠ X86_program_profile_bpf._t'1 := by decide
  have h6 : X86_program_profile_bpf._value ≠ X86_program_profile_bpf._t'2 := by decide
  have h7 : X86_program_profile_bpf._rhs ≠ X86_program_profile_bpf._value := by decide
  have h8 : X86_program_profile_bpf._rhs ≠ X86_program_profile_bpf._width := by decide
  have h9 : X86_program_profile_bpf._rhs ≠ X86_program_profile_bpf._count := by decide
  have h10 : X86_program_profile_bpf._rhs ≠ X86_program_profile_bpf._mask := by decide
  have h11 : X86_program_profile_bpf._rhs ≠ X86_program_profile_bpf._narrowed := by decide
  have h12 : X86_program_profile_bpf._rhs ≠ X86_program_profile_bpf._t'1 := by decide
  have h13 : X86_program_profile_bpf._rhs ≠ X86_program_profile_bpf._t'2 := by decide
  have h14 : X86_program_profile_bpf._width ≠ X86_program_profile_bpf._value := by decide
  have h15 : X86_program_profile_bpf._width ≠ X86_program_profile_bpf._rhs := by decide
  have h16 : X86_program_profile_bpf._width ≠ X86_program_profile_bpf._count := by decide
  have h17 : X86_program_profile_bpf._width ≠ X86_program_profile_bpf._mask := by decide
  have h18 : X86_program_profile_bpf._width ≠ X86_program_profile_bpf._narrowed := by decide
  have h19 : X86_program_profile_bpf._width ≠ X86_program_profile_bpf._t'1 := by decide
  have h20 : X86_program_profile_bpf._width ≠ X86_program_profile_bpf._t'2 := by decide
  have h21 : X86_program_profile_bpf._count ≠ X86_program_profile_bpf._value := by decide
  have h22 : X86_program_profile_bpf._count ≠ X86_program_profile_bpf._rhs := by decide
  have h23 : X86_program_profile_bpf._count ≠ X86_program_profile_bpf._width := by decide
  have h24 : X86_program_profile_bpf._count ≠ X86_program_profile_bpf._mask := by decide
  have h25 : X86_program_profile_bpf._count ≠ X86_program_profile_bpf._narrowed := by decide
  have h26 : X86_program_profile_bpf._count ≠ X86_program_profile_bpf._t'1 := by decide
  have h27 : X86_program_profile_bpf._count ≠ X86_program_profile_bpf._t'2 := by decide
  have h28 : X86_program_profile_bpf._mask ≠ X86_program_profile_bpf._value := by decide
  have h29 : X86_program_profile_bpf._mask ≠ X86_program_profile_bpf._rhs := by decide
  have h30 : X86_program_profile_bpf._mask ≠ X86_program_profile_bpf._width := by decide
  have h31 : X86_program_profile_bpf._mask ≠ X86_program_profile_bpf._count := by decide
  have h32 : X86_program_profile_bpf._mask ≠ X86_program_profile_bpf._narrowed := by decide
  have h33 : X86_program_profile_bpf._mask ≠ X86_program_profile_bpf._t'1 := by decide
  have h34 : X86_program_profile_bpf._mask ≠ X86_program_profile_bpf._t'2 := by decide
  have h35 : X86_program_profile_bpf._narrowed ≠ X86_program_profile_bpf._value := by decide
  have h36 : X86_program_profile_bpf._narrowed ≠ X86_program_profile_bpf._rhs := by decide
  have h37 : X86_program_profile_bpf._narrowed ≠ X86_program_profile_bpf._width := by decide
  have h38 : X86_program_profile_bpf._narrowed ≠ X86_program_profile_bpf._count := by decide
  have h39 : X86_program_profile_bpf._narrowed ≠ X86_program_profile_bpf._mask := by decide
  have h40 : X86_program_profile_bpf._narrowed ≠ X86_program_profile_bpf._t'1 := by decide
  have h41 : X86_program_profile_bpf._narrowed ≠ X86_program_profile_bpf._t'2 := by decide
  have h42 : X86_program_profile_bpf._t'1 ≠ X86_program_profile_bpf._value := by decide
  have h43 : X86_program_profile_bpf._t'1 ≠ X86_program_profile_bpf._rhs := by decide
  have h44 : X86_program_profile_bpf._t'1 ≠ X86_program_profile_bpf._width := by decide
  have h45 : X86_program_profile_bpf._t'1 ≠ X86_program_profile_bpf._count := by decide
  have h46 : X86_program_profile_bpf._t'1 ≠ X86_program_profile_bpf._mask := by decide
  have h47 : X86_program_profile_bpf._t'1 ≠ X86_program_profile_bpf._narrowed := by decide
  have h48 : X86_program_profile_bpf._t'1 ≠ X86_program_profile_bpf._t'2 := by decide
  have h49 : X86_program_profile_bpf._t'2 ≠ X86_program_profile_bpf._value := by decide
  have h50 : X86_program_profile_bpf._t'2 ≠ X86_program_profile_bpf._rhs := by decide
  have h51 : X86_program_profile_bpf._t'2 ≠ X86_program_profile_bpf._width := by decide
  have h52 : X86_program_profile_bpf._t'2 ≠ X86_program_profile_bpf._count := by decide
  have h53 : X86_program_profile_bpf._t'2 ≠ X86_program_profile_bpf._mask := by decide
  have h54 : X86_program_profile_bpf._t'2 ≠ X86_program_profile_bpf._narrowed := by decide
  have h55 : X86_program_profile_bpf._t'2 ≠ X86_program_profile_bpf._t'1 := by decide
  obtain ⟨bound31, bound63⟩ := count_bounds rhs
  obtain ⟨value31, value63⟩ := count_values rhs
  cases size
  all_goals
    simp_all [CC.PTree.gso,  CC.tulong,
    CC.typeof, CC.typeconv, CC.removeAttributes,
    CC.tattr, CC.tuchar, CC.tuint, CC.tint, steps, InternalPath, InternalState, argument, result, length, X86.Value.trunc, X86.Size.mask, X86.Size.bytes, X86.Flags.shiftCount,
    CC.doStep, CC.doFunctionEntry2,
    X86_program_profile_bpf.f_kprog_x86_shl_result, CC.listNorepet, CC.varNames,
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
    CC.Integers.Int64.repr, CC.Integers.Int64.unsigned, CC.Integers.Int.unsigned, CC.Integers.MI.unsigned, CC.Cop.semShl, CC.Cop.semShift, CC.Cop.classifyShift,
    CC.Integers.Int64.shl, CC.Integers.MI.shl, CC.Integers.Int.ltu, CC.Integers.MI.ltu]
  all_goals
    simp_all [CC.Cop.semCast, CC.Cop.classifyCast, CC.tulong,
      CC.Integers.Int64.repr, CC.Integers.MI.repr]


/-- The actual result helper has a silent internal run with complete memory preservation. -/
theorem internal (ge : CC.CGenv) (lhs rhs : BitVec 64) (size : X86.Size)
    (k : CC.Cont) (m : CC.Mem) :
    InternalRun ge (length size)
      (.Callstate (.Internal X86_program_profile_bpf.f_kprog_x86_shl_result)
        [.Vlong lhs, .Vlong rhs, argument size] k m)
      (.Returnstate (result lhs rhs size) (CC.callCont k) m) :=
  internalRun_of_steps (execution ge lhs rhs size k m).2 (execution ge lhs rhs size k m).1

/-- The source call returns the mature x86 left-shift result for every operand pair. -/
theorem returns (ge : CC.CGenv) (lhs rhs : BitVec 64) (size : X86.Size)
    (k : CC.Cont) (m : CC.Mem) :
    CC.Star (CC.Step2 ge)
      (.Callstate (.Internal X86_program_profile_bpf.f_kprog_x86_shl_result)
        [.Vlong lhs, .Vlong rhs, argument size] k m)
      CC.E0 (.Returnstate (result lhs rhs size) (CC.callCont k) m) :=
  steps_sound ge (length size) _ _ _ (execution ge lhs rhs size k m).1

/-- Every finite execution is a silent prefix of the same return; the complete
relational execution terminates with that unique terminal state. -/
theorem all_behaviors (ge : CC.CGenv) (lhs rhs : BitVec 64) (size : X86.Size) (m : CC.Mem) :
    (∀ t other, CC.Star (CC.Step2 ge)
      (.Callstate (.Internal X86_program_profile_bpf.f_kprog_x86_shl_result)
        [.Vlong lhs, .Vlong rhs, argument size] .Kstop m) t other →
      t = CC.E0 ∧ ∃ remaining, InternalRun ge remaining other
        (.Returnstate (result lhs rhs size) .Kstop m)) ∧
    (∀ t other, CC.Star (CC.Step2 ge)
      (.Callstate (.Internal X86_program_profile_bpf.f_kprog_x86_shl_result)
        [.Vlong lhs, .Vlong rhs, argument size] .Kstop m) t other →
      (∀ u next, ¬ CC.Step2 ge other u next) →
      t = CC.E0 ∧ other = .Returnstate (result lhs rhs size) .Kstop m) ∧
    ¬ (∃ states : Nat → CC.State,
      states 0 = .Callstate (.Internal X86_program_profile_bpf.f_kprog_x86_shl_result)
        [.Vlong lhs, .Vlong rhs, argument size] .Kstop m ∧
      ∀ i, ∃ t, CC.Step2 ge (states i) t (states (i + 1))) := by
  have run := internal ge lhs rhs size .Kstop m
  have stuck : ∀ t next, ¬ CC.Step2 ge (.Returnstate (result lhs rhs size) .Kstop m) t next := by
    intro t next step
    cases step
  exact ⟨fun _ _ observed => run.finish_prefix stuck observed,
    fun _ _ observed endpoint => run.endpoint_unique stuck observed endpoint,
    run.no_infinite stuck⟩



end KProgFormal.ClightRefinement.X86ShiftLeft
