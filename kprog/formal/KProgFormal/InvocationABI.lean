import KProgFormal.Refinement.EntryEnvironment
import KProgFormal.Generated.GeneratedAbiLoad

/-! Universal source entry and architectural return laws. The three context
forms follow X86_SIM_ENTRY_{XDP,SKB,RAW} and ARM64_SIM_ENTRY_{XDP,SKB,RAW}.
Physical JIT entry, cast provenance, frame ownership and compiled wrapper
correspondence supply the stated interfaces. Every law quantifies over the
complete incoming state and every context value. -/
namespace KProgFormal.InvocationABI
open Reference
open Refinement.EntryEnvironment

inductive ContextKind | xdp | skb | raw
  deriving DecidableEq, Repr

/-- XDP and raw preserve the received pointer. SKB receives the kernel-context
cast selected by the existing entry macro. -/
def argument (kind : ContextKind) (context kernelContext : Word) : Word :=
  match kind with
  | .xdp | .raw => context
  | .skb => kernelContext

/-- Same-invocation source coordinates; all remaining state stays arbitrary. -/
def x86Entry (env : Environment) (frame : Frame) (kind : ContextKind)
    (context kernelContext : Word) (incoming : X86.State) : X86.State :=
  { incoming with
    gpr := fun r => if r = 4 then base env frame .stack
      else if r = 7 then argument kind context kernelContext else incoming.gpr r
    pc := base env frame .code }

def arm64Entry (env : Environment) (frame : Frame) (kind : ContextKind)
    (context kernelContext : Word) (incoming : AArch64.State) : AArch64.State :=
  { incoming with
    gpr := fun r => if r = 0 then argument kind context kernelContext
      else if r = 30 then env.outerReturn else incoming.gpr r
    sp := base env frame .stack
    pc := base env frame .code }

/-- The real return-slot contents are an explicit x86 invocation premise. -/
theorem x86_entry_all_contexts (env : Environment) (frame : Frame)
    (kind : ContextKind) (context kernelContext slot : Word) (incoming : X86.State)
    (saved : wordAt incoming.memory slot 8 = env.outerReturn) :
    X86Entry env frame 7 (argument kind context kernelContext) slot
      (x86Entry env frame kind context kernelContext incoming) := by
  constructor <;> simp [x86Entry, saved]

theorem arm64_entry_all_contexts (env : Environment) (frame : Frame)
    (kind : ContextKind) (context kernelContext : Word) (incoming : AArch64.State) :
    Arm64Entry env frame 0 (argument kind context kernelContext)
      (arm64Entry env frame kind context kernelContext incoming) := by
  constructor <;> simp [arm64Entry]

/-- Complete architectural return: RAX, every other GPR, flags, SIMD, memory,
segment bases and the paging profile retain their body values. The return
slot read and canonical-target premise govern the native RET itself. -/
theorem x86_return (body : X86.State) (target ignored : Word)
    (release : BitVec 16) (read : Event)
    (saved : readMemory body.memory (body.gpr 4) 8 = .ok (target, read))
    (canonical : X86.canonicalTarget body.addressWidth target = true) :
    X86.step (.returnNear release ignored) body =
      ⟨{ body with
        gpr := fun r => if r = 4 then body.gpr 4 + 8 + release.setWidth 64 else body.gpr r
        pc := target }, [read], none⟩ := by
  simp [X86.step, X86.returnStep, saved, canonical]

/-- The ordinary outer ABI uses RET with release zero. This connects the
same-invocation return-slot witness to the actual body return instruction. -/
theorem x86_outer_return (env : Environment) (body : X86.State)
    (slot ignored : Word) (read : Event)
    (stack : body.gpr 4 = slot)
    (saved : readMemory body.memory slot 8 = .ok (env.outerReturn, read))
    (canonical : X86.canonicalTarget body.addressWidth env.outerReturn = true) :
    X86.step (.returnNear 0 ignored) body =
      ⟨{ body with
        gpr := fun r => if r = 4 then slot + 8 else body.gpr r,
        pc := env.outerReturn }, [read], none⟩ := by
  have actual := x86_return body env.outerReturn ignored 0 read (by simpa [stack] using saved) canonical
  simpa [stack] using actual

/-- RET X30 preserves the complete body state except PC, including X0,
SP, every vector bank, monitor, memory and per-step platform inputs. -/
theorem arm64_return (body : AArch64.State) :
    AArch64.step (.branchRegister false 30) body =
      ⟨{ body with pc := body.gpr 30 }, [], none⟩ := by
  rfl

theorem arm64_outer_return (env : Environment) (body : AArch64.State)
    (saved : body.gpr 30 = env.outerReturn) :
    AArch64.step (.branchRegister false 30) body =
      ⟨{ body with pc := env.outerReturn }, [], none⟩ := by
  rw [arm64_return, saved]

/-- Readability and the saved word derive the x86 return observation, retaining
its actual initialization bit and bytes. The chosen slot may wrap. -/
theorem x86_return_from_entry_slot (env : Environment) (frame : Frame)
    (kind : ContextKind) (context kernelContext slot ignored : Word)
    (incoming body : X86.State)
    (entry : X86Entry env frame 7 (argument kind context kernelContext) slot incoming)
    (stack : body.gpr 4 = slot)
    (bytes : wordAt body.memory slot 8 = wordAt incoming.memory slot 8)
    (readable : permitted body.memory.readable slot 8 = true)
    (canonical : X86.canonicalTarget body.addressWidth env.outerReturn = true) :
    X86.step (.returnNear 0 ignored) body =
      ⟨{ body with
        gpr := fun r => if r = 4 then slot + 8 else body.gpr r
        pc := env.outerReturn },
        [.memory .read slot (bytesAt body.memory slot 8) (initializedAt body.memory slot 8)], none⟩ := by
  apply x86_outer_return env body slot ignored _ stack _ canonical
  simp [readMemory, readable, bytes, entry.outerReturn]

/-- Entry relations also transport ARM's same-invocation saved LR to RET. -/
theorem arm64_return_from_entry (env : Environment) (frame : Frame)
    (kind : ContextKind) (context kernelContext : Word) (incoming body : AArch64.State)
    (entry : Arm64Entry env frame 0 (argument kind context kernelContext) incoming)
    (saved : body.gpr 30 = incoming.gpr 30) :
    AArch64.step (.branchRegister false 30) body =
      ⟨{ body with pc := env.outerReturn }, [], none⟩ :=
  arm64_outer_return env body (saved.trans entry.outerReturn)

/-- Exact context rebasing uses the generated implementation function. This
law ranges over all context values, including aliases and raw contexts. -/
theorem helper_context_base (base context : Nat) :
    GeneratedAbiLoad.helperContext base base context = context := by
  simp [GeneratedAbiLoad.helperContext]

theorem helper_context_identity (value context : Nat) :
    GeneratedAbiLoad.helperContext value context context = value := by
  by_cases same : value = context <;> simp [GeneratedAbiLoad.helperContext, same]

/-- An offset pointer keeps its own bits whenever it differs from the exact
context base. A physical provenance relation supplies the allowed argument. -/
theorem helper_context_offset (base offset context : Nat) (positive : 0 < offset) :
    GeneratedAbiLoad.helperContext (base + offset) base context = base + offset := by
  have apart : base + offset ≠ base := by omega
  simp [GeneratedAbiLoad.helperContext, apart]

/-- Actual AArch64 RET X30 bytes decode to the architectural return rule. -/
theorem arm64_ret_bytes :
    AArch64.decode #[0xc0, 0x03, 0x5f, 0xd6] = .ok (.branchRegister false 30) := by
  rfl

/-- The observable program result follows the existing u32 return casts. The
full64-bit source result remains intact through the architectural return. -/
theorem x86_return_result32 (body : X86.State) (target ignored : Word)
    (read : Event) (saved : readMemory body.memory (body.gpr 4) 8 = .ok (target, read))
    (canonical : X86.canonicalTarget body.addressWidth target = true) :
    ((X86.step (.returnNear 0 ignored) body).state.gpr 0).setWidth 32 =
      (body.gpr 0).setWidth 32 := by
  rw [x86_return body target ignored 0 read saved canonical]
  rfl

theorem arm64_return_result32 (body : AArch64.State) :
    ((AArch64.step (.branchRegister false 30) body).state.gpr 0).setWidth 32 =
      (body.gpr 0).setWidth 32 := by
  rw [arm64_return]

end KProgFormal.InvocationABI

#print axioms KProgFormal.InvocationABI.x86_return_from_entry_slot
#print axioms KProgFormal.InvocationABI.arm64_return_from_entry
