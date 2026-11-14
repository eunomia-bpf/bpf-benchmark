# kprog: lane R times an application once lane C reports it bound

- Date: 2026-11-07 (UTC)
- Scope: CronJob `agent-duties/bpf-benchmark-supervisor` prompt (lane R) for Workspace `yunwei356/bpf-benchmark-dev`
- Status: deployed

## User request and approval

> “你也要设计每小时监控, 用中文给我汇报结果, 并且盯着去做.”

The operator asked the coordinator to watch the lanes hourly and act on what the check shows. Earlier the same day the operator objected to repeated measurement work (“干嘛又重新做微基准?”).

## Defaults and decisions

| ID | Setting | Before | After | Reason |
| --- | --- | --- | --- | --- |
| BPF-28 | When R times an application | R timed each application "as the lanes publish it" and chose the moment itself | R starts an application's timing once lane C posts in COORDINATION.md that the whole application binds in the native-only runtime. While every remaining application awaits C, R reads COORDINATION.md, reports the waiting state in one line and ends the turn. | Between 20:41 and 22:24 UTC R ran the Tetragon verified arm five times and Katran once; each stopped at the same unbound program that C was already repairing |
| BPF-30 | Where R reports waiting (2026-11-08) | "reports the waiting state in one line"; R appended a waiting line to COORDINATION.md on each 10-minute Job (23:55, 00:05, 00:12, 00:18 UTC) | R states the waiting state in one line of its own final message; R writes to COORDINATION.md only new results and requests | Every lane reads COORDINATION.md each turn, so a line per Job adds reading work for all of them |
| BPF-29 | Ownership of service failures | R diagnosed trusted-service refusals and edited `corpus/results/kprog_app_coverage_20261107/native-only-runtime/guest.py` (732b9eeab, 33aed93db) | Generation, binding and trusted-service failures and the native-only-runtime files belong to C; R leaves diagnosis and retries of an unbound application to C | C runs the same Tetragon whole-application batches on CPUs 20-23 and owns that runtime |

## Evidence and implementation

- **Repeated runs.** R's logs `/tmp/R-verified-tet-s1.log` (20:54), `tet2` (21:44), `tet3` (22:05), `tet4` (22:22) and `tet5` (22:24), plus `R-verified-kat-s1.log` (21:23). Tetragon bound 2 programs and the service refused the third in every run; Katran's `balancer_ingress` was refused with EIO.
- **C's status.** C's 21:20 and 22:15 notes report Tetragon at 3 generated, 2 bound with a native-stub EINVAL on the third, Tracee at 5 of 6 bound, and Katran's partial-register repair in progress.
- **Prompt change.** One paragraph after the re-timing sentence in `services/agent-duties/duties.yaml`. The admission annotations point at this record.
- **Process.** After the CronJob carries the new text, the coordinator ends R's running OMP process and its make by exact pids, and deletes the Job created with the old prompt, so the next Job continues the session with the new prompt.

## Validation and rollback

Validation:
- The CronJob carries the new paragraph.
- The next R Job's argv carries it.
- R's next timing run names the C note that reported the application bound.

Rollback: revert this commit.
