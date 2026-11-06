# Reject native writeback/base register overlap

All11 targeted bad encodings were accepted by the production generation-bound
Arm QEMU loader before the repair, with program IDs8,16,…,88 and generation1.
They cover LDR X/W, LDRB, LDRH, preindex LDR, first/second LDP destinations,
STR X/W, and first/second STP sources overlapping a writeback base register.
The native bodies allocate and initialize32 stack bytes; every GPR they use is
defined. None of these native candidates was executed.

Arm DDI0602's WBOVERLAPLD/WBOVERLAPST constraints permit an undefined
instruction or a NOP, among other constrained outcomes, for these GPR aliases.
The source is the actual LDP/LDR and STP/STR shared decode, including the
non-SP-base condition; local primary text is in
`/workspaces/.agent-state/kprog-lanes/V/arm-a64.txt` (LDP near17190, STP near29882).
Overwriting a loaded result does not remove the possible instruction fault.

The production ABI checker now rejects writeback when a non-SP base aliases
a data GPR. It compares architectural register identity, so W1 also aliases
base X1. SP and ZR remain distinct despite their shared encoding number;
vector and general registers likewise retain separate identities. This is
source validation of a constrained-unpredictable encoding, with no runtime
simulator guard, chosen arbitrary register value, or changed valid semantics.

All11 now reject during specialization, at the same instruction offset0x18.
For example:

```text
constrained-unpredictable native writeback/base register overlap at 0x18: ldr w1, [x1], #4
```

Every native input and exact rejection is in `after/outcomes.json`; the
corresponding bound acceptance is in `before/outcomes.json`. Assembler warnings
and frozen before/after generator/include closures are preserved in the archive.
All five valid controls remain accepted with generation1: distinct-register
LDR/STR/LDP/STP writeback, and `str xzr,[sp,#-16]!` with balanced SP restoration.
Their IDs after repair are8,16,24,32,40. JSON marks these as positive controls;
their expected acceptances are not safety findings.

The permanent Arm suite now has21 cases:9 verifier,9 specialization and1
loader rejection, plus the same2 earlier numeric SP/LR address-state findings.
All11 original negatives and all newly added instruction-fault negatives
reject. The full suite intentionally exits1 for those two separate findings,
with zero infrastructure errors. All40 existing ABI regressions pass, and the
negative proof plus all29 workload-derived positive proofs rebuild.

```sh
taskset -c 16-23 make -C kprog/results/kprog_fidelity_20261106/negative/arm64-writeback-overlap build run
taskset -c 16-23 make -C kprog/results/kprog_fidelity_20261106/negative/arm64-writeback-overlap PHASE=after build run
taskset -c 16-23 make -C kprog/results/kprog_fidelity_20261106/negative/arm64-writeback-overlap full-build full-run
taskset -c 16-23 make -C kprog/results/kprog_fidelity_20261106/negative/arm64-sp-alignment check BUILD=/workspaces/repository/kprog/fidelity/build-arm64/writeback-overlap-bound/after
taskset -c 16-23 make -C kprog/arm64 micro-proofs-build PROOF_BUILD_DIR=build/fidelity-writeback/micro-proofs NEGATIVE_NATIVE_BUILD_DIR=build/fidelity-writeback/negative-native MICRO_SIM_PROOF_ARGS='--jobs 1'
```

The first command describes the preserved before-repair run; reproduce it with
the saved before source closure, not by removing the production fix. Every
guest is cortex-a57,2vCPUs/2GiB, on host CPUs16–23. Targeted runs are load-only.
`artifacts.tar.gz` restores `writeback-overlap-bound/` under
`kprog/fidelity/build-arm64/`, including native/proof inputs, exact source
closures,21-case permanent suite and40 ABI checks. Unchanged common runtime
assets are deduplicated in `../arm64-sp-alignment/artifacts.tar.gz` and copied
by the recipe. `raw-logs.tar.gz` preserves complete guest/per-case logs;
compressed Make logs preserve the commands and outcomes. No shared runtime
image, module or kernel was rebuilt.
