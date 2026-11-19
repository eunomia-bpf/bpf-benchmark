# M5: initialized Numeric null vector-pointer slots

The existing null-vector lvalue/store/list laws now execute in a supplied
world with the same composite layout. Actual source metadata, offsets,
writable memory and store construction are reused. Three old public
contracts remain projections, including the combined 228-transition header
law and its cache witnesses.

`initialized_null_vectors` composes the actual Numeric producer through all
98 input visits, stack/SP/context setup and the 12 scalar header pointers,
then the next 64 actual null pointer stores in 192 silent transitions. Each
slot at `96 + 8*i` holds typed C NULL, represented as `Vlong 0`. These slots
are separate from the 64 input vector words in the allocated vector array;
the live pointer loop follows the still-unproved Numeric header tail.

All 12 scalar pointer readbacks and their source-local bindings survive.
Both tables and updated GPRs (x0 context/tag 1 and x30 zero/tag 10), flags,
LR/SP zero, vector words, stack tags, context cells, cold caches, `_ctx`,
original 204-frontier globals/permissions and allocation access/frontier
survive. The same 98 ordered provider traces remain, with no new input visit.

Both borrowed cache-storage resources are derived at the reached memory
from the preserved scalar pointers and actual allocation rights. Binding
uniqueness connects their cells to the earlier cold values. No scalar-header
execution is repeated and cache storage is not assumed at the new memory.
The original represented-context and actual-world provider contracts remain
explicit; caller/native admission and physical memory are still M5 work.

Next is the 16-store header tail and its actual Numeric callback bindings,
then the vector loop, full Storage/caller/native/provider admission, relative
materialization, physical memory/alias/origin/control and O1/O2/O4 recount.
Complete ISA-handler/family count remains 0; M6 follows M5. The x86 atomic
and released-alias formal bindings remain separate open obligations.
No C/runtime, benchmark, paper/design, kernel, base or image change is made.

Raw attempts: /workspaces/kprog-raw/formal/m5-numeric-producer-header-vectors.
Every host command holds timing SH. One-worker builds use CPU 17 and 32 GiB;
reads/queries/Git use CPU 16. Heartbeats 200000, recursion 512, async false.
Validation outcomes and public axiom sets are recorded in validation.json.

Final validation: full Lake passes 331 jobs; all seven public type/axiom
queries pass. Focused attempts are retained in validation.json. All ten Arm64
exports retain the byte baseline. The historical 23-file comparison records
12 changed x86 exports and exit 1; it remains an explicit
report, with no x86 atomic/alias proof claim. Current export bytes are
248620630; historical baseline bytes are 243488732. Native make check
remains due at final goal confirmation.
