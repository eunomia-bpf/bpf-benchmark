# Shared benchmark results

Raw corpus runs are under [`corpus/results/`](../../corpus/results/) and raw
micro runs are under [`micro/results/`](../../micro/results/). Test artifacts
are under [`tests/results/`](../../tests/results/). These directories retain
the original `result.json` records; the reorganization does not alter them.

| Question | Current interpretation |
| --- | --- |
| kprog native execution | [kprog evaluation](../../kprog/docs/evaluation.md) |
| kinsn inline kfuncs | [kinsn evaluation](../../kinsn/docs/evaluation.md) |
| Speculative ReJIT | [ReJIT evaluation](../../rejit/docs/evaluation.md) |
| Cross-runtime micro characterization | [micro benchmark status](micro-bench-status.md) |
| Corpus workload selection | [workload tuning log](../workload.md) |

Run `make micro` or `make corpus` from the repository root to create new
results. For exact datasets, sample counts, and commands used in a claim,
follow the corresponding project evaluation document. Dated investigations
are retained in the [shared archive](../archive/shared/README.md).
