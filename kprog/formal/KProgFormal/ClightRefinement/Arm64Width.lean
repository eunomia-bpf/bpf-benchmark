import KProgFormal.ClightRefinement.InternalExecution
import KProgFormal.Clight.Arm64Program

namespace KProgFormal.ClightRefinement.Arm64Width

/-- The C ABI carries a byte in a zero-extended 32-bit Clight integer. -/
def argument (code : BitVec 8) : CC.Val := .Vint (code.setWidth 32)

def result (code : BitVec 8) : CC.Val :=
  argument (if code == 0 then 8 else code)

/-- Byte arguments and results survive the actual unsigned ABI cast. -/
theorem cast_argument (code : BitVec 8) (m : CC.Mem) :
    CC.Cop.semCast (argument code) CC.tuchar CC.tuchar m = some (argument code) := by
  simp [argument, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.tuchar, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext]
  change code.setWidth 32 &&& (BitVec.allOnes 8).setWidth 32 = code.setWidth 32
  rw [← BitVec.setWidth_and, BitVec.and_allOnes]

/-- Complete call of the actual exported width function, with arbitrary memory
and continuation. No memory, input stream or platform effect is supplied. -/
private theorem execution (ge : CC.CGenv) (code : BitVec 8) (k : CC.Cont) (m : CC.Mem) :
    steps ge 6 (.Callstate (.Internal Arm64Program.f_arm64_width_effective)
      [argument code] k m) = some (CC.E0, .Returnstate (result code) (CC.callCont k) m) ∧
    InternalPath ge 6 (.Callstate (.Internal Arm64Program.f_arm64_width_effective)
      [argument code] k m) := by
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  have ids : Arm64Program._code ≠ Arm64Program._t'1 := by decide
  by_cases hz : code = 0
  all_goals
    simp [empty, hz, ids, CC.typeof, CC.typeconv, CC.removeAttributes,
    CC.tattr, CC.tuchar, CC.tuint, CC.tint, steps, InternalPath, InternalState, argument, result,
    CC.doStep, CC.doFunctionEntry2,
    Arm64Program.f_arm64_width_effective, CC.listNorepet, CC.varNames,
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
    rw [ite_eq_right nonzero]
    simp_all [CC.doEvalExpr, CC.Cop.semCast, CC.Cop.classifyCast,
      CC.Cop.castIntInt, CC.typeof, CC.Mem.freeList]

  all_goals
    change code.setWidth 32 &&& (BitVec.allOnes 8).setWidth 32 = code.setWidth 32
    rw [← BitVec.setWidth_and, BitVec.and_allOnes]

/-- Complete executable result, with the original public contract. -/
theorem executes (ge : CC.CGenv) (code : BitVec 8) (k : CC.Cont) (m : CC.Mem) :
    steps ge 6 (.Callstate (.Internal Arm64Program.f_arm64_width_effective)
      [argument code] k m) = some (CC.E0, .Returnstate (result code) (CC.callCont k) m) :=
  (execution ge code k m).1

/-- All six visited sources are internal, even when unused branches contain
other operations. The certificate imposes no condition on the global env. -/
theorem internal (ge : CC.CGenv) (code : BitVec 8) (k : CC.Cont) (m : CC.Mem) :
    InternalRun ge 6 (.Callstate (.Internal Arm64Program.f_arm64_width_effective)
      [argument code] k m) (.Returnstate (result code) (CC.callCont k) m) :=
  internalRun_of_steps (execution ge code k m).2 (execution ge code k m).1

/-- The complete call is a trace-empty Clight relational execution and preserves
all memory, not merely an observed projection. This is a C helper law, not an
ISA handler refinement. -/
theorem returns (ge : CC.CGenv) (code : BitVec 8) (k : CC.Cont) (m : CC.Mem) :
    CC.Star (CC.Step2 ge)
      (.Callstate (.Internal Arm64Program.f_arm64_width_effective) [argument code] k m)
      CC.E0 (.Returnstate (result code) (CC.callCont k) m) :=
  steps_sound ge 6 _ _ _ (executes ge code k m)

end KProgFormal.ClightRefinement.Arm64Width
