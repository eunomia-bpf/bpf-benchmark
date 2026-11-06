# CPU differential evidence, 2026-11-06

The x86 host run finds **46,866 mismatching cases among 714,752 cases**:
698 forms, 1,024 states per form, 74 forms with at least one mismatch.
This is evidence of fidelity defects, not a successful fidelity claim.
The simulator and production encoders were not changed for this experiment.
Source baseline: master `075c64b6e`, plus the accompanying `kprog/fidelity/`
harness; unrelated working-tree changes were left in place.

## Commands and artifacts

From the repository root, on the Intel Core Ultra 9 285K host:

```sh
taskset -c 16-23 make -C kprog/fidelity run CASES=1024 OUT=../results/kprog_fidelity_20261106/differential/x86
taskset -c 16-23 make -C kprog/fidelity ARCH=arm64 build
taskset -c 16-23 make -C kprog/fidelity ARCH=arm64 run-emulated CASES=16 OUT=../results/kprog_fidelity_20261106/differential/arm64-qemu-smoke
```

The x86 run reports `forms=698 cases=714752 mismatches=46866` and exits 1
(the enclosing make exits 2). This nonzero exit records the findings.
`x86/forms.tsv` gives case and mismatch counts for every form;
`family-counts.tsv` groups those counts by encoded opcode.
`x86/mismatches.jsonl.gz` losslessly retains **every** mismatch's initial
registers, modeled flags, XMM0, stack bytes and memory, and both output states.
`x86-coverage.json` maps forms to disassembly/opcodes.
`x86/host.txt` records the host kernel, ISA, fixed seed and sample count.
The compressed build/run logs retain compiler diagnostics as well as outcomes.

Each form receives 128 boundary cases followed by 896 fixed-seed random cases.
All 16 combinations of CF/ZF/SF/OF cycle throughout the run. Registers outside
the instruction's operands are randomized and checked for preservation.
The backing memory contains 256 randomized bytes; all bytes are compared after
native execution and simulator execution using the same virtual addresses.
The x86 stack has 64 randomized bytes, captured before the wrapper's own
snapshot pushes can overwrite them. Static offset assertions tie the C state
to the assembly wrapper. DIV uses a nonzero divisor and zero high dividend to
stay inside its non-faulting domain. REP MOVS uses count 8 and DF=0.

The CPU oracle executes assembled machine instructions. For ordinary forms,
the production disassembler/encoder selects the real simulator macro; the test
does not reimplement its arithmetic. Control-flow composites exercise the
production branch/call/return macros and expose taken/not-taken results or the
actual stack return address. CF/ZF/SF/OF are compared where CPU-defined:
DIV flags are excluded, IMUL compares CF/OF, BT compares CF, and shift OF/CF
masks follow the instruction/count's defined domain. PF/AF are outside the
simulator's modeled state. Undefined hardware flags are not counted as defects.

## Findings

| Encoded family | Mismatching cases |
| --- | ---: |
| CMOV memory | 24,048 |
| CMOV register | 5,616 |
| IMUL memory/immediate | 3,072 |
| SHRD immediate | 2,506 |
| MULX | 2,048 |
| ANDN memory | 2,010 |
| BT memory/immediate | 1,533 |
| TEST memory/register | 1,147 |
| POP | 1,024 |
| PUSH | 1,024 |
| SHLD immediate | 936 |
| BZHI memory | 850 |
| BZHI register | 805 |
| BT register | 247 |

Representative observations (the complete inputs are in the JSONL):

- False 32-bit CMOV and zero-count 32-bit SHLD/SHRD can leave simulator upper
  register bits that the CPU clears.
- Intel-syntax MULX's first destination receives the high product on the CPU;
  the simulator's tested path reverses the two destinations.
- `push bx` and `pop ax` have two-byte CPU stack effects; the simulator's
  transfer path steps by eight bytes (and PUSH uses a 64-bit transfer).
- A 16-bit register BT with index 127 tests bit 15 on the CPU; the tested
  simulator path can disagree on CF.
- Other memory/flag mismatches remain findings without a blanket root-cause
  claim. Some are in the encoding/packed-operand path rather than the shared
  arithmetic contract; changing only an arithmetic theorem would not fix them.

All 24 forward/backward conditional-branch forms, the direct jump, local
call/return, four REP MOVS forms, and 64-bit PUSH/POP agree in this matrix.
Agreement is limited to these sampled states.

## AArch64 handoff

The static ELF64 AArch64 executable built successfully with GCC 13; its ELF
program headers contain no interpreter. `cpu-differential-arm64.gz` is the
stripped executable (debug information removed). The build tree also retains
the executable with debug information. `arm64-coverage.json` lists 497 forms.

On real Arm hardware, from the same checkout:

```sh
CASES=1024 OUT=../results/kprog_fidelity_20261106/differential/arm64-hardware kprog/fidelity/run-arm64.sh
```

The script checks the host ISA and invokes `make run-handoff`, which unpacks
the shipped static executable and runs it. The coordinator must record the
hardware identity and commit its output. At this initial handoff, hardware execution was still pending; the
coordinator's hardware follow-up is recorded below.

A QEMU-user smoke completed all 497 forms × 16 states = 7,952 cases, with 96
mismatches in six SIMD forms: FMOV to D0/S0, CNT at 8/16 lanes, and UADDLV at
8/16 lanes. Its exact outputs are under `arm64-qemu-smoke/`. This checks that
the executable runs and produces counterexamples; QEMU is not real-CPU
fidelity evidence. The Arm wrapper captures X0–X30, NZCV and V0. Its SP is
fixed and this matrix does not exercise Arm stack/control-flow instructions.

## Coverage boundary and retained preflight

This matrix covers the ordinary instruction forms emitted here, with legal
operand widths, selected immediates, high-byte operands where the encoder
supports them, safe memory operands, and x86 control/stack composites. It does
not exhaust every register alias, address, immediate or provenance tag, and
should not be described as complete ISA equivalence. RSP is an abstract stack
offset; the test does not compare raw host stack addresses as guest values.
Kernel helper/map bindings, ELF relocation adapters, synthesized libc calls,
and privileged/faulting execution need their own evidence. The production
encoder rejects ordinary ROR and overflow-condition SET/CMOV spellings; their
presence in a shared contract is not executable coverage.

`preflight/` retains the earlier 664-form, 128-state matrix: 84,992 cases,
4,492 mismatches in 72 forms. It predates the stack snapshots and control-flow
composites; use the final `x86/` run for current counts. Raw preflight results
are preserved, not substituted for the final run.


## Recovery and fidelity fixes

The original matrices above are preserved. The recovery runs use the production
encoders and simulator headers, with no change to the workload or CPU oracle.
The stack backing is now volatile and uninitialized, with direct accesses
instead of synthetic window traps. Six host route tests preserve the in-range
value/tag grids and test actual read/write SIGSEGV at protected-memory
boundaries. Their case counts are 167480, 2754300, 3843515, 9084768, 60144
and 789 (arm, arena, write lanes, write tags, read tags, helper pointers).
IMUL/BT memory operands now extract the packed signed displacement once;
TEST/ANDN memory displacement packing, negative immediate packing and MULX
operand order are also corrected. The retained memory-route logs cover the
actual C consumers, not only the generated arithmetic tables.

A full AArch64 QEMU-user follow-up first exposed 1407 further mismatches in
32-bit UDIV (621) and EXTR (786). The previous 16-state smoke missed them.
The original six SIMD failures are fixed by preserving the 8b/16b arrangement,
updating both vector halves and clearing scalar vector writeback upper bits.
UDIV/EXTR now narrow W-register operands before using the existing canonical
arithmetic primitives. The final `arm64-width-fix/forms.tsv` records **497
forms x1024 states =508928 cases, zero mismatches**. This remains emulation,
not AArch64 hardware fidelity evidence. The static hardware handoff now
selects `cpu-differential-arm64-width-fix.gz`; the original baseline binary
remains at its original path.

The real x86 recovery matrix records 7145 mismatches after the BT correction.
A later rebuild with V's BZHI correction records **5490 mismatches in seven
forms** out of 714752 cases: PUSH16, POP16, SHRD16/32/64 count1 and SHLD/SHRD32
count0. Those canonical corrections remain active work assigned to V.
`x86-recovery/` and `x86-reference-bt-cmov/` retain both matrices and every
counterexample. Their zero-mismatch families are sampled agreement only.

The raw-byte adapter checks all 81 CMOV/BT forms against V's compiled Lean
reference: **82944 cases, zero reference/CPU or reference/simulator
mismatches**. It supplies the actual executed native bytes, PC and segment
bases, checks full registers/vector/memory, and uses reference-provided
`defined_flags`. The remaining 617 forms await the executable reference and
are listed in `reference-forms.tsv`; the command exits nonzero rather than
claiming a complete reference check. The full CPU matrix in that directory
also still reports the seven x86 defects above.

```sh
taskset -c 16-23 make -C kprog/fidelity check-stack-memory check-memory-operands check-arm64-simd
taskset -c 16-23 make -C kprog/fidelity ARCH=arm64 run-emulated CASES=1024 OUT=../results/kprog_fidelity_20261106/differential/arm64-width-fix
taskset -c 16-23 make -C kprog/fidelity reference-check CASES=1024 OUT=../results/kprog_fidelity_20261106/differential/x86-reference-bt-cmov
```

`recovery-sources.tar.gz` preserves the source/header snapshot; raw matrices,
compressed counterexamples and `restart-*.log.gz` preserve all outcomes.
The checkout is shared and dirty; later lane changes are not retroactively
part of these measurements. No paper files or git state were changed by F
in this recovery turn.


The next rebuild includes V's double-shift fixes: `x86-reference-bzhi/` records
714752 CPU cases with only PUSH16/POP16 remaining (2048 mismatches).
Enabling the BZHI register/memory decoder extends the reference comparison to
85 forms and 87040 cases, with zero CPU/reference or simulator/reference
mismatches. 613 forms still await the executable reference; the command exits
nonzero for that incompleteness and the two CPU findings. Exact command:
`taskset -c 16-23 make -C kprog/fidelity reference-check CASES=1024 OUT=../results/kprog_fidelity_20261106/differential/x86-reference-bzhi`.


After V's PUSH/POP correction, the independent F rebuild at
`x86-cpu-fixed/` reports **698 forms, 714752 cases, zero CPU/simulator
mismatches**. The same run checks 87040 CMOV/BT/BZHI cases against the
executable reference with zero mismatches. The remaining 613 forms still need
their canonical raw-byte reference interface; this does not change the green
CPU matrix. The overall reference-check command exits 1 for that explicit
coverage gap. Native raw bytes, per-form records, empty mismatch files and the
complete Make log are retained in that directory.


The AArch64 register-cell representation published by A was independently
rebuilt and retested in `arm64-register-cells/`: all 497 forms/508928 QEMU-user
cases agree, with no mismatches. `make.log.gz` retains compilation and outcome.
The hardware replay default now selects
`cpu-differential-arm64-register-cells.gz`; both earlier handoff binaries are
retained. No real Arm hardware result is inferred from this emulation run.


## DGX Spark hardware follow-up

The coordinator ran the unchanged width-fix static handoff on `spark-d5fe`,
pinned separately to Cortex-X925 CPU 19 and Cortex-A725 CPU 10. **Each core
reports 497 forms, 508928 cases, zero mismatches.** This is real AArch64 CPU
evidence for that matrix. `arm64-hardware/RUN.txt` records the exact commands;
`out-cpu19/` and `out-cpu10/` retain per-form outcomes, raw mismatch files,
`lscpu.txt` and `uname.txt`. `run-cpu*.log` retain both complete status lines.
The supplied provenance files are preserved unchanged.

That binary predates A's register-cell/BR/BLR and real-helper updates. The
new register-cell handoff is `cpu-differential-arm64-register-cells.gz`, with
its independent 497-form QEMU comparison at zero mismatches; the coordinator
replayed it on both cores as recorded below. The current 497-form matrix
tests ordinary arithmetic/data/vector operations, not kernel-helper bodies or
Arm branch/call/stack composites. Those require their own CPU/ABI evidence;
the hardware result is not broadened to untested operations.

The coordinator also ran the newer register-cell handoff on both Spark core
classes at approximately 10:29 UTC. **CPU19/X925 and CPU10/A725 each report
497 forms, 508928 cases and zero mismatches.** The second independent replay's
unchanged commands, host metadata, logs and per-form results are retained in
`arm64-hardware-register-cells/` and its `RUN.txt`. This confirms the same
ordinary-form matrix after the register representation change; it does not
extend coverage to BR/BLR, stack composites or helper bodies.

## Arm control-flow and stack replay

The additional74-form composite matrix initially found12 real W-CBZ/CBNZ
mismatches, plus4096 observations affected by a test stack-offset bug. The
production decoder selected the64-bit register test for W operands. It now
narrows only the tested value before the unchanged generated branch predicate;
it never writes the architectural source register. Existing X-form macro
callers retain their behavior. The observer now uses the declared stack bias,
rather than the end of its larger backing array. Both original outputs and
all mismatch inputs remain in `arm64-control-qemu/`; the observer defects are
not attributed to the simulator.

After both corrections, `arm64-control-fixed/` reports **74 forms,75776 cases,
zero mismatches under QEMU-user**. It covers all14 conditions in both edge
directions, W/X CBZ/CBNZ, TBZ/TBNZ boundary bits, CMP/GT composition, finite
BR/BLR code choices, local BL, RET X30/alternate register, nested saved-LR
calls and raw stack stores/loads. Every case compares all31 GPRs, restored SP,
NZCV, V0, all64 observed stack bytes and256 external memory bytes.
The outer ABI return is the observation boundary; inner calls/returns run
the production whole-program encoder and return dispatcher. A fixed ELF code
section makes the CPU's real PCs equal the simulator's numeric code addresses.
X20=0 is the explicit observer return sentinel. No helper body is in this matrix.

```sh
taskset -c 16-23 make -C kprog/fidelity arm64-control-build ARM64_CONTROL_BUILD=build-arm64-control-fixed
taskset -c 16-23 make -C kprog/fidelity arm64-control-qemu ARM64_CONTROL_BUILD=build-arm64-control-fixed ARM64_CONTROL_OUT=../results/kprog_fidelity_20261106/differential/arm64-control-fixed CASES=1024
# On Spark, pinned once to each core class:
taskset -c 19 env OUT=../results/kprog_fidelity_20261106/differential/arm64-control-hardware-cpu19 kprog/fidelity/run-arm64-control.sh
taskset -c 10 env OUT=../results/kprog_fidelity_20261106/differential/arm64-control-hardware-cpu10 kprog/fidelity/run-arm64-control.sh
```

`cpu-differential-arm64-control.gz` is the new static stripped hardware replay;
`arm64-control-artifacts.tar.gz` preserves both exact encoder/header snapshots,
assembly, C and binaries. This also exercises A's current uncommitted finite
BR/BLR/CODE/RET changes; it is not a claim that those source changes have
already published independently. The supplied74-form replay is self-contained.
Real CPU replay remains a coordinator-owned active requirement until received.

## Absolute-stack reference and ANDN extension

`x86-reference-pop/` repeats the full698-form real-CPU matrix:
714752 cases, zero simulator mismatches. The extended lane-V reference check
covers **93 forms/95232 cases**, also with zero CPU or simulator disagreement.
It adds the four register PUSH/POP forms and four ANDN register/memory forms
to the previous85. Remaining605 forms are explicitly `awaiting_reference_instruction`;
the command exits1 for that gap. This is not whole-ISA reference closure.

CPU trace version2 records the wrapper's real stack base for every state.
The reference receives absolute architectural RSP and all64 actual stack
bytes at their real addresses. Only the comparison boundary rebases returned
RSP to the simulator's offset representation; the canonical ISA arithmetic,
stack accesses and read/write effects are not changed. Stack writes from
PUSH are compared as bytes, not assumed unchanged. The adapter also maps all256
external memory bytes, compares all16 GPRs, V0/XMM0, defined flags and final PC.
No effect-order refinement theorem is inferred from sampled final states.

```sh
taskset -c 16-23 make -C kprog/fidelity reference-check BUILD=build-x86-reference-stack CASES=1024 OUT=../results/kprog_fidelity_20261106/differential/x86-reference-pop
taskset -c 16-23 make -C kprog/fidelity reference-replay BUILD=build-x86-reference-stack CASES=1024 OUT=../results/kprog_fidelity_20261106/differential/x86-reference-pop
```

The second command reuses the unchanged recorded CPU states when the canonical
reference gains an operation; it does not rerun hardware or generate another
ISA. Both complete logs, per-form tables, raw code addresses/bytes and empty
mismatch files are retained. The first89-form result is separately preserved
as `reference-forms.tsv.pop-first.gz`. `x86-reference-stack-artifacts.tar.gz`
contains the test executable and generated native/C sources. The1.3GiB
`cpu-states.bin` remains in the workspace for subsequent reference replay;
it is not committed to git. All mismatches would still be committed losslessly.

## First canonical AArch64 replay

With V's canonical AArch64 register/multiply/divide reference at9b99b7166,
`arm64-reference/` records **12 forms/12288 cases** with no CPU-or-simulator
reference disagreement. The full independently executed QEMU matrix remains
497forms/508928cases/zero mismatches. The485 remaining forms stay explicitly
`awaiting_reference_instruction`, and the overall command exits1 for that gap.

The adapter supplies actual native instruction bytes and all32 X0..X30/SP
words, NZCV, PC, V0 and mapped memory to the existing `reference` executable
with `isa=aarch64`. It implements no arithmetic/decoder semantics. The exported
forms are W/X multiply, MADD/MSUB, UDIV and the long/high multiply variants.
Canonical handling of divide-by-zero and narrowing is exercised by the same
boundary and fixed-seed random states as the CPU comparison. This is emulated
Arm reference evidence, distinct from the earlier Spark CPU matrices.

```sh
taskset -c 16-23 make -C kprog/fidelity reference-check ARCH=arm64 BUILD=build-arm64-reference CASES=1024 OUT=../results/kprog_fidelity_20261106/differential/arm64-reference
# Refreshed ordinary-form binary after the SMADDL unsigned-wrap correction:
taskset -c 19 make -C kprog/fidelity run-handoff ARM64_HANDOFF=../results/kprog_fidelity_20261106/differential/cpu-differential-arm64-reference.gz OUT=../results/kprog_fidelity_20261106/differential/arm64-reference-hardware-cpu19
```

`cpu-differential-arm64-reference.gz` is the refreshed static ordinary-form
hardware replay; the74-control binary remains separate. Per-form tables, exact
native bytes/PCs, empty mismatch files and full build/reference log are retained.
The generated source/executable archive permits replay; the raw complete CPU
state trace stays in the workspace. Neither missing reference coverage nor
real hardware execution of this refreshed binary is inferred from QEMU.

The generalized ISA adapter was also regression-checked on x86 using16states
per form: full CPU698forms/11168cases/zero, reference93forms/1488cases/zero.
`x86-reference-isa-adapter/` retains its per-form records and complete log;
its nonzero status still reports the605 unavailable x86 reference forms.
This small integration regression does not replace the full1024-state result.

## Safe SP-flags counterexample after the74-form pass

The additional75th control composite compares SP with0 and has two harmless
arithmetic arms. `arm64-control-stack-base/` reports75forms/76800cases, with
**all1024 SP-compare cases mismatching** and all original74forms still agreeing.
The CPU's SP is nonzero while the model computes flags from offset0. Every
mismatch's full state and memory input/output is retained losslessly. This is
independent benign CPU/QEMU evidence for the actual accepted unsafe branch in
`../negative/arm64-stack-base/`; no unsafe native is executed to demonstrate it.
The earlier74-form green result did not exercise address-sensitive SP flags.

```sh
taskset -c 16-23 make -C kprog/fidelity arm64-control-build ARM64_CONTROL_BUILD=build-arm64-control-stack-base
taskset -c 16-23 make -C kprog/fidelity arm64-control-qemu ARM64_CONTROL_BUILD=build-arm64-control-stack-base ARM64_CONTROL_OUT=../results/kprog_fidelity_20261106/differential/arm64-control-stack-base
```

The optional hardware counterexample replay is
`cpu-differential-arm64-control-stack-base.gz`, via `arm64-control-handoff`
with `ARM64_CONTROL_HANDOFF` set to that file. It is expected to return nonzero
for the1024 mismatches until the address relation is fixed. The original74-form
zero replay remains separate; neither is broadened to an all-pointer-state claim.

## Refreshed hardware replay, 11:25–11:38 UTC

The coordinator replayed both unchanged static binaries on Spark CPU19
(Cortex-X925) and CPU10 (Cortex-A725). The reference handoff reports
**497 forms/508928 cases/zero mismatches on each core**; the control handoff
reports **74 forms/75776 cases/zero mismatches on each core**.
`arm64-reference-hardware/` and `arm64-control-hardware/` retain the supplied
RUN.txt, complete logs, host identification and per-form counts unchanged.
Their compressed binary SHA256 values are respectively
`c8d203b1131648ef43b41b4f2c375e85e5eca517b30c1989df50662ad5e3a0c6`
and `2459ff8618ca7cd3cffec5fe45ded0a9ef1fda482e59609dd6a5ad5e0d8c4ea2`.
These hardware results close replay of those frozen matrices, including the
branch/call/stack composite handoff. They do not cover the later SP-flags
counterexample or establish complete reference coverage.


## Current production emitters and redundant stack prefixes

The refreshed x86 matrix in `x86-current-stack/` passes **721 forms / 738304
real-CPU cases / zero mismatches**. The 23 additions cover eight immediate
PUSH values, 16-bit immediate PUSH, memory PUSH/POP at both widths, RSP-relative
source/destination addressing, and eight raw redundant-prefix encodings.
Each form runs 1024 states. Both orders of `66` and REX.W are retained for
register PUSH/POP and their FF/6 and 8F/0 aliases. The production parser now
folds objdump's prefix-only records and obtains stack width from active
prefixes. Previously valid instructions were parsed as `data16`/`rex.W` or
split into two instructions. Architectural semantics are unchanged.

All 29 workload-derived x86 positive proof artifacts and the negative artifact
compile through `make -C kprog/x86 micro-proofs-build`; this is compilation
validation, not a claim that the negative artifact verifies. Lane V's sole
workspace full check passed all331 Lean jobs, canonical wire checks and C
oracles (`V/check-stack-memory-full-3.log`, published with `5bd74ac0b`).
F stopped its duplicate check when the coordinator introduced the single-full-
check memory rule; the interrupted log is retained and is not counted as a pass.

The Arm data matrix now uses the production `append_insn` emitter, including
its literal opcode dispatch, rather than a separate generic-op invocation.
`arm64-production-current/` passes **563 forms / 576512 QEMU cases / zero
mismatches**, including shifted MVN/NEG and AL/NV conditional forms. Its
independent-reference replay checks **300 forms / 307200 cases / zero
mismatches**. The remaining263 forms produce explicit decoder diagnostics in
`arm64-production-reference-current/reference-unavailable.jsonl.gz`; the
reference command exits1 for that incomplete coverage. No ISA interpreter was
added to the harness. The earlier `arm64-reference/reference-forms.tsv` refresh
likewise broadens the old handoff's reference replay; its CPU inputs remain
unchanged.

`arm64-control-current/` uses production control emission and real return tags,
with the observation boundary outside the simulated application return. It
requires no artificial entry register or return token. The original74 controls
still pass; the additional SP-flags composite retains all1024 mismatches among
75 forms / 76800 cases. Every mismatch includes initial registers, flags, stack
and memory and both resulting states in `mismatches.jsonl.gz`. This remains a
real accepted-negative finding, not an observer artifact.

```sh
taskset -c 16-23 make -C kprog/fidelity run BUILD=build-x86-current-stack OUT=../results/kprog_fidelity_20261106/differential/x86-current-stack
taskset -c 16-23 make -C kprog/fidelity reference-check BUILD=build-x86-current-stack OUT=../results/kprog_fidelity_20261106/differential/x86-current-stack-reference
taskset -c 16-23 make -C kprog/x86 micro-proofs-build
taskset -c 16-23 make -C kprog/fidelity run-emulated ARCH=arm64 BUILD=build-arm64-production-current OUT=../results/kprog_fidelity_20261106/differential/arm64-production-current
taskset -c 16-23 make -C kprog/fidelity reference-check ARCH=arm64 BUILD=build-arm64-production-current OUT=../results/kprog_fidelity_20261106/differential/arm64-production-reference-current
taskset -c 16-23 make -C kprog/fidelity arm64-control-build ARM64_CONTROL_BUILD=build-arm64-control-current
taskset -c 16-23 make -C kprog/fidelity arm64-control-qemu ARM64_CONTROL_BUILD=build-arm64-control-current ARM64_CONTROL_OUT=../results/kprog_fidelity_20261106/differential/arm64-control-current
```

The last command intentionally exits1 while SP semantics differ. Updated
static hardware handoffs are `cpu-differential-arm64-production-current.gz`
and `cpu-differential-arm64-control-current.gz`. On a real Arm host, use the
existing scripts with these environment overrides:

```sh
ARM64_HANDOFF=../results/kprog_fidelity_20261106/differential/cpu-differential-arm64-production-current.gz OUT=../results/kprog_fidelity_20261106/differential/arm64-production-current-hardware sh kprog/fidelity/run-arm64.sh
ARM64_CONTROL_HANDOFF=../results/kprog_fidelity_20261106/differential/cpu-differential-arm64-control-current.gz OUT=../results/kprog_fidelity_20261106/differential/arm64-control-current-hardware sh kprog/fidelity/run-arm64-control.sh
```

`current-production-harness-artifacts.tar.gz` retains all three generated
harnesses, exact production include/import snapshots, native assembly and
static binaries. Passing CPU-state traces remain in the local result
directories for reference replay; per-form counts and all mismatch inputs are
published. These snapshots include other lanes' concurrent source changes;
they are not asserted to be a clean committed-source export.

The current x86 independent-reference replay is complete: **116 forms /
118784 cases / zero mismatches**, including all23 newly added stack encodings.
The605 remaining forms have explicit decoder/block-interface diagnostics;
`reference-check` exits1. Full721-form CPU/simulator agreement is distinct from
this incomplete canonical-reference coverage. Both sets of per-form results
and the exact diagnostics are retained in `x86-current-stack-reference/`.


## Same-input reference replay after the shift/unary proofs

V's canonical shift/unary increment, included in `0ce49da1d`, raises the Arm
reference comparison to **377 forms / 386048 cases / zero mismatches**.
`arm64-reference-shift/` reuses the unchanged563-form production binary and
CPU trace above. All77 newly covered forms agree;186 forms still report exact
reference-decoder failures and the command exits1. This replay changes no
simulator or native instruction and adds no independent ISA implementation.

```sh
taskset -c 16-19 make -C kprog/fidelity reference-replay ARCH=arm64 BUILD=build-arm64-production-current OUT=../results/kprog_fidelity_20261106/differential/arm64-reference-shift CASES=1024
```

The output directory reuses `cpu-states.bin`, `forms.tsv`, `native-code.json`
and `host.txt` from `arm64-production-reference-current/`; only the canonical
reference outputs differ. Exact new per-form counts, decoder diagnostics and
empty mismatch record are published alongside the log. The563-form static
hardware handoff is unchanged.


## Actual final-SP observers and address-state counterexamples

Both CPU wrappers now capture the actual final stack pointer before restoring
their private observer frame. x86 uses XMM5 without changing flags or modeled
XMM0; Arm uses D1/D2, preserving NZCV and modeled V0. Stack bytes are captured
before observer spills. This replaces x86's preset PUSH/POP delta and Arm's
unchanged input SP field. The `add rsp,16` and Arm `sub sp,sp,#16` controls
both agree in1024 cases with actual nonzero final-SP displacements.
Restoration happens after the native instruction/composite boundary, before
the observer dereferences its own stack. No safety guard is inserted into an
application instruction stream.

| Matrix | Forms | Cases | Raw CPU/simulator disagreements |
| --- | ---: | ---: | ---: |
| x86 real CPU, actual-SP observer | 733 | 750592 | 11264 |
| Arm QEMU, actual-SP observer | 567 | 580608 | 4096 |
| Arm controls, current MOV-to-SP implementation | 77 | 78848 | 1024 |
| Same Arm controls, frozen pre-repair header | 77 | 78848 | 2048 |

All721 earlier x86 forms and563 earlier Arm forms still agree. The new x86
rows that disagree are `mov rax,rsp`, `mov eax,esp`, `lea rax,[rsp+16]`,
`cmp rsp,0`, `mov rsp,rax`, `mov esp,eax`, `lea rsp,[rsp+16]`, and16/64-bit
PUSH/POP of SP. Each has1024 disagreements. The new `add rsp,16` control agrees.
Arm's four new SP/WSP-to/from-GPR forms each disagree in1024 cases.
The balanced MOV-to-SP round trip changes from1024 disagreements with the
old header to zero with A's repair; the existing SP-comparison control remains
at1024. Its companion unbalanced-SP observation control also agrees.

These are address-state differences at the missing frame/projection boundary,
not eleven independent unsafe-program claims. Some pointer copies may admit
an explicit frame projection; flags, narrow values and stored bytes require
actual-address materialization before their observations. The harness records
the raw state and does not invent a pointer normalization to turn rows green.
The known load-only negative findings still require the shared numeric-base
and state-relation repair.

The independent canonical replay checks144 x86 forms/147456 cases: CPU versus
reference has zero disagreements; simulator versus reference has4096, all in
16/64-bit PUSH/POP of SP. The589 remaining forms have explicit decoder/block
interface diagnostics. Arm checks419 forms/429056 cases: CPU versus reference
has zero disagreements; simulator versus reference has4096, exactly the four
SP/WSP moves. Its148 remaining forms have explicit diagnostics. Both reference
commands exit1 and preserve every unavailable encoding and counterexample.

Mismatch records now include `native_stack_base`, the real observer-frame
anchor. The architectural SP is that anchor plus the record's SP displacement,
modulo2^64. Input stack bytes occupy anchor-64 through anchor-1. The reference
adapter supplies the real initial SP and private stack cells and normalizes
only the final SP for comparison. Other recorded register words remain raw.
The x86 POP fixtures begin at displacement-2/-8; ordinary Arm fixtures begin
at displacement0. `reference-mismatches.jsonl.gz` additionally retains canonical results,
CPU/simulator states and all input bytes; `native-code.json` supplies bytes/PCs.

The new matrix initially exposed `unsupported register: wsp` in the Arm
parser. Its register alias now maps both SP spellings to ARM64_SP; width
selection and the ABI checker already distinguish WSP32. All29 original Arm
positive artifacts plus the negative proof artifact compile with one worker.
The focused real-assembly `wsp-return-negative/` fixture confirms that decoding
WSP does not accept an ABI-breaking return: specialization rejects it with
`native ABI return has an unbalanced stack pointer at 0xc: ret`.
That unsafe whole program is never executed.

Commands as executed:

```sh
taskset -c 16-23 prlimit --as=12884901888 -- make -C kprog/fidelity run BUILD=build-x86-sp-observer-control OUT=../results/kprog_fidelity_20261106/differential/x86-sp-observer-control
taskset -c 16-19 make -C kprog/fidelity -o build reference-check BUILD=build-x86-sp-observer-control OUT=../results/kprog_fidelity_20261106/differential/x86-sp-reference CASES=1024
taskset -c 16-19 make -C kprog/fidelity run-emulated ARCH=arm64 BUILD=build-arm64-sp-observer OUT=../results/kprog_fidelity_20261106/differential/arm64-sp-observer
taskset -c 16-19 make -C kprog/fidelity -o build reference-check ARCH=arm64 BUILD=build-arm64-sp-observer OUT=../results/kprog_fidelity_20261106/differential/arm64-sp-reference CASES=1024
taskset -c 16-19 make -C kprog/fidelity arm64-control-build ARM64_CONTROL_BUILD=build-arm64-control-sp-observer
taskset -c 16-19 make -C kprog/fidelity arm64-control-qemu ARM64_CONTROL_BUILD=build-arm64-control-sp-observer ARM64_CONTROL_OUT=../results/kprog_fidelity_20261106/differential/arm64-control-sp-observer
taskset -c 16-19 make -C kprog/arm64 micro-proofs-build PROOF_BUILD_DIR=build/fidelity-wsp/micro-proofs NEGATIVE_NATIVE_BUILD_DIR=build/fidelity-wsp/negative-native MICRO_SIM_PROOF_ARGS='--jobs 1'
taskset -c 16-23 make -C kprog/results/kprog_fidelity_20261106/differential/wsp-return-negative check
```

`-o build` reuses the already built, frozen CPU harness when replaying it;
it does not omit any instruction form. The initial732-form x86 observer run
is retained in `x86-sp-observer/`; the final733-form matrix adds the positive
ADD-to-SP observer control. `sp-observer-harness-artifacts.tar.gz` retains exact
headers/imports, generated C/native assembly, binaries, driver sources, the
old Arm header closure used for the paired test, and the WSP negative object.
The old-header test compiles the same generated control C/native object with
only its simulator include changed to that archived old header.

The two new static Arm handoffs are
`cpu-differential-arm64-sp-observer.gz` and
`cpu-differential-arm64-control-sp-observer.gz`. The existing hardware scripts
accept them through `ARM64_HANDOFF` and `ARM64_CONTROL_HANDOFF` respectively.
Expected current exit status is1, with4096 ordinary and1024 control differences.
The earlier successful hardware matrices remain separate and unchanged.

The preliminary76-form Arm MOV-to-SP run remains in `arm64-control-movsp/`; it predates final-SP capture. `sp-observer-preliminary-artifacts.tar.gz` retains its exact source/binary and the preliminary732-form x86 harness.


## LEA-to-RSP repair replay

C's one-condition repair, published in `7123cfddd`, keeps LEA-to-RSP in the
relative-SP representation consumed by the stack-memory path. The focused
production-encoder replay in `x86-lea-sp-after/` now agrees for all1024 states
of `lea rsp,[rsp+16]`; the same form previously disagreed in all1024 states.
The generator also retains its30 branch/call control composites, so the whole
focused run reports31 forms /31744 cases /zero mismatches. Its exact headers,
generated C/native code and static binary are archived there. The broader
733-form pre-repair matrix remains unchanged; other numeric-base, flags,
narrow-value and stored-pointer observations remain active shared work.

```sh
taskset -c 16-19 make -C kprog/results/kprog_fidelity_20261106/differential/x86-lea-sp-after check
```

## Expanded independent Arm reference on the identical CPU trace

After V's arithmetic/extension and earlier scalar/vector reference additions,
the **same567-form SP-observer trace** now checks523 forms /535552 cases.
CPU versus canonical reference:zero differences. Simulator versus reference:
4096 differences, unchanged and confined to the same four SP/WSP transfers.
The replay adds104 checked forms (ADD/ADDS/SUB/SUBS/CMP/CMN/CCMP,
CNT/UADDLV and FMOV families) relative to the previous419-form comparison.
It does not regenerate the native/simulator trace or erase any prior result.

The remaining44 forms have exact diagnostics in
`arm64-extend-reference/reference-unavailable.jsonl.gz`: NOP, ten bitfield
aliases, integer loads/stores/addressing variants, LDP/STP and Q loads/stores.
The full567-form per-form TSV includes every checked/missing row. The command
exits1 because of these missing encodings and the preserved SP differences.
No second reference ISA was introduced. `reference-snapshot.tar.gz` freezes
the actual executable, its captured Arm source/provenance, the replay adapter,
and the unchanged static CPU harness/coverage. The original CPU-state trace
is `arm64-sp-reference/cpu-states.bin`; archived mismatch records additionally
include every failing input, real SP anchor, memory and canonical output.

```sh
taskset -c 16-19 make -C kprog/results/kprog_fidelity_20261106/differential/arm64-extend-reference replay
```

## Complete x86 replay after the LEA repair

A fresh frozen-header build now reports733 forms /750592 real CPU cases /
10240 raw state differences:723 forms agree in every case; ten SP-observing
forms differ in all1024 states each. The previously failing `lea rsp,[rsp+16]`
row now agrees in all1024 cases. No other row changed its mismatch count.
The remaining rows are MOV RAX/RSP, MOV EAX/ESP, LEA RAX/[RSP+16], CMP RSP/0,
MOV RSP/RAX, MOV ESP/EAX, PUSH/POP RSP and PUSH/POP SP. These retain the
numeric-base/frame-projection obligations explained above; they are not
silently normalized or counted as ten independent unsafe programs.

`x86-after-lea-complete/forms.tsv` reports every form and count;
`mismatches.jsonl.gz` retains all10240 input/output/memory/SP-anchor records.
`harness-artifacts.tar.gz` retains exact native/generated source, static binary,
header/import snapshot, coverage and driver/build sources. `host.txt` and
`run.log.gz` retain host provenance, warnings and the expected nonzero exit.
No native unsafe negative is executed by this instruction-level harness.

```sh
taskset -c 16-23 prlimit --as=12884901888 -- timeout 900 make -C kprog/fidelity run BUILD=build-x86-after-lea-complete OUT=../results/kprog_fidelity_20261106/differential/x86-after-lea-complete
```

## Full32-vector Arm FMOV observer

`arm64-bank32/README.md` records128 forms /131072 QEMU cases with zero
native/simulator differences while checking every vector register. All128
forms also agree with V's canonical reference for every state, with zero
missing encodings. A new static full-bank hardware handoff is
`cpu-differential-arm64-bank32.gz`; the existing hardware script accepts it
through `ARM64_HANDOFF`. A733-form/16-state x86 compatibility run retains
exactly the previous per-form agreement status after the shared observer
layout extension. Earlier SP and address-state findings remain unchanged.

## Canonical Arm scalar memory and pair replay

`arm64-memory-reference/README.md` reuses the identical567-form CPU trace
with a frozen canonical executable:543 forms /556032 cases checked, zero
CPU differences,4096 unchanged model SP/WSP differences. Twenty additional
forms now decode, including scalar loads/stores and LDP/STP. All24 remaining
encoding requests stay in the report and active coverage queue. The adapter
reads the original trace directly and freezes the reference executable before
the replay, avoiding another duplicate1GiB trace.

## Canonical bitfield closure

`arm64-bitfield/README.md` records the handed-off canonical bitfield increment:
full formal check passes, and70 full-bank boundary/alias forms ×1024 QEMU
states agree with C and the canonical reference. The same original matrix
now checks553/567 forms (566272 cases), with zero CPU differences and the
same4096 model SP/WSP differences. All14 remaining memory encodings stay
in the active queue. A static full-bank bitfield hardware handoff is included.

## Exclusive-family audit

`arm64-exclusive/README.md` adds8 production-supported exclusive forms absent
from the old matrix. All4096 W/X STXR/STLXR cases after explicitCLREX disagree:
native status1/no-write versus C status0/write. All inputs and outputs remain
in counterexamples; a static hardware handoff is supplied. Four corresponding
unsafe failure branches are accepted by actual bound load-only tests. Monitor,
ordering and admissible failure/success semantics remain active repair work.

The expanded six-flag x86 replay covers 799 forms / 818176 hardware cases,
including every active CMOV/SET/Jcc condition and alias. The saved-state
canonical replay checks 452 forms / 462848 cases with zero CPU differences
and 10240 existing simulator stack-address differences; 347 forms remain
explicitly unhandled in this reference snapshot. Raw CPU replay has 11264
stack-address observations. Exact per-form inputs, commands and frozen source
are in differential/x86-full-conditions/README.md (or x86-full-conditions/
relative to this directory); the preceding 745-form result is retained.
