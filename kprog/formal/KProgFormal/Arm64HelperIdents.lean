import KProgFormal.GeneratedArm64HelperIdents

namespace KProgFormal

/-- Independent enumeration of the encoder's 61 BPF helper ids with the
helper name each one denotes, in id-sorted order. Written out by hand so it
shares no structure with the generated table. -/
def helperIdentsSpec : List (Nat × String) := [
  (1, "bpf_map_lookup_elem"), (2, "bpf_map_update_elem"),
  (3, "bpf_map_delete_elem"), (4, "bpf_probe_read"),
  (5, "bpf_ktime_get_ns"), (6, "bpf_trace_printk"),
  (7, "bpf_get_prandom_u32"), (8, "bpf_get_smp_processor_id"),
  (9, "bpf_skb_store_bytes"), (10, "bpf_l3_csum_replace"),
  (11, "bpf_l4_csum_replace"), (12, "bpf_tail_call"),
  (13, "bpf_clone_redirect"), (14, "bpf_get_current_pid_tgid"),
  (15, "bpf_get_current_uid_gid"), (16, "bpf_get_current_comm"),
  (21, "bpf_skb_set_tunnel_key"), (23, "bpf_redirect"),
  (25, "bpf_perf_event_output"), (26, "bpf_skb_load_bytes"),
  (27, "bpf_get_stackid"), (28, "bpf_csum_diff"),
  (31, "bpf_skb_change_proto"), (32, "bpf_skb_change_type"),
  (33, "bpf_skb_under_cgroup"), (35, "bpf_get_current_task"),
  (37, "bpf_current_task_under_cgroup"), (38, "bpf_skb_change_tail"),
  (39, "bpf_skb_pull_data"), (43, "bpf_skb_change_head"),
  (44, "bpf_xdp_adjust_head"), (45, "bpf_probe_read_str"),
  (46, "bpf_get_socket_cookie"), (50, "bpf_skb_adjust_room"),
  (65, "bpf_xdp_adjust_tail"), (67, "bpf_get_stack"),
  (68, "bpf_skb_load_bytes_relative"), (69, "bpf_fib_lookup"),
  (80, "bpf_get_current_cgroup_id"), (95, "bpf_sk_fullsock"),
  (112, "bpf_probe_read_user"), (113, "bpf_probe_read_kernel"),
  (114, "bpf_probe_read_user_str"), (115, "bpf_probe_read_kernel_str"),
  (118, "bpf_jiffies64"), (122, "bpf_get_netns_cookie"),
  (125, "bpf_ktime_get_boot_ns"), (127, "bpf_seq_write"),
  (148, "bpf_copy_from_user"), (152, "bpf_redirect_neigh"),
  (158, "bpf_get_current_task_btf"), (161, "bpf_ima_inode_hash"),
  (174, "bpf_get_attach_cookie"), (175, "bpf_task_pt_regs"),
  (183, "bpf_get_func_arg"), (184, "bpf_get_func_ret"),
  (185, "bpf_get_func_arg_cnt"), (186, "bpf_get_retval"),
  (191, "bpf_copy_from_user_task"), (193, "bpf_ima_file_hash"),
  (195, "bpf_map_lookup_percpu_elem"),
]

/-- Constructor enumeration of the generated table, in specification order;
the values still come from the generated `id`/`name` definitions. -/
def allHelperIdents : List GeneratedArm64HelperIdents.Helper := [
  .bpf_map_lookup_elem, .bpf_map_update_elem,
  .bpf_map_delete_elem, .bpf_probe_read,
  .bpf_ktime_get_ns, .bpf_trace_printk,
  .bpf_get_prandom_u32, .bpf_get_smp_processor_id,
  .bpf_skb_store_bytes, .bpf_l3_csum_replace,
  .bpf_l4_csum_replace, .bpf_tail_call,
  .bpf_clone_redirect, .bpf_get_current_pid_tgid,
  .bpf_get_current_uid_gid, .bpf_get_current_comm,
  .bpf_skb_set_tunnel_key, .bpf_redirect,
  .bpf_perf_event_output, .bpf_skb_load_bytes,
  .bpf_get_stackid, .bpf_csum_diff,
  .bpf_skb_change_proto, .bpf_skb_change_type,
  .bpf_skb_under_cgroup, .bpf_get_current_task,
  .bpf_current_task_under_cgroup, .bpf_skb_change_tail,
  .bpf_skb_pull_data, .bpf_skb_change_head,
  .bpf_xdp_adjust_head, .bpf_probe_read_str,
  .bpf_get_socket_cookie, .bpf_skb_adjust_room,
  .bpf_xdp_adjust_tail, .bpf_get_stack,
  .bpf_skb_load_bytes_relative, .bpf_fib_lookup,
  .bpf_get_current_cgroup_id, .bpf_sk_fullsock,
  .bpf_probe_read_user, .bpf_probe_read_kernel,
  .bpf_probe_read_user_str, .bpf_probe_read_kernel_str,
  .bpf_jiffies64, .bpf_get_netns_cookie,
  .bpf_ktime_get_boot_ns, .bpf_seq_write,
  .bpf_copy_from_user, .bpf_redirect_neigh,
  .bpf_get_current_task_btf, .bpf_ima_inode_hash,
  .bpf_get_attach_cookie, .bpf_task_pt_regs,
  .bpf_get_func_arg, .bpf_get_func_ret,
  .bpf_get_func_arg_cnt, .bpf_get_retval,
  .bpf_copy_from_user_task, .bpf_ima_file_hash,
  .bpf_map_lookup_percpu_elem,
]

def allHelperNames : List String :=
    allHelperIdents.map (fun h => GeneratedArm64HelperIdents.name h)

/-- The generated table, projected to `(id, name)` pairs, equals the
independent enumeration. A change to a generated id or name, or to the
independent list, breaks this equality. -/
theorem helper_idents_refines :
    helperIdentsSpec =
      allHelperIdents.map (fun h =>
                             (GeneratedArm64HelperIdents.id h,
                              GeneratedArm64HelperIdents.name h)) := by
  native_decide

/-- No two helpers share a name, so the per-program slot renumbering keys
on an unambiguous name. -/
theorem helper_idents_names_nodup :
    (helperIdentsSpec.map Prod.snd).Nodup := by
  native_decide

/-- The ids are strictly increasing in the specification's order. -/
theorem helper_idents_ids_strictly_increasing :
    (List.zip helperIdentsSpec (List.tail helperIdentsSpec)).all
      (fun p => if p.1.1 < p.2.1 then true else false) = true := by
  native_decide

/-- Each forwarding macro's target helper and the 1-based lexicographic
rank that target occupies over the full 61-name table, by source kernel id.
-/
def helperDelegateSpec : List (String × String × Nat) := [
  ("bpf_get_current_task_btf", "bpf_get_current_task", 11),
  ("bpf_task_pt_regs", "bpf_get_current_task", 11),
  ("bpf_copy_from_user_task", "bpf_copy_from_user", 2),
  ("bpf_ima_file_hash", "bpf_ima_inode_hash", 25),
  ("bpf_map_lookup_percpu_elem", "bpf_map_lookup_elem", 32),
]

/-- The compact per-program slot the encoder assigns `name`: 1-based
lexicographic rank over the used names. The encoder's
`compact_helper_defines` enumerates `sorted(helper_names)` from 1, which is
exactly this count of names lexicographically below `name`, plus one. -/
def helperSlot (used : List String) (name : String) : Nat :=
    1 + used.countP (fun x => if x < name then true else false)

/-- Over the full 61-name table, each forwarding target's pinned slot
agrees with `helperSlot`. A retarget, a rank drift, or a `helperSlot`
change breaks this. -/
theorem helper_delegate_ranks :
    helperDelegateSpec.all
      (fun t => helperSlot allHelperNames t.2.1 == t.2.2) = true := by
  native_decide

/-- Over the full 61-name table, each name's own slot is its lexicographic
rank, in specification order. -/
theorem helper_slot_ranks :
    allHelperNames.map (fun n => helperSlot allHelperNames n) =
      [32, 34, 31, 36, 28, 59, 18, 20,
       55, 29, 30, 57, 1, 10, 13, 9,
       54, 42, 35, 51, 23, 4, 48, 50,
       56, 11, 5, 49, 53, 47, 60, 39,
       21, 46, 61, 22, 52, 6, 8, 45,
       40, 37, 41, 38, 26, 17, 27, 44,
       2, 43, 12, 25, 7, 58, 14, 16,
       15, 19, 3, 24, 33] := by
  native_decide

end KProgFormal
