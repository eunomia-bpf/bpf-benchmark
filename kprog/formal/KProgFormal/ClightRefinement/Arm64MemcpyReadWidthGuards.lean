import KProgFormal.ClightRefinement.Arm64MemcpyReadByte

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyReadWidthGuards

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpyReadCall (reader)

private structure Parts where
  guard0 : CC.Stmt
  guard1 : CC.Stmt
  guard2 : CC.Stmt
  guard3 : CC.Stmt
  guard4 : CC.Stmt
  guard5 : CC.Stmt
  guard6 : CC.Stmt
  tail0 : CC.Stmt
  tail1 : CC.Stmt
  tail2 : CC.Stmt
  tail3 : CC.Stmt
  tail4 : CC.Stmt
  tail5 : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original reader width-guard sequence changed"
      pure actual.getAppArgs
    let first ← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyReadByte.remaining)) none
    let pair0 ← peel first
    let pair1 ← peel pair0[1]!
    let pair2 ← peel pair1[1]!
    let pair3 ← peel pair2[1]!
    let pair4 ← peel pair3[1]!
    let pair5 ← peel pair4[1]!
    Lean.Elab.Tactic.closeMainGoal `actual_reader_width_guard_suffix
      (← Lean.Meta.mkAppM ``Parts.mk #[pair0[0]!,pair1[0]!,pair2[0]!,pair3[0]!,pair4[0]!,pair5[0]!,pair5[1]!,first,pair0[1]!,pair1[1]!,pair2[1]!,pair3[1]!,pair4[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_reader_width_guard_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def guard0 : CC.Stmt := by run_tac cachePart (← `(parts.guard0))
private def guard1 : CC.Stmt := by run_tac cachePart (← `(parts.guard1))
private def guard2 : CC.Stmt := by run_tac cachePart (← `(parts.guard2))
private def guard3 : CC.Stmt := by run_tac cachePart (← `(parts.guard3))
private def guard4 : CC.Stmt := by run_tac cachePart (← `(parts.guard4))
private def guard5 : CC.Stmt := by run_tac cachePart (← `(parts.guard5))
private def guard6 : CC.Stmt := by run_tac cachePart (← `(parts.guard6))
private def tail0 : CC.Stmt := by run_tac cachePart (← `(parts.tail0))
private def tail1 : CC.Stmt := by run_tac cachePart (← `(parts.tail1))
private def tail2 : CC.Stmt := by run_tac cachePart (← `(parts.tail2))
private def tail3 : CC.Stmt := by run_tac cachePart (← `(parts.tail3))
private def tail4 : CC.Stmt := by run_tac cachePart (← `(parts.tail4))
private def tail5 : CC.Stmt := by run_tac cachePart (← `(parts.tail5))

theorem source : Arm64MemcpyReadByte.remaining = tail0 := rfl
private theorem sequence0 : tail0 = .Ssequence guard0 tail1 := rfl
private theorem sequence1 : tail1 = .Ssequence guard1 tail2 := rfl
private theorem sequence2 : tail2 = .Ssequence guard2 tail3 := rfl
private theorem sequence3 : tail3 = .Ssequence guard3 tail4 := rfl
private theorem sequence4 : tail4 = .Ssequence guard4 tail5 := rfl
private theorem sequence5 : tail5 = .Ssequence guard5 guard6 := rfl

private theorem guard0_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (width : le.get Arm64Program.___a64_str_width = some (.Vint 1)) :
    CC.doStep world (.State reader guard0 k e le m) = some (CC.E0,.State reader .Sskip k e le m) := by
  simp only [guard0,Arm64Program.s_kprog_arm64_program_memory_read_33,
    Arm64Program.s_kprog_arm64_program_memory_read_34,CC.doStep,CC.doEvalExpr,width]
  rfl

private theorem guard1_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (width : le.get Arm64Program.___a64_str_width = some (.Vint 1)) :
    CC.doStep world (.State reader guard1 k e le m) = some (CC.E0,.State reader .Sskip k e le m) := by
  simp only [guard1,Arm64Program.s_kprog_arm64_program_memory_read_33,
    Arm64Program.s_kprog_arm64_program_memory_read_34,CC.doStep,CC.doEvalExpr,width]
  rfl

private theorem guard2_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (width : le.get Arm64Program.___a64_str_width = some (.Vint 1)) :
    CC.doStep world (.State reader guard2 k e le m) = some (CC.E0,.State reader .Sskip k e le m) := by
  simp only [guard2,Arm64Program.s_kprog_arm64_program_memory_read_33,
    Arm64Program.s_kprog_arm64_program_memory_read_34,CC.doStep,CC.doEvalExpr,width]
  rfl

private theorem guard3_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (width : le.get Arm64Program.___a64_str_width = some (.Vint 1)) :
    CC.doStep world (.State reader guard3 k e le m) = some (CC.E0,.State reader .Sskip k e le m) := by
  simp only [guard3,Arm64Program.s_kprog_arm64_program_memory_read_33,
    Arm64Program.s_kprog_arm64_program_memory_read_34,CC.doStep,CC.doEvalExpr,width]
  rfl

private theorem guard4_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (width : le.get Arm64Program.___a64_str_width = some (.Vint 1)) :
    CC.doStep world (.State reader guard4 k e le m) = some (CC.E0,.State reader .Sskip k e le m) := by
  simp only [guard4,Arm64Program.s_kprog_arm64_program_memory_read_33,
    Arm64Program.s_kprog_arm64_program_memory_read_34,CC.doStep,CC.doEvalExpr,width]
  rfl

private theorem guard5_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (width : le.get Arm64Program.___a64_str_width = some (.Vint 1)) :
    CC.doStep world (.State reader guard5 k e le m) = some (CC.E0,.State reader .Sskip k e le m) := by
  simp only [guard5,Arm64Program.s_kprog_arm64_program_memory_read_33,
    Arm64Program.s_kprog_arm64_program_memory_read_34,CC.doStep,CC.doEvalExpr,width]
  rfl

private theorem guard6_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (width : le.get Arm64Program.___a64_str_width = some (.Vint 1)) :
    CC.doStep world (.State reader guard6 k e le m) = some (CC.E0,.State reader .Sskip k e le m) := by
  simp only [guard6,Arm64Program.s_kprog_arm64_program_memory_read_33,
    Arm64Program.s_kprog_arm64_program_memory_read_34,CC.doStep,CC.doEvalExpr,width]
  rfl

/-- All seven remaining original width gates take their actual false arms
for width1. Their original unchosen wider loads remain in the source; the
same heap and entire temporary environment reach the original suffix end. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (width : le.get Arm64Program.___a64_str_width = some (.Vint 1)) :
    InternalRun world 19 (.State reader Arm64MemcpyReadByte.remaining k e le m)
      (.State reader .Sskip k e le m) := by
  rw [source]
  rw [sequence0]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State reader .Sskip (.Kseq tail1 k) e le m)
    trivial (CC.doStep_sound _ _ _ _ (guard0_step e le m _ width)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [sequence1]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State reader .Sskip (.Kseq tail2 k) e le m)
    trivial (CC.doStep_sound _ _ _ _ (guard1_step e le m _ width)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [sequence2]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State reader .Sskip (.Kseq tail3 k) e le m)
    trivial (CC.doStep_sound _ _ _ _ (guard2_step e le m _ width)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [sequence3]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State reader .Sskip (.Kseq tail4 k) e le m)
    trivial (CC.doStep_sound _ _ _ _ (guard3_step e le m _ width)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [sequence4]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State reader .Sskip (.Kseq tail5 k) e le m)
    trivial (CC.doStep_sound _ _ _ _ (guard4_step e le m _ width)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [sequence5]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State reader .Sskip (.Kseq guard6 k) e le m)
    trivial (CC.doStep_sound _ _ _ _ (guard5_step e le m _ width)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  exact .step trivial (CC.doStep_sound _ _ _ _ (guard6_step e le m k width)) (.refl _)

end KProgFormal.ClightRefinement.Arm64MemcpyReadWidthGuards
