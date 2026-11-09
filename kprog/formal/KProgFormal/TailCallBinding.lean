import KProgFormal.InvocationABI

/-! Program-array selection and successful control transfer, once for all
programs. The selection follows the indirect tail-call paths in
arch/x86/net/bpf_jit_comp.c:emit_bpf_tail_call_indirect and
arch/arm64/net/bpf_jit_comp.c:emit_bpf_tail_call. Both publish the increment
only for a populated slot. The kernel's dynamic array lookup, RCU retention,
JIT unwind and target entry correspondence supply the physical interfaces.
The returning helper semantics and a successful transfer have distinct results. -/
namespace KProgFormal.TailCallBinding
open Reference InvocationABI

structure Target where
  identity : Nat
  bodyEntry : Word
  contextKind : ContextKind
  deriving DecidableEq, Repr

/-- A table is observed at this call; updates between calls stay arbitrary. -/
def select (entries budget used : Nat) (index : BitVec 32)
    (table : Nat → Option Target) : Option Target :=
  if index.toNat < entries ∧ used < budget then table index.toNat else none

inductive Outcome where
  | resume (used : Nat) (continuation : Word)
  | transfer (target : Target) (context : Word) (used : Nat) (outerReturn : Word)
  deriving DecidableEq, Repr

def invoke (entries budget used : Nat) (rawIndex context continuation outerReturn : Word)
    (table : Nat → Option Target) : Outcome :=
  match select entries budget used (rawIndex.setWidth 32) table with
  | none => .resume used continuation
  | some target => .transfer target context (used + 1) outerReturn

/-- Selection derives all successful-call premises from the result itself. -/
theorem selected_target (entries budget used : Nat) (index : BitVec 32)
    (table : Nat → Option Target) (target : Target)
    (chosen : select entries budget used index table = some target) :
    index.toNat < entries ∧ used < budget ∧ table index.toNat = some target := by
  unfold select at chosen
  split at chosen
  · rename_i valid
    exact ⟨valid.1, valid.2, chosen⟩
  · contradiction

/-- The successful path retains exact object, ABI, original context, shared
count and the outer continuation. It contains the target entry explicitly. -/
theorem successful_transfer (entries budget used : Nat)
    (rawIndex context continuation outerReturn : Word) (table : Nat → Option Target)
    (target : Target)
    (chosen : select entries budget used (rawIndex.setWidth 32) table = some target) :
    invoke entries budget used rawIndex context continuation outerReturn table =
      .transfer target context (used + 1) outerReturn := by
  simp [invoke, chosen]

/-- A failed tail call keeps the original count and resumes its own caller. -/
theorem failed_transfer (entries budget used : Nat)
    (rawIndex context continuation outerReturn : Word) (table : Nat → Option Target)
    (chosen : select entries budget used (rawIndex.setWidth 32) table = none) :
    invoke entries budget used rawIndex context continuation outerReturn table =
      .resume used continuation := by
  simp [invoke, chosen]

/-- Both native ABIs explicitly truncate the index to u32, so upper bits of
an arbitrary native argument have the same selection and control outcome. -/
theorem index32_preserves (entries budget used : Nat)
    (first second context continuation outerReturn : Word) (table : Nat → Option Target)
    (same : first.setWidth 32 = second.setWidth 32) :
    invoke entries budget used first context continuation outerReturn table =
      invoke entries budget used second context continuation outerReturn table := by
  simp only [invoke, same]

/-- The two lookup witnesses may come from independently changing tables.
Equality at the selected slot suffices; the rest of either table stays free. -/
theorem lookup_resolution_preserves (entries budget used : Nat)
    (rawIndex context continuation outerReturn : Word)
    (first second : Nat → Option Target)
    (same : first (rawIndex.setWidth 32).toNat = second (rawIndex.setWidth 32).toNat) :
    invoke entries budget used rawIndex context continuation outerReturn first =
      invoke entries budget used rawIndex context continuation outerReturn second := by
  simp only [invoke, select, same]

/-- RCU/object retention is an interval property, independent of later array
updates. This proof-level predicate introduces a lifetime premise. -/
def Retained (objects : Nat → Nat → Option Target) (target : Target)
    (start finish : Nat) : Prop :=
  ∀ time, start ≤ time → time ≤ finish → objects time target.identity = some target

/-- A selected target's entry and ABI remain those of the same live object
through a shorter use interval, even as the program-array slot changes. -/
theorem retained_target_lifetime (objects : Nat → Nat → Option Target)
    (target : Target) (start finish useStart useFinish : Nat)
    (pinned : Retained objects target start finish)
    (afterPin : start ≤ useStart) (beforeRelease : useFinish ≤ finish) :
    Retained objects target useStart useFinish := by
  intro time low high
  exact pinned time (Nat.le_trans afterPin low) (Nat.le_trans high beforeRelease)

/-- Target resolution from the retained object has a unique entry and ABI;
a subsequent slot update has no role in this dereference. -/
theorem retained_target_identity (objects : Nat → Nat → Option Target)
    (target observed : Target) (start finish time : Nat)
    (pinned : Retained objects target start finish)
    (low : start ≤ time) (high : time ≤ finish)
    (read : objects time target.identity = some observed) :
    observed = target ∧ observed.bodyEntry = target.bodyEntry ∧
      observed.contextKind = target.contextKind := by
  have same : observed = target := Option.some.inj (read.symm.trans (pinned time low high))
  exact ⟨same, congrArg Target.bodyEntry same, congrArg Target.contextKind same⟩

/-- The x86 register-indirect jump decodes to this reference branch with its
incoming register target. All unwound body state and memory retain their bits. -/
theorem x86_target_control (state : X86.State) (register : X86.Register)
    (target : Target) (fallthrough : Word) (resolved : state.gpr register = target.bodyEntry) :
    X86.step (.branch none (state.gpr register) fallthrough) state =
      ⟨{ state with pc := target.bodyEntry }, [], none⟩ := by
  simp [X86.step, resolved]

/-- BR samples the target register and retains LR, SP and every other field. -/
theorem arm64_target_control (state : AArch64.State) (register : AArch64.Register)
    (target : Target) (resolved : AArch64.readReg state register = target.bodyEntry) :
    AArch64.step (.branchRegister false register) state =
      ⟨{ state with pc := target.bodyEntry }, [], none⟩ := by
  simp [AArch64.step, resolved]

/-- The context ABI is independent of which program supplied the target.
An x86 tail entry requires the selected program's numeric argument and stack;
this law transports them through the actual jump. -/
theorem x86_target_entry (env : Refinement.EntryEnvironment.Environment)
    (frame : Refinement.EntryEnvironment.Frame) (state : X86.State)
    (register : X86.Register) (target : Target) (context kernelContext slot fallthrough : Word)
    (resolved : state.gpr register = target.bodyEntry)
    (code : target.bodyEntry = Refinement.EntryEnvironment.base env frame .code)
    (stack : state.gpr 4 = Refinement.EntryEnvironment.base env frame .stack)
    (argumentValue : state.gpr 7 = argument target.contextKind context kernelContext)
    (saved : wordAt state.memory slot 8 = env.outerReturn) :
    Refinement.EntryEnvironment.X86Entry env frame 7
      (argument target.contextKind context kernelContext) slot
      (X86.step (.branch none (state.gpr register) fallthrough) state).state := by
  rw [x86_target_control state register target fallthrough resolved]
  exact ⟨stack, code, argumentValue, saved⟩

theorem arm64_target_entry (env : Refinement.EntryEnvironment.Environment)
    (frame : Refinement.EntryEnvironment.Frame) (state : AArch64.State)
    (register : AArch64.Register) (target : Target) (context kernelContext : Word)
    (resolved : AArch64.readReg state register = target.bodyEntry)
    (code : target.bodyEntry = Refinement.EntryEnvironment.base env frame .code)
    (stack : state.sp = Refinement.EntryEnvironment.base env frame .stack)
    (argumentValue : state.gpr 0 = argument target.contextKind context kernelContext)
    (saved : state.gpr 30 = env.outerReturn) :
    Refinement.EntryEnvironment.Arm64Entry env frame 0
      (argument target.contextKind context kernelContext)
      (AArch64.step (.branchRegister false register) state).state := by
  rw [arm64_target_control state register target resolved]
  exact ⟨stack, code, argumentValue, saved⟩

end KProgFormal.TailCallBinding

#print axioms KProgFormal.TailCallBinding.selected_target
#print axioms KProgFormal.TailCallBinding.retained_target_identity
#print axioms KProgFormal.TailCallBinding.x86_target_entry
#print axioms KProgFormal.TailCallBinding.arm64_target_entry
