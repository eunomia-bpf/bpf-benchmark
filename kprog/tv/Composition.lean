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

/-- Change only the step presentation, retaining the original states and
complete ordered event trace. This lifts a token-labelled implementation
execution into the actual dispatch relation. -/
theorem Execution.of_step_imp {State : Type} {first second : BlockStep State}
    (includeStep : ∀ {s events t}, first s events t → second s events t)
    {s t : State} {events : List Event} (run : Execution first s events t) :
    Execution second s events t := by
  induction run with
  | refl => exact Execution.refl _
  | next head rest ih => exact Execution.next (includeStep head) ih

/-- Compose two independently proved preservation stages. Neither direction
is reversed: every original behavior must remain possible after each stage.
The intermediate architectural relation is retained existentially. -/
theorem TranslationValidation.trans {Native Middle Proof : Type}
    {native : BlockStep Native} {middle : BlockStep Middle} {proof : BlockStep Proof}
    {first : Native → Middle → Prop} {second : Middle → Proof → Prop}
    (left : TranslationValidation native middle first)
    (right : TranslationValidation middle proof second) :
    TranslationValidation native proof (fun n p => ∃ m, first n m ∧ second m p) := by
  constructor
  intro n p events next relation head
  obtain ⟨m,firstRelation,secondRelation⟩ := relation
  obtain ⟨middleLast,middleRun,firstLast⟩ := left.block firstRelation head
  obtain ⟨last,proofRun,secondLast⟩ := validated_execution right secondRelation middleRun
  exact ⟨last,proofRun,middleLast,firstLast,secondLast⟩

/-- Token identity is a dispatch label, never an alternative ISA semantics.
The supplied step must include its real native decoding or actual proof PC
selection; this union does not authorize a token at an unrelated PC. -/
def tokenStep {Token State : Type} (step : Token → BlockStep State) : BlockStep State :=
  fun before events after => ∃ token, step token before events after

/-- Prove each token once for arbitrary fields/invocations/programs. The
same state relation carries every token's architectural registers, flags,
memory and control location. Program-specific proof files are unnecessary. -/
theorem tokenwise_validation {Token Native Proof : Type}
    (native : Token → BlockStep Native) (proof : Token → BlockStep Proof)
    (related : Native → Proof → Prop)
    (tokenLaw : ∀ token, TranslationValidation (native token) (proof token) related) :
    TranslationValidation (tokenStep native) (tokenStep proof) related := by
  constructor
  intro n p events next relation head
  obtain ⟨token,nativeHead⟩ := head
  obtain ⟨last,proofRun,finalRelation⟩ := (tokenLaw token).block relation nativeHead
  exact ⟨last,Execution.of_step_imp (fun step => ⟨token,step⟩) proofRun,finalRelation⟩

/-- Any finite native block, not a fixed list/length or selected successful
path. This also covers faulting prefixes and every allowed control successor.
No fuel, termination, program certificate or native endpoint is supplied. -/
theorem TranslationValidation.execution {Native Proof : Type}
    {native : BlockStep Native} {proof : BlockStep Proof} {related : Native → Proof → Prop}
    (tv : TranslationValidation native proof related) :
    TranslationValidation (Execution native) proof related := by
  constructor
  intro n p events next relation run
  exact validated_execution tv relation run

/-- General identity transport between two names for an Artifact. The
single-kernel-copy corollaries instantiate both names with one value.
Verifier soundness, faithful simulation and the entry relation are explicit
hypotheses over complete finite executions. -/
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

/-- Once-for-all program block instance. O1 and O2 range over EVERY
artifact and token. `linkLaw` must itself be a once-for-all composition of the
actual native-link/compiler transformations, not a per-program certificate.
In particular a C-model equation cannot replace a proof about accepted B.

The final proof relation is the actual verifier-visible instruction relation
(or a projection whose soundness is separately derived from real B execution).
All binding/dispatch/ABI facts belong in the relations and their entry proof. -/
theorem generic_program_block_validation {Token Native Interpreter Specialized Proof : Type}
    (native : Artifact → Token → BlockStep Native)
    (interpreted : Artifact → Token → BlockStep Interpreter)
    (specialized : Artifact → Token → BlockStep Specialized)
    (proof : Artifact → BlockStep Proof)
    (isaRelated : Artifact → Native → Interpreter → Prop)
    (specializedRelated : Artifact → Interpreter → Specialized → Prop)
    (linkRelated : Artifact → Specialized → Proof → Prop)
    (isaLaw : ∀ a token, TranslationValidation (native a token) (interpreted a token) (isaRelated a))
    (specializationLaw : ∀ a token, TranslationValidation (interpreted a token) (specialized a token)
      (specializedRelated a))
    (linkLaw : ∀ a, TranslationValidation (tokenStep (specialized a)) (proof a) (linkRelated a)) :
    ∀ a, TranslationValidation (Execution (tokenStep (native a))) (proof a)
      (fun n p => ∃ s, (∃ i, isaRelated a n i ∧ specializedRelated a i s) ∧ linkRelated a s p) := by
  intro a
  exact ((tokenwise_validation (native a) (interpreted a) (isaRelated a) (isaLaw a)).trans
    (tokenwise_validation (interpreted a) (specialized a) (specializedRelated a) (specializationLaw a)) |>.trans
      (linkLaw a)).execution

/-- Generic instantiation of the binding/accepted-verifier safety theorem.
All operation/specialization/link laws are quantified over arbitrary programs;
only input state and verifier acceptance are instantiated at load time. Every
native block execution therefore matches real checked proof effects without
creating or checking an individual program's proof/certificate. -/
theorem generic_program_effects_checked {Token Native Interpreter Specialized Proof : Type}
    (native : Artifact → Token → BlockStep Native)
    (interpreted : Artifact → Token → BlockStep Interpreter)
    (specialized : Artifact → Token → BlockStep Specialized)
    (proof : Artifact → BlockStep Proof)
    (isaRelated : Artifact → Native → Interpreter → Prop)
    (specializedRelated : Artifact → Interpreter → Specialized → Prop)
    (linkRelated : Artifact → Specialized → Proof → Prop)
    (isaLaw : ∀ a token, TranslationValidation (native a token) (interpreted a token) (isaRelated a))
    (specializationLaw : ∀ a token, TranslationValidation (interpreted a token) (specialized a token)
      (specializedRelated a))
    (linkLaw : ∀ a, TranslationValidation (tokenStep (specialized a)) (proof a) (linkRelated a))
    (accepted : Artifact → Prop) (proofEntry : Artifact → Proof → Prop)
    (checked : Artifact → Event → Prop)
    (verifierSound : ∀ a, accepted a → ∀ p trace p', proofEntry a p →
      Execution (proof a) p trace p' → ∀ event ∈ trace, checked a event)
    (validated executed : Artifact) (binding : executed=validated) (acceptance : accepted validated)
    {n p trace n'}
    (entry : ∃ s, (∃ i, isaRelated validated n i ∧ specializedRelated validated i s) ∧
      linkRelated validated s p)
    (admittedEntry : proofEntry validated p)
    (run : Execution (Execution (tokenStep (native executed))) n trace n') :
    ∀ event ∈ trace, checked validated event := by
  exact native_effects_checked (fun a => Execution (tokenStep (native a))) proof
    (fun a n p => ∃ s, (∃ i, isaRelated a n i ∧ specializedRelated a i s) ∧ linkRelated a s p)
    accepted proofEntry checked verifierSound validated executed binding acceptance
    (generic_program_block_validation native interpreted specialized proof isaRelated specializedRelated linkRelated
      isaLaw specializationLaw linkLaw validated) entry admittedEntry run

/-- Stock verification and faithful simulation refer to the same kernel
copy by construction. Exact identity is discharged by reflexivity. -/
theorem native_effects_from_kernel_copy
    {Native Proof : Type}
    (native : Artifact → BlockStep Native)
    (proof : Artifact → BlockStep Proof)
    (related : Artifact → Native → Proof → Prop)
    (accepted : Artifact → Prop)
    (proofEntry : Artifact → Proof → Prop)
    (checked : Artifact → Event → Prop)
    (verifierSound : ∀ a, accepted a → ∀ p trace p', proofEntry a p →
      Execution (proof a) p trace p' → ∀ event ∈ trace, checked a event)
    (kernelCopy : Artifact)
    (acceptance : accepted kernelCopy)
    (tv : TranslationValidation (native kernelCopy) (proof kernelCopy)
      (related kernelCopy))
    {n p trace n'} (entry : related kernelCopy n p)
    (admittedEntry : proofEntry kernelCopy p)
    (run : Execution (native kernelCopy) n trace n') :
    ∀ event ∈ trace, checked kernelCopy event := by
  exact native_effects_checked native proof related accepted proofEntry checked verifierSound
    kernelCopy kernelCopy rfl acceptance tv entry admittedEntry run

/-- Universal O1/O2/link laws instantiate the two safety facts for one
kernel copy, for arbitrary programs and finite native execution prefixes. -/
theorem generic_program_effects_from_kernel_copy {Token Native Interpreter Specialized Proof : Type}
    (native : Artifact → Token → BlockStep Native)
    (interpreted : Artifact → Token → BlockStep Interpreter)
    (specialized : Artifact → Token → BlockStep Specialized)
    (proof : Artifact → BlockStep Proof)
    (isaRelated : Artifact → Native → Interpreter → Prop)
    (specializedRelated : Artifact → Interpreter → Specialized → Prop)
    (linkRelated : Artifact → Specialized → Proof → Prop)
    (isaLaw : ∀ a token, TranslationValidation (native a token) (interpreted a token) (isaRelated a))
    (specializationLaw : ∀ a token, TranslationValidation (interpreted a token) (specialized a token)
      (specializedRelated a))
    (linkLaw : ∀ a, TranslationValidation (tokenStep (specialized a)) (proof a) (linkRelated a))
    (accepted : Artifact → Prop) (proofEntry : Artifact → Proof → Prop)
    (checked : Artifact → Event → Prop)
    (verifierSound : ∀ a, accepted a → ∀ p trace p', proofEntry a p →
      Execution (proof a) p trace p' → ∀ event ∈ trace, checked a event)
    (kernelCopy : Artifact) (acceptance : accepted kernelCopy)
    {n p trace n'}
    (entry : ∃ s, (∃ i, isaRelated kernelCopy n i ∧ specializedRelated kernelCopy i s) ∧
      linkRelated kernelCopy s p)
    (admittedEntry : proofEntry kernelCopy p)
    (run : Execution (Execution (tokenStep (native kernelCopy))) n trace n') :
    ∀ event ∈ trace, checked kernelCopy event := by
  exact native_effects_checked (fun a => Execution (tokenStep (native a))) proof
    (fun a n p => ∃ s, (∃ i, isaRelated a n i ∧ specializedRelated a i s) ∧ linkRelated a s p)
    accepted proofEntry checked verifierSound kernelCopy kernelCopy rfl acceptance
    (generic_program_block_validation native interpreted specialized proof isaRelated specializedRelated linkRelated
      isaLaw specializationLaw linkLaw kernelCopy) entry admittedEntry run

end KProgTV

#print axioms KProgTV.validated_execution
#print axioms KProgTV.native_effects_checked

#print axioms KProgTV.execution_checked_of_complete

#print axioms KProgTV.Execution.of_step_imp

#print axioms KProgTV.TranslationValidation.trans

#print axioms KProgTV.tokenwise_validation

#print axioms KProgTV.TranslationValidation.execution

#print axioms KProgTV.generic_program_block_validation

#print axioms KProgTV.generic_program_effects_checked

#print axioms KProgTV.native_effects_from_kernel_copy
#print axioms KProgTV.generic_program_effects_from_kernel_copy
