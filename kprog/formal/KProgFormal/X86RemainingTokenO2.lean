import KProgFormal.X86HelperDispatch
import KProgFormal.Refinement.X86Dispatcher

namespace KProgFormal.X86RemainingTokenO2

open Reference
open Refinement.X86NumericAddress
open Refinement.X86Dispatcher

abbrev Word := Reference.Word

/-! O2 for the two helper tokens and both emitted RET forms. Helper bodies
are interpreted in an arbitrary complete C state and arbitrary outcome type.
Taking the outcome type to be a predicate also covers relational semantics.
Thus substitution preserves returning effects, metadata, fresh inputs, errors
and successful transfers for every interpretation of the shared macro bodies.
Helper/native faithfulness and C/compiler correspondence are separate relations.
-/

/-- The extracted sparse helper switch, including its error-default macro. -/
def helperSwitch {State Outcome : Type} (run : String → State → Outcome)
    (id : Word) (state : State) : Outcome :=
  let body := match GeneratedX86HelperDispatch.slotOf id with
    | some slot => GeneratedX86HelperDispatch.helperBodies.getD slot
        GeneratedX86HelperDispatch.defaultBody
    | none => GeneratedX86HelperDispatch.defaultBody
  run body state

/-- Independently enumerated helper-body selection with the same complete
macro interpretation. Each original state reaches the selected body intact. -/
def helperBody {State Outcome : Type} (run : String → State → Outcome)
    (id : Word) (state : State) : Outcome :=
  run (x86HelperDispatchRoutedBodySpec id) state

theorem helper_switch_body_matches {State Outcome : Type}
    (run : String → State → Outcome) (id : Word) (state : State) :
    helperBody run id state = helperSwitch run id state := by
  simp only [helperBody, helperSwitch, x86HelperDispatchRoutedBodySpec,
    x86_helper_dispatch_slotof_refines, x86_helper_dispatch_bodies_refine]
  rfl

/-- Branch-level helper dispatch: the immediate macro and the CALL_REG arm
both invoke X86_SIM_BPF_CALL_ID; CALL_REG captures READ_REG before invocation. -/
def helperDispatch {State Outcome : Type} (run : String → State → Outcome)
    (readRegister : State → Reference.X86.Register → Word) (state : State)
    (code : Nat) (_flags : Byte) (_aux : BitVec 32) (_dst : Byte)
    (src : Reference.X86.Register) (imm : Word) : Option Outcome :=
  if code = GeneratedX86Opcode.code .callHelper then
    some (helperSwitch run imm state)
  else if code = GeneratedX86Opcode.code .callReg then
    some (helperSwitch run (readRegister state src) state)
  else none

/-- Specialized direct-macro emission retains the full-width ID expression. -/
def helperTokenBody {State Outcome : Type} (run : String → State → Outcome)
    (readRegister : State → Reference.X86.Register → Word) (state : State)
    (kind : X86HelperBody.Token) (src : Reference.X86.Register) (imm : Word) : Outcome :=
  match kind with
  | .immediate => helperBody run imm state
  | .register => helperBody run (readRegister state src) state

theorem helper_token_body_matches {State Outcome : Type}
    (run : String → State → Outcome)
    (readRegister : State → Reference.X86.Register → Word) (state : State)
    (kind : X86HelperBody.Token) (flags : Byte) (aux : BitVec 32) (dst : Byte)
    (src : Reference.X86.Register) (imm : Word) :
    some (helperTokenBody run readRegister state kind src imm) =
      helperDispatch run readRegister state (GeneratedX86Opcode.code (X86HelperBody.opcode kind))
        flags aux dst src imm := by
  cases kind <;> simp [helperTokenBody, helperDispatch, X86HelperBody.opcode,
    GeneratedX86Opcode.code, ↓reduceIte, helper_switch_body_matches]

/-- CALL_HELPER O2 holds for every ID, complete state and macro outcome. -/
theorem call_helper_body_matches {State Outcome : Type}
    (run : String → State → Outcome)
    (readRegister : State → Reference.X86.Register → Word) (state : State)
    (flags : Byte) (aux : BitVec 32) (dst : Byte)
    (src : Reference.X86.Register) (imm : Word) :
    some (helperTokenBody run readRegister state .immediate src imm) =
      helperDispatch run readRegister state (GeneratedX86Opcode.code .callHelper)
        flags aux dst src imm :=
  helper_token_body_matches run readRegister state .immediate flags aux dst src imm

/-- CALL_REG O2 retains the original full-width register read and state. -/
theorem call_reg_body_matches {State Outcome : Type}
    (run : String → State → Outcome)
    (readRegister : State → Reference.X86.Register → Word) (state : State)
    (flags : Byte) (aux : BitVec 32) (dst : Byte)
    (src : Reference.X86.Register) (imm : Word) :
    some (helperTokenBody run readRegister state .register src imm) =
      helperDispatch run readRegister state (GeneratedX86Opcode.code .callReg)
        flags aux dst src imm :=
  helper_token_body_matches run readRegister state .register flags aux dst src imm

/-- The selected error-default body is preserved for every out-of-table ID. -/
theorem helper_default_body_matches {State Outcome : Type}
    (run : String → State → Outcome) (id : Word) (state : State)
    (selected : GeneratedX86HelperDispatch.slotOf id = none) :
    helperBody run id state = run GeneratedX86HelperDispatch.defaultBody state := by
  rw [helper_switch_body_matches]
  simp only [helperSwitch, selected]

/-- RET source emission chooses the invocation exit or the internal table. -/
inductive ReturnMode where
  | invocation
  | subroutine (targets : List Word)

/-- Invocation exit retains its complete input frame and uint32 result.
Internal exit retains the captured read/RSP/frame and selected/default branch. -/
inductive ReturnOutcome where
  | invocation (value : BitVec 32) (state : X86CallMemBody.Frame)
  | subroutine (state : X86CallMemBody.Frame) (result : ReturnDispatchResult)

/-- SUB_RET advances the raw RSP coordinate and retains all register tags,
stack-coordinate predicates, flags, XMM and memory cells. -/
def subroutineFrame (env : Refinement.EntryEnvironment.Environment)
    (entry : Refinement.EntryEnvironment.Frame) (arena : Word)
    (state : X86CallMemBody.Frame) : X86CallMemBody.Frame :=
  { state with registers := registerPc (advanceStack state.registers 8) (returnStackWord env entry arena state.registers) }

theorem subroutine_frame_projection (env : Refinement.EntryEnvironment.Environment)
    (entry : Refinement.EntryEnvironment.Frame) (arena : Word)
    (state : X86CallMemBody.Frame) :
    nativeRegisters env entry arena (subroutineFrame env entry arena state).registers =
        (returnLabelFrame env entry arena state.registers).state ∧
      (subroutineFrame env entry arena state).tags = state.tags := by
  exact ⟨rfl, rfl⟩

/-- C branch-dispatch interpretation: uint32 READ_REG(RAX), or SUB_RET and
its complete finite continuation switch. The mode comes from source emission. -/
def returnDispatch (env : Refinement.EntryEnvironment.Environment)
    (entry : Refinement.EntryEnvironment.Frame) (arena : Word) (state : X86CallMemBody.Frame)
    (mode : ReturnMode) (code : Nat) : Option ReturnOutcome :=
  if code = GeneratedX86Opcode.code .ret then
    some (match mode with
      | .invocation => .invocation (registerValue env entry arena state.registers 0 |>.setWidth 32) state
      | .subroutine targets => .subroutine (subroutineFrame env entry arena state) (generatedReturnDispatch env entry arena state.registers targets))
  else none

/-- Specialized RET composes its existing token theorem with both internal
switch alternatives. Invocation emission uses the native-value RAX projection. -/
def returnTokenBody (env : Refinement.EntryEnvironment.Environment)
    (entry : Refinement.EntryEnvironment.Frame) (arena : Word) (current : Nat)
    (state : X86CallMemBody.Frame) (mode : ReturnMode)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Word) : Option ReturnOutcome :=
  match mode with
  | .invocation => some (.invocation ((nativeRegisters env entry arena state.registers).gpr 0 |>.setWidth 32) state)
  | .subroutine targets =>
      (specializedReturnDispatchToken env entry arena current state.registers targets
        flags aux dst src value nextPc).map (ReturnOutcome.subroutine (subroutineFrame env entry arena state))

/-- RET O2 covers every mode, finite table, saved word and encoded field. -/
theorem ret_body_matches (env : Refinement.EntryEnvironment.Environment)
    (entry : Refinement.EntryEnvironment.Frame) (arena : Word) (current : Nat)
    (state : X86CallMemBody.Frame) (mode : ReturnMode)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Word) :
    returnTokenBody env entry arena current state mode flags aux dst src value nextPc =
      returnDispatch env entry arena state mode (GeneratedX86Opcode.code .ret) := by
  cases mode with
  | invocation => rfl
  | subroutine targets =>
      simp only [returnTokenBody, returnDispatch, ↓reduceIte,
        return_dispatch_token_body_matches, Option.map_some]
      rfl

/-- The internal default carries the same captured effect through O2. -/
theorem ret_default_body_matches (env : Refinement.EntryEnvironment.Environment)
    (entry : Refinement.EntryEnvironment.Frame) (arena : Word) (current : Nat)
    (state : X86CallMemBody.Frame) (targets : List Word)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Word)
    (selected : targets.contains (returnStackWord env entry arena state.registers) = false) :
    returnTokenBody env entry arena current state (.subroutine targets) flags aux dst src value nextPc =
      some (.subroutine (subroutineFrame env entry arena state)
        (.unresolved (returnLabelFrame env entry arena state.registers))) := by
  simp only [returnTokenBody, return_dispatch_token_default env entry arena current
    state.registers targets flags aux dst src value nextPc selected, Option.map_some]
  rfl

/-- Generated token identities attach the three equality theorems to their
canonical specialization classes and opcode names. -/
theorem remaining_token_identity :
    GeneratedX86Specialization.dispatch .callHelper = .directMacro ∧
    GeneratedX86Specialization.dispatch .callReg = .directMacro ∧
    GeneratedX86Specialization.dispatch .ret = .branchHandler ∧
    GeneratedX86Specialization.tokenName .ret = GeneratedX86Opcode.define .ret := by
  decide

end KProgFormal.X86RemainingTokenO2

#print axioms KProgFormal.X86RemainingTokenO2.call_helper_body_matches
#print axioms KProgFormal.X86RemainingTokenO2.call_reg_body_matches
#print axioms KProgFormal.X86RemainingTokenO2.ret_body_matches
#print axioms KProgFormal.X86RemainingTokenO2.ret_default_body_matches
