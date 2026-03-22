# Corpus 0.983x Root Cause Analysis (2026-03-20)

## Inputs

- `corpus/results/corpus_authoritative_20260320.json`
- `docs/tmp/full_rerun_authoritative_20260320.md` (corpus section)
- `micro/runner/src/kernel_runner.cpp`
- `micro/runner/src/common.cpp`

## Executive Summary

- Overall same-image corpus geomean is `0.982603x` over `93` measured pairs; authoritative report rounds this to `0.982603x`.
- `57/150` successful `v5_run` rows are missing `stock_exec_ns` because the runner only measures a paired stock pass when `measure_same_image_pair = recompile.requested && !options.compile_only` (`micro/runner/src/kernel_runner.cpp:1333-1334`). The JSON serializer only emits `stock_exec_ns` when the optional is populated (`micro/runner/src/common.cpp:526-528`).
- Every one of those 57 successful missing rows was `policy_mode=stock` with no `policy_path`, so no recompile path was requested. This is not a serialization bug; it is the current gating behavior.
- Applied-only is genuinely weak: `0.946786x` across `26` applied rows, with `16` regressions, `5` ties, and `5` wins.
- The worst applied regression is `xdp-tutorial/packet03-redirecting/xdp_redirect_func`, which slowed from `12ns` to `33ns` (`0.363636x`) after one applied `wide` site.
- `linux-selftests` and `xdp-tutorial` negatives are mostly ultra-short runtimes. `9/10` linux-selftests regressions and `3/3` xdp-tutorial regressions are `<20ns` baseline programs, where `1-2ns` shifts dominate the ratio.
- Same-image is not fully neutral for non-applied rows: the non-applied geomean is `0.996864x`, but `14` rows deviate by more than `20%` even though no recompile syscall was attempted. All of those rows are `io_mode=packet`.
- The runner resets only output buffers, `ctx_out`, and `result_map` (`micro/runner/src/kernel_runner.cpp:227-257`). It does not reset arbitrary mutable program maps, so packet-mode/stateful programs can take a different path in the second half of the pair even with identical code.

## 1. `stock_exec_ns` Coverage Analysis

### Runner Root Cause

- `measure_same_image_pair` is gated by `recompile.requested && !options.compile_only` (`micro/runner/src/kernel_runner.cpp:1333-1334`).
- `stock_exec_ns` is only populated inside that branch, immediately before `apply_recompile_policy()` (`micro/runner/src/kernel_runner.cpp:1515-1521`).
- `stock_exec_ns` is serialized only if the optional has a value (`micro/runner/src/common.cpp:526-528`).

Conclusion: the `57` missing successful rows are missing because the runner never entered the same-image path. This is a control-flow/design issue, not a JSON field-dropping bug.

### Coverage Numbers

| Metric | Value |
| --- | ---: |
| Successful `v5_run` rows | `150` |
| Successful rows with `stock_exec_ns` | `93` |
| Successful rows missing `stock_exec_ns` | `57` |
| Failed rows with no `v5_run` payload | `2` |
| Missing successful rows with `eligible_families=[]` | `43` |
| Missing successful rows with non-empty `eligible_families` | `14` |

All `57` successful missing rows share the same state:

- `policy_mode = stock`
- `policy_path = None`
- `requested_families_run = []`
- `v5_run.sample.recompile.requested = false`
- `v5_run.sample.recompile.mode = none`

Among those `57` rows, `14` still had eligible sites, so the issue is not “no opportunities existed”; it is “no recompile path was requested for those rows”. Eligible-family counts inside the missing set:

- `branch-flip`: `11` rows
- `cmov`: `2` rows
- `endian`: `2` rows
- `wide`: `1` rows

Source breakdown of the 57 successful missing rows:

- `calico`: `5` rows
- `katran`: `3` rows
- `linux-selftests`: `35` rows
- `xdp-tools`: `1` rows
- `xdp-tutorial`: `13` rows

### Full List Of The 57 Successful Rows Missing `stock_exec_ns`

#### calico

- `corpus/build/calico/xdp_debug.bpf.o:calico_xdp_accepted_entrypoint`  | eligible=`branch-flip`
- `corpus/build/calico/xdp_debug.bpf.o:calico_xdp_norm_pol_tail`  | eligible=`-`
- `corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_accepted_entrypoint`  | eligible=`branch-flip`
- `corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_drop`  | eligible=`branch-flip`
- `corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_norm_pol_tail`  | eligible=`-`

#### katran

- `corpus/build/katran/healthchecking_ipip.bpf.o:healthcheck_encap`  | eligible=`branch-flip`
- `corpus/build/katran/xdp_pktcntr.bpf.o:pktcntr`  | eligible=`branch-flip`
- `corpus/build/katran/xdp_root.bpf.o:xdp_root`  | eligible=`-`

#### linux-selftests

- `corpus/build/linux-selftests/test_tc_bpf.bpf.o:cls`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_ancestor.bpf.o:log_cgroup_id`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_skb_direct_packet_access.bpf.o:direct_packet_access`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/core_kern.bpf.o:balancer_ingress`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_array_map_elem.bpf.o:test_pkt_access`  | eligible=`cmov`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_hash_map_elem.bpf.o:test_pkt_access`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_hash_modify.bpf.o:test_pkt_access`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_multi_maps.bpf.o:test_pkt_access`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/netns_cookie_prog.bpf.o:get_netns_cookie_cgroup_skb`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/netns_cookie_prog.bpf.o:get_netns_cookie_tcx`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/prepare.bpf.o:program`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/priv_prog.bpf.o:xdp_prog1`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_AB`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_BA`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/skb_pkt_end.bpf.o:main_prog`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_changes`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_changes_with_subprogs`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_does_not_change`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_btf_skc_cls_ingress.bpf.o:cls_ingress`  | eligible=`endian`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ldsx_insn.bpf.o:_tc`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_skb_helpers.bpf.o:test_skb_helpers`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:decap_f`  | eligible=`cmov,wide,endian`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_verif_scale2.bpf.o:balancer_ingress`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:tc_count_pkts`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_count_pkts`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect_to_111`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect_to_222`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx2`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx3`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx5`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx6`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:unmodified_ctx_pointer_to_helper`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_mtu.bpf.o:tc_uninit_mtu`  | eligible=`-`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_metadata.bpf.o:redirect`  | eligible=`-`

#### xdp-tools

- `corpus/build/xdp-tools/xdpsock.bpf.o:xdp_sock_prog`  | eligible=`-`

#### xdp-tutorial

- `corpus/build/xdp-tutorial/advanced03-AF_XDP/af_xdp_kern.bpf.o:xdp_sock_prog`  | eligible=`branch-flip`
- `corpus/build/xdp-tutorial/basic01-xdp-pass/xdp_pass_kern.bpf.o:xdp_prog_simple`  | eligible=`-`
- `corpus/build/xdp-tutorial/basic02-prog-by-name/xdp_prog_kern.bpf.o:xdp_drop_func`  | eligible=`-`
- `corpus/build/xdp-tutorial/basic02-prog-by-name/xdp_prog_kern.bpf.o:xdp_pass_func`  | eligible=`-`
- `corpus/build/xdp-tutorial/basic03-map-counter/xdp_prog_kern.bpf.o:xdp_stats1_func`  | eligible=`branch-flip`
- `corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_abort_func`  | eligible=`branch-flip`
- `corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_drop_func`  | eligible=`branch-flip`
- `corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_pass_func`  | eligible=`branch-flip`
- `corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_port_rewrite_func`  | eligible=`-`
- `corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_pass_func`  | eligible=`-`
- `corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_router_func`  | eligible=`branch-flip`
- `corpus/build/xdp-tutorial/tracing01-xdp-simple/xdp_prog_kern.bpf.o:xdp_drop_func`  | eligible=`-`
- `corpus/build/xdp-tutorial/tracing03-xdp-debug-print/xdp_prog_kern.bpf.o:xdp_prog_simple`  | eligible=`-`

Failed rows not counted in the `57` list above:

- `corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies`  | record_error=`Segmentation fault (exit=139)`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_held_lock_max`  | record_error=`TypeError: sequence item 0: expected str instance, bytes found (exit=1)`

## 2. Applied-Only `0.946786x`: Why The 26 Applied Programs Average Negative

### High-Level Result

- Applied geomean: `0.946786x` over `26` rows.
- Regressions: `16` / `26`.
- Family-set breakdown: `wide+endian` = `12` rows at `0.924872x`; `endian` = `11` rows at `1.049081x`; `wide` = `3` rows at `0.713766x`.
- The drag is concentrated in two places:

1. `wide+endian` Calico packet programs: `12` applied rows, `10` regressions, geomean `0.924872x`.
2. One tiny `wide` XDP program: `xdp_redirect_func` (`12ns -> 33ns`, `0.363636x`).

### All 26 Applied Programs

| Source | Program | Families | Applied Sites | Eligible Sites | Stock ns | Recompile ns | Delta ns | Ratio |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `xdp-tutorial` | `corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_func` | `wide` | `1` | `4` | `12` | `33` | `-21` | `0.363636x` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_sit_none` | `endian` | `2` | `4` | `4` | `5` | `-1` | `0.800000x` |
| `calico` | `corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat` | `wide, endian` | `3` | `40` | `96` | `115` | `-19` | `0.834783x` |
| `calico` | `corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat` | `wide, endian` | `3` | `33` | `97` | `116` | `-19` | `0.836207x` |
| `calico` | `corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies` | `wide, endian` | `1` | `16` | `102` | `117` | `-15` | `0.871795x` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_vxlan_eth` | `endian` | `1` | `2` | `14` | `16` | `-2` | `0.875000x` |
| `calico` | `corpus/build/calico/to_nat_debug.bpf.o:calico_tc_host_ct_conflict` | `wide, endian` | `6` | `47` | `98` | `111` | `-13` | `0.882883x` |
| `real_world_code_size` | `corpus/build/real_world_code_size/libbpf-bootstrap/tc.bpf.o:tc_ingress` | `endian` | `1` | `1` | `110` | `124` | `-14` | `0.887097x` |
| `libbpf-bootstrap` | `corpus/build/libbpf-bootstrap/examples/c/tc.bpf.o:tc_ingress` | `endian` | `1` | `1` | `118` | `132` | `-14` | `0.893939x` |
| `tracee` | `corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress` | `wide, endian` | `4` | `132` | `24` | `26` | `-2` | `0.923077x` |
| `calico` | `corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint` | `endian` | `1` | `37` | `98` | `106` | `-8` | `0.924528x` |
| `calico` | `corpus/build/calico/to_hep_debug.bpf.o:calico_tc_host_ct_conflict` | `wide, endian` | `6` | `47` | `96` | `103` | `-7` | `0.932039x` |
| `calico` | `corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat` | `wide, endian` | `3` | `26` | `99` | `106` | `-7` | `0.933962x` |
| `calico` | `corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main` | `wide, endian` | `1` | `87` | `177` | `188` | `-11` | `0.941489x` |
| `calico` | `corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat` | `wide, endian` | `3` | `41` | `104` | `108` | `-4` | `0.962963x` |
| `calico` | `corpus/build/calico/to_nat_debug.bpf.o:calico_tc_main` | `wide, endian` | `1` | `76` | `106` | `109` | `-3` | `0.972477x` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_mpls` | `endian` | `1` | `2` | `14` | `14` | `+0` | `1.000000x` |
| `tracee` | `corpus/build/tracee/tracee.bpf.o:cgroup_skb_ingress` | `wide, endian` | `4` | `132` | `24` | `24` | `+0` | `1.000000x` |
| `xdp-tools` | `corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_full` | `endian` | `2` | `3` | `46` | `46` | `+0` | `1.000000x` |
| `xdp-tutorial` | `corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func` | `wide` | `1` | `3` | `10` | `10` | `+0` | `1.000000x` |
| `xdp-tutorial` | `corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_map_func` | `wide` | `1` | `4` | `19` | `19` | `+0` | `1.000000x` |
| `calico` | `corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint` | `endian` | `1` | `36` | `105` | `104` | `+1` | `1.009615x` |
| `calico` | `corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat` | `wide, endian` | `1` | `38` | `106` | `103` | `+3` | `1.029126x` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_none` | `endian` | `1` | `2` | `15` | `14` | `+1` | `1.071429x` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_eth` | `endian` | `1` | `2` | `14` | `13` | `+1` | `1.076923x` |
| `xdp-tools` | `corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct` | `endian` | `2` | `3` | `51` | `18` | `+33` | `2.833333x` |

### Interpretation

- This does **not** look like a pure I-cache flush artifact. The measured run is taken only after a post-recompile warmup loop (`micro/runner/src/kernel_runner.cpp:1517-1524`, default `warmup_repeat=5` from `micro/runner/include/micro_exec.hpp`).
- More importantly, large pair-to-pair deltas also appear on rows where **no recompile syscall was attempted at all**. That means the harness can drift even without any code-image change.
- The strongest evidence for a real policy problem, rather than only noise, is that applied `wide+endian` Calico rows are systematically negative even at `~100ns` scale. These are not all sub-20ns quantization artifacts.
- The strongest evidence for a real site-specific regression is `xdp_redirect_func`: sibling `wide`-applied XDP programs (`xdp_vlan_swap_func`, `xdp_redirect_map_func`) are neutral at `1.0x`, so the regression is not an unavoidable post-recompile constant overhead.

Bottom line: applied-only `0.946786x` is a mix of real negative policy picks (`wide`, especially inside Calico and `xdp_redirect_func`) plus harness contamination from packet-mode state carryover. It is not well explained by I-cache flush alone.

## 3. Per-Source Breakdown

### `xdp-tutorial` (`0.878507x`)

| Program | Applied? | Families | Stock ns | Recompile ns | Ratio | Comment |
| --- | ---: | --- | ---: | ---: | ---: | --- |
| `corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_func` | `yes` | `wide` | `12` | `33` | `0.363636x` | `sub-20ns` |
| `corpus/build/xdp-tutorial/packet-solutions/tc_reply_kern_02.bpf.o:_fix_port_egress` | `no` | `endian` | `4` | `5` | `0.800000x` | `sub-20ns` |
| `corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_parser_func` | `no` | `-` | `11` | `13` | `0.846154x` | `sub-20ns` |

- All `3` xdp-tutorial regressions are `<20ns` baseline programs.
- The source geomean is driven mostly by `xdp_redirect_func` (`12ns -> 33ns`, applied `wide`). The other two regressions are `4ns -> 5ns` and `11ns -> 13ns`, which are tiny in absolute terms.
- If you look only at `stock_exec_ns >= 20ns`, the remaining xdp-tutorial measured set is just one row (`xdp_sample_prog`) and it is positive at `1.640625x`.

### `linux-selftests` (`0.918463x`)

| Program | Applied? | Families | Stock ns | Recompile ns | Ratio | Comment |
| --- | ---: | --- | ---: | ---: | ---: | --- |
| `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_change_tail.bpf.o:change_tail` | `no` | `-` | `3` | `5` | `0.600000x` | `sub-20ns` |
| `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_eth` | `no` | `-` | `3` | `5` | `0.600000x` | `sub-20ns` |
| `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_none` | `no` | `-` | `3` | `5` | `0.600000x` | `sub-20ns` |
| `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_none` | `no` | `-` | `3` | `4` | `0.750000x` | `sub-20ns` |
| `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_eth` | `no` | `-` | `3` | `4` | `0.750000x` | `sub-20ns` |
| `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6vxlan_eth` | `no` | `-` | `3` | `4` | `0.750000x` | `sub-20ns` |
| `corpus/build/linux-selftests/test_tc_bpf.bpf.o:pkt_ptr` | `no` | `-` | `4` | `5` | `0.800000x` | `sub-20ns` |
| `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_sit_none` | `yes` | `endian` | `4` | `5` | `0.800000x` | `sub-20ns` |
| `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_vxlan_eth` | `yes` | `endian` | `14` | `16` | `0.875000x` | `sub-20ns` |
| `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test` | `no` | `-` | `2753` | `2815` | `0.977975x` | `>=20ns` |

- `9/10` linux-selftests regressions are `<20ns` baseline programs, mostly `3ns -> 4/5ns` tunnel helpers and one `4ns -> 5ns` `pkt_ptr` case.
- The only materially longer linux-selftests regression is `res_spin_lock_test` (`2753ns -> 2815ns`, `0.977975x`), which is mild.
- Excluding linux-selftests rows with `stock_exec_ns < 20ns` moves the **overall corpus** geomean from `0.982603x` to `1.008652x`.

### `calico` (`1.017423x`) Is Not Actually Clean

- Calico is positive on paper, but that number is dominated by a few large **non-applied** outliers:

- `corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint`: `729ns -> 118ns` = `6.177966x`, with `syscall_attempted=false`.
- `corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_main`: `17ns -> 6ns` = `2.833333x`, with `syscall_attempted=false`.
- `corpus/build/calico/xdp_debug.bpf.o:calico_xdp_drop`: `389ns -> 279ns` = `1.394265x`, with `syscall_attempted=false`.
- `corpus/build/calico/xdp_debug.bpf.o:calico_xdp_main`: `211ns -> 156ns` = `1.352564x`, with `syscall_attempted=false`.

- If those Calico non-applied `>20%` outliers are neutralized to `1.0x`, Calico drops from `1.017423x` to `0.952463x`.
- So “Calico is OK” is misleading. Its positive source geomean is being propped up by same-image instability on packet-mode, non-applied rows.

## 4. Same-Image Effectiveness On The 93 Rows With `stock_exec_ns`

### Non-Applied Rows: Is Same-Image Basically Working?

| Metric | Value |
| --- | ---: |
| Non-applied rows with `stock_exec_ns` | `67` |
| Geomean(`stock_exec_ns / exec_ns`) | `0.996864x` |
| Median ratio | `0.980952x` |
| Median absolute delta | `4ns` |
| 90th percentile absolute delta | `20ns` |
| Median absolute pct error | `0.076923` |
| Non-applied rows with `|ratio-1| > 20%` and `syscall_attempted=false` | `14` |

Interpretation:

- The **aggregate** non-applied geomean is close to neutral (`0.996864x`), so same-image is not completely broken.
- But it is also **not neutral enough to trust blindly**, because substantial drift appears even when the code image is unchanged.
- All rows with `stock_exec_ns` but `v5_run_applied=false` also have `recompile.requested=true` and `syscall_attempted=false`. In those rows, any speedup/regression must come from harness effects, not a JIT rewrite.
- The runner only resets `packet_out`, `ctx_out`, and `result_map`. It does not reset arbitrary program maps, counters, CT/NAT tables, or other mutable state (`micro/runner/src/kernel_runner.cpp:227-257`).
- Every `>20%` no-syscall outlier is `io_mode=packet`. That is consistent with packet-path state carryover, plus some very-short-runtime quantization noise.

### Worst Non-Applied No-Syscall Outliers

| Program | Source | Stock ns | Recompile ns | Ratio | Note |
| --- | --- | ---: | ---: | ---: | --- |
| `corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint` | `calico` | `729` | `118` | `6.177966x` | `stateful-packet suspect` |
| `corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_main` | `calico` | `17` | `6` | `2.833333x` | `sub-20ns, stateful-packet suspect` |
| `corpus/build/xdp-tutorial/tracing04-xdp-tcpdump/xdp_sample_pkts_kern.bpf.o:xdp_sample_prog` | `xdp-tutorial` | `210` | `128` | `1.640625x` | `-` |
| `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_change_tail.bpf.o:change_tail` | `linux-selftests` | `3` | `5` | `0.600000x` | `sub-20ns` |
| `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_eth` | `linux-selftests` | `3` | `5` | `0.600000x` | `sub-20ns` |
| `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_none` | `linux-selftests` | `3` | `5` | `0.600000x` | `sub-20ns` |
| `corpus/build/calico/xdp_debug.bpf.o:calico_xdp_drop` | `calico` | `389` | `279` | `1.394265x` | `stateful-packet suspect` |
| `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ipip6_none` | `linux-selftests` | `22` | `16` | `1.375000x` | `-` |
| `corpus/build/calico/xdp_debug.bpf.o:calico_xdp_main` | `calico` | `211` | `156` | `1.352564x` | `stateful-packet suspect` |
| `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6tnl_none` | `linux-selftests` | `4` | `3` | `1.333333x` | `sub-20ns` |
| `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/decap_sanity.bpf.o:decap_sanity` | `linux-selftests` | `5` | `4` | `1.250000x` | `sub-20ns` |
| `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_none` | `linux-selftests` | `3` | `4` | `0.750000x` | `sub-20ns` |
| `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_eth` | `linux-selftests` | `3` | `4` | `0.750000x` | `sub-20ns` |
| `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6vxlan_eth` | `linux-selftests` | `3` | `4` | `0.750000x` | `sub-20ns` |

## 5. Worst 20 Regressions (Measured Same-Image Pairs)

| Rank | Source | Program | Applied? | Families | Stock ns | Recompile ns | Delta ns | Ratio | Note |
| ---: | --- | --- | ---: | --- | ---: | ---: | ---: | ---: | --- |
| `1` | `xdp-tutorial` | `corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_func` | `yes` | `wide` | `12` | `33` | `-21` | `0.363636x` | `sub-20ns` |
| `2` | `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_change_tail.bpf.o:change_tail` | `no` | `-` | `3` | `5` | `-2` | `0.600000x` | `sub-20ns, no-syscall` |
| `3` | `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_eth` | `no` | `-` | `3` | `5` | `-2` | `0.600000x` | `sub-20ns, no-syscall` |
| `4` | `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_none` | `no` | `-` | `3` | `5` | `-2` | `0.600000x` | `sub-20ns, no-syscall` |
| `5` | `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_none` | `no` | `-` | `3` | `4` | `-1` | `0.750000x` | `sub-20ns, no-syscall` |
| `6` | `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_eth` | `no` | `-` | `3` | `4` | `-1` | `0.750000x` | `sub-20ns, no-syscall` |
| `7` | `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6vxlan_eth` | `no` | `-` | `3` | `4` | `-1` | `0.750000x` | `sub-20ns, no-syscall` |
| `8` | `katran` | `corpus/build/katran/balancer.bpf.o:balancer_ingress` | `no` | `wide, endian` | `52` | `65` | `-13` | `0.800000x` | `no-syscall` |
| `9` | `linux-selftests` | `corpus/build/linux-selftests/test_tc_bpf.bpf.o:pkt_ptr` | `no` | `-` | `4` | `5` | `-1` | `0.800000x` | `sub-20ns, no-syscall` |
| `10` | `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_sit_none` | `yes` | `endian` | `4` | `5` | `-1` | `0.800000x` | `sub-20ns` |
| `11` | `xdp-tutorial` | `corpus/build/xdp-tutorial/packet-solutions/tc_reply_kern_02.bpf.o:_fix_port_egress` | `no` | `endian` | `4` | `5` | `-1` | `0.800000x` | `sub-20ns, no-syscall` |
| `12` | `calico` | `corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint` | `no` | `endian` | `101` | `126` | `-25` | `0.801587x` | `no-syscall` |
| `13` | `xdp-tools` | `corpus/build/xdp-tools/xdp_load_bytes.bpf.o:xdp_probe_prog` | `no` | `-` | `19` | `23` | `-4` | `0.826087x` | `sub-20ns, no-syscall` |
| `14` | `calico` | `corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint` | `no` | `endian` | `97` | `117` | `-20` | `0.829060x` | `no-syscall` |
| `15` | `calico` | `corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_ipv4_frag` | `no` | `-` | `100` | `120` | `-20` | `0.833333x` | `no-syscall` |
| `16` | `calico` | `corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat` | `yes` | `wide, endian` | `96` | `115` | `-19` | `0.834783x` | `-` |
| `17` | `calico` | `corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat` | `yes` | `wide, endian` | `97` | `116` | `-19` | `0.836207x` | `-` |
| `18` | `xdp-tutorial` | `corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_parser_func` | `no` | `-` | `11` | `13` | `-2` | `0.846154x` | `sub-20ns, no-syscall` |
| `19` | `calico` | `corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_ipv4_frag` | `no` | `-` | `97` | `113` | `-16` | `0.858407x` | `no-syscall` |
| `20` | `calico` | `corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat` | `no` | `wide, endian` | `98` | `114` | `-16` | `0.859649x` | `no-syscall` |

## 6. Specific Recommendations To Get Corpus Back Above `1.0x`

1. Emit `stock_exec_ns` unconditionally for every successful corpus `run-kernel` row.
   Today, the missing `57` rows are excluded only because `measure_same_image_pair` is gated on `recompile.requested`. This should be decoupled from policy selection so coverage becomes `150/150` instead of `93/150`.
2. Make same-image pairs state-neutral, not just code-image-neutral.
   The current reset path does not clear arbitrary mutable maps. For corpus packet programs, reload the object between stock/recompiled halves or explicitly snapshot and clear mutable maps. Without that, same-image can drift massively with `syscall_attempted=false`.
3. Raise the measurement floor for corpus reporting.
   The overall geomean is `0.982603x`, but restricting to `stock_exec_ns >= 20ns` raises it to `1.018771x`; `stock_exec_ns >= 50ns` still stays positive at `1.016220x`. Extremely short programs need either higher repeat counts or a separate “noise-dominated” bucket.
4. Revisit `wide` policy picks first.
   Neutralizing applied rows that contain `wide` raises the overall measured corpus geomean from `0.982603x` to `1.003410x`. That is the single most direct policy lever in this dataset.
5. Revalidate policy files against the live xlated program before the VM run.
   `67` rows had same-image pairing enabled but still never attempted the recompile syscall because policy generation selected `0` rules (`policy site ... was not found in the live program`). Those stale/mismatched site references suppress actual apply coverage.
6. Treat current Calico source geomeans as untrustworthy until map-state reset is fixed.
   Calico looks positive only because a few non-applied rows show large same-image speedups. Those are evidence of harness contamination, not successful optimization.
7. After fixing pair neutrality, rerun applied-only triage on the remaining longer-running rows.
   If you neutralize only the applied regressions, the overall geomean would be `1.010945x`. That indicates there is enough headroom to get back above `1.0x` once the bad applied picks and state contamination are removed.

## Final Judgement

- `57/150` missing `stock_exec_ns` is caused by missing recompile requests, not by the JSON serializer.
- Applied-only `0.946786x` is not a single root cause. It is a combination of:
- bad applied `wide` / `wide+endian` policy picks,
- sub-20ns measurement noise in `linux-selftests` and parts of `xdp-tutorial`, and
- a real same-image harness bug/limitation for packet-mode stateful programs because mutable maps are not reset between the stock and post-policy halves.
- Until state reset and coverage are fixed, corpus source geomeans should be treated as diagnostic, not authoritative.

