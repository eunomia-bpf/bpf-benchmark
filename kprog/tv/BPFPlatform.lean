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
