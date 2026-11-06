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
hardware identity and commit its output. **Real AArch64 hardware has not run
here.**

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
