# Kernel Recompile Micro Strict

## Methodology

- Kernel: `7.0.0-rc2-ga7ce05b49cb2-dirty`
- Benchmarks: `62` from `config/micro_pure_jit.yaml`
- Runtimes: `kernel` vs `kernel-recompile`
- Warmups / iterations / repeat: `2 / 2 / 500`
- CPU pinning: `taskset -c 0`
- CPU governor: `unknown`
- Turbo state: `unknown`

## Headline Numbers

- Overall geomean (stock / recompile, valid pairs only): `1.003x`
- Applied-only geomean (stock / recompile): `0.932x`
- Wins / losses / ties: `30 / 30 / 1`
- Valid / invalid pairs: `61 / 1`

## Per-Family Breakdown

| Family | Benchmarks | Valid | Applied | Geomean | Applied-only Geomean | Wins | Losses | Ties |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| addr-calc | 1 | 1 | 1 | 1.401x | 1.401x | 1 | 0 | 0 |
| baseline | 3 | 3 | 0 | 1.010x | n/a | 1 | 1 | 1 |
| bitfield-extract | 2 | 2 | 1 | 0.846x | 0.556x | 1 | 1 | 0 |
| bounds-density | 2 | 2 | 1 | 1.056x | 1.173x | 1 | 1 | 0 |
| bounds-style | 1 | 1 | 0 | 1.080x | n/a | 1 | 0 | 0 |
| bpf-local-call | 2 | 2 | 1 | 0.968x | 0.990x | 0 | 2 | 0 |
| branch-density | 1 | 1 | 1 | 1.137x | 1.137x | 1 | 0 | 0 |
| branch-fanout | 1 | 1 | 0 | 0.991x | n/a | 0 | 1 | 0 |
| branch-flip | 1 | 1 | 1 | 1.052x | 1.052x | 1 | 0 | 0 |
| branch-skew | 1 | 1 | 0 | 0.907x | n/a | 0 | 1 | 0 |
| byte-compare | 1 | 1 | 1 | 0.937x | 0.937x | 0 | 1 | 0 |
| causal-isolation | 2 | 2 | 0 | 1.050x | n/a | 2 | 0 | 0 |
| code-clone | 2 | 2 | 0 | 1.007x | n/a | 1 | 1 | 0 |
| const-fold | 1 | 1 | 0 | 0.908x | n/a | 0 | 1 | 0 |
| deep-guards | 1 | 1 | 0 | 0.921x | n/a | 0 | 1 | 0 |
| dep-chain | 2 | 2 | 0 | 0.973x | n/a | 1 | 1 | 0 |
| endian-fusion | 1 | 1 | 1 | 0.695x | 0.695x | 0 | 1 | 0 |
| field-access | 1 | 1 | 0 | 1.017x | n/a | 1 | 0 | 0 |
| fixed-loop | 2 | 2 | 0 | 1.005x | n/a | 1 | 1 | 0 |
| hash-chain | 1 | 1 | 0 | 0.974x | n/a | 0 | 1 | 0 |
| immediate-stress | 1 | 1 | 0 | 1.286x | n/a | 1 | 0 | 0 |
| large-mixed | 2 | 2 | 1 | 1.003x | 0.971x | 1 | 1 | 0 |
| load-width | 2 | 2 | 0 | 1.054x | n/a | 2 | 0 | 0 |
| log2-fold | 1 | 1 | 1 | 0.968x | 0.968x | 0 | 1 | 0 |
| mega-block | 1 | 1 | 0 | 0.961x | n/a | 0 | 1 | 0 |
| mixed-alu-mem | 1 | 1 | 1 | 0.880x | 0.880x | 0 | 1 | 0 |
| mixed-width | 1 | 1 | 0 | 0.995x | n/a | 0 | 1 | 0 |
| multi-acc | 2 | 2 | 0 | 1.127x | n/a | 1 | 1 | 0 |
| nested-loop | 2 | 2 | 0 | 1.121x | n/a | 2 | 0 | 0 |
| packet-hash | 1 | 1 | 0 | 1.088x | n/a | 1 | 0 | 0 |
| parser | 2 | 2 | 0 | 1.153x | n/a | 1 | 1 | 0 |
| popcount | 2 | 2 | 0 | 1.008x | n/a | 1 | 1 | 0 |
| recurrence | 2 | 2 | 0 | 0.952x | n/a | 0 | 2 | 0 |
| reduction | 2 | 2 | 0 | 0.963x | n/a | 0 | 2 | 0 |
| rotate-canonical | 1 | 1 | 1 | 1.167x | 1.167x | 1 | 0 | 0 |
| rotate-hash | 1 | 1 | 0 | 1.123x | n/a | 1 | 0 | 0 |
| search | 1 | 1 | 1 | 1.112x | 1.112x | 1 | 0 | 0 |
| select-diamond | 3 | 2 | 2 | 0.650x | 0.650x | 0 | 2 | 0 |
| spill-pressure | 1 | 1 | 0 | 1.096x | n/a | 1 | 0 | 0 |
| strength-reduce | 1 | 1 | 0 | 1.096x | n/a | 1 | 0 | 0 |
| stride-load | 2 | 2 | 0 | 0.963x | n/a | 1 | 1 | 0 |
| switch-dispatch | 1 | 1 | 1 | 1.017x | 1.017x | 1 | 0 | 0 |

## Per-Benchmark Table

| Benchmark | Family | Stock median | Recompile median | Stock/Recompile | Applied | Sites | Status |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| simple | baseline | 6.5 ns | 8 ns | 0.812x | no | 0 | loss |
| simple_packet | baseline | 6 ns | 6 ns | 1.000x | no | 0 | tie |
| memory_pair_sum | baseline | 9.5 ns | 7.5 ns | 1.267x | no | 0 | win |
| bitcount | popcount | 4.956 us | 4.983 us | 0.995x | no | 0 | loss |
| log2_fold | log2-fold | 363 ns | 375 ns | 0.968x | yes | 3 | loss |
| dep_chain_short | dep-chain | 135.5 ns | 133 ns | 1.019x | no | 0 | win |
| dep_chain_long | dep-chain | 499.5 ns | 538 ns | 0.928x | no | 0 | loss |
| binary_search | search | 711 ns | 639.5 ns | 1.112x | yes | 3 | win |
| branch_layout | branch-skew | 570.5 ns | 629 ns | 0.907x | no | 0 | loss |
| switch_dispatch | switch-dispatch | 357 ns | 351 ns | 1.017x | yes | 3 | win |
| branch_dense | branch-density | 636.5 ns | 560 ns | 1.137x | yes | 7 | win |
| cmov_select | select-diamond | 574.5 ns | 655 ns | 0.877x | yes | 1 | loss |
| cmov_dense | select-diamond | n/a | n/a | n/a | no | 0 | command-failed / command-failed |
| checksum | reduction | 17.765 us | 17.799 us | 0.998x | no | 0 | loss |
| load_word32 | load-width | 80.5 ns | 78.5 ns | 1.025x | no | 0 | win |
| load_byte | load-width | 326.5 ns | 301.5 ns | 1.083x | no | 0 | win |
| load_byte_recompose | causal-isolation | 167.5 ns | 165.5 ns | 1.012x | no | 0 | win |
| load_native_u64 | causal-isolation | 84.5 ns | 77.5 ns | 1.090x | no | 0 | win |
| packet_parse | parser | 93 ns | 100.5 ns | 0.925x | no | 0 | loss |
| bounds_ladder | bounds-density | 234.5 ns | 200 ns | 1.173x | yes | 4 | win |
| bounds_check_heavy | bounds-style | 318 ns | 294.5 ns | 1.080x | no | 0 | win |
| stride_load_4 | stride-load | 268.5 ns | 263.5 ns | 1.019x | no | 0 | win |
| stride_load_16 | stride-load | 312.5 ns | 343.5 ns | 0.910x | no | 0 | loss |
| mixed_alu_mem | mixed-alu-mem | 863 ns | 981 ns | 0.880x | yes | 3 | loss |
| spill_pressure | spill-pressure | 409.5 ns | 373.5 ns | 1.096x | no | 0 | win |
| multi_acc_4 | multi-acc | 379 ns | 270.5 ns | 1.401x | no | 0 | win |
| multi_acc_8 | multi-acc | 503 ns | 555 ns | 0.906x | no | 0 | loss |
| fibonacci_iter | recurrence | 877.5 ns | 905 ns | 0.970x | no | 0 | loss |
| fibonacci_iter_packet | recurrence | 911.5 ns | 975 ns | 0.935x | no | 0 | loss |
| fixed_loop_small | fixed-loop | 106.5 ns | 104.5 ns | 1.019x | no | 0 | win |
| fixed_loop_large | fixed-loop | 1.467 us | 1.479 us | 0.992x | no | 0 | loss |
| nested_loop_2 | nested-loop | 615 ns | 592 ns | 1.039x | no | 0 | win |
| nested_loop_3 | nested-loop | 949.5 ns | 785.5 ns | 1.209x | no | 0 | win |
| code_clone_2 | code-clone | 392.5 ns | 370 ns | 1.061x | no | 0 | win |
| code_clone_8 | code-clone | 1.442 us | 1.508 us | 0.956x | no | 0 | loss |
| large_mixed_500 | large-mixed | 637.5 ns | 656.5 ns | 0.971x | yes | 3 | loss |
| large_mixed_1000 | large-mixed | 1.304 us | 1.258 us | 1.037x | no | 0 | win |
| bpf_call_chain | bpf-local-call | 471.5 ns | 476.5 ns | 0.990x | yes | 3 | loss |
| memcmp_prefix_64 | byte-compare | 134 ns | 143 ns | 0.937x | yes | 3 | loss |
| packet_parse_vlans_tcpopts | parser | 23 ns | 16 ns | 1.438x | no | 0 | win |
| local_call_fanout | bpf-local-call | 126 ns | 133 ns | 0.947x | no | 0 | loss |
| packet_rss_hash | packet-hash | 18.5 ns | 17 ns | 1.088x | no | 0 | win |
| imm64_storm | immediate-stress | 242.5 ns | 188.5 ns | 1.286x | no | 0 | win |
| alu32_64_pingpong | mixed-width | 507 ns | 509.5 ns | 0.995x | no | 0 | loss |
| branch_fanout_32 | branch-fanout | 391 ns | 394.5 ns | 0.991x | no | 0 | loss |
| deep_guard_tree_8 | deep-guards | 99 ns | 107.5 ns | 0.921x | no | 0 | loss |
| mega_basic_block_2048 | mega-block | 963.5 ns | 1.003 us | 0.961x | no | 0 | loss |
| rotate64_hash | rotate-hash | 96 ns | 85.5 ns | 1.123x | no | 0 | win |
| packet_redundant_bounds | bounds-density | 137.5 ns | 144.5 ns | 0.952x | no | 0 | loss |
| const_fold_chain | const-fold | 291.5 ns | 321 ns | 0.908x | no | 0 | loss |
| struct_field_cluster | field-access | 87.5 ns | 86 ns | 1.017x | no | 0 | win |
| bitfield_extract | bitfield-extract | 309 ns | 240 ns | 1.288x | no | 0 | win |
| smallmul_strength_reduce | strength-reduce | 400 ns | 365 ns | 1.096x | no | 0 | win |
| cond_select_dense | select-diamond | 48 ns | 99.5 ns | 0.482x | yes | 104 | loss |
| rotate_dense | rotate-canonical | 206 ns | 176.5 ns | 1.167x | yes | 256 | win |
| addr_calc_stride | addr-calc | 215 ns | 153.5 ns | 1.401x | yes | 8 | win |
| extract_dense | bitfield-extract | 149 ns | 268 ns | 0.556x | yes | 512 | loss |
| endian_swap_dense | endian-fusion | 130 ns | 187 ns | 0.695x | yes | 256 | loss |
| branch_flip_dense | branch-flip | 203.5 ns | 193.5 ns | 1.052x | yes | 255 | win |
| tc_bitcount | popcount | 4.712 us | 4.614 us | 1.021x | no | 0 | win |
| tc_checksum | reduction | 17.837 us | 19.191 us | 0.929x | no | 0 | loss |
| cgroup_hash_chain | hash-chain | 294.5 ns | 302.5 ns | 0.974x | no | 0 | loss |
