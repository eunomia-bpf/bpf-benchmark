# Cross-Domain Directive Site Census

Directive candidate sites found by scanning raw BPF bytecode from
executable ELF sections in `.bpf.o` files across multiple BPF program domains.

## Summary Table

| Domain | Sources | Objects | Programs | Insns | CMOV | WIDE | ROTATE | LEA | Total Sites | Objects w/ Sites |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| Networking | 9 | 61 | 148 | 349819 | 1051 | 1864 | 30 | 0 | 2945 | 39 |
| Tracing | 1 | 57 | 366 | 23707 | 109 | 0 | 0 | 0 | 109 | 20 |
| Security/Resource | 1 | 6 | 16 | 668 | 3 | 0 | 0 | 0 | 3 | 2 |
| Testing | 1 | 361 | 667 | 68350 | 74 | 6 | 1810 | 0 | 1890 | 37 |
| Examples | 1 | 12 | 22 | 946 | 0 | 0 | 0 | 0 | 0 | 0 |
| Other | 2 | 17 | 29 | 1120 | 0 | 0 | 0 | 0 | 0 | 0 |
| **Total** | **15** | **514** | **1248** | **444610** | **1237** | **1870** | **1840** | **0** | **4947** | **98** |

## Per-Source Breakdown

| Source | Domain | Objects | Programs | Insns | CMOV | WIDE | ROTATE | LEA | Total | w/ Sites |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| bcc | Tracing | 57 | 366 | 23707 | 109 | 0 | 0 | 0 | 109 | 20 |
| calico | Networking | 8 | 8 | 158995 | 196 | 108 | 10 | 0 | 314 | 8 |
| cilium | Networking | 3 | 9 | 97621 | 658 | 0 | 0 | 0 | 658 | 3 |
| katran | Networking | 5 | 6 | 3013 | 6 | 4 | 20 | 0 | 30 | 2 |
| libbpf-bootstrap | Examples | 12 | 22 | 946 | 0 | 0 | 0 | 0 | 0 | 0 |
| linux-selftests | Testing | 361 | 667 | 68350 | 74 | 6 | 1810 | 0 | 1890 | 37 |
| loxilb | Networking | 3 | 20 | 77619 | 98 | 1729 | 0 | 0 | 1827 | 3 |
| manual-test | Other | 2 | 4 | 48 | 0 | 0 | 0 | 0 | 0 | 0 |
| netbird | Networking | 1 | 2 | 264 | 0 | 0 | 0 | 0 | 0 | 0 |
| real_world_code_size | Other | 15 | 25 | 1072 | 0 | 0 | 0 | 0 | 0 | 0 |
| suricata | Networking | 2 | 2 | 744 | 2 | 0 | 0 | 0 | 2 | 2 |
| systemd | Security/Resource | 6 | 16 | 668 | 3 | 0 | 0 | 0 | 3 | 2 |
| tubular | Networking | 1 | 1 | 124 | 0 | 0 | 0 | 0 | 0 | 0 |
| xdp-tools | Networking | 13 | 58 | 9094 | 51 | 1 | 0 | 0 | 52 | 11 |
| xdp-tutorial | Networking | 25 | 42 | 2345 | 40 | 22 | 0 | 0 | 62 | 10 |

## Networking Domain Details

Sources: calico, cilium, katran, loxilb, netbird, suricata, tubular, xdp-tools, xdp-tutorial

### Programs with Directive Sites (39 of 61)

| Program | Source | Insns | CMOV | WIDE | ROTATE | LEA | Total |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: |
| llb_ebpf_emain.bpf.o | loxilb | 37938 | 49 | 863 | 0 | 0 | 912 |
| llb_ebpf_main.bpf.o | loxilb | 37895 | 49 | 863 | 0 | 0 | 912 |
| bpf_xdp.bpf.o | cilium | 26129 | 408 | 0 | 0 | 0 | 408 |
| bpf_lxc.bpf.o | cilium | 41881 | 142 | 0 | 0 | 0 | 142 |
| bpf_overlay.bpf.o | cilium | 29611 | 108 | 0 | 0 | 0 | 108 |
| from_hep_debug.bpf.o | calico | 28053 | 34 | 18 | 10 | 0 | 62 |
| to_hep_debug.bpf.o | calico | 30897 | 40 | 20 | 0 | 0 | 60 |
| to_nat_debug.bpf.o | calico | 30655 | 40 | 20 | 0 | 0 | 60 |
| from_nat_debug.bpf.o | calico | 24102 | 31 | 14 | 0 | 0 | 45 |
| to_wep_debug.bpf.o | calico | 18809 | 28 | 16 | 0 | 0 | 44 |
| from_wep_debug.bpf.o | calico | 24628 | 23 | 14 | 0 | 0 | 37 |
| xdp_flowtable.bpf.o | xdp-tools | 2744 | 30 | 0 | 0 | 0 | 30 |
| balancer.bpf.o | katran | 2546 | 5 | 4 | 20 | 0 | 29 |
| xdp_vlan01_kern.bpf.o | xdp-tutorial | 113 | 12 | 6 | 0 | 0 | 18 |
| xdp_prog_kern_02.bpf.o | xdp-tutorial | 338 | 1 | 9 | 0 | 0 | 10 |
| xdp_prog_kern_03.bpf.o | xdp-tutorial | 507 | 5 | 4 | 0 | 0 | 9 |
| xdp_vlan02_kern.bpf.o | xdp-tutorial | 127 | 9 | 0 | 0 | 0 | 9 |
| xdp_prog_kern.bpf.o | xdp-tutorial | 306 | 4 | 2 | 0 | 0 | 6 |
| xdp_debug.bpf.o | calico | 1435 | 0 | 4 | 0 | 0 | 4 |
| xdp_basic.bpf.o | xdp-tools | 1116 | 3 | 1 | 0 | 0 | 4 |
| trace_prog_kern.bpf.o | xdp-tutorial | 176 | 4 | 0 | 0 | 0 | 4 |
| llb_xdp_main.bpf.o | loxilb | 1786 | 0 | 3 | 0 | 0 | 3 |
| xdp_redirect_cpumap.bpf.o | xdp-tools | 1364 | 3 | 0 | 0 | 0 | 3 |
| xdp_trafficgen.bpf.o | xdp-tools | 1070 | 3 | 0 | 0 | 0 | 3 |
| xdp_prog_kern.bpf.o | xdp-tutorial | 117 | 2 | 1 | 0 | 0 | 3 |
| xdp_no_log.bpf.o | calico | 416 | 0 | 2 | 0 | 0 | 2 |
| xdp_forward.bpf.o | xdp-tools | 302 | 2 | 0 | 0 | 0 | 2 |
| xdp_monitor.bpf.o | xdp-tools | 541 | 2 | 0 | 0 | 0 | 2 |
| xdp_redirect_basic.bpf.o | xdp-tools | 630 | 2 | 0 | 0 | 0 | 2 |
| xdp_redirect_devmap.bpf.o | xdp-tools | 632 | 2 | 0 | 0 | 0 | 2 |
| xdp_redirect_devmap_multi.bpf.o | xdp-tools | 612 | 2 | 0 | 0 | 0 | 2 |
| healthchecking.bpf.o | katran | 325 | 1 | 0 | 0 | 0 | 1 |
| xdp_filter.bpf.o | suricata | 334 | 1 | 0 | 0 | 0 | 1 |
| xdp_lb.bpf.o | suricata | 410 | 1 | 0 | 0 | 0 | 1 |
| xdp_flowtable_sample.bpf.o | xdp-tools | 25 | 1 | 0 | 0 | 0 | 1 |
| xdp_load_bytes.bpf.o | xdp-tools | 13 | 1 | 0 | 0 | 0 | 1 |
| xdp_prog_fail2.bpf.o | xdp-tutorial | 7 | 1 | 0 | 0 | 0 | 1 |
| xdp_prog_kern4.bpf.o | xdp-tutorial | 25 | 1 | 0 | 0 | 0 | 1 |
| xdp_sample_pkts_kern.bpf.o | xdp-tutorial | 33 | 1 | 0 | 0 | 0 | 1 |

## Tracing Domain Details

Sources: bcc

### Programs with Directive Sites (20 of 57)

| Program | Source | Insns | CMOV | WIDE | ROTATE | LEA | Total |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: |
| biostacks.bpf.o | bcc | 569 | 15 | 0 | 0 | 0 | 15 |
| cpudist.bpf.o | bcc | 403 | 14 | 0 | 0 | 0 | 14 |
| readahead.bpf.o | bcc | 289 | 10 | 0 | 0 | 0 | 10 |
| biolatency.bpf.o | bcc | 534 | 7 | 0 | 0 | 0 | 7 |
| fsdist.bpf.o | bcc | 350 | 7 | 0 | 0 | 0 | 7 |
| futexctn.bpf.o | bcc | 215 | 7 | 0 | 0 | 0 | 7 |
| runqlat.bpf.o | bcc | 422 | 7 | 0 | 0 | 0 | 7 |
| funclatency.bpf.o | bcc | 171 | 6 | 0 | 0 | 0 | 6 |
| hardirqs.bpf.o | bcc | 248 | 6 | 0 | 0 | 0 | 6 |
| softirqs.bpf.o | bcc | 181 | 6 | 0 | 0 | 0 | 6 |
| bitesize.bpf.o | bcc | 140 | 4 | 0 | 0 | 0 | 4 |
| tcprtt.bpf.o | bcc | 499 | 4 | 0 | 0 | 0 | 4 |
| tcpsynbl.bpf.o | bcc | 93 | 4 | 0 | 0 | 0 | 4 |
| biotop.bpf.o | bcc | 551 | 3 | 0 | 0 | 0 | 3 |
| filetop.bpf.o | bcc | 179 | 2 | 0 | 0 | 0 | 2 |
| llcstat.bpf.o | bcc | 110 | 2 | 0 | 0 | 0 | 2 |
| memleak.bpf.o | bcc | 1606 | 2 | 0 | 0 | 0 | 2 |
| biopattern.bpf.o | bcc | 101 | 1 | 0 | 0 | 0 | 1 |
| ksnoop.bpf.o | bcc | 700 | 1 | 0 | 0 | 0 | 1 |
| runqlen.bpf.o | bcc | 83 | 1 | 0 | 0 | 0 | 1 |

## Security/Resource Domain Details

Sources: systemd

### Programs with Directive Sites (2 of 6)

| Program | Source | Insns | CMOV | WIDE | ROTATE | LEA | Total |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: |
| restrict-ifaces.bpf.o | systemd | 38 | 2 | 0 | 0 | 0 | 2 |
| userns-restrict.bpf.o | systemd | 258 | 1 | 0 | 0 | 0 | 1 |

## Testing Domain Details

Sources: linux-selftests

### Programs with Directive Sites (37 of 361)

| Program | Source | Insns | CMOV | WIDE | ROTATE | LEA | Total |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: |
| test_verif_scale2.bpf.o | linux-selftests | 14750 | 0 | 0 | 992 | 0 | 992 |
| core_kern.bpf.o | linux-selftests | 15789 | 0 | 0 | 818 | 0 | 818 |
| test_tc_tunnel.bpf.o | linux-selftests | 2339 | 8 | 1 | 0 | 0 | 9 |
| xdp_synproxy_kern.bpf.o | linux-selftests | 2203 | 4 | 5 | 0 | 0 | 9 |
| test_core_reloc_module.bpf.o | linux-selftests | 137 | 6 | 0 | 0 | 0 | 6 |
| bpf_cc_cubic.bpf.o | linux-selftests | 159 | 4 | 0 | 0 | 0 | 4 |
| bpf_cubic.bpf.o | linux-selftests | 558 | 4 | 0 | 0 | 0 | 4 |
| bpf_iter_ksym.bpf.o | linux-selftests | 149 | 3 | 0 | 0 | 0 | 3 |
| bpf_iter_task_vmas.bpf.o | linux-selftests | 124 | 3 | 0 | 0 | 0 | 3 |
| setget_sockopt.bpf.o | linux-selftests | 917 | 3 | 0 | 0 | 0 | 3 |
| test_skmsg_load_helpers.bpf.o | linux-selftests | 98 | 3 | 0 | 0 | 0 | 3 |
| uprobe_multi_pid_filter.bpf.o | linux-selftests | 49 | 3 | 0 | 0 | 0 | 3 |
| bpf_hashmap_lookup.bpf.o | linux-selftests | 60 | 2 | 0 | 0 | 0 | 2 |
| decap_sanity.bpf.o | linux-selftests | 75 | 2 | 0 | 0 | 0 | 2 |
| kfunc_call_test.bpf.o | linux-selftests | 212 | 2 | 0 | 0 | 0 | 2 |
| test_cgroup1_hierarchy.bpf.o | linux-selftests | 54 | 2 | 0 | 0 | 0 | 2 |
| test_kernel_flag.bpf.o | linux-selftests | 14 | 2 | 0 | 0 | 0 | 2 |
| test_overhead.bpf.o | linux-selftests | 16 | 2 | 0 | 0 | 0 | 2 |
| token_lsm.bpf.o | linux-selftests | 36 | 2 | 0 | 0 | 0 | 2 |
| verifier_arena.bpf.o | linux-selftests | 88 | 2 | 0 | 0 | 0 | 2 |
| bpf_dctcp.bpf.o | linux-selftests | 294 | 1 | 0 | 0 | 0 | 1 |
| bpf_iter_sockmap.bpf.o | linux-selftests | 47 | 1 | 0 | 0 | 0 | 1 |
| bpf_iter_unix.bpf.o | linux-selftests | 143 | 1 | 0 | 0 | 0 | 1 |
| bpf_mod_race.bpf.o | linux-selftests | 39 | 1 | 0 | 0 | 0 | 1 |
| for_each_array_map_elem.bpf.o | linux-selftests | 59 | 1 | 0 | 0 | 0 | 1 |
| get_func_ip_uprobe_test.bpf.o | linux-selftests | 13 | 1 | 0 | 0 | 0 | 1 |
| local_storage.bpf.o | linux-selftests | 188 | 1 | 0 | 0 | 0 | 1 |
| lru_bug.bpf.o | linux-selftests | 60 | 1 | 0 | 0 | 0 | 1 |
| map_kptr.bpf.o | linux-selftests | 1543 | 1 | 0 | 0 | 0 | 1 |
| mptcpify.bpf.o | linux-selftests | 38 | 1 | 0 | 0 | 0 | 1 |
| tcp_ca_write_sk_pacing.bpf.o | linux-selftests | 41 | 1 | 0 | 0 | 0 | 1 |
| test_perf_skip.bpf.o | linux-selftests | 8 | 1 | 0 | 0 | 0 | 1 |
| test_sockmap_update.bpf.o | linux-selftests | 33 | 1 | 0 | 0 | 0 | 1 |
| test_task_under_cgroup.bpf.o | linux-selftests | 65 | 1 | 0 | 0 | 0 | 1 |
| test_tc_change_tail.bpf.o | linux-selftests | 85 | 1 | 0 | 0 | 0 | 1 |
| test_varlen.bpf.o | linux-selftests | 192 | 1 | 0 | 0 | 0 | 1 |
| xfrm_info.bpf.o | linux-selftests | 35 | 1 | 0 | 0 | 0 | 1 |

## Examples Domain Details

Sources: libbpf-bootstrap

No programs with directive sites in this domain.

## Other Domain Details

Sources: manual-test, real_world_code_size

No programs with directive sites in this domain.

## Top 20 Programs by Total Sites (All Domains)

| Program | Source | Domain | Insns | CMOV | WIDE | ROTATE | LEA | Total |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: | ---: |
| test_verif_scale2.bpf.o | linux-selftests | Testing | 14750 | 0 | 0 | 992 | 0 | 992 |
| llb_ebpf_emain.bpf.o | loxilb | Networking | 37938 | 49 | 863 | 0 | 0 | 912 |
| llb_ebpf_main.bpf.o | loxilb | Networking | 37895 | 49 | 863 | 0 | 0 | 912 |
| core_kern.bpf.o | linux-selftests | Testing | 15789 | 0 | 0 | 818 | 0 | 818 |
| bpf_xdp.bpf.o | cilium | Networking | 26129 | 408 | 0 | 0 | 0 | 408 |
| bpf_lxc.bpf.o | cilium | Networking | 41881 | 142 | 0 | 0 | 0 | 142 |
| bpf_overlay.bpf.o | cilium | Networking | 29611 | 108 | 0 | 0 | 0 | 108 |
| from_hep_debug.bpf.o | calico | Networking | 28053 | 34 | 18 | 10 | 0 | 62 |
| to_hep_debug.bpf.o | calico | Networking | 30897 | 40 | 20 | 0 | 0 | 60 |
| to_nat_debug.bpf.o | calico | Networking | 30655 | 40 | 20 | 0 | 0 | 60 |
| from_nat_debug.bpf.o | calico | Networking | 24102 | 31 | 14 | 0 | 0 | 45 |
| to_wep_debug.bpf.o | calico | Networking | 18809 | 28 | 16 | 0 | 0 | 44 |
| from_wep_debug.bpf.o | calico | Networking | 24628 | 23 | 14 | 0 | 0 | 37 |
| xdp_flowtable.bpf.o | xdp-tools | Networking | 2744 | 30 | 0 | 0 | 0 | 30 |
| balancer.bpf.o | katran | Networking | 2546 | 5 | 4 | 20 | 0 | 29 |
| xdp_vlan01_kern.bpf.o | xdp-tutorial | Networking | 113 | 12 | 6 | 0 | 0 | 18 |
| biostacks.bpf.o | bcc | Tracing | 569 | 15 | 0 | 0 | 0 | 15 |
| cpudist.bpf.o | bcc | Tracing | 403 | 14 | 0 | 0 | 0 | 14 |
| readahead.bpf.o | bcc | Tracing | 289 | 10 | 0 | 0 | 0 | 10 |
| xdp_prog_kern_02.bpf.o | xdp-tutorial | Networking | 338 | 1 | 9 | 0 | 0 | 10 |

## Key Findings

### Cross-Domain Coverage

- **Networking**: 39/61 objects (63.9%) have at least one directive site
- **Tracing**: 20/57 objects (35.1%) have at least one directive site
- **Security/Resource**: 2/6 objects (33.3%) have at least one directive site
- **Testing**: 37/361 objects (10.2%) have at least one directive site
- **Examples**: 0/12 objects (0.0%) have at least one directive site
- **Other**: 0/17 objects (0.0%) have at least one directive site

### Directive Family Distribution

- **CMOV**: appears in Networking (1051), Tracing (109), Security/Resource (3), Testing (74)
- **WIDE**: appears in Networking (1864), Testing (6)
- **ROTATE**: appears in Networking (30), Testing (1810)
- **LEA**: not found in any domain

### Distribution Pattern

- Dominant family by raw count: **WIDE** (1870 sites)
- Total directive sites across all 514 objects: 4947
- Objects with at least one site: 98/514 (19.1%)
- Total BPF instructions scanned: 444610
- Site density: 11.13 sites per 1000 instructions

## Methodology

- Scanned raw BPF bytecode from every executable (`SHF_EXECINSTR`) ELF section
- Pattern matching uses the same heuristics as `scanner/src/scanner.cpp`
- Counts are **candidate** sites (pre-verifier), not accepted rules
- Only `EM_BPF` ELF objects were scanned; non-BPF `.bpf.o` files were skipped
- Domain classification is based on corpus directory name

