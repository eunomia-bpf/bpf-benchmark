# Corpus Batch Recompile Results

- Generated: 2026-03-20T04:31:40.288141+00:00
- Inventory: `/home/yunwei37/workspace/bpf-benchmark/docs/tmp/corpus-runnability-results.json`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- Requested mode: `strict-vm`
- Effective mode: `vm`
- Repeat: 10
- Skip families: `none`
- Target programs: 1
- Compile pairs: 1
- Measured pairs: 1
- Recompile applied programs: 1
- Code-size ratio geomean (baseline/v5): 1.000x
- Exec-time ratio geomean (baseline/v5): 0.843x
- Total sites: 13
- CMOV sites: 0
- WIDE sites: 0
- ROTATE sites: 10
- LEA sites: 0
- EXTRACT sites: 0
- ZERO-EXT sites: 0
- ENDIAN sites: 1
- BRANCH-FLIP sites: 2
- Kernel build: ok (0.00s)
- Guest kernel: `7.0.0-rc2-gce00e19bd75f-dirty`

## By Project

| Project | Programs | Compile Pairs | Measured Pairs | Applied | CMOV | WIDE | ROTATE | LEA | EXTRACT | ZERO-EXT | ENDIAN | BRANCH-FLIP | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| calico | 1 | 1 | 1 | 1 | 0 | 0 | 10 | 0 | 0 | 0 | 1 | 2 | 1.000x | 0.843x | 1 |

## By Family

| Family | Programs | Applied | Sites | Applied Sites | Compile Pairs | Measured Pairs | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| rotate | 1 | 1 | 10 | 10 | 1 | 1 | 1.000x | 0.843x | 1 |
| branch-flip | 1 | 1 | 2 | 2 | 1 | 1 | 1.000x | 0.843x | 1 |
| endian | 1 | 1 | 1 | 1 | 1 | 1 | 1.000x | 0.843x | 1 |
| cmov | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| extract | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| lea | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| wide | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| zero-ext | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |

## Regressions

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_maglev | calico | sched_cls | 0.843x | rotate, endian, branch-flip |

## Per-Program Results

| Program | Project | Type | Sites | Applied Families | Baseline JIT | v5 JIT | Code Ratio | Baseline ns | v5 ns | Exec Ratio | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_maglev | calico | sched_cls | 13 | rotate, endian, branch-flip | 3260 | 3260 | 1.000x | 107 | 127 | 0.843x |  |

## Notes

- Target selection comes from the runnability inventory and keeps every packet-test-run target whose baseline run already succeeds; the current scanner pass determines whether v5 has any eligible families.
- In strict VM mode, each target boots the framework v5 guest once and runs baseline compile-only, v5 compile-only, baseline test_run, and v5 test_run in that order.
- Default steady-state semantics are stock: without `--use-policy` or `--blind-apply`, the v5 lane does not request recompile.
- `--use-policy` only considers per-program version 3 policy files under `corpus/policies/`; if no match exists, the driver stays on stock JIT.
- `--blind-apply` forces the old debug/exploration path with `--recompile-v5 --recompile-all`.
- `--skip-families` only applies together with `--blind-apply`; the family columns above report applied families, not just eligible sites.
- Host fallback mode only does baseline compile-only plus offline scanner scan; it does not attempt recompile or runtime measurement.
- Family summaries are overlap-based: one program can contribute to multiple family rows, so those rows are not isolated causal attributions.
