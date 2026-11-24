import KProgFormal.ClightRefinement.X86RegisterTagCall

namespace KProgFormal.ClightRefinement.X86QwordSelection
open X86ShiftWriteback

private structure Parts where
  first : CC.Stmt
  second : CC.Stmt
  third : CC.Stmt
  fourth : CC.Stmt
  fifth : CC.Stmt
  gate : CC.Stmt
  call : CC.Stmt
  compared : CC.Stmt
  selected : CC.Stmt

private def parts : Parts :=
  match scalarWriter with
  | .Ssequence (.Ssequence (.Ssequence (.Ssequence (.Ssequence first second) third) fourth) fifth) gate =>
    match third with
    | .Sifthenelse _ (.Ssequence (.Ssequence call compared) selected) _ =>
      ⟨first, second, third, fourth, fifth, gate, call, compared, selected⟩
    | _ => ⟨.Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Sskip⟩
  | _ => ⟨.Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Sskip⟩

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_qword_selection_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private def first : CC.Stmt := by run_tac cachePart (← `(parts.first))
private def second : CC.Stmt := by run_tac cachePart (← `(parts.second))
private def third : CC.Stmt := by run_tac cachePart (← `(parts.third))
private def fourth : CC.Stmt := by run_tac cachePart (← `(parts.fourth))
private def fifth : CC.Stmt := by run_tac cachePart (← `(parts.fifth))
private def gate : CC.Stmt := by run_tac cachePart (← `(parts.gate))
private def tagCall : CC.Stmt := by run_tac cachePart (← `(parts.call))
def compared : CC.Stmt := by run_tac cachePart (← `(parts.compared))
def selected : CC.Stmt := by run_tac cachePart (← `(parts.selected))

/-- The selector prefix and first tag call are exact original source. -/
theorem source : scalarWriter =
    .Ssequence (.Ssequence (.Ssequence (.Ssequence (.Ssequence first second) third) fourth) fifth) gate ∧
    third = .Sifthenelse (.Etempvar X86_program_profile_bpf._t'130 CC.tint)
      (.Ssequence (.Ssequence tagCall compared) selected)
      (.Sset X86_program_profile_bpf._t'131 (.Econst_int (0#32) CC.tint)) := by
  constructor <;> rfl

def temps (le : CC.TempEnv) : CC.TempEnv :=
  (le.set X86_program_profile_bpf._t'129 (.Vint (1#32))).set
    X86_program_profile_bpf._t'130 (.Vint (1#32))

def continuation (k : CC.Cont) : CC.Cont :=
  .Kseq compared (.Kseq selected (.Kseq fourth (.Kseq fifth (.Kseq gate k))))

/-- Original qword aligned-lane selection reaches its actual destination tag
call. The helper is resolved in the real global environment, not assumed run. -/
theorem enter (ge : CC.CGenv) (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (memory : CC.Mem) (index : Fin 16) (bindingBlock helperBlock : CC.Block)
    (offset : CC.Integers.Ptrofs)
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument .q))
    (dstShift : le.get X86_program_profile_bpf.___x86_l_dst_shift = some (.Vint (0#32)))
    (srcShift : le.get X86_program_profile_bpf.___x86_l_src_shift = some (.Vint (0#32)))
    (destination : le.get X86_program_profile_bpf._dst =
      some (X86Width.argument (X86RegisterReadValue.registerByte index)))
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock offset))
    (helper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_reg_tag = some helperBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv helperBlock =
        some (.Internal X86_program_profile_bpf.f_x86_sim_inline_reg_tag))
    (unshadowed : e.get X86_program_profile_bpf._x86_sim_inline_reg_tag = none) :
    InternalRun ge 15 (.State function scalarWriter k e le memory)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_reg_tag)
        [.Vptr bindingBlock offset, .Vlong ((X86RegisterReadValue.registerByte index).setWidth 64)]
        (.Kcall (some X86_program_profile_bpf._t'132) function e (temps le) (continuation k)) memory) := by
  have widen : CC.Cop.semCast (X86Width.argument (X86RegisterReadValue.registerByte index))
      CC.tuchar CC.tulong memory =
      some (.Vlong ((X86RegisterReadValue.registerByte index).setWidth 64)) := by
    change some (CC.Val.Vlong (CC.Cop.castIntLong .Unsigned
      ((X86RegisterReadValue.registerByte index).setWidth 32))) = _
    rw [X86RegisterReadEntry.unsigned_byte]
  have prior : InternalRun ge 14 (.State function scalarWriter k e le memory)
      (.State function tagCall (continuation k) e (temps le) memory) := by
    rw [source.1]
    apply internalRun_of_steps
    all_goals
      simp +decide [steps, InternalPath, InternalState, first, second, third,
        temps, continuation, CC.doStep, CC.doEvalExpr, CC.typeof,
        CC.PTree.gss, CC.PTree.gso, width, dstShift, srcShift,
        X86ShiftLeft.argument, X86.Size.bytes,
        CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
        CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
        CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
        CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes, CC.tattr,
        CC.tuchar, CC.tuint, CC.tint, CC.tbool,
        CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.zero, CC.Integers.MI.zero,
        CC.Integers.Int.one, CC.Integers.MI.one, CC.Integers.Int.repr, CC.Integers.MI.repr,
        CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Eapp, CC.E0]
    exact ⟨rfl, rfl, rfl⟩
  have readyBinding : (temps le).get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock offset) := by
    simp +decide [temps, CC.PTree.gso, binding]
  have readyDst : (temps le).get X86_program_profile_bpf._dst =
      some (X86Width.argument (X86RegisterReadValue.registerByte index)) := by
    simp +decide [temps, CC.PTree.gso, destination]
  have invoked : InternalRun ge 1
      (.State function tagCall (continuation k) e (temps le) memory)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_reg_tag)
        [.Vptr bindingBlock offset, .Vlong ((X86RegisterReadValue.registerByte index).setWidth 64)]
        (.Kcall (some X86_program_profile_bpf._t'132) function e (temps le) (continuation k)) memory) := by
    refine .step trivial ?_ (.refl _)
    apply CC.Step.call (tyargs := [CC.tptr (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr),
      CC.tulong]) (tyres := CC.tuchar) (cconv := CC.cc_default) (vf := .Vptr helperBlock 0)
    · rfl
    · apply CC.doEvalExpr_sound
      simp only [CC.doEvalExpr, CC.lvalOfVar, CC.doDerefLoc, CC.accessMode, unshadowed, helper.1]
      rfl
    · apply CC.doEvalExprlist_sound
      simp only [CC.doEvalExprlist, CC.doEvalExpr, CC.typeof, readyBinding, readyDst, widen]
      rfl
    · change CC.Genv.findFunctPtr ge.genv_genv helperBlock = _
      exact helper.2
    · rfl
  exact prior.trans invoked

end KProgFormal.ClightRefinement.X86QwordSelection
