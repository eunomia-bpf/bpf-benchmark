# kprog Codex lanes moved from the Workspace to the local Codex

- Date: 2026-11-06 (UTC)
- Scope: kprog lanes C, A, F, V and T. Their loops leave `/workspaces/.agent-state/kprog-lanes/<lane>/` in Workspace `yunwei356/bpf-benchmark-dev`, where each now has a STOP file. They run in the coordinator scratchpad `kl/<lane>/` on the operator's Windows machine.
- Status: deployed

## User request and approval

> “用本地的”

The operator chose this after being told that the move frees the cluster
Codex login and survives Workspace restarts. The cost is that the lanes now
depend on this machine staying awake and on its Tailscale, alongside the local
eBPFOS lanes. It also follows the 2026-11-04 order of use: new agent work runs
on the local Codex.

## Defaults and decisions

| ID | Setting | Before | After | Reason |
| --- | --- | --- | --- | --- |
| BPF-22 | Where lanes C, A, F, V, T run | `codex exec` inside the Workspace with the cluster login (yusen356 since 16:58) | Local Codex CLI (newest bundled `codex.exe`, gpt-6.1-sol, reasoning high) in `kl/codex-lane-loop.sh`, reaching the Workspace through `kl/bws.sh` | Operator words above |
| BPF-23 | Lane R | OMP duty in the Workspace | unchanged | The duty CronJob keeps the reproduction going when this machine sleeps |
| BPF-24 | Hourly check | Workspace `check.sh` only | Also `kl/check-local.sh` on this machine (SKILL step 1b), which restarts dead local loops | The lanes moved |

## Evidence and implementation

- **Stopping the Workspace lanes (about 20:01 UTC).** Each of the five
  Workspace lane directories got a STOP file. Their running `codex exec`
  turns and loops were ended by exact pids, and no `codex exec` was left
  afterwards. Uncommitted work stays in the shared worktree.
- **Starting the local lanes (20:02 UTC).** Each local lane got a new session.
  Its `prompt.md` starts with how to work: commands go through `sh kl/bws.sh
  <<'S' ... S`, it edits nothing locally outside its lane directory, it
  commits from a private index, and it first checks git status for its
  predecessor's uncommitted work. The task text follows unchanged.
- **Check.** All five loops were alive, and their first turns were reading the
  Workspace.
- **COORDINATION.md.** The Lanes table and a notice record the move.
- **Keep-awake.** The desktop app holds keep-awake while the session is
  active. It does not cover a closed lid or the idle gaps between hourly
  checks.

## Validation and rollback

Validation: `kl/check-local.sh` lists each loop as alive with growing turns.
The cluster login's weekly usage stops rising from these lanes.

Rollback: touch `kl/<lane>/STOP` locally, remove the Workspace STOP files and
start `lane-loop.sh <lane>` in the Workspace as before.
