import KProgFormal.ClightRefinement.X86ProducerPushRspSource

namespace KProgFormal.ClightRefinement.X86ProducerPushExitSource
open X86ProducerLayout (ge)
open X86ProducerPushBody (handler)

def chain : List CC.Stmt → CC.Cont → CC.Cont
  | [], k => k
  | body :: rest, k => .Kloop1 body .Sbreak (chain rest k)

/-- Cache only the original enclosing loop frames, stopping at the supplied
actual caller continuation. A changed increment/continuation shape fails. -/
def bodies (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) : List CC.Stmt := by
  run_tac Lean.Elab.Tactic.withMainContext do
    let context ← Lean.getLCtx
    let arguments ← #[`binding,`k,`memory].mapM fun name => do
      let some argument := context.findFromUserName? name | throwError "missing actual PUSH exit argument"
      pure (Lean.mkFVar argument.fvarId)
    let mut current ← Lean.Meta.mkAppM ``X86ProducerPushRspSource.control arguments
    let mut rows : Array Lean.Expr := #[]
    let stop ← Lean.Elab.Term.elabTerm (← `(CC.Stmt.Sbreak)) none
    while true do
      if ← Lean.Meta.isDefEq current arguments[1]! then break
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf current)
      unless node.isAppOfArity ``CC.Cont.Kloop1 3 do throwError "original PUSH enclosing exit is not a loop frame: {node.getAppFn}"
      unless ← Lean.Meta.isDefEq node.getAppArgs[1]! stop do throwError "original PUSH enclosing increment is not its break"
      rows := rows.push node.getAppArgs[0]!
      current := node.getAppArgs[2]!
    Lean.Elab.Tactic.closeMainGoal `original_x86_push_exit_frames
      (← Lean.Meta.mkListLit (Lean.mkConst ``CC.Stmt) rows.toList)

theorem source (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) :
    X86ProducerPushRspSource.control binding k memory = chain (bodies binding k memory) k := rfl

theorem finish_loop (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (body : CC.Stmt) (k : CC.Cont) :
    InternalRun ge 2 (.State handler .Sskip (.Kloop1 body .Sbreak k) e le memory)
      (.State handler .Sskip k e le memory) := by
  apply internalRun_of_steps
  all_goals simp only [steps, InternalPath, InternalState, CC.doStep, CC.E0, CC.Eapp, List.nil_append, true_and]

theorem finish (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (rows : List CC.Stmt) (k : CC.Cont) :
    InternalRun ge (2 * rows.length) (.State handler .Sskip (chain rows k) e le memory)
      (.State handler .Sskip k e le memory) := by
  induction rows with
  | nil => exact .refl _
  | cons body rest ih =>
    simpa only [chain, List.length_cons, Nat.mul_succ, Nat.add_comm] using (finish_loop e le memory body (chain rest k)).trans ih

end KProgFormal.ClightRefinement.X86ProducerPushExitSource
