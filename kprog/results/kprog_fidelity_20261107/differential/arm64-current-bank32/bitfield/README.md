# Current production bitfield full-bank replay

**70 forms × 1024 = 71,680 states**, with zero QEMU/C,
QEMU/canonical or C/canonical mismatches and zero unavailable forms.
Build/QEMU and reference both exited0. All31 GPRs, SP/NZCV, all32 independent
vector registers and data memory are compared. This is functional QEMU
evidence; actual ARM hardware execution remains pending.

`forms.tsv` and `reference-forms.tsv` retain every form's case count.
All three compressed failure/unavailable streams are empty. `summary.json`
pins the full local trace, static executable and same f1c5 canonical reference
used by x86-control (its ARM source matches current canonical source).
The canonical source/executable archive is in `../../x86-control/` relative
to this directory. `compiled-inputs.json` and its verified archive preserve
the actual production header/encoder snapshot and generated/observer inputs.
This does not establish invocation ABI, ordering or universal O1–O4.

The missing owned build-arm64-bitfield cache was restored only from its historical
committed harness archive, then existing Make dependencies incrementally
rebuilt changed inputs. Historical outputs and other caches were preserved.

```sh
taskset -c 16-19 make -C kprog/fidelity -f bank32.mk run-qemu BUILD=build-arm64-bitfield FAMILY=bitfield CASES=1024 OUT=../results/kprog_fidelity_20261107/differential/arm64-current-bank32/bitfield
taskset -c 16-19 make -C kprog/fidelity -f bank32.mk reference BUILD=build-arm64-bitfield FAMILY=bitfield CASES=1024 OUT=../results/kprog_fidelity_20261107/differential/arm64-current-bank32/bitfield REFERENCE=build-x86-control/reference/.lake/build/bin/reference
```

Coordinator hardware command from repository root (the script rejects an
emulated/x86 host; use a fresh output directory for each actual run):

```sh
ARM64_HANDOFF=../results/kprog_fidelity_20261107/differential/arm64-current-bank32/bitfield/cpu-differential-arm64.gz OUT=../results/kprog_fidelity_20261107/differential/arm64-current-bank32/bitfield-hardware sh kprog/fidelity/run-arm64.sh
```
