# BPF NativeSim duty no longer edits papers

- Date: 2026-11-05 (America/Los_Angeles); deployed 2026-11-06 UTC
- Scope: `services/agent-duties/duties.yaml`, prompt of `bpf-benchmark-supervisor`
- Status: deployed

## User request and approval

Asked whether to move the kprog duty back to proof and evaluation work and to
bring the paper back within a page limit, the operator answered:

> “改，给我草稿”

and, in the same conversation:

> “以后禁止 agent 改论文”

> “论文你去让 claude 的 subagent改写成正常的版本”

The second quote approves this change. The first asks for a draft of the wider
redirect, which is not part of this change. The third gives the paper rewrite to
a Claude subagent outside this duty.

## Defaults and decisions

| ID | Setting | Current value | New value | Reason | Risk | Decision |
| --- | --- | --- | --- | --- | --- | --- |
| BPF-3 | `bpf-benchmark-supervisor` prompt | Continue the NativeSim proof goal "including its paper" | Same goal without the paper; no change in `docs/kprog-simulator-in-ebpf`, `docs/paper` or `docs/ebpf27-bpfoptbench` and no bump of their submodule pointers; the formal gate stops reading paper text | Operator words above; the formal gate (`check_lean_claims.py`, `check_paper_counts.py`) reads the paper, so a rewritten paper would otherwise fail the gate and send the agent back into it | A pointer bump the agent used to do now waits for the paper's own owner | Approved by "以后禁止 agent 改论文" |

The schedule, Workspace, runner, retained OMP session, model and all other duty
rows are unchanged.

## Evidence and implementation

On 2026-11-06 05:54 UTC, the retained OMP session in
`yunwei356/bpf-benchmark-dev` was running and committing about 150 times a day.
The 431 project commits since 2026-11-03 01:00 UTC changed only ten files: six
Python checkers under `kprog/formal`, `kprog/formal/README.md`,
`docs/shared/implementation.md`, `.gitignore` and the paper submodule pointer.
The last Lean proof change was 2026-11-03 00:39 UTC. The last C simulator
change was 2026-11-01. The last benchmark run was 2026-10-12. During the same
period, the paper repository `yunwei37/kprog-simulator-in-ebpf` received 104
commits. Its compiled PDF reached 122 pages. `sections/4-safety.tex` alone holds
96,506 words, up from 45,400 on 2026-10-20.

The change edits only the prompt and the two admission annotations of this
duty row. The OMP run already in progress keeps the old prompt until it ends.
The next scheduled run carries the new prompt as a new user event in the same
session.

## Validation and rollback

Validation: the live CronJob carries the new prompt and annotations after Flux
applies the commit. After the next run starts, the paper repository gets no new
commit from the Workspace agent.

Rollback: a forward-only commit that restores the previous prompt in this same
duty row.
