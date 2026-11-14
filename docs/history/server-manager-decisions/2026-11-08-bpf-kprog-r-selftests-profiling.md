# kprog: lane R ports the kernel BPF selftests and measures performance attribution

- Date: 2026-11-08 (UTC)
- Scope: CronJob `agent-duties/bpf-benchmark-supervisor` prompt (lane R) for Workspace `yunwei356/bpf-benchmark-dev`
- Status: deployed

## User request and approval

> “安全回归 38 例，我从原始归档逐例核对过 这个是不是改成用 linux kernel testcase 更好? 不要我们自己构造?”
>
> “性能优化是不是应该考虑排期?”
>
> “去做”

The operator asked for the safety evidence to come from the Linux kernel's own BPF test cases in place of a self-built suite, and for a schedule for performance work. Then the operator approved both.

## Defaults and decisions

| ID | Setting | Before | After | Reason |
| --- | --- | --- | --- | --- |
| BPF-31 | R while applications await C | R stated a waiting line and ended the turn | R works on the selftests port and then the performance attribution. It returns to timing when C posts the next whole-application binding. | R sat idle at a 10-minute cadence while C rebuilt the trusted path |
| BPF-32 | Safety evidence | 38 self-built native cases on x86-64 (30 on AArch64) | The kernel BPF selftests become the safety suite (see the setup below). ISA-level hazards outside eBPF state stay as ISA cases. | Kernel annotations are an external standard; the suite is about 20 times larger |
| BPF-33 | Performance schedule | Deferred ("剩下之后再说") | R measures per-program attribution first (computation, helper calls, map lookups, tail calls). C implements link-time optimizations in that order once the six applications bind on x86-64. Each optimization adds an O4 theorem (V). | Operator asked for a schedule |

| BPF-34 | How R submits selftests | R loaded the eBPF companion first, so 64 `__failure` programs stopped at the eBPF verdict | R submits P directly with source_prog_id 0, objects opened autoload=false; each C program becomes its own translation unit; guests pin to CPUs 0-7 | Two COORDINATION notices left the harness unchanged; the prompt reaches R on its next Job |

Selftests setup for BPF-32:
- **Source.** The C-written programs in `tools/testing/selftests/bpf/progs` that carry `__failure` or `__success` annotations: 453 and 298 of them in `vendor/linux-framework` at 9c50491de2a5.
- **Run.** Each program is compiled to native and run through the five-step path. The kernel annotation is the expected outcome.
- **Excluded.** The `__naked` BPF-assembly programs stay with the kernel's own test_progs.

## Evidence and implementation

- **Counts.** The coordinator counted them on the Workspace tree on 2026-11-08: 916 program files and 150 files with `__failure`. Among programs, 453 C-written and 592 inline-assembly ones expect failure, and 298 C-written and 741 inline-assembly ones expect success.
- **Prompt.** In `services/agent-duties/duties.yaml`, R's waiting sentence becomes the two task paragraphs. The admission annotations point at this record.
- **Priorities.** COORDINATION.md "Current priorities" gains item 2a (selftests), and item 5 becomes the performance schedule.

## Validation and rollback

Validation:
- The CronJob carries the new paragraphs, and the next R Job's argv carries them.
- R publishes the following:
  - `kprog/results/kprog_selftests_20261108/README.md`, with a per-program outcome against the kernel annotation;
  - `kprog/results/kprog_perf_attribution_20261108/README.md`, with per-program time shares.

Rollback: revert this commit.
