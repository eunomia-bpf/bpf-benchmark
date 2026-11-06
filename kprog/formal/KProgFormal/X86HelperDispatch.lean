import KProgFormal.Generated.GeneratedX86HelperDispatch

namespace KProgFormal

open GeneratedX86HelperDispatch (helperCount idBits helperIds helperNames
  helperBodies defaultBody slotOf idOfSlot nameOfSlot slotOfName)

/-- Independent Linux IDs, in increasing order, checked against public libbpf declarations. -/
def x86HelperDispatchIdsSpec : List Nat :=
  [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15, 16, 20, 21, 23, 25, 26, 27, 28, 32, 35, 36, 37, 38, 39, 43, 44, 45, 46, 50, 54, 58, 65, 67, 68, 69, 80, 85, 86, 87, 88, 95, 99, 109, 112, 113, 114, 115, 118, 122, 124, 125, 130, 148, 152, 155, 158, 174, 175, 181, 184, 193]

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
   "bpf_get_attach_cookie",
   "bpf_task_pt_regs",
   "bpf_loop",
   "bpf_get_func_ret",
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

/-- The armed count is65. The legacy theorem name is retained for compatibility. -/
theorem x86_helper_dispatch_count_is_7 : helperCount = 65 := rfl

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


end KProgFormal
