# Benchmark Framework Stability Timeline and Session Analysis

Generated: 2026-06-24

## 1. Framework Stabilization Timeline

### Phase 1: Initial Architecture (March 2026)

**Key commits establishing the framework:**

- `2026-03-28` — Benchmark configuration with policy rules and pass management introduced
- `2026-03-29` — Major cleanup: deleted non-conforming code (commit `8565cbb55`)
- `2026-03-29` — Post-cleanup architecture fixes (`ba92406d7`)
- `2026-03-30` — Framework blockers fixed, strict review cleanup (`7a6264399`)
- `2026-03-31` — Tightened benchmark metadata, pass split analysis (`e6f043c1f`)

**Early corpus results (March 30-31):**
- `vm_corpus_20260331_*` — Multiple runs establishing baseline
- Initial `optimization_summary` structure with geomean computation

### Phase 2: Methodology Formalization (April-May 2026)

**App corpus finalization:**

- `2026-04-23` — Six production workload variants added (`47f3295c0`)
- `2026-04-25` — SCX removed from framework (`764043c50`)
- `2026-04-25` — "Keep only supported macro apps" (`30dc544f1`)
- `2026-05-04` — Calico removed (`d88b7c6ed`)
- `2026-05-06` — bcc/set merged runner introduced (`c75bf9d59`)
- `2026-05-20` — bpftrace scripts removed (`27d279968`)

**Final 6-app corpus (stabilized by May 20):**
1. `bcc/set` (combined 8-tool runner)
2. `otelcol-ebpf-profiler/profiling`
3. `cilium/agent`
4. `tetragon/observer`
5. `katran`
6. `tracee/monitor`

**Methodology in CLAUDE.md (stabilized May 5):**

- `2026-05-05` — "SAMPLES cap is 3, paper-grade by min_runs filter" (`af7fab658`)

Core methodology rules:
- Per-program ratio: `ratio = post_rejit_avg_ns / baseline_avg_ns`
- Threshold filter: `min(baseline_runs, post_rejit_runs) >= 100` (mandatory)
- Noise floor CV: 29.6% unfiltered drops to 17.7% at >= 100 runs
- Headline metric: geometric mean of per-program ratios
- SAMPLES=1 or SAMPLES=3 both valid when min_runs passes

---

## 2. Chronological Session Inventory

### March 2026 — Framework Bootstrapping

| Date | Session | Type | Key Results | Issues |
|------|---------|------|-------------|--------|
| 2026-03-14 | `vm_micro_authoritative_20260314` | micro | Overall 1.054x, applied-only 1.074x, 16/62 applied | VM noise, >10% variance on non-applied |
| 2026-03-18 | `vm_micro_authoritative_20260318` | micro | Similar to 03-14 | - |
| 2026-03-22 | E2E Tracee/Tetragon | e2e | Tracee exec_storm +5.47%, Tetragon connect_storm +16.69% | file_io regression -25%, open_storm +74% BPF overhead |
| 2026-03-26 | `vm_corpus_20260326_045557` | corpus | Initial runs | Framework stabilizing |
| 2026-03-31 | `vm_corpus_20260331_*` | corpus | Multiple runs | Architecture solidifying |

### April 2026 — App Selection Iterations

| Date | Session | Type | Key Results | Issues |
|------|---------|------|-------------|--------|
| 2026-04-03 | `debug_scx_full_20260403_201049` | corpus | SCX debugging | SCX struct_ops crashes |
| 2026-04-09 | `x86_kvm_corpus_20260409_*` | corpus | Multiple runs, ~26K metadata | Iterating pass configs |
| 2026-04-12 | `x86_kvm_corpus_20260412_071101_774623` | corpus | all_geomean 1.027x, 6/9 applied | katran error, bcc unchanged |
| 2026-04-18 | `x86_kvm_micro_20260418_004726_916783` | micro | Micro baseline | - |
| 2026-04-21 | `x86_kvm_corpus_20260421_181829_750236` | corpus | all_geomean 1.010x, 10/48 applied | 38 programs excluded (no_programs_changed_in_loader) |

### May 2026 — Intensive Development & KOperation Integration

| Date | Session | Type | Key Results | Issues |
|------|---------|------|-------------|--------|
| 2026-05-04 | Various corpus runs | corpus | Low-trigger app analysis | - |
| 2026-05-06 | bcc/set runner introduced | - | Combined 8 BCC tools | - |
| 2026-05-13-14 | Multiple runs | corpus | Pass refinement | wide_mem rejit rejection on tetragon |
| 2026-05-20 | bpftrace removed | - | 6-app corpus finalized | - |
| 2026-05-21 | `aws_arm64_micro_*` | micro | ARM64 micro runs | - |
| 2026-05-22 | `aws_arm64_micro_20260522_*` | micro | ARM64 extensive micro | - |
| 2026-05-29 | Native evaluation | corpus | native/eBPF geomean 1.349x, OTEL 14.81x BPF speedup | tracee shows no improvement |

### June 2026 — KOperation All-Force Evaluation

| Date | Session | Type | Key Results | Issues |
|------|---------|------|-------------|--------|
| 2026-06-02 | `x86_kvm_corpus_20260602_*` | corpus | LEA pass testing | - |
| 2026-06-03 | `x86_kvm_corpus_20260603_175429_964295` | corpus | **All-force kop: BPF geomean 0.938x (6.2% speedup)** | 27085 sites applied |
| 2026-06-04 | `x86_kvm_corpus_20260604_*` | corpus | KOperation corpus continuation | - |
| 2026-06-05 | `aws_arm64_micro_20260605_*` | micro | ARM64 kop ablation | - |
| 2026-06-06 | `aws_arm64_micro_20260606_001225_821028` | micro | **ARM64 kop: geomean 1.208x (20.8% speedup)**, 24 wins / 2 losses | - |
| 2026-06-15-17 | `aws_arm64_corpus_2026061*` | corpus | ARM64 corpus runs | Some metadata empty (incomplete) |
| 2026-06-22 | `x86_kvm_corpus_20260622_*` | corpus | Many runs same day | Running/recent |

---

## 3. Authoritative Sessions for Paper

### Micro Benchmark — March 14, 2026

**Session:** `vm_micro_authoritative_20260314.json`

- Platform: virtme-ng KVM, Intel Core Ultra 9 285K
- Kernel: 7.0.0-rc2-g7de19ef03692
- Runtimes: llvmbpf, kernel, kernel-recompile
- Iterations: 3, warmups: 2, repeat: 500
- Result: Overall **1.054x** (VM noise warning)
- Applied-only: **1.074x** (16/62 applied)

### Corpus Benchmark — June 3, 2026 (All-Force KOperation)

**Session:** `x86_kvm_corpus_20260603_175429_964295`

- Apps: 6 (bcc/set, otel, cilium, tetragon, katran, tracee)
- Samples: 3
- Workload duration: 30s
- Pass: All-force kop (lea dominant)
- **BPF all-qualified geomean: 0.938x** (6.2% improvement)
- **BPF direct-self-applied geomean: 0.933x** (6.7% improvement)
- Applied sites: 27085 (lea=26097, cond_select=988)
- Workload throughput post/baseline geomean: 1.081x

**Per-app breakdown:**
| App | BPF geomean | Wins/Losses |
|-----|-------------|-------------|
| tracee | 0.925x | 35/5 |
| tetragon | 0.827x | 5/0 |
| cilium | 0.854x | 2/0 |
| bcc | 1.014x | 8/7 |
| katran | 1.002x | 0/1 |
| otel | 1.102x | 0/1 |

### ARM64 Micro — June 6, 2026

**Session:** `aws_arm64_micro_20260606_001225_821028`

- Platform: AWS t4g.small
- Benchmarks: 29
- **Speedup geomean: 1.208x** (20.8% improvement)
- KOperation-bearing geomean: 1.222x over 27 benchmarks
- Wins/losses/ties: 24/2/3
- Code-size ratio geomean: 0.879x (12% smaller)

### Native vs eBPF Evaluation — May 29, 2026

**Session:** Native kernel evaluation

- Corpus native/eBPF workload geomean: **1.349x**
- Headline per-app BPF speedups:
  - OTEL: **14.81x** (3210 ns/run eBPF → 217 ns/run native)
  - tetragon: 2.23x
  - cilium: 1.86x
  - katran: 1.25x
  - bcc: 1.01x
  - tracee: 0.98x (slight regression)

---

## 4. Are There More Recent Authoritative Sessions?

### June 2026 Sessions (post June 3)

The June 2026 runs fall into several categories:

1. **x86_kvm_corpus_20260622_*** — Multiple runs on June 22, but many show `status: running` or `enabled_passes: []`. These appear to be development/debugging runs, not authoritative.

2. **aws_arm64_corpus_2026061*** — ARM64 corpus runs June 15-17, but metadata files show 0 bytes (incomplete).

3. **kop evaluation runs** — June 2-6 runs with `lea`, `kop` passes are the most complete authoritative runs with full analysis scripts and summaries.

### Recommendation

**For the paper, the authoritative sessions should be:**

1. **June 3, 2026 x86 corpus** (`x86_kvm_corpus_20260603_175429_964295`) — All-force kop, SAMPLES=3, 30s workload, full 6-app coverage
2. **June 6, 2026 ARM64 micro** (`aws_arm64_micro_20260606_001225_821028`) — ARM64 kop, 29 benchmarks, 20.8% speedup
3. **May 29, 2026 native evaluation** — Native vs eBPF upper bound comparison

The April 2026 data referenced in MEMORY.md (`vm_micro_authoritative_20260314`) is older and from the VM noise period before methodology stabilization.

---

## 5. Framework Stability Assessment

### Framework Stabilized: Late April / Early May 2026

Key stabilization markers:
- **April 25** — 6-app corpus finalized (SCX removed)
- **May 5** — Methodology rules in CLAUDE.md (min_runs 100, geomean, SAMPLES cap)
- **May 20** — bpftrace removed, final 6-app list

### Methodology Validated

The noise-floor analysis establishing the 100-run threshold was based on the 18-app corpus with CV measurements:
- Unfiltered: CV 29.6%
- >=100 runs: CV 17.7%
- Inflection point at 100 captures noise reduction while maximizing coverage (127 vs 90 progs at >=10K)

### Post-Stabilization Results

All authoritative results since May 2026 use the stabilized framework with:
- 6-app corpus (bcc/set, otel, cilium, tetragon, katran, tracee)
- Per-program geomean as headline metric
- min_runs >= 100 filter
- SAMPLES=3, WORKLOAD_DURATION=30s for paper-grade

---

## 6. Key Findings Summary

| Metric | Session | Value |
|--------|---------|-------|
| x86 kop corpus BPF speedup | June 3 | **6.7%** (0.933x applied) |
| ARM64 kop micro speedup | June 6 | **20.8%** (1.208x) |
| Native vs eBPF upper bound | May 29 | **34.9%** (1.349x workload) |
| Micro authoritative (VM) | March 14 | **1.054x** overall (noisy) |
| VM noise impact | March 14 | >10% variance on non-applied |

The June 2026 kop evaluation runs represent the most recent authoritative data and should be prioritized over March/April numbers for paper claims.
