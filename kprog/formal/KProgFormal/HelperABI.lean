import KProgFormal.InvocationABI
import KProgFormal.X86HelperDispatch
import KProgFormal.Arm64HelperIdents

/-! Shared native helper argument and identity transport. The x86 register
order is SysV RDI,RSI,RDX,RCX,R8; AAPCS64 uses X0..X4. Typed pointee effects,
object lifetime, real symbol selection and compiler transport supply the
physical interfaces. Each statement ranges over every invocation and helper. -/
namespace KProgFormal.HelperABI
open Reference Refinement.EntryEnvironment

abbrev Word := Reference.Word

abbrev Arguments := Fin 5 → Word

def x86ArgumentRegister (index : Fin 5) : X86.Register :=
  match index.val with
  | 0 => 7 | 1 => 6 | 2 => 2 | 3 => 1 | _ => 8

def arm64ArgumentRegister (index : Fin 5) : AArch64.Gpr :=
  ⟨index.val, by omega⟩

def x86Arguments (state : X86.State) : Arguments :=
  fun index => state.gpr (x86ArgumentRegister index)

def arm64Arguments (state : AArch64.State) : Arguments :=
  fun index => state.gpr (arm64ArgumentRegister index)

/-- The source register selector is injective for all five argument places. -/
theorem x86_argument_registers_distinct : ∀ first second : Fin 5, x86ArgumentRegister first = x86ArgumentRegister second → first = second := by
  decide

theorem arm64_argument_registers_distinct : ∀ first second : Fin 5, arm64ArgumentRegister first = arm64ArgumentRegister second → first = second := by
  intro first second same
  have values := congrArg (fun register : AArch64.Gpr => register.val) same
  exact Fin.ext values

/-- Materialization uses actual same-invocation stack/code/return bases for
all arguments, independently of sparse helper registry positions. -/
def materializedArguments (env : Environment) (frame : Frame)
    (arguments : Fin 5 → Value) : Arguments :=
  fun index => materialize env frame (arguments index)

theorem x86_argument_transport (env : Environment) (frame : Frame)
    (arguments : Fin 5 → Value) (state : X86.State)
    (registers : ∀ index, state.gpr (x86ArgumentRegister index) =
      materialize env frame (arguments index)) :
    x86Arguments state = materializedArguments env frame arguments := by
  funext index
  exact registers index

theorem arm64_argument_transport (env : Environment) (frame : Frame)
    (arguments : Fin 5 → Value) (state : AArch64.State)
    (registers : ∀ index, state.gpr (arm64ArgumentRegister index) =
      materialize env frame (arguments index)) :
    arm64Arguments state = materializedArguments env frame arguments := by
  funext index
  exact registers index

/-- u32 coercions used by the real helper prototypes occur after numeric
materialization, including stack, code and saved-return values. -/
def u32Arguments (arguments : Arguments) : Fin 5 → BitVec 32 :=
  fun index => (arguments index).setWidth 32

theorem typed_u32_transport (env : Environment) (frame : Frame)
    (arguments : Fin 5 → Value) (native : Arguments)
    (same : native = materializedArguments env frame arguments) :
    u32Arguments native = fun index =>
      (materialize env frame (arguments index)).setWidth 32 := by
  rw [same]
  rfl

/-- A selected x86 slot recovers the original full64 identity. -/
theorem x86_selected_identity (identity : Word) (slot : Nat)
    (selected : GeneratedX86HelperDispatch.slotOf identity = some slot) :
    GeneratedX86HelperDispatch.idOfSlot slot = some identity.toNat :=
  X86HelperBody.routed_id_identity identity slot selected

/-- Every generated AArch64 helper constructor has its exact canonical Linux
id/name pair in the independent enumeration. -/
theorem arm64_selected_identity (helper : GeneratedArm64HelperIdents.Helper) :
    (GeneratedArm64HelperIdents.id helper, GeneratedArm64HelperIdents.name helper) ∈
      helperIdentsSpec := helper_idents_pair_complete helper

/-- The helper sees a pre-call snapshot even when its result or clobbers
later replace any argument registers. Arbitrary memory effects are retained. -/
theorem x86_precall_effect {Effect : Type} (helper : Word → Arguments → Memory → Effect)
    (env : Environment) (frame : Frame) (arguments : Fin 5 → Value)
    (identity : Word) (slot : Nat) (state : X86.State)
    (selected : GeneratedX86HelperDispatch.slotOf identity = some slot)
    (registers : ∀ index, state.gpr (x86ArgumentRegister index) =
      materialize env frame (arguments index)) :
    GeneratedX86HelperDispatch.idOfSlot slot = some identity.toNat ∧
    helper identity (x86Arguments state) state.memory =
      helper identity (materializedArguments env frame arguments) state.memory := by
  exact ⟨x86_selected_identity identity slot selected,
    congrArg (fun args => helper identity args state.memory)
      (x86_argument_transport env frame arguments state registers)⟩

/-- ARM retains the full canonical identity alongside the same source
argument tuple and the complete source memory. -/
theorem arm64_precall_effect {Effect : Type} (helper : Nat → Arguments → Memory → Effect)
    (env : Environment) (frame : Frame) (arguments : Fin 5 → Value)
    (identity : GeneratedArm64HelperIdents.Helper) (state : AArch64.State)
    (registers : ∀ index, state.gpr (arm64ArgumentRegister index) =
      materialize env frame (arguments index)) :
    (GeneratedArm64HelperIdents.id identity, GeneratedArm64HelperIdents.name identity) ∈
      helperIdentsSpec ∧
    helper (GeneratedArm64HelperIdents.id identity) (arm64Arguments state) state.memory =
      helper (GeneratedArm64HelperIdents.id identity)
        (materializedArguments env frame arguments) state.memory := by
  exact ⟨arm64_selected_identity identity,
    congrArg (fun args => helper (GeneratedArm64HelperIdents.id identity) args state.memory)
      (arm64_argument_transport env frame arguments state registers)⟩

/-- The actual generated returning-helper wrapper composes with native
argument transport. Capture precedes result, caller clobbers and PC advance. -/
theorem x86_generated_precall (env : Environment) (entry : Frame) (arena : Word)
    (effects : Word → Arguments → Memory → X86HelperBody.Effect)
    (state : X86CallMemBody.Frame) (arguments : Fin 5 → Value)
    (identity : Word) (slot : Nat) (fresh : X86CallMemBody.Fresh) (nextPc : Word)
    (selected : GeneratedX86HelperDispatch.slotOf identity = some slot)
    (registers : ∀ index,
      (Refinement.X86NumericAddress.nativeRegisters env entry arena state.registers).gpr
        (x86ArgumentRegister index) = materialize env entry (arguments index)) :
    X86HelperBody.generatedCall
      (fun id captured => effects id
        (x86Arguments (Refinement.X86NumericAddress.nativeRegisters env entry arena captured.registers))
        captured.registers.raw.memory) state identity fresh nextPc =
      some (X86HelperBody.returnSpec state
        (effects identity (materializedArguments env entry arguments) state.registers.raw.memory)
        fresh nextPc) := by
  rw [X86HelperBody.selected_helper_observation _ state identity slot selected fresh nextPc]
  rw [x86_argument_transport env entry arguments _ registers]

end KProgFormal.HelperABI

#print axioms KProgFormal.HelperABI.x86_precall_effect
#print axioms KProgFormal.HelperABI.arm64_precall_effect

#print axioms KProgFormal.HelperABI.x86_generated_precall
