# C ARRAY helper in checked-sim-c LTO

The native compiler consumes the frontend IR that produced the checked B.
Trusted map facts select only direct, named ARRAY handles with no direct-value
offset. Selected calls bind to a C implementation of
kernel/bpf/arraymap.c:array_map_lookup_elem; the target kernel BTF supplies
max_entries, elem_size, index_mask and value offsets. The C definition and
lowered simulator IR are linked before native O3. Unknown/dynamic/non-ARRAY
calls retain the existing kernel helper binding. There is no runtime map-type
selector and no hand-written machine-code helper.

`run.sh` replaces the canonical checked compiler tools through checked-sim-stage
under timing SH/image EX, then uses the local Makefile to check numeric helper
selection, O3 call elimination, actual kernel BTF layout, ARRAY hit/miss indexes,
and retained generic/dynamic calls. Raw outputs stay under kprog-raw/perf.
This host check does not measure app per-call time or prove stock acceptance.
The native change runs after B verification; B generation remains unchanged.

PERF 2026-11-19T06:00:59Z: Host results completed under timing SH/image EX (build),
then timing SH/image SH (replays), CPU 19, 16 GiB AS. Raw: `/workspaces/kprog-raw/perf/checked-array-c-20261119/host-20261119T055222Z-193415`.
`checked-sim-stage` passes and replaces the sole compiler tools in place.
The executable passes 1,008 ARRAY boundary cases plus two retained generic calls.
The target BTF offsets are max_entries 68, elem_size 288, index_mask 292, value 304.
All 25 retained BCC frontends lower successfully with zero selected ARRAY calls
and 17 retained generic calls; BCC has no eligible ordinary ARRAY handle here.
OTel retained checked request 1 selects one `system_analysis` lookup. The real
production `compile_checked_simulator` API reuses the original B frontend,
links the C helper, emits native code and proof, and removes that helper call.
Both baseline and candidate proof links succeed: 1,542/7 versus 1,572/6 text
bytes/relocations. The live map symbol remains. These are proof text bytes,
not installed image bytes.

The attempted Tetragon replay exits 2: its first success archive contains a
direct-native fallback and no checked-simulator.bc. Its log is retained as
`tetragon-replay.log`; no Tetragon checked coverage is inferred. The OTel
replay explicitly selects request 1 as a host subset, not an application
exclusion. No B is regenerated and no stock/guest run is claimed.

Next batch targets OTel in checked-sim-c with all surviving LTO on. Per-call
body/helpers/maps, throughput and installed bytes remain unmeasured for this
change. The dispatcher-free C binding is a first helper class; it does not
claim the performance target or coverage of dynamic, per-CPU or hash lookups.
