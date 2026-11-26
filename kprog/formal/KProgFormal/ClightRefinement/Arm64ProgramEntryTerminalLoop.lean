import KProgFormal.ClightRefinement.Arm64ProgramEntryTerminalState

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryTerminalLoop
open Arm64Producer (HeaderLocal HeaderSourceLocal)
open Arm64ProgramEntryAllocation (world allocation)

private structure Parts where
  loop : CC.Stmt
  afterLoop : CC.Stmt
  body : CC.Stmt
  checks : CC.Stmt
  readSP : CC.Stmt
  guard : CC.Stmt
  readPair : CC.Stmt
  callRead : CC.Stmt
  ret : CC.Stmt
private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original terminal return loop changed"
      pure actual.getAppArgs
    let tail ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryTerminalStores.tail)) none) ``CC.Stmt.Ssequence 2
    let loop ← peel tail[0]! ``CC.Stmt.Sloop 2
    let body ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let checks ← peel body[0]! ``CC.Stmt.Ssequence 2
    let readPair ← peel body[1]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_terminal_loop_parts
      (← Lean.Meta.mkAppM ``Parts.mk #[tail[0]!,tail[1]!,loop[0]!,body[0]!,checks[0]!,checks[1]!,body[1]!,readPair[0]!,readPair[1]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_terminal_loop_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
def loop : CC.Stmt := by run_tac cachePart (← `(parts.loop))
def afterLoop : CC.Stmt := by run_tac cachePart (← `(parts.afterLoop))
def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
def checks : CC.Stmt := by run_tac cachePart (← `(parts.checks))
def readSP : CC.Stmt := by run_tac cachePart (← `(parts.readSP))
def guard : CC.Stmt := by run_tac cachePart (← `(parts.guard))
def readPair : CC.Stmt := by run_tac cachePart (← `(parts.readPair))
def callRead : CC.Stmt := by run_tac cachePart (← `(parts.callRead))
def ret : CC.Stmt := by run_tac cachePart (← `(parts.ret))
theorem source : Arm64ProgramEntryTerminalStores.tail = .Ssequence loop afterLoop := rfl
theorem loop_source : loop = .Sloop body .Sbreak := rfl
theorem body_source : body = .Ssequence checks readPair := rfl
theorem checks_source : checks = .Ssequence readSP guard := rfl
theorem read_pair_source : readPair = .Ssequence callRead ret := rfl
theorem read_source : readSP = .Sset Arm64ProgramFixture._t'157 (.Evar Arm64ProgramFixture.___a64_sp CC.tlong) := rfl
theorem return_source : ret = .Sreturn (some (.Ecast (.Etempvar Arm64ProgramFixture._t'148 CC.tulong) CC.tuint)) := rfl

def loopCont (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak (.Kseq afterLoop k)
def callCont (k : CC.Cont) : CC.Cont := .Kseq ret (loopCont k)
def temps (le : CC.TempEnv) : CC.TempEnv := le.set Arm64ProgramFixture._t'157 (.Vlong 0)

private theorem read_step {initial : CC.Mem} (cell : HeaderSourceLocal initial 5) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (read : CC.Mem.load .Mint64 m cell.block 0 = some (.Vlong 0)) :
    CC.Step2 world (.State Arm64ProgramFixture.f_arm64_execute_compile readSP k (allocation initial).1 le m) CC.E0
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 (temps le) m) := by
  have evaluated : CC.doEvalExpr world (allocation initial).1 le m
      (.Evar Arm64ProgramFixture.___a64_sp CC.tlong) = some (.Vlong 0) := by
    simp only [CC.doEvalExpr,CC.lvalOfVar,Arm64ProgramEntryTerminalStores.sp_binding cell]
    change CC.Mem.load .Mint64 m cell.block 0 = some (.Vlong 0)
    exact read
  rw [read_source]
  exact CC.Step.set _ _ _ _ _ _ _ _ (CC.doEvalExpr_sound _ _ _ _ _ _ evaluated)

set_option hygiene false in
/-- Actual return loop reads real SP0, follows the original comparison false
arm and reaches the genuine scalar read0 Scall. -/
theorem execute {initial : CC.Mem} (cell : HeaderSourceLocal initial 5) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (read : CC.Mem.load .Mint64 m cell.block 0 = some (.Vlong 0)) :
    InternalRun world 9
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryTerminalStores.tail k (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile callRead (callCont k) (allocation initial).1 (temps le) m) := by
  run_tac do
    for i in [:9] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      if i == 4 then
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact read_step cell le m _ read))
      else
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [CC.doStep,source,loop_source,body_source,checks_source,read_pair_source,
          guard,CC.doEvalExpr,temps,CC.PTree.gss] <;> rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

end KProgFormal.ClightRefinement.Arm64ProgramEntryTerminalLoop
