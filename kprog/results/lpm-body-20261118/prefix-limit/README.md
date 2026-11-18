# Resolve the trie prefix limit before matching

The scope is the existing native trie loop in x86_lpm_lookup.rs. Its current
match length is `min(common, min(node, query))`. A match can use this node
exactly when `common >= node` and `query >= node`. The max-depth case has
node=query=common=96. For the twelve-byte data shape, allocation fixes the
trie's maximum prefix at96. These are the same kernel lookup conditions.

The smallest source change moves the existing query-prefix failure ahead of
matching, uses the node prefix as the remaining limit and compares the common
prefix directly. This removes two CMOVs and one MOV per visited node. The
comparison count drops from five to four. The layout/type guards, child
selection, fallback ABI, intermediate flags and current source-read policy
remain. The existing compact/wide exhaustive bit/prefix/flag tests, guarded
child walk and ancestor test cover the logical transformation.

Use the committed parent candidate.sh recipe under timing SH/image SH on CPU19,
with one Cargo worker and32GiB AS. It runs the full current suite, all295
captured requests and the same C body driver. The parent compare.py accepts
--before for the immediate prior source's replay; this step compares against
the bb8d5ed72 run at
/workspaces/kprog-raw/perf/lpm-body-20261118/candidate-20261118T011911Z-2847307/replay/replay.json.
All LTO stays enabled. Host results establish body cost and neutral bytes;
the actual app's installed code, per-call BPF time, body/helpers/maps and
throughput remain omp's frozen image/check/affected-app batch.

2026-11-18T01:30:10Z — Host2851937 finished0 at01:27:58Z. The full existing suite passes
62 tests with four opt-in, including34,920 bit/prefix/flag executions,
65,590 trie/guard/generic-ABI vectors and the named-shape execution cases.
The same C body driver passes its eight groups,4,096 deep queries and the
ancestor-value case. Every one of295 actual captured requests emits.
Helper targets, relocation-kind counts, map names, callee masks and
recovery-shape counts match in every pair; comparison.json retains each
request's status and observations.

All157 shared trie ranges shrink7B. The actual fused range is285→278B.
Neutral reductions by app: Cilium168B, Katran7B, OTel7B, Tetragon119B and
Tracee798B; BCC stays identical. The total is1,099B with zero growth cases.
These are captured payload sizes. The existing generic ranges activate in
these original plans; actual new-image named-lpm12 activation still needs
omp's loaded-shape capture.

| Query | Prior native ns | Prefix-limit native ns | Same-run kernel ns |
| --- | ---: | ---: | ---: |
| Full hit |4.096 /4.084 /4.084|4.085 /4.090 /4.083|4.602 /4.634 /4.608|
| First-bit miss |3.409 /3.406 /3.408|2.743 /2.744 /2.745|4.399 /4.396 /4.394|
| Deep hit |109.683 /110.042 /109.935|101.071 /101.173 /103.949|105.520 /103.945 /103.979|

The deep native median improves1.087x relative to the immediately preceding
source, and first-bit misses improve1.242x. The same-run compiled kernel
deep median is103.979ns versus native101.173ns. Every sample is retained.
These stable-node ordinary-return costs describe the helper bodies. Official
app per-call time, body/helpers/maps, throughput and installed native/JIT
bytes remain the next frozen all-LTO batch measurements.

The production edit is one existing file, +8/-7 lines. It replaces the
query-prefix portion of the existing mismatch condition with an earlier
exit and removes its now redundant minimum calculations. Comparison count
falls5→4 and each visited node saves two CMOVs and one MOV. Existing input
layout checks and generic fallback targets remain. The existing exhaustive
reference and multi-node ancestor tests cover the changed control flow;
the regression suite retains its current size.

Raw: /workspaces/kprog-raw/perf/lpm-body-20261118/candidate-20261118T012655Z-2851937. The same committed
candidate.sh/candidate.mk recipe supplies the sole Cargo unit artifact,
production link entry replay and original driver. It holds timing SH/image
SH on CPU19 with one worker and32GiB AS. The canonical CLI stays2,978,744B,
mtime1794948232; peer checked Tracee2754970 keeps its base/image/CLI lease.
All own workers and leases are terminal/free. Omp owns the image/check/app
batch once that lease finishes. The phase1 original-FD/context lifetime
handoff stays with the frozen-core owner.
