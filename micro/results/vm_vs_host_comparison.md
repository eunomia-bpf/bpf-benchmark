# VM vs Host Benchmark Comparison

## Run metadata

- Host authoritative file: `micro/results/pure_jit_authoritative.json`
- VM result file: `tmp/vm_authoritative.json`
- Host kernel: `6.15.11-061511-generic`
- VM kernel: `7.0.0-rc2-gc23719abc330`
- Host authoritative parameters: 30 iterations, 5 warmups, 1000 repeat, `--strict-env`
- VM run parameters: 10 iterations, 2 warmups, 500 repeat, kernel runtime only
- Comparison basis: kernel `exec_ns` median for each benchmark
- Overlap used for comparison: 31 host benchmarks
- VM-only benchmarks not in the host authoritative file: `bpf_call_chain, load_byte, load_byte_recompose, load_native_u64, load_word32`

## Summary

- Geometric mean of VM/Host kernel median ratios across the 31 overlapping benchmarks: `0.881x`
- Benchmarks faster in the VM (ratio < 1.0): `23`
- Benchmarks slower in the VM (ratio > 1.0): `8`

Fastest relative to host:
- `simple_packet`: host `17.0 ns`, VM `7.0 ns`, ratio `0.412x`
- `multi_acc_8`: host `470.5 ns`, VM `307.5 ns`, ratio `0.654x`
- `bounds_check_heavy`: host `258.0 ns`, VM `190.0 ns`, ratio `0.736x`
- `memory_pair_sum`: host `17.5 ns`, VM `13.0 ns`, ratio `0.743x`
- `spill_pressure`: host `284.5 ns`, VM `221.0 ns`, ratio `0.777x`

Slowest relative to host:
- `code_clone_2`: host `303.5 ns`, VM `369.0 ns`, ratio `1.216x`
- `multi_acc_4`: host `260.0 ns`, VM `287.5 ns`, ratio `1.106x`
- `bounds_ladder`: host `202.0 ns`, VM `217.5 ns`, ratio `1.077x`
- `binary_search`: host `454.0 ns`, VM `475.5 ns`, ratio `1.047x`
- `simple`: host `12.0 ns`, VM `12.5 ns`, ratio `1.042x`

## Per-benchmark Medians

| Benchmark | Host 6.15 kernel exec_ns median | VM 7.0-rc2 kernel exec_ns median | VM/Host |
| --- | ---: | ---: | ---: |
| `simple` | 12.0 | 12.5 | 1.042x |
| `simple_packet` | 17.0 | 7.0 | 0.412x |
| `memory_pair_sum` | 17.5 | 13.0 | 0.743x |
| `bitcount` | 3035.5 | 2990.5 | 0.985x |
| `log2_fold` | 320.0 | 271.0 | 0.847x |
| `dep_chain_short` | 149.0 | 152.5 | 1.023x |
| `dep_chain_long` | 412.0 | 366.5 | 0.890x |
| `binary_search` | 454.0 | 475.5 | 1.047x |
| `branch_layout` | 530.0 | 539.0 | 1.017x |
| `switch_dispatch` | 271.5 | 252.5 | 0.930x |
| `branch_dense` | 427.5 | 433.5 | 1.014x |
| `checksum` | 12055.5 | 11939.0 | 0.990x |
| `packet_parse` | 86.5 | 79.0 | 0.913x |
| `bounds_ladder` | 202.0 | 217.5 | 1.077x |
| `bounds_check_heavy` | 258.0 | 190.0 | 0.736x |
| `stride_load_4` | 238.0 | 220.0 | 0.924x |
| `stride_load_16` | 254.5 | 198.0 | 0.778x |
| `mixed_alu_mem` | 676.5 | 606.5 | 0.897x |
| `spill_pressure` | 284.5 | 221.0 | 0.777x |
| `multi_acc_4` | 260.0 | 287.5 | 1.106x |
| `multi_acc_8` | 470.5 | 307.5 | 0.654x |
| `fibonacci_iter` | 723.5 | 686.0 | 0.948x |
| `fibonacci_iter_packet` | 745.5 | 614.0 | 0.824x |
| `fixed_loop_small` | 142.0 | 111.5 | 0.785x |
| `fixed_loop_large` | 1255.0 | 1045.5 | 0.833x |
| `nested_loop_2` | 515.0 | 439.5 | 0.853x |
| `nested_loop_3` | 669.0 | 584.5 | 0.874x |
| `code_clone_2` | 303.5 | 369.0 | 1.216x |
| `code_clone_8` | 1184.5 | 1032.0 | 0.871x |
| `large_mixed_500` | 496.5 | 451.5 | 0.909x |
| `large_mixed_1000` | 987.5 | 839.5 | 0.850x |

## Notes

- The host authoritative JSON was produced with a stricter and longer run configuration than the VM run, so treat this as a reduced-but-substantial comparison rather than a publication-grade replacement for the host data.
- The VM run emitted environment warnings in the guest (`cpu_governor` unknown, turbo enabled, `perf_event_paranoid=2`, no CPU affinity). Those warnings do not invalidate the JSON, but they matter when interpreting small deltas.
