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

- Overall geomean (stock / recompile, valid pairs only): `1.018x`
- Applied-only geomean (stock / recompile): `1.049x`
- Wins / losses / ties: `30 / 21 / 5`
- Valid / invalid pairs: `56 / 0`

## Per-Family Breakdown

| Family | Benchmarks | Valid | Applied | Geomean | Applied-only Geomean | Wins | Losses | Ties |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| baseline | 3 | 3 | 0 | 0.987x | n/a | 0 | 1 | 2 |
| bitfield-extract | 1 | 1 | 0 | 1.065x | n/a | 1 | 0 | 0 |
| bounds-density | 2 | 2 | 1 | 0.886x | 0.889x | 0 | 2 | 0 |
| bounds-style | 1 | 1 | 0 | 0.893x | n/a | 0 | 1 | 0 |
| bpf-local-call | 2 | 2 | 1 | 1.082x | 1.109x | 2 | 0 | 0 |
| branch-density | 1 | 1 | 0 | 1.017x | n/a | 1 | 0 | 0 |
| branch-fanout | 1 | 1 | 0 | 0.929x | n/a | 0 | 1 | 0 |
| branch-skew | 1 | 1 | 0 | 1.005x | n/a | 1 | 0 | 0 |
| byte-compare | 1 | 1 | 1 | 1.229x | 1.229x | 1 | 0 | 0 |
| causal-isolation | 2 | 2 | 0 | 1.052x | n/a | 1 | 1 | 0 |
| code-clone | 2 | 2 | 0 | 1.004x | n/a | 1 | 1 | 0 |
| const-fold | 1 | 1 | 0 | 1.220x | n/a | 1 | 0 | 0 |
| deep-guards | 1 | 1 | 0 | 1.013x | n/a | 1 | 0 | 0 |
| dep-chain | 2 | 2 | 0 | 1.004x | n/a | 1 | 1 | 0 |
| field-access | 1 | 1 | 0 | 1.244x | n/a | 1 | 0 | 0 |
| fixed-loop | 2 | 2 | 0 | 0.963x | n/a | 1 | 1 | 0 |
| hash-chain | 1 | 1 | 0 | 0.978x | n/a | 0 | 1 | 0 |
| immediate-stress | 1 | 1 | 0 | 1.040x | n/a | 1 | 0 | 0 |
| large-mixed | 2 | 2 | 1 | 0.967x | 0.947x | 0 | 2 | 0 |
| load-width | 2 | 2 | 0 | 1.078x | n/a | 2 | 0 | 0 |
| log2-fold | 1 | 1 | 1 | 1.042x | 1.042x | 1 | 0 | 0 |
| mega-block | 1 | 1 | 0 | 0.990x | n/a | 0 | 1 | 0 |
| mixed-alu-mem | 1 | 1 | 1 | 1.023x | 1.023x | 1 | 0 | 0 |
| mixed-width | 1 | 1 | 0 | 1.009x | n/a | 1 | 0 | 0 |
| multi-acc | 2 | 2 | 0 | 0.997x | n/a | 1 | 1 | 0 |
| nested-loop | 2 | 2 | 0 | 0.986x | n/a | 1 | 1 | 0 |
| packet-hash | 1 | 1 | 0 | 1.000x | n/a | 0 | 0 | 1 |
| parser | 2 | 2 | 0 | 1.007x | n/a | 1 | 0 | 1 |
| popcount | 2 | 2 | 0 | 1.017x | n/a | 1 | 1 | 0 |
| recurrence | 2 | 2 | 0 | 1.014x | n/a | 1 | 1 | 0 |
| reduction | 2 | 2 | 0 | 1.001x | n/a | 2 | 0 | 0 |
| rotate-hash | 1 | 1 | 0 | 1.357x | n/a | 1 | 0 | 0 |
| search | 1 | 1 | 0 | 0.986x | n/a | 0 | 1 | 0 |
| select-diamond | 2 | 2 | 2 | 1.095x | 1.095x | 1 | 1 | 0 |
| spill-pressure | 1 | 1 | 0 | 0.952x | n/a | 0 | 1 | 0 |
| strength-reduce | 1 | 1 | 0 | 0.786x | n/a | 0 | 1 | 0 |
| stride-load | 2 | 2 | 0 | 1.034x | n/a | 1 | 0 | 1 |
| switch-dispatch | 1 | 1 | 0 | 1.075x | n/a | 1 | 0 | 0 |

## Per-Benchmark Table

| Benchmark | Family | Stock median | Recompile median | Stock/Recompile | Applied | Sites | Status |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| simple | baseline | 11 ns | 11 ns | 1.000x | no | 0 | tie |
| simple_packet | baseline | 11 ns | 11 ns | 1.000x | no | 0 | tie |
| memory_pair_sum | baseline | 13 ns | 13.5 ns | 0.963x | no | 0 | loss |
| bitcount | popcount | 4.511 us | 4.548 us | 0.992x | no | 0 | loss |
| log2_fold | log2-fold | 358.5 ns | 344 ns | 1.042x | yes | 3 | win |
| dep_chain_short | dep-chain | 207.5 ns | 201.5 ns | 1.030x | no | 0 | win |
| dep_chain_long | dep-chain | 557.5 ns | 569.5 ns | 0.979x | no | 0 | loss |
| binary_search | search | 625 ns | 634 ns | 0.986x | no | 0 | loss |
| branch_layout | branch-skew | 639.5 ns | 636.5 ns | 1.005x | no | 0 | win |
| switch_dispatch | switch-dispatch | 350.5 ns | 326 ns | 1.075x | no | 0 | win |
| branch_dense | branch-density | 558 ns | 548.5 ns | 1.017x | no | 0 | win |
| cmov_select | select-diamond | 631 ns | 647.5 ns | 0.975x | yes | 1 | loss |
| cmov_dense | select-diamond | 75 ns | 61 ns | 1.230x | yes | 26 | win |
| checksum | reduction | 17.765 us | 17.746 us | 1.001x | no | 0 | win |
| load_word32 | load-width | 133.5 ns | 120.5 ns | 1.108x | no | 0 | win |
| load_byte | load-width | 313 ns | 298.5 ns | 1.049x | no | 0 | win |
| load_byte_recompose | causal-isolation | 242 ns | 243 ns | 0.996x | no | 0 | loss |
| load_native_u64 | causal-isolation | 110 ns | 99 ns | 1.111x | no | 0 | win |
| packet_parse | parser | 114.5 ns | 113 ns | 1.013x | no | 0 | win |
| bounds_ladder | bounds-density | 208 ns | 234 ns | 0.889x | yes | 2 | loss |
| bounds_check_heavy | bounds-style | 274 ns | 307 ns | 0.893x | no | 0 | loss |
| stride_load_4 | stride-load | 293 ns | 293 ns | 1.000x | no | 0 | tie |
| stride_load_16 | stride-load | 278 ns | 260 ns | 1.069x | no | 0 | win |
| mixed_alu_mem | mixed-alu-mem | 896.5 ns | 876.5 ns | 1.023x | yes | 2 | win |
| spill_pressure | spill-pressure | 396.5 ns | 416.5 ns | 0.952x | no | 0 | loss |
| multi_acc_4 | multi-acc | 312.5 ns | 322 ns | 0.970x | no | 0 | loss |
| multi_acc_8 | multi-acc | 594 ns | 580.5 ns | 1.023x | no | 0 | win |
| fibonacci_iter | recurrence | 989.5 ns | 991 ns | 0.998x | no | 0 | loss |
| fibonacci_iter_packet | recurrence | 956 ns | 928.5 ns | 1.030x | no | 0 | win |
| fixed_loop_small | fixed-loop | 116 ns | 126.5 ns | 0.917x | no | 0 | loss |
| fixed_loop_large | fixed-loop | 1.526 us | 1.510 us | 1.011x | no | 0 | win |
| nested_loop_2 | nested-loop | 607 ns | 588.5 ns | 1.031x | no | 0 | win |
| nested_loop_3 | nested-loop | 806.5 ns | 856 ns | 0.942x | no | 0 | loss |
| code_clone_2 | code-clone | 405 ns | 412.5 ns | 0.982x | no | 0 | loss |
| code_clone_8 | code-clone | 1.526 us | 1.487 us | 1.026x | no | 0 | win |
| large_mixed_500 | large-mixed | 613 ns | 647 ns | 0.947x | yes | 3 | loss |
| large_mixed_1000 | large-mixed | 1.178 us | 1.194 us | 0.987x | no | 0 | loss |
| bpf_call_chain | bpf-local-call | 522 ns | 470.5 ns | 1.109x | yes | 2 | win |
| memcmp_prefix_64 | byte-compare | 131.5 ns | 107 ns | 1.229x | yes | 3 | win |
| packet_parse_vlans_tcpopts | parser | 27 ns | 27 ns | 1.000x | no | 0 | tie |
| local_call_fanout | bpf-local-call | 153 ns | 145 ns | 1.055x | no | 0 | win |
| packet_rss_hash | packet-hash | 21 ns | 21 ns | 1.000x | no | 0 | tie |
| imm64_storm | immediate-stress | 233 ns | 224 ns | 1.040x | no | 0 | win |
| alu32_64_pingpong | mixed-width | 533.5 ns | 529 ns | 1.009x | no | 0 | win |
| branch_fanout_32 | branch-fanout | 395 ns | 425 ns | 0.929x | no | 0 | loss |
| deep_guard_tree_8 | deep-guards | 120 ns | 118.5 ns | 1.013x | no | 0 | win |
| mega_basic_block_2048 | mega-block | 984.5 ns | 994 ns | 0.990x | no | 0 | loss |
| rotate64_hash | rotate-hash | 95 ns | 70 ns | 1.357x | no | 0 | win |
| packet_redundant_bounds | bounds-density | 159 ns | 180 ns | 0.883x | no | 0 | loss |
| const_fold_chain | const-fold | 396.5 ns | 325 ns | 1.220x | no | 0 | win |
| struct_field_cluster | field-access | 97 ns | 78 ns | 1.244x | no | 0 | win |
| bitfield_extract | bitfield-extract | 297 ns | 279 ns | 1.065x | no | 0 | win |
| smallmul_strength_reduce | strength-reduce | 353 ns | 449 ns | 0.786x | no | 0 | loss |
| tc_bitcount | popcount | 4.721 us | 4.529 us | 1.042x | no | 0 | win |
| tc_checksum | reduction | 17.761 us | 17.753 us | 1.000x | no | 0 | win |
| cgroup_hash_chain | hash-chain | 309 ns | 316 ns | 0.978x | no | 0 | loss |
