# Experiment 001 Plan: Preserve Load-Time Bytecode Evidence

Date: 2026-09-24T17:23:11+00:00
Phase: BUILD_AND_EVALUATE
Selected paper question: RQ1, "Does Load-Time Specialization Work End to End?"
Role: dependency fix required by the step-0005 invalid/inconclusive audit.

## Paper-value admission

Step 0005 found that retained load-time workdirs overwrite the canonicalized
pre-step bytecode when `output.next.N.bin` is renamed to `input.bin`.  Reports
and load events survive, but the actual before image does not.  No amount of
post-hoc analysis can recover it.  Preserving immutable per-step inputs and
outputs is therefore the smallest source change that enables the next decisive
current Cilium experiment.

This step changes evidence retention only when `KEEP_WORKDIRS` is enabled.  It
does not change optimizer policy, BPF instructions submitted to the kernel,
application code, workloads, runner behavior, launch wiring, or the two-start
protocol.  It does not add an experiment-admission gate.  The step has no paper
result by itself; its paper value is enabling directly auditable mechanism
evidence in the next Make-backed run.

## Hypothesis and competing explanation

The hypothesis is that the shim can retain an immutable
`input.step.N.bin` immediately before each optimizer step and leave the
corresponding `output.next.N.bin` intact, while copying that verified output
to the mutable `input.bin` used by the following step and final load.  The
competing explanation is that retention changes the installed bytes, breaks
multi-step sequencing, or silently succeeds when a copy fails.

## Change and validation contract

The implementation is local to `bpfopt/shim/shim_loadtime.h`:

1. Add one fail-fast file-copy helper with no fallback.
2. When workdir retention is enabled, copy the current canonicalized bytecode
   to `input.step.N.bin` immediately before executing step N.
3. After the candidate passes the existing verifier probe and its report is
   appended, copy `output.next.N.bin` to mutable `input.bin` instead of
   renaming it.  The retained output remains immutable evidence.
4. When retention is disabled, keep the existing rename path unchanged.
5. Update the analysis audit to require `input.step.0.bin` and
   `output.next.0.bin` for a changed one-step report.

Every new copy error is fatal and propagated through the existing load-time
error path.  The implementation must compile with `-Wall -Wextra`.  A source
inspection must show that both retained files are written before the mutable
input advances and that the non-retained path still uses `rename`.

Validation commands are:

```sh
timeout 120s make -C bpfopt/shim all
python3 -m py_compile analysis/audit_loadtime_evidence.py
git diff --check -- bpfopt/shim/shim_loadtime.h analysis/audit_loadtime_evidence.py
```

The existing step-0005 artifact is then re-audited.  It must remain
`invalid/inconclusive` and exit nonzero because historical before files cannot
be manufactured by the new code.  This is the negative regression oracle:

```sh
timeout 120s python3 analysis/audit_loadtime_evidence.py \
  corpus/results/x86_kvm_corpus_20260919_041801_813418 \
  --app cilium/agent --expected-pass map_inline \
  --expected-samples 1 --expected-workload-seconds 30
```

## Resource and completion boundary

A new throughput run is deliberately not part of this source-fix step.  The
shared tree currently contains unrelated uncommitted changes to `Makefile`,
`runner/scripts/qemu-arm64-init`, and, critically, `bpfopt/llvm/src/llvm_mapinline.hpp`
owned by concurrent work.  Building a paper artifact now would mix an
uncommitted `map_inline` implementation with this retention fix and give the
recorded Git revision incomplete provenance.  The user explicitly required
protecting dirty work and avoiding resource conflict, so this step will not
touch, stage, revert, or incorporate those files.

Completion requires the focused build and negative regression oracle to
behave as declared, an independent result review of the source/dataflow, and a
precise commit/push of only this step's files.  The immediate next experiment,
once the owner resolves the relevant dirty optimizer state, is exactly:

```sh
BPFREJIT_CORPUS_APPS=cilium/agent \
BPFREJIT_BENCH_PASSES=map_inline SAMPLES=1 WORKLOAD_DURATION=30 \
KEEP_WORKDIRS=1 make corpus
```

That future run must be analyzed as a new current artifact.  It will not be
combined causally with either the July repeated batches or the September 19
single observation.
