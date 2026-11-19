# Actual production setup and first input boundary

The production wrapper's three helper-context setup assignments execute in
nine Clight transitions. With the preceding actual ABI/cache prefix this takes
589 transitions from the one-context call entry to the real first-register
stage. The initial context and every other temporary are unchanged. Both cache
base words and validity bytes remain zero in the actual allocation environment;
caller framing, permissions and the exact allocation frontier are retained.

`setup_source` compares all three assignments and their successor with the
production body. `first_declaration_source` compares the complete first
register declaration with its source schema using the actual mapped temporary
names and actual next-register successor. The generic declaration-call proof
resolves an arbitrary input block with its full imported signature and a local
non-shadowing proof. Its production instance uses the independently proved
actual block 59, while the existing source APIs continue to use block 64.

The real five-transition branch/sequence/call prefix composes to
`first_input_ready`: 594 silent internal transitions from the actual generated
call to the actual kind-6 input call. Its saved continuation carries the real
production function, allocation environment and unchanged initial temporaries.
The provider's return word, trace and post-memory remain explicit future
obligations; no external transition is added by this result.

The existing source setup proof now parameterizes its executing function,
environment and successor. Its original store construction, other-local
readbacks and frame proofs are shared with the production instance. The
existing source setup and register-input-ready APIs retain their signatures.
There is no second producer/store replay or copied C fixture.

This extends actual execution through 196 of the 419 pre-header spine
statements and into the first register declaration. The remaining provider
returns/register traversal, pointer tables, flags, vector/stack/context setup,
header/body composition and native/original-context admission remain M5 work.
The actual signed32 wrapper and borrowed uint32 consumer return bridge remain
distinct. Completed ISA-family count stays zero; M6 follows M5.

Validation commands, exits, source hashes and public axiom reports are in
`validation.json`, with reproducible public queries in `Query.lean`. Raw data
is retained under `/workspaces/kprog-raw/formal/m5-program-entry-inputs`.
Host checks use CPU17, one worker, 32 GiB address space, original 200000-heartbeat
and 512-recursion caps, and `Elab.async false`; controls run on CPU16. The
2026-11-19 18:18:59 coordination rule permits host checks without the timing lock.
No simulator C, runtime, compiler, kernel, base, image, benchmark, paper or design
source changes in this step. Fresh final Lake and `make check` remain required
at M1–M6 closure.

Focused shared-helper build passed 149 jobs (92.505 s). The final actual-module
build passed 174 jobs (4.280 s after its dependencies); its earlier 344.373 s
attempt hit Meta recursion only on the closed declaration equality, whose direct
reflexivity certificate now passes kernel checking at the original caps. Eleven
public type and eleven axiom queries passed (1.969 s). One full `lake build`
passed 349 jobs (559.853 s), including the existing provider/storage and MOVK
call/native/context consumers. Syntax certificates use standard logical axioms;
execution proofs retain the imported `Step2` external-function and assembly
model axioms. No new axiom, `sorry` or external transition is introduced.

The historical full `make check` pass is
`5236c0e9677f635526fdd515cde5195b2ba0810c`; this step does not claim a fresh run.
The historical 23-export comparison remains in the entry-fields receipt (ten
Arm64 exports match baseline, twelve historical x86 differences recorded).
