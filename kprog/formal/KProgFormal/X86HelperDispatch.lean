import KProgFormal.Generated.GeneratedX86HelperDispatch
import KProgFormal.X86CallMemHandler

namespace KProgFormal

open GeneratedX86HelperDispatch (helperCount idBits helperIds helperNames
  helperBodies defaultBody slotOf idOfSlot nameOfSlot slotOfName)

/-- Independent Linux IDs, in increasing order, checked against public libbpf declarations. -/
def x86HelperDispatchIdsSpec : List Nat :=
  [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15, 16, 20, 21, 23, 25, 26, 27, 28, 32, 35, 36, 37, 38, 39, 43, 44, 45, 46, 50, 54, 58, 65, 67, 68, 69, 80, 85, 86, 87, 88, 95, 99, 105, 109, 112, 113, 114, 115, 118, 122, 124, 125, 130, 148, 152, 155, 158, 160, 163, 173, 174, 175, 181, 184, 189, 193]

/-- Independent names in Linux numeric ID order. -/
def x86HelperDispatchNamesSpec : List String :=
  ["bpf_map_lookup_elem",
   "bpf_map_update_elem",
   "bpf_map_delete_elem",
   "bpf_probe_read",
   "bpf_ktime_get_ns",
   "bpf_trace_printk",
   "bpf_get_prandom_u32",
   "bpf_get_smp_processor_id",
   "bpf_skb_store_bytes",
   "bpf_l3_csum_replace",
   "bpf_l4_csum_replace",
   "bpf_tail_call",
   "bpf_get_current_pid_tgid",
   "bpf_get_current_uid_gid",
   "bpf_get_current_comm",
   "bpf_skb_get_tunnel_key",
   "bpf_skb_set_tunnel_key",
   "bpf_redirect",
   "bpf_perf_event_output",
   "bpf_skb_load_bytes",
   "bpf_get_stackid",
   "bpf_csum_diff",
   "bpf_skb_change_type",
   "bpf_get_current_task",
   "bpf_probe_write_user",
   "bpf_current_task_under_cgroup",
   "bpf_skb_change_tail",
   "bpf_skb_pull_data",
   "bpf_skb_change_head",
   "bpf_xdp_adjust_head",
   "bpf_probe_read_str",
   "bpf_get_socket_cookie",
   "bpf_skb_adjust_room",
   "bpf_xdp_adjust_meta",
   "bpf_override_return",
   "bpf_xdp_adjust_tail",
   "bpf_get_stack",
   "bpf_skb_load_bytes_relative",
   "bpf_fib_lookup",
   "bpf_get_current_cgroup_id",
   "bpf_sk_lookup_udp",
   "bpf_sk_release",
   "bpf_map_push_elem",
   "bpf_map_pop_elem",
   "bpf_sk_fullsock",
   "bpf_skc_lookup_tcp",
   "bpf_strtol",
   "bpf_send_signal",
   "bpf_probe_read_user",
   "bpf_probe_read_kernel",
   "bpf_probe_read_user_str",
   "bpf_probe_read_kernel_str",
   "bpf_jiffies64",
   "bpf_get_netns_cookie",
   "bpf_sk_assign",
   "bpf_ktime_get_boot_ns",
   "bpf_ringbuf_output",
   "bpf_copy_from_user",
   "bpf_redirect_neigh",
   "bpf_redirect_peer",
   "bpf_get_current_task_btf",
   "bpf_ktime_get_coarse_ns",
   "bpf_check_mtu",
   "bpf_get_func_ip",
   "bpf_get_attach_cookie",
   "bpf_task_pt_regs",
   "bpf_loop",
   "bpf_get_func_ret",
   "bpf_xdp_load_bytes",
   "bpf_ima_file_hash"]

/-- Independent statement of the armed body macros, built from the literal
`X86_SIM_BPF_CALL_` prefix rather than the generated literal table. -/
def x86HelperDispatchBodiesSpec : List String :=
  x86HelperDispatchNamesSpec.map (fun n => "X86_SIM_BPF_CALL_" ++ n)

/-- The independent sparse ID-to-slot lookup. Unarmed IDs name no slot. -/
def x86HelperDispatchSlotOfSpec (id : BitVec 64) : Option Nat :=
  (x86HelperDispatchIdsSpec.zip (List.range x86HelperDispatchIdsSpec.length)).lookup id.toNat

/-- Generated IDs equal the independent sparse Linux table. -/
theorem x86_helper_dispatch_ids_refine :
    helperIds = x86HelperDispatchIdsSpec := by
  unfold helperIds x86HelperDispatchIdsSpec
  native_decide

/-- The generated armed-id table is strictly increasing, so the ladder cannot
alias two helper ids to one slot. -/
theorem x86_helper_dispatch_ids_strict_mono :
    (helperIds.zip helperIds.tail).all (fun p => p.1 < p.2) = true := by
  unfold helperIds
  native_decide

/-- The generated armed-name table equals the independent literal helper-name
order, so slot `i` names the `i`-th armed BPF helper. -/
theorem x86_helper_dispatch_names_refine :
    helperNames = x86HelperDispatchNamesSpec := by
  unfold helperNames x86HelperDispatchNamesSpec
  native_decide

/-- The generated armed-body table equals the independent literal
`X86_SIM_BPF_CALL_bpf_*` construction, so each slot invokes the body the ladder
names. -/
theorem x86_helper_dispatch_bodies_refine :
    helperBodies = x86HelperDispatchBodiesSpec := by
  unfold helperBodies x86HelperDispatchBodiesSpec x86HelperDispatchNamesSpec
  native_decide

/-- The generated armed-id table has exactly `helperCount` entries. -/
theorem x86_helper_dispatch_ids_length :
    helperIds.length = helperCount := rfl

/-- The generated armed-name table has exactly `helperCount` entries, so every
armed helper has a name and no name is orphaned. -/
theorem x86_helper_dispatch_names_length :
    helperNames.length = helperCount := rfl

/-- The generated body table has exactly `helperCount` entries, so every armed
helper has a body and no body is orphaned. -/
theorem x86_helper_dispatch_bodies_length :
    helperBodies.length = helperCount := rfl

/-- The armed helper ids are distinct, so no two ladder arms share an id. -/
theorem x86_helper_dispatch_ids_nodup : helperIds.Nodup := by
  unfold helperIds
  native_decide

/-- Generated lookup agrees for every64-bit ID, including gaps. -/
theorem x86_helper_dispatch_slotof_refines (id : BitVec 64) :
    slotOf id = x86HelperDispatchSlotOfSpec id := by
  unfold slotOf x86HelperDispatchSlotOfSpec helperCount
  rw [x86_helper_dispatch_ids_refine]
  rfl

/-- The helper-id width is the 64-bit width the sim decodes, pinned so the C
`__u64` helper id and the generated `idBits` cannot drift apart. -/
theorem x86_helper_dispatch_bits_is_64 : idBits = 64 := rfl

/-- The first armed helper (`bpf_map_lookup_elem`) dispatches to slot `0`. -/
theorem x86_helper_dispatch_slot_lookup : slotOf (1 : BitVec 64) = some 0 := by
  native_decide

/-- Linux ktime helper5 has slot4, independently of its numeric ID. -/
theorem x86_helper_dispatch_slot_ktime : slotOf (5 : BitVec 64) = some 4 := by
  native_decide

/-- Linux ID13 is outside the armed set and must not dispatch to another helper. -/
theorem x86_helper_dispatch_first_unarmed_is_none :
    slotOf (13 : BitVec 64) = none := by
  native_decide

/-- ID194 is outside the armed set and must reach the failure arm. -/
theorem x86_helper_dispatch_last_named_is_none :
    slotOf (194 : BitVec 64) = none := by
  native_decide

/-- Helper id `0` names no armed slot, so the zero id also reaches the default
arm. -/
theorem x86_helper_dispatch_zero_is_none : slotOf (0 : BitVec 64) = none := by
  native_decide

/-- Every armed ID round-trips to its own slot; zero, gaps and out-of-set IDs name none. -/
theorem x86_helper_dispatch_full_range :
    ((List.range helperCount).all
        (fun i => slotOf (BitVec.ofNat 64 (x86HelperDispatchIdsSpec.getD i 0)) = some i)) = true ∧
      (slotOf (0 : BitVec 64) = none) ∧
      (slotOf (13 : BitVec 64) = none) ∧
      (slotOf (194 : BitVec 64) = none) ∧
      (slotOf (22 : BitVec 64) = none) := by
  refine ⟨?_, ?_, ?_, ?_, ?_⟩ <;> native_decide

/-- Every armed helper name maps back to its slot and every slot maps back to
its name, so the name -> slot lookup inverts the slot -> name lookup over the
whole table. -/
theorem x86_helper_dispatch_name_slot_roundtrip :
    helperIds.length = helperNames.length ∧
      (helperNames.zip (List.range helperCount)).all
        (fun p => slotOfName p.1 = some p.2) = true ∧
      (helperNames.zip (List.range helperCount)).all
        (fun p => nameOfSlot p.2 = some p.1) = true := by
  refine ⟨rfl, ?_, ?_⟩ <;> native_decide

/-- The armed count is68. The legacy theorem name is retained for compatibility. -/
theorem x86_helper_dispatch_count_is_7 : helperCount = 70 := rfl

/-- The default is a compile-time error. The legacy theorem name is retained. -/
theorem x86_helper_dispatch_default_is_rax_zero :
    defaultBody = "X86_SIM_L_UNSUPPORTED_HELPER()" := rfl

/-- Every armed slot's id is nonzero, so no armed id collides with the zero id
that also reaches the default arm. -/
theorem x86_helper_dispatch_ids_nonzero :
    helperIds.all (fun n => n != 0) = true := by
  unfold helperIds
  native_decide

/-- Armed IDs are a sparse subset of the Linux ID interval through193. -/
theorem x86_helper_dispatch_armed_is_strict_subset :
    helperIds.all (fun n => n < 194) = true ∧ helperCount < 194 := by
  refine ⟨?_, ?_⟩ <;> native_decide

/-- Slot `i` names a helper id that, read back, names slot `i`: the id and slot
tables invert each other over the armed range, so the ladder cannot dispatch an
id to a body whose slot disagrees with its id. -/
theorem x86_helper_dispatch_id_slot_roundtrip :
    (List.range helperCount).all
        (fun i =>
          (idOfSlot i).bind (fun n => slotOf (BitVec.ofNat 64 n)) =
            some i) = true := by
  unfold idOfSlot helperIds helperCount
  native_decide

/-- Both armed and unarmed dispatch shapes are reachable at their real Linux IDs. -/
theorem x86_helper_dispatch_case_dispatch :
    slotOf (1 : BitVec 64) = some 0 ∧
      slotOf (5 : BitVec 64) = some 4 ∧
      slotOf (0 : BitVec 64) = none ∧
      slotOf (13 : BitVec 64) = none ∧
      slotOf (194 : BitVec 64) = none := by
  refine ⟨?_, ?_, ?_, ?_, ?_⟩ <;> native_decide

/-- Independent routed body selection over sparse IDs, with an error default. -/
def x86HelperDispatchRoutedBodySpec (id : BitVec 64) : String :=
  match x86HelperDispatchSlotOfSpec id with
  | some i => x86HelperDispatchBodiesSpec.getD i defaultBody
  | none => defaultBody

/-- Sparse IDs select distinct case labels, in table order. -/
theorem x86_helper_dispatch_route_labels_distinct :
    (x86HelperDispatchIdsSpec.map
        (fun n => slotOf (BitVec.ofNat 64 n))) =
      (List.range helperCount).map some ∧
      (List.range helperCount).Nodup := by
  refine ⟨?_, ?_⟩ <;> native_decide

/-- Each armed ID selects its table slot, without assuming ID equals slot plus one. -/
theorem x86_helper_dispatch_route_case_is_index :
    (List.range helperCount).all
        (fun i => slotOf (BitVec.ofNat 64 (x86HelperDispatchIdsSpec.getD i 0)) = some i) = true := by
  native_decide

/-- No armed ID falls through to the failure default. -/
theorem x86_helper_dispatch_route_armed_never_default :
    (List.range helperCount).all
        (fun i => slotOf (BitVec.ofNat 64 (x86HelperDispatchIdsSpec.getD i 0)) ≠ none) = true := by
  native_decide

/-- Each armed ID invokes its own body, while gaps and out-of-set IDs invoke the error default. -/
theorem x86_helper_dispatch_route_body_refines :
    (List.range helperCount).all
        (fun i => x86HelperDispatchRoutedBodySpec (BitVec.ofNat 64 (x86HelperDispatchIdsSpec.getD i 0)) =
          x86HelperDispatchBodiesSpec.getD i defaultBody) = true ∧
      x86HelperDispatchRoutedBodySpec (0 : BitVec 64) = defaultBody ∧
      x86HelperDispatchRoutedBodySpec (13 : BitVec 64) = defaultBody ∧
      x86HelperDispatchRoutedBodySpec (194 : BitVec 64) = defaultBody ∧
      x86HelperDispatchRoutedBodySpec (22 : BitVec 64) = defaultBody := by
  refine ⟨?_, ?_, ?_, ?_, ?_⟩ <;> native_decide

/-- Map lookup and ktime invoke their correct bodies at their sparse table slots. -/
theorem x86_helper_dispatch_route_body_is_table :
    x86HelperDispatchBodiesSpec.getD 0 defaultBody =
        "X86_SIM_BPF_CALL_bpf_map_lookup_elem" ∧
      x86HelperDispatchBodiesSpec.getD 4 defaultBody =
        "X86_SIM_BPF_CALL_bpf_ktime_get_ns" := by
  refine ⟨?_, ?_⟩ <;> native_decide



namespace X86HelperBody
abbrev Word := Reference.Word
open Reference
open Refinement.X86NumericAddress
open X86CallMemBody

/-- A returning helper's externally observable effect. Typed argument capture,
helper identity, physical memory and helper ABI supply this interface. Successful
tail transfers use the link-step interface instead of this returning path. -/
structure Effect where
  value : Word
  resultTag : Byte
  memory : Memory
  events : List Event

/-- The operation receives the complete frame before RAX and caller writes.
This interface retains every helper-visible memory effect and ordered event. -/
abbrev Environment := Word → Frame → Effect

structure Observation where
  frame : Frame
  events : List Event

/-- Extracted wrapper order: apply the helper memory effect, write the result,
consume sixteen caller words, then advance the simulated PC. -/
def generatedReturn (s : Frame) (effect : Effect) (fresh : Fresh)
    (nextPc : Word) : Observation :=
  let written := { s with registers := { s.registers with raw :=
    { s.registers.raw with memory := effect.memory } } }
  let result := generatedClobbers (rawWrite written 0 effect.value effect.resultTag) fresh
  ⟨{ result with registers := registerPc result.registers nextPc }, effect.events⟩

/-- Independent ABI observation: helper memory/result, independent caller-frame
replacement, and the supplied continuation. All other state is retained. -/
def returnSpec (s : Frame) (effect : Effect) (fresh : Fresh)
    (nextPc : Word) : Observation :=
  let written := { s with registers := { s.registers with raw :=
    { s.registers.raw with memory := effect.memory } } }
  let result := clobbersSpec (rawWrite written 0 effect.value effect.resultTag) fresh
  ⟨{ result with registers := registerPc result.registers nextPc }, effect.events⟩

theorem returning_helper_frame (s : Frame) (effect : Effect) (fresh : Fresh)
    (nextPc : Word) : generatedReturn s effect fresh nextPc =
      returnSpec s effect fresh nextPc := by
  simp only [generatedReturn, returnSpec, helper_clobbers_frame]

/-- Every selected slot carries the original full-width Linux ID. -/
theorem routed_id_identity (id : Word) (slot : Nat)
    (selected : GeneratedX86HelperDispatch.slotOf id = some slot) :
    GeneratedX86HelperDispatch.idOfSlot slot = some id.toNat := by
  change (GeneratedX86HelperDispatch.helperIds.zip
    (List.range GeneratedX86HelperDispatch.helperCount)).lookup id.toNat = some slot at selected
  obtain ⟨before, after, equation, _⟩ := List.lookup_eq_some_iff.mp selected
  have member : (id.toNat, slot) ∈ GeneratedX86HelperDispatch.helperIds.zip
      (List.range GeneratedX86HelperDispatch.helperCount) := by
    rw [equation]
    simp
  obtain ⟨i, bound, atIndex⟩ := List.mem_iff_getElem.mp member
  have indexed := List.getElem?_eq_some_iff.mpr ⟨bound, atIndex⟩
  obtain ⟨identifier, index⟩ := List.getElem?_zip_eq_some.mp indexed
  obtain ⟨rangeBound, rangeValue⟩ := List.getElem?_eq_some_iff.mp index
  have same : i = slot := by simpa using rangeValue
  subst slot
  exact identifier

/-- A slot selects its Linux helper ID through the generated table. -/
def generatedCall (helpers : Environment) (s : Frame) (id : Word)
    (fresh : Fresh) (nextPc : Word) : Option Observation := do
  let slot ← GeneratedX86HelperDispatch.slotOf id
  let linuxId ← GeneratedX86HelperDispatch.idOfSlot slot
  pure (generatedReturn s (helpers (BitVec.ofNat 64 linuxId) s) fresh nextPc)

/-- Argument capture uses the original frame and exact helper ID for every
64-bit request whose case is selected. Caller replacement happens afterward. -/
theorem selected_helper_observation (helpers : Environment) (s : Frame) (id : Word)
    (slot : Nat) (selected : GeneratedX86HelperDispatch.slotOf id = some slot)
    (fresh : Fresh) (nextPc : Word) :
    generatedCall helpers s id fresh nextPc =
      some (returnSpec s (helpers id s) fresh nextPc) := by
  simp [generatedCall, selected, routed_id_identity id slot selected,
    returning_helper_frame]

/-- Result, memory, events and continuation survive the caller-frame update. -/
theorem returning_helper_observations (s : Frame) (effect : Effect) (fresh : Fresh)
    (nextPc : Word) :
    (generatedReturn s effect fresh nextPc).frame.registers.raw.gpr 0 = effect.value ∧
    (generatedReturn s effect fresh nextPc).frame.tags 0 = effect.resultTag ∧
    (generatedReturn s effect fresh nextPc).frame.registers.raw.memory = effect.memory ∧
    (generatedReturn s effect fresh nextPc).frame.registers.raw.pc = nextPc ∧
    (generatedReturn s effect fresh nextPc).events = effect.events := by
  simp [generatedReturn, generatedClobbers, rawWrite, finishClobbers, registerPc]

/-- Sparse lookup in the independently enumerated Linux table. Each case calls
the operation at its original ID; a gap describes generation failure. -/
def callSpec (helpers : Environment) (s : Frame) (id : Word)
    (fresh : Fresh) (nextPc : Word) : Option Observation := do
  let slot ← x86HelperDispatchSlotOfSpec id
  let linuxId ← x86HelperDispatchIdsSpec[slot]?
  pure (returnSpec s (helpers (BitVec.ofNat 64 linuxId) s) fresh nextPc)

theorem returning_helper_call (helpers : Environment) (s : Frame) (id : Word)
    (fresh : Fresh) (nextPc : Word) :
    generatedCall helpers s id fresh nextPc = callSpec helpers s id fresh nextPc := by
  simp only [generatedCall, callSpec, x86_helper_dispatch_slotof_refines,
    GeneratedX86HelperDispatch.idOfSlot, x86_helper_dispatch_ids_refine,
    returning_helper_frame]

/-- Every callee register keeps its value, tag and stack-coordinate relation. -/
theorem returning_helper_callee (s : Frame) (effect : Effect) (fresh : Fresh)
    (nextPc : Word) (reg : Reference.X86.Register)
    (callee : clobberIndex reg = none) (result : reg ≠ 0) :
    (generatedReturn s effect fresh nextPc).frame.registers.raw.gpr reg =
        s.registers.raw.gpr reg ∧
    (generatedReturn s effect fresh nextPc).frame.tags reg = s.tags reg ∧
    (generatedReturn s effect fresh nextPc).frame.registers.stack reg =
        s.registers.stack reg := by
  rw [returning_helper_frame]
  simp [returnSpec, clobbersSpec, rawWrite, finishClobbers, registerPc, callee, result]

/-- Immediate and register tokens share one returning-helper body. -/
inductive Token where
  | immediate | register
  deriving DecidableEq, Repr

def token : Token → GeneratedX86Specialization.Op
  | .immediate => .callHelper | .register => .callReg

def opcode : Token → GeneratedX86Opcode.Op
  | .immediate => .callHelper | .register => .callReg

def generatedToken (env : Refinement.EntryEnvironment.Environment)
    (entry : Refinement.EntryEnvironment.Frame) (arena : Word)
    (helpers : Environment) (s : Frame) (kind : Token) (src : Reference.X86.Register)
    (imm : Word) (fresh : Fresh) (nextPc : Word) : Option Observation :=
  match kind with
  | .immediate => generatedCall helpers s imm fresh nextPc
  | .register => generatedCall helpers s (registerValue env entry arena s.registers src) fresh nextPc

def tokenSpec (env : Refinement.EntryEnvironment.Environment)
    (entry : Refinement.EntryEnvironment.Frame) (arena : Word)
    (helpers : Environment) (s : Frame) (kind : Token) (src : Reference.X86.Register)
    (imm : Word) (fresh : Fresh) (nextPc : Word) : Option Observation :=
  let id := match kind with
    | .immediate => imm
    | .register => (nativeRegisters env entry arena s.registers).gpr src
  callSpec helpers s id fresh nextPc

theorem returning_helper_token_body (env : Refinement.EntryEnvironment.Environment)
    (entry : Refinement.EntryEnvironment.Frame) (arena : Word)
    (helpers : Environment) (s : Frame) (kind : Token) (src : Reference.X86.Register)
    (imm : Word) (fresh : Fresh) (nextPc : Word) :
    generatedToken env entry arena helpers s kind src imm fresh nextPc =
      tokenSpec env entry arena helpers s kind src imm fresh nextPc := by
  cases kind <;> simpa only [generatedToken, tokenSpec, nativeRegisters] using
    (returning_helper_call helpers s _ fresh nextPc)

def helperPrefix (env : Refinement.EntryEnvironment.Environment)
    (entry : Refinement.EntryEnvironment.Frame) (arena : Word)
    (helpers : Environment) (s : Frame) (code : Nat) (src : Reference.X86.Register)
    (imm : Word) (fresh : Fresh) (nextPc : Word) : Option Observation :=
  if code = GeneratedX86Opcode.code .callHelper then
    generatedToken env entry arena helpers s .immediate src imm fresh nextPc
  else if code = GeneratedX86Opcode.code .callReg then
    generatedToken env entry arena helpers s .register src imm fresh nextPc
  else none

theorem helper_token_identity (kind : Token) :
    GeneratedX86Specialization.dispatch (token kind) = .directMacro ∧
    GeneratedX86Specialization.tokenName (token kind) =
      GeneratedX86Opcode.define (opcode kind) := by
  cases kind <;> decide

theorem returning_helper_prefix (env : Refinement.EntryEnvironment.Environment)
    (entry : Refinement.EntryEnvironment.Frame) (arena : Word)
    (helpers : Environment) (s : Frame) (kind : Token) (src : Reference.X86.Register)
    (imm : Word) (fresh : Fresh) (nextPc : Word) :
    helperPrefix env entry arena helpers s (GeneratedX86Opcode.code (opcode kind))
      src imm fresh nextPc =
      tokenSpec env entry arena helpers s kind src imm fresh nextPc := by
  cases kind <;> simp [helperPrefix, opcode, GeneratedX86Opcode.code,
    returning_helper_token_body]

end X86HelperBody

end KProgFormal
