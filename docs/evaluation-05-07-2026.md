# BpfReJIT Evaluation — Methodology and Infrastructure (2026-05-07)

## 1. System Under Test

- **What it does**: re-JIT already-loaded eBPF programs in place: re-generate the BPF bytecode and replace in place transparently and keep all safety model.
- **Kernel**: forked Linux 7.0-rc2.
  - Two added syscall commands: `BPF_PROG_REJIT`, `BPF_PROG_GET_ORIGINAL`.
  - Modify kernel to support kinsn.
  - Modify kernel to support re-JIT and replace the hooks in place.
- *kinsn* modules expose arch-specific code sequences (byte-swap `MOVBE`, `cmov`, prefetch, rotate, `BEXTR`, bulk `memcpy`/`memset`) as JIT inline-emit hooks invoked through kfunc calls.

```
   runner ──socket──▶  bpfrejit-daemon  ──fork+exec──▶  bpfopt --pass <name>
   (Python)            (Rust)                          (Rust, pure bytecode)
                          │
                          │ kernel-sys
                          ▼
                       BPF_PROG_REJIT(log_level=2)
```

- **`bpfrejit-daemon`** (Rust) — only userspace component that calls BPF
  syscalls.
  - Live program discovery; side-input preparation (map values, BTF, fd-array
    from `prog_info.used_maps`).
  - Per-pass orchestration: `fork+exec bpfopt` → kernel re-JIT.
  - No in-process bytecode transform; no default pass policy.
- **`bpfopt`** (Rust) — pure-bytecode CLI.
  - `stdin = bpf_insn[]`, `stdout = bpf_insn[]`, `--report = JSON`.
  - One invocation = one named pass.
  - Zero kernel dependency.
- **Per-pass loop** (per program):
  1. daemon writes verifier states + side-inputs to files
  2. `bpfopt --pass <name>` rewrites bytecode
  3. daemon issues `BPF_PROG_REJIT(log_level=2)`; kernel re-verifies + re-emits
  4. on failure → recorded in result JSON, no fallback, no retry

## 2. Optimization Passes

Three classes; every benchmark run selects an explicit subset via
`BPFREJIT_BENCH_PASSES`.

### 2.1 kinsn-class — replace bytecode with a kfunc, lowered by an in-kernel kinsn module via `KFUNC_INLINE_EMIT`

- **`rotate`** — shift+or pair → native rotate (`bpf_rotate{32,64}`)
- **`cond_select`** — branch+select → `cmov` (`bpf_select64`)
- **`ccmp`** *(arm64-only)* — same-target zero-test AND chain → conditional-compare (`bpf_ccmp`)
- **`extract`** — bit-field extract → BMI `BEXTR` (`bpf_extract64`)
- **`endian_fusion`** — load+`bswap` → `MOVBE` (`bpf_endian_load{16,32}`)
- **`bulk_memory`** — scalarized `memcpy`/`memset` → SIMD or `REP MOVS`
  (`bpf_memcpy` / `bpf_memset`)
- **`prefetch`** — insert `prefetch` ahead of pointer-chasing loads
  (`bpf_prefetch`)

### 2.2 Bytecode-rewriting — pure BPF→BPF, no kfunc; kernel JIT lowers as usual

- **`noop`** — no transform pass
- **`wide_mem`** — collapse byte-by-byte ladder into one wide `LDX_MEM`
  (size `H` / `W` / `DW`)
- **`map_inline`** — speculate constant `bpf_map_lookup_elem` results from
  captured map values
- **`const_prop`** — propagate verifier-known constants, fold uses
- **`dce`** — drop instructions dead under verifier liveness
- **`bounds_check_merge`** — merge redundant bounds checks on the same range
- **`skb_load_bytes_spec`** — specialize `bpf_skb_load_bytes` to fixed-width
  loads

## 3. Workload Suite — 7 production eBPF applications

Selection criteria:

- real, deployed eBPF — no synthetic micro-loops, no test programs
- diverse program types: `kprobe`, `tracepoint`, `raw_tp`, `socket_filter`,
  `tc`, `xdp`, `LSM`
- spanning the four large eBPF use-case classes (tracing, security,
  networking, profiling)
- launched through the upstream binary; the framework loads no `.bpf.o`
  files of its own

| App | Domain | Programs | Driving workload | Notes |
| --- | --- | ---: | --- | --- |
| `bcc/set` | tracing tools | 21 | `stress_ng_os_io_network` | bundle of bcc tools: opensnoop, execsnoop, tcpconnect, biolatency, … |
| `bpftrace/set` | tracing scripts | 9 | `stress_ng_os_io_network` | bundle of bpftrace one-liners, mostly `kprobe` + `tracepoint` |
| `tracee/monitor` | runtime security | 158 | `stress_ng_os_io_network` | per-syscall and `vfs_*` tracers; large `tail_call` chain |
| `tetragon/observer` | runtime security | 287 | `stress_ng_os_io_network` | `generic_kprobe_*` + `process_event` / `filter_arg` / `actions` / `output` tail chains |
| `cilium/agent` | k8s data-plane | 53 | `network_lossy_multi` | `tc`/`xdp` policy + `cil_lxc` + `cil_from_container`; SIGSTOP wrapper to suppress hot reload |
| `katran` | L4 XDP load balancer | 1 | `xdp_traffic` | standalone-attach mode (`balancer_ingress` direct, no `xdp_root`) |
| `otelcol-ebpf-profiler/profiling` | continuous profiler | 13 | `otel_mixed_workload` | `native_tracer_entry` + `perf_unwind_<lang>` (×8) tail chain across Python / Ruby / PHP / V8 / .NET / Erlang / Perl interpreters |

### 3.1 Workload specifications

Every workload runs for `WORKLOAD_DURATION` seconds (default 30 s) per phase
and is replayed identically in `baseline` and `post_rejit`.

| Workload | Generator | Composition | What it exercises |
| --- | --- | --- | --- |
| `stress_ng_os_io_network` | `stress-ng` | `--os` + `--io` + `--network` + `--memory` + `--filesystem` stressors run concurrently (`syscall`, `epoll`, `udp`, `sock*`, `mmap`, `aio`, `iomix`, `dentry`, `file-ioctl`, …) | High-rate kprobe / tracepoint dispatch on syscalls, VFS, sockets, scheduler — the dominant load for tracing and security agents |
| `network_lossy_multi` | `netem` + `wrk` + `ping` | 20 % loss + 50 ms delay on the iface; `wrk -t4 -c50` HTTP load (≈10 K connect events/s); concurrent high-rate ICMP probes | Multi-protocol datapath: ICMP, TCP, retransmits, conntrack — drives cilium tc/xdp policy slots beyond plain HTTP |
| `xdp_traffic` | `wrk` | `wrk -t2 -c10` HTTP keep-alive (≈30 K – 100 K req/s) with steady packet flow through the iface | Sustained packet ingress for `XDP` programs; goal is throughput, not connect-rate |
| `otel_mixed_workload` | 5 language interpreters + `stress-ng` | Concurrent SHA-256(1 KiB) loops in Python / Ruby / Node.js / Perl / PHP using only stdlib + `stress-ng --cpu` for native frames | Drives `perf_event` samples into interpreter PC ranges so `perf_unwind_<lang>` tail programs dispatch; native loop drives `perf_unwind_native` |

## 4. Experimental Setup

- **Primary platform — virtme-ng KVM**, x86_64
  - Host: 16 vCPU, 64 GiB RAM, Intel Core Ultra 9 285K
  - Guest: Docker-in-VM for app stack
- **Secondary platform — AWS** (cross-architecture validation only)
  - x86: `t3.small` ; arm64: `t4g.small` ; kernel test: `t3.micro`/`t4g.micro`
- **Kernel**: forked Linux 7.0-rc2 (`vendor/linux-framework`); same build
  on KVM and AWS

### 4.1 Per-run protocol

Three measured phases per app per sample, repeated `SAMPLES` times:

```
   ┌──────────────┐    ┌──────────────────────────┐    ┌──────────────┐
   │  baseline    │ →  │       ReJIT              │ →  │  post_rejit  │
   │              │    │   for each pass:         │    │              │
   │  run         │    │     bpfopt --pass X      │    │  run         │
   │  workload    │    │     | BPF_PROG_REJIT     │    │  workload    │
   │  for         │    │   per-program            │    │  for         │
   │  WORKLOAD_   │    │   success/failure        │    │  WORKLOAD_   │
   │  DURATION s  │    │   captured               │    │  DURATION s  │
   └──────┬───────┘    └─────────┬────────────────┘    └──────┬───────┘
          │                      │                            │
          ▼                      ▼                            ▼
     run_cnt_delta,         result.json                  run_cnt_delta,
     run_time_ns_delta      per-program record           run_time_ns_delta
     per BPF program                                     per BPF program
```

- `bpf_enable_stats(BPF_STATS_RUN_TIME)` is enabled for the whole run;
  per-phase deltas are computed from `bpftool prog show` snapshots taken
  at phase boundaries
- `BPFREJIT_BENCH_PASSES` selects the pass list; the same list runs in the
  ReJIT phase of every sample
- Default knobs: `SAMPLES=3`, `WORKLOAD_DURATION=30 s`, `min_runs ≥ 100`
  filter applied at analysis time
