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
