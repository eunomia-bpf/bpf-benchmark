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

## Supported Apps (8)
tracee, tetragon, bpftrace, bcc, katran, calico, cilium, otelcol-ebpf-profiler

## Removed Apps
- **scx**: struct_ops ReJIT crashes the scheduler
- **suricata**: upstream eBPF assets incompatible with libbpf v1.0+
- **systemd**: Ubuntu default packages compiled without BPF framework
- **loxilb**: no arm64 support
