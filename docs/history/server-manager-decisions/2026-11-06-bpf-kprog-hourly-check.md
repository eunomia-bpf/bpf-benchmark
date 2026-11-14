# kprog hourly check, R redirected to the reproduction, Workspace disk freed

- Date: 2026-11-06 (UTC)
- Scope: Workspace `yunwei356/bpf-benchmark-dev` (skill `/workspaces/.agent-state/claude/skills/kprog-hourly-check/`, lane loop and lanes F, C, T under `/workspaces/.agent-state/kprog-lanes/`, old work directories under `/workspaces/.agent-state/bpf-benchmark-supervisor/`); CronJob `agent-duties/bpf-benchmark-supervisor` prompt
- Status: deployed

## User request and approval

> “你也要设计每小时监控, 用中文给我汇报结果, 并且盯着去做.”

## Defaults and decisions

| ID | Setting | Current value | New value | Reason | Risk | Decision |
| --- | --- | --- | --- | --- | --- | --- |
| BPF-13 | Coordinator check | Every two hours: liveness and restart only | Hourly, following the Workspace skill `kprog-hourly-check`: `check.sh` (restart dead loops, receipts of the hour, resources, Codex quota), `audit.sh` (agent paper edits, "won't do" wording, generator lines that pass without matching native execution, `kprog/formal` edits outside V, timing outside R or CPUs 0-7, circling), one progress number per lane in `hourly/metrics.tsv`, paper integration of finished results, a Chinese report | Operator words above | A session-only local cron; it stops with the coordinator session | Approved by the quote above |
| BPF-14 | R duty prompt | Tells R to remove the paper checks from the formal gate | That sentence removed: lane V owns `kprog/formal` and already removed the paper, count and claims checkers; the five Codex lanes are named | R spent from 06:10 to 08:27 UTC profiling and restoring `check_lean_claims.py` that V had deleted, and had not started the reproduction | none | Approved by “并且盯着去做” |
| BPF-15 | Lane loop | Resumes the same session forever; a fresh session gets `cont.md` | Two failed turns in a row on the OpenAI content flag start a fresh session from `prompt.md`; a fresh session always gets `prompt.md` | F failed three turns in a row with “This content was flagged for possible cybersecurity risk” | Context of the old session is lost; the lane's state is in commits and results | Approved by “并且盯着去做” |
| BPF-17 | R duty prompt, corpus native arm | Says "native/eBPF" without naming the arm | Names the native-loader knobs (`BPFREJIT_SHIM_NATIVE_LOADER=post`, manifest, `BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF=1` for the verified arm); says `noop`/`dce`/`kinsn` pass runs are eBPF and not native; no coverage boundary, `shl esi` was a fixed checker bug | From 11:21 to 13:23 UTC R reported a `noop` eBPF-against-eBPF run as "native/eBPF 1.008x" and then started a 40-minute full-recipe `noop` run on the 64 GiB timing guest, after notices in `COORDINATION.md` from lane T, lane C and me | none | Approved by “并且盯着去做” |
| BPF-16 | Workspace disk | 96% used, 13 GB free | 83% used, 45 GB free | Lanes write GB-sized compile records and kernel trees | Removed only clean worktrees whose HEAD is on origin/master and one kernel build output | Approved by “并且盯着去做” |

## Evidence and implementation

Disk: removed the git worktrees `revert-native-decide` (f6ffe40e9),
`katran-compare-wt` (73c2ad809, its one ignored file `output.md` copied to
the main checkout's results directory first) and
`op-compare-20261007/{baseline,current,current-final}` (69f9a30f6,
f49c60b84, f6ffe40e9). Each was clean and its HEAD is contained in
origin/master. Also removed `kinsn-series-build`, the kernel build output
generated from `kinsn-series-20261005`. Not touched:
`cilium-lab-20261009/paper-tree` (the 2026-05-29 recipe tree R needs),
`bpf-next-rfc`, `kfunc-copy-v2*` and lane result directories.

Lanes: F's session id moved to `sid.<ts>` and F restarted from its prompt
plus a pointer to its commits and results. C was told that item 2b
(bounded indirect dispatch on x86-64) is still to be implemented after the
fuel-based dispatch was removed. T was told that C and A are blocked on app
proof lookup and linking and on call/map-capable proof regions, which the
six-application verified path needs. Both messages take effect at the
lane's next turn.

Restart caused while stopping R, 08:34 UTC: R's 08:32 retry of Job
`bpf-benchmark-supervisor-29899090` (created 06:10, before Flux applied the
new prompt) still ran the old prompt. While ending it, I killed the
grandparent of the first `pgrep -f` match. That match was the runner's
`bash -s`, so the grandparent was the Coder agent. The agent shut down and
the Workspace container restarted; the pod shows reason OOMKilled with exit
code 0 at 08:34:00. Every lane loop, guest, compile queue and kernel build
stopped. `/workspaces` was intact, with no git lock and Codex still logged in.
At 08:41 the five lanes were restarted. Each got a message saying what
stopped, asking it to restart its queues from its checkpoints. Job
29899090 could still retry with the old prompt (6 failures, backoffLimit 6),
so it was annotated with this record and deleted. The CronJob then created
Job 29899240, and its OMP process carries the new prompt (checked in its
argv at 08:42). The hourly skill now says to kill exact pids only.

OOM restart, 12:15:16 UTC: the Workspace container was OOM-killed (exit
137; the pod has no memory request or limit on the 125 GiB host). At that
time lane R's corpus guest (`VM_MEM.kvm-x86 := 64G`) was running together
with three full `make -C kprog/formal check` builds and the C/A compile
queues. The 12:23 hourly check restarted the five lane loops. R's Job
29899240 still showed Running although its OMP process had died with the
container, so the CronJob (concurrencyPolicy Forbid) would not start
another. It was annotated with this record and deleted; Job 29899460
started R again, and its argv was checked for the new prompt. A memory
split was added to `COORDINATION.md`: R keeps its 64 GiB guest, only one
full formal check runs at a time, and the Codex lanes stay together under
about 48 GiB. Each lane got a message about the restart.

R prompt change, 13:25-13:40 UTC (BPF-17): the first commit (79fbad07)
put `: ` inside the unquoted args scalar and the agent-duties kustomization
failed to build for about three minutes; f13c7c57 fixed it and Flux applied
it. R's `noop` corpus run was then ended by exact pids (sh/make corpus, its
64 GiB guest, the two omp processes). Job 29899460, created before the
change, retried its trigger and started a new run with the old prompt at
13:27, so it was annotated with this record and deleted and that run was
ended by exact pids. The replacement Job 29899530 exited `already_active`
while the lock was still held; the 13:40 schedule starts R with the new
prompt.

## Validation and rollback

Validation: the first hourly check ran at 08:27 UTC; the CronJob shows the
new prompt after Flux applies it, and R's next run starts the reproduction.

Rollback: revert this commit for the prompt. For the lane loop, remove the
`flagged` block and the `[ -n "$SID" ]` condition on `cont.md` from
`lane-loop.sh`; running loops keep the code they started with until
restarted. Removed worktrees can
be recreated with `git worktree add <path> <commit>`; the kernel build output
is rebuilt with `make -C kinsn-series-20261005 O=...`.
