# Cilium profiling

`make profile-cilium` profiles Cilium separately from the timing suite while
reusing the unchanged `corpus.driver` application lifecycle and
`cilium_endpoint_pktgen` workload. The two arms are the kernel JIT baseline
and whole-program native (`kprog`).

The host controller confines the four-vCPU, 16-GiB guest to host CPUs 16--19.
It uses host `perf stat` guest-only events for cycles, instructions, branches,
branch misses, and cache misses. In the selected corpus phase, a staged real
`perf record` binary records `cpu-clock` call graphs inside the guest. This
allows JIT BPF symbols, kprog-backed BPF images, helpers, map
operations, and the remaining kernel stack to be symbolized together. BPF
runtime statistics remain enabled, so the ordinary corpus result supplies
per-program run counts, run time, JIT size, attachment evidence, and workload
outcomes. Native-loader logs supply the paired original-JIT and native-blob
image sizes.
The guest also snapshots network attachments at the measurement boundary so
program IDs match the counters. Datapath symbol summaries disclose and exclude
idle-vCPU and unresolved leaf samples from the four-way time split; the raw
perf report remains available for audit.
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
  CILIUM_PROFILE_DURATION=60 \
  CILIUM_PROFILE_CPUS=16-19
```

For a short JIT preflight:

```sh
make profile-cilium \
  CILIUM_PROFILE_ARM=jit \
  CILIUM_PROFILE_DURATION=5 \
  CILIUM_PROFILE_CPUS=16-19
```

Set `CILIUM_PROFILE_OUTPUT_DIR` to choose a new directory below
`corpus/results/`; other locations are not visible through the runtime result
mount. The command fails instead of overwriting an existing directory. Each arm retains the exact
Make command, complete log, raw host counters, raw `perf.data`, guest kallsyms
and module snapshots, BPF inventory, `perf report`, `perf script`, and JSON and
Markdown analyses. `SUMMARY.md` compares the arms. The temporary staged perf
runtime is removed after collection and is never part of the result.
