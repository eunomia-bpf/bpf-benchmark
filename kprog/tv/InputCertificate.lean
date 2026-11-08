import CompiledBlocks
import BPFPath
import KProgFormal.Refinement.EntryEnvironment

namespace KProgTV.InputCertificate
open KProgFormal.Reference KProgTV.BPF
open KProgFormal.Refinement

def environment (native : EntryEnvironment.Environment) : Environment where
  nativeInput := fun
    | .stackPointer => .ok native.bodyStack
    | .codeBase => .ok native.bodyCode
    | .returnAddress => .ok native.outerReturn
  immediate := fun _ _ _ => .error "unexpected external immediate"
  helperCall := fun _ _ => .error "unexpected helper"
  helper := fun _ _ _ => .error "unexpected helper"

def entry (argument : Word) (memory : Memory) : State where
  regs := fun r => if r = 1 then argument else 0
  memory := memory
  pc := 0

def positions : List Nat := [0,1,2,3,4,5,6,7,8,9,10]

def summary (native : EntryEnvironment.Environment) (argument : Word) (memory : Memory) := do
  let result ← BPFPath.evaluate (environment native) Compiled.input_block
    positions (entry argument memory)
  pure (result.state.regs 0, result.state.memory, result.state.halted, result.fault, result.events)

/-- Actual clang instructions consume the invocation values without adding a
memory access, helper, or guard. This certifies the input ABI component only;
the native entry/source ABI relation remains a separate program obligation. -/
theorem compiled_inputs (native : EntryEnvironment.Environment) (argument : Word) (memory : Memory) :
    summary native argument memory =
      .ok ((native.bodyCode + native.bodyStack) + native.outerReturn + argument, memory, true, none, []) := by
  simp [summary, positions, BPFPath.evaluate, execute, source, alu, setReg,
    environment, entry, Except.bind, Except.map, Except.pure,
    Bind.bind, Pure.pure, Except.instMonad]

theorem compiled_execution (native : EntryEnvironment.Environment) (argument : Word) (memory : Memory) :
    ∃ result : Transition State,
      Execution (BPFPath.instructionStep (environment native) Compiled.input_block)
        (entry argument memory) result.events result.state ∧
      (result.state.regs 0, result.state.memory, result.state.halted, result.fault, result.events) =
        ((native.bodyCode + native.bodyStack) + native.outerReturn + argument, memory, true, none, []) := by
  have value := compiled_inputs native argument memory
  cases evaluated : BPFPath.evaluate (environment native) Compiled.input_block
      positions (entry argument memory) with
  | error error => simp [summary, evaluated, Except.bind, Except.pure,
      Bind.bind, Pure.pure, Except.instMonad] at value
  | ok result =>
      refine ⟨result, BPFPath.evaluate_sound _ _ _ _ _ evaluated, ?_⟩
      simpa [summary, evaluated, Except.bind, Except.pure,
        Bind.bind, Pure.pure, Except.instMonad] using value

/-- Marker values and the numeric argument are observations of the SAME native
state. Explicit frame biases prevent identifying source SP/PC with body bases. -/
theorem compiled_x86_entry (native : EntryEnvironment.Environment)
    (frame : EntryEnvironment.Frame) (argumentRegister : X86.Register)
    (argument returnSlot : Word) (source : X86.State) (memory : Memory)
    (witness : EntryEnvironment.X86Entry native frame argumentRegister argument returnSlot source) :
    summary native argument memory = .ok
      (((source.pc - frame.codeBias) + (source.gpr 4 - frame.stackBias)) +
        wordAt source.memory returnSlot 8 + source.gpr argumentRegister,
        memory, true, none, []) := by
  rw [compiled_inputs, witness.code, witness.stack, witness.outerReturn, witness.argument]
  simp [EntryEnvironment.base, BitVec.add_sub_cancel]

theorem compiled_arm64_entry (native : EntryEnvironment.Environment)
    (frame : EntryEnvironment.Frame) (argumentRegister : AArch64.Gpr)
    (argument : Word) (source : AArch64.State) (memory : Memory)
    (witness : EntryEnvironment.Arm64Entry native frame argumentRegister argument source) :
    summary native argument memory = .ok
      (((source.pc - frame.codeBias) + (source.sp - frame.stackBias)) +
        source.gpr 30 + source.gpr argumentRegister,
        memory, true, none, []) := by
  rw [compiled_inputs, witness.code, witness.stack, witness.outerReturn, witness.argument]
  simp [EntryEnvironment.base, BitVec.add_sub_cancel]

/-- The choice stream is shared by the compiled input units and their caller's
kind6 model. Each dynamic visit has its own arbitrary64-bit value. -/
def choiceEnvironment (native : EntryEnvironment.Environment) (choices : Nat → Word) : Environment :=
  { environment native with unspecifiedInput := fun visit => .ok (choices visit) }

def choiceSummary (native : EntryEnvironment.Environment) (choices : Nat → Word)
    (program : Array Byte) (positions : List Nat) (s : State) := do
  let result ← BPFPath.evaluate (choiceEnvironment native choices) program positions
    { s with pc := 0, halted := false }
  pure (result.state.regs 0, result.state.memory, result.state.unspecifiedVisit,
    result.state.halted, result.fault, result.events)

theorem compiled_unspecified (native : EntryEnvironment.Environment) (choices : Nat → Word) (s : State) :
    choiceSummary native choices Compiled.input_unspecified [0,1] s =
      .ok (choices s.unspecifiedVisit, s.memory, s.unspecifiedVisit + 1, true, none, []) := by
  simp [choiceSummary, choiceEnvironment, BPFPath.evaluate, execute, source, alu, setReg,
    Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad]

theorem compiled_unspecified_pair (native : EntryEnvironment.Environment)
    (choices : Nat → Word) (s : State) :
    choiceSummary native choices Compiled.input_unspecified_pair [0,1,2,3,4] s =
      .ok (choices (s.unspecifiedVisit + 1) + choices s.unspecifiedVisit,
        s.memory, s.unspecifiedVisit + 2, true, none, []) := by
  simp [choiceSummary, choiceEnvironment, BPFPath.evaluate, execute, source, alu, setReg,
    Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad, Nat.add_assoc]

/-- Successful byte execution supplies the generic execution relation used by
all callers of either compiled kind6 unit. -/
theorem compiled_choice_execution (native : EntryEnvironment.Environment) (choices : Nat → Word)
    (program : Array Byte) (positions : List Nat) (s : State) (value : Word) (visit : Nat)
    (computed : choiceSummary native choices program positions s =
      .ok (value, s.memory, visit, true, none, [])) :
    ∃ result : Transition State,
      Execution (BPFPath.instructionStep (choiceEnvironment native choices) program)
        { s with pc := 0, halted := false } result.events result.state ∧
      (result.state.regs 0, result.state.memory, result.state.unspecifiedVisit,
        result.state.halted, result.fault, result.events) =
        (value, s.memory, visit, true, none, []) := by
  cases evaluated : BPFPath.evaluate (choiceEnvironment native choices) program positions
      { s with pc := 0, halted := false } with
  | error error => simp [choiceSummary, evaluated, Except.bind, Except.pure,
      Bind.bind, Pure.pure, Except.instMonad] at computed
  | ok result =>
      refine ⟨result, BPFPath.evaluate_sound _ _ _ _ _ evaluated, ?_⟩
      simpa [choiceSummary, evaluated, Except.bind, Except.pure,
        Bind.bind, Pure.pure, Except.instMonad] using computed


end KProgTV.InputCertificate
#print axioms KProgTV.InputCertificate.compiled_inputs
#print axioms KProgTV.InputCertificate.compiled_execution

#print axioms KProgTV.InputCertificate.compiled_x86_entry
#print axioms KProgTV.InputCertificate.compiled_arm64_entry

#print axioms KProgTV.InputCertificate.compiled_unspecified
#print axioms KProgTV.InputCertificate.compiled_unspecified_pair
#print axioms KProgTV.InputCertificate.compiled_choice_execution
