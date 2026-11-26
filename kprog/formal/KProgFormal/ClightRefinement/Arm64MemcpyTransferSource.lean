import KProgFormal.ClightRefinement.Arm64MemcpyProgramEntry
import KProgFormal.ClightRefinement.Arm64MemsetClobberReturn

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyTransferSource

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

private structure Parts where
  transfer : CC.Stmt
  clobbers : CC.Stmt
  body : CC.Stmt
private def parts : Parts := by
  run_tac do
    let root ← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyCopyEntry.afterCopy)) none
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf root)
    unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do
      throwError "original memcpy transfer/clobber sequence changed"
    let transfer ← Lean.Meta.withTransparency .all (Lean.Meta.whnf actual.getAppArgs[0]!)
    unless transfer.isAppOfArity ``CC.Stmt.Sloop 2 do
      throwError "original memcpy tag transfer loop changed"
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_transfer_source
      (← Lean.Meta.mkAppM ``Parts.mk #[actual.getAppArgs[0]!,actual.getAppArgs[1]!,transfer.getAppArgs[0]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memcpy_transfer_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
def transfer : CC.Stmt := by run_tac cachePart (← `(parts.transfer))
def clobbers : CC.Stmt := by run_tac cachePart (← `(parts.clobbers))
def body : CC.Stmt := by run_tac cachePart (← `(parts.body))

theorem source : Arm64MemcpyCopyEntry.afterCopy = .Ssequence transfer clobbers ∧
    transfer = .Sloop body .Sbreak := ⟨rfl,rfl⟩

/-- Both actual source functions call the same original clobber helper. -/
theorem shared_clobbers : clobbers = Arm64MemsetTagTransfer.clobbers := rfl

def continuation (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak (.Kseq clobbers k)

/-- Enter the genuine transfer body, retaining its actual following
clobber statement and original outer continuation. -/
theorem enter (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 2 (.State handler Arm64MemcpyCopyEntry.afterCopy k e le m)
      (.State handler body (continuation k) e le m) := by
  rw [source.1,source.2]
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
    (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))

/-- Actual outer transfer exits reach the shared helper call while
retaining the same memcpy function, eight-local environment and heap. -/
theorem leave (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 3 (.State handler .Sskip (continuation k) e le m)
      (.State handler clobbers k e le m) :=
  .step trivial (CC.doStep_sound _ _ _ _ rfl)
    (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)))

end KProgFormal.ClightRefinement.Arm64MemcpyTransferSource
