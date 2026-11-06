# Canonical bitfield refinement and CPU comparison

All70 focused forms ×1024 states pass: **71680 QEMU/native/simulator/reference
cases, zero differences and zero missing encodings**. Every comparison checks
all31 GPRs, SP, NZCV, all32 independent128-bit vector registers,64 stack-observer
bytes and256 external-memory bytes. Forms cover UBFX/SBFX/UBFIZ/BFXIL/BFI in
W/X width, full-field, low-bit, high-bit, partial-field, aliased destination/source
and discarded-ZR destinations. `forms.tsv` and `reference-forms.tsv` retain
every row; the compressed counterexample files are empty for this focused run.

The same original567-form CPU trace now checks553 forms /566272 cases:
CPU/reference differences0; model differences4096, confined to the same four
SP/WSP transfers. The ten original bitfield forms now decode. All14 remaining
LDR/STR encodings stay in `original-matrix/reference-unavailable.jsonl.gz` and
the active reference queue. No original state was regenerated or excluded.
The original-matrix command exits1 for those missing encodings and SP findings.

With lane V's explicit ownership handoff, F extended the **existing** canonical
`Reference/AArch64.lean`: UBFM/SBFM/BFM fields, typed nonempty field bounds,
W zero-extension, ZR discard, alias preservation and wrapping PC. Existing
shift/extension decoder priorities and all prior fields/statements remain.
The reference also handles signed wrapping SBFIZ from the same primary encoding.
`Refinement/Arm64Bitfield.lean` composes the existing generated five-kind C
value contract with GPR read/write and full-state preservation. It introduces
no simulator runtime check or second ISA implementation.

The private immutable export passes the full `make check`: all Lean/C/static
encoder/wire checks and the actual BPF-width check. Twenty added fixed native
byte/state examples and six reserved N/opcode/width rejections pass alongside
every original Arm wire case. Two initial export attempts lacked vendored
kernel headers; they are retained separately, and the complete export passes
without relaxing any check. The full-check base is189ec6979 plus exactly the
three handed-off formal files; shared V/A/C/T work was preserved.

`axioms.log.gz` records the theorem trust dependencies. The value/full-state
refinements use the existing proof library's `propext`, `Classical.choice`,
`Lean.ofReduceBool` and `Quot.sound`; this is not an axiom-free claim.
No new axiom or admitted theorem was added.

Commands on host CPUs16–23:

```sh
taskset -c 16-23 prlimit --as=12884901888 -- make -C kprog/fidelity -f bank32.mk run-qemu BUILD=build-arm64-bitfield FAMILY=bitfield OUT=../results/kprog_fidelity_20261106/differential/arm64-bitfield
taskset -c 16-23 make -C /workspaces/.agent-state/kprog-lanes/F/bitfield-export/kprog/formal -f prototype.mk bitfield wire axioms
taskset -c 16-23 prlimit --as=12884901888 -- make -C /workspaces/.agent-state/kprog-lanes/F/bitfield-export/kprog/formal check
taskset -c 16-19 make -C kprog/fidelity -f bank32.mk reference BUILD=build-arm64-bitfield OUT=../results/kprog_fidelity_20261106/differential/arm64-bitfield REFERENCE=/workspaces/repository/kprog/fidelity/build-arm64-bitfield/reference
taskset -c 16-19 make -C kprog/results/kprog_fidelity_20261106/differential/arm64-bitfield original-replay
```

The executed candidate reference was frozen before the full check rebuilt its
private cache. `harness-artifacts.tar.gz` restores the exact static CPU binary,
candidate reference executable, generated C/assembly, production include/import
closure and driver/build/replay sources under `kprog/fidelity/build-arm64-bitfield/`.
`formal-source-artifacts.tar.gz` restores the private source export, required
vendor headers, proof/check recipes and source revision. It excludes rebuildable
`.lake` caches and host binaries. Compressed logs retain every final command.
The accidental first replay against the old root reference is preserved as
`initial-root-reference.tar.gz` and `initial-reference.log.gz`; the corrected
candidate replay checks every focused form successfully.

The adapter omits memory-cell serialization for known pure-register operations,
while still comparing all actual CPU/C memory bytes and requiring the reference
to report no memory effects or faults. Memory instructions retain complete
memory input. This avoids repeatedly serializing untouched cells and changes
no accepted/rejected encoding or architectural comparison.

The static hardware handoff is `../cpu-differential-arm64-bitfield.gz`:

```sh
ARM64_HANDOFF=../results/kprog_fidelity_20261106/differential/cpu-differential-arm64-bitfield.gz OUT=../results/kprog_fidelity_20261106/differential/arm64-bitfield-hardware taskset -c <hardware-core-set> kprog/fidelity/run-arm64.sh
```

This result is functional QEMU evidence, not Arm hardware timing. It does not
close the numeric SP/LR safety findings or application-program binding work.
