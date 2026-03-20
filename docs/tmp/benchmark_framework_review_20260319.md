# Benchmark Framework Review (2026-03-19)

## Executive Summary

- The current framework is good enough to support the **micro kernel vs kernel-recompile applied-only** headline, but it is **not** good enough to support the current **corpus overall** topline, and it cannot support any **pre-2026-03-19 llvmbpf exec-time** headline after the batch-timing fix.
- The main paper metric should be **applied-only net speedup**. Non-applied rows should be treated as a **neutrality / harness-quality diagnostic**, not mixed into the primary geomean.
- The corpus non-applied collapse is **not evidence that no-op recompile changes code**. In the current `vm-corpus` flow, stock and recompile are measured in the same guest boot, but they are still separate fresh loads with fixed stock-first / recompile-second ordering and only one measured sample per lane.
- The exact **0.609x characterization gap** is now stale. Any metric derived from that denominator, especially a claimed “gap recovery percentage,” is stale too.

---

## Question 1: What Data Does the Paper Actually Need?

### What the project plan says the paper must show

`docs/kernel-jit-optimization-plan.md` is clear about the current thesis:

1. There is a real **kernel JIT code-quality gap** worth recovering.
2. BpfReJIT yields **net speedup** on real programs.
3. That speedup requires **policy control**, not a fixed heuristic.
4. The evaluation includes **real programs** and **at least one real end-to-end deployment**.

That means the minimum credible bundle is smaller than the framework’s full output surface.

### Minimum authoritative data points

| Needed for paper | Benchmark | Comparison | Minimum authoritative parameters | Notes |
| --- | --- | --- | --- | --- |
| Characterization gap exists | Pure-JIT micro suite covering the families BpfReJIT targets | `llvmbpf / kernel` exec ratio | Strict rerun with **batch-timed llvmbpf**, counterbalanced order, `30 iterations x 1000 repeats`, strict env | This is the denominator for the “why backend optimization matters” argument. |
| Policy sensitivity exists | At least one bidirectional pair, e.g. CMOV helps one branch regime and hurts another; ideally also one selective-vs-fixed LEA example | Same transform under two workloads, or `fixed heuristic` vs `selective re-JIT` | Same micro config as above or same VM micro config as kernel-recompile | This is the evidence that a fixed kernel heuristic is insufficient. |
| Controlled BpfReJIT benefit | `vm-micro` applied benchmarks | `kernel / kernel-recompile` | Current style is close: `5 warmups x 10 iterations x 1000 repeats` | The primary micro headline should be **applied-only**, not all 62. |
| Real-program benefit below E2E | Corpus applied programs on exercised paths | `kernel / kernel-recompile` | Needs repeated paired samples or same-loaded-program before/after measurement; current single-sample `repeat=200` is not enough for a primary topline | This is where the current framework is weakest. |
| Real-program benefit at deployment level | Tracee and/or Tetragon live deployments | Before/after recompile on the **same loaded live programs** | Current durations are plausible (`Tracee 60s`, `Tetragon 30s`), but repeated phases would strengthen them | At least one strong E2E case is mandatory; two is safer. |
| Safety / compatibility | Production object corpus | Load / attach / recompile success; xlated identity; no result change | Same kernel build, same policy set | This is separate from performance and should not be confused with it. |

### Data that is secondary or redundant

These can be kept for debugging, appendix material, or historical context, but they are not minimum paper-critical datapoints:

- **Overall micro geomean including non-applied benchmarks.**
  - Useful only as a secondary summary once non-applied neutrality is shown.
- **Overall corpus geomean including non-applied rows.**
  - In the current framework this is actively misleading.
- **Non-applied per-program ratios** as a main result.
  - They are harness diagnostics, not optimization effect.
- **`wall_exec_ns`** in cross-runtime micro comparisons.
  - Good for dispatch overhead inspection, not for the main claim.
- **Corpus `compile_ns`** as a primary performance metric.
  - The paper thesis is steady-state net speedup, not one-time compile cost.
- **Corpus by-family geomeans** as a headline.
  - Families overlap heavily; these rows are not isolated causal effects.
- **Historical llvmbpf real-world exec-time corpus results**.
  - They are now both methodologically stale and no longer aligned with the paper’s kernel-vs-kernel-recompile direction.
- **Gap-recovery percentage** as a primary metric.
  - It couples a kernel-vs-recompile numerator to a separate llvmbpf characterization denominator that just changed.

### Bottom line for Q1

The paper does **not** need “every metric the harness can compute.” It needs:

1. One clean characterization gap measurement.
2. One clean policy-sensitivity demonstration.
3. One clean controlled micro applied-only improvement result.
4. One clean real-program result below E2E.
5. One or two clean same-session E2E case studies.
6. One clean compatibility/safety result.

Everything else is support material.

---

## Question 2: Non-Applied Corpus Noise

### Why are non-applied ratios far from 1.0x if code did not change?

Because the current corpus framework does **not** compare the same loaded image before and after recompile.

In `corpus/_driver_impl_run_corpus_v5_vm_batch.py`, each target is processed in this order inside one guest boot:

1. baseline compile-only
2. v5 compile-only
3. baseline run
4. v5 run

See `run_target_locally()` at `corpus/_driver_impl_run_corpus_v5_vm_batch.py:521-620`, and the summary note at `1257-1264`.

For the two run lanes, each measurement is a separate `micro_exec run-kernel` process, and each process performs a fresh:

- `bpf_object__open_file()`
- `bpf_object__load()`
- JIT image allocation / publication
- `bpf_prog_test_run_opts()`

See `micro/runner/src/kernel_runner.cpp:943-987`.

So even when stock and “recompile” emit identical code bytes, they are **not measuring the same loaded program image**. They can differ because of:

- different JIT image addresses
- different module-memory allocation state
- different instruction alignment / layout
- fixed stock-first / v5-second ordering
- only one measured sample per lane

That is enough to move very short kernels far away from 1.0x.

### Does the kernel recompile path mutate non-applied programs?

Usually, **no** in the common corpus policy-file path.

In `micro/runner/src/kernel_runner.cpp:1203-1234`, if policy filtering leaves `selected_rules.rules.empty()`, userspace never builds `policy_data`. Then at `1248-1295`, no `BPF_PROG_JIT_RECOMPILE` syscall is attempted at all.

So for the common “no sites” or “policy selected zero rules” case, the program only goes through:

- normal stock load/JIT
- normal `bpf_prog_test_run_opts()`

### If the kernel does get a no-op recompile request, what happens?

There is a narrower case where userspace does call `BPF_PROG_JIT_RECOMPILE`, but the kernel ends up applying zero rules.

In that case:

- the kernel snapshots the current program state (`jit_directives.c:658-664`)
- performs staged re-JIT work (`jit_directives.c:297-419`)
- allocates temporary JIT staging state / image memory (`arch/x86/net/bpf_jit_comp.c:5617-5798`)
- then aborts and restores the old live image (`jit_directives.c:704-709`, `524-533`; `bpf_jit_comp.c:5879-5899`)

Important negative result:

- I did **not** find an explicit TLB flush in this path.
- I did **not** find a live-image replacement when `jit_recompile_num_applied == 0`.
- The commit path with `synchronize_rcu()` is only on the real commit path (`jit_directives.c:468-521`).

So the no-op kernel path can do **temporary allocations and staged JIT work**, but it does **not** publish a new image when nothing applied.

### Are stock and recompile measured in the same VM boot?

For the current `make vm-corpus` path, **yes**.

`run_target_in_guest()` launches one `vng --run ... --exec ...` per target (`corpus/_driver_impl_run_corpus_v5_vm_batch.py:752-823`), and inside that one guest boot, `run_target_locally()` runs both stock and recompile lanes (`521-620`).

So the answer is:

- **same boot for stock vs recompile within a target**
- **different boots across different targets**

### Is the noise from VM layout randomization between boots?

Not primarily.

Because stock and recompile for the same target are already in the **same guest boot**, the main culprit is not “different boot randomization.”

The stronger explanation is:

- **within-boot per-load layout drift**
- **fixed order bias** (`baseline_run` always before `v5_run`)
- **single-sample measurement**

The fact that the non-applied population is not just noisy but often biased below `1.0x` is consistent with a systematic order / allocator-state effect, not just symmetric random jitter.

### Should non-applied programs be excluded from corpus reporting?

For **primary paper reporting**, yes.

Recommendation:

- Use **applied-only** rows for the primary corpus speedup headline.
- Keep **non-applied** rows only as a **neutrality diagnostic**.
- Require that non-applied geomean be close to `1.0x` before trusting any “overall” corpus number.

The current corpus overall metric mixes:

- real optimization signal from applied rows
- no-op / layout noise from non-applied rows

That mix is not meaningful for a performance-effect claim.

---

## Question 3: Impact of the Timing Fix on Existing Data

### What does `simple` 11ns -> 4ns mean for the 0.609x characterization gap?

It means the exact **0.609x** number is no longer trustworthy.

The old llvmbpf runner timed each `vm.exec()` inside the repeat loop. The new code correctly times one batch around the whole repeat loop and divides by `repeat` (`micro/runner/src/llvmbpf_runner.cpp:759-772`, `880-893`).

That old method inflated llvmbpf exec time on short benchmarks. Therefore:

- the old llvmbpf/kernel gap number is **stale**
- the old gap is likely **too pessimistic to llvmbpf**
- the qualitative claim “there is a substantial gap” probably survives
- the exact ratio and any derived “gap recovery” percentage do **not**

If llvmbpf got materially faster after correct timing, then the original kernel-vs-llvmbpf gap was probably **larger** than 0.609x implied. That also means any previously quoted “BpfReJIT recovers X% of the gap” is stale and likely optimistic in denominator terms.

### Which datasets need to be re-measured?

#### Must re-measure

- **All llvmbpf exec-time characterization datasets**
  - `pure_jit_authoritative*.json`
  - `pure_jit_authoritative_strict_20260312.json`
  - `runtime_authoritative.json`
  - `new_runtime_authoritative.json`
  - any host/VM overlap or combined llvmbpf exec summaries derived from them
- **All llvmbpf exec-time causal / ablation datasets**
  - `causal_isolation_authoritative.json`
  - pass-ablation / no-cmov / similar llvmbpf exec studies if cited
- **All derived analysis docs / tables / figures that use llvmbpf exec ratios**
  - `docs/micro-bench-status.md`
  - `docs/paper-comparison.md`
  - `docs/paper/paper.tex`
  - `micro/results/archive/pure_jit_authoritative_analysis.md`
  - `runtime_authoritative_analysis.md`
  - `performance_deep_analysis.md`
  - `paradox_analysis.md`
  - characterization-gap decomposition notes
- **Any ARM64 llvmbpf exec baseline collected before the fix**
  - the same timing bug is architecture-independent

#### Also re-measure the narrower kernel-side subset affected by the context-repeat fix

The 2026-03-19 timing fix also changed kernel context-mode repeat behavior so that batching is enabled for:

- `BPF_PROG_TYPE_SK_LOOKUP`
- `BPF_PROG_TYPE_NETFILTER`

See `micro/runner/src/kernel_runner.cpp:305-314`, `1425-1436`.

So any older kernel-side datasets involving those program types are also stale.

### What can be salvaged?

#### Safe to salvage

- **Code-size** data
- **Compile-time** data
- **JIT dump / disassembly** analysis
- **Static coverage / representativeness / site census** data
- **Kernel vs kernel-recompile micro** results, except the narrow pre-fix context-type subset above
- **Kernel vs kernel-recompile corpus** results, methodology caveats aside
- **E2E before/after recompile** results
- **Compatibility / success-count** data

#### Not safe to keep as authoritative numeric evidence

- any llvmbpf **exec_ns**
- any llvmbpf/kernel **geomean**
- any llvmbpf-based **CI / p-value / effect-size**
- any **gap recovery percentage** that depends on the stale llvmbpf denominator

### Bottom line for Q3

- The old exact characterization numbers are **invalid as authoritative data**.
- The main narrative “the kernel JIT leaves meaningful headroom” probably still holds.
- The easiest salvage strategy is:
  - keep code-size / compile-time / disassembly
  - re-measure all llvmbpf exec-time data
  - stop using gap-recovery percentage as a primary metric

---

## Question 4: Is the Benchmark Framework Producing the Right Metrics?

### Metrics that are worth keeping

| Metric | Keep? | Role |
| --- | --- | --- |
| Micro applied-only geomean (`kernel / recompile`) | Yes, primary | Best controlled measure of BpfReJIT effect |
| Micro non-applied geomean | Yes, QC | Harness neutrality check |
| Micro overall geomean | Secondary only | Only meaningful if non-applied is demonstrably neutral |
| Corpus applied-only geomean | Yes, primary for corpus | Best real-program aggregate that actually reflects optimization effect |
| E2E throughput delta on same live programs | Yes, primary for deployment evidence | What the paper actually cares about |
| E2E BPF avg ns/run | Yes, secondary | Mechanistic support, not user-facing outcome |
| Compatibility / applied-count / site-count metrics | Yes | Shows coverage and feasibility |

### Metrics that the framework computes but the paper does not really need

- **Corpus overall exec geomean including non-applied rows**
  - currently misleading
- **Per-project corpus geomeans including non-applied rows**
  - current project-level collapses mostly reflect the same no-op noise
- **Corpus by-family geomeans**
  - families overlap; not isolated effects
- **`wall_exec_ns`** as a cross-runtime headline
  - useful for debugging, not for paper claims
- **Corpus / E2E compile-time summaries**
  - not central to the steady-state performance thesis
- **Gap recovery percentage**
  - too coupled to a separate characterization denominator

### Metrics the framework needs but is not computing cleanly enough

- **Applied-only summaries as first-class framework outputs**
  - today this is often reconstructed in ad hoc docs, not emitted as the main summary
- **No-op neutrality gates**
  - example: non-applied geomean, fraction of non-applied rows within ±5% / ±10% of 1.0x
- **A clean split of non-applied reasons**
  - zero-site
  - policy-filtered-to-zero
  - kernel-requested-but-no-rule-applied
  - syscall failure
- **Repeated paired samples for corpus**
  - current `vm-corpus` uses one measured sample per lane
- **Order metadata / counterbalancing for corpus**
  - current order is fixed and biased
- **Path-hit evidence for corpus**
  - the framework still does not directly measure “the optimized site executed on the measured path”

### Is the overall geomean including non-applied meaningful?

For the current paper goal, **no**.

It is only meaningful if the non-applied population is acting like a neutral control and staying very close to `1.0x`.

That is approximately true in the best micro reruns:

- 2026-03-18 micro non-applied geomean: about `1.002x`
- 2026-03-19 post-simplification micro non-applied geomean: about `0.987x`

But it is very much **not** true in current corpus:

- post-simplification corpus non-applied geomean: `0.684x`

So the overall corpus geomean is not measuring “optimization effect on the corpus.” It is measuring “optimization effect plus no-op layout/order noise.”

### Should reporting switch to applied-only everywhere?

For **primary performance reporting**, yes.

Recommended policy:

- **Micro:** applied-only primary; non-applied neutrality as QC; overall secondary.
- **Corpus:** applied-only primary; non-applied separate diagnostic; overall demoted or removed.
- **E2E:** only cases with actual applied programs should be used for performance claims.
- **Compatibility / safety:** not applied-only, because those questions are about coverage, not effect size.

---

## Question 5: Measurement Methodology Review

### A. Micro kernel

#### Is `opts.repeat` sufficient?

Mostly **yes** for the current packet-backed / map-backed micro methodology.

`execute_kernel_test_run()` uses one `bpf_prog_test_run_opts()` call and reads `test_opts->duration` as the average per execution (`micro/runner/src/kernel_runner.cpp:266-303`). That is the right timing path.

For the current authoritative micro config, explicit `REPEAT=1000` is already high enough that timer quantization is largely controlled on the benchmarks that matter.

#### Important caveat

Context-mode batching is still not universal.

The runner only enables kernel-side repeat for:

- `SK_LOOKUP`
- `NETFILTER`

See `kernel_runner.cpp:305-314`.

Unsupported context paths force `repeat=0` / single execution (`1425-1436`). Those paths are still methodologically weaker.

#### Are warmups done right?

Not quite.

There are two warmup layers:

1. The Python micro driver reruns the whole command for `warmups` iterations (`micro/_driver_impl_run_micro.py:547-548`).
2. The kernel runner does an **internal same-image warmup** only if `recompile.applied` is true (`kernel_runner.cpp:1471-1475`).

That means:

- stock kernel does **not** get same-image internal warmups
- non-applied recompile rows do **not** get same-image internal warmups
- only applied recompile rows do

So the internal warmup policy is asymmetric and should be fixed. The driver-level warmups help the environment, but they do **not** warm the exact loaded image that will be measured next, because each measured sample is a fresh process and fresh load.

#### Verdict

- `repeat`: good enough for current authoritative packet-backed micro
- warmups: directionally okay, but **not symmetric** and therefore not ideal

### B. Micro llvmbpf

#### Is the new batch timing correct?

Yes. This is the right fix.

The new runner wraps one timer around the full repeat loop (`llvmbpf_runner.cpp:759-772`) and divides the batch cost by `repeat` (`880-893`).

That matches what `repeat` is supposed to mean.

#### Remaining issues

- All older llvmbpf exec-time data is stale.
- Cross-runtime timing symmetry is still imperfect:
  - kernel uses `bpf_prog_test_run`’s internal duration
  - llvmbpf uses user-space TSC timing
- There is still no equivalent same-image internal warmup in llvmbpf.

#### Verdict

- The new timing path is correct.
- The old llvmbpf datasets must be discarded or remeasured.

### C. Corpus (with llvmbpf removed)

#### Is the kernel vs kernel-recompile methodology conceptually sound?

It is **much sounder than the old llvmbpf corpus**, because both lanes now use the same kernel runner and same timing source.

But it is **not yet paper-grade** for a full-suite performance topline.

#### Main problems

1. **Separate fresh loads, not same-image before/after**
   - `run_target_locally()` runs baseline and v5 as separate `micro_exec` invocations (`corpus/_driver_impl_run_corpus_v5_vm_batch.py:521-620`).
2. **Fixed ordering**
   - baseline always before v5; no counterbalancing.
3. **One measured sample per lane**
   - no median / CI / robustness.
4. **No primary path-hit proof**
   - the framework still does not directly show that the optimized site executed on the measured path.
5. **Non-applied rows dominate the aggregate**
   - which means the current overall geomean is mostly a harness metric, not an optimization metric.

#### Verdict

- **Applied-only corpus**: usable as exploratory evidence
- **Overall corpus topline**: not reliable enough
- **Best next fix**: measure stock and recompile on the **same loaded program** in one runner invocation, before/after live `BPF_PROG_JIT_RECOMPILE`, and collect repeated paired samples

### D. E2E

#### Tracee

Best current properties:

- same long-lived live session
- same loaded programs before and after recompile
- BPF runtime deltas plus workload throughput

See `e2e/cases/tracee/case.py:805-845`.

Weakness:

- only one baseline phase and one post phase per workload
- no repeated paired runs / CI

Verdict:

- good **case-study evidence**
- not as statistically strong as the micro result

#### Tetragon

Very similar to Tracee:

- same live session
- same loaded programs
- before/after recompile on the same agent

See `e2e/cases/tetragon/case.py:1099-1149`.

Weakness:

- same single-phase issue

Verdict:

- also good **case-study evidence**

#### Katran

Structurally, this is actually strong:

- same live session
- path validation (HTTP success + IPIP decap packets + BPF events)
- repeated internal sample loop support

See `e2e/cases/katran/case.py:1037-1081`, `1170-1194`.

But the default `sample_count` is only `1` (`katran/case.py:65`, `1100`).

Verdict:

- good structure
- under-sampled by default
- increase `sample_count` before treating it as primary evidence

#### bpftrace

Methodologically weak for before/after performance claims.

Baseline and rejit phases start **separate bpftrace processes** and therefore attach **different live programs** (`e2e/cases/bpftrace/case.py:426-547`, `771-815`).

Verdict:

- okay for exploratory script-level compatibility
- **not** good as a primary before/after performance result

#### scx

Weak for BPF performance attribution.

The harness itself notes that `bpftool` often does not expose `run_cnt` / `run_time_ns` for these `struct_ops` programs (`e2e/cases/scx/case.py:757-764`).

Verdict:

- use as compatibility / smoke
- do not use as primary performance evidence

---

## Recommended Reporting Policy

### What I would treat as paper-authoritative today

- **Micro kernel vs kernel-recompile applied-only**
  - yes
- **Tracee / Tetragon same-session E2E**
  - yes, as case studies
- **Compatibility / success-count / xlated-identity data**
  - yes

### What I would not treat as paper-authoritative today

- **Corpus overall geomean including non-applied**
  - no
- **Any old llvmbpf exec-time number**
  - no
- **bpftrace or scx performance toplines**
  - no

### Concrete next steps

1. Re-measure all llvmbpf exec-time characterization datasets with the new batch timing.
2. Make **applied-only** the primary metric everywhere performance is reported.
3. Add a **non-applied neutrality gate** to framework summaries.
4. Rework corpus to compare **same loaded program before/after live recompile** and take repeated paired samples.
5. Make internal same-image warmups symmetric between stock and recompile lanes in the kernel runner.
6. Keep Tracee and Tetragon as the primary E2E deployment cases; increase Katran sampling before using it as a main result.

## Final Bottom Line

- The biggest current data-quality problem is **not** the kernel recompile path mutating no-op programs.
- It is the **benchmark methodology around no-op corpus rows**: separate fresh loads, fixed order, one sample, and inclusion of non-applied rows in the topline.
- The biggest current publication-readiness problem is **not** the micro kernel-recompile result.
- It is the combination of:
  - stale llvmbpf exec-time characterization data
  - an untrustworthy corpus overall metric
  - E2E results that are good case studies but still lightly sampled

That means the clean path forward is:

- keep the current micro kernel-recompile result
- remeasure llvmbpf exec characterization
- switch corpus reporting to applied-only and/or fix the measurement design
- use Tracee/Tetragon as the real deployment evidence
