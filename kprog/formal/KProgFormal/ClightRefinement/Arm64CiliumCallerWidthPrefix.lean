import KProgFormal.ClightRefinement.Arm64CiliumCallerReaderEntry
import KProgFormal.ClightRefinement.Arm64Width

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerWidthPrefix
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation)

noncomputable def widthCall : CC.Stmt := s_trusted_arm64_arm64_sim_xdp_31
noncomputable def setWidth : CC.Stmt :=
  .Sset ___a64_l_width (.Ecast (.Etempvar _t'133 CC.tuchar) CC.tuchar)
noncomputable def next : CC.Stmt :=
  .Sloop s_trusted_arm64_arm64_sim_xdp_150 s_trusted_arm64_arm64_sim_xdp_151
noncomputable def body : CC.Stmt := .Ssequence (.Ssequence widthCall setWidth) next
noncomputable def loop : CC.Stmt := .Sloop body .Sbreak
noncomputable def rest : CC.Stmt := by
  run_tac do
    let original ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerVectorPointerLoopSource.after)) none
    let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf original)
    unless node.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "actual first instruction successor changed"
    Lean.Elab.Tactic.closeMainGoal `actual_first_instruction_rest node.getAppArgs[1]!

theorem source : Arm64CiliumCallerVectorPointerLoopSource.after =
    .Ssequence (.Slabel _arm64_l_0 loop) rest := rfl
theorem call_source : widthCall =
    .Scall (some _t'133)
      (.Evar _arm64_width_effective (.Tfunction [CC.tuchar] CC.tuchar CC.cc_default))
      [.Econst_int (8#32) CC.tuint] := rfl

private theorem resolved :
    (CC.Genv.findSymbol ge.genv_genv _arm64_width_effective).bind
      (CC.Genv.findFunctPtr ge.genv_genv) = some (.Internal f_arm64_width_effective) := by
  run_tac do
    let goal ← Lean.Elab.Tactic.getMainGoal
    let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
    goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
    Lean.Elab.Tactic.replaceMainGoal []

theorem callee_lookup : ∃ b,
    CC.Genv.findSymbol ge.genv_genv _arm64_width_effective = some b ∧
    CC.Genv.findFunctPtr ge.genv_genv b = some (.Internal f_arm64_width_effective) :=
  (Option.bind_eq_some_iff
    (x := CC.Genv.findSymbol ge.genv_genv _arm64_width_effective)
    (f := CC.Genv.findFunctPtr ge.genv_genv)
    (b := .Internal f_arm64_width_effective)).mp resolved

theorem unshadowed (m : CC.Mem) :
    (allocation m).1.get _arm64_width_effective = none := by
  have absent : _arm64_width_effective ∉ CC.varNames procedure.fn_vars := by decide +kernel
  simpa only [CC.emptyEnv,CC.PTree.gempty] using
    CC.allocVariables_env_other (Arm64CiliumCallerLink.allocated m) absent

noncomputable def continuation (k : CC.Cont) : CC.Cont :=
  .Kseq setWidth (.Kseq next (.Kloop1 body .Sbreak (.Kseq rest k)))
noncomputable def callContinuation {m : CC.Mem} (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some _t'133) procedure (allocation m).1 le (continuation k)
noncomputable def resultEnv (le : CC.TempEnv) : CC.TempEnv :=
  (le.set _t'133 (.Vint (8#32))).set ___a64_l_width (.Vint (8#32))

/-- Actual symbol lookup and the original label/loop prefix reach the real internal helper. -/
theorem call_ready {m memory : CC.Mem} (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 6
      (.State procedure Arm64CiliumCallerVectorPointerLoopSource.after k (allocation m).1 le memory)
      (.Callstate (.Internal f_arm64_width_effective) [.Vint (8#32)] (callContinuation (m := m) le k) memory) := by
  obtain ⟨block,symbol,function⟩ := callee_lookup
  apply internalRun_of_steps
  all_goals
    simp [source,loop,body,call_source,steps,InternalPath,InternalState,CC.doStep,
      CC.doEvalExpr,CC.doEvalExprlist,CC.typeof,CC.Cop.classifyFun,CC.lvalOfVar,
      unshadowed m,symbol,function,CC.doDerefLoc,CC.accessMode,CC.Genv.findFunct,
      callContinuation,continuation,CC.typeOfFundef,CC.typeOfFunction,CC.typeOfParams,
      CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,
      f_arm64_width_effective,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero,
      CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,CC.tuchar,CC.tuint,CC.E0,CC.Eapp]

/-- The actual caller export has different temporary identifiers; execute that body directly. -/
theorem helper (memory : CC.Mem) (k : CC.Cont) :
    InternalRun ge 6
      (.Callstate (.Internal f_arm64_width_effective) [.Vint (8#32)] k memory)
      (.Returnstate (.Vint (8#32)) (CC.callCont k) memory) := by
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  have ids : _code ≠ _t'1 := by decide +kernel
  apply internalRun_of_steps
  all_goals
    simp [empty,ids,steps,InternalPath,InternalState,CC.doStep,CC.doFunctionEntry2,
      f_arm64_width_effective,CC.listNorepet,CC.varNames,CC.listDisjoint,CC.doAllocVariables,
      CC.bindParameterTemps,CC.createUndefTemps,CC.doEvalExpr,CC.typeof,CC.typeconv,
      CC.removeAttributes,CC.tattr,CC.tuchar,CC.tuint,CC.tint,
      CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.classifyCmp,
      CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
      CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,
      CC.Cop.boolVal,CC.Cop.classifyBool,CC.Val.ofBool,
      CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,CC.Integers.Int.eq,CC.Integers.MI.eq,
      CC.Integers.Int.zero,CC.Integers.Int.one,CC.Integers.MI.zero,CC.Integers.MI.one,
      CC.Integers.Int.repr,CC.Integers.MI.repr,CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,
      CC.Eapp,CC.E0,CC.Val.Vtrue,CC.Val.Vfalse,CC.blocksOfEnv,CC.emptyEnv,CC.Mem.freeList]

private theorem leave {m memory : CC.Mem} (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 4
      (.Returnstate (.Vint (8#32)) (callContinuation (m := m) le k) memory)
      (.State procedure next (.Kloop1 body .Sbreak (.Kseq rest k)) (allocation m).1 (resultEnv le) memory) := by
  apply internalRun_of_steps
  all_goals
    simp [steps,InternalPath,InternalState,CC.doStep,callContinuation,continuation,CC.callCont,
      CC.setOpttemp,setWidth,resultEnv,CC.doEvalExpr,CC.typeof,CC.PTree.gss,
      CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,
      CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,CC.tuchar,CC.tuint,CC.E0,CC.Eapp]

/-- Six prefix steps, six actual helper steps and four return/set steps preserve the whole heap. -/
theorem execute {m memory : CC.Mem} (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 16
      (.State procedure Arm64CiliumCallerVectorPointerLoopSource.after k (allocation m).1 le memory)
      (.State procedure next (.Kloop1 body .Sbreak (.Kseq rest k)) (allocation m).1 (resultEnv le) memory) := by
  have run := (call_ready (m := m) le k).trans
    ((helper memory (callContinuation (m := m) le k)).trans (leave (m := m) le k))
  simpa only [CC.callCont] using run

end KProgFormal.ClightRefinement.Arm64CiliumCallerWidthPrefix
