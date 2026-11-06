import CompiledBlocks
import BPFPath

namespace KProgTV.InputCertificate
open KProgFormal.Reference KProgTV.BPF

def environment (sp code ret : Word) : Environment where
  nativeInput := fun
    | .stackPointer => .ok sp
    | .codeBase => .ok code
    | .returnAddress => .ok ret
  immediate := fun _ _ _ => .error "unexpected external immediate"
  helperCall := fun _ _ => .error "unexpected helper"
  helper := fun _ _ _ => .error "unexpected helper"

def entry (argument : Word) (memory : Memory) : State where
  regs := fun r => if r = 1 then argument else 0
  memory := memory
  pc := 0

def positions : List Nat := [0,1,2,3,4,5,6,7,8,9,10]

def summary (sp code ret argument : Word) (memory : Memory) := do
  let result ← BPFPath.evaluate (environment sp code ret) Compiled.input_block
    positions (entry argument memory)
  pure (result.state.regs 0, result.state.memory, result.state.halted, result.fault, result.events)

/-- Actual clang instructions consume the invocation values without adding a
memory access, helper, or guard. This certifies the input ABI component only;
the native entry/source ABI relation remains a separate program obligation. -/
theorem compiled_inputs (sp code ret argument : Word) (memory : Memory) :
    summary sp code ret argument memory =
      .ok ((code + sp) + ret + argument, memory, true, none, []) := by
  simp [summary, positions, BPFPath.evaluate, execute, source, alu, setReg,
    environment, entry, Except.bind, Except.map, Except.pure,
    Bind.bind, Pure.pure, Except.instMonad]

theorem compiled_execution (sp code ret argument : Word) (memory : Memory) :
    ∃ result : Transition State,
      Execution (BPFPath.instructionStep (environment sp code ret) Compiled.input_block)
        (entry argument memory) result.events result.state ∧
      (result.state.regs 0, result.state.memory, result.state.halted, result.fault, result.events) =
        ((code + sp) + ret + argument, memory, true, none, []) := by
  have value := compiled_inputs sp code ret argument memory
  cases evaluated : BPFPath.evaluate (environment sp code ret) Compiled.input_block
      positions (entry argument memory) with
  | error error => simp [summary, evaluated, Except.bind, Except.pure,
      Bind.bind, Pure.pure, Except.instMonad] at value
  | ok result =>
      refine ⟨result, BPFPath.evaluate_sound _ _ _ _ _ evaluated, ?_⟩
      simpa [summary, evaluated, Except.bind, Except.pure,
        Bind.bind, Pure.pure, Except.instMonad] using value

end KProgTV.InputCertificate
#print axioms KProgTV.InputCertificate.compiled_inputs
#print axioms KProgTV.InputCertificate.compiled_execution
