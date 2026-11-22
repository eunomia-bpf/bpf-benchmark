# EQ CSEL condition through actual writeback

Work in progress: the source below is prepared; its focused build and public
queries are pending. No completed refinement is claimed by this receipt.

The actual four flag-pointer loads, EQ condition helper, caller normalization
and path helper now compose with the original selected raw/tag reads, real
pointer writer and caller resume: 66 + 120 = 186 silent transitions. The
selected direction follows the same pre-state NZCV relation and LNSym's actual
ConditionHolds; no taken temporary, helper result, store success or post-memory
is supplied independently. Any ordinary source/destination, either source,
all provenance bits and explicitly represented Vptr values are retained.

The result relates the actual final heap and complete register observations
to the fetched native CSEL64, with PC+4, empty event delta and no fault. Source
condition zero, opcode28 and width8 are explicit. Generic dispatch, frame
allocation/release and the original seventh source-call/prefix composition are
still required. No complete ISA family, O1/O2/O4 or M5/M6 completion is claimed.

Raw: /workspaces/kprog-raw/formal/m5-pointer-values/20261122T110830Z.
