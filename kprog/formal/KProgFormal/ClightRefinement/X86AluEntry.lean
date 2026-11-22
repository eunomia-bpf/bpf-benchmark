import KProgFormal.ClightRefinement.X86RegisterView

namespace KProgFormal.ClightRefinement.X86AluEntry

private structure Pieces where
  width : CC.Stmt
  innerBody : CC.Stmt
  innerExit : CC.Stmt
  outerExit : CC.Stmt

private def pieces : Pieces :=
  match X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_body with
  | .Sloop (.Ssequence width (.Sloop innerBody innerExit)) outerExit =>
      ⟨width, innerBody, innerExit, outerExit⟩
  | _ => ⟨.Sskip, .Sskip, .Sskip, .Sskip⟩

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_alu_entry_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

def innerBody : CC.Stmt := by run_tac cachePart (← `(pieces.innerBody))
private def innerExit : CC.Stmt := by run_tac cachePart (← `(pieces.innerExit))
private def outerExit : CC.Stmt := by run_tac cachePart (← `(pieces.outerExit))
private def widthStatement : CC.Stmt :=
  .Sset X86_program_profile_bpf.___x86_l_width
    (.Ecast (.Etempvar X86_program_profile_bpf._width CC.tuchar) CC.tuchar)

def continuation (k : CC.Cont) : CC.Cont :=
  .Kloop1 innerBody innerExit
    (.Kloop1 (.Ssequence widthStatement (.Sloop innerBody innerExit)) outerExit k)

/-- The prefix and loop continuations are the actual imported handler body. -/
theorem source : X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_body =
    .Sloop (.Ssequence widthStatement (.Sloop innerBody innerExit)) outerExit := rfl

private theorem byte_cast (value : BitVec 8) :
    value.setWidth 32 &&& (255#32) = value.setWidth 32 := by
  change value.setWidth 32 &&& (BitVec.allOnes 8).setWidth 32 = value.setWidth 32
  rw [← BitVec.setWidth_and, BitVec.and_allOnes]

/-- The real handler enters its inner source body in five silent transitions,
retaining its entire memory and setting only the original width temporary. -/
theorem enter (ge : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m : CC.Mem) (width : BitVec 8)
    (observed : le.get X86_program_profile_bpf._width = some (.Vint (width.setWidth 32))) :
    InternalRun ge 5
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG
        X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_body k e le m)
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG innerBody
        (continuation k) e (le.set X86_program_profile_bpf.___x86_l_width
          (.Vint (width.setWidth 32))) m) := by
  rw [source]
  apply internalRun_of_steps
  all_goals
    simp [steps, InternalPath, InternalState, CC.doStep, widthStatement, continuation,
      CC.doEvalExpr, observed, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
      CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.typeof,
      CC.tuchar, byte_cast, CC.Eapp, CC.E0]

private def widthCall : CC.Stmt := by
  run_tac cachePart (← `(match innerBody with
    | .Ssequence (.Ssequence call _) _ => call | _ => .Sskip))
private def widthSet : CC.Stmt := by
  run_tac cachePart (← `(match innerBody with
    | .Ssequence (.Ssequence _ assign) _ => assign | _ => .Sskip))
def afterWidth : CC.Stmt := by
  run_tac cachePart (← `(match innerBody with
    | .Ssequence _ rest => rest | _ => .Sskip))

theorem width_source : innerBody =
    .Ssequence (.Ssequence widthCall widthSet) afterWidth := rfl

private def widthContinuation (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some X86_program_profile_bpf._t'1)
    X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG e le
    (.Kseq widthSet (.Kseq afterWidth (continuation k)))

def widthTemps (le : CC.TempEnv) (flags : BitVec 8) : CC.TempEnv :=
  (le.set X86_program_profile_bpf._t'1 (X86Width.result flags)).set
    X86_program_profile_bpf.___x86_l_width__1 (X86Width.result flags)

/-- The original first call enters the linked width helper with the actual
flag byte. Its continuation is derived from the source sequence. -/
private theorem width_call (ge : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (m : CC.Mem) (flags : BitVec 8) (block : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (unshadowed : e.get X86_program_profile_bpf._x86_width_effective = none)
    (observed : le.get X86_program_profile_bpf._flags = some (X86Width.argument flags)) :
    InternalRun ge 3
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG innerBody
        (continuation k) e le m)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective)
        [X86Width.argument flags] (widthContinuation e le k) m) := by
  rw [width_source]
  apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, CC.doStep, widthCall,
      widthContinuation, CC.doEvalExpr, CC.doEvalExprlist, CC.lvalOfVar,
      CC.doDerefLoc, CC.accessMode, CC.Cop.classifyFun, CC.Cop.semCast,
      CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Genv.findFunct,
      X86_program_profile_bpf.f_x86_width_effective,
      CC.typeof, CC.tuchar, CC.cc_default, CC.Integers.Int.zero_ext,
      CC.Integers.MI.zero_ext, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero,
      X86Width.argument, observed, unshadowed, binding.1, binding.2, byte_cast,
      CC.Eapp, CC.E0]

private theorem width_resume (ge : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (m : CC.Mem) (flags : BitVec 8) :
    InternalRun ge 4
      (.Returnstate (X86Width.result flags) (CC.callCont (widthContinuation e le k)) m)
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG afterWidth
        (continuation k) e (widthTemps le flags) m) := by
  apply internalRun_of_steps
  all_goals
    simp [steps, InternalPath, InternalState, CC.doStep, widthContinuation,
      widthTemps, widthSet, CC.callCont, CC.setOpttemp, CC.doEvalExpr,
      CC.PTree.gss, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
      CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.typeof, CC.tuchar,
      X86Width.result, X86Width.argument, byte_cast, CC.Eapp, CC.E0]

/-- The real source width call and assignment complete in thirteen silent
transitions for every flag byte, preserving the entire caller memory. -/
theorem effective_width (ge : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (m : CC.Mem) (flags : BitVec 8) (block : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (unshadowed : e.get X86_program_profile_bpf._x86_width_effective = none)
    (observed : le.get X86_program_profile_bpf._flags = some (X86Width.argument flags)) :
    InternalRun ge 13
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG innerBody
        (continuation k) e le m)
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG afterWidth
        (continuation k) e (widthTemps le flags) m) :=
  ((width_call ge e le k m flags block binding unshadowed observed).trans
    (X86Width.internal ge flags (widthContinuation e le k) m)).trans
      (width_resume ge e le k m flags)

/-- Genuine function entry and both real source loops compose with the first
helper call. Width and flags are read from the actual bound parameters; all
other arguments and every caller byte are unrestricted and retained. -/
theorem from_call (ge : CC.CGenv) (caller : CC.Mem) (k : CC.Cont)
    (binding op dst src aux imm : CC.Val) (flags width : BitVec 8) (block : CC.Block)
    (helper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective)) :
    let initial := X86RegisterView.writerInitialTemps binding op dst src
      (X86Width.argument flags) aux imm (X86Width.argument width)
    InternalRun ge 19
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG)
        [binding, op, dst, src, X86Width.argument flags, aux, imm, X86Width.argument width] k caller)
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG afterWidth
        (continuation k) (X86RegisterView.writerAllocation ge.genv_cenv caller).1
        (widthTemps (initial.set X86_program_profile_bpf.___x86_l_width
          (X86Width.argument width)) flags)
        (X86RegisterView.writerAllocation ge.genv_cenv caller).2) := by
  dsimp only
  let initial := X86RegisterView.writerInitialTemps binding op dst src
    (X86Width.argument flags) aux imm (X86Width.argument width)
  have widthRead : initial.get X86_program_profile_bpf._width =
      some (.Vint (width.setWidth 32)) := by
    simp only [initial, X86RegisterView.writerInitialTemps, CC.PTree.gss, X86Width.argument]
  have flagsRead : (initial.set X86_program_profile_bpf.___x86_l_width
      (X86Width.argument width)).get X86_program_profile_bpf._flags =
        some (X86Width.argument flags) := by
    simp +decide [initial, X86RegisterView.writerInitialTemps, CC.PTree.gss, CC.PTree.gso]
  have notLocal : X86_program_profile_bpf._x86_width_effective ∉
      CC.varNames X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_vars := by
    decide +kernel
  have unshadowed : (X86RegisterView.writerAllocation ge.genv_cenv caller).1.get
      X86_program_profile_bpf._x86_width_effective = none := by
    simpa only [CC.emptyEnv, CC.PTree.gempty] using CC.allocVariables_env_other
      (CC.doAllocVariables_sound _ _ _ _ _ _
        (Prod.eta (X86RegisterView.writerAllocation ge.genv_cenv caller)).symm) notLocal
  exact ((X86RegisterView.writer_entry_internal ge caller k binding op dst src
    (X86Width.argument flags) aux imm (X86Width.argument width)).trans
      (enter ge _ initial k _ width widthRead)).trans
        (effective_width ge _ _ k _ flags block helper unshadowed flagsRead)

end KProgFormal.ClightRefinement.X86AluEntry
