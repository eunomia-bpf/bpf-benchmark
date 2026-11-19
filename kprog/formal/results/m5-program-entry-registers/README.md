# Actual first provider return and register writeback

The actual production continuation consumes a supplied 64-bit input word and
executes its nine internal writeback transitions to the real next-register
stage. The resulting shared store witness contains the full x0 word, scalar
tag zero, other-local readbacks, caller framing, permissions and frontier.
Actual local bindings are derived from allocation correspondence; the GPR
record and its union-x offset zero are the only composite premises.

`Arm64Producer.declaration_stores_for` exposes the existing word/tag store
construction for any declared, distinct word/tag names. The original source
factory specializes it. `declaration_return_body` and `declaration_zero_body`
share the existing execution proofs over arbitrary functions and local
environments using the named GPR layout and two real local bindings. Existing
source input-return and x30 interfaces retain their signatures. The production
proof instantiates that same memory witness, without copying a producer, C
fixture or memory interpreter.

`first_input_returns` composes the actual five-step call prefix, the stated
external provider outcome, and the nine-step writeback. It retains exactly the
provider trace and supplied post-memory. The external transition is separate
from the nine internal transitions. Its store-frame properties refer to the
supplied memory, so caller/cache preservation through the provider remains an
explicit invocation contract.

`entry_first_returns` composes the already checked actual 594-step call prefix
with a framed first-provider contract and writeback. The actual continuation,
function, allocation environment and mapped temporary names are retained. Both
cache words and validity bytes stay zero under the provider's stated local
preservation. Final permissions and allocation frontier equal those from the
actual allocation, and the caller frame composes across all three segments.
`other_temporaries` preserves every temporary outside the two return names;
`context_retained` derives the original context lookup after writeback.

This result is conditional on the explicit provider contract. Native input
availability, all-outcome semantics and original-context correspondence remain
M5 obligations. The remaining GPR declarations, x30 branch, pointer tables,
flags/vector/stack/context setup, and actual header/body/native composition
remain to be migrated. The signed32 production wrapper and borrowed uint32
consumer ABI remain distinct. Completed ISA-family count remains zero; M6
follows M5 and its O1/O2/O4 recount.

Public type/axiom queries are in `Query.lean`; commands, exits, source hashes
and proof limits are in `validation.json`. Raw logs and all attempts remain in
`/workspaces/kprog-raw/formal/m5-program-entry-registers`. Checks use CPU17,
one worker, 32 GiB address space and unchanged 200000-heartbeat/512-recursion
caps with `Elab.async false`, controlled on CPU16. The 2026-11-19 18:18:59
coordination rule permits host builds without the timing lock. No C/runtime,
compiler, kernel, base, image, benchmark, paper or design source changes here.
Fresh final Lake and `make check` remain required at M1–M6 closure.

The shared helper build passed 149 jobs (15.718 s); the production build passed
175 jobs (366.872 s including rebuilt dependencies, actual module 4.6 s).
All eleven public type and axiom queries passed (1.672 s). One full `lake build`
passed 350 jobs (552.872 s), including existing source/provider/storage and
MOVK call/native/context proofs. There were no failed attempts in this batch.
Store construction, executable-step, layout and temporary-frame laws use
standard logical axioms. Relational `InternalRun`/`Star` facts retain the
imported `CC.externalFunctionsSem` and `CC.inlineAssemblySem` model axioms.
No new axiom, `sorry`, C source or proof-limit increase is introduced.

The historical whole `make check` pass remains
`5236c0e9677f635526fdd515cde5195b2ba0810c`; this is not a fresh check of this step.
The last export comparison is recorded in the entry-fields receipt (ten Arm64
exports match baseline; twelve historical x86 differences remain recorded).
