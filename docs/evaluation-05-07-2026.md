# BpfReJIT Evaluation — Methodology and Infrastructure (2026-05-07)

TL'DR:

- Do observe improves, but not sure whether it's noise or benchmark issues.
- Not significant imrpovements if we exclude noise.

## 1. System Under Test

- **What it does**: re-JIT already-loaded eBPF programs in place: re-generate the BPF bytecode and replace in place transparently and keep all safety model.
- **Kernel**: forked Linux 7.0-rc2.
  - Two added syscall commands: `BPF_PROG_REJIT`, `BPF_PROG_GET_ORIGINAL`.
  - Modify kernel to support kinsn.
  - Modify kernel to support re-JIT and replace the hooks in place.
- *kinsn* modules expose arch-specific code sequences (byte-swap `MOVBE`, `cmov`, prefetch, rotate, `BEXTR`, bulk `memcpy`/`memset`) as JIT inline-emit hooks invoked through kfunc calls.

```
   runner ──socket──▶  bpfrejit-daemon  ──fork+exec──▶  bpfopt --pass <name>
   (Python)            (Rust)                          (Rust, pure bytecode)
                          │
                          │ kernel-sys
                          ▼
                       BPF_PROG_REJIT(log_level=2)
```

- **`bpfrejit-daemon`** (Rust) — only userspace component that calls BPF
  syscalls.
  - Live program discovery; side-input preparation (map values, BTF, fd-array
    from `prog_info.used_maps`).
  - Per-pass orchestration: `fork+exec bpfopt` → kernel re-JIT.
  - No in-process bytecode transform; no default pass policy.
- **`bpfopt`** (Rust) — pure-bytecode CLI.
  - `stdin = bpf_insn[]`, `stdout = bpf_insn[]`, `--report = JSON`.
  - One invocation = one named pass.
  - Zero kernel dependency.
- **Per-pass loop** (per program):
  1. daemon writes verifier states + side-inputs to files
  2. `bpfopt --pass <name>` rewrites bytecode
  3. daemon issues `BPF_PROG_REJIT(log_level=2)`; kernel re-verifies + re-emits
  4. on failure → recorded in result JSON, no fallback, no retry

## 2. Optimization Passes

Three classes; every benchmark run selects an explicit subset via
`BPFREJIT_BENCH_PASSES`.

### 2.1 kinsn-class — replace bytecode with a kfunc, lowered by an in-kernel kinsn module via `KFUNC_INLINE_EMIT`

- **`rotate`** — shift+or pair → native rotate (`bpf_rotate{32,64}`)
- **`cond_select`** — branch+select → `cmov` (`bpf_select64`)
- **`ccmp`** *(arm64-only)* — same-target zero-test AND chain → conditional-compare (`bpf_ccmp`)
- **`extract`** — bit-field extract → BMI `BEXTR` (`bpf_extract64`)
- **`endian_fusion`** — load+`bswap` → `MOVBE` (`bpf_endian_load{16,32}`)
- **`bulk_memory`** — scalarized `memcpy`/`memset` → SIMD or `REP MOVS`
  (`bpf_memcpy` / `bpf_memset`)
- **`prefetch`** — insert `prefetch` ahead of pointer-chasing loads
  (`bpf_prefetch`)

### 2.2 Bytecode-rewriting — pure BPF→BPF, no kfunc; kernel JIT lowers as usual

- **`noop`** — no transform pass
- **`wide_mem`** — collapse byte-by-byte ladder into one wide `LDX_MEM`
  (size `H` / `W` / `DW`)
- **`map_inline`** — speculate constant `bpf_map_lookup_elem` results from
  captured map values
- **`const_prop`** — propagate verifier-known constants, fold uses
- **`dce`** — drop instructions dead under verifier liveness
- **`bounds_check_merge`** — merge redundant bounds checks on the same range
- **`skb_load_bytes_spec`** — specialize `bpf_skb_load_bytes` to fixed-width
  loads

## 3. Workload Suite — 7 production eBPF applications

Selection criteria:

- real, deployed eBPF — no synthetic micro-loops, no test programs
- diverse program types: `kprobe`, `tracepoint`, `raw_tp`, `socket_filter`,
  `tc`, `xdp`, `LSM`
- spanning the four large eBPF use-case classes (tracing, security,
  networking, profiling)
- launched through the upstream binary; the framework loads no `.bpf.o`
  files of its own

"Programs" columns from the most recent paper-grade 7-app baseline (Q1
`noop` ReJIT, 2026-05-07 19:05Z, 30 s `stress_ng_os_io_network` /
workload-specific):

- **loaded** — `bpftool prog show` count after agent startup
- **triggered** — programs with `run_cnt_delta > 0` in baseline phase
  (dispatched at least once during the 30 s workload)
- **retained** — `run_cnt_delta ≥ 100`; the population that enters the
  per-program geomean per §5
- **median run_cnt** — median per-program dispatch count over 30 s in
  the retained population (per-program distributions are heavy-tailed,
  so median is more representative than mean)

| App | Domain | loaded | triggered | retained | median run_cnt | Workload | Why triggered ≪ loaded |
| --- | --- | ---: | ---: | ---: | ---: | --- | --- |
| `bcc/set` | tracing tools | 21 | 20 | 20 | 6.4 M | `stress_ng_os_io_network` | full coverage; the one un-triggered probe is a rare-syscall hook the stressor does not exercise |
| `bpftrace/set` | tracing scripts | 9 | 9 | 8 | 18 M | `stress_ng_os_io_network` | full coverage |
| `tracee/monitor` | runtime security | 158 | 92 | 81 | 1.8 M | `stress_ng_os_io_network` | ≈ 40 % of programs are tail targets (`vfs_*_tail`, `lkm_seeker_*`) and read `run_cnt = 0` (§5.6); the rest are syscalls the stressor does not invoke |
| `tetragon/observer` | runtime security | 287 | 34 | 30 | 0.7 M | `stress_ng_os_io_network` | 253 of 287 are tail-called helpers (`process_event` / `filter_arg` / `actions` / `output` chain) — hidden by `run_cnt = 0` accounting (§5.6) |
| `cilium/agent` | k8s data-plane | 53 | 8 | 6 | 1.6 M | `network_lossy_multi` | most policy / NodePort / CT programs are tail targets (`run_cnt = 0`); without a Kubernetes pod model many `cil_lxc` / `cil_from_container` slots also stay idle |
| `katran` | L4 XDP load balancer | 1 | 1 | 1 | 3.2 M | `xdp_traffic` | standalone-attach exposes only `balancer_ingress`; tail targets reachable through `xdp_root` are bypassed by design |
| `otelcol-ebpf-profiler/profiling` | continuous profiler | 13 | 2 | 1 | **0.14 M** | `otel_mixed_workload` | only `native_tracer_entry` is directly attached; `perf_unwind_<lang>` × 8 are tail targets and read `run_cnt = 0` even though the workload provably dispatches them (verified via OTEL debug exporter) |

### 3.1 Workload specifications

Every workload runs for `WORKLOAD_DURATION` seconds (default 30 s) per phase
and is replayed identically in `baseline` and `post_rejit`.

| Workload | Generator | Composition | What it exercises |
| --- | --- | --- | --- |
| `stress_ng_os_io_network` | `stress-ng` | `--os` + `--io` + `--network` + `--memory` + `--filesystem` stressors run concurrently (`syscall`, `epoll`, `udp`, `sock*`, `mmap`, `aio`, `iomix`, `dentry`, `file-ioctl`, …) | High-rate kprobe / tracepoint dispatch on syscalls, VFS, sockets, scheduler — the dominant load for tracing and security agents |
| `network_lossy_multi` | `netem` + `wrk` + `ping` | 20 % loss + 50 ms delay on the iface; `wrk -t4 -c50` HTTP load (≈10 K connect events/s); concurrent high-rate ICMP probes | Multi-protocol datapath: ICMP, TCP, retransmits, conntrack — drives cilium tc/xdp policy slots beyond plain HTTP |
| `xdp_traffic` | `wrk` | `wrk -t2 -c10` HTTP keep-alive (≈30 K – 100 K req/s) with steady packet flow through the iface | Sustained packet ingress for `XDP` programs; goal is throughput, not connect-rate |
| `otel_mixed_workload` | 5 language interpreters + `stress-ng` | Concurrent SHA-256(1 KiB) loops in Python / Ruby / Node.js / Perl / PHP using only stdlib + `stress-ng --cpu` for native frames | Drives `perf_event` samples into interpreter PC ranges so `perf_unwind_<lang>` tail programs dispatch; native loop drives `perf_unwind_native` |

## 4. Experimental Setup

- **Primary platform — virtme-ng KVM**, x86_64
  - Host: 16 vCPU, 64 GiB RAM, Intel Core Ultra 9 285K
  - Guest: Docker-in-VM for app stack
- **Secondary platform — AWS** (cross-architecture validation only)
  - x86: `t3.small` ; arm64: `t4g.small` ; kernel test: `t3.micro`/`t4g.micro`
- **Kernel**: forked Linux 7.0-rc2 (`vendor/linux-framework`); same build
  on KVM and AWS

### 4.1 Per-run protocol

Three measured phases per app per sample, repeated `SAMPLES` times:

```
   ┌──────────────┐    ┌──────────────────────────┐    ┌──────────────┐
   │  baseline    │ →  │       ReJIT              │ →  │  post_rejit  │
   │              │    │   for each pass:         │    │              │
   │  run         │    │     bpfopt --pass X      │    │  run         │
   │  workload    │    │     | BPF_PROG_REJIT     │    │  workload    │
   │  for         │    │   per-program            │    │  for         │
   │  WORKLOAD_   │    │   success/failure        │    │  WORKLOAD_   │
   │  DURATION s  │    │   captured               │    │  DURATION s  │
   └──────┬───────┘    └─────────┬────────────────┘    └──────┬───────┘
          │                      │                            │
          ▼                      ▼                            ▼
     run_cnt_delta,         result.json                  run_cnt_delta,
     run_time_ns_delta      per-program record           run_time_ns_delta
     per BPF program                                     per BPF program
```

- `bpf_enable_stats(BPF_STATS_RUN_TIME)` is enabled for the whole run;
  per-phase deltas are computed from `bpftool prog show` snapshots taken
  at phase boundaries
- `BPFREJIT_BENCH_PASSES` selects the pass list; the same list runs in the
  ReJIT phase of every sample
- Default knobs: `SAMPLES=3`, `WORKLOAD_DURATION=30 s`, `min_runs ≥ 100`
  filter applied at analysis time

## 5. Measurement Methodology

The framework writes only raw counters; every paper number is computed
post-hoc from `result.json` by `analysis/corpus_analyze.py`.

### 5.1 Per-program ratio

For each BPF program with `run_cnt_delta > 0` in both phases:

```
b_avg = baseline.run_time_ns_delta   /  baseline.run_cnt_delta
p_avg = post_rejit.run_time_ns_delta /  post_rejit.run_cnt_delta
ratio = p_avg / b_avg                          # < 1.0 ⇒ ReJIT faster
```

### 5.2 Threshold filter (mandatory)

- Drop programs where `min(baseline.run_cnt, post_rejit.run_cnt) < 100`.
- Empirical noise floor on the corpus drops sharply at this cutoff
  (CV 29.6 % unfiltered → 17.7 % at ≥ 100). Above 100 the CV stays flat
  through ≥ 100 K, so 100 captures the noise-reduction inflection point
  while retaining maximum program coverage (127 vs 90 programs at ≥ 10 K).
- Any change to this threshold requires re-measuring CV on the new
  dataset; ad-hoc thresholds are forbidden.

### 5.3 Headline metric — per-program geometric mean

```
geomean = exp( mean( log(ratio_i) ) )    over all retained programs
```

- Units: `< 1.0` is speedup, `> 1.0` is slowdown.
- Reason for geometric mean: ratio data; arithmetic mean is mathematically
  wrong, log/sqrt-weighted variants have no physical justification.

### 5.4 Supplemental — wins / losses / ties

- `wins`  : programs with `ratio < 1.0`
- `losses`: programs with `ratio > 1.0`
- `ties`  : programs with `ratio == 1.0`

Reported alongside the geomean as a sanity check on direction.

### 5.5 Confidence

Bootstrap CIs are taken over per-program ratios across the retained
population, not across cross-suite-run replication. Both `SAMPLES=1` and
`SAMPLES=3` produce paper-quotable numbers as long as retained-program
coverage is non-trivial.

### 5.6 Tail-call accounting caveat

Programs entered through `bpf_tail_call(ctx, &progs, key)` are jumped to
at `bpf_func + X86_TAIL_CALL_OFFSET` (and the equivalent on arm64). This
**skips the prologue** that increments `bpf_prog->stats.cnt` and
`stats.nsecs`. Consequences for measurement:

- `bpftool prog show` reports `run_cnt = 0` and `run_time_ns = 0` for
  every tail-called program, even when it executes on every dispatch.
- The `min_runs ≥ 100` filter therefore drops every tail target;
  per-program ratios are computed only for the **directly attached
  caller**.
- The caller's `run_time_ns` already includes time spent in every
  tail-called descendant, because the tail call jumps inline (control
  does not return). Optimizations applied to a tail target therefore
  show up at the caller's ratio.
- Concrete chains in this suite:
  - tetragon: `generic_kprobe_event` → `process_event` / `filter_arg`
    / `actions` / `output`
  - tracee: `lkm_seeker_*`, `vfs_*_tail`
  - cilium: NodePort / CT / policy `tail_*`
  - otel: `native_tracer_entry` → `perf_unwind_<lang>` (×8)
  - katran (pre-fix): `xdp_root` → `balancer_ingress`; bypassed by
    standalone-attach mode
- When evaluating coverage of tail-called programs, verify execution via
  profiler-side telemetry (e.g. OTEL debug exporter sample dump showing
  interpreter frame names) or by re-attaching the program directly so it
  becomes the entry point.

## 6. Research Questions and Datasets

Two RQs drive the evaluation. All runs below: KVM x86, `SAMPLES=3`,
`WORKLOAD_DURATION=30 s`, 7-app set unless noted.

### 6.1 RQ1 — Functional: does in-place ReJIT actually transform loaded programs and keep agents running?

The metric is the per-program ReJIT success rate plus
the agent-side `app.status` outcome — not performance.


| Condition | App payloads | Programs reached | ReJIT-ok | Failed | Success rate | Failure modes |
| --- | ---: | ---: | ---: | ---: | ---: | --- |
| `noop` transform (ReJIT cycle, no bytecode change) | 7 / 7 | 542 | 541 | 1 | **99.8 %** | `EPERM` ×1 |
| `noop` + `map_inline` (bytecode rewriting) | 7 / 7 | 542 | 540 | 2 | **99.6 %** | `EBUSY` ×1, `EPERM` ×1 |
| 7-pass mix: `rotate, cond_select, extract, endian_fusion, bulk_memory, skb_load_bytes_spec, wide_mem` | 7 / 7 | 542 | 512 | 30 | **94.5 %** | `EBUSY` ×27, `EPERM` ×1, other ×2 |
| `prefetch` isolated | 7 / 7 (cilium wrk timed out) | 545 | 530 | 15 | **97.2 %** | `EBUSY` ×10, `EPERM` ×1, other ×4 |
| `wide_mem` isolated | 3 / 7 ⚠ | 96 | 93 | 3 | — | **kernel panic**; `EBUSY` ×2, `EPERM` ×1 |
| Single kinsn pass on otel | 1 / 1 each ×4 | 52 (4 ×13) | 52 | 0 | **100 %** | — |

Findings:

- Every app that produced a payload completed its workload with
  `status=ok`; the bpfopt → BPF_PROG_REJIT loop is functional across
  all 7 production agents under the noop and `map_inline` conditions.
- Success rate degrades with pass-list complexity: 99.8 % (noop) →
  99.6 % (`map_inline`) → 94.5 % (7-pass mix). `EBUSY` from post-swap
  refresh of tail-call poke tables dominates the regression.
- Recurrent `EPERM` is the same kernel rejection across runs: tracee's
  `syscall__init_module` is a direct tail call whose poke table fails
  the `BPF_PROG_REJIT` compatibility check.
- The `wide_mem` isolated 7-app condition triggers a **kernel panic**
  in `trace_call_bpf → kprobe_perf_func` after seven
  `bpf_rejit: retaining old JIT image after refresh failure` warnings
  on tetragon. Root cause is post-swap refresh handling in
  `kernel/bpf/syscall.c:3937`, not `wide_mem` semantics. Investigation:
  `docs/tmp/q5_widemem_kernel_panic_20260507.md`.

#### 6.1.1 Bytecode-pass apply rate (per app × condition)

`bpfopt` reports `sites_matched` (candidates the pass found) and
`sites_applied` (candidates actually rewritten — the rest fail safety
filters such as live-out registers, alignment, BTF-pointer rules). Each
cell below shows `applied / matched`.

Sources: `map_inline` from the merged 7-app dataset; `wide_mem`,
`cond_select`, `bulk_memory`, `endian_fusion`, `extract`,
`skb_load_bytes_spec`, `rotate` from Run 4 (7-pass mix); `prefetch`
from the prefetch-only 7-app run at 2026-05-07 22:44Z (suite-status
`error` because cilium's wrk client timed out; per-app payloads are
intact for all 7 apps).

| Pass | bcc | bpftrace | cilium | katran | otel | tetragon | tracee |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| `map_inline` | 0 / 12 | 0 / 16 | 1 454 / 1 824 | 0 / 14 | 1 192 / 1 264 | 0 / 765 | 5 / 1 725 |
| `wide_mem` | 0 / 0 | 10 / 18 | 0 / 0 | 4 / 4 | 132 / 137 | 2 826 / 2 826 | 179 / 229 |
| `cond_select` | 8 / 8 | 4 / 4 | 208 / 218 | 7 / 7 | 45 / 47 | 1 331 / 1 753 | 391 / 400 |
| `bulk_memory` | 0 / 0 | 0 / 0 | 5 / 5 | 0 / 0 | 1 / 1 | 163 / 165 | 117 / 214 |
| `endian_fusion` | 1 / 1 | 1 / 1 | 24 / 24 | 6 / 6 | 4 / 4 | 210 / 210 | 4 / 4 |
| `extract` | 1 / 1 | 0 / 0 | 0 / 0 | 0 / 0 | 36 / 36 | 112 / 112 | 37 / 47 |
| `prefetch` | 3 / 3 | 9 / 9 | 430 / 430 | 44 / 44 | 415 / 415 | 1 526 / 1 526 | 1 770 / 1 770 |
| `skb_load_bytes_spec` | 0 / 0 | 0 / 0 | 4 / 166 | 0 / 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| `rotate` | 0 / 0 | 0 / 0 | 0 / 0 | 0 / 0 | 0 / 0 | 0 / 0 | 0 / 0 |

Passes omitted (no useful data in any 30 s 7-app run): `noop` (producer
pass, always 0 / 0), `const_prop`, `dce`, `bounds_check_merge` (no
isolated 30 s run), `ccmp` (arm64-only).

Observations:

- `map_inline` finds candidates almost everywhere (1 824 in cilium,
  1 725 in tracee, 1 264 in otel, 765 in tetragon) but **applies only
  where captured map values are constant**: cilium 80 %, otel 94 %, but
  0 % on bcc / bpftrace / katran / tetragon and 0.3 % on tracee. Needs further investigation.
- `cond_select` apply rate dips on tetragon (1 331 / 1 753 ≈ 76 %),
  pulling the 7-pass mix's overall apply rate down.
- `rotate` finds zero candidates in the 7-app corpus; the workload
  exposes no shift+or pairs that survive verifier range tracking.
- `skb_load_bytes_spec` matches 166 cilium sites but applies only 4
  (≈ 2.4 %) — almost all cilium `bpf_skb_load_bytes` calls fail the
  fixed-width specialization safety check.

### 6.2 RQ2 — Speedup: does ReJIT deliver per-program speedup above the noise floor?

Per-program geomean of `post / baseline` with `min_runs ≥ 100`
retention; `< 1.0` is speedup.

#### 6.2.1 Per-app geomean × condition

Single unified table: rows are conditions (noise-floor at top, then pass
coverage), columns are per-app and suite geomean. `< 1.0` is speedup.
Every cell that *should* be 1.0 (the noise-floor rows) is the empirical
phase-variance reference; everything below the noise rows is what a
pass coverage run produces.

| Condition | bcc | bpftrace | cilium | katran | otel | tetragon | tracee | suite | retained |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| `noop` ReJIT | 0.9818 | 1.0217 | 0.9921 | 0.9811 | 0.9887 | 1.0336 | 0.8218 | **0.9019** | 147 |
| `noop` SKIP_REJIT | 0.9836 | 1.0281 | 0.9783 | 0.9957 | 1.1023 | 0.9042 | 0.7888 | **0.8587** | 147 |
| `noop` + `map_inline` | 1.0097 | 1.0118 | 0.9728 | 0.9915 | **0.6567** | 1.0256 | 0.8150 | 0.8943 | 148 |
| `prefetch` | 1.0154 | 0.9895 | — (wrk timed out) | 0.9963 | **0.7186** | 1.0175 | 0.8112 | 0.8880 | 142 |
| 5-pass kinsn: `rotate, cond_select, extract, endian_fusion, bulk_memory` | 0.9896 | 1.0117 | 0.9951 | 0.9639 | 0.9891 | 1.0783 | 0.8171 | 0.9074 | 147 |
| 6-pass kinsn + prefetch: above + `prefetch` | 1.0289 | 1.0165 | 1.0066 | 0.9423 | 1.0056 | 1.0468 | 0.8067 | 0.9009 | 147 |
| All bytecode-rewriting: `noop, wide_mem, const_prop, dce, bounds_check_merge, skb_load_bytes_spec` | *pending* | *pending* | *pending* | *pending* | *pending* | *pending* | *pending* | *pending* | — |

### Findings

- **bcc, bpftrace, cilium, katran, tetragon** — every condition lands
  within ±1–3 % of the per-app noise bracket. No condition exceeds the
  per-app noise floor on these 5 apps.
- **otel — retained set is split between one stable program and one
  unstable tracepoint.** `native_tracer_entry` (perf_event, ~140 M
  runs) is high-frequency and balanced across phases. The remaining slot is
  filled — only when it clears `min_runs ≥ 100` — by a low-frequency
  tracepoint, `sched_process_free`, whose own per-phase trigger count
  is workload-driven and not stable: in the `map_inline` 0.6567 cell
  it fired 163 vs 1 422 times across baseline / post (8.7× asymmetry).
  6 `map_inline` sites on it actually fired. Whether its 0.42 per-
  program ratio reflects the optimization, the trigger asymmetry, or
  some mix is unknown and not resolvable from this run. The "clear-
  low" otel cells (0.6258 – 0.7186) ride on this single low-runs
  outlier; they are not interpretable at the current threshold.
- **tracee — phase bias dominates the geomean.** Every condition,
  including the pure-phase-variance controls, lands in 0.79 – 0.84.
  A systematic drift below 1.0 under no bytecode change implies a
  baseline-vs-post phase bias on tracee's 81 retained programs that
  is independent of any pass; per-pass speedup on tracee cannot be
  separated from this drift.

### What we cannot conclude

- No condition produces an app-level row that clears its own noise
  bracket by more than 1–3 %.
- The suite geomean below 1.0 in every condition is consistent with
  tracee's phase bias and otel's structural fragility, not with a
  demonstrable per-pass speedup.
- For paper-grade quotes: report otel on `native_tracer_entry` only,
  or raise the retention threshold to ≥10 K to drop the `sched_process_
  free` outlier; report tracee with an explicit phase-bias caveat or
  exclude it from suite-level claims.

### 6.2.2 App-side workload throughput

Per-app throughput recorded in `baseline.workloads[]` /
`post_rejit.workloads[]`. Each cell is `post / baseline`, mean over 3
samples (same `SAMPLES=3` runs as §6.2.1). Values >1.0 = app went
faster after ReJIT.

Per-app throughput metric:

- `bcc, bpftrace, tetragon, tracee` — `stress-ng` total bogo ops
  (sum of 63 stressors per 30 s sample)
- `katran` — `wrk Requests/sec`
- `cilium` — `wrk Requests/sec`
- `otel` — total SHA-256 ops across 5 interpreters + `stress-ng --cpu`
  bogo ops per 30 s

| Condition | bcc | bpftrace | cilium | katran | otel | tetragon | tracee |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| `noop` ReJIT | 0.985 | 0.961 | 0.980 | 1.007 | 1.004 | 0.874 | 1.132 |
| `noop` SKIP_REJIT | 1.043 | 1.040 | 1.071 | 1.001 | 0.992 | 1.268 | 0.919 |
| `noop` ReJIT + warm-up=3 | 1.098 | 0.798 | 1.034 | 1.014 | 0.999 | 0.903 | 0.806 |
| `noop` + `map_inline` | 0.809 | 0.913 | 1.040 | 1.004 | 0.997 | 1.279 | 1.144 |
| `prefetch` | 1.191 | 0.913 | — | 1.006 | 0.989 | 0.766 | 0.818 |
| 5-pass kinsn: `rotate, cond_select, extract, endian_fusion, bulk_memory` | 0.925 | 1.093 | 0.940 | 0.995 | 1.001 | 1.242 | 1.051 |
| 6-pass kinsn + prefetch: above + `prefetch` | 1.126 | 1.058 | 0.969 | 1.013 | 1.001 | 0.977 | 1.139 |
| All bytecode-rewriting: `noop, wide_mem, const_prop, dce, bounds_check_merge, skb_load_bytes_spec` | *pending* | *pending* | *pending* | *pending* | *pending* | *pending* | *pending* |

How to read this:

- The `noop` rows are app-side phase noise. stress-ng-driven apps
  (bcc / bpftrace / tetragon / tracee) swing 0.80 – 1.27 across the
  three controls — about **±27 %**. `katran` / `otel` / `cilium` swing
  ±2 – 7 %.
- **No optimization-condition cell exceeds its own per-app noise band
  on stress-ng-driven apps.** Reading bcc 1.19 in `prefetch`,
  tetragon 1.28 in `noop+map_inline`, or tracee 1.14 in
  `noop+map_inline` as ReJIT speedup is not separable from the noise
  envelope visible in the three `noop` rows.
- `katran` and `otel` are within ±1 % of 1.0 in every condition,
  including controls — consistent with their generators (`wrk` /
  fixed-iteration SHA-256 loops) being far less phase-sensitive than
  stress-ng. App-side throughput has no detectable signal on these
  two apps either.

### TODO

- improve map inline to make it actaully inline more; fix the 0 % apply rate in 5 of 7 apps (e.g. katran). We can fix it by allowing user provide map content and does not require the map key is const.
- check more details about otel and tracee's improvement. Is it benchmark framework issue or actual improvement?
- Why kinsn does not work well?
