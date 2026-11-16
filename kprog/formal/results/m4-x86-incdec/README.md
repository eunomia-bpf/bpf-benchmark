# INC/DEC preserve the live pointer representative

PERF's actual copy-loop fixture reproduced a shared-handler fault: after INC RDI,
the numeric writeback discarded its memory tag and installed exposed native
stack bits as a host pointer. The following MOV_STORE_REG faulted. The immediate
ALU handler now updates the pointer representative and retains its memory tag
for full-width, zero-lane INC/DEC. Its delta comes from the computed result, so
the unused encoded immediate cannot change the unary operation. Flags keep the
existing numeric computation. Narrow/lane writes and RSP's offset/release path
keep their existing behavior.

The six-line production change leaves the ADD/SUB branch intact. Two earlier
candidates widened that branch; although their host checks passed, they changed
the unaffected ADD copy-loop from 1,232 to 1,352 B and four to six relocations.
Those candidates were discarded before publication; their logs stay in raw.
The final ADD loop and the program, inline and frame-376 fixtures have identical
allocated sections and relocations against `69a67b0a0` and ordinary current
builds. This corrects INC/DEC behavior; it does not assert all native programs
have unchanged bytes.

`oracles/test_x86_incdec_host.c` checks 115,200 complete states per mode: direct
macro, native inline and CompCert adapters. It covers both unary operations,
RDI/RSI, all 256 tag bytes, widths 0/1/2/4/8/255, zero/high-byte lanes, three
ignored immediates and three carry bytes. Separate RSP cases check offset
representation, one-byte release inputs and cleared fact cells. Independent
expectations compare all flags, full register/private state, fact arrays and
input counts. The old header fails at case 216; the repaired header passes.
The initial test's lane encoding error and its correction are retained in raw.

The supplied host target is reproduced from the repository root:

```
make -r -f kprog/test/native-relocations.mk loop-pointer-analysis \
  LOOP_POINTER_ARGS="--step inc" OUTPUT=<new-raw-directory>
```

Repeat with `--step add`. Each final replay passes 64 native and 64 complete
shared-simulator executions, with a 72-byte frame and one return continuation.
The target uses its existing CPU 16-18/8 GiB limit and replaces its normal build
in place. These are host checks; no guest, workload or image is changed.

`make clight` runs all three unit modes and regenerates the actual exported
handlers. Only X86Inline, X86ProgramProfile, X86StackProfile200 and
X86StackProfile376 change; their final sizes and checks are in `result.json`.
All other 15 Clight sources remain byte-identical to `69a67b0a0`. Earlier result
receipts describe the ASTs at their own commits. The program's layout, typed
clock call and two return continuations are checked again on the current AST.

Full logs, failed candidates, old-header regression, final loop outputs,
compiler commands and native comparisons remain at
`/workspaces/kprog-raw/formal/m4-x86-incdec`. M4 remains in progress. No exported
Clight refinement is inferred from these finite checks; all 2,065 M5 proofs and
the O1/O2/O4 recount precede M6 and final whole-project confirmation.

An extra export probe to `/dev/stdout` differed; the final deterministic checks
use each normal output path and match all four files exactly. The unsuccessful
probe and all interim candidate validations remain in raw. The final C and Lean
results above were rerun after selecting the separate unary branch.
