# BPF Benchmark Framework

## Branch Discipline

`master` is the only development branch for this experimental repository. Do
not create task branches or switch away from `master`. If a session starts on
any other branch, stop before editing and align with the user; completed work
must land on `origin/master`.

## Design Rules

### No Invented Experiment Gates
Workload throughput is the primary measurement for speculative-optimization
experiments.  Assistants must not invent additional validity, admission, or
publication requirements and then use them to stop the experiment queue,
discard a completed run, or relabel a measured throughput result as invalid.

Unless the user explicitly requests them, the following must **not** be made
mandatory:
- matched/no-op control runs
- receiver-side delivery checks or zero-drop/zero-error assertions
- exclusive or completely idle benchmark CPUs
- BPF run counters or a minimum `run_cnt` threshold
- a healthy publisher checkout, successful commit, or successful push before
  the next experiment may run

CPU contention, PMU noise, missing supplementary checks, and temporarily
unavailable JSON publication may be recorded as analysis caveats, but they are
not blockers.  Use the least-contended available CPU set, preserve the raw
result locally, continue the breadth-first experiment queue, and publish the
JSON backlog when publication becomes available.

Do not retrospectively reject a successful raw workload-throughput result only
because one of these unrequested supplementary checks was absent.  Do not
modify an app runner, workload, experiment backend, or common framework to
enforce a new measurement-validity gate without explicit user authorization.
App-specific changes that implement or exercise the requested optimization are
allowed; app-specific changes that merely impose a new proof obligation are
not.

### Frozen Workloads and Benchmark Launchers
Do not modify benchmark workloads, upstream application source, app runners,
`corpus/driver.py`, benchmark Makefiles, or runtime-image launch wiring unless
the user explicitly authorizes that specific change.
Do not change stressors, worker counts, packet topology, traffic generation,
CPU count, duration, or application policy in order to amplify a reported
speedup.

Pass execution YAML under `runner/config/passes/` is optimization policy, not
a frozen benchmark launcher.  It may be added or changed freely, including
per-app context hints, profile paths, guarded/phase-stable choices, and
aggressive pass parameters.

Permission to make app-specific optimization changes means changes inside the
optimizer, shim, PMU/profile processing, or bytecode specialization policy.  It
does not implicitly authorize changing the workload or the application being
measured.  The accepted performance protocol is the existing two-start
load-time comparison.  Do not modify `corpus/driver.py` to add same-process PMU
training, `apply_app_rejit()`, or a live-swap measurement lifecycle; those are
not required for the speculative-optimization throughput experiments.

### No ReJIT Filtering
Never filter, skip, or exclude any BPF program from ReJIT. If a program fails ReJIT (e.g. EINVAL), the error must be recorded in results and surface naturally. Do not implement:
- `live_rejit_programs()` overrides that filter programs
- `LifecycleAbort` in `before_rejit` hooks
- Per-prog_type pass exclusions in `benchmark_config.yaml`
- Exclusion lists (e.g. `_EXCLUDED_PROGRAM_NAMES`)

### App-Level Loader Only
All benchmark apps must load their own BPF programs via real application startup. The framework must not directly load `.bpf.o` files via bpftool or libbpf. Never write custom loader binaries to replace upstream app binaries — always use the real upstream binary. If compilation is slow, use pre-built images or cached artifacts, not simplified replacements. Exception: katran's `xdp_root` bootstraps the XDP chain before the app starts.

### No In-Framework Computation or Summary
The benchmark framework collects raw counter measurements only. **Any aggregation, ratio, average, geomean, win/loss tally, confidence interval, comparison summary, or markdown rollup is forbidden in framework code.** All performance interpretation happens in external analysis scripts or post-hoc, using the methodology below.

What the framework writes to `result.json`:
- per BPF program, per phase (baseline / post_rejit): `run_cnt_delta`, `run_time_ns_delta`, `id`, `name`, `type`, `bytes_jited`, `bytes_xlated`
- workload `stdout`/`stderr`, lifecycle event log, app `status`, `error` string

Raw app-side workload metrics are explicitly allowed and should be preserved in the corpus per-app payloads under `.baseline.workloads[]` and `.post_rejit.workloads[]`. Examples include raw `ops_per_sec`, `ops_total`, `duration_s`, `latency_ms`, `request_count`, `success_count`, `bytes_total`, and `error_count`; storing these raw fields is not a framework-side comparison or summary. Only derived computation, aggregation, ratios, and interpretation are forbidden.

What the framework MUST NOT write or compute:
- `avg_ns_per_run`, `ratio`, `per_program` ratio list
- `per_program_geomean`, `program_count`, `wins`, `losses`, `summary` block
- bootstrap CI, comparison_summary, markdown summary tables
- "optimization_summary" or any fleet-level rollup in run_artifacts

Forbidden code patterns (delete on sight): `geometric_mean()`, `_geometric_mean()`, `bootstrap_geometric_mean_ci()`, `win_counts()`, `comparison_summary()`, `summarize_phase_timings()`, `summarize_named_counters()`, `derive_perf_metrics()`, anything that takes a list of ratios and returns a summary scalar.

### Performance Calculation Methodology (analysis-side reference)
This section documents how analysts compute paper-grade metrics from raw `result.json` data. Framework code MUST NOT implement any of this.

**Per-program ratio**:
```
avg_ns_per_run = run_time_ns_delta / run_cnt_delta
ratio = post_rejit_avg_ns_per_run / baseline_avg_ns_per_run    # < 1.0 = ReJIT faster
```
Skip programs where either phase has `run_cnt_delta == 0`.

**Threshold filter** (mandatory for paper-grade):
- Drop programs where `min(baseline_runs, post_rejit_runs) < 100`
- Justification: empirical noise floor on the BpfReJIT 18-app corpus drops sharply at 100 (CV 29.6% with no filter → 17.7% at ≥100). Above 100 the CV stays flat through ≥100K, so 100 captures the noise-reduction inflection point while retaining maximum program coverage (127 vs 90 progs at ≥10K). Justified by noise-floor measurement on the same dataset; do not raise without re-measuring CV on a new dataset.
- SAMPLES count is just a workload-cycle multiplier; it does not gate paper-grade. SAMPLES=1 is a legitimate authoritative measurement as long as the per-program min_runs filter (≥100) passes — a single workload pass that drives any one BPF program through several hundred run_cnt deltas already provides the noise floor. SAMPLES=3 is the upper cap; larger SAMPLES is not used.

**Reporting metric — per-program geomean**:
`geomean = exp(mean(log(ratio_i)))` over all retained programs (≥100 min_runs).
Answers: "average ReJIT speedup per BPF program."
Report `wins/losses/ties` counts as supplemental.

**Forbidden in metrics**:
- log/sqrt/log² weighted geomean (no physical justification, paper-review red flag)
- median ratio as primary (loses too much information)
- arithmetic mean of ratios (mathematically wrong for ratio data)
- ad-hoc thresholds other than 100 (any change must be justified by re-measuring noise-floor CV on the new dataset)

**Confidence reporting**: Bootstrap CIs are computed from per-program ratios across the retained-programs population (≥100 min_runs), not from cross-suite-run replication. Both SAMPLES=1 and SAMPLES=3 produce paper-quotable numbers when retained-program coverage is non-trivial.

**Tail-call accounting caveat (important for paper interpretation)**: BPF programs entered via `bpf_tail_call(ctx, &progs, key)` are jumped to at `bpf_func + X86_TAIL_CALL_OFFSET` (and the equivalent on arm64), which **skips the prologue that increments `bpf_prog->stats.cnt`/`nsecs`**. Consequently `bpftool prog show` reports `run_cnt = 0` and `run_time_ns = 0` for every tail-called program, even when the program executes on every dispatch. Per-program `run_cnt_delta` filtering at the framework level systematically under-counts these tail targets to zero. Concrete examples: OTEL `perf_unwind_<lang>` (×8) routed from `native_tracer_entry`; pre-fix katran `balancer_ingress` routed from `xdp_root` (now bypassed by switching katran to standalone attach mode); cilium NodePort/CT/policy `tail_*` programs; tetragon `generic_kprobe_event` → `process_event/filter_arg/actions/output` chain; tracee `lkm_seeker_*` and `vfs_*_tail` chains. When evaluating coverage of tail-called programs, verify program execution through profiler-side telemetry (e.g. OTEL debug exporter sample dump showing interpreter frame names) or by re-attaching the program directly so it becomes the entry point (the katran standalone-mode pattern). Do not interpret `run_cnt = 0` for a tail target as "program not running".

**Optimizations of tail-called programs are measured at the caller, NOT the tail target.** The caller's `run_time_ns` already includes the time spent in every tail-called descendant (the tail call jumps inline; control does not return). So when `map_inline`/`kop`/etc. apply to a tail target like `perf_unwind_python` or `cil_lxc_policy`, the runtime savings show up in the directly-attached caller's `run_time_ns_delta` (e.g. `native_tracer_entry`, `cil_xdp_entry`, `cil_from_netdev`, `generic_kprobe_event`). The right way to filter the qualified-and-affected population is **"caller's `applied>0` OR any tail-call descendant has `applied>0`"** — never restrict to "this program self-applied". The corpus framework's `run_cnt_delta` filter on the caller still gates statistical confidence, but program selection must follow the call tree. Do not kernel-patch the tail-call prologue: the time accounting at the caller is correct.

### BranchFlip Requires Real Per-Site PGO
`branch_flip` is the Paper B profile-guided branch-layout pass. It is production code but remains outside the runner benchmark default policy until Paper B benchmark results decide policy. It must consume real per-site PMU profile data from the external profiling toolchain (now archived under `bpfperf`): every candidate site needs `branch_count`, `branch_misses`, `miss_rate`, `taken`, and `not_taken`. Placeholder PMU fields, heuristic fallback, missing-site success, and optional per-site profile fields are forbidden; missing program/site PMU data must exit 1.

### No Redundant Informational Fields
Do not add `workload_miss`, `limitations`, or similar informational-only fields to result payloads. If something fails, it should surface as an error, not as a metadata annotation.

### Fail-Fast: No Dead Code, Fallback, or Silenced Errors
Keep the codebase fail-fast so missing v3 capabilities become visible defects instead of hidden behavior.
- No dead code: every fn, struct, field, and constant must have a real caller; remove `#[allow(dead_code)]` targets, legacy wrappers, compatibility APIs, and public unused APIs.
- No fallback: unsupported capability or command failure must exit 1 with friendly stderr, never downgrade to other logic, return partial results, or exit 0.
- No silenced errors: propagate BPF syscall, IO, and parse errors; do not use `.ok()`, `let _ = result`, `unwrap_or_default`, or warning-and-continue for fallible work.

### No Revert / Restore Commits
Do not produce `git revert` commits or "Restore X" commits to undo previous changes. If a change is wrong, fix it forward in a new commit that does the right thing — do not bounce the tree between two states. Repeated revert/restore pairs (e.g. `Revert "X"` followed by `Restore X`) are forbidden; they pollute history and obscure intent. Decide what the code should be, write that, commit once.

### Preserve Documentation History
Do not rewrite long-lived design notes, experiment logs, benchmark reports, or status documents wholesale unless the user explicitly asks for a full rewrite. Prefer minimal, additive edits that preserve existing data, failed experiments, artifact paths, and rationale. When simplifying stale documentation, first compare against the current diff and keep every still-relevant measurement, caveat, and lesson learned; summarize only duplicated or obsolete narrative.

### Explicitly Authorized Git Mutations Only
Assistants (Claude or codex) must NOT run git commands that modify state unless
the user explicitly asks for that operation. When explicitly requested by the
user, the allowed state-mutating git commands are `git pull`, `git add`,
`git commit`, and `git push`, scoped to the requested work. Before running any
of them, inspect `git status`/`git diff` and avoid overwriting unrelated
uncommitted work.

Destructive or history-rewriting git commands remain forbidden unless a future
explicit instruction updates this policy: `commit --amend`, `checkout -- <files>`,
`checkout HEAD -- <files>`, `reset`, `reset --hard`, `restore`, `stash`,
`stash pop`, `branch -D`, `push -f`, `rebase`, `cherry-pick`, `revert`.
Other allowed git commands are read-only: `status`, `diff`, `log`, `blame`,
`show`, `fsck`, `stash list`, `reflog`.

Uncommitted working-tree modifications may be the user's or a concurrent agent's WIP. Even when the build is broken (e.g., 82 compile errors from a half-done refactor), do NOT `git checkout` to "fix" it — report the situation to the user and wait for direction. Lost WIP is not recoverable through `git reflog` because reflog only tracks committed states.

Codex prompts must explicitly include "DO NOT modify git state" when invoking codex on a dirty tree.

### Unit Test Quality
Do not add unit tests unless they have a clear bug-detection purpose.
Good unit tests cover logic branches, state changes, calculations, conversions, boundaries, error paths, external ABI/layout/serialization contracts, or bug regressions.
ABI/layout tests must verify field offsets or encoded format, not just `size_of`.
Do not test trivial getters/setters, standard library or upstream library behavior, self-equality tautologies, mocks-only behavior, readability/documentation examples, pure const aliases, or duplicate coverage.
Before adding a test, be able to answer: what specific bug would this failure identify?

### Stock-Kernel Shim Architecture
The active bpfopt-suite architecture is the stock-kernel userspace path implemented in `bpfopt/shim/`. Historical daemon/ReJIT designs under `docs/tmp/` are not authoritative.
- Real upstream applications load their own BPF programs. The framework never replaces an application loader with a synthetic `.bpf.o` loader.
- `libbpfrejit_shim.so` is injected into supported application processes and intercepts their BPF-related syscalls. It captures the original `BPF_PROG_LOAD` context, map references, attachment state, and per-program bytecode needed by later optimization steps.
- The benchmark runner owns policy. It reads `runner/config/passes/<pass>/default.yaml`, builds an ordered plan, and either supplies it through `BPFREJIT_SHIM_LOADTIME_PLAN` or sends it to a per-process shim socket as an `execute_plan` request.
- `bpfopt` is a pure bytecode CLI with zero BPF syscall dependency. Each invocation performs one named pass over raw `struct bpf_insn[]`; side inputs and reports cross the CLI boundary through explicit files.
- The shim runs every configured `bpfopt` step, submits candidate bytecode through the stock `BPF_PROG_LOAD` verifier/JIT path, and either installs the optimized program at load time or reloads and reattaches it with existing stock-kernel APIs.
- Live replacement uses the attachment-specific mechanisms implemented in `shim_reload.h`, including `BPF_LINK_UPDATE`, link recreation, `BPF_PROG_ATTACH`, raw tracepoint reopen, perf-event replacement, and program-array updates. Partial replacement is an explicit error/result, not success.
- The active architecture has no `bpfrejit-daemon`, no `BPF_PROG_REJIT`, no `BPF_PROG_GET_ORIGINAL`, and no project-fork syscall dependency.

#### Evaluated Path vs Implemented Path
- The current corpus comparison is a two-start load-time experiment: run and stop the baseline upstream application, then restart the same application with `BPFREJIT_SHIM_LOADTIME_PLAN` so optimized bytecode is verified during its normal `BPF_PROG_LOAD` calls.
- The shim also implements running-process `execute_plan` plus reload/reattach. Do not describe a result as a live-swap result unless its recorded lifecycle used that path.
- Load-time results establish transparent loader interception and stock-verifier acceptance, but by themselves do not establish post-deployment re-specialization or phase-change recovery.

### No CLI Cross-Dependencies
- Runtime composition happens through bytecode files/stdin/stdout, explicit side-input files, runner plan JSON, and shim orchestration.
- Do not add a compile-time dependency from `bpfopt` to the shim or from the shim to a `bpfopt` library. The shim executes the `bpfopt` binary.
- `bpfget`, `bpfverify`, `bpfrejit`, `bpfprof`, `kernel-sys`, and `bpfrejit-daemon` have been removed. Do not restore them as compatibility layers.

### Use libbpf-rs/libbpf-sys, Don't Re-Wrap
Use `libbpf-rs`/`libbpf-sys` instead of custom wrappers whenever upstream libbpf exposes the needed API or type:
- BPF syscall wrappers (`PROG_LOAD`, `GET_NEXT_ID`, `GET_INFO`, `bpf_enable_stats`, etc.) should use `libbpf-rs`/`libbpf-sys`.
- `struct bpf_insn`, BPF opcode constants, and program type enums should use `libbpf-sys` re-exports.
- Hand-written wrappers are error-prone because `bpf_attr` layouts and kernel ABI details can drift.
- The shim must preserve the intercepted loader ABI exactly when reconstructing `BPF_PROG_LOAD` and attachment operations.

### Shim Syscall Boundary
`bpfopt` must remain a pure bytecode tool and must not call `libc::syscall(SYS_bpf, ...)` or otherwise invoke BPF syscalls directly. It may use `libbpf-sys` for UAPI data such as `struct bpf_insn`, opcode constants, map types, helper IDs, and program type enums.

All kernel interaction for speculative optimization stays inside the intercepted application process through `bpfopt/shim/`. Use stock BPF commands and attachment APIs; do not add fork-only syscall wrappers or move application-owned fd operations into an external process.

### Default Config Must Work
`make corpus`, `make test`, `PLATFORM=aws ARCH=x86 make test`, `PLATFORM=aws ARCH=arm64 make test` must work with zero manual environment variables beyond `PLATFORM`/`ARCH`. Defaults live in `runner/targets/*.env` files and are overridable via env vars.

### Make Is the Only Benchmark Entrypoint
**Every benchmark run must be invoked via `make <target>`. Never call `python -m runner.libs.run_target_suite`, `cargo run`, `docker run`, or any component binary directly.** Targets handle build dependencies, runtime image assembly, KVM/AWS dispatch, and artifact paths consistently; bypassing them silently changes the contract.

### Makefile Edit Discipline
Makefile changes must be minimal and local. Do not refactor target structure, add alias targets, or add conditional logic (`if`, `ifeq`, `ifneq`) for convenience. Do not add `mkdir` to Makefiles; use the repo's existing `install -d` pattern in the owning rule when an output directory must be created. Arch-specific build outputs belong under the owning component's build directories (for example `bpfopt/shim/build-x86` and `bpfopt/shim/build-arm64`), not under `.cache`, unless an existing rule already defines that location.

Targets (suite name only — platform/arch are env vars, NOT in the target name):
- Suites: `selftest`, `negative-test`, `test`, `micro`, `corpus`, `all`, `terminate`
- Platform: `PLATFORM=kvm` (default, x86 only) or `PLATFORM=aws`
- Arch (AWS only): `ARCH=x86` (default) or `ARCH=arm64`

Examples:
- `make corpus` — VM x86 corpus (PLATFORM=kvm default)
- `PLATFORM=aws ARCH=arm64 make test` — AWS arm64 fuzz test
- `PLATFORM=aws ARCH=x86 make corpus` — AWS x86 corpus

Override knobs (env vars passed to `make`):

| env | scope | purpose | example |
|-----|-------|---------|---------|
| `SAMPLES` | corpus / micro | per-program sample count (default 3 for both) | `SAMPLES=3 make corpus` |
| `WORKLOAD_DURATION` | corpus | seconds per workload sample, single global knob (default 30, applies to every app — no per-app override) | `WORKLOAD_DURATION=10 make corpus` |
| `TIMEOUT` | all VM | suite timeout in seconds (default 7200) | `TIMEOUT=3600 make test` |
| `BPFREJIT_CORPUS_APPS` | corpus | comma-separated subset of the 6 supported apps. Names match `corpus/config/macro_apps.yaml` (e.g. `bcc/set`, `tetragon/observer`, `katran`) | `BPFREJIT_CORPUS_APPS="cilium/agent,tracee/monitor" make corpus` |
| `BPFREJIT_BENCH_PASSES` | corpus / micro | comma-separated bpfopt pass list overriding `corpus/config/benchmark_config.yaml`. Set to `default` to use yaml policy explicitly | `BPFREJIT_BENCH_PASSES="noop,map_inline" make corpus` |
| `KEEP_WORKDIRS` | corpus | `1` = retain failure workdir tarballs at `details/failure-artifacts/<prog_id>.tar.gz`. To capture artifacts from a successful pass, edit the relevant `runner/config/passes/<pass>/<app>.yaml` and append `&& false` to that step's `command:` — that converts it into a controlled failure and the failure-tar pipeline writes the workdir | `KEEP_WORKDIRS=1 make corpus` |
| `BENCH` | micro | subset of micro benchmarks | `make micro BENCH="simple bitcount"` |
| `WARMUPS` / `INNER_REPEAT` | micro | micro-only knobs (same name on VM and AWS) | `make micro SAMPLES=1 WARMUPS=0 INNER_REPEAT=10` |
| `FUZZ_ROUNDS` | test | fuzz iteration count | `FUZZ_ROUNDS=5000 make test` |
| `AWS_<ARM64\|X86>_{REGION,PROFILE,SUBNET_ID,SECURITY_GROUP_ID,KEY_NAME,KEY_PATH}` | PLATFORM=aws | AWS deploy params | `AWS_ARM64_REGION=us-east-1 PLATFORM=aws ARCH=arm64 make test` |

Pass list reference (current `corpus/config/benchmark_config.yaml`):
- **kop-class** (replace bytecode with a kfunc call lowered by an in-kernel kop module): `rotate`, `cond_select`, `ccmp` (arm64-only), `extract`, `endian_fusion`, `bulk_memory`, `prefetch`. KOperation module `bpf_ldp` exists but has no bpfopt pass consuming it yet.
- **bytecode rewriting** (pure BPF→BPF, no kfunc): `noop` (verifier-state producer), `wide_mem` (collapse byte-ladder into wide `LDX_MEM`), `map_inline`, `const_prop`, `dce`, `bounds_check_merge`, `skb_load_bytes_spec`
- **profile-guided** (not in default policy): `branch_flip`

Per-pass + per-app combinations are how isolated benchmarks (e.g., "tetragon kop-only SAMPLES=3") are run. Compose env vars on a single `make` invocation; do not bypass the Makefile.

### Cost-Conscious AWS Defaults
All AWS runs (smoke and authoritative) use `t3.small` (x86) / `t4g.small` (arm64) for bench suites and `t3.micro` / `t4g.micro` for the kernel test suite. **`medium` is the absolute upper cap and only allowed as documented OOM mitigation. Never escalate beyond medium — not for variance, not for parallelism, not for SAMPLES=3 authoritative runs.** Variance noise, throughput limits, and CPU-credit throttling must be solved by optimizing code (smaller workloads, lighter tracing, fewer concurrent passes) rather than by upgrading the instance. c5/c6g, xlarge, 2xlarge, and larger sizes are forbidden as defaults. Spot instances are allowed for non-time-critical runs.

### No Host Bind Mount
Container must NOT bind mount host workspace (`-v workspace:workspace`). All files are delivered via Docker image layers. Only bind mount system paths (/sys, /sys/fs/bpf, /lib/modules, /boot) and result output directories.

### Docker Image Layering
Docker image layers must be ordered by change frequency (bottom = stable, top = frequent):
1. Base OS + apt packages (rarely changes)
2. App artifacts — pre-built images via `FROM`/`COPY --from` (rarely changes)
3. Kernel + kop modules (rarely changes)
4. C++ runner + micro .bpf.o + test artifacts (moderate)
5. C shim + bpfopt CLI (frequently changes)
6. Python code + configs + corpus data (most frequently changes)

Changing Python must NOT trigger recompilation of apps, kernel, shim, or bpfopt. `RUNNER_RUNTIME_IMAGE_SOURCE_FILES` in build.mk must only include files that participate in compilation, not runtime Python/YAML/config files.

## Supported Apps (6)
tracee, tetragon, bcc, katran, cilium, otelcol-ebpf-profiler

## Removed Apps
- **scx**: struct_ops ReJIT crashes the scheduler
- **suricata**: upstream eBPF assets incompatible with libbpf v1.0+
- **systemd**: Ubuntu default packages compiled without BPF framework
- **loxilb**: no arm64 support
- **calico**: BPF dataplane requires K8s pod model; bare-metal single-veth setup architecturally incompatible (Felix removes host IP from WEP iface)
