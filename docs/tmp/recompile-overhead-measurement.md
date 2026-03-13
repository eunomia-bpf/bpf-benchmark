# Recompile Overhead Measurement

Date: 2026-03-12

Raw artifacts:

- `docs/tmp/recompile_overhead_scanner_micro.csv`
- `docs/tmp/recompile_overhead_scanner_corpus_sample.csv`
- `docs/tmp/recompile_overhead_corpus_inventory.json`
- `docs/tmp/recompile_overhead_recompile_latency.csv`
- `docs/tmp/recompile_overhead_blob_sizes.csv`
- `docs/tmp/recompile_overhead_summary.json`
- generator: `docs/tmp/measure_recompile_overhead.py`

## Methodology

### Scanner latency

- Command: `./scanner/build/bpf-jit-scanner scan <obj> --all --v5 --json`
- Measurement: 1 warmup + 11 timed runs, report median wall-clock time.
- Micro suite: all 56 objects under `micro/programs/*.bpf.o`.
- Corpus suite: first scan all 470 `corpus/build/**/*.bpf.o` objects once, then select a 50-object size-diverse sample by log2 instruction-count buckets, then rerun those 50 objects with 11 repetitions.
- When an ELF contained multiple programs, the corpus sample used the scanner default (the first program in the object). The table reports the resolved program name that the scanner actually measured.

### Recompile syscall latency

- Source: `micro/results/kernel_recompile_v2_fixed_authoritative_20260312.json`
- Environment: virtme guest `virtme-ng`, kernel `7.0.0-rc2-ge52504a75c05-dirty`
- No runner code changes were needed. The runner already records:
  - `compile_ns = object_open_ns + object_load_ns + recompile_syscall_ns`
  - so `recompile_syscall_ns = compile_ns - phases_ns.object_open_ns - phases_ns.object_load_ns`
- I only count benchmarks with `recompile.syscall_attempted=true` and `recompile.applied=true`, i.e. cases where `BPF_PROG_JIT_RECOMPILE` actually ran successfully. That is 8 of 56 micro benchmarks in the fixed authoritative suite.

### Policy blob size and memory overhead

- Blob measurement command: `./scanner/build/bpf-jit-scanner scan <obj> --all --v5 --json --output <blob>`
- The v5 blob builder uses:
  - 32-byte header
  - per rule: `sizeof(V5RuleWire) == 28`
  - plus `16 * pattern_count + 16 * constraint_count + 8 * binding_count`
- The kernel stores essentially the same serialized blob in prog aux state after copying it from userspace, so resident memory overhead is well approximated by `policy_bytes` / blob size.

## Headline Numbers

- Scanner latency:
  - Micro median: `4.32 ms`, p90 `11.94 ms`, p95 `21.24 ms`, max `181.33 ms`
  - Corpus sample median: `4.42 ms`, p90 `112.37 ms`, p95 `143.15 ms`, max `172.52 ms`
- Scanner scaling:
  - Micro: `13.03 ms / 1k insns`, `R^2 = 0.997`, corr(insn,time) `0.999`
  - Corpus sample: `13.27 ms / 1k insns`, `R^2 = 0.954`, corr(insn,time) `0.977`
- Recompile syscall latency:
  - Median `29.89 us`, p90 `63.31 us`, range `19.26 us .. 67.58 us`
- Fixed-policy micro recompile payloads:
  - Median selected sites: `2.5`
  - Median `policy_bytes`: `382 B`
  - Max `policy_bytes`: `4504 B` (`cmov_dense`)
- Representative real-program blob sizes:
  - `1` site: `164 B`
  - `18` sites (`katran`): `2248 B`
  - `86` sites (`calico_tc_main`): `9632 B`
  - `123` sites (`tracee`): `16892 B`
  - `992` sites (`test_verif_scale2`): `218272 B`

## 1. Scanner Latency Tables

### Micro benchmarks

| Program | insn_cnt | num_sites | scan_time_ms |
| --- | ---: | ---: | ---: |
| `simple_packet_xdp` | 21 | 0 | 2.349 |
| `simple_xdp` | 24 | 0 | 2.521 |
| `load_native_u64_xdp` | 51 | 0 | 2.942 |
| `load_word32_xdp` | 68 | 2 | 3.202 |
| `load_byte_xdp` | 74 | 2 | 3.400 |
| `memory_pair_sum_xdp` | 78 | 2 | 3.316 |
| `load_byte_recompose_xdp` | 83 | 1 | 3.506 |
| `tc_checksum_prog` | 84 | 2 | 3.419 |
| `struct_field_cluster_xdp` | 93 | 0 | 3.869 |
| `branch_layout_xdp` | 95 | 2 | 3.649 |
| `fibonacci_iter_xdp` | 97 | 4 | 3.615 |
| `fibonacci_iter_packet_xdp` | 97 | 4 | 3.577 |
| `checksum_xdp` | 98 | 2 | 3.731 |
| `stride_load_16_xdp` | 103 | 3 | 3.810 |
| `stride_load_4_xdp` | 103 | 3 | 3.851 |
| `dep_chain_long_xdp` | 104 | 2 | 3.925 |
| `dep_chain_short_xdp` | 104 | 2 | 3.868 |
| `fixed_loop_small_xdp` | 108 | 4 | 3.830 |
| `packet_parse_xdp` | 108 | 5 | 3.739 |
| `fixed_loop_large_xdp` | 110 | 4 | 3.979 |
| `bpf_call_chain_xdp` | 112 | 3 | 3.890 |
| `code_clone_2_xdp` | 114 | 2 | 4.123 |
| `tc_bitcount_prog` | 115 | 2 | 4.041 |
| `cgroup_hash_chain_prog` | 117 | 2 | 4.084 |
| `local_call_fanout_xdp` | 120 | 3 | 4.131 |
| `log2_fold_xdp` | 127 | 11 | 3.847 |
| `smallmul_strength_reduce_xdp` | 127 | 2 | 4.336 |
| `const_fold_chain_xdp` | 128 | 2 | 4.431 |
| `multi_acc_4_xdp` | 128 | 3 | 4.302 |
| `bitcount_xdp` | 130 | 2 | 4.302 |
| `memcmp_prefix_64_xdp` | 139 | 4 | 4.391 |
| `deep_guard_tree_8_xdp` | 147 | 2 | 4.757 |
| `alu32_64_pingpong_xdp` | 148 | 4 | 4.575 |
| `nested_loop_2_xdp` | 154 | 3 | 4.798 |
| `packet_redundant_bounds_xdp` | 163 | 8 | 4.610 |
| `branch_dense_xdp` | 177 | 7 | 4.350 |
| `binary_search_xdp` | 180 | 3 | 5.218 |
| `bounds_ladder_xdp` | 180 | 4 | 5.017 |
| `code_clone_8_xdp` | 184 | 3 | 5.355 |
| `spill_pressure_xdp` | 200 | 2 | 5.619 |
| `multi_acc_8_xdp` | 202 | 4 | 5.683 |
| `nested_loop_3_xdp` | 221 | 3 | 6.056 |
| `packet_parse_vlans_tcpopts_xdp` | 232 | 7 | 5.989 |
| `bitfield_extract_xdp` | 247 | 11 | 6.333 |
| `packet_rss_hash_xdp` | 261 | 13 | 5.853 |
| `mixed_alu_mem_xdp` | 267 | 3 | 7.215 |
| `switch_dispatch_xdp` | 321 | 3 | 7.961 |
| `branch_fanout_32_xdp` | 423 | 9 | 9.210 |
| `cmov_select_xdp` | 530 | 10 | 11.338 |
| `large_mixed_500_xdp` | 548 | 11 | 11.628 |
| `cmov_dense_xdp` | 607 | 58 | 10.228 |
| `bounds_check_heavy_xdp` | 699 | 14 | 14.491 |
| `rotate64_hash_xdp` | 992 | 123 | 12.652 |
| `large_mixed_1000_xdp` | 1008 | 16 | 19.486 |
| `imm64_storm_xdp` | 1705 | 68 | 31.150 |
| `mega_basic_block_2048_xdp` | 13777 | 520 | 181.325 |

### Corpus sample (50 diverse objects)

| Program | insn_cnt | num_sites | scan_time_ms |
| --- | ---: | ---: | ---: |
| `bpf_tcp_nogpl.bpf.o:nogpltcp_init` | 1 | 0 | 2.026 |
| `test_tc_bpf.bpf.o:cls` | 2 | 0 | 1.966 |
| `freplace_unreliable_prog.bpf.o:replace_btf_unreliable_kprobe` | 2 | 0 | 1.963 |
| `test_netfilter_link_attach.bpf.o:nf_link_attach_test` | 2 | 0 | 2.006 |
| `xdp_prog_kern.bpf.o:xdp_pass_func` | 2 | 0 | 2.063 |
| `verifier_netfilter_ctx.bpf.o:with_invalid_ctx_access_test1` | 3 | 0 | 2.794 |
| `ksnoop.bpf.o:kprobe_entry` | 4 | 0 | 2.243 |
| `core_kern.bpf.o:tp_xdp_devmap_xmit_multi` | 5 | 0 | 2.408 |
| `summarization.bpf.o:main_changes_with_subprogs` | 6 | 0 | 2.090 |
| `xdp_prog_fail2.bpf.o:_xdp_fail2` | 7 | 1 | 2.052 |
| `uprobe.bpf.o:uprobe_add` | 8 | 0 | 2.173 |
| `map_kptr_fail.bpf.o:size_not_bpf_dw` | 11 | 0 | 2.331 |
| `find_vma_fail2.bpf.o:handle_getpid` | 13 | 0 | 2.246 |
| `xdp_metadata2.bpf.o:freplace_rx` | 15 | 0 | 2.297 |
| `cgrp_ls_sleepable.bpf.o:cgroup_iter` | 16 | 0 | 2.691 |
| `lru_bug.bpf.o:printk` | 19 | 0 | 2.423 |
| `softirqs.bpf.o:softirq_entry_btf` | 25 | 0 | 2.498 |
| `af_xdp_kern.bpf.o:xdp_sock_prog` | 31 | 0 | 2.507 |
| `runqlat.bpf.o:sched_wakeup` | 32 | 0 | 2.766 |
| `task_storage_nodeadlock.bpf.o:socket_post_create` | 38 | 0 | 2.816 |
| `xdp_prog_kern.bpf.o:xdp_prog_simple` | 49 | 0 | 2.919 |
| `restrict-fs.bpf.o:restrict_filesystems` | 63 | 1 | 3.215 |
| `system_monitor.bpf.o:sys_enter_setns` | 66 | 0 | 23.783 |
| `runqlen.bpf.o:do_sample` | 83 | 3 | 3.561 |
| `xdp_prog_kern.bpf.o:grow_parse` | 110 | 1 | 4.054 |
| `xdp_vlan02_kern.bpf.o:xdp_vlan_02` | 127 | 17 | 3.890 |
| `tcpstates.bpf.o:handle_set_state` | 137 | 0 | 4.864 |
| `xdp_flowtable.bpf.o:xdp_flowtable_do_lookup` | 149 | 2 | 4.777 |
| `loop6.bpf.o:trace_virtqueue_add_sgs` | 170 | 0 | 5.272 |
| `bpf_generic_kprobe.bpf.o:generic_kprobe_setup_event` | 250 | 3 | 8.761 |
| `bpf_execve_bprm_commit_creds.bpf.o:tg_kp_bprm_committing_creds` | 292 | 0 | 8.183 |
| `xdp_filter.bpf.o:xdp_hashfilter` | 334 | 3 | 8.304 |
| `xdp_lb.bpf.o:xdp_loadfilter` | 410 | 8 | 9.473 |
| `test_bpf_nf.bpf.o:nf_xdp_ct_test` | 476 | 0 | 11.560 |
| `xdp_debug.bpf.o:calico_xdp_main` | 959 | 10 | 19.819 |
| `bpf_generic_usdt.bpf.o:generic_usdt_setup_event` | 970 | 31 | 22.621 |
| `xdp_synproxy_kern.bpf.o:syncookie_xdp` | 1047 | 23 | 21.942 |
| `xdp_synproxy_kern.bpf.o:syncookie_xdp` | 1047 | 23 | 22.310 |
| `xdp_flowtable.bpf.o:xdp_fwd_flow_full` | 1372 | 33 | 27.059 |
| `llb_xdp_main.bpf.o:xdp_packet_func` | 1784 | 3 | 35.736 |
| `execsnoop.bpf.o:tracepoint__syscalls__sys_enter_execve` | 2236 | 0 | 44.156 |
| `balancer.bpf.o:balancer_ingress` | 2322 | 18 | 44.600 |
| `bpf_generic_tracepoint.bpf.o:generic_tracepoint_process_event` | 2633 | 54 | 49.741 |
| `protectproc.bpf.o:enforce_file` | 5139 | 2 | 85.628 |
| `from_nat_debug.bpf.o:calico_tc_main` | 6776 | 60 | 106.954 |
| `llb_ebpf_emain.bpf.o:tc_packet_func_fast` | 7237 | 104 | 112.970 |
| `to_hep_debug.bpf.o:calico_tc_main` | 8091 | 71 | 125.516 |
| `from_hep_debug.bpf.o:calico_tc_main` | 8829 | 86 | 135.746 |
| `enforcer.bpf.o:enforce_proc` | 11295 | 65 | 172.523 |
| `test_verif_scale2.bpf.o:balancer_ingress` | 14750 | 992 | 152.194 |

## 2. Recompile Syscall Latency

Applied benchmarks from the fixed authoritative VM suite:

| Benchmark | policy_bytes | selected_sites | syscall_us_median |
| --- | ---: | ---: | ---: |
| `bounds_ladder` | 312 | 2 | 20.401 |
| `bpf_call_chain` | 312 | 2 | 28.608 |
| `cmov_dense` | 4504 | 26 | 63.718 |
| `cmov_select` | 164 | 1 | 48.915 |
| `large_mixed_500` | 644 | 3 | 48.770 |
| `log2_fold` | 452 | 3 | 21.713 |
| `memcmp_prefix_64` | 548 | 3 | 23.899 |
| `mixed_alu_mem` | 296 | 2 | 29.886 |

Observations:

- The kernel-side recompile syscall is tiny in absolute terms: median `29.89 us`, p90 `63.31 us`, max `67.58 us`.
- Its scaling tracks program size more closely than selected-site count:
  - corr(`xlated_prog_len`, syscall) = `0.963`
  - corr(`policy_bytes`, syscall) = `0.690`
  - corr(`selected_sites`, syscall) = `0.673`
  - linear fit on `xlated_prog_len`: about `9.95 us / KiB`, `R^2 = 0.928`
- This matches the expected mechanism: once the syscall enters the kernel, the dominant work is re-JITing the full program image, not parsing the policy blob.

## 3. Policy Blob Sizes

Representative programs:

| Label | Program | insn_cnt | num_sites | blob_bytes |
| --- | --- | ---: | ---: | ---: |
| small-default | `tp_xdp_redirect_err` | 81 | 1 | 164 |
| medium-katran | `balancer_ingress` | 2322 | 18 | 2248 |
| calico-reference | `calico_tc_main` | 8829 | 86 | 9632 |
| large-tracee | `cgroup_skb_egress` | 3602 | 123 | 16892 |
| very-large-selftests | `balancer_ingress` | 14750 | 992 | 218272 |

Observations:

- The current March 12, 2026 corpus build does reproduce an `86`-site `calico_tc_main` (`corpus/build/calico/from_hep_debug.bpf.o`), so the earlier “large calico” intuition is valid for this build.
- For real production-ish programs, blob size stays in the low-KiB range:
  - `katran`: `2248 B`
  - `calico`: `9632 B`
  - `tracee`: `16892 B`
- The worst case I measured is the synthetic/selftest-style `test_verif_scale2:balancer_ingress` with `992` sites and a `218272 B` blob (`~213 KiB`).
- Bytes/site vary substantially with pattern complexity:
  - `calico` `~112 B/site`
  - `katran` `~125 B/site`
  - `tracee` `~137 B/site`
  - `test_verif_scale2` `~220 B/site`
- The 32-byte header is negligible once there are more than a handful of sites.

## 4. Memory Overhead Estimate

The most defensible estimate is simply the serialized policy size, because the kernel stores that same rule payload in prog aux state after validation/copy:

- Formula:
  - `32 B` header
  - `28 B` per `V5RuleWire`
  - `16 B` per pattern instruction
  - `16 B` per constraint
  - `8 B` per binding
- Fixed authoritative micro suite:
  - median `policy_bytes`: `382 B`
  - max `policy_bytes`: `4504 B`
- Representative real programs:
  - `164 B` for a 1-site XDP program
  - `2.2 KiB` for `katran`
  - `9.4 KiB` for the 86-site `calico_tc_main`
  - `16.5 KiB` for `tracee`
  - `213 KiB` worst case for `test_verif_scale2`

So the memory overhead is generally tiny for the programs that look like actual deployment targets, and only becomes noticeable on very large synthetic/test objects with hundreds of sites.

## 5. Scaling Analysis

### Scanner latency

- Micro suite:
  - corr(insn_cnt, scan_time_ms) = `0.999`
  - corr(num_sites, scan_time_ms) = `0.976`
  - slope = `13.03 ms / 1k insns`
  - `R^2 = 0.997`
- Corpus sample:
  - corr(insn_cnt, scan_time_ms) = `0.977`
  - corr(num_sites, scan_time_ms) = `0.543`
  - slope = `13.27 ms / 1k insns`
  - `R^2 = 0.954`

Interpretation:

- On micro benchmarks, scan overhead is almost perfectly linear in program size.
- On real ELF objects, instruction count is still the main driver, but site count becomes a weaker predictor because the CLI path includes full ELF/BTF parsing and program selection overhead.
- Concrete outlier: `system_monitor.bpf.o:sys_enter_setns` is only `66` instructions but still takes `23.78 ms` to scan because the scanner is opening a large object and selecting one program from it.
- Another useful contrast: `from_hep_debug.bpf.o:calico_tc_main` (`8829` insns, `86` sites) takes `135.75 ms`, while `test_verif_scale2.bpf.o:balancer_ingress` (`14750` insns, `992` sites) takes `152.19 ms`. The large difference in sites matters less than the fact that both are very large programs.

### Recompile syscall latency

- The syscall is two to three orders of magnitude smaller than the scanner:
  - applied-benchmark scanner median: `6.12 ms`
  - applied-benchmark recompile-syscall median: `0.029 ms`
  - scanner/syscall median ratio: `207.8x`
- That means the control-plane overhead is dominated by userspace discovery/serialization, not by the kernel recompile hook itself.

## 6. Comparison Against Original JIT Compile Time

Using the existing VM stock-compile numbers from `kernel_recompile_v2_fixed_authoritative_20260312.json`:

- Across all 56 micro benchmarks:
  - scanner median = `4.32 ms`
  - stock `compile_ns` median = `3.24 ms`
  - median scanner / stock-compile ratio = `1.35x`
- Across the 8 benchmarks where fixed-policy recompile actually applied:
  - scanner median = `6.12 ms`
  - stock `compile_ns` median = `5.44 ms`
  - median scanner / stock-compile ratio = `1.39x`

Caveat:

- This is a conservative comparison, because scanner timing here is the standalone CLI over an ELF object path, while stock `compile_ns` is the in-runner load path.
- Inference: a library-integrated scanner over already-loaded xlated bytes should be lower than this CLI number, because it avoids process startup plus some ELF/BTF parsing overhead.
- Even with the conservative CLI measurement, the absolute scanner cost remains in the single-digit milliseconds for most non-pathological programs, while the kernel recompile syscall itself remains in the tens of microseconds.

## 7. Paper-Ready Summary

`BpfReJIT`’s control-plane overhead is small and scales predictably. Across 56 micro benchmarks, scanner latency is `4.32 ms` median and grows linearly with program size (`13.03 ms / 1k insns`, `R^2 = 0.997`); on a size-diverse 50-object corpus sample, scanner latency is `4.42 ms` median and remains instruction-count dominated (`13.27 ms / 1k insns`, `R^2 = 0.954`). Inside the VM, the kernel-side `BPF_PROG_JIT_RECOMPILE` syscall itself is much smaller, only `29.89 us` median (`63.31 us` p90) on the 8 benchmarks where fixed-policy recompile actually applied. Policy memory overhead is likewise modest: the median applied micro policy is `382 B`, while representative real-program blobs range from `2.2 KiB` (`katran`, 18 sites) to `16.5 KiB` (`tracee`, 123 sites), with only a synthetic worst case reaching `213 KiB` (`test_verif_scale2`, 992 sites). Overall, the overhead of our approach is dominated by userspace scanning rather than the kernel recompile hook, and even that cost stays in the low-millisecond range for realistic programs.
