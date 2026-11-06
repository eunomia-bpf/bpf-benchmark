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

end KProgTV.ARM64Path

#print axioms KProgTV.ARM64Path.evaluate_sound
