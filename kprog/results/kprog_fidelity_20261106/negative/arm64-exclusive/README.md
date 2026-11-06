# Accepted unsafe exclusive-store failure branches

All four unsafe programs load successfully through the actual Arm
generation-bound path: one chunk and generation1 each. No unsafe native
candidate is executed.

| Program | Bound program ID | Outcome |
| --- | ---: | --- |
| Unpaired STXR, NULL read on failure | 8 | accepted safety finding |
| Unpaired STLXR, NULL read on failure | 16 | accepted safety finding |
| LDXR/STXR, NULL read on failure | 24 | accepted safety finding |
| LDAXR/STLXR, NULL read on failure | 32 | accepted safety finding |
| Unpaired STXR, unconditional safe return | 40 | positive control accepted |
| LDXR/STXR, unconditional safe return | 48 | positive control accepted |

Every body allocates and initializes16 stack bytes, stores through its aligned
stack address and branches on the actual32-bit exclusive status. The simulator
currently forces success and removes the native failure branch. The paired
forms are also unsafe: interference or monitor failure can make a store fail
after its matching exclusive load. The exact native assembly and bound outcome
for every row remain in `before/outcomes.json`; positive-control rows are
explicitly marked separately.

The permanent25-case Arm suite now reports9 verifier rejections,9
specialization rejections,1 loader rejection and6 accepted findings: four new
exclusive failures plus the two earlier numeric SP/LR address-state findings.
All11 original negatives and the repaired SP-alignment/LDP/writeback negatives
still reject. The full suite exits1 for these findings and has zero
infrastructure errors. `full-before/outcomes.json` retains all25 exact results.
No prior accepted case or failed run is dropped.

```sh
taskset -c 16-23 make -C kprog/results/kprog_fidelity_20261106/negative/arm64-exclusive build run
taskset -c 16-23 make -C kprog/results/kprog_fidelity_20261106/negative/arm64-exclusive full-build full-run
```

The targeted first command records its six outcomes without hiding the
acceptances; the full suite exits nonzero. Both commands use the matched
runtime assets saved by `../arm64-sp-alignment/artifacts.tar.gz`, cortex-a57,
2vCPUs and2GiB, on host CPUs16–23. `before-artifacts.tar.gz` restores all
native/proof fixtures, frozen production source closure, compiler diagnostics
and permanent-suite inputs under `kprog/fidelity/build-arm64/exclusive-bound/`.
Common runtime assets and initramfs files are deduplicated/rebuilt using the
existing saved package recipe. `before-raw-logs.tar.gz` preserves complete
guest and per-case logs; compressed Make logs retain commands and exit status.

The paired CPU evidence is in `../../differential/arm64-exclusive/README.md`:
all4096 STXR/STLXR cases after CLREX return failure/no-write on QEMU while C
returns success/write. A owns the production encoder/C/shared-contract repair;
F owns the canonical monitor model and replay; T owns the per-site proof-input
interface needed to check every admissible failure/success outcome. The repair
is active. No constant-status replacement, fake helper effect, program
exclusion or verified-path waiver is accepted as closure.
