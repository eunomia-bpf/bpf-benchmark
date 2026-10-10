# Cilium kprog profile: kprog-jit/01-kprog

Order: `kprog-jit`, position: 1; corpus run: `corpus/results/x86_kvm_corpus_20261010_140420_544041`; selected phase: `post_rejit`.

| Metric | Value |
| --- | ---: |
| cycles/packet | 4463.253 |
| instructions/packet | 12230.122 |
| IPC | 2.740 |
| branches/packet | 2307.016 |
| branch misses/packet | 1.734653 |
| branch miss rate | 0.075190% |
| cache misses/packet | 6.334797 |
| BPF runs/packet | 1.000 |
| active BPF programs | 7 / 51 |
| analyzed call-graph samples | 120059 / 491447 raw |
| excluded idle samples | 371388 |
| unresolved samples | 0 |
| samples with LBR context | 0 / 120059 (0.000%) |

## Resolved non-idle context-attributed cost per packet

Each resolved, non-idle sample is assigned to the first datapath class in its frame-pointer context. This places spin-lock frames reached through `htab_lru_map_update_elem` or `bpf_common_lru_pop_free` under maps. Values are fixed-period sampled guest CPU nanoseconds.

| Category | Samples | Fraction | Estimated guest ns/packet |
| --- | ---: | ---: | ---: |
| bpf_code | 8840 | 7.363% | 87.677 |
| helpers | 8492 | 7.073% | 84.226 |
| maps | 24193 | 20.151% | 239.952 |
| rest | 78534 | 65.413% | 778.920 |

## Top symbols

| Symbol | Category | Samples |
| --- | --- | ---: |
| `lookup_nulls_elem_raw` | maps | 17280 |
| `fib_table_lookup` | rest | 7715 |
| `pvclock_clocksource_read_nowd` | rest | 6741 |
| `_raw_spin_unlock_irq` | rest | 4905 |
| `mod_cur_headers` | rest | 3343 |
| `bpf_prog_f4e1f23a14f9f66e_cil_lxc_policy` | bpf_code | 3153 |
| `__rcu_read_lock` | rest | 3130 |
| `bpf_prog_ca1f00b91b95a464_tail_ipv4_ct_eg` | bpf_code | 2780 |
| `fib_lookup_good_nhc` | rest | 2653 |
| `enqueue_to_backlog` | rest | 2444 |
| `pktgen_thread_worker` | rest | 2425 |
| `htab_map_hash` | maps | 2419 |
| `enqueue_to_backlog` | helpers | 2278 |
| `__mkroute_output` | rest | 1973 |
| `__alloc_skb` | rest | 1945 |
| `__inet_dev_addr_type` | rest | 1890 |
| `__skb_flow_dissect` | rest | 1806 |
| `__rcu_read_unlock` | rest | 1732 |
| `__xfrm_decode_session` | rest | 1634 |
| `__icmp_send` | rest | 1594 |

## Per-program BPF counters

| ID | Program | Attach point(s) | Runs | ns/run | JIT bytes |
| ---: | --- | --- | ---: | ---: | ---: |
| 409 | `cil_xdp_entry` | xdp:bpfbench0:driver | 1 | 884.000 | 1175 |
| 460 | `cil_from_host` | tc:cilium_host:tcx/egress | 1 | 2593.000 | 7000 |
| 469 | `cil_from_contai` | tc:lxcbench0:tcx/ingress | 50021847 | 392.625 | 2450 |
| 514 | `cil_from_contai` | tc:lxcbench1:tcx/ingress | 50802521 | 370.969 | 2450 |
| 534 | `cil_to_host` | tc:cilium_net:tcx/ingress | 1 | 1265.000 | 3675 |
| 542 | `cil_to_netdev` | tc:bpfbench0:tcx/egress | 1 | 1493.000 | 6350 |
| 545 | `cil_from_netdev` | tc:bpfbench0:tcx/ingress | 1 | 869.000 | 6482 |

## Live-program JIT versus whole-program native image size

Only native IDs reachable from the measured XDP/TCX roots are included; stale measured IDs and earlier lifecycle replacements are excluded.

| Original ID | Native ID | Symbol | JIT bytes | Native blob bytes | Native stub image bytes |
| ---: | ---: | --- | ---: | ---: | ---: |
| **total (51 live)** |  |  | **233646** | **257161** | **258579** |
| 408 | 409 | `cil_xdp_entry` | 509 | 1161 | 1175 |
| 410 | 413 | `tail_nodeport_rev_dnat_ipv4` | 3622 | 3403 | 3433 |
| 412 | 417 | `tail_handle_ipv4_from_netdev` | 8254 | 8247 | 8277 |
| 420 | 424 | `tail_no_service_ipv4` | 2774 | 2211 | 2241 |
| 425 | 429 | `cil_lxc_policy` | 5760 | 5545 | 5575 |
| 426 | 431 | `tail_nodeport_nat_ingress_ipv4` | 8881 | 8283 | 8313 |
| 430 | 434 | `tail_ipv4_ct_egress` | 5375 | 6431 | 6461 |
| 436 | 439 | `tail_ipv4_policy` | 5580 | 7252 | 7282 |
| 435 | 441 | `tail_handle_snat_fwd_ipv4` | 12954 | 12917 | 12947 |
| 442 | 447 | `tail_handle_ipv4_from_host` | 1262 | 1220 | 1250 |
| 446 | 449 | `tail_ipv4_ct_ingress` | 5210 | 4982 | 5012 |
| 448 | 453 | `tail_drop_notify` | 405 | 828 | 842 |
| 450 | 454 | `tail_handle_arp` | 927 | 742 | 772 |
| 456 | 459 | `tail_drop_notify` | 382 | 805 | 819 |
| 455 | 460 | `cil_from_host` | 3945 | 6970 | 7000 |
| 462 | 465 | `tail_handle_ipv4` | 6216 | 6090 | 6120 |
| 461 | 466 | `cil_host_policy` | 16 | 2 | 16 |
| 467 | 469 | `cil_from_container` | 1089 | 2420 | 2450 |
| 471 | 475 | `tail_handle_ipv4_cont` | 6398 | 9133 | 9163 |
| 474 | 477 | `cil_to_host` | 859 | 3645 | 3675 |
| 476 | 481 | `tail_ipv4_to_endpoint` | 5802 | 7070 | 7100 |
| 479 | 482 | `tail_nodeport_nat_egress_ipv4` | 6566 | 5945 | 5975 |
| 485 | 488 | `tail_nodeport_nat_egress_ipv4` | 6566 | 5945 | 5975 |
| 495 | 496 | `tail_handle_arp` | 927 | 742 | 772 |
| 494 | 498 | `tail_no_service_ipv4` | 2792 | 2239 | 2269 |
| 497 | 500 | `tail_no_service_ipv4` | 2774 | 2211 | 2241 |
| 499 | 502 | `tail_handle_snat_fwd_ipv4` | 12981 | 12917 | 12947 |
| 501 | 504 | `tail_ipv4_to_endpoint` | 5802 | 7070 | 7100 |
| 505 | 506 | `tail_nodeport_rev_dnat_ipv4` | 3622 | 3403 | 3433 |
| 508 | 510 | `tail_ipv4_policy` | 5580 | 7252 | 7282 |
| 509 | 512 | `tail_nodeport_nat_ingress_ipv4` | 8881 | 8283 | 8313 |
| 511 | 514 | `cil_from_container` | 1089 | 2420 | 2450 |
| 513 | 516 | `tail_handle_ipv4_from_netdev` | 8242 | 8247 | 8277 |
| 515 | 517 | `tail_ipv4_ct_ingress` | 5210 | 4982 | 5012 |
| 519 | 520 | `tail_drop_notify` | 382 | 805 | 819 |
| 518 | 522 | `tail_handle_ipv4_from_host` | 1262 | 1220 | 1250 |
| 523 | 524 | `tail_drop_notify` | 405 | 828 | 842 |
| 521 | 525 | `tail_handle_ipv4_cont` | 6398 | 9133 | 9163 |
| 527 | 530 | `tail_handle_ipv4` | 6216 | 6090 | 6120 |
| 529 | 534 | `cil_to_host` | 859 | 3645 | 3675 |
| 535 | 538 | `tail_nodeport_nat_ingress_ipv4` | 8881 | 8283 | 8313 |
| 537 | 540 | `tail_ipv4_ct_egress` | 5375 | 6431 | 6461 |
| 539 | 542 | `cil_to_netdev` | 5222 | 6320 | 6350 |
| 541 | 544 | `cil_lxc_policy` | 5760 | 5545 | 5575 |
| 543 | 545 | `cil_from_netdev` | 3386 | 6452 | 6482 |
| 550 | 551 | `tail_handle_ipv4_from_netdev` | 8242 | 8247 | 8277 |
| 552 | 553 | `tail_nodeport_nat_egress_ipv4` | 6566 | 5945 | 5975 |
| 554 | 555 | `tail_no_service_ipv4` | 2792 | 2239 | 2269 |
| 556 | 557 | `tail_handle_ipv4_from_host` | 1262 | 1220 | 1250 |
| 558 | 559 | `tail_drop_notify` | 405 | 828 | 842 |
| 560 | 561 | `tail_handle_snat_fwd_ipv4` | 12981 | 12917 | 12947 |
