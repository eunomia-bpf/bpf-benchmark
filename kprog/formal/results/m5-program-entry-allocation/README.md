# Actual Arm64 program entry allocation

The real production-macro export and the extracted RAW producer allocate the
same memory for every incoming memory. Every local binding retains its actual
block, with the entry-view name and two anonymous composite tags mapped between
source units. This derives the production locals' freshness and full Freeable
ranges from the imported allocator, without an assumed allocation outcome.

The kernel compares the complete declaration lists and the vector, stack and
entry-header composite records, including member order/types, attributes, size,
alignment and rank. The allocator correspondence is an induction over the real
declarations and preserves all environment lookups under an injective name swap.
No C source, provider visit, runtime input or allocation is added.

Focused validation passes 147 jobs. One full Lake build passes 338 jobs;
six public type/axiom queries pass. The initial focused attempt found a lookup
orientation error, a list-member substitution issue and excessive elaboration
of a concrete composite environment. Generic environment parameters fixed the
latter at unchanged proof limits; all failed attempts remain raw.

All ten Arm64 exports retain their byte baseline at 9c617740f. Historical
comparison correctly exits 1 for 12 other x86 exports; exact files and
byte totals are in validation.json. No new source export was introduced.

This closes only the declaration/allocation part of source factoring. Temporary,
expression and statement correspondence, actual prefix execution, genuine
one-pointer/uint32 continuation binding, native/provider/context admission and
remaining handler families stay open. Completed ISA-family count is zero.
M5 precedes M6. Fresh final lake build and make check remain due at goal closure.

Raw logs: /workspaces/kprog-raw/formal/m5-program-entry-allocation
Public queries: Query.lean. Structured results: validation.json.
