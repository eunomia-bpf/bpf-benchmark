# Actual production pointer-table initialization

The actual post-register spine now has a checked equation for all 62 pointer
table assignments and their real successor. The first 31 assignments initialize
the word-cell table; the next 31 initialize the tag-cell table. Each statement
agrees with the existing source schema. The actual tail is extracted from the
production AST, with no assumption that source and production continuations
agree.

`Arm64Producer.initialize_pointer_table_body` generalizes the original table
execution and list induction over function and local environment, taking actual
table/cell bindings. The existing allocation, writable range, slot alignment,
store construction, typed readback and frame proof remain shared. The original
source APIs instantiate that same proof. The production instance derives its
actual bindings from the imported allocator and checked local-name/type
correspondence. Pointer arithmetic uses the unchanged 8-byte pointer stride;
no equality of the complete composite environments is required.

Each table executes 93 internal transitions. `initialized` composes the actual
62 stores in 186 internal transitions to `afterPointerTables`, retaining all
62 typed pointer readbacks, other-local loads, unchanged temporaries, caller
frame, permissions and allocation frontier. Its readback witnesses include
both actual table and actual cell bindings.

`entry_initialized` composes the preceding actual call/register traversal with
this table phase. All 30 provider traces, 31 word/tag values, actual cell
bindings, cache base/validity readbacks and the original context temporary are
retained. Each table pointer is proved to identify exactly the corresponding
register-readback cell by equality of allocation bindings. The tables and
register values therefore describe one reached memory with the same cells.

Provider availability, post-memory preservation and native/original-context
correspondence remain explicit invocation obligations from `ProviderAt`.
Remaining flag, vector, stack and context setup must execute before joining
the separately proved header/body suffix. Native/all-outcome admission, the
signed32 wrapper/borrowed uint32 return bridge, ISA refinements and O1/O2/O4
recount remain M5 work. Completed ISA-family count is zero; M6 follows M5.

Public queries are in `Query.lean`; commands, exits, source hashes and repaired
attempts are recorded in `validation.json`. Raw data remains under
`/workspaces/kprog-raw/formal/m5-program-entry-tables`. Checks use CPU17, one
worker, 32 GiB address space and unchanged 200000-heartbeat/512-recursion caps
with `Elab.async false`; controls run on CPU16. Host checks follow the
2026-11-19 18:18:59 coordination rule without the guest timing lock. This step
changes formal proofs, receipts and its todo line. Fresh final Lake and
`make check` remain required when M1–M6 close.

The focused build passed 190 jobs; all ten public type and axiom queries passed.
One full Lake build passed 353 jobs. The initial generic result-state mismatch
and its failed check remain in the raw logs and receipt. Source equations and
local-binding facts use standard logic; execution proofs retain the imported
Step2 external and assembly semantic models. No new axiom or proof-limit change
was added.
