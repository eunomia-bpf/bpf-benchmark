# Kernel Recompile Micro v2 Fixed Authoritative Rerun

## Methodology

- Date: `2026-03-12`
- Suite: `config/micro_pure_jit.yaml` (`56` benchmarks; `24` policy-file rows, `32` no-policy rows)
- Runtime: `kernel` vs `kernel-recompile` in framework-kernel VM
- Guest kernel: `vendor/linux-framework/arch/x86/boot/bzImage` -> `7.0.0-rc2-ge52504a75c05-dirty`
- Warmups / iterations / repeat: `2 / 10 / 500`
- VM shape: `vng --run vendor/linux-framework/arch/x86/boot/bzImage --memory 4G --cpus 2`
- Collection path: host-controlled `docs/tmp/kernel_recompile_micro_resume.py`, one benchmark per VM boot, output JSON at `micro/results/kernel_recompile_v2_fixed_authoritative_20260312.json`
- Compatibility fix applied before rerun: `docs/tmp/kernel_recompile_micro_strict.py` still referenced removed `inline_policy_text`; updated it to consume the current `policy_file`-only manifest so resume/strict collection could run again.

## Headline Numbers

| Metric | Blind all-apply (#118) | Pre-fix tuned (#126) | Fixed authoritative |
| --- | ---: | ---: | ---: |
| Overall geomean (stock / recompile) | `1.028x` | `1.027x` | `1.018x` |
| Applied-only geomean | `1.024x` | `1.040x` | `1.049x` |
| Valid / invalid pairs | `50 / 6` | `54 / 2` | `56 / 0` |
| Applied pairs | `45` | `33` | `8` |
| Wins / losses / ties | `31 / 17 / 2` | `28 / 18 / 8` | `30 / 21 / 5` |

- Fixed authoritative overall geomean is `1.018x`, versus blind `1.028x` (-1.0%) and pre-fix tuned `1.027x` (-1.0%).
- Fixed authoritative applied-only geomean is `1.049x`, above blind `1.024x` (+2.4%) and pre-fix tuned `1.040x` (+0.9%).
- This run is the first fully valid fixed-policy rerun: `56/56` valid pairs, compared with `50/56` for blind and `54/56` for the pre-fix tuned rerun.
- The new steady-state semantics matter: `32` benchmarks now have no policy file and therefore default to stock, and another `16` policy-file rows fail closed to zero selected sites. Only `8` rows actually applied recompile directives in this authoritative rerun.
- For context, the full-suite geomean now mixes `32` `none->stock` rows (`1.026x` geomean), `16` `file->skip` rows (`0.985x` geomean), and `8` actually-applied rows (`1.049x` geomean). Applied-only is therefore the more meaningful policy-quality number.

## Apples-to-Apples Subsets

- On the `5` currently-applied benchmarks that were already valid in blind all-apply, geomean improved from `0.885x` to `1.078x`: `log2_fold`, `cmov_select`, `cmov_dense`, `large_mixed_500`, `memcmp_prefix_64`.
- On the `6` currently-applied benchmarks that were already valid in the pre-fix tuned rerun, geomean improved from `0.990x` to `1.083x`: `log2_fold`, `cmov_select`, `cmov_dense`, `large_mixed_500`, `bpf_call_chain`, `memcmp_prefix_64`.
- The drop in full-suite overall geomean from `~1.028x` to `~1.018x` should therefore not be read as “policies got worse”; most of the suite is now intentionally stock-equivalent rather than blind all-apply.

## Recovered Mismatch / Crash Benchmarks

| Benchmark | Blind symptom | Fixed policy | Current status | Applied | Sites | Stock / recompile |
| --- | --- | --- | --- | ---: | ---: | ---: |
| `binary_search` | `result-mismatch` | `default skip (0 sites)` | `ok` | no | `0` | `0.986x` |
| `switch_dispatch` | `result-mismatch` | `default skip (0 sites)` | `ok` | no | `0` | `1.075x` |
| `branch_dense` | `result-mismatch` | `default skip (0 sites)` | `ok` | no | `0` | `1.017x` |
| `bpf_call_chain` | `result-mismatch` | `wide@11,15` | `ok` | yes | `2` | `1.109x` |
| `bounds_ladder` | `VM crash` | `wide@10,23` | `ok` | yes | `2` | `0.889x` |
| `mixed_alu_mem` | `VM crash` | `wide@10 + extract@73` | `ok` | yes | `2` | `1.023x` |

- Bottom line: the previous `6` mismatch/crash benchmarks are all now valid in the authoritative run. Three (`binary_search`, `switch_dispatch`, `branch_dense`) recover by fail-closing to zero sites; three (`bpf_call_chain`, `bounds_ladder`, `mixed_alu_mem`) recover with retained site-positive policies.
- `bounds_ladder` is the only one of the six that remains a regression after recovery (`0.889x`), but it is now a measured regression rather than a VM crash.

## Actually Applied Rows

| Benchmark | Family | Sites | Stock median | Recompile median | Stock / recompile | Status |
| --- | --- | ---: | ---: | ---: | ---: | --- |
| `cmov_dense` | `select-diamond` | `26` | `75 ns` | `61 ns` | `1.230x` | `win` |
| `memcmp_prefix_64` | `byte-compare` | `3` | `131.5 ns` | `107 ns` | `1.229x` | `win` |
| `bpf_call_chain` | `bpf-local-call` | `2` | `522 ns` | `470.5 ns` | `1.109x` | `win` |
| `log2_fold` | `log2-fold` | `3` | `358.5 ns` | `344 ns` | `1.042x` | `win` |
| `mixed_alu_mem` | `mixed-alu-mem` | `2` | `896.5 ns` | `876.5 ns` | `1.023x` | `win` |
| `cmov_select` | `select-diamond` | `1` | `631 ns` | `647.5 ns` | `0.975x` | `loss` |
| `large_mixed_500` | `large-mixed` | `3` | `613 ns` | `647 ns` | `0.947x` | `loss` |
| `bounds_ladder` | `bounds-density` | `2` | `208 ns` | `234 ns` | `0.889x` | `loss` |

## Per-Benchmark Table

| Benchmark | Family | Policy mode | Applied | Sites | Stock median | Recompile median | Stock / recompile | Status |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `simple` | `baseline` | `none->stock` | no | `0` | `11 ns` | `11 ns` | `1.000x` | `tie` |
| `simple_packet` | `baseline` | `none->stock` | no | `0` | `11 ns` | `11 ns` | `1.000x` | `tie` |
| `memory_pair_sum` | `baseline` | `file->skip` | no | `0` | `13 ns` | `13.5 ns` | `0.963x` | `loss` |
| `bitcount` | `popcount` | `file->skip` | no | `0` | `4.511 us` | `4.548 us` | `0.992x` | `loss` |
| `log2_fold` | `log2-fold` | `file->apply` | yes | `3` | `358.5 ns` | `344 ns` | `1.042x` | `win` |
| `dep_chain_short` | `dep-chain` | `none->stock` | no | `0` | `207.5 ns` | `201.5 ns` | `1.030x` | `win` |
| `dep_chain_long` | `dep-chain` | `file->skip` | no | `0` | `557.5 ns` | `569.5 ns` | `0.979x` | `loss` |
| `binary_search` | `search` | `file->skip` | no | `0` | `625 ns` | `634 ns` | `0.986x` | `loss` |
| `branch_layout` | `branch-skew` | `none->stock` | no | `0` | `639.5 ns` | `636.5 ns` | `1.005x` | `win` |
| `switch_dispatch` | `switch-dispatch` | `file->skip` | no | `0` | `350.5 ns` | `326 ns` | `1.075x` | `win` |
| `branch_dense` | `branch-density` | `file->skip` | no | `0` | `558 ns` | `548.5 ns` | `1.017x` | `win` |
| `cmov_select` | `select-diamond` | `file->apply` | yes | `1` | `631 ns` | `647.5 ns` | `0.975x` | `loss` |
| `cmov_dense` | `select-diamond` | `file->apply` | yes | `26` | `75 ns` | `61 ns` | `1.230x` | `win` |
| `checksum` | `reduction` | `file->skip` | no | `0` | `17.765 us` | `17.746 us` | `1.001x` | `win` |
| `load_word32` | `load-width` | `none->stock` | no | `0` | `133.5 ns` | `120.5 ns` | `1.108x` | `win` |
| `load_byte` | `load-width` | `file->skip` | no | `0` | `313 ns` | `298.5 ns` | `1.049x` | `win` |
| `load_byte_recompose` | `causal-isolation` | `file->skip` | no | `0` | `242 ns` | `243 ns` | `0.996x` | `loss` |
| `load_native_u64` | `causal-isolation` | `none->stock` | no | `0` | `110 ns` | `99 ns` | `1.111x` | `win` |
| `packet_parse` | `parser` | `file->skip` | no | `0` | `114.5 ns` | `113 ns` | `1.013x` | `win` |
| `bounds_ladder` | `bounds-density` | `file->apply` | yes | `2` | `208 ns` | `234 ns` | `0.889x` | `loss` |
| `bounds_check_heavy` | `bounds-style` | `none->stock` | no | `0` | `274 ns` | `307 ns` | `0.893x` | `loss` |
| `stride_load_4` | `stride-load` | `none->stock` | no | `0` | `293 ns` | `293 ns` | `1.000x` | `tie` |
| `stride_load_16` | `stride-load` | `none->stock` | no | `0` | `278 ns` | `260 ns` | `1.069x` | `win` |
| `mixed_alu_mem` | `mixed-alu-mem` | `file->apply` | yes | `2` | `896.5 ns` | `876.5 ns` | `1.023x` | `win` |
| `spill_pressure` | `spill-pressure` | `none->stock` | no | `0` | `396.5 ns` | `416.5 ns` | `0.952x` | `loss` |
| `multi_acc_4` | `multi-acc` | `none->stock` | no | `0` | `312.5 ns` | `322 ns` | `0.970x` | `loss` |
| `multi_acc_8` | `multi-acc` | `none->stock` | no | `0` | `594 ns` | `580.5 ns` | `1.023x` | `win` |
| `fibonacci_iter` | `recurrence` | `file->skip` | no | `0` | `989.5 ns` | `991 ns` | `0.998x` | `loss` |
| `fibonacci_iter_packet` | `recurrence` | `none->stock` | no | `0` | `956 ns` | `928.5 ns` | `1.030x` | `win` |
| `fixed_loop_small` | `fixed-loop` | `none->stock` | no | `0` | `116 ns` | `126.5 ns` | `0.917x` | `loss` |
| `fixed_loop_large` | `fixed-loop` | `none->stock` | no | `0` | `1.526 us` | `1.510 us` | `1.011x` | `win` |
| `nested_loop_2` | `nested-loop` | `file->skip` | no | `0` | `607 ns` | `588.5 ns` | `1.031x` | `win` |
| `nested_loop_3` | `nested-loop` | `file->skip` | no | `0` | `806.5 ns` | `856 ns` | `0.942x` | `loss` |
| `code_clone_2` | `code-clone` | `none->stock` | no | `0` | `405 ns` | `412.5 ns` | `0.982x` | `loss` |
| `code_clone_8` | `code-clone` | `none->stock` | no | `0` | `1.526 us` | `1.487 us` | `1.026x` | `win` |
| `large_mixed_500` | `large-mixed` | `file->apply` | yes | `3` | `613 ns` | `647 ns` | `0.947x` | `loss` |
| `large_mixed_1000` | `large-mixed` | `none->stock` | no | `0` | `1.178 us` | `1.194 us` | `0.987x` | `loss` |
| `bpf_call_chain` | `bpf-local-call` | `file->apply` | yes | `2` | `522 ns` | `470.5 ns` | `1.109x` | `win` |
| `memcmp_prefix_64` | `byte-compare` | `file->apply` | yes | `3` | `131.5 ns` | `107 ns` | `1.229x` | `win` |
| `packet_parse_vlans_tcpopts` | `parser` | `none->stock` | no | `0` | `27 ns` | `27 ns` | `1.000x` | `tie` |
| `local_call_fanout` | `bpf-local-call` | `none->stock` | no | `0` | `153 ns` | `145 ns` | `1.055x` | `win` |
| `packet_rss_hash` | `packet-hash` | `none->stock` | no | `0` | `21 ns` | `21 ns` | `1.000x` | `tie` |
| `imm64_storm` | `immediate-stress` | `none->stock` | no | `0` | `233 ns` | `224 ns` | `1.040x` | `win` |
| `alu32_64_pingpong` | `mixed-width` | `none->stock` | no | `0` | `533.5 ns` | `529 ns` | `1.009x` | `win` |
| `branch_fanout_32` | `branch-fanout` | `file->skip` | no | `0` | `395 ns` | `425 ns` | `0.929x` | `loss` |
| `deep_guard_tree_8` | `deep-guards` | `none->stock` | no | `0` | `120 ns` | `118.5 ns` | `1.013x` | `win` |
| `mega_basic_block_2048` | `mega-block` | `none->stock` | no | `0` | `984.5 ns` | `994 ns` | `0.990x` | `loss` |
| `rotate64_hash` | `rotate-hash` | `none->stock` | no | `0` | `95 ns` | `70 ns` | `1.357x` | `win` |
| `packet_redundant_bounds` | `bounds-density` | `none->stock` | no | `0` | `159 ns` | `180 ns` | `0.883x` | `loss` |
| `const_fold_chain` | `const-fold` | `none->stock` | no | `0` | `396.5 ns` | `325 ns` | `1.220x` | `win` |
| `struct_field_cluster` | `field-access` | `none->stock` | no | `0` | `97 ns` | `78 ns` | `1.244x` | `win` |
| `bitfield_extract` | `bitfield-extract` | `none->stock` | no | `0` | `297 ns` | `279 ns` | `1.065x` | `win` |
| `smallmul_strength_reduce` | `strength-reduce` | `file->skip` | no | `0` | `353 ns` | `449 ns` | `0.786x` | `loss` |
| `tc_bitcount` | `popcount` | `file->skip` | no | `0` | `4.721 us` | `4.529 us` | `1.042x` | `win` |
| `tc_checksum` | `reduction` | `none->stock` | no | `0` | `17.761 us` | `17.753 us` | `1.000x` | `win` |
| `cgroup_hash_chain` | `hash-chain` | `none->stock` | no | `0` | `309 ns` | `316 ns` | `0.978x` | `loss` |
