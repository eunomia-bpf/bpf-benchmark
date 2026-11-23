import KProgFormal.ClightRefinement.X86ShiftLeftAlu

namespace KProgFormal.ClightRefinement.X86LogicAlu

/-- Original ALU switch, assignments, loop exits and return for the three
logical operation codes. Width is retained as an arbitrary byte argument. -/
private theorem execution (ge : CC.CGenv) (lhs rhs : BitVec 64) (width : BitVec 8)
    (operation : BitVec 32) (value : BitVec 64) (k : CC.Cont) (m : CC.Mem)
    (selected : (operation = (2#32) ∧ value = lhs ^^^ rhs) ∨
      (operation = (3#32) ∧ value = lhs ||| rhs) ∨
      (operation = (4#32) ∧ value = lhs &&& rhs)) :
    InternalRun ge 20
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_alu_result)
        [.Vlong lhs, .Vlong rhs, .Vint operation, .Vint (width.setWidth 32)] k m)
      (.Returnstate (.Vlong value) (CC.callCont k) m) := by
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  rcases selected with ⟨rfl, rfl⟩ | ⟨rfl, rfl⟩ | ⟨rfl, rfl⟩
  all_goals apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, CC.doStep, CC.doFunctionEntry2,
      X86_program_profile_bpf.f_x86_alu_result, CC.doAllocVariables,
      CC.bindParameterTemps, CC.createUndefTemps, CC.PTree.gss, CC.PTree.gso,
      CC.doEvalExpr, CC.typeof, CC.tuchar, CC.tuint, CC.tint, CC.tulong,
      CC.Cop.semSwitchArg, CC.Cop.classifySwitch, CC.selectSwitch,
      CC.selectSwitchCase, CC.seqOfLabeledStatement, CC.Cop.semCast,
      CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.semBinaryOperation,
      CC.Cop.semXor, CC.Cop.semOr, CC.Cop.semAnd, CC.Cop.semBinarith,
      CC.Cop.classifyBinarith, CC.Cop.binarithType,
      CC.Integers.Int64.xor, CC.Integers.Int64.or, CC.Integers.Int64.and,
      CC.Integers.MI.xor, CC.Integers.MI.or, CC.Integers.MI.and,
      CC.Integers.Int.repr, CC.Integers.MI.repr,
      CC.Integers.Int.unsigned, CC.Integers.MI.unsigned,
      CC.callCont, CC.blocksOfEnv, CC.Mem.freeList, CC.emptyEnv, empty, CC.Eapp, CC.E0]

/-- The actual helper returns the full XOR word and original caller memory. -/
theorem xor_internal (ge : CC.CGenv) (lhs rhs : BitVec 64) (width : BitVec 8)
    (k : CC.Cont) (m : CC.Mem) :
    InternalRun ge 20
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_alu_result)
        [.Vlong lhs, .Vlong rhs, .Vint (2#32), .Vint (width.setWidth 32)] k m)
      (.Returnstate (.Vlong (lhs ^^^ rhs)) (CC.callCont k) m) :=
  execution ge lhs rhs width 2 (lhs ^^^ rhs) k m (.inl ⟨rfl, rfl⟩)

/-- The actual helper returns the full OR word and original caller memory. -/
theorem or_internal (ge : CC.CGenv) (lhs rhs : BitVec 64) (width : BitVec 8)
    (k : CC.Cont) (m : CC.Mem) :
    InternalRun ge 20
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_alu_result)
        [.Vlong lhs, .Vlong rhs, .Vint (3#32), .Vint (width.setWidth 32)] k m)
      (.Returnstate (.Vlong (lhs ||| rhs)) (CC.callCont k) m) :=
  execution ge lhs rhs width 3 (lhs ||| rhs) k m (.inr (.inl ⟨rfl, rfl⟩))

/-- The actual helper returns the full AND word and original caller memory. -/
theorem and_internal (ge : CC.CGenv) (lhs rhs : BitVec 64) (width : BitVec 8)
    (k : CC.Cont) (m : CC.Mem) :
    InternalRun ge 20
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_alu_result)
        [.Vlong lhs, .Vlong rhs, .Vint (4#32), .Vint (width.setWidth 32)] k m)
      (.Returnstate (.Vlong (lhs &&& rhs)) (CC.callCont k) m) :=
  execution ge lhs rhs width 4 (lhs &&& rhs) k m (.inr (.inr ⟨rfl, rfl⟩))

end KProgFormal.ClightRefinement.X86LogicAlu
