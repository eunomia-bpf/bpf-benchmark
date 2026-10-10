# Cilium jit profile

Corpus run: `corpus/results/x86_kvm_corpus_20261010_053047_825216`; selected phase: `baseline`.

| Metric | Value |
| --- | ---: |
| cycles/packet | 9551.225 |
| instructions/packet | 14997.458 |
| IPC | 1.570 |
| branches/packet | 2732.086 |
| branch misses/packet | 4.216881 |
| branch miss rate | 0.154347% |
| cache misses/packet | 8.901780 |
| BPF runs/packet | 1.000 |
| active BPF programs | 8 / 72 |
| analyzed call-graph samples | 113931 / 245625 raw |
| excluded idle samples | 125251 |
| unresolved samples | 6443 |

## Resolved non-idle leaf-sample time per packet

This heuristic classifies each resolved, non-idle sampled leaf by its symbol name; it excludes unresolved leaves and does not attribute inclusive callchain ancestry.

| Category | Samples | Fraction | Estimated CPU ns/packet |
| --- | ---: | ---: | ---: |
| bpf_code | 3701 | 3.248% | 91.988 |
| helpers | 1384 | 1.215% | 34.399 |
| maps | 22816 | 20.026% | 567.087 |
| rest | 86030 | 75.511% | 2138.258 |

## Top symbols

| Symbol | Category | Samples |
| --- | --- | ---: |
| `_raw_spin_unlock_irqrestore` | rest | 28045 |
| `lookup_nulls_elem_raw` | maps | 12620 |
| `htab_lru_map_update_elem` | maps | 5969 |
| `fib_table_lookup` | rest | 5067 |
| `_raw_spin_unlock_irq` | rest | 4771 |
| `enqueue_to_backlog` | rest | 3822 |
| `pvclock_clocksource_read_nowd` | rest | 2723 |
| `__pi_memcpy` | rest | 2439 |
| `jhash` | rest | 2362 |
| `get_random_u32` | rest | 1938 |
| `trie_lookup_elem` | maps | 1848 |
| `handle_softirqs` | rest | 1749 |
| `skb_defer_free_flush` | rest | 1665 |
| `do_softirq` | rest | 1498 |
| `__inet_dev_addr_type` | rest | 1371 |
| `fib_lookup_good_nhc` | rest | 1341 |
| `veth_xmit` | rest | 1326 |
| `__netif_receive_skb_core.constprop.0` | rest | 1282 |
| `__icmp_send` | rest | 1278 |
| `bpf_prog_0c4d509e86c07e4b_tail_handle_ipv4_cont` | bpf_code | 1222 |

## Per-program BPF counters

| ID | Program | Attach point(s) | Runs | ns/run | JIT bytes |
| ---: | --- | --- | ---: | ---: | ---: |
| 153 | `cil_from_contai` | tc:lxcbench0:tcx/ingress | 20118316 | 1527.000 | 1089 |
| 177 | `cil_from_contai` | tc:lxcbench1:tcx/ingress | 20115509 | 1543.511 | 1089 |
| 125 | `cil_xdp_entry` | xdp:bpfbench0:driver | 2 | 866.500 | 509 |
| 128 | `cil_from_host` | tc:cilium_host:tcx/egress | 2 | 1901.000 | 3945 |
| 154 | `cil_to_host` | tc:cilium_host:tcx/ingress | 2 | 1950.000 | 859 |
| 179 | `cil_to_host` | tc:cilium_net:tcx/ingress | 2 | 1067.500 | 859 |
| 192 | `cil_to_netdev` | tc:bpfbench0:tcx/egress | 2 | 1944.000 | 5222 |
| 194 | `cil_from_netdev` | tc:bpfbench0:tcx/ingress | 2 | 1601.500 | 3386 |
