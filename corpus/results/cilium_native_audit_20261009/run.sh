#!/bin/bash
D=/workspaces/.agent-state/bpf-benchmark-supervisor/cilium-rerun-20261009
cd /workspaces/repository
n=$(ls $D/run*.log 2>/dev/null | wc -l)
rm -f $D/exit
if [ "$n" -gt 0 ]; then extra="

Continuation note: an earlier run of this task was killed by a container restart. Check git status and git log in /workspaces/repository, keep the correct partial work, and continue."; else extra=""; fi
{ cat $D/prompt.md; printf '%s\n' "$extra"; } | codex exec --skip-git-repo-check -o $D/last.md - > $D/run.$n.log 2>&1
echo $? > $D/exit
