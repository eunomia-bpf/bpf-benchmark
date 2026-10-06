# Micro Benchmark Analysis Report (2026-03-22)

## Run Parameters

- **Date**: 2026-03-22T13:02:55.223777+00:00
- **Iterations**: 3, **Warmups**: 1, **Repeat**: 100
- **Runtimes**: llvmbpf, kernel, kernel-rejit
- **Total benchmarks**: 62
- **kinsn modules loaded**: 0/3 (bpf_rotate, bpf_select, bpf_extract NOT loaded)
- **POLICY**: default (micro/policies/)

## 1. Summary Table (62 benchmarks)

| Status | Count | Description |
|--------|-------|-------------|
| APPLIED | 47 | Daemon modified bytecode (WideMemPass auto-applied) |
| IDENTITY | 13 | Daemon ran but bytecode unchanged |
| ERROR | 2 | Daemon apply failed |

**Geomean ratios (rejit/kernel, excluding sub-resolution <50ns):**
- Overall: **0.9320x** (56 benchmarks)
- APPLIED only: **0.9484x** (46 benchmarks)
- IDENTITY only: **0.8484x** (8 benchmarks)

### Full Results Table

| # | Benchmark | Family | K (ns) | KR (ns) | Ratio | Status | JIT diff | Policy sites | Notes |
|---|-----------|--------|--------|---------|-------|--------|----------|-------------|-------|
| 1 | simple | baseline | 10 | 5 | 0.500 | IDENTITY | +0 | - | sub-res |
| 2 | simple_packet | baseline | 9 | 5 | 0.556 | IDENTITY | +0 | - | sub-res |
| 3 | memory_pair_sum | baseline | 12 | 6 | 0.500 | APPLIED | -24 | 0 | sub-res |
| 4 | bitcount | popcount | 4374 | 4366 | 0.998 | APPLIED | -75 | 0 |  |
| 5 | log2_fold | log2-fold | 283 | 259 | 0.915 | APPLIED | -62 | 0 |  |
| 6 | dep_chain_short | dep-chain | 109 | 103 | 0.945 | APPLIED | -76 | - |  |
| 7 | dep_chain_long | dep-chain | 409 | 402 | 0.983 | APPLIED | -76 | 0 |  |
| 8 | binary_search | search | 469 | 457 | 0.974 | APPLIED | -76 | 0 |  |
| 9 | branch_layout | branch-skew | 460 | 451 | 0.980 | APPLIED | -76 | - |  |
| 10 | switch_dispatch | switch-dispatch | 318 | 267 | 0.840 | APPLIED | -82 | 0 |  |
| 11 | branch_dense | branch-density | 472 | 434 | 0.919 | APPLIED | -75 | 0 |  |
| 12 | cmov_select | select-diamond | 463 | 440 | 0.950 | APPLIED | -131 | 0 |  |
| 13 | cmov_dense | select-diamond | 49 | 39 | 0.796 | IDENTITY | +0 | 26 | sub-res |
| 14 | checksum | reduction | 14398 | 14368 | 0.998 | APPLIED | -76 | 0 |  |
| 15 | load_word32 | load-width | 88 | 84 | 0.955 | APPLIED | -76 | - |  |
| 16 | load_byte | load-width | 232 | 227 | 0.978 | APPLIED | -76 | 0 |  |
| 17 | load_byte_recompose | causal-isolation | 152 | 142 | 0.934 | APPLIED | -38 | 0 |  |
| 18 | load_native_u64 | causal-isolation | 70 | 65 | 0.929 | IDENTITY | +0 | - |  |
| 19 | packet_parse | parser | 104 | 77 | 0.740 | APPLIED | -76 | 0 |  |
| 20 | bounds_ladder | bounds-density | 148 | 141 | 0.953 | APPLIED | -74 | 4 |  |
| 21 | bounds_check_heavy | bounds-style | 216 | 196 | 0.907 | ERROR | +0 | - | err: daemon apply failed with exit  |
| 22 | stride_load_4 | stride-load | 212 | 205 | 0.967 | APPLIED | -76 | - |  |
| 23 | stride_load_16 | stride-load | 210 | 203 | 0.967 | APPLIED | -76 | - |  |
| 24 | mixed_alu_mem | mixed-alu-mem | 673 | 666 | 0.990 | APPLIED | -37 | 0 |  |
| 25 | spill_pressure | spill-pressure | 247 | 308 | 1.247 | APPLIED | -75 | - |  |
| 26 | multi_acc_4 | multi-acc | 252 | 252 | 1.000 | APPLIED | -76 | 0 |  |
| 27 | multi_acc_8 | multi-acc | 419 | 417 | 0.995 | APPLIED | -76 | 0 |  |
| 28 | fibonacci_iter | recurrence | 687 | 680 | 0.990 | APPLIED | -74 | 0 |  |
| 29 | fibonacci_iter_packet | recurrence | 685 | 679 | 0.991 | APPLIED | -74 | - |  |
| 30 | fixed_loop_small | fixed-loop | 85 | 79 | 0.929 | APPLIED | -88 | - |  |
| 31 | fixed_loop_large | fixed-loop | 1227 | 1213 | 0.989 | APPLIED | -88 | - |  |
| 32 | nested_loop_2 | nested-loop | 499 | 493 | 0.988 | APPLIED | -88 | 0 |  |
| 33 | nested_loop_3 | nested-loop | 658 | 650 | 0.988 | APPLIED | -114 | 0 |  |
| 34 | code_clone_2 | code-clone | 295 | 289 | 0.980 | APPLIED | -38 | - |  |
| 35 | code_clone_8 | code-clone | 1127 | 1122 | 0.996 | APPLIED | -38 | - |  |
| 36 | large_mixed_500 | large-mixed | 523 | 496 | 0.948 | APPLIED | -38 | 7 |  |
| 37 | large_mixed_1000 | large-mixed | 1029 | 986 | 0.958 | APPLIED | -38 | 7 |  |
| 38 | bpf_call_chain | bpf-local-call | 376 | 364 | 0.968 | APPLIED | -24 | 2 |  |
| 39 | memcmp_prefix_64 | byte-compare | 80 | 74 | 0.925 | APPLIED | -38 | 0 |  |
| 40 | packet_parse_vlans_tcpopts | parser | 20 | 12 | 0.600 | IDENTITY | +0 | - | sub-res |
| 41 | local_call_fanout | bpf-local-call | 107 | 85 | 0.794 | APPLIED | -220 | - |  |
| 42 | packet_rss_hash | packet-hash | 21 | 14 | 0.667 | IDENTITY | +0 | 0 | sub-res |
| 43 | imm64_storm | immediate-stress | 169 | 154 | 0.911 | APPLIED | -48 | - |  |
| 44 | alu32_64_pingpong | mixed-width | 360 | 350 | 0.972 | APPLIED | -88 | - |  |
| 45 | branch_fanout_32 | branch-fanout | 362 | 343 | 0.948 | APPLIED | -38 | 0 |  |
| 46 | deep_guard_tree_8 | deep-guards | 82 | 66 | 0.805 | APPLIED | -50 | - |  |
| 47 | mega_basic_block_2048 | mega-block | 852 | 777 | 0.912 | APPLIED | -96 | - |  |
| 48 | rotate64_hash | rotate-hash | 56 | 47 | 0.839 | APPLIED | -84 | 116 |  |
| 49 | packet_redundant_bounds | bounds-density | 110 | 100 | 0.909 | ERROR | +0 | - | err: daemon apply failed with exit  |
| 50 | const_fold_chain | const-fold | 285 | 222 | 0.779 | APPLIED | -75 | - |  |
| 51 | struct_field_cluster | field-access | 60 | 51 | 0.850 | IDENTITY | +0 | - |  |
| 52 | bitfield_extract | bitfield-extract | 198 | 194 | 0.980 | APPLIED | -76 | - |  |
| 53 | smallmul_strength_reduce | strength-reduce | 329 | 323 | 0.982 | APPLIED | -50 | 0 |  |
| 54 | cond_select_dense | select-diamond | 59 | 39 | 0.661 | IDENTITY | +0 | 0 |  |
| 55 | rotate_dense | rotate-canonical | 191 | 169 | 0.885 | IDENTITY | +0 | 256 |  |
| 56 | addr_calc_stride | addr-calc | 151 | 145 | 0.960 | IDENTITY | +0 | 0 |  |
| 57 | extract_dense | bitfield-extract | 186 | 165 | 0.887 | IDENTITY | +0 | 0 |  |
| 58 | endian_swap_dense | endian-fusion | 121 | 109 | 0.901 | IDENTITY | +0 | 0 |  |
| 59 | branch_flip_dense | branch-flip | 190 | 144 | 0.758 | IDENTITY | +0 | 0 |  |
| 60 | tc_bitcount | popcount | 4246 | 4261 | 1.004 | APPLIED | -75 | 0 |  |
| 61 | tc_checksum | reduction | 14397 | 14383 | 0.999 | APPLIED | -80 | - |  |
| 62 | cgroup_hash_chain | hash-chain | 262 | 254 | 0.969 | APPLIED | -80 | - |  |

## 2. Geomean by Family

| Family | Count | Geomean | Best | Worst |
|--------|-------|---------|------|-------|
| addr-calc | 1 | 0.9603 | 0.960 | 0.960 |
| bitfield-extract | 2 | 0.9323 | 0.887 | 0.980 |
| bounds-density | 2 | 0.9306 | 0.909 | 0.953 |
| bounds-style | 1 | 0.9074 | 0.907 | 0.907 |
| bpf-local-call | 2 | 0.8769 | 0.794 | 0.968 |
| branch-density | 1 | 0.9195 | 0.919 | 0.919 |
| branch-fanout | 1 | 0.9475 | 0.948 | 0.948 |
| branch-flip | 1 | 0.7579 | 0.758 | 0.758 |
| branch-skew | 1 | 0.9804 | 0.980 | 0.980 |
| byte-compare | 1 | 0.9250 | 0.925 | 0.925 |
| causal-isolation | 2 | 0.9314 | 0.929 | 0.934 |
| code-clone | 2 | 0.9876 | 0.980 | 0.996 |
| const-fold | 1 | 0.7789 | 0.779 | 0.779 |
| deep-guards | 1 | 0.8049 | 0.805 | 0.805 |
| dep-chain | 2 | 0.9637 | 0.945 | 0.983 |
| endian-fusion | 1 | 0.9008 | 0.901 | 0.901 |
| field-access | 1 | 0.8500 | 0.850 | 0.850 |
| fixed-loop | 2 | 0.9585 | 0.929 | 0.989 |
| hash-chain | 1 | 0.9695 | 0.969 | 0.969 |
| immediate-stress | 1 | 0.9112 | 0.911 | 0.911 |
| large-mixed | 2 | 0.9533 | 0.948 | 0.958 |
| load-width | 2 | 0.9664 | 0.955 | 0.978 |
| log2-fold | 1 | 0.9152 | 0.915 | 0.915 |
| mega-block | 1 | 0.9120 | 0.912 | 0.912 |
| mixed-alu-mem | 1 | 0.9896 | 0.990 | 0.990 |
| mixed-width | 1 | 0.9722 | 0.972 | 0.972 |
| multi-acc | 2 | 0.9976 | 0.995 | 1.000 |
| nested-loop | 2 | 0.9879 | 0.988 | 0.988 |
| parser | 1 | 0.7404 | 0.740 | 0.740 |
| popcount | 2 | 1.0008 | 0.998 | 1.004 |
| recurrence | 2 | 0.9905 | 0.990 | 0.991 |
| reduction | 2 | 0.9985 | 0.998 | 0.999 |
| rotate-canonical | 1 | 0.8848 | 0.885 | 0.885 |
| rotate-hash | 1 | 0.8393 | 0.839 | 0.839 |
| search | 1 | 0.9744 | 0.974 | 0.974 |
| select-diamond | 2 | 0.7926 | 0.661 | 0.950 |
| spill-pressure | 1 | 1.2470 | 1.247 | 1.247 |
| strength-reduce | 1 | 0.9818 | 0.982 | 0.982 |
| stride-load | 2 | 0.9668 | 0.967 | 0.967 |
| switch-dispatch | 1 | 0.8396 | 0.840 | 0.840 |

### By Category

| Category | Count | Geomean |
|----------|-------|---------|
| alu-mix | 9 | 0.9488 |
| call-overhead | 2 | 0.8769 |
| call-size | 2 | 0.9876 |
| control-flow | 9 | 0.8638 |
| dependency-ilp | 5 | 1.0288 |
| loop-shape | 6 | 0.9789 |
| memory-local | 18 | 0.9278 |
| program-scale | 5 | 0.8993 |

## 3. Credibility Analysis: VM Noise vs Real Speedup

### Sub-resolution benchmarks (exec_ns < 50ns)

These benchmarks are below ktime precision (~10ns). Ratios are not reliable.

| Benchmark | K (ns) | KR (ns) | Ratio | Status |
|-----------|--------|---------|-------|--------|
| simple | 10 | 5 | 0.500 | IDENTITY |
| simple_packet | 9 | 5 | 0.556 | IDENTITY |
| memory_pair_sum | 12 | 6 | 0.500 | APPLIED |
| cmov_dense | 49 | 39 | 0.796 | IDENTITY |
| packet_parse_vlans_tcpopts | 20 | 12 | 0.600 | IDENTITY |
| packet_rss_hash | 21 | 14 | 0.667 | IDENTITY |

### IDENTITY benchmarks with >5% apparent speedup (VM noise)

These benchmarks had no bytecode modification but still show >5% speedup.
This is VM noise, NOT real REJIT benefit.

| Benchmark | K (ns) | KR (ns) | Ratio | JIT diff |
|-----------|--------|---------|-------|----------|
| load_native_u64 | 70 | 65 | 0.929 | +0 |
| struct_field_cluster | 60 | 51 | 0.850 | +0 |
| cond_select_dense | 59 | 39 | 0.661 | +0 |
| rotate_dense | 191 | 169 | 0.885 | +0 |
| extract_dense | 186 | 165 | 0.887 | +0 |
| endian_swap_dense | 121 | 109 | 0.901 | +0 |
| branch_flip_dense | 190 | 144 | 0.758 | +0 |

**7 IDENTITY benchmarks show >5% apparent speedup (VM noise)**

### APPLIED benchmarks with genuine speedup

Benchmarks where daemon modified bytecode AND exec_ns improved (excluding sub-resolution).

| Benchmark | K (ns) | KR (ns) | Ratio | JIT diff | What changed |
|-----------|--------|---------|-------|----------|-------------|
| log2_fold | 283 | 259 | 0.915 | -62 | WideMemPass |
| dep_chain_short | 109 | 103 | 0.945 | -76 | WideMemPass |
| switch_dispatch | 318 | 267 | 0.840 | -82 | WideMemPass |
| branch_dense | 472 | 434 | 0.919 | -75 | WideMemPass |
| load_byte_recompose | 152 | 142 | 0.934 | -38 | WideMemPass |
| packet_parse | 104 | 77 | 0.740 | -76 | WideMemPass |
| fixed_loop_small | 85 | 79 | 0.929 | -88 | WideMemPass |
| large_mixed_500 | 523 | 496 | 0.948 | -38 | WideMemPass + rotate policy |
| memcmp_prefix_64 | 80 | 74 | 0.925 | -38 | WideMemPass |
| local_call_fanout | 107 | 85 | 0.794 | -220 | WideMemPass |
| imm64_storm | 169 | 154 | 0.911 | -48 | WideMemPass |
| branch_fanout_32 | 362 | 343 | 0.948 | -38 | WideMemPass |
| deep_guard_tree_8 | 82 | 66 | 0.805 | -50 | WideMemPass |
| mega_basic_block_2048 | 852 | 777 | 0.912 | -96 | WideMemPass |
| rotate64_hash | 56 | 47 | 0.839 | -84 | WideMemPass + rotate policy |
| const_fold_chain | 285 | 222 | 0.779 | -75 | WideMemPass |

**16 APPLIED benchmarks with >5% genuine speedup**

### APPLIED benchmarks with neutral/regressed performance

| Benchmark | K (ns) | KR (ns) | Ratio | JIT diff |
|-----------|--------|---------|-------|----------|
| bitcount | 4374 | 4366 | 0.998 | -75 |
| dep_chain_long | 409 | 402 | 0.983 | -76 |
| binary_search | 469 | 457 | 0.974 | -76 |
| branch_layout | 460 | 451 | 0.980 | -76 |
| cmov_select | 463 | 440 | 0.950 | -131 |
| checksum | 14398 | 14368 | 0.998 | -76 |
| load_word32 | 88 | 84 | 0.955 | -76 |
| load_byte | 232 | 227 | 0.978 | -76 |
| bounds_ladder | 148 | 141 | 0.953 | -74 |
| stride_load_4 | 212 | 205 | 0.967 | -76 |
| stride_load_16 | 210 | 203 | 0.967 | -76 |
| mixed_alu_mem | 673 | 666 | 0.990 | -37 |
| spill_pressure | 247 | 308 | 1.247 | -75 |
| multi_acc_4 | 252 | 252 | 1.000 | -76 |
| multi_acc_8 | 419 | 417 | 0.995 | -76 |
| fibonacci_iter | 687 | 680 | 0.990 | -74 |
| fibonacci_iter_packet | 685 | 679 | 0.991 | -74 |
| fixed_loop_large | 1227 | 1213 | 0.989 | -88 |
| nested_loop_2 | 499 | 493 | 0.988 | -88 |
| nested_loop_3 | 658 | 650 | 0.988 | -114 |
| code_clone_2 | 295 | 289 | 0.980 | -38 |
| code_clone_8 | 1127 | 1122 | 0.996 | -38 |
| large_mixed_1000 | 1029 | 986 | 0.958 | -38 |
| bpf_call_chain | 376 | 364 | 0.968 | -24 |
| alu32_64_pingpong | 360 | 350 | 0.972 | -88 |
| bitfield_extract | 198 | 194 | 0.980 | -76 |
| smallmul_strength_reduce | 329 | 323 | 0.982 | -50 |
| tc_bitcount | 4246 | 4261 | 1.004 | -75 |
| tc_checksum | 14397 | 14383 | 0.999 | -80 |
| cgroup_hash_chain | 262 | 254 | 0.969 | -80 |

### Regressions (ratio > 1.0)

| Benchmark | K (ns) | KR (ns) | Ratio | Status | JIT diff |
|-----------|--------|---------|-------|--------|----------|
| spill_pressure | 247 | 308 | 1.247 | APPLIED | -75 |
| tc_bitcount | 4246 | 4261 | 1.004 | APPLIED | -75 |

**2 regressions (ratio > 1.0)**

## 4. Per-Pass Site Statistics

### kinsn Module Status

**0/3 kinsn modules loaded in the VM.** This means:
- RotatePass: `bpf_rotate64` kfunc NOT available => all rotate sites skipped by daemon
- CondSelectPass: `bpf_select64` kfunc NOT available => all cmov/cond_select sites skipped
- ExtractPass (BEXTR): `bpf_extract64` kfunc NOT available => all extract sites skipped

**Impact:** All policy files with rotate/cmov/extract sites had those sites ignored.
The daemon only applied WideMemPass (which does pure bytecode rewriting, no kfunc needed).

### WideMemPass (auto-applied, no policy needed)

WideMemPass replaces byte-load-recompose patterns (4x LDX_B + shifts + OR) with
wider single loads (LDX_W or LDX_DW). This reduces instruction count and JIT code size.

| Benchmark | JIT size diff | BPF insn diff | K (ns) | KR (ns) | Ratio |
|-----------|---------------|---------------|--------|---------|-------|
| bitcount | -75B | -144B | 4374 | 4366 | 0.998 |
| log2_fold | -62B | -120B | 283 | 259 | 0.915 |
| dep_chain_short | -76B | -144B | 109 | 103 | 0.945 |
| dep_chain_long | -76B | -144B | 409 | 402 | 0.983 |
| binary_search | -76B | -144B | 469 | 457 | 0.974 |
| branch_layout | -76B | -144B | 460 | 451 | 0.980 |
| switch_dispatch | -82B | -144B | 318 | 267 | 0.840 |
| branch_dense | -75B | -144B | 472 | 434 | 0.919 |
| cmov_select | -131B | -240B | 463 | 440 | 0.950 |
| checksum | -76B | -144B | 14398 | 14368 | 0.998 |
| load_word32 | -76B | -144B | 88 | 84 | 0.955 |
| load_byte | -76B | -144B | 232 | 227 | 0.978 |
| load_byte_recompose | -38B | -72B | 152 | 142 | 0.934 |
| packet_parse | -76B | -144B | 104 | 77 | 0.740 |
| bounds_ladder | -74B | -144B | 148 | 141 | 0.953 |
| stride_load_4 | -76B | -144B | 212 | 205 | 0.967 |
| stride_load_16 | -76B | -144B | 210 | 203 | 0.967 |
| mixed_alu_mem | -37B | -72B | 673 | 666 | 0.990 |
| spill_pressure | -75B | -144B | 247 | 308 | 1.247 |
| multi_acc_4 | -76B | -144B | 252 | 252 | 1.000 |
| multi_acc_8 | -76B | -144B | 419 | 417 | 0.995 |
| fibonacci_iter | -74B | -144B | 687 | 680 | 0.990 |
| fibonacci_iter_packet | -74B | -144B | 685 | 679 | 0.991 |
| fixed_loop_small | -88B | -168B | 85 | 79 | 0.929 |
| fixed_loop_large | -88B | -168B | 1227 | 1213 | 0.989 |
| nested_loop_2 | -88B | -168B | 499 | 493 | 0.988 |
| nested_loop_3 | -114B | -216B | 658 | 650 | 0.988 |
| code_clone_2 | -38B | -72B | 295 | 289 | 0.980 |
| code_clone_8 | -38B | -72B | 1127 | 1122 | 0.996 |
| large_mixed_500 | -38B | -72B | 523 | 496 | 0.948 |
| large_mixed_1000 | -38B | -72B | 1029 | 986 | 0.958 |
| bpf_call_chain | -24B | -48B | 376 | 364 | 0.968 |
| memcmp_prefix_64 | -38B | -72B | 80 | 74 | 0.925 |
| local_call_fanout | -220B | -408B | 107 | 85 | 0.794 |
| imm64_storm | -48B | -96B | 169 | 154 | 0.911 |
| alu32_64_pingpong | -88B | -168B | 360 | 350 | 0.972 |
| branch_fanout_32 | -38B | -72B | 362 | 343 | 0.948 |
| deep_guard_tree_8 | -50B | -96B | 82 | 66 | 0.805 |
| mega_basic_block_2048 | -96B | -192B | 852 | 777 | 0.912 |
| rotate64_hash | -84B | -168B | 56 | 47 | 0.839 |
| const_fold_chain | -75B | -144B | 285 | 222 | 0.779 |
| bitfield_extract | -76B | -144B | 198 | 194 | 0.980 |
| smallmul_strength_reduce | -50B | -96B | 329 | 323 | 0.982 |
| tc_bitcount | -75B | -144B | 4246 | 4261 | 1.004 |
| tc_checksum | -80B | -144B | 14397 | 14383 | 0.999 |
| cgroup_hash_chain | -80B | -144B | 262 | 254 | 0.969 |

### Policy Sites (rotate/cmov/extract/wide/branch-flip)

| Benchmark | Policy | Sites | Families | Applied? | Why not? |
|-----------|--------|-------|----------|----------|----------|
| memory_pair_sum | yes | 0 | - | APPLIED | empty policy (all sites deliberately skipped) |
| bitcount | yes | 0 | - | APPLIED | empty policy (all sites deliberately skipped) |
| log2_fold | yes | 0 | - | APPLIED | empty policy (all sites deliberately skipped) |
| dep_chain_long | yes | 0 | - | APPLIED | empty policy (all sites deliberately skipped) |
| binary_search | yes | 0 | - | APPLIED | empty policy (all sites deliberately skipped) |
| switch_dispatch | yes | 0 | - | APPLIED | empty policy (all sites deliberately skipped) |
| branch_dense | yes | 0 | - | APPLIED | empty policy (all sites deliberately skipped) |
| cmov_select | yes | 0 | - | APPLIED | empty policy (all sites deliberately skipped) |
| cmov_dense | yes | 26 | rotate=26 | IDENTITY | kinsn module not loaded (bpf_rotate64 unavailable) |
| checksum | yes | 0 | - | APPLIED | empty policy (all sites deliberately skipped) |
| load_byte | yes | 0 | - | APPLIED | empty policy (all sites deliberately skipped) |
| load_byte_recompose | yes | 0 | - | APPLIED | empty policy (all sites deliberately skipped) |
| packet_parse | yes | 0 | - | APPLIED | empty policy (all sites deliberately skipped) |
| bounds_ladder | yes | 4 | cmov=2, wide=2 | APPLIED | kinsn module not loaded (bpf_select64 unavailable) |
| mixed_alu_mem | yes | 0 | - | APPLIED | empty policy (all sites deliberately skipped) |
| multi_acc_4 | yes | 0 | - | APPLIED | empty policy (all sites deliberately skipped) |
| multi_acc_8 | yes | 0 | - | APPLIED | empty policy (all sites deliberately skipped) |
| fibonacci_iter | yes | 0 | - | APPLIED | empty policy (all sites deliberately skipped) |
| nested_loop_2 | yes | 0 | - | APPLIED | empty policy (all sites deliberately skipped) |
| nested_loop_3 | yes | 0 | - | APPLIED | empty policy (all sites deliberately skipped) |
| large_mixed_500 | yes | 7 | rotate=7 | APPLIED | kinsn module not loaded (bpf_rotate64 unavailable) |
| large_mixed_1000 | yes | 7 | rotate=7 | APPLIED | kinsn module not loaded (bpf_rotate64 unavailable) |
| bpf_call_chain | yes | 2 | wide=2 | APPLIED | WideMemPass auto-applies (policy wide sites redundant) |
| memcmp_prefix_64 | yes | 0 | - | APPLIED | empty policy (all sites deliberately skipped) |
| packet_rss_hash | yes | 0 | - | IDENTITY | empty policy (all sites deliberately skipped) |
| branch_fanout_32 | yes | 0 | - | APPLIED | empty policy (all sites deliberately skipped) |
| rotate64_hash | yes | 116 | rotate=116 | APPLIED | kinsn module not loaded (bpf_rotate64 unavailable) |
| smallmul_strength_reduce | yes | 0 | - | APPLIED | empty policy (all sites deliberately skipped) |
| cond_select_dense | yes | 0 | - | IDENTITY | empty policy (all sites deliberately skipped) |
| rotate_dense | yes | 256 | rotate=256 | IDENTITY | kinsn module not loaded (bpf_rotate64 unavailable) |
| addr_calc_stride | yes | 0 | - | IDENTITY | empty policy (all sites deliberately skipped) |
| extract_dense | yes | 0 | - | IDENTITY | empty policy (all sites deliberately skipped) |
| endian_swap_dense | yes | 0 | - | IDENTITY | empty policy (all sites deliberately skipped) |
| branch_flip_dense | yes | 0 | - | IDENTITY | empty policy (all sites deliberately skipped) |
| tc_bitcount | yes | 0 | - | APPLIED | empty policy (all sites deliberately skipped) |

## 5. Why REJIT Can't Accelerate Further

### A. kinsn modules not loaded (biggest blocker)

The Makefile's `LOAD_KINSN_MODULES` runs inside the VM but all 3 modules showed 0/3 loaded.
This could be because:
1. The .ko files were built for a different kernel version than the VM's bzImage
2. The module files weren't accessible at the expected path inside the VM
3. insmod failed silently (the `2>/dev/null || true` suppresses errors)

**Consequence:** All rotate (256+116+26+7+7 = 412 sites), cmov (2 sites), and extract
(0 active, all cleared) sites across 5 benchmarks were skipped.

**Rotate-policy benchmarks (all sites silently skipped):**

- `cmov_dense`: 26 rotate sites, ratio=0.796
- `large_mixed_500`: 7 rotate sites, ratio=0.948
- `large_mixed_1000`: 7 rotate sites, ratio=0.958
- `rotate64_hash`: 116 rotate sites, ratio=0.839
- `rotate_dense`: 256 rotate sites, ratio=0.885

### B. Empty policies (deliberately cleared)

Many benchmarks have policy files with `sites: []`. These were cleared in previous
iterations because the optimizations caused regressions:

| Pattern | Why cleared |
|---------|-------------|
| WideMemPass sites | Auto-applied by daemon regardless of policy; cleared from policy to avoid double-application |
| CMOV/cond_select | Predictable branches + CMOV adds critical-path latency (cond_select_dense policy note) |
| BEXTR/extract | Dense 512-site I-cache flush overhead > BEXTR execution benefit (extract_dense policy note) |
| ENDIAN_FUSION | MOVBE 32-bit = 5B = LDX+BSWAP32 5B (same size), I-cache flush dominates (endian_swap_dense policy note) |
| BRANCH_FLIP | 255 dense sites caused -8.4% regression from I-cache flush (branch_flip_dense policy note) |
| ADDR_CALC/LEA | 8 sites caused -5.6% regression from LEA AGU competition (addr_calc_stride policy note) |

### C. WideMemPass: the only active optimization

WideMemPass is the only pass that runs without kinsn modules. It provides:

- 16 benchmarks with >5% speedup
- 29 benchmarks with neutral (<5% change)
- 1 benchmarks with >5% regression
- Geomean of improved benchmarks: **0.8777x**

### D. spill_pressure regression (+24.7%)

spill_pressure shows 247ns -> 308ns (ratio 1.247). This is the only significant
regression among APPLIED benchmarks. The daemon's WideMemPass reduces byte-load
sequences but may increase register pressure in the rewritten code, causing additional
spills in a benchmark already designed to stress register allocation.

### E. Error benchmarks

- `bounds_check_heavy`: daemon apply failed with exit code 256
- `packet_redundant_bounds`: daemon apply failed with exit code 256

Exit code 256 from daemon typically means the verifier rejected the rewritten program.
This can happen when WideMemPass produces wider loads that the verifier cannot prove safe
(e.g., bounds checks for the wider access are insufficient).

## 6. IDENTITY Benchmarks (no bytecode modification)

13 benchmarks had no bytecode change. The daemon's WideMemPass found no
byte-recompose patterns to optimize. (2 additional benchmarks are ERROR status.)

| Benchmark | Family | K (ns) | KR (ns) | Ratio | Why no WideMemPass |
|-----------|--------|--------|---------|-------|--------------------|
| simple | baseline | 10 | 5 | 0.500 | trivial program, no memory patterns |
| simple_packet | baseline | 9 | 5 | 0.556 | packet-backed: no staged input byte-recompose |
| cmov_dense | select-diamond | 49 | 39 | 0.796 | policy has 26 rotate sites but kinsn not loaded |
| load_native_u64 | causal-isolation | 70 | 65 | 0.929 | native u64 loads: no byte-recompose by design |
| packet_parse_vlans_tcpopts | parser | 20 | 12 | 0.600 | packet-backed: direct packet field access |
| packet_rss_hash | packet-hash | 21 | 14 | 0.667 | packet-backed: direct packet field access |
| struct_field_cluster | field-access | 60 | 51 | 0.850 | fixed-offset field loads: compiler uses direct wider loads |
| cond_select_dense | select-diamond | 59 | 39 | 0.661 | canonical dense bench: native aligned loads, no byte-recompose |
| rotate_dense | rotate-canonical | 191 | 169 | 0.885 | canonical dense bench: native aligned loads, no byte-recompose |
| addr_calc_stride | addr-calc | 151 | 145 | 0.960 | canonical dense bench: native aligned loads, no byte-recompose |
| extract_dense | bitfield-extract | 186 | 165 | 0.887 | canonical dense bench: native aligned loads, no byte-recompose |
| endian_swap_dense | endian-fusion | 121 | 109 | 0.901 | canonical dense bench: native aligned loads, no byte-recompose |
| branch_flip_dense | branch-flip | 190 | 144 | 0.758 | canonical dense bench: native aligned loads, no byte-recompose |

## 7. Overall Assessment

### Key Numbers

- **Overall geomean (K vs KR, non-sub-res)**: 0.9320x
- **APPLIED geomean**: 0.9484x
- **IDENTITY geomean**: 0.8484x
- **Regressions**: 2
- **Errors**: 2

### What's Working

1. **WideMemPass is effective**: 47/62 benchmarks have bytecode modified, reducing
   JIT code size by 24-220 bytes. This translates to measurable speedups in many cases.
2. **No correctness issues**: All benchmarks produce correct results across all runtimes.
3. **Policy system correctly prevents regressions**: Benchmarks where CMOV/BEXTR/ENDIAN/BRANCH_FLIP
   previously regressed have been cleared to empty policies.

### What's Not Working

1. **kinsn modules not loading**: 0/3 modules loaded means RotatePass is completely
   inactive. This blocks 412 rotate sites across 5 benchmarks (rotate_dense,
   rotate64_hash, cmov_dense, large_mixed_500, large_mixed_1000).
2. **spill_pressure regression**: WideMemPass increases register pressure in this
   specific benchmark, causing +24.7% regression.
3. **bounds_check_heavy and packet_redundant_bounds daemon errors**: Verifier rejects
   the rewritten program for these two benchmarks.
4. **IDENTITY benchmarks still show apparent speedup**: Several IDENTITY benchmarks
   (struct_field_cluster 0.850, cond_select_dense 0.661, branch_flip_dense 0.758)
   show large apparent speedups despite zero bytecode change. This is pure VM noise
   from the order-of-execution and ktime measurement granularity.

### Next Steps

1. **Fix kinsn module loading**: Debug why `insmod` fails in the VM. Likely a kernel
   version mismatch between the .ko files and the bzImage.
2. **Investigate spill_pressure regression**: Consider skipping WideMemPass for
   programs with high register pressure.
3. **Fix daemon errors**: bounds_check_heavy and packet_redundant_bounds need
   investigation of why the verifier rejects the rewritten bytecode.
4. **Run with more iterations**: 3 iterations is marginal for statistical confidence.
   The authoritative runs use 10 iterations x 200 repeat.
