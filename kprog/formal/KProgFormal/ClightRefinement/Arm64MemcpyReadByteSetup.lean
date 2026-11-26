import KProgFormal.ClightRefinement.Arm64MemcpyReadIndex
import KProgFormal.ClightRefinement.Arm64MemcpyReadByte

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyReadByteSetup

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpyReadCall (reader)

private structure Parts where
  width : CC.Stmt
  afterWidth : CC.Stmt
  choose : CC.Stmt
  observed : CC.Stmt
  alignment : CC.Stmt
  test : CC.Stmt
  first : CC.Stmt
  second : CC.Stmt
  firstNo : CC.Stmt
  secondNo : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original width-one byte selection changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyReadIndex.afterIndex)) none) ``CC.Stmt.Ssequence 2
    let afterWidth ← peel root[1]! ``CC.Stmt.Ssequence 2
    let choose ← peel afterWidth[0]! ``CC.Stmt.Ssequence 2
    let alignment ← peel choose[0]! ``CC.Stmt.Ssequence 2
    let first ← peel alignment[0]! ``CC.Stmt.Sifthenelse 3
    let second ← peel alignment[1]! ``CC.Stmt.Sifthenelse 3
    Lean.Elab.Tactic.closeMainGoal `actual_reader_width_one_selection
      (← Lean.Meta.mkAppM ``Parts.mk #[root[0]!,root[1]!,afterWidth[0]!,afterWidth[1]!,choose[0]!,choose[1]!,alignment[0]!,alignment[1]!,first[2]!,second[2]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_reader_width_one_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def width : CC.Stmt := by run_tac cachePart (← `(parts.width))
private def afterWidth : CC.Stmt := by run_tac cachePart (← `(parts.afterWidth))
private def choose : CC.Stmt := by run_tac cachePart (← `(parts.choose))
def observed : CC.Stmt := by run_tac cachePart (← `(parts.observed))
private def alignment : CC.Stmt := by run_tac cachePart (← `(parts.alignment))
private def test : CC.Stmt := by run_tac cachePart (← `(parts.test))
private def first : CC.Stmt := by run_tac cachePart (← `(parts.first))
private def second : CC.Stmt := by run_tac cachePart (← `(parts.second))
private def firstNo : CC.Stmt := by run_tac cachePart (← `(parts.firstNo))
private def secondNo : CC.Stmt := by run_tac cachePart (← `(parts.secondNo))

theorem source : Arm64MemcpyReadIndex.afterIndex = .Ssequence width afterWidth ∧
    afterWidth = .Ssequence choose observed ∧ choose = .Ssequence alignment test ∧
    alignment = .Ssequence first second := ⟨rfl,rfl,rfl,rfl⟩

private def widthTemps (le : CC.TempEnv) : CC.TempEnv := le.set Arm64Program.___a64_str_width (.Vint 1)
private def firstTemps (le : CC.TempEnv) : CC.TempEnv := (widthTemps le).set Arm64Program._t'55 (.Vint 0)
def temps (le : CC.TempEnv) : CC.TempEnv := (firstTemps le).set Arm64Program._t'56 (.Vint 0)

private theorem width_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (actual : le.get Arm64Program._width = some (.Vint 1)) :
    CC.doStep world (.State reader width k e le m) =
      some (CC.E0,.State reader .Sskip k e (widthTemps le) m) := by
  simp only [width,CC.doStep,CC.doEvalExpr,actual]
  rfl

private theorem first_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    CC.doStep world (.State reader first k e (widthTemps le) m) =
      some (CC.E0,.State reader firstNo k e (widthTemps le) m) := by
  simp only [first,CC.doStep,CC.doEvalExpr,widthTemps,CC.PTree.gss]
  rfl

private theorem second_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    CC.doStep world (.State reader second k e (firstTemps le) m) =
      some (CC.E0,.State reader secondNo k e (firstTemps le) m) := by
  simp only [second,CC.doStep,CC.doEvalExpr,firstTemps,CC.PTree.gss]
  rfl

private theorem test_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    CC.doStep world (.State reader test k e (temps le) m) =
      some (CC.E0,.State reader Arm64MemcpyReadByte.bytes k e (temps le) m) := by
  simp only [test,CC.doStep,CC.doEvalExpr,temps,CC.PTree.gss]
  rfl

/-- The actual width copy and both alignment-selection temporaries select
the original byte branch. All original wider-load statements remain in the
unchosen arm; both numeric metadata and the caller heap are retained. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (actual : le.get Arm64Program._width = some (.Vint 1)) :
    InternalRun world 13 (.State reader Arm64MemcpyReadIndex.afterIndex k e le m)
      (.State reader Arm64MemcpyReadByte.bytes (.Kseq observed k) e (temps le) m) := by
  rw [source.1]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (width_step e le m _ actual)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [source.2.1]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [source.2.2.1]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [source.2.2.2]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (first_step e le m _)) ?_
  refine .step (mid := .State reader .Sskip (.Kseq second (.Kseq test (.Kseq observed k))) e (firstTemps le) m)
    trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (second_step e le m _)) ?_
  refine .step (mid := .State reader .Sskip (.Kseq test (.Kseq observed k)) e (temps le) m)
    trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  exact .step trivial (CC.doStep_sound _ _ _ _ (test_step e le m _)) (.refl _)

theorem kept (le : CC.TempEnv) (key : CC.Ident)
    (secondOther : Arm64Program._t'56 ≠ key) (firstOther : Arm64Program._t'55 ≠ key)
    (widthOther : Arm64Program.___a64_str_width ≠ key) :
    (temps le).get key = le.get key := by
  simp only [temps,firstTemps,widthTemps,CC.PTree.gso _ _ _ _ secondOther,
    CC.PTree.gso _ _ _ _ firstOther,CC.PTree.gso _ _ _ _ widthOther]

theorem width_one (le : CC.TempEnv) : (temps le).get Arm64Program.___a64_str_width = some (.Vint 1) := by
  simp +decide only [temps,firstTemps,widthTemps,CC.PTree.gso,CC.PTree.gss]

end KProgFormal.ClightRefinement.Arm64MemcpyReadByteSetup
