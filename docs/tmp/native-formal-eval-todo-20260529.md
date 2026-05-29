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
| otelcol-ebpf-profiler/profiling | `corpus/results/x86_kvm_corpus_20260529_021623_817446` | `corpus/results/x86_kvm_corpus_20260529_024714_858694` | `corpus/results/x86_kvm_corpus_20260529_031718_784847` | Status ok; 14 native replacements; native-loader failure/no-manifest/reloc/fallback counts all 0. Stats-on `native_tracer_e`: 3210 ns/run -> 217 ns/run; `tracepoint__sch`: 1839 -> 636 ns/run. Tail-called unwind programs still report run_cnt=0, so savings are accounted at `native_tracer_e`. Stats-off workload: total int-loop throughput 43.4M -> 78.7M ops/s (1.81x); CPU stress-ng 838 -> 1034 ops/s (1.23x). No-eBPF total int-loop throughput is 109.3M ops/s and CPU stress-ng is 1513 ops/s; native recovers about 72% of no-eBPF int-loop throughput vs 40% for kernel eBPF. |
| cilium/agent | `corpus/results/x86_kvm_corpus_20260529_033517_489159` | `corpus/results/x86_kvm_corpus_20260529_040554_604387` | `corpus/results/x86_kvm_corpus_20260529_043720_016160` | Status ok; 135 native replacements; native-loader failure/no-manifest/reloc/fallback counts all 0. Stats-on retained entry programs are the two `cil_from_contai` directions: avg 486-491 ns/run -> 261-264 ns/run, about 1.86x faster. Endpoint pktgen workload had 0 errors in all runs. Stats-on aggregate pps: 1.56M -> 3.51M; stats-off aggregate pps: 1.63M -> 3.88M (2.38x). No-eBPF workload-only aggregate pps: 2.41M with 0 errors; this is not a strict upper bound for Cilium because workload-only bypasses the Cilium datapath setup rather than replacing the native/eBPF program in the same path. |
| tetragon/observer | `corpus/results/x86_kvm_corpus_20260529_045551_393389` | `corpus/results/x86_kvm_corpus_20260529_052633_700199` | `corpus/results/x86_kvm_corpus_20260529_055644_747412` | Status ok; 288 native replacements; native-loader failure/no-manifest/reloc/fallback counts all 0. Stats-off workload ratios native/eBPF: eventfd 1.32x, mmap 4.75x, sock 2.41x, sockfd 1.05x, sockpair 1.71x, udp 1.43x. No-eBPF remains much faster: native reaches 23%-47% of no-eBPF throughput depending on stressor. Per-program counter matching is weak here because many Tetragon program names are truncated to duplicate `generic_kprobe_`/`generic_retkpro`; workload data is the reliable correctness/performance signal. |
| katran | `corpus/results/x86_kvm_corpus_20260529_061439_040837` | `corpus/results/x86_kvm_corpus_20260529_064444_673720` | `corpus/results/x86_kvm_corpus_20260529_071439_317979` | Status ok; standalone XDP mode replaced 1 `balancer_ingres` program; native-loader failure/no-manifest/reloc/fallback counts all 0. Stats-on counter: `balancer_ingres` 178.3 ns/run -> 142.4 ns/run (1.25x). Stats-off aggregate pktgen pps: 2.93M -> 3.25M (1.11x). No-eBPF workload-only aggregate pps: 8.44M; native reaches 38% of no-eBPF vs 35% for kernel eBPF. Katran pktgen reports high `errors` while the app status remains ok; this appears to be workload forwarding/drop accounting rather than a Cilium-style correctness error and needs explicit methodology text. |
| tracee/monitor | `corpus/results/x86_kvm_corpus_20260529_073309_993570` | `corpus/results/x86_kvm_corpus_20260529_080408_588450` | `corpus/results/x86_kvm_corpus_20260529_083605_206833` | Status ok; 169 native replacements; native-loader failure/no-manifest/reloc/fallback counts all 0. Stats-on aggregate BPF counters are neutral/slightly slower: 324.5 ns/run -> 330.9 ns/run. Stats-off workload median native/eBPF ratios: cap 0.96x, eventfd 0.96x, futex 1.02x, kill 0.98x, prctl 0.98x, set 0.95x, sigfd 0.93x; aggregate workload ratio is 0.958x. No-eBPF remains much faster: native reaches about 13% of no-eBPF aggregate throughput. |

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
