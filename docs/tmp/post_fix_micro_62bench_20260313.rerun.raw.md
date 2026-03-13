# Kernel Recompile Micro Strict

## Methodology

- Kernel: `7.0.0-rc2-g05a1845490ed-dirty`
- Benchmarks: `62` from `config/micro_pure_jit.yaml`
- Runtimes: `kernel` vs `kernel-recompile`
- Warmups / iterations / repeat: `2 / 2 / 500`
- CPU pinning: `taskset -c 0`
- CPU governor: `unknown`
- Turbo state: `unknown`

## Headline Numbers

- Overall geomean (stock / recompile, valid pairs only): `0.966x`
- Applied-only geomean (stock / recompile): `1.006x`
- Wins / losses / ties: `27 / 32 / 2`
- Valid / invalid pairs: `61 / 1`

## Per-Family Breakdown

| Family | Benchmarks | Valid | Applied | Geomean | Applied-only Geomean | Wins | Losses | Ties |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| addr-calc | 1 | 1 | 0 | 0.671x | n/a | 0 | 1 | 0 |
| baseline | 3 | 3 | 0 | 0.899x | n/a | 0 | 1 | 2 |
| bitfield-extract | 2 | 2 | 1 | 0.933x | 0.786x | 1 | 1 | 0 |
| bounds-density | 2 | 2 | 1 | 1.077x | 1.152x | 2 | 0 | 0 |
| bounds-style | 1 | 1 | 0 | 0.904x | n/a | 0 | 1 | 0 |
| bpf-local-call | 2 | 2 | 1 | 1.197x | 1.079x | 2 | 0 | 0 |
| branch-density | 1 | 1 | 1 | 1.011x | 1.011x | 1 | 0 | 0 |
| branch-fanout | 1 | 1 | 0 | 1.072x | n/a | 1 | 0 | 0 |
| branch-flip | 1 | 1 | 0 | 0.749x | n/a | 0 | 1 | 0 |
| branch-skew | 1 | 1 | 0 | 0.943x | n/a | 0 | 1 | 0 |
| byte-compare | 1 | 1 | 1 | 1.194x | 1.194x | 1 | 0 | 0 |
| causal-isolation | 2 | 2 | 0 | 0.938x | n/a | 1 | 1 | 0 |
| code-clone | 2 | 2 | 0 | 0.979x | n/a | 0 | 2 | 0 |
| const-fold | 1 | 1 | 0 | 0.739x | n/a | 0 | 1 | 0 |
| deep-guards | 1 | 1 | 0 | 0.835x | n/a | 0 | 1 | 0 |
| dep-chain | 2 | 2 | 0 | 1.001x | n/a | 1 | 1 | 0 |
| endian-fusion | 1 | 1 | 0 | 0.779x | n/a | 0 | 1 | 0 |
| field-access | 1 | 1 | 0 | 0.743x | n/a | 0 | 1 | 0 |
| fixed-loop | 2 | 2 | 0 | 1.226x | n/a | 1 | 1 | 0 |
| hash-chain | 1 | 1 | 0 | 1.101x | n/a | 1 | 0 | 0 |
| immediate-stress | 1 | 1 | 0 | 0.915x | n/a | 0 | 1 | 0 |
| large-mixed | 2 | 2 | 1 | 0.906x | 0.824x | 0 | 2 | 0 |
| load-width | 2 | 1 | 0 | 1.152x | n/a | 1 | 0 | 0 |
| log2-fold | 1 | 1 | 1 | 1.054x | 1.054x | 1 | 0 | 0 |
| mega-block | 1 | 1 | 0 | 0.868x | n/a | 0 | 1 | 0 |
| mixed-alu-mem | 1 | 1 | 1 | 0.918x | 0.918x | 0 | 1 | 0 |
| mixed-width | 1 | 1 | 0 | 1.126x | n/a | 1 | 0 | 0 |
| multi-acc | 2 | 2 | 0 | 1.110x | n/a | 1 | 1 | 0 |
| nested-loop | 2 | 2 | 0 | 0.958x | n/a | 0 | 2 | 0 |
| packet-hash | 1 | 1 | 0 | 0.457x | n/a | 0 | 1 | 0 |
| parser | 2 | 2 | 0 | 1.080x | n/a | 1 | 1 | 0 |
| popcount | 2 | 2 | 0 | 1.019x | n/a | 1 | 1 | 0 |
| recurrence | 2 | 2 | 0 | 1.049x | n/a | 2 | 0 | 0 |
| reduction | 2 | 2 | 0 | 1.047x | n/a | 2 | 0 | 0 |
| rotate-canonical | 1 | 1 | 1 | 1.161x | 1.161x | 1 | 0 | 0 |
| rotate-hash | 1 | 1 | 0 | 0.806x | n/a | 0 | 1 | 0 |
| search | 1 | 1 | 1 | 1.141x | 1.141x | 1 | 0 | 0 |
| select-diamond | 3 | 3 | 3 | 1.003x | 1.003x | 2 | 1 | 0 |
| spill-pressure | 1 | 1 | 0 | 0.961x | n/a | 0 | 1 | 0 |
| strength-reduce | 1 | 1 | 0 | 0.727x | n/a | 0 | 1 | 0 |
| stride-load | 2 | 2 | 0 | 1.014x | n/a | 1 | 1 | 0 |
| switch-dispatch | 1 | 1 | 1 | 0.869x | 0.869x | 0 | 1 | 0 |

## Per-Benchmark Table

| Benchmark | Family | Stock median | Recompile median | Stock/Recompile | Applied | Sites | Status |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| simple | baseline | 8 ns | 8 ns | 1.000x | no | 0 | tie |
| simple_packet | baseline | 7.5 ns | 7.5 ns | 1.000x | no | 0 | tie |
| memory_pair_sum | baseline | 8 ns | 11 ns | 0.727x | no | 0 | loss |
| bitcount | popcount | 4.837 us | 4.543 us | 1.065x | no | 0 | win |
| log2_fold | log2-fold | 393.5 ns | 373.5 ns | 1.054x | yes | 3 | win |
| dep_chain_short | dep-chain | 156.5 ns | 155 ns | 1.010x | no | 0 | win |
| dep_chain_long | dep-chain | 576.5 ns | 581 ns | 0.992x | no | 0 | loss |
| binary_search | search | 639 ns | 560 ns | 1.141x | yes | 3 | win |
| branch_layout | branch-skew | 631.5 ns | 670 ns | 0.943x | no | 0 | loss |
| switch_dispatch | switch-dispatch | 343 ns | 394.5 ns | 0.869x | yes | 3 | loss |
| branch_dense | branch-density | 589 ns | 582.5 ns | 1.011x | yes | 7 | win |
| cmov_select | select-diamond | 666.5 ns | 659.5 ns | 1.011x | yes | 1 | win |
| cmov_dense | select-diamond | 60 ns | 47 ns | 1.277x | yes | 26 | win |
| checksum | reduction | 19.375 us | 17.721 us | 1.093x | no | 0 | win |
| load_word32 | load-width | 121 ns | 105 ns | 1.152x | no | 0 | win |
| load_byte | load-width | n/a | n/a | n/a | no | 0 | command-failed / command-failed |
| load_byte_recompose | causal-isolation | 184.5 ns | 222 ns | 0.831x | no | 0 | loss |
| load_native_u64 | causal-isolation | 97.5 ns | 92 ns | 1.060x | no | 0 | win |
| packet_parse | parser | 95 ns | 114 ns | 0.833x | no | 0 | loss |
| bounds_ladder | bounds-density | 212 ns | 184 ns | 1.152x | yes | 4 | win |
| bounds_check_heavy | bounds-style | 276.5 ns | 306 ns | 0.904x | no | 0 | loss |
| stride_load_4 | stride-load | 233 ns | 279 ns | 0.835x | no | 0 | loss |
| stride_load_16 | stride-load | 287 ns | 233 ns | 1.232x | no | 0 | win |
| mixed_alu_mem | mixed-alu-mem | 852 ns | 928.5 ns | 0.918x | yes | 3 | loss |
| spill_pressure | spill-pressure | 381.5 ns | 397 ns | 0.961x | no | 0 | loss |
| multi_acc_4 | multi-acc | 394 ns | 299.5 ns | 1.316x | no | 0 | win |
| multi_acc_8 | multi-acc | 561 ns | 598.5 ns | 0.937x | no | 0 | loss |
| fibonacci_iter | recurrence | 943.5 ns | 877 ns | 1.076x | no | 0 | win |
| fibonacci_iter_packet | recurrence | 936 ns | 914.5 ns | 1.024x | no | 0 | win |
| fixed_loop_small | fixed-loop | 156.5 ns | 104 ns | 1.505x | no | 0 | win |
| fixed_loop_large | fixed-loop | 1.510 us | 1.512 us | 0.999x | no | 0 | loss |
| nested_loop_2 | nested-loop | 611.5 ns | 633.5 ns | 0.965x | no | 0 | loss |
| nested_loop_3 | nested-loop | 822 ns | 864.5 ns | 0.951x | no | 0 | loss |
| code_clone_2 | code-clone | 420 ns | 437 ns | 0.961x | no | 0 | loss |
| code_clone_8 | code-clone | 1.499 us | 1.503 us | 0.997x | no | 0 | loss |
| large_mixed_500 | large-mixed | 591 ns | 717 ns | 0.824x | yes | 3 | loss |
| large_mixed_1000 | large-mixed | 1.234 us | 1.240 us | 0.996x | no | 0 | loss |
| bpf_call_chain | bpf-local-call | 507.5 ns | 470.5 ns | 1.079x | yes | 3 | win |
| memcmp_prefix_64 | byte-compare | 135.5 ns | 113.5 ns | 1.194x | yes | 3 | win |
| packet_parse_vlans_tcpopts | parser | 21 ns | 15 ns | 1.400x | no | 0 | win |
| local_call_fanout | bpf-local-call | 166 ns | 125 ns | 1.328x | no | 0 | win |
| packet_rss_hash | packet-hash | 16 ns | 35 ns | 0.457x | no | 0 | loss |
| imm64_storm | immediate-stress | 188 ns | 205.5 ns | 0.915x | no | 0 | loss |
| alu32_64_pingpong | mixed-width | 580.5 ns | 515.5 ns | 1.126x | no | 0 | win |
| branch_fanout_32 | branch-fanout | 440 ns | 410.5 ns | 1.072x | no | 0 | win |
| deep_guard_tree_8 | deep-guards | 113.5 ns | 136 ns | 0.835x | no | 0 | loss |
| mega_basic_block_2048 | mega-block | 935 ns | 1.077 us | 0.868x | no | 0 | loss |
| rotate64_hash | rotate-hash | 56 ns | 69.5 ns | 0.806x | no | 0 | loss |
| packet_redundant_bounds | bounds-density | 144.5 ns | 143.5 ns | 1.007x | no | 0 | win |
| const_fold_chain | const-fold | 292.5 ns | 396 ns | 0.739x | no | 0 | loss |
| struct_field_cluster | field-access | 65 ns | 87.5 ns | 0.743x | no | 0 | loss |
| bitfield_extract | bitfield-extract | 327 ns | 295 ns | 1.108x | no | 0 | win |
| smallmul_strength_reduce | strength-reduce | 327 ns | 450 ns | 0.727x | no | 0 | loss |
| cond_select_dense | select-diamond | 56 ns | 71.5 ns | 0.783x | yes | 1 | loss |
| rotate_dense | rotate-canonical | 234.5 ns | 202 ns | 1.161x | yes | 5 | win |
| addr_calc_stride | addr-calc | 134.5 ns | 200.5 ns | 0.671x | no | 0 | loss |
| extract_dense | bitfield-extract | 147 ns | 187 ns | 0.786x | yes | 1 | loss |
| endian_swap_dense | endian-fusion | 144.5 ns | 185.5 ns | 0.779x | no | 0 | loss |
| branch_flip_dense | branch-flip | 178 ns | 237.5 ns | 0.749x | no | 0 | loss |
| tc_bitcount | popcount | 4.636 us | 4.750 us | 0.976x | no | 0 | loss |
| tc_checksum | reduction | 17.756 us | 17.707 us | 1.003x | no | 0 | win |
| cgroup_hash_chain | hash-chain | 353.5 ns | 321 ns | 1.101x | no | 0 | win |
