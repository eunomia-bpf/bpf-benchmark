import TrustedSimpleB29State

/-! Ghost observations for the concrete B29 certificate. The observer never
executes another ISA or changes physical BPF state/effects. Every transition
below contains an actual accepted-program step as its premise. -/
set_option maxRecDepth 4096
set_option maxHeartbeats 2000000
namespace KProgTV.TrustedSimpleB29Observer
open KProgFormal.Reference
open TrustedSimpleX86

inductive Phase where
  | initial | dataFault | endFault | firstGuard | secondGuard | thirdGuard | stores
  deriving Repr, DecidableEq

structure Frame where
  entryNative : X86.State
  initialProof : BPF.State
  cpu : BPF.State
  phase : Phase
  stackInput : Option Word
  storeEntry : Option BPF.State

def initialFrame (entry : X86.State) (p : BPF.State) : Frame :=
  ⟨entry,p,p,.initial,none,none⟩

/-- Capture only real B values at their actual instruction positions.
Immutable invocation inputs are retained; no observation affects execution. -/
def advance (before : Frame) (effect : Transition BPF.State) : Frame :=
  {before with
    cpu := effect.state
    phase := if effect.fault.isSome && before.cpu.pc=1 then .dataFault
      else if effect.fault.isSome && before.cpu.pc=2 then .endFault
      else if before.cpu.pc=4 then .firstGuard
      else if before.cpu.pc=7 then .secondGuard
      else if before.cpu.pc=10 then .thirdGuard
      else if before.cpu.pc=11 then .stores else before.phase
    stackInput := if before.cpu.pc=0 then some (effect.state.regs 0) else before.stackInput
    storeEntry := if before.cpu.pc=11 then some before.cpu else before.storeEntry}

def observedStep (env : BPF.Environment) : BlockStep Frame :=
  fun before events after => ∃ effect,
    BPFPlatform.step (TrustedSimpleB29.environment env) TrustedSimpleB29.proof before.cpu=.ok effect ∧
    effect.events=events ∧ after=advance before effect

theorem observed_step_erases (env : BPF.Environment) (before after : Frame) (events : List Event)
    (step : observedStep env before events after) :
    TrustedSimpleB29.instructionStep env before.cpu events after.cpu := by
  obtain ⟨effect,actual,trace,rfl⟩ := step
  exact ⟨effect,actual,trace,rfl⟩

/-- Every observed finite execution is a real B29 execution with precisely
identical effects and physical endpoints; ghost metadata cannot authorize B. -/
theorem observed_execution_erases (env : BPF.Environment) (before after : Frame) (events : List Event)
    (run : Execution (observedStep env) before events after) :
    Execution (TrustedSimpleB29.instructionStep env) before.cpu events after.cpu := by
  induction run with
  | refl => exact Execution.refl _
  | next step rest ih => exact Execution.next (observed_step_erases env _ _ _ step) ih

/-- Snapshot lineage always starts from the same invocation/initial proof
state. Neither arbitrary branch history nor a new initial frame can be injected. -/
theorem observed_execution_frame (env : BPF.Environment) (before after : Frame) (events : List Event)
    (run : Execution (observedStep env) before events after) :
    after.entryNative=before.entryNative ∧ after.initialProof=before.initialProof := by
  induction run with
  | refl => exact ⟨rfl,rfl⟩
  | next step rest ih =>
    obtain ⟨effect,_,_,rfl⟩ := step
    simpa only [advance] using ih

/-- Soundness for actual B executions transfers to the observer without any
new verifier assumption about the ghost values. The TV block simulation is a
separate obligation and is not supplied by these erasure theorems. -/
theorem checked_effects_transfer (env : BPF.Environment) (before after : Frame) (events : List Event)
    (checked : Event → Prop)
    (sound : ∀ trace last, Execution (TrustedSimpleB29.instructionStep env) before.cpu trace last →
      ∀ event ∈ trace, checked event)
    (run : Execution (observedStep env) before events after) :
    ∀ event ∈ events, checked event :=
  sound _ _ (observed_execution_erases env before after events run)


/-- Every store snapshot is inherited from the initial observer or was the
physical CPU state at an actual reached BPC11 boundary. -/
theorem observed_store_lineage (env : BPF.Environment) (before after : Frame) (events : List Event)
    (run : Execution (observedStep env) before events after) :
    ∀ saved, after.storeEntry=some saved → before.storeEntry=some saved ∨
      ∃ prefixTrace point, Execution (observedStep env) before prefixTrace point ∧
        point.cpu.pc=11 ∧ saved=point.cpu := by
  induction run with
  | refl => intro saved found; exact Or.inl found
  | @next start middle finish head tail step rest ih =>
    intro saved found
    rcases ih saved found with inherited | ⟨prefixTrace,point,reached,position,same⟩
    · obtain ⟨effect,_,_,middleEq⟩ := step
      have actualSnapshot : (advance start effect).storeEntry=some saved := by
        simpa only [middleEq] using inherited
      by_cases position : start.cpu.pc=11
      · have same : start.cpu=saved := Option.some.inj (by
          simpa only [advance,position,ite_true] using actualSnapshot)
        exact Or.inr ⟨[],start,Execution.refl start,position,same.symm⟩
      · exact Or.inl (by simpa only [advance,position,ite_false] using actualSnapshot)
    · exact Or.inr ⟨head++prefixTrace,point,Execution.next step reached,position,same⟩

/-- Starting with no snapshots, a recorded store entry always comes from a
real B execution prefix. No native result or unobserved B value supplies it. -/
theorem initial_store_snapshot_provenance (env : BPF.Environment) (entry : X86.State)
    (initial : BPF.State) (after : Frame) (events : List Event) (saved : BPF.State)
    (run : Execution (observedStep env) (initialFrame entry initial) events after)
    (found : after.storeEntry=some saved) :
    ∃ prefixTrace point, Execution (observedStep env) (initialFrame entry initial) prefixTrace point ∧
      point.cpu.pc=11 ∧ saved=point.cpu := by
  rcases observed_store_lineage env _ _ _ run saved found with inherited | reached
  · simp only [initialFrame] at inherited
    cases inherited
  · exact reached

/-- Conversely, every real B execution lifts to the observer. Ghost
metadata never disables a B step, adds a predicate, or restricts an input. -/
theorem observed_execution_lifts (env : BPF.Environment) (before : Frame)
    (last : BPF.State) (events : List Event)
    (run : Execution (TrustedSimpleB29.instructionStep env) before.cpu events last) :
    ∃ after, Execution (observedStep env) before events after ∧ after.cpu=last := by
  generalize initialEq : before.cpu=initial at run
  induction run generalizing before with
  | refl => exact ⟨before,Execution.refl before,initialEq⟩
  | @next start middle finish head tail step rest ih =>
    obtain ⟨effect,actual,trace,stateEq⟩ := step
    have actualBefore : BPFPlatform.step (TrustedSimpleB29.environment env)
        TrustedSimpleB29.proof before.cpu=.ok effect := by rw [initialEq]; exact actual
    obtain ⟨after,suffix,endpoint⟩ := ih (advance before effect) stateEq
    exact ⟨after,Execution.next ⟨effect,actualBefore,trace,rfl⟩ suffix,endpoint⟩

/-- The projection is exact in both directions, rather than merely an
observer that might select only a safer subset of accepted B executions. -/
theorem observed_execution_iff (env : BPF.Environment) (before : Frame)
    (last : BPF.State) (events : List Event) :
    Execution (TrustedSimpleB29.instructionStep env) before.cpu events last ↔
      ∃ after, Execution (observedStep env) before events after ∧ after.cpu=last := by
  constructor
  · exact observed_execution_lifts env before last events
  · rintro ⟨after,run,endpoint⟩
    simpa only [endpoint] using observed_execution_erases env before after events run

/-- The complete decoded native path has the full architecture obtained
from a real observed accepted-B execution. All invocation fields and the
initial proof state retain proved lineage; fault/branch/write outcomes are
selected by the single reference semantics, not supplied as premises. -/
theorem complete_native_observed_architecture (env : BPF.Environment)
    (entry : X86.State) (initial : BPF.State) (stack : Word) (actual : Transition X86.State)
    (nativePC : entry.pc=0) (proofPC : initial.pc=0) (active : initial.halted=false)
    (argument : entry.gpr 7=initial.regs 1) (memory : entry.memory=initial.memory)
    (input : env.nativeInput .stackPointer=.ok stack)
    (run : CanonicalRelationalPath 0 TrustedSimpleX86.native
      (TrustedSimpleX86.allReadNativePath entry) entry actual) :
    ∃ after, Execution (observedStep env) (initialFrame entry initial) actual.events after ∧
      after.cpu=TrustedSimpleB29.allInputsAfter initial stack ∧
      actual.state=TrustedSimpleB29State.observedAllView entry initial stack after.cpu ∧
      actual.fault=(TrustedSimpleX86.allReadNativeResult entry).fault ∧
      after.entryNative=entry ∧ after.initialProof=initial := by
  obtain ⟨architecture,fault,physical⟩ :=
    TrustedSimpleB29State.all_inputs_relational_architecture env entry initial stack actual
      nativePC proofPC active argument memory input run
  obtain ⟨after,observed,endpoint⟩ :=
    observed_execution_lifts env (initialFrame entry initial) _ _ physical
  obtain ⟨sameEntry,sameInitial⟩ := observed_execution_frame env _ _ _ observed
  exact ⟨after,observed,endpoint,by simpa only [endpoint] using architecture,fault,sameEntry,sameInitial⟩

end KProgTV.TrustedSimpleB29Observer
#print axioms KProgTV.TrustedSimpleB29Observer.observed_step_erases
#print axioms KProgTV.TrustedSimpleB29Observer.observed_execution_erases
#print axioms KProgTV.TrustedSimpleB29Observer.observed_execution_frame
#print axioms KProgTV.TrustedSimpleB29Observer.checked_effects_transfer

#print axioms KProgTV.TrustedSimpleB29Observer.observed_store_lineage
#print axioms KProgTV.TrustedSimpleB29Observer.initial_store_snapshot_provenance

#print axioms KProgTV.TrustedSimpleB29Observer.observed_execution_lifts
#print axioms KProgTV.TrustedSimpleB29Observer.observed_execution_iff
#print axioms KProgTV.TrustedSimpleB29Observer.complete_native_observed_architecture
