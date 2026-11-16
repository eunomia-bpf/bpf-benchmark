Known lookup targets, 2026-11-16

OTel's PMU profile identifies inline LPM and the ARRAY dispatch chain as large
costs. The native selector discarded complete named `call` targets, including
ARRAY_OF_MAPS and LRU_PERCPU_HASH. The loader also left known LPM maps at the
generic helper. Keep all complete named facts and select trie_lookup_elem from
the loaded LPM type, matching the sole kernel's map operation. Actual unknown
map arguments retain their dynamic semantics. No per-call check is added.

The existing named-map regression now covers call targets as well as inline
and raw-hash forms, and its ELF integration case checks that generic ARRAY
sharing leaves the named target intact. The result Makefile builds the one
linker and loader in place and replays retained Katran and OTel plans with
generic versus bound call facts. These are host payload bytes, not installed
bytes or runtime gains. OTel's extra LPM fact is source-derived and uses a
same-kernel symbol delta; actual loader capture remains a guest measurement.

Image 6641a7e1 remains in use for C's baseline round. Installed bytes, per-call
time and the body/helper/map split after publication remain open. The PMU
baseline and its attribution limits are in ../otel-regression-20261116/.


Host subset passes: 49 linker tests, zero failures, three existing ignored;
production linker and loader builds pass. Controller 1858500 finished with
exit 0 at 19:35:41Z. OTel sampling-entry replay shrinks 8,001 to 7,604 payload
bytes by removing the 67-byte ARRAY dispatcher and 330-byte LPM routine; its
last generic lookup relocation disappears. Katran remains 10,528 bytes because
its genuine dynamic inner lookups still need the dispatchers, while two outer
lookups now bind to their supplied operation. The two additional bound call
relocations replace local dispatcher calls. No per-call gain is claimed.

The first make -n preflight exposed recursive Make redirection before RAW
existed. The real controller creates RAW and passed; no benchmark input changed.
The dominant native unwinder has jump tables, which currently erase all named
map facts in that function. Recovering facts using the already-resolved table
destinations is the next source subset; targets must clear facts at each join.


The next source subset shares the helper analysis's already-resolved branch
destinations with map provenance. It clears map identities at each destination
and keeps the old generic behavior for unresolved indirect jumps. Regression
edges target block starts and calls that bypass either load, preventing facts
from leaking across those joins. The host replay now also includes retained
OTel V8. Each attempt uses a distinct raw output directory.


Resolved-table subset result: source e8960af11 passes 50 linker tests, zero
failures and three existing ignored tests. Linker and loader builds pass;
controller 1861331 finished 19:39:44Z, exit 0. Host fact variants give Katran
10,528 / 10,528 B, OTel entry 8,001 / 7,604 B, and V8 37,512 / 37,115 B.
The 397-byte reductions measure dispatch removal in these replays, not the
separate gain from recovering map facts across switch tables.

The hot perf_unwind_native lacks a kernel-link plan in the earlier replay
inventory because B generation stopped first. Its actual load facts do exist
in service/requests/3.success.tar.gz inside
/workspaces/kprog-raw/perf/20261116-checked-six-apps/otelcol-ebpf-profiler/service.tar.gz:
request/kernel.metadata.json binds names to actual map IDs and shapes;
request/kernel.facts.json and generation.metadata.json also retain inner-map
shapes. Use these for the next host replay. Source bsearch_step
(native_stack_trace.ebpf.c:121-134) repeatedly looks up a dynamic inner ARRAY.
That is separate from recovering named-map facts: treating the inner pointer
as a particular named map remains unsound. The captured outer HASH_OF_MAPS
inner ARRAY shapes can support the remaining map-return dataflow work.
