import KProgFormal.ControlABI
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
    (entry : Refinement.EntryEnvironment.Frame) (arena : Word) (fresh : Nat → Bool) (current : Nat)
    (state : X86CallMemBody.Frame) (mode : ReturnMode)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Word) : Option ReturnOutcome :=
  match mode with
  | .invocation => some (.invocation ((nativeRegisters env entry arena state.registers).gpr 0 |>.setWidth 32) state)
  | .subroutine targets =>
      (specializedReturnDispatchToken env entry arena fresh current state.registers targets
        flags aux dst src value nextPc).map (ReturnOutcome.subroutine (subroutineFrame env entry arena state))

/-- RET O2 covers every mode, finite table, saved word and encoded field. -/
theorem ret_body_matches (env : Refinement.EntryEnvironment.Environment)
    (entry : Refinement.EntryEnvironment.Frame) (arena : Word) (fresh : Nat → Bool) (current : Nat)
    (state : X86CallMemBody.Frame) (mode : ReturnMode)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Word) :
    returnTokenBody env entry arena fresh current state mode flags aux dst src value nextPc =
      returnDispatch env entry arena state mode (GeneratedX86Opcode.code .ret) := by
  cases mode with
  | invocation => rfl
  | subroutine targets =>
      simp only [returnTokenBody, returnDispatch, ↓reduceIte,
        return_dispatch_token_body_matches, Option.map_some]
      rfl

/-- The internal default carries the same captured effect through O2. -/
theorem ret_default_body_matches (env : Refinement.EntryEnvironment.Environment)
    (entry : Refinement.EntryEnvironment.Frame) (arena : Word) (fresh : Nat → Bool) (current : Nat)
    (state : X86CallMemBody.Frame) (targets : List Word)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Word)
    (selected : targets.contains (returnStackWord env entry arena state.registers) = false) :
    returnTokenBody env entry arena fresh current state (.subroutine targets) flags aux dst src value nextPc =
      some (.subroutine (subroutineFrame env entry arena state)
        (.unresolved (returnLabelFrame env entry arena state.registers))) := by
  simp only [returnTokenBody, return_dispatch_token_default env entry arena fresh current
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

/-- The current outer exit uses the existing callee/SP fault arm; internal
returns retain their saved-word/continuation outcome and complete frame. -/
inductive ContractReturnOutcome where
  | fault (state : X86CallMemBody.Frame)
  | normal (result : ReturnOutcome)

def guardReturn (snapshot : Reference.X86.Register → Word)
    (tags : Reference.X86.Register → Byte) (result : Option ReturnOutcome) :
    Option ContractReturnOutcome :=
  match result with
  | none => none
  | some outcome =>
      match outcome with
      | .invocation _ state =>
          if ControlABI.InvocationExit.x86Reject snapshot state.registers.raw.gpr tags
              (state.registers.raw.gpr 4) then some (.fault state) else some (.normal outcome)
      | .subroutine _ _ => some (.normal outcome)

def returnContractDispatch (env : Refinement.EntryEnvironment.Environment)
    (entry : Refinement.EntryEnvironment.Frame) (arena : Word)
    (snapshot : Reference.X86.Register → Word) (tags : Reference.X86.Register → Byte)
    (state : X86CallMemBody.Frame) (mode : ReturnMode) (code : Nat) : Option ContractReturnOutcome :=
  guardReturn snapshot tags (returnDispatch env entry arena state mode code)

def returnContractTokenBody (env : Refinement.EntryEnvironment.Environment)
    (entry : Refinement.EntryEnvironment.Frame) (arena : Word) (fresh : Nat → Bool) (current : Nat)
    (snapshot : Reference.X86.Register → Word) (tags : Reference.X86.Register → Byte)
    (state : X86CallMemBody.Frame) (mode : ReturnMode)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Word) :
    Option ContractReturnOutcome :=
  guardReturn snapshot tags (returnTokenBody env entry arena fresh current state mode
    flags aux dst src value nextPc)

theorem ret_contract_body_matches (env : Refinement.EntryEnvironment.Environment)
    (entry : Refinement.EntryEnvironment.Frame) (arena : Word) (fresh : Nat → Bool) (current : Nat)
    (snapshot : Reference.X86.Register → Word) (tags : Reference.X86.Register → Byte)
    (state : X86CallMemBody.Frame) (mode : ReturnMode)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Word) :
    returnContractTokenBody env entry arena fresh current snapshot tags state mode flags aux dst src value nextPc =
      returnContractDispatch env entry arena snapshot tags state mode (GeneratedX86Opcode.code .ret) := by
  unfold returnContractTokenBody returnContractDispatch
  rw [ret_body_matches]

/-- Every original tag/raw cell and every possible entered callee value is
quantified; the source condition precisely decides the uint32 result/fault. -/
theorem ret_invocation_contract (env : Refinement.EntryEnvironment.Environment)
    (entry : Refinement.EntryEnvironment.Frame) (arena : Word) (fresh : Nat → Bool) (current : Nat)
    (snapshot : Reference.X86.Register → Word) (tags : Reference.X86.Register → Byte)
    (state : X86CallMemBody.Frame) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Word) :
    returnContractTokenBody env entry arena fresh current snapshot tags state .invocation
        flags aux dst src value nextPc =
      if ControlABI.InvocationExit.x86Contract snapshot state.registers.raw.gpr tags
          (state.registers.raw.gpr 4) then
        some (.normal (.invocation ((nativeRegisters env entry arena state.registers).gpr 0 |>.setWidth 32) state))
      else some (.fault state) := by
  classical
  by_cases accepted : ControlABI.InvocationExit.x86Reject snapshot state.registers.raw.gpr tags
      (state.registers.raw.gpr 4) = false
  · have contract := (ControlABI.InvocationExit.x86_accepted_iff _ _ _ _).mp accepted
    simp only [returnContractTokenBody, returnTokenBody, guardReturn, accepted,
      Bool.false_eq_true, ↓reduceIte, contract]
  · have rejected : ControlABI.InvocationExit.x86Reject snapshot state.registers.raw.gpr tags
        (state.registers.raw.gpr 4) = true := by
      cases h : ControlABI.InvocationExit.x86Reject snapshot state.registers.raw.gpr tags
        (state.registers.raw.gpr 4) <;> simp_all
    have contract := mt (ControlABI.InvocationExit.x86_accepted_iff _ _ _ _).mpr accepted
    simp only [returnContractTokenBody, returnTokenBody, guardReturn, rejected, ↓reduceIte, contract]

theorem ret_subroutine_guard_preserves (env : Refinement.EntryEnvironment.Environment)
    (entry : Refinement.EntryEnvironment.Frame) (arena : Word) (fresh : Nat → Bool) (current : Nat)
    (snapshot : Reference.X86.Register → Word) (tags : Reference.X86.Register → Byte)
    (state : X86CallMemBody.Frame) (targets : List Word) (flags : Byte) (aux : BitVec 32)
    (dst src : Byte) (value nextPc : Word) :
    returnContractTokenBody env entry arena fresh current snapshot tags state (.subroutine targets)
        flags aux dst src value nextPc =
      some (.normal (.subroutine (subroutineFrame env entry arena state)
        (generatedReturnDispatch env entry arena state.registers targets))) := by
  rw [ret_contract_body_matches]
  rfl


namespace StackRelease

/-- Source stack-word representatives retain their payload bits when their
validity and provenance tags are released. -/
structure Cell where
  pointer : Word
  tag : Reference.Byte
  scalar : Word
  valid : Reference.Byte

def clear (cell : Cell) : Cell := { cell with tag := 0, valid := 0 }

theorem clear_idempotent (cell : Cell) : clear (clear cell) = clear cell := rfl

/-- Ordered source assignments, also covering scalarized sparse word lists. -/
def visit {Cell : Type} (selected : Nat → Bool) (change : Nat → Cell → Cell) :
    List Nat → (Nat → Cell) → Nat → Cell
  | [], cells => cells
  | i :: rest, cells => visit selected change rest
      (fun j => if j = i ∧ selected i = true then change i (cells i) else cells j)

theorem visit_cell {Cell : Type} (selected : Nat → Bool) (change : Nat → Cell → Cell)
    (idempotent : ∀ i x, change i (change i x) = change i x)
    (indices : List Nat) (cells : Nat → Cell) (i : Nat) :
    visit selected change indices cells i =
      if i ∈ indices ∧ selected i = true then change i (cells i) else cells i := by
  induction indices generalizing cells with
  | nil => simp [visit]
  | cons head rest ih =>
      rw [visit, ih]
      by_cases eq : i = head
      · subst head
        by_cases choose : selected i = true <;>
          by_cases member : i ∈ rest <;> simp [choose, member, idempotent]
      · by_cases choose : selected i = true <;>
          by_cases member : i ∈ rest <;> simp [eq, choose, member]

/-- Reference.Byte coordinates are signed offsets from the top of the source stack. -/
def offset (size index : Nat) : Int := (index : Int) - (size : Int)

def inReleased (size : Nat) (oldSp newSp : Int) (i : Nat) : Bool :=
  decide (oldSp ≤ offset size i ∧ offset size i < newSp)

structure Image where
  bytes : Nat → Reference.Byte
  cells : Nat → Cell

/-- STACK_RELEASE first replaces bytes in [oldSP,newSP), then invalidates
all declared source word representatives whose first byte is below newSP. -/
def body (size : Nat) (words : List Nat) (oldSp newSp : Int)
    (fresh : Nat → Reference.Byte) (image : Image) : Image :=
  if newSp > oldSp then
    { bytes := visit (inReleased size oldSp newSp) (fun i _ => fresh i)
        (List.range size) image.bytes
      cells := visit (fun i => decide (offset size (i * 8) < newSp))
        (fun _ => clear) words image.cells }
  else image

/-- Independent pointwise statement of the existing byte lifetime and
scalar/pointer validity effects, including arbitrary sparse declarations. -/
def spec (size : Nat) (words : List Nat) (oldSp newSp : Int)
    (fresh : Nat → Reference.Byte) (image : Image) : Image :=
  { bytes := fun i =>
      if newSp > oldSp ∧ i < size ∧ oldSp ≤ offset size i ∧ offset size i < newSp
      then fresh i else image.bytes i
    cells := fun i =>
      if newSp > oldSp ∧ i ∈ words ∧ offset size (i * 8) < newSp
      then clear (image.cells i) else image.cells i }

theorem body_matches (size : Nat) (words : List Nat) (oldSp newSp : Int)
    (fresh : Nat → Reference.Byte) (image : Image) :
    body size words oldSp newSp fresh image = spec size words oldSp newSp fresh image := by
  unfold body spec
  split <;> rename_i growing
  · congr 1
    · funext i
      rw [visit_cell _ _ (by intros; rfl)]
      simp [growing, inReleased, List.mem_range, and_assoc]
    · funext i
      rw [visit_cell _ _ (by intros; rfl)]
      simp [growing]
  · cases image
    congr 1 <;> funext i <;> simp [growing]

theorem released_byte (size : Nat) (words : List Nat) (oldSp newSp : Int)
    (fresh : Nat → Reference.Byte) (image : Image) (i : Nat)
    (growing : oldSp < newSp) (inside : i < size)
    (lower : oldSp ≤ offset size i) (upper : offset size i < newSp) :
    (body size words oldSp newSp fresh image).bytes i = fresh i := by
  rw [body_matches]
  simp [spec, growing, inside, lower, upper]

theorem retained_byte (size : Nat) (words : List Nat) (oldSp newSp : Int)
    (fresh : Nat → Reference.Byte) (image : Image) (i : Nat)
    (retained : ¬ (oldSp < newSp ∧ i < size ∧ oldSp ≤ offset size i ∧ offset size i < newSp)) :
    (body size words oldSp newSp fresh image).bytes i = image.bytes i := by
  rw [body_matches]
  simp [spec, retained]

theorem released_cell (size : Nat) (words : List Nat) (oldSp newSp : Int)
    (fresh : Nat → Reference.Byte) (image : Image) (i : Nat)
    (growing : oldSp < newSp) (declared : i ∈ words)
    (below : offset size (i * 8) < newSp) :
    (body size words oldSp newSp fresh image).cells i = clear (image.cells i) := by
  rw [body_matches]
  simp [spec, growing, declared, below]

theorem payload_preserved (size : Nat) (words : List Nat) (oldSp newSp : Int)
    (fresh : Nat → Reference.Byte) (image : Image) (i : Nat) :
    ((body size words oldSp newSp fresh image).cells i).pointer = (image.cells i).pointer ∧
      ((body size words oldSp newSp fresh image).cells i).scalar = (image.cells i).scalar := by
  rw [body_matches]
  simp only [spec]
  split <;> exact ⟨rfl, rfl⟩


theorem released_word_invalid (size : Nat) (words : List Nat) (oldSp newSp : Int)
    (fresh : Nat → Reference.Byte) (image : Image) (i : Nat)
    (growing : oldSp < newSp) (declared : i ∈ words)
    (below : offset size (i * 8) < newSp) :
    ((body size words oldSp newSp fresh image).cells i).tag = 0 ∧
      ((body size words oldSp newSp fresh image).cells i).valid = 0 := by
  rw [released_cell size words oldSp newSp fresh image i growing declared below]
  exact ⟨rfl, rfl⟩

theorem live_cell_preserved (size : Nat) (words : List Nat) (oldSp newSp : Int)
    (fresh : Nat → Reference.Byte) (image : Image) (i : Nat)
    (live : newSp ≤ offset size (i * 8)) :
    (body size words oldSp newSp fresh image).cells i = image.cells i := by
  rw [body_matches]
  simp [spec, Int.not_lt.mpr live]

/-- A fresh stream affects exactly the released byte interval; its complement
and every pointer/scalar representative have identical results. -/
theorem fresh_locality (size : Nat) (words : List Nat) (oldSp newSp : Int)
    (fresh other : Nat → Reference.Byte) (image : Image)
    (agree : ∀ i, i < size → oldSp ≤ offset size i → offset size i < newSp → fresh i = other i) :
    body size words oldSp newSp fresh image = body size words oldSp newSp other image := by
  rw [body_matches, body_matches]
  unfold spec
  congr 1
  funext i
  split <;> rename_i selected
  · exact agree i selected.2.1 selected.2.2.1 selected.2.2.2
  · rfl

/-- SUB_RET captures its source read before advancing the wrapping raw RSP
and releasing the associated signed stack interval. The owned-read primitive
and its raw/native memory projection remain explicit source interfaces. -/
structure ReturnImage where
  frame : X86CallMemBody.Frame
  stack : Image

structure CapturedReturn where
  target : Word
  state : ReturnImage

def subReturn (size : Nat) (words : List Nat) (read : ReturnImage → Word)
    (fresh : Nat → Reference.Byte) (state : ReturnImage) : CapturedReturn :=
  let target := read state
  let oldSp := state.frame.registers.raw.gpr 4
  let newSp := oldSp + 8
  { target := target
    state :=
      { frame := { state.frame with registers := registerPc (advanceStack state.frame.registers 8) target }
        stack := body size words (newSp.toInt - 8) newSp.toInt fresh state.stack } }

def subReturnSpec (size : Nat) (words : List Nat) (read : ReturnImage → Word)
    (fresh : Nat → Reference.Byte) (state : ReturnImage) : CapturedReturn :=
  { target := read state
    state :=
      { frame := { state.frame with registers := registerPc (advanceStack state.frame.registers 8) (read state) }
        stack := spec size words ((state.frame.registers.raw.gpr 4 + 8).toInt - 8)
          (state.frame.registers.raw.gpr 4 + 8).toInt fresh state.stack } }

theorem sub_return_matches (size : Nat) (words : List Nat) (read : ReturnImage → Word)
    (fresh : Nat → Reference.Byte) (state : ReturnImage) :
    subReturn size words read fresh state = subReturnSpec size words read fresh state := by
  simp only [subReturn, subReturnSpec, body_matches]

theorem saved_word_captured (size : Nat) (words : List Nat) (read : ReturnImage → Word)
    (fresh : Nat → Reference.Byte) (state : ReturnImage) :
    (subReturn size words read fresh state).target = read state ∧
      (subReturn size words read fresh state).state.frame.registers.raw.pc = read state := by
  exact ⟨rfl, rfl⟩

theorem sub_return_frame_projection (size : Nat) (words : List Nat)
    (env : Refinement.EntryEnvironment.Environment) (entry : Refinement.EntryEnvironment.Frame)
    (arena : Word) (read : ReturnImage → Word) (fresh : Nat → Reference.Byte) (state : ReturnImage)
    (readProjection : read state = returnStackWord env entry arena state.frame.registers) :
    (subReturn size words read fresh state).state.frame = subroutineFrame env entry arena state.frame := by
  simp only [subReturn, subroutineFrame, readProjection]



/-- The source release changes its stack image and word ghosts while the
historical native-memory projection retains its bytes and register tags. -/
theorem sub_return_frame_retained (size : Nat) (words : List Nat) (read : ReturnImage → Word)
    (fresh : Nat → Reference.Byte) (state : ReturnImage) :
    let result := (subReturn size words read fresh state).state.frame
    result.registers.raw.gpr 4 = state.frame.registers.raw.gpr 4 + 8 ∧
      result.tags = state.frame.tags ∧
      result.registers.stack = state.frame.registers.stack ∧
      result.registers.raw.memory = state.frame.registers.raw.memory ∧
      result.registers.raw.rflags = state.frame.registers.raw.rflags ∧
      result.registers.raw.xmm0 = state.frame.registers.raw.xmm0 := by
  exact ⟨rfl, rfl, rfl, rfl, rfl, rfl⟩

/-- Every byte at or above the new signed SP retains its original image. -/
theorem sub_return_live_bytes (size : Nat) (words : List Nat) (read : ReturnImage → Word)
    (fresh : Nat → Reference.Byte) (state : ReturnImage) (i : Nat)
    (live : (state.frame.registers.raw.gpr 4 + 8).toInt ≤ offset size i) :
    (subReturn size words read fresh state).state.stack.bytes i = state.stack.bytes i := by
  apply retained_byte
  omega

/-- The source-owned image carries its allocation metadata alongside the
historical native register/memory projection. Read ownership and physical
memory representation are explicit relations between these components. -/
def attach (stack : Image) : Option ReturnOutcome → Option (ReturnOutcome × Image)
  | none => none
  | some outcome => some (outcome, stack)

def tokenBody (size : Nat) (words : List Nat) (releaseFresh : Nat → Reference.Byte)
    (env : Refinement.EntryEnvironment.Environment) (entry : Refinement.EntryEnvironment.Frame)
    (arena : Word) (fresh : Nat → Bool) (current : Nat) (state : ReturnImage)
    (mode : ReturnMode) (flags : Reference.Byte) (aux : BitVec 32) (dst src : Reference.Byte) (value nextPc : Word) :
    Option (ReturnOutcome × Image) :=
  let stack := match mode with
    | .invocation => state.stack
    | .subroutine _ => (subReturn size words
        (fun s => returnStackWord env entry arena s.frame.registers) releaseFresh state).state.stack
  attach stack (returnTokenBody env entry arena fresh current state.frame mode flags aux dst src value nextPc)

def dispatch (size : Nat) (words : List Nat) (releaseFresh : Nat → Reference.Byte)
    (env : Refinement.EntryEnvironment.Environment) (entry : Refinement.EntryEnvironment.Frame)
    (arena : Word) (state : ReturnImage) (mode : ReturnMode) : Option (ReturnOutcome × Image) :=
  let stack := match mode with
    | .invocation => state.stack
    | .subroutine _ => spec size words ((state.frame.registers.raw.gpr 4 + 8).toInt - 8)
        (state.frame.registers.raw.gpr 4 + 8).toInt releaseFresh state.stack
  attach stack (returnDispatch env entry arena state.frame mode (GeneratedX86Opcode.code .ret))

theorem token_body_matches (size : Nat) (words : List Nat) (releaseFresh : Nat → Reference.Byte)
    (env : Refinement.EntryEnvironment.Environment) (entry : Refinement.EntryEnvironment.Frame)
    (arena : Word) (fresh : Nat → Bool) (current : Nat) (state : ReturnImage)
    (mode : ReturnMode) (flags : Reference.Byte) (aux : BitVec 32) (dst src : Reference.Byte) (value nextPc : Word) :
    tokenBody size words releaseFresh env entry arena fresh current state mode flags aux dst src value nextPc =
      dispatch size words releaseFresh env entry arena state mode := by
  simp only [tokenBody, dispatch, ret_body_matches]
  cases mode with
  | invocation => rfl
  | subroutine targets => simp only [subReturn, body_matches]

/-- Every continuation, including the unresolved-target edge, carries the
same released byte image and word validity/provenance result. -/
theorem token_default (size : Nat) (words : List Nat) (releaseFresh : Nat → Reference.Byte)
    (env : Refinement.EntryEnvironment.Environment) (entry : Refinement.EntryEnvironment.Frame)
    (arena : Word) (fresh : Nat → Bool) (current : Nat) (state : ReturnImage)
    (targets : List Word) (flags : Reference.Byte) (aux : BitVec 32) (dst src : Reference.Byte) (value nextPc : Word)
    (unmatched : targets.contains (returnStackWord env entry arena state.frame.registers) = false) :
    tokenBody size words releaseFresh env entry arena fresh current state (.subroutine targets)
        flags aux dst src value nextPc =
      some ((.subroutine (subroutineFrame env entry arena state.frame)
        (.unresolved (returnLabelFrame env entry arena state.frame.registers))),
        spec size words ((state.frame.registers.raw.gpr 4 + 8).toInt - 8)
          (state.frame.registers.raw.gpr 4 + 8).toInt releaseFresh state.stack) := by
  rw [token_body_matches]
  simp only [dispatch, returnDispatch, ↓reduceIte, attach,
    return_dispatch_default env entry arena state.frame.registers targets unmatched]


/-- The scalarized SC_READ loop visits each declared word and forwards the
saved scalar payload exactly when its valid byte is nonzero. -/
def forward (index : Nat) (cells : Nat → Cell) : List Nat → Word → Word
  | [], raw => raw
  | i :: rest, raw => forward index cells rest
      (if index = i * 8 ∧ (cells i).valid ≠ 0#8 then (cells i).scalar else raw)

theorem forward_matches (index : Nat) (cells : Nat → Cell) (words : List Nat)
    (raw : Word) (aligned : index % 8 = 0) :
    forward index cells words raw =
      if index / 8 ∈ words ∧ (cells (index / 8)).valid ≠ 0#8
      then (cells (index / 8)).scalar else raw := by
  induction words generalizing raw with
  | nil => simp [forward]
  | cons head rest ih =>
      rw [forward, ih]
      have same : index = head * 8 ↔ index / 8 = head := by omega
      by_cases selected : index / 8 = head
      · subst head
        by_cases valid : (cells (index / 8)).valid = 0#8 <;>
          by_cases member : index / 8 ∈ rest <;> simp [same, valid, member]
      · by_cases valid : (cells (index / 8)).valid = 0#8 <;>
          by_cases member : index / 8 ∈ rest <;> simp [same, selected, valid, member]

/-- The owned 64-bit path distinguishes aligned union-word reads with
optional scalar forwarding from the ordered eight-byte unaligned path.
The aligned union primitive is interpreted by its little-endian byte image. -/
def ownedRead (size : Nat) (words : List Nat) (sp : Int) (index : Nat) (image : Image) : Word :=
  let raw := GeneratedX86MemAccess.load (fun i => image.bytes (index + i)) .w64
  if index % 8 = 0 then
    if sp ≤ offset size index then forward index image.cells words raw else raw
  else raw

def ownedReadSpec (size : Nat) (words : List Nat) (sp : Int) (index : Nat) (image : Image) : Word :=
  if index % 8 = 0 ∧ sp ≤ offset size index ∧ index / 8 ∈ words ∧
      (image.cells (index / 8)).valid ≠ 0#8 then
    (image.cells (index / 8)).scalar
  else x86MemLoadSpec (fun i => image.bytes (index + i)) .w64

theorem owned_read_matches (size : Nat) (words : List Nat) (sp : Int) (index : Nat) (image : Image) :
    ownedRead size words sp index image = ownedReadSpec size words sp index image := by
  unfold ownedRead ownedReadSpec
  rw [x86_mem_load_refines]
  by_cases aligned : index % 8 = 0
  · simp only [aligned, ↓reduceIte, true_and]
    by_cases live : sp ≤ offset size index
    · simp only [live, ↓reduceIte, true_and, forward_matches index image.cells words _ aligned]
    · simp [live]
  · simp [aligned]

theorem owned_read_unaligned (size : Nat) (words : List Nat) (sp : Int) (index : Nat) (image : Image)
    (unaligned : index % 8 ≠ 0) :
    ownedRead size words sp index image = x86MemLoadSpec (fun i => image.bytes (index + i)) .w64 := by
  rw [owned_read_matches]
  simp [ownedReadSpec, unaligned]

theorem owned_read_forwarded (size : Nat) (words : List Nat) (sp : Int) (index : Nat) (image : Image)
    (aligned : index % 8 = 0) (live : sp ≤ offset size index)
    (declared : index / 8 ∈ words) (valid : (image.cells (index / 8)).valid ≠ 0#8) :
    ownedRead size words sp index image = (image.cells (index / 8)).scalar := by
  rw [owned_read_matches]
  simp [ownedReadSpec, aligned, live, declared, valid]

/-- Every branch of the source read agrees with the canonical native word
when active forwarded scalars and the source byte image represent that word. -/
theorem owned_read_native (size : Nat) (words : List Nat) (sp : Int) (index : Nat)
    (image : Image) (target : Word)
    (bytes : x86MemLoadSpec (fun i => image.bytes (index + i)) .w64 = target)
    (scalar : index % 8 = 0 → sp ≤ offset size index → index / 8 ∈ words →
      (image.cells (index / 8)).valid ≠ 0#8 → (image.cells (index / 8)).scalar = target) :
    ownedRead size words sp index image = target := by
  rw [owned_read_matches]
  unfold ownedReadSpec
  split <;> rename_i selected
  · exact scalar selected.1 selected.2.1 selected.2.2.1 selected.2.2.2
  · exact bytes

/-- SUB_RET reads at its current SP. The below-SP fresh-read alternative
therefore retains the owned result before the release changes the image. -/
def read (size : Nat) (words : List Nat) (sp off : Int) (index : Nat)
    (fresh : Word) (image : Image) : Word :=
  let raw := ownedRead size words sp index image
  if off < sp then fresh else raw

theorem read_at_sp (size : Nat) (words : List Nat) (sp : Int) (index : Nat)
    (fresh : Word) (image : Image) :
    read size words sp sp index fresh image = ownedRead size words sp index image := by
  simp [read]

/-- The read/forwarding relation supplies the earlier abstract saved-read
premise once for every entered source image and stack coordinate. -/
theorem sub_return_owned_projection (size : Nat) (words : List Nat)
    (env : Refinement.EntryEnvironment.Environment) (entry : Refinement.EntryEnvironment.Frame)
    (arena : Word) (index : Nat) (fresh : Nat → Reference.Byte) (state : ReturnImage)
    (bytes : x86MemLoadSpec (fun i => state.stack.bytes (index + i)) .w64 =
      returnStackWord env entry arena state.frame.registers)
    (scalar : index % 8 = 0 → (state.frame.registers.raw.gpr 4).toInt ≤ offset size index →
      index / 8 ∈ words → (state.stack.cells (index / 8)).valid ≠ 0#8 →
      (state.stack.cells (index / 8)).scalar = returnStackWord env entry arena state.frame.registers) :
    (subReturn size words
      (fun s => ownedRead size words (s.frame.registers.raw.gpr 4).toInt index s.stack)
      fresh state).state.frame = subroutineFrame env entry arena state.frame := by
  apply sub_return_frame_projection
  exact owned_read_native size words _ index state.stack _ bytes scalar


/-- Every later owned read inside the surviving live interval sees the
same bytes and scalar identity after the current release. -/
theorem owned_read_live_preserved (size : Nat) (words : List Nat) (oldSp newSp : Int)
    (fresh : Nat → Reference.Byte) (image : Image) (index : Nat)
    (live : newSp ≤ offset size index) :
    ownedRead size words newSp index (body size words oldSp newSp fresh image) =
      ownedRead size words newSp index image := by
  have bytes : (fun i => (body size words oldSp newSp fresh image).bytes (index + i)) =
      (fun i => image.bytes (index + i)) := by
    funext i
    apply retained_byte
    unfold offset at *
    omega
  rw [owned_read_matches, owned_read_matches]
  unfold ownedReadSpec
  rw [bytes]
  by_cases aligned : index % 8 = 0
  · have wordLive : newSp ≤ offset size (index / 8 * 8) := by
      have start : index / 8 * 8 = index := by omega
      simpa only [start] using live
    rw [live_cell_preserved size words oldSp newSp fresh image (index / 8) wordLive]
  · simp [aligned]

/-- Reallocating a previously released word reads its current byte image:
the cleared valid bit prevents stale scalar forwarding at every later SP. -/
theorem reallocated_word_reads_bytes (size : Nat) (words : List Nat) (oldSp newSp laterSp : Int)
    (fresh : Nat → Reference.Byte) (image : Image) (i : Nat)
    (growing : oldSp < newSp) (declared : i ∈ words)
    (below : offset size (i * 8) < newSp) :
    ownedRead size words laterSp (i * 8) (body size words oldSp newSp fresh image) =
      x86MemLoadSpec (fun j => (body size words oldSp newSp fresh image).bytes (i * 8 + j)) .w64 := by
  have invalid := (released_word_invalid size words oldSp newSp fresh image i growing declared below).2
  have zero : ((body size words oldSp newSp fresh image).cells i).valid = 0#8 := invalid
  rw [owned_read_matches]
  simp [ownedReadSpec, zero]


/-- Actual generated source index retains the complete wrapping raw SP. -/
def sourceIndex (size : Nat) (sp : Word) : Nat :=
  (GeneratedX86StackIndex.index (BitVec.ofNat 64 size) sp).toNat

theorem source_index_word (size : Nat) (sp : Word) :
    BitVec.ofNat 64 (sourceIndex size sp) = BitVec.ofNat 64 size + sp := by
  simp only [sourceIndex, GeneratedX86StackIndex.index, BitVec.ofNat_toNat, BitVec.setWidth_eq]

/-- Every allocated source coordinate has the same signed value as raw SP.
The capacity premise is the representation domain of the existing signed C
subtraction; the index premise is the allocated source interval. -/
theorem source_coordinate (size : Nat) (sp : Word)
    (capacity : size < 2 ^ 63) (inside : sourceIndex size sp ≤ size) :
    offset size (sourceIndex size sp) = sp.toInt := by
  let cap : Word := BitVec.ofNat 64 size
  let idx : Word := GeneratedX86StackIndex.index cap sp
  have capNat : cap.toNat = size := by
    simp only [cap, BitVec.toNat_ofNat]
    apply Nat.mod_eq_of_lt
    omega
  have idxNat : idx.toNat = sourceIndex size sp := rfl
  have capInt : cap.toInt = (size : Int) := by
    rw [BitVec.toInt_eq_toNat_of_lt (by rw [capNat]; omega), capNat]
  have idxInt : idx.toInt = (sourceIndex size sp : Int) := by
    rw [BitVec.toInt_eq_toNat_of_lt (by rw [idxNat]; omega), idxNat]
  have origin : idx - cap = sp := by
    simp only [idx, GeneratedX86StackIndex.index]
    rw [BitVec.add_comm, BitVec.add_sub_cancel]
  have exactInt : (idx - cap).toInt = (sourceIndex size sp : Int) - (size : Int) := by
    rw [BitVec.toInt_sub, idxInt, capInt]
    apply Int.bmod_eq_self_of_le <;> omega
  simpa only [origin, offset] using exactInt.symm

/-- The source arena and the native stack origin name each byte identically,
including wrapping physical arena addresses. -/
theorem source_byte_address (size : Nat) (sp origin : Word) (i : Nat) :
    origin + BitVec.ofNat 64 (sourceIndex size sp + i) =
      sp + (origin + BitVec.ofNat 64 size) + BitVec.ofNat 64 i := by
  rw [BitVec.ofNat_add, source_index_word]
  ac_rfl

/-- Exactly the eight bytes used by the generated full-word load matter. -/
theorem load64_congr (a b : Nat → Reference.Byte) (same : ∀ i, i < 8 → a i = b i) :
    GeneratedX86MemAccess.load a .w64 = GeneratedX86MemAccess.load b .w64 := by
  simp only [GeneratedX86MemAccess.load, GeneratedX86MemAccess.assemble,
    same 0 (by decide), same 1 (by decide), same 2 (by decide), same 3 (by decide),
    same 4 (by decide), same 5 (by decide), same 6 (by decide), same 7 (by decide)]

/-- Source values and active scalar identities represent the native memory
only in the allocated live interval. Released bytes are arbitrary fresh data. -/
def Coherent (size : Nat) (origin : Word) (sp : Int) (image : Image) (memory : Reference.Memory) : Prop :=
  (∀ i, i < size → sp ≤ offset size i → image.bytes i = memory.value (origin + BitVec.ofNat 64 i)) ∧
  (∀ slot, slot * 8 + 8 ≤ size → sp ≤ offset size (slot * 8) →
    (image.cells slot).valid ≠ 0#8 → (image.cells slot).scalar =
      GeneratedX86MemAccess.load (fun i => memory.value (origin + BitVec.ofNat 64 (slot * 8 + i))) .w64)

/-- Release preserves the representation of every surviving allocated byte
and active scalar word, for every supplied fresh stream. -/
theorem release_coherent (size : Nat) (words : List Nat) (origin : Word)
    (oldSp newSp : Int) (image : Image) (memory : Reference.Memory)
    (fresh : Nat → Reference.Byte) (increasing : oldSp ≤ newSp)
    (coherent : Coherent size origin oldSp image memory) :
    Coherent size origin newSp (body size words oldSp newSp fresh image) memory := by
  constructor
  · intro i inside live
    rw [retained_byte size words oldSp newSp fresh image i (by omega)]
    exact coherent.1 i inside (by omega)
  · intro slot inside live valid
    have same := live_cell_preserved size words oldSp newSp fresh image slot live
    rw [same] at valid ⊢
    exact coherent.2 slot inside (by omega) valid

/-- Actual index, live byte image and scalar forwarding together derive the
saved-read projection used by the current internal RET token. -/
theorem source_read_native (size : Nat) (words : List Nat)
    (env : Refinement.EntryEnvironment.Environment) (entry : Refinement.EntryEnvironment.Frame)
    (arena origin : Word) (state : ReturnImage)
    (capacity : size < 2 ^ 63)
    (allocated : sourceIndex size (state.frame.registers.raw.gpr 4) + 8 ≤ size)
    (stackOrigin : Refinement.EntryEnvironment.base env entry .stack = origin + BitVec.ofNat 64 size)
    (coherent : Coherent size origin (state.frame.registers.raw.gpr 4).toInt state.stack
      state.frame.registers.raw.memory) :
    ownedRead size words (state.frame.registers.raw.gpr 4).toInt
        (sourceIndex size (state.frame.registers.raw.gpr 4)) state.stack =
      returnStackWord env entry arena state.frame.registers := by
  let index := sourceIndex size (state.frame.registers.raw.gpr 4)
  have coordinate : offset size index = (state.frame.registers.raw.gpr 4).toInt :=
    source_coordinate size _ capacity (by omega)
  have address (i : Nat) : origin + BitVec.ofNat 64 (index + i) =
      registerValue env entry arena state.frame.registers 4 + BitVec.ofNat 64 i := by
    simp only [registerValue, ↓reduceIte, stackOrigin]
    exact source_byte_address size _ origin i
  apply owned_read_native
  · rw [← x86_mem_load_refines]
    unfold returnStackWord
    apply load64_congr
    intro i inside
    rw [coherent.1 (index + i) (by omega) (by unfold offset at *; omega), address]
  · intro aligned live declared valid
    have wordStart : index / 8 * 8 = index := by omega
    rw [coherent.2 (index / 8) (by omega) (by simpa only [wordStart] using live) valid]
    simp only [wordStart]
    unfold returnStackWord
    apply load64_congr
    intro i _
    rw [address]


/-- An allocated eight-byte return read supplies the representation bound
for the subsequent source index advance. -/
theorem source_index_advance (size : Nat) (sp : Word)
    (capacity : size < 2 ^ 63) (allocated : sourceIndex size sp + 8 ≤ size) :
    sourceIndex size (sp + 8) = sourceIndex size sp + 8 := by
  unfold sourceIndex
  simp only [GeneratedX86StackIndex.index, ← BitVec.add_assoc, BitVec.toNat_add]
  change (((BitVec.ofNat 64 size + sp).toNat + 8) % 18446744073709551616) = _
  apply Nat.mod_eq_of_lt
  change sourceIndex size sp + 8 < 18446744073709551616
  omega

/-- Signed C newSP-8 equals the captured previous SP throughout the allocated
RET domain, so the release interval is exactly eight signed bytes. -/
theorem source_sp_advance (size : Nat) (sp : Word)
    (capacity : size < 2 ^ 63) (allocated : sourceIndex size sp + 8 ≤ size) :
    (sp + 8).toInt = sp.toInt + 8 := by
  have previous := source_coordinate size sp capacity (by omega)
  have advance := source_index_advance size sp capacity allocated
  have current := source_coordinate size (sp + 8) capacity (by omega)
  rw [advance] at current
  unfold offset at *
  omega

def sourceRead (size : Nat) (words : List Nat) (state : ReturnImage) : Word :=
  ownedRead size words (state.frame.registers.raw.gpr 4).toInt
    (sourceIndex size (state.frame.registers.raw.gpr 4)) state.stack

def sourceSubReturn (size : Nat) (words : List Nat) (fresh : Nat → Reference.Byte)
    (state : ReturnImage) : CapturedReturn :=
  subReturn size words (sourceRead size words) fresh state

theorem source_sub_return_projection (size : Nat) (words : List Nat)
    (env : Refinement.EntryEnvironment.Environment) (entry : Refinement.EntryEnvironment.Frame)
    (arena origin : Word) (fresh : Nat → Reference.Byte) (state : ReturnImage)
    (capacity : size < 2 ^ 63)
    (allocated : sourceIndex size (state.frame.registers.raw.gpr 4) + 8 ≤ size)
    (stackOrigin : Refinement.EntryEnvironment.base env entry .stack = origin + BitVec.ofNat 64 size)
    (coherent : Coherent size origin (state.frame.registers.raw.gpr 4).toInt state.stack
      state.frame.registers.raw.memory) :
    (sourceSubReturn size words fresh state).state.frame = subroutineFrame env entry arena state.frame := by
  apply sub_return_frame_projection
  exact source_read_native size words env entry arena origin state capacity allocated stackOrigin coherent

/-- The same live-memory relation holds at the resulting raw SP. -/
theorem source_sub_return_coherent (size : Nat) (words : List Nat) (origin : Word)
    (fresh : Nat → Reference.Byte) (state : ReturnImage)
    (capacity : size < 2 ^ 63)
    (allocated : sourceIndex size (state.frame.registers.raw.gpr 4) + 8 ≤ size)
    (coherent : Coherent size origin (state.frame.registers.raw.gpr 4).toInt state.stack
      state.frame.registers.raw.memory) :
    let result := (sourceSubReturn size words fresh state).state
    Coherent size origin (result.frame.registers.raw.gpr 4).toInt result.stack result.frame.registers.raw.memory := by
  have advance := source_sp_advance size (state.frame.registers.raw.gpr 4) capacity allocated
  change Coherent size origin (state.frame.registers.raw.gpr 4 + 8).toInt
    (body size words ((state.frame.registers.raw.gpr 4 + 8).toInt - 8)
      (state.frame.registers.raw.gpr 4 + 8).toInt fresh state.stack) state.frame.registers.raw.memory
  rw [advance]
  have old : (state.frame.registers.raw.gpr 4).toInt + 8 - 8 =
      (state.frame.registers.raw.gpr 4).toInt := by omega
  rw [old]
  apply release_coherent size words origin _ _ state.stack state.frame.registers.raw.memory fresh (by omega) coherent

/-- Actual source read/index/forwarding and release compose into the native
RET step under the existing read-permission and canonical-target ISA premises. -/
theorem source_sub_return_step (size : Nat) (words : List Nat)
    (env : Refinement.EntryEnvironment.Environment) (entry : Refinement.EntryEnvironment.Frame)
    (arena origin : Word) (fresh : Nat → Reference.Byte) (state : ReturnImage) (nextPc : Word)
    (capacity : size < 2 ^ 63)
    (allocated : sourceIndex size (state.frame.registers.raw.gpr 4) + 8 ≤ size)
    (stackOrigin : Refinement.EntryEnvironment.base env entry .stack = origin + BitVec.ofNat 64 size)
    (coherent : Coherent size origin (state.frame.registers.raw.gpr 4).toInt state.stack
      state.frame.registers.raw.memory)
    (readable : Reference.permitted state.frame.registers.raw.memory.readable
      (registerValue env entry arena state.frame.registers 4) 8 = true)
    (canonical : Reference.X86.canonicalTarget state.frame.registers.raw.addressWidth
      (returnStackWord env entry arena state.frame.registers) = true) :
    Reference.Transition.mk
      (nativeRegisters env entry arena (sourceSubReturn size words fresh state).state.frame.registers)
      (returnStackReads env entry arena state.frame.registers) none =
      Reference.X86.step (.returnNear 0 nextPc) (nativeRegisters env entry arena state.frame.registers) := by
  rw [source_sub_return_projection size words env entry arena origin fresh state
    capacity allocated stackOrigin coherent]
  exact return_label_frame_refines env entry arena state.frame.registers nextPc readable canonical


/-- Current source RET uses the captured owned word for the finite continuation
choice and carries the released source image through both alternatives. -/
def sourceReturnBody (size : Nat) (words : List Nat)
    (env : Refinement.EntryEnvironment.Environment) (entry : Refinement.EntryEnvironment.Frame)
    (arena : Word) (releaseFresh : Nat → Reference.Byte) (state : ReturnImage)
    (targets : List Word) : ReturnOutcome × Image :=
  let result := sourceSubReturn size words releaseFresh state
  let effect : Reference.Transition Reference.X86.State :=
    ⟨nativeRegisters env entry arena result.state.frame.registers,
      returnStackReads env entry arena state.frame.registers, none⟩
  (.subroutine result.state.frame
    (if targets.contains result.target then .label effect else .unresolved effect), result.state.stack)

/-- The existing specialized RET token executes the current source read,
stack release and selected/default body under one live representation relation. -/
theorem source_return_token (size : Nat) (words : List Nat)
    (env : Refinement.EntryEnvironment.Environment) (entry : Refinement.EntryEnvironment.Frame)
    (arena origin : Word) (releaseFresh : Nat → Reference.Byte) (state : ReturnImage)
    (targets : List Word) (fresh : Nat → Bool) (current : Nat) (flags : Reference.Byte)
    (aux : BitVec 32) (dst src : Reference.Byte) (value nextPc : Word)
    (capacity : size < 2 ^ 63)
    (allocated : sourceIndex size (state.frame.registers.raw.gpr 4) + 8 ≤ size)
    (stackOrigin : Refinement.EntryEnvironment.base env entry .stack = origin + BitVec.ofNat 64 size)
    (coherent : Coherent size origin (state.frame.registers.raw.gpr 4).toInt state.stack
      state.frame.registers.raw.memory) :
    tokenBody size words releaseFresh env entry arena fresh current state (.subroutine targets)
        flags aux dst src value nextPc =
      some (sourceReturnBody size words env entry arena releaseFresh state targets) := by
  have frameProjection := source_sub_return_projection size words env entry arena origin releaseFresh
    state capacity allocated stackOrigin coherent
  have targetProjection : (sourceSubReturn size words releaseFresh state).target =
      returnStackWord env entry arena state.frame.registers :=
    source_read_native size words env entry arena origin state capacity allocated stackOrigin coherent
  have stackProjection : (sourceSubReturn size words releaseFresh state).state.stack =
      spec size words ((state.frame.registers.raw.gpr 4 + 8).toInt - 8)
        (state.frame.registers.raw.gpr 4 + 8).toInt releaseFresh state.stack := by
    simp only [sourceSubReturn, subReturn, body_matches]
  rw [token_body_matches]
  simp only [dispatch, returnDispatch, ↓reduceIte, attach, return_dispatch_body_matches,
    specializedReturnDispatch, sourceReturnBody, frameProjection, targetProjection, stackProjection]
  split <;> rfl

end StackRelease







end KProgFormal.X86RemainingTokenO2

#print axioms KProgFormal.X86RemainingTokenO2.call_helper_body_matches
#print axioms KProgFormal.X86RemainingTokenO2.call_reg_body_matches
#print axioms KProgFormal.X86RemainingTokenO2.ret_body_matches
#print axioms KProgFormal.X86RemainingTokenO2.ret_default_body_matches
