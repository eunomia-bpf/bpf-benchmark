# eBPF Profiling / Benchmarking / Microarchitectural Analysis Landscape

Date: 2026-03-08

## Executive Summary

The current public tooling ecosystem can already answer a few narrow questions about eBPF program performance:

- `bpf_prog_stats` and tools built on it (`bpftool prog show`, `bpftop`) can tell you cumulative runtime and run count per program.
- `bpftool prog profile` can collect a small fixed set of PMU metrics for a loaded kernel BPF program, using `fentry`/`fexit` and `bpf_perf_event_read_value()`.
- `perf stat --bpf-prog <id>` can collect more general PMU counters for a loaded kernel BPF program, so per-program IPC and branch/cache rates are possible in principle.
- `bpftool prog dump jited` and `bpf_prog_info` expose enough metadata to inspect emitted native code and some line mappings.

But the ecosystem still does **not** provide a strong answer to the questions that matter most for this project:

- Why is one BPF JIT output faster than another?
- Which machine-code patterns explain the delta?
- Can the same methodology work for both kernel BPF JITs and userspace BPF JITs?
- Can PMU evidence be aligned with BPF-aware code generation differences, rather than just reported as aggregate counters?

That is the key gap. A paper or tool that merely wraps existing counters would be incremental. A paper or tool that **automatically explains performance deltas between BPF JIT backends using emitted-code structure plus PMU evidence** still looks meaningfully novel.

My bottom-line assessment:

- The strongest novelty is **not** "another benchmark harness" or "another PMU collector."
- The strongest novelty is a **BPF-aware differential JIT analysis / microarchitectural explanation system** that works across kernel and userspace runtimes.
- The current repository already has most of the right scaffolding to prototype that.

## 1. What The Current Repository Already Does

### 1.1 Runner behavior

`micro/runner/src/main.cpp` is only a thin dispatcher. The actual timing and PMU behavior lives in:

- `micro/runner/src/kernel_runner.cpp`
- `micro/runner/src/llvmbpf_runner.cpp`
- `micro/runner/src/perf_counters.cpp`
- `micro/run_micro.py`

Important details from the implementation:

- Kernel execution time uses `bpf_prog_test_run_opts.duration` as `exec_ns`.
- In upstream kernel code, `BPF_PROG_TEST_RUN` timing is based on `ktime_get_ns()` and averaged over `repeat`; the result is stored in a 32-bit `duration` field.
- The kernel runner also records a userspace `rdtsc`-based `wall_exec_ns`, but that includes syscall dispatch around `BPF_PROG_TEST_RUN`.
- The llvmbpf runner uses `rdtsc/rdtscp` around each `vm.exec()` call and averages cycles over `repeat`.
- PMU collection in this repository uses `perf_event_open()` around the **entire repeated run**.
- In the kernel runner, that PMU window includes kernel-mode activity around `bpf_prog_test_run_opts()`, not only the target BPF instructions.
- In the llvmbpf runner, PMU collection is user-only and is closer to the actual JITed execution window.

This means the repository already contains a measurement asymmetry that matters for novelty positioning:

- Timing is reasonably isolated on both sides, but with `ktime` vs `rdtsc` asymmetry.
- PMU measurement is **not equally target-isolated** on both sides.

That is exactly why a future "BPF-aware microarchitectural profiler" would still be valuable even though this repo already collects perf counters.

### 1.2 Orchestration and methodology

`micro/run_micro.py` is already rigorous in the ways that matter for publishable benchmarking:

- warmups plus repeated measured iterations
- counterbalanced runtime order at iteration granularity
- optional benchmark shuffling
- CPU pinning support
- environment validation (`performance` governor, sudo checks, etc.)
- summary statistics
- derived metrics such as IPC, branch miss rate, and cache miss rate from collected counters

This is a strong foundation for a systems-measurement paper. The repo is already past the "toy benchmark script" stage.

### 1.3 What the docs already acknowledge

`docs/paper.md` and `docs/micro-bench-status.md` already identify the most important measurement caveats:

- `BPF_PROG_TEST_RUN` uses `ktime_get_ns()` on the kernel side, with roughly 100 ns granularity on this platform.
- llvmbpf uses `rdtsc`, so sub-100 ns kernels become asymmetric.
- PMU scope is not equivalent across kernel and userspace.
- `BPF_PROG_TEST_RUN` does not cover all program types.
- PMU evidence is therefore supplementary in the current paper, not the core causal evidence.

This is the correct stance. It also clarifies where a new contribution could be stronger than the current paper: target-isolated PMU attribution and automatic explanation.

## 2. Existing Tools And What They Actually Measure

### 2.1 `bpftool prog profile`

What it does:

- Profiles a loaded kernel BPF program for a fixed duration.
- Official metric menu is small: `cycles`, `instructions`, `l1d_loads`, `llc_misses`, `itlb_misses`, `dtlb_misses`.
- The upstream implementation attaches `fentry` and `fexit` programs to the target, reads perf counters with `bpf_perf_event_read_value()` at entry and exit, and accumulates deltas per CPU.
- It reports `run_cnt`, raw counter `value`, and `enabled` / `running` fields for multiplexing awareness.

What is good about it:

- It is genuinely program-scoped, unlike a coarse system-wide perf session.
- It is much closer to the target BPF execution window than this repository's current kernel-side PMU wrapper around `BPF_PROG_TEST_RUN`.
- It already supports IPC-style reasoning by collecting `cycles` and `instructions`.

Main limitations:

- Kernel BPF only; it says nothing about userspace BPF JITs.
- Very limited metric menu.
- No branch-miss metric.
- No frontend/backend stall metrics.
- No per-invocation distribution; only cumulative totals over the profiling window.
- No per-instruction or per-basic-block attribution.
- Requires the target program to have usable BTF / func info because the implementation uses attach-target resolution.
- Hard-capped to four metrics at a time in upstream code.

Novelty implication:

- A paper that only says "we can collect cycles and instructions for a BPF program" is already covered.
- A paper that unifies this style of isolation with userspace BPF JITs and then explains codegen-level causes is not covered.

### 2.2 `perf` with BPF support

The important current feature is `perf stat --bpf-prog <id>`.

What it enables:

- Per-program PMU counts for an existing kernel BPF program ID.
- In practice this means you can collect cycles, instructions, branch misses, cache misses, and any other supported PMU event or derived perf metric.
- Therefore per-program IPC is possible today.

What it does not solve:

- No BPF-aware explanation layer.
- No built-in alignment with BPF bytecode or emitted JIT instructions.
- No per-invocation latency distribution.
- No per-instruction PMU accounting.
- No symmetry with userspace BPF JITs unless you build a separate path.

Important nuance:

- `perf stat --bpf-prog` is broader than `bpftool prog profile` in event flexibility.
- `bpftool prog profile` is more BPF-specific in implementation and output.
- Neither tool gives you "why JIT A beat JIT B" beyond aggregate counters.

### 2.3 `BPF_PROG_TEST_RUN`

What it is good for:

- Controlled, repeatable execution in kernel test infrastructure.
- Clean A/B comparison of identical BPF objects.
- Average execution timing over many repeats.

What its timing really is:

- The syscall ABI exposes a 32-bit `duration` field.
- Upstream kernel code computes it with `ktime_get_ns()` and averages over the number of completed repeats.

Limitations:

- Not cycle-accurate.
- Program-type support is incomplete.
- It exercises a test harness path, not full production attach context.
- It has no built-in PMU model.
- It is excellent for controlled benchmarking, but not a complete answer for production attribution.

Answer to the timing-asymmetry question:

- The asymmetry between kernel-side `ktime` and userspace `rdtsc` is **structural in today's public interfaces**, but **not fundamental in principle**.
- It is not a law of nature that kernel BPF must be measured only with `ktime`.
- It is a consequence of the current ABI and portability constraints.
- A new kernel-side profiling interface could expose cycle deltas or better PMU-aligned measurement, but that interface does not currently exist in a standardized public tool.

### 2.4 `bpf_prog_stats` / built-in per-program stats

Kernel UAPI already exposes:

- `run_time_ns`
- `run_cnt`
- `recursion_misses`

and stats are globally enabled through `BPF_ENABLE_STATS` with `BPF_STATS_RUN_TIME`.

What this gives you:

- Per-program cumulative runtime since load.
- Per-program cumulative run count since load.
- Enough to compute average runtime over a sampling interval if you poll deltas.

What it does not give you:

- PMU counters
- distributions
- percentiles
- per-CPU breakdown through the normal public output path
- per-instruction attribution
- phase breakdown
- root-cause analysis

This is the data plane behind tools like `bpftop`, which samples deltas to show average runtime, events/s, and estimated CPU use.

So:

- `bpf_prog_stats` is useful for coarse runtime accounting.
- It is not a microarchitectural profiler.

### 2.5 Public operator tooling: Netflix, Cloudflare, Meta, Google

Closest public tool to "BPF program profiler":

- Netflix `bpftop`: shows average runtime, events/s, and estimated CPU usage per BPF program using `BPF_ENABLE_STATS`.

Adjacent public tooling:

- Cloudflare `ebpf_exporter`: exports custom metrics and traces from user-written eBPF programs. This is observability built with eBPF, not profiling of the eBPF programs themselves.
- Meta `Strobelight`: public material shows eBPF and `bpftrace` being used to profile services and binaries at scale. Again, that is profiling workloads using eBPF, not profiling the performance of eBPF programs as first-class code objects.

What I did **not** find strong public evidence for:

- A public Cloudflare / Meta / Google tool that provides per-BPF-program PMU attribution plus codegen-level explanation.
- A public operator-grade system that unifies kernel BPF JITs and userspace BPF JITs under one microarchitectural methodology.

So the public company landscape is mostly:

- coarse runtime stats for BPF programs
- eBPF-based profilers for other software
- no clear public microarchitectural profiler for the BPF programs themselves

### 2.6 Academic work

The literature I found is mostly in four categories:

1. Optimization systems for eBPF bytecode or runtime.
2. Macro performance studies of eBPF applications and runtimes.
3. Studies of specific eBPF subsystems such as maps.
4. Security / correctness work on the verifier or JIT.

Relevant examples:

- `Demystifying Performance of eBPF Network Applications` (2025): macro application-level performance, chaining, tail-call overhead.
- `No Two Snowflakes Are Alike: Studying eBPF Libraries' Performance, Fidelity and Resource Usage` (2025): runtime/library comparison and fidelity/resource behavior.
- `Understanding Performance of eBPF Maps` (2024): map-focused performance characterization.
- `Towards eBPF Overhead Quantification: An Exemplary Comparison of eBPF and SystemTap` (2025): overhead comparison, not microarchitectural per-program attribution.
- K2, Merlin, and EPSO: optimization systems, but they are not profilers.
- BeeBox and related JIT-security work: security hardening and correctness, not performance explanation tooling.

What I did **not** find:

- A mature academic tool whose primary contribution is per-BPF-program PMU attribution plus automatic codegen-aware explanation.
- A public system that systematically compares emitted native code for BPF JIT backends and then links that to PMU evidence in an automated way.

That gap is real.

## 3. Answers To The Specific Questions In The Prompt

### 3.1 Can you get IPC, cache miss rate, or branch mispredict rate per BPF program execution?

Short answer:

- **Per program, yes.**
- **Per individual execution, not really.**

Details:

- `bpftool prog profile` can provide cycles and instructions, so IPC is possible.
- `perf stat --bpf-prog` can provide more flexible counters, including branch/cache events where supported.
- If you combine PMU totals with a run count over the same interval, you can estimate per-run averages.

But:

- Current public tools do not provide per-invocation distributions.
- They provide aggregate totals over a time window.
- Very short BPF programs are still problematic because PMU windows become sparse and multiplexing noise matters.

### 3.2 Can you attribute PMU events to specific BPF instructions?

Not in a strong first-class way today.

Closest existing path:

- sample native addresses with `perf record`
- dump JITed machine code with `bpftool prog dump jited`
- use `line_info` / `jited_line_info` and disassembly to infer mappings

Why this is still insufficient:

- sampling is not exact per-instruction counting
- skid and multiplexing exist
- native instruction to BPF source mapping is incomplete or indirect
- source-line mapping is weaker than BPF-insn mapping
- no public turnkey tool does this robustly across kernel and userspace BPF JITs

So the honest answer is:

- approximate hotspot attribution at native-address level is possible
- rigorous per-BPF-instruction PMU accounting is still largely unsolved in public tooling

### 3.3 Does JIT dump plus perf annotation work?

Partially.

Kernel BPF:

- `bpftool prog dump jited` works and can show host machine code.
- If line info exists, bpftool can show source lines alongside the JITed dump.
- `bpf_prog_info` exposes JIT-related metadata such as JITed symbols, function lengths, and JITed line info.

Userspace JIT:

- `perf inject --jit` supports the normal jitdump-based workflow for JIT runtimes that emit jitdump data.
- That is the standard path for Java, JS, and other user JITs.

Limitation for BPF:

- Kernel BPF JIT is not a normal jitdump producer.
- Userspace BPF JITs such as llvmbpf would need explicit perf-jitdump or tool-specific integration.
- There is no public seamless workflow that takes a BPF ELF, runs both kernel and userspace JITs, collects PMU samples, and annotates them back to comparable BPF-level structures.

### 3.4 How do Intel VTune and AMD uProf handle JITed BPF code?

Intel VTune:

- VTune has an explicit JIT Profiling API.
- It is designed for JIT engines that report dynamic code before execution.
- Therefore a userspace BPF JIT **could** integrate with VTune if it emits the required JIT metadata.
- Kernel BPF JIT does not naturally fit that path, because the JIT API assumes a userspace JIT engine reporting code objects.

AMD uProf:

- Public AMD documentation emphasizes native applications plus specific managed/runtime cases such as Java via JVMTI.
- Public docs do not suggest a BPF-aware equivalent of VTune's dedicated JIT API.
- So uProf can analyze CPU bottlenecks in general, but I did not find evidence of first-class support for symbolizing kernel eBPF JIT output or generic custom JIT engines in the same way.

Inference:

- For userspace BPF JITs, VTune is more plausible if you add JIT-API support.
- For kernel BPF JITs, neither VTune nor uProf appears to provide a polished BPF-specific source mapping story out of the box.

### 3.5 Can you measure frontend-vs-backend stalls for BPF code?

At coarse program granularity: sometimes yes.

- `perf stat --bpf-prog` can, in principle, use top-down style metrics on supported CPUs.
- VTune and uProf can do top-down / microarchitectural analysis for code regions they can resolve.

But the public BPF-specific gap remains:

- no first-class BPF profiler exposes frontend/backend stall breakdown per BPF program in a BPF-aware report
- no public tool maps stall breakdown to BPF instruction patterns or emitted-code idioms

So the issue is not that the PMU cannot measure these phenomena. The issue is that the BPF tooling stack does not turn them into a convincing BPF-specific explanation.

## 4. Where The Real Gaps Are

### 4.1 Gap 1: Target-isolated PMU that is symmetric across kernel and userspace BPF JITs

Current situation:

- kernel-only public tools exist
- userspace-JIT tooling exists in generic form
- no unified BPF-specific system bridges both

Why it matters:

- this repository already compares identical ELF inputs across kernel and llvmbpf
- that makes it unusually well positioned to become the evaluation bed for a unified profiler

### 4.2 Gap 2: Automatic root-cause explanation

Existing tools stop at "program X has N cycles and M instructions."

What is missing:

- explanation of why the counts differ
- normalization of emitted code across backends
- detection of recurring patterns such as byte recomposition, fixed prologues, branch layout changes, `cmov` use, and dependency-chain shifts

This is where your project already has strong momentum, because the current paper is manually doing exactly this style of reasoning.

### 4.3 Gap 3: Instruction-level or block-level attribution that is BPF-aware

There is enough metadata to get part of the way there:

- JITed dumps
- line info
- JITed line info
- perf samples

But there is not yet a public tool that makes this routine and systematic.

### 4.4 Gap 4: Production-safe low-perturbation measurement

This is still hard because:

- `BPF_ENABLE_STATS` has overhead
- `fentry` / `fexit` based measurement adds instrumentation
- PMU programming is privileged and can perturb short windows
- observer effect matters more for tiny programs than for large user applications

### 4.5 Gap 5: Tail latency and code attribution under load

Most public tools measure averages or sampled hotspots.

They do not solve:

- which part of packet or syscall latency is due to BPF vs surrounding kernel
- how BPF affects tail latency under contention
- how long chains of hooks and tail calls behave under load

## 5. Novelty Assessment Of The Proposed Areas

### 5.1 Unified eBPF microarchitectural profiler across kernel and userspace JITs

Is anyone already doing this?

- Not convincingly in public.
- Pieces exist separately:
  - kernel BPF program PMU profiling
  - generic userspace JIT profiling
  - your repository's cross-runtime benchmarking
- I did not find a public system that unifies them into one BPF-specific methodology.

Prototype difficulty:

- Medium to high.
- Kernel side can build on `perf stat --bpf-prog` or a bpftool-style `fentry/fexit` profiler.
- Userspace side needs perf-jitdump, VTune JIT API, or a custom disassembly + PMU path.
- Address normalization and comparable reporting are the hard parts.

Publishability:

- Medium by itself.
- High if it enables new findings rather than acting as a wrapper around existing counters.

Fit with existing infrastructure:

- Excellent.
- This repo already has matched ELF inputs, timing discipline, JIT dump analysis, and paired benchmarking.

Judgment:

- Strong candidate if framed as "same methodology across kernel and userspace BPF JITs," not just "yet another profiler."

### 5.2 Automated root-cause analysis for why one JIT output is faster

Is anyone already doing this?

- Not in public BPF tooling that I found.
- Existing work does manual explanation, not automated explanation.

Prototype difficulty:

- Medium.
- The hard part is not PMU collection. The hard part is code alignment and explanation quality.
- You need semantic diffing of emitted code, not just textual diff.

Publishability:

- High.
- This is the cleanest "genuinely new" story in the list.
- It also aligns well with measurement and compiler-analysis venues.

Fit with existing infrastructure:

- Excellent.
- Your current paper already contains manually extracted explanation patterns.
- Those patterns can become the rule set or learned model for an automated explainer.

Judgment:

- Best novelty target in the entire list.

### 5.3 BPF-aware differential JIT analysis tool

Is anyone already doing this?

- Not as a dedicated public tool, as far as I could find.
- Existing practice is ad hoc: disassemble, compare, reason manually.

Prototype difficulty:

- Medium.
- Easier than a full profiler because it can start from offline dumps.

Publishability:

- Medium alone.
- High when coupled with validated performance explanations.

Fit with existing infrastructure:

- Excellent.
- You already have code-size analysis, JIT dumps, and identified recurring patterns.

Judgment:

- Very good as a core subsystem.
- Slightly weaker if pitched alone without strong measured outcomes.

### 5.4 LLVM `-mllvm -stats` integration with BPF-specific metrics

Is anyone already doing this?

- LLVM already has generic stats and pass remarks.
- Your repository already has pass-ablation hooks.

Prototype difficulty:

- Low to medium.

Publishability:

- Low by itself.
- It is useful supporting evidence, not a main contribution.

Fit with existing infrastructure:

- Good.

Judgment:

- Incremental.
- Worth doing as instrumentation, not as the headline.

### 5.5 Cycle-accurate or near-cycle simulation of emitted BPF JIT code with `llvm-mca` or uiCA

Is anyone already doing this for BPF?

- I did not find a public BPF-specific pipeline.
- But the underlying simulators are well known, so the novelty is in the integration and validation.

Prototype difficulty:

- Medium.
- Straight-line kernels are feasible.
- Memory-heavy kernels, helper calls, and branch-heavy programs are much harder to model faithfully.

Publishability:

- Medium.
- Higher if the simulator is validated against measured deltas and used to explain cases where PMU data is too sparse.

Fit with existing infrastructure:

- Good.
- The repo already emits or can dump machine code to feed such tools.

Judgment:

- Promising as an auxiliary explanation engine.
- Not strong enough alone unless validation is very convincing.

### 5.6 Per-instruction static cost model for BPF programs

Is anyone already doing this?

- There is extensive static analysis around verifier safety and bytecode optimization.
- I did not find a convincing public static runtime predictor for JITed BPF performance at this level.

Prototype difficulty:

- High.
- Your own current static-feature model already shows weak predictive power.
- Real runtime depends on JIT backend, emitted code shape, memory behavior, branch prediction, helper cost, and workload context.

Publishability:

- High if it works.
- High risk because it may not work well enough.

Fit with existing infrastructure:

- Partial.
- The repo has benchmark data for training and testing.
- But broader generalization will likely require much more corpus diversity.

Judgment:

- High-risk / high-reward.
- Better as a long-term research direction than the first prototype.

### 5.7 Spectre mitigation overhead measurement

Is anyone already doing this?

- There is broader literature on retpolines and mitigation overhead.
- I did not find a strong BPF-specific empirical study isolating the "security tax" on BPF JIT execution quality.

Prototype difficulty:

- Medium.
- Requires careful kernel configuration, mitigation toggles, and possibly reboot-based experiments.

Publishability:

- Medium.
- Good paper section or secondary contribution.
- Probably not enough as the primary novelty unless the effect is surprisingly large or architecture-specific.

Fit with existing infrastructure:

- Good.
- The repo already identified this as a planned 2x2 factor.

Judgment:

- Useful and publishable as a component.
- Probably incremental as the main story.

## 6. What Is Hard Or Still Unsolved

### 6.1 Low-perturbation production measurement

This is hard for BPF because the programs are often tiny.

- A few added instructions matter.
- Stats gathering is disabled by default for overhead reasons.
- Instrumentation around each invocation can dominate the signal for very short programs.

So "production-safe per-program microarchitecture" is still unsolved in a strong sense.

### 6.2 Separating BPF cost from surrounding kernel cost

This is one of the hardest methodological issues.

- `BPF_PROG_TEST_RUN` isolates the program, but not production context.
- perf around a whole kernel path sees too much.
- fentry/fexit isolates the target program better, but still only yields aggregate counters.

A publishable tool must be explicit about which boundary it draws.

### 6.3 Cross-architecture comparison

This is hard because:

- x86 and arm64 BPF JIT backends differ
- PMU event names and semantics differ
- top-down methodologies are not identical
- userspace JIT support and code quality may vary

This is feasible, but it is a separate expansion axis, not a free extension.

### 6.4 Tail latency under load

This is much harder than average microbenchmark timing.

- You need traffic generation or realistic request load.
- You need hook-chain context.
- You need queueing-sensitive measurement.
- You need attribution across BPF and non-BPF code.

This is likely beyond the first prototype unless the scope is narrowed sharply.

## 7. What Looks Genuinely Novel vs Merely Incremental

### Genuinely novel or close to it

1. **Automated differential JIT explanation**
2. **Unified kernel/userspace BPF microarchitectural profiling**
3. **BPF-aware native-code diff plus measured validation**
4. **Validated simulation-assisted explanation of emitted BPF JIT code**

### Publishable, but narrower or secondary

1. **Spectre mitigation tax measurement**
2. **Cross-architecture BPF JIT quality comparison**
3. **Production-oriented low-overhead runtime stats tooling**

### Mostly incremental

1. **A prettier wrapper over `bpftool prog profile` or `perf stat --bpf-prog`**
2. **LLVM stats integration without deeper insight**
3. **Dashboarding `bpf_prog_stats`**

## 8. Best Research Direction For This Repository

The best fit is:

### Recommended headline

"A BPF-aware differential microarchitectural explainer for JIT backends."

### Why this is the best fit

- It leverages the repository's strongest asset: identical ELF inputs across kernel and llvmbpf.
- It builds on work the repository already started: manual explanation of byte recomposition, `cmov`, prologue tax, dependency chains, and branch effects.
- It avoids competing directly with existing tools on raw counter collection.
- It can incorporate PMU evidence, but does not depend on PMU alone.

### Minimum viable publishable prototype

1. Use the existing benchmark harness and JIT dump pipeline.
2. Add target-isolated kernel PMU collection using either:
   - `perf stat --bpf-prog`, or
   - a bpftool-style `fentry/fexit` profiler.
3. Add userspace-JIT PMU collection plus symbolized dump export.
4. Build a differential analyzer that:
   - aligns native blocks
   - detects pattern classes
   - estimates likely root-cause categories
   - correlates them with timing and PMU deltas
5. Validate on both microbenchmarks and a real-program subset.

### Stronger second step

Add `llvm-mca` or similar analysis as a sidecar explanation engine for:

- sparse PMU cases
- dependency-chain reasoning
- "smaller but slower" paradox cases

## 9. Final Assessment

If the goal is a strong systems or measurement contribution, the novelty is **not** in showing that BPF programs can be timed or that PMU counters exist. Those facts are already public.

The novelty is in building a system that:

- works across kernel and userspace BPF JITs
- isolates the target code well enough to trust the counters
- links emitted machine-code differences to measured performance
- automatically explains why one backend wins

That remains meaningfully open.

For this repository, I would rank the directions as follows:

1. **Automated root-cause analysis plus BPF-aware differential JIT analysis**
2. **Unified microarchitectural profiler across kernel and userspace runtimes**
3. **Simulation-assisted explanation**
4. **Spectre tax measurement as a secondary contribution**
5. **LLVM stats integration as supporting instrumentation**
6. **Static per-instruction cost model as long-term, high-risk work**

In short:

- **Strong novelty:** explanation, unification, differential analysis
- **Moderate novelty:** simulation and mitigation studies
- **Weak novelty:** wrappers around existing stats and PMU interfaces

## References

- Local project files:
  - `micro/runner/src/main.cpp`
  - `micro/runner/src/kernel_runner.cpp`
  - `micro/runner/src/llvmbpf_runner.cpp`
  - `micro/runner/src/perf_counters.cpp`
  - `micro/run_micro.py`
  - `docs/paper.md`
  - `docs/micro-bench-status.md`

- Upstream / public sources:
  - Linux `BPF_PROG_TEST_RUN`, `BPF_ENABLE_STATS`, and `bpf_prog_info` UAPI:
    - https://elixir.bootlin.com/linux/latest/source/include/uapi/linux/bpf.h
    - https://elixir.bootlin.com/linux/latest/source/net/bpf/test_run.c
  - `bpftool prog` documentation:
    - https://manpages.debian.org/unstable/bpftool/bpftool-prog.8.en.html
  - `bpftool` source for `prog profile`:
    - https://github.com/libbpf/bpftool
  - `perf stat` manual (`--bpf-prog`):
    - https://man7.org/linux/man-pages/man1/perf-stat.1.html
  - `perf inject` manual (`--jit` / jitdump):
    - https://man7.org/linux/man-pages/man1/perf-inject.1.html
  - Netflix `bpftop`:
    - https://github.com/Netflix/bpftop
  - Cloudflare `ebpf_exporter`:
    - https://github.com/cloudflare/ebpf_exporter
  - Meta Strobelight:
    - https://engineering.fb.com/2025/01/21/production-engineering/strobelight-a-profiling-service-built-on-open-source-technology/
  - Intel VTune JIT Profiling API:
    - https://www.intel.com/content/www/us/en/docs/vtune-profiler/user-guide/current/jit-profiling-api.html
  - AMD uProf:
    - https://www.amd.com/en/developer/uprof.html
    - https://www.amd.com/content/dam/amd/en/documents/developer/uprof-v4.0-gaGA-user-guide.pdf
  - Paper metadata:
    - https://doi.org/10.1145/3749216
    - https://doi.org/10.1145/3748355.3748364
    - https://doi.org/10.1145/3672197.3673430
    - https://doi.org/10.1145/3680256.3721311
