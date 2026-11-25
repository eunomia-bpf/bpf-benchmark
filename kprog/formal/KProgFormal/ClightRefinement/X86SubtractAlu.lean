import KProgFormal.ClightRefinement.X86LogicAlu

namespace KProgFormal.ClightRefinement.X86SubtractAlu

/-- Complete actual original C ALU SUB case, including source switch,
borrow-zero expression, assignments, real breaks and return. Arbitrary source
words and width remain explicit; no result/helper-run premise is introduced. -/
theorem internal (ge : CC.CGenv) (lhs rhs : BitVec 64) (width : BitVec 8)
    (k : CC.Cont) (m : CC.Mem) :
    InternalRun ge 20
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_alu_result)
        [.Vlong lhs,.Vlong rhs,.Vint (1#32),.Vint (width.setWidth 32)] k m)
      (.Returnstate (.Vlong (lhs-rhs)) (CC.callCont k) m) := by
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  all_goals apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, CC.doStep, CC.doFunctionEntry2,
      X86_program_profile_bpf.f_x86_alu_result, CC.doAllocVariables,
      CC.bindParameterTemps, CC.createUndefTemps, CC.PTree.gss, CC.PTree.gso,
      CC.doEvalExpr, CC.typeof, CC.tuchar, CC.tuint, CC.tint, CC.tulong,
      CC.Cop.semSwitchArg, CC.Cop.classifySwitch, CC.selectSwitch,
      CC.selectSwitchCase, CC.seqOfLabeledStatement, CC.Cop.semCast,
      CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.semBinaryOperation,
      CC.Cop.semXor, CC.Cop.semOr, CC.Cop.semAnd, CC.Cop.semSub, CC.Cop.classifySub, CC.Cop.semBinarith,
      CC.Cop.semUnaryOperation, CC.Cop.semNotbool, CC.Cop.boolVal, CC.Cop.classifyBool,
      CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Integers.Int.eq, CC.Integers.MI.eq,
      CC.Integers.Int.zero, CC.Integers.Int.one, CC.Integers.MI.zero, CC.Integers.MI.one,
      CC.Cop.castIntLong, CC.typeconv, CC.removeAttributes, CC.tattr,
      CC.Cop.classifyBinarith, CC.Cop.binarithType,
      CC.Integers.Int64.sub, CC.Integers.MI.sub, BitVec.sub_zero, CC.Integers.Int64.xor, CC.Integers.Int64.or, CC.Integers.Int64.and,
      CC.Integers.MI.xor, CC.Integers.MI.or, CC.Integers.MI.and,
      CC.Integers.Int.repr, CC.Integers.MI.repr,
      CC.Integers.Int.unsigned, CC.Integers.MI.unsigned,
      CC.callCont, CC.blocksOfEnv, CC.Mem.freeList, CC.emptyEnv, empty, CC.Eapp, CC.E0]

  change lhs-rhs-(0#64) = lhs-rhs
  exact BitVec.sub_zero _

end KProgFormal.ClightRefinement.X86SubtractAlu
