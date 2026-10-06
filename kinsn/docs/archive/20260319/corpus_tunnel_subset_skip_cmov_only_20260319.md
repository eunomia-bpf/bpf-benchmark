# Corpus Batch Recompile Results

- Generated: 2026-03-19T15:33:30.416969+00:00
- Inventory: `/home/yunwei37/workspace/bpf-benchmark/docs/tmp/corpus_tunnel_subset_inventory_20260319.json`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- Requested mode: `strict-vm`
- Effective mode: `vm`
- Repeat: 200
- Skip families: `none`
- Target programs: 6
- Compile pairs: 6
- Measured pairs: 6
- Recompile applied programs: 5
- Code-size ratio geomean (baseline/v5): 1.002x
- Exec-time ratio geomean (baseline/v5): 0.748x
- Total sites: 11
- CMOV sites: 2
- WIDE sites: 1
- ROTATE sites: 0
- LEA sites: 0
- EXTRACT sites: 5
- ZERO-EXT sites: 0
- ENDIAN sites: 3
- BRANCH-FLIP sites: 0
- Kernel build: ok (0.00s)
- Guest kernel: `7.0.0-rc2-g8c70a729d22e`

## By Project

| Project | Programs | Compile Pairs | Measured Pairs | Applied | CMOV | WIDE | ROTATE | LEA | EXTRACT | ZERO-EXT | ENDIAN | BRANCH-FLIP | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| linux-selftests | 6 | 6 | 6 | 5 | 2 | 1 | 0 | 0 | 5 | 0 | 3 | 0 | 1.002x | 0.748x | 6 |

## By Family

| Family | Programs | Applied | Sites | Applied Sites | Compile Pairs | Measured Pairs | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| extract | 5 | 5 | 5 | 5 | 5 | 5 | 1.002x | 0.755x | 5 |
| endian | 2 | 1 | 3 | 2 | 2 | 2 | 1.006x | 0.756x | 2 |
| cmov | 2 | 0 | 2 | 0 | 2 | 2 | 1.006x | 0.756x | 2 |
| wide | 1 | 0 | 1 | 0 | 1 | 1 | 1.000x | 0.714x | 1 |
| branch-flip | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| lea | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| rotate | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| zero-ext | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |

## Regressions

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6tnl_none | linux-selftests | sched_cls | 0.600x | extract |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:decap_f | linux-selftests | sched_cls | 0.714x | cmov, wide, endian |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_none | linux-selftests | sched_cls | 0.800x | extract |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_none | linux-selftests | sched_cls | 0.800x | extract |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6vxlan_eth | linux-selftests | sched_cls | 0.800x | extract |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_sit_none | linux-selftests | sched_cls | 0.800x | extract, endian |

## Largest Code Shrinks

| Program | Project | Type | Code Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_sit_none | linux-selftests | sched_cls | 1.012x | extract, endian |

## Per-Program Results

| Program | Project | Type | Sites | Applied Families | Baseline JIT | v5 JIT | Code Ratio | Baseline ns | v5 ns | Exec Ratio | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_none | linux-selftests | sched_cls | 1 | extract | 435 | 435 | 1.000x | 4 | 5 | 0.800x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6tnl_none | linux-selftests | sched_cls | 1 | extract | 407 | 407 | 1.000x | 3 | 5 | 0.600x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_none | linux-selftests | sched_cls | 1 | extract | 545 | 545 | 1.000x | 4 | 5 | 0.800x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6vxlan_eth | linux-selftests | sched_cls | 1 | extract | 605 | 605 | 1.000x | 4 | 5 | 0.800x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_sit_none | linux-selftests | sched_cls | 4 | extract, endian | 697 | 689 | 1.012x | 4 | 5 | 0.800x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:decap_f | linux-selftests | sched_cls | 3 |  | 696 | 696 | 1.000x | 10 | 14 | 0.714x |  |

## Notes

- Target selection comes from the runnability inventory and keeps every packet-test-run target whose baseline run already succeeds; the current scanner pass determines whether v5 has any eligible families.
- In strict VM mode, each target boots the framework v5 guest once and runs baseline compile-only, v5 compile-only, baseline test_run, and v5 test_run in that order.
- Default steady-state semantics are stock: without `--use-policy` or `--blind-apply`, the v5 lane does not request recompile.
- `--use-policy` only considers per-program version 3 policy files under `corpus/policies/`; if no match exists, the driver stays on stock JIT.
- `--blind-apply` forces the old debug/exploration path with `--recompile-v5 --recompile-all`.
- `--skip-families` only applies together with `--blind-apply`; the family columns above report applied families, not just eligible sites.
- Host fallback mode only does baseline compile-only plus offline scanner scan; it does not attempt recompile or runtime measurement.
- Family summaries are overlap-based: one program can contribute to multiple family rows, so those rows are not isolated causal attributions.
