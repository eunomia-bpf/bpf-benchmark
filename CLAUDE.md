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

### No Redundant Informational Fields
Do not add `workload_miss`, `limitations`, or similar informational-only fields to result payloads. If something fails, it should surface as an error, not as a metadata annotation.

### bpfopt-suite v3 Architecture
`docs/tmp/bpfopt_design_v3.md` is the authoritative design document for bpfopt-suite. Keep implementation and documentation aligned with that design:
- The daemon must not run a pass pipeline, maintain `PassManager`, call `bpfopt`, do profiling, or transform bytecode.
- The daemon only watches for new BPF programs, detects map invalidation, and triggers external scripts/commands.
- `bpfopt` is a pure bytecode CLI tool with zero kernel dependency.
- Per-pass verify loops belong in bash/scripts, not inside the daemon.
- Benchmark runner code should prefer calling CLI tools directly instead of using the daemon socket.
- stdin/stdout carry raw binary bytecode (`struct bpf_insn[]`); side-inputs and side-outputs use files.

### No CLI Cross-Dependencies
The 6 bpfopt-suite CLI binary crates (`bpfopt`, `bpfverify`, `bpfprof`, `bpfget`, `bpfrejit`, `bpfrejit-daemon`) must not depend on each other:
- Runtime composition happens through stdin/stdout pipelines and bash orchestration.
- Compile-time dependencies between CLI binary crates are forbidden; do not add path-dependencies from one CLI crate to another.
- Shared code belongs in library crates, not in the lib portion of one CLI crate for other CLI crates to import.
- Transition exception: after Phase 1.1, `bpfrejit-daemon` may temporarily depend on `bpfopt`'s lib portion for passes/analysis/insn/verifier_log until Task #45 slims the daemon into an event trigger and removes that dependency.

### Use libbpf-rs/libbpf-sys, Don't Re-Wrap
Use `libbpf-rs`/`libbpf-sys` instead of custom wrappers whenever upstream libbpf exposes the needed API or type:
- BPF syscall wrappers (`PROG_LOAD`, `GET_NEXT_ID`, `GET_INFO`, `bpf_enable_stats`, etc.) should use `libbpf-rs`/`libbpf-sys`.
- `struct bpf_insn`, BPF opcode constants, and program type enums should use `libbpf-sys` re-exports.
- Hand-written wrappers are error-prone because `bpf_attr` layouts and kernel ABI details can drift.
- The only required custom wrappers are project-fork syscalls not supported upstream: `BPF_PROG_REJIT` and `BPF_PROG_GET_ORIGINAL`.
- The v3 §11 "direct libbpf linking, future fork+exec" limit was an early conservative constraint and is superseded; implementation code may link `libbpf-rs` directly.

### Default Config Must Work
`make vm-corpus`, `make vm-e2e`, `make aws-x86-test`, `make aws-arm64-test` must work with zero manual environment variables. Defaults live in `runner/targets/*.env` files and are overridable via env vars.

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
