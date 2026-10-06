# bpfopt/llvm O3 roundtrip full re-sweep (post ENOSPC + empty-target loader fixes) — 2026-05-20

Binary: `bpfopt/llvm/build/bpfopt` (system LLVM-18, NO kop). Loader: `bpfopt-loader`.
Raw: `o3_resweep_summary_20260520.tsv` + `/tmp/o3-resweep-20260520/`.

## Verdict
- **0 transformed-bytecode verifier rejections across every map_inline (O3) run.** O3 roundtrip is verifier-compatible everywhere it ran.
- The two ENOSPC-blocked cilium objects now pass: `cilium_bpf_lxc` (35 progs) and `cilium_bpf_xdp` (13 progs) → `map_inline` exit 0, retry fired, 0 rejects.
- `noop` (O0 control): all loadable objects exit 0.

## Loader fixes that unblocked this (bpfopt/loader/src/main.rs)
1. prep load at log_level>=2 that hits -ENOSPC now reopens + reloads at log_level=0 (verifier states unavailable for that object; harmless for the LLVM bpfopt) instead of bailing.
2. empty `--target` no longer emitted (was eating the `--` separator → `unknown argument: --map-values`).

## Remaining non-O3 failures (separate issues, not verifier/O3)
- `tracee_tracee` map_inline: exit 1, but **0 verifier reject**. Gets past ENOSPC retry, then fails at the map-value dump step: `bpftool map dump -j -p id 10619 failed` (some tracee map not dumpable). Tooling issue, not O3.
- `otel_*` (3 objects): exit 1 both passes — missing linked tracer `runner/repos/opentelemetry-ebpf-profiler/support/ebpf/tracer.ebpf.amd64`. Not O3.
- `bpftrace_*` (9 objects): 0 loader-prepared programs (fixtures).
