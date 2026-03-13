# Kernel Recompile Micro Strict

## Methodology

- Kernel: `7.0.0-rc2-g05a1845490ed-dirty`
- Benchmarks: `41` from `config/micro_pure_jit.yaml`
- Runtimes: `kernel` vs `kernel-recompile`
- Warmups / iterations / repeat: `2 / 2 / 500`
- CPU pinning: `taskset -c 0`
- CPU governor: `unknown`
- Turbo state: `unknown`

## Headline Numbers

- Overall geomean (stock / recompile, valid pairs only): `0.988x`
- Applied-only geomean (stock / recompile): `1.001x`
- Wins / losses / ties: `16 / 23 / 2`
- Valid / invalid pairs: `41 / 0`

## Per-Family Breakdown

| Family | Benchmarks | Valid | Applied | Geomean | Applied-only Geomean | Wins | Losses | Ties |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| baseline | 3 | 3 | 0 | 0.928x | n/a | 0 | 1 | 2 |
| bounds-density | 1 | 1 | 1 | 1.123x | 1.123x | 1 | 0 | 0 |
| bounds-style | 1 | 1 | 0 | 0.901x | n/a | 0 | 1 | 0 |
| bpf-local-call | 2 | 2 | 1 | 0.751x | 0.779x | 0 | 2 | 0 |
| branch-density | 1 | 1 | 1 | 1.039x | 1.039x | 1 | 0 | 0 |
| branch-skew | 1 | 1 | 0 | 1.117x | n/a | 1 | 0 | 0 |
| byte-compare | 1 | 1 | 1 | 0.869x | 0.869x | 0 | 1 | 0 |
| causal-isolation | 2 | 2 | 0 | 0.908x | n/a | 0 | 2 | 0 |
| code-clone | 2 | 2 | 0 | 0.970x | n/a | 1 | 1 | 0 |
| dep-chain | 2 | 2 | 0 | 1.018x | n/a | 1 | 1 | 0 |
| fixed-loop | 2 | 2 | 0 | 1.171x | n/a | 1 | 1 | 0 |
| large-mixed | 2 | 2 | 1 | 0.926x | 0.860x | 0 | 2 | 0 |
| load-width | 2 | 2 | 0 | 1.162x | n/a | 2 | 0 | 0 |
| log2-fold | 1 | 1 | 1 | 1.206x | 1.206x | 1 | 0 | 0 |
| mixed-alu-mem | 1 | 1 | 1 | 1.018x | 1.018x | 1 | 0 | 0 |
| multi-acc | 2 | 2 | 0 | 0.989x | n/a | 0 | 2 | 0 |
| nested-loop | 2 | 2 | 0 | 1.081x | n/a | 2 | 0 | 0 |
| parser | 2 | 2 | 0 | 0.861x | n/a | 0 | 2 | 0 |
| popcount | 1 | 1 | 0 | 1.010x | n/a | 1 | 0 | 0 |
| recurrence | 2 | 2 | 0 | 0.999x | n/a | 1 | 1 | 0 |
| reduction | 1 | 1 | 0 | 0.995x | n/a | 0 | 1 | 0 |
| search | 1 | 1 | 1 | 0.935x | 0.935x | 0 | 1 | 0 |
| select-diamond | 2 | 2 | 2 | 1.240x | 1.240x | 1 | 1 | 0 |
| spill-pressure | 1 | 1 | 0 | 0.923x | n/a | 0 | 1 | 0 |
| stride-load | 2 | 2 | 0 | 0.942x | n/a | 1 | 1 | 0 |
| switch-dispatch | 1 | 1 | 1 | 0.840x | 0.840x | 0 | 1 | 0 |

## Per-Benchmark Table

| Benchmark | Family | Stock median | Recompile median | Stock/Recompile | Applied | Sites | Status |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| simple | baseline | 9 ns | 9 ns | 1.000x | no | 0 | tie |
| simple_packet | baseline | 6 ns | 6 ns | 1.000x | no | 0 | tie |
| memory_pair_sum | baseline | 8 ns | 10 ns | 0.800x | no | 0 | loss |
| bitcount | popcount | 4.615 us | 4.569 us | 1.010x | no | 0 | win |
| log2_fold | log2-fold | 470.5 ns | 390 ns | 1.206x | yes | 3 | win |
| dep_chain_short | dep-chain | 154.5 ns | 160 ns | 0.966x | no | 0 | loss |
| dep_chain_long | dep-chain | 631.5 ns | 588 ns | 1.074x | no | 0 | win |
| binary_search | search | 618 ns | 661 ns | 0.935x | yes | 3 | loss |
| branch_layout | branch-skew | 694.5 ns | 622 ns | 1.117x | no | 0 | win |
| switch_dispatch | switch-dispatch | 308 ns | 366.5 ns | 0.840x | yes | 3 | loss |
| branch_dense | branch-density | 662 ns | 637 ns | 1.039x | yes | 7 | win |
| cmov_select | select-diamond | 582 ns | 654.5 ns | 0.889x | yes | 1 | loss |
| cmov_dense | select-diamond | 60.5 ns | 35 ns | 1.729x | yes | 26 | win |
| checksum | reduction | 17.794 us | 17.887 us | 0.995x | no | 0 | loss |
| load_word32 | load-width | 103.5 ns | 83.5 ns | 1.240x | no | 0 | win |
| load_byte | load-width | 354.5 ns | 325.5 ns | 1.089x | no | 0 | win |
| load_byte_recompose | causal-isolation | 205 ns | 218 ns | 0.940x | no | 0 | loss |
| load_native_u64 | causal-isolation | 113 ns | 129 ns | 0.876x | no | 0 | loss |
| packet_parse | parser | 105 ns | 110.5 ns | 0.950x | no | 0 | loss |
| bounds_ladder | bounds-density | 224 ns | 199.5 ns | 1.123x | yes | 4 | win |
| bounds_check_heavy | bounds-style | 296 ns | 328.5 ns | 0.901x | no | 0 | loss |
| stride_load_4 | stride-load | 269 ns | 349 ns | 0.771x | no | 0 | loss |
| stride_load_16 | stride-load | 306.5 ns | 266 ns | 1.152x | no | 0 | win |
| mixed_alu_mem | mixed-alu-mem | 816 ns | 801.5 ns | 1.018x | yes | 3 | win |
| spill_pressure | spill-pressure | 411 ns | 445.5 ns | 0.923x | no | 0 | loss |
| multi_acc_4 | multi-acc | 311.5 ns | 316 ns | 0.986x | no | 0 | loss |
| multi_acc_8 | multi-acc | 562.5 ns | 567 ns | 0.992x | no | 0 | loss |
| fibonacci_iter | recurrence | 876.5 ns | 925 ns | 0.948x | no | 0 | loss |
| fibonacci_iter_packet | recurrence | 927 ns | 880.5 ns | 1.053x | no | 0 | win |
| fixed_loop_small | fixed-loop | 157 ns | 114 ns | 1.377x | no | 0 | win |
| fixed_loop_large | fixed-loop | 1.480 us | 1.486 us | 0.996x | no | 0 | loss |
| nested_loop_2 | nested-loop | 659.5 ns | 575 ns | 1.147x | no | 0 | win |
| nested_loop_3 | nested-loop | 860 ns | 844 ns | 1.019x | no | 0 | win |
| code_clone_2 | code-clone | 370 ns | 396 ns | 0.934x | no | 0 | loss |
| code_clone_8 | code-clone | 1.492 us | 1.482 us | 1.007x | no | 0 | win |
| large_mixed_500 | large-mixed | 618.5 ns | 719 ns | 0.860x | yes | 3 | loss |
| large_mixed_1000 | large-mixed | 1.213 us | 1.217 us | 0.997x | no | 0 | loss |
| bpf_call_chain | bpf-local-call | 419 ns | 538 ns | 0.779x | yes | 3 | loss |
| memcmp_prefix_64 | byte-compare | 135.5 ns | 156 ns | 0.869x | yes | 3 | loss |
| packet_parse_vlans_tcpopts | parser | 16 ns | 20.5 ns | 0.780x | no | 0 | loss |
| local_call_fanout | bpf-local-call | 125 ns | 172.5 ns | 0.725x | no | 0 | loss |
