# BpfReJIT Benchmark Framework Review: OSDI/SOSP Gap Analysis

**Reviewer**: Opus 4.6 (acting as OSDI systems reviewer + benchmark expert)
**Date**: 2026-03-24
**Scope**: Complete code audit of micro/corpus/e2e/runner layers + OSDI evaluation gap analysis

---

## Part 1: Benchmark Framework Code Review

### 1.1 Micro Layer (`micro/driver.py`, `micro/benchmark_catalog.py`, `micro/config/micro_pure_jit.yaml`)

**Strengths:**
- Well-structured YAML-driven configuration with 62 benchmarks across 7 categories (baseline, alu-mix, byte-recompose, branch-layout, cmov, rotate, bitfield-extract, endian)
- `BenchmarkSpec` dataclass with `family`, `level`, `hypothesis` fields -- good scientific framing
- Alternating runtime order per iteration (`iteration_idx % 2 == 0`) for 2-runtime comparisons mitigates systematic drift
- `build_micro_batch_plan()` uses windowed parallel compile + serial execution -- correct separation of compile-time and runtime measurement
- PGO warmup integration (`--pgo-warmup-repeat`) for kernel-rejit runtimes
- Provenance collection (git sha, kernel commit, CPU model, governor, turbo state, perf_event_paranoid)

**Concerns:**
- **Default iterations=10, warmups=2, repeat=200** -- for micro benchmarks this is adequate but borderline for OSDI. Many systems papers use 30+ iterations. The `repeat=200` inside BPF_PROG_TEST_RUN is good (amortizes syscall overhead) but the outer `iterations=10` means only 10 paired samples for statistical tests.
- **No outlier filtering** -- raw samples fed directly to median/summary. No IQR-based trimming or Dixon's Q test. VM noise can produce outliers that inflate stdev.
- **`micro_batch_parallel_jobs()` uses `0.8 * cpu_count()`** for compile-only jobs, which is fine, but serial execution jobs share the same VM. No CPU pinning by default inside the VM guest.
- **Correctness checking** (`expected_result`) is present for some benchmarks but not all. Should be enforced for all measurement runs.
- **`random.Random(seed)` shuffle** is deterministic but not documented as a requirement in results JSON.

**Code quality**: Good. Clean dataclass hierarchy, typed throughout, sensible defaults. The `ArtifactSession` pattern for incremental result persistence is well-engineered.

### 1.2 Corpus Layer (`corpus/driver.py`, `corpus/modes.py`, `corpus/config/macro_corpus.yaml`)

**Strengths:**
- 133 named programs in `macro_corpus.yaml` from 7 real-world projects (Katran, Calico, Suricata, Tracee, Tetragon, loxilb, linux-selftests, xdp-tools)
- Paired measurement design: baseline compile -> baseline run -> PGO warmup -> v5 compile -> v5 run
- Per-family skip support (`--skip-families`) for ablation
- `build_target_batch_plan()` chunks targets and uses `prepared_key`/`prepared_ref` for state reuse across compile and run phases
- Daemon managed as server process with Unix socket (`start_daemon_server`/`stop_daemon_server`)
- Multiple modes: packet (exec time), tracing, perf counters, code-size

**Concerns:**
- **Default repeat=200** for corpus is reasonable, but **no warmup** is explicitly configured for corpus targets (unlike micro which has `warmups=2`). The PGO warmup of `repeat=10` is only for profiling data collection, not measurement warmup.
- **Timeout per target = 240s** with batch timeout = `target_count * per_target_timeout * 4 + 120`. For 133 targets this is ~128,000s (~35 hours). In practice, most complete faster, but there is no adaptive timeout.
- **`corpus_batch_parallel_jobs()`** = `0.8 * cpu_count()` for compile-only jobs -- same concern as micro about VM contention.
- **No explicit verification that baseline and v5 runs produce the same output** (retval check). The `speedup_ratio()` function only checks `ok` and `exec_ns` presence. A correctness mismatch between stock and rejit would go undetected unless the verifier catches it.
- **`size_ratio` computation** divides `baseline_len / v5_len`, which means ratio > 1.0 means v5 is smaller. This is inverse of the typical convention (should be clearly documented).
- **`families_from_scan()`** extracts which transform families are eligible from daemon scan results, but there is no validation that the scan is fresh (could be stale from inventory).

**Code quality**: Adequate but complex. The `build_record_from_batch_results()` function at ~70 lines has deeply nested dict access patterns like `(((record["v5_compile"] or {}).get("sample") or {}).get("rejit") or {}).get("applied")` which is fragile and hard to audit. Consider introducing helper accessors.

### 1.3 E2E Layer (`e2e/run.py`, `e2e/case_common.py`, `e2e/cases/tracee/case.py`, `e2e/cases/katran/case.py`)

**Strengths:**
- 6 real-world cases: Tracee, Tetragon, Katran, bpftrace, bcc, sched_ext
- Tracee case: Full workload-driven measurement with `run_exec_storm()`, `run_file_io()`, `run_network_load()` -- measures actual BPF program overhead under realistic load
- Katran case: Full network topology setup with namespace isolation (katran-router, katran-client, katran-real), wrk-based HTTP load generation, IPIP tunnel verification
- `TraceeOutputCollector` with thread-safe stdout/stderr consumption and event counting
- `TraceeAgentSession` context manager properly handles process lifecycle including `pidfd_getfd` for BPF program FD duplication
- `case_common.py` provides shared helpers (summarize_numbers, percent_delta, percentile, speedup_ratio)

**Concerns:**
- **Katran `DEFAULT_SAMPLE_COUNT = 3`** is very low for publication. Even with warm-up, 3 samples gives almost no statistical power for significance testing. Should be at least 10, ideally 30.
- **Tracee E2E** uses `sample_bpf_stats()` which reads `bpf_prog_info.run_cnt` and `run_time_ns` -- these are kernel-maintained counters with good accuracy, but their delta computation assumes no concurrent BPF execution between samples (may not hold under real workloads).
- **No Wilcoxon or significance testing** in E2E results. Only raw numbers and percentage deltas. Reviewers will question whether observed differences (e.g., +6.28% exec_storm) are statistically significant.
- **No warmup standardization** across E2E cases. Katran has explicit warmup parameters; Tracee relies on workload ramp-up.
- **Katran `DEFAULT_DURATION_S = 10`** -- short measurement windows may be dominated by connection setup overhead rather than steady-state BPF execution.

**Code quality**: Good for Tracee, complex for Katran. The Katran case at 200+ lines of network topology setup is a real integration test. The `PhaseSample` dataclass is well-structured.

### 1.4 Runner Shared Layer (`runner/libs/`)

**Strengths:**
- `statistics.py`: Clean implementation of `ns_summary` (count, mean, median, min, max, p95, stdev) and `geometric_mean`
- `results.py`: Well-typed `RunnerSample` TypedDict with all expected fields; `normalize_runner_sample()` handles legacy field migration
- `reporting.py`: Bootstrap CI implementation (5000 iterations, deterministic seed) for both individual ratios and geometric means. Wilcoxon + Benjamini-Hochberg adjustment for multiple comparisons.
- `environment.py`: Publication environment validation (CPU governor, turbo boost, perf_event_paranoid, CPU affinity)
- `vm.py`: Clean vng command construction with `--rwdir`, `--disable-monitor`, CPU/memory configuration
- `commands.py`: Type-safe command builder for micro_exec CLI
- `batch_runner.py`: YAML-based batch specification with JSON result collection

**Concerns:**
- **Bootstrap CI uses median of resampled medians** -- this is a reasonable choice but should be documented. Some reviewers prefer BCa (bias-corrected and accelerated) bootstrap rather than percentile bootstrap.
- **Wilcoxon test** (in `generate_figures.py`, not in `reporting.py`) requires paired samples. The code correctly pairs by iteration index, but returns `nan` if iterations don't match between runtimes. This is fragile -- any dropped sample breaks the test for that benchmark.
- **BH adjustment** is implemented correctly (step-down procedure), but is only applied in figure generation, not in the primary results JSON. Reviewers reading raw results won't see significance labels.
- **No effect size reporting** (Cohen's d or Cliff's delta). P-values alone are insufficient for OSDI -- reviewers want to know practical significance.
- **`geometric_mean()` silently drops non-positive values** -- this could hide regressions if any ratio rounds to 0.

### 1.5 C++ Runner (`runner/src/main.cpp`, `runner/include/micro_exec.hpp`, `runner/src/kernel_runner.cpp`)

**Strengths:**
- Kernel timing uses `bpf_prog_test_run_opts.duration` which is kernel's internal ktime measurement -- gold standard for BPF execution timing, not affected by syscall overhead
- Wall clock supplemented by RDTSC with proper lfence serialization (rdtsc_start: `lfence; rdtsc`, rdtsc_end: `rdtsc; lfence`)
- TSC frequency detection: reads from `/proc/cpuinfo` model name first, falls back to calibration with 20ms window
- Batch runner mode (`run-batch`) avoids process startup overhead for large suites
- Keep-alive mode for interactive use
- Perf counter capture with configurable scope (`full_repeat_raw` vs `full_repeat_avg`)
- REJIT integration: daemon socket communication for optimize-then-measure workflow
- `prepared_kernel_state` pattern separates compile from execution, enabling paired measurement

**Concerns:**
- **`repeat` is passed to `bpf_prog_test_run_opts` which runs the BPF program `repeat` times inside a single syscall** -- the reported `duration` is the total wall time for all repeats. The Python driver divides by `repeat` to get per-invocation time. This is correct but means very fast programs (<100ns) may have sub-resolution ktime values even with repeat=200.
- **No memory barrier before reading `duration`** after `bpf_prog_test_run_opts()` returns -- not needed (kernel/user boundary provides ordering) but worth a comment.
- **ARM64 has `kHasTscMeasurement = false`** which means no TSC-based wall clock supplementation. On ARM64, only ktime is available, which is the primary metric anyway.
- **No cache flushing** between stock and rejit measurements. The prepared_key/prepared_ref mechanism reuses loaded state, but I-cache state from the stock measurement may benefit the rejit measurement (or vice versa). For the paired measurement to be fair, both should start from the same cache state.

### 1.6 Makefile Layer

**Strengths:**
- Clean separation: root `Makefile` delegates to `runner/Makefile` for build, uses Python drivers for orchestration
- All VM targets properly chain dependencies: `vm-micro: micro_exec micro-programs daemon-binary kernel-image kinsn-modules-build`
- ARM64 cross-compilation support with Docker-based toolchain (`arm64-crossbuild.Dockerfile`)
- AWS Graviton remote execution pipeline (`aws_arm64.sh`)
- VM lock wrapper (`with_vm_lock.py`) prevents concurrent VM access

**Concerns:**
- **No `make artifact-eval`** target for one-command reproduction
- **No pinning of specific tool versions** (LLVM, clang, rustc) in the Makefile. Reproducibility depends on the host environment.
- **VM timeout defaults are generous** (7200s for micro, 7200s for e2e) but no automatic retry on transient VM failures.

### 1.7 Daemon Tests (`daemon/tests/static_verify.py`)

**Strengths:**
- Comprehensive static verification: loads every corpus/micro .bpf.o into kernel, applies daemon optimization, verifies kernel accepts the result
- Daemon server communication over Unix socket with proper timeout handling
- 303+ test cases (based on plan doc)
- Correctness-focused: verifies that optimized programs pass kernel verifier

**Concerns:**
- **No differential testing**: does not verify that optimized programs produce the same output as stock programs. Verifier acceptance != semantic equivalence.
- **No test for recompile overhead measurement**: static_verify counts pass/fail but doesn't measure or report per-program recompile latency.

---

## Part 2: OSDI/SOSP Gap Analysis

### 2.1 Evaluation Completeness (Required Questions)

| Question | Status | Evidence | Gap |
|----------|--------|----------|-----|
| Q1: Userspace policy produces different results across hardware/workload/programs? | Partial | CMOV policy-sensitivity shown (cond_select_dense 0.482x vs log2_fold +28.3%). x86 VM data exists. | **No ARM64 performance data. No workload-dependent policy variation data (same program, different inputs).** |
| Q2: Differences outperform fixed kernel heuristics? | Partial | v1 had `jit-fixed-baselines` branch for comparison. v2 lacks a head-to-head. | **No systematic "BpfReJIT vs kernel-fixed-cmov" comparison in v2. Plan mentions this but data is missing.** |
| Q3: Legality substrate acceptance rate on real programs? | Good | 303 daemon tests, 49/62 micro applied, 16535 total sites across 8 families. | **Acceptably complete for wide_mem; kinsn families (rotate/cond_select/extract) are blocked by verifier changes -- "0 applied" for kinsn passes.** |
| Q4: System generalizes to multiple directive families? | Good | 8 families implemented: wide_mem, rotate, cond_select, bitfield_extract, endian_fusion, branch_flip + spectre barrier + map inlining (design). | Sufficient breadth. |
| Q5: Operators can safely manage policy in production? | Missing | Watch mode "to be implemented". No rollback demonstration. No A/B testing framework. | **Critical gap. No production-readiness evidence.** |

### 2.2 Baseline Completeness

| Baseline | Status | Notes |
|----------|--------|-------|
| Stock kernel JIT | Present | Primary baseline in all measurements |
| Kernel-fixed peephole baselines | **Missing in v2** | `jit-fixed-baselines` branch exists from v1 but no v2 comparison data. The plan doc marks this as "v1 only". |
| advisor-static (CPU DB only) | **Missing** | No implementation or data |
| advisor-profiled (CPU DB + workload profile) | **Missing** | No implementation or data |
| llvmbpf upper bound | Present | Pure-JIT micro suite with 62 benchmarks, geomean 0.609x |

**Gap severity: HIGH.** Without kernel-fixed baselines, reviewers cannot distinguish "is BpfReJIT better because recompilation is inherently useful, or because the kernel is missing obvious peepholes?" The plan doc itself states this as a mandatory falsification criterion.

### 2.3 Workload Representativeness

**Current coverage:**
- **Micro**: 62 synthetic benchmarks covering 7 optimization families. Adequate for mechanism isolation.
- **Corpus**: 133 real-world programs from Katran (Meta), Calico (Tigera), Suricata, Tracee (Aqua), Tetragon (Isovalent), loxilb, linux-selftests, xdp-tools. Good breadth.
- **E2E**: 6 applications (Tracee, Tetragon, Katran, bpftrace, bcc, sched_ext).

**Missing workload categories:**
- **Cilium**: The most widely deployed eBPF networking stack. Absence is conspicuous.
- **eBPF-based schedulers**: sched_ext case exists but is new and may lack depth.
- **Storage/block I/O**: No BPF programs from the block layer (bcc tools like biolatency, biotop).
- **Cgroup/container security**: No BPF LSM programs beyond Tracee's.
- **Long-running steady-state**: All benchmarks are short bursts. No 1-hour stability test.

**Assessment**: Workload coverage is above average for a systems paper but has conspicuous gaps (Cilium, storage). The 568 .bpf.o corpus is competitive with K2's evaluation (which used ~200 programs).

### 2.4 Hardware Diversity

| Platform | Status | Notes |
|----------|--------|-------|
| x86-64 (VM) | Present | All current data from QEMU/KVM VM |
| x86-64 bare-metal | **Missing** | No bare-metal performance data |
| ARM64 (VM) | **Missing** | Cross-build pipeline exists, CI exists, but no performance data |
| ARM64 bare-metal (Graviton) | **Missing** | AWS pipeline exists but no results |
| Multi-core/NUMA | **Missing** | All measurements single-threaded |
| Small-core (Atom/Efficiency) | **Missing** | Plan marks as needed |

**Gap severity: HIGH.** OSDI reviewers will strongly question VM-only data. The `validate_publication_environment()` function even warns about VM detection, but all current data is from VMs. Key concerns:
1. **VM noise**: Plan doc acknowledges ">10% fluctuation in 3-iteration runs for non-applied benchmarks". This is unacceptable for publication.
2. **No bare-metal validation**: The 1.054x overall micro improvement could be entirely within VM noise margin.
3. **ARM64 is a primary kinsn selling point** (LDP/STP, MOVBE alternatives) but has zero performance data.

### 2.5 Statistical Rigor

**What exists:**
- Median as central tendency (correct for skewed timing distributions)
- Geometric mean for aggregation across benchmarks (correct)
- Bootstrap CI (5000 iterations, percentile method) for ratios and geometric means
- Wilcoxon signed-rank test for paired comparisons
- Benjamini-Hochberg correction for multiple comparisons
- Provenance recording (git sha, CPU, governor, turbo)
- Publication environment validation (governor, turbo, affinity)

**What is missing or insufficient:**

1. **Sample size**: Micro uses 10 iterations (10 paired samples per benchmark). This gives Wilcoxon a maximum detectable effect of ~0.001 at p=0.05 for perfectly paired data, but in practice with VM noise, many comparisons will be underpowered. **Recommend: 30 iterations minimum for authoritative runs.**

2. **No effect size metric**: Only p-values and ratios are reported. Reviewers will ask "is 1.054x practically meaningful?" Cohen's d or Cliff's delta should be reported alongside p-values.

3. **No variance reporting in summary tables**: The plan doc quotes "micro 1.054x" without CI bounds. The paper must report CIs for all headline numbers.

4. **Corpus repeat=200 with 1 iteration**: Each corpus program is measured once (with 200 internal repeats). This gives zero information about measurement variance. **Critical for publication: need multiple iterations.**

5. **E2E has no significance testing**: Percentage deltas are reported without confidence intervals or p-values. With 3 Katran samples, no statistical test has meaningful power.

6. **No power analysis**: How many iterations are needed to detect a 5% improvement at 80% power? This should inform the experimental design.

7. **Bootstrap CI is percentile method**: Works fine for symmetric distributions but can be biased for small samples. BCa bootstrap would be more robust.

8. **VM noise handling**: The plan doc acknowledges this problem but has no mitigation strategy beyond "more iterations". Consider:
   - Reporting coefficient of variation (CV) per benchmark
   - Flagging benchmarks with CV > 5% as "noisy"
   - Running bare-metal for headline numbers

### 2.6 Missing Experiments

| Experiment | Importance | Current Status | What Reviewers Will Ask |
|------------|-----------|----------------|------------------------|
| **Recompile overhead breakdown** | P0 | Scanner time=4.32ms, syscall=29.89us reported. No per-component breakdown (verify vs JIT vs swap). | "What fraction of recompile time is spent in kernel verifier vs JIT compilation vs image swap?" |
| **Scalability: program count** | P0 | No data. | "How does daemon performance scale with 100/1000/10000 loaded BPF programs?" |
| **Memory overhead** | P0 | No data. | "How much additional memory does the daemon consume? What about kernel-side overhead for original bytecode storage?" |
| **Policy sensitivity matrix** | P0 | CMOV shown for 2 benchmarks. No systematic cross-product. | "Show a matrix: each optimization x each program, with net speedup. Which optimizations help vs hurt?" |
| **Kernel-fixed vs BpfReJIT** | P0 | v1 had this, v2 does not. | "If we just add these peepholes to the kernel JIT, do we get the same benefit?" |
| **Long-running stability** | P1 | Watch mode not implemented. | "Does the daemon introduce any degradation over hours of operation?" |
| **K2/Merlin/EPSO quantitative comparison** | P1 | Only qualitative table (section 1.8). | "How does BpfReJIT's improvement compare to K2's superoptimization on the same programs?" |
| **Code size evaluation** | P1 | Code size geomean 0.496x exists for llvmbpf vs kernel. No BpfReJIT code size data. | "Does recompilation change native code size? By how much?" |
| **Correctness validation** | P1 | Verifier acceptance tested (303 programs). No output equivalence testing. | "How do you know the optimized program produces the same output?" |
| **Security hardening evaluation** | P2 | Spectre barrier pass implemented. No performance data. | "What is the overhead of adding speculation barriers?" |
| **Multi-directive interaction** | P2 | Ablation exists (byte-recompose 50.7%). No interaction effects between families. | "Do optimizations interfere with each other?" |
| **Compilation time overhead** | P1 | Not systematically measured. | "What is the end-to-end time from daemon scan to optimized program?" |

### 2.7 Presentation Concerns

1. **Figure generation** (`generate_figures.py`): Uses matplotlib with publication-quality settings (serif font, 300 DPI, PDF type 42 fonts). Wilcoxon + BH annotation. This is well-prepared.

2. **Data presentation**: Results are stored as JSON with rich metadata. The `summarize_rq.py` script generates markdown summaries with bootstrap CIs. However:
   - No LaTeX table generation for direct paper inclusion
   - No automated figure numbering or cross-referencing
   - Figures are generated from potentially stale data files

3. **Artifact evaluation**:
   - No `Dockerfile` for reproducible builds (ARM64 Dockerfile exists but is for cross-compilation)
   - No `artifact-eval.sh` one-command script
   - No documented hardware requirements
   - No expected runtime estimates
   - Git submodule dependencies (vendor/linux-framework) make reproduction harder
   - **OSDI AE requires**: README with setup instructions, expected results, and ~30-minute kick-the-tires test

---

## Part 3: Prioritized TODO List

### P0: Must Do Before Submission

| # | Task | Estimated Effort | Paper Impact |
|---|------|-----------------|--------------|
| P0.1 | **Bare-metal x86-64 run** for all three layers (micro/corpus/e2e). VM noise undermines all headline numbers. Need at least one bare-metal machine with CPU pinning, governor=performance, turbo disabled. | 2-3 days (hardware access + full run) | **Critical**: All headline numbers change. Without this, reviewer confidence in quantitative claims is very low. |
| P0.2 | **Kernel-fixed baseline comparison in v2**: Port `jit-fixed-baselines` to v2 kernel or implement equivalent. Run micro + corpus with both BpfReJIT and kernel-fixed on same hardware. | 3-5 days (kernel work + measurement) | **Critical**: Plan doc's own mandatory falsification criterion. Without this, the core contribution (userspace > kernel-fixed) is unproven. |
| P0.3 | **Increase micro iterations to 30**: Rerun authoritative micro suite with `--iterations 30 --warmups 5`. Current 10 iterations is underpowered. | 1 day (just runtime) | **High**: Enables meaningful Wilcoxon tests. Current p-values based on n=10 are marginal. |
| P0.4 | **Corpus multi-iteration**: Run corpus with at least 3 outer iterations (currently 1). Each program needs multiple independent measurements for variance estimation. | 1-2 days (runtime) | **High**: Currently impossible to assess measurement noise for corpus programs. |
| P0.5 | **Recompile overhead breakdown**: Instrument daemon and kernel to report per-phase timing: (a) daemon scan time, (b) daemon rewrite time, (c) kernel verify time, (d) kernel JIT time, (e) image swap time. | 2-3 days (daemon + kernel instrumentation) | **High**: Reviewers will ask "where does the time go?" and "can this be parallelized?" |
| P0.6 | **Scalability experiment**: Load 10/100/500/1000 BPF programs, measure daemon apply-all latency vs program count. | 1-2 days | **High**: Production environments have hundreds of BPF programs. Must show linear or sublinear scaling. |
| P0.7 | **Memory overhead measurement**: Measure (a) daemon RSS during apply-all, (b) kernel memory delta for storing original bytecode (`orig_prog_insns`), (c) per-program kernel overhead. | 1 day | **High**: Systems papers must report memory overhead. |
| P0.8 | **Correctness differential testing**: For every program in the corpus where both stock and rejit can execute (packet-test-run targets), verify that retval matches. Add assertion to corpus driver. | 1 day (add check to existing code) | **Critical**: "Transparent optimization" claim requires semantic equivalence evidence. Currently only verifier acceptance is tested. |
| P0.9 | **Policy sensitivity matrix**: For the micro benchmarks, run each optimization family independently (already supported via `--skip-families`). Report per-family contribution and interaction effects. | 1-2 days | **High**: Demonstrates the value of policy-driven optimization vs blind application. |
| P0.10 | **ARM64 performance data**: Use the existing AWS Graviton pipeline to get at least micro + corpus numbers on ARM64. | 2-3 days (setup + run) | **High**: Paper claims multi-arch support. Without ARM64 data, this is an unsupported claim. |

### P1: Strongly Recommended

| # | Task | Estimated Effort | Paper Impact |
|---|------|-----------------|--------------|
| P1.1 | **Effect size reporting**: Add Cohen's d or Cliff's delta to the reporting pipeline alongside p-values. | 0.5 days | **Medium**: Strengthens statistical methodology section. |
| P1.2 | **E2E significance testing**: Increase Katran/Tracee sample counts to 10+, add Wilcoxon tests to E2E results. | 2 days (mostly runtime) | **Medium**: E2E numbers without significance tests will be dismissed as anecdotal. |
| P1.3 | **Code size evaluation for BpfReJIT**: Measure JIT'd code size before and after daemon optimization for all corpus targets. The infrastructure already captures `jited_prog_len`. | 0.5 days (add reporting) | **Medium**: Paper claims "50% code size reduction" but this is llvmbpf, not BpfReJIT. Need BpfReJIT-specific code size data. |
| P1.4 | **K2/EPSO quantitative comparison**: Pick 10-20 programs that K2 evaluated, run both BpfReJIT and K2 on them, report head-to-head speedups. | 3-5 days (K2 setup + runs) | **Medium**: Transforms the related work from "we are different" to "we are better/complementary". |
| P1.5 | **Compilation time end-to-end**: For each corpus program, measure wall clock from "daemon receives scan request" to "optimized program running". Report distribution. | 1 day | **Medium**: Production readiness requires knowing how long optimization takes. |
| P1.6 | **Variance reporting**: Add CV (coefficient of variation) to all summary tables. Flag benchmarks with CV > 5% as "noisy". | 0.5 days | **Medium**: Improves reviewer confidence in measurement quality. |
| P1.7 | **Artifact evaluation package**: Create `artifact-eval/` directory with Dockerfile, README, kick-the-tires script, expected outputs. | 2-3 days | **Medium**: OSDI strongly encourages AE badges. Without it, acceptance probability drops. |
| P1.8 | **LaTeX table generation**: Add `--latex` output mode to `summarize_rq.py` and `generate_figures.py` for direct paper inclusion. | 0.5 days | **Low** (convenience, not substance). |
| P1.9 | **Cilium workload**: Add Cilium .bpf.o to corpus and/or build E2E case. Cilium is the most deployed eBPF networking stack; its absence is notable. | 2-3 days | **Medium**: Reviewers from the eBPF community will expect Cilium coverage. |
| P1.10 | **Watch mode prototype + long-running stability test**: Implement basic daemon watch mode, run for 1 hour with continuous BPF program loading/unloading. | 3-5 days | **Medium**: Demonstrates production viability. |

### P2: Nice to Have

| # | Task | Estimated Effort | Paper Impact |
|---|------|-----------------|--------------|
| P2.1 | **Atom/efficiency core evaluation**: Run on Intel Alder Lake E-cores or similar. | 1-2 days | **Low**: Interesting data point but not required. |
| P2.2 | **NUMA evaluation**: Run with BPF programs pinned to different NUMA nodes. | 1-2 days | **Low**: BPF programs are typically per-CPU; NUMA effects are secondary. |
| P2.3 | **Security hardening overhead**: Measure overhead of Spectre barrier insertion pass. | 1 day | **Low**: Interesting but not core contribution. |
| P2.4 | **BCa bootstrap**: Replace percentile bootstrap with BCa in reporting.py. | 0.5 days | **Low**: Minor statistical improvement; percentile method is adequate. |
| P2.5 | **Outlier detection**: Add IQR-based outlier flagging to statistics.py. | 0.5 days | **Low**: Improves robustness of summary statistics. |
| P2.6 | **Cache flush between phases**: Add explicit I-cache flush (or dummy BPF program execution) between stock and rejit measurement phases to eliminate cache warming effects. | 0.5 days | **Low**: May change micro results by a few percent. |
| P2.7 | **Interactive figure dashboard**: Web-based result viewer for exploring results interactively. | 3-5 days | **Very low**: Convenience for authors, not reviewers. |

---

## Summary Assessment

### What the framework does well:
1. **Architecture**: The three-layer (micro/corpus/e2e) design with shared runner infrastructure is well-engineered and follows established benchmarking methodology.
2. **Measurement correctness**: Using kernel's `bpf_prog_test_run_opts.duration` (ktime) as the primary timing source is the correct choice for BPF execution timing.
3. **Reproducibility infrastructure**: YAML manifests, deterministic seeds, provenance recording, artifact sessions -- all the building blocks for reproducible research.
4. **Statistical foundation**: Bootstrap CIs, Wilcoxon tests, BH correction -- the statistical toolkit is appropriate.
5. **Workload breadth**: 62 micro + 133 corpus + 6 E2E cases is competitive with peer publications.

### What blocks OSDI acceptance:
1. **VM-only data**: All performance numbers come from QEMU/KVM VMs. This is a fatal flaw for a performance-focused paper. Bare-metal data is essential.
2. **Missing kernel-fixed baseline**: The paper's central argument (userspace policy > fixed kernel heuristics) is unsubstantiated without this comparison.
3. **Insufficient iterations**: 10 micro iterations and 1 corpus iteration are underpowered for significance testing at the level OSDI expects.
4. **No correctness validation**: "Transparent optimization" is claimed but not tested (only verifier acceptance, not output equivalence).
5. **No ARM64 performance data**: Multi-arch is a selling point but has zero performance evidence.
6. **Missing overhead characterization**: Recompile breakdown, memory overhead, scalability -- all expected by systems reviewers.

### Estimated total effort for P0 items: ~15-20 person-days

This is aggressive but feasible before a submission deadline if work is parallelized across multiple machines (bare-metal x86, ARM64 instance, development environment for code changes).
