import KProgFormal.Reference.X86

/-! Finite execution witnesses for variable-length native instructions.
The witness supplies byte positions and extents, never decoded operands or
successors. Every instruction is decoded and stepped by the canonical ISA. -/
namespace KProgFormal.Reference.X86Path
open X86

structure Entry where
  offset : Nat
  length : Nat
  deriving Repr

/-- The decoder's actual fall-through, including prefixes and all operand bytes.
This projection does not choose a branch's architectural successor. -/
abbrev fallthrough := Instruction.fallthrough

def decodeAt (base : Word) (bytes : Array Byte) (entry : Entry)
    (state : State) : Except String Instruction := do
  if state.pc != base + BitVec.ofNat 64 entry.offset then
    throw "native path successor mismatch"
  if entry.length = 0 || entry.length > 15 then
    throw "native path instruction extent must be in [1,15]"
  if entry.offset + entry.length > bytes.size then
    throw "native path instruction extent outside artifact"
  let instruction ← decode (bytes.extract entry.offset (entry.offset + entry.length)) state
  if fallthrough instruction != state.pc + BitVec.ofNat 64 entry.length then
    throw "native path instruction extent differs from canonical decode"
  pure instruction

structure Result where
  effect : Transition State
  definedFlags : Word

def evaluate (base : Word) (bytes : Array Byte) :
    List Entry → State → Except String Result
  | [], state => .ok ⟨⟨state, [], none⟩, 0xffffffffffffffff⟩
  | entry :: rest, state =>
      match decodeAt base bytes entry state with
      | .error error => .error error
      | .ok instruction =>
          let first := step instruction state
          if first.fault.isSome then
            if rest.isEmpty then .ok ⟨first, 0xffffffffffffffff⟩
            else .error "native path continues after fault"
          else match evaluate base bytes rest first.state with
            | .error error => .error error
            | .ok tail => .ok ⟨{ tail.effect with events := first.events ++ tail.effect.events },
                definedFlags instruction &&& tail.definedFlags⟩

/-- This relation uses exactly the same decoded native steps; there is no
forced successor, instruction budget or successful timeout. -/
inductive Execution (base : Word) (bytes : Array Byte) :
    State → List Event → State → Prop
  | refl (state) : Execution base bytes state [] state
  | next {before after : State} {events : List Event} (entry : Entry)
      (instruction : Instruction)
      (decoded : decodeAt base bytes entry before = .ok instruction)
      (tail : Execution base bytes (step instruction before).state events after) :
      Execution base bytes before ((step instruction before).events ++ events) after

theorem evaluate_sound (base : Word) (bytes : Array Byte)
    (entries : List Entry) (state : State) (result : Result)
    (accepted : evaluate base bytes entries state = .ok result) :
    Execution base bytes state result.effect.events result.effect.state := by
  induction entries generalizing state result with
  | nil =>
      simp [evaluate] at accepted
      cases accepted
      exact Execution.refl state
  | cons entry rest ih =>
      cases decoded : decodeAt base bytes entry state with
      | error error => simp [evaluate, decoded] at accepted
      | ok instruction =>
          cases fault : (step instruction state).fault with
          | some reason =>
              cases rest with
              | nil =>
                  simp [evaluate, decoded, fault] at accepted
                  cases accepted
                  simpa using Execution.next entry instruction decoded
                    (Execution.refl (step instruction state).state)
              | cons next tail => simp [evaluate, decoded, fault] at accepted
          | none =>
              cases continued : evaluate base bytes rest (step instruction state).state with
              | error error => simp [evaluate, decoded, fault, continued] at accepted
              | ok tail =>
                  simp [evaluate, decoded, fault, continued] at accepted
                  cases accepted
                  exact Execution.next entry instruction decoded
                    (ih (step instruction state).state tail continued)

end KProgFormal.Reference.X86Path
