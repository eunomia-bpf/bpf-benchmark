# tracee/monitor source-opt summary

App: `tracee/monitor`

Status: phase3-in-progress

Start state:

- Started: 2026-06-25 05:18:43
- Initial worktree status: existing source-opt docs and corpus result files
  present; `vendor/repos/tracee` was clean.
- Initial disk: `/dev/nvme0n1p2 915G 701G 168G 81% /`
- Benchmark contract: single-app `make corpus`, `SKIP_REJIT=all`,
  `SAMPLES=3 WORKLOAD_DURATION=180 WARMUPS=1`,
  `BPFREJIT_CORPUS_BPF_STATS=0`
- Runner: real `tracee` binary with workload `stress_ng_tracee_syscall_hot`
- BPF source root: `vendor/repos/tracee/pkg/ebpf/c`

Baseline:

- Status: accepted
- Result path: `corpus/results/x86_kvm_corpus_20260625_122431_943915`
- App result: `corpus/results/x86_kvm_corpus_20260625_122431_943915/details/apps/tracee__monitor.json`
- Gate: suite `status=ok`; app `status=ok`; `error=""`; 3 workload
  samples all returned 0; `post_rejit=null`;
  `rejit_result.mode="skip_rejit_all"`; disk after run:
  `/dev/nvme0n1p2 915G 701G 168G 81% /`.

Attempts:

| Attempt | Status | Result path | Notes |
| --- | --- | --- | --- |
| 1 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260625_124558_225233` | `sys_exit_submit()` reuses `sys->ret` saved by `sys_exit_init()` instead of reading `ctx->args[1]` again. |
| 2 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260625_130746_945964` | `sys_enter_init()` caches `is_compat(task)` and reuses it for x86 argument selection plus syscall id translation. |
| 3 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260625_132825_862375` | `sys_exit_init()` defers reading `ctx->args[1]` until after syscall id sanity checking. |
| 4 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260625_134931_275984` | `send_socket_dup()` writes `oldfd`/`newfd` only after confirming a supported socket family. |
| 5 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260625_141005_857825` | `send_socket_dup()` turns the final `family == AF_UNIX` test into `else` after the existing family guard proves only UNIX remains. |

First-round completion gate:

- [x] Clean-source baseline result recorded.
- [x] Five independent source optimization attempts recorded. 5 / 5 accepted.
- [x] Every accepted attempt has `source.diff`, command, result path, and correctness notes.
- [x] tracee source tree returned to attempt-start state after each attempt.

Phase2 attempts:

| Attempt | Status | Result path | Notes |
| --- | --- | --- | --- |
| phase2/20260625-205820-cap-capable-fentry | rejected-correctness | `corpus/results/x86_kvm_corpus_20260626_040613_380312` | Converted `trace_cap_capable` from kprobe to fentry, but Tracee failed BPF load because the fentry program returned the unknown `events_perf_submit()` helper result instead of 0. No performance samples. |
| phase2/20260625-210832-cap-capable-fentry-return0 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260626_041555_482043` | Corrected fentry return value; `stress_ng_sum_bogo_ops_s mean=462359`, samples `466968, 460401, 459707`, +0.32% vs baseline. |
| phase2/20260625-213013-phase2-cap-fentry-early-noaudit | rejected-no-signal | `corpus/results/x86_kvm_corpus_20260626_043813_884875` | Stacked corrected fentry with an earlier `CAP_OPT_NOAUDIT` return before event setup; correctness passed, but `stress_ng_sum_bogo_ops_s mean=453930`, samples `453680, 454459, 453651`, -1.50% vs baseline. Not selected as next base. |
| phase2/20260625-215524-phase2-simple-value-args-fastpath | rejected-correctness | `corpus/results/x86_kvm_corpus_20260626_050351_616916` | Added a simple-value fast path to `save_args_to_submit_buf()`, but Tracee failed BPF load: verifier rejected `sys_exit_submit` with `invalid access to map value` on the fallback type table path. No performance samples. |
| phase2/20260625-220744-phase2-hot-syscall-arg-count | rejected-no-signal | `corpus/results/x86_kvm_corpus_20260626_051548_824007` | Reduced x86 hot syscall argument reads in `sys_enter_init()`; correctness passed, but `stress_ng_sum_bogo_ops_s mean=456957`, samples `453757, 460873, 456241`, -0.85% vs baseline. Not selected as next base. |

Phase2 gate:

- [x] 5 / 5 phase2 attempts recorded.
- [x] At least one phase2 tracee attempt accepted for performance analysis.
- [x] tracee source tree returned to attempt-start state after phase2 attempt 5.
- [x] Best tracee phase2 result remains
  `phase2/20260625-210832-cap-capable-fentry-return0` at +0.32%; tracee
  did not reach the 10% target.

Phase3 attempts:

| Attempt | Status | Result path | Primary metric | Notes |
| --- | --- | --- | ---: | --- |
| 1 | completed-not-stacked | `corpus/results/x86_kvm_corpus_20260626_155038_747634` | `stress_ng_sum_bogo_ops_s` mean=462517, samples `461582, 464345, 461625`, +0.36% vs clean baseline | Stacks phase2 best and adds a no-scope-filter fast path to `evaluate_scope_filters()`; gate passed, but improvement over phase2 best is only +0.03% while hot sections grew, so do not stack. |
| 2 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260626_161621_526914` | `stress_ng_sum_bogo_ops_s` mean=464810, samples `462950, 465355, 466125`, +0.86% vs clean baseline | Stacks phase2 best and converts `trace_security_task_prctl` from kprobe to typed fentry. Real loader accepted the fentry attach; this is the current tracee phase3 base, but prctl is a tiny workload contributor so next attempt should pivot to hotter shared syscall/cap/futex/sigfd paths. |
| 3 | completed-not-stacked | `corpus/results/x86_kvm_corpus_20260626_164248_792753` | `stress_ng_sum_bogo_ops_s` mean=457589, samples `458895, 456475, 457398`, -0.71% vs clean baseline | Stacks attempt 2 and adds direct hot syscall argument serialization for setuid/setgid/kill/tkill/tgkill/eventfd/signalfd/futex. Correctness passed, but `sys_exit_submit` grew from `0x4fc8` to `0x60a0` and throughput regressed by 1.55% vs attempt 2, so do not stack. |
| 4 | completed-not-stacked | `corpus/results/x86_kvm_corpus_20260626_170733_776031` | `stress_ng_sum_bogo_ops_s` mean=450374, samples `450246, 448766, 452111`, -2.28% vs clean baseline | Stacks attempt 2 and reorders `save_args_to_submit_buf()` to handle value arg types before pointer-type dispatch. Correctness passed, but throughput regressed by 3.11% vs attempt 2; do not stack and pivot away from serializer layout tweaks. |

Phase3 gate:

- [x] Phase3 attempt 1 recorded.
- [x] Phase3 attempt 1 source tree returned to clean state after run.
- [x] Phase3 attempt 2 recorded.
- [x] Phase3 attempt 2 source tree returned to clean state after run.
- [x] Phase3 attempt 3 recorded.
- [x] Phase3 attempt 3 source tree returned to clean state after run.
- [x] Phase3 attempt 4 recorded.
- [x] Phase3 attempt 4 source tree returned to clean state after run.
- [ ] Phase3 attempts complete: 4 / 5.
