# Shared working-tree publication, 2026-11-09

Lane S19 records the shared-tree cleanup requested by the operator. The live entry snapshot contains **3,712 status paths**: 3,386 untracked, 248 staged deletions, 59 working-tree modifications and 19 mixed index/worktree modifications. All 248 deletion-marked files existed on disk when checked; concurrent lane publication subsequently advanced the index. Counts describe their capture instants.

| Path group | Entry paths | Final paths | Disposition |
| --- | ---: | ---: | --- |
| Other corpus results | 1131 | 48 | active owner or standing submodule state |
| Current x86 application results | 270 | 16 | active owner or standing submodule state |
| Current ARM application results | 129 | 22 | active owner or standing submodule state |
| Other tracked source, results, submodules and core | 35 | 16 | active owner or standing submodule state |
| x86 source | 46 | 44 | active owner or standing submodule state |
| Cilium identity cache | 1242 | 0 | published and preserved |
| Fidelity replay output | 772 | 0 | published and preserved |
| Micro results | 54 | 0 | published and preserved |
| Test results | 33 | 0 | published and preserved |

Raw preservation root: `/var/tmp/kprog-tmp/S19/`. The entry status, active-process evidence, queued-input references and move receipts reside there. A moved file retains its content and receives a SHA-256 receipt. Recent files and active inputs stay with their owners. C retains the generated x86 micro sources and selftest launcher; V retains the formal-source backlog. Exact source paths are posted in the coordination notices. Vendor and paper submodule state remains with its existing owners.

cilium-cache: 1242 raw paths (6914669 bytes) preserved in 1 closed groups; status 3284 ? 2044. Per-file content hashes and destinations: `cilium-cache-moves.json.gz`. Deferred units: 0.

fidelity-replay: 403 raw paths (358010035 bytes) preserved in 17 closed groups; status 2042 ? 1641. Per-file content hashes and destinations: `fidelity-replay-moves.json.gz`. Deferred units: 0.

corpus-runs: 405 raw paths (3978314 bytes) preserved in 103 closed groups; status 1639 ? 1236. Per-file content hashes and destinations: `corpus-runs-moves.json.gz`. Deferred units: 0.

micro-test-core: 88 raw paths (26811853 bytes) preserved in 38 closed groups; status 1234 ? 1148. Per-file content hashes and destinations: `micro-test-core-moves.json.gz`. Deferred units: 0.

replay-input-extras: 368 raw paths (1223979923 bytes) preserved in 11 closed groups; status 1162 ? 796. Per-file content hashes and destinations: `replay-input-extras-moves.json.gz`. Deferred units: 0.

historical-corpus-runs: 631 raw paths (9420167 bytes) preserved in 154 closed groups; status 797 ? 168. Per-file content hashes and destinations: `historical-corpus-runs-moves.json.gz`. Deferred units: 0.

older-probe-output: 15 raw paths (1269641 bytes) preserved in 5 closed groups; status 166 ? 153. Per-file content hashes and destinations: `older-probe-output-moves.json.gz`. Deferred units: 0.

Application result publication: six existing coverage/log files for the closed x86 Cilium matched-module, Cilium owned-skb and OTel host-compile continuation cohorts are retained at their original result paths. Each coverage JSON parses, and each compressed driver log expands. Their actual startup and compiler outcomes remain in the raw records.

Historical replay captures: four tracked output paths retain their published Git capture. Their subsequent replay bytes and the corresponding Tetragon runtime are published in `historical-replay-overwrites.tar.gz`, with hash correspondence in `historical-replay-overwrites.json`. The BCC replay summary and runtime also match the committed `bcc-execution-queued/startup-libaio` capture. The ARM input archive has identical member contents across both gzip wrappers. The selftest replay records 315 resource failures at the bpffs setup stage; its complete raw table is retained in the archive. The older controllers record terminal states.

closed-broker-runs: 9 raw paths (94953 bytes) preserved in 6 closed groups; status 142 ? 135. Per-file content hashes and destinations: `closed-broker-runs-moves.json.gz`. Deferred units: 2.

completed-arm-replay: 1 raw paths (3124 bytes) preserved in 1 closed groups; status 143 ? 144. Per-file content hashes and destinations: `completed-arm-replay-moves.json.gz`. Deferred units: 0.

Final capture: **146 status records**, compared with **3,712** at entry. The retained records comprise 50 C-owned source/fixture paths, 4 standing paper/vendor submodule paths and 92 current lane records protected by recent writes or live ownership. Exact paths and reasons: `remaining-paths.json.gz`. Concurrent publication advances index records during the cleanup; both capture instants remain explicit.

Preservation total: **3162 moved files, 1630482679 bytes**. Every destination matched its move receipt; the complete 3,161-file batch also passed an independent SHA-256 reread, followed by the final completed ARM replay receipt. Four tracked replay overwrites have their original bytes retained in the published replay archive. Six authored application result/log paths were published in place.

Publication commits before this final ledger:

- `f1ff8e17b260b03ee87598bd44ea0be7259cec86` Record the shared-tree cleanup inventory and source ownership
- `c2c6fb52fab7125e604dce295b7b2ac517d4ac12` Preserve closed cilium-cache output with content receipts
- `86c8ea7f47e67388d2c4d4acb37fe6d9f54beea3` Preserve closed fidelity-replay output with content receipts
- `e10f331091d224b89beafef7ee354cf086f292ce` Preserve closed corpus-runs output with content receipts
- `5e1ef9b65ef01dccaba0137047fab4389d593808` Preserve closed micro-test-core output with content receipts
- `3f1679d55d2132788b2ec355f624e08c7cf03ee0` Preserve closed replay-input-extras output with content receipts
- `1c464d096c8984c2d46b96d7da1c6ca2f23c1e3b` Preserve closed historical-corpus-runs output with content receipts
- `b7ba7c8d52a949ea9679b3721000d4c93f7c03f6` Preserve closed older-probe-output output with content receipts
- `e2f1cd561baa9bf3870fe4ae20670f2c221cf8c4` Publish retained application coverage and driver outcomes
- `0a8fc858ff75c22d0eb9150dd4d69dcd41f547e2` Publish retained application coverage and driver outcomes
- `5f2bfa74c7bd512441585bee72eae198a8cb05b3` Preserve closed closed-broker-runs output with content receipts
- `248588384aa58a7b6f629cd9246f24ba4872fcd3` Preserve closed completed-arm-replay output with content receipts

Verification covers file preservation, archive member correspondence, JSON/gzip readability, path-scoped diff checks, pushed ancestry and the exact published path set. The cleanup changes result storage and Git ignore patterns. Simulator, loader, kernel, formal semantics, frozen workloads and paper/vendor gitlinks retain their existing owners. C retains 43 generated micro source edits, the historical selftest launcher and the six-file intrinsic-control source group; current C/A/V/S18/R work continues under its existing scope.
