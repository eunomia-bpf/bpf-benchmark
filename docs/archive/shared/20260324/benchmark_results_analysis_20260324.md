# BpfReJIT Benchmark Results Analysis (2026-03-24/25)

> Analysis of all benchmark runs completed 2026-03-25, on v2 architecture (syscall + kinsn + daemon).
> Platform: Intel Core Ultra 9 285K, QEMU/KVM VM (virtme-ng), kernel 7.0.0-rc2+.
> Results directories:
> - Micro: `micro/results/vm_micro_20260325_023400/`
> - Corpus: `corpus/results/vm_corpus_20260325_023726/`
> - E2E: `e2e/results/{tracee,tetragon,katran,bpftrace,scx,bcc}_2026032*/`
> - Static verify: `daemon/tests/results/static_verify.json` + `docs/tmp/20260324/static_verify.full_micro.rerun.json`

---

## Part 1: Performance Analysis

### 1.1 Micro Benchmark

| Metric | Value |
|--------|-------|
| Total benchmarks | 62 |
| Correctness pass (all) | 62/62 (100%) |
| Applied (has optimization sites) | 53 |
| Not applied | 9 |
| **Geomean speedup (all 62)** | **1.0673x** |
| **Geomean speedup (applied-only 53)** | **1.0735x** |
| Improvements (> 1.0x) | 41 |
| Regressions (< 1.0x) | 21 |
| Neutral (= 1.0x) | 0 |

**Configuration**: iterations=3, warmups=1, repeat=100, 3 runtimes (kernel, kernel-rejit, llvmbpf).

#### Top 5 Best Speedups

| Benchmark | Speedup | kernel (ns) | rejit (ns) | Sites | Passes |
|-----------|---------|-------------|------------|-------|--------|
| dep_chain_short | 6.628x | 623 | 94 | 6 | wide_mem |
| rotate64_hash | 2.632x | 100 | 38 | 207 | rotate, wide_mem |
| packet_rss_hash | 1.889x | 34 | 18 | 0 | (none) |
| log2_fold | 1.794x | 375 | 209 | 9 | wide_mem |
| cgroup_hash_chain | 1.634x | 526 | 322 | 6 | wide_mem |

#### Bottom 5 (Worst Regressions)

| Benchmark | Speedup | kernel (ns) | rejit (ns) | Sites | Passes |
|-----------|---------|-------------|------------|-------|--------|
| code_clone_2 | 0.419x | 281 | 670 | 6 | rotate, wide_mem |
| branch_flip_dense | 0.613x | 203 | 331 | 0 | (none) |
| memory_pair_sum | 0.800x | 8 | 10 | 6 | wide_mem |
| mixed_alu_mem | 0.811x | 540 | 666 | 9 | extract, wide_mem |
| branch_dense | 0.816x | 652 | 799 | 12 | rotate, wide_mem |

#### All Regressions (21 benchmarks, rejit < stock)

| Benchmark | Speedup | Notes |
|-----------|---------|-------|
| code_clone_2 | 0.419x | rotate+wide_mem; severe regression |
| branch_flip_dense | 0.613x | No sites applied (VM noise or baseline artifact) |
| memory_pair_sum | 0.800x | Very small program (8ns); noise dominates |
| mixed_alu_mem | 0.811x | extract+wide_mem |
| branch_dense | 0.816x | rotate+wide_mem |
| bitcount | 0.834x | wide_mem only |
| nested_loop_3 | 0.883x | wide_mem only |
| large_mixed_500 | 0.900x | rotate+wide_mem |
| tc_bitcount | 0.932x | wide_mem only |
| load_byte_recompose | 0.934x | wide_mem only |
| large_mixed_1000 | 0.935x | rotate+wide_mem |
| struct_field_cluster | 0.966x | No sites applied (noise) |
| stride_load_4 | 0.986x | Marginal, within noise |
| multi_acc_4 | 0.988x | Marginal, within noise |
| load_byte | 0.989x | Marginal, within noise |
| extract_dense | 0.990x | extract only; 1536 sites, near-neutral |
| spill_pressure | 0.991x | Marginal |
| endian_swap_dense | 0.992x | endian_fusion only; 768 sites, near-neutral |
| checksum | 0.993x | Marginal |
| addr_calc_stride | 0.993x | No sites applied (noise) |
| cmov_select | 0.999x | Marginal |

**Observation**: Of the 21 regressions, 11 are marginal (0.93-1.0x range, likely within VM noise). The severe regressions (code_clone_2, branch_flip_dense, memory_pair_sum, mixed_alu_mem, branch_dense) deserve investigation.

#### Per-Pass Contribution

| Pass | Benchmarks with pass | Geomean speedup |
|------|---------------------|-----------------|
| wide_mem | 49 | 1.0717x |
| rotate | 13 | 1.0387x |
| extract | 4 | 0.9524x |
| endian_fusion | 1 | 0.9921x |

**Counts**: wide_mem=147 invocations, rotate=39, extract=12, endian_fusion=3. Total sites applied: 4,797.

**Key insight**: wide_mem is the dominant pass both in coverage and positive impact. Extract and endian_fusion show near-neutral or slightly negative geomean -- extract is dragged down by mixed_alu_mem (0.81x). Rotate has positive contribution overall but some cases (code_clone_2, branch_dense, large_mixed_500/1000) show regression, suggesting I-cache pressure from code expansion.

#### Notable Non-Applied Anomalies

Some benchmarks with 0 applied sites show speedup variance:
- packet_rss_hash: 1.889x (sites=0) -- likely VM noise / measurement artifact
- cond_select_dense: 1.191x (sites=0) -- same
- branch_flip_dense: 0.613x (sites=0) -- concerning; rejit binary path overhead?

These suggest the rejit path has some non-trivial overhead even when no transforms are applied, possibly due to the recompilation/reverification cycle itself.

---

### 1.2 Corpus Benchmark

| Metric | Value |
|--------|-------|
| Total programs | 152 |
| Measured pairs | 152 |
| Applied (with sites) | 66 (via families) / 54 (via speedup filter) |
| **Geomean speedup (all 152)** | **1.0904x** |
| Max speedup | 3.800x (xdp_drop_func) |
| Min speedup | 0.196x (test_skb_helpers) |
| Improvements (> 1.0x) | 80 |
| Regressions (< 1.0x) | 66 |
| Sources | 9 (calico, katran, linux-selftests, xdp-tutorial, xdp-tools, tracee, suricata, libbpf-bootstrap, real_world_code_size) |

**Configuration**: repeat=100, VM execution, packet mode.

#### By Project

| Source | Programs | Applied | Geomean | Wins | Regressions |
|--------|----------|---------|---------|------|-------------|
| calico | 59 | 48 | 1.001x | 27 | 30 |
| linux-selftests | 59 | 7 | 1.040x | 29 | 27 |
| xdp-tutorial | 20 | 4 | 1.538x | 15 | 4 |
| katran | 5 | 1 | 1.371x | 4 | 1 |
| xdp-tools | 4 | 2 | 1.105x | 2 | 2 |
| tracee | 2 | 2 | 0.958x | 1 | 1 |
| suricata | 1 | 0 | 0.364x | 0 | 1 |
| libbpf-bootstrap | 1 | 1 | 1.667x | 1 | 0 |
| real_world_code_size | 1 | 1 | 2.143x | 1 | 0 |

#### By Family

| Family | Programs | Applied | Geomean | Wins | Regressions | Sites |
|--------|----------|---------|---------|------|-------------|-------|
| cmov | 68 | 50 | 1.057x | 32 | 35 | 233 |
| wide | 35 | 35 | 1.059x | 17 | 18 | 330 |
| rotate | 4 | 2 | 0.914x | 2 | 2 | 1,840 |
| endian | 0 | 0 | N/A | 0 | 0 | 0 |
| extract | 0 | 0 | N/A | 0 | 0 | 0 |
| branch-flip | 0 | 0 | N/A | 0 | 0 | 0 |
| lea | 0 | 0 | N/A | 0 | 0 | 0 |

**Key observation**: Calico (the largest project, 59 programs) shows near-neutral geomean (1.001x) with roughly equal wins vs regressions (27/30). The high overall geomean (1.09x) is boosted by xdp-tutorial (1.54x) and libbpf-bootstrap/real_world_code_size (small programs with large ratios). The corpus result is thus heavily influenced by composition.

#### Severe Corpus Regressions (< 0.50x)

| Program | Source | Speedup | Families |
|---------|--------|---------|----------|
| test_skb_helpers | linux-selftests | 0.196x | (none) |
| __encap_ip6gre_mpls | linux-selftests | 0.263x | (none) |
| xdp_fwd_fib_direct | xdp-tools | 0.333x | cmov |
| xdp_hashfilter | suricata | 0.364x | cmov |
| __encap_ip6vxlan_eth | linux-selftests | 0.368x | (none) |
| balancer_ingress | katran | 0.406x | cmov, wide, rotate |
| __encap_ip6gre_eth | linux-selftests | 0.412x | (none) |
| calico_tc_skb_accepted_entrypoint | calico | 0.416x | cmov |
| calico_tc_skb_send_tcp_rst | calico | 0.435x | cmov, wide |
| calico_xdp_norm_pol_tail | calico | 0.444x | (none) |

**Note**: Many severe regressions are from linux-selftests programs with no families applied (sites=0), suggesting these are measurement artifacts from very small programs in VM environment. The calico and katran regressions with applied families are more concerning -- likely I-cache pressure or CMOV in wrong branch-predictability context.

---

### 1.3 E2E Benchmark

#### Tracee (Observability)

| Metric | Value |
|--------|-------|
| Status | completed |
| Programs loaded | 27 |
| Programs with measurement data | 8/27 |
| REJIT applied | Yes |

**Workload comparison (stock vs rejit):**

| Workload | Throughput | BPF ns/run | Events/sec |
|----------|-----------|------------|------------|
| exec_storm | +3574% (anomalous) | -12.8% | +129.7% |
| file_io | +0.9% | +6.5% | +0.2% |
| network | -0.8% | +0.2% | -0.8% |

**Per-program BPF ns/run deltas:**
- tracepoint__raw: +0.45%, +0.21% (marginal)
- tracepoint__sch: +0.49%, +84.3% (one anomalous), +0.34%, -0.62%
- trace_security_: +1.02%, +0.26%

**Assessment**: Tracee shows near-neutral performance overall. The exec_storm anomaly (+3574% throughput) is suspicious and likely a measurement artifact (possibly different baseline state). Most individual program BPF ns/run deltas are within +/-1%, except one anomalous tracepoint__sch measurement (+84.3%). The scan found no optimization sites, so this is a "zero overhead" transparency test. The scan_results are empty, suggesting no kinsn sites were found in Tracee's programs.

#### Tetragon (Security Enforcement)

| Metric | Value |
|--------|-------|
| Status | completed |
| Programs loaded | 7 |
| REJIT applied | Yes |

**Workload comparison:**

| Workload | Throughput | BPF ns/run | Agent CPU |
|----------|-----------|------------|-----------|
| connect_storm | -1.1% | -44.1% | -2.4% |
| file_io | +4.9% | -1.9% | -0.0% |
| open_storm | -0.6% | +48.4% | -1.7% |
| stress_exec | **+22.2%** | **-34.1%** | **-90.9%** |

**Assessment**: stress_exec shows strong improvement (+22.2% throughput, -34.1% BPF ns/run, -90.9% agent CPU). connect_storm also shows BPF improvement (-44.1%) but marginal throughput change. open_storm shows BPF regression (+48.4%) but is within throughput noise. Mixed results overall, with the best case (stress_exec) being paper-worthy.

#### Katran (Networking/Load Balancing)

| Metric | Value |
|--------|-------|
| Status | completed |
| Sample count | 3 (paired cycles) |
| Program | balancer_ingress (XDP) |
| BPF speedup ratio | 0.935x |

**Comparison:**

| Metric | Delta |
|--------|-------|
| App throughput (RPS) | -4.5% |
| BPF avg ns/run | +6.9% |
| Latency p99 | +4.4% |
| System CPU busy | +2.4% |

**Assessment**: Katran shows a **regression** -- BPF is 6.9% slower, throughput drops 4.5%. This is consistent with the corpus result where balancer_ingress shows 0.406x speedup. The program uses cmov+wide+rotate families, and the combined transforms appear to be harmful for this workload. This is a key finding: complex production programs (katran's balancer_ingress has 2322 insns, 23872 xlated) may regress from optimization passes.

#### bpftrace

| Metric | Value |
|--------|-------|
| Status | completed |
| Scripts measured | 6 baseline, 5 rejit |
| Sites applied | 0 across all scripts |
| Geomean speedup | 1.471x |

**Per-script:**

| Script | Speedup | Notes |
|--------|---------|-------|
| tcplife | N/A | No rejit data |
| biosnoop | 1.068x | |
| runqlat | 1.029x | |
| tcpretrans | N/A | No speedup measurement |
| capable | 4.171x | Suspiciously high |
| vfsstat | 1.020x | |

**Assessment**: No optimization sites found in bpftrace programs. The speedup values (especially capable at 4.17x) are artifacts of measurement noise, not actual optimization. The geomean of 1.47x is misleading. This is essentially a transparency test confirming bpftrace works with rejit kernel.

#### sched_ext (scx)

| Metric | Value |
|--------|-------|
| Status | completed |
| Sites | 0 (no kinsn sites in scx programs) |
| Scanned programs | 0 |

**Workload comparison:**

| Workload | Throughput | Latency p50 | Context switches |
|----------|-----------|-------------|-----------------|
| hackbench | -0.4% | +2.5% | +0.9% |
| stress-ng-cpu | +0.3% | N/A | -20.1% |
| sysbench-cpu | -0.04% | 0.0% | -16.8% |

**Assessment**: Near-neutral. No optimization sites found, so this is a transparency test. The context switch reduction in stress-ng and sysbench is interesting but may be noise. Confirms scx works with rejit kernel.

#### bcc

| Metric | Value |
|--------|-------|
| Status | completed |
| All tools skipped | Yes (binaries not found) |
| Measured pairs | 0 |

**Assessment**: **Complete failure.** All 8 bcc tools (tcplife, biosnoop, runqlat, execsnoop, opensnoop, capable, vfsstat, tcpconnect) failed with "binary not found" errors. The bcc libbpf-tools were not built/installed in the VM. This case provides no useful data.

---

### 1.4 Static Verify

#### Full Micro Static Verify (62 programs)

| Metric | Value |
|--------|-------|
| Objects total | 62 |
| Objects OK | 62 |
| Programs total | 62 |
| Programs OK | 62 |
| **Verifier accepted** | **62/62 (100%)** |
| Programs applied | 53 |
| Programs unchanged | 9 |
| Verifier retries | 0 |
| Avg insn delta (applied) | -42.3 insns |
| Avg code delta (applied) | -188.3 bytes |

**Passes applied:**
- wide_mem: 49 programs
- rotate: 13 programs
- extract: 4 programs
- endian_fusion: 1 program

#### Latest Static Verify (1 program test)

| Metric | Value |
|--------|-------|
| Program | rotate_dense_xd |
| Insn before | 2,796 |
| Insn after | 2,284 (-512, -18.3%) |
| Code before | 10,200 bytes |
| Code after | 7,640 bytes (-2,560, -25.1%) |
| Verifier accepted | Yes |
| Passes | rotate |

**Assessment**: 100% verifier acceptance across all 62 micro programs. The insn reduction averages -42 insns per applied program, and code size reduction averages -188 bytes. The rotate_dense case shows dramatic 25% code size reduction. No verifier retries needed.

---

## Part 2: Test Quality Assessment

### 2.1 Statistical Sufficiency

| Parameter | Current | OSDI Target | Assessment |
|-----------|---------|-------------|------------|
| **Iterations** | 3 | 30+ | **CRITICALLY INSUFFICIENT.** 3 iterations provides no statistical power. |
| **Warmups** | 1 | 3-5 | **INSUFFICIENT.** 1 warmup may not stabilize caches. |
| **Repeat** | 100 | 100-1000 | Acceptable for inner loop. |
| **Significance testing** | None | Required | **MISSING.** No p-values, confidence intervals, or effect size analysis. |
| **Runtime order randomization** | Yes (per-iteration) | Required | Good. Randomized across 3 runtimes. |

**Critical gap**: With only 3 iterations, the data cannot support claims about statistical significance. The many marginal results (0.98-1.02x) are indistinguishable from noise. OSDI reviewers will reject without >= 30 iterations and proper significance testing.

### 2.2 Coverage

| Layer | Target | Measured | Gap |
|-------|--------|----------|-----|
| Micro benchmarks | 62 | 62/62 (100%) | None |
| Corpus targets | 166 inventory | 152 measured | 14 unmeasured |
| E2E - Tracee | 1 | 1 (completed) | Need more workloads |
| E2E - Tetragon | 1 | 1 (completed) | |
| E2E - Katran | 1 | 1 (completed) | |
| E2E - bpftrace | 1 | 1 (completed, no sites) | Transparency test only |
| E2E - scx | 1 | 1 (completed, no sites) | Transparency test only |
| E2E - bcc | 1 | **0 (FAILED)** | **Build issue, needs fix** |

**Pass coverage in micro:**
- wide_mem: 49/62 programs -- excellent
- rotate: 13/62 programs -- good
- extract: 4/62 programs -- limited
- endian_fusion: 1/62 programs -- minimal
- cond_select (cmov): not separately tracked in micro (in corpus: 68 programs)
- branch-flip, lea: 0 programs -- not tested

**Corpus family coverage:**
- cmov: 68 programs (best coverage)
- wide: 35 programs
- rotate: 4 programs (very limited)
- endian, extract, branch-flip, lea: 0 programs

**Gap**: The micro benchmark suite is heavily biased toward wide_mem. Extract has only 4 benchmarks, endian_fusion has 1, and there are no dedicated cmov micro benchmarks (cmov appears only in corpus). A balanced evaluation needs more extract/endian/cmov micro benchmarks.

### 2.3 Credibility

| Factor | Assessment |
|--------|------------|
| **VM environment (QEMU/KVM)** | Moderate noise. Known to inflate variance vs bare-metal. |
| **Bare-metal data** | **MISSING.** No bare-metal results available. |
| **VM noise evidence** | Non-applied benchmarks (0 sites) show up to 1.89x and 0.61x variation -- clear noise. |
| **Measurement artifacts** | E2E tracee exec_storm +3574% is obvious artifact. Katran BPF regression consistent between e2e and corpus. |
| **CPU governor** | "unknown" -- not pinned to performance. This is a significant concern. |
| **CPU affinity** | null -- not set. Another concern. |
| **Turbo state** | "unknown" -- not controlled. |

**Non-applied benchmark noise analysis:**

| Benchmark (0 sites) | "Speedup" | |
|---------------------|-----------|---|
| packet_rss_hash | 1.889x | Extreme noise |
| cond_select_dense | 1.191x | Moderate noise |
| branch_flip_dense | 0.613x | Extreme noise |
| struct_field_cluster | 0.966x | Moderate noise |
| addr_calc_stride | 0.993x | Low noise |
| simple/simple_packet/etc | 1.000x | Stable |

With 0-site benchmarks showing up to +89%/-39% variation, any result within this range is not statistically meaningful at 3 iterations.

### 2.4 Missing Items

1. **bcc E2E completely broken** -- binary not found for all 8 tools. Needs build fix.
2. **No bare-metal data** -- VM-only results have questionable credibility for OSDI.
3. **No significance tests** -- Need p-values for all claims.
4. **No confidence intervals** -- Only median/mean reported, no CI.
5. **No effect size analysis** -- Cohen's d or similar needed.
6. **Iterations far too low** -- 3 vs 30+ needed for OSDI.
7. **CPU governor/affinity/turbo not controlled** -- Major confound.
8. **No ablation study in current run** -- Need per-pass ablation (only combined results).
9. **Extract pass barely tested** -- Only 4 micro benchmarks, 0 corpus programs.
10. **Endian pass barely tested** -- Only 1 micro benchmark, 0 corpus programs.
11. **No hardware perf counter data** -- `perf_counters: false` in all runs.
12. **Code size reduction not measured in E2E** -- Only in corpus and static verify.

---

## Part 3: Key Numbers for Paper

### Headline Numbers (with caveats)

| Metric | Value | Confidence | Caveat |
|--------|-------|------------|--------|
| Micro geomean (all) | **1.067x** | LOW (3 iters, VM) | Need 30+ iterations |
| Micro geomean (applied-only) | **1.074x** | LOW | Need 30+ iterations |
| Corpus geomean (all 152) | **1.090x** | LOW (composition-sensitive) | Heavily influenced by small programs |
| Corpus code size reduction geomean | **1.005x** (0.5%) | MEDIUM | Consistent across runs |
| Micro correctness | **62/62** | HIGH | Deterministic |
| Verifier acceptance | **62/62 (100%)** | HIGH | Deterministic |
| Verifier retries | **0** | HIGH | No retry needed |
| Tracee (exec_storm BPF ns) | **-12.8%** | LOW | Anomalous throughput data |
| Tetragon (stress_exec throughput) | **+22.2%** | LOW (3 samples) | Single workload best-case |
| Tetragon (stress_exec BPF ns) | **-34.1%** | LOW | |
| Katran BPF speedup | **0.935x (regression)** | MEDIUM | Consistent with corpus |
| E2E transparency | **5/6 working** | HIGH | bcc failed (build issue, not regression) |
| Applied rate (micro) | **53/62 (85%)** | HIGH | |
| Applied rate (corpus) | **66/152 (43%)** | HIGH | |
| Recompile overhead | **~1.6s median** | MEDIUM | This is full recompile including llvmbpf JIT |
| Avg insn reduction (applied) | **-42.3 insns** | HIGH | From static verify |
| Avg code size reduction (applied) | **-188 bytes** | HIGH | From static verify |
| Max code size reduction | **-2,560 bytes (-25.1%)** | HIGH | rotate_dense |

### Comparison with v1 Authoritative Data

| Metric | v1 | v2 (current) | Delta |
|--------|-----|-------------|-------|
| Micro geomean (all) | 1.057x | 1.067x | +0.010x improved |
| Micro applied-only | 1.193x | 1.074x | -0.119x regressed |
| Corpus geomean | 0.983x | 1.090x | +0.107x **much improved** |
| Tracee exec_storm | +8.1% | -12.8% BPF ns | different metric |
| Tetragon | +20.3%/+32.2% | +22.2% (stress_exec) | comparable |

**Notable**: v2 corpus is dramatically better than v1 (1.090x vs 0.983x). Micro applied-only is lower (1.074x vs 1.193x), possibly because v2 has more passes that are not always beneficial. The micro overall is slightly better (1.067x vs 1.057x).

### Numbers NOT Ready for Paper

1. **Any geomean claimed with < 30 iterations** -- need rerun with proper iterations
2. **E2E Tracee exec_storm +3574% throughput** -- artifact, discard
3. **bpftrace 1.47x geomean** -- artifact of 0-site noise, discard
4. **Katran regression** -- needs investigation (is the transform incorrect for this program?)
5. **Any claimed improvement < 5%** -- cannot distinguish from VM noise at 3 iterations
6. **bcc results** -- completely missing

---

## Summary and Recommendations

### What's Working
1. **Correctness and safety**: 62/62 verifier acceptance, 62/62 correctness pass -- the framework's safety story is solid.
2. **Transparency**: 5/6 E2E cases run successfully (bcc is a build issue, not a framework issue).
3. **Corpus improvement**: 1.09x geomean across 152 real-world programs is a genuine improvement over v1's 0.983x.
4. **Code size reduction**: Consistent, verifiable insn and code size reductions.

### What Needs Fixing (Priority Order)
1. **Iterations**: Increase from 3 to 30+ for all micro and corpus benchmarks. This is blocking for paper.
2. **CPU governor/affinity/turbo**: Pin to performance governor, set CPU affinity, disable turbo. This is blocking for credible results.
3. **bcc E2E**: Fix binary build issue so all 6 E2E cases have data.
4. **Katran regression**: Investigate why balancer_ingress regresses -- is it I-cache pressure from code expansion? CMOV in wrong context?
5. **code_clone_2 regression**: 0.419x is severe. Debug what rotate+wide_mem does to this program.
6. **Bare-metal run**: At least one bare-metal comparison to bound VM noise.
7. **Significance testing**: Add bootstrap CI and p-value computation to analysis pipeline.
8. **Pass coverage**: Add more extract and endian micro benchmarks to demonstrate each pass independently.
9. **Hardware counters**: Enable perf counters (instructions, cycles, cache misses, branch mispredictions) for at least one full micro run.
10. **Ablation study**: Run micro with each pass individually disabled to measure per-pass contribution.
