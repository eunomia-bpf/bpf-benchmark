# BPF Benchmark Framework

## Design Rules

### No ReJIT Filtering
Never filter, skip, or exclude any BPF program from ReJIT. If a program fails ReJIT (e.g. EINVAL), the error must be recorded in results and surface naturally. Do not implement:
- `live_rejit_programs()` overrides that filter programs
- `LifecycleAbort` in `before_rejit` hooks
- Per-prog_type pass exclusions in `benchmark_config.yaml`
- Exclusion lists (e.g. `_EXCLUDED_PROGRAM_NAMES`)

### App-Level Loader Only
All benchmark apps must load their own BPF programs via real application startup. The framework must not directly load `.bpf.o` files via bpftool or libbpf. Exception: katran's `xdp_root` bootstraps the XDP chain before the app starts.

### Corpus Metrics: Per-Program avg_ns_per_run
Corpus performance is measured per-program, not per-app:
- `avg_ns_per_run = run_time_ns_delta / run_cnt_delta` for each BPF program
- `ratio = post_rejit_avg / baseline_avg` (< 1.0 = faster after ReJIT)
- Only programs with `run_cnt_delta > 0` on both baseline and post-ReJIT are included (mathematical necessity, not filtering)
- No thresholds, no type exclusions, no app-status filtering
- Result payload contains `per_program` list and `summary` with `per_program_geomean`, `program_count`, `wins`, `losses`

### No Redundant Informational Fields
Do not add `workload_miss`, `limitations`, or similar informational-only fields to result payloads. If something fails, it should surface as an error, not as a metadata annotation.

### Default Config Must Work
`make vm-corpus`, `make vm-e2e`, `make aws-x86-test`, `make aws-arm64-test` must work with zero manual environment variables. Defaults live in `runner/targets/*.env` files and are overridable via env vars.

## Supported Apps (8)
tracee, tetragon, bpftrace, bcc, katran, calico, cilium, otelcol-ebpf-profiler

## Removed Apps
- **scx**: struct_ops ReJIT crashes the scheduler
- **suricata**: upstream eBPF assets incompatible with libbpf v1.0+
- **systemd**: Ubuntu default packages compiled without BPF framework
- **loxilb**: no arm64 support
