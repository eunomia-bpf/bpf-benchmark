import KProgFormal.Reference.Memory

/-
This file supplies composition, not instruction semantics or a TV certificate.
The block relations must be instantiated with lane V's reference ISA and the
actual verifier-facing BPF bytes. No such instantiation is assumed silently.
-/
namespace KProgTV

abbrev Byte := KProgFormal.Reference.Byte
abbrev Event := KProgFormal.Reference.Event

/-- Full identities, not hash equality. Metadata includes relocations, maps,
ABI layout, specialization inputs and any instruction-to-block mapping. -/
structure Artifact where
  nativeBytes : List Byte
  proofBytes : List Byte
  entry : Nat
  abi : List Byte
  metadata : List Byte
  deriving DecidableEq, Repr

/-- Each step ends at a basic-block boundary. The state includes PC, every
architectural register/flag and memory, not only the live result register.
The proof relation's trace projects guest effects, erasing only proved-private
simulator spills; justifying this projection is part of the TV certificate. -/
abbrev BlockStep (State : Type) := State → List Event → State → Prop

/-- Finite prefixes suffice for safety, including prefixes of infinite loops.
No termination premise or artificial fuel bound occurs in this relation. -/
inductive Execution {State : Type} (step : BlockStep State) :
    State → List Event → State → Prop
  | refl (s) : Execution step s [] s
  | next {s t u head tail} : step s head t → Execution step t tail u →
      Execution step s (head ++ tail) u

theorem Execution.append {State : Type} {step : BlockStep State}
    {s t u a b} (first : Execution step s a t) (rest : Execution step t b u) :
    Execution step s (a ++ b) u := by
  induction first with
  | refl => exact rest
  | next h _ ih => simpa [List.append_assoc] using Execution.next h (ih rest)


/-- A deterministic terminal fault may repeat in a prefix relation that has
no halted bit. It contributes only its already checked effects. -/
theorem execution_checked_self_loops {State : Type} {step : BlockStep State}
    (checked : Event → Prop) {s last : State} {trace : List Event}
    (run : Execution step s trace last)
    (quiet : ∀ events next, step s events next → next = s ∧ ∀ event ∈ events, checked event) :
    ∀ event ∈ trace, checked event := by
  revert quiet
  induction run with
  | refl => intro _ event inside; simp at inside
  | next head rest ih =>
      intro quiet
      obtain ⟨same, allowed⟩ := quiet _ _ head
      have tailQuiet := quiet
      rw [← same] at tailQuiet
      have tail := ih tailQuiet
      intro event inside
      rcases List.mem_append.mp inside with first | second
      · exact allowed event first
      · exact tail event second

/-- Checking one complete deterministic execution checks every finite native
prefix. The terminal condition covers both a real return and a first fault;
it cannot authorize a new unchecked effect after that boundary. -/
theorem execution_checked_of_complete {State : Type} {step : BlockStep State}
    (deterministic : ∀ {s a t b u}, step s a t → step s b u → a = b ∧ t = u)
    (checked : Event → Prop) {s terminal : State} {expected : List Event}
    (complete : Execution step s expected terminal)
    (allowed : ∀ event ∈ expected, checked event)
    (quiet : ∀ events next, step terminal events next →
      next = terminal ∧ ∀ event ∈ events, checked event)
    {trace : List Event} {last : State} (run : Execution step s trace last) :
    ∀ event ∈ trace, checked event := by
  induction complete generalizing trace last with
  | refl => exact execution_checked_self_loops checked run quiet
  | next head suffix ih =>
      cases run with
      | refl => intro event inside; simp at inside
      | next actualHead actualTail =>
          obtain ⟨sameTrace, sameState⟩ := deterministic head actualHead
          cases sameTrace
          cases sameState
          have tail := ih (fun event inside => allowed event (List.mem_append_right _ inside)) quiet actualTail
          intro event inside
          rcases List.mem_append.mp inside with first | second
          · exact allowed event (List.mem_append_left _ first)
          · exact tail event second

/-- Native-to-proof simulation is the required direction: every native block,
including either branch successor, has a matching proof execution. The reverse
direction would allow verifier-only checks to hide unsafe native executions. -/
structure TranslationValidation {Native Proof : Type}
    (native : BlockStep Native) (proof : BlockStep Proof)
    (related : Native → Proof → Prop) : Prop where
  block : ∀ {n p trace n'}, related n p → native n trace n' →
    ∃ p', Execution proof p trace p' ∧ related n' p'

theorem validated_execution {Native Proof : Type}
    {native : BlockStep Native} {proof : BlockStep Proof}
    {related : Native → Proof → Prop}
    (tv : TranslationValidation native proof related)
    {n p trace n'} (initial : related n p)
    (run : Execution native n trace n') :
    ∃ p', Execution proof p trace p' ∧ related n' p' := by
  induction run generalizing p with
  | refl => exact ⟨p, Execution.refl p, initial⟩
  | next h _ ih =>
    obtain ⟨middle, first, relation⟩ := tv.block initial h
    obtain ⟨last, rest, finalRelation⟩ := ih relation
    exact ⟨last, first.append rest, finalRelation⟩

/-- Conditional end-to-end safety theorem. Binding is exact equality of the
executed and validated artifacts. Verifier soundness is an explicit hypothesis
on the accepted proof's finite executions. TranslationValidation and the entry
relation are obligations, not axioms supplied by this file. -/
theorem native_effects_checked
    {Native Proof : Type}
    (native : Artifact → BlockStep Native)
    (proof : Artifact → BlockStep Proof)
    (related : Artifact → Native → Proof → Prop)
    (accepted : Artifact → Prop)
    (proofEntry : Artifact → Proof → Prop)
    (checked : Artifact → Event → Prop)
    (verifierSound : ∀ a, accepted a → ∀ p trace p', proofEntry a p →
      Execution (proof a) p trace p' → ∀ event ∈ trace, checked a event)
    (validated executed : Artifact)
    (binding : executed = validated)
    (acceptance : accepted validated)
    (tv : TranslationValidation (native validated) (proof validated)
      (related validated))
    {n p trace n'} (entry : related validated n p)
    (admittedEntry : proofEntry validated p)
    (run : Execution (native executed) n trace n') :
    ∀ event ∈ trace, checked validated event := by
  subst executed
  obtain ⟨last, matching, _⟩ := validated_execution tv entry run
  exact verifierSound validated acceptance p trace last admittedEntry matching

end KProgTV

#print axioms KProgTV.validated_execution
#print axioms KProgTV.native_effects_checked

#print axioms KProgTV.execution_checked_of_complete
