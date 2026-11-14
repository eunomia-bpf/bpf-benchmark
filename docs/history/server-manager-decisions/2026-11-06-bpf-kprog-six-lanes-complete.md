# kprog push widened: six apps on the verified path, O1-O4 end to end, six lanes

- Date: 2026-11-06 (UTC)
- Scope: Codex lane loops inside Workspace `yunwei356/bpf-benchmark-dev` under `/workspaces/.agent-state/kprog-lanes/` (new lanes A, V, T; new tasks for C and F; `COORDINATION.md`)
- Status: deployed

## User request and approval

On reading the paper outline, the operator gave these directions:

> “要 merge 成 6个真实应用都有数据的, 并且都是经过验证的路径. 验证代码也需要整理.”

> “这里面都必须完整做完, 任何部分都不能有缺陷”

> “arm 后面可用 spark, 你先把模拟的跑通.”

> “不允许留下任何缺陷说不做.”

## Defaults and decisions

| ID | Setting | Current value | New value | Reason | Risk | Decision |
| --- | --- | --- | --- | --- | --- | --- |
| BPF-8 | Lane C task | x86 application coverage table | Every program of the six applications on the x86-64 verified path, bounded indirect dispatch implemented, a verified-path runtime arm with same-work counters, timing requests to R; no program left unsupported | Operator words above | Large simulator and generator changes in three days | Approved by the quotes above |
| BPF-9 | Lane A (new) | none | The same on AArch64 under QEMU, then a command sequence for DGX Spark | “arm 后面可用 spark, 你先把模拟的跑通” | QEMU timing is functional only | Approved |
| BPF-10 | Lane V (new) | none | Reorganize `kprog/formal` (one `make check`, delete scratch, duplicates and paper/count checkers, short README) without losing coverage; per-instruction refinement for all 77 x86-64 and 72 AArch64 operations, one reference specification per ISA | “验证代码也需要整理” | Concurrent edits with lane R's removal of paper checks; coordinated through notices | Approved |
| BPF-11 | Lane T (new) | none | Per-program translation validation of the clang-produced artifact against the reference ISA semantics, explicit binding of entry point, ABI and metadata, and a composed Lean theorem | O1-O4 “必须完整做完” | The hardest item; progress is checked every two hours | Approved |
| BPF-12 | Lane F task | Differential test, negative suite, load time, helper/map, TCB | Same, each complete; an accepted negative case is a bug to fix; scale sweep from 100 to 100K instructions added | “不允许留下任何缺陷说不做” | none beyond the lane's CPU and disk use | Approved |

All Codex lanes share host CPUs 8-23 and guests of at most 12 GiB. Lane R
keeps P-cores 0-7 for timing and takes the timing requests listed in
`COORDINATION.md`, including a coordinator request for JIT, verified, unbound
and trusted-module baselines with throughput, latency, CPU utilization and
same-work counters. No Kubernetes object, Workspace, login copy or duty
schedule changes.

## Evidence and implementation

Lanes A, V and T started at about 06:55 UTC with the existing
`lane-loop.sh`. Lanes C and F get their new tasks through `resume-msg.md`
on their next turn, and `prompt.md` and `cont.md` carry the same task. Ten
`codex exec` processes were running after the start, two for each of the
five Codex lanes. The cluster-wide Codex login (yunwei356) stood at 48% used.
At its limit, the order recorded in
`2026-11-04-cluster-codex-login-yunwei356-priority.md` applies.

## Validation and rollback

Validation: each lane's `turns.log` and results directory grow. A Claude
check every two hours restarts dead loops and reports progress.

Rollback: `touch /workspaces/.agent-state/kprog-lanes/<lane>/STOP` stops a
lane after its current turn; kill its loop and `codex exec` processes to stop
it at once.
