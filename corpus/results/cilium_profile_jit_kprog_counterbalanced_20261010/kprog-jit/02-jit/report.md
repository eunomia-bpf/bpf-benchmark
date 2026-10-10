# Cilium jit profile: kprog-jit/02-jit

Order: `kprog-jit`, position: 2; corpus run: `corpus/results/x86_kvm_corpus_20261010_140938_389097`; selected phase: `baseline`.

| Metric | Value |
| --- | ---: |
| cycles/packet | 5326.072 |
| instructions/packet | 12568.547 |
| IPC | 2.360 |
| branches/packet | 2298.683 |
| branch misses/packet | 2.640238 |
| branch miss rate | 0.114859% |
| cache misses/packet | 4.652043 |
| BPF runs/packet | 1.000 |
| active BPF programs | 8 / 51 |
| analyzed call-graph samples | 121138 / 491391 raw |
| excluded idle samples | 370253 |
| unresolved samples | 0 |
| samples with LBR context | 0 / 121138 (0.000%) |

## Resolved non-idle context-attributed cost per packet

Each resolved, non-idle sample is assigned to the first datapath class in its frame-pointer context. This places spin-lock frames reached through `htab_lru_map_update_elem` or `bpf_common_lru_pop_free` under maps. Values are fixed-period sampled guest CPU nanoseconds.

| Category | Samples | Fraction | Estimated guest ns/packet |
| --- | ---: | ---: | ---: |
| bpf_code | 13477 | 11.125% | 159.346 |
| helpers | 7323 | 6.045% | 86.584 |
| maps | 31751 | 26.211% | 375.410 |
| rest | 68587 | 56.619% | 810.944 |

## Top symbols

| Symbol | Category | Samples |
| --- | --- | ---: |
| `lookup_nulls_elem_raw` | maps | 23288 |
| `fib_table_lookup` | rest | 7538 |
| `pktgen_mark_device` | rest | 6384 |
| `pvclock_clocksource_read_nowd` | rest | 5837 |
| `bpf_prog_4c9130241f09acf5_tail_ipv4_ct_egress` | bpf_code | 5715 |
| `bpf_prog_52497018fcb6fd94_cil_lxc_policy` | bpf_code | 5237 |
| `_raw_spin_unlock_irq` | rest | 4462 |
| `jhash` | maps | 2432 |
| `fib_lookup_good_nhc` | rest | 2353 |
| `__rcu_read_lock` | rest | 2310 |
| `enqueue_to_backlog` | rest | 1993 |
| `htab_map_hash` | maps | 1947 |
| `enqueue_to_backlog` | helpers | 1888 |
| `__mkroute_output` | rest | 1623 |
| `memcmp` | maps | 1458 |
| `__alloc_skb` | rest | 1431 |
| `__icmp_send` | rest | 1429 |
| `handle_softirqs` | rest | 1407 |
| `__skb_flow_dissect` | rest | 1400 |
| `trie_lookup_elem` | maps | 1342 |

## Per-program BPF counters

| ID | Program | Attach point(s) | Runs | ns/run | JIT bytes |
| ---: | --- | --- | ---: | ---: | ---: |
| 111 | `cil_xdp_entry` | xdp:bpfbench0:driver | 2 | 878.500 | 509 |
| 112 | `cil_from_host` | tc:cilium_host:tcx/egress | 2 | 1655.000 | 3945 |
| 122 | `cil_to_host` | tc:cilium_host:tcx/ingress | 2 | 1168.500 | 859 |
| 134 | `cil_to_host` | tc:cilium_net:tcx/ingress | 2 | 956.000 | 859 |
| 135 | `cil_to_netdev` | tc:bpfbench0:tcx/egress | 2 | 1743.500 | 5222 |
| 142 | `cil_from_netdev` | tc:bpfbench0:tcx/ingress | 2 | 1589.500 | 3386 |
| 150 | `cil_from_contai` | tc:lxcbench0:tcx/ingress | 42288650 | 611.415 | 1089 |
| 168 | `cil_from_contai` | tc:lxcbench1:tcx/ingress | 42288275 | 604.105 | 1089 |
