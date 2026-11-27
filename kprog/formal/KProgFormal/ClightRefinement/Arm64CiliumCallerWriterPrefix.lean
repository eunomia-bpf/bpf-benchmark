import KProgFormal.ClightRefinement.Arm64CiliumCallerWriter

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerWriterPrefix
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation token)

noncomputable def guard : CC.Stmt := by
  run_tac do
    let value ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerWriter.rest)) none
    let mut node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf value)
    for _ in [:3] do
      unless node.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original setup sequence changed"
      node := node.getAppArgs[1]!
    Lean.Elab.Tactic.closeMainGoal `original_after_tag node

noncomputable def regSet : CC.Stmt :=
  .Sset ___a64_l_reg__234 (.Ecast (.Econst_int (30#32) CC.tuint) CC.tulong)
noncomputable def lrRead : CC.Stmt :=
  .Sset _t'12904 (.Evar ___a64_lr CC.tulong)
noncomputable def ptrExpr : CC.Expr :=
  .Ecast (.Ecast (.Ecast (.Etempvar _t'12904 CC.tulong) CC.tlong)
    (CC.tptr CC.tvoid)) (CC.tptr CC.tvoid)
noncomputable def ptrSet : CC.Stmt := .Sset ___a64_l_next_ptr ptrExpr
noncomputable def tagSet : CC.Stmt :=
  .Sset ___a64_l_next_tag (.Ecast (.Econst_int (9#32) CC.tuint) CC.tuchar)
noncomputable def toTag : CC.Stmt := .Ssequence tagSet guard
noncomputable def afterReg : CC.Stmt := .Ssequence (.Ssequence lrRead ptrSet) toTag

theorem rest_source : Arm64CiliumCallerWriter.rest = .Ssequence regSet afterReg := by
  run_tac do
    let goal ← Lean.Elab.Tactic.getMainGoal
    let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
    goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
    Lean.Elab.Tactic.replaceMainGoal []

noncomputable def temps (le : CC.TempEnv) : CC.TempEnv :=
  (((le.set ___a64_l_reg__234 (.Vlong (30#64))).set _t'12904 (.Vlong token)).set
    ___a64_l_next_ptr (.Vlong token)).set ___a64_l_next_tag (.Vint (9#32))

/-- Twelve original setup steps,using the actual preceding LR store. The
original memory and continuation stay identical;pointer bits remain raw88. -/
theorem execute {m after : CC.Mem} (lr : Arm64CiliumCallerLink.LRLocal m)
    (stored : CC.Mem.store .Mint64 (allocation m).2 lr.block 0 (.Vlong token) = some after)
    (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 12
      (.State procedure Arm64CiliumCallerWriter.rest k (allocation m).1 le after)
      (.State procedure guard k (allocation m).1 (temps le) after) := by
  let a := le.set ___a64_l_reg__234 (.Vlong (30#64))
  let b := a.set _t'12904 (.Vlong token)
  let c := b.set ___a64_l_next_ptr (.Vlong token)
  have regValue : CC.doEvalExpr ge (allocation m).1 le after
      (.Ecast (.Econst_int (30#32) CC.tuint) CC.tulong) = some (.Vlong (30#64)) := rfl
  have lrValue : CC.doEvalExpr ge (allocation m).1 a after
      (.Evar ___a64_lr CC.tulong) = some (.Vlong token) := by
    simp only [CC.doEvalExpr,CC.lvalOfVar,lr.binding]
    change CC.Mem.load .Mint64 after lr.block 0 = some (.Vlong token)
    exact CC.Mem.load_store_same stored
  have ptrValue : CC.doEvalExpr ge (allocation m).1 b after ptrExpr = some (.Vlong token) := by
    simp only [ptrExpr,CC.doEvalExpr,b,CC.PTree.gss]
    rfl
  have tagValue : CC.doEvalExpr ge (allocation m).1 c after
      (.Ecast (.Econst_int (9#32) CC.tuint) CC.tuchar) = some (.Vint (9#32)) := rfl
  have regStep : CC.Step2 ge
      (.State procedure regSet (.Kseq afterReg k) (allocation m).1 le after) CC.E0
      (.State procedure .Sskip (.Kseq afterReg k) (allocation m).1 a after) := by
    apply CC.doStep_sound
    simp only [regSet,CC.doStep,regValue]
    rfl
  have lrStep : CC.Step2 ge
      (.State procedure lrRead (.Kseq ptrSet (.Kseq toTag k)) (allocation m).1 a after) CC.E0
      (.State procedure .Sskip (.Kseq ptrSet (.Kseq toTag k)) (allocation m).1 b after) := by
    apply CC.doStep_sound
    simp only [lrRead,CC.doStep,lrValue]
    rfl
  have ptrStep : CC.Step2 ge
      (.State procedure ptrSet (.Kseq toTag k) (allocation m).1 b after) CC.E0
      (.State procedure .Sskip (.Kseq toTag k) (allocation m).1 c after) := by
    apply CC.doStep_sound
    simp only [ptrSet,CC.doStep,ptrValue]
    rfl
  have tagStep : CC.Step2 ge
      (.State procedure tagSet (.Kseq guard k) (allocation m).1 c after) CC.E0
      (.State procedure .Sskip (.Kseq guard k) (allocation m).1 (temps le) after) := by
    apply CC.doStep_sound
    simp only [tagSet,CC.doStep,tagValue]
    rfl
  rw [rest_source]
  exact (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial regStep (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial lrStep (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial ptrStep (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial tagStep (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)))))))))))))

/-- Same original site invocation:LR write,actual eagerSP read and all four
setup assignments reach the real guards in20 steps on the same after-memory.
No initial SP value,successful-reader or guard outcome is assumed. -/
theorem begin_allocated (m : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ lr : Arm64CiliumCallerLink.LRLocal m, ∃ after block value,
      InternalRun ge 20
        (.State procedure Arm64CiliumCallerLink.site k (allocation m).1 le (allocation m).2)
        (.State procedure guard
          (Arm64CiliumCallerWriter.continuation (Arm64CiliumCallerWriter.outerContinuation k))
          (allocation m).1 (temps (le.set ___a64_write_old_sp value)) after) ∧
      CC.Mem.store .Mint64 (allocation m).2 lr.block 0 (.Vlong token) = some after ∧
      CC.Mem.load .Mint64 after lr.block 0 = some (.Vlong token) ∧
      CC.Mem.load .Mint64 after block 0 = some value ∧
      FrameBelow m.nextblock (allocation m).2 after ∧
      after.access = (allocation m).2.access ∧ after.nextblock = (allocation m).2.nextblock := by
  obtain ⟨lr,after,block,value,first,stored,lrread,spread,frame,access,next⟩ :=
    Arm64CiliumCallerWriter.begin_allocated m le k
  have second := execute lr stored (le.set ___a64_write_old_sp value)
    (Arm64CiliumCallerWriter.continuation (Arm64CiliumCallerWriter.outerContinuation k))
  exact ⟨lr,after,block,value,first.trans second,stored,lrread,spread,frame,access,next⟩

end KProgFormal.ClightRefinement.Arm64CiliumCallerWriterPrefix
