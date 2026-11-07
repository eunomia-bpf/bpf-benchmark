import KProgFormal.Reference.AArch64
import Composition

namespace KProgTV.ARM64Path
open KProgFormal.Reference
abbrev State := AArch64.State

def step (base : Word) (bytes : Array Byte) (state : State) :
    Except String (Transition State) := do
  let position := (state.pc - base).toNat
  if position + 4 > bytes.size then throw "native PC outside bound artifact"
  let instruction ← AArch64.decode (bytes.extract position (position + 4))
  pure (AArch64.step instruction state)

/-- A path certificate checks the real reference successor, never changes it. -/
def evaluate (base : Word) (bytes : Array Byte) :
    List Nat → State → Except String (Transition State)
  | [], state => .ok ⟨state, [], none⟩
  | position :: rest, state =>
      if state.pc != base + BitVec.ofNat 64 position then
        .error "certificate native successor mismatch"
      else match step base bytes state with
        | .error error => .error error
        | .ok first =>
            if first.fault.isSome then
              if rest.isEmpty then .ok first
              else .error "certificate continues after native fault"
            else match evaluate base bytes rest first.state with
              | .error error => .error error
              | .ok tail => .ok { tail with events := first.events ++ tail.events }

def instructionStep (base : Word) (bytes : Array Byte) : BlockStep State :=
  fun before events after => ∃ effect,
    step base bytes before = .ok effect ∧ effect.events = events ∧ effect.state = after

theorem evaluate_sound (base : Word) (bytes : Array Byte)
    (positions : List Nat) (state : State) (result : Transition State)
    (accepted : evaluate base bytes positions state = .ok result) :
    Execution (instructionStep base bytes) state result.events result.state := by
  induction positions generalizing state result with
  | nil =>
      simp [evaluate] at accepted
      cases accepted
      exact Execution.refl state
  | cons position rest ih =>
      simp only [evaluate] at accepted
      split at accepted
      · simp at accepted
      · cases executed : step base bytes state with
        | error error => simp [evaluate, *, executed] at accepted
        | ok first =>
            have head : instructionStep base bytes state first.events first.state :=
              ⟨first, executed, rfl, rfl⟩
            cases fault : first.fault with
            | some reason =>
                cases rest with
                | nil =>
                    simp [evaluate, *, executed, fault] at accepted
                    cases accepted
                    simpa using Execution.next head (Execution.refl result.state)
                | cons next tail => simp [evaluate, *, executed, fault] at accepted
            | none =>
                cases continued : evaluate base bytes rest first.state with
                | error error => simp [evaluate, *, executed, fault, continued] at accepted
                | ok tail =>
                    simp [evaluate, *, executed, fault, continued] at accepted
                    cases accepted
                    exact Execution.next head (ih first.state tail continued)

/-- Lift an accepted source witness through pointwise checked byte steps.
The position list only selects a proof witness; each target head is an actual
byte-decoded transition and no target PC or branch is forced. -/
theorem evaluate_execution_transport (sourceBase targetBase : Word)
    (source target : Array Byte) (stateMap : State → State) (allowed : Nat → Prop)
    (stepMap : ∀ s position, allowed position → s.pc = sourceBase + BitVec.ofNat 64 position →
      ∀ result, step sourceBase source s = .ok result →
      instructionStep targetBase target (stateMap s) result.events (stateMap result.state))
    (positions : List Nat) (inside : ∀ position ∈ positions, allowed position)
    (state : State) (result : Transition State)
    (accepted : evaluate sourceBase source positions state = .ok result) :
    Execution (instructionStep targetBase target) (stateMap state) result.events (stateMap result.state) := by
  induction positions generalizing state result with
  | nil =>
      simp [evaluate] at accepted
      cases accepted
      exact Execution.refl _
  | cons position rest ih =>
      simp only [evaluate] at accepted
      split at accepted
      · simp at accepted
      · rename_i matching
        have pc : state.pc = sourceBase + BitVec.ofNat 64 position := by simpa using matching
        cases executed : step sourceBase source state with
        | error error => simp [executed] at accepted
        | ok first =>
          have head := stepMap state position (inside position (by simp)) pc first executed
          cases fault : first.fault with
          | some reason =>
            cases rest with
            | nil =>
                simp [executed, fault] at accepted
                cases accepted
                simpa using Execution.next head (Execution.refl (stateMap result.state))
            | cons next tail => simp [executed, fault] at accepted
          | none =>
            cases continued : evaluate sourceBase source rest first.state with
            | error error => simp [executed, fault, continued] at accepted
            | ok tail =>
              simp [executed, fault, continued] at accepted
              cases accepted
              exact Execution.next head (ih (fun pos member => inside pos (List.mem_cons_of_mem _ member))
                first.state tail continued)

end KProgTV.ARM64Path

#print axioms KProgTV.ARM64Path.evaluate_sound

#print axioms KProgTV.ARM64Path.evaluate_execution_transport
