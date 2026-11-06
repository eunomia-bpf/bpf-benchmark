# Complete canonical replay of the original567-form Arm matrix

All **567 forms /580608 saved CPU cases** now have canonical decoder coverage.
CPU/reference differences are **zero**. The4096 prior simulator SP/WSP numeric
address differences remain, with full counterexample inputs retained. There
are **zero missing canonical encodings** in this original matrix. This closes
its fourteen scalar pre/post/index and Q0-memory decoder rows; it is not a claim
that the older matrix covered every production family. The later255-form
memory expansion and8 exclusive forms have their own reports.

```sh
taskset -c 16-23 prlimit --as=12884901888 -- make -C kprog/results/kprog_fidelity_20261106/differential/arm64-addressed-memory snapshot reference
```

The command returns1 for those4096 model differences. It reads the same trace
at ../arm64-sp-reference/cpu-states.bin and does not rerun the CPU. The canonical
source/binary are frozen here; this snapshot predates the later pair writeback
extension, which was unnecessary for these567 forms. Complete counts, errors
(empty missing-encoding JSONL), counterexamples and command log are preserved.
