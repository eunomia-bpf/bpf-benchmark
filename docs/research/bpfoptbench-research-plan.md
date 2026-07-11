# Experiment Plan: BPFOptBench

Last updated: 2026-06-22
Stage at update: experiment-design
Source/command: user discussion on agentic eBPF optimization benchmark in `/home/yunwei37/workspace/bpf-benchmark`

## Thesis

BPFOptBench evaluates whether agents can tune existing eBPF programs under real verifier, JIT, and workload feedback by exposing eBPF optimization as a closed-loop decision problem over multiple transformation layers, rather than as a single compiler-pass benchmark.

## Paper Type

- Type: benchmark/tooling plus measurement study.
- Target venue: eBPF workshop or systems workshop first; a larger systems venue would require stronger agent wins and broader backend coverage.
- Implementation status: partial infrastructure exists for bytecode/ReJIT/kinds of kop optimization; source-level and LLVM-backend adapters are currently a design target, not demonstrated infrastructure.
- Main reviewer risk: current historical data proves the problem is hard and noisy, but does not yet prove that an agent can reliably improve eBPF programs.
- Scope discipline: the current repository is an execution substrate, not by itself an agent benchmark. BPFOptBench must add frozen tasks, base snapshots, hidden evaluator checks, protected workloads/scoring, task splits, and agent traces.

## Optimization Space

BPFOptBench should model eBPF optimization as four artifact layers plus one control plane. It can be summarized as three coarse regions, but the benchmark API should keep the layers separate because their inputs, safety oracle, and deployment story differ.

### Coarse Regions

| Region | Layers | What the agent changes | Requires source? | Uses live deployment facts? | First-paper status |
|---|---|---|---:|---:|---|
| Producer-side optimization | Source and LLVM backend | C/Rust eBPF source, Clang flags, LLVM IR/MIR/BPF backend passes | yes | usually no | adapter/future |
| Artifact-side optimization | Pre-load and live bytecode | `.bpf.o` or `struct bpf_insn[]` rewrites, pass order, pass params, per-program policy | no | pre-load no; live yes | primary |
| Consumer-side optimization | Kernel JIT and kop/native lowering | JIT lowering choices, kernel extension capabilities, kop use/gating | no | yes | primary when kop exists |

### Layer L0: Source-Level Transform

The agent edits eBPF source code or application-side BPF generation. Examples: helper replacement, map layout changes, source-level bounds-check restructuring, explicit unrolling, tail-call chain changes, or CO-RE access restructuring.

This layer is powerful but hard to benchmark cleanly. It requires source, rebuilds, app-specific semantic tests, and stronger review to distinguish optimization from workload or behavior changes. It is useful as a future extension, but it should not be required for the first BPFOptBench paper.

### Layer L1: LLVM/BPF Backend Transform

The agent changes compiler choices: Clang flags, LLVM IR pass placement, BPF backend peepholes, BPF target cost model, branch analysis, MachineInstr passes, or TableGen patterns.

This layer is important because current LLVM BPF backend intentionally protects verifier/CO-RE-sensitive forms and lacks many target-specific optimizations available on x86/AArch64. However, it is ahead-of-time and cannot see live map values, real verifier states after load, or deployment-specific profiles. For BPFOptBench, this is a separate adapter: an agent can propose an LLVM patch or compiler configuration, then the framework rebuilds apps and evaluates the resulting eBPF through the same oracle.

### Layer L2: Pre-Load Bytecode/Object Transform

The agent rewrites BPF bytecode or object files before kernel load. Examples: byte-ladder to wide load, static constant propagation, helper specialization, object-level pass ordering, or BPF bytecode superoptimization.

This layer is closest to K2/Merlin/EPSO-style work. It does not require source, but it still changes the load artifact and needs app reload. The kernel verifier remains the safety oracle. This should be supported by BPFOptBench, but it is not the most distinctive version of our current infrastructure.

### Layer L3: Live/Post-Load Bytecode Transform

The agent tunes already loaded or app-loaded BPF programs using bytecode rewrites plus real feedback. Examples: selecting `bpfopt` passes, choosing pass order, per-app/per-program gating, per-site allow/deny decisions, profile-guided branch decisions, map-value specialization, and verifier-error repair of candidate rewrites.

This is the strongest first-paper layer because it matches the core question: can an agent improve existing eBPF programs under real verifier/JIT/workload feedback? It also lets the benchmark use app-level loaders and real production-like workloads without requiring source or custom loaders.

### Layer L4: Kernel/JIT/KOperation Transform

The agent chooses or gates kernel-side capabilities that let bytecode express native operations unavailable in the base BPF ISA. Examples: `rotate`, `cond_select`, `extract`, `endian_fusion`, `bulk_memory`, `prefetch`, and future JIT-lowering choices.

This layer should be presented carefully. BPFOptBench should not depend on kop as its defining mechanism; kop is one backend that enlarges the action space. The benchmark claim is broader: agents should be evaluated against the real kernel acceptance path and final JIT/workload behavior, whether the action backend is source, LLVM, bytecode, ReJIT, or kop.

### Control Plane: Agent Decisions

Across all layers, the benchmark action space should expose increasingly fine-grained choices:

| Level | Action granularity | Example action | First-paper priority |
|---|---|---|---|
| A0 | no-op / baseline | keep program unchanged; run noop ReJIT floor | must |
| A1 | suite-wide pass list | `wide_mem,map_inline,dce` for all apps | must |
| A2 | per-app pass list | `map_inline` only for otel, skip for tracee | must |
| A3 | per-program policy | optimize only selected program IDs/names | should |
| A4 | per-site gating | allow a specific rewrite site only after evidence | later or small subset |
| A5 | pass parameters/profile use | use PMU profile for `branch_flip`; tune thresholds | later unless profile pipeline is ready |
| A6 | new rewrite generation | synthesize a new pass or patch compiler/kernel | future; too broad for first workshop paper |

The first BPFOptBench paper should focus on A1-A3 over L3/L4, with L0-L2/L1 described as supported-by-design adapters or small proof-of-concept tasks.

## Claim Ledger

| ID | Claim | Scope | Metric/evidence needed | Status |
|----|-------|-------|------------------------|--------|
| C1 | BPFOptBench defines a backend-agnostic benchmark interface for agentic eBPF optimization. | Existing eBPF apps, real loaders, verifier/JIT/workload feedback; first implementation may instantiate only bytecode/ReJIT/kop. | Task spec, action schema, feedback schema, oracle definition, trace/provenance format. | planned |
| C2 | eBPF optimization is a hard closed-loop tuning problem; static pass policies and local rewrite counts are insufficient. | Current corpus and historical runs. | Noop floors, noise intervals, pass-signal audit, policy comparison, examples where applied sites do not imply speedup. | partially supported |
| C3 | Real verifier, app, workload, and performance oracles must be composed; verifier acceptance alone is not enough. | Six supported corpus apps and selected microbenchmarks. | Failure taxonomy showing verifier rejection, app failure, workload failure, no-signal, regression, and noise chasing. | planned |
| C4 | Agents can be compared meaningfully using success, regret, and cost metrics under the same oracle. | Agent variants over A1-A3 action levels. | Controlled runs for scripted baseline, random/grid baseline, human policy, and LLM agent variants. | unsupported until run |
| C5 | Structured feedback should improve agent decisions over raw logs or one-shot prompting. | Same task split and model set. | Raw prompt vs structured feedback vs closed-loop feedback ablation, with identical run budget. | unsupported until run |
| C6 | The benchmark is not tied to kop/kprog; those are optional action backends. | Design plus at least one non-kop action path. | Demonstrate noop/bytecode-only policy tasks; optionally a pre-load bytecode or LLVM-backend adapter smoke test. | planned |
| C7 | BPFOptBench prevents and measures benchmark invalidation under performance incentives. | Frozen tasks with hidden evaluator and protected paths. | Integrity audit for workload mutation, reduced run counts, hidden failure filtering, loader bypass, result fabrication, and protected-path edits. | planned |

## Claim-To-Experiment Map

| Claim | Required evidence | Primary block | Falsifying result | Supported wording if partial |
|-------|-------------------|---------------|-------------------|------------------------------|
| C1 | Implemented task/feedback/oracle schema and reproducible trace records. | B1 | Benchmark cannot express existing runs without special cases. | "We propose the interface and instantiate it for bytecode/ReJIT tasks." |
| C2 | Historical data shows instability, mixed pass outcomes, and policy sensitivity. | B2 | Static policies consistently improve after noise filtering. | "The current corpus exposes noisy and workload-specific optimization behavior." |
| C3 | Component oracles disagree in real runs. | B3 | Verifier acceptance, app success, workload correctness, and performance always agree. | "For evaluated workloads, performance/noise remains the main extra oracle beyond acceptance." |
| C4 | Agent variants can be ranked by accepted/correct/faster outcomes, regret, and cost. | B4 | All agents collapse to random/no-op under fair budget. | "BPFOptBench exposes measurable gaps; current agents do not yet solve the task." |
| C5 | Structured feedback beats raw or one-shot feedback. | B5 | Structured feedback has no effect or worsens decisions. | "Feedback design is a variable BPFOptBench can measure; no universal win yet." |
| C6 | At least one task works without kop; kop appears as an optional backend. | B6 | All meaningful tasks require kop. | "This artifact evaluates bytecode/ReJIT/kindsn actions; broader adapters are future work." |
| C7 | Hidden evaluator catches reward hacking and invalid measurements. | B8 | Agents never try invalid actions, or checks cannot distinguish invalid from valid actions. | "BPFOptBench specifies integrity checks; measured reward-hacking prevalence is future work." |

## System-Under-Test Model

- Components: corpus runner, app-level loaders, workload drivers, in-app BPFReJIT shim, kernel verifier, kernel JIT, `bpfopt` bytecode passes, optional kop modules, external analysis scripts, and agent harness.
- Durable state: run artifacts under `corpus/results/`, app payload JSON, workload stdout/stderr, verifier logs, pass reports, agent traces, prompt manifests, model/toolchain versions.
- Trust/failure boundaries: agents are untrusted optimizers; the kernel verifier enforces safety; app/workload oracles enforce functional behavior; analysis scripts compute performance claims outside the framework.
- Safety/liveness guarantees: no bypass of Linux verifier; no direct `.bpf.o` custom loading in corpus benchmarks; failed ReJIT/load attempts surface as errors; benchmark does not hide failures or filter programs.
- Workloads: six supported corpus apps plus selected microbenchmarks for layer-specific smoke tests.
- Observability: raw counters per BPF program/phase, workload raw metrics, app lifecycle logs, verifier/JIT errors, pass reports, prompt/action/result traces.
- Assumptions: performance metrics are computed post-hoc using the documented per-program ratio methodology; tail-called programs are attributed through callers; branch-flip requires real per-site PMU profile data.

## Experiment Matrix

| Block | Claim | Experiment | Baselines/variants | Metric(s) | Oracle | Figure/table | Priority |
|-------|-------|------------|--------------------|-----------|--------|--------------|----------|
| B1 | C1,C6 | Benchmark schema and task instantiation | bytecode-only, ReJIT, kop-capable task configs | task coverage, trace completeness | schema validation and replayability | Table 1 | must |
| B2 | C2 | Historical difficulty study | noop, skip-ReJIT floor, static policies, tuned policy | Method B geomean, W/L/T, noise intervals, applied-vs-speed mismatch | post-hoc analysis over existing artifacts | Fig. 2 | must |
| B3 | C3 | Oracle disagreement taxonomy | accepted-only vs full oracle | rejection/app/workload/perf failure counts | verifier + app status + workload + performance oracle | Table 2 | must |
| B4 | C4 | Closed-loop agent tuning | no-op, default static, random/grid, human policy, LLM agents | `bpfopt_success_p`, geomean ratio, regret, attempts, time/cost | full oracle | Fig. 3 | must |
| B5 | C5 | Feedback ablation | raw logs, structured summaries, closed-loop feedback, expert prompt | success rate, regret, invalid-action rate | same task split and run budget | Fig. 4 | should |
| B6 | C6 | Layer/backend ablation | bytecode-only, kop-enabled, optional pre-load adapter | success by layer, failure modes | same workload oracle | Table 3 | should |
| B7 | C4,C5 | Generalization split | train/dev historical tasks vs heldout apps/runs | heldout success, overfit gap | hidden heldout oracle | Fig. 5 | should |
| B8 | C7 | Integrity and anti-gaming audit | public-only checks vs hidden evaluator | invalid-action rate, protected-path violations, workload hash drift | hidden evaluator and fresh-VM replay | Table 4 | must |

## Experiment Blocks

### B1. Benchmark Interface And Tasks

- Claim tested: C1, C6.
- Hypothesis: A single benchmark interface can describe eBPF optimization tasks without hard-coding kop or ReJIT as the only mechanism.
- Why this block exists: reviewers need to see BPFOptBench as a benchmark, not as another name for the existing optimizer.
- Workload: frozen task manifests over selected corpus app/program/pass combinations.
- Compared systems: bytecode-only task, live ReJIT task, kop-capable task; optional source/LLVM adapter specs.
- Metrics: number of tasks expressible, required oracle fields, replay success, trace completeness.
- Setup/config: use app-level loaders and `make <target>` benchmark entrypoints; no custom direct loaders.
- Run budget: smoke first, then one release-quality replay per task family.
- Oracle: task replay either reconstructs the same command/config and validates required raw result fields, or fails.
- Success criterion: every first-paper task has action schema, observation schema, allowed budget, oracle, and result path convention.
- Failure interpretation: if tasks need ad hoc fields, narrow the paper to "BPFOptBench-ReJIT" rather than backend-agnostic BPFOptBench.
- Figure/table target: Table 1 optimization layers and action space.
- Reproducibility files: task manifests, prompt manifests, agent traces, result paths.

### B2. Historical Difficulty Study

- Claim tested: C2.
- Hypothesis: existing data shows that eBPF optimization profitability is workload-specific, noisy, and not predictable from rewrite count alone.
- Why this block exists: it motivates the benchmark before claiming agent success.
- Workload: existing corpus results and historical policy-comparison docs.
- Compared systems: noop ReJIT floor, skip-ReJIT floor, static full pass policy, tuned policy, isolated pass attempts where available.
- Metrics: per-program ratio, retained-program geomean, W/L/T, app noise intervals, applied-site count, clear-low/high-near/inside classifications.
- Setup/config: post-hoc analysis only; no new benchmark framework summaries.
- Run budget: analysis-only.
- Oracle: existing artifact paths and documented Method B metric with `min_runs >= 100`.
- Success criterion: show at least three concrete difficulty modes: noise floor, pass interaction, and applied-count mismatch.
- Failure interpretation: if historical results are too stale for the current codebase, rerun a minimal six-app floor and static-policy subset.
- Figure/table target: Fig. 2 static policy and noise-floor motivation.
- Reproducibility files: `docs/tmp/pass_signal_audit_20260508.md`, `docs/tmp/corpus-performance-analysis-20260428.md`, `docs/tmp/2026-03-11/corpus-tuned-policy-comparison.md`, `docs/tmp/active/policy-iteration-rounds.md`.

### B3. Oracle Composition And Failure Taxonomy

- Claim tested: C3.
- Hypothesis: optimizing eBPF requires a composed oracle because candidates can fail at different boundaries.
- Why this block exists: an agent benchmark is only meaningful if "success" cannot be gamed by verifier acceptance or micro-only measurements.
- Workload: corpus tasks plus a small set of verifier-stress and workload-stress tasks.
- Compared systems: accepted-only scoring, accepted+app scoring, accepted+app+workload scoring, full accepted+app+workload+performance scoring.
- Metrics: failure counts by category, false success rate under weaker oracle, invalid-action rate.
- Setup/config: preserve raw workload metrics and lifecycle errors; compute classifications outside framework.
- Run budget: smoke taxonomy first; release taxonomy after B4/B5 runs.
- Oracle: verifier acceptance, app status, workload semantic counters, raw BPF counter deltas, and analysis-side performance threshold.
- Success criterion: demonstrate at least one case where a weaker oracle would overstate success or hide a regression/no-signal.
- Failure interpretation: if most failures are only performance/noise failures, claim narrower: "performance oracle and noise floor dominate in current corpus."
- Figure/table target: Table 2 failure taxonomy.
- Reproducibility files: run artifacts plus classification script/output.

### B4. Closed-Loop Agent Tuning

- Claim tested: C4.
- Hypothesis: agents can be ranked reproducibly by their ability to choose optimization actions that pass the full oracle and improve performance beyond baseline/noise.
- Why this block exists: this is the benchmark's anchor result.
- Workload: frozen tasks over the six supported apps; initial task levels A1-A3.
- Compared systems: no-op, default static pass list, random/grid search with same budget, human tuned policy, one-shot LLM, closed-loop LLM agent.
- Metrics: full-oracle success rate, `bpfopt_success_p`, retained-program geomean ratio, W/L/T, regret to best-known action, attempts, wall-clock, tokens/cost.
- Setup/config: agent may read allowed feedback and propose actions; executor runs only through `make <target>`.
- Run budget: smoke on subset, hardening on 2-3 apps, release on six-app split.
- Oracle: accepted by verifier, app succeeds, workload succeeds, retained-program performance passes threshold, no forbidden benchmark manipulation.
- Success criterion: at least one non-oracle agent beats no-op/static/random on heldout tasks under equal budget.
- Failure interpretation: if agents do not beat baselines, the paper can still be a benchmark paper if it clearly reports current-agent limitations and failure modes.
- Figure/table target: Fig. 3 benchmark scoreboard.
- Reproducibility files: task split, prompts, model versions, agent traces, run artifacts.

### B5. Feedback Ablation

- Claim tested: C5.
- Hypothesis: structured eBPF feedback improves agent decisions compared with raw logs or one-shot prompting.
- Why this block exists: it isolates the benchmark-specific contribution from simply running a large model.
- Workload: same task split as B4.
- Compared systems: raw verifier/workload/result logs, structured normalized feedback, structured feedback with historical context, closed-loop multi-attempt feedback.
- Metrics: full-oracle success, invalid action rate, noise-chasing rate, regret, attempts to first valid improvement.
- Setup/config: same model and budget across feedback modes.
- Run budget: smoke on historical-only tasks; release on live execution subset if budget permits.
- Oracle: same as B4.
- Success criterion: structured feedback reduces invalid/noisy choices or improves heldout success.
- Failure interpretation: if structured feedback does not help, present feedback design as an open challenge measured by BPFOptBench.
- Figure/table target: Fig. 4 feedback ablation.
- Reproducibility files: prompt manifests with hashes, feedback JSON schema, traces.

### B6. Backend And Layer Ablation

- Claim tested: C6.
- Hypothesis: BPFOptBench can separate action-layer effects from agent quality.
- Why this block exists: it prevents the paper from being perceived as only a kop benchmark.
- Workload: matched tasks where possible across bytecode-only and kop-enabled pass sets; optional pre-load object rewrite smoke.
- Compared systems: bytecode-only actions, kop-enabled actions, optional source/LLVM/pre-load adapters.
- Metrics: task success by layer, failure mode by layer, cost per layer, portability to x86/arm64 where available.
- Setup/config: use the same corpus oracle; do not require kop for bytecode-only task validity.
- Run budget: release-quality for bytecode-only vs kop-enabled; smoke for source/LLVM adapter unless already implemented.
- Oracle: same full oracle, plus layer-specific build/reload success.
- Success criterion: at least one meaningful benchmark track runs without kop.
- Failure interpretation: if only kop-enabled tasks produce signal, rename first paper scope to "agentic ReJIT/kop tuning" and leave BPFOptBench broadening to follow-up work.
- Figure/table target: Table 3 layer comparison.
- Reproducibility files: layer-specific task manifests and backend configs.

### B7. Generalization And Anti-Overfitting

- Claim tested: C4, C5.
- Hypothesis: agents that use feedback well generalize better than policies tuned on historical runs.
- Why this block exists: agent benchmarks are vulnerable to prompt/history overfitting.
- Workload: train/dev/heldout split by app, pass family, or run timestamp.
- Compared systems: best historical policy, closed-loop agent, one-shot agent, random/grid.
- Metrics: dev vs heldout success gap, regret gap, invalid-action rate.
- Setup/config: hide heldout result summaries from agent prompt; expose only task spec and allowed observations.
- Run budget: release only after B4 smoke shows non-trivial differences.
- Oracle: heldout full oracle.
- Success criterion: closed-loop feedback keeps heldout performance close to dev performance.
- Failure interpretation: if agents overfit, report the benchmark as exposing overfitting and narrow claims about generalization.
- Figure/table target: Fig. 5 heldout split.
- Reproducibility files: frozen split file, prompt manifest, heldout result paths.

### B8. Integrity And Anti-Gaming Audit

- Claim tested: C7.
- Hypothesis: performance-seeking agents will sometimes find invalid shortcuts unless the evaluator protects workloads, scoring, and execution policy.
- Why this block exists: agent benchmark reviewers will ask whether the benchmark can be gamed.
- Workload: the same frozen tasks as B4, plus a small set of adversarial task variants where public checks are intentionally weaker than hidden checks.
- Compared systems: public-only evaluator, hidden evaluator, hidden evaluator with fresh-VM replay.
- Metrics: protected-path edit rate, workload hash drift, run-budget changes, loader bypass attempts, filtered failure attempts, fabricated result attempts, and valid solved rate after integrity gates.
- Setup/config: evaluator files and workload specs live outside the agent-editable tree; task manifests name protected paths and workload hashes.
- Run budget: smoke with 5-10 tasks; release with the main task split.
- Oracle: hidden integrity checker plus fresh-VM replay.
- Success criterion: invalid shortcuts are either absent or detected and scored as failures.
- Failure interpretation: if the evaluator misses invalid shortcuts, the paper must narrow to "testbed" and defer benchmark claims.
- Figure/table target: Table 4 integrity failures by agent/baseline.
- Reproducibility files: task manifests, hidden-check descriptions, integrity audit output.

## Metrics

Primary benchmark metrics should be reported as components, not one opaque score:

| Metric | Definition | Why it matters |
|---|---|---|
| Validity rate | Fraction of attempts accepted by verifier and not rejected by framework policy. | Captures eBPF safety constraints. |
| Workload success rate | Fraction of attempts where app lifecycle and workload semantic checks pass. | Prevents "fast but broken" actions. |
| Performance success rate | Fraction of valid workload-success attempts that improve beyond the chosen threshold/noise gate. | Captures useful optimization. |
| `bpfopt_success_p` | Fraction of tasks accepted, workload-correct, and faster than baseline by at least threshold `p` or beyond the measured noise gate. | eBPF analogue of GPU-kernel benchmark fast-success metrics. |
| Geomean ratio | Post/baseline per-program runtime ratio over retained programs. Lower is better. | Matches existing paper-grade methodology. |
| Regret to best-known action | Agent ratio divided by best-known valid ratio for the task, using ratio direction consistently. | Separates success from search quality. |
| Cost | Attempts, wall-clock time, tokens, dollar cost, and benchmark runs consumed. | Agents can brute-force; benchmark should price that. |
| Consistency | Repeated-run success or pass-at-k-style stability for the same task/model budget. | Separates reliable agents from lucky single-run successes. |
| Integrity failure rate | Fraction of attempts rejected for workload mutation, protected-path edits, run-budget changes, hidden failure filtering, result fabrication, or loader bypass. | Measures reward hacking under performance incentives. |

For paper-grade performance, use the existing post-hoc methodology: skip programs with zero runs, require `min_runs >= 100`, compute per-program ratio as post average ns/run over baseline average ns/run, and report per-program geomean plus W/L/T. Tail-call descendants must be attributed through their directly attached callers.

## Baseline Fairness

- No-op baseline: app loads and workload runs without optimization.
- Noop ReJIT baseline: controls for ReJIT and measurement perturbation.
- Static default policy: current configured pass list or explicit pass group.
- Random/grid baseline: same action budget as the agent; proves whether the agent is better than blind search.
- Human tuned policy: policy derived from previous analysis, marked as non-agent expert baseline.
- Oracle policy: best observed action per task; used only to compute regret, not as a deployable baseline.
- Raw LLM baseline: one-shot prompt with raw logs.
- Structured-feedback LLM baseline: same model and budget, normalized feedback.

Baselines intentionally not first-paper primary:

- Full source-rewriting agents: high semantic risk and expensive rebuild/retest loop.
- LLVM backend patch agents: important but requires an upstream-style compiler benchmark track.
- Kernel/JIT patch-generating agents: too much safety and review burden for a workshop benchmark paper.

## Run Order

| Run ID | Stage | Purpose | Config | Seed/reps | Decision gate | Cost | Risk |
|--------|-------|---------|--------|-----------|---------------|------|------|
| R001 | sanity | Freeze task schema and result trace format. | no benchmark run; replay existing artifacts | n/a | trace can represent historical runs | low | schema churn |
| R002 | sanity | Build 15-25 vertical-slice tasks with base commits, public checks, hidden checks, protected paths, workload hashes, and reference solutions. | task authoring only | expert-reviewed | every task replays in a fresh VM | medium | task quality |
| R003 | sanity | Recompute current six-app no-op/noop-ReJIT floor if historical data is too stale. | `BPFREJIT_BENCH_PASSES="noop" SAMPLES=3 WORKLOAD_DURATION=30 make corpus` | 1 authoritative run plus optional repeat | retained coverage non-trivial | medium | noisy or long |
| R004 | sanity | Static pass smoke on 1-2 apps. | app subset via `BPFREJIT_CORPUS_APPS`, explicit pass list | 1 | apps complete and artifacts usable | medium | app flake |
| R005 | hardening | Historical-only agent task: choose policy from old reports, no live execution. | frozen prompt and hidden answer key | 3 model seeds if supported | agent output parseable and ranked | low | weak external validity |
| R006 | hardening | Live A1 suite-wide pass selection. | fixed app subset, equal attempt budget | 3 attempts/model | at least one baseline separation | medium | benchmark cost |
| R007 | hardening | Live A2 per-app policy. | six-app or 3-app split | 3 attempts/model | improves over A1 or reveals overfitting | high | noise |
| R008 | hardening | Integrity smoke. | public-only vs hidden evaluator on 5-10 tasks | fixed budget | invalid shortcuts detected | medium | evaluator gaps |
| R009 | release | B4 full scoreboard. | frozen split, fixed models, fixed budget | fixed by budget | stable ranking and trace completeness | high | insufficient signal |
| R010 | release | B5 feedback ablation. | same split/model, feedback modes | fixed by budget | structured feedback effect measurable | high | no difference |
| R011 | release | B6 layer/backend ablation. | bytecode-only vs kop-enabled | fixed by budget | at least one non-kop track valid | medium | adapter gaps |

All benchmark execution must use `make <target>` entrypoints. Analysis scripts may run post-hoc over raw artifacts.

## Tracker Handoff

- Tracker destination if persisted: `docs/research/bpfoptbench-experiment-tracker.md`.
- Result path convention: `corpus/results/<platform_arch>_corpus_<timestamp>/` plus `docs/tmp/bpfoptbench/<run-id>/` for analysis outputs.
- Required tracker columns: Run ID, Claim, Block, Purpose, Command/config, Commit, Machine, App subset, Pass/action space, Agent/model, Attempt budget, Oracle, Decision gate, Result path, Status.
- Next rows to add: R001-R006 after the task schema is frozen.

## Prompt And Agent Design

Borrow the hygiene from the verifier-repair project:

- Freeze prompt manifests with prompt hash, task split hash, model/toolchain versions, and dirty-worktree status.
- Separate raw-log prompts from structured-feedback prompts.
- Record every action, rejected action, run command/config, result path, and final decision.
- Keep a hidden oracle for heldout tasks; do not let the prompt include post-hoc answer tables for heldout runs.
- Report failed cases, not only successful optimizations.

Suggested first prompt modes:

| Mode | Agent sees | Agent can do | Purpose |
|---|---|---|---|
| M0 one-shot raw | raw historical snippets/result logs | propose one pass policy | baseline prompt |
| M1 structured one-shot | normalized task summary, app/pass/history fields | propose one policy | feedback-format ablation |
| M2 closed-loop | structured result after each attempt | propose next action within budget | main agent benchmark |
| M3 expert seeded | structured feedback plus concise optimization-space guide | propose next action | upper-bound prompt engineering |

## Result Presentation

The paper should present BPFOptBench as the main artifact, not as a claim that the current optimizer already wins everywhere.

Recommended figures/tables:

| Artifact | Message |
|---|---|
| Fig. 1 benchmark loop | Agent observes feedback, proposes an action, executor runs app-level benchmark, verifier/JIT/workload oracle returns feedback. |
| Table 1 optimization space | Source, LLVM, pre-load bytecode, live bytecode, kernel/JIT/kop layers and their oracles. |
| Fig. 2 historical difficulty | Noop floors, static-policy instability, and applied-count mismatch. |
| Table 2 failure taxonomy | Verifier rejection, app failure, workload failure, no performance signal, regression, noise chasing. |
| Fig. 3 scoreboard | Agent/baseline success, geomean ratio, regret, cost. |
| Fig. 4 feedback ablation | Raw vs structured vs closed-loop feedback. |
| Table 3 backend ablation | Bytecode-only vs kop-enabled, optional adapter smoke. |
| Table 4 integrity audit | Workload mutation, run-budget changes, protected-path edits, loader bypass, and result-provenance failures. |

Possible title:

> BPFOptBench: Benchmarking Agentic Optimization of Existing eBPF Programs

The name is reasonable. It signals "optimization benchmark" and connects to the existing `bpfopt` component. The risk is that readers may think BPFOptBench is itself an optimizer. The subtitle should always say "benchmarking agentic optimization" or "a benchmark for eBPF optimization agents."

## Reproducibility

- Hardware/software versions: record kernel fork, LLVM/Clang, libbpf, architecture, platform, app versions, kop module versions.
- Seeds/repetitions: freeze agent seeds where available; benchmark performance should follow the existing corpus methodology rather than increasing samples ad hoc.
- Workload generation: use existing corpus workload drivers and raw workload fields.
- Data/traces: preserve raw `result.json`, app payloads, stdout/stderr, verifier logs, pass reports, prompt manifests, and agent action traces.
- Scripts/configs: benchmark framework collects raw counters only; all ratios/geomeans/tables are post-hoc analysis artifacts.
- Result file paths: every claimed number must cite a result directory or analysis output.

## Residual Uncertainty

- Source-level and LLVM-backend optimization are part of the optimization space, but not first-paper evidence unless adapters are implemented and evaluated.
- With fewer than roughly 30 audited tasks, BPFOptBench should be framed as a vertical-slice testbed, not a mature standalone benchmark. A stronger benchmark paper needs 80-150 expert-audited tasks plus public/private or rotating holdout splits.
- Historical commits are useful task candidates, but AI-authored historical patches and public GitHub history make them unsuitable as unqualified gold solutions. Scoring should use independent hidden oracles, not patch matching.
- Branch-flip should remain out of default policy until real per-site PMU profile data is available.
- Historical pass data is useful motivation but may be stale after v3 architecture changes; current-code floor and static-policy checks are needed before final numbers.
- Agent wins may be modest or absent. That does not kill the benchmark paper, but it changes the contribution from "agents optimize eBPF" to "BPFOptBench exposes why current agents struggle."
- Tail-call accounting can hide optimized tail targets unless caller attribution is handled correctly.

## Claim Gate After Results

| Claim | Evidence file(s) | Verdict | Supported wording |
|-------|------------------|---------|-------------------|
| C1 | task schema, trace examples, replay outputs | planned | "BPFOptBench defines and instantiates a closed-loop benchmark interface." |
| C2 | historical reports plus refreshed floors if needed | partial | "Existing data shows noisy, workload-specific, policy-sensitive optimization behavior." |
| C3 | failure taxonomy output | planned | "A composed oracle is necessary to avoid false success." |
| C4 | agent scoreboard | unsupported until run | "Agents can/cannot outperform static and random baselines under this budget." |
| C5 | feedback ablation | unsupported until run | "Structured feedback improves/does not improve agent decisions in this setting." |
| C6 | backend/layer ablation | planned | "The benchmark is independent of kop in design and includes at least one non-kop task track." |
| C7 | integrity audit and hidden evaluator replay | planned | "BPFOptBench detects invalid benchmark manipulation under performance incentives." |
