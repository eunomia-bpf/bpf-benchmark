# Corpus Batch Recompile Results

- Generated: 2026-03-19T15:34:42.171625+00:00
- Inventory: `/home/yunwei37/workspace/bpf-benchmark/docs/tmp/corpus_calico_regressor_subset_inventory_20260319.json`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- Requested mode: `strict-vm`
- Effective mode: `vm`
- Repeat: 200
- Skip families: `none`
- Target programs: 3
- Compile pairs: 3
- Measured pairs: 3
- Recompile applied programs: 3
- Code-size ratio geomean (baseline/v5): 1.007x
- Exec-time ratio geomean (baseline/v5): 1.011x
- Total sites: 122
- CMOV sites: 34
- WIDE sites: 16
- ROTATE sites: 0
- LEA sites: 0
- EXTRACT sites: 2
- ZERO-EXT sites: 0
- ENDIAN sites: 64
- BRANCH-FLIP sites: 6
- Kernel build: ok (0.00s)
- Guest kernel: `7.0.0-rc2-g8c70a729d22e`

## By Project

| Project | Programs | Compile Pairs | Measured Pairs | Applied | CMOV | WIDE | ROTATE | LEA | EXTRACT | ZERO-EXT | ENDIAN | BRANCH-FLIP | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| calico | 3 | 3 | 3 | 3 | 34 | 16 | 0 | 0 | 2 | 0 | 64 | 6 | 1.007x | 1.011x | 1 |

## By Family

| Family | Programs | Applied | Sites | Applied Sites | Compile Pairs | Measured Pairs | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| endian | 3 | 3 | 64 | 64 | 3 | 3 | 1.007x | 1.011x | 1 |
| cmov | 2 | 0 | 34 | 0 | 2 | 2 | 1.003x | 0.994x | 1 |
| wide | 3 | 3 | 16 | 16 | 3 | 3 | 1.007x | 1.011x | 1 |
| branch-flip | 3 | 0 | 6 | 0 | 3 | 3 | 1.007x | 1.011x | 1 |
| extract | 2 | 0 | 2 | 0 | 2 | 2 | 1.003x | 0.994x | 1 |
| lea | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| rotate | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| zero-ext | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |

## Top Speedups

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_main | calico | xdp | 1.045x | wide, endian |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 1.038x | wide, endian |

## Regressions

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_main | calico | sched_cls | 0.952x | wide, endian |

## Largest Code Shrinks

| Program | Project | Type | Code Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_main | calico | xdp | 1.014x | wide, endian |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_main | calico | sched_cls | 1.005x | wide, endian |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 1.002x | wide, endian |

## Per-Program Results

| Program | Project | Type | Sites | Applied Families | Baseline JIT | v5 JIT | Code Ratio | Baseline ns | v5 ns | Exec Ratio | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_main | calico | sched_cls | 63 | wide, endian | 33180 | 33029 | 1.005x | 199 | 209 | 0.952x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 47 | wide, endian | 22218 | 22184 | 1.002x | 110 | 106 | 1.038x |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_main | calico | xdp | 12 | wide, endian | 4427 | 4365 | 1.014x | 256 | 245 | 1.045x |  |

## Notes

- Target selection comes from the runnability inventory and keeps every packet-test-run target whose baseline run already succeeds; the current scanner pass determines whether v5 has any eligible families.
- In strict VM mode, each target boots the framework v5 guest once and runs baseline compile-only, v5 compile-only, baseline test_run, and v5 test_run in that order.
- Default steady-state semantics are stock: without `--use-policy` or `--blind-apply`, the v5 lane does not request recompile.
- `--use-policy` only considers per-program version 3 policy files under `corpus/policies/`; if no match exists, the driver stays on stock JIT.
- `--blind-apply` forces the old debug/exploration path with `--recompile-v5 --recompile-all`.
- `--skip-families` only applies together with `--blind-apply`; the family columns above report applied families, not just eligible sites.
- Host fallback mode only does baseline compile-only plus offline scanner scan; it does not attempt recompile or runtime measurement.
- Family summaries are overlap-based: one program can contribute to multiple family rows, so those rows are not isolated causal attributions.
