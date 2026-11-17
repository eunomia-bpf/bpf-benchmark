import KProgFormal.ClightRefinement.Arm64ProducerHeaderTail
set_option Elab.async false
namespace KProgFormal.ClightRefinement.Arm64Producer.LoopInspection
private def parts : CC.Stmt × CC.Stmt × CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(beforeVectorLoop)) none
    body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
    unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "loop/consumer sequence changed"
    let continuation := body.getAppArgs[1]!
    body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body.getAppArgs[0]!)
    unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "loop initializer sequence changed"
    let loop ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body.getAppArgs[1]!)
    unless loop.isAppOfArity ``CC.Stmt.Sloop 2 do throwError "vector pointer loop changed"
    let rest ← Lean.Meta.mkAppM ``Prod.mk #[loop.getAppArgs[1]!, continuation]
    Lean.Elab.Tactic.closeMainGoal `actual_loop_parts (← Lean.Meta.mkAppM ``Prod.mk #[loop.getAppArgs[0]!, rest])
example : beforeVectorLoop = .Ssequence
    (.Ssequence (.Sset Arm64Entry._i (.Econst_int 0 CC.tint)) (.Sloop parts.1 parts.2.1)) parts.2.2 := rfl
example : parts.2.1 = .Sset Arm64Entry._i
    (.Ebinop .Oadd (.Etempvar Arm64Entry._i CC.tuint) (.Econst_int 1 CC.tint) CC.tuint) := rfl
-- Source binding only; loop execution and linked consumer are still separate.
#print parts
end KProgFormal.ClightRefinement.Arm64Producer.LoopInspection
