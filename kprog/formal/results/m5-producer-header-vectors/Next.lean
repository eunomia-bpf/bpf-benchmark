import KProgFormal.ClightRefinement.Arm64ProducerHeaderVectors

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Producer.TailInspection

private def tailParts : List CC.Ident × CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(afterNullVectorPointers)) none
    let mut names : Array Lean.Expr := #[]
    for _ in [:16] do
      body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "remaining header initializer sequence changed"
      let head ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body.getAppArgs[0]!)
      unless head.isAppOfArity ``CC.Stmt.Sassign 2 do
        throwError "remaining header initializer is not a store"
      let target ← Lean.Meta.withTransparency .all (Lean.Meta.whnf head.getAppArgs[0]!)
      unless target.isAppOfArity ``CC.Expr.Efield 3 do
        throwError "remaining header initializer is not a field"
      names := names.push target.getAppArgs[1]!
      body := body.getAppArgs[1]!
    let front ← Lean.Meta.mkListLit (Lean.mkConst ``CC.Ident) names.toList
    Lean.Elab.Tactic.closeMainGoal `actual_remaining_header_names (← Lean.Meta.mkAppM ``Prod.mk #[front, body])

example : tailParts.1 =
    [Arm64Entry._b, Arm64Entry._q, Arm64Entry._payload, Arm64Entry._payload_load,
     Arm64Entry._payload_store, Arm64Entry._stack_tags, Arm64Entry._capacity,
     Arm64Entry._payload_words, Arm64Entry._tag_bytes, Arm64Entry._bias,
     Arm64Entry._helper_context, Arm64Entry._helper_abi_base, Arm64Entry._is_xdp,
     Arm64Entry._abi_kind, Arm64Entry._skb_context, Arm64Entry._abi] := rfl

-- Metadata/source observation only; these sixteen stores and the loop are next.
#print tailParts
#print KProgFormal.ClightRefinement.Arm64Producer.afterNullVectorPointers

end KProgFormal.ClightRefinement.Arm64Producer.TailInspection
