# kprog paper push: three lanes in bpf-benchmark-dev, split by CPU

- Date: 2026-11-06 (UTC; the operator's 2026-11-05 evening in America/Los_Angeles)
- Scope: `services/agent-duties/duties.yaml` (prompt of `bpf-benchmark-supervisor`); two Codex lane loops inside Workspace `yunwei356/bpf-benchmark-dev` under `/workspaces/.agent-state/kprog-lanes/`
- Status: deployed

## User request and approval

The operator asked how to run several tracks in parallel so that the kprog
paper becomes submittable, on which machine the Workspace runs, and whether it
should be ready within three days:

> “怎样多路并行去把这个做成能投稿的? 我们的 workspace 在什么机器上? 应该是 3 天内准备好?”

Claude proposed three lanes in the one Workspace, split by CPU, with Claude
alone editing the paper. The operator pasted that plan back and said:

> “确保继续做”

## Defaults and decisions

| ID | Setting | Current value | New value | Reason | Risk | Decision |
| --- | --- | --- | --- | --- | --- | --- |
| BPF-5 | `bpf-benchmark-supervisor` prompt | Reproduce the early numbers, then continue the proof goal | Same, plus: read the lanes' `COORDINATION.md`, time only on host CPUs 0-7, and after the reproduction run the timing requests the other lanes list | Valid timing while two more lanes run guests on the same host | Lane R's queue grows | Approved by "确保继续做" |
| BPF-6 | Lane C, application coverage | none | Codex loop (`kprog-lanes/lane-loop.sh C`) in the Workspace, host CPUs 8-15, guests at most 16 GiB | Measure and raise how many programs of the six corpus applications pass the kprog path | Shares the tree and the host with R and F | Approved by "确保继续做" |
| BPF-7 | Lane F, fidelity and safety evidence | none | Codex loop (`kprog-lanes/lane-loop.sh F`), host CPUs 16-23, guests at most 16 GiB | Differential test against the real CPU, negative suite, load-time breakdown, helper/map on the bound path, TCB counts | As above | Approved by "确保继续做" |

Both Codex lanes use the cluster-wide shared Codex login (yunwei356, the order
recorded in `2026-11-04-cluster-codex-login-yunwei356-priority.md`). No new
Workspace, Kubernetes object, login copy or schedule is added.

## Evidence and implementation

The Workspace runs on `lab` (Intel Core Ultra 9 285K: 8 P-cores and 16
E-cores, 125 GiB, `/dev/kvm`). Its `/workspaces` volume had 40 GB free (85%).
Codex CLI 0.166.0 in the Workspace answered a one-word `codex exec` with
`gpt-6.1-sol`. `vng` pins only one guest at a time, so lanes C and F confine
their guests with `taskset` instead.

The lane loop restarts a turn when the previous one ends. It resumes the lane's
session by id and stops on a `STOP` file. Each lane's task is in its
`prompt.md` and `cont.md`, and the shared CPU, memory, commit and disk notes
are in `COORDINATION.md`. Lanes C and F started at about 06:50 UTC.

## Validation and rollback

Validation: `turns.log` in each lane directory records completed turns, and
`codex exec` processes are present. The live CronJob carries the new prompt
after Flux applies the commit.

Rollback: `touch /workspaces/.agent-state/kprog-lanes/{C,F}/STOP` stops the
lanes after their current turn, or kill the loop and `codex exec` processes.
Restore the previous duty prompt with a forward-only commit.
