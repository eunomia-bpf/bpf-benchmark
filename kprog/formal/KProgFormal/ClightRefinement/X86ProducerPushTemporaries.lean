import KProgFormal.ClightRefinement.X86ProducerPushBody

namespace KProgFormal.ClightRefinement.X86ProducerPushTemporaries
open X86ProducerPushBody (handler)

private partial def normalize (expression : Lean.Expr) : Lean.Meta.MetaM Lean.Expr := do
  if expression.isAppOfArity ``CC.PTree.Node 4 || expression.isAppOfArity ``CC.PTree.Leaf 1 then
    return expression
  let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf expression)
  if node.isAppOfArity ``CC.PTree.Leaf 1 then return node
  unless node.isAppOfArity ``CC.PTree.Node 4 do throwError "original temporary map changed shape"
  let args := node.getAppArgs
  return Lean.mkApp4 (Lean.mkConst ``CC.PTree.Node) (Lean.mkConst ``CC.Val) (← normalize args[1]!) args[2]! (← normalize args[3]!)

private def cacheChunk (source base : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let mut rows ← Lean.Elab.Term.elabTerm source none
  let mut names : Array Lean.Expr := #[]
  while true do
    let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rows)
    if node.isAppOfArity ``List.nil 1 then break
    unless node.isAppOfArity ``List.cons 3 do throwError "original PUSH temporary declarations changed"
    let row ← Lean.Meta.withTransparency .all (Lean.Meta.whnf node.getAppArgs[1]!)
    unless row.isAppOfArity ``Prod.mk 4 do throwError "original PUSH temporary row changed"
    names := names.push row.getAppArgs[2]!
    rows := node.getAppArgs[2]!
  let mut tree ← Lean.Elab.Term.elabTerm base none
  let undef ← Lean.Elab.Term.elabTerm (← `(CC.Val.Vundef)) none
  for name in names.toList.reverse do
    tree := Lean.mkApp4 (Lean.mkConst ``CC.PTree.set) (Lean.mkConst ``CC.Val) name undef tree
    tree ← normalize tree
  Lean.Elab.Tactic.closeMainGoal `exact_original_push_undefined_temporaries tree

-- The four declarations are the original export's four source chunks.
private def chunk3 : CC.TempEnv := by
  run_tac cacheChunk (← `(X86_program_profile_bpf.l_x86_sim_inline_arm_DISP_PUSH_temps_3)) (← `((CC.PTree.empty : CC.TempEnv)))
private def chunk2 : CC.TempEnv := by
  run_tac cacheChunk (← `(X86_program_profile_bpf.l_x86_sim_inline_arm_DISP_PUSH_temps_2)) (← `(chunk3))
private def chunk1 : CC.TempEnv := by
  run_tac cacheChunk (← `(X86_program_profile_bpf.l_x86_sim_inline_arm_DISP_PUSH_temps_1)) (← `(chunk2))
/-- Exact original undefined-temporary map, normalized at the export's own
four declaration boundaries. The equality below is checked by the kernel. -/
def undefined : CC.TempEnv := by
  run_tac cacheChunk (← `(X86_program_profile_bpf.l_x86_sim_inline_arm_DISP_PUSH_temps_0)) (← `(chunk1))

theorem undefined_exact : undefined = CC.createUndefTemps handler.fn_temps := by
  run_tac do
    let goal ← Lean.Elab.Tactic.getMainGoal
    let target ← Lean.instantiateMVars (← goal.getType)
    unless target.isAppOfArity ``Eq 3 do throwError "expected original temporary-tree equality"
    goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
    Lean.Elab.Tactic.replaceMainGoal []

def cached (binding : CC.Block) : CC.TempEnv := by
  run_tac Lean.Elab.Tactic.withMainContext do
    let target ← Lean.Elab.Tactic.getMainTarget
    let context ← Lean.getLCtx
    let some argument := context.findFromUserName? `binding | throwError "missing original binding parameter"
    let values ← Lean.Meta.mkAppM ``X86ProducerPushDispatch.values #[Lean.mkFVar argument.fvarId]
    let parameters ← Lean.Elab.Term.elabTerm (← `(handler.fn_params)) none
    let base ← Lean.Elab.Term.elabTerm (← `(undefined)) none
    let application ← Lean.Meta.mkAppM ``CC.bindParameterTemps #[parameters,values,base]
    let result ← Lean.Meta.withTransparency .all (Lean.Meta.whnf application)
    unless result.isAppOfArity ``Option.some 2 do throwError "original PUSH parameter binding refused"
    let term := result.getAppArgs[1]!
    unless ← Lean.Meta.isDefEq (← Lean.Meta.inferType term) target do throwError "original PUSH temporary type mismatch"
    Lean.Elab.Tactic.closeMainGoal `exact_original_push_bound_temporaries term

theorem cached_binds (binding : CC.Block) :
    CC.bindParameterTemps handler.fn_params (X86ProducerPushDispatch.values binding) undefined = some (cached binding) := by rfl

/-- All actual parameter bindings and every other original temporary retain
exactly their original value; no hidden initial-environment premise is added. -/
theorem exact_initial (binding : CC.Block) : cached binding = X86ProducerPushBody.initialTemps binding := by
  have original : CC.bindParameterTemps handler.fn_params (X86ProducerPushDispatch.values binding)
      (CC.createUndefTemps handler.fn_temps) = some (X86ProducerPushBody.initialTemps binding) := rfl
  have same := congrArg (fun base => CC.bindParameterTemps handler.fn_params (X86ProducerPushDispatch.values binding) base) undefined_exact
  rw [cached_binds, original] at same
  exact Option.some.inj same

end KProgFormal.ClightRefinement.X86ProducerPushTemporaries
