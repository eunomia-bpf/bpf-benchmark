# Static tail-call graph for corpus apps

Generated: 2026-05-06

Purpose: support analysis-side propagation of pass `applied` counts from tail-call target programs up to the directly attached caller whose `run_cnt_delta` / `run_time_ns_delta` receives the runtime charge. This follows the tail-call accounting caveat in `CLAUDE.md`: tail-called programs skip the stats prologue, so their own `bpftool prog show` counters can remain zero even when they execute.

Method: searched upstream BPF source for `SEC(...)`, `__section_entry`, `bpf_tail_call`, `bpf_tail_call_static`, `tail_call_static`, `tail_call_dynamic`, `tail_call(...)`, `BPF_MAP_TYPE_PROG_ARRAY`, `__array(values, ...)`, and userspace map updates. Rows below use source-level program/function names and the SEC name where it is statically knowable.

Source provenance:

| app | source root used | commit |
|---|---|---|
| cilium | `runner/repos/cilium` | `b0f502923e69` |
| tetragon | `/tmp/bpf-tailcall-src/tetragon` | `a46b00ecb53a` |
| tracee | `/tmp/bpf-tailcall-src/tracee` | `9194542d6343` |
| otel | `runner/repos/opentelemetry-ebpf-profiler` | `582a2cf4a91c` |
| katran | `runner/repos/katran` | `be1b2574fcac` |
| bpftrace | `/tmp/bpf-tailcall-src/bpftrace` | `2067bffa77cd` |
| bcc | `/tmp/bpf-tailcall-src/bcc` | `3fc265d6c847` |

Notes on source substitutions:

- `runner/repos/tetragon`, `runner/repos/tracee`, `runner/repos/bpftrace`, and `runner/repos/bcc` were not present in this checkout, so I cloned sparse upstream worktrees under `/tmp/bpf-tailcall-src`.
- Tetragon current upstream no longer has `bpf/sensors`; the scan covered `bpf/process`, `bpf/lib`, and `bpf/cgroup`.
- bpftrace current upstream has `src/ast/passes/codegen_llvm.cpp` / `.h`; the requested `codegen_llvm/*.cpp` directory does not exist.

Confidence:

- `static`: numeric key is a compile-time constant.
- `symbolic`: key is a compile-time enum / macro symbol resolved to a slot.
- `dynamic`: key is computed at runtime or the map slot is populated by runtime configuration; callee column over-approximates known possible targets.

## cilium

### Tail-call edges

Cilium's main map is `cilium_calls`, declared in `bpf/lib/tailcall.h:107`. Its targets are declared with `__declare_tail(index)` and carry `tail:cilium_calls/<index>` BTF tags. `tail_call_internal()` in `bpf/lib/tailcall.h:130` lowers to `tail_call_static(ctx, cilium_calls, index)`. Cilium also has dynamic endpoint policy arrays `cilium_call_policy` and `cilium_egresscall_policy` in `bpf/lib/local_delivery.h:17` and `bpf/lib/local_delivery.h:34`.

| caller program (SEC name) | call site (file:line) | prog_array map | key | callee program | confidence |
|---|---|---|---|---|---|
| `cil_xdp_entry` (`xdp/entry`) | `runner/repos/cilium/bpf/bpf_xdp.c:131` | `cilium_calls` | `CILIUM_CALL_IPV4_FROM_NETDEV` = 7 | `tail_lb_ipv4` | symbolic |
| `cil_xdp_entry` (`xdp/entry`) | `runner/repos/cilium/bpf/bpf_xdp.c:203` | `cilium_calls` | `CILIUM_CALL_IPV6_FROM_NETDEV` = 10 | `tail_lb_ipv6` | symbolic |
| `cil_from_container` (`tc/entry`) | `runner/repos/cilium/bpf/bpf_lxc.c:1824` | `cilium_calls` | `CILIUM_CALL_IPV6_FROM_LXC` = 10 | `tail_handle_ipv6` | symbolic |
| `cil_from_container` (`tc/entry`) | `runner/repos/cilium/bpf/bpf_lxc.c:1831` | `cilium_calls` | `CILIUM_CALL_IPV4_FROM_LXC` = 7 | `tail_handle_ipv4` | symbolic |
| `cil_from_container` (`tc/entry`) | `runner/repos/cilium/bpf/bpf_lxc.c:1836` | `cilium_calls` | `CILIUM_CALL_ARP` = 6 | `tail_handle_arp` | symbolic |
| `cil_lxc_policy` (`tc/entry`) | `runner/repos/cilium/bpf/bpf_lxc.c:2505` | `cilium_calls` | `CILIUM_CALL_IPV6_CT_INGRESS_POLICY_ONLY` = 32 | `tail_ipv6_ct_ingress_policy_only` | symbolic |
| `cil_lxc_policy` (`tc/entry`) | `runner/repos/cilium/bpf/bpf_lxc.c:2515` | `cilium_calls` | `CILIUM_CALL_IPV4_CT_INGRESS_POLICY_ONLY` = 29 | `tail_ipv4_ct_ingress_policy_only` | symbolic |
| `cil_lxc_policy_egress` (`tc/entry`) | `runner/repos/cilium/bpf/bpf_lxc.c:2566` | `cilium_calls` | `CILIUM_CALL_IPV6_FROM_LXC` = 10 | `tail_handle_ipv6` | symbolic |
| `cil_lxc_policy_egress` (`tc/entry`) | `runner/repos/cilium/bpf/bpf_lxc.c:2572` | `cilium_calls` | `CILIUM_CALL_IPV4_FROM_LXC` = 7 | `tail_handle_ipv4` | symbolic |
| `cil_to_container` (`tc/entry`) | `runner/repos/cilium/bpf/bpf_lxc.c:2619` | `cilium_egresscall_policy` | `lxc_id` | endpoint egress policy program for endpoint id | dynamic |
| `cil_to_container` (`tc/entry`) | `runner/repos/cilium/bpf/bpf_lxc.c:2646` | `cilium_call_policy` | `CONFIG(host_ep_id)` | host endpoint ingress policy program | dynamic |
| `cil_to_container` (`tc/entry`) | `runner/repos/cilium/bpf/bpf_lxc.c:2658` | `cilium_calls` | `CILIUM_CALL_IPV6_CT_INGRESS` = 31 | `tail_ipv6_ct_ingress` | symbolic |
| `cil_to_container` (`tc/entry`) | `runner/repos/cilium/bpf/bpf_lxc.c:2665` | `cilium_calls` | `CILIUM_CALL_IPV4_CT_INGRESS` = 28 | `tail_ipv4_ct_ingress` | symbolic |
| `cil_from_netdev` / `cil_from_host` (`tc/entry`) via `do_netdev` | `runner/repos/cilium/bpf/bpf_host.c:1079` | `cilium_calls` | `from_host ? CILIUM_CALL_IPV6_FROM_HOST : CILIUM_CALL_IPV6_FROM_NETDEV` | `tail_handle_ipv6_from_host` or `tail_handle_ipv6_from_netdev` | dynamic |
| `cil_from_netdev` / `cil_from_host` (`tc/entry`) via `do_netdev` | `runner/repos/cilium/bpf/bpf_host.c:1119` | `cilium_calls` | `from_host ? CILIUM_CALL_IPV4_FROM_HOST : CILIUM_CALL_IPV4_FROM_NETDEV` | `tail_handle_ipv4_from_host` or `tail_handle_ipv4_from_netdev` | dynamic |
| `cil_from_host` (`tc/entry`) | `runner/repos/cilium/bpf/bpf_host.c:1296` | `cilium_egresscall_policy` | `lxc_id` | endpoint egress policy program for endpoint id | dynamic |
| `cil_to_netdev` (`tc/entry`) | `runner/repos/cilium/bpf/bpf_host.c:1370` | `cilium_egresscall_policy` | `lxc_id` | endpoint egress policy program for endpoint id | dynamic |
| `cil_to_host` / `cil_host_policy` (`tc/entry`) via `host_ingress_policy` | `runner/repos/cilium/bpf/bpf_host.c:1606` | `cilium_calls` | `CILIUM_CALL_IPV6_TO_HOST_POLICY_ONLY` = 12 | `tail_ipv6_host_policy_ingress` | symbolic |
| `cil_to_host` / `cil_host_policy` (`tc/entry`) via `host_ingress_policy` | `runner/repos/cilium/bpf/bpf_host.c:1620` | `cilium_calls` | `CILIUM_CALL_IPV4_TO_HOST_POLICY_ONLY` = 11 | `tail_ipv4_host_policy_ingress` | symbolic |
| `cil_host_policy` (`tc/entry`) | `runner/repos/cilium/bpf/bpf_host.c:1888` | `cilium_call_policy` | `lxc_id` | endpoint ingress policy program for endpoint id | dynamic |
| `tail_ipv6_ct_egress` (`tc/tail`) | `runner/repos/cilium/bpf/bpf_lxc.c:1086` macro target | `cilium_calls` | `CILIUM_CALL_IPV6_FROM_LXC_CONT` = 27 | `tail_handle_ipv6_cont` | symbolic |
| `tail_ipv4_ct_egress` (`tc/tail`) | `runner/repos/cilium/bpf/bpf_lxc.c:1680` macro target | `cilium_calls` | `CILIUM_CALL_IPV4_FROM_LXC_CONT` = 26 | `tail_handle_ipv4_cont` | symbolic |
| `tail_ipv6_ct_ingress_policy_only` (`tc/tail`) | `runner/repos/cilium/bpf/bpf_lxc.c:2146` macro target | `cilium_calls` | `CILIUM_CALL_IPV6_TO_LXC_POLICY_ONLY` = 12 | `tail_ipv6_policy` | symbolic |
| `tail_ipv6_ct_ingress` (`tc/tail`) | `runner/repos/cilium/bpf/bpf_lxc.c:2151` macro target | `cilium_calls` | `CILIUM_CALL_IPV6_TO_ENDPOINT` = 14 | `tail_ipv6_to_endpoint` | symbolic |
| `tail_ipv4_ct_ingress_policy_only` (`tc/tail`) | `runner/repos/cilium/bpf/bpf_lxc.c:2467` macro target | `cilium_calls` | `CILIUM_CALL_IPV4_TO_LXC_POLICY_ONLY` = 11 | `tail_ipv4_policy` | symbolic |
| `tail_ipv4_ct_ingress` (`tc/tail`) | `runner/repos/cilium/bpf/bpf_lxc.c:2472` macro target | `cilium_calls` | `CILIUM_CALL_IPV4_TO_ENDPOINT` = 13 | `tail_ipv4_to_endpoint` | symbolic |
| `__per_packet_lb_svc_xlate_4` helper, reached from LXC IPv4 path | `runner/repos/cilium/bpf/bpf_lxc.c:291` | `cilium_calls` | `CILIUM_CALL_IPV4_CT_EGRESS` = 30 | `tail_ipv4_ct_egress` | symbolic |
| `__per_packet_lb_svc_xlate_6` helper, reached from LXC IPv6 path | `runner/repos/cilium/bpf/bpf_lxc.c:453` | `cilium_calls` | `CILIUM_CALL_IPV6_CT_EGRESS` = 33 | `tail_ipv6_ct_egress` | symbolic |
| `tail_handle_ipv6` (`tc/tail`) | `runner/repos/cilium/bpf/bpf_lxc.c:695` | `cilium_calls` | `CILIUM_CALL_SRV6_ENCAP` = 34 | `tail_srv6_encap` | symbolic |
| `tail_handle_ipv6` (`tc/tail`) | `runner/repos/cilium/bpf/bpf_lxc.c:985` | `cilium_calls` | `CILIUM_CALL_IPV6_POLICY_DENIED` = 49 | `tail_policy_denied_ipv6` | symbolic |
| `tail_handle_ipv6` (`tc/tail`) | `runner/repos/cilium/bpf/bpf_lxc.c:1055` | `cilium_calls` | `CILIUM_CALL_IPV6_NODEPORT_REVNAT_EGRESS` = 19 | `tail_nodeport_rev_dnat_egress_ipv6` | symbolic |
| `tail_handle_ipv4` (`tc/tail`) | `runner/repos/cilium/bpf/bpf_lxc.c:1554` | `cilium_calls` | `CILIUM_CALL_IPV4_POLICY_DENIED` = 48 | `tail_policy_denied_ipv4` | symbolic |
| `tail_handle_ipv4` (`tc/tail`) | `runner/repos/cilium/bpf/bpf_lxc.c:1647` | `cilium_calls` | `CILIUM_CALL_IPV4_NODEPORT_REVNAT` = 17 | `tail_nodeport_rev_dnat_ipv4` | symbolic |
| `tail_handle_ipv4` (`tc/tail`) | `runner/repos/cilium/bpf/bpf_lxc.c:1721` | `cilium_calls` | `CILIUM_CALL_MULTICAST_EP_DELIVERY` = 47 | `tail_mcast_ep_delivery` | symbolic |
| NodePort IPv6 helper, reached from XDP/TC paths | `runner/repos/cilium/bpf/lib/nodeport.h:1122` | `cilium_calls` | `CILIUM_CALL_IPV6_NODEPORT_REVNAT_INGRESS` = 18 | `tail_nodeport_rev_dnat_ingress_ipv6` | symbolic |
| NodePort IPv6 helper, reached from XDP/TC paths | `runner/repos/cilium/bpf/lib/nodeport.h:1208` | `cilium_calls` | `CILIUM_CALL_IPV6_NODEPORT_NAT_INGRESS` = 37 | `tail_nodeport_nat_ingress_ipv6` | symbolic |
| NodePort IPv6 helper, reached from XDP/TC paths | `runner/repos/cilium/bpf/lib/nodeport.h:1224` | `cilium_calls` | `CILIUM_CALL_IPV6_NODEPORT_NAT_EGRESS` = 16 | `tail_nodeport_nat_egress_ipv6` | symbolic |
| NodePort IPv6 DSR helper | `runner/repos/cilium/bpf/lib/nodeport.h:1450` | `cilium_calls` | `CILIUM_CALL_IPV6_NODEPORT_DSR` = 22 | `tail_nodeport_ipv6_dsr` | symbolic |
| NodePort IPv4 helper, reached from XDP/TC paths | `runner/repos/cilium/bpf/lib/nodeport.h:2372` | `cilium_calls` | `CILIUM_CALL_IPV4_NODEPORT_REVNAT` = 17 | `tail_nodeport_rev_dnat_ipv4` | symbolic |
| NodePort IPv4 helper, reached from XDP/TC paths | `runner/repos/cilium/bpf/lib/nodeport.h:2442` | `cilium_calls` | `CILIUM_CALL_IPV4_NODEPORT_NAT_INGRESS` = 36 | `tail_nodeport_nat_ingress_ipv4` | symbolic |
| NodePort IPv4 helper, reached from XDP/TC paths | `runner/repos/cilium/bpf/lib/nodeport.h:2521` | `cilium_calls` | `CILIUM_CALL_IPV4_NODEPORT_NAT_EGRESS` = 15 | `tail_nodeport_nat_egress_ipv4` | symbolic |
| NodePort IPv4 DSR helper | `runner/repos/cilium/bpf/lib/nodeport.h:2770` | `cilium_calls` | `CILIUM_CALL_IPV4_NODEPORT_DSR` = 21 | `tail_nodeport_ipv4_dsr` | symbolic |
| NodePort no-service helper | `runner/repos/cilium/bpf/lib/lb.h:2223` declaration / callers in `nodeport.h` | `cilium_calls` | `CILIUM_CALL_IPV4_NO_SERVICE` = 45 | `tail_no_service_ipv4` | symbolic |
| NodePort no-service helper | `runner/repos/cilium/bpf/lib/lb.h:2246` declaration / callers in `nodeport.h` | `cilium_calls` | `CILIUM_CALL_IPV6_NO_SERVICE` = 46 | `tail_no_service_ipv6` | symbolic |
| ICMPv6 helper | `runner/repos/cilium/bpf/lib/icmp6.h:341` | `cilium_calls` | `CILIUM_CALL_SEND_ICMP6_TIME_EXCEEDED` = 5 | `tail_icmp6_send_time_exceeded` | symbolic |
| ICMPv6 helper | `runner/repos/cilium/bpf/lib/icmp6.h:429` | `cilium_calls` | `CILIUM_CALL_HANDLE_ICMP6_NS` = 4 | `tail_icmp6_handle_ns` | symbolic |
| SRv6 helper | `runner/repos/cilium/bpf/lib/srv6.h:455` | `cilium_calls` | `CILIUM_CALL_SRV6_ENCAP` = 34 | `tail_srv6_encap` | symbolic |
| SRv6 helper | `runner/repos/cilium/bpf/lib/srv6.h:464` | `cilium_calls` | `CILIUM_CALL_SRV6_DECAP` = 35 | `tail_srv6_decap` | symbolic |
| Drop helper | `runner/repos/cilium/bpf/lib/drop.h:159` | `cilium_calls` | `CILIUM_CALL_DROP_NOTIFY` = 1 | `tail_drop_notify` | symbolic |

`cilium_calls` target declarations found in source:

| key | target declarations |
|---|---|
| `CILIUM_CALL_DROP_NOTIFY` | `tail_drop_notify` (`bpf/lib/drop.h:69`) |
| `CILIUM_CALL_HANDLE_ICMP6_NS` | `tail_icmp6_handle_ns` (`bpf/lib/icmp6.h:398`) |
| `CILIUM_CALL_SEND_ICMP6_TIME_EXCEEDED` | `tail_icmp6_send_time_exceeded` (`bpf/lib/icmp6.h:314`) |
| `CILIUM_CALL_ARP` | `tail_handle_arp` (`bpf_lxc.c:1752`, `bpf_overlay.c:423`) |
| `CILIUM_CALL_IPV4_FROM_*` | `tail_lb_ipv4`, `tail_handle_ipv4`, `tail_handle_ipv4_from_host`, `tail_handle_ipv4_from_netdev`, `tail_handle_ipv4_cont_from_host`, `tail_handle_ipv4_cont_from_netdev`, object-specific by BPF object |
| `CILIUM_CALL_IPV6_FROM_*` | `tail_lb_ipv6`, `tail_handle_ipv6`, `tail_handle_ipv6_from_host`, `tail_handle_ipv6_from_netdev`, `tail_handle_ipv6_cont_from_host`, `tail_handle_ipv6_cont_from_netdev`, object-specific by BPF object |
| `CILIUM_CALL_IPV4_CT_*` / `CILIUM_CALL_IPV6_CT_*` | `tail_ipv4_ct_*`, `tail_ipv6_ct_*` in `bpf_lxc.c` |
| `CILIUM_CALL_IPV4_TO_*` / `CILIUM_CALL_IPV6_TO_*` | `tail_ipv4_policy`, `tail_ipv6_policy`, `tail_ipv4_to_endpoint`, `tail_ipv6_to_endpoint`, host policy ingress tails |
| NodePort slots | `tail_nodeport_*` declarations in `bpf/lib/nodeport.h` and `bpf/lib/nodeport_egress.h` |
| `CILIUM_CALL_SRV6_*` | `tail_srv6_encap`, `tail_srv6_decap` |
| `CILIUM_CALL_MULTICAST_EP_DELIVERY` | `tail_mcast_ep_delivery` |
| `CILIUM_CALL_IPV4_POLICY_DENIED` / `CILIUM_CALL_IPV6_POLICY_DENIED` | `tail_policy_denied_ipv4`, `tail_policy_denied_ipv6` |

### Direct-attached entry points

- `xdp/entry`: `cil_xdp_entry`
- `tc/entry`: `cil_from_wireguard`, `cil_to_wireguard`, `cil_from_overlay`, `cil_to_overlay`, `cil_from_netdev`, `cil_from_host`, `cil_to_netdev`, `cil_to_host`, `cil_host_policy`, `cil_from_container`, `cil_lxc_policy`, `cil_lxc_policy_egress`, `cil_to_container`
- probe entries in `bpf_probes.c`: `probe_fib_lookup_skip_neigh`, `probe_fib_lookup_tbid`, `probe_fib_lookup_src`

### Spot-check

`cil_from_container` is a direct `tc/entry` program at `runner/repos/cilium/bpf/bpf_lxc.c:1789`. The protocol switch tail-calls `CILIUM_CALL_IPV6_FROM_LXC`, `CILIUM_CALL_IPV4_FROM_LXC`, and `CILIUM_CALL_ARP` at `bpf_lxc.c:1824`, `bpf_lxc.c:1831`, and `bpf_lxc.c:1836`. The matching tail targets are declared at `bpf_lxc.c:1130` (`tail_handle_ipv6`), `bpf_lxc.c:1736` (`tail_handle_ipv4`), and `bpf_lxc.c:1752` (`tail_handle_arp`).

## tetragon

### Tail-call edges

Tetragon uses per-sensor prog-array maps with inline `__array(values, ...)` initializers. The shared tail-call indexes are in `bpf/process/types/basic.h:142`: `TAIL_CALL_SETUP=0`, `PROCESS=1`, `FILTER=2`, `ARGS=3`, `ACTIONS=4`, `SEND=5`, `PATH=6`, `PROCESS_2=7`, `ARGS_2=8`.

| caller program (SEC name) | call site (file:line) | prog_array map | key | callee program | confidence |
|---|---|---|---|---|---|
| `generic_kprobe_event` (`kprobe/generic_kprobe` or `kprobe.multi/generic_kprobe`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/bpf_generic_kprobe.c:91`, helper at `generic_calls.h:77` | `kprobe_calls` | `TAIL_CALL_FILTER` = 2 | `generic_kprobe_process_filter` | symbolic |
| `generic_kprobe_process_filter` (`kprobe` or `kprobe.multi`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/bpf_generic_kprobe.c:127` | `kprobe_calls` | `TAIL_CALL_FILTER` = 2 | `generic_kprobe_process_filter` | symbolic |
| `generic_kprobe_process_filter` (`kprobe` or `kprobe.multi`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/bpf_generic_kprobe.c:129` | `kprobe_calls` | `TAIL_CALL_SETUP` = 0 | `generic_kprobe_setup_event` | symbolic |
| `generic_kprobe_setup_event` (`kprobe` or `kprobe.multi`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/generic_calls.h:1319` | `kprobe_calls` | `TAIL_CALL_ARGS` = 3 | `generic_kprobe_filter_arg` | symbolic |
| `generic_kprobe_process_event` (`kprobe` or `kprobe.multi`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/generic_calls.h:683` | `kprobe_calls` | `TAIL_CALL_PROCESS` = 1 | `generic_kprobe_process_event` | symbolic |
| `generic_kprobe_process_event` (`kprobe` or `kprobe.multi`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/generic_calls.h:688` | `kprobe_calls` | `TAIL_CALL_ARGS` = 3 | `generic_kprobe_filter_arg` | symbolic |
| `generic_kprobe_filter_arg` (`kprobe` or `kprobe.multi`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/generic_calls.h:1479` | `kprobe_calls` | `TAIL_CALL_ARGS` = 3 | `generic_kprobe_filter_arg` | symbolic |
| `generic_kprobe_filter_arg` (`kprobe` or `kprobe.multi`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/generic_calls.h:1489` | `kprobe_calls` | `TAIL_CALL_ACTIONS` = 4 | `generic_kprobe_actions` | symbolic |
| `generic_kprobe_filter_arg` (`kprobe` or `kprobe.multi`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/generic_calls.h:1492` | `kprobe_calls` | `TAIL_CALL_SEND` = 5 | `generic_kprobe_output` | symbolic |
| `generic_kprobe_actions` (`kprobe` or `kprobe.multi`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/generic_calls.h:1161` | `kprobe_calls` | `TAIL_CALL_SEND` = 5 | `generic_kprobe_output` | symbolic |
| `generic_kprobe_path` (`kprobe` or `kprobe.multi`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/generic_path.h:65` | `kprobe_calls` | `TAIL_CALL_PATH` = 6 | `generic_kprobe_path` | symbolic |
| `generic_kprobe_path` (`kprobe` or `kprobe.multi`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/generic_path.h:107` | `kprobe_calls` | `TAIL_CALL_PROCESS` = 1 | `generic_kprobe_process_event` | symbolic |
| `generic_kprobe_path` (`kprobe` or `kprobe.multi`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/generic_path.h:115` | `kprobe_calls` | `TAIL_CALL_PATH` = 6 | `generic_kprobe_path` | symbolic |
| `generic_kprobe_path` (`kprobe` or `kprobe.multi`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/generic_path.h:192` | `kprobe_calls` | `TAIL_CALL_PATH` = 6 | `generic_kprobe_path` | symbolic |
| `generic_uprobe_event` (`uprobe/generic_uprobe`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/bpf_generic_uprobe.c:105`, helper at `generic_calls.h:77` | `uprobe_calls` | `TAIL_CALL_FILTER` = 2 | `generic_uprobe_process_filter` | symbolic |
| `generic_uprobe_process_filter` (`uprobe`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/bpf_generic_uprobe.c:107` | `uprobe_calls` | `TAIL_CALL_SETUP` = 0 | `generic_uprobe_setup_event` | symbolic |
| `generic_usdt_event` (`uprobe/generic_usdt`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/bpf_generic_usdt.c:89`, helper at `generic_calls.h:77` | `usdt_calls` | `TAIL_CALL_FILTER` = 2 | `generic_usdt_process_filter` | symbolic |
| `generic_usdt_process_filter` (`uprobe`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/bpf_generic_usdt.c:91` | `usdt_calls` | `TAIL_CALL_SETUP` = 0 | `generic_usdt_setup_event` | symbolic |
| `generic_fentry_event` (`fentry`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/bpf_generic_fentry.c:77`, helper at `generic_calls.h:77` | `fentry_calls` | `TAIL_CALL_FILTER` = 2 | `generic_fentry_process_filter` | symbolic |
| `generic_fentry_process_filter` (`fentry`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/bpf_generic_fentry.c:79` | `fentry_calls` | `TAIL_CALL_SETUP` = 0 | `generic_fentry_setup_event` | symbolic |
| `generic_rawtp_event` (`raw_tp/generic_tracepoint`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/bpf_generic_rawtp.c:101`, helper at `generic_calls.h:77` | `tp_calls` | `TAIL_CALL_FILTER` = 2 | `generic_rawtp_process_filter` | symbolic |
| `generic_rawtp_process_filter` (`raw_tp`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/bpf_generic_rawtp.c:103` | `tp_calls` | `TAIL_CALL_SETUP` = 0 | `generic_rawtp_setup_event` | symbolic |
| `generic_tracepoint_event` (`tracepoint/generic_tracepoint`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/bpf_generic_tracepoint.c:265`, helper at `generic_calls.h:77` | `tp_calls` | `TAIL_CALL_FILTER` = 2 | `generic_tracepoint_process_filter` | symbolic |
| `generic_tracepoint_event` (`tracepoint/generic_tracepoint`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/bpf_generic_tracepoint.c:296` | `tp_calls` | `TAIL_CALL_FILTER` = 2 | `generic_tracepoint_process_filter` | symbolic |
| `generic_tracepoint_event` (`tracepoint/generic_tracepoint`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/bpf_generic_tracepoint.c:298` | `tp_calls` | `TAIL_CALL_PROCESS` = 1 | `generic_tracepoint_process_event` | symbolic |
| `generic_lsm_event` (`lsm` or `lsm.s`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/bpf_generic_lsm_core.c:80`, helper at `generic_calls.h:77` | `lsm_calls` | `TAIL_CALL_FILTER` = 2 | `generic_lsm_process_filter` | symbolic |
| `generic_lsm_process_filter` (`lsm`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/bpf_generic_lsm_core.c:82` | `lsm_calls` | `TAIL_CALL_SETUP` = 0 | `generic_lsm_setup_event` | symbolic |
| `generic_fexit_event` (`fexit`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/bpf_generic_fexit.c:43` and shared args helper | `fexit_calls` | `TAIL_CALL_ARGS` = 3 | `generic_fexit_filter_arg` | symbolic |
| `generic_fexit_filter_arg` (`fexit`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/generic_calls.h:1489` | `fexit_calls` | `TAIL_CALL_ACTIONS` = 4 | `generic_fexit_actions` | symbolic |
| `generic_fexit_actions` (`fexit`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/generic_calls.h:1161` | `fexit_calls` | `TAIL_CALL_SEND` = 5 | `generic_fexit_output` | symbolic |
| `generic_retkprobe_event` (`kretprobe/generic_kprobe`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/bpf_generic_retkprobe.c:50` and shared args helper | `retkprobe_calls` | `TAIL_CALL_ARGS` = 3 | `generic_retkprobe_filter_arg` | symbolic |
| `generic_retkprobe_filter_arg` (`kretprobe`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/generic_calls.h:1489` | `retkprobe_calls` | `TAIL_CALL_ACTIONS` = 4 | `generic_retkprobe_actions` | symbolic |
| `generic_retkprobe_actions` (`kretprobe`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/generic_calls.h:1161` | `retkprobe_calls` | `TAIL_CALL_SEND` = 5 | `generic_retkprobe_output` | symbolic |
| `generic_retuprobe_event` (`uretprobe/generic_uprobe`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/bpf_generic_retuprobe.c:50` and shared args helper | `retuprobe_calls` | `TAIL_CALL_ARGS` = 3 | `generic_retuprobe_filter_arg` | symbolic |
| `generic_retuprobe_filter_arg` (`uretprobe`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/generic_calls.h:1489` | `retuprobe_calls` | `TAIL_CALL_ACTIONS` = 4 | `generic_retuprobe_actions` | symbolic |
| `generic_retuprobe_actions` (`uretprobe`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/generic_calls.h:1161` | `retuprobe_calls` | `TAIL_CALL_SEND` = 5 | `generic_retuprobe_output` | symbolic |
| `event_execve` (`tracepoint/sys_execve`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/bpf_execve_event.c:324` | `execve_calls` | `0` | `execve_rate` | static |
| `execve_rate` (`tracepoint`) | `/tmp/bpf-tailcall-src/tetragon/bpf/process/bpf_execve_event.c:339` | `execve_calls` | `1` | `execve_send` | static |

Inline map initializers:

- `kprobe_calls`: `/tmp/bpf-tailcall-src/tetragon/bpf/process/bpf_generic_kprobe.c:29`, values map setup/process/filter/args/actions/send/path/process_2/args_2.
- `uprobe_calls`: `/tmp/bpf-tailcall-src/tetragon/bpf/process/bpf_generic_uprobe.c:31`, same generic chain.
- `usdt_calls`: `/tmp/bpf-tailcall-src/tetragon/bpf/process/bpf_generic_usdt.c:28`, same generic chain.
- `fentry_calls`: `/tmp/bpf-tailcall-src/tetragon/bpf/process/bpf_generic_fentry.c:28`, same generic chain.
- `tp_calls`: `/tmp/bpf-tailcall-src/tetragon/bpf/process/bpf_generic_tracepoint.c:29` and `bpf_generic_rawtp.c:29`.
- `lsm_calls`: `/tmp/bpf-tailcall-src/tetragon/bpf/process/bpf_generic_lsm_core.c:30`.
- `execve_calls`: `/tmp/bpf-tailcall-src/tetragon/bpf/process/bpf_execve_event.c:30`, values `[0]=execve_rate`, `[1]=execve_send`.

### Direct-attached entry points

- `kprobe/generic_kprobe` or `kprobe.multi/generic_kprobe`: `generic_kprobe_event`
- `uprobe/generic_uprobe`: `generic_uprobe_event`
- `uprobe/generic_usdt`: `generic_usdt_event`
- `fentry`: `generic_fentry_event`
- `fexit`: `generic_fexit_event`
- `kretprobe/generic_kprobe`: `generic_retkprobe_event`
- `uretprobe/generic_uprobe`: `generic_retuprobe_event`
- `tracepoint/generic_tracepoint`: `generic_tracepoint_event`
- `raw_tp/generic_tracepoint`: `generic_rawtp_event`
- `lsm` / `lsm.s`: `generic_lsm_event`
- `tracepoint/sys_execve`: `event_execve`
- `iter/bpf_prog`: `bpf_prog_iter` (no tail calls found from this root)

### Spot-check

`generic_kprobe_event` starts at `/tmp/bpf-tailcall-src/tetragon/bpf/process/bpf_generic_kprobe.c:88` and calls `generic_start_process_filter(ctx, &kprobe_calls)` at `bpf_generic_kprobe.c:91`. The helper tail-calls `TAIL_CALL_FILTER` at `/tmp/bpf-tailcall-src/tetragon/bpf/process/generic_calls.h:77`, and the `kprobe_calls` initializer maps that slot to `generic_kprobe_process_filter` at `bpf_generic_kprobe.c:34`.

## tracee

### Tail-call edges

Tracee has several runtime-populated prog-array maps declared in `pkg/ebpf/c/maps.h`: `prog_array` (`maps.h:169`), `prog_array_tp` (`maps.h:179`), `sys_enter_tails` (`maps.h:189`), `sys_exit_tails` (`maps.h:199`), `generic_sys_enter_tails` (`maps.h:209`), and `generic_sys_exit_tails` (`maps.h:219`). Userspace fills those maps in `pkg/ebpf/tracee.go:738` through `tracee.go:767`; event definitions provide map/program/index triples.

Tail-call ids in `pkg/ebpf/c/types.h:188` / `pkg/events/definition_dependencies.go:184`:

| id | value | resolved program examples |
|---|---:|---|
| `TAIL_VFS_WRITE` | 0 | `trace_ret_vfs_write_tail` |
| `TAIL_VFS_WRITEV` | 1 | `trace_ret_vfs_writev_tail` |
| `TAIL_SEND_BIN` | 2 | `send_bin` |
| `TAIL_SEND_BIN_TP` | 3 | `send_bin_tp` |
| `TAIL_KERNEL_WRITE` | 4 | `trace_ret_kernel_write_tail` |
| `TAIL_SCHED_PROCESS_EXEC_EVENT_SUBMIT` | 5 | `sched_process_exec_event_submit_tail` |
| `TAIL_VFS_READ` | 6 | `trace_ret_vfs_read_tail` |
| `TAIL_VFS_READV` | 7 | `trace_ret_vfs_readv_tail` |
| `TAIL_PROCESS_EXECUTE_FAILED` | 8 | `process_execute_failed_tail` |
| `TAIL_HIDDEN_KERNEL_MODULE_PROC` | 9 | `lkm_seeker_proc_tail` |
| `TAIL_HIDDEN_KERNEL_MODULE_KSET` | 10 | `lkm_seeker_kset_tail` |
| `TAIL_HIDDEN_KERNEL_MODULE_MOD_TREE` | 11 | `lkm_seeker_mod_tree_tail` |
| `TAIL_HIDDEN_KERNEL_MODULE_NEW_MOD_ONLY` | 12 | `lkm_seeker_new_mod_only_tail` |
| `TAIL_HIDDEN_KERNEL_MODULE_MODTREE_LOOP` | 13 | `lkm_seeker_modtree_loop` |
| `TAIL_FEATURES_FALLBACK` | 14 | one of `uprobe__features_fallback_*_tailcall` |

| caller program (SEC name) | call site (file:line) | prog_array map | key | callee program | confidence |
|---|---|---|---|---|---|
| `tracepoint__raw_syscalls__sys_enter` (`raw_tracepoint/sys_enter`) | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:58` | `sys_enter_init_tail` | syscall id | `sys_enter_init` dispatcher | dynamic |
| `sys_enter_init` (tail dispatcher) | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:128` | `sys_enter_submit_tail` | syscall id | `sys_enter_submit` dispatcher | dynamic |
| `sys_enter_init` (tail dispatcher) | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:131` | `sys_enter_tails` | syscall id | event-specific enter tail, e.g. `syscall__execve_enter`, `syscall__execveat_enter`, `syscall__init_module` | dynamic |
| `sys_enter_submit` (tail dispatcher) | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:177` | `sys_enter_tails` | syscall id | event-specific enter tail | dynamic |
| `tracepoint__raw_syscalls__sys_exit` (`raw_tracepoint/sys_exit`) | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:197` | `sys_exit_init_tail` | syscall id | `sys_exit_init` dispatcher | dynamic |
| `sys_exit_init` (tail dispatcher) | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:255` | `sys_exit_submit_tail` | syscall id | `sys_exit_submit` dispatcher | dynamic |
| `sys_exit_init` (tail dispatcher) | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:258` | `sys_exit_tails` | syscall id | event-specific exit tail, e.g. `syscall__execve_exit`, `syscall__execveat_exit`, `syscall__accept4` | dynamic |
| `sys_exit_submit` (tail dispatcher) | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:295` | `sys_exit_tails` | syscall id | event-specific exit tail | dynamic |
| generic syscall-enter macro roots | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/common/probes.h:191` | `generic_sys_enter_tails` | event id | generic syscall enter tail | dynamic |
| generic syscall-exit macro roots | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/common/probes.h:218` | `generic_sys_exit_tails` | event id | generic syscall exit tail, e.g. `sys_dup_exit_tail` for dup/dup2/dup3 | dynamic |
| `lkm_seeker` (`uprobe/lkm_seeker`) | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:1288` | `prog_array` | `TAIL_HIDDEN_KERNEL_MODULE_KSET` = 10 | `lkm_seeker_kset_tail` | symbolic |
| `lkm_seeker` (`uprobe/lkm_seeker`) | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:1292` | `prog_array` | `TAIL_HIDDEN_KERNEL_MODULE_PROC` = 9 | `lkm_seeker_proc_tail` | symbolic |
| `lkm_seeker_kset_tail` (`uprobe/lkm_seeker_kset_tail`) | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:1319` | `prog_array` | `TAIL_HIDDEN_KERNEL_MODULE_MOD_TREE` = 11 | `lkm_seeker_mod_tree_tail` | symbolic |
| `lkm_seeker_mod_tree_tail` (`uprobe/lkm_seeker_mod_tree_tail`) | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:1342` | `prog_array` | `TAIL_HIDDEN_KERNEL_MODULE_PROC` = 9 | `lkm_seeker_proc_tail` | symbolic |
| `lkm_seeker_proc_tail` (`uprobe/lkm_seeker_proc_tail`) | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:1364` | `prog_array` | `TAIL_HIDDEN_KERNEL_MODULE_NEW_MOD_ONLY` = 12 | `lkm_seeker_new_mod_only_tail` | symbolic |
| `lkm_seeker_modtree_loop` (`uprobe/lkm_seeker_modtree_loop_tail`) | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:1061` | `prog_array` | `TAIL_HIDDEN_KERNEL_MODULE_PROC` = 9 | `lkm_seeker_proc_tail` | symbolic |
| `lkm_seeker_modtree_loop` (`uprobe/lkm_seeker_modtree_loop_tail`) | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:1073` | `prog_array` | `TAIL_HIDDEN_KERNEL_MODULE_MODTREE_LOOP` = 13 | `lkm_seeker_modtree_loop` | symbolic |
| `find_modules_from_mod_tree` helper | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:1108` | `prog_array` | `TAIL_HIDDEN_KERNEL_MODULE_MODTREE_LOOP` = 13 | `lkm_seeker_modtree_loop` | symbolic |
| `tracepoint__sched_process_exec` (`raw_tracepoint/sched_process_exec`) | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:1482` | `prog_array_tp` | `TAIL_SCHED_PROCESS_EXEC_EVENT_SUBMIT` = 5 | `sched_process_exec_event_submit_tail` | symbolic |
| `tail_call_send_bin` helper, reached from file/bin capture roots | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:3015` | `prog_array` | `TAIL_SEND_BIN` = 2 | `send_bin` | symbolic |
| `tail_call_send_bin` helper, reached from tracepoint bin capture roots | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:3017` | `prog_array_tp` | `TAIL_SEND_BIN_TP` = 3 | `send_bin_tp` | symbolic |
| `send_bin` (`kprobe/send_bin`) | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:3054` | `prog_array` | `TAIL_SEND_BIN` = 2 | `send_bin` | symbolic |
| `send_bin` (`kprobe/send_bin`) | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:3109` | `prog_array` | `TAIL_SEND_BIN` = 2 | `send_bin` | symbolic |
| `send_bin` (`kprobe/send_bin`) | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:3136` | `prog_array` | `TAIL_SEND_BIN` = 2 | `send_bin` | symbolic |
| `send_bin_tp` (`raw_tracepoint/send_bin_tp`) | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:3054` | `prog_array_tp` | `TAIL_SEND_BIN_TP` = 3 | `send_bin_tp` | symbolic |
| `do_file_io_operation` helper from `trace_ret_vfs_write` | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:3217` | `prog_array` | `TAIL_VFS_WRITE` = 0 | `trace_ret_vfs_write_tail` | symbolic |
| `do_file_io_operation` helper from `trace_ret_vfs_writev` | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:3217` | `prog_array` | `TAIL_VFS_WRITEV` = 1 | `trace_ret_vfs_writev_tail` | symbolic |
| `do_file_io_operation` helper from `trace_ret_kernel_write` | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:3217` | `prog_array` | `TAIL_KERNEL_WRITE` = 4 | `trace_ret_kernel_write_tail` | symbolic |
| `do_file_io_operation` helper from `trace_ret_vfs_read` | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:3217` | `prog_array` | `TAIL_VFS_READ` = 6 | `trace_ret_vfs_read_tail` | symbolic |
| `do_file_io_operation` helper from `trace_ret_vfs_readv` | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:3217` | `prog_array` | `TAIL_VFS_READV` = 7 | `trace_ret_vfs_readv_tail` | symbolic |
| `trace_ret_vfs_write` (`kretprobe/vfs_write`) | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:3365` | `prog_array` | `TAIL_VFS_WRITE` = 0 | `trace_ret_vfs_write_tail` | symbolic |
| `trace_ret_vfs_writev` (`kretprobe/vfs_writev`) | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:3380` | `prog_array` | `TAIL_VFS_WRITEV` = 1 | `trace_ret_vfs_writev_tail` | symbolic |
| `trace_ret_kernel_write` (`kretprobe/__kernel_write`) | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:3395` | `prog_array` | `TAIL_KERNEL_WRITE` = 4 | `trace_ret_kernel_write_tail` | symbolic |
| `trace_ret_vfs_read` (`kretprobe/vfs_read`) | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:3410` | `prog_array` | `TAIL_VFS_READ` = 6 | `trace_ret_vfs_read_tail` | symbolic |
| `trace_ret_vfs_readv` (`kretprobe/vfs_readv`) | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:3425` | `prog_array` | `TAIL_VFS_READV` = 7 | `trace_ret_vfs_readv_tail` | symbolic |
| `security_bprm_check` / process execute failed path | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:5130` | `prog_array` | `TAIL_PROCESS_EXECUTE_FAILED` = 8 | `process_execute_failed_tail` | symbolic |
| `uprobe__features_fallback_arena` (`uprobe/features_fallback_test`) | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:7638` | `prog_array` | `TAIL_FEATURES_FALLBACK` = 14 | one enabled `uprobe__features_fallback_*_tailcall` | dynamic |
| feature fallback helper | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:7670` | `prog_array` | `TAIL_FEATURES_FALLBACK` = 14 | one enabled `uprobe__features_fallback_*_tailcall` | dynamic |
| feature fallback minimal root | `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:7698` | `prog_array` | `TAIL_FEATURES_FALLBACK` = 14 | one enabled `uprobe__features_fallback_*_tailcall` | dynamic |

Runtime map entries observed in event definitions:

- `sys_enter_tails[Execve] -> syscall__execve_enter`, `sys_exit_tails[Execve] -> syscall__execve_exit` at `/tmp/bpf-tailcall-src/tracee/pkg/events/core.go:1965`.
- `sys_enter_tails[Execveat] -> syscall__execveat_enter`, `sys_exit_tails[Execveat] -> syscall__execveat_exit` at `core.go:9191`.
- `generic_sys_exit_tails[Dup|Dup2|Dup3] -> sys_dup_exit_tail` at `core.go:13478`.
- `prog_array` hidden module tails at `core.go:13755` through `core.go:13759`.
- `prog_array` VFS/bin tails at `core.go:13938` through `core.go:13967`.
- `sys_enter_tails[InitModule] -> syscall__init_module`, `prog_array_tp[TAIL_SEND_BIN_TP] -> send_bin_tp`, and `prog_array[TAIL_SEND_BIN] -> send_bin` at `core.go:14011` through `core.go:14013`.
- `sys_exit_tails[Accept|Accept4] -> syscall__accept4` at `core.go:14136`.
- `prog_array[TAIL_PROCESS_EXECUTE_FAILED] -> process_execute_failed_tail` at `core.go:14610`.
- `prog_array[TAIL_FEATURES_FALLBACK] -> uprobe__features_fallback_*_tailcall` at `core.go:15793`, `core.go:15804`, and `core.go:15813`; these are alternative dependency selections for the same tail-call key.

### Direct-attached entry points

- Raw syscall roots: `raw_tracepoint/sys_enter`, `raw_tracepoint/sys_exit`
- Raw tracepoint roots including `raw_tracepoint/sched_process_exec`
- Kprobe/kretprobe roots for VFS/bin/module/process/security events, excluding names ending in `_tail` when they only appear as tail destinations
- Uprobe roots such as `uprobe/lkm_seeker` and `uprobe/features_fallback_test`, excluding `*_tail` / `*_tailcall` destinations
- LSM, cgroup, tracepoint, and generic syscall macro roots generated by `common/probes.h`; their event-specific tail handlers are populated from the Go event definition tables

### Spot-check

The raw syscall-enter root `tracepoint__raw_syscalls__sys_enter` tail-calls through `sys_enter_init_tail[id]` at `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/c/tracee.bpf.c:58`. `sys_enter_init` then dispatches to either `sys_enter_submit_tail[id]` or `sys_enter_tails[sys->id]` at `tracee.bpf.c:128` and `tracee.bpf.c:131`. Userspace inserts the selected program fd into the requested map/index in `/tmp/bpf-tailcall-src/tracee/pkg/ebpf/tracee.go:738` through `tracee.go:767`; examples are `sys_enter_tails[Execve] -> syscall__execve_enter` at `pkg/events/core.go:1965` and `sys_enter_tails[InitModule] -> syscall__init_module` at `core.go:14011`.

## otel

### Tail-call edges

OTEL has `perf_progs` in `support/ebpf/interpreter_dispatcher.ebpf.c:29` and `kprobe_progs` in `support/ebpf/off_cpu.ebpf.c:7`. Tail-call keys are the `PROG_*` enum in `support/ebpf/types.h:345`: stop=0, native=1, hotspot=2, perl=3, python=4, php=5, ruby=6, v8=7, dotnet=8, dotnet10=9, go labels=10, beam=11.

Userspace declares tail target names and ids in `tracer/tracer.go:391` through `tracer.go:450`, loads `perf_` prefixed targets into `perf_progs` at `tracer.go:699` through `tracer.go:743`, loads rewritten `kprobe_` targets at `tracer.go:768` through `tracer.go:806`, and updates the prog-array slot in `loadProgram()` at `tracer.go:811` through `tracer.go:847`.

| caller program (SEC name) | call site (file:line) | prog_array map | key | callee program | confidence |
|---|---|---|---|---|---|
| `native_tracer_entry` (`perf_event/native_tracer_entry`) | `runner/repos/opentelemetry-ebpf-profiler/support/ebpf/tracemgmt.h:760` | `perf_progs` | `PROG_UNWIND_STOP` = 0 | `perf_unwind_stop` (`unwind_stop`) | symbolic |
| `native_tracer_entry` (`perf_event/native_tracer_entry`) via `collect_trace` | `runner/repos/opentelemetry-ebpf-profiler/support/ebpf/tracemgmt.h:783` | `perf_progs` | `unwinder` from native-frame dispatch | `perf_unwind_stop`, `perf_unwind_native`, `perf_unwind_hotspot`, `perf_unwind_perl`, `perf_unwind_python`, `perf_unwind_php`, `perf_unwind_ruby`, `perf_unwind_v8`, `perf_unwind_dotnet`, `perf_unwind_dotnet10`, `perf_unwind_beam` | dynamic |
| `perf_unwind_native` (`perf_event/unwind_native`) | `runner/repos/opentelemetry-ebpf-profiler/support/ebpf/native_stack_trace.ebpf.c:580` | `perf_progs` | `unwinder` | next enabled unwinder or `perf_unwind_stop` | dynamic |
| `perf_unwind_native` (`perf_event/unwind_native`) | `runner/repos/opentelemetry-ebpf-profiler/support/ebpf/native_stack_trace.ebpf.c:593` | `perf_progs` | `unwinder` | next enabled unwinder or `perf_unwind_stop` | dynamic |
| `perf_unwind_python` (`perf_event/unwind_python`) | `runner/repos/opentelemetry-ebpf-profiler/support/ebpf/python_tracer.ebpf.c:334` | `perf_progs` | `unwinder` | `perf_unwind_native`, self/next interpreter, or `perf_unwind_stop` | dynamic |
| `perf_unwind_php` (`perf_event/unwind_php`) | `runner/repos/opentelemetry-ebpf-profiler/support/ebpf/php_tracer.ebpf.c:263` | `perf_progs` | `unwinder` | `perf_unwind_native`, self/next interpreter, or `perf_unwind_stop` | dynamic |
| `perf_unwind_ruby` (`perf_event/unwind_ruby`) | `runner/repos/opentelemetry-ebpf-profiler/support/ebpf/ruby_tracer.ebpf.c:560` | `perf_progs` | `unwinder` | `perf_unwind_native`, self/next interpreter, or `perf_unwind_stop` | dynamic |
| `perf_unwind_perl` (`perf_event/unwind_perl`) | `runner/repos/opentelemetry-ebpf-profiler/support/ebpf/perl_tracer.ebpf.c:440` | `perf_progs` | `unwinder` | `perf_unwind_native`, self/next interpreter, or `perf_unwind_stop` | dynamic |
| `perf_unwind_hotspot` (`perf_event/unwind_hotspot`) | `runner/repos/opentelemetry-ebpf-profiler/support/ebpf/hotspot_tracer.ebpf.c:956` | `perf_progs` | `unwinder` | `perf_unwind_native`, self/next interpreter, or `perf_unwind_stop` | dynamic |
| `perf_unwind_v8` (`perf_event/unwind_v8`) | `runner/repos/opentelemetry-ebpf-profiler/support/ebpf/v8_tracer.ebpf.c:349` | `perf_progs` | `unwinder` | `perf_unwind_native`, self/next interpreter, or `perf_unwind_stop` | dynamic |
| `perf_unwind_dotnet` (`perf_event/unwind_dotnet`) | `runner/repos/opentelemetry-ebpf-profiler/support/ebpf/dotnet_tracer.ebpf.c:460` | `perf_progs` | `unwinder` | `perf_unwind_native`, self/next interpreter, or `perf_unwind_stop` | dynamic |
| `perf_unwind_dotnet10` (`perf_event/unwind_dotnet10`) | `runner/repos/opentelemetry-ebpf-profiler/support/ebpf/dotnet_tracer.ebpf.c:460` | `perf_progs` | `unwinder` | `perf_unwind_native`, self/next interpreter, or `perf_unwind_stop` | dynamic |
| `perf_unwind_beam` (`perf_event/unwind_beam`) | `runner/repos/opentelemetry-ebpf-profiler/support/ebpf/beam_tracer.ebpf.c:236` | `perf_progs` | `unwinder` | `perf_unwind_native`, self/next interpreter, or `perf_unwind_stop` | dynamic |
| `perf_unwind_stop` (`perf_event/unwind_stop`) | `runner/repos/opentelemetry-ebpf-profiler/support/ebpf/interpreter_dispatcher.ebpf.c:188` | `perf_progs` | `PROG_GO_LABELS` = 10 | `perf_go_labels` | symbolic |
| `kprobe_dummy` (`kprobe/dummy`) | `runner/repos/opentelemetry-ebpf-profiler/support/ebpf/off_cpu.ebpf.c:55` | `kprobe_progs` | `0` | `kprobe_unwind_stop` slot 0 in rewritten kprobe unwinder map | static |

Target mapping from `tracer/tracer.go:391`:

| key | perf target | kprobe target |
|---|---|---|
| `PROG_UNWIND_STOP` = 0 | `perf_unwind_stop` | `kprobe_unwind_stop` |
| `PROG_UNWIND_NATIVE` = 1 | `perf_unwind_native` | `kprobe_unwind_native` |
| `PROG_UNWIND_HOTSPOT` = 2 | `perf_unwind_hotspot` | `kprobe_unwind_hotspot` |
| `PROG_UNWIND_PERL` = 3 | `perf_unwind_perl` | `kprobe_unwind_perl` |
| `PROG_UNWIND_PYTHON` = 4 | `perf_unwind_python` | `kprobe_unwind_python` |
| `PROG_UNWIND_PHP` = 5 | `perf_unwind_php` | `kprobe_unwind_php` |
| `PROG_UNWIND_RUBY` = 6 | `perf_unwind_ruby` | `kprobe_unwind_ruby` |
| `PROG_UNWIND_V8` = 7 | `perf_unwind_v8` | `kprobe_unwind_v8` |
| `PROG_UNWIND_DOTNET` = 8 | `perf_unwind_dotnet` | `kprobe_unwind_dotnet` |
| `PROG_UNWIND_DOTNET10` = 9 | `perf_unwind_dotnet10` | `kprobe_unwind_dotnet10` |
| `PROG_GO_LABELS` = 10 | `perf_go_labels` | `kprobe_go_labels` |
| `PROG_UNWIND_BEAM` = 11 | `perf_unwind_beam` | `kprobe_unwind_beam` |

### Direct-attached entry points

- `perf_event/native_tracer_entry`: `native_tracer_entry` is the primary CPU profiler root. Runtime under all `perf_unwind_*` descendants is charged to this caller.
- `kprobe/finish_task_switch`: off-CPU root in `support/ebpf/off_cpu.ebpf.c`.
- Other roots without this tail chain include process-monitoring and system-configuration tracepoints/kprobes in the support tree.
- `perf_event/unwind_*` and `kprobe/unwind_*` generated by `MULTI_USE_FUNC` are tail-call targets in the profiler chain; they should not be treated as independent direct roots for this propagation purpose unless loaded/attached separately in a different mode.

### Spot-check

`native_tracer_entry` is declared at `runner/repos/opentelemetry-ebpf-profiler/support/ebpf/native_stack_trace.ebpf.c:598` and calls `collect_trace()`. `collect_trace()` chooses an unwinder and calls `tail_call(ctx, unwinder)` at `support/ebpf/tracemgmt.h:779` through `tracemgmt.h:783`; `tail_call()` dispatches through `perf_progs` at `tracemgmt.h:563`. Userspace resolves `PROG_UNWIND_PYTHON=4` to `perf_unwind_python` in `tracer/tracer.go:418` through `tracer.go:420`, and updates the prog-array slot in `tracer.go:845` through `tracer.go:847`.

## katran

### Tail-call edges

Katran has two relevant prog arrays: `root_array` in `xdp_root.c` for shared-mode XDP chaining, and `subprograms` in `control_data_maps.h` for inline decapsulation recirculation. Current corpus notes say Katran now uses standalone attach mode for `balancer_ingress`, so the `xdp_root -> balancer_ingress` edge is a source-level edge but should not be used as the benchmark's root in standalone mode.

| caller program (SEC name) | call site (file:line) | prog_array map | key | callee program | confidence |
|---|---|---|---|---|---|
| `xdp_root` (`xdp`) | `runner/repos/katran/katran/lib/bpf/xdp_root.c:34` | `root_array` | loop `i = 0..2` | runtime-loaded program in root slot; corpus/shared example uses `balancer_ingress` | dynamic |
| userspace shared-mode insertion | `runner/repos/katran/katran/lib/KatranLb.cpp:926` | `root_array` | `rootMapPos` (`--prog_pos`, example default 2) | `balancer_ingress` fd | dynamic |
| `recirculate` helper, reachable from `balancer_ingress` when `INLINE_DECAP_GENERIC` is enabled | `runner/repos/katran/katran/lib/bpf/balancer_helpers.h:79` | `subprograms` | `RECIRCULATION_INDEX` | `balancer_ingress` | symbolic |
| userspace recirculation insertion | `runner/repos/katran/katran/lib/KatranLb.cpp:698` | `subprograms` | `RECIRCULATION_INDEX` | `balancer_ingress` fd | symbolic |

No `bpf_tail_call` sites were found in `healthchecking_ipip.c` or `healthchecking.bpf.c`; `healthcheck_encap` is a direct `tc` root at `runner/repos/katran/katran/lib/bpf/healthchecking.bpf.c:37`.

### Direct-attached entry points

- `xdp`: `balancer_ingress` from `balancer.bpf.c` (`SEC(PROG_SEC_NAME)`, default `PROG_SEC_NAME="xdp"`); this is the benchmark root in standalone mode.
- `xdp`: `xdp_root` from `xdp_root.c`; shared-mode bootstrap/root only.
- `tc`: `healthcheck_encap` from `healthchecking_ipip.c` and `healthchecking.bpf.c`.
- `xdp`: `xdp_pktcntr` if the optional packet-counter object is loaded.

### Spot-check

`xdp_root` declares `root_array` at `runner/repos/katran/katran/lib/bpf/xdp_root.c:22` and loops over slots 0..2 with `bpf_tail_call(ctx, &root_array, i)` at `xdp_root.c:29` through `xdp_root.c:35`. Userspace fills the selected root slot with the main program fd at `runner/repos/katran/katran/lib/KatranLb.cpp:926`. In standalone corpus mode, `balancer_ingress` is attached directly instead, so propagation should start from `balancer_ingress`, not `xdp_root`.

## bpftrace

### Tail-call edges

No tail-call edges were found in current upstream bpftrace codegen source. The requested path `src/ast/passes/codegen_llvm/*.cpp` is outdated; current upstream has `src/ast/passes/codegen_llvm.cpp` and `.h`. Grepping these files found no `bpf_tail_call`, `tail_call`, `BPF_FUNC_tail_call`, `BPF_MAP_TYPE_PROG_ARRAY`, or `SEC(...)` tail-call machinery.

| caller program (SEC name) | call site (file:line) | prog_array map | key | callee program | confidence |
|---|---|---|---|---|---|
| none found | n/a | n/a | n/a | n/a | n/a |

### Direct-attached entry points

- bpftrace direct roots are generated per script/probe by codegen. `CodegenLLVM::generateProbe()` sets the generated program section with `func->setSection(util::get_section_name(func_name))` at `/tmp/bpf-tailcall-src/bpftrace/src/ast/passes/codegen_llvm.cpp:3361`.
- No static tail-call target set exists in this codegen path.

### Spot-check

The codegen scan found no tail-call helpers or prog-array declarations in `/tmp/bpf-tailcall-src/bpftrace/src/ast/passes/codegen_llvm.cpp` or `.h`. The relevant direct-attach code path is the generated probe section assignment at `codegen_llvm.cpp:3361`.

## bcc

### Tail-call edges

No actual BPF tail-call sites were found in the sparse upstream BCC checkout under `tools`, `libbpf-tools`, or `examples`. Grep hits were limited to a README mention and generated `vmlinux_*.h` enum constants for `BPF_MAP_TYPE_PROG_ARRAY`; no BPF source used `bpf_tail_call` or declared a live prog-array dispatch graph in the scanned corpus roots.

| caller program (SEC name) | call site (file:line) | prog_array map | key | callee program | confidence |
|---|---|---|---|---|---|
| none found | n/a | n/a | n/a | n/a | n/a |

### Direct-attached entry points

- BCC corpus programs are per-tool direct kprobe/tracepoint/perf/usdt/fentry-style programs, often generated from embedded C or libbpf-tools sources.
- No static tail-call target-only programs were found in the scanned BCC source roots.

### Spot-check

`rg` for `bpf_tail_call`, `tail_call(`, and `BPF_MAP_TYPE_PROG_ARRAY` under `/tmp/bpf-tailcall-src/bcc/tools`, `/tmp/bpf-tailcall-src/bcc/libbpf-tools`, and `/tmp/bpf-tailcall-src/bcc/examples` found no code call sites. The only non-generated-source hit was `/tmp/bpf-tailcall-src/bcc/examples/networking/tunnel_monitor/README.md:7`, which is documentation text, not a BPF program edge.

