# Native Execution Evaluation

Date: 2026-05-26

This document tracks the authoritative evaluation of the native execution path
against the existing eBPF JIT paths. It is intentionally a post-hoc analysis
document: the benchmark framework records raw counters and workload payloads,
while all aggregation and interpretation live here or in external analysis
scripts.

## Status

| Area | Status | Artifact |
| --- | --- | --- |
| Micro stage1 | complete | `micro/results/x86_kvm_micro_20260526_210952_650695/metadata.json` |
| Micro stage2 | complete | `micro/results/x86_kvm_micro_20260526_210434_440390/metadata.json` |
| Corpus, BPF stats on | running | `bcc/set`, `otelcol-ebpf-profiler/profiling`, `cilium/agent` complete |
| Corpus, BPF stats off | pending | pending |
| Corpus, workload-only no eBPF | pending | pending |

## Current Figures

The current complete figures cover the authoritative micro runs that have
already finished. Runtime is normalized to kernel eBPF (`kernel = 1.0`);
lower is faster.

![Micro stage1 runtime](figures/eval-native-micro-stage1-runtime.png)

![Micro stage2 runtime](figures/eval-native-micro-stage2-runtime.png)

## Setup

- Platform: x86 KVM (`make` default target).
- Kernel/runtime image: repository default build used by `make micro` and
  `make corpus`.
- Micro samples: `SAMPLES=3`, `WARMUPS=0`, `INNER_REPEAT=100000`.
- Corpus samples: `SAMPLES=3`, `WORKLOAD_DURATION=180`, default
  `WARMUPS=1`. The warmup is not counted in the three stored workload
  samples, but it does add one extra 180 s workload pass before each measured
  phase.
- Corpus apps: `bcc/set`, `otelcol-ebpf-profiler/profiling`,
  `cilium/agent`, `tetragon/observer`, `katran`, `tracee/monitor`.

## Commands

Micro stage1:

```sh
RUNTIMES="native llvmbpf native_kernel kernel" \
SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000 TIMEOUT=2400 \
make micro
```

Micro stage2:

```sh
SUITE=micro/config/micro_stage2.yaml \
RUNTIMES="native llvmbpf native_kernel kernel" \
SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000 TIMEOUT=2400 \
make micro
```

Corpus native with BPF runtime counters enabled:

```sh
BPFREJIT_CORPUS_APPS="<app>" \
BPFREJIT_SHIM_NATIVE_LOADER=post SKIP_REJIT=norejit \
BPFREJIT_CORPUS_BPF_STATS=1 \
SAMPLES=3 WORKLOAD_DURATION=180 TIMEOUT=14400 \
make corpus
```

Corpus native with BPF runtime counters disabled:

```sh
BPFREJIT_CORPUS_APPS="<app>" \
BPFREJIT_SHIM_NATIVE_LOADER=post SKIP_REJIT=norejit \
BPFREJIT_CORPUS_BPF_STATS=0 \
SAMPLES=3 WORKLOAD_DURATION=180 TIMEOUT=14400 \
make corpus
```

Corpus workload-only no-eBPF baseline:

```sh
BPFREJIT_CORPUS_APPS="<app>" \
BPFREJIT_CORPUS_WORKLOAD_ONLY=1 BPFREJIT_CORPUS_BPF_STATS=0 \
SAMPLES=3 WORKLOAD_DURATION=180 TIMEOUT=14400 \
make corpus
```

## Progress Log

- 2026-05-26: Micro stage2 completed for 13 benchmarks across
  `native`, `llvmbpf`, `native_kernel`, and `kernel`; all runtimes returned
  matching results. Geomean normalized runtime vs kernel eBPF:
  userspace native `2.29x`, userspace eBPF `1.01x`, kernel native `0.71x`,
  kernel eBPF `1.00x`.
- 2026-05-26: Micro stage1 completed for 29 benchmarks across
  `native`, `llvmbpf`, `native_kernel`, and `kernel`; all runtimes returned
  matching results. Geomean normalized runtime vs kernel eBPF:
  userspace native `0.58x`, userspace eBPF `0.65x`, kernel native `0.68x`,
  kernel eBPF `1.00x`.
- 2026-05-26: `bcc/set` corpus native-post run with BPF stats enabled
  completed successfully. Artifact:
  `corpus/results/x86_kvm_corpus_20260526_211758_813406/metadata.json`.
  The app payload has status `ok`, empty error string, 3 baseline workloads,
  3 post-native workloads, and 25 BPF counter records in each phase.
- 2026-05-26: `otelcol-ebpf-profiler/profiling` corpus native-post run with
  BPF stats enabled completed successfully. Artifact:
  `corpus/results/x86_kvm_corpus_20260526_214808_410996/metadata.json`.
  The app payload has status `ok`, empty error string, 3 baseline workloads,
  and 3 post-native workloads. Baseline has 13 BPF counter records; post-native
  has 12 because the zero-run `custom__generic` kprobe record is absent in the
  post app instance.
- 2026-05-26: `cilium/agent` corpus native-post run with BPF stats enabled
  failed during post-native endpoint setup, before workload measurement.
  Artifact:
  `corpus/results/x86_kvm_corpus_20260526_221732_763158/metadata.json`.
  The baseline phase completed; the post phase returned HTTP 500 from
  `PUT /v1/endpoint/0` with `timeout while waiting for initial endpoint
  generation to complete`. Shim logs show baseline loading 179 programs over
  9.1 seconds, while post-native attempted 287 program loads and 163 native
  replacements over 315.8 seconds. No individual shimmed `BPF_PROG_LOAD` call
  took seconds, so the immediate debug target is Cilium endpoint regeneration
  behavior and native object/config matching rather than one slow syscall.
- 2026-05-26: Short `cilium/agent` debug run reproduced the post-native
  endpoint timeout and captured cilium-agent logs. Artifact:
  `corpus/results/x86_kvm_corpus_20260526_224438_925300/metadata.json`.
  The agent repeatedly failed endpoint regeneration with
  `program tail_drop_notify: load program: no such file or directory`,
  `program cil_host_policy: load program: no such file or directory`, and
  `program cil_lxc_policy_egress: load program: no such file or directory`.
  The shim logged `native-loader enabled but no manifest object` for the same
  programs even though the symbols exist in the native objects; the miss came
  from `source_map_prefix` disambiguation on short/special Cilium variants.
  Fixed the shim so a present manifest with no matching entry keeps the
  original `BPF_PROG_LOAD` fd, while true manifest/object/native-loader errors
  still fail.
- 2026-05-26: Short `cilium/agent` verification run after the shim fix
  completed successfully. Artifact:
  `corpus/results/x86_kvm_corpus_20260526_225719_943967/metadata.json`.
  The app payload has status `ok`, empty error string, one baseline workload,
  one post-native workload, 53 baseline BPF counter records, and 50 post-native
  BPF counter records. The post shim log shows 113 native replacements and
  22 explicit `no manifest match` pass-throughs for the short/special Cilium
  variants; the previous `load program: no such file or directory` endpoint
  failures are gone.
- 2026-05-26: Checked the Cilium reload controls in the corpus runner.
  `CiliumRunner` already starts `cilium-agent` with
  `--enable-drift-checker=false`, `--enable-dynamic-config=false`,
  `--enable-dynamic-lifecycle-manager=false`,
  `--endpoint-bpf-prog-watchdog-interval=0`, and
  `--endpoint-regen-interval=0`; it also sends `SIGSTOP` to the agent during
  workload samples after endpoint setup. These controls suppress continuous
  userspace reload/regeneration during measurement. They do not suppress the
  required initial endpoint BPF build/regeneration that happens while creating
  endpoints in baseline and post-native startup, so the earlier post-native
  repeated loads are being treated as startup-path failures or manifest
  mismatches, not as a missing autoreload flag.
- 2026-05-26: Authoritative `cilium/agent` corpus native-post run with BPF
  stats enabled completed successfully after the shim manifest no-match fix.
  Artifact:
  `corpus/results/x86_kvm_corpus_20260526_230251_020975/metadata.json`.
  The app payload has status `ok`, empty error string, 3 baseline workloads,
  3 post-native workloads, 62 baseline BPF counter records, and 62 post-native
  BPF counter records. The post shim log shows 201 `BPF_PROG_LOAD` calls,
  113 native replacements, and 22 explicit manifest no-match pass-throughs.
  No `load program: no such file`, `phase_error`, or endpoint regeneration
  failure string was found in the app payload or post shim log.
- 2026-05-26: Authoritative `tetragon/observer` corpus native-post run with
  BPF stats enabled failed during post-native startup, before workload
  measurement. Artifact:
  `corpus/results/x86_kvm_corpus_20260526_233252_573223/metadata.json`.
  The baseline phase completed with 3 workload samples and 171 BPF counter
  records. The post phase exited after 31 `BPF_PROG_LOAD` calls, 6 native
  replacements, and 4 manifest no-match pass-throughs. Tetragon panicked in
  `ExtendedInfoFromMap(collMaps[id])` because `Program.Info().MapIDs()`
  returned a map id not present in the libbpf collection map table. Root cause:
  the shim returned the native-loader stub fd to the app, so app-visible
  `BPF_OBJ_GET_INFO_BY_FD` observed native-loader program metadata instead of
  original BPF program metadata. Fix target: preserve the original loaded BPF
  prog fd inside the shim and redirect app-visible prog info queries for the
  replacement fd back to that original fd.
- 2026-05-26: Short `tetragon/observer` verification run after adding the
  shim program-info redirect still failed with the same loader panic. Artifact:
  `corpus/results/x86_kvm_corpus_20260526_235351_389554/metadata.json`.
  The shim log confirms `BPF_OBJ_GET_INFO_BY_FD` redirects were active for
  replaced program fds, so the remaining bug is Tetragon's loader assuming
  every `ProgramInfo.MapIDs()` entry has a non-nil entry in `coll.Maps`.
  That assumption is not valid for all loaded program/map combinations. Fixed
  Tetragon's loader to fall back to `ExtendedInfoFromMapID(id)` when the map id
  is absent from `coll.Maps`, and added a nil guard in
  `ExtendedInfoFromMap()`.
- 2026-05-27: Short `tetragon/observer` verification run progressed past the
  previous nil dereference and loaded the base sensor, then failed while loading
  the generic kprobe sensor. Artifact:
  `corpus/results/x86_kvm_corpus_20260527_000124_646747/metadata.json`.
  The error showed `tg_stats_map` map metadata as impossible values
  (`Hash` with random key/value sizes instead of the expected `PerCPUArray`).
  Shim log confirmed fd reuse: a closed native program fd was later reused by a
  map, but stale program state still caused the map's
  `BPF_OBJ_GET_INFO_BY_FD` query to be redirected to the old original program
  fd. Fixed the shim to remove stale same-fd state whenever a new BPF/perf fd
  is recorded, and to redirect object-info queries only when the current fd is
  still a BPF program with the expected kernel program id.
- 2026-05-27: The first smoke after that fd-reuse fix was interrupted because
  baseline `tetragon/observer` stayed in runner-side `list_progs` polling.
  Artifact directory:
  `corpus/results/x86_kvm_corpus_20260527_000825_189724/`.
  The bug was an over-fix in the shim: when a new map/link/perf/raw-tracepoint
  fd reused a closed program fd, the shim deleted the old `prog_entry`
  entirely. That prevents bad app-visible info redirects, but it also removes
  the historical program record that the corpus runner needs from
  `list_progs`. Fixed forward by changing the fd-reuse handling to call
  `prog_forget_loader_fd()`: the current fd is no longer treated as that
  program for future fd-based lookups, while the kernel program id,
  bytecode path, and map snapshot remain available for runner discovery.
- 2026-05-27: Short `tetragon/observer` smoke after preserving historical
  program records completed successfully. Artifact:
  `corpus/results/x86_kvm_corpus_20260527_001857_499465/metadata.json`.
  The app payload has status `ok`, empty error string, one baseline workload,
  one post-native workload, 111 baseline BPF counter records, and 101
  post-native BPF counter records. The post shim log shows 316
  `BPF_PROG_LOAD` calls, 288 native replacements, 5 manifest no-match
  pass-throughs, and 864 program-info redirects. No `panic`,
  `map spec is incompatible`, `load program: no such file`, or `phase_error`
  string was found in the artifact. This verifies the startup correctness
  chain: native replacement keeps original program info visible to the app,
  Tetragon handles map ids absent from `coll.Maps`, and fd reuse no longer
  redirects map info queries to stale program fds.
