# Canonical x86 control-path replay

The saved 799-form hardware trace now has **525 checked forms / 537600 cases**,
with **zero CPU/reference differences** and **10240 simulator/reference
differences** on the same ten stack-address rows. This increment adds all
37 generated Jcc/JMP sequences (37888 cases) and V's 36 unary forms
(36864 cases). Every added case agrees among CPU, simulator and canonical
reference. The earlier 452-form result remains in `../x86-full-conditions/`.
274 encodings remain unhandled in this frozen reference snapshot, including
CALL/RET; `reference-forms.tsv` reports every form and diagnostic. None is
counted as passing.

`Reference.X86Path` executes an explicit finite witness of actual byte offsets
and instruction extents. It checks the current real PC, bounds each extent to
1–15 bytes inside the artifact, invokes the canonical decoder on those bytes,
and verifies that the decoder consumed exactly that extent. It then takes the
canonical successor and validates the next witness position against it. It
retains full state, ordered memory/fault events and defined flags, and rejects
continuation after a fault. It has no fuel, forced successor or timeout success.
A finite witness by itself is not a whole-program termination certificate;
the differential adapter also requires its final PC to equal the observed end.

The fidelity adapter reads instruction extents from the actual binary's
`objdump` output. For these generated 0/1 branch observers, the actual CPU's
final RAX selects the known taken/not-taken witness shape. The adapter never
interprets flags or condition codes. Canonical decode and execution validate
every byte extent and every selected successor. A wrong observer path fails
rather than being corrected. All flag/memory/GPR/vector comparisons remain.

**Validation:** 2053 focused full-state cases and 40 precise rejections pass,
including all sixteen conditions over all 64 flag combinations, forward and
backward paths, variable extents, wrapped PCs, interior entries, memory effects,
false-CMOV memory faults and fault continuation. `evaluate_sound` proves that
an accepted witness is an execution of those canonical decoded instructions;
its displayed dependencies are only `propext` and `Quot.sound`. The complete
root formal `make check` passes all Lean/C/encoder/wire checks. The later alias
to V's public `Instruction.fallthrough` getter is definitionally the same total
projection and passes a fresh reference rebuild and all 2053/40 focused cases.
The getter keeps instruction-extent maintenance in the canonical module.

```sh
taskset -c 20-23 make -C /workspaces/.agent-state/kprog-lanes/F/exclusive-export/kprog/formal -f path.mk build wire axioms
taskset -c 20-23 prlimit --as=12884901888 -- make -C kprog/formal check
taskset -c 20-23 make -C kprog/results/kprog_fidelity_20261106/differential/x86-control-reference wire
taskset -c 16-23 prlimit --as=12884901888 -- make -C kprog/results/kprog_fidelity_20261106/differential/x86-control-reference snapshot reference
```

The final reference command returns1 for the recorded stack findings and
unhandled encodings, retaining all inputs and outputs. The first invocation
failed before comparison because a relative executable name was searched on
PATH; its log is retained. The corrected Make recipe uses an absolute path.
The replay reads `../x86-full-conditions/cpu-states.bin`; it neither reruns the
CPU nor changes its input states. The static hardware observer and actual
production sources are archived in that sibling directory.

`canonical-source.tar.gz` and `reference.gz` preserve the exact replay snapshot
(private source base23f3c6931 plus the recorded canonical exclusive/X86 unary/
path overlays). It predates the later Arm memory prototype and uses the total
extent projection before its alias. `published-path-source.tar.gz` preserves
the published alias, CLI, checker and adapter with V's public projection.
`source-provenance.txt` identifies the publication source and unrelated dirty
source paths; those are not silently claimed to be committed. Complete full,
focused, axiom and replay logs are preserved. All mismatch JSONL records include
initial state, actual stack base, input memory and CPU/C/reference outputs.
