import BPF
import Composition

namespace KProgTV.BPFPath
open KProgFormal.Reference KProgTV.BPF

/-- A finite proof witness for a block. Each supplied position is checked
against the actual PC; it never changes the PC or forces a branch. An empty
suffix denotes a prefix boundary, whose correspondence is checked by TV. -/
def evaluate (env : Environment) (program : Array Byte) :
    List Nat → State → Except String (Transition State)
  | [], state => .ok ⟨state, [], none⟩
  | pc :: rest, state =>
      if state.halted then .error "certificate continues after BPF return"
      else if state.pc != (pc : Int) then .error "certificate BPF successor mismatch"
      else match decode program pc with
        | .error error => .error error
        | .ok instruction =>
            match execute env program state instruction with
            | .error error => .error error
            | .ok first =>
                if first.fault.isSome then
                  if rest.isEmpty then .ok first
                  else .error "certificate continues after BPF fault"
                else match evaluate env program rest first.state with
                  | .error error => .error error
                  | .ok tail => .ok { tail with events := first.events ++ tail.events }

def instructionStep (env : Environment) (program : Array Byte) : BlockStep State :=
  fun before events after => ∃ effect,
    step env program before = .ok effect ∧ effect.events = events ∧ effect.state = after

/-- The checker cannot authorize a forced CFG path. Every successful witness
is a real execution prefix of the byte-decoded BPF semantics, with its exact
ordered memory/helper/fault trace and complete resulting BPF state. -/
theorem evaluate_sound (env : Environment) (program : Array Byte)
    (positions : List Nat) (state : State) (result : Transition State)
    (accepted : evaluate env program positions state = .ok result) :
    Execution (instructionStep env program) state result.events result.state := by
  induction positions generalizing state result with
  | nil =>
      simp [evaluate] at accepted
      cases accepted
      exact Execution.refl state
  | cons pc rest ih =>
      cases active : state.halted with
      | true => simp [evaluate, active] at accepted
      | false =>
          by_cases position : state.pc = (pc : Int)
          · cases decoded : decode program pc with
            | error error => simp [evaluate, active, position, decoded] at accepted
            | ok instruction =>
                cases executed : execute env program state instruction with
                | error error => simp [evaluate, active, position, decoded, executed] at accepted
                | ok first =>
                    have actual : step env program state = .ok first := by
                      simp [step, active, position, decoded, executed]
                    have head : instructionStep env program state first.events first.state :=
                      ⟨first, actual, rfl, rfl⟩
                    cases fault : first.fault with
                    | some reason =>
                        cases rest with
                        | nil =>
                            simp [evaluate, active, position, decoded, executed, fault] at accepted
                            cases accepted
                            simpa using Execution.next head (Execution.refl result.state)
                        | cons next tail =>
                            simp [evaluate, active, position, decoded, executed, fault] at accepted
                    | none =>
                        cases continued : evaluate env program rest first.state with
                        | error error =>
                            simp [evaluate, active, position, decoded, executed, fault, continued] at accepted
                        | ok tail =>
                            simp [evaluate, active, position, decoded, executed, fault, continued] at accepted
                            cases accepted
                            exact Execution.next head (ih first.state tail continued)
          · simp [evaluate, active, position] at accepted


/-- Equality at the actual path positions and their possible LDDW
continuations transports a certificate to another captured program. -/
theorem evaluate_program_congr (env : Environment) (first second : Array Byte)
    (positions : List Nat)
    (same : ∀ pc ∈ positions, decode first pc = decode second pc ∧
      decode first (pc + 1) = decode second (pc + 1)) (state : State) :
    evaluate env first positions state = evaluate env second positions state := by
  induction positions generalizing state with
  | nil => rfl
  | cons pc rest ih =>
      have head := same pc (by simp)
      have suffix : ∀ next ∈ rest, decode first next = decode second next ∧
          decode first (next + 1) = decode second (next + 1) :=
        fun next inside => same next (by simp [inside])
      by_cases active : state.halted = true
      · simp [evaluate, active]
      · by_cases atPosition : state.pc = (pc : Int)
        · have continuation : decode first (state.pc.toNat + 1) = decode second (state.pc.toNat + 1) := by
            simpa [atPosition] using head.2
          have executed : ∀ i, execute env first state i = execute env second state i :=
            fun i => execute_program_congr env first second state i continuation
          simp only [evaluate]
          simp [active, atPosition, head.1, executed, ih suffix]
        · simp [evaluate, active, atPosition]

end KProgTV.BPFPath

#print axioms KProgTV.BPFPath.evaluate_sound

#print axioms KProgTV.BPFPath.evaluate_program_congr
