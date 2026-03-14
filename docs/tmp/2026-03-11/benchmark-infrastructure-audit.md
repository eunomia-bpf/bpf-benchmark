# Benchmark Infrastructure Audit

Date: 2026-03-10

This document audits the current benchmark stack around `micro_exec`, `run_micro.py`, the shared scanner library, the corpus tooling, and the ad hoc VM/test scripts. It is based on the current repository state, with `docs/kernel-jit-optimization-plan.md` treated as the design source of truth and the code used to determine what is actually implemented today.

## 1. Current Inventory

### 1.1 Scope snapshot

- Micro benchmark configs:
  - `config/micro_pure_jit.yaml`: 51 configured benchmarks
  - `config/micro_runtime.yaml`: 11 configured benchmarks
- Micro program artifacts on disk:
  - `micro/programs/*.bpf.c`: 62
  - `micro/programs/*.bpf.o`: 62
- Corpus objects currently visible to `micro/directive_census.py`:
  - `EM_BPF` corpus objects: 36
  - skipped non-BPF `.bpf.o` artifacts: 4
- Current result sprawl:
  - `micro/results/`: mixed suite JSON, manual JSON, and Markdown analyses
  - `corpus/results/`: corpus JSON and Markdown outputs
  - `docs/tmp/`: design docs, ad hoc VM reports, fixed-baseline JSONL logs, and scratch outputs

### 1.2 Lowest-level execution primitives

The real execution primitive is not `run_micro.py`; it is `micro_exec`.

#### `micro_exec` CLI surfaces

`micro/runner/src/main.cpp` exposes exactly three subcommands:

1. `list-programs`
2. `run-llvmbpf`
3. `run-kernel`

`micro/runner/src/common.cpp` hand-parses the full flag surface. The important point for consolidation is that `run-kernel` currently contains multiple benchmark and policy modes hidden behind boolean flags.

#### `micro_exec list-programs`

Role:

- Enumerates libbpf-visible programs inside an ELF object
- Used heavily by corpus tools to expand multi-program objects into per-program runs

Inputs:

- `--program <object>`

Output:

- JSON array of `{name, section_name, insn_count}`

Current users:

- `corpus/run_real_world_code_size.py`
- `micro/run_corpus_perf.py`
- manual corpus workflows

#### `micro_exec run-llvmbpf`

Role:

- Loads BPF bytecode into `bpftime::llvmbpf_vm`
- Supports `map`, `staged`, and `packet` I/O modes
- Supports LLVM/JIT tuning flags such as `--opt-level`, `--no-cmov`, `--llvm-disable-pass`, and `--llvm-log-passes`
- Supports `--compile-only` and `--dump-jit`

Output:

- One JSON object per invocation with compile/exec timing, result, code size, perf counters, and phase timings

Important constraint:

- This path is purely userspace and is not policy-aware. It is a backend baseline or upper bound, not part of the kernel recompile framework.

#### `micro_exec run-kernel`

`run-kernel` is not one mode. It is a family of modes:

1. Stock kernel load + `BPF_PROG_TEST_RUN`
2. Manual load path via `--manual-load`
3. Load-time directive path via `--directive-blob`
4. Post-load recompile via `--policy-blob`
5. v4 auto-scan recompile via `--recompile-*`
6. v5 declarative auto-scan recompile via `--recompile-v5`
7. Inspection modifiers via `--compile-only` and `--dump-jit`

More concretely, the currently implemented kernel-side user-visible modes are:

| Mode | How it is selected | What it does |
| --- | --- | --- |
| Stock kernel run | `run-kernel` with no directive/recompile flags | `bpf_object__load()` + `bpf_prog_test_run_opts()` |
| Manual load only | `--manual-load` | Reconstructs `program_image` and issues raw `BPF_PROG_LOAD` |
| Load-time directives | `--directive-blob` | Seals a directive memfd and passes `jit_directives_fd` during manual `BPF_PROG_LOAD` |
| Prebuilt recompile policy | `--policy-blob` | Reads a blob, patches `insn_cnt`/`prog_tag`, then calls `BPF_PROG_JIT_RECOMPILE` |
| v4 auto-scan recompile | `--recompile-cmov`, `--recompile-wide`, `--recompile-rotate`, `--recompile-rotate-rorx`, `--recompile-lea`, `--recompile-all` | Dumps xlated bytecode, runs v4 scanners, builds a v1 blob, applies `BPF_PROG_JIT_RECOMPILE` |
| v5 auto-scan recompile | `--recompile-v5` plus rotate/wide/lea flags | Uses runner-local declarative pattern matching, builds a v2 blob, applies `BPF_PROG_JIT_RECOMPILE` |
| Compile-only inspect | `--compile-only` | Returns after load/JIT/recompile, without execution |
| JIT dump | `--dump-jit` | Writes `<bench>.kernel.bin` |

Important implementation detail:

- v4 low-level matching is now sourced from the shared `scanner/` library.
- v5 matching and v2 blob building still live only inside `micro/runner/src/kernel_runner.cpp`.

### 1.3 Shared scanner surfaces

The `scanner/` tree now exists as a separate library/toolchain:

- `scanner/include/bpf_jit_scanner/`
- `scanner/src/`
- `scanner/examples/`
- `scanner/tests/`
- standalone `scanner/README.md`

It provides two layers.

#### Low-level C layer

Files:

- `scanner/include/bpf_jit_scanner/scanner.h`
- `scanner/include/bpf_jit_scanner/policy.h`
- `scanner/include/bpf_jit_scanner/types.h`
- `scanner/src/scanner.cpp`
- `scanner/src/policy.cpp`

Capabilities:

- v4 family scanners: `cmov`, `wide_mem`, `rotate`, `addr_calc`
- v1 policy blob serialization and patching

#### Higher-level C++ policy layer

Files:

- `scanner/include/bpf_jit_scanner/engine.hpp`
- `scanner/src/engine.cpp`
- `scanner/src/cli.cpp`

Capabilities:

- Pattern registry
- site feature extraction
- overlap arbitration
- config defaults and overrides
- placeholder profile-provider hook
- standalone CLI

#### `bpf-jit-scanner` CLI modes

The standalone scanner binary exposes:

1. `scan`
2. `apply`
3. `dump`

Behavior:

- `scan` and `apply` both run `scan -> decide -> materialize`
- `apply` then seals a blob memfd and calls `BPF_PROG_JIT_RECOMPILE`
- `dump` writes xlated bytecode

Key limitation today:

- The standalone scanner owns the richer policy pipeline for v4, but `micro_exec run-kernel --recompile-*` does not call that pipeline. It calls the low-level scanners directly and skips arbitration, config-driven choices, and profile hooks.
- The standalone scanner has no v5 equivalent today.

### 1.4 High-level orchestrators and benchmark drivers

These are the actual user-facing benchmark entry points above `micro_exec`.

#### Micro suite driver: `micro/run_micro.py`

Role:

- Main declarative suite orchestrator for micro benchmarks
- Loads `config/micro_pure_jit.yaml` by default, or a different suite via `--suite`
- Builds `micro_exec` and benchmark objects
- Generates inputs through `micro/input_generators.py`
- Runs `llvmbpf` and `kernel`
- Counterbalances runtime order across iterations
- Writes suite-level JSON under `micro/results/`

Current limitations:

- The suite schema only models two runtime kinds: `llvmbpf` and `kernel`
- `resolve_helper_command()` has no concept of stock vs v4 vs v5 vs fixed-baseline kernel modes
- Comparison logic is still hard-coded around `llvmbpf` vs `kernel`
- It has no VM transport abstraction

#### LLVM pass ablation: `micro/run_pass_ablation.py`

Role:

- Separate llvmbpf-only experiment driver
- Disables specific LLVM passes and compares code size and exec time

Why it matters:

- It reimplements much of `run_micro.py` command building, result parsing, host metadata capture, and JSON/Markdown writing
- It is a second orchestrator, not a small extension of the first one

#### Corpus kernel stock vs recompile-all: `micro/run_corpus_perf.py`

Role:

- Runs real-world corpus objects through `micro_exec run-kernel`
- Compares stock kernel vs `--recompile-all`
- Uses `micro/directive_census.py` discovery/filtering
- Writes JSON and Markdown to `docs/tmp/`

Important limitations:

- kernel only
- only `stock` vs `recompile-all`
- no llvmbpf comparison
- no per-family or v4/v5 mode matrix
- no VM abstraction

#### JIT dump pipeline: `micro/dump_all_jit.sh` + `micro/archive/scripts/analyze_jit.py`

Role:

- `dump_all_jit.sh` iterates the pure-JIT suite and runs both `run-llvmbpf` and `run-kernel` with `--dump-jit`
- `micro/archive/scripts/analyze_jit.py` consumes disassembly dumps from `micro/jit-dumps`

This is a distinct analysis pipeline outside `run_micro.py`.

### 1.5 Corpus-specific execution and discovery tools

These are not integrated into the micro suite config model.

#### Corpus fetch/config tooling

Files:

- `config/macro_corpus.yaml`
- `corpus/fetch_real_world_corpus.py`
- `corpus/fetch_bcf_dataset.py`

Current state:

- `config/macro_corpus.yaml` contains only manifest/inventory paths
- it is used for fetching/inventorying corpus sources
- it is not a runnable benchmark experiment config

#### `corpus/batch_run.py`

Role:

- Batch-runs BCF manifest entries through `micro_exec`
- runtime choices: `llvmbpf` and/or `kernel`
- packet mode only
- `repeat = 1`
- fixed timeout and input size

This is a separate corpus executor with its own schema and defaults.

#### `corpus/run_real_world_code_size.py`

Role:

- Compiles curated real-world `.bpf.c` sources or uses prebuilt `.o` files
- expands multi-program objects via `list-programs`
- runs `run-llvmbpf` and `run-kernel` in `--compile-only`
- records per-program native code size

This is really a compile-only inspection pipeline, not an execution pipeline.

#### `corpus/run_real_world_exec_time.py`

Role:

- Takes paired programs from `real_world_code_size.json`
- runs actual execution-time measurements over `packet` mode with a generated valid packet
- kernel first, llvmbpf second

Important observation:

- The exec-time pipeline is chained to the compile-only pipeline through a JSON artifact, not through a shared experiment model.

#### `corpus/analyze_bytecode.py`

Role:

- Static bytecode feature analysis over the BCF corpus
- outputs `bytecode_features.json` and `helper_pareto.json`

This is part of the representativeness/static-analysis layer, not execution.

### 1.6 Static analysis and reporting scripts

These consume benchmark outputs but do not execute benchmarks directly:

- `micro/archive/scripts/analyze_statistics.py`
- `micro/archive/scripts/analyze_stability.py`
- `micro/archive/scripts/analyze_pmu.py`
- `micro/archive/scripts/analyze_performance_deep.py`
- `micro/archive/scripts/analyze_paradox.py`
- `micro/archive/scripts/analyze_representativeness.py`
- `micro/generate_figures.py`
- `micro/compute_combined_40_summary.py`
- `micro/summarize_rq.py`

This matters because the output schemas they consume are already part of the infrastructure contract. Any consolidation has to either preserve or migrate those schemas.

### 1.7 Static directive census

`micro/directive_census.py` is its own benchmark-adjacent mode.

Role:

- scans `micro/programs/*.bpf.o` and `corpus/**/*.bpf.o`
- matches candidate directive sites in raw executable ELF sections
- emits Markdown coverage reports

Important semantic constraint:

- it is a raw ELF candidate census, not an xlated-program acceptance measurement
- it explicitly says it is not a substitute for actual kernel acceptance

### 1.8 VM and ad hoc test paths

There is no reusable VM orchestration layer in code today. VM execution exists mainly as:

1. documented `vng --run ... --exec "micro_exec run-kernel ..."` command lines in `docs/tmp/`
2. ad hoc helper scripts:
   - `docs/tmp/run_poc_validation_in_vm.py`
   - `docs/tmp/run_poc_v2_validation.py`

The plan document also describes VM worktrees and manual `vng` usage, but there is no canonical Python module that turns a named kernel variant into a reproducible VM benchmark run.

## 2. Duplication and Inconsistency Map

### 2.1 Scanner ownership is only partially consolidated

What is improved:

- v4 low-level scanners now live in `scanner/src/scanner.cpp`
- the micro runner links against `scanner/`

What is still duplicated or split:

1. `micro/directive_census.py` reimplements the scanner matchers in Python
2. `micro_exec run-kernel --recompile-*` bypasses `PolicyEngine` and directly concatenates raw `bpf_jit_scan_rule`s
3. `micro_exec` still carries runner-local v5 scanning, descriptor definitions, and v2 blob serialization
4. policy memfd creation and raw `BPF_PROG_JIT_RECOMPILE` issuance are duplicated between `scanner/src/cli.cpp` and `micro/runner/src/kernel_runner.cpp`

Net result:

- v4 low-level matching is centralized
- v4 policy selection is not centralized
- v5 is not centralized at all

### 2.2 v4 and v5 are two different infrastructures, not two configurations

Current reality:

- v4 is represented by shared C scanners + v1 blob builder + optional C++ `PolicyEngine`
- v5 is represented by runner-local declarative pattern tables + v2 blob builder

Consequences:

- `scanner` CLI cannot generate or apply v5 policies
- `run_micro.py` cannot describe v5 as a first-class runtime mode
- v5 comparisons are necessarily ad hoc/manual
- there is no common result schema for “policy decision” across v4 and v5

### 2.3 `run_micro.py` and the corpus drivers are parallel orchestration stacks

`micro/run_micro.py`, `micro/run_pass_ablation.py`, `micro/run_corpus_perf.py`, `corpus/batch_run.py`, `corpus/run_real_world_code_size.py`, and `corpus/run_real_world_exec_time.py` all independently do some subset of:

- ensuring `micro_exec` exists
- building commands for `run-llvmbpf` / `run-kernel`
- parsing the last JSON line
- collecting host metadata
- doing timeout/error handling
- writing custom JSON/Markdown schemas

This is the main consolidation problem above the scanner layer.

### 2.4 YAML configuration is only used for micro suites

`micro/benchmark_catalog.py` only knows:

- toolchains
- build commands
- defaults
- runtimes with `{name, label, mode, repeat, sudo, aliases}`
- micro benchmark definitions

What it cannot model:

- kernel stock vs v4 vs v5 vs fixed-baseline modes
- kernel image/worktree selection
- VM transport
- policy families or policy blobs
- corpus discovery
- compile-only inspection stages
- comparison matrices across more than the hard-coded `llvmbpf` vs `kernel`

`config/macro_corpus.yaml` is not the answer here; it is a fetch/inventory config, not a benchmark config.

### 2.5 Static candidate census and actual execution are disconnected

Current layers:

1. `directive_census.py`: raw ELF candidate counts
2. `scanner` CLI / runner recompile scan: xlated-program candidate sites
3. `run-kernel` recompile: actual kernel policy application attempt
4. benchmark executors: actual performance/correctness measurements

What is missing is a shared chain of evidence from:

- candidate site
- decision
- emitted policy rule
- accepted/applied rule
- execution impact

Today each stage writes a different format and often a different schema.

### 2.6 Result storage and schemas are fragmented

Current formats in active use:

- `micro_exec`: one JSON object per invocation
- `run_micro.py`: suite JSON
- `run_pass_ablation.py`: custom JSON + custom Markdown
- `run_corpus_perf.py`: custom JSON + custom Markdown
- `corpus/run_real_world_code_size.py`: custom JSON + custom Markdown
- `corpus/run_real_world_exec_time.py`: custom JSON + custom Markdown
- `directive_census.py`: Markdown only
- `bpf-jit-scanner`: human-readable table, optional binary blob, no machine-readable text output
- `docs/tmp/kernel-fixed-baselines-*.jsonl`: raw manual sweep logs
- `micro/results/v4_recompile_scan.json`: list schema
- `micro/results/v4_new_directives_test.json`: bespoke report schema

This is more than stylistic inconsistency. It means downstream tooling cannot assume a canonical raw-sample format, canonical summary format, or canonical comparison format.

### 2.7 VM execution is still manual and documentation-driven

The plan document and `docs/tmp/` reports describe:

- kernel worktrees
- `vng --run ... --exec ...`
- `--rwdir` persistence issues
- custom kernel branch selection

But there is no code-level abstraction for:

- “run this experiment on `vendor/linux-framework`”
- “run this same matrix on `vendor/linux-baseline`”
- “record which kernel image and branch produced these results”

This is why VM results currently show up as isolated bespoke JSON files and Markdown notes instead of first-class experiment outputs.

### 2.8 Fixed baselines are outside the config and tool model

The plan clearly treats fixed-kernel baselines as a required comparison dimension, but the current benchmark config and runner model cannot represent them.

Current reality:

- fixed baselines exist as separate kernel worktrees / configs
- results are stored as JSONL logs in `docs/tmp/`
- comparisons are written up manually in Markdown

They are therefore not a runnable “mode” in the current micro suite infrastructure, even though they are a required mode in the evaluation story.

## 3. Gap Analysis

### 3.1 Missing unified comparison matrix

There is no first-class way to say:

- run `llvmbpf`
- run kernel stock
- run kernel v4 auto-scan
- run kernel v5 auto-scan
- run kernel with a prebuilt policy blob
- run kernel fixed baselines
- compare all of them over the same benchmark set and environment

The closest current approximation is manual command assembly plus bespoke JSON/Markdown.

### 3.2 Missing environment/kernel abstraction

There is no reusable config model for:

- host kernel vs VM kernel
- stock upstream vs framework kernel vs fixed-baseline kernel
- named worktrees or bzImage paths
- `vng` options and writable directories

This is the main reason VM evaluation is still ad hoc.

### 3.3 Missing shared policy pipeline

Needed but absent:

- one scanner/policy implementation that owns both v4 and v5
- one way to emit machine-readable decisions, conflicts, and materialized rules
- one shared apply/patch helper reused by runner and scanner CLI

Today the richer policy pipeline lives in `scanner`, while the active low-level execution path lives in `micro_exec`.

### 3.4 Missing corpus execution framework

Today the repo has three separate corpus execution paths:

1. `corpus/batch_run.py`
2. `corpus/run_real_world_code_size.py`
3. `corpus/run_real_world_exec_time.py`

Plus a fourth hybrid path:

4. `micro/run_corpus_perf.py`

What is missing is a single corpus pipeline with explicit stages:

- discover artifacts
- expand multi-program objects
- inspect compile-only
- scan candidates
- attempt kernel acceptance
- execute if attach/test-run compatible

### 3.5 Missing rigorous experiment profiles

There are fragments of rigor in the current code:

- `run_micro.py` captures governor/turbo state
- it can pin to a CPU
- it counterbalances runtime order
- it can collect perf counters

But the methodology is not encoded as reusable experiment profiles. Missing first-class knobs include:

- smoke vs authoritative vs VM-smoke vs corpus-scan profiles
- required CPU affinity / isolation
- hard failure on bad governor/turbo state for rigorous runs
- unified warmup/iteration/repeat policies across all drivers
- shared statistical post-processing contract

### 3.6 Missing reproducibility packaging

A reproducible run should automatically capture:

- repo git SHA
- kernel worktree or image path
- kernel branch / commit
- scanner engine version
- policy blob hash
- full command line
- environment metadata
- raw samples

Some scripts capture parts of this, but there is no canonical run manifest or replay command.

### 3.7 Missing clean separation between raw candidate coverage and accepted execution

The paper plan requires both breadth and actual accepted/runtime evidence, but current tooling conflates or disconnects them:

- raw ELF census is broad but not authoritative for acceptance
- compile-only corpus code-size runs are broad but not execution
- execution-time corpus runs are narrower and chained off prior JSON
- scanner decisions and kernel-applied rules are not stored in a shared machine-readable way

## 4. Proposed Unified Architecture

### 4.1 Recommended control model

The infrastructure should be split into four explicit layers:

1. Executor layer
2. Policy layer
3. Orchestration layer
4. Results/reporting layer

#### Executor layer

Keep `micro_exec` as the low-level executor for:

- `list-programs`
- `run-llvmbpf`
- `run-kernel`
- `--compile-only`
- `--dump-jit`

But stop treating it as a user-facing experiment driver. It should become the stable internal engine used by the orchestrator.

#### Policy layer

Make `scanner/` the single owner of:

- v4 scanners
- v5 declarative scanners
- policy decisions and arbitration
- blob serialization
- blob patching
- policy application helper

That means moving the v5-specific code out of `micro/runner/src/kernel_runner.cpp` and into `scanner/`.

#### Orchestration layer

Add one canonical top-level driver for all benchmark scenarios.

Recommended path:

- add a new top-level Python package, for example `bench/`
- add a new canonical CLI, for example `python3 bench/run.py`

Do not make `micro_exec` the single entry point. It is too low-level.

Do not keep `micro/run_micro.py` as the canonical name. The name is already wrong once corpus, VM, and fixed-baseline runs are included.

Recommended user-facing subcommands:

1. `run`
2. `list`
3. `scan`
4. `compare`
5. `report`

Compatibility wrappers can remain:

- `micro/run_micro.py`
- `micro/run_corpus_perf.py`
- `corpus/run_real_world_code_size.py`
- `corpus/run_real_world_exec_time.py`

But they should become thin shims over the new driver.

### 4.2 Recommended YAML model

The current suite YAML model is too narrow. The consolidated model should have separate concepts for:

1. program sets
2. environments
3. modes
4. measurement profiles
5. experiments

#### Program sets

Represent what is being measured:

- micro pure-JIT suite
- micro runtime suite
- curated corpus sources
- prebuilt BCF objects
- expanded per-program manifests from `list-programs`

#### Environments

Represent where kernel code runs:

- current host kernel
- VM with stock kernel image
- VM with framework kernel image
- VM with fixed-baseline kernel image

#### Modes

Represent what backend/policy configuration is being compared:

- `llvmbpf-o3`
- `kernel-stock`
- `kernel-v4-cmov`
- `kernel-v4-all`
- `kernel-v5-rotate-rorx`
- `kernel-policy-blob`
- `fixed-all`
- `fixed-cmov`

Important rule:

- fixed baselines should be represented as modes whose `policy.kind` is `none` but whose `environment` points at a fixed-baseline kernel image/worktree
- fixed baselines are not a userspace recompile mode; they are a kernel-environment variant

#### Measurement profiles

Represent rigor level:

- `smoke`
- `default`
- `authoritative`
- `vm-smoke`
- `corpus-compile-only`
- `corpus-exec`

These should hold:

- iterations
- warmups
- repeat
- CPU pinning requirements
- perf counter requirements
- environment strictness
- ordering/randomization policy

#### Experiment objects

Represent the actual runnable matrix:

- program set
- mode set
- environment set
- measurement profile
- comparison pairs/groups

#### Example

```yaml
program_set:
  kind: suite
  path: config/micro_pure_jit.yaml

environments:
  host-current:
    transport: host

  vm-framework:
    transport: vng
    kernel_image: vendor/linux-framework/arch/x86/boot/bzImage
    cwd: /home/yunwei37/workspace/bpf-benchmark
    rwdirs: [micro/results, tmp]

  vm-fixed-all:
    transport: vng
    kernel_image: vendor/linux/arch/x86/boot/bzImage
    cwd: /home/yunwei37/workspace/bpf-benchmark
    rwdirs: [micro/results, tmp]

modes:
  llvmbpf-o3:
    runner: llvmbpf

  kernel-stock:
    runner: kernel
    environment: host-current
    policy:
      kind: none

  kernel-v4-all:
    runner: kernel
    environment: vm-framework
    policy:
      kind: auto
      engine: v4
      families: [cmov, wide-mem, rotate, lea]

  kernel-v5-rotate-rorx:
    runner: kernel
    environment: vm-framework
    policy:
      kind: auto
      engine: v5
      families: [rotate]
      rotate_choice: rorx

  fixed-all:
    runner: kernel
    environment: vm-fixed-all
    policy:
      kind: none

measurement:
  profile: authoritative
  cpu: 2
  iterations: 30
  warmups: 3
  repeat: 1000

comparisons:
  - [llvmbpf-o3, kernel-stock]
  - [kernel-stock, kernel-v4-all]
  - [kernel-v4-all, fixed-all]
```

### 4.3 Recommended VM kernel selection model

VM selection should be an environment concern, not a script concern.

Add an environment abstraction with:

- `transport: host | vng`
- `kernel_image`
- `kernel_label`
- `kernel_branch`
- `kernel_commit`
- `cwd`
- `rwdirs`
- optional `command_prefix`

The orchestrator should be responsible for wrapping `micro_exec` invocations in `vng --run ... --exec ...` when the environment requires it.

This replaces:

- manual docs/tmp commands
- ad hoc VM helper scripts
- implicit assumptions in Markdown notes

### 4.4 Recommended scanner integration

#### Make scanner the only policy owner

Concrete direction:

- move v5 pattern structs, descriptors, scan logic, and v2 blob serialization out of `micro/runner/src/kernel_runner.cpp`
- add them under `scanner/`, for example:
  - `scanner/include/bpf_jit_scanner/v5.hpp`
  - `scanner/src/v5.cpp`
  - or integrate them into `engine.cpp` with a clean split

#### Make runner call the full scanner engine

`micro_exec run-kernel` should not directly call `bpf_jit_scan_*` for auto modes. Instead it should call a shared scanner API that does:

1. family scanning
2. overlap arbitration
3. config/default/profile policy choice
4. materialization
5. blob serialization

This keeps the richer policy flow on the actual execution path.

#### Add machine-readable scanner output

`bpf-jit-scanner` should gain a JSON output mode with at least:

- raw candidate sites
- merged sites
- overlap conflicts
- decisions
- materialized rules
- blob metadata

This is needed both for reproducibility and for joining scan decisions with execution results.

#### Add an offline object-scan path

To eliminate Python matcher duplication in `micro/directive_census.py`, add an offline scanner mode that can consume ELF objects directly and emit machine-readable results.

Recommended options:

- `bpf-jit-scanner scan-elf --object foo.bpf.o --format json`
- or a library API that `directive_census.py` can call through bindings

The simpler near-term approach is a CLI mode plus JSON output. Then `directive_census.py` becomes a report renderer, not a second matcher implementation.

### 4.5 Recommended `micro_exec` CLI cleanup

The current boolean flag surface is too fragmented. Replace the cluster of `--recompile-*` booleans with a structured policy description.

Recommended direction:

- keep `--policy-blob` for explicit blob application
- keep `--directive-blob` only as a legacy/debug load-time path
- replace:
  - `--recompile-cmov`
  - `--recompile-wide`
  - `--recompile-rotate`
  - `--recompile-rotate-rorx`
  - `--recompile-lea`
  - `--recompile-all`
  - `--recompile-v5`
- with something like:
  - `--policy-mode stock|auto|blob`
  - `--policy-engine v4|v5`
  - `--policy-families cmov,wide-mem,rotate,lea`
  - `--rotate-choice ror|rorx`
  - `--policy-config <yaml>`

This makes the CLI easier for the new orchestrator to generate and easier for YAML to represent.

### 4.6 Recommended result model

Use one canonical result directory shape for all experiment runs:

```text
results/
  <experiment-name>/
    <timestamp>/
      manifest.json
      samples.jsonl
      scan_decisions.jsonl
      summary.json
      summary.md
      logs/
```

#### `manifest.json`

Should contain:

- experiment config snapshot
- git SHA
- environment metadata
- kernel image/worktree metadata
- measurement profile
- full generated commands

#### `samples.jsonl`

One row per:

- benchmark/program
- mode
- environment
- iteration

Fields should include:

- compile/exec timing
- code size
- correctness result
- timing source
- perf counters
- policy blob hash
- whether recompile was applied

#### `scan_decisions.jsonl`

One row per candidate/decision with:

- family
- site_start
- site_len
- engine version
- decision source
- native choice
- overlap/arbitration status
- materialized/applied status

This is the missing bridge between static analysis and runtime measurement.

#### `summary.json`

Aggregated benchmark/mode summaries used by all downstream reporting.

#### `summary.md`

Human-readable rendering generated from `summary.json`, not hand-authored by separate scripts.

### 4.7 Recommended corpus integration model

Corpus programs should become a first-class program-set provider with explicit stages.

#### Stage 1: acquisition

Keep:

- `corpus/fetch_real_world_corpus.py`
- `corpus/fetch_bcf_dataset.py`

These are acquisition utilities, not measurement utilities.

#### Stage 2: discovery

Create a canonical per-program manifest by:

- locating source or object artifacts
- expanding them via `micro_exec list-programs`
- recording program name, section name, instruction count, kind, and compatibility

#### Stage 3: compile-only inspection

Run `run-llvmbpf` / `run-kernel --compile-only` through the unified driver.

This replaces the current dedicated `run_real_world_code_size.py` special case.

#### Stage 4: scan and acceptance

Run scanner candidate/decision collection and compile-only recompile acceptance measurements through the same driver.

#### Stage 5: execution

Only for programs that are execution-compatible:

- `BPF_PROG_TEST_RUN` compatible packet paths
- map/staged paths where applicable

Longer-term, a separate live-attach environment type can be added for end-to-end deployment evaluation.

## 5. Concrete File and Module Changes

### 5.1 New modules to add

Recommended new top-level package:

- `bench/catalog.py`
- `bench/cli.py`
- `bench/orchestrator.py`
- `bench/environments.py`
- `bench/modes.py`
- `bench/corpus.py`
- `bench/results.py`
- `bench/reporting.py`

### 5.2 Existing modules to refactor

#### `micro/benchmark_catalog.py`

Current role:

- micro-only suite loader

Recommended action:

- supersede with `bench/catalog.py`
- keep `micro/benchmark_catalog.py` as a compatibility wrapper for existing micro analysis scripts

#### `micro/run_micro.py`

Recommended action:

- migrate main logic into `bench/orchestrator.py`
- keep `micro/run_micro.py` as a thin compatibility entry point for the pure-JIT/runtime micro suites

#### `micro/run_pass_ablation.py`

Recommended action:

- port onto shared orchestration helpers
- keep pass-ablation-specific comparison/report logic only

#### `micro/run_corpus_perf.py`

Recommended action:

- fold into the unified corpus execution pipeline
- deprecate as a standalone driver once the new corpus stage model exists

#### `corpus/run_real_world_code_size.py`

Recommended action:

- split into:
  - corpus discovery/build helpers reusable by the driver
  - a compatibility wrapper that invokes the shared driver in compile-only mode

#### `corpus/run_real_world_exec_time.py`

Recommended action:

- fold packet generation, timing loop, and paired-program loading into the shared corpus execution stage

### 5.3 Runner/scanner ownership changes

#### `micro/runner/src/kernel_runner.cpp`

Recommended action:

- remove inline v5 policy structures and matching code
- stop doing direct low-level v4 scan concatenation
- call shared scanner APIs for all auto-policy modes
- reuse shared blob patch/apply helpers

#### `micro/runner/src/common.cpp` and `micro/runner/include/micro_exec.hpp`

Recommended action:

- replace boolean `recompile_*` flags with structured policy-mode fields

#### `scanner/src/engine.cpp`, `scanner/src/cli.cpp`, `scanner/src/policy.cpp`

Recommended action:

- absorb v5
- add JSON output
- expose shared apply helper
- add offline object-scan support

#### `micro/directive_census.py`

Recommended action:

- remove embedded matcher logic
- consume scanner JSON output instead
- keep only census aggregation/report rendering in Python

## 6. Priority-Ordered Implementation Plan

### P0: Make scanner the single policy implementation

1. Move v5 logic out of `kernel_runner.cpp` and into `scanner/`.
2. Add a shared “scan -> decide -> materialize -> serialize/apply” API used by both the scanner CLI and `micro_exec`.
3. Add scanner JSON output for candidates, conflicts, and decisions.

Why first:

- Without this, the orchestrator would still be papering over two different policy stacks.

### P1: Introduce a unified catalog and driver

1. Add `bench/catalog.py` and the new config schema.
2. Add `bench/cli.py` / `bench/orchestrator.py`.
3. Port `micro/run_micro.py` to the new driver first.

Why second:

- Micro suites are already the cleanest declarative entry point and are the safest migration target.

### P2: Normalize the `micro_exec` policy CLI

1. Replace the current `--recompile-*` boolean sprawl with structured policy options.
2. Keep legacy flags temporarily as compatibility aliases.

Why third:

- The new driver needs a stable low-level contract before the corpus and VM layers are migrated.

### P3: Add environment and VM abstractions

1. Add named host/VM environments in config.
2. Implement a `vng` wrapper in the driver.
3. Bring framework-kernel and fixed-baseline-kernel runs under the same result schema.

Why fourth:

- This removes the biggest remaining source of ad hoc manual experimentation.

### P4: Fold corpus workflows into the unified pipeline

1. Create canonical corpus discovery manifests.
2. Port compile-only inspection.
3. Port execution-time runs.
4. Port stock vs recompile corpus runs.

Why fifth:

- The corpus side currently has the most script sprawl, but it will be much easier to unify once the driver, environments, and policy layer are stable.

### P5: Replace duplicated static-analysis logic

1. Convert `directive_census.py` into a scanner-result renderer.
2. Standardize static analysis outputs into the unified result tree.

Why sixth:

- This removes the last major logic duplication and closes the raw-candidate vs accepted-execution gap.

### P6: Retire or wrap legacy scripts

Keep compatibility wrappers for one transition window:

- `micro/run_micro.py`
- `micro/run_pass_ablation.py`
- `micro/run_corpus_perf.py`
- `corpus/run_real_world_code_size.py`
- `corpus/run_real_world_exec_time.py`

But move the real implementation behind the shared driver.

## 7. Bottom Line

The repo no longer has one benchmark infrastructure. It has:

- one low-level executor (`micro_exec`)
- one partially centralized policy library (`scanner/`)
- one micro suite runner (`run_micro.py`)
- multiple parallel corpus runners
- multiple static/reporting pipelines
- manual VM and fixed-baseline workflows outside the config model

The right consolidation target is:

- one canonical orchestrator
- one canonical policy implementation
- one canonical experiment schema
- one canonical result schema
- environment-aware mode comparison across host, VM, stock, v4, v5, fixed baselines, and llvmbpf

Anything smaller will reduce some script count, but it will not actually solve the architectural fragmentation that the current plan document now depends on.
