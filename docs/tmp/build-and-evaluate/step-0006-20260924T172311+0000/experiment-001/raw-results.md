# Raw Results: Preserve Load-Time Bytecode Evidence

Date: 2026-09-24

## Focused build

Command:

```sh
timeout 120s make -C bpfopt/shim all
```

Exit code: `0`.

The shim shared library and both host selftest binaries compiled with
`-Wall -Wextra`.  The compiler emitted only pre-existing warnings in
`shim_reload.h` and `selftest_full.c`; no warning names the changed
`shim_loadtime.h` code.

Commands:

```sh
python3 -m py_compile analysis/audit_loadtime_evidence.py
git diff --check -- bpfopt/shim/shim_loadtime.h analysis/audit_loadtime_evidence.py
```

Both exited `0` with no output.

## Historical negative regression oracle

Command:

```sh
timeout 120s python3 analysis/audit_loadtime_evidence.py \
  corpus/results/x86_kvm_corpus_20260919_041801_813418 \
  --app cilium/agent --expected-pass map_inline \
  --expected-samples 1 --expected-workload-seconds 30
```

Exit code: `1`, as required.

Key output:

```text
error: invalid/inconclusive evidence: 244 integrity errors
outcome: invalid/inconclusive
changed_workdirs: 122
input_matches_reported_before: 0
mutable_input_matches_reported_after: 122
retained_output_next_0: 0
output_matches_reported_after: 0
missing input.step.0.bin: 122
missing output.next.0.bin: 122
```

The unchanged report/log/workload totals remain 122 successful changed loads,
3,787 applied sites, baseline 1,576,821 pps, policy 1,623,352 pps, and the
descriptive single-run ratio `1.0295093736067695`.  The new source did not
manufacture evidence in the historical workdirs.

## Source dataflow

With workdir retention enabled, step N now copies the current canonicalized
input to `input.step.N.bin`, invokes the optimizer to produce
`output.next.N.bin`, verifies and records the candidate, and copies the retained
output to mutable `input.bin`.  With retention disabled, the original
`rename(output.next.N.bin, input.bin)` path remains selected.

No KVM benchmark was started in this step.  Concurrent uncommitted
`bpfopt/llvm/src/llvm_mapinline.hpp` changes would alter the tested optimizer
without appearing in the recorded source revision; the next Make-backed run is
deferred until that owner resolves the relevant state.
