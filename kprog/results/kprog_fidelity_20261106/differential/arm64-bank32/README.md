# Full32-vector FMOV comparison

All128 forms pass1024 states each: **131072 native/simulator cases, zero
mismatches**. The independent canonical reference also checks all131072
cases, with zero CPU differences, zero simulator differences and zero missing
encodings. `forms.tsv` and `reference-forms.tsv` report every form separately;
the compressed counterexample files are empty because these runs agree.

The matrix covers D←X, X←D, S←W and W←S for each V0..V31, including V31
and X30. Every case initializes all32 independent128-bit vectors, all31 GPRs
and NZCV, and compares the complete vector bank and GPR output, modeled SP,
flags,64 stack-observer bytes and256 external-memory bytes. Boundary GPR
inputs precede fixed-seed random states. NZCV cycles all16 combinations. The
production encoder and `append_insn` emit the simulator step; there is no
second ISA implementation in this harness.

The native observer saves guest X0 temporarily in user-writable TPIDR_EL0,
allowing it to capture every vector and GPR without using an unobserved
vector scratch register. It restores the original thread pointer before any
call or return to C, and preserves the caller's callee-saved registers. The
generated instruction is always FMOV and leaves SP unchanged. Observer loads,
saves and thread-pointer operations are outside the recorded native PC span.
The reference receives all32 vectors explicitly; no unprovided bank values
are invented. Trace header KPFID002 retains its explicit state-size field:
the full-bank state is840 bytes, the original V0-only state remains344 bytes.

Commands on host CPUs16–23:

```sh
taskset -c 16-23 prlimit --as=12884901888 -- make -C kprog/fidelity -f bank32.mk run-qemu
taskset -c 16-19 make -C kprog/fidelity -f bank32.mk reference
taskset -c 16-19 make -C kprog/results/kprog_fidelity_20261106/differential/x86-driver-layout check
```

This run uses qemu-aarch64-static and establishes emulation agreement; it
does not claim an Arm hardware result or timing. For real Arm hardware,
the coordinator runs the same static binary through the existing script:

```sh
ARM64_HANDOFF=../results/kprog_fidelity_20261106/differential/cpu-differential-arm64-bank32.gz OUT=../results/kprog_fidelity_20261106/differential/arm64-bank32-hardware taskset -c <hardware-core-set> kprog/fidelity/run-arm64.sh
```

`../cpu-differential-arm64-bank32.gz` is the static handoff. The hardware
script checks the host architecture and enters the Make target.
`harness-artifacts.tar.gz` preserves generated C/native assembly, raw native
instruction objects/disassembly, static CPU binary, frozen production
include/import closure, driver/generator/build/replay sources, and the exact
canonical executable and source closure. `native-code.json` records every
actual native byte span. `provenance.txt` records the source commit; the
full-bank production increment is now published as d8845e7a4, with formal
reference increment648423317. No production simulator is edited by F here.

The x86 compatibility run exercises733 forms ×16 states (11728 cases).
All733 retain their prior CPU agreement status: the same723 forms agree and
the same ten SP-observing forms differ. Its detailed report is in
`../x86-driver-layout/`; it tests the observer/layout extension, and does
not replace the complete1024-state x86 matrix or close its SP findings.

`../superseded-reference-reports.tar.gz` additionally preserves all per-form
reports, unavailable-encoding diagnostics, counterexamples and native byte
metadata from the earlier Arm production/unary reference passes before their
superseded raw CPU traces are removed for disk recovery. Current comparison
traces remain in place until their readers finish.
