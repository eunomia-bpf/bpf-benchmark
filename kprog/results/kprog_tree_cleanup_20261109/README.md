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
