# Shared working-tree publication, 2026-11-09

Lane S19 records the shared-tree cleanup requested by the operator. The live entry snapshot contains **3,712 status paths**: 3,386 untracked, 248 staged deletions, 59 working-tree modifications and 19 mixed index/worktree modifications. All 248 deletion-marked files existed on disk when checked; concurrent lane publication subsequently advanced the index. Counts describe their capture instants.

| Path group | Entry paths | Final paths | Disposition |
| --- | ---: | ---: | --- |
| Other corpus results | 1131 | pending | inventory captured |
| Current x86 application results | 270 | pending | inventory captured |
| Current ARM application results | 129 | pending | inventory captured |
| Other tracked source, results, submodules and core | 35 | pending | inventory captured |
| x86 source | 46 | pending | inventory captured |
| Cilium identity cache | 1242 | pending | inventory captured |
| Fidelity replay output | 772 | pending | inventory captured |
| Micro results | 54 | pending | inventory captured |
| Test results | 33 | pending | inventory captured |

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
