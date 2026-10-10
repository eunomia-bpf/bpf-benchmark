# Cilium jit profile: jit-kprog/01-jit

Order: `jit-kprog`, position: 1; corpus run: `corpus/results/x86_kvm_corpus_20261010_135459_510211`; selected phase: `baseline`.

| Metric | Value |
| --- | ---: |
| cycles/packet | 5119.152 |
| instructions/packet | 12571.090 |
| IPC | 2.456 |
| branches/packet | 2296.618 |
| branch misses/packet | 2.468274 |
| branch miss rate | 0.107474% |
| cache misses/packet | 4.505008 |
| BPF runs/packet | 1.000 |
| active BPF programs | 8 / 51 |
| analyzed call-graph samples | 121652 / 491367 raw |
| excluded idle samples | 369715 |
| unresolved samples | 0 |
| samples with LBR context | 0 / 121652 (0.000%) |

## Resolved non-idle context-attributed cost per packet

Each resolved, non-idle sample is assigned to the first datapath class in its frame-pointer context. This places spin-lock frames reached through `htab_lru_map_update_elem` or `bpf_common_lru_pop_free` under maps. Values are fixed-period sampled guest CPU nanoseconds.

| Category | Samples | Fraction | Estimated guest ns/packet |
| --- | ---: | ---: | ---: |
| bpf_code | 11925 | 9.803% | 135.548 |
| helpers | 7514 | 6.177% | 85.409 |
| maps | 31364 | 25.782% | 356.504 |
| rest | 70849 | 58.239% | 805.317 |

## Top symbols

| Symbol | Category | Samples |
| --- | --- | ---: |
| `lookup_nulls_elem_raw` | maps | 22664 |
| `pktgen_mark_device` | rest | 6494 |
| `fib_table_lookup` | rest | 6419 |
| `pvclock_clocksource_read_nowd` | rest | 6147 |
| `bpf_prog_4c9130241f09acf5_tail_ipv4_ct_egress` | bpf_code | 4836 |
| `bpf_prog_52497018fcb6fd94_cil_lxc_policy` | bpf_code | 4574 |
| `_raw_spin_unlock_irq` | rest | 4545 |
| `__rcu_read_lock` | rest | 2873 |
| `jhash` | maps | 2608 |
| `fib_lookup_good_nhc` | rest | 2365 |
| `enqueue_to_backlog` | rest | 2071 |
| `htab_map_hash` | maps | 2021 |
| `handle_softirqs` | rest | 1960 |
| `enqueue_to_backlog` | helpers | 1916 |
| `__mkroute_output` | rest | 1646 |
| `__rcu_read_unlock` | rest | 1620 |
| `__inet_dev_addr_type` | rest | 1553 |
| `trie_lookup_elem` | maps | 1520 |
| `__skb_flow_dissect` | rest | 1460 |
| `__icmp_send` | rest | 1438 |

## Per-program BPF counters

| ID | Program | Attach point(s) | Runs | ns/run | JIT bytes |
| ---: | --- | --- | ---: | ---: | ---: |
| 111 | `cil_xdp_entry` | xdp:bpfbench0:driver | 2 | 834.000 | 509 |
| 117 | `cil_from_host` | tc:cilium_host:tcx/egress | 2 | 1485.500 | 3945 |
| 119 | `cil_to_host` | tc:cilium_host:tcx/ingress | 2 | 977.500 | 859 |
| 127 | `cil_to_host` | tc:cilium_net:tcx/ingress | 2 | 884.500 | 859 |
| 135 | `cil_from_netdev` | tc:bpfbench0:tcx/ingress | 2 | 1406.000 | 3386 |
| 144 | `cil_to_netdev` | tc:bpfbench0:tcx/egress | 2 | 1358.500 | 5222 |
| 156 | `cil_from_contai` | tc:lxcbench0:tcx/ingress | 43988164 | 559.036 | 1089 |
| 166 | `cil_from_contai` | tc:lxcbench1:tcx/ingress | 43988478 | 557.013 | 1089 |
