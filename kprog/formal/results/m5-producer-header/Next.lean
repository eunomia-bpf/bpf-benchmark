import KProgFormal.ClightRefinement.Arm64ProducerHeader

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Producer.HeaderInspection

private def parts : List CC.Stmt × CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(afterHeaderPointers)) none
    let mut rows : Array Lean.Expr := #[]
    for _ in [:64] do
      body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "header vector-pointer initializer sequence changed"
      let head ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body.getAppArgs[0]!)
      rows := rows.push head
      body := body.getAppArgs[1]!
    let front ← Lean.Meta.mkListLit (Lean.mkConst ``CC.Stmt) rows.toList
    Lean.Elab.Tactic.closeMainGoal `actual_vector_pointer_zeroes (← Lean.Meta.mkAppM ``Prod.mk #[front, body])

private def zeroStore (i : Fin 64) : CC.Stmt :=
  .Sassign (.Ederef (.Ebinop .Oadd
    (.Efield (.Evar Arm64Entry._entry headerType)
      (if i.val < 32 then Arm64Entry._vector_lo else Arm64Entry._vector_hi)
      (CC.tarray (CC.tptr CC.tulong) 32))
    (.Econst_int (CC.Integers.Int.repr (i.val % 32)) CC.tint)
    (CC.tptr (CC.tptr CC.tulong))) (CC.tptr CC.tulong))
    (.Ecast (.Econst_int 0 CC.tint) (CC.tptr CC.tvoid))

example : parts.1 = List.ofFn zeroStore := rfl

-- Source inspection only: no vector-pointer stores or consumer run are claimed.
#print parts
#eval CC.sizeof ge.genv_cenv headerType

end KProgFormal.ClightRefinement.Arm64Producer.HeaderInspection
