# OTel checked-C compiler cost

The completed LLVM O3 diagnostic attributes 86.7% of reported pass wall time to
InstCombine (44.3%) and SROA (42.4%). This directs further compiler work toward
the expanded simulator's scalar operations and aggregate accesses. The earlier
literal-helper specialization already reduced preprocessed input from
1,011,998,390 to 370,116,027 bytes while preserving allocated B code and
relocations; this diagnostic examines the optimization cost that remains.

| Measurement | Observed value |
| --- | ---: |
| Process exit | 0 |
| Process wall time | 3,150.007 s |
| Process user CPU time | 3,016.280 s |
| Peak RSS | 13,934,196 KiB |
| LLVM pass wall time | 3,085.168 s |
| InstCombine wall time | 1,365.325 s |
| SROA wall time | 1,307.632 s |
| Correlated value propagation wall time | 290.244 s |
| Jump threading wall time | 62.635 s |

The input is the archived OTel main simulator's unoptimized IR. The command is
`opt-18 -passes='default<O3>' -debug-pass-manager -time-passes unoptimized.bc -o optimized.bc`;
[optimization.json](optimization.json) preserves the full absolute arguments,
process timing and scope. [passes.csv](passes.csv) contains every pass row,
and [optimization.log](optimization.log) contains LLVM's original output.
Raw IR, optimized bitcode and job files remain under
`/workspaces/kprog-raw/perf/20261114-otel-compiler-breakdown/`.

This is one compiler-cost diagnostic on shared E-cores 16–17. The process's
existing 80 GiB address-space budget protected the host. Clang target hooks may
give its integrated pipeline different behavior. Syntax-only and IR-generation
probes are retained in the adjacent `otel-compiler-cost-breakdown.json`.
These timings describe this compiler replay; actual stock-verifier acceptance,
application performance and M4 completion retain their separate work items.

Regenerate the collected table and logs with:

```sh
python3 kprog/test/collect_compiler_cost.py \
  --raw /workspaces/kprog-raw/perf/20261114-otel-compiler-breakdown \
  --output kprog/results/perf_20261113/otel-compiler-cost-final
```
