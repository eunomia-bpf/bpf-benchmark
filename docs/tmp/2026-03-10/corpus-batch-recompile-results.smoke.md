# Corpus Batch Recompile Results

- Generated: 2026-03-11T04:47:16.324109+00:00
- Inventory: `/home/yunwei37/workspace/bpf-benchmark/docs/tmp/corpus-runnability-results.json`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- Requested mode: `strict-vm`
- Effective mode: `vm`
- Repeat: 200
- Target programs: 1
- Compile pairs: 1
- Measured pairs: 1
- Recompile applied programs: 1
- Code-size ratio geomean (baseline/v5): 1.046x
- Exec-time ratio geomean (baseline/v5): 0.742x
- Total sites: 10
- CMOV sites: 0
- WIDE sites: 0
- ROTATE sites: 10
- LEA sites: 0
- Kernel build: ok (1.61s)
- Guest kernel: `7.0.0-rc2-g2a6783cc77b6`

## By Project

| Project | Programs | Compile Pairs | Measured Pairs | Applied | CMOV | WIDE | ROTATE | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| calico | 1 | 1 | 1 | 1 | 0 | 0 | 10 | 1.046x | 0.742x | 1 |

## By Family

| Family | Programs | Applied | Sites | Compile Pairs | Measured Pairs | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| rotate | 1 | 1 | 10 | 1 | 1 | 1.046x | 0.742x | 1 |
| cmov | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| lea | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| wide | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |

## Regressions

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_maglev | calico | sched_cls | 0.742x | rotate |

## Largest Code Shrinks

| Program | Project | Type | Code Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_maglev | calico | sched_cls | 1.046x | rotate |

## Per-Program Results

| Program | Project | Type | Sites | Applied Families | Baseline JIT | v5 JIT | Code Ratio | Baseline ns | v5 ns | Exec Ratio | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_maglev | calico | sched_cls | 10 | rotate | 3267 | 3124 | 1.046x | 175 | 236 | 0.742x |  |

## Notes

- Target selection comes from the runnability inventory and keeps only the 79 packet-test-run programs that previously formed a paired baseline/recompile set with directive sites.
- In strict VM mode, each target boots the framework v5 guest once and runs baseline compile-only, v5 compile-only, baseline test_run, and v5 test_run in that order.
- Host fallback mode only does baseline compile-only plus offline scanner scan; it does not attempt recompile or runtime measurement.
- Family summaries are overlap-based: one program can contribute to multiple family rows, so those rows are not isolated causal attributions.
