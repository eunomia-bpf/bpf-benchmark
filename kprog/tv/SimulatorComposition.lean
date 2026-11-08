import Composition
import KProgFormal.Refinement.X86Dispatcher

/-! V's unified raw dispatcher and O2 token equations instantiate the generic
composition interface. Native steps use the canonical decoder and relational
ISA. Definedness transport and actual compiled-B preservation stay explicit. -/
namespace KProgTV.SimulatorComposition
open KProgFormal KProgFormal.Reference
open KProgFormal.Refinement
open KProgFormal.Refinement.X86NumericAddress

abbrev NativeState := Reference.X86.State
abbrev Effect := Reference.Transition NativeState

structure Site where
  token : GeneratedX86Specialization.Op
  opcode : GeneratedX86Opcode.Op
  current : Nat
  flags : Reference.Byte
  aux : BitVec 32
  dst : Reference.Byte
  src : Reference.Byte
  value : Reference.Word
  nextPc : Reference.Word
  instruction : Reference.X86.Instruction

/-- A canonical state has a scalar register representation, with its RSP
normalized once to the invocation's actual entry-stack origin. This algebraic
encoding supplies a common-input witness; actual C frame closure is a later
implementation correspondence law. -/
def encode (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (state : NativeState) : RegisterState :=
  ⟨{state with gpr := fun reg => if reg=4 then state.gpr reg-EntryEnvironment.base env frame .stack
      else state.gpr reg},fun _ => false⟩

theorem encode_native (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (state : NativeState) : nativeRegisters env frame arena (encode env frame state)=state := by
  have values : registerValue env frame arena (encode env frame state)=state.gpr := by
    funext reg
    by_cases stack : reg=4
    · simp only [registerValue,encode,stack,ite_true]
      exact BitVec.sub_add_cancel _ _
    · simp only [registerValue,encode,stack,ite_false,Bool.false_eq_true]
  change {state with gpr:=registerValue env frame arena (encode env frame state)}=state
  rw [values]

/-- Selection names the actual instruction site and its bound metadata. The
native bytes are fetched at the architectural PC and decoded by canonical X86. -/
def nativeToken (image : Artifact → Memory) (select : Artifact → Site → NativeState → Prop)
    (a : Artifact) (site : Site) : BlockStep NativeState := fun before trace after =>
  select a site before ∧
    Reference.X86.decode (bytesAt (image a) before.pc 15).toArray before=.ok site.instruction ∧
    ∃ effect, Reference.X86.Step site.instruction before effect ∧ effect.events=trace ∧ effect.state=after

def interpretedToken (env : Artifact → EntryEnvironment.Environment) (frame : Artifact → EntryEnvironment.Frame)
    (arena : Artifact → Reference.Word) (select : Artifact → Site → NativeState → Prop)
    (a : Artifact) (site : Site) : BlockStep NativeState := fun before trace after =>
  select a site before ∧ X86Dispatcher.stepTokenOpcode site.token=some site.opcode ∧
    ∃ raw effect, nativeRegisters (env a) (frame a) (arena a) raw=before ∧
      X86Dispatcher.dispatchStep (env a) (frame a) (arena a) site.current
        (GeneratedX86Opcode.code site.opcode) site.flags site.aux site.dst site.src site.value site.nextPc raw=some effect ∧
      effect.events=trace ∧ effect.state=after

def specializedToken (env : Artifact → EntryEnvironment.Environment) (frame : Artifact → EntryEnvironment.Frame)
    (arena : Artifact → Reference.Word) (select : Artifact → Site → NativeState → Prop)
    (a : Artifact) (site : Site) : BlockStep NativeState := fun before trace after =>
  select a site before ∧ X86Dispatcher.stepTokenOpcode site.token=some site.opcode ∧
    ∃ raw effect, nativeRegisters (env a) (frame a) (arena a) raw=before ∧
      X86Dispatcher.specializedStep (env a) (frame a) (arena a) site.current
        site.token site.flags site.aux site.dst site.src site.value site.nextPc raw=some effect ∧
      effect.events=trace ∧ effect.state=after

/-- Metadata/operand alignment is universal in artifacts and invocations. It
also transports selected PCs through the same definedness relation. -/
def FieldsAligned (image : Artifact → Memory) (select : Artifact → Site → NativeState → Prop)
    (related : Artifact → NativeState → NativeState → Prop) : Prop :=
  ∀ a site native model, related a native model → select a site native →
    Reference.X86.decode (bytesAt (image a) native.pc 15).toArray native=.ok site.instruction →
      select a site model ∧ X86Dispatcher.stepTokenOpcode site.token=some site.opcode ∧
        X86Dispatcher.StepBinding site.flags site.aux site.dst site.src site.value site.nextPc model
          (GeneratedX86Opcode.code site.opcode) site.instruction

/-- The program-wide definedness invariant transports a real native step into
the common input and closes the relation for every canonically matching
successor. Exact events and faults retain their canonical meaning. -/
def DefinednessTransport (image : Artifact → Memory) (select : Artifact → Site → NativeState → Prop)
    (related : Artifact → NativeState → NativeState → Prop) : Prop :=
  ∀ a site native model trace next, related a native model → nativeToken image select a site native trace next →
    ∃ effect, Reference.X86.Step site.instruction model effect ∧ effect.events=trace ∧
      ∀ actual, Reference.X86.matchesTransition site.instruction effect actual → related a next actual.state

/-- Two permitted canonical successors agree on the canonical observed state,
effects and fault. This is equality reasoning over the existing ISA relation. -/
theorem canonical_successors_match (instruction : Reference.X86.Instruction) (before : NativeState)
    (first second : Effect) (left : Reference.X86.Step instruction before first)
    (right : Reference.X86.Step instruction before second) :
    Reference.X86.matchesTransition instruction first second := by
  unfold Reference.X86.Step at left right
  unfold Reference.X86.matchesTransition at left right ⊢
  obtain ⟨firstEvents,firstFault,firstState⟩ := left
  obtain ⟨secondEvents,secondFault,secondState⟩ := right
  refine ⟨firstEvents.symm.trans secondEvents,firstFault.symm.trans secondFault,?_⟩
  rw [←firstFault]
  exact firstState.symm.trans secondState

/-- V's unified refinement supplies the matching dispatcher step. All native
successors are retained through the explicit definedness closure interface. -/
theorem native_to_interpreted (image : Artifact → Memory)
    (env : Artifact → EntryEnvironment.Environment) (frame : Artifact → EntryEnvironment.Frame)
    (arena : Artifact → Reference.Word) (select : Artifact → Site → NativeState → Prop)
    (related : Artifact → NativeState → NativeState → Prop)
    (fields : FieldsAligned image select related) (transport : DefinednessTransport image select related)
    (a : Artifact) (site : Site) :
    TranslationValidation (nativeToken image select a site)
      (interpretedToken env frame arena select a site) (related a) := by
  constructor
  intro native model trace next relation source
  obtain ⟨selected,decoded,successor,run,events,state⟩ := source
  obtain ⟨modelSelected,tokenSelected,binding⟩ := fields a site native model relation selected decoded
  obtain ⟨reference,referenceStep,referenceEvents,closure⟩ :=
    transport a site native model trace next relation ⟨selected,decoded,successor,run,events,state⟩
  have rawBinding : X86Dispatcher.StepBinding site.flags site.aux site.dst site.src site.value site.nextPc
      (nativeRegisters (env a) (frame a) (arena a) (encode (env a) (frame a) model))
      (GeneratedX86Opcode.code site.opcode) site.instruction := by
    rw [encode_native]
    exact binding
  obtain ⟨actual,dispatched,actualStep⟩ := X86Dispatcher.simulator_step_refines
    (env a) (frame a) (arena a) site.current _ site.flags site.aux site.dst site.src site.value site.nextPc
    (encode (env a) (frame a) model) site.instruction rawBinding
  rw [encode_native] at actualStep
  have matching := canonical_successors_match site.instruction model reference actual referenceStep actualStep
  have head : interpretedToken env frame arena select a site model trace actual.state :=
    ⟨modelSelected,tokenSelected,encode (env a) (frame a) model,actual,encode_native _ _ _ _,dispatched,
      matching.1.symm.trans referenceEvents,rfl⟩
  exact ⟨actual.state,by simpa only [List.append_nil] using Execution.next head (Execution.refl actual.state),
    closure actual matching⟩

/-- The same raw input and same output instantiate O2 directly from V's
per-token body equation, for every currently covered token class. -/
theorem interpreted_to_specialized (env : Artifact → EntryEnvironment.Environment)
    (frame : Artifact → EntryEnvironment.Frame) (arena : Artifact → Reference.Word)
    (select : Artifact → Site → NativeState → Prop) (a : Artifact) (site : Site) :
    TranslationValidation (interpretedToken env frame arena select a site)
      (specializedToken env frame arena select a site) Eq := by
  constructor
  intro before other trace after relation source
  subst other
  obtain ⟨selected,tokenSelected,raw,effect,input,dispatched,events,state⟩ := source
  have body := X86Dispatcher.step_token_body_matches (env a) (frame a) (arena a) site.current
    site.token site.opcode site.flags site.aux site.dst site.src site.value site.nextPc raw tokenSelected
  have head : specializedToken env frame arena select a site before trace after :=
    ⟨selected,tokenSelected,raw,effect,input,body.trans dispatched,events,state⟩
  exact ⟨after,by simpa only [List.append_nil] using Execution.next head (Execution.refl after),rfl⟩

theorem specialized_reflects (env : Artifact → EntryEnvironment.Environment)
    (frame : Artifact → EntryEnvironment.Frame) (arena : Artifact → Reference.Word)
    (select : Artifact → Site → NativeState → Prop) (a : Artifact) (site : Site)
    (before after : NativeState) (trace : List Event)
    (run : specializedToken env frame arena select a site before trace after) :
    interpretedToken env frame arena select a site before trace after := by
  obtain ⟨selected,tokenSelected,raw,effect,input,dispatched,events,state⟩ := run
  have body := X86Dispatcher.step_token_body_matches (env a) (frame a) (arena a) site.current
    site.token site.opcode site.flags site.aux site.dst site.src site.value site.nextPc raw tokenSelected
  exact ⟨selected,tokenSelected,raw,effect,input,body.symm.trans dispatched,events,state⟩

/-- The generic block instance consumes V's actual unified laws. The final
stage is the actual accepted B relation, supplied once for every artifact. -/
theorem program_block_validation {Proof : Type} (image : Artifact → Memory)
    (env : Artifact → EntryEnvironment.Environment) (frame : Artifact → EntryEnvironment.Frame)
    (arena : Artifact → Reference.Word) (select : Artifact → Site → NativeState → Prop)
    (related : Artifact → NativeState → NativeState → Prop)
    (fields : FieldsAligned image select related) (transport : DefinednessTransport image select related)
    (proof : Artifact → BlockStep Proof) (linkRelated : Artifact → NativeState → Proof → Prop)
    (linkLaw : ∀ a, TranslationValidation (tokenStep (specializedToken env frame arena select a))
      (proof a) (linkRelated a)) :
    ∀ a, TranslationValidation (Execution (tokenStep (nativeToken image select a))) (proof a)
      (fun n p => ∃ s, (∃ i, related a n i ∧ i=s) ∧ linkRelated a s p) := by
  exact generic_program_block_validation (nativeToken image select) (interpretedToken env frame arena select)
    (specializedToken env frame arena select) proof related (fun _ => Eq) linkRelated
    (native_to_interpreted image env frame arena select related fields transport)
    (interpreted_to_specialized env frame arena select) linkLaw

/-- Exact artifact identity and accepted-B verifier soundness complete the
checked-effects instantiation after the universal field/definedness/link laws. -/
theorem program_effects_checked {Proof : Type} (image : Artifact → Memory)
    (env : Artifact → EntryEnvironment.Environment) (frame : Artifact → EntryEnvironment.Frame)
    (arena : Artifact → Reference.Word) (select : Artifact → Site → NativeState → Prop)
    (related : Artifact → NativeState → NativeState → Prop)
    (fields : FieldsAligned image select related) (transport : DefinednessTransport image select related)
    (proof : Artifact → BlockStep Proof) (linkRelated : Artifact → NativeState → Proof → Prop)
    (linkLaw : ∀ a, TranslationValidation (tokenStep (specializedToken env frame arena select a)) (proof a) (linkRelated a))
    (accepted : Artifact → Prop) (proofEntry : Artifact → Proof → Prop) (checked : Artifact → Event → Prop)
    (verifierSound : ∀ a, accepted a → ∀ p trace p', proofEntry a p →
      Execution (proof a) p trace p' → ∀ event∈trace, checked a event)
    (validated executed : Artifact) (binding : executed=validated) (acceptance : accepted validated)
    {n : NativeState} {p : Proof} {trace : List Event} {last : NativeState}
    (entry : ∃ s, (∃ i, related validated n i ∧ i=s) ∧ linkRelated validated s p)
    (admitted : proofEntry validated p)
    (run : Execution (Execution (tokenStep (nativeToken image select executed))) n trace last) :
    ∀ event∈trace, checked validated event := by
  exact generic_program_effects_checked (nativeToken image select) (interpretedToken env frame arena select)
    (specializedToken env frame arena select) proof related (fun _ => Eq) linkRelated
    (native_to_interpreted image env frame arena select related fields transport)
    (interpreted_to_specialized env frame arena select) linkLaw accepted proofEntry checked verifierSound
    validated executed binding acceptance entry admitted run


/-- This condition identifies instructions whose successful outputs retain
every architectural bit. Canonical faults retain the whole state as well. -/
def CompleteOutputs (instruction : Reference.X86.Instruction) : Prop :=
  Reference.X86.definedFlags instruction=BitVec.allOnes 64 ∧
    ∀ state, Reference.X86.observedRegisters instruction state=state.gpr

/-- Canonical observational matching becomes full architectural equality
when the instruction observes all output bits. Events and fault stay exact. -/
theorem complete_match (instruction : Reference.X86.Instruction) (complete : CompleteOutputs instruction)
    (expected actual : Effect) (matching : Reference.X86.matchesTransition instruction expected actual) :
    expected.state=actual.state ∧ expected.events=actual.events ∧ expected.fault=actual.fault := by
  obtain ⟨events,fault,state⟩ := matching
  have mask : (if expected.fault.isSome then (0xffffffffffffffff : Reference.Word)
      else Reference.X86.definedFlags instruction)=BitVec.allOnes 64 := by
    rw [complete.1]
    split <;> decide
  have registers (s : NativeState) :
      (if expected.fault.isSome then s.gpr else Reference.X86.observedRegisters instruction s)=s.gpr := by
    split
    · rfl
    · exact complete.2 s
  dsimp only at state
  rw [mask,registers,registers] at state
  simp only [BitVec.and_allOnes] at state
  exact ⟨state,events,fault⟩

theorem branch_complete (condition : Option (Fin 16)) (target nextPc : Reference.Word) :
    CompleteOutputs (.branch condition target nextPc) := ⟨by change (0xffffffffffffffff : Reference.Word)=BitVec.allOnes 64; decide,by intro state; rfl⟩

theorem move_complete (width : Reference.X86.ScalarWidth) (dst : Reference.X86.ScalarDestination)
    (src : Reference.X86.ScalarSource) (nextPc : Reference.Word) :
    CompleteOutputs (.move width dst src nextPc) := ⟨by change (0xffffffffffffffff : Reference.Word)=BitVec.allOnes 64; decide,by intro state; rfl⟩

/-- Full-output selections discharge the universal definedness transport
interface with exact common states; partial outputs use its general relation. -/
theorem exact_definedness_transport (image : Artifact → Memory)
    (select : Artifact → Site → NativeState → Prop)
    (complete : ∀ a site state, select a site state → CompleteOutputs site.instruction) :
    DefinednessTransport image select (fun _ => Eq) := by
  intro a site native model trace next relation source
  subst model
  obtain ⟨selected,decoded,effect,step,events,state⟩ := source
  refine ⟨effect,step,events,?_⟩
  intro actual matching
  exact state.symm.trans (complete_match site.instruction (complete a site native selected) effect actual matching).1

/-- Fully observed instruction selections instantiate the generic block law
with a derived state-closure proof and V's unified O1/O2 interfaces. -/
theorem exact_program_block_validation {Proof : Type} (image : Artifact → Memory)
    (env : Artifact → EntryEnvironment.Environment) (frame : Artifact → EntryEnvironment.Frame)
    (arena : Artifact → Reference.Word) (select : Artifact → Site → NativeState → Prop)
    (fields : FieldsAligned image select (fun _ => Eq))
    (complete : ∀ a site state, select a site state → CompleteOutputs site.instruction)
    (proof : Artifact → BlockStep Proof) (linkRelated : Artifact → NativeState → Proof → Prop)
    (linkLaw : ∀ a, TranslationValidation (tokenStep (specializedToken env frame arena select a)) (proof a) (linkRelated a)) :
    ∀ a, TranslationValidation (Execution (tokenStep (nativeToken image select a))) (proof a)
      (fun n p => ∃ s, (∃ i, n=i ∧ i=s) ∧ linkRelated a s p) :=
  program_block_validation image env frame arena select (fun _ => Eq) fields
    (exact_definedness_transport image select complete) proof linkRelated linkLaw


/-- Coverage ranges over every behavior of the actual native block relation.
The canonical-decoded selected-site execution covers the complete block, so
instruction/PC coverage is explicit in the actual-program instantiation. -/
theorem actual_program_block_validation {Proof : Type} (actualNative : Artifact → BlockStep NativeState)
    (image : Artifact → Memory) (env : Artifact → EntryEnvironment.Environment)
    (frame : Artifact → EntryEnvironment.Frame) (arena : Artifact → Reference.Word)
    (select : Artifact → Site → NativeState → Prop)
    (coverage : ∀ a before trace after, actualNative a before trace after →
      Execution (tokenStep (nativeToken image select a)) before trace after)
    (related : Artifact → NativeState → NativeState → Prop)
    (fields : FieldsAligned image select related) (transport : DefinednessTransport image select related)
    (proof : Artifact → BlockStep Proof) (linkRelated : Artifact → NativeState → Proof → Prop)
    (linkLaw : ∀ a, TranslationValidation (tokenStep (specializedToken env frame arena select a)) (proof a) (linkRelated a)) :
    ∀ a, TranslationValidation (actualNative a) (proof a)
      (fun n p => ∃ s, (∃ i, related a n i ∧ i=s) ∧ linkRelated a s p) := by
  intro a
  constructor
  intro native checked trace next relation source
  exact (program_block_validation image env frame arena select related fields transport proof linkRelated linkLaw a).block
    relation (coverage a native trace next source)

/-- Every actual native execution prefix has checked effects after the
universal coverage, V O1/O2, definedness and actual compiled-B/link laws.
Verifier acceptance, exact Artifact binding and physical entry are explicit. -/
theorem actual_program_effects_checked {Proof : Type} (actualNative : Artifact → BlockStep NativeState)
    (image : Artifact → Memory) (env : Artifact → EntryEnvironment.Environment)
    (frame : Artifact → EntryEnvironment.Frame) (arena : Artifact → Reference.Word)
    (select : Artifact → Site → NativeState → Prop)
    (coverage : ∀ a before trace after, actualNative a before trace after →
      Execution (tokenStep (nativeToken image select a)) before trace after)
    (related : Artifact → NativeState → NativeState → Prop)
    (fields : FieldsAligned image select related) (transport : DefinednessTransport image select related)
    (proof : Artifact → BlockStep Proof) (linkRelated : Artifact → NativeState → Proof → Prop)
    (linkLaw : ∀ a, TranslationValidation (tokenStep (specializedToken env frame arena select a)) (proof a) (linkRelated a))
    (accepted : Artifact → Prop) (proofEntry : Artifact → Proof → Prop) (checked : Artifact → Event → Prop)
    (verifierSound : ∀ a, accepted a → ∀ p trace p', proofEntry a p →
      Execution (proof a) p trace p' → ∀ event∈trace, checked a event)
    (validated executed : Artifact) (binding : executed=validated) (acceptance : accepted validated)
    {n : NativeState} {p : Proof} {trace : List Event} {last : NativeState}
    (entry : ∃ s, (∃ i, related validated n i ∧ i=s) ∧ linkRelated validated s p)
    (admitted : proofEntry validated p)
    (run : Execution (actualNative executed) n trace last) :
    ∀ event∈trace, checked validated event := by
  exact native_effects_checked actualNative proof
    (fun a n p => ∃ s, (∃ i, related a n i ∧ i=s) ∧ linkRelated a s p)
    accepted proofEntry checked verifierSound validated executed binding acceptance
    (actual_program_block_validation actualNative image env frame arena select coverage related fields transport proof linkRelated linkLaw validated)
    entry admitted run

/-- The generic native block relation and accepted B share one kernel copy.
The construction supplies Artifact identity by reflexivity. -/
theorem actual_program_effects_from_kernel_copy {Proof : Type} (actualNative : Artifact → BlockStep NativeState)
    (image : Artifact → Memory) (env : Artifact → EntryEnvironment.Environment)
    (frame : Artifact → EntryEnvironment.Frame) (arena : Artifact → Reference.Word)
    (select : Artifact → Site → NativeState → Prop)
    (coverage : ∀ a before trace after, actualNative a before trace after →
      Execution (tokenStep (nativeToken image select a)) before trace after)
    (related : Artifact → NativeState → NativeState → Prop)
    (fields : FieldsAligned image select related) (transport : DefinednessTransport image select related)
    (proof : Artifact → BlockStep Proof) (linkRelated : Artifact → NativeState → Proof → Prop)
    (linkLaw : ∀ a, TranslationValidation (tokenStep (specializedToken env frame arena select a)) (proof a) (linkRelated a))
    (accepted : Artifact → Prop) (proofEntry : Artifact → Proof → Prop) (checked : Artifact → Event → Prop)
    (verifierSound : ∀ a, accepted a → ∀ p trace p', proofEntry a p →
      Execution (proof a) p trace p' → ∀ event∈trace, checked a event)
    (kernelCopy : Artifact) (acceptance : accepted kernelCopy)
    {n : NativeState} {p : Proof} {trace : List Event} {last : NativeState}
    (entry : ∃ s, (∃ i, related kernelCopy n i ∧ i=s) ∧ linkRelated kernelCopy s p)
    (admitted : proofEntry kernelCopy p)
    (run : Execution (actualNative kernelCopy) n trace last) :
    ∀ event∈trace, checked kernelCopy event := by
  exact native_effects_checked actualNative proof
    (fun a n p => ∃ s, (∃ i, related a n i ∧ i=s) ∧ linkRelated a s p)
    accepted proofEntry checked verifierSound kernelCopy kernelCopy rfl acceptance
    (actual_program_block_validation actualNative image env frame arena select coverage related fields transport proof linkRelated linkLaw kernelCopy)
    entry admitted run

end KProgTV.SimulatorComposition

#print axioms KProgTV.SimulatorComposition.encode_native
#print axioms KProgTV.SimulatorComposition.canonical_successors_match
#print axioms KProgTV.SimulatorComposition.native_to_interpreted
#print axioms KProgTV.SimulatorComposition.interpreted_to_specialized
#print axioms KProgTV.SimulatorComposition.specialized_reflects
#print axioms KProgTV.SimulatorComposition.program_block_validation
#print axioms KProgTV.SimulatorComposition.program_effects_checked

#print axioms KProgTV.SimulatorComposition.complete_match

#print axioms KProgTV.SimulatorComposition.branch_complete

#print axioms KProgTV.SimulatorComposition.move_complete

#print axioms KProgTV.SimulatorComposition.exact_definedness_transport

#print axioms KProgTV.SimulatorComposition.exact_program_block_validation

#print axioms KProgTV.SimulatorComposition.actual_program_block_validation

#print axioms KProgTV.SimulatorComposition.actual_program_effects_checked

#print axioms KProgTV.SimulatorComposition.actual_program_effects_from_kernel_copy
