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

2026-11-18T01:52:01Z — Both workers2860445 and2861239 ended0, and both
pass the eight reference groups including4,096 deep queries. The first
extra-JMP medians give guarded/known0.969(full),1.082(miss),1.009(deep).
The direct slice gives1.506(full),1.113(miss),1.032(deep). Its full-hit
known values are2.715/2.665/2.952ns versus guarded4.148/4.090/4.090ns;
deep known106.384/105.850/114.497ns versus109.756/109.094/115.174ns.
All original series, labels, inputs and patches/slices stay in the two JSON
files and raw paths. These host costs motivate preserving exact-map entry
identity through the existing linker, with one shared body for mixed calls
and guards omitted when every caller has that loaded shape. App installed
size and speed remain the frozen all-LTO batch measurement.

2026-11-18T01:59:08Z — Production host validation completes. Exact loaded LPM12 calls
retain a LocalLpm patch through final source layout. Existing guarded and
exact callers enter one shared worker at their respective entry points.
An all-exact image emits the worker with type/data-size dispatch and the
generic helper fallback omitted. Query bounds, child selection, intermediate
flags, source lifetime and call/return behavior remain. Other shapes and
proof calls retain their existing target. The existing branch compactor
maps the known entry through relaxation.

All62 tests pass with four opt-in. The existing ELF binding fixture now
covers16 exact/type/layout/ARRAY combinations and executes eight named-map
hit/miss/prefix cases. Both existing shared-routine tests cover mixed
entries, checking their exact targets and single generic fallback. Existing
104,760 bit/prefix/flag and65,590 trie/guard/ABI vectors pass. The suite
retains62 tests; these are additions to existing regression cases.

Every one of295 original captures emits, and every blob/relocation/map/ABI
artifact set is byte-identical to source1baa33404. See legacy/compatibility.json
and its per-app summary. These plans retain the original call kind; actual
new-image lpm12 activation and installed bytes remain separate measurements.
The host direct-entry slice measured the entry-cost class before source
implementation, with full-hit1.506x and deep1.032x median guarded/known;
code alignment and the synthetic stable-node distribution remain explicit.
Production app per-call/body/helpers/maps/throughput effects stay open.

The change uses four open source files, including the visibility of existing
compact_at. Production adds one patch kind and an entry offset to existing
routine results, with compile-time guard selection. The same body serves
mixed callers, and all-exact callers emit the smaller worker. The existing
runtime guard set is selected by loaded shape, with zero new runtime check,
helper identity, configuration flag or refusal. Source net growth includes
mixed-entry and doubled binding fixture coverage; the implementation reuses
the current emitter/offset mapper and keeps one trie body per program.

Worker2862934 ended0 at01:55:16Z, raw:
/workspaces/kprog-raw/perf/lpm-body-20261118/candidate-20261118T015409Z-2862934. It used timing SH/image SH,
CPU19 and one Cargo worker/32GiB AS. The canonical CLI remains2,978,744B,
mtime1794948232. The two diagnostics and source worker are terminal, with
own leases free. Peer checked Tracee2754970 retains current CLI/base/image.
Omp's next frozen all-LTO image/check/affected-app batch records actual
loaded selection, native programs/errors, installed native/JIT bytes,
per-call BPF time, body/helpers/maps and throughput. Phase1 original-FD and
owned context-only helper binding remains the frozen-core owner handoff.
