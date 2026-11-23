import KProgFormal.ClightRefinement.X86AluDecode

namespace KProgFormal.ClightRefinement.X86AluReadSite

private structure Pieces where
  operationGate : CC.Stmt
  laneGate : CC.Stmt
  call : CC.Stmt
  assign : CC.Stmt
  rhs : CC.Stmt

private def pieces : Pieces :=
  match X86AluDecode.operandReads with
  | .Ssequence (.Ssequence (.Ssequence op lane)
      (.Sifthenelse _ (.Ssequence (.Ssequence call assign) rhs) _)) _ =>
      ⟨op, lane, call, assign, rhs⟩
  | _ => ⟨.Sskip, .Sskip, .Sskip, .Sskip, .Sskip⟩

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_alu_read_site_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private def operationGate : CC.Stmt := by run_tac cachePart (← `(pieces.operationGate))
private def laneGate : CC.Stmt := by run_tac cachePart (← `(pieces.laneGate))
private def readCall : CC.Stmt := by run_tac cachePart (← `(pieces.call))
private def assignLhs : CC.Stmt := by run_tac cachePart (← `(pieces.assign))
def rhsRead : CC.Stmt := by run_tac cachePart (← `(pieces.rhs))

def readStatements : CC.Stmt :=
  .Ssequence (.Ssequence readCall assignLhs) rhsRead

private def selectReads : CC.Stmt :=
  .Sifthenelse (.Eunop .Onotbool (.Etempvar X86_program_profile_bpf._t'5 CC.tint) CC.tint)
    readStatements .Sskip

/-- Both XOR shortcut gates, reads and arithmetic dispatcher are actual source. -/
theorem source : X86AluDecode.operandReads =
    .Ssequence (.Ssequence (.Ssequence operationGate laneGate) selectReads)
      X86ShiftLeftRoute.dispatch := rfl

def selectedTemps (le : CC.TempEnv) : CC.TempEnv :=
  (le.set X86_program_profile_bpf._t'4 (.Vint 0)).set
    X86_program_profile_bpf._t'5 (.Vint 0)

/-- The real two XOR gates select the original operand-read statements in
ten silent transitions for every other operation, with the full heap retained. -/
theorem select_reads (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (operation : BitVec 8)
    (different : operation.setWidth 32 ≠ (2#32))
    (opRead : le.get X86_program_profile_bpf.___x86_l_alu =
      some (.Vint (operation.setWidth 32))) :
    InternalRun ge 10 (.State function X86AluDecode.operandReads k e le m)
      (.State function readStatements (.Kseq X86ShiftLeftRoute.dispatch k)
        e (selectedTemps le) m) := by
  have notXor : (operation.setWidth 32 == (2#32)) = false :=
    beq_eq_false_iff_ne.mpr different
  have compared : CC.Cop.semBinaryOperation ge.genv_cenv .Oeq
      (.Vint (operation.setWidth 32)) (.Tint .I8 .Unsigned CC.noattr)
      (.Vint (2#32)) (.Tint .I32 .Unsigned CC.noattr) m =
        some (.Vint (0#32)) := by
    change some (CC.Val.ofBool (operation.setWidth 32 == (2#32))) = _
    rw [notXor]
    rfl
  rw [source]
  apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, CC.doStep,
      operationGate, laneGate, selectReads, readStatements, selectedTemps, CC.doEvalExpr,
      compared, opRead, CC.PTree.gss, CC.typeof,
      CC.Cop.boolVal, CC.Cop.classifyBool, CC.Cop.semUnaryOperation, CC.Cop.semNotbool,
      CC.typeconv, CC.removeAttributes, CC.tattr, CC.tint, CC.tuint, CC.tuchar,
      CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.repr, CC.Integers.MI.repr,
      CC.Integers.Int.zero, CC.Integers.Int.one, CC.Integers.MI.zero,
      CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Eapp, CC.E0]

private def bindingType : CC.Ty :=
  CC.tptr (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)

private def readerTypes : List CC.Ty :=
  [bindingType, CC.tulong, CC.tulong, CC.tulong]

private def readerExpression : CC.Expr :=
  .Evar X86_program_profile_bpf._x86_sim_inline_read_reg
    (.Tfunction readerTypes CC.tulong CC.cc_default)

private def lhsExpressions : List CC.Expr :=
  [.Etempvar X86_program_profile_bpf.___x86_bind bindingType,
    .Etempvar X86_program_profile_bpf._dst CC.tuchar,
    .Etempvar X86_program_profile_bpf.___x86_l_width__1 CC.tuchar,
    .Etempvar X86_program_profile_bpf.___x86_l_dst_shift CC.tuchar]

/-- The real call's identifier, expression, argument order and signature. -/
theorem lhs_source : readCall =
    .Scall (some X86_program_profile_bpf._t'2) readerExpression lhsExpressions := rfl

def arguments (binding : CC.Val) (reg width shift : BitVec 8) : List CC.Val :=
  [binding, .Vlong (CC.Cop.castIntLong .Unsigned (reg.setWidth 32)),
    .Vlong (CC.Cop.castIntLong .Unsigned (width.setWidth 32)),
    .Vlong (CC.Cop.castIntLong .Unsigned (shift.setWidth 32))]

private theorem pointer_cast (m : CC.Mem) (block : CC.Block) (offset : CC.Integers.Ptrofs) :
    CC.Cop.semCast (.Vptr block offset) bindingType bindingType m =
      some (.Vptr block offset) := rfl

private theorem byte_cast (m : CC.Mem) (code : BitVec 8) :
    CC.Cop.semCast (.Vint (code.setWidth 32)) CC.tuchar CC.tulong m =
      some (.Vlong (CC.Cop.castIntLong .Unsigned (code.setWidth 32))) := rfl

private theorem lhs_arguments (ge : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (block : CC.Block) (offset : CC.Integers.Ptrofs)
    (reg width shift : BitVec 8)
    (bindingRead : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr block offset))
    (regRead : le.get X86_program_profile_bpf._dst = some (.Vint (reg.setWidth 32)))
    (widthRead : le.get X86_program_profile_bpf.___x86_l_width__1 =
      some (.Vint (width.setWidth 32)))
    (shiftRead : le.get X86_program_profile_bpf.___x86_l_dst_shift =
      some (.Vint (shift.setWidth 32))) :
    CC.doEvalExprlist ge e le m lhsExpressions readerTypes =
      some (arguments (.Vptr block offset) reg width shift) := by
  simp only [lhsExpressions, readerTypes, arguments, CC.doEvalExprlist, CC.doEvalExpr,
    CC.typeof, bindingRead, regRead, widthRead, shiftRead, pointer_cast, byte_cast]

/-- The actual LHS call is one relational transition. Expression evaluation,
argument casts and callee identity follow independently of the call interpreter. -/
theorem lhs_call (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (bindingBlock helperBlock : CC.Block) (bindingOffset : CC.Integers.Ptrofs)
    (reg width shift : BitVec 8)
    (bindingRead : le.get X86_program_profile_bpf.___x86_bind =
      some (.Vptr bindingBlock bindingOffset))
    (regRead : le.get X86_program_profile_bpf._dst = some (.Vint (reg.setWidth 32)))
    (widthRead : le.get X86_program_profile_bpf.___x86_l_width__1 =
      some (.Vint (width.setWidth 32)))
    (shiftRead : le.get X86_program_profile_bpf.___x86_l_dst_shift =
      some (.Vint (shift.setWidth 32)))
    (helper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_read_reg =
        some helperBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv helperBlock =
        some (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg))
    (unshadowed : e.get X86_program_profile_bpf._x86_sim_inline_read_reg = none) :
    InternalRun ge 1 (.State function readCall k e le m)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg)
        (arguments (.Vptr bindingBlock bindingOffset) reg width shift)
        (.Kcall (some X86_program_profile_bpf._t'2) function e le k) m) := by
  have expression : CC.doEvalExpr ge e le m readerExpression =
      some (.Vptr helperBlock 0) := by
    simp only [readerExpression, CC.doEvalExpr, CC.lvalOfVar, unshadowed, helper.1,
      CC.doDerefLoc, CC.accessMode]
    rfl
  have callee : CC.Genv.findFunct ge.genv_genv (.Vptr helperBlock 0) =
      some (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg) := by
    change CC.Genv.findFunctPtr ge.genv_genv helperBlock = _
    exact helper.2
  have signature : CC.typeOfFundef (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg) =
      .Tfunction readerTypes CC.tulong CC.cc_default := rfl
  rw [lhs_source]
  refine .step trivial ?_ (.refl _)
  exact .call function (some X86_program_profile_bpf._t'2) readerExpression lhsExpressions
    k e le m readerTypes CC.tulong CC.cc_default (.Vptr helperBlock 0)
    (arguments (.Vptr bindingBlock bindingOffset) reg width shift)
    (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg) rfl
    (CC.doEvalExpr_sound ge e le m _ _ expression)
    (CC.doEvalExprlist_sound ge e le m _ _ _
      (lhs_arguments ge e le m bindingBlock bindingOffset reg width shift
        bindingRead regRead widthRead shiftRead)) callee signature

def callContinuation (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) : CC.Cont :=
  .Kcall (some X86_program_profile_bpf._t'2) function e le
    (.Kseq assignLhs (.Kseq rhsRead k))

/-- The two original sequences followed by the real LHS call. -/
theorem first_read (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (bindingBlock helperBlock : CC.Block) (bindingOffset : CC.Integers.Ptrofs)
    (reg width shift : BitVec 8)
    (bindingRead : le.get X86_program_profile_bpf.___x86_bind =
      some (.Vptr bindingBlock bindingOffset))
    (regRead : le.get X86_program_profile_bpf._dst = some (.Vint (reg.setWidth 32)))
    (widthRead : le.get X86_program_profile_bpf.___x86_l_width__1 =
      some (.Vint (width.setWidth 32)))
    (shiftRead : le.get X86_program_profile_bpf.___x86_l_dst_shift =
      some (.Vint (shift.setWidth 32)))
    (helper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_read_reg =
        some helperBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv helperBlock =
        some (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg))
    (unshadowed : e.get X86_program_profile_bpf._x86_sim_inline_read_reg = none) :
    InternalRun ge 3 (.State function readStatements k e le m)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg)
        (arguments (.Vptr bindingBlock bindingOffset) reg width shift)
        (callContinuation function e le k) m) := by
  refine .step trivial (.seq _ _ _ _ _ _ _) ?_
  refine .step trivial (.seq _ _ _ _ _ _ _) ?_
  exact lhs_call ge function e le (.Kseq assignLhs (.Kseq rhsRead k)) m
    bindingBlock helperBlock bindingOffset reg width shift bindingRead regRead widthRead
    shiftRead helper unshadowed

/-- The original XOR gates and both sequences enter the actual reader with
the original four arguments. The two scratch writes retain all incoming values. -/
theorem to_first_read (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (operation reg width shift : BitVec 8)
    (bindingBlock helperBlock : CC.Block) (bindingOffset : CC.Integers.Ptrofs)
    (different : operation.setWidth 32 ≠ (2#32))
    (opRead : le.get X86_program_profile_bpf.___x86_l_alu =
      some (.Vint (operation.setWidth 32)))
    (bindingRead : le.get X86_program_profile_bpf.___x86_bind =
      some (.Vptr bindingBlock bindingOffset))
    (regRead : le.get X86_program_profile_bpf._dst = some (.Vint (reg.setWidth 32)))
    (widthRead : le.get X86_program_profile_bpf.___x86_l_width__1 =
      some (.Vint (width.setWidth 32)))
    (shiftRead : le.get X86_program_profile_bpf.___x86_l_dst_shift =
      some (.Vint (shift.setWidth 32)))
    (helper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_read_reg =
        some helperBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv helperBlock =
        some (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg))
    (unshadowed : e.get X86_program_profile_bpf._x86_sim_inline_read_reg = none) :
    InternalRun ge 13 (.State function X86AluDecode.operandReads k e le m)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg)
        (arguments (.Vptr bindingBlock bindingOffset) reg width shift)
        (callContinuation function e (selectedTemps le) (.Kseq X86ShiftLeftRoute.dispatch k)) m) := by
  have bindingReady : (selectedTemps le).get X86_program_profile_bpf.___x86_bind =
      some (.Vptr bindingBlock bindingOffset) := by
    simp +decide [selectedTemps, CC.PTree.gso, bindingRead]
  have regReady : (selectedTemps le).get X86_program_profile_bpf._dst =
      some (.Vint (reg.setWidth 32)) := by
    simp +decide [selectedTemps, CC.PTree.gso, regRead]
  have widthReady : (selectedTemps le).get X86_program_profile_bpf.___x86_l_width__1 =
      some (.Vint (width.setWidth 32)) := by
    simp +decide [selectedTemps, CC.PTree.gso, widthRead]
  have shiftReady : (selectedTemps le).get X86_program_profile_bpf.___x86_l_dst_shift =
      some (.Vint (shift.setWidth 32)) := by
    simp +decide [selectedTemps, CC.PTree.gso, shiftRead]
  exact (select_reads ge function e le k m operation different opRead).trans
    (first_read ge function e (selectedTemps le) (.Kseq X86ShiftLeftRoute.dispatch k) m
      bindingBlock helperBlock bindingOffset reg width shift bindingReady regReady
      widthReady shiftReady helper unshadowed)

def lhsTemps (le : CC.TempEnv) (value : CC.Val) : CC.TempEnv :=
  (le.set X86_program_profile_bpf._t'2 value).set
    X86_program_profile_bpf.___x86_l_lhs value

/-- The actual helper return and original LHS assignment resume the RHS read
in four silent transitions, retaining the returned raw value and complete heap. -/
theorem resume_lhs (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (value : CC.Val) :
    InternalRun ge 4
      (.Returnstate value (CC.callCont (callContinuation function e le k)) m)
      (.State function rhsRead k e (lhsTemps le value) m) := by
  apply internalRun_of_steps
  all_goals
    simp only [steps, InternalPath, InternalState, CC.doStep, callContinuation,
      lhsTemps, assignLhs, CC.callCont, CC.setOpttemp, CC.doEvalExpr,
      CC.PTree.gss, CC.Eapp, CC.E0, List.nil_append, true_and]

/-- Actual function entry, width and aux decoding, XOR gates and reader call
compose from the original eight arguments. The four reader values and helper
scope are derived from the genuine entry, and its allocated heap is retained. -/
theorem from_call (ge : CC.CGenv) (caller : CC.Mem) (k : CC.Cont)
    (bindingBlock : CC.Block) (bindingOffset : CC.Integers.Ptrofs)
    (op imm : CC.Val) (dst src flags width : BitVec 8) (aux : BitVec 32)
    (widthBlock readerBlock : CC.Block)
    (different : (aux.setWidth 8).setWidth 32 ≠ (2#32))
    (widthHelper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective =
        some widthBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv widthBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (readerHelper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_read_reg =
        some readerBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv readerBlock =
        some (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg)) :
    let initial := X86RegisterView.writerInitialTemps (.Vptr bindingBlock bindingOffset) op
      (X86Width.argument dst) (X86Width.argument src) (X86Width.argument flags)
      (.Vint aux) imm (X86Width.argument width)
    let ready := X86AluDecode.temps (X86AluEntry.widthTemps
      (initial.set X86_program_profile_bpf.___x86_l_width (X86Width.argument width)) flags) aux
    InternalRun ge 50
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG)
        [.Vptr bindingBlock bindingOffset, op, X86Width.argument dst, X86Width.argument src,
          X86Width.argument flags, .Vint aux, imm, X86Width.argument width] k caller)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg)
        (arguments (.Vptr bindingBlock bindingOffset) dst (if flags == 0 then 8 else flags)
          ((aux >>> 8).setWidth 8))
        (callContinuation X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG
          (X86RegisterView.writerAllocation ge.genv_cenv caller).1 (selectedTemps ready)
          (.Kseq X86ShiftLeftRoute.dispatch (X86AluEntry.continuation k)))
        (X86RegisterView.writerAllocation ge.genv_cenv caller).2) := by
  dsimp only
  let initial := X86RegisterView.writerInitialTemps (.Vptr bindingBlock bindingOffset) op
    (X86Width.argument dst) (X86Width.argument src) (X86Width.argument flags)
    (.Vint aux) imm (X86Width.argument width)
  let afterWidth := X86AluEntry.widthTemps
    (initial.set X86_program_profile_bpf.___x86_l_width (X86Width.argument width)) flags
  let ready := X86AluDecode.temps afterWidth aux
  have opReady : ready.get X86_program_profile_bpf.___x86_l_alu =
      some (.Vint ((aux.setWidth 8).setWidth 32)) := by
    simpa only [ready, X86AluDecode.field_byte, BitVec.ushiftRight_zero] using
      (X86AluDecode.observations afterWidth aux).1
  have shiftReady : ready.get X86_program_profile_bpf.___x86_l_dst_shift =
      some (.Vint (((aux >>> 8).setWidth 8).setWidth 32)) := by
    simpa only [ready, X86AluDecode.field_byte] using
      (X86AluDecode.observations afterWidth aux).2.1
  have bindingReady : ready.get X86_program_profile_bpf.___x86_bind =
      some (.Vptr bindingBlock bindingOffset) := by
    simp +decide [ready, afterWidth, initial, X86AluDecode.temps, X86AluEntry.widthTemps,
      X86RegisterView.writerInitialTemps, CC.PTree.gss, CC.PTree.gso]
  have regReady : ready.get X86_program_profile_bpf._dst =
      some (.Vint (dst.setWidth 32)) := by
    simp +decide [ready, afterWidth, initial, X86AluDecode.temps, X86AluEntry.widthTemps,
      X86RegisterView.writerInitialTemps, X86Width.argument, CC.PTree.gss, CC.PTree.gso]
  have widthReady : ready.get X86_program_profile_bpf.___x86_l_width__1 =
      some (.Vint ((if flags == 0 then 8 else flags).setWidth 32)) := by
    simp +decide [ready, afterWidth, X86AluDecode.temps, X86AluEntry.widthTemps,
      X86Width.result, X86Width.argument, CC.PTree.gss, CC.PTree.gso]
  have notLocal : X86_program_profile_bpf._x86_sim_inline_read_reg ∉
      CC.varNames X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_vars := by
    decide +kernel
  have unshadowed : (X86RegisterView.writerAllocation ge.genv_cenv caller).1.get
      X86_program_profile_bpf._x86_sim_inline_read_reg = none := by
    simpa only [CC.emptyEnv, CC.PTree.gempty] using CC.allocVariables_env_other
      (CC.doAllocVariables_sound _ _ _ _ _ _
        (Prod.eta (X86RegisterView.writerAllocation ge.genv_cenv caller)).symm) notLocal
  exact (X86AluDecode.from_call ge caller k (.Vptr bindingBlock bindingOffset) op
    (X86Width.argument dst) (X86Width.argument src) imm aux flags width
    widthBlock widthHelper).trans
      (to_first_read ge _ _ ready (X86AluEntry.continuation k) _ (aux.setWidth 8) dst
        (if flags == 0 then 8 else flags) ((aux >>> 8).setWidth 8)
        bindingBlock readerBlock bindingOffset different opReady bindingReady regReady
        widthReady shiftReady readerHelper unshadowed)

end KProgFormal.ClightRefinement.X86AluReadSite
