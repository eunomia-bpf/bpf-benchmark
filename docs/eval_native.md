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

- [ ] `bcc/set`
- [ ] `otelcol-ebpf-profiler/profiling`
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
RUNTIMES="native native_kernel kernel" \
make micro
```

Stage2 has no `llvmbpf` runtime in the suite catalog, so userspace eBPF is not
part of the stage2 four-way comparison unless the catalog grows that runtime.

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
- [ ] Run authoritative micro stage1.
- [ ] Run authoritative micro stage2.
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
