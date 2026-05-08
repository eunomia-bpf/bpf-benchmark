# BpfReJIT Evaluation — Methodology and Infrastructure (2026-05-07)

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

| App | Domain | loaded | triggered | retained | Workload | Why triggered ≪ loaded |
| --- | --- | ---: | ---: | ---: | --- | --- |
| `bcc/set` | tracing tools | 21 | 20 | 20 | `stress_ng_os_io_network` | full coverage; the one un-triggered probe is a rare-syscall hook the stressor does not exercise |
| `bpftrace/set` | tracing scripts | 9 | 9 | 8 | `stress_ng_os_io_network` | full coverage |
| `tracee/monitor` | runtime security | 158 | 92 | 81 | `stress_ng_os_io_network` | ≈ 40 % of programs are tail targets (`vfs_*_tail`, `lkm_seeker_*`) and read `run_cnt = 0` (§5.6); the rest are syscalls the stressor does not invoke |
| `tetragon/observer` | runtime security | 287 | 34 | 30 | `stress_ng_os_io_network` | 253 of 287 are tail-called helpers (`process_event` / `filter_arg` / `actions` / `output` chain) — hidden by `run_cnt = 0` accounting (§5.6) |
| `cilium/agent` | k8s data-plane | 53 | 8 | 6 | `network_lossy_multi` | most policy / NodePort / CT programs are tail targets (`run_cnt = 0`); without a Kubernetes pod model many `cil_lxc` / `cil_from_container` slots also stay idle |
| `katran` | L4 XDP load balancer | 1 | 1 | 1 | `xdp_traffic` | standalone-attach exposes only `balancer_ingress`; tail targets reachable through `xdp_root` are bypassed by design |
| `otelcol-ebpf-profiler/profiling` | continuous profiler | 13 | 2 | 1 | `otel_mixed_workload` | only `native_tracer_entry` is directly attached; `perf_unwind_<lang>` × 8 are tail targets and read `run_cnt = 0` even though the workload provably dispatches them (verified via OTEL debug exporter) |

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

This is a *does the system work* question: do the bytecode pass and
the kernel re-JIT cycle complete on real programs without breaking the
running agent? The metric is the per-program ReJIT success rate plus
the agent-side `app.status` outcome — not performance.

Results aggregated across all paper-grade 30 s SAMPLES=3 runs by
*functional condition* (pass list + workload), not by individual run:

| Condition | App payloads | Programs reached | ReJIT-ok | Failed | Success rate | Failure modes |
| --- | ---: | ---: | ---: | ---: | ---: | --- |
| `noop` transform (ReJIT cycle, no bytecode change) | 14 | 1 093 | 1 091 | 2 | **99.8 %** | `EPERM` ×2 |
| `noop` + `map_inline` (bytecode rewriting) | 10 | 766 | 762 | 4 | **99.5 %** | `EBUSY` ×2, `EPERM` ×2 |
| 7-pass kinsn / bytecode mix | 14 | 1 093 | 1 031 | 62 | **94.3 %** | `EBUSY` ×54, `EPERM` ×2, other ×6 |
| `wide_mem` isolated, 7-app | 3 ⚠ | 96 | 93 | 3 | — | **kernel panic**; `EBUSY` ×2, `EPERM` ×1 |
| Single kinsn pass on otel (`prefetch` / `bulk_memory` / `cond_select` / `bulk_memory + prefetch`) | 4 | 52 | 52 | 0 | **100 %** | — |

Findings:

- Every app that produced a payload completed its workload with
  `status=ok`; the bpfopt → BPF_PROG_REJIT loop is functional across
  all 7 production agents under the noop and `map_inline` conditions.
- Success rate degrades with pass-list complexity: 99.8 % (noop) →
  99.5 % (`map_inline`) → 94.3 % (7-pass mix). `EBUSY` from post-swap
  refresh of tail-call poke tables dominates the regression.
- Recurrent `EPERM` is the same kernel rejection across runs: tracee's
  `syscall__init_module` is a direct tail call whose poke table fails
  the `BPF_PROG_REJIT` compatibility check.
- The `wide_mem` isolated 7-app condition triggers a **kernel panic**
  in `trace_call_bpf → kprobe_perf_func` after seven
  `bpf_rejit: retaining old JIT image after refresh failure` warnings
  on tetragon. Root cause is post-swap refresh handling in
  `kernel/bpf/syscall.c:3937`, not `wide_mem` semantics. Investigation:
  `docs/tmp/q5_widemem_kernel_panic_20260507.md`. A rerun with
  `KEEP_WORKDIRS=1` is queued to determine whether the bug is
  deterministic on this graph or a graph-position race.
- ⚠ on `wide_mem` and on the `map_inline` condition flags missing app
  payloads (3 of 7 apps in each case); see §7.

### 6.2 RQ2 — Speedup: does ReJIT deliver per-program speedup above the noise floor?

Per-program geomean of `post / baseline` with `min_runs ≥ 100`
retention; `< 1.0` is speedup.

#### 6.2.1 Noise-floor calibration

| Run | `WARMUPS` | `SKIP_REJIT` | suite geomean | Retained | wins / losses | What it captures |
| --- | ---: | ---: | ---: | ---: | ---: | --- |
| **Q1** | 0 | 0 | **0.9019** | 147 | 73 / 74 | phase variance + full ReJIT cycle |
| **P1** | 0 | 1 | **0.8587** | 147 | 75 / 72 | phase variance only |
| **P2** | 3 | 0 | **0.9035** | 148 | 70 / 78 | Q1 with warm-ups |
| **P3** | 3 | 1 | *pending* | — | — | P1 with warm-ups |

- Suite-level noise amplitude `|Q1 − P1| = 0.0432` is the bar a real
  speedup must clear.
- Warm-ups did not move the suite geomean (P2 ≈ Q1); per-app phase
  variance dominates the noise band, not warm-up state.

Per-app noise intervals `[min(Q1, P1), max(Q1, P1)]` and the speed
threshold (`min − 0.0432`):

| App | Q1 | P1 | noise interval | speed threshold | retained |
| --- | ---: | ---: | --- | ---: | ---: |
| `bcc/set` | 0.9818 | 0.9836 | [0.9818, 0.9836] | 0.9387 | 20 |
| `bpftrace/set` | 1.0217 | 1.0281 | [1.0217, 1.0281] | 0.9786 | 8 |
| `cilium/agent` | 0.9921 | 0.9783 | [0.9783, 0.9921] | 0.9352 | 6 |
| `katran` | 0.9811 | 0.9957 | [0.9811, 0.9957] | 0.9380 | 1 |
| `otelcol-ebpf-profiler/profiling` | 0.9887 | 1.1023 | [0.9887, 1.1023] | 0.9456 | 1 |
| `tetragon/observer` | 1.0336 | 0.9042 | [0.9042, 1.0336] | 0.8611 | 30 |
| `tracee/monitor` | 0.8218 | 0.7888 | [0.7888, 0.8218] | 0.7457 | 81 |

Note: `katran` and `otel` have only 1 retained program each, so a single
sample swings their threshold.

#### 6.2.2 Bytecode-rewriting passes (RQ2a)

| Run | Passes added | App payloads | suite geomean | Retained | Verdict |
| --- | --- | ---: | ---: | ---: | --- |
| **Run 3** | `map_inline` | 3 / 7 ⚠ | 0.8258 | 88 | 9 601 sites applied across cilium / otel / tracee. All three per-app ratios sit *inside* or `low-near` the noise band; **no app crosses its speed threshold**. |
| **Q5** | `wide_mem` | 3 / 7 ⚠ | 0.9976 | 28 | partial; not adjudicable |
| **WMRR** | `wide_mem` rerun | pending | — | — | — |

`const_prop`, `dce`, `bounds_check_merge`, `skb_load_bytes_spec` have no
isolated 30 s run; see §7 open gap.

#### 6.2.3 kinsn-class passes (RQ2b)

| Run | Passes | App payloads | suite geomean | Retained | Verdict |
| --- | --- | ---: | ---: | ---: | --- |
| **Run 4** | 7-pass mix ¹ | 7 / 7 | 0.8953 | 148 | suite geomean is *worse* than Q1 (0.9019). The otel cell is 0.6258 (clear-low against the otel interval), but the pass list is mixed so attribution is ambiguous. |
| **Q4** | `prefetch` | **1 / 7 ⚠** | 1.0651 | 20 | only `bcc/set` payload — **the prefetch-only 7-app dataset is missing.** |
| **Q6** | `prefetch` | otel only | 1.0107 | 1 | inside otel interval [0.9887, 1.1023] |
| **Q7** | `bulk_memory` | otel only | 0.9901 | 1 | inside otel interval |
| **Q8** | `cond_select` | otel only | 1.0212 | 1 | inside otel interval |
| **Q9** | `bulk_memory, prefetch` | otel only | 0.9895 | 1 | inside otel interval |

¹ Run 4 pass list = `rotate, cond_select, extract, endian_fusion,
bulk_memory, skb_load_bytes_spec, wide_mem` — by §2 taxonomy this is a
*kinsn ∪ bytecode-rewriting* mix; attribution from Run 4 alone is not
clean.

#### 6.2.4 Pass × app applied-site counts (Run 3 + Run 4)

| pass | bcc | bpftrace | cilium | katran | otel | tetragon | tracee |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| `map_inline` (Run 3) | n/a | n/a | 1 454 | n/a | 1 192 | n/a | 5 |
| `rotate` (Run 4) | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| `cond_select` (Run 4) | 8 | 4 | 208 | 7 | 45 | 1 331 | 391 |
| `extract` (Run 4) | 1 | 0 | 0 | 0 | 36 | 112 | 37 |
| `endian_fusion` (Run 4) | 1 | 1 | 24 | 6 | 4 | 210 | 4 |
| `bulk_memory` (Run 4) | 0 | 0 | 5 | 0 | 1 | 163 | 117 |
| `skb_load_bytes_spec` (Run 4) | 0 | 0 | 4 | 0 | 0 | 0 | 0 |
| `wide_mem` (Run 4) | 0 | 10 | 0 | 4 | 132 | 2 826 | 179 |

Passes with no applied site in any 30 s 7-app run: `rotate`,
`bounds_check_merge`, `branch_flip` (latter is out of scope).

#### 6.2.5 Speedup verdict

> **No optimization pass produces a paper-grade speedup that crosses its
> per-app threshold in any completed dataset.**

- Suite geomean for every pass-coverage run (Run 3 0.8258, Run 4
  0.8953) is dragged below 1.0 by tracee's already-low noise interval
  ([0.7888, 0.8218]); the suite-level number is therefore not
  interpretable as ReJIT speedup.
- Per-app: every cell in §6.2.2 / §6.2.3 lands *inside* the per-app
  interval or only `near` it (within 0.0432 of the floor). The
  strongest app-level low mark is otel 0.6258 in Run 4 (clear-low
  against its interval), but the pass list is a 7-pass mix and
  Q6 – Q9 single-pass otel runs all sit inside the otel interval, so
  no individual pass is yet attributable.
- The closest follow-up candidate is `map_inline` on otel: an earlier
  non-paper-grade run (`x86_kvm_corpus_20260507_072543_601953`) reports
  otel geomean 0.6567 with applied = 1 192, driven by
  `tracepoint__sched_process_free` (ratio 0.4225, min_runs 163). Run 3
  does not reproduce because the same program drops below the
  `min_runs ≥ 100` retention threshold there.
- The pass-signal audit (`docs/tmp/pass_signal_audit_20260508.md`)
  enumerates every pass × app cell with the same threshold rule and
  reaches the same conclusion.

### 6.3 Excluded from analysis

- Pre-19:00 runs on 2026-05-07: exploratory dev runs with
  `WORKLOAD_DURATION=3 s`, superseded by 30 s reruns.
- 22:00 – 22:39 noop SAMPLES=1 smokes: post-refactor sanity checks.
- 22:44 prefetch run with `status=error`: aborted Q4 attempt.
