# Corpus Batch Recompile Results

- Generated: 2026-03-12T20:55:31.682561+00:00
- Inventory: `/home/yunwei37/workspace/bpf-benchmark/docs/tmp/corpus-runnability-results.json`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- Requested mode: `strict-vm`
- Effective mode: `vm`
- Repeat: 5
- Skip families: `none`
- Target programs: 1
- Compile pairs: 1
- Measured pairs: 1
- Recompile applied programs: 0
- Code-size ratio geomean (baseline/v5): 1.000x
- Exec-time ratio geomean (baseline/v5): 0.517x
- Total sites: 3
- CMOV sites: 1
- WIDE sites: 1
- ROTATE sites: 0
- LEA sites: 0
- EXTRACT sites: 0
- ZERO-EXT sites: 0
- ENDIAN sites: 1
- BRANCH-FLIP sites: 0
- Kernel build: ok (0.00s)
- Guest kernel: `7.0.0-rc2-ge52504a75c05-dirty`

## By Project

| Project | Programs | Compile Pairs | Measured Pairs | Applied | CMOV | WIDE | ROTATE | LEA | EXTRACT | ZERO-EXT | ENDIAN | BRANCH-FLIP | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| linux-selftests | 1 | 1 | 1 | 0 | 1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 | 1.000x | 0.517x | 1 |

## By Family

| Family | Programs | Applied | Sites | Applied Sites | Compile Pairs | Measured Pairs | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| cmov | 1 | 0 | 1 | 0 | 1 | 1 | 1.000x | 0.517x | 1 |
| endian | 1 | 0 | 1 | 0 | 1 | 1 | 1.000x | 0.517x | 1 |
| wide | 1 | 0 | 1 | 0 | 1 | 1 | 1.000x | 0.517x | 1 |
| branch-flip | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| extract | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| lea | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| rotate | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| zero-ext | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |

## Regressions

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:decap_f | linux-selftests | sched_cls | 0.517x | cmov, wide, endian |

## Per-Program Results

| Program | Project | Type | Sites | Applied Families | Baseline JIT | v5 JIT | Code Ratio | Baseline ns | v5 ns | Exec Ratio | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:decap_f | linux-selftests | sched_cls | 3 |  | 696 | 696 | 1.000x | 62 | 120 | 0.517x |  |

## Notes

- Target selection comes from the runnability inventory and keeps every packet-test-run target whose baseline run already succeeds; the current scanner pass determines whether v5 has any eligible families.
- In strict VM mode, each target boots the framework v5 guest once and runs baseline compile-only, v5 compile-only, baseline test_run, and v5 test_run in that order.
- Default steady-state semantics are stock: without `--use-policy` or `--blind-apply`, the v5 lane does not request recompile.
- `--use-policy` only considers per-program version 2 policy files under `corpus/policies/`; if no match exists, the driver stays on stock JIT.
- `--blind-apply` forces the old debug/exploration path with `--recompile-v5 --recompile-all`.
- `--skip-families` only applies together with `--blind-apply`; the family columns above report applied families, not just eligible sites.
- Host fallback mode only does baseline compile-only plus offline scanner scan; it does not attempt recompile or runtime measurement.
- Family summaries are overlap-based: one program can contribute to multiple family rows, so those rows are not isolated causal attributions.
