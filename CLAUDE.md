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

### Corpus Metrics: Per-Program avg_ns_per_run
Corpus performance is measured per-program, not per-app:
- `avg_ns_per_run = run_time_ns_delta / run_cnt_delta` for each BPF program
- `ratio = post_rejit_avg / baseline_avg` (< 1.0 = faster after ReJIT)
- Only programs with `run_cnt_delta > 0` on both baseline and post-ReJIT are included (mathematical necessity, not filtering)
- No thresholds, no type exclusions, no app-status filtering
- Result payload contains `per_program` list and `summary` with `per_program_geomean`, `program_count`, `wins`, `losses`

### BranchFlip Requires Real Per-Site PGO
`branch_flip` is the Paper B profile-guided branch-layout pass. It is production code but remains outside the default 11-pass `bpfopt optimize` pipeline until Paper B benchmark results decide policy. It must consume real `bpfprof --per-site` data: every candidate site needs `branch_count`, `branch_misses`, `miss_rate`, `taken`, and `not_taken`. Placeholder PMU fields, heuristic fallback, missing-site success, and optional per-site profile fields are forbidden; missing program/site PMU data must exit 1.

### No Redundant Informational Fields
Do not add `workload_miss`, `limitations`, or similar informational-only fields to result payloads. If something fails, it should surface as an error, not as a metadata annotation.

### Fail-Fast: No Dead Code, Fallback, or Silenced Errors
Keep the codebase fail-fast so missing v3 capabilities become visible defects instead of hidden behavior.
- No dead code: every fn, struct, field, and constant must have a real caller; remove `#[allow(dead_code)]` targets, legacy wrappers, compatibility APIs, and public unused APIs.
- No fallback: unsupported capability or command failure must exit 1 with friendly stderr, never downgrade to other logic, return partial results, or exit 0.
- No silenced errors: propagate BPF syscall, IO, and parse errors; do not use `.ok()`, `let _ = result`, `unwrap_or_default`, or warning-and-continue for fallible work.

### Unit Test Quality
Do not add unit tests unless they have a clear bug-detection purpose.
Good unit tests cover logic branches, state changes, calculations, conversions, boundaries, error paths, external ABI/layout/serialization contracts, or bug regressions.
ABI/layout tests must verify field offsets or encoded format, not just `size_of`.
Do not test trivial getters/setters, standard library or upstream library behavior, self-equality tautologies, mocks-only behavior, readability/documentation examples, pure const aliases, or duplicate coverage.
Before adding a test, be able to answer: what specific bug would this failure identify?

### bpfopt-suite v3 Architecture
`docs/tmp/bpfopt_design_v3.md` is the authoritative design document for bpfopt-suite. Keep implementation and documentation aligned with that design:
- The daemon must not run a pass pipeline, maintain `PassManager`, do profiling internally, parse `verifier_log`, or transform bytecode in-process.
- The daemon only watches for new BPF programs, detects map invalidation, preserves the socket + JSON protocol, and triggers external scripts/commands or CLI subprocesses.
- `bpfopt` is a pure bytecode CLI tool with zero kernel dependency.
- Per-pass verify loops belong in bash/scripts, not inside the daemon.
- Benchmark runner Python stays on the existing daemon socket boundary during the v3 migration.
- stdin/stdout carry raw binary bytecode (`struct bpf_insn[]`); side-inputs and side-outputs use files.

#### Daemon Adapts Socket-to-CLI; Runner Stays Untouched
- v3 §8 option B: runner Python (`runner/libs/`, `corpus/`, `e2e/`, `micro/`) is the stable boundary; do not refactor it for v3 migration.
- The daemon retains the socket + JSON protocol but delegates optimize/rejit/profile/discover to CLI subprocesses (`bpfopt`, `bpfget`, `bpfrejit`, `bpfverify`, `bpfprof`).
- Daemon internal `PassManager`, pass code, profiler, and `verifier_log` parser are removed; the daemon body shrinks to socket server + watch + invalidation + CLI fork+exec.
- The only allowed runner Python changes during v3 migration are bug fixes (for example, micro driver baseline regression) and stale test data updates.

### No CLI Cross-Dependencies
The 6 bpfopt-suite CLI binary crates (`bpfopt`, `bpfverify`, `bpfprof`, `bpfget`, `bpfrejit`, `bpfrejit-daemon`) must not depend on each other:
- Runtime composition happens through stdin/stdout pipelines and bash orchestration.
- Compile-time dependencies between CLI binary crates are forbidden; do not add path-dependencies from one CLI crate to another.
- Shared code belongs in library crates, not in the lib portion of one CLI crate for other CLI crates to import.
- `bpfrejit-daemon` must not depend on `bpfopt`'s lib portion; shared syscall/data access belongs in `kernel-sys`.

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
- Other CLI crates (`bpfverify`, `bpfprof`, `bpfget`, `bpfrejit`, `bpfrejit-daemon`) must also call BPF syscalls only through `kernel-sys`.
- Inside `kernel-sys`, standard BPF commands should go through `libbpf-rs`/`libbpf-sys`; project-fork commands (`BPF_PROG_REJIT`, `BPF_PROG_GET_ORIGINAL`) are wrapped with `libc::syscall` because upstream libbpf does not support them.

### Default Config Must Work
`make vm-corpus`, `make vm-e2e`, `make aws-x86-test`, `make aws-arm64-test` must work with zero manual environment variables. Defaults live in `runner/targets/*.env` files and are overridable via env vars.

### Cost-Conscious AWS Defaults
All AWS runs (smoke and authoritative) use `t3.small` (x86) / `t4g.small` (arm64) for bench suites and `t3.micro` / `t4g.micro` for the kernel test suite. **`medium` is the absolute upper cap and only allowed as documented OOM mitigation. Never escalate beyond medium — not for variance, not for parallelism, not for SAMPLES=30 authoritative runs.** Variance noise, throughput limits, and CPU-credit throttling must be solved by optimizing code (smaller workloads, lighter tracing, fewer concurrent passes) rather than by upgrading the instance. c5/c6g, xlarge, 2xlarge, and larger sizes are forbidden as defaults. Spot instances are allowed for non-time-critical runs.

### No Host Bind Mount
Container must NOT bind mount host workspace (`-v workspace:workspace`). All files are delivered via Docker image layers. Only bind mount system paths (/sys, /sys/fs/bpf, /lib/modules, /boot) and result output directories.

### Docker Image Layering
Docker image layers must be ordered by change frequency (bottom = stable, top = frequent):
1. Base OS + apt packages (rarely changes)
2. App artifacts — pre-built images via `FROM`/`COPY --from` (rarely changes)
3. Kernel + kinsn modules (rarely changes)
4. C++ runner + micro .bpf.o + test artifacts (moderate)
5. Rust daemon (frequently changes)
6. Python code + configs + corpus/e2e data (most frequently changes)

Changing Python must NOT trigger recompilation of apps, kernel, or daemon. `RUNNER_RUNTIME_IMAGE_SOURCE_FILES` in build.mk must only include files that participate in compilation, not runtime Python/YAML/config files.

## Supported Apps (8)
tracee, tetragon, bpftrace, bcc, katran, calico, cilium, otelcol-ebpf-profiler

## Removed Apps
- **scx**: struct_ops ReJIT crashes the scheduler
- **suricata**: upstream eBPF assets incompatible with libbpf v1.0+
- **systemd**: Ubuntu default packages compiled without BPF framework
- **loxilb**: no arm64 support
