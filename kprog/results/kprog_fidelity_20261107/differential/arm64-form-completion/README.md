# Complete missing ARM numeric instruction forms

Extend the existing single instruction matrix with CMP/CMN immediates at
W/X widths, the ZR-destination BICS test form and all existing D0 memory
addressing modes. Production encoder/macros and the same c110b03a canonical
reference are reused; no new ISA model or production semantics is introduced.
Earlier771-form results remain unchanged.

The Make-backed incremental build and canonical replay run detached on
CPUs16-19. Results and any exact counterexamples will be retained after
completion. These are emulated observations; real ARM hardware remains
required through the static handoff. The active34-case safety guest is
independent and remains unchanged.

```sh
taskset -c 16-19 make -C kprog/fidelity build ARCH=arm64
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/differential/arm64-current-logical/Makefile reference OUT=/workspaces/repository/kprog/results/kprog_fidelity_20261107/differential/arm64-form-completion
```

The native assembler accepts all805 instructions, but the production encoder
rejects two new valid forms: `ldur d0, [x4, #8]` and `stur d0, [x4, #8]`, each
with `unsupported register: d0`. Its existing D0 special cases select only
LDR/STR; unscaled LDUR/STUR enter the scalar-register parser instead. The
other32 added forms encode successfully. `decoder-forms.json` retains all34
added-form outcomes; no rejected form is silently removed.

The Make build exits2 before generating/linking the new C harness, so no805
CPU/canonical pass is claimed. The old771 binary was not run by this failed
driver. `build-failure-summary.json` and the compressed unaltered log retain
the failure; `attempt-inputs.tar.gz` preserves original native assembly,
object/disassembly, production include/encoder closure and exact generator.
The10-line matrix extension remains pending source work until the parser
repair and replay pass. Production code has not been edited while the
independent original34 safety guest still consumes it; that active source
input is preserved. This is an open encoder defect, not out-of-scope work.

## Forward parser repair and complete807 replay

The production encoder now recognizes unscaled LDUR/STUR for its existing
D0 and Q0 handlers. Only four mnemonic predicates change; existing memory
semantics, width/address decoding and native instructions stay unchanged.
Two matching Q0-unscaled forms extend the matrix from805 to807.
`repaired-decoder-comparison.json` checks all807 actually assembled native
instructions against the original encoder:803 previously accepted records
are unchanged, while the four valid unscaled vector forms now select their
existing D0/Q0 opcodes. The original805 failure archive above is retained.

The incremental build and full canonical replay both exit0:
**807 forms x1,024 =826,368 states, zero QEMU/C, QEMU/reference or C/reference
differences, zero unavailable forms**. `repaired-summary.json` pins both
executables; form tables preserve every case count. Complete mismatch and
unavailable streams are empty and retained compressed with original logs.
`repaired-compiled-inputs.tar.gz` preserves exact source/header/generated
inputs; every archived file was independently rehashed against its manifest.

The current static ARM handoff is `cpu-differential-arm64.gz`, SHA256
`f579152c37404acec64c36c187700babc42b5a09544754f0013e65dbe935d682`.
The existing default handoff now selects this807-form executable. On real ARM
hardware the coordinator runs, from the repository root:

```sh
sh kprog/fidelity/run-arm64.sh
```

Actual ARM hardware execution remains pending. These constant-form observers
do not close entry ABI projection, the independent dynamic-dispatch host
compile regression, exclusive monitor/order effects or all O1-O4 obligations.
The separately completed ARM34 and x86 safety suites retain their own scope.

## Raw trace cleanup, 2026-11-07

At the coordinator's explicit disk-cleanup request, the closed
`cpu-states.bin` (1,500,684,312 bytes, SHA256
`51c4052b1ef0ebd9943fb72f0ce2c4b0bf45aa0d6de115376cde75407ad6af9c`) was deleted after checking every
visible process's file descriptors and mappings: no users or inaccessible
processes. The summary and per-form tables were already committed and
published. Static executables, compiled input archives, logs, counterexample
streams and incremental build caches remain. Regenerate the trace with the
recorded run command before any future `--reuse-trace` replay.

## Current handoff supersedes this historical snapshot

The default hardware handoff now selects [arm64-current-core](../arm64-current-core/README.md),
which contains the later published b890/c218 simulator snapshot and static
binary 2eb0d29a. Its unchanged807-form QEMU/C/canonical replay completes with
zero differences. This directory retains the exact14:22/c82 source, binary,
failure and completed results as history. The existing run-arm64.sh command
now selects the newer artifact; real ARM hardware results remain pending.
