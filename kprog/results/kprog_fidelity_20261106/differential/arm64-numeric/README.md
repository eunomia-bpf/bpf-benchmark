# AArch64 numeric SP and outer-return observations

| Comparison | Forms | Cases | Mismatches |
| --- | ---: | ---: | ---: |
| Native AArch64 execution under QEMU versus production C simulator |567|580608|0|
| Same saved CPU states versus canonical Lean reference |567|580608|0|
| Full control sequences, including SP/LR flags and every spill byte width |97|99328|0|

`forms.tsv` and `reference-forms.tsv` retain per-form counts; each mismatch
file is empty. `control/forms.tsv` includes20 added numeric-address controls.
QEMU is functional evidence; the supplied static binaries remain a hardware
handoff. Earlier real Spark results cover the earlier matrices, not this fix.

The simulator formerly exposed a stack offset or outer-return token as its
numeric value. The fix lazily reads the invocation-stable entry SP/return
inputs already bound by the loader/module. Scalar reads, flags, narrow writes
and guest spill bytes observe native bits; pointer addressing and control
return dispatch retain relative payloads. A complete aligned spill stores the
relative payload separately from guest bytes; partial stores invalidate its
tag before any reload. This preserves typed pointer restoration without
changing the bytes a native narrow/vector load observes. An identity compiler
barrier retains out-of-bounds accesses for verifier analysis; it adds no bound,
branch or native safety check. The first erased-OOB acceptance is retained in
the negative evidence, alongside its rejection after repair.

`KProgFormal.Refinement.Arm64NumericAddress` checks numeric read projection,
SP scalar-write normalization and the guest-byte/private-payload relation.
These are supporting refinement lemmas, not a complete whole-program C proof.
The full `make -C kprog/formal check` passes on the exact published baseline
plus13 F numeric paths recorded in `numeric-source.json`; `formal-full.log.gz`
retains the complete output. Earlier failed integration checks are preserved.
Nine existing routing oracles pass, and all29 workload-derived proofs plus the
existing negative proof compile. CPU/reference, focused oracle and build logs
are retained here. `source-inputs.tar.gz` freezes both observers and their
header/generator dependencies. `source-provenance.txt` distinguishes the
combined observer header from the isolated numeric formal candidate.

Commands from the repository root, under `taskset -c 16-23`:

```sh
make -C kprog/results/kprog_fidelity_20261106/differential/arm64-numeric run
make -C kprog/results/kprog_fidelity_20261106/differential/arm64-numeric control
make -C kprog/results/kprog_fidelity_20261106/differential/arm64-numeric reference
make -C kprog/results/kprog_fidelity_20261106/differential/arm64-numeric host lean
make -C kprog/arm64 micro-proofs-build PROOF_BUILD_DIR=build-f-numeric/proofs NEGATIVE_PROOF_BUILD_DIR=build-f-numeric/negative NEGATIVE_NATIVE_BUILD_DIR=build-f-numeric/native MICRO_SIM_PROOF_ARGS='--jobs 4'
```

On actual arm64 hardware, from `kprog/fidelity`, the existing scripts run each
new static binary without a compiler or cross-toolchain:

```sh
ARM64_HANDOFF=../results/kprog_fidelity_20261106/differential/arm64-numeric/cpu-differential-arm64-numeric.gz OUT=../results/kprog_fidelity_20261106/differential/arm64-numeric/hardware sh run-arm64.sh
ARM64_CONTROL_HANDOFF=../results/kprog_fidelity_20261106/differential/arm64-numeric/cpu-differential-arm64-control-numeric.gz OUT=../results/kprog_fidelity_20261106/differential/arm64-numeric/control-hardware sh run-arm64-control.sh
```
