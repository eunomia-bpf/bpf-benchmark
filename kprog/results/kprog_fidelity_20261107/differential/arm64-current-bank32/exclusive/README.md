# Current production exclusive observed-state replay

Eight W/X LDXR/LDAXR/STXR/STLXR forms ×1024 QEMU cases =8192 states,
zero QEMU/C differences. All31 GPRs, SP/NZCV,32 vectors and memory are
observed. Each native observer executes CLREX immediately before native_pc;
the C fixture supplies failure1 only for its four explicit store sites and
rejects any unknown site. This is not a production default or evidence for
paired store success, physical reservations or acquire/release ordering.

QEMU/build exited0. The canonical Make exited2: all8 requests were rejected
with `reference: exclusive instruction requires explicit monitor state`.
`reference-forms.tsv` records zero canonical cases for every form;
`reference-unavailable.jsonl.gz` retains all eight complete first requests.
No missing monitor/environment fields were guessed to turn this into a pass.
The explicit canonical model/properties remain in the historical
arm64-exclusive/canonical result; the physical-monitor relation and current
CPU/canonical replay are still open.

`summary.json`, per-form tables, exact static binary, native PCs, empty
QEMU/C mismatch stream and verified compiled source closure are preserved.
This is functional emulation; actual ARM hardware replay is pending.

```sh
taskset -c 16-19 make -C kprog/fidelity -f bank32.mk run-qemu BUILD=build-arm64-exclusive-choice FAMILY=exclusive CASES=1024 OUT=../results/kprog_fidelity_20261107/differential/arm64-current-bank32/exclusive
taskset -c 16-19 make -C kprog/fidelity -f bank32.mk reference BUILD=build-arm64-exclusive-choice FAMILY=exclusive CASES=1024 OUT=../results/kprog_fidelity_20261107/differential/arm64-current-bank32/exclusive REFERENCE=build-x86-control/reference/.lake/build/bin/reference
```

Coordinator hardware observation (does not discharge canonical inputs):

```sh
ARM64_HANDOFF=../results/kprog_fidelity_20261107/differential/arm64-current-bank32/exclusive/cpu-differential-arm64.gz OUT=../results/kprog_fidelity_20261107/differential/arm64-current-bank32/exclusive-hardware sh kprog/fidelity/run-arm64.sh
```
