# Exact-shape entry cost

The smallest diagnostic compares the current retained native trie body with
the same body entered at its query-prefix read. A host-only initial JMP
skips the ARRAY/LPM type and data-size guards for the exact LPM12 fixtures.
The query bound, child-selection guard, flags and fallback code stay.
All original body bytes, explicit entry patch and actual layout remain
recorded. The extra JMP adds cost to the known entry.

The unchanged existing C driver checks expected pointers and times three
query shapes with alternating arm order. Its raw labels kernel/native map
to guarded-native/known-entry in input.json and the result reader. The two
function arguments are the retained native body and its host entry patch;
both arms measure native code. The read-only input and sole driver remain
at their existing paths. The wrapper uses timing SH/image SH, CPU19 and
4GiB AS, with raw output under /workspaces/kprog-raw/perf/lpm-body-20261118.

This establishes helper entry cost. Actual named-lpm12 load selection,
source routing, installed bytes and app per-call/body/helpers/maps/throughput
remain the production implementation and omp's frozen all-LTO batch.

Forward diagnostic: the first run uses the extra entry JMP and retains its
raw input and samples. The next run slices the body at the existing query
load so the driver calls it directly. The remaining internal branches and
fallback trap lie inside that slice and retain their relative displacements;
the full pointer-reference checks execute it. The removed prefix is recorded
as raw bytes. Code alignment changes with this entry, and both series stay
available when judging the guard-cost effect.
