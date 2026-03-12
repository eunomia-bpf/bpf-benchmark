# Kernel Recompile Micro Strict

## Methodology

- Kernel: `7.0.0-rc2-ge52504a75c05-dirty`
- Benchmarks: `56` from `config/micro_pure_jit.yaml`
- Runtimes: `kernel` vs `kernel-recompile`
- Warmups / iterations / repeat: `2 / 10 / 500`
- CPU pinning: `taskset -c 0`
- CPU governor: `unknown`
- Turbo state: `unknown`

## Headline Numbers

- Overall geomean (stock / recompile, valid pairs only): `1.052x`
- Applied-only geomean (stock / recompile): `1.075x`
- Wins / losses / ties: `34 / 18 / 2`
- Valid / invalid pairs: `54 / 2`

## Per-Family Breakdown

| Family | Benchmarks | Valid | Applied | Geomean | Applied-only Geomean | Wins | Losses | Ties |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| baseline | 3 | 3 | 0 | 0.994x | n/a | 1 | 2 | 0 |
| bitfield-extract | 1 | 1 | 1 | 0.985x | 0.985x | 0 | 1 | 0 |
| bounds-density | 2 | 1 | 1 | 1.346x | 1.346x | 1 | 0 | 0 |
| bounds-style | 1 | 1 | 1 | 1.009x | 1.009x | 1 | 0 | 0 |
| bpf-local-call | 2 | 2 | 2 | 1.027x | 1.027x | 2 | 0 | 0 |
| branch-density | 1 | 1 | 0 | 0.985x | n/a | 0 | 1 | 0 |
| branch-fanout | 1 | 1 | 0 | 1.040x | n/a | 1 | 0 | 0 |
| branch-skew | 1 | 1 | 1 | 1.031x | 1.031x | 1 | 0 | 0 |
| byte-compare | 1 | 1 | 1 | 0.878x | 0.878x | 0 | 1 | 0 |
| causal-isolation | 2 | 2 | 0 | 1.028x | n/a | 2 | 0 | 0 |
| code-clone | 2 | 2 | 2 | 1.118x | 1.118x | 2 | 0 | 0 |
| const-fold | 1 | 1 | 1 | 1.094x | 1.094x | 1 | 0 | 0 |
| deep-guards | 1 | 1 | 1 | 0.943x | 0.943x | 0 | 1 | 0 |
| dep-chain | 2 | 2 | 1 | 1.002x | 1.003x | 1 | 0 | 1 |
| field-access | 1 | 1 | 0 | 1.207x | n/a | 1 | 0 | 0 |
| fixed-loop | 2 | 2 | 2 | 1.174x | 1.174x | 1 | 1 | 0 |
| hash-chain | 1 | 1 | 1 | 0.973x | 0.973x | 0 | 1 | 0 |
| immediate-stress | 1 | 1 | 1 | 1.201x | 1.201x | 1 | 0 | 0 |
| large-mixed | 2 | 2 | 2 | 1.097x | 1.097x | 2 | 0 | 0 |
| load-width | 2 | 2 | 1 | 1.082x | 1.137x | 2 | 0 | 0 |
| log2-fold | 1 | 1 | 1 | 0.981x | 0.981x | 0 | 1 | 0 |
| mega-block | 1 | 1 | 0 | 0.982x | n/a | 0 | 1 | 0 |
| mixed-alu-mem | 1 | 0 | 0 | n/a | n/a | 0 | 0 | 0 |
| mixed-width | 1 | 1 | 1 | 1.096x | 1.096x | 1 | 0 | 0 |
| multi-acc | 2 | 2 | 2 | 0.939x | 0.939x | 1 | 1 | 0 |
| nested-loop | 2 | 2 | 0 | 1.070x | n/a | 1 | 1 | 0 |
| packet-hash | 1 | 1 | 1 | 1.273x | 1.273x | 1 | 0 | 0 |
| parser | 2 | 2 | 1 | 0.962x | 1.000x | 0 | 1 | 1 |
| popcount | 2 | 2 | 0 | 1.002x | n/a | 1 | 1 | 0 |
| recurrence | 2 | 2 | 1 | 1.008x | 1.032x | 1 | 1 | 0 |
| reduction | 2 | 2 | 1 | 1.001x | 1.001x | 2 | 0 | 0 |
| rotate-hash | 1 | 1 | 1 | 1.534x | 1.534x | 1 | 0 | 0 |
| search | 1 | 1 | 0 | 0.949x | n/a | 0 | 1 | 0 |
| select-diamond | 2 | 2 | 2 | 1.206x | 1.206x | 2 | 0 | 0 |
| spill-pressure | 1 | 1 | 1 | 0.956x | 0.956x | 0 | 1 | 0 |
| strength-reduce | 1 | 1 | 0 | 0.917x | n/a | 0 | 1 | 0 |
| stride-load | 2 | 2 | 2 | 1.068x | 1.068x | 2 | 0 | 0 |
| switch-dispatch | 1 | 1 | 0 | 1.198x | n/a | 1 | 0 | 0 |

## Per-Benchmark Table

| Benchmark | Family | Stock median | Recompile median | Stock/Recompile | Applied | Sites | Status |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| simple | baseline | 7 ns | 7.5 ns | 0.933x | no | 0 | loss |
| simple_packet | baseline | 9 ns | 7 ns | 1.286x | no | 0 | win |
| memory_pair_sum | baseline | 9 ns | 11 ns | 0.818x | no | 0 | loss |
| bitcount | popcount | 4.585 us | 4.637 us | 0.989x | no | 0 | loss |
| log2_fold | log2-fold | 368 ns | 375 ns | 0.981x | yes | 3 | loss |
| dep_chain_short | dep-chain | 148 ns | 147.5 ns | 1.003x | yes | 2 | win |
| dep_chain_long | dep-chain | 578 ns | 578 ns | 1.000x | no | 0 | tie |
| binary_search | search | 665 ns | 701 ns | 0.949x | no | 0 | loss |
| branch_layout | branch-skew | 658.5 ns | 639 ns | 1.031x | yes | 2 | win |
| switch_dispatch | switch-dispatch | 414 ns | 345.5 ns | 1.198x | no | 0 | win |
| branch_dense | branch-density | 619.5 ns | 629 ns | 0.985x | no | 0 | loss |
| cmov_select | select-diamond | 655 ns | 634 ns | 1.033x | yes | 11 | win |
| cmov_dense | select-diamond | 57 ns | 40.5 ns | 1.407x | yes | 26 | win |
| checksum | reduction | 17.795 us | 17.779 us | 1.001x | no | 0 | win |
| load_word32 | load-width | 120.5 ns | 106 ns | 1.137x | yes | 2 | win |
| load_byte | load-width | 335.5 ns | 326 ns | 1.029x | no | 0 | win |
| load_byte_recompose | causal-isolation | 209.5 ns | 206 ns | 1.017x | no | 0 | win |
| load_native_u64 | causal-isolation | 94 ns | 90.5 ns | 1.039x | no | 0 | win |
| packet_parse | parser | 106.5 ns | 115 ns | 0.926x | no | 0 | loss |
| bounds_ladder | bounds-density | 205 ns | n/a | n/a | no | 0 | ok / vm-crash |
| bounds_check_heavy | bounds-style | 282.5 ns | 280 ns | 1.009x | yes | 14 | win |
| stride_load_4 | stride-load | 296 ns | 275.5 ns | 1.074x | yes | 3 | win |
| stride_load_16 | stride-load | 293 ns | 276 ns | 1.062x | yes | 3 | win |
| mixed_alu_mem | mixed-alu-mem | 901 ns | n/a | n/a | no | 0 | ok / vm-crash |
| spill_pressure | spill-pressure | 379 ns | 396.5 ns | 0.956x | yes | 2 | loss |
| multi_acc_4 | multi-acc | 315.5 ns | 367 ns | 0.860x | yes | 3 | loss |
| multi_acc_8 | multi-acc | 525.5 ns | 512 ns | 1.026x | yes | 4 | win |
| fibonacci_iter | recurrence | 962 ns | 978 ns | 0.984x | no | 0 | loss |
| fibonacci_iter_packet | recurrence | 986 ns | 955 ns | 1.032x | yes | 4 | win |
| fixed_loop_small | fixed-loop | 116 ns | 124.5 ns | 0.932x | yes | 4 | loss |
| fixed_loop_large | fixed-loop | 1.784 us | 1.206 us | 1.479x | yes | 4 | win |
| nested_loop_2 | nested-loop | 710 ns | 591 ns | 1.201x | no | 0 | win |
| nested_loop_3 | nested-loop | 890 ns | 934.5 ns | 0.952x | no | 0 | loss |
| code_clone_2 | code-clone | 429 ns | 382 ns | 1.123x | yes | 2 | win |
| code_clone_8 | code-clone | 1.621 us | 1.458 us | 1.112x | yes | 3 | win |
| large_mixed_500 | large-mixed | 637.5 ns | 624.5 ns | 1.021x | yes | 3 | win |
| large_mixed_1000 | large-mixed | 1.423 us | 1.206 us | 1.180x | yes | 16 | win |
| bpf_call_chain | bpf-local-call | 496.5 ns | 494.5 ns | 1.004x | yes | 2 | win |
| memcmp_prefix_64 | byte-compare | 133.5 ns | 152 ns | 0.878x | yes | 3 | loss |
| packet_parse_vlans_tcpopts | parser | 26 ns | 26 ns | 1.000x | yes | 7 | tie |
| local_call_fanout | bpf-local-call | 155.5 ns | 148 ns | 1.051x | yes | 21 | win |
| packet_rss_hash | packet-hash | 28 ns | 22 ns | 1.273x | yes | 13 | win |
| imm64_storm | immediate-stress | 260 ns | 216.5 ns | 1.201x | yes | 68 | win |
| alu32_64_pingpong | mixed-width | 531 ns | 484.5 ns | 1.096x | yes | 4 | win |
| branch_fanout_32 | branch-fanout | 440.5 ns | 423.5 ns | 1.040x | no | 0 | win |
| deep_guard_tree_8 | deep-guards | 107 ns | 113.5 ns | 0.943x | yes | 2 | loss |
| mega_basic_block_2048 | mega-block | 960 ns | 977.5 ns | 0.982x | no | 520 | loss |
| rotate64_hash | rotate-hash | 102 ns | 66.5 ns | 1.534x | yes | 123 | win |
| packet_redundant_bounds | bounds-density | 194.5 ns | 144.5 ns | 1.346x | yes | 8 | win |
| const_fold_chain | const-fold | 338.5 ns | 309.5 ns | 1.094x | yes | 2 | win |
| struct_field_cluster | field-access | 108 ns | 89.5 ns | 1.207x | no | 0 | win |
| bitfield_extract | bitfield-extract | 324 ns | 329 ns | 0.985x | yes | 11 | loss |
| smallmul_strength_reduce | strength-reduce | 358 ns | 390.5 ns | 0.917x | no | 0 | loss |
| tc_bitcount | popcount | 4.744 us | 4.670 us | 1.016x | no | 0 | win |
| tc_checksum | reduction | 17.750 us | 17.733 us | 1.001x | yes | 2 | win |
| cgroup_hash_chain | hash-chain | 304 ns | 312.5 ns | 0.973x | yes | 2 | loss |
