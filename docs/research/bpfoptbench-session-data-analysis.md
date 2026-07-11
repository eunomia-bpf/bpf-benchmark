# BPFOptBench Existing Data and Session Analysis

Last updated: 2026-06-22

This note analyzes the data already present in this repository and the local
agent/session logs that are relevant to the BPFOptBench idea. The goal is not
to claim that agents already optimize eBPF programs. The goal is to decide what
the current evidence can support, how to adjust the research questions, and
what experiments should be run next.

This is an analysis-side document. It does not imply any framework-side
aggregation or summary logic.

## Executive Conclusion

BPFOptBench is a plausible and distinct eBPF workshop paper, but the strongest
current framing is:

> BPFOptBench is a benchmark and evaluator for closed-loop agent tuning of
> existing eBPF programs under real verifier, JIT, application, and workload
> feedback.

The current evidence supports three claims well:

1. eBPF optimization is hard to evaluate because verifier acceptance, bytecode
   rewrite counts, JIT size deltas, workload stability, and runtime counters do
   not agree automatically.
2. The repository already contains a realistic execution substrate: real app
   startup, app-level loaders, v3 raw result schema, six supported macro apps,
   and historical pass-policy data.
3. Historical agent sessions are useful as a task-mining source: they expose
   realistic debugging, policy-selection, result-interpretation, and
   benchmark-integrity tasks.

The current evidence does not yet support these stronger claims:

1. Agents can reliably improve existing eBPF programs.
2. Structured feedback improves eBPF optimization success.
3. A leaderboard can rank agents reproducibly on live performance tasks.

Those claims require a frozen task set, hidden evaluator, current no-op/noop
floor measurements, and agent-vs-baseline runs.

## Data Sources

The analysis used five local sources:

| Source | What It Provides | Main Limitation |
|---|---|---|
| `corpus/results/*/details/result.json` | Historical and current benchmark artifacts. | Mixed legacy/v3 schemas; older artifacts include summaries that are no longer allowed in framework code. |
| `docs/tmp/*.md` and `docs/tmp/active/*.md` | Human analysis of pass signal, policy iteration, and corpus stability. | Post-hoc notes, not a frozen benchmark dataset. |
| `~/.codex/history.jsonl` and `~/.codex/session_index.jsonl` | Local prompt/session history related to this repo and adjacent eBPF agent work. | Useful for task taxonomy, not scored outcomes. Raw prompts should not be quoted into a public artifact. |
| `~/.agentsight/monitor/monitor-2026-W25.db` | Current-week agent process monitor metadata. | No direct `bpf-benchmark`/`bpfopt`/`rejit`/`kop` cwd or command matches in the tracked sessions. |
| BPFix/verifier-repair data from the adjacent verifier-agent project | Evidence that structured verifier feedback can help repair tasks. | It is a different benchmark problem; it should be cited only as methodological precedent. |

## Corpus Artifact Inventory

Scanning `corpus/results/*/details/result.json` found:

| Item | Count |
|---|---:|
| `details/result.json` files | 1535 |
| raw-only v3-style results | 799 |
| legacy or mixed-schema results | 736 |
| `status=ok` | 938 |
| `status=error` | 588 |
| `status=unknown` | 9 |

The largest artifact groups are:

| Prefix | Count |
|---|---:|
| `x86_kvm` | 1320 |
| `aws_arm64` | 134 |
| `arm64_qemu` | 57 |
| `aws_x86` | 10 |
| `vm_corpus` | 9 |

The latest inspected x86 v3 run is:

`corpus/results/x86_kvm_corpus_20260622_190658_322856/details/result.json`

Key facts:

| Field | Value |
|---|---|
| generated | `2026-06-22T19:12:58.569139+00:00` |
| status | `ok` |
| suite | `macro_apps` |
| samples | `1` |
| workload seconds | `5.0` |
| schema | raw-only v3 |
| app payloads | `bcc/set`, `cilium/agent`, `katran`, `otelcol-ebpf-profiler/profiling`, `tetragon/observer`, `tracee/monitor` |
| ReJIT mode | `native_loader` |
| enabled passes | empty list for all six apps |

Interpretation: this run is good substrate evidence. It shows the current
six-app runner and raw schema can produce complete v3 app payloads. It is not
optimization evidence because no pass was enabled.

## Historical Performance Evidence

The strongest existing performance evidence is not "optimizer wins"; it is
"the problem is difficult enough to justify a benchmark."

### Noop And ReJIT Floors

`docs/tmp/pass_signal_audit_20260508.md` records completed no-op and
skip-ReJIT floor measurements:

| Run | Retained Programs | Method B Ratio | W/L/T | Interpretation |
|---|---:|---:|---|---|
| noop ReJIT floor, `x86_kvm_corpus_20260507_190554_205137` | 147 | 0.9019 | 73/74/0 | ReJIT/noop path itself has large apparent movement. |
| noop SKIP_REJIT floor, `x86_kvm_corpus_20260508_000244_131324` | 147 | 0.8587 | 75/72/0 | Even no-ReJIT comparison has a large floor. |

The recorded suite-noise amplitude is about `0.0431`. Per-app noise is uneven:
`bcc/set` and `cilium` are tight, while `otel` and `tetragon` are much wider.

This is important for BPFOptBench because an agent can easily chase noise unless
the evaluator requires no-op floors, run-count filters, and hidden validity
checks.

### Pass Signal Audit

The same audit reports:

1. No standalone pass had paper-ready measurable improvement in completed runs.
2. Earlier `map_inline` on OTEL showed a strong low ratio in one 7-app run, but
   the result was not reproduced in a named follow-up run.
3. Combined kop runs had strong OTEL-looking numbers, but single-pass
   attribution did not isolate the cause.
4. Several passes had large applied counts but no reliable speedup signal.

This supports a benchmark contribution: the evaluator must separate verifier
success, rewrite applicability, JIT/code-size changes, workload success, and
performance improvement.

### Corpus-Wide Flat Result

`docs/tmp/corpus-performance-analysis-20260428.md` records a cleaner full-corpus
run:

| Metric | Value |
|---|---:|
| comparable programs | 146 |
| geomean post/base | 1.003828 |
| wins/losses | 81/65 |
| app status | 21/22 ok |
| changed-code comparable rows | 63/146 |
| applied rows geomean | 1.032346 |
| non-applied rows geomean | 0.982708 |

The key lesson is not the headline ratio. The key lesson is that non-applied
rows moved away from neutral, while applied rows were worse under the unweighted
per-program metric. That is exactly the kind of ambiguity that a closed-loop
agent benchmark should expose.

### Policy Iteration Evidence

`docs/tmp/2026-03-11/corpus-tuned-policy-comparison.md` and
`docs/tmp/active/policy-iteration-rounds.md` show that policy selection matters:

| Evidence | Result |
|---|---|
| Blind all-apply policy | many regressions; not corpus-wide break-even |
| Tuned policy shared subset | wins improved from 38 to 42 and regressions dropped from 90 to 84 |
| Dense micro policy iteration | original 6-dense geomean about 0.836x; skipping known regressors moved best rounds above 1.0x |
| Full 62-bench policy round | overall about 0.995x, applied-only about 0.993x, dense subset about 1.125x |

This is a strong seed for an agent task: "choose when not to optimize." It also
suggests the benchmark should score invalid/noisy actions separately from
valid-but-slow actions.

## Session Evidence

The local Codex history contains many repo-related prompts, but it should be
used conservatively. It is useful for deriving task families and prompt modes;
it is not a source of benchmark scores.

Keyword scanning of `~/.codex/history.jsonl` found:

| Item | Count |
|---|---:|
| keyword hits | 1867 |
| unique sessions | 132 |

Top keyword counts:

| Keyword | Count |
|---|---:|
| `agent` | 511 |
| `benchmark` | 338 |
| `native` | 332 |
| `kop` | 313 |
| `corpus` | 271 |
| `JIT` | 254 |
| `verifier` | 239 |
| `bpf-benchmark` | 220 |
| `policy` | 195 |
| `loader` | 97 |
| `ReJIT` / `rejit` | 91 / 91 |
| `bpfopt` | 85 |

Aggregating hits into task categories gives:

| Category | Count |
|---|---:|
| corpus/evaluation | 593 |
| agent/session/prompt | 531 |
| optimizer/policy | 529 |
| verifier/JIT/ReJIT | 445 |
| native/loader | 397 |
| bpf repo/tooling | 287 |

The related prompt volume is concentrated in 2026-03 through 2026-06:

| Month | Related Messages |
|---|---:|
| 2025-11 | 2 |
| 2026-03 | 307 |
| 2026-04 | 179 |
| 2026-05 | 925 |
| 2026-06 | 454 |

Interpretation:

1. There is enough historical session material to mine realistic tasks.
2. The task material clusters around exactly the dimensions BPFOptBench cares
   about: corpus evaluation, optimizer policy, verifier/JIT, loader/app
   lifecycle, and agent prompting.
3. The history does not contain hidden oracle labels or clean success/failure
   scoring. A benchmark paper must create those labels explicitly.

## Prompt-Level Lessons

The previous prompts suggest a useful evolution in problem framing:

1. Early prompts focus on concrete mechanisms: verifier repair, kop, ReJIT,
   bytecode rewriting, loader behavior, and pass policy.
2. Later prompts ask whether the work should become an agent benchmark rather
   than another optimizer-system paper.
3. The current BPFOptBench framing should keep that separation: verifier-error
   repair is a separate problem already covered by BPFix-style work; BPFOptBench
   should instead evaluate closed-loop optimization decisions on existing eBPF
   programs.

This suggests three prompt modes for the benchmark:

| Prompt Mode | Agent Sees | Purpose |
|---|---|---|
| raw | result files, logs, source tree, and task statement | Measures whether an agent can operate in the real repo. |
| structured | normalized verifier/app/workload/perf feedback | Measures whether better feedback improves decisions. |
| expert-summary | concise analysis note plus raw artifacts | Measures whether the limiting factor is information extraction or optimization reasoning. |

The benchmark should preserve raw prompts and model outputs in private traces,
but public artifacts should expose redacted metadata, action manifests, and
scored outcomes rather than full local prompts.

## Adjusted Research Questions

The original high-level question was:

> Can agents tune existing eBPF programs under real verifier/JIT/workload
> feedback?

That should remain the motivating question, but it should not be RQ1. The
current data supports a staged RQ structure:

| RQ | Question | Current Status | Evidence Needed |
|---|---|---|---|
| RQ1 | Can we define a replayable benchmark interface for agent eBPF optimization tasks? | mostly design-supported | task manifest, action schema, feedback schema, hidden evaluator |
| RQ2 | Why is eBPF optimization a hard closed-loop benchmark problem? | supported by historical data | no-op floors, pass-signal audit, policy sensitivity, applied-vs-speed mismatch |
| RQ3 | Can historical repo sessions be converted into realistic benchmark tasks? | partially supported | 20-50 audited tasks with labels and replay scripts |
| RQ4 | Does structured feedback reduce invalid or noisy optimization decisions? | planned | raw-vs-structured prompt experiment |
| RQ5 | Can agents beat no-op, static-policy, random/grid, and human baselines? | not yet supported | frozen live task set plus repeated agent runs |
| RQ6 | Does the benchmark generalize across optimization layers? | design-supported only | bytecode-only, kop-enabled, and future source/LLVM adapters |

The key adjustment is to make benchmark construction and difficulty evidence
first-class contributions. Agent performance can be a result, but the paper
should survive even if current agents do not win.

## Optimization Space

BPFOptBench can expose a layered action space without requiring every layer in
the first paper:

| Layer | Agent Action | Current Practicality |
|---|---|---|
| L0 analysis-only | choose next experiment or diagnose a result from existing artifacts | immediate |
| L1 pass-list tuning | choose pass subset/order and workload budget | immediate |
| L2 per-app/per-program policy | choose where a pass is allowed | near-term |
| L3 per-site gating | choose rewrite sites or thresholds | near-term for selected passes |
| L4 profile-guided decisions | consume real PMU/profile data such as branch site stats | planned; must use real per-site profile data |
| L5 source/LLVM/backend modifications | edit source, LLVM backend, or pass implementation | future/harder |
| L6 kop/kernel-layer actions | choose kop-backed transformations and kernel/JIT variants | BpfReJIT-specific extension path |

For the workshop version, L0-L3 are enough. L4-L6 should be presented as
adapter generality or future expansion unless there are fresh results.

## Candidate Task Tracks

### Track A: Offline Analysis Tasks

These tasks use existing artifacts and do not run benchmarks.

Examples:

1. Given no-op floor and pass-signal reports, decide whether a pass result is
   paper-grade or noise.
2. Given policy iteration logs, choose the next pass-policy experiment.
3. Given a v3 raw result payload, extract the valid evidence without relying on
   legacy summary fields.
4. Given tail-call accounting notes, decide which directly attached caller
   should receive descendant optimization attribution.

Why this matters: these tasks are cheap, reproducible, and immediately
derivable from historical sessions.

### Track B: Repo/Benchmark Integrity Tasks

These tasks evaluate whether the agent respects benchmark rules.

Examples:

1. Adapt an analyzer from legacy summary schema to v3 raw app payloads.
2. Add a task manifest without filtering ReJIT failures.
3. Preserve app-level loaders and avoid custom replacement loaders.
4. Detect forbidden manipulations such as lowering workload duration, excluding
   programs, or hiding verifier failures.

Why this matters: agent benchmarks are easy to game unless the evaluator checks
protected paths and policy constraints.

### Track C: Live Optimization Tasks

These tasks run real benchmark commands through `make`.

Examples:

1. Choose a pass subset for one app from historical reports, then run a small
   smoke benchmark.
2. Choose a per-app policy for `map_inline` or kop-family passes.
3. Compare no-op, default static, random/grid, and agent-chosen pass lists under
   the same workload budget.
4. Reproduce one historical strong-looking signal such as OTEL `map_inline`
   before allowing it into the benchmark set.

Why this matters: this is the final target of the paper, but it should come
after the task interface and hidden evaluator exist.

## Recommended Next Experiments

### E1. Build A Session-Derived Task Index

Create a private or redacted manifest with 20-50 candidate tasks mined from
history and existing docs.

Minimum fields:

| Field | Meaning |
|---|---|
| `task_id` | stable identifier |
| `track` | offline, integrity, live |
| `source_artifacts` | docs/results paths |
| `allowed_actions` | pass-list, policy, per-site, code edit, analysis-only |
| `forbidden_actions` | workload changes, filtering, loader replacement, summary injection |
| `oracle` | verifier/app/workload/perf/integrity checks |
| `baseline` | no-op, static policy, random/grid, human |
| `expected_difficulty` | smoke, medium, hard |
| `privacy` | public, redacted, private |

Success criterion: at least 20 tasks have enough artifacts and oracle rules to
be replayed or manually adjudicated.

### E2. Define The Hidden Evaluator Contract

Before running agents, specify what the evaluator protects:

1. benchmark command must go through `make`;
2. workload duration/sample knobs must match the task budget;
3. no app or program exclusion is allowed;
4. app-level loader behavior must be preserved;
5. raw result schema must be preserved;
6. ReJIT/verifier errors must remain visible;
7. post-hoc analysis must use the documented `min_runs >= 100` methodology;
8. tail-called programs must be attributed through directly attached callers.

Success criterion: a deliberately bad agent action is rejected by the evaluator.

### E3. Recompute Current Noop/Noop-ReJIT Floor

The historical floor is useful, but a current v3 benchmark should have its own
floor.

Candidate commands, when ready to run:

```bash
BPFREJIT_BENCH_PASSES="noop" SAMPLES=3 WORKLOAD_DURATION=30 make corpus
SAMPLES=3 WORKLOAD_DURATION=30 make corpus
```

Interpretation should remain post-hoc. The framework should only collect raw
counters.

Success criterion: retained-program coverage is non-trivial and the no-op floor
is documented for the same schema and app set used by agent tasks.

### E4. Run A Low-Cost Offline Agent Study First

Before live tuning, evaluate agents on offline task decisions:

1. choose whether a result is real or noise;
2. choose next experiment from policy logs;
3. identify invalid benchmark manipulations;
4. adapt to v3 raw schema.

Metrics:

| Metric | Meaning |
|---|---|
| valid-action rate | Did the agent obey constraints? |
| oracle-pass rate | Did the decision satisfy the hidden rubric? |
| noise-chasing rate | Did it treat no-op/no-signal movement as improvement? |
| attempt count | How many tries until valid? |
| cost/time | Tokens and wall-clock budget. |

This gives the paper an early scoreboard without spending many VM/AWS runs.

### E5. Then Run A Small Live A1/A2 Study

Suggested first live split:

| Task | Scope | Why |
|---|---|---|
| A1 pass-list tuning | one app, 2-3 candidate pass lists | cheapest closed-loop task |
| A2 per-app policy | one or two historically noisy apps | tests whether agents learn "do not optimize" |
| A3 reproduction | one historical strong-looking signal | tests whether agents can validate evidence |

Baselines:

1. no-op/no pass;
2. default static policy;
3. random/grid over small pass choices;
4. human policy from historical notes;
5. agent raw prompt;
6. agent structured prompt.

The first live study should not try to cover every app, architecture, and pass.
It should test whether the benchmark loop works and whether agent decisions are
meaningfully different from baselines.

## How To Present Results

The paper should present BPFOptBench as the artifact and the current data as a
difficulty study.

Recommended result layout:

| Paper Element | Content |
|---|---|
| Figure 1 | BPFOptBench loop: agent action, real app loader, verifier/ReJIT, JIT, workload, raw feedback, hidden evaluator. |
| Table 1 | Optimization layers and action types. |
| Figure 2 | Historical difficulty evidence: no-op floor, pass-signal instability, applied-count mismatch. |
| Table 2 | Task tracks and oracle components. |
| Figure 3 | Agent/baseline scoreboard, only after frozen tasks exist. |
| Table 3 | Failure taxonomy: invalid action, verifier failure, app failure, workload failure, no signal, regression, noise chasing. |

The safest current contribution wording is:

1. a benchmark specification for agent tuning of existing eBPF programs;
2. a real-kernel evaluator that composes verifier, JIT, application, workload,
   and raw performance feedback;
3. a task taxonomy and seed corpus mined from real eBPF optimization sessions;
4. a historical difficulty study showing why simple static policies and
   rewrite counts are insufficient;
5. an initial agent/baseline evaluation, if E1-E5 are completed.

Avoid claiming:

1. BPFOptBench proves agents can optimize eBPF;
2. kop is required for the benchmark;
3. verifier repair is the main novelty;
4. current pass results already provide a stable optimization win.

## Claim Readiness

| Claim | Status | Notes |
|---|---|---|
| BPFOptBench is distinct from BpfReJIT/kop/native-loader papers. | supported | It evaluates agents and task/oracle design rather than proposing one optimizer mechanism. |
| Existing data shows eBPF optimization is difficult and noisy. | supported | Historical reports give multiple concrete failure modes. |
| The current repo can host a real evaluator. | partially supported | Latest v3 six-app raw runs are promising; hidden evaluator still needs implementation. |
| Sessions can seed realistic tasks. | partially supported | Strong aggregate evidence; needs curated task manifest and labels. |
| Structured feedback improves optimization. | not yet supported | Requires raw-vs-structured controlled study. |
| Agents outperform baselines on live eBPF tuning. | not yet supported | Requires frozen live tasks and repeated runs. |
| Cross-layer optimization generality is demonstrated. | not yet supported | Current evidence is strongest for bytecode/pass-policy and kop-adjacent paths. |

## Bottom Line

The current data is enough to justify writing BPFOptBench as a benchmark paper,
not enough to write it as an agent-optimizer success paper.

The next milestone should be a frozen seed task set and hidden evaluator, using
historical sessions as task material and historical performance reports as the
difficulty study. Only after that should the project spend substantial compute
on live agent tuning runs.
