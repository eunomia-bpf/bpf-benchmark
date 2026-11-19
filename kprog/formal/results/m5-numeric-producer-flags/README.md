# M5: initialized Numeric flag inputs and LR zero

The existing actual flag call and return/store proofs now execute in an
explicit world with its real input symbol/fundef binding. The three call
setup transitions and four return/store transitions retain genuine source
continuations, temporary keys, full provider words, traces and post-memory.
The actual byte store derives `flagWord`, the exported unsigned-byte cast of
the input word AND 1, proved to be either 0 or 1. The separate pure LR-zero
assignment executes its three real transitions in that world. All prior
standalone public API statements remain projections of these shared laws.

`ProviderAt` states flag outcome availability in the actual world's Senv,
with provider frame, local-read preservation, access and nextblock facts.
The existing four-visit induction now uses it in that world. The final pure
LR store preserves the masked flag readbacks and reaches `vectorStart`.
No vector call is consumed, and no first flag call setup is duplicated.

`initialized_flags` starts with actual Numeric initialization and the already
proved 30 GPR visits, x30 zero and pointer tables. It derives all four masked
flag bytes and LR zero from their real stores, preserving all 62 table
pointers, all 31 pointed-to word/tag values, both cold caches, `_ctx`, and
the initial 204-frontier global contents and both permission maps. Allocation
access and nextblock remain. The actual 30 GPR traces followed by four flag
traces form one ordered 34-trace list; no empty-trace or post-memory=pre-memory
premise is introduced. Actual table/flag/LR bindings remain available.

The two provider availability/ABI premises remain explicit; this is not an
implementation or native admission proof. Full flag words are arbitrary;
the source masks them before storage. Native NZCV correspondence, 64 vector
visits, complete producer/header/RAW/register Storage/caller transport,
relative caches, native physical memory/alias/origin/control and all-family
O1/O2/O4 recount remain M5. Complete ISA-handler/family count remains 0; M6
follows M5. No C/runtime, benchmark, paper/design, kernel, base or image change
is made here.

Validation and retained attempts are in validation.json. Raw data:
/workspaces/kprog-raw/formal/m5-numeric-producer-flags. Builds use one worker
on CPU 17; reads/queries/Git use CPU 16. Every command holds timing SH, with
32 GiB address space and normal 200000 heartbeats / 512 recursion limits.
No new trusted axioms or increased proof limits are introduced.

Final result: shared focused build passes 170 jobs; actual composition passes
182 jobs after the retained reserved-identifier parser correction. Full Lake
passes 327 jobs once at the end, all nine public type/axiom queries pass, and
all 23 exports remain byte-identical (243,488,732 bytes) to 9c617740f. Queried
laws use only standard axioms and the existing Clight external-function and
assembly parameters. Native make check is due at final goal confirmation
(last whole pass 5236c0e9677f635526fdd515cde5195b2ba0810c).
