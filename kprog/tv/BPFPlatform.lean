import BPFPath

namespace KProgTV.BPFPlatform
open KProgFormal.Reference

/-- Kernel context conversion belongs to the bound platform, not the native
ISA. Both instruction streams and this map belong to Artifact.metadata.
Each position is checked against the actual physical BPF successor. -/
structure Expansion where
  original : BPF.Instruction
  bytes : Array Byte
  positions : BPF.State → List Nat

structure Environment where
  bpf : BPF.Environment
  /-- Ordinary accesses must be classified explicitly. Missing context
  conversion is an error, not permission to use ordinary load semantics. -/
  access : Int → BPF.Instruction → Except String (Option Expansion)

def expand (env : BPF.Environment) (expansion : Expansion) (state : BPF.State) :
    Except String (Transition BPF.State) :=
  if expansion.bytes.isEmpty || expansion.bytes.size % 8 != 0 then
    .error "invalid kernel context expansion extent"
  else
    let physical := { state with pc := 0 }
    match BPFPath.evaluate env expansion.bytes (expansion.positions physical) physical with
    | .error error => .error error
    | .ok result =>
      if result.state.halted then .error "kernel context expansion returned from program"
      else if result.fault.isNone && result.state.pc != (expansion.bytes.size / 8 : Nat) then
        .error "kernel context expansion stopped before its boundary"
      else .ok { result with state := { result.state with
        pc := if result.fault.isSome then state.pc else state.pc + 1 } }

def step (env : Environment) (program : Array Byte) (state : BPF.State) :
    Except String (Transition BPF.State) := do
  if state.halted then throw "BPF execution already returned"
  if state.pc < 0 then throw "BPF PC before artifact"
  let instruction ← BPF.decode program state.pc.toNat
  match ← env.access state.pc instruction with
  | none => BPF.execute env.bpf program state instruction
  | some expansion =>
      if expansion.original != instruction then
        throw "kernel context expansion does not match original instruction"
      if instruction.code % 8 ∉ [1, 2, 3] then
        throw "kernel context expansion replaces a nonmemory instruction"
      expand env.bpf expansion state

/-- Every accepted expansion is an actual execution of the captured physical
BPF bytes, preserving all registers, memory, faults and ordered effects.
Only its local instruction positions are projected back to the virtual PC. -/
theorem expand_sound (env : BPF.Environment) (expansion : Expansion)
    (state : BPF.State) (result : Transition BPF.State)
    (accepted : expand env expansion state = .ok result) :
    ∃ physical : Transition BPF.State,
      Execution (BPFPath.instructionStep env expansion.bytes)
        { state with pc := 0 } physical.events physical.state ∧
      physical.state.halted = false ∧
      (physical.fault.isSome = true ∨ physical.state.pc = (expansion.bytes.size / 8 : Nat)) ∧
      result = { physical with state := { physical.state with
        pc := if physical.fault.isSome then state.pc else state.pc + 1 } } := by
  unfold expand at accepted
  split at accepted
  · simp at accepted
  · cases evaluated : BPFPath.evaluate env expansion.bytes
        (expansion.positions { state with pc := 0 }) { state with pc := 0 } with
    | error error => simp [evaluated] at accepted
    | ok physical =>
        simp only [evaluated] at accepted
        split at accepted
        · simp at accepted
        · split at accepted
          · simp at accepted
          · simp only [Except.ok.injEq] at accepted
            exact ⟨physical, BPFPath.evaluate_sound _ _ _ _ _ evaluated,
              by simp_all, by cases h : physical.fault <;> simp_all, accepted.symm⟩

/-- The platform classifier depends on the decoded instruction and actual PC,
not bytes elsewhere in the artifact. Wide-immediate payloads remain explicit. -/
theorem step_program_congr_if_wide (env : Environment) (first second : Array Byte)
    (s : BPF.State) (i : BPF.Instruction)
    (left : BPF.decode first s.pc.toNat = .ok i)
    (right : BPF.decode second s.pc.toNat = .ok i)
    (wide : i.code = 0x18 → BPF.decode first (s.pc.toNat+1) = BPF.decode second (s.pc.toNat+1)) :
    step env first s = step env second s := by
  have executed := BPF.execute_program_congr_if_wide env.bpf first second s i wide
  cases active : s.halted <;> by_cases negative : s.pc < 0 <;>
    simp [step, active, negative, left, right, executed,
      Except.bind, Except.pure, Bind.bind, Pure.pure, Except.instMonad]

/-- Corresponding plain physical steps, with the same wide-payload condition. -/
theorem physical_step_program_congr_if_wide (env : BPF.Environment) (first second : Array Byte)
    (s : BPF.State) (i : BPF.Instruction)
    (left : BPF.decode first s.pc.toNat = .ok i)
    (right : BPF.decode second s.pc.toNat = .ok i)
    (wide : i.code = 0x18 → BPF.decode first (s.pc.toNat+1) = BPF.decode second (s.pc.toNat+1)) :
    BPF.step env first s = BPF.step env second s := by
  have executed := BPF.execute_program_congr_if_wide env first second s i wide
  cases active : s.halted <;> by_cases negative : s.pc < 0 <;>
    simp [BPF.step, active, negative, left, right, executed,
      Except.bind, Except.pure, Bind.bind, Pure.pure, Except.instMonad]

end KProgTV.BPFPlatform

#print axioms KProgTV.BPFPlatform.expand_sound

#print axioms KProgTV.BPFPlatform.step_program_congr_if_wide
#print axioms KProgTV.BPFPlatform.physical_step_program_congr_if_wide

namespace KProgTV.BPFPlatform
open KProgFormal.Reference

/-- The actual BPF CALL captures all arguments from the pre-call state,
uses the resolved full-width identity, then applies memory/result/clobbers.
This is the returning path; successful tail transfer is a separate relation. -/
theorem returning_helper_execute
    (environment : BPF.Environment) (program : Array Byte) (state : BPF.State)
    (instruction : BPF.Instruction) (call : BPF.HelperCall) (effect : BPF.HelperResult)
    (opcode : instruction.code = 0x85) (source : instruction.src = 0 ∨ instruction.src = 2)
    (resolved : environment.helperCall instruction state = .ok call)
    (returned : environment.helper call (BPF.helperArguments call state) state.memory = .ok effect) :
    BPF.execute environment program state instruction = .ok
      ⟨{ state with
          pc := state.pc + 1
          memory := effect.memory
          regs := fun register : BPF.Register =>
            if register.val = 0 then effect.result
            else if h : register.val - 1 < 5 then effect.clobbers ⟨register.val - 1, h⟩
            else state.regs register },
        effect.events ++ [.helper call.identity (BPF.helperArguments call state) effect.result], none⟩ := by
  rcases source with source | source <;>
    simp [BPF.execute, opcode, source, resolved, returned,
      Except.bind, Except.pure, Except.map, Bind.bind, Pure.pure, Except.instMonad]

/-- Relocation changes instruction fields and its resolver, but retaining the
same helper identity/argument count preserves the whole returning step.
No bytes outside either call instruction affect this execution. -/
theorem returning_helper_resolution_preserves
    (left right : BPF.Environment) (first second : Array Byte) (state : BPF.State)
    (before after : BPF.Instruction) (call : BPF.HelperCall) (effect : BPF.HelperResult)
    (firstOpcode : before.code = 0x85) (secondOpcode : after.code = 0x85)
    (firstSource : before.src = 0 ∨ before.src = 2)
    (secondSource : after.src = 0 ∨ after.src = 2)
    (firstResolved : left.helperCall before state = .ok call)
    (secondResolved : right.helperCall after state = .ok call)
    (firstEffect : left.helper call (BPF.helperArguments call state) state.memory = .ok effect)
    (secondEffect : right.helper call (BPF.helperArguments call state) state.memory = .ok effect) :
    BPF.execute left first state before = BPF.execute right second state after := by
  rw [returning_helper_execute left first state before call effect firstOpcode firstSource firstResolved firstEffect,
    returning_helper_execute right second state after call effect secondOpcode secondSource secondResolved secondEffect]

/-- A decoded call at any final-program PC is a real one-step execution,
with the original argument snapshot and exact ordered helper effects. -/
theorem returning_helper_execution
    (environment : BPF.Environment) (program : Array Byte) (state : BPF.State)
    (instruction : BPF.Instruction) (call : BPF.HelperCall) (effect : BPF.HelperResult)
    (active : state.halted = false) (position : 0 ≤ state.pc)
    (decoded : BPF.decode program state.pc.toNat = .ok instruction)
    (opcode : instruction.code = 0x85) (source : instruction.src = 0 ∨ instruction.src = 2)
    (resolved : environment.helperCall instruction state = .ok call)
    (returned : environment.helper call (BPF.helperArguments call state) state.memory = .ok effect) :
    Execution (BPFPath.instructionStep environment program) state
      (effect.events ++ [.helper call.identity (BPF.helperArguments call state) effect.result])
      { state with
        pc := state.pc + 1
        memory := effect.memory
        regs := fun register : BPF.Register =>
          if register.val = 0 then effect.result
          else if h : register.val - 1 < 5 then effect.clobbers ⟨register.val - 1, h⟩
          else state.regs register } := by
  have actual := returning_helper_execute environment program state instruction call effect
    opcode source resolved returned
  have stepped : BPF.step environment program state = .ok
      ⟨{ state with
          pc := state.pc + 1
          memory := effect.memory
          regs := fun register : BPF.Register =>
            if register.val = 0 then effect.result
            else if h : register.val - 1 < 5 then effect.clobbers ⟨register.val - 1, h⟩
            else state.regs register },
        effect.events ++ [.helper call.identity (BPF.helperArguments call state) effect.result], none⟩ := by
    simp [BPF.step, active, Int.not_lt.mpr position, decoded, actual]
  have head : BPFPath.instructionStep environment program state
      (effect.events ++ [.helper call.identity (BPF.helperArguments call state) effect.result])
      { state with
        pc := state.pc + 1
        memory := effect.memory
        regs := fun register : BPF.Register =>
          if register.val = 0 then effect.result
          else if h : register.val - 1 < 5 then effect.clobbers ⟨register.val - 1, h⟩
          else state.regs register } := ⟨_, stepped, rfl, rfl⟩
  simpa only [List.append_nil] using Execution.next head (Execution.refl _)

/-- Every captured argument is exactly its pre-call R1..R5 value, including
calls whose returned caller-clobber words differ from all input arguments. -/
theorem returning_helper_argument (call : BPF.HelperCall) (state : BPF.State)
    (index : Fin call.argumentCount.val) :
    (BPF.helperArguments call state)[index.val]? =
      some (state.regs ⟨index.val + 1, by
        have := index.isLt
        have := call.argumentCount.isLt
        omega⟩) := by
  apply List.getElem?_eq_some_iff.mpr
  refine ⟨by simp [BPF.helperArguments], ?_⟩
  simp [BPF.helperArguments]

/-- Whole returned state: R0 is the actual result, R1..R5 are independent
platform clobbers, and R6..R10/ghost indices/halted state retain their inputs.
Only the supplied helper memory/effects and the next PC change. -/
theorem returning_helper_frame
    (environment : BPF.Environment) (program : Array Byte) (state : BPF.State)
    (instruction : BPF.Instruction) (call : BPF.HelperCall) (effect : BPF.HelperResult)
    (opcode : instruction.code = 0x85) (source : instruction.src = 0 ∨ instruction.src = 2)
    (resolved : environment.helperCall instruction state = .ok call)
    (returned : environment.helper call (BPF.helperArguments call state) state.memory = .ok effect)
    (actual : Transition BPF.State)
    (observed : BPF.execute environment program state instruction = .ok actual) :
    actual.state.regs 0 = effect.result ∧ actual.state.memory = effect.memory ∧
    actual.state.pc = state.pc + 1 ∧ actual.state.halted = state.halted ∧
    actual.state.unspecifiedVisit = state.unspecifiedVisit ∧
    actual.state.exclusiveVisit = state.exclusiveVisit ∧
    actual.events = effect.events ++ [.helper call.identity (BPF.helperArguments call state) effect.result] ∧
    actual.fault = none ∧
    (∀ register : BPF.Register, 6 ≤ register.val → actual.state.regs register = state.regs register) ∧
    (∀ index : Fin 5, actual.state.regs ⟨index.val + 1, by have := index.isLt; omega⟩ = effect.clobbers index) := by
  have equal := (returning_helper_execute environment program state instruction call effect
    opcode source resolved returned).symm.trans observed
  cases Except.ok.inj equal
  refine ⟨by simp, rfl, rfl, rfl, rfl, rfl, rfl, rfl, ?_, ?_⟩
  · intro register callee
    have notResult : register.val ≠ 0 := by omega
    have notCaller : ¬register.val - 1 < 5 := by omega
    simp [notResult, notCaller]
  · intro index
    have notResult : index.val + 1 ≠ 0 := by omega
    have caller : index.val + 1 - 1 < 5 := by have := index.isLt; omega
    simp [notResult, caller]

end KProgTV.BPFPlatform
#print axioms KProgTV.BPFPlatform.returning_helper_execute
#print axioms KProgTV.BPFPlatform.returning_helper_resolution_preserves
#print axioms KProgTV.BPFPlatform.returning_helper_execution

#print axioms KProgTV.BPFPlatform.returning_helper_argument
#print axioms KProgTV.BPFPlatform.returning_helper_frame
