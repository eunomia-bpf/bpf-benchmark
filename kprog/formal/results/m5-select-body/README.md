# Original CSEL64 EQ handler body

Body.execute composes actual width-helper and dispatch execution, the original
EQ condition/path calls, selected raw/tag reads, actual writer stores, caller
resume and the real enclosing loop exit. It starts at the original handler
fn_body and reaches Sskip with its original continuation and environment.

Source selection follows the same native NZCV relation; both source choices,
all ordinary registers, all tag bits and explicitly bound Vptr values are
covered. The final full-register relation is to the actual fetched LNSym step
state, including PC advancement through the existing cursor law, empty event
delta and no fault. Actual cache observations and storage/readback follow from
the same result. No helper return, store success or post-memory is postulated.

The generic function's frame remains live. Actual allocation/free, the original
seventh call and complete program prefix remain open, together with remaining
instruction forms, physical memory/ABI, O1/O2/O4, M5 and M6. No ISA family is
reported complete.

Raw: /workspaces/kprog-raw/formal/m5-pointer-values/20261122T110830Z.

Focused263 and one public type/axiom query pass at original limits, CPU17,
one worker and32GiB, under the shared timing lock. Full confirmation follows.
