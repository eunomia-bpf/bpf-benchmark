# Post-cmov-fix Micro Full Rerun

## Methodology

- Date: `2026-03-12`
- Suite: `config/micro_pure_jit.yaml` (`56` benchmarks; `24` policy-file rows)
- Runtime: `kernel` vs `kernel-recompile` in the framework VM
- Guest kernel: `vendor/linux-framework/arch/x86/boot/bzImage`
- Warmups / iterations / repeat: `10 / 2 / 500`
- Output JSON: `micro/results/post_cmov_fix_micro.json`
- Pre-run repair: the checked-out micro `version: 3` policy files were empty/stale in this workspace, so they were regenerated from the prior version-2 policy intent onto live framework-kernel scanner manifests, yielding `11` non-empty benchmark policies and `59` explicit sites total.
- Runtime fix: rebuilt `micro/build/runner/micro_exec` so the embedded scanner/policy parser accepted `version: 3` policy files.
- Smoke validation before the full run: `binary_search`, `switch_dispatch`, `branch_dense`, `bpf_call_chain`, `bounds_ladder`, `mixed_alu_mem`, `cmov_select`, and `cmov_dense` all preserved `stock == kernel-recompile` results with the repaired policy path.

## Headline Numbers

| Metric | #139 authoritative | Post-cmov-fix rerun | Delta |
| --- | ---: | ---: | ---: |
| Valid pairs | `56/56` | `56/56` | `+0` |
| Applied pairs | `8/56` | `11/56` | `+3` |
| Overall geomean (stock / recompile) | `1.018x` | `1.007x` | `-1.1%` |
| Applied-only geomean | `1.049x` | `0.986x` | `-6.0%` |
| Overall wins / losses / ties | `30 / 21 / 5` | `29 / 26 / 1` | `-` |
| Applied-only wins / losses / ties | `5 / 3 / 0` | `4 / 7 / 0` | `-` |

- Structural outcome: the CMOV-fix/v3-policy path increases applied rows from `8` to `11` while keeping the suite fully valid (`56/56`).
- Performance outcome: the newly applied rows are net-positive, but the previously-applied set regressed enough that the applied-only geomean fell below parity.

## Comparison With #139

- Newly applied benchmarks: `binary_search, switch_dispatch, branch_dense`.
- Newly applied subset geomean: `#139 1.025x` -> `post-cmov-fix 1.052x`.
- Previously applied subset geomean: `#139 1.049x` -> `post-cmov-fix 0.962x`.
- Biggest structural changes in selected sites among previously-applied rows:
  - `bounds_ladder`: `2 -> 4` sites (`wide=2, cmov=2`)
  - `bpf_call_chain`: `2 -> 3` sites (`wide=2, cmov=1`)
  - `mixed_alu_mem`: `2 -> 3` sites (`wide=1, extract=2`)
- Biggest ratio deltas versus #139 among applied rows:
  - Better: `binary_search` `0.986x -> 1.113x`
  - Better: `log2_fold` `1.042x -> 1.117x`
  - Better: `large_mixed_500` `0.947x -> 0.980x`
  - Worse: `memcmp_prefix_64` `1.229x -> 0.820x`
  - Worse: `cmov_dense` `1.230x -> 1.017x`
  - Worse: `bpf_call_chain` `1.109x -> 0.960x`

## Newly Applied Rows

| Benchmark | Sites | Site mix | #139 ratio | Post-cmov-fix ratio |
| --- | ---: | --- | ---: | ---: |
| `binary_search` | `3` | `cmov=1, wide=2` | `0.986x` | `1.113x` |
| `switch_dispatch` | `3` | `cmov=1, wide=2` | `1.075x` | `1.054x` |
| `branch_dense` | `7` | `cmov=1, wide=2, branch-flip=4` | `1.017x` | `0.992x` |

## Per-Benchmark Table

| Benchmark | Family | Applied | Sites | Stock median | Recompile median | Stock / recompile | Status |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `simple` | `baseline` | `no` | `0` | `9 ns` | `13 ns` | `0.692x` | `loss` |
| `simple_packet` | `baseline` | `no` | `0` | `11.5 ns` | `13 ns` | `0.885x` | `loss` |
| `memory_pair_sum` | `baseline` | `no` | `0` | `13 ns` | `13 ns` | `1.000x` | `tie` |
| `bitcount` | `popcount` | `no` | `0` | `4.539 us` | `4.847 us` | `0.936x` | `loss` |
| `log2_fold` | `log2-fold` | `yes` | `3` | `391 ns` | `350 ns` | `1.117x` | `win` |
| `dep_chain_short` | `dep-chain` | `no` | `0` | `203.5 ns` | `189.5 ns` | `1.074x` | `win` |
| `dep_chain_long` | `dep-chain` | `no` | `0` | `583 ns` | `538 ns` | `1.084x` | `win` |
| `binary_search` | `search` | `yes` | `3` | `648.5 ns` | `582.5 ns` | `1.113x` | `win` |
| `branch_layout` | `branch-skew` | `no` | `0` | `693.5 ns` | `598.5 ns` | `1.159x` | `win` |
| `switch_dispatch` | `switch-dispatch` | `yes` | `3` | `360.5 ns` | `342 ns` | `1.054x` | `win` |
| `branch_dense` | `branch-density` | `yes` | `7` | `547.5 ns` | `552 ns` | `0.992x` | `loss` |
| `cmov_select` | `select-diamond` | `yes` | `1` | `585.5 ns` | `621 ns` | `0.943x` | `loss` |
| `cmov_dense` | `select-diamond` | `yes` | `26` | `60.5 ns` | `59.5 ns` | `1.017x` | `win` |
| `checksum` | `reduction` | `no` | `0` | `17.758 us` | `17.831 us` | `0.996x` | `loss` |
| `load_word32` | `load-width` | `no` | `0` | `146.5 ns` | `127.5 ns` | `1.149x` | `win` |
| `load_byte` | `load-width` | `no` | `0` | `344 ns` | `283 ns` | `1.216x` | `win` |
| `load_byte_recompose` | `causal-isolation` | `no` | `0` | `250.5 ns` | `248.5 ns` | `1.008x` | `win` |
| `load_native_u64` | `causal-isolation` | `no` | `0` | `109 ns` | `123.5 ns` | `0.883x` | `loss` |
| `packet_parse` | `parser` | `no` | `0` | `132.5 ns` | `133.5 ns` | `0.993x` | `loss` |
| `bounds_ladder` | `bounds-density` | `yes` | `4` | `213 ns` | `238 ns` | `0.895x` | `loss` |
| `bounds_check_heavy` | `bounds-style` | `no` | `0` | `285.5 ns` | `340 ns` | `0.840x` | `loss` |
| `stride_load_4` | `stride-load` | `no` | `0` | `262 ns` | `326.5 ns` | `0.802x` | `loss` |
| `stride_load_16` | `stride-load` | `no` | `0` | `277.5 ns` | `290.5 ns` | `0.955x` | `loss` |
| `mixed_alu_mem` | `mixed-alu-mem` | `yes` | `3` | `862 ns` | `868.5 ns` | `0.993x` | `loss` |
| `spill_pressure` | `spill-pressure` | `no` | `0` | `391.5 ns` | `350.5 ns` | `1.117x` | `win` |
| `multi_acc_4` | `multi-acc` | `no` | `0` | `339.5 ns` | `341.5 ns` | `0.994x` | `loss` |
| `multi_acc_8` | `multi-acc` | `no` | `0` | `567.5 ns` | `530 ns` | `1.071x` | `win` |
| `fibonacci_iter` | `recurrence` | `no` | `0` | `995.5 ns` | `944 ns` | `1.055x` | `win` |
| `fibonacci_iter_packet` | `recurrence` | `no` | `0` | `912.5 ns` | `989 ns` | `0.923x` | `loss` |
| `fixed_loop_small` | `fixed-loop` | `no` | `0` | `152.5 ns` | `152 ns` | `1.003x` | `win` |
| `fixed_loop_large` | `fixed-loop` | `no` | `0` | `1.492 us` | `1.524 us` | `0.979x` | `loss` |
| `nested_loop_2` | `nested-loop` | `no` | `0` | `581 ns` | `636.5 ns` | `0.913x` | `loss` |
| `nested_loop_3` | `nested-loop` | `no` | `0` | `880.5 ns` | `935 ns` | `0.942x` | `loss` |
| `code_clone_2` | `code-clone` | `no` | `0` | `452 ns` | `429.5 ns` | `1.052x` | `win` |
| `code_clone_8` | `code-clone` | `no` | `0` | `1.526 us` | `1.478 us` | `1.032x` | `win` |
| `large_mixed_500` | `large-mixed` | `yes` | `3` | `625 ns` | `637.5 ns` | `0.980x` | `loss` |
| `large_mixed_1000` | `large-mixed` | `no` | `0` | `1.260 us` | `1.229 us` | `1.026x` | `win` |
| `bpf_call_chain` | `bpf-local-call` | `yes` | `3` | `419.5 ns` | `437 ns` | `0.960x` | `loss` |
| `memcmp_prefix_64` | `byte-compare` | `yes` | `3` | `139 ns` | `169.5 ns` | `0.820x` | `loss` |
| `packet_parse_vlans_tcpopts` | `parser` | `no` | `0` | `26 ns` | `15 ns` | `1.733x` | `win` |
| `local_call_fanout` | `bpf-local-call` | `no` | `0` | `204.5 ns` | `183.5 ns` | `1.114x` | `win` |
| `packet_rss_hash` | `packet-hash` | `no` | `0` | `24 ns` | `29 ns` | `0.828x` | `loss` |
| `imm64_storm` | `immediate-stress` | `no` | `0` | `256.5 ns` | `251.5 ns` | `1.020x` | `win` |
| `alu32_64_pingpong` | `mixed-width` | `no` | `0` | `561 ns` | `512 ns` | `1.096x` | `win` |
| `branch_fanout_32` | `branch-fanout` | `no` | `0` | `456.5 ns` | `430.5 ns` | `1.060x` | `win` |
| `deep_guard_tree_8` | `deep-guards` | `no` | `0` | `164 ns` | `132 ns` | `1.242x` | `win` |
| `mega_basic_block_2048` | `mega-block` | `no` | `0` | `1.024 us` | `1.032 us` | `0.993x` | `loss` |
| `rotate64_hash` | `rotate-hash` | `no` | `0` | `93 ns` | `72.5 ns` | `1.283x` | `win` |
| `packet_redundant_bounds` | `bounds-density` | `no` | `0` | `165.5 ns` | `189.5 ns` | `0.873x` | `loss` |
| `const_fold_chain` | `const-fold` | `no` | `0` | `349.5 ns` | `374.5 ns` | `0.933x` | `loss` |
| `struct_field_cluster` | `field-access` | `no` | `0` | `114.5 ns` | `108.5 ns` | `1.055x` | `win` |
| `bitfield_extract` | `bitfield-extract` | `no` | `0` | `270 ns` | `303.5 ns` | `0.890x` | `loss` |
| `smallmul_strength_reduce` | `strength-reduce` | `no` | `0` | `353 ns` | `339.5 ns` | `1.040x` | `win` |
| `tc_bitcount` | `popcount` | `no` | `0` | `4.527 us` | `4.517 us` | `1.002x` | `win` |
| `tc_checksum` | `reduction` | `no` | `0` | `17.709 us` | `17.701 us` | `1.000x` | `win` |
| `cgroup_hash_chain` | `hash-chain` | `no` | `0` | `309 ns` | `286.5 ns` | `1.079x` | `win` |

