import CCLib.ClightExecSound

namespace KProgFormal.ClightRefinement

/-- Bounded composition of the upstream interpreter, retaining its trace and
entire final state. Unknown external calls remain refused by that interpreter. -/
def steps (ge : CC.CGenv) : Nat → CC.State → Option (CC.Trace × CC.State)
  | 0, s => some (CC.E0, s)
  | n + 1, s =>
    match CC.doStep ge s with
    | none => none
    | some (t, mid) =>
      match steps ge n mid with
      | none => none
      | some (u, last) => some (CC.Eapp t u, last)

/-- Every composed execution is an execution of the existing Clight relation.
This proves no ISA correspondence and supplies no external-call interpretation. -/
theorem steps_sound (ge : CC.CGenv) (n : Nat) (s : CC.State)
    (t : CC.Trace) (last : CC.State) (h : steps ge n s = some (t, last)) :
    CC.Star (CC.Step2 ge) s t last := by
  induction n generalizing s t last with
  | zero =>
    simp only [steps] at h
    cases h
    exact .refl s
  | succ n ih =>
    cases hs : CC.doStep ge s with
    | none => simp [steps, hs] at h
    | some next =>
      obtain ⟨u, mid⟩ := next
      cases ht : steps ge n mid with
      | none => simp [steps, hs, ht] at h
      | some next =>
        obtain ⟨v, last'⟩ := next
        simp only [steps, hs, ht, Option.some.injEq, Prod.mk.injEq] at h
        obtain ⟨rfl, rfl⟩ := h
        exact .step s u mid v last' _ (CC.doStep_sound ge s u mid hs)
          (ih mid v last' ht) rfl

/-- Composition preserves the full Clight trace and state. -/
theorem star_trans {R : CC.State → CC.Trace → CC.State → Prop}
    {s : CC.State} {t : CC.Trace} {mid : CC.State} (h : CC.Star R s t mid) :
    ∀ {last : CC.State} {u : CC.Trace}, CC.Star R mid u last →
      CC.Star R s (CC.Eapp t u) last := by
  induction h with
  | refl s =>
    intro last u h'
    simpa [CC.Eapp, CC.E0] using h'
  | step s1 t1 s2 t2 s3 t h12 _ ht ih =>
    intro last u h'
    subst t
    exact .step s1 t1 s2 (CC.Eapp t2 u) last _ h12 (ih h')
      (by simp [CC.Eapp, List.append_assoc])

end KProgFormal.ClightRefinement
