import KProgFormal.ClightRefinement.X86ProducerFirstInputPrefix

namespace KProgFormal.ClightRefinement.X86ProducerInputReturn
open X86ProducerHeaderSource (producer)

private structure Parts where
  saved : CC.Stmt
  destination : CC.Stmt
  following : CC.Stmt

private def parts : Parts := by
  run_tac do
    let cont ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(X86ProducerFirstInput.callCont CC.Cont.Kstop)) none))
    unless cont.isAppOfArity ``CC.Cont.Kseq 2 do throwError "original saved-pointer continuation changed"
    let next ← Lean.Meta.withTransparency .all (Lean.Meta.whnf cont.getAppArgs[1]!)
    unless next.isAppOfArity ``CC.Cont.Kseq 2 do throwError "original GPR destination continuation changed"
    let last ← Lean.Meta.withTransparency .all (Lean.Meta.whnf next.getAppArgs[1]!)
    unless last.isAppOfArity ``CC.Cont.Kseq 2 do throwError "original GPR following continuation changed"
    Lean.Elab.Tactic.closeMainGoal `original_x86_input_return_parts
      (← Lean.Meta.mkAppM ``Parts.mk #[cont.getAppArgs[0]!, next.getAppArgs[0]!, last.getAppArgs[0]!])

def savedPointer : CC.Stmt := parts.saved
def destination : CC.Stmt := parts.destination
def following : CC.Stmt := parts.following

def temps (le : CC.TempEnv) (word : BitVec 64) : CC.TempEnv :=
  (le.set X86_program_profile_bpf._t'2 (.Vlong word)).set X86_program_profile_bpf._t'1 (.Vlong word)

/-- The original continuation retains both pointer casts and the real destination. -/
theorem source_continuation (k : CC.Cont) : X86ProducerFirstInput.callCont k =
    .Kseq savedPointer (.Kseq destination (.Kseq following k)) := by rfl

theorem source_saved : savedPointer = .Sset X86_program_profile_bpf._t'1
    (.Ecast (.Ecast (.Etempvar X86_program_profile_bpf._t'2 CC.tulong) (CC.tptr CC.tvoid)) (CC.tptr CC.tvoid)) := by rfl

/-- The actual return stores t'2, pops its original continuation and executes
both numerical-pointer casts into t'1, reaching the real RAX assignment in4
transitions. The complete supplied heap and word remain unchanged. -/
theorem to_destination (ge : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (k : CC.Cont) (word : BitVec 64) :
    InternalRun ge 4
      (.Returnstate (.Vlong word) (X86ProducerFirstInput.continuation e le k) memory)
      (.State producer destination (.Kseq following k) e (temps le word) memory) := by
  have evaluated : CC.doEvalExpr ge e (le.set X86_program_profile_bpf._t'2 (.Vlong word)) memory
      (.Ecast (.Ecast (.Etempvar X86_program_profile_bpf._t'2 CC.tulong) (CC.tptr CC.tvoid)) (CC.tptr CC.tvoid)) =
      some (.Vlong word) := by
    simp only [CC.doEvalExpr, CC.PTree.gss, CC.typeof, CC.Cop.semCast, CC.Cop.classifyCast,
      CC.tulong, CC.tptr, CC.Archi.ptr64, ite_true]
  have saved : CC.doStep ge
      (.State producer savedPointer (.Kseq destination (.Kseq following k)) e
        (le.set X86_program_profile_bpf._t'2 (.Vlong word)) memory) =
      some (CC.E0, .State producer .Sskip (.Kseq destination (.Kseq following k)) e (temps le word) memory) := by
    rw [source_saved]
    simp only [CC.doStep, evaluated, temps]
  exact .step trivial (CC.doStep_sound ge _ _ _ rfl)
    (.step trivial (CC.doStep_sound ge _ _ _ rfl)
      (.step trivial (CC.doStep_sound ge _ _ _ saved)
        (.step trivial (CC.doStep_sound ge _ _ _ rfl) (.refl _))))

end KProgFormal.ClightRefinement.X86ProducerInputReturn
