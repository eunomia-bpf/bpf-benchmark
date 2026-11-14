# Corrected OTel main: stock verification and checked native installation

The corrected OTel main proof passed stock verification, then the production
checked-simulator compiler reused its retained pre-bounds IR, compiled native
code and installed program 14. `verify.stdout` and `load.stdout` report zero
status for the same kernel request. `result.json` records successful completion
and a zero-status submission reply. The proof's frame is 512 bytes.

The transform uses explicit 64-bit shifts to clear the upper half. The earlier
self-copy counterexample and 2,120 corrected stock-kernel value executions are
retained in `../whole-word-spill-values/`. This result uses the corrected proof
stored here as `accepted.bpf.o`. The checked native object and its proof are
also retained, together with every native compiler command and the existing
frontend-IR binding record.

The replay recreated the original program type and map shapes using the source
BPF object and captured application settings. `generation.metadata.json`
matches the retained request; `resources.json` records the map adjustments.
The source C and pre-bounds IR came from that original main request's archive.
This diagnostic creates maps and installs the program. Application startup,
map population, attachment and workload execution are the next experiment.

The VM used the sole kernel, CPUs 22–23, one vCPU, 8 GiB and a shared image
lock. `command.json` and `load-command.json` contain the actual loader commands.
The raw launch log and retained evidence remain at
`/workspaces/kprog-raw/perf/20261114-scalar-spill-precision/checked-main-fixed`.
Rebuildable compiler files live under
`/var/tmp/kprog-tmp/perf/retained-proof-otel-main`, mapped to guest `/var/tmp`.

The optional production B backend is selected with
`KPROG_BPF_WHOLE_WORD_SPILLS=1` (commit `fb6695afa`). It chooses an eligible
scalar pair from each physical MIR function. The default value zero preserves
the previous compiler invocation. The committed backend integration test
confirms full default/explicit-zero object equality with the previous command
and actual execution of the optional LLVM backend. `backend-parity.json` and
`backend-commands.json` preserve that subset check. The automatic fixture output
also equals the manually selected fixture already executed in the kernel.

The separate application diagnostic uses the unchanged same-source OTel
producer and the corrected combined LTO linker. Its command is:

```sh
make -f kprog/test/scalar-spill-precision.mk checked-corpus \
  OUTPUT=/workspaces/kprog-raw/perf/20261114-otel-whole-word-checked \
  REPLAY_BUILD=/var/tmp/kprog-tmp/perf/otel-whole-word-checked
```

It uses two vCPUs, 48 GiB, CPUs 16–17 and the existing verified corpus entry
point with one ten-second sample. This is an application diagnostic. The
combined direct-P measurements, equal-work investigation, performance target
and final six-application confirmation retain their previous scope.
