# tracee/monitor source-opt summary

App: `tracee/monitor`

Status: complete

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

Completion gate:

- [x] Clean-source baseline result recorded.
- [x] Five independent source optimization attempts recorded. 5 / 5 accepted.
- [x] Every accepted attempt has `source.diff`, command, result path, and correctness notes.
- [x] tracee source tree returned to attempt-start state after each attempt.
