# Keep agreeing named-map identities across native control flow

The smallest source change replaces basic-block clearing in the existing named
map analysis with a forward meet over the same decoded instructions and already
resolved branch destinations. Identity originates only at the existing named
GOT/absolute references; every reachable predecessor must agree by name. Unknown
entry inputs, mixed joins, caller clobbers, arithmetic, partial writes, memory
reloads and inner-map results remain unknown. Existing unresolved-indirect
behavior and error handling stay. No new runtime instruction/check, flag,
helper catalogue, pointer cache, benchmark or compiler-policy change.

This exposes additional sites to the existing named lookup/update/delete
lowering, which already implements map/NULL/LRU/per-CPU semantics. No kernel
hash body or new lowering is copied. The regression covers same/mixed joins,
loop fixed points and callee/caller register clobbers; existing indirect-table
and unsafe-pointer tests remain. The formerly negative zero-length conditional
join is safe and now belongs to the agreeing-join regression.

Committed one-shot recipe applies test, records baseline, applies source, runs
full tests/unrelated-byte comparison and all295 actual captured requests through
the production link(Args) unit entry. TimingSH/imageSH/CPU19/oneworker/AS32GiB;
canonical guest CLI stays untouched. Source and emitted gain are pending until
actual results; native helper bindings/bytes and call-site changes must be
reported before any per-call claim. Omp owns later image/check/target timing,
with all LTO on. Raw: /workspaces/kprog-raw/perf/map-provenance-cfg-20261117.

2026-11-17T23:25:24Z — Named map CFG source and full host tests completed; actual logs and source.patch committed. Raw: /workspaces/kprog-raw/perf/map-provenance-cfg-20261117/host-20261117T232351Z-2807862. Production unit-entry build and captured-request emission follow; canonical CLI stays unchanged; installed/time results remain pending.
