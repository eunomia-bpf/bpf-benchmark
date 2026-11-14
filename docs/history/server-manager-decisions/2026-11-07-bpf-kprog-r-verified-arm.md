# kprog: lane R moves from reproduction to the verified arm

- Date: 2026-11-07 (UTC)
- Scope: CronJob `agent-duties/bpf-benchmark-supervisor` prompt (lane R) for Workspace `yunwei356/bpf-benchmark-dev`
- Status: deployed

## User request and approval

> “干嘛又重新做微基准? 讨论一下昨晚上到现在的所有进展”

The operator asked why the microbenchmarks were being measured again.

## Defaults and decisions

| ID | Setting | Before | After | Reason |
| --- | --- | --- | --- | --- |
| BPF-26 | R's task | Reproduce the 2026-05-29 numbers first, then serve timing requests | The reproduction is complete history. R times each application's verified arm on the trusted path as the lanes publish it, starting with BCC through C's native-only-runtime Makefile (CPUS=0-7, VM_CPUS=8, VM_MEM=64G, SAMPLES=3, WORKLOAD_DURATION=180, both stats modes). Each ratio is taken against the JIT arm of the same run. | R re-timed the pure micro suite (1.468x, 613a60402) and started the helper/map suite again after a COORDINATION notice asked it to stop |
| BPF-27 | Re-timing | R re-ran finished measurements on each new code revision | R re-times a program only after the native code it executes changes, and names the commit that changed it | The trusted path changes who generates the proof; the executed native bytes stay identical (F's 231cbde41) |

## Evidence and implementation

- **What R re-ran.** R's long-running session started at 18:02 UTC and missed the 19:00 COORDINATION notice. At 19:25 it pushed the pure micro re-measurement and started `make micro` on the stage2 suite. That make was rebuilding the application objects with `make -B`.
- **Stopping the run.** The coordinator ended that make by exact pids: the make, its shell and its four children.
- **Prompt change.** The prompt in `services/agent-duties/duties.yaml` now opens R's instructions with the current task. Its admission annotations point at this record.

## Validation and rollback

Validation:
- The CronJob carries the new sentence.
- The next R Job's argv carries it.
- R's next timing run is BCC on the trusted path with the stated recipe.

Rollback: revert this commit.
