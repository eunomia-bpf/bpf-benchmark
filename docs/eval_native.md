# Native Loader Evaluation

This document is the authoritative run log for the native-loader evaluation.
It tracks smoke validation, bug fixes, paper-grade runs, and the final
correctness/performance interpretation. Keep raw framework results in
`corpus/results/` and `micro/results/`; this document records artifact paths
and analysis performed outside the framework.

## Goals

- Validate that corpus native loading uses the app-level loader path:
  baseline starts the real app with kernel eBPF, post starts the same real app
  with native-loader enabled by the shim.
- Validate that micro native loading uses the same native-loader core path as
  corpus after the frontend supplies `original_prog_fd`, source bytecode, and
  native object path.
- Collect corpus data for all supported apps under three configurations:
  BPF stats on for per-program `run_cnt/run_time_ns`, BPF stats off for
  workload metrics, and workload-only with no eBPF app.
- Collect micro stage1/stage2 data comparing userspace native, userspace eBPF,
  kernel native, and kernel eBPF.
- Re-run all affected smoke and authoritative measurements after any bug fix.

## Method

All runs use the Makefile entrypoint. Do not run corpus or micro driver modules
directly.

Supported corpus apps:

- [x] `bcc/set`
- [x] `otelcol-ebpf-profiler/profiling`
- [ ] `cilium/agent`
- [ ] `tetragon/observer`
- [ ] `katran`
- [ ] `tracee/monitor`

Native-vs-kernel smoke command, run once per app before authoritative runs:

```sh
SAMPLES=1 WARMUPS=0 WORKLOAD_DURATION=10 \
BPFREJIT_CORPUS_APPS="<app>" \
BPFREJIT_SHIM_NATIVE_LOADER=post \
BPFREJIT_CORPUS_BPF_STATS=1 \
SKIP_REJIT=norejit \
make corpus
```

Authoritative corpus configuration A: BPF stats on for per-program runtime:

```sh
SAMPLES=3 WARMUPS=1 WORKLOAD_DURATION=180 \
BPFREJIT_CORPUS_APPS="<app>" \
BPFREJIT_SHIM_NATIVE_LOADER=post \
BPFREJIT_CORPUS_BPF_STATS=1 \
SKIP_REJIT=norejit \
make corpus
```

Authoritative corpus configuration B: BPF stats off for workload metrics:

```sh
SAMPLES=3 WARMUPS=1 WORKLOAD_DURATION=180 \
BPFREJIT_CORPUS_APPS="<app>" \
BPFREJIT_SHIM_NATIVE_LOADER=post \
BPFREJIT_CORPUS_BPF_STATS=0 \
SKIP_REJIT=norejit \
make corpus
```

Authoritative corpus configuration C: no eBPF app, workload only:

```sh
SAMPLES=3 WARMUPS=1 WORKLOAD_DURATION=180 \
BPFREJIT_CORPUS_APPS="<app>" \
BPFREJIT_CORPUS_WORKLOAD_ONLY=1 \
BPFREJIT_CORPUS_BPF_STATS=0 \
make corpus
```

Authoritative micro stage1 command:

```sh
SAMPLES=3 WARMUPS=1 INNER_REPEAT=100000 \
SUITE=micro/config/micro_pure_jit.yaml \
RUNTIMES="native llvmbpf native_kernel kernel" \
make micro
```

Authoritative micro stage2 command:

```sh
SAMPLES=3 WARMUPS=1 INNER_REPEAT=100000 \
SUITE=micro/config/micro_stage2.yaml \
RUNTIMES="native llvmbpf native_kernel kernel" \
make micro
```

Stage2 now includes the `llvmbpf` runtime, so the four-way comparison is
userspace native, userspace eBPF, kernel native, and kernel eBPF.

## Todo

- [x] Confirm no stale benchmark process is running before starting this log.
- [x] Build-check native-loader, native-link, runner, and shim artifacts.
- [ ] Smoke each corpus app individually with native-loader post mode.
- [ ] Fix every smoke failure without adding skip lists, fallback paths, or
  kernel symbol lookup.
- [ ] Re-run all corpus smokes after the last smoke bug fix.
- [ ] Run authoritative corpus stats-on configuration for every app.
- [ ] Run authoritative corpus stats-off configuration for every app.
- [ ] Run authoritative workload-only/no-eBPF configuration for every app.
- [x] Run authoritative micro stage1.
- [x] Run authoritative micro stage2.
- [ ] Cross-check function correctness: app status, workload success counters,
  native replacement count, and matching expected micro results.
- [ ] Cross-check performance sanity: stats-on per-program data vs stats-off
  workload data vs no-eBPF workload data.
- [ ] Write final result tables and conclusions in this document.

## Run Log

- 2026-05-26: no stale `make corpus`, `make micro`, VM, Docker benchmark, or
  `bpfrejit` process was running before this evaluation started.
- 2026-05-26: build-check passed:
  `make -C native-sim/libnativeloader`,
  `cargo check --manifest-path native-sim/x86/native_lab/native_link/Cargo.toml`,
  `make -C bpfopt/shim`, and
  `cmake --build runner/build-llvmbpf --target micro_exec native_loader_shared -j24`.
- 2026-05-26: `bcc/set` smoke failed at
  `corpus/results/x86_kvm_corpus_20260526_053029_966757`. Baseline kernel eBPF
  loaded and ran, but post native failed during app startup because native-link
  exhausted the positional JIT oracle for `bpf_map_update_elem` and
  `bpf_probe_read_kernel` call sites. The fix is to pass the intercepted source
  helper call ids from libnativeloader into native-link and match JIT-decoded
  helper targets by helper id, still fail-fast and without `/proc/kallsyms`.
- 2026-05-26: after the helper-id oracle change,
  `make -C native-sim/libnativeloader` and
  `cargo check --manifest-path native-sim/x86/native_lab/native_link/Cargo.toml`
  passed.
- 2026-05-26: second `bcc/set` smoke failed at
  `corpus/results/x86_kvm_corpus_20260526_054627_407651`. The shim now passes
  source helper ids to native-link, but native-link rejected several programs
  because the source helper sequence is longer than the xlated/JIT matched
  oracle sequence. Representative failures include `opensnoop`
  `[14,15,2] -> 2 targets`, `syscount` `[14,37,5,2] -> 3 targets`,
  and `tcpconnect` `16 helpers -> 10 targets`. The likely root cause is that
  some verifier-lowered map operation calls are visible in the raw JIT call
  stream but missing from the xlated-helper matching stream. The planned fix is
  to preserve raw JIT call indices during matching and expand the contiguous
  source-helper oracle only when the raw JIT stream proves the required targets
  are present; otherwise native-link must still fail fast. No `/proc/kallsyms`
  or helper-symbol fallback is allowed.
- 2026-05-26: third `bcc/set` smoke failed at
  `corpus/results/x86_kvm_corpus_20260526_055713_880643`. The improved error
  showed raw JIT also has only two external call targets for `capable` and
  `opensnoop`; the missing source helper is `bpf_map_update_elem`. That means
  the target cannot be recovered from the JIT call stream. The fix is to expose
  `map->ops->map_update_elem` and `map->ops->map_delete_elem` through the
  native_lab debugfs module by map fd, then have libnativeloader attach those
  map-owned targets to update/delete call metadata. This keeps lookup through
  kernel-owned map metadata and still avoids `/proc/kallsyms`.
- 2026-05-26: implemented map-owned update/delete target lookup in both x86
  and arm64 native_lab modules and in libnativeloader. Build checks passed for
  native-link, libnativeloader, x86 native_lab, arm64 native_lab with
  `CROSS_COMPILE=aarch64-linux-gnu-`, release native-link, and the runner
  `micro_exec/native_loader_shared` targets. A bare arm64 module build without
  `CROSS_COMPILE` fails because host `gcc` does not accept arm64 kernel flags;
  this is an invocation issue, not a code failure.
- 2026-05-26: fourth `bcc/set` smoke failed at
  `corpus/results/x86_kvm_corpus_20260526_061035_257257`. The update/delete
  fix let several programs load as native, but the remaining failures exposed
  three separate gaps: x86 JIT oracle decoding ignored `movabs; call *reg`
  helper-call lowering, native-link treated compiler `memset` as a BPF helper
  oracle consumer, and hash-map lookup lowering still lacked the map-owned
  `map_gen_lookup` call target. Implemented fixes: decode register-indirect
  JIT call targets for oracle input, inline small `memset`/`memcpy` libcalls in
  native-link instead of consuming helper oracle entries, and expose
  `map_lookup_ptr` through x86/arm64 native_lab debugfs by executing
  `map->ops->map_gen_lookup()` on the kernel-owned map and extracting its
  emitted BPF call target. This remains fail-fast and does not use kallsyms.
- 2026-05-26: after the JIT-indirect/libcall/map-lookup fixes, build checks
  passed for native-link, release native-link, libnativeloader, x86 native_lab,
  arm64 native_lab with `CROSS_COMPILE=aarch64-linux-gnu-`, and runner
  `micro_exec/native_loader_shared`.
- 2026-05-26: fifth `bcc/set` smoke failed at
  `corpus/results/x86_kvm_corpus_20260526_062319_609704`. The kernel module
  and loader were now passing non-zero map lookup targets, but native-link still
  allowed explicit map lookup/update/delete sites to consume companion JIT
  oracle entries. That shifted the oracle away from ordinary helpers such as
  `bpf_probe_read_kernel`, `bpf_get_stackid`, and `bpf_perf_event_output`, and
  also left unused helper targets in `sched_switch`. The fix is to make
  native-link treat explicit map-owned targets as authoritative, exclude those
  map operations from both source-helper and xlated-helper oracle streams,
  remove array/percpu update inline oracle consumption, require `--source-helper`
  whenever an oracle has helper targets, and fail fast on source/xlated target
  count mismatch rather than falling back to positional matching.
- 2026-05-26: after the explicit-map-target oracle cleanup, build checks passed
  for native-link dev, native-link release, libnativeloader,
  `bpfopt/shim`, and runner `micro_exec/native_loader_shared`.
- 2026-05-26: sixth `bcc/set` smoke failed at
  `corpus/results/x86_kvm_corpus_20260526_063319_392938` with a kernel oops in
  `lookup_nulls_elem_raw` during post native execution. The bad call had
  `0xdeadbeef` in the raw lookup arguments, which proved that the new
  `map_gen_lookup()` target extraction was wrong: the generated lookup target
  uses the verifier/JIT internal raw hash-lookup ABI, not the public
  `bpf_map_lookup_elem(map, key)` helper ABI emitted by the native C call site.
  The fix is to expose and call `map->ops->map_lookup_elem` for non-array maps
  and mark those lookup sites as normal `Call` sites, so native-link does not
  apply hash `key_offset` postprocessing to a helper-ABI result. Array and
  percpu-array sites remain inline lowered.
- 2026-05-26: after the lookup helper-ABI fix, build checks passed for
  libnativeloader, x86 native_lab, arm64 native_lab with
  `CROSS_COMPILE=aarch64-linux-gnu-`, and runner
  `micro_exec/native_loader_shared`.
- 2026-05-26: micro stage2 userspace runtime support was made functional by
  sharing map/helper state between `native` and `llvmbpf`, adding stage2
  `.native.so` builds, and teaching `micro_stage2.yaml` to run all four
  runtimes. Functional smokes passed:
  `micro/results/x86_kvm_micro_20260526_084235_234271`,
  `micro/results/x86_kvm_micro_20260526_084642_830655`,
  `micro/results/x86_kvm_micro_20260526_091105_928226`, and
  `micro/results/x86_kvm_micro_20260526_091516_932919`.
- 2026-05-26: stage2 stable run before the x86 map-gen encoding cleanup:
  `micro/results/x86_kvm_micro_20260526_092046_061746`.
  Native-kernel/kernel per-bench geometric mean was 0.742
  (1.348x speedup), with 10 wins, 1 loss, and 2 ties. This was below older
  stage2 runs from 2026-05-22/2026-05-23, which were around 1.45x.
- 2026-05-26: tested a map-retention cleanup that put the map FD references
  behind a direct `BPF_JA`. The kernel verifier rejected it with unreachable
  instructions, so it was not kept. The currently working stub still uses the
  verifier-accepted `MOV r1 = 1; JEQ r1, 1` retention form. Final x86 JIT
  keeps only the `mov edi, 1` residue and removes the skipped map-FD loads.
- 2026-05-26: implemented a small x86 native-link cleanup for verifier-generated
  map lookup bodies: `cmp reg, 0` lowers to `test reg, reg`, and group-1
  immediates use imm8 encoding when possible. This is a code-size cleanup, not
  a semantic fallback.
- 2026-05-26: micro stage2 smoke after the x86 cleanup passed at
  `micro/results/x86_kvm_micro_20260526_100409_068990` and
  `micro/results/x86_kvm_micro_20260526_100914_334801`.
- 2026-05-26: authoritative micro stage2 after the x86 cleanup passed at
  `micro/results/x86_kvm_micro_20260526_101329_551095`.
  Native-kernel/kernel per-bench geometric mean was 0.744
  (1.344x speedup), with 9 wins, 1 loss, and 3 ties. The cleanup reduced some
  final JIT size (for example `map_hash_lookup` native-kernel sample00 from
  162 to 155 bytes), but did not recover the older 1.45x stage2 number.
  The main reason is not a native correctness bug: current hash-map kernel
  baseline samples are much faster than the earlier run (`map_hash_lookup`
  kernel 31/31/32 ns now vs 81/80/80 ns in
  `x86_kvm_micro_20260526_092046_061746`), so native has less headroom.
  `map_percpu_hash_counter` has one low kernel sample (27/75/75 ns), which
  makes the three-sample mean look like a slowdown; the other two samples are
  essentially tied with native-kernel (75 vs 74 ns). Packet and mixed-helper
  programs remain tied because the fixed stub cost and map-retention residue
  offset the shorter native body on these tiny hooks.
- 2026-05-26: authoritative micro stage1 passed at
  `micro/results/x86_kvm_micro_20260526_102643_925420` with all 29 pure-JIT
  benches returning matching results across `native`, `llvmbpf`, `kernel`, and
  `native_kernel`. Post-hoc analysis of raw `exec_ns` samples gives:
  native-kernel/kernel geometric mean ratio 0.701 (1.427x speedup),
  userspace-native/llvmbpf ratio 0.861 (1.161x speedup),
  userspace-native/kernel ratio 0.600 (1.668x speedup), and
  native-kernel/userspace-native ratio 1.169 (kernel native is 0.856x of
  userspace native). The only native-kernel slowdowns are the two trivial
  `simple*` benches, where absolute times are 5-6 ns and the fixed kernel
  entry/native stub cost dominates. Large pure-JIT programs still show the
  expected benefit, for example `packet_checksum_fold` and
  `tc_packet_checksum_fold` are both about 13.2 us native-kernel vs 17.6 us
  kernel eBPF.
- 2026-05-26: `bcc/set` native-loader smoke is now passing at
  `corpus/results/x86_kvm_corpus_20260526_123450_295749`. This run loaded 25
  baseline programs and 25 post native replacements, and both baseline and
  post workloads completed with status `ok`.
- 2026-05-26: the final `bcc/set` blocker had two parts. First,
  `sched_switch` still used an old positional source-helper/xlated-oracle
  invariant even though loader now passes explicit helper targets from helper
  oracle loads. The fix keeps the fail-fast positional check only for helper
  targets that are actually taken from xlated/JIT oracle order; explicit
  helper targets no longer depend on source/xlated helper order. Second,
  x86 proof objects encode unresolved helper PLT32 calls as local-looking
  `call` instructions, so kernel-mode rewrite misclassified `bpf_map_update_elem`
  as a local `handle_switch` call before helper rewrite. The fix makes
  relocation-marked helper call sites bypass the cross-symbol call path, so
  map update and lookup calls are routed through their per-site metadata.
- 2026-05-26: `otelcol-ebpf-profiler/profiling` smoke passed at
  `corpus/results/x86_kvm_corpus_20260526_145323_965689`. The post shim log
  has 14 native replacements, including `custom__generic`, and no
  `native-loader failed`, relocation-bounds, `ff d0`, or legacy nop7 hits.
  The OTel-specific blocker was dynamic tail-call map rewriting in the real Go
  loader: source bytecode for `custom__generic` rewrites the symbolic
  `perf_progs` tail-call map to the runtime `kprobe_progs` map, while the
  native object relocation still names `perf_progs`. The fix records
  tail-call prog-array maps from the captured source bytecode and aliases the
  native prog-array symbol to that actual source map when the native symbol has
  the expected prog-array shape. This keeps corpus on original app bytecode and
  avoids `/proc/kallsyms` or process-map-name fallback.
