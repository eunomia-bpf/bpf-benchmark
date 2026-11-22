# Selected source and fetched native CSEL agree at the writer boundary

selected_writer_matches composes the original 66-transition selected Clight
branch with the actual fetched native CSEL64 step. The source condition is
bound to LNSym ConditionHolds; the chosen source's raw value, full tag and
materialized native word come from the existing complete register relation.
Both possible sources, all ordinary registers and all four-bit conditions are
covered. The call reaches the genuine linked pointer writer with that exact
raw/tag pair, unchanged memory and actual caller continuation/temp map.
The native step identifies the corresponding tagged physical register update,
PC+4, empty event delta and no fault. No writer post-memory is assumed.

This closes the selected-operand match at the call boundary. It does not execute
the source writer, establish arbitrary source condition computation, derive
generic entry/dispatch from all input arguments, free its frame or return to
the original seventh source call. Those remain explicit M5 obligations, along
with the complete handlers, physical memory/ABI, O1/O2/O4 and M6. No ISA family
is reported complete.

Focused258 and one public type/axiom query pass at original limits, CPU17/nice0,
one worker and32GiB address space. Only standard logic and inherited external/
assembly relations appear. Batch-end default `lake build` passes all 478 jobs; fourteen root type/axiom queries also pass.
Raw: /workspaces/kprog-raw/formal/m5-select-branch/20261122T105431Z.
