import KProgFormal.Refinement.X86NumericAddress
import KProgFormal.InvocationABI
import KProgFormal.TailCallBinding
import KProgFormal.HelperABI
import KProgFormal.SpillControl

/-! Universal control/ABI reductions against the physical producer interfaces.
The kernel, compiler and C interpretation are explicit universal premises.
The laws apply to arbitrary programs, incoming states and execution prefixes.
S7's exit contract (48eb036f5, 98013a7f6) supplies callee-save equality;
S11 supplies the physical native cleanup and JIT tail-frame correspondence.
-/
namespace KProgFormal.ControlABI
open Reference
abbrev Word := Reference.Word

/-! ## JIT entry and unwind
x86 emit_prologue establishes RBP, stack storage and the optional two-word
shared-tail-count frame before saving used callee registers. ARM build_prologue
saves FP/LR, its count frame and callee registers before allocating the stack.
The equations below retain every other architectural field, and use the
physical frame sizes supplied by those producers. -/

@[reducible] def x86Callee (r : Reference.X86.Register) : Prop :=
  r.val ∈ [3, 5, 12, 13, 14, 15]

@[reducible] def arm64Callee (r : Reference.AArch64.Gpr) : Prop :=
  19 ≤ r.val ∧ r.val ≤ 29

def x86Exit (entry body : X86.State) : Prop :=
  body.gpr 4 = entry.gpr 4 ∧ ∀ r, x86Callee r → body.gpr r = entry.gpr r

def arm64Exit (entry body : AArch64.State) : Prop :=
  body.sp = entry.sp ∧ ∀ r, arm64Callee r → body.gpr r = entry.gpr r

/-- Stack arithmetic is modular Word arithmetic, including all frame sizes. -/
theorem x86_frame_unwind (outer allocated saved : Word) :
    ((outer - allocated) - saved) + saved + allocated = outer := by
  rw [BitVec.sub_add_cancel, BitVec.sub_add_cancel]

theorem arm64_frame_unwind (outer records allocated : Word) :
    ((outer - records) - allocated) + allocated + records = outer := by
  rw [BitVec.sub_add_cancel, BitVec.sub_add_cancel]

/-- S11 kinds10/11 use the actual physical JIT stack size: the shared
counter pointer lies below the rounded allocation and the two count words. -/
theorem x86_tail_counter_address (frame depth : Word) :
    frame + ((-16 : Word) - depth) = (frame - depth) - 16 := by
  unfold Word Reference.Word at *
  bv_decide

/-- Native cleanup, used JIT callee saves, the two count words and the
actual allocation are unwound before the fixed target tail-entry landing pad. -/
theorem x86_tail_stack_unwind (frame depth jitSaved nativeSaved : Word) :
    (((((frame - depth - 16) - jitSaved) - nativeSaved) + nativeSaved + jitSaved) + 8 + 8) + depth
      = frame := by
  unfold Word Reference.Word at *
  bv_decide

/-- The kernel writes a signed disp32 for the counter-pointer load. This
source-domain bound is the encoding premise, shared by every emitted program. -/
theorem x86_tail_count_disp32 (depth : BitVec 32) (encodable : depth ≤ (0x7ffffff0#32)) :
    ((-16 - depth).signExtend 64) = (-16 : Word) - depth.zeroExtend 64 := by
  unfold Word Reference.Word at *
  bv_decide

theorem x86_tail_stack_imm32 (depth : BitVec 32) (encodable : depth < (0x80000000#32)) :
    depth.signExtend 64 = depth.zeroExtend 64 := by
  bv_decide

/-- S7 supplies exactly the equalities consumed at a native body exit.
Callee-save restoration retains every other register from the body. -/
def x86Restore (entry body : X86.State) : X86.State :=
  { body with gpr := fun r => if x86Callee r then entry.gpr r else body.gpr r }

def arm64Restore (entry body : AArch64.State) : AArch64.State :=
  { body with gpr := fun r => if arm64Callee r then entry.gpr r else body.gpr r }


theorem x86_restore_exit (entry body : X86.State) (exit : x86Exit entry body) :
    x86Restore entry body = body := by
  have regs : (fun r => if x86Callee r then entry.gpr r else body.gpr r) = body.gpr := by
    funext r
    split
    · rename_i saved
      exact (exit.2 r saved).symm
    · rfl
  simp only [x86Restore, regs]

theorem arm64_restore_exit (entry body : AArch64.State) (exit : arm64Exit entry body) :
    arm64Restore entry body = body := by
  have regs : (fun r => if arm64Callee r then entry.gpr r else body.gpr r) = body.gpr := by
    funext r
    split
    · rename_i saved
      exact (exit.2 r saved).symm
    · rfl
  simp only [arm64Restore, regs]

/-- Actual x86 RET follows S7's complete callee-save exit relation and the
same physical readable saved-return slot. The full body result is retained. -/
theorem x86_physical_return (entry body : X86.State) (target ignored : Word) (read : Event)
    (exit : x86Exit entry body)
    (saved : readMemory body.memory (body.gpr 4) 8 = .ok (target, read))
    (canonical : X86.canonicalTarget body.addressWidth target = true) :
    X86.step (.returnNear 0 ignored) (x86Restore entry body) =
      ⟨{ body with
          gpr := fun r => if r = 4 then body.gpr 4 + 8 else body.gpr r
          pc := target }, [read], none⟩ := by
  rw [x86_restore_exit entry body exit]
  simpa using InvocationABI.x86_return body target ignored 0 read saved canonical

/-- ARM JIT epilogue moves BPF R0 (physical X7) into physical X0. FP/LR
reload, authentication and SP cleanup supply the physical unwind premises. -/
def arm64ResultMove (body : AArch64.State) : AArch64.State :=
  { body with gpr := fun r => if r = 0 then body.gpr 7 else body.gpr r }

theorem arm64_jit_result (entry body : AArch64.State) (outer : Word)
    (exit : arm64Exit entry body) (saved : body.gpr 30 = outer) :
    AArch64.step (.branchRegister false 30)
      (arm64ResultMove (arm64Restore entry body)) =
      ⟨{ arm64ResultMove body with pc := outer }, [], none⟩ ∧
    ((arm64ResultMove body).gpr 0).setWidth 32 = (body.gpr 7).setWidth 32 := by
  rw [arm64_restore_exit entry body exit]
  constructor
  · change (⟨{ arm64ResultMove body with pc := body.gpr 30 }, [], none⟩ : Transition AArch64.State) = _
    rw [saved]
  · rfl

/-- The fixed x86 prologue bytes come directly from emit_prologue.
The decoder retains the arbitrary incoming PC and complete input state. -/
theorem x86_jit_push_bytes (state : X86.State) :
    X86.decode #[0x55] state = .ok (.push .w64 5 (state.pc + 1)) := by
  canonical_x86_decode

theorem x86_jit_frame_bytes (state : X86.State) :
    X86.decode #[0x48, 0x89, 0xe5] state =
      .ok (.move .w64 (.register (.low 5)) (.register (.low 4)) (state.pc + 3)) := by
  canonical_x86_decode

theorem x86_tail_pop_bytes (state : X86.State) :
    X86.decode #[0x58] state = .ok (.pop .w64 0 (state.pc + 1)) := by
  canonical_x86_decode

theorem x86_jit_ret_bytes (state : X86.State) :
    X86.decode #[0xc3] state = .ok (.returnNear 0 (state.pc + 1)) := by
  canonical_x86_decode

/-- Every emitted callee-save PUSH has this whole-state architectural effect.
The actual permission check precedes all SP, memory and PC changes. -/
theorem x86_jit_push (state : X86.State) (register : X86.Register) (next : Word)
    (permission : permitted state.memory.writable (state.gpr 4 - 8) 8 = true) :
    X86.step (.push .w64 register next) state =
      ⟨{ state with
          gpr := fun r => if r = 4 then state.gpr 4 - 8 else state.gpr r
          memory := storeMemory state.memory (state.gpr 4 - 8) (state.gpr register) 8
          pc := next },
        [.memory .write (state.gpr 4 - 8) (valueBytes (state.gpr register) 8) true], none⟩ := by
  simp only [X86.step, X86.pushTransfer, X86.StackWidth.bytes]
  have write := permission
  change permitted state.memory.writable (state.gpr 4 - (8#64)) 8 = true at write
  simp only [writeMemory, write, ite_true, List.nil_append]
  rfl

/-- MOV RBP,RSP keeps context, flags, SIMD and memory and samples old RSP. -/
theorem x86_jit_frame (state : X86.State) (next : Word) :
    X86.step (.move .w64 (.register (.low 5)) (.register (.low 4)) next) state =
      ⟨{ state with
          gpr := fun r => if r = 5 then state.gpr 4 else state.gpr r
          pc := next }, [], none⟩ := by
  simp +decide [X86.step, X86.moveStep, X86.scalarRead, X86.scalarRegisterValue,
    X86.scalarWrite, X86.scalarWriteValue, X86.RegisterSlice.reg, X86.RegisterSlice.shift,
    X86.ScalarWidth.bits, X86.ScalarWidth.bytes]

/-- The actual POP primitive includes its original ordered read, and allows
arbitrary saved values and register destinations, including RSP. -/
theorem x86_jit_pop (state : X86.State) (register : X86.Register) (value next : Word)
    (event : Event) (saved : readMemory state.memory (state.gpr 4) 8 = .ok (value, event)) :
    X86.step (.pop .w64 register next) state =
      ⟨{ state with
          gpr := fun r => if r = register then value
            else if r = 4 then state.gpr 4 + 8 else state.gpr r
          pc := next }, [event], none⟩ := by
  simp [X86.step, X86.readSource, X86.StackWidth.bytes, saved,
    X86.StackWidth.registerWidth, X86.cmovValue]

/-- Exact ARM result-move bytes emitted by build_epilogue. -/
theorem arm64_jit_result_bytes :
    AArch64.decode #[0xe0, 0x03, 0x07, 0xaa] = .ok (.moveRegister .w64 (.general 0) (.general 7)) := by
  rfl

/-- Actual A64_PUSH(FP,LR,SP) frame record, independent of the program. -/
def arm64PushFrame : AArch64.AddressedPairMemoryInstruction :=
  ⟨⟨.w64, false, 29, 30, 31, -16, by simp⟩, .pre, by decide⟩

def arm64PopFrame : AArch64.AddressedPairMemoryInstruction :=
  ⟨⟨.w64, true, 29, 30, 31, 16, by decide⟩, .post, by decide⟩

theorem arm64_jit_push_frame_bytes :
    AArch64.decode #[0xfd, 0x7b, 0xbf, 0xa9] = .ok (.addressedPairMemory arm64PushFrame) := by
  rfl

theorem arm64_jit_pop_frame_bytes :
    AArch64.decode #[0xfd, 0x7b, 0xc1, 0xa8] = .ok (.addressedPairMemory arm64PopFrame) := by
  rfl

/-- The decoded physical X7-to-X0 move realizes the result transport above. -/
theorem arm64_jit_result_move (state : AArch64.State) :
    AArch64.step (.moveRegister .w64 (.general 0) (.general 7)) state =
      ⟨{ arm64ResultMove state with pc := state.pc + 4 }, [], none⟩ := by
  simp [AArch64.step, AArch64.moveRegStep, AArch64.writeData, AArch64.readData,
    AArch64.narrow, AArch64.Width.bits, arm64ResultMove, Fin.ext_iff]

/-! ## RCU retention
Program-array exchange drops its old reference through prog_fd_array_put_ptr;
__bpf_prog_put_noref schedules call_rcu or call_rcu_tasks_trace. Grace-period
semantics supplies readEnd < reclaim for each observed object, with the same
read-side domain as the invocation. The allocator supplies immutable object
contents through reclaim, including executable bytes and attach metadata. -/

structure RetireInterval where
  observed : Nat
  readEnd : Nat
  reclaim : Nat
  ordered : observed ≤ readEnd
  grace : readEnd < reclaim

/-- Every target use inside the observing reader precedes reclamation. -/
theorem rcu_use_before_reclaim (interval : RetireInterval) (time : Nat)
    (inside : time ≤ interval.readEnd) : time < interval.reclaim :=
  Nat.lt_of_le_of_lt inside interval.grace

/-- A live pre-retirement object and the deferred-reclaim interval derive
S6's Retained predicate even while the program-array slot changes. -/
theorem rcu_derives_retained (interval : RetireInterval)
    (objects : Nat → Nat → Option TailCallBinding.Target) (target : TailCallBinding.Target)
    (immutable : ∀ time, interval.observed ≤ time → time < interval.reclaim →
      objects time target.identity = some target) :
    TailCallBinding.Retained objects target interval.observed interval.readEnd := by
  intro time lower upper
  exact immutable time lower (rcu_use_before_reclaim interval time upper)

/-- The selected object's complete payload follows the retained object,
independently of subsequent array updates or an address reused after grace. -/
theorem rcu_selected_payload {Payload : Type} (interval : RetireInterval)
    (payload : Nat → Nat → Option Payload) (object : Nat) (value : Payload)
    (immutable : ∀ time, interval.observed ≤ time → time < interval.reclaim →
      payload time object = some value)
    (time : Nat) (lower : interval.observed ≤ time) (upper : time ≤ interval.readEnd) :
    payload time object = some value :=
  immutable time lower (rcu_use_before_reclaim interval time upper)

/-! ## Typed helper resolver and effect lifetime
The executable resolver follows symbol-for-ID followed by symbol address.
Signature/provenance/effect contracts belong to the resolved kernel object,
including mapops aliases and attach-specific helper implementations. -/

inductive ArgType | word | u32 | pointer
  deriving DecidableEq

structure Pointer where
  address : Word
  object : Nat
  offset : Nat
  deriving DecidableEq

inductive TypedValue | word (bits : Word) | u32 (bits : BitVec 32) | pointer (value : Pointer)
  deriving DecidableEq

def typedBits : TypedValue → Word
  | .word bits => bits
  | .u32 bits => bits.setWidth 64
  | .pointer value => value.address

def typedKind : TypedValue → ArgType
  | .word _ => .word | .u32 _ => .u32 | .pointer _ => .pointer

structure Helper where
  identity : Word
  symbol : String
  address : Word
  signature : Fin 5 → ArgType

/-- The same helper descriptor is retained across the two resolver stages. -/
def resolve (byId : Word → Option Helper) (symbols : String → Option Word)
    (identity : Word) : Option Helper := do
  let helper ← byId identity
  let address ← symbols helper.symbol
  pure { helper with address := address }

theorem resolved_helper (byId : Word → Option Helper) (symbols : String → Option Word)
    (identity : Word) (helper : Helper)
    (registry : byId identity = some helper) (address : symbols helper.symbol = some helper.address) :
    resolve byId symbols identity = some helper := by
  simp [resolve, registry, address]

/-- Registry identity and type consistency are universal registry premises;
this theorem transports them through the actual two-stage resolver shape. -/
theorem resolver_identity_signature (byId : Word → Option Helper)
    (symbols : String → Option Word) (identity : Word) (helper resolved : Helper)
    (registry : byId identity = some helper) (canonical : helper.identity = identity)
    (selected : resolve byId symbols identity = some resolved) :
    resolved.identity = identity ∧ resolved.signature = helper.signature ∧
    symbols helper.symbol = some resolved.address := by
  cases address : symbols helper.symbol with
  | none => simp [resolve, registry, address] at selected
  | some bits =>
    have eq : some { helper with address := bits } = some resolved := by
      simpa [resolve, registry, address] using selected
    have selected := Option.some.inj eq
    cases selected
    exact ⟨canonical, rfl, rfl⟩

/-- Each pointer has its own capture-to-last-use lifetime. Consuming helpers
may release an object after that use. Scalar arguments retain their actual
bits, including explicit u32 coercion. -/
def ArgumentsLive (live : Nat → Nat → Nat → Word → Prop)
    (start : Nat) (lastUse : Fin 5 → Nat) (arguments : Fin 5 → TypedValue) : Prop :=
  ∀ i pointer, arguments i = .pointer pointer →
    ∀ time, start ≤ time → time ≤ lastUse i →
      live time pointer.object pointer.offset pointer.address

theorem typed_arguments_live (live : Nat → Nat → Nat → Word → Prop)
    (start time : Nat) (lastUse : Fin 5 → Nat) (arguments : Fin 5 → TypedValue)
    (retained : ArgumentsLive live start lastUse arguments)
    (i : Fin 5) (lower : start ≤ time) (upper : time ≤ lastUse i) (pointer : Pointer) (argument : arguments i = .pointer pointer) :
    live time pointer.object pointer.offset (typedBits (arguments i)) := by
  rw [argument]
  exact retained i pointer argument time lower upper

/-- Descriptor signatures constrain the same typed values on both ABIs. -/
def ArgumentsTyped (helper : Helper) (arguments : Fin 5 → TypedValue) : Prop :=
  ∀ i, typedKind (arguments i) = helper.signature i

theorem resolved_arguments_typed (byId : Word → Option Helper)
    (symbols : String → Option Word) (identity : Word) (helper resolved : Helper)
    (arguments : Fin 5 → TypedValue) (registry : byId identity = some helper)
    (canonical : helper.identity = identity)
    (selected : resolve byId symbols identity = some resolved)
    (typed : ArgumentsTyped helper arguments) : ArgumentsTyped resolved arguments := by
  have signature := (resolver_identity_signature byId symbols identity helper resolved
    registry canonical selected).2.1
  intro i
  rw [signature]
  exact typed i

/-- Independently retained pointer objects derive validity through each
argument last use, including aliases and consuming helper effects. The post-call
lifetime may differ from the pre-call lifetime. -/
theorem arguments_live_of_retention (live : Nat → Nat → Nat → Word → Prop)
    (start : Nat) (lastUse : Fin 5 → Nat) (arguments : Fin 5 → TypedValue)
    (interval : Fin 5 → RetireInterval)
    (begins : ∀ i, (interval i).observed ≤ start)
    (ends : ∀ i, lastUse i ≤ (interval i).readEnd)
    (objects : ∀ i pointer, arguments i = .pointer pointer →
      ∀ time, (interval i).observed ≤ time → time < (interval i).reclaim →
        live time pointer.object pointer.offset pointer.address) :
    ArgumentsLive live start lastUse arguments := by
  intro i pointer argument time lower upper
  exact objects i pointer argument time (Nat.le_trans (begins i) lower)
    (rcu_use_before_reclaim (interval i) time (Nat.le_trans upper (ends i)))

/-! ## Compiler CFG and owned private frame
A compiler simulation is universal over its input programs. Local instruction
correspondence includes private-slot disjointness, full saved value liveness,
address-register preservation and early-exit successors. Physical instruction
execution and effect erasure are part of the universal step relation. The theorem lifts this local compiler interface over
all finite prefixes, loops, branch successors and helper effects. -/

/-- Local compiler correspondence targets arbitrary decoded execution paths.
Silent administrative edges and multi-instruction expansions are both allowed. -/
structure CompilerCorrespondence {Source Machine : Type}
    (sourceStep : Source → List Event → Source → Prop)
    (machineStep : Machine → List Event → Machine → Prop)
    (related : Source → Machine → Prop) : Prop where
  localStep : ∀ {s m events next}, related s m → sourceStep s events next →
    ∃ final, SpillControl.Path machineStep m events final ∧ related next final

/-- Universal compiler block correspondence produces exact ordered decoded
runs for every source execution; each successor retains the private-frame relation. -/
theorem compiler_cfg_frame {Source Machine : Type}
    {sourceStep : Source → List Event → Source → Prop}
    {machineStep : Machine → List Event → Machine → Prop}
    {related : Source → Machine → Prop}
    (compiler : CompilerCorrespondence sourceStep machineStep related)
    {first last : Source} {machine : Machine} {events : List Event}
    (initial : related first machine) (run : SpillControl.Path sourceStep first events last) :
    ∃ final, SpillControl.Path machineStep machine events final ∧ related last final := by
  induction run generalizing machine with
  | refl state => exact ⟨machine, SpillControl.Path.refl machine, initial⟩
  | next step rest ih =>
    obtain ⟨middle, head, relation⟩ := compiler.localStep initial step
    obtain ⟨final, tail, finalRelation⟩ := ih relation
    exact ⟨final, head.append tail, finalRelation⟩

/-- Compiler and private spill/body/reload CFG correspondence compose; body
liveness and all physical byte/permission/effect premises remain in related.
This equation covers actual decoded early exits when localStep covers them. -/
theorem compiler_spill_cfg {Source Saved Machine : Type}
    (capture : Source → Saved) (body : Source → List Event → Source → Prop)
    (machineStep : Machine → List Event → Machine → Prop)
    (related : SpillControl.Phase Source Saved → Machine → Prop)
    (compiler : CompilerCorrespondence (SpillControl.Edge capture body) machineStep related)
    {first last : Source} {machine : Machine} {events : List Event}
    (initial : related (.entry first) machine) (run : SpillControl.Path body first events last) :
    ∃ final, SpillControl.Path machineStep machine events final ∧ related (.entry last) final :=
  compiler_cfg_frame compiler initial (SpillControl.path_lifts capture body run)

end KProgFormal.ControlABI

#print axioms KProgFormal.ControlABI.x86_physical_return
#print axioms KProgFormal.ControlABI.arm64_jit_result
#print axioms KProgFormal.ControlABI.rcu_derives_retained
#print axioms KProgFormal.ControlABI.resolver_identity_signature
#print axioms KProgFormal.ControlABI.compiler_spill_cfg

namespace KProgFormal.ControlABI.InvocationExit
open Reference

/-- The exact existing x86 C exit predicate, in its emitted register order. -/
def x86Reject (snapshot raw : X86.Register → Reference.Word) (tags : X86.Register → Reference.Byte)
    (sp : Reference.Word) : Bool :=
  tags 3 != 0 || raw 3 != snapshot 3 || tags 5 != 0 || raw 5 != snapshot 5 ||
  tags 12 != 0 || raw 12 != snapshot 12 || tags 13 != 0 || raw 13 != snapshot 13 ||
  tags 14 != 0 || raw 14 != snapshot 14 || tags 15 != 0 || raw 15 != snapshot 15 || sp != 0

/-- The exact existing ARM C exit predicate, including X29 and raw SP. -/
def arm64Reject (snapshot raw : AArch64.Gpr → Reference.Word) (tags : AArch64.Gpr → Reference.Byte)
    (sp : Reference.Word) : Bool :=
  tags 19 != 0 || raw 19 != snapshot 19 || tags 20 != 0 || raw 20 != snapshot 20 ||
  tags 21 != 0 || raw 21 != snapshot 21 || tags 22 != 0 || raw 22 != snapshot 22 ||
  tags 23 != 0 || raw 23 != snapshot 23 || tags 24 != 0 || raw 24 != snapshot 24 ||
  tags 25 != 0 || raw 25 != snapshot 25 || tags 26 != 0 || raw 26 != snapshot 26 ||
  tags 27 != 0 || raw 27 != snapshot 27 || tags 28 != 0 || raw 28 != snapshot 28 ||
  tags 29 != 0 || raw 29 != snapshot 29 || sp != 0

def x86Contract (snapshot raw : X86.Register → Reference.Word) (tags : X86.Register → Reference.Byte)
    (sp : Reference.Word) : Prop :=
  sp = 0 ∧ ∀ r, x86Callee r → tags r = 0 ∧ raw r = snapshot r

def arm64Contract (snapshot raw : AArch64.Gpr → Reference.Word) (tags : AArch64.Gpr → Reference.Byte)
    (sp : Reference.Word) : Prop :=
  sp = 0 ∧ ∀ r, arm64Callee r → tags r = 0 ∧ raw r = snapshot r

theorem x86_callee_cases (r : X86.Register) :
    x86Callee r ↔ r = 3 ∨ r = 5 ∨ r = 12 ∨ r = 13 ∨ r = 14 ∨ r = 15 := by
  simp only [x86Callee, List.mem_cons, List.mem_singleton, List.not_mem_nil, or_false, Fin.ext_iff]
  change (r.val = 3 ∨ r.val = 5 ∨ r.val = 12 ∨ r.val = 13 ∨ r.val = 14 ∨ r.val = 15) ↔
    (r.val = 3 ∨ r.val = 5 ∨ r.val = 12 ∨ r.val = 13 ∨ r.val = 14 ∨ r.val = 15)
  rfl

theorem arm64_callee_cases (r : AArch64.Gpr) :
    arm64Callee r ↔ r = 19 ∨ r = 20 ∨ r = 21 ∨ r = 22 ∨ r = 23 ∨ r = 24 ∨
      r = 25 ∨ r = 26 ∨ r = 27 ∨ r = 28 ∨ r = 29 := by
  simp only [arm64Callee, Fin.ext_iff]
  omega

theorem x86_accepted_iff (snapshot raw : X86.Register → Reference.Word)
    (tags : X86.Register → Reference.Byte) (sp : Reference.Word) :
    x86Reject snapshot raw tags sp = false ↔ x86Contract snapshot raw tags sp := by
  constructor
  · intro accepted
    simp only [x86Reject, Bool.or_eq_false_iff, bne_eq_false_iff_eq, and_assoc] at accepted
    rcases accepted with ⟨t3, v3,t5, v5,t12, v12,t13, v13,t14, v14,t15, v15, stack⟩
    constructor
    · exact stack
    · intro r saved
      rcases (x86_callee_cases r).mp saved with rfl | rfl | rfl | rfl | rfl | rfl
      · exact ⟨t3, v3⟩
      · exact ⟨t5, v5⟩
      · exact ⟨t12, v12⟩
      · exact ⟨t13, v13⟩
      · exact ⟨t14, v14⟩
      · exact ⟨t15, v15⟩
  · intro contract
    simp only [x86Reject, Bool.or_eq_false_iff, bne_eq_false_iff_eq, and_assoc]
    exact ⟨(contract.2 3 (by decide)).1, (contract.2 3 (by decide)).2, (contract.2 5 (by decide)).1, (contract.2 5 (by decide)).2, (contract.2 12 (by decide)).1, (contract.2 12 (by decide)).2, (contract.2 13 (by decide)).1, (contract.2 13 (by decide)).2, (contract.2 14 (by decide)).1, (contract.2 14 (by decide)).2, (contract.2 15 (by decide)).1, (contract.2 15 (by decide)).2, contract.1⟩

instance x86ContractDecidable (snapshot raw : X86.Register → Reference.Word)
    (tags : X86.Register → Reference.Byte) (sp : Reference.Word) :
    Decidable (x86Contract snapshot raw tags sp) :=
  if accepted : x86Reject snapshot raw tags sp = false then
    isTrue ((x86_accepted_iff _ _ _ _).mp accepted)
  else isFalse (fun contract => accepted ((x86_accepted_iff _ _ _ _).mpr contract))

theorem arm64_accepted_iff (snapshot raw : AArch64.Gpr → Reference.Word)
    (tags : AArch64.Gpr → Reference.Byte) (sp : Reference.Word) :
    arm64Reject snapshot raw tags sp = false ↔ arm64Contract snapshot raw tags sp := by
  constructor
  · intro accepted
    simp only [arm64Reject, Bool.or_eq_false_iff, bne_eq_false_iff_eq, and_assoc] at accepted
    rcases accepted with ⟨t19, v19,t20, v20,t21, v21,t22, v22,t23, v23,t24, v24,t25, v25,t26, v26,t27, v27,t28, v28,t29, v29, stack⟩
    constructor
    · exact stack
    · intro r saved
      rcases (arm64_callee_cases r).mp saved with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
      · exact ⟨t19, v19⟩
      · exact ⟨t20, v20⟩
      · exact ⟨t21, v21⟩
      · exact ⟨t22, v22⟩
      · exact ⟨t23, v23⟩
      · exact ⟨t24, v24⟩
      · exact ⟨t25, v25⟩
      · exact ⟨t26, v26⟩
      · exact ⟨t27, v27⟩
      · exact ⟨t28, v28⟩
      · exact ⟨t29, v29⟩
  · intro contract
    simp only [arm64Reject, Bool.or_eq_false_iff, bne_eq_false_iff_eq, and_assoc]
    exact ⟨(contract.2 19 (by decide)).1, (contract.2 19 (by decide)).2, (contract.2 20 (by decide)).1, (contract.2 20 (by decide)).2, (contract.2 21 (by decide)).1, (contract.2 21 (by decide)).2, (contract.2 22 (by decide)).1, (contract.2 22 (by decide)).2, (contract.2 23 (by decide)).1, (contract.2 23 (by decide)).2, (contract.2 24 (by decide)).1, (contract.2 24 (by decide)).2, (contract.2 25 (by decide)).1, (contract.2 25 (by decide)).2, (contract.2 26 (by decide)).1, (contract.2 26 (by decide)).2, (contract.2 27 (by decide)).1, (contract.2 27 (by decide)).2, (contract.2 28 (by decide)).1, (contract.2 28 (by decide)).2, (contract.2 29 (by decide)).1, (contract.2 29 (by decide)).2, contract.1⟩

instance arm64ContractDecidable (snapshot raw : AArch64.Gpr → Reference.Word)
    (tags : AArch64.Gpr → Reference.Byte) (sp : Reference.Word) :
    Decidable (arm64Contract snapshot raw tags sp) :=
  if accepted : arm64Reject snapshot raw tags sp = false then
    isTrue ((arm64_accepted_iff _ _ _ _).mp accepted)
  else isFalse (fun contract => accepted ((arm64_accepted_iff _ _ _ _).mpr contract))

/-- Both branches retain the complete C state, including arbitrary memory,
register metadata, fresh inputs and caller-owned ghost fields. -/
inductive Result (State : Type) where
  | fault (state : State)
  | returned (value : BitVec 32) (state : State)

def body {State : Type} (reject : Bool) (value : Reference.Word) (state : State) : Result State :=
  if reject then .fault state else .returned (value.setWidth 32) state

theorem x86_body_contract {State : Type} (snapshot raw : X86.Register → Reference.Word)
    (tags : X86.Register → Reference.Byte) (sp value : Reference.Word) (state : State) :
    body (x86Reject snapshot raw tags sp) value state =
      if x86Contract snapshot raw tags sp then .returned (value.setWidth 32) state else .fault state := by
  by_cases accepted : x86Reject snapshot raw tags sp = false
  · have contract := (x86_accepted_iff snapshot raw tags sp).mp accepted
    simp only [body, accepted, Bool.false_eq_true, ↓reduceIte, contract]
  · have rejected : x86Reject snapshot raw tags sp = true := by
      cases h : x86Reject snapshot raw tags sp <;> simp_all
    have contract := mt (x86_accepted_iff snapshot raw tags sp).mpr accepted
    simp only [body, rejected, ↓reduceIte, contract]

theorem arm64_body_contract {State : Type} (snapshot raw : AArch64.Gpr → Reference.Word)
    (tags : AArch64.Gpr → Reference.Byte) (sp value : Reference.Word) (state : State) :
    body (arm64Reject snapshot raw tags sp) value state =
      if arm64Contract snapshot raw tags sp then .returned (value.setWidth 32) state else .fault state := by
  by_cases accepted : arm64Reject snapshot raw tags sp = false
  · have contract := (arm64_accepted_iff snapshot raw tags sp).mp accepted
    simp only [body, accepted, Bool.false_eq_true, ↓reduceIte, contract]
  · have rejected : arm64Reject snapshot raw tags sp = true := by
      cases h : arm64Reject snapshot raw tags sp <;> simp_all
    have contract := mt (arm64_accepted_iff snapshot raw tags sp).mpr accepted
    simp only [body, rejected, ↓reduceIte, contract]

/-- A normal modeled C return derives the ABI predicate and retains the
exact uint32 value and complete frame; the guard is obtained from the outcome. -/
theorem x86_returned_contract {State : Type} (snapshot raw : X86.Register → Reference.Word)
    (tags : X86.Register → Reference.Byte) (sp value : Reference.Word) (state final : State)
    (output : BitVec 32)
    (returned : body (x86Reject snapshot raw tags sp) value state = .returned output final) :
    x86Contract snapshot raw tags sp ∧ output = value.setWidth 32 ∧ final = state := by
  have accepted : x86Reject snapshot raw tags sp = false := by
    cases decision : x86Reject snapshot raw tags sp with
    | false => rfl
    | true => simp [body, decision] at returned
  have fields : Result.returned (value.setWidth 32) state = Result.returned output final := by
    simpa [body, accepted] using returned
  have pair := Result.returned.inj fields
  exact ⟨(x86_accepted_iff _ _ _ _).mp accepted, pair.1.symm, pair.2.symm⟩

/-- A normal modeled C return derives the ABI predicate and retains the
exact uint32 value and complete frame; the guard is obtained from the outcome. -/
theorem arm64_returned_contract {State : Type} (snapshot raw : AArch64.Gpr → Reference.Word)
    (tags : AArch64.Gpr → Reference.Byte) (sp value : Reference.Word) (state final : State)
    (output : BitVec 32)
    (returned : body (arm64Reject snapshot raw tags sp) value state = .returned output final) :
    arm64Contract snapshot raw tags sp ∧ output = value.setWidth 32 ∧ final = state := by
  have accepted : arm64Reject snapshot raw tags sp = false := by
    cases decision : arm64Reject snapshot raw tags sp with
    | false => rfl
    | true => simp [body, decision] at returned
  have fields : Result.returned (value.setWidth 32) state = Result.returned output final := by
    simpa [body, accepted] using returned
  have pair := Result.returned.inj fields
  exact ⟨(arm64_accepted_iff _ _ _ _).mp accepted, pair.1.symm, pair.2.symm⟩

/-- Accepted source cells derive the complete native callee-save relation.
The tag projection and entry snapshot/origin are explicit representation inputs. -/
theorem x86_source_exit (env : Refinement.EntryEnvironment.Environment)
    (frame : Refinement.EntryEnvironment.Frame) (arena : Reference.Word)
    (snapshot : X86.Register → Reference.Word) (tags : X86.Register → Reference.Byte)
    (raw : Refinement.X86NumericAddress.RegisterState) (entry : X86.State)
    (entryStack : entry.gpr 4 = Refinement.EntryEnvironment.base env frame .stack)
    (entryRegisters : ∀ r, x86Callee r → entry.gpr r = snapshot r)
    (tagProjection : ∀ r, raw.stack r = (tags r == 4))
    (accepted : x86Reject snapshot raw.raw.gpr tags (raw.raw.gpr 4) = false) :
    x86Exit entry (Refinement.X86NumericAddress.nativeRegisters env frame arena raw) := by
  have contract := (x86_accepted_iff _ _ _ _).mp accepted
  constructor
  · change raw.raw.gpr 4 + Refinement.EntryEnvironment.base env frame .stack = entry.gpr 4
    simpa [contract.1, Reference.Word] using entryStack.symm
  · intro r saved
    have scalar := (contract.2 r saved).1
    have bits := (contract.2 r saved).2
    have regular : r ≠ 4 := by
      have values : r.val = 3 ∨ r.val = 5 ∨ r.val = 12 ∨ r.val = 13 ∨ r.val = 14 ∨ r.val = 15 := by
        simpa only [x86Callee, List.mem_cons, List.mem_singleton, List.not_mem_nil, or_false] using saved
      intro eq
      have index : r.val = 4 := congrArg Fin.val eq
      omega
    have tag : raw.stack r = false := by rw [tagProjection, scalar]; rfl
    change Refinement.X86NumericAddress.registerValue env frame arena raw r = entry.gpr r
    simp only [Refinement.X86NumericAddress.registerValue, regular, ↓reduceIte, tag,
      Bool.false_eq_true]
    exact bits.trans (entryRegisters r saved).symm

/-- Source raw SP is an offset from the entered native stack origin. All
other architectural fields, including memory/flags/LR, retain their raw image. -/
def arm64Native (origin : Reference.Word) (raw : AArch64.State) : AArch64.State :=
  { raw with sp := raw.sp + origin }

theorem arm64_source_exit (snapshot : AArch64.Gpr → Reference.Word)
    (tags : AArch64.Gpr → Reference.Byte) (origin : Reference.Word) (raw entry : AArch64.State)
    (entryStack : entry.sp = origin)
    (entryRegisters : ∀ r, arm64Callee r → entry.gpr r = snapshot r)
    (accepted : arm64Reject snapshot raw.gpr tags raw.sp = false) :
    arm64Exit entry (arm64Native origin raw) := by
  have contract := (arm64_accepted_iff _ _ _ _).mp accepted
  constructor
  · change raw.sp + origin = entry.sp
    simpa [contract.1, Reference.Word] using entryStack.symm
  · intro r saved
    exact (contract.2 r saved).2.trans (entryRegisters r saved).symm

/-- The actual source exit condition supplies the previously separate ABI
premise of the physical x86 return law, for every input/program prefix. -/
theorem x86_source_physical_return (env : Refinement.EntryEnvironment.Environment)
    (frame : Refinement.EntryEnvironment.Frame) (arena : Reference.Word)
    (snapshot : X86.Register → Reference.Word) (tags : X86.Register → Reference.Byte)
    (raw : Refinement.X86NumericAddress.RegisterState) (entry : X86.State)
    (target ignored : Reference.Word) (event : Event)
    (entryStack : entry.gpr 4 = Refinement.EntryEnvironment.base env frame .stack)
    (entryRegisters : ∀ r, x86Callee r → entry.gpr r = snapshot r)
    (tagProjection : ∀ r, raw.stack r = (tags r == 4))
    (accepted : x86Reject snapshot raw.raw.gpr tags (raw.raw.gpr 4) = false)
    (saved : readMemory raw.raw.memory
      ((Refinement.X86NumericAddress.nativeRegisters env frame arena raw).gpr 4) 8 = .ok (target, event))
    (canonical : X86.canonicalTarget raw.raw.addressWidth target = true) :
    let body := Refinement.X86NumericAddress.nativeRegisters env frame arena raw
    X86.step (.returnNear 0 ignored) (x86Restore entry body) =
      ⟨{ body with
          gpr := fun r => if r = 4 then body.gpr 4 + 8 else body.gpr r
          pc := target }, [event], none⟩ := by
  exact x86_physical_return entry _ target ignored event
    (x86_source_exit env frame arena snapshot tags raw entry entryStack entryRegisters tagProjection accepted)
    saved canonical

/-- The source ARM condition also supplies the JIT return law's complete
callee/SP premise; saved LR and actual result-register binding remain explicit. -/
theorem arm64_source_jit_result (snapshot : AArch64.Gpr → Reference.Word)
    (tags : AArch64.Gpr → Reference.Byte) (origin outer : Reference.Word) (raw entry : AArch64.State)
    (entryStack : entry.sp = origin)
    (entryRegisters : ∀ r, arm64Callee r → entry.gpr r = snapshot r)
    (accepted : arm64Reject snapshot raw.gpr tags raw.sp = false)
    (saved : raw.gpr 30 = outer) :
    AArch64.step (.branchRegister false 30)
      (arm64ResultMove (arm64Restore entry (arm64Native origin raw))) =
      ⟨{ arm64ResultMove (arm64Native origin raw) with pc := outer }, [], none⟩ ∧
    ((arm64ResultMove (arm64Native origin raw)).gpr 0).setWidth 32 =
      (raw.gpr 7).setWidth 32 := by
  exact arm64_jit_result entry _ outer
    (arm64_source_exit snapshot tags origin raw entry entryStack entryRegisters accepted) saved

end KProgFormal.ControlABI.InvocationExit
