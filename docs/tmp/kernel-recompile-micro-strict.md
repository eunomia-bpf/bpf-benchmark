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

- Overall geomean (stock / recompile, valid pairs only): `1.028x`
- Applied-only geomean (stock / recompile): `1.024x`
- Wins / losses / ties: `31 / 17 / 2`
- Valid / invalid pairs: `50 / 6`

## Per-Family Breakdown

| Family | Benchmarks | Valid | Applied | Geomean | Applied-only Geomean | Wins | Losses | Ties |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| baseline | 3 | 3 | 1 | 1.013x | 0.808x | 1 | 1 | 1 |
| bitfield-extract | 1 | 1 | 1 | 1.083x | 1.083x | 1 | 0 | 0 |
| bounds-density | 2 | 1 | 1 | 1.508x | 1.508x | 1 | 0 | 0 |
| bounds-style | 1 | 1 | 1 | 1.144x | 1.144x | 1 | 0 | 0 |
| bpf-local-call | 2 | 1 | 1 | 1.075x | 1.075x | 1 | 0 | 0 |
| branch-density | 1 | 0 | 0 | n/a | n/a | 0 | 0 | 0 |
| branch-fanout | 1 | 1 | 1 | 0.999x | 0.999x | 0 | 1 | 0 |
| branch-skew | 1 | 1 | 1 | 1.010x | 1.010x | 1 | 0 | 0 |
| byte-compare | 1 | 1 | 1 | 0.966x | 0.966x | 0 | 1 | 0 |
| causal-isolation | 2 | 2 | 1 | 0.982x | 0.877x | 1 | 1 | 0 |
| code-clone | 2 | 2 | 2 | 1.048x | 1.048x | 2 | 0 | 0 |
| const-fold | 1 | 1 | 1 | 1.100x | 1.100x | 1 | 0 | 0 |
| deep-guards | 1 | 1 | 1 | 1.298x | 1.298x | 1 | 0 | 0 |
| dep-chain | 2 | 2 | 2 | 1.017x | 1.017x | 1 | 1 | 0 |
| field-access | 1 | 1 | 0 | 0.924x | n/a | 0 | 1 | 0 |
| fixed-loop | 2 | 2 | 2 | 1.117x | 1.117x | 2 | 0 | 0 |
| hash-chain | 1 | 1 | 1 | 1.046x | 1.046x | 1 | 0 | 0 |
| immediate-stress | 1 | 1 | 1 | 1.080x | 1.080x | 1 | 0 | 0 |
| large-mixed | 2 | 2 | 2 | 0.937x | 0.937x | 1 | 1 | 0 |
| load-width | 2 | 2 | 2 | 1.065x | 1.065x | 1 | 1 | 0 |
| log2-fold | 1 | 1 | 1 | 1.016x | 1.016x | 1 | 0 | 0 |
| mega-block | 1 | 1 | 0 | 1.036x | n/a | 1 | 0 | 0 |
| mixed-alu-mem | 1 | 0 | 0 | n/a | n/a | 0 | 0 | 0 |
| mixed-width | 1 | 1 | 1 | 1.040x | 1.040x | 1 | 0 | 0 |
| multi-acc | 2 | 2 | 2 | 1.029x | 1.029x | 2 | 0 | 0 |
| nested-loop | 2 | 2 | 2 | 0.920x | 0.920x | 0 | 2 | 0 |
| packet-hash | 1 | 1 | 1 | 1.273x | 1.273x | 1 | 0 | 0 |
| parser | 2 | 2 | 2 | 0.912x | 0.912x | 0 | 1 | 1 |
| popcount | 2 | 2 | 2 | 0.989x | 0.989x | 0 | 2 | 0 |
| recurrence | 2 | 2 | 2 | 1.007x | 1.007x | 1 | 1 | 0 |
| reduction | 2 | 2 | 2 | 1.000x | 1.000x | 1 | 1 | 0 |
| rotate-hash | 1 | 1 | 1 | 1.600x | 1.600x | 1 | 0 | 0 |
| search | 1 | 0 | 0 | n/a | n/a | 0 | 0 | 0 |
| select-diamond | 2 | 2 | 2 | 0.795x | 0.795x | 1 | 1 | 0 |
| spill-pressure | 1 | 1 | 1 | 1.034x | 1.034x | 1 | 0 | 0 |
| strength-reduce | 1 | 1 | 1 | 0.880x | 0.880x | 0 | 1 | 0 |
| stride-load | 2 | 2 | 2 | 1.004x | 1.004x | 2 | 0 | 0 |
| switch-dispatch | 1 | 0 | 0 | n/a | n/a | 0 | 0 | 0 |

## Per-Benchmark Table

| Benchmark | Family | Stock median | Recompile median | Stock/Recompile | Applied | Sites | Status |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| simple | baseline | 11 ns | 11 ns | 1.000x | no | 0 | tie |
| simple_packet | baseline | 9 ns | 7 ns | 1.286x | no | 0 | win |
| memory_pair_sum | baseline | 10.5 ns | 13 ns | 0.808x | yes | 2 | loss |
| bitcount | popcount | 4.450 us | 4.456 us | 0.999x | yes | 2 | loss |
| log2_fold | log2-fold | 358.5 ns | 353 ns | 1.016x | yes | 3 | win |
| dep_chain_short | dep-chain | 180.5 ns | 171 ns | 1.056x | yes | 2 | win |
| dep_chain_long | dep-chain | 550.5 ns | 562 ns | 0.980x | yes | 2 | loss |
| binary_search | search | 642 ns | n/a | n/a | yes | 3 | ok / result-mismatch |
| branch_layout | branch-skew | 650.5 ns | 644 ns | 1.010x | yes | 2 | win |
| switch_dispatch | switch-dispatch | 354 ns | n/a | n/a | yes | 3 | ok / result-mismatch |
| branch_dense | branch-density | 543 ns | n/a | n/a | yes | 7 | ok / result-mismatch |
| cmov_select | select-diamond | 613 ns | 594.5 ns | 1.031x | yes | 11 | win |
| cmov_dense | select-diamond | 45 ns | 73.5 ns | 0.612x | yes | 32 | loss |
| checksum | reduction | 17.730 us | 17.741 us | 0.999x | yes | 2 | loss |
| load_word32 | load-width | 120 ns | 105 ns | 1.143x | yes | 2 | win |
| load_byte | load-width | 323.5 ns | 326 ns | 0.992x | yes | 2 | loss |
| load_byte_recompose | causal-isolation | 207 ns | 236 ns | 0.877x | yes | 1 | loss |
| load_native_u64 | causal-isolation | 99.5 ns | 90.5 ns | 1.099x | no | 0 | win |
| packet_parse | parser | 126 ns | 151.5 ns | 0.832x | yes | 5 | loss |
| bounds_ladder | bounds-density | 231 ns | n/a | n/a | no | 0 | ok / vm-crash |
| bounds_check_heavy | bounds-style | 309 ns | 270 ns | 1.144x | yes | 14 | win |
| stride_load_4 | stride-load | 269.5 ns | 269 ns | 1.002x | yes | 3 | win |
| stride_load_16 | stride-load | 273.5 ns | 272 ns | 1.006x | yes | 3 | win |
| mixed_alu_mem | mixed-alu-mem | 849.5 ns | n/a | n/a | no | 0 | ok / vm-crash |
| spill_pressure | spill-pressure | 380.5 ns | 368 ns | 1.034x | yes | 2 | win |
| multi_acc_4 | multi-acc | 303.5 ns | 303 ns | 1.002x | yes | 3 | win |
| multi_acc_8 | multi-acc | 565 ns | 535 ns | 1.056x | yes | 4 | win |
| fibonacci_iter | recurrence | 987 ns | 996.5 ns | 0.990x | yes | 4 | loss |
| fibonacci_iter_packet | recurrence | 932 ns | 911 ns | 1.023x | yes | 4 | win |
| fixed_loop_small | fixed-loop | 160.5 ns | 134 ns | 1.198x | yes | 4 | win |
| fixed_loop_large | fixed-loop | 1.788 us | 1.716 us | 1.042x | yes | 4 | win |
| nested_loop_2 | nested-loop | 603.5 ns | 708.5 ns | 0.852x | yes | 3 | loss |
| nested_loop_3 | nested-loop | 823.5 ns | 828 ns | 0.995x | yes | 3 | loss |
| code_clone_2 | code-clone | 396.5 ns | 389.5 ns | 1.018x | yes | 2 | win |
| code_clone_8 | code-clone | 1.497 us | 1.387 us | 1.079x | yes | 3 | win |
| large_mixed_500 | large-mixed | 617 ns | 704 ns | 0.876x | yes | 11 | loss |
| large_mixed_1000 | large-mixed | 1.185 us | 1.182 us | 1.002x | yes | 16 | win |
| bpf_call_chain | bpf-local-call | 462 ns | n/a | n/a | yes | 3 | ok / result-mismatch |
| memcmp_prefix_64 | byte-compare | 143 ns | 148 ns | 0.966x | yes | 4 | loss |
| packet_parse_vlans_tcpopts | parser | 26 ns | 26 ns | 1.000x | yes | 7 | tie |
| local_call_fanout | bpf-local-call | 151 ns | 140.5 ns | 1.075x | yes | 21 | win |
| packet_rss_hash | packet-hash | 28 ns | 22 ns | 1.273x | yes | 13 | win |
| imm64_storm | immediate-stress | 216 ns | 200 ns | 1.080x | yes | 68 | win |
| alu32_64_pingpong | mixed-width | 519.5 ns | 499.5 ns | 1.040x | yes | 4 | win |
| branch_fanout_32 | branch-fanout | 398 ns | 398.5 ns | 0.999x | yes | 9 | loss |
| deep_guard_tree_8 | deep-guards | 148 ns | 114 ns | 1.298x | yes | 2 | win |
| mega_basic_block_2048 | mega-block | 994 ns | 959.5 ns | 1.036x | no | 520 | win |
| rotate64_hash | rotate-hash | 104 ns | 65 ns | 1.600x | yes | 123 | win |
| packet_redundant_bounds | bounds-density | 181 ns | 120 ns | 1.508x | yes | 8 | win |
| const_fold_chain | const-fold | 337 ns | 306.5 ns | 1.100x | yes | 2 | win |
| struct_field_cluster | field-access | 97 ns | 105 ns | 0.924x | no | 0 | loss |
| bitfield_extract | bitfield-extract | 281.5 ns | 260 ns | 1.083x | yes | 11 | win |
| smallmul_strength_reduce | strength-reduce | 408.5 ns | 464 ns | 0.880x | yes | 2 | loss |
| tc_bitcount | popcount | 4.561 us | 4.659 us | 0.979x | yes | 2 | loss |
| tc_checksum | reduction | 17.733 us | 17.704 us | 1.002x | yes | 2 | win |
| cgroup_hash_chain | hash-chain | 328.5 ns | 314 ns | 1.046x | yes | 2 | win |
