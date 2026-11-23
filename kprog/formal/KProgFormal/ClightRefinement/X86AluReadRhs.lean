import KProgFormal.ClightRefinement.X86RegisterReadScalar

namespace KProgFormal.ClightRefinement.X86AluReadRhs

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_alu_rhs_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private def assignRhs : CC.Stmt := by
  run_tac cachePart (← `(match X86AluReadSite.rhsRead with
    | .Ssequence _ assign => assign | _ => .Sskip))

private def bindingType : CC.Ty :=
  CC.tptr (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)
private def readerTypes : List CC.Ty := [bindingType, CC.tulong, CC.tulong, CC.tulong]
private def readerExpression : CC.Expr :=
  .Evar X86_program_profile_bpf._x86_sim_inline_read_reg
    (.Tfunction readerTypes CC.tulong CC.cc_default)
private def expressions : List CC.Expr :=
  [.Etempvar X86_program_profile_bpf.___x86_bind bindingType,
    .Etempvar X86_program_profile_bpf._src CC.tuchar,
    .Etempvar X86_program_profile_bpf.___x86_l_width__1 CC.tuchar,
    .Etempvar X86_program_profile_bpf.___x86_l_src_shift CC.tuchar]

/-- The RHS is the original second reader call and value-copy assignment. -/
theorem source : X86AluReadSite.rhsRead =
    .Ssequence (.Scall (some X86_program_profile_bpf._t'3) readerExpression expressions) assignRhs := rfl

def continuation (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some X86_program_profile_bpf._t'3) function e le (.Kseq assignRhs k)

private theorem pointer_cast (m : CC.Mem) (block : CC.Block) (offset : CC.Integers.Ptrofs) :
    CC.Cop.semCast (.Vptr block offset) bindingType bindingType m = some (.Vptr block offset) := rfl

private theorem byte_cast (m : CC.Mem) (code : BitVec 8) :
    CC.Cop.semCast (.Vint (code.setWidth 32)) CC.tuchar CC.tulong m =
      some (.Vlong (CC.Cop.castIntLong .Unsigned (code.setWidth 32))) := rfl

/-- Two actual transitions enter the linked RHS reader with the original
binding, source register, effective width and source-lane shift. -/
theorem enter (ge : CC.CGenv) (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (m : CC.Mem) (bindingBlock helperBlock : CC.Block)
    (bindingOffset : CC.Integers.Ptrofs) (reg width shift : BitVec 8)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock bindingOffset))
    (sourceReg : le.get X86_program_profile_bpf._src = some (.Vint (reg.setWidth 32)))
    (effectiveWidth : le.get X86_program_profile_bpf.___x86_l_width__1 = some (.Vint (width.setWidth 32)))
    (sourceShift : le.get X86_program_profile_bpf.___x86_l_src_shift = some (.Vint (shift.setWidth 32)))
    (helper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_read_reg =
        some helperBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv helperBlock =
        some (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg))
    (unshadowed : e.get X86_program_profile_bpf._x86_sim_inline_read_reg = none) :
    InternalRun ge 2 (.State function X86AluReadSite.rhsRead k e le m)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg)
        (X86AluReadSite.arguments (.Vptr bindingBlock bindingOffset) reg width shift)
        (continuation function e le k) m) := by
  have expression : CC.doEvalExpr ge e le m readerExpression = some (.Vptr helperBlock 0) := by
    simp only [readerExpression, CC.doEvalExpr, CC.lvalOfVar, unshadowed, helper.1,
      CC.doDerefLoc, CC.accessMode]
    rfl
  have args : CC.doEvalExprlist ge e le m expressions readerTypes =
      some (X86AluReadSite.arguments (.Vptr bindingBlock bindingOffset) reg width shift) := by
    simp only [expressions, readerTypes, X86AluReadSite.arguments, CC.doEvalExprlist,
      CC.doEvalExpr, CC.typeof, binding, sourceReg, effectiveWidth, sourceShift, pointer_cast, byte_cast]
  rw [source]
  refine .step trivial (.seq _ _ _ _ _ _ _) ?_
  refine .step trivial ?_ (.refl _)
  apply CC.Step.call (tyargs := readerTypes) (tyres := CC.tulong)
    (cconv := CC.cc_default) (vf := .Vptr helperBlock 0)
  · rfl
  · exact CC.doEvalExpr_sound ge e le m _ _ expression
  · exact CC.doEvalExprlist_sound ge e le m _ _ _ args
  · change CC.Genv.findFunctPtr ge.genv_genv helperBlock = _
    exact helper.2
  · rfl

def temps (le : CC.TempEnv) (value : CC.Val) : CC.TempEnv :=
  (le.set X86_program_profile_bpf._t'3 value).set X86_program_profile_bpf.___x86_l_rhs value

/-- The real RHS return, original assignment and sequence exit reach the
arithmetic dispatcher, preserving the returned raw value and complete heap. -/
theorem resume (ge : CC.CGenv) (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (m : CC.Mem) (value : CC.Val) :
    InternalRun ge 4
      (.Returnstate value (CC.callCont (continuation function e le (.Kseq X86ShiftLeftRoute.dispatch k))) m)
      (.State function X86ShiftLeftRoute.dispatch k e (temps le value) m) := by
  apply internalRun_of_steps
  all_goals
    simp only [steps, InternalPath, InternalState, CC.doStep, continuation,
      temps, assignRhs, CC.callCont, CC.setOpttemp, CC.doEvalExpr, CC.PTree.gss,
      CC.Eapp, CC.E0, List.nil_append, true_and]

/-- Updating the RHS retains the complete incoming LHS observation. -/
theorem lhs_kept (le : CC.TempEnv) (value : CC.Val) :
    (temps le value).get X86_program_profile_bpf.___x86_l_lhs =
      le.get X86_program_profile_bpf.___x86_l_lhs := by
  simp +decide [temps, CC.PTree.gso]

end KProgFormal.ClightRefinement.X86AluReadRhs
