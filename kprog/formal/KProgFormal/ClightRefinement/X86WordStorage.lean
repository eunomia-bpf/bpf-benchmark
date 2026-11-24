import KProgFormal.ClightRefinement.X86WordMemory
import KProgFormal.ClightRefinement.X86FullWidthStorage

namespace KProgFormal.ClightRefinement.X86WordStorage

private structure Pieces where
  first : CC.Stmt
  test : CC.Expr
  word : CC.Stmt
  rest : CC.Stmt

private def pieces : Pieces :=
  match X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_106 with
  | .Ssequence first (.Sifthenelse test word rest) => ⟨first, test, word, rest⟩
  | _ => ⟨.Sskip, .Econst_int 0 CC.tint, .Sskip, .Sskip⟩

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_word_storage_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private def first : CC.Stmt := by run_tac cachePart (← `(pieces.first))
private def test : CC.Expr := by run_tac cachePart (← `(pieces.test))
def word : CC.Stmt := by run_tac cachePart (← `(pieces.word))
private def rest : CC.Stmt := by run_tac cachePart (← `(pieces.rest))

/-- The word leaf is selected from the original handler's complete branch. -/
theorem source : X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_106 =
    .Ssequence first (.Sifthenelse test word rest) := rfl

private theorem set_twice (id : CC.Ident) (value : CC.Val) (le : CC.TempEnv) :
    (le.set id value).set id value = le.set id value := by
  induction id generalizing le with
  | xH => cases le <;> rfl
  | xO id ih => cases le <;> simp [CC.PTree.set, ih]
  | xI id ih => cases le <;> simp [CC.PTree.set, ih]

def selectionTemps (le : CC.TempEnv) : CC.TempEnv :=
  le.set X86_program_profile_bpf._t'111 (.Vint (1#32))

/-- The actual first width classifier selects low16 storage in nine steps. -/
theorem select (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (width : le.get X86_program_profile_bpf.___x86_wr_width__2 =
      some (X86ShiftLeft.argument .w)) :
    InternalRun ge 9
      (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_106 k e le memory)
      (.State function word k e (selectionTemps le) memory) := by
  rw [source]
  apply internalRun_of_steps
  all_goals simp +decide [steps, InternalPath, InternalState, CC.doStep,
    first, test, selectionTemps, CC.doEvalExpr, CC.typeof, width,
    X86ShiftLeft.argument, X86.Size.bytes, CC.PTree.gss, CC.PTree.gso,
    CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
    CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes,
    CC.tattr, CC.tuchar, CC.tuint, CC.tint, CC.Integers.Int.eq, CC.Integers.MI.eq,
    CC.Integers.Int.zero, CC.Integers.Int.one, CC.Integers.MI.zero, CC.Integers.MI.one,
    CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
    CC.Eapp, CC.E0, set_twice]

private def prelude : CC.Stmt := by
  run_tac cachePart (← `(match word with | .Ssequence prelude _ => prelude | _ => .Sskip))
private def body : CC.Stmt := by
  run_tac cachePart (← `(match word with | .Ssequence _ (.Sloop body _) => body | _ => .Sskip))
private def laneSet : CC.Stmt := by
  run_tac cachePart (← `(match body with | .Ssequence lane _ => lane | _ => .Sskip))
private def choice : CC.Stmt := by
  run_tac cachePart (← `(match body with | .Ssequence _ (.Ssequence choice _) => choice | _ => .Sskip))
private def tagSet : CC.Stmt := by
  run_tac cachePart (← `(match body with | .Ssequence _ (.Ssequence _ tag) => tag | _ => .Sskip))
private def scalar : CC.Stmt := by
  run_tac cachePart (← `(match choice with | .Sifthenelse _ scalar _ => scalar | _ => .Sskip))

theorem word_source : word =
    .Ssequence prelude (.Sloop (.Ssequence laneSet (.Ssequence choice tagSet)) .Sbreak) := rfl

def loopCont (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak k

def laneTemps (le : CC.TempEnv) (next : BitVec 64) : CC.TempEnv :=
  le.set X86_program_profile_bpf.___kprog_x86_lane__5 (.Vint (X86WordMemory.lane next))

def temps (le : CC.TempEnv) (next : BitVec 64) : CC.TempEnv :=
  (laneTemps le next).set X86_program_profile_bpf.___x86_wr_cell_tag__2 (.Vint (0#32))

private theorem cast_lane (next : BitVec 64) :
    next.setWidth 32 &&& (65535#32) = (next.setWidth 16).setWidth 32 := by
  have mask : (65535#32) = (BitVec.allOnes 16).setWidth 32 := by decide
  rw [mask]
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp only [BitVec.getLsbD_and, BitVec.getLsbD_setWidth, BitVec.getLsbD_allOnes]
  simp [hi, Bool.and_comm]

/-- Execute the real ordinary/scalar prelude, lane cast and tag branch. -/
theorem enter (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem) (dst : BitVec 8) (next : BitVec 64)
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint (dst.setWidth 32)))
    (ordinary : dst.setWidth 32 ≠ (4#32))
    (tag : le.get X86_program_profile_bpf.___x86_wr_cell_tag__2 = some (.Vint (0#32)))
    (value : le.get X86_program_profile_bpf.___x86_wr_next__2 = some (.Vlong next)) :
    InternalRun ge 10
      (.State function word k e le memory)
      (.State function scalar (.Kseq tagSet (loopCont k)) e (laneTemps le next) memory) := by
  rw [word_source]
  apply internalRun_of_steps
  all_goals simp +decide [steps, InternalPath, InternalState, prelude, laneSet, choice,
    loopCont, body, scalar, tagSet, laneTemps, X86WordMemory.lane,
    CC.doStep, CC.doEvalExpr, CC.typeof, destination, ordinary, tag, value, CC.PTree.gso,
    CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
    CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes,
    CC.tattr, CC.tuchar, CC.tushort, CC.tuint, CC.tint, CC.tulong,
    CC.Integers.Int.cmpu, CC.Integers.MI.cmpu, CC.Integers.Int.repr, CC.Integers.MI.repr,
    CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.zero,
    CC.Integers.Int.one, CC.Integers.MI.zero, CC.Integers.MI.one,
    CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
    CC.Integers.Int64.unsigned, CC.Integers.MI.unsigned,
    CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Eapp, CC.E0, cast_lane]

end KProgFormal.ClightRefinement.X86WordStorage
