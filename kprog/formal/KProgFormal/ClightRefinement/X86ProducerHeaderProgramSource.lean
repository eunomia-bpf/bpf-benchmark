import KProgFormal.ClightRefinement.X86ProducerHeaderSource

namespace KProgFormal.ClightRefinement.X86ProducerHeaderProgramSource
open X86ProducerHeaderSource

private def programParts : List CC.Stmt × CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(producer.fn_body)) none
    let mut rows : Array Lean.Expr := #[]
    while true do
      body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original producer header is not a sequence suffix"
      let head ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body.getAppArgs[0]!)
      if head.isAppOfArity ``CC.Stmt.Sassign 2 then
        let lhs ← Lean.Meta.withTransparency .all (Lean.Meta.whnf head.getAppArgs[0]!)
        if lhs.isAppOfArity ``CC.Expr.Efield 3 && lhs.getAppArgs[1]!.isConstOf ``X86_program_profile_bpf._cells then
          let front ← Lean.Meta.mkListLit (Lean.mkConst ``CC.Stmt) rows.toList
          Lean.Elab.Tactic.closeMainGoal `original_x86_program_header_cut (← Lean.Meta.mkAppM ``Prod.mk #[front, body])
          return
      rows := rows.push head
      body := body.getAppArgs[1]!


def programPrefix : List CC.Stmt := programParts.1

/-- The header initializer is the genuine suffix of the original complete
producer body, retaining every preceding source statement. This identity
alone makes no execution or provider-success assertion for that prefix. -/
theorem program_source : producer.fn_body = programPrefix.foldr CC.Stmt.Ssequence headerStart := by
  run_tac do
    let goal ← Lean.Elab.Tactic.getMainGoal
    let source ← Lean.Elab.Term.elabTerm (← `(producer.fn_body)) none
    goal.assign (← Lean.Meta.mkEqRefl source)
    Lean.Elab.Tactic.replaceMainGoal []

end KProgFormal.ClightRefinement.X86ProducerHeaderProgramSource
