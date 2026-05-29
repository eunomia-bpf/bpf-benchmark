# Native Kernel Formal Evaluation Run Ledger

Date: 2026-05-29

Scope:
- x86 KVM corpus, one app at a time.
- Native comparison: baseline kernel eBPF vs post-load kernel native with
  `SKIP_REJIT=norejit` and `BPFREJIT_SHIM_NATIVE_LOADER=post`.
- Per-run BPF counters: `BPFREJIT_CORPUS_BPF_STATS=1`.
- Workload-only numbers: `BPFREJIT_CORPUS_BPF_STATS=0`.
- No-eBPF workload baseline: `BPFREJIT_CORPUS_WORKLOAD_ONLY=1` and BPF stats off.
- Authoritative workload knob: `SAMPLES=3`, `WORKLOAD_DURATION=180`,
  default warmup (`WARMUPS=1`).

Commands are always invoked through `make corpus`.

## TODO

| App | Native stats-on | Native stats-off | No-eBPF workload-only | Notes |
| --- | --- | --- | --- | --- |
| bcc/set | `corpus/results/x86_kvm_corpus_20260529_005704_033715` | `corpus/results/x86_kvm_corpus_20260529_012805_826766` | `corpus/results/x86_kvm_corpus_20260529_015843_382681` | All status ok; 25 native replacements; native-loader failure/no-manifest/reloc/fallback counts all 0. Stats-off workload: cap +0.37%, set -1.25%, sockfd +0.78%; syscall stressor is too low-throughput/noisy. No-eBPF throughput is roughly 2.2x-2.6x higher than app+BPF for cap/set/sockfd. |
| otelcol-ebpf-profiler/profiling | pending | pending | pending | Run after bcc. |
| cilium/agent | pending | pending | pending | Requires endpoint workload validation. |
| tetragon/observer | pending | pending | pending | Check runtime-helper skip remains benign. |
| katran | pending | pending | pending | Check standalone XDP mode. |
| tracee/monitor | pending | pending | pending | Check feature-probe skips only. |

## Completed Micro Artifacts

| Artifact | Config | Result |
| --- | --- | --- |
| `micro/results/x86_kvm_micro_20260529_003919_048557` | pure bytecode, `RUNTIMES=kernel native_kernel llvmbpf native`, `SAMPLES=3`, `INNER_REPEAT=100000` | 29/29 correct; kernel native geomean speedup 1.478x over kernel eBPF; no kernel-native slowdowns. |
| `micro/results/x86_kvm_micro_20260529_004658_667642` | helpers/maps, `RUNTIMES=kernel native_kernel`, `SAMPLES=3`, `INNER_REPEAT=100000` | 13/13 correct; kernel native geomean speedup 1.429x over kernel eBPF; no slowdowns. |

## Implementation State To Validate

- Native stub no longer emits dummy runtime map-reference instructions.
- Stub load keeps module BTF fds in `fd_array[0..1]`, appends retained map fds,
  sets `fd_array_cnt`, then validates `prog_info.map_ids`.
- Native-link consumes typed JSON link plans from the loader.
- The current native path intentionally does not run bpfopt load-time passes in
  the corpus comparison.
