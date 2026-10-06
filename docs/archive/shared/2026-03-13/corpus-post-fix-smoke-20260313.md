# Corpus Batch Recompile Results

- Generated: 2026-03-13T20:32:37.547714+00:00
- Inventory: `/home/yunwei37/workspace/bpf-benchmark/docs/tmp/corpus-runnability-results.json`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- Requested mode: `strict-vm`
- Effective mode: `vm`
- Repeat: 200
- Skip families: `none`
- Target programs: 20
- Compile pairs: 20
- Measured pairs: 20
- Recompile applied programs: 2
- Code-size ratio geomean (baseline/v5): 1.000x
- Exec-time ratio geomean (baseline/v5): 1.023x
- Total sites: 584
- CMOV sites: 149
- WIDE sites: 40
- ROTATE sites: 10
- LEA sites: 0
- EXTRACT sites: 13
- ZERO-EXT sites: 0
- ENDIAN sites: 332
- BRANCH-FLIP sites: 40
- Kernel build: ok (0.00s)
- Guest kernel: `7.0.0-rc2-gdaca445b10fd-dirty`

## By Project

| Project | Programs | Compile Pairs | Measured Pairs | Applied | CMOV | WIDE | ROTATE | LEA | EXTRACT | ZERO-EXT | ENDIAN | BRANCH-FLIP | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| calico | 20 | 20 | 20 | 2 | 149 | 40 | 10 | 0 | 13 | 0 | 332 | 40 | 1.000x | 1.023x | 9 |

## By Family

| Family | Programs | Applied | Sites | Applied Sites | Compile Pairs | Measured Pairs | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| endian | 18 | 2 | 332 | 74 | 18 | 18 | 1.000x | 1.022x | 8 |
| cmov | 16 | 0 | 149 | 0 | 16 | 16 | 1.000x | 1.021x | 7 |
| branch-flip | 20 | 0 | 40 | 0 | 20 | 20 | 1.000x | 1.023x | 9 |
| wide | 9 | 2 | 40 | 14 | 9 | 9 | 1.000x | 0.981x | 5 |
| extract | 6 | 1 | 13 | 1 | 6 | 6 | 1.000x | 1.011x | 2 |
| rotate | 1 | 0 | 10 | 0 | 1 | 1 | 1.000x | 1.176x | 0 |
| lea | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| zero-ext | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |

## Top Speedups

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 1.254x | cmov, endian, branch-flip |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 1.205x | cmov, wide, endian, branch-flip |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 1.179x | cmov, branch-flip |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_maglev | calico | sched_cls | 1.176x | rotate, endian, branch-flip |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 1.155x | cmov, extract, endian, branch-flip |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main | calico | sched_cls | 1.112x | wide, extract, endian |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 1.094x | cmov, extract, endian, branch-flip |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_main | calico | sched_cls | 1.086x | cmov, wide, extract, endian, branch-flip |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 1.085x | cmov, endian, branch-flip |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_main | calico | sched_cls | 1.025x | cmov, wide, endian, branch-flip |

## Regressions

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 0.743x | cmov, wide, extract, endian, branch-flip |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 0.888x | wide, endian |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 0.899x | cmov, endian, branch-flip |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 0.907x | cmov, branch-flip |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 0.933x | cmov, wide, endian, branch-flip |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 0.944x | cmov, wide, extract, endian, branch-flip |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 0.971x | cmov, wide, endian, branch-flip |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 0.974x | endian, branch-flip |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 0.981x | endian, branch-flip |

## Largest Code Shrinks

| Program | Project | Type | Code Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 1.000x | wide, endian |

## Per-Program Results

| Program | Project | Type | Sites | Applied Families | Baseline JIT | v5 JIT | Code Ratio | Baseline ns | v5 ns | Exec Ratio | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_maglev | calico | sched_cls | 13 |  | 3260 | 3260 | 1.000x | 200 | 170 | 1.176x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main | calico | sched_cls | 87 | wide, extract, endian | 46152 | 46152 | 1.000x | 309 | 278 | 1.112x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 36 |  | 20957 | 20957 | 1.000x | 161 | 179 | 0.899x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 7 |  | 2408 | 2408 | 1.000x | 155 | 158 | 0.981x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 38 |  | 18440 | 18440 | 1.000x | 169 | 174 | 0.971x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 3 |  | 896 | 896 | 1.000x | 147 | 162 | 0.907x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 44 |  | 23489 | 23489 | 1.000x | 163 | 149 | 1.094x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 16 |  | 11888 | 11888 | 1.000x | 188 | 156 | 1.205x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 18 |  | 10978 | 10978 | 1.000x | 153 | 162 | 0.944x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_main | calico | sched_cls | 63 |  | 33180 | 33180 | 1.000x | 303 | 279 | 1.086x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 30 |  | 18932 | 18932 | 1.000x | 212 | 169 | 1.254x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 7 |  | 2408 | 2408 | 1.000x | 148 | 152 | 0.974x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 33 | wide, endian | 16630 | 16626 | 1.000x | 150 | 169 | 0.888x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 3 |  | 896 | 896 | 1.000x | 184 | 156 | 1.179x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 40 |  | 21185 | 21185 | 1.000x | 171 | 148 | 1.155x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 16 |  | 12004 | 12004 | 1.000x | 154 | 165 | 0.933x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 18 |  | 11097 | 11097 | 1.000x | 165 | 222 | 0.743x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_main | calico | sched_cls | 72 |  | 36667 | 36667 | 1.000x | 161 | 157 | 1.025x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 34 |  | 22172 | 22172 | 1.000x | 166 | 153 | 1.085x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 6 |  | 1729 | 1729 | 1.000x | 191 | 189 | 1.011x |  |

## Notes

- Target selection comes from the runnability inventory and keeps every packet-test-run target whose baseline run already succeeds; the current scanner pass determines whether v5 has any eligible families.
- In strict VM mode, each target boots the framework v5 guest once and runs baseline compile-only, v5 compile-only, baseline test_run, and v5 test_run in that order.
- Default steady-state semantics are stock: without `--use-policy` or `--blind-apply`, the v5 lane does not request recompile.
- `--use-policy` only considers per-program version 3 policy files under `corpus/policies/`; if no match exists, the driver stays on stock JIT.
- `--blind-apply` forces the old debug/exploration path with `--recompile-v5 --recompile-all`.
- `--skip-families` only applies together with `--blind-apply`; the family columns above report applied families, not just eligible sites.
- Host fallback mode only does baseline compile-only plus offline scanner scan; it does not attempt recompile or runtime measurement.
- Family summaries are overlap-based: one program can contribute to multiple family rows, so those rows are not isolated causal attributions.
