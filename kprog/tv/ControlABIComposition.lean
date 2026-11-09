import Composition
import PrivateSpillProjection
import KProgFormal.ControlABI

/-! Universal returning/transfer composition at the kernel tail-call boundary.
BPFPlatform's returning helper branch and the successful kernel tail helper
have different operational outcomes. The physical kernel/JIT correspondence
supplies the transfer primitive below; the ordinary BPF instruction semantics
retains its existing returning interpretation. -/
namespace KProgTV.ControlABIComposition
open KProgFormal KProgFormal.Reference
abbrev Word := KProgFormal.Reference.Word

/-- Kernel object contents retained across lookup, unwind and target entry.
Both byte streams, permissions and metadata belong to this one object. -/
structure TargetImage where
  target : TailCallBinding.Target
  nativeBytes : Array Byte
  proofBytes : Array Byte
  permissions : Word → Bool
  metadata : List Byte

/-- A control boundary includes the shared tail counter and outer return.
The body state carries every register, memory/provenance and environment index. -/
structure Boundary (State : Type) where
  body : State
  context : Word
  count : Nat
  outerReturn : Word

/-- Returning body edges and successful kernel transfers compose uniformly.
The latter retains the exact target object and its own entry relation. -/
inductive ControlStep {State : Type} (body transfer : BlockStep State) : BlockStep State where
  | body {first events last} : body first events last → ControlStep body transfer first events last
  | transfer {first events last} : transfer first events last → ControlStep body transfer first events last

/-- Whole-prefix simulation includes arbitrary interleavings of body edges
and successful transfers, including repeated transfers and target loops. -/
theorem control_simulation {Native Proof : Type}
    {nativeBody nativeTransfer : BlockStep Native} {proofBody proofTransfer : BlockStep Proof}
    {related : Native → Proof → Prop}
    (body : TranslationValidation nativeBody proofBody related)
    (transfer : TranslationValidation nativeTransfer proofTransfer related) :
    TranslationValidation (ControlStep nativeBody nativeTransfer)
      (ControlStep proofBody proofTransfer) related := by
  constructor
  intro n p events next relation step
  cases step with
  | body actual =>
    obtain ⟨final, run, finalRelation⟩ := body.block relation actual
    exact ⟨final, run.of_step_imp (fun h => ControlStep.body h), finalRelation⟩
  | transfer actual =>
    obtain ⟨final, run, finalRelation⟩ := transfer.block relation actual
    exact ⟨final, run.of_step_imp (fun h => ControlStep.transfer h), finalRelation⟩

/-- A successful B transfer is a platform control outcome, with a real target
entry and a shared counter. The matching primitive preserves exact event order.
Its source correspondence includes decoded CALL12 and kernel map selection. -/
inductive TailTransfer {State : Type}
    (lookup : State → Nat → Option TargetImage)
    (index : State → BitVec 32) (limit : State → Nat) (budget : Nat)
    (enter : TargetImage → Word → Nat → Word → State)
    (events : State → TargetImage → List Event) : BlockStep (Boundary State) where
  | selected (first : Boundary State) (image : TargetImage)
      (inRange : (index first.body).toNat < limit first.body)
      (available : first.count < budget)
      (selected : lookup first.body (index first.body).toNat = some image) :
      TailTransfer lookup index limit budget enter events first (events first.body image)
        ⟨enter image first.context (first.count + 1) first.outerReturn,
          first.context, first.count + 1, first.outerReturn⟩

/-- S6's Outcome.transfer is derived from the actual selected platform image.
Failed selection retains its separate returning continuation in S6.invoke. -/
theorem successful_B_outcome {State : Type}
    (lookup : State → Nat → Option TargetImage) (index : State → BitVec 32)
    (limit : State → Nat) (budget : Nat)
    (enter : TargetImage → Word → Nat → Word → State)
    (events : State → TargetImage → List Event)
    (first last : Boundary State) (trace : List Event)
    (run : TailTransfer lookup index limit budget enter events first trace last)
    (rawIndex continuation : Word) (indexBits : rawIndex.setWidth 32 = index first.body) :
    ∃ image,
      TailCallBinding.invoke (limit first.body) budget first.count rawIndex
        first.context continuation first.outerReturn
        (fun slot => (lookup first.body slot).map TargetImage.target) =
        .transfer image.target first.context (first.count + 1) first.outerReturn ∧
      last.body = enter image first.context (first.count + 1) first.outerReturn ∧
      last.count = first.count + 1 ∧ last.outerReturn = first.outerReturn ∧
      trace = events first.body image := by
  cases run with
  | selected first image inRange available chosen =>
    refine ⟨image, ?_, rfl, rfl, rfl, rfl⟩
    apply TailCallBinding.successful_transfer
    simp [TailCallBinding.select, indexBits, inRange, available, chosen]

/-- A coupled lookup observes one RCU-retained object. Entry correspondence
quantifies over every object, context, count and outer return. Both entry
functions receive the exact same image bytes, permissions and metadata. -/
theorem tail_transfer_simulation {Native Proof : Type}
    (nativeLookup : Native → Nat → Option TargetImage)
    (proofLookup : Proof → Nat → Option TargetImage)
    (nativeIndex : Native → BitVec 32) (proofIndex : Proof → BitVec 32)
    (nativeLimit : Native → Nat) (proofLimit : Proof → Nat) (budget : Nat)
    (nativeEnter : TargetImage → Word → Nat → Word → Native)
    (proofEnter : TargetImage → Word → Nat → Word → Proof)
    (nativeEvents : Native → TargetImage → List Event)
    (proofEvents : Proof → TargetImage → List Event)
    (bodyRelated : Native → Proof → Prop)
    (snapshot : ∀ n p, bodyRelated n p →
      nativeIndex n = proofIndex p ∧ nativeLimit n = proofLimit p ∧
      ∀ slot, nativeLookup n slot = proofLookup p slot)
    (effects : ∀ n p, bodyRelated n p → ∀ image, nativeEvents n image = proofEvents p image)
    (entry : ∀ image context count outer,
      bodyRelated (nativeEnter image context count outer) (proofEnter image context count outer)) :
    TranslationValidation
      (TailTransfer nativeLookup nativeIndex nativeLimit budget nativeEnter nativeEvents)
      (TailTransfer proofLookup proofIndex proofLimit budget proofEnter proofEvents)
      (fun n p => bodyRelated n.body p.body ∧ n.context = p.context ∧
        n.count = p.count ∧ n.outerReturn = p.outerReturn) := by
  constructor
  intro n p trace next relation step
  obtain ⟨body, context, count, outer⟩ := relation
  obtain ⟨index, limit, lookup⟩ := snapshot n.body p.body body
  cases step with
  | selected first image inRange available selected =>
    let final : Boundary Proof :=
      ⟨proofEnter image p.context (p.count + 1) p.outerReturn,
        p.context, p.count + 1, p.outerReturn⟩
    have proofStep : TailTransfer proofLookup proofIndex proofLimit budget proofEnter proofEvents
        p (proofEvents p.body image) final :=
      TailTransfer.selected p image (by simpa [← index, ← limit] using inRange)
        (by simpa [← count] using available) (by simpa [← index, ← lookup] using selected)
    refine ⟨final, ?_, ?_⟩
    · rw [effects n.body p.body body image]
      simpa using Execution.next proofStep (Execution.refl final)
    · exact ⟨by simpa [final, context, count, outer] using entry image p.context (p.count+1) p.outerReturn,
        context, congrArg (· + 1) count, outer⟩

/-- Conditional safety uses accepted physical B executions, complete body
simulation, the transfer primitive correspondence and private-effect ownership.
Every native prefix, across successful transfers, inherits those checked effects. -/
theorem control_effects_checked {Native Proof : Type}
    {nativeBody nativeTransfer : BlockStep Native} {proofBody proofTransfer : BlockStep Proof}
    {related : Native → Proof → Prop}
    (body : TranslationValidation nativeBody proofBody related)
    (transfer : TranslationValidation nativeTransfer proofTransfer related)
    (checked : Event → Prop) {n last : Native} {p : Proof} {trace : List Event}
    (initial : related n p)
    (verifier : ∀ events final, Execution (ControlStep proofBody proofTransfer) p events final →
      ∀ event ∈ events, checked event)
    (run : Execution (ControlStep nativeBody nativeTransfer) n trace last) :
    ∀ event ∈ trace, checked event := by
  obtain ⟨final, actual, _⟩ := validated_execution (control_simulation body transfer) initial run
  exact verifier trace final actual

/-- Resolved native helpers and actual returning B CALLs share one typed
pre-call tuple and complete effect. The kernel effect relation is universal
per descriptor, including attach aliases, map families and consuming lifetimes. -/
theorem resolved_returning_helper_execute
    (environment : BPF.Environment) (program : Array Byte) (state : BPF.State)
    (instruction : BPF.Instruction) (call : BPF.HelperCall)
    (byId : Word → Option ControlABI.Helper) (symbols : String → Option Word)
    (identity : Word) (helper resolved : ControlABI.Helper)
    (arguments : Fin 5 → ControlABI.TypedValue)
    (nativeEffect : ControlABI.Helper → (Fin 5 → ControlABI.TypedValue) → Memory → BPF.HelperResult)
    (registry : byId identity = some helper) (canonical : helper.identity = identity)
    (selected : ControlABI.resolve byId symbols identity = some resolved)
    (typed : ControlABI.ArgumentsTyped helper arguments)
    (opcode : instruction.code = 0x85) (source : instruction.src = 0 ∨ instruction.src = 2)
    (callIdentity : call.identity = identity)
    (callResolved : environment.helperCall instruction state = .ok call)
    (captured : BPF.helperArguments call state =
      (List.ofFn fun i => ControlABI.typedBits (arguments i)).take call.argumentCount.val)
    (kernelEffect : environment.helper call
      ((List.ofFn fun i => ControlABI.typedBits (arguments i)).take call.argumentCount.val)
      state.memory = .ok (nativeEffect resolved arguments state.memory)) :
    let effect := nativeEffect resolved arguments state.memory
    resolved.identity = call.identity ∧ ControlABI.ArgumentsTyped resolved arguments ∧
    BPF.execute environment program state instruction = .ok
      ⟨{ state with
          pc := state.pc + 1
          memory := effect.memory
          regs := fun register : BPF.Register =>
            if register.val = 0 then effect.result
            else if h : register.val - 1 < 5 then effect.clobbers ⟨register.val - 1, h⟩
            else state.regs register },
        effect.events ++ [.helper call.identity (BPF.helperArguments call state) effect.result], none⟩ := by
  refine ⟨(ControlABI.resolver_identity_signature byId symbols identity helper resolved
      registry canonical selected).1.trans callIdentity.symm,
    ControlABI.resolved_arguments_typed byId symbols identity helper resolved arguments
      registry canonical selected typed, ?_⟩
  apply BPFPlatform.returning_helper_execute environment program state instruction call _ opcode source callResolved
  rw [captured]
  exact kernelEffect

/-- S6's generic CFG paths transport to the actual finite-execution relation. -/
theorem cfg_path_execution {State : Type} {step : BlockStep State}
    {first last : State} {events : List Event}
    (path : SpillControl.Path step first events last) : Execution step first events last := by
  induction path with
  | refl state => exact Execution.refl state
  | next head tail ih => exact Execution.next head ih

/-- The compiler's local CFG/frame correspondence yields an actual decoded B
execution with the exact public trace. Spill/reload, arbitrary body effects,
loops and early exits share the same universal compiler premise. -/
theorem compiled_spill_execution {Source Saved : Type}
    (capture : Source → Saved) (body : BlockStep Source)
    (environment : BPF.Environment) (program : Array Byte) (owned : Word → Bool)
    (related : SpillControl.Phase Source Saved → BPF.State → Prop)
    (compiler : ControlABI.CompilerCorrespondence (SpillControl.Edge capture body)
      (PrivateSpillProjection.projectedBlock owned (BPFPath.instructionStep environment program)) related)
    {first last : Source} {machine : BPF.State} {events : List Event}
    (initial : related (.entry first) machine) (run : SpillControl.Path body first events last) :
    ∃ final rawEvents,
      Execution (BPFPath.instructionStep environment program) machine rawEvents final ∧
      rawEvents.filterMap (PrivateSpillProjection.project owned) = events ∧
      related (.entry last) final := by
  obtain ⟨final, cfg, relation⟩ := ControlABI.compiler_spill_cfg capture body _ related compiler initial run
  obtain ⟨rawEvents, physical, projection⟩ :=
    PrivateSpillProjection.projected_execution_lifts owned _ (cfg_path_execution cfg)
  exact ⟨final, rawEvents, physical, projection, relation⟩

/-- Stock-verifier soundness on physical B supplies safety for every source
prefix under universal local compiler/frame correspondence and owned erasure. -/
theorem compiled_spill_effects_checked {Source Saved : Type}
    (capture : Source → Saved) (body : BlockStep Source)
    (environment : BPF.Environment) (program : Array Byte) (owned : Word → Bool)
    (related : SpillControl.Phase Source Saved → BPF.State → Prop)
    (compiler : ControlABI.CompilerCorrespondence (SpillControl.Edge capture body)
      (PrivateSpillProjection.projectedBlock owned (BPFPath.instructionStep environment program)) related)
    (checked : Event → Prop) {first last : Source} {machine : BPF.State} {events : List Event}
    (initial : related (.entry first) machine)
    (verifier : ∀ rawEvents final, Execution (BPFPath.instructionStep environment program)
      machine rawEvents final → ∀ event ∈ rawEvents, checked event)
    (run : SpillControl.Path body first events last) : ∀ event ∈ events, checked event := by
  obtain ⟨final, rawEvents, physical, projection, _⟩ :=
    compiled_spill_execution capture body environment program owned related compiler initial run
  rw [← projection]
  exact PrivateSpillProjection.projected_trace_checked owned checked rawEvents
    (verifier rawEvents final physical)

end KProgTV.ControlABIComposition

#print axioms KProgTV.ControlABIComposition.successful_B_outcome
#print axioms KProgTV.ControlABIComposition.tail_transfer_simulation
#print axioms KProgTV.ControlABIComposition.control_effects_checked

#print axioms KProgTV.ControlABIComposition.compiled_spill_execution
#print axioms KProgTV.ControlABIComposition.compiled_spill_effects_checked

#print axioms KProgTV.ControlABIComposition.resolved_returning_helper_execute
