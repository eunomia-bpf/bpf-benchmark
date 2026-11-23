import KProgFormal.ClightRefinement.X86AluReadSite

namespace KProgFormal.ClightRefinement.X86RegisterReadEntry

private structure Pieces where
  body : CC.Stmt
  reg : CC.Stmt
  width : CC.Stmt
  call : CC.Stmt
  assign : CC.Stmt
  rest : CC.Stmt
  result : CC.Stmt

private def pieces : Pieces :=
  match X86_program_profile_bpf.f_x86_sim_inline_read_reg.fn_body with
  | .Ssequence (.Sloop body@(.Ssequence reg (.Ssequence width
      (.Ssequence (.Ssequence call assign) rest))) _) result =>
      ⟨body, reg, width, call, assign, rest, result⟩
  | _ => ⟨.Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Sskip⟩

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_register_read_entry_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private def body : CC.Stmt := by run_tac cachePart (← `(pieces.body))
private def regSet : CC.Stmt := by run_tac cachePart (← `(pieces.reg))
private def widthSet : CC.Stmt := by run_tac cachePart (← `(pieces.width))
private def widthCall : CC.Stmt := by run_tac cachePart (← `(pieces.call))
private def widthAssign : CC.Stmt := by run_tac cachePart (← `(pieces.assign))
def afterWidth : CC.Stmt := by run_tac cachePart (← `(pieces.rest))
private def returnStatement : CC.Stmt := by run_tac cachePart (← `(pieces.result))

/-- Original reader body, including its own effective-width call and return. -/
theorem source : X86_program_profile_bpf.f_x86_sim_inline_read_reg.fn_body =
    .Ssequence (.Sloop (.Ssequence regSet (.Ssequence widthSet
      (.Ssequence (.Ssequence widthCall widthAssign) afterWidth))) .Sbreak)
      returnStatement := rfl

def continuation (k : CC.Cont) : CC.Cont :=
  .Kloop1 body .Sbreak (.Kseq returnStatement k)

def initialTemps (binding reg width shift : CC.Val) : CC.TempEnv :=
  ((((CC.createUndefTemps X86_program_profile_bpf.f_x86_sim_inline_read_reg.fn_temps).set
    X86_program_profile_bpf.___x86_bind binding).set X86_program_profile_bpf._reg reg).set
    X86_program_profile_bpf._width width).set X86_program_profile_bpf._shift shift

/-- The actual four reader parameters bind without allocating any local block. -/
theorem entry (ge : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (binding reg width shift : CC.Val) :
    InternalRun ge 1
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg)
        [binding, reg, width, shift] k m)
      (.State X86_program_profile_bpf.f_x86_sim_inline_read_reg
        X86_program_profile_bpf.f_x86_sim_inline_read_reg.fn_body k CC.emptyEnv
        (initialTemps binding reg width shift) m) := by
  apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, CC.doStep, CC.doFunctionEntry2,
      X86_program_profile_bpf.f_x86_sim_inline_read_reg, CC.listNorepet,
      CC.listDisjoint, CC.varNames, CC.doAllocVariables, CC.bindParameterTemps,
      initialTemps, CC.Eapp, CC.E0]

theorem byte_long_cast (m : CC.Mem) (code : BitVec 8) :
    CC.Cop.semCast (.Vlong (code.setWidth 64)) CC.tulong
      (.Tint .I8 .Unsigned CC.noattr) m =
      some (X86Width.argument code) := by
  change some (CC.Val.Vint (((code.setWidth 64).setWidth 32) &&& (255#32))) = _
  rw [BitVec.setWidth_setWidth (by decide)]
  change some (CC.Val.Vint ((code.setWidth 32) &&& (BitVec.allOnes 8).setWidth 32)) = _
  rw [← BitVec.setWidth_and, BitVec.and_allOnes]
  rfl

theorem byte_cast (m : CC.Mem) (code : BitVec 8) :
    CC.Cop.semCast (X86Width.argument code) (.Tint .I8 .Unsigned CC.noattr)
      (.Tint .I8 .Unsigned CC.noattr) m =
      some (X86Width.argument code) := by
  change some (CC.Val.Vint ((code.setWidth 32) &&& (BitVec.allOnes 8).setWidth 32)) = _
  rw [← BitVec.setWidth_and, BitVec.and_allOnes]
  rfl

def prefixTemps (le : CC.TempEnv) (reg width : BitVec 8) : CC.TempEnv :=
  (le.set X86_program_profile_bpf.___x86_rd_reg (X86Width.argument reg)).set
    X86_program_profile_bpf.___x86_rd_raw_width (X86Width.argument width)

private def callContinuation (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some X86_program_profile_bpf._t'1)
    X86_program_profile_bpf.f_x86_sim_inline_read_reg e le
    (.Kseq widthAssign (.Kseq afterWidth (continuation k)))

private def widthStatements : CC.Stmt :=
  .Ssequence (.Ssequence widthCall widthAssign) afterWidth

private theorem narrow (ge : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (reg width : BitVec 8)
    (regRead : le.get X86_program_profile_bpf._reg = some (.Vlong (reg.setWidth 64)))
    (widthRead : le.get X86_program_profile_bpf._width = some (.Vlong (width.setWidth 64))) :
    InternalRun ge 8
      (.State X86_program_profile_bpf.f_x86_sim_inline_read_reg
        X86_program_profile_bpf.f_x86_sim_inline_read_reg.fn_body k e le m)
      (.State X86_program_profile_bpf.f_x86_sim_inline_read_reg widthStatements
        (continuation k) e (prefixTemps le reg width) m) := by
  rw [source]
  apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, CC.doStep, regSet, widthSet,
      widthStatements, continuation, prefixTemps, CC.doEvalExpr, CC.typeof,
      CC.PTree.gss, CC.PTree.gso, regRead, widthRead, CC.tuchar, byte_long_cast,
      CC.Eapp, CC.E0]
  all_goals rfl

private theorem width_call (ge : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (width : BitVec 8) (block : CC.Block)
    (widthRead : le.get X86_program_profile_bpf.___x86_rd_raw_width =
      some (X86Width.argument width))
    (helper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective =
        some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (unshadowed : e.get X86_program_profile_bpf._x86_width_effective = none) :
    InternalRun ge 3
      (.State X86_program_profile_bpf.f_x86_sim_inline_read_reg widthStatements
        (continuation k) e le m)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective)
        [X86Width.argument width] (callContinuation e le k) m) := by
  refine .step trivial (.seq _ _ _ _ _ _ _) ?_
  refine .step trivial (.seq _ _ _ _ _ _ _) ?_
  refine .step trivial ?_ (.refl _)
  apply CC.Step.call (tyargs := [CC.tuchar]) (tyres := CC.tuchar)
    (cconv := CC.cc_default) (vf := .Vptr block 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr, CC.lvalOfVar, CC.doDerefLoc, CC.accessMode,
      unshadowed, helper.1]
    rfl
  · apply CC.doEvalExprlist_sound
    simp only [CC.doEvalExprlist, CC.doEvalExpr, CC.typeof, widthRead, CC.tuchar, byte_cast]
  · change CC.Genv.findFunctPtr ge.genv_genv block = _
    exact helper.2
  · rfl

/-- Real register/width narrowing and the linked width call preserve the heap. -/
theorem to_width (ge : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (reg width : BitVec 8) (block : CC.Block)
    (regRead : le.get X86_program_profile_bpf._reg = some (.Vlong (reg.setWidth 64)))
    (widthRead : le.get X86_program_profile_bpf._width = some (.Vlong (width.setWidth 64)))
    (helper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective =
        some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (unshadowed : e.get X86_program_profile_bpf._x86_width_effective = none) :
    InternalRun ge 11
      (.State X86_program_profile_bpf.f_x86_sim_inline_read_reg
        X86_program_profile_bpf.f_x86_sim_inline_read_reg.fn_body k e le m)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective)
        [X86Width.argument width] (callContinuation e (prefixTemps le reg width) k) m) := by
  have rawRead : (prefixTemps le reg width).get X86_program_profile_bpf.___x86_rd_raw_width =
      some (X86Width.argument width) := CC.PTree.gss _ _ _
  exact (narrow ge e le m k reg width regRead widthRead).trans
    (width_call ge e (prefixTemps le reg width) m k width block rawRead helper unshadowed)

def widthTemps (le : CC.TempEnv) (width : BitVec 8) : CC.TempEnv :=
  (le.set X86_program_profile_bpf._t'1 (X86Width.result width)).set
    X86_program_profile_bpf.___x86_rd_width (X86Width.result width)

/-- The real helper return and byte assignment resume the original reader. -/
theorem resume_width (ge : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (width : BitVec 8) :
    InternalRun ge 4
      (.Returnstate (X86Width.result width) (CC.callCont (callContinuation e le k)) m)
      (.State X86_program_profile_bpf.f_x86_sim_inline_read_reg afterWidth
        (continuation k) e (widthTemps le width) m) := by
  apply internalRun_of_steps
  all_goals
    simp only [steps, InternalPath, InternalState, CC.doStep, callContinuation,
      widthAssign, widthTemps, CC.callCont, CC.setOpttemp, CC.doEvalExpr,
      CC.PTree.gss, X86Width.result, CC.typeof, CC.tuchar, byte_cast,
      CC.Eapp, CC.E0, List.nil_append, true_and]

/-- Actual entry and the complete width helper reach the reader's original
shift/cell-read source in22 transitions for every three input bytes. -/
theorem from_call (ge : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (binding : CC.Val) (reg width shift : BitVec 8) (block : CC.Block)
    (helper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective =
        some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective)) :
    let le := initialTemps binding (.Vlong (reg.setWidth 64))
      (.Vlong (width.setWidth 64)) (.Vlong (shift.setWidth 64))
    InternalRun ge 22
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg)
        [binding, .Vlong (reg.setWidth 64), .Vlong (width.setWidth 64),
          .Vlong (shift.setWidth 64)] k m)
      (.State X86_program_profile_bpf.f_x86_sim_inline_read_reg afterWidth
        (continuation k) CC.emptyEnv (widthTemps (prefixTemps le reg width) width) m) := by
  dsimp only
  let le := initialTemps binding (.Vlong (reg.setWidth 64))
    (.Vlong (width.setWidth 64)) (.Vlong (shift.setWidth 64))
  have regRead : le.get X86_program_profile_bpf._reg = some (.Vlong (reg.setWidth 64)) := by
    simp +decide [le, initialTemps, CC.PTree.gss, CC.PTree.gso]
  have widthRead : le.get X86_program_profile_bpf._width = some (.Vlong (width.setWidth 64)) := by
    simp +decide [le, initialTemps, CC.PTree.gss, CC.PTree.gso]
  exact (((entry ge m k binding (.Vlong (reg.setWidth 64)) (.Vlong (width.setWidth 64))
    (.Vlong (shift.setWidth 64))).trans
      (to_width ge CC.emptyEnv le m k reg width block regRead widthRead helper
        (CC.PTree.gempty _))).trans
          (X86Width.internal ge width (callContinuation CC.emptyEnv (prefixTemps le reg width) k) m)).trans
            (resume_width ge CC.emptyEnv (prefixTemps le reg width) m k width)

theorem unsigned_byte (code : BitVec 8) :
    CC.Cop.castIntLong .Unsigned (code.setWidth 32) = code.setWidth 64 := by
  change BitVec.ofInt 64 ((code.setWidth 32).toNat : Int) = _
  rw [BitVec.toNat_setWidth_of_le (by decide), BitVec.ofInt_natCast]
  exact BitVec.eq_of_toNat_eq (by simp only [BitVec.toNat_ofNat, BitVec.toNat_setWidth])

/-- The actual ALU call-site casts supply exactly the reader's three long
arguments used above, for every input byte. -/
theorem arguments (binding : CC.Val) (reg width shift : BitVec 8) :
    X86AluReadSite.arguments binding reg width shift =
      [binding, .Vlong (reg.setWidth 64), .Vlong (width.setWidth 64),
        .Vlong (shift.setWidth 64)] := by
  simp only [X86AluReadSite.arguments, unsigned_byte]

end KProgFormal.ClightRefinement.X86RegisterReadEntry
