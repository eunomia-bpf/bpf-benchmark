import KProgFormal.ClightRefinement.X86QwordTagStage
import KProgFormal.ClightRefinement.X86RegisterTagSite

namespace KProgFormal.ClightRefinement.X86QwordDestination

private structure Parts where
  condition : CC.Expr
  active : CC.Stmt
  call : CC.Stmt
  compared : CC.Stmt
  saved : CC.Stmt

private def parts : Parts :=
  match X86QwordSelection.selected with
  | .Sifthenelse condition active (.Ssequence (.Ssequence call compared) saved) =>
    ⟨condition, active, call, compared, saved⟩
  | _ => ⟨.Econst_int 0 CC.tint, .Sskip, .Sskip, .Sskip, .Sskip⟩

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_qword_destination_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private def condition : CC.Expr := by run_tac cachePart (← `(parts.condition))
private def active : CC.Stmt := by run_tac cachePart (← `(parts.active))
private def tagCall : CC.Stmt := by run_tac cachePart (← `(parts.call))
def compared : CC.Stmt := by run_tac cachePart (← `(parts.compared))
def saved : CC.Stmt := by run_tac cachePart (← `(parts.saved))

/-- The second tag call is the original source's scalar-tag fallback. -/
theorem source : X86QwordSelection.selected = .Sifthenelse condition active
    (.Ssequence (.Ssequence tagCall compared) saved) := rfl

def temps (le : CC.TempEnv) : CC.TempEnv :=
  le.set X86_program_profile_bpf._t'133 (.Vint (0#32))

def continuation (k : CC.Cont) : CC.Cont :=
  .Kseq compared (.Kseq saved (.Kseq X86QwordSelection.fourth
    (.Kseq X86QwordSelection.fifth (.Kseq X86QwordSelection.gate k))))

/-- This identity binds the original repeated call to the shared actual site. -/
theorem call_source : tagCall = X86RegisterTagSite.statement
    X86_program_profile_bpf._t'135 X86_program_profile_bpf._dst := rfl

/-- The seven real gate transitions preceding the repeated call. -/
theorem prepare (ge : CC.CGenv) (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (memory : CC.Mem)
    (firstTag : le.get X86_program_profile_bpf._t'132 = some (X86Width.argument (0#8))) :
    InternalRun ge 7 (.State function .Sskip (X86QwordSelection.continuation k) e le memory)
      (.State function tagCall (continuation k) e (temps le) memory) := by
  apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, X86QwordSelection.continuation,
      X86QwordSelection.compared, X86QwordSelection.selected, temps, continuation,
      CC.doStep, CC.doEvalExpr, CC.typeof, firstTag, X86Width.argument,
      CC.PTree.gss, CC.PTree.gso, CC.Cop.semBinaryOperation, CC.Cop.semCmp,
      CC.Cop.classifyCmp, CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
      CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes, CC.tattr,
      CC.tuchar, CC.tuint, CC.tint, CC.tbool,
      CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.zero, CC.Integers.MI.zero,
      CC.Integers.Int.one, CC.Integers.MI.one, CC.Integers.Int.repr, CC.Integers.MI.repr,
      CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Eapp, CC.E0]
  exact ⟨rfl, rfl, rfl⟩

/-- A real scalar tag still takes the original second helper call. The
actual first comparison and scalar fallback reach that call in eight steps. -/
theorem enter (ge : CC.CGenv) (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (memory : CC.Mem) (index : Fin 16) (bindingBlock helperBlock : CC.Block)
    (offset : CC.Integers.Ptrofs)
    (firstTag : le.get X86_program_profile_bpf._t'132 = some (X86Width.argument (0#8)))
    (destination : le.get X86_program_profile_bpf._dst =
      some (X86Width.argument (X86RegisterReadValue.registerByte index)))
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock offset))
    (helper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_reg_tag = some helperBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv helperBlock =
        some (.Internal X86_program_profile_bpf.f_x86_sim_inline_reg_tag))
    (unshadowed : e.get X86_program_profile_bpf._x86_sim_inline_reg_tag = none) :
    InternalRun ge 8
      (.State function .Sskip (X86QwordSelection.continuation k) e le memory)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_reg_tag)
        [.Vptr bindingBlock offset, .Vlong ((X86RegisterReadValue.registerByte index).setWidth 64)]
        (.Kcall (some X86_program_profile_bpf._t'135) function e (temps le) (continuation k)) memory) := by
  have prior := prepare ge function e le k memory firstTag
  have readyBinding : (temps le).get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock offset) := by
    simp +decide [temps, CC.PTree.gso, binding]
  have readyDst : (temps le).get X86_program_profile_bpf._dst =
      some (X86Width.argument (X86RegisterReadValue.registerByte index)) := by
    simp +decide [temps, CC.PTree.gso, destination]
  have widen : CC.Cop.semCast (X86Width.argument (X86RegisterReadValue.registerByte index))
      CC.tuchar CC.tulong memory =
      some (.Vlong ((X86RegisterReadValue.registerByte index).setWidth 64)) := by
    change some (CC.Val.Vlong (CC.Cop.castIntLong .Unsigned
      ((X86RegisterReadValue.registerByte index).setWidth 32))) = _
    rw [X86RegisterReadEntry.unsigned_byte]
  have invoked : InternalRun ge 1
      (.State function tagCall (continuation k) e (temps le) memory)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_reg_tag)
        [.Vptr bindingBlock offset, .Vlong ((X86RegisterReadValue.registerByte index).setWidth 64)]
        (.Kcall (some X86_program_profile_bpf._t'135) function e (temps le) (continuation k)) memory) := by
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

end KProgFormal.ClightRefinement.X86QwordDestination
