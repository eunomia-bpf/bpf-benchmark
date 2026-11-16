import KProgFormal.ClightRefinement.Execution
import CCLib.Determinism

namespace KProgFormal.ClightRefinement

/-- A path certificate excludes external calls and builtins at the current
state only. It does not classify unexecuted branches or change Step2. -/
def InternalState : CC.State → Prop
  | .State _ (.Sbuiltin ..) _ _ _ _ => False
  | .Callstate (.External ..) _ _ _ => False
  | _ => True

/-- Internal transitions have one complete successor and trace. The proof
uses upstream expression, store and allocation determinism; it never invokes
the general step theorem's external-call determinism assumptions. -/
theorem internal_step_unique {ge : CC.CGenv} {s a b : CC.State} {t u : CC.Trace}
    (hs : InternalState s) (ha : CC.Step2 ge s t a) (hb : CC.Step2 ge s u b) :
    t = u ∧ a = b := by
  cases ha <;> (try contradiction) <;> cases hb <;>
    try (first | exact ⟨rfl, rfl⟩ | (exfalso; simp_all [CC.isCallCont]; done))
  case assign.assign =>
    rename_i hlv1 he1 hc1 hal1 _ _ _ _ _ _ hal2 hc2 hlv2 he2
    refine ⟨rfl, ?_⟩
    obtain ⟨hb, ho, hbf⟩ := CC.evalLvalue_determ hlv1 hlv2
    subst hb; subst ho; subst hbf
    have hv := CC.evalExpr_determ he1 he2
    subst hv
    rw [hc1] at hc2
    simp only [Option.some.injEq] at hc2
    subst hc2
    rw [CC.assignLoc_determ hal1 hal2]
  case set.set =>
    rename_i _ he1 _ he2
    exact ⟨rfl, by rw [CC.evalExpr_determ he1 he2]⟩
  case call.call =>
    rename_i hcf1 he1 hel1 hff1 _ _ _ _ _ _ _ hff2 _ hcf2 he2 hel2
    refine ⟨rfl, ?_⟩
    rw [hcf1] at hcf2
    simp only [CC.Cop.FunCase.f.injEq] at hcf2
    obtain ⟨e1, e2, e3⟩ := hcf2
    subst e1; subst e2; subst e3
    have hvf := CC.evalExpr_determ he1 he2
    subst hvf
    have hva := CC.evalExprlist_determ hel1 _ hel2
    subst hva
    rw [hff1] at hff2
    simp only [Option.some.injEq] at hff2
    subst hff2
    rfl
  case ifthenelse.ifthenelse =>
    rename_i he1 hb1 _ _ hb2 he2
    refine ⟨rfl, ?_⟩
    have hv := CC.evalExpr_determ he1 he2
    subst hv
    rw [hb1] at hb2
    simp_all
  case return_0.return_0 =>
    rename_i hf1 _ hf2
    exact ⟨rfl, by rw [hf1] at hf2; simp_all⟩
  case return_1.return_1 =>
    rename_i he1 hc1 hf1 _ _ _ hc2 hf2 he2
    refine ⟨rfl, ?_⟩
    have hv := CC.evalExpr_determ he1 he2
    subst hv
    rw [hc1] at hc2
    rw [hf1] at hf2
    simp_all
  case skip_call.skip_call =>
    rename_i _ hf1 _ _ hf2
    exact ⟨rfl, by rw [hf1] at hf2; simp_all⟩
  case switch.switch =>
    rename_i he1 hn1 _ _ hn2 he2
    refine ⟨rfl, ?_⟩
    have hv := CC.evalExpr_determ he1 he2
    subst hv
    rw [hn1] at hn2
    simp_all
  case goto.goto =>
    rename_i hfl1 _ _ hfl2
    exact ⟨rfl, by rw [hfl1] at hfl2; simp_all⟩
  case internal_function.internal_function =>
    rename_i hfe1 _ _ _ hfe2
    obtain ⟨he, hle, hm⟩ := CC.functionEntry2_determ hfe1 hfe2
    subst he; subst hle; subst hm
    exact ⟨rfl, rfl⟩

/-- A finite certificate over the existing Step2 relation, counting the
actual transitions and retaining each complete state. -/
inductive InternalRun (ge : CC.CGenv) : Nat → CC.State → CC.State → Prop where
  | refl (s) : InternalRun ge 0 s s
  | step {n s mid last} : InternalState s → CC.Step2 ge s CC.E0 mid →
      InternalRun ge n mid last → InternalRun ge (n + 1) s last

/-- Check only the sources visited by the imported interpreter. Success of
the execution itself is supplied separately by steps, not inferred here. -/
def InternalPath (ge : CC.CGenv) : Nat → CC.State → Prop
  | 0, _ => True
  | n + 1, s => InternalState s ∧
      match CC.doStep ge s with
      | none => False
      | some (_, mid) => InternalPath ge n mid

theorem internalRun_of_steps {ge : CC.CGenv} {n : Nat} {s last : CC.State}
    (path : InternalPath ge n s) (exec : steps ge n s = some (CC.E0, last)) :
    InternalRun ge n s last := by
  induction n generalizing s last with
  | zero =>
    simp only [steps, Option.some.injEq, Prod.mk.injEq] at exec
    exact exec.2 ▸ InternalRun.refl s
  | succ n ih =>
    cases hd : CC.doStep ge s with
    | none => simp [steps, hd] at exec
    | some next =>
      rcases next with ⟨t, mid⟩
      cases ht : steps ge n mid with
      | none => simp [steps, hd, ht] at exec
      | some next =>
        rcases next with ⟨u, last'⟩
        simp only [steps, hd, ht, Option.some.injEq, Prod.mk.injEq] at exec
        have silent : t = CC.E0 ∧ u = CC.E0 := by
          simpa only [CC.Eapp, CC.E0, List.append_eq_nil_iff] using exec.1
        rcases silent with ⟨rfl, rfl⟩
        cases exec.2
        have rest : InternalPath ge n mid := by
          simpa only [InternalPath, hd] using path.2
        exact .step path.1 (CC.doStep_sound ge _ _ _ hd) (ih rest ht)

namespace InternalRun

theorem trans {ge : CC.CGenv} {n m : Nat} {s mid last : CC.State}
    (first : InternalRun ge n s mid) (second : InternalRun ge m mid last) :
    InternalRun ge (n + m) s last := by
  induction first with
  | refl _ => simpa using second
  | step hs hstep _ ih =>
    simpa [Nat.add_assoc, Nat.add_comm, Nat.add_left_comm] using
      (InternalRun.step hs hstep (ih second))

theorem sound {ge : CC.CGenv} {n : Nat} {s last : CC.State}
    (run : InternalRun ge n s last) : CC.Star (CC.Step2 ge) s CC.E0 last := by
  induction run with
  | refl _ => exact .refl _
  | step _ hstep _ ih => exact .step _ _ _ _ _ _ hstep ih rfl

/-- Every relational execution, with an arbitrary trace, is a prefix of an
internal execution reaching a stuck endpoint. It can always finish there. -/
theorem finish_prefix {ge : CC.CGenv} {n : Nat} {s last : CC.State}
    (run : InternalRun ge n s last)
    (stuck : ∀ t next, ¬ CC.Step2 ge last t next)
    {t : CC.Trace} {other : CC.State} (observed : CC.Star (CC.Step2 ge) s t other) :
    t = CC.E0 ∧ ∃ remaining, InternalRun ge remaining other last := by
  induction run generalizing t other with
  | refl _ =>
    cases observed with
    | refl _ => exact ⟨rfl, 0, .refl _⟩
    | step _ _ _ _ _ _ hstep _ _ => exact False.elim (stuck _ _ hstep)
  | @step n s mid last hs hstep rest ih =>
    cases observed with
    | refl _ => exact ⟨rfl, n + 1, .step hs hstep rest⟩
    | step _ _ _ _ _ _ otherStep tail ht =>
      obtain ⟨ht1, heq⟩ := internal_step_unique hs hstep otherStep
      cases ht1
      cases heq
      obtain ⟨ht2, remaining, finish⟩ := ih stuck tail
      exact ⟨by simpa [CC.Eapp, CC.E0, ht2] using ht, remaining, finish⟩

theorem endpoint_unique {ge : CC.CGenv} {n : Nat} {s last : CC.State}
    (run : InternalRun ge n s last)
    (stuck : ∀ t next, ¬ CC.Step2 ge last t next)
    {t : CC.Trace} {other : CC.State} (observed : CC.Star (CC.Step2 ge) s t other)
    (otherStuck : ∀ u next, ¬ CC.Step2 ge other u next) :
    t = CC.E0 ∧ other = last := by
  obtain ⟨silent, remaining, finish⟩ := run.finish_prefix stuck observed
  refine ⟨silent, ?_⟩
  cases finish with
  | refl _ => rfl
  | step _ hstep _ => exact False.elim (otherStuck _ _ hstep)

/-- There is no infinite sequence of relational transitions from an internal
terminating run. No fairness, trace-silence or external determinism premise
is imposed on the proposed sequence. -/
theorem no_infinite {ge : CC.CGenv} {n : Nat} {s last : CC.State}
    (run : InternalRun ge n s last)
    (stuck : ∀ t next, ¬ CC.Step2 ge last t next) :
    ¬ ∃ states : Nat → CC.State, states 0 = s ∧
      ∀ i, ∃ t, CC.Step2 ge (states i) t (states (i + 1)) := by
  induction run with
  | refl _ =>
    rintro ⟨states, start, next⟩
    obtain ⟨t, first⟩ := next 0
    rw [start] at first
    exact stuck _ _ first
  | step hs hstep _ ih =>
    rintro ⟨states, start, next⟩
    obtain ⟨t, first⟩ := next 0
    rw [start] at first
    have heq := (internal_step_unique hs hstep first).2
    apply ih stuck
    exact ⟨fun i => states (i + 1), heq.symm, fun i => next (i + 1)⟩

end InternalRun

end KProgFormal.ClightRefinement
