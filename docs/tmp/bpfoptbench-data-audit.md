# BPFOptBench Data Audit

Date: 2026-06-24

This document audits the benchmark data claimed in the BPFOptBench paper
(`docs/ebpf27-bpfoptbench/main.tex`) and traces each number to its authoritative
source.

## Paper Claims vs Actual Data

### Claim 1: 6 production applications with 146 programs

**Paper text** (lines 47-48, 250-251):
> covering 6 production applications with 146 programs

**Authoritative source**:
`corpus/results/x86_kvm_corpus_20260428_070851_973550/details/result.json`
Analysis in: `docs/tmp/corpus-performance-analysis-20260428.md`

**Actual data**:
- 6 apps confirmed: bcc/set, tracee/monitor, tetragon/observer, katran, cilium/agent, otelcol-ebpf-profiler/profiling
- 146 comparable programs (programs with `run_cnt_delta > 0` in both phases, meeting min_runs threshold)

**Latest run program counts** (June 2026, `x86_kvm_corpus_20260622_190658_322856`):
| App | Programs |
|---|---:|
| bcc/set | 25 |
| cilium/agent | 62 |
| katran | 1 |
| otelcol-ebpf-profiler/profiling | 13 |
| tetragon/observer | 234 |
| tracee/monitor | 151 |
| **Total** | **486** |

Note: The 146 is not total loaded programs. It is the count of programs that:
1. Have `run_cnt_delta > 0` in both baseline and post-rejit phases
2. Meet the minimum run count threshold (typically 100)

The discrepancy between 486 loaded and 146 comparable comes from tail-called
programs showing `run_cnt = 0` (their time is counted in the caller) and programs
not hit during the workload.

**Verdict**: ACCURATE - 146 is the comparable program count from the April 2026 run.

---

### Claim 2: 35 micro benchmarks

**Paper text** (lines 47-48):
> 35 micro benchmarks

**Actual data**:
- `micro/programs/*.bpf.c`: 29 files
- `micro/programs/*.md`: 44 files (some documentation-only)

**Verdict**: INACCURATE - actual count is 29 micro benchmark BPF programs, not 35.
Either the paper should say 29, or there were additional benchmarks that were
removed. The documentation files (44) may be the source of confusion.

---

### Claim 3: Static policy geomean 1.004x, 81 wins / 65 losses

**Paper text** (Table 1, line 150):
> Static policy: 146 programs, geomean 1.004x, 81 wins / 65 losses

**Authoritative source**:
`docs/tmp/corpus-performance-analysis-20260428.md`, section "Executive Summary"

**Exact quote from source**:
> The latest run is effectively flat by the headline metric: `1.0038275637087666`
> across `146` comparable programs, with `81` wins and `65` losses.

**Calculation**:
- Source result: `corpus/results/x86_kvm_corpus_20260428_070851_973550/details/result.json`
- Method: per-program geomean of `(post_avg_ns_per_run / baseline_avg_ns_per_run)`
- Filter: `min(baseline_runs, post_rejit_runs) >= 100`
- 81 + 65 = 146 (ties are excluded, consistent with analysis methodology)

**Verdict**: ACCURATE - paper rounds 1.0038 to 1.004x.

---

### Claim 4: Applied-split: changed-code 1.032x, unchanged 0.983x

**Paper text** (Table 1, line 151):
> changed-code programs 1.032x, unchanged 0.983x

**Authoritative source**:
`docs/tmp/corpus-performance-analysis-20260428.md`, section "Applied Coverage"

**Exact quote from source**:
> | all apps | 146 | 63 | 1.032346 | 0.982708 |

Where:
- 63 programs had `bytes_jited_delta != 0` (code actually changed)
- 83 programs had no JIT byte change
- Applied geomean: 1.032346 (paper rounds to 1.032x)
- Non-applied geomean: 0.982708 (paper rounds to 0.983x)

**Interpretation**:
- "changed-code" = programs where `bytes_jited_delta != 0` after optimization
- Programs with changed code regress by 3.2%
- Programs with unchanged code improve by 1.7% (this is noise/phase effect)
- The improvement on unchanged programs proves measurement perturbation exists

**Verdict**: ACCURATE

---

### Claim 5: Noise floor: noop-ReJIT 0.902x, skip-ReJIT 0.859x, noise floor 0.04x

**Paper text** (Table 1, line 149):
> noop ReJIT 0.902x, skip-ReJIT 0.859x; noise floor is 0.04x

**Authoritative source**:
`docs/tmp/pass_signal_audit_20260508.md`, section "Q1/P1 noise floor"

**Exact quote from source**:
> | Q1 noop ReJIT | `x86_kvm_corpus_20260507_190554_205137` | n/a | 147 | 0.9019 | 73/74/0 |
> | P1 noop SKIP_REJIT | `x86_kvm_corpus_20260508_000244_131324` | true | 147 | 0.8587 | 75/72/0 |
>
> Suite noise amplitude: `|0.9019 - 0.8587| = 0.0431`.

**Interpretation of 0.04x**:
- noop-ReJIT floor: 0.9019 (ReJIT with identity transformation)
- skip-ReJIT floor: 0.8587 (no ReJIT at all, just measure twice)
- Difference: |0.9019 - 0.8587| = 0.0431 ~ 0.04x

The 0.04x is the **difference between two baselines**, not an absolute noise floor.
Both baselines show apparent "speedups" of 10-14% from doing nothing, which
indicates systematic measurement perturbation.

**What this means**:
- The 0.04x is the between-baseline variance
- The fact that both baselines show apparent speedups (0.902x, 0.859x) rather
  than being near 1.0x indicates significant phase effects
- Any claimed optimization must exceed 0.04x beyond the noise floor

**Problem**: The paper says "noise floor is 0.04x" but both floor measurements
are far from 1.0x. The phrasing is confusing. The 0.902x noop-ReJIT result means
that even doing nothing shows a 9.8% apparent speedup, which is a major confounder.

**Verdict**: TECHNICALLY ACCURATE but POORLY EXPLAINED - the 0.04x derivation is
correct (0.9019 - 0.8587 = 0.0432 ~ 0.04), but the implication is unclear.

---

## Questions Answered

### Q1: Where is the authoritative data source for these numbers?

**Primary source**: `corpus/results/x86_kvm_corpus_20260428_070851_973550/details/result.json`

**Analysis documents**:
- `docs/tmp/corpus-performance-analysis-20260428.md` - main corpus analysis
- `docs/tmp/pass_signal_audit_20260508.md` - noise floor measurements
- `docs/research/bpfoptbench-session-data-analysis.md` - meta-analysis

The numbers come from a specific April 2026 corpus run analyzed offline.

### Q2: What do the noise floor numbers (0.902x, 0.859x) actually mean? How is 0.04x derived?

**noop-ReJIT floor (0.9019x)**:
- Run: `x86_kvm_corpus_20260507_190554_205137`
- Configuration: ReJIT enabled but only the `noop` pass runs (identity transformation)
- 147 retained programs, 73 wins / 74 losses
- Interpretation: ReJIT syscall path + measurement itself causes apparent 9.8% speedup

**skip-ReJIT floor (0.8587x)**:
- Run: `x86_kvm_corpus_20260508_000244_131324`
- Configuration: ReJIT completely skipped, just measure baseline vs post
- 147 retained programs, 75 wins / 72 losses
- Interpretation: Even without ReJIT, the second measurement shows 14.1% apparent speedup

**0.04x derivation**:
```
0.9019 - 0.8587 = 0.0432 ~ 0.04x
```

This is the difference between the two floor measurements, representing the
additional perturbation introduced by the ReJIT path itself.

**Critical insight**: Both floors are far from 1.0x. This means:
1. The measurement setup has systematic bias (second measurement faster)
2. Phase effects from app lifecycle, workload variance, or BPF event mix dominate
3. Any real optimization signal must be much larger than the floor variance

### Q3: What is "applied split" - how many programs had changes applied vs unchanged?

**From April 2026 run**:
- **Total comparable programs**: 146
- **Applied (bytes_jited_delta != 0)**: 63 programs
- **Unchanged (bytes_jited_delta == 0)**: 83 programs

**Applied geomean**: 1.032x (3.2% slower after optimization)
**Unchanged geomean**: 0.983x (1.7% faster, but no code changed)

The counterintuitive result that unchanged programs "improve" while changed
programs regress suggests phase effects dominate the signal. This motivates the
paper's argument that static policies are insufficient.

**App breakdown**:
- Tracee dominates applied coverage: 59/63 comparable applied rows are tracee
- Most other apps have zero applied programs

### Q4: Are there more recent results we should use instead?

**Most recent run found**: `x86_kvm_corpus_20260622_190658_322856`
- Date: June 22, 2026
- Status: ok
- 6 apps present
- **However**: `enabled_passes=[]`, meaning no optimization was run

The June 2026 runs appear to be infrastructure verification runs, not optimization
benchmarks. The April 2026 data remains the most recent complete optimization run
with the full pass list.

**Recommendation**: Before paper submission, run a fresh corpus with:
```bash
SAMPLES=3 WORKLOAD_DURATION=30 make corpus
```
to get updated numbers on the current codebase.

---

## Summary Table

| Claim | Paper Value | Actual Value | Source | Status |
|---|---|---|---|---|
| Production apps | 6 | 6 | macro_apps.yaml | ACCURATE |
| Programs | 146 | 146 comparable | corpus 20260428 | ACCURATE |
| Micro benchmarks | 35 | 29 | micro/programs/*.bpf.c | INACCURATE |
| Static geomean | 1.004x | 1.0038x | corpus analysis | ACCURATE |
| Wins/losses | 81/65 | 81/65 | corpus analysis | ACCURATE |
| Applied geomean | 1.032x | 1.032346x | corpus analysis | ACCURATE |
| Unchanged geomean | 0.983x | 0.982708x | corpus analysis | ACCURATE |
| noop-ReJIT floor | 0.902x | 0.9019x | pass_signal_audit | ACCURATE |
| skip-ReJIT floor | 0.859x | 0.8587x | pass_signal_audit | ACCURATE |
| Noise floor | 0.04x | 0.0431x | derived from above | ACCURATE |

---

## Recommended Fixes

1. **Micro benchmark count**: Change "35 micro benchmarks" to "29 micro benchmarks"
   or verify if there are additional benchmarks not in the repository.

2. **Noise floor explanation**: Add clarification that both noop-ReJIT (0.902x) and
   skip-ReJIT (0.859x) show apparent speedups, and the 0.04x is the difference
   between these two baselines, not an absolute noise floor around 1.0x.

3. **Fresh data**: Consider running updated corpus benchmarks before submission
   to ensure numbers reflect current codebase state.

---

## Post-May-20 Session Analysis

This section analyzes all benchmark sessions after the framework stabilization date
(May 20, 2026). Data extracted on June 24, 2026.

### Total Session Count

| Category | Count |
|----------|------:|
| **Total sessions** | **1,275** |
| Corpus sessions | 960 |
| Micro sessions | 315 |
| Completed | 740 |
| Error | 348 |
| Running/Stale | 187 |

### Session Inventory by Platform

| Type + Platform | Sessions |
|-----------------|-------:|
| corpus_x86_kvm | 779 |
| corpus_aws_arm64 | 181 |
| micro_x86_kvm | 224 |
| micro_aws_arm64 | 82 |
| micro_aws_x86 | 4 |
| micro_other | 5 |

### Activity Timeline

| Date | Sessions | Notes |
|------|-------:|-------|
| 20260521 | 157 | Initial post-stabilization burst |
| 20260522 | 142 | Heavy exploration |
| 20260523 | 117 | Pass configuration testing |
| 20260524 | 99 | Continued exploration |
| 20260602 | 94 | Second exploration wave |
| 20260528 | 84 | Debugging sessions |
| 20260615 | 72 | ARM64 focused runs |
| 20260622 | 52 | Recent validation runs |

### Agentic Exploration Analysis

**Sessions with explicit pass configurations**: 845 (66% of all sessions)

This indicates extensive agentic exploration of different optimization strategies.

**Unique pass configurations tested**: 25

**Top Pass Configurations by Frequency**:

| Configuration | Count | Completed | Error | Date Range |
|---------------|------:|----------:|------:|------------|
| Full pipeline (11 passes) | 284 | 142 | 103 | May 23-29 |
| noop (baseline) | 196 | 103 | 46 | May 21 - Jun 21 |
| [empty/default] | 115 | 98 | 10 | May 22 - Jun 22 |
| lea only | 102 | 13 | 76 | May 31 - Jun 3 |
| ARM64 pipeline (10 passes) | 97 | 43 | 16 | Jun 14-17 |
| kinsn only | 50 | 37 | 9 | Jun 3-8 |
| rotate only | 35 | 8 | 21 | Jun 2-3 |
| map_inline only | 33 | 22 | 11 | May 21-22 |

### Pass-Level Application Statistics

Aggregated from all report files across post-May-20 sessions:

| Pass | Sessions | Sites Applied | Sites Matched | Sites Skipped |
|------|-------:|-------------:|-------------:|-------------:|
| **kinsn** | 30 | **305,449** | 305,449 | 0 |
| **rotate** | 40 | **222,547** | 222,547 | 0 |
| **lea** | 10 | **46,749** | 46,749 | 0 |
| **cond_select** | 13 | **6,578** | 6,578 | 0 |
| **map_inline** | 24 | 3,918 | 5,859 | 1,941 |
| noop | 13 | 874 | 874 | 0 |
| endian_fusion | 6 | 197 | 197 | 0 |
| bulk_memory | 5 | 57 | 57 | 0 |
| extract | 6 | 48 | 48 | 0 |
| const_prop | 1 | 2 | 2 | 0 |
| dce | 1 | 2 | 2 | 0 |
| bounds_check_merge | 1 | 1 | 1 | 0 |
| wide_mem | 1 | 1 | 1 | 0 |
| skb_load_bytes_spec | 1 | 1 | 1 | 0 |
| prefetch | 2 | 0 | 0 | 0 |
| ccmp | 1 | 0 | 0 | 0 |

### Key Findings and Interesting Facts

#### 1. kinsn is the Most Impactful Pass
With 305,449 sites applied, `kinsn` dominates the optimization landscape. This
aligns with the paper's emphasis on kinsn (kernel instruction lowering) as a
major optimization opportunity.

#### 2. High Error Rate During Exploration
33% error rate (348/1,060 non-running sessions) indicates significant debugging
and iteration during the exploration phase. Most errors were infrastructure
issues (tetragon startup, app timing) rather than pass bugs.

#### 3. lea Pass Had High Failure Rate
The `lea` pass showed 76 errors vs only 13 completions (85% failure rate).
This suggests the LEA optimization was being actively debugged during June 2026.

#### 4. map_inline Shows Skip Pattern
`map_inline` is the only pass with significant skipped sites (1,941 skipped out
of 5,859 matched = 33% skip rate). This reflects the conservative nature of
map inlining which requires verifier state confirmation.

#### 5. ARM64 Exploration Concentrated in Mid-June
181 ARM64 corpus sessions, heavily concentrated June 14-17, indicating focused
ARM64 validation after x86 stabilization.

#### 6. Samples Distribution
- SAMPLES=1: 749 sessions (78%)
- SAMPLES=3: 211 sessions (22%)

Most sessions used SAMPLES=1 for quick iteration; SAMPLES=3 reserved for
authoritative measurements.

### Best/Worst Results Observation

**Important finding**: Post-May-20 sessions show `applied=0` in rejit_result
summaries for app-level JSON. This is because:

1. The summary aggregation was moved to the report.json level per-program
2. The app-level rejit_result.summary field was deprecated
3. Actual application counts must be computed from loadtime-workdirs/*/report.*.json

The pass-level statistics above reflect actual optimization activity. The paper
numbers (April 2026 run) remain the authoritative source for geomean calculations.

### Session Quality Assessment

| Quality Tier | Count | Description |
|--------------|------:|-------------|
| Authoritative (SAMPLES=3, completed) | ~50 | Paper-grade measurements |
| Exploration (SAMPLES=1, completed) | ~690 | Debugging/iteration |
| Infrastructure failures | ~348 | App startup, timing issues |
| Stale/Running | ~187 | Orphaned or long-running |

### Recommendations from Post-May-20 Data

1. **kinsn validation**: The 305K applied sites need runtime performance
   validation to confirm speedup claims.

2. **lea debugging needed**: 85% failure rate suggests active issues with the
   LEA pass that may have been resolved but need fresh runs.

3. **ARM64 coverage gap**: Only 181 ARM64 corpus sessions vs 779 x86 KVM.
   Need more ARM64 authoritative runs.

4. **map_inline skip investigation**: 33% skip rate worth investigating -
   are these genuine verifier-state mismatches or overly conservative?

5. **Fresh authoritative run**: Run `SAMPLES=3 WORKLOAD_DURATION=30 make corpus`
   to get updated paper-grade numbers with current pass implementations.
