# AWS ARM64 Benchmark Report (2026-03-28)

## Run Status

- Final benchmark run succeeded via `runner/scripts/aws_arm64.sh full` (equivalent to the `make aws-arm64` flow without forcing another `cross-arm64` rebuild).
- AWS instance: `i-006784a366edd1865` (`t4g.micro`, region `us-east-1`, profile `codex-ec2`).
- Kernel under test: `7.0.0-rc2-gc0938be86146-dirty`.
- Local preflight status before final run: `.cache/aws-arm64/state/instance.env` was `clean`; cross-build artifacts and cached ARM64 kernel artifacts were present and reused.
- Post-run cleanup status: `.cache/aws-arm64/state/instance.env` returned `clean`; `describe-instances` found no remaining `Name=bpf-benchmark-arm64` instances in `us-east-1`.

## Artifacts

- Command log: `/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/logs/22_aws_arm64_full_retry3.log`
- Setup verification log: `/home/yunwei37/workspace/bpf-benchmark/.cache/aws-arm64/results/setup_verify_7.0.0-rc2-gc0938be86146-dirty_20260329_065618.log`
- Result JSON: `/home/yunwei37/workspace/bpf-benchmark/.cache/aws-arm64/results/benchmark_20260329_065727/results/arm64_t4g_micro.json`
- Result archive: `/home/yunwei37/workspace/bpf-benchmark/.cache/aws-arm64/results/benchmark_20260329_065727.tar.gz`
- Result JSON size: `11272768` bytes

## Configuration

- Benchmark parameters: `iterations=1`, `warmups=0`, `repeat=10`, `cpu=0`
- Kernel cmdline: `BOOT_IMAGE=(hd0,gpt1)/boot/vmlinuz-7.0.0-rc2-gc0938be86146-dirty root=UUID=6856c9a2-033a-4d4b-8e40-3d26b1d0f7dd ro console=tty0 console=ttyS0,115200n8 nvme_core.io_timeout=4294967295 rd.emergency=poweroff rd.shell=0 selinux=1 security=selinux quiet numa_cma=1:64M`
- Host notes: `cpu_governor=unknown`, `perf_event_paranoid=2`, `turbo_state=unknown`

## Summary

- `llvmbpf_vs_kernel`: benchmarks `62`; `llvmbpf` faster `55`; kernel faster `7`; median ratio (`llvmbpf/kernel`) `0.615585`; geometric mean ratio `0.615781`
- `daemon_stock_vs_rejit`: benchmarks `62`; benchmarks with sites `49`; benchmarks rejited `49`; total candidate sites `123`; total applied sites `123`; median absolute exec delta `28.0` ns; max absolute exec delta `2466.0` ns
- `katran_smoke`: `selected_load_mode=plain_xdp`; `rejit_applied=True`; `total_sites=16`; `applied_sites=16`; `loadall_plain_xdp_rc=0`; `loadall_kernel_btf_rc=255`

## Largest llvmbpf Wins

| benchmark | llvmbpf_exec_ns | kernel_exec_ns | ratio |
| --- | --- | --- | --- |
| multi_acc_8 | 509 | 1954 | 0.260491 |
| cmov_select | 486 | 1828 | 0.265864 |
| load_byte_recompose | 203 | 646 | 0.314241 |
| bpf_call_chain | 596 | 1645 | 0.362310 |
| binary_search | 791 | 2157 | 0.366713 |

## Largest Kernel Wins

| benchmark | llvmbpf_exec_ns | kernel_exec_ns | ratio |
| --- | --- | --- | --- |
| bounds_ladder | 1081 | 492 | 2.197154 |
| packet_parse | 540 | 365 | 1.479452 |
| simple_packet | 62 | 49 | 1.265306 |
| cond_select_dense | 338 | 306 | 1.104575 |
| simple | 62 | 57 | 1.087719 |

## Largest Stock-vs-REJIT Deltas

| benchmark | stock_exec_ns | rejit_exec_ns | rejit_minus_stock_ns |
| --- | --- | --- | --- |
| tc_checksum | 45167 | 42701 | -2466 |
| tc_bitcount | 15923 | 18039 | 2116 |
| bitcount | 15843 | 15531 | -312 |
| memcmp_prefix_64 | 402 | 659 | 257 |
| switch_dispatch | 1480 | 1283 | -197 |
| const_fold_chain | 1200 | 1036 | -164 |
| stride_load_4 | 794 | 905 | 111 |
| alu32_64_pingpong | 985 | 910 | -75 |
| mega_basic_block_2048 | 3844 | 3769 | -75 |
| packet_parse | 420 | 369 | -51 |

## Full llvmbpf-vs-kernel Data

Columns: benchmark name, category, median compile time for `llvmbpf`, median exec time for `llvmbpf`, median compile time for kernel JIT, median exec time for kernel JIT, `llvmbpf/kernel` exec ratio, whether `llvmbpf` was faster.

| benchmark | category | llvmbpf_compile_ns | llvmbpf_exec_ns | kernel_compile_ns | kernel_exec_ns | ratio | llvmbpf_faster |
| --- | --- | --- | --- | --- | --- | --- | --- |
| simple | baseline | 7463078 | 62 | 479212 | 57 | 1.087719 | no |
| simple_packet | baseline | 6219550 | 62 | 315288 | 49 | 1.265306 | no |
| memory_pair_sum | baseline | 9972590 | 61 | 555354 | 64 | 0.953125 | yes |
| bitcount | alu-mix | 17710048 | 7351 | 200510403 | 15287 | 0.480866 | yes |
| log2_fold | alu-mix | 18131572 | 711 | 13861782 | 949 | 0.749210 | yes |
| dep_chain_short | dependency-ilp | 14721240 | 199 | 1013505 | 413 | 0.481840 | yes |
| dep_chain_long | dependency-ilp | 14252013 | 581 | 2819476 | 1536 | 0.378255 | yes |
| binary_search | control-flow | 20793104 | 791 | 33607397 | 2157 | 0.366713 | yes |
| branch_layout | control-flow | 14021054 | 1102 | 18278406 | 1674 | 0.658303 | yes |
| switch_dispatch | control-flow | 36588458 | 996 | 70430202 | 1419 | 0.701903 | yes |
| branch_dense | control-flow | 22015914 | 1361 | 21490811 | 2358 | 0.577184 | yes |
| cmov_select | control-flow | 61883739 | 486 | 9470815 | 1828 | 0.265864 | yes |
| cmov_dense | control-flow | 39349260 | 152 | 842524 | 182 | 0.835165 | yes |
| checksum | memory-local | 15155662 | 27684 | 95829945 | 42356 | 0.653603 | yes |
| load_word32 | memory-local | 13241824 | 244 | 1188613 | 280 | 0.871429 | yes |
| load_byte | memory-local | 13344441 | 476 | 1569926 | 469 | 1.014925 | no |
| load_byte_recompose | memory-local | 13240748 | 203 | 1451406 | 646 | 0.314241 | yes |
| load_native_u64 | memory-local | 10667928 | 190 | 848457 | 262 | 0.725191 | yes |
| packet_parse | memory-local | 19994025 | 540 | 3170109 | 365 | 1.479452 | no |
| bounds_ladder | memory-local | 25431653 | 1081 | 3025581 | 492 | 2.197154 | no |
| bounds_check_heavy | memory-local | 68141548 | 670 | 195339038 | 771 | 0.869001 | yes |
| stride_load_4 | memory-local | 14950747 | 306 | 1843738 | 733 | 0.417462 | yes |
| stride_load_16 | memory-local | 14421157 | 295 | 1885895 | 772 | 0.382124 | yes |
| mixed_alu_mem | alu-mix | 26252672 | 1412 | 18579787 | 2675 | 0.527850 | yes |
| spill_pressure | dependency-ilp | 20047069 | 513 | 1882835 | 998 | 0.514028 | yes |
| multi_acc_4 | dependency-ilp | 17712887 | 386 | 1990801 | 1005 | 0.384080 | yes |
| multi_acc_8 | dependency-ilp | 20125943 | 509 | 3401035 | 1954 | 0.260491 | yes |
| fibonacci_iter | loop-shape | 14490012 | 1394 | 4595613 | 2562 | 0.544106 | yes |
| fibonacci_iter_packet | loop-shape | 17483429 | 1396 | 4586883 | 2561 | 0.545100 | yes |
| fixed_loop_small | loop-shape | 14127931 | 164 | 767163 | 318 | 0.515723 | yes |
| fixed_loop_large | loop-shape | 14547462 | 2370 | 5357614 | 3702 | 0.640194 | yes |
| nested_loop_2 | loop-shape | 23280331 | 848 | 3904617 | 2040 | 0.415686 | yes |
| nested_loop_3 | loop-shape | 23792290 | 1176 | 8308753 | 2358 | 0.498728 | yes |
| code_clone_2 | call-size | 15341864 | 438 | 2070848 | 1018 | 0.430255 | yes |
| code_clone_8 | call-size | 22330005 | 1691 | 4087150 | 2683 | 0.630265 | yes |
| large_mixed_500 | program-scale | 56840140 | 1164 | 17354563 | 2147 | 0.542152 | yes |
| large_mixed_1000 | program-scale | 98612187 | 2590 | 32276020 | 4140 | 0.625604 | yes |
| bpf_call_chain | call-overhead | 24755983 | 596 | 3776285 | 1645 | 0.362310 | yes |
| memcmp_prefix_64 | memory-local | 21605056 | 266 | 1597592 | 367 | 0.724796 | yes |
| packet_parse_vlans_tcpopts | memory-local | 24785594 | 98 | 933844 | 100 | 0.980000 | yes |
| local_call_fanout | call-overhead | 57773008 | 209 | 3620006 | 457 | 0.457330 | yes |
| packet_rss_hash | alu-mix | 27711585 | 97 | 668187 | 117 | 0.829060 | yes |
| imm64_storm | program-scale | 75152022 | 416 | 1165508 | 556 | 0.748201 | yes |
| alu32_64_pingpong | alu-mix | 21307294 | 638 | 1753393 | 877 | 0.727480 | yes |
| branch_fanout_32 | control-flow | 37844646 | 1082 | 81948308 | 1326 | 0.815988 | yes |
| deep_guard_tree_8 | control-flow | 19296030 | 231 | 5707813 | 329 | 0.702128 | yes |
| mega_basic_block_2048 | program-scale | 748819681 | 2002 | 6715747 | 3306 | 0.605566 | yes |
| rotate64_hash | alu-mix | 60041937 | 123 | 1152766 | 247 | 0.497976 | yes |
| packet_redundant_bounds | memory-local | 20257081 | 231 | 2704083 | 434 | 0.532258 | yes |
| const_fold_chain | program-scale | 18016360 | 564 | 2246087 | 1165 | 0.484120 | yes |
| struct_field_cluster | memory-local | 15017904 | 208 | 1882809 | 279 | 0.745520 | yes |
| bitfield_extract | memory-local | 39192736 | 535 | 1875745 | 894 | 0.598434 | yes |
| smallmul_strength_reduce | alu-mix | 18579516 | 560 | 2547223 | 1235 | 0.453441 | yes |
| cond_select_dense | control-flow | 137621004 | 338 | 1516691 | 306 | 1.104575 | no |
| rotate_dense | alu-mix | 146516724 | 528 | 1523543 | 656 | 0.804878 | yes |
| addr_calc_stride | memory-local | 21502684 | 268 | 1416700 | 574 | 0.466899 | yes |
| extract_dense | memory-local | 150899109 | 380 | 1651152 | 497 | 0.764588 | yes |
| endian_swap_dense | memory-local | 118151122 | 224 | 789561 | 292 | 0.767123 | yes |
| branch_flip_dense | control-flow | 453587701 | 853 | 3377889 | 826 | 1.032688 | no |
| tc_bitcount | alu-mix | 16051017 | 7324 | 133567207 | 15450 | 0.474045 | yes |
| tc_checksum | memory-local | 13614225 | 26156 | 78024812 | 39517 | 0.661892 | yes |
| cgroup_hash_chain | alu-mix | 16204490 | 416 | 2151468 | 1004 | 0.414343 | yes |

## Full daemon stock-vs-rejit Data

Columns: benchmark name, category, total candidate sites, applied sites, whether REJIT was applied, apply reason, stock exec median, REJIT exec median, `rejit-stock` exec delta in ns.

| benchmark | category | total_sites | applied_sites | rejit_applied | apply_reason | stock_exec_ns | rejit_exec_ns | delta_ns |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| simple | baseline | 0 | 0 | no | no_sites | 78 | n/a | n/a |
| simple_packet | baseline | 0 | 0 | no | no_sites | 76 | n/a | n/a |
| memory_pair_sum | baseline | 2 | 2 | yes | - | 98 | 103 | 5 |
| bitcount | alu-mix | 2 | 2 | yes | - | 15843 | 15531 | -312 |
| log2_fold | alu-mix | 3 | 3 | yes | - | 998 | 953 | -45 |
| dep_chain_short | dependency-ilp | 2 | 2 | yes | - | 444 | 455 | 11 |
| dep_chain_long | dependency-ilp | 2 | 2 | yes | - | 1576 | 1546 | -30 |
| binary_search | control-flow | 2 | 2 | yes | - | 2168 | 2180 | 12 |
| branch_layout | control-flow | 2 | 2 | yes | - | 1653 | 1648 | -5 |
| switch_dispatch | control-flow | 2 | 2 | yes | - | 1480 | 1283 | -197 |
| branch_dense | control-flow | 2 | 2 | yes | - | 2402 | 2414 | 12 |
| cmov_select | control-flow | 6 | 6 | yes | - | 1853 | 1819 | -34 |
| cmov_dense | control-flow | 0 | 0 | no | no_sites | 233 | n/a | n/a |
| checksum | memory-local | 2 | 2 | yes | - | 39539 | 39543 | 4 |
| load_word32 | memory-local | 2 | 2 | yes | - | 305 | 344 | 39 |
| load_byte | memory-local | 2 | 2 | yes | - | 497 | 486 | -11 |
| load_byte_recompose | memory-local | 1 | 1 | yes | - | 663 | 630 | -33 |
| load_native_u64 | memory-local | 0 | 0 | no | no_sites | 320 | n/a | n/a |
| packet_parse | memory-local | 2 | 2 | yes | - | 420 | 369 | -51 |
| bounds_ladder | memory-local | 2 | 2 | yes | - | 539 | 567 | 28 |
| bounds_check_heavy | memory-local | 2 | 2 | yes | - | 812 | 843 | 31 |
| stride_load_4 | memory-local | 2 | 2 | yes | - | 794 | 905 | 111 |
| stride_load_16 | memory-local | 2 | 2 | yes | - | 785 | 791 | 6 |
| mixed_alu_mem | alu-mix | 1 | 1 | yes | - | 2682 | 2692 | 10 |
| spill_pressure | dependency-ilp | 2 | 2 | yes | - | 982 | 1016 | 34 |
| multi_acc_4 | dependency-ilp | 2 | 2 | yes | - | 1042 | 1069 | 27 |
| multi_acc_8 | dependency-ilp | 2 | 2 | yes | - | 1975 | 2016 | 41 |
| fibonacci_iter | loop-shape | 3 | 3 | yes | - | 2610 | 2584 | -26 |
| fibonacci_iter_packet | loop-shape | 3 | 3 | yes | - | 2615 | 2621 | 6 |
| fixed_loop_small | loop-shape | 2 | 2 | yes | - | 347 | 315 | -32 |
| fixed_loop_large | loop-shape | 2 | 2 | yes | - | 3748 | 3742 | -6 |
| nested_loop_2 | loop-shape | 2 | 2 | yes | - | 2070 | 2074 | 4 |
| nested_loop_3 | loop-shape | 2 | 2 | yes | - | 2408 | 2374 | -34 |
| code_clone_2 | call-size | 1 | 1 | yes | - | 1042 | 1014 | -28 |
| code_clone_8 | call-size | 1 | 1 | yes | - | 2718 | 2702 | -16 |
| large_mixed_500 | program-scale | 1 | 1 | yes | - | 2177 | 2193 | 16 |
| large_mixed_1000 | program-scale | 1 | 1 | yes | - | 4271 | 4262 | -9 |
| bpf_call_chain | call-overhead | 3 | 3 | yes | - | 1680 | 1659 | -21 |
| memcmp_prefix_64 | memory-local | 1 | 1 | yes | - | 402 | 659 | 257 |
| packet_parse_vlans_tcpopts | memory-local | 0 | 0 | no | no_sites | 117 | n/a | n/a |
| local_call_fanout | call-overhead | 11 | 11 | yes | - | 505 | 480 | -25 |
| packet_rss_hash | alu-mix | 0 | 0 | no | no_sites | 129 | n/a | n/a |
| imm64_storm | program-scale | 4 | 4 | yes | - | 694 | 667 | -27 |
| alu32_64_pingpong | alu-mix | 3 | 3 | yes | - | 985 | 910 | -75 |
| branch_fanout_32 | control-flow | 1 | 1 | yes | - | 1368 | 1406 | 38 |
| deep_guard_tree_8 | control-flow | 2 | 2 | yes | - | 352 | 335 | -17 |
| mega_basic_block_2048 | program-scale | 6 | 6 | yes | - | 3844 | 3769 | -75 |
| rotate64_hash | alu-mix | 7 | 7 | yes | - | 340 | 315 | -25 |
| packet_redundant_bounds | memory-local | 6 | 6 | yes | - | 452 | 443 | -9 |
| const_fold_chain | program-scale | 2 | 2 | yes | - | 1200 | 1036 | -164 |
| struct_field_cluster | memory-local | 0 | 0 | no | no_sites | 316 | n/a | n/a |
| bitfield_extract | memory-local | 2 | 2 | yes | - | 945 | 969 | 24 |
| smallmul_strength_reduce | alu-mix | 2 | 2 | yes | - | 1228 | 1277 | 49 |
| cond_select_dense | control-flow | 0 | 0 | no | no_sites | 379 | n/a | n/a |
| rotate_dense | alu-mix | 0 | 0 | no | no_sites | 895 | n/a | n/a |
| addr_calc_stride | memory-local | 0 | 0 | no | no_sites | 936 | n/a | n/a |
| extract_dense | memory-local | 0 | 0 | no | no_sites | 662 | n/a | n/a |
| endian_swap_dense | memory-local | 0 | 0 | no | no_sites | 409 | n/a | n/a |
| branch_flip_dense | control-flow | 0 | 0 | no | no_sites | 1110 | n/a | n/a |
| tc_bitcount | alu-mix | 2 | 2 | yes | - | 15923 | 18039 | 2116 |
| tc_checksum | memory-local | 2 | 2 | yes | - | 45167 | 42701 | -2466 |
| cgroup_hash_chain | alu-mix | 2 | 2 | yes | - | 1040 | 1008 | -32 |

## Notes

- Two earlier AWS retries failed before this successful run. I fixed the local ARM64 bundle layout so the remote host receives `daemon/target/release/bpfrejit-daemon`, and I fixed the remote benchmark reader to load `micro/driver.py` results from the run-artifact directory (`details/result.json`) instead of assuming a flat output JSON file exists.
- Earlier setup retries also exposed local cache/kernel issues: corrupted cached EFI image after an `ENOSPC` event, missing `XFS/ENA/NVME` config in the ARM64 kernel, and missing `EFI_ZBOOT` when building `vmlinuz.efi`. Those were repaired before the successful final run.
- The raw JSON file is the authoritative record for all benchmark details, including per-sample payloads, compile timings, phase timings, daemon scan output, and Katran smoke metadata.
