# M5: initialized Numeric x30 and pointer tables

The shared pointer-table execution proof now accepts its actual execution
world. Assignment evaluation only needs pointer-size arithmetic and local
bindings, so this pure table segment needs no global symbol or external-call
premise. The x30 zero branch retains its explicit composite-layout fact.
Existing table metadata, allocation resources and source-store construction
are reused; all three standalone public contracts remain projections.

The combined 196-transition law retains unchanged-local readbacks, including
those previously discarded by the older combined API. Its 10-transition x30
zero branch is followed by both 93-transition table initializations, with
62 actual pointer stores. This preserves the prior 30 input values and both
cold caches while deriving the real x30 full64 zero word and scalar tag.

`initialized_pointer_tables` composes after all 30 admitted provider visits
from the initialized Numeric program. Both typed 31-slot tables point to the
actual allocated cells, and all 31 word/tag readbacks are derived from source
stores and binding uniqueness. Input values are retained at x0..x29; x30 is
zero without a provider call. The real temporary environment retains `_ctx`,
the original 204-frontier globals retain contents and both permission maps,
and allocation access/nextblock are preserved. All 30 actual provider traces
remain ordered; the final pure segment appends no events.

The provider ABI/availability premise remains explicit in the actual Numeric
Senv, with full post-memory. It is not a native protocol implementation or
native admission proof. Four flag and 64 vector visits, producer/caller and
native admission, relative caches, physical memory/alias/origin/control and
all-family O1/O2/O4 recount remain M5. Complete ISA-handler/family count stays
0; M6 follows M5. No C/runtime, benchmark, paper/design, kernel, base or image
change is made here.

Validation and retained attempts are recorded in validation.json. Raw data:
/workspaces/kprog-raw/formal/m5-numeric-producer-tables. Builds use one worker
on CPU 17; reads/queries/Git use CPU 16 while PERF may use 18. Every command
holds timing SH, with 32 GiB address-space and normal 200000 heartbeats / 512
recursion limits. No new trusted axiom or increased proof limit is introduced.

Final result: shared focused build passes 151 jobs; actual composition passes
181 jobs after the retained pointer-zero normalization correction. Full Lake
passes 326 jobs once at the end, all seven public type/axiom queries pass, and
all 23 exports remain byte-identical (243,488,732 bytes) to 9c617740f. Queried laws use
only standard axioms and the existing Clight external-function/assembly
parameters. The native make check is reserved for final goal confirmation
(last whole pass 5236c0e9677f635526fdd515cde5195b2ba0810c).
