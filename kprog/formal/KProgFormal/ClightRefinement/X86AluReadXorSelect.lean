import KProgFormal.ClightRefinement.X86AluReadSelfXor

namespace KProgFormal.ClightRefinement.X86AluReadXorSelect

private theorem operation_compare (ge : CC.CGenv) (m : CC.Mem) :
    CC.Cop.semBinaryOperation ge.genv_cenv .Oeq
      (.Vint (2#32)) (.Tint .I8 .Unsigned CC.noattr)
      (.Vint (2#32)) (.Tint .I32 .Unsigned CC.noattr) m = some (.Vint (1#32)) := rfl

private theorem byte_same (ge : CC.CGenv) (m : CC.Mem) (code : BitVec 8) :
    CC.Cop.semBinaryOperation ge.genv_cenv .Oeq
      (X86Width.argument code) (.Tint .I8 .Unsigned CC.noattr)
      (X86Width.argument code) (.Tint .I8 .Unsigned CC.noattr) m = some (.Vint (1#32)) := by
  change some (CC.Val.ofBool (code.setWidth 32 == code.setWidth 32)) = _
  simp only [beq_self_eq_true]
  rfl

private theorem byte_different (ge : CC.CGenv) (m : CC.Mem) (left right : BitVec 8)
    (different : left ≠ right) :
    CC.Cop.semBinaryOperation ge.genv_cenv .Oeq
      (X86Width.argument left) (.Tint .I8 .Unsigned CC.noattr)
      (X86Width.argument right) (.Tint .I8 .Unsigned CC.noattr) m = some (.Vint (0#32)) := by
  have distinct : left.setWidth 32 ≠ right.setWidth 32 := by
    intro eq
    apply different
    simpa using congrArg (fun bits : BitVec 32 => bits.setWidth 8) eq
  change some (CC.Val.ofBool (left.setWidth 32 == right.setWidth 32)) = _
  rw [beq_eq_false_iff_ne.mpr distinct]
  rfl

private theorem bool_cast (m : CC.Mem) :
    CC.Cop.semCast (.Vint (0#32)) (.Tint .I32 .Signed CC.noattr)
      (.Tint .IBool .Unsigned CC.noattr) m = some (.Vint (0#32)) ∧
    CC.Cop.semCast (.Vint (1#32)) (.Tint .I32 .Signed CC.noattr)
      (.Tint .IBool .Unsigned CC.noattr) m = some (.Vint (1#32)) := ⟨rfl, rfl⟩

/-- Different register bytes make the actual XOR shortcut false. The
original operand-read sequence is selected without evaluating either shift. -/
theorem different_registers (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (dst src : BitVec 8) (different : dst ≠ src)
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (2#32)))
    (destination : le.get X86_program_profile_bpf._dst = some (X86Width.argument dst))
    (sourceReg : le.get X86_program_profile_bpf._src = some (X86Width.argument src)) :
    InternalRun ge 10 (.State function X86AluDecode.operandReads k e le m)
      (.State function X86AluReadSite.readStatements (.Kseq X86ShiftLeftRoute.dispatch k)
        e (X86AluReadSite.selectedTemps le) m) := by
  rw [X86AluReadSelfXor.source]
  apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, CC.doStep,
      X86AluReadSelfXor.operationGate, X86AluReadSelfXor.laneGate, X86AluReadSelfXor.selection,
      X86AluReadSite.selectedTemps, CC.doEvalExpr, CC.typeof, operation, destination, sourceReg,
      CC.PTree.gss, CC.PTree.gso, operation_compare, byte_different ge m dst src different,
      (bool_cast m).1, (bool_cast m).2, CC.Cop.semUnaryOperation, CC.Cop.semNotbool,
      CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes, CC.tattr,
      CC.tuchar, CC.tuint, CC.tint, CC.tbool, CC.Integers.Int.eq, CC.Integers.MI.eq,
      CC.Integers.Int.zero, CC.Integers.MI.zero, CC.Integers.Int.one, CC.Integers.MI.one,
      CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
      CC.Eapp, CC.E0]
  all_goals rfl

def differentLaneTemps (le : CC.TempEnv) : CC.TempEnv :=
  (le.set X86_program_profile_bpf._t'4 (.Vint (1#32))).set X86_program_profile_bpf._t'5 (.Vint (0#32))

/-- For equal registers, unequal lane bytes make the real second test
false. Its actual first-test value1 is retained in the temporary map. -/
theorem different_lanes (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (reg dstShift srcShift : BitVec 8)
    (different : dstShift ≠ srcShift)
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (2#32)))
    (destination : le.get X86_program_profile_bpf._dst = some (X86Width.argument reg))
    (sourceReg : le.get X86_program_profile_bpf._src = some (X86Width.argument reg))
    (leftShift : le.get X86_program_profile_bpf.___x86_l_dst_shift = some (X86Width.argument dstShift))
    (rightShift : le.get X86_program_profile_bpf.___x86_l_src_shift = some (X86Width.argument srcShift)) :
    InternalRun ge 10 (.State function X86AluDecode.operandReads k e le m)
      (.State function X86AluReadSite.readStatements (.Kseq X86ShiftLeftRoute.dispatch k)
        e (differentLaneTemps le) m) := by
  rw [X86AluReadSelfXor.source]
  apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, CC.doStep,
      X86AluReadSelfXor.operationGate, X86AluReadSelfXor.laneGate, X86AluReadSelfXor.selection,
      differentLaneTemps, CC.doEvalExpr, CC.typeof, operation, destination, sourceReg,
      leftShift, rightShift, CC.PTree.gss, CC.PTree.gso, operation_compare, byte_same,
      byte_different ge m dstShift srcShift different, (bool_cast m).1, (bool_cast m).2,
      CC.Cop.semUnaryOperation, CC.Cop.semNotbool, CC.Cop.boolVal, CC.Cop.classifyBool,
      CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tuint, CC.tint, CC.tbool,
      CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.zero, CC.Integers.MI.zero,
      CC.Integers.Int.one, CC.Integers.MI.one, CC.Integers.Int.repr, CC.Integers.MI.repr,
      CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Eapp, CC.E0]
  all_goals rfl

/-- Exhaustive source XOR selection: equal register/lane takes the actual
zero shortcut; every other case enters the original reader sequence. -/
theorem all_cases (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (dst src dstShift srcShift : BitVec 8)
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (2#32)))
    (destination : le.get X86_program_profile_bpf._dst = some (X86Width.argument dst))
    (sourceReg : le.get X86_program_profile_bpf._src = some (X86Width.argument src))
    (leftShift : le.get X86_program_profile_bpf.___x86_l_dst_shift = some (X86Width.argument dstShift))
    (rightShift : le.get X86_program_profile_bpf.___x86_l_src_shift = some (X86Width.argument srcShift)) :
    if dst = src then
      if dstShift = srcShift then
        InternalRun ge 11 (.State function X86AluDecode.operandReads k e le m)
          (.State function X86ShiftLeftRoute.dispatch k e (X86AluReadSelfXor.temps le) m)
      else
        InternalRun ge 10 (.State function X86AluDecode.operandReads k e le m)
          (.State function X86AluReadSite.readStatements (.Kseq X86ShiftLeftRoute.dispatch k)
            e (differentLaneTemps le) m)
    else
      InternalRun ge 10 (.State function X86AluDecode.operandReads k e le m)
        (.State function X86AluReadSite.readStatements (.Kseq X86ShiftLeftRoute.dispatch k)
          e (X86AluReadSite.selectedTemps le) m) := by
  by_cases registers : dst = src
  · subst src
    rw [if_pos rfl]
    by_cases lanes : dstShift = srcShift
    · subst srcShift
      rw [if_pos rfl]
      exact X86AluReadSelfXor.choose ge function e le k m dst dstShift
        operation destination sourceReg leftShift rightShift
    · rw [if_neg lanes]
      exact different_lanes ge function e le k m dst dstShift srcShift lanes
        operation destination sourceReg leftShift rightShift
  · rw [if_neg registers]
    exact different_registers ge function e le k m dst src registers operation destination sourceReg

end KProgFormal.ClightRefinement.X86AluReadXorSelect
