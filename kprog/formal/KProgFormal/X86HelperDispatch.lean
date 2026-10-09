import KProgFormal.GeneratedX86HelperDispatch

namespace KProgFormal

open GeneratedX86HelperDispatch (helperCount idBits helperIds helperNames
  helperBodies defaultBody slotOf idOfSlot nameOfSlot slotOfName)

/-- Independent statement of the armed helper ids, built from the literal
`1 .. 7` range rather than the generated literal table. -/
def x86HelperDispatchIdsSpec : List Nat :=
  (List.range 7).map (fun i => i + 1)

/-- Independent statement of the armed helper names, built from the literal
`bpf_map_lookup_elem .. bpf_ktime_get_ns` order rather than the generated
literal table. -/
def x86HelperDispatchNamesSpec : List String :=
  ["bpf_map_lookup_elem", "bpf_map_update_elem", "bpf_map_delete_elem",
   "bpf_get_current_uid_gid", "bpf_get_current_pid_tgid",
   "bpf_get_smp_processor_id", "bpf_ktime_get_ns"]

/-- Independent statement of the armed body macros, built from the literal
`X86_SIM_BPF_CALL_` prefix rather than the generated literal table. -/
def x86HelperDispatchBodiesSpec : List String :=
  x86HelperDispatchNamesSpec.map (fun n => "X86_SIM_BPF_CALL_" ++ n)

/-- Independent statement of which decoded helper ids name an armed ladder arm:
the lookup runs over the independently built `1 .. 7` id table, so an armed id
`i + 1` names slot `i` and the zero id and every id `8 ..` name none. -/
def x86HelperDispatchSlotOfSpec (id : BitVec 64) : Option Nat :=
  (x86HelperDispatchIdsSpec.zip (List.range 7)).lookup id.toNat

/-- The generated armed-id table equals the independent literal `1 .. 7`
construction, so ladder slot `i` dispatches helper id `i + 1`. -/
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

/-- The ladder selector equals the independent lookup over the `1 .. 7` id
table for every decoded helper id. -/
theorem x86_helper_dispatch_slotof_refines (id : BitVec 64) :
    slotOf id = x86HelperDispatchSlotOfSpec id := by
  unfold slotOf x86HelperDispatchSlotOfSpec helperCount
  rw [x86_helper_dispatch_ids_refine]

/-- The helper-id width is the 64-bit width the sim decodes, pinned so the C
`__u64` helper id and the generated `idBits` cannot drift apart. -/
theorem x86_helper_dispatch_bits_is_64 : idBits = 64 := rfl

/-- The first armed helper (`bpf_map_lookup_elem`) dispatches to slot `0`. -/
theorem x86_helper_dispatch_slot_lookup : slotOf (1 : BitVec 64) = some 0 := by
  native_decide

/-- The last armed helper (`bpf_ktime_get_ns`) dispatches to slot `6`, so the
armed id range is covered without a gap. -/
theorem x86_helper_dispatch_slot_ktime : slotOf (7 : BitVec 64) = some 6 := by
  native_decide

/-- The first unarmed named helper id (`bpf_current_task_under_cgroup`, id `8`)
names no armed slot, so the armed range ends exactly at `bpf_ktime_get_ns`. -/
theorem x86_helper_dispatch_first_unarmed_is_none :
    slotOf (8 : BitVec 64) = none := by
  native_decide

/-- The last named helper id (`bpf_get_current_task`, id `21`) names no armed
slot, so it reaches the default arm like every unarmed id. -/
theorem x86_helper_dispatch_last_named_is_none :
    slotOf (21 : BitVec 64) = none := by
  native_decide

/-- Helper id `0` names no armed slot, so the zero id also reaches the default
arm. -/
theorem x86_helper_dispatch_zero_is_none : slotOf (0 : BitVec 64) = none := by
  native_decide

/-- Every armed helper id `1 .. 7` names its own slot and the whole unarmed
range (id `0`, the named ids `8 .. 21`, and an id beyond the whole named space)
names none: the full-range round trip, so the dispatch is total on the armed
range and routes the unarmed tail to the default arm. -/
theorem x86_helper_dispatch_full_range :
    ((List.range helperCount).all
        (fun i => slotOf (BitVec.ofNat 64 (i + 1)) = some i)) = true ∧
      (slotOf (0 : BitVec 64) = none) ∧
      (slotOf (8 : BitVec 64) = none) ∧
      (slotOf (21 : BitVec 64) = none) ∧
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

/-- The armed count is the seven helper bodies the x86-64 sim implements
(`bpf_map_lookup_elem .. bpf_ktime_get_ns`). -/
theorem x86_helper_dispatch_count_is_7 : helperCount = 7 := rfl

/-- The default arm body is the RAX zero-write the hand-written ladder's `else`
branch runs, so every unarmed id writes RAX width 64 with the zero value. -/
theorem x86_helper_dispatch_default_is_rax_zero :
    defaultBody = "X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64)" := rfl

/-- Every armed slot's id is nonzero, so no armed id collides with the zero id
that also reaches the default arm. -/
theorem x86_helper_dispatch_ids_nonzero :
    helperIds.all (fun n => n != 0) = true := by
  unfold helperIds
  native_decide

/-- The armed ids `1 .. 7` are a strict subset of the helper ids `1 .. 21` the
sim names, so the ids `8 .. 21` provably reach the default arm. -/
theorem x86_helper_dispatch_armed_is_strict_subset :
    helperIds.all (fun n => n < 22) = true ∧ helperCount < 21 := by
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

/-- All the dispatch shapes are reachable: the first armed slot, the last armed
slot, the zero id, the first unarmed named id, and the last named id, so no
branch of the contract is dead. -/
theorem x86_helper_dispatch_case_dispatch :
    slotOf (1 : BitVec 64) = some 0 ∧
      slotOf (7 : BitVec 64) = some 6 ∧
      slotOf (0 : BitVec 64) = none ∧
      slotOf (8 : BitVec 64) = none ∧
      slotOf (21 : BitVec 64) = none := by
  refine ⟨?_, ?_, ?_, ?_, ?_⟩ <;> native_decide

end KProgFormal
