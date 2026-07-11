# BPFOptBench Data Summary

Date: 2026-06-26

This document summarizes all optimization results from BPFOptBench, covering Source-level, bytecode ReJIT, and kop-backed kernel JIT optimizations.

---

## 1. Overall Statistics

### Total Exploration Scale

| Metric | Count |
|--------|------:|
| **Total corpus sessions** | 2,124 |
| **Total micro sessions** | 852 |
| **Total sessions** | **2,976** |
| x86 KVM corpus | ~1,635 |
| AWS ARM64 corpus | ~213 |
| Unique pass configurations tested | 25 |
| Source-opt experiments (phase 1-3) | 92 attempts |

### Source-Level Optimization Summary (Latest Phase 3)

| App | Best Improvement | Status | Attempt |
|-----|------------------|--------|---------|
| **cilium/agent** | **+15.19%** | Reached 10% target | phase3-policy-error-unlikely-stack |
| **bcc/set** | **+11.81%** | Reached 10% target | phase3-syscount-key-width-cleanup |
| **tetragon/observer** | **+11.59%** | Reached 10% target | phase3-tracepoint-no-selector-config-flag |
| **katran** | **+11.53%** | Reached 10% target | phase3-vip-flag-branch-layout |
| **tracee/monitor** | **+0.86%** | Below target | phase3-prctl-fentry |
| **otelcol-ebpf-profiler** | **-1.42% to +0%** | No positive signal | All attempts regressed or flat |

### Kernel JIT / ReJIT Summary (KOperation + Bytecode Passes)

| Metric | Value | Source |
|--------|-------|--------|
| Micro benchmark geomean (all passes) | **1.054x** overall | vm_micro_authoritative_20260314 |
| Micro applied-only geomean | **1.074x** (16 applied, 62/62 valid) | vm_micro_authoritative_20260314 |
| Best kop corpus geomean | **0.938x** (6.2% improvement) | x86_kvm_corpus_20260603_175429_964295 |
| KOperation sites applied (single run) | 27,085 | June 3 breakthrough session |

---

## 2. Improvement vs Regression Analysis

### Source-Level Optimizations (92 Attempts Total)

| Outcome | Count | Percentage |
|---------|------:|------------|
| **Performance improved (accepted)** | 34 | 37.0% |
| **Flat / no signal** | 47 | 51.1% |
| **Regressed (correctness passed)** | 8 | 8.7% |
| **Correctness rejected** | 3 | 3.3% |

#### By Phase

| Phase | Attempts | Improved | Flat | Regressed | Rejected |
|-------|----------|----------|------|-----------|----------|
| Phase 1 (first-round) | 30 | 8 (27%) | 18 (60%) | 4 (13%) | 0 |
| Phase 2 (stacked tuning) | 30 | 12 (40%) | 12 (40%) | 4 (13%) | 2 (7%) |
| Phase 3 (deep tuning) | 32 | 14 (44%) | 17 (53%) | 0 | 1 (3%) |

### ReJIT / KOperation Optimizations

| Pass Category | Typical Wins | Typical Losses | Notes |
|---------------|--------------|----------------|-------|
| kop (full) | 24/29 micro | 2/29 micro | 1.208x geomean on ARM64 |
| rotate | High apply count | Rare regression | 222,547 sites across sessions |
| cond_select | Dense conditional benchmarks | Predictable branches | 6,578 sites, policy-sensitive |
| map_inline | Static maps | Dynamic maps (33% skip rate) | 3,918 applied, 1,941 skipped |
| lea | Address calculation | Verifier edge cases | 85% failure rate during debugging |

---

## 3. Verifier Rejection Analysis

### Source-Level Verifier Rejects (3 cases)

| App | Attempt | Reason |
|-----|---------|--------|
| tracee/monitor | phase2-cap-capable-fentry | Fentry program returned helper result instead of 0 |
| tracee/monitor | phase2-simple-value-args-fastpath | Verifier rejected `invalid access to map value` |
| otelcol-ebpf-profiler | pre-1 | Artifact provenance failed (not a verifier reject) |

### ReJIT-Level Verifier Issues

| Issue | Impact | Resolution |
|-------|--------|------------|
| map_inline skip rate | 33% of matched sites skipped | Expected behavior - only static maps inline |
| LEA pass failures | 85% failure rate during Jun 2 debugging | Fixed by Jun 3 |
| ARM64 poke gap | 56% tetragon programs affected | Known limitation, kernel patch required |

---

## 4. Kernel Panic / Crash Analysis

### Known Stability Issues

| Issue | Severity | Status |
|-------|----------|--------|
| SCX struct_ops ReJIT | **Kernel crash** | App removed from corpus |
| OTEL panic after ReJIT | Application panic | Deferred, bisect pending |
| Verifier-PC namespace mismatch | Pass skips | Documented limitation |

**No kernel panics reported in the June 2026 source-opt experiments.** All 92 source-opt attempts completed without kernel crashes.

---

## 5. Per-Layer Statistics

### Source Layer (eBPF C source rewrites)

| Metric | Value |
|--------|-------|
| Apps evaluated | 6 |
| Total attempts | 92 |
| Best single-app improvement | +15.19% (cilium) |
| Apps reaching 10% target | 4 / 6 |
| Verifier rejects | 2 (tracee) |

### LLVM Layer (Bytecode Rewriting Passes)

| Pass | Sessions | Applied Sites | Effectiveness |
|------|----------|---------------|---------------|
| noop (baseline) | 196 | 874 | N/A |
| map_inline | 33 | 3,918 | ~98% success when applied |
| const_prop | 1 | 2 | Limited visibility |
| dce | 1 | 2 | Limited visibility |
| wide_mem | 1 | 1 | Limited visibility |
| bounds_check_merge | 1 | 1 | Limited visibility |

### Kernel JIT Layer (KOperation Passes)

| Pass Family | Sessions | Sites Applied | Typical Speedup |
|-------------|----------|---------------|-----------------|
| kop (combined) | 30 | 305,449 | 1.2x on select benchmarks |
| rotate | 40 | 222,547 | Up to 1.9x on rotate-heavy code |
| cond_select | 13 | 6,578 | Policy-sensitive (-28% to +37%) |
| extract | 6 | 48 | Modest improvements |
| endian_fusion | 6 | 197 | Platform-specific |
| bulk_memory | 5 | 57 | Platform-specific (hurts arm64) |

---

## 6. Per-App Statistics

### Source-Opt Results Summary

| App | Baseline Metric | Best Result | Improvement | Attempts (all phases) |
|-----|-----------------|-------------|-------------|----------------------|
| cilium/agent | 1,488,103 pps | 1,714,120 pps | **+15.19%** | 15 |
| bcc/set | 710,465 bogo ops/s | 794,393 bogo ops/s | **+11.81%** | 15 |
| tetragon/observer | 358,681 bogo ops/s | 400,249 bogo ops/s | **+11.59%** | 16 |
| katran | 3,061,171 pps | 3,414,266 pps | **+11.53%** | 16 |
| tracee/monitor | 460,865 bogo ops/s | 464,810 bogo ops/s | **+0.86%** | 15 |
| otelcol-ebpf-profiler | 19.64B ops | 19.64B ops (flat) | **0%** | 15 |

### ReJIT / KOperation Results by App (from kop_eval_20260604)

| App | Geomean | Wins/Losses/Ties | Applied Sites |
|-----|---------|------------------|---------------|
| bcc | 0.961x (WIN) | 11/4/0 | 77 |
| katran | 0.940x (WIN) | 1/0/0 | 90 |
| cilium | 1.009x (TIE) | 1/1/0 | 4,086 |
| tracee | 1.028x (LOSS) | 14/27/0 | 14,833 |
| otel | 1.065x (LOSS) | 0/1/0 | 1,475 |

---

## 7. Failure Case Classification

### Category 1: Verifier Rejection (Source Layer)

| App | Attempt | Error |
|-----|---------|-------|
| tracee | cap-capable-fentry | Return value must be 0 for fentry |
| tracee | simple-value-args-fastpath | Invalid map value access |

### Category 2: No Signal (Flat Performance)

- **OTEL**: All 15+ attempts showed flat or negative throughput despite instruction count reductions
- **Tracee**: Most phase1 attempts were within noise margin (-0.5% to +0.5%)
- **Common pattern**: Instruction count reduction does not guarantee workload improvement

### Category 3: Regression Despite Correctness

| App | Attempt | Regression |
|-----|---------|------------|
| cilium | phase2-egress-policy-verdict | -0.78% vs baseline |
| cilium | phase2-lazy-ingress-fraginfo | -2.11% vs baseline |
| tracee | phase2-cap-fentry-early-noaudit | -1.50% vs baseline |
| otel | phase3-native-unwind-error-unlikely | -1.42% vs baseline |

### Category 4: Platform-Specific Issues

| Issue | x86 | arm64 |
|-------|-----|-------|
| bulk_memory pass | Helps | Hurts (regression) |
| ARM64 poke gap | N/A | 56% tetragon programs fail |
| prefetch pass | Helps some | Not implemented |

---

## 8. Key Findings (Paper Takeaways)

### Finding 1: Source-Level Optimization is Effective

4 out of 6 apps achieved >10% improvement through systematic source-level optimization:
- cilium: +15.19% via error-path branch layout hints
- bcc: +11.81% via task-local-storage for syscount latency map
- tetragon: +11.59% via load-time no-selector config flag
- katran: +11.53% via VIP flag branch layout optimization

### Finding 2: One-Size-Fits-All Policy Does Not Work

Same pass produces opposite effects across programs:
- rotate helps `siphash_rotate64_mixer` by 1.9x but neutral/harmful on `bpftrace_comm_key_fnv_hash`
- cond_select helps dense conditional micros (+37%) but hurts predictable branches (-28%)
- bulk_memory helps x86 cilium (0.776x BPF cost) but hurts arm64 cilium (1.066x)

### Finding 3: Instruction Count Reduction != Performance Improvement

OTEL case study:
- phase2-5 cut `unwind_php` from 6899 to 3358 instructions (51% reduction)
- Workload throughput: -0.70% regression
- Root cause: Code size reduction disrupted hot-path locality

### Finding 4: Tail-Called Programs Mask Measurement

Programs entered via `bpf_tail_call()` show `run_cnt=0` because the prologue that increments stats is skipped. This affects:
- OTEL: 8 `perf_unwind_<lang>` programs
- tetragon: `generic_kprobe_event` chains
- tracee: `lkm_seeker_*` and `vfs_*_tail` chains

Optimization effects on tail targets appear in the caller's `run_time_ns_delta`.

### Finding 5: Noise Floor Requires Threshold Filtering

CV drops from 29.6% (no filter) to 17.7% with min_runs >= 100 filter. Without filtering:
- Q1/P1 baseline drift: 4.3%
- Per-program variance: up to 31% within same app

---

## 9. Data Sources

- Corpus results: `/home/yunwei37/workspace/bpf-benchmark/corpus/results/` (2,124 sessions)
- Micro results: `/home/yunwei37/workspace/bpf-benchmark/micro/results/` (852 sessions)
- Source-opt records: `/home/yunwei37/workspace/bpf-benchmark/docs/source-opt/` (6 apps)
- Evaluation sessions: `/home/yunwei37/workspace/bpf-benchmark/docs/ebpf27-bpfoptbench/docs/evaluation-sessions.md`
- Pass variance analysis: `/home/yunwei37/workspace/bpf-benchmark/docs/ebpf27-bpfoptbench/docs/micro-pass-variance-analysis.md`

---

## 10. Summary Table: Authoritative Results

| Layer | Best Result | Methodology | Date |
|-------|-------------|-------------|------|
| Source (cilium) | +15.19% | Phase3 stacked unlikely hints | 2026-06-26 |
| Source (bcc) | +11.81% | Task-local-storage syscount | 2026-06-26 |
| Source (tetragon) | +11.59% | Load-time no-selector config | 2026-06-26 |
| Source (katran) | +11.53% | VIP flag branch layout | 2026-06-26 |
| KOperation (x86) | 0.938x geomean | Full kop policy | 2026-06-03 |
| Micro (applied) | 1.074x | 16 programs, all passes | 2026-03-14 |
