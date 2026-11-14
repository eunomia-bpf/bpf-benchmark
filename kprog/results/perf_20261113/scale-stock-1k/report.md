# Production stock scale: 100/1K subset complete

All eight 100/1K scalar/pointer × direct/indirect cases pass real stock
verification and execution. Every loader returns0 and reports the independent
expected packet value and XDP_PASS; `kernel-cases.json` and `kernel.csv`
retain the full observations, actual B/verified instruction counts, verifier
time and traced memory intervals. `native-source-parity.json` confirms all
eight native assembly fixtures equal the original legacy fixtures.

This uses production ordinary-input/chunk preprocessing/B IR compilation,
the single scratch build, the sole kernel and the actual libbpf loader.
The earlier legacy private-opcode failures remain separate results. Scalar
arithmetic folds atO3, so these are capacity/correctness fixtures rather than
runtime speedup evidence. The eight completed traces record zero lost events;
all raw traces and logs remain persistent. Stage exit0 is backed by actual
per-case loader status and execution output, not trace-cmd's exit alone.

The1K compiler resources and commands are retained separately in
`compiler-resources.json`. Runs share the host with the ongoing OTel/census
guests; compiler wall costs are not isolated timing comparisons. Raw data:
`/workspaces/kprog-raw/perf/20261114-scale-stock` (compile records and
`batch/subset-kernel`). The full batch666038 has advanced to production
10K/100K compilation; final all-case kernel results remain pending.

This subset closes production100/1K validation. FullV3, checked OTel whole
application, equal work and the1.20 target remain open.
