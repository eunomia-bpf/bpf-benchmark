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

/-- Only an actual wide immediate may observe its continuation. This avoids
requiring an ordinary block's following instruction to remain unchanged. -/
theorem evaluate_program_congr_if_wide (env : Environment) (first second : Array Byte)
    (positions : List Nat)
    (same : ∀ pc ∈ positions, ∃ i,
      decode first pc = .ok i ∧ decode second pc = .ok i ∧
      (i.code = 0x18 → decode first (pc + 1) = decode second (pc + 1)))
    (state : State) : evaluate env first positions state = evaluate env second positions state := by
  induction positions generalizing state with
  | nil => rfl
  | cons pc rest ih =>
      obtain ⟨i, firstDecode, secondDecode, high⟩ := same pc (by simp)
      have suffix : ∀ next ∈ rest, ∃ i,
          decode first next = .ok i ∧ decode second next = .ok i ∧
          (i.code = 0x18 → decode first (next + 1) = decode second (next + 1)) :=
        fun next inside => same next (by simp [inside])
      by_cases active : state.halted = true
      · simp [evaluate, active]
      · by_cases atPosition : state.pc = (pc : Int)
        · have execution := execute_program_congr_if_wide env first second state i
            (by simpa [atPosition] using high)
          simp only [evaluate]
          simp [active, atPosition, firstDecode, secondDecode, execution, ih suffix]
        · simp [evaluate, active, atPosition]

/-- Transfer a successful witness using actual pointwise target transitions.
The source checks every selected PC; the target relation must be established
for the whole state and exact ordered effects at each such step. -/
theorem evaluate_execution_transport (env : Environment) (source : Array Byte)
    (stateMap : State → State) (target : BlockStep State) (allowed : Nat → Prop)
    (stepMap : ∀ s position, allowed position → s.pc = (position : Int) →
      ∀ result, step env source s = .ok result →
      target (stateMap s) result.events (stateMap result.state))
    (positions : List Nat) (inside : ∀ position ∈ positions, allowed position)
    (state : State) (result : Transition State)
    (accepted : evaluate env source positions state = .ok result) :
    Execution target (stateMap state) result.events (stateMap result.state) := by
  induction positions generalizing state result with
  | nil =>
      simp [evaluate] at accepted
      cases accepted
      exact Execution.refl _
  | cons pc rest ih =>
    cases active : state.halted with
    | true => simp [evaluate, active] at accepted
    | false =>
      by_cases position : state.pc = (pc : Int)
      · cases decoded : decode source pc with
        | error error => simp [evaluate, active, position, decoded] at accepted
        | ok instruction =>
          cases executed : execute env source state instruction with
          | error error => simp [evaluate, active, position, decoded, executed] at accepted
          | ok first =>
            have actual : step env source state = .ok first := by
              simp [step, active, position, decoded, executed]
            have head := stepMap state pc (inside pc (by simp)) position first actual
            cases fault : first.fault with
            | some reason =>
              cases rest with
              | nil =>
                simp [evaluate, active, position, decoded, executed, fault] at accepted
                cases accepted
                simpa using Execution.next head (Execution.refl (stateMap result.state))
              | cons next tail => simp [evaluate, active, position, decoded, executed, fault] at accepted
            | none =>
              cases continued : evaluate env source rest first.state with
              | error error => simp [evaluate, active, position, decoded, executed, fault, continued] at accepted
              | ok tail =>
                simp [evaluate, active, position, decoded, executed, fault, continued] at accepted
                cases accepted
                exact Execution.next head (ih (fun pos member => inside pos (List.mem_cons_of_mem _ member))
                  first.state tail continued)
      · simp [evaluate, active, position] at accepted

/-! Consecutive kind6 reads retain memory and every register except R0.
Each visit consumes its own arbitrary word. The finite byte path is shared by
all callers and retains the actual PC and ordered-execution relation. -/
namespace InputBurst

def afterInputs (choices : Nat → Word) (s : State) : Nat → State
  | 0 => s
  | n + 1 => { s with
      regs := fun r => if r = 0 then choices (s.unspecifiedVisit + n) else s.regs r
      pc := s.pc + Int.ofNat (n + 1)
      unspecifiedVisit := s.unspecifiedVisit + n + 1 }

theorem after_one (choices : Nat → Word) (s : State) (n : Nat) :
    afterInputs choices (afterInputs choices s 1) n = afterInputs choices s (n + 1) := by
  cases n with
  | zero => rfl
  | succ n =>
      simp only [afterInputs]
      congr 1
      · funext r
        by_cases h : r = 0 <;> simp [h, Nat.add_assoc, Nat.add_comm, Nat.add_left_comm]
      · simp [Int.natCast_add, Int.add_assoc]
        omega
      · omega

@[irreducible] def inputPositions (start count : Nat) (rest : List Nat) : List Nat :=
  List.range' start count ++ rest

def marker : Instruction := ⟨0xb7, 0, 9, 6, 2⟩

theorem evaluate_burst (env : Environment) (choices : Nat → Word) (program : Array Byte)
    (start count : Nat) (rest : List Nat) (s : State)
    (inputs : ∀ visit, env.unspecifiedInput visit = .ok (choices visit))
    (active : s.halted = false) (position : s.pc = Int.ofNat start)
    (decoded : ∀ i : Fin count, decode program (start + i.val) = .ok marker) :
    BPFPath.evaluate env program (inputPositions start count rest) s =
      BPFPath.evaluate env program rest (afterInputs choices s count) := by
  unfold inputPositions
  induction count generalizing start s with
  | zero => rfl
  | succ count ih =>
      have first : decode program start = .ok marker := by
        simpa using decoded ⟨0, by omega⟩
      have later : ∀ i : Fin count, decode program (start + 1 + i.val) = .ok marker := by
        intro i
        have step := decoded ⟨i.val + 1, by have := i.isLt; omega⟩
        simpa [Nat.add_assoc, Nat.add_comm, Nat.add_left_comm] using step
      have nextActive : (afterInputs choices s 1).halted = false := active
      have nextPosition : (afterInputs choices s 1).pc = Int.ofNat (start + 1) := by
        simp [afterInputs, position, Int.natCast_add]
      simp only [List.range'_succ, List.cons_append, BPFPath.evaluate, active, position,
        bne_self_eq_false, Bool.false_eq_true, if_false, first]
      simp [execute, marker, inputs, source, alu, setReg,
        Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad]
      have evaluated := ih (start + 1) (afterInputs choices s 1) nextActive nextPosition later
      rw [after_one] at evaluated
      change (match BPFPath.evaluate env program (List.range' (start + 1) count ++ rest)
          (afterInputs choices s 1) with
        | .error error => Except.error error
        | .ok tail => Except.ok (⟨tail.state, tail.events, tail.fault⟩ : Transition State)) = _
      rw [evaluated]
      cases BPFPath.evaluate env program rest (afterInputs choices s (count + 1)) <;> rfl

end InputBurst

end KProgTV.BPFPath

#print axioms KProgTV.BPFPath.evaluate_sound

#print axioms KProgTV.BPFPath.evaluate_program_congr

#print axioms KProgTV.BPFPath.evaluate_program_congr_if_wide

#print axioms KProgTV.BPFPath.evaluate_execution_transport

#print axioms KProgTV.BPFPath.InputBurst.after_one
#print axioms KProgTV.BPFPath.InputBurst.evaluate_burst
