# Cilium kprog profile

Corpus run: `corpus/results/x86_kvm_corpus_20261010_053449_422289`; selected phase: `post_rejit`.

| Metric | Value |
| --- | ---: |
| cycles/packet | 9857.488 |
| instructions/packet | 15207.088 |
| IPC | 1.543 |
| branches/packet | 2872.214 |
| branch misses/packet | 3.393561 |
| branch miss rate | 0.118151% |
| cache misses/packet | 7.087662 |
| BPF runs/packet | 1.000 |
| active BPF programs | 5 / 72 |
| analyzed call-graph samples | 120179 / 245841 raw |
| excluded idle samples | 125513 |
| unresolved samples | 149 |

## Resolved non-idle leaf-sample time per packet

This heuristic classifies each resolved, non-idle sampled leaf by its symbol name; it excludes unresolved leaves and does not attribute inclusive callchain ancestry.

| Category | Samples | Fraction | Estimated CPU ns/packet |
| --- | ---: | ---: | ---: |
| bpf_code | 3901 | 3.246% | 100.210 |
| helpers | 1474 | 1.227% | 37.864 |
| maps | 20145 | 16.762% | 517.490 |
| rest | 94659 | 78.765% | 2431.623 |

## Top symbols

| Symbol | Category | Samples |
| --- | --- | ---: |
| `_raw_spin_unlock_irqrestore` | rest | 32742 |
| `lookup_nulls_elem_raw` | maps | 8223 |
| `htab_lru_map_update_elem` | maps | 7865 |
| `_raw_spin_unlock_irq` | rest | 4598 |
| `mod_cur_headers` | rest | 3965 |
| `fib_table_lookup` | rest | 3784 |
| `enqueue_to_backlog` | rest | 3736 |
| `pvclock_clocksource_read_nowd` | rest | 2663 |
| `__pi_memcpy` | rest | 2636 |
| `jhash` | rest | 2192 |
| `get_random_u32` | rest | 1922 |
| `bpf_prog_7cae18cdf59b850b_tail_handle_ipv` | bpf_code | 1718 |
| `__netif_receive_skb_core.constprop.0` | rest | 1582 |
| `skb_defer_free_flush` | rest | 1568 |
| `handle_softirqs` | rest | 1555 |
| `trie_lookup_elem` | maps | 1535 |
| `veth_xmit` | rest | 1518 |
| `do_softirq` | rest | 1390 |
| `__icmp_send` | rest | 1298 |
| `fib_lookup_good_nhc` | rest | 1296 |

## Per-program BPF counters

| ID | Program | Attach point(s) | Runs | ns/run | JIT bytes |
| ---: | --- | --- | ---: | ---: | ---: |
| 520 | `cil_from_contai` | tc:lxcbench1:tcx/ingress | 19474537 | 1664.688 | 1709 |
| 433 | `cil_from_contai` | tc:lxcbench0:tcx/ingress | 19453923 | 1643.872 | 1709 |
| 409 | `cil_xdp_entry` | xdp:bpfbench0:driver | 1 | 1141.000 | 1096 |
| 543 | `cil_to_netdev` | tc:bpfbench0:tcx/egress | 1 | 2056.000 | 6740 |
| 547 | `cil_from_netdev` | tc:bpfbench0:tcx/ingress | 1 | 1392.000 | 3660 |

## JIT versus whole-program native image size

| Original ID | Native ID | Symbol | JIT bytes | Native blob bytes | Native stub image bytes |
| ---: | ---: | --- | ---: | ---: | ---: |
| 236 | 237 | `cil_xdp_entry` | 509 | 1082 | 1096 |
| 238 | 241 | `cil_to_netdev` | 5222 | 6710 | 6740 |
| 242 | 243 | `tail_handle_ipv4_from_netdev` | 8254 | 12234 | 12264 |
| 244 | 245 | `cil_to_host` | 859 | 2884 | 2914 |
| 246 | 247 | `tail_nodeport_nat_ingress_ipv4` | 8881 | 8291 | 8321 |
| 248 | 249 | `tail_drop_notify` | 405 | 1107 | 1121 |
| 250 | 251 | `cil_from_netdev` | 3386 | 3630 | 3660 |
| 252 | 253 | `cil_from_host` | 3945 | 3749 | 3779 |
| 254 | 255 | `tail_handle_ipv4_from_host` | 1262 | 1220 | 1250 |
| 256 | 257 | `tail_handle_snat_fwd_ipv4` | 12954 | 13200 | 13230 |
| 258 | 259 | `tail_nodeport_nat_egress_ipv4` | 6566 | 5945 | 5975 |
| 260 | 261 | `cil_host_policy` | 16 | 2 | 16 |
| 262 | 263 | `tail_no_service_ipv4` | 2792 | 2239 | 2269 |
| 264 | 265 | `cil_to_host` | 859 | 2884 | 2914 |
| 266 | 267 | `tail_drop_notify` | 405 | 1107 | 1121 |
| 268 | 269 | `cil_host_policy` | 16 | 2 | 16 |
| 270 | 271 | `cil_to_netdev` | 5222 | 6710 | 6740 |
| 272 | 273 | `tail_handle_snat_fwd_ipv4` | 12981 | 13200 | 13230 |
| 274 | 275 | `tail_handle_ipv4_from_netdev` | 8242 | 12234 | 12264 |
| 276 | 277 | `cil_from_host` | 3945 | 3749 | 3779 |
| 278 | 279 | `tail_nodeport_nat_ingress_ipv4` | 8881 | 8291 | 8321 |
| 280 | 281 | `tail_nodeport_nat_egress_ipv4` | 6566 | 5945 | 5975 |
| 282 | 283 | `tail_handle_ipv4_from_host` | 1262 | 1220 | 1250 |
| 284 | 285 | `cil_from_netdev` | 3386 | 3630 | 3660 |
| 286 | 287 | `tail_nodeport_nat_ingress_ipv4` | 8881 | 8291 | 8321 |
| 288 | 289 | `tail_nodeport_nat_egress_ipv4` | 6566 | 5945 | 5975 |
| 290 | 291 | `tail_handle_ipv4_from_host` | 1262 | 1220 | 1250 |
| 292 | 293 | `tail_no_service_ipv4` | 2792 | 2239 | 2269 |
| 294 | 295 | `tail_drop_notify` | 405 | 1107 | 1121 |
| 296 | 297 | `cil_to_host` | 859 | 2884 | 2914 |
| 298 | 299 | `cil_from_netdev` | 3386 | 3630 | 3660 |
| 300 | 301 | `cil_host_policy` | 16 | 2 | 16 |
| 302 | 303 | `cil_to_netdev` | 5222 | 6710 | 6740 |
| 304 | 305 | `tail_handle_snat_fwd_ipv4` | 12981 | 13200 | 13230 |
| 306 | 307 | `tail_handle_ipv4_from_netdev` | 8242 | 12234 | 12264 |
| 308 | 309 | `cil_from_host` | 3945 | 3749 | 3779 |
| 310 | 311 | `tail_nodeport_nat_ingress_ipv4` | 8881 | 8291 | 8321 |
| 312 | 313 | `tail_nodeport_nat_egress_ipv4` | 6566 | 5945 | 5975 |
| 314 | 315 | `tail_handle_snat_fwd_ipv4` | 12954 | 13200 | 13230 |
| 316 | 317 | `tail_handle_ipv4_from_netdev` | 8254 | 12234 | 12264 |
| 318 | 319 | `tail_drop_notify` | 405 | 1107 | 1121 |
| 320 | 321 | `cil_host_policy` | 16 | 2 | 16 |
| 322 | 323 | `tail_handle_ipv4_from_host` | 1262 | 1220 | 1250 |
| 324 | 325 | `cil_to_netdev` | 5222 | 6710 | 6740 |
| 326 | 327 | `cil_from_netdev` | 3386 | 3630 | 3660 |
| 328 | 329 | `cil_to_host` | 859 | 2884 | 2914 |
| 330 | 331 | `cil_from_host` | 3945 | 3749 | 3779 |
| 332 | 333 | `cil_host_policy` | 16 | 2 | 16 |
| 334 | 335 | `tail_handle_ipv4_from_host` | 1262 | 1220 | 1250 |
| 336 | 337 | `cil_to_host` | 859 | 2884 | 2914 |
| 338 | 339 | `tail_nodeport_nat_egress_ipv4` | 6566 | 5945 | 5975 |
| 340 | 341 | `cil_from_host` | 3945 | 3749 | 3779 |
| 342 | 343 | `tail_handle_ipv4_from_netdev` | 8242 | 12234 | 12264 |
| 344 | 345 | `tail_drop_notify` | 405 | 1107 | 1121 |
| 346 | 347 | `tail_no_service_ipv4` | 2792 | 2239 | 2269 |
| 348 | 349 | `cil_from_netdev` | 3386 | 3630 | 3660 |
| 350 | 351 | `tail_nodeport_nat_ingress_ipv4` | 8881 | 8291 | 8321 |
| 352 | 353 | `tail_handle_snat_fwd_ipv4` | 12981 | 13200 | 13230 |
| 354 | 355 | `cil_to_netdev` | 5222 | 6710 | 6740 |
| 356 | 357 | `cil_to_host` | 859 | 2884 | 2914 |
| 358 | 359 | `tail_handle_ipv4_from_host` | 1262 | 1220 | 1250 |
| 360 | 361 | `tail_handle_ipv4_from_netdev` | 8242 | 12234 | 12264 |
| 362 | 363 | `tail_no_service_ipv4` | 2792 | 2239 | 2269 |
| 364 | 365 | `tail_nodeport_nat_ingress_ipv4` | 8881 | 8291 | 8321 |
| 366 | 367 | `cil_from_host` | 3945 | 3749 | 3779 |
| 368 | 369 | `tail_drop_notify` | 405 | 1107 | 1121 |
| 370 | 371 | `cil_from_netdev` | 3386 | 3630 | 3660 |
| 372 | 373 | `cil_host_policy` | 16 | 2 | 16 |
| 374 | 375 | `tail_nodeport_nat_egress_ipv4` | 6566 | 5945 | 5975 |
| 376 | 377 | `cil_to_netdev` | 5222 | 6710 | 6740 |
| 378 | 379 | `tail_handle_snat_fwd_ipv4` | 12981 | 13200 | 13230 |
| 380 | 381 | `tail_ipv4_ct_egress` | 5375 | 6431 | 6461 |
| 382 | 383 | `tail_nodeport_rev_dnat_ipv4` | 3622 | 3403 | 3433 |
| 384 | 385 | `cil_lxc_policy_egress` | 16 | 2 | 16 |
| 386 | 387 | `tail_handle_ipv4` | 6216 | 6100 | 6130 |
| 388 | 389 | `tail_ipv4_ct_ingress` | 5210 | 4982 | 5012 |
| 390 | 391 | `tail_ipv4_policy` | 5580 | 7329 | 7359 |
| 392 | 393 | `tail_drop_notify` | 382 | 805 | 819 |
| 394 | 395 | `cil_to_container` | 1888 | 2108 | 2138 |
| 396 | 397 | `cil_from_container` | 1089 | 1679 | 1709 |
| 398 | 399 | `tail_ipv4_to_endpoint` | 5802 | 7009 | 7039 |
| 400 | 401 | `cil_lxc_policy` | 5760 | 5545 | 5575 |
| 402 | 403 | `tail_handle_ipv4_cont` | 6398 | 13290 | 13320 |
| 404 | 405 | `tail_no_service_ipv4` | 2774 | 2211 | 2241 |
| 406 | 407 | `tail_handle_arp` | 927 | 742 | 772 |
| 408 | 409 | `cil_xdp_entry` | 509 | 1082 | 1096 |
| 410 | 412 | `cil_host_policy` | 16 | 2 | 16 |
| 411 | 414 | `tail_nodeport_rev_dnat_ipv4` | 3622 | 3403 | 3433 |
| 413 | 416 | `tail_drop_notify` | 405 | 1107 | 1121 |
| 418 | 419 | `tail_ipv4_policy` | 5580 | 7329 | 7359 |
| 415 | 420 | `tail_handle_ipv4_cont` | 6398 | 13290 | 13320 |
| 417 | 421 | `tail_handle_ipv4_from_host` | 1262 | 1220 | 1250 |
| 422 | 424 | `tail_ipv4_ct_egress` | 5375 | 6431 | 6461 |
| 423 | 425 | `cil_lxc_policy` | 5760 | 5545 | 5575 |
| 426 | 429 | `tail_ipv4_to_endpoint` | 5802 | 7009 | 7039 |
| 427 | 431 | `tail_ipv4_ct_egress` | 5375 | 6431 | 6461 |
| 428 | 432 | `tail_handle_ipv4_from_netdev` | 8254 | 12234 | 12264 |
| 430 | 433 | `cil_from_container` | 1089 | 1679 | 1709 |
| 434 | 436 | `cil_to_netdev` | 5222 | 6710 | 6740 |
| 435 | 437 | `tail_handle_ipv4_cont` | 6398 | 13290 | 13320 |
| 439 | 441 | `cil_to_container` | 1888 | 2108 | 2138 |
| 438 | 442 | `cil_to_host` | 859 | 2884 | 2914 |
| 440 | 444 | `tail_handle_ipv4` | 6216 | 6100 | 6130 |
| 443 | 445 | `tail_ipv4_ct_ingress` | 5210 | 4982 | 5012 |
| 446 | 447 | `cil_to_container` | 1888 | 2108 | 2138 |
| 448 | 450 | `tail_drop_notify` | 382 | 805 | 819 |
| 451 | 452 | `tail_handle_ipv4` | 6216 | 6100 | 6130 |
| 449 | 455 | `tail_handle_snat_fwd_ipv4` | 12954 | 13200 | 13230 |
| 454 | 456 | `cil_lxc_policy_egress` | 16 | 2 | 16 |
| 453 | 459 | `tail_ipv4_to_endpoint` | 5802 | 7009 | 7039 |
| 457 | 460 | `tail_drop_notify` | 382 | 805 | 819 |
| 458 | 462 | `tail_nodeport_nat_egress_ipv4` | 6566 | 5945 | 5975 |
| 461 | 464 | `tail_no_service_ipv4` | 2774 | 2211 | 2241 |
| 466 | 467 | `cil_lxc_policy` | 5760 | 5545 | 5575 |
| 463 | 468 | `tail_ipv4_ct_ingress` | 5210 | 4982 | 5012 |
| 465 | 471 | `cil_from_netdev` | 3386 | 3630 | 3660 |
| 469 | 472 | `tail_handle_arp` | 927 | 742 | 772 |
| 470 | 473 | `tail_handle_arp` | 927 | 742 | 772 |
| 474 | 476 | `tail_nodeport_rev_dnat_ipv4` | 3622 | 3403 | 3433 |
| 475 | 478 | `tail_nodeport_nat_ingress_ipv4` | 8881 | 8291 | 8321 |
| 477 | 479 | `cil_lxc_policy_egress` | 16 | 2 | 16 |
| 480 | 482 | `cil_from_host` | 3945 | 3749 | 3779 |
| 481 | 483 | `tail_no_service_ipv4` | 2774 | 2211 | 2241 |
| 484 | 485 | `cil_from_container` | 1089 | 1679 | 1709 |
| 486 | 488 | `cil_from_host` | 3945 | 3749 | 3779 |
| 487 | 490 | `tail_ipv4_policy` | 5580 | 7329 | 7359 |
| 489 | 491 | `tail_handle_ipv4_from_host` | 1262 | 1220 | 1250 |
| 492 | 493 | `tail_nodeport_nat_egress_ipv4` | 6566 | 5945 | 5975 |
| 494 | 495 | `tail_nodeport_nat_ingress_ipv4` | 8881 | 8291 | 8321 |
| 497 | 498 | `tail_handle_ipv4` | 6216 | 6100 | 6130 |
| 496 | 499 | `tail_handle_ipv4_from_netdev` | 8242 | 12234 | 12264 |
| 500 | 502 | `tail_ipv4_ct_egress` | 5375 | 6431 | 6461 |
| 503 | 504 | `tail_nodeport_rev_dnat_ipv4` | 3622 | 3403 | 3433 |
| 501 | 505 | `cil_to_netdev` | 5222 | 6710 | 6740 |
| 506 | 508 | `cil_to_container` | 1888 | 2108 | 2138 |
| 507 | 510 | `cil_from_netdev` | 3386 | 3630 | 3660 |
| 509 | 511 | `cil_lxc_policy_egress` | 16 | 2 | 16 |
| 512 | 514 | `tail_drop_notify` | 405 | 1107 | 1121 |
| 513 | 515 | `tail_drop_notify` | 382 | 805 | 819 |
| 516 | 518 | `cil_host_policy` | 16 | 2 | 16 |
| 517 | 520 | `cil_from_container` | 1089 | 1679 | 1709 |
| 521 | 522 | `tail_handle_arp` | 927 | 742 | 772 |
| 519 | 523 | `cil_to_host` | 859 | 2884 | 2914 |
| 524 | 525 | `tail_no_service_ipv4` | 2774 | 2211 | 2241 |
| 526 | 527 | `cil_lxc_policy` | 5760 | 5545 | 5575 |
| 529 | 530 | `tail_handle_ipv4_cont` | 6398 | 13290 | 13320 |
| 528 | 531 | `tail_handle_snat_fwd_ipv4` | 12981 | 13200 | 13230 |
| 533 | 534 | `tail_ipv4_to_endpoint` | 5802 | 7009 | 7039 |
| 532 | 535 | `tail_no_service_ipv4` | 2792 | 2239 | 2269 |
| 536 | 537 | `tail_ipv4_ct_ingress` | 5210 | 4982 | 5012 |
| 538 | 539 | `tail_ipv4_policy` | 5580 | 7329 | 7359 |
| 540 | 541 | `tail_handle_snat_fwd_ipv4` | 12981 | 13200 | 13230 |
| 542 | 543 | `cil_to_netdev` | 5222 | 6710 | 6740 |
| 544 | 545 | `tail_handle_ipv4_from_host` | 1262 | 1220 | 1250 |
| 546 | 547 | `cil_from_netdev` | 3386 | 3630 | 3660 |
| 548 | 549 | `tail_handle_ipv4_from_netdev` | 8242 | 12234 | 12264 |
| 550 | 551 | `tail_nodeport_nat_egress_ipv4` | 6566 | 5945 | 5975 |
| 552 | 553 | `cil_host_policy` | 16 | 2 | 16 |
| 554 | 555 | `cil_to_host` | 859 | 2884 | 2914 |
| 556 | 557 | `tail_no_service_ipv4` | 2792 | 2239 | 2269 |
| 558 | 559 | `tail_nodeport_nat_ingress_ipv4` | 8881 | 8291 | 8321 |
| 560 | 561 | `cil_from_host` | 3945 | 3749 | 3779 |
| 562 | 563 | `tail_drop_notify` | 405 | 1107 | 1121 |
