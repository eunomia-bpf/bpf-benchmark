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

2026-11-17T23:29:24Z — Source `9cf2726e0` and reader `a806bedfe` completed. The original regression fails (exit 101); the new solver passes all 60 tests with four existing opt-in tests, and all 649 unrelated fixture/metadata files match the preceding tail build. The production unit entry emits all 295 actual captured requests (exit 0). The live canonical CLI keeps its size/mtime 2978744 / 1794948232; base and image remain the checked guest's version.

| App | Requests emitted | Neutral bytes before | Neutral bytes after | Changed payloads | Additional named facts |
| --- | ---: | ---: | ---: | ---: | ---: |
| BCC | 25 | 11028 | 11028 | 0 | 0 |
| Cilium | 47 | 178766 | 178766 | 0 | 0 |
| Katran | 1 | 9241 | 9241 | 0 | 0 |
| OTel | 14 | 130320 | 129734 | 2 | 4 |
| Tetragon | 39 | 284403 | 284119 | 12 | 23 |
| Tracee | 169 | 1744902 | 1744643 | 3 | 165 |

There are 111 added lookup identities, one update identity and 80 push/pop identities. The existing emitter consumes the lookup/update facts it supports; a newly named fact alone measures analysis coverage. Every old identity remains, and helper-site keys, map-patch name multisets, callee-saved masks and four-byte tail-counter-slot observations match in every request. Six requests change external helper-target multisets. Full per-site names, offsets, target deltas and statuses are in comparison.json.

OTel's metrics per-CPU ARRAY gains four facts across perf_unwind_v8 and perf_unwind_dotnet, with each image 293 B smaller and its generic lookup fallback removed. Tetragon execve_map_update binds execve_map's existing raw HASH target and shrinks 284 B. Eleven Tetragon substring-map programs change ARRAY instruction bytes at equal size. Tracee lkm_seeker_new_mod_only_tail shrinks 284 B; lkm_seeker_proc_tail adds 4 B while binding 33 modules_map HASH calls, and uprobe_syscall_table_check adds 21 B while binding 50 ARRAY calls. Both growth cases stay in the report. Total neutral payload reduction is 1129 B.

The existing typed map lowering supplies bounds, NULL, value conversion, LRU and per-CPU work. This change carries existing named identities through agreeing paths and adds zero runtime instructions by itself. Katran's remaining inner/mixed-map sites keep their previous treatment. App per-call, throughput, body/helpers/maps and installed native/JIT bytes remain the next image-batch measurements, under Omp's scheduling with all LTO on. The source, raw before/after failure/success logs, and all requests remain available under /workspaces/kprog-raw/perf/map-provenance-cfg-20261117/host-20261117T232351Z-2807862.
