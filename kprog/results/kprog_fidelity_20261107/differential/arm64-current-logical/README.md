# Current ARM matrix including logical immediates

This run extends the existing instruction-form list with AND/ORR/EOR/ANDS/TST
immediates at W/X widths, distinct and aliased GPRs, ZR sources, and SP/WSP
destinations where the architecture permits them. Six valid masks cover low
and high single bits, byte/half-width runs and repeated elements. The current
production encoder, simulator, native observer and canonical reference are
reused. It is not a second ISA model. Old matrix forms remain present.

The existing static AArch64 harness build runs incrementally on CPUs16-19;
QEMU user-mode smoke and canonical replay follow in the detached job. Those
are emulation evidence; the coordinator must run the static binary on real
ARM hardware for CPU evidence. Per-form numbers, mismatch inputs, exact
commands and compiled-input pins will be recorded after completion.

```sh
taskset -c 16-19 make -C kprog/fidelity build ARCH=arm64
taskset -c 16-19 make -C kprog/fidelity run-emulated ARCH=arm64 CASES=1024 OUT=../results/kprog_fidelity_20261107/differential/arm64-current-logical
```

The static build and QEMU smoke completed: **771 forms x1,024 =789,504
states, zero architectural-state or memory mismatches**. The extension adds
204 logical-immediate forms to the existing567 forms. `qemu-forms.tsv`
retains every form/count; `qemu-summary.json` pins the static binary and
explicitly labels emulation. `compiled-inputs.tar.gz` and its source manifest
preserve the header/Python snapshot, generated C/assembly and observer sources.
`static-elf.txt` confirms AArch64 static ELF without an interpreter.

The current static handoff is `cpu-differential-arm64.gz`. On real ARM hardware,
from the repository root, run the existing script:

```sh
sh kprog/fidelity/run-arm64.sh
```

It now selects this current771-form binary and writes hardware per-form counts
and complete mismatch inputs under `differential/arm64-current-hardware`.
The script rejects non-AArch64 hosts. The control-observer handoff remains a
separate existing artifact. QEMU results do not substitute hardware evidence.
The independent canonical replay uses the same already-pinned executable as
the completed x86 matrix, through this directory's `make reference` target;
its outcome is pending and is not counted here.
