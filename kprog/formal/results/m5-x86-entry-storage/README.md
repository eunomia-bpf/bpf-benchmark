# x86 handler entry storage

The actual ALU_REG allocation preserves all caller bytes and permission maps.
`writer_caller_access` carries any caller typed permission into reached heaps
with the allocated access map. `writer_entry_registers` preserves the complete
native GPR representation, including pointer origins and tags.
`writer_entry_storage` derives the real local binding, its writable word and
separation from caller blocks, and carries the caller table word/tag rights.

Validation: exact current `X86RegisterView.lean` through
`lake env lean -j1 --stdin`, then four public type/axiom queries: exit 0,
9.13 seconds, one worker, original proof budgets. The four new theorems use
only propext, Classical.choice and Quot.sound. No compiled outputs were added.
The [query output](proof.txt) is retained; raw logs and invocation metadata
are under `/workspaces/kprog-raw/V/x86-entry-storage-20261122`.

The 169-step ordinary scalar byte writer is established separately.
Connecting these derived permissions to that run is next. Complete handlers,
dispatcher composition, O1/O2/O4 and M5/M6 remain open.

## Allocated writer composition

`byte_writer_allocated` composes these entry-derived facts with the actual
169-transition writer run. It constructs the local and all four intermediate
store heaps internally, derives the width-helper scope from the real local
list, and updates the complete represented GPR bank via the original
`X86.Cpu.setReg`. Final permissions and nextblock equal the reached input.
Caller table rights, linked layouts/callee and the reached source observations
remain explicit. The prefix from the handler body to this writer is still open.

The exact updated source plus the public type/axiom query passed in 10.52s at
one worker and the original proof budgets. The inherited CompCert external/asm
semantic axioms appear in this execution composition; no new axioms were added.
See [the output](allocated-writer.txt).

## Other caller blocks

Both writable and allocated writer theorems additionally retain the complete
raw contents of every unaffected block. The allocated form proves exact bytes
and Cur/Max permission maps for every old caller block except the register-table
block. Existing selected/other-register results still cover the table's modeled
cells. This frames separately allocated flags, memory and SIMD storage when their
block identities satisfy the stated separation. It does not assume a successful
load or discard undefined bytes.

The exact source and both public type/axiom queries passed in 9.23s with the
original proof budgets and a 32 GiB process cap. See [the output](framed-writer.txt).
The initial arithmetic projection-normalization diagnostic is retained in raw
`framed-writer.txt`; the successful run is `framed-writer-pass.txt` there.
No axioms or intermediate-store premises were added.
