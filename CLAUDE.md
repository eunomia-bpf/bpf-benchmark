# BPF Benchmark Framework

## Design Rules

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
- bootstrap CI, run-weighted aggregate, comparison_summary, markdown summary tables
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

**Two reporting metrics, always paired**:
- **Method B — per-program geomean** (primary):
  `geomean = exp(mean(log(ratio_i)))` over all retained programs (≥100 min_runs)
  Answers: "average ReJIT speedup per BPF program"
- **Method C — run-weighted aggregate** (secondary):
  `aggregate_ratio = sum(post_avg × min_runs) / sum(baseline_avg × min_runs)`
  Equivalent to `total_post_rejit_BPF_time / total_baseline_BPF_time`
  Answers: "real CPU-time reduction in BPF execution"

Both reported together; agreement (within 1%) signals high confidence. Report `wins/losses/ties` counts as supplemental.

**Forbidden in metrics**:
- log/sqrt/log² weighted geomean (no physical justification, paper-review red flag)
- median ratio as primary (loses too much information)
- arithmetic mean of ratios (mathematically wrong for ratio data)
- ad-hoc thresholds other than 100 (any change must be justified by re-measuring noise-floor CV on the new dataset)

**Confidence reporting**: Bootstrap CIs are computed from per-program ratios across the retained-programs population (≥100 min_runs), not from cross-suite-run replication. Both SAMPLES=1 and SAMPLES=3 produce paper-quotable numbers when retained-program coverage is non-trivial.

**Tail-call accounting caveat (important for paper interpretation)**: BPF programs entered via `bpf_tail_call(ctx, &progs, key)` are jumped to at `bpf_func + X86_TAIL_CALL_OFFSET` (and the equivalent on arm64), which **skips the prologue that increments `bpf_prog->stats.cnt`/`nsecs`**. Consequently `bpftool prog show` reports `run_cnt = 0` and `run_time_ns = 0` for every tail-called program, even when the program executes on every dispatch. Per-program `run_cnt_delta` filtering at the framework level systematically under-counts these tail targets to zero. Concrete examples: OTEL `perf_unwind_<lang>` (×8) routed from `native_tracer_entry`; pre-fix katran `balancer_ingress` routed from `xdp_root` (now bypassed by switching katran to standalone attach mode); cilium NodePort/CT/policy `tail_*` programs; tetragon `generic_kprobe_event` → `process_event/filter_arg/actions/output` chain; tracee `lkm_seeker_*` and `vfs_*_tail` chains. When evaluating coverage of tail-called programs, verify program execution through profiler-side telemetry (e.g. OTEL debug exporter sample dump showing interpreter frame names) or by re-attaching the program directly so it becomes the entry point (the katran standalone-mode pattern). Do not interpret `run_cnt = 0` for a tail target as "program not running".

**Optimizations of tail-called programs are measured at the caller, NOT the tail target.** The caller's `run_time_ns` already includes the time spent in every tail-called descendant (the tail call jumps inline; control does not return). So when `map_inline`/`kinsn`/etc. apply to a tail target like `perf_unwind_python` or `cil_lxc_policy`, the runtime savings show up in the directly-attached caller's `run_time_ns_delta` (e.g. `native_tracer_entry`, `cil_xdp_entry`, `cil_from_netdev`, `generic_kprobe_event`). The right way to filter the qualified-and-affected population is **"caller's `applied>0` OR any tail-call descendant has `applied>0`"** — never restrict to "this program self-applied". The corpus framework's `run_cnt_delta` filter on the caller still gates statistical confidence, but program selection must follow the call tree. Do not kernel-patch the tail-call prologue: the time accounting at the caller is correct.

### BranchFlip Requires Real Per-Site PGO
`branch_flip` is the Paper B profile-guided branch-layout pass. It is production code but remains outside the runner benchmark default policy until Paper B benchmark results decide policy. It must consume real `bpfprof --per-site` data: every candidate site needs `branch_count`, `branch_misses`, `miss_rate`, `taken`, and `not_taken`. Placeholder PMU fields, heuristic fallback, missing-site success, and optional per-site profile fields are forbidden; missing program/site PMU data must exit 1.

### No Redundant Informational Fields
Do not add `workload_miss`, `limitations`, or similar informational-only fields to result payloads. If something fails, it should surface as an error, not as a metadata annotation.

### Fail-Fast: No Dead Code, Fallback, or Silenced Errors
Keep the codebase fail-fast so missing v3 capabilities become visible defects instead of hidden behavior.
- No dead code: every fn, struct, field, and constant must have a real caller; remove `#[allow(dead_code)]` targets, legacy wrappers, compatibility APIs, and public unused APIs.
- No fallback: unsupported capability or command failure must exit 1 with friendly stderr, never downgrade to other logic, return partial results, or exit 0.
- No silenced errors: propagate BPF syscall, IO, and parse errors; do not use `.ok()`, `let _ = result`, `unwrap_or_default`, or warning-and-continue for fallible work.

### No Revert / Restore Commits
Do not produce `git revert` commits or "Restore X" commits to undo previous changes. If a change is wrong, fix it forward in a new commit that does the right thing — do not bounce the tree between two states. Repeated revert/restore pairs (e.g. `Revert "X"` followed by `Restore X`) are forbidden; they pollute history and obscure intent. Decide what the code should be, write that, commit once.

### Unit Test Quality
Do not add unit tests unless they have a clear bug-detection purpose.
Good unit tests cover logic branches, state changes, calculations, conversions, boundaries, error paths, external ABI/layout/serialization contracts, or bug regressions.
ABI/layout tests must verify field offsets or encoded format, not just `size_of`.
Do not test trivial getters/setters, standard library or upstream library behavior, self-equality tautologies, mocks-only behavior, readability/documentation examples, pure const aliases, or duplicate coverage.
Before adding a test, be able to answer: what specific bug would this failure identify?

### bpfopt-suite v3 Architecture
`docs/tmp/bpfopt_design_v3.md` is the authoritative design document for bpfopt-suite. Keep implementation and documentation aligned with that design:
- The daemon must not maintain `PassManager`, do profiling internally, transform bytecode in-process, or maintain a default pass list. It owns the runner-provided per-pass orchestration loop, but every bytecode transform is a separate `bpfopt --pass <name>` CLI invocation followed immediately by `BPF_PROG_REJIT(log_level=2)`.
- The daemon watches for new BPF programs, detects map invalidation, preserves the runner socket + JSON protocol, and owns in-process live discovery, map-value side-input preparation, minimal fd-array construction from `prog_info.used_maps`, and per-pass `BPF_PROG_REJIT`.
- `bpfopt` is a pure bytecode CLI tool with zero kernel dependency.
- `bpfprof` remains a standalone CLI for PMU profiling.
- Bytecode transforms remain `bpfopt` CLI invocations. The daemon does not accept candidates through `BPF_PROG_LOAD` dry-runs; the kernel re-verifies each pass candidate during `BPF_PROG_REJIT`.
- Benchmark runner Python stays on the existing daemon socket boundary during the v3 migration.
- stdin/stdout carry raw binary bytecode (`struct bpf_insn[]`) for `bpfopt`; side-inputs and side-outputs use files only at the `bpfopt`/`bpfprof` CLI boundary.

#### Daemon Owns Kernel Calls; Runner Stays Untouched
- v3 §8 option B: runner Python (`runner/libs/`, `corpus/`, `micro/`) is the stable boundary; do not refactor it for v3 migration.
- The daemon retains the socket + JSON protocol. It invokes `bpfopt --pass <name>` as an external pure-bytecode CLI and `bpfprof` as an external profiling CLI, while live discovery comes from the daemon-owned `bpfget` library and every ReJIT call goes through `kernel-sys` directly.
- Daemon internal `PassManager`, pass code, profiler, thin dry-run module, LoadAttr rebuilds, BTF metadata replay, and pseudo-map fd rewriting are removed. Verifier states for `map_inline` / `const_prop` come only from the previous successful per-pass `BPF_PROG_REJIT(log_level=2)` verifier log.
- Main `BPF_PROG_REJIT` is a synchronous syscall with no daemon-side timeout; a kernel verifier hang can block the daemon. This limitation is accepted and documented rather than hidden behind a fallback.
- The only allowed runner Python changes during v3 migration are bug fixes (for example, micro driver baseline regression) and stale test data updates.

### No CLI Cross-Dependencies
The remaining standalone CLI binary crates (`bpfopt`, `bpfprof`, `bpfrejit-daemon`) must not depend on each other:
- Runtime composition happens through stdin/stdout pipelines and bash orchestration.
- Compile-time dependencies between CLI binary crates are forbidden; do not add path-dependencies from one CLI crate to another.
- `bpfget` is a daemon-owned library crate, not a standalone CLI crate. `bpfverify` and `bpfrejit` crates have been removed; per-pass ReJIT orchestration lives inside `bpfrejit-daemon` and calls `kernel-sys`.
- Shared syscall/data access belongs in `kernel-sys`; `bpfrejit-daemon` must not depend on `bpfopt`'s lib portion.

### Use libbpf-rs/libbpf-sys, Don't Re-Wrap
Use `libbpf-rs`/`libbpf-sys` instead of custom wrappers whenever upstream libbpf exposes the needed API or type:
- BPF syscall wrappers (`PROG_LOAD`, `GET_NEXT_ID`, `GET_INFO`, `bpf_enable_stats`, etc.) should use `libbpf-rs`/`libbpf-sys`.
- `struct bpf_insn`, BPF opcode constants, and program type enums should use `libbpf-sys` re-exports.
- Hand-written wrappers are error-prone because `bpf_attr` layouts and kernel ABI details can drift.
- The only required custom wrappers are project-fork syscalls not supported upstream: `BPF_PROG_REJIT` and `BPF_PROG_GET_ORIGINAL`.
- The v3 §11 "direct libbpf linking, future fork+exec" limit was an early conservative constraint and is superseded; implementation code may link `libbpf-rs` directly.

### kernel-sys is the Only Syscall Boundary
`kernel-sys` is the only bpfopt-suite crate that may directly call BPF syscalls:
- `bpfopt` (lib and bin) may depend on `kernel-sys` for pure data APIs such as the `bpf_insn` type, opcode constants, and program type enums.
- `bpfopt` must not call `libc::syscall(SYS_bpf, ...)` or otherwise invoke BPF syscalls directly.
- `bpfprof`, `bpfrejit-daemon`, and daemon-owned `bpfget` must also call BPF syscalls only through `kernel-sys`.
- Inside `kernel-sys`, standard BPF commands should go through `libbpf-rs`/`libbpf-sys`; project-fork commands (`BPF_PROG_REJIT`, `BPF_PROG_GET_ORIGINAL`) are wrapped with `libc::syscall` because upstream libbpf does not support them.

### Default Config Must Work
`make vm-corpus`, `make vm-test`, `make aws-x86-test`, `make aws-arm64-test` must work with zero manual environment variables. Defaults live in `runner/targets/*.env` files and are overridable via env vars.

### Make Is the Only Benchmark Entrypoint
**Every benchmark run must be invoked via `make <target>`. Never call `python -m runner.libs.run_target_suite`, `cargo run`, `docker run`, or any component binary directly.** Targets handle build dependencies, runtime image assembly, KVM/AWS dispatch, and artifact paths consistently; bypassing them silently changes the contract.

Targets (orthogonal — mode goes in the target name, not in env vars):
- VM x86: `vm-{selftest,negative-test,test,micro,corpus,all}`
- AWS:    `aws-{arm64,x86}-{selftest,negative-test,test,micro,corpus,terminate}`
- AWS arch dispatch: `aws-corpus` (chooses arm64/x86 by `RUN_TARGET_ARCH`)

Override knobs (env vars passed to `make`):

| env | scope | purpose | example |
|-----|-------|---------|---------|
| `SAMPLES` | corpus / micro | per-program sample count (default 3 corpus, 1 micro) | `SAMPLES=3 make corpus` |
| `WORKLOAD_DURATION` | corpus | seconds per workload sample, single global knob (default 30, applies to every app — no per-app override) | `WORKLOAD_DURATION=10 make corpus` |
| `TIMEOUT` | all VM | suite timeout in seconds (default 7200) | `TIMEOUT=3600 make test` |
| `BPFREJIT_CORPUS_APPS` | corpus | comma-separated subset of the 7 supported apps. Names match `corpus/config/macro_apps.yaml` (e.g. `bcc/set`, `tetragon/observer`, `katran`) | `BPFREJIT_CORPUS_APPS="cilium/agent,tracee/monitor" make vm-corpus` |
| `BPFREJIT_BENCH_PASSES` | corpus / micro | comma-separated bpfopt pass list overriding `corpus/config/benchmark_config.yaml`. Set to `default` to use yaml policy explicitly | `BPFREJIT_BENCH_PASSES="noop,map_inline" make vm-corpus` |
| `KEEP_WORKDIRS` | corpus | `1` = retain failure workdir tarballs at `details/failure-artifacts/<prog_id>.tar.gz`; `all` = also force-capture successful prog workdirs (sets `BPFREJIT_KEEP_ALL_WORKDIRS=1` for daemon) | `KEEP_WORKDIRS=1 make vm-corpus` |
| `BENCH` | micro | subset of micro benchmarks | `make vm-micro BENCH="simple bitcount"` |
| `WARMUPS` / `INNER_REPEAT` | micro | micro-only knobs (same name on VM and AWS) | `make vm-micro SAMPLES=1 WARMUPS=0 INNER_REPEAT=10` |
| `FUZZ_ROUNDS` | test | fuzz iteration count | `FUZZ_ROUNDS=5000 make vm-test` |
| `AWS_<ARM64\|X86>_{REGION,PROFILE,SUBNET_ID,SECURITY_GROUP_ID,KEY_NAME,KEY_PATH}` | aws-* | AWS deploy params | `AWS_ARM64_REGION=us-east-1 make aws-arm64-test` |

Pass list reference (current `corpus/config/benchmark_config.yaml`):
- **kinsn-class**: `wide_mem`, `rotate`, `cond_select`, `extract`, `endian_fusion`, `bulk_memory`, `prefetch`
- **bytecode rewriting**: `noop` (verifier-state producer), `map_inline`, `const_prop`, `dce`, `bounds_check_merge`, `skb_load_bytes_spec`
- **profile-guided** (not in default policy): `branch_flip`

Per-pass + per-app combinations are how isolated benchmarks (e.g., "tetragon kinsn-only SAMPLES=3") are run. Compose env vars on a single `make` invocation; do not bypass the Makefile.

### Cost-Conscious AWS Defaults
All AWS runs (smoke and authoritative) use `t3.small` (x86) / `t4g.small` (arm64) for bench suites and `t3.micro` / `t4g.micro` for the kernel test suite. **`medium` is the absolute upper cap and only allowed as documented OOM mitigation. Never escalate beyond medium — not for variance, not for parallelism, not for SAMPLES=3 authoritative runs.** Variance noise, throughput limits, and CPU-credit throttling must be solved by optimizing code (smaller workloads, lighter tracing, fewer concurrent passes) rather than by upgrading the instance. c5/c6g, xlarge, 2xlarge, and larger sizes are forbidden as defaults. Spot instances are allowed for non-time-critical runs.

### No Host Bind Mount
Container must NOT bind mount host workspace (`-v workspace:workspace`). All files are delivered via Docker image layers. Only bind mount system paths (/sys, /sys/fs/bpf, /lib/modules, /boot) and result output directories.

### Docker Image Layering
Docker image layers must be ordered by change frequency (bottom = stable, top = frequent):
1. Base OS + apt packages (rarely changes)
2. App artifacts — pre-built images via `FROM`/`COPY --from` (rarely changes)
3. Kernel + kinsn modules (rarely changes)
4. C++ runner + micro .bpf.o + test artifacts (moderate)
5. Rust daemon (frequently changes)
6. Python code + configs + corpus data (most frequently changes)

Changing Python must NOT trigger recompilation of apps, kernel, or daemon. `RUNNER_RUNTIME_IMAGE_SOURCE_FILES` in build.mk must only include files that participate in compilation, not runtime Python/YAML/config files.

## Supported Apps (7)
tracee, tetragon, bpftrace, bcc, katran, cilium, otelcol-ebpf-profiler

## Removed Apps
- **scx**: struct_ops ReJIT crashes the scheduler
- **suricata**: upstream eBPF assets incompatible with libbpf v1.0+
- **systemd**: Ubuntu default packages compiled without BPF framework
- **loxilb**: no arm64 support
- **calico**: BPF dataplane requires K8s pod model; bare-metal single-veth setup architecturally incompatible (Felix removes host IP from WEP iface)
