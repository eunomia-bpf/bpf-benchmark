# Production stock scale compiler: four 100-instruction cases

All four scalar/pointer × direct/indirect fixtures compile through the existing
production `trusted_specializer.compile_simulator` and load/execute on the
sole stock kernel. Actual loader status0 and one real test-run observation
are retained for each case, matching its independent arithmetic reference
and XDP_PASS. The scalar direct/indirect outputs are17694198624199650402/405;
pointer outputs56/59. B has31/32 and279/281 instructions respectively.
The scalar arithmetic folds atO3; this is a capacity/correctness fixture,
not a runtime speedup measurement.

The generated native assembly is byte-identical to all four previous scale
fixtures, and the instruction count/reference result is unchanged. The
production ordinary-input header replaces the legacy private encoding, and
the B IR compiler removes unused private-input reads. These four final
objects import only `bpf_cast_to_kern_ctx`; no live unspecified-input map
relocation remains. The actual libbpf loader resolves the kernel call;
no fabricated map binding or verifier change was needed.

The first scratch-backed guest attempt could not see its nested var-tmp
mount and failed with ENOENT before verification.9d8e1288b maps the single
scratch build to guest `/var/tmp`; the same compiled objects then passed.
Both attempts' logs and traces remain persistent. d9ae8bb90 adds the explicit
stock-pipeline selection and separates rebuildable products from raw records,
without copying simulator headers or the encoder.

Single build: `/var/tmp/kprog-tmp/perf/scale`. Raw records, commands, resources,
loader logs and verifier/allocation traces:
`/workspaces/kprog-raw/perf/20261114-scale-stock`. Kernel run uses18–19,
2vCPU/8GiB,16GiB host address-space limit and imageSH. It retains every
allocation interval and zero lost events in these four recorded traces.
The100/1K subset and full100–100K production scale work remain in progress;
old legacy compiler failures retain their separate published receipts.

The existing1K build continues in the same build location. `batch-queue.json`
records the bounded background queue that waits for it, verifies100/1K,
compiles10K/100K through production, then records the final kernel batch.
Every stage's status/log is retained; the larger results remain pending.
