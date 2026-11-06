# Repaired exclusive-store observed-state replay

After A's production choice repair a7e5d6d8f, the8 W/X LDXR/LDAXR/STXR/STLXR
forms ×1024 QEMU states now have **8192 cases /zero observed-state differences**.
The former4096 store differences remain in ../arm64-exclusive/. All31 GPRs,
SP/NZCV, all32 vectors and memory bytes are compared.

Every store observer executes CLREX immediately before its native byte span.
Its host simulator hook explicitly returns failure1 only for the four recorded
store sites, and rejects an unknown site. This is a fixture for that known
empty monitor, not a default for arbitrary entry monitors or paired attempts.
A's production BPF path uses T's bound fresh choice and conditional store;
there is no production constant-success/failure fallback or random helper.
The related full negative suite rejects all four formerly accepted failure
branches on T's actual new#24 kernel/module (../.. /negative/arm64-current-choice).

This observer compares architectural registers and memory. It does not capture
physical reservation granules, translation, interference or acquire/release
ordering. Zero load-row differences do not establish those effects. The
explicit canonical monitor/environment model and its properties remain in
../arm64-exclusive/canonical/; a complete platform/event refinement is separate
from this concrete observed-state experiment.

```sh
taskset -c 16-19 prlimit --as=12884901888 -- make -C kprog/fidelity -f bank32.mk run-qemu BUILD=build-arm64-exclusive-choice FAMILY=exclusive CASES=1024 OUT=../results/kprog_fidelity_20261106/differential/arm64-exclusive-choice
```

Exact harness/production headers/imports, generated C/native assembly and
static binary are archived, together with per-form counts/PCs and the empty
mismatch JSONL. The new static hardware handoff is
../cpu-differential-arm64-exclusive-choice.gz, usable with ARM64_HANDOFF and
the existing run-arm64.sh. QEMU evidence is not Arm hardware timing.
