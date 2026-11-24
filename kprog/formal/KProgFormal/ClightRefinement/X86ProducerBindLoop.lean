import KProgFormal.ClightRefinement.X86ProducerContextSource

namespace KProgFormal.ClightRefinement.X86ProducerBindLoop
open X86ProducerContextSource
open X86ProducerHeaderSource (producer)

def firstCall : CC.Stmt := by
  run_tac do
    let label ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(firstLabel)) none))
    unless label.isAppOfArity ``CC.Stmt.Slabel 2 do throwError "original first PUSH label changed"
    Lean.Elab.Tactic.closeMainGoal `original_x86_first_call label.getAppArgs[1]!

theorem source_call : firstLabel = .Slabel X86_program_profile_bpf._x86_l_0 firstCall := by rfl

/-- The empty bind loop really executes its body/increment/break and returns
through the actual sequencing and label to the first original PUSH call.
No source loop, label or continuation is erased; memory and temporaries stay identical. -/
theorem to_call (ge : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (k : CC.Cont) :
    InternalRun ge 7
      (.State producer afterContext k e le memory)
      (.State producer firstCall (.Kseq followingCalls k) e le memory) := by
  rw [source_loop, source_call]
  exact .step trivial (CC.doStep_sound ge _ _ _ rfl)
    (.step trivial (CC.doStep_sound ge _ _ _ rfl)
      (.step trivial (CC.doStep_sound ge _ _ _ rfl)
        (.step trivial (CC.doStep_sound ge _ _ _ rfl)
          (.step trivial (CC.doStep_sound ge _ _ _ rfl)
            (.step trivial (CC.doStep_sound ge _ _ _ rfl)
              (.step trivial (CC.doStep_sound ge _ _ _ rfl)
                (.refl _)))))))

end KProgFormal.ClightRefinement.X86ProducerBindLoop
