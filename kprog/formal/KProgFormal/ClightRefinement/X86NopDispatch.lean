import KProgFormal.Clight.X86Inline
import KProgFormal.ClightRefinement.X86NopNative

namespace KProgFormal.ClightRefinement.X86NopDispatch

/-- Generic and profile exports retain the same original NOP function. -/
theorem handler_source : X86Inline.f_x86_sim_inline_arm_DISP_NOP = X86NopCall.handler := by rfl

/-- The generic export has a distinct normalized temporary, so its real
six-step execution is proved directly against the shared width contract. -/
private theorem width_execution (ge : CC.CGenv) (code : BitVec 8) (k : CC.Cont) (m : CC.Mem) :
    steps ge 6 (.Callstate (.Internal X86Inline.f_x86_width_effective)
      [X86Width.argument code] k m) = some (CC.E0, .Returnstate (X86Width.result code) (CC.callCont k) m) ∧
    InternalPath ge 6 (.Callstate (.Internal X86Inline.f_x86_width_effective)
      [X86Width.argument code] k m) := by
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  have ids : X86Inline._code ≠ X86Inline._t'1 := by decide
  by_cases hz : code = 0
  all_goals
    simp [empty, hz, ids, CC.typeof, CC.typeconv, CC.removeAttributes,
    CC.tattr, CC.tuchar, CC.tuint, CC.tint, steps, InternalPath, InternalState, X86Width.argument, X86Width.result,
    CC.doStep, CC.doFunctionEntry2,
    X86Inline.f_x86_width_effective, CC.listNorepet, CC.varNames,
    CC.listDisjoint, CC.doAllocVariables, CC.bindParameterTemps, CC.createUndefTemps,
    CC.doEvalExpr, CC.typeconv, CC.removeAttributes, CC.tattr, CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
    CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.Cop.boolVal, CC.Cop.classifyBool, CC.Val.ofBool,
    CC.Integers.Int.cmpu, CC.Integers.MI.cmpu,
    CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.zero,
    CC.Integers.Int.one, CC.Integers.MI.zero, CC.Integers.MI.one,
    CC.Integers.Int.repr, CC.Integers.MI.repr,
    CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
    CC.Eapp, CC.E0, CC.Val.Vtrue, CC.Val.Vfalse, CC.blocksOfEnv, CC.emptyEnv, CC.Mem.freeList]

  all_goals
    have nonzero : code.setWidth 32 ≠ (0#32) := by
      intro heq
      apply hz
      have low := congrArg (fun v : BitVec 32 => v.setWidth 8) heq
      simpa using low
    simp_all [CC.doEvalExpr, CC.Cop.semCast, CC.Cop.classifyCast,
      CC.Cop.castIntInt, CC.typeof, CC.Mem.freeList]

  all_goals
    change code.setWidth 32 &&& (BitVec.allOnes 8).setWidth 32 = code.setWidth 32
    rw [← BitVec.setWidth_and, BitVec.and_allOnes]


private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_nop_dispatch_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

def handler : CC.Function := X86Inline.f_x86_sim_inline_execute
private def widthCall : CC.Stmt := by
  run_tac cachePart (← `(match handler.fn_body with
    | .Sloop (.Ssequence (.Ssequence call _) _) _ => call | _ => .Sskip))
private def widthSet : CC.Stmt := by
  run_tac cachePart (← `(match handler.fn_body with
    | .Sloop (.Ssequence (.Ssequence _ assign) _) _ => assign | _ => .Sskip))
private def decision : CC.Stmt := by
  run_tac cachePart (← `(match handler.fn_body with
    | .Sloop (.Ssequence _ choose) _ => choose | _ => .Sskip))
private def nopCall : CC.Stmt := by
  run_tac cachePart (← `(match decision with
    | .Sifthenelse _ call _ => call | _ => .Sskip))
private def other : CC.Stmt := by
  run_tac cachePart (← `(match decision with
    | .Sifthenelse _ _ rest => rest | _ => .Sskip))
private def test : CC.Expr := .Ebinop .Oeq (.Etempvar X86Inline._op CC.tuchar)
  (.Econst_int (0#32) CC.tuint) CC.tint
private def loopBody : CC.Stmt := .Ssequence (.Ssequence widthCall widthSet) decision
private def loopCont (k : CC.Cont) : CC.Cont := .Kloop1 loopBody .Sbreak k

/-- Original generic dispatch source, including every unselected arm. -/
theorem source : handler.fn_body = .Sloop loopBody .Sbreak ∧
    decision = .Sifthenelse test nopCall other := by constructor <;> rfl

private def initialTemps (binding : CC.Block) (offset : CC.Integers.Ptrofs)
    (dst src flags : BitVec 8) (aux : BitVec 32) (imm : BitVec 64) : CC.TempEnv :=
  (((((((CC.createUndefTemps handler.fn_temps).set X86Inline.___x86_bind (.Vptr binding offset)).set
    X86Inline._op (.Vint (0#32))).set X86Inline._dst (X86Width.argument dst)).set
    X86Inline._src (X86Width.argument src)).set X86Inline._flags (X86Width.argument flags)).set
    X86Inline._aux (.Vint aux)).set X86Inline._imm (.Vlong imm)

private theorem entry (ge : CC.CGenv) (memory : CC.Mem) (k : CC.Cont)
    (binding : CC.Block) (offset : CC.Integers.Ptrofs) (dst src flags : BitVec 8) (aux : BitVec 32) (imm : BitVec 64) :
    InternalRun ge 1
      (.Callstate (.Internal handler)
        [.Vptr binding offset, .Vint (0#32), X86Width.argument dst, X86Width.argument src,
          X86Width.argument flags, .Vint aux, .Vlong imm] k memory)
      (.State handler handler.fn_body k CC.emptyEnv (initialTemps binding offset dst src flags aux imm) memory) := by
  have entered : CC.FunctionEntry2 ge handler
      [.Vptr binding offset, .Vint (0#32), X86Width.argument dst, X86Width.argument src,
        X86Width.argument flags, .Vint aux, .Vlong imm] memory CC.emptyEnv
      (initialTemps binding offset dst src flags aux imm) memory :=
    .intro (by decide +kernel) (by decide +kernel) (by decide +kernel) (.nil _ _) rfl
  exact .step trivial (.internal_function _ _ _ _ _ _ _ entered) (.refl _)

private theorem byte_cast (value : BitVec 8) : value.setWidth 32 &&& (255#32) = value.setWidth 32 := by
  change value.setWidth 32 &&& (BitVec.allOnes 8).setWidth 32 = value.setWidth 32
  rw [← BitVec.setWidth_and, BitVec.and_allOnes]

private def widthCont (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some X86Inline._t'1) handler CC.emptyEnv le (.Kseq widthSet (.Kseq decision (loopCont k)))
private def widthTemps (le : CC.TempEnv) (flags : BitVec 8) : CC.TempEnv :=
  (le.set X86Inline._t'1 (X86Width.result flags)).set X86Inline.___x86_dispatch_width (X86Width.result flags)

private theorem width_call (ge : CC.CGenv) (memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (flags : BitVec 8) (block : CC.Block)
    (symbol : CC.Genv.findSymbol ge.genv_genv X86Inline._x86_width_effective = some block)
    (global : CC.Genv.findFunctPtr ge.genv_genv block = some (.Internal X86Inline.f_x86_width_effective))
    (observed : le.get X86Inline._flags = some (X86Width.argument flags)) :
    InternalRun ge 4 (.State handler handler.fn_body k CC.emptyEnv le memory)
      (.Callstate (.Internal X86Inline.f_x86_width_effective) [X86Width.argument flags] (widthCont le k) memory) := by
  rw [source.1]
  apply internalRun_of_steps
  all_goals simp +decide [steps, InternalPath, InternalState, CC.doStep, loopBody, widthCall, widthCont, loopCont,
    CC.doEvalExpr, CC.doEvalExprlist, CC.lvalOfVar, CC.doDerefLoc, CC.accessMode,
    CC.Cop.classifyFun, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.Genv.findFunct, CC.typeof, CC.tuchar, CC.cc_default, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
    CC.Integers.Ptrofs.zero, CC.Integers.MI.zero, X86Width.argument, observed, CC.emptyEnv, CC.PTree.gempty,
    symbol, global, byte_cast, CC.Eapp, CC.E0]

private theorem width_resume (ge : CC.CGenv) (memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (flags : BitVec 8) :
    InternalRun ge 4 (.Returnstate (X86Width.result flags) (CC.callCont (widthCont le k)) memory)
      (.State handler decision (loopCont k) CC.emptyEnv (widthTemps le flags) memory) := by
  apply internalRun_of_steps
  all_goals simp [steps, InternalPath, InternalState, CC.doStep, widthCont, widthTemps, widthSet,
    CC.callCont, CC.setOpttemp, CC.doEvalExpr, CC.PTree.gss, CC.Cop.semCast, CC.Cop.classifyCast,
    CC.Cop.castIntInt, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.typeof, CC.tuchar,
    X86Width.result, X86Width.argument, byte_cast, CC.Eapp, CC.E0]

private structure Core (le : CC.TempEnv) (binding : CC.Block) (offset : CC.Integers.Ptrofs)
    (dst src flags : BitVec 8) (aux : BitVec 32) (imm : BitVec 64) : Prop where
  binding : le.get X86Inline.___x86_bind = some (.Vptr binding offset)
  op : le.get X86Inline._op = some (.Vint (0#32))
  dst : le.get X86Inline._dst = some (X86Width.argument dst)
  src : le.get X86Inline._src = some (X86Width.argument src)
  flagsRead : le.get X86Inline._flags = some (X86Width.argument flags)
  aux : le.get X86Inline._aux = some (.Vint aux)
  imm : le.get X86Inline._imm = some (.Vlong imm)
  width : le.get X86Inline.___x86_dispatch_width = some (X86Width.result flags)

private def nopCont (le : CC.TempEnv) (k : CC.Cont) : CC.Cont := .Kcall none handler CC.emptyEnv le (loopCont k)
private def nopExpression : CC.Expr := by
  run_tac cachePart (← `(match nopCall with | .Scall _ expression _ => expression | _ => .Econst_int (0#32) CC.tint))
private def nopExpressions : List CC.Expr := by
  run_tac cachePart (← `(match nopCall with | .Scall _ _ expressions => expressions | _ => []))
private def nopTypes : List CC.Ty :=
  [CC.tptr (.Tstruct X86Inline._x86_sim_inline_bindings CC.noattr), CC.tuchar, CC.tuchar,
    CC.tuchar, CC.tuchar, CC.tuint, CC.tulong, CC.tuchar]
private theorem nop_call_source : nopCall = .Scall none nopExpression nopExpressions := rfl
private theorem argument_cast (memory : CC.Mem) (code : BitVec 8) :
    CC.Cop.semCast (X86Width.argument code) CC.tuchar CC.tuchar memory = some (X86Width.argument code) := by
  simp +decide [X86Width.argument, CC.tuchar, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, byte_cast]

private theorem choose_call (ge : CC.CGenv) (memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (binding : CC.Block) (offset : CC.Integers.Ptrofs) (dst src flags : BitVec 8) (aux : BitVec 32) (imm : BitVec 64)
    (block : CC.Block)
    (symbol : CC.Genv.findSymbol ge.genv_genv X86Inline._x86_sim_inline_arm_DISP_NOP = some block)
    (global : CC.Genv.findFunctPtr ge.genv_genv block = some (.Internal X86Inline.f_x86_sim_inline_arm_DISP_NOP))
    (core : Core le binding offset dst src flags aux imm) :
    InternalRun ge 2 (.State handler decision (loopCont k) CC.emptyEnv le memory)
      (.Callstate (.Internal X86NopCall.handler)
        [.Vptr binding offset, .Vint (0#32), X86Width.argument dst, X86Width.argument src,
          X86Width.argument flags, .Vint aux, .Vlong imm, X86Width.result flags] (nopCont le k) memory) := by
  have comparison : CC.Cop.semBinaryOperation ge.genv_cenv .Oeq (.Vint (0#32)) CC.tuchar
      (.Vint (0#32)) CC.tuint memory = some .Vtrue := rfl
  have truth : CC.Cop.boolVal .Vtrue CC.tint memory = some true := rfl
  have guard : InternalRun ge 1 (.State handler decision (loopCont k) CC.emptyEnv le memory)
      (.State handler nopCall (loopCont k) CC.emptyEnv le memory) := by
    rw [source.2]
    apply internalRun_of_steps
    all_goals simp only [steps, InternalPath, InternalState, CC.doStep, test, CC.doEvalExpr, core.op,
      CC.typeof, comparison, truth, ite_true, CC.Eapp, CC.E0, List.nil_append, true_and]
  have call : InternalRun ge 1 (.State handler nopCall (loopCont k) CC.emptyEnv le memory)
      (.Callstate (.Internal X86NopCall.handler)
        [.Vptr binding offset, .Vint (0#32), X86Width.argument dst, X86Width.argument src,
          X86Width.argument flags, .Vint aux, .Vlong imm, X86Width.result flags] (nopCont le k) memory) := by
    have expression : CC.doEvalExpr ge CC.emptyEnv le memory nopExpression = some (.Vptr block 0) := by
      simp only [nopExpression, CC.doEvalExpr, CC.lvalOfVar, CC.emptyEnv, CC.PTree.gempty, symbol,
        CC.doDerefLoc, CC.accessMode]
      rfl
    have args : CC.doEvalExprlist ge CC.emptyEnv le memory nopExpressions nopTypes =
        some [.Vptr binding offset, .Vint (0#32), X86Width.argument dst, X86Width.argument src,
          X86Width.argument flags, .Vint aux, .Vlong imm, X86Width.result flags] := by
      simp only [nopExpressions, nopTypes, CC.doEvalExprlist, CC.doEvalExpr, CC.typeof,
        core.binding, core.op, core.dst, core.src, core.flagsRead, core.aux, core.imm, core.width,
        X86Width.result, argument_cast]
      rfl
    rw [nop_call_source]
    refine .step trivial ?_ (.refl _)
    apply CC.Step.call (tyargs := nopTypes) (tyres := CC.tvoid) (cconv := CC.cc_default) (vf := .Vptr block 0)
    · rfl
    · exact CC.doEvalExpr_sound ge CC.emptyEnv le memory _ _ expression
    · exact CC.doEvalExprlist_sound ge CC.emptyEnv le memory _ _ _ args
    · change CC.Genv.findFunctPtr ge.genv_genv block = _
      simpa only [handler_source] using global
    · rfl

  exact guard.trans call

private theorem resume (ge : CC.CGenv) (memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (boundary : CC.isCallCont k = true) :
    InternalRun ge 4 (.Returnstate .Vundef (nopCont le k) memory) (.Returnstate .Vundef k memory) := by
  have freed : CC.Mem.freeList memory (CC.blocksOfEnv ge.genv_cenv CC.emptyEnv) = some memory := rfl
  cases k <;> simp only [CC.isCallCont, Bool.false_eq_true] at boundary
  all_goals apply internalRun_of_steps
  all_goals simp +decide [steps, InternalPath, InternalState, CC.doStep, nopCont, loopCont,
    CC.callCont, CC.setOpttemp, freed, CC.Eapp, CC.E0]

/-- The original generic dispatcher enters its real width helper, selects
NOP, calls the identical proved handler and exits its genuine loop/free/return.
Every byte operand and flag code, heap and caller boundary is covered. -/
theorem execute (ge : CC.CGenv) (memory : CC.Mem) (k : CC.Cont)
    (binding : CC.Block) (offset : CC.Integers.Ptrofs) (dst src flags : BitVec 8) (aux : BitVec 32) (imm : BitVec 64)
    (widthBlock nopBlock : CC.Block)
    (widthSymbol : CC.Genv.findSymbol ge.genv_genv X86Inline._x86_width_effective = some widthBlock)
    (widthGlobal : CC.Genv.findFunctPtr ge.genv_genv widthBlock = some (.Internal X86Inline.f_x86_width_effective))
    (nopSymbol : CC.Genv.findSymbol ge.genv_genv X86Inline._x86_sim_inline_arm_DISP_NOP = some nopBlock)
    (nopGlobal : CC.Genv.findFunctPtr ge.genv_genv nopBlock = some (.Internal X86Inline.f_x86_sim_inline_arm_DISP_NOP))
    (boundary : CC.isCallCont k = true) :
    InternalRun ge 27
      (.Callstate (.Internal handler)
        [.Vptr binding offset, .Vint (0#32), X86Width.argument dst, X86Width.argument src,
          X86Width.argument flags, .Vint aux, .Vlong imm] k memory)
      (.Returnstate .Vundef k memory) := by
  let le := initialTemps binding offset dst src flags aux imm
  have observed : le.get X86Inline._flags = some (X86Width.argument flags) := by
    simp +decide [le, initialTemps, CC.PTree.gso, CC.PTree.gss]
  have core : Core (widthTemps le flags) binding offset dst src flags aux imm := by
    constructor <;> simp +decide [le, widthTemps, initialTemps, CC.PTree.gso, CC.PTree.gss]
  have first := (entry ge memory k binding offset dst src flags aux imm).trans
    (width_call ge memory le k flags widthBlock widthSymbol widthGlobal observed)
  have widthRun := internalRun_of_steps (width_execution ge flags (widthCont le k) memory).2
    (width_execution ge flags (widthCont le k) memory).1
  have chosen := ((first.trans widthRun).trans (width_resume ge memory le k flags)).trans
    (choose_call ge memory (widthTemps le flags) k binding offset dst src flags aux imm nopBlock nopSymbol nopGlobal core)
  have called := X86NopCall.execute ge memory (nopCont (widthTemps le flags) k)
    (.Vptr binding offset) (.Vint (0#32)) (X86Width.argument dst) (X86Width.argument src) (X86Width.argument flags)
    (.Vint aux) (.Vlong imm) (if flags == 0 then 8 else flags) rfl
  exact (chosen.trans called).trans (resume ge memory (widthTemps le flags) k boundary)

/-- The real generic-dispatch NOP case refines the same canonical checked
ISA step, retaining the entire C heap and all native state except PC. No
provider ABI, tag, permission, width-code or ignored-operand case is excluded. -/
theorem refines (ge : CC.CGenv) (memory : CC.Mem) (k : CC.Cont)
    (binding : CC.Block) (offset : CC.Integers.Ptrofs) (dst src flags : BitVec 8) (aux : BitVec 32) (imm : BitVec 64)
    (widthBlock nopBlock : CC.Block)
    (widthSymbol : CC.Genv.findSymbol ge.genv_genv X86Inline._x86_width_effective = some widthBlock)
    (widthGlobal : CC.Genv.findFunctPtr ge.genv_genv widthBlock = some (.Internal X86Inline.f_x86_width_effective))
    (nopSymbol : CC.Genv.findSymbol ge.genv_genv X86Inline._x86_sim_inline_arm_DISP_NOP = some nopBlock)
    (nopGlobal : CC.Genv.findFunctPtr ge.genv_genv nopBlock = some (.Internal X86Inline.f_x86_sim_inline_arm_DISP_NOP))
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (cells : CC.Block) (base : CC.Integers.Ptrofs) (places : X86LogicFlagOrder.Locations)
    (state : Reference.X86.State) (nextPc : BitVec 64)
    (registers : X86RegisterView.RegistersRepresent addresses origins memory cells base (X86LogicReference.input state))
    (flagBytes : X86LogicFlagMemory.FlagsRepresent memory places (X86LogicReference.input state).flags)
    (running : state.modelError = none) (boundary : CC.isCallCont k = true) :
    let native := Reference.X86.step (.nop nextPc) state
    InternalRun ge 27
      (.Callstate (.Internal handler)
        [.Vptr binding offset, .Vint (0#32), X86Width.argument dst, X86Width.argument src,
          X86Width.argument flags, .Vint aux, .Vlong imm] k memory)
      (.Returnstate .Vundef k memory) ∧
    X86RegisterView.RegistersRepresent addresses origins memory cells base (X86LogicReference.input native.state) ∧
    X86LogicFlagMemory.FlagsRepresent memory places (X86LogicReference.input native.state).flags ∧
    native = ⟨{state with pc := nextPc}, [], none⟩ := by
  have canonical := X86NopReference.step state nextPc running
  dsimp only
  refine ⟨execute ge memory k binding offset dst src flags aux imm widthBlock nopBlock
    widthSymbol widthGlobal nopSymbol nopGlobal boundary, ?_, ?_, canonical⟩
  · rw [canonical]
    exact registers
  · rw [canonical]
    exact flagBytes

end KProgFormal.ClightRefinement.X86NopDispatch
