# New Benchmark Authoritative Summary

Inputs:
- `micro/results/new_benchmarks_authoritative.json`
- `micro/results/new_runtime_authoritative.json`
- Parameters: `30` iterations, `5` warmups, `1000` repeats, `llvmbpf` vs `kernel`, `--strict-env`, pinned to CPU `6`.

## Per-benchmark Results

| Benchmark | Suite | llvmbpf exec_ns median | kernel exec_ns median | Exec ratio (L/K) | llvmbpf code_size (B) | kernel code_size (B) | Code-size ratio (L/K) | Exec winner |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: | --- |
| `memcmp_prefix_64` | pure-jit | 112 | 135 | 0.830x | 483 | 650 | 0.743x | llvmbpf |
| `packet_parse_vlans_tcpopts` | pure-jit | 25 | 28 | 0.893x | 677 | 1111 | 0.609x | llvmbpf |
| `local_call_fanout` | pure-jit | 108.5 | 150.5 | 0.721x | 815 | 2222 | 0.367x | llvmbpf |
| `packet_rss_hash` | pure-jit | 31.5 | 29 | 1.086x | 630 | 1010 | 0.624x | kernel |
| `imm64_storm` | pure-jit | 210.5 | 216.5 | 0.972x | 4623 | 6433 | 0.719x | llvmbpf |
| `alu32_64_pingpong` | pure-jit | 300 | 509.5 | 0.589x | 508 | 668 | 0.760x | llvmbpf |
| `branch_fanout_32` | pure-jit | 332.5 | 397 | 0.838x | 2327 | 1939 | 1.200x | llvmbpf |
| `deep_guard_tree_8` | pure-jit | 72 | 117.5 | 0.613x | 396 | 710 | 0.558x | llvmbpf |
| `mega_basic_block_2048` | pure-jit | 921 | 964.5 | 0.955x | 30731 | 49512 | 0.621x | llvmbpf |
| `atomic_counter_xadd` | runtime | 388.5 | 385 | 1.009x | 475 | 678 | 0.701x | kernel |

## Geomean

| Scope | Exec ratio geomean (L/K) | Code-size ratio geomean (L/K) |
| --- | ---: | ---: |
| All 10 new benchmarks | 0.835x | 0.663x |
| 9 new pure-JIT benchmarks | 0.817x | 0.659x |

## Win Sets

- `llvmbpf` exec wins (`8/10`): `memcmp_prefix_64`, `packet_parse_vlans_tcpopts`, `local_call_fanout`, `imm64_storm`, `alu32_64_pingpong`, `branch_fanout_32`, `deep_guard_tree_8`, `mega_basic_block_2048`
- `kernel` exec wins (`2/10`): `packet_rss_hash`, `atomic_counter_xadd`
- `llvmbpf` smaller native code on `9/10`; `kernel` smaller native code on `1/10`.

## Patterns

- Overall, the new additions preserve the main trend: `llvmbpf` wins `8/10` on execution time with an all-benchmark exec geomean of `0.835x`, while shrinking native code to `0.663x` of the kernel JIT on average.
- `local_call_fanout` is not a kernel-favoring exception here. `llvmbpf` is materially faster (`0.721x`) and much smaller (`0.367x`), so call-site layout and register allocation dominated any advantage from the kernel's existing BPF local-call support.
- The smaller-but-slower cases are `packet_rss_hash` and `atomic_counter_xadd`. `packet_rss_hash` is the stronger example: `llvmbpf` emits only `0.624x` of the native code size but runs at `1.086x`, which reinforces that mixed parse-plus-hash hot paths are not explained by code size alone. `atomic_counter_xadd` is effectively parity and likely dominated by map/runtime overhead plus atomic update mechanics rather than JIT code quality.
- `branch_fanout_32` is the inverse case: `llvmbpf` is faster (`0.838x`) despite larger native code (`1.200x`), which points to branch layout and hot-path structure mattering more than raw byte count.
- Program-scale cases such as `imm64_storm` and `mega_basic_block_2048` show large code-size reductions without equally large runtime gains. `mega_basic_block_2048` drops to `0.621x` of kernel code size but only improves to `0.955x`, so steady-state throughput still depends on the executed dependence chain, not just emitted bytes.
- The strongest `llvmbpf` speedups in this batch are `alu32_64_pingpong` (0.589x), `deep_guard_tree_8` (0.613x), and `local_call_fanout` (0.721x). The strongest kernel-side result is `packet_rss_hash` (1.086x).
