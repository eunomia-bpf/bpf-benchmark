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
