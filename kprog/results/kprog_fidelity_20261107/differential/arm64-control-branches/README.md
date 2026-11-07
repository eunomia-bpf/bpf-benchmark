# Current ARM control and stack observer replay

The existing control/stack harness retains its97 forms and adds the four
AL/NV forward/backward branch forms already supported by the production
encoder. All branch, finite BR/BLR, direct/nested call/RET, SP/LR alias and
stack byte observers use the same production macros and canonical step.
No new ISA model or production code is introduced. Source-label coordinates
and the fixed native observer origin0x1000000 remain explicit; this does not
prove arbitrary kernel code-base transport or the real invocation ABI.

```sh
taskset -c 20-23 make -C kprog/fidelity arm64-control-build
taskset -c 20-23 make -f kprog/results/kprog_fidelity_20261107/differential/arm64-control-branches/Makefile cpu reference
```

The detached incremental build and QEMU/canonical replay are pending; no
counts are claimed until completed. Actual ARM hardware remains separate.
The active x861080 compile on16-19 is preserved, not restarted.

The full replay completed: **101 forms x1,024 =103,424 states, zero QEMU/C,
QEMU/reference or C/reference differences**. Every form completes the same
canonical step path, with3-10 actual native steps per observer.
`forms.tsv` and `reference-forms.tsv` retain all counts; `summary.json` pins
both executables. Complete empty mismatch streams and original logs are
compressed without alteration. All compiler-input archive members were
independently rehashed against `compiled-inputs.json`.

The refreshed static control handoff SHA256 is
`db737361a92f0571ba64736ad499c27d55fad50e8b2a921d521b9a9f05b334e4`.
The existing default ARM64_CONTROL_HANDOFF now selects its compressed copy
here. On real ARM hardware, from the repository root, use the existing
control script with a fresh output directory:

```sh
OUT=../results/kprog_fidelity_20261107/differential/arm64-control-hardware sh kprog/fidelity/run-arm64-control.sh
```

Actual hardware execution remains pending. This control/stack package
complements the separate807-form numeric package selected by run-arm64.sh;
these are distinct observer families, not alternative ISA models. The fixed
source/native observer origin and outer boundary remain explicit, so no
kernel relocation/Entry/ABI/RET transport or universal safety is inferred.
