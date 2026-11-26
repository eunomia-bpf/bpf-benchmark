import KProgFormal.ClightRefinement.Arm64ProgramEntryReturnLR

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryReturnGuard
open Arm64Producer (HeaderSourceLocal)
open Arm64ProgramEntryAllocation (world allocation)

private structure Parts where
  guard : CC.Stmt
  choose : CC.Stmt
  fallback : CC.Stmt
  readLR : CC.Stmt
  condition : CC.Stmt
  perform : CC.Stmt
private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original RET_TO guard changed"
      pure actual.getAppArgs
    let tail ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryReturnRaw.tail)) none) ``CC.Stmt.Ssequence 2
    let gates ← peel tail[0]! ``CC.Stmt.Ssequence 2
    let guard ← peel gates[0]! ``CC.Stmt.Ssequence 2
    let choice ← peel gates[1]! ``CC.Stmt.Sifthenelse 3
    Lean.Elab.Tactic.closeMainGoal `actual_return_guard_parts
      (← Lean.Meta.mkAppM ``Parts.mk #[gates[0]!,gates[1]!,tail[1]!,guard[0]!,guard[1]!,choice[1]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_return_guard_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
def guard : CC.Stmt := by run_tac cachePart (← `(parts.guard))
def choose : CC.Stmt := by run_tac cachePart (← `(parts.choose))
def fallback : CC.Stmt := by run_tac cachePart (← `(parts.fallback))
def readLR : CC.Stmt := by run_tac cachePart (← `(parts.readLR))
def condition : CC.Stmt := by run_tac cachePart (← `(parts.condition))
def perform : CC.Stmt := by run_tac cachePart (← `(parts.perform))
theorem source : Arm64ProgramEntryReturnRaw.tail = .Ssequence (.Ssequence guard choose) fallback := rfl
theorem guard_source : guard = .Ssequence readLR condition := rfl
theorem read_source : readLR = .Sset Arm64ProgramFixture._t'156 (.Evar Arm64ProgramFixture.___a64_lr CC.tulong) := rfl
theorem perform_source : perform = Arm64ProgramFixture.s_arm64_execute_compile_60 := rfl

def cont (k : CC.Cont) : CC.Cont := .Kseq fallback (Arm64ProgramEntryReturnRaw.outerCont k)
def temps (le : CC.TempEnv) : CC.TempEnv :=
  (le.set Arm64ProgramFixture._t'156 (.Vlong 64)).set Arm64ProgramFixture._t'151 (.Vint 1)

private theorem read_step {initial : CC.Mem} (lr : HeaderSourceLocal initial 4) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (read : CC.Mem.load .Mint64 m lr.block 0 = some (.Vlong 64)) :
    CC.Step2 world (.State Arm64ProgramFixture.f_arm64_execute_compile readLR k (allocation initial).1 le m) CC.E0
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1
        (le.set Arm64ProgramFixture._t'156 (.Vlong 64)) m) := by
  have evaluated : CC.doEvalExpr world (allocation initial).1 le m
      (.Evar Arm64ProgramFixture.___a64_lr CC.tulong) = some (.Vlong 64) := by
    simp only [CC.doEvalExpr,CC.lvalOfVar,Arm64ProgramEntryLinkCall.local_binding lr]
    change CC.Mem.load .Mint64 m lr.block 0 = some (.Vlong 64)
    exact read
  rw [read_source]
  exact CC.Step.set _ _ _ _ _ _ _ _ (CC.doEvalExpr_sound _ _ _ _ _ _ evaluated)

set_option hygiene false in
/-- The REAL nonzero LR guard selects the original RET_TO body. The source
fallback tag10 test remains in the actual false arm and is not called here. -/
theorem execute {initial : CC.Mem} (lr : HeaderSourceLocal initial 4) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (read : CC.Mem.load .Mint64 m lr.block 0 = some (.Vlong 64)) :
    InternalRun world 9
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryReturnRaw.tail
        (Arm64ProgramEntryReturnRaw.outerCont k) (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile perform (cont k) (allocation initial).1 (temps le) m) := by
  run_tac do
    for i in [:9] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      if i == 3 then
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact read_step lr le m _ read))
      else
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [CC.doStep,source,guard_source,condition,choose,
          CC.doEvalExpr,CC.PTree.gss] <;> rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

end KProgFormal.ClightRefinement.Arm64ProgramEntryReturnGuard
