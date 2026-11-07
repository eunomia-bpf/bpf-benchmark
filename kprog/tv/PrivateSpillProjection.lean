import Composition

/-! Universal verifier-visible projection for compiler-private spill bytes.
Ownership is supplied by the generic compiler/layout relation. Physical
executions and canonical event values remain the source of every observation. -/
namespace KProgTV.PrivateSpillProjection
open KProgFormal.Reference

/-- A complete ordinary access belongs to the compiler-private region. -/
def privateAccess (privateByte : Word → Bool) (address : Word) (bytes : List Byte) : Bool :=
  (!bytes.isEmpty) && (List.range bytes.length).all (fun i => privateByte (address+BitVec.ofNat 64 i))

/-- Projection retains every helper, atomic, exclusive and fault effect.
Ordinary reads/writes use the ownership of every addressed byte. -/
def project (privateByte : Word → Bool) : Event → Option Event
  | event@(.memory .read address bytes _) =>
      if privateAccess privateByte address bytes then none else some event
  | event@(.memory .write address bytes _) =>
      if privateAccess privateByte address bytes then none else some event
  | event => some event

/-- A retained event has its original address, size, kind, values and flags. -/
theorem kept_event_original (privateByte : Word → Bool) (before after : Event)
    (kept : project privateByte before=some after) : before=after := by
  cases before with
  | memory kind address bytes initialized =>
    cases kind with
    | read =>
      simp only [project] at kept
      split at kept
      · contradiction
      · exact Option.some.inj kept
    | write =>
      simp only [project] at kept
      split at kept
      · contradiction
      · exact Option.some.inj kept
    | atomic => exact Option.some.inj kept
  | helper => exact Option.some.inj kept
  | fault => exact Option.some.inj kept
  | exclusive => exact Option.some.inj kept

/-- Every erased effect is an ordinary access fully owned by the compiler's
private region and carries a positive byte count. Other canonical event
constructors and empty access events remain observable. -/
theorem erased_access_owned (privateByte : Word → Bool) (event : Event)
    (erased : project privateByte event=none) :
    ∃ kind address bytes initialized, event=.memory kind address bytes initialized ∧
      (kind=.read ∨ kind=.write) ∧ 0<bytes.length ∧
      ∀ i<bytes.length, privateByte (address+BitVec.ofNat 64 i)=true := by
  cases event with
  | memory kind address bytes initialized =>
    cases kind with
    | read =>
      simp only [project] at erased
      split at erased
      · rename_i owned
        have positive : 0<bytes.length := by cases bytes <;> simp_all [privateAccess]
        exact ⟨.read,address,bytes,initialized,rfl,Or.inl rfl,positive,
          fun i small => (List.all_eq_true.mp (Bool.and_eq_true_iff.mp owned).2) i (List.mem_range.mpr small)⟩
      · contradiction
    | write =>
      simp only [project] at erased
      split at erased
      · rename_i owned
        have positive : 0<bytes.length := by cases bytes <;> simp_all [privateAccess]
        exact ⟨.write,address,bytes,initialized,rfl,Or.inr rfl,positive,
          fun i small => (List.all_eq_true.mp (Bool.and_eq_true_iff.mp owned).2) i (List.mem_range.mpr small)⟩
      · contradiction
    | atomic => contradiction
  | helper => contradiction
  | fault => contradiction
  | exclusive => contradiction

/-- Raw verifier-checked effects imply checked projected effects. -/
theorem projected_trace_checked (privateByte : Word → Bool) (checked : Event → Prop)
    (events : List Event) (sound : ∀ event∈events, checked event) :
    ∀ event∈events.filterMap (project privateByte), checked event := by
  intro event member
  obtain ⟨original,inside,kept⟩ := List.mem_filterMap.mp member
  rw [← kept_event_original privateByte original event kept]
  exact sound original inside

/-- A projected block contains a real instruction execution and its physical
endpoints. It can group any finite number of actual B steps. -/
def projectedBlock {State : Type} (privateByte : Word → Bool) (raw : BlockStep State) : BlockStep State :=
  fun before events after => ∃ rawEvents, Execution raw before rawEvents after ∧
    rawEvents.filterMap (project privateByte)=events

/-- Every projected execution lifts to a physical execution with the same
endpoints and exact ordered projection of its raw trace. -/
theorem projected_execution_lifts {State : Type} (privateByte : Word → Bool)
    (raw : BlockStep State) {before after : State} {events : List Event}
    (run : Execution (projectedBlock privateByte raw) before events after) :
    ∃ rawEvents, Execution raw before rawEvents after ∧
      rawEvents.filterMap (project privateByte)=events := by
  induction run with
  | refl => exact ⟨[],Execution.refl _,rfl⟩
  | next head tail ih =>
    obtain ⟨headEvents,headRun,headProjection⟩ := head
    obtain ⟨tailEvents,tailRun,tailProjection⟩ := ih
    exact ⟨headEvents++tailEvents,headRun.append tailRun,by
      simp only [List.filterMap_append,headProjection,tailProjection]⟩

/-- Actual accepted-B soundness transfers through the generic ownership
projection, using the actual B trace and retained-event identity. -/
theorem projected_execution_checked {State : Type} (privateByte : Word → Bool)
    (raw : BlockStep State) (before : State) (checked : Event → Prop)
    (sound : ∀ rawEvents last, Execution raw before rawEvents last →
      ∀ event∈rawEvents, checked event)
    {after : State} {events : List Event}
    (run : Execution (projectedBlock privateByte raw) before events after) :
    ∀ event∈events, checked event := by
  obtain ⟨rawEvents,rawRun,projection⟩ := projected_execution_lifts privateByte raw run
  rw [← projection]
  exact projected_trace_checked privateByte checked rawEvents (sound rawEvents after rawRun)

/-- Universal artifact composition with compiler-private spill projection.
The validation law ranges over all artifacts; verifier soundness refers to
their actual physical proof executions. Binding includes layout metadata. -/
theorem generic_artifact_effects_checked {Native Proof : Type}
    (native : Artifact → BlockStep Native) (rawProof : Artifact → BlockStep Proof)
    (privateByte : Artifact → Word → Bool) (related : Artifact → Native → Proof → Prop)
    (validation : ∀ a, TranslationValidation (native a)
      (projectedBlock (privateByte a) (rawProof a)) (related a))
    (accepted : Artifact → Prop) (proofEntry : Artifact → Proof → Prop)
    (checked : Artifact → Event → Prop)
    (verifierSound : ∀ a, accepted a → ∀ p trace p', proofEntry a p →
      Execution (rawProof a) p trace p' → ∀ event∈trace, checked a event)
    (validated executed : Artifact) (binding : executed=validated) (acceptance : accepted validated)
    {n p trace n'} (entry : related validated n p) (admitted : proofEntry validated p)
    (run : Execution (native executed) n trace n') :
    ∀ event∈trace, checked validated event := by
  apply native_effects_checked native (fun a => projectedBlock (privateByte a) (rawProof a)) related
    accepted proofEntry checked ?_ validated executed binding acceptance (validation validated) entry admitted run
  intro a acceptedA p events last entryA projectedRun
  exact projected_execution_checked (privateByte a) (rawProof a) p (checked a)
    (fun rawEvents rawLast rawRun => verifierSound a acceptedA p rawEvents rawLast entryA rawRun) projectedRun

end KProgTV.PrivateSpillProjection
#print axioms KProgTV.PrivateSpillProjection.kept_event_original
#print axioms KProgTV.PrivateSpillProjection.erased_access_owned
#print axioms KProgTV.PrivateSpillProjection.projected_trace_checked
#print axioms KProgTV.PrivateSpillProjection.projected_execution_lifts
#print axioms KProgTV.PrivateSpillProjection.projected_execution_checked
#print axioms KProgTV.PrivateSpillProjection.generic_artifact_effects_checked
