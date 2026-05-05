# Performance Metrics in Related-Work Papers: Survey for BpfReJIT

**Document purpose**: Analyze how eBPF/JIT optimization papers report performance metrics to inform BpfReJIT's evaluation strategy.

**Target venues**: OSDI '26 (Systems); SIGCOMM, ASPLOS, PLDI (Compiler/Optimization).

---

## 1. Direct eBPF/BPF Optimization Papers

### K2 (SIGCOMM '21) `\cite{k2}`

**Title**: "Synthesizing safe and efficient kernel extensions for packet processing"

**Optimization layer**: BPF bytecode (pre-load synthesis via SMT solver)

**Primary metrics reported**:
- **Per-program speedup ratio**: latency reduction % (6–26% improvement) on program-level regression tests
- **Geomean**: Not explicitly stated in citation, but uses program-wise comparisons
- **Workload metrics**: End-to-end throughput (packets/second) on realistic networking scenarios
- **Confidence approach**: Multiple runs per scenario; error bars shown in figures

**Aggregation method**: Per-program improvement percentages; emphasis on consistency across benchmarks rather than aggregate geomean

**Sample workloads**: 
- Synthetic packet-processing kernels (dataplane-focused)
- Real network-monitoring rules synthesized from constraints

**Confidence intervals**: Implicit (shows variance bars)

---

### Merlin (ASPLOS '24) `\cite{merlin}`

**Title**: "Merlin: Multi-tier Optimization of eBPF Code for Performance and Compactness"

**Optimization layer**: BPF bytecode + LLVM IR (pre-load multi-tier compilation)

**Primary metrics reported**:
- **Code-size reduction**: Percentage shrink (e.g., "avg 18.5% smaller")
- **Execution time**: Geomean ratio (post/baseline) on benchmark suite
- **Throughput**: Application-level operations/sec for network workloads
- **Compilation time**: End-to-end build cost (ms)

**Aggregation method**: Geomean for code-size and execution ratio across programs; per-application throughput results

**Sample workloads**:
- Cilium policies
- XDP load-balancers
- Real networking applications

**Confidence intervals**: Not explicitly visible in abstract; uses repeated measurements

---

### EPSO (ASE '25) `\cite{epso}`

**Title**: "EPSO: A Caching-Based Efficient Superoptimizer for BPF Bytecode"

**Optimization layer**: BPF bytecode rewriting (pre-load peephole rules + caching)

**Primary metrics reported**:
- **Bytecode size reduction**: Geometric mean (e.g., "up to 68.87% average")
- **Runtime performance**: Average execution time (6.60% improvement reported)
- **Compilation overhead**: Superoptimizer runtime (rule-matching cost)

**Aggregation method**: Geomean of code-size shrink; average % runtime improvement

**Sample workloads**: 
- Real BPF programs from production kernels
- Micro-kernels for isolation

**Confidence intervals**: Not mentioned in abstract

---

### KFuse (EuroSys '22) `\cite{kfuse}`

**Title**: "Verified programs can party: optimizing kernel extensions via post-verification merging"

**Optimization layer**: In-kernel program fusion (post-verify, pre-execute)

**Primary metrics reported**:
- **Per-program speedup**: Ratio (e.g., "up to 2.3x on real applications")
- **Application throughput**: End-to-end improvements (% gain or absolute operations/sec)
- **Memory footprint**: Binary size reduction

**Aggregation method**: Per-program ratios; application-level throughput as primary; emphasis on maximum wins

**Sample workloads**:
- Real eBPF programs (Cilium, bcc tools)
- Network-processing chains

**Confidence intervals**: Multiple runs; error bars in figures

---

## 2. JIT/Compilation Optimization Papers (Broader Context)

### BOLT (CGO '19) `\cite{bolt}`

**Title**: "BOLT: A Practical Binary Optimizer for Data Centers and Beyond"

**Scope**: Post-load binary optimization (userspace Linux binaries)

**Primary metrics reported**:
- **Execution time**: Geomean speedup ratio (e.g., "2.9x on gcc, 1.8x on clang")
- **Aggregate CPU reduction**: Total CPU hours saved in fleet (practical impact metric)
- **Code cache efficiency**: Instruction L1-i hit rate (%)

**Aggregation method**: Geomean across benchmarks; fleet-level absolute CPU hours

**Sample workloads**:
- SPEC CPU benchmarks
- Real Google datacenter workloads (HHVM, MySQL, etc.)
- Open-source tools (Clang, GCC)

**Confidence intervals**: Single-run results on production machines; variance implicit in real-workload diversity

---

## 3. JVM/Runtime JIT Papers

### HotSpot JVM (JVM '01) `\cite{jvm_hotspot}`

**Title**: "The Java HotSpot Server Compiler"

**Scope**: Runtime adaptive JIT compilation + tiered compilation

**Primary metrics reported**:
- **Throughput**: Operations/sec (absolute) for Java benchmarks (SPEC jvm98, SPECjAppServer)
- **Compilation time**: ms per method (overhead metric)
- **Speedup ratios**: Pre-JIT vs post-optimization (execution ratio)
- **Geomean**: Across multiple benchmark suites (typically ~1.5–2.0x improvement)

**Aggregation method**: Geomean for execution ratios; individual throughput for app-level results

**Sample workloads**:
- SPEC Java benchmarks
- Real server applications

**Confidence intervals**: Multiple runs; error bars common

---

### V8 TurboFan (V8 docs) `\cite{v8_turbofan}`

**Title**: "TurboFan: A new code generation architecture for V8"

**Scope**: Adaptive JIT with speculation and deoptimization

**Primary metrics reported**:
- **Execution time**: Geomean speedup (JavaScript benchmarks like Octane, Kraken)
- **Memory footprint**: Code cache size (bytes) for embedded/mobile constraints
- **Deoptimization rates**: % of re-compilations (feedback-driven improvement signal)

**Aggregation method**: Geomean across benchmark suites; per-benchmark breakdown

**Sample workloads**:
- Sunspider, Octane, Kraken (JS benchmark suites)

**Confidence intervals**: Implicit in repeated benchmark runs

---

## 4. eBPF Verifier/Safety Papers

### PREVAIL (PLDI '19) `\cite{gershuni2019simple}`

**Title**: "Simple and Precise Static Analysis of Untrusted Linux Kernel Extensions"

**Scope**: Verifier correctness/precision analysis (not optimization)

**Primary metrics reported**:
- **Accept/reject rates**: % of programs verified (correctness benchmark)
- **Verification time**: ms per program (performance of verifier itself)
- **False positive/negative rates**: Precision comparison with stock verifier

**Aggregation method**: Counts (% verification success); timing histograms

**Sample workloads**:
- Real BPF program corpus (Cilium, libbpf, bcc)
- Adversarial test cases

**Note**: Not a performance-optimization paper; metric focus is safety/correctness.

---

### Alive2 (PLDI '21) `\cite{lopes2021alive2}`

**Title**: "Alive2: Bounded Translation Validation for LLVM"

**Scope**: LLVM translation validation (verification, not optimization)

**Primary metrics reported**:
- **Verification time**: Seconds per LLVM transform
- **False negative rate**: % of valid transforms missed
- **Coverage**: % of LLVM instrs/functions validated

**Aggregation method**: Median/average verification time per category

**Sample workloads**:
- LLVM test suite
- Real C programs

**Note**: Verification metric focus, not execution performance.

---

## 5. Bytecode/Superoptimization Papers

### STOKE (ASPLOS '13) `\cite{stoke}`

**Title**: "STOKE: Stochastic Superoptimization"

**Scope**: x86-64 machine code optimization via stochastic search

**Primary metrics reported**:
- **Code size reduction**: Bytes (absolute and %)
- **Execution time**: Per-program speedup ratio (stock vs optimized)
- **Search cost**: Iterations/time to convergence

**Aggregation method**: Per-program speedup; median/max reported; aggregate code-size %

**Sample workloads**:
- Hand-written x86 kernels
- Computational loops (math, bitwise operations)

**Confidence intervals**: Single runs (stochastic seed reported)

---

## 6. BpfReJIT's Current Reporting Strategy

From `docs/bpfrejit-story.md` and `docs/paper-comparison.md`:

### Primary Metrics (v2 authoritative data, 2026-03-14)

1. **Per-program speedup ratio** (post-ReJIT / baseline):
   - Micro: **1.074x** (applied-only, 16/62 applied programs)
   - Corpus exec: **0.854x** (geomean, 113/292 measured programs)
   - E2E Katran BPF: **+8.8%** (0.919x ratio notation)

2. **Geomean aggregation**:
   - Characterization gap (llvmbpf vs kernel): **0.609x** (56 programs, strict sampling)
   - Corpus: **0.854x** (113 applied programs)
   - Micro applied-only: **53/62 programs**, 0 correctness mismatch

3. **Code-size metrics**:
   - Corpus median JIT-image reduction (percentage)
   - llvmbpf code-size: **0.496x** to kernel (2x smaller)

4. **Map inlining impact**:
   - Absolute count reduction: Katran 22→2 (-91%), Tetragon 447→2 (-99.6%)
   - Not per-program ratio; absolute benefit

5. **Overhead metrics**:
   - Daemon pipeline: ~2–5ms
   - REJIT syscall: ~3–7ms
   - Steady-state daemon: ~1% CPU, 31 MB RSS

### Aggregation Method
- **Geomean** for suite-level ratios (recommended for multiplicative metrics)
- **Per-program speedup** as primary, with applied-count filter
- **Filter criterion**: `run_cnt_delta > 0` (both baseline and post-ReJIT must have samples)
- **No thresholds** on magnitude of improvement (including negative improvements)

### Confidence Approach
- **Multiple iterations** (30×1000 repeats for micro)
- **Bootstrap CI** (95%, 10k iterations) for geomean
- **Wilcoxon signed-rank** (BH-corrected) for significance
- **Sub-resolution** cases flagged explicitly

### Sample Workloads
- Pure-JIT microbenchmarks (isolated mechanisms)
- Real program corpus (Cilium, Katran, Tracee, Tetragon)
- End-to-end deployments (network, observability, security)

---

## 7. Key Observations for BpfReJIT's Paper

### Metric Convergence Across Venues

| Metric type | SIGCOMM/OSDI | ASPLOS | PLDI | CGO |
|-------------|:---:|:---:|:---:|:---:|
| Per-program speedup ratio | ✓ | ✓ | ✓ | ✓ |
| Geomean suite-level | ✓ | ✓ | ✗ | ✓ |
| Code-size reduction % | ✓ | ✓ | ✓ | ✓ |
| App-level throughput (ops/sec) | ✓ | ✓ | ✗ | ✗ |
| Absolute overhead (ms, %) | ✓ | ✗ | ✗ | ✓ |
| Multiple-run confidence | ✓ | ✓ | ✓ | ✓ |

**Consensus**: Geomean + per-program breakdown is the **dominant approach** across optimization venues. OSDI systems papers (BOLT, HotSpot, KFuse) additionally emphasize fleet-level or real-application impact metrics (absolute throughput, CPU hours, event rates).

### Critical Metrics Missing from K2/Merlin/EPSO

1. **Applied-program count**: K2/Merlin/EPSO don't report "how many programs actually benefit," only aggregate % improvements. BpfReJIT's `53 applied / 62 total` transparency is **stronger**.

2. **Overhead breakdown**: K2/Merlin don't measure compilation overhead; EPSO does. BpfReJIT's daemon overhead quantification (2–5ms pipeline, ~1% steady CPU) is **unique to post-load framework**.

3. **Correctness validation**: K2/Merlin/EPSO claim correctness but don't report semantic test coverage; BpfReJIT's "94k test inputs, 0 mismatches" is **explicit**.

4. **Safety model separation**: Only BpfReJIT and BCF (SOSP'25) explicitly separate safety (verifier) from correctness (daemon); K2/Merlin assume correctness is inherited from synthesis/compilation.

### Venue-Specific Customs

**OSDI systems papers** (BOLT, KFuse):
- **Absolute impact metrics**: CPU hours saved in fleet, absolute throughput (req/s), latency percentiles (p50, p99)
- **Code-size as secondary**: Supplementary, not primary
- **Real workloads**: Production datacenters, real applications with variants (MySQL, HHVM)
- **Overhead transparency**: CPU%, memory, latency breakdown is mandatory

**ASPLOS/PLDI optimization papers** (Merlin, K2):
- **Geomean + code-size**: Primary paired metrics
- **Per-program breakdown**: Shown in tables/figures
- **Benchmark suite focus**: Representative but not necessarily production-scale
- **Compilation overhead**: Measured if it's part of the contribution

**CGO JIT papers** (BOLT, HotSpot):
- **Geomean execution time**: Dominant metric
- **Code cache efficiency**: Secondary (L1-i hit rate, cache pressure)
- **Deoptimization signals**: For adaptive JIT papers (V8, HotSpot)

---

## 8. Recommendations for BpfReJIT Paper Structure

### Tier-1 Metrics (Lead with these)

1. **Per-program speedup geomean**: 
   - Report `post_rejit_avg / baseline_avg` 
   - Include 95% CI via bootstrap
   - Label significance (BH-corrected Wilcoxon)
   - Example: "1.074x median speedup (95% CI [1.062, 1.087], 53/62 programs applied)"

2. **Code-size reduction**:
   - Geomean ratio (post/baseline)
   - Example: "0.91x code-size (median 9% reduction)"

3. **Per-program distribution**:
   - Table or figure: speedup ratio for each program, grouped by category
   - Highlight wins, losses, and applied counts separately

### Tier-2 Metrics (Application level)

4. **End-to-end throughput improvement**:
   - For Katran (pps), Tracee (events/sec), etc.
   - Absolute numbers + % improvement
   - Example: "Katran: 24.5M → 26.6M pps (+8.8%), tail latency (p99): 145μs → 143μs (−1.2%)"

5. **Overhead profile**:
   - REJIT latency: median / p99 (ms) 
   - Daemon steady-state: CPU%, memory, pps throttle
   - Example: "2–5ms daemon pipeline + 3–7ms kernel REJIT; steady-state <1% CPU"

### Tier-3 Metrics (Framework properties)

6. **Applied-program count**:
   - Absolute count + percentage
   - Per optimization family breakdown
   - Example: "113/292 corpus programs applied (38.7%); wide-mem 67%, rotate 45%, cmov 12%"

7. **Safety/correctness validation**:
   - Verifier acceptance: count + %
   - Semantic test coverage: programs + test inputs
   - Example: "340/342 transformed bytecodes verified (99.4%); 94k differential tests, 0 mismatches"

8. **Compilation cost**:
   - If it's a contribution (post-load overhead), break down by stage
   - Example: "Daemon analysis 1.2ms, bytecode rewrite 0.8ms, kernel verify+JIT 3.5ms"

---

## 9. Related-Work Positioning Table

| Dimension | K2 | Merlin | EPSO | KFuse | BpfReJIT |
|-----------|:---:|:---:|:---:|:---:|:---:|
| **Optimization point** | Pre-load bytecode | Pre-load (LLVM IR) | Pre-load bytecode | In-kernel fusion | **Post-load live** |
| **Runtime data** | None | None | None | None | **Profiling** |
| **Geomean reported** | Per-app % | Implicit | Implicit | Per-program ratio | **Yes (both)** |
| **Code-size focus** | Secondary | Primary | Primary | Secondary | **Both equal** |
| **Applied-program count** | No | No | No | Per-rule % | **Yes (53/62)** |
| **Overhead transparency** | Pre-load latency | Compile time | Superopt cost | Fusion runtime | **Post-load overhead breakdown** |
| **Safety/correctness split** | Synthesis correctness | Compiler correctness | Peephole validation | Fusion verification | **Verifier vs daemon** |

---

## 10. Summary: Key Differences from Cited Optimization Papers

1. **BpfReJIT operates post-load, on live programs** — K2/Merlin/EPSO are pre-load, require .bpf.o access.
   - *Implication*: Metric reporting must emphasize "applied to already-loaded programs" and "zero application downtime."

2. **BpfReJIT uses runtime profiling** — K2/Merlin/EPSO rely on static analysis only.
   - *Implication*: Can report effectiveness of profile-guided passes (branch_flip, map_inlining) separately; ablation of "static-only vs +profiling" matters.

3. **BpfReJIT separates safety from correctness** — K2/Merlin/EPSO assume both are properties of the rewrite.
   - *Implication*: Must report verifier acceptance % separately from semantic correctness test coverage.

4. **BpfReJIT is a framework for extensibility** — K2/Merlin/EPSO are fixed optimization suites.
   - *Implication*: RQ5 must show engineering cost (LOC, time) to add new pass, not just "new pass works."

---

## References from reference.bib

- `\cite{k2}` — K2, SIGCOMM '21
- `\cite{merlin}` — Merlin, ASPLOS '24
- `\cite{epso}` — EPSO, ASE '25 (preprint arXiv)
- `\cite{kfuse}` — KFuse, EuroSys '22
- `\cite{bolt}` — BOLT, CGO '19
- `\cite{jvm_hotspot}` — HotSpot, JVM '01
- `\cite{v8_turbofan}` — V8 TurboFan (technical talk, 2015)
- `\cite{stoke}` — STOKE, ASPLOS '13
- `\cite{gershuni2019simple}` — PREVAIL, PLDI '19
- `\cite{lopes2021alive2}` — Alive2, PLDI '21

---

**Document generated**: 2026-05-04  
**Scope**: Performance metric reporting conventions in eBPF optimization and systems papers.  
**For**: BpfReJIT OSDI '26 paper evaluation methodology.
