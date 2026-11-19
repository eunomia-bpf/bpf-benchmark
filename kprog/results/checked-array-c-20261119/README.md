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
