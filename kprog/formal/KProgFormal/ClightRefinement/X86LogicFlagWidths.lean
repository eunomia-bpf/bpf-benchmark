import KProgFormal.ClightRefinement.X86LogicFlagClassify
import KProgFormal.ClightRefinement.X86Width
import KProgFormal.ClightRefinement.X86ApplyWidth

namespace KProgFormal.ClightRefinement.X86LogicFlagWidths

private structure Pieces where
  effective : CC.Stmt
  applyWidth : CC.Stmt
  bits : CC.Stmt
  rest : CC.Stmt
  loopExit : CC.Stmt
  branchExit : CC.Stmt
  tail : CC.Stmt

private def pieces : Pieces :=
  match X86LogicFlagClassify.branch with
  | .Ssequence (.Ssequence (.Sloop
      (.Ssequence effective (.Ssequence applyWidth (.Ssequence bits rest))) loopExit) branchExit) tail =>
    ⟨effective, applyWidth, bits, rest, loopExit, branchExit, tail⟩
  | _ => ⟨.Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Sskip⟩

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_logical_width_source
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

def effective : CC.Stmt := by run_tac cachePart (← `(pieces.effective))
def applyWidth : CC.Stmt := by run_tac cachePart (← `(pieces.applyWidth))
def bits : CC.Stmt := by run_tac cachePart (← `(pieces.bits))
def rest : CC.Stmt := by run_tac cachePart (← `(pieces.rest))

private def body : CC.Stmt := .Ssequence effective (.Ssequence applyWidth (.Ssequence bits rest))

theorem source : X86LogicFlagClassify.branch =
    .Ssequence (.Ssequence (.Sloop body pieces.loopExit) pieces.branchExit) pieces.tail := rfl

def continuation (k : CC.Cont) : CC.Cont :=
  .Kloop1 body pieces.loopExit (.Kseq pieces.branchExit (.Kseq pieces.tail k))

def effectiveTemps (le : CC.TempEnv) (size : X86.Size) : CC.TempEnv :=
  (le.set X86_program_profile_bpf._t'78 (X86ShiftLeft.argument size)).set
    X86_program_profile_bpf.___x86_fl_width (X86ShiftLeft.argument size)

/-- Four original sequence/loop steps enter the real logical width call. -/
theorem enter (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) :
    InternalRun ge 4 (.State function X86LogicFlagClassify.branch k e le m)
      (.State function effective (.Kseq (.Ssequence applyWidth (.Ssequence bits rest))
        (continuation k)) e le m) := by
  rw [source]
  apply internalRun_of_steps
  all_goals simp [steps, InternalPath, InternalState, body, continuation, CC.doStep, CC.Eapp, CC.E0]

private def effectiveAssign : CC.Stmt := by
  run_tac cachePart (← `(match effective with | .Ssequence _ assignment => assignment | _ => .Sskip))

/-- The real width call and original cast/assign return the effective ISA size. -/
theorem effective_internal (ge : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block = some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_width_effective = none)
    (size : X86.Size) (k : CC.Cont) (m : CC.Mem)
    (observed : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument size)) :
    InternalRun ge 11 (.State function effective k e le m)
      (.State function .Sskip k e (effectiveTemps le size) m) := by
  obtain ⟨symbol, callee⟩ := binding
  let callK := CC.Cont.Kcall (some X86_program_profile_bpf._t'78) function e le
    (.Kseq effectiveAssign k)
  have beforeCall : InternalRun ge 2 (.State function effective k e le m)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective)
        [X86ShiftLeft.argument size] callK m) := by
    cases size <;> apply internalRun_of_steps
    all_goals
      simp +decide [steps, InternalPath, InternalState, effective, effectiveAssign, callK,
        CC.typeof, CC.tuchar, CC.cc_default, CC.doStep, CC.doEvalExpr, CC.doEvalExprlist,
        CC.lvalOfVar, CC.doDerefLoc, CC.accessMode, CC.Cop.classifyFun,
        CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Genv.findFunct,
        CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero,
        unshadowed, observed, symbol, callee, X86ShiftLeft.argument, X86.Size.bytes, CC.Eapp, CC.E0]
  have afterCall : InternalRun ge 3
      (.Returnstate (X86ShiftLeft.argument size) (CC.callCont callK) m)
      (.State function .Sskip k e (effectiveTemps le size) m) := by
    cases size <;> apply internalRun_of_steps
    all_goals
      simp +decide [steps, InternalPath, InternalState, effectiveTemps, effectiveAssign, callK,
        CC.doStep, CC.doEvalExpr, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
        CC.typeof, CC.tuchar, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
        CC.callCont, CC.setOpttemp, X86ShiftLeft.argument, X86.Size.bytes, CC.Eapp, CC.E0]
  have value : X86Width.result (BitVec.ofNat 8 size.bytes) = X86ShiftLeft.argument size := by
    cases size <;> rfl
  have argument : X86Width.argument (BitVec.ofNat 8 size.bytes) = X86ShiftLeft.argument size := by
    cases size <;> rfl
  have helper : InternalRun ge 6
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective)
        [X86ShiftLeft.argument size] callK m)
      (.Returnstate (X86ShiftLeft.argument size) (CC.callCont callK) m) := by
    simpa only [argument, value] using
      X86Width.internal ge (BitVec.ofNat 8 size.bytes) callK m
  exact (beforeCall.trans helper).trans afterCall

/-- The actual branch prefix reaches its real width-application statement. -/
theorem to_apply (ge : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block = some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_width_effective = none)
    (size : X86.Size) (k : CC.Cont) (m : CC.Mem)
    (observed : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument size)) :
    InternalRun ge 17 (.State function X86LogicFlagClassify.branch k e le m)
      (.State function applyWidth (.Kseq (.Ssequence bits rest) (continuation k)) e
        (effectiveTemps le size) m) := by
  have numerical := effective_internal ge block binding function e le unshadowed size
    (.Kseq (.Ssequence applyWidth (.Ssequence bits rest)) (continuation k)) m observed
  have next : InternalRun ge 2
      (.State function .Sskip (.Kseq (.Ssequence applyWidth (.Ssequence bits rest)) (continuation k))
        e (effectiveTemps le size) m)
      (.State function applyWidth (.Kseq (.Ssequence bits rest) (continuation k)) e
        (effectiveTemps le size) m) := by
    apply internalRun_of_steps
    all_goals simp [steps, InternalPath, InternalState, CC.doStep, CC.Eapp, CC.E0]
  exact ((enter ge function e le k m).trans numerical).trans next

end KProgFormal.ClightRefinement.X86LogicFlagWidths
