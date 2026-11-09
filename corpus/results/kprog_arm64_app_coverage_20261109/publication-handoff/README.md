ARM active-run publication handoff

The operator 2026-11-09 instruction uses git commit -F <msg> -- <paths> for each step. A publication helper now keeps its private index/message under /var/tmp/kprog-tmp/A/publication and uses that path-scoped command plus normal push. The shared source tree remains master.

The two existing Make/QEMU children retain their exact live source, guest and runtime state. Their original terminal-only parent collectors are suspended while replacement collectors wait on the exact Make pidfd, read its retained kernel wait status and run the original terminal collection/cleanup bodies with the updated publication helper. After published closure each replacement retires its suspended original collector. Original controller recipes and live QEMU processes remain preserved through this handoff. Receipts identify every original parent, Make child and replacement collector.

Existing read-only guest exports stay attached through their current lifetimes; following run/build/cache outputs use /var/tmp/kprog-tmp/A. Project implementation edits take place in /workspaces/repository on master. Runtime model changes:0; admission additions:0.
