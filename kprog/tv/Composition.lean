import KProgFormal.TagErasure

/-
This file supplies composition, not instruction semantics or a TV certificate.
The block relations must be instantiated with lane V's reference ISA and the
actual verifier-facing BPF bytes. No such instantiation is assumed silently.
-/
namespace KProgTV

abbrev Byte := Fin 256
abbrev Address := KProgFormal.Word

inductive AccessKind
  | read | write | atomic
  deriving DecidableEq, Repr

/-- Architectural effects, in order. Helper identity, arguments and result
are observable; equal call counts alone cannot establish refinement. -/
inductive Event
  | memory (kind : AccessKind) (address : Address) (bytes : Nat)
      (value : List Byte)
  | helper (identity : Address) (arguments : List Address) (result : Address)
  deriving DecidableEq, Repr

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
    (checked : Artifact → List Event → Prop)
    (verifierSound : ∀ a, accepted a → ∀ p trace p', proofEntry a p →
      Execution (proof a) p trace p' → checked a trace)
    (validated executed : Artifact)
    (binding : executed = validated)
    (acceptance : accepted validated)
    (tv : TranslationValidation (native validated) (proof validated)
      (related validated))
    {n p trace n'} (entry : related validated n p)
    (admittedEntry : proofEntry validated p)
    (run : Execution (native executed) n trace n') :
    checked validated trace := by
  subst executed
  obtain ⟨last, matching, _⟩ := validated_execution tv entry run
  exact verifierSound validated acceptance p trace last admittedEntry matching

end KProgTV

#print axioms KProgTV.validated_execution
#print axioms KProgTV.native_effects_checked
