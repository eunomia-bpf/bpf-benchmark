# Corpus Batch Recompile Results

- Generated: 2026-03-19T15:35:08.297967+00:00
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
- Recompile applied programs: 0
- Code-size ratio geomean (baseline/v5): 1.000x
- Exec-time ratio geomean (baseline/v5): 0.860x
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
| calico | 3 | 3 | 3 | 0 | 34 | 16 | 0 | 0 | 2 | 0 | 64 | 6 | 1.000x | 0.860x | 3 |

## By Family

| Family | Programs | Applied | Sites | Applied Sites | Compile Pairs | Measured Pairs | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| endian | 3 | 0 | 64 | 0 | 3 | 3 | 1.000x | 0.860x | 3 |
| cmov | 2 | 0 | 34 | 0 | 2 | 2 | 1.000x | 0.863x | 2 |
| wide | 3 | 0 | 16 | 0 | 3 | 3 | 1.000x | 0.860x | 3 |
| branch-flip | 3 | 0 | 6 | 0 | 3 | 3 | 1.000x | 0.860x | 3 |
| extract | 2 | 0 | 2 | 0 | 2 | 2 | 1.000x | 0.863x | 2 |
| lea | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| rotate | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| zero-ext | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |

## Regressions

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 0.748x | cmov, wide, extract, endian, branch-flip |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_main | calico | xdp | 0.855x | wide, endian, branch-flip |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_main | calico | sched_cls | 0.995x | cmov, wide, extract, endian, branch-flip |

## Per-Program Results

| Program | Project | Type | Sites | Applied Families | Baseline JIT | v5 JIT | Code Ratio | Baseline ns | v5 ns | Exec Ratio | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_main | calico | sched_cls | 63 |  | 33180 | 33180 | 1.000x | 213 | 214 | 0.995x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 47 |  | 22218 | 22218 | 1.000x | 110 | 147 | 0.748x |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_main | calico | xdp | 12 |  | 4427 | 4427 | 1.000x | 247 | 289 | 0.855x |  |

## Notes

- Target selection comes from the runnability inventory and keeps every packet-test-run target whose baseline run already succeeds; the current scanner pass determines whether v5 has any eligible families.
- In strict VM mode, each target boots the framework v5 guest once and runs baseline compile-only, v5 compile-only, baseline test_run, and v5 test_run in that order.
- Default steady-state semantics are stock: without `--use-policy` or `--blind-apply`, the v5 lane does not request recompile.
- `--use-policy` only considers per-program version 3 policy files under `corpus/policies/`; if no match exists, the driver stays on stock JIT.
- `--blind-apply` forces the old debug/exploration path with `--recompile-v5 --recompile-all`.
- `--skip-families` only applies together with `--blind-apply`; the family columns above report applied families, not just eligible sites.
- Host fallback mode only does baseline compile-only plus offline scanner scan; it does not attempt recompile or runtime measurement.
- Family summaries are overlap-based: one program can contribute to multiple family rows, so those rows are not isolated causal attributions.
