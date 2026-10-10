# Cilium kprog profile: jit-kprog/02-kprog

Order: `jit-kprog`, position: 2; corpus run: `corpus/results/x86_kvm_corpus_20261010_135905_293120`; selected phase: `post_rejit`.

| Metric | Value |
| --- | ---: |
| cycles/packet | 4560.677 |
| instructions/packet | 12201.885 |
| IPC | 2.675 |
| branches/packet | 2302.589 |
| branch misses/packet | 1.763710 |
| branch miss rate | 0.076597% |
| cache misses/packet | 6.643630 |
| BPF runs/packet | 1.000 |
| active BPF programs | 7 / 51 |
| analyzed call-graph samples | 120197 / 491349 raw |
| excluded idle samples | 371152 |
| unresolved samples | 0 |
| samples with LBR context | 0 / 120197 (0.000%) |

## Resolved non-idle context-attributed cost per packet

Each resolved, non-idle sample is assigned to the first datapath class in its frame-pointer context. This places spin-lock frames reached through `htab_lru_map_update_elem` or `bpf_common_lru_pop_free` under maps. Values are fixed-period sampled guest CPU nanoseconds.

| Category | Samples | Fraction | Estimated guest ns/packet |
| --- | ---: | ---: | ---: |
| bpf_code | 9024 | 7.508% | 91.308 |
| helpers | 8295 | 6.901% | 83.932 |
| maps | 25913 | 21.559% | 262.197 |
| rest | 76965 | 64.032% | 778.760 |

## Top symbols

| Symbol | Category | Samples |
| --- | --- | ---: |
| `lookup_nulls_elem_raw` | maps | 19282 |
| `fib_table_lookup` | rest | 7645 |
| `pvclock_clocksource_read_nowd` | rest | 6556 |
| `_raw_spin_unlock_irq` | rest | 4875 |
| `mod_cur_headers` | rest | 3531 |
| `bpf_prog_f4e1f23a14f9f66e_cil_lxc_policy` | bpf_code | 3165 |
| `fib_lookup_good_nhc` | rest | 2962 |
| `bpf_prog_ca1f00b91b95a464_tail_ipv4_ct_eg` | bpf_code | 2854 |
| `__rcu_read_lock` | rest | 2755 |
| `htab_map_hash` | maps | 2341 |
| `enqueue_to_backlog` | rest | 2239 |
| `pktgen_thread_worker` | rest | 2138 |
| `enqueue_to_backlog` | helpers | 2118 |
| `__mkroute_output` | rest | 2019 |
| `__alloc_skb` | rest | 1677 |
| `__icmp_send` | rest | 1601 |
| `trie_lookup_elem` | maps | 1585 |
| `__inet_dev_addr_type` | rest | 1578 |
| `__xfrm_decode_session` | rest | 1561 |
| `__skb_flow_dissect` | rest | 1510 |

## Per-program BPF counters

| ID | Program | Attach point(s) | Runs | ns/run | JIT bytes |
| ---: | --- | --- | ---: | ---: | ---: |
| 409 | `cil_xdp_entry` | xdp:bpfbench0:driver | 1 | 1090.000 | 1175 |
| 429 | `cil_from_host` | tc:cilium_host:tcx/egress | 1 | 1584.000 | 7000 |
| 467 | `cil_from_contai` | tc:lxcbench0:tcx/ingress | 50261430 | 387.703 | 2450 |
| 500 | `cil_to_host` | tc:cilium_net:tcx/ingress | 1 | 1116.000 | 3675 |
| 501 | `cil_from_contai` | tc:lxcbench1:tcx/ingress | 48568910 | 424.044 | 2450 |
| 541 | `cil_from_netdev` | tc:bpfbench0:tcx/ingress | 1 | 1464.000 | 6482 |
| 547 | `cil_to_netdev` | tc:bpfbench0:tcx/egress | 1 | 1897.000 | 6350 |

## Live-program JIT versus whole-program native image size

Only native IDs reachable from the measured XDP/TCX roots are included; stale measured IDs and earlier lifecycle replacements are excluded.

| Original ID | Native ID | Symbol | JIT bytes | Native blob bytes | Native stub image bytes |
| ---: | ---: | --- | ---: | ---: | ---: |
| **total (51 live)** |  |  | **233646** | **257161** | **258579** |
| 408 | 409 | `cil_xdp_entry` | 509 | 1161 | 1175 |
| 412 | 413 | `tail_ipv4_policy` | 5580 | 7252 | 7282 |
| 410 | 415 | `cil_host_policy` | 16 | 2 | 16 |
| 416 | 420 | `tail_no_service_ipv4` | 2774 | 2211 | 2241 |
| 418 | 423 | `tail_handle_ipv4_from_netdev` | 8254 | 8247 | 8277 |
| 421 | 425 | `tail_ipv4_ct_egress` | 5375 | 6431 | 6461 |
| 424 | 429 | `cil_from_host` | 3945 | 6970 | 7000 |
| 428 | 431 | `tail_handle_ipv4_cont` | 6398 | 9133 | 9163 |
| 433 | 435 | `tail_nodeport_rev_dnat_ipv4` | 3622 | 3403 | 3433 |
| 434 | 441 | `tail_handle_snat_fwd_ipv4` | 12954 | 12917 | 12947 |
| 444 | 446 | `tail_ipv4_ct_ingress` | 5210 | 4982 | 5012 |
| 443 | 449 | `cil_to_host` | 859 | 3645 | 3675 |
| 454 | 458 | `cil_lxc_policy` | 5760 | 5545 | 5575 |
| 459 | 461 | `tail_drop_notify` | 382 | 805 | 819 |
| 456 | 463 | `tail_handle_ipv4_from_host` | 1262 | 1220 | 1250 |
| 462 | 467 | `cil_from_container` | 1089 | 2420 | 2450 |
| 465 | 469 | `tail_nodeport_nat_egress_ipv4` | 6566 | 5945 | 5975 |
| 468 | 473 | `tail_ipv4_to_endpoint` | 5802 | 7070 | 7100 |
| 472 | 477 | `tail_nodeport_nat_ingress_ipv4` | 8881 | 8283 | 8313 |
| 476 | 481 | `tail_handle_ipv4` | 6216 | 6090 | 6120 |
| 478 | 483 | `tail_drop_notify` | 405 | 828 | 842 |
| 482 | 486 | `tail_handle_arp` | 927 | 742 | 772 |
| 489 | 491 | `tail_handle_ipv4_cont` | 6398 | 9133 | 9163 |
| 492 | 494 | `cil_lxc_policy` | 5760 | 5545 | 5575 |
| 493 | 496 | `tail_handle_snat_fwd_ipv4` | 12981 | 12917 | 12947 |
| 495 | 498 | `tail_drop_notify` | 382 | 805 | 819 |
| 497 | 500 | `cil_to_host` | 859 | 3645 | 3675 |
| 499 | 501 | `cil_from_container` | 1089 | 2420 | 2450 |
| 502 | 506 | `tail_handle_ipv4_from_netdev` | 8242 | 8247 | 8277 |
| 505 | 508 | `tail_ipv4_policy` | 5580 | 7252 | 7282 |
| 510 | 512 | `tail_handle_ipv4` | 6216 | 6090 | 6120 |
| 511 | 514 | `tail_no_service_ipv4` | 2792 | 2239 | 2269 |
| 513 | 516 | `tail_ipv4_ct_egress` | 5375 | 6431 | 6461 |
| 519 | 522 | `tail_nodeport_nat_egress_ipv4` | 6566 | 5945 | 5975 |
| 521 | 524 | `tail_ipv4_to_endpoint` | 5802 | 7070 | 7100 |
| 525 | 527 | `tail_no_service_ipv4` | 2774 | 2211 | 2241 |
| 528 | 530 | `tail_handle_arp` | 927 | 742 | 772 |
| 529 | 532 | `tail_nodeport_nat_ingress_ipv4` | 8881 | 8283 | 8313 |
| 531 | 534 | `tail_ipv4_ct_ingress` | 5210 | 4982 | 5012 |
| 533 | 536 | `tail_drop_notify` | 405 | 828 | 842 |
| 535 | 538 | `tail_nodeport_rev_dnat_ipv4` | 3622 | 3403 | 3433 |
| 537 | 539 | `tail_handle_ipv4_from_host` | 1262 | 1220 | 1250 |
| 540 | 541 | `cil_from_netdev` | 3386 | 6452 | 6482 |
| 542 | 543 | `tail_handle_ipv4_from_host` | 1262 | 1220 | 1250 |
| 546 | 547 | `cil_to_netdev` | 5222 | 6320 | 6350 |
| 548 | 549 | `tail_no_service_ipv4` | 2792 | 2239 | 2269 |
| 550 | 551 | `tail_nodeport_nat_ingress_ipv4` | 8881 | 8283 | 8313 |
| 552 | 553 | `tail_handle_ipv4_from_netdev` | 8242 | 8247 | 8277 |
| 554 | 555 | `tail_drop_notify` | 405 | 828 | 842 |
| 556 | 557 | `tail_handle_snat_fwd_ipv4` | 12981 | 12917 | 12947 |
| 560 | 561 | `tail_nodeport_nat_egress_ipv4` | 6566 | 5945 | 5975 |
