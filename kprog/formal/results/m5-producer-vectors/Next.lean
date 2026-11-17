import KProgFormal.ClightRefinement.Arm64ProducerVectors

namespace KProgFormal.ClightRefinement.Arm64Producer

private def nextAssignments : List CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(afterVectorInputs)) none
    let mut rows : Array Lean.Expr := #[]
    for _ in [:26] do
      body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "expected producer assignments after vector inputs"
      let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body.getAppArgs[0]!)
      rows := rows.push stmt
      body := body.getAppArgs[1]!
    Lean.Elab.Tactic.closeMainGoal `after_vector_assignments
      (← Lean.Meta.mkListLit (Lean.mkConst ``CC.Stmt) rows.toList)

#print nextAssignments
example : (Arm64Entry.___a64_stack_tag, CC.tarray CC.tuchar 24) ∈ producer.fn_vars := by decide +kernel

end KProgFormal.ClightRefinement.Arm64Producer
