# kprog: performance numbers first, self-imposed requirements removed

- Date: 2026-11-06 (UTC)
- Scope: CronJob `agent-duties/bpf-benchmark-supervisor` prompt (lane R); `bpfopt/shim/shim_native_loader.h` in `yunwei356/bpf-benchmark-dev`; `/workspaces/.agent-state/kprog-lanes/COORDINATION.md`
- Status: deployed

## User request and approval

> “是不是有些不必要的额外规定, 互相等来等去? ... 这个没必要吧? 不必要的额外的要删掉”

> “重点是性能数据确定正确的跑出来对吧? 不要加额外的自己给自己设置障碍的”

> “你也要看还有没有额外的组织复现的, 现在复现还差啥? 如果直接跑 native 有碰到 verifier 错误, 我们是不是也应该先把性能跑出来”

## Defaults and decisions

| ID | Setting | Before | After | Reason |
| --- | --- | --- | --- | --- |
| BPF-18 | libbpf feature probes in the verified arm | Required generation-bound proofs (0bff849bf) | Pass through unchanged (20aae50eb) | Probes are libbpf's own two-instruction programs, not application programs; the operator called the requirement unnecessary |
| BPF-19 | Native load failure without a proof requirement | Aborted the whole application | The program stays eBPF and is logged `pass-through-after-failure` (9962aec5e); the verified arm still aborts | Performance numbers first |
| BPF-20 | R's reproduction task | Old 05-29 tree and current code; native arm described with the verified-arm flag | Current code first with the unbound native loader as on 05-29; the old tree only to explain a number that does not reproduce; the verified arm is a separate later measurement; R fixes a shared build break that stops it | R spent the afternoon on the strict verified arm and on other lanes' build breaks while no six-app number appeared |
| BPF-21 | Lane coordination rules | Only R times; change another lane's files only after a notice; R reports and waits (my 17:40 decision); shared-index windows | Any lane times on CPUs 0-7, one run at a time; any lane makes the minimal fix for what blocks it and posts afterwards; commits use a private index, no windows; my 17:40 decision withdrawn | These rules made lanes wait on each other |

## Evidence and implementation

Both shim commits were made from a private `GIT_INDEX_FILE` holding only
those lines, pushed to master, and the shared index entry for the file was
moved to the new blob because no lane had staged it. The worktree copy keeps
lane R's uncommitted diagnostic labels. `COORDINATION.md` gained the operator
words in its Goal section and a withdrawal note, and each Codex lane got a
message. R's prompt in `services/agent-duties/duties.yaml` carries the new
reproduction text; its admission annotations point at this record.

## Validation and rollback

Validation: R's next run carries the new prompt, as its argv shows, and its
corpus runs use `BPFREJIT_SHIM_NATIVE_LOADER=post` without
`BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF`; the hourly check reads the
`pass-through-after-failure` lines per app.

Rollback: revert 9962aec5e and 20aae50eb in bpf-benchmark, and revert this
commit for the prompt.
