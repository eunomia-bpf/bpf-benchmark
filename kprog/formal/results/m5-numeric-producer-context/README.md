# M5: initialized Numeric stack, SP and context

The existing 24 stack-tag stores and SP-zero store now execute in their actual
world. Their source metadata, resource constructors, store proofs and list
induction are reused. They take 72 + 3 real internal transitions, preserve
other local reads, and retain the caller frame, access and nextblock.

The five context stores use the actual world and its matching composite
layout. Existing defined-cast `ValueRep` and local-storage premises remain.
The existing source lvalue/RHS/store/list proofs are reused, with 15 actual
internal transitions and unchanged-local readbacks retained. The combined
90-transition law preserves every needed local observation and all old public
standalone statements remain projections.

`initialized_context` follows all 98 admitted Numeric input visits. It derives
24 zero tag bytes, SP zero and all five actual context-cell readbacks, including
helper context/ABI pointers. x0's word becomes the represented context with
RAW tag 1; x30's word remains zero and its tag becomes RETURN tag 10. The same
actual table pointers lead to these updated cells; other GPR data, four flags,
LR zero, all 64 vector words, both cold caches and `_ctx` remain derived.

The pure suffix appends no provider visits or events. All 98 actual provider
traces remain ordered, and the original 204-frontier globals retain contents
and both permission maps. Allocation access and nextblock remain. Actual
world/Senv, full post-memory and provider availability/ABI premises remain
explicit. A represented context may be a pointer or a 64-bit word; no Vlong
inference, physical-address binding or dereference permission is inferred
from a scalar tag or from program initialization.

Actual header/RAW/register Storage/caller transport and native/provider
admission, relative cache/materialization, physical memory/alias/origin,
source control and all-family O1/O2/O4 recount remain M5. Complete ISA-handler/
family count stays 0; M6 follows M5. No C/runtime, benchmark, paper/design,
kernel, base or image change is made here.

Validation and retained attempts are in validation.json. Raw data:
/workspaces/kprog-raw/formal/m5-numeric-producer-context. One-worker builds use
CPU 17, reads/queries/Git use CPU 16; every host command holds timing SH,
with 32 GiB address space and normal 200000 heartbeats / 512 recursion limits.
No new trusted axioms or increased proof limits are introduced.

Final result: focused attempts are retained in validation.json. Full Lake
passes 329 jobs once at the end and all 11 public type/axiom queries pass;
the 10 Arm64 exports remain byte-identical to 9c617740f. The full comparison
records 12 changed x86 exports from PERF’s typed LOCK boundary
and exits 1; that result is retained explicitly. Atomic correspondence
remains open. Current total export size is 243488732 bytes. Queried
laws use standard axioms and the existing Clight external-function/assembly
parameters. Native make check is due at final goal confirmation
(last whole pass 5236c0e9677f635526fdd515cde5195b2ba0810c).
