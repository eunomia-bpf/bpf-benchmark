# Cilium profiling

`make profile-cilium` profiles Cilium separately from the timing suite while
reusing the unchanged `corpus.driver` application lifecycle and
`cilium_endpoint_pktgen` workload. The two arms are the kernel JIT baseline
and whole-program native (`kprog`).

The host controller uses the timing setup: an eight-vCPU, 64-GiB guest pinned
to host P-cores 0--7.
It uses host `perf stat` guest-only events for cycles, instructions, branches,
branch misses, and cache misses. In the selected corpus phase, a staged real
`perf record` binary records kernel cycles, frame-pointer call graphs, and LBR
call/return branch stacks inside the guest. The LBR history crosses native
program frames built without frame pointers. This allows JIT BPF symbols,
kprog-backed BPF images, helpers, map operations, and the remaining kernel
stack to be symbolized together. BPF
runtime statistics remain enabled, so the ordinary corpus result supplies
per-program run counts, run time, JIT size, attachment evidence, and workload
outcomes. Native-loader logs supply paired original-JIT and native-blob image
sizes; the report retains only IDs in the final measured live-program set
rather than all lifecycle replacements.
The guest snapshots symbols, modules, and network attachments after the
workload has run and sampling has stopped. Thus pktgen is present in the JIT
symbol table and program IDs match the counters. Datapath summaries use
frame-pointer plus LBR context, including LRU spin-lock frames below
`htab_lru_map_update_elem` or `bpf_common_lru_pop_free` in the map category.
They disclose and exclude idle-vCPU and unresolved leaf samples; the raw perf
report remains available for audit.
The guest-only collector and its real `perf` binary are staged through the
result mount, so profiling works with agent 1's validated runtime image and
does not require an image rebuild. The nested Make invocation treats the
validated runtime tar as immutable and fails if that tar or its kernel image
is missing. A staged guest launch script also keeps the virtme kernel command
line short; the full resolved guest Make command remains in `commands.json`.
The staged `perf` runtime and its recording file are copied to guest-local
ext4 storage before sampling, then the completed raw data is copied back; perf
therefore never mmaps the virtme/9p result mount during the workload.

Run the complete profile only while holding the coordination file's
`HOST-EXCLUSIVE` lease:

```sh
make profile-cilium \
  CILIUM_PROFILE_ARM=all \
  CILIUM_PROFILE_ORDER=both \
  CILIUM_PROFILE_DURATION=60 \
  CILIUM_PROFILE_CPUS=0-7
```

`both` launches four fresh guests: JIT then kprog, followed by kprog then JIT.
The two within-order ratios and their counterbalanced geometric mean are
reported separately so boot/order effects remain visible.

For a short JIT preflight:

```sh
make profile-cilium \
  CILIUM_PROFILE_ARM=jit \
  CILIUM_PROFILE_ORDER=single \
  CILIUM_PROFILE_DURATION=5 \
  CILIUM_PROFILE_CPUS=0-7
```

Set `CILIUM_PROFILE_OUTPUT_DIR` to choose a new directory below
`corpus/results/`; other locations are not visible through the runtime result
mount. The command fails instead of overwriting an existing directory. Each arm retains the exact
Make command, complete log, raw host counters, raw `perf.data`, guest kallsyms
and module snapshots, BPF inventory, `perf report`, `perf script`, and JSON and
Markdown analyses. `SUMMARY.md` compares the arms. The temporary staged perf
runtime is removed after collection and is never part of the result.
