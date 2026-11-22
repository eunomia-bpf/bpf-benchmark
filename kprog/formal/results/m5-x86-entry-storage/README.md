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
