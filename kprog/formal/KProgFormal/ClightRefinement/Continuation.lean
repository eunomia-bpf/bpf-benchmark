import KProgFormal.ClightRefinement.InternalExecution

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Continuation

/-- Replace only the terminal Kstop, retaining every nested caller frame. -/
def extend (tail : CC.Cont) : CC.Cont → CC.Cont
  | .Kstop => tail
  | .Kseq s k => .Kseq s (extend tail k)
  | .Kloop1 s1 s2 k => .Kloop1 s1 s2 (extend tail k)
  | .Kloop2 s1 s2 k => .Kloop2 s1 s2 (extend tail k)
  | .Kswitch k => .Kswitch (extend tail k)
  | .Kcall id f e le k => .Kcall id f e le (extend tail k)

def state (tail : CC.Cont) : CC.State → CC.State
  | .State f s k e le m => .State f s (extend tail k) e le m
  | .Callstate fd args k m => .Callstate fd args (extend tail k) m
  | .Returnstate value k m => .Returnstate value (extend tail k) m

theorem callCont_extend (tail : CC.Cont) (valid : CC.isCallCont tail = true) (k : CC.Cont) :
    CC.callCont (extend tail k) = extend tail (CC.callCont k) := by
  have terminal : CC.callCont tail = tail := by
    cases tail <;> simp_all [CC.isCallCont, CC.callCont]
  induction k <;> simp_all [extend, CC.callCont]

theorem isCallCont_extend (tail : CC.Cont) (valid : CC.isCallCont tail = true) (k : CC.Cont) :
    CC.isCallCont (extend tail k) = CC.isCallCont k := by
  cases k <;> simp [extend, CC.isCallCont, valid]

private def found (tail : CC.Cont) (sk : CC.Stmt × CC.Cont) : CC.Stmt × CC.Cont :=
  (sk.1, extend tail sk.2)

mutual
/-- Label lookup rebuilds precisely the same control frames under the caller.
Both sides include loop/switch labels; no visited-goto exclusion is required. -/
theorem findLabel_extend (tail : CC.Cont) (lbl : CC.Ident) (s : CC.Stmt) (k : CC.Cont) :
    CC.findLabel lbl s (extend tail k) = (CC.findLabel lbl s k).map (found tail) := by
  cases s <;> try rfl
  case Ssequence s1 s2 =>
    change (match CC.findLabel lbl s1 (extend tail (.Kseq s2 k)) with
      | some sk => some sk
      | none => CC.findLabel lbl s2 (extend tail k)) =
      (match CC.findLabel lbl s1 (.Kseq s2 k) with
      | some sk => some sk
      | none => CC.findLabel lbl s2 k).map (found tail)
    rw [findLabel_extend tail lbl s1 (.Kseq s2 k), findLabel_extend tail lbl s2 k]
    cases CC.findLabel lbl s1 (.Kseq s2 k) <;> rfl
  case Sifthenelse a s1 s2 =>
    change (match CC.findLabel lbl s1 (extend tail k) with
      | some sk => some sk
      | none => CC.findLabel lbl s2 (extend tail k)) =
      (match CC.findLabel lbl s1 k with
      | some sk => some sk
      | none => CC.findLabel lbl s2 k).map (found tail)
    rw [findLabel_extend tail lbl s1 k, findLabel_extend tail lbl s2 k]
    cases CC.findLabel lbl s1 k <;> rfl
  case Sloop s1 s2 =>
    change (match CC.findLabel lbl s1 (extend tail (.Kloop1 s1 s2 k)) with
      | some sk => some sk
      | none => CC.findLabel lbl s2 (extend tail (.Kloop2 s1 s2 k))) =
      (match CC.findLabel lbl s1 (.Kloop1 s1 s2 k) with
      | some sk => some sk
      | none => CC.findLabel lbl s2 (.Kloop2 s1 s2 k)).map (found tail)
    rw [findLabel_extend tail lbl s1 (.Kloop1 s1 s2 k),
      findLabel_extend tail lbl s2 (.Kloop2 s1 s2 k)]
    cases CC.findLabel lbl s1 (.Kloop1 s1 s2 k) <;> rfl
  case Sswitch a ls =>
    exact findLabelLs_extend tail lbl ls (.Kswitch k)
  case Slabel label s =>
    by_cases equal : lbl = label
    · simp only [CC.findLabel, equal, ite_true, Option.map_some, found]
    · simpa only [CC.findLabel, equal, ite_false] using findLabel_extend tail lbl s k
termination_by sizeOf s
decreasing_by all_goals simp_wf; omega

theorem findLabelLs_extend (tail : CC.Cont) (lbl : CC.Ident) (ls : CC.LStmts) (k : CC.Cont) :
    CC.findLabelLs lbl ls (extend tail k) = (CC.findLabelLs lbl ls k).map (found tail) := by
  cases ls with
  | LSnil => rfl
  | LScons label s rest =>
    change (match CC.findLabel lbl s
        (extend tail (.Kseq (CC.seqOfLabeledStatement rest) k)) with
      | some sk => some sk
      | none => CC.findLabelLs lbl rest (extend tail k)) =
      (match CC.findLabel lbl s (.Kseq (CC.seqOfLabeledStatement rest) k) with
      | some sk => some sk
      | none => CC.findLabelLs lbl rest k).map (found tail)
    rw [findLabel_extend tail lbl s (.Kseq (CC.seqOfLabeledStatement rest) k),
      findLabelLs_extend tail lbl rest k]
    cases CC.findLabel lbl s (.Kseq (CC.seqOfLabeledStatement rest) k) <;> rfl
termination_by sizeOf ls
decreasing_by all_goals simp_wf; omega
end

/-- Every imported Clight transition transports to the real enclosing call.
Expression evaluation, memory effects, arguments and traces stay identical. -/
theorem step_extend (tail : CC.Cont) (valid : CC.isCallCont tail = true)
    {ge : CC.CGenv} {s next : CC.State} {trace : CC.Trace}
    (step : CC.Step2 ge s trace next) :
    CC.Step2 ge (state tail s) trace (state tail next) := by
  cases step <;> simp only [state, extend]
  all_goals try (solve | constructor <;> assumption)
  case return_0 =>
    rw [← callCont_extend tail valid]
    constructor
    assumption
  case return_1 =>
    rw [← callCont_extend tail valid]
    constructor <;> assumption
  case skip_call =>
    apply CC.Step.skip_call
    · rw [isCallCont_extend tail valid]
      assumption
    · assumption
  case goto =>
    apply CC.Step.goto
    rw [callCont_extend tail valid, findLabel_extend]
    simp_all only [Option.map_some, found]

/-- Arbitrary finite relational traces transport unchanged, including provider
and helper events. No silence or external determinism premise is imposed. -/
theorem star_extend (tail : CC.Cont) (valid : CC.isCallCont tail = true)
    {ge : CC.CGenv} {s last : CC.State} {trace : CC.Trace}
    (run : CC.Star (CC.Step2 ge) s trace last) :
    CC.Star (CC.Step2 ge) (state tail s) trace (state tail last) := by
  induction run with
  | refl s => exact .refl _
  | step s1 t1 s2 t2 s3 t transition rest traceEq ih =>
    exact .step _ _ _ _ _ _ (step_extend tail valid transition) ih traceEq

theorem internal_state (tail : CC.Cont) (s : CC.State) :
    InternalState (state tail s) ↔ InternalState s := by
  cases s with
  | State f s k e le m => cases s <;> rfl
  | Callstate fd args k m => cases fd <;> rfl
  | Returnstate value k m => rfl

/-- Reuse the same finite internal certificate in an actual caller, preserving
its exact number of transitions and complete post-memory. -/
theorem run_extend (tail : CC.Cont) (valid : CC.isCallCont tail = true)
    {ge : CC.CGenv} {n : Nat} {s last : CC.State} (run : InternalRun ge n s last) :
    InternalRun ge n (state tail s) (state tail last) := by
  induction run with
  | refl s => exact .refl _
  | step internal step rest ih =>
    exact .step ((internal_state tail _).mpr internal) (step_extend tail valid step) ih

end KProgFormal.ClightRefinement.Continuation
