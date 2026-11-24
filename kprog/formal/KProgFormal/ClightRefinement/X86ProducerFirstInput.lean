import KProgFormal.ClightRefinement.X86ProducerInitialPrefix

namespace KProgFormal.ClightRefinement.X86ProducerFirstInput
open X86ProducerHeaderSource (producer)
open X86ProducerGhostSource (beforeProvider)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)
open X86RegisterWriteRspReleaseWord (inputFunction inputEF)

private structure Parts where
  call : CC.Stmt
  savedPointer : CC.Stmt
  destination : CC.Stmt
  following : CC.Stmt

private def parts : Parts := by
  run_tac do
    let source ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(beforeProvider)) none))
    unless source.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original first input outer sequence changed"
    let setup ← Lean.Meta.withTransparency .all (Lean.Meta.whnf source.getAppArgs[0]!)
    unless setup.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original first input destination changed"
    let branch ← Lean.Meta.withTransparency .all (Lean.Meta.whnf setup.getAppArgs[0]!)
    unless branch.isAppOfArity ``CC.Stmt.Sifthenelse 3 do throwError "original first input condition changed"
    let route ← Lean.Meta.withTransparency .all (Lean.Meta.whnf branch.getAppArgs[2]!)
    unless route.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original first input call route changed"
    Lean.Elab.Tactic.closeMainGoal `original_x86_first_input_parts
      (← Lean.Meta.mkAppM ``Parts.mk #[route.getAppArgs[0]!, route.getAppArgs[1]!, setup.getAppArgs[1]!, source.getAppArgs[1]!])

def inputCall : CC.Stmt := parts.call

def callCont (k : CC.Cont) : CC.Cont :=
  .Kseq parts.savedPointer (.Kseq parts.destination (.Kseq parts.following k))
def continuation (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some X86_program_profile_bpf._t'2) producer e le (callCont k)

private def inputIndex : Nat := by
  run_tac do
    let mut rows ← Lean.Elab.Term.elabTerm (← `(X86_program_profile_bpf.global_definitions)) none
    let mut index := 0
    while true do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rows)
      unless node.isAppOfArity ``List.cons 3 do throwError "original input definition missing"
      let row ← Lean.Meta.withTransparency .all (Lean.Meta.whnf node.getAppArgs[1]!)
      unless row.isAppOfArity ``Prod.mk 4 do throwError "original global definition changed"
      if row.getAppArgs[2]!.isConstOf ``X86_program_profile_bpf._native_lab_entry_input then
        Lean.Elab.Tactic.closeMainGoal `original_x86_input_index (Lean.mkNatLit index)
        return
      rows := node.getAppArgs[2]!
      index := index + 1

def inputBlock : CC.Block := CC.Positive.ofNat (inputIndex + 1)

/-- The original complete source world supplies the genuine external input symbol/function. -/
theorem input_binding :
    CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._native_lab_entry_input = some inputBlock ∧
    CC.Genv.findFunctPtr ge.genv_genv inputBlock = some inputFunction := by
  constructor <;> run_tac do
    let goal ← Lean.Elab.Tactic.getMainGoal
    let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
    unless target.isAppOfArity ``Eq 3 do throwError "expected actual input binding equality"
    goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
    Lean.Elab.Tactic.replaceMainGoal []

theorem call_source : inputCall = .Scall (some X86_program_profile_bpf._t'2)
    (.Evar X86_program_profile_bpf._native_lab_entry_input (.Tfunction [CC.tuint] CC.tulong CC.cc_default))
    [.Econst_int (CC.Integers.Int.repr 6) CC.tint] := by rfl

/-- The original constant branch, sequencing and real call evaluation reach the
first kind-6 provider Callstate in five transitions, with actual global binding
and original caller continuation. No provider outcome or memory frame is assumed. -/
theorem enter (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 5 (.State producer beforeProvider k (allocation ge.genv_cenv before).1 le memory)
      (.Callstate inputFunction [.Vint (6#32)] (continuation (allocation ge.genv_cenv before).1 le k) memory) := by
  have allocated := CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation ge.genv_cenv before)).symm
  have absent : X86_program_profile_bpf._native_lab_entry_input ∉ CC.varNames producer.fn_vars := by decide +kernel
  have notLocal : (allocation ge.genv_cenv before).1.get X86_program_profile_bpf._native_lab_entry_input = none := by
    simpa only [CC.emptyEnv, CC.PTree.gempty] using CC.allocVariables_env_other allocated absent
  have call : CC.doStep ge (.State producer inputCall (callCont k) (allocation ge.genv_cenv before).1 le memory) =
      some (CC.E0, .Callstate inputFunction [.Vint (6#32)] (continuation (allocation ge.genv_cenv before).1 le k) memory) := by
    simp +decide [call_source, continuation, CC.doStep, CC.doEvalExpr, CC.doEvalExprlist,
      CC.lvalOfVar, notLocal, CC.doDerefLoc, CC.accessMode, CC.typeof,
      input_binding.1, input_binding.2, CC.Genv.findFunct, CC.Cop.classifyFun,
      inputFunction, inputEF, CC.Cop.semCast, CC.Cop.classifyCast,
      CC.Cop.castIntInt, CC.tuint, CC.tint, CC.tulong]
  exact .step trivial (CC.doStep_sound ge _ _ _ rfl)
    (.step trivial (CC.doStep_sound ge _ _ _ rfl)
      (.step trivial (CC.doStep_sound ge _ _ _ rfl)
        (.step trivial (CC.doStep_sound ge _ _ _ rfl)
          (.step trivial (CC.doStep_sound ge _ _ _ call) (.refl _)))))

end KProgFormal.ClightRefinement.X86ProducerFirstInput
