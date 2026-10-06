# Corpus Batch Recompile Results

- Generated: 2026-03-24T12:08:42.937349+00:00
- Inventory: `/home/yunwei37/workspace/bpf-benchmark/docs/tmp/corpus-runnability-results.json`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/runner/build/micro_exec`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Requested mode: `strict-vm`
- Effective mode: `vm`
- Repeat: 1
- Skip families: `none`
- Target programs: 2
- Compile pairs: 2
- Measured pairs: 2
- Recompile applied programs: 1
- Code-size ratio geomean (baseline/v5): 0.998x
- Exec-time ratio geomean (baseline/v5): 0.711x
- Total sites: 33
- CMOV sites: 11
- WIDE sites: 12
- ROTATE sites: 10
- LEA sites: 0
- EXTRACT sites: 0
- ENDIAN sites: 0
- BRANCH-FLIP sites: 0
- Guest kernel: `7.0.0-rc2+`

## By Project

| Project | Programs | Compile Pairs | Measured Pairs | Applied | CMOV | WIDE | ROTATE | LEA | EXTRACT | ENDIAN | BRANCH-FLIP | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| calico | 2 | 2 | 2 | 1 | 11 | 12 | 10 | 0 | 0 | 0 | 0 | 0.998x | 0.711x | 2 |

## By Family

| Family | Programs | Applied | Sites | Applied Sites | Compile Pairs | Measured Pairs | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| wide | 1 | 0 | 12 | 0 | 1 | 1 | 1.000x | 0.717x | 1 |
| cmov | 1 | 0 | 11 | 0 | 1 | 1 | 1.000x | 0.717x | 1 |
| rotate | 1 | 1 | 10 | 10 | 1 | 1 | 0.996x | 0.706x | 1 |
| branch-flip | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| endian | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| extract | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| lea | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |

## Regressions

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_maglev | calico | sched_cls | 0.706x | rotate |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main | calico | sched_cls | 0.717x | cmov, wide |

## Per-Program Results

| Program | Project | Type | Sites | Applied Families | Baseline JIT | v5 JIT | Code Ratio | Baseline ns | v5 ns | Exec Ratio | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_maglev | calico | sched_cls | 10 | rotate | 3267 | 3279 | 0.996x | 3121 | 4419 | 0.706x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main | calico | sched_cls | 23 |  | 46216 | 46216 | 1.000x | 3517 | 4908 | 0.717x |  |

## Notes

- Target selection comes from the runnability inventory and keeps every packet-test-run target whose baseline run already succeeds; the current daemon pass determines whether v5 has any eligible families.
- In strict VM mode, the framework v5 guest boots once, keeps `daemon serve` alive for the full batch, and runs baseline compile-only, v5 compile-only, baseline test_run, and v5 test_run for each target in that order.
- Default steady-state semantics: the daemon is always started and tries to optimize each program; programs with no applicable sites stay on stock JIT.
- `--blind-apply` forces the old debug/exploration path with `--recompile-v5 --recompile-all`.
- `--skip-families` only applies together with `--blind-apply`; the family columns above report applied families, not just eligible sites.
- The Make-driven `vm-corpus` path is strict VM-only: guest batch failures fail the run instead of falling back to host execution.
- Family summaries are overlap-based: one program can contribute to multiple family rows, so those rows are not isolated causal attributions.
